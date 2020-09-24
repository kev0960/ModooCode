----------------------------
title : TEST (Intel x86/64 assembly instruction)
cat_title : TEST
ref_title : TEST
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/T
publish_date: 2020-09-01
----------------------------


#@ TEST

**Logical Compare**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|A8 ib|`TEST` AL \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |I|Valid |Valid|AND imm8 with AL; set SF, ZF, PF according to result.|
|A9 iw|`TEST` AX \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |I|Valid |Valid|AND imm16 with AX; set SF, ZF, PF according to result.|
|A9 id|`TEST` EAX \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |I|Valid |Valid|AND imm32 with EAX; set SF, ZF, PF according to result.|
|REX.W + A9 id|`TEST` RAX \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |I|Valid |N.E.|AND imm32 sign-extended to 64-bits with RAX; set SF, ZF, PF according to result.|
|F6 /0 ib|`TEST` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|AND imm8 with r/m8; set SF, ZF, PF according to result.|
|REX + F6 /0 ib|`TEST` r/m8\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |N.E.|AND imm8 with r/m8; set SF, ZF, PF according to result.|
|F7 /0 iw|`TEST` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |MI|Valid |Valid|AND imm16 with r/m16; set SF, ZF, PF according to result.|
|F7 /0 id|`TEST` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |MI|Valid |Valid|AND imm32 with r/m32; set SF, ZF, PF according to result.|
|REX.W + F7 /0 id|`TEST` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |MI|Valid |N.E.|AND imm32 sign-extended to 64-bits with r/m64; set SF, ZF, PF according to result.|
|84 /r|`TEST` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{r8}{1 바이트 짜리 범용 레지스터를 의미 (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, SIL). 64 비트 모드에 경우 추가적으로 R8L 부터 R16L 까지 가능} |MR|Valid |Valid|AND r8 with r/m8; set SF, ZF, PF according to result.|
|REX + 84 /r|`TEST` r/m8\htmlonly{*} r8\htmlonly{*} |MR|Valid |N.E.|AND r8 with r/m8; set SF, ZF, PF according to result.|
|85 /r|`TEST` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |MR|Valid |Valid|AND r16 with r/m16; set SF, ZF, PF according to result.|
|85 /r|`TEST` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |MR|Valid |Valid|AND r32 with r/m32; set SF, ZF, PF according to result.|
|REX.W + 85 /r|`TEST` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |MR|Valid |N.E.|AND r64 with r/m64; set SF, ZF, PF according to result.|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|I|AL/AX/EAX/RAX|imm8/16/32|NA|NA|
|MI|ModRM:r/m (r)|imm8/16/32|NA|NA|
|MR|ModRM:r/m (r)|ModRM:reg (r)|NA|NA|
### Description


Computes the bit-wise logical `AND` of first operand (source 1 operand) and the second operand (source 2 operand) and sets the SF, ZF, and PF status flags according to the result. The result is then discarded.

In 64-bit mode, using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). Using a REX prefix in the form of REX.W promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
TEMP <- SRC1 AND SRC2;
SF <- MSB(TEMP);
IF TEMP = 0
    THEN ZF <- 1;
    ELSE ZF <- 0;
FI:
PF <- BitwiseXNOR(TEMP[0:7]);
CF <- 0;
OF <- 0;
(* AF is undefined *)
```
### Flags Affected


The OF and CF flags are set to 0. The SF, ZF, and PF flags are set according to the result (see the "Operation" section above). The state of the AF flag is undefined.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

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
