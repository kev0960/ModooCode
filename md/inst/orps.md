----------------------------
title : ORPS (Intel x86/64 assembly instruction)
cat_title : ORPS
ref_title : ORPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/O
publish_date: 2020-09-01
----------------------------
#@ ORPS

**Bitwise Logical OR of Packed Single Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 56 /r\newline{}ORPS xmm1, xmm2/m128|RM|V/V|SSE|Return the bitwise logical OR of packed single-precision floating-point values in xmm1 and xmm2/mem. |
|VEX.NDS.128.0F 56 /r\newline{}VORPS xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Return the bitwise logical OR of packed single-precision floating-point values in xmm2 and xmm3/mem. |
|VEX.NDS.256.0F 56 /r\newline{}VORPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Return the bitwise logical OR of packed single-precision floating-point values in ymm2 and ymm3/mem.|
|EVEX.NDS.128.0F.W0 56 /r\newline{}VORPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512DQ|Return the bitwise logical OR of packed single-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.|
|EVEX.NDS.256.0F.W0 56 /r\newline{}VORPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512DQ|Return the bitwise logical OR of packed single-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.|
|EVEX.NDS.512.0F.W0 56 /r\newline{}VORPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512DQ|Return the bitwise logical OR of packed single-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a bitwise logical `OR` of the four, eight or sixteen packed single-precision floating-point values from the first source operand and the second source operand, and stores the result in the destination operand

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register destination are zeroed.

VEX.128 encoded version: The first source operand is an XMM register. The second source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding register destination are unmodified.


### Operation
#### VORPS (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b == 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+31:i] <-  SRC1[i+31:i] BITWISE OR SRC2[31:0]
                      ELSE 
                            DEST[i+31:i] <-  SRC1[i+31:i] BITWISE OR SRC2[i+31:i]
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VORPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] BITWISE OR SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] BITWISE OR SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] BITWISE OR SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] BITWISE OR SRC2[127:96]
DEST[159:128] <-  SRC1[159:128] BITWISE OR SRC2[159:128]
DEST[191:160] <-  SRC1[191:160] BITWISE OR SRC2[191:160]
DEST[223:192] <-  SRC1[223:192] BITWISE OR SRC2[223:192]
DEST[255:224] <-  SRC1[255:224] BITWISE OR SRC2[255:224].
DEST[MAX_VL-1:256] <-  0
```
#### VORPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] BITWISE OR SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] BITWISE OR SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] BITWISE OR SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] BITWISE OR SRC2[127:96]
DEST[MAX_VL-1:128] <-  0
```
#### ORPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  SRC1[31:0] BITWISE OR SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] BITWISE OR SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] BITWISE OR SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] BITWISE OR SRC2[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VORPS __m512 _mm512_or_ps ( __m512 a, __m512 b);
VORPS __m512 _mm512_mask_or_ps ( __m512 s, __mmask16 k, __m512 a, __m512 b);
VORPS __m512 _mm512_maskz_or_ps (__mmask16 k, __m512 a, __m512 b);
VORPS __m256 _mm256_mask_or_ps (__m256 s, ___mmask8 k, __m256 a, __m256 b);
VORPS __m256 _mm256_maskz_or_ps (__mmask8 k, __m256 a, __m256 b);
VORPS __m128 _mm_mask_or_ps ( __m128 s, __mmask8 k, __m128 a, __m128 b);
VORPS __m128 _mm_maskz_or_ps (__mmask8 k, __m128 a, __m128 b);
VORPS __m256 _mm256_or_ps (__m256 a, __m256 b);
ORPS __m128 _mm_or_ps (__m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.

