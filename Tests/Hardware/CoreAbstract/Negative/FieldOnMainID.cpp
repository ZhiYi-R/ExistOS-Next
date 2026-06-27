/**
 * @file FieldOnMainID.cpp
 * @brief 负向编译测试:把 Field 绑定到只读的 MainID 必须编译失败。
 *
 * 预期失败原因:MainID 只有 Read、无 Write,不满足 Backend;Field 带
 * requires Backend<RegisterBackend> 约束。
 */
#include "CP15.hpp"
#include "Field.hpp"

using namespace LowLevel;
using IllegalField = Field<MainID, 0, 4>; // MainID 非 Backend(只读)

int main() {
    (void)sizeof(IllegalField); // 实例化以触发约束失败
    return 0;
}
