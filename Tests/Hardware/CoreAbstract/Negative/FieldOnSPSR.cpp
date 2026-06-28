/**
 * @file FieldOnSPSR.cpp
 * @brief 负向编译测试:把 Field 绑定到 Spsr 必须编译失败。
 *
 * 预期失败原因:Spsr 有意不满足 Backend(USR/SYS 读 SPSR 为 UNPREDICTABLE),
 * 而 Field 带 requires Backend<RegisterBackend> 约束。
 */
#include "Field.hpp"
#include "PSR.hpp"
#include <cstdint>

using namespace LowLevel;
using IllegalField = Field<Spsr, Bit::Bit0, 5>; // Spsr 非 Backend

int main() {
    (void)sizeof(IllegalField); // 实例化以触发约束失败
    return 0;
}
