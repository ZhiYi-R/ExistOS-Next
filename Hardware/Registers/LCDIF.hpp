#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_LCDIF
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_LCDIF

/**
 * @file LCDIF.hpp
 * @brief LCDIF 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 LCDIF (eLCDIF) 显示控制器，支持 MPU/8080 并行接口、VSYNC 模式与 DOTCLK 模式，集成 DMA 帧缓冲、RGB-to-YCbCr 4:2:2 CSC 转换、DVI 输出及引脚共享仲裁。基地址 0x80030000。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::LCDIF {

    /** @brief LCDIF 通用控制寄存器，控制数据传输启动、数据格式、接口模式、字节序、移位及复位等全局行为。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030000, 0x80030004, 0x80030008, 0x8003000C, LowLevel::Access::ReadWrite>;
        /** @brief COUNT 的取值。 */
        enum class COUNT_Values : std::uint32_t {
            _16_BIT = 0x0,
            _8_BIT = 0x1,
            _18_BIT = 0x2,
            _24_BIT = 0x3,
        };
        using COUNT = LowLevel::Field<Reg, 0, 16, COUNT_Values>; /**< LCD 数据格式选择，编码像素数据输出位宽（0=16 位，1=8 位，2=18 位，3=24 位）。 */
        /** @brief RUN 的取值。 */
        enum class RUN_Values : std::uint32_t {
            _16_BIT = 0x0,
            _8_BIT = 0x1,
        };
        using RUN = LowLevel::Field<Reg, 16, 1, RUN_Values>; /**< 启动 LCDIF 数据传输，写 1 使能传输引擎运行。 */
        /** @brief WORD_LENGTH 的取值。 */
        enum class WORD_LENGTH_Values : std::uint32_t {
            NO_SWAP = 0x0,
            BIG_ENDIAN_SWAP = 0x1,
        };
        using WORD_LENGTH = LowLevel::Field<Reg, 17, 1, WORD_LENGTH_Values>; /**< 像素字长选择，0=16 位，1=24 位。 */
        /** @brief DATA_SELECT 的取值。 */
        enum class DATA_SELECT_Values : std::uint32_t {
            CMD_MODE = 0x0,
            DATA_MODE = 0x1,
        };
        using DATA_SELECT = LowLevel::Field<Reg, 18, 1, DATA_SELECT_Values>; /**< MPU/8080 接口命令/数据选择，0=命令模式，1=数据模式。 */
        using DOTCLK_MODE = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< DOTCLK 接口模式使能，1 表示使用同步 DOTCLK 时序驱动 RGB 屏。 */
        using VSYNC_MODE = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< VSYNC 接口模式使能，1 表示使用 VSYNC 同步模式。 */
        using DATA_SWIZZLE = LowLevel::Field<Reg, 21, 2, std::uint32_t>; /**< 输入数据字节序调整（Swizzle），控制 32 位字内各字节的排列顺序。 */
        using BYPASS_COUNT = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< 旁路内部行列计数器，1 时由外部逻辑或 DMA 直接控制传输终止。 */
        using DVI_MODE = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< DVI 输出模式使能，1 时启用 DVI/数字视频接口输出。 */
        using SHIFT_NUM_BITS = LowLevel::Field<Reg, 25, 2, std::uint32_t>; /**< 数据移位的位数（0-3），指定像素数据在输出前左/右移的位数。 */
        /** @brief DATA_SHIFT_DIR 的取值。 */
        enum class DATA_SHIFT_DIR_Values : std::uint32_t {
            TXDATA_SHIFT_LEFT = 0x0,
            TXDATA_SHIFT_RIGHT = 0x1,
        };
        using DATA_SHIFT_DIR = LowLevel::Field<Reg, 27, 1, DATA_SHIFT_DIR_Values>; /**< 数据移位方向，0=左移，1=右移。 */
        using WAIT_FOR_VSYNC_EDGE = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 等待 VSYNC 边沿后再启动帧传输，用于帧同步对齐。 */
        using READ_WRITEB = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 读写方向控制，0=写（发送），1=读（接收）。 */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 时钟门控，1 时关闭 LCDIF 内部时钟以节省功耗。 */
        using SFTRST = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 软复位，写 1 对 LCDIF 模块进行软件复位。 */
    } // namespace CTRL

    /** @brief LCDIF 通用控制寄存器 1，包含 LCD 复位、接口子模式、中断状态/使能及字节打包格式。 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030010, 0x80030014, 0x80030018, 0x8003001C, LowLevel::Access::ReadWrite>;
        /** @brief RESET 的取值。 */
        enum class RESET_Values : std::uint32_t {
            LCDRESET_LOW = 0x0,
            LCDRESET_HIGH = 0x1,
        };
        using RESET = LowLevel::Field<Reg, 0, 1, RESET_Values>; /**< LCD 面板硬件复位信号控制，0=低电平复位，1=高电平释放。 */
        /** @brief MODE86 的取值。 */
        enum class MODE86_Values : std::uint32_t {
            _8080_MODE = 0x0,
            _6800_MODE = 0x1,
        };
        using MODE86 = LowLevel::Field<Reg, 1, 1, MODE86_Values>; /**< MPU 接口子模式选择，0=8080 模式，1=6800 模式。 */
        /** @brief BUSY_ENABLE 的取值。 */
        enum class BUSY_ENABLE_Values : std::uint32_t {
            BUSY_DISABLED = 0x0,
            BUSY_ENABLED = 0x1,
        };
        using BUSY_ENABLE = LowLevel::Field<Reg, 2, 1, BUSY_ENABLE_Values>; /**< BUSY 信号检测使能，1 时 LCDIF 在 MPU 读/写期间检测外部 BUSY 信号。 */
        using LCD_CS_CTRL = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< LCD 片选信号控制，直接控制 CS 引脚输出电平。 */
        /** @brief FIRST_READ_DUMMY 的取值。 */
        enum class FIRST_READ_DUMMY_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using FIRST_READ_DUMMY = LowLevel::Field<Reg, 4, 1, FIRST_READ_DUMMY_Values>; /**< 首次读虚拟周期请求，1 时在读序列开头插入一个虚拟读周期。 */
        using READ_MODE_NUM_PACKED_SUBWORDS = LowLevel::Field<Reg, 5, 3, std::uint32_t>; /**< 读模式下每字内打包的子字数量，决定一次 32 位读操作中包含的有效像素子字数。 */
        /** @brief VSYNC_EDGE_IRQ 的取值。 */
        enum class VSYNC_EDGE_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using VSYNC_EDGE_IRQ = LowLevel::Field<Reg, 8, 1, VSYNC_EDGE_IRQ_Values>; /**< VSYNC 边沿中断状态，1 表示检测到 VSYNC 边沿中断请求。 */
        /** @brief CUR_FRAME_DONE_IRQ 的取值。 */
        enum class CUR_FRAME_DONE_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using CUR_FRAME_DONE_IRQ = LowLevel::Field<Reg, 9, 1, CUR_FRAME_DONE_IRQ_Values>; /**< 当前帧完成中断状态，1 表示当前帧传输完成中断请求。 */
        /** @brief UNDERFLOW_IRQ 的取值。 */
        enum class UNDERFLOW_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using UNDERFLOW_IRQ = LowLevel::Field<Reg, 10, 1, UNDERFLOW_IRQ_Values>; /**< 下溢中断状态，1 表示 TXFIFO 下溢中断请求。 */
        /** @brief OVERFLOW_IRQ 的取值。 */
        enum class OVERFLOW_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using OVERFLOW_IRQ = LowLevel::Field<Reg, 11, 1, OVERFLOW_IRQ_Values>; /**< 溢出中断状态，1 表示 RXFIFO/TXFIFO 溢出中断请求。 */
        using VSYNC_EDGE_IRQ_EN = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< VSYNC 边沿中断使能，1 时允许 VSYNC_EDGE_IRQ 产生中断。 */
        using CUR_FRAME_DONE_IRQ_EN = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< 当前帧完成中断使能，1 时允许 CUR_FRAME_DONE_IRQ 产生中断。 */
        using UNDERFLOW_IRQ_EN = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 下溢中断使能，1 时允许 UNDERFLOW_IRQ 产生中断。 */
        using OVERFLOW_IRQ_EN = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 溢出中断使能，1 时允许 OVERFLOW_IRQ 产生中断。 */
        using BYTE_PACKING_FORMAT = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< 字节打包格式，32 位字内各字节通道的有效/无效掩码，用于非 32 位对齐像素格式。 */
    } // namespace CTRL1

    /** @brief LCDIF 有效数据传输计数寄存器，定义一帧内水平与垂直方向的像素数量。 */
    namespace TRANSFER_COUNT {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030020, LowLevel::Access::ReadWrite>;
        using H_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 水平方向有效像素计数（每行像素数）。 */
        using V_COUNT = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 垂直方向有效像素计数（行数）。 */
    } // namespace TRANSFER_COUNT

    /** @brief LCD 接口时序寄存器，配置 MPU/8080 并行接口的命令与数据建立/保持周期。注：该物理地址在 System 模式下为 TRANSFER_COUNT。 */
    namespace TIMING {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030020, 0x80030024, 0x80030028, 0x8003002C, LowLevel::Access::ReadWrite>;
        using DATA_SETUP = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< 数据写操作的建立周期数（DATA 有效到 WR 有效之间的等待时钟数）。 */
        using DATA_HOLD = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< 数据写操作的保持周期数（WR 无效后 DATA 保持有效的时钟数）。 */
        using CMD_SETUP = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 命令写操作的建立周期数（CMD 有效到 WR 有效之间的等待时钟数）。 */
        using CMD_HOLD = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< 命令写操作的保持周期数（WR 无效后 CMD 保持有效的时钟数）。 */
    } // namespace TIMING

    /** @brief LCD 接口当前帧缓冲地址寄存器，存储 DMA 当前正在传输的帧数据物理地址。 */
    namespace CUR_BUF {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030030, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< 当前帧缓冲在系统内存中的 32 位物理地址。 */
    } // namespace CUR_BUF

    /** @brief LCDIF VSYNC/DOTCLK 模式控制寄存器 1，定义 VSYNC 周期（帧总周期）。注：该物理地址在 System 模式下为 CUR_BUF。 */
    namespace VDCTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030030, 0x80030034, 0x80030038, 0x8003003C, LowLevel::Access::ReadWrite>;
        using VSYNC_PERIOD = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< VSYNC 周期值，表示一帧的总时钟周期数（含有效与消隐区）。 */
    } // namespace VDCTRL1

    /** @brief LCD 接口下一帧缓冲地址寄存器，存储 DMA 下一帧待传输的帧数据物理地址。 */
    namespace NEXT_BUF {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030040, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< 下一帧缓冲在系统内存中的 32 位物理地址，硬件在当前帧完成后自动切换。 */
    } // namespace NEXT_BUF

    /** @brief LCDIF VSYNC/DOTCLK 模式控制寄存器 2，定义 HSYNC 周期与脉冲宽度。注：该物理地址在 System 模式下为 NEXT_BUF。 */
    namespace VDCTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030040, 0x80030044, 0x80030048, 0x8003004C, LowLevel::Access::ReadWrite>;
        using HSYNC_PERIOD = LowLevel::Field<Reg, 0, 18, std::uint32_t>; /**< HSYNC 周期值，表示一行的总时钟周期数（含有效与消隐区）。 */
        using HSYNC_PULSE_WIDTH = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< HSYNC 脉冲宽度，表示水平同步脉冲持续的有效时钟周期数。 */
    } // namespace VDCTRL2

    /** @brief LCDIF 页表寄存器，使能 DMA 页表寻址并配置页表基地址。 */
    namespace PAGETABLE {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030050, LowLevel::Access::ReadWrite>;
        using ENABLE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 页表机制使能，1 时 DMA 通过页表进行分散/聚集式地址转换。 */
        using FLUSH = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 页表刷新，写 1 强制刷新内部页表缓存。 */
        using BASE = LowLevel::Field<Reg, 14, 18, std::uint32_t>; /**< 页表基地址的高 18 位（以 16KB 对齐），指向内存中的页表起始位置。 */
    } // namespace PAGETABLE

    /** @brief LCDIF VSYNC/DOTCLK 模式控制寄存器 3，配置行列等待计数及同步信号复用。注：该物理地址在 System 模式下为 PAGETABLE。 */
    namespace VDCTRL3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030050, 0x80030054, 0x80030058, 0x8003005C, LowLevel::Access::ReadWrite>;
        using VERTICAL_WAIT_CNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 垂直等待计数，表示 VSYNC 有效后到首行有效数据前的行等待周期数。 */
        using HORIZONTAL_WAIT_CNT = LowLevel::Field<Reg, 16, 12, std::uint32_t>; /**< 水平等待计数，表示 HSYNC 有效后到首像素有效数据前的时钟等待周期数。 */
        using VSYNC_ONLY = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 仅 VSYNC 模式，1 时关闭 DOTCLK 输出，仅使用 VSYNC 同步。 */
        using MUX_SYNC_SIGNALS = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 同步信号复用使能，1 时将 VSYNC/HSYNC/ENABLE 信号复用输出。 */
    } // namespace VDCTRL3

    /** @brief LCDIF VSYNC/DOTCLK 模式控制寄存器 4，配置水平有效数据计数及同步信号强制输出。 */
    namespace VDCTRL4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030060, 0x80030064, 0x80030068, 0x8003006C, LowLevel::Access::ReadWrite>;
        using DOTCLK_H_VALID_DATA_CNT = LowLevel::Field<Reg, 0, 18, std::uint32_t>; /**< DOTCLK 模式下每行有效数据像素计数。 */
        using SYNC_SIGNALS_ON = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< 强制同步信号输出使能，1 时持续输出 HSYNC/VSYNC/ENABLE 波形。 */
    } // namespace VDCTRL4

    /** @brief LCDIF VSYNC/DOTCLK 模式控制寄存器 0，配置 VSYNC 脉冲宽度、极性、半行模式及同步信号属性。 */
    namespace VDCTRL0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030070, LowLevel::Access::ReadWrite>;
        using VSYNC_PULSE_WIDTH = LowLevel::Field<Reg, 0, 18, std::uint32_t>; /**< VSYNC 脉冲宽度，表示垂直同步脉冲持续的有效时钟周期数。 */
        using HALF_LINE_MODE = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< 半行模式使能，1 时每帧按半行粒度进行扫描时序控制。 */
        using HALF_LINE = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< 半行指示，当前处于半行扫描状态标志（只读）。 */
        using VSYNC_PULSE_WIDTH_UNIT = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< VSYNC 脉冲宽度单位，0=以像素时钟为单位，1=以行为单位。 */
        using VSYNC_PERIOD_UNIT = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< VSYNC 周期单位，0=以像素时钟为单位，1=以行为单位。 */
        using ENABLE_POL = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 数据使能信号（ENABLE/DE）极性，0=低电平有效，1=高电平有效。 */
        using DOTCLK_POL = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< DOTCLK 像素时钟极性，0=上升沿采样，1=下降沿采样。 */
        using HSYNC_POL = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< HSYNC 水平同步极性，0=低电平有效，1=高电平有效。 */
        using VSYNC_POL = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< VSYNC 垂直同步极性，0=低电平有效，1=高电平有效。 */
        using ENABLE_PRESENT = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 数据使能信号（ENABLE/DE）存在标志，1 表示接口使用 DE 信号。 */
        /** @brief VSYNC_OEB 的取值。 */
        enum class VSYNC_OEB_Values : std::uint32_t {
            VSYNC_OUTPUT = 0x0,
            VSYNC_INPUT = 0x1,
        };
        using VSYNC_OEB = LowLevel::Field<Reg, 29, 1, VSYNC_OEB_Values>; /**< VSYNC 引脚方向控制，0=输出（内部产生 VSYNC），1=输入（外部接收 VSYNC）。 */
    } // namespace VDCTRL0

    /** @brief 数字视频接口控制寄存器 0，配置 DVI 输出时视频帧的行数、水平消隐与有效像素。注：该物理地址在 VSYNC/DOTCLK 模式下为 VDCTRL0。 */
    namespace DVICTRL0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030070, LowLevel::Access::ReadWrite>;
        using V_LINES_CNT = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 每帧有效视频行数（垂直方向总行数）。 */
        using H_BLANKING_CNT = LowLevel::Field<Reg, 10, 10, std::uint32_t>; /**< 水平消隐期像素计数（每行中无效像素时钟数）。 */
        using H_ACTIVE_CNT = LowLevel::Field<Reg, 20, 11, std::uint32_t>; /**< 水平有效像素计数（每行中有效像素数）。 */
        using START_TRS = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< DVI 传输启动，写 1 开始 DVI 数据流输出。 */
    } // namespace DVICTRL0

    /** @brief 数字视频接口控制寄存器 1，配置隔行扫描时场 1 与场 2 的起止行位置。注：该物理地址在 VSYNC/DOTCLK 模式下为 VDCTRL0，与 DVICTRL0 共享地址。 */
    namespace DVICTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030070, 0x80030074, 0x80030078, 0x8003007C, LowLevel::Access::ReadWrite>;
        using F2_START_LINE = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 场 2（F2）起始行号，定义隔行扫描第二场的第一有效行。 */
        using F1_END_LINE = LowLevel::Field<Reg, 10, 10, std::uint32_t>; /**< 场 1（F1）结束行号，定义隔行扫描第一场的最后一有效行。 */
        using F1_START_LINE = LowLevel::Field<Reg, 20, 10, std::uint32_t>; /**< 场 1（F1）起始行号，定义隔行扫描第一场的第一有效行。 */
    } // namespace DVICTRL1

    /** @brief 数字视频接口控制寄存器 2，配置场 1 垂直消隐及场 2 结束行位置。 */
    namespace DVICTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030080, 0x80030084, 0x80030088, 0x8003008C, LowLevel::Access::ReadWrite>;
        using V1_BLANK_END_LINE = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 场 1 垂直消隐结束行号，定义第一场消隐期结束、有效视频开始的行。 */
        using V1_BLANK_START_LINE = LowLevel::Field<Reg, 10, 10, std::uint32_t>; /**< 场 1 垂直消隐开始行号，定义第一场有效视频结束、消隐开始的行。 */
        using F2_END_LINE = LowLevel::Field<Reg, 20, 10, std::uint32_t>; /**< 场 2（F2）结束行号，定义隔行扫描第二场的最后一有效行。 */
    } // namespace DVICTRL2

    /** @brief 数字视频接口控制寄存器 3，配置场 2 垂直消隐起止行位置。 */
    namespace DVICTRL3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030090, 0x80030094, 0x80030098, 0x8003009C, LowLevel::Access::ReadWrite>;
        using V2_BLANK_END_LINE = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< 场 2 垂直消隐结束行号，定义第二场消隐期结束、有效视频开始的行。 */
        using V2_BLANK_START_LINE = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< 场 2 垂直消隐开始行号，定义第二场有效视频结束、消隐开始的行。 */
    } // namespace DVICTRL3

    /** @brief 数字视频接口控制寄存器 4，配置 DVI 水平填充计数及 YCbCr 填充值。 */
    namespace DVICTRL4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800300A0, 0x800300A4, 0x800300A8, 0x800300AC, LowLevel::Access::ReadWrite>;
        using H_FILL_CNT = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< 水平填充像素计数，定义每行消隐期插入的填充像素数。 */
        using CR_FILL_VALUE = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< Cr 色度填充值，消隐期输出的 Cr 分量默认值。 */
        using CB_FILL_VALUE = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Cb 色度填充值，消隐期输出的 Cb 分量默认值。 */
        using Y_FILL_VALUE = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Y 亮度填充值，消隐期输出的 Y 分量默认值。 */
    } // namespace DVICTRL4

    /** @brief LCD 接口数据寄存器，用于 PIO 方式直接写入 4 字节像素数据到 TXFIFO。 */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800300B0, 0x800300B4, 0x800300B8, 0x800300BC, LowLevel::Access::ReadWrite>;
        using DATA_ZERO = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< 字节 0 数据，32 位字中最低有效字节对应的像素数据。 */
        using DATA_ONE = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< 字节 1 数据，32 位字中次低字节对应的像素数据。 */
        using DATA_TWO = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 字节 2 数据，32 位字中次高字节对应的像素数据。 */
        using DATA_THREE = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< 字节 3 数据，32 位字中最高有效字节对应的像素数据。 */
    } // namespace DATA

    /** @brief 总线主设备错误状态寄存器，记录 DMA 传输发生总线错误时的出错地址。注：该物理地址在其他模式下作为 STAT（状态寄存器）使用。 */
    namespace BM_ERROR_STAT {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800300C0, LowLevel::Access::ReadOnly>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< DMA 总线错误发生时的 32 位出错内存地址。 */
    } // namespace BM_ERROR_STAT

    /** @brief LCD 接口状态寄存器，反映当前运行状态、FIFO 状态及 DMA 请求标志。注：该物理地址在 System 模式下为 BM_ERROR_STAT（总线错误状态寄存器）。 */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800300C0, 0x800300C4, 0x800300C8, 0x800300CC, LowLevel::Access::ReadWrite>;
        using DVI_CURRENT_FIELD = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< DVI 当前场指示，0=场 1，1=场 2（隔行输出时）。 */
        using BUSY = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 忙标志，1 表示 LCDIF 正在执行数据传输或时序生成。 */
        using TXFIFO_EMPTY = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< 发送 FIFO 空标志，1 表示 TXFIFO 已空。 */
        using TXFIFO_FULL = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< 发送 FIFO 满标志，1 表示 TXFIFO 已满。 */
        using RXFIFO_EMPTY = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 接收 FIFO 空标志，1 表示 RXFIFO 已空。 */
        using RXFIFO_FULL = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 接收 FIFO 满标志，1 表示 RXFIFO 已满。 */
        using DMA_REQ = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< DMA 请求标志，1 表示 LCDIF 正在向 DMA 控制器请求数据传输。 */
        using PRESENT = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 模块存在标志，1 表示 LCDIF 硬件模块已集成并可用。 */
    } // namespace STAT

    /** @brief LCD 接口版本寄存器，读取硬件版本号（主/次/步进）。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800300D0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 步进版本号（STEP），标识当前硬件的修订步进。 */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 次版本号（MINOR），标识当前硬件的次要版本。 */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< 主版本号（MAJOR），标识当前硬件的主要版本。 */
    } // namespace VERSION

    /** @brief LCD 接口调试寄存器 0，提供内部状态机、握手信号及同步信号的实时快照。 */
    namespace DEBUG0 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800300E0, LowLevel::Access::ReadOnly>;
        using LCDIF_GPMI_GRANT = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< GPMI 对 LCDIF 的引脚共享授权信号，1 表示 GPMI 已授权 LCDIF 使用共享引脚。 */
        using GPMI_LCDIF_REQ = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< GPMI 向 LCDIF 发出的引脚共享请求信号。 */
        using LCDIF_PXP_B1_DONE = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< LCDIF 到 PXP 的 Buffer 1 完成信号，1 表示 LCDIF 已完成 Buffer 1 的像素处理。 */
        using PXP_LCDIF_B1_READY = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< PXP 到 LCDIF 的 Buffer 1 就绪信号，1 表示 PXP 已准备好 Buffer 1 数据供 LCDIF 读取。 */
        using LCDIF_PXP_B0_DONE = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< LCDIF 到 PXP 的 Buffer 0 完成信号，1 表示 LCDIF 已完成 Buffer 0 的像素处理。 */
        using PXP_LCDIF_B0_READY = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< PXP 到 LCDIF 的 Buffer 0 就绪信号，1 表示 PXP 已准备好 Buffer 0 数据供 LCDIF 读取。 */
        using CUR_STATE = LowLevel::Field<Reg, 16, 7, std::uint32_t>; /**< 当前状态机状态码，反映 LCDIF 内部控制状态机的当前状态编号。 */
        using EMPTY_WORD = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< 空字标志，1 表示当前 TXFIFO 输出为空字（填充数据）。 */
        using CUR_FRAME_TX = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 当前帧传输中标志，1 表示 LCDIF 正在传输当前帧数据。 */
        using VSYNC = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 内部 VSYNC 信号实时状态。 */
        using HSYNC = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< 内部 HSYNC 信号实时状态。 */
        using ENABLE = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< 内部 ENABLE/DE 数据使能信号实时状态。 */
        using DMACMDKICK = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< DMA 命令触发（Kick）信号，1 表示 DMA 命令已被触发执行。 */
        using SYNC_SIGNALS_ON_REG = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 同步信号强制输出寄存器位的实时状态，反映 VDCTRL4.SYNC_SIGNALS_ON 的生效状态。 */
        using WAIT_FOR_VSYNC_EDGE_OUT = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< WAIT_FOR_VSYNC_EDGE 输出的实时状态，反映 CTRL 中该位的内部生效状态。 */
        using STREAMING_END_DETECTED = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 流结束检测标志，1 表示 LCDIF 检测到数据流传输结束。 */
    } // namespace DEBUG0

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换系数寄存器 0，配置色度子采样滤波器及 CSC 矩阵系数 C0。 */
    namespace CSC_COEFF0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030110, 0x80030114, 0x80030118, 0x8003011C, LowLevel::Access::ReadWrite>;
        /** @brief CSC_SUBSAMPLE_FILTER 的取值。 */
        enum class CSC_SUBSAMPLE_FILTER_Values : std::uint32_t {
            SAMPLE_AND_HOLD = 0x0,
            RSRVD = 0x1,
            INTERSTITIAL = 0x2,
            COSITED = 0x3,
        };
        using CSC_SUBSAMPLE_FILTER = LowLevel::Field<Reg, 0, 2, CSC_SUBSAMPLE_FILTER_Values>; /**< 色度子采样滤波器模式选择，0=采样保持，2=间插式，3=共位式。 */
        using C0 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C0（10 位有符号定点数），用于 RGB 到 YCbCr 的线性变换。 */
    } // namespace CSC_COEFF0

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换系数寄存器 1，配置 CSC 矩阵系数 C1 与 C2。 */
    namespace CSC_COEFF1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030120, 0x80030124, 0x80030128, 0x8003012C, LowLevel::Access::ReadWrite>;
        using C1 = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C1（10 位有符号定点数）。 */
        using C2 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C2（10 位有符号定点数）。 */
    } // namespace CSC_COEFF1

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换系数寄存器 2，配置 CSC 矩阵系数 C3 与 C4。 */
    namespace CSC_COEFF2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030130, 0x80030134, 0x80030138, 0x8003013C, LowLevel::Access::ReadWrite>;
        using C3 = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C3（10 位有符号定点数）。 */
        using C4 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C4（10 位有符号定点数）。 */
    } // namespace CSC_COEFF2

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换系数寄存器 3，配置 CSC 矩阵系数 C5 与 C6。 */
    namespace CSC_COEFF3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030140, 0x80030144, 0x80030148, 0x8003014C, LowLevel::Access::ReadWrite>;
        using C5 = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C5（10 位有符号定点数）。 */
        using C6 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C6（10 位有符号定点数）。 */
    } // namespace CSC_COEFF3

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换系数寄存器 4，配置 CSC 矩阵系数 C7 与 C8。 */
    namespace CSC_COEFF4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030150, 0x80030154, 0x80030158, 0x8003015C, LowLevel::Access::ReadWrite>;
        using C7 = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C7（10 位有符号定点数）。 */
        using C8 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< CSC 转换矩阵系数 C8（10 位有符号定点数）。 */
    } // namespace CSC_COEFF4

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换偏移寄存器，配置 Y 与 CbCr 的亮度/色度偏移量。 */
    namespace CSC_OFFSET {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030160, 0x80030164, 0x80030168, 0x8003016C, LowLevel::Access::ReadWrite>;
        using Y_OFFSET = LowLevel::Field<Reg, 0, 9, std::uint32_t>; /**< Y 亮度分量偏移量（9 位有符号数），用于 CSC 转换后的亮度平移。 */
        using CBCR_OFFSET = LowLevel::Field<Reg, 16, 9, std::uint32_t>; /**< Cb/Cr 色度分量偏移量（9 位有符号数），用于 CSC 转换后的色度平移。 */
    } // namespace CSC_OFFSET

    /** @brief RGB 到 YCbCr 4:2:2 色彩空间转换限幅寄存器，配置 Y 与 CbCr 的输出上下限。 */
    namespace CSC_LIMIT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030170, 0x80030174, 0x80030178, 0x8003017C, LowLevel::Access::ReadWrite>;
        using Y_MAX = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< Y 亮度分量输出最大值（上限限幅值）。 */
        using Y_MIN = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< Y 亮度分量输出最小值（下限限幅值）。 */
        using CBCR_MAX = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Cb/Cr 色度分量输出最大值（上限限幅值）。 */
        using CBCR_MIN = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Cb/Cr 色度分量输出最小值（下限限幅值）。 */
    } // namespace CSC_LIMIT

    /** @brief 引脚共享控制寄存器 0，使能 LCDIF 与 GPMI 的引脚共享仲裁，并配置中断与复用覆盖。 */
    namespace PIN_SHARING_CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030180, 0x80030184, 0x80030188, 0x8003018C, LowLevel::Access::ReadWrite>;
        using PIN_SHARING_ENABLE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 引脚共享机制使能，1 时允许 LCDIF 与 GPMI 通过仲裁共享外部数据总线引脚。 */
        /** @brief PIN_SHARING_IRQ 的取值。 */
        enum class PIN_SHARING_IRQ_Values : std::uint32_t {
            NO_REQUEST = 0x0,
            REQUEST = 0x1,
        };
        using PIN_SHARING_IRQ = LowLevel::Field<Reg, 1, 1, PIN_SHARING_IRQ_Values>; /**< 引脚共享中断状态，1 表示引脚共享仲裁事件产生中断请求。 */
        using PIN_SHARING_IRQ_EN = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 引脚共享中断使能，1 时允许 PIN_SHARING_IRQ 产生中断。 */
        /** @brief MUX_OVERRIDE 的取值。 */
        enum class MUX_OVERRIDE_Values : std::uint32_t {
            NO_OVERRIDE = 0x0,
            RSRVD = 0x1,
            LCDIF_SEL = 0x2,
            GPMI_SEL = 0x3,
        };
        using MUX_OVERRIDE = LowLevel::Field<Reg, 4, 2, MUX_OVERRIDE_Values>; /**< 引脚复用覆盖选择，0=无覆盖，2=强制 LCDIF 使用，3=强制 GPMI 使用。 */
    } // namespace PIN_SHARING_CTRL0

    /** @brief 引脚共享控制寄存器 1，配置引脚共享仲裁阈值 1（GPMI 优先阈值或时间窗口）。 */
    namespace PIN_SHARING_CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80030190, 0x80030194, 0x80030198, 0x8003019C, LowLevel::Access::ReadWrite>;
        using THRESHOLD1 = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< 引脚共享仲裁阈值 1，用于控制 LCDIF 与 GPMI 之间的总线占用时间分配。 */
    } // namespace PIN_SHARING_CTRL1

    /** @brief 引脚共享控制寄存器 2，配置引脚共享仲裁阈值 2（LCDIF 优先阈值或时间窗口）。 */
    namespace PIN_SHARING_CTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800301A0, 0x800301A4, 0x800301A8, 0x800301AC, LowLevel::Access::ReadWrite>;
        using THRESHOLD2 = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< 引脚共享仲裁阈值 2，用于控制 LCDIF 与 GPMI 之间的总线占用时间分配。 */
    } // namespace PIN_SHARING_CTRL2

    /** @brief LCD 接口调试寄存器 1，提供内部垂直与水平像素计数器的实时值。 */
    namespace DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80030200, LowLevel::Access::ReadOnly>;
        using V_DATA_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 垂直数据计数器，当前帧已传输的行数（有效数据行计数）。 */
        using H_DATA_COUNT = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 水平数据计数器，当前行已传输的像素数（有效数据像素计数）。 */
    } // namespace DEBUG1

} // namespace Hardware::Registers::LCDIF

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_LCDIF
