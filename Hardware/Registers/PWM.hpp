#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_PWM
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_PWM

/**
 * @file PWM.hpp
 * @brief PWM 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 脉宽调制控制器(多通道 PWM 输出,可用于背光/蜂鸣等)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::PWM {

    /** @brief PWM Control and Status Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064000, 0x80064004, 0x80064008, 0x8006400C, LowLevel::Access::ReadWrite>;
        using PWM0_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Bit 0. Enables PWM channel 0 to begin cycling when set to 1. */
        using PWM1_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Bit 1. Enables PWM channel 1 to begin cycling when set to 1. */
        using PWM2_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bit 2. Enables PWM channel 2 to begin cycling when set to 1. */
        using PWM3_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Bit 3. Enables PWM channel 3 to begin cycling when set to 1. */
        using PWM4_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Bit 4. Enables PWM channel 4 to begin cycling when set to 1. */
        using PWM2_ANA_CTRL_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Bit 5. Setting to 1 enables PWM Channel 2 output to be enabled by analog circuitry outside this block. */
        using OUTPUT_CUTOFF_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 输出截止使能，超出有效周期后强制输出无效态。 */
        using PWM0_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Bit 25. Read-only. 0 = PWM0 is not present in this product. */
        using PWM1_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bit 26. Read-only. 0 = PWM1 is not present in this product. */
        using PWM2_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Bit 27. Read-only. 0 = PWM2 is not present in this product. */
        using PWM3_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Bit 28. Read-only. 0 = PWM3 is not present in this product. */
        using PWM4_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Bit 29. Read-only. 0 = PWM4 is not present in this product. */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bit 30. Must be cleared to 0 for normal operation. When set to 1, gates off the clocks to the block. */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Bit 31. Must be cleared to 0 for normal operation. When set to 1, forces a block-wide reset. */
    } // namespace CTRL

    /** @brief ACTIVE */
    namespace ACTIVE0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064010, 0x80064014, 0x80064018, 0x8006401C, LowLevel::Access::ReadWrite>;
        using ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道有效周期计数值（以分频后晶振周期为单位）。 */
        using INACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< PWM通道无效周期计数值（以分频后晶振周期为单位）。 */
    } // namespace ACTIVE0

    /** @brief PERIOD */
    namespace PERIOD0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064020, 0x80064024, 0x80064028, 0x8006402C, LowLevel::Access::ReadWrite>;
        using PERIOD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道周期计数值（周期 = PERIOD+1 个分频时钟）。 */
        /** @brief ACTIVE_STATE 的取值。 */
        enum class ACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using ACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, ACTIVE_STATE_Values>; /**< 有效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief INACTIVE_STATE 的取值。 */
        enum class INACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using INACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, INACTIVE_STATE_Values>; /**< 无效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief CDIV 的取值。 */
        enum class CDIV_Values : std::uint32_t {
            DIV_1 = 0x0,
            DIV_2 = 0x1,
            DIV_4 = 0x2,
            DIV_8 = 0x3,
            DIV_16 = 0x4,
            DIV_64 = 0x5,
            DIV_256 = 0x6,
            DIV_1024 = 0x7,
        };
        using CDIV = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, CDIV_Values>; /**< 时钟分频比选择：1/2/4/8/16/64/256/1024。 */
        using MATT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 多芯片连接模式，将24MHz晶振时钟输出到PWM引脚。 */
        using MATT_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 多芯片连接模式选择。 */
    } // namespace PERIOD0

    /** @brief ACTIVE */
    namespace ACTIVE1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064030, 0x80064034, 0x80064038, 0x8006403C, LowLevel::Access::ReadWrite>;
        using ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道有效周期计数值（以分频后晶振周期为单位）。 */
        using INACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< PWM通道无效周期计数值（以分频后晶振周期为单位）。 */
    } // namespace ACTIVE1

    /** @brief PERIOD */
    namespace PERIOD1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064040, 0x80064044, 0x80064048, 0x8006404C, LowLevel::Access::ReadWrite>;
        using PERIOD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道周期计数值（周期 = PERIOD+1 个分频时钟）。 */
        /** @brief ACTIVE_STATE 的取值。 */
        enum class ACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using ACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, ACTIVE_STATE_Values>; /**< 有效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief INACTIVE_STATE 的取值。 */
        enum class INACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using INACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, INACTIVE_STATE_Values>; /**< 无效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief CDIV 的取值。 */
        enum class CDIV_Values : std::uint32_t {
            DIV_1 = 0x0,
            DIV_2 = 0x1,
            DIV_4 = 0x2,
            DIV_8 = 0x3,
            DIV_16 = 0x4,
            DIV_64 = 0x5,
            DIV_256 = 0x6,
            DIV_1024 = 0x7,
        };
        using CDIV = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, CDIV_Values>; /**< 时钟分频比选择：1/2/4/8/16/64/256/1024。 */
        using MATT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 多芯片连接模式，将24MHz晶振时钟输出到PWM引脚。 */
        using MATT_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 多芯片连接模式选择。 */
    } // namespace PERIOD1

    /** @brief ACTIVE */
    namespace ACTIVE2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064050, 0x80064054, 0x80064058, 0x8006405C, LowLevel::Access::ReadWrite>;
        using ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道有效周期计数值（以分频后晶振周期为单位）。 */
        using INACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< PWM通道无效周期计数值（以分频后晶振周期为单位）。 */
    } // namespace ACTIVE2

    /** @brief PERIOD */
    namespace PERIOD2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064060, 0x80064064, 0x80064068, 0x8006406C, LowLevel::Access::ReadWrite>;
        using PERIOD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道周期计数值（周期 = PERIOD+1 个分频时钟）。 */
        /** @brief ACTIVE_STATE 的取值。 */
        enum class ACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using ACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, ACTIVE_STATE_Values>; /**< 有效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief INACTIVE_STATE 的取值。 */
        enum class INACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using INACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, INACTIVE_STATE_Values>; /**< 无效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief CDIV 的取值。 */
        enum class CDIV_Values : std::uint32_t {
            DIV_1 = 0x0,
            DIV_2 = 0x1,
            DIV_4 = 0x2,
            DIV_8 = 0x3,
            DIV_16 = 0x4,
            DIV_64 = 0x5,
            DIV_256 = 0x6,
            DIV_1024 = 0x7,
        };
        using CDIV = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, CDIV_Values>; /**< 时钟分频比选择：1/2/4/8/16/64/256/1024。 */
        using MATT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 多芯片连接模式，将24MHz晶振时钟输出到PWM引脚。 */
        using MATT_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 多芯片连接模式选择。 */
    } // namespace PERIOD2

    /** @brief ACTIVE */
    namespace ACTIVE3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064070, 0x80064074, 0x80064078, 0x8006407C, LowLevel::Access::ReadWrite>;
        using ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道有效周期计数值（以分频后晶振周期为单位）。 */
        using INACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< PWM通道无效周期计数值（以分频后晶振周期为单位）。 */
    } // namespace ACTIVE3

    /** @brief PERIOD */
    namespace PERIOD3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064080, 0x80064084, 0x80064088, 0x8006408C, LowLevel::Access::ReadWrite>;
        using PERIOD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道周期计数值（周期 = PERIOD+1 个分频时钟）。 */
        /** @brief ACTIVE_STATE 的取值。 */
        enum class ACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using ACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, ACTIVE_STATE_Values>; /**< 有效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief INACTIVE_STATE 的取值。 */
        enum class INACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using INACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, INACTIVE_STATE_Values>; /**< 无效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief CDIV 的取值。 */
        enum class CDIV_Values : std::uint32_t {
            DIV_1 = 0x0,
            DIV_2 = 0x1,
            DIV_4 = 0x2,
            DIV_8 = 0x3,
            DIV_16 = 0x4,
            DIV_64 = 0x5,
            DIV_256 = 0x6,
            DIV_1024 = 0x7,
        };
        using CDIV = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, CDIV_Values>; /**< 时钟分频比选择：1/2/4/8/16/64/256/1024。 */
        using MATT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 多芯片连接模式，将24MHz晶振时钟输出到PWM引脚。 */
        using MATT_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 多芯片连接模式选择。 */
    } // namespace PERIOD3

    /** @brief ACTIVE */
    namespace ACTIVE4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80064090, 0x80064094, 0x80064098, 0x8006409C, LowLevel::Access::ReadWrite>;
        using ACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道有效周期计数值（以分频后晶振周期为单位）。 */
        using INACTIVE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< PWM通道无效周期计数值（以分频后晶振周期为单位）。 */
    } // namespace ACTIVE4

    /** @brief PERIOD */
    namespace PERIOD4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800640A0, 0x800640A4, 0x800640A8, 0x800640AC, LowLevel::Access::ReadWrite>;
        using PERIOD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< PWM通道周期计数值（周期 = PERIOD+1 个分频时钟）。 */
        /** @brief ACTIVE_STATE 的取值。 */
        enum class ACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using ACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, ACTIVE_STATE_Values>; /**< 有效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief INACTIVE_STATE 的取值。 */
        enum class INACTIVE_STATE_Values : std::uint32_t {
            HI_Z = 0x0,
            _0 = 0x2,
            _1 = 0x3,
        };
        using INACTIVE_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, INACTIVE_STATE_Values>; /**< 无效状态电平选择：0=高阻，2=低电平，3=高电平。 */
        /** @brief CDIV 的取值。 */
        enum class CDIV_Values : std::uint32_t {
            DIV_1 = 0x0,
            DIV_2 = 0x1,
            DIV_4 = 0x2,
            DIV_8 = 0x3,
            DIV_16 = 0x4,
            DIV_64 = 0x5,
            DIV_256 = 0x6,
            DIV_1024 = 0x7,
        };
        using CDIV = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, CDIV_Values>; /**< 时钟分频比选择：1/2/4/8/16/64/256/1024。 */
        using MATT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 多芯片连接模式，将24MHz晶振时钟输出到PWM引脚。 */
        using MATT_SEL = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 多芯片连接模式选择。 */
    } // namespace PERIOD4

    /** @brief PWM Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800640B0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Bits 15:0. Read-only. Fixed value reflecting the stepping of the RTL version. Reset: 0x0000. */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Bits 23:16. Read-only. Fixed value reflecting the MINOR field of the RTL version. Reset: 0x01. */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Bits 31:24. Read-only. Fixed value reflecting the MAJOR field of the RTL version. Reset: 0x01. */
    } // namespace VERSION

} // namespace Hardware::Registers::PWM

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_PWM
