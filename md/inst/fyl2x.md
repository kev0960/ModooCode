----------------------------
title : FYL2X (Intel x86/64 assembly instruction)
cat_title : FYL2X
ref_title : FYL2X
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FYL2X

**Compute y `*` log2x**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 F1|FYL2X|Valid|Valid|Replace ST(1) with (ST(1) `*` log2ST(0)) and pop the register stack.|
### Description


Computes (ST(1) `\esc{*}` log2 (ST(0))), stores the result in resister ST(1), and pops the FPU register stack. The source operand in ST(0) must be a non-zero positive number.

The following table shows the results obtained when taking the log of various classes of numbers, assuming that neither overflow nor underflow occurs.

### Table 3-48.  FYL2X Results


|- $$\infty$$\newline{}- $$\infty$$ \htmlonly{*}|- F\newline{} \htmlonly{*}|$$\pm$$0\newline{}+ $$\infty$$|**ST(0)**\newline{}+0<+F<+1\newline{}    + $$\infty$$|+ 1\newline{} \htmlonly{*}|+ F > + 1\newline{}   - $$\infty$$|+ $$\infty$$\newline{}- $$\infty$$|NaN\newline{}NaN|
|-----------------------------------------------|--------------------------|------------------------------|-----------------------------------------------------|--------------------------|----------------------------------|----------------------------------|----------------|
|**ST(1)** - F \htmlonly{*}|\htmlonly{*}|\htmlonly{*}\htmlonly{*}|+ F|- 0|- F|- $$\infty$$|NaN|
|- 0 \htmlonly{*}|\htmlonly{*}|\htmlonly{*}|+ 0|- 0|- 0|\htmlonly{*}|NaN|
|+ 0 \htmlonly{*}|\htmlonly{*}|\htmlonly{*}|- 0|+ 0|+ 0|\htmlonly{*}|NaN|
|+ F \htmlonly{*}|\htmlonly{*}|\htmlonly{*}\htmlonly{*}|- F|+ 0|+ F|+ $$\infty$$|NaN|
|+ $$\infty$$ \htmlonly{*}|\htmlonly{*}|- $$\infty$$|- $$\infty$$|\htmlonly{*}|+ $$\infty$$|+ $$\infty$$|NaN|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|NaN|NaN|
###  NOTES:


F Means finite floating-point value.

 \htmlonly{*} Indicates floating-point invalid-operation (#IA) exception.

 \htmlonly{*}\htmlonly{*}Indicates floating-point zero-divide (#Z) exception.

If the divide-by-zero exception is masked and register ST(0) contains $$\pm$$0, the instruction returns $$\infty$$ with a sign that is the opposite of the sign of the source operand in register ST(1).

The FYL2X instruction is designed with a built-in multiplication to optimize the calculation of logarithms with an arbitrary positive base (b):

    log x <- (log b)\footnote{-1}b 2  `*` log2x

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
ST(1) <- ST(1) `*` log2ST(0);
PopRegisterStack;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

                              Set if result was rounded up; cleared otherwise.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Either operand is an SNaN or unsupported format.

                              Source operand in register ST(0) is a negative finite value (not -0).

#Z Source operand in register ST(0) is $$\pm$$0.

#D Source operand is a denormal value.

#U Result is too small for destination format.

#O Result is too large for destination format.

#P Value cannot be represented exactly in destination format.


### Protected Mode Exceptions

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #MF
* If there is a pending x87 FPU exception.

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
