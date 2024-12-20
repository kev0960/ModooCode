----------------------------
title : XEND (Intel x86/64 assembly instruction)
cat_title : XEND
ref_title : XEND
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/X
publish_date: 2020-09-01
----------------------------


#@ XEND

** Transactional End**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|-----------------------------------------------------|--------------------------------------------------|---------------|
|`0F 01 D5`\newline{}`XEND` |A|V/V|RTM|Specifies the end of an RTM code region.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|Operand3|Operand4|
|-----|---------|--------|--------|--------|
|A|NA|NA|NA|NA|
### Description


The instruction marks the end of an RTM code region. If this corresponds to the outermost scope (that is, including this `XEND` instruction, the number of `XBEGIN` instructions is the same as number of `XEND` instructions), the logical processor will attempt to commit the logical processor state atomically. If the commit fails, the logical processor will rollback all architectural register and memory updates performed during the RTM execution. The logical processor will resume execution at the fallback address computed from the outermost `XBEGIN` instruction. The EAX register is updated to reflect RTM abort information.

XEND executed outside a transactional region will cause a #GP (General Protection Fault). 


### Operation
#### XEND
```info-verb
IF (RTM_ACTIVE = 0) THEN
    SIGNAL #GP
ELSE
    RTM_NEST_COUNT--
    IF (RTM_NEST_COUNT = 0) THEN
          Try to commit transaction
          IF fail to commit transactional execution
                THEN
                      GOTO RTM_ABORT_PROCESSING;
                ELSE (* commit success *)
                      RTM_ACTIVE <- 0
          FI;
    FI;
FI;
(* For any RTM abort condition encountered during RTM execution *)
RTM_ABORT_PROCESSING:
    Restore architectural register state
    Discard memory updates performed in transaction
    Update EAX with status
    RTM_NEST_COUNT <- 0
    RTM_ACTIVE <- 0
    IF 64-bit Mode
          THEN
                RIP <- fallbackRIP
          ELSE
                EIP <- fallbackEIP
    FI;
END
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XEND: void _xend( void );
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


#UD CPUID.(EAX=7, ECX=0):EBX.RTM[bit 11] = 0.

                              If LOCK or 66H or F2H or F3H prefix is used.

#GP(0) If RTM_ACTIVE = 0.

