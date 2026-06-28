/**
 * @file ZeroOverheadProbes.cpp
 * @brief 零开销验证探针:每个访问器封进一个 extern "C" 包装,便于 objdump 按符号
 *        逐项核对生成指令。本文件由 SConstruct 用 arm-none-eabi-g++ -O2 编译,
 *        再反汇编断言"单指令 / 无 bl / 无 ldrex / 临界区无栈溢出 / test-clean 用 r15"。
 *
 * 注意:函数体均含 volatile MMIO 或 volatile 内联汇编,故 -O2 下不会被优化掉;
 * extern "C" 保证符号名稳定可被脚本定位。
 */

#include "CP15.hpp"
#include "Field.hpp"
#include "PSR.hpp"
#include "Register.hpp"

#include <cstdint>

using namespace LowLevel;

/* 示例 MMIO 地址(不绑定真实 SoC):主寄存器 + SET/CLR/TOG 别名。 */
using Mmio = Register<std::uint32_t, 0x80070000>;
using AliasReg =
    RegisterWithSetClearToggle<std::uint32_t, 0x80070000, 0x80070004, 0x80070008,
                               0x8007000C>;
using LowByte = Field<Mmio, Bit::Bit0, 8>;   /**< 位[7:0] */
using HighNibble = Field<Mmio, Bit::Bit8, 4>; /**< 位[11:8] */
using AliasField = Field<AliasReg, Bit::Bit8, 4>; /**< 带别名后端上的位[11:8] */

extern "C" {

/* ============================ MMIO ============================ */
std::uint32_t ProbeRegisterRead() { return Mmio::Read(); }                 // 1×ldr
void ProbeRegisterWrite(std::uint32_t value) { Mmio::Write(value); }       // 1×str
void ProbeRegisterModify(std::uint32_t setBits, std::uint32_t clearBits) { // 非原子 RMW
    Mmio::Modify(setBits, clearBits);
}
void ProbeAliasSet(std::uint32_t bits) { AliasReg::Set(bits); }       // 1×str→SET 别名
void ProbeAliasClear(std::uint32_t bits) { AliasReg::Clear(bits); }   // 1×str→CLR 别名
void ProbeAliasToggle(std::uint32_t bits) { AliasReg::Toggle(bits); } // 1×str→TOG 别名

/* ====================== Field over MMIO ====================== */
std::uint32_t ProbeFieldRead() { return Mmio::ReadField<LowByte>(); }           // ldr + and/lsr
void ProbeFieldWrite(std::uint32_t value) { Mmio::WriteField<LowByte>(value); } // 非原子 RMW
void ProbeFieldSet() { Mmio::SetField<LowByte>(); }                            // 非原子 RMW
void ProbeWriteFields(std::uint32_t low, std::uint32_t high) {                  // 单次合并 RMW
    Mmio::WriteFields<LowByte, HighNibble>(low, high);
}

/* 字段级 Set/Clear/Toggle 在带别名后端上应分派到单条原子 str(无回读 RMW)。 */
void ProbeAliasFieldSet() { AliasReg::SetField<AliasField>(); }       // 1×str→SET 别名
void ProbeAliasFieldClear() { AliasReg::ClearField<AliasField>(); }   // 1×str→CLR 别名
void ProbeAliasFieldToggle() { AliasReg::ToggleField<AliasField>(); } // 1×str→TOG 别名

/* ============================ PSR ============================ */
std::uint32_t ProbeCPSRRead() { return Cpsr::Read(); }         // 1×mrs
void ProbeDisableInterrupt() { DisableInterrupt(); }           // mrs;orr;msr
void ProbeEnableInterrupt() { EnableInterrupt(); }             // mrs;bic;msr
std::uint32_t ProbeSaveAndDisableInterrupt() { return SaveAndDisableInterrupt(); }
void ProbeRestoreInterrupt(std::uint32_t saved) { RestoreInterrupt(saved); } // 1×msr
void ProbeCriticalSection(std::uint32_t value) {               // RAII:无 push/pop/sp
    CriticalSection criticalSection{};
    Mmio::Write(value);
}
void ProbeModifyAtomic(std::uint32_t orBits) {                 // 关中断内 RMW,无 bl
    ModifyAtomic<Mmio>([orBits](std::uint32_t old) { return old | orBits; });
}

/* ============================ CP15 ============================ */
std::uint32_t ProbeSCTLRRead() { return SCTLR::Read(); }       // 1×mrc
void ProbeSCTLRWrite(std::uint32_t value) { SCTLR::Write(value); } // 1×mcr
void ProbeSCTLRFieldSet() { SCTLR::SetField<SCTLR::InstructionCacheEnable>(); } // mrc;orr;mcr
void ProbeInvalidateInstructionCacheAll() { InvalidateInstructionCacheAll(); } // mcr c7,c5,0
void ProbeDrainWriteBuffer() { DrainWriteBuffer(); }           // mcr c7,c10,4
void ProbeInvalidateUnifiedTLBAll() { InvalidateUnifiedTLBAll(); } // mcr c8,c7,0
void ProbeInvalidateDataCacheLine(std::uint32_t modifiedVirtualAddress) {
    InvalidateDataCacheLine(modifiedVirtualAddress);           // mcr c7,c6,1
}
void ProbeCleanDataCacheAll() { CleanDataCacheAll(); }         // mrc r15 c7,c10,3 循环 + 排空
void ProbeCleanInvalidateDataCacheAll() { CleanInvalidateDataCacheAll(); } // mrc r15 c7,c14,3 循环 + 排空

/* ============================ SPSR ============================ */
std::uint32_t ProbeSPSRRead() { return Spsr::Read(PrivilegedModeTag{}); } // mrs ...,spsr
void ProbeSPSRWrite(std::uint32_t value) { Spsr::Write(PrivilegedModeTag{}, value); }
std::uint32_t ProbeSPSRGetMode() {
    return static_cast<std::uint32_t>(Spsr::GetMode(PrivilegedModeTag{}));
}

} // extern "C"
