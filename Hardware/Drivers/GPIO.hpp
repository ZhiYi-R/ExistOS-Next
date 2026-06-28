#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_GPIO
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_GPIO

/**
 * @file GPIO.hpp
 * @brief 编译期参数化的 GPIO 门面:GPIO<Bank, Pin>,引脚在类型层面固定,零开销。
 *
 * STMP3770/i.MX23 的引脚控制(PINCTRL)对 GPIO 操作的寄存器几何如下(已对生成头核对):
 *  - 复用选择 MUXSEL:每引脚 2 位,Bank b 的引脚 p 落在 MUXSEL{2*b + p/16} 的
 *    位偏移 (p%16)*2 处。寄存器地址取自生成头,2 位均匀步距为架构保证。
 *  - 方向 DOE / 输出 DOUT / 输入 DIN:每 Bank 一个寄存器,内部是一个宽位域(无逐引脚
 *    Field),故方向/读写用"原子位别名 + (1u<<Pin)":单条 str/ldr,零开销。
 *
 * 驱动强度 DRIVE 与上拉 PULL 的字段布局高度不规则(并非每引脚都存在、且跨寄存器乱序
 * 排布),无法对每引脚干净参数化,故本门面不提供 SetDrive/SetPull;需要时调用方直接
 * 使用 Registers/PINCTRL.hpp 中该引脚对应的具体 DRIVEn/PULLn 字段别名。
 *
 * @note 所有寄存器后端均取自生成头 Registers/PINCTRL.hpp,绝不硬编码地址。
 */

#include "Registers/PINCTRL.hpp"
#include "Field.hpp"
#include <cstdint>
#include <type_traits>

namespace Hardware::Drivers {

    namespace Detail {

        /**
         * @brief MUXSEL 寄存器序号 → 生成头 MUXSEL{Index} 后端的编译期选择(consteval 链)。
         *
         * 以 `std::type_identity` 包装"序号→类型"的映射,替代曾经的 `##` token 拼接宏:
         * 编译期按 Index 选出对应 MUXSEL{Index}::Reg,非法序号无分支返回、实例化即失败。
         * @tparam Index MUXSEL 寄存器序号(0–7)。
         */
        template <std::uint32_t Index>
        [[nodiscard]] consteval auto SelectMuxSelectRegister() noexcept {
            if constexpr (Index == 0u) return std::type_identity<Registers::PINCTRL::MUXSEL0::Reg>{};
            else if constexpr (Index == 1u) return std::type_identity<Registers::PINCTRL::MUXSEL1::Reg>{};
            else if constexpr (Index == 2u) return std::type_identity<Registers::PINCTRL::MUXSEL2::Reg>{};
            else if constexpr (Index == 3u) return std::type_identity<Registers::PINCTRL::MUXSEL3::Reg>{};
            else if constexpr (Index == 4u) return std::type_identity<Registers::PINCTRL::MUXSEL4::Reg>{};
            else if constexpr (Index == 5u) return std::type_identity<Registers::PINCTRL::MUXSEL5::Reg>{};
            else if constexpr (Index == 6u) return std::type_identity<Registers::PINCTRL::MUXSEL6::Reg>{};
            else if constexpr (Index == 7u) return std::type_identity<Registers::PINCTRL::MUXSEL7::Reg>{};
        }

        /** @brief 序号→MUXSEL 寄存器后端类型(由 SelectMuxSelectRegister 提取)。 */
        template <std::uint32_t Index>
        using MuxSelectRegister = typename decltype(SelectMuxSelectRegister<Index>())::type;

        /**
         * @brief Bank 号 → 该 Bank 输出数据寄存器 DOUT{Bank} 后端的编译期选择。
         * @tparam Bank GPIO Bank 号(0–2)。
         */
        template <std::uint32_t Bank>
        [[nodiscard]] consteval auto SelectBankDataOutput() noexcept {
            if constexpr (Bank == 0u) return std::type_identity<Registers::PINCTRL::DOUT0::Reg>{};
            else if constexpr (Bank == 1u) return std::type_identity<Registers::PINCTRL::DOUT1::Reg>{};
            else if constexpr (Bank == 2u) return std::type_identity<Registers::PINCTRL::DOUT2::Reg>{};
        }

        /**
         * @brief Bank 号 → 该 Bank 方向寄存器 DOE{Bank} 后端的编译期选择。
         * @tparam Bank GPIO Bank 号(0–2)。
         */
        template <std::uint32_t Bank>
        [[nodiscard]] consteval auto SelectBankOutputEnable() noexcept {
            if constexpr (Bank == 0u) return std::type_identity<Registers::PINCTRL::DOE0::Reg>{};
            else if constexpr (Bank == 1u) return std::type_identity<Registers::PINCTRL::DOE1::Reg>{};
            else if constexpr (Bank == 2u) return std::type_identity<Registers::PINCTRL::DOE2::Reg>{};
        }

        /**
         * @brief Bank 号 → 该 Bank 输入数据寄存器 DIN{Bank} 后端的编译期选择。
         * @tparam Bank GPIO Bank 号(0–2)。
         */
        template <std::uint32_t Bank>
        [[nodiscard]] consteval auto SelectBankDataInput() noexcept {
            if constexpr (Bank == 0u) return std::type_identity<Registers::PINCTRL::DIN0::Reg>{};
            else if constexpr (Bank == 1u) return std::type_identity<Registers::PINCTRL::DIN1::Reg>{};
            else if constexpr (Bank == 2u) return std::type_identity<Registers::PINCTRL::DIN2::Reg>{};
        }

