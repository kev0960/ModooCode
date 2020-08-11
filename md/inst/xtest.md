----------------------------
title : XTEST instruction(Intel x86/64 assembly instruction)
cat_title : XTEST
----------------------------
### XTEST -- Test If In Transactional Execution


|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|-----------------------------------------------------|--------------------------------------------------|---------------|
|0F 01 D6XTEST|A|V/V|HLE or RTM|Test if executing in a transactional region|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|Operand3|Operand4|
|-----|---------|--------|--------|--------|
|A|NA|NA|NA|NA|
### Description


The XTEST instruction queries the transactional execution status. If the instruction executes inside a transaction-ally executing RTM region or a transactionally executing HLE region, then the ZF flag is cleared, else it is set.


### Operation
#### XTEST
```info-verb
IF (RTM_ACTIVE = 1 OR HLE_ACTIVE = 1)
 THEN
   ZF <- 0
 ELSE
   ZF <- 1
FI;
```
### Flags Affected


The ZF flag is cleared if the instruction is executed transactionally; otherwise it is set to 1. The CF, OF, SF, PF, and AF, flags are cleared.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XTEST: int _xtest( void );
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


#UD CPUID.(EAX=7, ECX=0):HLE[bit 4] = 0 and CPUID.(EAX=7, ECX=0):RTM[bit 11] = 0.

         If LOCK or 66H or F2H or F3H prefix is used.

