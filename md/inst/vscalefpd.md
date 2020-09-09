----------------------------
title : VSCALEFPD (Intel x86/64 assembly instruction)
cat_title : VSCALEFPD
ref_title : VSCALEFPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VSCALEFPD

**Scale Packed Float64 Values With Float64 Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F38.W1 2C /r \newline{}VSCALEFPD xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Scale the packed double-precision floating-point values in xmm2 using values from xmm3/m128/m64bcst. Under writemask k1.|
|EVEX.NDS.256.66.0F38.W1 2C /r \newline{}VSCALEFPD ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Scale the packed double-precision floating-point values in ymm2 using values from ymm3/m256/m64bcst. Under writemask k1.|
|EVEX.NDS.512.66.0F38.W1 2C /r \newline{}VSCALEFPD zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst{er}|FV|V/V|AVX512F|Scale the packed double-precision floating-point values in zmm2 using values from zmm3/m512/m64bcst. Under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a floating-point scale of the packed double-precision floating-point values in the first source operand by multiplying it by 2 power of the double-precision floating-point values in second source operand.

The equation of this operation is given by:

zmm1 := zmm2\htmlonly{\esc{*}}2\footnote{floor(zmm3)} .

Floor(zmm3) means maximum integer value "  zmm3.

If the result cannot be represented in double precision, then the proper overflow response (for positive scaling operand), or the proper underflow response (for negative scaling operand) is issued. The overflow and underflow responses are dependent on the rounding mode (for IEEE-compliant rounding), as well as on other settings in MXCSR (exception mask bits, FTZ bit), and on the SAE bit.

The first source operand is a ZMM/YMM/XMM register. The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

Handling of special-case input values are listed in Table 5-31 and Table 5-32.

### Table 5-31. \VSCALEFPD/SD/PS/SS Special Cases


||||**S**|**rc2**||**Set IE**|
||||-----|-------||----------|
|||**$$\pm$$NaN**|**+Inf**|**-Inf**|**0/Denorm/Norm**||
|**Src1**|$$\pm$$QNaN|QNaN(Src1)|+INF|+0|QNaN(Src1)|IF either source is SNAN|
||$$\pm$$SNaN|QNaN(Src1)|QNaN(Src1)|QNaN(Src1)|QNaN(Src1)|YES|
||$$\pm$$Inf|QNaN(Src2)|Src1|QNaN_Indefinite|Src1|IF Src2 is SNAN or -INF|
||$$\pm$$0|QNaN(Src2)|QNaN_Indefinite|Src1|Src1|IF Src2 is SNAN or +INF|
||Denorm/Norm|QNaN(Src2)|$$\pm$$INF (Src1 sign)|$$\pm$$0 (Src1 sign)|Compute Result|IF Src2 is SNAN|
### Table 5-32. Additional VSCALEFPD/SD Special Cases


|**Special Case**|** Returned value **|**Faults**|
|----------------|--------------------|----------|
||result| < 2\footnote{-1074}|$$\pm$$0 or $$\pm$$Min-Denormal (Src1 sign)|Underflow|
||result| *   2\footnote{1024}|$$\pm$$INF (Src1 sign) or $$\pm$$Max-normal (Src1 sign)|Overflow|

### Operation
#### VSCALEFPD (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1) AND (SRC2 *is register*)
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  SCALE(SRC1[i+63:i], SRC2[63:0]);
                      ELSE DEST[i+63:i] <-  SCALE(SRC1[i+63:i], SRC2[i+63:i]);
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSCALEFPD __m512d _mm512_scalef_round_pd(__m512d a, __m512d b, int);
VSCALEFPD __m512d _mm512_mask_scalef_round_pd(__m512d s, __mmask8 k, __m512d a, __m512d b, int);
VSCALEFPD __m512d _mm512_maskz_scalef_round_pd(__mmask8 k, __m512d a, __m512d b, int);
VSCALEFPD __m256d _mm256_scalef_round_pd(__m256d a, __m256d b, int);
VSCALEFPD __m256d _mm256_mask_scalef_round_pd(__m256d s, __mmask8 k, __m256d a, __m256d b, int);
VSCALEFPD __m256d _mm256_maskz_scalef_round_pd(__mmask8 k, __m256d a, __m256d b, int);
VSCALEFPD __m128d _mm_scalef_round_pd(__m128d a, __m128d b, int);
VSCALEFPD __m128d _mm_mask_scalef_round_pd(__m128d s, __mmask8 k, __m128d a, __m128d b, int);
VSCALEFPD __m128d _mm_maskz_scalef_round_pd(__mmask8 k, __m128d a, __m128d b, int);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal (for Src1).

Denormal is not reported for Src2.

### Other Exceptions


See Exceptions Type E2.

