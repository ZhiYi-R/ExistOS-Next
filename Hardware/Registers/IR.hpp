#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_IR
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_IR

/**
 * @file IR.hpp
 * @brief IR 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 红外接口控制器(IrDA/红外收发)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::IR {

    /** @brief IR Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078000, 0x80078004, 0x80078008, 0x8007800C, LowLevel::Access::ReadWrite>;
        using RXEN = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 红外接收使能，置位时启用红外接收器。 */
        using TXEN = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 红外发送使能，置位时启用红外发送器。 */
        using TCEN = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 红外定时器/计数器使能。 */
        using SIPEN = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< SIP模式使能，置位时启用串行红外协议。 */
        /** @brief SIR_GAP 的取值。 */
        enum class SIR_GAP_Values : std::uint32_t {
            GAP_10K = 0x0,
            GAP_5K = 0x1,
            GAP_1K = 0x2,
            GAP_500 = 0x3,
            GAP_100 = 0x4,
            GAP_50 = 0x5,
            GAP_10 = 0x6,
            GAP_0 = 0x7,
        };
        using SIR_GAP = LowLevel::Field<Reg, 4, 3, SIR_GAP_Values>; /**< SIR帧间间隔控制，配置串行红外帧之间的空闲时间。 */
        using TC_TYPE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 定时器/计数器类型选择。 */
        using TC_TIME_DIV = LowLevel::Field<Reg, 8, 6, std::uint32_t>; /**< 定时器/计数器分频配置。 */
        /** @brief SPEED 的取值。 */
        enum class SPEED_Values : std::uint32_t {
            SPD000 = 0x0,
            SPD001 = 0x1,
            SPD010 = 0x2,
            SPD011 = 0x3,
            SPD100 = 0x4,
            SPD101 = 0x5,
        };
        using SPEED = LowLevel::Field<Reg, 19, 3, SPEED_Values>; /**< 红外通信速率选择（SIR/MIR/FIR）。 */
        /** @brief MODE 的取值。 */
        enum class MODE_Values : std::uint32_t {
            SIR = 0x0,
            MIR = 0x1,
            FIR = 0x2,
            VFIR = 0x3,
        };
        using MODE = LowLevel::Field<Reg, 22, 2, MODE_Values>; /**< 红外工作模式选择。 */
        /** @brief MTA 的取值。 */
        enum class MTA_Values : std::uint32_t {
            MTA_10MS = 0x0,
            MTA_5MS = 0x1,
            MTA_1MS = 0x2,
            MTA_500US = 0x3,
            MTA_100US = 0x4,
            MTA_50US = 0x5,
            MTA_10US = 0x6,
            MTA_0 = 0x7,
        };
        using MTA = LowLevel::Field<Reg, 24, 3, MTA_Values>; /**< 最小时间间隙配置。 */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 时钟门控控制位，写1关闭模块时钟以节省功耗，配置状态保持。写0恢复正常时钟供应。 */
        /** @brief SFTRST 的取值。 */
        enum class SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            RESET = 0x1,
        };
        using SFTRST = LowLevel::Field<Reg, 31, 1, SFTRST_Values>; /**< 软复位控制位，写1复位本模块，写0恢复正常运行。复位后所有寄存器回到默认值。 */
    } // namespace CTRL

    /** @brief IR Transmit DMA Control Register */
    namespace TXDMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078010, 0x80078014, 0x80078018, 0x8007801C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, 0, 12, std::uint32_t>; /**< 数据传送计数字段，指定本次DMA/传输操作的数据量，单位为字（由WORD_LENGTH决定字宽）。 */
        using XBOFS = LowLevel::Field<Reg, 12, 6, std::uint32_t>; /**< 发送DMA缓冲区偏移量。 */
        using BOF_TYPE = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< 帧起始类型选择。 */
        using NEW_SPEED = LowLevel::Field<Reg, 19, 3, std::uint32_t>; /**< 下一帧使用的新速率。 */
        using NEW_MODE = LowLevel::Field<Reg, 22, 2, std::uint32_t>; /**< 下一帧使用的新模式。 */
        using NEW_MTA = LowLevel::Field<Reg, 24, 3, std::uint32_t>; /**< 下一帧使用的新MTA值。 */
        using CHANGE = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< 速率/模式/MTA变更使能。 */
        using INT = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 内部帧传输指示。 */
        using EMPTY = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< DMA缓冲区空标志。 */
        using RUN = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 运行使能位，写1启动模块运行，写0停止。DMA操作时硬件自动置位。 */
    } // namespace TXDMA

    /** @brief IR Receive DMA Register */
    namespace RXDMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078020, 0x80078024, 0x80078028, 0x8007802C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 数据传送计数字段，指定本次DMA/传输操作的数据量，单位为字（由WORD_LENGTH决定字宽）。 */
        using RUN = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 运行使能位，写1启动模块运行，写0停止。DMA操作时硬件自动置位。 */
    } // namespace RXDMA

    /** @brief IR Debug Control Register */
    namespace DBGCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078030, 0x80078034, 0x80078038, 0x8007803C, LowLevel::Access::ReadWrite>;
        using MIO_EN = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 多功能I/O使能。 */
        using MIO_SCLK = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< MIO串行时钟选择。 */
        using MIO_TX = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< MIO发送数据观察。 */
        using MIO_RX = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< MIO接收数据观察。 */
        using DUPLEX = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 全双工模式使能。 */
        using INTLOOPBACK = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 内部环回使能，用于自测。 */
        using TXINVERT = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 发送数据极性反转。 */
        using TXCRCOFF = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 发送CRC关闭。 */
        using TXFRMOFF = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 发送帧封装关闭。 */
        using RXINVERT = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 接收数据极性反转。 */
        using RXCRCOFF = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 接收CRC关闭。 */
        using RXFRMOFF = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< 接收帧封装关闭。 */
        /** @brief VFIRSWZ 的取值。 */
        enum class VFIRSWZ_Values : std::uint32_t {
            NORMAL = 0x0,
            SWAP = 0x1,
        };
        using VFIRSWZ = LowLevel::Field<Reg, 12, 1, VFIRSWZ_Values>; /**< VFIR软件交换控制。 */
    } // namespace DBGCTRL

    /** @brief IR Interrupt Register */
    namespace INTR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078040, 0x80078044, 0x80078048, 0x8007804C, LowLevel::Access::ReadWrite>;
        /** @brief TX_IRQ 的取值。 */
        enum class TX_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using TX_IRQ = LowLevel::Field<Reg, 0, 1, TX_IRQ_Values>; /**< 发送中断状态，写1清零。 */
        /** @brief RX_IRQ 的取值。 */
        enum class RX_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using RX_IRQ = LowLevel::Field<Reg, 1, 1, RX_IRQ_Values>; /**< 接收中断状态，写1清零。 */
        /** @brief TC_IRQ 的取值。 */
        enum class TC_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using TC_IRQ = LowLevel::Field<Reg, 2, 1, TC_IRQ_Values>; /**< 定时器/计数器中断状态，写1清零。 */
        /** @brief TXUF_IRQ 的取值。 */
        enum class TXUF_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using TXUF_IRQ = LowLevel::Field<Reg, 3, 1, TXUF_IRQ_Values>; /**< 发送下溢中断状态，写1清零。 */
        /** @brief RXOF_IRQ 的取值。 */
        enum class RXOF_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using RXOF_IRQ = LowLevel::Field<Reg, 4, 1, RXOF_IRQ_Values>; /**< 接收上溢中断状态，写1清零。 */
        /** @brief SPEED_IRQ 的取值。 */
        enum class SPEED_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using SPEED_IRQ = LowLevel::Field<Reg, 5, 1, SPEED_IRQ_Values>; /**< 速率变更中断状态，写1清零。 */
        /** @brief RXABORT_IRQ 的取值。 */
        enum class RXABORT_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using RXABORT_IRQ = LowLevel::Field<Reg, 6, 1, RXABORT_IRQ_Values>; /**< 接收中止中断状态，写1清零。 */
        /** @brief TX_IRQ_EN 的取值。 */
        enum class TX_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using TX_IRQ_EN = LowLevel::Field<Reg, 16, 1, TX_IRQ_EN_Values>; /**< 发送中断使能。 */
        /** @brief RX_IRQ_EN 的取值。 */
        enum class RX_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using RX_IRQ_EN = LowLevel::Field<Reg, 17, 1, RX_IRQ_EN_Values>; /**< 接收中断使能。 */
        /** @brief TC_IRQ_EN 的取值。 */
        enum class TC_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using TC_IRQ_EN = LowLevel::Field<Reg, 18, 1, TC_IRQ_EN_Values>; /**< 定时器/计数器中断使能。 */
        /** @brief TXUF_IRQ_EN 的取值。 */
        enum class TXUF_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using TXUF_IRQ_EN = LowLevel::Field<Reg, 19, 1, TXUF_IRQ_EN_Values>; /**< 发送下溢中断使能。 */
        /** @brief RXOF_IRQ_EN 的取值。 */
        enum class RXOF_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using RXOF_IRQ_EN = LowLevel::Field<Reg, 20, 1, RXOF_IRQ_EN_Values>; /**< 接收上溢中断使能。 */
        /** @brief SPEED_IRQ_EN 的取值。 */
        enum class SPEED_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using SPEED_IRQ_EN = LowLevel::Field<Reg, 21, 1, SPEED_IRQ_EN_Values>; /**< 速率变更中断使能。 */
        /** @brief RXABORT_IRQ_EN 的取值。 */
        enum class RXABORT_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using RXABORT_IRQ_EN = LowLevel::Field<Reg, 22, 1, RXABORT_IRQ_EN_Values>; /**< 接收中止中断使能。 */
    } // namespace INTR

    /** @brief IR RX Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078050, 0x80078054, 0x80078058, 0x8007805C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< 数据寄存器，写操作将数据写入发送FIFO，读操作从接收FIFO取出数据。 */
    } // namespace DATA

    /** @brief IR Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078060, 0x80078064, 0x80078068, 0x8007806C, LowLevel::Access::ReadWrite>;
        using TX_ACTIVE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 发送器激活状态。 */
        using RX_ACTIVE = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 接收器激活状态。 */
        using MEDIA_BUSY = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 介质忙状态。 */
        /** @brief TX_SUMMARY 的取值。 */
        enum class TX_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using TX_SUMMARY = LowLevel::Field<Reg, 16, 1, TX_SUMMARY_Values>; /**< 发送中断汇总。 */
        /** @brief RX_SUMMARY 的取值。 */
        enum class RX_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using RX_SUMMARY = LowLevel::Field<Reg, 17, 1, RX_SUMMARY_Values>; /**< 接收中断汇总。 */
        /** @brief TC_SUMMARY 的取值。 */
        enum class TC_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using TC_SUMMARY = LowLevel::Field<Reg, 18, 1, TC_SUMMARY_Values>; /**< 定时器/计数器中断汇总。 */
        /** @brief TXUF_SUMMARY 的取值。 */
        enum class TXUF_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using TXUF_SUMMARY = LowLevel::Field<Reg, 19, 1, TXUF_SUMMARY_Values>; /**< 发送下溢中断汇总。 */
        /** @brief RXOF_SUMMARY 的取值。 */
        enum class RXOF_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using RXOF_SUMMARY = LowLevel::Field<Reg, 20, 1, RXOF_SUMMARY_Values>; /**< 接收上溢中断汇总。 */
        /** @brief SPEED_SUMMARY 的取值。 */
        enum class SPEED_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using SPEED_SUMMARY = LowLevel::Field<Reg, 21, 1, SPEED_SUMMARY_Values>; /**< 速率变更中断汇总。 */
        /** @brief RXABORT_SUMMARY 的取值。 */
        enum class RXABORT_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using RXABORT_SUMMARY = LowLevel::Field<Reg, 22, 1, RXABORT_SUMMARY_Values>; /**< 接收中止中断汇总。 */
        /** @brief ANY_IRQ 的取值。 */
        enum class ANY_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using ANY_IRQ = LowLevel::Field<Reg, 28, 1, ANY_IRQ_Values>; /**< 任意中断汇总标志。 */
        /** @brief MODE_ALLOWED 的取值。 */
        enum class MODE_ALLOWED_Values : std::uint32_t {
            VFIR = 0x0,
            FIR = 0x1,
            MIR = 0x2,
            SIR = 0x3,
        };
        using MODE_ALLOWED = LowLevel::Field<Reg, 29, 2, MODE_ALLOWED_Values>; /**< 当前允许的模式指示。 */
        /** @brief PRESENT 的取值。 */
        enum class PRESENT_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using PRESENT = LowLevel::Field<Reg, 31, 1, PRESENT_Values>; /**< IR模块存在标志，只读。1=存在。 */
    } // namespace STAT

    /** @brief IR Transceiver Control Register */
    namespace TCCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078070, 0x80078074, 0x80078078, 0x8007807C, LowLevel::Access::ReadWrite>;
        using C = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 定时器/计数器计数值。 */
        using INDX = LowLevel::Field<Reg, 1, 4, std::uint32_t>; /**< 定时器/计数器索引。 */
        using ADDR = LowLevel::Field<Reg, 5, 3, std::uint32_t>; /**< 定时器/计数器地址。 */
        using DATA = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< 数据寄存器，写操作将数据写入发送FIFO，读操作从接收FIFO取出数据。 */
        using EXT_DATA = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 外部数据。 */
        /** @brief TEMIC 的取值。 */
        enum class TEMIC_Values : std::uint32_t {
            LOW = 0x0,
            HIGH = 0x1,
        };
        using TEMIC = LowLevel::Field<Reg, 24, 1, TEMIC_Values>; /**< TEMIC协议控制。 */
        using BUSY = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 定时器忙标志。 */
        using GO = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 启动控制。 */
        using INIT = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 初始化控制。 */
    } // namespace TCCTRL

    /** @brief IR Serial Interface Read Data Register */
    namespace SI_READ {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80078080, 0x80078084, 0x80078088, 0x8007808C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< 数据寄存器，写操作将数据写入发送FIFO，读操作从接收FIFO取出数据。 */
        using ABORT = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< SI读中止。 */
    } // namespace SI_READ

    /** @brief IR Debug Register */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80078090, LowLevel::Access::ReadOnly>;
        using RXDMAREQ = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 接收DMA请求状态。 */
        using TXDMAREQ = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 发送DMA请求状态。 */
        using RXDMAEND = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 接收DMA结束。 */
        using TXDMAEND = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 发送DMA结束。 */
        using RXDMAKICK = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 接收DMA触发。 */
        using TXDMAKICK = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 发送DMA触发。 */
    } // namespace DEBUG

    /** @brief IR Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800780A0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< IR模块修订步进号，只读。 */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< IR模块次版本号，只读。 */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< IR模块主版本号，只读。 */
    } // namespace VERSION

} // namespace Hardware::Registers::IR

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_IR
