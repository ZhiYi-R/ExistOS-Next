#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_TIMROT
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_TIMROT

/**
 * @file TIMROT.hpp
 * @brief TIMROT 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * STMP3770 TIMROT 外设：定时器与旋钮解码器。包含 4 个通用定时器（Timer0~3）和 1 个旋钮解码器，支持 PWM、晶振及旋钮输入等多种时钟源，可配置预分频、自动重载、中断等功能。ROTCTRL 控制旋钮解码器输入源、极性、过采样率及分频等；ROTCOUNT 保存旋钮旋转产生的计数值。各定时器通过 TIMCTRLn/TIMCOUNTn 寄存器组独立控制与计数。
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::TIMROT {

    /** @brief 旋钮解码器控制寄存器，配置输入源选择、极性、过采样率、相对模式、分频系数，以及各定时器/旋钮存在性标志、时钟门控和软复位。 */
    namespace ROTCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068000, 0x80068004, 0x80068008, 0x8006800C, LowLevel::Access::ReadWrite>;
        /** @brief SELECT_A 的取值。 */
        enum class SELECT_A_Values : std::uint32_t {
            NEVER_TICK = 0x0,
            PWM0 = 0x1,
            PWM1 = 0x2,
            PWM2 = 0x3,
            PWM3 = 0x4,
            PWM4 = 0x5,
            ROTARYA = 0x6,
            ROTARYB = 0x7,
        };
        using SELECT_A = LowLevel::Field<Reg, 0, 3, SELECT_A_Values>; /**< 旋钮 A 输入源选择：NEVER_TICK=不选；PWM0~4=对应 PWM 通道；ROTARYA/B=旋钮 A/B 输入。 */
        /** @brief SELECT_B 的取值。 */
        enum class SELECT_B_Values : std::uint32_t {
            NEVER_TICK = 0x0,
            PWM0 = 0x1,
            PWM1 = 0x2,
            PWM2 = 0x3,
            PWM3 = 0x4,
            PWM4 = 0x5,
            ROTARYA = 0x6,
            ROTARYB = 0x7,
        };
        using SELECT_B = LowLevel::Field<Reg, 4, 3, SELECT_B_Values>; /**< 旋钮 B 输入源选择：NEVER_TICK=不选；PWM0~4=对应 PWM 通道；ROTARYA/B=旋钮 A/B 输入。 */
        using POLARITY_A = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 旋钮 A 输入极性控制位。 */
        using POLARITY_B = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 旋钮 B 输入极性控制位。 */
        /** @brief OVERSAMPLE 的取值。 */
        enum class OVERSAMPLE_Values : std::uint32_t {
            _8X = 0x0,
            _4X = 0x1,
            _2X = 0x2,
            _1X = 0x3,
        };
        using OVERSAMPLE = LowLevel::Field<Reg, 10, 2, OVERSAMPLE_Values>; /**< 旋钮过采样率选择：8X/4X/2X/1X。 */
        using RELATIVE = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< 旋钮相对模式使能，置位后计数器按相对变化量累加或递减。 */
        using DIVIDER = LowLevel::Field<Reg, 16, 6, std::uint32_t>; /**< 旋钮输入时钟分频系数，6 位无符号值。 */
        using STATE = LowLevel::Field<Reg, 22, 3, std::uint32_t>; /**< 旋钮解码器当前状态，3 位只读状态值。 */
        using TIM0_PRESENT = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< Timer0 存在性标志，只读，1 表示该定时器存在。 */
        using TIM1_PRESENT = LowLevel::Field<Reg, 26, 1, std::uint32_t>; /**< Timer1 存在性标志，只读，1 表示该定时器存在。 */
        using TIM2_PRESENT = LowLevel::Field<Reg, 27, 1, std::uint32_t>; /**< Timer2 存在性标志，只读，1 表示该定时器存在。 */
        using TIM3_PRESENT = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< Timer3 存在性标志，只读，1 表示该定时器存在。 */
        using ROTARY_PRESENT = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< 旋钮解码器存在性标志，只读，1 表示该模块存在。 */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 时钟门控控制位，用于控制 TIMROT 模块时钟以节省功耗。 */
        using SFTRST = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 软复位控制位，置位时对整个 TIMROT 模块执行软件复位。 */
    } // namespace ROTCTRL

    /** @brief 旋钮解码器上下计数寄存器，保存旋钮旋转产生的计数值。 */
    namespace ROTCOUNT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068010, 0x80068014, 0x80068018, 0x8006801C, LowLevel::Access::ReadWrite>;
        using UPDOWN = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 旋钮上下计数值，16 位，反映旋钮旋转的方向与幅度。 */
    } // namespace ROTCOUNT

    /** @brief 定时器控制寄存器（数组，4 个实例），配置时钟源、预分频、自动重载、更新触发、极性、中断使能及中断状态。 */
    namespace TIMCTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068020, 0x80068024, 0x80068028, 0x8006802C, LowLevel::Access::ReadWrite>;
        /** @brief SELECT 的取值。 */
        enum class SELECT_Values : std::uint32_t {
            NEVER_TICK = 0x0,
            PWM0 = 0x1,
            PWM1 = 0x2,
            PWM2 = 0x3,
            PWM3 = 0x4,
            PWM4 = 0x5,
            ROTARYA = 0x6,
            ROTARYB = 0x7,
            _32KHZ_XTAL = 0x8,
            _8KHZ_XTAL = 0x9,
            _4KHZ_XTAL = 0xA,
            _1KHZ_XTAL = 0xB,
            TICK_ALWAYS = 0xC,
        };
        using SELECT = LowLevel::Field<Reg, 0, 4, SELECT_Values>; /**< 定时器时钟源选择：NEVER_TICK=不选；PWM0~4=对应 PWM 通道；ROTARYA/B=旋钮输入；32KHZ_XTAL/8KHZ_XTAL/4KHZ_XTAL/1KHZ_XTAL=对应晶振；TICK_ALWAYS=始终滴答。 */
        /** @brief PRESCALE 的取值。 */
        enum class PRESCALE_Values : std::uint32_t {
            DIV_BY_1 = 0x0,
            DIV_BY_2 = 0x1,
            DIV_BY_4 = 0x2,
            DIV_BY_8 = 0x3,
        };
        using PRESCALE = LowLevel::Field<Reg, 4, 2, PRESCALE_Values>; /**< 定时器预分频选择：DIV_BY_1=1 分频；DIV_BY_2=2 分频；DIV_BY_4=4 分频；DIV_BY_8=8 分频。 */
        using RELOAD = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 自动重载使能，计数到零后自动从 FIXED_COUNT 重新加载并继续计数。 */
        using UPDATE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 更新控制位，置位后刷新计数值并使能计数器。 */
        using POLARITY = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 定时器极性控制位。 */
        using DUTY_CYCLE = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 占空比测量模式使能(仅TIMCTRL3)，置位时进入占空比测量模式，TIMCOUNT3记录高电平宽度。 */
        using DUTY_VALID = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 占空比数据有效标志(仅TIMCTRL3)，只读，硬件置位表示TIMCOUNT3中占空比数据有效。 */
        using IRQ_EN = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 定时器中断使能控制位，置位时允许计数到零产生中断。 */
        using IRQ = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 定时器中断状态标志，计数到零时置位。 */
        using TEST_SIGNAL = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< 被测信号源选择(仅TIMCTRL3占空比模式)，枚举值与SELECT字段相同。 */
    } // namespace TIMCTRL0

    /** @brief 定时器计数寄存器（数组，4 个实例），包含重载初值与当前递减计数值。 */
    namespace TIMCOUNT0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068030, 0x80068034, 0x80068038, 0x8006803C, LowLevel::Access::ReadWrite>;
        using FIXED_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 定时器重载初值，计数器归零时从此值重新加载（需 RELOAD 使能）。 */
        using RUNNING_COUNT = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 定时器当前递减计数值，16 位只读，计数过程中实时递减。 */
    } // namespace TIMCOUNT0

    /** @brief 定时器控制寄存器（数组，4 个实例），配置时钟源、预分频、自动重载、更新触发、极性、中断使能及中断状态。 */
    namespace TIMCTRL1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068040, 0x80068044, 0x80068048, 0x8006804C, LowLevel::Access::ReadWrite>;
        /** @brief SELECT 的取值。 */
        enum class SELECT_Values : std::uint32_t {
            NEVER_TICK = 0x0,
            PWM0 = 0x1,
            PWM1 = 0x2,
            PWM2 = 0x3,
            PWM3 = 0x4,
            PWM4 = 0x5,
            ROTARYA = 0x6,
            ROTARYB = 0x7,
            _32KHZ_XTAL = 0x8,
            _8KHZ_XTAL = 0x9,
            _4KHZ_XTAL = 0xA,
            _1KHZ_XTAL = 0xB,
            TICK_ALWAYS = 0xC,
        };
        using SELECT = LowLevel::Field<Reg, 0, 4, SELECT_Values>; /**< 定时器时钟源选择：NEVER_TICK=不选；PWM0~4=对应 PWM 通道；ROTARYA/B=旋钮输入；32KHZ_XTAL/8KHZ_XTAL/4KHZ_XTAL/1KHZ_XTAL=对应晶振；TICK_ALWAYS=始终滴答。 */
        /** @brief PRESCALE 的取值。 */
        enum class PRESCALE_Values : std::uint32_t {
            DIV_BY_1 = 0x0,
            DIV_BY_2 = 0x1,
            DIV_BY_4 = 0x2,
            DIV_BY_8 = 0x3,
        };
        using PRESCALE = LowLevel::Field<Reg, 4, 2, PRESCALE_Values>; /**< 定时器预分频选择：DIV_BY_1=1 分频；DIV_BY_2=2 分频；DIV_BY_4=4 分频；DIV_BY_8=8 分频。 */
        using RELOAD = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 自动重载使能，计数到零后自动从 FIXED_COUNT 重新加载并继续计数。 */
        using UPDATE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 更新控制位，置位后刷新计数值并使能计数器。 */
        using POLARITY = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 定时器极性控制位。 */
        using DUTY_CYCLE = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 占空比测量模式使能(仅TIMCTRL3)，置位时进入占空比测量模式，TIMCOUNT3记录高电平宽度。 */
        using DUTY_VALID = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 占空比数据有效标志(仅TIMCTRL3)，只读，硬件置位表示TIMCOUNT3中占空比数据有效。 */
        using IRQ_EN = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 定时器中断使能控制位，置位时允许计数到零产生中断。 */
        using IRQ = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 定时器中断状态标志，计数到零时置位。 */
        using TEST_SIGNAL = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< 被测信号源选择(仅TIMCTRL3占空比模式)，枚举值与SELECT字段相同。 */
    } // namespace TIMCTRL1

    /** @brief 定时器计数寄存器（数组，4 个实例），包含重载初值与当前递减计数值。 */
    namespace TIMCOUNT1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068050, 0x80068054, 0x80068058, 0x8006805C, LowLevel::Access::ReadWrite>;
        using FIXED_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 定时器重载初值，计数器归零时从此值重新加载（需 RELOAD 使能）。 */
        using RUNNING_COUNT = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 定时器当前递减计数值，16 位只读，计数过程中实时递减。 */
    } // namespace TIMCOUNT1

    /** @brief 定时器控制寄存器（数组，4 个实例），配置时钟源、预分频、自动重载、更新触发、极性、中断使能及中断状态。 */
    namespace TIMCTRL2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068060, 0x80068064, 0x80068068, 0x8006806C, LowLevel::Access::ReadWrite>;
        /** @brief SELECT 的取值。 */
        enum class SELECT_Values : std::uint32_t {
            NEVER_TICK = 0x0,
            PWM0 = 0x1,
            PWM1 = 0x2,
            PWM2 = 0x3,
            PWM3 = 0x4,
            PWM4 = 0x5,
            ROTARYA = 0x6,
            ROTARYB = 0x7,
            _32KHZ_XTAL = 0x8,
            _8KHZ_XTAL = 0x9,
            _4KHZ_XTAL = 0xA,
            _1KHZ_XTAL = 0xB,
            TICK_ALWAYS = 0xC,
        };
        using SELECT = LowLevel::Field<Reg, 0, 4, SELECT_Values>; /**< 定时器时钟源选择：NEVER_TICK=不选；PWM0~4=对应 PWM 通道；ROTARYA/B=旋钮输入；32KHZ_XTAL/8KHZ_XTAL/4KHZ_XTAL/1KHZ_XTAL=对应晶振；TICK_ALWAYS=始终滴答。 */
        /** @brief PRESCALE 的取值。 */
        enum class PRESCALE_Values : std::uint32_t {
            DIV_BY_1 = 0x0,
            DIV_BY_2 = 0x1,
            DIV_BY_4 = 0x2,
            DIV_BY_8 = 0x3,
        };
        using PRESCALE = LowLevel::Field<Reg, 4, 2, PRESCALE_Values>; /**< 定时器预分频选择：DIV_BY_1=1 分频；DIV_BY_2=2 分频；DIV_BY_4=4 分频；DIV_BY_8=8 分频。 */
        using RELOAD = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 自动重载使能，计数到零后自动从 FIXED_COUNT 重新加载并继续计数。 */
        using UPDATE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 更新控制位，置位后刷新计数值并使能计数器。 */
        using POLARITY = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 定时器极性控制位。 */
        using DUTY_CYCLE = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 占空比测量模式使能(仅TIMCTRL3)，置位时进入占空比测量模式，TIMCOUNT3记录高电平宽度。 */
        using DUTY_VALID = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 占空比数据有效标志(仅TIMCTRL3)，只读，硬件置位表示TIMCOUNT3中占空比数据有效。 */
        using IRQ_EN = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 定时器中断使能控制位，置位时允许计数到零产生中断。 */
        using IRQ = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 定时器中断状态标志，计数到零时置位。 */
        using TEST_SIGNAL = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< 被测信号源选择(仅TIMCTRL3占空比模式)，枚举值与SELECT字段相同。 */
    } // namespace TIMCTRL2

    /** @brief 定时器计数寄存器（数组，4 个实例），包含重载初值与当前递减计数值。 */
    namespace TIMCOUNT2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068070, 0x80068074, 0x80068078, 0x8006807C, LowLevel::Access::ReadWrite>;
        using FIXED_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 定时器重载初值，计数器归零时从此值重新加载（需 RELOAD 使能）。 */
        using RUNNING_COUNT = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 定时器当前递减计数值，16 位只读，计数过程中实时递减。 */
    } // namespace TIMCOUNT2

    /** @brief 定时器控制寄存器（数组，4 个实例），配置时钟源、预分频、自动重载、更新触发、极性、中断使能及中断状态。 */
    namespace TIMCTRL3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068080, 0x80068084, 0x80068088, 0x8006808C, LowLevel::Access::ReadWrite>;
        /** @brief SELECT 的取值。 */
        enum class SELECT_Values : std::uint32_t {
            NEVER_TICK = 0x0,
            PWM0 = 0x1,
            PWM1 = 0x2,
            PWM2 = 0x3,
            PWM3 = 0x4,
            PWM4 = 0x5,
            ROTARYA = 0x6,
            ROTARYB = 0x7,
            _32KHZ_XTAL = 0x8,
            _8KHZ_XTAL = 0x9,
            _4KHZ_XTAL = 0xA,
            _1KHZ_XTAL = 0xB,
            TICK_ALWAYS = 0xC,
        };
        using SELECT = LowLevel::Field<Reg, 0, 4, SELECT_Values>; /**< 定时器时钟源选择：NEVER_TICK=不选；PWM0~4=对应 PWM 通道；ROTARYA/B=旋钮输入；32KHZ_XTAL/8KHZ_XTAL/4KHZ_XTAL/1KHZ_XTAL=对应晶振；TICK_ALWAYS=始终滴答。 */
        /** @brief PRESCALE 的取值。 */
        enum class PRESCALE_Values : std::uint32_t {
            DIV_BY_1 = 0x0,
            DIV_BY_2 = 0x1,
            DIV_BY_4 = 0x2,
            DIV_BY_8 = 0x3,
        };
        using PRESCALE = LowLevel::Field<Reg, 4, 2, PRESCALE_Values>; /**< 定时器预分频选择：DIV_BY_1=1 分频；DIV_BY_2=2 分频；DIV_BY_4=4 分频；DIV_BY_8=8 分频。 */
        using RELOAD = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< 自动重载使能，计数到零后自动从 FIXED_COUNT 重新加载并继续计数。 */
        using UPDATE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< 更新控制位，置位后刷新计数值并使能计数器。 */
        using POLARITY = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< 定时器极性控制位。 */
        using DUTY_CYCLE = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< 占空比测量模式使能(仅TIMCTRL3)，置位时进入占空比测量模式，TIMCOUNT3记录高电平宽度。 */
        using DUTY_VALID = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< 占空比数据有效标志(仅TIMCTRL3)，只读，硬件置位表示TIMCOUNT3中占空比数据有效。 */
        using IRQ_EN = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< 定时器中断使能控制位，置位时允许计数到零产生中断。 */
        using IRQ = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< 定时器中断状态标志，计数到零时置位。 */
        using TEST_SIGNAL = LowLevel::Field<Reg, 16, 4, std::uint32_t>; /**< 被测信号源选择(仅TIMCTRL3占空比模式)，枚举值与SELECT字段相同。 */
    } // namespace TIMCTRL3

    /** @brief 定时器计数寄存器（数组，4 个实例），包含重载初值与当前递减计数值。 */
    namespace TIMCOUNT3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80068090, 0x80068094, 0x80068098, 0x8006809C, LowLevel::Access::ReadWrite>;
        using FIXED_COUNT = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 定时器重载初值，计数器归零时从此值重新加载（需 RELOAD 使能）。 */
        using RUNNING_COUNT = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< 定时器当前递减计数值，16 位只读，计数过程中实时递减。 */
    } // namespace TIMCOUNT3

    /** @brief TIMROT 版本寄存器，保存模块的步进、次要和主要版本号。 */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x800680A0, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< 步进版本号，16 位。 */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< 次要版本号，8 位。 */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< 主要版本号，8 位。 */
    } // namespace VERSION

} // namespace Hardware::Registers::TIMROT

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_TIMROT
