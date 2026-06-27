#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_UARTDBG
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_UARTDBG

/**
 * @file UARTDBG.hpp
 * @brief UARTDBG 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 UARTDBG 调试串口外设（ARM PrimeCell PL011 兼容），基地址 0x80070000，用于内核调试输出。包含数据收发、接收状态/错误清除、标志、红外低功耗计数、整数/小数波特率分频、线控、控制、FIFO 中断触发水平、中断屏蔽、原始中断状态、屏蔽后中断状态、中断清除及 DMA 控制等寄存器。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::UARTDBG {

    /** @brief UART 数据寄存器，读写收发字节并附带接收错误标志。 */
    namespace DR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070000, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< 收发数据字节（8 位），写入时送入发送 FIFO，读取时返回接收 FIFO 数据。 */
        using FE = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 接收帧错误标志（Frame Error），读取时反映最近接收字节的帧错误状态。 */
        using PE = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 接收校验错误标志（Parity Error），读取时反映最近接收字节的校验错误状态。 */
        using BE = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 接收 Break 错误标志（Break Error），读取时反映最近接收字节是否检测到 Break 条件。 */
        using OE = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< 接收溢出错误标志（Overrun Error），读取时反映 FIFO 溢出状态。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace DR

    /** @brief UART 接收状态寄存器（读）/ 错误清除寄存器（写），读取时返回接收错误状态，写入时向 EC 字段写值以清除错误标志。 */
    namespace RSR_ECR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070004, LowLevel::Access::ReadWrite>;
        using FE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 帧错误状态（Frame Error）。 */
        using PE = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 校验错误状态（Parity Error）。 */
        using BE = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Break 错误状态（Break Error）。 */
        using OE = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 溢出错误状态（Overrun Error）。 */
        using EC = LowLevel::Field<Reg, 4, 4, std::uint32_t>; /**< 错误清除（Error Clear），写入时向该 4 位字段写值以清除接收错误标志。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 8, 24, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace RSR_ECR

    /** @brief UART 标志寄存器（只读），反映 UART 当前状态与 FIFO 状态。 */
    namespace FR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070018, LowLevel::Access::ReadWrite>;
        using CTS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< CTS 调制解调器状态输入（Clear To Send）。 */
        using DSR = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< DSR 调制解调器状态输入（Data Set Ready）。 */
        using DCD = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< DCD 调制解调器状态输入（Data Carrier Detect）。 */
        using BUSY = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 发送忙标志，表示 UART 正在发送数据。 */
        using RXFE = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 接收 FIFO 空标志（Receive FIFO Empty）。 */
        using TXFF = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 发送 FIFO 满标志（Transmit FIFO Full）。 */
        using RXFF = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 接收 FIFO 满标志（Receive FIFO Full）。 */
        using TXFE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 发送 FIFO 空标志（Transmit FIFO Empty）。 */
        using RI = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< RI 调制解调器状态输入（Ring Indicator）。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace FR

    /** @brief UART IrDA 低功耗计数寄存器，配置低功耗分频值。 */
    namespace ILPR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070020, LowLevel::Access::ReadWrite>;
        using ILPDVSR = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< IrDA 低功耗分频值（IrDA Low-Power Divisor），用于 IrDA SIR 低功耗模式的波特率生成。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 8, 24, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace ILPR

    /** @brief UART 整数波特率分频寄存器，设置波特率整数分频值。 */
    namespace IBRD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070024, LowLevel::Access::ReadWrite>;
        using BAUD_DIVINT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 波特率整数分频值（Baud Rate Integer Divisor），与 FBRD 共同决定 UART 波特率。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace IBRD

    /** @brief UART 小数波特率分频寄存器，设置波特率小数分频值。 */
    namespace FBRD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070028, LowLevel::Access::ReadWrite>;
        using BAUD_DIVFRAC = LowLevel::Field<Reg, 0, 6, std::uint32_t>; /**< 波特率小数分频值（Baud Rate Fractional Divisor），与 IBRD 共同决定 UART 波特率。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 8, 24, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace FBRD

    /** @brief UART 线控寄存器（高字节），配置数据格式、校验、停止位及 FIFO 使能。 */
    namespace LCR_H {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8007002C, LowLevel::Access::ReadWrite>;
        using BRK = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 发送 Break 控制，置位时强制 UART 输出低电平 Break 条件。 */
        using PEN = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 校验使能（Parity Enable），置位时启用奇偶校验。 */
        using EPS = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 偶校验选择（Even Parity Select），置位时选择偶校验，清零时选择奇校验。 */
        using STP2 = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 双停止位使能（Two Stop Bits），置位时发送两个停止位。 */
        using FEN = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< FIFO 使能（FIFO Enable），置位时启用发送/接收 FIFO。 */
        using WLEN = LowLevel::Field<Reg, 5, 2, std::uint32_t>; /**< 字长选择（Word Length），00=5 位、01=6 位、10=7 位、11=8 位。 */
        using SPS = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< Stick 校验选择（Stick Parity Select），置位时强制校验位为固定值。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace LCR_H

    /** @brief UART 控制寄存器，使能 UART、收发方向、环回及调制解调器控制。 */
    namespace CR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070030, LowLevel::Access::ReadWrite>;
        using UARTEN = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< UART 使能（UART Enable），置位时启动 UART 模块。 */
        using SIREN = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< IrDA SIR 模式使能（SIR Enable），置位时启用 IrDA SIR 编码/解码。 */
        using SIRLP = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< IrDA SIR 低功耗模式使能（SIR Low-Power），置位时启用 IrDA 低功耗模式。 */
        using LBE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 环回使能（Loopback Enable），置位时内部将发送输出连接到接收输入用于自测。 */
        using TXE = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 发送使能（Transmit Enable），置位时允许 UART 发送数据。 */
        using RXE = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 接收使能（Receive Enable），置位时允许 UART 接收数据。 */
        using DTR = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< DTR 调制解调器输出控制（Data Terminal Ready）。 */
        using RTS = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< RTS 调制解调器输出控制（Request To Send）。 */
        using OUT1 = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< OUT1 调制解调器输出控制信号 1。 */
        using OUT2 = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< OUT2 调制解调器输出控制信号 2。 */
        using RTSEN = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< RTS 硬件流控使能（RTS Hardware Flow Control Enable），置位时启用 RTS 自动流控。 */
        using CTSEN = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< CTS 硬件流控使能（CTS Hardware Flow Control Enable），置位时启用 CTS 自动流控。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace CR

    /** @brief UART FIFO 中断触发水平选择寄存器，设置收发 FIFO 中断阈值。 */
    namespace IFLS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070034, LowLevel::Access::ReadWrite>;
        /** @brief TXIFLSEL 的取值。 */
        enum class TXIFLSEL_Values : std::uint32_t {
            EMPTY = 0x0,
            ONE_QUARTER = 0x1,
            ONE_HALF = 0x2,
            THREE_QUARTERS = 0x3,
            SEVEN_EIGHTHS = 0x4,
            INVALID5 = 0x5,
            INVALID6 = 0x6,
            INVALID7 = 0x7,
        };
        using TXIFLSEL = LowLevel::Field<Reg, 0, 3, TXIFLSEL_Values>; /**< 发送 FIFO 中断触发水平选择（Transmit Interrupt FIFO Level Select），0=空、1=1/4、2=1/2、3=3/4、4=7/8、5-7=保留无效值。 */
        /** @brief RXIFLSEL 的取值。 */
        enum class RXIFLSEL_Values : std::uint32_t {
            NOT_EMPTY = 0x0,
            ONE_QUARTER = 0x1,
            ONE_HALF = 0x2,
            THREE_QUARTERS = 0x3,
            SEVEN_EIGHTHS = 0x4,
            INVALID5 = 0x5,
            INVALID6 = 0x6,
            INVALID7 = 0x7,
        };
        using RXIFLSEL = LowLevel::Field<Reg, 3, 3, RXIFLSEL_Values>; /**< 接收 FIFO 中断触发水平选择（Receive Interrupt FIFO Level Select），0=非空、1=1/4、2=1/2、3=3/4、4=7/8、5-7=保留无效值。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace IFLS

    /** @brief UART 中断屏蔽设置/清除寄存器，写 1 置位屏蔽对应中断，写 0 清除屏蔽。 */
    namespace IMSC {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070038, LowLevel::Access::ReadWrite>;
        using RIMIM = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RI 调制解调器中断屏蔽（Ring Indicator Interrupt Mask）。 */
        using CTSMIM = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< CTS 调制解调器中断屏蔽（CTS Interrupt Mask）。 */
        using DCDMIM = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< DCD 调制解调器中断屏蔽（DCD Interrupt Mask）。 */
        using DSRMIM = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< DSR 调制解调器中断屏蔽（DSR Interrupt Mask）。 */
        using RXIM = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 接收中断屏蔽（Receive Interrupt Mask）。 */
        using TXIM = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 发送中断屏蔽（Transmit Interrupt Mask）。 */
        using RTIM = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 接收超时中断屏蔽（Receive Timeout Interrupt Mask）。 */
        using FEIM = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 帧错误中断屏蔽（Framing Error Interrupt Mask）。 */
        using PEIM = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 校验错误中断屏蔽（Parity Error Interrupt Mask）。 */
        using BEIM = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Break 错误中断屏蔽（Break Error Interrupt Mask）。 */
        using OEIM = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 溢出错误中断屏蔽（Overrun Error Interrupt Mask）。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace IMSC

    /** @brief UART 原始中断状态寄存器（只读），反映各中断源在屏蔽前的原始状态。 */
    namespace RIS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8007003C, LowLevel::Access::ReadWrite>;
        using RIRMIS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RI 原始中断状态（Ring Indicator Raw Interrupt Status）。 */
        using CTSRMIS = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< CTS 原始中断状态（CTS Raw Interrupt Status）。 */
        using DCDRMIS = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< DCD 原始中断状态（DCD Raw Interrupt Status）。 */
        using DSRRMIS = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< DSR 原始中断状态（DSR Raw Interrupt Status）。 */
        using RXRIS = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 接收原始中断状态（Receive Raw Interrupt Status）。 */
        using TXRIS = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 发送原始中断状态（Transmit Raw Interrupt Status）。 */
        using RTRIS = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 接收超时原始中断状态（Receive Timeout Raw Interrupt Status）。 */
        using FERIS = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 帧错误原始中断状态（Framing Error Raw Interrupt Status）。 */
        using PERIS = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 校验错误原始中断状态（Parity Error Raw Interrupt Status）。 */
        using BERIS = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Break 错误原始中断状态（Break Error Raw Interrupt Status）。 */
        using OERIS = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 溢出错误原始中断状态（Overrun Error Raw Interrupt Status）。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace RIS

    /** @brief UART 屏蔽后中断状态寄存器（只读），反映经过 IMSC 屏蔽后的有效中断状态。 */
    namespace MIS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070040, LowLevel::Access::ReadWrite>;
        using RIMMIS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< RI 屏蔽后中断状态（Ring Indicator Masked Interrupt Status）。 */
        using CTSMMIS = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< CTS 屏蔽后中断状态（CTS Masked Interrupt Status）。 */
        using DCDMMIS = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< DCD 屏蔽后中断状态（DCD Masked Interrupt Status）。 */
        using DSRMMIS = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< DSR 屏蔽后中断状态（DSR Masked Interrupt Status）。 */
        using RXMIS = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 接收屏蔽后中断状态（Receive Masked Interrupt Status）。 */
        using TXMIS = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 发送屏蔽后中断状态（Transmit Masked Interrupt Status）。 */
        using RTMIS = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 接收超时屏蔽后中断状态（Receive Timeout Masked Interrupt Status）。 */
        using FEMIS = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 帧错误屏蔽后中断状态（Framing Error Masked Interrupt Status）。 */
        using PEMIS = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 校验错误屏蔽后中断状态（Parity Error Masked Interrupt Status）。 */
        using BEMIS = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Break 错误屏蔽后中断状态（Break Error Masked Interrupt Status）。 */
        using OEMIS = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 溢出错误屏蔽后中断状态（Overrun Error Masked Interrupt Status）。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace MIS

    /** @brief UART 中断清除寄存器，写入对应位以清除相应中断状态。 */
    namespace ICR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070044, LowLevel::Access::ReadWrite>;
        using RIMIC = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 清除 RI 中断（Ring Indicator Interrupt Clear）。 */
        using CTSMIC = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 清除 CTS 中断（CTS Interrupt Clear）。 */
        using DCDMIC = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 清除 DCD 中断（DCD Interrupt Clear）。 */
        using DSRMIC = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 清除 DSR 中断（DSR Interrupt Clear）。 */
        using RXIC = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 清除接收中断（Receive Interrupt Clear）。 */
        using TXIC = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 清除发送中断（Transmit Interrupt Clear）。 */
        using RTIC = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 清除接收超时中断（Receive Timeout Interrupt Clear）。 */
        using FEIC = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 清除帧错误中断（Framing Error Interrupt Clear）。 */
        using PEIC = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 清除校验错误中断（Parity Error Interrupt Clear）。 */
        using BEIC = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 清除 Break 错误中断（Break Error Interrupt Clear）。 */
        using OEIC = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 清除溢出错误中断（Overrun Error Interrupt Clear）。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace ICR

    /** @brief UART DMA 控制寄存器，配置 DMA 请求使能及错误处理。 */
    namespace DMACR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80070048, LowLevel::Access::ReadWrite>;
        using RXDMAE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 接收 DMA 使能（Receive DMA Enable），置位时允许接收 FIFO 触发 DMA 请求。 */
        using TXDMAE = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 发送 DMA 使能（Transmit DMA Enable），置位时允许发送 FIFO 触发 DMA 请求。 */
        using DMAONERR = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 错误时停止 DMA（DMA On Error），置位时接收错误时禁止 DMA 请求。 */
        using UNAVAILABLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 未实现位，读取值未定义。 */
    } // namespace DMACR

} // namespace Hardware::Registers::UARTDBG

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_UARTDBG
