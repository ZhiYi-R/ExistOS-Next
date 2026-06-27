/**
 * @file ConstructRegister.cpp
 * @brief 负向编译测试:实例化 Register 必须编译失败。
 *
 * 预期失败原因:Register 是纯静态门面,构造/析构均 = delete。
 */
#include "Register.hpp"
#include <cstdint>

using namespace LowLevel;
using DemoRegister = Register<std::uint32_t, 0x1000>;

int main() {
    DemoRegister instance; // 期望:构造函数已删除,不可编译
    (void)instance;
    return 0;
}
