----------------------------
title : VFNMADD132SS, VFNMADD213SS, VFNMADD231SSs (Intel x86/64 assembly instruction)
cat_title : VFNMADD132SS, VFNMADD213SS, VFNMADD231SS
ref_title : VFNMADD132SS, VFNMADD213SS, VFNMADD231SS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFNMADD132SS, VFNMADD213SS, VFNMADD231SS

**Fused Negative Multiply-Add of Scalar Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.DDS.LIG.66.0F38.W0 9D /r \newline{}VFNMADD132SS xmm1, xmm2, xmm3/m32|RVM|V/V|FMA|Multiply scalar single-precision floating-point value from xmm1 and xmm3/m32, negate the multiplication result andadd to xmm2 and put result in xmm1.|
|VEX.DDS.LIG.66.0F38.W0 AD /r \newline{}VFNMADD213SS xmm1, xmm2, xmm3/m32|RVM|V/V|FMA|Multiply scalar single-precision floating-point value from xmm1 and xmm2, negate the multiplication result and add to xmm3/m32 and put result in xmm1.|
|VEX.DDS.LIG.66.0F38.W0 BD /r \newline{}VFNMADD231SS xmm1, xmm2, xmm3/m32|RVM|V/V|FMA|Multiply scalar single-precision floating-point value from xmm2 and xmm3/m32, negate the multiplication result and add to xmm1 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W0 9D /r \newline{}VFNMADD132SS xmm1 {k1}{z}, xmm2, xmm3/m32{er}|T1S|V/V|AVX512F|Multiply scalar single-precision floating-point value from xmm1 and xmm3/m32, negate the multiplication result andadd to xmm2 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W0 AD /r \newline{}VFNMADD213SS xmm1 {k1}{z}, xmm2, xmm3/m32{er}|T1S|V/V|AVX512F|Multiply scalar single-precision floating-point value from xmm1 and xmm2, negate the multiplication result and add to xmm3/m32 and put result in xmm1.|
|EVEX.DDS.LIG.66.0F38.W0 BD /r \newline{}VFNMADD231SS xmm1 {k1}{z}, xmm2, xmm3/m32{er}|T1S|V/V|AVX512F|Multiply scalar single-precision floating-point value from xmm2 and xmm3/m32, negate the multiplication result and add to xmm1 and put result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (r, w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (r, w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


VFNMADD132SS: Multiplies the low packed single-precision floating-point value from the first source operand to the low packed single-precision floating-point value in the third source operand, adds the negated infinite precision intermediate result to the low packed single-precision floating-point value in the second source operand, performs rounding and stores the resulting packed single-precision floating-point value to the destination operand (first source operand).

VFNMADD213SS: Multiplies the low packed single-precision floating-point value from the second source operand to the low packed single-precision floating-point value in the first source operand, adds the negated infinite preci-sion intermediate result to the low packed single-precision floating-point value in the third source operand, performs rounding and stores the resulting packed single-precision floating-point value to the destination operand (first source operand).

VFNMADD231SS: Multiplies the low packed single-precision floating-point value from the second source operand to the low packed single-precision floating-point value in the third source operand, adds the negated infinite preci-sion intermediate result to the low packed single-precision floating-point value in the first source operand, performs rounding and stores the resulting packed single-precision floating-point value to the destination operand (first source operand).

VEX.128 and EVEX encoded version: The destination operand (also first source operand) is encoded in reg\esc{_}field. The second source operand is encoded in VEX.vvvv/EVEX.vvvv. The third source operand is encoded in rm\esc{_}field. Bits 127:32 of the destination are unchanged. Bits MAXVL-1:128 of the destination register are zeroed.



EVEX encoded version: The low doubleword element of the destination is updated according to the writemask.

Compiler tools may optionally support a complementary mnemonic for each instruction mnemonic listed in the opcode/instruction column of the summary table. The behavior of the complementary mnemonic in situations involving NANs are governed by the definition of the instruction mnemonic defined in the opcode/instruction column.


### Operation
#### VFNMADD132SS DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  RoundFPControl(-(DEST[31:0]*SRC3[31:0]) + SRC2[31:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  DEST[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### VFNMADD213SS DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  RoundFPControl(-(SRC2[31:0]*DEST[31:0]) + SRC3[31:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  DEST[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### VFNMADD231SS DEST, SRC2, SRC3 (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) and SRC3 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  RoundFPControl(-(SRC2[31:0]*SRC3[63:0]) + DEST[31:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  DEST[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### VFNMADD132SS DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
DEST[31:0] <- RoundFPControl_MXCSR(- (DEST[31:0]*SRC3[31:0]) + SRC2[31:0])
DEST[127:32] <- DEST[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### VFNMADD213SS DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
DEST[31:0] <- RoundFPControl_MXCSR(- (SRC2[31:0]*DEST[31:0]) + SRC3[31:0])
DEST[127:32] <- DEST[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### VFNMADD231SS DEST, SRC2, SRC3 (VEX encoded version)
```info-verb
DEST[31:0] <- RoundFPControl_MXCSR(- (SRC2[31:0]*SRC3[31:0]) + DEST[31:0])
DEST[127:32] <- DEST[127:32]
DEST[MAX_VL-1:128] <- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFNMADDxxxSS __m128 _mm_fnmadd_round_ss(__m128 a, __m128 b, __m128 c, int r);
VFNMADDxxxSS __m128 _mm_mask_fnmadd_ss(__m128 a, __mmask8 k, __m128 b, __m128 c);
VFNMADDxxxSS __m128 _mm_maskz_fnmadd_ss(__mmask8 k, __m128 a, __m128 b, __m128 c);
VFNMADDxxxSS __m128 _mm_mask3_fnmadd_ss(__m128 a, __m128 b, __m128 c, __mmask8 k);
VFNMADDxxxSS __m128 _mm_mask_fnmadd_round_ss(__m128 a, __mmask8 k, __m128 b, __m128 c, int r);
VFNMADDxxxSS __m128 _mm_maskz_fnmadd_round_ss(__mmask8 k, __m128 a, __m128 b, __m128 c, int r);
VFNMADDxxxSS __m128 _mm_mask3_fnmadd_round_ss(__m128 a, __m128 b, __m128 c, __mmask8 k, int r);
VFNMADDxxxSS __m128 _mm_fnmadd_ss (__m128 a, __m128 b, __m128 c);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.

