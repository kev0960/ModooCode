----------------------------
title : VCVTUSI2SS (Intel x86/64 assembly instruction)
cat_title : VCVTUSI2SS
ref_title : VCVTUSI2SS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCVTUSI2SS

**Convert Unsigned Integer to Scalar Single-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.F3.0F.W0 7B /r\newline{}VCVTUSI2SS xmm1, xmm2, r/m32{er}|T1S|V/V|AVX512F|Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.|
|EVEX.NDS.LIG.F3.0F.W1 7B /r\newline{}VCVTUSI2SS xmm1, xmm2, r/m64{er}|T1S|V/N.E.\footnote{1}|AVX512F|Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.|
||||||

```note
1. For this specific instruction, EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 version isused
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
### Description


Converts a unsigned doubleword integer (or unsigned quadword integer if operand size is 64 bits) in the source operand (second operand) to a single-precision floating-point value in the destination operand (first operand). The source operand can be a general-purpose register or a memory location. The destination operand is an XMM register. The result is stored in the low doubleword of the destination operand. When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register or the embedded rounding control bits.

The second source operand can be a general-purpose register or a 32/64-bit memory location. The first source and destination operands are XMM registers. Bits (127:32) of the XMM register destination are copied from corre-sponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX.W1 version: promotes the instruction to use 64-bit input value in 64-bit mode.


### Operation
#### VCVTUSI2SS (EVEX encoded version)
```info-verb
IF (SRC2 *is register*) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[31:0] <-  Convert_UInteger_To_Single_Precision_Floating_Point(SRC[63:0]);
ELSE
    DEST[31:0] <-  Convert_UInteger_To_Single_Precision_Floating_Point(SRC[31:0]);
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTUSI2SS __m128 _mm_cvtu32_ss( __m128 s, unsigned a);
VCVTUSI2SS __m128 _mm_cvt_roundu32_ss( __m128 s, unsigned a, int r);
VCVTUSI2SS __m128 _mm_cvtu64_ss( __m128 s, unsigned __int64 a);
VCVTUSI2SS __m128 _mm_cvt_roundu64_ss( __m128 s, unsigned __int64 a, int r);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


See Exceptions Type E3NF.

