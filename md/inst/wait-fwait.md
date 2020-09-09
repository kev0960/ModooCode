----------------------------
title : WAIT, FWAITs (Intel x86/64 assembly instruction)
cat_title : WAIT, FWAIT
ref_title : WAIT, FWAIT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/W
publish_date: 2020-09-01
----------------------------


#@ WAIT, FWAIT

**Wait**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|9B|WAIT|NP|Valid|Valid|Check pending unmasked floating-point exceptions.|
|9B|FWAIT|NP|Valid|Valid|Check pending unmasked floating-point exceptions.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Causes the processor to check for and handle pending, unmasked, floating-point exceptions before proceeding. (FWAIT is an alternate mnemonic for `WAIT`.)

This instruction is useful for synchronizing exceptions in critical sections of code. Coding a `WAIT` instruction after a floating-point instruction ensures that any unmasked floating-point exceptions the instruction may raise are handled before the processor can modify the instruction's results. See the section titled "Floating-Point Exception Synchronization" in Chapter 8 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for more information on using the WAIT/FWAIT instruction.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
CheckForPendingUnmaskedFloatingPointExceptions;
```
### FPU Flags Affected


The C0, C1, C2, and C3 flags are undefined.

### Floating-Point Exceptions


None. 


### Protected Mode Exceptions

#### #NM
* If CR0.MP[bit 1] = 1 and CR0.TS[bit 3] = 1.

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

