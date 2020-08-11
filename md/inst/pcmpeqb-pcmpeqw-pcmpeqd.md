----------------------------
title : PCMPEQB, PCMPEQW, PCMPEQD instructions(Intel x86/64 assembly instruction)
cat_title : PCMPEQB, PCMPEQW, PCMPEQD
----------------------------
### PCMPEQB/PCMPEQW/PCMPEQD-- Compare Packed Data for Equal


|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 74 /r\footnote{1}\newline{}PCMPEQB mm, mm/m64|RM|V/V|MMX|Compare packed bytes in mm/m64 and mm for equality.|
|66 0F 74 /r\newline{}PCMPEQB xmm1, xmm2/m128|RM|V/V|SSE2|Compare packed bytes in xmm2/m128 and xmm1 for equality.|
|0F 75 /r\footnote{1}\newline{}PCMPEQW mm, mm/m64|RM|V/V|MMX|Compare packed words in mm/m64 and mm for equality.|
|66 0F 75 /r\newline{}PCMPEQW xmm1, xmm2/m128|RM|V/V|SSE2|Compare packed words in xmm2/m128 and xmm1 for equality.|
|0F 76 /r\footnote{1}\newline{}PCMPEQD mm, mm/m64|RM|V/V|MMX|Compare packed doublewords in mm/m64 and mm for equality.|
|66 0F 76 /r\newline{}PCMPEQD xmm1, xmm2/m128|RM|V/V|SSE2|Compare packed doublewords in xmm2/m128 and xmm1 for equality.|
|VEX.NDS.128.66.0F.WIG 74 /r\newline{}VPCMPEQB xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed bytes in xmm3/m128 and xmm2 for equality.|
|VEX.NDS.128.66.0F.WIG 75 /r\newline{}VPCMPEQW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed words in xmm3/m128 and xmm2 for equality.|
|VEX.NDS.128.66.0F.WIG 76 /r\newline{}VPCMPEQD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Compare packed doublewords in xmm3/m128 and xmm2 for equality.|
|VEX.NDS.256.66.0F.WIG 74 /rVPCMPEQB ymm1, ymm2, ymm3 /m256|RVM|V/V|AVX2|Compare packed bytes in ymm3/m256 and ymm2 for equality.|
|VEX.NDS.256.66.0F.WIG 75 /r\newline{}VPCMPEQW ymm1, ymm2, ymm3 /m256|RVM|V/V|AVX2|Compare packed words in ymm3/m256 and ymm2 for equality.|
|VEX.NDS.256.66.0F.WIG 76 /r\newline{}VPCMPEQD ymm1, ymm2, ymm3 /m256|RVM|V/V|AVX2|Compare packed doublewords in ymm3/m256 and ymm2 for equality.|
|EVEX.NDS.128.66.0F.W0 76 /rVPCMPEQD k1 {k2}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VLAVX512F|Compare Equal between int32 vector xmm2 and int32 vector xmm3/m128/m32bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.256.66.0F.W0 76 /rVPCMPEQD k1 {k2}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VLAVX512F|Compare Equal between int32 vector ymm2 and int32 vector ymm3/m256/m32bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.512.66.0F.W0 76 /rVPCMPEQD k1 {k2}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Compare Equal between int32 vectors in zmm2 and zmm3/m512/m32bcst, and set destination k1 according to the comparison results under writemask k2.|
|EVEX.NDS.128.66.0F.WIG 74 /rVPCMPEQB k1 {k2}, xmm2, xmm3 /m128|FVM|V/V|AVX512VLAVX512BW|Compare packed bytes in xmm3/m128 and xmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|


|EVEX.NDS.256.66.0F.WIG 74 /r\newline{}VPCMPEQB k1 {k2}, ymm2, ymm3 /m256|FVM|V/V|AVX512V\newline{}L\newline{}AVX512B\newline{}W|Compare packed bytes in ymm3/m256 and \newline{}ymm2 for equality and set vector mask k1 to \newline{}reflect the zero/nonzero status of each \newline{}element of the result, under writemask.|
|------------------------------------------------------------------------|---|---|----------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|EVEX.NDS.512.66.0F.WIG 74 /rVPCMPEQB k1 {k2}, zmm2, zmm3 /m512|FVM|V/V|AVX512BW|Compare packed bytes in zmm3/m512 and zmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.128.66.0F.WIG 75 /rVPCMPEQW k1 {k2}, xmm2, xmm3 /m128|FVM|V/V|AVX512VLAVX512BW|Compare packed words in xmm3/m128 and xmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.256.66.0F.WIG 75 /rVPCMPEQW k1 {k2}, ymm2, ymm3 /m256|FVM|V/V|AVX512VLAVX512BW|Compare packed words in ymm3/m256 and ymm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.512.66.0F.WIG 75 /rVPCMPEQW k1 {k2}, zmm2, zmm3 /m512|FVM|V/V|AVX512BW|Compare packed words in zmm3/m512 and zmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
### NOTES:


1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD compare for equality of the packed bytes, words, or doublewords in the destination operand (first operand) and the source operand (second operand). If a pair of data elements is equal, the corresponding data element in the destination operand is set to all 1s; otherwise, it is set to all 0s. 

