/**
 * @file FieldOutOfRange.cpp
 * @brief 负向编译测试:字段越出寄存器边界必须编译失败。
 *
 * 预期失败原因:Field 内 static_assert(BitOffset + BitWidth <= 位数)。
 */
#include "Field.hpp"
#include "Register.hpp"
#include <cstdint>

using namespace LowLevel;
using DemoRegister = Register<std::uint32_t, 0x1000>;
using OutOfRangeField = Field<DemoRegister, Bit::Bit30, 4>; // 30 + 4 = 34 > 32

int main() {
    (void)OutOfRangeField::GetMask(); // 实例化以触发 static_assert
    return 0;
}
