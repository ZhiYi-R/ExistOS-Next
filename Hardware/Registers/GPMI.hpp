#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_GPMI
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_GPMI

/**
 * @file GPMI.hpp
 * @brief GPMI 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * NAND Flash 通用接口控制器，支持 NAND/ATA 模式，集成 ECC(BCH/ECC8) 纠错引擎，提供 DMA 数据传输、时序配置与命令执行功能。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::GPMI {

    /** @brief GPMI 控制寄存器 0，配置单次命令传输的核心参数并启动执行。 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C000, 0x8000C004, 0x8000C008, 0x8000C00C, LowLevel::Access::ReadWrite>;
        using XFER_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 本次命令传输的字节数，0 表示 65536 字节。 */
        /** @brief ADDRESS_INCREMENT 的取值。 */
        enum class ADDRESS_INCREMENT_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using ADDRESS_INCREMENT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, ADDRESS_INCREMENT_Values>; /**< 地址自增使能：DISABLED=禁止自增；ENABLED=每传输一个字后地址自动递增。 */
        /** @brief ADDRESS 的取值。 */
        enum class ADDRESS_Values : std::uint32_t {
            NAND_DATA = 0x0,
            NAND_CLE = 0x1,
            NAND_ALE = 0x2,
        };
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 3, ADDRESS_Values>; /**< NAND 地址类型：NAND_DATA=数据寄存器；NAND_CLE=命令锁存使能；NAND_ALE=地址锁存使能。 */
        using CS = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< 片选信号编号，选择当前操作的 NAND 设备(0~3)。 */
        /** @brief LOCK_CS 的取值。 */
        enum class LOCK_CS_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using LOCK_CS = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, LOCK_CS_Values>; /**< 片选锁定使能：DISABLED=传输结束后自动释放 CS；ENABLED=锁定 CS 直到显式释放。 */
        /** @brief WORD_LENGTH 的取值。 */
        enum class WORD_LENGTH_Values : std::uint32_t {
            _16_BIT = 0x0,
            _8_BIT = 0x1,
        };
        using WORD_LENGTH = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, WORD_LENGTH_Values>; /**< 数据位宽：_16_BIT=16 位；_8_BIT=8 位。 */
        /** @brief COMMAND_MODE 的取值。 */
        enum class COMMAND_MODE_Values : std::uint32_t {
            WRITE = 0x0,
            READ = 0x1,
            READ_AND_COMPARE = 0x2,
            WAIT_FOR_READY = 0x3,
        };
        using COMMAND_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, COMMAND_MODE_Values>; /**< 命令模式：WRITE=写数据；READ=读数据；READ_AND_COMPARE=读并比较；WAIT_FOR_READY=等待设备就绪。 */
        /** @brief UDMA 的取值。 */
        enum class UDMA_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using UDMA = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, UDMA_Values>; /**< UDMA 模式使能：DISABLED=禁用；ENABLED=启用 Ultra DMA 传输。 */
        using TIMEOUT_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< 设备忙等待超时中断使能，置 1 允许超时中断上报。 */
        using DEV_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< 设备就绪中断使能，置 1 允许设备就绪中断上报。 */
        /** @brief RUN 的取值。 */
        enum class RUN_Values : std::uint32_t {
            IDLE = 0x0,
            BUSY = 0x1,
        };
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, RUN_Values>; /**< 命令执行状态：IDLE=空闲；BUSY=命令正在执行，写 1 启动命令。 */
        /** @brief CLKGATE 的取值。 */
        enum class CLKGATE_Values : std::uint32_t {
            RUN = 0x0,
            NO_CLKS = 0x1,
        };
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, CLKGATE_Values>; /**< 时钟门控：RUN=正常运行；NO_CLKS=关闭 GPMI 时钟以节能。 */
        /** @brief SFTRST 的取值。 */
        enum class SFTRST_Values : std::uint32_t {
            RUN = 0x0,
            RESET = 0x1,
        };
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, SFTRST_Values>; /**< 软复位：RUN=正常工作；RESET=复位整个 GPMI 模块。 */
    } // namespace CTRL0

    /** @brief 读数据比较寄存器，用于 READ_AND_COMPARE 模式下的数据校验。 */
    namespace COMPARE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C010, 0x8000C014, 0x8000C018, 0x8000C01C, LowLevel::Access::ReadWrite>;
        using REFERENCE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 读数据比较的参考值。 */
        using MASK = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 比较掩码，仅掩码为 1 的位参与比较。 */
    } // namespace COMPARE

    /** @brief 集成 ECC 控制寄存器，配置 ECC 引擎的操作模式与数据缓冲。 */
    namespace ECCCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C020, 0x8000C024, 0x8000C028, 0x8000C02C, LowLevel::Access::ReadWrite>;
        /** @brief BUFFER_MASK 的取值。 */
        enum class BUFFER_MASK_Values : std::uint32_t {
            BCH_AUXONLY = 0x100,
            BCH_PAGE = 0x1FF,
            BUFFER7 = 0x80,
            BUFFER6 = 0x40,
            BUFFER5 = 0x20,
            BUFFER4 = 0x10,
            BUFFER3 = 0x8,
            BUFFER2 = 0x4,
            BUFFER1 = 0x2,
            BUFFER0 = 0x1,
        };
        using BUFFER_MASK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 9, BUFFER_MASK_Values>; /**< ECC 数据缓冲掩码，选择参与 ECC 编解码的缓冲单元(BUFFER0~7、BCH_PAGE、BCH_AUXONLY)。 */
        /** @brief ENABLE_ECC 的取值。 */
        enum class ENABLE_ECC_Values : std::uint32_t {
            ENABLE = 0x1,
            DISABLE = 0x0,
        };
        using ENABLE_ECC = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, ENABLE_ECC_Values>; /**< ECC 使能：ENABLE=启用 ECC 编解码(写 1)；DISABLE=关闭 ECC(写 0)。 */
        /** @brief ECC_CMD 的取值。 */
        enum class ECC_CMD_Values : std::uint32_t {
            DECODE_4_BIT = 0x0,
            ENCODE_4_BIT = 0x1,
            DECODE_8_BIT = 0x2,
            ENCODE_8_BIT = 0x3,
        };
        using ECC_CMD = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 2, ECC_CMD_Values>; /**< ECC 命令：DECODE_4_BIT=4 位解码；ENCODE_4_BIT=4 位编码；DECODE_8_BIT=8 位解码；ENCODE_8_BIT=8 位编码。 */
        using HANDLE = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< ECC 操作句柄标识，用于关联本次 ECC 传输的上下文。 */
    } // namespace ECCCTRL

    /** @brief 集成 ECC 传输计数寄存器，指定 ECC 编解码的数据量。 */
    namespace ECCCOUNT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C030, 0x8000C034, 0x8000C038, 0x8000C03C, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< ECC 编解码的字节数，0 表示 65536 字节。 */
    } // namespace ECCCOUNT

    /** @brief DMA 主数据(Payload)缓冲地址寄存器，存放 NAND 页数据(数据区)的物理地址。 */
    namespace PAYLOAD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C040, 0x8000C044, 0x8000C048, 0x8000C04C, LowLevel::Access::ReadWrite>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 30, std::uint32_t>; /**< Payload 数据缓冲的物理地址高 30 位(bit 31:2)，低 2 位固定为 0。 */
    } // namespace PAYLOAD

    /** @brief DMA 辅助数据(Auxiliary)缓冲地址寄存器，存放 NAND 备用区(如 OOB/元数据)的物理地址。 */
    namespace AUXILIARY {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C050, 0x8000C054, 0x8000C058, 0x8000C05C, LowLevel::Access::ReadWrite>;
        using ADDRESS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 30, std::uint32_t>; /**< Auxiliary 数据缓冲的物理地址高 30 位(bit 31:2)，低 2 位固定为 0。 */
    } // namespace AUXILIARY

    /** @brief GPMI 控制寄存器 1，配置工作模式、中断、采样时序与设备复位等全局参数。 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C060, 0x8000C064, 0x8000C068, 0x8000C06C, LowLevel::Access::ReadWrite>;
        /** @brief GPMI_MODE 的取值。 */
        enum class GPMI_MODE_Values : std::uint32_t {
            NAND = 0x0,
            ATA = 0x1,
        };
        using GPMI_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, GPMI_MODE_Values>; /**< GPMI 工作模式：NAND=NAND Flash 模式；ATA=ATA 硬盘模式。 */
        using CAMERA_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Camera 模式使能，控制 GPMI 是否工作于 Camera 接口模式。 */
        /** @brief ATA_IRQRDY_POLARITY 的取值。 */
        enum class ATA_IRQRDY_POLARITY_Values : std::uint32_t {
            ACTIVELOW = 0x0,
            ACTIVEHIGH = 0x1,
        };
        using ATA_IRQRDY_POLARITY = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, ATA_IRQRDY_POLARITY_Values>; /**< ATA IRQ/RDY 信号极性：ACTIVELOW=低电平有效；ACTIVEHIGH=高电平有效。 */
        /** @brief DEV_RESET 的取值。 */
        enum class DEV_RESET_Values : std::uint32_t {
            ENABLED = 0x0,
            DISABLED = 0x1,
        };
        using DEV_RESET = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, DEV_RESET_Values>; /**< 设备复位控制：ENABLED=释放复位、设备正常工作(写 0)；DISABLED=置位复位、设备被复位(写 1)。 */
        using ABORT_WAIT_FOR_READY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 强制中止设备 0 的等待就绪操作。 */
        using ABORT_WAIT_FOR_READY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 强制中止设备 1 的等待就绪操作。 */
        using ABORT_WAIT_FOR_READY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 强制中止设备 2 的等待就绪操作。 */
        using ABORT_WAIT_FOR_READY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 强制中止设备 3 的等待就绪操作。 */
        using BURST_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< DMA 突发传输(Burst)使能。 */
        using TIMEOUT_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< 设备忙等待超时中断状态位，写 1 清零。 */
        using DEV_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< 设备就绪中断状态位，写 1 清零。 */
        using DMA2ECC_MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< DMA 到 ECC 直通模式使能，控制 DMA 数据是否直接送入 ECC 引擎处理。 */
        using DSAMPLE_TIME = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 读数据采样延时，以 GPMI 时钟周期为单位调整读数据采样时刻，用于时序补偿。 */
    } // namespace CTRL1

    /** @brief NAND 时序寄存器 0，配置 NAND 读写的基础时序参数。 */
    namespace TIMING0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C070, 0x8000C074, 0x8000C078, 0x8000C07C, LowLevel::Access::ReadWrite>;
        using DATA_SETUP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< 数据建立时间，控制 WE/RE 有效到数据稳定所需的 GPMI 时钟周期数。 */
        using DATA_HOLD = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< 数据保持时间，控制数据稳定后 WE/RE 保持有效的 GPMI 时钟周期数。 */
        using ADDRESS_SETUP = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 地址建立时间，控制 ALE/CLE 有效到 WE/RE 有效之间的 GPMI 时钟周期数。 */
    } // namespace TIMING0

    /** @brief NAND 时序寄存器 1，配置设备忙等待超时时间。 */
    namespace TIMING1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C080, 0x8000C084, 0x8000C088, 0x8000C08C, LowLevel::Access::ReadWrite>;
        using DEVICE_BUSY_TIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< 设备忙等待超时计数，以 GPMI 时钟周期为单位设定最大等待时间。 */
    } // namespace TIMING1

    /** @brief UDMA 时序寄存器 2，配置 Ultra DMA 模式下的专用时序参数。 */
    namespace TIMING2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C090, 0x8000C094, 0x8000C098, 0x8000C09C, LowLevel::Access::ReadWrite>;
        using UDMA_SETUP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< UDMA 建立时间，控制 UDMA 传输开始前信号的建立周期数。 */
        using UDMA_HOLD = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 8, std::uint32_t>; /**< UDMA 保持时间，控制 UDMA 传输结束后信号的保持周期数。 */
        using UDMA_ENV = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< UDMA 包络时间，控制 UDMA 传输包络信号的宽度。 */
        using UDMA_TRP = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< UDMA 恢复时间，控制 UDMA 传输之间所需的最小间隔周期数。 */
    } // namespace TIMING2

    /** @brief DMA 数据传送寄存器，用于 APB 总线直接读写 NAND 数据(非 DMA 模式或调试用途)。 */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C0A0, 0x8000C0A4, 0x8000C0A8, 0x8000C0AC, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 32 位数据端口，通过 APB 总线直接读写 NAND 数据。 */
    } // namespace DATA

    /** @brief GPMI 状态寄存器，反映设备错误、FIFO 状态、中断与模块存在性。 */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8000C0B0, 0x8000C0B4, 0x8000C0B8, 0x8000C0BC, LowLevel::Access::ReadWrite>;
        using DEV0_ERROR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 设备 0 错误标志，指示该设备发生错误。 */
        using DEV1_ERROR = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 设备 1 错误标志，指示该设备发生错误。 */
        using DEV2_ERROR = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 设备 2 错误标志，指示该设备发生错误。 */
        using DEV3_ERROR = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 设备 3 错误标志，指示该设备发生错误。 */
        /** @brief FIFO_FULL 的取值。 */
        enum class FIFO_FULL_Values : std::uint32_t {
            NOT_FULL = 0x0,
            FULL = 0x1,
        };
        using FIFO_FULL = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, FIFO_FULL_Values>; /**< FIFO 满状态：NOT_FULL=未满；FULL=已满。 */
        /** @brief FIFO_EMPTY 的取值。 */
        enum class FIFO_EMPTY_Values : std::uint32_t {
            NOT_EMPTY = 0x0,
            EMPTY = 0x1,
        };
        using FIFO_EMPTY = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, FIFO_EMPTY_Values>; /**< FIFO 空状态：NOT_EMPTY=非空；EMPTY=已空。 */
        using INVALID_BUFFER_MASK = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< ECC 缓冲掩码无效标志，指示 ECCCTRL 中 BUFFER_MASK 配置非法。 */
        using ATA_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< ATA 设备中断请求状态。 */
        using RDY_TIMEOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< 就绪超时状态，指示哪个设备发生了 RDY 超时(位映射)。 */
        /** @brief PRESENT 的取值。 */
        enum class PRESENT_Values : std::uint32_t {
            UNAVAILABLE = 0x0,
            AVAILABLE = 0x1,
        };
        using PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, PRESENT_Values>; /**< GPMI 模块存在性：UNAVAILABLE=不存在；AVAILABLE=存在。 */
    } // namespace STAT

    /** @brief GPMI 调试信息寄存器，提供主状态机、引脚状态机、DMA 请求与设备就绪等实时调试信号。 */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8000C0C0, LowLevel::Access::ReadOnly>;
        /** @brief MAIN_STATE 的取值。 */
        enum class MAIN_STATE_Values : std::uint32_t {
            MSM_IDLE = 0x0,
            MSM_BYTCNT = 0x1,
            MSM_WAITFE = 0x2,
            MSM_WAITFR = 0x3,
            MSM_DMAREQ = 0x4,
            MSM_DMAACK = 0x5,
            MSM_WAITFF = 0x6,
            MSM_LDFIFO = 0x7,
            MSM_LDDMAR = 0x8,
            MSM_RDCMP = 0x9,
            MSM_DONE = 0xA,
        };
        using MAIN_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, MAIN_STATE_Values>; /**< 主状态机状态：MSM_IDLE~MSM_DONE，反映 GPMI 内部命令执行流程。 */
        /** @brief PIN_STATE 的取值。 */
        enum class PIN_STATE_Values : std::uint32_t {
            PSM_IDLE = 0x0,
            PSM_BYTCNT = 0x1,
            PSM_ADDR = 0x2,
            PSM_STALL = 0x3,
            PSM_STROBE = 0x4,
            PSM_ATARDY = 0x5,
            PSM_DHOLD = 0x6,
            PSM_DONE = 0x7,
        };
        using PIN_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 3, PIN_STATE_Values>; /**< 引脚状态机状态：PSM_IDLE~PSM_DONE，反映外部引脚时序状态。 */
        /** @brief BUSY 的取值。 */
        enum class BUSY_Values : std::uint32_t {
            DISABLED = 0x0,
            ENABLED = 0x1,
        };
        using BUSY = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, BUSY_Values>; /**< GPMI 忙标志：DISABLED=空闲；ENABLED=忙。 */
        using UDMA_STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< UDMA 状态机当前状态值。 */
        using CMD_END = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< 命令结束状态，反映各通道命令完成情况的位映射。 */
        using DMAREQ0 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 设备 0 的 DMA 请求信号状态。 */
        using DMAREQ1 = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 设备 1 的 DMA 请求信号状态。 */
        using DMAREQ2 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< 设备 2 的 DMA 请求信号状态。 */
        using DMAREQ3 = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< 设备 3 的 DMA 请求信号状态。 */
        using SENSE0 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 设备 0 的 sense 信号状态(用于检测设备就绪/中断)。 */
        using SENSE1 = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< 设备 1 的 sense 信号状态。 */
        using SENSE2 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< 设备 2 的 sense 信号状态。 */
        using SENSE3 = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 设备 3 的 sense 信号状态。 */
        using WAIT_FOR_READY_END0 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 设备 0 的等待就绪结束标志。 */
        using WAIT_FOR_READY_END1 = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< 设备 1 的等待就绪结束标志。 */
        using WAIT_FOR_READY_END2 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< 设备 2 的等待就绪结束标志。 */
        using WAIT_FOR_READY_END3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< 设备 3 的等待就绪结束标志。 */
        using READY0 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< 设备 0 的就绪(READY)信号输入状态。 */
        using READY1 = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< 设备 1 的就绪(READY)信号输入状态。 */
        using READY2 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 设备 2 的就绪(READY)信号输入状态。 */
        using READY3 = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 设备 3 的就绪(READY)信号输入状态。 */
    } // namespace DEBUG

    /** @brief GPMI 版本寄存器，记录模块的硬件版本号。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8000C0D0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 步进版本号，标识当前硬件的步进修订。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 次版本号。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 主版本号。 */
    } // namespace VERSION

    /** @brief GPMI 调试信息寄存器 2，提供读数据采样 DLL 抽头、同步器握手与字节使能等调试信号。 */
    namespace DEBUG2 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8000C0E0, LowLevel::Access::ReadOnly>;
        using RDN_TAP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 6, std::uint32_t>; /**< 读数据采样 DLL 抽头值，反映当前 DLL 延时链的抽头位置。 */
        using UPDATE_WINDOW = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< DLL 更新窗口标志，指示 DLL 是否处于允许更新的时间窗口。 */
        using VIEW_DELAYED_RDN = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 延时读数据采样视图使能，用于观察经 DLL 延时后的读数据采样信号。 */
        using SYND2GPMI_READY = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Syndrome 到 GPMI 的 READY 握手信号状态。 */
        using SYND2GPMI_VALID = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Syndrome 到 GPMI 的 VALID 握手信号状态。 */
        using GPMI2SYND_READY = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< GPMI 到 Syndrome 的 READY 握手信号状态。 */
        using GPMI2SYND_VALID = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< GPMI 到 Syndrome 的 VALID 握手信号状态。 */
        using SYND2GPMI_BE = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 4, std::uint32_t>; /**< Syndrome 到 GPMI 的字节使能信号，指示有效字节位置。 */
    } // namespace DEBUG2

    /** @brief GPMI 调试信息寄存器 3，提供设备侧与 APB 侧的字计数器。 */
    namespace DEBUG3 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8000C0F0, LowLevel::Access::ReadOnly>;
        using DEV_WORD_CNTR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 设备侧已传输字数计数器，反映与 NAND 设备之间传输的字数。 */
        using APB_WORD_CNTR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< APB 侧已传输字数计数器，反映 APB 总线侧传输的字数。 */
    } // namespace DEBUG3

} // namespace Hardware::Registers::GPMI

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_GPMI
