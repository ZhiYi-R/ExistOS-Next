#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_ECC8
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_ECC8

/**
 * @file ECC8.hpp
 * @brief ECC8 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * NAND ECC8/BCH 硬件纠错加速器(配合 GPMI 对 NAND 数据做 ECC 编解码)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::ECC8 {

    /** @brief Hardware ECC Accelerator Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008000, 0x80008004, 0x80008008, 0x8000800C, LowLevel::Access::ReadWrite>;
        using COMPLETE_IRQ = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Complete IRQ. RW, Reset=0x0. External Interrupt Line Status. Write 1 to SCT clear address to clear. ECC completions held off while set. Read STATUS0/1 before clearing. */
        using DEBUG_WRITE_IRQ = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< Debug Write IRQ. RW, Reset=0x0. Debug Write Interrupt Status. Write 1 to SCT clear address to clear. */
        using DEBUG_STALL_IRQ = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Debug Stall IRQ. RW, Reset=0x0. Debug Stall Interrupt Status. Write 1 to SCT clear address to clear. */
        using BM_ERROR_IRQ = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Bus Master Error IRQ. RW, Reset=0x0. AHB Bus Interface Error Interrupt Status. Write 1 to SCT clear address to clear. */
        using COMPLETE_IRQ_EN = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Complete Interrupt Enable. RW, Reset=0x0. 1=Interrupt on completion of correction is enabled. */
        using DEBUG_WRITE_IRQ_EN = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Debug Write Interrupt Enable. RW, Reset=0x0. 1=IRQ on debug write mode enabled, raised on every transfer. No correction in this mode. */
        using DEBUG_STALL_IRQ_EN = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< Debug Stall Interrupt Enable. RW, Reset=0x0. 1=IRQ on debug stall mode enabled, raised on every block. */
        using THROTTLE = LowLevel::Field<Reg, 24, 4, std::uint32_t>; /**< AHB Throttle. RW, Reset=0x0. Non-zero values hold off that number of HCLKs between successive burst requests on AHB. */
        /** @brief AHBM_SFTRST 的取值。 */
        enum class AHBM_SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            RESET = 0x1,
        };
        using AHBM_SFTRST = LowLevel::Field<Reg, 29, 1, AHBM_SFTRST_Values>; /**< AHB Master Soft Reset. RW, Reset=0x1. Resets the AHB state machine. 0=Normal, 1=Reset. Not for normal device soft-resets. */
        /** @brief CLKGATE 的取值。 */
        enum class CLKGATE_Values : std::uint32_t {
            RUN = 0x0,
            NO_CLKS = 0x1,
        };
        using CLKGATE = LowLevel::Field<Reg, 30, 1, CLKGATE_Values>; /**< Clock Gate. RW, Reset=0x1. Must be 0 for normal operation. When 1, gates off clocks to minimize power consumption. */
        /** @brief SFTRST 的取值。 */
        enum class SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            RESET = 0x1,
        };
        using SFTRST = LowLevel::Field<Reg, 31, 1, SFTRST_Values>; /**< Soft Reset. RW, Reset=0x1. 0=Normal ECC8 operation. 1=Hold ECC8 in reset (lowest power) state. Resets all state machines except AHB master. */
    } // namespace CTRL

    /** @brief Hardware ECC Accelerator Status Register 0 */
    namespace STATUS0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008010, 0x80008014, 0x80008018, 0x8000801C, LowLevel::Access::ReadWrite>;
        using COMPLETED_CE = LowLevel::Field<Reg, 0, 2, std::uint32_t>; /**< Completed Chip Enable. RO, Reset=0x0. Chip enable number (0-3) for the NAND device the data came from. */
        using UNCORRECTABLE = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Uncorrectable Flag. RO, Reset=0x0. 1=Uncorrectable error during last processing cycle. */
        using CORRECTED = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Corrected Flag. RO, Reset=0x0. 1=At least one correctable error during last processing cycle. */
        using ALLONES = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< All Ones Flag. RO, Reset=0x1. 1=All data bits of this transaction are 1. */
        /** @brief STATUS_AUX 的取值。 */
        enum class STATUS_AUX_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_AUX = LowLevel::Field<Reg, 8, 4, STATUS_AUX_Values>; /**< Auxiliary Data Status. RO, Reset=0xC (NOT_CHECKED). Symbol error count for auxiliary area. 0xF=uncorrectable. Values: 0-4=error count, 0xC=not checked, 0xE=uncorrectable, 0xF=all ones. */
        using RS4ECC_DEC_PRESENT = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< RS(4) ECC Decode Present. RO, Reset=0x1. Reserved. */
        using RS4ECC_ENC_PRESENT = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< RS(4) ECC Encode Present. RO, Reset=0x1. Reserved. */
        using RS8ECC_DEC_PRESENT = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< RS(8) ECC Decode Present. RO, Reset=0x1. Reserved. */
        using RS8ECC_ENC_PRESENT = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< RS(8) ECC Encode Present. RO, Reset=0x1. Reserved. */
        using HANDLE = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< Transfer Handle. RO, Reset=0x0. 16-bit handle from GPMI DMA PIO operation. Passes through pipeline and is present when ECC8 interrupt signals. */
    } // namespace STATUS0

    /** @brief Hardware ECC Accelerator Status Register 1 */
    namespace STATUS1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008020, 0x80008024, 0x80008028, 0x8000802C, LowLevel::Access::ReadWrite>;
        /** @brief STATUS_PAYLOAD0 的取值。 */
        enum class STATUS_PAYLOAD0_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD0 = LowLevel::Field<Reg, 0, 4, STATUS_PAYLOAD0_Values>; /**< Payload Area 0 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD1 的取值。 */
        enum class STATUS_PAYLOAD1_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD1 = LowLevel::Field<Reg, 4, 4, STATUS_PAYLOAD1_Values>; /**< Payload Area 1 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD2 的取值。 */
        enum class STATUS_PAYLOAD2_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD2 = LowLevel::Field<Reg, 8, 4, STATUS_PAYLOAD2_Values>; /**< Payload Area 2 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD3 的取值。 */
        enum class STATUS_PAYLOAD3_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD3 = LowLevel::Field<Reg, 12, 4, STATUS_PAYLOAD3_Values>; /**< Payload Area 3 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD4 的取值。 */
        enum class STATUS_PAYLOAD4_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD4 = LowLevel::Field<Reg, 16, 4, STATUS_PAYLOAD4_Values>; /**< Payload Area 4 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD5 的取值。 */
        enum class STATUS_PAYLOAD5_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD5 = LowLevel::Field<Reg, 20, 4, STATUS_PAYLOAD5_Values>; /**< Payload Area 5 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD6 的取值。 */
        enum class STATUS_PAYLOAD6_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD6 = LowLevel::Field<Reg, 24, 4, STATUS_PAYLOAD6_Values>; /**< Payload Area 6 Status. RO, Reset=0xC. Same encoding as STATUS_PAYLOAD7. */
        /** @brief STATUS_PAYLOAD7 的取值。 */
        enum class STATUS_PAYLOAD7_Values : std::uint32_t {
            NO_ERRORS = 0x0,
            ONE_CORRECTABLE = 0x1,
            TWO_CORRECTABLE = 0x2,
            THREE_CORRECTABLE = 0x3,
            FOUR_CORRECTABLE = 0x4,
            FIVE_CORRECTABLE = 0x5,
            SIX_CORRECTABLE = 0x6,
            SEVEN_CORRECTABLE = 0x7,
            EIGHT_CORRECTABLE = 0x8,
            NOT_CHECKED = 0xC,
            UNCORRECTABLE = 0xE,
            ALL_ONES = 0xF,
        };
        using STATUS_PAYLOAD7 = LowLevel::Field<Reg, 28, 4, STATUS_PAYLOAD7_Values>; /**< Payload Area 7 Status. RO, Reset=0xC. Symbol error count for payload 7. 0xF=uncorrectable. Values: 0-8=error count, 0xC=not checked, 0xE=uncorrectable, 0xF=all ones. */
    } // namespace STATUS1

    /** @brief Hardware ECC Accelerator Debug Register 0 */
    namespace DEBUG0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80008030, LowLevel::Access::ReadOnly>;
        using DEBUG_REG_SELECT = LowLevel::Field<Reg, 0, 6, std::uint32_t>; /**< Debug Register Select. RW, Reset=0x0. Selects internal register state view of KES or Chien search engine. */
        /** @brief BM_KES_TEST_BYPASS 的取值。 */
        enum class BM_KES_TEST_BYPASS_Values : std::uint32_t {
            NORMAL = 0x0,
            TEST_MODE = 0x1,
        };
        using BM_KES_TEST_BYPASS = LowLevel::Field<Reg, 8, 1, BM_KES_TEST_BYPASS_Values>; /**< Bus Master KES Test Bypass. RW, Reset=0x0. 1=Point synd_gen writes to dummy area for diagnostic preload of payload, parity, syndrome bytes. */
        /** @brief KES_DEBUG_STALL 的取值。 */
        enum class KES_DEBUG_STALL_Values : std::uint32_t {
            NORMAL = 0x0,
            WAIT = 0x1,
        };
        using KES_DEBUG_STALL = LowLevel::Field<Reg, 9, 1, KES_DEBUG_STALL_Values>; /**< KES Debug Stall. RW, Reset=0x0. Stall KES FSM after notifying Chien search but before notifying bus master. 0=proceed, 1=wait. */
        using KES_DEBUG_STEP = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< KES Debug Step. RW, Reset=0x0. Toggling skips KES FSM past stall state when in DEBUG_STALL mode and block done. */
        /** @brief KES_STANDALONE 的取值。 */
        enum class KES_STANDALONE_Values : std::uint32_t {
            NORMAL = 0x0,
            TEST_MODE = 0x1,
        };
        using KES_STANDALONE = LowLevel::Field<Reg, 11, 1, KES_STANDALONE_Values>; /**< KES Standalone Mode. RW, Reset=0x0. Set to 1 to suppress KES_BM_DONE and CF_BM_DONE signal toggling to bus master. */
        using KES_DEBUG_KICK = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< KES Debug Kick. RW, Reset=0x0. Toggling starts KES engine FSM as if kicked by bus master for standalone testing. */
        /** @brief KES_DEBUG_MODE4K 的取值。 */
        enum class KES_DEBUG_MODE4K_Values : std::uint32_t {
            _4k = 0x1,
        };
        using KES_DEBUG_MODE4K = LowLevel::Field<Reg, 13, 1, KES_DEBUG_MODE4K_Values>; /**< KES Debug 4K Mode. RW, Reset=0x0. Presented to KES as input mode. 4k(1)=4K NAND pages. 2k(1)=2K NAND pages. */
        /** @brief KES_DEBUG_PAYLOAD_FLAG 的取值。 */
        enum class KES_DEBUG_PAYLOAD_FLAG_Values : std::uint32_t {
            DATA = 0x1,
        };
        using KES_DEBUG_PAYLOAD_FLAG = LowLevel::Field<Reg, 14, 1, KES_DEBUG_PAYLOAD_FLAG_Values>; /**< KES Debug Payload Flag. RW, Reset=0x0. Presented to KES as input payload flag. DATA(1)=512B block. AUX(1)=65/19B auxiliary block. */
        using KES_DEBUG_SHIFT_SYND = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< KES Debug Shift Syndrome. RW, Reset=0x0. Toggling shifts KES_SYNDROME_SYMBOL into syndrome array. After 16 symbols, kick KES/CF by toggling KES_DEBUG_KICK. */
        /** @brief KES_DEBUG_SYNDROME_SYMBOL 的取值。 */
        enum class KES_DEBUG_SYNDROME_SYMBOL_Values : std::uint32_t {
            NORMAL = 0x0,
            TEST_MODE = 0x1,
        };
        using KES_DEBUG_SYNDROME_SYMBOL = LowLevel::Field<Reg, 16, 9, KES_DEBUG_SYNDROME_SYMBOL_Values>; /**< KES Debug Syndrome Symbol. RW, Reset=0x0. 9-bit value shifted into syndrome register array at KES input when KES_DEBUG_SHIFT_SYND toggles. */
    } // namespace DEBUG0

    /** @brief KES Debug Read Register */
    namespace DBGKESREAD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008040, 0x80008044, 0x80008048, 0x8000804C, LowLevel::Access::ReadWrite>;
        using VALUES = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Debug KES Read Values. RO, Reset=0x0. Reserved. */
    } // namespace DBGKESREAD

    /** @brief Chien Search Forney Evaluator Debug Read Register */
    namespace DBGCSFEREAD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008050, 0x80008054, 0x80008058, 0x8000805C, LowLevel::Access::ReadWrite>;
        using VALUES = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Debug CSFE Read Values. RO, Reset=0x0. Reserved. */
    } // namespace DBGCSFEREAD

    /** @brief Syndrome Generator Debug Read Register */
    namespace DBGSYNDGENREAD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008060, 0x80008064, 0x80008068, 0x8000806C, LowLevel::Access::ReadWrite>;
        using VALUES = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Debug Syndrome Generator Read Values. RO, Reset=0x0. Reserved. */
    } // namespace DBGSYNDGENREAD

    /** @brief AHB Master and ECC8 Controller Debug Read Register */
    namespace DBGAHBMREAD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008070, 0x80008074, 0x80008078, 0x8000807C, LowLevel::Access::ReadWrite>;
        using VALUES = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Debug AHB Master Read Values. RO, Reset=0x0. Reserved. */
    } // namespace DBGAHBMREAD

    /** @brief ECC8 Block Name Register */
    namespace BLOCKNAME {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80008080, 0x80008084, 0x80008088, 0x8000808C, LowLevel::Access::ReadWrite>;
        using NAME = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Block Name. RO, Reset=0x38434345. ASCII '8','C','C','E' (ECC8). Readable as zero-terminated ASCII string. */
    } // namespace BLOCKNAME

    /** @brief ECC8 Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800080A0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< Version Step. RO, Reset=0x0000. Fixed read-only stepping field of the RTL version. */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Version Minor. RO, Reset=0x00. Fixed read-only MINOR field of the RTL version. */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Version Major. RO, Reset=0x01. Fixed read-only MAJOR field of the RTL version. */
    } // namespace VERSION

} // namespace Hardware::Registers::ECC8

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_ECC8
