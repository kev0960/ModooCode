----------------------------
title : PCMPEQQ (Intel x86/64 assembly instruction)
cat_title : PCMPEQQ
ref_title : PCMPEQQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PCMPEQQ

** Compare Packed Qword Data for Equal**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 38 29 /r\newline{}PCMPEQQ xmm1, xmm2/m128|RM|V/V|SSE4_1|Compare packed qwords in xmm2/m128 and xmm1 for equality.|
|VEX.NDS.128.66.0F38.WIG 29 /r\newline{}VPCMPEQQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed quadwords in xmm3/m128 and xmm2 for equality.|
|VEX.NDS.256.66.0F38.WIG 29 /r\newline{}VPCMPEQQ ymm1, ymm2, ymm3 /m256|RVM|V/V|AVX2|Compare packed quadwords in ymm3/m256 and ymm2 for equality.|
|EVEX.NDS.128.66.0F38.W1 29 /r\newline{}VPCMPEQQ k1 {k2}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare Equal between int64 vector xmm2 and int64 vector xmm3/m128/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.256.66.0F38.W1 29 /r\newline{}VPCMPEQQ k1 {k2}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Compare Equal between int64 vector ymm2 and int64 vector ymm3/m256/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.512.66.0F38.W1 29 /r\newline{}VPCMPEQQ k1 {k2}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Compare Equal between int64 vector zmm2 and int64 vector zmm3/m512/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs an SIMD compare for equality of the packed quadwords in the destination operand (first operand) and the source operand (second operand).  If a pair of data elements is equal, the corresponding data element in the desti-nation is set to all 1s; otherwise, it is set to 0s.

128-bit Legacy SSE version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register.

EVEX encoded VPCMPEQQ: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand (first operand) is a mask register updated according to the writemask k2.


### Operation
#### PCMPEQQ (with 128-bit operands)
```info-verb
IF (DEST[63:0] = SRC[63:0]) 
    THEN DEST[63:0] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[63:0] <-  0; FI;
IF (DEST[127:64] = SRC[127:64]) 
    THEN DEST[127:64] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[127:64] <-  0; FI;
DEST[MAX_VL-1:128] (Unmodified)
```
#### COMPARE_QWORDS_EQUAL (SRC1, SRC2)
```info-verb
    IF SRC1[63:0] = SRC2[63:0]
    THEN DEST[63:0] <- FFFFFFFFFFFFFFFFH;
    ELSE DEST[63:0] <- 0; FI;
    IF SRC1[127:64] = SRC2[127:64]
    THEN DEST[127:64] <- FFFFFFFFFFFFFFFFH;
    ELSE DEST[127:64] <- 0; FI;
```
#### VPCMPEQQ (VEX.128 encoded version)
```info-verb
DEST[127:0] <- COMPARE_QWORDS_EQUAL(SRC1,SRC2)
DEST[VLMAX-1:128] <-  0
```
#### VPCMPEQQ (VEX.256 encoded version)
```info-verb
DEST[127:0] <- COMPARE_QWORDS_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_QWORDS_EQUAL(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256] <-  0
```
#### VPCMPEQQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k2[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN CMP <-  SRC1[i+63:i] = SRC2[63:0];
                      ELSE CMP <-  SRC1[i+63:i] = SRC2[i+63:i];
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
VPCMPEQQ __mmask8 _mm512_cmpeq_epi64_mask( __m512i a, __m512i b);
VPCMPEQQ __mmask8 _mm512_mask_cmpeq_epi64_mask(__mmask8 k, __m512i a, __m512i b);
VPCMPEQQ __mmask8 _mm256_cmpeq_epi64_mask( __m256i a, __m256i b);
VPCMPEQQ __mmask8 _mm256_mask_cmpeq_epi64_mask(__mmask8 k, __m256i a, __m256i b);
VPCMPEQQ __mmask8 _mm_cmpeq_epi64_mask( __m128i a, __m128i b);
VPCMPEQQ __mmask8 _mm_mask_cmpeq_epi64_mask(__mmask8 k, __m128i a, __m128i b);
(V)PCMPEQQ: __m128i _mm_cmpeq_epi64(__m128i a, __m128i b);
VPCMPEQQ: __m256i _mm256_cmpeq_epi64( __m256i a, __m256i b);
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPCMPEQQ, see Exceptions Type E4.

