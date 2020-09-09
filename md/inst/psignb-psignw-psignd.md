----------------------------
title : PSIGNB, PSIGNW, PSIGNDs (Intel x86/64 assembly instruction)
cat_title : PSIGNB, PSIGNW, PSIGND
ref_title : PSIGNB, PSIGNW, PSIGND
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSIGNB, PSIGNW, PSIGND

** Packed SIGN **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|
|------------------------|------------------------------------------------------|--------------------------------------------------|
|RM|V/V|SSSE3|
|RM|V/V|SSSE3|
|RM|V/V|SSSE3|
|RM|V/V|SSSE3|
|RM|V/V|SSSE3|
|RM|V/V|SSSE3|
|RVM|V/V|AVX|
|RVM|V/V|AVX|
|RVM|V/V|AVX|
|RVM|V/V|AVX2|
|RVM|V/V|AVX2|
|RVM|V/V|AVX2|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


(V)PSIGNB/(V)PSIGNW/(V)PSIGND negates each data element of the destination operand (the first operand) if the signed integer value of the corresponding data element in the source operand (the second operand) is less than zero. If the signed integer value of a data element in the source operand is positive, the corresponding data element in the destination operand is unchanged. If a data element in the source operand is zero, the corre-sponding data element in the destination operand is set to zero.

(V)PSIGNB operates on signed bytes. (V)PSIGNW operates on 16-bit signed words. (V)PSIGND operates on signed 32-bit integers. When the source operand is a 128bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

Legacy SSE instructions: Both operands can be MMX registers. In 64-bit mode, use the REX prefix to access addi-tional registers. 

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.L must be 0, otherwise instructions will #UD.

VEX.256 encoded version: The first source and destination operands are YMM registers. The second source operand is an YMM register or a 256-bit memory location.

### Operation 


**PSIGNB (with 64 bit operands)**

    IF (SRC[7:0] < 0 ) 

          DEST[7:0] <- Neg(DEST[7:0]) 

    ELSEIF (SRC[7:0] = 0 ) 

          DEST[7:0] <- 0 

    ELSEIF (SRC[7:0] > 0 ) 

          DEST[7:0] <- DEST[7:0] 

    Repeat operation for 2nd through 7th bytes 

    IF (SRC[63:56] < 0 )

          DEST[63:56] <- Neg(DEST[63:56]) 

    ELSEIF (SRC[63:56] = 0 ) 

          DEST[63:56] <- 0 

    ELSEIF (SRC[63:56] > 0 ) 

          DEST[63:56] <- DEST[63:56] 

**PSIGNB (with 128 bit operands)**

    IF (SRC[7:0] < 0 ) 

          DEST[7:0] <- Neg(DEST[7:0]) 

    ELSEIF (SRC[7:0] = 0 )

          DEST[7:0] <- 0 

    ELSEIF (SRC[7:0] > 0 ) 

          DEST[7:0] <- DEST[7:0] 

    Repeat operation for 2nd through 15th bytes 

    IF (SRC[127:120] < 0 ) 

          DEST[127:120] <- Neg(DEST[127:120]) 

    ELSEIF (SRC[127:120] = 0 ) 

          DEST[127:120] <- 0 

    ELSEIF (SRC[127:120] > 0 ) 

          DEST[127:120] <- DEST[127:120] 



**VPSIGNB (VEX.128 encoded version)**

DEST[127:0] <- BYTE_SIGN(SRC1, SRC2)

DEST[VLMAX-1:128] <-  0

**VPSIGNB (VEX.256 encoded version)**

DEST[255:0] <- BYTE_SIGN_256b(SRC1, SRC2)

**PSIGNW (with 64 bit operands)**

    IF (SRC[15:0] < 0 ) 

          DEST[15:0] <- Neg(DEST[15:0]) 

    ELSEIF (SRC[15:0] = 0 ) 

          DEST[15:0] <- 0 

    ELSEIF (SRC[15:0] > 0 ) 

          DEST[15:0] <- DEST[15:0] 

