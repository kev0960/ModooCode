----------------------------
title : FPATAN (Intel x86/64 assembly instruction)
cat_title : FPATAN
ref_title : FPATAN
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FPATAN

**Partial Arctangent**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------|---------------|-----------------------------|---------------------------------|---------------|
|D9 F3|FPATAN|Valid|Valid|Replace ST(1) with arctan(ST(1)/ST(0)) and pop the register stack.|
### Description


Computes the arctangent of the source operand in register ST(1) divided by the source operand in register ST(0), stores the result in ST(1), and pops the FPU register stack. The result in register ST(0) has the same sign as the source operand ST(1) and a magnitude less than +.

The `FPATAN` instruction returns the angle between the X axis and the line from the origin to the point (X,Y), where Y (the ordinate) is ST(1) and X (the abscissa) is ST(0). The angle depends on the sign of X and Y independently, not just on the sign of the ratio Y/X. This is because a point (-X,Y) is in the second quadrant, resulting in an angle between /2 and , while a point (X,-Y) is in the fourth quadrant, resulting in an angle between 0 and -/2. A point (-X,-Y) is in the third quadrant, giving an angle between -/2 and -.

The following table shows the results obtained when computing the arctangent of various classes of numbers, assuming that underflow does not occur.

### Table 3-30.  FPATAN Results


|- $$\infty$$\newline{}- $$\infty$$ - 3/4\htmlonly{*}|- F\newline{}- /2|**ST(0**\newline{}- 0\newline{}- /2|**)**\newline{}+ 0\newline{}- /2|+ F\newline{}- /2|+ $$\infty$$\newline{}- /4\htmlonly{*}|NaN\newline{}NaN|
|-----------------------------------------------------|------------------|------------------------------------|---------------------------------|------------------|---------------------------------------|----------------|
|**ST(1)** - F -p|- to -/2|-/2|-/2|-/2 to -0|- 0|NaN|
|- 0 -p|-p|-p\htmlonly{*}|- 0\htmlonly{*}|- 0|- 0|NaN|
|+ 0 +p|+ p|+ \htmlonly{*}|+ 0\htmlonly{*}|+ 0|+ 0|NaN|
|+ F +p|+ to +/2|+ /2|+/2|+/2 to +0|+ 0|NaN|
|+ $$\infty$$ +3/4\htmlonly{*}|+/2|+/2|+/2|+ /2|+ /4\htmlonly{*}|NaN|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|NaN|
###  NOTES:


F Means finite floating-point value.

 \htmlonly{*} Table 8-10 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, specifies that the ratios 0/0 and $$\infty$$/$$\infty$$ generate the floating-point invalid arithmetic-operation exception and, if this exception is masked, the floating-point QNaN indefi-nite value is returned. With the FPATAN instruction, the 0/0 or $$\infty$$/$$\infty$$ value is actually not calculated using division. Instead, the arc-tangent of the two variables is derived from a standard mathematical formulation that is generalized to allow complex numbers as arguments. In this complex variable formulation, arctangent(0,0) etc. has well defined values. These values are needed to develop a library to compute transcendental functions with complex arguments, based on the FPU functions that only allow floating-point values as arguments.

There is no restriction on the range of source operands that FPATAN can accept.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### IA-32 Architecture Compatibility


The source operands for this instruction are restricted for the 80287 math coprocessor to the following range:

0 <= |ST(1)| < |ST(0)| < +$$\infty$$


### Operation

```info-verb
ST(1) <- arctan(ST(1) / ST(0));
PopRegisterStack;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

                              Set if result was rounded up; cleared otherwise.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Source operand is an SNaN value or unsupported format.

#D Source operand is a denormal value.

#U Result is too small for destination format.

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

