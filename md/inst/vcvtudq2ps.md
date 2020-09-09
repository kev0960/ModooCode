----------------------------
title : VCVTUDQ2PS (Intel x86/64 assembly instruction)
cat_title : VCVTUDQ2PS
ref_title : VCVTUDQ2PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCVTUDQ2PS

**Convert Packed Unsigned Doubleword Integers to Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.F2.0F.W0 7A /r\newline{}VCVTUDQ2PS xmm1 {k1}{z}, xmm2/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Convert four packed unsigned doubleword integers from xmm2/m128/m32bcst to packed single-precision floating-point values in xmm1 with writemask k1.|
|EVEX.256.F2.0F.W0 7A /r\newline{}VCVTUDQ2PS ymm1 {k1}{z}, ymm2/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Convert eight packed unsigned doubleword integers from ymm2/m256/m32bcst to packed single-precision floating-point values in zmm1 with writemask k1.|
|EVEX.512.F2.0F.W0 7A /r\newline{}VCVTUDQ2PS zmm1 {k1}{z}, zmm2/m512/m32bcst{er} |FV|V/V|AVX512F|Convert sixteen packed unsigned doubleword integers from zmm2/m512/m32bcst to sixteen packed single-precision floating-point values in zmm1 with writemask k1.|
###                                                         Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

  FV ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts packed unsigned doubleword integers in the source operand (second operand) to single-precision floating-point values in the destination operand (first operand). 

The source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1. 

Note: EVEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### VCVTUDQ2PS (EVEX encoded version) when src operand is a register
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-
                Convert_UInteger_To_Single_Precision_Floating_Point(SRC[i+31:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VCVTUDQ2PS (EVEX encoded version) when src operand is a memory source
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) 
                      THEN
                            DEST[i+31:i] <-
                Convert_UInteger_To_Single_Precision_Floating_Point(SRC[31:0])
                      ELSE 
                            DEST[i+31:i] <-
                Convert_UInteger_To_Single_Precision_Floating_Point(SRC[i+31:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTUDQ2PS __m512 _mm512_cvtepu32_ps( __m512i a);
VCVTUDQ2PS __m512 _mm512_mask_cvtepu32_ps( __m512 s, __mmask16 k, __m512i a);
VCVTUDQ2PS __m512 _mm512_maskz_cvtepu32_ps( __mmask16 k, __m512i a);
VCVTUDQ2PS __m512 _mm512_cvt_roundepu32_ps( __m512i a, int r);
VCVTUDQ2PS __m512 _mm512_mask_cvt_roundepu32_ps( __m512 s, __mmask16 k, __m512i a, int r);
VCVTUDQ2PS __m512 _mm512_maskz_cvt_roundepu32_ps( __mmask16 k, __m512i a, int r);
VCVTUDQ2PS __m256 _mm256_cvtepu32_ps( __m256i a);
VCVTUDQ2PS __m256 _mm256_mask_cvtepu32_ps( __m256 s, __mmask8 k, __m256i a);
VCVTUDQ2PS __m256 _mm256_maskz_cvtepu32_ps( __mmask8 k, __m256i a);
VCVTUDQ2PS __m128 _mm_cvtepu32_ps( __m128i a);
VCVTUDQ2PS __m128 _mm_mask_cvtepu32_ps( __m128 s, __mmask8 k, __m128i a);
VCVTUDQ2PS __m128 _mm_maskz_cvtepu32_ps( __mmask8 k, __m128i a);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E2.

#UD If EVEX.vvvv != 1111B.

