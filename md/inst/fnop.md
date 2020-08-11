----------------------------
title : FNOP instruction(Intel x86/64 assembly instruction)
cat_title : FNOP
----------------------------
### FNOP--No Operation


|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 D0|FNOP|Valid|Valid|No operation is performed.|
### Description


Performs no FPU operation. This instruction takes up space in the instruction stream but does not affect the FPU or machine context, except the EIP register and the FPU Instruction Pointer.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### FPU Flags Affected


C0, C1, C2, C3 undefined.

### Floating-Point Exceptions


None


### Protected Mode Exceptions

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #MF
* If there is a pending x87 FPU exception.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions



Same exceptions as in protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

