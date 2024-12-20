----------------------------
title : FIST, FISTPs (Intel x86/64 assembly instruction)
cat_title : FIST, FISTP
ref_title : FIST, FISTP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FIST, FISTP

**Store Integer**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|DF /2|`FIST` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Store ST(0) in m16int.|
|DB /2|`FIST` \tooltip{m32int}{To-m16int} |Valid|Valid|Store ST(0) in m32int.|
|DF /3|`FISTP` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Store ST(0) in m16int and pop register stack.|
|DB /3|`FISTP` \tooltip{m32int}{To-m16int} |Valid|Valid|Store ST(0) in m32int and pop register stack.|
|DF /7|`FISTP` \tooltip{m64int}{To-m16int} |Valid|Valid|Store ST(0) in m64int and pop register stack.|
### Description


The `FIST` instruction converts the value in the ST(0) register to a signed integer and stores the result in the desti-nation operand. Values can be stored in word or doubleword integer format. The destination operand specifies the address where the first byte of the destination value is to be stored.

The `FISTP` instruction performs the same operation as the `FIST` instruction and then pops the register stack. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. The `FISTP` instruction also stores values in quadword integer format.

The following table shows the results obtained when storing various classes of numbers in integer format.

###                                               Table 3-27.  FIST/FISTP Results 


**ST(0) DEST**

- $$\infty$$ or Value Too Large for DEST Format \htmlonly{*}

                     F <= -1 - I

                  -1 < F < -0 \htmlonly{*}\htmlonly{*}

                       - 0 0

                       + 0 0

                 + 0 < F < + 1 \htmlonly{*}\htmlonly{*}

                     F >= + 1 + I

+ $$\infty$$ or Value Too Large for DEST Format \htmlonly{*}

                       NaN \htmlonly{*}

###  NOTES:


F Means finite floating-point value.

 I Means integer.

 \htmlonly{*} Indicates floating-point invalid-operation (#IA) exception.

 \htmlonly{*}\htmlonly{*}0 or $$\pm$$1, depending on the rounding mode.

If the source value is a non-integral value, it is rounded to an integer value, according to the rounding mode spec-ified by the RC field of the FPU control word. 

If the converted value is too large for the destination format, or if the source operand is an $$\infty$$, SNaN, QNAN, or is in an unsupported format, an invalid-arithmetic-operand condition is signaled. If the invalid-operation exception is not masked, an invalid-arithmetic-operand exception (#IA) is generated and no value is stored in the destination operand. If the invalid-operation exception is masked, the integer indefinite value is stored in memory.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
DEST <- Integer(ST(0));
IF Instruction = FISTP 
    THEN 
          PopRegisterStack;
FI;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

                              Indicates rounding direction of if the inexact exception (#P) is generated: 0 <- not roundup; 1 <- roundup.

                              Set to 0 otherwise.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Converted value is too large for the destination format.

                              Source operand is an SNaN, QNaN, $$\pm$$$$\infty$$, or unsupported format.

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
