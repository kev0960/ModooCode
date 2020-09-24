----------------------------
title : LZCNT (Intel x86/64 assembly instruction)
cat_title : LZCNT
ref_title : LZCNT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LZCNT

** Count the Number of Leading Zero Bits**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F BD /r`\newline{} |RM|V/V|LZCNT|Count the number of leading zero bits in r/m16, return result in r16.|
|``\newline{}`LZCNT` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |||||
|`F3 0F BD /r`\newline{} |RM|V/V|LZCNT|Count the number of leading zero bits in r/m32, return result in r32.|
|``\newline{}`LZCNT` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |||||
|`F3 REX.W 0F BD /r`\newline{} |RM|V/N.E.|LZCNT|Count the number of leading zero bits in r/m64, return result in r64.|
|``\newline{}`LZCNT` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |||||
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description 


Counts the number of leading most significant zero bits in a source operand (second operand) returning the result into a destination (first operand). 

LZCNT differs from BSR. For example, LZCNT will produce the operand size when the input operand is zero. It should be noted that on processors that do not support LZCNT, the instruction byte encoding is executed as BSR. 

In 64-bit mode 64-bit operand size requires REX.W=1. 


### Operation

```info-verb
temp <- OperandSize - 1
DEST <- 0
WHILE (temp >= 0) AND (Bit(SRC, temp) = 0)
DO
    temp <- temp - 1
    DEST <- DEST+ 1
OD
IF DEST = OperandSize
    CF <- 1
ELSE
    CF <- 0
FI
IF DEST = 0
    ZF <- 1
ELSE
    ZF <- 0
FI
```
### Flags Affected


ZF flag is set to 1 in case of zero output (most significant bit of the source is set), and to 0 otherwise, CF flag is set to 1 if input was zero and cleared otherwise. OF, SF, PF and AF flags are undefined.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
LZCNT: unsigned __int32 _lzcnt_u32(unsigned __int32 src);
LZCNT: unsigned __int64 _lzcnt_u64(unsigned __int64 src);
```

### Protected Mode Exceptions

#### #GP(0)
* For an illegal memory operand effective address in the CS, DS, ES, FS or GS segments.
* If the DS, ES, FS, or GS register is used to access memory and it contains a null segment selector.

#### #SS(0)
* For an illegal address in the SS segment.

#### #PF
* (fault-code) For a page fault.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

### Real-Address Mode Exceptions

#### #GP(0)
* If any part of the operand lies outside of the effective address space from 0 to 0FFFFH.

#### #SS(0)
* For an illegal address in the SS segment.
### Virtual 8086 Mode Exceptions


#GP(0) If any part of the operand lies outside of the effective address space from 0 to 0FFFFH.

#SS(0) For an illegal address in the SS segment.

#PF (fault-code) For a page fault.

#AC(0) If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.


### Compatibility Mode Exceptions



Same exceptions as in Protected Mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #PF
* (fault-code) For a page fault.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.
