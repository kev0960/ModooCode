----------------------------
title : FST, FSTPs (Intel x86/64 assembly instruction)
cat_title : FST, FSTP
ref_title : FST, FSTP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FST, FSTP

**Store Floating Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 /2|`FST` m32fp |Valid|Valid|Copy ST(0) to m32fp.|
|DD /2|`FST` \tooltip{m64fp}{To-m32fp} |Valid|Valid|Copy ST(0) to m64fp.|
|DD D0+i|`FST` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Copy ST(0) to ST(i).|
|D9 /3|`FSTP` m32fp |Valid|Valid|Copy ST(0) to m32fp and pop register stack.|
|DD /3|`FSTP` \tooltip{m64fp}{To-m32fp} |Valid|Valid|Copy ST(0) to m64fp and pop register stack.|
|DB /7|`FSTP` \tooltip{m80fp}{To-m32fp} |Valid|Valid|Copy ST(0) to m80fp and pop register stack.|
|DD D8+i|`FSTP` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Copy ST(0) to ST(i) and pop register stack.|
### Description


The `FST` instruction copies the value in the ST(0) register to the destination operand, which can be a memory loca-tion or another register in the FPU register stack. When storing the value in memory, the value is converted to single-precision or double-precision floating-point format. 

The `FSTP` instruction performs the same operation as the `FST` instruction and then pops the register stack. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. The `FSTP` instruction can also store values in memory in double extended-precision floating-point format.

If the destination operand is a memory location, the operand specifies the address where the first byte of the desti-nation value is to be stored. If the destination operand is a register, the operand specifies a register in the register stack relative to the top of the stack.

If the destination size is single-precision or double-precision, the significand of the value being stored is rounded to the width of the destination (according to the rounding mode specified by the RC field of the FPU control word), and the exponent is converted to the width and bias of the destination format. If the value being stored is too large for the destination format, a numeric overflow exception (#O) is generated and, if the exception is unmasked, no value is stored in the destination operand. If the value being stored is a denormal value, the denormal exception (#D) is not generated. This condition is simply signaled as a numeric underflow exception (#U) condition.

If the value being stored is $$\pm$$0, $$\pm$$$$\infty$$, or a NaN, the least-significant bits of the significand and the exponent are trun-cated to fit the destination format. This operation preserves the value's identity as a 0, $$\infty$$, or NaN.

If the destination operand is a non-empty register, the invalid-operation exception is not generated.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
DEST <- ST(0);
IF Instruction = FSTP 
    THEN 
          PopRegisterStack; 
FI;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

                              Indicates rounding direction of if the floating-point inexact exception (#P) is generated: 0 <- not roundup; 1 <- roundup.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA If destination result is an SNaN value or unsupported format, except when the destination format is in double extended-precision floating-point format.

#U Result is too small for the destination format.

#O Result is too large for the destination format.

#P Value cannot be represented exactly in destination format.


### Protected Mode Exceptions

#### #GP(0)
* If the destination is located in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #MF
* If there is a pending x87 FPU exception.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
