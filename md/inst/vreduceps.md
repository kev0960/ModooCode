----------------------------
title : VREDUCEPS (Intel x86/64 assembly instruction)
cat_title : VREDUCEPS
ref_title : VREDUCEPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VREDUCEPS

**Perform Reduction Transformation on Packed Float32 Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F3A.W0 56 /r ib\newline{}VREDUCEPS xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Perform reduction transformation on packed single-precision floating point values in xmm2/m128/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register under writemask k1.|
|EVEX.256.66.0F3A.W0 56 /r ib\newline{}VREDUCEPS ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Perform reduction transformation on packed single-precision floating point values in ymm2/m256/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register under writemask k1.|
|EVEX.512.66.0F3A.W0 56 /r ib\newline{}VREDUCEPS zmm1 {k1}{z}, zmm2/m512/m32bcst{sae}, imm8|FV|V/V|AVX512DQ|Perform reduction transformation on packed single-precision floating point values in zmm2/m512/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description


Perform reduction transformation of the packed binary encoded single-precision FP values in the source operand (the second operand) and store the reduced results in binary FP format to the destination operand (the first operand) under the writemask k1. 

The reduction transformation subtracts the integer part and the leading M fractional bits from the binary FP source value, where M is a unsigned integer specified by imm8[7:4], see Figure 5-28. Specifically, the reduction transfor-mation can be expressed as:

dest = src - (ROUND(2\footnote{M} \htmlonly{\esc{*}}src))\htmlonly{\esc{*}}2\footnote{-M} ;

where "Round()" treats "src", "2\footnote{M} ", and their product as binary FP numbers with normalized significand and bi-ased exponents.

The magnitude of the reduced result can be expressed by considering src= 2\footnote{p} \htmlonly{\esc{*}}man2,

where 'man2' is the normalized significand and 'p' is the unbiased exponent 

Then if RC = RNE: 0<=|Reduced Result|<=2\footnote{p-M-1}

Then if RC ->  RNE: 0<=|Reduced Result|<2\footnote{p-M}

This instruction might end up with a precision exception set. However, in case of SPE set (i.e. Suppress Precision Exception, which is imm8[3]=1), no precision exception is reported.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

Handling of special case of input values are listed in Table 5-21.


### Operation
#### VREDUCEPS 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b == 1) AND (SRC *is memory*)
                      THEN DEST[i+31:i] <-  ReduceArgumentSP(SRC[31:0], imm8[7:0]);
                      ELSE DEST[i+31:i] <-  ReduceArgumentSP(SRC[i+31:i], imm8[7:0]);
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[i+31:i] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[i+31:i] = 0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VREDUCEPS __m512 _mm512_mask_reduce_ps( __m512 a, int imm, int sae)
VREDUCEPS __m512 _mm512_mask_reduce_ps(__m512 s, __mmask16 k, __m512 a, int imm, int sae)
VREDUCEPS __m512 _mm512_maskz_reduce_ps(__mmask16 k, __m512 a, int imm, int sae)
VREDUCEPS __m256 _mm256_mask_reduce_ps( __m256 a, int imm)
VREDUCEPS __m256 _mm256_mask_reduce_ps(__m256 s, __mmask8 k, __m256 a, int imm)
VREDUCEPS __m256 _mm256_maskz_reduce_ps(__mmask8 k, __m256 a, int imm)
VREDUCEPS __m128 _mm_mask_reduce_ps( __m128 a, int imm)
VREDUCEPS __m128 _mm_mask_reduce_ps(__m128 s, __mmask8 k, __m128 a, int imm)
VREDUCEPS __m128 _mm_maskz_reduce_ps(__mmask8 k, __m128 a, int imm)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

If SPE is enabled, precision exception is not reported (regardless of MXCSR exception mask).

### Other Exceptions


See Exceptions Type E2, additionally

#UD  If EVEX.vvvv != 1111B.

