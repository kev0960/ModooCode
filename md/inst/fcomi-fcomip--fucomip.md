----------------------------
title : FCOMI, FCOMIP, , FUCOMIPs (Intel x86/64 assembly instruction)
cat_title : FCOMI, FCOMIP, , FUCOMIP
ref_title : FCOMI, FCOMIP, , FUCOMIP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FCOMI, FCOMIP, , FUCOMIP

**Compare Floating Point Values and Set EFLAGS**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|DB F0+i|`FCOMI` \tooltip{ST}{FPU 레지스터 스택의 가장 최상단에 위치한 원소.} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Compare ST(0) with ST(i) and set status flags accordingly.|
|DF F0+i|`FCOMIP` \tooltip{ST}{FPU 레지스터 스택의 가장 최상단에 위치한 원소.} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Compare ST(0) with ST(i), set status flags accordingly, and pop register stack.|
|DB E8+i|FUCOMI \tooltip{ST}{FPU 레지스터 스택의 가장 최상단에 위치한 원소.} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Compare ST(0) with ST(i), check for ordered values, and set status flags accordingly.|
|DF E8+i|`FUCOMIP` \tooltip{ST}{FPU 레지스터 스택의 가장 최상단에 위치한 원소.} \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Compare ST(0) with ST(i), check for ordered values, set status flags accordingly, and pop register stack.|
### Description


Performs an unordered comparison of the contents of registers ST(0) and ST(i) and sets the status flags ZF, PF, and CF in the EFLAGS register according to the results (see the table below). The sign of zero is ignored for compari-sons, so that -0.0 is equal to +0.0. 

### Table 3-22.  FCOMI/FCOMIP/ FUCOMI/FUCOMIP Results


|**Comparison Results\htmlonly{*}**|**ZF**|**PF**|**CF**|
|----------------------------------|------|------|------|
|ST0 > ST(i)|0|0|0|
|ST0 < ST(i)|0|0|1|
|ST0 = ST(i)|1|0|0|
|Unordered\htmlonly{*}\htmlonly{*}|1|1|1|
###  NOTES:


\htmlonly{*} See the IA-32 Architecture Compatibility section below.

 \htmlonly{*}\htmlonly{*}Flags not set if unmasked invalid-arithmetic-operand (#IA) exception is generated.

An unordered comparison checks the class of the numbers being compared (see "FXAM--Examine Floating-Point" in this chapter). The FUCOMI/FUCOMIP instructions perform the same operations as the FCOMI/FCOMIP instruc-tions. The only difference is that the FUCOMI/FUCOMIP instructions raise the invalid-arithmetic-operand exception (#IA) only when either or both operands are an SNaN or are in an unsupported format; QNaNs cause the condition code flags to be set to unordered, but do not cause an exception to be generated. The FCOMI/FCOMIP instructions raise an invalid-operation exception when either or both of the operands are a NaN value of any kind or are in an unsupported format.

If the operation results in an invalid-arithmetic-operand exception being raised, the status flags in the EFLAGS register are set only if the exception is masked. 

The FCOMI/FCOMIP and FUCOMI/FUCOMIP instructions set the OF, SF and AF flags to zero in the EFLAGS register (regardless of whether an invalid-operation exception is detected).

The FCOMIP and FUCOMIP instructions also pop the register stack following the comparison operation. To pop the register stack, the processor marks the ST(0) register as empty and increments the stack pointer (TOP) by 1.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

### IA-32 Architecture Compatibility


The FCOMI/FCOMIP/FUCOMI/FUCOMIP instructions were introduced to the IA-32 Architecture in the P6 family processors and are not available in earlier IA-32 processors. 


### Operation

```info-verb
CASE (relation of operands) OF
    ST(0) > ST(i): ZF, PF, CF <- 000;
    ST(0) < ST(i): ZF, PF, CF <- 001;
    ST(0) = ST(i): ZF, PF, CF <- 100;
ESAC;
IF Instruction is FCOMI or FCOMIP
    THEN
          IF ST(0) or ST(i) = NaN or unsupported format
                THEN 
                      #IA
                      IF FPUControlWord.IM = 1
                            THEN 
                                  ZF, PF, CF <- 111;
                      FI;
          FI;
FI;
IF Instruction is FUCOMI or FUCOMIP
    THEN
          IF ST(0) or ST(i) = QNaN, but not SNaN or unsupported format
                THEN 
                      ZF, PF, CF <- 111;
                ELSE (* ST(0) or ST(i) is SNaN or unsupported format *)
                       #IA;
                      IF FPUControlWord.IM = 1
                            THEN 
                                  ZF, PF, CF <- 111;
                      FI;
          FI;
FI;
IF Instruction is FCOMIP or FUCOMIP 
    THEN 
          PopRegisterStack;
FI;
```
### FPU Flags Affected


C1 Set to 0.

C0, C2, C3  Not affected.

### Floating-Point Exceptions


#IS Stack underflow occurred.

#IA (FCOMI or FCOMIP instruction) One or both operands are NaN values or have unsupported formats.

                              (FUCOMI or FUCOMIP instruction) One or both operands are SNaN values (but not QNaNs) or have undefined formats. Detection of a QNaN value does not raise an invalid-operand excep-tion.


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

