#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_CACHE_MAINTENANCE
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_CACHE_MAINTENANCE

/**
 * @file CacheMaintenance.hpp
 * @brief DMA 数据缓冲区的 D-cache 一致性维护(基于 CP15 行操作)。
 *
 * 在带 D-cache 的 ARM926 上,DMA 引擎直接访问主存,绕过 CPU cache,故 CPU 与 DMA 之间
 * 共享缓冲区前后必须手动维护一致性:
 *  - 让 DMA **读取** CPU 准备的数据前:把缓冲区从 D-cache 回写到主存(clean)并排空写缓冲。
 *  - 让 CPU **读取** DMA 写入的数据前:失效缓冲区对应 D-cache 行(invalidate),丢弃陈旧副本。
 *
 * 按 32 字节 cache 行粒度逐行操作(ARM926 行长 32 字节)。本头依赖 CP15.hpp 的 mcr/mrc
 * 内联汇编,仅可用于目标(arm-none-eabi)编译,不进主机单元测试。
 *
 * @warning 失效操作按整 cache 行进行;若缓冲区起止未 32 字节对齐,边缘行可能牵连相邻数据。
 *          DMA 缓冲区应按 32 字节对齐分配。
 */

#include "CP15.hpp"
#include <cstdint>

namespace Hardware::Drivers::Common {

    /** @brief ARM926 D-cache 行长(字节)。 */
    inline constexpr std::uint32_t CacheLineSize = 32u;

    /**
     * @brief 把缓冲区从 D-cache 回写主存并排空写缓冲,供 DMA 读取前调用。
     * @param address   缓冲区起始地址。
     * @param byteCount 缓冲区字节数。
     */
    [[gnu::always_inline]] inline void FlushBufferForDevice(const void* address,
                                                            std::uint32_t byteCount) noexcept {
        const std::uintptr_t startAddress = reinterpret_cast<std::uintptr_t>(address);
        const std::uintptr_t endAddress = startAddress + byteCount;
        std::uintptr_t line = startAddress & ~static_cast<std::uintptr_t>(CacheLineSize - 1u);
        for (; line < endAddress; line += CacheLineSize) {
            LowLevel::CleanDataCacheLine(static_cast<std::uint32_t>(line));
        }
        LowLevel::DrainWriteBuffer();
    }

    /**
     * @brief 失效缓冲区对应的 D-cache 行,供 CPU 读取 DMA 写入的数据前调用。
     * @param address   缓冲区起始地址。
     * @param byteCount 缓冲区字节数。
     */
    [[gnu::always_inline]] inline void InvalidateBufferFromDevice(const void* address,
                                                                  std::uint32_t byteCount) noexcept {
        const std::uintptr_t startAddress = reinterpret_cast<std::uintptr_t>(address);
        const std::uintptr_t endAddress = startAddress + byteCount;
        std::uintptr_t line = startAddress & ~static_cast<std::uintptr_t>(CacheLineSize - 1u);
        for (; line < endAddress; line += CacheLineSize) {
            LowLevel::InvalidateDataCacheLine(static_cast<std::uint32_t>(line));
        }
    }

} // namespace Hardware::Drivers::Common

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_COMMON_CACHE_MAINTENANCE
