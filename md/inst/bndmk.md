----------------------------
title : BNDMK (Intel x86/64 assembly instruction)
cat_title : BNDMK
ref_title : BNDMK
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BNDMK

**Make Bounds**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 1B /r\newline{}BNDMK bnd, m32|RM|NE/V|MPX|Make lower and upper bounds from m32 and store them in bnd.|
|F3 0F 1B /r\newline{}BNDMK bnd, m64|RM|V/NE|MPX|Make lower and upper bounds from m64 and store them in bnd.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|
### Description


Makes bounds from the second operand and stores the lower and upper bounds in the bound register bnd. The second operand must be a memory operand. The content of the base register from the memory operand is stored in the lower bound bnd.LB. The 1's complement of the effective address of m32/m64 is stored in the upper bound b.UB. Computation of m32/m64 has identical behavior to `LEA`.

This instruction does not cause any memory access, and does not read or write any flags. 

If the instruction did not specify base register, the lower bound will be zero. The reg-reg form of this instruction retains legacy behavior (NOP). 

RIP relative instruction in 64-bit will #UD.


### Operation

```info-verb
BND.LB <-  SRCMEM.base;
IF 64-bit mode Then
    BND.UB <-  NOT(LEA.64_bits(SRCMEM)); 
ELSE
    BND.UB <-  Zero_Extend.64_bits(NOT(LEA.32_bits(SRCMEM)));
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BNDMKvoid * _bnd_set_ptr_bounds(const void * q, size_t size); 
```
### Flags Affected


None


### Protected Mode Exceptions

#### #UD
* If ModRM is RIP relative.
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 67H prefix is not used and CS.D=0.
* If 67H prefix is used and CS.D=1.

### Real-Address Mode Exceptions

#### #UD
* If ModRM is RIP relative.
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

### Virtual-8086 Mode Exceptions

#### #UD
* If ModRM is RIP relative.
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If ModRM.r/m and REX encodes BND4-BND15 when Intel MPX is enabled.

#### #SS(0)
* If the memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.
* Same exceptions as in protected mode.
