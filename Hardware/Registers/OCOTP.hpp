#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_OCOTP
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_OCOTP

/**
 * @file OCOTP.hpp
 * @brief OCOTP 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 片上一次性可编程熔丝(OCOTP,存储芯片 ID、ROM 配置、密钥与硬件能力位)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::OCOTP {

    /** @brief OTP Controller Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C000, 0x8002C004, 0x8002C008, 0x8002C00C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< Addr，5位读写字段。 */
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Busy，1位读写字段。 */
        using ERROR = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Error，1位读写字段。 */
        using RD_BANK_OPEN = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Rd Bank Open，1位读写字段。 */
        using RELOAD_SHADOWS = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Reload Shadows，1位读写字段。 */
        /** @brief WR_UNLOCK 的取值。 */
        enum class WR_UNLOCK_Values : std::uint32_t {
            KEY = 0x3E77,
        };
        using WR_UNLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, WR_UNLOCK_Values>; /**< Wr Unlock，16位读写字段。 */
    } // namespace CTRL

    /** @brief OTP Controller Write Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C010, 0x8002C014, 0x8002C018, 0x8002C01C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 数据寄存器，写操作将数据写入发送FIFO，读操作从接收FIFO取出数据。 */
    } // namespace DATA

    /** @brief CUST */
    namespace CUST0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C020, 0x8002C024, 0x8002C028, 0x8002C02C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CUST0

    /** @brief CUST */
    namespace CUST1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C030, 0x8002C034, 0x8002C038, 0x8002C03C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CUST1

    /** @brief CUST */
    namespace CUST2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C040, 0x8002C044, 0x8002C048, 0x8002C04C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CUST2

    /** @brief CUST */
    namespace CUST3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C050, 0x8002C054, 0x8002C058, 0x8002C05C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CUST3

    /** @brief CRYPTO */
    namespace CRYPTO0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C060, 0x8002C064, 0x8002C068, 0x8002C06C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CRYPTO0

    /** @brief CRYPTO */
    namespace CRYPTO1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C070, 0x8002C074, 0x8002C078, 0x8002C07C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CRYPTO1

    /** @brief CRYPTO */
    namespace CRYPTO2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C080, 0x8002C084, 0x8002C088, 0x8002C08C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CRYPTO2

    /** @brief CRYPTO */
    namespace CRYPTO3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C090, 0x8002C094, 0x8002C098, 0x8002C09C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CRYPTO3

    /** @brief HWCAP */
    namespace HWCAP0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C0A0, 0x8002C0A4, 0x8002C0A8, 0x8002C0AC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace HWCAP0

    /** @brief HWCAP */
    namespace HWCAP1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C0B0, 0x8002C0B4, 0x8002C0B8, 0x8002C0BC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace HWCAP1

    /** @brief HWCAP */
    namespace HWCAP2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C0C0, 0x8002C0C4, 0x8002C0C8, 0x8002C0CC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace HWCAP2

    /** @brief HWCAP */
    namespace HWCAP3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C0D0, 0x8002C0D4, 0x8002C0D8, 0x8002C0DC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace HWCAP3

    /** @brief HWCAP */
    namespace HWCAP4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C0E0, 0x8002C0E4, 0x8002C0E8, 0x8002C0EC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace HWCAP4

    /** @brief HWCAP */
    namespace HWCAP5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C0F0, 0x8002C0F4, 0x8002C0F8, 0x8002C0FC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace HWCAP5

    /** @brief SW Capability Shadow Register */
    namespace SWCAP {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C100, 0x8002C104, 0x8002C108, 0x8002C10C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace SWCAP

    /** @brief Customer Capability Shadow Register */
    namespace CUSTCAP {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C110, 0x8002C114, 0x8002C118, 0x8002C11C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace CUSTCAP

    /** @brief LOCK Shadow Register OTP Bank 2 Word 0 */
    namespace LOCK {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C120, 0x8002C124, 0x8002C128, 0x8002C12C, LowLevel::Access::ReadWrite>;
        using CUST0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Cust0，1位读写字段。 */
        using CUST1 = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Cust1，1位读写字段。 */
        using CUST2 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Cust2，1位读写字段。 */
        using CUST3 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Cust3，1位读写字段。 */
        using CRYPTOKEY = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Cryptokey，1位读写字段。 */
        using CRYPTODCP = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Cryptodcp，1位读写字段。 */
        using HWSW_SHADOW = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Hwsw Shadow，1位读写字段。 */
        using CUSTCAP_SHADOW = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Custcap Shadow，1位读写字段。 */
        using HWSW = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Hwsw，1位读写字段。 */
        using CUSTCAP = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Custcap，1位读写字段。 */
        using ROM_SHADOW = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Rom Shadow，1位读写字段。 */
        using UNALLOCATED = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 5, std::uint32_t>; /**< Unallocated，5位读写字段。 */
        using UN0 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Un0，1位读写字段。 */
        using UN1 = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< Un1，1位读写字段。 */
        using UN2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Un2，1位读写字段。 */
        using OPS = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< Ops，1位读写字段。 */
        using PIN = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< Pin，1位读写字段。 */
        using CRYPTOKEY_ALT = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< Cryptokey Alt，1位读写字段。 */
        using CRYPTODCP_ALT = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Cryptodcp Alt，1位读写字段。 */
        using HWSW_SHADOW_ALT = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< Hwsw Shadow Alt，1位读写字段。 */
        using ROM0 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Rom0，1位读写字段。 */
        using ROM1 = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Rom1，1位读写字段。 */
        using ROM2 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Rom2，1位读写字段。 */
        using ROM3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Rom3，1位读写字段。 */
        using ROM4 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Rom4，1位读写字段。 */
        using ROM5 = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Rom5，1位读写字段。 */
        using ROM6 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Rom6，1位读写字段。 */
        using ROM7 = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Rom7，1位读写字段。 */
    } // namespace LOCK

    /** @brief OPS */
    namespace OPS0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C130, 0x8002C134, 0x8002C138, 0x8002C13C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace OPS0

    /** @brief OPS */
    namespace OPS1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C140, 0x8002C144, 0x8002C148, 0x8002C14C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace OPS1

    /** @brief OPS */
    namespace OPS2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C150, 0x8002C154, 0x8002C158, 0x8002C15C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace OPS2

    /** @brief OPS */
    namespace OPS3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C160, 0x8002C164, 0x8002C168, 0x8002C16C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace OPS3

    /** @brief UN */
    namespace UN0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C170, 0x8002C174, 0x8002C178, 0x8002C17C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace UN0

    /** @brief UN */
    namespace UN1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C180, 0x8002C184, 0x8002C188, 0x8002C18C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace UN1

    /** @brief UN */
    namespace UN2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C190, 0x8002C194, 0x8002C198, 0x8002C19C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace UN2

    /** @brief ROM */
    namespace ROM0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C1A0, 0x8002C1A4, 0x8002C1A8, 0x8002C1AC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM0

    /** @brief ROM */
    namespace ROM1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C1B0, 0x8002C1B4, 0x8002C1B8, 0x8002C1BC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM1

    /** @brief ROM */
    namespace ROM2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C1C0, 0x8002C1C4, 0x8002C1C8, 0x8002C1CC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM2

    /** @brief ROM */
    namespace ROM3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C1D0, 0x8002C1D4, 0x8002C1D8, 0x8002C1DC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM3

    /** @brief ROM */
    namespace ROM4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C1E0, 0x8002C1E4, 0x8002C1E8, 0x8002C1EC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM4

    /** @brief ROM */
    namespace ROM5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C1F0, 0x8002C1F4, 0x8002C1F8, 0x8002C1FC, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM5

    /** @brief ROM */
    namespace ROM6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C200, 0x8002C204, 0x8002C208, 0x8002C20C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM6

    /** @brief ROM */
    namespace ROM7 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8002C210, 0x8002C214, 0x8002C218, 0x8002C21C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bits，32位读写字段。 */
    } // namespace ROM7

    /** @brief OTP Controller Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8002C220, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Step，16位读写字段。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Minor，8位读写字段。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Major，8位读写字段。 */
    } // namespace VERSION

} // namespace Hardware::Registers::OCOTP

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_OCOTP
