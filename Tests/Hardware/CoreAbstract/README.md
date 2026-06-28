# CoreAbstract 测试套件

针对 `Hardware/CoreAbstract/` 下 ARM926EJ-S(ARMv5TEJ)零开销寄存器抽象层的
单元测试与集成测试。构建与测试统一由仓库根的 **SConstruct** 驱动。

## 为什么分三层?(主机 vs 目标的根本约束)

本抽象层的访问器最终落到三类**特权 / 绝对地址**操作:
- MMIO `Register` 解引用**绝对 MMIO 地址**(`ldr`/`str`);
- `CP15` / `PSR` 走**特权内联汇编**(`mrc`/`mcr`/`mrs`/`msr`)。

这些**无法在开发机(x86)上运行**;本机也**没有 QEMU**,而 CP15/PSR 即便在
QEMU user 模式下也受限,需要 QEMU system 模式或真机。但全库**唯一含算术的逻辑**
都在 `Field<>`(掩码 / 移位 / 读-改-写 / 多字段合并),它只依赖 `Backend` 抽象的
`Read`/`Write`,与具体后端无关。于是测试按"能在哪验证"自然分三层:

| 层 | 验证什么 | 在哪跑 | 手段 |
|----|----------|--------|------|
| **单元(运行期)** | `Field`/`WriteFields` 的位算术真值 | **主机** clang++ | 内存后端替身 + 真跑断言 |
| **编译期断言** | 概念满足性、访问门控、各字段掩码数值 | 主机 **与** 目标 | `static_assert`(编译通过即通过) |
| **负向编译** | 非法用法**必须编译失败** | 主机 clang++ | 期望编译失败(`NegativeCompile` builder) |
| **目标零开销 / 集成** | 每个访问器编出**单指令、无 bl、无栈溢出**;五头协同 `-Werror` | **目标** arm-none-eabi | `-O2` + `objdump` 逐项断言 |

> 真实的 `Register`/`CP15`/`PSR` 后端是**极薄的指令包装**,其"逻辑"就是它编出的那条
> 机器指令——因此它们的行为正确性由**目标 objdump**(正确的单指令 = 正确的行为)
> 保证,而非主机运行期数值核对。两层互补,无盲区。

## 目录结构

测试树镜像源码树,置于仓库根的 `Tests/` 下:

```
Tests/Hardware/CoreAbstract/
  TestSupport/
    TestHarness.hpp           # 零依赖极简单测框架(TEST_CASE / CHECK / CHECK_EQUAL)
    MemoryBackend.hpp         # 内存后端测试替身(满足 Backend / HasSetClearToggle)
  Unit/
    FieldRuntimeTests.cpp     # Field 读写/置清翻/谓词/枚举型/满宽/u16
    WriteFieldsRuntimeTests.cpp # Reg::WriteFields<F...> 多字段合并写
  CompileTime/
    ConceptAssertions.cpp     # Backend/HasSetClearToggle 满足性 + 访问门控
    MaskAssertions.cpp        # GetMask/Shifted/SCTLR/DACR/CPSR 字段数值
  Negative/                   # 10 个"必须编译失败"用例(每个一个 .cpp,PascalCase)
  Target/
    ZeroOverheadProbes.cpp    # 各访问器的 extern "C" 探针(Probe*),供 objdump 定位
    IntegrationCompose.cpp    # 五头协同的端到端用法,-Werror 编为目标 .o
```

零开销断言不再是独立 shell 脚本,而是**移植进 SConstruct**(`PROBE_ASSERTIONS` 表),
与 `ZeroOverheadProbes.cpp` 的 `Probe*` 符号一一对应,跨平台逐条核对。

## 如何运行

从**仓库根**调用 SCons:

```bash
scons          # 默认:编译主机程序 + 目标产物,并生成 compile_commands.json
scons test     # 运行全部测试(主机单测 / 编译期断言 / 负向编译 / 目标零开销)
scons -c       # 清理
```

可用变量覆盖工具链(机器无关):

```bash
scons test CXX=/path/clang++ TARGET_CXX=/path/arm-none-eabi-g++ TARGET_OBJDUMP=/path/arm-none-eabi-objdump
```

## 工具链前置

- **构建系统**:`scons`(≥4.x;自带 Python 解释器,无需系统 `python`)。
- **主机侧**:`clang++`(C++23;本仓库用 clang 22,MSVC ABI)。
- **目标侧**:`arm-none-eabi-g++`(C++23;本仓库用 xPack GCC 15.2.1)、`arm-none-eabi-objdump`。
  缺目标工具链时 SConstruct 会**跳过**目标侧零开销验证,主机侧测试仍照常运行。

## 语言服务器(clangd)

`scons` 在仓库根生成 `compile_commands.json`(相对路径、机器无关的 `directory`),
配合根目录的 `.clangd` 即可让 clangd 正确解析全树。两者均无需手填本机绝对路径。

## 命名约定说明

受测库遵循"全称 + 驼峰"。测试 DSL 的宏(`TEST_CASE`/`CHECK`/`CHECK_EQUAL`)
沿用测试框架界通行的**全大写宏**风格——既符合宏惯例、也避免与库标识符冲突;
宏以外的标识符(含 `Probe*` 探针、`IntegrationScenario`)一律遵循驼峰全称。
