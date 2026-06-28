#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_CONCEPTS
#define EXIST_OS_NEXT_CORE_ABSTRACT_CONCEPTS

#include <concepts>

/**
 * @file Concepts.hpp
 * @brief 寄存器抽象层的基础约束:统一后端概念、访问权限、特权标签。
 */

namespace LowLevel {

/**
 * @brief 寄存器访问权限。
 *
 * 作为 Register / CP15 寄存器的非类型模板参数,用 requires 在编译期约束读写:
 * 写一个 ReadOnly、读一个 WriteOnly 都会直接编译失败。
 */
enum class Access {
    ReadOnly,  /**< 只读 */
    WriteOnly, /**< 只写 */
    ReadWrite, /**< 读写(默认) */
};

/**
 * @brief 特权模式标签。
 *
 * 访问 SPSR 等仅在特权模式下合法的资源时,要求显式构造一个该标签,
 * 让调用方在类型层面承认"当前处于特权模式"。
 */
struct PrivilegedModeTag {
    explicit PrivilegedModeTag() = default;
};

/**
 * @brief 可读后端概念。
 *
 * 任何提供 ValueType + 按值 Read()(noexcept)的类型。寄存器侧的读类字段操作
 * (ReadField/ReadFieldRaw/FieldIs/FieldIsSet)只需后端可读即可发起,因此只读
 * MMIO/CP15 寄存器也能拥有强类型字段。
 *
 * @tparam RegisterBackend 待检测的后端类型。
 */
template <typename RegisterBackend>
concept ReadableBackend = requires {
    typename RegisterBackend::ValueType;
    requires std::unsigned_integral<typename RegisterBackend::ValueType>;
    { RegisterBackend::Read() } noexcept -> std::same_as<typename RegisterBackend::ValueType>;
};

/**
 * @brief 可写后端概念。
 *
 * 任何提供 ValueType + 单参 Write(ValueType)(noexcept)的类型。
 *
 * @tparam RegisterBackend 待检测的后端类型。
 */
template <typename RegisterBackend>
concept WritableBackend = requires(typename RegisterBackend::ValueType value) {
    typename RegisterBackend::ValueType;
    requires std::unsigned_integral<typename RegisterBackend::ValueType>;
    { RegisterBackend::Write(value) } noexcept;
};

/**
 * @brief 统一寄存器后端概念(可读且可写)。
 *
 * 同时满足 ReadableBackend 与 WritableBackend:提供 ValueType + 按值 Read()
 * + 单参 Write(ValueType)(均 noexcept)。寄存器侧的写类/读改写字段操作
 * (WriteField/WriteFields/SetField/ClearField/ToggleField)都要求 Backend。
 *
 * 满足者:MMIO Register、CP15 的 RW 寄存器、CPSR。
 * 有意不满足者:SPSR(USR/SYS 下读取 UNPREDICTABLE)、只读 CP15 寄存器
 *              (MainID/CacheType…,仅可读)、CP15 只写命令、test-clean。
 *
 * @tparam RegisterBackend 待检测的后端类型。
 */
template <typename RegisterBackend>
concept Backend = ReadableBackend<RegisterBackend> && WritableBackend<RegisterBackend>;

/**
 * @brief 带 Set/Clear/Toggle 原子位别名的后端。
 *
 * 用于 Sigmatel/STMP/i.MX 家族那种"写别名地址即单条 store 原子置位/清位/翻转"
 * 的寄存器。普通寄存器不满足此概念,也就不会暴露这些接口。
 *
 * @tparam RegisterBackend 待检测的后端类型。
 */
template <typename RegisterBackend>
concept HasSetClearToggle =
    Backend<RegisterBackend> && requires(typename RegisterBackend::ValueType bits) {
        { RegisterBackend::Set(bits) } noexcept;
        { RegisterBackend::Clear(bits) } noexcept;
        { RegisterBackend::Toggle(bits) } noexcept;
    };

} // namespace LowLevel

#endif
