----------------------------
title : PSHUFHW (Intel x86/64 assembly instruction)
cat_title : PSHUFHW
ref_title : PSHUFHW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSHUFHW

**Shuffle Packed High Words**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 70 /r ib`\newline{}`PSHUFHW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE2|Shuffle the high words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.|
|`VEX.128.F3.0F.WIG 70 /r ib`\newline{}VPSHUFHW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|AVX|Shuffle the high words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.|
|`VEX.256.F3.0F.WIG 70 /r ib`\newline{}VPSHUFHW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|AVX2|Shuffle the high words in ymm2/m256 based on the encoding in imm8 and store the result in ymm1.|
|`EVEX.128.F3.0F.WIG 70 /r ib`\newline{}VPSHUFHW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVM|V/V|AVX512VL\newline{}AVX512BW|Shuffle the high words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1 under write mask k1.|
|`EVEX.256.F3.0F.WIG 70 /r ib`\newline{}VPSHUFHW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVM|V/V|AVX512VL\newline{}AVX512BW|Shuffle the high words in ymm2/m256 based on the encoding in imm8 and store the result in ymm1 under write mask k1.|
|`EVEX.512.F3.0F.WIG 70 /r ib`\newline{}VPSHUFHW zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVM|V/V|AVX512BW|Shuffle the high words in zmm2/m512 based on the encoding in imm8 and store the result in zmm1 under write mask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
|FVM|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description


Copies words from the high quadword of a 128-bit lane of the source operand and inserts them in the high quad-word of the destination operand at word locations (of the respective lane) selected with the immediate operand. This 256-bit operation is similar to the in-lane operation used by the 256-bit VPSHUFD instruction, which is illus-trated in Figure 4-16. For 128-bit operation, only the low 128-bit lane is operative. Each 2-bit field in the immediate operand selects the contents of one word location in the high quadword of the destination operand. The binary encodings of the immediate operand fields select words (0, 1, 2 or 3, 4) from the high quadword of the source operand to be copied to the destination operand. The low quadword of the source operand is copied to the low quadword of the destination operand, for each 128-bit lane.

Note that this instruction permits a word in the high quadword of the source operand to be copied to more than one word location in the high quadword of the destination operand.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

128-bit Legacy SSE version: The destination operand is an XMM register. The source operand can be an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The destination operand is an XMM register. The source operand can be an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.vvvv is reserved and must be 1111b, VEX.L must be 0, otherwise the instruction will #UD.

VEX.256 encoded version: The destination operand is an YMM register. The source operand can be an YMM register or a 256-bit memory location. 



EVEX encoded version: The destination operand is a ZMM/YMM/XMM registers. The source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination is updated according to the writemask.

