#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_PWM
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_PWM

/**
 * @file PWM.hpp
 * @brief 脉宽调制(PWM)驱动:模块复位/门控 + 编译期参数化的逐通道门面 Channel<Index>。
 *
 * STMP3770/i.MX23 的 PWM 含 5 路通道(0–4),各有一对寄存器:
 *  - ACTIVE{n}:有效计数 ACTIVE[0,16] 与无效计数 INACTIVE[16,16](单位:分频后时钟);
 *  - PERIOD{n}:周期 PERIOD[0,16](周期 = PERIOD+1 个分频时钟)、有效/无效态电平
 *    ACTIVE_STATE/INACTIVE_STATE、时钟分频 CDIV;
 * 通道使能位 PWM{n}_ENABLE 集中在 CTRL,模块软复位/门控在 CTRL.SFTRST/CLKGATE。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * 占空比 = ACTIVE / (ACTIVE + INACTIVE);典型背光用法(通道 2,1/2 占空):
 *   `PWM::DeassertSoftReset(); PWM::EnableClock();`
 *   `using Backlight = PWM::Channel<2>;`
 *   `Backlight::Configure(period, period/2, Backlight::ClockDivider::DIV_1,`
 *   `                     Backlight::ActiveState::_1, Backlight::InactiveState::_0);`
 *   `Backlight::Enable();`
 *
 * 命名空间 ACTIVE{n}/PERIOD{n} 无法被模板整数参数化,故用 Detail::PwmChannelTraits<n> 的
 * **手写显式特化**把"通道号 → 该通道的寄存器/字段/枚举别名"在编译期固定。
 *
 * @note 寄存器/字段取自生成头 Registers/PWM.hpp,复位原语复用 Common::{AssertSoftReset,…};
 *       复位序列节拍上移 OS,本层只给触发 + 谓词。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/PWM.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    namespace Detail {

        /**
         * @brief PWM 通道号 → 该通道寄存器/字段/枚举别名的映射(主模板未定义)。
         *
         * 仅对 0–4 提供**手写显式特化**(原先由局部宏批量生成,现按"禁止函数式宏"展开为
         * 逐通道特化列表);非法通道号实例化将因主模板不完整而编译失败。
         * @tparam Index 通道号(0–4)。
         */
        template <std::uint32_t Index>
        struct PwmChannelTraits;

        template <>
        struct PwmChannelTraits<0u> {
            using ActiveReg = Registers::PWM::ACTIVE0::Reg;
            using ActiveField = Registers::PWM::ACTIVE0::ACTIVE;
            using InactiveField = Registers::PWM::ACTIVE0::INACTIVE;
            using PeriodReg = Registers::PWM::PERIOD0::Reg;
            using PeriodField = Registers::PWM::PERIOD0::PERIOD;
            using ActiveStateField = Registers::PWM::PERIOD0::ACTIVE_STATE;
            using ActiveStateValues = Registers::PWM::PERIOD0::ACTIVE_STATE_Values;
            using InactiveStateField = Registers::PWM::PERIOD0::INACTIVE_STATE;
            using InactiveStateValues = Registers::PWM::PERIOD0::INACTIVE_STATE_Values;
            using DividerField = Registers::PWM::PERIOD0::CDIV;
            using DividerValues = Registers::PWM::PERIOD0::CDIV_Values;
            using EnableField = Registers::PWM::CTRL::PWM0_ENABLE;
        };
        template <>
        struct PwmChannelTraits<1u> {
            using ActiveReg = Registers::PWM::ACTIVE1::Reg;
            using ActiveField = Registers::PWM::ACTIVE1::ACTIVE;
            using InactiveField = Registers::PWM::ACTIVE1::INACTIVE;
            using PeriodReg = Registers::PWM::PERIOD1::Reg;
            using PeriodField = Registers::PWM::PERIOD1::PERIOD;
            using ActiveStateField = Registers::PWM::PERIOD1::ACTIVE_STATE;
            using ActiveStateValues = Registers::PWM::PERIOD1::ACTIVE_STATE_Values;
            using InactiveStateField = Registers::PWM::PERIOD1::INACTIVE_STATE;
            using InactiveStateValues = Registers::PWM::PERIOD1::INACTIVE_STATE_Values;
            using DividerField = Registers::PWM::PERIOD1::CDIV;
            using DividerValues = Registers::PWM::PERIOD1::CDIV_Values;
            using EnableField = Registers::PWM::CTRL::PWM1_ENABLE;
        };
        template <>
        struct PwmChannelTraits<2u> {
            using ActiveReg = Registers::PWM::ACTIVE2::Reg;
            using ActiveField = Registers::PWM::ACTIVE2::ACTIVE;
            using InactiveField = Registers::PWM::ACTIVE2::INACTIVE;
            using PeriodReg = Registers::PWM::PERIOD2::Reg;
            using PeriodField = Registers::PWM::PERIOD2::PERIOD;
            using ActiveStateField = Registers::PWM::PERIOD2::ACTIVE_STATE;
            using ActiveStateValues = Registers::PWM::PERIOD2::ACTIVE_STATE_Values;
            using InactiveStateField = Registers::PWM::PERIOD2::INACTIVE_STATE;
            using InactiveStateValues = Registers::PWM::PERIOD2::INACTIVE_STATE_Values;
            using DividerField = Registers::PWM::PERIOD2::CDIV;
            using DividerValues = Registers::PWM::PERIOD2::CDIV_Values;
            using EnableField = Registers::PWM::CTRL::PWM2_ENABLE;
        };
        template <>
        struct PwmChannelTraits<3u> {
            using ActiveReg = Registers::PWM::ACTIVE3::Reg;
            using ActiveField = Registers::PWM::ACTIVE3::ACTIVE;
            using InactiveField = Registers::PWM::ACTIVE3::INACTIVE;
            using PeriodReg = Registers::PWM::PERIOD3::Reg;
            using PeriodField = Registers::PWM::PERIOD3::PERIOD;
            using ActiveStateField = Registers::PWM::PERIOD3::ACTIVE_STATE;
            using ActiveStateValues = Registers::PWM::PERIOD3::ACTIVE_STATE_Values;
            using InactiveStateField = Registers::PWM::PERIOD3::INACTIVE_STATE;
            using InactiveStateValues = Registers::PWM::PERIOD3::INACTIVE_STATE_Values;
            using DividerField = Registers::PWM::PERIOD3::CDIV;
            using DividerValues = Registers::PWM::PERIOD3::CDIV_Values;
            using EnableField = Registers::PWM::CTRL::PWM3_ENABLE;
        };
        template <>
        struct PwmChannelTraits<4u> {
            using ActiveReg = Registers::PWM::ACTIVE4::Reg;
            using ActiveField = Registers::PWM::ACTIVE4::ACTIVE;
            using InactiveField = Registers::PWM::ACTIVE4::INACTIVE;
            using PeriodReg = Registers::PWM::PERIOD4::Reg;
            using PeriodField = Registers::PWM::PERIOD4::PERIOD;
            using ActiveStateField = Registers::PWM::PERIOD4::ACTIVE_STATE;
            using ActiveStateValues = Registers::PWM::PERIOD4::ACTIVE_STATE_Values;
            using InactiveStateField = Registers::PWM::PERIOD4::INACTIVE_STATE;
            using InactiveStateValues = Registers::PWM::PERIOD4::INACTIVE_STATE_Values;
            using DividerField = Registers::PWM::PERIOD4::CDIV;
            using DividerValues = Registers::PWM::PERIOD4::CDIV_Values;
            using EnableField = Registers::PWM::CTRL::PWM4_ENABLE;
        };

    } // namespace Detail

    /** @brief 脉宽调制(PWM)驱动:纯静态门面,无实例。 */
    struct PWM {
        PWM() = delete;
        ~PWM() = delete;
        PWM(const PWM&) = delete;
        PWM& operator=(const PWM&) = delete;

    private:
        using ControlRegister = Registers::PWM::CTRL::Reg;     /**< 主控制寄存器(复位/门控/逐通道使能)。 */
        using SoftReset = Registers::PWM::CTRL::SFTRST;        /**< CTRL.SFTRST 字段后端。 */
        using ClockGate = Registers::PWM::CTRL::CLKGATE;       /**< CTRL.CLKGATE 字段后端。 */

    public:
        /** @brief PWM 通道个数(0–4)。 */
        static constexpr std::uint32_t ChannelCount = 5u;

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

        /** @brief 使能 PWM 模块时钟(清 CTRL.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 PWM 模块时钟(置 CTRL.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        /**
         * @brief 编译期固定通道号的逐通道门面(纯静态)。
         *
         * @tparam Index 通道号(0–4),越界编译期报错。
         */
        template <std::uint32_t Index>
            requires(Index < ChannelCount)
        struct Channel {
            Channel() = delete;
            ~Channel() = delete;
            Channel(const Channel&) = delete;
            Channel& operator=(const Channel&) = delete;

        private:
            using Traits = Detail::PwmChannelTraits<Index>; /**< 本通道的寄存器/字段/枚举映射。 */

        public:
            /** @brief 有效态输出电平(HI_Z=高阻、_0=低、_1=高)。 */
            using ActiveState = typename Traits::ActiveStateValues;
            /** @brief 无效态输出电平(HI_Z=高阻、_0=低、_1=高)。 */
            using InactiveState = typename Traits::InactiveStateValues;
            /** @brief 时钟分频比(DIV_1/2/4/8/16/64/256/1024)。 */
            using ClockDivider = typename Traits::DividerValues;

            /**
             * @brief 设置有效/无效计数(写 ACTIVE{n} 的 ACTIVE/INACTIVE,一次 RMW)。
             * @param activeCount   有效计数(决定高/有效时长)。
             * @param inactiveCount 无效计数(决定低/无效时长)。
             */
            [[gnu::always_inline]] static void SetActiveInactive(std::uint32_t activeCount,
                                                                std::uint32_t inactiveCount) noexcept {
                Traits::ActiveReg::template WriteFields<typename Traits::ActiveField,
                                                        typename Traits::InactiveField>(activeCount,
                                                                                        inactiveCount);
            }

            /**
             * @brief 设置周期/电平态/分频(写 PERIOD{n} 的 PERIOD/ACTIVE_STATE/INACTIVE_STATE/CDIV,一次 RMW)。
             * @param period        周期计数(周期 = period+1 个分频时钟)。
             * @param activeState   有效态电平。
             * @param inactiveState 无效态电平。
             * @param clockDivider  时钟分频比。
             */
            [[gnu::always_inline]] static void SetPeriod(std::uint32_t period, ActiveState activeState,
                                                        InactiveState inactiveState,
                                                        ClockDivider clockDivider) noexcept {
                Traits::PeriodReg::template WriteFields<
                    typename Traits::PeriodField, typename Traits::ActiveStateField,
                    typename Traits::InactiveStateField, typename Traits::DividerField>(
                    period, activeState, inactiveState, clockDivider);
            }

            /**
             * @brief 一次性配置通道(设有效/无效计数 + 周期/电平/分频),不含使能。
             * @param activeCount   有效计数。
             * @param period        周期计数(应 ≥ activeCount)。
             * @param clockDivider  时钟分频比。
             * @param activeState   有效态电平(默认高)。
             * @param inactiveState 无效态电平(默认低)。
             */
            [[gnu::always_inline]] static void Configure(std::uint32_t activeCount, std::uint32_t period,
                                                        ClockDivider clockDivider,
                                                        ActiveState activeState = ActiveState::_1,
                                                        InactiveState inactiveState = InactiveState::_0) noexcept {
                SetActiveInactive(activeCount, period);
                SetPeriod(period, activeState, inactiveState, clockDivider);
            }

            /** @brief 使能本通道开始循环(置 CTRL.PWM{n}_ENABLE,单条原子 str→SET)。 */
            [[gnu::always_inline]] static void Enable() noexcept {
                ControlRegister::template SetField<typename Traits::EnableField>();
            }

            /** @brief 停止本通道(清 CTRL.PWM{n}_ENABLE,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void Disable() noexcept {
                ControlRegister::template ClearField<typename Traits::EnableField>();
            }
        };
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_PWM
