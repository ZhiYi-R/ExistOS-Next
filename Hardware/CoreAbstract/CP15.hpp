#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_CP15
#define EXIST_OS_NEXT_CORE_ABSTRACT_CP15

#include "Field.hpp"
#include <cstdint>

/**
 * @file CP15.hpp
 * @brief CP15 系统控制协处理器(ARM926EJ-S / ARMv5TEJ)的纯模板特化。
 *
 * 每个寄存器一个类型,手写 mrc/mcr 内联汇编,不用任何宏。mrc/mcr 的协处理器
 * 坐标 (opc1,CRn,CRm,opc2) 必须是字面立即数,因此无法参数化——这正是"一个
 * 寄存器一个类型"的根本原因。
 *
 * 约定:
 *  - 所有 MRC(读)用 asm volatile,禁止 CSE/重排。
 *  - 所有 MCR(写/命令)带 "memory" clobber,作为编译屏障。
 *  - RW 寄存器满足 Backend,可配合 Field;只写命令建模为自由函数。
 */

namespace LowLevel {

/**
 * @brief c1,c0,0 —— SCTLR 系统控制寄存器(RW,Backend)。
 *
 * @note 位字段使用全称命名,注释中给出 ARMv5TEJ TRM 的位字母,勿照搬 ARMv7 布局。
 */
struct SCTLR : FieldAccess<SCTLR> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */

    /** @brief 读 SCTLR:单条 mrc。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c1, c0, 0" : "=r"(value));
        return value;
    }
    /** @brief 写 SCTLR:单条 mcr。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c1, c0, 0" : : "r"(value) : "memory");
    }

    using MmuEnable = Field<SCTLR, Bit::Bit0, 1>;               /**< M:MMU 使能 */
    using AlignmentCheckEnable = Field<SCTLR, Bit::Bit1, 1>;    /**< A:对齐检查使能 */
    using DataCacheEnable = Field<SCTLR, Bit::Bit2, 1>;         /**< C:D-cache 使能 */
    using WriteBufferEnable = Field<SCTLR, Bit::Bit3, 1>;       /**< W:写缓冲使能 */
    using BigEndian = Field<SCTLR, Bit::Bit7, 1>;               /**< B:大端 */
    using SystemProtection = Field<SCTLR, Bit::Bit8, 1>;        /**< S:系统保护 */
    using RomProtection = Field<SCTLR, Bit::Bit9, 1>;           /**< R:ROM 保护 */
    using InstructionCacheEnable = Field<SCTLR, Bit::Bit12, 1>; /**< I:I-cache 使能 */
    using HighVectors = Field<SCTLR, Bit::Bit13, 1>;            /**< V:高位异常向量(0xFFFF0000) */
    using RoundRobinReplacement = Field<SCTLR, Bit::Bit14, 1>;  /**< RR:round-robin 替换 */
    using ThumbInterworkingDisable = Field<SCTLR, Bit::Bit15, 1>; /**< L4:抑制加载到 PC 时切 Thumb */
};

/**
 * @brief c0,c0,0 —— 主标识寄存器(只读,非 Backend:仅 Read)。
 */
struct MainID : FieldAccess<MainID> {
    using ValueType = uint32_t; /**< 值类型(注意:只读,不满足 Backend) */
    /** @brief 读主 ID。 @return MIDR 值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c0, c0, 0" : "=r"(value));
        return value;
    }
};

/**
 * @brief c0,c0,1 —— Cache 类型寄存器(只读,非 Backend)。
 */
struct CacheType : FieldAccess<CacheType> {
    using ValueType = uint32_t; /**< 值类型(注意:只读,不满足 Backend) */
    /** @brief 读 Cache 类型。 @return CTR 值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r"(value));
        return value;
    }
};

/**
 * @brief c0,c0,2 —— TCM 状态寄存器(只读,非 Backend)。
 */
struct TCMStatus : FieldAccess<TCMStatus> {
    using ValueType = uint32_t; /**< 值类型(注意:只读,不满足 Backend) */
    /** @brief 读 TCM 状态。 @return TCM 状态值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c0, c0, 2" : "=r"(value));
        return value;
    }
};

/**
 * @brief c2,c0,0 —— TTBR0 翻译表基址(RW,Backend)。
 */
struct TTBR0 : FieldAccess<TTBR0> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 TTBR0:单条 mrc。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c2, c0, 0" : "=r"(value));
        return value;
    }
    /** @brief 写 TTBR0:单条 mcr。 @param value 翻译表基址。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c2, c0, 0" : : "r"(value) : "memory");
    }
};

/**
 * @brief 域访问权限(DACR 每域 2 位)。
 */
enum class DomainAccess : uint32_t {
    NoAccess = 0b00, /**< 任何访问触发域故障 */
    Client = 0b01,   /**< 按页表权限检查 */
    Manager = 0b11,  /**< 不检查权限 */
};

/**
 * @brief c3,c0,0 —— DACR 域访问控制(RW,Backend)。
 *
 * 16 个域,每域 2 位:Domain0[1:0] … Domain15[31:30]。
 */
struct DACR : FieldAccess<DACR> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 DACR:单条 mrc。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c3, c0, 0" : "=r"(value));
        return value;
    }
    /** @brief 写 DACR:单条 mcr。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c3, c0, 0" : : "r"(value) : "memory");
    }

    /**
     * @brief 第 N 个域的 2 位访问权限字段。
     * @tparam N 域编号(0..15)。
     */
    template <uint32_t N>
    using Domain = Field<DACR, static_cast<Bit>(2 * N), 2, DomainAccess>;
};

