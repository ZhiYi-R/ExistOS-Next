/**
 * @file ConceptAssertions.cpp
 * @brief 概念满足性的编译期断言(编译通过即测试通过)。可移植:主机与目标皆可编。
 *
 * 验证三件事:
 *  1. 哪些真实类型满足 / 不满足 Backend;
 *  2. 哪些满足 HasSetClearToggle;
 *  3. 访问权限门控:RO 无 Write、WO 无 Read、RW 两者皆有——用 requires 表达式
 *     在 SFINAE 友好的上下文里探测,不触发硬错误。
 *
 * 本文件只做编译期检查,不 ODR-use 任何 ARM 内联汇编,故在主机 clang 上亦可编译。
 */

#include "CP15.hpp"
#include "Concepts.hpp"
#include "Field.hpp"
#include "PSR.hpp"
#include "Register.hpp"

#include <cstdint>

namespace {

using namespace LowLevel;

/* ---- 探测某后端是否暴露 Read / Write(随访问权限门控而变) ---- */
template <typename RegisterBackend>
concept ExposesRead = requires { RegisterBackend::Read(); };

template <typename RegisterBackend>
concept ExposesWrite =
    requires(typename RegisterBackend::ValueType value) { RegisterBackend::Write(value); };

/* ---- 代表性类型别名 ---- */
using PlainReadWrite = Register<std::uint32_t, 0x1000>;
using PlainReadOnly = Register<std::uint32_t, 0x1000, Access::ReadOnly>;
using PlainWriteOnly = Register<std::uint32_t, 0x1000, Access::WriteOnly>;
using ByteRegister = Register<std::uint8_t, 0x1000>;
using AliasRegister =
    RegisterWithSetClearToggle<std::uint32_t, 0x1000, 0x1004, 0x1008, 0x100C>;

/* ============================ Backend 满足性 ============================ */
static_assert(Backend<PlainReadWrite>, "RW MMIO 应满足 Backend");
static_assert(Backend<ByteRegister>, "u8 MMIO 应满足 Backend");
static_assert(Backend<AliasRegister>, "带别名的 MMIO 应满足 Backend");
static_assert(Backend<SCTLR>, "SCTLR(RW)应满足 Backend");
static_assert(Backend<TTBR0>, "TTBR0 应满足 Backend");
static_assert(Backend<DACR>, "DACR 应满足 Backend");
static_assert(Backend<DFSR>, "DFSR 应满足 Backend");
static_assert(Backend<FAR>, "FAR 应满足 Backend");
static_assert(Backend<ContextID>, "ContextID 应满足 Backend");
static_assert(Backend<Cpsr>, "CPSR(读总是合法)应满足 Backend");

/* ----------------------- 有意不满足 Backend ----------------------- */
static_assert(!Backend<Spsr>, "SPSR 有意不作 Backend(USR/SYS 读 UNPREDICTABLE)");
static_assert(!Backend<MainID>, "MainID 只读,无 Write,不应满足 Backend");
static_assert(!Backend<CacheType>, "CacheType 只读,不应满足 Backend");
static_assert(!Backend<TCMStatus>, "TCMStatus 只读,不应满足 Backend");

/* ========================= HasSetClearToggle ========================= */
static_assert(HasSetClearToggle<AliasRegister>, "带别名的 MMIO 应满足 HasSetClearToggle");
static_assert(!HasSetClearToggle<PlainReadWrite>, "普通 MMIO 无 Set/Clear/Toggle");
static_assert(!HasSetClearToggle<SCTLR>, "SCTLR 无 Set/Clear/Toggle 别名");

/* ====================== 访问权限门控(编译期) ====================== */
static_assert(ExposesRead<PlainReadWrite> && ExposesWrite<PlainReadWrite>,
              "RW 应同时暴露 Read 与 Write");
static_assert(ExposesRead<PlainReadOnly> && !ExposesWrite<PlainReadOnly>,
              "RO 应只暴露 Read");
static_assert(!ExposesRead<PlainWriteOnly> && ExposesWrite<PlainWriteOnly>,
              "WO 应只暴露 Write");

/* 别名寄存器的 Set/Clear/Toggle 也随访问权限门控:RO 别名不应暴露写类操作。 */
using ReadOnlyAlias =
    RegisterWithSetClearToggle<std::uint32_t, 0x2000, 0x2004, 0x2008, 0x200C,
                               Access::ReadOnly>;
static_assert(!HasSetClearToggle<ReadOnlyAlias>,
              "只读别名寄存器不应暴露 Set/Clear/Toggle");

/* ===================== Field 可绑定于各类 Backend ===================== */
static_assert(Field<PlainReadWrite, 0, 8>::GetMask() == 0xFFu);
static_assert(Field<SCTLR, 0, 1>::GetMask() == 0x1u);
static_assert(Field<Cpsr, 31, 1>::GetMask() == 0x80000000u);

/* ============ Readable / Writable Backend 拆分满足性 ============ */
static_assert(ReadableBackend<PlainReadWrite> && WritableBackend<PlainReadWrite>,
              "RW MMIO 既可读也可写");
static_assert(ReadableBackend<PlainReadOnly> && !WritableBackend<PlainReadOnly>,
              "RO MMIO 仅可读");
static_assert(!ReadableBackend<PlainWriteOnly> && WritableBackend<PlainWriteOnly>,
              "WO MMIO 仅可写");
static_assert(ReadableBackend<MainID> && !WritableBackend<MainID>,
              "只读 CP15 MainID 仅可读");

/* ====== Field 绑定只读后端:可绑定、读类可用、写类被门控掉 ====== */
template <typename FieldType>
concept FieldExposesRead = requires { FieldType::Read(); };
template <typename FieldType>
concept FieldExposesWrite =
    requires(typename FieldType::ValueType value) { FieldType::Write(value); };

using ReadOnlyMmioField = Field<PlainReadOnly, 0, 8>;
using MainIdField = Field<MainID, 0, 4>; // 只读 CP15 寄存器也能绑定字段
static_assert(ReadOnlyMmioField::GetMask() == 0xFFu, "只读后端字段掩码照常 consteval");
static_assert(FieldExposesRead<ReadOnlyMmioField> && !FieldExposesWrite<ReadOnlyMmioField>,
              "只读后端的 Field 只暴露读、不暴露写");
static_assert(FieldExposesRead<MainIdField> && !FieldExposesWrite<MainIdField>,
              "只读 CP15 字段只可读");
static_assert(FieldExposesRead<Field<PlainReadWrite, 0, 8>> &&
                  FieldExposesWrite<Field<PlainReadWrite, 0, 8>>,
              "RW 后端的 Field 读写皆可用");

} // namespace

int main() { return 0; }
