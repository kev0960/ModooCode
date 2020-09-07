----------------------------
title : VPSRLVW, VPSRLVD, VPSRLVQs (Intel x86/64 assembly instruction)
cat_title : VPSRLVW, VPSRLVD, VPSRLVQ
ref_title : VPSRLVW, VPSRLVD, VPSRLVQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VPSRLVW, VPSRLVD, VPSRLVQ

**Variable Bit Shift Right Logical **

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.128.66.0F38.W0 45 /r\newline{}VPSRLVD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX2|Shift doublewords in xmm2 right by amount specified in the corresponding element of xmm3/m128 while shifting in 0s.|
|VEX.NDS.128.66.0F38.W1 45 /r\newline{}VPSRLVQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX2|Shift quadwords in xmm2 right by amount specified in the corresponding element of xmm3/m128 while shifting in 0s.|
|VEX.NDS.256.66.0F38.W0 45 /r\newline{}VPSRLVD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Shift doublewords in ymm2 right by amount specified in the corresponding element of ymm3/m256 while shifting in 0s.|
|VEX.NDS.256.66.0F38.W1 45 /r\newline{}VPSRLVQ ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Shift quadwords in ymm2 right by amount specified in the corresponding element of ymm3/m256 while shifting in 0s.|
|EVEX.NDS.128.66.0F38.W1 10 /r\newline{}VPSRLVW xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Shift words in xmm2 right by amount specified in the corresponding element of xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F38.W1 10 /r\newline{}VPSRLVW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Shift words in ymm2 right by amount specified in the corresponding element of ymm3/m256 while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F38.W1 10 /r\newline{}VPSRLVW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Shift words in zmm2 right by amount specified in the corresponding element of zmm3/m512 while shifting in 0s using writemask k1.|
|EVEX.NDS.128.66.0F38.W0 45 /r\newline{}VPSRLVD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in xmm2 right by amount specified in the corresponding element of xmm3/m128/m32bcst while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F38.W0 45 /r\newline{}VPSRLVD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in ymm2 right by amount specified in the corresponding element of ymm3/m256/m32bcst while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F38.W0 45 /r\newline{}VPSRLVD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Shift doublewords in zmm2 right by amount specified in the corresponding element of zmm3/m512/m32bcst while shifting in 0s using writemask k1.|
|EVEX.NDS.128.66.0F38.W1 45 /r\newline{}VPSRLVQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in xmm2 right by amount specified in the corresponding element of xmm3/m128/m64bcst while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F38.W1 45 /r\newline{}VPSRLVQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in ymm2 right by amount specified in the corresponding element of ymm3/m256/m64bcst while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F38.W1 45 /r\newline{}VPSRLVQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Shift quadwords in zmm2 right by amount specified in the corresponding element of zmm3/m512/m64bcst while shifting in 0s using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Shifts the bits in the individual data elements (words, doublewords or quadword) in the first source operand to the right by the count value of respective data elements in the second source operand. As the bits in the data elements are shifted right, the empty high-order bits are cleared (set to 0). 

The count values are specified individually in each data element of the second source operand. If the unsigned integer value specified in the respective data element of the second source operand is greater than 15 (for word), 31 (for doublewords), or 63 (for a quadword), then the destination data element are written with 0. 

VEX.128 encoded version: The destination and first source operands are XMM registers. The count operand can be either an XMM register or a 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

VEX.256 encoded version: The destination and first source operands are YMM registers. The count operand can be either an YMM register or a 256-bit memory. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed.

EVEX encoded VPSRLVD/Q: The destination and first source operands are ZMM/YMM/XMM registers. The count operand can be either a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512-bit vector broad-casted from a 32/64-bit memory location. The destination is conditionally updated with writemask k1.

EVEX encoded VPSRLVW: The destination and first source operands are ZMM/YMM/XMM registers. The count operand can be either a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination is condition-ally updated with writemask k1.


