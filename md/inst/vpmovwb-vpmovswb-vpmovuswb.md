----------------------------
title : VPMOVWB, VPMOVSWB, VPMOVUSWBs (Intel x86/64 assembly instruction)
cat_title : VPMOVWB, VPMOVSWB, VPMOVUSWB
ref_title : VPMOVWB, VPMOVSWB, VPMOVUSWB
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPMOVWB, VPMOVSWB, VPMOVUSWB

**Down Convert Word to Byte**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.F3.0F38.W0 30 /r\newline{}VPMOVWB xmm1/m64 {k1}{z}, xmm2|HVM|V/V|AVX512VL\newline{}AVX512BW|Converts 8 packed word integers from xmm2 into 8 packed bytes in xmm1/m64 with truncation under writemask k1.|
|EVEX.128.F3.0F38.W0 20 /r\newline{}VPMOVSWB xmm1/m64 {k1}{z}, xmm2|HVM|V/V|AVX512VL\newline{}AVX512BW|Converts 8 packed signed word integers from xmm2 into 8 packed signed bytes in xmm1/m64 using signed saturation under writemask k1.|
|EVEX.128.F3.0F38.W0 10 /r\newline{}VPMOVUSWB xmm1/m64 {k1}{z}, xmm2|HVM|V/V|AVX512VL\newline{}AVX512BW|Converts 8 packed unsigned word integers from xmm2 into 8 packed unsigned bytes in 8mm1/m64 using unsigned saturation under writemask k1.|
|EVEX.256.F3.0F38.W0 30 /r\newline{}VPMOVWB xmm1/m128 {k1}{z}, ymm2|HVM|V/V|AVX512VL\newline{}AVX512BW|Converts 16 packed word integers from ymm2 into 16 packed bytes in xmm1/m128 with truncation under writemask k1.|
|EVEX.256.F3.0F38.W0 20 /r\newline{}VPMOVSWB xmm1/m128 {k1}{z}, ymm2|HVM|V/V|AVX512VL\newline{}AVX512BW|Converts 16 packed signed word integers from ymm2 into 16 packed signed bytes in xmm1/m128 using signed saturation under writemask k1.|
|EVEX.256.F3.0F38.W0 10 /r\newline{}VPMOVUSWB xmm1/m128 {k1}{z}, ymm2|HVM|V/V|AVX512VL\newline{}AVX512BW|Converts 16 packed unsigned word integers from ymm2 into 16 packed unsigned bytes in xmm1/m128 using unsigned saturation under writemask k1.|
|EVEX.512.F3.0F38.W0 30 /r\newline{}VPMOVWB ymm1/m256 {k1}{z}, zmm2|HVM|V/V|AVX512BW|Converts 32 packed word integers from zmm2 into 32 packed bytes in ymm1/m256 with truncation under writemask k1.|
|EVEX.512.F3.0F38.W0 20 /r\newline{}VPMOVSWB ymm1/m256 {k1}{z}, zmm2|HVM|V/V|AVX512BW|Converts 32 packed signed word integers from zmm2 into 32 packed signed bytes in ymm1/m256 using signed saturation under writemask k1.|
|EVEX.512.F3.0F38.W0 10 /r\newline{}VPMOVUSWB ymm1/m256 {k1}{z}, zmm2|HVM|V/V|AVX512BW|Converts 32 packed unsigned word integers from zmm2 into 32 packed unsigned bytes in ymm1/m256 using unsigned saturation under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|HVM|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description 


VPMOVWB down converts 16-bit integers into packed bytes using truncation. VPMOVSWB converts signed 16-bit integers into packed signed bytes using signed saturation. VPMOVUSWB convert unsigned word values into unsigned byte values using unsigned saturation. 

The source operand is a ZMM/YMM/XMM register. The destination operand is a YMM/XMM/XMM register or a 256/128/64-bit memory location.

Down-converted byte elements are written to the destination operand (the first operand) from the least-significant byte. Byte elements of the destination operand are updated according to the writemask. Bits (MAX_VL-1:256/128/64) of the register destination are zeroed.

Note: EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPMOVWB instruction (EVEX encoded versions) when dest is a register
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
    FOR j <-  0 TO Kl-1
          i <-  j * 8
          m <-  j * 16
          IF k1[j] OR *no writemask*
                THEN DEST[i+7:i] <-  TruncateWordToByte (SRC[m+15:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+7:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+7:i] = 0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/2] <-  0;
```
#### VPMOVWB instruction (EVEX encoded versions) when dest is memory
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
    FOR j <-  0 TO Kl-1
          i <-  j * 8
          m <-  j * 16
          IF k1[j] OR *no writemask*
                THEN DEST[i+7:i] <-  TruncateWordToByte (SRC[m+15:m])
                ELSE 
                      *DEST[i+7:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```
#### VPMOVSWB instruction (EVEX encoded versions) when dest is a register
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
    FOR j <-  0 TO Kl-1
          i <-  j * 8
          m <-  j * 16
          IF k1[j] OR *no writemask*
                THEN DEST[i+7:i] <-  SaturateSignedWordToByte (SRC[m+15:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+7:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+7:i] = 0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/2] <-  0;
```
#### VPMOVSWB instruction (EVEX encoded versions) when dest is memory
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
    FOR j <-  0 TO Kl-1
          i <-  j * 8
          m <-  j * 16
          IF k1[j] OR *no writemask*
                THEN DEST[i+7:i] <-  SaturateSignedWordToByte (SRC[m+15:m])
                ELSE 
                      *DEST[i+7:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```
