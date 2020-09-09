----------------------------
title : FSCALE (Intel x86/64 assembly instruction)
cat_title : FSCALE
ref_title : FSCALE
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FSCALE

**Scale**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 FD|FSCALE|Valid|Valid|Scale ST(0) by ST(1).|
### Description


Truncates the value in the source operand (toward 0) to an integral value and adds that value to the exponent of the destination operand. The destination and source operands are floating-point values located in registers ST(0) and ST(1), respectively. This instruction provides rapid multiplication or division by integral powers of 2. The following table shows the results obtained when scaling various classes of numbers, assuming that neither over-flow nor underflow occurs.

### Table 3-34.  FSCALE Results


|**ST(1)**\newline{}                        - $$\infty$$\newline{}      - $$\infty$$ NaN|- F\newline{}- $$\infty$$|- 0\newline{}- $$\infty$$|+ 0\newline{}- $$\infty$$|+ F + $$\infty$$ NaN\newline{}- $$\infty$$ - $$\infty$$ NaN|
|---------------------------------------------------------------------------------------|-------------------------|-------------------------|-------------------------|-----------------------------------------------------------|
|**ST(0) ** - F - 0|- F|- F|- F|- F - $$\infty$$ NaN|
|- 0 - 0|- 0|- 0|- 0|- 0 NaN NaN|
|+ 0 + 0|+ 0|+ 0|+ 0|+ 0 NaN NaN|
|+ F + 0|+ F|+ F|+ F|+ F + $$\infty$$ NaN|
|+ $$\infty$$ NaN|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$|+ $$\infty$$ + $$\infty$$ NaN|
|NaN NaN |NaN|NaN |NaN |NaN  NaN  NaN|
###  NOTES:


F Means finite floating-point value.

In most cases, only the exponent is changed and the mantissa (significand) remains unchanged. However, when the value being scaled in ST(0) is a denormal value, the mantissa is also changed and the result may turn out to be a normalized number. Similarly, if overflow or underflow results from a scale operation, the resulting mantissa will differ from the source's mantissa.

The FSCALE instruction can also be used to reverse the action of the FXTRACT instruction, as shown in the following example:

    FXTRACT;

    FSCALE;

    FSTP ST(1);

In this example, the FXTRACT instruction extracts the significand and exponent from the value in ST(0) and stores them in ST(0) and ST(1) respectively. The FSCALE then scales the significand in ST(0) by the exponent in ST(1), recreating the original value before the FXTRACT operation was performed. The FSTP ST(1) instruction overwrites the exponent (extracted by the FXTRACT instruction) with the recreated value, which returns the stack to its orig-inal state with only one register [ST(0)] occupied.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
ST(0) <- ST(0) `*` 2\footnote{RoundTowardZero(ST(1))} ;
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

