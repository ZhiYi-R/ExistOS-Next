/**
 * @file MisalignedRegister.cpp
 * @brief 负向编译测试:MMIO 基址未对齐必须编译失败。
 *
 * 预期失败原因:Register 内 static_assert(BaseAddress % alignof == 0)。
 */
#include "Register.hpp"
#include <cstdint>

using namespace LowLevel;
using MisalignedRegister = Register<std::uint32_t, 0x1001>; // 0x1001 未按 4 字节对齐

int main() {
    (void)sizeof(MisalignedRegister); // 实例化以触发 static_assert
    return 0;
}
