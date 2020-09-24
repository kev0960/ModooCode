----------------------------
title : PBLENDW (Intel x86/64 assembly instruction)
cat_title : PBLENDW
ref_title : PBLENDW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PBLENDW

** Blend Packed Words**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A 0E /r ib`\newline{}`PBLENDW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE4_1|Select words from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.|
|`VEX.NDS.128.66.0F3A.WIG 0E /r ib`\newline{}VPBLENDW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Select words from xmm2 and xmm3/m128 from mask specified in imm8 and store the values into xmm1.|
|`VEX.NDS.256.66.0F3A.WIG 0E /r ib`\newline{}VPBLENDW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX2|Select words from ymm2 and ymm3/m256 from mask specified in imm8 and store the values into ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
### Description


Words from the source operand (second operand) are conditionally written to the destination operand (first operand) depending on bits in the immediate operand (third operand). The immediate bits (bits 7:0) form a mask that determines whether the corresponding word in the destination is copied from the source. If a bit in the mask, corresponding to a word, is "1", then the word is copied, else the word element in the destination operand is unchanged.

128-bit Legacy SSE version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### PBLENDW (128-bit Legacy SSE version)
```info-verb
IF (imm8[0] = 1) THEN DEST[15:0] <-  SRC[15:0]
ELSE DEST[15:0] <-  DEST[15:0]
IF (imm8[1] = 1) THEN DEST[31:16] <-  SRC[31:16]
ELSE DEST[31:16] <-  DEST[31:16]
IF (imm8[2] = 1) THEN DEST[47:32] <-  SRC[47:32]
ELSE DEST[47:32] <-  DEST[47:32]
IF (imm8[3] = 1) THEN DEST[63:48] <-  SRC[63:48]
ELSE DEST[63:48] <-  DEST[63:48]
IF (imm8[4] = 1) THEN DEST[79:64] <-  SRC[79:64]
ELSE DEST[79:64] <-  DEST[79:64]
IF (imm8[5] = 1) THEN DEST[95:80] <-  SRC[95:80]
ELSE DEST[95:80] <-  DEST[95:80]
IF (imm8[6] = 1) THEN DEST[111:96] <-  SRC[111:96]
ELSE DEST[111:96] <-  DEST[111:96]
IF (imm8[7] = 1) THEN DEST[127:112] <-  SRC[127:112]
ELSE DEST[127:112] <-  DEST[127:112]
```
#### VPBLENDW (VEX.128 encoded version)
```info-verb
IF (imm8[0] = 1) THEN DEST[15:0] <-  SRC2[15:0]
ELSE DEST[15:0] <-  SRC1[15:0]
IF (imm8[1] = 1) THEN DEST[31:16] <-  SRC2[31:16]
ELSE DEST[31:16] <-  SRC1[31:16]
IF (imm8[2] = 1) THEN DEST[47:32] <-  SRC2[47:32]
ELSE DEST[47:32] <-  SRC1[47:32]
IF (imm8[3] = 1) THEN DEST[63:48] <-  SRC2[63:48]
ELSE DEST[63:48] <-  SRC1[63:48]
IF (imm8[4] = 1) THEN DEST[79:64] <-  SRC2[79:64]
ELSE DEST[79:64] <-  SRC1[79:64]
IF (imm8[5] = 1) THEN DEST[95:80] <-  SRC2[95:80]
ELSE DEST[95:80] <-  SRC1[95:80]
IF (imm8[6] = 1) THEN DEST[111:96] <-  SRC2[111:96]
ELSE DEST[111:96] <-  SRC1[111:96]
IF (imm8[7] = 1) THEN DEST[127:112] <-  SRC2[127:112]
ELSE DEST[127:112] <-  SRC1[127:112]
DEST[VLMAX-1:128] <-  0
```
#### VPBLENDW (VEX.256 encoded version)
```info-verb
IF (imm8[0] == 1) THEN DEST[15:0] <-  SRC2[15:0]
ELSE DEST[15:0] <-  SRC1[15:0]
IF (imm8[1] == 1) THEN DEST[31:16] <-  SRC2[31:16]
ELSE DEST[31:16] <-  SRC1[31:16]
IF (imm8[2] == 1) THEN DEST[47:32] <-  SRC2[47:32]
ELSE DEST[47:32] <-  SRC1[47:32]
IF (imm8[3] == 1) THEN DEST[63:48] <-  SRC2[63:48]
ELSE DEST[63:48] <-  SRC1[63:48]
IF (imm8[4] == 1) THEN DEST[79:64] <-  SRC2[79:64]
ELSE DEST[79:64] <-  SRC1[79:64]
IF (imm8[5] == 1) THEN DEST[95:80] <-  SRC2[95:80]
ELSE DEST[95:80] <-  SRC1[95:80]
IF (imm8[6] == 1) THEN DEST[111:96] <-  SRC2[111:96]
ELSE DEST[111:96] <-  SRC1[111:96]
IF (imm8[7] == 1) THEN DEST[127:112] <-  SRC2[127:112]
ELSE DEST[127:112] <-  SRC1[127:112]
IF (imm8[0] == 1) THEN DEST[143:128] <-  SRC2[143:128]
ELSE DEST[143:128] <-  SRC1[143:128]
IF (imm8[1] == 1) THEN DEST[159:144] <-  SRC2[159:144]
ELSE DEST[159:144] <-  SRC1[159:144]
IF (imm8[2] == 1) THEN DEST[175:160] <-  SRC2[175:160]
ELSE DEST[175:160] <-  SRC1[175:160]
IF (imm8[3] == 1) THEN DEST[191:176] <-  SRC2[191:176]
ELSE DEST[191:176] <-  SRC1[191:176]
IF (imm8[4] == 1) THEN DEST[207:192] <-  SRC2[207:192]
ELSE DEST[207:192] <-  SRC1[207:192]
IF (imm8[5] == 1) THEN DEST[223:208] <-  SRC2[223:208]
ELSE DEST[223:208] <-  SRC1[223:208]
IF (imm8[6] == 1) THEN DEST[239:224] <-  SRC2[239:224]
ELSE DEST[239:224] <-  SRC1[239:224]
IF (imm8[7] == 1) THEN DEST[255:240] <-  SRC2[255:240]
ELSE DEST[255:240] <-  SRC1[255:240]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
(V)PBLENDW:  __m128i _mm_blend_epi16 (__m128i v1, __m128i v2, const int mask);
VPBLENDW: __m256i _mm256_blend_epi16 (__m256i v1, __m256i v2, const int mask)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1 and AVX2 = 0.

