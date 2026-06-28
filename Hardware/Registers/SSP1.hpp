#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_SSP1
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_SSP1

/**
 * @file SSP1.hpp
 * @brief SSP1 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 同步串行端口 1(SSP,支持 SD/MMC 卡与 SPI 主/从模式)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::SSP1 {

    /** @brief SSP Control Register 0 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010000, 0x80010004, 0x80010008, 0x8001000C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Number of words to transfer per WORD_LENGTH in CTRL1. Run bit and DMA request clear after transfer. SD/MMC: multiple of block size. Bits[15:0] RW Reset=0x1 */
        using ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< SD/MMC/MS Command Transmit Enable. 0=commands disabled, 1=data in Command registers will be sent. Bits[16] RW Reset=0x0 */
        using GET_RESP = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< SD/MMC/MS: 0=do not wait for card response, 1=command expects response from card. Bits[17] RW Reset=0x0 */
        using CHECK_RESP = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< SD/MMC/MS: XOR response with REFERENCE, mask with MASK. Mismatch sets RESP_ERR and optionally RESP_ERR_IRQ. Bits[18] RW Reset=0x0 */
        using LONG_RESP = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< SD/MMC: 0=short response, 1=136-bit long response. Only valid if GET_RESP set. Bits[19] RW Reset=0x0 */
        using WAIT_FOR_CMD = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< SD/MMC: 0=send commands immediately, 1=wait until CRC-checking of data transfer completes. Used to send STOP during multi-block read. Bits[20] RW Reset=0x0 */
        using WAIT_FOR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< MS: wait for card IRQ before TPC. SD/MMC: wait for MMC ready before sending command. Bits[21] RW Reset=0x0 */
        /** @brief BUS_WIDTH 的取值。 */
        enum class BUS_WIDTH_Values : std::uint32_t {
            ONE_BIT = 0x0,
            FOUR_BIT = 0x1,
            EIGHT_BIT = 0x2,
        };
        using BUS_WIDTH = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, BUS_WIDTH_Values>; /**< Data Bus Width. ONE_BIT=0x0, FOUR_BIT=0x1, EIGHT_BIT=0x2. SD/MMC/CE_ATA support all; MS 1/4-bit; SPI 1-bit. Bits[23:22] RW Reset=0x0 */
        using DATA_XFER = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Data Transfer Mode. When set, transfers XFER_COUNT bytes of data. MS mode: 1=use FIFOs, 0=use Resp0/Cmd1 registers. Bits[24] RW Reset=0x0 */
        using READ = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Read Mode. When set with DATA_XFER, SSP reads from device. Otherwise SSP writes to device. Bits[25] RW Reset=0x0 */
        using IGNORE_CRC = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Ignore Response CRC in SD/MMC and MS modes. Bits[26] RW Reset=0x0 */
        using LOCK_CS = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< SPI: 0=deassert CS, 1=hold CS. SD/MMC: 0=check CRC status, 1=ignore CRC. CE_ATA: disable CCS. If set, DATA_XFER must also be set. Bits[27] RW Reset=0x0 */
        using SDIO_IRQ_CHECK = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< SD/MMC: enable SDIO IRQ. CE_ATA: 0=ignore CCS, 1=wait for CCS. Must not be 1 if LOCK_CS=1. Bits[28] RW Reset=0x0 */
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< SSP Run. 0=not running, 1=running. Automatically set during DMA operation. Bits[29] RW Reset=0x0 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Gate SSP Clocks. 0=clocks not gated, 1=clocks gated. Set to save power while SSP not actively used. Bits[30] RW Reset=0x1 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SSP Reset. 0=not reset, 1=held in reset. Registers returned to reset state. Min reset time = max(6 APBCLK, 2 SSPCLK) cycles. Bits[31] RW Reset=0x1 */
    } // namespace CTRL0

    /** @brief SD/MMC and MS Command Register 0 */
    namespace CMD0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010010, 0x80010014, 0x80010018, 0x8001001C, LowLevel::Access::ReadWrite>;
        /** @brief CMD 的取值。 */
        enum class CMD_Values : std::uint32_t {
            MMC_GO_IDLE_STATE = 0x0,
            MMC_SEND_OP_COND = 0x1,
            MMC_ALL_SEND_CID = 0x2,
            MMC_SET_RELATIVE_ADDR = 0x3,
            MMC_SET_DSR = 0x4,
            MMC_RESERVED_5 = 0x5,
            MMC_SWITCH = 0x6,
            MMC_SELECT_DESELECT_CARD = 0x7,
            MMC_SEND_EXT_CSD = 0x8,
            MMC_SEND_CSD = 0x9,
            MMC_SEND_CID = 0xA,
            MMC_READ_DAT_UNTIL_STOP = 0xB,
            MMC_STOP_TRANSMISSION = 0xC,
            MMC_SEND_STATUS = 0xD,
            MMC_BUSTEST_R = 0xE,
            MMC_GO_INACTIVE_STATE = 0xF,
            MMC_SET_BLOCKLEN = 0x10,
            MMC_READ_SINGLE_BLOCK = 0x11,
            MMC_READ_MULTIPLE_BLOCK = 0x12,
            MMC_BUSTEST_W = 0x13,
            MMC_WRITE_DAT_UNTIL_STOP = 0x14,
            MMC_SET_BLOCK_COUNT = 0x17,
            MMC_WRITE_BLOCK = 0x18,
            MMC_WRITE_MULTIPLE_BLOCK = 0x19,
            MMC_PROGRAM_CID = 0x1A,
            MMC_PROGRAM_CSD = 0x1B,
            MMC_SET_WRITE_PROT = 0x1C,
            MMC_CLR_WRITE_PROT = 0x1D,
            MMC_SEND_WRITE_PROT = 0x1E,
            MMC_ERASE_GROUP_START = 0x23,
            MMC_ERASE_GROUP_END = 0x24,
            MMC_ERASE = 0x26,
            MMC_FAST_IO = 0x27,
            MMC_GO_IRQ_STATE = 0x28,
            MMC_LOCK_UNLOCK = 0x2A,
            MMC_APP_CMD = 0x37,
            MMC_GEN_CMD = 0x38,
            SD_ERASE_WR_BLK_START = 0x20,
            SD_ERASE_WR_BLK_END = 0x21,
            SD_IO_RW_DIRECT = 0x34,
            SD_IO_RW_EXTENDED = 0x35,
        };
        using CMD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, CMD_Values>; /**< SD/MMC Command Index (bits 5:0) or MS TPC[7:0] to send to card. Also SPI control word[7:0]. Includes all standard MMC/SD commands. Bits[7:0] RW Reset=0x0 */
        using BLOCK_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< SD/MMC block count minus one. Equation: XFER_COUNT = (1<<BLOCK_SIZE)*(BLOCK_COUNT+1). Also SPI control word[15:8]. Bits[15:8] RW Reset=0x0 */
        using BLOCK_SIZE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< SD/MMC block size encode. When BLOCK_COUNT!=0, size = (1<<BLOCK_SIZE). When BLOCK_COUNT=0, ignored. Bits[19:16] RW Reset=0x0 */
        using APPEND_8CYC = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< SD/MMC/CE_ATA: 0=SCK toggles up to 4 cycles idle, 1=8 more cycles. Set to 1 at end of block transfer. Bits[20] RW Reset=0x0 */
        using CONT_CLKING_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< CONT_CLKING_EN。注：PDF第16.11.2节Table 752将bit 31:21标记为RSVD，此字段可能来自后续芯片修订。 */
        using SLOW_CLKING_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< SLOW_CLKING_EN。注：PDF第16.11.2节Table 752将bit 31:21标记为RSVD，此字段可能来自后续芯片修订。 */
    } // namespace CMD0

    /** @brief SD/MMC Command Register 1 */
    namespace CMD1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010020, 0x80010024, 0x80010028, 0x8001002C, LowLevel::Access::ReadWrite>;
        using CMD_ARG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC or MS Command Argument. Bits[31:0] RW Reset=0x0 */
    } // namespace CMD1

    /** @brief SD/MMC and MS Compare Reference */
    namespace COMPREF {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010030, 0x80010034, 0x80010038, 0x8001003C, LowLevel::Access::ReadWrite>;
        using REFERENCE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC/MS compare reference. XOR'd with response when CHECK_RESP set, masked by MASK. Differences indicate error to DMA. Bits[31:0] RW Reset=0x0 */
    } // namespace COMPREF

    /** @brief SD/MMC and MS compare mask */
    namespace COMPMASK {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010040, 0x80010044, 0x80010048, 0x8001004C, LowLevel::Access::ReadWrite>;
        using MASK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC/MS Compare Mode Mask. Masks result of response vs REFERENCE comparison when CHECK_RESP set. Bits[31:0] RW Reset=0x0 */
    } // namespace COMPMASK

    /** @brief SSP Timing Register */
    namespace TIMING {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010050, 0x80010054, 0x80010058, 0x8001005C, LowLevel::Access::ReadWrite>;
        using CLOCK_RATE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< Serial Clock Rate. Bit rate = SSPCLK / (CLOCK_DIVIDE * (1+CLOCK_RATE)). Value from 0 to 255. Bits[7:0] RW Reset=0x0 */
        using CLOCK_DIVIDE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< Clock Pre-Divider. Must be even value from 2 to 254. Bits[15:8] RW Reset=0x0 */
        using TIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Time-Out Counter. SCK cycles * 4096 before asserting DATA TIMEOUT IRQ. Used for SD/MMC and MS data transfer time-out. Bits[31:16] RW Reset=0x0 */
    } // namespace TIMING

    /** @brief SSP Control Register 1 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010060, 0x80010064, 0x80010068, 0x8001006C, LowLevel::Access::ReadWrite>;
        /** @brief SSP_MODE 的取值。 */
        enum class SSP_MODE_Values : std::uint32_t {
            SPI = 0x0,
            SSI = 0x1,
            SD_MMC = 0x3,
            MS = 0x4,
            CE_ATA = 0x7,
        };
        using SSP_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, SSP_MODE_Values>; /**< Operating Mode. 0x0=SPI, 0x1=TI SSI, 0x3=SD/MMC, 0x4=MS, 0x7=CE_ATA. Soft reset before changing. Bits[3:0] RW Reset=0x0 */
        /** @brief WORD_LENGTH 的取值。 */
        enum class WORD_LENGTH_Values : std::uint32_t {
            RESERVED0 = 0x0,
            RESERVED1 = 0x1,
            RESERVED2 = 0x2,
            FOUR_BITS = 0x3,
            EIGHT_BITS = 0x7,
            SIXTEEN_BITS = 0xF,
        };
        using WORD_LENGTH = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, WORD_LENGTH_Values>; /**< Word Length in bits. 0x0-0x2 reserved, 0x3=4b, 0x7=8b, 0xF=16b. Always 8b in SD/MMC/CE_ATA and MS. Bits[7:4] RW Reset=0x8 */
        using SLAVE_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Slave Mode. 0=master, 1=slave. Clear to 0 for SD/MMC and MS modes. Bits[8] RW Reset=0x0 */
        using POLARITY = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Serial Clock Polarity. SD/MMC/MS: CMD/TX edge select. MS 1-bit=1, 4-bit=0. SPI: 0=steady 0, 1=steady 1 when idle. Bits[9] RW Reset=0x0 */
        using PHASE = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Serial Clock Phase. For SPI mode only. Bits[10] RW Reset=0x0 */
        using SLAVE_OUT_DISABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< Slave Output Disable. 0=SSP drives MISO in slave mode, 1=does not drive MISO. Bits[11] RW Reset=0x0 */
        using CEATA_CCS_ERR_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< CE-ATA unexpected CCS error enable. Enables error generation for unexpected CCS. Bits[12] RW Reset=0x0 */
        using DMA_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< DMA Enable. Enables DMA request and command end signals. Bits[13] RW Reset=0x0 */
        using FIFO_OVERRUN_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< FIFO Overrun Interrupt Enable. IRQ if FIFO written while full. Bits[14] RW Reset=0x0 */
        using FIFO_OVERRUN_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< FIFO Overrun Interrupt. Written while full. Write 1 to SET clear address to reset. Bits[15] RW Reset=0x0 */
        using RECV_TIMEOUT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Receive Time-Out IRQ Enable. IRQ if RX FIFO not empty and no read for 128 HCLK cycles. Bits[16] RW Reset=0x0 */
        using RECV_TIMEOUT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< Data Time-Out Interrupt. RX FIFO not empty but not read for 128 HCLK cycles. SPI modes only. Write 1 to SET clear to reset. Bits[17] RW Reset=0x0 */
        using CEATA_CCS_ERR_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< CE-ATA Unexpected CCS Error Interrupt Enable. 0=disable, 1=enable. Bits[18] RW Reset=0x0 */
        using CEATA_CCS_ERR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< CE-ATA unexpected CCS error interrupt. Write 1 to SET clear address to reset. Bits[19] RW Reset=0x0 */
        using FIFO_UNDERRUN_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< FIFO Underrun IRQ Enable. IRQ generated if set and FIFO_UNDERRUN_IRQ asserted. Bits[20] RW Reset=0x0 */
        using FIFO_UNDERRUN_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< FIFO Underrun Interrupt. Set when FIFO read while empty. Write 1 to SET clear address to reset. Bits[21] RW Reset=0x1 */
        using DATA_CRC_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Data CRC Error IRQ Enable. For SD/MMC and MS modes only. Bits[22] RW Reset=0x0 */
        using DATA_CRC_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< Data CRC Error IRQ. For SD/MMC and MS modes only. Write 1 to SET clear address to reset. Bits[23] RW Reset=0x0 */
        using DATA_TIMEOUT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Data Time-Out Error IRQ Enable. For SD/MMC and MS modes only. Bits[24] RW Reset=0x0 */
        using DATA_TIMEOUT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Data transmit/receive time-out error IRQ. Counter expired before data bus ready. SD/MMC and MS only. Bits[25] RW Reset=0x0 */
        using RESP_TIMEOUT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Response Time-Out IRQ Enable. 0=masked, 1=enabled. Asserts when no SD/MMC response in 64 cycles or MS not ready in 16 cycles. Bits[26] RW Reset=0x0 */
        using RESP_TIMEOUT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Command response time-out occurred. SD/MMC and MS handshake. Write 1 to SET clear address to reset. Bits[27] RW Reset=0x0 */
        using RESP_ERR_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Card Error IRQ Enable. 0=masked, 1=enabled. Asserts CPU IRQ when card error bit set in both Error Mask and R1 response. Bits[28] RW Reset=0x0 */
        using RESP_ERR_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Unexpected response/CRC when CHECK_RESP set. Write 1 to SET clear address to reset. Bits[29] RW Reset=0x0 */
        using SDIO_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< SDIO Card Interrupt IRQ Enable. 0=masked, 1=IRQs sent to ICOLL. Bits[30] RW Reset=0x0 */
        using SDIO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SDIO card interrupt occurred. Write 1 to SET clear address to reset. Bits[31] RW Reset=0x0 */
    } // namespace CTRL1

    /** @brief SSP Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010070, 0x80010074, 0x80010078, 0x8001007C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Data Register. Holds 1-4 words per WORD_LENGTH. Right-justified. Read increments RX FIFO; write increments TX FIFO. Bits[31:0] RW Reset=0x0 */
    } // namespace DATA

    /** @brief SD/MMC Card Response Register 0 */
    namespace SDRESP0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010080, 0x80010084, 0x80010088, 0x8001008C, LowLevel::Access::ReadWrite>;
        using RESP0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC Response Status Bits[31:0]. MS mode: device read data. Bits[31:0] RO Reset=0x0 */
    } // namespace SDRESP0

    /** @brief SD/MMC Card Response Register 1 */
    namespace SDRESP1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80010090, 0x80010094, 0x80010098, 0x8001009C, LowLevel::Access::ReadWrite>;
        using RESP1 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC Short Response Command Index[37:32] or Long Response[63:32]. Bits[31:0] RO Reset=0x0 */
    } // namespace SDRESP1

    /** @brief SD/MMC Card Response Register 2 */
    namespace SDRESP2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800100A0, 0x800100A4, 0x800100A8, 0x800100AC, LowLevel::Access::ReadWrite>;
        using RESP2 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC Long Response[95:64]. Bits[31:0] RO Reset=0x0 */
    } // namespace SDRESP2

    /** @brief SD/MMC Card Response Register 3 */
    namespace SDRESP3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800100B0, 0x800100B4, 0x800100B8, 0x800100BC, LowLevel::Access::ReadWrite>;
        using RESP3 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< SD/MMC Long Response[127:96]. Bits[31:0] RO Reset=0x0 */
    } // namespace SDRESP3

    /** @brief SSP Status Register */
    namespace STATUS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800100C0, LowLevel::Access::ReadOnly>;
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< SSP state machines are busy. Bits[0] RO Reset=0x0 */
        using DATA_BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Command controller busy transferring data. Bits[2] RO Reset=0x0 */
        using CMD_BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Command controller busy sending command or receiving response. Bits[3] RO Reset=0x0 */
        using FIFO_UNDRFLW = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< FIFO Underflow has occurred. Bits[4] RO Reset=0x0 */
        using FIFO_EMPTY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< FIFO Empty. Bits[5] RO Reset=0x1 */
        using FIFO_FULL = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< FIFO Full. Bits[8] RO Reset=0x0 */
        using FIFO_OVRFLW = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< FIFO Overflow Interrupt. Bits[9] RO Reset=0x0 */
        using CEATA_CCS_ERR = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Unexpected CCS (CE-ATA Interrupt) occurred. Cleared by soft reset or CTRL0_RUN rising edge. Bits[10] RO Reset=0x0 */
        using RECV_TIMEOUT_STAT = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< Raw receive time-out. RX FIFO non-empty but not read for 128 cycles. Bits[11] RO Reset=0x0 */
        using TIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< SD/MMC: time-out before data bus ready. MS: time-out waiting for IRQ. Cleared by soft reset or CTRL0_RUN. Bits[12] RO Reset=0x0 */
        using DATA_CRC_ERR = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Data CRC Error. Cleared by soft reset or rising edge of CTRL0_RUN. Bits[13] RO Reset=0x0 */
        using RESP_TIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Response not received in 64 cycles (SD/MMC) or 16 (MS). Cleared by soft reset or CTRL0_RUN rising edge. Bits[14] RO Reset=0x0 */
        using RESP_ERR = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< Card response with error condition. Cleared by soft reset or rising edge of CTRL0_RUN. Bits[15] RO Reset=0x0 */
        using RESP_CRC_ERR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< SD/MMC, MS Response CRC failed. Cleared by soft reset or rising edge of CTRL0_RUN. Bits[16] RO Reset=0x0 */
        using SDIO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< SDIO IRQ detected. Bits[17] RO Reset=0x0 */
        using DMAEND = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Reflects ssp_dmaend output port. Toggle signal. Bits[18] RO Reset=0x0 */
        using DMAREQ = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< Reflects ssp_dmareq output port. Toggle signal. Bits[19] RO Reset=0x0 */
        using DMATERM = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< Reflects ssp_dmaterm output port. Toggle signal. Bits[20] RO Reset=0x0 */
        using DMASENSE = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< ssp_dmasense output. Indicates DMA error (time-out/CRC) when high at DMA command end. Bits[21] RO Reset=0x0 */
        using CARD_DETECT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Reflects SSP_DETECT input pin state. Bits[28] RO Reset=0x0 */
        using SD_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< SD/MMC Controller Present. 0=not present, 1=present. Bits[29] RO Reset=0x1 */
        using MS_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< MS Controller Present. 0=not present, 1=present. Bits[30] RO Reset=0x1 */
        using PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SSP Present. 0=not present in product, 1=present. Bits[31] RO Reset=0x1 */
    } // namespace STATUS

    /** @brief SSP Debug Register */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80010100, LowLevel::Access::ReadOnly>;
        using SSP_RXD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< SSP_RXD signal value. Bits[7:0] RO Reset=0x0 */
        using SSP_RESP = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< SSP响应调试值。 */
        using SSP_CMD = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< SSP_CMD signal value. Bits[9] RO Reset=0x0 */
        /** @brief CMD_SM 的取值。 */
        enum class CMD_SM_Values : std::uint32_t {
            CSM_IDLE = 0x0,
            CSM_INDEX = 0x1,
            CSM_ARG = 0x2,
            CSM_CRC = 0x3,
        };
        using CMD_SM = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, CMD_SM_Values>; /**< MMC Command SM: CSM_IDLE=0x0, INDEX=0x1, ARG=0x2, CRC=0x3. Bits[11:10] RO Reset=0x0 */
        /** @brief MMC_SM 的取值。 */
        enum class MMC_SM_Values : std::uint32_t {
            MMC_IDLE = 0x0,
            MMC_CMD = 0x1,
            MMC_TRC = 0x2,
            MMC_RESP = 0x3,
            MMC_RPRX = 0x4,
            MMC_TX = 0x5,
            MMC_CTOK = 0x6,
            MMC_RX = 0x7,
            MMC_CCS = 0x8,
            MMC_PUP = 0x9,
            MMC_WAIT = 0xA,
        };
        using MMC_SM = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, MMC_SM_Values>; /**< MMC SM (11 states): IDLE=0x0 to WAIT=0xA. Includes CMD, TRC, RESP, RPRX, TX, CTOK, RX, CCS, PUP. Bits[15:12] RO Reset=0x0 */
        /** @brief DMA_SM 的取值。 */
        enum class DMA_SM_Values : std::uint32_t {
            DMA_IDLE = 0x0,
            DMA_DMAREQ = 0x1,
            DMA_DMAACK = 0x2,
            DMA_STALL = 0x3,
            DMA_BUSY = 0x4,
            DMA_DONE = 0x5,
            DMA_COUNT = 0x6,
        };
        using DMA_SM = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 3, DMA_SM_Values>; /**< DMA SM: DMA_IDLE=0x0, DMAREQ=0x1, DMAACK=0x2, STALL=0x3, BUSY=0x4, DONE=0x5, COUNT=0x6. Bits[18:16] RO Reset=0x0 */
        using CMD_OE = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< Enable for SSP_CMD. Bits[19] RO Reset=0x0 */
        /** @brief MSTK_SM 的取值。 */
        enum class MSTK_SM_Values : std::uint32_t {
            MSTK_IDLE = 0x0,
            MSTK_CKON = 0x1,
            MSTK_BS1 = 0x2,
            MSTK_TPC = 0x3,
            MSTK_BS2 = 0x4,
            MSTK_HDSHK = 0x5,
            MSTK_BS3 = 0x6,
            MSTK_RW = 0x7,
            MSTK_CRC1 = 0x8,
            MSTK_CRC2 = 0x9,
            MSTK_BS0 = 0xA,
            MSTK_END1 = 0xB,
            MSTK_END2W = 0xC,
            MSTK_END2R = 0xD,
            MSTK_DONE = 0xE,
        };
        using MSTK_SM = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 4, MSTK_SM_Values>; /**< MS State Machine (15 states). MSTK_IDLE=0x0 to MSTK_DONE=0xE. Includes BS1-3, TPC, HDSHK, RW, CRC, END, DONE. Bits[23:20] RO Reset=0x0 */
        /** @brief DAT_SM 的取值。 */
        enum class DAT_SM_Values : std::uint32_t {
            DSM_IDLE = 0x0,
            DSM_WORD = 0x2,
            DSM_CRC1 = 0x3,
            DSM_CRC2 = 0x4,
            DSM_END = 0x5,
        };
        using DAT_SM = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 3, DAT_SM_Values>; /**< Data transfer SM: DSM_IDLE=0x0, WORD=0x2, CRC1=0x3, CRC2=0x4, END=0x5. Bits[26:24] RO Reset=0x0 */
        using DATA_STALL = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< MS/MMC: FIFO transfer not ready. Bits[27] RO Reset=0x0 */
        using DATACRC_ERR = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 4, std::uint32_t>; /**< Data CRC error count. Bits[31:28] RO Reset=0x0 */
    } // namespace DEBUG

    /** @brief SSP Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80010110, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< RTL version stepping field. Bits[15:0] RO Reset=0x0000 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< RTL version MINOR field. Bits[23:16] RO Reset=0x00 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< RTL version MAJOR field. Bits[31:24] RO Reset=0x02 */
    } // namespace VERSION

} // namespace Hardware::Registers::SSP1

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_SSP1
