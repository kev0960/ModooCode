----------------------------
title : MINSS (Intel x86/64 assembly instruction)
cat_title : MINSS
ref_title : MINSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MINSS

**Return Minimum Scalar Single-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 5D /r`\newline{}`MINSS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/V|SSE|Return the minimum scalar single-precision floating-point value between xmm2/m32 and xmm1.|
|`VEX.NDS.128.F3.0F.WIG 5D /r`\newline{}VMINSS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RVM|V/V|AVX|Return the minimum scalar single-precision floating-point value between xmm3/m32 and xmm2.|
|`EVEX.NDS.LIG.F3.0F.W0 5D /r`\newline{}VMINSS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m32{sae} |T1S|V/V|AVX512F|Return the minimum scalar single-precision floating-point value between xmm3/m32 and xmm2.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Compares the low single-precision floating-point values in the first source operand and the second source operand and returns the minimum value to the low doubleword of the destination operand.

If the values being compared are both 0.0s (of either sign), the value in the second source operand is returned. If a value in the second operand is an SNaN, that SNaN is returned unchanged to the destination (that is, a QNaN version of the SNaN is not returned).

If only one value is a NaN (SNaN or QNaN) for this instruction, the second source operand, either a NaN or a valid floating-point value, is written to the result. If instead of this behavior, it is required that the NaN in either source operand be returned, the action of `MINSD` can be emulated using a sequence of instructions, such as, a comparison followed by `AND`, `ANDN` and `OR`. 

The second source operand can be an XMM register or a 32-bit memory location. The first source and destination operands are XMM registers. 

128-bit Legacy SSE version: The destination and first source operand are the same. Bits (MAX\esc{_}VL:32) of the corre-sponding destination register remain unchanged.

VEX.128 and EVEX encoded version: The first source operand is an xmm register encoded by (E)VEX.vvvv. Bits (127:32) of the XMM register destination are copied from corresponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

EVEX encoded version: The low doubleword element of the destination operand is updated according to the writemask.

Software should ensure VMINSS is encoded with VEX.L=0. Encoding VMINSS with VEX.L=1 may encounter unpre-dictable behavior across different processor generations.


### Operation
#### MINSS (EVEX encoded version)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  MIN(SRC1[31:0], SRC2[31:0])
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
#### VMINSS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- MIN(SRC1[31:0], SRC2[31:0])
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### MINSS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- MIN(SRC1[31:0], SRC2[31:0])
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMINSS __m128 _mm_min_round_ss( __m128 a, __m128 b, int);
VMINSS __m128 _mm_mask_min_round_ss(__m128 s, __mmask8 k, __m128 a, __m128 b, int);
VMINSS __m128 _mm_maskz_min_round_ss( __mmask8 k, __m128 a, __m128 b, int);
MINSS __m128 _mm_min_ss(__m128 a, __m128 b)
```
### SIMD Floating-Point Exceptions


Invalid (Including QNaN Source Operand), Denormal

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 2.

EVEX-encoded instruction, see Exceptions Type E2.

