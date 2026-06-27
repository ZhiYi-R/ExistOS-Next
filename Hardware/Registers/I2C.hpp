#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_I2C
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_I2C

/**
 * @file I2C.hpp
 * @brief I2C 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * I2C 总线控制器，支持主从模式、PIO/DMA 数据传输、可编程时序与多主机仲裁。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::I2C {

    /** @brief I2C 控制寄存器 0，配置传输方向、主从模式、字节数、START/STOP 条件、PIO 模式、时钟门控与软复位等核心参数。 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058000, 0x80058004, 0x80058008, 0x8005800C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 本次传输的字节数（16 位）。 */
        /** @brief DIRECTION 的取值。 */
        enum class DIRECTION_Values : std::uint32_t {
            RECEIVE = 0x0,
            TRANSMIT = 0x1,
        };
        using DIRECTION = LowLevel::Field<Reg, 16, 1, DIRECTION_Values>; /**< 传输方向：0=接收，1=发送。 */
        /** @brief MASTER_MODE 的取值。 */
        enum class MASTER_MODE_Values : std::uint32_t {
            SLAVE = 0x0,
            MASTER = 0x1,
        };
        using MASTER_MODE = LowLevel::Field<Reg, 17, 1, MASTER_MODE_Values>; /**< 主从模式选择：0=从机，1=主机。 */
        /** @brief SLAVE_ADDRESS_ENABLE 的取值。 */
        enum class SLAVE_ADDRESS_ENABLE_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using SLAVE_ADDRESS_ENABLE = LowLevel::Field<Reg, 18, 1, SLAVE_ADDRESS_ENABLE_Values>; /**< 从机地址匹配使能：0=禁用，1=使能。 */
        /** @brief PRE_SEND_START 的取值。 */
        enum class PRE_SEND_START_Values : std::uint32_t {
            NO_START = 0x0,
            SEND_START = 0x1,
        };
        using PRE_SEND_START = LowLevel::Field<Reg, 19, 1, PRE_SEND_START_Values>; /**< 传输前是否发送 START 条件：0=不发，1=发送 START。 */
        /** @brief POST_SEND_STOP 的取值。 */
        enum class POST_SEND_STOP_Values : std::uint32_t {
            NO_STOP = 0x0,
            SEND_STOP = 0x1,
        };
        using POST_SEND_STOP = LowLevel::Field<Reg, 20, 1, POST_SEND_STOP_Values>; /**< 传输后是否发送 STOP 条件：0=不发，1=发送 STOP。 */
        /** @brief RETAIN_CLOCK 的取值。 */
        enum class RETAIN_CLOCK_Values : std::uint32_t {
            RELEASE = 0x0,
            HOLD_LOW = 0x1,
        };
        using RETAIN_CLOCK = LowLevel::Field<Reg, 21, 1, RETAIN_CLOCK_Values>; /**< 保持 SCL 低电平：0=释放，1=保持低电平。 */
        /** @brief CLOCK_HELD 的取值。 */
        enum class CLOCK_HELD_Values : std::uint32_t {
            RELEASE = 0x0,
            HELD_LOW = 0x1,
        };
        using CLOCK_HELD = LowLevel::Field<Reg, 22, 1, CLOCK_HELD_Values>; /**< 时钟保持状态：0=释放，1=保持低电平。 */
        /** @brief MULTI_MASTER 的取值。 */
        enum class MULTI_MASTER_Values : std::uint32_t {
            SINGLE = 0x0,
            MULTIPLE = 0x1,
        };
        using MULTI_MASTER = LowLevel::Field<Reg, 23, 1, MULTI_MASTER_Values>; /**< 多主机模式：0=单主机，1=多主机。 */
        using PIO_MODE = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< PIO 模式使能，用于软件直接控制数据读写。 */
        /** @brief SEND_NAK_ON_LAST 的取值。 */
        enum class SEND_NAK_ON_LAST_Values : std::uint32_t {
            ACK_IT = 0x0,
            NAK_IT = 0x1,
        };
        using SEND_NAK_ON_LAST = LowLevel::Field<Reg, 25, 1, SEND_NAK_ON_LAST_Values>; /**< 最后一字节是否发送 NAK：0=ACK，1=NAK。 */
        /** @brief ACKNOWLEDGE 的取值。 */
        enum class ACKNOWLEDGE_Values : std::uint32_t {
            SNAK = 0x0,
            ACK = 0x1,
        };
        using ACKNOWLEDGE = LowLevel::Field<Reg, 26, 1, ACKNOWLEDGE_Values>; /**< 应答控制：0=发送 NAK，1=发送 ACK。 */
        using PRE_ACK = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< 预应答控制，用于在时钟保持前提前产生 ACK。 */
        /** @brief RUN 的取值。 */
        enum class RUN_Values : std::uint32_t {
            HALT = 0x0,
            RUN = 0x1,
        };
        using RUN = LowLevel::Field<Reg, 29, 1, RUN_Values>; /**< 控制器运行控制：0=停止，1=运行。 */
        /** @brief CLKGATE 的取值。 */
        enum class CLKGATE_Values : std::uint32_t {
            RUN = 0x0,
            NO_CLKS = 0x1,
        };
        using CLKGATE = LowLevel::Field<Reg, 30, 1, CLKGATE_Values>; /**< 时钟门控：0=正常时钟，1=关闭时钟以节能。 */
        /** @brief SFTRST 的取值。 */
        enum class SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            RESET = 0x1,
        };
        using SFTRST = LowLevel::Field<Reg, 31, 1, SFTRST_Values>; /**< 软复位：0=正常运行，1=复位整个 I2C 模块。 */
    } // namespace CTRL0

    /** @brief I2C 时序寄存器 0，配置 SCL 高电平周期与接收采样计数。 */
    namespace TIMING0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058010, 0x80058014, 0x80058018, 0x8005801C, LowLevel::Access::ReadWrite>;
        using RCV_COUNT = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 接收采样计数，用于控制接收数据位的采样时序。 */
        using HIGH_COUNT = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< SCL 高电平周期计数，决定 SCL 保持高电平的时钟周期数。 */
    } // namespace TIMING0

    /** @brief I2C 时序寄存器 1，配置 SCL 低电平周期与发送采样计数。 */
    namespace TIMING1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058020, 0x80058024, 0x80058028, 0x8005802C, LowLevel::Access::ReadWrite>;
        using XMIT_COUNT = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 发送采样计数，用于控制发送数据位的时序。 */
        using LOW_COUNT = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< SCL 低电平周期计数，决定 SCL 保持低电平的时钟周期数。 */
    } // namespace TIMING1

    /** @brief I2C 时序寄存器 2，配置引导计数与总线空闲时间。 */
    namespace TIMING2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058030, 0x80058034, 0x80058038, 0x8005803C, LowLevel::Access::ReadWrite>;
        using LEADIN_COUNT = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 引导计数，用于 START 条件前的引导时序。 */
        using BUS_FREE = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< 总线空闲时间计数，定义两次传输之间总线必须保持空闲的最小时钟周期数。 */
    } // namespace TIMING2

    /** @brief I2C 控制寄存器 1，配置各类中断状态/使能、从机地址、广播监听、ACK 模式及清除 NAK 标志。 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058040, 0x80058044, 0x80058048, 0x8005804C, LowLevel::Access::ReadWrite>;
        /** @brief SLAVE_IRQ 的取值。 */
        enum class SLAVE_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using SLAVE_IRQ = LowLevel::Field<Reg, 0, 1, SLAVE_IRQ_Values>; /**< 从机访问中断状态：0=无请求，1=有请求。 */
        /** @brief SLAVE_STOP_IRQ 的取值。 */
        enum class SLAVE_STOP_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using SLAVE_STOP_IRQ = LowLevel::Field<Reg, 1, 1, SLAVE_STOP_IRQ_Values>; /**< 从机 STOP 中断状态：0=无请求，1=有请求。 */
        /** @brief MASTER_LOSS_IRQ 的取值。 */
        enum class MASTER_LOSS_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using MASTER_LOSS_IRQ = LowLevel::Field<Reg, 2, 1, MASTER_LOSS_IRQ_Values>; /**< 主机仲裁丢失中断状态：0=无请求，1=有请求。 */
        /** @brief EARLY_TERM_IRQ 的取值。 */
        enum class EARLY_TERM_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using EARLY_TERM_IRQ = LowLevel::Field<Reg, 3, 1, EARLY_TERM_IRQ_Values>; /**< 提前终止中断状态：0=无请求，1=有请求。 */
        /** @brief OVERSIZE_XFER_TERM_IRQ 的取值。 */
        enum class OVERSIZE_XFER_TERM_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using OVERSIZE_XFER_TERM_IRQ = LowLevel::Field<Reg, 4, 1, OVERSIZE_XFER_TERM_IRQ_Values>; /**< 超长传输终止中断状态：0=无请求，1=有请求。 */
        /** @brief NO_SLAVE_ACK_IRQ 的取值。 */
        enum class NO_SLAVE_ACK_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using NO_SLAVE_ACK_IRQ = LowLevel::Field<Reg, 5, 1, NO_SLAVE_ACK_IRQ_Values>; /**< 无从机应答中断状态：0=无请求，1=有请求。 */
        /** @brief DATA_ENGINE_CMPLT_IRQ 的取值。 */
        enum class DATA_ENGINE_CMPLT_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using DATA_ENGINE_CMPLT_IRQ = LowLevel::Field<Reg, 6, 1, DATA_ENGINE_CMPLT_IRQ_Values>; /**< 数据引擎完成中断状态：0=无请求，1=有请求。 */
        /** @brief BUS_FREE_IRQ 的取值。 */
        enum class BUS_FREE_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using BUS_FREE_IRQ = LowLevel::Field<Reg, 7, 1, BUS_FREE_IRQ_Values>; /**< 总线空闲中断状态：0=无请求，1=有请求。 */
        /** @brief SLAVE_IRQ_EN 的取值。 */
        enum class SLAVE_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using SLAVE_IRQ_EN = LowLevel::Field<Reg, 8, 1, SLAVE_IRQ_EN_Values>; /**< 从机访问中断使能：0=禁用，1=使能。 */
        /** @brief SLAVE_STOP_IRQ_EN 的取值。 */
        enum class SLAVE_STOP_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using SLAVE_STOP_IRQ_EN = LowLevel::Field<Reg, 9, 1, SLAVE_STOP_IRQ_EN_Values>; /**< 从机 STOP 中断使能：0=禁用，1=使能。 */
        /** @brief MASTER_LOSS_IRQ_EN 的取值。 */
        enum class MASTER_LOSS_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using MASTER_LOSS_IRQ_EN = LowLevel::Field<Reg, 10, 1, MASTER_LOSS_IRQ_EN_Values>; /**< 主机仲裁丢失中断使能：0=禁用，1=使能。 */
        /** @brief EARLY_TERM_IRQ_EN 的取值。 */
        enum class EARLY_TERM_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using EARLY_TERM_IRQ_EN = LowLevel::Field<Reg, 11, 1, EARLY_TERM_IRQ_EN_Values>; /**< 提前终止中断使能：0=禁用，1=使能。 */
        /** @brief OVERSIZE_XFER_TERM_IRQ_EN 的取值。 */
        enum class OVERSIZE_XFER_TERM_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using OVERSIZE_XFER_TERM_IRQ_EN = LowLevel::Field<Reg, 12, 1, OVERSIZE_XFER_TERM_IRQ_EN_Values>; /**< 超长传输终止中断使能：0=禁用，1=使能。 */
        /** @brief NO_SLAVE_ACK_IRQ_EN 的取值。 */
        enum class NO_SLAVE_ACK_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using NO_SLAVE_ACK_IRQ_EN = LowLevel::Field<Reg, 13, 1, NO_SLAVE_ACK_IRQ_EN_Values>; /**< 无从机应答中断使能：0=禁用，1=使能。 */
        /** @brief DATA_ENGINE_CMPLT_IRQ_EN 的取值。 */
        enum class DATA_ENGINE_CMPLT_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using DATA_ENGINE_CMPLT_IRQ_EN = LowLevel::Field<Reg, 14, 1, DATA_ENGINE_CMPLT_IRQ_EN_Values>; /**< 数据引擎完成中断使能：0=禁用，1=使能。 */
        /** @brief BUS_FREE_IRQ_EN 的取值。 */
        enum class BUS_FREE_IRQ_EN_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using BUS_FREE_IRQ_EN = LowLevel::Field<Reg, 15, 1, BUS_FREE_IRQ_EN_Values>; /**< 总线空闲中断使能：0=禁用，1=使能。 */
        using SLAVE_ADDRESS_BYTE = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 从机地址字节（8 位），用于配置本机从机地址。 */
        /** @brief BCAST_SLAVE_EN 的取值。 */
        enum class BCAST_SLAVE_EN_Values : std::uint32_t {
            NO_BCAST = 0x0,
            WATCH_BCAST = 0x1,
        };
        using BCAST_SLAVE_EN = LowLevel::Field<Reg, 24, 1, BCAST_SLAVE_EN_Values>; /**< 广播地址监听：0=忽略广播，1=监听广播地址。 */
        using FORCE_CLK_IDLE = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 强制 SCL 空闲，用于调试时强制时钟线进入空闲状态。 */
        using FORCE_DATA_IDLE = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< 强制 SDA 空闲，用于调试时强制数据线进入空闲状态。 */
        /** @brief ACK_MODE 的取值。 */
        enum class ACK_MODE_Values : std::uint32_t {
            ACK_AFTER_HOLD_LOW = 0x0,
            ACK_BEFORE_HOLD_LOW = 0x1,
        };
        using ACK_MODE = LowLevel::Field<Reg, 27, 1, ACK_MODE_Values>; /**< ACK 模式：0=在时钟保持低后应答，1=在时钟保持低前应答。 */
        /** @brief CLR_GOT_A_NAK 的取值。 */
        enum class CLR_GOT_A_NAK_Values : std::uint32_t {
            DO_NOTHING = 0x0,
            CLEAR = 0x1,
        };
        using CLR_GOT_A_NAK = LowLevel::Field<Reg, 28, 1, CLR_GOT_A_NAK_Values>; /**< 清除 GOT_A_NAK 标志：0=无操作，1=清除标志。 */
    } // namespace CTRL1

    /** @brief I2C 状态寄存器，反映各类中断汇总、总线/引擎/时钟忙状态、从机搜索状态及接收到的从机地址等信息。 */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058050, 0x80058054, 0x80058058, 0x8005805C, LowLevel::Access::ReadWrite>;
        /** @brief SLAVE_IRQ_SUMMARY 的取值。 */
        enum class SLAVE_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using SLAVE_IRQ_SUMMARY = LowLevel::Field<Reg, 0, 1, SLAVE_IRQ_SUMMARY_Values>; /**< 从机访问中断汇总：0=无请求，1=有请求。 */
        /** @brief SLAVE_STOP_IRQ_SUMMARY 的取值。 */
        enum class SLAVE_STOP_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using SLAVE_STOP_IRQ_SUMMARY = LowLevel::Field<Reg, 1, 1, SLAVE_STOP_IRQ_SUMMARY_Values>; /**< 从机 STOP 中断汇总：0=无请求，1=有请求。 */
        /** @brief MASTER_LOSS_IRQ_SUMMARY 的取值。 */
        enum class MASTER_LOSS_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using MASTER_LOSS_IRQ_SUMMARY = LowLevel::Field<Reg, 2, 1, MASTER_LOSS_IRQ_SUMMARY_Values>; /**< 主机仲裁丢失中断汇总：0=无请求，1=有请求。 */
        /** @brief EARLY_TERM_IRQ_SUMMARY 的取值。 */
        enum class EARLY_TERM_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using EARLY_TERM_IRQ_SUMMARY = LowLevel::Field<Reg, 3, 1, EARLY_TERM_IRQ_SUMMARY_Values>; /**< 提前终止中断汇总：0=无请求，1=有请求。 */
        /** @brief OVERSIZE_XFER_TERM_IRQ_SUMMARY 的取值。 */
        enum class OVERSIZE_XFER_TERM_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using OVERSIZE_XFER_TERM_IRQ_SUMMARY = LowLevel::Field<Reg, 4, 1, OVERSIZE_XFER_TERM_IRQ_SUMMARY_Values>; /**< 超长传输终止中断汇总：0=无请求，1=有请求。 */
        /** @brief NO_SLAVE_ACK_IRQ_SUMMARY 的取值。 */
        enum class NO_SLAVE_ACK_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using NO_SLAVE_ACK_IRQ_SUMMARY = LowLevel::Field<Reg, 5, 1, NO_SLAVE_ACK_IRQ_SUMMARY_Values>; /**< 无从机应答中断汇总：0=无请求，1=有请求。 */
        /** @brief DATA_ENGINE_CMPLT_IRQ_SUMMARY 的取值。 */
        enum class DATA_ENGINE_CMPLT_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using DATA_ENGINE_CMPLT_IRQ_SUMMARY = LowLevel::Field<Reg, 6, 1, DATA_ENGINE_CMPLT_IRQ_SUMMARY_Values>; /**< 数据引擎完成中断汇总：0=无请求，1=有请求。 */
        /** @brief BUS_FREE_IRQ_SUMMARY 的取值。 */
        enum class BUS_FREE_IRQ_SUMMARY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using BUS_FREE_IRQ_SUMMARY = LowLevel::Field<Reg, 7, 1, BUS_FREE_IRQ_SUMMARY_Values>; /**< 总线空闲中断汇总：0=无请求，1=有请求。 */
        /** @brief SLAVE_BUSY 的取值。 */
        enum class SLAVE_BUSY_Values : std::uint32_t {
            IDLE = 0x0,
            BUSY = 0x1,
        };
        using SLAVE_BUSY = LowLevel::Field<Reg, 8, 1, SLAVE_BUSY_Values>; /**< 从机引擎忙状态：0=空闲，1=忙。 */
        /** @brief DATA_ENGINE_BUSY 的取值。 */
        enum class DATA_ENGINE_BUSY_Values : std::uint32_t {
            IDLE = 0x0,
            BUSY = 0x1,
        };
        using DATA_ENGINE_BUSY = LowLevel::Field<Reg, 9, 1, DATA_ENGINE_BUSY_Values>; /**< 数据引擎忙状态：0=空闲，1=忙。 */
        /** @brief CLK_GEN_BUSY 的取值。 */
        enum class CLK_GEN_BUSY_Values : std::uint32_t {
            IDLE = 0x0,
            BUSY = 0x1,
        };
        using CLK_GEN_BUSY = LowLevel::Field<Reg, 10, 1, CLK_GEN_BUSY_Values>; /**< 时钟生成器忙状态：0=空闲，1=忙。 */
        /** @brief BUS_BUSY 的取值。 */
        enum class BUS_BUSY_Values : std::uint32_t {
            IDLE = 0x0,
            BUSY = 0x1,
        };
        using BUS_BUSY = LowLevel::Field<Reg, 11, 1, BUS_BUSY_Values>; /**< 总线忙状态：0=空闲，1=忙。 */
        /** @brief DATA_ENGINE_DMA_WAIT 的取值。 */
        enum class DATA_ENGINE_DMA_WAIT_Values : std::uint32_t {
            CONTINUE = 0x0,
            WAITING = 0x1,
        };
        using DATA_ENGINE_DMA_WAIT = LowLevel::Field<Reg, 12, 1, DATA_ENGINE_DMA_WAIT_Values>; /**< 数据引擎 DMA 等待状态：0=继续，1=等待 DMA。 */
        /** @brief SLAVE_SEARCHING 的取值。 */
        enum class SLAVE_SEARCHING_Values : std::uint32_t {
            IDLE = 0x0,
            ACTIVE = 0x1,
        };
        using SLAVE_SEARCHING = LowLevel::Field<Reg, 13, 1, SLAVE_SEARCHING_Values>; /**< 从机地址搜索状态：0=空闲，1=正在搜索。 */
        /** @brief SLAVE_FOUND 的取值。 */
        enum class SLAVE_FOUND_Values : std::uint32_t {
            IDLE = 0x0,
            WAITING = 0x1,
        };
        using SLAVE_FOUND = LowLevel::Field<Reg, 14, 1, SLAVE_FOUND_Values>; /**< 从机地址匹配结果：0=空闲，1=已匹配并等待。 */
        /** @brief SLAVE_ADDR_EQ_ZERO 的取值。 */
        enum class SLAVE_ADDR_EQ_ZERO_Values : std::uint32_t {
            ZERO_NOT_MATCHED = 0x0,
            WAS_ZERO = 0x1,
        };
        using SLAVE_ADDR_EQ_ZERO = LowLevel::Field<Reg, 15, 1, SLAVE_ADDR_EQ_ZERO_Values>; /**< 接收到的从机地址是否为 0：0=未匹配到 0，1=地址为 0。 */
        using RCVD_SLAVE_ADDR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 接收到的从机地址字节（8 位）。 */
        /** @brief GOT_A_NAK 的取值。 */
        enum class GOT_A_NAK_Values : std::uint32_t {
            NO_NAK = 0x0,
            DETECTED_NAK = 0x1,
        };
        using GOT_A_NAK = LowLevel::Field<Reg, 28, 1, GOT_A_NAK_Values>; /**< 检测到 NAK 标志：0=未检测到，1=检测到 NAK。 */
        /** @brief ANY_ENABLED_IRQ 的取值。 */
        enum class ANY_ENABLED_IRQ_Values : std::uint32_t {
            NO_REQUESTS = 0x0,
            AT_LEAST_ONE_REQUEST = 0x1,
        };
        using ANY_ENABLED_IRQ = LowLevel::Field<Reg, 29, 1, ANY_ENABLED_IRQ_Values>; /**< 任意已使能中断请求：0=无请求，1=至少有一个中断请求。 */
        /** @brief SLAVE_PRESENT 的取值。 */
        enum class SLAVE_PRESENT_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using SLAVE_PRESENT = LowLevel::Field<Reg, 30, 1, SLAVE_PRESENT_Values>; /**< 从机功能存在标志：0=不可用，1=可用。 */
        /** @brief MASTER_PRESENT 的取值。 */
        enum class MASTER_PRESENT_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using MASTER_PRESENT = LowLevel::Field<Reg, 31, 1, MASTER_PRESENT_Values>; /**< 主机功能存在标志：0=不可用，1=可用。 */
    } // namespace STAT

    /** @brief I2C 数据寄存器，用于 PIO 模式下读写传输数据，或作为 DMA 数据接口。 */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80058060, 0x80058064, 0x80058068, 0x8005806C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< PIO/DMA 数据读写端口（32 位），写操作发送数据，读操作接收数据。 */
    } // namespace DATA

    /** @brief I2C 调试寄存器 0，提供从机状态机、DMA 状态机、各类事件翻转位及 DMA 控制信号的调试可见性。 */
    namespace DEBUG0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80058070, LowLevel::Access::ReadOnly>;
        using SLAVE_STATE = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 从机状态机当前状态（10 位）。 */
        using SLAVE_HOLD_CLK = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 从机时钟保持状态：0=未保持，1=正在保持 SCL 低电平。 */
        using TESTMODE = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< 测试模式使能，用于芯片测试时的特殊模式。 */
        using CHANGE_TOGGLE = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< CHANGE 事件翻转位，用于调试时观察状态变化事件。 */
        using GRAB_TOGGLE = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< GRAB 事件翻转位，用于调试时观察总线占用事件。 */
        using STOP_TOGGLE = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< STOP 事件翻转位，用于调试时观察 STOP 条件事件。 */
        using START_TOGGLE = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< START 事件翻转位，用于调试时观察 START 条件事件。 */
        using DMA_STATE = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< DMA 状态机当前状态（10 位）。 */
        using TBD = LowLevel::Field<Reg, 26, 2, std::uint32_t>; /**< 保留位（2 位），供未来扩展或内部测试使用。 */
        using DMATERMINATE = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< DMA 终止信号，用于调试时观察 DMA 传输终止状态。 */
        using DMAKICK = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< DMA 启动信号，用于调试时观察 DMA 传输启动状态。 */
        using DMAENDCMD = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< DMA 结束命令信号，用于调试时观察 DMA 命令结束状态。 */
        using DMAREQ = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< DMA 请求信号，用于调试时观察 DMA 请求状态。 */
    } // namespace DEBUG0

    /** @brief I2C 调试寄存器 1，提供强制信号注入、从机测试模式、时钟生成器状态、DMA 字节使能及 I2C 引脚输入状态的调试可见性。 */
    namespace DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80058080, LowLevel::Access::ReadOnly>;
        using FORCE_I2C_CLK_OE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 强制 I2C 时钟输出使能，用于调试时手动控制 SCL 输出。 */
        using FORCE_I2C_DATA_OE = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 强制 I2C 数据输出使能，用于调试时手动控制 SDA 输出。 */
        using FORCE_RCV_ACK = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 强制接收 ACK，用于调试时手动注入 ACK 信号。 */
        using FORCE_ARB_LOSS = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 强制仲裁丢失，用于调试时模拟仲裁丢失场景。 */
        using FORCE_CLK_ON = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 强制时钟开启，用于调试时强制使能时钟生成器。 */
        using LOCAL_SLAVE_TEST = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 本地从机测试模式使能，用于芯片测试时启用内部从机测试逻辑。 */
        /** @brief LST_MODE 的取值。 */
        enum class LST_MODE_Values : std::uint32_t {
            BCAST = 0x0,
            MY_WRITE = 0x1,
            MY_READ = 0x2,
            NOT_ME = 0x3,
        };
        using LST_MODE = LowLevel::Field<Reg, 9, 2, LST_MODE_Values>; /**< 从机监听传输模式：0=广播，1=本机写，2=本机读，3=非本机。 */
        using CLK_GEN_STATE = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 时钟生成器状态机当前状态（8 位）。 */
        using DMA_BYTE_ENABLES = LowLevel::Field<Reg, 24, 4, std::uint32_t>; /**< DMA 字节使能掩码（4 位），指示当前 DMA 传输中哪些字节有效。 */
        using I2C_DATA_IN = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< I2C 数据输入引脚（SDA）的当前电平状态。 */
        using I2C_CLK_IN = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< I2C 时钟输入引脚（SCL）的当前电平状态。 */
    } // namespace DEBUG1

    /** @brief I2C 版本寄存器，记录 IP 核的主版本、次版本和步进版本号。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80058090, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 步进版本号（16 位），标识当前 IP 的修订步进。 */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 次版本号（8 位）。 */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< 主版本号（8 位）。 */
    } // namespace VERSION

} // namespace Hardware::Registers::I2C

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_I2C
