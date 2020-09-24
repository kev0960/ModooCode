----------------------------
title : VSHUFF32x4, VSHUFF64x2, VSHUFI32x4, VSHUFI64x2s (Intel x86/64 assembly instruction)
cat_title : VSHUFF32x4, VSHUFF64x2, VSHUFI32x4, VSHUFI64x2
ref_title : VSHUFF32x4, VSHUFF64x2, VSHUFI32x4, VSHUFI64x2
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VSHUFF32x4, VSHUFF64x2, VSHUFI32x4, VSHUFI64x2

**Shuffle Packed Values at 128-bit Granularity**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.NDS.256.66.0F3A.W0 23 /r ibVSHUFF32X4 ymm1{k1}{z}, ymm2, ymm3/m256/m32bcst, imm8`\newline{} |FV|V/V|AVX512VL\newline{}AVX512F|Shuffle 128-bit packed single-precision floating-point values selected by imm8 from ymm2 and ymm3/m256/m32bcst and place results in ymm1 subject to writemask k1.|
|`EVEX.NDS.512.66.0F3A.W0 23 /r ib`\newline{}`VSHUFF32x4` zmm1{k1}{z} zmm2 \tooltip{zmm3/m512/m32bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 32 비트 메모리 주소값에 불러온 벡터 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512F|Shuffle 128-bit packed single-precision floating-point values selected by imm8 from zmm2 and zmm3/m512/m32bcst and place results in zmm1 subject to writemask k1.|
|`EVEX.NDS.256.66.0F3A.W1 23 /r ibVSHUFF64X2 ymm1{k1}{z}, ymm2, ymm3/m256/m64bcst, imm8`\newline{} |FV|V/V|AVX512VL\newline{}AVX512F|Shuffle 128-bit packed double-precision floating-point values selected by imm8 from ymm2 and ymm3/m256/m64bcst and place results in ymm1 subject to writemask k1.|
|`EVEX.NDS.512.66.0F3A.W1 23 /r ib`\newline{}`VSHUFF64x2` zmm1{k1}{z} zmm2 \tooltip{zmm3/m512/m64bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 64 비트 메모리 주소값에 불러온 벡터 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512F|Shuffle 128-bit packed double-precision floating-point values selected by imm8 from zmm2 and zmm3/m512/m64bcst and place results in zmm1 subject to writemask k1.|
|`EVEX.NDS.256.66.0F3A.W0 43 /r ibVSHUFI32X4 ymm1{k1}{z}, ymm2, ymm3/m256/m32bcst, imm8`\newline{} |FV|V/V|AVX512VL\newline{}AVX512F|Shuffle 128-bit packed double-word values selected by imm8 from ymm2 and ymm3/m256/m32bcst and place results in ymm1 subject to writemask k1.|
|`EVEX.NDS.512.66.0F3A.W0 43 /r ib`\newline{}`VSHUFI32x4` zmm1{k1}{z} zmm2 \tooltip{zmm3/m512/m32bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 32 비트 메모리 주소값에 불러온 벡터 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512F|Shuffle 128-bit packed double-word values selected by imm8 from zmm2 and zmm3/m512/m32bcst and place results in zmm1 subject to writemask k1.|
|`EVEX.NDS.256.66.0F3A.W1 43 /r ibVSHUFI64X2 ymm1{k1}{z}, ymm2, ymm3/m256/m64bcst, imm8`\newline{} |FV|V/V|AVX512VL\newline{}AVX512F|Shuffle 128-bit packed quad-word values selected by imm8 from ymm2 and ymm3/m256/m64bcst and place results in ymm1 subject to writemask k1.|
|`EVEX.NDS.512.66.0F3A.W1 43 /r ib`\newline{}`VSHUFI64x2` zmm1{k1}{z} zmm2 \tooltip{zmm3/m512/m64bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 64 비트 메모리 주소값에 불러온 벡터 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512F|Shuffle 128-bit packed quad-word values selected by imm8 from zmm2 and zmm3/m512/m64bcst and place results in zmm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


256-bit Version: Moves one of the two 128-bit packed single-precision floating-point values from the first source operand (second operand) into the low 128-bit of the destination operand (first operand); moves one of the two packed 128-bit floating-point values from the second source operand (third operand) into the high 128-bit of the destination operand. The selector operand (third operand) determines which values are moved to the destination operand.

512-bit Version: Moves two of the four 128-bit packed single-precision floating-point values from the first source operand (second operand) into the low 256-bit of each double qword of the destination operand (first operand); moves two of the four packed 128-bit floating-point values from the second source operand (third operand) into the high 256-bit of the destination operand. The selector operand (third operand) determines which values are moved to the destination operand.

The first source operand is a vector register. The second source operand can be a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32/64-bit memory location. The destination operand is a vector register.

The writemask updates the destination operand with the granularity of 32/64-bit data elements.


### Operation
#### VSHUFF32x4 (EVEX versions)
```info-verb
(KL, VL) = (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+31:i] <-  SRC2[31:0]
          ELSE TMP_SRC2[i+31:i] <-  SRC2[i+31:i]
    FI;
ENDFOR;
IF VL = 256
    TMP_DEST[127:0] <-  Select2(SRC1[255:0], imm8[0]);
    TMP_DEST[255:128] <-  Select2(SRC2[255:0], imm8[1]);
