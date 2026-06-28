# -*- coding: utf-8 -*-
"""从 CMSIS-SVD 生成 Hardware/Registers 下的零开销寄存器实例化头文件。

把 Utilities/STMP3770.svd 里的每个外设/寄存器/字段,翻译成 Hardware/CoreAbstract
抽象层(Register / RegisterWithSetClearToggle / Field)的强类型别名:

    Hardware::Registers::<外设>::<寄存器>::Reg          —— 寄存器后端(整字读写/原子位别名)
    Hardware::Registers::<外设>::<寄存器>::<字段>       —— 强类型 Field
    Hardware::Registers::<外设>::<寄存器>::<字段>_Values —— 带枚举取值的字段值类型

设计要点:
  - SET/CLR/TOG 原子别名 SVD 未编码,按 STMP 几何惯例判定:非只读、地址 0x10 对齐、
    且到下一寄存器跨度 ≥0x10 → RegisterWithSetClearToggle(别名 = 主 +0x4/+0x8/+0xC);
    否则普通 Register。
  - dim 数组寄存器(名字带 %s)展开为 <名字>0、<名字>1 … 各自独立实例。
  - 每寄存器自占一个嵌套命名空间,字段同名不会跨寄存器冲突。
  - SVD 的中文 description 原样落为 Doxygen 注释。

用法(经 uv):
    uv run python Utilities/GenerateRegisters.py
"""

import os
import re
import xml.etree.ElementTree as ElementTree

REPOSITORY_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SVD_PATH = os.path.join(REPOSITORY_ROOT, "Utilities", "STMP3770.svd")
OUTPUT_DIRECTORY = os.path.join(REPOSITORY_ROOT, "Hardware", "Registers")

ATOMIC_ALIAS_STRIDE = 0x10  # 主寄存器后接 SET(+4)/CLR(+8)/TOG(+C),共占 0x10。


def CleanDescription(rawText):
    """把 SVD description 压成单行 Doxygen 文本(去多余空白,避让注释结束符)。"""
    if not rawText:
        return ""
    collapsed = re.sub(r"\s+", " ", rawText).strip()
    return collapsed.replace("*/", "* /")


def ParseInteger(text):
    """解析 SVD 里的十进制 / 0x 十六进制整数。"""
    return int(text, 0)


def SanitizeIdentifier(name):
    """保证是合法 C++ 标识符(数字开头补下划线)。SVD 名基本已合规。"""
    cleaned = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if cleaned and cleaned[0].isdigit():
        cleaned = "_" + cleaned
    return cleaned


class FieldModel:
    """一个位域:偏移、位宽、可选枚举取值。"""

    def __init__(self, name, bitOffset, bitWidth, description, enumerations):
        self.name = SanitizeIdentifier(name)
        self.bitOffset = bitOffset
        self.bitWidth = bitWidth
        self.description = description
        self.enumerations = enumerations  # [(名字, 值, 描述)]


class RegisterModel:
    """一个具体寄存器实例(dim 已展开):绝对地址、访问权限、字段、是否带原子别名。"""

    def __init__(self, name, absoluteAddress, isReadOnly, description, fields):
        self.name = SanitizeIdentifier(name)
        self.absoluteAddress = absoluteAddress
        self.isReadOnly = isReadOnly
        self.description = description
        self.fields = fields
        self.hasAtomicAlias = False  # 由几何规则在外设层面回填。


def ExtractFields(registerElement):
    """从 <register> 抽取全部 <field>(含枚举取值)。"""
    fields = []
    for fieldElement in registerElement.findall("./fields/field"):
        name = fieldElement.findtext("name")
        bitOffset = ParseInteger(fieldElement.findtext("bitOffset"))
        bitWidth = ParseInteger(fieldElement.findtext("bitWidth"))
        description = CleanDescription(fieldElement.findtext("description"))

        enumerations = []
        seenNames = set()
        for enumElement in fieldElement.findall(".//enumeratedValue"):
            enumName = enumElement.findtext("name")
            enumValueText = enumElement.findtext("value")
            if not enumName or enumValueText is None:
                continue
            enumName = SanitizeIdentifier(enumName)
            if enumName in seenNames:
                continue  # 同字段内枚举名去重,避免重复 enumerator。
            seenNames.add(enumName)
            enumerations.append((enumName, ParseInteger(enumValueText),
                                 CleanDescription(enumElement.findtext("description"))))

        fields.append(FieldModel(name, bitOffset, bitWidth, description, enumerations))
    fields.sort(key=lambda item: item.bitOffset)
    return fields


