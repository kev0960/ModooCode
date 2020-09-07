----------------------------
title : MULPD (Intel x86/64 assembly instruction)
cat_title : MULPD
ref_title : MULPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MULPD

**Multiply Packed Double-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 59 /r\newline{}MULPD xmm1, xmm2/m128|RM|V/V|SSE2|Multiply packed double-precision floating-point values in xmm2/m128 with xmm1 and store result in xmm1.|
|VEX.NDS.128.66.0F.WIG 59 /r\newline{}VMULPD xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Multiply packed double-precision floating-point values in xmm3/m128 with xmm2 and store result in xmm1.|
|VEX.NDS.256.66.0F.WIG 59 /r\newline{}VMULPD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Multiply packed double-precision floating-point values in ymm3/m256 with ymm2 and store result in ymm1.|
|EVEX.NDS.128.66.0F.W1 59 /r\newline{}VMULPD xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed double-precision floating-point values from xmm3/m128/m64bcst to xmm2 and store result in xmm1.|
|EVEX.NDS.256.66.0F.W1 59 /r\newline{}VMULPD ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed double-precision floating-point values from ymm3/m256/m64bcst to ymm2 and store result in ymm1.|
|EVEX.NDS.512.66.0F.W1 59 /r\newline{}VMULPD zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst{er}|FV|V/V|AVX512F|Multiply packed double-precision floating-point values in zmm3/m512/m64bcst with zmm2 and store result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Multiply packed double-precision floating-point values from the first source operand with corresponding values in the second source operand, and stores the packed double-precision floating-point results in the destination operand.

EVEX encoded versions: The first source operand (the second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. Bits (MAX\esc{_}VL-1:256) of the corresponding destination ZMM register are zeroed.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX\esc{_}VL-1:128) of the destination YMM register destination are zeroed.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are unmodified.


### Operation
#### VMULPD (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1) AND SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+63:i] <-  SRC1[i+63:i] * SRC2[63:0]
                      ELSE 
                            DEST[i+63:i] <-  SRC1[i+63:i] * SRC2[i+63:i]
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
#### VMULPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <- SRC1[63:0] * SRC2[63:0]
DEST[127:64] <- SRC1[127:64] * SRC2[127:64]
DEST[191:128] <- SRC1[191:128] * SRC2[191:128]
DEST[255:192] <- SRC1[255:192] * SRC2[255:192]
DEST[MAX_VL-1:256] <- 0;
.
```
#### VMULPD (VEX.128 encoded version)
```info-verb
DEST[63:0] <- SRC1[63:0] * SRC2[63:0]
DEST[127:64] <- SRC1[127:64] * SRC2[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### MULPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <- DEST[63:0] * SRC[63:0]
DEST[127:64] <- DEST[127:64] * SRC[127:64]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMULPD __m512d _mm512_mul_pd( __m512d a, __m512d b);
VMULPD __m512d _mm512_mask_mul_pd(__m512d s, __mmask8 k, __m512d a, __m512d b);
VMULPD __m512d _mm512_maskz_mul_pd( __mmask8 k, __m512d a, __m512d b);
VMULPD __m512d _mm512_mul_round_pd( __m512d a, __m512d b, int);
VMULPD __m512d _mm512_mask_mul_round_pd(__m512d s, __mmask8 k, __m512d a, __m512d b, int);
VMULPD __m512d _mm512_maskz_mul_round_pd( __mmask8 k, __m512d a, __m512d b, int);
VMULPD __m256d _mm256_mul_pd (__m256d a, __m256d b);
MULPD __m128d _mm_mul_pd (__m128d a, __m128d b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 2.

EVEX-encoded instruction, see Exceptions Type E2.

