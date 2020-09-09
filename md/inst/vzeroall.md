----------------------------
title : VZEROALL (Intel x86/64 assembly instruction)
cat_title : VZEROALL
ref_title : VZEROALL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VZEROALL

**Zero All YMM Registers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.256.0F.WIG 77\newline{}\newline{}VZEROALL|NP|V/V|AVX|Zero all YMM registers.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


The instruction zeros contents of all XMM or YMM registers.

Note: VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD. In Compatibility and legacy 32-bit mode only the lower 8 registers are modified.


### Operation
#### VZEROALL (VEX.256 encoded version)
```info-verb
IF (64-bit mode)
    YMM0[VLMAX-1:0] <-  0
    YMM1[VLMAX-1:0] <-  0
    YMM2[VLMAX-1:0] <-  0
    YMM3[VLMAX-1:0] <-  0
    YMM4[VLMAX-1:0] <-  0
    YMM5[VLMAX-1:0] <-  0
    YMM6[VLMAX-1:0] <-  0
    YMM7[VLMAX-1:0] <-  0
    YMM8[VLMAX-1:0] <-  0
    YMM9[VLMAX-1:0] <-  0
    YMM10[VLMAX-1:0] <-  0
    YMM11[VLMAX-1:0] <-  0
    YMM12[VLMAX-1:0] <-  0
    YMM13[VLMAX-1:0] <-  0
    YMM14[VLMAX-1:0] <-  0
    YMM15[VLMAX-1:0] <-  0
ELSE
    YMM0[VLMAX-1:0] <-  0
    YMM1[VLMAX-1:0] <-  0
    YMM2[VLMAX-1:0] <-  0
    YMM3[VLMAX-1:0] <-  0
    YMM4[VLMAX-1:0] <-  0
    YMM5[VLMAX-1:0] <-  0
    YMM6[VLMAX-1:0] <-  0
    YMM7[VLMAX-1:0] <-  0
    YMM8-15: Unmodified
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VZEROALL:  _mm256_zeroall()
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 8.

