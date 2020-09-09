----------------------------
title : VPERMD, VPERMWs (Intel x86/64 assembly instruction)
cat_title : VPERMD, VPERMW
ref_title : VPERMD, VPERMW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPERMD, VPERMW

**Permute Packed Doublewords/Words Elements**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.256.66.0F38.W0 36 /r\newline{}VPERMD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Permute doublewords in ymm3/m256 using indices in ymm2 and store the result in ymm1.|
|EVEX.NDS.256.66.0F38.W0 36 /r\newline{}VPERMD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Permute doublewords in ymm3/m256/m32bcst using indexes in ymm2 and store the result in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W0 36 /r\newline{}VPERMD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Permute doublewords in zmm3/m512/m32bcst using indices in zmm2 and store the result in zmm1 using writemask k1.|
|EVEX.NDS.128.66.0F38.W1 8D /r\newline{}\newline{}VPERMW xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Permute word integers in xmm3/m128 using indexes in xmm2 and store the result in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F38.W1 8D /r\newline{}\newline{}VPERMW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Permute word integers in ymm3/m256 using indexes in ymm2 and store the result in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W1 8D /r\newline{}VPERMW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Permute word integers in zmm3/m512 using indexes in zmm2 and store the result in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
### Description


Copies doublewords (or words) from the second source operand (the third operand) to the destination operand (the first operand) according to the indices in the first source operand (the second operand). Note that this instruction permits a doubleword (word) in the source operand to be copied to more than one location in the destination operand.

VEX.256 encoded VPERMD: The first and second operands are YMM registers, the third operand can be a YMM register or memory location. Bits (MAX\esc{_}VL-1:256) of the corresponding destination register are zeroed. 

EVEX encoded VPERMD: The first and second operands are ZMM/YMM registers, the third operand can be a ZMM/YMM register, a 512/256-bit memory location or a 512/256-bit vector broadcasted from a 32-bit memory location. The elements in the destination are updated using the writemask k1.

VPERMW: first and second operands are ZMM/YMM/XMM registers, the third operand can be a ZMM/YMM/XMM register, or a 512/256/128-bit memory location. The destination is updated using the writemask k1.

EVEX.128 encoded versions: Bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register are zeroed.


### Operation
#### VPERMD (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 256), (16, 512)
IF VL = 256 THEN n <-  2; FI;
IF VL = 512 THEN n <-  3; FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    id <-  32*SRC1[i+n:i]
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+31:i] <-  SRC2[31:0];
                      ELSE DEST[i+31:i] <-  SRC2[id+31:id];
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPERMD (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  (SRC2[255:0] >> (SRC1[2:0] * 32))[31:0];
DEST[63:32] <-  (SRC2[255:0] >> (SRC1[34:32] * 32))[31:0];
DEST[95:64] <-  (SRC2[255:0] >> (SRC1[66:64] * 32))[31:0];
DEST[127:96] <-  (SRC2[255:0] >> (SRC1[98:96] * 32))[31:0];
DEST[159:128] <-  (SRC2[255:0] >> (SRC1[130:128] * 32))[31:0];
DEST[191:160] <-  (SRC2[255:0] >> (SRC1[162:160] * 32))[31:0];
DEST[223:192] <-  (SRC2[255:0] >> (SRC1[194:192] * 32))[31:0];
DEST[255:224] <-  (SRC2[255:0] >> (SRC1[226:224] * 32))[31:0];
DEST[MAX_VL-1:256] <-  0
```
#### VPERMW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128 THEN n <-  2; FI;
IF VL = 256 THEN n <-  3; FI;
IF VL = 512 THEN n <-  4; FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    id <-  16*SRC1[i+n:i]
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SRC2[id+15:id]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPERMD __m512i _mm512_permutexvar_epi32( __m512i idx, __m512i a);
VPERMD __m512i _mm512_mask_permutexvar_epi32(__m512i s, __mmask16 k, __m512i idx, __m512i a);
VPERMD __m512i _mm512_maskz_permutexvar_epi32( __mmask16 k, __m512i idx, __m512i a);
VPERMD __m256i _mm256_permutexvar_epi32( __m256i idx, __m256i a);
VPERMD __m256i _mm256_mask_permutexvar_epi32(__m256i s, __mmask8 k, __m256i idx, __m256i a);
VPERMD __m256i _mm256_maskz_permutexvar_epi32( __mmask8 k, __m256i idx, __m256i a);
VPERMW __m512i _mm512_permutexvar_epi16( __m512i idx, __m512i a);
VPERMW __m512i _mm512_mask_permutexvar_epi16(__m512i s, __mmask32 k, __m512i idx, __m512i a);
VPERMW __m512i _mm512_maskz_permutexvar_epi16( __mmask32 k, __m512i idx, __m512i a);
VPERMW __m256i _mm256_permutexvar_epi16( __m256i idx, __m256i a);
VPERMW __m256i _mm256_mask_permutexvar_epi16(__m256i s, __mmask16 k, __m256i idx, __m256i a);
VPERMW __m256i _mm256_maskz_permutexvar_epi16( __mmask16 k, __m256i idx, __m256i a);
VPERMW __m128i _mm_permutexvar_epi16( __m128i idx, __m128i a);
VPERMW __m128i _mm_mask_permutexvar_epi16(__m128i s, __mmask8 k, __m128i idx, __m128i a);
VPERMW __m128i _mm_maskz_permutexvar_epi16( __mmask8 k, __m128i idx, __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPERMD, see Exceptions Type E4NF.

EVEX-encoded VPERMW, see Exceptions Type E4NF.nb.

#UD If VEX.L = 0.

                              If EVEX.L'L = 0 for VPERMD.

