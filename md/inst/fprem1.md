----------------------------
title : FPREM1 (Intel x86/64 assembly instruction)
cat_title : FPREM1
ref_title : FPREM1
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FPREM1

**Partial Remainder**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 F5|`FPREM1` |Valid|Valid|Replace ST(0) with the IEEE remainder obtained from dividing ST(0) by ST(1).|
### Description


Computes the IEEE remainder obtained from dividing the value in the ST(0) register (the dividend) by the value in the ST(1) register (the divisor or modulus), and stores the result in ST(0). The remainder represents the following value:

Remainder <- ST(0) - (Q `\esc{*}` ST(1))

Here, Q is an integer value that is obtained by rounding the floating-point number quotient of [ST(0) / ST(1)] toward the nearest integer value. The magnitude of the remainder is less than or equal to half the magnitude of the modulus, unless a partial remainder was computed (as described below).

This instruction produces an exact result; the precision (inexact) exception does not occur and the rounding control has no effect. The following table shows the results obtained when computing the remainder of various classes of numbers, assuming that underflow does not occur.

### Table 3-32.  FPREM1 Results


|- $$\infty$$\newline{}- $$\infty$$ \htmlonly{*}|- F\newline{} \htmlonly{*}|**ST(**\newline{}- 0\newline{} \htmlonly{*}|**1)**\newline{}      + 0\newline{}        \htmlonly{*}|+ F\newline{} \htmlonly{*}|+ $$\infty$$\newline{} \htmlonly{*}|NaN\newline{}NaN|
|-----------------------------------------------|--------------------------|-------------------------------------------|-------------------------------------------------------|--------------------------|-----------------------------------|----------------|
|**ST(0)** - F ST(0)|$$\pm$$F or -0|\htmlonly{*}\htmlonly{*}|\htmlonly{*}\htmlonly{*}|$$\pm$$ F or - 0|ST(0)|NaN|
|- 0 - 0|- 0|\htmlonly{*}|\htmlonly{*}|- 0|-0|NaN|
|+ 0 + 0|+ 0|\htmlonly{*}|\htmlonly{*}|+ 0|+0|NaN|
|+ F ST(0)|$$\pm$$ F or + 0|\htmlonly{*}\htmlonly{*}|\htmlonly{*}\htmlonly{*}|$$\pm$$ F or + 0|ST(0)|NaN|
|+ $$\infty$$ \htmlonly{*}|\htmlonly{*}|\htmlonly{*}|\htmlonly{*}|\htmlonly{*}|\htmlonly{*}|NaN|
|NaN NaN|NaN|NaN|NaN|NaN|NaN|NaN|
###  NOTES:


F Means finite floating-point value.

 \htmlonly{*} Indicates floating-point invalid-arithmetic-operand (#IA) exception.

 \htmlonly{*}\htmlonly{*}Indicates floating-point zero-divide (#Z) exception.

When the result is 0, its sign is the same as that of the dividend. When the modulus is $$\infty$$, the result is equal to the value in ST(0). 

The FPREM1 instruction computes the remainder specified in IEEE Standard 754. This instruction operates differ-ently from the FPREM instruction in the way that it rounds the quotient of ST(0) divided by ST(1) to an integer (see the "Operation" section below).

Like the FPREM instruction, FPREM1 computes the remainder through iterative subtraction, but can reduce the exponent of ST(0) by no more than 63 in one execution of the instruction. If the instruction succeeds in producing a remainder that is less than one half the modulus, the operation is complete and the C2 flag in the FPU status word is cleared. Otherwise, C2 is set, and the result in ST(0) is called the partial remainder. The exponent of the partial remainder will be less than the exponent of the original dividend by at least 32. Software can re-execute the instruction (using the partial remainder in ST(0) as the dividend) until C2 is cleared. (Note that while executing such a remainder-computation loop, a higher-priority interrupting routine that needs the FPU can force a context switch in-between the instructions in the loop.)

An important use of the FPREM1 instruction is to reduce the arguments of periodic functions. When reduction is complete, the instruction stores the three least-significant bits of the quotient in the C3, C1, and C0 flags of the FPU 



status word. This information is important in argument reduction for the tangent function (using a modulus of /4), because it locates the original angle in the correct one of eight sectors of the unit circle.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### Operation 


D <- exponent(ST(0)) - exponent(ST(1));

IF D < 64

    THEN

          Q <- Integer(RoundTowardNearestInteger(ST(0) / ST(1)));

          ST(0) <- ST(0) - (ST(1) `*` Q);

          C2 <- 0;

          C0, C3, C1 <- LeastSignificantBits(Q); (\htmlonly{*} Q2, Q1, Q0 \htmlonly{*})

    ELSE

          C2 <- 1;

          N <- An implementation-dependent number between 32 and 63;

          QQ <- Integer(TruncateTowardZero((ST(0)  / ST(1)) / 2\footnote{(D - N)} ));

          ST(0) <- ST(0) - (ST(1) `*` QQ `*` 2\footnote{(D - N)} ); 

FI;

### FPU Flags Affected


C0 Set to bit 2 (Q2) of the quotient.

C1 Set to 0 if stack underflow occurred; otherwise, set to least significant bit of quotient (Q0).

C2 Set to 0 if reduction complete; set to 1 if incomplete.

C3  Set to bit 1 (Q1) of the quotient.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Source operand is an SNaN value, modulus (divisor) is 0, dividend is $$\infty$$, or unsupported format.

#D Source operand is a denormal value.

#U Result is too small for destination format.


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

