----------------------------
title : VPBLENDMB, VPBLENDMWs (Intel x86/64 assembly instruction)
cat_title : VPBLENDMB, VPBLENDMW
ref_title : VPBLENDMB, VPBLENDMW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VPBLENDMB, VPBLENDMW

**Blend Byte/Word Vectors Using an Opmask Control**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F38.W0 66 /r\newline{}VPBLENDMB xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Blend byte integer vector xmm2 and byte vector xmm3/m128 and store the result in xmm1, under control mask.|
|EVEX.NDS.256.66.0F38.W0 66 /r \newline{}VPBLENDMB ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Blend byte integer vector ymm2 and byte vector ymm3/m256 and store the result in ymm1, under control mask.|
|EVEX.NDS.512.66.0F38.W0 66 /r\newline{}VPBLENDMB zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Blend byte integer vector zmm2 and byte vector zmm3/m512 and store the result in zmm1, under control mask.|
|EVEX.NDS.128.66.0F38.W1 66 /r\newline{}VPBLENDMW xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Blend word integer vector xmm2 and word vector xmm3/m128 and store the result in xmm1, under control mask.|
|EVEX.NDS.256.66.0F38.W1 66 /r\newline{}VPBLENDMW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Blend word integer vector ymm2 and word vector ymm3/m256 and store the result in ymm1, under control mask.|
|EVEX.NDS.512.66.0F38.W1 66 /r\newline{}VPBLENDMW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Blend word integer vector zmm2 and word vector zmm3/m512 and store the result in zmm1, under control mask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FVM|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Performs an element-by-element blending of byte/word elements between the first source operand byte vector register and the second source operand byte vector from memory or register, using the instruction mask as selector. The result is written into the destination byte vector register.

The destination and first source operands are ZMM/YMM/XMM registers. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit memory location.

The mask is not used as a writemask for this instruction. Instead, the mask is used as an element selector: every element of the destination is conditionally selected between first source or second source using the value of the related mask bit (0 for first source, 1 for second source).


### Operation
#### VPBLENDMB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SRC2[i+7:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN DEST[i+7:i] <-  SRC1[i+7:i]
                      ELSE  ; zeroing-masking
                            DEST[i+7:i] <-  0
                FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0;
```
#### VPBLENDMW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SRC2[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN DEST[i+15:i] <-  SRC1[i+15:i]
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPBLENDMB __m512i _mm512_mask_blend_epi8(__mmask64 m, __m512i a, __m512i b);
VPBLENDMB __m256i _mm256_mask_blend_epi8(__mmask32 m, __m256i a, __m256i b);
VPBLENDMB __m128i _mm_mask_blend_epi8(__mmask16 m, __m128i a, __m128i b);
VPBLENDMW __m512i _mm512_mask_blend_epi16(__mmask32 m, __m512i a, __m512i b);
VPBLENDMW __m256i _mm256_mask_blend_epi16(__mmask16 m, __m256i a, __m256i b);
VPBLENDMW __m128i _mm_mask_blend_epi16(__mmask8 m, __m128i a, __m128i b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4.

