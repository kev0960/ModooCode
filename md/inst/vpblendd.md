----------------------------
title : VPBLENDD (Intel x86/64 assembly instruction)
cat_title : VPBLENDD
ref_title : VPBLENDD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPBLENDD

** Blend Packed Dwords**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.128.66.0F3A.W0 02 /r ib`\newline{}`VPBLENDD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX2|Select dwords from xmm2 and xmm3/m128 from mask specified in imm8 and store the values into xmm1.|
|`VEX.NDS.256.66.0F3A.W0 02 /r ib`\newline{}`VPBLENDD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX2|Select dwords from ymm2 and ymm3/m256 from mask specified in imm8 and store the values into ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Dword elements from the source operand (second operand) are conditionally written to the destination operand (first operand) depending on bits in the immediate operand (third operand). The immediate bits (bits 7:0) form a mask that determines whether the corresponding word in the destination is copied from the source. If a bit in the mask, corresponding to a word, is "1", then the word is copied, else the word is unchanged.

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### VPBLENDD (VEX.256 encoded version)
```info-verb
IF (imm8[0] == 1) THEN DEST[31:0] <-  SRC2[31:0]
ELSE DEST[31:0] <-  SRC1[31:0]
IF (imm8[1] == 1) THEN DEST[63:32] <-  SRC2[63:32]
ELSE DEST[63:32] <-  SRC1[63:32]
IF (imm8[2] == 1) THEN DEST[95:64] <-  SRC2[95:64]
ELSE DEST[95:64] <-  SRC1[95:64]
IF (imm8[3] == 1) THEN DEST[127:96] <-  SRC2[127:96]
ELSE DEST[127:96] <-  SRC1[127:96]
IF (imm8[4] == 1) THEN DEST[159:128] <-  SRC2[159:128]
ELSE DEST[159:128] <-  SRC1[159:128]
IF (imm8[5] == 1) THEN DEST[191:160] <-  SRC2[191:160]
ELSE DEST[191:160] <-  SRC1[191:160]
IF (imm8[6] == 1) THEN DEST[223:192] <-  SRC2[223:192]
ELSE DEST[223:192] <-  SRC1[223:192]
IF (imm8[7] == 1) THEN DEST[255:224] <-  SRC2[255:224]
ELSE DEST[255:224] <-  SRC1[255:224]
```
#### VPBLENDD (VEX.128 encoded version)
```info-verb
IF (imm8[0] == 1) THEN DEST[31:0] <-  SRC2[31:0]
ELSE DEST[31:0] <-  SRC1[31:0]
IF (imm8[1] == 1) THEN DEST[63:32] <-  SRC2[63:32]
ELSE DEST[63:32] <-  SRC1[63:32]
IF (imm8[2] == 1) THEN DEST[95:64] <-  SRC2[95:64]
ELSE DEST[95:64] <-  SRC1[95:64]
IF (imm8[3] == 1) THEN DEST[127:96] <-  SRC2[127:96]
ELSE DEST[127:96] <-  SRC1[127:96]
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPBLENDD: __m128i _mm_blend_epi32 (__m128i v1, __m128i v2, const int mask)
VPBLENDD: __m256i _mm256_blend_epi32 (__m256i v1, __m256i v2, const int mask)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.W = 1.

