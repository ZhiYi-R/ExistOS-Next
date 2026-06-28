#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_POWER
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_POWER

/**
 * @file POWER.hpp
 * @brief POWER 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 电源管理单元(POWER)寄存器与位域中文描述。涵盖电源控制、5V控制、低功耗、电池充电、各电源域(VDDD/VDDA/VDDIO)控制、DC-DC多输出转换、占空比限制、反馈环路、状态、晶体管速度、电池监测、复位、调试、测试及版本寄存器。注：VDD5V_DROOP(64)和DCDC4P2_BO(65)为POWER模块内部中断，不路由至ICOLL。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::POWER {

    /** @brief 电源控制寄存器，集中管理各电源事件的中断使能、中断状态、极性配置及模块时钟门控。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044000, 0x80044004, 0x80044008, 0x8004400C, LowLevel::Access::ReadWrite>;
        using ENIRQ_VDD5V_GT_VDDIO = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< VDD5V 高于 VDDIO 中断使能。 */
        using VDD5V_GT_VDDIO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< VDD5V 高于 VDDIO 中断状态(写1清零)。 */
        using POLARITY_VDD5V_GT_VDDIO = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< VDD5V 高于 VDDIO 中断极性选择。 */
        using ENIRQ_VBUS_VALID = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< VBUS 有效中断使能。 */
        using VBUSVALID_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< VBUS 有效中断状态(写1清零)。 */
        using POLARITY_VBUSVALID = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< VBUS 有效中断极性选择。 */
        using ENIRQ_VDDD_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< VDDD 欠压中断使能。 */
        using VDDD_BO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< VDDD 欠压中断状态(写1清零)。 */
        using ENIRQ_VDDA_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< VDDA 欠压中断使能。 */
        using VDDA_BO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< VDDA 欠压中断状态(写1清零)。 */
        using ENIRQ_VDDIO_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< VDDIO 欠压中断使能。 */
        using VDDIO_BO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< VDDIO 欠压中断状态(写1清零)。 */
        using ENIRQBATT_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< 电池欠压中断使能。 */
        using BATT_BO_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< 电池欠压中断状态(写1清零)。 */
        using ENIRQ_DC_OK = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< DC-DC 正常中断使能。 */
        using DC_OK_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< DC-DC 正常中断状态(写1清零)。 */
        using ENIRQ_LINREG_OK = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 线性稳压器正常中断使能。 */
        using LINREG_OK_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 线性稳压器正常中断状态(写1清零)。 */
        using POLARITY_LINREG_OK = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< 线性稳压器正常中断极性选择。 */
        using ENIRQ_PSWITCH = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< PSWITCH 中断使能。 */
        using POLARITY_PSWITCH = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< PSWITCH 中断极性选择。 */
        using PSWITCH_IRQ_SRC = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< PSWITCH 中断源选择。 */
        using PSWITCH_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< PSWITCH 中断状态(写1清零)。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< POWER 模块时钟门控，置1关闭时钟以节能。 */
    } // namespace CTRL

    /** @brief DC-DC 5V 控制寄存器，管理 DCDC 使能、VBUS 检测、电流限制及 5V 欠压保护。 */
    namespace _5VCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044010, 0x80044014, 0x80044018, 0x8004401C, LowLevel::Access::ReadWrite>;
        using ENABLE_DCDC = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 使能 DC-DC 转换器。 */
        using OTG_PWRUP_CMPS = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< OTG 比较器上电控制。 */
        using ILIMIT_EQ_ZERO = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 电流限制置零。 */
        using VBUSVALID_TO_B = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< VBUS 有效信号路由到 B 端。 */
        using VBUSVALID_5VDETECT = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< VBUS 有效检测来自 5V 检测电路。 */
        using EN_BATT_PULLDN = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 使能电池下拉。 */
        using DCDC_XFER = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< DC-DC 转换模式切换。 */
        using ENABLE_ILIMIT = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 使能电流限制功能。 */
        using PWDN_5VBRNOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 5V 欠压掉电控制。 */
        using VBUSVALID_TRSH = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< VBUS 有效检测阈值选择。 */
    } // namespace _5VCTRL

    /** @brief DC-DC 最小功耗及杂项控制寄存器，用于降低功耗、控制振荡器及 FET 驱动。 */
    namespace MINPWR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044020, 0x80044024, 0x80044028, 0x8004402C, LowLevel::Access::ReadWrite>;
        using DC_HALFCLK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< DC-DC 时钟减半以降低功耗。 */
        using EN_DC_PFM = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 使能 DC-DC PFM(脉冲频率调制)模式。 */
        using DC_STOPCLK = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 停止 DC-DC 时钟。 */
        using PWD_XTAL24 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 24MHz 晶振掉电控制。 */
        using LESSANA_I = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 减小模拟偏置电流。 */
        using HALF_FETS = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< FET 驱动能力减半。 */
        using DOUBLE_FETS = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< FET 驱动能力加倍。 */
        using VBG_OFF = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< 带隙基准关闭。 */
        using SELECT_OSC = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< 选择内部振荡器作为 DC-DC 时钟源。 */
        using ENABLE_OSC = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< 使能内部振荡器。 */
        using USB_I_SUSPENDED = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< USB 挂起电流控制。 */
        using PWD_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< 欠压检测电路掉电。 */
    } // namespace MINPWR

    /** @brief 电池充电控制寄存器，配置充电电流、终止电流及故障检测。 */
    namespace CHARGE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044030, 0x80044034, 0x80044038, 0x8004403C, LowLevel::Access::ReadWrite>;
        using BATTCHRG_I = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 6, std::uint32_t>; /**< 电池充电电流设置值。 */
        using STOP_ILIMIT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< 充电终止电流阈值。 */
        using PWD_BATTCHRG = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 电池充电电路掉电。 */
        using USE_EXTERN_R = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 使用外部电阻设置充电电流。 */
        using CHRG_STS_OFF = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< 关闭充电状态指示。 */
        using ENABLE_FAULT_DETECT = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 使能充电故障检测。 */
    } // namespace CHARGE

    /** @brief VDDD 电源域目标电压与欠压控制寄存器。 */
    namespace VDDDCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044040, 0x80044044, 0x80044048, 0x8004404C, LowLevel::Access::ReadWrite>;
        using TRG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< VDDD 目标电压档位设置。 */
        using BO_OFFSET = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< VDDD 欠压门限偏移量。 */
        using LINREG_OFFSET = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< VDDD 线性稳压器偏移量。 */
        using DISABLE_FET = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 禁用 VDDD 外部 FET。 */
        using ENABLE_LINREG = LowLevel::Field<Reg, LowLevel::Bit::Bit21, 1, std::uint32_t>; /**< 使能 VDDD 线性稳压器。 */
        using LINREG_FROM_BATT = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< VDDD 线性稳压器由电池供电。 */
        using DISABLE_STEPPING = LowLevel::Field<Reg, LowLevel::Bit::Bit23, 1, std::uint32_t>; /**< 禁用 VDDD 电压步进调节。 */
        using ALKALINE_CHARGE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 碱性电池充电模式。 */
        using ADJTN = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 4, std::uint32_t>; /**< VDDD 调整值。 */
    } // namespace VDDDCTRL

    /** @brief VDDA 电源域目标电压与欠压控制寄存器。 */
    namespace VDDACTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044050, 0x80044054, 0x80044058, 0x8004405C, LowLevel::Access::ReadWrite>;
        using TRG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< VDDA 目标电压档位设置。 */
        using BO_OFFSET = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< VDDA 欠压门限偏移量。 */
        using LINREG_OFFSET = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< VDDA 线性稳压器偏移量。 */
        using DISABLE_FET = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 禁用 VDDA 外部 FET。 */
        using ENABLE_LINREG = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 使能 VDDA 线性稳压器。 */
        using DISABLE_STEPPING = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< 禁用 VDDA 电压步进调节。 */
    } // namespace VDDACTRL

    /** @brief VDDIO 电源域目标电压与欠压控制寄存器。 */
    namespace VDDIOCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044060, 0x80044064, 0x80044068, 0x8004406C, LowLevel::Access::ReadWrite>;
        using TRG = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 5, std::uint32_t>; /**< VDDIO 目标电压档位设置。 */
        using BO_OFFSET = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< VDDIO 欠压门限偏移量。 */
        using LINREG_OFFSET = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< VDDIO 线性稳压器偏移量。 */
        using DISABLE_FET = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< 禁用 VDDIO 外部 FET。 */
        using DISABLE_STEPPING = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< 禁用 VDDIO 电压步进调节。 */
        using ADJTN = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 4, std::uint32_t>; /**< VDDIO 调整值。 */
    } // namespace VDDIOCTRL

    /** @brief DC-DC 多输出转换器模式控制寄存器，设置 VDDIO 与 VDDD 转换值。 */
    namespace DCFUNCV {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044070, 0x80044074, 0x80044078, 0x8004407C, LowLevel::Access::ReadWrite>;
        using VDDIO = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 10, std::uint32_t>; /**< VDDIO 转换目标值。 */
        using VDDD = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 10, std::uint32_t>; /**< VDDD 转换目标值。 */
    } // namespace DCFUNCV

    /** @brief DC-DC 杂项控制寄存器，含外设开关、PLL 时钟选择及测试模式。 */
    namespace MISC {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044080, 0x80044084, 0x80044088, 0x8004408C, LowLevel::Access::ReadWrite>;
        using PERIPHERALSWOFF = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 外设电源开关关闭。 */
        using SEL_PLLCLK = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 选择 PLL 时钟作为 DC-DC 时钟源。 */
        using TEST = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< 测试模式使能。 */
        using DELAY_TIMING = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< 延迟时序控制。 */
        using FREQSEL = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< DC-DC 频率选择。 */
    } // namespace MISC

    /** @brief DC-DC 占空比限制控制寄存器，设置负限、Buck 正限及 Boost 正限。 */
    namespace DCLIMITS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044090, 0x80044094, 0x80044098, 0x8004409C, LowLevel::Access::ReadWrite>;
        using NEGLIMIT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 7, std::uint32_t>; /**< 负占空比限制值。 */
        using POSLIMIT_BUCK = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 7, std::uint32_t>; /**< Buck 模式正占空比限制值。 */
        using POSLIMIT_BOOST = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 7, std::uint32_t>; /**< Boost 模式正占空比限制值。 */
    } // namespace DCLIMITS

    /** @brief 转换器反馈环路行为控制寄存器，调整环路补偿与滞环参数。 */
    namespace LOOPCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800440A0, 0x800440A4, 0x800440A8, 0x800440AC, LowLevel::Access::ReadWrite>;
        using DC_C = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 环路电容补偿系数。 */
        using DC_R = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, std::uint32_t>; /**< 环路电阻补偿系数。 */
        using DC_FF = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< 前馈补偿系数。 */
        using EN_RCSCALE = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< RC 缩放使能控制。 */
        using RCSCALE_THRESH = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< RC 缩放阈值。 */
        using DF_HYST_THRESH = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< 差分滞环阈值。 */
        using CM_HYST_THRESH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< 共模滞环阈值。 */
        using EN_DF_HYST = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< 差分滞环使能。 */
        using EN_CM_HYST = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< 共模滞环使能。 */
        using HYST_SIGN = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< 滞环符号选择。 */
        using TOGGLE_DIF = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< 差分信号翻转。 */
    } // namespace LOOPCTRL

    /** @brief 电源子系统状态寄存器，反映各电源事件、USB 会话及 PSWITCH 的实时状态。 */
    namespace STS {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800440B0, 0x800440B4, 0x800440B8, 0x800440BC, LowLevel::Access::ReadWrite>;
        using SESSEND = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< USB 会话结束状态。 */
        using VBUSVALID = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< VBUS 有效状态。 */
        using BVALID = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< B 设备有效状态。 */
        using AVALID = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< A 设备有效状态。 */
        using VDD5V_GT_VDDIO = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< VDD5V 高于 VDDIO 状态。 */
        using VDDD_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< VDDD 欠压状态。 */
        using VDDA_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< VDDA 欠压状态。 */
        using VDDIO_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< VDDIO 欠压状态。 */
        using DC_OK = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< DC-DC 正常状态。 */
        using LINREG_OK = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< 线性稳压器正常状态。 */
        using CHRGSTS = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< 充电状态指示。 */
        using VDD5V_FAULT = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< VDD5V 故障状态。 */
        using BATT_BO = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< 电池欠压状态。 */
        using MODE = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< 电源工作模式指示。 */
        using SESSEND_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< USB 会话结束状态(经滤波)。 */
        using VBUSVALID_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< VBUS 有效状态(经滤波)。 */
        using BVALID_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< B 设备有效状态(经滤波)。 */
        using AVALID_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< A 设备有效状态(经滤波)。 */
        using PSWITCH = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< PSWITCH 按键状态。 */
        using BATT_CHRG_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 电池充电器存在标志。 */
    } // namespace STS

    /** @brief 晶体管速度控制与状态寄存器。 */
    namespace SPEED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800440C0, 0x800440C4, 0x800440C8, 0x800440CC, LowLevel::Access::ReadWrite>;
        using CTRL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< 晶体管速度控制值。 */
        using STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 晶体管速度状态回读值。 */
    } // namespace SPEED

    /** @brief 电池电压监测寄存器，用于读取电池电压值及配置电池欠压参数。 */
    namespace BATTMONITOR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800440D0, 0x800440D4, 0x800440D8, 0x800440DC, LowLevel::Access::ReadWrite>;
        using BRWNOUT_LVL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 4, std::uint32_t>; /**< 电池欠压检测电平设置。 */
        using BRWNOUT_PWD = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< 电池欠压检测电路掉电。 */
        using PWDN_BATTBRNOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< 电池欠压掉电控制。 */
        using EN_BATADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< 使能电池电压调整。 */
        using BATT_VAL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 10, std::uint32_t>; /**< 电池电压 ADC 采样值(由固件读取)。 */
    } // namespace BATTMONITOR

    /** @brief 电源模块复位寄存器，需写入解锁密钥后方可操作复位。 */
    namespace RESET {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800440E0, 0x800440E4, 0x800440E8, 0x800440EC, LowLevel::Access::ReadWrite>;
        using PWD = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< 电源模块复位请求。 */
        using PWD_OFF = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< 关闭电源模块复位。 */
        /** @brief UNLOCK 的取值。 */
        enum class UNLOCK_Values : std::uint32_t {
            KEY = 0x3E77,
        };
        using UNLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, UNLOCK_Values>; /**< 解锁密钥，写入 0x3E77 后方可修改复位位。 */
    } // namespace RESET

    /** @brief 电源模块调试寄存器，用于锁定 USB 会话相关 PIO 信号。 */
    namespace DEBUG {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800440F0, LowLevel::Access::ReadOnly>;
        using SESSENDPIOLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< SESSEND PIO 信号锁定。 */
        using BVALIDPIOLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< BVALID PIO 信号锁定。 */
        using AVALIDPIOLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< AVALID PIO 信号锁定。 */
        using VBUSVALIDPIOLOCK = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< VBUSVALID PIO 信号锁定。 */
    } // namespace DEBUG

    /** @brief 电源模块特殊测试寄存器。 */
    namespace SPECIAL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80044100, 0x80044104, 0x80044108, 0x8004410C, LowLevel::Access::ReadWrite>;
        using TEST = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< 测试数据(32位全宽)。 */
    } // namespace SPECIAL

    /** @brief 电源模块版本寄存器。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80044130, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< 步进版本号。 */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< 次版本号。 */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< 主版本号。 */
    } // namespace VERSION

} // namespace Hardware::Registers::POWER

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_POWER
