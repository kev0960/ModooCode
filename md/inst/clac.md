----------------------------
title : CLAC (Intel x86/64 assembly instruction)
cat_title : CLAC
ref_title : CLAC
path : /X86-64 명령어 레퍼런스
----------------------------
#@ CLAC

**Clear AC Flag in EFLAGS Register**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 01 CA\newline{}\newline{}CLAC|NP|V/V|SMAP|Clear the AC flag in the EFLAGS register.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Clears the AC flag bit in EFLAGS register. This disables any alignment checking of user-mode data accesses. If the SMAP bit is set in the CR4 register, this disallows explicit supervisor-mode data accesses to user-mode pages.

This instruction's operation is the same in non-64-bit modes and 64-bit mode. Attempts to execute `CLAC` when CPL > 0 cause #UD.


### Operation

```info-verb
EFLAGS.AC <- 0;
```
### Flags Affected


AC cleared. Other flags are unaffected.


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the CPL > 0.
* If CPUID.(EAX=07H, ECX=0H):EBX.SMAP[bit 20] = 0.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.SMAP[bit 20] = 0.

### Virtual-8086 Mode Exceptions

#### #UD
* The CLAC instruction is not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the CPL > 0.
* If CPUID.(EAX=07H, ECX=0H):EBX.SMAP[bit 20] = 0.

### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the CPL > 0.
* If CPUID.(EAX=07H, ECX=0H):EBX.SMAP[bit 20] = 0.
