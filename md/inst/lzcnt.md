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
|F3 0F BD /r|RM|V/V|LZCNT|Count the number of leading zero bits in r/m16, return result in r16.|
|LZCNT r16, r/m16|||||
|F3 0F BD /r|RM|V/V|LZCNT|Count the number of leading zero bits in r/m32, return result in r32.|
|LZCNT r32, r/m32|||||
|F3 REX.W 0F BD /r|RM|V/N.E.|LZCNT|Count the number of leading zero bits in r/m64, return result in r64.|
|LZCNT r64, r/m64|||||
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