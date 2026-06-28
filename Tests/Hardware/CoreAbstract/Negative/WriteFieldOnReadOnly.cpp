/**
 * @file WriteFieldOnReadOnly.cpp
 * @brief 负向编译测试:对只读后端的字段调用 WriteField 必须编译失败。
 *
 * 只读寄存器(此处 CP15 的 MainID,只有 Read、无 Write)允许绑定 Field 做强类型
 * 读取(ReadField/ReadFieldRaw/FieldIsSet/FieldIs),但寄存器侧的写类动作
 * (WriteField/WriteFields/SetField/ClearField/ToggleField)带 `requires Backend<Derived>`
 * 约束——后端不可写,故此处不可编译。
 */
#include "CP15.hpp"
#include "Field.hpp"

using namespace LowLevel;
using ReadOnlyField = Field<MainID, Bit::Bit0, 4>; // MainID 只读:绑定合法,仅可读

int main() {
    MainID::WriteField<ReadOnlyField>(0x1u); // 期望:此处不可编译(只读后端无写能力)
    return 0;
}
