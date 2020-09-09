----------------------------
title : VRSQRT28SD (Intel x86/64 assembly instruction)
cat_title : VRSQRT28SD
ref_title : VRSQRT28SD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VRSQRT28SD

**Approximation to the Reciprocal Square Root of Scalar Double-Precision Floating-Point Value with Less Than 2^-28 Relative Error**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F38.W1 CD /r\newline{}VRSQRT28SD xmm1 {k1}{z}, xmm2, xmm3/m64 {sae}|T1S|V/V|AVX512ER|Computes approximate reciprocal square root (<2^-28 relative error) of the scalar double-precision floating-point value from xmm3/m64 and stores result in xmm1with writemask k1. Also, upper double-precision floating-point value (bits[127:64]) from xmm2 is copied to xmm1[127:64].|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Computes the reciprocal square root of the low float64 value in the second source operand (the third operand) and store the result to the destination operand (the first operand). The approximate reciprocal square root is evaluated with less than 2^-28 of maximum relative error. The result is written into the low float64 element of xmm1 according to the writemask k1. Bits 127:64 of the destination is copied from the corresponding bits of the first source operand (the second operand).

If any source element is NaN, the quietized NaN source value is returned for that element. Negative (non-zero) source numbers, as well as -' , return the canonical NaN and set the Invalid Flag (#I).

A value of -0 must return -'  and set the DivByZero flags (#Z). Negative numbers should return NaN and set the Invalid flag (#I). Note however that the instruction flush input denormals to zero of the same sign, so negative denormals return -'  and set the DivByZero flag.

The first source operand is an XMM register. The second source operand is an XMM register or a 64-bit memory location. The destination operand is a XMM register. 

A numerically exact implementation of VRSQRT28xx can be found at 

###                                                                                                        https://software.intel.com/en-us/arti-cles/reference-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VRSQRT28SD (EVEX encoded versions) 
```info-verb
    IF k1[0] OR *no writemask* THEN
                 DEST[63: 0] <-  (1.0/ SQRT(SRC[63: 0]));
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63: 0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[63: 0] <-  0
          FI;
    FI;
ENDFOR;
DEST[127:64] <-  SRC1[127: 64]
DEST[MAX_VL-1:128] <-  0
```
### Table 5-28. VRSQRT28SD Special Cases


|**Input value**|**Result value**|**Comments**|
|---------------|----------------|------------|
|NAN|QNAN(input)|If (SRC = SNaN) then #I|
|X = 2\footnote{-2n}|2\footnote{n}||
|X < 0|QNaN_Indefinite|Including -INF|
|X = -0 or negative denormal|-INF|#Z|
|X = +0 or positive denormal|+INF|#Z|
|X = +INF|+0||

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRSQRT28SD __m128d _mm_rsqrt28_round_sd(__m128d a, __m128b b, int sae);
VRSQRT28SD __m128d _mm_mask_rsqrt28_round_pd(__m128d s, __mmask8 m,__m128d a, __m128d b, int sae);
VRSQRT28SD __m128d _mm_maskz_rsqrt28_round_pd( __mmask8 m,__m128d a, __m128d b, int sae);
```
### SIMD Floating-Point Exceptions


Invalid (if SNaN input), Divide-by-zero

### Other Exceptions


See Exceptions Type E3.

