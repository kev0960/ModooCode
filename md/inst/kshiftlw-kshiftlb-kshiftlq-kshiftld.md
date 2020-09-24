----------------------------
title : KSHIFTLW, KSHIFTLB, KSHIFTLQ, KSHIFTLDs (Intel x86/64 assembly instruction)
cat_title : KSHIFTLW, KSHIFTLB, KSHIFTLQ, KSHIFTLD
ref_title : KSHIFTLW, KSHIFTLB, KSHIFTLQ, KSHIFTLD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KSHIFTLW, KSHIFTLB, KSHIFTLQ, KSHIFTLD

**Shift Left Mask Registers **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.L0.66.0F3A.W1 32 /r `\newline{}`KSHIFTLW` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RRI|V/V|AVX512F|Shift left 16 bits in k2 by immediate and write result in k1.|
|`VEX.L0.66.0F3A.W0 32 /r `\newline{}`KSHIFTLB` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RRI|V/V|AVX512DQ|Shift left 8 bits in k2 by immediate and write result in k1.|
|`VEX.L0.66.0F3A.W1 33 /r `\newline{}`KSHIFTLQ` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RRI|V/V|AVX512BW|Shift left 64 bits in k2 by immediate and write result in k1.|
|`VEX.L0.66.0F3A.W0 33 /r `\newline{}`KSHIFTLD` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RRI|V/V|AVX512BW|Shift left 32 bits in k2 by immediate and write result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RRI|ModRM:reg (w)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|Imm8|
### Description


Shifts 8/16/32/64 bits in the second operand (source operand) left by the count specified in immediate byte and place the least significant 8/16/32/64 bits of the result in the destination operand. The higher bits of the destina-tion are zero-extended. The destination is set to zero if the count value is greater than 7 (for byte shift), 15 (for word shift), 31 (for doubleword shift) or 63 (for quadword shift).


### Operation
#### KSHIFTLW
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=15
    THEN DEST[15:0] <-  SRC1[15:0] << COUNT;
FI;
```
#### KSHIFTLB
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=7
            THEN  DEST[7:0] <-  SRC1[7:0] << COUNT;FI;
```
#### KSHIFTLQ
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=63
            THEN  DEST[63:0] <-  SRC1[63:0] << COUNT;
FI;
```
#### KSHIFTLD
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=31
            THEN  DEST[31:0] <-  SRC1[31:0] << COUNT;FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
Compiler auto generates KSHIFTLW when needed.
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

