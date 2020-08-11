----------------------------
title : XABORT instruction(Intel x86/64 assembly instruction)
cat_title : XABORT
----------------------------
### XABORT -- Transactional Abort


|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|-----------------------------------------------------|--------------------------------------------------|---------------|
|C6 F8 ibXABORT imm8|A|V/V|RTM|Causes an RTM abort if in RTM execution|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|Operand3|Operand4|
|-----|---------|--------|--------|--------|
|A|imm8|NA|NA|NA|
### Description


XABORT forces an RTM abort. Following an RTM abort, the logical processor resumes execution at the fallback address computed through the outermost XBEGIN instruction. The EAX register is updated to reflect an XABORT instruction caused the abort, and the imm8 argument will be provided in bits 31:24 of EAX. 


### Operation
#### XABORT
```info-verb
IF RTM_ACTIVE = 0
 THEN 
   Treat as NOP;
 ELSE
   GOTO RTM_ABORT_PROCESSING;
FI;
(\htmlonly{*} For any RTM abort condition encountered during RTM execution \htmlonly{*})
RTM_ABORT_PROCESSING:
 Restore architectural register state;
 Discard memory updates performed in transaction;
 Update EAX with status and XABORT argument;
 RTM_NEST_COUNT <- 0;
 RTM_ACTIVE <- 0;
 IF 64-bit Mode
   THEN
    RIP <- fallbackRIP;
   ELSE
    EIP <- fallbackEIP;
 FI;
END
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XABORT: void _xabort( unsigned int);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


#UD CPUID.(EAX=7, ECX=0):EBX.RTM[bit 11] = 0.

         If LOCK prefix is used.

