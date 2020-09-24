----------------------------
title : FSUB, FSUBP, FISUBs (Intel x86/64 assembly instruction)
cat_title : FSUB, FSUBP, FISUB
ref_title : FSUB, FSUBP, FISUB
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FSUB, FSUBP, FISUB

**Subtract**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D8 /4|`FSUB` m32fp |Valid|Valid|Subtract m32fp from ST(0) and store result in ST(0).|
|DC /4|`FSUB` \tooltip{m64fp}{To-m32fp} |Valid|Valid|Subtract m64fp from ST(0) and store result in ST(0).|
|D8 E0+i|`FSUB` \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Subtract ST(i) from ST(0) and store result in ST(0).|
|DC E8+i|`FSUB` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Subtract ST(0) from ST(i) and store result in ST(i).|
|DE E8+i|`FSUBP` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Subtract ST(0) from ST(i), store result in ST(i), and pop register stack.|
|DE E9|`FSUBP` |Valid|Valid|Subtract ST(0) from ST(1), store result in ST(1), and pop register stack.|
|DA /4|`FISUB` \tooltip{m32int}{To-m16int} |Valid|Valid|Subtract m32int from ST(0) and store result in ST(0).|
|DE /4|`FISUB` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Subtract m16int from ST(0) and store result in ST(0).|
### Description


Subtracts the source operand from the destination operand and stores the difference in the destination location. The destination operand is always an FPU data register; the source operand can be a register or a memory location. Source operands in memory can be in single-precision or double-precision floating-point format or in word or doubleword integer format.

The no-operand version of the instruction subtracts the contents of the ST(0) register from the ST(1) register and stores the result in ST(1). The one-operand version subtracts the contents of a memory location (either a floating-point or an integer value) from the contents of the ST(0) register and stores the result in ST(0). The two-operand version, subtracts the contents of the ST(0) register from the ST(i) register or vice versa.

The `FSUBP` instructions perform the additional operation of popping the FPU register stack following the subtrac-tion. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. The no-operand version of the floating-point subtract instructions always results in the register stack being popped. In some assemblers, the mnemonic for this instruction is `FSUB` rather than `FSUBP`.

The `FISUB` instructions convert an integer source operand to double extended-precision floating-point format before performing the subtraction.

Table 3-38 shows the results obtained when subtracting various classes of numbers from one another, assuming that neither overflow nor underflow occurs. Here, the SRC value is subtracted from the DEST value (DEST - SRC = result).

When the difference between two operands of like sign is 0, the result is +0, except for the round toward -$$\infty$$ mode, in which case the result is -0. This instruction also guarantees that +0 - (-0) = +0, and that -0 - (+0) = -0. When the source operand is an integer 0, it is treated as a +0.

When one operand is $$\infty$$, the result is $$\infty$$ of the expected sign. If both operands are $$\infty$$ of the same sign, an invalid-operation exception is generated.

### Table 3-38.  FSUB/FSUBP/FISUB Results


|- $$\infty$$\newline{}- $$\infty$$ \htmlonly{*}|- F or - I\newline{}   - $$\infty$$|**SR**\newline{}- 0\newline{}- $$\infty$$|**C**\newline{}      + 0\newline{}      - $$\infty$$|+ F or + I\newline{}   - $$\infty$$|+ $$\infty$$\newline{}- $$\infty$$|NaN\newline{}NaN|
|-----------------------------------------------|-----------------------------------|-----------------------------------------|----------------------------------------------------|-----------------------------------|----------------------------------|----------------|
|- F + $$\infty$$|$$\pm$$F or $$\pm$$0|DEST|DEST|- F|- $$\infty$$|NaN|
|**DEST** - 0 + $$\infty$$|-SRC|$$\pm$$0|- 0|- SRC|- $$\infty$$|NaN|
|+ 0 + $$\infty$$|-SRC|+ 0|$$\pm$$0|- SRC|- $$\infty$$|NaN|
|+ F + $$\infty$$|+ F|DEST|DEST|$$\pm$$F or $$\pm$$0|- $$\infty$$|NaN|
|+ $$\infty$$ + $$\infty$$|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$|\htmlonly{*}|NaN|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|NaN|
###   NOTES:


F Means finite floating-point value.

  I Means integer.

  \htmlonly{*} Indicates floating-point invalid-arithmetic-operand (#IA) exception.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF Instruction = FISUB
    THEN
          DEST <- DEST - ConvertToDoubleExtendedPrecisionFP(SRC);
    ELSE (* Source operand is floating-point value *)
          DEST <- DEST - SRC;
FI;
IF Instruction = FSUBP 
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

                              Operands are infinities of like sign.

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
