----------------------------
title : PUSH (Intel x86/64 assembly instruction)
cat_title : PUSH
ref_title : PUSH
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PUSH

**Push Word, Doubleword or Quadword Onto the Stack**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FF /6|`PUSH` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Push r/m16.|
|FF /6|`PUSH` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |M|N.E.|Valid|Push r/m32.|
|FF /6|`PUSH` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |M|Valid|N.E.|Push r/m64. |
|50+rw|`PUSH` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |O|Valid |Valid|Push r16.|
|50+rd|`PUSH` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |O|N.E.|Valid|Push r32.|
|50+rd|`PUSH` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |O|Valid|N.E.|Push r64.|
|6A ib|`PUSH` \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |I|Valid|Valid|Push imm8.|
|68 iw|`PUSH` \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |I|Valid|Valid|Push imm16.|
|68 id|`PUSH` \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |I|Valid|Valid|Push imm32.|
|0E|`PUSH` CS |NP|Invalid|Valid|Push CS.|
|16|`PUSH` SS |NP|Invalid|Valid|Push SS.|
|1E|`PUSH` DS |NP|Invalid|Valid|Push DS.|
|06|`PUSH` ES |NP|Invalid|Valid|Push ES.|
|0F A0|`PUSH` FS |NP|Valid|Valid|Push FS.|
|0F A8|`PUSH` GS |NP|Valid|Valid|Push GS.|

```note
\htmlonly{*} See IA-32 Architecture Compatibility section below
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
|O|opcode + rd (r)|NA|NA|NA|
|I|imm8/16/32|NA|NA|NA|
|NP|NA|NA|NA|NA|
### Description


Decrements the stack pointer and then stores the source operand on the top of the stack. Address and operand sizes are determined and used as follows:

*  Address size. The D flag in the current code-segment descriptor determines the default address size; it may be overridden by an instruction prefix (67H).

     The address size is used only when referencing a source operand in memory.

*  Operand size. The D flag in the current code-segment descriptor determines the default operand size; it may be overridden by instruction prefixes (66H or REX.W).

     The operand size (16, 32, or 64 bits) determines the amount by which the stack pointer is decremented (2, 4or 8).

     If the source operand is an immediate of size less than the operand size, a sign-extended value is pushed onthe stack. If the source operand is a segment register (16 bits) and the operand size is 64-bits, a zero-extended value is pushed on the stack; if the operand size is 32-bits, either a zero-extended value is pushedon the stack or the segment selector is written on the stack using a 16-bit move. For the last case, all recentCore and Atom processors perform a 16-bit move, leaving the upper portion of the stack location unmodified.

*  Stack-address size. Outside of 64-bit mode, the B flag in the current stack-segment descriptor determines the size of the stack pointer (16 or 32 bits); in 64-bit mode, the size of the stack pointer is always 64 bits.



The stack-address size determines the width of the stack pointer when writing to the stack in memory andwhen  decrementing  the  stack  pointer.  (As  stated  above,  the  amount  by  which  the  stack  pointer  isdecremented is determined by the operand size.)

     If the operand size is less than the stack-address size, the `PUSH` instruction may result in a misaligned stackpointer (a stack pointer that is not aligned on a doubleword or quadword boundary).

The `PUSH` ESP instruction pushes the value of the ESP register as it existed before the instruction was executed. If a `PUSH` instruction uses a memory operand in which the ESP register is used for computing the operand address, the address of the operand is computed before the ESP register is decremented. 

If the ESP or SP register is 1 when the `PUSH` instruction is executed in real-address mode, a stack-fault exception (#SS) is generated (because the limit of the stack segment is violated). Its delivery encounters a second stack-fault exception (for the same reason), causing generation of a double-fault exception (#DF). Delivery of the double-fault exception encounters a third stack-fault exception, and the logical processor enters shutdown mode. See the discussion of the double-fault exception in Chapter 6 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

### IA-32 Architecture Compatibility


For IA-32 processors from the Intel 286 on, the PUSH ESP instruction pushes the value of the ESP register as it existed before the instruction was executed. (This is also true for Intel 64 architecture, real-address and virtual-8086 modes of IA-32 architecture.) For the Intel\footnote{(R)}  8086 processor, the PUSH SP instruction pushes the new value of the SP register (that is the value after it has been decremented by 2).


### Operation

```info-verb
(* See Description section for possible sign-extension or zero-extension of source operand and for *)
(* a case in which the size of the memory store may be smaller than the instruction's operand size *)
IF StackAddrSize = 64
    THEN
          IF OperandSize = 64
                THEN
                      RSP <- RSP - 8;
                      Memory[SS:RSP] <- SRC; (* push quadword *)
          ELSE IF OperandSize = 32
                THEN
                      RSP <- RSP - 4;
                      Memory[SS:RSP] <- SRC; (* push dword *)
                ELSE (* OperandSize = 16 *)
                      RSP <- RSP - 2;
                      Memory[SS:RSP] <- SRC; (* push word *)
          FI;
ELSE IF StackAddrSize = 32
    THEN
          IF OperandSize = 64
                THEN
                      ESP <- ESP - 8;
                      Memory[SS:ESP] <- SRC; (* push quadword *)
          ELSE IF OperandSize = 32
                THEN
                      ESP <- ESP - 4;
                      Memory[SS:ESP] <- SRC; (* push dword *)
                ELSE (* OperandSize = 16 *)
                      ESP <- ESP - 2;
                      Memory[SS:ESP] <- SRC; (* push word *)
          FI;
    ELSE (* StackAddrSize = 16 *)
IF OperandSize = 32
                THEN
                      SP <- SP - 4;
                      Memory[SS:SP] <- SRC; (* push dword *)
                ELSE (* OperandSize = 16 *)
                      SP <- SP - 2;
                      Memory[SS:SP] <- SRC; (* push word *)
          FI;
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

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
* If the new value of the SP or ESP register is outside the stack segment limit.

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

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
* If the PUSH is of CS, SS, DS, or ES.
