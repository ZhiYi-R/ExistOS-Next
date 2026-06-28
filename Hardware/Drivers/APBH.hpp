#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_APBH
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_APBH

/**
 * @file APBH.hpp
 * @brief APBH DMA 引擎模块级门面:整模块软复位/门控、全局中断聚合,并把逐通道 DMA
 *        设施(描述符布局、命令字打包、通道操作、cache 维护)聚合再导出。
 *
 * STMP3770/i.MX23 的 APBH-DMA 是服务于 LCDIF/GPMI(NAND)等高带宽外设的描述符式 DMA。
 * 其寄存器分两层:
 *  - **模块级**:CTRL0(整模块 SFTRST/CLKGATE,以及 8 通道各自的 RESET/CLKGATE/FREEZE 位)、
 *    CTRL1(8 通道的命令完成/AHB 错误中断标志与使能)。
 *  - **通道级**:CH{n}_NXTCMDAR/SEMA/… 共 8 组,由 Common::DmaChannel<n> 封装。
 *
 * 本头负责"整模块"的复位与门控;单通道的启动/等待/确认在 Common::DmaChannel,描述符内存
 * 布局与命令字打包在 Common::DmaDescriptor。为方便上层(LCDIF/GPMI 驱动)只
 * `#include "Drivers/APBH.hpp"` 即可拿到这两套设施,这里在类内用别名/透传把它们再导出到
 * Hardware::Drivers::APBH 门面。
 *
 * 数据缓冲的 cache 一致性维护在 Common::CacheMaintenance,它依赖 CP15 内联汇编、仅可目标编译,
 * 故**不**在此聚合;需要时由上层驱动在目标侧自行 `#include "Drivers/Common/CacheMaintenance.hpp"`。
 *
 * 典型 bring-up(复位脉冲节拍由 OS 编排,本层只给触发 + 谓词):
 *   `APBH::DeassertSoftReset(); … APBH::EnableClock();`  // 整模块退出复位 + 开时钟
 *   `using LcdDma = APBH::Channel<0>;`                   // 取 0 号通道门面
 *   `LcdDma::BeginReset();  LcdDma::Start(descPhys);`    // 触发该通道复位并启动描述符链
 *
 * @note 寄存器/字段取自生成头 Registers/APBH.hpp,绝不硬编码地址。
 */

#include "Drivers/Common/DmaChannel.hpp"
#include "Drivers/Common/DmaDescriptor.hpp"
#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/APBH.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    /** @brief APBH DMA 引擎模块级门面:纯静态单例,无实例。 */
    struct APBH {
        APBH() = delete;
        ~APBH() = delete;
        APBH(const APBH&) = delete;
        APBH& operator=(const APBH&) = delete;

    private:
        using SoftReset = Registers::APBH::CTRL0::SFTRST;  /**< CTRL0.SFTRST 字段后端。 */
        using ClockGate = Registers::APBH::CTRL0::CLKGATE; /**< CTRL0.CLKGATE 字段后端。 */

    public:
        /** @brief APBH DMA 通道个数(0–7)。 */
        static constexpr std::uint32_t ChannelCount = 8u;

        // ====================== 聚合再导出 Common DMA 设施 ======================

        /**
         * @brief 逐通道 DMA 门面(= Common::DmaChannel<Channel>)。
         *
         * 用 `APBH::Channel<N>` 即可拿到该通道的 BeginReset/Start/IsBusy 等;
         * 通道号越界(>7)在 Common::DmaChannel 处编译期报错。
         * @tparam ChannelIndex DMA 通道号(0–7)。
         */
        template <std::uint32_t ChannelIndex>
        using Channel = Common::DmaChannel<ChannelIndex>;

        /**
         * @brief DMA 描述符(= Common::DmaDescriptor<PioWordCount>)。
         * @tparam PioWordCount 随描述符的 PIO 字数。
         */
        template <std::uint32_t PioWordCount>
        using Descriptor = Common::DmaDescriptor<PioWordCount>;

        using DmaCommandOptions = Common::DmaCommandOptions; /**< 命令字选项(= Common::DmaCommandOptions)。 */
        using DmaTransferType = Common::DmaTransferType;     /**< 传输方向枚举(= Common::DmaTransferType)。 */

        /**
         * @brief 按选项打包 APBH DMA 命令字(透传 Common::BuildCommand,纯函数)。
         * @param options 命令字选项。
         * @return 打包好的 32 位命令字。
         */
        [[nodiscard]] static constexpr std::uint32_t BuildCommand(const DmaCommandOptions& options) noexcept {
            return Common::BuildCommand(options);
        }

        // ====================== 模块级:复位 / 门控 ======================

        /** @brief 触发整模块软复位:置 CTRL0.SFTRST(单条原子 str→SET)。 */
        [[gnu::always_inline]] static void AssertSoftReset() noexcept {
            Common::AssertSoftReset<SoftReset>();
        }

        /** @brief 退出整模块软复位:清 CTRL0.SFTRST(单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DeassertSoftReset() noexcept {
            Common::DeassertSoftReset<SoftReset>();
        }

        /** @brief 非阻塞谓词:整模块软复位是否仍被置位(CTRL0.SFTRST==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSoftResetAsserted() noexcept {
            return Common::IsSoftResetAsserted<SoftReset>();
        }

        /** @brief 使能 APBH 模块时钟(清 CTRL0.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 APBH 模块时钟(置 CTRL0.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL0.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_APBH
