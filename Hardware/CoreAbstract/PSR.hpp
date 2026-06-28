#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_PSR
#define EXIST_OS_NEXT_CORE_ABSTRACT_PSR

#include "Concepts.hpp"
#include "Field.hpp"
#include <cstdint>

/**
 * @file PSR.hpp
 * @brief 程序状态寄存器 CPSR/SPSR(经 mrs/msr)与中断屏蔽原语。
 *
 * ARMv5 CPSR 布局:
 *   [31]N [30]Z [29]C [28]V [27]Q            —— 标志字节(flags,_f)
 *   ... [7]I [6]F [5]T [4:0]M                —— 控制字节(control,_c)
 *
 * 关键区分:
 *  - 标志位 N/Z/C/V/Q 在标志字节 → Cpsr 作为 Backend,其 Write 用
 *    `msr cpsr_f`,只动标志字节,在 USR 模式也安全。Field<Cpsr,…> 适用。
 *  - 中断屏蔽 I/F、模式 M 在控制字节 → 绝不能经 Cpsr 的字段写(那会用
 *    cpsr_f 写错字节)。改用下方专用原语(msr cpsr_c)。
 */

namespace LowLevel {

/**
 * @brief CPSR 标志字节后端(Backend)。
 *
 * Read 读整字 CPSR;Write 仅写标志字节。只把 N/Z/C/V/Q 暴露为 Field。
 */
struct Cpsr : FieldAccess<Cpsr> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */

    /**
     * @brief 读整字 CPSR:单条 mrs。
     * @return CPSR 当前值。
     */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrs %0, cpsr" : "=r"(value));
        return value;
    }

    /**
     * @brief 仅写标志字节:单条 msr cpsr_f(USR 下安全,不动 I/F/M)。
     * @param value 新的标志字节(取其高位 NZCVQ)。
     */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("msr cpsr_f, %0" : : "r"(value) : "cc");
    }

    using Negative = Field<Cpsr, Bit::Bit31, 1>; /**< N:负标志 */
    using Zero = Field<Cpsr, Bit::Bit30, 1>;     /**< Z:零标志 */
    using Carry = Field<Cpsr, Bit::Bit29, 1>;    /**< C:进位标志 */
    using Overflow = Field<Cpsr, Bit::Bit28, 1>; /**< V:溢出标志 */
    using Saturate = Field<Cpsr, Bit::Bit27, 1>; /**< Q:饱和标志(DSP) */
};

/**
 * @brief 处理器模式(CPSR M[4:0])。
 */
enum class Mode : uint32_t {
    User = 0x10,           /**< USR */
    FastInterrupt = 0x11,  /**< FIQ */
    Interrupt = 0x12,      /**< IRQ */
    Supervisor = 0x13,     /**< SVC */
    Abort = 0x17,          /**< ABT */
    Undefined = 0x1B,      /**< UND */
    System = 0x1F,         /**< SYS */
};

inline constexpr uint32_t CpsrIrqMask = 1u << 7; /**< CPSR I 位(IRQ 屏蔽) */
inline constexpr uint32_t CpsrFiqMask = 1u << 6; /**< CPSR F 位(FIQ 屏蔽) */

/**
 * @brief 关 IRQ:mrs; orr #0x80; msr cpsr_c。
 *
 * 这些是访问 I/F 位的唯一正确途径,不要用 Cpsr 的 Field。
 */
[[gnu::always_inline]] inline void DisableInterrupt() noexcept {
    uint32_t temp;
    asm volatile("mrs %0, cpsr\n\t"
                 "orr %0, %0, #0x80\n\t"
                 "msr cpsr_c, %0"
                 : "=r"(temp)
                 :
                 : "memory", "cc");
}

/** @brief 开 IRQ:mrs; bic #0x80; msr cpsr_c。 */
[[gnu::always_inline]] inline void EnableInterrupt() noexcept {
    uint32_t temp;
    asm volatile("mrs %0, cpsr\n\t"
                 "bic %0, %0, #0x80\n\t"
                 "msr cpsr_c, %0"
                 : "=r"(temp)
                 :
                 : "memory", "cc");
}

/** @brief 关 FIQ。 */
[[gnu::always_inline]] inline void DisableFastInterrupt() noexcept {
    uint32_t temp;
    asm volatile("mrs %0, cpsr\n\t"
                 "orr %0, %0, #0x40\n\t"
                 "msr cpsr_c, %0"
                 : "=r"(temp)
                 :
                 : "memory", "cc");
}

