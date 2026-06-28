/**
 * @file WriteFieldsMixedBackend.cpp
 * @brief 负向编译测试:Reg::WriteFields 混入别的寄存器的字段必须编译失败。
 *
 * 预期失败原因:WriteFields 内 static_assert 要求所有字段都属于发起调用的本寄存器。
 * 这里用 BackendA 的 WriteFields 去写一个 BackendB 的字段,违反归属约束。
 */
#include "Field.hpp"
#include <cstdint>

using namespace LowLevel;

namespace {
struct BackendA : FieldAccess<BackendA> {
    using ValueType = std::uint32_t;
    static inline std::uint32_t storage = 0;
    static std::uint32_t Read() noexcept { return storage; }
    static void Write(std::uint32_t value) noexcept { storage = value; }
};
struct BackendB : FieldAccess<BackendB> {
    using ValueType = std::uint32_t;
    static inline std::uint32_t storage = 0;
    static std::uint32_t Read() noexcept { return storage; }
    static void Write(std::uint32_t value) noexcept { storage = value; }
};
} // namespace

using FieldA = Field<BackendA, Bit::Bit0, 4>;
using FieldB = Field<BackendB, Bit::Bit8, 4>; // 属于 BackendB

int main() {
    // FieldB 不属于 BackendA,违反"所有字段必须属于本寄存器"约束。
    BackendA::WriteFields<FieldA, FieldB>(0x1u, 0x2u); // 期望:此处不可编译
    return 0;
}
