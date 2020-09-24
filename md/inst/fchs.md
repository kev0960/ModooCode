----------------------------
title : FCHS (Intel x86/64 assembly instruction)
cat_title : FCHS
ref_title : FCHS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FCHS

**Change Sign**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 E0|`FCHS` |Valid|Valid|Complements sign of ST(0).|
### Description


Complements the sign bit of ST(0). This operation changes a positive value into a negative value of equal magni-tude or vice versa. The following table shows the results obtained when changing the sign of various classes of numbers.

### Table 3-20.  FCHS Results


|**ST(0) SRC**|**ST(0) DEST**|
|-------------|--------------|
|- $$\infty$$|+ $$\infty$$|
|- F|+ F|
|- 0|+ 0|
|+ 0|- 0|
|+ F|- F|
|+ $$\infty$$|- $$\infty$$|
|NaN|NaN |
###  NOTES:


\htmlonly{*} F means finite floating-point value.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
SignBit(ST(0)) <- NOT (SignBit(ST(0)));
```
### FPU Flags Affected


C1 Set to 0.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.


### Protected Mode Exceptions

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

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

