----------------------------
title : PADDSB, PADDSWs (Intel x86/64 assembly instruction)
cat_title : PADDSB, PADDSW
ref_title : PADDSB, PADDSW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PADDSB, PADDSW

**Add Packed Signed Integers with Signed Saturation**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F EC /r\footnote{1}`\newline{}`PADDSB` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V |MMX|Add packed signed byte integers from mm/m64 and mm and saturate the results.|
|`66 0F EC /r`\newline{}`PADDSB` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Add packed signed byte integers from xmm2/m128 and xmm1 saturate the results.|
|`0F ED /r\footnote{1}`\newline{}`PADDSW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Add packed signed word integers from mm/m64 and mm and saturate the results.|
|`66 0F ED /r`\newline{}`PADDSW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Add packed signed word integers from xmm2/m128 and xmm1 and saturate the results.|
|`VEX.NDS.128.66.0F.WIG EC /r`\newline{}VPADDSB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Add packed signed byte integers from xmm3/m128 and xmm2 saturate the results.|
|`VEX.NDS.128.66.0F.WIG ED /r`\newline{}VPADDSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Add packed signed word integers from xmm3/m128 and xmm2 and saturate the results.|
|`VEX.NDS.256.66.0F.WIG EC /r`\newline{}VPADDSB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Add packed signed byte integers from ymm2, and ymm3/m256 and store the saturated results in ymm1.|
|`VEX.NDS.256.66.0F.WIG ED /r`\newline{}VPADDSW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Add packed signed word integers from ymm2, and ymm3/m256 and store the saturated results in ymm1.|
|`EVEX.NDS.128.66.0F.WIG EC /r`\newline{}VPADDSB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Add packed signed byte integers from xmm2, and xmm3/m128 and store the saturated results in xmm1 under writemask k1.|
|`EVEX.NDS.256.66.0F.WIG EC /r`\newline{}VPADDSB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Add packed signed byte integers from ymm2, and ymm3/m256 and store the saturated results in ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F.WIG EC /r`\newline{}VPADDSB zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Add packed signed byte integers from zmm2, and zmm3/m512 and store the saturated results in zmm1 under writemask k1.|
|`EVEX.NDS.128.66.0F.WIG ED /r`\newline{}VPADDSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Add packed signed word integers from xmm2, and xmm3/m128 and store the saturated results in xmm1 under writemask k1.|
|`EVEX.NDS.256.66.0F.WIG ED /r`\newline{}VPADDSW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Add packed signed word integers from ymm2, and ymm3/m256 and store the saturated results in ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F.WIG ED /r`\newline{}VPADDSW zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Add packed signed word integers from zmm2, and zmm3/m512 and store the saturated results in zmm1 under writemask k1.|

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


Performs a SIMD add of the packed signed integers from the source operand (second operand) and the destination operand (first operand), and stores the packed integer results in the destination operand. See Figure 9-4 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for an illustration of a SIMD operation. Overflow is handled with signed saturation, as described in the following paragraphs.

(V)PADDSB performs a SIMD add of the packed signed integers with saturation from the first source operand and second source operand and stores the packed integer results in the destination operand. When an individual byte result is beyond the range of a signed byte integer (that is, greater than 7FH or less than 80H), the saturated value of 7FH or 80H, respectively, is written to the destination operand.

(V)PADDSW performs a SIMD add of the packed signed word integers with saturation from the first source operand and second source operand and stores the packed integer results in the destination operand. When an individual word result is beyond the range of a signed word integer (that is, greater than 7FFFH or less than 8000H), the satu-rated value of 7FFFH or 8000H, respectively, is written to the destination operand.

EVEX encoded versions: The first source operand is an ZMM/YMM/XMM register. The second source operand is an ZMM/YMM/XMM register or a memory location. The destination operand is an ZMM/YMM/XMM register.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. 

VEX.128 encoded version: The first source operand is an XMM register. The second source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (MAX\esc{_}VL-1:128) of the corresponding register destination are zeroed.

128-bit Legacy SSE version: The first source operand is an XMM register. The second operand can be an XMM register or an 128-bit memory location. The destination is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding register destination are unmodified.


### Operation
#### PADDSB (with 64-bit operands)
```info-verb
    DEST[7:0] <- SaturateToSignedByte(DEST[7:0] + SRC (7:0]);
    (* Repeat add operation for 2nd through 7th bytes *)
    DEST[63:56] <- SaturateToSignedByte(DEST[63:56] + SRC[63:56] );
```
#### PADDSB (with 128-bit operands)
```info-verb
    DEST[7:0] <-SaturateToSignedByte (DEST[7:0] + SRC[7:0]);
    (* Repeat add operation for 2nd through 14th bytes *)
    DEST[127:120] <- SaturateToSignedByte (DEST[111:120] + SRC[127:120]);
