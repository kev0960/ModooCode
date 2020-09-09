----------------------------
title : BNDCU, BNDCNs (Intel x86/64 assembly instruction)
cat_title : BNDCU, BNDCN
ref_title : BNDCU, BNDCN
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BNDCU, BNDCN

**Check Upper Bound**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F 1A /r\newline{}BNDCU bnd, r/m32|RM|NE/V|MPX|Generate a #BR if the address in r/m32 is higher than the upper bound in bnd.UB (bnb.UB in 1's complement form).|
|F2 0F 1A /r\newline{}BNDCU bnd, r/m64|RM|V/NE|MPX|Generate a #BR if the address in r/m64 is higher than the upper bound in bnd.UB (bnb.UB in 1's complement form).|
|F2 0F 1B /r\newline{}BNDCN bnd, r/m32|RM|NE/V|MPX|Generate a #BR if the address in r/m32 is higher than the upper bound in bnd.UB (bnb.UB not in 1's complement form).|
|F2 0F 1B /r\newline{}BNDCN bnd, r/m64|RM|V/NE|MPX|Generate a #BR if the address in r/m64 is higher than the upper bound in bnd.UB (bnb.UB not in 1's complement form).|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|
### Description


Compare the address in the second operand with the upper bound in bnd. The second operand can be either a register or a memory operand. If the address is higher than the upper bound in bnd.UB, it will set BNDSTATUS to 01H and signal a #BR exception.

BNDCU perform 1's complement operation on the upper bound of bnd first before proceeding with address compar-ison. `BNDCN` perform address comparison directly using the upper bound in bnd that is already reverted out of 1's complement form. 

This instruction does not cause any memory access, and does not read or write any flags. 

Effective address computation of m32/64 has identical behavior to LEA


### Operation
#### BNDCU BND, reg
```info-verb
IF reg > NOT(BND.UB) Then
    BNDSTATUS <-  01H; 
    #BR; 
FI;
```
#### BNDCU BND, mem
```info-verb
TEMP <-  LEA(mem); 
IF TEMP > NOT(BND.UB) Then
    BNDSTATUS <-  01H; 
    #BR; 
FI;
```
#### BNDCN BND, reg
```info-verb
IF reg > BND.UB Then
    BNDSTATUS <-  01H; 
    #BR; 
FI;
```
#### BNDCN BND, mem
```info-verb
TEMP <-  LEA(mem); 
IF TEMP > BND.UB Then
    BNDSTATUS <-  01H; 
    #BR; 
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BNDCU .void   _bnd_chk_ptr_ubounds(const void *q)
```
### Flags Affected


None


### Protected Mode Exceptions

#### #BR
* If upper bound check fails.

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 67H prefix is not used and CS.D=0.
* If 67H prefix is used and CS.D=1.

### Real-Address Mode Exceptions

#### #BR
* If upper bound check fails.

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

### Virtual-8086 Mode Exceptions

#### #BR
* If upper bound check fails.

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If ModRM.r/m and REX encodes BND4-BND15 when Intel MPX is enabled.
* Same exceptions as in protected mode.