#### VPMOVUSWB instruction (EVEX encoded versions) when dest is a register
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
    FOR j <-  0 TO Kl-1
          i <-  j * 8
          m <-  j * 16
          IF k1[j] OR *no writemask*
                THEN DEST[i+7:i] <-  SaturateUnsignedWordToByte (SRC[m+15:m])
                ELSE 
                      IF *merging-masking* ; merging-masking
                            THEN *DEST[i+7:i] remains unchanged*
                            ELSE *zeroing-masking* ; zeroing-masking
                                  DEST[i+7:i] = 0
                      FI
          FI;
    ENDFOR
    DEST[MAX_VL-1:VL/2] <-  0;
```
#### VPMOVUSWB instruction (EVEX encoded versions) when dest is memory
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
    FOR j <-  0 TO Kl-1
          i <-  j * 8
          m <-  j * 16
          IF k1[j] OR *no writemask*
                THEN DEST[i+7:i] <-  SaturateUnsignedWordToByte (SRC[m+15:m])
                ELSE 
                      *DEST[i+7:i] remains unchanged* ; merging-masking
          FI;
    ENDFOR
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPMOVUSWB __m256i _mm512_cvtusepi16_epi8(__m512i a);
VPMOVUSWB __m256i _mm512_mask_cvtusepi16_epi8(__m256i a, __mmask32 k, __m512i b);
VPMOVUSWB __m256i _mm512_maskz_cvtusepi16_epi8( __mmask32 k, __m512i b);
VPMOVUSWB void _mm512_mask_cvtusepi16_storeu_epi8(void * , __mmask32 k, __m512i b);
VPMOVSWB __m256i _mm512_cvtsepi16_epi8(__m512i a);
VPMOVSWB __m256i _mm512_mask_cvtsepi16_epi8(__m256i a, __mmask32 k, __m512i b);
VPMOVSWB __m256i _mm512_maskz_cvtsepi16_epi8( __mmask32 k, __m512i b);
VPMOVSWB void _mm512_mask_cvtsepi16_storeu_epi8(void * , __mmask32 k, __m512i b);
VPMOVWB __m256i _mm512_cvtepi16_epi8(__m512i a);
VPMOVWB __m256i _mm512_mask_cvtepi16_epi8(__m256i a, __mmask32 k, __m512i b);
VPMOVWB __m256i _mm512_maskz_cvtepi16_epi8( __mmask32 k, __m512i b);
VPMOVWB void _mm512_mask_cvtepi16_storeu_epi8(void * , __mmask32 k, __m512i b);
VPMOVUSWB __m128i _mm256_cvtusepi16_epi8(__m256i a);
VPMOVUSWB __m128i _mm256_mask_cvtusepi16_epi8(__m128i a, __mmask16 k, __m256i b);
VPMOVUSWB __m128i _mm256_maskz_cvtusepi16_epi8( __mmask16 k, __m256i b);
VPMOVUSWB void _mm256_mask_cvtusepi16_storeu_epi8(void * , __mmask16 k, __m256i b);
VPMOVUSWB __m128i _mm_cvtusepi16_epi8(__m128i a);
VPMOVUSWB __m128i _mm_mask_cvtusepi16_epi8(__m128i a, __mmask8 k, __m128i b);
VPMOVUSWB __m128i _mm_maskz_cvtusepi16_epi8( __mmask8 k, __m128i b);
VPMOVUSWB void _mm_mask_cvtusepi16_storeu_epi8(void * , __mmask8 k, __m128i b);
VPMOVSWB __m128i _mm256_cvtsepi16_epi8(__m256i a);
VPMOVSWB __m128i _mm256_mask_cvtsepi16_epi8(__m128i a, __mmask16 k, __m256i b);
VPMOVSWB __m128i _mm256_maskz_cvtsepi16_epi8( __mmask16 k, __m256i b);
VPMOVSWB void _mm256_mask_cvtsepi16_storeu_epi8(void * , __mmask16 k, __m256i b);
VPMOVSWB __m128i _mm_cvtsepi16_epi8(__m128i a);
VPMOVSWB __m128i _mm_mask_cvtsepi16_epi8(__m128i a, __mmask8 k, __m128i b);
VPMOVSWB __m128i _mm_maskz_cvtsepi16_epi8( __mmask8 k, __m128i b);
VPMOVSWB void _mm_mask_cvtsepi16_storeu_epi8(void * , __mmask8 k, __m128i b);
VPMOVWB __m128i _mm256_cvtepi16_epi8(__m256i a);
VPMOVWB __m128i _mm256_mask_cvtepi16_epi8(__m128i a, __mmask16 k, __m256i b);
VPMOVWB __m128i _mm256_maskz_cvtepi16_epi8( __mmask16 k, __m256i b);
VPMOVWB void _mm256_mask_cvtepi16_storeu_epi8(void * , __mmask16 k, __m256i b);
VPMOVWB __m128i _mm_cvtepi16_epi8(__m128i a);
VPMOVWB __m128i _mm_mask_cvtepi16_epi8(__m128i a, __mmask8 k, __m128i b);
VPMOVWB __m128i _mm_maskz_cvtepi16_epi8( __mmask8 k, __m128i b);
VPMOVWB void _mm_mask_cvtepi16_storeu_epi8(void * , __mmask8 k, __m128i b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E6NF

#UD  If EVEX.vvvv != 1111B.
