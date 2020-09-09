----------------------------
title : VRSQRT14SS (Intel x86/64 assembly instruction)
cat_title : VRSQRT14SS
ref_title : VRSQRT14SS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VRSQRT14SS

**Compute Approximate Reciprocal of Square Root of Scalar Float32 Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F38.W0 4F /r\newline{}VRSQRT14SS xmm1 {k1}{z}, xmm2, xmm3/m32|T1S|V/V|AVX512F|Computes the approximate reciprocal square root of the scalar single-precision floating-point value in xmm3/m32 and stores the result in the low doubleword element of xmm1 using writemask k1. Bits[127:32] of xmm2 is copied to xmm1[127:32]. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
### Description


Computes of the approximate reciprocal of the square root of the scalar single-precision floating-point value in the low doubleword element of the source operand (the second operand) and stores the result in the low doubleword element of the destination operand (the first operand) according to the writemask. The maximum relative error for this approximation is less than 2\footnote{-14} . The source operand can be an XMM register or a 32-bit memory location. The destination operand is an XMM register. 

Bits (127:32) of the XMM register destination are copied from corresponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

The `VRSQRT14SS` instruction is not affected by the rounding control bits in the MXCSR register. When a source value is a 0.0, an $$\infty$$ with the sign of the source value is returned. When the source operand is an $$\infty$$, zero with the sign of the source value is returned. A denormal source value is treated as zero only if DAZ bit is set in MXCSR. Otherwise it is treated correctly and performs the approximation with the specified masked response. When a source value is a negative value (other than 0.0) a floating-point indefinite is returned. When a source value is an SNaN or QNaN, the SNaN is converted to a QNaN or the source QNaN is returned.

MXCSR exception flags are not affected by this instruction and floating-point exceptions are not reported.

A numerically exact implementation of VRSQRT14xx can be found at 

###                                                                                                        https://software.intel.com/en-us/arti-cles/reference-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VRSQRT14SS (EVEX version)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  APPROXIMATE(1.0/ SQRT(SRC2[31:0]))
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```
### Table 5-26. VRSQRT14SS Special Cases


|**Input value**|**Result value**|**Comments**|
|---------------|----------------|------------|
|Any denormal|Normal|Cannot generate overflow|
|X = 2\footnote{-2n}|2\footnote{n}||
|X < 0|QNaN_Indefinite|Including -INF|
|X = -0|-INF||
|X = +0|+INF||
|X = +INF|+0||

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRSQRT14SS __m128 _mm_rsqrt14_ss( __m128 a, __m128 b);
VRSQRT14SS __m128 _mm_mask_rsqrt14_ss(__m128 s, __mmask8 k, __m128 a, __m128 b);
VRSQRT14SS __m128 _mm_maskz_rsqrt14_ss( __mmask8 k, __m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E5.

