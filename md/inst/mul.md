----------------------------
title : MUL (Intel x86/64 assembly instruction)
cat_title : MUL
ref_title : MUL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MUL

**Unsigned Multiply**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|F6 /4|`MUL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Unsigned multiply (AX <- AL `*` r/m8).|
|REX + F6 /4|`MUL` r/m8\footnote{\htmlonly{*}} |M|Valid|N.E.|Unsigned multiply (AX <- AL `*` r/m8).|
|F7 /4|`MUL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |M|Valid|Valid|Unsigned multiply (DX:AX <- AX `*` r/m16).|
|F7 /4|`MUL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |M|Valid|Valid|Unsigned multiply (EDX:EAX <- EAX `*` r/m32).|
|REX.W + F7 /4|`MUL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |M|Valid |N.E.|Unsigned multiply (RDX:RAX <- RAX `*` r/m64).|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Performs an unsigned multiplication of the first operand (destination operand) and the second operand (source operand) and stores the result in the destination operand. The destination operand is an implied operand located in register AL, AX or EAX (depending on the size of the operand); the source operand is located in a general-purpose register or a memory location. The action of this instruction and the location of the result depends on the opcode and the operand size as shown in Table 4-9.

The result is stored in register AX, register pair DX:AX, or register pair EDX:EAX (depending on the operand size), with the high-order bits of the product contained in register AH, DX, or EDX, respectively. If the high-order bits of the product are 0, the CF and OF flags are cleared; otherwise, the flags are set.

In 64-bit mode, the instruction's default operation size is 32 bits. Use of the REX.R prefix permits access to addi-tional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits. 

See the summary chart at the beginning of this section for encoding data and limits.

### Table 4-9.  MUL Results


|**Operand Size**|**Source 1**|**Source 2**|**Destination**|
|----------------|------------|------------|---------------|
|Byte|AL|r/m8|AX|
|Word|AX|r/m16|DX:AX|
|Doubleword|EAX|r/m32|EDX:EAX|
|Quadword|RAX|r/m64|RDX:RAX|

### Operation

```info-verb
IF (Byte operation)
    THEN 
          AX <- AL `*` SRC;
    ELSE (* Word or doubleword operation *)
          IF OperandSize = 16
                THEN 
                      DX:AX <- AX `*` SRC;
                ELSE IF OperandSize = 32
                      THEN EDX:EAX <- EAX `*` SRC; FI;
                ELSE (* OperandSize = 64 *)
                      RDX:RAX <- RAX `*` SRC;
          FI;
FI;
```
### Flags Affected


The OF and CF flags are set to 0 if the upper half of the result is 0; otherwise, they are set to 1. The SF, ZF, AF, and PF flags are undefined.


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