```
#### VPADDSB (VEX.128 encoded version)
```info-verb
    DEST[7:0] <-  SaturateToSignedByte (SRC1[7:0] + SRC2[7:0]);
    (* Repeat subtract operation for 2nd through 14th bytes *)
    DEST[127:120] <-  SaturateToSignedByte (SRC1[111:120] + SRC2[127:120]);
    DEST[VLMAX-1:128] <-  0
```
#### VPADDSB (VEX.256 encoded version)
```info-verb
    DEST[7:0] <-  SaturateToSignedByte (SRC1[7:0] + SRC2[7:0]);
    (* Repeat add operation for 2nd through 31st bytes *)
    DEST[255:248]<-  SaturateToSignedByte (SRC1[255:248] + SRC2[255:248]);
```
#### VPADDSB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SaturateToSignedByte (SRC1[i+7:i] + SRC2[i+7:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i] = 0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### PADDSW (with 64-bit operands)
```info-verb
    DEST[15:0] <- SaturateToSignedWord(DEST[15:0] + SRC[15:0] );
    (* Repeat add operation for 2nd and 7th words *)
    DEST[63:48] <- SaturateToSignedWord(DEST[63:48] + SRC[63:48] );
```
#### PADDSW (with 128-bit operands)
```info-verb
    DEST[15:0]  <- SaturateToSignedWord (DEST[15:0] + SRC[15:0]);
    (* Repeat add operation for 2nd through 7th words *)
    DEST[127:112] <- SaturateToSignedWord (DEST[127:112] + SRC[127:112]);
```
#### VPADDSW (VEX.128 encoded version)
```info-verb
    DEST[15:0] <-  SaturateToSignedWord (SRC1[15:0] + SRC2[15:0]);
    (* Repeat subtract operation for 2nd through 7th words *)
    DEST[127:112] <-  SaturateToSignedWord (SRC1[127:112] + SRC2[127:112]);
    DEST[VLMAX-1:128] <-  0
```
#### VPADDSW (VEX.256 encoded version)
```info-verb
    DEST[15:0] <-  SaturateToSignedWord (SRC1[15:0] + SRC2[15:0]);
    (* Repeat add operation for 2nd through 15th words *)
    DEST[255:240] <-  SaturateToSignedWord (SRC1[255:240] + SRC2[255:240])
```
#### VPADDSW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SaturateToSignedWord (SRC1[i+15:i] + SRC2[i+15:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
PADDSB:  __m64 _mm_adds_pi8(__m64 m1, __m64 m2)
(V)PADDSB:  __m128i _mm_adds_epi8 ( __m128i a, __m128i b)
VPADDSB: __m256i _mm256_adds_epi8 ( __m256i a, __m256i b)
PADDSW:  __m64 _mm_adds_pi16(__m64 m1, __m64 m2)
(V)PADDSW:  __m128i _mm_adds_epi16 ( __m128i a, __m128i b)
VPADDSW: __m256i _mm256_adds_epi16 ( __m256i a, __m256i b)VPADDSB__m512i _mm512_adds_epi8 ( __m512i a, __m512i b)
VPADDSW__m512i _mm512_adds_epi16 ( __m512i a, __m512i b)
VPADDSB__m512i _mm512_mask_adds_epi8 ( __m512i s, __mmask64 m, __m512i a, __m512i b)
VPADDSW__m512i _mm512_mask_adds_epi16 ( __m512i s, __mmask32 m, __m512i a, __m512i b)
VPADDSB__m512i _mm512_maskz_adds_epi8 (__mmask64 m, __m512i a, __m512i b)
VPADDSW__m512i _mm512_maskz_adds_epi16 (__mmask32 m, __m512i a, __m512i b)
VPADDSB__m256i _mm256_mask_adds_epi8 (__m256i s, __mmask32 m, __m256i a, __m256i b)
VPADDSW__m256i _mm256_mask_adds_epi16 (__m256i s, __mmask16 m, __m256i a, __m256i b)
VPADDSB__m256i _mm256_maskz_adds_epi8 (__mmask32 m, __m256i a, __m256i b)
VPADDSW__m256i _mm256_maskz_adds_epi16 (__mmask16 m, __m256i a, __m256i b)
VPADDSB__m128i _mm_mask_adds_epi8 (__m128i s, __mmask16 m, __m128i a, __m128i b)
VPADDSW__m128i _mm_mask_adds_epi16 (__m128i s, __mmask8 m, __m128i a, __m128i b)
VPADDSB__m128i _mm_maskz_adds_epi8 (__mmask16 m, __m128i a, __m128i b)
VPADDSW__m128i _mm_maskz_adds_epi16 (__mmask8 m, __m128i a, __m128i b)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.nb.

