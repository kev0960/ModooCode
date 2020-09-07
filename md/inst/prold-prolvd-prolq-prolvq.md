----------------------------
title : PROLD, PROLVD, PROLQ, PROLVQs (Intel x86/64 assembly instruction)
cat_title : PROLD, PROLVD, PROLQ, PROLVQ
ref_title : PROLD, PROLVD, PROLQ, PROLVQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PROLD, PROLVD, PROLQ, PROLVQ

**Bit Rotate Left**

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F38.W0 15 /r\newline{}VPROLVD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV-RVM|V/V|AVX512VL\newline{}AVX512F|Rotate doublewords in xmm2 left by count in the corresponding element of xmm3/m128/m32bcst. Result written to xmm1 under writemask k1.|
|EVEX.NDD.128.66.0F.W0 72 /1 ib\newline{}VPROLD xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FV-VMI|V/V|AVX512VL\newline{}AVX512F|Rotate doublewords in xmm2/m128/m32bcst left by imm8. Result written to xmm1 using writemask k1.|
|EVEX.NDS.128.66.0F38.W1 15 /r\newline{}VPROLVQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV-RVM|V/V|AVX512VL\newline{}AVX512F|Rotate quadwords in xmm2 left by count in the corresponding element of xmm3/m128/m64bcst. Result written to xmm1 under writemask k1.|
|EVEX.NDD.128.66.0F.W1 72 /1 ib\newline{}VPROLQ xmm1 {k1}{z}, xmm2/m128/m64bcst, imm8|FV-VMI|V/V|AVX512VL\newline{}AVX512F|Rotate quadwords in xmm2/m128/m64bcst left by imm8. Result written to xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F38.W0 15 /r\newline{}VPROLVD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV-RVM|V/V|AVX512VL\newline{}AVX512F|Rotate doublewords in ymm2 left by count in the corresponding element of ymm3/m256/m32bcst. Result written to ymm1 under writemask k1.|
|EVEX.NDD.256.66.0F.W0 72 /1 ib\newline{}VPROLD ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FV-VMI|V/V|AVX512VL\newline{}AVX512F|Rotate doublewords in ymm2/m256/m32bcst left by imm8. Result written to ymm1 using writemask k1.|
|EVEX.NDS.256.66.0F38.W1 15 /r\newline{}VPROLVQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV-RVM|V/V|AVX512VL\newline{}AVX512F|Rotate quadwords in ymm2 left by count in the corresponding element of ymm3/m256/m64bcst. Result written to ymm1 under writemask k1.|
|EVEX.NDD.256.66.0F.W1 72 /1 ib\newline{}VPROLQ ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FV-VMI|V/V|AVX512VL\newline{}AVX512F|Rotate quadwords in ymm2/m256/m64bcst left by imm8. Result written to ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W0 15 /r\newline{}VPROLVD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV-RVM|V/V|AVX512F|Rotate left of doublewords in zmm2 by count in the corresponding element of zmm3/m512/m32bcst. Result written to zmm1 using writemask k1.|
|EVEX.NDD.512.66.0F.W0 72 /1 ib\newline{}VPROLD zmm1 {k1}{z}, zmm2/m512/m32bcst, imm8|FV-VMI|V/V|AVX512F|Rotate left of doublewords in zmm3/m512/m32bcst by imm8. Result written to zmm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W1 15 /r\newline{}VPROLVQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV-RVM|V/V|AVX512F|Rotate quadwords in zmm2 left by count in the corresponding element of zmm3/m512/m64bcst. Result written to zmm1under writemask k1.|
|EVEX.NDD.512.66.0F.W1 72 /1 ib\newline{}VPROLQ zmm1 {k1}{z}, zmm2/m512/m64bcst, imm8|FV-VMI|V/V|AVX512F|Rotate quadwords in zmm2/m512/m64bcst left by imm8. Result written to zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV-VMI|VEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
|FV-RVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Rotates the bits in the individual data elements (doublewords, or quadword) in the first source operand to the left by the number of bits specified in the count operand. If the value specified by the count operand is greater than 31 (for doublewords), or 63 (for a quadword), then the count operand modulo the data size (32 or 64) is used. 

EVEX.128 encoded version: The destination operand is a XMM register. The source operand is a XMM register or a memory location (for immediate form). The count operand can come either from an XMM register or a memory location or an 8-bit immediate. Bits (MAX\esc{_}VL-1:128) of the corresponding ZMM register are zeroed.

EVEX.256 encoded version: The destination operand is a YMM register. The source operand is a YMM register or a memory location (for immediate form). The count operand can come either from an XMM register or a memory location or an 8-bit immediate. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed.

EVEX.512 encoded version: The destination operand is a ZMM register updated according to the writemask. For the count operand in immediate form, the source operand can be a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32/64-bit memory location, the count operand is an 8-bit immediate. For the count operand in variable form, the first source operand (the second operand) is a ZMM register and the counter operand (the third operand) is a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32/64-bit memory location. 


