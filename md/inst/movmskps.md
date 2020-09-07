----------------------------
title : MOVMSKPS (Intel x86/64 assembly instruction)
cat_title : MOVMSKPS
ref_title : MOVMSKPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MOVMSKPS

**Extract Packed Single-Precision Floating-Point Sign Mask**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|0F 50 /r\newline{}\newline{}MOVMSKPS reg, xmm|RM|V/V|SSE|Extract 4-bit sign mask from xmm and store in reg. The upper bits of r32 or r64 are filled with zeros.|
|VEX.128.0F.WIG 50 /r\newline{}\newline{}VMOVMSKPS reg, xmm2|RM|V/V|AVX|Extract 4-bit sign mask from xmm2 and store in reg. The upper bits of r32 or r64 are zeroed.|
|VEX.256.0F.WIG 50 /r\newline{}\newline{}VMOVMSKPS reg, ymm2|RM|V/V|AVX|Extract 8-bit sign mask from ymm2 and store in reg. The upper bits of r32 or r64 are zeroed.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Extracts the sign bits from the packed single-precision floating-point values in the source operand (second operand), formats them into a 4- or 8-bit mask, and stores the mask in the destination operand (first operand). The source operand is an XMM or YMM register, and the destination operand is a general-purpose register. The mask is stored in the 4 or 8 low-order bits of the destination operand. The upper bits of the destination operand beyond the mask are filled with zeros.

In 64-bit mode, the instruction can access additional registers (XMM8-XMM15, R8-R15) when used with a REX.R prefix. The default operand size is 64-bit in 64-bit mode.

128-bit versions: The source operand is a YMM register. The destination operand is a general purpose register. 

VEX.256 encoded version: The source operand is a YMM register. The destination operand is a general purpose register. 

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation

```info-verb
DEST[0] <- SRC[31]; 
DEST[1] <- SRC[63]; 
DEST[2] <- SRC[95]; 
DEST[3] <- SRC[127]; 
IF DEST = r32
    THEN DEST[31:4] <- ZeroExtend;
    ELSE DEST[63:4] <- ZeroExtend;
FI;
```
```sidenote


1. ModRM.MOD = 011B required
```

**(V)MOVMSKPS (128-bit version)**

DEST[0] <-  SRC[31]

DEST[1] <-  SRC[63]

DEST[2] <-  SRC[95]

DEST[3] <-  SRC[127]

IF DEST = r32

    THEN DEST[31:4] <-  0;

    ELSE DEST[63:4] <-  0;

FI

**VMOVMSKPS (VEX.256 encoded version)**

DEST[0] <-  SRC[31]

DEST[1] <-  SRC[63]

DEST[2] <-  SRC[95]

DEST[3] <-  SRC[127]

DEST[4] <-  SRC[159]

DEST[5] <-  SRC[191]

DEST[6] <-  SRC[223]

DEST[7] <-  SRC[255]

IF DEST = r32

    THEN DEST[31:8] <-  0;

    ELSE DEST[63:8] <-  0;

FI


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
int _mm_movemask_ps(__m128 a)
int _mm256_movemask_ps(__m256 a)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 7; additionally

#UD  If VEX.vvvv ->  1111B.

