----------------------------
title : DIVPD (Intel x86/64 assembly instruction)
cat_title : DIVPD
ref_title : DIVPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/D
publish_date: 2020-09-01
----------------------------


#@ DIVPD

**Divide Packed Double-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 5E /r\newline{}DIVPD xmm1, xmm2/m128|RM|V/V|SSE2|Divide packed double-precision floating-point values in xmm1 by packed double-precision floating-point values in xmm2/mem.|
|VEX.NDS.128.66.0F.WIG 5E /r\newline{}VDIVPD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Divide packed double-precision floating-point values in xmm2 by packed double-precision floating-point values in xmm3/mem.|
|VEX.NDS.256.66.0F.WIG 5E /r\newline{}VDIVPD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Divide packed double-precision floating-point values in ymm2 by packed double-precision floating-point values in ymm3/mem.|
|EVEX.NDS.128.66.0F.W1 5E /r\newline{}VDIVPD xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Divide packed double-precision floating-point values in xmm2 by packed double-precision floating-point values in xmm3/m128/m64bcst and write results to xmm1 subject to writemask k1.|
|EVEX.NDS.256.66.0F.W1 5E /r\newline{}VDIVPD ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Divide packed double-precision floating-point values in ymm2 by packed double-precision floating-point values in ymm3/m256/m64bcst and write results to ymm1 subject to writemask k1.|
|EVEX.NDS.512.66.0F.W1 5E /r\newline{}VDIVPD zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst{er}|FV|V/V|AVX512F|Divide packed double-precision floating-point values in zmm2 by packed double-precision FP values in zmm3/m512/m64bcst and write results to zmm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Performs a SIMD divide of the double-precision floating-point values in the first source operand by the floating-point values in the second source operand (the third operand). Results are written to the destination operand (the first operand).

EVEX encoded versions: The first source operand (the second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

VEX.256 encoded version: The first source operand (the second operand) is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX\esc{_}VL-1:256) of the corresponding destination are zeroed.

VEX.128 encoded version: The first source operand (the second operand) is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX\esc{_}VL-1:128) of the corresponding destination are zeroed.

128-bit Legacy SSE version: The second source operand (the second operand) can be an XMM register or an 128-bit memory location. The destination is the same as the first source operand. The upper bits (MAX\esc{_}VL-1:128) of the corresponding destination are unmodified.


### Operation
#### VDIVPD (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1) AND SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);  ; refer to Table 2-4 in the Intel(R) Architecture Instruction Set Extensions Programming Reference
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+63:i] <-  SRC1[i+63:i] / SRC2[63:0]
                      ELSE 
                            DEST[i+63:i] <-  SRC1[i+63:i] / SRC2[i+63:i]
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
#### VDIVPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <- SRC1[63:0] / SRC2[63:0]
DEST[127:64] <- SRC1[127:64] / SRC2[127:64]
DEST[191:128] <- SRC1[191:128] / SRC2[191:128]
DEST[255:192] <- SRC1[255:192] / SRC2[255:192]
DEST[MAX_VL-1:256] <- 0;
```
#### VDIVPD (VEX.128 encoded version)
```info-verb
DEST[63:0] <- SRC1[63:0] / SRC2[63:0]
DEST[127:64] <- SRC1[127:64] / SRC2[127:64]
DEST[MAX_VL-1:128] <- 0;
```
#### DIVPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <- SRC1[63:0] / SRC2[63:0]
DEST[127:64] <- SRC1[127:64] / SRC2[127:64]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VDIVPD __m512d _mm512_div_pd( __m512d a, __m512d b);
VDIVPD __m512d _mm512_mask_div_pd(__m512d s, __mmask8 k, __m512d a, __m512d b);
VDIVPD __m512d _mm512_maskz_div_pd( __mmask8 k, __m512d a, __m512d b);
VDIVPD __m256d _mm256_mask_div_pd(__m256d s, __mmask8 k, __m256d a, __m256d b);
VDIVPD __m256d _mm256_maskz_div_pd( __mmask8 k, __m256d a, __m256d b);
VDIVPD __m128d _mm_mask_div_pd(__m128d s, __mmask8 k, __m128d a, __m128d b);
VDIVPD __m128d _mm_maskz_div_pd( __mmask8 k, __m128d a, __m128d b);
VDIVPD __m512d _mm512_div_round_pd( __m512d a, __m512d b, int);
VDIVPD __m512d _mm512_mask_div_round_pd(__m512d s, __mmask8 k, __m512d a, __m512d b, int);
VDIVPD __m512d _mm512_maskz_div_round_pd( __mmask8 k, __m512d a, __m512d b, int);
VDIVPD __m256d _mm256_div_pd (__m256d a, __m256d b);
DIVPD __m128d _mm_div_pd (__m128d a, __m128d b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Divide-by-Zero, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2.

EVEX-encoded instructions, see Exceptions Type E2.

