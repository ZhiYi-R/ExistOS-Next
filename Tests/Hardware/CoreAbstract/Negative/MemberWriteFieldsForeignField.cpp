/**
 * @file MemberWriteFieldsForeignField.cpp
 * @brief 负向编译测试:Reg::WriteField 写入不属于本寄存器的字段必须编译失败。
 *
 * 动作收归寄存器后,每个字段动作都 static_assert 把字段锚定到发起调用的 Derived
 * (本寄存器)——这正是字段的"归属语义"。此处用 RegA 去写 RegB 的字段,违反归属
 * 约束,故不可编译。
 */
#include "Field.hpp"
#include "Register.hpp"

#include <cstdint>

using namespace LowLevel;

using RegA = Register<std::uint32_t, 0x80000000>;
using RegB = Register<std::uint32_t, 0x80000010>;
using FieldOfB = Field<RegB, 0, 4>; // 属于 RegB

int main() {
    // 用 RegA 写 RegB 的字段:违反"字段必须属于本寄存器"。
    RegA::WriteField<FieldOfB>(0x1u); // 期望:此处不可编译
    return 0;
}
