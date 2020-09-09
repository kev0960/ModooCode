----------------------------
title : KSHIFTRW, KSHIFTRB, KSHIFTRQ, KSHIFTRDs (Intel x86/64 assembly instruction)
cat_title : KSHIFTRW, KSHIFTRB, KSHIFTRQ, KSHIFTRD
ref_title : KSHIFTRW, KSHIFTRB, KSHIFTRQ, KSHIFTRD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KSHIFTRW, KSHIFTRB, KSHIFTRQ, KSHIFTRD

**Shift Right Mask Registers **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.L0.66.0F3A.W1 30 /r \newline{}KSHIFTRW k1, k2, imm8|RRI|V/V|AVX512F|Shift right 16 bits in k2 by immediate and write result in k1.|
|VEX.L0.66.0F3A.W0 30 /r \newline{}KSHIFTRB k1, k2, imm8|RRI|V/V|AVX512DQ|Shift right 8 bits in k2 by immediate and write result in k1.|
|VEX.L0.66.0F3A.W1 31 /r \newline{}KSHIFTRQ k1, k2, imm8|RRI|V/V|AVX512BW|Shift right 64 bits in k2 by immediate and write result in k1.|
|VEX.L0.66.0F3A.W0 31 /r \newline{}KSHIFTRD k1, k2, imm8|RRI|V/V|AVX512BW|Shift right 32 bits in k2 by immediate and write result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RRI|ModRM:reg (w)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|Imm8|
### Description


Shifts 8/16/32/64 bits in the second operand (source operand) right by the count specified in immediate and place the least significant 8/16/32/64 bits of the result in the destination operand. The higher bits of the destination are zero-extended. The destination is set to zero if the count value is greater than 7 (for byte shift), 15 (for word shift), 31 (for doubleword shift) or 63 (for quadword shift).


### Operation
#### KSHIFTRW
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=15
    THEN DEST[15:0] <-  SRC1[15:0] >> COUNT;
FI;
```
#### KSHIFTRB
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=7
            THEN  DEST[7:0] <-  SRC1[7:0] >> COUNT;FI;
```
#### KSHIFTRQ
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=63
            THEN  DEST[63:0] <-  SRC1[63:0] >> COUNT;
FI;
```
#### KSHIFTRD
```info-verb
COUNT <-  imm8[7:0]
DEST[MAX_KL-1:0] <-  0
IF COUNT <=31
            THEN  DEST[31:0] <-  SRC1[31:0] >> COUNT;
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
Compiler auto generates KSHIFTRW when needed.
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

