----------------------------
title : FDECSTP (Intel x86/64 assembly instruction)
cat_title : FDECSTP
ref_title : FDECSTP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FDECSTP

**Decrement Stack-Top Pointer**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 F6|`FDECSTP` |Valid|Valid|Decrement TOP field in FPU status word.|
### Description


Subtracts one from the TOP field of the FPU status word (decrements the top-of-stack pointer). If the TOP field contains a 0, it is set to 7. The effect of this instruction is to rotate the stack by one position. The contents of the FPU data registers and tag register are not affected. 

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF TOP = 0
    THEN TOP <- 7;
    ELSE TOP <- TOP - 1;
FI;
```
### FPU Flags Affected


The C1 flag is set to 0. The C0, C2, and C3 flags are undefined.

### Floating-Point Exceptions


None.


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