def ExpandRegister(registerElement, baseAddress):
    """把单个 <register> 展开为一个或多个 RegisterModel(处理 dim 数组)。"""
    name = registerElement.findtext("name")
    addressOffset = ParseInteger(registerElement.findtext("addressOffset"))
    # 设备默认 read-write;仅当寄存器显式标 read-only 才视为只读。
    isReadOnly = (registerElement.findtext("access") == "read-only")
    description = CleanDescription(registerElement.findtext("description"))
    fields = ExtractFields(registerElement)

    dimText = registerElement.findtext("dim")
    if dimText is None:
        return [RegisterModel(name, baseAddress + addressOffset, isReadOnly,
                              description, fields)]

    # dim 数组:dim 份,步长 dimIncrement,名字里的 %s 换成索引。
    count = ParseInteger(dimText)
    increment = ParseInteger(registerElement.findtext("dimIncrement"))
    expanded = []
    for index in range(count):
        elementName = name.replace("%s", str(index))
        elementAddress = baseAddress + addressOffset + index * increment
        expanded.append(RegisterModel(elementName, elementAddress, isReadOnly,
                                      description, fields))
    return expanded


def AssignAtomicAliases(registers):
    """几何法回填 hasAtomicAlias:非只读、0x10 对齐、到下一寄存器跨度 ≥0x10。"""
    ordered = sorted(registers, key=lambda item: item.absoluteAddress)
    for position, register in enumerate(ordered):
        if register.isReadOnly:
            continue
        if register.absoluteAddress % ATOMIC_ALIAS_STRIDE != 0:
            continue
        if position + 1 < len(ordered):
            span = ordered[position + 1].absoluteAddress - register.absoluteAddress
        else:
            span = ATOMIC_ALIAS_STRIDE  # 末尾寄存器:地址块惯例保证别名空间存在。
        if span >= ATOMIC_ALIAS_STRIDE:
            register.hasAtomicAlias = True


def AccessExpression(isReadOnly):
    return "LowLevel::Access::ReadOnly" if isReadOnly else "LowLevel::Access::ReadWrite"


def RenderField(field, lines):
    """渲染一个字段:可选强类型枚举 + Field 别名。"""
    valueType = "std::uint32_t"
    if field.enumerations:
        enumTypeName = field.name + "_Values"
        valueType = enumTypeName
        if field.description:
            lines.append("        /** @brief %s 的取值。 */" % field.name)
        lines.append("        enum class %s : std::uint32_t {" % enumTypeName)
        for enumName, enumValue, enumDescription in field.enumerations:
            trailing = (" /**< %s */" % enumDescription) if enumDescription else ""
            lines.append("            %s = 0x%X,%s" % (enumName, enumValue, trailing))
        lines.append("        };")

    aliasText = "        using %s = LowLevel::Field<Reg, LowLevel::Bit::Bit%d, %d, %s>;" % (
        field.name, field.bitOffset, field.bitWidth, valueType)
    if field.description:
        aliasText += " /**< %s */" % field.description
    lines.append(aliasText)


def RenderRegister(register, lines):
    """渲染一个寄存器命名空间:Reg 后端 + 全部字段。"""
    if register.description:
        lines.append("    /** @brief %s */" % register.description)
    lines.append("    namespace %s {" % register.name)

    address = register.absoluteAddress
    if register.hasAtomicAlias:
        lines.append("        /** @brief 寄存器后端(带 SET/CLR/TOG 原子位别名)。 */")
        lines.append("        using Reg = LowLevel::RegisterWithSetClearToggle<"
                     "std::uint32_t,")
        lines.append("            0x%08X, 0x%08X, 0x%08X, 0x%08X, %s>;" % (
            address, address + 0x4, address + 0x8, address + 0xC,
            AccessExpression(register.isReadOnly)))
    else:
        lines.append("        /** @brief 寄存器后端(普通整字 ldr/str)。 */")
        lines.append("        using Reg = LowLevel::Register<std::uint32_t, 0x%08X, %s>;"
                     % (address, AccessExpression(register.isReadOnly)))

    for field in register.fields:
        RenderField(field, lines)

    lines.append("    } // namespace %s" % register.name)


