----------------------------
title : CVTSI2SS (Intel x86/64 assembly instruction)
cat_title : CVTSI2SS
ref_title : CVTSI2SS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------
#@ CVTSI2SS

**Convert Doubleword Integer to Scalar Single-Precision Floating-Point Value**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 2A /r\newline{}CVTSI2SS xmm1, r/m32|RM|V/V|SSE|Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.|
|F3 REX.W 0F 2A /r\newline{}CVTSI2SS xmm1, r/m64|RM|V/N.E.|SSE|Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.|
|VEX.NDS.128.F3.0F.W0 2A /r\newline{}VCVTSI2SS xmm1, xmm2, r/m32|RVM|V/V|AVX|Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.|
|VEX.NDS.128.F3.0F.W1 2A /r\newline{}VCVTSI2SS xmm1, xmm2, r/m64|RVM|V/N.E.\footnote{1}|AVX|Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.|
|EVEX.NDS.LIG.F3.0F.W0 2A /r\newline{}VCVTSI2SS xmm1, xmm2, r/m32{er}|T1S|V/V|AVX512F|Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.|
|EVEX.NDS.LIG.F3.0F.W1 2A /r\newline{}VCVTSI2SS xmm1, xmm2, r/m64{er}|T1S|V/N.E.\footnote{1}|AVX512F|Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.|
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


Converts a signed doubleword integer (or signed quadword integer if operand size is 64 bits) in the "convert-from" source operand to a single-precision floating-point value in the destination operand (first operand). The "convert-from" source operand can be a general-purpose register or a memory location. The destination operand is an XMM register. The result is stored in the low doubleword of the destination operand, and the upper three doublewords are left unchanged. When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register or the embedded rounding control bits.

128-bit Legacy SSE version: In 64-bit mode, Use of the REX.W prefix promotes the instruction to use 64-bit input value. The "convert-from" source operand (the second operand) is a general-purpose register or memory location. Bits (MAX\esc{_}VL-1:32) of the corresponding destination register remain unchanged.

VEX.128 and EVEX encoded versions: The "convert-from" source operand (the third operand) can be a general-purpose register or a memory location. The first source and destination operands are XMM registers. Bits (127:32) of the XMM register destination are copied from corresponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX encoded version: the converted result in written to the low doubleword element of the destination under the writemask.

Software should ensure VCVTSI2SS is encoded with VEX.L=0. Encoding VCVTSI2SS with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### VCVTSI2SS (EVEX encoded version)
```info-verb
IF (SRC2 *is register*) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[31:0] <-  Convert_Integer_To_Single_Precision_Floating_Point(SRC[63:0]);
ELSE
    DEST[31:0] <-  Convert_Integer_To_Single_Precision_Floating_Point(SRC[31:0]);
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### VCVTSI2SS (VEX.128 encoded version)
```info-verb
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[31:0] <- Convert_Integer_To_Single_Precision_Floating_Point(SRC[63:0]);
ELSE
    DEST[31:0] <- Convert_Integer_To_Single_Precision_Floating_Point(SRC[31:0]);
FI;
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### CVTSI2SS (128-bit Legacy SSE version)
```info-verb
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[31:0] <- Convert_Integer_To_Single_Precision_Floating_Point(SRC[63:0]);
ELSE
    DEST[31:0] <- Convert_Integer_To_Single_Precision_Floating_Point(SRC[31:0]);
FI;
DEST[MAX_VL-1:32] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTSI2SS __m128 _mm_cvti32_ss(__m128 s, int a);
VCVTSI2SS __m128 _mm_cvt_roundi32_ss(__m128 s, int a, int r);
VCVTSI2SS __m128 _mm_cvti64_ss(__m128 s, __int64 a);
VCVTSI2SS __m128 _mm_cvt_roundi64_ss(__m128 s, __int64 a, int r);
CVTSI2SS __m128 _mm_cvtsi64_ss(__m128 s, __int64 a);
CVTSI2SS __m128 _mm_cvtsi32_ss(__m128 a, int b);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3NF.

