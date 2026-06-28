#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_GPMI
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_GPMI

/**
 * @file GPMI.hpp
 * @brief 通用多媒体存储接口(GPMI)驱动 —— NAND Flash 命令/地址/数据时序与 DMA/ECC 配置。
 *
 * STMP3770/i.MX23 的 GPMI 是 NAND 控制器:一次"命令"由 CTRL0 一次性描述(传输字节数、
 * 数据/命令锁存/地址锁存类型、片选、位宽、读写模式),写 CTRL0.RUN 启动;批量页数据经
 * APBH-DMA 描述符把 PIO 字写入 CTRL0、并以 PAYLOAD/AUXILIARY 指向数据/OOB 缓冲;集成 BCH
 * ECC 在 ECCCTRL/ECCCOUNT 配置。NAND 引脚时序(地址/数据建立保持)在 TIMING0,设备忙超时在 TIMING1。
 *
 * 一次命令的典型构成(CTRL0):
 *  - COMMAND_MODE:WRITE 发命令/地址、READ 读数据、WAIT_FOR_READY 等 R/B 就绪;
 *  - ADDRESS:NAND_CLE(命令锁存)/NAND_ALE(地址锁存)/NAND_DATA(数据);
 *  - XFER_COUNT:本次字节数;CS:片选;WORD_LENGTH:8/16 位。
 *
 * 本驱动是**控制器层**:暴露模块复位/门控、NAND 模式与时序配置、设备复位、单次命令发起
 * (IssueCommand 一次 RMW 配齐 CTRL0 并置 RUN)、PIO 数据端口、DMA 缓冲地址、BCH ECC 配置、
 * 状态与中断。命令完成只给 IsRunning() 谓词,**等待编排上移 OS**,本层不自旋。完整的页读写/
 * 坏块/地址周期编排属上层 NAND 驱动,不在此固化。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。
 *
 * @note 寄存器/字段取自生成头 Registers/GPMI.hpp,复位原语复用 Common::{AssertSoftReset,…}。
 *       CTRL0 的 SFTRST/CLKGATE/RUN 等为枚举字段;CLKGATE 的 RUN=0 表示供时钟、NO_CLKS=1 表示关断,
 *       故 EnableClock(清位)语义正确。CTRL1.DEV_RESET 为**反逻辑**:写 0(ENABLED)释放设备复位、
 *       写 1(DISABLED)使设备处于复位,见 AssertDeviceReset/DeassertDeviceReset。
 */

