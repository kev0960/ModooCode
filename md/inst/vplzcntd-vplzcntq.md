----------------------------
title : VPLZCNTD, VPLZCNTQs (Intel x86/64 assembly instruction)
cat_title : VPLZCNTD, VPLZCNTQ
ref_title : VPLZCNTD, VPLZCNTQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPLZCNTD, VPLZCNTQ

**Count the Number of Leading Zero Bits for Packed Dword, Packed Qword Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W0 44 /r\newline{}VPLZCNTD xmm1 {k1}{z}, xmm2/m128/m32bcst|FV |V/V |AVX512VL\newline{}AVX512CD|Count the number of leading zero bits in each dword element of xmm2/m128/m32bcst using writemask k1.|
|EVEX.256.66.0F38.W0 44 /r\newline{}VPLZCNTD ymm1 {k1}{z}, ymm2/m256/m32bcst|FV|V/V |AVX512VL\newline{}AVX512CD|Count the number of leading zero bits in each dword element of ymm2/m256/m32bcst using writemask k1.|
|EVEX.512.66.0F38.W0 44 /r\newline{}VPLZCNTD zmm1 {k1}{z}, zmm2/m512/m32bcst|FV|V/V |AVX512CD|Count the number of leading zero bits in each dword element of zmm2/m512/m32bcst using writemask k1.|
|EVEX.128.66.0F38.W1 44 /r\newline{}VPLZCNTQ xmm1 {k1}{z}, xmm2/m128/m64bcst|FV |V/V |AVX512VL\newline{}AVX512CD|Count the number of leading zero bits in each qword element of xmm2/m128/m64bcst using writemask k1.|
|EVEX.256.66.0F38.W1 44 /r\newline{}VPLZCNTQ ymm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V |AVX512VL\newline{}AVX512CD|Count the number of leading zero bits in each qword element of ymm2/m256/m64bcst using writemask k1.|
|EVEX.512.66.0F38.W1 44 /r\newline{}VPLZCNTQ zmm1 {k1}{z}, zmm2/m512/m64bcst|FV|V/V |AVX512CD|Count the number of leading zero bits in each qword element of zmm2/m512/m64bcst using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Counts the number of leading most significant zero bits in each dword or qword element of the source operand (the second operand) and stores the results in the destination register (the first operand) according to the writemask. If an element is zero, the result for that element is the operand size of the element.\esc{*}\esc{*} \esc{*}\esc{*}

EVEX.512 encoded version: The source operand is a ZMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a ZMM register, conditionally updated using writemask k1. 

EVEX.256 encoded version: The source operand is a YMM register, a 256-bit memory location, or a 256-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a YMM register, conditionally updated using writemask k1. 

EVEX.128 encoded version: The source operand is a XMM register, a 128-bit memory location, or a 128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a XMM register, conditionally updated using writemask k1. 

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPLZCNTD
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j*32
    IF MaskBit(j) OR *no writemask*
          THEN 
    temp <-  32
    DEST[i+31:i] <-  0
    WHILE (temp > 0) AND (SRC[i+temp-1] = 0)
              DO
                      temp <-  temp - 1
                      DEST[i+31:i] <-  DEST[i+31:i] + 1
              OD
          ELSE
             IF *merging-masking* 
                THEN *DEST[i+31:i] remains unchanged*
                ELSE DEST[i+31:i] <-  0
             FI
    FI
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPLZCNTQ
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j*64
    IF MaskBit(j) OR *no writemask*
          THEN
    temp <-  64
    DEST[i+63:i] <-  0
    WHILE (temp > 0) AND (SRC[i+temp-1] = 0)
             DO
                      temp <-  temp - 1
                      DEST[i+63:i] <-  DEST[i+63:i] + 1
              OD
          ELSE
             IF *merging-masking* 
                THEN *DEST[i+63:i] remains unchanged*
                ELSE DEST[i+63:i] <-  0
             FI
    FI
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPLZCNTD __m512i _mm512_lzcnt_epi32(__m512i a);
VPLZCNTD __m512i _mm512_mask_lzcnt_epi32(__m512i s, __mmask16 m, __m512i a);
VPLZCNTD __m512i _mm512_maskz_lzcnt_epi32( __mmask16 m, __m512i a);
VPLZCNTQ __m512i _mm512_lzcnt_epi64(__m512i a);
VPLZCNTQ __m512i _mm512_mask_lzcnt_epi64(__m512i s, __mmask8 m, __m512i a);
VPLZCNTQ __m512i _mm512_maskz_lzcnt_epi64(__mmask8 m, __m512i a);
VPLZCNTD __m256i _mm256_lzcnt_epi32(__m256i a);
VPLZCNTD __m256i _mm256_mask_lzcnt_epi32(__m256i s, __mmask8 m, __m256i a);
VPLZCNTD __m256i _mm256_maskz_lzcnt_epi32( __mmask8 m, __m256i a);
VPLZCNTQ __m256i _mm256_lzcnt_epi64(__m256i a);
VPLZCNTQ __m256i _mm256_mask_lzcnt_epi64(__m256i s, __mmask8 m, __m256i a);
VPLZCNTQ __m256i _mm256_maskz_lzcnt_epi64(__mmask8 m, __m256i a);
VPLZCNTD __m128i _mm_lzcnt_epi32(__m128i a);
VPLZCNTD __m128i _mm_mask_lzcnt_epi32(__m128i s, __mmask8 m, __m128i a);
VPLZCNTD __m128i _mm_maskz_lzcnt_epi32( __mmask8 m, __m128i a);
VPLZCNTQ __m128i _mm_lzcnt_epi64(__m128i a);
VPLZCNTQ __m128i _mm_mask_lzcnt_epi64(__m128i s, __mmask8 m, __m128i a);
VPLZCNTQ __m128i _mm_maskz_lzcnt_epi64(__mmask8 m, __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E4.

