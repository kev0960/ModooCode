----------------------------
title : PSUBUSB, PSUBUSWs (Intel x86/64 assembly instruction)
cat_title : PSUBUSB, PSUBUSW
ref_title : PSUBUSB, PSUBUSW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSUBUSB, PSUBUSW

**Subtract Packed Unsigned Integers with Unsigned Saturation**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F D8 /r\footnote{1}\newline{}\newline{}PSUBUSB mm, mm/m64|RM|V/V|MMX|Subtract unsigned packed bytes in mm/m64 from unsigned packed bytes in mm and saturate result.|
|66 0F D8 /r\newline{}\newline{}PSUBUSB xmm1, xmm2/m128|RM|V/V|SSE2|Subtract packed unsigned byte integers in xmm2/m128 from packed unsigned byte integers in xmm1 and saturate result.|
|0F D9 /r\footnote{1}\newline{}\newline{}PSUBUSW mm, mm/m64|RM|V/V|MMX|Subtract unsigned packed words in mm/m64 from unsigned packed words in mm and saturate result.|
|66 0F D9 /r\newline{}\newline{}PSUBUSW xmm1, xmm2/m128|RM|V/V|SSE2|Subtract packed unsigned word integers in xmm2/m128 from packed unsigned word integers in xmm1 and saturate result.|
|VEX.NDS.128.66.0F.WIG D8 /r\newline{}\newline{}VPSUBUSB xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Subtract packed unsigned byte integers in xmm3/m128 from packed unsigned byte integers in xmm2 and saturate result.|
|VEX.NDS.128.66.0F.WIG D9 /r\newline{}\newline{}VPSUBUSW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Subtract packed unsigned word integers in xmm3/m128 from packed unsigned word integers in xmm2 and saturate result.|
|VEX.NDS.256.66.0F.WIG D8 /r\newline{}\newline{}VPSUBUSB ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Subtract packed unsigned byte integers in ymm3/m256 from packed unsigned byte integers in ymm2 and saturate result.|
|VEX.NDS.256.66.0F.WIG D9 /r\newline{}\newline{}VPSUBUSW ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Subtract packed unsigned word integers in ymm3/m256 from packed unsigned word integers in ymm2 and saturate result.|
|EVEX.NDS.128.66.0F.WIG D8 /r\newline{}VPSUBUSB xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed unsigned byte integers in xmm3/m128 from packed unsigned byte integers in xmm2, saturate results and store in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F.WIG D8 /r\newline{}VPSUBUSB ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed unsigned byte integers in ymm3/m256 from packed unsigned byte integers in ymm2, saturate results and store in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F.WIG D8 /r\newline{}VPSUBUSB zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Subtract packed unsigned byte integers in zmm3/m512 from packed unsigned byte integers in zmm2, saturate results and store in zmm1 using writemask k1.|
|EVEX.NDS.128.66.0F.WIG D9 /r\newline{}VPSUBUSW xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed unsigned word integers in xmm3/m128 from packed unsigned word integers in xmm2 and saturate results and store in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F.WIG D9 /r\newline{}VPSUBUSW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed unsigned word integers in ymm3/m256 from packed unsigned word integers in ymm2, saturate results and store in ymm1 using writemask k1.|


|EVEX.NDS.512.66.0F.WIG D9 /r\newline{}VPSUBUSW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Subtract packed unsigned word integers in \newline{}zmm3/m512 from packed unsigned word \newline{}integers in zmm2, saturate results and store \newline{}in zmm1 using writemask k1.|
|----------------------------------------------------------------------------|---|---|--------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD subtract of the packed unsigned integers of the source operand (second operand) from the packed unsigned integers of the destination operand (first operand), and stores the packed unsigned integer results in the destination operand. See Figure 9-4 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for an illustration of a SIMD operation. Overflow is handled with unsigned saturation, as described in the following paragraphs.

These instructions can operate on either 64-bit or 128-bit operands.

The (V)PSUBUSB instruction subtracts packed unsigned byte integers. When an individual byte result is less than zero, the saturated value of 00H is written to the destination operand.

The (V)PSUBUSW instruction subtracts packed unsigned word integers. When an individual word result is less than zero, the saturated value of 0000H is written to the destination operand.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version 64-bit operand: The destination operand must be an MMX technology register and the source operand can be either an MMX technology register or a 64-bit memory location. 

128-bit Legacy SSE version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM desti-nation register remain unchanged.

VEX.128 encoded version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded versions: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed.

EVEX encoded version: The second source operand is an ZMM/YMM/XMM register or an 512/256/128-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is condi-tionally updated with writemask k1.


