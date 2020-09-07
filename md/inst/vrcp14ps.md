----------------------------
title : VRCP14PS (Intel x86/64 assembly instruction)
cat_title : VRCP14PS
ref_title : VRCP14PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VRCP14PS

**Compute Approximate Reciprocals of Packed Float32 Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W0 4C /r\newline{}VRCP14PS xmm1 {k1}{z}, xmm2/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Computes the approximate reciprocals of the packed single-precision floating-point values in xmm2/m128/m32bcst and stores the results in xmm1. Under writemask.|
|EVEX.256.66.0F38.W0 4C /r\newline{}VRCP14PS ymm1 {k1}{z}, ymm2/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Computes the approximate reciprocals of the packed single-precision floating-point values in ymm2/m256/m32bcst and stores the results in ymm1. Under writemask.|
|EVEX.512.66.0F38.W0 4C /r\newline{}VRCP14PS zmm1 {k1}{z}, zmm2/m512/m32bcst|FV|V/V|AVX512F|Computes the approximate reciprocals of the packed single-precision floating-point values in zmm2/m512/m32bcst and stores the results in zmm1. Under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


This instruction performs a SIMD computation of the approximate reciprocals of the packed single-precision floating-point values in the source operand (the second operand) and stores the packed single-precision floating-point results in the destination operand (the first operand). The maximum relative error for this approximation is less than 2\footnote{-14} . 

The source operand can be a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM register conditionally updated according to the writemask.

The `VRCP14PS` instruction is not affected by the rounding control bits in the MXCSR register. When a source value is a 0.0, an $$\infty$$ with the sign of the source value is returned. A denormal source value will be treated as zero only in case of DAZ bit set in MXCSR. Otherwise it is treated correctly (i.e. not as a 0.0). Underflow results are flushed to zero only in case of FTZ bit set in MXCSR. Otherwise it will be treated correctly (i.e. correct underflow result is written) with the sign of the operand. When a source value is a SNaN or QNaN, the SNaN is converted to a QNaN or the source QNaN is returned.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

MXCSR exception flags are not affected by this instruction and floating-point exceptions are not reported.

###                                                  Table 5-16. VRCP14PS/VRCP14SS Special Cases


\htmlonly{*} in this case the mantissa is shifted right by one or two bits

A numerically exact implementation of VRCP14xx can be found at 



|**Input value**|**Result value**|**Comments**|
|---------------|----------------|------------|
|0 "  X "  2\footnote{-128}|INF|Very small denormal|
|-2\footnote{-128 } "  X "  -0|-INF|Very small denormal|
|X > 2\footnote{126}|Underflow|Up to 18 bits of fractions are returned\htmlonly{*}|
|X < -2\footnote{126}|-Underflow|Up to 18 bits of fractions are returned\htmlonly{*}|
|X = 2\footnote{-n}|2\footnote{n}||
|X = -2\footnote{-n}|-2\footnote{n}||
###                                                                                                    https://software.intel.com/en-us/articles/refer-ence-implementations-for-IA-approximation-instructions-vrcp14-vrsqrt14-vrcp28-vrsqrt28-vexp2.

### Operation
#### VRCP14PS (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN DEST[i+31:i] <-  APPROXIMATE(1.0/SRC[31:0]);
                      ELSE DEST[i+31:i] <-  APPROXIMATE(1.0/SRC[i+31:i]);
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[i+31:i] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[i+31:i] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRCP14PS __m512 _mm512_rcp14_ps( __m512 a);
VRCP14PS __m512 _mm512_mask_rcp14_ps(__m512 s, __mmask16 k, __m512 a);
VRCP14PS __m512 _mm512_maskz_rcp14_ps( __mmask16 k, __m512 a);
VRCP14PS __m256 _mm256_rcp14_ps( __m256 a);
VRCP14PS __m256 _mm512_mask_rcp14_ps(__m256 s, __mmask8 k, __m256 a);
VRCP14PS __m256 _mm512_maskz_rcp14_ps( __mmask8 k, __m256 a);
VRCP14PS __m128 _mm_rcp14_ps( __m128 a);
VRCP14PS __m128 _mm_mask_rcp14_ps(__m128 s, __mmask8 k, __m128 a);
VRCP14PS __m128 _mm_maskz_rcp14_ps( __mmask8 k, __m128 a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4.

