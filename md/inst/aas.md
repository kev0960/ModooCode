----------------------------
title : AAS (Intel x86/64 assembly instruction)
cat_title : AAS
ref_title : AAS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ AAS

**ASCII Adjust AL After Subtraction**

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|3F|AAS|NP|Invalid|Valid|ASCII adjust AL after subtraction.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Adjusts the result of the subtraction of two unpacked BCD values to create a unpacked BCD result. The AL register is the implied source and destination operand for this instruction. The `AAS` instruction is only useful when it follows a `SUB` instruction that subtracts (binary subtraction) one unpacked BCD value from another and stores a byte result in the AL register. The `AAA` instruction then adjusts the contents of the AL register to contain the correct 1-digit unpacked BCD result. 

If the subtraction produced a decimal carry, the AH register decrements by 1, and the CF and AF flags are set. If no decimal carry occurred, the CF and AF flags are cleared, and the AH register is unchanged. In either case, the AL register is left with its top four bits set to 0.

This instruction executes as described in compatibility mode and legacy mode. It is not valid in 64-bit mode.


### Operation

```info-verb
IF 64-bit modeTHEN#UD;ELSEIF ((AL AND 0FH) > 9) or (AF = 1)
                THEN
                      AX <- AX - 6;
                      AH <- AH - 1;
                      AF <- 1;
                      CF <- 1;
                      AL <- AL AND 0FH;
                ELSE
                      CF <- 0;
                      AF <- 0;
                      AL <- AL AND 0FH;
          FI;
FI;
```
### Flags Affected


The AF and CF flags are set to 1 if there is a decimal borrow; otherwise, they are cleared to 0. The OF, SF, ZF, and PF flags are undefined.


### Protected Mode Exceptions

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
