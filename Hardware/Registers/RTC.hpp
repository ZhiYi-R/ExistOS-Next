#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_RTC
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_RTC

/**
 * @file RTC.hpp
 * @brief RTC 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 RTC (Real-Time Clock) 外设寄存器与位域中文描述
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::RTC {

    /** @brief 实时时钟控制寄存器，用于配置中断使能、看门狗、强制更新及模块时钟/复位控制。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C000, 0x8005C004, 0x8005C008, 0x8005C00C, LowLevel::Access::ReadWrite>;
        using ALARM_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 闹钟中断使能，置位后允许 ALARM 匹配时产生中断。 */
        using ONEMSEC_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 1毫秒中断使能，置位后允许每 1ms 产生一次中断。 */
        using ALARM_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 闹钟中断状态标志，硬件在 ALARM 匹配时置位，写 1 清除。 */
        using ONEMSEC_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 1毫秒中断状态标志，硬件每 1ms 置位一次，写 1 清除。 */
        using WATCHDOGEN = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 看门狗使能，置位后启动 WATCHDOG 计数器。 */
        using FORCE_UPDATE = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 强制更新，置位后强制将数字域寄存器值写入模拟域。 */
        using SUPPRESS_COPY2ANALOG = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 抑制写回模拟域，置位后阻止数字域寄存器值拷贝到模拟域。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 时钟门控，置位后关闭 RTC 模块时钟以节能。 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 软复位，置位后对 RTC 模块执行软件复位。 */
    } // namespace CTRL

    /** @brief 实时时钟状态寄存器，反映寄存器同步状态及硬件功能存在性标志。 */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C010, 0x8005C014, 0x8005C018, 0x8005C01C, LowLevel::Access::ReadWrite>;
        using NEW_REGS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< 新值待生效标志，位图中置 1 的位表示对应寄存器有新值尚未同步到模拟域。 */
        using STALE_REGS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 写入未完成标志，位图中置 1 的位表示对应寄存器写入模拟域尚未完成。 */
        using XTAL32768_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< 32.768kHz 晶振存在标志，置位表示该晶振已连接并可用。 */
        using XTAL32000_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< 32.000kHz 晶振存在标志，置位表示该晶振已连接并可用。 */
        using WATCHDOG_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 看门狗功能存在标志，置位表示 RTC 集成看门狗硬件。 */
        using ALARM_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 闹钟功能存在标志，置位表示 RTC 集成闹钟硬件。 */
        using RTC_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< RTC 模块存在标志，置位表示 RTC 硬件存在。 */
    } // namespace STAT

    /** @brief 实时时钟毫秒计数器，32 位自由运行毫秒计数。 */
    namespace MILLISECONDS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C020, 0x8005C024, 0x8005C028, 0x8005C02C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 毫秒计数值，32 位自由运行计数器，每 1ms 递增。 */
    } // namespace MILLISECONDS

    /** @brief 实时时钟秒计数器，32 位自由运行秒计数。 */
    namespace SECONDS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C030, 0x8005C034, 0x8005C038, 0x8005C03C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 秒计数值，32 位自由运行计数器，每 1 秒递增。 */
    } // namespace SECONDS

    /** @brief 实时时钟闹钟寄存器，用于设置秒级闹钟比较值。 */
    namespace ALARM {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C040, 0x8005C044, 0x8005C048, 0x8005C04C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 闹钟比较值，当 SECONDS.COUNT 等于该值时触发闹钟事件。 */
    } // namespace ALARM

    /** @brief 看门狗定时器寄存器，用于配置看门狗倒计数初值。 */
    namespace WATCHDOG {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C050, 0x8005C054, 0x8005C058, 0x8005C05C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 看门狗倒计数值，写入后递减，减至 0 时触发看门狗复位。 */
    } // namespace WATCHDOG

    /** @brief 掉电保持状态寄存器 0，保存系统级持久控制位，掉电后由备用电源维持。 */
    namespace PERSISTENT0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C060, 0x8005C064, 0x8005C068, 0x8005C06C, LowLevel::Access::ReadWrite>;
        using CLOCKSOURCE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< RTC 时钟源选择，0 表示 32.768kHz 晶振，1 表示 32.000kHz 晶振。 */
        using ALARM_WAKE_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 闹钟唤醒使能，置位后允许闹钟事件将系统从低功耗状态唤醒。 */
        using ALARM_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 闹钟功能使能，置位后启用 RTC 闹钟比较功能。 */
        using LCK_SECS = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 秒计数器锁定，置位后锁定 SECONDS 寄存器防止误写。 */
        using XTAL24MHZ_PWRUP = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 24MHz 晶振上电控制，置位后给 24MHz 晶振电路上电。 */
        using XTAL32KHZ_PWRUP = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 32kHz 晶振上电控制，置位后给 32kHz 晶振电路上电。 */
        using XTAL32_FREQ = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 32kHz 晶振频率选择，0 表示 32.768kHz，1 表示 32.000kHz。 */
        using ALARM_WAKE = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 闹钟唤醒标志，置位表示系统由闹钟事件唤醒。 */
        using MSEC_RES = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 5, std::uint32_t>; /**< 毫秒分辨率配置，5 位字段用于设置毫秒计数器的分辨率。 */
        using DISABLE_XTALOK = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< 禁用 XTAL 正常指示，置位后关闭晶振起振 OK 检测。 */
        using LOWERBIAS = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< 降低偏置电流配置，2 位字段用于调节模拟偏置电流以降低功耗。 */
        using DISABLE_PSWITCH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 禁用 PSWITCH 功能，置位后关闭电源开关检测。 */
        using AUTO_RESTART = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 自动重启使能，置位后系统在特定条件下自动重新启动。 */
        using SPARE_ANALOG = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 14, std::uint32_t>; /**< 模拟域备用位，14 位保留给模拟电路使用的备用配置字段。 */
    } // namespace PERSISTENT0

    /** @brief 掉电保持状态寄存器 1，32 位通用持久存储，可用于保存系统标志。 */
    namespace PERSISTENT1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C070, 0x8005C074, 0x8005C078, 0x8005C07C, LowLevel::Access::ReadWrite>;
        /** @brief GENERAL 的取值。 */
        enum class GENERAL_Values : std::uint32_t {
            ENUMERATE_500MA_TWICE = 0x1000,
            USB_BOOT_PLAYER_MODE = 0x800,
            SKIP_CHECKDISK = 0x400,
            USB_LOW_POWER_MODE = 0x200,
            OTG_HNP_BIT = 0x100,
            OTG_ATL_ROLE_BIT = 0x80,
        };
        using GENERAL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, GENERAL_Values>; /**< 通用 32 位持久数据，掉电保持，可存储系统标志(如 USB 启动模式、OTG 角色等)。 */
    } // namespace PERSISTENT1

    /** @brief 掉电保持状态寄存器 2，32 位通用持久存储。 */
    namespace PERSISTENT2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C080, 0x8005C084, 0x8005C088, 0x8005C08C, LowLevel::Access::ReadWrite>;
        using GENERAL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 通用 32 位持久数据，掉电保持，由软件自由使用。 */
    } // namespace PERSISTENT2

    /** @brief 掉电保持状态寄存器 3，32 位通用持久存储。 */
    namespace PERSISTENT3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C090, 0x8005C094, 0x8005C098, 0x8005C09C, LowLevel::Access::ReadWrite>;
        using GENERAL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 通用 32 位持久数据，掉电保持，由软件自由使用。 */
    } // namespace PERSISTENT3

    /** @brief 掉电保持状态寄存器 4，32 位通用持久存储。 */
    namespace PERSISTENT4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C0A0, 0x8005C0A4, 0x8005C0A8, 0x8005C0AC, LowLevel::Access::ReadWrite>;
        using GENERAL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 通用 32 位持久数据，掉电保持，由软件自由使用。 */
    } // namespace PERSISTENT4

    /** @brief 掉电保持状态寄存器 5，32 位通用持久存储。 */
    namespace PERSISTENT5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8005C0B0, 0x8005C0B4, 0x8005C0B8, 0x8005C0BC, LowLevel::Access::ReadWrite>;
        using GENERAL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 通用 32 位持久数据，掉电保持，由软件自由使用。 */
    } // namespace PERSISTENT5

    /** @brief 实时时钟调试寄存器，用于控制看门狗复位行为。 */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8005C0C0, LowLevel::Access::ReadOnly>;
        using WATCHDOG_RESET = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 看门狗复位标志，置位表示看门狗已触发复位。 */
        using WATCHDOG_RESET_MASK = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 看门狗复位屏蔽，置位后屏蔽看门狗产生的系统复位。 */
    } // namespace DEBUG

    /** @brief 实时时钟版本寄存器，反映 RTC 模块的硬件版本信息。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8005C0D0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 步进版本号，16 位字段表示当前硬件的步进版本。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 次版本号，8 位字段表示当前硬件的次要版本。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 主版本号，8 位字段表示当前硬件的主要版本。 */
    } // namespace VERSION

} // namespace Hardware::Registers::RTC

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_RTC
