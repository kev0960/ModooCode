----------------------------
title : CVTSI2SD (Intel x86/64 assembly instruction)
cat_title : CVTSI2SD
ref_title : CVTSI2SD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------
#@ CVTSI2SD

**Convert Doubleword Integer to Scalar Double-Precision Floating-Point Value**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F 2A /r\newline{}CVTSI2SD xmm1, r32/m32|RM|V/V|SSE2|Convert one signed doubleword integer from r32/m32 to one double-precision floating-point value in xmm1.|
|F2 REX.W 0F 2A /r\newline{}CVTSI2SD xmm1, r/m64|RM|V/N.E.|SSE2|Convert one signed quadword integer from r/m64 to one double-precision floating-point value in xmm1.|
|VEX.NDS.128.F2.0F.W0 2A /r\newline{}VCVTSI2SD xmm1, xmm2, r/m32|RVM|V/V|AVX|Convert one signed doubleword integer from r/m32 to one double-precision floating-point value in xmm1.|
|VEX.NDS.128.F2.0F.W1 2A /r\newline{}VCVTSI2SD xmm1, xmm2, r/m64|RVM|V/N.E.\footnote{1}|AVX|Convert one signed quadword integer from r/m64 to one double-precision floating-point value in xmm1.|
|EVEX.NDS.LIG.F2.0F.W0 2A /r\newline{}VCVTSI2SD xmm1, xmm2, r/m32|T1S|V/V|AVX512F|Convert one signed doubleword integer from r/m32 to one double-precision floating-point value in xmm1.|
|EVEX.NDS.LIG.F2.0F.W1 2A /r\newline{}VCVTSI2SD xmm1, xmm2, r/m64{er}|T1S|V/N.E.\footnote{1}|AVX512F|Convert one signed quadword integer from r/m64 to one double-precision floating-point value in xmm1.|
||||||

```note
1. VEX.W1/EVEX.W1 in non-64 bit is ignored; the instructions behaves as if the W0 version is used
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Converts a signed doubleword integer (or signed quadword integer if operand size is 64 bits) in the "convert-from" source operand to a double-precision floating-point value in the destination operand. The result is stored in the low quadword of the destination operand, and the high quadword left unchanged. When conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register.

The second source operand can be a general-purpose register or a 32/64-bit memory location. The first source and destination operands are XMM registers. 

128-bit Legacy SSE version: Use of the REX.W prefix promotes the instruction to 64-bit operands. The "convert-from" source operand (the second operand) is a general-purpose register or memory location. The destination is an XMM register Bits (MAX\esc{_}VL-1:64) of the corresponding destination register remain unchanged.

VEX.128 and EVEX encoded versions: The "convert-from" source operand (the third operand) can be a general-purpose register or a memory location. The first source and destination operands are XMM registers. Bits (127:64) of the XMM register destination are copied from the corresponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX.W0 version: attempt to encode this instruction with EVEX embedded rounding is ignored.

VEX.W1 and EVEX.W1 versions: promotes the instruction to use 64-bit input value in 64-bit mode.

Software should ensure VCVTSI2SD is encoded with VEX.L=0. Encoding VCVTSI2SD with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### VCVTSI2SD (EVEX encoded version)
```info-verb
IF (SRC2 *is register*) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[63:0] <-  Convert_Integer_To_Double_Precision_Floating_Point(SRC2[63:0]);
ELSE
    DEST[63:0] <-  Convert_Integer_To_Double_Precision_Floating_Point(SRC2[31:0]);
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VCVTSI2SD (VEX.128 encoded version)
```info-verb
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[63:0] <- Convert_Integer_To_Double_Precision_Floating_Point(SRC2[63:0]);
ELSE
    DEST[63:0] <- Convert_Integer_To_Double_Precision_Floating_Point(SRC2[31:0]);
FI;
DEST[127:64] <- SRC1[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### CVTSI2SD 
```info-verb
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[63:0] <- Convert_Integer_To_Double_Precision_Floating_Point(SRC[63:0]);
ELSE
    DEST[63:0] <- Convert_Integer_To_Double_Precision_Floating_Point(SRC[31:0]);
FI;
DEST[MAX_VL-1:64] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTSI2SD __m128d _mm_cvti32_sd(__m128d s, int a);
VCVTSI2SD __m128d _mm_cvt_roundi32_sd(__m128d s, int a, int r);
VCVTSI2SD __m128d _mm_cvti64_sd(__m128d s, __int64 a);
VCVTSI2SD __m128d _mm_cvt_roundi64_sd(__m128d s, __int64 a, int r);
CVTSI2SD __m128d _mm_cvtsi64_sd(__m128d s, __int64 a);
CVTSI2SD __m128d_mm_cvtsi32_sd(__m128d a, int b)
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3 if W1, else Type 5.

EVEX-encoded instructions, see Exceptions Type E3NF if W1, else Type E10NF.

