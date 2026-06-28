/**
 * @file GpioPinOutOfRange.cpp
 * @brief 负向编译:GPIO Pin 超过 31 必须编译失败。
 *
 * 预期失败原因:GPIO<Bank,Pin> 的 requires(Bank <= 2 && Pin <= 31) 约束不满足。
 */
#include "Drivers/GPIO.hpp"

using Bad = Hardware::Drivers::GPIO<0, 32>; // Pin 32 越界(每 Bank 仅 0–31)

int main() {
    Bad::Read(); // 实例化以触发约束失败
    return 0;
}
