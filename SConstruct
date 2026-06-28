# -*- coding: utf-8 -*-
"""ExistOS-Next 构建 + 测试系统(SCons)。

CoreAbstract 是 header-only 的 ARM926EJ-S(ARMv5TEJ)零开销寄存器抽象层。本脚本
统一驱动两侧验证,并为语言服务器生成 compile_commands.json:

    scons                 # 默认:编译主机侧测试 + 生成 compile_commands.json
    scons test            # 运行全部测试(主机单测 / 编译期断言 / 负向编译 / 目标零开销)
    scons compile_commands.json   # 仅(重新)生成编译数据库
    scons -c              # 清理产物

测试分三层(详见 Tests/Hardware/CoreAbstract/README.md):
    - 主机运行期(clang++):Unit/ 真跑断言、CompileTime/ static_assert 编过即通过;
    - 负向编译(clang++):Negative/ 每个用例必须编译失败;
    - 目标(arm-none-eabi-g++):ZeroOverheadProbes 反汇编逐条核对零开销,
      IntegrationCompose 与各头自洽性以 -Werror 编为目标 .o(只编不跑)。

工具链经 PATH 自动发现,可用变量覆盖(机器无关):
    scons CXX=/path/clang++ TARGET_CXX=/path/arm-none-eabi-g++ TARGET_OBJDUMP=/path/...
"""

import os
import re
import subprocess

# ============================================================================
# 路径常量(全部相对仓库根,保证 compile_commands.json 机器无关)
# ============================================================================
LIBRARY_INCLUDE = "Hardware/CoreAbstract"
REGISTERS_INCLUDE = "Hardware/Registers"
TEST_SUPPORT_INCLUDE = "Tests/Hardware/CoreAbstract/TestSupport"

TEST_BASE = Dir("#Tests/Hardware/CoreAbstract")
UNIT_DIR = TEST_BASE.Dir("Unit")
COMPILE_TIME_DIR = TEST_BASE.Dir("CompileTime")
NEGATIVE_DIR = TEST_BASE.Dir("Negative")
TARGET_DIR = TEST_BASE.Dir("Target")
LIBRARY_DIR = Dir("#" + LIBRARY_INCLUDE)
REGISTERS_DIR = Dir("#" + REGISTERS_INCLUDE)
BUILD_DIR = Dir("#build")

# 受测的五个头(用于目标侧"逐头自洽"编译)。
LIBRARY_HEADERS = ["Bit", "Concepts", "Field", "Register", "PSR", "CP15"]

# 目标侧编译标志:ARM926EJ-S / ARMv5TEJ。
TARGET_ARCH_FLAGS = ["-march=armv5te", "-mcpu=arm926ej-s", "-ffreestanding"]

# ============================================================================
# 可覆盖变量
# ============================================================================
buildVariables = Variables()
buildVariables.Add("CXX", "主机 C++ 编译器(默认从 PATH 找 clang++)",
                   os.environ.get("CXX"))
buildVariables.Add("TARGET_CXX", "目标交叉编译器(默认 arm-none-eabi-g++)",
                   os.environ.get("TARGET_CXX"))
buildVariables.Add("TARGET_OBJDUMP", "目标反汇编器(默认 arm-none-eabi-objdump)",
                   os.environ.get("TARGET_OBJDUMP"))

# ============================================================================
# 主机环境:clang++,负责单测 / 编译期断言 / 负向编译,并产出 compile_commands.json
# ============================================================================
hostEnv = Environment(
    variables=buildVariables,
    ENV=os.environ,
    tools=["clangxx", "clang", "link", "compilation_db"],
)
hostEnv["CXX"] = hostEnv.get("CXX") or hostEnv.Detect(["clang++"]) or "clang++"
hostEnv["CC"] = hostEnv["CXX"]
hostEnv.Replace(LINK="$CXX")
hostEnv.Append(
    CXXFLAGS=["-std=c++23", "-Wall", "-Wextra",
              "-I", LIBRARY_INCLUDE, "-I", TEST_SUPPORT_INCLUDE],
    LINKFLAGS=["-std=c++23"],
)

