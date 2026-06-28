#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_LRADC
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_LRADC

/**
 * @file LRADC.hpp
 * @brief LRADC 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 LRADC 外设寄存器与位域中文描述
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::LRADC {

    /** @brief LRADC 控制寄存器 0，负责通道调度、触摸屏电极使能、片内地参考及模块级时钟/复位控制。 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050000, 0x80050004, 0x80050008, 0x8005000C, LowLevel::Access::ReadWrite>;
        using SCHEDULE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 8 位按位调度掩码，置位对应位即启动 LRADC 通道 0~7 的 ADC 转换。 */
        /** @brief XPLUS_ENABLE 的取值。 */
        enum class XPLUS_ENABLE_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using XPLUS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, XPLUS_ENABLE_Values>; /**< 触摸屏 X+ 电极驱动使能，ON 时接通 X+ 面板电极用于坐标采样。 */
        /** @brief YPLUS_ENABLE 的取值。 */
        enum class YPLUS_ENABLE_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using YPLUS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, YPLUS_ENABLE_Values>; /**< 触摸屏 Y+ 电极驱动使能，ON 时接通 Y+ 面板电极用于坐标采样。 */
        /** @brief XMINUS_ENABLE 的取值。 */
        enum class XMINUS_ENABLE_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using XMINUS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, XMINUS_ENABLE_Values>; /**< 触摸屏 X- 电极驱动使能，ON 时接通 X- 面板电极用于坐标采样。 */
        /** @brief YMINUS_ENABLE 的取值。 */
        enum class YMINUS_ENABLE_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using YMINUS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, YMINUS_ENABLE_Values>; /**< 触摸屏 Y- 电极驱动使能，ON 时接通 Y- 面板电极用于坐标采样。 */
        /** @brief TOUCH_DETECT_ENABLE 的取值。 */
        enum class TOUCH_DETECT_ENABLE_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using TOUCH_DETECT_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, TOUCH_DETECT_ENABLE_Values>; /**< 触摸检测功能使能，ON 时启用面板触摸按下/释放检测逻辑。 */
        /** @brief ONCHIP_GROUNDREF 的取值。 */
        enum class ONCHIP_GROUNDREF_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using ONCHIP_GROUNDREF = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, ONCHIP_GROUNDREF_Values>; /**< 片内地参考使能，ON 时使用芯片内部地作为 ADC 参考地。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 时钟门控控制，置位时关闭 LRADC 模块时钟以节省功耗。 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 软复位控制，置位时对 LRADC 模块执行软件复位。 */
    } // namespace CTRL0

    /** @brief LRADC 控制寄存器 1，管理各通道转换完成中断状态及对应中断使能。 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050010, 0x80050014, 0x80050018, 0x8005001C, LowLevel::Access::ReadWrite>;
        /** @brief LRADC0_IRQ 的取值。 */
        enum class LRADC0_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC0_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, LRADC0_IRQ_Values>; /**< LRADC 通道 0 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC1_IRQ 的取值。 */
        enum class LRADC1_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC1_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, LRADC1_IRQ_Values>; /**< LRADC 通道 1 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC2_IRQ 的取值。 */
        enum class LRADC2_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC2_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, LRADC2_IRQ_Values>; /**< LRADC 通道 2 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC3_IRQ 的取值。 */
        enum class LRADC3_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC3_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, LRADC3_IRQ_Values>; /**< LRADC 通道 3 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC4_IRQ 的取值。 */
        enum class LRADC4_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC4_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, LRADC4_IRQ_Values>; /**< LRADC 通道 4 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC5_IRQ 的取值。 */
        enum class LRADC5_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC5_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, LRADC5_IRQ_Values>; /**< LRADC 通道 5 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC6_IRQ 的取值。 */
        enum class LRADC6_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC6_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, LRADC6_IRQ_Values>; /**< LRADC 通道 6 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief LRADC7_IRQ 的取值。 */
        enum class LRADC7_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using LRADC7_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, LRADC7_IRQ_Values>; /**< LRADC 通道 7 转换完成中断状态，PENDING 表示中断挂起，写 CLEAR 清除。 */
        /** @brief TOUCH_DETECT_IRQ 的取值。 */
        enum class TOUCH_DETECT_IRQ_Values : std::uint32_t {
            CLEAR = 0x0,
            PENDING = 0x1,
        };
        using TOUCH_DETECT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, TOUCH_DETECT_IRQ_Values>; /**< 触摸检测中断状态，PENDING 表示检测到触摸事件，写 CLEAR 清除。 */
        /** @brief LRADC0_IRQ_EN 的取值。 */
        enum class LRADC0_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC0_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, LRADC0_IRQ_EN_Values>; /**< LRADC 通道 0 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC1_IRQ_EN 的取值。 */
        enum class LRADC1_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC1_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, LRADC1_IRQ_EN_Values>; /**< LRADC 通道 1 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC2_IRQ_EN 的取值。 */
        enum class LRADC2_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC2_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, LRADC2_IRQ_EN_Values>; /**< LRADC 通道 2 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC3_IRQ_EN 的取值。 */
        enum class LRADC3_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC3_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, LRADC3_IRQ_EN_Values>; /**< LRADC 通道 3 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC4_IRQ_EN 的取值。 */
        enum class LRADC4_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC4_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, LRADC4_IRQ_EN_Values>; /**< LRADC 通道 4 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC5_IRQ_EN 的取值。 */
        enum class LRADC5_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC5_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, LRADC5_IRQ_EN_Values>; /**< LRADC 通道 5 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC6_IRQ_EN 的取值。 */
        enum class LRADC6_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC6_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, LRADC6_IRQ_EN_Values>; /**< LRADC 通道 6 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief LRADC7_IRQ_EN 的取值。 */
        enum class LRADC7_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using LRADC7_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, LRADC7_IRQ_EN_Values>; /**< LRADC 通道 7 转换完成中断使能，ENABLE 时允许该通道转换结束后产生中断。 */
        /** @brief TOUCH_DETECT_IRQ_EN 的取值。 */
        enum class TOUCH_DETECT_IRQ_EN_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using TOUCH_DETECT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, TOUCH_DETECT_IRQ_EN_Values>; /**< 触摸检测中断使能，ENABLE 时允许触摸检测事件产生中断。 */
    } // namespace CTRL1

    /** @brief LRADC 控制寄存器 2，配置温度传感器电流源、背光控制及各通道输入分频。 */
    namespace CTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050020, 0x80050024, 0x80050028, 0x8005002C, LowLevel::Access::ReadWrite>;
        /** @brief TEMP_ISRC0 的取值。 */
        enum class TEMP_ISRC0_Values : std::uint32_t {
            _300 = 0xF,
            _280 = 0xE,
            _260 = 0xD,
            _240 = 0xC,
            _220 = 0xB,
            _200 = 0xA,
            _180 = 0x9,
            _160 = 0x8,
            _140 = 0x7,
            _120 = 0x6,
            _100 = 0x5,
            _80 = 0x4,
            _60 = 0x3,
            _40 = 0x2,
            _20 = 0x1,
            ZERO = 0x0,
        };
        using TEMP_ISRC0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, TEMP_ISRC0_Values>; /**< 温度传感器 0 电流源强度选择，枚举值从 300μA 递减至 0μA，用于温感二极管偏置。 */
        /** @brief TEMP_ISRC1 的取值。 */
        enum class TEMP_ISRC1_Values : std::uint32_t {
            _300 = 0xF,
            _280 = 0xE,
            _260 = 0xD,
            _240 = 0xC,
            _220 = 0xB,
            _200 = 0xA,
            _180 = 0x9,
            _160 = 0x8,
            _140 = 0x7,
            _120 = 0x6,
            _100 = 0x5,
            _80 = 0x4,
            _60 = 0x3,
            _40 = 0x2,
            _20 = 0x1,
            ZERO = 0x0,
        };
        using TEMP_ISRC1 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, TEMP_ISRC1_Values>; /**< 温度传感器 1 电流源强度选择，枚举值从 300μA 递减至 0μA，用于温感二极管偏置。 */
        /** @brief TEMP_SENSOR_IENABLE0 的取值。 */
        enum class TEMP_SENSOR_IENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using TEMP_SENSOR_IENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, TEMP_SENSOR_IENABLE0_Values>; /**< 温度传感器 0 电流源使能，ENABLE 时打开 TEMP0 的恒流源供电。 */
        /** @brief TEMP_SENSOR_IENABLE1 的取值。 */
        enum class TEMP_SENSOR_IENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using TEMP_SENSOR_IENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, TEMP_SENSOR_IENABLE1_Values>; /**< 温度传感器 1 电流源使能，ENABLE 时打开 TEMP1 的恒流源供电。 */
        using EXT_EN0 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< 外部扩展使能 0，控制外部模拟通路或扩展通道的开关。 */
        /** @brief EXT_EN1 的取值。 */
        enum class EXT_EN1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using EXT_EN1 = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, EXT_EN1_Values>; /**< 外部扩展使能 1，控制外部模拟通路或扩展通道的开关。 */
        /** @brief TEMPSENSE_PWD 的取值。 */
        enum class TEMPSENSE_PWD_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using TEMPSENSE_PWD = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, TEMPSENSE_PWD_Values>; /**< 温度传感器掉电控制，ENABLE 时关闭温感电路以节省功耗。 */
        using BL_BRIGHTNESS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, std::uint32_t>; /**< 背光亮度等级设置，5 位数值用于控制背光 PWM 或 DAC 亮度输出。 */
        using BL_MUX_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< 背光多路选择器控制，用于选择背光驱动信号的输入源。 */
        using BL_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< 背光模块使能，置位时打开背光驱动电路。 */
        /** @brief BL_AMP_BYPASS 的取值。 */
        enum class BL_AMP_BYPASS_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using BL_AMP_BYPASS = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, BL_AMP_BYPASS_Values>; /**< 背光放大器旁路使能，ENABLE 时绕过背光放大器直接输出。 */
        using DIVIDE_BY_TWO = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 各通道输入二分频使能掩码，8 位按位控制通道 0~7 的输入是否先经 1/2 分压再进入 ADC。 */
    } // namespace CTRL2

    /** @brief LRADC 控制寄存器 3，配置 ADC 采样时钟相位、采样高电平时间、转换周期、模拟电源强制状态及初始丢弃样本数。 */
    namespace CTRL3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050030, 0x80050034, 0x80050038, 0x8005003C, LowLevel::Access::ReadWrite>;
        /** @brief INVERT_CLOCK 的取值。 */
        enum class INVERT_CLOCK_Values : std::uint32_t {
            NORMAL = 0x0,
            INVERT = 0x1,
        };
        using INVERT_CLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, INVERT_CLOCK_Values>; /**< ADC 采样时钟相位反转控制，INVERT 时翻转采样时钟极性。 */
        /** @brief DELAY_CLOCK 的取值。 */
        enum class DELAY_CLOCK_Values : std::uint32_t {
            NORMAL = 0x0,
            DELAYED = 0x1,
        };
        using DELAY_CLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, DELAY_CLOCK_Values>; /**< ADC 采样时钟延迟控制，DELAYED 时引入额外时钟延迟以调整采样相位。 */
        /** @brief HIGH_TIME 的取值。 */
        enum class HIGH_TIME_Values : std::uint32_t {
            _42NS = 0x0,
            _83NS = 0x1,
            _125NS = 0x2,
            _250NS = 0x3,
        };
        using HIGH_TIME = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, HIGH_TIME_Values>; /**< ADC 采样高电平保持时间选择，决定采样开关导通时长(42/83/125/250 ns)。 */
        /** @brief CYCLE_TIME 的取值。 */
        enum class CYCLE_TIME_Values : std::uint32_t {
            _6MHZ = 0x0,
            _4MHZ = 0x1,
            _3MHZ = 0x2,
            _2MHZ = 0x3,
        };
        using CYCLE_TIME = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, CYCLE_TIME_Values>; /**< ADC 转换周期时间选择，决定采样速率对应的时钟频率(6/4/3/2 MHz)。 */
        /** @brief FORCE_ANALOG_PWDN 的取值。 */
        enum class FORCE_ANALOG_PWDN_Values : std::uint32_t {
            ON = 0x0,
            OFF = 0x1,
        };
        using FORCE_ANALOG_PWDN = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, FORCE_ANALOG_PWDN_Values>; /**< 强制模拟电路掉电控制，ON 时强制关闭模拟部分电源。 */
        /** @brief FORCE_ANALOG_PWUP 的取值。 */
        enum class FORCE_ANALOG_PWUP_Values : std::uint32_t {
            OFF = 0x0,
            ON = 0x1,
        };
        using FORCE_ANALOG_PWUP = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, FORCE_ANALOG_PWUP_Values>; /**< 强制模拟电路上电控制，ON 时强制开启模拟部分电源。 */
        /** @brief DISCARD 的取值。 */
        enum class DISCARD_Values : std::uint32_t {
            _1_SAMPLE = 0x1,
            _2_SAMPLES = 0x2,
            _3_SAMPLES = 0x3,
        };
        using DISCARD = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, DISCARD_Values>; /**< 初始丢弃样本数选择，启动后自动丢弃前 1/2/3 个样本以稳定 ADC 结果。 */
    } // namespace CTRL3

    /** @brief LRADC 状态寄存器，反映触摸检测原始状态、各通道及外设的存在性标志。 */
    namespace STATUS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80050040, LowLevel::Access::ReadOnly>;
        /** @brief TOUCH_DETECT_RAW 的取值。 */
        enum class TOUCH_DETECT_RAW_Values : std::uint32_t {
            OPEN = 0x0,
            HIT = 0x1,
        };
        using TOUCH_DETECT_RAW = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, TOUCH_DETECT_RAW_Values>; /**< 触摸检测原始状态，OPEN 表示未触摸，HIT 表示面板被触摸。 */
        using CHANNEL0_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 通道 0 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL1_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 通道 1 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL2_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< 通道 2 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL3_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< 通道 3 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL4_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 通道 4 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL5_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< 通道 5 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL6_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< 通道 6 存在性标志，置位表示该物理通道可用。 */
        using CHANNEL7_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 通道 7 存在性标志，置位表示该物理通道可用。 */
        using TOUCH_PANEL_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 触摸屏面板存在性标志，置位表示触摸面板已连接。 */
        using TEMP0_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< 温度传感器 0 存在性标志，置位表示 TEMP0 通道可用。 */
        using TEMP1_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< 温度传感器 1 存在性标志，置位表示 TEMP1 通道可用。 */
    } // namespace STATUS

    /** @brief LRADC 通道结果寄存器(数组 CH0~CH5)，存储 ADC 转换结果并控制累加模式。 */
    namespace CH0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050050, 0x80050054, 0x80050058, 0x8005005C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放该通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数(0~31 对应 1~32 次)。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH0

    /** @brief LRADC 通道结果寄存器(数组 CH0~CH5)，存储 ADC 转换结果并控制累加模式。 */
    namespace CH1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050060, 0x80050064, 0x80050068, 0x8005006C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放该通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数(0~31 对应 1~32 次)。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH1

    /** @brief LRADC 通道结果寄存器(数组 CH0~CH5)，存储 ADC 转换结果并控制累加模式。 */
    namespace CH2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050070, 0x80050074, 0x80050078, 0x8005007C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放该通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数(0~31 对应 1~32 次)。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH2

    /** @brief LRADC 通道结果寄存器(数组 CH0~CH5)，存储 ADC 转换结果并控制累加模式。 */
    namespace CH3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050080, 0x80050084, 0x80050088, 0x8005008C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放该通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数(0~31 对应 1~32 次)。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH3

    /** @brief LRADC 通道结果寄存器(数组 CH0~CH5)，存储 ADC 转换结果并控制累加模式。 */
    namespace CH4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050090, 0x80050094, 0x80050098, 0x8005009C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放该通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数(0~31 对应 1~32 次)。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH4

    /** @brief LRADC 通道结果寄存器(数组 CH0~CH5)，存储 ADC 转换结果并控制累加模式。 */
    namespace CH5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800500A0, 0x800500A4, 0x800500A8, 0x800500AC, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放该通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数(0~31 对应 1~32 次)。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH5

    /** @brief LRADC 通道 6 结果寄存器(VddIO)，存储 VddIO 电压采样结果并支持累加模式。 */
    namespace CH6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800500B0, 0x800500B4, 0x800500B8, 0x800500BC, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放 VddIO 通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH6

    /** @brief LRADC 通道 7 结果寄存器(BATT)，存储电池电压采样结果并支持累加与测试模式。 */
    namespace CH7 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800500C0, 0x800500C4, 0x800500C8, 0x800500CC, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 18, std::uint32_t>; /**< 18 位 ADC 转换结果值，存放电池通道最近一次或累加后的采样数据。 */
        using NUM_SAMPLES = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< 累加样本数配置，指定一次累加转换中需采样的次数。 */
        using ACCUMULATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 累加使能，置位时启用多次采样累加模式以提高分辨率/抑制噪声。 */
        using TESTMODE_TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 测试模式翻转控制，用于调试时手动翻转通道 7 的测试状态位。 */
        using TOGGLE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 通道结果翻转标志，硬件在每次更新结果时自动翻转，软件可用于判断新数据是否就绪。 */
    } // namespace CH7

    /** @brief LRADC 延迟触发寄存器(数组 DELAY0~DELAY3)，配置定时延迟、循环计数及触发链。 */
    namespace DELAY0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800500D0, 0x800500D4, 0x800500D8, 0x800500DC, LowLevel::Access::ReadWrite>;
        using DELAY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< 延迟计数值，指定该延迟槽的定时长度，用于控制采样触发的时间间隔。 */
        using LOOP_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 5, std::uint32_t>; /**< 循环次数配置，指定该延迟序列需重复执行的次数。 */
        using TRIGGER_DELAYS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< 延迟链触发掩码，4 位按位选择该延迟到期后触发哪些其他 DELAY 槽。 */
        using KICK = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 延迟启动触发位，写 1 立即启动该延迟槽的计数器。 */
        using TRIGGER_LRADCS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< LRADC 通道触发掩码，8 位按位选择该延迟到期后触发哪些 LRADC 通道开始转换。 */
    } // namespace DELAY0

    /** @brief LRADC 延迟触发寄存器(数组 DELAY0~DELAY3)，配置定时延迟、循环计数及触发链。 */
    namespace DELAY1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800500E0, 0x800500E4, 0x800500E8, 0x800500EC, LowLevel::Access::ReadWrite>;
        using DELAY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< 延迟计数值，指定该延迟槽的定时长度，用于控制采样触发的时间间隔。 */
        using LOOP_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 5, std::uint32_t>; /**< 循环次数配置，指定该延迟序列需重复执行的次数。 */
        using TRIGGER_DELAYS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< 延迟链触发掩码，4 位按位选择该延迟到期后触发哪些其他 DELAY 槽。 */
        using KICK = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 延迟启动触发位，写 1 立即启动该延迟槽的计数器。 */
        using TRIGGER_LRADCS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< LRADC 通道触发掩码，8 位按位选择该延迟到期后触发哪些 LRADC 通道开始转换。 */
    } // namespace DELAY1

    /** @brief LRADC 延迟触发寄存器(数组 DELAY0~DELAY3)，配置定时延迟、循环计数及触发链。 */
    namespace DELAY2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800500F0, 0x800500F4, 0x800500F8, 0x800500FC, LowLevel::Access::ReadWrite>;
        using DELAY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< 延迟计数值，指定该延迟槽的定时长度，用于控制采样触发的时间间隔。 */
        using LOOP_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 5, std::uint32_t>; /**< 循环次数配置，指定该延迟序列需重复执行的次数。 */
        using TRIGGER_DELAYS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< 延迟链触发掩码，4 位按位选择该延迟到期后触发哪些其他 DELAY 槽。 */
        using KICK = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 延迟启动触发位，写 1 立即启动该延迟槽的计数器。 */
        using TRIGGER_LRADCS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< LRADC 通道触发掩码，8 位按位选择该延迟到期后触发哪些 LRADC 通道开始转换。 */
    } // namespace DELAY2

    /** @brief LRADC 延迟触发寄存器(数组 DELAY0~DELAY3)，配置定时延迟、循环计数及触发链。 */
    namespace DELAY3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050100, 0x80050104, 0x80050108, 0x8005010C, LowLevel::Access::ReadWrite>;
        using DELAY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< 延迟计数值，指定该延迟槽的定时长度，用于控制采样触发的时间间隔。 */
        using LOOP_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 5, std::uint32_t>; /**< 循环次数配置，指定该延迟序列需重复执行的次数。 */
        using TRIGGER_DELAYS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< 延迟链触发掩码，4 位按位选择该延迟到期后触发哪些其他 DELAY 槽。 */
        using KICK = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 延迟启动触发位，写 1 立即启动该延迟槽的计数器。 */
        using TRIGGER_LRADCS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< LRADC 通道触发掩码，8 位按位选择该延迟到期后触发哪些 LRADC 通道开始转换。 */
    } // namespace DELAY3

    /** @brief LRADC 调试寄存器 0，提供状态机状态及只读调试信息。 */
    namespace DEBUG0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80050110, LowLevel::Access::ReadOnly>;
        using STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 12, std::uint32_t>; /**< LRADC 内部状态机当前状态值，12 位用于调试跟踪控制器运行阶段。 */
        using READONLY = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 只读调试数据，16 位硬件内部调试信号供分析使用。 */
    } // namespace DEBUG0

    /** @brief LRADC 调试寄存器 1，提供测试模式控制、测试计数及请求信号调试。 */
    namespace DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80050120, LowLevel::Access::ReadOnly>;
        /** @brief TESTMODE 的取值。 */
        enum class TESTMODE_Values : std::uint32_t {
            NORMAL = 0x0,
            TEST = 0x1,
        };
        using TESTMODE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, TESTMODE_Values>; /**< 测试模式总开关，TEST 时启用 LRADC 整体测试模式。 */
        /** @brief TESTMODE5 的取值。 */
        enum class TESTMODE5_Values : std::uint32_t {
            NORMAL = 0x0,
            TEST = 0x1,
        };
        using TESTMODE5 = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, TESTMODE5_Values>; /**< 测试模式 5 控制，TEST 时启用通道 5 相关测试逻辑。 */
        /** @brief TESTMODE6 的取值。 */
        enum class TESTMODE6_Values : std::uint32_t {
            NORMAL = 0x0,
            TEST = 0x1,
        };
        using TESTMODE6 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, TESTMODE6_Values>; /**< 测试模式 6 控制，TEST 时启用通道 6 相关测试逻辑。 */
        using TESTMODE_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 5, std::uint32_t>; /**< 测试模式计数配置，指定测试序列的计数长度。 */
        using REQUEST = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 8 位请求调试信号，反映内部各通道的转换请求状态。 */
    } // namespace DEBUG1

    /** @brief LRADC 电池转换寄存器，配置电池类型缩放系数及自动转换使能。 */
    namespace CONVERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80050130, LowLevel::Access::ReadOnly>;
        using SCALED_BATT_VOLTAGE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, std::uint32_t>; /**< 10 位电池电压缩放后值，反映经 SCALE_FACTOR 缩放后的电池电压读数。 */
        /** @brief SCALE_FACTOR 的取值。 */
        enum class SCALE_FACTOR_Values : std::uint32_t {
            NIMH = 0x0,
            DUAL_NIMH = 0x1,
            LI_ION = 0x2,
            ALT_LI_ION = 0x3,
        };
        using SCALE_FACTOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, SCALE_FACTOR_Values>; /**< 电池类型缩放系数选择，决定电池电压到 ADC 量程的映射关系(NiMH/双 NiMH/Li-Ion/替代 Li-Ion)。 */
        /** @brief AUTOMATIC 的取值。 */
        enum class AUTOMATIC_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using AUTOMATIC = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, AUTOMATIC_Values>; /**< 电池自动转换使能，ENABLE 时启用硬件自动电池电压采样与转换。 */
    } // namespace CONVERSION

    /** @brief LRADC 控制寄存器 4，为 8 个虚拟 LRADC 槽分别选择物理输入通道 0~15。 */
    namespace CTRL4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80050140, 0x80050144, 0x80050148, 0x8005014C, LowLevel::Access::ReadWrite>;
        /** @brief LRADC0SELECT 的取值。 */
        enum class LRADC0SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC0SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, LRADC0SELECT_Values>; /**< LRADC 槽 0 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC1SELECT 的取值。 */
        enum class LRADC1SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC1SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, LRADC1SELECT_Values>; /**< LRADC 槽 1 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC2SELECT 的取值。 */
        enum class LRADC2SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC2SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, LRADC2SELECT_Values>; /**< LRADC 槽 2 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC3SELECT 的取值。 */
        enum class LRADC3SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC3SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, LRADC3SELECT_Values>; /**< LRADC 槽 3 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC4SELECT 的取值。 */
        enum class LRADC4SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC4SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, LRADC4SELECT_Values>; /**< LRADC 槽 4 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC5SELECT 的取值。 */
        enum class LRADC5SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC5SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 4, LRADC5SELECT_Values>; /**< LRADC 槽 5 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC6SELECT 的取值。 */
        enum class LRADC6SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC6SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, LRADC6SELECT_Values>; /**< LRADC 槽 6 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
        /** @brief LRADC7SELECT 的取值。 */
        enum class LRADC7SELECT_Values : std::uint32_t {
            CHANNEL0 = 0x0,
            CHANNEL1 = 0x1,
            CHANNEL2 = 0x2,
            CHANNEL3 = 0x3,
            CHANNEL4 = 0x4,
            CHANNEL5 = 0x5,
            CHANNEL6 = 0x6,
            CHANNEL7 = 0x7,
            CHANNEL8 = 0x8,
            CHANNEL9 = 0x9,
            CHANNEL10 = 0xA,
            CHANNEL11 = 0xB,
            CHANNEL12 = 0xC,
            CHANNEL13 = 0xD,
            CHANNEL14 = 0xE,
            CHANNEL15 = 0xF,
        };
        using LRADC7SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 4, LRADC7SELECT_Values>; /**< LRADC 槽 7 物理通道选择，4 位编码从 16 路输入通道中选定通道 0~15。 */
    } // namespace CTRL4

    /** @brief LRADC 版本寄存器，记录 IP 核的主版本、次版本及步进号。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80050150, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 16 位步进版本号，标识当前 IP 核的修订步进。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 8 位次版本号，标识当前 IP 核的次要版本。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 8 位主版本号，标识当前 IP 核的主要版本。 */
    } // namespace VERSION

} // namespace Hardware::Registers::LRADC

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_LRADC
