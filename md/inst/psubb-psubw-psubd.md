----------------------------
title : PSUBB, PSUBW, PSUBDs (Intel x86/64 assembly instruction)
cat_title : PSUBB, PSUBW, PSUBD
ref_title : PSUBB, PSUBW, PSUBD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSUBB, PSUBW, PSUBD

**Subtract Packed Integers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F F8 /r\footnote{1}`\newline{}`PSUBB` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Subtract packed byte integers in mm/m64 from packed byte integers in mm.|
|`66 0F F8 /r`\newline{}`PSUBB` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Subtract packed byte integers in xmm2/m128 from packed byte integers in xmm1.|
|`0F F9 /r\footnote{1}`\newline{}`PSUBW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Subtract packed word integers in mm/m64 from packed word integers in mm.|
|`66 0F F9 /r`\newline{}`PSUBW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Subtract packed word integers in xmm2/m128 from packed word integers in xmm1.|
|`0F FA /r\footnote{1}`\newline{}`PSUBD` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Subtract packed doubleword integers in mm/m64 from packed doubleword integers in mm.|
|`66 0F FA /r`\newline{}`PSUBD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Subtract packed doubleword integers in xmm2/mem128 from packed doubleword integers in xmm1.|
|`VEX.NDS.128.66.0F.WIG F8 /r`\newline{}VPSUBB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract packed byte integers in xmm3/m128 from xmm2.|
|`VEX.NDS.128.66.0F.WIG F9 /r`\newline{}VPSUBW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract packed word integers in xmm3/m128 from xmm2.|
|`VEX.NDS.128.66.0F.WIG FA /r`\newline{}VPSUBD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Subtract packed doubleword integers in xmm3/m128 from xmm2.|
|`VEX.NDS.256.66.0F.WIG F8 /r`\newline{}VPSUBB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Subtract packed byte integers in ymm3/m256 from ymm2.|
|`VEX.NDS.256.66.0F.WIG F9 /r`\newline{}VPSUBW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Subtract packed word integers in ymm3/m256 from ymm2.|
|`VEX.NDS.256.66.0F.WIG FA /r`\newline{}VPSUBD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Subtract packed doubleword integers in ymm3/m256 from ymm2.|
|`EVEX.NDS.128.66.0F.WIG F8 /r`\newline{}VPSUBB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed byte integers in xmm3/m128 from xmm2 and store in xmm1 using writemask k1.|
|`EVEX.NDS.256.66.0F.WIG F8 /r`\newline{}VPSUBB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed byte integers in ymm3/m256 from ymm2 and store in ymm1 using writemask k1.|
|`EVEX.NDS.512.66.0F.WIG F8 /r`\newline{}VPSUBB zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Subtract packed byte integers in zmm3/m512 from zmm2 and store in zmm1 using writemask k1.|
|`EVEX.NDS.128.66.0F.WIG F9 /r`\newline{}VPSUBW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed word integers in xmm3/m128 from xmm2 and store in xmm1 using writemask k1.|
|`EVEX.NDS.256.66.0F.WIG F9 /r`\newline{}VPSUBW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Subtract packed word integers in ymm3/m256 from ymm2 and store in ymm1 using writemask k1.|
|`EVEX.NDS.512.66.0F.WIG F9 /r`\newline{}VPSUBW zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Subtract packed word integers in zmm3/m512 from zmm2 and store in zmm1 using writemask k1.|


|EVEX.NDS.128.66.0F.W0 FA /r\newline{}VPSUBD xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}\newline{}AVX512F|Subtract packed doubleword integers in \newline{}xmm3/m128/m32bcst from xmm2 and store \newline{}in xmm1 using writemask k1.|
|----------------------------------------------------------------------------------|--|---|-----------------------------------|----------------------------------------------------------------------------------------------------------------------------|
|EVEX.NDS.256.66.0F.W0 FA /rVPSUBD ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Subtract packed doubleword integers in ymm3/m256/m32bcst from ymm2 and store in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F.W0 FA /rVPSUBD zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst |FV|V/V|AVX512F|Subtract packed doubleword integers in zmm3/m512/m32bcst from zmm2 and store in zmm1 using writemask k1|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs a SIMD subtract of the packed integers of the source operand (second operand) from the packed integers of the destination operand (first operand), and stores the packed integer results in the destination operand. See Figure 9-4 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for an illustration of a SIMD operation. Overflow is handled with wraparound, as described in the following paragraphs.

The (V)PSUBB instruction subtracts packed byte integers. When an individual result is too large or too small to be represented in a byte, the result is wrapped around and the low 8 bits are written to the destination element.

The (V)PSUBW instruction subtracts packed word integers. When an individual result is too large or too small to be represented in a word, the result is wrapped around and the low 16 bits are written to the destination element.

