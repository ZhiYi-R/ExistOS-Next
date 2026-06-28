#ifndef EXIST_OS_NEXT_HARDWARE_BSP
#define EXIST_OS_NEXT_HARDWARE_BSP

/**
 * @file BSP.hpp
 * @brief HP39GII 板级支持包:把"具体板子的硬件连线"集中为编译期常量与类型别名,使驱动层解耦。
 *
 * 驱动层(Hardware/Drivers/)只描述外设语义、不含任何具体引脚或频率;本头是**板级合成根**:
 * 单向依赖驱动(`#include "Drivers/…"`),把 HP39GII(STMP3770)实际的时钟频率、屏幕几何、
 * GPIO 引脚连线、键盘矩阵接线、DMA 通道、电池换算汇集于此。驱动绝不反向引用 BSP::。
 *
 * 硬件事实来源:原固件 ExistOS-Team/ExistOS-For-HP39GII(stmp_clkctrl.c / stmp_board.c /
 * stmp_lcdif.c / input/stmp_gpio.c),寄存器几何以本仓库生成头为准。
 *
 * @note 时钟频率为复位后固件配置的稳态值;若 bring-up 改了 CLKCTRL 分频,这里须同步。
 */

#include "Drivers/GPIO.hpp"
#include "Drivers/Keyboard.hpp"
#include <cstdint>

namespace Hardware::BSP {

    /** @brief GPIO 门面别名(本板引脚类型基于编译期参数化 GPIO<Bank,Pin>)。 */
    template <std::uint32_t Bank, std::uint32_t Pin>
    using GPIO = Drivers::GPIO<Bank, Pin>;

    // ============================================================
    //                         时钟频率
    // ============================================================
    // i.MX23 时钟树:PLL=480MHz;各 ref 时钟 = PLL*18/FRAC(FRAC∈[18,35]),再经整数分频。
    // 数值取自固件 stmp_clkctrl.c 的稳态配置。

    /** @brief 锁相环输出频率(Hz)。 */
    inline constexpr std::uint32_t PllFrequencyHz = 480'000'000u;

    /** @brief CPU 时钟小数分频(CLKCTRL_FRAC.CPUFRAC,固件配 22)。 */
    inline constexpr std::uint32_t CpuFractionalDivider = 22u;
    /** @brief CPU 时钟整数分频(CLKCTRL_CPU.DIV_CPU,固件配 5)。 */
    inline constexpr std::uint32_t CpuIntegerDivider = 5u;
    /**
     * @brief CPU 时钟频率(Hz)= PLL*18/CPUFRAC/DIV_CPU ≈ 78.5MHz。
     * @note 由真实分频推导(非整除,取整);供 OS 层换算 TIMROT 计时基准等用途,裸金属层不再做忙等延时。
     */
    inline constexpr std::uint32_t CpuFrequencyHz = static_cast<std::uint32_t>(
        static_cast<std::uint64_t>(PllFrequencyHz) * 18u / CpuFractionalDivider / CpuIntegerDivider);

    /** @brief AHB/HBUS 总线时钟(Hz)= PLL/2 = 240MHz。 */
    inline constexpr std::uint32_t HBusFrequencyHz = PllFrequencyHz / 2u;
    /** @brief GPMI(NAND)时钟(Hz)= PLL/2 = 240MHz。 */
    inline constexpr std::uint32_t GpmiFrequencyHz = PllFrequencyHz / 2u;
    /** @brief LCDIF 像素时钟(Hz),固件显式设为 24MHz。 */
    inline constexpr std::uint32_t LcdifPixelFrequencyHz = 24'000'000u;

    // ============================================================
    //                         屏幕几何
    // ============================================================

    /** @brief 屏幕宽度(像素)。 */
    inline constexpr std::uint32_t ScreenWidthPixels = 256u;
    /** @brief 屏幕高度(像素)。 */
    inline constexpr std::uint32_t ScreenHeightPixels = 127u;
    /** @brief 像素位深(LCDIF 以 8 位灰度数据接口驱动面板)。 */
    inline constexpr std::uint32_t ScreenColorBitDepth = 8u;
    /** @brief 帧缓冲字节数(按 8 位/像素)= 宽×高。 */
    inline constexpr std::uint32_t FrameBufferSizeBytes =
        ScreenWidthPixels * ScreenHeightPixels * (ScreenColorBitDepth / 8u);

    // ============================================================
    //                      DMA 通道分配(APBH)
    // ============================================================

    /** @brief LCDIF 帧传输使用的 APBH DMA 通道号。 */
    inline constexpr std::uint32_t LcdifDmaChannel = 0u;
    /** @brief GPMI(NAND)页传输使用的 APBH DMA 通道号。 */
    inline constexpr std::uint32_t GpmiDmaChannel = 4u;

    // ============================================================
    //                  LCD 接口引脚(LCDIF system 模式)
    // ============================================================
    // 这些引脚由 LCDIF 控制器驱动,bring-up 时把其 MUXSEL 设为 LCDIF 复用功能(非 GPIO 模式);
    // 此处别名仅用于定位与一次性 MUX 配置。数据 D0–D7 在 Bank1 引脚 0–7,控制信号在 Bank1 引脚 16–20。

