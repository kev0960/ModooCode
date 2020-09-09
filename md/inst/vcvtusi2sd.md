----------------------------
title : VCVTUSI2SD (Intel x86/64 assembly instruction)
cat_title : VCVTUSI2SD
ref_title : VCVTUSI2SD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCVTUSI2SD

**Convert Unsigned Integer to Scalar Double-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.F2.0F.W0 7B /r\newline{}VCVTUSI2SD xmm1, xmm2, r/m32|T1S|V/V|AVX512F|Convert one unsigned doubleword integer from r/m32 to one double-precision floating-point value in xmm1.|
|EVEX.NDS.LIG.F2.0F.W1 7B /r\newline{}VCVTUSI2SD xmm1, xmm2, r/m64{er}|T1S|V/N.E.\footnote{1}|AVX512F|Convert one unsigned quadword integer from r/m64 to one double-precision floating-point value in xmm1.|
||||||

```note
1. For this specific instruction, EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 version isused
```
###                                                       Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

 T1S ModRM:reg (w) EVEX.vvvv ModRM:r/m (r) NA

### Description


Converts an unsigned doubleword integer (or unsigned quadword integer if operand size is 64 bits) in the second source operand to a double-precision floating-point value in the destination operand. The result is stored in the low quadword of the destination operand. When conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register.

The second source operand can be a general-purpose register or a 32/64-bit memory location. The first source and destination operands are XMM registers. Bits (127:64) of the XMM register destination are copied from corre-sponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX.W1 version: promotes the instruction to use 64-bit input value in 64-bit mode.

EVEX.W0 version: attempt to encode this instruction with EVEX embedded rounding is ignored.


### Operation
#### VCVTUSI2SD (EVEX encoded version)
```info-verb
IF (SRC2 *is register*) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF 64-Bit Mode And OperandSize = 64
THEN
    DEST[63:0] <-  Convert_UInteger_To_Double_Precision_Floating_Point(SRC2[63:0]);
ELSE
    DEST[63:0] <-  Convert_UInteger_To_Double_Precision_Floating_Point(SRC2[31:0]);
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTUSI2SD __m128d _mm_cvtu32_sd( __m128d s, unsigned a); 
VCVTUSI2SD __m128d _mm_cvtu64_sd( __m128d s, unsigned __int64 a);
VCVTUSI2SD __m128d _mm_cvt_roundu64_sd( __m128d s, unsigned __int64 a, int r);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


See Exceptions Type E3NF if W1, else type E10NF.

