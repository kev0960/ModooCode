----------------------------
title : SYSENTER instruction(Intel x86/64 assembly instruction)
cat_title : SYSENTER
----------------------------
### SYSENTER--Fast System Call


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 34|SYSENTER|NP|Valid|Valid|Fast call to privilege level 0 system procedures.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Executes a fast call to a level 0 system procedure or routine. SYSENTER is a companion instruction to SYSEXIT. The instruction is optimized to provide the maximum performance for system calls from user code running at privilege level 3 to operating system or executive procedures running at privilege level 0.

When executed in IA-32e mode, the SYSENTER instruction transitions the logical processor to 64-bit mode; other-wise, the logical processor remains in protected mode.

Prior to executing the SYSENTER instruction, software must specify the privilege level 0 code segment and code entry point, and the privilege level 0 stack segment and stack pointer by writing values to the following MSRs:

*  IA32_SYSENTER_CS (MSR address 174H) -- The lower 16 bits of this MSR are the segment selector for the privilege level 0 code segment. This value is also used to determine the segment selector of the privilege level 0 stack segment (see the Operation section). This value cannot indicate a null selector.

*  IA32_SYSENTER_EIP (MSR address 176H) -- The value of this MSR is loaded into RIP (thus, this value references the first instruction of the selected operating procedure or routine). In protected mode, only bits31:0 are loaded.

*  IA32_SYSENTER_ESP (MSR address 175H) -- The value of this MSR is loaded into RSP (thus, this value contains the stack pointer for the privilege level 0 stack). This value cannot represent a non-canonical address. In protected mode, only bits31:0 are loaded.

These MSRs can be read from and written to using RDMSR/WRMSR. The WRMSR instruction ensures that the IA32_SYSENTER_EIP and IA32_SYSENTER_ESP MSRs always contain canonical addresses.

While SYSENTER loads the CS and SS selectors with values derived from the IA32_SYSENTER_CS MSR, the CS and SS descriptor caches are not loaded from the descriptors (in GDT or LDT) referenced by those selectors. Instead, the descriptor caches are loaded with fixed values. See the Operation section for details. It is the responsibility of OS software to ensure that the descriptors (in GDT or LDT) referenced by those selector values correspond to the fixed values loaded into the descriptor caches; the SYSENTER instruction does not ensure this correspondence.

The SYSENTER instruction can be invoked from all operating modes except real-address mode. 

The SYSENTER and SYSEXIT instructions are companion instructions, but they do not constitute a call/return pair. When executing a SYSENTER instruction, the processor does not save state information for the user code (e.g., the instruction pointer), and neither the SYSENTER nor the SYSEXIT instruction supports passing parameters on the stack.

To use the SYSENTER and SYSEXIT instructions as companion instructions for transitions between privilege level 3 code and privilege level 0 operating system procedures, the following conventions must be followed:

*  The segment descriptors for the privilege level 0 code and stack segments and for the privilege level 3 code and stack segments must be contiguous in a descriptor table. This convention allows the processor to compute the segment selectors from the value entered in the SYSENTER_CS_MSR MSR.

*  The fast system call "stub" routines executed by user code (typically in shared libraries or DLLs) must save the required return IP and processor state information if a return to the calling procedure is required. Likewise, the operating system or executive procedures called with SYSENTER instructions must have access to and use this saved return and state information when returning to the user code.



The SYSENTER and SYSEXIT instructions were introduced into the IA-32 architecture in the Pentium II processor. The availability of these instructions on a processor is indicated with the SYSENTER/SYSEXIT present (SEP) feature flag returned to the EDX register by the CPUID instruction. An operating system that qualifies the SEP flag must also qualify the processor family and model to ensure that the SYSENTER/SYSEXIT instructions are actually present. For example:

IF CPUID SEP bit is set

 THEN IF (Family = 6) and (Model < 3) and (Stepping < 3) 

   THEN

    SYSENTER/SYSEXIT_Not_Supported; FI;

   ELSE 

    SYSENTER/SYSEXIT_Supported; FI;

FI;

When the CPUID instruction is executed on the Pentium Pro processor (model 1), the processor returns a the SEP flag as set, but does not support the SYSENTER/SYSEXIT instructions.


### Operation

```info-verb
IF CR0.PE = 0 OR IA32_SYSENTER_CS[15:2] = 0 THEN #GP(0); FI;
RFLAGS.VM <- 0; (\htmlonly{*} Ensures protected mode execution \htmlonly{*})
RFLAGS.IF <- 0; (\htmlonly{*} Mask interrupts \htmlonly{*})
IF in IA-32e mode
 THEN
   RSP <- IA32_SYSENTER_ESP;
   RIP <- IA32_SYSENTER_EIP;
ELSE
   ESP <- IA32_SYSENTER_ESP[31:0];
   EIP <- IA32_SYSENTER_EIP[31:0];
FI;
CS.Selector <- IA32_SYSENTER_CS[15:0] AND FFFCH;
                 (\htmlonly{*} Operating system provides CS; RPL forced to 0 \htmlonly{*})
(\htmlonly{*} Set rest of CS to a fixed value \htmlonly{*})
CS.Base <- 0; (\htmlonly{*} Flat segment \htmlonly{*})
CS.Limit <- FFFFFH; (\htmlonly{*} With 4-KByte granularity, implies a 4-GByte limit \htmlonly{*})
CS.Type <- 11; (\htmlonly{*} Execute/read code, accessed \htmlonly{*})
CS.S <- 1;
CS.DPL <- 0;
CS.P <- 1;
IF in IA-32e mode
 THEN
   CS.L <- 1; (\htmlonly{*} Entry is to 64-bit mode \htmlonly{*})
   CS.D <- 0; (\htmlonly{*} Required if CS.L = 1 \htmlonly{*})
 ELSE
   CS.L <- 0;
   CS.D <- 1; (\htmlonly{*} 32-bit code segment\htmlonly{*})
FI;
CS.G <- 1; (\htmlonly{*} 4-KByte granularity \htmlonly{*})
CPL <- 0;
SS.Selector <- CS.Selector + 8; (\htmlonly{*} SS just above CS \htmlonly{*})
(\htmlonly{*} Set rest of SS to a fixed value \htmlonly{*})
SS.Base <- 0; (\htmlonly{*} Flat segment \htmlonly{*})
SS.Limit <- FFFFFH; (\htmlonly{*} With 4-KByte granularity, implies a 4-GByte limit \htmlonly{*})
SS.Type <- 3; (\htmlonly{*} Read/write data, accessed \htmlonly{*})
SS.S <- 1;
SS.DPL <- 0;
SS.P <- 1;
SS.B <- 1; (* 32-bit stack segment*)
SS.G <- 1; (* 4-KByte granularity *)
```
### Flags Affected


VM, IF (see Operation above)


### Protected Mode Exceptions

#### #GP(0)
* If IA32_SYSENTER_CS[15:2] = 0.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* The SYSENTER instruction is not recognized in real-address mode.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

