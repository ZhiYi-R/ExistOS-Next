#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_TIMROT
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_TIMROT

/**
 * @file TIMROT.hpp
 * @brief 定时器/旋钮(TIMROT)驱动:模块复位/门控 + 编译期参数化的逐定时器门面 Timer<Index>。
 *
 * STMP3770/i.MX23 的 TIMROT 含 4 个 16 位倒计数定时器(Timer0–3),各有一对寄存器:
 *  - TIMCTRL{n}:时钟源 SELECT、预分频 PRESCALE、自动重载 RELOAD、更新触发 UPDATE、
 *    中断使能 IRQ_EN、中断标志 IRQ;
 *  - TIMCOUNT{n}:重载初值 FIXED_COUNT(写)、当前计数 RUNNING_COUNT(只读)。
 * 模块整体的软复位/时钟门控在 ROTCTRL.SFTRST/CLKGATE。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * 系统 tick 典型用法(Timer0 取 32kHz 晶振,周期 N,开中断):
 *   `TIMROT::DeassertSoftReset(); TIMROT::EnableClock();`
 *   `using Tick = TIMROT::Timer<0>;`
 *   `Tick::ConfigurePeriodic(Tick::Source::_32KHZ_XTAL, Tick::Prescale::DIV_BY_1, reload, true);`
 * ISR 内 `Tick::AcknowledgeInterrupt();` 清标志。
 *
 * 命名空间 TIMCTRL{n}/TIMCOUNT{n} 无法被模板整数参数化,故用 Detail::TimerTraits<n> 的
 * **手写显式特化**把"定时器号 → 该定时器的寄存器/字段/枚举别名"在编译期固定。
 *
 * @note 寄存器/字段取自生成头 Registers/TIMROT.hpp,复位原语复用 Common::{AssertSoftReset,…};
 *       复位序列节拍上移 OS,本层只给触发 + 谓词。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/TIMROT.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    namespace Detail {

        /**
         * @brief 定时器号 → 该定时器寄存器/字段/枚举别名的映射(主模板未定义)。
         *
         * 仅对 0–3 提供**手写显式特化**(原先由局部宏批量生成,现按"禁止函数式宏"展开为
         * 逐定时器特化列表);非法定时器号实例化将因主模板不完整而编译失败。
         * @tparam Index 定时器号(0–3)。
         */
        template <std::uint32_t Index>
        struct TimerTraits;

        template <>
        struct TimerTraits<0u> {
            using ControlReg = Registers::TIMROT::TIMCTRL0::Reg;
            using CountReg = Registers::TIMROT::TIMCOUNT0::Reg;
            using SelectField = Registers::TIMROT::TIMCTRL0::SELECT;
            using SelectValues = Registers::TIMROT::TIMCTRL0::SELECT_Values;
            using PrescaleField = Registers::TIMROT::TIMCTRL0::PRESCALE;
            using PrescaleValues = Registers::TIMROT::TIMCTRL0::PRESCALE_Values;
            using ReloadField = Registers::TIMROT::TIMCTRL0::RELOAD;
            using UpdateField = Registers::TIMROT::TIMCTRL0::UPDATE;
            using IrqEnableField = Registers::TIMROT::TIMCTRL0::IRQ_EN;
            using IrqField = Registers::TIMROT::TIMCTRL0::IRQ;
            using FixedCountField = Registers::TIMROT::TIMCOUNT0::FIXED_COUNT;
            using RunningCountField = Registers::TIMROT::TIMCOUNT0::RUNNING_COUNT;
        };
        template <>
        struct TimerTraits<1u> {
            using ControlReg = Registers::TIMROT::TIMCTRL1::Reg;
            using CountReg = Registers::TIMROT::TIMCOUNT1::Reg;
            using SelectField = Registers::TIMROT::TIMCTRL1::SELECT;
            using SelectValues = Registers::TIMROT::TIMCTRL1::SELECT_Values;
            using PrescaleField = Registers::TIMROT::TIMCTRL1::PRESCALE;
            using PrescaleValues = Registers::TIMROT::TIMCTRL1::PRESCALE_Values;
            using ReloadField = Registers::TIMROT::TIMCTRL1::RELOAD;
            using UpdateField = Registers::TIMROT::TIMCTRL1::UPDATE;
            using IrqEnableField = Registers::TIMROT::TIMCTRL1::IRQ_EN;
            using IrqField = Registers::TIMROT::TIMCTRL1::IRQ;
            using FixedCountField = Registers::TIMROT::TIMCOUNT1::FIXED_COUNT;
            using RunningCountField = Registers::TIMROT::TIMCOUNT1::RUNNING_COUNT;
        };
        template <>
        struct TimerTraits<2u> {
            using ControlReg = Registers::TIMROT::TIMCTRL2::Reg;
            using CountReg = Registers::TIMROT::TIMCOUNT2::Reg;
            using SelectField = Registers::TIMROT::TIMCTRL2::SELECT;
            using SelectValues = Registers::TIMROT::TIMCTRL2::SELECT_Values;
            using PrescaleField = Registers::TIMROT::TIMCTRL2::PRESCALE;
            using PrescaleValues = Registers::TIMROT::TIMCTRL2::PRESCALE_Values;
            using ReloadField = Registers::TIMROT::TIMCTRL2::RELOAD;
            using UpdateField = Registers::TIMROT::TIMCTRL2::UPDATE;
            using IrqEnableField = Registers::TIMROT::TIMCTRL2::IRQ_EN;
            using IrqField = Registers::TIMROT::TIMCTRL2::IRQ;
            using FixedCountField = Registers::TIMROT::TIMCOUNT2::FIXED_COUNT;
            using RunningCountField = Registers::TIMROT::TIMCOUNT2::RUNNING_COUNT;
        };
        template <>
        struct TimerTraits<3u> {
            using ControlReg = Registers::TIMROT::TIMCTRL3::Reg;
            using CountReg = Registers::TIMROT::TIMCOUNT3::Reg;
            using SelectField = Registers::TIMROT::TIMCTRL3::SELECT;
            using SelectValues = Registers::TIMROT::TIMCTRL3::SELECT_Values;
            using PrescaleField = Registers::TIMROT::TIMCTRL3::PRESCALE;
            using PrescaleValues = Registers::TIMROT::TIMCTRL3::PRESCALE_Values;
            using ReloadField = Registers::TIMROT::TIMCTRL3::RELOAD;
            using UpdateField = Registers::TIMROT::TIMCTRL3::UPDATE;
            using IrqEnableField = Registers::TIMROT::TIMCTRL3::IRQ_EN;
            using IrqField = Registers::TIMROT::TIMCTRL3::IRQ;
            using FixedCountField = Registers::TIMROT::TIMCOUNT3::FIXED_COUNT;
            using RunningCountField = Registers::TIMROT::TIMCOUNT3::RUNNING_COUNT;
        };

    } // namespace Detail

    /** @brief 定时器/旋钮(TIMROT)驱动:纯静态门面,无实例。 */
    struct TIMROT {
        TIMROT() = delete;
        ~TIMROT() = delete;
        TIMROT(const TIMROT&) = delete;
        TIMROT& operator=(const TIMROT&) = delete;

    private:
        using SoftReset = Registers::TIMROT::ROTCTRL::SFTRST;  /**< ROTCTRL.SFTRST 字段后端。 */
        using ClockGate = Registers::TIMROT::ROTCTRL::CLKGATE; /**< ROTCTRL.CLKGATE 字段后端。 */

    public:
        /** @brief TIMROT 内定时器个数(0–3)。 */
        static constexpr std::uint32_t TimerCount = 4u;

        // ====================== 模块级:复位 / 门控 ======================

        /** @brief 触发软复位:置 ROTCTRL.SFTRST(单条原子 str→SET)。 */
        [[gnu::always_inline]] static void AssertSoftReset() noexcept {
            Common::AssertSoftReset<SoftReset>();
        }

        /** @brief 退出软复位:清 ROTCTRL.SFTRST(单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DeassertSoftReset() noexcept {
            Common::DeassertSoftReset<SoftReset>();
        }

        /** @brief 非阻塞谓词:软复位是否仍被置位(ROTCTRL.SFTRST==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSoftResetAsserted() noexcept {
            return Common::IsSoftResetAsserted<SoftReset>();
        }

        /** @brief 使能 TIMROT 模块时钟(清 ROTCTRL.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 TIMROT 模块时钟(置 ROTCTRL.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(ROTCTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        /**
         * @brief 编译期固定定时器号的逐定时器门面(纯静态)。
         *
         * @tparam Index 定时器号(0–3),越界编译期报错。
         */
        template <std::uint32_t Index>
            requires(Index < TimerCount)
        struct Timer {
            Timer() = delete;
            ~Timer() = delete;
            Timer(const Timer&) = delete;
            Timer& operator=(const Timer&) = delete;

        private:
            using Traits = Detail::TimerTraits<Index>; /**< 本定时器的寄存器/字段/枚举映射。 */

        public:
            /** @brief 时钟源选择枚举(NEVER_TICK / PWM0–4 / ROTARYA-B / 各晶振分频 / TICK_ALWAYS)。 */
            using Source = typename Traits::SelectValues;
            /** @brief 预分频枚举(DIV_BY_1/2/4/8)。 */
            using Prescale = typename Traits::PrescaleValues;

            /**
             * @brief 设置重载初值(写 TIMCOUNT{n}.FIXED_COUNT)。倒计数归零后据此重装(需 RELOAD)。
             * @param reloadValue 16 位重载初值。
             */
            [[gnu::always_inline]] static void SetReloadValue(std::uint32_t reloadValue) noexcept {
                Traits::CountReg::template WriteField<typename Traits::FixedCountField>(reloadValue);
            }

            /**
             * @brief 读取当前递减计数值(读 TIMCOUNT{n}.RUNNING_COUNT)。
             * @return 16 位当前计数。
             */
            [[gnu::always_inline]] [[nodiscard]] static std::uint32_t CurrentCount() noexcept {
                return Traits::CountReg::template ReadField<typename Traits::RunningCountField>();
            }

            /**
             * @brief 配置为周期性倒计数定时器:设重载值,再一次 RMW 写控制寄存器并启动。
             *
             * 控制位一次性写入 SELECT/PRESCALE/RELOAD=1/UPDATE=1/IRQ_EN(合并 RMW),写 UPDATE
             * 触发计数器加载并使能。中断标志(IRQ,bit15)不在写掩码内,由 AcknowledgeInterrupt 清。
             * @param source          时钟源。
             * @param prescale        预分频。
             * @param reloadValue     16 位重载初值(决定周期)。
             * @param enableInterrupt 是否使能计数到零中断。
             */
            [[gnu::always_inline]] static void ConfigurePeriodic(Source source, Prescale prescale,
                                                                 std::uint32_t reloadValue,
                                                                 bool enableInterrupt) noexcept {
                SetReloadValue(reloadValue);
                Traits::ControlReg::template WriteFields<
                    typename Traits::SelectField, typename Traits::PrescaleField,
                    typename Traits::ReloadField, typename Traits::UpdateField,
                    typename Traits::IrqEnableField>(source, prescale, 1u, 1u,
                                                     enableInterrupt ? 1u : 0u);
            }

            /**
             * @brief 选择时钟源(写 SELECT 字段)。设为 Source::NEVER_TICK 即停表。
             * @param source 时钟源。
             */
            [[gnu::always_inline]] static void SelectSource(Source source) noexcept {
                Traits::ControlReg::template WriteField<typename Traits::SelectField>(source);
            }

            /** @brief 停止计数(SELECT 置 NEVER_TICK)。 */
            [[gnu::always_inline]] static void Stop() noexcept {
                SelectSource(Source::NEVER_TICK);
            }

            /** @brief 使能计数到零中断(置 IRQ_EN,单条原子 str→SET)。 */
            [[gnu::always_inline]] static void EnableInterrupt() noexcept {
                Traits::ControlReg::template SetField<typename Traits::IrqEnableField>();
            }

            /** @brief 关闭计数到零中断(清 IRQ_EN,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void DisableInterrupt() noexcept {
                Traits::ControlReg::template ClearField<typename Traits::IrqEnableField>();
            }

            /**
             * @brief 中断标志是否已置(读 IRQ 位)。
             * @return 计数到零后返回 true。
             */
            [[gnu::always_inline]] [[nodiscard]] static bool IsInterruptPending() noexcept {
                return Traits::ControlReg::template FieldIsSet<typename Traits::IrqField>();
            }

            /** @brief 清除中断标志(清 IRQ 位,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void AcknowledgeInterrupt() noexcept {
                Traits::ControlReg::template ClearField<typename Traits::IrqField>();
            }
        };
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_TIMROT