        /** @brief Bank→DOUT/DOE/DIN 后端类型(由对应 Select 函数提取)。 */
        template <std::uint32_t Bank>
        using BankDataOutput = typename decltype(SelectBankDataOutput<Bank>())::type;
        template <std::uint32_t Bank>
        using BankOutputEnable = typename decltype(SelectBankOutputEnable<Bank>())::type;
        template <std::uint32_t Bank>
        using BankDataInput = typename decltype(SelectBankDataInput<Bank>())::type;

    } // namespace Detail

    /**
     * @brief 编译期固定 (Bank, Pin) 的 GPIO 纯静态门面。
     *
     * 用法:`using LcdReset = GPIO<1, 18>; LcdReset::ConfigureAsOutput(); LcdReset::SetHigh();`
     * 方向/读写均编译为单条原子 MMIO 指令;复用选择为一次配置期 RMW。
     *
     * @tparam Bank GPIO Bank 号(0–2)。
     * @tparam Pin  Bank 内引脚号(0–31)。
     */
    template <std::uint32_t Bank, std::uint32_t Pin>
        requires(Bank <= 2u && Pin <= 31u)
    struct GPIO {
        GPIO() = delete;
        ~GPIO() = delete;
        GPIO(const GPIO&) = delete;
        GPIO& operator=(const GPIO&) = delete;

        /** @brief 复用功能选择值:0–3,值 3 通常为 GPIO 模式。 */
        enum class MuxFunction : std::uint32_t {
            Function0 = 0u, /**< 复用功能 0(通常为主复用外设)。 */
            Function1 = 1u, /**< 复用功能 1。 */
            Function2 = 2u, /**< 复用功能 2。 */
            Gpio = 3u,      /**< 复用功能 3:GPIO 模式。 */
        };

    private:
        /** @brief 本引脚所属 MUXSEL 寄存器序号:Bank 占 2 个寄存器,低/高 16 引脚各一。 */
        static constexpr std::uint32_t MuxRegisterIndex = 2u * Bank + (Pin / 16u);
        /** @brief 本引脚在 MUXSEL 寄存器内的位偏移:每引脚 2 位。 */
        static constexpr std::uint32_t MuxBitOffset = (Pin % 16u) * 2u;

        using MuxRegister = Detail::MuxSelectRegister<MuxRegisterIndex>;
        /** @brief 本引脚的 2 位复用字段(后端地址来自生成头,2 位步距为架构保证)。 */
        using MuxField = LowLevel::Field<MuxRegister, static_cast<LowLevel::Bit>(MuxBitOffset), 2u,
                                         MuxFunction>;

        using DataOutput = Detail::BankDataOutput<Bank>;
        using OutputEnable = Detail::BankOutputEnable<Bank>;
        using DataInput = Detail::BankDataInput<Bank>;

        /** @brief 本引脚在 DOUT/DOE/DIN 宽位域中的位掩码。 */
        static constexpr std::uint32_t PinMask = 1u << Pin;

    public:
        /**
         * @brief 设置引脚复用功能(配置期一次 RMW 写 2 位 MUXSEL 字段)。
         * @param function 复用功能选择。
         */
        [[gnu::always_inline]] static void SetMux(MuxFunction function) noexcept {
            MuxRegister::template WriteField<MuxField>(function);
        }

        /** @brief 把引脚复用为 GPIO 模式(MUXSEL 写 3)。 */
        [[gnu::always_inline]] static void SetMuxToGpio() noexcept {
            SetMux(MuxFunction::Gpio);
        }

        /**
         * @brief 设置引脚方向(置/清 DOE 对应位,单条原子 str)。
         * @param output true=输出,false=输入/高阻。
         */
        [[gnu::always_inline]] static void SetDirection(bool output) noexcept {
            if (output) {
                OutputEnable::Set(PinMask);
            } else {
                OutputEnable::Clear(PinMask);
            }
        }

        /** @brief 配置引脚为输出方向(置 DOE 对应位,单条原子 str)。 */
        [[gnu::always_inline]] static void ConfigureAsOutput() noexcept {
            OutputEnable::Set(PinMask);
        }

        /** @brief 配置引脚为输入方向(清 DOE 对应位,单条原子 str)。 */
        [[gnu::always_inline]] static void ConfigureAsInput() noexcept {
            OutputEnable::Clear(PinMask);
        }

        /**
         * @brief 写输出电平(置/清 DOUT 对应位,单条原子 str)。
         * @param high true=高电平,false=低电平。
         */
        [[gnu::always_inline]] static void Write(bool high) noexcept {
            if (high) {
                DataOutput::Set(PinMask);
            } else {
                DataOutput::Clear(PinMask);
            }
        }

        /** @brief 输出置高(置 DOUT 对应位,单条原子 str)。 */
        [[gnu::always_inline]] static void SetHigh() noexcept { DataOutput::Set(PinMask); }
        /** @brief 输出置低(清 DOUT 对应位,单条原子 str)。 */
        [[gnu::always_inline]] static void SetLow() noexcept { DataOutput::Clear(PinMask); }
        /** @brief 输出翻转(翻转 DOUT 对应位,单条原子 str)。 */
        [[gnu::always_inline]] static void Toggle() noexcept { DataOutput::Toggle(PinMask); }

        /**
         * @brief 读取引脚输入电平(读 DIN 整字后与本引脚掩码相与)。
         * @return 引脚为高返回 true。
         */
        [[gnu::always_inline]] [[nodiscard]] static bool Read() noexcept {
            return (DataInput::Read() & PinMask) != 0u;
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_GPIO
