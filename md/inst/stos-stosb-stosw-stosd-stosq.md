----------------------------
title : STOS, STOSB, STOSW, STOSD, STOSQs (Intel x86/64 assembly instruction)
cat_title : STOS, STOSB, STOSW, STOSD, STOSQ
ref_title : STOS, STOSB, STOSW, STOSD, STOSQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ STOS, STOSB, STOSW, STOSD, STOSQ

**Store String**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|AA|`STOS` \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |NA|Valid |Valid|For legacy mode, store AL at address ES:(E)DI; For 64-bit mode store AL at address RDI or EDI.|
|AB|`STOS` \tooltip{m16}{DS:(E)SI, ES:(E)DI 로 표현되는 2 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |NA|Valid |Valid|For legacy mode, store AX at address ES:(E)DI; For 64-bit mode store AX at address RDI or EDI.|
|AB|`STOS` \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} |NA|Valid |Valid|For legacy mode, store EAX at address ES:(E)DI; For 64-bit mode store EAX at address RDI or EDI.|
|REX.W + AB|`STOS` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} |NA|Valid |N.E.|Store RAX at address RDI or EDI.|
|AA|`STOSB` |NA|Valid |Valid|For legacy mode, store AL at address ES:(E)DI; For 64-bit mode store AL at address RDI or EDI.|
|AB|`STOSW` |NA|Valid |Valid|For legacy mode, store AX at address ES:(E)DI; For 64-bit mode store AX at address RDI or EDI.|
|AB|`STOSD` |NA|Valid |Valid|For legacy mode, store EAX at address ES:(E)DI; For 64-bit mode store EAX at address RDI or EDI.|
|REX.W + AB|`STOSQ` |NA|Valid |N.E.|Store RAX at address RDI or EDI.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NA|NA|NA|NA|NA|
### Description


In non-64-bit and default 64-bit mode; stores a byte, word, or doubleword from the AL, AX, or EAX register (respectively) into the destination operand. The destination operand is a memory location, the address of which is read from either the ES:EDI or ES:DI register (depending on the address-size attribute of the instruction and the mode of operation). The ES segment cannot be overridden with a segment override prefix.

At the assembly-code level, two forms of the instruction are allowed: the "explicit-operands" form and the "no-operands" form. The explicit-operands form (specified with the `STOS` mnemonic) allows the destination operand to be specified explicitly. Here, the destination operand should be a symbol that indicates the size and location of the destination value. The source operand is then automatically selected to match the size of the destination operand (the AL register for byte operands, AX for word operands, EAX for doubleword operands). The explicit-operands form is provided to allow documentation; however, note that the documentation provided by this form can be misleading. That is, the destination operand symbol must specify the correct type (size) of the operand (byte, word, or doubleword), but it does not have to specify the correct location. The location is always specified by the ES:(E)DI register. These must be loaded correctly before the store string instruction is executed.

The no-operands form provides "short forms" of the byte, word, doubleword, and quadword versions of the `STOS` instructions. Here also ES:(E)DI is assumed to be the destination operand and AL, AX, or EAX is assumed to be the source operand. The size of the destination and source operands is selected by the mnemonic: `STOSB` (byte read from register AL), `STOSW` (word from AX), `STOSD` (doubleword from EAX).

After the byte, word, or doubleword is transferred from the register to the memory location, the (E)DI register is incremented or decremented according to the setting of the DF flag in the EFLAGS register. If the DF flag is 0, the register is incremented; if the DF flag is 1, the register is decremented (the register is incremented or decremented by 1 for byte operations, by 2 for word operations, by 4 for doubleword operations).



NOTE: To improve performance, more recent processors support modifications to the processor's operation during the string store operations initiated with `STOS` and `STOSB`. See Section 7.3.9.3 in the Intel(R) 64 and IA-32 Archi-tectures Software Developer's Manual, Volume 1 for additional information on fast-string operation.

In 64-bit mode, the default address size is 64 bits, 32-bit address size is supported using the prefix 67H. Using a REX prefix in the form of REX.W promotes operation on doubleword operand to 64 bits. The promoted no-operand mnemonic is `STOSQ`. `STOSQ` (and its explicit operands variant) store a quadword from the RAX register into the destination addressed by RDI or EDI. See the summary chart at the beginning of this section for encoding data and limits.

The `STOS`, `STOSB`, `STOSW`, `STOSD`, `STOSQ` instructions can be preceded by the `REP` prefix for block loads of ECX bytes, words, or doublewords. More often, however, these instructions are used within a `LOOP` construct because data needs to be moved into the AL, AX, or EAX register before it can be stored. See "REP/REPE/REPZ /REPNE/REPNZ--Repeat String Operation Prefix" in this chapter for a description of the `REP` prefix.


### Operation

```info-verb
Non-64-bit Mode:
IF (Byte store)
    THEN
          DEST <- AL;
                THEN IF DF = 0
                      THEN (E)DI <- (E)DI + 1; 
                      ELSE (E)DI <- (E)DI - 1; 
                FI;
    ELSE IF (Word store)
          THEN
                DEST <- AX;
                      THEN IF DF = 0
                            THEN (E)DI <- (E)DI + 2; 
                            ELSE (E)DI <- (E)DI - 2; 
                      FI;
          FI;
    ELSE IF (Doubleword store)
          THEN
                DEST <- EAX;
                      THEN IF DF = 0
                            THEN (E)DI <- (E)DI + 4; 
                            ELSE (E)DI <- (E)DI - 4; 
                      FI;
          FI;
FI;
64-bit Mode:
IF (Byte store)
    THEN
          DEST <- AL;
                THEN IF DF = 0
                      THEN (R|E)DI <- (R|E)DI + 1; 
                      ELSE (R|E)DI <- (R|E)DI - 1; 
                FI;
    ELSE IF (Word store)
          THEN
                DEST <- AX;
THEN IF DF = 0
                            THEN (R|E)DI <- (R|E)DI + 2; 
                            ELSE (R|E)DI <- (R|E)DI - 2; 
                      FI;
          FI;
    ELSE IF (Doubleword store)
          THEN
                DEST <- EAX;
                      THEN IF DF = 0
                            THEN (R|E)DI <- (R|E)DI + 4; 
                            ELSE (R|E)DI <- (R|E)DI - 4; 
                      FI;
          FI;
    ELSE IF (Quadword store using REX.W )
          THEN
                DEST <- RAX;
                      THEN IF DF = 0
                            THEN (R|E)DI <- (R|E)DI + 8; 
                            ELSE (R|E)DI <- (R|E)DI - 8; 
                      FI;
          FI;
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If the destination is located in a non-writable segment.
* If a memory operand effective address is outside the limit of the ES segment.
* If the ES register contains a NULL segment selector.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the ES segment limit.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the ES segment limit.

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

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
