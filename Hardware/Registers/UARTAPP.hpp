#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_UARTAPP
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_UARTAPP

/**
 * @file UARTAPP.hpp
 * @brief UARTAPP 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 应用 UART(高速 UART,支持 DMA 收发,区别于调试用 UARTDBG)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::UARTAPP {

    /** @brief CTRL0 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C000, 0x8006C004, 0x8006C008, 0x8006C00C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Number of bytes to receive [15:0]. Must be a multiple of 4. */
        using RXTIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 11, std::uint32_t>; /**< Receive Time-Out Counter Value [10:0]. Number of 8-bit-time to wait before asserting time-out on the RX input. 7-bit-time is added to the programmed value; default 0x3 (31-bit-time). */
        using RXTO_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< RXTIMEOUT Enable. 0 = Receive time-out will not affect receive DMA operation. 1 = Receive time-out will cause the receive DMA logic to terminate. */
        using RX_SOURCE = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Source of Receive Data. If set to 1, the status register will be the source of the DMA; otherwise RX data will be the source. */
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Tell the UART to execute the RX DMA command. The UART will clear this bit at the end of receive execution. */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Clock gate. Clear to 0 for normal operation. Setting to 1 (default) gates all block-level clocks off to minimize AC energy consumption. */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Soft reset. Clear to 0 for normal operation. When set to 1 (default), the entire block is held in its reset state. */
    } // namespace CTRL0

    /** @brief CTRL1 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C010, 0x8006C014, 0x8006C018, 0x8006C01C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Number of bytes to transmit [15:0]. */
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Tell the UART to execute the TX DMA command. The UART will clear this bit at the end of transmit execution. */
    } // namespace CTRL1

    /** @brief CTRL2 */
    namespace CTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C020, 0x8006C024, 0x8006C028, 0x8006C02C, LowLevel::Access::ReadWrite>;
        using UARTEN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< UART Enable. If set to 1, the UART is enabled. Completes current character before stopping when disabled mid-transmission or reception. */
        using SIREN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< SIR Enable. Unsupported. */
        using SIRLP = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< IrDA SIR Low Power Mode. Unsupported. */
        using USE_LCR2 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< If set to 1, the Line Control 2 Register values are used. */
        using LBE = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Loopback Enable. If set to 1, UARTTXD is fed through to UARTRXD. Modem outputs are also fed through to modem inputs. */
        using TXE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Transmit Enable. If set to 1, the transmit section of the UART is enabled. Completes current character before stopping when disabled mid-transmission. */
        using RXE = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Receive Enable. If set to 1, the receive section of the UART is enabled. Completes current character before stopping when disabled mid-reception. */
        using DTR = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Data Transmit Ready. Complement of nUARTDTR modem status output. Unsupported. */
        using RTS = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< Request To Send. Software can manually control nUARTRTS via this bit when RTSEN=0. Complement of nUARTRTS output. */
        using OUT1 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Complement of the UART Out1 (nUARTOut1) modem status output. Unsupported. */
        using OUT2 = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Complement of the UART Out2 (nUARTOut2) modem status output. Unsupported. */
        using RTSEN = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< RTS Hardware Flow Control Enable. If set to 1, RTS hardware flow control is enabled; data is only requested when there is space in the receive FIFO. */
        using CTSEN = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< CTS Hardware Flow Control Enable. If set to 1, CTS hardware flow control is enabled; data is only transmitted when nUARTCTS is asserted. */
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
        using TXIFLSEL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 3, TXIFLSEL_Values>; /**< Transmit Interrupt FIFO Level Select [2:0]. Trigger points: 0=EMPTY (no entries), 1=ONE_QUARTER (<4), 2=ONE_HALF (<8), 3=THREE_QUARTERS (<12), 4=SEVEN_EIGHTHS (<14), 5-7=Reserved. */
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
        using RXIFLSEL = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, RXIFLSEL_Values>; /**< Receive Interrupt FIFO Level Select [2:0]. Trigger points: 0=NOT_EMPTY (>=1 of 16), 1=ONE_QUARTER (>=4), 2=ONE_HALF (>=8), 3=THREE_QUARTERS (>=12), 4=SEVEN_EIGHTHS (>=14), 5-7=Reserved. */
        using RXDMAE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Receive DMA Enable. Data Register can contain up to 4 bytes per read. RXFIFO must be enabled in RXDMA mode. */
        using TXDMAE = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Transmit DMA Enable. Data Register can be loaded with up to 4 bytes per write. TXFIFO must be enabled in TXDMA mode. */
        using DMAONERR = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< DMA On Error. If set to 1, receive DMA will terminate on error (cmd_end signal may not be asserted when this occurs). */
        using RTS_SEMAPHORE = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< If set to 1, RTS is deasserted when the semaphore threshold is less than 2. */
        using INVERT_RX = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Invert RX signal. If set to 1, the RX input is inverted before sampled. */
        using INVERT_TX = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Invert TX signal. If set to 1, the TX output is inverted before transmitted. */
        using INVERT_CTS = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Invert CTS signal. If set to 1, the CTS input is inverted before sampled. */
        using INVERT_RTS = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Invert RTS signal. If set to 1, the RTS output is inverted before transmitted. */
    } // namespace CTRL2

    /** @brief LINECTRL */
    namespace LINECTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C030, 0x8006C034, 0x8006C038, 0x8006C03C, LowLevel::Access::ReadWrite>;
        using BRK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Send Break. If set to 1, a low-level is continually output on UARTTXD after completing current character. Must be set for at least two complete frames. Normal use: cleared to 0. */
        using PEN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Parity Enable. 1 = parity checking and generation enabled. 0 = parity disabled, no parity bit added. */
        using EPS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Even Parity Select. 1 = even parity generation and checking. 0 = odd parity. No effect when PEN=0. */
        using STP2 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Two Stop Bits Select. If set to 1, two stop bits are transmitted at end of frame. Receive logic does not check for two stop bits. */
        using FEN = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Enable FIFOs. 1 = FIFO mode enabled. 0 = FIFOs disabled (character mode, 1-byte-deep holding registers). */
        using WLEN = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 2, std::uint32_t>; /**< Word Length [1:0]. 11=8 bits, 10=7 bits, 01=6 bits, 00=5 bits. */
        using SPS = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Stick Parity Select. When bits 1,2,7 are set, parity is transmitted/checked as 0. When bits 1 and 7 set, bit 2 clear, parity is transmitted/checked as 1. Cleared = stick parity disabled. */
        using BAUD_DIVFRAC = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 6, std::uint32_t>; /**< Baud Rate Fraction [5:0]. The fractional baud rate divisor. */
        using BAUD_DIVINT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Baud Rate Integer [15:0]. The integer baud rate divisor. */
    } // namespace LINECTRL

    /** @brief LINECTRL2 */
    namespace LINECTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C040, 0x8006C044, 0x8006C048, 0x8006C04C, LowLevel::Access::ReadWrite>;
        using PEN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Parity Enable. 1 = parity checking/generation enabled. 0 = disabled. */
        using EPS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Even Parity Select. 1 = even parity. 0 = odd parity. No effect when PEN=0. */
        using STP2 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Two Stop Bits Select. Same behavior as HW_UARTAPP_LINECTRL.STP2. */
        using FEN = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Enable FIFOs. 1 = FIFO mode enabled. 0 = FIFOs disabled (character mode). */
        using WLEN = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 2, std::uint32_t>; /**< Word Length [1:0]. 00=5 bits, 01=6 bits, 10=7 bits, 11=8 bits. */
        using SPS = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Stick Parity Select. Same behavior as HW_UARTAPP_LINECTRL.SPS. */
        using BAUD_DIVFRAC = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 6, std::uint32_t>; /**< Baud Rate Fraction [5:0]. The fractional baud rate divisor. */
        using BAUD_DIVINT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Baud Rate Integer [15:0]. The integer baud rate divisor. */
    } // namespace LINECTRL2

    /** @brief INTR */
    namespace INTR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C050, 0x8006C054, 0x8006C058, 0x8006C05C, LowLevel::Access::ReadWrite>;
        using RIMIS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< nUARTRI Modem Interrupt Status. Unsupported. */
        using CTSMIS = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< nUARTCTS Modem Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using DCDMIS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< nUARTDCD Modem Interrupt Status. Unsupported. */
        using DSRMIS = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< nUARTDSR Modem Interrupt Status. Unsupported. */
        using RXIS = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Receive Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using TXIS = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Transmit Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using RTIS = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Receive Time-Out Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using FEIS = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Framing Error Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using PEIS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Parity Error Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using BEIS = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Break Error Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using OEIS = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Overrun Error Interrupt Status. Clear by writing bit-clear address with bit set to 1. */
        using RIMIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< nUARTRI Modem Interrupt Enable. Unsupported. */
        using CTSMIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< nUARTCTS Modem Interrupt Enable. */
        using DCDMIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< nUARTDCD Modem Interrupt Enable. Unsupported. */
        using DSRMIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< nUARTDSR Modem Interrupt Enable. Unsupported. */
        using RXIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< Receive Interrupt Enable. */
        using TXIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< Transmit Interrupt Enable. */
        using RTIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Receive Time-Out Interrupt Enable. */
        using FEIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< Framing Error Interrupt Enable. */
        using PEIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Parity Error Interrupt Enable. */
        using BEIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Break Error Interrupt Enable. */
        using OEIEN = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Overrun Error Interrupt Enable. */
    } // namespace INTR

    /** @brief DATA */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C060, 0x8006C064, 0x8006C068, 0x8006C06C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Receive/Transmit data [31:0]. In DMA mode, up to 4 characters accessed at a time. In PIO mode, only one character at a time. */
    } // namespace DATA

    /** @brief STAT */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C070, 0x8006C074, 0x8006C078, 0x8006C07C, LowLevel::Access::ReadWrite>;
        using RXCOUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Number of bytes received during a receive DMA command [15:0]. */
        using FERR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Framing Error. For PIO mode: last character read. For DMA mode: set if any received character had a Framing Error. Clear by writing 0. */
        using PERR = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< Parity Error. For PIO mode: last character read. For DMA mode: set if any received character had a Parity Error. Clear by writing 0. */
        using BERR = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Break Error. For PIO mode: last character read from data register. For DMA mode: set if any received character had a Break Error. Clear by writing 0. */
        using OERR = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< Overrun Error. Set if data received and FIFO already full. Cleared by any write to the Status Register. */
        using RXBYTE_INVALID = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 4, std::uint32_t>; /**< Invalid state of last read of Receive Data [3:0]. Each bit corresponds to one byte of RX data. 1=invalid. */
        using RXFE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Receive FIFO Empty. */
        using TXFF = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Transmit FIFO Full. */
        using RXFF = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Receive FIFO Full. */
        using TXFE = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Transmit FIFO Empty. With FIFO disabled: set when transmit holding register is empty. With FIFO enabled: set when transmit FIFO is empty. */
        using CTS = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Clear To Send. */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< UART Busy. */
        /** @brief HISPEED 的取值。 */
        enum class HISPEED_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using HISPEED = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, HISPEED_Values>; /**< Indicates high-speed function is present when reads back 1. 0=HISPEED not present, 1=HISPEED present. */
        /** @brief PRESENT 的取值。 */
        enum class PRESENT_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, PRESENT_Values>; /**< Indicates UARTAPP is present when reads back 1. 0=UARTAPP not present, 1=UARTAPP present. */
    } // namespace STAT

    /** @brief DEBUG */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8006C080, LowLevel::Access::ReadOnly>;
        using RXDMARQ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< DMA Request Status. Reflects state of toggle signal for UART_RXDMAREQ. RX burst request not supported. */
        using TXDMARQ = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< DMA Request Status. Reflects state of toggle signal for UART_TXDMAREQ. TX burst request not supported. */
        using RXCMDEND = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< DMA Command End Status. Reflects state of toggle signal for UART_RXCMDEND. */
        using TXCMDEND = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< DMA Command End Status. Reflects state of toggle signal for UART_TXCMDEND. */
        using RXDMARUN = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< DMA Command Run Status. Reflects state of toggle signal for RXDMARUN. */
        using TXDMARUN = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< DMA Command Run Status. Reflects state of toggle signal for TXDMARUN. */
        using RXFBAUD_DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 6, std::uint32_t>; /**< 接收波特率分频整数部分（调试用）。 */
        using RXIBAUD_DIV = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 接收波特率分频小数部分（调试用）。 */
    } // namespace DEBUG

    /** @brief VERSION */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8006C090, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Fixed read-only value reflecting the stepping of RTL version [15:0]. */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Fixed read-only value reflecting the MINOR field of RTL version [7:0]. */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Fixed read-only value reflecting the MAJOR field of RTL version [7:0]. */
    } // namespace VERSION

    /** @brief AUTOBAUD */
    namespace AUTOBAUD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8006C0A0, 0x8006C0A4, 0x8006C0A8, 0x8006C0AC, LowLevel::Access::ReadWrite>;
        using BAUD_DETECT_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 波特率检测使能，置位时UART自动检测接收数据的波特率。 */
        using START_BAUD_DETECT = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 启动波特率检测，写1开始自动波特率测量。 */
        using START_WITH_RUNBIT = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 检测到RUN位时启动波特率检测。 */
        using TWO_REF_CHARS = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 使用两个参考字符进行波特率检测。 */
        using UPDATE_TX = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 将检测到的波特率同时更新到发送通道。 */
        using REFCHAR0 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 波特率检测参考字符0，用于测量接收波特率。 */
        using REFCHAR1 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 波特率检测参考字符1，用于双字符模式。 */
    } // namespace AUTOBAUD

} // namespace Hardware::Registers::UARTAPP

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_UARTAPP
