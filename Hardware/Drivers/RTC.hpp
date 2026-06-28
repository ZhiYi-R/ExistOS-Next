#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_RTC
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_RTC

/**
 * @file RTC.hpp
 * @brief 实时时钟(RTC)驱动:模块复位/门控、毫秒/秒自由计数读取、闹钟与 1ms 中断、
 *        看门狗,以及掉电保持寄存器 PERSISTENT0–5 的参数化访问。
 *
 * STMP3770/i.MX23 的 RTC 数字域寄存器(MILLISECONDS/SECONDS 等)由 32.768kHz 低速时钟
 * 驱动自由计数,读取无需同步;写计数/闹钟/保持值需经数字域→模拟域拷贝,STAT.NEW_REGS 位图
 * 指示尚未同步完成的寄存器。本层只给"触发写入 + 非阻塞谓词 AreWritesComplete()",
 * 同步落地的轮询/超时编排上移 OS。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * 典型用法:
 *  - bring-up:`RTC::DeassertSoftReset(); RTC::EnableClock();`
 *  - 软件 tick:周期读 `RTC::ReadMilliseconds()` 求差。
 *  - 启动模式标志:`RTC::PersistentRegister<1>::Write(flag);`(触发);`RTC::AreWritesComplete()` 查同步。
 *
 * PERSISTENT{n} 命名空间无法被模板整数参数化,故用 consteval 选择函数 SelectPersistentRegister<n>
 * 把"序号 → PERSISTENT{n} 后端"在编译期固定;访问以整字读写(各位语义见生成头)。
 *
 * @note 寄存器/字段取自生成头 Registers/RTC.hpp,复位原语复用 Common::{AssertSoftReset,…};
 *       复位序列节拍上移 OS,本层只给触发 + 谓词。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/RTC.hpp"
#include <cstdint>
#include <type_traits>

namespace Hardware::Drivers {

    /** @brief 实时时钟(RTC)驱动:纯静态门面,无实例。 */
    struct RTC {
        RTC() = delete;
        ~RTC() = delete;
        RTC(const RTC&) = delete;
        RTC& operator=(const RTC&) = delete;

    private:
        using ControlRegister = Registers::RTC::CTRL::Reg;            /**< 主控制寄存器(复位/门控/中断/看门狗)。 */
        using StatusRegister = Registers::RTC::STAT::Reg;             /**< 状态寄存器(NEW_REGS 同步位图)。 */
        using MillisecondsRegister = Registers::RTC::MILLISECONDS::Reg; /**< 毫秒自由计数寄存器。 */
        using SecondsRegister = Registers::RTC::SECONDS::Reg;         /**< 秒自由计数寄存器。 */
        using AlarmRegister = Registers::RTC::ALARM::Reg;             /**< 闹钟比较值寄存器。 */
        using WatchdogRegister = Registers::RTC::WATCHDOG::Reg;       /**< 看门狗倒计数寄存器。 */

        using SoftReset = Registers::RTC::CTRL::SFTRST;  /**< CTRL.SFTRST 字段后端。 */
        using ClockGate = Registers::RTC::CTRL::CLKGATE; /**< CTRL.CLKGATE 字段后端。 */

        /**
         * @brief PERSISTENT 序号 → 生成头 PERSISTENT{Index} 后端的编译期映射。
         * @tparam Index 序号(0–5)。
         * @return std::type_identity 包裹对应 PERSISTENT{Index}::Reg 后端类型。
         */
        template <std::uint32_t Index>
        [[nodiscard]] static consteval auto SelectPersistentRegister() noexcept {
            if constexpr (Index == 0u) return std::type_identity<Registers::RTC::PERSISTENT0::Reg>{};
            else if constexpr (Index == 1u) return std::type_identity<Registers::RTC::PERSISTENT1::Reg>{};
            else if constexpr (Index == 2u) return std::type_identity<Registers::RTC::PERSISTENT2::Reg>{};
            else if constexpr (Index == 3u) return std::type_identity<Registers::RTC::PERSISTENT3::Reg>{};
            else if constexpr (Index == 4u) return std::type_identity<Registers::RTC::PERSISTENT4::Reg>{};
            else return std::type_identity<Registers::RTC::PERSISTENT5::Reg>{};
        }

        /** @brief 序号 → PERSISTENT{Index} 后端类型(consteval 链产物)。 */
        template <std::uint32_t Index>
        using PersistentBackend = typename decltype(SelectPersistentRegister<Index>())::type;

    public:
        /** @brief 掉电保持寄存器个数(PERSISTENT0–5)。 */
        static constexpr std::uint32_t PersistentRegisterCount = 6u;

        // ====================== 模块级:复位 / 门控 ======================

        /** @brief 触发软复位:置 CTRL.SFTRST(单条原子 str→SET)。 */
        [[gnu::always_inline]] static void AssertSoftReset() noexcept {
            Common::AssertSoftReset<SoftReset>();
        }

        /** @brief 退出软复位:清 CTRL.SFTRST(单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DeassertSoftReset() noexcept {
            Common::DeassertSoftReset<SoftReset>();
        }

        /** @brief 非阻塞谓词:软复位是否仍被置位(CTRL.SFTRST==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSoftResetAsserted() noexcept {
            return Common::IsSoftResetAsserted<SoftReset>();
        }

        /** @brief 使能 RTC 模块时钟(清 CTRL.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 RTC 模块时钟(置 CTRL.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        // ====================== 计数读取 / 写同步 ======================

        /**
         * @brief 读取毫秒自由计数(MILLISECONDS,32 位)。无需模拟域同步,可直接读。
         * @return 32 位毫秒计数。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadMilliseconds() noexcept {
            return MillisecondsRegister::Read();
        }

        /**
         * @brief 读取秒自由计数(SECONDS,32 位)。
         * @return 32 位秒计数。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadSeconds() noexcept {
            return SecondsRegister::Read();
        }

        /**
         * @brief 非阻塞谓词:挂起的数字域写入是否已全部同步到模拟域(STAT.NEW_REGS==0)。
         *
         * 写计数/闹钟/保持值后用此谓词查询同步是否落地;轮询/超时编排上移 OS。
         * @return 无挂起写入返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool AreWritesComplete() noexcept {
            return StatusRegister::template ReadField<Registers::RTC::STAT::NEW_REGS>() == 0u;
        }

        /**
         * @brief 设置秒计数(纯触发:写 SECONDS)。同步落地用 AreWritesComplete() 查询。
         * @param seconds 新的秒计数值。
         */
        [[gnu::always_inline]] static void SetSeconds(std::uint32_t seconds) noexcept {
            SecondsRegister::Write(seconds);
        }

        // ====================== 闹钟 ======================

        /**
         * @brief 设置闹钟比较值(写 ALARM,单位秒,与 SECONDS 比较)。
         * @param alarmSeconds 闹钟触发的秒值。
         */
        [[gnu::always_inline]] static void SetAlarm(std::uint32_t alarmSeconds) noexcept {
            AlarmRegister::Write(alarmSeconds);
        }

        /** @brief 使能闹钟中断(置 CTRL.ALARM_IRQ_EN,单条原子 str→SET)。 */
        [[gnu::always_inline]] static void EnableAlarmInterrupt() noexcept {
            ControlRegister::template SetField<Registers::RTC::CTRL::ALARM_IRQ_EN>();
        }

        /** @brief 关闭闹钟中断(清 CTRL.ALARM_IRQ_EN,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DisableAlarmInterrupt() noexcept {
            ControlRegister::template ClearField<Registers::RTC::CTRL::ALARM_IRQ_EN>();
        }

        /**
         * @brief 闹钟中断是否挂起(读 CTRL.ALARM_IRQ)。
         * @return 已触发返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool IsAlarmInterruptPending() noexcept {
            return ControlRegister::template FieldIsSet<Registers::RTC::CTRL::ALARM_IRQ>();
        }

        /** @brief 清除闹钟中断标志(清 CTRL.ALARM_IRQ,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AcknowledgeAlarmInterrupt() noexcept {
            ControlRegister::template ClearField<Registers::RTC::CTRL::ALARM_IRQ>();
        }

        // ====================== 1ms 周期中断 ======================

        /** @brief 使能 1ms 周期中断(置 CTRL.ONEMSEC_IRQ_EN)。 */
        [[gnu::always_inline]] static void EnableMillisecondInterrupt() noexcept {
            ControlRegister::template SetField<Registers::RTC::CTRL::ONEMSEC_IRQ_EN>();
        }

        /** @brief 关闭 1ms 周期中断(清 CTRL.ONEMSEC_IRQ_EN)。 */
        [[gnu::always_inline]] static void DisableMillisecondInterrupt() noexcept {
            ControlRegister::template ClearField<Registers::RTC::CTRL::ONEMSEC_IRQ_EN>();
        }

        /**
         * @brief 1ms 中断是否挂起(读 CTRL.ONEMSEC_IRQ)。
         * @return 已触发返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool IsMillisecondInterruptPending() noexcept {
            return ControlRegister::template FieldIsSet<Registers::RTC::CTRL::ONEMSEC_IRQ>();
        }

        /** @brief 清除 1ms 中断标志(清 CTRL.ONEMSEC_IRQ)。 */
        [[gnu::always_inline]] static void AcknowledgeMillisecondInterrupt() noexcept {
            ControlRegister::template ClearField<Registers::RTC::CTRL::ONEMSEC_IRQ>();
        }

        // ====================== 看门狗 ======================

        /**
         * @brief 设置看门狗倒计数初值(写 WATCHDOG,减至 0 触发复位)。
         * @param count 倒计数初值(单位毫秒)。
         */
        [[gnu::always_inline]] static void SetWatchdogCount(std::uint32_t count) noexcept {
            WatchdogRegister::Write(count);
        }

        /** @brief 使能看门狗(置 CTRL.WATCHDOGEN)。 */
        [[gnu::always_inline]] static void EnableWatchdog() noexcept {
            ControlRegister::template SetField<Registers::RTC::CTRL::WATCHDOGEN>();
        }

        /** @brief 关闭看门狗(清 CTRL.WATCHDOGEN)。 */
        [[gnu::always_inline]] static void DisableWatchdog() noexcept {
            ControlRegister::template ClearField<Registers::RTC::CTRL::WATCHDOGEN>();
        }

        /**
         * @brief 编译期固定序号的掉电保持寄存器门面(纯静态),以整字读写。
         *
         * PERSISTENT0/1 含结构化位域(时钟源/闹钟/启动模式等,见生成头),本门面只提供整字
         * 读写;需要逐位语义时直接用 Registers/RTC.hpp 中该寄存器的具名字段。写入为纯触发,
         * 同步落地用外层 RTC::AreWritesComplete() 查询。
         *
         * @tparam Index 序号(0–5),越界编译期报错。
         */
        template <std::uint32_t Index>
            requires(Index < PersistentRegisterCount)
        struct PersistentRegister {
            PersistentRegister() = delete;
            ~PersistentRegister() = delete;
            PersistentRegister(const PersistentRegister&) = delete;
            PersistentRegister& operator=(const PersistentRegister&) = delete;

        private:
            using Backend = PersistentBackend<Index>; /**< 本序号对应的 PERSISTENT 寄存器后端。 */

        public:
            /**
             * @brief 读取整字(掉电保持数据)。
             * @return 32 位保持值。
             */
            [[gnu::always_inline]] [[nodiscard]] static std::uint32_t Read() noexcept {
                return Backend::Read();
            }

            /**
             * @brief 写入整字(纯触发)。同步落地用 RTC::AreWritesComplete() 查询。
             * @param value 新的 32 位保持值。
             */
            [[gnu::always_inline]] static void Write(std::uint32_t value) noexcept {
                Backend::Write(value);
            }
        };
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_RTC
