----------------------------
title : VSCALEFSD (Intel x86/64 assembly instruction)
cat_title : VSCALEFSD
ref_title : VSCALEFSD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VSCALEFSD

**Scale Scalar Float64 Values With Float64 Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.NDS.LIG.66.0F38.W1 2D /r `\newline{}`VSCALEFSD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m64{er} |T1S|V/V|AVX512F|Scale the scalar double-precision floating-point values in xmm2 using the value from xmm3/m64. Under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a floating-point scale of the packed double-precision floating-point value in the first source operand by multiplying it by 2 power of the double-precision floating-point value in second source operand.

The equation of this operation is given by:

xmm1 := xmm2\htmlonly{\esc{*}}2\footnote{floor(xmm3)} .

Floor(xmm3) means maximum integer value "  xmm3.

If the result cannot be represented in double precision, then the proper overflow response (for positive scaling operand), or the proper underflow response (for negative scaling operand) is issued. The overflow and underflow responses are dependent on the rounding mode (for IEEE-compliant rounding), as well as on other settings in MXCSR (exception mask bits, FTZ bit), and on the SAE bit.

EVEX encoded version: The first source operand is an XMM register. The second source operand is an XMM register or a memory location. The destination operand is an XMM register conditionally updated with writemask k1.

Handling of special-case input values are listed in Table 5-31 and Table 5-32.


### Operation
#### VSCALEFSD (EVEX encoded version)
```info-verb
IF (EVEX.b= 1) and SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] OR *no writemask*
    THEN DEST[63:0] <-  SCALE(SRC1[63:0], SRC2[63:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[63:0] <-  0
          FI
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSCALEFSD __m128d _mm_scalef_round_sd(__m128d a, __m128d b, int);
VSCALEFSD __m128d _mm_mask_scalef_round_sd(__m128d s, __mmask8 k, __m128d a, __m128d b, int);
VSCALEFSD __m128d _mm_maskz_scalef_round_sd(__mmask8 k, __m128d a, __m128d b, int);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal (for Src1).

Denormal is not reported for Src2.

### Other Exceptions


See Exceptions Type E3.