# compile_commands.json:相对路径 file/output,directory 取仓库根。
hostEnv["COMPILATIONDB_USE_ABSPATH"] = False
compilationDatabase = hostEnv.CompilationDatabase("compile_commands.json")

# ============================================================================
# 目标环境:arm-none-eabi-g++,负责零开销反汇编核对 + 组合/自洽编译
# ============================================================================
targetEnv = hostEnv.Clone()
targetEnv["CXX"] = (targetEnv.get("TARGET_CXX")
                    or targetEnv.Detect(["arm-none-eabi-g++"])
                    or "arm-none-eabi-g++")
targetEnv["OBJDUMP"] = (targetEnv.get("TARGET_OBJDUMP")
                        or targetEnv.Detect(["arm-none-eabi-objdump"])
                        or "arm-none-eabi-objdump")

haveTargetToolchain = bool(targetEnv.get("TARGET_CXX")) or \
    targetEnv.WhereIs(targetEnv["CXX"]) is not None

# ============================================================================
# 零开销断言表:对每个探针符号,逐项核对 objdump 反汇编的指令形态。
# 由 Tests/.../Target/check_target.sh 的人工断言移植而来,与 ZeroOverheadProbes.cpp
# 的 extern "C" 符号一一对应。kind ∈ {present, absent, count}。
# ============================================================================
# (symbol, kind, pattern, expectedCount, description)
PROBE_ASSERTIONS = [
    # ---- MMIO ----
    ("ProbeRegisterRead", "present", r"ldr\s+r[0-9]+, \[r[0-9]+\]", None,
     "Register::Read 含 ldr 间接访存"),
    ("ProbeRegisterWrite", "count", r"\bstr\b", 1, "Register::Write = 单条 str"),
    ("ProbeRegisterModify", "absent", r"\bbl\b", None,
     "Register::Modify 无函数调用(内联 RMW)"),
    ("ProbeAliasSet", "count", r"\bstr\b", 1, "别名 Set = 单条 str"),
    ("ProbeAliasClear", "count", r"\bstr\b", 1, "别名 Clear = 单条 str"),
    ("ProbeAliasToggle", "count", r"\bstr\b", 1, "别名 Toggle = 单条 str"),
    # ---- Field over MMIO ----
    ("ProbeWriteFields", "count", r"\bstr\b", 1, "WriteFields 合并为单次写(1×str)"),
    ("ProbeWriteFields", "count", r"ldr\s+r[0-9]+, \[r[0-9]+\]", 1,
     "WriteFields 仅一次回读(1×ldr 间接)"),
    # 字段级 Set/Clear/Toggle 在带别名后端上分派到单条原子 str,且无回读(非 RMW)。
    ("ProbeAliasFieldSet", "count", r"\bstr\b", 1, "字段级原子 Set = 单条 str→别名"),
    ("ProbeAliasFieldSet", "absent", r"ldr\s+r[0-9]+, \[r[0-9]+\]", None,
     "字段级原子 Set 无回读(非 RMW)"),
    ("ProbeAliasFieldClear", "count", r"\bstr\b", 1, "字段级原子 Clear = 单条 str→别名"),
    ("ProbeAliasFieldClear", "absent", r"ldr\s+r[0-9]+, \[r[0-9]+\]", None,
     "字段级原子 Clear 无回读(非 RMW)"),
    ("ProbeAliasFieldToggle", "count", r"\bstr\b", 1, "字段级原子 Toggle = 单条 str→别名"),
    ("ProbeAliasFieldToggle", "absent", r"ldr\s+r[0-9]+, \[r[0-9]+\]", None,
     "字段级原子 Toggle 无回读(非 RMW)"),
    # ---- PSR ----
    ("ProbeCPSRRead", "count", r"\bmrs\b", 1, "Cpsr::Read = 单条 mrs"),
    ("ProbeCPSRRead", "count", r"\bmsr\b", 0, "Cpsr::Read 不含 msr"),
    ("ProbeDisableInterrupt", "count", r"\bmrs\b", 1, "DisableInterrupt 含 1×mrs"),
    ("ProbeDisableInterrupt", "count", r"\bmsr\b", 1, "DisableInterrupt 含 1×msr(cpsr_c)"),
    ("ProbeDisableInterrupt", "count", r"\borr\b", 1, "DisableInterrupt 含 1×orr(置 I 位)"),
    ("ProbeEnableInterrupt", "count", r"\bbic\b", 1, "EnableInterrupt 含 1×bic(清 I 位)"),
    ("ProbeRestoreInterrupt", "count", r"\bmsr\b", 1, "RestoreInterrupt = 单条 msr"),
    ("ProbeCriticalSection", "absent", r"\bbl\b", None, "CriticalSection 无函数调用"),
    ("ProbeCriticalSection", "absent", r"\b(push|pop|stmfd|stmdb|ldmia|ldmfd)\b", None,
     "CriticalSection 无 push/pop"),
    ("ProbeCriticalSection", "absent", r"\bsp\b", None, "CriticalSection 不触碰 sp(无栈溢出)"),
    ("ProbeCriticalSection", "count", r"\bmsr\b", 2, "CriticalSection = 进出各一次 msr"),
    ("ProbeModifyAtomic", "absent", r"\bbl\b", None, "ModifyAtomic 无函数调用"),
    ("ProbeModifyAtomic", "count", r"\bmsr\b", 2, "ModifyAtomic = 关/开中断各一次 msr"),
    # ---- CP15 ----
    ("ProbeSCTLRRead", "count", r"\bmrc\b", 1, "SCTLR::Read = 单条 mrc"),
    ("ProbeSCTLRWrite", "count", r"\bmcr\b", 1, "SCTLR::Write = 单条 mcr"),
    ("ProbeSCTLRFieldSet", "count", r"\bmrc\b", 1, "SCTLR 字段 Set 含 1×mrc"),
    ("ProbeSCTLRFieldSet", "count", r"\bmcr\b", 1, "SCTLR 字段 Set 含 1×mcr"),
    ("ProbeSCTLRFieldSet", "count", r"\borr\b", 1, "SCTLR 字段 Set 含 1×orr(RMW)"),
    ("ProbeInvalidateInstructionCacheAll", "count", r"cr7, cr5, \{0\}", 1,
     "InvalidateInstructionCacheAll = mcr c7,c5,0"),
    ("ProbeDrainWriteBuffer", "count", r"cr7, cr10, \{4\}", 1,
     "DrainWriteBuffer = mcr c7,c10,4"),
    ("ProbeInvalidateUnifiedTLBAll", "count", r"cr8, cr7, \{0\}", 1,
     "InvalidateUnifiedTLBAll = mcr c8,c7,0"),
    ("ProbeInvalidateDataCacheLine", "count", r"cr7, cr6, \{1\}", 1,
     "InvalidateDataCacheLine = mcr c7,c6,1"),
    ("ProbeCleanDataCacheAll", "present", r"cr7, cr10, \{3\}", None,
     "CleanDataCacheAll 用 test-clean MRC(c7,c10,3)"),
    ("ProbeCleanDataCacheAll", "present", r"\bbne\b", None, "CleanDataCacheAll 含自回边 bne"),
    ("ProbeCleanDataCacheAll", "present", r"cr7, cr10, \{4\}", None,
     "CleanDataCacheAll 末尾排空写缓冲"),
    ("ProbeCleanInvalidateDataCacheAll", "present", r"cr7, cr14, \{3\}", None,
     "CleanInvalidateDataCacheAll 用 test-clean MRC(c7,c14,3)"),
    ("ProbeCleanInvalidateDataCacheAll", "present", r"\bbne\b", None,
     "CleanInvalidateDataCacheAll 含自回边 bne"),
    # ---- SPSR ----
    ("ProbeSPSRRead", "present", r"mrs\s+r[0-9]+, SPSR", None, "Spsr::Read = mrs ...,SPSR"),
    ("ProbeSPSRWrite", "present", r"msr\s+SPSR", None, "Spsr::Write = msr SPSR_..."),
    ("ProbeSPSRGetMode", "count", r"\bmrs\b", 1, "Spsr::GetMode 含 1×mrs"),
]

