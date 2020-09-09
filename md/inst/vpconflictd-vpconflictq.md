----------------------------
title : VPCONFLICTD, VPCONFLICTQs (Intel x86/64 assembly instruction)
cat_title : VPCONFLICTD, VPCONFLICTQ
ref_title : VPCONFLICTD, VPCONFLICTQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPCONFLICTD, VPCONFLICTQ

**Detect Conflicts Within a Vector of Packed Dword/Qword Values into Dense Memory/ Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W0 C4 /r\newline{}VPCONFLICTD xmm1 {k1}{z}, xmm2/m128/m32bcst|FV |V/V |AVX512VL\newline{}AVX512CD|Detect duplicate double-word values in xmm2/m128/m32bcst using writemask k1.|
|EVEX.256.66.0F38.W0 C4 /r\newline{}VPCONFLICTD ymm1 {k1}{z}, ymm2/m256/m32bcst|FV|V/V |AVX512VL\newline{}AVX512CD|Detect duplicate double-word values in ymm2/m256/m32bcst using writemask k1.|
|EVEX.512.66.0F38.W0 C4 /r\newline{}VPCONFLICTD zmm1 {k1}{z}, zmm2/m512/m32bcst|FV |V/V |AVX512CD|Detect duplicate double-word values in zmm2/m512/m32bcst using writemask k1.|
|EVEX.128.66.0F38.W1 C4 /r\newline{}VPCONFLICTQ xmm1 {k1}{z}, xmm2/m128/m64bcst|FV |V/V |AVX512VL\newline{}AVX512CD|Detect duplicate quad-word values in xmm2/m128/m64bcst using writemask k1.|
|EVEX.256.66.0F38.W1 C4 /r\newline{}VPCONFLICTQ ymm1 {k1}{z}, ymm2/m256/m64bcst|FV |V/V |AVX512VL\newline{}AVX512CD|Detect duplicate quad-word values in ymm2/m256/m64bcst using writemask k1.|
|EVEX.512.66.0F38.W1 C4 /r\newline{}VPCONFLICTQ zmm1 {k1}{z}, zmm2/m512/m64bcst|FV |V/V |AVX512CD|Detect duplicate quad-word values in zmm2/m512/m64bcst using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Test each dword/qword element of the source operand (the second operand) for equality with all other elements in the source operand closer to the least significant element. Each element's comparison results form a bit vector, which is then zero extended and written to the destination according to the writemask.

EVEX.512 encoded version: The source operand is a ZMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a ZMM register, conditionally updated using writemask k1. 

EVEX.256 encoded version: The source operand is a YMM register, a 256-bit memory location, or a 256-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a YMM register, conditionally updated using writemask k1. 

EVEX.128 encoded version: The source operand is a XMM register, a 128-bit memory location, or a 128-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a XMM register, conditionally updated using writemask k1. 

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPCONFLICTD
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j*32
    IF MaskBit(j) OR *no writemask*THEN 
          FOR k <-  0 TO j-1
                m <-  k*32
                IF ((SRC[i+31:i] = SRC[m+31:m])) THEN 
                      DEST[i+k] <-  1
                ELSE 
                      DEST[i+k] <-  0
                FI
          ENDFOR
          DEST[i+31:i+j] <-  0
    ELSE
          IF *merging-masking* THEN 
                *DEST[i+31:i] remains unchanged*
          ELSE 
                DEST[i+31:i] <-  0
          FI
    FI
ENDFOR
DEST[MAX_VL-1:VL] <- 0
```
#### VPCONFLICTQ
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
     i <-  j*64
     IF MaskBit(j) OR *no writemask*THEN 
          FOR k <-  0 TO j-1
                m <-  k*64
                 IF ((SRC[i+63:i] = SRC[m+63:m])) THEN 
                      DEST[i+k] <-  1
                 ELSE 
                      DEST[i+k] <-  0
                FI
           ENDFOR
           DEST[i+63:i+j] <-  0
     ELSE
           IF *merging-masking* THEN 
                 *DEST[i+63:i] remains unchanged*
            ELSE
                 DEST[i+63:i] <-  0
            FI
     FI
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPCONFLICTD __m512i _mm512_conflict_epi32( __m512i a);
VPCONFLICTD __m512i _mm512_mask_conflict_epi32(__m512i s, __mmask16 m, __m512i a);
VPCONFLICTD __m512i _mm512_maskz_conflict_epi32(__mmask16 m, __m512i a);
VPCONFLICTQ __m512i _mm512_conflict_epi64( __m512i a);
VPCONFLICTQ __m512i _mm512_mask_conflict_epi64(__m512i s, __mmask8 m, __m512i a);
VPCONFLICTQ __m512i _mm512_maskz_conflict_epi64(__mmask8 m, __m512i a);
VPCONFLICTD __m256i _mm256_conflict_epi32( __m256i a);
VPCONFLICTD __m256i _mm256_mask_conflict_epi32(__m256i s, __mmask8 m, __m256i a);
VPCONFLICTD __m256i _mm256_maskz_conflict_epi32(__mmask8 m, __m256i a);
VPCONFLICTQ __m256i _mm256_conflict_epi64( __m256i a);
VPCONFLICTQ __m256i _mm256_mask_conflict_epi64(__m256i s, __mmask8 m, __m256i a);
VPCONFLICTQ __m256i _mm256_maskz_conflict_epi64(__mmask8 m, __m256i a);
VPCONFLICTD __m128i _mm_conflict_epi32( __m128i a);
VPCONFLICTD __m128i _mm_mask_conflict_epi32(__m128i s, __mmask8 m, __m128i a);
VPCONFLICTD __m128i _mm_maskz_conflict_epi32(__mmask8 m, __m128i a);
VPCONFLICTQ __m128i _mm_conflict_epi64( __m128i a);
VPCONFLICTQ __m128i _mm_mask_conflict_epi64(__m128i s, __mmask8 m, __m128i a);
VPCONFLICTQ __m128i _mm_maskz_conflict_epi64(__mmask8 m, __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E4.
