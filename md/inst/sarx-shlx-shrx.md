----------------------------
title : SARX, SHLX, SHRXs (Intel x86/64 assembly instruction)
cat_title : SARX, SHLX, SHRX
ref_title : SARX, SHLX, SHRX
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SARX, SHLX, SHRX

** Shift Without Affecting Flags**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.LZ.F3.0F38.W0 F7 /r`\newline{}`SARX` r32a \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} r32b |RMV|V/V|BMI2|Shift r/m32 arithmetically right with count specified in r32b.|
|`VEX.NDS.LZ.66.0F38.W0 F7 /r`\newline{}`SHLX` r32a \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} r32b |RMV|V/V|BMI2|Shift r/m32 logically left with count specified in r32b.|
|`VEX.NDS.LZ.F2.0F38.W0 F7 /r`\newline{}`SHRX` r32a \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} r32b |RMV|V/V|BMI2|Shift r/m32 logically right with count specified in r32b.|
|`VEX.NDS.LZ.F3.0F38.W1 F7 /r`\newline{}`SARX` r64a \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} r64b |RMV|V/N.E.|BMI2|Shift r/m64 arithmetically right with count specified in r64b.|
|`VEX.NDS.LZ.66.0F38.W1 F7 /r`\newline{}`SHLX` r64a \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} r64b |RMV|V/N.E.|BMI2|Shift r/m64 logically left with count specified in r64b.|
|`VEX.NDS.LZ.F2.0F38.W1 F7 /r`\newline{}`SHRX` r64a \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} r64b |RMV|V/N.E.|BMI2|Shift r/m64 logically right with count specified in r64b.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMV|ModRM:reg (w)|ModRM:r/m (r)|VEX.vvvv (r)|NA|
### Description


Shifts the bits of the first source operand (the second operand) to the left or right by a COUNT value specified in the second source operand (the third operand). The result is written to the destination operand (the first operand).

The shift arithmetic right (SARX) and shift logical right (SHRX) instructions shift the bits of the destination operand to the right (toward less significant bit locations), `SARX` keeps and propagates the most significant bit (sign bit) while shifting.

The logical shift left (SHLX) shifts the bits of the destination operand to the left (toward more significant bit loca-tions). 

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.

If the value specified in the first source operand exceeds OperandSize -1, the COUNT value is masked.

SARX,`SHRX`, and `SHLX` instructions do not update flags. 


### Operation

```info-verb
TEMP <- SRC1;
IF VEX.W1 and CS.L = 1
THEN
    countMASK <-3FH;
ELSE
    countMASK <-1FH;
FI
COUNT <- (SRC2 AND countMASK)
DEST[OperandSize -1] = TEMP[OperandSize -1];
DO WHILE (COUNT ->  0)
    IF instruction is SHLX
          THEN
                DEST[] <- DEST *2;
ELSE IF instruction is SHRX
                THEN
                      DEST[] <- DEST /2; //unsigned divide
          ELSE // SARX
                      DEST[] <- DEST /2; // signed divide, round toward negative infinity
    FI;
    COUNT <- COUNT - 1;
OD
```
### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
Auto-generated from high-level language.
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

