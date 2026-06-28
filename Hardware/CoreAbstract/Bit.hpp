#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_BIT
#define EXIST_OS_NEXT_CORE_ABSTRACT_BIT

#include <cstdint>

/**
 * @file Bit.hpp
 * @brief 强类型位索引枚举,供 Field 表达字段最低位,杜绝裸位号 magic number。
 *
 * 设计:位偏移本质是"第几位",而非任意整数。用 enum class 把它与普通 uint32_t
 * 隔开,既让字段定义 `Field<Reg, Bit::Bit12, 1>` 自解释,又从类型层面防止把位宽
 * 当偏移误插(Bit 与 uint32_t 不可隐式互转)。转为底层整型是编译期常量,零开销。
 */

namespace LowLevel {

/**
 * @brief 位索引(0..31,覆盖当前最宽的 32 位寄存器)。
 *
 * 仅作 Field 的 Offset 模板实参;下游掩码/移位仍以 uint32_t(Field::BitOffset)运算。
 * 若日后出现 64 位寄存器,在此扩充到 Bit63 即可。
 */
enum class Bit : std::uint32_t {
    Bit0 = 0, Bit1,  Bit2,  Bit3,  Bit4,  Bit5,  Bit6,  Bit7,
    Bit8,     Bit9,  Bit10, Bit11, Bit12, Bit13, Bit14, Bit15,
    Bit16,    Bit17, Bit18, Bit19, Bit20, Bit21, Bit22, Bit23,
    Bit24,    Bit25, Bit26, Bit27, Bit28, Bit29, Bit30, Bit31,
};

} // namespace LowLevel

#endif
