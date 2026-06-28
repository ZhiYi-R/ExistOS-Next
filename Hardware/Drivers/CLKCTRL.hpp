#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_CLKCTRL
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_CLKCTRL

/**
 * @file CLKCTRL.hpp
 * @brief 时钟控制器(CLKCTRL)驱动:PLL 上电/锁定、各域整数与分数分频、选源旁路、外设时钟门控。
 *
 * STMP3770/i.MX23 的时钟树以 480MHz PLL 与 24MHz 晶振为两大源:
 *  - PLL:PLLCTRL0.POWER 上电,PLLCTRL1.LOCK 指示锁定。
 *  - 各时钟域(CPU/HBUS/XBUS/PIX/SSP/GPMI/EMI…)各有一个整数分频寄存器,含 DIV 与
 *    更新中的 BUSY 标志;PIX/SSP/GPMI/EMI 等自带 CLKGATE 门控位。
 *  - FRAC 提供 CPU/PIX/IO 三路分数分频(CPUFRAC/PIXFRAC/IOFRAC),各有 *_STABLE 稳定
 *    标志与 CLKGATE* 门控。
 *  - CLKSEQ 的 BYPASS_* 位逐域选择"PLL/分数源(0)"还是"旁路到 24MHz 晶振(1)"。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。提供两层接口:
 *  - 通用模板(对字段类型参数化):任意域的分频/门控/选源一行复用;
 *  - 具名包装:HP39GII bring-up 实际用到的 CPU/HBUS/PIX/GPMI/EMI 等。
 * 门控逻辑复用 Common::EnableClock/DisableClock(带别名后端单条原子 str),不重复书写。
 *
 * 分频/上电均拆为"触发动作 + 非阻塞谓词":置位/写值是单步触发,锁定/稳定/BUSY 由谓词查询,
 * **轮询节拍编排上移 OS**(未来以 TIMROT 计时),本层不自旋。
 *
 * @note 所有寄存器/字段均取自生成头 Registers/CLKCTRL.hpp,绝不硬编码地址。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/CLKCTRL.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    /** @brief 时钟控制器(CLKCTRL)驱动:纯静态门面,无实例。 */
    struct CLKCTRL {
        CLKCTRL() = delete;
        ~CLKCTRL() = delete;
        CLKCTRL(const CLKCTRL&) = delete;
        CLKCTRL& operator=(const CLKCTRL&) = delete;

    private:
        using PllControl0 = Registers::CLKCTRL::PLLCTRL0::Reg;  /**< PLL 上电控制寄存器。 */
        using PllControl1 = Registers::CLKCTRL::PLLCTRL1::Reg;  /**< PLL 锁定状态寄存器。 */
        using ClockSequence = Registers::CLKCTRL::CLKSEQ::Reg;  /**< 逐域选源(BYPASS_*)寄存器。 */

    public:
        // ====================== PLL ======================

        /**
         * @brief PLL 是否已锁定(读 PLLCTRL1.LOCK)。
         * @return 锁定返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool IsPllLocked() noexcept {
            return PllControl1::template FieldIsSet<Registers::CLKCTRL::PLLCTRL1::LOCK>();
        }

        /**
         * @brief 给 PLL 上电(置 PLLCTRL0.POWER,单条原子 str)。
         *
         * 仅触发上电;锁定与否由 IsPllLocked() 谓词查询,等待节拍上移 OS,本层不自旋。
         */
        [[gnu::always_inline]] static void PowerOnPll() noexcept {
            PllControl0::template SetField<Registers::CLKCTRL::PLLCTRL0::POWER>();
        }

        /**
         * @brief 给 PLL 断电(清 PLLCTRL0.POWER,单条原子 str)。仅在确无时钟域依赖 PLL 时调用。
         */
        [[gnu::always_inline]] static void PowerOffPll() noexcept {
            PllControl0::template ClearField<Registers::CLKCTRL::PLLCTRL0::POWER>();
        }

        // ====================== 通用原语(对字段类型参数化) ======================

        /**
         * @brief 使能某外设时钟(清其 CLKGATE 字段)。
         * @tparam ClockGateField 该域时钟寄存器的 CLKGATE 字段别名。
         */
        template <typename ClockGateField>
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGateField>();
        }

        /**
         * @brief 关断某外设时钟(置其 CLKGATE 字段),用于低功耗。
         * @tparam ClockGateField 该域时钟寄存器的 CLKGATE 字段别名。
         */
        template <typename ClockGateField>
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGateField>();
        }

        /**
         * @brief 非阻塞谓词:某外设时钟是否被门控(其 CLKGATE 字段==1)。
         * @tparam ClockGateField 该域时钟寄存器的 CLKGATE 字段别名。
         */
        template <typename ClockGateField>
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGateField>();
        }

        /**
         * @brief 非阻塞谓词:某域分频器是否仍在更新中(其 BUSY 字段==1)。
         * @tparam BusyField 该域时钟寄存器的 BUSY 字段别名。
         * @return 仍在更新返回 true;已生效返回 false。
         */
        template <typename BusyField>
        [[gnu::always_inline]] [[nodiscard]] static bool IsDividerBusy() noexcept {
            using DividerRegister = typename BusyField::BackendType;
            return DividerRegister::template FieldIsSet<BusyField>();
        }

        /**
         * @brief 触发设置某域整数分频值(以非原子 RMW 写 DIV 字段,配置期非热路径)。
         *
         * 仅触发;生效与否由 IsDividerBusy<BusyField>() 谓词查询,等待节拍上移 OS。
         * @tparam DivisorField 该域 DIV 字段别名。
         * @param divisor       整数分频值。
         */
        template <typename DivisorField>
        [[gnu::always_inline]] static void SetIntegerDivider(typename DivisorField::ValueType divisor) noexcept {
            using DividerRegister = typename DivisorField::BackendType;
            DividerRegister::template WriteField<DivisorField>(divisor);
        }

        /**
         * @brief 触发设置一路分数分频值(写 6 位 FRAC 字段)。
         *
         * 仅触发;稳定与否由 IsFractionalStable<StableField>() 谓词查询,等待节拍上移 OS。
         * @tparam FractionField 分数分频字段别名(CPUFRAC/PIXFRAC/IOFRAC)。
         * @param fraction       6 位分数分频值。
         */
        template <typename FractionField>
        [[gnu::always_inline]] static void SetFractionalDivider(typename FractionField::ValueType fraction) noexcept {
            using FractionRegister = typename FractionField::BackendType;
            FractionRegister::template WriteField<FractionField>(fraction);
        }

        /**
         * @brief 非阻塞谓词:某路分数分频是否已稳定(其 *_STABLE 字段==1)。
         * @tparam StableField 对应的 *_STABLE 稳定标志字段别名。
         */
        template <typename StableField>
        [[gnu::always_inline]] [[nodiscard]] static bool IsFractionalStable() noexcept {
            using FractionRegister = typename StableField::BackendType;
            return FractionRegister::template FieldIsSet<StableField>();
        }

        /**
         * @brief 选择某域时钟源为 PLL/分数源(清 CLKSEQ 对应 BYPASS 位)。
         * @tparam BypassField CLKSEQ 中该域的 BYPASS_* 字段别名。
         */
        template <typename BypassField>
        [[gnu::always_inline]] static void SelectPllSource() noexcept {
            ClockSequence::template ClearField<BypassField>();
        }

        /**
         * @brief 选择某域时钟源为 24MHz 晶振旁路(置 CLKSEQ 对应 BYPASS 位)。
         * @tparam BypassField CLKSEQ 中该域的 BYPASS_* 字段别名。
         */
        template <typename BypassField>
        [[gnu::always_inline]] static void SelectCrystalSource() noexcept {
            ClockSequence::template SetField<BypassField>();
        }

        // ====================== 具名整数分频包装(触发 + 谓词) ======================

        /** @brief 触发设置 CPU 参考路径整数分频(DIV_CPU)。 */
        [[gnu::always_inline]] static void SetCpuDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::CPU::DIV_CPU>(divisor);
        }
        /** @brief 非阻塞谓词:CPU 分频是否仍在更新(BUSY_REF_CPU==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsCpuDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::CPU::BUSY_REF_CPU>();
        }

        /** @brief 触发设置 AHB 总线整数分频(HBUS.DIV)。 */
        [[gnu::always_inline]] static void SetHBusDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::HBUS::DIV>(divisor);
        }
        /** @brief 非阻塞谓词:HBUS 分频是否仍在更新(HBUS.BUSY==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsHBusDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::HBUS::BUSY>();
        }

        /** @brief 触发设置 APBX 总线整数分频(XBUS.DIV)。 */
        [[gnu::always_inline]] static void SetXBusDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::XBUS::DIV>(divisor);
        }
        /** @brief 非阻塞谓词:XBUS 分频是否仍在更新(XBUS.BUSY==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsXBusDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::XBUS::BUSY>();
        }

        /** @brief 触发设置 LCDIF 像素时钟整数分频(PIX.DIV)。 */
        [[gnu::always_inline]] static void SetPixDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::PIX::DIV>(divisor);
        }
        /** @brief 非阻塞谓词:PIX 分频是否仍在更新(PIX.BUSY==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsPixDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::PIX::BUSY>();
        }

        /** @brief 触发设置 GPMI 时钟整数分频(GPMI.DIV)。 */
        [[gnu::always_inline]] static void SetGpmiDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::GPMI::DIV>(divisor);
        }
        /** @brief 非阻塞谓词:GPMI 分频是否仍在更新(GPMI.BUSY==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsGpmiDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::GPMI::BUSY>();
        }

        /** @brief 触发设置 SSP 时钟整数分频(SSP.DIV)。 */
        [[gnu::always_inline]] static void SetSspDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::SSP::DIV>(divisor);
        }
        /** @brief 非阻塞谓词:SSP 分频是否仍在更新(SSP.BUSY==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSspDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::SSP::BUSY>();
        }

        /** @brief 触发设置 EMI 时钟整数分频(EMI.DIV_EMI)。 */
        [[gnu::always_inline]] static void SetEmiDivider(std::uint32_t divisor) noexcept {
            SetIntegerDivider<Registers::CLKCTRL::EMI::DIV_EMI>(divisor);
        }
        /** @brief 非阻塞谓词:EMI 分频是否仍在更新(EMI.BUSY_REF_EMI==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsEmiDividerBusy() noexcept {
            return IsDividerBusy<Registers::CLKCTRL::EMI::BUSY_REF_EMI>();
        }

        // ====================== 具名分数分频包装(触发 + 谓词) ======================

        /** @brief 触发设置 CPU 分数分频(FRAC.CPUFRAC)。 */
        [[gnu::always_inline]] static void SetCpuFractionalDivider(std::uint32_t fraction) noexcept {
            SetFractionalDivider<Registers::CLKCTRL::FRAC::CPUFRAC>(fraction);
        }
        /** @brief 非阻塞谓词:CPU 分数分频是否已稳定(FRAC.CPU_STABLE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsCpuFractionalStable() noexcept {
            return IsFractionalStable<Registers::CLKCTRL::FRAC::CPU_STABLE>();
        }

        /** @brief 触发设置 PIX 分数分频(FRAC.PIXFRAC)。 */
        [[gnu::always_inline]] static void SetPixFractionalDivider(std::uint32_t fraction) noexcept {
            SetFractionalDivider<Registers::CLKCTRL::FRAC::PIXFRAC>(fraction);
        }
        /** @brief 非阻塞谓词:PIX 分数分频是否已稳定(FRAC.PIX_STABLE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsPixFractionalStable() noexcept {
            return IsFractionalStable<Registers::CLKCTRL::FRAC::PIX_STABLE>();
        }

        /** @brief 触发设置 IO 分数分频(FRAC.IOFRAC)。 */
        [[gnu::always_inline]] static void SetIoFractionalDivider(std::uint32_t fraction) noexcept {
            SetFractionalDivider<Registers::CLKCTRL::FRAC::IOFRAC>(fraction);
        }
        /** @brief 非阻塞谓词:IO 分数分频是否已稳定(FRAC.IO_STABLE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsIoFractionalStable() noexcept {
            return IsFractionalStable<Registers::CLKCTRL::FRAC::IO_STABLE>();
        }

        /** @brief 使能 CPU 分数时钟输出(清 FRAC.CLKGATECPU)。 */
        [[gnu::always_inline]] static void EnableCpuFractionalClock() noexcept {
            Common::EnableClock<Registers::CLKCTRL::FRAC::CLKGATECPU>();
        }

        /** @brief 使能 PIX 分数时钟输出(清 FRAC.CLKGATEPIX)。 */
        [[gnu::always_inline]] static void EnablePixFractionalClock() noexcept {
            Common::EnableClock<Registers::CLKCTRL::FRAC::CLKGATEPIX>();
        }

        /** @brief 使能 IO 分数时钟输出(清 FRAC.CLKGATEIO)。 */
        [[gnu::always_inline]] static void EnableIoFractionalClock() noexcept {
            Common::EnableClock<Registers::CLKCTRL::FRAC::CLKGATEIO>();
        }

        // ====================== 具名外设门控包装 ======================

        /** @brief 使能 LCDIF 像素时钟(清 PIX.CLKGATE)。 */
        [[gnu::always_inline]] static void EnablePixClock() noexcept { Common::EnableClock<Registers::CLKCTRL::PIX::CLKGATE>(); }
        /** @brief 关断 LCDIF 像素时钟(置 PIX.CLKGATE)。 */
        [[gnu::always_inline]] static void DisablePixClock() noexcept { Common::DisableClock<Registers::CLKCTRL::PIX::CLKGATE>(); }

        /** @brief 使能 GPMI 时钟(清 GPMI.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableGpmiClock() noexcept { Common::EnableClock<Registers::CLKCTRL::GPMI::CLKGATE>(); }
        /** @brief 关断 GPMI 时钟(置 GPMI.CLKGATE)。 */
        [[gnu::always_inline]] static void DisableGpmiClock() noexcept { Common::DisableClock<Registers::CLKCTRL::GPMI::CLKGATE>(); }

        /** @brief 使能 SSP 时钟(清 SSP.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableSspClock() noexcept { Common::EnableClock<Registers::CLKCTRL::SSP::CLKGATE>(); }
        /** @brief 关断 SSP 时钟(置 SSP.CLKGATE)。 */
        [[gnu::always_inline]] static void DisableSspClock() noexcept { Common::DisableClock<Registers::CLKCTRL::SSP::CLKGATE>(); }

        /** @brief 使能 EMI 时钟(清 EMI.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableEmiClock() noexcept { Common::EnableClock<Registers::CLKCTRL::EMI::CLKGATE>(); }
        /** @brief 关断 EMI 时钟(置 EMI.CLKGATE)。 */
        [[gnu::always_inline]] static void DisableEmiClock() noexcept { Common::DisableClock<Registers::CLKCTRL::EMI::CLKGATE>(); }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_CLKCTRL