Repeat operation for 2nd through 3rd words 

    IF (SRC[63:48] < 0 ) 

          DEST[63:48] <- Neg(DEST[63:48]) 

    ELSEIF (SRC[63:48] = 0 ) 

          DEST[63:48] <- 0 

    ELSEIF (SRC[63:48] > 0 ) 

          DEST[63:48] <- DEST[63:48] 

**PSIGNW (with 128 bit operands)**

    IF (SRC[15:0] < 0 ) 

          DEST[15:0] <- Neg(DEST[15:0])

    ELSEIF (SRC[15:0] = 0 ) 

          DEST[15:0] <- 0 

    ELSEIF (SRC[15:0] > 0 ) 

          DEST[15:0] <- DEST[15:0] 

    Repeat operation for 2nd through 7th words 

    IF (SRC[127:112] < 0 ) 

          DEST[127:112] <- Neg(DEST[127:112]) 

    ELSEIF (SRC[127:112] = 0 ) 

          DEST[127:112] <- 0 

    ELSEIF (SRC[127:112] > 0 ) 

          DEST[127:112] <- DEST[127:112] 

**VPSIGNW (VEX.128 encoded version)**

DEST[127:0] <- WORD_SIGN(SRC1, SRC2)

DEST[VLMAX-1:128] <-  0

**VPSIGNW (VEX.256 encoded version)**

DEST[255:0] <- WORD_SIGN(SRC1, SRC2)

**PSIGND (with 64 bit operands)**

    IF (SRC[31:0] < 0 ) 

          DEST[31:0] <- Neg(DEST[31:0]) 

    ELSEIF (SRC[31:0] = 0 ) 

          DEST[31:0] <- 0 

    ELSEIF (SRC[31:0] > 0 ) 

          DEST[31:0] <- DEST[31:0]

    IF (SRC[63:32] < 0 ) 

          DEST[63:32] <- Neg(DEST[63:32]) 

    ELSEIF (SRC[63:32] = 0 ) 

          DEST[63:32] <- 0 



ELSEIF (SRC[63:32] > 0 ) 

          DEST[63:32] <- DEST[63:32] 

**PSIGND (with 128 bit operands)**

    IF (SRC[31:0] < 0 ) 

          DEST[31:0] <- Neg(DEST[31:0]) 

    ELSEIF (SRC[31:0] = 0 ) 

          DEST[31:0] <- 0 

    ELSEIF (SRC[31:0] > 0 ) 

          DEST[31:0] <- DEST[31:0] 

    Repeat operation for 2nd through 3rd double words 

    IF (SRC[127:96] < 0 ) 

          DEST[127:96] <- Neg(DEST[127:96]) 

    ELSEIF (SRC[127:96] = 0 ) 

          DEST[127:96] <- 0 

    ELSEIF (SRC[127:96] > 0 ) 

          DEST[127:96] <- DEST[127:96] 

**VPSIGND (VEX.128 encoded version)**

DEST[127:0] <- DWORD_SIGN(SRC1, SRC2)

DEST[VLMAX-1:128] <-  0

**VPSIGND (VEX.256 encoded version)**

DEST[255:0] <- DWORD_SIGN(SRC1, SRC2)


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PSIGNB:  __m64 _mm_sign_pi8 (__m64 a, __m64 b)
(V)PSIGNB:  __m128i _mm_sign_epi8 (__m128i a, __m128i b)
VPSIGNB: __m256i _mm256_sign_epi8 (__m256i a, __m256i b)
PSIGNW:  __m64 _mm_sign_pi16 (__m64 a, __m64 b)
(V)PSIGNW:  __m128i _mm_sign_epi16 (__m128i a, __m128i b)
VPSIGNW: __m256i _mm256_sign_epi16 (__m256i a, __m256i b)
PSIGND:  __m64 _mm_sign_pi32 (__m64 a, __m64 b)
(V)PSIGND:  __m128i _mm_sign_epi32 (__m128i a, __m128i b)
VPSIGND: __m256i _mm256_sign_epi32 (__m256i a, __m256i b)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1.

