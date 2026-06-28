#ifndef EXIST_OS_NEXT_HARDWARE_DRIVERS_KEYBOARD
#define EXIST_OS_NEXT_HARDWARE_DRIVERS_KEYBOARD

/**
 * @file Keyboard.hpp
 * @brief 通用 GPIO 矩阵键盘扫描器:驱动线/读取线以 GPIO 类型注入,极性参数化,逐线原语全编译期展开。
 *
 * HP39GII 的键盘是一组"驱动线 × 读取线"的交叉矩阵(无专用 KPP 外设,纯 GPIO 位扫描):
 *  - **驱动线**(输出):逐条拉到有效电平选通,其余保持空闲电平;
 *  - **读取线**(输入,内部上拉/下拉):某交叉点按键按下时,该读取线被选通的驱动线拉到有效电平。
 * HP39GII 实测为 **active-low**:选通把驱动线拉低、空闲为高;读取线常态为高,按下读到低。
 *
 * 本驱动是**与板子解耦的通用扫描器**:具体引脚(以及哪些是驱动线/读取线)由上层 BSP 通过
 * PinGroup<…> 注入,驱动体内不出现任何具体引脚或 BSP 依赖。极性由非类型模板参数 DriveActiveLow
 * 表达(默认 true=HP39GII)。注入的引脚类型只需暴露 GPIO<> 同款纯静态接口:
 * SetMuxToGpio / ConfigureAsOutput / ConfigureAsInput / SetHigh / SetLow / Read。
 *
 * 本层只给**逐线 GPIO 触发/读取原语**:选通一条驱动线 SelectDriveLine<i>()、读取全部读取线位图
 * ReadSenseLines()、撤销选通 DeselectDriveLine<i>()。"选通→等 settle tick→采样→撤销"的整矩阵
 * 扫描节拍编排上移 OS statemachine(本层不自旋等待线电平稳定)。
 *
 * 典型用法(引脚别名置于 BSP,扫描循环由 OS 编排):
 *   using Drive = Keyboard::PinGroup<GPIO<2,6>, GPIO<2,5>, ...>;   // 驱动线(输出)
 *   using Sense = Keyboard::PinGroup<GPIO<1,23>, GPIO<1,25>, ...>; // 读取线(输入)
 *   using Keys  = Keyboard::Matrix<Drive, Sense>;
 *   Keys::Initialize();
 *   // —— 以下由 OS statemachine 按 tick 编排 ——
 *   Keys::SelectDriveLine<0>();
 *   // …等待 settle tick(OS 计时)…
 *   const std::uint32_t bits = Keys::ReadSenseLines();
 *   Keys::DeselectDriveLine<0>();
 *
 * 每个引脚动作落为单条原子 MMIO 指令、无运行时下标、无函数调用开销。键码映射、去抖、组合键
 * 判定属上层 UI;矩阵之外的零散按键(如非规则交叉点)由板级以普通 GPIO 单独读取。
 *
 * @note 本头不 #include GPIO.hpp:引脚类型由调用方注入,以保持与具体引脚后端解耦。
 */

#include <cstddef>
#include <cstdint>
#include <utility>

namespace Hardware::Drivers::Keyboard {

    namespace Detail {

        /**
         * @brief 取参数包中第 N 个类型(主模板递归剥离表头)。
         * @tparam N     下标(0 起)。
         * @tparam First 当前表头类型。
         * @tparam Rest  其余类型。
         */
        template <std::size_t N, typename First, typename... Rest>
        struct TypeAt {
            using Type = typename TypeAt<N - 1u, Rest...>::Type;
        };

        /** @brief 递归基:下标 0 取表头。 */
        template <typename First, typename... Rest>
        struct TypeAt<0u, First, Rest...> {
            using Type = First;
        };

    } // namespace Detail

    /**
     * @brief 一组引脚的编译期容器(供 Matrix 注入驱动线/读取线)。
     * @tparam Pins GPIO<> 同款纯静态引脚门面类型,顺序即逻辑线序(下标 0 起)。
     */
    template <typename... Pins>
    struct PinGroup {
        /** @brief 本组引脚数。 */
        static constexpr std::uint32_t Count = sizeof...(Pins);

        /**
         * @brief 取本组第 Index 条线的引脚类型。
         * @tparam Index 线序下标(0 起)。
         */
        template <std::size_t Index>
        using PinAt = typename Detail::TypeAt<Index, Pins...>::Type;
    };

    /**
     * @brief 编译期固定接线的矩阵键盘扫描器(纯静态门面)。
     *
     * @tparam DriveGroup     驱动线 PinGroup(配为输出,逐条选通)。
     * @tparam SenseGroup     读取线 PinGroup(配为输入,读取选通结果)。
     * @tparam DriveActiveLow 选通极性:true=拉低选通/空闲高、按下读低(HP39GII);false=反相。
     */
    template <typename DriveGroup, typename SenseGroup, bool DriveActiveLow = true>
    struct Matrix {
        Matrix() = delete;
        ~Matrix() = delete;
        Matrix(const Matrix&) = delete;
        Matrix& operator=(const Matrix&) = delete;

        /** @brief 驱动线条数。 */
        static constexpr std::uint32_t DriveCount = DriveGroup::Count;
        /** @brief 读取线条数。 */
        static constexpr std::uint32_t SenseCount = SenseGroup::Count;

        static_assert(DriveCount > 0u && SenseCount > 0u, "矩阵至少需要一条驱动线与一条读取线");
        static_assert(SenseCount <= 32u, "读取线数不能超过 32(单字位图容量)");

