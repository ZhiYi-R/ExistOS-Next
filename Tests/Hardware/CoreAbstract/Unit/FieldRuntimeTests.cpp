/**
 * @file FieldRuntimeTests.cpp
 * @brief 字段读写逻辑核心的主机运行期单元测试(over 内存后端替身)。
 *
 * 覆盖:Field::GetMask / Field::Shifted,以及以寄存器为主体的字段动作
 * ReadField / ReadFieldRaw / WriteField / SetField / ClearField / ToggleField /
 * FieldIsSet / FieldIs、保留邻位、枚举型字段、满宽(32 位)字段、u16 寄存器宽度。
 * 这些是全库唯一含算术的逻辑;真实 Register/CP15/CPSR 后端的"单指令"性质由
 * 目标 objdump 验证(见 Target/)。
 */

#include "Field.hpp"
#include "MemoryBackend.hpp"
#include "TestHarness.hpp"

#include <cstdint>

using LowLevel::Bit;
using LowLevel::Field;
using TestSupport::MemoryBackend;

namespace {

/* 为每个用例准备独立标签,避免存储串扰。 */
struct TagGeneral;
struct TagPreserve;
struct TagSetClearToggle;
struct TagAliasField;
struct TagPredicate;
struct TagEnum;
struct TagFullWidth;
struct TagHalfword;

using GeneralBackend = MemoryBackend<TagGeneral>;
using GeneralField = Field<GeneralBackend, Bit::Bit4, 3>; /**< 位[6:4]，掩码 0x70 */

} // namespace

TEST_CASE(getMaskIsCompileTimeAndCorrect) {
    // GetMask 是 consteval，这里同时核对它在运行期上下文也取到同值。
    CHECK_EQUAL(GeneralField::GetMask(), 0x70u);
    CHECK_EQUAL((Field<GeneralBackend, Bit::Bit0, 1>::GetMask()), 0x1u);
    CHECK_EQUAL((Field<GeneralBackend, Bit::Bit31, 1>::GetMask()), 0x80000000u);
    CHECK_EQUAL((Field<GeneralBackend, Bit::Bit8, 8>::GetMask()), 0xFF00u);
}

TEST_CASE(shiftedAlignsAndMasksValue) {
    CHECK_EQUAL(GeneralField::Shifted(0x5u), 0x50u);
    // 超出位宽的高位被字段掩码截断(0xF 取低 3 位 = 0x7 → 0x70)。
    CHECK_EQUAL(GeneralField::Shifted(0xFu), 0x70u);
}

TEST_CASE(writeThenReadRoundTrips) {
    GeneralBackend::Reset(0);
    GeneralBackend::WriteField<GeneralField>(0x5u);
    CHECK_EQUAL(GeneralBackend::storage, 0x50u);
    CHECK_EQUAL(GeneralBackend::ReadField<GeneralField>(), 0x5u);
    CHECK_EQUAL(GeneralBackend::ReadFieldRaw<GeneralField>(), 0x50u);
}

TEST_CASE(writeTruncatesToFieldWidth) {
    GeneralBackend::Reset(0);
    GeneralBackend::WriteField<GeneralField>(0xFFu); // 仅低 3 位有效
    CHECK_EQUAL(GeneralBackend::storage, 0x70u);
    CHECK_EQUAL(GeneralBackend::ReadField<GeneralField>(), 0x7u);
}

TEST_CASE(writePreservesNeighbouringBits) {
    using PreserveBackend = MemoryBackend<TagPreserve>;
    using MiddleField = Field<PreserveBackend, Bit::Bit4, 3>; // 0x70
    PreserveBackend::Reset(0xFFFFFFFFu);              // 全 1 背景
    PreserveBackend::WriteField<MiddleField>(0x2u);   // 仅改 [6:4]
    // 期望：[6:4] = 010，其余保持 1 → 0xFFFFFFAF
    CHECK_EQUAL(PreserveBackend::storage, 0xFFFFFFAFu);
}

