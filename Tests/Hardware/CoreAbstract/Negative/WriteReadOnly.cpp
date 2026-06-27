/**
 * @file WriteReadOnly.cpp
 * @brief 负向编译测试:对 ReadOnly 寄存器调用 Write 必须编译失败。
 *
 * 预期失败原因:Write 的 requires 约束(access==ReadWrite||WriteOnly)对 RO 不成立。
 */
#include "Register.hpp"
#include <cstdint>

using namespace LowLevel;
using ReadOnlyRegister = Register<std::uint32_t, 0x1000, Access::ReadOnly>;

int main() {
    ReadOnlyRegister::Write(0x1u); // 期望:此处不可编译
    return 0;
}
