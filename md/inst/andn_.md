### ANDN -- Logical AND NOT


|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.LZ.0F38.W0 F2 /rANDN r32a, r32b, r/m32|RVM|V/V|BMI1|Bitwise AND of inverted r32b with r/m32, store result in r32a.|
|VEX.NDS.LZ. 0F38.W1 F2 /rANDN r64a, r64b, r/m64|RVM|V/NE|BMI1|Bitwise AND of inverted r64b with r/m64, store result in r64a.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a bitwise logical AND of inverted second operand (the first source operand) with the third operand (the 

second source operand). The result is stored in the first operand (destination operand).

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.


### Operation

```info-verb
DEST <- (NOT SRC1) bitwiseAND SRC2;
SF <- DEST[OperandSize -1];
ZF <- (DEST = 0);
```
### Flags Affected


SF and ZF are updated based on result. OF and CF flags are cleared. AF and PF flags are undefined.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
Auto-generated from high-level language.
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

