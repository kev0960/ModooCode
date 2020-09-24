----------------------------
title : PABSB, PABSW, PABSD, PABSQs (Intel x86/64 assembly instruction)
cat_title : PABSB, PABSW, PABSD, PABSQ
ref_title : PABSB, PABSW, PABSD, PABSQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PABSB, PABSW, PABSD, PABSQ

** Packed Absolute Value **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 1C /r\footnote{1}`\newline{}`PABSB` mm1 mm2/m64 |RM|V/V|SSSE3|Compute the absolute value of bytes in mm2/m64 and store UNSIGNED result in mm1.|
|`66 0F 38 1C /r `\newline{}`PABSB` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Compute the absolute value of bytes in xmm2/m128 and store UNSIGNED result in xmm1. |
|`0F 38 1D /r\footnote{1}`\newline{}`PABSW` mm1 mm2/m64 |RM|V/V|SSSE3|Compute the absolute value of 16-bit integers in mm2/m64 and store UNSIGNED result in mm1.|
|`66 0F 38 1D /r`\newline{}`PABSW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Compute the absolute value of 16-bit integers in xmm2/m128 and store UNSIGNED result in xmm1.|
|`0F 38 1E /r\footnote{1}  `\newline{}`PABSD` mm1 mm2/m64 |RM|V/V|SSSE3|Compute the absolute value of 32-bit integers in mm2/m64 and store UNSIGNED result in mm1. |
|`66 0F 38 1E /r `\newline{}`PABSD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Compute the absolute value of 32-bit integers in xmm2/m128 and store UNSIGNED result in xmm1. |
|`VEX.128.66.0F38.WIG 1C /r`\newline{}VPABSB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Compute the absolute value of bytes in xmm2/m128 and store UNSIGNED result in xmm1.|
|`VEX.128.66.0F38.WIG 1D /r`\newline{}VPABSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Compute the absolute value of 16- bit integers in xmm2/m128 and store UNSIGNED result in xmm1.|
|`VEX.128.66.0F38.WIG 1E /r`\newline{}VPABSD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Compute the absolute value of 32- bit integers in xmm2/m128 and store UNSIGNED result in xmm1.|
|`VEX.256.66.0F38.WIG 1C /r`\newline{}VPABSB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX2|Compute the absolute value of bytes in ymm2/m256 and store UNSIGNED result in ymm1.|
|`VEX.256.66.0F38.WIG 1D /r`\newline{}VPABSW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX2|Compute the absolute value of 16-bit integers in ymm2/m256 and store UNSIGNED result in ymm1.|
|`VEX.256.66.0F38.WIG 1E /r`\newline{}VPABSD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX2|Compute the absolute value of 32-bit integers in ymm2/m256 and store UNSIGNED result in ymm1.|
|`EVEX.128.66.0F38.WIG 1C /r`\newline{}VPABSB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Compute the absolute value of bytes in xmm2/m128 and store UNSIGNED result in xmm1 using writemask k1.|
|`EVEX.256.66.0F38.WIG 1C /r`\newline{}VPABSB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Compute the absolute value of bytes in ymm2/m256 and store UNSIGNED result in ymm1 using writemask k1.|
|`EVEX.512.66.0F38.WIG 1C /r`\newline{}VPABSB zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Compute the absolute value of bytes in zmm2/m512 and store UNSIGNED result in zmm1 using writemask k1.|
|`EVEX.128.66.0F38.WIG 1D /r `\newline{}VPABSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Compute the absolute value of 16-bit integers in xmm2/m128 and store UNSIGNED result in xmm1 using writemask k1.|


|EVEX.256.66.0F38.WIG 1D /r \newline{}VPABSW ymm1 {k1}{z}, ymm2/m256 |FVM|V/V|AVX512VL\newline{}\newline{}AVX512BW|Compute the absolute value of 16-bit integers \newline{}in ymm2/m256 and store UNSIGNED result in \newline{}ymm1 using writemask k1.|
|--------------------------------------------------------------------|---|---|------------------------------------|------------------------------------------------------------------------------------------------------------------------------------|
|EVEX.512.66.0F38.WIG 1D /r VPABSW zmm1 {k1}{z}, zmm2/m512|FVM|V/V|AVX512BW|Compute the absolute value of 16-bit integers in zmm2/m512 and store UNSIGNED result in zmm1 using writemask k1.|
|EVEX.128.66.0F38.W0 1E /rVPABSD xmm1 {k1}{z}, xmm2/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compute the absolute value of 32-bit integers in xmm2/m128/m32bcst and store UNSIGNED result in xmm1 using writemask k1. |
|EVEX.256.66.0F38.W0 1E /rVPABSD ymm1 {k1}{z}, ymm2/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compute the absolute value of 32-bit integers in ymm2/m256/m32bcst and store UNSIGNED result in ymm1 using writemask k1. |
|VPABSD zmm1 {k1}{z}, zmm2/m512/m32bcst |FV|V/V|AVX512F|Compute the absolute value of 32-bit integers in zmm2/m512/m32bcst and store UNSIGNED result in zmm1 using writemask k1. |
|EVEX.128.66.0F38.W1 1F /rVPABSQ xmm1 {k1}{z}, xmm2/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compute the absolute value of 64-bit integers in xmm2/m128/m64bcst and store UNSIGNED result in xmm1 using writemask k1. |
|EVEX.256.66.0F38.W1 1F /rVPABSQ ymm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compute the absolute value of 64-bit integers in ymm2/m256/m64bcst and store UNSIGNED result in ymm1 using writemask k1. |
|EVEX.512.66.0F38.W1 1F /rVPABSQ zmm1 {k1}{z}, zmm2/m512/m64bcst |FV|V/V|AVX512F|Compute the absolute value of 64-bit integers in zmm2/m512/m64bcst and store UNSIGNED result in zmm1 using writemask k1. |

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FVM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description 


PABSB/W/D computes the absolute value of each data element of the source operand (the second operand) and stores the UNSIGNED results in the destination operand (the first operand). PABSB operates on signed bytes, PABSW operates on signed 16-bit words, and PABSD operates on signed 32-bit integers. 

EVEX encoded VPABSD/Q: The source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a ZMM/YMM/XMM register updated according to the writemask. 

EVEX encoded VPABSB/W: The source operand is a ZMM/YMM/XMM register, or a 512/256/128-bit memory loca-tion. The destination operand is a ZMM/YMM/XMM register updated according to the writemask. 

VEX.256 encoded versions: The source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX_VL-1:256) of the corresponding register destination are zeroed.

VEX.128 encoded versions: The source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding register destination are zeroed.



128-bit Legacy SSE version: The source operand can be an XMM register or an 128-bit memory location. The desti-nation is an XMM register. The upper bits (VL_MAX-1:128) of the corresponding register destination are unmodi-fied.

VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### PABSB with 128 bit operands:
```info-verb
    Unsigned DEST[7:0] <- ABS(SRC[7: 0]) 
    Repeat operation for 2nd through 15th bytes 
    Unsigned DEST[127:120] <- ABS(SRC[127:120])
