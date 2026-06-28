#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_EMI
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_EMI

/**
 * @file EMI.hpp
 * @brief EMI 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 外部存储器接口控制器(EMI,SDRAM/mDDR 时钟与读写时序配置)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::EMI {

    /** @brief EMI Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80020000, 0x80020004, 0x80020008, 0x8002000C, LowLevel::Access::ReadWrite>;
        /** @brief CE_SELECT 的取值。 */
        enum class CE_SELECT_Values : std::uint32_t {
            NONE = 0x0,
            CE0 = 0x1,
            CE1 = 0x2,
            CE2 = 0x4,
            CE3 = 0x8,
        };
        using CE_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, CE_SELECT_Values>; /**< Ce Select，4位读写字段。 */
        using RESET_OUT = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Reset Out，1位读写字段。 */
        using WRITE_PROTECT = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Write Protect，1位读写字段。 */
        using MEM_WIDTH = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Mem Width，1位读写字段。 */
        using HIGH_PRIORITY_WRITE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< High Priority Write，3位读写字段。 */
        using PRIORITY_WRITE_ITER = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 3, std::uint32_t>; /**< Priority Write Iter，3位读写字段。 */
        /** @brief PORT_PRIORITY_ORDER 的取值。 */
        enum class PORT_PRIORITY_ORDER_Values : std::uint32_t {
            PORT0123 = 0x0,
            PORT0312 = 0x1,
            PORT0231 = 0x2,
            PORT0321 = 0x3,
            PORT0213 = 0x4,
            PORT0132 = 0x5,
            PORT1023 = 0x6,
            PORT1302 = 0x7,
            PORT1230 = 0x8,
            PORT1320 = 0x9,
            PORT1203 = 0xA,
            PORT1032 = 0xB,
            PORT2013 = 0xC,
            PORT2301 = 0xD,
            PORT2130 = 0xE,
            PORT2310 = 0xF,
            PORT2103 = 0x10,
            PORT2031 = 0x11,
            PORT3012 = 0x12,
            PORT3201 = 0x13,
            PORT3120 = 0x14,
            PORT3210 = 0x15,
            PORT3102 = 0x16,
            PORT3021 = 0x17,
        };
        using PORT_PRIORITY_ORDER = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, PORT_PRIORITY_ORDER_Values>; /**< Port Priority Order，5位读写字段。 */
        /** @brief ARB_MODE 的取值。 */
        enum class ARB_MODE_Values : std::uint32_t {
            TIMESTAMP = 0x0,
            WRITE_HYBRID = 0x1,
            PORT_PRIORITY = 0x2,
        };
        using ARB_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, ARB_MODE_Values>; /**< Arb Mode，2位读写字段。 */
        using DLL_RESET = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Dll Reset，1位读写字段。 */
        using DLL_SHIFT_RESET = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Dll Shift Reset，1位读写字段。 */
        /** @brief AXI_DEPTH 的取值。 */
        enum class AXI_DEPTH_Values : std::uint32_t {
            ONE = 0x0,
            TWO = 0x1,
            THREE = 0x2,
            FOUR = 0x3,
        };
        using AXI_DEPTH = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, AXI_DEPTH_Values>; /**< Axi Depth，2位读写字段。 */
        using TRAP_INIT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Trap Init，1位读写字段。 */
        using TRAP_SR = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Trap Sr，1位读写字段。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 时钟门控控制位，写1关闭模块时钟以节省功耗，配置状态保持。写0恢复正常时钟供应。 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 软复位控制位，写1复位本模块，写0恢复正常运行。复位后所有寄存器回到默认值。 */
    } // namespace CTRL

    /** @brief NOR Flash Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80020010, 0x80020014, 0x80020018, 0x8002001C, LowLevel::Access::ReadWrite>;
        /** @brief NOR_BUSY 的取值。 */
        enum class NOR_BUSY_Values : std::uint32_t {
            NOT_BUSY = 0x0,
            BUSY = 0x1,
        };
        using NOR_BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, NOR_BUSY_Values>; /**< Nor Busy，1位读写字段。 */
        /** @brief DRAM_HALTED 的取值。 */
        enum class DRAM_HALTED_Values : std::uint32_t {
            NOT_HALTED = 0x0,
            HALTED = 0x1,
        };
        using DRAM_HALTED = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, DRAM_HALTED_Values>; /**< Dram Halted，1位读写字段。 */
        using LARGE_DRAM_ENABLED = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Large Dram Enabled，1位读写字段。 */
        using NOR_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Nor Present，1位读写字段。 */
        using DRAM_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Dram Present，1位读写字段。 */
    } // namespace STAT

    /** @brief NOR Flash Memory Timing Control Register */
    namespace TIME {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80020020, 0x80020024, 0x80020028, 0x8002002C, LowLevel::Access::ReadWrite>;
        using TAS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< Tas，4位读写字段。 */
        using TDS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 5, std::uint32_t>; /**< Tds，5位读写字段。 */
        using TDH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< Tdh，4位读写字段。 */
        using THZ = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< Thz，4位读写字段。 */
    } // namespace TIME

    /** @brief DDR Test Mode Control and Status Register */
    namespace DDR_TEST_MODE_CSR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80020030, 0x80020034, 0x80020038, 0x8002003C, LowLevel::Access::ReadWrite>;
        using START = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Start，1位读写字段。 */
        using DONE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Done，1位读写字段。 */
    } // namespace DDR_TEST_MODE_CSR

    /** @brief NOR Flash Debug Register */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80020080, LowLevel::Access::ReadOnly>;
        using NOR_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< Nor State，4位读写字段。 */
    } // namespace DEBUG

    /** @brief DDR Test Mode Status Register 0 */
    namespace DDR_TEST_MODE_STATUS0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80020090, 0x80020094, 0x80020098, 0x8002009C, LowLevel::Access::ReadWrite>;
        using ADDR0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< Addr0，13位读写字段。 */
    } // namespace DDR_TEST_MODE_STATUS0

    /** @brief DDR Test Mode Status Register 1 */
    namespace DDR_TEST_MODE_STATUS1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800200A0, 0x800200A4, 0x800200A8, 0x800200AC, LowLevel::Access::ReadWrite>;
        using ADDR1 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< Addr1，13位读写字段。 */
    } // namespace DDR_TEST_MODE_STATUS1

    /** @brief DDR Test Mode Status Register 2 */
    namespace DDR_TEST_MODE_STATUS2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800200B0, 0x800200B4, 0x800200B8, 0x800200BC, LowLevel::Access::ReadWrite>;
        using DATA0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Data0，32位读写字段。 */
    } // namespace DDR_TEST_MODE_STATUS2

    /** @brief DDR Test Mode Status Register 3 */
    namespace DDR_TEST_MODE_STATUS3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800200C0, 0x800200C4, 0x800200C8, 0x800200CC, LowLevel::Access::ReadWrite>;
        using DATA1 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Data1，32位读写字段。 */
    } // namespace DDR_TEST_MODE_STATUS3

    /** @brief EMI Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800200F0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Step，16位读写字段。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Minor，8位读写字段。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Major，8位读写字段。 */
    } // namespace VERSION

} // namespace Hardware::Registers::EMI

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_EMI
