----------------------------
title : VPTERNLOGD, VPTERNLOGQs (Intel x86/64 assembly instruction)
cat_title : VPTERNLOGD, VPTERNLOGQ
ref_title : VPTERNLOGD, VPTERNLOGQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPTERNLOGD, VPTERNLOGQ

**Bitwise Ternary Logic**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.DDS.128.66.0F3A.W0 25 /r ib\newline{}VPTERNLOGD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Bitwise ternary logic taking xmm1, xmm2 and xmm3/m128/m32bcst as source operands and writing the result to xmm1 under writemask k1 with dword granularity. The immediate value determines the specific binary function being implemented.|
|EVEX.DDS.256.66.0F3A.W0 25 /r ib\newline{}VPTERNLOGD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Bitwise ternary logic taking ymm1, ymm2 and ymm3/m256/m32bcst as source operands and writing the result to ymm1 under writemask k1 with dword granularity. The immediate value determines the specific binary function being implemented.|
|EVEX.DDS.512.66.0F3A.W0 25 /r ib\newline{}VPTERNLOGD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst, imm8|FV|V/V|AVX512F|Bitwise ternary logic taking zmm1, zmm2 and zmm3/m512/m32bcst as source operands and writing the result to zmm1 under writemask k1 with dword granularity. The immediate value determines the specific binary function being implemented.|
|EVEX.DDS.128.66.0F3A.W1 25 /r ib\newline{}VPTERNLOGQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Bitwise ternary logic taking xmm1, xmm2 and xmm3/m128/m64bcst as source operands and writing the result to xmm1 under writemask k1 with qword granularity. The immediate value determines the specific binary function being implemented. |
|EVEX.DDS.256.66.0F3A.W1 25 /r ib\newline{}VPTERNLOGQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Bitwise ternary logic taking ymm1, ymm2 and ymm3/m256/m64bcst as source operands and writing the result to ymm1 under writemask k1 with qword granularity. The immediate value determines the specific binary function being implemented. |
|EVEX.DDS.512.66.0F3A.W1 25 /r ib\newline{}VPTERNLOGQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst, imm8|FV|V/V|AVX512F|Bitwise ternary logic taking zmm1, zmm2 and zmm3/m512/m64bcst as source operands and writing the result to zmm1 under writemask k1 with qword granularity. The immediate value determines the specific binary function being implemented. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (r, w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description 


VPTERNLOGD/Q takes three bit vectors of 512-bit length (in the first, second and third operand) as input data to form a set of 512 indices, each index is comprised of one bit from each input vector. The imm8 byte specifies a boolean logic table producing a binary value for each 3-bit index value. The final 512-bit boolean result is written to the destination operand (the first operand) using the writemask k1 with the granularity of doubleword element or quadword element into the destination.

The destination operand is a ZMM (EVEX.512)/YMM (EVEX.256)/XMM (EVEX.128) register. The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location The destination operand is a ZMM register conditionally updated with writemask k1.



Table 5-11 shows two examples of Boolean functions specified by immediate values 0xE2 and 0xE4, with the look up result listed in the fourth column following the three columns containing all possible values of the 3-bit index.

###                    Table 5-11. Examples of VPTERNLOGD/Q Imm8 Boolean Function and Input Index Values


Specifying different values in imm8 will allow any arbitrary three-input Boolean functions to be implemented in software using VPTERNLOGD/Q. Table 5-1 and Table 5-2 provide a mapping of all 256 possible imm8 values to various Boolean expressions.



|**VPTERNLOGD **|**reg1, reg2, src3**|**, 0xE2**|**Bit Result with **|**VPTERNLOGD **|**reg1, reg2, src3**|**, 0xE4**|**Bit Result with **|
|---------------|--------------------|----------|--------------------|---------------|--------------------|----------|--------------------|
|||||||||
|**Bit(reg1)**|**Bit(reg2)**|**Bit(src3)**|**Imm8=0xE2**|**Bit(reg1)**|**Bit(reg2)**|**Bit(src3)**|**Imm8=0xE4**|
|0|0|0|0|0|0|0|0|
|0|0|1|1|0|0|1|0|
|0|1|0|0|0|1|0|1|
|0|1|1|0|0|1|1|0|
|1|0|0|0|1|0|0|0|
|1|0|1|1|1|0|1|1|
|1|1|0|1|1|1|0|1|
|1|1|1|1|1|1|1|1|

### Operation
#### VPTERNLOGD (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                FOR k <-  0 TO 31 
                      IF (EVEX.b = 1) AND (SRC2 *is memory*)
                            THEN DEST[j][k] <-  imm[(DEST[i+k] << 2) + (SRC1[ i+k ] << 1) + SRC2[ k ]]
                            ELSE DEST[j][k] <-  imm[(DEST[i+k] << 2) + (SRC1[ i+k ] << 1) + SRC2[ i+k ]]
                      FI;
                                  ; table lookup of immediate bellow;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31+i:i] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[31+i:i] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPTERNLOGQ (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                FOR k <-  0 TO 63 
                      IF (EVEX.b = 1) AND (SRC2 *is memory*)
                            THEN DEST[j][k] <-  imm[(DEST[i+k] << 2) + (SRC1[ i+k ] << 1) + SRC2[ k ]]
                            ELSE DEST[j][k] <-  imm[(DEST[i+k] << 2) + (SRC1[ i+k ] << 1) + SRC2[ i+k ]]
                      FI; ; table lookup of immediate bellow;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[63+i:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[63+i:i] <-  0
                FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPTERNLOGD __m512i _mm512_ternarylogic_epi32(__m512i a, __m512i b, int imm);
VPTERNLOGD __m512i _mm512_mask_ternarylogic_epi32(__m512i s, __mmask16 m, __m512i a, __m512i b, int imm);
VPTERNLOGD __m512i _mm512_maskz_ternarylogic_epi32(__mmask m, __m512i a, __m512i b, int imm);
VPTERNLOGD __m256i _mm256_ternarylogic_epi32(__m256i a, __m256i b, int imm);
VPTERNLOGD __m256i _mm256_mask_ternarylogic_epi32(__m256i s, __mmask8 m, __m256i a, __m256i b, int imm);
VPTERNLOGD __m256i _mm256_maskz_ternarylogic_epi32( __mmask8 m, __m256i a, __m256i b, int imm);
VPTERNLOGD __m128i _mm_ternarylogic_epi32(__m128i a, __m128i b, int imm);
VPTERNLOGD __m128i _mm_mask_ternarylogic_epi32(__m128i s, __mmask8 m, __m128i a, __m128i b, int imm);
VPTERNLOGD __m128i _mm_maskz_ternarylogic_epi32( __mmask8 m, __m128i a, __m128i b, int imm);
VPTERNLOGQ __m512i _mm512_ternarylogic_epi64(__m512i a, __m512i b, int imm);
VPTERNLOGQ __m512i _mm512_mask_ternarylogic_epi64(__m512i s, __mmask8 m, __m512i a, __m512i b, int imm);
VPTERNLOGQ __m512i _mm512_maskz_ternarylogic_epi64( __mmask8 m, __m512i a, __m512i b, int imm);
VPTERNLOGQ __m256i _mm256_ternarylogic_epi64(__m256i a, __m256i b, int imm);
VPTERNLOGQ __m256i _mm256_mask_ternarylogic_epi64(__m256i s, __mmask8 m, __m256i a, __m256i b, int imm);
VPTERNLOGQ __m256i _mm256_maskz_ternarylogic_epi64( __mmask8 m, __m256i a, __m256i b, int imm);
VPTERNLOGQ __m128i _mm_ternarylogic_epi64(__m128i a, __m128i b, int imm);
VPTERNLOGQ __m128i _mm_mask_ternarylogic_epi64(__m128i s, __mmask8 m, __m128i a, __m128i b, int imm);
VPTERNLOGQ __m128i _mm_maskz_ternarylogic_epi64( __mmask8 m, __m128i a, __m128i b, int imm);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4.

