----------------------------
title : PMULHW (Intel x86/64 assembly instruction)
cat_title : PMULHW
ref_title : PMULHW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PMULHW

**Multiply Packed Signed Integers and Store High Result**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F E5 /r\footnote{1}`\newline{}`PMULHW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Multiply the packed signed word integers in mm1 register and mm2/m64, and store the high 16 bits of the results in mm1. |
|`66 0F E5 /r`\newline{}`PMULHW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Multiply the packed signed word integers in xmm1 and xmm2/m128, and store the high 16 bits of the results in xmm1. |
|`VEX.NDS.128.66.0F.WIG E5 /r`\newline{}VPMULHW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Multiply the packed signed word integers in xmm2 and xmm3/m128, and store the high 16 bits of the results in xmm1.|
|`VEX.NDS.256.66.0F.WIG E5 /r`\newline{}VPMULHW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Multiply the packed signed word integers in ymm2 and ymm3/m256, and store the high 16 bits of the results in ymm1.|
|`EVEX.NDS.128.66.0F.WIG E5 /r`\newline{}VPMULHW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed signed word integers in xmm2 and xmm3/m128, and store the high 16 bits of the results in xmm1 under writemask k1.|
|`EVEX.NDS.256.66.0F.WIG E5 /r`\newline{}VPMULHW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed signed word integers in ymm2 and ymm3/m256, and store the high 16 bits of the results in ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F.WIG E5 /r`\newline{}VPMULHW zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Multiply the packed signed word integers in zmm2 and zmm3/m512, and store the high 16 bits of the results in zmm1 under writemask k1.|

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


Performs a SIMD signed multiply of the packed signed word integers in the destination operand (first operand) and the source operand (second operand), and stores the high 16 bits of each intermediate 32-bit result in the destina-tion operand. (Figure 4-12 shows this operation when using 64-bit operands.) 

n 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version 64-bit operand: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an MMX technology register.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.L must be 0, otherwise the instruction will #UD.



VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.