/**
 * @brief c5,c0,0 —— DFSR 数据故障状态寄存器(RW,Backend)。
 */
struct DFSR : FieldAccess<DFSR> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 DFSR。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c5, c0, 0" : "=r"(value));
        return value;
    }
    /** @brief 写 DFSR。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c5, c0, 0" : : "r"(value) : "memory");
    }
};

/**
 * @brief c5,c0,1 —— IFSR 指令故障状态寄存器(RW,Backend)。
 */
struct IFSR : FieldAccess<IFSR> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 IFSR。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c5, c0, 1" : "=r"(value));
        return value;
    }
    /** @brief 写 IFSR。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c5, c0, 1" : : "r"(value) : "memory");
    }
};

/**
 * @brief c6,c0,0 —— FAR 故障地址寄存器(RW,Backend)。
 */
struct FAR : FieldAccess<FAR> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 FAR。 @return 触发故障的地址。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c6, c0, 0" : "=r"(value));
        return value;
    }
    /** @brief 写 FAR。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c6, c0, 0" : : "r"(value) : "memory");
    }
};

/**
 * @brief c13,c0,0 —— FCSE PID 快速上下文切换扩展 PID(RW,Backend)。
 */
struct FCSE_PID : FieldAccess<FCSE_PID> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 FCSE PID。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c13, c0, 0" : "=r"(value));
        return value;
    }
    /** @brief 写 FCSE PID。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c13, c0, 0" : : "r"(value) : "memory");
    }
};

/**
 * @brief c13,c0,1 —— Context ID 寄存器(RW,Backend)。
 */
struct ContextID : FieldAccess<ContextID> {
    using ValueType = uint32_t; /**< 暴露给 Backend/Field 的值类型 */
    /** @brief 读 Context ID。 @return 当前值。 */
    [[gnu::always_inline]] [[nodiscard]] static uint32_t Read() noexcept {
        uint32_t value;
        asm volatile("mrc p15, 0, %0, c13, c0, 1" : "=r"(value));
        return value;
    }
    /** @brief 写 Context ID。 @param value 待写入值。 */
    [[gnu::always_inline]] static void Write(uint32_t value) noexcept {
        asm volatile("mcr p15, 0, %0, c13, c0, 1" : : "r"(value) : "memory");
    }
};

/* ================================================================== *
 * c7 —— Cache 维护命令(只写,自由函数,非 Backend)
 * 全部带 "memory" clobber 防止编译器越过它重排访存。
 * ================================================================== */

/** @brief 失效整个 I-cache(mcr c7,c5,0)。 */
[[gnu::always_inline]] inline void InvalidateInstructionCacheAll() noexcept {
    asm volatile("mcr p15, 0, %0, c7, c5, 0" : : "r"(0) : "memory");
}
/** @brief 失效整个 D-cache(不回写,丢弃脏行——慎用)。 */
[[gnu::always_inline]] inline void InvalidateDataCacheAll() noexcept {
    asm volatile("mcr p15, 0, %0, c7, c6, 0" : : "r"(0) : "memory");
}
/** @brief 失效整个 I-cache + D-cache。 */
[[gnu::always_inline]] inline void InvalidateBothCachesAll() noexcept {
    asm volatile("mcr p15, 0, %0, c7, c7, 0" : : "r"(0) : "memory");
}
/** @brief 排空写缓冲(Drain Write Buffer / DSB 的 ARMv5 形态)。 */
[[gnu::always_inline]] inline void DrainWriteBuffer() noexcept {
    asm volatile("mcr p15, 0, %0, c7, c10, 4" : : "r"(0) : "memory");
}
/** @brief 刷新预取缓冲(Flush Prefetch Buffer)。 */
[[gnu::always_inline]] inline void FlushPrefetchBuffer() noexcept {
    asm volatile("mcr p15, 0, %0, c7, c5, 4" : : "r"(0) : "memory");
}
/** @brief 等待中断(进入低功耗直到中断,ARMv5 的 WFI)。 */
[[gnu::always_inline]] inline void WaitForInterrupt() noexcept {
    asm volatile("mcr p15, 0, %0, c7, c0, 4" : : "r"(0) : "memory");
}

