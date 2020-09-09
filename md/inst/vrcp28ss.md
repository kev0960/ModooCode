----------------------------
title : VRCP28SS (Intel x86/64 assembly instruction)
cat_title : VRCP28SS
ref_title : VRCP28SS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VRCP28SS

**Approximation to the Reciprocal of Scalar Single-Precision Floating-Point Value with Less Than 2^-28 Relative Error**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F38.W0 CB /r\newline{}VRCP28SS xmm1 {k1}{z}, xmm2, xmm3/m32 {sae}|T1S|V/V|AVX512ER|Computes the approximate reciprocal ( < 2^-28 relative error) of the scalar single-precision floating-point value in xmm3/m32 and stores the results in xmm1. Under writemask. Also, upper 3 single-precision floating-point values (bits[127:32]) from xmm2 is copied to xmm1[127:32].|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Computes the reciprocal approximation of the low float32 value in the second source operand (the third operand) and store the result to the destination operand (the first operand). The approximate reciprocal is evaluated with less than 2^-28 of maximum relative error prior to final rounding. The final result is rounded to < 2^-23 relative error before written into the low float32 element of the destination according to writemask k1. Bits 127:32 of the destination is copied from the corresponding bits of the first source operand (the second operand).

A denormal input value is treated as zero and does not signal #DE, irrespective of MXCSR.DAZ. A denormal result is flushed to zero and does not signal #UE, irrespective of MXCSR.FZ.

If any source element is NaN, the quietized NaN source value is returned for that element. If any source element is $$\pm$$' , $$\pm$$0.0 is returned for that element. Also, if any source element is $$\pm$$0.0, $$\pm$$'  is returned for that element.

The first source operand is an XMM register. The second source operand is an XMM register or a 32-bit memory location. The destination operand is a XMM register, conditionally updated using writemask k1. 

A numerically exact implementation of VRCP28xx can be found at 

###                                                                                                    https://software.intel.com/en-us/articles/refer-ence-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VRCP28SS ((EVEX encoded versions) 
```info-verb
IF k1[0] OR *no writemask* THEN
                DEST[31: 0] <-  RCP_28_SP(1.0/SRC2[31: 0]);
ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31: 0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[31: 0] <-  0
          FI;
FI;
ENDFOR;
DEST[127:32] <-  SRC1[127: 32]
DEST[MAX_VL-1:128] <-  0
```
### Table 5-20. VRCP28SS Special Cases


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
VRCP28SS __m128 _mm_rcp28_round_ss ( __m128 a, __m128 b, int sae);
VRCP28SS __m128 _mm_mask_rcp28_round_ss(__m128 s, __mmask8 m, __m128 a, __m128 b, int sae);
VRCP28SS __m128 _mm_maskz_rcp28_round_ss(__mmask8 m, __m128 a, __m128 b, int sae);
```
### SIMD Floating-Point Exceptions


Invalid (if SNaN input), Divide-by-zero

### Other Exceptions


See Exceptions Type E3.

