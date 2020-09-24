----------------------------
title : LODS, LODSB, LODSW, LODSD, LODSQs (Intel x86/64 assembly instruction)
cat_title : LODS, LODSB, LODSW, LODSD, LODSQ
ref_title : LODS, LODSB, LODSW, LODSD, LODSQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LODS, LODSB, LODSW, LODSD, LODSQ

**Load String**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|AC|`LODS` \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |NP|Valid|Valid|For legacy mode, Load byte at address DS:(E)SI into AL. For 64-bit mode load byte at address (R)SI into AL.|
|AD|`LODS` \tooltip{m16}{DS:(E)SI, ES:(E)DI 로 표현되는 2 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |NP|Valid|Valid|For legacy mode, Load word at address DS:(E)SI into AX. For 64-bit mode load word at address (R)SI into AX.|
|AD|`LODS` \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} |NP|Valid|Valid|For legacy mode, Load dword at address DS:(E)SI into EAX. For 64-bit mode load dword at address (R)SI into EAX.|
|REX.W + AD|`LODS` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} |NP|Valid|N.E.|Load qword at address (R)SI into RAX.|
|AC|`LODSB` |NP|Valid|Valid|For legacy mode, Load byte at address DS:(E)SI into AL. For 64-bit mode load byte at address (R)SI into AL.|
|AD|`LODSW` |NP|Valid|Valid|For legacy mode, Load word at address DS:(E)SI into AX. For 64-bit mode load word at address (R)SI into AX.|
|AD|`LODSD` |NP|Valid|Valid|For legacy mode, Load dword at address DS:(E)SI into EAX. For 64-bit mode load dword at address (R)SI into EAX.|
|REX.W + AD|`LODSQ` |NP|Valid|N.E.|Load qword at address (R)SI into RAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Loads a byte, word, or doubleword from the source operand into the AL, AX, or EAX register, respectively. The source operand is a memory location, the address of which is read from the DS:ESI or the DS:SI registers (depending on the address-size attribute of the instruction, 32 or 16, respectively). The DS segment may be over-ridden with a segment override prefix.

At the assembly-code level, two forms of this instruction are allowed: the "explicit-operands" form and the "no-operands" form. The explicit-operands form (specified with the `LODS` mnemonic) allows the source operand to be specified explicitly. Here, the source operand should be a symbol that indicates the size and location of the source value. The destination operand is then automatically selected to match the size of the source operand (the AL register for byte operands, AX for word operands, and EAX for doubleword operands). This explicit-operands form is provided to allow documentation; however, note that the documentation provided by this form can be misleading. That is, the source operand symbol must specify the correct type (size) of the operand (byte, word, or doubleword), but it does not have to specify the correct location. The location is always specified by the DS:(E)SI registers, which must be loaded correctly before the load string instruction is executed.

The no-operands form provides "short forms" of the byte, word, and doubleword versions of the `LODS` instructions. Here also DS:(E)SI is assumed to be the source operand and the AL, AX, or EAX register is assumed to be the desti-nation operand. The size of the source and destination operands is selected with the mnemonic: `LODSB` (byte loaded into register AL), `LODSW` (word loaded into AX), or `LODSD` (doubleword loaded into EAX).

After the byte, word, or doubleword is transferred from the memory location into the AL, AX, or EAX register, the (E)SI register is incremented or decremented automatically according to the setting of the DF flag in the EFLAGS register. (If the DF flag is 0, the (E)SI register is incremented; if the DF flag is 1, the ESI register is decremented.) The (E)SI register is incremented or decremented by 1 for byte operations, by 2 for word operations, or by 4 for doubleword operations.



In 64-bit mode, use of the REX.W prefix promotes operation to 64 bits. LODS/LODSQ load the quadword at address (R)SI into RAX. The (R)SI register is then incremented or decremented automatically according to the setting of the DF flag in the EFLAGS register. 

The `LODS`, `LODSB`, `LODSW`, and `LODSD` instructions can be preceded by the `REP` prefix for block loads of ECX bytes, words, or doublewords. More often, however, these instructions are used within a `LOOP` construct because further processing of the data moved into the register is  usually necessary before the next transfer can be made. See "REP/REPE/REPZ /REPNE/REPNZ--Repeat String Operation Prefix" in Chapter 4 of the Intel(R) 64 and IA-32 Archi-tectures Software Developer's Manual, Volume 2B, for a description of the `REP` prefix.


### Operation

```info-verb
IF AL <- SRC; (* Byte load *)
    THEN AL <- SRC; (* Byte load *)
          IF DF = 0
                THEN (E)SI <- (E)SI + 1; 
                ELSE (E)SI <- (E)SI - 1; 
          FI;
ELSE IF AX <- SRC; (* Word load *)
    THEN IF DF = 0
                THEN (E)SI <- (E)SI + 2; 
                ELSE (E)SI <- (E)SI - 2; 
          IF;
    FI;
ELSE IF EAX <- SRC; (* Doubleword load *)
    THEN IF DF = 0
                THEN (E)SI <- (E)SI + 4; 
                ELSE (E)SI <- (E)SI - 4; 
          FI;
    FI;
ELSE IF RAX <- SRC; (* Quadword load *)
    THEN IF DF = 0
                THEN (R)SI <- (R)SI + 8; 
                ELSE (R)SI <- (R)SI - 8; 
          FI;
    FI;
FI;
```
### Flags Affected


None


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
