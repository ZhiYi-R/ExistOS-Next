#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_LRADC
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_LRADC

/**
 * @file LRADC.hpp
 * @brief 低分辨率 ADC(LRADC)驱动:模块复位/门控、电池转换读取,
 *        以及编译期参数化的逐通道门面 Channel<Index>。
 *
 * STMP3770/i.MX23 的 LRADC 有 8 个虚拟通道槽(0–7),各槽:
 *  - 由 CTRL4.LRADC{n}SELECT 选择映射到 16 路物理输入之一;
 *  - 结果寄存器 CH{n}:VALUE[0,18] 转换结果、NUM_SAMPLES/ACCUMULATE 累加配置;
 *  - 完成中断状态/使能在 CTRL1.LRADC{n}_IRQ / LRADC{n}_IRQ_EN;
 *  - 启动一次转换:向 CTRL0.SCHEDULE(8 位掩码)对应位写 1(经 SET 别名)。
 * 模块软复位/门控在 CTRL0.SFTRST/CLKGATE。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * 电池电压走通道 7(BATT);CONVERSION 寄存器(只读)提供缩放后的电池电压。典型用法:
 *   `LRADC::DeassertSoftReset(); LRADC::EnableClock();`
 *   `using Batt = LRADC::Channel<7>;`
 *   `Batt::SelectInput(Batt::InputSource::CHANNEL7);`
 *   `Batt::StartConversion();`                    // 触发;完成轮询编排上移 OS
 *   `if (Batt::IsConversionComplete()) { auto raw = Batt::ReadResult(); Batt::AcknowledgeInterrupt(); }`
 *
 * 命名空间 CH{n} 与 CTRL1/CTRL4 的逐通道字段无法被模板整数参数化,故用 Detail::LradcChannelTraits<n>
 * 的**手写显式特化**把"通道号 → 该通道的结果寄存器/中断字段/选择字段"在编译期固定。
 *
 * @note 寄存器/字段取自生成头 Registers/LRADC.hpp,复位原语复用 Common::{AssertSoftReset,…};
 *       复位序列节拍上移 OS,本层只给触发 + 谓词。CONVERSION 在生成头中为只读,故本驱动只提供
 *       其读取,不提供 SCALE_FACTOR/AUTOMATIC 写配置。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/LRADC.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    namespace Detail {

        /**
         * @brief LRADC 通道号 → 该通道结果寄存器/中断字段/选择字段别名的映射(主模板未定义)。
         *
         * 仅对 0–7 提供**手写显式特化**(原先由局部宏批量生成,现按"禁止函数式宏"展开为
         * 逐通道特化列表);非法通道号实例化将因主模板不完整而编译失败。
         * @tparam Index 通道号(0–7)。
         */
        template <std::uint32_t Index>
        struct LradcChannelTraits;

        template <>
        struct LradcChannelTraits<0u> {
            using ResultReg = Registers::LRADC::CH0::Reg;
            using ValueField = Registers::LRADC::CH0::VALUE;
            using NumSamplesField = Registers::LRADC::CH0::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH0::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC0_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC0_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC0SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC0SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<1u> {
            using ResultReg = Registers::LRADC::CH1::Reg;
            using ValueField = Registers::LRADC::CH1::VALUE;
            using NumSamplesField = Registers::LRADC::CH1::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH1::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC1_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC1_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC1SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC1SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<2u> {
            using ResultReg = Registers::LRADC::CH2::Reg;
            using ValueField = Registers::LRADC::CH2::VALUE;
            using NumSamplesField = Registers::LRADC::CH2::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH2::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC2_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC2_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC2SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC2SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<3u> {
            using ResultReg = Registers::LRADC::CH3::Reg;
            using ValueField = Registers::LRADC::CH3::VALUE;
            using NumSamplesField = Registers::LRADC::CH3::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH3::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC3_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC3_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC3SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC3SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<4u> {
            using ResultReg = Registers::LRADC::CH4::Reg;
            using ValueField = Registers::LRADC::CH4::VALUE;
            using NumSamplesField = Registers::LRADC::CH4::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH4::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC4_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC4_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC4SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC4SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<5u> {
            using ResultReg = Registers::LRADC::CH5::Reg;
            using ValueField = Registers::LRADC::CH5::VALUE;
            using NumSamplesField = Registers::LRADC::CH5::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH5::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC5_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC5_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC5SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC5SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<6u> {
            using ResultReg = Registers::LRADC::CH6::Reg;
            using ValueField = Registers::LRADC::CH6::VALUE;
            using NumSamplesField = Registers::LRADC::CH6::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH6::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC6_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC6_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC6SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC6SELECT_Values;
        };
        template <>
        struct LradcChannelTraits<7u> {
            using ResultReg = Registers::LRADC::CH7::Reg;
            using ValueField = Registers::LRADC::CH7::VALUE;
            using NumSamplesField = Registers::LRADC::CH7::NUM_SAMPLES;
            using AccumulateField = Registers::LRADC::CH7::ACCUMULATE;
            using IrqField = Registers::LRADC::CTRL1::LRADC7_IRQ;
            using IrqEnableField = Registers::LRADC::CTRL1::LRADC7_IRQ_EN;
            using SelectField = Registers::LRADC::CTRL4::LRADC7SELECT;
            using SelectValues = Registers::LRADC::CTRL4::LRADC7SELECT_Values;
        };

    } // namespace Detail

    /** @brief 低分辨率 ADC(LRADC)驱动:纯静态门面,无实例。 */
    struct LRADC {
        LRADC() = delete;
        ~LRADC() = delete;
        LRADC(const LRADC&) = delete;
        LRADC& operator=(const LRADC&) = delete;

    private:
        using ControlRegister0 = Registers::LRADC::CTRL0::Reg;     /**< 主控制寄存器(复位/门控/SCHEDULE)。 */
        using InterruptRegister = Registers::LRADC::CTRL1::Reg;    /**< 逐通道中断状态/使能寄存器。 */
        using SelectRegister = Registers::LRADC::CTRL4::Reg;       /**< 逐通道物理输入选择寄存器。 */
        using ConversionRegister = Registers::LRADC::CONVERSION::Reg; /**< 缩放后电池电压寄存器(只读)。 */

        using SoftReset = Registers::LRADC::CTRL0::SFTRST;  /**< CTRL0.SFTRST 字段后端。 */
        using ClockGate = Registers::LRADC::CTRL0::CLKGATE; /**< CTRL0.CLKGATE 字段后端。 */

    public:
        /** @brief LRADC 虚拟通道槽个数(0–7)。 */
        static constexpr std::uint32_t ChannelCount = 8u;

        // ====================== 模块级:复位 / 门控 ======================

        /** @brief 触发软复位:置 CTRL0.SFTRST(单条原子 str→SET)。 */
        [[gnu::always_inline]] static void AssertSoftReset() noexcept {
            Common::AssertSoftReset<SoftReset>();
        }

        /** @brief 退出软复位:清 CTRL0.SFTRST(单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DeassertSoftReset() noexcept {
            Common::DeassertSoftReset<SoftReset>();
        }

        /** @brief 非阻塞谓词:软复位是否仍被置位(CTRL0.SFTRST==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSoftResetAsserted() noexcept {
            return Common::IsSoftResetAsserted<SoftReset>();
        }

        /** @brief 使能 LRADC 模块时钟(清 CTRL0.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 LRADC 模块时钟(置 CTRL0.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL0.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        // ====================== 电池转换结果(CONVERSION,只读) ======================

        /**
         * @brief 读取缩放后的电池电压(读 CONVERSION.SCALED_BATT_VOLTAGE,10 位)。
         *
         * 该值由硬件按 SCALE_FACTOR 缩放;CONVERSION 在生成头中为只读,缩放系数/自动转换使能
         * 不在此配置(若需配置须确认 SVD 访问属性后重生成)。
         * @return 10 位缩放后电池电压码。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadScaledBatteryVoltage() noexcept {
            return ConversionRegister::template ReadField<Registers::LRADC::CONVERSION::SCALED_BATT_VOLTAGE>();
        }

        /**
         * @brief 编译期固定通道号的逐通道门面(纯静态)。
         *
         * @tparam Index 通道号(0–7),越界编译期报错。
         */
        template <std::uint32_t Index>
            requires(Index < ChannelCount)
        struct Channel {
            Channel() = delete;
            ~Channel() = delete;
            Channel(const Channel&) = delete;
            Channel& operator=(const Channel&) = delete;

        private:
            using Traits = Detail::LradcChannelTraits<Index>; /**< 本通道的寄存器/字段/枚举映射。 */
            /** @brief 本通道在 CTRL0.SCHEDULE(8 位)中的启动掩码。 */
            static constexpr std::uint32_t ScheduleMask = 1u << Index;

        public:
            /** @brief 物理输入通道选择(CHANNEL0–CHANNEL15)。 */
            using InputSource = typename Traits::SelectValues;

            /**
             * @brief 为本虚拟槽选择物理输入通道(写 CTRL4.LRADC{n}SELECT,一次 RMW)。
             * @param source 物理输入通道。
             */
            [[gnu::always_inline]] static void SelectInput(InputSource source) noexcept {
                SelectRegister::template WriteField<typename Traits::SelectField>(source);
            }

            /**
             * @brief 配置累加采样(写 CH{n}.NUM_SAMPLES/ACCUMULATE,一次 RMW)。
             * @param numSamples 累加样本数码(0–31 对应 1–32 次)。
             * @param accumulate 是否启用累加。
             */
            [[gnu::always_inline]] static void ConfigureAccumulation(std::uint32_t numSamples,
                                                                    bool accumulate) noexcept {
                Traits::ResultReg::template WriteFields<typename Traits::NumSamplesField,
                                                        typename Traits::AccumulateField>(
                    numSamples, accumulate ? 1u : 0u);
            }

            /** @brief 启动一次转换(向 CTRL0.SCHEDULE 本通道位写 1,单条原子 str→SET)。 */
            [[gnu::always_inline]] static void StartConversion() noexcept {
                ControlRegister0::Set(ScheduleMask);
            }

            /**
             * @brief 读取转换结果(读 CH{n}.VALUE,18 位)。
             * @return 18 位 ADC 结果(累加模式下为累加值)。
             */
            [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadResult() noexcept {
                return Traits::ResultReg::template ReadField<typename Traits::ValueField>();
            }

            /**
             * @brief 转换是否完成(读 CTRL1.LRADC{n}_IRQ)。
             * @return 完成返回 true。
             */
            [[gnu::always_inline]] [[nodiscard]] static bool IsConversionComplete() noexcept {
                return InterruptRegister::template FieldIsSet<typename Traits::IrqField>();
            }

            /** @brief 使能本通道转换完成中断(置 CTRL1.LRADC{n}_IRQ_EN,单条原子 str→SET)。 */
            [[gnu::always_inline]] static void EnableInterrupt() noexcept {
                InterruptRegister::template SetField<typename Traits::IrqEnableField>();
            }

            /** @brief 关闭本通道转换完成中断(清 CTRL1.LRADC{n}_IRQ_EN,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void DisableInterrupt() noexcept {
                InterruptRegister::template ClearField<typename Traits::IrqEnableField>();
            }

            /** @brief 清除本通道转换完成中断标志(清 CTRL1.LRADC{n}_IRQ,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void AcknowledgeInterrupt() noexcept {
                InterruptRegister::template ClearField<typename Traits::IrqField>();
            }
        };
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_LRADC
