/**
 * @file DriverLogicTests.cpp
 * @brief 驱动层"可剥离 MMIO 的纯逻辑"主机单元测试:DMA 命令字打包、电池电压换算,
 *        以及键盘矩阵"选通→采样→撤销"三原语耦合逻辑(用内存假引脚)。
 *
 * 真正打绝对 MMIO 地址的访问路径(GPIO/LCDIF 等)不在主机运行,仅由目标 objdump 探针守;
 * 本文件只测与后端无关的算法与控制流。键盘逐线原语的引脚动作被替换为内存假引脚,从而可在
 * 主机上真跑并核对"只有被选通驱动线上的按下交叉点才被采到、撤销选通后驱动线复位空闲"。
 */

#include "TestHarness.hpp"

#include "BSP.hpp"
#include "Drivers/Common/DmaDescriptor.hpp"
#include "Drivers/Keyboard.hpp"

#include <cstdint>
#include <utility>

namespace {

using namespace Hardware::Drivers::Common;
namespace BSP = Hardware::BSP;
namespace Keyboard = Hardware::Drivers::Keyboard;

/* ======================================================================
 *  键盘扫描的主机假引脚模型
 *  ------------------------------------------------------------------
 *  共享一个 (drive,sense) 按下矩阵与"当前被拉低的驱动线"状态;假引脚的
 *  SetLow/SetHigh 改写当前选通线,Read 按 active-low 返回该选通线上对应
 *  交叉点是否按下(按下读低)。以此真跑 Matrix::Scan 的耦合逻辑。
 * ====================================================================== */
namespace MatrixModel {
    constexpr std::uint32_t DriveCount = 3u;
    constexpr std::uint32_t SenseCount = 4u;

    bool pressed[DriveCount][SenseCount];   /**< 真值:某交叉点是否按下。 */
    int activeDriveLine = -1;               /**< 当前被拉低(选通)的驱动线下标;-1 = 无。 */

    void reset() noexcept {
        activeDriveLine = -1;
        for (auto& row : pressed) {
            for (bool& cell : row) {
                cell = false;
            }
        }
    }
} // namespace MatrixModel

/** @brief 假驱动线:SetLow 选通(记录自身为当前选通线),SetHigh 撤销。 */
template <int DriveIndex>
struct FakeDriveLine {
    static void SetMuxToGpio() noexcept {}
    static void ConfigureAsOutput() noexcept {}
    static void ConfigureAsInput() noexcept {}
    static void SetLow() noexcept { MatrixModel::activeDriveLine = DriveIndex; }
    static void SetHigh() noexcept {
        if (MatrixModel::activeDriveLine == DriveIndex) {
            MatrixModel::activeDriveLine = -1;
        }
    }
    static bool Read() noexcept { return true; }
};

/** @brief 假读取线:active-low,被选通驱动线上对应交叉点按下时读低(false)。 */
template <int SenseIndex>
struct FakeSenseLine {
    static void SetMuxToGpio() noexcept {}
    static void ConfigureAsOutput() noexcept {}
    static void ConfigureAsInput() noexcept {}
    static void SetLow() noexcept {}
    static void SetHigh() noexcept {}
    static bool Read() noexcept {
        const int drive = MatrixModel::activeDriveLine;
        if (drive < 0) {
            return true; // 无选通:线常态为高
        }
        return !MatrixModel::pressed[drive][SenseIndex]; // 按下读低
    }
};

using FakeDrive = Keyboard::PinGroup<FakeDriveLine<0>, FakeDriveLine<1>, FakeDriveLine<2>>;
using FakeSense = Keyboard::PinGroup<FakeSenseLine<0>, FakeSenseLine<1>, FakeSenseLine<2>, FakeSenseLine<3>>;
using FakeMatrix = Keyboard::Matrix<FakeDrive, FakeSense>; // 默认 active-low

} // namespace

/* ============================ DMA 命令字 ============================ */
TEST_CASE(buildCommandPacksFields) {
    CHECK_EQUAL(BuildCommand({}), 0u);
    CHECK_EQUAL(BuildCommand({.transferType = DmaTransferType::MemoryToDevice}), 0x2u);
    CHECK_EQUAL(BuildCommand({.transferType = DmaTransferType::DeviceToMemory}), 0x1u);
    CHECK_EQUAL(BuildCommand({.pioWordCount = 3}), 3u << 12);
    CHECK_EQUAL(BuildCommand({.transferCount = 0x1FF}), 0x1FFu << 16);
    CHECK_EQUAL(BuildCommand({.chain = true}), 1u << 2);
    CHECK_EQUAL(BuildCommand({.semaphore = true}), 1u << 6);
}

TEST_CASE(buildCommandCombinesByOr) {
    const std::uint32_t command = BuildCommand({.transferType = DmaTransferType::MemoryToDevice,
                                                .transferCount = 512,
                                                .pioWordCount = 1,
                                                .chain = true,
                                                .interruptOnCompletion = true});
    CHECK_EQUAL(command, (512u << 16) | (1u << 12) | (1u << 3) | (1u << 2) | 0x2u);
}

TEST_CASE(buildCommandTruncatesPioWordCountToNibble) {
    // pioWordCount 仅占 4 位,高位被掩掉(0x1F & 0xF = 0xF)。
    CHECK_EQUAL(BuildCommand({.pioWordCount = 0x1F}), 0xFu << 12);
}

