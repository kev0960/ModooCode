----------------------------
title : FICOM, FICOMPs (Intel x86/64 assembly instruction)
cat_title : FICOM, FICOMP
ref_title : FICOM, FICOMP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FICOM, FICOMP

**Compare Integer**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|DE /2|`FICOM` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Compare ST(0) with m16int.|
|DA /2|`FICOM` \tooltip{m32int}{To-m16int} |Valid|Valid|Compare ST(0) with m32int.|
|DE /3|`FICOMP` \tooltip{m16int}{메모리 상에 위치한 2 바이트, 4 바이트, 8 바이트 정수 데이터로, 위와 마찬가지로 x87 FPU 부동 소수점 명령어에서 사용된다. } |Valid|Valid|Compare ST(0) with m16int and pop stack register.|
|DA /3|`FICOMP` \tooltip{m32int}{To-m16int} |Valid|Valid|Compare ST(0) with m32int and pop stack register.|
### Description


Compares the value in ST(0) with an integer source operand and sets the condition code flags C0, C2, and C3 in the FPU status word according to the results (see table below). The integer value is converted to double extended-precision floating-point format before the comparison is made.

###                                                            Table 3-26.  FICOM/FICOMP Results


These instructions perform an "unordered comparison." An unordered comparison also checks the class of the numbers being compared (see "FXAM--Examine Floating-Point" in this chapter). If either operand is a NaN or is in an undefined format, the condition flags are set to "unordered."

The sign of zero is ignored, so that -0.0 <- +0.0.

The FICOMP instructions pop the register stack following the comparison. To pop the register stack, the processor marks the ST(0) register empty and increments the stack pointer (TOP) by 1.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.



|**Condition**|**C3**|**C2**|**C0**|
|-------------|------|------|------|
|ST(0) > SRC|0|0|0|
|ST(0) < SRC|0|0|1|
|ST(0) = SRC|1|0|0|
|Unordered|1|1|1|

### Operation

```info-verb
CASE (relation of operands) OF
    ST(0) > SRC: C3, C2, C0 <- 000;
    ST(0) < SRC: C3, C2, C0 <- 001;
    ST(0) = SRC: C3, C2, C0 <- 100;
    Unordered: C3, C2, C0 <- 111;
ESAC;
IF Instruction = FICOMP 
    THEN 
          PopRegisterStack; 
FI;
```
### FPU Flags Affected


C1 Set to 0.

C0, C2, C3 See table on previous page.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA One or both operands are NaN values or have unsupported formats.

#D One or both operands are denormal values.


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #NM
* CR0.EM[bit 2] or CR0.TS[bit 3] = 1.

#### #MF
* If there is a pending x87 FPU exception.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