#include "Drivers/Common/ResetAndClockGate.hpp"
#include "Registers/GPMI.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    /** @brief 通用多媒体存储接口(GPMI)驱动:纯静态门面,无实例。 */
    struct GPMI {
        GPMI() = delete;
        ~GPMI() = delete;
        GPMI(const GPMI&) = delete;
        GPMI& operator=(const GPMI&) = delete;

    private:
        using ControlRegister0 = Registers::GPMI::CTRL0::Reg;       /**< 主控制寄存器(命令描述/RUN)。 */
        using ControlRegister1 = Registers::GPMI::CTRL1::Reg;       /**< 辅控制寄存器(模式/设备复位/中断)。 */
        using Timing0Register = Registers::GPMI::TIMING0::Reg;      /**< 引脚时序寄存器。 */
        using Timing1Register = Registers::GPMI::TIMING1::Reg;      /**< 设备忙超时寄存器。 */
        using DataRegister = Registers::GPMI::DATA::Reg;            /**< PIO 数据端口。 */
        using StatusRegister = Registers::GPMI::STAT::Reg;          /**< 状态寄存器(FIFO)。 */
        using PayloadRegister = Registers::GPMI::PAYLOAD::Reg;      /**< 主数据 DMA 地址寄存器。 */
        using AuxiliaryRegister = Registers::GPMI::AUXILIARY::Reg;  /**< 辅数据 DMA 地址寄存器。 */
        using EccControlRegister = Registers::GPMI::ECCCTRL::Reg;   /**< BCH ECC 控制寄存器。 */
        using EccCountRegister = Registers::GPMI::ECCCOUNT::Reg;    /**< ECC 字节数寄存器。 */

        using SoftReset = Registers::GPMI::CTRL0::SFTRST;  /**< CTRL0.SFTRST 字段后端。 */
        using ClockGate = Registers::GPMI::CTRL0::CLKGATE; /**< CTRL0.CLKGATE 字段后端。 */

    public:
        /** @brief 命令模式(CTRL0.COMMAND_MODE:WRITE / READ / READ_AND_COMPARE / WAIT_FOR_READY)。 */
        using CommandMode = Registers::GPMI::CTRL0::COMMAND_MODE_Values;
        /** @brief 地址锁存类型(CTRL0.ADDRESS:NAND_DATA / NAND_CLE / NAND_ALE)。 */
        using AddressType = Registers::GPMI::CTRL0::ADDRESS_Values;
        /** @brief 数据位宽(CTRL0.WORD_LENGTH:_8_BIT / _16_BIT)。 */
        using WordLength = Registers::GPMI::CTRL0::WORD_LENGTH_Values;
        /** @brief BCH ECC 命令(ECCCTRL.ECC_CMD:4/8 位编/解码)。 */
        using EccCommand = Registers::GPMI::ECCCTRL::ECC_CMD_Values;
        /** @brief ECC 缓冲掩码(ECCCTRL.BUFFER_MASK:BUFFER0–7 / BCH_PAGE / BCH_AUXONLY)。 */
        using EccBufferMask = Registers::GPMI::ECCCTRL::BUFFER_MASK_Values;

        // ====================== 模块级:复位 / 门控 ======================

        /** @brief 触发软复位:置 CTRL0.SFTRST(单条原子 str→SET)。 */
        [[gnu::always_inline]] static void AssertSoftReset() noexcept {
            Common::AssertSoftReset<SoftReset>();
        }

        /** @brief 退出软复位:清 CTRL0.SFTRST(单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DeassertSoftReset() noexcept {
            Common::DeassertSoftReset<SoftReset>();
        }

        /** @brief 非阻塞谓词:软复位是否仍被置位(CTRL0.SFTRST==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsSoftResetAsserted() noexcept {
            return Common::IsSoftResetAsserted<SoftReset>();
        }

        /** @brief 使能 GPMI 模块时钟(清 CTRL0.CLKGATE,即 RUN 态)。 */
        [[gnu::always_inline]] static void EnableClock() noexcept {
            Common::EnableClock<ClockGate>();
        }

        /** @brief 关断 GPMI 模块时钟(置 CTRL0.CLKGATE,即 NO_CLKS 态),用于低功耗。 */
        [[gnu::always_inline]] static void DisableClock() noexcept {
            Common::DisableClock<ClockGate>();
        }

        /** @brief 非阻塞谓词:模块时钟是否被门控(CTRL0.CLKGATE==1)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsClockGated() noexcept {
            return Common::IsClockGated<ClockGate>();
        }

        // ====================== NAND 模式与时序配置 ======================

        /** @brief 设为 NAND 模式(清 CTRL1.GPMI_MODE,NAND=0,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void SetNandMode() noexcept {
            ControlRegister1::template ClearField<Registers::GPMI::CTRL1::GPMI_MODE>();
        }

        /**
         * @brief 设置读数据采样延时(写 CTRL1.DSAMPLE_TIME,4 位,以 GPMI 时钟为单位)。
         * @param sampleDelay 采样延时周期数,用于补偿读路径时延。
         */
        [[gnu::always_inline]] static void SetReadSampleDelay(std::uint32_t sampleDelay) noexcept {
            ControlRegister1::template WriteField<Registers::GPMI::CTRL1::DSAMPLE_TIME>(sampleDelay);
        }

        /**
         * @brief 设置 NAND 引脚时序(写 TIMING0 的地址/数据建立与保持周期,一次 RMW)。
         * @param addressSetup 地址建立周期(ADDRESS_SETUP)。
         * @param dataSetup    数据建立周期(DATA_SETUP)。
         * @param dataHold     数据保持周期(DATA_HOLD)。
         */
        [[gnu::always_inline]] static void SetTimings(std::uint32_t addressSetup, std::uint32_t dataSetup,
                                                      std::uint32_t dataHold) noexcept {
            Timing0Register::template WriteFields<Registers::GPMI::TIMING0::ADDRESS_SETUP,
                                                  Registers::GPMI::TIMING0::DATA_SETUP,
                                                  Registers::GPMI::TIMING0::DATA_HOLD>(
                addressSetup, dataSetup, dataHold);
        }

        /**
         * @brief 设置设备忙等待超时(写 TIMING1.DEVICE_BUSY_TIMEOUT,16 位 GPMI 时钟周期)。
         * @param timeoutCycles 最大等待周期数。
         */
        [[gnu::always_inline]] static void SetDeviceBusyTimeout(std::uint32_t timeoutCycles) noexcept {
            Timing1Register::template WriteField<Registers::GPMI::TIMING1::DEVICE_BUSY_TIMEOUT>(timeoutCycles);
        }

        /**
         * @brief 使 NAND 设备进入复位(置 CTRL1.DEV_RESET=DISABLED=1,反逻辑,单条原子 str→SET)。
         * @note 厂商命名反直觉:DEV_RESET 写 1(DISABLED)才让设备处于复位态。
         */
        [[gnu::always_inline]] static void AssertDeviceReset() noexcept {
            ControlRegister1::template SetField<Registers::GPMI::CTRL1::DEV_RESET>();
        }

        /**
         * @brief 释放 NAND 设备复位(清 CTRL1.DEV_RESET=ENABLED=0,反逻辑,单条原子 str→CLR)。
         * @note 厂商命名反直觉:DEV_RESET 写 0(ENABLED)才让设备正常工作。
         */
        [[gnu::always_inline]] static void DeassertDeviceReset() noexcept {
            ControlRegister1::template ClearField<Registers::GPMI::CTRL1::DEV_RESET>();
        }

        // ====================== 单次命令发起(CTRL0) ======================

        /** @brief 一次命令的全部 CTRL0 参数(便于具名传参)。 */
        struct CommandOptions {
            CommandMode commandMode;                          /**< 命令模式(WRITE/READ/…)。 */
            AddressType addressType = AddressType::NAND_DATA; /**< 地址锁存类型(CLE/ALE/DATA)。 */
            std::uint32_t byteCount = 0u;                     /**< 传输字节数(XFER_COUNT,0 表示 65536)。 */
            std::uint32_t chipSelect = 0u;                    /**< 片选编号(CS,0–3)。 */
            WordLength wordLength = WordLength::_8_BIT;        /**< 数据位宽。 */
            bool lockChipSelect = false;                      /**< 是否锁定 CS 直到显式释放(LOCK_CS)。 */
            bool incrementAddress = false;                    /**< 是否每字后地址自增(ADDRESS_INCREMENT)。 */
        };

        /**
         * @brief 发起一次 NAND 命令:一次 RMW 把全部参数写入 CTRL0 并置 RUN 启动。
         *
         * 写入后硬件按 COMMAND_MODE 执行,完成后 CTRL0.RUN 自清(用 IsRunning() 谓词查询,
         * 等待编排上移 OS)。
         * @param options 命令参数。
         */
        [[gnu::always_inline]] static void IssueCommand(const CommandOptions& options) noexcept {
            ControlRegister0::template WriteFields<Registers::GPMI::CTRL0::XFER_COUNT,
                                                   Registers::GPMI::CTRL0::ADDRESS_INCREMENT,
                                                   Registers::GPMI::CTRL0::ADDRESS,
                                                   Registers::GPMI::CTRL0::CS,
                                                   Registers::GPMI::CTRL0::LOCK_CS,
                                                   Registers::GPMI::CTRL0::WORD_LENGTH,
                                                   Registers::GPMI::CTRL0::COMMAND_MODE,
                                                   Registers::GPMI::CTRL0::RUN>(
                options.byteCount,
                options.incrementAddress ? Registers::GPMI::CTRL0::ADDRESS_INCREMENT_Values::ENABLED
                                         : Registers::GPMI::CTRL0::ADDRESS_INCREMENT_Values::DISABLED,
                options.addressType, options.chipSelect,
                options.lockChipSelect ? Registers::GPMI::CTRL0::LOCK_CS_Values::ENABLED
                                       : Registers::GPMI::CTRL0::LOCK_CS_Values::DISABLED,
                options.wordLength, options.commandMode, Registers::GPMI::CTRL0::RUN_Values::BUSY);
        }

        /** @brief 非阻塞谓词:命令是否仍在执行(读 CTRL0.RUN);自清后返回 false 表示完成。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsRunning() noexcept {
            return ControlRegister0::template FieldIsSet<Registers::GPMI::CTRL0::RUN>();
        }

        // ====================== PIO 数据端口(DATA) ======================

        /**
         * @brief 经 APB 直接写一个 32 位数据字(写 DATA),用于非 DMA/调试路径。
         * @param word 数据字。
         */
        [[gnu::always_inline]] static void WriteData(std::uint32_t word) noexcept {
            DataRegister::Write(word);
        }

        /**
         * @brief 经 APB 直接读一个 32 位数据字(读 DATA)。
         * @return 读到的数据字。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadData() noexcept {
            return DataRegister::Read();
        }

        /** @brief 数据 FIFO 是否已满(读 STAT.FIFO_FULL)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsFifoFull() noexcept {
            return StatusRegister::template FieldIsSet<Registers::GPMI::STAT::FIFO_FULL>();
        }

        /** @brief 数据 FIFO 是否为空(读 STAT.FIFO_EMPTY)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsFifoEmpty() noexcept {
            return StatusRegister::template FieldIsSet<Registers::GPMI::STAT::FIFO_EMPTY>();
        }

        // ====================== DMA 缓冲地址(PAYLOAD / AUXILIARY) ======================

        /**
         * @brief 设置主数据(页数据区)DMA 缓冲物理地址(写 PAYLOAD)。
         * @param physicalAddress 4 字节对齐的物理地址(低 2 位被硬件忽略)。
         */
        [[gnu::always_inline]] static void SetPayloadAddress(std::uint32_t physicalAddress) noexcept {
            PayloadRegister::Write(physicalAddress);
        }

        /**
         * @brief 设置辅助数据(OOB/元数据)DMA 缓冲物理地址(写 AUXILIARY)。
         * @param physicalAddress 4 字节对齐的物理地址(低 2 位被硬件忽略)。
         */
        [[gnu::always_inline]] static void SetAuxiliaryAddress(std::uint32_t physicalAddress) noexcept {
            AuxiliaryRegister::Write(physicalAddress);
        }

        // ====================== BCH ECC(ECCCTRL / ECCCOUNT) ======================

        /**
         * @brief 配置 ECC 引擎命令与缓冲掩码(写 ECCCTRL 的 ECC_CMD/BUFFER_MASK,一次 RMW)。
         * @param eccCommand 编/解码命令(4/8 位)。
         * @param bufferMask 参与 ECC 的缓冲单元掩码。
         */
        [[gnu::always_inline]] static void ConfigureEcc(EccCommand eccCommand,
                                                        EccBufferMask bufferMask) noexcept {
            EccControlRegister::template WriteFields<Registers::GPMI::ECCCTRL::ECC_CMD,
                                                     Registers::GPMI::ECCCTRL::BUFFER_MASK>(
                eccCommand, bufferMask);
        }

        /**
         * @brief 设置 ECC 编解码字节数(写 ECCCOUNT.COUNT,0 表示 65536)。
         * @param byteCount 字节数。
         */
        [[gnu::always_inline]] static void SetEccCount(std::uint32_t byteCount) noexcept {
            EccCountRegister::template WriteField<Registers::GPMI::ECCCOUNT::COUNT>(byteCount);
        }

        /** @brief 使能 ECC 引擎(置 ECCCTRL.ENABLE_ECC,单条原子 str→SET)。 */
        [[gnu::always_inline]] static void EnableEcc() noexcept {
            EccControlRegister::template SetField<Registers::GPMI::ECCCTRL::ENABLE_ECC>();
        }

        /** @brief 关闭 ECC 引擎(清 ECCCTRL.ENABLE_ECC,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void DisableEcc() noexcept {
            EccControlRegister::template ClearField<Registers::GPMI::ECCCTRL::ENABLE_ECC>();
        }

        // ====================== 中断与设备状态 ======================

        /** @brief 使能设备就绪中断(置 CTRL0.DEV_IRQ_EN)。 */
        [[gnu::always_inline]] static void EnableDeviceInterrupt() noexcept {
            ControlRegister0::template SetField<Registers::GPMI::CTRL0::DEV_IRQ_EN>();
        }

        /** @brief 关闭设备就绪中断(清 CTRL0.DEV_IRQ_EN)。 */
        [[gnu::always_inline]] static void DisableDeviceInterrupt() noexcept {
            ControlRegister0::template ClearField<Registers::GPMI::CTRL0::DEV_IRQ_EN>();
        }

        /** @brief 设备就绪中断是否挂起(读 CTRL1.DEV_IRQ)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsDeviceInterruptPending() noexcept {
            return ControlRegister1::template FieldIsSet<Registers::GPMI::CTRL1::DEV_IRQ>();
        }

        /** @brief 清除设备就绪中断标志(清 CTRL1.DEV_IRQ,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AcknowledgeDeviceInterrupt() noexcept {
            ControlRegister1::template ClearField<Registers::GPMI::CTRL1::DEV_IRQ>();
        }

        /** @brief 设备忙超时中断是否挂起(读 CTRL1.TIMEOUT_IRQ)。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsTimeoutInterruptPending() noexcept {
            return ControlRegister1::template FieldIsSet<Registers::GPMI::CTRL1::TIMEOUT_IRQ>();
        }

        /** @brief 清除设备忙超时中断标志(清 CTRL1.TIMEOUT_IRQ,单条原子 str→CLR)。 */
        [[gnu::always_inline]] static void AcknowledgeTimeoutInterrupt() noexcept {
            ControlRegister1::template ClearField<Registers::GPMI::CTRL1::TIMEOUT_IRQ>();
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_GPMI
