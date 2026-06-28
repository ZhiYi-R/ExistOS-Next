/**
 * @file WriteFieldsRuntimeTests.cpp
 * @brief 寄存器主体形式 Reg::WriteFields<F...>(v...) 的主机运行期单元测试。
 *
 * 重点:多字段经一次读-改-写合并写入,且不破坏所有字段并集之外的位。字段以模板
 * 实参显式给出,值按序传入;每个字段都在编译期被 static_assert 锚定到本寄存器。
 */

#include "Field.hpp"
#include "MemoryBackend.hpp"
#include "TestHarness.hpp"

#include <cstdint>

using LowLevel::Bit;
using LowLevel::Field;
using TestSupport::MemoryBackend;

namespace {

struct TagShifted;
struct TagCombine;
struct TagPreserveOutside;
struct TagSingle;

using ShiftedBackend = MemoryBackend<TagShifted>;
using LowField = Field<ShiftedBackend, Bit::Bit0, 4>;  /**< 位[3:0] */
using HighField = Field<ShiftedBackend, Bit::Bit8, 4>; /**< 位[11:8] */

} // namespace

TEST_CASE(shiftedAlignsValueToField) {
    // Field::Shifted 把字段值移位归位,是 WriteFields 合并的基础积木。
    CHECK_EQUAL(LowField::Shifted(0xAu), 0x0Au);
    CHECK_EQUAL(HighField::Shifted(0xAu), 0xA00u);
}

TEST_CASE(writeFieldsCombinesIntoSingleValue) {
    using Backend = MemoryBackend<TagCombine>;
    using NibbleZero = Field<Backend, Bit::Bit0, 4>;  // 0x000F
    using NibbleTwo = Field<Backend, Bit::Bit8, 4>;   // 0x0F00
    using NibbleFour = Field<Backend, Bit::Bit16, 4>; // 0x0F0000

    Backend::Reset(0);
    Backend::WriteFields<NibbleZero, NibbleTwo, NibbleFour>(0x1u, 0x2u, 0x3u);
    CHECK_EQUAL(Backend::storage, 0x030201u);
}

TEST_CASE(writeFieldsPreservesBitsOutsideAllFields) {
    using Backend = MemoryBackend<TagPreserveOutside>;
    using LowNibble = Field<Backend, Bit::Bit0, 4>;  // 0x000F
    using HighNibble = Field<Backend, Bit::Bit8, 4>; // 0x0F00

    // 背景含字段并集(0x0F0F)之外的位,必须原样保留。
    Backend::Reset(0xA5A5A5A5u);
    Backend::WriteFields<LowNibble, HighNibble>(0x2u, 0x3u);
    // 期望:低半字节 5→2、第二半字节 5→3,其余位不变。
    // 0xA5A5A5A5 → 清掉 0x0F0F 得 0xA5A5A0A0,再或入 0x0302 → 0xA5A5A3A2
    CHECK_EQUAL(Backend::storage, 0xA5A5A3A2u);
}

TEST_CASE(writeFieldsSingleFieldEquivalentToFieldWrite) {
    using Backend = MemoryBackend<TagSingle>;
    using OnlyField = Field<Backend, Bit::Bit4, 3>;

    Backend::Reset(0xFFFFFFFFu);
    Backend::WriteFields<OnlyField>(0x2u);
    CHECK_EQUAL(Backend::storage, 0xFFFFFFAFu); // 与 WriteField 同语义
}

TEST_MAIN()