### Operation
#### PSUBUSB (with 64-bit operands)
```info-verb
    DEST[7:0] <- SaturateToUnsignedByte (DEST[7:0] - SRC (7:0] );
    (* Repeat add operation for 2nd through 7th bytes *)
    DEST[63:56] <- SaturateToUnsignedByte (DEST[63:56] - SRC[63:56]; 
```
#### PSUBUSW (with 64-bit operands)
```info-verb
    DEST[15:0] <- SaturateToUnsignedWord (DEST[15:0] - SRC[15:0] );
    (* Repeat add operation for 2nd and 3rd words *)
    DEST[63:48] <- SaturateToUnsignedWord (DEST[63:48] - SRC[63:48] );
```
#### VPSUBUSB (EVEX encoded versions) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8;
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SaturateToUnsignedByte (SRC1[i+7:i] - SRC2[i+7:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i] <-  0;
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0;
```
#### VPSUBUSW (EVEX encoded versions) 
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16;
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SaturateToUnsignedWord (SRC1[i+15:i] - SRC2[i+15:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] <-  0;
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0;
```
#### VPSUBUSB (VEX.256 encoded version)
```info-verb
DEST[7:0] <-  SaturateToUnsignedByte (SRC1[7:0] - SRC2[7:0]);
(* Repeat subtract operation for 2nd through 31st bytes *)
DEST[255:148] <-  SaturateToUnsignedByte (SRC1[255:248] - SRC2[255:248]);
DEST[MAX_VL-1:256] <-  0;
```
#### VPSUBUSB (VEX.128 encoded version)
```info-verb
DEST[7:0] <-  SaturateToUnsignedByte (SRC1[7:0] - SRC2[7:0]);
(* Repeat subtract operation for 2nd through 14th bytes *)
DEST[127:120] <-  SaturateToUnsignedByte (SRC1[127:120] - SRC2[127:120]);
DEST[MAX_VL-1:128] <-  0
```
#### PSUBUSB (128-bit Legacy SSE Version)
```info-verb
DEST[7:0] <-  SaturateToUnsignedByte (DEST[7:0] - SRC[7:0]);
(* Repeat subtract operation for 2nd through 14th bytes *)
DEST[127:120] <-  SaturateToUnsignedByte (DEST[127:120] - SRC[127:120]);
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSUBUSW (VEX.256 encoded version)
```info-verb
DEST[15:0] <-  SaturateToUnsignedWord (SRC1[15:0] - SRC2[15:0]);
(* Repeat subtract operation for 2nd through 15th words *)
DEST[255:240] <-  SaturateToUnsignedWord (SRC1[255:240] - SRC2[255:240]);
DEST[MAX_VL-1:256] <-  0;
```
#### VPSUBUSW (VEX.128 encoded version)
```info-verb
DEST[15:0] <-  SaturateToUnsignedWord (SRC1[15:0] - SRC2[15:0]);
(* Repeat subtract operation for 2nd through 7th words *)
DEST[127:112] <-  SaturateToUnsignedWord (SRC1[127:112] - SRC2[127:112]);
DEST[MAX_VL-1:128] <-  0
```
#### PSUBUSW (128-bit Legacy SSE Version)
```info-verb
DEST[15:0] <-  SaturateToUnsignedWord (DEST[15:0] - SRC[15:0]);
(* Repeat subtract operation for 2nd through 7th words *)
DEST[127:112] <-  SaturateToUnsignedWord (DEST[127:112] - SRC[127:112]);
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPSUBUSB __m512i _mm512_subs_epu8(__m512i a, __m512i b);
VPSUBUSB __m512i _mm512_mask_subs_epu8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPSUBUSB __m512i _mm512_maskz_subs_epu8( __mmask64 k, __m512i a, __m512i b);
VPSUBUSB __m256i _mm256_mask_subs_epu8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPSUBUSB __m256i _mm256_maskz_subs_epu8( __mmask32 k, __m256i a, __m256i b);
VPSUBUSB __m128i _mm_mask_subs_epu8(__m128i s, __mmask16 k, __m128i a, __m128i b);
VPSUBUSB __m128i _mm_maskz_subs_epu8( __mmask16 k, __m128i a, __m128i b);
VPSUBUSW __m512i _mm512_subs_epu16(__m512i a, __m512i b);
VPSUBUSW __m512i _mm512_mask_subs_epu16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPSUBUSW __m512i _mm512_maskz_subs_epu16( __mmask32 k, __m512i a, __m512i b);
VPSUBUSW __m256i _mm256_mask_subs_epu16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPSUBUSW __m256i _mm256_maskz_subs_epu16( __mmask16 k, __m256i a, __m256i b);
VPSUBUSW __m128i _mm_mask_subs_epu16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPSUBUSW __m128i _mm_maskz_subs_epu16( __mmask8 k, __m128i a, __m128i b);
PSUBUSB:__m64 _mm_subs_pu8(__m64 m1, __m64 m2)
(V)PSUBUSB:__m128i _mm_subs_epu8(__m128i m1, __m128i m2)
VPSUBUSB:__m256i _mm256_subs_epu8(__m256i m1, __m256i m2)
PSUBUSW:__m64 _mm_subs_pu16(__m64 m1, __m64 m2)
(V)PSUBUSW:__m128i _mm_subs_epu16(__m128i m1, __m128i m2)
VPSUBUSW:__m256i _mm256_subs_epu16(__m256i m1, __m256i m2)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.
