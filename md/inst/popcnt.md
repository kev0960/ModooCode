----------------------------
title : POPCNT (Intel x86/64 assembly instruction)
cat_title : POPCNT
ref_title : POPCNT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ POPCNT

** Return the Count of Number of Bits Set to 1**

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|F3  0F B8 /r|POPCNT r16, r/m16|RM|Valid|Valid|POPCNT on r/m16|
|F3  0F B8 /r|POPCNT r32, r/m32|RM|Valid|Valid|POPCNT on r/m32|
|F3 REX.W 0F B8 /r|POPCNT r64, r/m64|RM|Valid|N.E.|POPCNT on r/m64|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


This instruction calculates the number of bits set to 1 in the second operand (source) and returns the count in the first operand (a destination register).


### Operation

```info-verb
Count = 0;
For (i=0; i < OperandSize; i++) 
{   IF (SRC[ i] = 1) // i'th bit
          THEN Count++; FI;
}
DEST <-  Count;
```
### Flags Affected


OF, SF, ZF, AF, CF, PF are all cleared. ZF is set if SRC = 0, otherwise ZF is cleared.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
POPCNT:  int _mm_popcnt_u32(unsigned int a);
POPCNT:  int64_t _mm_popcnt_u64(unsigned __int64 a);
```

### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS or GS segments.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF
* (fault-code) For a page fault.

#### #AC(0)
* If an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled.

#### #UD
* If CPUID.01H:ECX.POPCNT [Bit 23] = 0.
* If LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP(0)
* If any part of the operand lies outside of the effective address space from 0 to 0FFFFH.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If CPUID.01H:ECX.POPCNT [Bit 23] = 0.
* If LOCK prefix is used.
### Virtual 8086 Mode Exceptions


#GP(0) If any part of the operand lies outside of the effective address space from 0 to 0FFFFH.

#SS(0) If a memory operand effective address is outside the SS segment limit.

#PF (fault-code) For a page fault.

#AC(0) If an unaligned memory reference is made while alignment checking is enabled.

#UD If CPUID.01H:ECX.POPCNT [Bit 23] = 0.

                              If LOCK prefix is used.


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

#### #UD
* If CPUID.01H:ECX.POPCNT [Bit 23] = 0.
* If LOCK prefix is used.
