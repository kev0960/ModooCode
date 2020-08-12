----------------------------
title : FINCSTP (Intel x86/64 assembly instruction)
cat_title : FINCSTP
ref_title : FINCSTP
path : /X86-64 명령어 레퍼런스
----------------------------
#@ FINCSTP

**Increment Stack-Top Pointer**

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 F7|FINCSTP|Valid|Valid|Increment the TOP field in the FPU status register.|
### Description


Adds one to the TOP field of the FPU status word (increments the top-of-stack pointer). If the TOP field contains a 7, it is set to 0. The effect of this instruction is to rotate the stack by one position. The contents of the FPU data registers and tag register are not affected. This operation is not equivalent to popping the stack, because the tag for the previous top-of-stack register is not marked empty.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF TOP = 7
    THEN TOP <- 0;
    ELSE TOP <- TOP + 1;
FI;
```
### FPU Flags Affected


The C1 flag is set to 0. The C0, C2, and C3 flags are undefined.

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

