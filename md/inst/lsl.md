### LSL--Load Segment Limit


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 03 /r|LSL r16, r16/m16|RM|Valid|Valid|Load: r16 <- segment limit, selector r16/m16.|
|0F 03 /r|LSL r32, r32/m16\footnote{*}|RM|Valid|Valid|Load: r32 <- segment limit, selector r32/m16.|
|REX.W + 0F 03 /r|LSL r64, r32/m16\footnote{*}|RM|Valid|Valid|Load: r64 <- segment limit, selector r32/m16|
### NOTES:


*For all loads (regardless of destination sizing), only bits 16-0 are used. Other bits are ignored.

### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Loads the unscrambled segment limit from the segment descriptor specified with the second operand (source operand) into the first operand (destination operand) and sets the ZF flag in the EFLAGS register. The source operand (which can be a register or a memory location) contains the segment selector for the segment descriptor being accessed. The destination operand is a general-purpose register.

The processor performs access checks as part of the loading process. Once loaded in the destination register, soft-ware can compare the segment limit with the offset of a pointer. 

The segment limit is a 20-bit value contained in bytes 0 and 1 and in the first 4 bits of byte 6 of the segment descriptor. If the descriptor has a byte granular segment limit (the granularity flag is set to 0), the destination operand is loaded with a byte granular value (byte limit). If the descriptor has a page granular segment limit (the granularity flag is set to 1), the LSL instruction will translate the page granular limit (page limit) into a byte limit before loading it into the destination operand. The translation is performed by shifting the 20-bit "raw" limit left 12 bits and filling the low-order 12 bits with 1s.

When the operand size is 32 bits, the 32-bit byte limit is stored in the destination operand. When the operand size is 16 bits, a valid 32-bit limit is computed; however, the upper 16 bits are truncated and only the low-order 16 bits are loaded into the destination operand.

This instruction performs the following checks before it loads the segment limit into the destination register: 

*  Checks that the segment selector is not NULL.

*  Checks that the segment selector points to a descriptor that is within the limits of the GDT or LDT being accessed

*  Checks that the descriptor type is valid for this instruction. All code and data segment descriptors are valid for (can be accessed with) the LSL instruction. The valid special segment and gate descriptor types are given in the following table. 

*  If the segment is not a conforming code segment, the instruction checks that the specified segment descriptor is visible at the CPL (that is, if the CPL and the RPL of the segment selector are less than or equal to the DPL of the segment selector).

If the segment descriptor cannot be accessed or is an invalid type for the instruction, the ZF flag is cleared and no value is loaded in the destination operand.

### Table 3-55.  Segment and Gate Descriptor Types


|**Type**|**Protected Mo**|**de**|**IA-32e Mo**|**de**|
|--------|----------------|------|-------------|------|
||**Name**|**Valid**|**Name**|**Valid**|
|0\newline{}1\newline{}2\newline{}3\newline{}4\newline{}5\newline{}6\newline{}7\newline{}8\newline{}9\newline{}A\newline{}B\newline{}C\newline{}D\newline{}E\newline{}F|Reserved\newline{}Available 16-bit TSS\newline{}LDT\newline{}Busy 16-bit TSS\newline{}16-bit call gate\newline{}16-bit/32-bit task gate\newline{}16-bit interrupt gate\newline{}16-bit trap gate\newline{}Reserved\newline{}Available 32-bit TSS\newline{}Reserved\newline{}Busy 32-bit TSS\newline{}32-bit call gate\newline{}Reserved\newline{}32-bit interrupt gate\newline{}32-bit trap gate|No\newline{}Yes\newline{}Yes\newline{}Yes\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}Yes\newline{}No\newline{}Yes\newline{}No\newline{}No\newline{}No\newline{}No|Upper 8 byte of a 16-Byte descriptor\newline{}Reserved\newline{}LDT\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}Reserved\newline{}64-bit TSS\newline{}Reserved\newline{}Busy 64-bit TSS\newline{}64-bit call gate\newline{}Reserved\newline{}64-bit interrupt gate\newline{}64-bit trap gate|Yes\newline{}No\newline{}Yes\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}No\newline{}Yes\newline{}No\newline{}Yes\newline{}No\newline{}No\newline{}No\newline{}No|

### Operation

```info-verb
IF SRC(Offset) > descriptor table limit
 THEN ZF <- 0; FI;
Read segment descriptor;
IF SegmentDescriptor(Type) != conforming code segment
and (CPL > DPL) OR (RPL > DPL)
or Segment type is not valid for instruction
   THEN
    ZF <- 0;
   ELSE
    temp <- SegmentLimit([SRC]);
    IF (G <- 1)
      THEN temp <- ShiftLeft(12, temp) OR 00000FFFH;
    ELSE IF OperandSize = 32 
      THEN DEST <- temp; FI;
    ELSE IF OperandSize = 64 (\htmlonly{*} REX.W used \htmlonly{*})
      THEN DEST (\htmlonly{*} Zero-extended \htmlonly{*}) <- temp; FI;
    ELSE (\htmlonly{*} OperandSize = 16 \htmlonly{*})
      DEST <- temp AND FFFFH;
    FI;
FI;
```
### Flags Affected


The ZF flag is set to 1 if the segment limit is loaded successfully; otherwise, it is set to 0.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and the memory operand effective address is unaligned while the current privilege level is 3. 

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* The LSL instruction cannot be executed in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The LSL instruction cannot be executed in virtual-8086 mode.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If the memory operand effective address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory operand effective address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and the memory operand effective address is unaligned while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
