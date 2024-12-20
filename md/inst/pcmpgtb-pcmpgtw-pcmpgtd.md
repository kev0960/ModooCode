----------------------------
title : PCMPGTB, PCMPGTW, PCMPGTDs (Intel x86/64 assembly instruction)
cat_title : PCMPGTB, PCMPGTW, PCMPGTD
ref_title : PCMPGTB, PCMPGTW, PCMPGTD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PCMPGTB, PCMPGTW, PCMPGTD

**Compare Packed Signed Integers for Greater Than**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 64 /r\footnote{1}`\newline{}`PCMPGTB` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Compare packed signed byte integers in mm and mm/m64 for greater than.|
|`66 0F 64 /r`\newline{}`PCMPGTB` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Compare packed signed byte integers in xmm1 and xmm2/m128 for greater than.|
|`0F 65 /r\footnote{1}`\newline{}`PCMPGTW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Compare packed signed word integers in mm and mm/m64 for greater than.|
|`66 0F 65 /r`\newline{}`PCMPGTW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V |SSE2|Compare packed signed word integers in xmm1 and xmm2/m128 for greater than.|
|`0F 66 /r\footnote{1}`\newline{}`PCMPGTD` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V |MMX|Compare packed signed doubleword integers in mm and mm/m64 for greater than.|
|`66 0F 66 /r`\newline{}`PCMPGTD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Compare packed signed doubleword integers in xmm1 and xmm2/m128 for greater than.|
|`VEX.NDS.128.66.0F.WIG 64 /r`\newline{}VPCMPGTB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Compare packed signed byte integers in xmm2 and xmm3/m128 for greater than.|
|`VEX.NDS.128.66.0F.WIG 65 /r`\newline{}VPCMPGTW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Compare packed signed word integers in xmm2 and xmm3/m128 for greater than.|
|`VEX.NDS.128.66.0F.WIG 66 /r`\newline{}VPCMPGTD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Compare packed signed doubleword integers in xmm2 and xmm3/m128 for greater than.|
|`VEX.NDS.256.66.0F.WIG 64 /r`\newline{}VPCMPGTB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Compare packed signed byte integers in ymm2 and ymm3/m256 for greater than.|
|`VEX.NDS.256.66.0F.WIG 65 /r`\newline{}VPCMPGTW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Compare packed signed word integers in ymm2 and ymm3/m256 for greater than.|
|`VEX.NDS.256.66.0F.WIG 66 /r`\newline{}VPCMPGTD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Compare packed signed doubleword integers in ymm2 and ymm3/m256 for greater than.|
|`EVEX.NDS.128.66.0F.W0 66 /r`\newline{}VPCMPGTD \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Compare Greater between int32 vector xmm2 and int32 vector xmm3/m128/m32bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|`EVEX.NDS.256.66.0F.W0 66 /r`\newline{}VPCMPGTD \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Compare Greater between int32 vector ymm2 and int32 vector ymm3/m256/m32bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|`EVEX.NDS.512.66.0F.W0 66 /r`\newline{}VPCMPGTD \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} zmm2 \tooltip{zmm3/m512/m32bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 32 비트 메모리 주소값에 불러온 벡터 데이터.} |FV|V/V|AVX512F|Compare Greater between int32 elements in zmm2 and zmm3/m512/m32bcst, and set destination k1 according to the comparison results under writemask. k2.|
|`EVEX.NDS.128.66.0F.WIG 64 /r`\newline{}VPCMPGTB \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed byte integers in xmm2 and xmm3/m128 for greater than, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|`EVEX.NDS.256.66.0F.WIG 64 /r`\newline{}VPCMPGTB \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed byte integers in ymm2 and ymm3/m256 for greater than, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|


|EVEX.NDS.512.66.0F.WIG 64 /r\newline{}VPCMPGTB k1 {k2}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Compare packed signed byte integers in zmm2 and \newline{}zmm3/m512 for greater than, and set vector \newline{}mask k1 to reflect the zero/nonzero status of each \newline{}element of the result, under writemask.|
|-----------------------------------------------------------------------|---|---|--------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|EVEX.NDS.128.66.0F.WIG 65 /rVPCMPGTW k1 {k2}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed word integers in xmm2 and xmm3/m128 for greater than, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.256.66.0F.WIG 65 /rVPCMPGTW k1 {k2}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Compare packed signed word integers in ymm2 and ymm3/m256 for greater than, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|
|EVEX.NDS.512.66.0F.WIG 65 /rVPCMPGTW k1 {k2}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Compare packed signed word integers in zmm2 and zmm3/m512 for greater than, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs an SIMD signed compare for the greater value of the packed byte, word, or doubleword integers in the destination operand (first operand) and the source operand (second operand). If a data element in the destination operand is greater than the corresponding date element in the source operand, the corresponding data element in the destination operand is set to all 1s; otherwise, it is set to all 0s.

