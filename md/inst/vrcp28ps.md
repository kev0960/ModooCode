----------------------------
title : VRCP28PS (Intel x86/64 assembly instruction)
cat_title : VRCP28PS
ref_title : VRCP28PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VRCP28PS

**Approximation to the Reciprocal of Packed Single-Precision Floating-Point Values with Less Than 2^-28 Relative Error**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.512.66.0F38.W0 CA /r\newline{}VRCP28PS zmm1 {k1}{z}, zmm2/m512/m32bcst {sae}|FV|V/V|AVX512ER|Computes the approximate reciprocals ( < 2^-28 relative error) of the packed single-precision floating-point values in zmm2/m512/m32bcst and stores the results in zmm1. Under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Computes the reciprocal approximation of the float32 values in the source operand (the second operand) and store the results to the destination operand (the first operand) using the writemask k1. The approximate reciprocal is evaluated with less than 2^-28 of maximum relative error prior to final rounding. The final results are rounded to < 2^-23 relative error before written to the destination.

Denormal input values are treated as zeros and do not signal #DE, irrespective of MXCSR.DAZ. Denormal results are flushed to zeros and do not signal #UE, irrespective of MXCSR.FZ.

If any source element is NaN, the quietized NaN source value is returned for that element. If any source element is $$\pm$$' , $$\pm$$0.0 is returned for that element. Also, if any source element is $$\pm$$0.0, $$\pm$$'  is returned for that element.

The source operand is a ZMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM register, conditionally updated using writemask k1. 

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

A numerically exact implementation of VRCP28xx can be found at 

###                                                                                                    https://software.intel.com/en-us/articles/refer-ence-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VRCP28PS (EVEX encoded versions) 
```info-verb
(KL, VL) = (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN DEST[i+31:i] <-  RCP_28_SP(1.0/SRC[31:0]);
                      ELSE DEST[i+31:i] <-  RCP_28_SP(1.0/SRC[i+31:i]);
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
### Table 5-19. VRCP28PS Special Cases


|**Input value**|**Result value**|**Comments**|
|---------------|----------------|------------|
|NAN|QNAN(input)|If (SRC = SNaN) then #I|
|0 "  X < 2\footnote{-126}|INF|Positive input denormal or zero; #Z|
|-2\footnote{-126 } < X "  -0|-INF|Negative input denormal or zero; #Z|
|X > 2\footnote{126}|+0.0f||
|X < -2\footnote{126}|-0.0f||
|X = +'|+0.0f||
|X = -'|-0.0f||
|X = 2\footnote{-n}|2\footnote{n}|Exact result (unless input/output is a denormal)|
|X = -2\footnote{-n}|-2\footnote{n}|Exact result (unless input/output is a denormal)|

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRCP28PS _mm512_rcp28_round_ps ( __m512 a, int sae);
VRCP28PS __m512 _mm512_mask_rcp28_round_ps(__m512 s, __mmask16 m, __m512 a, int sae);
VRCP28PS __m512 _mm512_maskz_rcp28_round_ps( __mmask16 m, __m512 a, int sae);
```
### SIMD Floating-Point Exceptions


Invalid (if SNaN input), Divide-by-zero

### Other Exceptions


See Exceptions Type E2.

