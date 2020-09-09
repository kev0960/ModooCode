----------------------------
title : VPEXPANDQ (Intel x86/64 assembly instruction)
cat_title : VPEXPANDQ
ref_title : VPEXPANDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPEXPANDQ

**Load Sparse Packed Quadword Integer Values from Dense Memory / Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W1 89 /r\newline{}VPEXPANDQ xmm1 {k1}{z}, xmm2/m128|T1S|V/V|AVX512VL\newline{}AVX512F|Expand packed quad-word integer values from xmm2/m128 to xmm1 using writemask k1.|
|EVEX.256.66.0F38.W1 89 /r\newline{}VPEXPANDQ ymm1 {k1}{z}, ymm2/m256|T1S|V/V|AVX512VL\newline{}AVX512F|Expand packed quad-word integer values from ymm2/m256 to ymm1 using writemask k1.|
|EVEX.512.66.0F38.W1 89 /r\newline{}VPEXPANDQ zmm1 {k1}{z}, zmm2/m512|T1S|V/V|AVX512F|Expand packed quad-word integer values from zmm2/m512 to zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description 


Expand (load) up to 8 quadword integer values from the source operand (the second operand) to sparse elements in the destination operand (the first operand), selected by the writemask k1. The destination operand is a ZMM register, the source operand can be a ZMM register or memory location.

The input vector starts from the lowest element in the source operand. The opmask register k1 selects the destina-tion elements (a partial vector or sparse elements if less than 8 elements) to be replaced by the ascending elements in the input vector. Destination elements not selected by the writemask k1 are either unmodified or zeroed, depending on EVEX.z.

Note: EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

Note that the compressed displacement assumes a pre-scaling (N) corresponding to the size of one single element instead of the size of the full vector.


### Operation
#### VPEXPANDQ (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
k <-  0
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                DEST[i+63:i] <-  SRC[k+63:k];
                k <-  k + 64
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            THEN DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-!= 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPEXPANDQ __m512i _mm512_mask_expandloadu_epi64(__m512i s, __mmask8 k, void * a);
VPEXPANDQ __m512i _mm512_maskz_expandloadu_epi64( __mmask8 k, void * a);
VPEXPANDQ __m512i _mm512_mask_expand_epi64(__m512i s, __mmask8 k, __m512i a);
VPEXPANDQ __m512i _mm512_maskz_expand_epi64( __mmask8 k, __m512i a);
VPEXPANDQ __m256i _mm256_mask_expandloadu_epi64(__m256i s, __mmask8 k, void * a);
VPEXPANDQ __m256i _mm256_maskz_expandloadu_epi64( __mmask8 k, void * a);
VPEXPANDQ __m256i _mm256_mask_expand_epi64(__m256i s, __mmask8 k, __m256i a);
VPEXPANDQ __m256i _mm256_maskz_expand_epi64( __mmask8 k, __m256i a);
VPEXPANDQ __m128i _mm_mask_expandloadu_epi64(__m128i s, __mmask8 k, void * a);
VPEXPANDQ __m128i _mm_maskz_expandloadu_epi64( __mmask8 k, void * a);
VPEXPANDQ __m128i _mm_mask_expand_epi64(__m128i s, __mmask8 k, __m128i a);
VPEXPANDQ __m128i _mm_maskz_expand_epi64( __mmask8 k, __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E4.nb.

#UD If EVEX.vvvv != 1111B.

