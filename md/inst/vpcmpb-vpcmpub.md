----------------------------
title : VPCMPB, VPCMPUBs (Intel x86/64 assembly instruction)
cat_title : VPCMPB, VPCMPUB
ref_title : VPCMPB, VPCMPUB
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPCMPB, VPCMPUB

**Compare Packed Byte Values Into Mask**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F3A.W0 3F /r ib\newline{}\newline{}VPCMPB k1 {k2}, xmm2, xmm3/m128, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed byte values in xmm3/m128 and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.256.66.0F3A.W0 3F /r ib\newline{}\newline{}VPCMPB k1 {k2}, ymm2, ymm3/m256, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed byte values in ymm3/m256 and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.512.66.0F3A.W0 3F /r ib\newline{}VPCMPB k1 {k2}, zmm2, zmm3/m512, imm8|FVM|V/V|AVX512BW|Compare packed signed byte values in zmm3/m512 and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.128.66.0F3A.W0 3E /r ib\newline{}\newline{}VPCMPUB k1 {k2}, xmm2, xmm3/m128, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed unsigned byte values in xmm3/m128 and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.256.66.0F3A.W0 3E /r ib\newline{}\newline{}VPCMPUB k1 {k2}, ymm2, ymm3/m256, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed unsigned byte values in ymm3/m256 and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.512.66.0F3A.W0 3E /r ib\newline{}VPCMPUB k1 {k2}, zmm2, zmm3/m512, imm8|FVM|V/V|AVX512BW|Compare packed unsigned byte values in zmm3/m512 and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FVM|ModRM:reg (w)|vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD compare of the packed byte values in the second source operand and the first source operand and returns the results of the comparison to the mask destination operand. The comparison predicate operand (imme-diate byte) specifies the type of comparison performed on each pair of packed values in the two source operands. The result of each comparison is a single mask bit result of 1 (comparison true) or 0 (comparison false).

VPCMPB performs a comparison between pairs of signed byte values.

VPCMPUB performs a comparison between pairs of unsigned byte values.

The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operand (first operand) is a mask register k1. Up to 64/32/16 comparisons are performed with results written to the destination operand under the writemask k2.



The comparison predicate operand is an 8-bit immediate: bits 2:0 define the type of comparison to be performed. Bits 3 through 7 of the immediate are reserved. Compiler can implement the pseudo-op mnemonic listed in Table 5-10.

:

### Table 5-10. Pseudo-Op and VPCMP\htmlonly{*} Implementation


|**Pseudo-Op**|**PCMPM Implementation**|
|-------------|------------------------|
|VPCMPEQ\htmlonly{*} reg1, reg2, reg3|VPCMP\htmlonly{*} reg1, reg2, reg3, 0|
|VPCMPLT\htmlonly{*} reg1, reg2, reg3|VPCMP\htmlonly{*}reg1, reg2, reg3, 1|
|VPCMPLE\htmlonly{*} reg1, reg2, reg3|VPCMP\htmlonly{*} reg1, reg2, reg3, 2|
|VPCMPNEQ\htmlonly{*} reg1, reg2, reg3|VPCMP\htmlonly{*} reg1, reg2, reg3, 4|
|VPPCMPNLT\htmlonly{*} reg1, reg2, reg3|VPCMP\htmlonly{*} reg1, reg2, reg3, 5|
|VPCMPNLE\htmlonly{*} reg1, reg2, reg3|VPCMP\htmlonly{*} reg1, reg2, reg3, 6|

### Operation
#### VPCMPB (EVEX encoded versions) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k2[j] OR *no writemask*
          THEN 
                CMP <-  SRC1[i+7:i] OP SRC2[i+7:i];
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] = 0 ; zeroing-masking onlyFI;
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### VPCMPUB (EVEX encoded versions) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k2[j] OR *no writemask*
          THEN 
                CMP <-  SRC1[i+7:i] OP SRC2[i+7:i];
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] = 0 ; zeroing-masking onlyFI;
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPCMPB __mmask64 _mm512_cmp_epi8_mask( __m512i a, __m512i b, int cmp);
VPCMPB __mmask64 _mm512_mask_cmp_epi8_mask( __mmask64 m, __m512i a, __m512i b, int cmp);
VPCMPB __mmask32 _mm256_cmp_epi8_mask( __m256i a, __m256i b, int cmp);
VPCMPB __mmask32 _mm256_mask_cmp_epi8_mask( __mmask32 m, __m256i a, __m256i b, int cmp);
VPCMPB __mmask16 _mm_cmp_epi8_mask( __m128i a, __m128i b, int cmp);
VPCMPB __mmask16 _mm_mask_cmp_epi8_mask( __mmask16 m, __m128i a, __m128i b, int cmp);
VPCMPB __mmask64 _mm512_cmp[eq|ge|gt|le|lt|neq]_epi8_mask( __m512i a, __m512i b);
VPCMPB __mmask64 _mm512_mask_cmp[eq|ge|gt|le|lt|neq]_epi8_mask( __mmask64 m, __m512i a, __m512i b);
VPCMPB __mmask32 _mm256_cmp[eq|ge|gt|le|lt|neq]_epi8_mask( __m256i a, __m256i b);
VPCMPB __mmask32 _mm256_mask_cmp[eq|ge|gt|le|lt|neq]_epi8_mask( __mmask32 m, __m256i a, __m256i b);
VPCMPB __mmask16 _mm_cmp[eq|ge|gt|le|lt|neq]_epi8_mask( __m128i a, __m128i b);
VPCMPB __mmask16 _mm_mask_cmp[eq|ge|gt|le|lt|neq]_epi8_mask( __mmask16 m, __m128i a, __m128i b);
VPCMPUB __mmask64 _mm512_cmp_epu8_mask( __m512i a, __m512i b, int cmp);
VPCMPUB __mmask64 _mm512_mask_cmp_epu8_mask( __mmask64 m, __m512i a, __m512i b, int cmp);
VPCMPUB __mmask32 _mm256_cmp_epu8_mask( __m256i a, __m256i b, int cmp);
VPCMPUB __mmask32 _mm256_mask_cmp_epu8_mask( __mmask32 m, __m256i a, __m256i b, int cmp);
VPCMPUB __mmask16 _mm_cmp_epu8_mask( __m128i a, __m128i b, int cmp);
VPCMPUB __mmask16 _mm_mask_cmp_epu8_mask( __mmask16 m, __m128i a, __m128i b, int cmp);
VPCMPUB __mmask64 _mm512_cmp[eq|ge|gt|le|lt|neq]_epu8_mask( __m512i a, __m512i b, int cmp);
VPCMPUB __mmask64 _mm512_mask_cmp[eq|ge|gt|le|lt|neq]_epu8_mask( __mmask64 m, __m512i a, __m512i b, int cmp);
VPCMPUB __mmask32 _mm256_cmp[eq|ge|gt|le|lt|neq]_epu8_mask( __m256i a, __m256i b, int cmp);
VPCMPUB __mmask32 _mm256_mask_cmp[eq|ge|gt|le|lt|neq]_epu8_mask( __mmask32 m, __m256i a, __m256i b, int cmp);
VPCMPUB __mmask16 _mm_cmp[eq|ge|gt|le|lt|neq]_epu8_mask( __m128i a, __m128i b, int cmp);
VPCMPUB __mmask16 _mm_mask_cmp[eq|ge|gt|le|lt|neq]_epu8_mask( __mmask16 m, __m128i a, __m128i b, int cmp);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E4.nb.