/** @brief 开 FIQ。 */
[[gnu::always_inline]] inline void EnableFastInterrupt() noexcept {
    uint32_t temp;
    asm volatile("mrs %0, cpsr\n\t"
                 "bic %0, %0, #0x40\n\t"
                 "msr cpsr_c, %0"
                 : "=r"(temp)
                 :
                 : "memory", "cc");
}

/**
 * @brief 保存当前 CPSR 并关 IRQ,返回旧值。
 *
 * 用独立 scratch 寄存器避免双输出别名。
 *
 * @return 关中断前的 CPSR(供 RestoreInterrupt 还原)。
 */
[[gnu::always_inline]] [[nodiscard]] inline uint32_t SaveAndDisableInterrupt() noexcept {
    uint32_t saved, scratch;
    asm volatile("mrs %0, cpsr\n\t"
                 "orr %1, %0, #0x80\n\t"
                 "msr cpsr_c, %1"
                 : "=r"(saved), "=&r"(scratch)
                 :
                 : "memory", "cc");
    return saved;
}

/**
 * @brief 恢复之前保存的 CPSR 控制字节(写回 I/F/T/M)。
 * @param saved SaveAndDisableInterrupt 返回的旧 CPSR。
 */
[[gnu::always_inline]] inline void RestoreInterrupt(uint32_t saved) noexcept {
    asm volatile("msr cpsr_c, %0" : : "r"(saved) : "memory", "cc");
}

/**
 * @brief RAII 关中断临界区。
 *
 * @note ctor/dtor 必须 always_inline,否则 savedState 会溢出到栈、并引入函数调用。
 */
class CriticalSection {
    uint32_t savedState; /**< 进入临界区前的 CPSR */

public:
    [[gnu::always_inline]] CriticalSection() noexcept
        : savedState{SaveAndDisableInterrupt()} {}
    [[gnu::always_inline]] ~CriticalSection() noexcept { RestoreInterrupt(savedState); }

    CriticalSection(const CriticalSection&) = delete;
    CriticalSection& operator=(const CriticalSection&) = delete;
    CriticalSection(CriticalSection&&) = delete;
    CriticalSection& operator=(CriticalSection&&) = delete;
};

/**
 * @brief 关中断内对任意 Backend 做一次 RMW。
 *
 * 在 ARM926 上这是"原子"RMW 的通用途径(无 LDREX/STREX 时,关中断是唯一
 * 与中断处理程序互斥的手段)。
 *
 * @tparam RegisterBackend 目标后端(须满足 Backend)。
 * @tparam Operation       形如 ValueType(ValueType) 的可调用对象。
 * @param operation 接收旧值、返回新值的变换。
 */
template <typename RegisterBackend, typename Operation>
    requires Backend<RegisterBackend>
[[gnu::always_inline]] inline void ModifyAtomic(Operation&& operation) noexcept {
    const uint32_t saved{SaveAndDisableInterrupt()};
    RegisterBackend::Write(
        static_cast<typename RegisterBackend::ValueType>(operation(RegisterBackend::Read())));
    RestoreInterrupt(saved);
}

/**
 * @brief 备份程序状态寄存器 SPSR(有意不作 Backend)。
 *
 * 在 USR/SYS 模式下读取 SPSR 是 UNPREDICTABLE,因此 Spsr 不满足 Backend,
 * 也无法被 Field 误用。所有访问要求显式构造 PrivilegedModeTag,让调用方在
 * 类型层面承认"当前处于特权模式"。
 */
struct Spsr {
    using ValueType = uint32_t; /**< 值类型(注意:本类型不满足 Backend) */

    /**
     * @brief 读整字 SPSR(仅特权模式合法)。
     * @return SPSR 当前值。
     */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read(PrivilegedModeTag) noexcept {
        uint32_t value;
        asm volatile("mrs %0, spsr" : "=r"(value));
        return value;
    }

    /**
     * @brief 写整字 SPSR 全部字段(_fsxc)。
     * @param value 待写入值。
     */
    [[gnu::always_inline]] static void Write(PrivilegedModeTag, uint32_t value) noexcept {
        asm volatile("msr spsr_fsxc, %0" : : "r"(value) : "cc");
    }

    /**
     * @brief 取被中断模式的 M[4:0](手写,不经 Field)。
     * @param tag 特权模式标签。
     * @return 被中断时的处理器模式。
     */
    [[gnu::always_inline]] [[nodiscard]] static Mode GetMode(PrivilegedModeTag tag) noexcept {
        return static_cast<Mode>(Read(tag) & 0x1Fu);
    }
};

} // namespace LowLevel

#endif
