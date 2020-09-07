----------------------------
title : VPBROADCASTB, VPBROADCASTW, VPBROADCASTD, VPBROADCASTQs (Intel x86/64 assembly instruction)
cat_title : VPBROADCASTB, VPBROADCASTW, VPBROADCASTD, VPBROADCASTQ
ref_title : VPBROADCASTB, VPBROADCASTW, VPBROADCASTD, VPBROADCASTQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VPBROADCASTB, VPBROADCASTW, VPBROADCASTD, VPBROADCASTQ

**Load with Broadcast Integer Data from General Purpose Register**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|--------------------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W0 7A /r\newline{}VPBROADCASTB xmm1 {k1}{z}, reg|T1S|V/V|AVX512VL\newline{}AVX512BW|Broadcast an 8-bit value from a GPR to all bytes in the 128-bit destination subject to writemask k1.|
|EVEX.256.66.0F38.W0 7A /r\newline{}VPBROADCASTB ymm1 {k1}{z}, reg|T1S|V/V|AVX512VL\newline{}AVX512BW|Broadcast an 8-bit value from a GPR to all bytes in the 256-bit destination subject to writemask k1.|
|EVEX.512.66.0F38.W0 7A /r\newline{}VPBROADCASTB zmm1 {k1}{z}, reg|T1S|V/V|AVX512BW|Broadcast an 8-bit value from a GPR to all bytes in the 512-bit destination subject to writemask k1.|
|EVEX.128.66.0F38.W0 7B /r\newline{}VPBROADCASTW xmm1 {k1}{z}, reg|T1S|V/V|AVX512VL\newline{}AVX512BW|Broadcast a 16-bit value from a GPR to all words in the 128-bit destination subject to writemask k1.|
|EVEX.256.66.0F38.W0 7B /r\newline{}VPBROADCASTW ymm1 {k1}{z}, reg|T1S|V/V|AVX512VL\newline{}AVX512BW|Broadcast a 16-bit value from a GPR to all words in the 256-bit destination subject to writemask k1.|
|EVEX.512.66.0F38.W0 7B /r\newline{}VPBROADCASTW zmm1 {k1}{z}, reg|T1S|V/V|AVX512BW|Broadcast a 16-bit value from a GPR to all words in the 512-bit destination subject to writemask k1.|
|EVEX.128.66.0F38.W0 7C /r\newline{}VPBROADCASTD xmm1 {k1}{z}, r32|T1S|V/V|AVX512VL\newline{}AVX512F|Broadcast a 32-bit value from a GPR to all double-words in the 128-bit destination subject to writemask k1.|
|EVEX.256.66.0F38.W0 7C /r\newline{}VPBROADCASTD ymm1 {k1}{z}, r32|T1S|V/V|AVX512VL\newline{}AVX512F|Broadcast a 32-bit value from a GPR to all double-words in the 256-bit destination subject to writemask k1.|
|EVEX.512.66.0F38.W0 7C /r\newline{}VPBROADCASTD zmm1 {k1}{z}, r32|T1S|V/V|AVX512F|Broadcast a 32-bit value from a GPR to all double-words in the 512-bit destination subject to writemask k1.|
|EVEX.128.66.0F38.W1 7C /r\newline{}VPBROADCASTQ xmm1 {k1}{z}, r64|T1S|V/N.E.\footnote{1}|AVX512VL\newline{}AVX512F|Broadcast a 64-bit value from a GPR to all quad-words in the 128-bit destination subject to writemask k1.|
|EVEX.256.66.0F38.W1 7C /r\newline{}VPBROADCASTQ ymm1 {k1}{z}, r64|T1S|V/N.E.\footnote{1}|AVX512VL\newline{}AVX512F|Broadcast a 64-bit value from a GPR to all quad-words in the 256-bit destination subject to writemask k1.|
|EVEX.512.66.0F38.W1 7C /r\newline{}VPBROADCASTQ zmm1 {k1}{z}, r64|T1S|V/N.E.\footnote{1}|AVX512F|Broadcast a 64-bit value from a GPR to all quad-words in the 512-bit destination subject to writemask k1.|
||||||

```note
1. EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 version is used
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Broadcasts a 8-bit, 16-bit, 32-bit or 64-bit value from a general-purpose register (the second operand) to all the locations in the destination vector register (the first operand) using the writemask k1.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPBROADCASTB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <- j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SRC[7:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+7:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPBROADCASTW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <- j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SRC[15:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPBROADCASTD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <- j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[31:0]
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
#### VPBROADCASTQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <- j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC[63:0]
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

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPBROADCASTB __m512i _mm512_mask_set1_epi8(__m512i s, __mmask64 k, int a);
VPBROADCASTB __m512i _mm512_maskz_set1_epi8( __mmask64 k, int a);
VPBROADCASTB __m256i _mm256_mask_set1_epi8(__m256i s, __mmask32 k, int a);
VPBROADCASTB __m256i _mm256_maskz_set1_epi8( __mmask32 k, int a);
VPBROADCASTB __m128i _mm_mask_set1_epi8(__m128i s, __mmask16 k, int a);
VPBROADCASTB __m128i _mm_maskz_set1_epi8( __mmask16 k, int a);
VPBROADCASTD __m512i _mm512_mask_set1_epi32(__m512i s, __mmask16 k, int a);
VPBROADCASTD __m512i _mm512_maskz_set1_epi32( __mmask16 k, int a);
VPBROADCASTD __m256i _mm256_mask_set1_epi32(__m256i s, __mmask8 k, int a);
VPBROADCASTD __m256i _mm256_maskz_set1_epi32( __mmask8 k, int a);
VPBROADCASTD __m128i _mm_mask_set1_epi32(__m128i s, __mmask8 k, int a);
VPBROADCASTD __m128i _mm_maskz_set1_epi32( __mmask8 k, int a);
VPBROADCASTQ __m512i _mm512_mask_set1_epi64(__m512i s, __mmask8 k, __int64 a);
VPBROADCASTQ __m512i _mm512_maskz_set1_epi64( __mmask8 k, __int64 a);
VPBROADCASTQ __m256i _mm256_mask_set1_epi64(__m256i s, __mmask8 k, __int64 a);
VPBROADCASTQ __m256i _mm256_maskz_set1_epi64( __mmask8 k, __int64 a);
VPBROADCASTQ __m128i _mm_mask_set1_epi64(__m128i s, __mmask8 k, __int64 a);
VPBROADCASTQ __m128i _mm_maskz_set1_epi64( __mmask8 k, __int64 a);
VPBROADCASTW __m512i _mm512_mask_set1_epi16(__m512i s, __mmask32 k, int a);
VPBROADCASTW __m512i _mm512_maskz_set1_epi16( __mmask32 k, int a);
VPBROADCASTW __m256i _mm256_mask_set1_epi16(__m256i s, __mmask16 k, int a);
VPBROADCASTW __m256i _mm256_maskz_set1_epi16( __mmask16 k, int a);
VPBROADCASTW __m128i _mm_mask_set1_epi16(__m128i s, __mmask8 k, int a);
VPBROADCASTW __m128i _mm_maskz_set1_epi16( __mmask8 k, int a);
```
### Exceptions


EVEX-encoded instructions, see Exceptions Type E7NM.

#UD If EVEX.vvvv != 1111B.

