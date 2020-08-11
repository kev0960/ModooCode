----------------------------
title : RDPKRU instruction(Intel x86/64 assembly instruction)
cat_title : RDPKRU
----------------------------
### RDPKRU--Read Protection Key Rights for User Pages


|**Opcode***|**Instruction**|**Op/ **\newline{}**En**|**64/32bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|-----------|---------------|------------------------|-----------------------------------------------------|--------------------------------------------------|---------------|
|0F 01 EE|RDPKRU|NP|V/V|OSPKE|Reads PKRU into EAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Reads the value of PKRU into EAX and clears EDX. ECX must be 0 when RDPKRU is executed; otherwise, a general-protection exception (#GP) occurs.

RDPKRU can be executed only if CR4.PKE= 1; otherwise, an invalid-opcode exception (#UD) occurs. Software can discover the value of CR4.PKE by examining CPUID.(EAX=07H,ECX=0H):ECX.OSPKE [bit 4].

On processors that support the Intel64 Architecture, the high-order 32-bits of RCX are ignored and the high-order 32-bits of RDX and RAX are cleared.


### Operation

```info-verb
IF (ECX = 0) 
 THEN
   EAX <- PKRU;
   EDX <- 0;
 ELSE #GP(0); 
FI;
```
### Flags Affected


None.

### C/C++ Compiler Intrinsic Equivalent


RDPKRU: uint32_t _rdpkru_u32(void);


### Protected Mode Exceptions

#### #GP(0)
* If ECX >=B 0 

#### #UD
* If the LOCK prefix is used.
* If CR4.PKE = 0.

### Real-Address Mode Exceptions



Same exceptions as in protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

