----------------------------
title : BLSI (Intel x86/64 assembly instruction)
cat_title : BLSI
ref_title : BLSI
path : /X86-64 명령어 레퍼런스
----------------------------
#@ BLSI

** Extract Lowest Set Isolated Bit**

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDD.LZ.0F38.W0 F3 /3BLSI r32, r/m32|VM|V/V|BMI1|Extract lowest set bit from r/m32 and set that bit in r32.|
|VEX.NDD.LZ.0F38.W1 F3 /3BLSI r64, r/m64|VM|V/N.E.|BMI1|Extract lowest set bit from r/m64, and set that bit in r64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|VM|VEX.vvvv (w)|ModRM:r/m (r)|NA|NA|
### Description


Extracts the lowest set bit from the source operand and set the corresponding bit in the destination register. All other bits in the destination operand are zeroed. If no bits are set in the source operand, `BLSI` sets all the bits in the destination to 0 and sets ZF and CF.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.


### Operation

```info-verb
temp <- (-SRC) bitwiseAND (SRC); 
SF <- temp[OperandSize -1];
ZF <- (temp = 0);
IF SRC = 0
 CF <- 0;
ELSE
 CF <- 1;
FI
DEST <- temp;
```
### Flags Affected


ZF and SF are updated based on the result. CF is set if the source is not zero. OF flags are cleared. AF and PF flags are undefined.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BLSI: unsigned __int32 _blsi_u32(unsigned __int32 src);
BLSI: unsigned __int64 _blsi_u64(unsigned __int64 src);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

