----------------------------
title : NOT (Intel x86/64 assembly instruction)
cat_title : NOT
ref_title : NOT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/N
publish_date: 2020-09-01
----------------------------


#@ NOT

**One's Complement Negation**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|F6 /2|`NOT` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Reverse each bit of r/m8.|
|REX + F6 /2|`NOT` r/m8\htmlonly{*} |M|Valid|N.E.|Reverse each bit of r/m8.|
|F7 /2|`NOT` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Reverse each bit of r/m16.|
|F7 /2|`NOT` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |M|Valid|Valid|Reverse each bit of r/m32.|
|REX.W + F7 /2|`NOT` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |M|Valid |N.E.|Reverse each bit of r/m64.|

```note
\htmlonly{*}  In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r, w)|NA|NA|NA|
### Description


Performs a bitwise `NOT` operation (each 1 is set to 0, and each 0 is set to 1) on the destination operand and stores the result in the destination operand location. The destination operand can be a register or a memory location.

This instruction can be used with a `LOCK` prefix to allow the instruction to be executed atomically.

In 64-bit mode, the instruction's default operation size is 32 bits. Using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). Using a REX prefix in the form of REX.W promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
DEST <- NOT DEST;
```
### Flags Affected


None


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



Same as for protected mode exceptions.


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
