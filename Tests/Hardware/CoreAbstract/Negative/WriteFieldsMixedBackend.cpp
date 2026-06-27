/**
 * @file WriteFieldsMixedBackend.cpp
 * @brief 负向编译测试:WriteFields 跨不同后端的字段必须编译失败。
 *
 * 预期失败原因:WriteFields 内 static_assert 要求所有字段属于同一 Backend。
 */
#include "Field.hpp"
#include <cstdint>

using namespace LowLevel;

namespace {
struct BackendA {
    using ValueType = std::uint32_t;
    static inline std::uint32_t storage = 0;
    static std::uint32_t Read() noexcept { return storage; }
    static void Write(std::uint32_t value) noexcept { storage = value; }
};
struct BackendB {
    using ValueType = std::uint32_t;
    static inline std::uint32_t storage = 0;
    static std::uint32_t Read() noexcept { return storage; }
    static void Write(std::uint32_t value) noexcept { storage = value; }
};
} // namespace

using FieldA = Field<BackendA, 0, 4>;
using FieldB = Field<BackendB, 8, 4>;

int main() {
    // 两个字段分属 BackendA / BackendB,违反"同一寄存器"约束。
    WriteFields(MakeFieldValue<FieldA>(0x1u), MakeFieldValue<FieldB>(0x2u));
    return 0;
}