# 全局红线:整段反汇编不得出现(任一探针被 outline 成调用,或出现 ARMv6+ 指令)。
GLOBAL_FORBIDDEN = [
    (r"\bbl\b", "出现 bl —— 有访问器被 outline 成函数调用"),
    (r"\b(ldrex|strex)\b", "出现 ldrex/strex —— ARMv6+ 指令,ARM926 不该有"),
]


def extractSymbolBlock(disassembly, symbol):
    """取某符号的指令块:从 `<symbol>:` 之后到下一空行为止。"""
    block = []
    capturing = False
    marker = "<%s>:" % symbol
    for line in disassembly.splitlines():
        if not capturing:
            if marker in line:
                capturing = True
            continue
        if line.strip() == "":
            break
        block.append(line)
    return block


def countMatchingLines(lines, pattern):
    """统计匹配 pattern 的行数(等价 grep -cE)。"""
    compiled = re.compile(pattern)
    return sum(1 for line in lines if compiled.search(line))


# ============================================================================
# Builder:主机测试可执行文件 —— 运行,退出码非零即失败
# ============================================================================
def runHostTestAction(target, source, env):
    executable = source[0].abspath
    print("运行主机测试: %s" % os.path.basename(executable))
    try:
        result = subprocess.run([executable], capture_output=True, text=True,
                                timeout=120, env=env["ENV"])
    except Exception as error:
        print("  执行失败: %s" % error)
        return 1
    if result.returncode != 0:
        print("  [FAIL] 退出码 %d" % result.returncode)
        if result.stdout:
            print(result.stdout)
        if result.stderr:
            print(result.stderr)
        return 1
    with open(target[0].abspath, "w") as marker:
        marker.write("PASSED\n")
    return 0