### Operation
#### PMULHW (with 64-bit operands)
```info-verb
    TEMP0[31:0] <-  DEST[15:0] `*` SRC[15:0]; (* Signed multiplication *)
    TEMP1[31:0] <-  DEST[31:16] `*` SRC[31:16];
    TEMP2[31:0] <-  DEST[47:32] `*` SRC[47:32];
    TEMP3[31:0] <- DEST[63:48] `*` SRC[63:48];
    DEST[15:0] <-  TEMP0[31:16];
    DEST[31:16] <-  TEMP1[31:16];
    DEST[47:32] <-  TEMP2[31:16];
    DEST[63:48] <-  TEMP3[31:16];
```
#### PMULHW (with 128-bit operands)
```info-verb
    TEMP0[31:0] <-  DEST[15:0] `*` SRC[15:0]; (* Signed multiplication *)
    TEMP1[31:0] <- DEST[31:16] `*` SRC[31:16];
    TEMP2[31:0] <-  DEST[47:32] `*` SRC[47:32];
    TEMP3[31:0] <- DEST[63:48] `*` SRC[63:48];
    TEMP4[31:0] <- DEST[79:64] `*` SRC[79:64];
    TEMP5[31:0] <-  DEST[95:80] `*` SRC[95:80];
    TEMP6[31:0] <-  DEST[111:96] `*` SRC[111:96];
    TEMP7[31:0] <- DEST[127:112] `*` SRC[127:112];
    DEST[15:0] <-  TEMP0[31:16];
    DEST[31:16] <-  TEMP1[31:16];
    DEST[47:32] <-  TEMP2[31:16];
    DEST[63:48] <-  TEMP3[31:16];
    DEST[79:64] <-  TEMP4[31:16];
    DEST[95:80] <-  TEMP5[31:16];
    DEST[111:96] <-  TEMP6[31:16];
    DEST[127:112] <- TEMP7[31:16];
```
#### VPMULHW (VEX.128 encoded version)
```info-verb
TEMP0[31:0] <-  SRC1[15:0] * SRC2[15:0] (*Signed Multiplication*)
TEMP1[31:0] <-  SRC1[31:16] * SRC2[31:16]
TEMP2[31:0] <-  SRC1[47:32] * SRC2[47:32]
TEMP3[31:0] <-  SRC1[63:48] * SRC2[63:48]
TEMP4[31:0] <-  SRC1[79:64] * SRC2[79:64]
TEMP5[31:0] <-  SRC1[95:80] * SRC2[95:80]
TEMP6[31:0] <-  SRC1[111:96] * SRC2[111:96]
TEMP7[31:0] <-  SRC1[127:112] * SRC2[127:112]
DEST[15:0] <-  TEMP0[31:16]
DEST[31:16] <-  TEMP1[31:16]
DEST[47:32] <-  TEMP2[31:16]
DEST[63:48] <-  TEMP3[31:16]
DEST[79:64] <-  TEMP4[31:16]
DEST[95:80] <-  TEMP5[31:16]
DEST[111:96] <-  TEMP6[31:16]
DEST[127:112] <-  TEMP7[31:16]
DEST[VLMAX-1:128] <-  0
```
#### PMULHW (VEX.256 encoded version)
```info-verb
TEMP0[31:0] <-  SRC1[15:0] * SRC2[15:0] (*Signed Multiplication*)
TEMP1[31:0] <-  SRC1[31:16] * SRC2[31:16]
TEMP2[31:0] <-  SRC1[47:32] * SRC2[47:32]
TEMP3[31:0] <-  SRC1[63:48] * SRC2[63:48]
TEMP4[31:0] <-  SRC1[79:64] * SRC2[79:64]
TEMP5[31:0] <-  SRC1[95:80] * SRC2[95:80]
TEMP6[31:0] <-  SRC1[111:96] * SRC2[111:96]
TEMP7[31:0] <-  SRC1[127:112] * SRC2[127:112]
TEMP8[31:0] <-  SRC1[143:128] * SRC2[143:128]
TEMP9[31:0] <-  SRC1[159:144] * SRC2[159:144]
TEMP10[31:0] <-  SRC1[175:160] * SRC2[175:160]
TEMP11[31:0] <-  SRC1[191:176] * SRC2[191:176]
TEMP12[31:0] <-  SRC1[207:192] * SRC2[207:192]
TEMP13[31:0] <-  SRC1[223:208] * SRC2[223:208]
TEMP14[31:0] <-  SRC1[239:224] * SRC2[239:224]
TEMP15[31:0] <-  SRC1[255:240] * SRC2[255:240]
DEST[15:0] <-  TEMP0[31:16]
DEST[31:16] <-  TEMP1[31:16]
DEST[47:32] <-  TEMP2[31:16]
DEST[63:48] <-  TEMP3[31:16]
DEST[79:64] <-  TEMP4[31:16]
DEST[95:80] <-  TEMP5[31:16]
DEST[111:96] <-  TEMP6[31:16]
DEST[127:112] <-  TEMP7[31:16]
DEST[143:128] <-  TEMP8[31:16]
DEST[159:144] <-  TEMP9[31:16]
DEST[175:160] <-  TEMP10[31:16]
DEST[191:176] <-  TEMP11[31:16]
DEST[207:192] <-  TEMP12[31:16]
DEST[223:208] <-  TEMP13[31:16]
DEST[239:224] <-  TEMP14[31:16]
DEST[255:240] <-  TEMP15[31:16]
DEST[VLMAX-1:256] <-  0
```
#### PMULHW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN 
                temp[31:0] <-  SRC1[i+15:i] * SRC2[i+15:i]
                DEST[i+15:i] <-  tmp[31:16]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMULHW __m512i _mm512_mulhi_epi16(__m512i a, __m512i b);
VPMULHW __m512i _mm512_mask_mulhi_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPMULHW __m512i _mm512_maskz_mulhi_epi16( __mmask32 k, __m512i a, __m512i b);
VPMULHW __m256i _mm256_mask_mulhi_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMULHW __m256i _mm256_maskz_mulhi_epi16( __mmask16 k, __m256i a, __m256i b);
VPMULHW __m128i _mm_mask_mulhi_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMULHW __m128i _mm_maskz_mulhi_epi16( __mmask8 k, __m128i a, __m128i b);
PMULHW:__m64 _mm_mulhi_pi16 (__m64 m1, __m64 m2)
(V)PMULHW:__m128i _mm_mulhi_epi16 ( __m128i a, __m128i b)
VPMULHW:__m256i _mm256_mulhi_epi16 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.nb.

