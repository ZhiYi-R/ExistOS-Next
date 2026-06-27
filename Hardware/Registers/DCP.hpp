#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS_DCP
#define EXIST_OS_NEXT_HARDWARE_REGISTERS_DCP

/**
 * @file DCP.hpp
 * @brief DCP 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。
 *
 * 数据协处理器(DCP,硬件 AES/SHA 加解密与哈希,支持内存拷贝/校验)
 *
 * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。
 */

#include "../CoreAbstract/Field.hpp"
#include "../CoreAbstract/Register.hpp"
#include <cstdint>

namespace Hardware::Registers::DCP {

    /** @brief DCP Control Register 0 */
    namespace CTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028000, 0x80028004, 0x80028008, 0x8002800C, LowLevel::Access::ReadWrite>;
        /** @brief CHANNEL_INTERRUPT_ENABLE 的取值。 */
        enum class CHANNEL_INTERRUPT_ENABLE_Values : std::uint32_t {
            CH0 = 0x1,
            CH1 = 0x2,
            CH2 = 0x4,
            CH3 = 0x8,
        };
        using CHANNEL_INTERRUPT_ENABLE = LowLevel::Field<Reg, 0, 8, CHANNEL_INTERRUPT_ENABLE_Values>; /**< Per-channel interrupt enable. CH0=0x01, CH1=0x02, CH2=0x04, CH3=0x08. CH0 routed to dcp_vmi_irq, others to dcp_irq. */
        using CSC_INTERRUPT_ENABLE = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Interrupt enable bit for the CSC. Combined with channels 1-3 interrupts to form dcp_irq. */
        using ENABLE_CONTEXT_SWITCHING = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< Enable automatic context switching for channels. Set if more than one channel does hashing/cipher requiring context save (e.g. CBC mode). */
        using ENABLE_CONTEXT_CACHING = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< Enable caching of contexts between operations. If only one channel used for encryption/hashing, context not reloaded if channel was last used. */
        using GATHER_RESIDUAL_WRITES = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< Enable ragged writes to unaligned buffers to be gathered between multiple write operations. Improves performance. */
        /** @brief PRESENT_CSC 的取值。 */
        enum class PRESENT_CSC_Values : std::uint32_t {
            Present = 0x1,
            Absent = 0x0,
        };
        using PRESENT_CSC = LowLevel::Field<Reg, 28, 1, PRESENT_CSC_Values>; /**< Indicates whether the CSC function is present. Present=0x1, Absent=0x0. */
        /** @brief PRESENT_CRYPTO 的取值。 */
        enum class PRESENT_CRYPTO_Values : std::uint32_t {
            Present = 0x1,
            Absent = 0x0,
        };
        using PRESENT_CRYPTO = LowLevel::Field<Reg, 29, 1, PRESENT_CRYPTO_Values>; /**< Indicates whether the crypto (cipher/hash) functions are present. Present=0x1, Absent=0x0. */
        using CLKGATE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< Must be cleared to 0 for normal operation. When set to 1, gates off the clocks to the block. */
        using SFTRST = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< Clear to 0 to enable normal DCP operation. Set to 1 (default) to disable clocking and hold in reset (lowest power) state. */
    } // namespace CTRL

    /** @brief DCP Status Register */
    namespace STAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028010, 0x80028014, 0x80028018, 0x8002801C, LowLevel::Access::ReadWrite>;
        using IRQ = LowLevel::Field<Reg, 0, 4, std::uint32_t>; /**< Indicates channels with pending interrupts. CH0 on dcp_vmi_irq, others on dcp_irq. */
        using CSCIRQ = LowLevel::Field<Reg, 8, 1, std::uint32_t>; /**< Indicates CSC has a pending interrupt request. Appears on dcp_irq line. */
        /** @brief READY_CHANNELS 的取值。 */
        enum class READY_CHANNELS_Values : std::uint32_t {
            CH0 = 0x1,
            CH1 = 0x2,
            CH2 = 0x4,
            CH3 = 0x8,
        };
        using READY_CHANNELS = LowLevel::Field<Reg, 16, 8, READY_CHANNELS_Values>; /**< Indicates which channels are ready to proceed with a transfer. One-hot per channel. */
        /** @brief CUR_CHANNEL 的取值。 */
        enum class CUR_CHANNEL_Values : std::uint32_t {
            None = 0x0,
            CH0 = 0x1,
            CH1 = 0x2,
            CH2 = 0x3,
            CH3 = 0x4,
            CSC = 0x8,
        };
        using CUR_CHANNEL = LowLevel::Field<Reg, 24, 4, CUR_CHANNEL_Values>; /**< Current (active) channel encoded. None=0x0, CH0=0x1, CH1=0x2, CH2=0x3, CH3=0x4, CSC=0x8. */
        using OTP_KEY_READY = LowLevel::Field<Reg, 28, 1, std::uint32_t>; /**< When set, indicates the OTP key has been shifted from the fuse block and is ready for use. */
    } // namespace STAT

    /** @brief DCP Channel Control Register */
    namespace CHANNELCTRL {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028020, 0x80028024, 0x80028028, 0x8002802C, LowLevel::Access::ReadWrite>;
        /** @brief ENABLE_CHANNEL 的取值。 */
        enum class ENABLE_CHANNEL_Values : std::uint32_t {
            CH0 = 0x1,
            CH1 = 0x2,
            CH2 = 0x4,
            CH3 = 0x8,
        };
        using ENABLE_CHANNEL = LowLevel::Field<Reg, 0, 8, ENABLE_CHANNEL_Values>; /**< Setting a bit enables the DMA channel. CH0=0x01, CH1=0x02, CH2=0x04, CH3=0x08. */
        /** @brief HIGH_PRIORITY_CHANNEL 的取值。 */
        enum class HIGH_PRIORITY_CHANNEL_Values : std::uint32_t {
            CH0 = 0x1,
            CH1 = 0x2,
            CH2 = 0x4,
            CH3 = 0x8,
        };
        using HIGH_PRIORITY_CHANNEL = LowLevel::Field<Reg, 8, 8, HIGH_PRIORITY_CHANNEL_Values>; /**< Setting a bit marks the channel for high-priority arbitration. Round-robin among them. CH0=0x01, CH1=0x02, CH2=0x04, CH3=0x08. */
        using CH0_IRQ_MERGED = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< 通道0中断合并，置位时CH0中断并入共享dcp_irq。 */
        /** @brief CSC_PRIORITY 的取值。 */
        enum class CSC_PRIORITY_Values : std::uint32_t {
            HIGH = 0x3,
            MED = 0x2,
            LOW = 0x1,
            BACKGROUND = 0x0,
        };
        using CSC_PRIORITY = LowLevel::Field<Reg, 17, 2, CSC_PRIORITY_Values>; /**< Sets CSC priority: HIGH=0x3, MED=0x2, LOW=0x1, BACKGROUND=0x0. */
    } // namespace CHANNELCTRL

    /** @brief DCP Capability 0 Register */
    namespace CAPABILITY0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028030, 0x80028034, 0x80028038, 0x8002803C, LowLevel::Access::ReadWrite>;
        using NUM_KEYS = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< Encoded value indicating the number of key storage locations. */
        using NUM_CHANNELS = LowLevel::Field<Reg, 8, 4, std::uint32_t>; /**< Encoded value indicating the number of channels implemented. */
        using ENABLE_TZONE = LowLevel::Field<Reg, 30, 1, std::uint32_t>; /**< 信任区使能标志。 */
        using DISABLE_DECRYPT = LowLevel::Field<Reg, 31, 1, std::uint32_t>; /**< 解密禁用标志。 */
    } // namespace CAPABILITY0

    /** @brief DCP Capability 1 Register */
    namespace CAPABILITY1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028040, 0x80028044, 0x80028048, 0x8002804C, LowLevel::Access::ReadWrite>;
        /** @brief CIPHER_ALGORITHMS 的取值。 */
        enum class CIPHER_ALGORITHMS_Values : std::uint32_t {
            AES128 = 0x1,
        };
        using CIPHER_ALGORITHMS = LowLevel::Field<Reg, 0, 16, CIPHER_ALGORITHMS_Values>; /**< One-hot field indicating cipher algorithms available. AES128=0x0001. */
        /** @brief HASH_ALGORITHMS 的取值。 */
        enum class HASH_ALGORITHMS_Values : std::uint32_t {
            SHA1 = 0x1,
            CRC32 = 0x2,
        };
        using HASH_ALGORITHMS = LowLevel::Field<Reg, 16, 16, HASH_ALGORITHMS_Values>; /**< One-hot field indicating hashing algorithms available. SHA1=0x0001, CRC32=0x0002. */
    } // namespace CAPABILITY1

    /** @brief DCP Context Buffer Pointer */
    namespace CONTEXT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028050, 0x80028054, 0x80028058, 0x8002805C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Context pointer address. Should be in system RAM and word-aligned for optimal performance. */
    } // namespace CONTEXT

    /** @brief DCP Key Index */
    namespace KEY {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028060, 0x80028064, 0x80028068, 0x8002806C, LowLevel::Access::ReadWrite>;
        using SUBWORD = LowLevel::Field<Reg, 0, 2, std::uint32_t>; /**< Key subword pointer. Valid indices 0-3. Auto-increments after each key data write. */
        using RSVD_SUBWORD = LowLevel::Field<Reg, 2, 2, std::uint32_t>; /**< 保留关键字子字域。 */
        using INDEX = LowLevel::Field<Reg, 4, 2, std::uint32_t>; /**< Key index pointer. Valid indices are 0-[number_keys]. */
        using RSVD_INDEX = LowLevel::Field<Reg, 6, 2, std::uint32_t>; /**< 保留关键字索引导。 */
    } // namespace KEY

    /** @brief DCP Key Data */
    namespace KEYDATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028070, 0x80028074, 0x80028078, 0x8002807C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Word 0 data for key. This is the least-significant word. */
    } // namespace KEYDATA

    /** @brief DCP Work Packet 0 Status Register */
    namespace PACKET0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028080, 0x80028084, 0x80028088, 0x8002808C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Next Pointer Register. */
    } // namespace PACKET0

    /** @brief DCP Work Packet 1 Status Register */
    namespace PACKET1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028090, 0x80028094, 0x80028098, 0x8002809C, LowLevel::Access::ReadWrite>;
        using INTERRUPT = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Reflects whether channel should issue interrupt upon packet completion. */
        using DECR_SEMAPHORE = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< Reflects whether channel semaphore decremented at end of current operation. */
        using CHAIN = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Reflects whether next command pointer should be loaded into channel's descriptor pointer. */
        using CHAIN_CONTIGUOUS = LowLevel::Field<Reg, 3, 1, std::uint32_t>; /**< Reflects whether next packet's address is located following this packet's payload. */
        using ENABLE_MEMCOPY = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< Reflects whether memcopy function is enabled for this operation. */
        using ENABLE_CIPHER = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< Reflects whether cipher function is enabled for this operation. */
        using ENABLE_HASH = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< Reflects whether hashing function is enabled for this operation. */
        using ENABLE_BLIT = LowLevel::Field<Reg, 7, 1, std::uint32_t>; /**< Reflects whether DCP performs blit. BUFFER_SIZE treated as two 16-bit X-Y extents. */
        /** @brief CIPHER_ENCRYPT 的取值。 */
        enum class CIPHER_ENCRYPT_Values : std::uint32_t {
            ENCRYPT = 0x1,
            DECRYPT = 0x0,
        };
        using CIPHER_ENCRYPT = LowLevel::Field<Reg, 8, 1, CIPHER_ENCRYPT_Values>; /**< Indicates encryption or decryption. ENCRYPT=0x01, DECRYPT=0x00. */
        using CIPHER_INIT = LowLevel::Field<Reg, 9, 1, std::uint32_t>; /**< Reflects whether the cipher block should load IV from payload. */
        using OTP_KEY = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< Reflects whether a hardware-based key should be used. KEY_SELECT selects key. */
        using PAYLOAD_KEY = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< When set, payload contains the key. Takes precedence over OTP_KEY. */
        using HASH_INIT = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< Reflects whether current hashing block is initial block; hash registers initialized before operation. */
        using HASH_TERM = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< Reflects whether current hashing block is the final block; hash padding applied by hardware. */
        using CHECK_HASH = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< Reflects whether the calculated hash should be compared against payload hash. */
        /** @brief HASH_OUTPUT 的取值。 */
        enum class HASH_OUTPUT_Values : std::uint32_t {
            INPUT = 0x0,
            OUTPUT = 0x1,
        };
        using HASH_OUTPUT = LowLevel::Field<Reg, 15, 1, HASH_OUTPUT_Values>; /**< Controls whether input or output data is hashed. INPUT=0x00, OUTPUT=0x01. */
        using CONSTANT_FILL = LowLevel::Field<Reg, 16, 1, std::uint32_t>; /**< When set (MEMCOPY/BLIT modes), DCP fills destination buffer with value from Source Address field. */
        using TEST_SEMA_IRQ = LowLevel::Field<Reg, 17, 1, std::uint32_t>; /**< Used to test the channel semaphore transition to 0. FOR TEST USE ONLY! */
        using KEY_BYTESWAP = LowLevel::Field<Reg, 18, 1, std::uint32_t>; /**< Reflects whether the DCP engine swaps key bytes (big-endian key). */
        using KEY_WORDSWAP = LowLevel::Field<Reg, 19, 1, std::uint32_t>; /**< Reflects whether the DCP engine swaps key words (big-endian key). */
        using INPUT_BYTESWAP = LowLevel::Field<Reg, 20, 1, std::uint32_t>; /**< Reflects whether the DCP engine byte-swaps input data (big-endian). */
        using INPUT_WORDSWAP = LowLevel::Field<Reg, 21, 1, std::uint32_t>; /**< Reflects whether the DCP engine word-swaps input data (big-endian). */
        using OUTPUT_BYTESWAP = LowLevel::Field<Reg, 22, 1, std::uint32_t>; /**< Reflects whether the DCP engine byte-swaps output data (big-endian). */
        using OUTPUT_WORDSWAP = LowLevel::Field<Reg, 23, 1, std::uint32_t>; /**< Reflects whether the DCP engine word-swaps output data (big-endian). */
        using TAG = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Packet Tag. */
    } // namespace PACKET1

    /** @brief DCP Work Packet 2 Status Register */
    namespace PACKET2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800280A0, 0x800280A4, 0x800280A8, 0x800280AC, LowLevel::Access::ReadWrite>;
        /** @brief CIPHER_SELECT 的取值。 */
        enum class CIPHER_SELECT_Values : std::uint32_t {
            AES128 = 0x0,
        };
        using CIPHER_SELECT = LowLevel::Field<Reg, 0, 4, CIPHER_SELECT_Values>; /**< Cipher Selection Field. AES128=0x00. */
        /** @brief CIPHER_MODE 的取值。 */
        enum class CIPHER_MODE_Values : std::uint32_t {
            ECB = 0x0,
            CBC = 0x1,
        };
        using CIPHER_MODE = LowLevel::Field<Reg, 4, 4, CIPHER_MODE_Values>; /**< Cipher Mode Selection. ECB=0x00, CBC=0x01. */
        using KEY_SELECT = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< Key Selection reflecting the key index for cipher operation. */
        /** @brief HASH_SELECT 的取值。 */
        enum class HASH_SELECT_Values : std::uint32_t {
            SHA1 = 0x0,
            CRC32 = 0x1,
        };
        using HASH_SELECT = LowLevel::Field<Reg, 16, 4, HASH_SELECT_Values>; /**< Hash Selection. SHA1=0x00, CRC32=0x01. */
        using CIPHER_CFG = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Cipher configuration bits. Optional configuration required for ciphers. */
    } // namespace PACKET2

    /** @brief DCP Work Packet 3 Status Register */
    namespace PACKET3 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800280B0, 0x800280B4, 0x800280B8, 0x800280BC, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Source Buffer Address Pointer. Working value, updates as operation proceeds. */
    } // namespace PACKET3

    /** @brief DCP Work Packet 4 Status Register */
    namespace PACKET4 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800280C0, 0x800280C4, 0x800280C8, 0x800280CC, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Destination Buffer Address Pointer. Working value, updates as operation proceeds. */
    } // namespace PACKET4

    /** @brief DCP Work Packet 5 Status Register */
    namespace PACKET5 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800280D0, 0x800280D4, 0x800280D8, 0x800280DC, LowLevel::Access::ReadWrite>;
        using COUNT = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Byte Count register. Working value, updates as operation proceeds. */
    } // namespace PACKET5

    /** @brief DCP Work Packet 6 Status Register */
    namespace PACKET6 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800280E0, 0x800280E4, 0x800280E8, 0x800280EC, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Payload pointer for the current control packet. */
    } // namespace PACKET6

    /** @brief Color Space Conversion Control Register 0 */
    namespace CSCCTRL0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028300, 0x80028304, 0x80028308, 0x8002830C, LowLevel::Access::ReadWrite>;
        using ENABLE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< Enables color-space conversion with specified parameters. */
        /** @brief YUV_FORMAT 的取值。 */
        enum class YUV_FORMAT_Values : std::uint32_t {
            YUV420 = 0x0,
            YUV422 = 0x2,
        };
        using YUV_FORMAT = LowLevel::Field<Reg, 4, 4, YUV_FORMAT_Values>; /**< YUV Input Buffer format. YUV420=0x0, YUV422=0x2. */
        /** @brief RGB_FORMAT 的取值。 */
        enum class RGB_FORMAT_Values : std::uint32_t {
            RGB16_565 = 0x0,
            YCbCrI = 0x1,
            RGB24 = 0x2,
            YUV422I = 0x3,
        };
        using RGB_FORMAT = LowLevel::Field<Reg, 8, 2, RGB_FORMAT_Values>; /**< Target RGB framebuffer format. RGB16_565=0x0, RGB24=0x2, YUV422I=0x3. */
        using DELTA = LowLevel::Field<Reg, 10, 1, std::uint32_t>; /**< Framebuffer color ordering for delta pixel config. For 24-bit RGB only. */
        using SUBSAMPLE = LowLevel::Field<Reg, 11, 1, std::uint32_t>; /**< Pixel subsampling. Only enable when DELTA bit is set. */
        using ROTATE = LowLevel::Field<Reg, 12, 1, std::uint32_t>; /**< Output image should be rotated (clockwise 90 degrees with horizontal flip). */
        using SCALE = LowLevel::Field<Reg, 13, 1, std::uint32_t>; /**< Output image should be scaled. CSCXSCALE/CSCYSCALE registers must be programmed. */
        using UPSAMPLE = LowLevel::Field<Reg, 14, 1, std::uint32_t>; /**< Upsample subsampled chroma at luma locations before color conversion. Smooths horizontal color transitions. */
        using CLIP = LowLevel::Field<Reg, 15, 1, std::uint32_t>; /**< CSC输出裁剪使能。 */
    } // namespace CSCCTRL0

    /** @brief Color Space Conversion Status Register */
    namespace CSCSTAT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028310, 0x80028314, 0x80028318, 0x8002831C, LowLevel::Access::ReadWrite>;
        using COMPLETE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< When set, indicates the CSC has completed its operation. */
        using ERROR_SETUP = LowLevel::Field<Reg, 2, 1, std::uint32_t>; /**< Invalid programming configuration detected. */
        using ERROR_SRC = LowLevel::Field<Reg, 4, 1, std::uint32_t>; /**< Bus error when reading source buffer. CSC terminates. */
        using ERROR_DST = LowLevel::Field<Reg, 5, 1, std::uint32_t>; /**< Bus error when writing output RGB buffer. CSC terminates. */
        using ERROR_PAGEFAULT = LowLevel::Field<Reg, 6, 1, std::uint32_t>; /**< CSC页错误状态。 */
        /** @brief ERROR_CODE 的取值。 */
        enum class ERROR_CODE_Values : std::uint32_t {
            LUMA0_FETCH_ERROR_Y0 = 0x1,
            LUMA1_FETCH_ERROR_Y1 = 0x2,
            CHROMA_FETCH_ERROR_U = 0x3,
            CHROMA_FETCH_ERROR_V = 0x4,
        };
        using ERROR_CODE = LowLevel::Field<Reg, 16, 8, ERROR_CODE_Values>; /**< Error codes: LUMA0_FETCH=0x01, LUMA1_FETCH=0x02, CHROMA_U_FETCH=0x03, CHROMA_V_FETCH=0x04. */
    } // namespace CSCSTAT

    /** @brief Color Space Conversion Output Buffer Parameters */
    namespace CSCOUTBUFPARAM {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028320, 0x80028324, 0x80028328, 0x8002832C, LowLevel::Access::ReadWrite>;
        using LINE_SIZE = LowLevel::Field<Reg, 0, 12, std::uint32_t>; /**< Line size in horizontal pixels (horizontal width of display). */
        using FIELD_SIZE = LowLevel::Field<Reg, 12, 12, std::uint32_t>; /**< Field size as number of lines (vertical height) for unscaled images. */
    } // namespace CSCOUTBUFPARAM

    /** @brief Color Space Conversion Input Buffer Parameters */
    namespace CSCINBUFPARAM {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028330, 0x80028334, 0x80028338, 0x8002833C, LowLevel::Access::ReadWrite>;
        using LINE_SIZE = LowLevel::Field<Reg, 0, 12, std::uint32_t>; /**< Line size in horizontal pixels (horizontal width of display). */
    } // namespace CSCINBUFPARAM

    /** @brief Color Space RGB Frame Buffer Pointer */
    namespace CSCRGB {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028340, 0x80028344, 0x80028348, 0x8002834C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Current address pointer for output frame buffer. Working register. MUST be word-aligned. */
    } // namespace CSCRGB

    /** @brief Color Space Luma (Y) Buffer Pointer */
    namespace CSCLUMA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028350, 0x80028354, 0x80028358, 0x8002835C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Current address pointer for input luminance (Y) buffer. Working register. MUST be word-aligned. */
    } // namespace CSCLUMA

    /** @brief Color Space Chroma (U/Cb) Buffer Pointer */
    namespace CSCCHROMAU {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028360, 0x80028364, 0x80028368, 0x8002836C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Current address pointer for input chrominance (U/Cb) buffer. Working register. MUST be word-aligned. */
    } // namespace CSCCHROMAU

    /** @brief Color Space Chroma (V/Cr) Buffer Pointer */
    namespace CSCCHROMAV {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028370, 0x80028374, 0x80028378, 0x8002837C, LowLevel::Access::ReadWrite>;
        using ADDR = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Current address pointer for input chrominance (V/Cr) buffer. Working register. MUST be word-aligned. */
    } // namespace CSCCHROMAV

    /** @brief Color Space Conversion Coefficient Register 0 */
    namespace CSCCOEFF0 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028380, 0x80028384, 0x80028388, 0x8002838C, LowLevel::Access::ReadWrite>;
        using Y_OFFSET = LowLevel::Field<Reg, 0, 8, std::uint32_t>; /**< Amplitude offset in Y data. YUV=0, CbCr=16 (0x10). */
        using UV_OFFSET = LowLevel::Field<Reg, 8, 8, std::uint32_t>; /**< Phase offset for UV data (typically 128/0x80 for -0.5 to 0.5 range). */
        using C0 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< Y multiplier coefficient. */
    } // namespace CSCCOEFF0

    /** @brief Color Space Conversion Coefficient Register 1 */
    namespace CSCCOEFF1 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028390, 0x80028394, 0x80028398, 0x8002839C, LowLevel::Access::ReadWrite>;
        using C4 = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< Blue Cb multiplier coefficient. */
        using C1 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< Red Cr multiplier coefficient. */
    } // namespace CSCCOEFF1

    /** @brief Color Space Conversion Coefficient Register 2 */
    namespace CSCCOEFF2 {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800283A0, 0x800283A4, 0x800283A8, 0x800283AC, LowLevel::Access::ReadWrite>;
        using C3 = LowLevel::Field<Reg, 0, 10, std::uint32_t>; /**< Green Cb multiplier coefficient. */
        using C2 = LowLevel::Field<Reg, 16, 10, std::uint32_t>; /**< Green Cr multiplier coefficient. */
    } // namespace CSCCOEFF2

    /** @brief Color Space Conversion Clipping Register */
    namespace CSCCLIP {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800283D0, 0x800283D4, 0x800283D8, 0x800283DC, LowLevel::Access::ReadWrite>;
        using WIDTH = LowLevel::Field<Reg, 0, 12, std::uint32_t>; /**< CSC裁剪宽度。 */
        using HEIGHT = LowLevel::Field<Reg, 12, 12, std::uint32_t>; /**< CSC裁剪高度。 */
    } // namespace CSCCLIP

    /** @brief Color Space Conversion X-Scaling Register */
    namespace CSCXSCALE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800283E0, 0x800283E4, 0x800283E8, 0x800283EC, LowLevel::Access::ReadWrite>;
        using WIDTH = LowLevel::Field<Reg, 0, 12, std::uint32_t>; /**< Scaled video width. */
        using FRAC = LowLevel::Field<Reg, 12, 12, std::uint32_t>; /**< Fractional coefficient = source_width % target_width. */
        using INT = LowLevel::Field<Reg, 24, 2, std::uint32_t>; /**< Integer coefficient = source_width/target_width. Upscaling=0, downscaling=1 or 2. */
    } // namespace CSCXSCALE

    /** @brief Color Space Conversion Y-Scaling Register */
    namespace CSCYSCALE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x800283F0, 0x800283F4, 0x800283F8, 0x800283FC, LowLevel::Access::ReadWrite>;
        using HEIGHT = LowLevel::Field<Reg, 0, 12, std::uint32_t>; /**< Scaled video height. */
        using FRAC = LowLevel::Field<Reg, 12, 12, std::uint32_t>; /**< Fractional coefficient = source_height % target_height. */
        using INT = LowLevel::Field<Reg, 24, 2, std::uint32_t>; /**< Integer coefficient = source_height/target_height. Upscaling=0, downscaling=1 or 2. */
    } // namespace CSCYSCALE

    /** @brief DCP Debug Select Register */
    namespace DBGSELECT {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028400, 0x80028404, 0x80028408, 0x8002840C, LowLevel::Access::ReadWrite>;
        /** @brief INDEX 的取值。 */
        enum class INDEX_Values : std::uint32_t {
            CONTROL = 0x1,
            OTPKEY0 = 0x10,
            OTPKEY1 = 0x11,
            OTPKEY2 = 0x12,
            OTPKEY3 = 0x13,
        };
        using INDEX = LowLevel::Field<Reg, 0, 8, INDEX_Values>; /**< Selects debug value via debug data register. CONTROL=0x01, OTPKEY0-3=0x10-0x13. */
    } // namespace DBGSELECT

    /** @brief DCP Debug Data Register */
    namespace DBGDATA {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028410, 0x80028414, 0x80028418, 0x8002841C, LowLevel::Access::ReadWrite>;
        using DATA = LowLevel::Field<Reg, 0, 32, std::uint32_t>; /**< Debug Data. */
    } // namespace DBGDATA

    /** @brief DCP Page Table Register */
    namespace PAGETABLE {
        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */
        using Reg = LowLevel::RegisterWithSetClearToggle<std::uint32_t,
            0x80028420, 0x80028424, 0x80028428, 0x8002842C, LowLevel::Access::ReadWrite>;
        using ENABLE = LowLevel::Field<Reg, 0, 1, std::uint32_t>; /**< 使能控制位，写1使能功能，写0禁用。 */
        using FLUSH = LowLevel::Field<Reg, 1, 1, std::uint32_t>; /**< 页表刷新，写1刷新DCP页表缓存。 */
        using BASE = LowLevel::Field<Reg, 2, 30, std::uint32_t>; /**< 页表基地址指针。 */
    } // namespace PAGETABLE

    /** @brief DCP Version Register */
    namespace VERSION {
        /** @brief 寄存器后端(普通整字 ldr/str)。 */
        using Reg = LowLevel::Register<std::uint32_t, 0x80028430, LowLevel::Access::ReadOnly>;
        using STEP = LowLevel::Field<Reg, 0, 16, std::uint32_t>; /**< Fixed read-only value reflecting the stepping version of the design implementation. */
        using MINOR = LowLevel::Field<Reg, 16, 8, std::uint32_t>; /**< Fixed read-only value reflecting the MINOR version of the design implementation. */
        using MAJOR = LowLevel::Field<Reg, 24, 8, std::uint32_t>; /**< Fixed read-only value reflecting the MAJOR version of the design implementation. */
    } // namespace VERSION

} // namespace Hardware::Registers::DCP

#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS_DCP
