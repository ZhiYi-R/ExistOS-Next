#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_DMA_CHANNEL
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_DMA_CHANNEL

/**
 * @file DmaChannel.hpp
 * @brief APBH DMA 单通道门面:复位通道、启动描述符链、轮询完成、确认中断/查错。
 *
 * APBH 的 8 条 DMA 通道在寄存器层是 8 组独立命名空间(CH0_NXTCMDAR / CH0_SEMA …,
 * 每组步距 0x70),命名空间无法被模板整数参数化,故本头用 Detail::ChannelTraits<N>
 * 的显式特化把"通道号 → 该通道的寄存器后端/字段别名"在编译期固定下来;主模板留空,
 * 越界通道号(>7)直接编译失败。
 *
 * 启动流程(对应 i.MX23/STMP3xxx 参考实现):
 *  1. 把描述符链链首的 **物理地址** 写入 CHn_NXTCMDAR(单条 str)。
 *  2. 向 CHn_SEMA 的 INCREMENT_SEMA 写入排队描述符个数,信号量非零即触发 DMA(单条 str)。
 * 完成检测可读 CHn_SEMA 的 PHORE(剩余未完成描述符数,归零即全部完成),或在描述符
 * 置了 IRQONCMPLT 时轮询 CTRL1 的 CHn_CMDCMPLT_IRQ。
 *
 * 本头只负责"踢启动 + 状态轮询",描述符内存布局见 DmaDescriptor.hpp,数据缓冲的 cache
 * 一致性维护见 CacheMaintenance.hpp(目标编译)。所有地址均来自生成头,绝不硬编码。
 */

#include "Registers/APBH.hpp"
#include <cstdint>

namespace Hardware::Drivers::Common {

    namespace Detail {

        /**
         * @brief 通道号 → 该通道寄存器后端/字段别名的映射(主模板未定义)。
         *
         * 仅对 0–7 提供**手写显式特化**(原先由局部宏批量生成,现按"禁止函数式宏"展开为
         * 逐通道特化列表);以非法通道号实例化将因主模板不完整而编译失败。每条特化只是把
         * 该通道命名空间里的 Reg/Field 别名汇总,无任何运行期代价。
         * @tparam Channel DMA 通道号。
         */
        template <std::uint32_t Channel>
        struct ChannelTraits;

