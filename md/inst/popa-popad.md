----------------------------
title : POPA, POPADs (Intel x86/64 assembly instruction)
cat_title : POPA, POPAD
ref_title : POPA, POPAD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ POPA, POPAD

**Pop All General-Purpose Registers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|61|`POPA` |NP|Invalid|Valid|Pop DI, SI, BP, BX, DX, CX, and AX.|
|61|`POPAD` |NP|Invalid|Valid|Pop EDI, ESI, EBP, EBX, EDX, ECX, and EAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Pops doublewords (POPAD) or words (POPA) from the stack into the general-purpose registers. The registers are loaded in the following order: EDI, ESI, EBP, EBX, EDX, ECX, and EAX (if the operand-size attribute is 32) and DI, SI, BP, BX, DX, CX, and AX (if the operand-size attribute is 16). (These instructions reverse the operation of the PUSHA/PUSHAD instructions.) The value on the stack for the ESP or SP register is ignored. Instead, the ESP or SP register is incremented after each register is loaded.

The `POPA` (pop all) and `POPAD` (pop all double) mnemonics reference the same opcode. The `POPA` instruction is intended for use when the operand-size attribute is 16 and the `POPAD` instruction for when the operand-size attri-bute is 32. Some assemblers may force the operand size to 16 when `POPA` is used and to 32 when `POPAD` is used (using the operand-size override prefix [66H] if necessary). Others may treat these mnemonics as synonyms (POPA/POPAD) and use the current setting of the operand-size attribute to determine the size of values to be popped from the stack, regardless of the mnemonic used. (The D flag in the current code segment's segment descriptor determines the operand-size attribute.)

This instruction executes as described in non-64-bit modes. It is not valid in 64-bit mode.


### Operation

```info-verb
IF 64-Bit ModeTHEN#UD;ELSEIF OperandSize = 32 (* Instruction = POPAD *)
    THEN
          EDI <- Pop();
          ESI <- Pop();
          EBP <- Pop();
          Increment ESP by 4; (* Skip next 4 bytes of stack *)
          EBX <- Pop();
          EDX <- Pop();
          ECX <- Pop();
          EAX <- Pop();
    ELSE (* OperandSize = 16, instruction = POPA *)
          DI <- Pop();
          SI <- Pop();
          BP <- Pop();
          Increment ESP by 2; (* Skip next 2 bytes of stack *)
          BX <- Pop();
          DX <- Pop();
          CX <- Pop();
          AX <- Pop();
    FI;
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #SS(0)
* If the starting or ending stack address is not within the stack segment. 

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #SS
* If the starting or ending stack address is not within the stack segment.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #SS(0)
* If the starting or ending stack address is not within the stack segment.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same as for protected mode exceptions.


### 64-Bit Mode Exceptions

#### #UD
* If in 64-bit mode.
