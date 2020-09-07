----------------------------
title : PANDN (Intel x86/64 assembly instruction)
cat_title : PANDN
ref_title : PANDN
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PANDN

**Logical AND NOT**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F DF /r\footnote{1}\newline{}\newline{}PANDN mm, mm/m64|RM|V/V|MMX|Bitwise AND NOT of mm/m64 and mm.|
|66 0F DF /r\newline{}\newline{}PANDN xmm1, xmm2/m128|RM|V/V|SSE2|Bitwise AND NOT of xmm2/m128 and xmm1.|
|VEX.NDS.128.66.0F.WIG DF /r\newline{}\newline{}VPANDN xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Bitwise AND NOT of xmm3/m128 and xmm2.|
|VEX.NDS.256.66.0F.WIG DF /r\newline{}\newline{}VPANDN ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Bitwise AND NOT of ymm2, and ymm3/m256 and store result in ymm1.|
|EVEX.NDS.128.66.0F.W0 DF /r\newline{}VPANDND xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise AND NOT of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and store result in xmm1 using writemask k1. |
|EVEX.NDS.256.66.0F.W0 DF /r\newline{}VPANDND ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise AND NOT of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and store result in ymm1 using writemask k1. |
|EVEX.NDS.512.66.0F.W0 DF /r\newline{}VPANDND zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst |FV|V/V|AVX512F|Bitwise AND NOT of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and store result in zmm1 using writemask k1. |
|EVEX.NDS.128.66.0F.W1 DF /r\newline{}VPANDNQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise AND NOT of packed quadword integers in xmm2 and xmm3/m128/m64bcst and store result in xmm1 using writemask k1. |
|EVEX.NDS.256.66.0F.W1 DF /r\newline{}VPANDNQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise AND NOT of packed quadword integers in ymm2 and ymm3/m256/m64bcst and store result in ymm1 using writemask k1. |
|EVEX.NDS.512.66.0F.W1 DF /r\newline{}VPANDNQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst |FV|V/V|AVX512F|Bitwise AND NOT of packed quadword integers in zmm2 and zmm3/m512/m64bcst and store result in zmm1 using writemask k1. |

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a bitwise logical `NOT` operation on the first source operand, then performs bitwise `AND` with second source operand and stores the result in the destination operand. Each bit of the result is set to 1 if the corre-sponding bit in the first operand is 0 and the corresponding bit in the second operand is 1, otherwise it is set to 0.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).



Legacy SSE instructions: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand can be an MMX technology register.

128-bit Legacy SSE version: The first source operand is an XMM register. The second operand can be an XMM register or an 128-bit memory location. The destination is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are unmodified.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1 at 32/64-bit granularity.

VEX.256 encoded versions: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register destination are zeroed.

VEX.128 encoded versions: The first source operand is an XMM register. The second source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register destination are zeroed.


### Operation
#### PANDN (64-bit operand)
```info-verb
DEST <-  NOT(DEST) AND SRC
```
#### PANDN (128-bit Legacy SSE version)
```info-verb
DEST <-  NOT(DEST) AND SRC
DEST[VLMAX-1:128] (Unmodified)
```
#### VPANDN (VEX.128 encoded version)
```info-verb
DEST <-  NOT(SRC1) AND SRC2
DEST[VLMAX-1:128] <-  0
```
#### VPANDN (VEX.256 encoded instruction)
```info-verb
DEST[255:0] <-  ((NOT SRC1[255:0]) AND SRC2[255:0])
DEST[VLMAX-1:256] <-  0
```
#### VPANDND (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+31:i] <-  ((NOT SRC1[i+31:i]) AND SRC2[31:0])
                      ELSE DEST[i+31:i] <-  ((NOT SRC1[i+31:i]) AND SRC2[i+31:i])
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
#### VPANDNQ (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  ((NOT SRC1[i+63:i]) AND SRC2[63:0])
                      ELSE DEST[i+63:i] <-  ((NOT SRC1[i+63:i]) AND SRC2[i+63:i])
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

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPANDND __m512i _mm512_andnot_epi32( __m512i a, __m512i b);
VPANDND __m512i _mm512_mask_andnot_epi32(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPANDND __m512i _mm512_maskz_andnot_epi32( __mmask16 k, __m512i a, __m512i b);
VPANDND __m256i _mm256_mask_andnot_epi32(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPANDND __m256i _mm256_maskz_andnot_epi32( __mmask8 k, __m256i a, __m256i b);
VPANDND __m128i _mm_mask_andnot_epi32(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPANDND __m128i _mm_maskz_andnot_epi32( __mmask8 k, __m128i a, __m128i b);
VPANDNQ __m512i _mm512_andnot_epi64( __m512i a, __m512i b);
VPANDNQ __m512i _mm512_mask_andnot_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPANDNQ __m512i _mm512_maskz_andnot_epi64( __mmask8 k, __m512i a, __m512i b);
VPANDNQ __m256i _mm256_mask_andnot_epi64(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPANDNQ __m256i _mm256_maskz_andnot_epi64( __mmask8 k, __m256i a, __m256i b);
VPANDNQ __m128i _mm_mask_andnot_epi64(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPANDNQ __m128i _mm_maskz_andnot_epi64( __mmask8 k, __m128i a, __m128i b);
PANDN: __m64 _mm_andnot_si64 (__m64 m1, __m64 m2)
(V)PANDN:__m128i _mm_andnot_si128 ( __m128i a, __m128i b)
VPANDN: __m256i _mm256_andnot_si256 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.

