----------------------------
title : MULPS (Intel x86/64 assembly instruction)
cat_title : MULPS
ref_title : MULPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MULPS

**Multiply Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 59 /r\newline{}MULPS xmm1, xmm2/m128|RM|V/V|SSE|Multiply packed single-precision floating-point values in xmm2/m128 with xmm1 and store result in xmm1.|
|VEX.NDS.128.0F.WIG 59 /r\newline{}VMULPS xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Multiply packed single-precision floating-point values in xmm3/m128 with xmm2 and store result in xmm1.|
|VEX.NDS.256.0F.WIG 59 /r\newline{}VMULPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Multiply packed single-precision floating-point values in ymm3/m256 with ymm2 and store result in ymm1.|
|EVEX.NDS.128.0F.W0 59 /r\newline{}VMULPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from xmm3/m128/m32bcst to xmm2 and store result in xmm1.|
|EVEX.NDS.256.0F.W0 59 /r\newline{}VMULPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed single-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1.|
|EVEX.NDS.512.0F.W0 59 /r\newline{}VMULPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst {er}|FV|V/V|AVX512F|Multiply packed single-precision floating-point values in zmm3/m512/m32bcst with zmm2 and store result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Multiply the packed single-precision floating-point values from the first source operand with the corresponding values in the second source operand, and stores the packed double-precision floating-point results in the destina-tion operand.

EVEX encoded versions: The first source operand (the second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. Bits (MAX\esc{_}VL-1:256) of the corresponding destination ZMM register are zeroed.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX\esc{_}VL-1:128) of the destination YMM register destination are zeroed.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are unmodified.


### Operation
#### VMULPS (EVEX encoded version)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1) AND SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+31:i] <-  SRC1[i+31:i] * SRC2[31:0]
                      ELSE 
                            DEST[i+31:i] <-  SRC1[i+31:i] * SRC2[i+31:i]
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
#### VMULPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0] * SRC2[31:0]
DEST[63:32] <- SRC1[63:32] * SRC2[63:32]
DEST[95:64] <- SRC1[95:64] * SRC2[95:64]
DEST[127:96] <- SRC1[127:96] * SRC2[127:96]
DEST[159:128] <- SRC1[159:128] * SRC2[159:128]
DEST[191:160]<- SRC1[191:160] * SRC2[191:160]
DEST[223:192] <- SRC1[223:192] * SRC2[223:192]
DEST[255:224] <- SRC1[255:224] * SRC2[255:224].
DEST[MAX_VL-1:256] <- 0;
```
#### VMULPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0] * SRC2[31:0]
DEST[63:32] <- SRC1[63:32] * SRC2[63:32]
DEST[95:64] <- SRC1[95:64] * SRC2[95:64]
DEST[127:96] <- SRC1[127:96] * SRC2[127:96]
DEST[MAX_VL-1:128] <- 0
```
#### MULPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- SRC1[31:0] * SRC2[31:0]
DEST[63:32] <- SRC1[63:32] * SRC2[63:32]
DEST[95:64] <- SRC1[95:64] * SRC2[95:64]
DEST[127:96] <- SRC1[127:96] * SRC2[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMULPS __m512 _mm512_mul_ps( __m512 a, __m512 b);
VMULPS __m512 _mm512_mask_mul_ps(__m512 s, __mmask16 k, __m512 a, __m512 b);
VMULPS __m512 _mm512_maskz_mul_ps(__mmask16 k, __m512 a, __m512 b);
VMULPS __m512 _mm512_mul_round_ps( __m512 a, __m512 b, int);
VMULPS __m512 _mm512_mask_mul_round_ps(__m512 s, __mmask16 k, __m512 a, __m512 b, int);
VMULPS __m512 _mm512_maskz_mul_round_ps(__mmask16 k, __m512 a, __m512 b, int);
VMULPS __m256 _mm256_mask_mul_ps(__m256 s, __mmask8 k, __m256 a, __m256 b);
VMULPS __m256 _mm256_maskz_mul_ps(__mmask8 k, __m256 a, __m256 b);
VMULPS __m128 _mm_mask_mul_ps(__m128 s, __mmask8 k, __m128 a, __m128 b);
VMULPS __m128 _mm_maskz_mul_ps(__mmask8 k, __m128 a, __m128 b);
VMULPS __m256 _mm256_mul_ps (__m256 a, __m256 b);
MULPS __m128 _mm_mul_ps (__m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 2.

EVEX-encoded instruction, see Exceptions Type E2.
