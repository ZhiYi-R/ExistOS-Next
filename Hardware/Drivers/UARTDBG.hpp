#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_UARTDBG
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_UARTDBG

/**
 * @file UARTDBG.hpp
 * @brief 调试串口(UARTDBG,PrimeCell PL011)驱动:波特率配置、帧格式、收发使能与非阻塞 I/O。
 *
 * STMP3770/i.MX23 的调试 UART 为 ARM PL011,无 SFTRST/CLKGATE(由总线时钟常开),寄存器
 * 均为普通整字读写。波特率由 IBRD(整数 16 位)+ FBRD(小数 6 位)分频决定:
 *   divisor = UARTCLK / (16 * baud);IBRD = 整数部分,FBRD = round(小数部分 * 64)。
 * PL011 要求改 IBRD/FBRD 后必须再写一次 LCR_H 才会锁存,本驱动的 Initialize 已按此时序。
 *
 * 本驱动为单例外设,以与 LowLevel::Register 同构的纯静态门面类呈现(无实例可构造)。I/O 一律
 * **非阻塞**:WriteByte/ReadByte 只做单条 DR 读写(触发),收发 FIFO 状态由 TransmitFifoFull/
 * ReceiveFifoEmpty/IsBusy 谓词查询,"轮询/超时"编排上移 OS,本层不自旋。
 *
 * 典型用法:
 *   `UARTDBG::Initialize(intDiv, fracDiv);`                       // 8N1 + FIFO,使能收发
 *   `if (!UARTDBG::TransmitFifoFull()) UARTDBG::WriteByte('A');`  // 非阻塞发送
 *   `if (!UARTDBG::ReceiveFifoEmpty()) c = UARTDBG::ReadByte();`  // 非阻塞接收
 *
 * @note 寄存器/字段取自生成头 Registers/UARTDBG.hpp;UARTCLK 频率由板级/调用方决定,
 *       本驱动只接受已算好的分频值,不在驱动体内引用频率常量。
 */

#include "Registers/UARTDBG.hpp"
#include <cstdint>

namespace Hardware::Drivers {

    /** @brief 调试串口(UARTDBG,PL011)驱动:纯静态门面,无实例。 */
    struct UARTDBG {
        UARTDBG() = delete;
        ~UARTDBG() = delete;
        UARTDBG(const UARTDBG&) = delete;
        UARTDBG& operator=(const UARTDBG&) = delete;

    private:
        using ControlRegister = Registers::UARTDBG::CR::Reg;          /**< 控制寄存器(UARTEN/TXE/RXE)。 */
        using IntegerBaudRegister = Registers::UARTDBG::IBRD::Reg;    /**< 整数分频寄存器。 */
        using FractionalBaudRegister = Registers::UARTDBG::FBRD::Reg; /**< 小数分频寄存器。 */
        using LineControlRegister = Registers::UARTDBG::LCR_H::Reg;   /**< 帧格式寄存器(WLEN/FEN)。 */
        using FlagRegister = Registers::UARTDBG::FR::Reg;             /**< 状态标志寄存器。 */
        using DataRegister = Registers::UARTDBG::DR::Reg;             /**< 收发数据寄存器。 */

    public:
        /** @brief 字长选择(对应 LCR_H.WLEN 的 2 位编码)。 */
        enum class WordLength : std::uint32_t {
            Bits5 = 0u, /**< 5 位数据。 */
            Bits6 = 1u, /**< 6 位数据。 */
            Bits7 = 2u, /**< 7 位数据。 */
            Bits8 = 3u, /**< 8 位数据。 */
        };

        // ====================== 配置 ======================

        /** @brief 关闭 UART(清 CR.UARTEN)。改波特率/帧格式前应先关闭。 */
        [[gnu::always_inline]] static void Disable() noexcept {
            ControlRegister::template ClearField<Registers::UARTDBG::CR::UARTEN>();
        }

        /**
         * @brief 设置波特率分频(写 IBRD 整数部分与 FBRD 小数部分)。
         *
         * 仅写分频寄存器,需随后写一次 LCR_H 才锁存(见 ConfigureFrame / Initialize)。
         * @param integerDivisor    16 位整数分频(IBRD.BAUD_DIVINT)。
         * @param fractionalDivisor 6 位小数分频(FBRD.BAUD_DIVFRAC)。
         */
        [[gnu::always_inline]] static void SetBaudDivisors(std::uint32_t integerDivisor,
                                                           std::uint32_t fractionalDivisor) noexcept {
            IntegerBaudRegister::template WriteField<Registers::UARTDBG::IBRD::BAUD_DIVINT>(integerDivisor);
            FractionalBaudRegister::template WriteField<Registers::UARTDBG::FBRD::BAUD_DIVFRAC>(fractionalDivisor);
        }

