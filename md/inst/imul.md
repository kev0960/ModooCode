----------------------------
title : IMUL (Intel x86/64 assembly instruction)
cat_title : IMUL
ref_title : IMUL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/I
publish_date: 2020-09-01
----------------------------


#@ IMUL

**Signed Multiply**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|F6 /5|`IMUL` r/m8\htmlonly{*} |M|Valid|Valid|AX<- AL `*` r/m byte.|
|F7 /5|`IMUL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|DX:AX <- AX `*` r/m word.|
|F7 /5|`IMUL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |M|Valid|Valid|EDX:EAX <- EAX `*` r/m32.|
|REX.W + F7 /5|`IMUL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |M|Valid|N.E.|RDX:RAX <- RAX `*` r/m64.|
|0F AF /r|`IMUL` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|word register <- word register `*` r/m16.|
|0F AF /r|`IMUL` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|Valid|Valid|doubleword register <- doubleword register `*` r/m32.|
|REX.W + 0F AF /r|`IMUL` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|Valid|N.E.|Quadword register <- Quadword register `*` r/m64.|
|6B /r ib|`IMUL` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|Valid|Valid|word register <- r/m16 `*` sign-extended immediate byte.|
|6B /r ib|`IMUL` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|Valid|Valid|doubleword register <- r/m32 `*` sign-extended immediate byte.|
|REX.W + 6B /r ib|`IMUL` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|Valid|N.E.|Quadword register <- r/m64 `*` sign-extended immediate byte.|
|69 /r iw|`IMUL` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |RMI|Valid|Valid|word register <- r/m16 `*` immediate word.|
|69 /r id|`IMUL` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |RMI|Valid|Valid|doubleword register <- r/m32 `*` immediate doubleword.|
|REX.W + 69 /r id|`IMUL` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |RMI|Valid|N.E.|Quadword register <- r/m64 `*` immediate doubleword.|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r, w)|NA|NA|NA|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|imm8/16/32|NA|
### Description


Performs a signed multiplication of two operands. This instruction has three forms, depending on the number of operands. 

*  One-operand form -- This form is identical to that used by the `MUL` instruction. Here, the source operand (in a general-purpose register or memory location) is multiplied by the value in the AL, AX, EAX, or RAX register (depending on the operand size) and the product (twice the size of the input operand) is stored in the AX, DX:AX, EDX:EAX, or RDX:RAX registers, respectively.

*  Two-operand form -- With this form the destination operand (the first operand) is multiplied by the source operand (second operand). The destination operand is a general-purpose register and the source operand is an immediate value, a general-purpose register, or a memory location. The intermediate product (twice the size of the input operand) is truncated and stored in the destination operand location.

*  Three-operand form -- This form requires a destination operand (the first operand) and two source operands (the second and the third operands). Here, the first source operand (which can be a general-purpose register or a memory location) is multiplied by the second source operand (an immediate value). The intermediate product (twice the size of the first source operand) is truncated and stored in the destination operand (a general-purpose register).



When an immediate value is used as an operand, it is sign-extended to the length of the destination operand format.

The CF and OF flags are set when the signed integer value of the intermediate product differs from the sign extended operand-size-truncated product, otherwise the CF and OF flags are cleared.

The three forms of the `IMUL` instruction are similar in that the length of the product is calculated to twice the length of the operands. With the one-operand form, the product is stored exactly in the destination. With the two- and three- operand forms, however, the result is truncated to the length of the destination before it is stored in the destination register. Because of this truncation, the CF or OF flag should be tested to ensure that no significant bits are lost. 

The two- and three-operand forms may also be used with unsigned operands because the lower half of the product is the same regardless if the operands are signed or unsigned. The CF and OF flags, however, cannot be used to determine if the upper half of the result is non-zero.

In 64-bit mode, the instruction's default operation size is 32 bits. Use of the REX.R prefix permits access to addi-tional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits. Use of REX.W modifies the three forms of the instruction as follows.

*  One-operand form --The source operand (in a 64-bit general-purpose register or memory location) is multiplied by the value in the RAX register and the product is stored in the RDX:RAX registers.

*  Two-operand form -- The source operand is promoted to 64 bits if it is a register or a memory location. The destination operand is promoted to 64 bits.

*  Three-operand form -- The first source operand (either a register or a memory location) and destination operand are promoted to 64 bits. If the source operand is an immediate, it is sign extended to 64 bits. 


### Operation

```info-verb
IF (NumberOfOperands = 1)
    THEN IF (OperandSize = 8)
          THEN
                TMP_XP <- AL `*` SRC (* Signed multiplication; TMP_XP is a signed integer at twice the width of the SRC *); 
                AX <- TMP_XP[15:0];
                IF SignExtend(TMP_XP[7:0]) = TMP_XP
                      THEN CF <- 0; OF <- 0;
                      ELSE CF <- 1; OF <- 1; FI;
          ELSE IF OperandSize = 16
                THEN 
                      TMP_XP <- AX `*` SRC (* Signed multiplication; TMP_XP is a signed integer at twice the width of the SRC *) 
                      DX:AX <- TMP_XP[31:0];
                      IF SignExtend(TMP_XP[15:0]) = TMP_XP
                            THEN CF <- 0; OF <- 0;
                            ELSE CF <- 1; OF <- 1; FI;
                ELSE IF OperandSize = 32 
                      THEN 
                            TMP_XP <- EAX `*` SRC (* Signed multiplication; TMP_XP is a signed integer at twice the width of the SRC*) 
                            EDX:EAX <- TMP_XP[63:0];
                            IF SignExtend(TMP_XP[31:0]) = TMP_XP
                                  THEN CF <- 0; OF <- 0;
                                  ELSE CF <- 1; OF <- 1; FI;
                      ELSE (* OperandSize = 64 *)
                            TMP_XP <- RAX `*` SRC (* Signed multiplication; TMP_XP is a signed integer at twice the width of the SRC *)
                            EDX:EAX <- TMP_XP[127:0];
                            IF SignExtend(TMP_XP[63:0]) = TMP_XP
                                  THEN CF <- 0; OF <- 0;
                                  ELSE CF <- 1; OF <- 1; FI;
                      FI;
FI;
    ELSE IF (NumberOfOperands = 2)
          THEN 
                TMP_XP <- DEST `*` SRC (* Signed multiplication; TMP_XP is a signed integer at twice the width of the SRC *)
                DEST <- TruncateToOperandSize(TMP_XP);
                IF SignExtend(DEST) != TMP_XP
                      THEN CF <- 1; OF <- 1;
                      ELSE CF <- 0; OF <- 0; FI;
          ELSE (* NumberOfOperands = 3 *)
                TMP_XP <- SRC1 `*` SRC2 (* Signed multiplication; TMP_XP is a signed integer at twice the width of the SRC1 *)
                DEST <- TruncateToOperandSize(TMP_XP);
                IF SignExtend(DEST) != TMP_XP
                      THEN CF <- 1; OF <- 1;
                      ELSE CF <- 0; OF <- 0; FI;
    FI;
FI;
```
### Flags Affected


For the one operand form of the instruction, the CF and OF flags are set when significant bits are carried into the upper half of the result and cleared when the result fits exactly in the lower half of the result. For the two- and three-operand forms of the instruction, the CF and OF flags are set when the result must be truncated to fit in the destination operand size and cleared when the result fits exactly in the destination operand size. The SF, ZF, AF, and PF flags are undefined.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
