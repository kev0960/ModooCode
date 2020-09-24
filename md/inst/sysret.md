----------------------------
title : SYSRET (Intel x86/64 assembly instruction)
cat_title : SYSRET
ref_title : SYSRET
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SYSRET

**Return From Fast System Call**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 07|`SYSRET` |NP|Valid|Invalid|Return to compatibility mode from fast system call |
|REX.W + 0F 07|`SYSRET` |NP|Valid|Invalid|Return to 64-bit mode from fast system call |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


SYSRET is a companion instruction to the `SYSCALL` instruction. It returns from an OS system-call handler to user code at privilege level 3. It does so by loading RIP from RCX and loading RFLAGS from R11.\footnote{1}  With a 64-bit operand size, `SYSRET` remains in 64-bit mode; otherwise, it enters compatibility mode and only the low 32 bits of the regis-ters are loaded.

SYSRET loads the CS and SS selectors with values derived from bits 63:48 of the IA32\esc{_}STAR MSR. However, the CS and SS descriptor caches are not loaded from the descriptors (in GDT or LDT) referenced by those selectors. Instead, the descriptor caches are loaded with fixed values. See the Operation section for details. It is the respon-sibility of OS software to ensure that the descriptors (in GDT or LDT) referenced by those selector values corre-spond to the fixed values loaded into the descriptor caches; the `SYSRET` instruction does not ensure this correspondence.

The `SYSRET` instruction does not modify the stack pointer (ESP or RSP). For that reason, it is necessary for software to switch to the user stack. The OS may load the user stack pointer (if it was saved after SYSCALL) before executing SYSRET; alternatively, user code may load the stack pointer (if it was saved before SYSCALL) after receiving control from `SYSRET`.

If the OS loads the stack pointer before executing `SYSRET`, it must ensure that the handler of any interrupt or exception delivered between restoring the stack pointer and successful execution of `SYSRET` is not invoked with the user stack. It can do so using approaches such as the following:

*  External interrupts. The OS can prevent an external interrupt from being delivered by clearing EFLAGS.IF before loading the user stack pointer.

*  Nonmaskable interrupts (NMIs). The OS can ensure that the NMI handler is invoked with the correct stack by using the interrupt stack table (IST) mechanism for gate 2 (NMI) in the IDT (see Section 6.14.5, "Interrupt Stack Table," in Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A).

*  General-protection exceptions (#GP). The `SYSRET` instruction generates #GP(0) if the value of RCX is not canonical. The OS can address this possibility using one or more of the following approaches:

     -- Confirming that the value of RCX is canonical before executing `SYSRET`.

     -- Using paging to ensure that the `SYSCALL` instruction will never save a non-canonical value into RCX.

     -- Using the IST mechanism for gate 13 (#GP) in the IDT.


### Operation

```info-verb
IF (CS.L != 1 ) or (IA32_EFER.LMA != 1) or (IA32_EFER.SCE != 1)(* Not in 64-Bit Mode or SYSCALL/SYSRET not enabled in IA32_EFER *)
    THEN #UD; FI;
IF (CPL != 0) OR (RCX is not canonical) THEN #GP(0); FI;
```
```sidenote


1. Regardless of the value of R11, the RF and VM flags are always 0 in RFLAGS after execution of SYSRET. In addition, all reserved bits in RFLAGS retain the fixed values.
```

IF (operand size is 64-bit) 

    THEN (\htmlonly{*} Return to 64-Bit Mode \htmlonly{*})

          RIP <- RCX;

    ELSE (\htmlonly{*} Return to Compatibility Mode \htmlonly{*})

          RIP <- ECX;

FI;

RFLAGS <- (R11 & 3C7FD7H) | 2; (\htmlonly{*} Clear RF, VM, reserved bits; set bit 2 \htmlonly{*})

IF (operand size is 64-bit) 

    THEN CS.Selector <- IA32_STAR[63:48]+16;

    ELSE CS.Selector <- IA32_STAR[63:48];

FI;

CS.Selector <- CS.Selector OR 3; (\htmlonly{*} RPL forced to 3 \htmlonly{*})

(\htmlonly{*} Set rest of CS to a fixed value \htmlonly{*})

CS.Base <- 0; (\htmlonly{*} Flat segment \htmlonly{*})

CS.Limit <- FFFFFH; (\htmlonly{*} With 4-KByte granularity, implies a 4-GByte limit \htmlonly{*})

CS.Type <- 11; (\htmlonly{*} Execute/read code, accessed \htmlonly{*})

CS.S <- 1;

CS.DPL <- 3;

CS.P <- 1;

IF (operand size is 64-bit) 

    THEN (\htmlonly{*} Return to 64-Bit Mode \htmlonly{*})

          CS.L <- 1; (\htmlonly{*} 64-bit code segment \htmlonly{*})

          CS.D <- 0; (\htmlonly{*} Required if CS.L = 1 \htmlonly{*})

    ELSE (\htmlonly{*} Return to Compatibility Mode \htmlonly{*})

          CS.L <- 0; (\htmlonly{*} Compatibility mode \htmlonly{*})

          CS.D <- 1; (\htmlonly{*} 32-bit code segment \htmlonly{*})

FI;

CS.G <- 1; (\htmlonly{*} 4-KByte granularity \htmlonly{*})

CPL <- 3;

SS.Selector <- (IA32_STAR[63:48]+8) OR 3; (\htmlonly{*} RPL forced to 3 \htmlonly{*})

(\htmlonly{*} Set rest of SS to a fixed value \htmlonly{*})

SS.Base <- 0; (\htmlonly{*} Flat segment \htmlonly{*})

SS.Limit <- FFFFFH; (\htmlonly{*} With 4-KByte granularity, implies a 4-GByte limit \htmlonly{*})

SS.Type <- 3; (\htmlonly{*} Read/write data, accessed \htmlonly{*})

SS.S <- 1;

SS.DPL <- 3;

SS.P <- 1;

SS.B <- 1; (\htmlonly{*} 32-bit stack segment\htmlonly{*})

SS.G <- 1; (\htmlonly{*} 4-KByte granularity \htmlonly{*})

### Flags Affected


All.


### Protected Mode Exceptions

#### #UD
* The SYSRET instruction is not recognized in protected mode.

### Real-Address Mode Exceptions

#### #UD
* The SYSRET instruction is not recognized in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The SYSRET instruction is not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions

#### #UD
* The SYSRET instruction is not recognized in compatibility mode.

### 64-Bit Mode Exceptions

#### #UD
* If IA32_EFER.SCE = 0.
* If the LOCK prefix is used.

#### #GP(0)
* If CPL != 0.
* If RCX contains a non-canonical address.
