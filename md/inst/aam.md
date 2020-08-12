----------------------------
title : AAM (Intel x86/64 assembly instruction)
cat_title : AAM
ref_title : AAM
path : /X86-64 명령어 레퍼런스
----------------------------
#@ AAM

**ASCII Adjust AX After Multiply**

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|D4 0A|AAM|NP|Invalid|Valid|ASCII adjust AX after multiply.|
|D4 ib|AAM imm8|NP|Invalid|Valid|Adjust AX after multiply to number base imm8.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Adjusts the result of the multiplication of two unpacked BCD values to create a pair of unpacked (base 10) BCD values. The AX register is the implied source and destination operand for this instruction. The `AAM` instruction is only useful when it follows an `MUL` instruction that multiplies (binary multiplication) two unpacked BCD values and stores a word result in the AX register. The `AAM` instruction then adjusts the contents of the AX register to contain the correct 2-digit unpacked (base 10) BCD result. 

The generalized version of this instruction allows adjustment of the contents of the AX to create two unpacked digits of any number base (see the "Operation" section below). Here, the imm8 byte is set to the selected number base (for example, 08H for octal, 0AH for decimal, or 0CH for base 12 numbers). The `AAM` mnemonic is interpreted by all assemblers to mean adjust to ASCII (base 10) values. To adjust to values in another number base, the instruction must be hand coded in machine code (D4 imm8).

This instruction executes as described in compatibility mode and legacy mode. It is not valid in 64-bit mode.


### Operation

```info-verb
IF 64-Bit ModeTHEN#UD;ELSEtempAL <- AL;
          AH <- tempAL / imm8; (* imm8 is set to 0AH for the AAM mnemonic *)
          AL <- tempAL MOD imm8;
FI;
The immediate value (imm8) is taken from the second byte of the instruction.
```
### Flags Affected


The SF, ZF, and PF flags are set according to the resulting binary value in the AL register. The OF, AF, and CF flags are undefined.


### Protected Mode Exceptions

#### #DE
* If an immediate value of 0 is used.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions



Same exceptions as protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as protected mode.


### Compatibility Mode Exceptions



Same exceptions as protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If in 64-bit mode.
