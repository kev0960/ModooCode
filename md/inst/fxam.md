----------------------------
title : FXAM (Intel x86/64 assembly instruction)
cat_title : FXAM
ref_title : FXAM
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FXAM

**Examine Floating-Point**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 E5|FXAM|Valid|Valid|Classify value or number in ST(0).|
### Description


Examines the contents of the ST(0) register and sets the condition code flags C0, C2, and C3 in the FPU status word to indicate the class of value or number in the register (see the table below)..

###                                                                  Table 3-42.  FXAM Results


The C1 flag is set to the sign of the value in ST(0), regardless of whether the register is empty or full.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.



|**Class**|**C3**|**C2**|**C0**|
|---------|------|------|------|
|Unsupported|0|0|0|
|NaN|0|0|1|
|Normal finite number|0|1|0|
|Infinity|0|1|1|
|Zero|1|0|0|
|Empty|1|0|1|
|Denormal number|1|1|0|

### Operation

```info-verb
C1 <- sign bit of ST; (* 0 for positive, 1 for negative *)
CASE (class of value or number in ST(0)) OF
    Unsupported:C3, C2, C0 <- 000;
    NaN: C3, C2, C0 <- 001;
    Normal: C3, C2, C0 <- 010;
    Infinity: C3, C2, C0 <- 011;
    Zero: C3, C2, C0 <- 100;
    Empty: C3, C2, C0 <- 101;
    Denormal: C3, C2, C0 <- 110;
ESAC;
```
### FPU Flags Affected


C1 Sign of value in ST(0).

C0, C2, C3 See Table 3-42.

### Floating-Point Exceptions


None


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

