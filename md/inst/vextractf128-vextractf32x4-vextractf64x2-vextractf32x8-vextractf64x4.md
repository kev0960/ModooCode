----------------------------
title : VEXTRACTF128, VEXTRACTF32x4, VEXTRACTF64x2, VEXTRACTF32x8, VEXTRACTF64x4s (Intel x86/64 assembly instruction)
cat_title : VEXTRACTF128, VEXTRACTF32x4, VEXTRACTF64x2, VEXTRACTF32x8, VEXTRACTF64x4
ref_title : VEXTRACTF128, VEXTRACTF32x4, VEXTRACTF64x2, VEXTRACTF32x8, VEXTRACTF64x4
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VEXTRACTF128, VEXTRACTF32x4, VEXTRACTF64x2, VEXTRACTF32x8, VEXTRACTF64x4

**Extract Packed Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.256.66.0F3A.W0 19 /r ib`\newline{}`VEXTRACTF128` \tooltip{xmm1/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|AVX|Extract 128 bits of packed floating-point values from ymm2 and store results in xmm1/m128.|
|`EVEX.256.66.0F3A.W0 19 /r ibVEXTRACTF32X4 xmm1/m128 {k1}{z}, ymm2, imm8`\newline{} |T4|V/V|AVX512VL\newline{}AVX512F|Extract 128 bits of packed single-precision floating-point values from ymm2 and store results in xmm1/m128 subject to writemask k1.|
|`EVEX.512.66.0F3A.W0 19 /r ib`\newline{}`VEXTRACTF32x4` \tooltip{xmm1/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T4|V/V|AVX512F|Extract 128 bits of packed single-precision floating-point values from zmm2 and store results in xmm1/m128 subject to writemask k1.|
|`EVEX.256.66.0F3A.W1 19 /r ibVEXTRACTF64X2 xmm1/m128 {k1}{z}, ymm2, imm8`\newline{} |T2|V/V|AVX512VL\newline{}AVX512DQ|Extract 128 bits of packed double-precision floating-point values from ymm2 and store results in xmm1/m128 subject to writemask k1.|
|`EVEX.512.66.0F3A.W1 19 /r ibVEXTRACTF64X2 xmm1/m128 {k1}{z}, zmm2, imm8`\newline{} |T2|V/V|AVX512DQ|Extract 128 bits of packed double-precision floating-point values from zmm2 and store results in xmm1/m128 subject to writemask k1.|
|`EVEX.512.66.0F3A.W0 1B /r ibVEXTRACTF32X8 ymm1/m256 {k1}{z}, zmm2, imm8`\newline{} |T8|V/V|AVX512DQ|Extract 256 bits of packed single-precision floating-point values from zmm2 and store results in ymm1/m256 subject to writemask k1.|
|`EVEX.512.66.0F3A.W1 1B /r ib`\newline{}`VEXTRACTF64x4` \tooltip{ymm1/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T4|V/V|AVX512F|Extract 256 bits of packed double-precision floating-point values from zmm2 and store results in ymm1/m256 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:r/m (w)|ModRM:reg (r)|Imm8|NA|
|T2, T4, T8|ModRM:r/m (w)|ModRM:reg (r)|Imm8|NA|
### Description


VEXTRACTF128/VEXTRACTF32x4 and `VEXTRACTF64x2` extract 128-bits of single-precision floating-point values from the source operand (the second operand) and store to the low 128-bit of the destination operand (the first operand). The 128-bit data extraction occurs at an 128-bit granular offset specified by imm8[0] (256-bit) or imm8[1:0] as the multiply factor. The destination may be either a vector register or an 128-bit memory location.

VEXTRACTF32x4: The low 128-bit of the destination operand is updated at 32-bit granularity according to the writemask.

VEXTRACTF32x8 and `VEXTRACTF64x4` extract 256-bits of double-precision floating-point values from the source operand (second operand) and store to the low 256-bit of the destination operand (the first operand). The 256-bit data extraction occurs at an 256-bit granular offset specified by imm8[0] (256-bit) or imm8[0] as the multiply factor The destination may be either a vector register or a 256-bit memory location.

VEXTRACTF64x4: The low 256-bit of the destination operand is updated at 64-bit granularity according to the writemask.

VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

The high 6 bits of the immediate are ignored.

If `VEXTRACTF128` is encoded with VEX.L= 0, an attempt to execute the instruction encoded with VEX.L= 0 will cause an #UD exception.


### Operation
#### VEXTRACTF32x4 (EVEX encoded versions) when destination is a register
```info-verb
VL = 256, 512
IF VL = 256
    CASE (imm8[0]) OF
          0: TMP_DEST[127:0] <-  SRC1[127:0]
          1: TMP_DEST[127:0] <-  SRC1[255:128]
    ESAC.
