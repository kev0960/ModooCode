----------------------------
title : PSLLDQ (Intel x86/64 assembly instruction)
cat_title : PSLLDQ
ref_title : PSLLDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSLLDQ

**Shift Double Quadword Left Logical**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`66 0F 73 /7 ib`\newline{}`PSLLDQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|SSE2|Shift xmm1 left by imm8 bytes while shifting in 0s.|
|`VEX.NDD.128.66.0F.WIG 73 /7 ib`\newline{}VPSLLDQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |VMI|V/V|AVX|Shift xmm2 left by imm8 bytes while shifting in 0s and store result in xmm1.|
|`VEX.NDD.256.66.0F.WIG 73 /7 ib`\newline{}VPSLLDQ \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |VMI|V/V|AVX2|Shift ymm2 left by imm8 bytes while shifting in 0s and store result in ymm1.|
|`EVEX.NDD.128.66.0F.WIG 73 /7 ib`\newline{}VPSLLDQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm2/ \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVMI|V/V|AVX512VL\newline{}AVX512BW|Shift xmm2/m128 left by imm8 bytes while shifting in 0s and store result in xmm1.|
|`EVEX.NDD.256.66.0F.WIG 73 /7 ib`\newline{}VPSLLDQ \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVMI|V/V|AVX512VL\newline{}AVX512BW|Shift ymm2/m256 left by imm8 bytes while shifting in 0s and store result in ymm1.|
|`EVEX.NDD.512.66.0F.WIG 73 /7 ib`\newline{}VPSLLDQ zmm1 \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVMI|V/V|AVX512BW|Shift zmm2/m512 left by imm8 bytes while shifting in 0s and store result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MI|ModRM:r/m (r, w)|imm8|NA|NA|
|VMI|VEX.vvvv (w)|ModRM:r/m (r)|imm8|NA|
|FVMI|EVEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
### Description


Shifts the destination operand (first operand) to the left by the number of bytes specified in the count operand (second operand). The empty low-order bytes are cleared (set to all 0s). If the value specified by the count operand is greater than 15, the destination operand is set to all 0s. The count operand is an 8-bit immediate.

128-bit Legacy SSE version: The source and destination operands are the same. Bits (VLMAX-1:128) of the corre-sponding YMM destination register remain unchanged.

VEX.128 encoded version: The source and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The source operand is YMM register. The destination operand is an YMM register. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed. The count operand applies to both the low and high 128-bit lanes.

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operand is a ZMM/YMM/XMM register. The count operand applies to each 128-bit lanes.


### Operation
#### VPSLLDQ (EVEX.U1.512 encoded version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST[127:0] <-  SRC[127:0] << (TEMP * 8)
DEST[255:128] <-  SRC[255:128] << (TEMP * 8)
DEST[383:256] <-  SRC[383:256] << (TEMP * 8)
DEST[511:384] <-  SRC[511:384] << (TEMP * 8)
DEST[MAX_VL-1:512] <-  0
```
#### VPSLLDQ (VEX.256 and EVEX.256 encoded version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST[127:0] <-  SRC[127:0] << (TEMP * 8)
DEST[255:128] <-  SRC[255:128] << (TEMP * 8)
DEST[MAX_VL-1:256] <-  0
```
#### VPSLLDQ (VEX.128 and EVEX.128 encoded version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST <-  SRC << (TEMP * 8)
DEST[MAX_VL-1:128] <-  0
```
#### PSLLDQ(128-bit Legacy SSE version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST <-  DEST << (TEMP * 8)
DEST[VLMAX-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
(V)PSLLDQ:__m128i _mm_slli_si128 ( __m128i a, int imm)
VPSLLDQ:__m256i _mm256_slli_si256 ( __m256i a, const int imm)
VPSLLDQ __m512i _mm512_bslli_epi128 ( __m512i a, const int imm)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 7. 

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

