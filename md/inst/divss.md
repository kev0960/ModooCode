----------------------------
title : DIVSS (Intel x86/64 assembly instruction)
cat_title : DIVSS
ref_title : DIVSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/D
publish_date: 2020-09-01
----------------------------


#@ DIVSS

**Divide Scalar Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 5E /r`\newline{}`DIVSS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/V|SSE|Divide low single-precision floating-point value in xmm1 by low single-precision floating-point value in xmm2/m32.|
|`VEX.NDS.128.F3.0F.WIG 5E /r`\newline{}VDIVSS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RVM|V/V|AVX|Divide low single-precision floating-point value in xmm2 by low single-precision floating-point value in xmm3/m32.|
|`EVEX.NDS.LIG.F3.0F.W0 5E /r`\newline{}VDIVSS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m32{er} |T1S|V/V|AVX512F|Divide low single-precision floating-point value in xmm2 by low single-precision floating-point value in xmm3/m32.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Divides the low single-precision floating-point value in the first source operand by the low single-precision floating-point value in the second source operand, and stores the single-precision floating-point result in the destination operand. The second source operand can be an XMM register or a 32-bit memory location.

128-bit Legacy SSE version: The first source operand and the destination operand are the same. Bits (MAX\esc{_}VL-1:32) of the corresponding YMM destination register remain unchanged. 

VEX.128 encoded version: The first source operand is an xmm register encoded by VEX.vvvv. The three high-order doublewords of the destination operand are copied from the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX.128 encoded version: The first source operand is an xmm register encoded by EVEX.vvvv. The doubleword elements of the destination operand at bits 127:32 are copied from the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX version: The low doubleword element of the destination is updated according to the writemask.

Software should ensure VDIVSS is encoded with VEX.L=0. Encoding VDIVSS with VEX.L=1 may encounter unpre-dictable behavior across different processor generations.


### Operation
#### VDIVSS (EVEX encoded version)
```info-verb
IF (EVEX.b = 1) AND SRC2 *is a register*
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  SRC1[31:0] / SRC2[31:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### VDIVSS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0] / SRC2[31:0]
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### DIVSS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- DEST[31:0] / SRC[31:0]
DEST[MAX_VL-1:32] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VDIVSS __m128 _mm_mask_div_ss(__m128 s, __mmask8 k, __m128 a, __m128 b);
VDIVSS __m128 _mm_maskz_div_ss( __mmask8 k, __m128 a, __m128 b);
VDIVSS __m128 _mm_div_round_ss( __m128 a, __m128 b, int);
VDIVSS __m128 _mm_mask_div_round_ss(__m128 s, __mmask8 k, __m128 a, __m128 b, int);
VDIVSS __m128 _mm_maskz_div_round_ss( __mmask8 k, __m128 a, __m128 b, int);
DIVSS __m128 _mm_div_ss(__m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Divide-by-Zero, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.