FI;
IF VL = 512 
    CASE (imm8[1:0]) OF
          00: TMP_DEST[127:0] <-  SRC1[127:0]
          01: TMP_DEST[127:0] <-  SRC1[255:128]
          10: TMP_DEST[127:0] <-  SRC1[383:256]
          11: TMP_DEST[127:0] <-  SRC1[511:384]
    ESAC.
FI;
FOR j <-  0 TO 3
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:128] <-  0
```
#### VEXTRACTF32x4 (EVEX encoded versions) when destination is memory
```info-verb
VL = 256, 512
IF VL = 256
    CASE (imm8[0]) OF
          0: TMP_DEST[127:0] <-  SRC1[127:0]
          1: TMP_DEST[127:0] <-  SRC1[255:128]
    ESAC.
FI;
IF VL = 512 
    CASE (imm8[1:0]) OF
          00: TMP_DEST[127:0] <-  SRC1[127:0]
          01: TMP_DEST[127:0] <-  SRC1[255:128]
          10: TMP_DEST[127:0] <-  SRC1[383:256]
          11: TMP_DEST[127:0] <-  SRC1[511:384]
    ESAC.
FI;
FOR j <-  0 TO 3
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE *DEST[i+31:i] remains unchanged* ; merging-masking
    FI;
ENDFOR
```
#### VEXTRACTF64x2 (EVEX encoded versions) when destination is a register
```info-verb
VL = 256, 512
IF VL = 256
    CASE (imm8[0]) OF
          0: TMP_DEST[127:0] <-  SRC1[127:0]
          1: TMP_DEST[127:0] <-  SRC1[255:128]
    ESAC.
FI;
IF VL = 512 
    CASE (imm8[1:0]) OF
          00: TMP_DEST[127:0] <-  SRC1[127:0]
          01: TMP_DEST[127:0] <-  SRC1[255:128]
          10: TMP_DEST[127:0] <-  SRC1[383:256]
          11: TMP_DEST[127:0] <-  SRC1[511:384]
    ESAC.
FI;
FOR j <-  0 TO 1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:128] <-  0
```
#### VEXTRACTF64x2 (EVEX encoded versions) when destination is memory
```info-verb
VL = 256, 512
IF VL = 256
    CASE (imm8[0]) OF
          0: TMP_DEST[127:0] <-  SRC1[127:0]
          1: TMP_DEST[127:0] <-  SRC1[255:128]
    ESAC.
FI;
IF VL = 512 
    CASE (imm8[1:0]) OF
          00: TMP_DEST[127:0] <-  SRC1[127:0]
          01: TMP_DEST[127:0] <-  SRC1[255:128]
          10: TMP_DEST[127:0] <-  SRC1[383:256]
          11: TMP_DEST[127:0] <-  SRC1[511:384]
    ESAC.
FI;
FOR j <-  0 TO 1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE *DEST[i+63:i] remains unchanged* ; merging-masking
    FI;
ENDFOR
```
#### VEXTRACTF32x8 (EVEX.U1.512 encoded version) when destination is a register
```info-verb
VL = 512
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC1[255:0]
    1: TMP_DEST[255:0] <-  SRC1[511:256]
ESAC.
FOR j <-  0 TO 7
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:256] <-  0
```
#### VEXTRACTF32x8 (EVEX.U1.512 encoded version) when destination is memory
```info-verb
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC1[255:0]
    1: TMP_DEST[255:0] <-  SRC1[511:256]
ESAC.
FOR j <-  0 TO 7
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE *DEST[i+31:i] remains unchanged* ; merging-masking
    FI;
