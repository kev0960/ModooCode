----------------------------
title : RORX (Intel x86/64 assembly instruction)
cat_title : RORX
ref_title : RORX
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RORX

** Rotate Right Logical Without Affecting Flags**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.LZ.F2.0F3A.W0 F0 /r ib\newline{}RORX r32, r/m32, imm8|RMI|V/V|BMI2|Rotate 32-bit r/m32 right imm8 times without affecting arithmetic flags.|
|VEX.LZ.F2.0F3A.W1 F0 /r ib\newline{}RORX r64, r/m64, imm8|RMI|V/N.E.|BMI2|Rotate 64-bit r/m64 right imm8 times without affecting arithmetic flags.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description 


Rotates the bits of second operand right by the count value specified in imm8 without affecting arithmetic flags. The RORX instruction does not read or write the arithmetic flags.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.


### Operation

```info-verb
IF (OperandSize = 32)
    y <- imm8 AND 1FH;
    DEST <- (SRC >> y) | (SRC << (32-y));
ELSEIF (OperandSize = 64 ) 
    y <- imm8 AND 3FH;
    DEST <- (SRC >> y) | (SRC << (64-y));
ENDIF
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
Auto-generated from high-level language.
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

