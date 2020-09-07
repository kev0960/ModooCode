----------------------------
title : SUBPD (Intel x86/64 assembly instruction)
cat_title : SUBPD
ref_title : SUBPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------
#@ SUBPD

**Subtract Packed Double-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 5C /r\newline{}SUBPD xmm1, xmm2/m128|RM|V/V|SSE2|Subtract packed double-precision floating-point values in xmm2/mem from xmm1 and store result in xmm1.|
|VEX.NDS.128.66.0F.WIG 5C /r\newline{}VSUBPD xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Subtract packed double-precision floating-point values in xmm3/mem from xmm2 and store result in xmm1.|
|VEX.NDS.256.66.0F.WIG 5C /r\newline{}VSUBPD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Subtract packed double-precision floating-point values in ymm3/mem from ymm2 and store result in ymm1.|
|EVEX.NDS.128.66.0F.W1 5C /r\newline{}VSUBPD xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed double-precision floating-point values from xmm3/m128/m64bcst to xmm2 and store result in xmm1 with writemask k1.|
|EVEX.NDS.256.66.0F.W1 5C /r\newline{}VSUBPD ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed double-precision floating-point values from ymm3/m256/m64bcst to ymm2 and store result in ymm1 with writemask k1.|
|EVEX.NDS.512.66.0F.W1 5C /r\newline{}VSUBPD zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst{er}|FV|V/V|AVX512F|Subtract packed double-precision floating-point values from zmm3/m512/m64bcst to zmm2 and store result in zmm1 with writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD subtract of the two, four or eight packed double-precision floating-point values of the second Source operand from the first Source operand, and stores the packed double-precision floating-point results in the destination operand.

VEX.128 and EVEX.128 encoded versions: The second source operand is an XMM register or an 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (MAX\esc{_}VL-1:128) of the corre-sponding destination register are zeroed.

VEX.256 and EVEX.256 encoded versions: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. Bits (MAX\esc{_}VL-1:256) of the corre-sponding destination register are zeroed.

EVEX.512 encoded version: The second source operand is a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 64-bit memory location. The first source operand and destination operands are ZMM registers. The destination operand is conditionally updated according to the writemask.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper Bits (MAX\esc{_}VL-1:128) of the corresponding register destination are unmodified.


### Operation
#### VSUBPD (EVEX encoded versions) when src2 operand is a vector register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC1[i+63:i] - SRC2[i+63:i]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[63:0] <-  0
          FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSUBPD (EVEX encoded versions) when src2 operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1)
                      THEN  DEST[i+63:i] <-  SRC1[i+63:i] - SRC2[63:0];
                      ELSE  EST[i+63:i] <-  SRC1[i+63:i] - SRC2[i+63:i];
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[63:0] <-  0
          FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSUBPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC2[63:0]
DEST[127:64] <-  SRC1[127:64] - SRC2[127:64]
DEST[191:128] <-  SRC1[191:128] - SRC2[191:128]
DEST[255:192] <-  SRC1[255:192] - SRC2[255:192]
DEST[MAX_VL-1:256] <-  0
```
#### VSUBPD (VEX.128 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC2[63:0]
DEST[127:64] <-  SRC1[127:64] - SRC2[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### SUBPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-  DEST[63:0] - SRC[63:0]
DEST[127:64] <-  DEST[127:64] - SRC[127:64]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSUBPD __m512d _mm512_sub_pd (__m512d a, __m512d b);
VSUBPD __m512d _mm512_mask_sub_pd (__m512d s, __mmask8 k, __m512d a, __m512d b);
VSUBPD __m512d _mm512_maskz_sub_pd (__mmask8 k, __m512d a, __m512d b);
VSUBPD __m512d _mm512_sub_round_pd (__m512d a, __m512d b, int);
VSUBPD __m512d _mm512_mask_sub_round_pd (__m512d s, __mmask8 k, __m512d a, __m512d b, int);
VSUBPD __m512d _mm512_maskz_sub_round_pd (__mmask8 k, __m512d a, __m512d b, int);
VSUBPD __m256d _mm256_sub_pd (__m256d a, __m256d b);
VSUBPD __m256d _mm256_mask_sub_pd (__m256d s, __mmask8 k, __m256d a, __m256d b);
VSUBPD __m256d _mm256_maskz_sub_pd (__mmask8 k, __m256d a, __m256d b);
SUBPD __m128d _mm_sub_pd (__m128d a, __m128d b);
VSUBPD __m128d _mm_mask_sub_pd (__m128d s, __mmask8 k, __m128d a, __m128d b);
VSUBPD __m128d _mm_maskz_sub_pd (__mmask8 k, __m128d a, __m128d b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2.

EVEX-encoded instructions, see Exceptions Type E2.

