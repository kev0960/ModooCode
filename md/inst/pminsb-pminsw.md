----------------------------
title : PMINSB, PMINSWs (Intel x86/64 assembly instruction)
cat_title : PMINSB, PMINSW
ref_title : PMINSB, PMINSW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PMINSB, PMINSW

**Minimum of Packed Signed Integers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|
|-------------------------|------------------------------------------------------|--------------------------------------------------|
|RM|V/V|SSE|
|RM|V/V|SSE4_1|
|RM|V/V|SSE2|
|RVM|V/V|AVX|
|RVM|V/V|AVX|
|RVM|V/V|AVX2|
|RVM|V/V|AVX2|
|FVM|V/V|AVX512VLAVX512BW|
|FVM|V/V|AVX512VLAVX512BW|
|FVM|V/V|AVX512BW|
|FVM|V/V|AVX512VLAVX512BW|
|FVM|V/V|AVX512VLAVX512BW|
|FVM|V/V|AVX512BW|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD compare of the packed signed byte, word, or dword integers in the second source operand and the first source operand and returns the minimum value for each pair of integers to the destination operand. 

Legacy SSE version PMINSW: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand can be an MMX technology register.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register; The second source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operand is conditionally updated based on writemask k1.


### Operation
#### PMINSW (64-bit operands)
```info-verb
    IF DEST[15:0] < SRC[15:0] THEN
          DEST[15:0] <- DEST[15:0];
    ELSE
          DEST[15:0] <- SRC[15:0]; FI;
    (* Repeat operation for 2nd and 3rd words in source and destination operands *)
    IF DEST[63:48] < SRC[63:48] THEN
          DEST[63:48] <- DEST[63:48];
    ELSE
          DEST[63:48] <- SRC[63:48]; FI;
```
#### PMINSB (128-bit Legacy SSE version)
```info-verb
    IF DEST[7:0] < SRC[7:0] THEN
          DEST[7:0] <-  DEST[7:0];
    ELSE
          DEST[15:0] <-  SRC[7:0]; FI;
    (* Repeat operation for 2nd through 15th bytes in source and destination operands *)
    IF DEST[127:120] < SRC[127:120] THEN
          DEST[127:120] <-  DEST[127:120];
    ELSE
          DEST[127:120] <-  SRC[127:120]; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPMINSB (VEX.128 encoded version)
```info-verb
    IF SRC1[7:0] < SRC2[7:0] THEN
          DEST[7:0] <-  SRC1[7:0];
    ELSE
          DEST[7:0] <-  SRC2[7:0]; FI;
    (* Repeat operation for 2nd through 15th bytes in source and destination operands *)
    IF SRC1[127:120] < SRC2[127:120] THEN
          DEST[127:120] <-  SRC1[127:120];
    ELSE
          DEST[127:120] <-  SRC2[127:120]; FI;
DEST[MAX_VL-1:128] <-  0
```
#### VPMINSB (VEX.256 encoded version)
```info-verb
    IF SRC1[7:0] < SRC2[7:0] THEN
          DEST[7:0] <-  SRC1[7:0];
    ELSE
          DEST[15:0] <-  SRC2[7:0]; FI;
    (* Repeat operation for 2nd through 31st bytes in source and destination operands *)
    IF SRC1[255:248] < SRC2[255:248] THEN
          DEST[255:248] <-  SRC1[255:248];
    ELSE
          DEST[255:248] <-  SRC2[255:248]; FI;
DEST[MAX_VL-1:256] <-  0
```
#### VPMINSB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask* THEN
          IF SRC1[i+7:i] < SRC2[i+7:i] 
                THEN DEST[i+7:i] <-  SRC1[i+7:i];
                ELSE DEST[i+7:i] <-  SRC2[i+7:i]; 
          FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+7:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### PMINSW (128-bit Legacy SSE version)
```info-verb
    IF DEST[15:0] < SRC[15:0] THEN
          DEST[15:0] <-  DEST[15:0];
    ELSE
          DEST[15:0] <-  SRC[15:0]; FI;
    (* Repeat operation for 2nd through 7th words in source and destination operands *)
    IF DEST[127:112] < SRC[127:112] THEN
          DEST[127:112] <-  DEST[127:112];
    ELSE
          DEST[127:112] <-  SRC[127:112]; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPMINSW (VEX.128 encoded version)
```info-verb
    IF SRC1[15:0] < SRC2[15:0] THEN
          DEST[15:0] <-  SRC1[15:0];
    ELSE
          DEST[15:0] <-  SRC2[15:0]; FI;
    (* Repeat operation for 2nd through 7th words in source and destination operands *)
    IF SRC1[127:112] < SRC2[127:112] THEN
          DEST[127:112] <-  SRC1[127:112];
    ELSE
          DEST[127:112] <-  SRC2[127:112]; FI;
DEST[MAX_VL-1:128] <-  0
```
#### VPMINSW (VEX.256 encoded version)
```info-verb
    IF SRC1[15:0] < SRC2[15:0] THEN
          DEST[15:0] <-  SRC1[15:0];
    ELSE
          DEST[15:0] <-  SRC2[15:0]; FI;
    (* Repeat operation for 2nd through 15th words in source and destination operands *)
    IF SRC1[255:240] < SRC2[255:240] THEN
          DEST[255:240] <-  SRC1[255:240];
    ELSE
          DEST[255:240] <-  SRC2[255:240]; FI;
DEST[MAX_VL-1:256] <-  0
```
#### VPMINSW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask* THEN
          IF SRC1[i+15:i] < SRC2[i+15:i] 
                THEN DEST[i+15:i] <-  SRC1[i+15:i];
                ELSE DEST[i+15:i] <-  SRC2[i+15:i]; 
          FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMINSB __m512i _mm512_min_epi8( __m512i a, __m512i b);
VPMINSB __m512i _mm512_mask_min_epi8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPMINSB __m512i _mm512_maskz_min_epi8( __mmask64 k, __m512i a, __m512i b);
VPMINSW __m512i _mm512_min_epi16( __m512i a, __m512i b);
VPMINSW __m512i _mm512_mask_min_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPMINSW __m512i _mm512_maskz_min_epi16( __mmask32 k, __m512i a, __m512i b);
VPMINSB __m256i _mm256_mask_min_epi8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPMINSB __m256i _mm256_maskz_min_epi8( __mmask32 k, __m256i a, __m256i b);
VPMINSW __m256i _mm256_mask_min_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMINSW __m256i _mm256_maskz_min_epi16( __mmask16 k, __m256i a, __m256i b);
VPMINSB __m128i _mm_mask_min_epi8(__m128i s, __mmask16 k, __m128i a, __m128i b);
VPMINSB __m128i _mm_maskz_min_epi8( __mmask16 k, __m128i a, __m128i b);
VPMINSW __m128i _mm_mask_min_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMINSW __m128i _mm_maskz_min_epi16( __mmask8 k, __m128i a, __m128i b);
(V)PMINSB __m128i _mm_min_epi8 ( __m128i a, __m128i b);
(V)PMINSW __m128i _mm_min_epi16 ( __m128i a, __m128i b)
VPMINSB __m256i _mm256_min_epi8 ( __m256i a, __m256i b);
VPMINSW __m256i _mm256_min_epi16 ( __m256i a, __m256i b)
PMINSW:__m64 _mm_min_pi16 (__m64 a, __m64 b)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.nb.

#MF (64-bit operations only) If there is a pending x87 FPU exception.

