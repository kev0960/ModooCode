----------------------------
title : DIVSD (Intel x86/64 assembly instruction)
cat_title : DIVSD
ref_title : DIVSD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/D
publish_date: 2020-09-01
----------------------------


#@ DIVSD

**Divide Scalar Double-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F 5E /r\newline{}DIVSD xmm1, xmm2/m64|RM|V/V|SSE2|Divide low double-precision floating-point value in xmm1 by low double-precision floating-point value in xmm2/m64.|
|VEX.NDS.128.F2.0F.WIG 5E /r\newline{}VDIVSD xmm1, xmm2, xmm3/m64|RVM|V/V|AVX|Divide low double-precision floating-point value in xmm2 by low double-precision floating-point value in xmm3/m64.|
|EVEX.NDS.LIG.F2.0F.W1 5E /r\newline{}VDIVSD xmm1 {k1}{z}, xmm2, xmm3/m64{er}|T1S|V/V|AVX512F|Divide low double-precision floating-point value in xmm2 by low double-precision floating-point value in xmm3/m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Divides the low double-precision floating-point value in the first source operand by the low double-precision floating-point value in the second source operand, and stores the double-precision floating-point result in the desti-nation operand. The second source operand can be an XMM register or a 64-bit memory location. The first source and destination are XMM registers. 

128-bit Legacy SSE version: The first source operand and the destination operand are the same. Bits (MAX\esc{_}VL-1:64) of the corresponding ZMM destination register remain unchanged.

VEX.128 encoded version: The first source operand is an xmm register encoded by VEX.vvvv. The quadword at bits 127:64 of the destination operand is copied from the corresponding quadword of the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX.128 encoded version: The first source operand is an xmm register encoded by EVEX.vvvv. The quadword element of the destination operand at bits 127:64 are copied from the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX version: The low quadword element of the destination is updated according to the writemask.

Software should ensure VDIVSD is encoded with VEX.L=0. Encoding VDIVSD with VEX.L=1 may encounter unpre-dictable behavior across different processor generations.


### Operation
#### VDIVSD (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) AND SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  SRC1[63:0] / SRC2[63:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] <-  0
          FI;
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VDIVSD (VEX.128 encoded version)
```info-verb
DEST[63:0] <- SRC1[63:0] / SRC2[63:0]
DEST[127:64] <- SRC1[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### DIVSD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <- DEST[63:0] / SRC[63:0]
DEST[MAX_VL-1:64] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VDIVSD __m128d _mm_mask_div_sd(__m128d s, __mmask8 k, __m128d a, __m128d b);
VDIVSD __m128d _mm_maskz_div_sd( __mmask8 k, __m128d a, __m128d b);
VDIVSD __m128d _mm_div_round_sd( __m128d a, __m128d b, int);
VDIVSD __m128d _mm_mask_div_round_sd(__m128d s, __mmask8 k, __m128d a, __m128d b, int);
VDIVSD __m128d _mm_maskz_div_round_sd( __mmask8 k, __m128d a, __m128d b, int);
DIVSD __m128d _mm_div_sd (__m128d a, __m128d b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Divide-by-Zero, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.
