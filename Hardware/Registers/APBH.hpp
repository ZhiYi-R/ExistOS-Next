#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_APBH
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_APBH

/**
 * @file APBH.hpp
 * @brief APBH 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * AHB-to-APBH 桥 DMA 控制器(为 GPMI/NAND、LCDIF 等高速外设提供 DMA 通道)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::APBH {

    /** @brief AHB to APBH Bridge Control and Status Register 0 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008000, 0x80008004, 0x80008008, 0x8000800C, LowLevel::Access::ReadWrite>;
        /** @brief FREEZE_CHANNEL 的取值。 */
        enum class FREEZE_CHANNEL_Values : std::uint32_t {
            LCDIF = 0x1,
            SSP1 = 0x2,
            SSP2 = 0x4,
            ATA = 0x10,
            NAND1 = 0x20,
            NAND2 = 0x40,
            NAND3 = 0x80,
        };
        using FREEZE_CHANNEL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, FREEZE_CHANNEL_Values>; /**< Freeze Channel，8位读写字段。 */
        /** @brief CLKGATE_CHANNEL 的取值。 */
        enum class CLKGATE_CHANNEL_Values : std::uint32_t {
            LCDIF = 0x1,
            SSP1 = 0x2,
            SSP2 = 0x4,
            ATA = 0x10,
            NAND1 = 0x20,
            NAND2 = 0x40,
            NAND3 = 0x80,
        };
        using CLKGATE_CHANNEL = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, CLKGATE_CHANNEL_Values>; /**< Clkgate Channel，8位读写字段。 */
        /** @brief RESET_CHANNEL 的取值。 */
        enum class RESET_CHANNEL_Values : std::uint32_t {
            LCDIF = 0x1,
            SSP1 = 0x2,
            SSP2 = 0x4,
            ATA = 0x10,
            NAND1 = 0x20,
            NAND2 = 0x40,
            NAND3 = 0x80,
        };
        using RESET_CHANNEL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, RESET_CHANNEL_Values>; /**< Reset Channel，8位读写字段。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 时钟门控控制位，写1关闭模块时钟以节省功耗，配置状态保持。写0恢复正常时钟供应。 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 软复位控制位，写1复位本模块，写0恢复正常运行。复位后所有寄存器回到默认值。 */
    } // namespace CTRL0

    /** @brief AHB to APBH Bridge Control and Status Register 1 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008010, 0x80008014, 0x80008018, 0x8000801C, LowLevel::Access::ReadWrite>;
        using CH0_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Ch0 Cmdcmplt Irq，1位读写字段。 */
        using CH1_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Ch1 Cmdcmplt Irq，1位读写字段。 */
        using CH2_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Ch2 Cmdcmplt Irq，1位读写字段。 */
        using CH3_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Ch3 Cmdcmplt Irq，1位读写字段。 */
        using CH4_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Ch4 Cmdcmplt Irq，1位读写字段。 */
        using CH5_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Ch5 Cmdcmplt Irq，1位读写字段。 */
        using CH6_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Ch6 Cmdcmplt Irq，1位读写字段。 */
        using CH7_CMDCMPLT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Ch7 Cmdcmplt Irq，1位读写字段。 */
        using CH0_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Ch0 Cmdcmplt Irq En，1位读写字段。 */
        using CH1_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Ch1 Cmdcmplt Irq En，1位读写字段。 */
        using CH2_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Ch2 Cmdcmplt Irq En，1位读写字段。 */
        using CH3_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< Ch3 Cmdcmplt Irq En，1位读写字段。 */
        using CH4_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Ch4 Cmdcmplt Irq En，1位读写字段。 */
        using CH5_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Ch5 Cmdcmplt Irq En，1位读写字段。 */
        using CH6_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Ch6 Cmdcmplt Irq En，1位读写字段。 */
        using CH7_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< Ch7 Cmdcmplt Irq En，1位读写字段。 */
        using CH0_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Ch0 Ahb Error Irq，1位读写字段。 */
        using CH1_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< Ch1 Ahb Error Irq，1位读写字段。 */
        using CH2_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Ch2 Ahb Error Irq，1位读写字段。 */
        using CH3_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< Ch3 Ahb Error Irq，1位读写字段。 */
        using CH4_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< Ch4 Ahb Error Irq，1位读写字段。 */
        using CH5_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< Ch5 Ahb Error Irq，1位读写字段。 */
        using CH6_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Ch6 Ahb Error Irq，1位读写字段。 */
        using CH7_AHB_ERROR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< Ch7 Ahb Error Irq，1位读写字段。 */
    } // namespace CTRL1

    /** @brief AHB to APBH DMA Device Assignment Register */
    namespace DEVSEL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008020, 0x80008024, 0x80008028, 0x8000802C, LowLevel::Access::ReadWrite>;
        using CH0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< CH0 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH1 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, std::uint32_t>; /**< CH1 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH2 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< CH2 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH3 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< CH3 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH4 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< CH4 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH5 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 4, std::uint32_t>; /**< CH5 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH6 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< CH6 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
        using CH7 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 4, std::uint32_t>; /**< CH7 通道设备分配只读值，反映复位固定的 DMA 通道到外设的分配关系。PDF 标记为 RO/保留。 */
    } // namespace DEVSEL

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH0_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008040, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH0_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH0_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008050, 0x80008054, 0x80008058, 0x8000805C, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH0_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH0_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008060, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH0_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH0_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008070, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH0_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH0_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008080, 0x80008084, 0x80008088, 0x8000808C, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH0_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH0_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008090, LowLevel::Access::ReadOnly>;
    } // namespace CH0_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH0_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800080A0, LowLevel::Access::ReadOnly>;
    } // namespace CH0_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH1_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800080B0, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH1_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH1_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800080C0, 0x800080C4, 0x800080C8, 0x800080CC, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH1_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH1_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800080D0, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH1_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH1_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800080E0, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH1_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH1_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800080F0, 0x800080F4, 0x800080F8, 0x800080FC, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH1_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH1_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008100, LowLevel::Access::ReadOnly>;
    } // namespace CH1_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH1_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008110, LowLevel::Access::ReadOnly>;
    } // namespace CH1_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH2_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008120, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH2_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH2_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008130, 0x80008134, 0x80008138, 0x8000813C, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH2_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH2_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008140, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH2_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH2_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008150, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH2_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH2_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008160, 0x80008164, 0x80008168, 0x8000816C, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH2_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH2_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008170, LowLevel::Access::ReadOnly>;
    } // namespace CH2_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH2_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008180, LowLevel::Access::ReadOnly>;
    } // namespace CH2_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH3_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008190, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH3_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH3_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800081A0, 0x800081A4, 0x800081A8, 0x800081AC, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH3_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH3_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800081B0, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH3_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH3_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800081C0, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH3_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH3_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800081D0, 0x800081D4, 0x800081D8, 0x800081DC, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH3_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH3_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800081E0, LowLevel::Access::ReadOnly>;
    } // namespace CH3_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH3_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800081F0, LowLevel::Access::ReadOnly>;
    } // namespace CH3_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH4_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008200, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH4_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH4_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008210, 0x80008214, 0x80008218, 0x8000821C, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH4_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH4_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008220, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH4_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH4_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008230, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH4_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH4_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008240, 0x80008244, 0x80008248, 0x8000824C, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH4_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH4_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008250, LowLevel::Access::ReadOnly>;
    } // namespace CH4_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH4_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008260, LowLevel::Access::ReadOnly>;
    } // namespace CH4_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH5_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008270, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH5_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH5_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008280, 0x80008284, 0x80008288, 0x8000828C, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH5_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH5_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008290, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH5_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH5_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800082A0, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH5_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH5_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800082B0, 0x800082B4, 0x800082B8, 0x800082BC, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH5_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH5_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800082C0, LowLevel::Access::ReadOnly>;
    } // namespace CH5_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH5_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800082D0, LowLevel::Access::ReadOnly>;
    } // namespace CH5_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH6_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800082E0, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH6_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH6_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800082F0, 0x800082F4, 0x800082F8, 0x800082FC, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH6_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH6_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008300, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH6_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH6_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008310, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH6_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH6_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008320, 0x80008324, 0x80008328, 0x8000832C, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH6_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH6_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008330, LowLevel::Access::ReadOnly>;
    } // namespace CH6_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH6_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008340, LowLevel::Access::ReadOnly>;
    } // namespace CH6_DEBUG2

    /** @brief DMA 通道当前命令描述符物理地址(只读,DMA 引擎执行时自动更新)。 */
    namespace CH7_CURCMDAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008350, LowLevel::Access::ReadOnly>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 当前命令描述符的 32 位物理地址。 */
    } // namespace CH7_CURCMDAR

    /** @brief DMA 通道下一命令描述符物理地址(读写,软件写入待执行描述符链首地址)。 */
    namespace CH7_NXTCMDAR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008360, 0x80008364, 0x80008368, 0x8000836C, LowLevel::Access::ReadWrite>;
        using CMD_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 下一命令描述符的 32 位物理地址。 */
    } // namespace CH7_NXTCMDAR

    /** @brief DMA 通道当前命令字(只读,镜像正在执行描述符的 CMD 字)。 */
    namespace CH7_CMD {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008370, LowLevel::Access::ReadOnly>;
        using COMMAND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 传输方向：0=不传输，1=外设→内存(DMA_WRITE)，2=内存→外设(DMA_READ)，3=条件分支(DMA_SENSE)。 */
        using CHAIN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 置位则完成后继续取 NEXT 指向的下一描述符。 */
        using IRQONCMPLT = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 置位则描述符完成后产生通道命令完成中断。 */
        using NANDLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 置位则把 GPMI 锁定给本通道直到解锁。 */
        using NANDWAIT4READY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 置位则等待 NAND R/B 就绪信号后再继续。 */
        using SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 置位则完成后递减通道信号量。 */
        using WAIT4ENDCMD = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 置位则等待外设结束命令握手后再推进描述符。 */
        using HALTONTERMINATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 置位则在终止时停在当前描述符。 */
        using CMDWORDS = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 随描述符的 PIO 字数。 */
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 本次 DMA 传输字节数。 */
    } // namespace CH7_CMD

    /** @brief DMA 通道缓冲区基址(只读,镜像当前描述符的负载缓冲物理地址)。 */
    namespace CH7_BAR {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008380, LowLevel::Access::ReadOnly>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 负载缓冲的 32 位物理地址。 */
    } // namespace CH7_BAR

    /** @brief DMA 通道信号量寄存器(读写,写 INCREMENT_SEMA 踢启动传输,读 PHORE 取剩余待处理描述符数)。 */
    namespace CH7_SEMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008390, 0x80008394, 0x80008398, 0x8000839C, LowLevel::Access::ReadWrite>;
        using INCREMENT_SEMA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 写入的值累加到通道信号量,等于排队待执行的描述符个数;非零即启动 DMA。 */
        using PHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 当前信号量计数(只读),为剩余尚未完成的描述符个数。 */
    } // namespace CH7_SEMA

    /** @brief DMA 通道调试寄存器 1(只读,含状态机、FIFO 与命令状态)。 */
    namespace CH7_DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800083A0, LowLevel::Access::ReadOnly>;
    } // namespace CH7_DEBUG1

    /** @brief DMA 通道调试寄存器 2(只读,含 AHB/APB 已传输字节数)。 */
    namespace CH7_DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800083B0, LowLevel::Access::ReadOnly>;
    } // namespace CH7_DEBUG2

} // namespace Hardware::Registers::APBH

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_APBH
