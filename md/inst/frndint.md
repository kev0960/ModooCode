----------------------------
title : FRNDINT (Intel x86/64 assembly instruction)
cat_title : FRNDINT
ref_title : FRNDINT
path : /X86-64 명령어 레퍼런스
----------------------------
#@ FRNDINT

**Round to Integer**

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 FC|FRNDINT|Valid|Valid|Round ST(0) to an integer.|
### Description


Rounds the source value in the ST(0) register to the nearest integral value, depending on the current rounding mode (setting of the RC field of the FPU control word), and stores the result in ST(0).

If the source value is $$\infty$$, the value is not changed. If the source value is not an integral value, the floating-point inexact-result exception (#P) is generated.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
ST(0) <- RoundToIntegralValue(ST(0));
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

                              Set if result was rounded up; cleared otherwise.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Source operand is an SNaN value or unsupported format.

#D Source operand is a denormal value.

#P Source operand is not an integral value.


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