FI;
IF VL = 512
    TMP_DEST[127:0] <-  Select4(SRC1[511:0], imm8[1:0]);
    TMP_DEST[255:128] <-  Select4(SRC1[511:0], imm8[3:2]);
    TMP_DEST[383:256] <-  Select4(TMP_SRC2[511:0], imm8[5:4]);
    TMP_DEST[511:384] <-  Select4(TMP_SRC2[511:0], imm8[7:6]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            THEN DEST[i+31:i] <-  0
                FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSHUFF64x2 (EVEX 512-bit version)
```info-verb
(KL, VL) = (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+63:i] <-  SRC2[63:0]
          ELSE TMP_SRC2[i+63:i] <-  SRC2[i+63:i]
    FI;
ENDFOR;
IF VL = 256
    TMP_DEST[127:0] <-  Select2(SRC1[255:0], imm8[0]);
    TMP_DEST[255:128] <-  Select2(SRC2[255:0], imm8[1]);
FI;
IF VL = 512
    TMP_DEST[127:0] <-  Select4(SRC1[511:0], imm8[1:0]);
    TMP_DEST[255:128] <-  Select4(SRC1[511:0], imm8[3:2]);
    TMP_DEST[383:256] <-  Select4(TMP_SRC2[511:0], imm8[5:4]);
    TMP_DEST[511:384] <-  Select4(TMP_SRC2[511:0], imm8[7:6]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            THEN DEST[i+63:i] <-!= 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSHUFI32x4 (EVEX 512-bit version)
```info-verb
(KL, VL) = (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+31:i] <-  SRC2[31:0]
          ELSE TMP_SRC2[i+31:i] <-  SRC2[i+31:i]
    FI;
ENDFOR;
IF VL = 256
    TMP_DEST[127:0] <-  Select2(SRC1[255:0], imm8[0]);
    TMP_DEST[255:128] <-  Select2(SRC2[255:0], imm8[1]);
FI;
IF VL = 512
    TMP_DEST[127:0] <-  Select4(SRC1[511:0], imm8[1:0]);
    TMP_DEST[255:128] <-  Select4(SRC1[511:0], imm8[3:2]);
    TMP_DEST[383:256] <-  Select4(TMP_SRC2[511:0], imm8[5:4]);
    TMP_DEST[511:384] <-  Select4(TMP_SRC2[511:0], imm8[7:6]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            THEN DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSHUFI64x2 (EVEX 512-bit version)
```info-verb
(KL, VL) = (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+63:i] <-  SRC2[63:0]
          ELSE TMP_SRC2[i+63:i] <-  SRC2[i+63:i]
    FI;
ENDFOR;
IF VL = 256
    TMP_DEST[127:0] <-  Select2(SRC1[255:0], imm8[0]);
    TMP_DEST[255:128] <-  Select2(SRC2[255:0], imm8[1]);
FI;
IF VL = 512
    TMP_DEST[127:0] <-  Select4(SRC1[511:0], imm8[1:0]);
    TMP_DEST[255:128] <-  Select4(SRC1[511:0], imm8[3:2]);
    TMP_DEST[383:256] <-  Select4(TMP_SRC2[511:0], imm8[5:4]);
    TMP_DEST[511:384] <-  Select4(TMP_SRC2[511:0], imm8[7:6]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            THEN DEST[i+63:i] <-!= 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSHUFI32x4 __m512i _mm512_shuffle_i32x4(__m512i a, __m512i b, int imm);
VSHUFI32x4 __m512i _mm512_mask_shuffle_i32x4(__m512i s, __mmask16 k, __m512i a, __m512i b, int imm);
VSHUFI32x4 __m512i _mm512_maskz_shuffle_i32x4( __mmask16 k, __m512i a, __m512i b, int imm);
VSHUFI32x4 __m256i _mm256_shuffle_i32x4(__m256i a, __m256i b, int imm);
VSHUFI32x4 __m256i _mm256_mask_shuffle_i32x4(__m256i s, __mmask8 k, __m256i a, __m256i b, int imm);
VSHUFI32x4 __m256i _mm256_maskz_shuffle_i32x4( __mmask8 k, __m256i a, __m256i b, int imm);
VSHUFF32x4 __m512 _mm512_shuffle_f32x4(__m512 a, __m512 b, int imm);
VSHUFF32x4 __m512 _mm512_mask_shuffle_f32x4(__m512 s, __mmask16 k, __m512 a, __m512 b, int imm);
VSHUFF32x4 __m512 _mm512_maskz_shuffle_f32x4( __mmask16 k, __m512 a, __m512 b, int imm);
VSHUFI64x2 __m512i _mm512_shuffle_i64x2(__m512i a, __m512i b, int imm);
VSHUFI64x2 __m512i _mm512_mask_shuffle_i64x2(__m512i s, __mmask8 k, __m512i b, __m512i b, int imm);
VSHUFI64x2 __m512i _mm512_maskz_shuffle_i64x2( __mmask8 k, __m512i a, __m512i b, int imm);
VSHUFF64x2 __m512d _mm512_shuffle_f64x2(__m512d a, __m512d b, int imm);
VSHUFF64x2 __m512d _mm512_mask_shuffle_f64x2(__m512d s, __mmask8 k, __m512d a, __m512d b, int imm);
VSHUFF64x2 __m512d _mm512_maskz_shuffle_f64x2( __mmask8 k, __m512d a, __m512d b, int imm);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4NF.

#UD If EVEX.L'L = 0 for VSHUFF32x4/VSHUFF64x2.

