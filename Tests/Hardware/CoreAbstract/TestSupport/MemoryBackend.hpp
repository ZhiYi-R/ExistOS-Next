#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_TESTS_MEMORY_BACKEND
#define EXIST_OS_NEXT_CORE_ABSTRACT_TESTS_MEMORY_BACKEND

/**
 * @file MemoryBackend.hpp
 * @brief 内存后端测试替身：用一格静态存储模拟寄存器，让 Field 等逻辑可在主机真跑。
 *
 * 真实的 Register/CP15/CPSR 后端要么解引用绝对 MMIO 地址、要么执行特权内联汇编，
 * 在主机(x86)上无法运行。但 Field 的全部算术(掩码/移位/读-改-写/多字段合并)只
 * 依赖 Backend 的 Read/Write 抽象，与具体后端无关。于是用一个满足 Backend 的内存
 * 替身，就能在主机上对 Field 的逻辑核心做真值核对。
 *
 * 每个不同的 Tag 类型拥有一份独立存储，便于用例之间互不串扰。
 */

#include "Field.hpp"

#include <cstdint>

namespace TestSupport {

/**
 * @brief 满足 Backend 的内存后端替身。
 * @tparam Tag   区分独立实例的标签类型(每个 Tag 一份存储)。
 * @tparam Value 寄存器底层无符号整型。
 */
template <typename Tag, typename Value = std::uint32_t>
struct MemoryBackend : LowLevel::FieldAccess<MemoryBackend<Tag, Value>> {
    using ValueType = Value;            /**< 暴露给 Backend/Field 的值类型 */
    static inline Value storage = Value{0}; /**< 模拟寄存器的存储格 */

    /** @brief 读当前值。 */
    [[nodiscard]] static Value Read() noexcept { return storage; }
    /** @brief 写入新值。 */
    static void Write(Value value) noexcept { storage = value; }
    /** @brief 复位存储(测试前置)。 */
    static void Reset(Value value = Value{0}) noexcept { storage = value; }
};

/**
 * @brief 额外满足 HasSetClearToggle 的内存后端替身。
 *
 * 模拟 SET/CLR/TOG 别名硬件的"单次写即位操作"语义,供概念满足性与组合测试使用。
 *
 * @tparam Tag   区分独立实例的标签类型。
 * @tparam Value 寄存器底层无符号整型。
 */
template <typename Tag, typename Value = std::uint32_t>
struct MemoryBackendWithSetClearToggle
    : LowLevel::FieldAccess<MemoryBackendWithSetClearToggle<Tag, Value>> {
    using ValueType = Value;            /**< 暴露给 Backend/Field 的值类型 */
    static inline Value storage = Value{0}; /**< 模拟寄存器的存储格 */

    /** @brief 读当前值。 */
    [[nodiscard]] static Value Read() noexcept { return storage; }
    /** @brief 写入新值。 */
    static void Write(Value value) noexcept { storage = value; }
    /** @brief 原子置位(模拟 SET 别名)。 */
    static void Set(Value bits) noexcept { storage |= bits; }
    /** @brief 原子清位(模拟 CLR 别名)。 */
    static void Clear(Value bits) noexcept { storage &= static_cast<Value>(~bits); }
    /** @brief 原子翻转(模拟 TOG 别名)。 */
    static void Toggle(Value bits) noexcept { storage ^= bits; }
    /** @brief 复位存储(测试前置)。 */
    static void Reset(Value value = Value{0}) noexcept { storage = value; }
};

} // namespace TestSupport

#endif
