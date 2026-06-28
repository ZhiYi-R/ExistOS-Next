#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_LCDIF
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_LCDIF

/**
 * @file LCDIF.hpp
 * @brief LCD 接口控制器(LCDIF)驱动 —— MPU/8080 system 模式:模块复位/门控、接口与时序
 *        配置、LCD 硬复位、PIO 命令/数据收发、帧缓冲 DMA 地址、状态与中断。
 *
 * HP39GII 的 LCD 经 LCDIF 的 MPU(system)并口驱动:CPU 先发命令(DATA_SELECT=CMD_MODE)
 * 再发参数/像素数据(DATA_SELECT=DATA_MODE),WR/RD 时序由 TIMING 寄存器(建立/保持周期)
 * 决定;批量像素帧则交 APBH-DMA 经 CUR_BUF/NEXT_BUF 推送,免 CPU 逐字搬运。
 *
 * 一次 PIO/DMA 传输的通用流程:
 *  1. 配置数据宽度(CTRL.COUNT)、接口子模式(CTRL1.MODE86=8080)、读写方向(CTRL.READ_WRITEB);
 *  2. 命令/数据选择(CTRL.DATA_SELECT)、传输字数(TRANSFER_COUNT.H_COUNT×V_COUNT);
 *  3. 置 CTRL.RUN 启动,PIO 时把字写入 DATA 寄存器、DMA 时由引擎灌 FIFO;
 *  4. 传完 H×V 个字后 RUN 自清,或读 STAT.BUSY 查询。
 *
 * 本驱动是**控制器层**:只暴露上述寄存器语义动作(触发)与状态谓词;不提供 SendCommand/SendData
 * 这类"配方向→置计数→Run→写字→等完成"的阻塞复合,**单字 PIO 的步序与等待编排上移 OS**——
 * 由上层用 SetWriteDirection/SetDataSelect/SetTransferCount/Run/WriteData 触发,IsRunning() 查询完成。
 * 具体面板初始化命令序列、帧格式编排属上层 panel 驱动;批量帧 DMA 由调用方组合
 * `LCDIF::SetCurrentBuffer(physAddr)` 与 `Drivers/APBH.hpp` 的通道操作完成。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * @note 寄存器/字段取自生成头 Registers/LCDIF.hpp,复位原语复用 Common::{AssertSoftReset,…}。
 *       TRANSFER_COUNT 与 TIMING 在生成头中共享物理地址 0x80030020(System 模式视图为前者,
 *       时序配置视图为后者),分别用于"设传输字数"与"设读写时序",二者按阶段使用。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/LCDIF.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    /** @brief LCD 接口控制器(LCDIF)驱动:纯静态门面,无实例。 */
    struct LCDIF {
        LCDIF() = delete;
        ~LCDIF() = delete;
        LCDIF(const LCDIF&) = delete;
        LCDIF& operator=(const LCDIF&) = delete;

    private:
        using ControlRegister = Registers::LCDIF::CTRL::Reg;                  /**< 主控制寄存器(RUN/方向/选择/位宽)。 */
        using InterfaceControlRegister = Registers::LCDIF::CTRL1::Reg;        /**< 接口控制寄存器(MODE86/LCD 复位/中断)。 */
        using TimingRegister = Registers::LCDIF::TIMING::Reg;                 /**< 读写时序寄存器。 */
        using TransferCountRegister = Registers::LCDIF::TRANSFER_COUNT::Reg;  /**< 传输字数寄存器。 */
        using StatusRegister = Registers::LCDIF::STAT::Reg;                   /**< 状态寄存器(BUSY/FIFO)。 */
        using DataRegister = Registers::LCDIF::DATA::Reg;                     /**< PIO 数据端口。 */
        using CurrentBufferRegister = Registers::LCDIF::CUR_BUF::Reg;         /**< 当前帧缓冲地址寄存器。 */
        using NextBufferRegister = Registers::LCDIF::NEXT_BUF::Reg;           /**< 下一帧缓冲地址寄存器。 */

        using SoftReset = Registers::LCDIF::CTRL::SFTRST;  /**< CTRL.SFTRST 字段后端。 */
        using ClockGate = Registers::LCDIF::CTRL::CLKGATE; /**< CTRL.CLKGATE 字段后端。 */

    public:
        /** @brief LCD 数据总线宽度/像素格式(CTRL.COUNT:16/8/18/24 位)。 */
        using BusWidth = Registers::LCDIF::CTRL::COUNT_Values;
        /** @brief MPU 接口子模式(CTRL1.MODE86:8080 / 6800)。 */
        using InterfaceMode = Registers::LCDIF::CTRL1::MODE86_Values;
        /** @brief 命令/数据选择(CTRL.DATA_SELECT:CMD_MODE / DATA_MODE)。 */
        using DataSelect = Registers::LCDIF::CTRL::DATA_SELECT_Values;

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

        /** @brief 使能 LCDIF 模块时钟(清 CTRL.CLKGATE)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 LCDIF 模块时钟(置 CTRL.CLKGATE),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        // ====================== 接口与时序配置 ======================

        /**
         * @brief 设置数据总线宽度/像素格式(写 CTRL.COUNT)。
         * @param busWidth 总线宽度(8/16/18/24 位)。
         */
        [[gnu::always_inline]] static void SetBusWidth(BusWidth busWidth) noexcept {
            ControlRegister::template WriteField<Registers::LCDIF::CTRL::COUNT>(busWidth);
        }

        /**
         * @brief 配置 MPU 接口子模式与 BUSY 检测(写 CTRL1.MODE86/BUSY_ENABLE,一次 RMW)。
         * @param mode             8080 或 6800 子模式。
         * @param enableBusyDetect 是否在读/写期间检测外部 BUSY 信号。
         */
        [[gnu::always_inline]] static void ConfigureMpuInterface(InterfaceMode mode,
                                                                 bool enableBusyDetect) noexcept {
            InterfaceControlRegister::template WriteFields<Registers::LCDIF::CTRL1::MODE86,
                                                           Registers::LCDIF::CTRL1::BUSY_ENABLE>(
                mode, enableBusyDetect ? Registers::LCDIF::CTRL1::BUSY_ENABLE_Values::BUSY_ENABLED
                                       : Registers::LCDIF::CTRL1::BUSY_ENABLE_Values::BUSY_DISABLED);
        }

        /**
         * @brief 设置 MPU 读写时序(写 TIMING 的数据/命令建立与保持周期,一次 RMW)。
         * @param dataSetup    数据建立周期(DATA_SETUP)。
         * @param dataHold     数据保持周期(DATA_HOLD)。
         * @param commandSetup 命令建立周期(CMD_SETUP)。
         * @param commandHold  命令保持周期(CMD_HOLD)。
         */
        [[gnu::always_inline]] static void SetTimings(std::uint32_t dataSetup, std::uint32_t dataHold,
                                                      std::uint32_t commandSetup,
                                                      std::uint32_t commandHold) noexcept {
            TimingRegister::template WriteFields<Registers::LCDIF::TIMING::DATA_SETUP,
                                                 Registers::LCDIF::TIMING::DATA_HOLD,
                                                 Registers::LCDIF::TIMING::CMD_SETUP,
                                                 Registers::LCDIF::TIMING::CMD_HOLD>(
                dataSetup, dataHold, commandSetup, commandHold);
        }

        // ====================== LCD 面板硬复位(CTRL1.RESET) ======================

        /** @brief 拉低 LCD 复位线进入复位(清 CTRL1.RESET,低电平有效,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AssertLcdReset() noexcept {
            InterfaceControlRegister::template ClearField<Registers::LCDIF::CTRL1::RESET>();
        }

        /** @brief 释放 LCD 复位线(置 CTRL1.RESET,单条原子 str→SET)。 */
        [[gnu::always_inline]] static void DeassertLcdReset() noexcept {
            InterfaceControlRegister::template SetField<Registers::LCDIF::CTRL1::RESET>();
        }

        // ====================== 传输控制(触发 + 谓词) ======================

        /**
         * @brief 设置传输字数(写 TRANSFER_COUNT 的 H_COUNT×V_COUNT,一次 RMW)。
         * @param horizontalCount 水平字数(每行)。
         * @param verticalCount   垂直行数(PIO 单字传输时取 1)。
         */
        [[gnu::always_inline]] static void SetTransferCount(std::uint32_t horizontalCount,
                                                            std::uint32_t verticalCount) noexcept {
            TransferCountRegister::template WriteFields<Registers::LCDIF::TRANSFER_COUNT::H_COUNT,
                                                        Registers::LCDIF::TRANSFER_COUNT::V_COUNT>(
                horizontalCount, verticalCount);
        }

        /**
         * @brief 选择命令/数据模式(写 CTRL.DATA_SELECT)。
         * @param dataSelect CMD_MODE(命令)或 DATA_MODE(数据)。
         */
        [[gnu::always_inline]] static void SetDataSelect(DataSelect dataSelect) noexcept {
            ControlRegister::template WriteField<Registers::LCDIF::CTRL::DATA_SELECT>(dataSelect);
        }

        /** @brief 设为写方向(清 CTRL.READ_WRITEB,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void SetWriteDirection() noexcept {
            ControlRegister::template ClearField<Registers::LCDIF::CTRL::READ_WRITEB>();
        }

        /** @brief 设为读方向(置 CTRL.READ_WRITEB,单条原子 str→SET)。 */
        [[gnu::always_inline]] static void SetReadDirection() noexcept {
            ControlRegister::template SetField<Registers::LCDIF::CTRL::READ_WRITEB>();
        }

        /** @brief 启动传输引擎(置 CTRL.RUN,单条原子 str→SET);传完 H×V 字后硬件自清。 */
        [[gnu::always_inline]] static void Run() noexcept {
            ControlRegister::template SetField<Registers::LCDIF::CTRL::RUN>();
        }

        /** @brief 停止传输引擎(清 CTRL.RUN,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void Stop() noexcept {
            ControlRegister::template ClearField<Registers::LCDIF::CTRL::RUN>();
        }

        /** @brief 非阻塞谓词:传输引擎是否仍在运行(读 CTRL.RUN);自清后返回 false 表示传输完成。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsRunning() noexcept {
            return ControlRegister::template FieldIsSet<Registers::LCDIF::CTRL::RUN>();
        }

        /** @brief LCDIF 是否忙(读 STAT.BUSY)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsBusy() noexcept {
            return StatusRegister::template FieldIsSet<Registers::LCDIF::STAT::BUSY>();
        }

        /** @brief 发送 FIFO 是否已满(读 STAT.TXFIFO_FULL)。满时不可再写 DATA。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsTransmitFifoFull() noexcept {
            return StatusRegister::template FieldIsSet<Registers::LCDIF::STAT::TXFIFO_FULL>();
        }

        /** @brief 发送 FIFO 是否为空(读 STAT.TXFIFO_EMPTY)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsTransmitFifoEmpty() noexcept {
            return StatusRegister::template FieldIsSet<Registers::LCDIF::STAT::TXFIFO_EMPTY>();
        }

        // ====================== PIO 数据端口 ======================

        /**
         * @brief 向 TXFIFO 写一个 32 位字(写 DATA 寄存器);需先置 RUN 并配好计数。
         * @param word 要发送的数据字(按 BUS 宽度取低位)。
         */
        [[gnu::always_inline]] static void WriteData(std::uint32_t word) noexcept {
            DataRegister::Write(word);
        }

        // ====================== 帧缓冲 DMA 地址 ======================

        /**
         * @brief 设置当前帧缓冲物理地址(写 CUR_BUF),供 APBH-DMA 推送像素帧。
         * @param physicalAddress 帧缓冲 32 位物理地址。
         */
        [[gnu::always_inline]] static void SetCurrentBuffer(std::uint32_t physicalAddress) noexcept {
            CurrentBufferRegister::Write(physicalAddress);
        }

        /**
         * @brief 设置下一帧缓冲物理地址(写 NEXT_BUF);硬件在当前帧完成后自动切换。
         * @param physicalAddress 帧缓冲 32 位物理地址。
         */
        [[gnu::always_inline]] static void SetNextBuffer(std::uint32_t physicalAddress) noexcept {
            NextBufferRegister::Write(physicalAddress);
        }

        // ====================== 中断(CTRL1:帧完成 / 下溢 / 上溢) ======================

        /** @brief 使能"当前帧完成"中断(置 CTRL1.CUR_FRAME_DONE_IRQ_EN)。 */
        [[gnu::always_inline]] static void EnableFrameDoneInterrupt() noexcept {
            InterfaceControlRegister::template SetField<Registers::LCDIF::CTRL1::CUR_FRAME_DONE_IRQ_EN>();
        }

        /** @brief 关闭"当前帧完成"中断(清 CTRL1.CUR_FRAME_DONE_IRQ_EN)。 */
        [[gnu::always_inline]] static void DisableFrameDoneInterrupt() noexcept {
            InterfaceControlRegister::template ClearField<Registers::LCDIF::CTRL1::CUR_FRAME_DONE_IRQ_EN>();
        }

        /** @brief "当前帧完成"中断是否挂起(读 CTRL1.CUR_FRAME_DONE_IRQ)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsFrameDoneInterruptPending() noexcept {
            return InterfaceControlRegister::template FieldIsSet<Registers::LCDIF::CTRL1::CUR_FRAME_DONE_IRQ>();
        }

        /** @brief 清除"当前帧完成"中断标志(清 CTRL1.CUR_FRAME_DONE_IRQ,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AcknowledgeFrameDoneInterrupt() noexcept {
            InterfaceControlRegister::template ClearField<Registers::LCDIF::CTRL1::CUR_FRAME_DONE_IRQ>();
        }

        /** @brief TXFIFO 下溢中断是否挂起(读 CTRL1.UNDERFLOW_IRQ)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsUnderflowInterruptPending() noexcept {
            return InterfaceControlRegister::template FieldIsSet<Registers::LCDIF::CTRL1::UNDERFLOW_IRQ>();
        }

        /** @brief 清除 TXFIFO 下溢中断标志(清 CTRL1.UNDERFLOW_IRQ,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AcknowledgeUnderflowInterrupt() noexcept {
            InterfaceControlRegister::template ClearField<Registers::LCDIF::CTRL1::UNDERFLOW_IRQ>();
        }

        /** @brief FIFO 上溢中断是否挂起(读 CTRL1.OVERFLOW_IRQ)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsOverflowInterruptPending() noexcept {
            return InterfaceControlRegister::template FieldIsSet<Registers::LCDIF::CTRL1::OVERFLOW_IRQ>();
        }

        /** @brief 清除 FIFO 上溢中断标志(清 CTRL1.OVERFLOW_IRQ,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AcknowledgeOverflowInterrupt() noexcept {
            InterfaceControlRegister::template ClearField<Registers::LCDIF::CTRL1::OVERFLOW_IRQ>();
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_LCDIF
