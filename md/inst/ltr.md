----------------------------
title : LTR (Intel x86/64 assembly instruction)
cat_title : LTR
ref_title : LTR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LTR

**Load Task Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 00 /3|LTR r/m16|M|Valid|Valid|Load r/m16 into task register.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Loads the source operand into the segment selector field of the task register. The source operand (a general-purpose register or a memory location) contains a segment selector that points to a task state segment (TSS). After the segment selector is loaded in the task register, the processor uses the segment selector to locate the segment descriptor for the TSS in the global descriptor table (GDT). It then loads the segment limit and base address for the TSS from the segment descriptor into the task register. The task pointed to by the task register is marked busy, but a switch to the task does not occur.

The `LTR` instruction is provided for use in operating-system software; it should not be used in application programs. It can only be executed in protected mode when the CPL is 0. It is commonly used in initialization code to establish the first task to be executed.

The operand-size attribute has no effect on this instruction. 

In 64-bit mode, the operand size is still fixed at 16 bits. The instruction references a 16-byte descriptor to load the 64-bit base.


### Operation

```info-verb
IF SRC is a NULL selectorTHEN #GP(0);
IF SRC(Offset) > descriptor table limit OR IF SRC(type) != global
    THEN #GP(segment selector); FI;
Read segment descriptor;
IF segment descriptor is not for an available TSS 
    THEN #GP(segment selector); FI;
IF segment descriptor is not present 
    THEN #NP(segment selector); FI;
TSSsegmentDescriptor(busy) <- 1; 
(* Locked read-modify-write operation on the entire descriptor when setting busy flag *)
TaskRegister(SegmentSelector) <- SRC;
TaskRegister(SegmentDescriptor) <- TSSSegmentDescriptor;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the source operand contains a NULL segment selector.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #GP(selector)
* If the source selector points to a segment that is not a TSS or to one for a task that is already busy.
* If the selector points to LDT or is beyond the GDT limit.

#### #NP(selector)
* If the TSS is marked not present.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* The LTR instruction is not recognized in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The LTR instruction is not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the current privilege level is not 0.
* If the memory address is in a non-canonical form.
* If the source operand contains a NULL segment selector.

#### #GP(selector)
* If the source selector points to a segment that is not a TSS or to one for a task that is already busy.
* If the selector points to LDT or is beyond the GDT limit.
* If the descriptor type of the upper 8-byte of the 16-byte descriptor is non-zero.

#### #NP(selector)
* If the TSS is marked not present.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.