The (V)PCMPEQB instruction compares the corresponding bytes in the destination and source operands; the (V)PCMPEQW instruction compares the corresponding words in the destination and source operands; and the (V)PCMPEQD instruction compares the corresponding doublewords in the destination and source operands.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE instructions: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand can be an MMX technology register.

128-bit Legacy SSE version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.



VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register.

EVEX encoded VPCMPEQD: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand (first operand) is a mask register updated according to the writemask k2.

EVEX encoded VPCMPEQB/W: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand (first operand) is a mask register updated according to the writemask k2.


### Operation
#### PCMPEQB (with 64-bit operands)
```info-verb
 IF DEST[7:0] = SRC[7:0]
   THEN DEST[7:0) <- FFH; 
   ELSE DEST[7:0] <- 0; FI;
 (\htmlonly{*} Continue comparison of 2nd through 7th bytes in DEST and SRC \htmlonly{*})
 IF DEST[63:56] = SRC[63:56]
   THEN DEST[63:56] <- FFH;
   ELSE DEST[63:56] <- 0; FI;
```
#### COMPARE_BYTES_EQUAL (SRC1, SRC2)
```info-verb
 IF SRC1[7:0] = SRC2[7:0]
 THEN DEST[7:0] <- FFH;
 ELSE DEST[7:0] <- 0; FI;
(\htmlonly{*} Continue comparison of 2nd through 15th bytes in SRC1 and SRC2 \htmlonly{*})
 IF SRC1[127:120] = SRC2[127:120]
 THEN DEST[127:120]  <-FFH;
 ELSE DEST[127:120]  <-0; FI;
```
#### COMPARE_WORDS_EQUAL (SRC1, SRC2)
```info-verb
 IF SRC1[15:0] = SRC2[15:0]
 THEN DEST[15:0] <- FFFFH;
 ELSE DEST[15:0]  <-0; FI;
(\htmlonly{*} Continue comparison of 2nd through 7th 16-bit words in SRC1 and SRC2 \htmlonly{*})
 IF SRC1[127:112] = SRC2[127:112]
 THEN DEST[127:112]  <-FFFFH;
 ELSE DEST[127:112]  <-0; FI;
```
#### COMPARE_DWORDS_EQUAL (SRC1, SRC2)
```info-verb
 IF SRC1[31:0] = SRC2[31:0]
 THEN DEST[31:0] <- FFFFFFFFH;
 ELSE DEST[31:0] <- 0; FI;
(\htmlonly{*} Continue comparison of 2nd through 3rd 32-bit dwords in SRC1 and SRC2 \htmlonly{*})
 IF SRC1[127:96] = SRC2[127:96]
 THEN DEST[127:96] <- FFFFFFFFH;
 ELSE DEST[127:96] <- 0; FI;
```
#### PCMPEQB (with 128-bit operands)
```info-verb
DEST[127:0]  <-COMPARE_BYTES_EQUAL(DEST[127:0],SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPCMPEQB (VEX.128 encoded version)
```info-verb
DEST[127:0] <- COMPARE_BYTES_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[VLMAX-1:128]  <- 0
```
#### VPCMPEQB (VEX.256 encoded version)
```info-verb
DEST[127:0]  <-COMPARE_BYTES_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[255:128]  <-COMPARE_BYTES_EQUAL(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256]  <- 0
```
#### VPCMPEQB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j  <- 0 TO KL-1
 i <-  j * 8
 IF k2[j] OR *no writemask*
   THEN 
    /* signed comparison */
    CMP  <- SRC1[i+7:i] == SRC2[i+7:i];
    IF CMP = TRUE
      THEN DEST[j] <-  1;
      ELSE DEST[j] <-  0; FI;
   ELSE  DEST[j]  <- 0 ; zeroing-masking onlyFI;
 FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### PCMPEQW (with 64-bit operands)
```info-verb
 IF DEST[15:0] = SRC[15:0] THEN DEST[15:0] <- FFFFH;
   ELSE DEST[15:0] <- 0; FI;
 (* Continue comparison of 2nd and 3rd words in DEST and SRC *)
 IF DEST[63:48] = SRC[63:48]
   THEN DEST[63:48] <- FFFFH;
   ELSE DEST[63:48] <- 0; FI;
