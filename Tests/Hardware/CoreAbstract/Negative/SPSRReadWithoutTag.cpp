/**
 * @file SPSRReadWithoutTag.cpp
 * @brief 负向编译测试:不带 PrivilegedModeTag 调用 Spsr::Read 必须编译失败。
 *
 * 预期失败原因:Spsr::Read 仅有 Read(PrivilegedModeTag) 重载,无无参版本,
 * 强制调用方在类型层面承认处于特权模式。
 */
#include "PSR.hpp"
#include <cstdint>

using namespace LowLevel;

int main() {
    volatile std::uint32_t value = Spsr::Read(); // 期望:缺少 PrivilegedModeTag,不可编译
    (void)value;
    return 0;
}