        /**
         * @brief 配置帧格式并锁存波特率(写 LCR_H 的 WLEN/FEN)。
         * @param wordLength 字长。
         * @param enableFifo 是否启用收发 FIFO(置 FEN)。
         */
        [[gnu::always_inline]] static void ConfigureFrame(WordLength wordLength, bool enableFifo) noexcept {
            LineControlRegister::template WriteFields<Registers::UARTDBG::LCR_H::WLEN,
                                                      Registers::UARTDBG::LCR_H::FEN>(
                static_cast<std::uint32_t>(wordLength), enableFifo ? 1u : 0u);
        }

        /** @brief 使能 UART 收发(置 CR.UARTEN/TXE/RXE,一次 RMW)。 */
        [[gnu::always_inline]] static void Enable() noexcept {
            ControlRegister::template WriteFields<Registers::UARTDBG::CR::UARTEN,
                                                  Registers::UARTDBG::CR::TXE,
                                                  Registers::UARTDBG::CR::RXE>(1u, 1u, 1u);
        }

        /**
         * @brief 一站式初始化:关闭→设分频→配 8 位帧+FIFO(锁存)→使能收发。
         * @param integerDivisor    16 位整数分频。
         * @param fractionalDivisor 6 位小数分频。
         * @param wordLength        字长(默认 8 位)。
         * @param enableFifo        是否启用 FIFO(默认启用)。
         */
        [[gnu::always_inline]] static void Initialize(std::uint32_t integerDivisor,
                                                      std::uint32_t fractionalDivisor,
                                                      WordLength wordLength = WordLength::Bits8,
                                                      bool enableFifo = true) noexcept {
            Disable();
            SetBaudDivisors(integerDivisor, fractionalDivisor);
            ConfigureFrame(wordLength, enableFifo);
            Enable();
        }

        // ====================== 状态查询(非阻塞谓词) ======================

        /** @brief 发送 FIFO 是否已满(读 FR.TXFF)。满时不可再写 DR。 */
        [[gnu::always_inline]] [[nodiscard]] static bool TransmitFifoFull() noexcept {
            return FlagRegister::template FieldIsSet<Registers::UARTDBG::FR::TXFF>();
        }

        /** @brief 接收 FIFO 是否为空(读 FR.RXFE)。空时无数据可读。 */
        [[gnu::always_inline]] [[nodiscard]] static bool ReceiveFifoEmpty() noexcept {
            return FlagRegister::template FieldIsSet<Registers::UARTDBG::FR::RXFE>();
        }

        /** @brief UART 是否仍在发送(读 FR.BUSY)。发送完成由其否定判定。 */
        [[gnu::always_inline]] [[nodiscard]] static bool IsBusy() noexcept {
            return FlagRegister::template FieldIsSet<Registers::UARTDBG::FR::BUSY>();
        }

        // ====================== 非阻塞 I/O ======================

        /**
         * @brief 非阻塞发送一字节:直接写 DR(单条 str)。
         *
         * 不检查 FIFO,调用前须由 `!TransmitFifoFull()` 谓词确认有空位(否则数据丢失);
         * "等空位"的轮询编排上移 OS,本层不自旋。
         * @param byte 待发送字节。
         */
        [[gnu::always_inline]] static void WriteByte(std::uint8_t byte) noexcept {
            DataRegister::Write(byte);
        }

        /**
         * @brief 非阻塞接收一字节:直接读 DR.DATA(单条 ldr)。
         *
         * 不检查 FIFO,调用前须由 `!ReceiveFifoEmpty()` 谓词确认有数据;"等数据"的轮询
         * 编排上移 OS,本层不自旋。
         * @return 收到的字节(低 8 位)。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint8_t ReadByte() noexcept {
            return static_cast<std::uint8_t>(DataRegister::template ReadField<Registers::UARTDBG::DR::DATA>());
        }
    };

} // namespace Hardware::Drivers

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_UARTDBG
