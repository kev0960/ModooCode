----------------------------
title : PXOR (Intel x86/64 assembly instruction)
cat_title : PXOR
ref_title : PXOR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PXOR

**Logical Exclusive OR**

|**Opcode\htmlonly{*}/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F EF /r\footnote{1}\newline{}PXOR mm, mm/m64|RM|V/V|MMX|Bitwise XOR of mm/m64 and mm.|
|66 0F EF /r\newline{}PXOR xmm1, xmm2/m128|RM|V/V|SSE2|Bitwise XOR of xmm2/m128 and xmm1.|
|VEX.NDS.128.66.0F.WIG EF /rVPXOR xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Bitwise XOR of xmm3/m128 and xmm2.|
|VEX.NDS.256.66.0F.WIG EF /rVPXOR ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Bitwise XOR of ymm3/m256 and ymm2.|
|EVEX.NDS.128.66.0F.W0 EF /rVPXORD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise XOR of packed doubleword integers in xmm2 and xmm3/m128 using writemask k1. |
|EVEX.NDS.256.66.0F.W0 EF /rVPXORD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise XOR of packed doubleword integers in ymm2 and ymm3/m256 using writemask k1. |
|EVEX.NDS.512.66.0F.W0 EF /rVPXORD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst |FV|V/V|AVX512F|Bitwise XOR of packed doubleword integers in zmm2 and zmm3/m512/m32bcst using writemask k1. |
|EVEX.NDS.128.66.0F.W1 EF /rVPXORQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise XOR of packed quadword integers in xmm2 and xmm3/m128 using writemask k1. |
|EVEX.NDS.256.66.0F.W1 EF /rVPXORQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Bitwise XOR of packed quadword integers in ymm2 and ymm3/m256 using writemask k1. |
|EVEX.NDS.512.66.0F.W1 EF /rVPXORQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst |FV|V/V|AVX512F|Bitwise XOR of packed quadword integers in zmm2 and zmm3/m512/m64bcst using writemask k1. |

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


Performs a bitwise logical exclusive-OR (XOR) operation on the source operand (second operand) and the destina-tion operand (first operand) and stores the result in the destination operand. Each bit of the result is 1 if the corre-sponding bits of the two operands are different; each bit is 0 if the corresponding bits of the operands are the same.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE instructions 64-bit operand: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an MMX technology register.



128-bit Legacy SSE version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM desti-nation register remain unchanged.

VEX.128 encoded version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX\esc{_}VL-1:256) of the corresponding register destination are zeroed.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.


### Operation
#### PXOR (64-bit operand)
```info-verb
DEST <-  DEST XOR SRC
```
#### PXOR (128-bit Legacy SSE version)
```info-verb
DEST <-  DEST XOR SRC
DEST[VLMAX-1:128] (Unmodified)
```
#### VPXOR (VEX.128 encoded version)
```info-verb
DEST <-  SRC1 XOR SRC2
DEST[VLMAX-1:128] <-  0
```
#### VPXOR (VEX.256 encoded version)
```info-verb
DEST <-  SRC1 XOR SRC2
DEST[VLMAX-1:256] <-  0
```
#### VPXORD (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+31:i] <-  SRC1[i+31:i] BITWISE XOR SRC2[31:0]
                      ELSE DEST[i+31:i] <-  SRC1[i+31:i] BITWISE XOR SRC2[i+31:i]
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[31:0] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPXORQ (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  SRC1[i+63:i] BITWISE XOR SRC2[63:0]
                      ELSE DEST[i+63:i] <-  SRC1[i+63:i] BITWISE XOR SRC2[i+63:i]
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[63:0] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPXORD __m512i _mm512_xor_epi32(__m512i a, __m512i b)
VPXORD __m512i _mm512_mask_xor_epi32(__m512i s, __mmask16 m, __m512i a, __m512i b)
VPXORD __m512i _mm512_maskz_xor_epi32( __mmask16 m, __m512i a, __m512i b)
VPXORD __m256i _mm256_xor_epi32(__m256i a, __m256i b)
VPXORD __m256i _mm256_mask_xor_epi32(__m256i s, __mmask8 m, __m256i a, __m256i b)
VPXORD __m256i _mm256_maskz_xor_epi32( __mmask8 m, __m256i a, __m256i b)
VPXORD __m128i _mm_xor_epi32(__m128i a, __m128i b)
VPXORD __m128i _mm_mask_xor_epi32(__m128i s, __mmask8 m, __m128i a, __m128i b)
VPXORD __m128i _mm_maskz_xor_epi32( __mmask16 m, __m128i a, __m128i b)
VPXORQ __m512i _mm512_xor_epi64( __m512i a, __m512i b);
VPXORQ __m512i _mm512_mask_xor_epi64(__m512i s, __mmask8 m, __m512i a, __m512i b);
VPXORQ __m512i _mm512_maskz_xor_epi64(__mmask8 m, __m512i a, __m512i b);
VPXORQ __m256i _mm256_xor_epi64( __m256i a, __m256i b);
VPXORQ __m256i _mm256_mask_xor_epi64(__m256i s, __mmask8 m, __m256i a, __m256i b);
VPXORQ __m256i _mm256_maskz_xor_epi64(__mmask8 m, __m256i a, __m256i b);
VPXORQ __m128i _mm_xor_epi64( __m128i a, __m128i b);
VPXORQ __m128i _mm_mask_xor_epi64(__m128i s, __mmask8 m, __m128i a, __m128i b);
VPXORQ __m128i _mm_maskz_xor_epi64(__mmask8 m, __m128i a, __m128i b);
PXOR:__m64 _mm_xor_si64 (__m64 m1, __m64 m2)
(V)PXOR:__m128i _mm_xor_si128 ( __m128i a, __m128i b)
VPXOR:__m256i _mm256_xor_si256 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.

