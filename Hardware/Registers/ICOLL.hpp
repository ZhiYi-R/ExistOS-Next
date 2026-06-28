#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_ICOLL
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_ICOLL

/**
 * @file ICOLL.hpp
 * @brief ICOLL 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * ICOLL 中断收集器，负责 ARM926EJ-S 中断请求(IRQ)与快速中断请求(FIQ)的优先级仲裁、向量分发及状态管理。注：SRC 1(JTAG调试)由ARM JTAG TAP控制器直接处理，不经过ICOLL。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::ICOLL {

    /** @brief 中断向量地址寄存器，存储当前最高优先级中断的向量字地址，ISR 读取后可直接跳转。 */
    namespace VECTOR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000000, 0x80000004, 0x80000008, 0x8000000C, LowLevel::Access::ReadWrite>;
        using IRQVECTOR = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 30, std::uint32_t>; /**< 当前中断向量字地址，占 bit[31:2]，对应 4 字节对齐的中断入口地址。 */
    } // namespace VECTOR

    /** @brief 中断优先级确认寄存器，ISR 结束时写入对应位以清除指定优先级的中断服务状态。 */
    namespace LEVELACK {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000010, 0x80000014, 0x80000018, 0x8000001C, LowLevel::Access::ReadWrite>;
        /** @brief IRQLEVELACK 的取值。 */
        enum class IRQLEVELACK_Values : std::uint32_t {
            LEVEL0 = 0x1,
            LEVEL1 = 0x2,
            LEVEL2 = 0x4,
            LEVEL3 = 0x8,
        };
        using IRQLEVELACK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, IRQLEVELACK_Values>; /**< 写 1<<level 确认对应优先级中断，可写 LEVEL0(0x1)、LEVEL1(0x2)、LEVEL2(0x4)、LEVEL3(0x8)。 */
    } // namespace LEVELACK

    /** @brief 中断收集器全局控制寄存器，配置 IRQ/FIQ 总使能、嵌套策略、向量表间距及模块复位/时钟门控。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000020, 0x80000024, 0x80000028, 0x8000002C, LowLevel::Access::ReadWrite>;
        using ENABLE2FIQ_T0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Timer 0 FIQ 路由使能，置位后 Timer 0 中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ_T1 = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Timer 1 FIQ 路由使能，置位后 Timer 1 中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ_T2 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Timer 2 FIQ 路由使能，置位后 Timer 2 中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ_T3 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Timer 3 FIQ 路由使能，置位后 Timer 3 中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ32 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 中断源 32(BATT_BRNOUT)FIQ 路由使能，置位后对应中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ33 = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 中断源 33(VDDD_BRNOUT)FIQ 路由使能，置位后对应中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ34 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 中断源 34(VDDIO_BRNOUT)FIQ 路由使能，置位后对应中断改为 FIQ 方式送达 ARM 核。 */
        using ENABLE2FIQ35 = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 中断源 35(VDD18_BRNOUT)FIQ 路由使能，置位后对应中断改为 FIQ 方式送达 ARM 核。 */
        /** @brief IRQ_FINAL_ENABLE 的取值。 */
        enum class IRQ_FINAL_ENABLE_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using IRQ_FINAL_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, IRQ_FINAL_ENABLE_Values>; /**< IRQ 总使能开关，ENABLE 时允许向 ARM 发出 IRQ 请求。 */
        /** @brief FIQ_FINAL_ENABLE 的取值。 */
        enum class FIQ_FINAL_ENABLE_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using FIQ_FINAL_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, FIQ_FINAL_ENABLE_Values>; /**< FIQ 总使能开关，ENABLE 时允许向 ARM 发出 FIQ 请求。 */
        using ARM_RSE_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< ARM 读副作用模式，使能后读取 VECTOR 寄存器会触发 ICOLL 内部状态转换。 */
        /** @brief NO_NESTING 的取值。 */
        enum class NO_NESTING_Values : std::uint32_t {
            NORMAL = 0x0,
            NO_NEST = 0x1,
        };
        using NO_NESTING = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, NO_NESTING_Values>; /**< 禁止中断嵌套，NO_NEST 时 ICOLL 不响应更低或同级优先级的新中断。 */
        /** @brief BYPASS_FSM 的取值。 */
        enum class BYPASS_FSM_Values : std::uint32_t {
            NORMAL = 0x0,
            BYPASS = 0x1,
        };
        using BYPASS_FSM = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, BYPASS_FSM_Values>; /**< FSM 旁路模式，BYPASS 时绕过内部向量状态机，用于调试或特殊操作模式。 */
        /** @brief VECTOR_PITCH 的取值。 */
        enum class VECTOR_PITCH_Values : std::uint32_t {
            DEFAULT_BY4 = 0x0,
            BY4 = 0x1,
            BY8 = 0x2,
            BY12 = 0x3,
            BY16 = 0x4,
            BY20 = 0x5,
            BY24 = 0x6,
            BY28 = 0x7,
        };
        using VECTOR_PITCH = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 3, VECTOR_PITCH_Values>; /**< 向量表项间距，枚举值 DEFAULT_BY4(默认)、BY4、BY8、BY12、BY16、BY20、BY24、BY28。 */
        /** @brief CLKGATE 的取值。 */
        enum class CLKGATE_Values : std::uint32_t {
            RUN = 0x0,
            NO_CLOCKS = 0x1,
        };
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, CLKGATE_Values>; /**< 时钟门控，NO_CLOCKS 时关闭 ICOLL 模块时钟以节省功耗。 */
        /** @brief SFTRST 的取值。 */
        enum class SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            IN_RESET = 0x1,
        };
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, SFTRST_Values>; /**< 软复位，IN_RESET 时对整个 ICOLL 模块执行软件复位。 */
    } // namespace CTRL

    /** @brief 中断收集器状态寄存器，反映当前正在服务的中断编号。 */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000030, 0x80000034, 0x80000038, 0x8000003C, LowLevel::Access::ReadWrite>;
        using VECTOR_NUMBER = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 6, std::uint32_t>; /**< 当前正在服务的中断向量号，取值范围对应各中断源编号。 */
    } // namespace STAT

    /** @brief 原始中断状态寄存器数组，每位反映对应中断源的原始硬件请求状态，不受使能控制影响。 */
    namespace RAW0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000040, 0x80000044, 0x80000048, 0x8000004C, LowLevel::Access::ReadWrite>;
        using RAW_IRQS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位原始中断请求状态位图，1 表示对应中断源存在未处理硬件请求。 */
    } // namespace RAW0

    /** @brief 原始中断状态寄存器数组，每位反映对应中断源的原始硬件请求状态，不受使能控制影响。 */
    namespace RAW1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000050, 0x80000054, 0x80000058, 0x8000005C, LowLevel::Access::ReadWrite>;
        using RAW_IRQS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位原始中断请求状态位图，1 表示对应中断源存在未处理硬件请求。 */
    } // namespace RAW1

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000060, 0x80000064, 0x80000068, 0x8000006C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY0

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000070, 0x80000074, 0x80000078, 0x8000007C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY1

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000080, 0x80000084, 0x80000088, 0x8000008C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY2

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000090, 0x80000094, 0x80000098, 0x8000009C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY3

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800000A0, 0x800000A4, 0x800000A8, 0x800000AC, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY4

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800000B0, 0x800000B4, 0x800000B8, 0x800000BC, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY5

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800000C0, 0x800000C4, 0x800000C8, 0x800000CC, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY6

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY7 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800000D0, 0x800000D4, 0x800000D8, 0x800000DC, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY7

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY8 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800000E0, 0x800000E4, 0x800000E8, 0x800000EC, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY8

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY9 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800000F0, 0x800000F4, 0x800000F8, 0x800000FC, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY9

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY10 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000100, 0x80000104, 0x80000108, 0x8000010C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY10

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY11 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000110, 0x80000114, 0x80000118, 0x8000011C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY11

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY12 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000120, 0x80000124, 0x80000128, 0x8000012C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY12

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY13 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000130, 0x80000134, 0x80000138, 0x8000013C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY13

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY14 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000140, 0x80000144, 0x80000148, 0x8000014C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY14

    /** @brief 中断优先级配置寄存器数组，每个寄存器管理 4 个中断源的优先级、使能及软件触发。 */
    namespace PRIORITY15 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000150, 0x80000154, 0x80000158, 0x8000015C, LowLevel::Access::ReadWrite>;
        /** @brief PRIORITY0 的取值。 */
        enum class PRIORITY0_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, PRIORITY0_Values>; /**< 中断源 0 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE0 的取值。 */
        enum class ENABLE0_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ENABLE0_Values>; /**< 中断源 0 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ0 的取值。 */
        enum class SOFTIRQ0_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, SOFTIRQ0_Values>; /**< 中断源 0 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY1 的取值。 */
        enum class PRIORITY1_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, PRIORITY1_Values>; /**< 中断源 1 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE1 的取值。 */
        enum class ENABLE1_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, ENABLE1_Values>; /**< 中断源 1 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ1 的取值。 */
        enum class SOFTIRQ1_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, SOFTIRQ1_Values>; /**< 中断源 1 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY2 的取值。 */
        enum class PRIORITY2_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, PRIORITY2_Values>; /**< 中断源 2 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE2 的取值。 */
        enum class ENABLE2_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, ENABLE2_Values>; /**< 中断源 2 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ2 的取值。 */
        enum class SOFTIRQ2_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, SOFTIRQ2_Values>; /**< 中断源 2 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
        /** @brief PRIORITY3 的取值。 */
        enum class PRIORITY3_Values : std::uint32_t {
            LEVEL0 = 0x0,
            LEVEL1 = 0x1,
            LEVEL2 = 0x2,
            LEVEL3 = 0x3,
        };
        using PRIORITY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, PRIORITY3_Values>; /**< 中断源 3 的优先级，LEVEL0 最低，LEVEL3 最高。 */
        /** @brief ENABLE3 的取值。 */
        enum class ENABLE3_Values : std::uint32_t {
            DISABLE = 0x0,
            ENABLE = 0x1,
        };
        using ENABLE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, ENABLE3_Values>; /**< 中断源 3 的使能开关，ENABLE 时允许该中断参与仲裁。 */
        /** @brief SOFTIRQ3 的取值。 */
        enum class SOFTIRQ3_Values : std::uint32_t {
            NO_INTERRUPT = 0x0,
            FORCE_INTERRUPT = 0x1,
        };
        using SOFTIRQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, SOFTIRQ3_Values>; /**< 中断源 3 的软件触发，FORCE_INTERRUPT 时强制产生软件中断请求。 */
    } // namespace PRIORITY15

    /** @brief 中断向量基地址寄存器，存放中断向量表的字地址，供 ICOLL 计算最终跳转地址。 */
    namespace VBASE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80000160, 0x80000164, 0x80000168, 0x8000016C, LowLevel::Access::ReadWrite>;
        using TABLE_ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 30, std::uint32_t>; /**< 中断向量表基地址的字地址，占 bit[31:2]，低 2 位固定为 0 即 4 字节对齐。 */
    } // namespace VBASE

    /** @brief 中断收集器调试寄存器，暴露内部向量 FSM 状态、IRQ/FIQ 请求线及各优先级请求/服务状态。 */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80001120, LowLevel::Access::ReadOnly>;
        /** @brief VECTOR_FSM 的取值。 */
        enum class VECTOR_FSM_Values : std::uint32_t {
            FSM_IDLE = 0x0,
            FSM_MULTICYCLE1 = 0x1,
            FSM_MULTICYCLE2 = 0x2,
            FSM_PENDING = 0x4,
            FSM_MULTICYCLE3 = 0x8,
            FSM_MULTICYCLE4 = 0x10,
            FSM_ISR_RUNNING1 = 0x20,
            FSM_ISR_RUNNING2 = 0x40,
            FSM_ISR_RUNNING3 = 0x80,
            FSM_MULTICYCLE5 = 0x100,
            FSM_MULTICYCLE6 = 0x200,
        };
        using VECTOR_FSM = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, VECTOR_FSM_Values>; /**< 向量 FSM 当前状态，枚举值覆盖 IDLE、PENDING、多周期处理及 ISR 运行等阶段。 */
        /** @brief IRQ 的取值。 */
        enum class IRQ_Values : std::uint32_t {
            NO_IRQ_REQUESTED = 0x0,
            IRQ_REQUESTED = 0x1,
        };
        using IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, IRQ_Values>; /**< IRQ 请求状态，IRQ_REQUESTED 表示当前存在向 ARM 的 IRQ 请求。 */
        /** @brief FIQ 的取值。 */
        enum class FIQ_Values : std::uint32_t {
            NO_FIQ_REQUESTED = 0x0,
            FIQ_REQUESTED = 0x1,
        };
        using FIQ = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, FIQ_Values>; /**< FIQ 请求状态，FIQ_REQUESTED 表示当前存在向 ARM 的 FIQ 请求。 */
        /** @brief REQUESTS_BY_LEVEL 的取值。 */
        enum class REQUESTS_BY_LEVEL_Values : std::uint32_t {
            LEVEL0 = 0x1,
            LEVEL1 = 0x2,
            LEVEL2 = 0x4,
            LEVEL3 = 0x8,
        };
        using REQUESTS_BY_LEVEL = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 4, REQUESTS_BY_LEVEL_Values>; /**< 按优先级分类的原始中断请求位图，每位对应 LEVEL0~LEVEL3 是否有该级请求。 */
        /** @brief LEVEL_REQUESTS 的取值。 */
        enum class LEVEL_REQUESTS_Values : std::uint32_t {
            LEVEL0 = 0x1,
            LEVEL1 = 0x2,
            LEVEL2 = 0x4,
            LEVEL3 = 0x8,
        };
        using LEVEL_REQUESTS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 4, LEVEL_REQUESTS_Values>; /**< 经门控后的每优先级中断请求汇总位图，每位表示对应 LEVEL 是否存在有效待处理请求。 */
        /** @brief INSERVICE 的取值。 */
        enum class INSERVICE_Values : std::uint32_t {
            LEVEL0 = 0x1,
            LEVEL1 = 0x2,
            LEVEL2 = 0x4,
            LEVEL3 = 0x8,
        };
        using INSERVICE = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 4, INSERVICE_Values>; /**< 当前正在服务的中断优先级位图，每位表示对应 LEVEL 是否处于服务中。 */
    } // namespace DEBUG

    /** @brief 调试读镜像寄存器 0，用于调试时读取 ICOLL 内部总线或状态镜像值。 */
    namespace DBGREAD0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80001130, 0x80001134, 0x80001138, 0x8000113C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位调试镜像值，反映内部信号或总线数据的快照。 */
    } // namespace DBGREAD0

    /** @brief 调试读镜像寄存器 1，用于调试时读取 ICOLL 内部另一组总线或状态镜像值。 */
    namespace DBGREAD1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80001140, 0x80001144, 0x80001148, 0x8000114C, LowLevel::Access::ReadWrite>;
        using VALUE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位调试镜像值，反映内部信号或总线数据的快照。 */
    } // namespace DBGREAD1

    /** @brief 调试标志寄存器，提供 16 位调试标志位供内部状态标记或调试使用。 */
    namespace DBGFLAG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80001150, LowLevel::Access::ReadOnly>;
        using FLAG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 16 位调试标志位图，用于标记或读取内部调试状态。 */
    } // namespace DBGFLAG

    /** @brief 调试请求寄存器数组，提供调试用的中断请求位镜像，用于观察或注入调试请求。 */
    namespace DBGREQUEST0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80001160, 0x80001164, 0x80001168, 0x8000116C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位调试请求位图，反映或控制调试模式下的中断请求状态。 */
    } // namespace DBGREQUEST0

    /** @brief 调试请求寄存器数组，提供调试用的中断请求位镜像，用于观察或注入调试请求。 */
    namespace DBGREQUEST1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80001170, 0x80001174, 0x80001178, 0x8000117C, LowLevel::Access::ReadWrite>;
        using BITS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位调试请求位图，反映或控制调试模式下的中断请求状态。 */
    } // namespace DBGREQUEST1

    /** @brief 中断收集器版本寄存器，标识当前 ICOLL 硬件版本的主次及步进号。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800011E0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 步进版本号，标识当前硬件的步进修订。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 次版本号，标识当前硬件的次要版本。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 主版本号，标识当前硬件的主要版本。 */
    } // namespace VERSION

} // namespace Hardware::Registers::ICOLL

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_ICOLL
