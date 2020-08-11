----------------------------
title : POP instruction(Intel x86/64 assembly instruction)
cat_title : POP
----------------------------
### POP--Pop a Value from the Stack


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|8F /0|POP r/m16|M|Valid|Valid|Pop top of stack into m16; increment stack pointer.|
|8F /0|POP r/m32|M|N.E.|Valid|Pop top of stack into m32; increment stack pointer.|
|8F /0|POP r/m64|M|Valid|N.E.|Pop top of stack into m64; increment stack pointer. Cannot encode 32-bit operand size.|
|58+ rw|POP r16|O|Valid|Valid|Pop top of stack into r16; increment stack pointer.|
|58+ rd|POP r32|O|N.E.|Valid|Pop top of stack into r32; increment stack pointer.|
|58+ rd|POP r64|O|Valid|N.E.|Pop top of stack into r64; increment stack pointer. Cannot encode 32-bit operand size.|
|1F|POP DS|NP|Invalid|Valid|Pop top of stack into DS; increment stack pointer.|
|07|POP ES|NP|Invalid|Valid|Pop top of stack into ES; increment stack pointer.|
|17|POP SS|NP|Invalid|Valid|Pop top of stack into SS; increment stack pointer.|
|0F A1|POP FS |NP|Valid|Valid|Pop top of stack into FS; increment stack pointer by 16 bits. |
|0F A1|POP FS |NP|N.E.|Valid|Pop top of stack into FS; increment stack pointer by 32 bits. |
|0F A1|POP FS |NP|Valid|N.E.|Pop top of stack into FS; increment stack pointer by 64 bits. |
|0F A9|POP GS |NP|Valid|Valid|Pop top of stack into GS; increment stack pointer by 16 bits. |
|0F A9|POP GS |NP|N.E.|Valid|Pop top of stack into GS; increment stack pointer by 32 bits. |
|0F A9|POP GS |NP|Valid|N.E.|Pop top of stack into GS; increment stack pointer by 64 bits. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
|O|opcode + rd (w)|NA|NA|NA|
|NP|NA|NA|NA|NA|
### Description


Loads the value from the top of the stack to the location specified with the destination operand (or explicit opcode) and then increments the stack pointer. The destination operand can be a general-purpose register, memory loca-tion, or segment register.

Address and operand sizes are determined and used as follows:

*  Address size. The D flag in the current code-segment descriptor determines the default address size; it may be overridden by an instruction prefix (67H).



The address size is used only when writing to a destination operand in memory.

*  Operand size. The D flag in the current code-segment descriptor determines the default operand size; it may be overridden by instruction prefixes (66H or REX.W).

 The operand size (16, 32, or 64 bits) determines the amount by which the stack pointer is incremented (2, 4or 8).

*  Stack-address size. Outside of 64-bit mode, the B flag in the current stack-segment descriptor determines the size of the stack pointer (16 or 32 bits); in 64-bit mode, the size of the stack pointer is always 64 bits.

 The stack-address size determines the width of the stack pointer when reading from the stack in memory andwhen incrementing the stack pointer. (As stated above, the amount by which the stack pointer is incrementedis determined by the operand size.)

If the destination operand is one of the segment registers DS, ES, FS, GS, or SS, the value loaded into the register must be a valid segment selector. In protected mode, popping a segment selector into a segment register automat-ically causes the descriptor information associated with that segment selector to be loaded into the hidden (shadow) part of the segment register and causes the selector and the descriptor information to be validated (see the "Operation" section below).

A NULL value (0000-0003) may be popped into the DS, ES, FS, or GS register without causing a general protection fault. However, any subsequent attempt to reference a segment whose corresponding segment register is loaded with a NULL value causes a general protection exception (#GP). In this situation, no memory reference occurs and the saved value of the segment register is NULL.

The POP instruction cannot pop a value into the CS register. To load the CS register from the stack, use the RET instruction.

If the ESP register is used as a base register for addressing a destination operand in memory, the POP instruction computes the effective address of the operand after it increments the ESP register. For the case of a 16-bit stack where ESP wraps to 0H as a result of the POP instruction, the resulting location of the memory write is processor-family-specific.

The POP ESP instruction increments the stack pointer (ESP) before data at the old top of stack is written into the destination.

A POP SS instruction inhibits all interrupts, including the NMI interrupt, until after execution of the next instruction. This action allows sequential execution of POP SS and MOV ESP, EBP instructions without the danger of having an invalid stack during an interrupt\footnote{1} . However, use of the LSS instruction is the preferred method of loading the SS and ESP registers.

In 64-bit mode, using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). When in 64-bit mode, POPs using 32-bit operands are not encodable and POPs to DS, ES, SS are not valid. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
IF StackAddrSize = 32
 THEN
   IF OperandSize = 32
    THEN
      DEST <- SS:ESP; (\htmlonly{*} Copy a doubleword \htmlonly{*})
      ESP <- ESP + 4;
    ELSE (\htmlonly{*} OperandSize = 16\htmlonly{*})
      DEST <- SS:ESP; (\htmlonly{*} Copy a word \htmlonly{*})
