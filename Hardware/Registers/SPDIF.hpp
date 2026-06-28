#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_SPDIF
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_SPDIF

/**
 * @file SPDIF.hpp
 * @brief SPDIF 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * S/PDIF 数字音频发送接口
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::SPDIF {

    /** @brief SPDIF Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80054000, 0x80054004, 0x80054008, 0x8005400C, LowLevel::Access::ReadWrite>;
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Set to 1 to start SPDIF conversion. Actual conversion begins when FIFO is filled (4 or 8 words depending on sample format). Reset: 0x0. */
        using FIFO_ERROR_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Enable SPDIF interrupt request on FIFO overflow or underflow status conditions. Reset: 0x0. */
        using FIFO_OVERFLOW_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Set by hardware on FIFO overflow during SPDIF transmission. Reset by writing 1 to SCT clear address space. Reset: 0x0. */
        using FIFO_UNDERFLOW_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Set by hardware on FIFO underflow during SPDIF transmission. Reset by writing 1 to SCT clear address space. Reset: 0x0. */
        using WORD_LENGTH = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 0 = 32-bit mode (24 MSBs of DATA transmitted), 1 = 16-bit mode (8 zeros appended to LSBs). SPDIF frame always transmits only 24 bits. Reset: 0x0. */
        using WAIT_END_XFER = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< When set, SPDIF transmitter waits until internal FIFO is empty before halting on RUN deassertion. Use with HW_SPDIF_STAT_END_XFER. Reset: 0x1. */
        using DMAWAIT_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, std::uint32_t>; /**< DMA Request Delay Count (0-31 APBX clock cycles). Throttles bandwidth consumed by SPDIF block. Can be loaded by DMA. Reset: 0x00. */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Clock gate. Set to 1 to gate off clocks to block. Must coordinate with HW_CLKCTRL_SPDIF.CLKGATE. Clear to 0 for normal operation. */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Soft reset. Setting to 1 forces reset to entire block and gates clocks off. Must be cleared to 0 for normal operation. Reset: 0x1. */
    } // namespace CTRL

    /** @brief SPDIF Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80054010, 0x80054014, 0x80054018, 0x8005401C, LowLevel::Access::ReadWrite>;
        using END_XFER = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Indicates SPDIF module has completed transfer of all data including internal FIFOs. Use with HW_SPDIF_CTRL.WAIT_END_XFER. Reset: 0x0. */
        using PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Set to 1 in products where SPDIF is present. Read-only. Reset: 0x1. */
    } // namespace STAT

    /** @brief SPDIF Frame Control Register */
    namespace FRAMECTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80054020, 0x80054024, 0x80054028, 0x8005402C, LowLevel::Access::ReadWrite>;
        using PRO = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Channel usage: 0 = Consumer use, 1 = Professional use. Reset: 0x0. */
        using AUDIO = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Audio type: 0 = PCM data, 1 = Non-PCM data. Reset: 0x0. */
        using COPY = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Copyright: 0 = Copyright NOT asserted, 1 = Copyright asserted. Reset: 0x0. */
        using PRE = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Pre-Emphasis: 0 = No Pre-Emphasis, 1 = Pre-Emphasis is 50/15 usec. Reset: 0x0. */
        using CC = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 7, std::uint32_t>; /**< Category Code (7 bits). Defined by IEC standard or as appropriate. Reset: 0x0. */
        using L = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Generation Level bit. Defined by IEC standard or as appropriate. Reset: 0x0. */
        using V = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Validity bit: 0 = Sub-frame valid (correctly transmitted/received), 1 = Sub-frame invalid. Reset: 0x0. */
        using USER_DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< User Data bit. Transmitted during each sub-frame. Consult IEC-60958 for additional details. Reset: 0x0. */
        using AUTO_MUTE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Auto-Mute stream on stream-suspend detect. Reset: 0x0. */
        using V_CONFIG = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< SPDIF behavior on invalid frames: 0 = Do NOT tag as invalid, 1 = Tag frame as invalid. Reset: 0x1. */
    } // namespace FRAMECTRL

    /** @brief SPDIF Sample Rate Register */
    namespace SRR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80054030, 0x80054034, 0x80054038, 0x8005403C, LowLevel::Access::ReadWrite>;
        using RATE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 20, std::uint32_t>; /**< Sample-Rate Conversion Factor. Valid entries: 0x07D00 (32k), 0x0AC44 (44.1k), 0x0BB80 (48k). Reset: 0x00000. */
        using BASEMULT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 3, std::uint32_t>; /**< Base-Rate Multiplier: 1 = Single-Rate (48 kHz), 2 = Double-Rate (96 kHz). Reset: 0x1. */
    } // namespace SRR

    /** @brief SPDIF Debug Register */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80054040, LowLevel::Access::ReadOnly>;
        using FIFO_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Set when FIFO has empty space, reflecting a DMA request being generated. Reset: 0x1. */
        using DMA_PREQ = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< DMA Request Status. Reflects current DMA request signal state. Polled by software for PIO mode data movement. Reset: 0x0. */
    } // namespace DEBUG

    /** @brief SPDIF Write Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80054050, 0x80054054, 0x80054058, 0x8005405C, LowLevel::Access::ReadWrite>;
        using LOW = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 16-bit mode: entire left channel sample. 32-bit mode: 16 LSBs of the 32-bit sample (left or right). Reset: 0x0000. */
        using HIGH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 16-bit mode: entire right channel sample. 32-bit mode: 16 MSBs of the 32-bit sample (left or right). Reset: 0x0000. */
    } // namespace DATA

    /** @brief SPDIF Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80054060, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Fixed read-only value reflecting the stepping of the RTL version. Reset: 0x0000. */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Fixed read-only value reflecting the MINOR field of the RTL version. Reset: 0x01. */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Fixed read-only value reflecting the MAJOR field of the RTL version. Reset: 0x01. */
    } // namespace VERSION

} // namespace Hardware::Registers::SPDIF

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_SPDIF
