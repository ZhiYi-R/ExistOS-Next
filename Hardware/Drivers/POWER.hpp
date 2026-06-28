#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_POWER
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_POWER

/**
 * @file POWER.hpp
 * @brief 电源管理单元(POWER)驱动:时钟门控、电源/电池状态查询、充电控制、电池监测与软关机。
 *
 * STMP3770/i.MX23 的 POWER 集成 DC-DC、各域 LDO、电池充电器与监测、PSWITCH 检测。注意其
 * CTRL 只有 CLKGATE(Bit30)而**无 SFTRST**,故本驱动不提供软复位原语;整模块软关机改用
 * RESET 寄存器:须先写 UNLOCK 密钥 0x3E77 再置 PWD。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。电池电压
 * 由 LRADC 采样,BATTMONITOR.BATT_VAL 为固件回写的 10 位结果(单位 8mV),实际换算系数置于板级 BSP。
 *
 * @note 寄存器/字段取自生成头 Registers/POWER.hpp,绝不硬编码地址。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/POWER.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    /** @brief 电源管理单元(POWER)驱动:纯静态门面,无实例。 */
    struct POWER {
        POWER() = delete;
        ~POWER() = delete;
        POWER(const POWER&) = delete;
        POWER& operator=(const POWER&) = delete;

    private:
        using StatusRegister = Registers::POWER::STS::Reg;             /**< 电源/电池状态寄存器。 */
        using BatteryMonitorRegister = Registers::POWER::BATTMONITOR::Reg; /**< 电池监测寄存器。 */
        using ChargeRegister = Registers::POWER::CHARGE::Reg;          /**< 充电控制寄存器。 */
        using ResetRegister = Registers::POWER::RESET::Reg;            /**< 软关机寄存器(含 UNLOCK 密钥)。 */
        using ClockGate = Registers::POWER::CTRL::CLKGATE;             /**< CTRL.CLKGATE 字段后端。 */

    public:
        // ====================== 时钟门控 ======================

        /** @brief 使能 POWER 模块时钟(清 CTRL.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 POWER 模块时钟(置 CTRL.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        // ====================== 电源 / 电池状态查询(读 STS) ======================

        /** @brief 5V/VBUS 是否有效(读 STS.VBUSVALID),用于检测 USB/外部供电接入。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsVbusValid() noexcept {
            return StatusRegister::template FieldIsSet<Registers::POWER::STS::VBUSVALID>();
        }

        /** @brief DC-DC 是否工作正常(读 STS.DC_OK)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsDcDcOk() noexcept {
            return StatusRegister::template FieldIsSet<Registers::POWER::STS::DC_OK>();
        }

        /** @brief 电池是否处于欠压(读 STS.BATT_BO)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsBatteryBrownout() noexcept {
            return StatusRegister::template FieldIsSet<Registers::POWER::STS::BATT_BO>();
        }

        /** @brief 是否检测到充电器(读 STS.BATT_CHRG_PRESENT)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsBatteryChargerPresent() noexcept {
            return StatusRegister::template FieldIsSet<Registers::POWER::STS::BATT_CHRG_PRESENT>();
        }

        /** @brief 是否正在充电(读 STS.CHRGSTS)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsCharging() noexcept {
            return StatusRegister::template FieldIsSet<Registers::POWER::STS::CHRGSTS>();
        }

        /**
         * @brief 读取 PSWITCH 电源键状态(读 STS.PSWITCH,2 位)。
         * @return 2 位 PSWITCH 状态(具体编码见生成头)。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadPowerSwitch() noexcept {
            return StatusRegister::template ReadField<Registers::POWER::STS::PSWITCH>();
        }

        // ====================== 电池监测(BATTMONITOR) ======================

        /**
         * @brief 读取电池电压原始值(读 BATTMONITOR.BATT_VAL,10 位,单位 8mV)。
         *
         * 该字段由固件用 LRADC 采样后回写;返回原始码,换算为电压由板级常量完成。
         * @return 10 位电池电压码。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadBatteryVoltageRaw() noexcept {
            return BatteryMonitorRegister::template ReadField<Registers::POWER::BATTMONITOR::BATT_VAL>();
        }

        /**
         * @brief 回写电池电压原始码(写 BATTMONITOR.BATT_VAL),供欠压比较使用。
         * @param raw 10 位电池电压码(单位 8mV)。
         */
        [[gnu::always_inline]] static void WriteBatteryVoltageRaw(std::uint32_t raw) noexcept {
            BatteryMonitorRegister::template WriteField<Registers::POWER::BATTMONITOR::BATT_VAL>(raw);
        }

        /**
         * @brief 设置电池欠压检测电平(写 BATTMONITOR.BRWNOUT_LVL,4 位档位)。
         * @param level 4 位欠压电平档位。
         */
        [[gnu::always_inline]] static void SetBatteryBrownoutLevel(std::uint32_t level) noexcept {
            BatteryMonitorRegister::template WriteField<Registers::POWER::BATTMONITOR::BRWNOUT_LVL>(level);
        }

        // ====================== 充电控制(CHARGE) ======================

        /**
         * @brief 设置充电电流码(写 CHARGE.BATTCHRG_I,6 位)。
         * @param currentCode 6 位充电电流设置值。
         */
        [[gnu::always_inline]] static void SetChargeCurrent(std::uint32_t currentCode) noexcept {
            ChargeRegister::template WriteField<Registers::POWER::CHARGE::BATTCHRG_I>(currentCode);
        }

        /**
         * @brief 设置充电终止电流阈值码(写 CHARGE.STOP_ILIMIT,4 位)。
         * @param thresholdCode 4 位终止电流阈值。
         */
        [[gnu::always_inline]] static void SetChargeStopThreshold(std::uint32_t thresholdCode) noexcept {
            ChargeRegister::template WriteField<Registers::POWER::CHARGE::STOP_ILIMIT>(thresholdCode);
        }

        /** @brief 使能电池充电器(清 CHARGE.PWD_BATTCHRG,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void EnableCharger() noexcept {
            ChargeRegister::template ClearField<Registers::POWER::CHARGE::PWD_BATTCHRG>();
        }

        /** @brief 关闭电池充电器(置 CHARGE.PWD_BATTCHRG,单条原子 str→SET)。 */
        [[gnu::always_inline]] static void DisableCharger() noexcept {
            ChargeRegister::template SetField<Registers::POWER::CHARGE::PWD_BATTCHRG>();
        }

        // ====================== 软关机(RESET,需解锁密钥) ======================

        /**
         * @brief 整机软关机:写 RESET,带 UNLOCK 密钥 0x3E77 并置 PWD,一次 RMW 完成。
         *
         * RESET.PWD 受 UNLOCK 密钥保护,须同写 UNLOCK=KEY 才生效;本函数一次写入二者后芯片下电。
         * 调用后系统断电,不再返回。
         */
        [[gnu::always_inline]] static void PowerOff() noexcept {
            ResetRegister::template WriteFields<Registers::POWER::RESET::UNLOCK,
                                                Registers::POWER::RESET::PWD>(
                Registers::POWER::RESET::UNLOCK_Values::KEY, 1u);
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_POWER
