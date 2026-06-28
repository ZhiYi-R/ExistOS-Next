#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_PINCTRL
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_PINCTRL

/**
 * @file PINCTRL.hpp
 * @brief PINCTRL 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 PINCTRL 引脚复用与 GPIO 控制器。提供 4 组物理引脚 Bank（Bank0~Bank3）的复用选择（MUXSEL）、驱动强度（DRIVE）、上拉电阻使能（PULL）、GPIO 输出数据（DOUT）、输入数据（DIN）、输出使能（DOE）以及中断配置（PIN2IRQ/IRQEN/IRQLEVEL/IRQPOL/IRQSTAT）。每引脚通过 2 位 MUXSEL 选择 0~3 共 4 种复用功能，值 3 通常映射为 GPIO 模式。DRIVE 寄存器按引脚配置输出驱动电流档位（_MA）与 I/O 电压域（_V）。PULL0/1/2 控制对应 Bank 的上拉电阻使能，PULL3 用于 Bank3 的 Pad Keeper 禁用。DOUT/DIN/DOE 以位掩码方式控制各 Bank 的 GPIO 输出值、输入采样值与方向。中断相关寄存器以位掩码逐引脚配置中断源选择、使能、电平/边沿触发、极性及状态。CTRL 寄存器提供模块级软复位（SFTRST）、时钟门控（CLKGATE）、Bank 存在标志（PRESENT）及中断输出路由（IRQOUT）。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::PINCTRL {

    /** @brief PINCTRL 模块控制寄存器，包含中断输出路由、Bank 存在标志、时钟门控与软复位。 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018000, 0x80018004, 0x80018008, 0x8001800C, LowLevel::Access::ReadWrite>;
        using IRQOUT0 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Bank 0 中断输出路由使能，置 1 时将 Bank 0 的 GPIO 中断路由至 IRQ0 输出。 */
        using IRQOUT1 = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Bank 1 中断输出路由使能，置 1 时将 Bank 1 的 GPIO 中断路由至 IRQ1 输出。 */
        using IRQOUT2 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 2 中断输出路由使能，置 1 时将 Bank 2 的 GPIO 中断路由至 IRQ2 输出。 */
        using PRESENT0 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Bank 0 存在标志，只读，为 1 表示 Bank 0 引脚在芯片中物理存在。 */
        using PRESENT1 = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Bank 1 存在标志，只读，为 1 表示 Bank 1 引脚在芯片中物理存在。 */
        using PRESENT2 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 2 存在标志，只读，为 1 表示 Bank 2 引脚在芯片中物理存在。 */
        using PRESENT3 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Bank 3 存在标志，只读，为 1 表示 Bank 3 引脚在芯片中物理存在。 */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< 时钟门控控制，置 1 时关闭 PINCTRL 模块时钟以节省功耗，置 0 时使能时钟。 */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< 软复位控制，置 1 时对 PINCTRL 模块执行软复位，置 0 时正常工作。 */
    } // namespace CTRL

    /** @brief Bank 0 引脚复用选择寄存器 0，配置 Pin00~Pin15 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018100, 0x80018104, 0x80018108, 0x8001810C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 0 引脚 0 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN01 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 0 引脚 1 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN02 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 0 引脚 2 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN03 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 0 引脚 3 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN04 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 0 引脚 4 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN05 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 0 引脚 5 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN06 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 0 引脚 6 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN07 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 0 引脚 7 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN08 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 0 引脚 8 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN09 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 0 引脚 9 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN10 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 0 引脚 10 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN11 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 0 引脚 11 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN12 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 0 引脚 12 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN13 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 0 引脚 13 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 0 引脚 14 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN15 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< Bank 0 引脚 15 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL0

    /** @brief Bank 0 引脚复用选择寄存器 1，配置 Pin16~Pin31 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018110, 0x80018114, 0x80018118, 0x8001811C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN16 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 0 引脚 16 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN17 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 0 引脚 17 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN18 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 0 引脚 18 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN19 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 0 引脚 19 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN20 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 0 引脚 20 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN21 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 0 引脚 21 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN22 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 0 引脚 22 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN23 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 0 引脚 23 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN24 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 0 引脚 24 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN25 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 0 引脚 25 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN26 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 0 引脚 26 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN27 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 0 引脚 27 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN28 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 0 引脚 28 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN29 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 0 引脚 29 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN30 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 0 引脚 30 的复用功能选择（2 位，0~3）。 */
        using BANK0_PIN31 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< Bank 0 引脚 31 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL1

    /** @brief Bank 1 引脚复用选择寄存器 2，配置 Pin00~Pin15 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018120, 0x80018124, 0x80018128, 0x8001812C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 1 引脚 0 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN01 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 1 引脚 1 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN02 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 1 引脚 2 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN03 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 1 引脚 3 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN04 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 1 引脚 4 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN05 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 1 引脚 5 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN06 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 1 引脚 6 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN07 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 1 引脚 7 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN08 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 1 引脚 8 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN09 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 1 引脚 9 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN10 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 1 引脚 10 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN11 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 1 引脚 11 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN12 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 1 引脚 12 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN13 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 1 引脚 13 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 1 引脚 14 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN15 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< Bank 1 引脚 15 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL2

    /** @brief Bank 1 引脚复用选择寄存器 3，配置 Pin16~Pin27 及 Pin14/Pin29/Pin30 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018130, 0x80018134, 0x80018138, 0x8001813C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN16 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 1 引脚 16 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN17 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 1 引脚 17 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN18 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 1 引脚 18 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN19 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 1 引脚 19 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN20 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 1 引脚 20 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN21 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 1 引脚 21 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN22 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 1 引脚 22 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN23 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 1 引脚 23 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN24 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 1 引脚 24 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN25 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 1 引脚 25 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN26 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 1 引脚 26 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN27 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 1 引脚 27 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 1 引脚 14 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN29 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 1 引脚 29 的复用功能选择（2 位，0~3）。 */
        using BANK1_PIN30 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 1 引脚 30 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL3

    /** @brief Bank 2 引脚复用选择寄存器 4，配置 Pin00~Pin15 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018140, 0x80018144, 0x80018148, 0x8001814C, LowLevel::Access::ReadWrite>;
        using BANK2_PIN00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 2 引脚 0 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN01 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 2 引脚 1 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN02 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 2 引脚 2 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN03 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 2 引脚 3 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN04 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 2 引脚 4 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN05 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 2 引脚 5 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN06 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 2 引脚 6 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN07 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 2 引脚 7 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN08 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 2 引脚 8 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN09 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 2 引脚 9 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN10 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 2 引脚 10 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN11 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 2 引脚 11 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN12 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 2 引脚 12 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN13 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 2 引脚 13 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 2 引脚 14 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN15 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< Bank 2 引脚 15 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL4

    /** @brief Bank 2 引脚复用选择寄存器 5，配置 Pin16~Pin27 及 Pin14/Pin29/Pin30/Pin31 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018150, 0x80018154, 0x80018158, 0x8001815C, LowLevel::Access::ReadWrite>;
        using BANK2_PIN16 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 2 引脚 16 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN17 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 2 引脚 17 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN18 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 2 引脚 18 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN19 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 2 引脚 19 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN20 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 2 引脚 20 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN21 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 2 引脚 21 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN22 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 2 引脚 22 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN23 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 2 引脚 23 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN24 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 2 引脚 24 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN25 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 2 引脚 25 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN26 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 2 引脚 26 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN27 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 2 引脚 27 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 2 引脚 14 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN29 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 2 引脚 29 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN30 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 2 引脚 30 的复用功能选择（2 位，0~3）。 */
        using BANK2_PIN31 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< Bank 2 引脚 31 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL5

    /** @brief Bank 3 引脚复用选择寄存器 6，配置 Pin00~Pin15 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018160, 0x80018164, 0x80018168, 0x8001816C, LowLevel::Access::ReadWrite>;
        using BANK3_PIN00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 3 引脚 0 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN01 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 3 引脚 1 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN02 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 3 引脚 2 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN03 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 3 引脚 3 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN04 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 3 引脚 4 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN05 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 3 引脚 5 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN06 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 3 引脚 6 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN07 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< Bank 3 引脚 7 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN08 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 3 引脚 8 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN09 = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 2, std::uint32_t>; /**< Bank 3 引脚 9 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN10 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 3 引脚 10 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN11 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Bank 3 引脚 11 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN12 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 3 引脚 12 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN13 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 2, std::uint32_t>; /**< Bank 3 引脚 13 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 3 引脚 14 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN15 = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 2, std::uint32_t>; /**< Bank 3 引脚 15 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL6

    /** @brief Bank 3 引脚复用选择寄存器 7，配置 Pin16~Pin21 的复用功能（每引脚 2 位，0~3 对应 4 种功能，值 3 通常为 GPIO 模式）。 */
    namespace MUXSEL7 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018170, 0x80018174, 0x80018178, 0x8001817C, LowLevel::Access::ReadWrite>;
        using BANK3_PIN16 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 3 引脚 16 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN17 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 2, std::uint32_t>; /**< Bank 3 引脚 17 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN18 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 3 引脚 18 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN19 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 2, std::uint32_t>; /**< Bank 3 引脚 19 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN20 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 3 引脚 20 的复用功能选择（2 位，0~3）。 */
        using BANK3_PIN21 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 2, std::uint32_t>; /**< Bank 3 引脚 21 的复用功能选择（2 位，0~3）。 */
    } // namespace MUXSEL7

    /** @brief Bank 0 驱动强度与电压寄存器 0，配置 Pin00~Pin07 的输出驱动电流档位（_MA，2 位）与 I/O 电压域选择（_V，1 位）。 */
    namespace DRIVE0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018200, 0x80018204, 0x80018208, 0x8001820C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN00_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 0 引脚 0 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN00_V = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 0 引脚 0 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN01_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 0 引脚 1 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN01_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 0 引脚 1 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN02_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 0 引脚 2 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN02_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 0 引脚 2 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN03_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 0 引脚 3 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN03_V = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 0 引脚 3 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN04_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 0 引脚 4 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN04_V = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Bank 0 引脚 4 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN05_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 0 引脚 5 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN05_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 0 引脚 5 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN06_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 0 引脚 6 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN06_V = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 0 引脚 6 的 I/O 电压域选择（1 位）。 */
        using BANK0_PIN07_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 0 引脚 7 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN07_V = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bank 0 引脚 7 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE0

    /** @brief Bank 0 驱动强度寄存器 1，配置 Pin08~Pin15 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018210, 0x80018214, 0x80018218, 0x8001821C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN08_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 0 引脚 8 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN09_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 0 引脚 9 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN10_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 0 引脚 10 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN11_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 0 引脚 11 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN12_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 0 引脚 12 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN13_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 0 引脚 13 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 0 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN15_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 0 引脚 15 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE1

    /** @brief Bank 0 驱动强度寄存器 2，配置 Pin16~Pin23 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018220, 0x80018224, 0x80018228, 0x8001822C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN16_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 0 引脚 16 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN17_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 0 引脚 17 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN18_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 0 引脚 18 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN19_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 0 引脚 19 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN20_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 0 引脚 20 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN21_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 0 引脚 21 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN22_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 0 引脚 22 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN23_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 0 引脚 23 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE2

    /** @brief Bank 0 驱动强度寄存器 3，配置 Pin24~Pin27 及 Pin14/Pin29/Pin30/Pin31 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018230, 0x80018234, 0x80018238, 0x8001823C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN24_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 0 引脚 24 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN25_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 0 引脚 25 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN26_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 0 引脚 26 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN27_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 0 引脚 27 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 0 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN29_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 0 引脚 29 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN30_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 0 引脚 30 的输出驱动电流档位选择（2 位）。 */
        using BANK0_PIN31_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 0 引脚 31 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE3

    /** @brief Bank 1 驱动强度寄存器 4，配置 Pin00~Pin07 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018240, 0x80018244, 0x80018248, 0x8001824C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN00_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 1 引脚 0 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN01_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 1 引脚 1 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN02_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 1 引脚 2 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN03_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 1 引脚 3 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN04_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 1 引脚 4 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN05_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 1 引脚 5 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN06_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 1 引脚 6 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN07_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 1 引脚 7 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE4

    /** @brief Bank 1 驱动强度寄存器 5，配置 Pin08~Pin15 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018250, 0x80018254, 0x80018258, 0x8001825C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN08_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 1 引脚 8 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN09_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 1 引脚 9 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN10_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 1 引脚 10 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN11_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 1 引脚 11 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN12_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 1 引脚 12 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN13_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 1 引脚 13 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 1 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN15_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 1 引脚 15 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE5

    /** @brief Bank 1 驱动强度寄存器 6，配置 Pin16~Pin23 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018260, 0x80018264, 0x80018268, 0x8001826C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN16_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 1 引脚 16 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN17_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 1 引脚 17 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN18_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 1 引脚 18 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN19_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 1 引脚 19 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN20_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 1 引脚 20 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN21_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 1 引脚 21 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN22_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 1 引脚 22 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN23_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 1 引脚 23 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE6

    /** @brief Bank 1 驱动强度寄存器 7，配置 Pin24~Pin27 及 Pin14/Pin29/Pin30 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE7 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018270, 0x80018274, 0x80018278, 0x8001827C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN24_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 1 引脚 24 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN25_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 1 引脚 25 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN26_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 1 引脚 26 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN27_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 1 引脚 27 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 1 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN29_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 1 引脚 29 的输出驱动电流档位选择（2 位）。 */
        using BANK1_PIN30_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 1 引脚 30 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE7

    /** @brief Bank 2 驱动强度寄存器 8，配置 Pin00~Pin07 的输出驱动电流档位（_MA，2 位，无 _V 字段）。 */
    namespace DRIVE8 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018280, 0x80018284, 0x80018288, 0x8001828C, LowLevel::Access::ReadWrite>;
        using BANK2_PIN00_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 2 引脚 0 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN01_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 2 引脚 1 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN02_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 2 引脚 2 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN03_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 2 引脚 3 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN04_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 2 引脚 4 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN05_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 2 引脚 5 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN06_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 2 引脚 6 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN07_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 2 引脚 7 的输出驱动电流档位选择（2 位）。 */
    } // namespace DRIVE8

    /** @brief Bank 2 驱动强度与电压寄存器 9，配置 Pin08~Pin15 的输出驱动电流档位（_MA，2 位）与电压域（_V，1 位）；其中 Pin08 仅有 _MA 无 _V。 */
    namespace DRIVE9 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018290, 0x80018294, 0x80018298, 0x8001829C, LowLevel::Access::ReadWrite>;
        using BANK2_PIN08_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 2 引脚 8 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN09_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 2 引脚 9 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN09_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 2 引脚 9 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN10_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 2 引脚 10 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN10_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 2 引脚 10 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN11_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 2 引脚 11 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN11_V = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 2 引脚 11 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN12_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 2 引脚 12 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN12_V = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Bank 2 引脚 12 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN13_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 2 引脚 13 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN13_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 2 引脚 13 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 2 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN14_V = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 2 引脚 14 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN15_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 2 引脚 15 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN15_V = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bank 2 引脚 15 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE9

    /** @brief Bank 2 驱动强度与电压寄存器 10，配置 Pin16~Pin23 的输出驱动电流档位（_MA，2 位）与电压域（_V，1 位）。 */
    namespace DRIVE10 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800182A0, 0x800182A4, 0x800182A8, 0x800182AC, LowLevel::Access::ReadWrite>;
        using BANK2_PIN16_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 2 引脚 16 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN16_V = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 2 引脚 16 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN17_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 2 引脚 17 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN17_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 2 引脚 17 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN18_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 2 引脚 18 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN18_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 2 引脚 18 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN19_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 2 引脚 19 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN19_V = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 2 引脚 19 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN20_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 2 引脚 20 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN20_V = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Bank 2 引脚 20 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN21_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 2 引脚 21 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN21_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 2 引脚 21 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN22_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 2 引脚 22 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN22_V = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 2 引脚 22 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN23_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 2 引脚 23 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN23_V = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bank 2 引脚 23 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE10

    /** @brief Bank 2 驱动强度与电压寄存器 11，配置 Pin24~Pin26、Pin14、Pin29~Pin31 的输出驱动电流档位（_MA，2 位）与电压域（_V，1 位）；其中 Pin27 仅有 _MA 无 _V。 */
    namespace DRIVE11 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800182B0, 0x800182B4, 0x800182B8, 0x800182BC, LowLevel::Access::ReadWrite>;
        using BANK2_PIN24_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 2 引脚 24 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN24_V = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 2 引脚 24 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN25_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 2 引脚 25 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN25_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 2 引脚 25 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN26_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 2 引脚 26 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN26_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 2 引脚 26 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN27_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 2 引脚 27 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 2 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN29_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 2 引脚 29 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN29_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 2 引脚 29 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN30_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 2 引脚 30 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN30_V = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 2 引脚 30 的 I/O 电压域选择（1 位）。 */
        using BANK2_PIN31_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 2 引脚 31 的输出驱动电流档位选择（2 位）。 */
        using BANK2_PIN31_V = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bank 2 引脚 31 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE11

    /** @brief Bank 3 驱动强度与电压寄存器 12，配置 Pin00~Pin07 的输出驱动电流档位（_MA，2 位）与电压域（_V，1 位）。 */
    namespace DRIVE12 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800182C0, 0x800182C4, 0x800182C8, 0x800182CC, LowLevel::Access::ReadWrite>;
        using BANK3_PIN00_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 3 引脚 0 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN00_V = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 3 引脚 0 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN01_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 3 引脚 1 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN01_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 3 引脚 1 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN02_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 3 引脚 2 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN02_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 3 引脚 2 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN03_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 3 引脚 3 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN03_V = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 3 引脚 3 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN04_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 3 引脚 4 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN04_V = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Bank 3 引脚 4 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN05_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 3 引脚 5 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN05_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 3 引脚 5 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN06_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 3 引脚 6 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN06_V = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 3 引脚 6 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN07_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 3 引脚 7 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN07_V = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bank 3 引脚 7 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE12

    /** @brief Bank 3 驱动强度与电压寄存器 13，配置 Pin08~Pin15 的输出驱动电流档位（_MA，2 位）与电压域（_V，1 位）。 */
    namespace DRIVE13 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800182D0, 0x800182D4, 0x800182D8, 0x800182DC, LowLevel::Access::ReadWrite>;
        using BANK3_PIN08_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 3 引脚 8 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN08_V = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 3 引脚 8 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN09_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 3 引脚 9 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN09_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 3 引脚 9 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN10_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 3 引脚 10 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN10_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 3 引脚 10 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN11_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 3 引脚 11 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN11_V = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 3 引脚 11 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN12_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 3 引脚 12 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN12_V = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Bank 3 引脚 12 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN13_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 3 引脚 13 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN13_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 3 引脚 13 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN14_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 2, std::uint32_t>; /**< Bank 3 引脚 14 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN14_V = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 3 引脚 14 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN15_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 2, std::uint32_t>; /**< Bank 3 引脚 15 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN15_V = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Bank 3 引脚 15 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE13

    /** @brief Bank 3 驱动强度与电压寄存器 14，配置 Pin16~Pin21 的输出驱动电流档位（_MA，2 位）与电压域（_V，1 位）。 */
    namespace DRIVE14 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800182E0, 0x800182E4, 0x800182E8, 0x800182EC, LowLevel::Access::ReadWrite>;
        using BANK3_PIN16_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 2, std::uint32_t>; /**< Bank 3 引脚 16 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN16_V = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 3 引脚 16 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN17_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 2, std::uint32_t>; /**< Bank 3 引脚 17 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN17_V = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 3 引脚 17 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN18_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Bank 3 引脚 18 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN18_V = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 3 引脚 18 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN19_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< Bank 3 引脚 19 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN19_V = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 3 引脚 19 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN20_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bank 3 引脚 20 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN20_V = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< Bank 3 引脚 20 的 I/O 电压域选择（1 位）。 */
        using BANK3_PIN21_MA = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Bank 3 引脚 21 的输出驱动电流档位选择（2 位）。 */
        using BANK3_PIN21_V = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 3 引脚 21 的 I/O 电压域选择（1 位）。 */
    } // namespace DRIVE14

    /** @brief Bank 0 上拉电阻使能寄存器，逐位控制对应引脚的上拉电阻使能（1 表示使能内部上拉电阻）。 */
    namespace PULL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018300, 0x80018304, 0x80018308, 0x8001830C, LowLevel::Access::ReadWrite>;
        using BANK0_PIN01 = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Bank 0 引脚 1 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN02 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 0 引脚 2 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN03 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Bank 0 引脚 3 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN04 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Bank 0 引脚 4 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN05 = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Bank 0 引脚 5 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN06 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 0 引脚 6 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN07 = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Bank 0 引脚 7 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN20 = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< Bank 0 引脚 20 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN26 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 0 引脚 26 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN27 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Bank 0 引脚 27 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Bank 0 引脚 14 的上拉电阻使能控制（1 使能）。 */
        using BANK0_PIN29 = LowLevel::Field<Reg, LowLevel::Bit::Bit29, 1, std::uint32_t>; /**< Bank 0 引脚 29 的上拉电阻使能控制（1 使能）。 */
    } // namespace PULL0

    /** @brief Bank 1 上拉电阻使能寄存器，逐位控制对应引脚的上拉电阻使能（1 表示使能内部上拉电阻）。 */
    namespace PULL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018310, 0x80018314, 0x80018318, 0x8001831C, LowLevel::Access::ReadWrite>;
        using BANK1_PIN22 = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 1, std::uint32_t>; /**< Bank 1 引脚 22 的上拉电阻使能控制（1 使能）。 */
        using BANK1_PIN24 = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Bank 1 引脚 24 的上拉电阻使能控制（1 使能）。 */
        using BANK1_PIN25 = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Bank 1 引脚 25 的上拉电阻使能控制（1 使能）。 */
        using BANK1_PIN26 = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Bank 1 引脚 26 的上拉电阻使能控制（1 使能）。 */
        using BANK1_PIN27 = LowLevel::Field<Reg, LowLevel::Bit::Bit27, 1, std::uint32_t>; /**< Bank 1 引脚 27 的上拉电阻使能控制（1 使能）。 */
    } // namespace PULL1

    /** @brief Bank 2 上拉电阻使能寄存器，逐位控制对应引脚的上拉电阻使能（1 表示使能内部上拉电阻）。 */
    namespace PULL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018320, 0x80018324, 0x80018328, 0x8001832C, LowLevel::Access::ReadWrite>;
        using BANK2_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 2 引脚 14 的上拉电阻使能控制（1 使能）。 */
    } // namespace PULL2

    /** @brief Bank 3 Pad Keeper 禁用寄存器，逐位控制对应引脚的 Pad Keeper 功能禁用（1 表示禁用 Pad Keeper）。 */
    namespace PULL3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018330, 0x80018334, 0x80018338, 0x8001833C, LowLevel::Access::ReadWrite>;
        using BANK3_PIN00 = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Bank 3 引脚 0 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN01 = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Bank 3 引脚 1 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN02 = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Bank 3 引脚 2 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN03 = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Bank 3 引脚 3 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN04 = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Bank 3 引脚 4 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN05 = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Bank 3 引脚 5 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN06 = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< Bank 3 引脚 6 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN07 = LowLevel::Field<Reg, LowLevel::Bit::Bit7, 1, std::uint32_t>; /**< Bank 3 引脚 7 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN08 = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Bank 3 引脚 8 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN09 = LowLevel::Field<Reg, LowLevel::Bit::Bit9, 1, std::uint32_t>; /**< Bank 3 引脚 9 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN10 = LowLevel::Field<Reg, LowLevel::Bit::Bit10, 1, std::uint32_t>; /**< Bank 3 引脚 10 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN11 = LowLevel::Field<Reg, LowLevel::Bit::Bit11, 1, std::uint32_t>; /**< Bank 3 引脚 11 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN12 = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Bank 3 引脚 12 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN13 = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Bank 3 引脚 13 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN14 = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Bank 3 引脚 14 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN15 = LowLevel::Field<Reg, LowLevel::Bit::Bit15, 1, std::uint32_t>; /**< Bank 3 引脚 15 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN16 = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Bank 3 引脚 16 的 Pad Keeper 禁用控制（1 禁用）。 */
        using BANK3_PIN17 = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 1, std::uint32_t>; /**< Bank 3 引脚 17 的 Pad Keeper 禁用控制（1 禁用）。 */
    } // namespace PULL3

    /** @brief Bank 0 GPIO 数据输出寄存器，低 30 位逐位控制对应引脚的 GPIO 输出电平（1 高电平，0 低电平）。 */
    namespace DOUT0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018400, 0x80018404, 0x80018408, 0x8001840C, LowLevel::Access::ReadWrite>;
        using DOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 30, std::uint32_t>; /**< Bank 0 的 GPIO 输出数据位域（30 位），逐位对应引脚 0~29 的输出电平。 */
    } // namespace DOUT0

    /** @brief Bank 1 GPIO 数据输出寄存器，低 29 位逐位控制对应引脚的 GPIO 输出电平（1 高电平，0 低电平）。 */
    namespace DOUT1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018410, 0x80018414, 0x80018418, 0x8001841C, LowLevel::Access::ReadWrite>;
        using DOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 29, std::uint32_t>; /**< Bank 1 的 GPIO 输出数据位域（29 位），逐位对应引脚 0~28 的输出电平。 */
    } // namespace DOUT1

    /** @brief Bank 2 GPIO 数据输出寄存器，32 位逐位控制对应引脚的 GPIO 输出电平（1 高电平，0 低电平）。 */
    namespace DOUT2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018420, 0x80018424, 0x80018428, 0x8001842C, LowLevel::Access::ReadWrite>;
        using DOUT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的 GPIO 输出数据位域（32 位），逐位对应引脚 0~31 的输出电平。 */
    } // namespace DOUT2

    /** @brief Bank 0 GPIO 数据输入寄存器，低 30 位反映对应引脚的当前输入采样电平（只读）。 */
    namespace DIN0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018500, 0x80018504, 0x80018508, 0x8001850C, LowLevel::Access::ReadWrite>;
        using DIN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 30, std::uint32_t>; /**< Bank 0 的 GPIO 输入数据位域（30 位），逐位反映引脚 0~29 的当前输入电平。 */
    } // namespace DIN0

    /** @brief Bank 1 GPIO 数据输入寄存器，低 29 位反映对应引脚的当前输入采样电平（只读）。 */
    namespace DIN1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018510, 0x80018514, 0x80018518, 0x8001851C, LowLevel::Access::ReadWrite>;
        using DIN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 29, std::uint32_t>; /**< Bank 1 的 GPIO 输入数据位域（29 位），逐位反映引脚 0~28 的当前输入电平。 */
    } // namespace DIN1

    /** @brief Bank 2 GPIO 数据输入寄存器，32 位反映对应引脚的当前输入采样电平（只读）。 */
    namespace DIN2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018520, 0x80018524, 0x80018528, 0x8001852C, LowLevel::Access::ReadWrite>;
        using DIN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的 GPIO 输入数据位域（32 位），逐位反映引脚 0~31 的当前输入电平。 */
    } // namespace DIN2

    /** @brief Bank 0 GPIO 输出使能寄存器，低 30 位逐位控制对应引脚的方向（1 输出模式，0 输入/高阻模式）。 */
    namespace DOE0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018600, 0x80018604, 0x80018608, 0x8001860C, LowLevel::Access::ReadWrite>;
        using DOE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 30, std::uint32_t>; /**< Bank 0 的 GPIO 输出使能位域（30 位），逐位控制引脚 0~29 的方向。 */
    } // namespace DOE0

    /** @brief Bank 1 GPIO 输出使能寄存器，低 29 位逐位控制对应引脚的方向（1 输出模式，0 输入/高阻模式）。 */
    namespace DOE1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018610, 0x80018614, 0x80018618, 0x8001861C, LowLevel::Access::ReadWrite>;
        using DOE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 29, std::uint32_t>; /**< Bank 1 的 GPIO 输出使能位域（29 位），逐位控制引脚 0~28 的方向。 */
    } // namespace DOE1

    /** @brief Bank 2 GPIO 输出使能寄存器，32 位逐位控制对应引脚的方向（1 输出模式，0 输入/高阻模式）。 */
    namespace DOE2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018620, 0x80018624, 0x80018628, 0x8001862C, LowLevel::Access::ReadWrite>;
        using DOE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的 GPIO 输出使能位域（32 位），逐位控制引脚 0~31 的方向。 */
    } // namespace DOE2

    /** @brief Bank 0 中断源选择寄存器，32 位逐位将对应引脚映射为中断源（1 表示该引脚可产生中断）。 */
    namespace PIN2IRQ0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018700, 0x80018704, 0x80018708, 0x8001870C, LowLevel::Access::ReadWrite>;
        using PIN2IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 0 的引脚中断源选择位域（32 位），逐位使能引脚 0~31 作为中断源。 */
    } // namespace PIN2IRQ0

    /** @brief Bank 1 中断源选择寄存器，低 31 位逐位将对应引脚映射为中断源（1 表示该引脚可产生中断）。 */
    namespace PIN2IRQ1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018710, 0x80018714, 0x80018718, 0x8001871C, LowLevel::Access::ReadWrite>;
        using PIN2IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 31, std::uint32_t>; /**< Bank 1 的引脚中断源选择位域（31 位），逐位使能引脚 0~30 作为中断源。 */
    } // namespace PIN2IRQ1

    /** @brief Bank 2 中断源选择寄存器，32 位逐位将对应引脚映射为中断源（1 表示该引脚可产生中断）。 */
    namespace PIN2IRQ2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018720, 0x80018724, 0x80018728, 0x8001872C, LowLevel::Access::ReadWrite>;
        using PIN2IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的引脚中断源选择位域（32 位），逐位使能引脚 0~31 作为中断源。 */
    } // namespace PIN2IRQ2

    /** @brief Bank 0 中断使能寄存器，32 位逐位控制对应引脚中断的使能（1 允许中断，0 屏蔽中断）。 */
    namespace IRQEN0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018800, 0x80018804, 0x80018808, 0x8001880C, LowLevel::Access::ReadWrite>;
        using IRQEN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 0 的中断使能位域（32 位），逐位控制引脚 0~31 的中断屏蔽。 */
    } // namespace IRQEN0

    /** @brief Bank 1 中断使能寄存器，低 31 位逐位控制对应引脚中断的使能（1 允许中断，0 屏蔽中断）。 */
    namespace IRQEN1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018810, 0x80018814, 0x80018818, 0x8001881C, LowLevel::Access::ReadWrite>;
        using IRQEN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 31, std::uint32_t>; /**< Bank 1 的中断使能位域（31 位），逐位控制引脚 0~30 的中断屏蔽。 */
    } // namespace IRQEN1

    /** @brief Bank 2 中断使能寄存器，32 位逐位控制对应引脚中断的使能（1 允许中断，0 屏蔽中断）。 */
    namespace IRQEN2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018820, 0x80018824, 0x80018828, 0x8001882C, LowLevel::Access::ReadWrite>;
        using IRQEN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的中断使能位域（32 位），逐位控制引脚 0~31 的中断屏蔽。 */
    } // namespace IRQEN2

    /** @brief Bank 0 中断电平/边沿触发寄存器，32 位逐位配置对应引脚的中断触发方式（1 电平触发，0 边沿触发）。 */
    namespace IRQLEVEL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018900, 0x80018904, 0x80018908, 0x8001890C, LowLevel::Access::ReadWrite>;
        using IRQLEVEL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 0 的中断触发方式位域（32 位），逐位配置引脚 0~31 为电平触发（1）或边沿触发（0）。 */
    } // namespace IRQLEVEL0

    /** @brief Bank 1 中断电平/边沿触发寄存器，低 31 位逐位配置对应引脚的中断触发方式（1 电平触发，0 边沿触发）。 */
    namespace IRQLEVEL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018910, 0x80018914, 0x80018918, 0x8001891C, LowLevel::Access::ReadWrite>;
        using IRQLEVEL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 31, std::uint32_t>; /**< Bank 1 的中断触发方式位域（31 位），逐位配置引脚 0~30 为电平触发（1）或边沿触发（0）。 */
    } // namespace IRQLEVEL1

    /** @brief Bank 2 中断电平/边沿触发寄存器，32 位逐位配置对应引脚的中断触发方式（1 电平触发，0 边沿触发）。 */
    namespace IRQLEVEL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018920, 0x80018924, 0x80018928, 0x8001892C, LowLevel::Access::ReadWrite>;
        using IRQLEVEL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的中断触发方式位域（32 位），逐位配置引脚 0~31 为电平触发（1）或边沿触发（0）。 */
    } // namespace IRQLEVEL2

    /** @brief Bank 0 中断极性寄存器，32 位逐位配置对应引脚的中断触发极性（1 高电平/上升沿有效，0 低电平/下降沿有效）。 */
    namespace IRQPOL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018A00, 0x80018A04, 0x80018A08, 0x80018A0C, LowLevel::Access::ReadWrite>;
        using IRQPOL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 0 的中断极性位域（32 位），逐位配置引脚 0~31 的触发极性。 */
    } // namespace IRQPOL0

    /** @brief Bank 1 中断极性寄存器，低 31 位逐位配置对应引脚的中断触发极性（1 高电平/上升沿有效，0 低电平/下降沿有效）。 */
    namespace IRQPOL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018A10, 0x80018A14, 0x80018A18, 0x80018A1C, LowLevel::Access::ReadWrite>;
        using IRQPOL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 31, std::uint32_t>; /**< Bank 1 的中断极性位域（31 位），逐位配置引脚 0~30 的触发极性。 */
    } // namespace IRQPOL1

    /** @brief Bank 2 中断极性寄存器，32 位逐位配置对应引脚的中断触发极性（1 高电平/上升沿有效，0 低电平/下降沿有效）。 */
    namespace IRQPOL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018A20, 0x80018A24, 0x80018A28, 0x80018A2C, LowLevel::Access::ReadWrite>;
        using IRQPOL = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的中断极性位域（32 位），逐位配置引脚 0~31 的触发极性。 */
    } // namespace IRQPOL2

    /** @brief Bank 0 中断状态寄存器，32 位逐位反映对应引脚的中断挂起状态（1 表示有中断待处理，写 1 清除）。 */
    namespace IRQSTAT0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018B00, 0x80018B04, 0x80018B08, 0x80018B0C, LowLevel::Access::ReadWrite>;
        using IRQSTAT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 0 的中断状态位域（32 位），逐位反映引脚 0~31 的中断挂起状态。 */
    } // namespace IRQSTAT0

    /** @brief Bank 1 中断状态寄存器，低 31 位逐位反映对应引脚的中断挂起状态（1 表示有中断待处理，写 1 清除）。 */
    namespace IRQSTAT1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018B10, 0x80018B14, 0x80018B18, 0x80018B1C, LowLevel::Access::ReadWrite>;
        using IRQSTAT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 31, std::uint32_t>; /**< Bank 1 的中断状态位域（31 位），逐位反映引脚 0~30 的中断挂起状态。 */
    } // namespace IRQSTAT1

    /** @brief Bank 2 中断状态寄存器，32 位逐位反映对应引脚的中断挂起状态（1 表示有中断待处理，写 1 清除）。 */
    namespace IRQSTAT2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80018B20, 0x80018B24, 0x80018B28, 0x80018B2C, LowLevel::Access::ReadWrite>;
        using IRQSTAT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 32, std::uint32_t>; /**< Bank 2 的中断状态位域（32 位），逐位反映引脚 0~31 的中断挂起状态。 */
    } // namespace IRQSTAT2

} // namespace Hardware::Registers::PINCTRL

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_PINCTRL
