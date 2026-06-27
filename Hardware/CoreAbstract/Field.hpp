#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_FIELD
#define EXIST_OS_NEXT_CORE_ABSTRACT_FIELD

#include "Concepts.hpp"
#include <cstdint>

/**
 * @file Field.hpp
 * @brief 强类型位域模板:绑定后端寄存器,提供 consteval 掩码与零开销读写。
 */

namespace LowLevel {

/**
 * @brief 强类型位域(模板类)。
 *
 * 绑定到一个 Backend(MMIO Register / CP15 寄存器 / CPSR),用编译期已知的
 * 偏移/位宽描述一个字段。对外提供 consteval 的 GetMask(),以及零开销的
 * 读/写/置位/清位/翻转。
 *
 * @note Set/Clear/Toggle/Write 在 ARMv5 上是"读-改-写",非原子(本核无
 *       LDREX/STREX)。需要原子时用 Set/Clear/Toggle 别名或 CriticalSection。
 *
 * @tparam RegisterBackend 后端寄存器类型(须满足 Backend)。
 * @tparam Offset          字段最低位。
 * @tparam Width           字段位宽。
 * @tparam FieldValueType  字段值的强类型(默认与寄存器同宽的无符号整型,可传枚举)。
 */
template <typename RegisterBackend, uint32_t Offset, uint32_t Width,
          typename FieldValueType = typename RegisterBackend::ValueType>
    requires Backend<RegisterBackend>
struct Field {
    using BackendType = RegisterBackend;                       /**< 所属后端 */
    using RegisterType = typename RegisterBackend::ValueType;  /**< 寄存器底层无符号整型 */
    using ValueType = FieldValueType;                          /**< 字段值的强类型 */

    static constexpr uint32_t BitOffset = Offset; /**< 字段最低位 */
    static constexpr uint32_t BitWidth = Width;   /**< 字段位宽 */

    static_assert(BitWidth >= 1, "Field 位宽至少为 1");
    static_assert(BitOffset + BitWidth <= sizeof(RegisterType) * 8,
                  "Field 越出寄存器边界");

    /**
     * @brief 编译期掩码(已对齐到 BitOffset 位置)。
     * @return 该字段在寄存器中占据的位掩码。
     */
    [[nodiscard]] static consteval RegisterType GetMask() noexcept {
        if constexpr (BitWidth >= sizeof(RegisterType) * 8) {
            return static_cast<RegisterType>(~RegisterType{0});
        } else {
            return static_cast<RegisterType>(
                ((RegisterType{1} << BitWidth) - RegisterType{1}) << BitOffset);
        }
    }

    /**
     * @brief 把一个字段值移位到位(编译期常量场景可参与折叠)。
     * @param value 字段值。
     * @return 已移位并掩码后的寄存器位模式。
     */
    [[nodiscard]] static constexpr RegisterType Shifted(ValueType value) noexcept {
        return static_cast<RegisterType>(
            (static_cast<RegisterType>(value) << BitOffset) & GetMask());
    }

    /**
     * @brief 读取字段并右移归位:ldr/mrc + and + lsr。
     * @return 字段当前值。
     */
    [[gnu::always_inline]] [[nodiscard]] static ValueType Read() noexcept {
        return static_cast<ValueType>((RegisterBackend::Read() & GetMask()) >> BitOffset);
    }

    /**
     * @brief 读取字段的原始掩码值(仍在原位,便于按位合并)。
     * @return 寄存器读数与字段掩码相与的结果。
     */
    [[gnu::always_inline]] [[nodiscard]] static RegisterType ReadRaw() noexcept {
        return RegisterBackend::Read() & GetMask();
    }

    /**
     * @brief 写入字段值(非原子 RMW:读 + bic + orr + 写)。
     * @param value 待写入的字段值。
     */
    [[gnu::always_inline]] static void Write(ValueType value) noexcept {
        RegisterBackend::Write(static_cast<RegisterType>(
            (RegisterBackend::Read() & ~GetMask()) | Shifted(value)));
    }