### Operation
#### VPSRLVW (EVEX encoded version) 
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  ZeroExtend(SRC1[i+15:i] >> SRC2[i+15:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0;
```
#### VPSRLVD (VEX.128 version)
```info-verb
COUNT_0 <- SRC2[31 : 0]
    (* Repeat Each COUNT_i for the 2nd through 4th dwords of SRC2*)
COUNT_3 <- SRC2[127 : 96];
IF COUNT_0 < 32 THEN
    DEST[31:0] <- ZeroExtend(SRC1[31:0] >> COUNT_0);
ELSE
    DEST[31:0] <- 0;
    (* Repeat shift operation for 2nd through 4th dwords *)
IF COUNT_3 < 32 THEN
    DEST[127:96] <- ZeroExtend(SRC1[127:96] >> COUNT_3);
ELSE
    DEST[127:96] <- 0;
DEST[MAX_VL-1:128] <- 0;
```
#### VPSRLVD (VEX.256 version)
```info-verb
COUNT_0 <- SRC2[31 : 0];
    (* Repeat Each COUNT_i for the 2nd through 7th dwords of SRC2*)
COUNT_7 <- SRC2[255 : 224];
IF COUNT_0 < 32 THEN
DEST[31:0] <- ZeroExtend(SRC1[31:0] >> COUNT_0);
ELSE
DEST[31:0] <- 0;
    (* Repeat shift operation for 2nd through 7th dwords *)
IF COUNT_7 < 32 THEN
    DEST[255:224] <- ZeroExtend(SRC1[255:224] >> COUNT_7);
ELSE
    DEST[255:224] <- 0;
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLVD (EVEX encoded version) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+31:i] <-  ZeroExtend(SRC1[i+31:i] >> SRC2[31:0])
                      ELSE DEST[i+31:i] <-  ZeroExtend(SRC1[i+31:i] >> SRC2[i+31:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0;
```
#### VPSRLVQ (VEX.128 version)
```info-verb
COUNT_0 <- SRC2[63 : 0];
COUNT_1 <- SRC2[127 : 64];
IF COUNT_0 < 64 THEN
    DEST[63:0] <- ZeroExtend(SRC1[63:0] >> COUNT_0);
ELSE
    DEST[63:0] <- 0;
IF COUNT_1 < 64 THEN
    DEST[127:64] <- ZeroExtend(SRC1[127:64] >> COUNT_1);
ELSE
    DEST[127:64] <- 0;
DEST[MAX_VL-1:128] <- 0;
```
#### VPSRLVQ (VEX.256 version)
```info-verb
COUNT_0 <- SRC2[63 : 0];
    (* Repeat Each COUNT_i for the 2nd through 4th dwords of SRC2*)
COUNT_3 <- SRC2[255 : 192];
IF COUNT_0 < 64 THEN
DEST[63:0] <- ZeroExtend(SRC1[63:0] >> COUNT_0);
ELSE
DEST[63:0] <- 0;
    (* Repeat shift operation for 2nd through 4th dwords *)
IF COUNT_3 < 64 THEN
    DEST[255:192] <- ZeroExtend(SRC1[255:192] >> COUNT_3);
ELSE
    DEST[255:192] <- 0;
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLVQ (EVEX encoded version) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  ZeroExtend(SRC1[i+63:i] >> SRC2[63:0])
                      ELSE DEST[i+63:i] <-  ZeroExtend(SRC1[i+63:i] >> SRC2[i+63:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPSRLVW __m512i _mm512_srlv_epi16(__m512i a, __m512i cnt);
VPSRLVW __m512i _mm512_mask_srlv_epi16(__m512i s, __mmask32 k, __m512i a, __m512i cnt);
VPSRLVW __m512i _mm512_maskz_srlv_epi16( __mmask32 k, __m512i a, __m512i cnt);
VPSRLVW __m256i _mm256_mask_srlv_epi16(__m256i s, __mmask16 k, __m256i a, __m256i cnt);
VPSRLVW __m256i _mm256_maskz_srlv_epi16( __mmask16 k, __m256i a, __m256i cnt);
VPSRLVW __m128i _mm_mask_srlv_epi16(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRLVW __m128i _mm_maskz_srlv_epi16( __mmask8 k, __m128i a, __m128i cnt);
VPSRLVW __m256i _mm256_srlv_epi32 (__m256i m, __m256i count)
VPSRLVD __m512i _mm512_srlv_epi32(__m512i a, __m512i cnt);
VPSRLVD __m512i _mm512_mask_srlv_epi32(__m512i s, __mmask16 k, __m512i a, __m512i cnt);
VPSRLVD __m512i _mm512_maskz_srlv_epi32( __mmask16 k, __m512i a, __m512i cnt);
VPSRLVD __m256i _mm256_mask_srlv_epi32(__m256i s, __mmask8 k, __m256i a, __m256i cnt);
VPSRLVD __m256i _mm256_maskz_srlv_epi32( __mmask8 k, __m256i a, __m256i cnt);
VPSRLVD __m128i _mm_mask_srlv_epi32(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRLVD __m128i _mm_maskz_srlv_epi32( __mmask8 k, __m128i a, __m128i cnt);
VPSRLVQ __m512i _mm512_srlv_epi64(__m512i a, __m512i cnt);
VPSRLVQ __m512i _mm512_mask_srlv_epi64(__m512i s, __mmask8 k, __m512i a, __m512i cnt);
VPSRLVQ __m512i _mm512_maskz_srlv_epi64( __mmask8 k, __m512i a, __m512i cnt);
VPSRLVQ __m256i _mm256_mask_srlv_epi64(__m256i s, __mmask8 k, __m256i a, __m256i cnt);
VPSRLVQ __m256i _mm256_maskz_srlv_epi64( __mmask8 k, __m256i a, __m256i cnt);
VPSRLVQ __m128i _mm_mask_srlv_epi64(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRLVQ __m128i _mm_maskz_srlv_epi64( __mmask8 k, __m128i a, __m128i cnt);
VPSRLVQ __m256i _mm256_srlv_epi64 (__m256i m, __m256i count)
VPSRLVD __m128i _mm_srlv_epi32( __m128i a, __m128i cnt);
VPSRLVQ __m128i _mm_srlv_epi64( __m128i a, __m128i cnt);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 4.

EVEX-encoded VPSRLVD/Q, see Exceptions Type E4.

EVEX-encoded VPSRLVW, see Exceptions Type E4.nb.

