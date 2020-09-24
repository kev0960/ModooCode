----------------------------
title : FADD, FADDP, FIADDs (Intel x86/64 assembly instruction)
cat_title : FADD, FADDP, FIADD
ref_title : FADD, FADDP, FIADD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FADD, FADDP, FIADD

**Add**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D8 /0|`FADD` m32fp |Valid|Valid|Add m32fp to ST(0) and store result in ST(0).|
|DC /0|`FADD` \tooltip{m64fp}{To-m32fp} |Valid|Valid|Add m64fp to ST(0) and store result in ST(0).|
|D8 C0+i|`FADD` \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Add ST(0) to ST(i) and store result in ST(0).|
|DC C0+i|`FADD` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Add ST(i) to ST(0) and store result in ST(i).|
|DE C0+i|`FADDP` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Add ST(0) to ST(i), store result in ST(i), and pop the register stack.|
|DE C1|`FADDP` |Valid|Valid|Add ST(0) to ST(1), store result in ST(1), and pop the register stack.|
|DA /0|`FIADD` \tooltip{m32int}{To-m16int} |Valid|Valid|Add m32int to ST(0) and store result in ST(0).|
|DE /0|`FIADD` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Add m16int to ST(0) and store result in ST(0).|
### Description


Adds the destination and source operands and stores the sum in the destination location. The destination operand is always an FPU register; the source operand can be a register or a memory location. Source operands in memory can be in single-precision or double-precision floating-point format or in word or doubleword integer format.

The no-operand version of the instruction adds the contents of the ST(0) register to the ST(1) register. The one-operand version adds the contents of a memory location (either a floating-point or an integer value) to the contents of the ST(0) register. The two-operand version, adds the contents of the ST(0) register to the ST(i) register or vice versa. The value in ST(0) can be doubled by coding:

    `FADD` ST(0), ST(0);

The `FADDP` instructions perform the additional operation of popping the FPU register stack after storing the result. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. (The no-operand version of the floating-point add instructions always results in the register stack being popped. In some assemblers, the mnemonic for this instruction is `FADD` rather than `FADDP`.)

The `FIADD` instructions convert an integer source operand to double extended-precision floating-point format before performing the addition.

The table on the following page shows the results obtained when adding various classes of numbers, assuming that neither overflow nor underflow occurs.

When the sum of two operands with opposite signs is 0, the result is +0, except for the round toward -$$\infty$$ mode, in which case the result is -0. When the source operand is an integer 0, it is treated as a +0.

When both operand are infinities of the same sign, the result is $$\infty$$ of the expected sign. If both operands are infini-ties of opposite signs, an invalid-operation exception is generated. See Table 3-18.

### Table 3-18.  FADD/FADDP/FIADD Results


NaN

                                                                                                 NaN

                                                                                                 NaN

                                                                                                 NaN

                                                                                                 NaN

                                                                                                 NaN

                                                                                                 NaN

                                                                                                 NaN



|- $$\infty$$\newline{}- $$\infty$$ - $$\infty$$|- F\newline{}- $$\infty$$|**DE**\newline{}- 0\newline{}- $$\infty$$|**ST**\newline{} + 0\newline{} - $$\infty$$|+ F\newline{}- $$\infty$$|+ $$\infty$$\newline{}\htmlonly{*}|
|-----------------------------------------------|-------------------------|-----------------------------------------|-------------------------------------------|-------------------------|----------------------------------|
|- F or - I - $$\infty$$|- F|SRC|SRC|$$\pm$$ F or $$\pm$$ 0|+ $$\infty$$|
|**SRC** -0 - $$\infty$$|DEST|- 0|$$\pm$$ 0|DEST|+ $$\infty$$|
|+ 0 - $$\infty$$|DEST|$$\pm$$ 0|+ 0|DEST|+ $$\infty$$|
|+ F or + I - $$\infty$$|$$\pm$$ F or $$\pm$$ 0|SRC|SRC|+ F|+ $$\infty$$|
|+ $$\infty$$ \htmlonly{*}|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|
###   NOTES:


F Means finite floating-point value.

  I Means integer.

  \htmlonly{*} Indicates floating-point invalid-arithmetic-operand (#IA) exception.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF Instruction = FIADD
    THEN
          DEST <- DEST + ConvertToDoubleExtendedPrecisionFP(SRC);
    ELSE (* Source operand is floating-point value *)
          DEST <- DEST + SRC;
FI;
IF Instruction = FADDP 
    THEN 
          PopRegisterStack;
FI;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

                              Set if result was rounded up; cleared otherwise.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Operand is an SNaN value or unsupported format.

                              Operands are infinities of unlike sign.

#D Source operand is a denormal value.

#U Result is too small for destination format.

#O Result is too large for destination format.

#P Value cannot be represented exactly in destination format.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

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
