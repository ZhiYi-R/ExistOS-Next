#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_SAIF1
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_SAIF1

/**
 * @file SAIF1.hpp
 * @brief SAIF1 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 串行音频接口 1(SAIF,I2S 风格音频数据收发)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::SAIF1 {

    /** @brief SAIF Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80042000, 0x80042004, 0x80042008, 0x8004200C, LowLevel::Access::ReadWrite>;
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 运行使能位，写1启动模块运行，写0停止。DMA操作时硬件自动置位。 */
        using READ_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< I2S 读模式选择，置位时 SAIF 从外部读取数据（接收模式），清零时发送数据（发送模式）。 */
        using SLAVE_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 主从模式选择，0=主机模式（SAIF 产生位时钟和帧时钟），1=从机模式（外部提供时钟）。 */
        using BITCLK_48XFS_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 位时钟 48x 帧同步使能，置位时位时钟频率为帧同步的 48 倍。 */
        using WORD_LENGTH = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, std::uint32_t>; /**< 数据字长选择，0=16位，1=20位，2=24位，3=32位。 */
        using BITCLK_EDGE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 位时钟边沿选择，决定数据在哪个时钟边沿驱动和采样。 */
        using LRCLK_POLARITY = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< 左右声道时钟极性控制，定义帧同步信号的极性。 */
        using JUSTIFY = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< 数据对齐方式选择，控制数据在帧内的对齐位置（左对齐/右对齐/I2S）。 */
        using DELAY = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< 数据延迟控制，配置数据相对于帧同步信号的延迟周期数。 */
        using BIT_ORDER = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< 位顺序控制，0=MSB 先发送，1=LSB 先发送。 */
        using CHANNEL_NUM_SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< 声道数选择，配置 I2S 接口的音频声道数量。 */
        using DMAWAIT_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, std::uint32_t>; /**< DMA 等待计数值，DMA 请求的等待周期数。 */
        using FIFO_SERVICE_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< FIFO 服务中断使能，置位时允许 FIFO 触发服务请求中断。 */
        using FIFO_ERROR_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< FIFO 错误中断使能，置位时允许 FIFO 上溢/下溢触发中断。 */
        using BITCLK_BASE_RATE = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< 位时钟基准速率选择，配置 SAIF 位时钟的基准分频值。 */
        using BITCLK_MULT_RATE = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 3, std::uint32_t>; /**< 位时钟倍频速率选择，在基准速率上配置倍频系数。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 时钟门控控制位，写1关闭模块时钟以节省功耗，配置状态保持。写0恢复正常时钟供应。 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 软复位控制位，写1复位本模块，写0恢复正常运行。复位后所有寄存器回到默认值。 */
    } // namespace CTRL

    /** @brief SAIF Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80042010, 0x80042014, 0x80042018, 0x8004201C, LowLevel::Access::ReadWrite>;
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< SAIF 忙状态指示，置位表示 SAIF 正在数据发送或接收中。 */
        using FIFO_SERVICE_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< FIFO 服务中断状态，置位表示 FIFO 需要服务（可从 DATA 读写数据）。写 1 清零。 */
        using FIFO_OVERFLOW_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< FIFO 上溢中断状态，置位表示接收 FIFO 发生上溢。写 1 清零。 */
        using FIFO_UNDERFLOW_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< FIFO 下溢中断状态，置位表示发送 FIFO 发生下溢。写 1 清零。 */
        using DMA_PREQ = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< DMA 请求状态，反映当前 DMA 请求线的状态。只读。 */
        using PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< SAIF 模块存在标志，只读。1=SAIF 模块在本芯片中存在。 */
    } // namespace STAT

    /** @brief SAIF Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80042020, 0x80042024, 0x80042028, 0x8004202C, LowLevel::Access::ReadWrite>;
        using PCM_LEFT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 左声道 PCM 数据，存放 I2S 左声道音频采样数据（高 16 位）。 */
        using PCM_RIGHT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 右声道 PCM 数据，存放 I2S 右声道音频采样数据（低 16 位）。 */
    } // namespace DATA

    /** @brief SAIF Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80042030, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< SAIF 模块修订步进号，只读。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< SAIF 模块次版本号，只读。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< SAIF 模块主版本号，只读。 */
    } // namespace VERSION

} // namespace Hardware::Registers::SAIF1

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_SAIF1
