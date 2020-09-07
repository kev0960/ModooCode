----------------------------
title : PMINSD, PMINSQs (Intel x86/64 assembly instruction)
cat_title : PMINSD, PMINSQ
ref_title : PMINSD, PMINSQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PMINSD, PMINSQ

**Minimum of Packed Signed Integers**

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 38 39 /r\newline{}PMINSD xmm1, xmm2/m128|RM|V/V|SSE4_1|Compare packed signed dword integers in xmm1 and xmm2/m128 and store packed minimum values in xmm1.|
|VEX.NDS.128.66.0F38.WIG 39 /r\newline{}VPMINSD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1.|
|VEX.NDS.256.66.0F38.WIG 39 /r\newline{}VPMINSD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Compare packed signed dword integers in ymm2 and ymm3/m128 and store packed minimum values in ymm1.|
|EVEX.NDS.128.66.0F38.W0 39 /r\newline{}VPMINSD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.|
|EVEX.NDS.256.66.0F38.W0 39 /r\newline{}VPMINSD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed dword integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F38.W0 39 /r\newline{}VPMINSD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Compare packed signed dword integers in zmm2 and zmm3/m512/m32bcst and store packed minimum values in zmm1 under writemask k1.|
|EVEX.NDS.128.66.0F38.W1 39 /r\newline{}VPMINSQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed qword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.|
|EVEX.NDS.256.66.0F38.W1 39 /r\newline{}VPMINSQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed qword integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F38.W1 39 /r\newline{}VPMINSQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Compare packed signed qword integers in zmm2 and zmm3/m512/m64bcst and store packed minimum values in zmm1 under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD compare of the packed signed dword or qword integers in the second source operand and the first source operand and returns the minimum value for each pair of integers to the destination operand. 

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers. Bits (MAX\esc{_}VL-1:256) of the corresponding destination register are zeroed.



EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register; The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is conditionally updated based on writemask k1.


### Operation
#### PMINSD (128-bit Legacy SSE version)
```info-verb
    IF DEST[31:0] < SRC[31:0] THEN
          DEST[31:0] <-  DEST[31:0];
    ELSE
          DEST[31:0] <-  SRC[31:0]; FI;
    (* Repeat operation for 2nd through 7th words in source and destination operands *)
    IF DEST[127:96] < SRC[127:96] THEN
          DEST[127:96] <-  DEST[127:96];
    ELSE
          DEST[127:96] <-  SRC[127:96]; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPMINSD (VEX.128 encoded version)
```info-verb
    IF SRC1[31:0] < SRC2[31:0] THEN
          DEST[31:0] <-  SRC1[31:0];
    ELSE
          DEST[31:0] <-  SRC2[31:0]; FI;
    (* Repeat operation for 2nd through 3rd dwords in source and destination operands *)
    IF SRC1[127:96] < SRC2[127:96] THEN
          DEST[127:96] <-  SRC1[127:96];
    ELSE
          DEST[127:96] <-  SRC2[127:96]; FI;
DEST[MAX_VL-1:128] <-  0
```
#### VPMINSD (VEX.256 encoded version)
```info-verb
    IF SRC1[31:0] < SRC2[31:0] THEN
          DEST[31:0] <-  SRC1[31:0];
    ELSE
          DEST[31:0] <-  SRC2[31:0]; FI;
    (* Repeat operation for 2nd through 7th dwords in source and destination operands *)
    IF SRC1[255:224] < SRC2[255:224] THEN
          DEST[255:224] <-  SRC1[255:224];
    ELSE
          DEST[255:224] <-  SRC2[255:224]; FI;
DEST[MAX_VL-1:256] <-  0
```
#### VPMINSD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
          IF (EVEX.b = 1) AND (SRC2 *is memory*)
                THEN 
                      IF SRC1[i+31:i] < SRC2[31:0] 
                            THEN DEST[i+31:i] <-  SRC1[i+31:i];
                            ELSE DEST[i+31:i] <-  SRC2[31:0]; 
                      FI;
                ELSE 
                      IF SRC1[i+31:i] < SRC2[i+31:i] 
                            THEN DEST[i+31:i] <-  SRC1[i+31:i];
                            ELSE DEST[i+31:i] <-  SRC2[i+31:i]; 
                FI;
          FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPMINSQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
          IF (EVEX.b = 1) AND (SRC2 *is memory*)
                THEN 
                      IF SRC1[i+63:i] < SRC2[63:0] 
                            THEN DEST[i+63:i] <-  SRC1[i+63:i];
                            ELSE DEST[i+63:i] <-  SRC2[63:0]; 
                      FI;
                ELSE 
                      IF SRC1[i+63:i] < SRC2[i+63:i] 
                            THEN DEST[i+63:i] <-  SRC1[i+63:i];
                            ELSE DEST[i+63:i] <-  SRC2[i+63:i]; 
                FI;
          FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMINSD __m512i _mm512_min_epi32( __m512i a, __m512i b);
VPMINSD __m512i _mm512_mask_min_epi32(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPMINSD __m512i _mm512_maskz_min_epi32( __mmask16 k, __m512i a, __m512i b);
VPMINSQ __m512i _mm512_min_epi64( __m512i a, __m512i b);
VPMINSQ __m512i _mm512_mask_min_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPMINSQ __m512i _mm512_maskz_min_epi64( __mmask8 k, __m512i a, __m512i b);
VPMINSD __m256i _mm256_mask_min_epi32(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMINSD __m256i _mm256_maskz_min_epi32( __mmask16 k, __m256i a, __m256i b);
VPMINSQ __m256i _mm256_mask_min_epi64(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPMINSQ __m256i _mm256_maskz_min_epi64( __mmask8 k, __m256i a, __m256i b);
VPMINSD __m128i _mm_mask_min_epi32(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMINSD __m128i _mm_maskz_min_epi32( __mmask8 k, __m128i a, __m128i b);
VPMINSQ __m128i _mm_mask_min_epi64(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMINSQ __m128i _mm_maskz_min_epu64( __mmask8 k, __m128i a, __m128i b);
(V)PMINSD __m128i _mm_min_epi32 ( __m128i a, __m128i b);
VPMINSD __m256i _mm256_min_epi32 (__m256i a, __m256i b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.

