----------------------------
title : PMULHRSW (Intel x86/64 assembly instruction)
cat_title : PMULHRSW
ref_title : PMULHRSW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PMULHRSW

** Packed Multiply High with Round and Scale **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 0B /r\footnote{1}  `\newline{}`PMULHRSW` mm1 mm2/m64 |RM|V/V|SSSE3|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to mm1.|
|`66 0F 38 0B /r`\newline{}`PMULHRSW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to xmm1.|
|`VEX.NDS.128.66.0F38.WIG 0B /r`\newline{}VPMULHRSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to xmm1.|
|`VEX.NDS.256.66.0F38.WIG 0B /r`\newline{}VPMULHRSW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to ymm1.|
|`EVEX.NDS.128.66.0F38.WIG 0B /r`\newline{}VPMULHRSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to xmm1 under writemask k1.|
|`EVEX.NDS.256.66.0F38.WIG 0B /r`\newline{}VPMULHRSW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F38.WIG 0B /r`\newline{}VPMULHRSW zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to zmm1 under writemask k1.|

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


PMULHRSW multiplies vertically each signed 16-bit integer from the destination operand (first operand) with the corresponding signed 16-bit integer of the source operand (second operand), producing intermediate, signed 32-bit integers. Each intermediate 32-bit integer is truncated to the 18 most significant bits. Rounding is always performed by adding 1 to the least significant bit of the 18-bit intermediate result. The final result is obtained by selecting the 16 bits immediately to the right of the most significant bit of each 18-bit intermediate result and packed to the destination operand. 

When the source operand is a 128-bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

In 64-bit mode and not encoded with VEX/EVEX, use the REX prefix to access XMM8-XMM15 registers. 

Legacy SSE version 64-bit operand: Both operands can be MMX registers. The second source operand is an MMX register or a 64-bit memory location.



128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.


### Operation
#### PMULHRSW (with 64-bit operands)
```info-verb
    temp0[31:0] = INT32 ((DEST[15:0] * SRC[15:0]) >>14) + 1;
    temp1[31:0] = INT32 ((DEST[31:16] * SRC[31:16]) >>14) + 1;
    temp2[31:0] = INT32 ((DEST[47:32] * SRC[47:32]) >> 14) + 1;
    temp3[31:0] = INT32 ((DEST[63:48] * SRc[63:48]) >> 14) + 1;
    DEST[15:0] = temp0[16:1];
    DEST[31:16] = temp1[16:1];
    DEST[47:32] = temp2[16:1];
    DEST[63:48] = temp3[16:1];
