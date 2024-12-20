----------------------------
title : WRMSR (Intel x86/64 assembly instruction)
cat_title : WRMSR
ref_title : WRMSR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/W
publish_date: 2020-09-01
----------------------------


#@ WRMSR

**Write to Model Specific Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 30|`WRMSR` |NP|Valid |Valid|Write the value in EDX:EAX to MSR specified by ECX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Writes the contents of registers EDX:EAX into the 64-bit model specific register (MSR) specified in the ECX register. (On processors that support the Intel 64 architecture, the high-order 32 bits of RCX are ignored.) The contents of the EDX register are copied to high-order 32 bits of the selected MSR and the contents of the EAX register are copied to low-order 32 bits of the MSR. (On processors that support the Intel 64 architecture, the high-order 32 bits of each of RAX and RDX are ignored.) Undefined or reserved bits in an MSR should be set to values previously read.

This instruction must be executed at privilege level 0 or in real-address mode; otherwise, a general protection exception #GP(0) is generated. Specifying a reserved or unimplemented MSR address in ECX will also cause a general protection exception. The processor will also generate a general protection exception if software attempts to write to bits in a reserved MSR.

When the `WRMSR` instruction is used to write to an MTRR, the TLBs are invalidated. This includes global entries (see "Translation Lookaside Buffers (TLBs)" in Chapter 3 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A).

MSRs control functions for testability, execution tracing, performance-monitoring and machine check errors. Chapter 35, "Model-Specific Registers (MSRs)", in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3C, lists all MSRs that can be written with this instruction and their addresses. Note that each processor family has its own set of MSRs.

The `WRMSR` instruction is a serializing instruction (see "Serializing Instructions" in Chapter 8 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A). Note that `WRMSR` to the IA32\esc{_}TSC\esc{_}DEADLINE MSR (MSR index 6E0H) and the X2APIC MSRs (MSR indices 802H to 83FH) are not serializing.

The `CPUID` instruction should be used to determine whether MSRs are supported (CPUID.01H:EDX[5] = 1) before using this instruction.

### IA-32 Architecture Compatibility


The MSRs and the ability to read them with the WRMSR instruction were introduced into the IA-32 architecture with the Pentium processor. Execution of this instruction by an IA-32 processor earlier than the Pentium processor results in an invalid opcode exception #UD.


### Operation

```info-verb
MSR[ECX] <- EDX:EAX;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If the value in ECX specifies a reserved or unimplemented MSR address.
* If the value in EDX:EAX sets bits that are reserved in the MSR specified by ECX.
* If the source register contains a non-canonical address and ECX specifies one of the following MSRs: IA32_DS_AREA, IA32_FS_BASE, IA32_GS_BASE, IA32_KERNEL_GS_BASE, IA32_LSTAR, IA32_SYSENTER_EIP, IA32_SYSENTER_ESP.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If the value in ECX specifies a reserved or unimplemented MSR address.
* If the value in EDX:EAX sets bits that are reserved in the MSR specified by ECX.
* If the source register contains a non-canonical address and ECX specifies one of the following MSRs: IA32_DS_AREA, IA32_FS_BASE, IA32_GS_BASE, IA32_KERNEL_GS_BASE, IA32_LSTAR, IA32_SYSENTER_EIP, IA32_SYSENTER_ESP.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* The WRMSR instruction is not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

