/**
 * @file DriverZeroOverheadProbes.cpp
 * @brief 驱动层零开销验证探针:把若干驱动访问器封进 extern "C" 包装,供 objdump 按符号
 *        逐项核对生成指令。本文件由 SConstruct 用 arm-none-eabi-g++ -O2 编译再反汇编断言。
 *
 * 核心要守住的零开销契约:
 *  - GPIO 的方向/电平动作在带 SET/CLR/TOG 别名的 PINCTRL 后端上 = 单条原子 str,无 RMW 回读、无 bl;
 *  - GPIO::Read = 单条 ldr 间接访存 + 掩码,无 bl;
 *  - 外设模块时钟门控 / 单字段原子置清(LCDIF/GPMI)= 单条原子 str,无 bl。
 *
 * 函数体均含 volatile MMIO,故 -O2 下不会被优化掉;extern "C" 保证符号名稳定可被脚本定位。
 */

#include "Drivers/GPIO.hpp"
#include "Drivers/GPMI.hpp"
#include "Drivers/LCDIF.hpp"

using LcdReset = Hardware::Drivers::GPIO<1, 18>; /**< 固定 (Bank1,Pin18) 引脚门面。 */
using LcdifDriver = Hardware::Drivers::LCDIF;
using GpmiDriver = Hardware::Drivers::GPMI;

extern "C" {

/* ============================ GPIO 原子位动作 ============================ */
void ProbeGpioConfigureAsOutput() { LcdReset::ConfigureAsOutput(); } // 1×str→DOE SET 别名
void ProbeGpioConfigureAsInput() { LcdReset::ConfigureAsInput(); }   // 1×str→DOE CLR 别名
void ProbeGpioSetHigh() { LcdReset::SetHigh(); }                     // 1×str→DOUT SET 别名
void ProbeGpioSetLow() { LcdReset::SetLow(); }                       // 1×str→DOUT CLR 别名
void ProbeGpioToggle() { LcdReset::Toggle(); }                       // 1×str→DOUT TOG 别名
bool ProbeGpioRead() { return LcdReset::Read(); }                    // 1×ldr 间接 + 掩码,无 bl

/* ===================== 外设模块时钟门控 / 字段原子置清 ===================== */
void ProbeLcdifEnableClock() { LcdifDriver::EnableClock(); }     // 清 CLKGATE = 1×str→CLR 别名
void ProbeLcdifAssertReset() { LcdifDriver::AssertLcdReset(); }  // 清 CTRL1.RESET = 1×str→CLR 别名
void ProbeLcdifRun() { LcdifDriver::Run(); }                     // 置 CTRL.RUN = 1×str→SET 别名
void ProbeGpmiEnableEcc() { GpmiDriver::EnableEcc(); }           // 置 ECCCTRL.ENABLE_ECC = 1×str→SET 别名
void ProbeGpmiSetNandMode() { GpmiDriver::SetNandMode(); }       // 清 CTRL1.GPMI_MODE = 1×str→CLR 别名

} // extern "C"
