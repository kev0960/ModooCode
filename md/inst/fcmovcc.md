----------------------------
title : FCMOVcc (Intel x86/64 assembly instruction)
cat_title : FCMOVcc
ref_title : FCMOVcc
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FCMOVcc

**Floating-Point Conditional Move**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode\htmlonly{*}**|**Description**|
|----------------------|---------------|-----------------------------|---------------------------------------------|---------------|
|DA C0+i|FCMOVB \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if below (CF=1).|
|DA C8+i|FCMOVE \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if equal (ZF=1).|
|DA D0+i|FCMOVBE \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if below or equal (CF=1 or ZF=1).|
|DA D8+i|FCMOVU \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if unordered (PF=1).|
|DB C0+i|FCMOVNB \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if not below (CF=0).|
|DB C8+i|FCMOVNE \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if not equal (ZF=0).|
|DB D0+i|FCMOVNBE \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if not below or equal (CF=0 and ZF=0).|
|DB D8+i|FCMOVNU \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Move if not unordered (PF=0).|

```note
\htmlonly{*} See IA-32 Architecture Compatibility section below
```
### Description


Tests the status flags in the EFLAGS register and moves the source operand (second operand) to the destination operand (first operand) if the given test condition is true. The condition for each mnemonic os given in the Descrip-tion column above and in Chapter 8 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1. The source operand is always in the ST(i) register and the destination operand is always ST(0).

The `FCMOVcc` instructions are useful for optimizing small IF constructions. They also help eliminate branching overhead for IF operations and the possibility of branch mispredictions by the processor. 

A processor may not support the `FCMOVcc` instructions. Software can check if the `FCMOVcc` instructions are supported by checking the processor's feature information with the `CPUID` instruction (see "COMISS--Compare Scalar Ordered Single-Precision Floating-Point Values and Set EFLAGS" in this chapter). If both the CMOV and FPU feature bits are set, the `FCMOVcc` instructions are supported.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### IA-32 Architecture Compatibility


The FCMOVcc instructions were introduced to the IA-32 Architecture in the P6 family processors and are not avail-able in earlier IA-32 processors.


### Operation

```info-verb
IF condition TRUE
    THEN ST(0) <- ST(i);
FI;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

### Integer Flags Affected


None.


### Protected Mode Exceptions

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

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

