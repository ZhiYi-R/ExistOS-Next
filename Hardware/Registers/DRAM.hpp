#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_DRAM
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_DRAM

/**
 * @file DRAM.hpp
 * @brief DRAM 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * DRAM 控制器(mDDR/SDRAM 时序、刷新与校准配置寄存器)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::DRAM {

    /** @brief DRAM Control Register 00 */
    namespace CTL00 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0000, LowLevel::Access::ReadWrite>;
        using ADDR_CMP_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Addr Cmp En，1位读写字段。 */
        using AHB0_FIFO_TYPE_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Ahb0 Fifo Type Reg，1位读写字段。 */
        using AHB0_R_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Ahb0 R Priority，1位读写字段。 */
        using AHB0_W_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Ahb0 W Priority，1位读写字段。 */
    } // namespace CTL00

    /** @brief DRAM Control Register 01 */
    namespace CTL01 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0004, LowLevel::Access::ReadWrite>;
        using AHB1_FIFO_TYPE_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Ahb1 Fifo Type Reg，1位读写字段。 */
        using AHB1_R_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Ahb1 R Priority，1位读写字段。 */
        using AHB1_W_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Ahb1 W Priority，1位读写字段。 */
        using AHB2_FIFO_TYPE_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Ahb2 Fifo Type Reg，1位读写字段。 */
    } // namespace CTL01

    /** @brief DRAM Control Register 02 */
    namespace CTL02 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0008, LowLevel::Access::ReadWrite>;
        using AHB2_R_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Ahb2 R Priority，1位读写字段。 */
        using AHB2_W_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Ahb2 W Priority，1位读写字段。 */
        using AHB3_FIFO_TYPE_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Ahb3 Fifo Type Reg，1位读写字段。 */
        using AHB3_R_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Ahb3 R Priority，1位读写字段。 */
    } // namespace CTL02

    /** @brief DRAM Control Register 03 */
    namespace CTL03 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E000C, LowLevel::Access::ReadWrite>;
        using AHB3_W_PRIORITY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Ahb3 W Priority，1位读写字段。 */
        using AP = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Ap，1位读写字段。 */
        using AREFRESH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Arefresh，1位读写字段。 */
        using AUTO_REFRESH_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Auto Refresh Mode，1位读写字段。 */
    } // namespace CTL03

    /** @brief DRAM Control Register 04 */
    namespace CTL04 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0010, LowLevel::Access::ReadWrite>;
        using BANK_SPLIT_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Bank Split En，1位读写字段。 */
        using CONCURRENTAP = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Concurrentap，1位读写字段。 */
        using DLLLOCKREG = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Dlllockreg，1位读写字段。 */
        using DLL_BYPASS_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Dll Bypass Mode，1位读写字段。 */
    } // namespace CTL04

    /** @brief DRAM Control Register 05 */
    namespace CTL05 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0014, LowLevel::Access::ReadWrite>;
        using EN_LOWPOWER_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< En Lowpower Mode，1位读写字段。 */
        using FAST_WRITE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Fast Write，1位读写字段。 */
        using INTRPTAPBURST = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Intrptapburst，1位读写字段。 */
        using INTRPTREADA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Intrptreada，1位读写字段。 */
    } // namespace CTL05

    /** @brief DRAM Control Register 06 */
    namespace CTL06 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0018, LowLevel::Access::ReadWrite>;
        using INTRPTWRITEA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Intrptwritea，1位读写字段。 */
        using NO_CMD_INIT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< No Cmd Init，1位读写字段。 */
        using PLACEMENT_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Placement En，1位读写字段。 */
        using POWER_DOWN = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Power Down，1位读写字段。 */
    } // namespace CTL06

    /** @brief DRAM Control Register 07 */
    namespace CTL07 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E001C, LowLevel::Access::ReadWrite>;
        using PRIORITY_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Priority En，1位读写字段。 */
        using RD2RD_TURN = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Rd2Rd Turn，1位读写字段。 */
        using REG_DIMM_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Reg Dimm Enable，1位读写字段。 */
        using RW_SAME_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Rw Same En，1位读写字段。 */
    } // namespace CTL07

    /** @brief DRAM Control Register 08 */
    namespace CTL08 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0020, LowLevel::Access::ReadWrite>;
        using SDR_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Sdr Mode，1位读写字段。 */
        using SREFRESH = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Srefresh，1位读写字段。 */
        using START = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Start，1位读写字段。 */
        using TRAS_LOCKOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Tras Lockout，1位读写字段。 */
    } // namespace CTL08

    /** @brief DRAM Control Register 09 */
    namespace CTL09 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0024, LowLevel::Access::ReadWrite>;
        using WRITEINTERP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Writeinterp，1位读写字段。 */
        using WRITE_MODEREG = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Write Modereg，1位读写字段。 */
        using OUT_OF_RANGE_SOURCE_ID = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Out Of Range Source Id，2位读写字段。 */
        using OUT_OF_RANGE_TYPE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Out Of Range Type，2位读写字段。 */
    } // namespace CTL09

    /** @brief DRAM Control Register 10 */
    namespace CTL10 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0028, LowLevel::Access::ReadWrite>;
        using Q_FULLNESS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Q Fullness，2位读写字段。 */
        using TEMRS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Temrs，2位读写字段。 */
        using ADDR_PINS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 3, std::uint32_t>; /**< Addr Pins，3位读写字段。 */
        using AGE_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 3, std::uint32_t>; /**< Age Count，3位读写字段。 */
    } // namespace CTL10

    /** @brief DRAM Control Register 11 */
    namespace CTL11 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E002C, LowLevel::Access::ReadWrite>;
        using CASLAT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 3, std::uint32_t>; /**< Caslat，3位读写字段。 */
        using COLUMN_SIZE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< Column Size，3位读写字段。 */
        using COMMAND_AGE_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 3, std::uint32_t>; /**< Command Age Count，3位读写字段。 */
        using MAX_CS_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 3, std::uint32_t>; /**< Max Cs Reg，3位读写字段。 */
    } // namespace CTL11

    /** @brief DRAM Control Register 12 */
    namespace CTL12 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0030, LowLevel::Access::ReadWrite>;
        using TCKE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 3, std::uint32_t>; /**< Tcke，3位读写字段。 */
        using OBSOLETE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< Obsolete，8位读写字段。 */
        using TRRD = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 3, std::uint32_t>; /**< Trrd，3位读写字段。 */
        using TWR_INT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 3, std::uint32_t>; /**< Twr Int，3位读写字段。 */
    } // namespace CTL12

    /** @brief DRAM Control Register 13 */
    namespace CTL13 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0034, LowLevel::Access::ReadWrite>;
        using TWTR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 3, std::uint32_t>; /**< Twtr，3位读写字段。 */
        using APREBIT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< Aprebit，4位读写字段。 */
        using CASLAT_LIN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< Caslat Lin，4位读写字段。 */
        using CASLAT_LIN_GATE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< Caslat Lin Gate，4位读写字段。 */
    } // namespace CTL13

    /** @brief DRAM Control Register 14 */
    namespace CTL14 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0038, LowLevel::Access::ReadWrite>;
        using CS_MAP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< Cs Map，4位读写字段。 */
        using INITAREF = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< Initaref，4位读写字段。 */
        using LOWPOWER_REFRESH_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< Lowpower Refresh Enable，4位读写字段。 */
        using MAX_COL_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< Max Col Reg，4位读写字段。 */
    } // namespace CTL14

    /** @brief DRAM Control Register 15 */
    namespace CTL15 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E003C, LowLevel::Access::ReadWrite>;
        using MAX_ROW_REG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< Max Row Reg，4位读写字段。 */
        using PORT_BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< Port Busy，4位读写字段。 */
        using TDAL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< Tdal，4位读写字段。 */
        using TRP = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, std::uint32_t>; /**< Trp，4位读写字段。 */
    } // namespace CTL15

    /** @brief DRAM Control Register 16 */
    namespace CTL16 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0040, LowLevel::Access::ReadWrite>;
        using INT_ACK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< Int Ack，4位读写字段。 */
        using LOWPOWER_AUTO_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 5, std::uint32_t>; /**< Lowpower Auto Enable，5位读写字段。 */
        using LOWPOWER_CONTROL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, std::uint32_t>; /**< Lowpower Control，5位读写字段。 */
        using TMRD = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< Tmrd，5位读写字段。 */
    } // namespace CTL16

    /** @brief DRAM Control Register 17 */
    namespace CTL17 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0044, LowLevel::Access::ReadWrite>;
        using TRC = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< Trc，5位读写字段。 */
        using DLL_INCREMENT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< Dll Increment，8位读写字段。 */
        using DLL_LOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Dll Lock，8位读写字段。 */
        using DLL_START_POINT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Dll Start Point，8位读写字段。 */
    } // namespace CTL17

    /** @brief DRAM Control Register 18 */
    namespace CTL18 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0048, LowLevel::Access::ReadWrite>;
        using INT_MASK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< Int Mask，5位读写字段。 */
        using INT_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 5, std::uint32_t>; /**< Int Status，5位读写字段。 */
        using DLL_DQS_DELAY_0 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 7, std::uint32_t>; /**< Dll Dqs Delay 0，7位读写字段。 */
        using DLL_DQS_DELAY_1 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 7, std::uint32_t>; /**< Dll Dqs Delay 1，7位读写字段。 */
    } // namespace CTL18

    /** @brief DRAM Control Register 19 */
    namespace CTL19 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E004C, LowLevel::Access::ReadWrite>;
        using DLL_DQS_DELAY_BYPASS_0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< Dll Dqs Delay Bypass 0，8位读写字段。 */
        using DLL_DQS_DELAY_BYPASS_1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< Dll Dqs Delay Bypass 1，8位读写字段。 */
        using DQS_OUT_SHIFT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 7, std::uint32_t>; /**< Dqs Out Shift，7位读写字段。 */
        using DQS_OUT_SHIFT_BYPASS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Dqs Out Shift Bypass，8位读写字段。 */
    } // namespace CTL19

    /** @brief DRAM Control Register 20 */
    namespace CTL20 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0050, LowLevel::Access::ReadWrite>;
        using WR_DQS_SHIFT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 7, std::uint32_t>; /**< Wr Dqs Shift，7位读写字段。 */
        using WR_DQS_SHIFT_BYPASS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< Wr Dqs Shift Bypass，8位读写字段。 */
        using TRAS_MIN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Tras Min，8位读写字段。 */
        using TRCD_INT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Trcd Int，8位读写字段。 */
    } // namespace CTL20

    /** @brief DRAM Control Register 21 */
    namespace CTL21 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0054, LowLevel::Access::ReadWrite>;
        using TRFC = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< Trfc，8位读写字段。 */
        using OUT_OF_RANGE_LENGTH = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 10, std::uint32_t>; /**< Out Of Range Length，10位读写字段。 */
        using OBSOLETE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Obsolete，8位读写字段。 */
    } // namespace CTL21

    /** @brief DRAM Control Register 22 */
    namespace CTL22 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0058, LowLevel::Access::ReadWrite>;
        using AHB0_RDCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< Ahb0 Rdcnt，11位读写字段。 */
        using AHB0_WRCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 11, std::uint32_t>; /**< Ahb0 Wrcnt，11位读写字段。 */
    } // namespace CTL22

    /** @brief DRAM Control Register 23 */
    namespace CTL23 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E005C, LowLevel::Access::ReadWrite>;
        using AHB1_RDCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< Ahb1 Rdcnt，11位读写字段。 */
        using AHB1_WRCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 11, std::uint32_t>; /**< Ahb1 Wrcnt，11位读写字段。 */
    } // namespace CTL23

    /** @brief DRAM Control Register 24 */
    namespace CTL24 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0060, LowLevel::Access::ReadWrite>;
        using AHB2_RDCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< Ahb2 Rdcnt，11位读写字段。 */
        using AHB2_WRCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 11, std::uint32_t>; /**< Ahb2 Wrcnt，11位读写字段。 */
    } // namespace CTL24

    /** @brief DRAM Control Register 25 */
    namespace CTL25 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0064, LowLevel::Access::ReadWrite>;
        using AHB3_RDCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 11, std::uint32_t>; /**< Ahb3 Rdcnt，11位读写字段。 */
        using AHB3_WRCNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 11, std::uint32_t>; /**< Ahb3 Wrcnt，11位读写字段。 */
    } // namespace CTL25

    /** @brief DRAM Control Register 26 */
    namespace CTL26 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0068, LowLevel::Access::ReadWrite>;
        using TREF = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 12, std::uint32_t>; /**< Tref，12位读写字段。 */
        using OBSOLETE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Obsolete，16位读写字段。 */
    } // namespace CTL26

    /** @brief DRAM Control Register 27 */
    namespace CTL27 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E006C, LowLevel::Access::ReadWrite>;
        using OBSOLETE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Obsolete，32位读写字段。 */
    } // namespace CTL27

    /** @brief DRAM Control Register 28 */
    namespace CTL28 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0070, LowLevel::Access::ReadWrite>;
        using OBSOLETE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Obsolete，32位读写字段。 */
    } // namespace CTL28

    /** @brief DRAM Control Register 29 */
    namespace CTL29 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0074, LowLevel::Access::ReadWrite>;
        using LOWPOWER_EXTERNAL_CNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Lowpower External Cnt，16位读写字段。 */
        using LOWPOWER_INTERNAL_CNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Lowpower Internal Cnt，16位读写字段。 */
    } // namespace CTL29

    /** @brief DRAM Control Register 30 */
    namespace CTL30 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0078, LowLevel::Access::ReadWrite>;
        using LOWPOWER_POWER_DOWN_CNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Lowpower Power Down Cnt，16位读写字段。 */
        using LOWPOWER_REFRESH_HOLD = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Lowpower Refresh Hold，16位读写字段。 */
    } // namespace CTL30

    /** @brief DRAM Control Register 31 */
    namespace CTL31 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E007C, LowLevel::Access::ReadWrite>;
        using LOWPOWER_SELF_REFRESH_CNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Lowpower Self Refresh Cnt，16位读写字段。 */
        using TDLL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Tdll，16位读写字段。 */
    } // namespace CTL31

    /** @brief DRAM Control Register 32 */
    namespace CTL32 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0080, LowLevel::Access::ReadWrite>;
        using TRAS_MAX = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Tras Max，16位读写字段。 */
        using TXSNR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Txsnr，16位读写字段。 */
    } // namespace CTL32

    /** @brief DRAM Control Register 33 */
    namespace CTL33 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0084, LowLevel::Access::ReadWrite>;
        using TXSR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Txsr，16位读写字段。 */
        using VERSION = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Version，16位读写字段。 */
    } // namespace CTL33

    /** @brief DRAM Control Register 34 */
    namespace CTL34 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0088, LowLevel::Access::ReadWrite>;
        using TINIT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 24, std::uint32_t>; /**< Tinit，24位读写字段。 */
    } // namespace CTL34

    /** @brief DRAM Control Register 35 */
    namespace CTL35 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E008C, LowLevel::Access::ReadWrite>;
        using OUT_OF_RANGE_ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 31, std::uint32_t>; /**< Out Of Range Addr，31位读写字段。 */
    } // namespace CTL35

    /** @brief DRAM Control Register 36 */
    namespace CTL36 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0090, LowLevel::Access::ReadWrite>;
        using ACTIVE_AGING = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Active Aging，1位读写字段。 */
        using BUS_SHARE_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Bus Share Enable，1位读写字段。 */
        using ENABLE_QUICK_SREFRESH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Enable Quick Srefresh，1位读写字段。 */
        using PWRUP_SREFRESH_EXIT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Pwrup Srefresh Exit，1位读写字段。 */
    } // namespace CTL36

    /** @brief DRAM Control Register 37 */
    namespace CTL37 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0094, LowLevel::Access::ReadWrite>;
        using TREF_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Tref Enable，1位读写字段。 */
        using BUS_SHARE_TIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 10, std::uint32_t>; /**< Bus Share Timeout，10位读写字段。 */
        using OBSOLETE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Obsolete，8位读写字段。 */
    } // namespace CTL37

    /** @brief DRAM Control Register 38 */
    namespace CTL38 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E0098, LowLevel::Access::ReadWrite>;
        using EMRS1_DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< Emrs1 Data，13位读写字段。 */
        using EMRS2_DATA_0 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 13, std::uint32_t>; /**< Emrs2 Data 0，13位读写字段。 */
    } // namespace CTL38

    /** @brief DRAM Control Register 39 */
    namespace CTL39 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800E009C, LowLevel::Access::ReadWrite>;
        using EMRS2_DATA_1 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< Emrs2 Data 1，13位读写字段。 */
        using EMRS2_DATA_2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 13, std::uint32_t>; /**< Emrs2 Data 2，13位读写字段。 */
    } // namespace CTL39

    /** @brief DRAM Control Register 40 */
    namespace CTL40 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800E00A0, 0x800E00A4, 0x800E00A8, 0x800E00AC, LowLevel::Access::ReadWrite>;
        using EMRS2_DATA_3 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< Emrs2 Data 3，13位读写字段。 */
        using TPDEX = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Tpdex，16位读写字段。 */
    } // namespace CTL40

} // namespace Hardware::Registers::DRAM

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_DRAM
