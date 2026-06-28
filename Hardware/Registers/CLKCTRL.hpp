#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_CLKCTRL
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_CLKCTRL

/**
 * @file CLKCTRL.hpp
 * @brief CLKCTRL 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 时钟控制单元 (CLKCTRL)，管理 480MHz USB PLL、CPU/HBUS/XBUS 总线分频、各外设时钟门控与分数分频器、时钟源旁路选择及系统软复位。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::CLKCTRL {

    /** @brief 480MHz USB PLL 控制寄存器 0，控制 PLL 电源、USB 时钟输出使能及环路参数。 */
    namespace PLLCTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040000, 0x80040004, 0x80040008, 0x8004000C, LowLevel::Access::ReadWrite>;
        using POWER = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< PLL 电源使能，置位后启动 PLL 电路供电。 */
        using EN_USB_CLKS = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< USB 时钟输出使能，置位后向 USB 模块提供 PLL 时钟。 */
        /** @brief DIV_SEL 的取值。 */
        enum class DIV_SEL_Values : std::uint32_t {
            DEFAULT = 0x0,
            LOWER = 0x1,
            LOWEST = 0x2,
            UNDEFINED = 0x3,
        };
        using DIV_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, DIV_SEL_Values>; /**< PLL 反馈分频选择，枚举值：DEFAULT=默认分频，LOWER=较低分频，LOWEST=最低分频，UNDEFINED=未定义。 */
        /** @brief CP_SEL 的取值。 */
        enum class CP_SEL_Values : std::uint32_t {
            DEFAULT = 0x0,
            TIMES_2 = 0x1,
            TIMES_05 = 0x2,
            UNDEFINED = 0x3,
        };
        using CP_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, CP_SEL_Values>; /**< PLL 电荷泵电流选择，枚举值：DEFAULT=默认电流，TIMES_2=2 倍电流，TIMES_05=0.5 倍电流，UNDEFINED=未定义。 */
        /** @brief LFR_SEL 的取值。 */
        enum class LFR_SEL_Values : std::uint32_t {
            DEFAULT = 0x0,
            TIMES_2 = 0x1,
            TIMES_05 = 0x2,
            UNDEFINED = 0x3,
        };
        using LFR_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, LFR_SEL_Values>; /**< PLL 低频电阻选择，枚举值：DEFAULT=默认阻值，TIMES_2=2 倍阻值，TIMES_05=0.5 倍阻值，UNDEFINED=未定义。 */
    } // namespace PLLCTRL0

    /** @brief PLL 控制寄存器 1，保留寄存器，反映 PLL 锁定状态与锁定计数。 */
    namespace PLLCTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040010, 0x80040014, 0x80040018, 0x8004001C, LowLevel::Access::ReadWrite>;
        using LOCK_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PLL 锁定计数器值，反映 PLL 从启动到锁定经历的计数周期。 */
        using FORCE_LOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 强制锁定指示，置位后强制声明 PLL 锁定状态。 */
        using LOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< PLL 锁定状态标志，只读，为 1 表示 PLL 已稳定锁定。 */
    } // namespace PLLCTRL1

    /** @brief CPU 时钟控制寄存器，配置 CPU 主时钟与晶振参考时钟的分频比。 */
    namespace CPU {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040020, 0x80040024, 0x80040028, 0x8004002C, LowLevel::Access::ReadWrite>;
        using DIV_CPU = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, std::uint32_t>; /**< CPU 时钟整数分频值，用于 PLL/分数时钟源路径的分频。 */
        using DIV_CPU_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< CPU 时钟分数分频使能，置位后启用 CPU 分数分频模式。 */
        using INTERRUPT_WAIT = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< 中断等待模式使能，置位后 CPU 在时钟切换时等待中断完成。 */
        using DIV_XTAL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 10, std::uint32_t>; /**< 晶振参考时钟整数分频值，用于 XTAL 旁路路径的分频。 */
        using DIV_XTAL_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< 晶振参考时钟分数分频使能，置位后启用 XTAL 路径分数分频模式。 */
        using BUSY_REF_CPU = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< CPU 参考时钟分频忙标志，为 1 表示 DIV_CPU 分频器正在更新。 */
        using BUSY_REF_XTAL = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 晶振参考时钟分频忙标志，为 1 表示 DIV_XTAL 分频器正在更新。 */
    } // namespace CPU

    /** @brief AHB/APBH 总线时钟控制寄存器，配置 HBUS 分频及自动降速策略。 */
    namespace HBUS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040030, 0x80040034, 0x80040038, 0x8004003C, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< AHB 总线整数分频值，决定 HBUS 相对于参考源的时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< AHB 总线分数分频使能，置位后启用 HBUS 分数分频模式。 */
        /** @brief SLOW_DIV 的取值。 */
        enum class SLOW_DIV_Values : std::uint32_t {
            BY1 = 0x0,
            BY2 = 0x1,
            BY4 = 0x2,
            BY8 = 0x3,
            BY16 = 0x4,
            BY32 = 0x5,
        };
        using SLOW_DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 3, SLOW_DIV_Values>; /**< AHB 总线慢速分频选择，枚举值：BY1=1 分频，BY2=2 分频，BY4=4 分频，BY8=8 分频，BY16=16 分频，BY32=32 分频。 */
        using AUTO_SLOW_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 自动慢速模式使能，置位后根据总线负载自动降低 HBUS 频率。 */
        using CPU_INSTR_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< CPU 指令访问自动慢速模式使能，置位后允许 CPU 取指触发自动降速。 */
        using CPU_DATA_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< CPU 数据访问自动慢速模式使能，置位后允许 CPU 数据访问触发自动降速。 */
        using TRAFFIC_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 总线流量自动慢速模式使能，置位后允许总线流量触发自动降速。 */
        using TRAFFIC_JAM_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 总线拥塞自动慢速模式使能，置位后允许总线拥塞触发自动降速。 */
        using APBXDMA_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< APBX DMA 自动慢速模式使能，置位后允许 APBX DMA 触发自动降速。 */
        using APBHDMA_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< APBH DMA 自动慢速模式使能，置位后允许 APBH DMA 触发自动降速。 */
        using PXP_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< PXP 像素处理器自动慢速模式使能，置位后允许 PXP 触发自动降速。 */
        using DCP_AS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< DCP 数据协处理器自动慢速模式使能，置位后允许 DCP 触发自动降速。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< HBUS 时钟分频忙标志，为 1 表示分频器正在更新。 */
    } // namespace HBUS

    /** @brief APBX 总线时钟控制寄存器，配置 APBX 外设总线时钟分频。 */
    namespace XBUS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040040, 0x80040044, 0x80040048, 0x8004004C, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, std::uint32_t>; /**< APBX 总线整数分频值，决定 APBX 相对于参考源的时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< APBX 总线分数分频使能，置位后启用 APBX 分数分频模式。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< APBX 时钟分频忙标志，为 1 表示分频器正在更新。 */
    } // namespace XBUS

    /** @brief 24MHz 晶振时钟门控寄存器，控制各模块从 XTAL 获取的时钟门控。 */
    namespace XTAL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040050, 0x80040054, 0x80040058, 0x8004005C, LowLevel::Access::ReadWrite>;
        using DIV_UART = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< UART 晶振时钟分频值，决定 UART 模块从 24MHz 晶振获取的时钟分频比。 */
        using TIMROT_CLK32K_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< TIMROT 32kHz 时钟门控，置位后关闭 TIMROT 模块的 32kHz 时钟。 */
        using DIGCTRL_CLK1M_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< DIGCTRL 1MHz 时钟门控，置位后关闭 DIGCTRL 模块的 1MHz 时钟。 */
        using DRI_CLK24M_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< DRI 24MHz 时钟门控，置位后关闭 DRI 模块的 24MHz 时钟。 */
        using PWM_CLK24M_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< PWM 24MHz 时钟门控，置位后关闭 PWM 模块的 24MHz 时钟。 */
        using FILT_CLK24M_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< FILT 24MHz 时钟门控，置位后关闭 FILT 模块的 24MHz 时钟。 */
        using UART_CLK_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< UART 时钟总门控，置位后关闭 UART 模块的晶振时钟。 */
    } // namespace XTAL

    /** @brief LCDIF 像素时钟控制寄存器，配置显示像素时钟分频与门控。 */
    namespace PIX {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040060, 0x80040064, 0x80040068, 0x8004006C, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 15, std::uint32_t>; /**< PIX 像素时钟整数分频值，决定 LCDIF 像素时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< PIX 像素时钟分数分频使能，置位后启用 PIX 分数分频模式。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< PIX 时钟分频忙标志，为 1 表示分频器正在更新。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< PIX 时钟门控，置位后关闭 LCDIF 像素时钟输出。 */
    } // namespace PIX

    /** @brief SSP 同步串行端口时钟控制寄存器，配置 SSP 外设时钟分频与门控。 */
    namespace SSP {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040070, 0x80040074, 0x80040078, 0x8004007C, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 9, std::uint32_t>; /**< SSP 时钟整数分频值，决定 SSP 外设时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< SSP 时钟分数分频使能，置位后启用 SSP 分数分频模式。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< SSP 时钟分频忙标志，为 1 表示分频器正在更新。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SSP 时钟门控，置位后关闭 SSP 外设时钟。 */
    } // namespace SSP

    /** @brief GPMI 通用媒体接口时钟控制寄存器，配置 GPMI 外设时钟分频与门控。 */
    namespace GPMI {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040080, 0x80040084, 0x80040088, 0x8004008C, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, std::uint32_t>; /**< GPMI 时钟整数分频值，决定 GPMI 外设时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< GPMI 时钟分数分频使能，置位后启用 GPMI 分数分频模式。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< GPMI 时钟分频忙标志，为 1 表示分频器正在更新。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< GPMI 时钟门控，置位后关闭 GPMI 外设时钟。 */
    } // namespace GPMI

    /** @brief SPDIF 数字音频接口时钟控制寄存器，仅含时钟门控控制。 */
    namespace SPDIF {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040090, 0x80040094, 0x80040098, 0x8004009C, LowLevel::Access::ReadWrite>;
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SPDIF 时钟门控，置位后关闭 SPDIF 模块时钟。 */
    } // namespace SPDIF

    /** @brief EMI 外部存储器接口时钟控制寄存器，配置 EMI 时钟分频与同步模式。 */
    namespace EMI {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800400A0, 0x800400A4, 0x800400A8, 0x800400AC, LowLevel::Access::ReadWrite>;
        using DIV_EMI = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 6, std::uint32_t>; /**< EMI 时钟整数分频值，决定 EMI 相对于参考源的时钟频率。 */
        using DIV_XTAL = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< EMI 晶振参考时钟整数分频值，用于 XTAL 旁路路径的分频。 */
        using DCC_RESYNC_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< DCC 重同步使能，置位后启用 EMI 动态时钟校准重同步功能。 */
        using BUSY_DCC_RESYNC = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< DCC 重同步忙标志，为 1 表示 DCC 重同步操作正在进行。 */
        using BUSY_SYNC_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< 同步模式忙标志，为 1 表示 EMI 同步模式切换正在进行。 */
        using BUSY_REF_CPU = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< CPU 参考时钟忙标志，为 1 表示 EMI 的 CPU 参考分频器正在更新。 */
        using BUSY_REF_EMI = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< EMI 参考时钟忙标志，为 1 表示 EMI 参考分频器正在更新。 */
        using BUSY_REF_XTAL = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 晶振参考时钟忙标志，为 1 表示 EMI 的 XTAL 参考分频器正在更新。 */
        using SYNC_MODE_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< EMI 同步模式使能，置位后启用 EMI 同步时钟模式。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< EMI 时钟门控，置位后关闭 EMI 模块时钟。 */
    } // namespace EMI

    /** @brief 红外接口时钟控制寄存器，配置 IR 与 IROV 时钟分频及门控。 */
    namespace IR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800400B0, 0x800400B4, 0x800400B8, 0x800400BC, LowLevel::Access::ReadWrite>;
        using IR_DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, std::uint32_t>; /**< IR 红外时钟整数分频值，决定红外接口时钟频率。 */
        using IROV_DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 9, std::uint32_t>; /**< IROV 红外过采样时钟整数分频值，决定红外过采样时钟频率。 */
        using IROV_BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< IROV 时钟分频忙标志，为 1 表示 IROV 分频器正在更新。 */
        using IR_BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< IR 时钟分频忙标志，为 1 表示 IR 分频器正在更新。 */
        using AUTO_DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< IR 自动分频使能，置位后启用 IR 时钟自动分频模式。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< IR 时钟门控，置位后关闭红外接口时钟。 */
    } // namespace IR

    /** @brief SAIF 音频接口时钟控制寄存器，配置 SAIF 时钟分频与门控。 */
    namespace SAIF {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800400C0, 0x800400C4, 0x800400C8, 0x800400CC, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< SAIF 时钟整数分频值，决定 SAIF 音频接口时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< SAIF 时钟分数分频使能，置位后启用 SAIF 分数分频模式。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< SAIF 时钟分频忙标志，为 1 表示分频器正在更新。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SAIF 时钟门控，置位后关闭 SAIF 音频接口时钟。 */
    } // namespace SAIF

    /** @brief TV 编码时钟控制寄存器（i.MX23 残留），控制 TV 模块时钟门控。注：该物理地址当前映射为 FRAC（分数时钟控制寄存器），TV 为遗留兼容名称。 */
    namespace TV {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800400D0, LowLevel::Access::ReadWrite>;
        using CLK_TV_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< TV 编码时钟门控，置位后关闭 TV 编码模块时钟。 */
        using CLK_TV108M_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< TV 108MHz 时钟门控，置位后关闭 TV 编码 108MHz 时钟。 */
    } // namespace TV

    /** @brief 分数时钟控制寄存器，配置 CPU/PIX/IO 分数分频器参数与门控。 */
    namespace FRAC {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800400D0, 0x800400D4, 0x800400D8, 0x800400DC, LowLevel::Access::ReadWrite>;
        using CPUFRAC = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 6, std::uint32_t>; /**< CPU 分数分频值，决定 CPU 分数分频器的分频比。 */
        using CPU_STABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< CPU 分数分频稳定标志，为 1 表示 CPUFRAC 分频已稳定。 */
        using CLKGATECPU = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< CPU 分数时钟门控，置位后关闭 CPU 分数时钟输出。 */
        using PIXFRAC = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 6, std::uint32_t>; /**< PIX 分数分频值，决定 PIX 分数分频器的分频比。 */
        using PIX_STABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< PIX 分数分频稳定标志，为 1 表示 PIXFRAC 分频已稳定。 */
        using CLKGATEPIX = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< PIX 分数时钟门控，置位后关闭 PIX 分数时钟输出。 */
        using IOFRAC = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 6, std::uint32_t>; /**< IO 分数分频值，决定 IO 分数分频器的分频比。 */
        using IO_STABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< IO 分数分频稳定标志，为 1 表示 IOFRAC 分频已稳定。 */
        using CLKGATEIO = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< IO 分数时钟门控，置位后关闭 IO 分数时钟输出。 */
    } // namespace FRAC

    /** @brief ETM 嵌入式跟踪宏单元时钟控制寄存器（i.MX23 残留），配置 ETM 时钟分频与门控。注：该物理地址当前映射为 CLKSEQ（时钟频率序列控制寄存器），ETM 为遗留兼容名称。 */
    namespace ETM {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800400E0, LowLevel::Access::ReadWrite>;
        using DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 6, std::uint32_t>; /**< ETM 时钟整数分频值，决定 ETM 跟踪模块时钟频率。 */
        using DIV_FRAC_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< ETM 时钟分数分频使能，置位后启用 ETM 分数分频模式。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< ETM 时钟分频忙标志，为 1 表示分频器正在更新。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< ETM 时钟门控，置位后关闭 ETM 跟踪模块时钟。 */
    } // namespace ETM

    /** @brief 时钟频率序列控制寄存器，选择各模块时钟源是否旁路至 24MHz 晶振。 */
    namespace CLKSEQ {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800400E0, 0x800400E4, 0x800400E8, 0x800400EC, LowLevel::Access::ReadWrite>;
        using BYPASS_SAIF = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< SAIF 时钟旁路选择，0=使用 PLL/分数时钟源，1=旁路至 24MHz 晶振。 */
        using BYPASS_PIX = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< PIX 时钟旁路选择，0=使用 PLL/分数时钟源，1=旁路至 24MHz 晶振。 */
        using BYPASS_IR = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< IR 时钟旁路选择，0=使用 PLL/分数时钟源，1=旁路至 24MHz 晶振。 */
        using BYPASS_GPMI = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< GPMI 时钟旁路选择，0=使用 PLL/分数时钟源，1=旁路至 24MHz 晶振。 */
        using BYPASS_SSP = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< SSP 时钟旁路选择，0=使用 PLL/分数时钟源，1=旁路至 24MHz 晶振。 */
        using BYPASS_CPU = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< CPU 时钟旁路选择，0=使用 PLL/分数时钟源，1=旁路至 24MHz 晶振。 */
    } // namespace CLKSEQ

    /** @brief 系统软件复位寄存器，控制芯片级与数字域软复位。 */
    namespace RESET {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800400F0, 0x800400F4, 0x800400F8, 0x800400FC, LowLevel::Access::ReadWrite>;
        using DIG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 数字域软复位，置位后复位数字逻辑域。 */
        using CHIP = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 芯片级软复位，置位后触发整芯片软复位。 */
    } // namespace RESET

    /** @brief 分数时钟控制寄存器 1，控制视频分数分频器稳定与门控。 */
    namespace FRAC1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80040100, 0x80040104, 0x80040108, 0x8004010C, LowLevel::Access::ReadWrite>;
        using VID_STABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< VID 视频分数分频稳定标志，为 1 表示视频分数分频已稳定。 */
        using CLKGATEVID = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< VID 视频分数时钟门控，置位后关闭视频分数时钟输出。 */
    } // namespace FRAC1

    /** @brief 时钟控制状态寄存器，反映时钟单元运行状态。 */
    namespace STATUS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80040130, LowLevel::Access::ReadOnly>;
        using CPU_LIMIT = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< CPU 时钟限制状态，指示当前 CPU 频率是否受到限制。 */
    } // namespace STATUS

    /** @brief 时钟控制单元版本寄存器，反映 IP 核版本信息。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80040140, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< IP 核步进版本号。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< IP 核次版本号。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< IP 核主版本号。 */
    } // namespace VERSION

} // namespace Hardware::Registers::CLKCTRL

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_CLKCTRL
