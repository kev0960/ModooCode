----------------------------
title : PHADDSW (Intel x86/64 assembly instruction)
cat_title : PHADDSW
ref_title : PHADDSW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PHADDSW

** Packed Horizontal Add and Saturate**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 03 /r\footnote{1}  `\newline{}`PHADDSW` mm1 mm2/m64 |RM|V/V|SSSE3|Add 16-bit signed integers horizontally, pack saturated integers to mm1.|
|`66 0F 38 03 /r`\newline{}`PHADDSW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Add 16-bit signed integers horizontally, pack saturated integers to xmm1.|
|`VEX.NDS.128.66.0F38.WIG 03 /r`\newline{}VPHADDSW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Add 16-bit signed integers horizontally, pack saturated integers to xmm1.|
|`VEX.NDS.256.66.0F38.WIG 03 /r`\newline{}VPHADDSW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Add 16-bit signed integers horizontally, pack saturated integers to ymm1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


(V)PHADDSW adds two adjacent signed 16-bit integers horizontally from the source and destination operands and saturates the signed results; packs the signed, saturated 16-bit results to the destination operand (first operand) When the source operand is a 128-bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

Legacy SSE version: Both operands can be MMX registers. The second source operand can be an MMX register or a 64-bit memory location.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged. 

In 64-bit mode, use the REX prefix to access additional registers.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The first source and destination operands are YMM registers. The second source operand can be an YMM register or a 256-bit memory location.

Note: VEX.L must be 0, otherwise the instruction will #UD.

### Operation 


**PHADDSW (with 64-bit operands)**

    mm1[15-0]  = SaturateToSignedWord((mm1[31-16] + mm1[15-0]); 

    mm1[31-16] = SaturateToSignedWord(mm1[63-48] + mm1[47-32]);

    mm1[47-32] = SaturateToSignedWord(mm2/m64[31-16] + mm2/m64[15-0]); 

    mm1[63-48] = SaturateToSignedWord(mm2/m64[63-48] + mm2/m64[47-32]); 



**PHADDSW (with 128-bit operands)**

    xmm1[15-0]= SaturateToSignedWord(xmm1[31-16] + xmm1[15-0]);

    xmm1[31-16] = SaturateToSignedWord(xmm1[63-48] + xmm1[47-32]);

    xmm1[47-32] = SaturateToSignedWord(xmm1[95-80] + xmm1[79-64]);

    xmm1[63-48] = SaturateToSignedWord(xmm1[127-112] + xmm1[111-96]); 

    xmm1[79-64] = SaturateToSignedWord(xmm2/m128[31-16] + xmm2/m128[15-0]);

    xmm1[95-80] = SaturateToSignedWord(xmm2/m128[63-48] + xmm2/m128[47-32]);

    xmm1[111-96] = SaturateToSignedWord(xmm2/m128[95-80] + xmm2/m128[79-64]);

    xmm1[127-112] = SaturateToSignedWord(xmm2/m128[127-112] + xmm2/m128[111-96]); 

**VPHADDSW (VEX.128 encoded version)**

DEST[15:0]= SaturateToSignedWord(SRC1[31:16] + SRC1[15:0])

DEST[31:16] = SaturateToSignedWord(SRC1[63:48] + SRC1[47:32])

DEST[47:32] = SaturateToSignedWord(SRC1[95:80] + SRC1[79:64])

DEST[63:48] = SaturateToSignedWord(SRC1[127:112] + SRC1[111:96])

DEST[79:64] = SaturateToSignedWord(SRC2[31:16] + SRC2[15:0])

DEST[95:80] = SaturateToSignedWord(SRC2[63:48] + SRC2[47:32])

DEST[111:96] = SaturateToSignedWord(SRC2[95:80] + SRC2[79:64])

DEST[127:112] = SaturateToSignedWord(SRC2[127:112] + SRC2[111:96])

DEST[VLMAX-1:128] <-  0

**VPHADDSW (VEX.256 encoded version)**

DEST[15:0]= SaturateToSignedWord(SRC1[31:16] + SRC1[15:0])

DEST[31:16] = SaturateToSignedWord(SRC1[63:48] + SRC1[47:32])

DEST[47:32] = SaturateToSignedWord(SRC1[95:80] + SRC1[79:64])

DEST[63:48] = SaturateToSignedWord(SRC1[127:112] + SRC1[111:96])

DEST[79:64] = SaturateToSignedWord(SRC2[31:16] + SRC2[15:0])

DEST[95:80] = SaturateToSignedWord(SRC2[63:48] + SRC2[47:32])

DEST[111:96] = SaturateToSignedWord(SRC2[95:80] + SRC2[79:64])

DEST[127:112] = SaturateToSignedWord(SRC2[127:112] + SRC2[111:96])

DEST[143:128]= SaturateToSignedWord(SRC1[159:144] + SRC1[143:128])

DEST[159:144] = SaturateToSignedWord(SRC1[191:176] + SRC1[175:160])

DEST[175:160] = SaturateToSignedWord( SRC1[223:208] + SRC1[207:192])

DEST[191:176] = SaturateToSignedWord(SRC1[255:240] + SRC1[239:224])

DEST[207:192] = SaturateToSignedWord(SRC2[127:112] + SRC2[143:128])

DEST[223:208] = SaturateToSignedWord(SRC2[159:144] + SRC2[175:160])

DEST[239:224] = SaturateToSignedWord(SRC2[191-160] + SRC2[159-128])

DEST[255:240] = SaturateToSignedWord(SRC2[255:240] + SRC2[239:224])


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PHADDSW:  __m64 _mm_hadds_pi16 (__m64 a, __m64 b)
(V)PHADDSW:  __m128i _mm_hadds_epi16 (__m128i a, __m128i b)
VPHADDSW: __m256i _mm256_hadds_epi16 (__m256i a, __m256i b)
```
### SIMD Floating-Point Exceptions 


None. 

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1.

