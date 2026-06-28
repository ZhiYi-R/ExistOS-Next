#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_FIELD
#define EXIST_OS_NEXT_CORE_ABSTRACT_FIELD

#include "Bit.hpp"
#include "Concepts.hpp"
#include <cstdint>

/**
 * @file Field.hpp
 * @brief 强类型位域描述符(纯数据类)+ 寄存器侧字段访问 CRTP mixin。
 *
 * 设计:Field 是纯描述符——只描述一个字段的偏移/位宽/值类型,以及它归属哪个
 * 后端寄存器,自身不含任何动作。一切读写都以寄存器为主体发起,体现字段的归属:
 *   CTRL::Reg::WriteField<CTRL::FOO>(value);
 *   auto v = CTRL::Reg::ReadField<CTRL::FOO>();
 * 这些动作由 FieldAccess mixin 注入到寄存器后端,并在编译期 static_assert
 * 字段确属本寄存器,从类型层面挡掉"拿别的寄存器的字段来读写"。
 */

namespace LowLevel {

/**
 * @brief 强类型位域描述符(纯数据类,无动作)。
 *
 * 绑定到一个后端(MMIO Register / CP15 寄存器 / CPSR)只为表达"该字段属于谁"
 * 并借其取底层整型宽度。对外仅提供 consteval 的 GetMask()/Shifted() 与位信息;
 * 读/写/置/清/翻转一律经所属寄存器的 ReadField/WriteField/... 完成(见 FieldAccess)。
 *
 * @tparam RegisterBackend 所属后端寄存器类型(须可读或可写)。
 * @tparam Offset          字段最低位(强类型位索引 Bit,杜绝裸位号)。
 * @tparam Width           字段位宽。
 * @tparam FieldValueType  字段值的强类型(默认与寄存器同宽的无符号整型,可传枚举)。
 */
template <typename RegisterBackend, Bit Offset, uint32_t Width,
          typename FieldValueType = typename RegisterBackend::ValueType>
    requires(ReadableBackend<RegisterBackend> || WritableBackend<RegisterBackend>)
struct Field {
    using BackendType = RegisterBackend;                      /**< 所属后端 */
    using RegisterType = typename RegisterBackend::ValueType; /**< 寄存器底层无符号整型 */
    using ValueType = FieldValueType;                         /**< 字段值的强类型 */

