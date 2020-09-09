----------------------------
title : VFNMSUB132SD, VFNMSUB213SD, VFNMSUB231SDs (Intel x86/64 assembly instruction)
cat_title : VFNMSUB132SD, VFNMSUB213SD, VFNMSUB231SD
ref_title : VFNMSUB132SD, VFNMSUB213SD, VFNMSUB231SD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFNMSUB132SD, VFNMSUB213SD, VFNMSUB231SD

**Fused Negative Multiply-Subtract of Scalar Double-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.DDS.LIG.66.0F38.W1 9F /r \newline{}VFNMSUB132SD xmm1, xmm2, xmm3/m64|RVM|V/V|FMA|Multiply scalar double-precision floating-point value from xmm1 and xmm3/mem, negate the multiplication result and subtract xmm2 and put result in xmm1.|
|VEX.DDS.LIG.66.0F38.W1 AF /r \newline{}VFNMSUB213SD xmm1, xmm2, xmm3/m64|RVM|V/V|FMA|Multiply scalar double-precision floating-point value from xmm1 and xmm2, negate the multiplication result and subtract xmm3/mem and put result in xmm1.|
|VEX.DDS.LIG.66.0F38.W1 BF /r \newline{}VFNMSUB231SD xmm1, xmm2, xmm3/m64|RVM|V/V|FMA|Multiply scalar double-precision floating-point value from xmm2 and xmm3/mem, negate the multiplication result and subtract xmm1 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W1 9F /r \newline{}VFNMSUB132SD xmm1 {k1}{z}, xmm2, xmm3/m64{er}|T1S|V/V|AVX512F|Multiply scalar double-precision floating-point value from xmm1 and xmm3/m64, negate the multiplication result and subtract xmm2 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W1 AF /r \newline{}VFNMSUB213SD xmm1 {k1}{z}, xmm2, xmm3/m64{er} |T1S|V/V|AVX512F|Multiply scalar double-precision floating-point value from xmm1 and xmm2, negate the multiplication result and subtract xmm3/m64 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W1 BF /r \newline{}VFNMSUB231SD xmm1 {k1}{z}, xmm2, xmm3/m64{er}|T1S|V/V|AVX512F|Multiply scalar double-precision floating-point value from xmm2 and xmm3/m64, negate the multiplication result and subtract xmm1 and put result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (r, w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (r, w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


VFNMSUB132SD: Multiplies the low packed double-precision floating-point value from the first source operand to the low packed double-precision floating-point value in the third source operand. From negated infinite precision intermediate result, subtracts the low double-precision floating-point value in the second source operand, performs rounding and stores the resulting packed double-precision floating-point value to the destination operand (first source operand).

VFNMSUB213SD: Multiplies the low packed double-precision floating-point value from the second source operand to the low packed double-precision floating-point value in the first source operand. From negated infinite precision intermediate result, subtracts the low double-precision floating-point value in the third source operand, performs rounding and stores the resulting packed double-precision floating-point value to the destination operand (first source operand).

VFNMSUB231SD: Multiplies the low packed double-precision floating-point value from the second source to the low packed double-precision floating-point value in the third source operand. From negated infinite precision interme-diate result, subtracts the low double-precision floating-point value in the first source operand, performs rounding and stores the resulting packed double-precision floating-point value to the destination operand (first source operand).

VEX.128 and EVEX encoded version: The destination operand (also first source operand) is encoded in reg\esc{_}field. The second source operand is encoded in VEX.vvvv/EVEX.vvvv. The third source operand is encoded in rm\esc{_}field. Bits 127:64 of the destination are unchanged. Bits MAXVL-1:128 of the destination register are zeroed.



EVEX encoded version: The low quadword element of the destination is updated according to the writemask.

Compiler tools may optionally support a complementary mnemonic for each instruction mnemonic listed in the opcode/instruction column of the summary table. The behavior of the complementary mnemonic in situations involving NANs are governed by the definition of the instruction mnemonic defined in the opcode/instruction column.


### Operation
#### VFNMSUB132SD DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  RoundFPControl(-(DEST[63:0]*SRC3[63:0]) - SRC2[63:0])
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
#### VFNMSUB213SD DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  RoundFPControl(-(SRC2[63:0]*DEST[63:0]) - SRC3[63:0])
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
#### VFNMSUB231SD DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  RoundFPControl(-(SRC2[63:0]*SRC3[63:0]) - DEST[63:0])
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
#### VFNMSUB132SD DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
DEST[63:0] <- RoundFPControl_MXCSR(- (DEST[63:0]*SRC3[63:0]) - SRC2[63:0])
DEST[127:64] <- DEST[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### VFNMSUB213SD DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
DEST[63:0] <- RoundFPControl_MXCSR(- (SRC2[63:0]*DEST[63:0]) - SRC3[63:0])
DEST[127:64] <- DEST[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### VFNMSUB231SD DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
DEST[63:0] <- RoundFPControl_MXCSR(- (SRC2[63:0]*SRC3[63:0]) - DEST[63:0])
DEST[127:64] <- DEST[127:64]
DEST[MAX_VL-1:128] <- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFNMSUBxxxSD __m128d _mm_fnmsub_round_sd(__m128d a, __m128d b, __m128d c, int r);
VFNMSUBxxxSD __m128d _mm_mask_fnmsub_sd(__m128d a, __mmask8 k, __m128d b, __m128d c);
VFNMSUBxxxSD __m128d _mm_maskz_fnmsub_sd(__mmask8 k, __m128d a, __m128d b, __m128d c);
VFNMSUBxxxSD __m128d _mm_mask3_fnmsub_sd(__m128d a, __m128d b, __m128d c, __mmask8 k);
VFNMSUBxxxSD __m128d _mm_mask_fnmsub_round_sd(__m128d a, __mmask8 k, __m128d b, __m128d c, int r);
VFNMSUBxxxSD __m128d _mm_maskz_fnmsub_round_sd(__mmask8 k, __m128d a, __m128d b, __m128d c, int r);
VFNMSUBxxxSD __m128d _mm_mask3_fnmsub_round_sd(__m128d a, __m128d b, __m128d c, __mmask8 k, int r);
VFNMSUBxxxSD __m128d _mm_fnmsub_sd (__m128d a, __m128d b, __m128d c);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.

