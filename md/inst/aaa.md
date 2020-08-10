### AAA--ASCII Adjust After Addition


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|37|AAA|NP|Invalid|Valid|ASCII adjust AL after addition.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Adjusts the sum of two unpacked BCD values to create an unpacked BCD result. The AL register is the implied source and destination operand for this instruction. The AAA instruction is only useful when it follows an ADD instruction that adds (binary addition) two unpacked BCD values and stores a byte result in the AL register. The AAA instruction then adjusts the contents of the AL register to contain the correct 1-digit unpacked BCD result. 

If the addition produces a decimal carry, the AH register increments by 1, and the CF and AF flags are set. If there was no decimal carry, the CF and AF flags are cleared and the AH register is unchanged. In either case, bits 4 through 7 of the AL register are set to 0.

This instruction executes as described in compatibility mode and legacy mode. It is not valid in 64-bit mode.


### Operation

```info-verb
IF 64-Bit ModeTHEN#UD;ELSEIF ((AL AND 0FH) > 9) or (AF = 1)
    THEN
      AX <- AX + 106H;
      AF <- 1;
      CF <- 1;
    ELSE
      AF <- 0;
      CF <- 0;FI;
   AL <- AL AND 0FH;
FI;
```
### Flags Affected


The AF and CF flags are set to 1 if the adjustment results in a decimal carry; otherwise they are set to 0. The OF, SF, ZF, and PF flags are undefined.


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
