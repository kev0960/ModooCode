----------------------------
title : INC (Intel x86/64 assembly instruction)
cat_title : INC
ref_title : INC
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/I
publish_date: 2020-09-01
----------------------------


#@ INC

**Increment by 1**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FE /0|`INC` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Increment r/m byte by 1.|
|REX + FE /0|`INC` r/m8\footnote{\htmlonly{*}} |M|Valid|N.E.|Increment r/m byte by 1.|
|FF /0|`INC` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Increment r/m word by 1.|
|FF /0|`INC` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |M|Valid|Valid|Increment r/m doubleword by 1.|
|REX.W + FF /0|`INC` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |M|Valid|N.E.|Increment r/m quadword by 1.|
|40+ rw\footnote{\htmlonly{*}\htmlonly{*}}|`INC` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |O|N.E.|Valid|Increment word register by 1.|
|40+ rd|`INC` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |O|N.E.|Valid|Increment doubleword register by 1.|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.

\htmlonly{*}\htmlonly{*}40H through 47H are REX prefixes in 64-bit mode
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r, w)|NA|NA|NA|
|O|opcode + rd (r, w)|NA|NA|NA|
### Description


Adds 1 to the destination operand, while preserving the state of the CF flag. The destination operand can be a register or a memory location. This instruction allows a loop counter to be updated without disturbing the CF flag. (Use a `ADD` instruction with an immediate operand of 1 to perform an increment operation that does updates the CF flag.)

This instruction can be used with a `LOCK` prefix to allow the instruction to be executed atomically.

In 64-bit mode, `INC` r16 and `INC` r32 are not encodable (because opcodes 40H through 47H are REX prefixes). Otherwise, the instruction's 64-bit mode default operation size is 32 bits. Use of the REX.R prefix permits access to additional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits.


### Operation

```info-verb
DEST <- DEST + 1;
```
### AFlags Affected


The CF flag is not affected. The OF, SF, ZF, AF, and PF flags are set according to the result.


### Protected Mode Exceptions

#### #GP(0)
* If the destination operand is located in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULLsegment selector.

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
