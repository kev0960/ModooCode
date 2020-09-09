----------------------------
title : VEXP2PS (Intel x86/64 assembly instruction)
cat_title : VEXP2PS
ref_title : VEXP2PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VEXP2PS

**Approximation to the Exponential 2^x of Packed Single-Precision Floating-Point Values with Less Than 2^-23 Relative Error**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.512.66.0F38.W0 C8 /r\newline{}VEXP2PS zmm1 {k1}{z}, zmm2/m512/m32bcst {sae}|FV|V/V|AVX512ER|Computes approximations to the exponential 2^x (with less than 2^-23 of maximum relative error) of the packed single-precision floating-point values from zmm2/m512/m32bcst and stores the floating-point result in zmm1with writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
### Description


Computes the approximate base-2 exponential evaluation of the single-precision floating-point values in the source operand (the second operand) and store the results in the destination operand (the first operand) using the writemask k1. The approximate base-2 exponential is evaluated with less than 2^-23 of relative error. 

Denormal input values are treated as zeros and do not signal #DE, irrespective of MXCSR.DAZ. Denormal results are flushed to zeros and do not signal #UE, irrespective of MXCSR.FZ.

The source operand is a ZMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM register, conditionally updated using writemask k1. 

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

A numerically exact implementation of VEXP2xx can be found at 

###                                                                                                  https://software.intel.com/en-us/articles/refer-ence-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VEXP2PS 
```info-verb
(KL, VL) = (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN DEST[i+31:i] <-  EXP2_23_SP(SRC[31:0])
                      ELSE DEST[i+31:i] <-  EXP2_23_SP(SRC[i+31:i])
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[i+31:i] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[i+31:i] <-  0
          FI;
    FI;
ENDFOR;
```
### Table 5-5. Special Values Behavior


|**Source Input**|**Result**|**Comments**|
|----------------|----------|------------|
|NaN|QNaN(src)|If (SRC = SNaN) then #I|
|+'|+'||
|+/-0|1.0f|Exact result|
|-'|+0.0f||
|Integral value N|2^ (N)|Exact result|

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VEXP2PS __m512 _mm512_exp2a23_round_ps (__m512 a, int sae);
VEXP2PS __m512 _mm512_mask_exp2a23_round_ps (__m512 a, __mmask16 m, __m512 b, int sae);
VEXP2PS __m512 _mm512_maskz_exp2a23_round_ps (__mmask16 m, __m512 b, int sae);
```
### SIMD Floating-Point Exceptions


Invalid (if SNaN input), Overflow

### Other Exceptions


See Exceptions Type E2.

