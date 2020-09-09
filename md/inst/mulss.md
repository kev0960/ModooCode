----------------------------
title : MULSS (Intel x86/64 assembly instruction)
cat_title : MULSS
ref_title : MULSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MULSS

**Multiply Scalar Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 59 /r\newline{}MULSS xmm1,xmm2/m32|RM|V/V|SSE|Multiply the low single-precision floating-point value in xmm2/m32 by the low single-precision floating-point value in xmm1.|
|VEX.NDS.128.F3.0F.WIG 59 /r\newline{}VMULSS xmm1,xmm2, xmm3/m32|RVM|V/V|AVX|Multiply the low single-precision floating-point value in xmm3/m32 by the low single-precision floating-point value in xmm2.|
|EVEX.NDS.LIG.F3.0F.W0 59 /r\newline{}VMULSS xmm1 {k1}{z}, xmm2, xmm3/m32 {er}|T1S|V/V|AVX512F|Multiply the low single-precision floating-point value in xmm3/m32 by the low single-precision floating-point value in xmm2.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Multiplies the low single-precision floating-point value from the second source operand by the low single-precision floating-point value in the first source operand, and stores the single-precision floating-point result in the destina-tion operand. The second source operand can be an XMM register or a 32-bit memory location. The first source operand and the destination operands are XMM registers. 

128-bit Legacy SSE version: The first source operand and the destination operand are the same. Bits (MAX\esc{_}VL-1:32) of the corresponding YMM destination register remain unchanged.

VEX.128 and EVEX encoded version: The first source operand is an xmm register encoded by VEX.vvvv. The three high-order doublewords of the destination operand are copied from the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX encoded version: The low doubleword element of the destination operand is updated according to the writemask.

Software should ensure VMULSS is encoded with VEX.L=0. Encoding VMULSS with VEX.L=1 may encounter unpre-dictable behavior across different processor generations.


### Operation
#### VMULSS (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) AND SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  SRC1[31:0] * SRC2[31:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
                FI
    FI;
ENDFOR
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### VMULSS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0] * SRC2[31:0]
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### MULSS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- DEST[31:0] * SRC[31:0]
DEST[MAX_VL-1:32] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMULSS __m128 _mm_mask_mul_ss(__m128 s, __mmask8 k, __m128 a, __m128 b);
VMULSS __m128 _mm_maskz_mul_ss( __mmask8 k, __m128 a, __m128 b);
VMULSS __m128 _mm_mul_round_ss( __m128 a, __m128 b, int);
VMULSS __m128 _mm_mask_mul_round_ss(__m128 s, __mmask8 k, __m128 a, __m128 b, int);
VMULSS __m128 _mm_maskz_mul_round_ss( __mmask8 k, __m128 a, __m128 b, int);
MULSS __m128 _mm_mul_ss(__m128 a, __m128 b)
```
### SIMD Floating-Point Exceptions


Underflow, Overflow, Invalid, Precision, Denormal

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 3.

EVEX-encoded instruction, see Exceptions Type E3.