/* ============================ 电池换算 ============================ */
TEST_CASE(batteryCodeToMillivolts) {
    CHECK_EQUAL(BSP::BatteryCodeToMillivolts(0u), 0u);
    CHECK_EQUAL(BSP::BatteryCodeToMillivolts(1u), 8u);
    CHECK_EQUAL(BSP::BatteryCodeToMillivolts(500u), 4000u);
    CHECK_EQUAL(BSP::BatteryCodeToMillivolts(1023u), 8184u); // 10 位满码
}

/* ===================== 键盘三原语耦合逻辑(假引脚真跑) =====================
 *  本层不再提供整矩阵 Scan();OS 按 tick 编排"选通→等 settle→采样→撤销"。
 *  此处用一个等价的全展开编排复刻该序列,真跑 SelectDriveLine<i>/ReadSenseLines/
 *  DeselectDriveLine<i> 三原语,核对其耦合语义与原 Scan() 一致。
 * ====================================================================== */

/** @brief 用三原语复刻一次全矩阵扫描(逐驱动线:选通→读全部读取线→撤销选通)。 */
template <std::size_t... Drives>
[[nodiscard]] static FakeMatrix::ScanResult scanViaPrimitivesImpl(
    std::index_sequence<Drives...>) noexcept {
    FakeMatrix::ScanResult result{};
    ((FakeMatrix::SelectDriveLine<Drives>(),
      result.lines[Drives] = FakeMatrix::ReadSenseLines(),
      FakeMatrix::DeselectDriveLine<Drives>()),
     ...);
    return result;
}

/** @brief 复刻全矩阵扫描入口(展开 DriveCount 条驱动线)。 */
[[nodiscard]] static FakeMatrix::ScanResult scanViaPrimitives() noexcept {
    return scanViaPrimitivesImpl(std::make_index_sequence<FakeMatrix::DriveCount>{});
}

TEST_CASE(keyboardPrimitivesEmptyMatrixDetectsNothing) {
    MatrixModel::reset();
    const auto snapshot = scanViaPrimitives();
    CHECK(!snapshot.AnyPressed());
    for (std::uint32_t d = 0u; d < FakeMatrix::DriveCount; ++d) {
        for (std::uint32_t s = 0u; s < FakeMatrix::SenseCount; ++s) {
            CHECK(!snapshot.IsPressed(d, s));
        }
    }
}

TEST_CASE(keyboardPrimitivesDetectExactPressedCrosspoints) {
    MatrixModel::reset();
    MatrixModel::pressed[0][2] = true; // 驱动线 0 × 读取线 2
    MatrixModel::pressed[2][0] = true; // 驱动线 2 × 读取线 0
    MatrixModel::pressed[1][3] = true; // 驱动线 1 × 读取线 3
    const auto snapshot = scanViaPrimitives();

    CHECK(snapshot.AnyPressed());
    for (std::uint32_t d = 0u; d < FakeMatrix::DriveCount; ++d) {
        for (std::uint32_t s = 0u; s < FakeMatrix::SenseCount; ++s) {
            const bool expected = (d == 0u && s == 2u) || (d == 2u && s == 0u) || (d == 1u && s == 3u);
            CHECK_EQUAL(snapshot.IsPressed(d, s), expected);
        }
    }
}

TEST_CASE(keyboardReadSenseLinesOnlySeesSelectedDriveLine) {
    // 只有被选通的那条驱动线上的按下交叉点会被采到:选通线 1 时读不到线 0 的按下。
    MatrixModel::reset();
    MatrixModel::pressed[0][1] = true; // 仅驱动线 0 上按下
    MatrixModel::pressed[1][2] = true; // 仅驱动线 1 上按下

    FakeMatrix::SelectDriveLine<1>();
    const std::uint32_t line1 = FakeMatrix::ReadSenseLines();
    FakeMatrix::DeselectDriveLine<1>();
    // 选通线 1:只应读到 (1,2),读不到 (0,1)。
    CHECK_EQUAL(line1, (1u << 2));
}

TEST_CASE(keyboardDeselectRestoresDriveLineToIdle) {
    MatrixModel::reset();
    MatrixModel::pressed[1][1] = true;
    FakeMatrix::SelectDriveLine<1>();
    CHECK_EQUAL(MatrixModel::activeDriveLine, 1);
    FakeMatrix::DeselectDriveLine<1>();
    // 撤销选通后没有任何驱动线仍被拉低。
    CHECK_EQUAL(MatrixModel::activeDriveLine, -1);
}

TEST_CASE(keyboardScanResultBitLayout) {
    // 直接构造快照,核对位图语义:lines[d] 的位 s = 交叉点 (d,s)。
    FakeMatrix::ScanResult snapshot{};
    snapshot.lines[0] = (1u << 2);
    snapshot.lines[2] = (1u << 0) | (1u << 3);
    CHECK(snapshot.IsPressed(0u, 2u));
    CHECK(!snapshot.IsPressed(0u, 1u));
    CHECK(snapshot.IsPressed(2u, 0u));
    CHECK(snapshot.IsPressed(2u, 3u));
    CHECK(snapshot.AnyPressed());
}

TEST_MAIN()