def RenderPeripheral(peripheralName, peripheralDescription, registers):
    """渲染一个外设头文件全文。"""
    guard = "EXIST_OS_NEXT_HARDWARE_REGISTERS_" + peripheralName.upper()
    lines = []
    lines.append("#ifndef " + guard)
    lines.append("#define " + guard)
    lines.append("")
    lines.append("/**")
    lines.append(" * @file %s.hpp" % peripheralName)
    lines.append(" * @brief %s 外设寄存器实例化(由 Utilities/GenerateRegisters.py 从 SVD 生成)。"
                 % peripheralName)
    if peripheralDescription:
        lines.append(" *")
        lines.append(" * %s" % peripheralDescription)
    lines.append(" *")
    lines.append(" * @warning 本文件为自动生成,请勿手改;改 SVD 后重跑生成器。")
    lines.append(" */")
    lines.append("")
    lines.append('#include "../CoreAbstract/Field.hpp"')
    lines.append('#include "../CoreAbstract/Register.hpp"')
    lines.append("#include <cstdint>")
    lines.append("")
    lines.append("namespace Hardware::Registers::%s {" % peripheralName)
    lines.append("")

    for index, register in enumerate(registers):
        RenderRegister(register, lines)
        if index + 1 < len(registers):
            lines.append("")

    lines.append("")
    lines.append("} // namespace Hardware::Registers::%s" % peripheralName)
    lines.append("")
    lines.append("#endif // " + guard)
    lines.append("")
    return "\n".join(lines)


def Main():
    tree = ElementTree.parse(SVD_PATH)
    root = tree.getroot()

    if not os.path.isdir(OUTPUT_DIRECTORY):
        os.makedirs(OUTPUT_DIRECTORY)

    peripheralNames = []
    totalRegisters = 0
    totalFields = 0

    for peripheralElement in root.findall(".//peripheral"):
        peripheralName = SanitizeIdentifier(peripheralElement.findtext("name"))
        peripheralDescription = CleanDescription(peripheralElement.findtext("description"))
        baseAddress = ParseInteger(peripheralElement.findtext("baseAddress"))

        registers = []
        for registerElement in peripheralElement.findall(".//register"):
            registers.extend(ExpandRegister(registerElement, baseAddress))

        AssignAtomicAliases(registers)
        registers.sort(key=lambda item: item.absoluteAddress)

        content = RenderPeripheral(peripheralName, peripheralDescription, registers)
        outputPath = os.path.join(OUTPUT_DIRECTORY, peripheralName + ".hpp")
        with open(outputPath, "w", encoding="utf-8", newline="\n") as outputFile:
            outputFile.write(content)

        peripheralNames.append(peripheralName)
        totalRegisters += len(registers)
        totalFields += sum(len(register.fields) for register in registers)

    # 汇总头:一站式包含全部外设。
    aggregateLines = []
    aggregateLines.append("#ifndef EXIST_OS_NEXT_HARDWARE_REGISTERS")
    aggregateLines.append("#define EXIST_OS_NEXT_HARDWARE_REGISTERS")
    aggregateLines.append("")
    aggregateLines.append("/**")
    aggregateLines.append(" * @file Registers.hpp")
    aggregateLines.append(" * @brief STMP3770 全部外设寄存器实例化的汇总入口(自动生成)。")
    aggregateLines.append(" *")
    aggregateLines.append(" * 各外设位于 Hardware::Registers::<外设> 命名空间;按需单独包含对应头可减小翻译单元。")
    aggregateLines.append(" */")
    aggregateLines.append("")
    for peripheralName in peripheralNames:
        aggregateLines.append('#include "%s.hpp"' % peripheralName)
    aggregateLines.append("")
    aggregateLines.append("#endif // EXIST_OS_NEXT_HARDWARE_REGISTERS")
    aggregateLines.append("")
    with open(os.path.join(OUTPUT_DIRECTORY, "Registers.hpp"), "w",
              encoding="utf-8", newline="\n") as aggregateFile:
        aggregateFile.write("\n".join(aggregateLines))

    print("已生成 %d 个外设头,共 %d 个寄存器、%d 个字段 → %s"
          % (len(peripheralNames), totalRegisters, totalFields, OUTPUT_DIRECTORY))


if __name__ == "__main__":
    Main()
