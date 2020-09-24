----------------------------
title : FMUL, FMULP, FIMULs (Intel x86/64 assembly instruction)
cat_title : FMUL, FMULP, FIMUL
ref_title : FMUL, FMULP, FIMUL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FMUL, FMULP, FIMUL

**Multiply**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D8 /1|`FMUL` m32fp |Valid|Valid|Multiply ST(0) by m32fp and store result in ST(0).|
|DC /1|`FMUL` \tooltip{m64fp}{To-m32fp} |Valid|Valid|Multiply ST(0) by m64fp and store result in ST(0).|
|D8 C8+i|`FMUL` \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Multiply ST(0) by ST(i) and store result in ST(0).|
|DC C8+i|`FMUL` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Multiply ST(i) by ST(0) and store result in ST(i).|
|DE C8+i|`FMULP` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Multiply ST(i) by ST(0), store result in ST(i), and pop the register stack.|
|DE C9|`FMULP` |Valid|Valid|Multiply ST(1) by ST(0), store result in ST(1), and pop the register stack.|
|DA /1|`FIMUL` \tooltip{m32int}{To-m16int} |Valid|Valid|Multiply ST(0) by m32int and store result in ST(0).|
|DE /1|`FIMUL` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Multiply ST(0) by m16int and store result in ST(0).|
### Description


Multiplies the destination and source operands and stores the product in the destination location. The destination operand is always an FPU data register; the source operand can be an FPU data register or a memory location. Source operands in memory can be in single-precision or double-precision floating-point format or in word or doubleword integer format.

The no-operand version of the instruction multiplies the contents of the ST(1) register by the contents of the ST(0) register and stores the product in the ST(1) register. The one-operand version multiplies the contents of the ST(0) register by the contents of a memory location (either a floating point or an integer value) and stores the product in the ST(0) register. The two-operand version, multiplies the contents of the ST(0) register by the contents of the ST(i) register, or vice versa, with the result being stored in the register specified with the first operand (the desti-nation operand). 

The `FMULP` instructions perform the additional operation of popping the FPU register stack after storing the product. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. The no-operand version of the floating-point multiply instructions always results in the register stack being popped. In some assemblers, the mnemonic for this instruction is `FMUL` rather than `FMULP`.

The `FIMUL` instructions convert an integer source operand to double extended-precision floating-point format before performing the multiplication.

The sign of the result is always the exclusive-OR of the source signs, even if one or more of the values being multi-plied is 0 or $$\infty$$. When the source operand is an integer 0, it is treated as a +0.

The following table shows the results obtained when multiplying various classes of numbers, assuming that neither overflow nor underflow occurs.

### Table 3-29.  FMUL/FMULP/FIMUL Results


|- $$\infty$$\newline{}- $$\infty$$ + $$\infty$$|- F\newline{}+ $$\infty$$|**DE**\newline{}- 0\newline{} \htmlonly{*}|**ST**\newline{}       + 0\newline{}        \htmlonly{*}|+ F\newline{}- $$\infty$$|+ $$\infty$$\newline{}- $$\infty$$|NaN\newline{}NaN|
|-----------------------------------------------|-------------------------|------------------------------------------|--------------------------------------------------------|-------------------------|----------------------------------|----------------|
|- F + $$\infty$$|+ F|+ 0|- 0|- F|- $$\infty$$|NaN|
|- I + $$\infty$$|+ F|+ 0|- 0|- F|- $$\infty$$|NaN|
|**SRC** - 0 \htmlonly{*}|+ 0|+ 0|- 0|- 0|\htmlonly{*}|NaN|
|+ 0 \htmlonly{*}|- 0|- 0|+ 0|+ 0|\htmlonly{*}|NaN|
|+ I - $$\infty$$|- F|- 0|+ 0|+ F|+ $$\infty$$|NaN|
|+ F - $$\infty$$|- F|- 0|+ 0|+ F|+ $$\infty$$|NaN|
|+ $$\infty$$ - $$\infty$$|- $$\infty$$|\htmlonly{*}|\htmlonly{*}|+ $$\infty$$|+ $$\infty$$|NaN|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|NaN|
###  NOTES:


F Means finite floating-point value.

 I Means Integer.

 \htmlonly{*} Indicates invalid-arithmetic-operand (#IA) exception.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF Instruction = FIMUL
    THEN
          DEST <- DEST `*` ConvertToDoubleExtendedPrecisionFP(SRC);
    ELSE (* Source operand is floating-point value *)
          DEST <- DEST `*` SRC;
FI;
IF Instruction = FMULP 
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

                              One operand is $$\pm$$0 and the other is $$\pm$$$$\infty$$.

#D Source operand is a denormal value.

#U Result is too small for destination format.

#O Result is too large for destination format.

#P Value cannot be represented exactly in destination format.


### Protected Mode Exceptions

#### #GP(0)
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
