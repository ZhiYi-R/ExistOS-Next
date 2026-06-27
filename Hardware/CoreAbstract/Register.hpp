#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_REGISTER
#define EXIST_OS_NEXT_CORE_ABSTRACT_REGISTER

#include "Concepts.hpp"
#include <cstdint>
#include <concepts>

/**
 * @file Register.hpp
 * @brief MMIO 外设寄存器抽象:普通 ldr/str,以及带 Set/Clear/Toggle 别名的变体。
 */

namespace LowLevel {

/**
 * @brief MMIO 外设寄存器(普通 ldr/str)。
 *
 * 满足 Backend,可直接喂给 Field。访问权限由 requires 在编译期约束:
 * 读 WriteOnly、写 ReadOnly 都直接编译失败。Read 按值返回(避免 const&
 * 丢失 volatile)。
 *
 * @note Modify 是非原子的 3 指令 RMW(ARM926 无 LDREX/STREX)。需要原子时
 *       用 RegisterWithSetClearToggle 的别名,或在 CriticalSection 内操作。
 *
 * @tparam RegisterType 寄存器底层无符号整型(u8/u16/u32…)。
 * @tparam BaseAddress  绝对 MMIO 地址(编译期常量)。
 * @tparam access       访问权限(默认 ReadWrite)。
 */
template <std::unsigned_integral RegisterType, uint32_t BaseAddress,
          Access access = Access::ReadWrite>
class Register {
    static_assert(BaseAddress % alignof(RegisterType) == 0, "MMIO 地址未对齐");

public:
    using ValueType = RegisterType; /**< 暴露给 Backend/Field 的值类型 */

    /* 删除一切实例化:纯静态门面。 */
    Register() = delete;
    ~Register() = delete;
    Register(const Register&) = delete;
    Register& operator=(const Register&) = delete;

    /**
     * @brief 整字读:单条 ldr,按值返回。
     * @return 寄存器当前值。
     */
    [[gnu::always_inline]] [[nodiscard]] static RegisterType Read() noexcept
        requires(access == Access::ReadWrite || access == Access::ReadOnly)
    {
        return *reinterpret_cast<volatile RegisterType*>(BaseAddress);
    }

    /**
     * @brief 整字写:单条 str。
     * @param value 待写入值。
     */
    [[gnu::always_inline]] static void Write(RegisterType value) noexcept
        requires(access == Access::ReadWrite || access == Access::WriteOnly)
    {
        *reinterpret_cast<volatile RegisterType*>(BaseAddress) = value;
    }

    /**
     * @brief 置 setBits 中的位、清 clearBits 中的位:非原子 RMW(ldr;bic;orr;str)。
     * @param setBits   需要置 1 的位掩码。
     * @param clearBits 需要清 0 的位掩码。
     */
    [[gnu::always_inline]] static void Modify(RegisterType setBits, RegisterType clearBits) noexcept
        requires(access == Access::ReadWrite)
    {
        Write(static_cast<RegisterType>((Read() & ~clearBits) | setBits));
    }
};

/**
 * @brief 带 Set/Clear/Toggle 别名的 MMIO 寄存器。
 *
 * Sigmatel/STMP/i.MX 家族风格:同一寄存器在另外三个地址(由 SoC 实际偏移
 * 给出)暴露"写即原子置位/清位/翻转"的别名。每个操作是单条 str,硬件保证
 * 原子,无需关中断。无别名的普通寄存器请用 Register,不会为此付出任何代价。
 *
 * @tparam RegisterType   寄存器底层无符号整型。
 * @tparam BaseAddress    主寄存器绝对地址。
 * @tparam SetAddress     原子置位别名地址。
 * @tparam ClearAddress   原子清位别名地址。
 * @tparam ToggleAddress  原子翻转别名地址。
 * @tparam access         访问权限(默认 ReadWrite)。
 */
template <std::unsigned_integral RegisterType, uint32_t BaseAddress,
          uint32_t SetAddress, uint32_t ClearAddress, uint32_t ToggleAddress,
          Access access = Access::ReadWrite>
class RegisterWithSetClearToggle {
    static_assert(BaseAddress % alignof(RegisterType) == 0, "MMIO 地址未对齐");
    static_assert(SetAddress % alignof(RegisterType) == 0, "Set 别名地址未对齐");
    static_assert(ClearAddress % alignof(RegisterType) == 0, "Clear 别名地址未对齐");
    static_assert(ToggleAddress % alignof(RegisterType) == 0, "Toggle 别名地址未对齐");

public:
    using ValueType = RegisterType; /**< 暴露给 Backend/Field 的值类型 */

    RegisterWithSetClearToggle() = delete;
    ~RegisterWithSetClearToggle() = delete;
    RegisterWithSetClearToggle(const RegisterWithSetClearToggle&) = delete;
    RegisterWithSetClearToggle& operator=(const RegisterWithSetClearToggle&) = delete;

    /**
     * @brief 整字读:单条 ldr,按值返回。
     * @return 寄存器当前值。
     */
    [[gnu::always_inline]] [[nodiscard]] static RegisterType Read() noexcept
        requires(access == Access::ReadWrite || access == Access::ReadOnly)
    {
        return *reinterpret_cast<volatile RegisterType*>(BaseAddress);
    }

    /**
     * @brief 整字写:单条 str。
     * @param value 待写入值。
     */
    [[gnu::always_inline]] static void Write(RegisterType value) noexcept
        requires(access == Access::ReadWrite || access == Access::WriteOnly)
    {
        *reinterpret_cast<volatile RegisterType*>(BaseAddress) = value;
    }

    /**
     * @brief 原子置位:单条 str 到 Set 别名地址。
     * @param bits 需要置 1 的位掩码。
     */
    [[gnu::always_inline]] static void Set(RegisterType bits) noexcept
        requires(access == Access::ReadWrite || access == Access::WriteOnly)
    {
        *reinterpret_cast<volatile RegisterType*>(SetAddress) = bits;
    }

    /**
     * @brief 原子清位:单条 str 到 Clear 别名地址。
     * @param bits 需要清 0 的位掩码。
     */
    [[gnu::always_inline]] static void Clear(RegisterType bits) noexcept
        requires(access == Access::ReadWrite || access == Access::WriteOnly)
    {
        *reinterpret_cast<volatile RegisterType*>(ClearAddress) = bits;
    }

    /**
     * @brief 原子翻转:单条 str 到 Toggle 别名地址。
     * @param bits 需要翻转的位掩码。
     */
    [[gnu::always_inline]] static void Toggle(RegisterType bits) noexcept
        requires(access == Access::ReadWrite || access == Access::WriteOnly)
    {
        *reinterpret_cast<volatile RegisterType*>(ToggleAddress) = bits;
    }
};

} // namespace LowLevel

#endif
