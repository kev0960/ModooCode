----------------------------
title : FDIV, FDIVP, FIDIVs (Intel x86/64 assembly instruction)
cat_title : FDIV, FDIVP, FIDIV
ref_title : FDIV, FDIVP, FIDIV
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FDIV, FDIVP, FIDIV

**Divide**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D8 /6|`FDIV` m32fp |Valid|Valid|Divide ST(0) by m32fp and store result in ST(0).|
|DC /6|`FDIV` \tooltip{m64fp}{To-m32fp} |Valid|Valid|Divide ST(0) by m64fp and store result in ST(0).|
|D8 F0+i|`FDIV` \tooltip{ST(0)}{To-ST} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Divide ST(0) by ST(i) and store result in ST(0).|
|DC F8+i|`FDIV` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Divide ST(i) by ST(0) and store result in ST(i).|
|DE F8+i|`FDIVP` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} \tooltip{ST(0)}{To-ST} |Valid|Valid|Divide ST(i) by ST(0), store result in ST(i), and pop the register stack.|
|DE F9|`FDIVP` |Valid|Valid|Divide ST(1) by ST(0), store result in ST(1), and pop the register stack.|
|DA /6|`FIDIV` \tooltip{m32int}{To-m16int} |Valid|Valid|Divide ST(0) by m32int and store result in ST(0).|
|DE /6|`FIDIV` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Divide ST(0) by m16int and store result in ST(0).|
### Description


Divides the destination operand by the source operand and stores the result in the destination location. The desti-nation operand (dividend) is always in an FPU register; the source operand (divisor) can be a register or a memory location. Source operands in memory can be in single-precision or double-precision floating-point format, word or doubleword integer format.

The no-operand version of the instruction divides the contents of the ST(1) register by the contents of the ST(0) register. The one-operand version divides the contents of the ST(0) register by the contents of a memory location (either a floating-point or an integer value). The two-operand version, divides the contents of the ST(0) register by the contents of the ST(i) register or vice versa.

The `FDIVP` instructions perform the additional operation of popping the FPU register stack after storing the result. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. The no-operand version of the floating-point divide instructions always results in the register stack being popped. In some assemblers, the mnemonic for this instruction is `FDIV` rather than `FDIVP`.

The `FIDIV` instructions convert an integer source operand to double extended-precision floating-point format before performing the division. When the source operand is an integer 0, it is treated as a +0.

If an unmasked divide-by-zero exception (#Z) is generated, no result is stored; if the exception is masked, an $$\infty$$ of the appropriate sign is stored in the destination operand.

The following table shows the results obtained when dividing various classes of numbers, assuming that neither overflow nor underflow occurs.

### Table 3-24.  FDIV/FDIVP/FIDIV Results


NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN

                                                                                               NaN



|- $$\infty$$\newline{}- $$\infty$$ \htmlonly{*}|- F\newline{}+ 0|**DE**\newline{}- 0\newline{}+ 0|**ST**\newline{} + 0\newline{} - 0|+ F\newline{}- 0|+ $$\infty$$\newline{}\htmlonly{*}|
|-----------------------------------------------|----------------|--------------------------------|----------------------------------|----------------|----------------------------------|
|- F + $$\infty$$|+ F|+ 0|- 0|- F|- $$\infty$$|
|- I + $$\infty$$|+ F|+ 0|- 0|- F|- $$\infty$$|
|**SRC** - 0 + $$\infty$$|\htmlonly{*}\htmlonly{*}|\htmlonly{*}|\htmlonly{*}|\htmlonly{*}\htmlonly{*}|- $$\infty$$|
|+ 0 - $$\infty$$|\htmlonly{*}\htmlonly{*}|\htmlonly{*}|\htmlonly{*}|\htmlonly{*}\htmlonly{*}|+ $$\infty$$|
|+ I - $$\infty$$|- F|- 0|+ 0|+ F|+ $$\infty$$|
|+ F - $$\infty$$|- F|- 0|+ 0|+ F|+ $$\infty$$|
|+ $$\infty$$ \htmlonly{*}|- 0|- 0|+ 0|+ 0|\htmlonly{*}|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|
###   NOTES:


F Means finite floating-point value.

  I Means integer.

  \htmlonly{*} Indicates floating-point invalid-arithmetic-operand (#IA) exception.

  \htmlonly{*}\htmlonly{*}Indicates floating-point zero-divide (#Z) exception.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF SRC = 0
    THEN
          #Z;
    ELSE
          IF Instruction is FIDIV
                THEN
                      DEST <- DEST / ConvertToDoubleExtendedPrecisionFP(SRC);
                ELSE (* Source operand is floating-point value *)
                      DEST <- DEST / SRC;
          FI;
FI;
IF Instruction = FDIVP 
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

                              $$\pm$$$$\infty$$ / $$\pm$$$$\infty$$; $$\pm$$0 / $$\pm$$0

#D Source is a denormal value.

#Z DEST / $$\pm$$0, where DEST is not equal to $$\pm$$0.

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
