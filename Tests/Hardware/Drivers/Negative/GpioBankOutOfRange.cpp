/**
 * @file GpioBankOutOfRange.cpp
 * @brief 负向编译:GPIO Bank 超过 2 必须编译失败。
 *
 * 预期失败原因:GPIO<Bank,Pin> 的 requires(Bank <= 2 && Pin <= 31) 约束不满足。
 */
#include "Drivers/GPIO.hpp"

using Bad = Hardware::Drivers::GPIO<3, 0>; // Bank 3 越界(只有 Bank 0–2)

int main() {
    Bad::SetHigh(); // 实例化以触发约束失败
    return 0;
}
