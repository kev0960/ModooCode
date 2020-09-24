----------------------------
title : VINSERTI128, VINSERTI32x4, VINSERTI64x2, VINSERTI32x8, VINSERTI64x4s (Intel x86/64 assembly instruction)
cat_title : VINSERTI128, VINSERTI32x4, VINSERTI64x2, VINSERTI32x8, VINSERTI64x4
ref_title : VINSERTI128, VINSERTI32x4, VINSERTI64x2, VINSERTI32x8, VINSERTI64x4
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VINSERTI128, VINSERTI32x4, VINSERTI64x2, VINSERTI32x8, VINSERTI64x4

**Insert Packed Integer Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.256.66.0F3A.W0 38 /r ib`\newline{}`VINSERTI128` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX2|Insert 128 bits of integer data from xmm3/m128 and the remaining values from ymm2 into ymm1.|
|`EVEX.NDS.256.66.0F3A.W0 38 /r ibVINSERTI32X4 ymm1 {k1}{z}, ymm2, xmm3/m128, imm8`\newline{} |T4|V/V|AVX512VL\newline{}AVX512F|Insert 128 bits of packed doubleword integer values from xmm3/m128 and the remaining values from ymm2 into ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F3A.W0 38 /r ibVINSERTI32X4 zmm1 {k1}{z}, zmm2, xmm3/m128, imm8`\newline{} |T4|V/V|AVX512F|Insert 128 bits of packed doubleword integer values from xmm3/m128 and the remaining values from zmm2 into zmm1 under writemask k1.|
|`EVEX.NDS.256.66.0F3A.W1 38 /r ibVINSERTI64X2 ymm1 {k1}{z}, ymm2, xmm3/m128, imm8`\newline{} |T2|V/V|AVX512VL\newline{}AVX512DQ|Insert 128 bits of packed quadword integer values from xmm3/m128 and the remaining values from ymm2 into ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F3A.W1 38 /r ibVINSERTI64X2 zmm1 {k1}{z}, zmm2, xmm3/m128, imm8`\newline{} |T2|V/V|AVX512DQ|Insert 128 bits of packed quadword integer values from xmm3/m128 and the remaining values from zmm2 into zmm1 under writemask k1.|
|`EVEX.NDS.512.66.0F3A.W0 3A /r ibVINSERTI32X8 zmm1 {k1}{z}, zmm2, ymm3/m256, imm8`\newline{} |T8|V/V|AVX512DQ|Insert 256 bits of packed doubleword integer values from ymm3/m256 and the remaining values from zmm2 into zmm1 under writemask k1.|
|`EVEX.NDS.512.66.0F3A.W1 3A /r ibVINSERTI64X4 zmm1 {k1}{z}, zmm2, ymm3/m256, imm8`\newline{} |T4|V/V|AVX512F|Insert 256 bits of packed quadword integer values from ymm3/m256 and the remaining values from zmm2 into zmm1 under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
|T2, T4, T8|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


VINSERTI32x4 and `VINSERTI64x2` inserts 128-bits of packed integer values from the second source operand (the third operand) into the destination operand (the first operand) at an 128-bit granular offset multiplied by imm8[0] (256-bit) or imm8[1:0]. The remaining portions of the destination are copied from the corresponding fields of the first source operand (the second operand). The second source operand can be either an XMM register or a 128-bit memory location. The high 6/7bits of the immediate are ignored. The destination operand is a ZMM/YMM register and updated at 32 and 64-bit granularity according to the writemask.

VINSERTI32x8 and `VINSERTI64x4` inserts 256-bits of packed integer values from the second source operand (the third operand) into the destination operand (the first operand) at a 256-bit granular offset multiplied by imm8[0]. The remaining portions of the destination are copied from the corresponding fields of the first source operand (the second operand). The second source operand can be either an YMM register or a 256-bit memory location. The upper bits of the immediate are ignored. The destination operand is a ZMM register and updated at 32 and 64-bit granularity according to the writemask.

VINSERTI128 inserts 128-bits of packed integer data from the second source operand (the third operand) into the destination operand (the first operand) at a 128-bit granular offset multiplied by imm8[0]. The remaining portions of the destination are copied from the corresponding fields of the first source operand (the second operand). The second source operand can be either an XMM register or a 128-bit memory location. The high 7 bits of the imme-diate are ignored. VEX.L must be 1, otherwise attempt to execute this instruction with VEX.L=0 will cause #UD.


### Operation
#### VINSERTI32x4 (EVEX encoded versions) 
```info-verb
(KL, VL) = (8, 256), (16, 512)
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
IF VL = 256
    CASE (imm8[0]) OF
          0:  TMP_DEST[127:0] <-  SRC2[127:0]
          1:  TMP_DEST[255:128] <-  SRC2[127:0]
    ESAC.
