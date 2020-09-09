----------------------------
title : BOUND (Intel x86/64 assembly instruction)
cat_title : BOUND
ref_title : BOUND
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BOUND

**Check Array Index Against Bounds**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|62 /r|BOUND r16, m16&16|RM|Invalid|Valid|Check if r16 (array index) is within bounds specified by m16&16.|
|62 /r|BOUND r32, m32&32|RM|Invalid|Valid|Check if r32 (array index) is within bounds specified by m32&32.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r)|ModRM:r/m (r)|NA|NA|
### Description


BOUND determines if the first operand (array index) is within the bounds of an array specified the second operand (bounds operand). The array index is a signed integer located in a register. The bounds operand is a memory loca-tion that contains a pair of signed doubleword-integers (when the operand-size attribute is 32) or a pair of signed word-integers (when the operand-size attribute is 16). The first doubleword (or word) is the lower bound of the array and the second doubleword (or word) is the upper bound of the array. The array index must be greater than or equal to the lower bound and less than or equal to the upper bound plus the operand size in bytes. If the index is not within bounds, a `BOUND` range exceeded exception (#BR) is signaled. When this exception is generated, the saved return instruction pointer points to the `BOUND` instruction.

The bounds limit data structure (two words or doublewords containing the lower and upper limits of the array) is usually placed just before the array itself, making the limits addressable via a constant offset from the beginning of the array. Because the address of the array already will be present in a register, this practice avoids extra bus cycles to obtain the effective address of the array bounds.

This instruction executes as described in compatibility mode and legacy mode. It is not valid in 64-bit mode.


### Operation

```info-verb
IF 64bit ModeTHEN#UD;ELSEIF (ArrayIndex < LowerBound OR ArrayIndex > UpperBound)
          (* Below lower bound or above upper bound *)
                THEN #BR; FI;
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #BR
* If the bounds test fails.

#### #UD
* If second operand is not a memory location.
* If the LOCK prefix is used.

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

### Real-Address Mode Exceptions

#### #BR
* If the bounds test fails.

#### #UD
* If second operand is not a memory location.
* If the LOCK prefix is used.

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

### Virtual-8086 Mode Exceptions

#### #BR
* If the bounds test fails.

#### #UD
* If second operand is not a memory location.
* If the LOCK prefix is used.

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If in 64-bit mode.