    static constexpr uint32_t BitOffset = static_cast<uint32_t>(Offset); /**< 字段最低位 */
    static constexpr uint32_t BitWidth = Width;                          /**< 字段位宽 */

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
};

/**
 * @brief 字段访问 CRTP mixin:给寄存器后端注入"以寄存器为主体"的字段读写。
 *
 * 让具体寄存器后端(Derived)继承本类,即可用成员语法对它的字段做强类型读写:
 *   Derived::ReadField<F>()  / ReadFieldRaw<F>() / FieldIs<F>(v) / FieldIsSet<F>()
 *   Derived::WriteField<F>(v)/ WriteFields<F...>(v...) / SetField<F>() / ClearField<F>() / ToggleField<F>()
 * 每个动作都 static_assert F 属于 Derived(本寄存器),在编译期挡掉跨寄存器误用——
 * 这正是 Field 作为纯描述符、动作收归寄存器后才得以表达的归属语义。
 *
 * 读类(ReadField/ReadFieldRaw/FieldIs/FieldIsSet)只要求后端可读,故只读寄存器
 * 也能读其字段;写类/读改写(WriteField/WriteFields/SetField/ClearField/ToggleField)
 * 要求后端可读且可写。空基类、全 static + always_inline,零开销。
 *
 * @note WriteField/WriteFields 是非原子 RMW(本核无 LDREX/STREX)。SetField/
 *       ClearField/ToggleField 在带 SET/CLR/TOG 别名的后端上自动编成单条原子
 *       str,否则退回非原子 RMW;后者需原子时请用 CriticalSection。
 *
 * @tparam Derived 派生的寄存器后端类型(CRTP 自身)。
 */
template <typename Derived>
struct FieldAccess {
    /**
     * @brief 读取字段并右移归位:ldr/mrc + and + lsr。
     * @return 字段当前值。
     */
    template <typename FieldType>
    [[gnu::always_inline]] [[nodiscard]] static typename FieldType::ValueType
    ReadField() noexcept
        requires ReadableBackend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "ReadField: 字段必须属于本寄存器");
        return static_cast<typename FieldType::ValueType>(
            (Derived::Read() & FieldType::GetMask()) >> FieldType::BitOffset);
    }

    /**
     * @brief 读取字段的原始掩码值(仍在原位,便于按位合并)。
     * @return 寄存器读数与字段掩码相与的结果。
     */
    template <typename FieldType>
    [[gnu::always_inline]] [[nodiscard]] static typename FieldType::RegisterType
    ReadFieldRaw() noexcept
        requires ReadableBackend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "ReadFieldRaw: 字段必须属于本寄存器");
        return Derived::Read() & FieldType::GetMask();
    }

    /**
     * @brief 字段是否等于给定值。
     * @param value 期望值。
     * @return 相等时返回 true。
     */
    template <typename FieldType>
    [[gnu::always_inline]] [[nodiscard]] static bool
    FieldIs(typename FieldType::ValueType value) noexcept
        requires ReadableBackend<Derived>
    {
        return ReadField<FieldType>() == value;
    }

    /**
     * @brief 字段是否非零。
     * @return 字段任一位为 1 时返回 true。
     */
    template <typename FieldType>
    [[gnu::always_inline]] [[nodiscard]] static bool FieldIsSet() noexcept
        requires ReadableBackend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "FieldIsSet: 字段必须属于本寄存器");
        return (Derived::Read() & FieldType::GetMask()) != 0;
    }

    /**
     * @brief 写入单个字段(非原子 RMW:读 + bic + orr + 写)。
     * @param value 待写入的字段值。
     */
    template <typename FieldType>
    [[gnu::always_inline]] static void
    WriteField(typename FieldType::ValueType value) noexcept
        requires Backend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "WriteField: 字段必须属于本寄存器");
        using RegisterType = typename Derived::ValueType;
        Derived::Write(static_cast<RegisterType>(
            (Derived::Read() & ~FieldType::GetMask()) | FieldType::Shifted(value)));
    }

    /**
     * @brief 一次 RMW 合并写入多个字段(同属本寄存器)。
     * @tparam FieldTypes 目标字段(显式给出,均须属于本寄存器)。
     * @param values 与 FieldTypes 一一对应的字段值。
     */
    template <typename... FieldTypes>
    [[gnu::always_inline]] static void
    WriteFields(typename FieldTypes::ValueType... values) noexcept
        requires Backend<Derived>
    {
        static_assert(sizeof...(FieldTypes) >= 1, "WriteFields: 至少写入一个字段");
        static_assert((std::same_as<typename FieldTypes::BackendType, Derived> && ...),
                      "WriteFields: 所有字段必须属于本寄存器");
        using RegisterType = typename Derived::ValueType;
        constexpr RegisterType combinedMask{
            static_cast<RegisterType>((FieldTypes::GetMask() | ... | RegisterType{0}))};
        const RegisterType combinedValue{static_cast<RegisterType>(
            (static_cast<RegisterType>(FieldTypes::Shifted(values)) | ... | RegisterType{0}))};
        Derived::Write(
            static_cast<RegisterType>((Derived::Read() & ~combinedMask) | combinedValue));
    }

    /**
     * @brief 整字段置 1。带别名后端走单条原子 str→SET,否则非原子 RMW(3 指令)。
     */
    template <typename FieldType>
    [[gnu::always_inline]] static void SetField() noexcept
        requires Backend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "SetField: 字段必须属于本寄存器");
        if constexpr (HasSetClearToggle<Derived>) {
            Derived::Set(FieldType::GetMask()); // 单条原子 str→SET 别名
        } else {
            Derived::Write(
                static_cast<typename Derived::ValueType>(Derived::Read() | FieldType::GetMask()));
        }
    }

    /**
     * @brief 整字段清 0。带别名后端走单条原子 str→CLR,否则非原子 RMW(3 指令)。
     */
    template <typename FieldType>
    [[gnu::always_inline]] static void ClearField() noexcept
        requires Backend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "ClearField: 字段必须属于本寄存器");
        if constexpr (HasSetClearToggle<Derived>) {
            Derived::Clear(FieldType::GetMask()); // 单条原子 str→CLR 别名
        } else {
            Derived::Write(
                static_cast<typename Derived::ValueType>(Derived::Read() & ~FieldType::GetMask()));
        }
    }

    /**
     * @brief 整字段翻转。带别名后端走单条原子 str→TOG,否则非原子 RMW(3 指令)。
     */
    template <typename FieldType>
    [[gnu::always_inline]] static void ToggleField() noexcept
        requires Backend<Derived>
    {
        static_assert(std::same_as<typename FieldType::BackendType, Derived>,
                      "ToggleField: 字段必须属于本寄存器");
        if constexpr (HasSetClearToggle<Derived>) {
            Derived::Toggle(FieldType::GetMask()); // 单条原子 str→TOG 别名
        } else {
            Derived::Write(
                static_cast<typename Derived::ValueType>(Derived::Read() ^ FieldType::GetMask()));
        }
    }
};

} // namespace LowLevel

#endif
