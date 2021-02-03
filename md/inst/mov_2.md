----------------------------
title : MOV (Intel x86/64 assembly instruction)
cat_title : MOV
ref_title : MOV
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOV

**Move to/from Debug Registers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|`0F 21/r`\newline{}`MOV` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} DR0-DR7 |MR|N.E.|Valid|Move debug register to r32.|
|`0F 21/r`\newline{}`MOV` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} DR0-DR7 |MR|Valid|N.E.|Move extended debug register to r64. |
|`0F 23 /r`\newline{}`MOV` DR�V� �DR7 \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |RM|N.E.|Valid|Move r32 to debug register.|
|`0F 23 /r`\newline{}`MOV` DR�V� �DR7 \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |RM|Valid |N.E.|Move r64 to extended debug register. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|RM|ModRM:reg (w��|ModRM:r/m (r)|NA|NA|
### Description


Moves the contents of a debug register (DR0, DR1, DR2, DR3, DR4, DR5, DR6, or DR7�� to a general-purpose register or vice versa. The operand size for these instructions is always 32 bits in non-64-bit modes, regardless of the operand-size attribute. (See Section 17.2, ��VV�bug Registers", of theI ntel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 3A, for a detailed description of the flags and fields in the debug registers.��

The instructions must be executed at privilege level 0 or in real-address mode.

When the debug extension (DE) flag in register CR4 is clear, these instructions operate on debug registers in a manner that is compatible with Intel386 and Intel486 processors. In this mode, references to DR4 and DR5 refer to DR6 and DR7, respectively. When the DE flag in CR4 is set, attempts to reference DR4 and DR5 result in an undefined opcode (#UD) exception. (The CR4 register was added to the IA-32 Architecture beginning with the Pentium processor.��

At the opcode level, the reg field within the ModR/M byte specifies which of the debug registers is loaded or read. The two bits in the mod field are ignored. The r/m field specifies the general-purpose register loaded or read.

In 64-bit mode, the instruction's default operation size is 64 bits. Use of the REX.B prefix permits access to addi-tional registers (R8-R15). Use of the REX.W or 66H prefix is ignored. Use of the REX.R prefix causes an invalid-opcode exception. See the summary chart at the beginning of this section for encoding data and limits. 


### Operation

```info-verb
IF ((DE = 1) and (SRC or DEST = DR4 or DR5)��THEN#UD;ELSE DEST 0  SRC;
FI;
```
### Flags Affected


The OF, SF, ZF, AF, PF, and CF flags are undefined.


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.

#### #UD
* If CR4.DE[bit 3] = 1 (debug extensions) and a MOV instruction is executed involving DR4 or DR5.
* If the LOCK prefix is used.

#### #DB
* If any debug register is accessed while the DR7.GD[bit 13] = 1.

### Real-Address Mode Exceptions

#### #UD
* If CR4.DE[bit 3] = 1 (debug extensions) and a MOV instruction is executed involving DR4 or DR5. 
* If the LOCK prefix is used.

#### #DB
* If any debug register is accessed while the DR7.GD[bit 13] = 1.

### Virtual-8086 Mode Exceptions

#### #GP��0)
* The debug registers cannot be loaded or read when in virtual-8086 mode.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If an attempt is made to write a 1 to any of bits 63:32 in DR6.
* If an attempt is made to write a 1 to any of bits 63:32 in DR7.

#### #UD
* If CR4.DE[bit 3] = 1 (debug extensions) and a MOV instruction is executed involving DR4 or DR5.
* If the LOCK prefix is used.
* If the REX.R prefix is used.

#### #DB
* If any debug register is accessed while the DR7.GD[bit 13] = 1.
