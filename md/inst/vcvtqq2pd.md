----------------------------
title : VCVTQQ2PD (Intel x86/64 assembly instruction)
cat_title : VCVTQQ2PD
ref_title : VCVTQQ2PD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCVTQQ2PD

**Convert Packed Quadword Integers to Packed Double-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.F3.0F.W1 E6 /r\newline{}VCVTQQ2PD xmm1 {k1}{z}, xmm2/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512DQ|Convert two packed quadword integers from xmm2/m128/m64bcst to packed double-precision floating-point values in xmm1 with writemask k1.|
|EVEX.256.F3.0F.W1 E6 /r\newline{}VCVTQQ2PD ymm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512DQ|Convert four packed quadword integers from ymm2/m256/m64bcst to packed double-precision floating-point values in ymm1 with writemask k1.|
|EVEX.512.F3.0F.W1 E6 /r\newline{}VCVTQQ2PD zmm1 {k1}{z}, zmm2/m512/m64bcst{er}|FV|V/V|AVX512DQ|Convert eight packed quadword integers from zmm2/m512/m64bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.|
###                                                 Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

  FV ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts packed quadword integers in the source operand (second operand) to packed double-precision floating-point values in the destination operand (first operand). 

The source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operation is a ZMM/YMM/XMM register conditionally updated with writemask k1. 

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VCVTQQ2PD (EVEX2 encoded versions) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL == 512) AND (EVEX.b == 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-
                Convert_QuadInteger_To_Double_Precision_Floating_Point(SRC[i+63:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VCVTQQ2PD (EVEX encoded versions) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b == 1) 
                      THEN
                            DEST[i+63:i] <-
                Convert_QuadInteger_To_Double_Precision_Floating_Point(SRC[63:0])
                      ELSE 
                            DEST[i+63:i] <-
                Convert_QuadInteger_To_Double_Precision_Floating_Point(SRC[i+63:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTQQ2PD __m512d _mm512_cvtepi64_pd( __m512i a);
VCVTQQ2PD __m512d _mm512_mask_cvtepi64_pd( __m512d s, __mmask16 k, __m512i a);
VCVTQQ2PD __m512d _mm512_maskz_cvtepi64_pd( __mmask16 k, __m512i a);
VCVTQQ2PD __m512d _mm512_cvt_roundepi64_pd( __m512i a, int r);
VCVTQQ2PD __m512d _mm512_mask_cvt_roundepi_ps( __m512d s, __mmask8 k, __m512i a, int r);
VCVTQQ2PD __m512d _mm512_maskz_cvt_roundepi64_pd( __mmask8 k, __m512i a, int r);
VCVTQQ2PD __m256d _mm256_mask_cvtepi64_pd( __m256d s, __mmask8 k, __m256i a);
VCVTQQ2PD __m256d _mm256_maskz_cvtepi64_pd( __mmask8 k, __m256i a);
VCVTQQ2PD __m128d _mm_mask_cvtepi64_pd( __m128d s, __mmask8 k, __m128i a);
VCVTQQ2PD __m128d _mm_maskz_cvtepi64_pd( __mmask8 k, __m128i a);
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E2

#UD If EVEX.vvvv != 1111B.

