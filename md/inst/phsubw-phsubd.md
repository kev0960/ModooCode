----------------------------
title : PHSUBW, PHSUBDs (Intel x86/64 assembly instruction)
cat_title : PHSUBW, PHSUBD
ref_title : PHSUBW, PHSUBD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PHSUBW, PHSUBD

** Packed Horizontal Subtract**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 05 /r\footnote{1}`\newline{}`PHSUBW` mm1 mm2/m64 |RM|V/V|SSSE3|Subtract 16-bit signed integers horizontally, pack to mm1. |
|`66 0F 38 05 /r `\newline{}`PHSUBW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Subtract 16-bit signed integers horizontally, pack to xmm1. |
|`0F 38 06 /r `\newline{}`PHSUBD` mm1 mm2/m64 |RM|V/V|SSSE3|Subtract 32-bit signed integers horizontally, pack to mm1. |
|`66 0F 38 06 /r`\newline{}`PHSUBD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Subtract 32-bit signed integers horizontally, pack to xmm1. |
|`VEX.NDS.128.66.0F38.WIG 05 /r`\newline{}VPHSUBW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract 16-bit signed integers horizontally, pack to xmm1.|
|`VEX.NDS.128.66.0F38.WIG 06 /r`\newline{}VPHSUBD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract 32-bit signed integers horizontally, pack to xmm1.|
|`VEX.NDS.256.66.0F38.WIG 05 /r`\newline{}VPHSUBW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Subtract 16-bit signed integers horizontally, pack to ymm1.|
|`VEX.NDS.256.66.0F38.WIG 06 /r`\newline{}VPHSUBD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Subtract 32-bit signed integers horizontally, pack to ymm1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (r, w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


(V)PHSUBW performs horizontal subtraction on each adjacent pair of 16-bit signed integers by subtracting the most significant word from the least significant word of each pair in the source and destination operands, and packs the signed 16-bit results to the destination operand (first operand). (V)PHSUBD performs horizontal subtraction on each adjacent pair of 32-bit signed integers by subtracting the most significant doubleword from the least signifi-cant doubleword of each pair, and packs the signed 32-bit result to the destination operand. When the source operand is a 128-bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

Legacy SSE version: Both operands can be MMX registers. The second source operand can be an MMX register or a 64-bit memory location.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.

In 64-bit mode, use the REX prefix to access additional registers.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 



VEX.256 encoded version: The first source and destination operands are YMM registers. The second source operand can be an YMM register or a 256-bit memory location.

Note: VEX.L must be 0, otherwise the instruction will #UD.


### Operation
#### PHSUBW (with 64-bit operands) 
```info-verb
    mm1[15-0] = mm1[15-0] - mm1[31-16]; 
    mm1[31-16] = mm1[47-32] - mm1[63-48]; 
    mm1[47-32] = mm2/m64[15-0] - mm2/m64[31-16];
    mm1[63-48] = mm2/m64[47-32] - mm2/m64[63-48]; 
```
#### PHSUBW (with 128-bit operands)
```info-verb
    xmm1[15-0] = xmm1[15-0] - xmm1[31-16]; 
    xmm1[31-16] = xmm1[47-32] - xmm1[63-48]; 
    xmm1[47-32] = xmm1[79-64] - xmm1[95-80]; 
    xmm1[63-48] = xmm1[111-96] - xmm1[127-112]; 
    xmm1[79-64] = xmm2/m128[15-0] - xmm2/m128[31-16]; 
    xmm1[95-80] = xmm2/m128[47-32] - xmm2/m128[63-48]; 
    xmm1[111-96] = xmm2/m128[79-64] - xmm2/m128[95-80]; 
    xmm1[127-112] = xmm2/m128[111-96] - xmm2/m128[127-112];
