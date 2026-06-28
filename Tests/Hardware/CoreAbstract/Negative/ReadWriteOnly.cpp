/**
 * @file ReadWriteOnly.cpp
 * @brief 负向编译测试:对 WriteOnly 寄存器调用 Read 必须编译失败。
 *
 * 预期失败原因:Read 的 requires 约束(access==ReadWrite||ReadOnly)对 WO 不成立。
 */
#include "Register.hpp"
#include <cstdint>

using namespace LowLevel;
using WriteOnlyRegister = Register<std::uint32_t, 0x1000, Access::WriteOnly>;

int main() {
    volatile std::uint32_t value{WriteOnlyRegister::Read()}; // 期望:此处不可编译
    (void)value;
    return 0;
}
