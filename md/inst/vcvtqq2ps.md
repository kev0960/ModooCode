----------------------------
title : VCVTQQ2PS (Intel x86/64 assembly instruction)
cat_title : VCVTQQ2PS
ref_title : VCVTQQ2PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VCVTQQ2PS

**Convert Packed Quadword Integers to Packed Single-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.0F.W1 5B /r\newline{}VCVTQQ2PS xmm1 {k1}{z}, xmm2/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512DQ|Convert two packed quadword integers from xmm2/mem to packed single-precision floating-point values in xmm1 with writemask k1.|
|EVEX.256.0F.W1 5B /r\newline{}VCVTQQ2PS xmm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512DQ|Convert four packed quadword integers from ymm2/mem to packed single-precision floating-point values in xmm1 with writemask k1.|
|EVEX.512.0F.W1 5B /r\newline{}VCVTQQ2PS ymm1 {k1}{z}, zmm2/m512/m64bcst{er}|FV|V/V|AVX512DQ|Convert eight packed quadword integers from zmm2/mem to eight packed single-precision floating-point values in ymm1 with writemask k1.|
###                                                   Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

  FV ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts packed quadword integers in the source operand (second operand) to packed single-precision floating-point values in the destination operand (first operand). 

The source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operation is a YMM/XMM/XMM (lower 64 bits) register conditionally updated with writemask k1. 

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VCVTQQ2PS (EVEX encoded versions) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    k <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[k+31:k] <-
                Convert_QuadInteger_To_Single_Precision_Floating_Point(SRC[i+63:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[k+31:k] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[k+31:k] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```
#### VCVTQQ2PS (EVEX encoded versions) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    k <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b == 1) 
                      THEN
                            DEST[k+31:k] <-
                Convert_QuadInteger_To_Single_Precision_Floating_Point(SRC[63:0])
                      ELSE 
                            DEST[k+31:k] <-
                Convert_QuadInteger_To_Single_Precision_Floating_Point(SRC[i+63:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[k+31:k] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[k+31:k] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTQQ2PS __m256 _mm512_cvtepi64_ps( __m512i a);
VCVTQQ2PS __m256 _mm512_mask_cvtepi64_ps( __m256 s, __mmask16 k, __m512i a);
VCVTQQ2PS __m256 _mm512_maskz_cvtepi64_ps( __mmask16 k, __m512i a);
VCVTQQ2PS __m256 _mm512_cvt_roundepi64_ps( __m512i a, int r);
VCVTQQ2PS __m256 _mm512_mask_cvt_roundepi_ps( __m256 s, __mmask8 k, __m512i a, int r);
VCVTQQ2PS __m256 _mm512_maskz_cvt_roundepi64_ps( __mmask8 k, __m512i a, int r);
VCVTQQ2PS __m128 _mm256_cvtepi64_ps( __m256i a);
VCVTQQ2PS __m128 _mm256_mask_cvtepi64_ps( __m128 s, __mmask8 k, __m256i a);
VCVTQQ2PS __m128 _mm256_maskz_cvtepi64_ps( __mmask8 k, __m256i a);
VCVTQQ2PS __m128 _mm_cvtepi64_ps( __m128i a);
VCVTQQ2PS __m128 _mm_mask_cvtepi64_ps( __m128 s, __mmask8 k, __m128i a);
VCVTQQ2PS __m128 _mm_maskz_cvtepi64_ps( __mmask8 k, __m128i a);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E2

#UD If EVEX.vvvv != 1111B.