        template <>
        struct ChannelTraits<0u> {
            using NextCommandRegister = Registers::APBH::CH0_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH0_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH0_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH0_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH0_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH0_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH0_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH0_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<1u> {
            using NextCommandRegister = Registers::APBH::CH1_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH1_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH1_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH1_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH1_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH1_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH1_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH1_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<2u> {
            using NextCommandRegister = Registers::APBH::CH2_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH2_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH2_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH2_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH2_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH2_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH2_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH2_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<3u> {
            using NextCommandRegister = Registers::APBH::CH3_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH3_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH3_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH3_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH3_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH3_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH3_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH3_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<4u> {
            using NextCommandRegister = Registers::APBH::CH4_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH4_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH4_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH4_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH4_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH4_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH4_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH4_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<5u> {
            using NextCommandRegister = Registers::APBH::CH5_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH5_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH5_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH5_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH5_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH5_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH5_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH5_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<6u> {
            using NextCommandRegister = Registers::APBH::CH6_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH6_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH6_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH6_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH6_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH6_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH6_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH6_AHB_ERROR_IRQ;
        };
        template <>
        struct ChannelTraits<7u> {
            using NextCommandRegister = Registers::APBH::CH7_NXTCMDAR::Reg;
            using NextCommandAddress = Registers::APBH::CH7_NXTCMDAR::CMD_ADDR;
            using SemaphoreRegister = Registers::APBH::CH7_SEMA::Reg;
            using IncrementSemaphore = Registers::APBH::CH7_SEMA::INCREMENT_SEMA;
            using PendingCount = Registers::APBH::CH7_SEMA::PHORE;
            using CurrentCommandRegister = Registers::APBH::CH7_CURCMDAR::Reg;
            using CompletionIrq = Registers::APBH::CTRL1::CH7_CMDCMPLT_IRQ;
            using AhbErrorIrq = Registers::APBH::CTRL1::CH7_AHB_ERROR_IRQ;
        };

    } // namespace Detail

    /**
     * @brief 参数化的 APBH DMA 通道门面(纯静态,通道号编译期固定)。
     *
     * 用法:`using LcdChannel = DmaChannel<0>; LcdChannel::Start(descriptorPhysicalAddress);`
     * 启动前须保证描述符与数据缓冲已做 cache 维护(见 CacheMaintenance.hpp),且传入的是
     * **物理地址**(本平台主存物理=虚拟,无 MMU 重映射时二者一致)。
     *
     * @tparam Channel DMA 通道号(0–7),越界编译期报错。
     */
    template <std::uint32_t Channel>
        requires(Channel <= 7u)
    struct DmaChannel {
        DmaChannel() = delete;
        ~DmaChannel() = delete;
        DmaChannel(const DmaChannel&) = delete;
        DmaChannel& operator=(const DmaChannel&) = delete;

    private:
        using Traits = Detail::ChannelTraits<Channel>; /**< 本通道的寄存器/字段映射。 */
        using Control0 = Registers::APBH::CTRL0::Reg;   /**< APBH 全局 CTRL0(含逐通道复位/门控位)。 */

        /** @brief 本通道在 CTRL0.RESET_CHANNEL 位域中的位掩码。 */
        static constexpr std::uint32_t ResetChannelMask =
            1u << (Registers::APBH::CTRL0::RESET_CHANNEL::BitOffset + Channel);

    public:
        /**
         * @brief 触发本 DMA 通道复位:置 CTRL0.RESET_CHANNEL 对应位(单条原子 str→SET)。
         *
         * RESET_CHANNEL 是 8 位字段(位 n 对应通道 n),CTRL0 带 SET/CLR/TOG 别名,故置位为
         * 单条原子 str。复位会丢弃通道当前描述符与信号量状态。复位脉冲的**自清等待**由
         * `IsResetComplete()` 谓词轮询、节拍编排上移 OS,本层不自旋。
         */
        [[gnu::always_inline]] static void BeginReset() noexcept {
            Control0::Set(ResetChannelMask);
        }

        /**
         * @brief 非阻塞谓词:本通道复位脉冲是否已自清(RESET_CHANNEL 对应位归零)。
         * @return 复位完成返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool IsResetComplete() noexcept {
            return (Control0::Read() & ResetChannelMask) == 0u;
        }

        /**
         * @brief 使能本通道时钟(清 CTRL0 的 CLKGATE_CHANNEL 对应位,单条原子 str)。
         */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Control0::Clear(1u << (Registers::APBH::CTRL0::CLKGATE_CHANNEL::BitOffset + Channel));
        }

        /**
         * @brief 关断本通道时钟(置 CTRL0 的 CLKGATE_CHANNEL 对应位,单条原子 str)。
         */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Control0::Set(1u << (Registers::APBH::CTRL0::CLKGATE_CHANNEL::BitOffset + Channel));
        }

        /**
         * @brief 启动一条(或一串链)描述符:写链首物理地址并踢动信号量。
         * @param descriptorPhysicalAddress 描述符链链首的 32 位物理地址(须 32 字节对齐)。
         * @param descriptorCount 排队的描述符个数(累加到信号量),默认为 1。
         */
        [[gnu::always_inline]] static void Start(std::uint32_t descriptorPhysicalAddress,
                                                 std::uint32_t descriptorCount = 1u) noexcept {
            // 1. 写下一命令描述符地址(整字单条 str)。
            Traits::NextCommandRegister::Write(descriptorPhysicalAddress);
            // 2. 信号量加 descriptorCount,非零即启动 DMA(整字单条 str,PHORE 为只读写入忽略)。
            Traits::SemaphoreRegister::Write(descriptorCount);
        }

        /**
         * @brief 当前尚未完成的描述符个数(读 CHn_SEMA 的 PHORE)。
         * @return 剩余待处理描述符数,0 表示已全部消费。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t PendingDescriptors() noexcept {
            return Traits::SemaphoreRegister::template ReadField<typename Traits::PendingCount>();
        }

        /**
         * @brief 通道是否仍在传输(信号量计数非零)。
         * @return 仍有待处理描述符时返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool IsBusy() noexcept {
            return PendingDescriptors() != 0u;
        }

        /**
         * @brief 命令完成中断标志是否已置(CTRL1 的 CHn_CMDCMPLT_IRQ)。
         * @return 描述符完成(且置了 IRQONCMPLT)时返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool IsCompletionFlagSet() noexcept {
            return Registers::APBH::CTRL1::Reg::template FieldIsSet<typename Traits::CompletionIrq>();
        }

        /**
         * @brief 是否发生 AHB 总线错误(CTRL1 的 CHn_AHB_ERROR_IRQ)。
         * @return 本通道有 AHB 传输错误时返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool HasAhbError() noexcept {
            return Registers::APBH::CTRL1::Reg::template FieldIsSet<typename Traits::AhbErrorIrq>();
        }

        /**
         * @brief 清除本通道的命令完成中断标志(CTRL1 带别名,单条原子 str→CLR)。
         */
        [[gnu::always_inline]] static void AcknowledgeCompletion() noexcept {
            Registers::APBH::CTRL1::Reg::template ClearField<typename Traits::CompletionIrq>();
        }

        /**
         * @brief 清除本通道的 AHB 错误中断标志(CTRL1 带别名,单条原子 str→CLR)。
         */
        [[gnu::always_inline]] static void AcknowledgeAhbError() noexcept {
            Registers::APBH::CTRL1::Reg::template ClearField<typename Traits::AhbErrorIrq>();
        }
    };

} // namespace Hardware::Drivers::Common

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_DMA_CHANNEL