TEST_CASE(setClearToggleAffectOnlyField) {
    using Backend = MemoryBackend<TagSetClearToggle>;
    using TargetField = Field<Backend, Bit::Bit4, 3>; // 0x70

    Backend::Reset(0x0000000Fu); // 低 4 位为 1，字段区为 0
    Backend::SetField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x0000007Fu); // 置满字段，低位不动

    Backend::ClearField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x0000000Fu); // 清空字段，低位不动

    Backend::Reset(0x00000000u);
    Backend::ToggleField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x70u);
    Backend::ToggleField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x00u);
}

TEST_CASE(aliasedBackendFieldSetClearToggleMatchesRmwSemantics) {
    // 带 SET/CLR/TOG 别名的后端:字段级位操作走原子别名分支,结果须与 RMW 路径等价。
    using Backend = TestSupport::MemoryBackendWithSetClearToggle<TagAliasField>;
    using TargetField = Field<Backend, Bit::Bit4, 3>; // 0x70

    Backend::Reset(0x0000000Fu);
    Backend::SetField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x0000007Fu); // 经 SET 别名置满字段,低位不动

    Backend::ClearField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x0000000Fu); // 经 CLR 别名清空字段,低位不动

    Backend::Reset(0x00000000u);
    Backend::ToggleField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x70u); // 经 TOG 别名翻转
    Backend::ToggleField<TargetField>();
    CHECK_EQUAL(Backend::storage, 0x00u);
}

TEST_CASE(predicatesReflectFieldState) {
    using Backend = MemoryBackend<TagPredicate>;
    using TargetField = Field<Backend, Bit::Bit4, 3>;

    Backend::Reset(0x00u);
    CHECK(!Backend::FieldIsSet<TargetField>());
    CHECK(Backend::FieldIs<TargetField>(0x0u));

    Backend::WriteField<TargetField>(0x5u);
    CHECK(Backend::FieldIsSet<TargetField>());
    CHECK(Backend::FieldIs<TargetField>(0x5u));
    CHECK(!Backend::FieldIs<TargetField>(0x4u));
}

TEST_CASE(enumTypedFieldRoundTrips) {
    enum class Speed : std::uint32_t { Slow = 0, Medium = 1, Fast = 2, Turbo = 3 };
    using Backend = MemoryBackend<TagEnum>;
    using SpeedField = Field<Backend, Bit::Bit4, 2, Speed>; // 位[5:4]

    Backend::Reset(0);
    Backend::WriteField<SpeedField>(Speed::Fast);
    CHECK_EQUAL(Backend::storage, (static_cast<std::uint32_t>(Speed::Fast) << 4));
    CHECK(Backend::ReadField<SpeedField>() == Speed::Fast);
    CHECK(Backend::FieldIs<SpeedField>(Speed::Fast));
    CHECK(!Backend::FieldIs<SpeedField>(Speed::Slow));
}

TEST_CASE(fullWidthFieldUsesAllOnesMask) {
    using Backend = MemoryBackend<TagFullWidth>;
    using WholeField = Field<Backend, Bit::Bit0, 32>;

    CHECK_EQUAL(WholeField::GetMask(), 0xFFFFFFFFu);
    Backend::Reset(0);
    Backend::WriteField<WholeField>(0xDEADBEEFu);
    CHECK_EQUAL(Backend::storage, 0xDEADBEEFu);
    CHECK_EQUAL(Backend::ReadField<WholeField>(), 0xDEADBEEFu);
}

TEST_CASE(halfwordRegisterWidthRespected) {
    using Backend = MemoryBackend<TagHalfword, std::uint16_t>;
    using HighNibble = Field<Backend, Bit::Bit12, 4>; // 位[15:12]，掩码 0xF000

    CHECK_EQUAL(HighNibble::GetMask(), static_cast<std::uint16_t>(0xF000u));
    Backend::Reset(static_cast<std::uint16_t>(0x0FFFu));
    Backend::WriteField<HighNibble>(0xAu);
    CHECK_EQUAL(Backend::storage, static_cast<std::uint16_t>(0xAFFFu));
    CHECK_EQUAL(Backend::ReadField<HighNibble>(), static_cast<std::uint16_t>(0xAu));
}

TEST_MAIN()
