/**
 * @file MaskAssertions.cpp
 * @brief 掩码/移位/字段数值的编译期断言。可移植:主机与目标皆可编。
 *
 * 这些 static_assert 把 consteval GetMask()、Shifted()、以及各寄存器字段的
 * 偏移/位宽固化为可回归的真值,任何位布局笔误都会让编译失败。
 */

#include "CP15.hpp"
#include "Concepts.hpp"
#include "Field.hpp"
#include "PSR.hpp"
#include "Register.hpp"

#include <cstdint>

namespace {

using namespace LowLevel;

using DemoRegister = Register<std::uint32_t, 0x1000>;

/* =========================== GetMask 基本规律 =========================== */
static_assert(Field<DemoRegister, Bit::Bit0, 1>::GetMask() == 0x00000001u);
static_assert(Field<DemoRegister, Bit::Bit4, 3>::GetMask() == 0x00000070u);
static_assert(Field<DemoRegister, Bit::Bit8, 8>::GetMask() == 0x0000FF00u);
static_assert(Field<DemoRegister, Bit::Bit31, 1>::GetMask() == 0x80000000u);
static_assert(Field<DemoRegister, Bit::Bit16, 16>::GetMask() == 0xFFFF0000u);
static_assert(Field<DemoRegister, Bit::Bit0, 32>::GetMask() == 0xFFFFFFFFu, "满宽边界");

/* u16 寄存器的满宽边界 */
using DemoHalfword = Register<std::uint16_t, 0x1000>;
static_assert(Field<DemoHalfword, Bit::Bit0, 16>::GetMask() == 0xFFFFu, "u16 满宽");
static_assert(Field<DemoHalfword, Bit::Bit12, 4>::GetMask() == 0xF000u);

/* ============================== Shifted ============================== */
static_assert(Field<DemoRegister, Bit::Bit4, 3>::Shifted(0x5u) == 0x50u);
static_assert(Field<DemoRegister, Bit::Bit4, 3>::Shifted(0xFu) == 0x70u, "超宽位被截断");
static_assert(Field<DemoRegister, Bit::Bit0, 8>::Shifted(0xABu) == 0xABu);

/* ============================ SCTLR 位布局 ============================ */
static_assert(SCTLR::MmuEnable::GetMask() == (1u << 0));
static_assert(SCTLR::AlignmentCheckEnable::GetMask() == (1u << 1));
static_assert(SCTLR::DataCacheEnable::GetMask() == (1u << 2));
static_assert(SCTLR::WriteBufferEnable::GetMask() == (1u << 3));
static_assert(SCTLR::BigEndian::GetMask() == (1u << 7));
static_assert(SCTLR::SystemProtection::GetMask() == (1u << 8));
static_assert(SCTLR::RomProtection::GetMask() == (1u << 9));
static_assert(SCTLR::InstructionCacheEnable::GetMask() == (1u << 12));
static_assert(SCTLR::HighVectors::GetMask() == (1u << 13));
static_assert(SCTLR::RoundRobinReplacement::GetMask() == (1u << 14));
static_assert(SCTLR::ThumbInterworkingDisable::GetMask() == (1u << 15));

/* ============================ DACR 域字段 ============================ */
static_assert(DACR::Domain<0>::GetMask() == (0b11u << 0));
static_assert(DACR::Domain<1>::GetMask() == (0b11u << 2));
static_assert(DACR::Domain<5>::GetMask() == (0b11u << 10));
static_assert(DACR::Domain<15>::GetMask() == (0b11u << 30));
/* 枚举型字段值移位到位 */
static_assert(DACR::Domain<1>::Shifted(DomainAccess::Manager) == (0b11u << 2));
static_assert(DACR::Domain<2>::Shifted(DomainAccess::Client) == (0b01u << 4));
static_assert(static_cast<std::uint32_t>(DomainAccess::NoAccess) == 0b00u);

/* ============================ CPSR 标志位 ============================ */
static_assert(Cpsr::Negative::GetMask() == (1u << 31));
static_assert(Cpsr::Zero::GetMask() == (1u << 30));
static_assert(Cpsr::Carry::GetMask() == (1u << 29));
static_assert(Cpsr::Overflow::GetMask() == (1u << 28));
static_assert(Cpsr::Saturate::GetMask() == (1u << 27));

/* ===================== 模式/中断屏蔽位常量 ===================== */
static_assert(CpsrIrqMask == (1u << 7));
static_assert(CpsrFiqMask == (1u << 6));
static_assert(static_cast<std::uint32_t>(Mode::User) == 0x10u);
static_assert(static_cast<std::uint32_t>(Mode::FastInterrupt) == 0x11u);
static_assert(static_cast<std::uint32_t>(Mode::Interrupt) == 0x12u);
static_assert(static_cast<std::uint32_t>(Mode::Supervisor) == 0x13u);
static_assert(static_cast<std::uint32_t>(Mode::Abort) == 0x17u);
static_assert(static_cast<std::uint32_t>(Mode::Undefined) == 0x1Bu);
static_assert(static_cast<std::uint32_t>(Mode::System) == 0x1Fu);

} // namespace

int main() { return 0; }