The (V)PSUBD instruction subtracts packed doubleword integers. When an individual result is too large or too small to be represented in a doubleword, the result is wrapped around and the low 32 bits are written to the destination element.

Note that the (V)PSUBB, (V)PSUBW, and (V)PSUBD instructions can operate on either unsigned or signed (two's complement notation) packed integers; however, it does not set bits in the EFLAGS register to indicate overflow and/or a carry. To prevent undetected overflow conditions, software must control the ranges of values upon which it operates.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version 64-bit operand: The destination operand must be an MMX technology register and the source operand can be either an MMX technology register or a 64-bit memory location.

128-bit Legacy SSE version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM desti-nation register remain unchanged.

VEX.128 encoded version: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 



VEX.256 encoded versions: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed.

EVEX encoded VPSUBD: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory loca-tion or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is conditionally updated with writemask k1.

EVEX encoded VPSUBB/W: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is condi-tionally updated with writemask k1.


### Operation
#### PSUBB (with 64-bit operands)
```info-verb
    DEST[7:0] <- DEST[7:0] - SRC[7:0]; 
    (* Repeat subtract operation for 2nd through 7th byte *)
    DEST[63:56] <- DEST[63:56] - SRC[63:56];
```
#### PSUBW (with 64-bit operands)
```info-verb
    DEST[15:0] <- DEST[15:0] - SRC[15:0];
    (* Repeat subtract operation for 2nd and 3rd word *)
    DEST[63:48] <- DEST[63:48] - SRC[63:48];
```
#### PSUBD (with 64-bit operands)
```info-verb
    DEST[31:0] <- DEST[31:0] - SRC[31:0];
    DEST[63:32] <- DEST[63:32] - SRC[63:32];
```
#### PSUBD (with 128-bit operands)
```info-verb
    DEST[31:0]  <- DEST[31:0] - SRC[31:0];
    (* Repeat subtract operation for 2nd and 3rd doubleword *)
    DEST[127:96] <- DEST[127:96] - SRC[127:96];
```
#### VPSUBB (EVEX encoded versions) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SRC1[i+7:i] - SRC2[i+7:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i] = 0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPSUBW (EVEX encoded versions) 
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SRC1[i+15:i] - SRC2[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPSUBD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN DEST[i+31:i] <-  SRC1[i+31:i] - SRC2[31:0]
                      ELSE DEST[i+31:i] <-  SRC1[i+31:i] - SRC2[i+31:i]
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPSUBB (VEX.256 encoded version)
```info-verb
DEST[7:0] <- SRC1[7:0]-SRC2[7:0]
DEST[15:8] <- SRC1[15:8]-SRC2[15:8]
DEST[23:16] <- SRC1[23:16]-SRC2[23:16]
DEST[31:24] <- SRC1[31:24]-SRC2[31:24]
DEST[39:32] <- SRC1[39:32]-SRC2[39:32]
DEST[47:40] <- SRC1[47:40]-SRC2[47:40]
DEST[55:48] <- SRC1[55:48]-SRC2[55:48]
DEST[63:56] <- SRC1[63:56]-SRC2[63:56]
DEST[71:64] <- SRC1[71:64]-SRC2[71:64]
DEST[79:72] <- SRC1[79:72]-SRC2[79:72]
DEST[87:80] <- SRC1[87:80]-SRC2[87:80]
DEST[95:88] <- SRC1[95:88]-SRC2[95:88]
DEST[103:96] <- SRC1[103:96]-SRC2[103:96]
DEST[111:104] <- SRC1[111:104]-SRC2[111:104]
DEST[119:112] <- SRC1[119:112]-SRC2[119:112]
DEST[127:120] <- SRC1[127:120]-SRC2[127:120]
DEST[135:128] <- SRC1[135:128]-SRC2[135:128]
DEST[143:136] <- SRC1[143:136]-SRC2[143:136]
DEST[151:144] <- SRC1[151:144]-SRC2[151:144]
DEST[159:152] <- SRC1[159:152]-SRC2[159:152]
DEST[167:160] <- SRC1[167:160]-SRC2[167:160]
DEST[175:168] <- SRC1[175:168]-SRC2[175:168]
DEST[183:176] <- SRC1[183:176]-SRC2[183:176]
DEST[191:184] <- SRC1[191:184]-SRC2[191:184]
DEST[199:192] <- SRC1[199:192]-SRC2[199:192]
DEST[207:200] <- SRC1[207:200]-SRC2[207:200]
DEST[215:208] <- SRC1[215:208]-SRC2[215:208]
DEST[223:216] <- SRC1[223:216]-SRC2[223:216]
DEST[231:224] <- SRC1[231:224]-SRC2[231:224]
DEST[239:232] <- SRC1[239:232]-SRC2[239:232]
DEST[247:240] <- SRC1[247:240]-SRC2[247:240]
DEST[255:248] <- SRC1[255:248]-SRC2[255:248]
DEST[MAX_VL-1:256] <- 0
```
#### VPSUBB (VEX.128 encoded version)
```info-verb
DEST[7:0] <- SRC1[7:0]-SRC2[7:0]
DEST[15:8] <- SRC1[15:8]-SRC2[15:8]
DEST[23:16] <- SRC1[23:16]-SRC2[23:16]
DEST[31:24] <- SRC1[31:24]-SRC2[31:24]
DEST[39:32] <- SRC1[39:32]-SRC2[39:32]
DEST[47:40] <- SRC1[47:40]-SRC2[47:40]
DEST[55:48] <- SRC1[55:48]-SRC2[55:48]
DEST[63:56] <- SRC1[63:56]-SRC2[63:56]
DEST[71:64] <- SRC1[71:64]-SRC2[71:64]
DEST[79:72] <- SRC1[79:72]-SRC2[79:72]
DEST[87:80] <- SRC1[87:80]-SRC2[87:80]
DEST[95:88] <- SRC1[95:88]-SRC2[95:88]
DEST[103:96] <- SRC1[103:96]-SRC2[103:96]
DEST[111:104] <- SRC1[111:104]-SRC2[111:104]
DEST[119:112] <- SRC1[119:112]-SRC2[119:112]
DEST[127:120] <- SRC1[127:120]-SRC2[127:120]
DEST[MAX_VL-1:128] <- 0
```
#### PSUBB (128-bit Legacy SSE version)
```info-verb
DEST[7:0] <- DEST[7:0]-SRC[7:0]
DEST[15:8] <- DEST[15:8]-SRC[15:8]
DEST[23:16] <- DEST[23:16]-SRC[23:16]
DEST[31:24] <- DEST[31:24]-SRC[31:24]
DEST[39:32] <- DEST[39:32]-SRC[39:32]
DEST[47:40] <- DEST[47:40]-SRC[47:40]
DEST[55:48] <- DEST[55:48]-SRC[55:48]
DEST[63:56] <- DEST[63:56]-SRC[63:56]
DEST[71:64] <- DEST[71:64]-SRC[71:64]
DEST[79:72] <- DEST[79:72]-SRC[79:72]
DEST[87:80] <- DEST[87:80]-SRC[87:80]
DEST[95:88] <- DEST[95:88]-SRC[95:88]
DEST[103:96] <- DEST[103:96]-SRC[103:96]
DEST[111:104] <- DEST[111:104]-SRC[111:104]
DEST[119:112] <- DEST[119:112]-SRC[119:112]
DEST[127:120] <- DEST[127:120]-SRC[127:120]
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSUBW (VEX.256 encoded version)
```info-verb
DEST[15:0] <- SRC1[15:0]-SRC2[15:0]
DEST[31:16] <- SRC1[31:16]-SRC2[31:16]
DEST[47:32] <- SRC1[47:32]-SRC2[47:32]
DEST[63:48] <- SRC1[63:48]-SRC2[63:48]
DEST[79:64] <- SRC1[79:64]-SRC2[79:64]
DEST[95:80] <- SRC1[95:80]-SRC2[95:80]
DEST[111:96] <- SRC1[111:96]-SRC2[111:96]
DEST[127:112] <- SRC1[127:112]-SRC2[127:112]
DEST[143:128] <- SRC1[143:128]-SRC2[143:128]
DEST[159:144] <- SRC1[159:144]-SRC2[159:144]
DEST[175:160] <- SRC1[175:160]-SRC2[175:160]
DEST[191:176] <- SRC1[191:176]-SRC2[191:176]
DEST[207:192] <- SRC1207:192]-SRC2[207:192]
DEST[223:208] <- SRC1[223:208]-SRC2[223:208]
DEST[239:224] <- SRC1[239:224]-SRC2[239:224]
DEST[255:240] <- SRC1[255:240]-SRC2[255:240]
DEST[MAX_VL-1:256] <- 0
```
#### VPSUBW (VEX.128 encoded version)
```info-verb
DEST[15:0] <- SRC1[15:0]-SRC2[15:0]
DEST[31:16] <- SRC1[31:16]-SRC2[31:16]
DEST[47:32] <- SRC1[47:32]-SRC2[47:32]
DEST[63:48] <- SRC1[63:48]-SRC2[63:48]
DEST[79:64] <- SRC1[79:64]-SRC2[79:64]
DEST[95:80] <- SRC1[95:80]-SRC2[95:80]
DEST[111:96] <- SRC1[111:96]-SRC2[111:96]
DEST[127:112] <- SRC1[127:112]-SRC2[127:112]
DEST[MAX_VL-1:128] <- 0
```
#### PSUBW (128-bit Legacy SSE version)
```info-verb
DEST[15:0] <- DEST[15:0]-SRC[15:0]
DEST[31:16] <- DEST[31:16]-SRC[31:16]
DEST[47:32] <- DEST[47:32]-SRC[47:32]
DEST[63:48] <- DEST[63:48]-SRC[63:48]
DEST[79:64] <- DEST[79:64]-SRC[79:64]
DEST[95:80] <- DEST[95:80]-SRC[95:80]
DEST[111:96] <- DEST[111:96]-SRC[111:96]
DEST[127:112] <- DEST[127:112]-SRC[127:112]
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSUBD (VEX.256 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0]-SRC2[31:0]
DEST[63:32] <- SRC1[63:32]-SRC2[63:32]
DEST[95:64] <- SRC1[95:64]-SRC2[95:64]
DEST[127:96] <- SRC1[127:96]-SRC2[127:96]
DEST[159:128] <- SRC1[159:128]-SRC2[159:128]
DEST[191:160] <- SRC1[191:160]-SRC2[191:160]
DEST[223:192] <- SRC1[223:192]-SRC2[223:192]
DEST[255:224] <- SRC1[255:224]-SRC2[255:224]
DEST[MAX_VL-1:256] <- 0
```
#### VPSUBD (VEX.128 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0]-SRC2[31:0]
DEST[63:32] <- SRC1[63:32]-SRC2[63:32]
DEST[95:64] <- SRC1[95:64]-SRC2[95:64]
DEST[127:96] <- SRC1[127:96]-SRC2[127:96]
DEST[MAX_VL-1:128] <- 0
```
#### PSUBD (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- DEST[31:0]-SRC[31:0]
DEST[63:32] <- DEST[63:32]-SRC[63:32]
DEST[95:64] <- DEST[95:64]-SRC[95:64]
DEST[127:96] <- DEST[127:96]-SRC[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPSUBB __m512i _mm512_sub_epi8(__m512i a, __m512i b);
VPSUBB __m512i _mm512_mask_sub_epi8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPSUBB __m512i _mm512_maskz_sub_epi8( __mmask64 k, __m512i a, __m512i b);
VPSUBB __m256i _mm256_mask_sub_epi8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPSUBB __m256i _mm256_maskz_sub_epi8( __mmask32 k, __m256i a, __m256i b);
VPSUBB __m128i _mm_mask_sub_epi8(__m128i s, __mmask16 k, __m128i a, __m128i b);
VPSUBB __m128i _mm_maskz_sub_epi8( __mmask16 k, __m128i a, __m128i b);
VPSUBW __m512i _mm512_sub_epi16(__m512i a, __m512i b);
VPSUBW __m512i _mm512_mask_sub_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPSUBW __m512i _mm512_maskz_sub_epi16( __mmask32 k, __m512i a, __m512i b);
VPSUBW __m256i _mm256_mask_sub_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPSUBW __m256i _mm256_maskz_sub_epi16( __mmask16 k, __m256i a, __m256i b);
VPSUBW __m128i _mm_mask_sub_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPSUBW __m128i _mm_maskz_sub_epi16( __mmask8 k, __m128i a, __m128i b);
VPSUBD __m512i _mm512_sub_epi32(__m512i a, __m512i b);
VPSUBD __m512i _mm512_mask_sub_epi32(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPSUBD __m512i _mm512_maskz_sub_epi32( __mmask16 k, __m512i a, __m512i b);
VPSUBD __m256i _mm256_mask_sub_epi32(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPSUBD __m256i _mm256_maskz_sub_epi32( __mmask8 k, __m256i a, __m256i b);
VPSUBD __m128i _mm_mask_sub_epi32(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPSUBD __m128i _mm_maskz_sub_epi32( __mmask8 k, __m128i a, __m128i b);
PSUBB:__m64 _mm_sub_pi8(__m64 m1, __m64 m2)
(V)PSUBB:__m128i _mm_sub_epi8 ( __m128i a, __m128i b)
VPSUBB:__m256i _mm256_sub_epi8 ( __m256i a, __m256i b)
PSUBW:__m64 _mm_sub_pi16(__m64 m1, __m64 m2)
(V)PSUBW:__m128i _mm_sub_epi16 ( __m128i a, __m128i b)
VPSUBW:__m256i _mm256_sub_epi16 ( __m256i a, __m256i b)
PSUBD:__m64 _mm_sub_pi32(__m64 m1, __m64 m2)
(V)PSUBD:__m128i _mm_sub_epi32 ( __m128i a, __m128i b)
VPSUBD:__m256i _mm256_sub_epi32 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPSUBD, see Exceptions Type E4.

EVEX-encoded VPSUBB/W, see Exceptions Type E4.nb.

