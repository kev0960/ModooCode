----------------------------
title : FXCH (Intel x86/64 assembly instruction)
cat_title : FXCH
ref_title : FXCH
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/F
publish_date: 2020-09-01
----------------------------


#@ FXCH

**Exchange Register Contents**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|-----------------------------|---------------------------------|---------------|
|D9 C8+i|`FXCH` \tooltip{ST(i)}{FPU 레지스터 스택에서 최상단으로 부터 i 번째 원소로 i 의 값으로 0 부터 7 까지가 가능하다.} |Valid|Valid|Exchange the contents of ST(0) and ST(i).|
|D9 C9|`FXCH` |Valid|Valid|Exchange the contents of ST(0) and ST(1).|
### Description


Exchanges the contents of registers ST(0) and ST(i). If no source operand is specified, the contents of ST(0) and ST(1) are exchanged.

This instruction provides a simple means of moving values in the FPU register stack to the top of the stack [ST(0)], so that they can be operated on by those floating-point instructions that can only operate on values in ST(0). For example, the following instruction sequence takes the square root of the third register from the top of the register stack:

    `FXCH` ST(3);

    FSQRT;

    `FXCH` ST(3);

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF (Number-of-operands) is 1
    THEN
          temp <- ST(0);
          ST(0) <- SRC;
          SRC <- temp;
    ELSE
          temp <- ST(0);
          ST(0) <- ST(1);
          ST(1) <- temp;
FI;
```
### FPU Flags Affected


C1 Set to 0.

C0, C2, C3  Undefined.

### Floating-Point Exceptions


#IS Stack underflow occurred.


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

