#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_DIGCTL
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_DIGCTL

/**
 * @file DIGCTL.hpp
 * @brief DIGCTL 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 DIGCTL 外设（数字控制/杂项）寄存器与位域中文描述。覆盖 slice 中全部寄存器与位域，名称逐字一致。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::DIGCTL {

    /** @brief DIGCTL 控制寄存器，包含熵锁存、JTAG 防护、USB/SY 时钟门控、调试禁用、地址陷阱、串行 JTAG、SAIF/UART 环回、BIST 启动与时钟使能、测试模式、24MHz 晶振门控等控制位。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C000, 0x8001C004, 0x8001C008, 0x8001C00C, LowLevel::Access::ReadWrite>;
        using LATCH_ENTROPY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 置位后锁存当前 ENTROPY 寄存器值到 ENTROPY_LATCHED 寄存器。 */
        /** @brief JTAG_SHIELD 的取值。 */
        enum class JTAG_SHIELD_Values : std::uint32_t {
            NORMAL = 0x0,
            SHIELDS_UP = 0x1,
        };
        using JTAG_SHIELD = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, JTAG_SHIELD_Values>; /**< JTAG 防护使能：NORMAL=正常模式，SHIELDS_UP=屏蔽模式（禁止外部 JTAG 访问）。 */
        /** @brief USB_CLKGATE 的取值。 */
        enum class USB_CLKGATE_Values : std::uint32_t {
            RUN = 0x0,
            NO_CLKS = 0x1,
        };
        using USB_CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, USB_CLKGATE_Values>; /**< USB 控制器时钟门控：RUN=时钟运行，NO_CLKS=关闭时钟以节省功耗。 */
        using DEBUG_DISABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位后禁用片上调试功能。 */
        using TRAP_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 使能地址陷阱功能，当访问落在陷阱范围内时触发异常。 */
        using TRAP_IN_RANGE = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位表示陷阱范围有效（在 LOW/HIGH 地址之间），清零表示仅匹配单一地址。 */
        /** @brief USE_SERIAL_JTAG 的取值。 */
        enum class USE_SERIAL_JTAG_Values : std::uint32_t {
            OLD_JTAG = 0x0,
            SERIAL_JTAG = 0x1,
        };
        using USE_SERIAL_JTAG = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, USE_SERIAL_JTAG_Values>; /**< JTAG 接口选择：OLD_JTAG=传统 JTAG 接口，SERIAL_JTAG=串行 JTAG 接口。 */
        using SY_CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< SY 模块时钟门控控制位。 PDF第7章标记bit 7为保留。 */
        using SY_SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< SY 模块软复位控制位。 PDF第7章标记bit 8为保留。 */
        using SY_ENDIAN = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< SY 模块字节序选择控制位。 PDF第7章标记bit 9为保留。 */
        using SAIF_ALT_BITCLK_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< SAIF 备用位时钟选择控制位。 */
        /** @brief SAIF_CLKMST_SEL 的取值。 */
        enum class SAIF_CLKMST_SEL_Values : std::uint32_t {
            SAIF1_MST = 0x0,
            SAIF2_MST = 0x1,
        };
        using SAIF_CLKMST_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, SAIF_CLKMST_SEL_Values>; /**< SAIF 主时钟源选择：SAIF1_MST=SAIF1 作主控，SAIF2_MST=SAIF2 作主控。 */
        /** @brief SAIF_CLKMUX_SEL 的取值。 */
        enum class SAIF_CLKMUX_SEL_Values : std::uint32_t {
            MBL_CLK_OUT = 0x0,
            BL_CLK_OUT = 0x1,
            M_CLK_OUT_BL_CLK_IN = 0x2,
            BL_CLK_IN = 0x3,
        };
        using SAIF_CLKMUX_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 2, SAIF_CLKMUX_SEL_Values>; /**< SAIF 时钟多路选择：MBL_CLK_OUT/BL_CLK_OUT/M_CLK_OUT_BL_CLK_IN/BL_CLK_IN。 */
        /** @brief SAIF_LOOPBACK 的取值。 */
        enum class SAIF_LOOPBACK_Values : std::uint32_t {
            NORMAL = 0x0,
            LOOPIT = 0x1,
        };
        using SAIF_LOOPBACK = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, SAIF_LOOPBACK_Values>; /**< SAIF 环回模式：NORMAL=正常传输，LOOPIT=内部环回测试。 */
        /** @brief UART_LOOPBACK 的取值。 */
        enum class UART_LOOPBACK_Values : std::uint32_t {
            NORMAL = 0x0,
            LOOPIT = 0x1,
        };
        using UART_LOOPBACK = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, UART_LOOPBACK_Values>; /**< UART 环回模式：NORMAL=正常传输，LOOPIT=内部环回测试。 */
        using ARM_BIST_START = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 置位启动 ARM 内核 BIST（内置自测试）。 */
        using DIGITAL_TESTMODE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< 数字测试模式使能控制位。 */
        using ANALOG_TESTMODE = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< 模拟测试模式使能控制位。 */
        using USB_TESTMODE = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< USB 测试模式使能控制位。 */
        using ARM_BIST_CLKEN = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< ARM BIST 测试时钟使能控制位。 */
        using DCP_BIST_START = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< 置位启动 DCP（显示协处理器）BIST。 */
        using DCP_BIST_CLKEN = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< DCP BIST 测试时钟使能控制位。 */
        using LCD_BIST_START = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 置位启动 LCD 控制器 BIST。 PDF第7章标记bit 24为保留。 */
        using LCD_BIST_CLKEN = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< LCD BIST 测试时钟使能控制位。 */
        using CACHE_BIST_TMODE = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Cache BIST 测试模式选择控制位。 */
        using TRAP_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 地址陷阱中断状态/触发位。 */
        using XTAL24M_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 24MHz 晶振时钟门控控制位，置位关闭 XTAL24M 输出。 */
    } // namespace CTRL

    /** @brief DIGCTL 状态寄存器，反映芯片封装类型、JTAG 占用状态、LCD/DCP BIST 结果及 USB 设备/主机/OTG/HS 存在性标志。 */
    namespace STATUS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8001C010, LowLevel::Access::ReadOnly>;
        using WRITTEN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 芯片是否已被写入过（如熔丝/ROM 配置已写入）标志位。 */
        using PACKAGE_TYPE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 3, std::uint32_t>; /**< 芯片封装类型标识编码。 */
        using JTAG_IN_USE = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< JTAG 接口当前正在被使用标志位。 */
        using LCD_BIST_DONE = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< LCD BIST 测试完成标志位。 */
        using LCD_BIST_PASS = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< LCD BIST 测试通过标志位。 */
        using LCD_BIST_FAIL = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< LCD BIST 测试失败标志位。 */
        using DCP_BIST_DONE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< DCP BIST 测试完成标志位。 */
        using DCP_BIST_PASS = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< DCP BIST 测试通过标志位。 */
        using DCP_BIST_FAIL = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< DCP BIST 测试失败标志位。 */
        using USB_DEVICE_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< USB Device 功能存在标志位。 */
        using USB_HOST_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< USB Host 功能存在标志位。 */
        using USB_OTG_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< USB OTG 功能存在标志位。 */
        using USB_HS_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< USB High-Speed 功能存在标志位。 */
    } // namespace STATUS

    /** @brief HCLK 自由运行计数器，提供 32 位 AHB 总线时钟周期计数。 */
    namespace HCLKCOUNT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C020, 0x8001C024, 0x8001C028, 0x8001C02C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< HCLK 自由运行计数值，每拍递增，自然回绕。 */
    } // namespace HCLKCOUNT

    /** @brief 片内 RAM 控制寄存器，包含 RAM 修复使能与速度档位选择。 */
    namespace RAMCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C030, 0x8001C034, 0x8001C038, 0x8001C03C, LowLevel::Access::ReadWrite>;
        using RAM_REPAIR_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 片内 RAM 修复功能使能控制位。 */
        using SPEED_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< 片内 RAM 速度档位选择，用于调整时序裕量。 */
    } // namespace RAMCTRL

    /** @brief 片内 RAM 修复地址寄存器，指定需要修复的 RAM 地址。 */
    namespace RAMREPAIR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C040, 0x8001C044, 0x8001C048, 0x8001C04C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< RAM 修复目标地址。 */
    } // namespace RAMREPAIR

    /** @brief 片内 ROM 控制寄存器，用于调整 ROM 读时序。 */
    namespace ROMCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C050, 0x8001C054, 0x8001C058, 0x8001C05C, LowLevel::Access::ReadWrite>;
        using RD_MARGIN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< ROM 读操作裕量（延迟/边距）设置值。 */
    } // namespace ROMCTRL

    /** @brief 软件一次性写寄存器，写入后不可再次修改（仅能在复位后重写）。 */
    namespace WRITEONCE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C060, 0x8001C064, 0x8001C068, 0x8001C06C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位一次性写入数据位域。 */
    } // namespace WRITEONCE

    /** @brief 熵寄存器，提供来自物理噪声源的随机数值。 */
    namespace ENTROPY {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C090, 0x8001C094, 0x8001C098, 0x8001C09C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 实时熵值（随机数），由片上物理噪声源生成。 */
    } // namespace ENTROPY

    /** @brief 熵锁存寄存器，保存由 LATCH_ENTROPY 触发锁存时的熵值。 */
    namespace ENTROPY_LATCHED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C0A0, 0x8001C0A4, 0x8001C0A8, 0x8001C0AC, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 锁存后的熵值快照，供软件读取固定随机数。 */
    } // namespace ENTROPY_LATCHED

    /** @brief 串行 JTAG 调试寄存器，提供 SJTAG 接口的调试访问、状态监控与手动控制。 */
    namespace SJTAGDBG {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C0B0, 0x8001C0B4, 0x8001C0B8, 0x8001C0BC, LowLevel::Access::ReadWrite>;
        using SJTAG_DEBUG_OE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< SJTAG 调试数据输出使能控制位。 */
        using SJTAG_DEBUG_DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< SJTAG 调试数据输出值。 */
        using SJTAG_PIN_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< SJTAG 引脚当前状态。 */
        using ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< SJTAG 接口当前激活状态标志。 */
        using DELAYED_ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, std::uint32_t>; /**< SJTAG 激活延迟计数/延迟值。 */
        using SJTAG_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< SJTAG 模式选择控制位。 */
        using SJTAG_TDI = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< SJTAG TDI（测试数据输入）信号值。 */
        using SJTAG_TDO = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< SJTAG TDO（测试数据输出）信号值。 */
        using SJTAG_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 11, std::uint32_t>; /**< SJTAG 状态机当前状态编码。 */
    } // namespace SJTAGDBG

    /** @brief 微秒计数器寄存器，用于软件实现微秒级延时与计时。 */
    namespace MICROSECONDS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C0C0, 0x8001C0C4, 0x8001C0C8, 0x8001C0CC, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 微秒计数值，软件可读写，用于实现 us 级延时。 */
    } // namespace MICROSECONDS

    /** @brief 数字控制调试读测试寄存器，读取值为 DBG 寄存器值的按位取反。 */
    namespace DBGRD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C0D0, 0x8001C0D4, 0x8001C0D8, 0x8001C0DC, LowLevel::Access::ReadWrite>;
        using COMPLEMENT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< DBG 寄存器值的按位补码（取反），用于总线读测试验证。 */
    } // namespace DBGRD

    /** @brief 数字控制调试寄存器，通用 32 位调试端口。 */
    namespace DBG {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C0E0, 0x8001C0E4, 0x8001C0E8, 0x8001C0EC, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位调试数据值，只读，返回当前调试端口状态。 */
    } // namespace DBG

    /** @brief SRAM BIST 控制与状态寄存器，用于启动和监控片内 SRAM 自测试。 */
    namespace OCRAM_BIST_CSR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C0F0, 0x8001C0F4, 0x8001C0F8, 0x8001C0FC, LowLevel::Access::ReadWrite>;
        using START = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 置位启动 SRAM BIST 测试。 */
        using DONE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< SRAM BIST 测试完成标志位。 */
        using PASS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< SRAM BIST 测试通过标志位。 */
        using FAIL = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< SRAM BIST 测试失败标志位。 */
        using BIST_CLKEN = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< SRAM BIST 测试时钟使能控制位。 */
        using BIST_DATA_CHANGE = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< SRAM BIST 数据变化模式控制位。 */
        using BIST_DEBUG_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< SRAM BIST 调试模式使能控制位。 */
    } // namespace OCRAM_BIST_CSR

    /** @brief SRAM 状态寄存器 0，记录 BIST 失败时端口 0/数据 0 的故障数据。 */
    namespace OCRAM_STATUS0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C110, 0x8001C114, 0x8001C118, 0x8001C11C, LowLevel::Access::ReadWrite>;
        using FAILDATA00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 0、数据 0 的故障数据值。 */
    } // namespace OCRAM_STATUS0

    /** @brief SRAM 状态寄存器 1，记录 BIST 失败时端口 0/数据 1 的故障数据。 */
    namespace OCRAM_STATUS1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C120, 0x8001C124, 0x8001C128, 0x8001C12C, LowLevel::Access::ReadWrite>;
        using FAILDATA01 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 0、数据 1 的故障数据值。 */
    } // namespace OCRAM_STATUS1

    /** @brief SRAM 状态寄存器 2，记录 BIST 失败时端口 1/数据 0 的故障数据。 */
    namespace OCRAM_STATUS2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C130, 0x8001C134, 0x8001C138, 0x8001C13C, LowLevel::Access::ReadWrite>;
        using FAILDATA10 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 1、数据 0 的故障数据值。 */
    } // namespace OCRAM_STATUS2

    /** @brief SRAM 状态寄存器 3，记录 BIST 失败时端口 1/数据 1 的故障数据。 */
    namespace OCRAM_STATUS3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C140, 0x8001C144, 0x8001C148, 0x8001C14C, LowLevel::Access::ReadWrite>;
        using FAILDATA11 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 1、数据 1 的故障数据值。 */
    } // namespace OCRAM_STATUS3

    /** @brief SRAM 状态寄存器 4，记录 BIST 失败时端口 2/数据 0 的故障数据。 */
    namespace OCRAM_STATUS4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C150, 0x8001C154, 0x8001C158, 0x8001C15C, LowLevel::Access::ReadWrite>;
        using FAILDATA20 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 2、数据 0 的故障数据值。 */
    } // namespace OCRAM_STATUS4

    /** @brief SRAM 状态寄存器 5，记录 BIST 失败时端口 2/数据 1 的故障数据。 */
    namespace OCRAM_STATUS5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C160, 0x8001C164, 0x8001C168, 0x8001C16C, LowLevel::Access::ReadWrite>;
        using FAILDATA21 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 2、数据 1 的故障数据值。 */
    } // namespace OCRAM_STATUS5

    /** @brief SRAM 状态寄存器 6，记录 BIST 失败时端口 3/数据 0 的故障数据。 */
    namespace OCRAM_STATUS6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C170, 0x8001C174, 0x8001C178, 0x8001C17C, LowLevel::Access::ReadWrite>;
        using FAILDATA30 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 3、数据 0 的故障数据值。 */
    } // namespace OCRAM_STATUS6

    /** @brief SRAM 状态寄存器 7，记录 BIST 失败时端口 3/数据 1 的故障数据。 */
    namespace OCRAM_STATUS7 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C180, 0x8001C184, 0x8001C188, 0x8001C18C, LowLevel::Access::ReadWrite>;
        using FAILDATA31 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< BIST 失败时端口 3、数据 1 的故障数据值。 */
    } // namespace OCRAM_STATUS7

    /** @brief SRAM 状态寄存器 8，记录 BIST 失败时端口 0 的故障地址。 */
    namespace OCRAM_STATUS8 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C190, 0x8001C194, 0x8001C198, 0x8001C19C, LowLevel::Access::ReadWrite>;
        using FAILADDR00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< BIST 失败时端口 0、数据 0 的故障地址。 */
        using FAILADDR01 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 13, std::uint32_t>; /**< BIST 失败时端口 0、数据 1 的故障地址。 */
    } // namespace OCRAM_STATUS8

    /** @brief SRAM 状态寄存器 9，记录 BIST 失败时端口 1 的故障地址。 */
    namespace OCRAM_STATUS9 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C1A0, 0x8001C1A4, 0x8001C1A8, 0x8001C1AC, LowLevel::Access::ReadWrite>;
        using FAILADDR10 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< BIST 失败时端口 1、数据 0 的故障地址。 */
        using FAILADDR11 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 13, std::uint32_t>; /**< BIST 失败时端口 1、数据 1 的故障地址。 */
    } // namespace OCRAM_STATUS9

    /** @brief SRAM 状态寄存器 10，记录 BIST 失败时端口 2 的故障地址。 */
    namespace OCRAM_STATUS10 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C1B0, 0x8001C1B4, 0x8001C1B8, 0x8001C1BC, LowLevel::Access::ReadWrite>;
        using FAILADDR20 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< BIST 失败时端口 2、数据 0 的故障地址。 */
        using FAILADDR21 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 13, std::uint32_t>; /**< BIST 失败时端口 2、数据 1 的故障地址。 */
    } // namespace OCRAM_STATUS10

    /** @brief SRAM 状态寄存器 11，记录 BIST 失败时端口 3 的故障地址。 */
    namespace OCRAM_STATUS11 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C1C0, 0x8001C1C4, 0x8001C1C8, 0x8001C1CC, LowLevel::Access::ReadWrite>;
        using FAILADDR30 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< BIST 失败时端口 3、数据 0 的故障地址。 */
        using FAILADDR31 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 13, std::uint32_t>; /**< BIST 失败时端口 3、数据 1 的故障地址。 */
    } // namespace OCRAM_STATUS11

    /** @brief SRAM 状态寄存器 12，记录 BIST 失败时端口 0 和端口 1 的故障状态。 */
    namespace OCRAM_STATUS12 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C1D0, 0x8001C1D4, 0x8001C1D8, 0x8001C1DC, LowLevel::Access::ReadWrite>;
        using FAILSTATE00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< BIST 失败时端口 0、数据 0 的故障状态编码。 */
        using FAILSTATE01 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< BIST 失败时端口 0、数据 1 的故障状态编码。 */
        using FAILSTATE10 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< BIST 失败时端口 1、数据 0 的故障状态编码。 */
        using FAILSTATE11 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< BIST 失败时端口 1、数据 1 的故障状态编码。 */
    } // namespace OCRAM_STATUS12

    /** @brief SRAM 状态寄存器 13，记录 BIST 失败时端口 2 和端口 3 的故障状态。 */
    namespace OCRAM_STATUS13 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C1E0, 0x8001C1E4, 0x8001C1E8, 0x8001C1EC, LowLevel::Access::ReadWrite>;
        using FAILSTATE20 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< BIST 失败时端口 2、数据 0 的故障状态编码。 */
        using FAILSTATE21 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< BIST 失败时端口 2、数据 1 的故障状态编码。 */
        using FAILSTATE30 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< BIST 失败时端口 3、数据 0 的故障状态编码。 */
        using FAILSTATE31 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< BIST 失败时端口 3、数据 1 的故障状态编码。 */
    } // namespace OCRAM_STATUS13

    /** @brief 数字控制 scratch 寄存器 0，供软件临时存储 32 位数据。 */
    namespace SCRATCH0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C290, 0x8001C294, 0x8001C298, 0x8001C29C, LowLevel::Access::ReadWrite>;
        using PTR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位通用暂存数据值。 */
    } // namespace SCRATCH0

    /** @brief 数字控制 scratch 寄存器 1，供软件临时存储 32 位数据。 */
    namespace SCRATCH1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C2A0, 0x8001C2A4, 0x8001C2A8, 0x8001C2AC, LowLevel::Access::ReadWrite>;
        using PTR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位通用暂存数据值。 */
    } // namespace SCRATCH1

    /** @brief ARM Cache 寄存器，反映 ARM926EJ-S 各 cache 子阵列的大小配置状态。 */
    namespace ARMCACHE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C2B0, 0x8001C2B4, 0x8001C2B8, 0x8001C2BC, LowLevel::Access::ReadWrite>;
        using ITAG_SS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 指令 Tag 阵列大小状态（ITAG sub-array size status）。 */
        using DTAG_SS = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< 数据 Tag 阵列大小状态（DTAG sub-array size status）。 */
        using CACHE_SS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Cache 数据阵列大小状态（Cache sub-array size status）。 */
        using DRTY_SS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Dirty 位阵列大小状态（Dirty sub-array size status）。 */
        using VALID_SS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Valid 位阵列大小状态（Valid sub-array size status）。 */
    } // namespace ARMCACHE

    /** @brief 调试陷阱范围低地址寄存器，设定地址陷阱监控范围的下限。 */
    namespace DEBUG_TRAP_ADDR_LOW {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C2C0, 0x8001C2C4, 0x8001C2C8, 0x8001C2CC, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 陷阱范围低地址边界值。 */
    } // namespace DEBUG_TRAP_ADDR_LOW

    /** @brief 调试陷阱范围高地址寄存器，设定地址陷阱监控范围的上限。 */
    namespace DEBUG_TRAP_ADDR_HIGH {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C2D0, 0x8001C2D4, 0x8001C2D8, 0x8001C2DC, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 陷阱范围高地址边界值。 */
    } // namespace DEBUG_TRAP_ADDR_HIGH

    /** @brief SigmaTel 版权标识寄存器，读取返回固定版权标识码。 */
    namespace SGTL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C300, 0x8001C304, 0x8001C308, 0x8001C30C, LowLevel::Access::ReadWrite>;
        using COPYRIGHT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SigmaTel 版权标识值。 */
    } // namespace SGTL

    /** @brief 芯片版本与产品代码寄存器，用于识别芯片型号与硅片版本。 */
    namespace CHIPID {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C310, 0x8001C314, 0x8001C318, 0x8001C31C, LowLevel::Access::ReadWrite>;
        using REVISION = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 芯片硅片版本号（Revision）。 */
        using PRODUCT_CODE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 芯片产品代码，用于区分不同型号/变体。 */
    } // namespace CHIPID

    /** @brief AHB 统计控制寄存器，选择各 AHB 层要监控的主设备。 */
    namespace AHB_STATS_SELECT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C330, 0x8001C334, 0x8001C338, 0x8001C33C, LowLevel::Access::ReadWrite>;
        /** @brief L0_MASTER_SELECT 的取值。 */
        enum class L0_MASTER_SELECT_Values : std::uint32_t {
            ECC8 = 0x1,
            CRYPTO = 0x2,
        };
        using L0_MASTER_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, L0_MASTER_SELECT_Values>; /**< AHB 层 0 主设备选择位掩码：ECC8=0x1，CRYPTO=0x2。 */
        /** @brief L1_MASTER_SELECT 的取值。 */
        enum class L1_MASTER_SELECT_Values : std::uint32_t {
            ARM_I = 0x1,
        };
        using L1_MASTER_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, L1_MASTER_SELECT_Values>; /**< AHB 层 1 主设备选择位掩码：ARM_I=0x1。 */
        /** @brief L2_MASTER_SELECT 的取值。 */
        enum class L2_MASTER_SELECT_Values : std::uint32_t {
            ARM_D = 0x1,
        };
        using L2_MASTER_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, L2_MASTER_SELECT_Values>; /**< AHB 层 2 主设备选择位掩码：ARM_D=0x1。 */
        /** @brief L3_MASTER_SELECT 的取值。 */
        enum class L3_MASTER_SELECT_Values : std::uint32_t {
            APBH = 0x1,
            APBX = 0x2,
            USB = 0x4,
        };
        using L3_MASTER_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, L3_MASTER_SELECT_Values>; /**< AHB 层 3 主设备选择位掩码：APBH=0x1，APBX=0x2，USB=0x4。 */
    } // namespace AHB_STATS_SELECT

    /** @brief AHB 层 0 活跃周期计数器，记录选定主设备的总线传输周期数。 */
    namespace L0_AHB_ACTIVE_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C340, 0x8001C344, 0x8001C348, 0x8001C34C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 0 活跃周期计数值。 */
    } // namespace L0_AHB_ACTIVE_CYCLES

    /** @brief AHB 层 0 数据停滞周期计数器，记录总线因等待而停滞的周期数。 */
    namespace L0_AHB_DATA_STALLED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C350, 0x8001C354, 0x8001C358, 0x8001C35C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 0 数据停滞周期计数值。 */
    } // namespace L0_AHB_DATA_STALLED

    /** @brief AHB 层 0 有效数据周期计数器，记录总线上有效数据传输的周期数。 */
    namespace L0_AHB_DATA_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C360, 0x8001C364, 0x8001C368, 0x8001C36C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 0 有效数据周期计数值。 */
    } // namespace L0_AHB_DATA_CYCLES

    /** @brief AHB 层 1 活跃周期计数器，记录选定主设备的总线传输周期数。 */
    namespace L1_AHB_ACTIVE_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C370, 0x8001C374, 0x8001C378, 0x8001C37C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 1 活跃周期计数值。 */
    } // namespace L1_AHB_ACTIVE_CYCLES

    /** @brief AHB 层 1 数据停滞周期计数器，记录总线因等待而停滞的周期数。 */
    namespace L1_AHB_DATA_STALLED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C380, 0x8001C384, 0x8001C388, 0x8001C38C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 1 数据停滞周期计数值。 */
    } // namespace L1_AHB_DATA_STALLED

    /** @brief AHB 层 1 有效数据周期计数器，记录总线上有效数据传输的周期数。 */
    namespace L1_AHB_DATA_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C390, 0x8001C394, 0x8001C398, 0x8001C39C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 1 有效数据周期计数值。 */
    } // namespace L1_AHB_DATA_CYCLES

    /** @brief AHB 层 2 活跃周期计数器，记录选定主设备的总线传输周期数。 */
    namespace L2_AHB_ACTIVE_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C3A0, 0x8001C3A4, 0x8001C3A8, 0x8001C3AC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 2 活跃周期计数值。 */
    } // namespace L2_AHB_ACTIVE_CYCLES

    /** @brief AHB 层 2 数据停滞周期计数器，记录总线因等待而停滞的周期数。 */
    namespace L2_AHB_DATA_STALLED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C3B0, 0x8001C3B4, 0x8001C3B8, 0x8001C3BC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 2 数据停滞周期计数值。 */
    } // namespace L2_AHB_DATA_STALLED

    /** @brief AHB 层 2 有效数据周期计数器，记录总线上有效数据传输的周期数。 */
    namespace L2_AHB_DATA_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C3C0, 0x8001C3C4, 0x8001C3C8, 0x8001C3CC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 2 有效数据周期计数值。 */
    } // namespace L2_AHB_DATA_CYCLES

    /** @brief AHB 层 3 活跃周期计数器，记录选定主设备的总线传输周期数。 */
    namespace L3_AHB_ACTIVE_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C3D0, 0x8001C3D4, 0x8001C3D8, 0x8001C3DC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 3 活跃周期计数值。 */
    } // namespace L3_AHB_ACTIVE_CYCLES

    /** @brief AHB 层 3 数据停滞周期计数器，记录总线因等待而停滞的周期数。 */
    namespace L3_AHB_DATA_STALLED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C3E0, 0x8001C3E4, 0x8001C3E8, 0x8001C3EC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 3 数据停滞周期计数值。 */
    } // namespace L3_AHB_DATA_STALLED

    /** @brief AHB 层 3 有效数据周期计数器，记录总线上有效数据传输的周期数。 */
    namespace L3_AHB_DATA_CYCLES {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C3F0, 0x8001C3F4, 0x8001C3F8, 0x8001C3FC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< AHB 层 3 有效数据周期计数值。 */
    } // namespace L3_AHB_DATA_CYCLES

    /** @brief EMI CLK/CLKN 延迟调整寄存器，用于微调外部存储器接口时钟相位。 */
    namespace EMICLK_DELAY {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8001C500, 0x8001C504, 0x8001C508, 0x8001C50C, LowLevel::Access::ReadWrite>;
        using NUM_TAPS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< EMI 时钟延迟抽头数，控制 CLK/CLKN 输出延迟量。 */
    } // namespace EMICLK_DELAY

} // namespace Hardware::Registers::DIGCTL

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_DIGCTL
