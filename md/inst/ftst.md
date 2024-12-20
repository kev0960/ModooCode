----------------------------
title : FTST (Intel x86/64 assembly instruction)
cat_title : FTST
ref_title : FTST
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FTST

**TEST**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 E4|`FTST` |Valid|Valid|Compare ST(0) with 0.0.|
### Description


Compares the value in the ST(0) register with 0.0 and sets the condition code flags C0, C2, and C3 in the FPU status word according to the results (see table below).

###                                                                   Table 3-40.  FTST Results


This instruction performs an "unordered comparison." An unordered comparison also checks the class of the numbers being compared (see "FXAM--Examine Floating-Point" in this chapter). If the value in register ST(0) is a NaN or is in an undefined format, the condition flags are set to "unordered" and the invalid operation exception is generated.

The sign of zero is ignored, so that (- 0.0 <- +0.0).

This instruction's operation is the same in non-64-bit modes and 64-bit mode.



|**Condition**|**C3**|**C2**|**C0**|
|-------------|------|------|------|
|ST(0) > 0.0|0|0|0|
|ST(0) < 0.0|0|0|1|
|ST(0) = 0.0|1|0|0|
|Unordered|1|1|1|

### Operation

```info-verb
CASE (relation of operands) OF
    Not comparable: C3, C2, C0 <- 111;
    ST(0) > 0.0: C3, C2, C0 <- 000;
    ST(0) < 0.0: C3, C2, C0 <- 001;
    ST(0) = 0.0: C3, C2, C0 <- 100;
ESAC;
```
### FPU Flags Affected


C1 Set to 0.

C0, C2, C3 See Table 3-40.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA The source operand is a NaN value or is in an unsupported format.

#D The source operand is a denormal value.


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

