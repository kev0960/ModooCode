----------------------------
title : XOR (Intel x86/64 assembly instruction)
cat_title : XOR
ref_title : XOR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/X
publish_date: 2020-09-01
----------------------------


#@ XOR

**Logical Exclusive OR**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|34 ib|`XOR` AL \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |I|Valid|Valid|AL XOR imm8.|
|35 iw|`XOR` AX \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |I|Valid|Valid|AX XOR imm16.|
|35 id|`XOR` EAX \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |I|Valid|Valid|EAX XOR imm32.|
|REX.W + 35 id|`XOR` RAX \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |I|Valid|N.E.|RAX XOR imm32 (sign-extended).|
|80 /6 ib|`XOR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|Valid|r/m8 XOR imm8.|
|REX + 80 /6 ib|`XOR` r/m8\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|r/m8 XOR imm8.|
|81 /6 iw|`XOR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |MI|Valid|Valid|r/m16 XOR imm16.|
|81 /6 id|`XOR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |MI|Valid|Valid|r/m32 XOR imm32.|
|REX.W + 81 /6 id|`XOR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |MI|Valid|N.E.|r/m64 XOR imm32 (sign-extended).|
|83 /6 ib|`XOR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|Valid|r/m16 XOR imm8 (sign-extended).|
|83 /6 ib|`XOR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|Valid|r/m32 XOR imm8 (sign-extended).|
|REX.W + 83 /6 ib|`XOR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|r/m64 XOR imm8 (sign-extended).|
|30 /r|`XOR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{r8}{1 바이트 짜리 범용 레지스터를 의미 (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, SIL). 64 비트 모드에 경우 추가적으로 R8L 부터 R16L 까지 가능} |MR|Valid|Valid|r/m8 XOR r8.|
|REX + 30 /r|`XOR` r/m8\htmlonly{*} r8\htmlonly{*} |MR|Valid|N.E.|r/m8 XOR r8.|
|31 /r|`XOR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |MR|Valid|Valid|r/m16 XOR r16.|
|31 /r|`XOR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |MR|Valid|Valid|r/m32 XOR r32.|
|REX.W + 31 /r|`XOR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |MR|Valid|N.E.|r/m64 XOR r64.|
|32 /r|`XOR` \tooltip{r8}{1 바이트 짜리 범용 레지스터를 의미 (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, SIL). 64 비트 모드에 경우 추가적으로 R8L 부터 R16L 까지 가능} \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|r8 XOR r/m8.|
|REX + 32 /r|`XOR` r8\htmlonly{*} r/m8\htmlonly{*} |RM|Valid|N.E.|r8 XOR r/m8.|
|33 /r|`XOR` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|r16 XOR r/m16.|
|33 /r|`XOR` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|Valid|Valid|r32 XOR r/m32.|
|REX.W + 33 /r|`XOR` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|Valid|N.E.|r64 XOR r/m64.|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|I|AL/AX/EAX/RAX|imm8/16/32|NA|NA|
|MI|ModRM:r/m (r, w)|imm8/16/32|NA|NA|
|MR|ModRM:r/m (r, w)|ModRM:reg (r)|NA|NA|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
### Description


Performs a bitwise exclusive `OR` (XOR) operation on the destination (first) and source (second) operands and stores the result in the destination operand location. The source operand can be an immediate, a register, or a memory location; the destination operand can be a register or a memory location. (However, two memory oper-ands cannot be used in one instruction.) Each bit of the result is 1 if the corresponding bits of the operands are different; each bit is 0 if the corresponding bits are the same.

This instruction can be used with a `LOCK` prefix to allow the instruction to be executed atomically.



In 64-bit mode, using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). Using a REX prefix in the form of REX.W promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
DEST <- DEST XOR SRC;
```
### Flags Affected


The OF and CF flags are cleared; the SF, ZF, and PF flags are set according to the result. The state of the AF flag is undefined.


### Protected Mode Exceptions

#### #GP(0)
* If the destination operand points to a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.

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
* If the LOCK prefix is used but the destination is not a memory operand.

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
* If the LOCK prefix is used but the destination is not a memory operand.