FI;
IF VL = 512
    CASE (imm8[1:0]) OF
          00:  TMP_DEST[127:0] <-  SRC2[127:0]
          01:  TMP_DEST[255:128] <-  SRC2[127:0]
          10:  TMP_DEST[383:256] <-  SRC2[127:0]
          11:  TMP_DEST[511:384] <-  SRC2[127:0]
    ESAC.
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTI64x2 (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 256), (8, 512)
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
IF VL = 256
    CASE (imm8[0]) OF
          0:  TMP_DEST[127:0] <-  SRC2[127:0]
          1:  TMP_DEST[255:128] <-  SRC2[127:0]
    ESAC.
FI;
IF VL = 512
    CASE (imm8[1:0]) OF
          00:  TMP_DEST[127:0] <-  SRC2[127:0]
          01:  TMP_DEST[255:128] <-  SRC2[127:0]
          10:  TMP_DEST[383:256] <-  SRC2[127:0]
          11:  TMP_DEST[511:384] <-  SRC2[127:0]
    ESAC.
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTI32x8 (EVEX.U1.512 encoded version)
```info-verb
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC2[255:0]
    1: TMP_DEST[511:256] <-  SRC2[255:0]
ESAC.
FOR j <-  0 TO 15
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTI64x4 (EVEX.512 encoded version) 
```info-verb
VL = 512
TEMP_DEST[VL-1:0] <-  SRC1[VL-1:0]
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC2[255:0]
    1: TMP_DEST[511:256] <-  SRC2[255:0]
ESAC.
FOR j <-  0 TO 7
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VINSERTI128
```info-verb
TEMP[255:0] <- SRC1[255:0]
CASE (imm8[0]) OF
    0: TEMP[127:0] <- SRC2[127:0]
    1: TEMP[255:128] <- SRC2[127:0]
ESAC
DEST <- TEMP
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VINSERTI32x4 _mm512i _inserti32x4( __m512i a, __m128i b, int imm);
VINSERTI32x4 _mm512i _mask_inserti32x4(__m512i s, __mmask16 k, __m512i a, __m128i b, int imm);
VINSERTI32x4 _mm512i _maskz_inserti32x4( __mmask16 k, __m512i a, __m128i b, int imm);
VINSERTI32x4 __m256i _mm256_inserti32x4( __m256i a, __m128i b, int imm);
VINSERTI32x4 __m256i _mm256_mask_inserti32x4(__m256i s, __mmask8 k, __m256i a, __m128i b, int imm);
VINSERTI32x4 __m256i _mm256_maskz_inserti32x4( __mmask8 k, __m256i a, __m128i b, int imm);
VINSERTI32x8 __m512i _mm512_inserti32x8( __m512i a, __m256i b, int imm);
VINSERTI32x8 __m512i _mm512_mask_inserti32x8(__m512i s, __mmask16 k, __m512i a, __m256i b, int imm);
VINSERTI32x8 __m512i _mm512_maskz_inserti32x8( __mmask16 k, __m512i a, __m256i b, int imm);
VINSERTI64x2 __m512i _mm512_inserti64x2( __m512i a, __m128i b, int imm);
VINSERTI64x2 __m512i _mm512_mask_inserti64x2(__m512i s, __mmask8 k, __m512i a, __m128i b, int imm);
VINSERTI64x2 __m512i _mm512_maskz_inserti64x2( __mmask8 k, __m512i a, __m128i b, int imm);
VINSERTI64x2 __m256i _mm256_inserti64x2( __m256i a, __m128i b, int imm);
VINSERTI64x2 __m256i _mm256_mask_inserti64x2(__m256i s, __mmask8 k, __m256i a, __m128i b, int imm);
VINSERTI64x2 __m256i _mm256_maskz_inserti64x2( __mmask8 k, __m256i a, __m128i b, int imm);
VINSERTI64x4 _mm512_inserti64x4( __m512i a, __m256i b, int imm);
VINSERTI64x4 _mm512_mask_inserti64x4(__m512i s, __mmask8 k, __m512i a, __m256i b, int imm);
VINSERTI64x4 _mm512_maskz_inserti64x4( __mmask m, __m512i a, __m256i b, int imm);
VINSERTI128 __m256i _mm256_insertf128_si256 (__m256i a, __m128i b, int offset);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


VEX-encoded instruction, see Exceptions Type 6; additionally

#UD If VEX.L = 0.

EVEX-encoded instruction, see Exceptions Type E6NF.

