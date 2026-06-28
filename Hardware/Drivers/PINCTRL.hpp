#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_PINCTRL
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_PINCTRL

/**
 * @file PINCTRL.hpp
 * @brief 引脚控制器(PINCTRL)模块级驱动:软复位与时钟门控(纯静态单例门面)。
 *
 * 本头只负责 PINCTRL 模块整体的复位/上电(CTRL.SFTRST / CTRL.CLKGATE),逐引脚的复用、
 * 方向、读写在 GPIO.hpp 的参数化门面 GPIO<Bank, Pin> 中。bring-up 时序:先复位/使能
 * PINCTRL 模块,再用 GPIO<> 配置各引脚。
 *
 * 复位时序(清 SFTRST→等→清 CLKGATE→置 SFTRST→清 SFTRST→等→清 CLKGATE→等)所需的
 * 单步原语与非阻塞谓词由 Common::{AssertSoftReset,DeassertSoftReset,IsSoftResetAsserted,
 * EnableClock,DisableClock,IsClockGated} 提供,**节拍编排上移 OS**,本层不自旋。
 *
 * @note 寄存器/字段取自生成头 Registers/PINCTRL.hpp,绝不硬编码地址。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/PINCTRL.hpp"

namespace Hardware::Drivers {

    /** @brief 引脚控制器(PINCTRL)模块级驱动:纯静态门面,无实例。 */
    struct PINCTRL {
        PINCTRL() = delete;
        ~PINCTRL() = delete;
        PINCTRL(const PINCTRL&) = delete;
        PINCTRL& operator=(const PINCTRL&) = delete;

    private:
        using SoftReset = Registers::PINCTRL::CTRL::SFTRST;  /**< CTRL.SFTRST 字段后端。 */
        using ClockGate = Registers::PINCTRL::CTRL::CLKGATE; /**< CTRL.CLKGATE 字段后端。 */

    public:
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

        /** @brief 使能 PINCTRL 模块时钟(清 CTRL.CLKGATE,单条原子 str)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 PINCTRL 模块时钟(置 CTRL.CLKGATE,单条原子 str),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_PINCTRL
