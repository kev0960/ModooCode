----------------------------
title : SUBPS (Intel x86/64 assembly instruction)
cat_title : SUBPS
ref_title : SUBPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SUBPS

**Subtract Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 5C /r`\newline{}`SUBPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE|Subtract packed single-precision floating-point values in xmm2/mem from xmm1 and store result in xmm1.|
|`VEX.NDS.128.0F.WIG 5C /r`\newline{}VSUBPS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract packed single-precision floating-point values in xmm3/mem from xmm2 and stores result in xmm1.|
|`VEX.NDS.256.0F.WIG 5C /r`\newline{}VSUBPS \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract packed single-precision floating-point values in ymm3/mem from ymm2 and stores result in ymm1.|
|`EVEX.NDS.128.0F.W0 5C /r`\newline{}VSUBPS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed single-precision floating-point values from xmm3/m128/m32bcst to xmm2 and stores result in xmm1 with writemask k1.|
|`EVEX.NDS.256.0F.W0 5C /r`\newline{}VSUBPS \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed single-precision floating-point values from ymm3/m256/m32bcst to ymm2 and stores result in ymm1 with writemask k1.|
|`EVEX.NDS.512.0F.W0 5C /r`\newline{}VSUBPS zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 zmm3/m512/m32bcst{er} |FV|V/V|AVX512F|Subtract packed single-precision floating-point values in zmm3/m512/m32bcst from zmm2 and stores result in zmm1 with writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD subtract of the packed single-precision floating-point values in the second Source operand from the First Source operand, and stores the packed single-precision floating-point results in the destination operand.

VEX.128 and EVEX.128 encoded versions: The second source operand is an XMM register or an 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (MAX\esc{_}VL-1:128) of the corre-sponding destination register are zeroed.

VEX.256 and EVEX.256 encoded versions: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. Bits (MAX\esc{_}VL-1:256) of the corre-sponding destination register are zeroed.

EVEX.512 encoded version: The second source operand is a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32-bit memory location. The first source operand and destination operands are ZMM registers. The destination operand is conditionally updated according to the writemask.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper Bits (MAX\esc{_}VL-1:128) of the corresponding register destination are unmodified.


### Operation
#### VSUBPS (EVEX encoded versions) when src2 operand is a vector register
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF (VL = 512) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC1[i+31:i] - SRC2[i+31:i]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[31:0] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VSUBPS (EVEX encoded versions) when src2 operand is a memory source
```info-verb
(KL, VL) = (4, 128), (8, 256),(16, 512)
FOR j <-  0 TO KL-1
    i <- j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1)
                      THEN  DEST[i+31:i] <-  SRC1[i+31:i] - SRC2[31:0];
                      ELSE  DEST[i+31:i] <-  SRC1[i+31:i] - SRC2[i+31:i];
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[31:0] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VSUBPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] - SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] - SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] - SRC2[127:96]
DEST[159:128] <-  SRC1[159:128] - SRC2[159:128]
DEST[191:160]<-  SRC1[191:160] - SRC2[191:160]
DEST[223:192] <-  SRC1[223:192] - SRC2[223:192]
DEST[255:224] <-  SRC1[255:224] - SRC2[255:224].
DEST[MAX_VL-1:256] <-  0
```
#### VSUBPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] - SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] - SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] - SRC2[127:96]
DEST[MAX_VL-1:128] <-  0
```
#### SUBPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] - SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] - SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] - SRC2[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSUBPS __m512 _mm512_sub_ps (__m512 a, __m512 b);
VSUBPS __m512 _mm512_mask_sub_ps (__m512 s, __mmask16 k, __m512 a, __m512 b);
VSUBPS __m512 _mm512_maskz_sub_ps (__mmask16 k, __m512 a, __m512 b);
VSUBPS __m512 _mm512_sub_round_ps (__m512 a, __m512 b, int);
VSUBPS __m512 _mm512_mask_sub_round_ps (__m512 s, __mmask16 k, __m512 a, __m512 b, int);
VSUBPS __m512 _mm512_maskz_sub_round_ps (__mmask16 k, __m512 a, __m512 b, int);
VSUBPS __m256 _mm256_sub_ps (__m256 a, __m256 b);
VSUBPS __m256 _mm256_mask_sub_ps (__m256 s, __mmask8 k, __m256 a, __m256 b);
VSUBPS __m256 _mm256_maskz_sub_ps (__mmask16 k, __m256 a, __m256 b);
SUBPS __m128 _mm_sub_ps (__m128 a, __m128 b);
VSUBPS __m128 _mm_mask_sub_ps (__m128 s, __mmask8 k, __m128 a, __m128 b);
VSUBPS __m128 _mm_maskz_sub_ps (__mmask16 k, __m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2.

EVEX-encoded instructions, see Exceptions Type E2.

