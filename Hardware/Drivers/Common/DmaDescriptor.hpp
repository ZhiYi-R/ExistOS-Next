#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_DMA_DESCRIPTOR
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_DMA_DESCRIPTOR

/**
 * @file DmaDescriptor.hpp
 * @brief APBH DMA 描述符的内存布局与命令字(CMD word)位打包。
 *
 * APBH DMA 引擎在内存中沿"描述符链"工作,每个描述符是一段硬件约定布局的连续字:
 *   +0x00 NEXT          —— 下一描述符物理地址(链尾置 0)
 *   +0x04 CMD           —— 命令字(传输方向、链接、中断、PIO 字数、字节数等,见 BuildCommand)
 *   +0x08 BUFFER(BAR)  —— 负载缓冲物理地址
 *   +0x0C PIO words[]   —— 随后紧跟若干 PIO 字,数量 = CMD.CMDWORDS,内容写入目标外设的 PIO 寄存器
 *
 * 本头只描述"内存里的描述符"与命令字打包(纯数据 / 纯函数,可主机单元测试),不涉及任何
 * MMIO 寄存器访问;启动通道、cache 维护分别在 DmaChannel.hpp / CacheMaintenance.hpp。
 *
 * @note 命令字位域取自 i.MX23/STMP3xxx 参考手册 HW_APBH_CHn_CMD。
 */

#include <cstdint>

namespace Hardware::Drivers::Common {

    /**
     * @brief DMA 传输方向(命令字 COMMAND 位[1:0])。
     *
     * @warning 厂商命名以"DMA 引擎视角"定义,易混淆:DMA_WRITE 指外设→内存(引擎向内存写),
     *          DMA_READ 指内存→外设。此处枚举名采用语义化命名,括号内为厂商原始名/原始值。
     */
    enum class DmaTransferType : std::uint32_t {
        NoTransfer = 0x0,     /**< 不传输数据,仅执行 PIO/控制(NO_DMA_XFER)。 */
        DeviceToMemory = 0x1, /**< 外设 → 内存(厂商 DMA_WRITE)。 */
        MemoryToDevice = 0x2, /**< 内存 → 外设(厂商 DMA_READ)。 */
        Sense = 0x3,          /**< 条件分支/探测(DMA_SENSE)。 */
    };

    /** @brief 命令字各控制位的位偏移与宽度(对应 HW_APBH_CHn_CMD)。 */
    namespace DmaCommandBits {
        inline constexpr std::uint32_t CommandOffset = 0u;          /**< COMMAND 位[1:0]:传输方向。 */
        inline constexpr std::uint32_t CommandWidth = 2u;
        inline constexpr std::uint32_t Chain = 1u << 2;             /**< CHAIN:完成后继续取 NEXT 指向的描述符。 */
        inline constexpr std::uint32_t InterruptOnCompletion = 1u << 3; /**< IRQONCMPLT:完成后产生通道中断。 */
        inline constexpr std::uint32_t NandLock = 1u << 4;          /**< NANDLOCK:锁定 GPMI 给本通道。 */
        inline constexpr std::uint32_t NandWaitForReady = 1u << 5;  /**< NANDWAIT4READY:等待 NAND R/B 就绪。 */
        inline constexpr std::uint32_t Semaphore = 1u << 6;         /**< SEMAPHORE:递减通道信号量。 */
        inline constexpr std::uint32_t WaitForEndCommand = 1u << 7; /**< WAIT4ENDCMD:等待外设结束命令握手。 */
        inline constexpr std::uint32_t HaltOnTerminate = 1u << 8;   /**< HALTONTERMINATE:终止时停在本描述符。 */
        inline constexpr std::uint32_t CommandWordsOffset = 12u;    /**< CMDWORDS 位[15:12]:PIO 字数。 */
        inline constexpr std::uint32_t CommandWordsWidth = 4u;
        inline constexpr std::uint32_t TransferCountOffset = 16u;   /**< XFER_COUNT 位[31:16]:传输字节数。 */
        inline constexpr std::uint32_t TransferCountWidth = 16u;
    } // namespace DmaCommandBits

