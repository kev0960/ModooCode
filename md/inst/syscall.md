----------------------------
title : SYSCALL (Intel x86/64 assembly instruction)
cat_title : SYSCALL
ref_title : SYSCALL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SYSCALL

**Fast System Call**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 05|`SYSCALL` |NP|Valid|Invalid|Fast call to privilege level 0 system procedures.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


SYSCALL invokes an OS system-call handler at privilege level 0. It does so by loading RIP from the IA32\esc{_}LSTAR MSR (after saving the address of the instruction following `SYSCALL` into RCX). (The `WRMSR` instruction ensures that the IA32\esc{_}LSTAR MSR always contain a canonical address.)

SYSCALL also saves RFLAGS into R11 and then masks RFLAGS using the IA32\esc{_}FMASK MSR (MSR address C0000084H); specifically, the processor clears in RFLAGS every bit corresponding to a bit that is set in the IA32\esc{_}FMASK MSR.

SYSCALL loads the CS and SS selectors with values derived from bits 47:32 of the IA32\esc{_}STAR MSR. However, the CS and SS descriptor caches are not loaded from the descriptors (in GDT or LDT) referenced by those selectors. Instead, the descriptor caches are loaded with fixed values. See the Operation section for details. It is the respon-sibility of OS software to ensure that the descriptors (in GDT or LDT) referenced by those selector values corre-spond to the fixed values loaded into the descriptor caches; the `SYSCALL` instruction does not ensure this correspondence.

The `SYSCALL` instruction does not save the stack pointer (RSP). If the OS system-call handler will change the stack pointer, it is the responsibility of software to save the previous value of the stack pointer. This might be done prior to executing `SYSCALL`, with software restoring the stack pointer with the instruction following `SYSCALL` (which will be executed after SYSRET). Alternatively, the OS system-call handler may save the stack pointer and restore it before executing `SYSRET`.


### Operation

```info-verb
IF (CS.L != 1 ) or (IA32_EFER.LMA != 1) or (IA32_EFER.SCE != 1)(* Not in 64-Bit Mode or SYSCALL/SYSRET not enabled in IA32_EFER *)
    THEN #UD;
FI;
RCX <- RIP; (* Will contain address of next instruction *)
RIP <- IA32_LSTAR;
R11 <- RFLAGS;
RFLAGS <- RFLAGS AND NOT(IA32_FMASK);
CS.Selector <- IA32_STAR[47:32] AND FFFCH(* Operating system provides CS; RPL forced to 0 *)
(* Set rest of CS to a fixed value *)
CS.Base <- 0; (* Flat segment *)
CS.Limit <- FFFFFH; (* With 4-KByte granularity, implies a 4-GByte limit *)
CS.Type <- 11; (* Execute/read code, accessed *)
CS.S <- 1;
CS.DPL <- 0;
CS.P <- 1;
CS.L <- 1; (* Entry is to 64-bit mode *)
CS.D <- 0; (* Required if CS.L = 1 *)
CS.G <- 1; (* 4-KByte granularity *)
CPL <- 0;
SS.Selector <- IA32_STAR[47:32] + 8; (* SS just above CS *)
(* Set rest of SS to a fixed value *)
SS.Base <- 0; (* Flat segment *)
SS.Limit <- FFFFFH; (* With 4-KByte granularity, implies a 4-GByte limit *)
SS.Type <- 3; (* Read/write data, accessed *)
SS.S <- 1;
SS.DPL <- 0;
SS.P <- 1;
SS.B <- 1; (* 32-bit stack segment *)
SS.G <- 1; (* 4-KByte granularity *)
```
### Flags Affected


All.


### Protected Mode Exceptions

#### #UD
* The SYSCALL instruction is not recognized in protected mode.

### Real-Address Mode Exceptions

#### #UD
* The SYSCALL instruction is not recognized in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The SYSCALL instruction is not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions

#### #UD
* The SYSCALL instruction is not recognized in compatibility mode.

### 64-Bit Mode Exceptions

#### #UD
* If IA32_EFER.SCE = 0.
* If the LOCK prefix is used.
