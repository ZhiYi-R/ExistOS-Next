/**
 * @file WriteFieldsRuntimeTests.cpp
 * @brief FieldValue / MakeFieldValue / WriteFields 的主机运行期单元测试。
 *
 * 重点：多字段经一次读-改-写合并写入,且不破坏所有字段并集之外的位。
 */

#include "Field.hpp"
#include "MemoryBackend.hpp"
#include "TestHarness.hpp"

#include <cstdint>

using LowLevel::Field;
using LowLevel::MakeFieldValue;
using LowLevel::WriteFields;
using TestSupport::MemoryBackend;

namespace {

struct TagFieldValue;
struct TagCombine;
struct TagPreserveOutside;

using FieldValueBackend = MemoryBackend<TagFieldValue>;
using LowField = Field<FieldValueBackend, 0, 4>;  /**< 位[3:0] */
using HighField = Field<FieldValueBackend, 8, 4>; /**< 位[11:8] */

} // namespace

TEST_CASE(fieldValueRawAlignsValue) {
    CHECK_EQUAL(MakeFieldValue<LowField>(0xAu).Raw(), 0x0Au);
    CHECK_EQUAL(MakeFieldValue<HighField>(0xAu).Raw(), 0xA00u);
}

TEST_CASE(writeFieldsCombinesIntoSingleValue) {
    using Backend = MemoryBackend<TagCombine>;
    using NibbleZero = Field<Backend, 0, 4>;  // 0x000F
    using NibbleTwo = Field<Backend, 8, 4>;   // 0x0F00
    using NibbleFour = Field<Backend, 16, 4>; // 0x0F0000

    Backend::Reset(0);
    WriteFields(MakeFieldValue<NibbleZero>(0x1u),
                MakeFieldValue<NibbleTwo>(0x2u),
                MakeFieldValue<NibbleFour>(0x3u));
    CHECK_EQUAL(Backend::storage, 0x030201u);
}

TEST_CASE(writeFieldsPreservesBitsOutsideAllFields) {
    using Backend = MemoryBackend<TagPreserveOutside>;
    using LowNibble = Field<Backend, 0, 4>;  // 0x000F
    using HighNibble = Field<Backend, 8, 4>; // 0x0F00

    // 背景含字段并集(0x0F0F)之外的位,必须原样保留。
    Backend::Reset(0xA5A5A5A5u);
    WriteFields(MakeFieldValue<LowNibble>(0x2u),
                MakeFieldValue<HighNibble>(0x3u));
    // 期望:低半字节 5→2、第二半字节 5→3,其余位不变。
    // 0xA5A5A5A5 → 清掉 0x0F0F 得 0xA5A5A0A0,再或入 0x0302 → 0xA5A5A3A2
    CHECK_EQUAL(Backend::storage, 0xA5A5A3A2u);
}

TEST_CASE(writeFieldsSingleFieldEquivalentToFieldWrite) {
    using Backend = MemoryBackend<TagFieldValue, std::uint32_t>;
    using OnlyField = Field<Backend, 4, 3>;

    Backend::Reset(0xFFFFFFFFu);
    WriteFields(MakeFieldValue<OnlyField>(0x2u));
    CHECK_EQUAL(Backend::storage, 0xFFFFFFAFu); // 与 Field::Write 同语义
}

TEST_MAIN()