The `PCMPGTB` instruction compares the corresponding signed byte integers in the destination and source oper-ands; the `PCMPGTW` instruction compares the corresponding signed word integers in the destination and source operands; and the `PCMPGTD` instruction compares the corresponding signed doubleword integers in the destina-tion and source operands.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE instructions: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand can be an MMX technology register.

128-bit Legacy SSE version: The second source operand can be an XMM register or a 128-bit memory location. The first source operand and destination operand are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged. 

VEX.128 encoded version: The second source operand can be an XMM register or a 128-bit memory location. The first source operand and destination operand are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register.



EVEX encoded VPCMPGTD: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand (first operand) is a mask register updated according to the writemask k2.

EVEX encoded VPCMPGTB/W: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand (first operand) is a mask register updated according to the writemask k2.


### Operation
#### PCMPGTB (with 64-bit operands)
```info-verb
    IF DEST[7:0] > SRC[7:0]
          THEN DEST[7:0) <- FFH; 
          ELSE DEST[7:0] <- 0; FI;
    (* Continue comparison of 2nd through 7th bytes in DEST and SRC *)
    IF DEST[63:56] > SRC[63:56]
          THEN DEST[63:56] <- FFH;
          ELSE DEST[63:56] <- 0; FI;
```
#### COMPARE_BYTES_GREATER (SRC1, SRC2)
```info-verb
    IF SRC1[7:0] > SRC2[7:0]
    THEN DEST[7:0] <- FFH;
    ELSE DEST[7:0] <- 0; FI;
(* Continue comparison of 2nd through 15th bytes in SRC1 and SRC2 *)
    IF SRC1[127:120] > SRC2[127:120]
    THEN DEST[127:120] <- FFH;
    ELSE DEST[127:120] <- 0; FI;
```
#### COMPARE_WORDS_GREATER (SRC1, SRC2)
```info-verb
    IF SRC1[15:0] > SRC2[15:0]
    THEN DEST[15:0] <- FFFFH;
    ELSE DEST[15:0] <- 0; FI;
(* Continue comparison of 2nd through 7th 16-bit words in SRC1 and SRC2 *)
    IF SRC1[127:112] > SRC2[127:112]
    THEN DEST[127:112] <- FFFFH;
    ELSE DEST[127:112] <- 0; FI;
```
#### COMPARE_DWORDS_GREATER (SRC1, SRC2)
```info-verb
    IF SRC1[31:0] > SRC2[31:0]
    THEN DEST[31:0] <- FFFFFFFFH;
    ELSE DEST[31:0] <- 0; FI;
(* Continue comparison of 2nd through 3rd 32-bit dwords in SRC1 and SRC2 *)
    IF SRC1[127:96] > SRC2[127:96]
    THEN DEST[127:96] <- FFFFFFFFH;
    ELSE DEST[127:96] <- 0; FI;
```
#### PCMPGTB (with 128-bit operands)
```info-verb
DEST[127:0] <- COMPARE_BYTES_GREATER(DEST[127:0],SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPCMPGTB (VEX.128 encoded version)
```info-verb
DEST[127:0] <- COMPARE_BYTES_GREATER(SRC1,SRC2)
DEST[VLMAX-1:128] <-  0
```
#### VPCMPGTB (VEX.256 encoded version)
```info-verb
DEST[127:0] <- COMPARE_BYTES_GREATER(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_BYTES_GREATER(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256] <-  0
```
#### VPCMPGTB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k2[j] OR *no writemask*
          THEN 
                /* signed comparison */
                CMP <-  SRC1[i+7:i] > SRC2[i+7:i];
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] <-  0 ; zeroing-masking onlyFI;
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### PCMPGTW (with 64-bit operands)
```info-verb
    IF DEST[15:0] > SRC[15:0] THEN DEST[15:0] <- FFFFH;
          ELSE DEST[15:0] <- 0; FI;
    (* Continue comparison of 2nd and 3rd words in DEST and SRC *)
    IF DEST[63:48] > SRC[63:48]
          THEN DEST[63:48] <- FFFFH;
          ELSE DEST[63:48] <- 0; FI;
```
#### PCMPGTW (with 128-bit operands)
```info-verb
DEST[127:0] <- COMPARE_WORDS_GREATER(DEST[127:0],SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPCMPGTW (VEX.128 encoded version)
```info-verb
DEST[127:0] <- COMPARE_WORDS_GREATER(SRC1,SRC2)
DEST[VLMAX-1:128] <-  0
```
#### VPCMPGTW (VEX.256 encoded version)
```info-verb
DEST[127:0] <- COMPARE_WORDS_GREATER(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_WORDS_GREATER(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256] <-  0
```
#### VPCMPGTW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k2[j] OR *no writemask*
          THEN 
                /* signed comparison */
                CMP <-  SRC1[i+15:i] > SRC2[i+15:i];
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
ELSE  DEST[j] <-  0 ; zeroing-masking onlyFI;
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### PCMPGTD (with 64-bit operands)
```info-verb
    IF DEST[31:0] > SRC[31:0]
          THEN DEST[31:0] <- FFFFFFFFH; 
          ELSE DEST[31:0] <- 0; FI;
    IF DEST[63:32] > SRC[63:32]
          THEN DEST[63:32] <- FFFFFFFFH;
          ELSE DEST[63:32] <- 0; FI;
```
#### PCMPGTD (with 128-bit operands)
```info-verb
DEST[127:0] <- COMPARE_DWORDS_GREATER(DEST[127:0],SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPCMPGTD (VEX.128 encoded version)
```info-verb
DEST[127:0] <- COMPARE_DWORDS_GREATER(SRC1,SRC2)
DEST[VLMAX-1:128] <-  0
```
#### VPCMPGTD (VEX.256 encoded version)
```info-verb
DEST[127:0] <- COMPARE_DWORDS_GREATER(SRC1[127:0],SRC2[127:0])
DEST[255:128] <- COMPARE_DWORDS_GREATER(SRC1[255:128],SRC2[255:128])
DEST[VLMAX-1:256] <-  0
```
#### VPCMPGTD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k2[j] OR *no writemask*
          THEN 
                /* signed comparison */
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN CMP <-  SRC1[i+31:i] > SRC2[31:0];
                      ELSE CMP <-  SRC1[i+31:i] > SRC2[i+31:i];
                FI;
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] <-  0 ; zeroing-masking only
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPCMPGTB __mmask64 _mm512_cmpgt_epi8_mask(__m512i a, __m512i b);
VPCMPGTB __mmask64 _mm512_mask_cmpgt_epi8_mask(__mmask64 k, __m512i a, __m512i b);
VPCMPGTB __mmask32 _mm256_cmpgt_epi8_mask(__m256i a, __m256i b);
VPCMPGTB __mmask32 _mm256_mask_cmpgt_epi8_mask(__mmask32 k, __m256i a, __m256i b);
VPCMPGTB __mmask16 _mm_cmpgt_epi8_mask(__m128i a, __m128i b);
VPCMPGTB __mmask16 _mm_mask_cmpgt_epi8_mask(__mmask16 k, __m128i a, __m128i b);
VPCMPGTD __mmask16 _mm512_cmpgt_epi32_mask(__m512i a, __m512i b);
VPCMPGTD __mmask16 _mm512_mask_cmpgt_epi32_mask(__mmask16 k, __m512i a, __m512i b);
VPCMPGTD __mmask8 _mm256_cmpgt_epi32_mask(__m256i a, __m256i b);
VPCMPGTD __mmask8 _mm256_mask_cmpgt_epi32_mask(__mmask8 k, __m256i a, __m256i b);
VPCMPGTD __mmask8 _mm_cmpgt_epi32_mask(__m128i a, __m128i b);
VPCMPGTD __mmask8 _mm_mask_cmpgt_epi32_mask(__mmask8 k, __m128i a, __m128i b);
VPCMPGTW __mmask32 _mm512_cmpgt_epi16_mask(__m512i a, __m512i b);
VPCMPGTW __mmask32 _mm512_mask_cmpgt_epi16_mask(__mmask32 k, __m512i a, __m512i b);
VPCMPGTW __mmask16 _mm256_cmpgt_epi16_mask(__m256i a, __m256i b);
VPCMPGTW __mmask16 _mm256_mask_cmpgt_epi16_mask(__mmask16 k, __m256i a, __m256i b);
VPCMPGTW __mmask8 _mm_cmpgt_epi16_mask(__m128i a, __m128i b);
VPCMPGTW __mmask8 _mm_mask_cmpgt_epi16_mask(__mmask8 k, __m128i a, __m128i b);
PCMPGTB:__m64 _mm_cmpgt_pi8 (__m64 m1, __m64 m2)
PCMPGTW:__m64 _mm_pcmpgt_pi16 (__m64 m1, __m64 m2)
PCMPGTD:__m64 _mm_pcmpgt_pi32 (__m64 m1, __m64 m2)
(V)PCMPGTB:__m128i _mm_cmpgt_epi8 ( __m128i a, __m128i b)
(V)PCMPGTW:__m128i _mm_cmpgt_epi16 ( __m128i a, __m128i b)
(V)DCMPGTD:__m128i _mm_cmpgt_epi32 ( __m128i a, __m128i b)
VPCMPGTB: __m256i _mm256_cmpgt_epi8 ( __m256i a, __m256i b)
VPCMPGTW: __m256i _mm256_cmpgt_epi16 ( __m256i a, __m256i b)
VPCMPGTD: __m256i _mm256_cmpgt_epi32 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPCMPGTD, see Exceptions Type E4.

EVEX-encoded VPCMPGTB/W, see Exceptions Type E4.nb.