```
#### VPHSUBW (VEX.128 encoded version)
```info-verb
DEST[15:0] <-  SRC1[15:0] - SRC1[31:16]
DEST[31:16] <-  SRC1[47:32] - SRC1[63:48]
DEST[47:32] <-  SRC1[79:64] - SRC1[95:80]
DEST[63:48] <-  SRC1[111:96] - SRC1[127:112]
DEST[79:64] <-  SRC2[15:0] - SRC2[31:16]
DEST[95:80] <-  SRC2[47:32] - SRC2[63:48]
DEST[111:96] <-  SRC2[79:64] - SRC2[95:80]
DEST[127:112] <-  SRC2[111:96] - SRC2[127:112]
DEST[VLMAX-1:128] <-  0
```
#### VPHSUBW (VEX.256 encoded version)
```info-verb
DEST[15:0] <-  SRC1[15:0] - SRC1[31:16]
DEST[31:16] <-  SRC1[47:32] - SRC1[63:48]
DEST[47:32] <-  SRC1[79:64] - SRC1[95:80]
DEST[63:48] <-  SRC1[111:96] - SRC1[127:112]
DEST[79:64] <-  SRC2[15:0] - SRC2[31:16]
DEST[95:80] <-  SRC2[47:32] - SRC2[63:48]
DEST[111:96] <-  SRC2[79:64] - SRC2[95:80]
DEST[127:112] <-  SRC2[111:96] - SRC2[127:112]
DEST[143:128] <-  SRC1[143:128] - SRC1[159:144]
DEST[159:144] <-  SRC1[175:160] - SRC1[191:176]
DEST[175:160] <-  SRC1[207:192] - SRC1[223:208]
DEST[191:176] <-  SRC1[239:224] - SRC1[255:240]
DEST[207:192] <-  SRC2[143:128] - SRC2[159:144]
DEST[223:208] <-  SRC2[175:160] - SRC2[191:176]
DEST[239:224] <-  SRC2[207:192] - SRC2[223:208]
DEST[255:240] <-  SRC2[239:224] - SRC2[255:240]
```
#### PHSUBD (with 64-bit operands)
```info-verb
    mm1[31-0] = mm1[31-0] - mm1[63-32];
    mm1[63-32] = mm2/m64[31-0] - mm2/m64[63-32];
```
#### PHSUBD (with 128-bit operands)
```info-verb
    xmm1[31-0] = xmm1[31-0] - xmm1[63-32]; 
    xmm1[63-32] = xmm1[95-64] - xmm1[127-96]; 
    xmm1[95-64] = xmm2/m128[31-0] - xmm2/m128[63-32]; 
    xmm1[127-96] = xmm2/m128[95-64] - xmm2/m128[127-96]; 
```
#### VPHSUBD (VEX.128 encoded version)
```info-verb
DEST[31-0] <-  SRC1[31-0] - SRC1[63-32]
DEST[63-32] <-  SRC1[95-64] - SRC1[127-96]
DEST[95-64] <-  SRC2[31-0] - SRC2[63-32]
DEST[127-96] <-  SRC2[95-64] - SRC2[127-96]
DEST[VLMAX-1:128] <-  0
```
#### VPHSUBD (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC1[63:32]
DEST[63:32] <-  SRC1[95:64] - SRC1[127:96]
DEST[95:64] <-  SRC2[31:0] - SRC2[63:32]
DEST[127:96] <-  SRC2[95:64] - SRC2[127:96]
DEST[159:128] <-  SRC1[159:128] - SRC1[191:160]
DEST[191:160] <-  SRC1[223:192] - SRC1[255:224]
DEST[223:192] <-  SRC2[159:128] - SRC2[191:160]
DEST[255:224] <-  SRC2[223:192] - SRC2[255:224]
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
PHSUBW:  __m64 _mm_hsub_pi16 (__m64 a, __m64 b)
PHSUBD:  __m64 _mm_hsub_pi32 (__m64 a, __m64 b)
(V)PHSUBW:  __m128i _mm_hsub_epi16 (__m128i a, __m128i b)
(V)PHSUBD:  __m128i _mm_hsub_epi32 (__m128i a, __m128i b)
VPHSUBW: __m256i _mm256_hsub_epi16 (__m256i a, __m256i b)
VPHSUBD: __m256i _mm256_hsub_epi32 (__m256i a, __m256i b)
```
### SIMD Floating-Point Exceptions 


None. 

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1.

