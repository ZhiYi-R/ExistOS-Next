#ifndef EXIST_OS_NEXT_CORE_ABSTRACT_TESTS_TEST_HARNESS
#define EXIST_OS_NEXT_CORE_ABSTRACT_TESTS_TEST_HARNESS

/**
 * @file TestHarness.hpp
 * @brief 零依赖的极简单元测试框架（主机运行期使用）。
 *
 * 设计取向：本仓库是 bare-metal、header-only、无第三方依赖。为保持一致，
 * 测试框架不引入 doctest/GoogleTest，仅用一个百余行的注册器 + 断言宏。
 * 测试代码运行在主机（clang++ x86-64），可自由使用完整 STL（与受测的
 * freestanding 库无关）。
 *
 * 命名约定说明：受测库遵循"全称 + 驼峰"。测试 DSL 的宏（TEST_CASE/CHECK/
 * CHECK_EQUAL）沿用测试框架界通行的全大写宏风格——这是有意为之，既符合宏
 * 的惯例、也避免与库标识符冲突；宏之外的标识符仍遵循驼峰全称。
 *
 * 用法：
 * @code
 *   #include "TestHarness.hpp"
 *   TEST_CASE(myThingDoesX) {
 *       CHECK(condition);
 *       CHECK_EQUAL(actual, expected);
 *   }
 *   TEST_MAIN()
 * @endcode
 */

#include <cstdio>
#include <vector>

namespace TestHarness {

/** @brief 一个测试用例：名字 + 无参函数指针。 */
struct TestCase {
    const char* name; /**< 用例名（即函数名） */
    void (*function)(); /**< 用例体 */
};

/** @brief 全局用例注册表(inline 函数局部静态，跨 TU 唯一)。 */
[[nodiscard]] inline std::vector<TestCase>& registry() noexcept {
    static std::vector<TestCase> cases{};
    return cases;
}

/** @brief 累计执行的断言数。 */
[[nodiscard]] inline int& checkCountTotal() noexcept {
    static int count{0};
    return count;
}
/** @brief 累计失败的断言数。 */
[[nodiscard]] inline int& checkCountFailed() noexcept {
    static int count{0};
    return count;
}
/** @brief 当前用例是否已出现失败断言。 */
[[nodiscard]] inline bool& currentCaseFailed() noexcept {
    static bool failed{false};
    return failed;
}

/** @brief 构造期把用例登记进注册表的小帮手。 */
struct AutoRegister {
    AutoRegister(const char* name, void (*function)()) {
        registry().push_back(TestCase{name, function});
    }
};

/** @brief 记录一次断言失败(打印位置 + 表达式)。 */
inline void reportFailure(const char* file, int line, const char* expression) {
    ++checkCountFailed();
    currentCaseFailed() = true;
    std::printf("    [FAIL] %s:%d  %s\n", file, line, expression);
}

/** @brief 记录一次相等断言失败(附带两侧数值)。 */
inline void reportEqualFailure(const char* file, int line, const char* expression,
                               unsigned long long lhs, unsigned long long rhs) {
    ++checkCountFailed();
    currentCaseFailed() = true;
    std::printf("    [FAIL] %s:%d  %s\n", file, line, expression);
    std::printf("           实际(lhs)=0x%llx  期望(rhs)=0x%llx\n", lhs, rhs);
}

/**
 * @brief 依次运行全部已注册用例。
 * @return 全部通过返回 0，否则返回 1(供 main / CTest 判定)。
 */
[[nodiscard]] inline int runAll() {
    const int caseCount{static_cast<int>(registry().size())};
    std::printf("运行 %d 个测试用例...\n", caseCount);
    int failedCases{0};
    for (const TestCase& testCase : registry()) {
        currentCaseFailed() = false;
        testCase.function();
        if (currentCaseFailed()) {
            ++failedCases;
            std::printf("  [用例失败] %s\n", testCase.name);
        } else {
            std::printf("  [通过] %s\n", testCase.name);
        }
    }
    std::printf("--------\n断言: %d 执行 / %d 失败    用例: %d 执行 / %d 失败\n",
                checkCountTotal(), checkCountFailed(), caseCount, failedCases);
    return failedCases == 0 ? 0 : 1;
}

} // namespace TestHarness

/** @brief 定义并自动注册一个测试用例。 */
#define TEST_CASE(caseName)                                                          \
    static void caseName();                                                          \
    static ::TestHarness::AutoRegister caseName##Registrar(#caseName, &caseName);    \
    static void caseName()

/** @brief 布尔断言。 */
#define CHECK(expression)                                                            \
    do {                                                                             \
        ++::TestHarness::checkCountTotal();                                          \
        if (!(expression)) {                                                         \
            ::TestHarness::reportFailure(__FILE__, __LINE__, #expression);           \
        }                                                                            \
    } while (0)

/** @brief 相等断言(失败时打印两侧数值)。 */
#define CHECK_EQUAL(actual, expected)                                                \
    do {                                                                             \
        ++::TestHarness::checkCountTotal();                                          \
        auto checkActual{(actual)};                                                 \
        auto checkExpected{(expected)};                                             \
        if (!(checkActual == checkExpected)) {                                       \
            ::TestHarness::reportEqualFailure(                                       \
                __FILE__, __LINE__, #actual " == " #expected,                        \
                static_cast<unsigned long long>(checkActual),                        \
                static_cast<unsigned long long>(checkExpected));                     \
        }                                                                            \
    } while (0)

/** @brief 生成测试可执行文件的 main。 */
#define TEST_MAIN()                                                                  \
    int main() { return ::TestHarness::runAll(); }

#endif
