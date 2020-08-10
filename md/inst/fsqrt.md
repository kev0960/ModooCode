### FSQRT--Square Root


|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 FA|FSQRT|Valid|Valid|Computes square root of ST(0) and stores the result in ST(0).|
### Description


Computes the square root of the source value in the ST(0) register and stores the result in ST(0).

The following table shows the results obtained when taking the square root of various classes of numbers, assuming that neither overflow nor underflow occurs.

### Table 3-37.  FSQRT Results


|**SRC (ST(0))**|**DEST (ST(0))**|
|---------------|----------------|
|- $$\infty$$|*|
|- F|*|
|- 0|- 0|
|+ 0|+ 0|
|+ F|+ F|
|+ $$\infty$$|+ $$\infty$$|
|NaN|NaN |
### NOTES:


FMeans finite floating-point value.

*Indicates floating-point invalid-arithmetic-operand (#IA) exception.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
ST(0) <- SquareRoot(ST(0));
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

         Set if result was rounded up; cleared otherwise.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA Source operand is an SNaN value or unsupported format.

         Source operand is a negative value (except for -0).

#D Source operand is a denormal value.

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

