#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_ICOLL
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_ICOLL

/**
 * @file ICOLL.hpp
 * @brief 中断收集器(ICOLL)驱动:模块复位/门控、IRQ 总使能、向量读取与优先级确认,
 *        以及编译期参数化的逐中断源门面 InterruptSource<Number>。
 *
 * STMP3770/i.MX23 的 ICOLL 仲裁 64 路中断源(RAW0/RAW1 各 32 位),逐源的优先级/使能/
 * 软触发集中在 16 个 PRIORITY 寄存器里,每个寄存器管 4 路:源 4*r+s 的字段落在
 * PRIORITY{r} 的位 s*8 处 —— PRIORITY[s*8,2]、ENABLE[s*8+2]、SOFTIRQ[s*8+3]。
 * 命名空间无法被模板整数参数化,故用 consteval 选择函数 SelectPriorityRegister<r> 把
 * "寄存器序号 → PRIORITY{r} 后端"在编译期固定,再按 slot 合成该源的三个字段。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * 典型用法:
 *  - bring-up:`ICOLL::DeassertSoftReset(); ICOLL::SetVectorTableBase(addr); ICOLL::EnableIrqDelivery();`
 *  - 配某源:`using TimerIrq = ICOLL::InterruptSource<48>; TimerIrq::SetPriority(3); TimerIrq::Enable();`
 *  - ISR 内:读 `ICOLL::ReadVector()` 取处理函数地址,服务完 `ICOLL::AcknowledgeLevel(level)`。
 *
 * @note 寄存器/字段取自生成头 Registers/ICOLL.hpp,复位原语复用 Common::{AssertSoftReset,…};
 *       复位序列节拍(清SR→等→清CG→置SR→清SR→等)的编排上移 OS,本层只给触发 + 谓词。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/ICOLL.hpp"
#include "Field.hpp"
#include <cstdint>
#include <type_traits>

namespace Hardware::Drivers {

    /** @brief 中断收集器(ICOLL)驱动:纯静态门面,无实例。 */
    struct ICOLL {
        ICOLL() = delete;
        ~ICOLL() = delete;
        ICOLL(const ICOLL&) = delete;
        ICOLL& operator=(const ICOLL&) = delete;

    private:
        using ControlRegister = Registers::ICOLL::CTRL::Reg;              /**< 主控制寄存器(复位/门控/总使能)。 */
        using VectorBaseRegister = Registers::ICOLL::VBASE::Reg;          /**< 向量表基地址寄存器。 */
        using VectorRegister = Registers::ICOLL::VECTOR::Reg;             /**< 当前最高优先级向量字寄存器。 */
        using StatusRegister = Registers::ICOLL::STAT::Reg;               /**< 仲裁状态寄存器(当前服务向量号)。 */
        using LevelAcknowledgeRegister = Registers::ICOLL::LEVELACK::Reg; /**< 优先级确认寄存器。 */

        using SoftReset = Registers::ICOLL::CTRL::SFTRST;  /**< CTRL.SFTRST 字段后端。 */
        using ClockGate = Registers::ICOLL::CTRL::CLKGATE; /**< CTRL.CLKGATE 字段后端。 */

        /**
         * @brief PRIORITY 寄存器序号 → 生成头 PRIORITY{Index} 后端的编译期映射。
         * @tparam Index PRIORITY 寄存器序号(0–15)。
         * @return std::type_identity 包裹对应 PRIORITY{Index}::Reg 后端类型。
         */
        template <std::uint32_t Index>
        [[nodiscard]] static consteval auto SelectPriorityRegister() noexcept {
            if constexpr (Index == 0u) return std::type_identity<Registers::ICOLL::PRIORITY0::Reg>{};
            else if constexpr (Index == 1u) return std::type_identity<Registers::ICOLL::PRIORITY1::Reg>{};
            else if constexpr (Index == 2u) return std::type_identity<Registers::ICOLL::PRIORITY2::Reg>{};
            else if constexpr (Index == 3u) return std::type_identity<Registers::ICOLL::PRIORITY3::Reg>{};
            else if constexpr (Index == 4u) return std::type_identity<Registers::ICOLL::PRIORITY4::Reg>{};
            else if constexpr (Index == 5u) return std::type_identity<Registers::ICOLL::PRIORITY5::Reg>{};
            else if constexpr (Index == 6u) return std::type_identity<Registers::ICOLL::PRIORITY6::Reg>{};
            else if constexpr (Index == 7u) return std::type_identity<Registers::ICOLL::PRIORITY7::Reg>{};
            else if constexpr (Index == 8u) return std::type_identity<Registers::ICOLL::PRIORITY8::Reg>{};
            else if constexpr (Index == 9u) return std::type_identity<Registers::ICOLL::PRIORITY9::Reg>{};
            else if constexpr (Index == 10u) return std::type_identity<Registers::ICOLL::PRIORITY10::Reg>{};
            else if constexpr (Index == 11u) return std::type_identity<Registers::ICOLL::PRIORITY11::Reg>{};
            else if constexpr (Index == 12u) return std::type_identity<Registers::ICOLL::PRIORITY12::Reg>{};
            else if constexpr (Index == 13u) return std::type_identity<Registers::ICOLL::PRIORITY13::Reg>{};
            else if constexpr (Index == 14u) return std::type_identity<Registers::ICOLL::PRIORITY14::Reg>{};
            else return std::type_identity<Registers::ICOLL::PRIORITY15::Reg>{};
        }

        /** @brief 序号 → PRIORITY{Index} 后端类型(consteval 链产物)。 */
        template <std::uint32_t Index>
        using PriorityRegister = typename decltype(SelectPriorityRegister<Index>())::type;

    public:
        /** @brief ICOLL 支持的中断源总数(0–63)。 */
        static constexpr std::uint32_t InterruptSourceCount = 64u;

        // ====================== 模块级:复位 / 门控 ======================

        /** @brief 触发软复位:置 CTRL.SFTRST(单条原子 str→SET)。 */
        [[gnu::always_inline]] static void AssertSoftReset() noexcept {
            Common::AssertSoftReset<SoftReset>();
        }

        /** @brief 退出软复位:清 CTRL.SFTRST(单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DeassertSoftReset() noexcept {
            Common::DeassertSoftReset<SoftReset>();
        }

        /** @brief 非阻塞谓词:软复位是否仍被置位(CTRL.SFTRST==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSoftResetAsserted() noexcept {
            return Common::IsSoftResetAsserted<SoftReset>();
        }

        /** @brief 使能 ICOLL 模块时钟(清 CTRL.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 ICOLL 模块时钟(置 CTRL.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        /** @brief 打开 IRQ 总送达开关(置 CTRL.IRQ_FINAL_ENABLE,单条原子 str→SET)。 */
        [[gnu::always_inline]] static void EnableIrqDelivery() noexcept {
            ControlRegister::template SetField<Registers::ICOLL::CTRL::IRQ_FINAL_ENABLE>();
        }

        /** @brief 关闭 IRQ 总送达开关(清 CTRL.IRQ_FINAL_ENABLE,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DisableIrqDelivery() noexcept {
            ControlRegister::template ClearField<Registers::ICOLL::CTRL::IRQ_FINAL_ENABLE>();
        }

        /** @brief 打开 FIQ 总送达开关(置 CTRL.FIQ_FINAL_ENABLE)。 */
        [[gnu::always_inline]] static void EnableFiqDelivery() noexcept {
            ControlRegister::template SetField<Registers::ICOLL::CTRL::FIQ_FINAL_ENABLE>();
        }

        /** @brief 关闭 FIQ 总送达开关(清 CTRL.FIQ_FINAL_ENABLE)。 */
        [[gnu::always_inline]] static void DisableFiqDelivery() noexcept {
            ControlRegister::template ClearField<Registers::ICOLL::CTRL::FIQ_FINAL_ENABLE>();
        }

        // ====================== 向量表 / 仲裁状态 / 优先级确认 ======================

        /**
         * @brief 设置中断向量表基地址(写 VBASE.TABLE_ADDRESS,占 bit[31:2],须 4 字节对齐)。
         * @param tableBaseAddress 向量表基地址(低 2 位被硬件忽略)。
         */
        [[gnu::always_inline]] static void SetVectorTableBase(std::uint32_t tableBaseAddress) noexcept {
            VectorBaseRegister::Write(tableBaseAddress);
        }

        /**
         * @brief 读取当前最高优先级中断的向量字(ISR 入口处读取,可据此跳转)。
         * @return VECTOR 寄存器整字(bit[31:2] 为向量地址)。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadVector() noexcept {
            return VectorRegister::Read();
        }

        /**
         * @brief 当前正在服务的中断向量号(读 STAT.VECTOR_NUMBER)。
         * @return 中断源编号(0–63)。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t CurrentServingVector() noexcept {
            return StatusRegister::template ReadField<Registers::ICOLL::STAT::VECTOR_NUMBER>();
        }

        /**
         * @brief 确认(结束服务)指定优先级的中断:向 LEVELACK 写 one-hot 的 1<<level。
         *
         * ISR 末尾调用以清除该优先级的服务态,使 ICOLL 可继续仲裁后续中断。
         * @param level 优先级 0–3。
         */
        [[gnu::always_inline]] static void AcknowledgeLevel(std::uint32_t level) noexcept {
            LevelAcknowledgeRegister::Write(1u << level);
        }

        /**
         * @brief 编译期固定中断源号的逐源门面(纯静态):优先级/使能/软触发。
         *
         * 源 Number 落在 PRIORITY{Number/4} 的第 (Number%4) 个 slot:每 slot 占 8 位,
         * PRIORITY 在 slot*8、ENABLE 在 slot*8+2、SOFTIRQ 在 slot*8+3。字段地址来自生成头,
         * slot 步距 8 位为架构保证。
         *
         * @tparam Number 中断源号(0–63),越界编译期报错。
         */
        template <std::uint32_t Number>
            requires(Number < InterruptSourceCount)
        struct InterruptSource {
            InterruptSource() = delete;
            ~InterruptSource() = delete;
            InterruptSource(const InterruptSource&) = delete;
            InterruptSource& operator=(const InterruptSource&) = delete;

        private:
            /** @brief 本源所属 PRIORITY 寄存器序号:每寄存器管 4 路。 */
            static constexpr std::uint32_t RegisterIndex = Number / 4u;
            /** @brief 本源在寄存器内的 slot(0–3),slot 步距 8 位。 */
            static constexpr std::uint32_t SlotBitBase = (Number % 4u) * 8u;

            /** @brief 本源所属 PRIORITY 寄存器后端(经 consteval 链选出)。 */
            using Backend = PriorityRegister<RegisterIndex>;
            /** @brief 本源 2 位优先级字段(LEVEL0 最低、LEVEL3 最高)。 */
            using PriorityField =
                LowLevel::Field<Backend, static_cast<LowLevel::Bit>(SlotBitBase), 2u>;
            /** @brief 本源使能字段(1 位)。 */
            using EnableField =
                LowLevel::Field<Backend, static_cast<LowLevel::Bit>(SlotBitBase + 2u), 1u>;
            /** @brief 本源软件触发字段(1 位)。 */
            using SoftIrqField =
                LowLevel::Field<Backend, static_cast<LowLevel::Bit>(SlotBitBase + 3u), 1u>;

        public:
            /**
             * @brief 设置本源优先级(配置期一次 RMW 写 2 位 PRIORITY 字段)。
             * @param priorityLevel 0–3,数值越大优先级越高。
             */
            [[gnu::always_inline]] static void SetPriority(std::uint32_t priorityLevel) noexcept {
                Backend::template WriteField<PriorityField>(priorityLevel);
            }

            /** @brief 使能本中断源参与仲裁(置 ENABLE,单条原子 str→SET)。 */
            [[gnu::always_inline]] static void Enable() noexcept {
                Backend::template SetField<EnableField>();
            }

            /** @brief 禁用本中断源(清 ENABLE,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void Disable() noexcept {
                Backend::template ClearField<EnableField>();
            }

            /** @brief 软件强制触发本中断(置 SOFTIRQ,单条原子 str→SET)。 */
            [[gnu::always_inline]] static void ForceSoftwareInterrupt() noexcept {
                Backend::template SetField<SoftIrqField>();
            }

            /** @brief 撤销软件触发(清 SOFTIRQ,单条原子 str→CLR)。 */
            [[gnu::always_inline]] static void ClearSoftwareInterrupt() noexcept {
                Backend::template ClearField<SoftIrqField>();
            }
        };
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_ICOLL
