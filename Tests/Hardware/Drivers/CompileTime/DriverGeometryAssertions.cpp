/**
 * @file DriverGeometryAssertions.cpp
 * @brief 驱动层编译期几何断言:把 DMA 描述符布局、命令字位打包、BSP 板级常量、
 *        键盘矩阵规模、驱动访问器的 noexcept 性等固化为可回归真值。
 *
 * 这些 static_assert 不触碰任何 MMIO(GPIO/外设访问只在 noexcept() 的非求值上下文
 * 出现),编译通过即代表几何/类型契约成立;任何位布局或接线笔误都会让编译失败。
 * 可主机与目标双侧编译。
 */

#include "BSP.hpp"
#include "Drivers/Common/DmaDescriptor.hpp"
#include "Drivers/GPIO.hpp"

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace {

using namespace Hardware::Drivers::Common;
namespace BSP = Hardware::BSP;

/* ===================== DMA 描述符内存布局 ===================== */
// ARM926 D-cache 行 32 字节:描述符独占 32 字节对齐,clean/invalidate 不牵连邻数据。
static_assert(alignof(DmaDescriptor<1>) == 32u, "描述符须 32 字节对齐");
static_assert(alignof(DmaDescriptor<0>) == 32u, "无 PIO 字描述符亦 32 字节对齐");
static_assert(offsetof(DmaDescriptor<1>, next) == 0u, "NEXT 在 +0x00");
static_assert(offsetof(DmaDescriptor<1>, command) == 4u, "CMD 在 +0x04");
static_assert(offsetof(DmaDescriptor<1>, bufferAddress) == 8u, "BAR 在 +0x08");
static_assert(offsetof(DmaDescriptor<1>, pio) == 12u, "PIO 字数组在 +0x0C");
// 头部 12 字节 + PIO 字,凑齐到 32 的整数倍;≤5 个 PIO 字仍是一个 32 字节描述符。
static_assert(sizeof(DmaDescriptor<0>) == 32u);
static_assert(sizeof(DmaDescriptor<1>) == 32u);
static_assert(sizeof(DmaDescriptor<3>) == 32u);
static_assert(sizeof(DmaDescriptor<5>) == 32u, "12+5*4=32,正好一行");

/* ===================== DMA 命令字位打包 ===================== */
static_assert(BuildCommand({}) == 0u, "全默认 = 0");
static_assert(BuildCommand({.transferType = DmaTransferType::MemoryToDevice}) == 0x2u,
              "COMMAND 位[1:0] = 内存→外设(2)");
static_assert(BuildCommand({.transferType = DmaTransferType::DeviceToMemory}) == 0x1u,
              "COMMAND 位[1:0] = 外设→内存(1)");
static_assert(BuildCommand({.pioWordCount = 3}) == (3u << 12), "CMDWORDS 位[15:12]");
static_assert(BuildCommand({.transferCount = 0x200}) == (0x200u << 16), "XFER_COUNT 位[31:16]");
static_assert(BuildCommand({.chain = true}) == (1u << 2), "CHAIN 位 2");
static_assert(BuildCommand({.interruptOnCompletion = true}) == (1u << 3), "IRQONCMPLT 位 3");
static_assert(BuildCommand({.semaphore = true}) == (1u << 6), "SEMAPHORE 位 6");
static_assert(BuildCommand({.waitForEndCommand = true}) == (1u << 7), "WAIT4ENDCMD 位 7");
static_assert(BuildCommand({.nandLock = true}) == (1u << 4), "NANDLOCK 位 4");
static_assert(BuildCommand({.nandWaitForReady = true}) == (1u << 5), "NANDWAIT4READY 位 5");
static_assert(BuildCommand({.haltOnTerminate = true}) == (1u << 8), "HALTONTERMINATE 位 8");
// 组合:一条 LCDIF 帧描述符(内存→外设、链接、完成中断、1 个 PIO 字、512 字节)。
static_assert(BuildCommand({.transferType = DmaTransferType::MemoryToDevice,
                            .transferCount = 512,
                            .pioWordCount = 1,
                            .chain = true,
                            .interruptOnCompletion = true}) ==
                  ((512u << 16) | (1u << 12) | (1u << 3) | (1u << 2) | 0x2u),
              "组合命令字按位或叠加");

/* ===================== BSP 板级常量与几何 ===================== */
static_assert(BSP::PllFrequencyHz == 480'000'000u);
static_assert(BSP::CpuFrequencyHz == 78'545'454u, "PLL*18/22/5 取整");
static_assert(BSP::HBusFrequencyHz == 240'000'000u);
static_assert(BSP::GpmiFrequencyHz == 240'000'000u);
static_assert(BSP::LcdifPixelFrequencyHz == 24'000'000u);
static_assert(BSP::FrameBufferSizeBytes == 256u * 127u, "8bpp 帧缓冲 = 宽*高");
static_assert(BSP::BatteryCodeToMillivolts(0u) == 0u);
static_assert(BSP::BatteryCodeToMillivolts(500u) == 4000u, "500 码 * 8mV");
static_assert(noexcept(BSP::BatteryCodeToMillivolts(0u)), "换算为 noexcept 纯函数");

/* ===================== 键盘矩阵规模 ===================== */
static_assert(BSP::KeyboardMatrix::DriveCount == 10u, "10 条驱动线");
static_assert(BSP::KeyboardMatrix::SenseCount == 5u, "5 条读取线");
// PinGroup::PinAt 取出的类型即对应 GPIO<Bank,Pin>(下标 0 = 固件 row0 = GPIO<2,6>)。
static_assert(std::is_same_v<BSP::KeyboardDriveLines::PinAt<0>, BSP::GPIO<2, 6>>);
static_assert(std::is_same_v<BSP::KeyboardSenseLines::PinAt<0>, BSP::GPIO<1, 23>>);

/* ===================== GPIO 复用值与访问器 noexcept ===================== */
using LcdReset = Hardware::Drivers::GPIO<1, 18>;
static_assert(static_cast<std::uint32_t>(LcdReset::MuxFunction::Gpio) == 3u, "GPIO 模式 = MUXSEL 3");
static_assert(noexcept(LcdReset::SetHigh()), "SetHigh 为 noexcept");
static_assert(noexcept(LcdReset::SetLow()), "SetLow 为 noexcept");
static_assert(noexcept(LcdReset::Toggle()), "Toggle 为 noexcept");
static_assert(noexcept(LcdReset::Read()), "Read 为 noexcept");
static_assert(noexcept(LcdReset::ConfigureAsOutput()), "ConfigureAsOutput 为 noexcept");

} // namespace

int main() { return 0; }
