#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_AUDIOOUT
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_AUDIOOUT

/**
 * @file AUDIOOUT.hpp
 * @brief AUDIOOUT 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 音频 DAC 输出(耳机/线路输出的音量、滤波与 DMA 控制)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::AUDIOOUT {

    /** @brief AUDIOOUT Control Register */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048000, 0x80048004, 0x80048008, 0x8004800C, LowLevel::Access::ReadWrite>;
        using RUN = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< AUDIOOUT Enable. Set to 1 to start operation with DMA request. Clear to 0 stops conversion and sets CLKGATE. */
        using FIFO_ERROR_IRQ_EN = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< FIFO Error Interrupt Enable. Enables interrupt when overflow or underflow status bits are set. */
        using FIFO_OVERFLOW_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< FIFO Overflow Interrupt Status. Set by hardware on FIFO overflow. Clear by writing 1 to CLR register. */
        using FIFO_UNDERFLOW_IRQ = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< FIFO Underflow Interrupt Status. Set by hardware on FIFO underflow. Clear by writing 1 to CLR register. */
        using LOOPBACK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< AUDIOIN-to-AUDIOOUT Loopback Enable. Routes AUDIOIN FIFO data to AUDIOOUT FIFO for test. */
        using DAC_ZERO_ENABLE = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Quiet Output Enable. Causes SDM to transmit alternating ones and zeros for pop-suppression. Reset by power-on reset only. */
        using WORD_LENGTH = LowLevel::Field<Reg, LowLevel::Bit::Bit6, 1, std::uint32_t>; /**< PCM Audio Bit Size Select. 0=32-bit PCM samples, 1=16-bit samples. */
        using SS3D_EFFECT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 2, std::uint32_t>; /**< Virtual 3D Effect Enable. Subtracts opposite channel content. 00=Off, 01=Low (3dB), 10=Medium (4.5dB), 11=High (6dB). */
        using INVERT_1BIT = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Invert Serial Audio Output Enable. Inverts the 1-bit serial output of both channels to the sigma-delta modulator. */
        using EDGE_SYNC = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Serial Output Clock Edge Sync Select. 0=Rising edge, 1=Falling edge for SDM synchronization. */
        using LR_SWAP = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Left/Right Output Channel Swap Enable. When set, swaps left and right serial audio outputs from SDM to analog DAC. */
        using DMAWAIT_COUNT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, std::uint32_t>; /**< DMA Request Delay Count. Specifies number of APBX clock cycles (0 to 31) to delay before each DMA request. Acts as a bandwidth throttle. */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit30, 1, std::uint32_t>; /**< Clock Gate Enable. When set to 1, gates off clocks to DIGFILT portions controlling only output audio functions. Clear to 0 for normal operation. */
        using SFTRST = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Module Soft Reset. Set to 1 to force reset to portions of DIGFILT controlling AUDIOOUT, then gates clocks off. Clear to 0 for normal operation. */
    } // namespace CTRL

    /** @brief AUDIOOUT Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048010, 0x80048014, 0x80048018, 0x8004801C, LowLevel::Access::ReadWrite>;
        using DAC_PRESENT = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< AUDIOOUT Functionality Present. Set to 1 if DAC is present. 0 means permanently disabled. */
    } // namespace STAT

    /** @brief AUDIOOUT Sample Rate Register */
    namespace DACSRR {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048020, 0x80048024, 0x80048028, 0x8004802C, LowLevel::Access::ReadWrite>;
        using SRC_FRAC = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 13, std::uint32_t>; /**< Sample Rate Conversion Fraction Factor. Fractional portion of divide term for sample rate conversion. */
        using SRC_INT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 5, std::uint32_t>; /**< Sample Rate Conversion Integer Factor. Integer portion of divide term for sample rate conversion. */
        using SRC_HOLD = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 3, std::uint32_t>; /**< Sample Rate Conversion Hold Factor. Used to generate half/quarter sample rates. */
        /** @brief BASEMULT 的取值。 */
        enum class BASEMULT_Values : std::uint32_t {
            SINGLE_RATE = 0x1,
            DOUBLE_RATE = 0x2,
            QUAD_RATE = 0x4,
        };
        using BASEMULT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 3, BASEMULT_Values>; /**< Base Sample Rate Multiplier. 0x1=Single (48/44.1/32 kHz), 0x2=Double (96/88.2/64 kHz), 0x4=Quad (192/176.4/128 kHz). */
        /** @brief OSR 的取值。 */
        enum class OSR_Values : std::uint32_t {
            OSR6 = 0x0,
            OSR12 = 0x1,
        };
        using OSR = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, OSR_Values>; /**< Oversample Rate. Fixed at 6 MHz for STMP3770. 0x0=6 MHz, 0x1=12 MHz. */
    } // namespace DACSRR

    /** @brief AUDIOOUT Volume Register */
    namespace DACVOLUME {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048030, 0x80048034, 0x80048038, 0x8004803C, LowLevel::Access::ReadWrite>;
        using VOLUME_RIGHT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< Right Channel Volume Setting. -0.5dB (0xFE) to -100dB (0x37). Each increment = +0.5dB. */
        using MUTE_RIGHT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Mute Right Channel. 0=Unmute, 1=Mute. Applied immediately. */
        using VOLUME_UPDATE_RIGHT = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Right Channel Volume Update Pending. Set by hardware when volume update pending on right channel zero-crossing. */
        using VOLUME_LEFT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Left Channel Volume Setting. -0.5dB (0xFE) to -100dB (0x37). Each increment = +0.5dB. */
        using MUTE_LEFT = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Mute Left Channel. 0=unmute, 1=mute. Applied immediately. */
        using EN_ZCD = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Enable Zero-Cross Detect. When enabled, volume changes applied only at zero-crossing. */
        using VOLUME_UPDATE_LEFT = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Left Channel Volume Update Pending. Set by hardware when volume update pending on left channel zero-crossing. */
    } // namespace DACVOLUME

    /** @brief AUDIOOUT Debug Register */
    namespace DACDEBUG {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048040, 0x80048044, 0x80048048, 0x8004804C, LowLevel::Access::ReadWrite>;
        using FIFO_STATUS = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< FIFO Status. Set when FIFO has empty entries, cleared when full. */
        using DMA_PREQ = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< DMA Request Status. Current state of AUDIOOUT DMA request signal. Can be polled for manual FIFO filling. */
        using SET_INTERRUPT0_HAND_SHAKE = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Interrupt[0] Status. State of APBX interface state machine interrupt[0] signal. Test only. */
        using SET_INTERRUPT1_HAND_SHAKE = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< Interrupt[1] Status. State of APBX interface state machine interrupt[1] signal. Test only. */
        using SET_INTERRUPT0_CLK_CROSS = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Interrupt[0] Sync Status. State of sync flop chain for interrupt[0] signal. Test only. */
        using SET_INTERRUPT1_CLK_CROSS = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Interrupt[1] Sync Status. State of sync flop chain for interrupt[1] signal. Test only. */
        using RAM_SS = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< DIGFILT RAM Speed Select. Sense AMP timing control. Do not alter unless instructed by SigmaTel. */
        using ENABLE_DACDMA = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Digital Path Test Enable. Bypasses DAC analog for debug; transfers serial audio data via AUDIOIN DMA Channel 0. */
    } // namespace DACDEBUG

    /** @brief Headphone Volume and Select Control Register */
    namespace HPVOL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048050, 0x80048054, 0x80048058, 0x8004805C, LowLevel::Access::ReadWrite>;
        using VOL_RIGHT = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 7, std::uint32_t>; /**< Right Headphone Volume Control. 0.5dB steps. Same ranges as VOL_LEFT. Reset=0x0C (0dB). Power-on reset only. */
        using VOL_LEFT = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 7, std::uint32_t>; /**< Left Headphone Volume Control. 0.5dB steps. DAC mode: 0x00=+6dB to 0x7F=-57.5dB. Line1 mode: 0x00=+12dB to 0x7F=-51.5dB. Reset=0x0C (0dB). Power-on reset only. */
        using SELECT = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Input Signal Select. 0=DAC, 1=Line1. Reset by power-on reset only. */
        using MUTE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Headphone Mute. Reset by power-on reset only. */
        using EN_MSTR_ZCD = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Enable Zero-Cross Detect for Headphone Amplifier. */
        using VOLUME_UPDATE_PENDING = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Volume Update Pending. Set when headphone volume update waiting on zero-crossing. */
    } // namespace HPVOL

    /** @brief Reserved Register */
    namespace RESERVED {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048060, 0x80048064, 0x80048068, 0x8004806C, LowLevel::Access::ReadWrite>;
    } // namespace RESERVED

    /** @brief Audio Power-Down Control Register */
    namespace PWRDN {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048070, 0x80048074, 0x80048078, 0x8004807C, LowLevel::Access::ReadWrite>;
        using HEADPHONE = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Master (Headphone) Power Down. Reset by power-on reset only. */
        using CAPLESS = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Power Down Headphone Common Amplifier for Capless Headphone. Reset by power-on reset only. */
        using ADC = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 1, std::uint32_t>; /**< Power Down ADC and Input Mux Circuitry. ADC function; reset by ADC SFTRST. */
        using DAC = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Power Down DAC Analog Circuitry. Reset by power-on reset only. */
        using RIGHT_ADC = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 1, std::uint32_t>; /**< Right ADC Power Down. Powers down ADC right channel for mono operation. ADC function; reset by ADC SFTRST. */
        using SELFBIAS = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 1, std::uint32_t>; /**< Currently does not control any logic; altering has no effect. */
        using SPEAKER = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 扬声器功放掉电，写1关闭以省电。 */
    } // namespace PWRDN

    /** @brief AUDIOOUT Reference Control Register */
    namespace REFCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048080, 0x80048084, 0x80048088, 0x8004808C, LowLevel::Access::ReadWrite>;
        using DAC_ADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 3, std::uint32_t>; /**< These bits have no effect. */
        using VAG_VAL = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 4, std::uint32_t>; /**< VAG Reference Value. When ADJ_VAG=1: 0x7=1.0V, 0x0=0.825V, 25mV steps. Affected by RAISE_REF. Power-on reset only. */
        using ADC_REFVAL = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 4, std::uint32_t>; /**< ADC Reference Value. When ADJ_ADC=1: 0x7=1.60V, 0x0=1.425V, 25mV steps. Affected by RAISE_REF. */
        using ADJ_VAG = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< VAG select. 0=VDD/2 (resistor divider). 1=controlled by VAG_VAL. Controls both DAC and ADC. Power-on reset only. */
        using ADJ_ADC = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< ADC Reference Voltage Adjust. 0=1.5V/1.31V fixed ref. 1=controlled by ADC_REFVAL. Must be set when both ADC and DAC enabled. */
        using VDDXTAL_TO_VDDD = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 1, std::uint32_t>; /**< Shorts XTAL oscillator supply to VDDD to reduce power. ADC function; reset by ADC SFTRST. */
        using BIAS_CTRL = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 2, std::uint32_t>; /**< Bias current control for all analog blocks. 00=Nominal, 01=-20%, 10=-10%, 11=+10%. Test/debug only. Power-on reset only. */
        using LW_REF = LowLevel::Field<Reg, LowLevel::Bit::Bit18, 1, std::uint32_t>; /**< This bit currently does not control any logic; altering its value has no effect. */
        using LOW_PWR = LowLevel::Field<Reg, LowLevel::Bit::Bit19, 1, std::uint32_t>; /**< Lowers bandgap amplifier power (~100uA). Useful in USB suspend/standby. Power-on reset only. */
        using VBG_ADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 3, std::uint32_t>; /**< VBG adjustment. Affects ALL references. 000=Nominal, 001=+0.3%, 010=+0.6%, 011=+0.85%, 100=-0.3%, 101=-0.6%, 110=-0.9%, 111=-1.2%. Power-on reset only. */
        using XTAL_BGR_BIAS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Switch XTAL bias from self-bias to bandgap-based. Powers both DAC and ADC. Reset by power-on reset only. */
        using RAISE_REF = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< Must be low when VDDA < ~1.7V. When low, VAG and ADC ref voltages drop by factor 0.875. */
        using FASTSETTLING = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Increases vag buffer output current by 2X to 20uA to improve startup settling time. */
    } // namespace REFCTRL

    /** @brief Miscellaneous Audio Controls Register */
    namespace ANACTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048090, 0x80048094, 0x80048098, 0x8004809C, LowLevel::Access::ReadWrite>;
        using HP_CLASSAB = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< Headphone amplifier mode. 0=ClassA (for power-up/down and short handling). 1=ClassAB (normal operation). Power-on reset only. */
        using HP_HOLD_GND = LowLevel::Field<Reg, LowLevel::Bit::Bit5, 1, std::uint32_t>; /**< Hold Headphone Output to Ground. Used for power-up/power-down procedures. Power-on reset only. */
        using SHORT_LVLADJR = LowLevel::Field<Reg, LowLevel::Bit::Bit8, 3, std::uint32_t>; /**< Adjust right headphone current short detect trip point. 000=Nominal, +/-25/50/75/100%. Power-on reset only. */
        using SHORT_LVLADJL = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 3, std::uint32_t>; /**< Adjust left headphone current short detect trip point. 000=Nominal, +/-25/50/75/100%. Power-on reset only. */
        using SHORTMODE_LR = LowLevel::Field<Reg, LowLevel::Bit::Bit17, 2, std::uint32_t>; /**< Headphone L/R Channel Short Control. 00=Reset latch no power-down, 01=Latch short signal with HW power-down. */
        using SHORTMODE_CM = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Headphone Common Mode Amplifier Short Control. 00=Reset analog latch, 01=Latch short signal and HW power down. */
        using SHORT_LR_STS = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Status of headphone amplifier short detection. 0=No short. Clear and rearm via SHORTMODE_LR sequence. */
        using SHORT_CM_STS = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 1, std::uint32_t>; /**< Status of common mode amplifier short detection. 0=No short. Clear and rearm via SHORTMODE_CM sequence. */
    } // namespace ANACTRL

    /** @brief Miscellaneous Test Audio Controls Register */
    namespace TEST {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800480A0, 0x800480A4, 0x800480A8, 0x800480AC, LowLevel::Access::ReadWrite>;
        using DAC_DIS_RTZ = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Set to 1 to disable DAC RTZ mode. Test-only. Should remain cleared. */
        using DAC_DOUBLE_I = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< Set to 1 to double ClassA current in DAC amplifier (+360uA each DAC). */
        using DAC_CLASSA = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< Set to 1 to disable ClassAB mode in DAC (+~600uA). */
        using ADCTODAC_LOOP = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< ADC到DAC环回测试使能。 */
        using VAG_DOUBLE_I = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 1, std::uint32_t>; /**< Set to 1 to double ClassA current in VAG amplifier (+240uA). Power-on reset only. */
        using VAG_CLASSA = LowLevel::Field<Reg, LowLevel::Bit::Bit13, 1, std::uint32_t>; /**< Set to 1 to disable ClassAB mode in VAG Amp (+~200uA). Controls both DAC and ADC. Power-on reset only. */
        using HP_IALL_ADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< Adjust all bias current in headphone amplifier. 00=Nominal, 01=-50%, 10=+50%, 11=-40%. Power-on reset only. */
        using HP_I1_ADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< Adjust bias current in first stage of headphone amplifier. 00=Nominal, 01=-50%, 10=+100%, 11=+50%. Power-on reset only. */
        using TM_HPCOMMON = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< Testmode: use headphone common VAG in ADC Mux for analog loopback DAC-HP-ADC. */
        using TM_LOOP = LowLevel::Field<Reg, LowLevel::Bit::Bit25, 1, std::uint32_t>; /**< 测试模式环回使能。 */
        using TM_ADCIN_TOHP = LowLevel::Field<Reg, LowLevel::Bit::Bit26, 1, std::uint32_t>; /**< Testmode: pipe ADC Mux Out to Headphone Output pins. ADC function; reset by ADC SFTRST. */
        using HP_ANTIPOP = LowLevel::Field<Reg, LowLevel::Bit::Bit28, 3, std::uint32_t>; /**< Reserved. */
    } // namespace TEST

    /** @brief BIST Control and Status Register */
    namespace BISTCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800480B0, 0x800480B4, 0x800480B8, 0x800480BC, LowLevel::Access::ReadWrite>;
        using START = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 1, std::uint32_t>; /**< Initiate BIST of internal memory. */
        using DONE = LowLevel::Field<Reg, LowLevel::Bit::Bit1, 1, std::uint32_t>; /**< BIST has completed. */
        using PASS = LowLevel::Field<Reg, LowLevel::Bit::Bit2, 1, std::uint32_t>; /**< BIST has passed. */
        using FAIL = LowLevel::Field<Reg, LowLevel::Bit::Bit3, 1, std::uint32_t>; /**< BIST has failed. */
    } // namespace BISTCTRL

    /** @brief Hardware BIST Status 0 Register */
    namespace BISTSTAT0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800480C0, 0x800480C4, 0x800480C8, 0x800480CC, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 24, std::uint32_t>; /**< Failing data at the failing address. */
    } // namespace BISTSTAT0

    /** @brief Hardware AUDIOUT BIST Status 1 Register */
    namespace BISTSTAT1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800480D0, 0x800480D4, 0x800480D8, 0x800480DC, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 8, std::uint32_t>; /**< Failing address from BIST. */
        using STATE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 5, std::uint32_t>; /**< Fail state of the BIST engine. */
    } // namespace BISTSTAT1

    /** @brief Analog Clock Control Register */
    namespace ANACLKCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800480E0, 0x800480E4, 0x800480E8, 0x800480EC, LowLevel::Access::ReadWrite>;
        using DACDIV = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 3, std::uint32_t>; /**< DAC Analog Clock Divider. Selects oversampling clock rate. 000=6MHz, 001=4MHz, 010/100=3MHz, 011/101=2MHz, 110=1.5MHz, 111=1MHz. */
        using INVERT_DACCLK = LowLevel::Field<Reg, LowLevel::Bit::Bit4, 1, std::uint32_t>; /**< DAC Clock Invert. Invert DAC_CLK for sigma-delta converter and digital filters. */
        using CLKGATE = LowLevel::Field<Reg, LowLevel::Bit::Bit31, 1, std::uint32_t>; /**< Analog clock Gate. Gate clocks for DAC converter and digital filter. Reset by power-on reset only. */
    } // namespace ANACLKCTRL

    /** @brief AUDIOOUT Write Data Register */
    namespace DATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800480F0, 0x800480F4, 0x800480F8, 0x800480FC, LowLevel::Access::ReadWrite>;
        using LOW = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Left Sample or Sample Low Half-Word. For 16-bit mode: left channel. For 32-bit mode: LSB 16 bits. */
        using HIGH = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 16, std::uint32_t>; /**< Right Sample or Sample High Half-Word. For 16-bit mode: right channel. For 32-bit mode: MSB 16 bits. */
    } // namespace DATA

    /** @brief AUDIOOUT Speaker Control Register */
    namespace SPEAKERCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80048100, 0x80048104, 0x80048108, 0x8004810C, LowLevel::Access::ReadWrite>;
        using NEGDRIVER = LowLevel::Field<Reg, LowLevel::Bit::Bit12, 2, std::uint32_t>; /**< 扬声器负端驱动控制。 */
        using POSDRIVER = LowLevel::Field<Reg, LowLevel::Bit::Bit14, 2, std::uint32_t>; /**< 扬声器正端驱动控制。 */
        using IALL_ADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit20, 2, std::uint32_t>; /**< 扬声器总电流调整。 */
        using I1_ADJ = LowLevel::Field<Reg, LowLevel::Bit::Bit22, 2, std::uint32_t>; /**< 扬声器段1电流调整。 */
        using MUTE = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 1, std::uint32_t>; /**< 扬声器静音控制。 */
    } // namespace SPEAKERCTRL

    /** @brief AUDIOOUT Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80048200, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, LowLevel::Bit::Bit0, 16, std::uint32_t>; /**< Fixed read-only RTL version stepping field. Reset=0x0000. */
        using MINOR = LowLevel::Field<Reg, LowLevel::Bit::Bit16, 8, std::uint32_t>; /**< Fixed read-only RTL version minor field. Reset=0x01. */
        using MAJOR = LowLevel::Field<Reg, LowLevel::Bit::Bit24, 8, std::uint32_t>; /**< Fixed read-only RTL version major field. Reset=0x01. */
    } // namespace VERSION

} // namespace Hardware::Registers::AUDIOOUT

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_AUDIOOUT
