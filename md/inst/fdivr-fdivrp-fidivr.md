----------------------------
title : FDIVR, FDIVRP, FIDIVRs (Intel x86/64 assembly instruction)
cat_title : FDIVR, FDIVRP, FIDIVR
ref_title : FDIVR, FDIVRP, FIDIVR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FDIVR, FDIVRP, FIDIVR

**Reverse Divide**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D8 /7|FDIVR m32fp|Valid|Valid|Divide m32fp by ST(0) and store result in ST(0).|
|DC /7|FDIVR m64fp|Valid|Valid|Divide m64fp by ST(0) and store result in ST(0).|
|D8 F8+i|FDIVR ST(0), ST(i)|Valid|Valid|Divide ST(i) by ST(0) and store result in ST(0).|
|DC F0+i|FDIVR ST(i), ST(0)|Valid|Valid|Divide ST(0) by ST(i) and store result in ST(i).|
|DE F0+i|FDIVRP ST(i), ST(0)|Valid|Valid|Divide ST(0) by ST(i), store result in ST(i), and pop the register stack.|
|DE F1|FDIVRP|Valid|Valid|Divide ST(0) by ST(1), store result in ST(1), and pop the register stack.|
|DA /7|FIDIVR m32int|Valid|Valid|Divide m32int by ST(0) and store result in ST(0).|
|DE /7|FIDIVR m16int|Valid|Valid|Divide m16int by ST(0) and store result in ST(0).|
### Description


Divides the source operand by the destination operand and stores the result in the destination location. The desti-nation operand (divisor) is always in an FPU register; the source operand (dividend) can be a register or a memory location. Source operands in memory can be in single-precision or double-precision floating-point format, word or doubleword integer format.

These instructions perform the reverse operations of the `FDIV`, `FDIVP`, and `FIDIV` instructions. They are provided to support more efficient coding.

The no-operand version of the instruction divides the contents of the ST(0) register by the contents of the ST(1) register. The one-operand version divides the contents of a memory location (either a floating-point or an integer value) by the contents of the ST(0) register. The two-operand version, divides the contents of the ST(i) register by the contents of the ST(0) register or vice versa.

The `FDIVRP` instructions perform the additional operation of popping the FPU register stack after storing the result. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1. The no-operand version of the floating-point divide instructions always results in the register stack being popped. In some assemblers, the mnemonic for this instruction is `FDIVR` rather than `FDIVRP`.

The `FIDIVR` instructions convert an integer source operand to double extended-precision floating-point format before performing the division.

If an unmasked divide-by-zero exception (#Z) is generated, no result is stored; if the exception is masked, an $$\infty$$ of the appropriate sign is stored in the destination operand.

The following table shows the results obtained when dividing various classes of numbers, assuming that neither overflow nor underflow occurs.

### Table 3-25.  FDIVR/FDIVRP/FIDIVR Results


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



|- $$\infty$$\newline{}- $$\infty$$ \htmlonly{*}|- F\newline{}+ $$\infty$$|**DE**\newline{}- 0\newline{}+ $$\infty$$|**ST**\newline{}       + 0\newline{}       - $$\infty$$|+ F\newline{}- $$\infty$$|+ $$\infty$$\newline{} \htmlonly{*}|
|-----------------------------------------------|-------------------------|-----------------------------------------|-------------------------------------------------------|-------------------------|-----------------------------------|
|**SRC** - F + 0|+ F|\htmlonly{*}\htmlonly{*}|\htmlonly{*}\htmlonly{*}|- F|- 0|
|- I + 0|+ F|\htmlonly{*}\htmlonly{*}|\htmlonly{*}\htmlonly{*}|- F|- 0|
|- 0 + 0|+ 0|\htmlonly{*}|\htmlonly{*}|- 0|- 0|
|+ 0 - 0|- 0|\htmlonly{*}|\htmlonly{*}|+ 0|+ 0|
|+ I - 0|- F|\htmlonly{*}\htmlonly{*}|\htmlonly{*}\htmlonly{*}|+ F|+ 0|
|+ F - 0|- F|\htmlonly{*}\htmlonly{*}|\htmlonly{*}\htmlonly{*}|+ F|+ 0|
|+ $$\infty$$ \htmlonly{*}|- $$\infty$$|- $$\infty$$|+ $$\infty$$|+ $$\infty$$|\htmlonly{*}|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|
###  NOTES:


F Means finite floating-point value.

 I Means integer.

 \htmlonly{*} Indicates floating-point invalid-arithmetic-operand (#IA) exception.

 \htmlonly{*}\htmlonly{*} Indicates floating-point zero-divide (#Z) exception.

When the source operand is an integer 0, it is treated as a +0. This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF DEST = 0
    THEN
          #Z;
    ELSE
          IF Instruction = FIDIVR
                THEN
                      DEST <- ConvertToDoubleExtendedPrecisionFP(SRC) / DEST;
                ELSE (* Source operand is floating-point value *)
                      DEST <- SRC / DEST;
          FI;
FI;
IF Instruction = FDIVRP 
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

#Z SRC / $$\pm$$0, where SRC is not equal to $$\pm$$0.

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
