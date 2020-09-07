----------------------------
title : VPMOVM2B, VPMOVM2W, VPMOVM2D, VPMOVM2Qs (Intel x86/64 assembly instruction)
cat_title : VPMOVM2B, VPMOVM2W, VPMOVM2D, VPMOVM2Q
ref_title : VPMOVM2B, VPMOVM2W, VPMOVM2D, VPMOVM2Q
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VPMOVM2B, VPMOVM2W, VPMOVM2D, VPMOVM2Q

**Convert a Mask Register to a Vector Register**

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.F3.0F38.W0 28 /r \newline{}VPMOVM2B xmm1, k1|RM|V/V|AVX512VL\newline{}AVX512BW|Sets each byte in XMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.256.F3.0F38.W0 28 /r \newline{}VPMOVM2B ymm1, k1|RM|V/V|AVX512VL\newline{}AVX512BW|Sets each byte in YMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.512.F3.0F38.W0 28 /r \newline{}VPMOVM2B zmm1, k1|RM|V/V|AVX512BW|Sets each byte in ZMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.128.F3.0F38.W1 28 /r \newline{}VPMOVM2W xmm1, k1 |RM|V/V|AVX512VL\newline{}AVX512BW|Sets each word in XMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.256.F3.0F38.W1 28 /r\newline{}VPMOVM2W ymm1, k1 |RM|V/V|AVX512VL\newline{}AVX512BW|Sets each word in YMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.512.F3.0F38.W1 28 /r \newline{}VPMOVM2W zmm1, k1 |RM|V/V|AVX512BW|Sets each word in ZMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.128.F3.0F38.W0 38 /r \newline{}VPMOVM2D xmm1, k1|RM|V/V|AVX512VL\newline{}AVX512DQ|Sets each doubleword in XMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.256.F3.0F38.W0 38 /r \newline{}VPMOVM2D ymm1, k1|RM|V/V|AVX512VL\newline{}AVX512DQ|Sets each doubleword in YMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.512.F3.0F38.W0 38 /r \newline{}VPMOVM2D zmm1, k1|RM|V/V|AVX512DQ|Sets each doubleword in ZMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.128.F3.0F38.W1 38 /r \newline{}VPMOVM2Q xmm1, k1 |RM|V/V|AVX512VL\newline{}AVX512DQ|Sets each quadword in XMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.256.F3.0F38.W1 38 /r \newline{}VPMOVM2Q ymm1, k1 |RM|V/V|AVX512VL\newline{}AVX512DQ|Sets each quadword in YMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
|EVEX.512.F3.0F38.W1 38 /r \newline{}VPMOVM2Q zmm1, k1 |RM|V/V|AVX512DQ|Sets each quadword in ZMM1 to all 1's or all 0's based on the value of the corresponding bit in k1. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description 


Converts a mask register to a vector register. Each element in the destination register is set to all 1's or all 0's depending on the value of the corresponding bit in the source mask register.

The source operand is a mask register. The destination operand is a ZMM/YMM/XMM register.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPMOVM2B (EVEX encoded versions) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF SRC[j]
          THEN  DEST[i+7:i] <-  -1 
          ELSE  DEST[i+7:i] <-  0
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPMOVM2W (EVEX encoded versions) 
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF SRC[j]
          THEN  DEST[i+15:i] <-  -1 
          ELSE  DEST[i+15:i] <-  0
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPMOVM2D (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF SRC[j]
          THEN  DEST[i+31:i] <-  -1 
          ELSE  DEST[i+31:i] <-  0
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPMOVM2Q (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF SRC[j]
          THEN  DEST[i+63:i] <-  -1 
          ELSE  DEST[i+63:i] <-  0
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPMOVM2B __m512i _mm512_movm_epi8(__mmask64 );
VPMOVM2D __m512i _mm512_movm_epi32(__mmask8 );
VPMOVM2Q __m512i _mm512_movm_epi64(__mmask16 );
VPMOVM2W __m512i _mm512_movm_epi16(__mmask32 );
VPMOVM2B __m256i _mm256_movm_epi8(__mmask32 );
VPMOVM2D __m256i _mm256_movm_epi32(__mmask8 );
VPMOVM2Q __m256i _mm256_movm_epi64(__mmask8 );
VPMOVM2W __m256i _mm256_movm_epi16(__mmask16 );
VPMOVM2B __m128i _mm_movm_epi8(__mmask16 );
VPMOVM2D __m128i _mm_movm_epi32(__mmask8 );
VPMOVM2Q __m128i _mm_movm_epi64(__mmask8 );
VPMOVM2W __m128i _mm_movm_epi16(__mmask8 );
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E7NM

#UD  If EVEX.vvvv != 1111B.

