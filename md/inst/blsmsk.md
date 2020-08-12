----------------------------
title : BLSMSK (Intel x86/64 assembly instruction)
cat_title : BLSMSK
ref_title : BLSMSK
path : /X86-64 명령어 레퍼런스
----------------------------
#@ BLSMSK

** Get Mask Up to Lowest Set Bit**

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDD.LZ.0F38.W0 F3 /2BLSMSK r32, r/m32|VM|V/V|BMI1|Set all lower bits in r32 to "1" starting from bit 0 to lowest set bit in r/m32.|
|VEX.NDD.LZ.0F38.W1 F3 /2BLSMSK r64, r/m64|VM|V/N.E.|BMI1|Set all lower bits in r64 to "1" starting from bit 0 to lowest set bit in r/m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|VM|VEX.vvvv (w)|ModRM:r/m (r)|NA|NA|
### Description


Sets all the lower bits of the destination operand to "1" up to and including lowest set bit (=1) in the source operand. If source operand is zero, `BLSMSK` sets all bits of the destination operand to 1 and also sets CF to 1.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.


### Operation

```info-verb
temp <- (SRC-1) XOR (SRC) ;
SF <- temp[OperandSize -1];
ZF <- 0;
IF SRC = 0
    CF <- 1;
ELSE
    CF <- 0;
FI
DEST <- temp;
```
### Flags Affected


SF is updated based on the result. CF is set if the source if zero. ZF and OF flags are cleared. AF and PF flag are undefined.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BLSMSK: unsigned __int32 _blsmsk_u32(unsigned __int32 src);
BLSMSK: unsigned __int64 _blsmsk_u64(unsigned __int64 src);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