# ============================================================================
# Builder:负向编译 —— 必须编译失败,成功反而判失败
# ============================================================================
def negativeCompileAction(target, source, env):
    sourcePath = source[0].abspath
    scratchObject = target[0].abspath + ".o"
    command = [env["CXX"]] + env.subst("$CXXFLAGS").split() + \
        ["-c", sourcePath, "-o", scratchObject]
    print("负向编译(期望失败): %s" % os.path.basename(sourcePath))
    try:
        result = subprocess.run(command, capture_output=True, text=True,
                                timeout=120, env=env["ENV"])
    except Exception as error:
        print("  执行失败: %s" % error)
        return 1
    if os.path.exists(scratchObject):
        os.remove(scratchObject)
    if result.returncode == 0:
        print("  [FAIL] 竟然编译通过了(应当失败)")
        return 1
    with open(target[0].abspath, "w") as marker:
        marker.write("NEGATIVE PASSED\n")
    return 0


# ============================================================================
# Builder:目标编译并核对零开销 —— 反汇编逐项断言
# ============================================================================
def targetProbeAction(target, source, env):
    sourcePath = source[0].abspath
    scratchObject = target[0].abspath + ".o"
    compileCommand = [env["CXX"]] + env.subst("$CXXFLAGS").split() + \
        TARGET_ARCH_FLAGS + ["-O2", "-c", sourcePath, "-o", scratchObject]
    print("目标零开销核对: %s" % os.path.basename(sourcePath))
    compileResult = subprocess.run(compileCommand, capture_output=True, text=True,
                                   timeout=120, env=env["ENV"])
    if compileResult.returncode != 0:
        print("  [FAIL] 编译失败:\n%s" % compileResult.stderr)
        return 1
    disassembleResult = subprocess.run(
        [env["OBJDUMP"], "-d", "--no-show-raw-insn", scratchObject],
        capture_output=True, text=True, timeout=60, env=env["ENV"])
    if os.path.exists(scratchObject):
        os.remove(scratchObject)
    if disassembleResult.returncode != 0:
        print("  [FAIL] 反汇编失败:\n%s" % disassembleResult.stderr)
        return 1
    disassembly = disassembleResult.stdout

    failures = []
    # 全局红线
    for pattern, description in GLOBAL_FORBIDDEN:
        if countMatchingLines(disassembly.splitlines(), pattern) > 0:
            failures.append(description)
    # 逐探针断言
    for symbol, kind, pattern, expected, description in PROBE_ASSERTIONS:
        block = extractSymbolBlock(disassembly, symbol)
        if not block:
            failures.append("%s —— 未在反汇编中找到符号 %s" % (description, symbol))
            continue
        hits = countMatchingLines(block, pattern)
        if kind == "present" and hits == 0:
            failures.append("%s —— 未找到 [%s]" % (description, pattern))
        elif kind == "absent" and hits > 0:
            failures.append("%s —— 不应出现 [%s]" % (description, pattern))
        elif kind == "count" and hits != expected:
            failures.append("%s —— 期望 [%s]×%d,实得 ×%d" %
                            (description, pattern, expected, hits))

    if failures:
        print("  [FAIL] %d 项断言未通过:" % len(failures))
        for item in failures:
            print("    - %s" % item)
        return 1
    with open(target[0].abspath, "w") as marker:
        marker.write("TARGET PROBE PASSED\n")
    print("  [ok] 全部零开销断言通过")
    return 0


