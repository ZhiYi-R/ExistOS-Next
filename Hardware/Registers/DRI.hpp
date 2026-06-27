#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_DRI
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_DRI

/**
 * @file DRI.hpp
 * @brief DRI 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 数字无线电接口(DRI,串行调试/数据接口)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::DRI {

    /** @brief DRI Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80074000, 0x80074004, 0x80074008, 0x8007400C, LowLevel::Access::ReadWrite>;
        /** @brief RUN 的取值。 */
        enum class RUN_Values : std::uint32_t {
            HALT = 0x0,
            RUN = 0x1,
        };
        using RUN = LowLevel::Field<Reg, 0, 1, RUN_Values>; /**< Enable DRI controller operation. Auto-set by DMA commands; can be set by SW for soft DMA. 0=HALT, 1=RUN. Default 0x0. */
        /** @brief ATTENTION_IRQ 的取值。 */
        enum class ATTENTION_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using ATTENTION_IRQ = LowLevel::Field<Reg, 1, 1, ATTENTION_IRQ_Values>; /**< Attention interrupt pending. Attention bit detected in DRI frame. Write 1 to SET/CLR to clear. 0=NO_REQUEST, 1=REQUEST. Default 0x0. */
        /** @brief PILOT_SYNC_LOSS_IRQ 的取值。 */
        enum class PILOT_SYNC_LOSS_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using PILOT_SYNC_LOSS_IRQ = LowLevel::Field<Reg, 2, 1, PILOT_SYNC_LOSS_IRQ_Values>; /**< Pilot sync loss interrupt pending. Pilot peak not seen at expected 8-sample boundary. Write 1 to SET/CLR to clear. 0=NO_REQUEST, 1=REQUEST. Default 0x0. */
        /** @brief OVERFLOW_IRQ 的取值。 */
        enum class OVERFLOW_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using OVERFLOW_IRQ = LowLevel::Field<Reg, 3, 1, OVERFLOW_IRQ_Values>; /**< Overflow interrupt pending. DMA FIFO overrun detected. Write 1 to SET/CLR address to clear. 0=NO_REQUEST, 1=REQUEST. Default 0x0. */
        /** @brief ATTENTION_IRQ_EN 的取值。 */
        enum class ATTENTION_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using ATTENTION_IRQ_EN = LowLevel::Field<Reg, 9, 1, ATTENTION_IRQ_EN_Values>; /**< Attention interrupt enable. 0=DISABLED, 1=ENABLED. Default 0x0. */
        /** @brief PILOT_SYNC_LOSS_IRQ_EN 的取值。 */
        enum class PILOT_SYNC_LOSS_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using PILOT_SYNC_LOSS_IRQ_EN = LowLevel::Field<Reg, 10, 1, PILOT_SYNC_LOSS_IRQ_EN_Values>; /**< Pilot sync loss interrupt enable. 0=DISABLED, 1=ENABLED. Default 0x0. */
        /** @brief OVERFLOW_IRQ_EN 的取值。 */
        enum class OVERFLOW_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using OVERFLOW_IRQ_EN = LowLevel::Field<Reg, 11, 1, OVERFLOW_IRQ_EN_Values>; /**< Overflow interrupt enable. 0=DISABLED, 1=ENABLED. Default 0x0. */
        /** @brief REACQUIRE_PHASE 的取值。 */
        enum class REACQUIRE_PHASE_Values : std::uint32_t {
            NORMAL = 0x0,
            NEW_PHASE = 0x1,
        };
        using REACQUIRE_PHASE = LowLevel::Field<Reg, 15, 1, REACQUIRE_PHASE_Values>; /**< Reacquire phase alignment with pilot peak marker. HW clears when next pilot peak received. 0=NORMAL, 1=NEW_PHASE. Default 0x0. */
        using DMA_DELAY_COUNT = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< Spare bits (formerly encoded DMA request idle cycle count). Default 0x01. */
        /** @brief STOP_ON_PILOT_ERROR 的取值。 */
        enum class STOP_ON_PILOT_ERROR_Values : std::uint32_t {
            IGNORE = 0x0,
            STOP = 0x1,
        };
        using STOP_ON_PILOT_ERROR = LowLevel::Field<Reg, 25, 1, STOP_ON_PILOT_ERROR_Values>; /**< Stop DMA on loss of pilot sync. 0=IGNORE, 1=STOP. Default 0x0. */
        /** @brief STOP_ON_OFLOW_ERROR 的取值。 */
        enum class STOP_ON_OFLOW_ERROR_Values : std::uint32_t {
            IGNORE = 0x0,
            STOP = 0x1,
        };
        using STOP_ON_OFLOW_ERROR = LowLevel::Field<Reg, 26, 1, STOP_ON_OFLOW_ERROR_Values>; /**< Stop DMA on overflow. 0=IGNORE (keep transferring), 1=STOP. Default 0x0. */
        /** @brief ENABLE_INPUTS 的取值。 */
        enum class ENABLE_INPUTS_Values : std::uint32_t {
            ANALOG_LINE_IN = 0x0,
            DRI_DIGITAL_IN = 0x1,
        };
        using ENABLE_INPUTS = LowLevel::Field<Reg, 29, 1, ENABLE_INPUTS_Values>; /**< Enable input pads in digital mode instead of analog line-in. 0=ANALOG_LINE_IN, 1=DRI_DIGITAL_IN. Default 0x0. */
        /** @brief CLKGATE 的取值。 */
        enum class CLKGATE_Values : std::uint32_t {
            RUN = 0x0,
            NO_CLKS = 0x1,
        };
        using CLKGATE = LowLevel::Field<Reg, 30, 1, CLKGATE_Values>; /**< Clock gate. 0=RUN (normal), 1=NO_CLKS (gate clocks). Default 0x1. */
        /** @brief SFTRST 的取值。 */
        enum class SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            RESET = 0x1,
        };
        using SFTRST = LowLevel::Field<Reg, 31, 1, SFTRST_Values>; /**< Soft reset. 0=RUN (normal operation), 1=RESET (hold in reset). Default 0x1. */
    } // namespace CTRL

    /** @brief DRI Timing Register */
    namespace TIMING {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80074010, 0x80074014, 0x80074018, 0x8007401C, LowLevel::Access::ReadWrite>;
        using GAP_DETECTION_INTERVAL = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< Number of 24-MHz crystal clocks to count to detect a gap in DRI source clocks. Default 0x10. */
        using PILOT_REP_RATE = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< Number of DRI samples between pilot sample centers. Default 0x8. */
    } // namespace TIMING

    /** @brief DRI Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80074020, 0x80074024, 0x80074028, 0x8007402C, LowLevel::Access::ReadWrite>;
        /** @brief ATTENTION_IRQ_SUMMARY 的取值。 */
        enum class ATTENTION_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using ATTENTION_IRQ_SUMMARY = LowLevel::Field<Reg, 1, 1, ATTENTION_IRQ_SUMMARY_Values>; /**< Logical AND of ATTENTION_IRQ status and enable. 0=NO_REQUEST, 1=REQUEST. Default 0x0. */
        /** @brief PILOT_SYNC_LOSS_IRQ_SUMMARY 的取值。 */
        enum class PILOT_SYNC_LOSS_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using PILOT_SYNC_LOSS_IRQ_SUMMARY = LowLevel::Field<Reg, 2, 1, PILOT_SYNC_LOSS_IRQ_SUMMARY_Values>; /**< Logical AND of PILOT_SYNC_LOSS_IRQ status and enable. 0=NO_REQUEST, 1=REQUEST. Default 0x0. */
        /** @brief OVERFLOW_IRQ_SUMMARY 的取值。 */
        enum class OVERFLOW_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using OVERFLOW_IRQ_SUMMARY = LowLevel::Field<Reg, 3, 1, OVERFLOW_IRQ_SUMMARY_Values>; /**< Logical AND of OVERFLOW_IRQ status and enable. 0=NO_REQUEST, 1=REQUEST. Default 0x0. */
        using PILOT_PHASE = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< Phase of the last pilot peak marker relative to phase established when DRI exited soft reset. 0 until first phase error. Default 0x0. */
        /** @brief DRI_PRESENT 的取值。 */
        enum class DRI_PRESENT_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using DRI_PRESENT = LowLevel::Field<Reg, 31, 1, DRI_PRESENT_Values>; /**< DRI presence indicator. 0=UNAVAILABLE (DRI not present), 1=AVAILABLE (DRI present). Default 0x1. */
    } // namespace STAT

    /** @brief DRI Controller DMA Read Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80074030, 0x80074034, 0x80074038, 0x8007403C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< DMA read/write data register backed by an 8-deep FIFO. Default 0x00000000. */
    } // namespace DATA

    /** @brief DRI Device Debug Register 0 */
    namespace DEBUG0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80074040, LowLevel::Access::ReadOnly>;
        using FRAME = LowLevel::Field<Reg, 0, 18, std::uint32_t>; /**< Current state of frame synchronizing register received from digital radio receiver. Default 0x0000. */
        using SPARE = LowLevel::Field<Reg, 18, 8, std::uint32_t>; /**< Spare bits for patching hardware in metal. Default 0x00. */
        /** @brief PILOT_REP_RATE 的取值。 */
        enum class PILOT_REP_RATE_Values : std::uint32_t {
            _8_AT_4MHZ = 0x0,
            _12_AT_6MHZ = 0x1,
        };
        using PILOT_REP_RATE = LowLevel::Field<Reg, 26, 1, PILOT_REP_RATE_Values>; /**< Test mode pilot repeat rate select. 0=8_AT_4MHZ, 1=12_AT_6MHZ. Integrated test source removed; now a spare bit. Default 0x0. */
        using TEST_MODE = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< Enable internal test mode (pseudo DRI frames). Integrated test source removed; now a spare bit. Default 0x0. */
        using DRI_DATA_INPUT = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< Read-only view of DRI data input signal from analog logic. Default 0x0. */
        using DRI_CLK_INPUT = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< Read-only view of DRI clock input signal from analog logic. Default 0x0. */
        using DMACMDKICK = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< Read-only view of DMA command kick toggle state. Default 0x0. */
        using DMAREQ = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< Read-only view of DMA request line toggle state. Default 0x0. */
    } // namespace DEBUG0

    /** @brief DRI Device Debug Register 1 */
    namespace DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80074050, LowLevel::Access::ReadOnly>;
        using SWIZZLED_FRAME = LowLevel::Field<Reg, 0, 18, std::uint32_t>; /**< Current frame register as swizzled by invert/reverse bits in DEBUG1. Default 0x0000. */
        /** @brief REVERSE_FRAME 的取值。 */
        enum class REVERSE_FRAME_Values : std::uint32_t {
            NORMAL = 0x0,
            REVERSED = 0x1,
        };
        using REVERSE_FRAME = LowLevel::Field<Reg, 27, 1, REVERSE_FRAME_Values>; /**< Reverse bit order of 18-bit frames from digital radio. 0=NORMAL, 1=REVERSED. Default 0x0. */
        /** @brief INVERT_DRI_CLOCK 的取值。 */
        enum class INVERT_DRI_CLOCK_Values : std::uint32_t {
            NORMAL = 0x0,
            INVERTED = 0x1,
        };
        using INVERT_DRI_CLOCK = LowLevel::Field<Reg, 28, 1, INVERT_DRI_CLOCK_Values>; /**< Invert DRI_CLK edge used to shift data into shift register. 0=NORMAL, 1=INVERTED. Default 0x0. */
        /** @brief INVERT_DRI_DATA 的取值。 */
        enum class INVERT_DRI_DATA_Values : std::uint32_t {
            NORMAL = 0x0,
            INVERTED = 0x1,
        };
        using INVERT_DRI_DATA = LowLevel::Field<Reg, 29, 1, INVERT_DRI_DATA_Values>; /**< Invert DRI_DATA prior to shifting into shift register. 0=NORMAL, 1=INVERTED. Default 0x0. */
        /** @brief INVERT_ATTENTION 的取值。 */
        enum class INVERT_ATTENTION_Values : std::uint32_t {
            NORMAL = 0x0,
            INVERTED = 0x1,
        };
        using INVERT_ATTENTION = LowLevel::Field<Reg, 30, 1, INVERT_ATTENTION_Values>; /**< Invert frame register bit used for attention bit. 0=NORMAL, 1=INVERTED. Default 0x0. */
        /** @brief INVERT_PILOT 的取值。 */
        enum class INVERT_PILOT_Values : std::uint32_t {
            NORMAL = 0x0,
            INVERTED = 0x1,
        };
        using INVERT_PILOT = LowLevel::Field<Reg, 31, 1, INVERT_PILOT_Values>; /**< Invert frame register bit used for pilot peak indicator. 0=NORMAL, 1=INVERTED. Default 0x0. */
    } // namespace DEBUG1

    /** @brief DRI Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80074060, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< Stepping of RTL version. Fixed read-only. Default 0x0000. */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Minor field of RTL version. Fixed read-only. Default 0x01. */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Major field of RTL version. Fixed read-only. Default 0x01. */
    } // namespace VERSION

} // namespace Hardware::Registers::DRI

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_DRI
