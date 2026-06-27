#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_USBCTRL
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_USBCTRL

/**
 * @file USBCTRL.hpp
 * @brief USBCTRL 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * ChipIdea/MXS USB 2.0 OTG 控制器（EHCI 兼容扩展），HP39GII 工作于 Device 模式。包含 EHCI 能力寄存器、USB 命令/状态/中断控制、端点队列管理（QH）、端口状态控制、OTG 状态控制及端点控制寄存器组。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::USBCTRL {

    /** @brief Identification Register */
    namespace ID {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080000, LowLevel::Access::ReadWrite>;
        using ID = LowLevel::Field<Reg, 0, 6, std::uint32_t>; /**< USB 控制器 ID 标识码（只读） */
        using NID = LowLevel::Field<Reg, 8, 6, std::uint32_t>; /**< ID 取反码（只读） */
        using TAG = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< 架构版本标签（只读） */
        using REVISION = LowLevel::Field<Reg, 21, 4, std::uint32_t>; /**< 硅片修订版本号（只读） */
        using VERSION = LowLevel::Field<Reg, 25, 4, std::uint32_t>; /**< USB 控制器版本号（只读） */
        using CIVERSION = LowLevel::Field<Reg, 29, 3, std::uint32_t>; /**< ChipIdea 接口版本号（只读） */
    } // namespace ID

    /** @brief General Hardware Parameters Register */
    namespace HWGENERAL {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080004, LowLevel::Access::ReadWrite>;
        using RT = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 保留测试模式（只读） */
        using CLKC = LowLevel::Field<Reg, 1, 2, std::uint32_t>; /**< 时钟配置（只读） */
        using BWT = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 总线等待时间配置（只读） */
        using PHYW = LowLevel::Field<Reg, 4, 2, std::uint32_t>; /**< PHY 数据宽度（只读） */
        using PHYM = LowLevel::Field<Reg, 6, 3, std::uint32_t>; /**< PHY 模式（只读） */
        using SM = LowLevel::Field<Reg, 9, 2, std::uint32_t>; /**< 串行模式选择（只读） */
    } // namespace HWGENERAL

    /** @brief Host Hardware Parameters Register */
    namespace HWHOST {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080008, LowLevel::Access::ReadWrite>;
        using HC = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Host 模式支持标志（只读） */
        using NPORT = LowLevel::Field<Reg, 1, 3, std::uint32_t>; /**< 端口数量（只读） */
        using TTASY = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< TT 异步调度延迟（只读） */
        using TTPER = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< TT 周期性调度延迟（只读） */
    } // namespace HWHOST

    /** @brief Device Hardware Parameters Register */
    namespace HWDEVICE {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8008000C, LowLevel::Access::ReadWrite>;
        using DC = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Device 模式支持标志（只读） */
        using DEVEP = LowLevel::Field<Reg, 1, 5, std::uint32_t>; /**< 支持的 Device 端点数量（只读） */
    } // namespace HWDEVICE

    /** @brief TX Buffer Hardware Parameters Register */
    namespace HWTXBUF {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080010, LowLevel::Access::ReadWrite>;
        using TXBURST = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< TX 突发传输长度（只读） */
        using TXADD = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< TX 缓冲区总大小（只读） */
        using TXCHANADD = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< TX 每通道缓冲区大小（只读） */
        using TXLCR = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< TX 本地上下文重排使能（只读） */
    } // namespace HWTXBUF

    /** @brief RX Buffer Hardware Parameters Register */
    namespace HWRXBUF {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080014, LowLevel::Access::ReadWrite>;
        using RXBURST = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< RX 突发传输长度（只读） */
        using RXADD = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< RX 缓冲区总大小（只读） */
    } // namespace HWRXBUF

    /** @brief General-Purpose Timer 0 Load (Non-EHCI-Compliant) Register */
    namespace GPTIMER0LD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080080, LowLevel::Access::ReadWrite>;
        using GPTLD = LowLevel::Field<Reg, 0, 24, std::uint32_t>; /**< 通用定时器 0 加载值（24 位递减计数初值） */
    } // namespace GPTIMER0LD

    /** @brief General-Purpose Timer 0 Control (Non-EHCI-Compliant) Register */
    namespace GPTIMER0CTRL {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080084, LowLevel::Access::ReadWrite>;
        using GPTCNT = LowLevel::Field<Reg, 0, 24, std::uint32_t>; /**< 通用定时器 0 当前计数值（24 位，只读） */
        /** @brief GPTMODE 的取值。 */
        enum class GPTMODE_Values : std::uint32_t {
            ONESHOT = 0x0,
            REPEAT = 0x1,
        };
        using GPTMODE = LowLevel::Field<Reg, 24, 1, GPTMODE_Values>; /**< 通用定时器 0 工作模式（0=单次 ONESHOT，1=重复 REPEAT） */
        /** @brief GPTRST 的取值。 */
        enum class GPTRST_Values : std::uint32_t {
            NOACTION = 0x0,
            LOADCOUNTER = 0x1,
        };
        using GPTRST = LowLevel::Field<Reg, 30, 1, GPTRST_Values>; /**< 通用定时器 0 复位（0=无操作，1=加载 GPTLD 到计数器） */
        /** @brief GPTRUN 的取值。 */
        enum class GPTRUN_Values : std::uint32_t {
            STOP = 0x0,
            RUN = 0x1,
        };
        using GPTRUN = LowLevel::Field<Reg, 31, 1, GPTRUN_Values>; /**< 通用定时器 0 运行控制（0=停止 STOP，1=运行 RUN） */
    } // namespace GPTIMER0CTRL

    /** @brief General-Purpose Timer 1 Load (Non-EHCI-Compliant) Register */
    namespace GPTIMER1LD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080088, LowLevel::Access::ReadWrite>;
        using GPTLD = LowLevel::Field<Reg, 0, 24, std::uint32_t>; /**< 通用定时器 1 加载值（24 位递减计数初值） */
    } // namespace GPTIMER1LD

    /** @brief General-Purpose Timer 1 Control (Non-EHCI-Compliant) Register */
    namespace GPTIMER1CTRL {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8008008C, LowLevel::Access::ReadWrite>;
        using GPTCNT = LowLevel::Field<Reg, 0, 24, std::uint32_t>; /**< 通用定时器 1 当前计数值（24 位，只读） */
        /** @brief GPTMODE 的取值。 */
        enum class GPTMODE_Values : std::uint32_t {
            ONESHOT = 0x0,
            REPEAT = 0x1,
        };
        using GPTMODE = LowLevel::Field<Reg, 24, 1, GPTMODE_Values>; /**< 通用定时器 1 工作模式（0=单次 ONESHOT，1=重复 REPEAT） */
        /** @brief GPTRST 的取值。 */
        enum class GPTRST_Values : std::uint32_t {
            NOACTION = 0x0,
            LOADCOUNTER = 0x1,
        };
        using GPTRST = LowLevel::Field<Reg, 30, 1, GPTRST_Values>; /**< 通用定时器 1 复位（0=无操作，1=加载 GPTLD 到计数器） */
        /** @brief GPTRUN 的取值。 */
        enum class GPTRUN_Values : std::uint32_t {
            STOP = 0x0,
            RUN = 0x1,
        };
        using GPTRUN = LowLevel::Field<Reg, 31, 1, GPTRUN_Values>; /**< 通用定时器 1 运行控制（0=停止 STOP，1=运行 RUN） */
    } // namespace GPTIMER1CTRL

    /** @brief System Bus Configuration (Non-EHCI-Compliant) Register */
    namespace SBUSCFG {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80080090, 0x80080094, 0x80080098, 0x8008009C, LowLevel::Access::ReadWrite>;
        /** @brief AHBBRST 的取值。 */
        enum class AHBBRST_Values : std::uint32_t {
            U_INCR = 0x0,
            S_INCR4 = 0x1,
            S_INCR8 = 0x2,
            S_INCR16 = 0x3,
            RESERVED = 0x4,
            U_INCR4 = 0x5,
            U_INCR8 = 0x6,
            U_INCR16 = 0x7,
        };
        using AHBBRST = LowLevel::Field<Reg, 0, 3, AHBBRST_Values>; /**< AHB 总线突发传输模式（INCR/INCR4/INCR8/INCR16 等） */
    } // namespace SBUSCFG

    /** @brief Capability Length and HCI Version (EHCI-Compliant) Register */
    namespace CAPLENGTH {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080100, LowLevel::Access::ReadWrite>;
        using CAPLENGTH = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< 能力寄存器组长度（字节数，只读） */
        using HCIVERSION = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< EHCI HCI 版本号（BCD 编码，只读） */
    } // namespace CAPLENGTH

    /** @brief Host Control Structural Parameters (EHCI-Compliant with Extensions) Register */
    namespace HCSPARAMS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080104, LowLevel::Access::ReadWrite>;
        using N_PORTS = LowLevel::Field<Reg, 0, 4, std::uint32_t>; /**< 物理端口数量（只读） */
        using PPC = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 端口电源控制支持（只读） */
        using N_PCC = LowLevel::Field<Reg, 8, 4, std::uint32_t>; /**< 每 Companion 控制器端口数（只读） */
        using N_CC = LowLevel::Field<Reg, 12, 4, std::uint32_t>; /**< Companion 控制器数量（只读） */
        using PI = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< 端口指示器支持（只读） */
        using N_PTT = LowLevel::Field<Reg, 20, 4, std::uint32_t>; /**< 每 TT 端口数（只读） */
        using N_TT = LowLevel::Field<Reg, 24, 4, std::uint32_t>; /**< Transaction Translator 数量（只读） */
    } // namespace HCSPARAMS

    /** @brief Host Control Capability Parameters (EHCI-Compliant) Register */
    namespace HCCPARAMS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080108, LowLevel::Access::ReadWrite>;
        using ADC = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 64 位地址映射能力（只读） */
        using PFL = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 可编程帧列表标志（只读） */
        using ASP = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 异步调度 Park 能力（只读） */
        using IST = LowLevel::Field<Reg, 4, 4, std::uint32_t>; /**< 等时同步调度阈值（只读） */
        using EECP = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< EHCI 扩展能力指针偏移（只读） */
    } // namespace HCCPARAMS

    /** @brief Device Interface Version Number (Non-EHCI-Compliant) Register */
    namespace DCIVERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080120, LowLevel::Access::ReadOnly>;
        using DCIVERSION = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< Device 接口版本号（BCD 编码，只读） */
    } // namespace DCIVERSION

    /** @brief Device Control Capability Parameters (Non-EHCI-Compliant) Register */
    namespace DCCPARAMS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080124, LowLevel::Access::ReadWrite>;
        using DEN = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< Device 端点数量（只读） */
        using DC = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< Device 模式支持标志（只读） */
        using HC = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Host 模式支持标志（只读） */
    } // namespace DCCPARAMS

    /** @brief USB Command Register */
    namespace USBCMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080140, LowLevel::Access::ReadWrite>;
        using RS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Run/Stop，控制器运行（1）或停止（0）并连接总线 */
        using RST = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 控制器软复位，写 1 复位所有内部状态机 */
        using FS0 = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 帧列表大小位 0（与 FS1/FS2 组合） */
        using FS1 = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 帧列表大小位 1（与 FS0/FS2 组合） */
        using PSE = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 周期性调度使能（Host 模式） */
        using ASE = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 异步调度使能（Host 模式） */
        using IAA = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 异步调度推进门铃（Host 模式） */
        using LR = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 中断仲裁级别控制（Host 模式） */
        using ASP = LowLevel::Field<Reg, 8, 2, std::uint32_t>; /**< 异步调度 Park 模式计数（Host 模式） */
        using ASPE = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< 异步调度 Park 模式使能（Host 模式） */
        using SUTW = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< Setup 包定时写（Device 模式，用于同步 Setup 包处理） */
        using ATDTW = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 添加 dTD 定时写（Device 模式，用于同步 dTD 添加） */
        using FS2 = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 帧列表大小位 2（与 FS0/FS1 组合） */
        /** @brief ITC 的取值。 */
        enum class ITC_Values : std::uint32_t {
            IMM = 0x0,
            _1_MICROFRAME = 0x1,
            _2_MICROFRAME = 0x2,
            _4_MICROFRAME = 0x4,
            _8_MICROFRAME = 0x8,
            _16_MICROFRAME = 0x10,
            _32_MICROFRAME = 0x20,
            _64_MICROFRAME = 0x40,
        };
        using ITC = LowLevel::Field<Reg, 16, 8, ITC_Values>; /**< 中断阈值控制（微帧数：立即/1/2/4/8/16/32/64） */
    } // namespace USBCMD

    /** @brief USB Status Register */
    namespace USBSTS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080144, LowLevel::Access::ReadWrite>;
        using UI = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< USB 中断（传输完成等事件） */
        using UEI = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< USB 错误中断（传输错误） */
        using PCI = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 端口变化中断（Host 模式，端口状态变化） */
        using FRI = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 帧列表滚动中断（Host 模式） */
        using SEI = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 系统错误中断 */
        using AAI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 异步调度推进中断（Host 模式） */
        using URI = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< USB 复位中断（Device 模式，总线复位事件） */
        using SRI = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< SOF 接收中断（Device 模式，收到 Start-of-Frame） */
        using SLI = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 挂起中断（Device 模式，总线挂起事件） */
        using ULPII = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< ULPI 中断 */
        using HCH = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 主机控制器已停止（只读） */
        using RCL = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< 异步调度回收中（只读） */
        using PS = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 周期性调度状态（只读） */
        using AS = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 异步调度状态（只读） */
        using NAKI = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< NAK 中断（Device 模式，端点 NAK 事件） */
        using UAI = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< USB 主机异步中断 */
        using UPI = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< USB 主机周期性中断 */
        using TI0 = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 通用定时器 0 中断 */
        using TI1 = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 通用定时器 1 中断 */
    } // namespace USBSTS

    /** @brief USB Interrupt Enable Register */
    namespace USBINTR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080148, LowLevel::Access::ReadWrite>;
        using UE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< USB 中断使能（对应 UI） */
        using UEE = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< USB 错误中断使能（对应 UEI） */
        using PCE = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 端口变化中断使能（对应 PCI） */
        using FRE = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 帧列表滚动中断使能（对应 FRI） */
        using SEE = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 系统错误中断使能（对应 SEI） */
        using AAE = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 异步调度推进中断使能（对应 AAI） */
        using URE = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< USB 复位中断使能（对应 URI） */
        using SRE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< SOF 接收中断使能（对应 SRI） */
        using SLE = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 挂起中断使能（对应 SLI） */
        using ULPIE = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< ULPI 中断使能（对应 ULPII） */
        using NAKE = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< NAK 中断使能（对应 NAKI） */
        using UAIE = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< USB 主机异步中断使能（对应 UAI） */
        using UPIE = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< USB 主机周期性中断使能（对应 UPI） */
        using TIE0 = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 通用定时器 0 中断使能（对应 TI0） */
        using TIE1 = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 通用定时器 1 中断使能（对应 TI1） */
    } // namespace USBINTR

    /** @brief USB Frame Index Register */
    namespace FRINDEX {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8008014C, LowLevel::Access::ReadWrite>;
        using UINDEX = LowLevel::Field<Reg, 0, 3, std::uint32_t>; /**< 微帧索引（当前微帧号，0-7） */
        /** @brief FRINDEX 的取值。 */
        enum class FRINDEX_Values : std::uint32_t {
            N_12 = 0xC,
            N_11 = 0xB,
            N_10 = 0xA,
            N_9 = 0x9,
            N_8 = 0x8,
            N_7 = 0x7,
            N_6 = 0x6,
            N_5 = 0x5,
        };
        using FRINDEX = LowLevel::Field<Reg, 3, 11, FRINDEX_Values>; /**< 帧索引（当前帧号，与帧列表配合） */
    } // namespace FRINDEX

    /** @brief Frame List Base Address Register (Host Controller mode) */
    namespace PERIODICLISTBASE {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080154, LowLevel::Access::ReadWrite>;
        using PERBASE = LowLevel::Field<Reg, 12, 20, std::uint32_t>; /**< 周期性帧列表基地址（4K 对齐，Host 模式） */
    } // namespace PERIODICLISTBASE

    /** @brief USB Device Address Register (Device Controller mode)。注：该物理地址在 Host 模式下为 PERIODICLISTBASE。 */
    namespace DEVICEADDR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080154, LowLevel::Access::ReadWrite>;
        using USBADRA = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< USB 设备地址立即生效（写 1 使 USBADR 立即生效） */
        using USBADR = LowLevel::Field<Reg, 25, 7, std::uint32_t>; /**< USB 设备地址（7 位，Device 模式） */
    } // namespace DEVICEADDR

    /** @brief Next Asynchronous Address Register (Host Controller mode) */
    namespace ASYNCLISTADDR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080158, LowLevel::Access::ReadWrite>;
        using ASYBASE = LowLevel::Field<Reg, 5, 27, std::uint32_t>; /**< 异步列表下一队列头基地址（32 字节对齐，Host 模式） */
    } // namespace ASYNCLISTADDR

    /** @brief Endpoint List Address Register (Device Controller mode)。注：该物理地址在 Host 模式下为 ASYNCLISTADDR。 */
    namespace ENDPOINTLISTADDR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080158, LowLevel::Access::ReadWrite>;
        using EPBASE = LowLevel::Field<Reg, 11, 21, std::uint32_t>; /**< 端点队列头（QH）列表基地址（2K 对齐，Device 模式） */
    } // namespace ENDPOINTLISTADDR

    /** @brief Embedded TT Asynchronous Buffer Status and Control Register (Host Controller mode) */
    namespace TTCTRL {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8008015C, LowLevel::Access::ReadWrite>;
        using TTHA = LowLevel::Field<Reg, 24, 7, std::uint32_t>; /**< TT 异步缓冲区水位线（Host 模式） */
    } // namespace TTCTRL

    /** @brief Programmable Burst Size Register */
    namespace BURSTSIZE {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080160, LowLevel::Access::ReadWrite>;
        using RXPBURST = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< RX 突发传输长度（一次 AHB 突发中读的数据 beats 数） */
        using TXPBURST = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< TX 突发传输长度（一次 AHB 突发中写的数据 beats 数） */
    } // namespace BURSTSIZE

    /** @brief Host Transmit Pre-Buffer Packet Timing Register */
    namespace TXFILLTUNING {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080164, LowLevel::Access::ReadWrite>;
        using TXSCHOH = LowLevel::Field<Reg, 0, 7, std::uint32_t>; /**< TX 调度过载健康计数（Host 模式） */
        using TXSCHEALTH = LowLevel::Field<Reg, 8, 5, std::uint32_t>; /**< TX 调度健康计数器（Host 模式） */
        using TXFIFOTHRES = LowLevel::Field<Reg, 16, 6, std::uint32_t>; /**< TX FIFO 阈值（Host 模式，预缓冲包触发阈值） */
    } // namespace TXFILLTUNING

    /** @brief Inter-Chip Control Register */
    namespace IC_USB {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8008016C, LowLevel::Access::ReadWrite>;
        /** @brief IC_VDD 的取值。 */
        enum class IC_VDD_Values : std::uint32_t {
            VOLTAGE_NONE = 0x0,
            VOLTAGE_1_0 = 0x1,
            VOLTAGE_1_2 = 0x2,
            VOLTAGE_1_5 = 0x3,
            VOLTAGE_1_8 = 0x4,
            VOLTAGE_3_0 = 0x5,
            RESERVED0 = 0x6,
            RESERVED1 = 0x7,
        };
        using IC_VDD = LowLevel::Field<Reg, 0, 3, IC_VDD_Values>; /**< Inter-Chip 接口电压选择（0=无/1.0V/1.2V/1.5V/1.8V/3.0V 等） */
        using IC_ENABLE = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Inter-Chip 接口使能 */
    } // namespace IC_USB

    /** @brief ULPI Viewport Register */
    namespace ULPI {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080170, LowLevel::Access::ReadWrite>;
        using ULPIDATWR = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< ULPI 数据写（发起 ULPI 寄存器写时的数据） */
        using ULPIDATRD = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< ULPI 数据读（ULPI 寄存器读返回的数据，只读） */
        using ULPIADDR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< ULPI 寄存器地址（要访问的 ULPI 寄存器地址） */
        using ULPIPORT = LowLevel::Field<Reg, 24, 3, std::uint32_t>; /**< ULPI 端口选择 */
        using ULPISS = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< ULPI 状态（0=空闲，1=忙，只读） */
        using ULPIRW = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< ULPI 读写方向（0=读，1=写） */
        using ULPIRUN = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< ULPI 运行（写 1 启动 ULPI 事务，完成后硬件清零） */
        using ULPIWU = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< ULPI 唤醒（写 1 发送 ULPI 唤醒信号） */
    } // namespace ULPI

    /** @brief Endpoint NAK Register */
    namespace ENDPTNAK {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080178, LowLevel::Access::ReadWrite>;
        using EPRN = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< RX 端点 NAK 状态（5 位，每 bit 对应一个端点，只读） */
        using EPTN = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< TX 端点 NAK 状态（5 位，每 bit 对应一个端点，只读） */
    } // namespace ENDPTNAK

    /** @brief Endpoint NAK Enable Register */
    namespace ENDPTNAKEN {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8008017C, LowLevel::Access::ReadWrite>;
        using EPRNE = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< RX 端点 NAK 中断使能（5 位，每 bit 对应一个端点） */
        using EPTNE = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< TX 端点 NAK 中断使能（5 位，每 bit 对应一个端点） */
    } // namespace ENDPTNAKEN

    /** @brief Port Status and Control 1 Register */
    namespace PORTSC1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80080184, LowLevel::Access::ReadWrite>;
        using CCS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 当前连接状态（1=设备已连接，只读） */
        using CSC = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 连接状态变化（写 1 清零） */
        using PE = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 端口使能（1=端口已使能） */
        using PEC = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 端口使能变化（写 1 清零） */
        using OCA = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 过流状态（1=检测到过流，只读） */
        using OCC = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 过流变化（写 1 清零） */
        using FPR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 强制端口恢复（写 1 从挂起恢复） */
        using SUSP = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 挂起状态（1=端口已挂起） */
        using PR = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 端口复位（写 1 启动端口复位，10ms 后硬件清零） */
        using HSP = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 高速端口（1=端口工作于高速，只读） */
        /** @brief LS 的取值。 */
        enum class LS_Values : std::uint32_t {
            SE0 = 0x0,
            K_STATE = 0x1,
            J_STATE = 0x2,
            UNDEF = 0x3,
        };
        using LS = LowLevel::Field<Reg, 10, 2, LS_Values>; /**< 线路状态（SE0/K_STATE/J_STATE/UNDEF，反映 D+/D- 电平） */
        using PP = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 端口电源（1=端口供电） */
        using PO = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< 端口拥有者（Host 模式，Companion/HC 切换） */
        /** @brief PIC 的取值。 */
        enum class PIC_Values : std::uint32_t {
            OFF = 0x0,
            AMBER = 0x1,
            GREEN = 0x2,
            UNDEF = 0x3,
        };
        using PIC = LowLevel::Field<Reg, 14, 2, PIC_Values>; /**< 端口指示器颜色（OFF/AMBER/GREEN，配合 PI 使用） */
        /** @brief PTC 的取值。 */
        enum class PTC_Values : std::uint32_t {
            TEST_DISABLE = 0x0,
            TEST_J_STATE = 0x1,
            TEST_K_STATE = 0x2,
            TEST_J_SE0_NAK = 0x3,
            TEST_PACKET = 0x4,
            TEST_FORCE_ENABLE_HS = 0x5,
            TEST_FORCE_ENABLE_FS = 0x6,
            TEST_FORCE_ENABLE_LS = 0x7,
        };
        using PTC = LowLevel::Field<Reg, 16, 4, PTC_Values>; /**< 端口测试控制（TEST_DISABLE/J_STATE/K_STATE/PACKET 等） */
        using WKCN = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< 连接唤醒使能（远程唤醒检测） */
        using WKDS = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< 断开唤醒使能 */
        using WKOC = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< 过流唤醒使能 */
        using PHCD = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< PHY 时钟关闭（1=关闭 PHY 时钟以省电） */
        using PFSC = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 强制全速（1=强制端口工作于全速） */
        using SRT = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 串行收发器选择 */
        /** @brief PSPD 的取值。 */
        enum class PSPD_Values : std::uint32_t {
            FULL = 0x0,
            LOW = 0x1,
            HIGH = 0x2,
        };
        using PSPD = LowLevel::Field<Reg, 26, 2, PSPD_Values>; /**< 端口速度（FULL/LOW/HIGH，只读） */
        using PTW = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 端口 16 位 UTMI 宽度（1=使用 16 位数据宽度） */
        using STS = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 串行收发器选择状态 */
        /** @brief PTS 的取值。 */
        enum class PTS_Values : std::uint32_t {
            UTMI = 0x0,
            PHIL = 0x1,
            ULPI = 0x2,
            SERIAL = 0x3,
        };
        using PTS = LowLevel::Field<Reg, 30, 2, PTS_Values>; /**< PHY 收发器选择（UTMI/PHIL/ULPI/SERIAL） */
    } // namespace PORTSC1

    /** @brief OTG Status and Control Register */
    namespace OTGSC {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801A4, LowLevel::Access::ReadWrite>;
        using VD = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< VBUS 放电（写 1 对 VBUS 放电） */
        using VC = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< VBUS 充电（写 1 对 VBUS 充电） */
        using HAAR = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 辅助 A 设备自动重试（Host 模式 A 设备自动重试） */
        using OT = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< OTG 终止（终止 OTG 会话） */
        using DP = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 数据脉冲（写 1 发送数据脉冲） */
        using IDPU = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< ID 上拉使能（1=使能 ID 线上拉） */
        using HADP = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 主机 A 设备断开脉冲（Host 模式 A 设备断开检测） */
        using HABA = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 主机 A 设备 B 设备自动（Host 模式自动切换） */
        using ID = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< ID 状态（0=A 设备，1=B 设备，只读） */
        using AVV = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< A 设备 VBUS 有效（1=VBUS 有效，只读） */
        using ASV = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< A 设备会话有效（1=会话有效，只读） */
        using BSV = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< B 设备会话有效（1=会话有效，只读） */
        using BSE = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< B 设备会话结束（1=会话结束，只读） */
        using ONEMST = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< 1 毫秒定时器（1ms 定时器状态，只读） */
        using DPS = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 数据脉冲状态（只读） */
        using IDIS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< ID 中断状态（写 1 清零） */
        using AVVIS = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< A 设备 VBUS 有效中断状态（写 1 清零） */
        using ASVIS = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< A 设备会话有效中断状态（写 1 清零） */
        using BSVIS = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< B 设备会话有效中断状态（写 1 清零） */
        using BSEIS = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< B 设备会话结束中断状态（写 1 清零） */
        using ONEMSS = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< 1 毫秒定时器中断状态（写 1 清零） */
        using DPIS = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< 数据脉冲中断状态（写 1 清零） */
        using IDIE = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< ID 中断使能 */
        using AVVIE = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< A 设备 VBUS 有效中断使能 */
        using ASVIE = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< A 设备会话有效中断使能 */
        using BSVIE = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< B 设备会话有效中断使能 */
        using BSEIE = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< B 设备会话结束中断使能 */
        using ONEMSE = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 1 毫秒定时器中断使能 */
        using DPIE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 数据脉冲中断使能 */
    } // namespace OTGSC

    /** @brief USB Device Mode Register */
    namespace USBMODE {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801A8, LowLevel::Access::ReadWrite>;
        /** @brief CM 的取值。 */
        enum class CM_Values : std::uint32_t {
            IDLE = 0x0,
            DEVICE = 0x2,
            HOST = 0x3,
        };
        using CM = LowLevel::Field<Reg, 0, 2, CM_Values>; /**< 控制器模式（0=空闲 IDLE，2=Device，3=Host，0x1 保留） */
        using ES = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 端点排序（1=大端模式，0=小端模式） */
        using SLOM = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Setup 锁存模式（1=Setup 包不覆盖已有 dTD） */
        using SDIS = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 流 ID 禁用（禁用流 ID 功能） */
        using VBPS = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< VBUS 电源选择 */
    } // namespace USBMODE

    /** @brief Endpoint Setup Status Register */
    namespace ENDPTSETUPSTAT {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801AC, LowLevel::Access::ReadWrite>;
        using ENDPTSETUPSTAT = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< 端点 Setup 包到达状态（5 位，每 bit 对应一个端点，写 1 清零） */
    } // namespace ENDPTSETUPSTAT

    /** @brief Endpoint Initialization Register */
    namespace ENDPTPRIME {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801B0, LowLevel::Access::ReadWrite>;
        using PERB = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< RX 端点 PRIME（5 位，每 bit 对应一个端点，写 1 请求硬件准备接收缓冲区） */
        using PETB = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< TX 端点 PRIME（5 位，每 bit 对应一个端点，写 1 请求硬件准备发送缓冲区） */
    } // namespace ENDPTPRIME

    /** @brief Endpoint De-Initialize Register */
    namespace ENDPTFLUSH {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801B4, LowLevel::Access::ReadWrite>;
        using FERB = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< RX 端点 FLUSH（5 位，每 bit 对应一个端点，写 1 刷新 RX 端点缓冲区） */
        using FETB = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< TX 端点 FLUSH（5 位，每 bit 对应一个端点，写 1 刷新 TX 端点缓冲区） */
    } // namespace ENDPTFLUSH

    /** @brief Endpoint Status Register */
    namespace ENDPTSTAT {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801B8, LowLevel::Access::ReadWrite>;
        using ERBR = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< RX 端点缓冲区就绪（5 位，每 bit 对应一个端点，只读） */
        using ETBR = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< TX 端点缓冲区就绪（5 位，每 bit 对应一个端点，只读） */
    } // namespace ENDPTSTAT

    /** @brief Endpoint Complete Register */
    namespace ENDPTCOMPLETE {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801BC, LowLevel::Access::ReadWrite>;
        using ERCE = LowLevel::Field<Reg, 0, 5, std::uint32_t>; /**< RX 端点传输完成（5 位，每 bit 对应一个端点，写 1 清零） */
        using ETCE = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< TX 端点传输完成（5 位，每 bit 对应一个端点，写 1 清零） */
    } // namespace ENDPTCOMPLETE

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801C0, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL0

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801C4, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL1

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801C8, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL2

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL3 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801CC, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL3

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL4 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801D0, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL4

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL5 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801D4, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL5

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL6 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801D8, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL6

    /** @brief ENDPTCTRL */
    namespace ENDPTCTRL7 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800801DC, LowLevel::Access::ReadWrite>;
        using RXS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RX 端点 STALL（1=RX 端点发送 STALL 握手） */
        using RXD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< RX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief RXT 的取值。 */
        enum class RXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using RXT = LowLevel::Field<Reg, 2, 2, RXT_Values>; /**< RX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using RXI = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< RX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using RXR = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< RX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using RXE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< RX 端点使能（1=使能 RX 端点） */
        using TXS = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< TX 端点 STALL（1=TX 端点发送 STALL 握手） */
        using TXD = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< TX 端点数据切换（只读，反映当前数据切换状态） */
        /** @brief TXT 的取值。 */
        enum class TXT_Values : std::uint32_t {
            CONTROL = 0x0,
            ISO = 0x1,
            BULK = 0x2,
            INT = 0x3,
        };
        using TXT = LowLevel::Field<Reg, 18, 2, TXT_Values>; /**< TX 端点类型（00=控制/01=等时/10=批量/11=中断） */
        using TXI = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< TX 端点数据切换禁止（写 1 禁止硬件自动数据切换） */
        using TXR = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< TX 端点数据切换复位（写 1 复位数据切换序列为 DATA0） */
        using TXE = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< TX 端点使能（1=使能 TX 端点） */
    } // namespace ENDPTCTRL7

} // namespace Hardware::Registers::USBCTRL

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_USBCTRL
