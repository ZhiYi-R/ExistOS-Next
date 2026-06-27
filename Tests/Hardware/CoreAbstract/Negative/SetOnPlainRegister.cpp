/**
 * @file SetOnPlainRegister.cpp
 * @brief 负向编译测试:对普通 Register 调用 Set(别名原子置位)必须编译失败。
 *
 * 预期失败原因:Set/Clear/Toggle 仅存在于 RegisterWithSetClearToggle;
 * 普通 Register 无此成员,不应为不存在的别名硬件付出接口代价。
 */
#include "Register.hpp"
#include <cstdint>

using namespace LowLevel;
using PlainRegister = Register<std::uint32_t, 0x1000>;

int main() {
    PlainRegister::Set(0x1u); // 期望:Register 无 Set 成员,不可编译
    return 0;
}
