----------------------------
title : VFMADD132SD, VFMADD213SD, VFMADD231SDs (Intel x86/64 assembly instruction)
cat_title : VFMADD132SD, VFMADD213SD, VFMADD231SD
ref_title : VFMADD132SD, VFMADD213SD, VFMADD231SD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFMADD132SD, VFMADD213SD, VFMADD231SD

**Fused Multiply-Add of Scalar Double-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.DDS.LIG.66.0F38.W1 99 /r \newline{}VFMADD132SD xmm1, xmm2, xmm3/m64|RVM|V/V|FMA|Multiply scalar double-precision floating-point value from xmm1 and xmm3/m64, add to xmm2 and put result in xmm1.|
|VEX.DDS.LIG.66.0F38.W1 A9 /r \newline{}VFMADD213SD xmm1, xmm2, xmm3/m64|RVM|V/V|FMA|Multiply scalar double-precision floating-point value from xmm1 and xmm2, add to xmm3/m64 and put result in xmm1.|
|VEX.DDS.LIG.66.0F38.W1 B9 /r\newline{}VFMADD231SD xmm1, xmm2, xmm3/m64|RVM|V/V|FMA|Multiply scalar double-precision floating-point value from xmm2 and xmm3/m64, add to xmm1 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W1 99 /r \newline{}VFMADD132SD xmm1 {k1}{z}, xmm2, xmm3/m64{er}|T1S|V/V|AVX512F|Multiply scalar double-precision floating-point value from xmm1 and xmm3/m64, add to xmm2 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W1 A9 /r \newline{}VFMADD213SD xmm1 {k1}{z}, xmm2, xmm3/m64{er} |T1S|V/V|AVX512F|Multiply scalar double-precision floating-point value from xmm1 and xmm2, add to xmm3/m64 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W1 B9 /r \newline{}VFMADD231SD xmm1 {k1}{z}, xmm2, xmm3/m64{er}|T1S|V/V|AVX512F|Multiply scalar double-precision floating-point value from xmm2 and xmm3/m64, add to xmm1 and put result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (r, w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (r, w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD multiply-add computation on the low double-precision floating-point values using three source operands and writes the multiply-add result in the destination operand. The destination operand is also the first source operand. The first and second operand are XMM registers. The third source operand can be an XMM register or a 64-bit memory location. 

VFMADD132SD: Multiplies the low double-precision floating-point value from the first source operand to the low double-precision floating-point value in the third source operand, adds the infinite precision intermediate result to the low double-precision floating-point values in the second source operand, performs rounding and stores the resulting double-precision floating-point value to the destination operand (first source operand).

VFMADD213SD: Multiplies the low double-precision floating-point value from the second source operand to the low double-precision floating-point value in the first source operand, adds the infinite precision intermediate result to the low double-precision floating-point value in the third source operand, performs rounding and stores the resulting double-precision floating-point value to the destination operand (first source operand).

VFMADD231SD: Multiplies the low double-precision floating-point value from the second source to the low double-precision floating-point value in the third source operand, adds the infinite precision intermediate result to the low double-precision floating-point value in the first source operand, performs rounding and stores the resulting double-precision floating-point value to the destination operand (first source operand).

VEX.128 and EVEX encoded version: The destination operand (also first source operand) is encoded in reg\esc{_}field. The second source operand is encoded in VEX.vvvv/EVEX.vvvv. The third source operand is encoded in rm\esc{_}field. Bits 127:64 of the destination are unchanged. Bits MAXVL-1:128 of the destination register are zeroed.

EVEX encoded version: The low quadword element of the destination is updated according to the writemask.


### Operation
#### VFMADD132SD DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  RoundFPControl(DEST[63:0]*SRC3[63:0] + SRC2[63:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] <-  0
          FI;
FI;
DEST[127:64] <-  DEST[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VFMADD213SD DEST, SRC2, SRC3 (EVEX encoded version) 
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  RoundFPControl(SRC2[63:0]*DEST[63:0] + SRC3[63:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] <-  0
          FI;
FI;
DEST[127:64] <-  DEST[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VFMADD231SD DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  RoundFPControl(SRC2[63:0]*SRC3[63:0] + DEST[63:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] <-  0
          FI;
FI;
DEST[127:64] <-  DEST[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VFMADD132SD DEST, SRC2, SRC3 (VEX encoded version) 
```info-verb
DEST[63:0] <-  MAX_VL-1:128RoundFPControl_MXCSR(DEST[63:0]*SRC3[63:0] + SRC2[63:0])
DEST[127:63] <-  DEST[127:63]
DEST[MAX_VL-1:128] <-  0
```
#### VFMADD213SD DEST, SRC2, SRC3 (VEX encoded version) 
```info-verb
DEST[63:0] <-  RoundFPControl_MXCSR(SRC2[63:0]*DEST[63:0] + SRC3[63:0])
DEST[127:63] <-  DEST[127:63]
DEST[MAX_VL-1:128] <-  0
```
#### VFMADD231SD DEST, SRC2, SRC3 (VEX encoded version) 
```info-verb
DEST[63:0] <-  RoundFPControl_MXCSR(SRC2[63:0]*SRC3[63:0] + DEST[63:0])
DEST[127:63] <-  DEST[127:63]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFMADDxxxSD __m128d _mm_fmadd_round_sd(__m128d a, __m128d b, __m128d c, int r);
VFMADDxxxSD __m128d _mm_mask_fmadd_sd(__m128d a, __mmask8 k, __m128d b, __m128d c);
VFMADDxxxSD __m128d _mm_maskz_fmadd_sd(__mmask8 k, __m128d a, __m128d b, __m128d c);
VFMADDxxxSD __m128d _mm_mask3_fmadd_sd(__m128d a, __m128d b, __m128d c, __mmask8 k);
VFMADDxxxSD __m128d _mm_mask_fmadd_round_sd(__m128d a, __mmask8 k, __m128d b, __m128d c, int r);
VFMADDxxxSD __m128d _mm_maskz_fmadd_round_sd(__mmask8 k, __m128d a, __m128d b, __m128d c, int r);
VFMADDxxxSD __m128d _mm_mask3_fmadd_round_sd(__m128d a, __m128d b, __m128d c, __mmask8 k, int r);
VFMADDxxxSD __m128d _mm_fmadd_sd (__m128d a, __m128d b, __m128d c);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.
