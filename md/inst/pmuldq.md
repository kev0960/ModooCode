----------------------------
title : PMULDQ (Intel x86/64 assembly instruction)
cat_title : PMULDQ
ref_title : PMULDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PMULDQ

**Multiply Packed Doubleword Integers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 38 28 /r\newline{}PMULDQ xmm1, xmm2/m128|RM|V/V|SSE4_1|Multiply packed signed doubleword integers in xmm1 by packed signed doubleword integers in xmm2/m128, and store the quadword results in xmm1.|
|VEX.NDS.128.66.0F38.WIG 28 /r\newline{}VPMULDQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Multiply packed signed doubleword integers in xmm2 by packed signed doubleword integers in xmm3/m128, and store the quadword results in xmm1.|
|VEX.NDS.256.66.0F38.WIG 28 /r\newline{}VPMULDQ ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Multiply packed signed doubleword integers in ymm2 by packed signed doubleword integers in ymm3/m256, and store the quadword results in ymm1.|
|EVEX.NDS.128.66.0F38.W1 28 /r\newline{}VPMULDQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed signed doubleword integers in xmm2 by packed signed doubleword integers in xmm3/m128/m64bcst, and store the quadword results in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F38.W1 28 /r\newline{}VPMULDQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Multiply packed signed doubleword integers in ymm2 by packed signed doubleword integers in ymm3/m256/m64bcst, and store the quadword results in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W1 28 /r\newline{}VPMULDQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Multiply packed signed doubleword integers in zmm2 by packed signed doubleword integers in zmm3/m512/m64bcst, and store the quadword results in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Multiplies packed signed doubleword integers in the even-numbered (zero-based reference) elements of the first source operand with the packed signed doubleword integers in the corresponding elements of the second source operand and stores packed signed quadword results in the destination operand. 

128-bit Legacy SSE version: The input signed doubleword integers are taken from the even-numbered elements of the source operands, i.e. the first (low) and third doubleword element. For 128-bit memory operands, 128 bits are fetched from memory, but only the first and third doublewords are used in the computation. The first source operand and the destination XMM operand is the same. The second source operand can be an XMM register or 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 encoded version: The input signed doubleword integers are taken from the even-numbered elements of the source operands, i.e., the first (low) and third doubleword element. For 128-bit memory operands, 128 bits are fetched from memory, but only the first and third doublewords are used in the computation.The first source operand and the destination operand are XMM registers. The second source operand can be an XMM register or 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

VEX.256 encoded version: The input signed doubleword integers are taken from the even-numbered elements of the source operands, i.e. the first, 3rd, 5th, 7th doubleword element. For 256-bit memory operands, 256 bits are fetched from memory, but only the four even-numbered doublewords are used in the computation. The first source operand and the destination operand are YMM registers. The second source operand can be a YMM register or 256-bit memory location. Bits (MAX\esc{_}VL-1:256) of the corresponding destination ZMM register are zeroed.



EVEX encoded version: The input signed doubleword integers are taken from the even-numbered elements of the source operands. The first source operand is a ZMM/YMM/XMM registers. The second source operand can be an ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination is a ZMM/YMM/XMM register, and updated according to the writemask at 64-bit granularity. 


### Operation
#### VPMULDQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  SignExtend64( SRC1[i+31:i]) * SignExtend64( SRC2[31:0])
                      ELSE DEST[i+63:i] <-  SignExtend64( SRC1[i+31:i]) * SignExtend64( SRC2[i+31:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPMULDQ (VEX.256 encoded version)
```info-verb
DEST[63:0] <- SignExtend64( SRC1[31:0]) * SignExtend64( SRC2[31:0])
DEST[127:64] <- SignExtend64( SRC1[95:64]) * SignExtend64( SRC2[95:64])
DEST[191:128] <- SignExtend64( SRC1[159:128]) * SignExtend64( SRC2[159:128])
DEST[255:192] <- SignExtend64( SRC1[223:192]) * SignExtend64( SRC2[223:192])
DEST[MAX_VL-1:256] <- 0
```
#### VPMULDQ (VEX.128 encoded version)
```info-verb
DEST[63:0] <- SignExtend64( SRC1[31:0]) * SignExtend64( SRC2[31:0])
DEST[127:64] <- SignExtend64( SRC1[95:64]) * SignExtend64( SRC2[95:64])
DEST[MAX_VL-1:128] <- 0
```
#### PMULDQ (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <- SignExtend64( DEST[31:0]) * SignExtend64( SRC[31:0])
DEST[127:64] <- SignExtend64( DEST[95:64]) * SignExtend64( SRC[95:64])
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMULDQ __m512i _mm512_mul_epi32(__m512i a, __m512i b);
VPMULDQ __m512i _mm512_mask_mul_epi32(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPMULDQ __m512i _mm512_maskz_mul_epi32( __mmask8 k, __m512i a, __m512i b);
VPMULDQ __m256i _mm256_mask_mul_epi32(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPMULDQ __m256i _mm256_mask_mul_epi32( __mmask8 k, __m256i a, __m256i b);
VPMULDQ __m128i _mm_mask_mul_epi32(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMULDQ __m128i _mm_mask_mul_epi32( __mmask8 k, __m128i a, __m128i b);
(V)PMULDQ __m128i _mm_mul_epi32( __m128i a, __m128i b);
VPMULDQ __m256i _mm256_mul_epi32( __m256i a, __m256i b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.

