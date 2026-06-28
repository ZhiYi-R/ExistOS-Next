#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_RESET_AND_CLOCK_GATE
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_RESET_AND_CLOCK_GATE

/**
 * @file ResetAndClockGate.hpp
 * @brief STMP/i.MX23 标准模块软复位 + 时钟门控的**单步原语**(作用于任意带 SFTRST/CLKGATE 的 CTRL 寄存器)。
 *
 * STMP3xxx / i.MX23 家族的每个外设控制寄存器普遍含两个控制位:
 *  - SFTRST(Bit31):软复位,置 1 把模块保持在复位态,清 0 退出复位。
 *  - CLKGATE(Bit30):时钟门控,置 1 关断模块时钟,清 0 供给时钟。
 *
 * 官方复位时序(u-boot `mxs_reset_block`)是一段含"清 SFTRST→等归零→清 CLKGATE→置 SFTRST→
 * 清 SFTRST→等归零→清 CLKGATE→等归零"的**带等待序列**。按本仓库的分层契约,裸金属层**不持有任何
 * 阻塞自旋**:本头只提供对**字段类型**参数化的"单步触发"与"非阻塞谓词",复位脉冲的节拍/超时编排
 * 上移到 OS(未来 NuttX statemachine 用 TIMROT 计时)。每个原语都是单条原子 str / 单条 ldr,无回读 RMW、无 `bl`。
 *
 * @note 字段的 BackendType::{SetField,ClearField,FieldIsSet} 由各外设传入的字段别名带入,
 *       本头不直接依赖 Concepts/Field 头(由调用方的寄存器/字段头提供完整定义)。
 */

namespace Hardware::Drivers::Common {

    /**
     * @brief 触发软复位:置 SFTRST(把模块保持在复位态)。单条原子 str→SET 别名。
     * @tparam SoftResetField 该外设 CTRL 的 SFTRST 字段别名。
     */
    template <typename SoftResetField>
    [[gnu::always_inline]] inline void AssertSoftReset() noexcept {
        using RegisterBackend = typename SoftResetField::BackendType;
        RegisterBackend::template SetField<SoftResetField>();
    }

    /**
     * @brief 退出软复位:清 SFTRST。单条原子 str→CLR 别名。
     * @tparam SoftResetField 该外设 CTRL 的 SFTRST 字段别名。
     */
    template <typename SoftResetField>
    [[gnu::always_inline]] inline void DeassertSoftReset() noexcept {
        using RegisterBackend = typename SoftResetField::BackendType;
        RegisterBackend::template ClearField<SoftResetField>();
    }

    /**
     * @brief 非阻塞谓词:软复位是否仍被置位(SFTRST==1)。单条 ldr + 掩码。
     * @tparam SoftResetField 该外设 CTRL 的 SFTRST 字段别名。
     * @return SFTRST 当前是否为 1。
     */
    template <typename SoftResetField>
    [[gnu::always_inline]] [[nodiscard]] inline bool IsSoftResetAsserted() noexcept {
        using RegisterBackend = typename SoftResetField::BackendType;
        return RegisterBackend::template FieldIsSet<SoftResetField>();
    }

    /**
     * @brief 使能某外设时钟(清 CLKGATE)。单条原子 str→CLR 别名。
     * @tparam ClockGateField 该外设 CTRL 的 CLKGATE 字段别名。
     */
    template <typename ClockGateField>
    [[gnu::always_inline]] inline void EnableClock() noexcept {
        using RegisterBackend = typename ClockGateField::BackendType;
        RegisterBackend::template ClearField<ClockGateField>();
    }

    /**
     * @brief 关断某外设时钟(置 CLKGATE),用于低功耗。单条原子 str→SET 别名。
     * @tparam ClockGateField 该外设 CTRL 的 CLKGATE 字段别名。
     */
    template <typename ClockGateField>
    [[gnu::always_inline]] inline void DisableClock() noexcept {
        using RegisterBackend = typename ClockGateField::BackendType;
        RegisterBackend::template SetField<ClockGateField>();
    }

    /**
     * @brief 非阻塞谓词:时钟是否被门控(CLKGATE==1)。单条 ldr + 掩码。
     * @tparam ClockGateField 该外设 CTRL 的 CLKGATE 字段别名。
     * @return CLKGATE 当前是否为 1。
     */
    template <typename ClockGateField>
    [[gnu::always_inline]] [[nodiscard]] inline bool IsClockGated() noexcept {
        using RegisterBackend = typename ClockGateField::BackendType;
        return RegisterBackend::template FieldIsSet<ClockGateField>();
    }

} // namespace Hardware::Drivers::Common

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_RESET_AND_CLOCK_GATE
