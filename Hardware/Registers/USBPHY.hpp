#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_USBPHY
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_USBPHY

/**
 * @file USBPHY.hpp
 * @brief USBPHY 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * USB 2.0 收发 PHY 寄存器，包含电源关断、发送器/接收器控制、通用控制、状态、调试及 IP 版本等寄存器。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::USBPHY {

    /** @brief USB PHY 各路电源关断控制寄存器，写 0 上电、写 1 掉电。 */
    namespace PWD {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8007C000, 0x8007C004, 0x8007C008, 0x8007C00C, LowLevel::Access::ReadWrite>;
        using TXPWDFS = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 全速发送器掉电控制位，写 1 掉电、写 0 上电。 */
        using TXPWDIBIAS = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< 发送器偏置电流源掉电控制位，写 1 掉电、写 0 上电。 */
        using TXPWDV2I = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 发送器压流转换器掉电控制位，写 1 掉电、写 0 上电。 */
        using TXPWDVBG = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< 发送器带隙参考掉电控制位，写1掉电、写0上电。STMP3770中此位无功能。PDF标记为未使用。 */
        using TXPWDCOMP = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 发送器比较器掉电控制位，写1掉电、写0上电。此位不使用，应保持置位。PDF标记。 */
        using RXPWDENV = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< 接收器包络检测器掉电控制位，写 1 掉电、写 0 上电。 */
        using RXPWD1PT1 = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< 1.1V 接收器掉电控制位，写 1 掉电、写 0 上电。 */
        using RXPWDDIFF = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< 差分接收器掉电控制位，写 1 掉电、写 0 上电。 */
        using RXPWDRX = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< 整个接收器掉电控制位，写 1 掉电、写 0 上电。 */
    } // namespace PWD

    /** @brief USB PHY 发送器控制寄存器，负责驱动校准与端接电阻校准。 */
    namespace TX {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8007C010, 0x8007C014, 0x8007C018, 0x8007C01C, LowLevel::Access::ReadWrite>;
        using D_CAL = LowLevel::Field<Reg, 0, 4, std::uint32_t>; /**< D+/D- 输出驱动电流校准值，4 位无符号数。 */
        using TXCALIBRATE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 发送器校准控制位。此位不使用，必须保持清零。 */
        using TXCAL45DN = LowLevel::Field<Reg, 8, 4, std::uint32_t>; /**< D- 线 45Ω 端接电阻校准值，4 位无符号数。 */
        using TXENCAL45DN = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< D- 线 45Ω 端接电阻校准使能位，写 1 使能。 */
        using TXCAL45DP = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< D+ 线 45Ω 端接电阻校准值，4 位无符号数。 */
        using TXENCAL45DP = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< D+ 线 45Ω 端接电阻校准使能位，写 1 使能。 */
        using TXCMPOUT_STATUS = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< 发送器比较器输出状态，只读。此位不使用。 */
        using USBPHY_TX_SYNC_MUX = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 发送同步多路选择控制位。 */
        using USBPHY_TX_SYNC_INVERT = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< 发送同步信号反相控制位，写 1 反相。 */
        using USBPHY_TX_EDGECTRL = LowLevel::Field<Reg, 26, 3, std::uint32_t>; /**< 发送边沿控制字段，3 位数值，用于调整输出边沿速率。 */
    } // namespace TX

    /** @brief USB PHY 接收器控制寄存器，负责包络检测与断开检测阈值调整。 */
    namespace RX {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8007C020, 0x8007C024, 0x8007C028, 0x8007C02C, LowLevel::Access::ReadWrite>;
        using ENVADJ = LowLevel::Field<Reg, 0, 3, std::uint32_t>; /**< 接收器包络检测阈值调整值，3 位数值。 */
        using DISCONADJ = LowLevel::Field<Reg, 4, 3, std::uint32_t>; /**< 断开检测阈值调整值，3 位数值。 */
        using RXDBYPASS = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< 接收器数据旁路控制位，写 1 绕过同步/解码逻辑直接输出原始数据。 */
    } // namespace RX

    /** @brief USB PHY 通用控制寄存器，包含检测使能、中断、UTMI 挂起、时钟门控及软复位控制。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8007C030, 0x8007C034, 0x8007C038, 0x8007C03C, LowLevel::Access::ReadWrite>;
        using ENHOSTDISCONDETECT = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 主机断开检测使能位，写 1 使能 Host 模式下设备断开检测。 */
        using ENIRQHOSTDISCON = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< 主机断开中断使能位，写 1 允许主机断开事件触发中断。 */
        using HOSTDISCONDETECT_IRQ = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 主机断开中断状态位，写 1 清除中断标志。 */
        using ENDEVPLUGINDETECT = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< 设备插入检测使能位，写 1 使能设备插入检测。 */
        using DEVPLUGIN_POLARITY = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< 设备插入检测极性选择位。 */
        using ENOTGIDDETECT = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< OTG ID 检测使能位，写 1 使能 OTG ID 引脚状态检测。 */
        using ENIRQRESUMEDETECT = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 远程唤醒中断使能位，写 1 允许 USB 远程唤醒事件触发中断。 */
        using RESUME_IRQ = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 远程唤醒中断状态位，写 1 清除中断标志。 */
        using ENIRQDEVPLUGIN = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< 设备插入中断使能位，写 1 允许设备插入事件触发中断。 */
        using DEVPLUGIN_IRQ = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 设备插入中断状态位，写 1 清除中断标志。 */
        using DATA_ON_LRADC = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< LRADC 数据映射使能位，写 1 将 USB 数据信号映射到低分辨率 ADC 采样。 */
        using HOST_FORCE_LS_SE0 = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 主机强制低速 SE0 控制位，写 1 在 Host 模式下强制输出低速 SE0 状态。 */
        using UTMI_SUSPENDM = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< UTMI 挂起控制位，写 1 将 PHY 置于 UTMI 挂起状态。 */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 时钟门控控制位，写 1 关闭 USB PHY 时钟以节省功耗，写 0 解除门控。 */
        using SFTRST = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 软复位控制位，写 1 触发 USB PHY 软复位，写 0 释放复位。 */
    } // namespace CTRL

    /** @brief USB PHY 状态寄存器，只读，反映主机断开、设备插入、OTG ID 及远程唤醒等事件状态。 */
    namespace STATUS {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8007C040, LowLevel::Access::ReadOnly>;
        using HOSTDISCONDETECT_STATUS = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< 主机断开检测状态位，只读，1 表示 Host 模式下设备已断开。 */
        using DEVPLUGIN_STATUS = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 设备插入状态位，只读，1 表示检测到 USB 设备已插入。 */
        using OTGID_STATUS = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< OTG ID 状态位，只读，反映 OTG ID 引脚当前电平状态。 */
        using RESUME_STATUS = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 远程唤醒状态位，只读，1 表示检测到 USB 远程唤醒信号。 */
    } // namespace STATUS

    /** @brief USB PHY 调试寄存器，用于调试模式下控制 OTG ID 锁定、接口保持、主机下拉、发送转接收计数及静噪复位等功能。 */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8007C050, LowLevel::Access::ReadOnly>;
        using OTGIDPIOLOCK = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< OTG ID PIO 锁定控制位，写 1 锁定 OTG ID 状态到 PIO 采样值。 */
        using DEBUG_INTERFACE_HOLD = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 调试接口保持控制位，写 1 保持 UTMI 调试接口处于保持状态。 */
        using HSTPULLDOWN = LowLevel::Field<Reg, 2, 2, std::uint32_t>; /**< 主机下拉电阻控制字段，2 位数值，分别控制 D+/D- 线上的主机下拉电阻。 */
        using ENHSTPULLDOWN = LowLevel::Field<Reg, 4, 2, std::uint32_t>; /**< 主机下拉电阻使能字段，2 位数值，分别使能 D+/D- 线上的主机下拉电阻。 */
        using TX2RXCOUNT = LowLevel::Field<Reg, 8, 4, std::uint32_t>; /**< 发送转接收计数器阈值，4 位数值，定义发送完成后切换到接收模式的延迟计数值。 */
        using ENTX2RXCOUNT = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 发送转接收计数使能位，写 1 使能 TX2RXCOUNT 计数器功能。 */
        using SQUELCHRESETCOUNT = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< 静噪复位计数器阈值，5 位数值，定义检测到静噪后触发复位的计数值。 */
        using ENSQUELCHRESET = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< 静噪复位使能位，写 1 使能静噪检测复位功能。 */
        using SQUELCHRESETLENGTH = LowLevel::Field<Reg, 25, 4, std::uint32_t>; /**< 静噪复位脉冲长度，4 位数值，定义静噪复位信号的持续时间。 */
        using HOST_RESUME_DEBUG = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 主机恢复调试控制位，写 1 使能主机恢复调试模式。 */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 调试时钟门控控制位，写 1 关闭调试模块时钟，写 0 解除门控。 */
    } // namespace DEBUG

    /** @brief UTMI 调试状态寄存器 0，只读，反映环回测试、接收错误及静噪检测的计数状态。 */
    namespace DEBUG0_STATUS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8007C060, 0x8007C064, 0x8007C068, 0x8007C06C, LowLevel::Access::ReadWrite>;
        using LOOP_BACK_FAIL_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 环回测试失败计数，16 位数值，记录环回测试过程中失败的次数。 */
        using UTMI_RXERROR_FAIL_COUNT = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< UTMI 接收错误失败计数，10 位数值，记录 UTMI 接收错误检测的累计次数。 */
        using SQUELCH_COUNT = LowLevel::Field<Reg, 26, 6, std::uint32_t>; /**< 静噪计数，6 位数值，反映当前静噪检测器的状态计数值。 */
    } // namespace DEBUG0_STATUS

    /** @brief UTMI 调试寄存器 1，用于配置调试地址、发送环回及尾码调整电压等调试功能。 */
    namespace DEBUG1 {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8007C070, LowLevel::Access::ReadOnly>;
        using DBG_ADDRESS = LowLevel::Field<Reg, 0, 4, std::uint32_t>; /**< 调试地址字段，4 位数值，选择当前访问的 UTMI 内部调试寄存器地址。 */
        using ENTX2TX = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 发送环回使能位，写 1 使能发送器到发送器的内部环回路径。 */
        using ENTAILADJVD = LowLevel::Field<Reg, 13, 2, std::uint32_t>; /**< 尾码调整电压控制字段，2 位数值，用于调整发送器尾码电流的电压偏置。 */
    } // namespace DEBUG1

    /** @brief UTMI RTL 版本寄存器，只读，反映当前 USB PHY IP 的 RTL 版本号。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x8007C080, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 步进版本号，16 位数值，表示 RTL 的步进版本。 */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 次版本号，8 位数值，表示 RTL 的次要版本。 */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< 主版本号，8 位数值，表示 RTL 的主要版本。 */
    } // namespace VERSION

    /** @brief USB PHY IP 块控制寄存器，包含 PLL 电源、USB 时钟使能、模拟测试模式及 PLL 环路参数选择。 */
    namespace IP {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8007C090, 0x8007C094, 0x8007C098, 0x8007C09C, LowLevel::Access::ReadWrite>;
        using PLL_POWER = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< PLL 电源控制位，写 1 为 USB PHY PLL 上电，写 0 掉电。 */
        using PLL_LOCKED = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< PLL 锁定状态位，只读，1 表示 USB PHY PLL 已锁定。 */
        using EN_USB_CLKS = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< USB 时钟使能位，写 1 使能 USB PHY 内部时钟输出到控制器。 */
        using ANALOG_TESTMODE = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< 模拟测试模式使能位，写 1 使能 USB PHY 模拟电路测试模式。 */
        using TSTI_TX_DM = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< 模拟测试输入 D- 控制位，写 1 将测试信号驱动到 D- 线。 */
        using TSTI_TX_DP = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< 模拟测试输入 D+ 控制位，写 1 将测试信号驱动到 D+ 线。 */
        /** @brief CP_SEL 的取值。 */
        enum class CP_SEL_Values : std::uint32_t {
            DEFAULT = 0x0,
            TIMES_2 = 0x1,
            TIMES_05 = 0x2,
            UNDEFINED = 0x3,
        };
        using CP_SEL = LowLevel::Field<Reg, 19, 2, CP_SEL_Values>; /**< 电荷泵电流选择字段，2 位枚举：DEFAULT(默认)、TIMES_2(2 倍)、TIMES_05(0.5 倍)、UNDEFINED(未定义)。 */
        /** @brief LFR_SEL 的取值。 */
        enum class LFR_SEL_Values : std::uint32_t {
            DEFAULT = 0x0,
            TIMES_2 = 0x1,
            TIMES_05 = 0x2,
            UNDEFINED = 0x3,
        };
        using LFR_SEL = LowLevel::Field<Reg, 21, 2, LFR_SEL_Values>; /**< 环路滤波电阻选择字段，2 位枚举：DEFAULT(默认)、TIMES_2(2 倍)、TIMES_05(0.5 倍)、UNDEFINED(未定义)。 */
        /** @brief DIV_SEL 的取值。 */
        enum class DIV_SEL_Values : std::uint32_t {
            DEFAULT = 0x0,
            LOWER = 0x1,
            LOWEST = 0x2,
            UNDEFINED = 0x3,
        };
        using DIV_SEL = LowLevel::Field<Reg, 23, 2, DIV_SEL_Values>; /**< PLL 分频比选择字段，2 位枚举：DEFAULT(默认)、LOWER(较低)、LOWEST(最低)、UNDEFINED(未定义)。 */
    } // namespace IP

} // namespace Hardware::Registers::USBPHY

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_USBPHY