```
#### VPABSB with 128 bit operands:
```info-verb
    Unsigned DEST[7:0] <- ABS(SRC[7: 0]) 
    Repeat operation for 2nd through 15th bytes 
    Unsigned DEST[127:120]<- ABS(SRC[127:120])
```
#### VPABSB with 256 bit operands:
```info-verb
    Unsigned DEST[7:0]<- ABS(SRC[7: 0]) 
    Repeat operation for 2nd through 31st bytes 
    Unsigned DEST[255:248]<- ABS(SRC[255:248]) 
```
#### VPABSB (EVEX encoded versions)
```info-verb
    (KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN 
                Unsigned DEST[i+7:i] <-  ABS(SRC[i+7:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### PABSW with 128 bit operands:
```info-verb
    Unsigned DEST[15:0]<- ABS(SRC[15:0]) 
    Repeat operation for 2nd through 7th 16-bit words 
    Unsigned DEST[127:112]<- ABS(SRC[127:112]) 
```
#### VPABSW with 128 bit operands:
```info-verb
    Unsigned DEST[15:0] <- ABS(SRC[15:0]) 
    Repeat operation for 2nd through 7th 16-bit words 
    Unsigned DEST[127:112]<- ABS(SRC[127:112]) 
```
#### VPABSW with 256 bit operands:
```info-verb
    Unsigned DEST[15:0]<- ABS(SRC[15:0]) 
    Repeat operation for 2nd through 15th 16-bit words 
    Unsigned DEST[255:240] <- ABS(SRC[255:240]) 
```
#### VPABSW (EVEX encoded versions)
```info-verb
    (KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN 
                Unsigned DEST[i+15:i] <-  ABS(SRC[i+15:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### PABSD with 128 bit operands:
```info-verb
    Unsigned DEST[31:0]<- ABS(SRC[31:0]) 
    Repeat operation for 2nd through 3rd 32-bit double words 
    Unsigned DEST[127:96]<- ABS(SRC[127:96]) 
```
#### VPABSD with 128 bit operands:
```info-verb
    Unsigned DEST[31:0]<- ABS(SRC[31:0]) 
    Repeat operation for 2nd through 3rd 32-bit double words 
    Unsigned DEST[127:96]<- ABS(SRC[127:96]) 
```
#### VPABSD with 256 bit operands:
```info-verb
    Unsigned DEST[31:0] <- ABS(SRC[31:0]) 
    Repeat operation for 2nd through 7th 32-bit double words 
    Unsigned DEST[255:224] <- ABS(SRC[255:224]) 
```
#### VPABSD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN
                            Unsigned DEST[i+31:i] <-  ABS(SRC[31:0])
                      ELSE 
                            Unsigned DEST[i+31:i] <-  ABS(SRC[i+31:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPABSQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN
                            Unsigned DEST[i+63:i] <-  ABS(SRC[63:0])
                      ELSE 
                            Unsigned DEST[i+63:i] <-  ABS(SRC[i+63:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPABSB__m512i _mm512_abs_epi8 ( __m512i a)
VPABSW__m512i _mm512_abs_epi16 ( __m512i a)
VPABSB__m512i _mm512_mask_abs_epi8 ( __m512i s, __mmask64 m, __m512i a)
VPABSW__m512i _mm512_mask_abs_epi16 ( __m512i s, __mmask32 m, __m512i a)
VPABSB__m512i _mm512_maskz_abs_epi8 (__mmask64 m, __m512i a)
VPABSW__m512i _mm512_maskz_abs_epi16 (__mmask32 m, __m512i a)
VPABSB__m256i _mm256_mask_abs_epi8 (__m256i s, __mmask32 m, __m256i a)
VPABSW__m256i _mm256_mask_abs_epi16 (__m256i s, __mmask16 m, __m256i a)
VPABSB__m256i _mm256_maskz_abs_epi8 (__mmask32 m, __m256i a)
VPABSW__m256i _mm256_maskz_abs_epi16 (__mmask16 m, __m256i a)
VPABSB__m128i _mm_mask_abs_epi8 (__m128i s, __mmask16 m, __m128i a)
VPABSW__m128i _mm_mask_abs_epi16 (__m128i s, __mmask8 m, __m128i a)
VPABSB__m128i _mm_maskz_abs_epi8 (__mmask16 m, __m128i a)
VPABSW__m128i _mm_maskz_abs_epi16 (__mmask8 m, __m128i a)
VPABSD __m256i _mm256_mask_abs_epi32(__m256i s, __mmask8 k, __m256i a);
VPABSD __m256i _mm256_maskz_abs_epi32( __mmask8 k, __m256i a);
VPABSD __m128i _mm_mask_abs_epi32(__m128i s, __mmask8 k, __m128i a);
VPABSD __m128i _mm_maskz_abs_epi32( __mmask8 k, __m128i a);
VPABSD  __m512i _mm512_abs_epi32( __m512i a);
VPABSD  __m512i _mm512_mask_abs_epi32(__m512i s, __mmask16 k, __m512i a);
VPABSD  __m512i _mm512_maskz_abs_epi32( __mmask16 k, __m512i a);
VPABSQ __m512i _mm512_abs_epi64( __m512i a);
VPABSQ __m512i _mm512_mask_abs_epi64(__m512i s, __mmask8 k, __m512i a);
VPABSQ __m512i _mm512_maskz_abs_epi64( __mmask8 k, __m512i a);
VPABSQ __m256i _mm256_mask_abs_epi64(__m256i s, __mmask8 k, __m256i a);
VPABSQ __m256i _mm256_maskz_abs_epi64( __mmask8 k, __m256i a);
VPABSQ __m128i _mm_mask_abs_epi64(__m128i s, __mmask8 k, __m128i a);
VPABSQ __m128i _mm_maskz_abs_epi64( __mmask8 k, __m128i a);
PABSB __m128i _mm_abs_epi8 (__m128i a)
VPABSB __m128i _mm_abs_epi8 (__m128i a)
VPABSB __m256i _mm256_abs_epi8 (__m256i a)
PABSW __m128i _mm_abs_epi16 (__m128i a)
VPABSW __m128i _mm_abs_epi16 (__m128i a)
VPABSW __m256i _mm256_abs_epi16 (__m256i a)
PABSD __m128i _mm_abs_epi32 (__m128i a)
VPABSD __m128i _mm_abs_epi32 (__m128i a)
VPABSD __m256i _mm256_abs_epi32 (__m256i a)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPABSD/Q, see Exceptions Type E4.

EVEX-encoded VPABSB/W, see Exceptions Type E4.nb.