Note: In VEX encoded versions, VEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### PSHUFHW (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-  SRC[63:0]
DEST[79:64] <-  (SRC >> (imm[1:0] *16))[79:64]
DEST[95:80] <-  (SRC >> (imm[3:2] * 16))[79:64]
DEST[111:96] <-  (SRC >> (imm[5:4] * 16))[79:64]
DEST[127:112] <-  (SRC >> (imm[7:6] * 16))[79:64]
DEST[VLMAX-1:128] (Unmodified)
```
#### VPSHUFHW (VEX.128 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0]
DEST[79:64] <-  (SRC1 >> (imm[1:0] *16))[79:64]
DEST[95:80] <-  (SRC1 >> (imm[3:2] * 16))[79:64]
DEST[111:96] <-  (SRC1 >> (imm[5:4] * 16))[79:64]
DEST[127:112] <-  (SRC1 >> (imm[7:6] * 16))[79:64]
DEST[VLMAX-1:128] <-  0
```
#### VPSHUFHW (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0]
DEST[79:64] <-  (SRC1 >> (imm[1:0] *16))[79:64]
DEST[95:80] <-  (SRC1 >> (imm[3:2] * 16))[79:64]
DEST[111:96] <-  (SRC1 >> (imm[5:4] * 16))[79:64]
DEST[127:112] <-  (SRC1 >> (imm[7:6] * 16))[79:64]
DEST[191:128] <-  SRC1[191:128]
DEST[207192] <-  (SRC1 >> (imm[1:0] *16))[207:192]
DEST[223:208] <-  (SRC1 >> (imm[3:2] * 16))[207:192]
DEST[239:224] <-  (SRC1 >> (imm[5:4] * 16))[207:192]
DEST[255:240] <-  (SRC1 >> (imm[7:6] * 16))[207:192]
DEST[VLMAX-1:256] <-  0
```
#### VPSHUFHW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL >= 128
    TMP_DEST[63:0] <-  SRC1[63:0]
    TMP_DEST[79:64] <-  (SRC1 >> (imm[1:0] *16))[79:64]
    TMP_DEST[95:80] <-  (SRC1 >> (imm[3:2] * 16))[79:64]
    TMP_DEST[111:96] <-  (SRC1 >> (imm[5:4] * 16))[79:64]
    TMP_DEST[127:112] <-  (SRC1 >> (imm[7:6] * 16))[79:64]
FI;
IF VL >= 256
    TMP_DEST[191:128] <-  SRC1[191:128]
    TMP_DEST[207:192] <-  (SRC1 >> (imm[1:0] *16))[207:192]
    TMP_DEST[223:208] <-  (SRC1 >> (imm[3:2] * 16))[207:192]
    TMP_DEST[239:224] <-  (SRC1 >> (imm[5:4] * 16))[207:192]
    TMP_DEST[255:240] <-  (SRC1 >> (imm[7:6] * 16))[207:192]
FI;
IF VL >= 512
    TMP_DEST[319:256] <-  SRC1[319:256]
    TMP_DEST[335:320] <-  (SRC1 >> (imm[1:0] *16))[335:320]
TMP_DEST[351:336] <-  (SRC1 >> (imm[3:2] * 16))[335:320]
    TMP_DEST[367:352] <-  (SRC1 >> (imm[5:4] * 16))[335:320]
    TMP_DEST[383:368] <-  (SRC1 >> (imm[7:6] * 16))[335:320]
    TMP_DEST[447:384] <-  SRC1[447:384]
    TMP_DEST[463:448] <-  (SRC1 >> (imm[1:0] *16))[463:448]
    TMP_DEST[479:464] <-  (SRC1 >> (imm[3:2] * 16))[463:448]
    TMP_DEST[495:480] <-  (SRC1 >> (imm[5:4] * 16))[463:448]
    TMP_DEST[511:496] <-  (SRC1 >> (imm[7:6] * 16))[463:448]
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  TMP_DEST[i+15:i];
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPSHUFHW __m512i _mm512_shufflehi_epi16(__m512i a, int n);
VPSHUFHW __m512i _mm512_mask_shufflehi_epi16(__m512i s, __mmask16 k, __m512i a, int n );
VPSHUFHW __m512i _mm512_maskz_shufflehi_epi16( __mmask16 k, __m512i a, int n );
VPSHUFHW __m256i _mm256_mask_shufflehi_epi16(__m256i s, __mmask8 k, __m256i a, int n );
VPSHUFHW __m256i _mm256_maskz_shufflehi_epi16( __mmask8 k, __m256i a, int n );
VPSHUFHW __m128i _mm_mask_shufflehi_epi16(__m128i s, __mmask8 k, __m128i a, int n );
VPSHUFHW __m128i _mm_maskz_shufflehi_epi16( __mmask8 k, __m128i a, int n );
(V)PSHUFHW:__m128i _mm_shufflehi_epi16(__m128i a, int n)
VPSHUFHW:__m256i _mm256_shufflehi_epi16(__m256i a, const int n)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4; 

EVEX-encoded instruction, see Exceptions Type E4NF.nb

#UD  If VEX.vvvv != 1111B, or EVEX.vvvv != 1111B.

