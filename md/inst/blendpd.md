----------------------------
title : BLENDPD (Intel x86/64 assembly instruction)
cat_title : BLENDPD
ref_title : BLENDPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BLENDPD

** Blend Packed Double Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A 0D /r ib`\newline{}`BLENDPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE4_1|Select packed DP-FP values from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.|
|`VEX.NDS.128.66.0F3A.WIG 0D /r ib`\newline{}VBLENDPD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Select packed double-precision floating-point Values from xmm2 and xmm3/m128 from mask in imm8 and store the values in xmm1.|
|`VEX.NDS.256.66.0F3A.WIG 0D /r ib`\newline{}VBLENDPD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Select packed double-precision floating-point Values from ymm2 and ymm3/m256 from mask in imm8 and store the values in ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8[3:0]|
### Description


Double-precision floating-point values from the second source operand (third operand) are conditionally merged with values from the first source operand (second operand) and written to the destination operand (first operand). The immediate bits [3:0] determine whether the corresponding double-precision floating-point value in the desti-nation is copied from the second source or first source. If a bit in the mask, corresponding to a word, is "1", then the double-precision floating-point value in the second source operand is copied, else the value in the first source operand is copied.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register. The second source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### BLENDPD (128-bit Legacy SSE version)
```info-verb
IF (IMM8[0] = 0)THEN DEST[63:0] <-  DEST[63:0]
          ELSE DEST [63:0] <-  SRC[63:0] FI
IF (IMM8[1] = 0) THEN DEST[127:64] <-  DEST[127:64]
          ELSE DEST [127:64] <-  SRC[127:64] FI
DEST[VLMAX-1:128] (Unmodified)
```
#### VBLENDPD (VEX.128 encoded version)
```info-verb
IF (IMM8[0] = 0)THEN DEST[63:0] <-  SRC1[63:0]
          ELSE DEST [63:0] <-  SRC2[63:0] FI
IF (IMM8[1] = 0) THEN DEST[127:64] <-  SRC1[127:64]
          ELSE DEST [127:64] <-  SRC2[127:64] FI
DEST[VLMAX-1:128] <-  0
```
#### VBLENDPD (VEX.256 encoded version)
```info-verb
IF (IMM8[0] = 0)THEN DEST[63:0] <-  SRC1[63:0]
          ELSE DEST [63:0] <-  SRC2[63:0] FI
IF (IMM8[1] = 0) THEN DEST[127:64] <-  SRC1[127:64]
          ELSE DEST [127:64] <-  SRC2[127:64] FI
IF (IMM8[2] = 0) THEN DEST[191:128] <-  SRC1[191:128]
          ELSE DEST [191:128] <-  SRC2[191:128] FI
IF (IMM8[3] = 0) THEN DEST[255:192] <-  SRC1[255:192]
          ELSE DEST [255:192] <-  SRC2[255:192] FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BLENDPD: __m128d _mm_blend_pd (__m128d v1, __m128d v2, const int mask);
VBLENDPD: __m256d _mm256_blend_pd (__m256d a, __m256d b, const int mask);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