        /**
         * @brief 一次全矩阵扫描的快照:每条驱动线一字,位 s 置 1 表示该线与读取线 s 的交叉点按下。
         *
         * 本层不再自行扫描;此类型供 OS 编排逐线 ReadSenseLines() 结果时填充并查询。
         */
        struct ScanResult {
            std::uint32_t lines[DriveCount]; /**< 按驱动线下标索引;位 s = (drive,sense=s) 是否按下。 */

            /**
             * @brief 查询某交叉点是否按下。
             * @param driveIndex 驱动线下标(< DriveCount)。
             * @param senseIndex 读取线下标(< SenseCount)。
             * @return 按下返回 true。
             */
            [[nodiscard]] bool IsPressed(std::uint32_t driveIndex, std::uint32_t senseIndex) const noexcept {
                return (lines[driveIndex] & (1u << senseIndex)) != 0u;
            }

            /** @brief 是否有任意按键按下。 */
            [[nodiscard]] bool AnyPressed() const noexcept {
                std::uint32_t merged = 0u;
                for (std::uint32_t index = 0u; index < DriveCount; ++index) {
                    merged |= lines[index];
                }
                return merged != 0u;
            }
        };

        /**
         * @brief 初始化所有引脚:全部复用为 GPIO;驱动线配输出并置空闲电平;读取线配输入。
         *
         * 须在首次扫描前调用一次(PINCTRL/GPIO 时钟须已使能)。
         */
        [[gnu::always_inline]] static void Initialize() noexcept {
            initializeDriveLines(std::make_index_sequence<DriveCount>{});
            initializeSenseLines(std::make_index_sequence<SenseCount>{});
        }

        /**
         * @brief 选通第 DriveIndex 条驱动线(按极性拉到有效电平,单条原子 MMIO)。
         *
         * 选通后须由 OS 计时等待线电平稳定(settle tick),再调用 ReadSenseLines() 采样。
         * @tparam DriveIndex 驱动线下标(< DriveCount),越界编译期报错。
         */
        template <std::uint32_t DriveIndex>
            requires(DriveIndex < DriveCount)
        [[gnu::always_inline]] static void SelectDriveLine() noexcept {
            selectLine<typename DriveGroup::template PinAt<DriveIndex>>();
        }

        /**
         * @brief 撤销选通第 DriveIndex 条驱动线(按极性置回空闲电平,单条原子 MMIO)。
         * @tparam DriveIndex 驱动线下标(< DriveCount),越界编译期报错。
         */
        template <std::uint32_t DriveIndex>
            requires(DriveIndex < DriveCount)
        [[gnu::always_inline]] static void DeselectDriveLine() noexcept {
            deselectLine<typename DriveGroup::template PinAt<DriveIndex>>();
        }

        /**
         * @brief 读取全部读取线并打包成位图:位 s = 读取线 s 是否按下(按极性折算,编译期展开)。
         *
         * 应在选通某驱动线并等待 settle 之后调用;返回值即该驱动线一行的按下位图。
         * @return 读取线按下位图(bit s 对应读取线 s)。
         */
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t ReadSenseLines() noexcept {
            return readSenseBits(std::make_index_sequence<SenseCount>{});
        }

    private:
        /** @brief 选通一条驱动线(按极性拉到有效电平)。 */
        template <typename Pin>
        [[gnu::always_inline]] static void selectLine() noexcept {
            if constexpr (DriveActiveLow) {
                Pin::SetLow();
            } else {
                Pin::SetHigh();
            }
        }

        /** @brief 撤销选通一条驱动线(按极性置回空闲电平)。 */
        template <typename Pin>
        [[gnu::always_inline]] static void deselectLine() noexcept {
            if constexpr (DriveActiveLow) {
                Pin::SetHigh();
            } else {
                Pin::SetLow();
            }
        }

        /** @brief 读取一条读取线,按极性折算为"是否按下"。 */
        template <typename Pin>
        [[gnu::always_inline]] [[nodiscard]] static bool senseIsPressed() noexcept {
            const bool level = Pin::Read();
            return DriveActiveLow ? !level : level;
        }

        /** @brief 配置全部驱动线为输出并置空闲电平(编译期展开)。 */
        template <std::size_t... Indices>
        [[gnu::always_inline]] static void initializeDriveLines(std::index_sequence<Indices...>) noexcept {
            (configureDriveLine<typename DriveGroup::template PinAt<Indices>>(), ...);
        }

        /** @brief 配置单条驱动线:复用 GPIO→输出→空闲电平。 */
        template <typename Pin>
        [[gnu::always_inline]] static void configureDriveLine() noexcept {
            Pin::SetMuxToGpio();
            Pin::ConfigureAsOutput();
            deselectLine<Pin>();
        }

        /** @brief 配置全部读取线为输入(编译期展开)。 */
        template <std::size_t... Indices>
        [[gnu::always_inline]] static void initializeSenseLines(std::index_sequence<Indices...>) noexcept {
            (configureSenseLine<typename SenseGroup::template PinAt<Indices>>(), ...);
        }

        /** @brief 配置单条读取线:复用 GPIO→输入。 */
        template <typename Pin>
        [[gnu::always_inline]] static void configureSenseLine() noexcept {
            Pin::SetMuxToGpio();
            Pin::ConfigureAsInput();
        }

        /** @brief 读取全部读取线并打包成位图:位 s = 读取线 s 是否按下(编译期展开)。 */
        template <std::size_t... Indices>
        [[gnu::always_inline]] [[nodiscard]] static std::uint32_t readSenseBits(
            std::index_sequence<Indices...>) noexcept {
            std::uint32_t bits = 0u;
            ((bits |= senseIsPressed<typename SenseGroup::template PinAt<Indices>>() ? (1u << Indices) : 0u),
             ...);
            return bits;
        }
    };

} // namespace Hardware::Drivers::Keyboard

#endif // EXIST_OS_NEXT_HARDWARE_DRIVERS_KEYBOARD