### Operation
#### VPROLD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+31:i] <-  LEFT_ROTATE_DWORDS(SRC1[31:0], imm8)
                      ELSE DEST[i+31:i] <-  LEFT_ROTATE_DWORDS(SRC1[i+31:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPROLVD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+31:i] <-  LEFT_ROTATE_DWORDS(SRC1[i+31:i], SRC2[31:0])
                      ELSE DEST[i+31:i] <-  LEFT_ROTATE_DWORDS(SRC1[i+31:i], SRC2[i+31:i])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPROLQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+63:i] <-  LEFT_ROTATE_QWORDS(SRC1[63:0], imm8)
                      ELSE DEST[i+63:i] <-  LEFT_ROTATE_QWORDS(SRC1[i+63:i], imm8)
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
#### VPROLVQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  LEFT_ROTATE_QWORDS(SRC1[i+63:i], SRC2[63:0])
                      ELSE DEST[i+63:i] <-  LEFT_ROTATE_QWORDS(SRC1[i+63:i], SRC2[i+63:i])
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

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPROLD __m512i _mm512_rol_epi32(__m512i a, int imm);
VPROLD __m512i _mm512_mask_rol_epi32(__m512i a, __mmask16 k, __m512i b, int imm);
VPROLD __m512i _mm512_maskz_rol_epi32( __mmask16 k, __m512i a, int imm);
VPROLD __m256i _mm256_rol_epi32(__m256i a, int imm);
VPROLD __m256i _mm256_mask_rol_epi32(__m256i a, __mmask8 k, __m256i b, int imm);
VPROLD __m256i _mm256_maskz_rol_epi32( __mmask8 k, __m256i a, int imm);
VPROLD __m128i _mm_rol_epi32(__m128i a, int imm);
VPROLD __m128i _mm_mask_rol_epi32(__m128i a, __mmask8 k, __m128i b, int imm);
VPROLD __m128i _mm_maskz_rol_epi32( __mmask8 k, __m128i a, int imm);
VPROLQ __m512i _mm512_rol_epi64(__m512i a, int imm);
VPROLQ __m512i _mm512_mask_rol_epi64(__m512i a, __mmask8 k, __m512i b, int imm);
VPROLQ __m512i _mm512_maskz_rol_epi64(__mmask8 k, __m512i a, int imm);
VPROLQ __m256i _mm256_rol_epi64(__m256i a, int imm);
VPROLQ __m256i _mm256_mask_rol_epi64(__m256i a, __mmask8 k, __m256i b, int imm);
VPROLQ __m256i _mm256_maskz_rol_epi64( __mmask8 k, __m256i a, int imm);
VPROLQ __m128i _mm_rol_epi64(__m128i a, int imm);
VPROLQ __m128i _mm_mask_rol_epi64(__m128i a, __mmask8 k, __m128i b, int imm);
VPROLQ __m128i _mm_maskz_rol_epi64( __mmask8 k, __m128i a, int imm);
VPROLVD __m512i _mm512_rolv_epi32(__m512i a, __m512i cnt);
VPROLVD __m512i _mm512_mask_rolv_epi32(__m512i a, __mmask16 k, __m512i b, __m512i cnt);
VPROLVD __m512i _mm512_maskz_rolv_epi32(__mmask16 k, __m512i a, __m512i cnt);
VPROLVD __m256i _mm256_rolv_epi32(__m256i a, __m256i cnt);
VPROLVD __m256i _mm256_mask_rolv_epi32(__m256i a, __mmask8 k, __m256i b, __m256i cnt);
VPROLVD __m256i _mm256_maskz_rolv_epi32(__mmask8 k, __m256i a, __m256i cnt);
VPROLVD __m128i _mm_rolv_epi32(__m128i a, __m128i cnt);
VPROLVD __m128i _mm_mask_rolv_epi32(__m128i a, __mmask8 k, __m128i b, __m128i cnt);
VPROLVD __m128i _mm_maskz_rolv_epi32(__mmask8 k, __m128i a, __m128i cnt);
VPROLVQ __m512i _mm512_rolv_epi64(__m512i a, __m512i cnt);
VPROLVQ __m512i _mm512_mask_rolv_epi64(__m512i a, __mmask8 k, __m512i b, __m512i cnt);
VPROLVQ __m512i _mm512_maskz_rolv_epi64( __mmask8 k, __m512i a, __m512i cnt);
VPROLVQ __m256i _mm256_rolv_epi64(__m256i a, __m256i cnt);
VPROLVQ __m256i _mm256_mask_rolv_epi64(__m256i a, __mmask8 k, __m256i b, __m256i cnt);
VPROLVQ __m256i _mm256_maskz_rolv_epi64(__mmask8 k, __m256i a, __m256i cnt);
VPROLVQ __m128i _mm_rolv_epi64(__m128i a, __m128i cnt);
VPROLVQ __m128i _mm_mask_rolv_epi64(__m128i a, __mmask8 k, __m128i b, __m128i cnt);
VPROLVQ __m128i _mm_maskz_rolv_epi64(__mmask8 k, __m128i a, __m128i cnt);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E4.