```
#### PCMPEQW (with 128-bit operands)
```info-verb
DEST[127:0]  <-COMPARE_WORDS_EQUAL(DEST[127:0],SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPCMPEQW (VEX.128 encoded version)
```info-verb
DEST[127:0]  <-COMPARE_WORDS_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[VLMAX-1:128] <-  0
```
#### VPCMPEQW (VEX.256 encoded version)
```info-verb
DEST[127:0]  <-COMPARE_WORDS_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_WORDS_EQUAL(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256] <-  0
```
#### VPCMPEQW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
 i  <- j * 16
 IF k2[j] OR *no writemask*
   THEN 
    /* signed comparison */
    CMP <-  SRC1[i+15:i] == SRC2[i+15:i];
    IF CMP = TRUE
THEN DEST[j]  <- 1;
      ELSE DEST[j]  <- 0; FI;
   ELSE  DEST[j] <-  0 ; zeroing-masking onlyFI;
 FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### PCMPEQD (with 64-bit operands)
```info-verb
 IF DEST[31:0] = SRC[31:0]
   THEN DEST[31:0] <- FFFFFFFFH; 
   ELSE DEST[31:0] <- 0; FI;
 IF DEST[63:32] = SRC[63:32]
   THEN DEST[63:32] <- FFFFFFFFH;
   ELSE DEST[63:32] <- 0; FI;
```
#### PCMPEQD (with 128-bit operands)
```info-verb
DEST[127:0]  <-COMPARE_DWORDS_EQUAL(DEST[127:0],SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPCMPEQD (VEX.128 encoded version)
```info-verb
DEST[127:0]  <-COMPARE_DWORDS_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[VLMAX-1:128]  <- 0
```
#### VPCMPEQD (VEX.256 encoded version)
```info-verb
DEST[127:0] <- COMPARE_DWORDS_EQUAL(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_DWORDS_EQUAL(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256]  <- 0
```
#### VPCMPEQD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
 i <-  j * 32
 IF k2[j] OR *no writemask*
   THEN 
    /* signed comparison */
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
      THEN CMP  <- SRC1[i+31:i] = SRC2[31:0];
      ELSE CMP  <- SRC1[i+31:i] = SRC2[i+31:i];
    FI;
    IF CMP = TRUE
      THEN DEST[j]  <- 1;
      ELSE DEST[j] <-  0; FI;
   ELSE  DEST[j]  <- 0 ; zeroing-masking only
 FI;
ENDFOR
DEST[MAX_KL-1:KL]  <- 0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPCMPEQB __mmask64 _mm512_cmpeq_epi8_mask(__m512i a, __m512i b);
VPCMPEQB __mmask64 _mm512_mask_cmpeq_epi8_mask(__mmask64 k, __m512i a, __m512i b);
VPCMPEQB __mmask32 _mm256_cmpeq_epi8_mask(__m256i a, __m256i b);
VPCMPEQB __mmask32 _mm256_mask_cmpeq_epi8_mask(__mmask32 k, __m256i a, __m256i b);
VPCMPEQB __mmask16 _mm_cmpeq_epi8_mask(__m128i a, __m128i b);
VPCMPEQB __mmask16 _mm_mask_cmpeq_epi8_mask(__mmask16 k, __m128i a, __m128i b);
VPCMPEQW __mmask32 _mm512_cmpeq_epi16_mask(__m512i a, __m512i b);
VPCMPEQW __mmask32 _mm512_mask_cmpeq_epi16_mask(__mmask32 k, __m512i a, __m512i b);
VPCMPEQW __mmask16 _mm256_cmpeq_epi16_mask(__m256i a, __m256i b);
VPCMPEQW __mmask16 _mm256_mask_cmpeq_epi16_mask(__mmask16 k, __m256i a, __m256i b);
VPCMPEQW __mmask8 _mm_cmpeq_epi16_mask(__m128i a, __m128i b);
VPCMPEQW __mmask8 _mm_mask_cmpeq_epi16_mask(__mmask8 k, __m128i a, __m128i b);
VPCMPEQD __mmask16 _mm512_cmpeq_epi32_mask( __m512i a, __m512i b);
VPCMPEQD __mmask16 _mm512_mask_cmpeq_epi32_mask(__mmask16 k, __m512i a, __m512i b);
VPCMPEQD __mmask8 _mm256_cmpeq_epi32_mask(__m256i a, __m256i b);
VPCMPEQD __mmask8 _mm256_mask_cmpeq_epi32_mask(__mmask8 k, __m256i a, __m256i b);
VPCMPEQD __mmask8 _mm_cmpeq_epi32_mask(__m128i a, __m128i b);
VPCMPEQD __mmask8 _mm_mask_cmpeq_epi32_mask(__mmask8 k, __m128i a, __m128i b);
PCMPEQB: __m64 _mm_cmpeq_pi8 (__m64 m1, __m64 m2)
PCMPEQW: __m64 _mm_cmpeq_pi16 (__m64 m1, __m64 m2)
PCMPEQD: __m64 _mm_cmpeq_pi32 (__m64 m1, __m64 m2)
(V)PCMPEQB: __m128i _mm_cmpeq_epi8 ( __m128i a, __m128i b)
(V)PCMPEQW: __m128i _mm_cmpeq_epi16 ( __m128i a, __m128i b)
(V)PCMPEQD: __m128i _mm_cmpeq_epi32 ( __m128i a, __m128i b)
VPCMPEQB: __m256i _mm256_cmpeq_epi8 ( __m256i a, __m256i b)
VPCMPEQW: __m256i _mm256_cmpeq_epi16 ( __m256i a, __m256i b)
VPCMPEQD: __m256i _mm256_cmpeq_epi32 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPCMPEQD, see Exceptions Type E4.

EVEX-encoded VPCMPEQB/W, see Exceptions Type E4.nb.

