----------------------------
title : PCMPGTQ (Intel x86/64 assembly instruction)
cat_title : PCMPGTQ
ref_title : PCMPGTQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PCMPGTQ

** Compare Packed Data for Greater Than**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`66 0F 38 37 /r`\newline{}`PCMPGTQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE4_2|Compare packed signed qwords in  xmm2/m128 and xmm1 for greater than.|
|`VEX.NDS.128.66.0F38.WIG 37 /r`\newline{}VPCMPGTQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Compare packed signed qwords in xmm2 and xmm3/m128 for greater than.|
|`VEX.NDS.256.66.0F38.WIG 37 /r`\newline{}VPCMPGTQ \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Compare packed signed qwords in ymm2 and ymm3/m256 for greater than.|
|`EVEX.NDS.128.66.0F38.W1 37 /r`\newline{}VPCMPGTQ \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Compare Greater between int64 vector xmm2 and int64 vector xmm3/m128/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|`EVEX.NDS.256.66.0F38.W1 37 /r`\newline{}VPCMPGTQ \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Compare Greater between int64 vector ymm2 and int64 vector ymm3/m256/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|`EVEX.NDS.512.66.0F38.W1 37 /r`\newline{}VPCMPGTQ \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} zmm2 \tooltip{zmm3/m512/m64bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 64 비트 메모리 주소값에 불러온 벡터 데이터.} |FV|V/V|AVX512F|Compare Greater between int64 vector zmm2 and int64 vector zmm3/m512/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs an SIMD signed compare for the packed quadwords in the destination operand (first operand) and the source operand (second operand). If the data element in the first (destination) operand is greater than the corresponding element in the second (source) operand, the corresponding data element in the destination is set to all 1s; otherwise, it is set to 0s.

128-bit Legacy SSE version: The second source operand can be an XMM register or a 128-bit memory location. The first source operand and destination operand are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source operand and destination operand are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register.

EVEX encoded VPCMPGTD/Q: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand (first operand) is a mask register updated according to the writemask k2.


### Operation
#### COMPARE_QWORDS_GREATER (SRC1, SRC2)
```info-verb
    IF SRC1[63:0] > SRC2[63:0]
    THEN DEST[63:0] <- FFFFFFFFFFFFFFFFH;
    ELSE DEST[63:0] <- 0; FI;
    IF SRC1[127:64] > SRC2[127:64]
    THEN DEST[127:64] <- FFFFFFFFFFFFFFFFH;
    ELSE DEST[127:64] <- 0; FI;
```
#### VPCMPGTQ (VEX.128 encoded version)
```info-verb
DEST[127:0] <- COMPARE_QWORDS_GREATER(SRC1,SRC2)
DEST[VLMAX-1:128] <-  0
```
#### VPCMPGTQ (VEX.256 encoded version)
```info-verb
DEST[127:0] <- COMPARE_QWORDS_GREATER(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_QWORDS_GREATER(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256] <-  0
```
#### VPCMPGTQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k2[j] OR *no writemask*
          THEN 
                /* signed comparison */
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN CMP <-  SRC1[i+63:i] > SRC2[63:0];
                      ELSE CMP <-  SRC1[i+63:i] > SRC2[i+63:i];
                FI;
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] <-  0 ; zeroing-masking only
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPCMPGTQ __mmask8 _mm512_cmpgt_epi64_mask( __m512i a, __m512i b);
VPCMPGTQ __mmask8 _mm512_mask_cmpgt_epi64_mask(__mmask8 k, __m512i a, __m512i b);
VPCMPGTQ __mmask8 _mm256_cmpgt_epi64_mask( __m256i a, __m256i b);
VPCMPGTQ __mmask8 _mm256_mask_cmpgt_epi64_mask(__mmask8 k, __m256i a, __m256i b);
VPCMPGTQ __mmask8 _mm_cmpgt_epi64_mask( __m128i a, __m128i b);
VPCMPGTQ __mmask8 _mm_mask_cmpgt_epi64_mask(__mmask8 k, __m128i a, __m128i b);
(V)PCMPGTQ:  __m128i _mm_cmpgt_epi64(__m128i a, __m128i b)
VPCMPGTQ: __m256i _mm256_cmpgt_epi64( __m256i a, __m256i b);
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPCMPGTQ, see Exceptions Type E4.

