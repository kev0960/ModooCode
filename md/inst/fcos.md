----------------------------
title : FCOS (Intel x86/64 assembly instruction)
cat_title : FCOS
ref_title : FCOS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ FCOS

** Cosine**

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 FF|FCOS|Valid|Valid|Replace ST(0) with its approximate cosine.|
### Description


Computes the approximate cosine of the source operand in register ST(0) and stores the result in ST(0). The source operand must be given in radians and must be within the range -2\footnote{63}  to +2\footnote{63} . The following table shows the results obtained when taking the cosine of various classes of numbers.

### Table 3-23.  FCOS Results


|**ST(0) SRC**|**ST(0) DEST**|
|-------------|--------------|
|- $$\infty$$|\htmlonly{*}|
|- F|-1 to +1|
|- 0|+ 1|
|+ 0|+ 1|
|+ F|- 1 to + 1|
|+ $$\infty$$|\htmlonly{*}|
|NaN|NaN |
### NOTES:


FMeans finite floating-point value.

\htmlonly{*} Indicates floating-point invalid-arithmetic-operand (#IA) exception.

If the source operand is outside the acceptable range, the C2 flag in the FPU status word is set, and the value in register ST(0) remains unchanged. The instruction does not raise an exception when the source operand is out of range. It is up to the program to check the C2 flag for out-of-range conditions. Source values outside the range -2\footnote{63}  to +2\footnote{63}  can be reduced to the range of the instruction by subtracting an appropriate integer multiple of 2. However, even within the range -2\footnote{63}  to +2\footnote{63} , inaccurate results can occur because the finite approximation of  used internally for argument reduction is not sufficient in all cases. Therefore, for accurate results it is safe to apply FCOS only to arguments reduced accurately in software, to a value smaller in absolute value than 3/8. See the sections titled "Approximation of Pi" and "Transcendental Instruction Accuracy" in Chapter 8 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for a discussion of the proper value to use for  in performing such reductions.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF |ST(0)| < 2\footnote{63}
THEN
 C2 <- 0;
 ST(0) <- FCOS(ST(0)); // approximation of cosine
ELSE (* Source operand is out-of-range *)
 C2 <- 1;
FI;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

         Set if result was rounded up; cleared otherwise.

         Undefined if C2 is 1.

C2 Set to 1 if outside range (-2\footnote{63}  < source operand < +2\footnote{63} ); otherwise, set to 0.

C0, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Source operand is an SNaN value, $$\infty$$, or unsupported format.

#D Source is a denormal value.

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

