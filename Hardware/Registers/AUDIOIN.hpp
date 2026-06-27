#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_AUDIOIN
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_AUDIOIN

/**
 * @file AUDIOIN.hpp
 * @brief AUDIOIN 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 音频 ADC 输入(麦克风/线路输入采集与 DMA 控制)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::AUDIOIN {

    /** @brief AUDIOIN Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C000, 0x8004C004, 0x8004C008, 0x8004C00C, LowLevel::Access::ReadWrite>;
        using RUN = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< AUDIOIN Enable. Setting to 1 starts data conversion; DMA request made after 8 words collected. Clearing to 0 stops conversion and sets CLKGATE. */
        using FIFO_ERROR_IRQ_EN = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< FIFO Error Interrupt Enable. Set to 1 to enable interrupt request when FIFO overflow or underflow status bits are set. */
        using FIFO_OVERFLOW_IRQ = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< FIFO Overflow Interrupt Status Bit. Set by hardware on FIFO overflow due to unserviced DMA request. Cleared by writing 1 to SET/CLR address. */
        using FIFO_UNDERFLOW_IRQ = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< FIFO Underflow Interrupt Status Bit. Set by hardware on FIFO underflow. Cleared by writing 1 to SET/CLR address. IRQ issued if FIFO_ERROR_IRQ_EN=1. */
        using LOOPBACK = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< AUDIOOUT-to-AUDIOIN Loopback Enable. Setting to 1 connects AUDIOOUT serial data to AUDIOIN CIC input, bypassing analog DAC and ADC. */
        using WORD_LENGTH = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< PCM Audio Bit Size Select. 0 = 32-bit PCM samples, 1 = 16-bit samples. 24-bit FIR output is sign-extended to 32 or truncated to 16. */
        using HPF_ENABLE = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< ADC High-Pass Filter Enable. When set, enables the ADC analog high-pass filter. Used with OFFSET_ENABLE for DC offset removal. */
        using OFFSET_ENABLE = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< ADC Analog High-Pass Filter Offset Calculation Enable. When set, the HPF actively adjusts serial audio input removing DC offset. Requires HPF_ENABLE=1. */
        using INVERT_1BIT = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Invert Serial Audio Input Enable. When set, inverts the 1-bit serial input of both channels from the ADC sigma-delta modulator. */
        using EDGE_SYNC = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Serial Input Clock Edge Sync Select. 0 = Rising edge, 1 = Falling edge for CIC filter data receive synchronization. */
        using LR_SWAP = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< Left/Right Input Channel Swap Enable. Setting to 1 swaps the left and right serial audio inputs from the ADC before CIC block processing. */
        using DMAWAIT_COUNT = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< DMA Request Delay Count. Specifies number of APBX clock cycles (0-31) to delay before each DMA request. Acts as bandwidth throttle for DIGFILT. */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< AUDIOIN Clock Gate Enable. When set to 1, gates off clocks to DIGFILT portions controlling input audio functions. Does not affect AUDIOOUT. Clear to 0 for normal operation. */
        using SFTRST = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< AUDIOIN Module Soft Reset. Setting to 1 forces reset to DIGFILT portions that control audio input and gates clocks off. Must be cleared to 0 for normal operation. */
    } // namespace CTRL

    /** @brief AUDIOIN Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C010, 0x8004C014, 0x8004C018, 0x8004C01C, LowLevel::Access::ReadWrite>;
        using ADC_PRESENT = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< AUDIOIN Functionality Present. Set to 1 in products that include AUDIOIN/ADC. If 0, the AUDIOIN/ADC is permanently disabled. */
    } // namespace STAT

    /** @brief AUDIOIN Sample Rate Register */
    namespace ADCSRR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C020, 0x8004C024, 0x8004C028, 0x8004C02C, LowLevel::Access::ReadWrite>;
        using SRC_FRAC = LowLevel::Field<Reg, 0, 13, std::uint32_t>; /**< Sample Rate Conversion Fraction Factor. Fractional portion of divide term. Reset 0x37. Used in sample rate equation. */
        using SRC_INT = LowLevel::Field<Reg, 16, 5, std::uint32_t>; /**< Sample Rate Conversion Integer Factor. Integer portion of divide term. Reset 0x11. Used in sample rate equation. */
        using SRC_HOLD = LowLevel::Field<Reg, 24, 3, std::uint32_t>; /**< Sample Rate Conversion Hold Factor. Used to generate half/quarter sample rates. Equation: output_sample_rate = (6e6 * BASEMULT) / (SRC_INT.SRC_FRAC * 8 * (SRC_HOLD+1)). */
        /** @brief BASEMULT 的取值。 */
        enum class BASEMULT_Values : std::uint32_t {
            SINGLE_RATE = 0x1,
            DOUBLE_RATE = 0x2,
            QUAD_RATE = 0x4,
        };
        using BASEMULT = LowLevel::Field<Reg, 28, 3, BASEMULT_Values>; /**< Base Sample Rate Multiplier. 0x1 = Single (48/44.1/32 kHz), 0x2 = Double (96/88.2/64 kHz), 0x4 = Quad (192/176.4/128 kHz). */
        /** @brief OSR 的取值。 */
        enum class OSR_Values : std::uint32_t {
            OSR6 = 0x0,
            OSR12 = 0x1,
        };
        using OSR = LowLevel::Field<Reg, 31, 1, OSR_Values>; /**< AUDIOIN Oversample Rate (read-only). 0x0 = 6 MHz, 0x1 = 12 MHz. Fixed at 6 MHz for STMP3770. */
    } // namespace ADCSRR

    /** @brief AUDIOIN Volume Register */
    namespace ADCVOLUME {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C030, 0x8004C034, 0x8004C038, 0x8004C03C, LowLevel::Access::ReadWrite>;
        using VOLUME_RIGHT = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< Right Channel Volume Setting. Range -0.5 dB (0xFE reset) to -100 dB (0x37). Each increment = +0.5 dB. Values 0x00-0x37 = -100 dB. 0xFF reserved. */
        using VOLUME_UPDATE_RIGHT = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< Right Channel Volume Update Pending. Set by hardware when volume update is pending (waiting on zero-crossing on right channel). Not used when EN_ZCD=0. */
        using VOLUME_LEFT = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Left Channel Volume Setting. Range -0.5 dB (0xFE reset) to -100 dB (0x37). Each increment = +0.5 dB. Values 0x00-0x37 = -100 dB. 0xFF reserved. */
        using EN_ZCD = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< Enable Zero-Cross Detect. When enabled, volume changes are applied only on zero-crossing. When disabled, changes take effect immediately. */
        using VOLUME_UPDATE_LEFT = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< Left Channel Volume Update Pending. Set by hardware when volume update is pending (waiting on zero-crossing on left channel). Not used when EN_ZCD=0. */
    } // namespace ADCVOLUME

    /** @brief AUDIOIN Debug Register */
    namespace ADCDEBUG {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C040, 0x8004C044, 0x8004C048, 0x8004C04C, LowLevel::Access::ReadWrite>;
        using FIFO_STATUS = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< FIFO Status. Set when AUDIOIN FIFO contains any valid data. Cleared when FIFO is empty. */
        using DMA_PREQ = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< DMA Request Status. Reflects AUDIOIN DMA request signal state. Can be polled to manually move samples when DMA channel not used. */
        using SET_INTERRUPT3_HAND_SHAKE = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Interrupt[3] Status. Reflects APBX interface state machine internal interrupt[3] for DigFilt DMA channel priority. Test only. */
        using ADC_DMA_REQ_HAND_SHAKE_CLK_CROSS = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< DMA Request Sync Status. Reflects state of second flop in the sync chain for AUDIOIN DMA request (24 MHz to APBX clock domain). Test only. */
        using ENABLE_ADCDMA = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< AUDIOIN Digital Path Test Enable. For debug only. Causes serial audio data to bypass CIC block and transfer via AUDIOOUT DMA Channel 1. */
    } // namespace ADCDEBUG

    /** @brief ADC Mux Volume and Select Control Register */
    namespace ADCVOL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C050, 0x8004C054, 0x8004C058, 0x8004C05C, LowLevel::Access::ReadWrite>;
        using GAIN_RIGHT = LowLevel::Field<Reg, 0, 4, std::uint32_t>; /**< Right Channel ADC Gain. Each increment = 1.5 dB. 0x0 = 0 dB, 0x1 = 1.5 dB, ... up to 0xF = 22.5 dB. */
        using SELECT_RIGHT = LowLevel::Field<Reg, 4, 2, std::uint32_t>; /**< ADC Right Channel Input Source Select. 00 = Microphone, 01 = Line1, 10 = Headphone, 11 = Reserved. */
        using GAIN_LEFT = LowLevel::Field<Reg, 8, 4, std::uint32_t>; /**< Left Channel ADC Gain. Each increment = 1.5 dB. 0x0 = 0 dB, 0x1 = 1.5 dB, ... up to 0xF = 22.5 dB. */
        using SELECT_LEFT = LowLevel::Field<Reg, 12, 2, std::uint32_t>; /**< ADC Left Channel Input Source Select. 00 = Microphone, 01 = Line1, 10 = Headphone, 11 = Reserved. */
        using MUTE = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< ADC Mute. 0 = Unmute, 1 = Mute. When set, mutes both left and right channel analog inputs. */
        using EN_ADC_ZCD = LowLevel::Field<Reg, 25, 1, std::uint32_t>; /**< Enable Zero-Cross Detect for ADC Amplifier. */
        using VOLUME_UPDATE_PENDING = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< Volume Update Pending. Set when ADC left or right volume update is pending (waiting on zero-crossing). Cleared when both gains are applied. */
    } // namespace ADCVOL

    /** @brief Microphone and Line Control Register */
    namespace MICLINE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C060, 0x8004C064, 0x8004C068, 0x8004C06C, LowLevel::Access::ReadWrite>;
        using MIC_GAIN = LowLevel::Field<Reg, 0, 2, std::uint32_t>; /**< Microphone Gain. 00 = 0 dB, 01 = 20 dB, 10 = 30 dB, 11 = 40 dB. */
        using MIC_CHOPCLK = LowLevel::Field<Reg, 4, 2, std::uint32_t>; /**< Microphone Amplifier Chopping Clock. 00 = Disabled, 01 = 192 kHz, 10 = 96 kHz, 11 = 48 kHz. */
        using MIC_BIAS = LowLevel::Field<Reg, 16, 3, std::uint32_t>; /**< Microphone Bias Voltage Select. 0 = 1.21 V, 1 = 1.46 V, up to 7 = 2.96 V (0.25 V increments). */
        using MIC_RESISTOR = LowLevel::Field<Reg, 20, 2, std::uint32_t>; /**< Microphone Bias Resistor Select. 00 = Off, 01 = 2 KOhm, 10 = 4 KOhm, 11 = 8 KOhm. ADC block must be powered on before Micbias. */
        using MIC_SELECT = LowLevel::Field<Reg, 24, 1, std::uint32_t>; /**< Microphone Bias Pin Select. When MIC_RESISTOR enabled, selects Micbias voltage reference pin source. 0 = LRADC0, 1 = LRADC1. */
        using DIVIDE_LINE2 = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< 线路输入2分压控制。 */
        using DIVIDE_LINE1 = LowLevel::Field<Reg, 29, 1, std::uint32_t>; /**< Attenuate Line1 Input. With 10K external series resistor, attenuates Line1 by 9.5 dB (+/-1.5 dB) for 2-Vrms input. Affects both channels of ADC and headphone. */
    } // namespace MICLINE

    /** @brief Analog Clock Control Register */
    namespace ANACLKCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C070, 0x8004C074, 0x8004C078, 0x8004C07C, LowLevel::Access::ReadWrite>;
        using ADCDIV = LowLevel::Field<Reg, 0, 3, std::uint32_t>; /**< ADC Analog Clock Divider. Selects oversampling clock rate: 000=6 MHz, 001=4 MHz, 010/100=3 MHz, 011/101=2 MHz, 110=1.5 MHz, 111=1 MHz. */
        using INVERT_ADCCLK = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< ADC Clock Invert. Set to invert ADC_CLK for the sigma-delta converter and associated digital filters. */
        using SLOW_DITHER = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< Slow Dither. When dither enabled (DITHER_OFF=0) and this bit set, ADC input signal dithering is slowed to half rate. */
        using DITHER_OFF = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< ADC Dither Disable. When set, dither is disabled within the ADC. */
        using CLKGATE = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< Analog Clock Gate. Set to gate the clocks for the ADC converter and associated digital filter. */
    } // namespace ANACLKCTRL

    /** @brief AUDIOIN Read Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x8004C080, 0x8004C084, 0x8004C088, 0x8004C08C, LowLevel::Access::ReadWrite>;
        using LOW = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< Left Sample or Sample Low Half-Word. 16-bit mode: left channel sample. 32-bit mode: least significant 16 bits of sample. */
        using HIGH = LowLevel::Field<Reg, 16, 16, std::uint32_t>; /**< Right Sample or Sample High Half-Word. 16-bit mode: right channel sample. 32-bit mode: most significant 16 bits of sample. */
    } // namespace DATA

} // namespace Hardware::Registers::AUDIOIN

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_AUDIOIN