/**
 * @brief 失效单条 D-cache 行(按 MVA)。
 * @param modifiedVirtualAddress 目标行的修正虚拟地址。
 */
[[gnu::always_inline]] inline void InvalidateDataCacheLine(uint32_t modifiedVirtualAddress) noexcept {
    asm volatile("mcr p15, 0, %0, c7, c6, 1" : : "r"(modifiedVirtualAddress) : "memory");
}
/**
 * @brief 清(回写)单条 D-cache 行(按 MVA)。
 * @param modifiedVirtualAddress 目标行的修正虚拟地址。
 */
[[gnu::always_inline]] inline void CleanDataCacheLine(uint32_t modifiedVirtualAddress) noexcept {
    asm volatile("mcr p15, 0, %0, c7, c10, 1" : : "r"(modifiedVirtualAddress) : "memory");
}
/**
 * @brief 清并失效单条 D-cache 行(按 MVA)。
 * @param modifiedVirtualAddress 目标行的修正虚拟地址。
 */
[[gnu::always_inline]] inline void CleanInvalidateDataCacheLine(uint32_t modifiedVirtualAddress) noexcept {
    asm volatile("mcr p15, 0, %0, c7, c14, 1" : : "r"(modifiedVirtualAddress) : "memory");
}

/* ------------------------------------------------------------------ *
 * ARM926 专有:test-clean 全 D-cache 循环
 * c7 没有"一次性清整个 D-cache"的 MCR;只能反复执行特殊 MRC——其目标
 * 必须是 r15(PC),把 Z 标志置为"是否已全部清完",再 bne 回跳。
 * 数字局部标号 1: / 1b 即使函数被多次内联也安全(每个 asm 块独立)。
 * ------------------------------------------------------------------ */

/**
 * @brief 清(回写但不失效)整个 D-cache,然后排空写缓冲。
 */
[[gnu::always_inline]] inline void CleanDataCacheAll() noexcept {
    asm volatile("1:\n\t"
                 "mrc p15, 0, r15, c7, c10, 3\n\t"
                 "bne 1b"
                 :
                 :
                 : "cc", "memory");
    DrainWriteBuffer();
}

/**
 * @brief 清并失效整个 D-cache,然后排空写缓冲。
 */
[[gnu::always_inline]] inline void CleanInvalidateDataCacheAll() noexcept {
    asm volatile("1:\n\t"
                 "mrc p15, 0, r15, c7, c14, 3\n\t"
                 "bne 1b"
                 :
                 :
                 : "cc", "memory");
    DrainWriteBuffer();
}

/* ================================================================== *
 * c8 —— TLB 维护命令(只写,自由函数,非 Backend)
 * ================================================================== */

/** @brief 失效整个统一 TLB(mcr c8,c7,0)。 */
[[gnu::always_inline]] inline void InvalidateUnifiedTLBAll() noexcept {
    asm volatile("mcr p15, 0, %0, c8, c7, 0" : : "r"(0) : "memory");
}
/** @brief 失效整个 I-TLB。 */
[[gnu::always_inline]] inline void InvalidateInstructionTLBAll() noexcept {
    asm volatile("mcr p15, 0, %0, c8, c5, 0" : : "r"(0) : "memory");
}
/** @brief 失效整个 D-TLB。 */
[[gnu::always_inline]] inline void InvalidateDataTLBAll() noexcept {
    asm volatile("mcr p15, 0, %0, c8, c6, 0" : : "r"(0) : "memory");
}
/**
 * @brief 失效单条 TLB 项(按 MVA)。
 * @param modifiedVirtualAddress 目标项的修正虚拟地址。
 */
[[gnu::always_inline]] inline void InvalidateTLBEntry(uint32_t modifiedVirtualAddress) noexcept {
    asm volatile("mcr p15, 0, %0, c8, c7, 1" : : "r"(modifiedVirtualAddress) : "memory");
}

} // namespace LowLevel

#endif
