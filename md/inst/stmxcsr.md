----------------------------
title : STMXCSR (Intel x86/64 assembly instruction)
cat_title : STMXCSR
ref_title : STMXCSR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ STMXCSR

**Store MXCSR Register State**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F AE /3\newline{}STMXCSR m32|M|V/V|SSE|Store contents of MXCSR register to m32.|
|VEX.LZ.0F.WIG AE /3\newline{}VSTMXCSR m32|M|V/V|AVX|Store contents of MXCSR register to m32.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Stores the contents of the MXCSR control and status register to the destination operand. The destination operand is a 32-bit memory location. The reserved bits in the MXCSR register are stored as 0s.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

VEX.L must be 0, otherwise instructions will #UD.

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation

```info-verb
m32 <- MXCSR;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
_mm_getcsr(void)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 5; additionally

#UD If VEX.L= 1,

                              If VEX.vvvv ->  1111B.