    using LcdData0 = GPIO<1, 0>;  /**< LCD 数据位 0。 */
    using LcdData1 = GPIO<1, 1>;  /**< LCD 数据位 1。 */
    using LcdData2 = GPIO<1, 2>;  /**< LCD 数据位 2。 */
    using LcdData3 = GPIO<1, 3>;  /**< LCD 数据位 3。 */
    using LcdData4 = GPIO<1, 4>;  /**< LCD 数据位 4。 */
    using LcdData5 = GPIO<1, 5>;  /**< LCD 数据位 5。 */
    using LcdData6 = GPIO<1, 6>;  /**< LCD 数据位 6。 */
    using LcdData7 = GPIO<1, 7>;  /**< LCD 数据位 7。 */
    using LcdControl0 = GPIO<1, 16>; /**< LCD 控制信号 0(Bank1 引脚 16)。 */
    using LcdControl1 = GPIO<1, 17>; /**< LCD 控制信号 1(Bank1 引脚 17)。 */
    using LcdControl2 = GPIO<1, 18>; /**< LCD 控制信号 2(Bank1 引脚 18)。 */
    using LcdControl3 = GPIO<1, 19>; /**< LCD 控制信号 3(Bank1 引脚 19)。 */
    using LcdControl4 = GPIO<1, 20>; /**< LCD 控制信号 4(Bank1 引脚 20)。 */

    // ============================================================
    //                  NAND 接口引脚(GPMI)
    // ============================================================
    // 数据/握手由 GPMI 控制器驱动(MUXSEL 设为 GPMI 复用功能);ALE/CLE 不占独立引脚,
    // 由 GPMI_CTRL0.ADDRESS 选 NAND_ALE/NAND_CLE 实现。此处别名用于定位与一次性 MUX 配置。

    using NandData0 = GPIO<0, 0>; /**< NAND 数据位 0。 */
    using NandData1 = GPIO<0, 1>; /**< NAND 数据位 1。 */
    using NandData2 = GPIO<0, 2>; /**< NAND 数据位 2。 */
    using NandData3 = GPIO<0, 3>; /**< NAND 数据位 3。 */
    using NandData4 = GPIO<0, 4>; /**< NAND 数据位 4。 */
    using NandData5 = GPIO<0, 5>; /**< NAND 数据位 5。 */
    using NandData6 = GPIO<0, 6>; /**< NAND 数据位 6。 */
    using NandData7 = GPIO<0, 7>; /**< NAND 数据位 7。 */
    using NandChipEnable0 = GPIO<2, 15>; /**< NAND 片选 CE0N。 */
    using NandReadStrobe = GPIO<0, 25>;  /**< NAND 读选通 RDn。 */
    using NandWriteStrobe = GPIO<0, 24>; /**< NAND 写选通 WRn。 */
    using NandReadyBusy0 = GPIO<0, 19>;  /**< NAND 就绪/忙 RB0。 */
    using NandReset = GPIO<0, 22>;       /**< NAND 复位 RSTn。 */

    // ============================================================
    //                  键盘矩阵接线(GPIO 位扫描)
    // ============================================================
    // 固件电气模型:10 条"驱动线"(输出,逐条拉低选通、空闲高)× 5 条"读取线"(输入,
    // 上拉,按下读低)。另有 1 个独立键经 DIN0.14 直接读取,不在矩形矩阵内。active-low。
    // 驱动线下标 0–9 对应固件 row_line 0–9;读取线下标 0–4 对应固件 col_line 0–4。

    /** @brief 键盘驱动线(输出,逐条选通):固件 row_line 0–9。 */
    using KeyboardDriveLines =
        Drivers::Keyboard::PinGroup<GPIO<2, 6>,  /* row 0 */
                                    GPIO<2, 5>,  /* row 1 */
                                    GPIO<2, 4>,  /* row 2 */
                                    GPIO<2, 2>,  /* row 3 */
                                    GPIO<2, 3>,  /* row 4 */
                                    GPIO<1, 24>, /* row 5 */
                                    GPIO<2, 8>,  /* row 6 */
                                    GPIO<2, 7>,  /* row 7 */
                                    GPIO<0, 20>, /* row 8 */
                                    GPIO<2, 14>  /* row 9 */>;

    /** @brief 键盘读取线(输入,采样选通结果):固件 col_line 0–4。 */
    using KeyboardSenseLines =
        Drivers::Keyboard::PinGroup<GPIO<1, 23>, /* col 0 */
                                    GPIO<1, 25>, /* col 1 */
                                    GPIO<1, 27>, /* col 2 */
                                    GPIO<1, 26>, /* col 3 */
                                    GPIO<1, 22>  /* col 4 */>;

    /** @brief HP39GII 键盘矩阵扫描器(active-low,10 驱动线 × 5 读取线)。 */
    using KeyboardMatrix = Drivers::Keyboard::Matrix<KeyboardDriveLines, KeyboardSenseLines>;

    /** @brief 矩形矩阵外的独立按键输入(DIN0 引脚 14,active-low:按下读低)。 */
    using KeyboardExtraInput = GPIO<0, 14>;

    // ============================================================
    //                         电池换算
    // ============================================================

    /** @brief 电池电压采样所用 LRADC 虚拟通道号。 */
    inline constexpr std::uint32_t BatteryAdcChannel = 7u;
    /** @brief POWER.BATTMONITOR.BATT_VAL 每码对应的毫伏数(单位 8mV/码)。 */
    inline constexpr std::uint32_t BatteryMillivoltsPerCode = 8u;

    /**
     * @brief 把电池监测原始码换算为毫伏(纯函数,可主机测试)。
     * @param batteryCode 10 位 BATT_VAL 原始码。
     * @return 电池电压(毫伏)。
     */
    [[nodiscard]] constexpr std::uint32_t BatteryCodeToMillivolts(std::uint32_t batteryCode) noexcept {
        return batteryCode * BatteryMillivoltsPerCode;
    }

} // namespace Hardware::BSP

#endif // EXIST_OS_NEXT_HARDWARE_BSP