ENDFOR
```
#### VEXTRACTF64x4 (EVEX.512 encoded version) when destination is a register
```info-verb
VL = 512
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC1[255:0]
    1: TMP_DEST[255:0] <-  SRC1[511:256]
ESAC.
FOR j <-  0 TO 3
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:256] <-  0
```
#### VEXTRACTF64x4 (EVEX.512 encoded version) when destination is memory
```info-verb
CASE (imm8[0]) OF
    0: TMP_DEST[255:0] <-  SRC1[255:0]
    1: TMP_DEST[255:0] <-  SRC1[511:256]
ESAC.
FOR j <-  0 TO 3
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE  ; merging-masking
                *DEST[i+63:i] remains unchanged*
    FI;
ENDFOR
```
#### VEXTRACTF128 (memory destination form)
```info-verb
CASE (imm8[0]) OF
    0: DEST[127:0] <- SRC1[127:0]
    1: DEST[127:0] <- SRC1[255:128]
ESAC.
```
#### VEXTRACTF128 (register destination form)
```info-verb
CASE (imm8[0]) OF
    0: DEST[127:0] <- SRC1[127:0]
    1: DEST[127:0] <- SRC1[255:128]
ESAC.
DEST[MAX_VL-1:128] <- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VEXTRACTF32x4 __m128 _mm512_extractf32x4_ps(__m512 a, const int nidx);
VEXTRACTF32x4 __m128 _mm512_mask_extractf32x4_ps(__m128 s, __mmask8 k, __m512 a, const int nidx);
VEXTRACTF32x4 __m128 _mm512_maskz_extractf32x4_ps( __mmask8 k, __m512 a, const int nidx);
VEXTRACTF32x4 __m128 _mm256_extractf32x4_ps(__m256 a, const int nidx);
VEXTRACTF32x4 __m128 _mm256_mask_extractf32x4_ps(__m128 s, __mmask8 k, __m256 a, const int nidx);
VEXTRACTF32x4 __m128 _mm256_maskz_extractf32x4_ps( __mmask8 k, __m256 a, const int nidx);
VEXTRACTF32x8 __m256 _mm512_extractf32x8_ps(__m512 a, const int nidx);
VEXTRACTF32x8 __m256 _mm512_mask_extractf32x8_ps(__m256 s, __mmask8 k, __m512 a, const int nidx);
VEXTRACTF32x8 __m256 _mm512_maskz_extractf32x8_ps( __mmask8 k, __m512 a, const int nidx);
VEXTRACTF64x2 __m128d _mm512_extractf64x2_pd(__m512d a, const int nidx);
VEXTRACTF64x2 __m128d _mm512_mask_extractf64x2_pd(__m128d s, __mmask8 k, __m512d a, const int nidx);
VEXTRACTF64x2 __m128d _mm512_maskz_extractf64x2_pd( __mmask8 k, __m512d a, const int nidx);
VEXTRACTF64x2 __m128d _mm256_extractf64x2_pd(__m256d a, const int nidx);
VEXTRACTF64x2 __m128d _mm256_mask_extractf64x2_pd(__m128d s, __mmask8 k, __m256d a, const int nidx);
VEXTRACTF64x2 __m128d _mm256_maskz_extractf64x2_pd( __mmask8 k, __m256d a, const int nidx);
VEXTRACTF64x4 __m256d _mm512_extractf64x4_pd( __m512d a, const int nidx);
VEXTRACTF64x4 __m256d _mm512_mask_extractf64x4_pd(__m256d s, __mmask8 k, __m512d a, const int nidx);
VEXTRACTF64x4 __m256d _mm512_maskz_extractf64x4_pd( __mmask8 k, __m512d a, const int nidx);
VEXTRACTF128 __m128 _mm256_extractf128_ps (__m256 a, int offset);
VEXTRACTF128 __m128d _mm256_extractf128_pd (__m256d a, int offset);
VEXTRACTF128 __m128i_mm256_extractf128_si256(__m256i a, int offset);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 6; 

EVEX-encoded instructions, see Exceptions Type E6NF.

#UD  IF VEX.L = 0.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