# ============================================================================
# Builder:目标侧只编不跑 —— -Werror 编为 .o,验证组合/自洽
# ============================================================================
def targetCompileOnlyAction(target, source, env):
    sourcePath = source[0].abspath
    scratchObject = target[0].abspath + ".o"
    command = [env["CXX"]] + env.subst("$CXXFLAGS").split() + \
        TARGET_ARCH_FLAGS + ["-O2", "-Werror", "-c", sourcePath, "-o", scratchObject]
    print("目标 -Werror 编译: %s" % os.path.basename(sourcePath))
    result = subprocess.run(command, capture_output=True, text=True,
                            timeout=120, env=env["ENV"])
    if os.path.exists(scratchObject):
        os.remove(scratchObject)
    if result.returncode != 0:
        print("  [FAIL] 编译失败:\n%s" % result.stderr)
        return 1
    with open(target[0].abspath, "w") as marker:
        marker.write("TARGET COMPILE PASSED\n")
    return 0


hostEnv.Append(BUILDERS={
    "RunHostTest": Builder(action=Action(runHostTestAction, "$SOURCE"), suffix=".passed"),
    "NegativeCompile": Builder(action=Action(negativeCompileAction, "负向编译 $SOURCE"),
                               suffix=".passed", src_suffix=".cpp"),
})
targetEnv.Append(BUILDERS={
    "TargetProbe": Builder(action=Action(targetProbeAction, "目标核对 $SOURCE"),
                           suffix=".passed", src_suffix=".cpp"),
    "TargetCompileOnly": Builder(action=Action(targetCompileOnlyAction, "目标编译 $SOURCE"),
                                 suffix=".passed", src_suffix=".cpp"),
})


# ============================================================================
# 注册测试节点
# ============================================================================
def outputFor(sourceNode, category, suffix):
    """build/<category>/<basename><suffix>。"""
    base = os.path.splitext(sourceNode.name)[0]
    return BUILD_DIR.Dir(category).File(base + suffix)


def sourcesIn(directory):
    return sorted(directory.glob("*.cpp"), key=lambda node: node.name) \
        if directory.exists() else []


hostTestNodes = []       # 主机单测 + 编译期断言(默认编译,test 时运行)
negativeNodes = []       # 负向编译(仅 test)
targetNodes = []         # 目标零开销 + 组合/自洽(默认编译验证 + test)
hostProgramNodes = []    # 进入 compile_commands.json 的主机编译条目

# --- 主机:单元测试 + 编译期断言(同样编为 exe 运行,退出码 0 即通过) ---
for category in ("Unit", "CompileTime"):
    for source in sourcesIn(TEST_BASE.Dir(category)):
        # 显式把目标文件放进 build/,避免污染源码树;compilation_db 仍据此登记。
        objectFile = hostEnv.Object(outputFor(source, category, ".o").abspath, source)
        program = hostEnv.Program(outputFor(source, category, "").abspath, objectFile)
        hostProgramNodes.append(program)
        passed = hostEnv.RunHostTest(outputFor(source, category, ".passed"), program)
        hostEnv.AlwaysBuild(passed)
        hostTestNodes.append(passed)

