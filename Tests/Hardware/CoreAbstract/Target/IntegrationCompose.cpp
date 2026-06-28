/**
 * @file IntegrationCompose.cpp
 * @brief 集成测试:五个头协同组合的端到端用法,以 -Wall -Wextra -Werror 编为目标 .o。
 *
 * 目的不是运行(含特权汇编/绝对 MMIO,需真机或 QEMU system 模式),而是确保:
 *  - 五个头互相包含、命名空间、模板实例化全部自洽;
 *  - 计划文档里的端到端用法在目标编译器下零警告通过。
 */

#include "CP15.hpp"
#include "Concepts.hpp"
#include "Field.hpp"
#include "PSR.hpp"
#include "Register.hpp"

#include <cstdint>

using namespace LowLevel;

/* ---- 一个示例外设寄存器块(地址仅示意,不绑定真实 SoC) ---- */
using UartData = Register<std::uint32_t, 0x80070000>;
using UartControl =
    RegisterWithSetClearToggle<std::uint32_t, 0x80070030, 0x80070034, 0x80070038,
                               0x8007003C>;
using TxFifoLevel = Field<UartData, Bit::Bit0, 8>;  /**< TX FIFO 计数 */
using RxFifoLevel = Field<UartData, Bit::Bit16, 8>; /**< RX FIFO 计数 */

/* DACR 域配置的强类型用法 */
enum class SpeedSetting : std::uint32_t { Slow = 0, Fast = 1 };

extern "C" void IntegrationScenario() {
    /* 1) MMIO 字段读写 + 多字段单次写入 */
    UartData::WriteField<TxFifoLevel>(0u);
    UartData::WriteFields<TxFifoLevel, RxFifoLevel>(0x10u, 0x20u);
    const std::uint32_t pending{UartData::ReadField<TxFifoLevel>()};

    /* 2) 带别名的原子位操作(单条 str,无需关中断) */
    UartControl::Set(0x1u);
    UartControl::Clear(0x2u);
    UartControl::Toggle(0x4u);

    /* 3) 关中断临界区内的非原子 RMW */
    {
        CriticalSection criticalSection{};
        UartData::Modify(/*setBits=*/pending, /*clearBits=*/0xFFu);
    }

    /* 4) CP15:启用 I-cache(启动期非原子可接受),运行期需原子时走 ModifyAtomic */
    SCTLR::SetField<SCTLR::InstructionCacheEnable>();
    ModifyAtomic<SCTLR>(
        [](std::uint32_t value) { return value | SCTLR::DataCacheEnable::GetMask(); });

    /* 5) DACR 域权限:枚举型字段 */
    DACR::WriteField<DACR::Domain<0>>(DomainAccess::Manager);
    DACR::WriteField<DACR::Domain<1>>(DomainAccess::Client);

    /* 6) cache/TLB 维护 */
    CleanInvalidateDataCacheAll();
    InvalidateInstructionCacheAll();
    InvalidateUnifiedTLBAll();
    DrainWriteBuffer();

    /* 7) 中断屏蔽原语 */
    const std::uint32_t saved{SaveAndDisableInterrupt()};
    RestoreInterrupt(saved);

    /* 8) 特权模式下读取 SPSR(显式 tag) */
    const Mode interruptedMode{Spsr::GetMode(PrivilegedModeTag{})};
    (void)interruptedMode;
}
