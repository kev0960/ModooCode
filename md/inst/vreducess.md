----------------------------
title : VREDUCESS (Intel x86/64 assembly instruction)
cat_title : VREDUCESS
ref_title : VREDUCESS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VREDUCESS

**Perform a Reduction Transformation on a Scalar Float32 Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F3A.W0 57 /r /ib\newline{}VREDUCESS xmm1 {k1}{z}, xmm2, xmm3/m32{sae}, imm8|T1S|V/V|AVX512DQ|Perform a reduction transformation on a scalar single-precision floating point value in xmm3/m32 by subtracting a number of fraction bits specified by the imm8 field. Also, upper single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32]. Stores the result in xmm1 register.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Perform a reduction transformation of the binary encoded single-precision FP value in the low dword element of the second source operand (the third operand) and store the reduced result in binary FP format to the low dword element of the destination operand (the first operand) under the writemask k1. Bits 127:32 of the destination operand are copied from respective dword elements of the first source operand (the second operand). 

The reduction transformation subtracts the integer part and the leading M fractional bits from the binary FP source value, where M is a unsigned integer specified by imm8[7:4], see Figure 5-28. Specifically, the reduction transfor-mation can be expressed as:

dest = src - (ROUND(2\footnote{M} \htmlonly{\esc{*}}src))\htmlonly{\esc{*}}2\footnote{-M} ;

where "Round()" treats "src", "2\footnote{M} ", and their product as binary FP numbers with normalized significand and bi-ased exponents.

The magnitude of the reduced result can be expressed by considering src= 2\footnote{p} \htmlonly{\esc{*}}man2,

where 'man2' is the normalized significand and 'p' is the unbiased exponent 

Then if RC = RNE: 0<=|Reduced Result|<=2\footnote{p-M-1}

Then if RC ->  RNE: 0<=|Reduced Result|<2\footnote{p-M}

This instruction might end up with a precision exception set. However, in case of SPE set (i.e. Suppress Precision Exception, which is imm8[3]=1), no precision exception is reported.

Handling of special case of input values are listed in Table 5-21.


### Operation
#### VREDUCESS 
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  ReduceArgumentSP(SRC2[31:0], imm8[7:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] = 0
          FI;
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VREDUCESS __m128 _mm_mask_reduce_ss( __m128 a, __m128 b, int imm, int sae)
VREDUCESS __m128 _mm_mask_reduce_ss(__m128 s, __mmask16 k, __m128 a, __m128 b, int imm, int sae)
VREDUCESS __m128 _mm_maskz_reduce_ss(__mmask16 k, __m128 a, __m128 b, int imm, int sae)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

If SPE is enabled, precision exception is not reported (regardless of MXCSR exception mask).

### Other Exceptions


See Exceptions Type E3.

