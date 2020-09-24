----------------------------
title : BNDCL (Intel x86/64 assembly instruction)
cat_title : BNDCL
ref_title : BNDCL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BNDCL

**Check Lower Bound**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 1A /r`\newline{}`BNDCL` \tooltip{bnd}{128 비트 바운드 레지스터. BND0 부터 BND3 까지 가능하다. } \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|NE/V|MPX|Generate a #BR if the address in r/m32 is lower than the lower bound in bnd.LB.|
|`F3 0F 1A /r`\newline{}`BNDCL` \tooltip{bnd}{128 비트 바운드 레지스터. BND0 부터 BND3 까지 가능하다. } \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|V/NE|MPX|Generate a #BR if the address in r/m64 is lower than the lower bound in bnd.LB.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|
### Description


Compare the address in the second operand with the lower bound in bnd. The second operand can be either a register or memory operand. If the address is lower than the lower bound in bnd.LB, it will set BNDSTATUS to 01H and signal a #BR exception.

This instruction does not cause any memory access, and does not read or write any flags. 


### Operation
#### BNDCL BND, reg
```info-verb
IF reg < BND.LB Then
    BNDSTATUS <-  01H; 
    #BR; 
FI;
```
#### BNDCL BND, mem
```info-verb
TEMP <-  LEA(mem); 
IF TEMP < BND.LB Then
    BNDSTATUS <-  01H; 
    #BR; 
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BNDCL void   _bnd_chk_ptr_lbounds(const void *q)
```
### Flags Affected


None


### Protected Mode Exceptions

#### #BR
* If lower bound check fails.

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 67H prefix is not used and CS.D=0.
* If 67H prefix is used and CS.D=1.

### Real-Address Mode Exceptions

#### #BR
* If lower bound check fails.

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

### Virtual-8086 Mode Exceptions

#### #BR
* If lower bound check fails.

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
