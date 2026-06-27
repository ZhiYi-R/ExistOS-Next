#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_APBX
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_APBX

/**
 * @file APBX.hpp
 * @brief APBX 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * AHB-to-APBX 桥 DMA 控制器(为音频、UARTAPP、I2C、LRADC 等低速外设提供 DMA 通道)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::APBX {

    /** @brief AHB to APBX Bridge Control Register 0 */
    namespace CTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80024000, 0x80024004, 0x80024008, 0x8002400C, LowLevel::Access::ReadWrite>;
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 时钟门控控制位，写1关闭模块时钟以节省功耗，配置状态保持。写0恢复正常时钟供应。 */
        using SFTRST = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 软复位控制位，写1复位本模块，写0恢复正常运行。复位后所有寄存器回到默认值。 */
    } // namespace CTRL0

    /** @brief AHB to APBX Bridge Control Register 1 */
    namespace CTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80024010, 0x80024014, 0x80024018, 0x8002401C, LowLevel::Access::ReadWrite>;
        using CH0_CMDCMPLT_IRQ = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Ch0 Cmdcmplt Irq，1位读写字段。 */
        using CH1_CMDCMPLT_IRQ = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< Ch1 Cmdcmplt Irq，1位读写字段。 */
        using CH2_CMDCMPLT_IRQ = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Ch2 Cmdcmplt Irq，1位读写字段。 */
        using CH3_CMDCMPLT_IRQ = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Ch3 Cmdcmplt Irq，1位读写字段。 */
        using CH4_CMDCMPLT_IRQ = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< Ch4 Cmdcmplt Irq，1位读写字段。 */
        using CH5_CMDCMPLT_IRQ = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< Ch5 Cmdcmplt Irq，1位读写字段。 */
        using CH6_CMDCMPLT_IRQ = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< Ch6 Cmdcmplt Irq，1位读写字段。 */
        using CH7_CMDCMPLT_IRQ = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< Ch7 Cmdcmplt Irq，1位读写字段。 */
        using CH8_CMDCMPLT_IRQ = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Ch8 Cmdcmplt Irq，1位读写字段。 */
        using CH9_CMDCMPLT_IRQ = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Ch9 Cmdcmplt Irq，1位读写字段。 */
        using CH10_CMDCMPLT_IRQ = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< Ch10 Cmdcmplt Irq，1位读写字段。 */
        using CH11_CMDCMPLT_IRQ = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< Ch11 Cmdcmplt Irq，1位读写字段。 */
        using CH12_CMDCMPLT_IRQ = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< Ch12 Cmdcmplt Irq，1位读写字段。 */
        using CH13_CMDCMPLT_IRQ = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< Ch13 Cmdcmplt Irq，1位读写字段。 */
        using CH14_CMDCMPLT_IRQ = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< Ch14 Cmdcmplt Irq，1位读写字段。 */
        using CH15_CMDCMPLT_IRQ = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< Ch15 Cmdcmplt Irq，1位读写字段。 */
        using CH0_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< Ch0 Cmdcmplt Irq En，1位读写字段。 */
        using CH1_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< Ch1 Cmdcmplt Irq En，1位读写字段。 */
        using CH2_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< Ch2 Cmdcmplt Irq En，1位读写字段。 */
        using CH3_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< Ch3 Cmdcmplt Irq En，1位读写字段。 */
        using CH4_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< Ch4 Cmdcmplt Irq En，1位读写字段。 */
        using CH5_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< Ch5 Cmdcmplt Irq En，1位读写字段。 */
        using CH6_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< Ch6 Cmdcmplt Irq En，1位读写字段。 */
        using CH7_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< Ch7 Cmdcmplt Irq En，1位读写字段。 */
        using CH8_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< Ch8 Cmdcmplt Irq En，1位读写字段。 */
        using CH9_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< Ch9 Cmdcmplt Irq En，1位读写字段。 */
        using CH10_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< Ch10 Cmdcmplt Irq En，1位读写字段。 */
        using CH11_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< Ch11 Cmdcmplt Irq En，1位读写字段。 */
        using CH12_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< Ch12 Cmdcmplt Irq En，1位读写字段。 */
        using CH13_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< Ch13 Cmdcmplt Irq En，1位读写字段。 */
        using CH14_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< Ch14 Cmdcmplt Irq En，1位读写字段。 */
        using CH15_CMDCMPLT_IRQ_EN = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< Ch15 Cmdcmplt Irq En，1位读写字段。 */
    } // namespace CTRL1

    /** @brief AHB to APBX Bridge Control and Status Register 2 */
    namespace CTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80024020, 0x80024024, 0x80024028, 0x8002402C, LowLevel::Access::ReadWrite>;
        using CH0_ERROR_IRQ = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Ch0 Error Irq，1位读写字段。 */
        using CH1_ERROR_IRQ = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< Ch1 Error Irq，1位读写字段。 */
        using CH2_ERROR_IRQ = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Ch2 Error Irq，1位读写字段。 */
        using CH3_ERROR_IRQ = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Ch3 Error Irq，1位读写字段。 */
        using CH4_ERROR_IRQ = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< Ch4 Error Irq，1位读写字段。 */
        using CH5_ERROR_IRQ = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< Ch5 Error Irq，1位读写字段。 */
        using CH6_ERROR_IRQ = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< Ch6 Error Irq，1位读写字段。 */
        using CH7_ERROR_IRQ = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< Ch7 Error Irq，1位读写字段。 */
        using CH8_ERROR_IRQ = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Ch8 Error Irq，1位读写字段。 */
        using CH9_ERROR_IRQ = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Ch9 Error Irq，1位读写字段。 */
        using CH10_ERROR_IRQ = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< Ch10 Error Irq，1位读写字段。 */
        using CH11_ERROR_IRQ = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< Ch11 Error Irq，1位读写字段。 */
        using CH12_ERROR_IRQ = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< Ch12 Error Irq，1位读写字段。 */
        using CH13_ERROR_IRQ = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< Ch13 Error Irq，1位读写字段。 */
        using CH14_ERROR_IRQ = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< Ch14 Error Irq，1位读写字段。 */
        using CH15_ERROR_IRQ = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< Ch15 Error Irq，1位读写字段。 */
        /** @brief CH0_ERROR_STATUS 的取值。 */
        enum class CH0_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH0_ERROR_STATUS = LowLevel::Field<Reg, 16, 1, CH0_ERROR_STATUS_Values>; /**< Ch0 Error Status，1位读写字段。 */
        /** @brief CH1_ERROR_STATUS 的取值。 */
        enum class CH1_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH1_ERROR_STATUS = LowLevel::Field<Reg, 17, 1, CH1_ERROR_STATUS_Values>; /**< Ch1 Error Status，1位读写字段。 */
        /** @brief CH2_ERROR_STATUS 的取值。 */
        enum class CH2_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH2_ERROR_STATUS = LowLevel::Field<Reg, 18, 1, CH2_ERROR_STATUS_Values>; /**< Ch2 Error Status，1位读写字段。 */
        /** @brief CH3_ERROR_STATUS 的取值。 */
        enum class CH3_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH3_ERROR_STATUS = LowLevel::Field<Reg, 19, 1, CH3_ERROR_STATUS_Values>; /**< Ch3 Error Status，1位读写字段。 */
        /** @brief CH4_ERROR_STATUS 的取值。 */
        enum class CH4_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH4_ERROR_STATUS = LowLevel::Field<Reg, 20, 1, CH4_ERROR_STATUS_Values>; /**< Ch4 Error Status，1位读写字段。 */
        /** @brief CH5_ERROR_STATUS 的取值。 */
        enum class CH5_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH5_ERROR_STATUS = LowLevel::Field<Reg, 21, 1, CH5_ERROR_STATUS_Values>; /**< Ch5 Error Status，1位读写字段。 */
        /** @brief CH6_ERROR_STATUS 的取值。 */
        enum class CH6_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH6_ERROR_STATUS = LowLevel::Field<Reg, 22, 1, CH6_ERROR_STATUS_Values>; /**< Ch6 Error Status，1位读写字段。 */
        /** @brief CH7_ERROR_STATUS 的取值。 */
        enum class CH7_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH7_ERROR_STATUS = LowLevel::Field<Reg, 23, 1, CH7_ERROR_STATUS_Values>; /**< Ch7 Error Status，1位读写字段。 */
        /** @brief CH8_ERROR_STATUS 的取值。 */
        enum class CH8_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH8_ERROR_STATUS = LowLevel::Field<Reg, 24, 1, CH8_ERROR_STATUS_Values>; /**< Ch8 Error Status，1位读写字段。 */
        /** @brief CH9_ERROR_STATUS 的取值。 */
        enum class CH9_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH9_ERROR_STATUS = LowLevel::Field<Reg, 25, 1, CH9_ERROR_STATUS_Values>; /**< Ch9 Error Status，1位读写字段。 */
        /** @brief CH10_ERROR_STATUS 的取值。 */
        enum class CH10_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH10_ERROR_STATUS = LowLevel::Field<Reg, 26, 1, CH10_ERROR_STATUS_Values>; /**< Ch10 Error Status，1位读写字段。 */
        /** @brief CH11_ERROR_STATUS 的取值。 */
        enum class CH11_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH11_ERROR_STATUS = LowLevel::Field<Reg, 27, 1, CH11_ERROR_STATUS_Values>; /**< Ch11 Error Status，1位读写字段。 */
        /** @brief CH12_ERROR_STATUS 的取值。 */
        enum class CH12_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH12_ERROR_STATUS = LowLevel::Field<Reg, 28, 1, CH12_ERROR_STATUS_Values>; /**< Ch12 Error Status，1位读写字段。 */
        /** @brief CH13_ERROR_STATUS 的取值。 */
        enum class CH13_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH13_ERROR_STATUS = LowLevel::Field<Reg, 29, 1, CH13_ERROR_STATUS_Values>; /**< Ch13 Error Status，1位读写字段。 */
        /** @brief CH14_ERROR_STATUS 的取值。 */
        enum class CH14_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH14_ERROR_STATUS = LowLevel::Field<Reg, 30, 1, CH14_ERROR_STATUS_Values>; /**< Ch14 Error Status，1位读写字段。 */
        /** @brief CH15_ERROR_STATUS 的取值。 */
        enum class CH15_ERROR_STATUS_Values : std::uint32_t {
            TERMINATION = 0x0,
            BUS_ERROR = 0x1,
        };
        using CH15_ERROR_STATUS = LowLevel::Field<Reg, 31, 1, CH15_ERROR_STATUS_Values>; /**< Ch15 Error Status，1位读写字段。 */
    } // namespace CTRL2

    /** @brief AHB to APBX Bridge Channel Register */
    namespace CHANNEL_CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80024030, 0x80024034, 0x80024038, 0x8002403C, LowLevel::Access::ReadWrite>;
        /** @brief FREEZE_CHANNEL 的取值。 */
        enum class FREEZE_CHANNEL_Values : std::uint32_t {
            AUDIOIN = 0x1,
            AUDIOOUT = 0x2,
            SPDIF_TX = 0x4,
            I2C = 0x8,
            SAIF1 = 0x10,
            DRI = 0x20,
            IRDA_RX = 0x40,
            IRDA_TX = 0x80,
            UART1_RX = 0x100,
            UART1_TX = 0x200,
            SAIF2 = 0x400,
        };
        using FREEZE_CHANNEL = LowLevel::Field<Reg, 0, 16, FREEZE_CHANNEL_Values>; /**< Freeze Channel，16位读写字段。 */
        /** @brief RESET_CHANNEL 的取值。 */
        enum class RESET_CHANNEL_Values : std::uint32_t {
            AUDIOIN = 0x1,
            AUDIOOUT = 0x2,
            SPDIF_TX = 0x4,
            I2C = 0x8,
            SAIF1 = 0x10,
            DRI = 0x20,
            IRDA_RX = 0x40,
            IRDA_TX = 0x80,
            UART1_RX = 0x100,
            UART1_TX = 0x200,
            SAIF2 = 0x400,
        };
        using RESET_CHANNEL = LowLevel::Field<Reg, 16, 16, RESET_CHANNEL_Values>; /**< Reset Channel，16位读写字段。 */
    } // namespace CHANNEL_CTRL

    /** @brief AHB to APBX DMA Device Assignment Register */
    namespace DEVSEL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80024040, 0x80024044, 0x80024048, 0x8002404C, LowLevel::Access::ReadWrite>;
        using CH0 = LowLevel::Field<Reg, 0, 2, std::uint32_t>; /**< Ch0，2位读写字段。 */
        using CH1 = LowLevel::Field<Reg, 2, 2, std::uint32_t>; /**< Ch1，2位读写字段。 */
        using CH2 = LowLevel::Field<Reg, 4, 2, std::uint32_t>; /**< Ch2，2位读写字段。 */
        using CH3 = LowLevel::Field<Reg, 6, 2, std::uint32_t>; /**< Ch3，2位读写字段。 */
        using CH4 = LowLevel::Field<Reg, 8, 2, std::uint32_t>; /**< Ch4，2位读写字段。 */
        using CH5 = LowLevel::Field<Reg, 10, 2, std::uint32_t>; /**< Ch5，2位读写字段。 */
        /** @brief CH6 的取值。 */
        enum class CH6_Values : std::uint32_t {
            USE_SAIF1 = 0x0,
            USE_IRDA = 0x1,
        };
        using CH6 = LowLevel::Field<Reg, 12, 2, CH6_Values>; /**< Ch6，2位读写字段。 */
        /** @brief CH7 的取值。 */
        enum class CH7_Values : std::uint32_t {
            USE_I2C1 = 0x0,
            USE_IRDA = 0x1,
        };
        using CH7 = LowLevel::Field<Reg, 14, 2, CH7_Values>; /**< Ch7，2位读写字段。 */
        using CH8 = LowLevel::Field<Reg, 16, 2, std::uint32_t>; /**< Ch8，2位读写字段。 */
        using CH9 = LowLevel::Field<Reg, 18, 2, std::uint32_t>; /**< Ch9，2位读写字段。 */
        using CH10 = LowLevel::Field<Reg, 20, 2, std::uint32_t>; /**< Ch10，2位读写字段。 */
        using CH11 = LowLevel::Field<Reg, 22, 2, std::uint32_t>; /**< Ch11，2位读写字段。 */
        using CH12 = LowLevel::Field<Reg, 24, 2, std::uint32_t>; /**< Ch12，2位读写字段。 */
        using CH13 = LowLevel::Field<Reg, 26, 2, std::uint32_t>; /**< Ch13，2位读写字段。 */
        using CH14 = LowLevel::Field<Reg, 28, 2, std::uint32_t>; /**< Ch14，2位读写字段。 */
        using CH15 = LowLevel::Field<Reg, 30, 2, std::uint32_t>; /**< Ch15，2位读写字段。 */
    } // namespace DEVSEL

    /** @brief APBX Bridge Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80024800, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< Step，16位读写字段。 */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Minor，8位读写字段。 */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Major，8位读写字段。 */
    } // namespace VERSION

} // namespace Hardware::Registers::APBX

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_APBX