    /** @brief 整字段置 1(非原子 RMW,3 指令)。 */
    [[gnu::always_inline]] static void Set() noexcept {
        RegisterBackend::Write(static_cast<RegisterType>(RegisterBackend::Read() | GetMask()));
    }

    /** @brief 整字段清 0(非原子 RMW,3 指令)。 */
    [[gnu::always_inline]] static void Clear() noexcept {
        RegisterBackend::Write(static_cast<RegisterType>(RegisterBackend::Read() & ~GetMask()));
    }

    /** @brief 整字段翻转(非原子 RMW,3 指令)。 */
    [[gnu::always_inline]] static void Toggle() noexcept {
        RegisterBackend::Write(static_cast<RegisterType>(RegisterBackend::Read() ^ GetMask()));
    }

    /**
     * @brief 字段是否非零。
     * @return 字段任一位为 1 时返回 true。
     */
    [[gnu::always_inline]] [[nodiscard]] static bool IsSet() noexcept {
        return (RegisterBackend::Read() & GetMask()) != 0;
    }

    /**
     * @brief 字段是否等于给定值。
     * @param value 期望值。
     * @return 相等时返回 true。
     */
    [[gnu::always_inline]] [[nodiscard]] static bool IsValue(ValueType value) noexcept {
        return Read() == value;
    }
};

/**
 * @brief 一个字段及其待写入值的绑定,供 WriteFields 合并写入。
 * @tparam FieldType 目标字段类型。
 */
template <typename FieldType>
struct FieldValue {
    using FieldTypeAlias = FieldType;       /**< 目标字段类型 */
    typename FieldType::ValueType value;    /**< 待写入的字段值 */

    /**
     * @brief 取已移位到位的寄存器位模式。
     * @return 该字段值对应的寄存器位。
     */
    [[gnu::always_inline]] [[nodiscard]] constexpr typename FieldType::RegisterType
    Raw() const noexcept {
        return FieldType::Shifted(value);
    }
};

/**
 * @brief 构造一个 FieldValue。
 * @tparam FieldType 目标字段类型。
 * @param value 字段值。
 * @return 绑定好的 FieldValue。
 */
template <typename FieldType>
[[gnu::always_inline]] [[nodiscard]] constexpr FieldValue<FieldType>
MakeFieldValue(typename FieldType::ValueType value) noexcept {
    return FieldValue<FieldType>{value};
}

/**
 * @brief 一次 RMW 合并写入多个字段,要求它们属于同一个 Backend。
 *
 * 把首个 FieldValue 单独取出做形参,既能拿到共同 Backend,又避开了
 * "别名模板把参数包展开到固定首形参"这种 clang 拒绝的写法。
 *
 * @param first 第一个字段值(用于推导共同后端)。
 * @param rest  其余字段值。
 */
template <typename FirstFieldValue, typename... RestFieldValues>
[[gnu::always_inline]] inline void
WriteFields(FirstFieldValue first, RestFieldValues... rest) noexcept {
    using RegisterBackendType = typename FirstFieldValue::FieldTypeAlias::BackendType;
    static_assert((std::same_as<typename RestFieldValues::FieldTypeAlias::BackendType,
                                RegisterBackendType> && ...),
                  "WriteFields: 所有字段必须属于同一个寄存器");
    using RegisterType = typename RegisterBackendType::ValueType;
    constexpr RegisterType combinedMask =
        (FirstFieldValue::FieldTypeAlias::GetMask() | ... |
         RestFieldValues::FieldTypeAlias::GetMask());
    const RegisterType combinedValue =
        (static_cast<RegisterType>(first.Raw()) | ... |
         static_cast<RegisterType>(rest.Raw()));
    RegisterBackendType::Write(
        static_cast<RegisterType>((RegisterBackendType::Read() & ~combinedMask) | combinedValue));
}

} // namespace LowLevel

#endif