1.If a code instruction breakpoint (for debug) is placed on an instruction located immediately after a POP SS instruction, the breakpoint may not be triggered. However, in a sequence of instructions that POP the SS register, only the first instruction in the sequence is guaranteed to delay an interrupt.
 In the following sequence, interrupts may be recognized before POP ESP executes:
 POP SSPOP SSPOP ESP
ESP <- ESP + 2;
   FI;
 ELSE IF StackAddrSize = 64
   THEN
    IF OperandSize = 64
      THEN
        DEST <- SS:RSP; (* Copy quadword *)
        RSP <- RSP + 8;
      ELSE (* OperandSize = 16*)
        DEST <- SS:RSP; (* Copy a word *)
        RSP <- RSP + 2;
    FI;
   FI;
 ELSE StackAddrSize = 16
   THEN
    IF OperandSize = 16
      THEN
        DEST <- SS:SP; (* Copy a word *)
        SP <- SP + 2;
      ELSE (* OperandSize = 32 *)
        DEST <- SS:SP; (* Copy a doubleword *)
        SP <- SP + 4;
    FI;
FI;
Loading a segment register while in protected mode results in special actions, as described in the following listing. These checks are performed on the segment selector and the segment descriptor it points to.
64-BIT_MODE
IF FS, or GS is loaded with non-NULL selector;
 THEN
   IF segment selector index is outside descriptor table limits
    OR segment is not a data or readable code segment
    OR ((segment is a data or nonconforming code segment)
      AND (both RPL and CPL > DPL))
        THEN #GP(selector);
    IF segment not marked present
      THEN #NP(selector);
   ELSE
    SegmentRegister <- segment selector;
    SegmentRegister <- segment descriptor;
   FI;
FI;
IF FS, or GS is loaded with a NULL selector;
   THEN
    SegmentRegister <- segment selector;
    SegmentRegister <- segment descriptor;
FI;
PREOTECTED MODE OR COMPATIBILITY MODE;
IF SS is loaded;
THEN
   IF segment selector is NULL
    THEN #GP(0); 
   FI;
   IF segment selector index is outside descriptor table limits 
    or segment selector's RPL != CPL
    or segment is not a writable data segment
    or DPL != CPL
      THEN #GP(selector); 
   FI;
   IF segment not marked present 
    THEN #SS(selector); 
    ELSE
      SS <- segment selector;
      SS <- segment descriptor; 
   FI;
FI;
IF DS, ES, FS, or GS is loaded with non-NULL selector;
 THEN
   IF segment selector index is outside descriptor table limits
    or segment is not a data or readable code segment
    or ((segment is a data or nonconforming code segment)
    and (both RPL and CPL > DPL))
      THEN #GP(selector); 
   FI;
   IF segment not marked present
    THEN #NP(selector);
    ELSE
      SegmentRegister <- segment selector;
      SegmentRegister <- segment descriptor;
    FI;
FI;
IF DS, ES, FS, or GS is loaded with a NULL selector
 THEN
   SegmentRegister <- segment selector;
   SegmentRegister <- segment descriptor;
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If attempt is made to load SS register with NULL segment selector.
* If the destination operand is in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #GP(selector)
* If segment selector index is outside descriptor table limits. 
* If the SS register is being loaded and the segment selector's RPL and the segment descriptor's DPL are not equal to the CPL. 
* If the SS register is being loaded and the segment pointed to is anon-writable data segment.
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is not a data or readable code segment.
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is a data or nonconforming code segment, but both the RPL and the CPL are greater than the DPL.

#### #SS(0)
* If the current top of stack is not within the stack segment.
* If a memory operand effective address is outside the SS segment limit.

#### #SS(selector)
* If the SS register is being loaded and the segment pointed to is marked not present.

#### #NP
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is marked not present.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same as for protected mode exceptions.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #GP(selector)
* If the descriptor is outside the descriptor table limit.
* If the FS or GS register is being loaded and the segment pointed to is not a data or readable code segment.
* If the FS or GS register is being loaded and the segment pointed to is a data or nonconforming code segment, but both the RPL and the CPL are greater than the DPL.

#### #AC(0)
* If an unaligned memory reference is made while alignment checking is enabled.

#### #PF(fault-code)
* If a page fault occurs.

#### #NP
* If the FS or GS register is being loaded and the segment pointed to is marked not present.

#### #UD
* If the LOCK prefix is used.