# --- 主机:负向编译 ---
for source in sourcesIn(NEGATIVE_DIR):
    passed = hostEnv.NegativeCompile(outputFor(source, "Negative", ".passed"), source)
    hostEnv.AlwaysBuild(passed)
    negativeNodes.append(passed)

# --- 目标:零开销 / 组合 / 逐头自洽(缺工具链则跳过) ---
if haveTargetToolchain:
    probes = targetEnv.TargetProbe(
        outputFor(TARGET_DIR.File("ZeroOverheadProbes.cpp"), "Target", ".passed"),
        TARGET_DIR.File("ZeroOverheadProbes.cpp"))
    targetEnv.AlwaysBuild(probes)
    targetNodes.append(probes)

    integration = targetEnv.TargetCompileOnly(
        outputFor(TARGET_DIR.File("IntegrationCompose.cpp"), "Target", ".passed"),
        TARGET_DIR.File("IntegrationCompose.cpp"))
    targetEnv.AlwaysBuild(integration)
    targetNodes.append(integration)

    # 逐头自洽:生成 `#include "X.hpp"\nint main(){}` 再以 -Werror 编译。
    for header in LIBRARY_HEADERS:
        generatedSource = BUILD_DIR.Dir("SelfContained").File(header + ".cpp")

        def writeSelfContained(target, source, env, header=header):
            with open(target[0].abspath, "w") as out:
                out.write('#include "%s.hpp"\nint main() { return 0; }\n' % header)
            return 0

        hostEnv.Command(generatedSource, LIBRARY_DIR.File(header + ".hpp"),
                        Action(writeSelfContained, "生成自洽探针 %s.hpp" % header))
        passed = targetEnv.TargetCompileOnly(
            BUILD_DIR.Dir("SelfContained").File(header + ".passed"), generatedSource)
        targetEnv.AlwaysBuild(passed)
        targetNodes.append(passed)

    # 生成的寄存器层自洽:汇总头 Registers.hpp 含全部外设,以 -Werror 编为目标 .o,
    # 确保 SVD 重新生成后整套实例化在目标编译器下仍零警告通过。
    registersEnv = targetEnv.Clone()
    registersEnv.Append(CXXFLAGS=["-I", REGISTERS_INCLUDE])
    registersProbe = BUILD_DIR.Dir("SelfContained").File("Registers.cpp")

    def writeRegistersProbe(target, source, env):
        with open(target[0].abspath, "w") as out:
            out.write('#include "Registers.hpp"\nint main() { return 0; }\n')
        return 0

    registersEnv.Command(registersProbe, REGISTERS_DIR.File("Registers.hpp"),
                         Action(writeRegistersProbe, "生成自洽探针 Registers.hpp"))
    registersPassed = registersEnv.TargetCompileOnly(
        BUILD_DIR.Dir("SelfContained").File("Registers.passed"), registersProbe)
    registersEnv.AlwaysBuild(registersPassed)
    targetNodes.append(registersPassed)
else:
    print("注意:未找到 %s,跳过目标侧零开销验证。" % targetEnv["CXX"])

# ============================================================================
# 默认目标与 test alias
# ============================================================================
# 默认:生成 compile_commands.json + 编译主机程序与目标产物(不跑负向/单测)。
Default(compilationDatabase, hostProgramNodes, targetNodes)

# test:跑全部(主机单测/编译期/负向/目标)。
Alias("test", hostTestNodes + negativeNodes + targetNodes)

Help("""
目标(targets):
    scons                        编译 + 生成 compile_commands.json(默认)
    scons test                   运行全部测试
    scons compile_commands.json  仅重新生成编译数据库
    scons -c                     清理

变量(machine-independent overrides):
    CXX=<path>             主机 C++ 编译器(默认 clang++)
    TARGET_CXX=<path>      目标交叉编译器(默认 arm-none-eabi-g++)
    TARGET_OBJDUMP=<path>  目标反汇编器(默认 arm-none-eabi-objdump)
""")
