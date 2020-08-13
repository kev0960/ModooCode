----------------------------
title : PMAXSB, PMAXSW, PMAXSD, PMAXSQs (Intel x86/64 assembly instruction)
cat_title : PMAXSB, PMAXSW, PMAXSD, PMAXSQ
ref_title : PMAXSB, PMAXSW, PMAXSD, PMAXSQ
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PMAXSB, PMAXSW, PMAXSD, PMAXSQ

**Maximum of Packed Signed Integers**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F EE /r\footnote{1}\newline{}\newline{}PMAXSW mm1, mm2/m64|RM|V/V|SSE|Compare signed word integers in mm2/m64 and mm1 and return maximum values.|
|66 0F 38 3C /r\newline{}PMAXSB xmm1, xmm2/m128|RM|V/V|SSE4_1|Compare packed signed byte integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.|
|66 0F EE /r\newline{}PMAXSW xmm1, xmm2/m128|RM|V/V|SSE2|Compare packed signed word integers in xmm2/m128 and xmm1 and stores maximum packed values in xmm1.|
|66 0F 38 3D /r\newline{}PMAXSD xmm1, xmm2/m128|RM|V/V|SSE4_1|Compare packed signed dword integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.|
|VEX.NDS.128.66.0F38.WIG 3C /r\newline{}VPMAXSB xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed signed byte integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1.|
|VEX.NDS.128.66.0F.WIG EE /r\newline{}VPMAXSW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed signed word integers in xmm3/m128 and xmm2 and store packed maximum values in xmm1.|
|VEX.NDS.128.66.0F38.WIG 3D /r\newline{}VPMAXSD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1.|
|VEX.NDS.256.66.0F38.WIG 3C /r\newline{}VPMAXSB ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Compare packed signed byte integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1.|
|VEX.NDS.256.66.0F.WIG EE /r\newline{}VPMAXSW ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Compare packed signed word integers in ymm3/m256 and ymm2 and store packed maximum values in ymm1.|
|VEX.NDS.256.66.0F38.WIG 3D /r\newline{}VPMAXSD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Compare packed signed dword integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1.|
|EVEX.NDS.128.66.0F38.WIG 3C /r\newline{}VPMAXSB xmm1{k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed byte integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.|
|EVEX.NDS.256.66.0F38.WIG 3C /r\newline{}VPMAXSB ymm1{k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed byte integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F38.WIG 3C /r\newline{}VPMAXSB zmm1{k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Compare packed signed byte integers in zmm2 and zmm3/m512 and store packed maximum values in zmm1 under writemask k1.|
|EVEX.NDS.128.66.0F.WIG EE /r\newline{}VPMAXSW xmm1{k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed word integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.|
|EVEX.NDS.256.66.0F.WIG EE /r\newline{}VPMAXSW ymm1{k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed word integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F.WIG EE /r\newline{}VPMAXSW zmm1{k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Compare packed signed word integers in zmm2 and zmm3/m512 and store packed maximum values in zmm1 under writemask k1.|
|EVEX.NDS.128.66.0F38.W0 3D /r\newline{}VPMAXSD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed dword integers in xmm2 and xmm3/m128/m32bcst and store packed maximum values in xmm1 using writemask k1.|


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.256.66.0F38.W0 3D /r\newline{}VPMAXSD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed dword integers in ymm2 and ymm3/m256/m32bcst and store packed maximum values in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W0 3D /r\newline{}VPMAXSD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Compare packed signed dword integers in zmm2 and zmm3/m512/m32bcst and store packed maximum values in zmm1 using writemask k1.|
|EVEX.NDS.128.66.0F38.W1 3D /r\newline{}VPMAXSQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed qword integers in xmm2 and xmm3/m128/m64bcst and store packed maximum values in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F38.W1 3D /r\newline{}VPMAXSQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed signed qword integers in ymm2 and ymm3/m256/m64bcst and store packed maximum values in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W1 3D /r\newline{}VPMAXSQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Compare packed signed qword integers in zmm2 and zmm3/m512/m64bcst and store packed maximum values in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD compare of the packed signed byte, word, dword or qword integers in the second source operand and the first source operand and returns the maximum value for each pair of integers to the destination operand. 

Legacy SSE version PMAXSW: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand can be an MMX technology register.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX_VL-1:128) of the corresponding YMM destina-tion register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX_VL-1:128) of the corresponding destination register are zeroed.

VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers. Bits (MAX_VL-1:256) of the corresponding destination register are zeroed.

EVEX encoded VPMAXSD/Q: The first source operand is a ZMM/YMM/XMM register; The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is conditionally updated based on writemask k1.

EVEX encoded VPMAXSB/W: The first source operand is a ZMM/YMM/XMM register; The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand is conditionally updated based on writemask k1.


### Operation
#### PMAXSW (64-bit operands)
```info-verb
    IF DEST[15:0] > SRC[15:0]) THEN
          DEST[15:0] <- DEST[15:0];
ELSE
          DEST[15:0] <- SRC[15:0]; FI;
    (* Repeat operation for 2nd and 3rd words in source and destination operands *)
    IF DEST[63:48] > SRC[63:48]) THEN
          DEST[63:48] <- DEST[63:48];
    ELSE
          DEST[63:48] <- SRC[63:48]; FI;
```
#### PMAXSB (128-bit Legacy SSE version)
```info-verb
    IF DEST[7:0] >SRC[7:0] THEN
          DEST[7:0] <- DEST[7:0];
    ELSE
          DEST[7:0] <- SRC[7:0]; FI;
    (* Repeat operation for 2nd through 15th bytes in source and destination operands *)
    IF DEST[127:120] >SRC[127:120] THEN
          DEST[127:120] <- DEST[127:120];
    ELSE
          DEST[127:120] <- SRC[127:120]; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPMAXSB (VEX.128 encoded version)
```info-verb
    IF SRC1[7:0] >SRC2[7:0] THEN
          DEST[7:0] <- SRC1[7:0];
    ELSE
          DEST[7:0] <- SRC2[7:0]; FI;
    (* Repeat operation for 2nd through 15th bytes in source and destination operands *)
    IF SRC1[127:120] >SRC2[127:120] THEN
          DEST[127:120] <- SRC1[127:120];
    ELSE
          DEST[127:120] <- SRC2[127:120]; FI;
DEST[MAX_VL-1:128] <- 0
```
#### VPMAXSB (VEX.256 encoded version)
```info-verb
    IF SRC1[7:0] >SRC2[7:0] THEN
          DEST[7:0] <- SRC1[7:0];
    ELSE
          DEST[7:0] <- SRC2[7:0]; FI;
    (* Repeat operation for 2nd through 31st bytes in source and destination operands *)
    IF SRC1[255:248] >SRC2[255:248] THEN
          DEST[255:248] <- SRC1[255:248];
    ELSE
          DEST[255:248] <- SRC2[255:248]; FI;
DEST[MAX_VL-1:256] <- 0
```
#### VPMAXSB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask* THEN
          IF SRC1[i+7:i] > SRC2[i+7:i] 
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
#### PMAXSW (128-bit Legacy SSE version)
```info-verb
    IF DEST[15:0] >SRC[15:0] THEN
          DEST[15:0] <- DEST[15:0];
    ELSE
          DEST[15:0] <- SRC[15:0]; FI;
    (* Repeat operation for 2nd through 7th words in source and destination operands *)
    IF DEST[127:112] >SRC[127:112] THEN
          DEST[127:112] <- DEST[127:112];
    ELSE
          DEST[127:112] <- SRC[127:112]; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPMAXSW (VEX.128 encoded version)
```info-verb
    IF SRC1[15:0] > SRC2[15:0] THEN
          DEST[15:0] <- SRC1[15:0];
    ELSE
          DEST[15:0] <- SRC2[15:0]; FI;
    (* Repeat operation for 2nd through 7th words in source and destination operands *)
    IF SRC1[127:112] >SRC2[127:112] THEN
          DEST[127:112] <- SRC1[127:112];
    ELSE
          DEST[127:112] <- SRC2[127:112]; FI;
DEST[MAX_VL-1:128] <- 0
```
#### VPMAXSW (VEX.256 encoded version)
```info-verb
    IF SRC1[15:0] > SRC2[15:0] THEN
          DEST[15:0] <- SRC1[15:0];
    ELSE
          DEST[15:0] <- SRC2[15:0]; FI;
    (* Repeat operation for 2nd through 15th words in source and destination operands *)
    IF SRC1[255:240] >SRC2[255:240] THEN
          DEST[255:240] <- SRC1[255:240];
    ELSE
          DEST[255:240] <- SRC2[255:240]; FI;
DEST[MAX_VL-1:256] <- 0
```
#### VPMAXSW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask* THEN
          IF SRC1[i+15:i] > SRC2[i+15:i] 
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
#### PMAXSD (128-bit Legacy SSE version)
```info-verb
    IF DEST[31:0] >SRC[31:0] THEN
          DEST[31:0] <- DEST[31:0];
    ELSE
          DEST[31:0] <- SRC[31:0]; FI;
    (* Repeat operation for 2nd through 7th words in source and destination operands *)
    IF DEST[127:96] >SRC[127:96] THEN
          DEST[127:96] <- DEST[127:96];
    ELSE
          DEST[127:96] <- SRC[127:96]; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPMAXSD (VEX.128 encoded version)
```info-verb
    IF SRC1[31:0] > SRC2[31:0] THEN
          DEST[31:0] <- SRC1[31:0];
    ELSE
          DEST[31:0] <- SRC2[31:0]; FI;
    (* Repeat operation for 2nd through 3rd dwords in source and destination operands *)
    IF SRC1[127:96] > SRC2[127:96] THEN
          DEST[127:96] <- SRC1[127:96];
    ELSE
          DEST[127:96] <- SRC2[127:96]; FI;
DEST[MAX_VL-1:128] <- 0
```
#### VPMAXSD (VEX.256 encoded version)
```info-verb
    IF SRC1[31:0] > SRC2[31:0] THEN
          DEST[31:0] <- SRC1[31:0];
    ELSE
          DEST[31:0] <- SRC2[31:0]; FI;
    (* Repeat operation for 2nd through 7th dwords in source and destination operands *)
    IF SRC1[255:224] > SRC2[255:224] THEN
          DEST[255:224] <- SRC1[255:224];
    ELSE
          DEST[255:224] <- SRC2[255:224]; FI;
DEST[MAX_VL-1:256] <- 0
```
#### VPMAXSD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*THEN
          IF (EVEX.b = 1) AND (SRC2 *is memory*)
                THEN 
                      IF SRC1[i+31:i] > SRC2[31:0] 
                            THEN DEST[i+31:i] <-  SRC1[i+31:i];
ELSE DEST[i+31:i] <-  SRC2[31:0]; 
                      FI;
                ELSE 
                      IF SRC1[i+31:i] > SRC2[i+31:i] 
                            THEN DEST[i+31:i] <-  SRC1[i+31:i];
                            ELSE DEST[i+31:i] <-  SRC2[i+31:i]; 
                FI;
          FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  DEST[i+31:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPMAXSQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
          IF (EVEX.b = 1) AND (SRC2 *is memory*)
                THEN 
                      IF SRC1[i+63:i] > SRC2[63:0] 
                            THEN DEST[i+63:i] <-  SRC1[i+63:i];
                            ELSE DEST[i+63:i] <-  SRC2[63:0]; 
                      FI;
                ELSE 
                      IF SRC1[i+63:i] > SRC2[i+63:i] 
                            THEN DEST[i+63:i] <-  SRC1[i+63:i];
                            ELSE DEST[i+63:i] <-  SRC2[i+63:i]; 
                FI;
          FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            THEN DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMAXSB __m512i _mm512_max_epi8( __m512i a, __m512i b);
VPMAXSB __m512i _mm512_mask_max_epi8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPMAXSB __m512i _mm512_maskz_max_epi8( __mmask64 k, __m512i a, __m512i b);
VPMAXSW __m512i _mm512_max_epi16( __m512i a, __m512i b);
VPMAXSW __m512i _mm512_mask_max_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPMAXSW __m512i _mm512_maskz_max_epi16( __mmask32 k, __m512i a, __m512i b);
VPMAXSB __m256i _mm256_mask_max_epi8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPMAXSB __m256i _mm256_maskz_max_epi8( __mmask32 k, __m256i a, __m256i b);
VPMAXSW __m256i _mm256_mask_max_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMAXSW __m256i _mm256_maskz_max_epi16( __mmask16 k, __m256i a, __m256i b);
VPMAXSB __m128i _mm_mask_max_epi8(__m128i s, __mmask16 k, __m128i a, __m128i b);
VPMAXSB __m128i _mm_maskz_max_epi8( __mmask16 k, __m128i a, __m128i b);
VPMAXSW __m128i _mm_mask_max_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMAXSW __m128i _mm_maskz_max_epi16( __mmask8 k, __m128i a, __m128i b);
VPMAXSD __m256i _mm256_mask_max_epi32(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMAXSD __m256i _mm256_maskz_max_epi32( __mmask16 k, __m256i a, __m256i b);
VPMAXSQ __m256i _mm256_mask_max_epi64(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPMAXSQ __m256i _mm256_maskz_max_epi64( __mmask8 k, __m256i a, __m256i b);
VPMAXSD __m128i _mm_mask_max_epi32(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMAXSD __m128i _mm_maskz_max_epi32( __mmask8 k, __m128i a, __m128i b);
VPMAXSQ __m128i _mm_mask_max_epi64(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMAXSQ __m128i _mm_maskz_max_epu64( __mmask8 k, __m128i a, __m128i b);
VPMAXSD __m512i _mm512_max_epi32( __m512i a, __m512i b);
VPMAXSD __m512i _mm512_mask_max_epi32(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPMAXSD __m512i _mm512_maskz_max_epi32( __mmask16 k, __m512i a, __m512i b);
VPMAXSQ __m512i _mm512_max_epi64( __m512i a, __m512i b);
VPMAXSQ __m512i _mm512_mask_max_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPMAXSQ __m512i _mm512_maskz_max_epi64( __mmask8 k, __m512i a, __m512i b);
(V)PMAXSB __m128i _mm_max_epi8 ( __m128i a, __m128i b);
(V)PMAXSW __m128i _mm_max_epi16 ( __m128i a, __m128i b)
(V)PMAXSD __m128i _mm_max_epi32 ( __m128i a, __m128i b);
VPMAXSB __m256i _mm256_max_epi8 ( __m256i a, __m256i b);
VPMAXSW __m256i _mm256_max_epi16 ( __m256i a, __m256i b)
VPMAXSD __m256i _mm256_max_epi32 ( __m256i a, __m256i b);
PMAXSW:__m64 _mm_max_pi16(__m64 a, __m64 b)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPMAXSD/Q, see Exceptions Type E4.

EVEX-encoded VPMAXSB/W, see Exceptions Type E4.nb.