    /** @brief 组装命令字的可选标志集合(便于具名传参,避免裸位或)。 */
    struct DmaCommandOptions {
        DmaTransferType transferType = DmaTransferType::NoTransfer; /**< 传输方向。 */
        std::uint16_t transferCount = 0;        /**< 传输字节数(写入 XFER_COUNT)。 */
        std::uint8_t pioWordCount = 0;          /**< 随描述符的 PIO 字数(写入 CMDWORDS)。 */
        bool chain = false;                     /**< 置 CHAIN。 */
        bool interruptOnCompletion = false;     /**< 置 IRQONCMPLT。 */
        bool semaphore = false;                 /**< 置 SEMAPHORE。 */
        bool waitForEndCommand = false;         /**< 置 WAIT4ENDCMD。 */
        bool nandLock = false;                  /**< 置 NANDLOCK。 */
        bool nandWaitForReady = false;          /**< 置 NANDWAIT4READY。 */
        bool haltOnTerminate = false;           /**< 置 HALTONTERMINATE。 */
    };

    /**
     * @brief 按选项打包 APBH DMA 命令字(纯函数,可主机测试)。
     * @param options 命令字选项。
     * @return 打包好的 32 位命令字。
     */
    [[nodiscard]] constexpr std::uint32_t BuildCommand(const DmaCommandOptions& options) noexcept {
        std::uint32_t command = 0u;
        command |= static_cast<std::uint32_t>(options.transferType) << DmaCommandBits::CommandOffset;
        command |= static_cast<std::uint32_t>(options.pioWordCount & 0xFu) << DmaCommandBits::CommandWordsOffset;
        command |= static_cast<std::uint32_t>(options.transferCount) << DmaCommandBits::TransferCountOffset;
        if (options.chain) { command |= DmaCommandBits::Chain; }
        if (options.interruptOnCompletion) { command |= DmaCommandBits::InterruptOnCompletion; }
        if (options.semaphore) { command |= DmaCommandBits::Semaphore; }
        if (options.waitForEndCommand) { command |= DmaCommandBits::WaitForEndCommand; }
        if (options.nandLock) { command |= DmaCommandBits::NandLock; }
        if (options.nandWaitForReady) { command |= DmaCommandBits::NandWaitForReady; }
        if (options.haltOnTerminate) { command |= DmaCommandBits::HaltOnTerminate; }
        return command;
    }

    /**
     * @brief 内存中的 APBH DMA 描述符(带 PioWordCount 个 PIO 字)。
     *
     * 以 32 字节对齐:ARM926 的 D-cache 行为 32 字节,独占对齐可保证对描述符做 cache
     * clean/invalidate 时不会牵连相邻数据。字段标 volatile,防止编译器缓存 DMA 引擎会读改的值。
     *
     * @tparam PioWordCount 随描述符的 PIO 字数(LCDIF 通常 1,GPMI 通常 1~3)。
     */
    template <std::uint32_t PioWordCount>
    struct alignas(32) DmaDescriptor {
        volatile std::uint32_t next;          /**< 下一描述符物理地址(链尾置 0)。 */
        volatile std::uint32_t command;       /**< 命令字(见 BuildCommand)。 */
        volatile std::uint32_t bufferAddress; /**< 负载缓冲物理地址(BAR)。 */
        volatile std::uint32_t pio[PioWordCount]; /**< PIO 字数组,写入目标外设 PIO 寄存器。 */
    };

    /** @brief 无 PIO 字的描述符特化(纯内存搬运)。 */
    template <>
    struct alignas(32) DmaDescriptor<0> {
        volatile std::uint32_t next;          /**< 下一描述符物理地址(链尾置 0)。 */
        volatile std::uint32_t command;       /**< 命令字(见 BuildCommand)。 */
        volatile std::uint32_t bufferAddress; /**< 负载缓冲物理地址(BAR)。 */
    };

} // namespace Hardware::Drivers::Common

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_DMA_DESCRIPTOR
