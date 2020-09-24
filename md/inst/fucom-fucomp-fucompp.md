----------------------------
title : FUCOM, FUCOMP, FUCOMPPs (Intel x86/64 assembly instruction)
cat_title : FUCOM, FUCOMP, FUCOMPP
ref_title : FUCOM, FUCOMP, FUCOMPP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FUCOM, FUCOMP, FUCOMPP

**Unordered Compare Floating Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|DD E0+i|`FUCOM` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Compare ST(0) with ST(i).|
|DD E1|`FUCOM` |Valid|Valid|Compare ST(0) with ST(1).|
|DD E8+i|`FUCOMP` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Compare ST(0) with ST(i) and pop register stack.|
|DD E9|`FUCOMP` |Valid|Valid|Compare ST(0) with ST(1) and pop register stack.|
|DA E9|`FUCOMPP` |Valid|Valid|Compare ST(0) with ST(1) and pop register stack twice.|
### Description


Performs an unordered comparison of the contents of register ST(0) and ST(i) and sets condition code flags C0, C2, and C3 in the FPU status word according to the results (see the table below). If no operand is specified, the contents of registers ST(0) and ST(1) are compared. The sign of zero is ignored, so that -0.0 is equal to +0.0.

### Table 3-41.  FUCOM/FUCOMP/FUCOMPP Results


|**Comparison Results\htmlonly{*}**|**C3**|**C2**|**C0**|
|----------------------------------|------|------|------|
|ST0 > ST(i)|0|0|0|
|ST0 < ST(i)|0|0|1|
|ST0 = ST(i)|1|0|0|
|Unordered|1|1|1|
###  NOTES:


\htmlonly{*} Flags not set if unmasked invalid-arithmetic-operand (#IA) exception is generated.

An unordered comparison checks the class of the numbers being compared (see "FXAM--Examine Floating-Point" in this chapter). The FUCOM/FUCOMP/FUCOMPP instructions perform the same operations as the FCOM/FCOMP/FCOMPP instructions. The only difference is that the FUCOM/FUCOMP/FUCOMPP instructions raise the invalid-arithmetic-operand exception (#IA) only when either or both operands are an SNaN or are in an unsup-ported format; QNaNs cause the condition code flags to be set to unordered, but do not cause an exception to be generated. The FCOM/FCOMP/FCOMPP instructions raise an invalid-operation exception when either or both of the operands are a NaN value of any kind or are in an unsupported format.

As with the FCOM/FCOMP/FCOMPP instructions, if the operation results in an invalid-arithmetic-operand exception being raised, the condition code flags are set only if the exception is masked.

The FUCOMP instruction pops the register stack following the comparison operation and the FUCOMPP instruction pops the register stack twice following the comparison operation. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
CASE (relation of operands) OF
    ST > SRC: C3, C2, C0 <- 000;
    ST < SRC: C3, C2, C0 <- 001;
    ST = SRC: C3, C2, C0 <- 100;
ESAC;
IF ST(0) or SRC = QNaN, but not SNaN or unsupported format
    THEN 
          C3, C2, C0 <- 111;
    ELSE (* ST(0) or SRC is SNaN or unsupported format *)
           #IA;
          IF FPUControlWord.IM = 1
                THEN 
                      C3, C2, C0 <- 111;
          FI;
FI;
IF Instruction = FUCOMP 
    THEN 
          PopRegisterStack;
FI;
IF Instruction = FUCOMPP 
    THEN 
          PopRegisterStack; 
FI;
```
### FPU Flags Affected


C1 Set to 0 if stack underflow occurred.

C0, C2, C3 See Table 3-41.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA One or both operands are SNaN values or have unsupported formats. Detection of a QNaN value in and of itself does not raise an invalid-operand exception.

#D One or both operands are denormal values.


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

