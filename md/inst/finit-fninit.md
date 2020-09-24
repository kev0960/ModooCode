----------------------------
title : FINIT, FNINITs (Intel x86/64 assembly instruction)
cat_title : FINIT, FNINIT
ref_title : FINIT, FNINIT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FINIT, FNINIT

**Initialize Floating-Point Unit**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|9B DB E3|`FINIT` |Valid|Valid|Initialize FPU after checking for pending unmasked floating-point exceptions.|
|DB E3|FNINIT\footnote{*} |Valid|Valid|Initialize FPU without checking for pending unmasked floating-point exceptions.|

```note
\htmlonly{*} See IA-32 Architecture Compatibility section below
```
### Description


Sets the FPU control, status, tag, instruction pointer, and data pointer registers to their default states. The FPU control word is set to 037FH (round to nearest, all exceptions masked, 64-bit precision). The status word is cleared (no exception flags set, TOP is set to 0). The data registers in the register stack are left unchanged, but they are all tagged as empty (11B). Both the instruction and data pointers are cleared.

The `FINIT` instruction checks for and handles any pending unmasked floating-point exceptions before performing the initialization; the `FNINIT` instruction does not.

The assembler issues two instructions for the `FINIT` instruction (an `FWAIT` instruction followed by an `FNINIT` instruction), and the processor executes each of these instructions in separately. If an exception is generated for either of these instructions, the save EIP points to the instruction that caused the exception.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### IA-32 Architecture Compatibility


When operating a Pentium or Intel486 processor in MS-DOS compatibility mode, it is possible (under unusual circumstances) for an FNINIT instruction to be interrupted prior to being executed to handle a pending FPU excep-tion. See the section titled "No-Wait FPU Instructions Can Get FPU Interrupt in Window" in Appendix D of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for a description of these circumstances. An FNINIT instruction cannot be interrupted in this way on later Intel processors, except for the Intel Quark\footnote{TM}  X1000 processor.

In the Intel387 math coprocessor, the FINIT/FNINIT instruction does not clear the instruction and data pointers.

This instruction affects only the x87 FPU. It does not affect the XMM and MXCSR registers.


### Operation

```info-verb
FPUControlWord <- 037FH;
FPUStatusWord <- 0;
FPUTagWord <- FFFFH;
FPUDataPointer <- 0;
FPUInstructionPointer <- 0;
FPULastInstructionOpcode <- 0;
```
### FPU Flags Affected


C0, C1, C2, C3 set to 0.

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

