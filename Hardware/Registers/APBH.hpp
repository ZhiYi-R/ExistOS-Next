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

} // namespace Hardware::Registers::APBH

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_APBH