```
#### PMULHRSW (with 128-bit operand)
```info-verb
    temp0[31:0] = INT32 ((DEST[15:0] * SRC[15:0]) >>14) + 1;
    temp1[31:0] = INT32 ((DEST[31:16] * SRC[31:16]) >>14) + 1;
    temp2[31:0] = INT32 ((DEST[47:32] * SRC[47:32]) >>14) + 1;
    temp3[31:0] = INT32 ((DEST[63:48] * SRC[63:48]) >>14) + 1;
    temp4[31:0] = INT32 ((DEST[79:64] * SRC[79:64]) >>14) + 1;
    temp5[31:0] = INT32 ((DEST[95:80] * SRC[95:80]) >>14) + 1;
    temp6[31:0] = INT32 ((DEST[111:96] * SRC[111:96]) >>14) + 1;
    temp7[31:0] = INT32 ((DEST[127:112] * SRC[127:112) >>14) + 1;
    DEST[15:0] = temp0[16:1];
    DEST[31:16] = temp1[16:1];
    DEST[47:32] = temp2[16:1];
    DEST[63:48] = temp3[16:1];
    DEST[79:64] = temp4[16:1];
    DEST[95:80] = temp5[16:1];
    DEST[111:96] = temp6[16:1];
    DEST[127:112] = temp7[16:1];
```
#### VPMULHRSW (VEX.128 encoded version)
```info-verb
temp0[31:0] <-  INT32 ((SRC1[15:0] * SRC2[15:0]) >>14) + 1
temp1[31:0] <-  INT32 ((SRC1[31:16] * SRC2[31:16]) >>14) + 1
temp2[31:0] <-  INT32 ((SRC1[47:32] * SRC2[47:32]) >>14) + 1
temp3[31:0] <-  INT32 ((SRC1[63:48] * SRC2[63:48]) >>14) + 1
temp4[31:0] <-  INT32 ((SRC1[79:64] * SRC2[79:64]) >>14) + 1
temp5[31:0] <-  INT32 ((SRC1[95:80] * SRC2[95:80]) >>14) + 1
temp6[31:0] <-  INT32 ((SRC1[111:96] * SRC2[111:96]) >>14) + 1
temp7[31:0] <-  INT32 ((SRC1[127:112] * SRC2[127:112) >>14) + 1
DEST[15:0] <-  temp0[16:1]
DEST[31:16] <-  temp1[16:1]
DEST[47:32] <-  temp2[16:1]
DEST[63:48] <-  temp3[16:1]
DEST[79:64] <-  temp4[16:1]
DEST[95:80] <-  temp5[16:1]
DEST[111:96] <-  temp6[16:1]
DEST[127:112] <-  temp7[16:1]
DEST[VLMAX-1:128] <-  0
```
#### VPMULHRSW (VEX.256 encoded version)
```info-verb
temp0[31:0] <-  INT32 ((SRC1[15:0] * SRC2[15:0]) >>14) + 1
temp1[31:0] <-  INT32 ((SRC1[31:16] * SRC2[31:16]) >>14) + 1
temp2[31:0] <-  INT32 ((SRC1[47:32] * SRC2[47:32]) >>14) + 1
temp3[31:0] <-  INT32 ((SRC1[63:48] * SRC2[63:48]) >>14) + 1
temp4[31:0] <-  INT32 ((SRC1[79:64] * SRC2[79:64]) >>14) + 1
temp5[31:0] <-  INT32 ((SRC1[95:80] * SRC2[95:80]) >>14) + 1
temp6[31:0] <-  INT32 ((SRC1[111:96] * SRC2[111:96]) >>14) + 1
temp7[31:0] <-  INT32 ((SRC1[127:112] * SRC2[127:112) >>14) + 1
temp8[31:0] <-  INT32 ((SRC1[143:128] * SRC2[143:128]) >>14) + 1
temp9[31:0] <-  INT32 ((SRC1[159:144] * SRC2[159:144]) >>14) + 1
temp10[31:0] <-  INT32 ((SRC1[75:160] * SRC2[175:160]) >>14) + 1
temp11[31:0] <-  INT32 ((SRC1[191:176] * SRC2[191:176]) >>14) + 1
temp12[31:0] <-  INT32 ((SRC1[207:192] * SRC2[207:192]) >>14) + 1
temp13[31:0] <-  INT32 ((SRC1[223:208] * SRC2[223:208]) >>14) + 1
temp14[31:0] <-  INT32 ((SRC1[239:224] * SRC2[239:224]) >>14) + 1
temp15[31:0] <-  INT32 ((SRC1[255:240] * SRC2[255:240) >>14) + 1
DEST[15:0] <-  temp0[16:1]
DEST[31:16] <-  temp1[16:1]
DEST[47:32] <-  temp2[16:1]
DEST[63:48] <-  temp3[16:1]
DEST[79:64] <-  temp4[16:1]
DEST[95:80] <-  temp5[16:1]
DEST[111:96] <-  temp6[16:1]
DEST[127:112] <-  temp7[16:1]
DEST[143:128] <-  temp8[16:1]
DEST[159:144] <-  temp9[16:1]
DEST[175:160] <-  temp10[16:1]
DEST[191:176] <-  temp11[16:1]
DEST[207:192] <-  temp12[16:1]
DEST[223:208] <-  temp13[16:1]
DEST[239:224] <-  temp14[16:1]
DEST[255:240] <-  temp15[16:1]
DEST[MAX_VL-1:256] <-  0
```
#### VPMULHRSW (EVEX encoded version)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN 
                temp[31:0] <-  ((SRC1[i+15:i] * SRC2[i+15:i]) >>14) + 1
                DEST[i+15:i] <-  tmp[16:1]
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

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPMULHRSW __m512i _mm512_mulhrs_epi16(__m512i a, __m512i b);
VPMULHRSW __m512i _mm512_mask_mulhrs_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPMULHRSW __m512i _mm512_maskz_mulhrs_epi16( __mmask32 k, __m512i a, __m512i b);
VPMULHRSW __m256i _mm256_mask_mulhrs_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMULHRSW __m256i _mm256_maskz_mulhrs_epi16( __mmask16 k, __m256i a, __m256i b);
VPMULHRSW __m128i _mm_mask_mulhrs_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMULHRSW __m128i _mm_maskz_mulhrs_epi16( __mmask8 k, __m128i a, __m128i b);
PMULHRSW: __m64 _mm_mulhrs_pi16 (__m64 a, __m64 b)
(V)PMULHRSW: __m128i _mm_mulhrs_epi16 (__m128i a, __m128i b)
VPMULHRSW:__m256i _mm256_mulhrs_epi16 (__m256i a, __m256i b)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.nb.

