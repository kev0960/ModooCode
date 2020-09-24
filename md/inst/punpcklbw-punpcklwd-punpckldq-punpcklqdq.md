----------------------------
title : PUNPCKLBW, PUNPCKLWD, PUNPCKLDQ, PUNPCKLQDQs (Intel x86/64 assembly instruction)
cat_title : PUNPCKLBW, PUNPCKLWD, PUNPCKLDQ, PUNPCKLQDQ
ref_title : PUNPCKLBW, PUNPCKLWD, PUNPCKLDQ, PUNPCKLQDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PUNPCKLBW, PUNPCKLWD, PUNPCKLDQ, PUNPCKLQDQ

**Unpack Low Data**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 60 /r\footnote{1}`\newline{}`PUNPCKLBW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m32}{MMX 레지스터의 하위 32 비트 혹은 32 비트 메모리 데이터.} |RM|V/V|MMX|Interleave low-order bytes from mm and mm/m32 into mm.|
|`66 0F 60 /r`\newline{}`PUNPCKLBW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Interleave low-order bytes from xmm1 and xmm2/m128 into xmm1.|
|`0F 61 /r\footnote{1}`\newline{}`PUNPCKLWD` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m32}{MMX 레지스터의 하위 32 비트 혹은 32 비트 메모리 데이터.} |RM|V/V|MMX|Interleave low-order words from mm and mm/m32 into mm.|
|`66 0F 61 /r`\newline{}`PUNPCKLWD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Interleave low-order words from xmm1 and xmm2/m128 into xmm1.|
|`0F 62 /r\footnote{1}`\newline{}`PUNPCKLDQ` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m32}{MMX 레지스터의 하위 32 비트 혹은 32 비트 메모리 데이터.} |RM|V/V|MMX|Interleave low-order doublewords from mm and mm/m32 into mm.|
|`66 0F 62 /r`\newline{}`PUNPCKLDQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Interleave low-order doublewords from xmm1 and xmm2/m128 into xmm1.|
|`66 0F 6C /r`\newline{}`PUNPCKLQDQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Interleave low-order quadword from xmm1 and xmm2/m128 into xmm1 register.|
|`VEX.NDS.128.66.0F.WIG 60/r`\newline{}VPUNPCKLBW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Interleave low-order bytes from xmm2 and xmm3/m128 into xmm1.|
|`VEX.NDS.128.66.0F.WIG 61/r`\newline{}VPUNPCKLWD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Interleave low-order words from xmm2 and xmm3/m128 into xmm1.|
|`VEX.NDS.128.66.0F.WIG 62/r`\newline{}VPUNPCKLDQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Interleave low-order doublewords from xmm2 and xmm3/m128 into xmm1.|
|`VEX.NDS.128.66.0F.WIG 6C/r`\newline{}VPUNPCKLQDQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Interleave low-order quadword from xmm2 and xmm3/m128 into xmm1 register.|
|`VEX.NDS.256.66.0F.WIG 60 /r`\newline{}VPUNPCKLBW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Interleave low-order bytes from ymm2 and ymm3/m256 into ymm1 register.|
|`VEX.NDS.256.66.0F.WIG 61 /r`\newline{}VPUNPCKLWD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Interleave low-order words from ymm2 and ymm3/m256 into ymm1 register.|
|`VEX.NDS.256.66.0F.WIG 62 /r`\newline{}VPUNPCKLDQ \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Interleave low-order doublewords from ymm2 and ymm3/m256 into ymm1 register.|
|`VEX.NDS.256.66.0F.WIG 6C /r`\newline{}VPUNPCKLQDQ \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Interleave low-order quadword from ymm2 and ymm3/m256 into ymm1 register.|
|`EVEX.NDS.128.66.0F.WIG 60 /r`\newline{}VPUNPCKLBW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Interleave low-order bytes from xmm2 and xmm3/m128 into xmm1 register subject to write mask k1.|
|`EVEX.NDS.128.66.0F.WIG 61 /r`\newline{}VPUNPCKLWD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Interleave low-order words from xmm2 and xmm3/m128 into xmm1 register subject to write mask k1.|
|`EVEX.NDS.128.66.0F.W0 62 /r`\newline{}VPUNPCKLDQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst |FV|V/V|AVX512VL\newline{}AVX512F|Interleave low-order doublewords from xmm2 and xmm3/m128/m32bcst into xmm1 register subject to write mask k1.|
|`EVEX.NDS.128.66.0F.W1 6C /r`\newline{}VPUNPCKLQDQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m64bcst |FV|V/V|AVX512VL\newline{}AVX512F|Interleave low-order quadword from zmm2 and zmm3/m512/m64bcst into zmm1 register subject to write mask k1.|


|EVEX.NDS.256.66.0F.WIG 60 /r\newline{}VPUNPCKLBW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}\newline{}AVX512BW|Interleave low-order bytes from ymm2 and \newline{}ymm3/m256 into ymm1 register subject to \newline{}write mask k1.|
|------------------------------------------------------------------------------|---|---|------------------------------------|-------------------------------------------------------------------------------------------------------------------|
|EVEX.NDS.256.66.0F.WIG 61 /rVPUNPCKLWD ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Interleave low-order words from ymm2 and ymm3/m256 into ymm1 register subject to write mask k1.|
|EVEX.NDS.256.66.0F.W0 62 /rVPUNPCKLDQ ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Interleave low-order doublewords from ymm2 and ymm3/m256/m32bcst into ymm1 register subject to write mask k1.|
|EVEX.NDS.256.66.0F.W1 6C /rVPUNPCKLQDQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VL\newline{}AVX512F|Interleave low-order quadword from ymm2 and ymm3/m256/m64bcst into ymm1 register subject to write mask k1.|
|EVEX.NDS.512.66.0F.WIG 60/rVPUNPCKLBW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Interleave low-order bytes from zmm2 and zmm3/m512 into zmm1 register subject to write mask k1.|
|EVEX.NDS.512.66.0F.WIG 61/rVPUNPCKLWD zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Interleave low-order words from zmm2 and zmm3/m512 into zmm1 register subject to write mask k1.|
|EVEX.NDS.512.66.0F.W0 62 /rVPUNPCKLDQ zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Interleave low-order doublewords from zmm2 and zmm3/m512/m32bcst into zmm1 register subject to write mask k1.|
|EVEX.NDS.512.66.0F.W1 6C /rVPUNPCKLQDQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Interleave low-order quadword from zmm2 and zmm3/m512/m64bcst into zmm1 register subject to write mask k1.|

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


Unpacks and interleaves the low-order data elements (bytes, words, doublewords, and quadwords) of the destina-tion operand (first operand) and source operand (second operand) into the destination operand. (Figure 4-22 shows the unpack operation for bytes in 64-bit operands.). The high-order data elements are ignored.

```embed
<figure>
<svg viewBox="0 0 379.679993 189.059998">
<rect x="0.000000" y="10.059998" width="0.480000" height="98.879997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.059998" width="0.479980" height="98.879997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="108.940002" width="379.679993" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.740005" y="84.100037" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="166.740005" y="83.860046" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.500000" y="84.100037" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.500015" y="101.859985" width="144.240005" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.500015" y="83.860046" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.319992" y="83.860046" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.319992" y="84.100037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.379990" y="83.860046" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.379990" y="84.100037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.440002" y="83.860046" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.440002" y="84.100037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.500000" y="83.860046" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.500000" y="84.100037" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="220.500015" y="83.860046" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="220.500015" y="84.100037" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="256.500000" y="83.860046" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="256.500000" y="84.100037" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="184.500015" y="83.860046" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="184.500015" y="84.100037" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="197.939987" y="21.400024" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="197.939987" y="21.160034" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="341.700012" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="197.699997" y="39.160034" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="197.699997" y="21.160034" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="233.520004" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="233.520004" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.580017" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.580017" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.640015" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.640015" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.700012" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.700012" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.699997" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.699997" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.699997" y="21.160034" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.699997" y="21.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="35.699997" y="21.460022" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="35.699997" y="21.220032" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="179.460007" y="21.460022" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="35.460007" y="39.220032" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="35.460007" y="21.220032" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.279999" y="21.220032" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.279999" y="21.460022" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="107.339996" y="21.220032" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="107.339996" y="21.460022" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.399994" y="21.220032" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.399994" y="21.460022" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="161.460007" y="21.220032" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="161.460007" y="21.460022" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.460007" y="21.220032" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.460007" y="21.460022" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="125.460007" y="21.220032" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="125.460007" y="21.460022" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.460007" y="21.220032" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.460007" y="21.460022" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M200.340012,80.680054 L200.100021,80.200073 L199.199997,80.680054 L199.440018,81.160034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.680008,80.560059 L200.880020,81.700073 L201.660019,82.360046 L200.580002,82.540039 L195.120010,83.680054 L193.440018,84.040039 L194.699997,82.840088 L198.720016,78.940063 L199.440018,78.220032 L199.560013,79.240051 L199.380020,79.660034 L195.360001,83.560059 L194.699997,82.840088 L194.940018,82.720032 L200.400009,81.580078 L200.580002,82.540039 L200.160019,82.360046 L198.960007,81.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.560013,79.240051 L199.800003,80.860046 L198.960007,81.220032 L198.840012,81.100037 L198.840012,80.980042 L198.600021,79.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.319992,80.920044 L200.520004,82.060059 L195.059982,83.200073 L199.080002,79.300049" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.140015,40.480042 L277.320007,40.360046 L277.080017,39.940063 L276.900024,40.060059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M200.340012,80.680054 L200.160019,80.800049 L199.919998,80.380066 L200.100021,80.260071" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.140015,40.480042 L276.900024,40.060059 L200.099991,80.260010 L200.339981,80.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.860001,79.960022 L235.620010,79.600037 L234.719986,80.200012 L234.960007,80.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.139999,79.960022 L236.460007,80.920044 L237.360001,81.520020 L236.280014,81.820007 L230.939987,83.500000 L229.259995,84.040039 L230.400009,82.720032 L234.060013,78.460022 L234.780014,77.619995 L234.960007,78.640015 L234.840012,79.119995 L231.180008,83.380005 L230.400009,82.720032 L230.639999,82.540039 L235.979996,80.860046 L236.280014,81.820007 L235.860001,81.760010 L234.539993,80.800049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.960007,78.640015 L235.319992,80.260010 L234.539993,80.799988 L234.360001,80.679993 L234.360001,80.500000 L234.000015,78.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.840012,80.380005 L236.160019,81.340027 L230.820023,83.020020 L234.480026,78.760010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.859985,40.480042 L296.039978,40.360046 L295.799988,39.940063 L295.619995,40.060059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.860001,80.020020 L235.680008,80.140015 L235.439987,79.720032 L235.620010,79.600037" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.859985,40.480042 L295.619995,40.060059 L235.620010,79.600037 L235.860001,80.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M271.619995,79.000000 L271.260010,78.640015 L270.479980,79.359985 L270.840027,79.719971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.900024,79.060059 L272.340027,79.840088 L273.239990,80.320068 L272.280029,80.800049 L267.299988,83.260071 L265.739990,84.040039 L266.640015,82.540039 L269.580017,77.800049 L270.179993,76.900085 L270.540039,77.860046 L270.479980,78.340088 L267.540039,83.080078 L266.640015,82.540039 L266.880005,82.360046 L271.859985,79.900085 L272.280029,80.800049 L271.859985,80.800049 L270.419983,80.020081" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.539978,77.860046 L271.140015,79.360046 L270.419983,80.020020 L270.239990,79.900024 L270.179993,79.720032 L269.580017,78.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.659973,79.540039 L272.099976,80.320068 L267.119995,82.780029 L270.059998,78.040039" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M314.700012,39.880005 L314.880005,39.760010 L314.580017,39.400024 L314.400024,39.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M271.619995,79.000000 L271.440002,79.119995 L271.140015,78.760010 L271.320007,78.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M314.700012,39.880005 L314.400024,39.520020 L271.320007,78.640015 L271.619995,79.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M305.280029,77.920044 L304.920044,77.680054 L304.320007,78.520020 L304.679993,78.760071" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M304.619995,78.160034 L306.179993,78.640015 L307.200012,78.880005 L306.359985,79.540039 L301.919983,82.960022 L300.540039,84.040039 L301.140015,82.420044 L303.059998,77.200012 L303.419983,76.240051 L303.900024,77.020020 L304.020020,77.500061 L302.100037,82.720032 L301.140015,82.420044 L301.320007,82.180054 L305.760010,78.760010 L306.359985,79.540039 L305.880005,79.600037 L304.320007,79.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.900024,77.020020 L304.859985,78.340027 L304.320007,79.119995 L304.200012,79.059998 L304.080017,78.940002 L303.119995,77.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M304.500000,78.640015 L306.059998,79.119995 L301.619995,82.540039 L303.540039,77.320007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M332.880005,39.880005 L333.000000,39.700012 L332.640015,39.400024 L332.520020,39.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M305.280029,77.980042 L305.160034,78.160034 L304.799988,77.860046 L304.920044,77.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M332.880005,39.880005 L332.520020,39.580017 L304.919983,77.679993 L305.279968,77.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.840027,80.980042 L276.720032,81.460022 L277.739990,81.880066 L277.859985,81.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.260010,81.640015 L277.260010,79.960022 L277.320007,78.940002 L278.159973,79.600037 L282.659973,83.020020 L284.099976,84.100037 L282.299988,83.920044 L276.719971,83.380005 L275.640015,83.260010 L276.359985,82.480042 L276.779968,82.359985 L282.359985,82.900024 L282.299988,83.920044 L282.000000,83.799988 L277.500000,80.380005 L278.159973,79.600037 L278.339966,79.960022 L278.339966,81.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.359985,82.480042 L277.440002,81.280029 L278.340027,81.640015 L278.280029,81.820068 L278.159973,82.000061 L277.080017,83.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.799988,81.640015 L277.799988,79.960022 L282.299988,83.380005 L276.720032,82.840027" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.439987,39.520020 L169.259995,39.460022 L169.080002,39.880005 L169.259995,39.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.900024,81.040039 L277.080017,81.100037 L276.900024,81.520020 L276.720032,81.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.439987,39.520020 L169.259995,39.940002 L276.719971,81.460022 L276.899963,81.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.180008,80.560059 L239.940018,81.040039 L240.900009,81.460083 L241.139999,80.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.479996,81.160034 L240.599991,79.540039 L240.719986,78.520020 L241.499985,79.240051 L245.699997,82.900024 L247.020004,84.040039 L245.279984,83.800049 L239.759995,82.900024 L238.740005,82.720032 L239.460007,82.000061 L239.939987,81.880005 L245.460007,82.780029 L245.279984,83.800049 L245.039993,83.620056 L240.839981,79.960022 L241.499985,79.240051 L241.680008,79.660034 L241.559982,81.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.460007,82.000000 L240.660019,80.859985 L241.560013,81.280029 L241.500015,81.460022 L241.380020,81.580017 L240.180008,82.719971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M241.020004,81.220032 L241.139999,79.600037 L245.340012,83.260010 L239.819992,82.360046" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.740005,39.400024 L151.560013,39.340027 L151.380020,39.760010 L151.560013,39.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.180008,80.620056 L240.360001,80.680054 L240.180008,81.100037 L240.000015,81.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.740005,39.400024 L151.560013,39.820007 L240.000015,81.040039 L240.180008,80.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.599991,80.500000 L204.360001,80.859985 L205.259995,81.400024 L205.499985,81.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.900009,81.160034 L205.199997,79.540039 L205.320023,78.520020 L206.100021,79.300049 L209.940018,83.320007 L211.080002,84.520020 L209.460007,84.100037 L204.060013,82.780029 L202.979996,82.540039 L203.820023,81.880005 L204.240005,81.820007 L209.639999,83.140015 L209.460007,84.100037 L209.160019,83.980042 L205.320023,79.960022 L206.100021,79.300049 L206.160019,79.660034 L205.860001,81.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M203.819992,81.880005 L205.080002,80.799988 L205.860001,81.280029 L205.860001,81.520020 L205.679977,81.640015 L204.419998,82.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.379990,81.220032 L205.679977,79.600037 L209.520004,83.620056 L204.119980,82.300049" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.639999,39.940002 L134.460007,39.820007 L134.220001,40.239990 L134.399994,40.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.599991,80.500000 L204.779984,80.619995 L204.539993,81.039978 L204.360001,80.919983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.639999,39.940002 L134.399994,40.359985 L204.360001,80.919983 L204.599991,80.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.199997,79.180054 L168.960007,79.540039 L169.800003,80.200073 L170.039993,79.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.439987,79.900024 L169.919998,78.340027 L170.159988,77.320007 L170.819992,78.160034 L174.179977,82.600037 L175.199997,83.980042 L173.639999,83.380005 L168.419998,81.400024 L167.399979,81.040039 L168.239975,80.500000 L168.719986,80.440002 L173.939987,82.420044 L173.639999,83.380005 L173.399979,83.200012 L170.039993,78.760010 L170.819992,78.160034 L170.879990,78.580017 L170.399979,80.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M168.240005,80.500000 L169.620010,79.599976 L170.400009,80.140015 L170.340012,80.320007 L170.220016,80.440002 L168.840012,81.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.919998,80.020020 L170.400009,78.460022 L173.759995,82.900024 L168.539993,80.920044" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M117.539993,40.060059 L117.360001,39.940063 L117.059998,40.300049 L117.239990,40.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.259995,79.180054 L169.439987,79.300049 L169.139999,79.660034 L168.960007,79.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M117.539993,40.060059 L117.239990,40.420044 L168.959976,79.540039 L169.259995,79.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="154.269058" y="95.561401" textLength="5.329997" font-size="8px">S</text>
<text x="148.934280" y="95.561401" textLength="5.329997" font-size="8px">E</text>
<text x="349.993408" y="33.101318" textLength="5.329997" font-size="8px">E</text>
<text x="344.219116" y="33.101318" textLength="5.769502" font-size="8px">D</text>
<text x="27.538986" y="32.740906" textLength="5.769502" font-size="8px">C</text>
<text x="21.739914" y="32.740906" textLength="5.769502" font-size="8px">R</text>
<text x="76.197800" y="33.700623" textLength="5.329997" font-size="8px">Y</text>
<text x="62.279068" y="33.700623" textLength="4.442996" font-size="8px">6</text>
<text x="56.938675" y="33.700623" textLength="5.329997" font-size="8px">Y</text>
<text x="93.240189" y="33.700623" textLength="5.329997" font-size="8px">Y</text>
<text x="225.178024" y="33.040588" textLength="4.442996" font-size="8px">6</text>
<text x="219.837631" y="33.040588" textLength="5.329997" font-size="8px">X</text>
<text x="208.018936" y="33.040588" textLength="4.442996" font-size="8px">7</text>
<text x="148.018509" y="34.240845" textLength="5.329997" font-size="8px">Y</text>
<text x="134.099777" y="34.240845" textLength="4.442996" font-size="8px">2</text>
<text x="128.759384" y="34.240845" textLength="5.329997" font-size="8px">Y</text>
<text x="315.718445" y="33.100525" textLength="4.442996" font-size="8px">1</text>
<text x="310.378052" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="296.459351" y="33.100525" textLength="4.442996" font-size="8px">2</text>
<text x="291.118958" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="279.360168" y="33.100525" textLength="4.442996" font-size="8px">3</text>
<text x="274.019775" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="247.499283" y="95.380005" textLength="4.442996" font-size="8px">1</text>
<text x="242.158890" y="95.380005" textLength="5.329997" font-size="8px">Y</text>
<text x="176.340988" y="95.380005" textLength="4.442996" font-size="8px">3</text>
<text x="277.380005" y="95.380005" textLength="5.329997" font-size="8px">Y</text>
<text x="230.459396" y="95.380005" textLength="4.442996" font-size="8px">2</text>
<text x="225.119003" y="95.380005" textLength="5.329997" font-size="8px">X</text>
<text x="193.980484" y="95.380005" textLength="4.442996" font-size="8px">3</text>
<text x="188.700821" y="95.380005" textLength="5.329997" font-size="8px">X</text>
<text x="302.040405" y="95.380005" textLength="4.442996" font-size="8px">0</text>
<text x="296.700012" y="95.380005" textLength="5.329997" font-size="8px">X</text>
<text x="143.159973" y="95.561401" textLength="5.769502" font-size="8px">D</text>
<text x="206.340012" y="95.380005" textLength="5.329997" font-size="8px">Y</text>
<text x="39.840332" y="33.700623" textLength="5.329997" font-size="8px">Y</text>
<text x="327.419617" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="282.720398" y="95.380005" textLength="4.442996" font-size="8px">0</text>
<text x="81.477448" y="33.700623" textLength="4.442996" font-size="8px">5</text>
<text x="117.000626" y="34.240845" textLength="4.442996" font-size="8px">3</text>
<text x="111.660248" y="34.240845" textLength="5.329997" font-size="8px">Y</text>
<text x="332.760010" y="33.100525" textLength="4.442996" font-size="8px">0</text>
<text x="360.662964" y="33.101318" textLength="4.882501" font-size="8px">T</text>
<text x="355.328186" y="33.101318" textLength="5.329997" font-size="8px">S</text>
<text x="211.680405" y="95.380005" textLength="4.442996" font-size="8px">2</text>
<text x="265.738098" y="95.380005" textLength="4.442996" font-size="8px">1</text>
<text x="256.139099" y="33.040588" textLength="5.329997" font-size="8px">X</text>
<text x="45.119980" y="33.700623" textLength="4.442996" font-size="8px">7</text>
<text x="153.298172" y="34.240845" textLength="4.442996" font-size="8px">1</text>
<text x="244.376419" y="33.040588" textLength="4.442996" font-size="8px">5</text>
<text x="170.400497" y="34.240845" textLength="4.442996" font-size="8px">0</text>
<text x="159.603836" y="95.561401" textLength="4.882501" font-size="8px">T</text>
<text x="98.580582" y="33.700623" textLength="4.442996" font-size="8px">4</text>
<text x="202.739273" y="33.040588" textLength="5.329997" font-size="8px">X</text>
<text x="171.000595" y="95.380005" textLength="5.329997" font-size="8px">Y</text>
<text x="261.479492" y="33.040588" textLength="4.442996" font-size="8px">4</text>
<text x="16.380356" y="32.740906" textLength="5.329997" font-size="8px">S</text>
<text x="239.096756" y="33.040588" textLength="5.329997" font-size="8px">X</text>
<text x="165.060104" y="34.240845" textLength="5.329997" font-size="8px">Y</text>
<text x="260.397705" y="95.380005" textLength="5.329997" font-size="8px">X</text>
</svg>
<figcaption>Figure 4-22.  PUNPCKLBW Instruction Operation Using 64-bit Operands
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 326.207245 156.239990">
<rect x="150.359650" y="78.159760" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="150.359650" y="77.919800" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.119659" y="78.159790" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.119659" y="95.919769" width="144.240005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.119659" y="77.919769" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="185.939636" y="77.919769" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.999634" y="77.919769" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="258.059631" y="77.919769" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="276.119659" y="77.919769" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.119659" y="77.919769" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.119659" y="77.919769" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.119659" y="77.919769" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.559631" y="15.459778" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="181.559631" y="15.219727" width="144.240005" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.319641" y="15.459778" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.319641" y="33.219788" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.319641" y="15.219788" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.139648" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.199646" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.259644" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.319641" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.319641" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.319641" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.319641" y="15.219788" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.319641" y="15.519775" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="19.319641" y="15.279785" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.079651" y="15.519775" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.079651" y="33.279724" width="144.240005" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.079651" y="15.279785" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.899643" y="15.279785" width="0.480000" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.959641" y="15.279785" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="127.019638" y="15.279785" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.079651" y="15.279785" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="73.079651" y="15.279785" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.079651" y="15.279785" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="37.079651" y="15.279785" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.939636,73.119781 L182.579651,72.759796 L181.799622,73.419769 L182.159637,73.779785" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.219635,73.119781 L183.659637,73.899780 L184.559631,74.379791 L183.599640,74.859772 L178.559631,77.319794 L176.999634,78.099792 L177.899628,76.599792 L180.839630,71.859772 L181.379639,71.019775 L181.739624,71.859772 L181.739624,72.399780 L178.799622,77.139771 L177.899628,76.599792 L178.139648,76.419769 L183.179626,73.959778 L183.599640,74.859772 L183.179626,74.859772 L181.739624,74.079773" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M181.739655,71.859772 L182.399658,73.359772 L181.739655,74.079773 L181.559662,73.959778 L181.499664,73.779785 L180.839661,72.279785" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M181.979645,73.599762 L183.419647,74.379761 L178.379639,76.839752 L181.319641,72.099762" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.599640,34.419800 L225.779633,34.299805 L225.479645,33.939819 L225.299652,34.059814" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.939636,73.119781 L182.759644,73.239777 L182.459625,72.879791 L182.639648,72.759796" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.599640,34.419800 L225.299652,34.059814 L182.639648,72.759796 L182.939636,73.119812" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M217.799652,72.099762 L217.439667,71.859772 L216.839661,72.699768 L217.199646,72.939758" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M217.199646,72.339783 L218.759644,72.819794 L219.719635,73.059784 L218.879639,73.719788 L214.379639,77.079773 L212.999634,78.099792 L213.599640,76.479797 L215.639648,71.259796 L215.999634,70.299774 L216.539642,71.139771 L216.599640,71.619781 L214.559631,76.839783 L213.599640,76.479797 L213.779633,76.299774 L218.279633,72.939789 L218.879639,73.719788 L218.399658,73.779785 L216.839661,73.299774" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.539642,71.139771 L217.439636,72.519775 L216.839630,73.299774 L216.719635,73.239777 L216.599640,73.119781 L215.699646,71.739777" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M217.019653,72.819763 L218.579651,73.299774 L214.079651,76.659760 L216.119659,71.439758" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M245.999634,35.619751 L246.119629,35.439758 L245.759644,35.139771 L245.639648,35.319763" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M217.799652,72.159760 L217.679657,72.339752 L217.319641,72.039764 L217.439667,71.859772" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M245.999634,35.619751 L245.639648,35.319763 L217.439636,71.859741 L217.799622,72.159760" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M255.239655,73.059784 L254.879669,72.699799 L254.099640,73.419769 L254.459656,73.779785" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M254.519653,73.119781 L255.959656,73.899780 L256.859650,74.379791 L255.899658,74.859772 L250.919647,77.319794 L249.419647,78.039795 L250.259644,76.599792 L253.139648,71.859772 L253.679657,71.019775 L254.039642,71.859772 L254.039642,72.399780 L251.159668,77.139771 L250.259644,76.599792 L250.499664,76.419769 L255.479645,73.959778 L255.899658,74.859772 L255.479645,74.859772 L254.039642,74.079773" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M254.039642,71.859772 L254.699646,73.359772 L254.039642,74.079773 L253.859650,73.959778 L253.799652,73.779785 L253.139648,72.279785" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M254.279633,73.599762 L255.719635,74.379761 L250.739624,76.839752 L253.619629,72.099762" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M298.799652,33.219788 L298.979645,33.099792 L298.679657,32.739807 L298.499664,32.859802" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M255.239655,73.059784 L255.059662,73.179779 L254.759644,72.819794 L254.939667,72.699799" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M298.799652,33.219788 L298.499664,32.859802 L254.939667,72.699799 L255.239655,73.059784" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M289.199646,72.279785 L288.839661,71.919800 L288.179657,72.759796 L288.539642,73.119781" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.539642,72.459778 L290.099640,72.939789 L291.119629,73.179779 L290.159637,73.839783 L285.599640,77.079773 L284.219635,78.099792 L284.879639,76.479767 L287.039642,71.319763 L287.459656,70.359772 L287.939636,71.259766 L287.939636,71.679779 L285.779633,76.839783 L284.879639,76.479767 L285.059631,76.239777 L289.619629,72.999786 L290.159637,73.839783 L289.739655,73.899780 L288.179657,73.419769" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.939636,71.259766 L288.779633,72.699768 L288.179626,73.419769 L287.999634,73.359772 L287.939636,73.179779 L287.099640,71.739777" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.359650,72.939758 L289.919647,73.419769 L285.359650,76.659760 L287.519653,71.499756" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M319.199646,35.019775 L319.319641,34.839783 L318.959656,34.539795 L318.839661,34.719788" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M289.199646,72.279785 L289.079651,72.459778 L288.719635,72.159790 L288.839661,71.979797" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M319.199646,35.019775 L318.839661,34.719788 L288.839630,71.979767 L289.199646,72.279785" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.459656,75.039764 L260.339661,75.519775 L261.359650,75.939758 L261.479645,75.459778" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.879639,75.699768 L260.939636,74.019775 L260.999634,72.999756 L261.839630,73.659760 L266.279633,77.079773 L267.659637,78.099762 L265.919647,77.979767 L260.339630,77.439758 L259.259644,77.319763 L259.979645,76.539764 L260.399628,76.419769 L265.979645,76.959778 L265.919647,77.979767 L265.619629,77.859772 L261.179626,74.439758 L261.839630,73.659760 L262.019653,74.019775 L261.959625,75.699768" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.979645,76.539764 L261.059631,75.339752 L261.959656,75.699768 L261.899658,75.879761 L261.779633,76.059753 L260.699646,77.259766" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M261.419647,75.699768 L261.479645,74.019775 L265.919647,77.439758 L260.339661,76.899780" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M156.539642,34.659790 L156.359650,34.599792 L156.179657,35.019775 L156.359650,35.079773" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.519653,75.099762 L260.699646,75.159760 L260.519653,75.579773 L260.339661,75.519775" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M156.539642,34.659790 L156.359650,35.079773 L260.339630,75.519775 L260.519653,75.099792" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.739655,74.619781 L223.499664,75.099792 L224.459656,75.519775 L224.699646,75.039795" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.039642,75.219757 L224.219635,73.599762 L224.339630,72.579742 L225.119629,73.299744 L229.319641,76.959747 L230.639648,78.099762 L228.899628,77.859772 L223.379639,77.019745 L222.419647,76.839752 L223.079651,76.179749 L223.559631,75.999756 L229.079651,76.839752 L228.899628,77.859772 L228.659637,77.679749 L224.459656,74.019745 L225.119629,73.299744 L225.239655,73.779755 L225.059631,75.399750" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.079651,76.179779 L224.219666,74.979767 L225.059662,75.399780 L225.059662,75.579773 L224.939636,75.639771 L223.799652,76.839783" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.579651,75.279785 L224.759644,73.659790 L228.959656,77.319794 L223.439636,76.479797" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M136.739655,34.659790 L136.559662,34.599792 L136.379669,35.019775 L136.559662,35.079773" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.739655,74.679779 L223.919647,74.739777 L223.739655,75.159790 L223.559662,75.099792" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M136.739655,34.659790 L136.559662,35.079773 L223.559662,75.099792 L223.739655,74.679779" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.679657,75.519775 L187.559662,75.999786 L188.519653,76.419769 L188.639648,75.939789" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.039642,76.179779 L188.099640,74.499786 L188.099640,73.419769 L188.999634,74.139771 L193.439636,77.559784 L194.759644,78.579773 L193.079651,78.459778 L187.499634,77.919769 L186.419647,77.799774 L187.139648,77.019775 L187.559631,76.899780 L193.139648,77.439789 L193.079651,78.459778 L192.779633,78.339783 L188.339630,74.919769 L188.999634,74.139771 L189.179657,74.499786 L189.119629,76.179779" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.139648,77.019775 L188.219635,75.819763 L189.119659,76.179779 L189.059662,76.359772 L188.939636,76.539764 L187.859650,77.739777" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.579651,76.179779 L188.639648,74.499786 L193.079651,77.919769 L187.499664,77.379791" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M83.939651,34.059753 L83.759659,33.999756 L83.579651,34.419739 L83.759659,34.479736" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.739655,75.579773 L187.919647,75.639771 L187.739655,76.059784 L187.559662,75.999786" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M83.939651,34.059753 L83.759659,34.479736 L187.559662,75.999756 L187.739655,75.579742" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919647,74.679779 L151.679657,75.159790 L152.639648,75.639771 L152.879639,75.159790" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.219635,75.339783 L152.339630,73.659790 L152.399628,72.639771 L153.239624,73.359772 L157.559631,76.959778 L158.879639,78.099792 L157.139648,77.859772 L151.559631,77.079773 L150.539642,76.899780 L151.259644,76.179779 L151.679626,76.059784 L157.259644,76.839783 L157.139648,77.859772 L156.899628,77.679779 L152.579620,74.079773 L153.239624,73.359772 L153.419647,73.779785 L153.299622,75.459778" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.259644,76.179779 L152.399658,75.039764 L153.299652,75.459778 L153.239655,75.639771 L151.979645,76.899780" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.759644,75.399780 L152.879639,73.719788 L157.199646,77.319794 L151.619629,76.539795" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.539642,35.259766 L63.359650,35.199768 L63.179642,35.619751 L63.359650,35.679749" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919647,74.739777 L152.099640,74.799774 L151.919647,75.219788 L151.739655,75.159790" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.539642,35.259766 L63.359650,35.679749 L151.739655,75.159760 L151.919647,74.739777" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="145.318787" y="10.000000" textLength="3.887607" font-size="8px">3</text>
<text x="152.216492" y="72.219879" textLength="3.887607" font-size="8px">5</text>
<text x="148.377838" y="72.219879" textLength="3.887607" font-size="8px">5</text>
<text x="144.479034" y="72.219879" textLength="3.887607" font-size="8px">2</text>
<text x="23.216461" y="11.020142" textLength="3.887607" font-size="8px">5</text>
<text x="19.377792" y="11.020142" textLength="3.887607" font-size="8px">5</text>
<text x="292.919250" y="72.999481" textLength="3.887607" font-size="8px">0</text>
<text x="312.778229" y="11.619324" textLength="3.887607" font-size="8px">1</text>
<text x="308.879425" y="11.619324" textLength="3.887607" font-size="8px">3</text>
<text x="182.938416" y="11.439636" textLength="3.887607" font-size="8px">5</text>
<text x="179.099762" y="11.439636" textLength="3.887607" font-size="8px">2</text>
<text x="322.319641" y="11.799744" textLength="3.887607" font-size="8px">0</text>
<text x="137.888702" y="89.620300" textLength="5.329997" font-size="8px">S</text>
<text x="132.553925" y="89.620300" textLength="5.329997" font-size="8px">E</text>
<text x="126.779617" y="89.620300" textLength="5.769502" font-size="8px">D</text>
<text x="5.359558" y="26.800659" textLength="5.769502" font-size="8px">R</text>
<text x="65.097092" y="27.760376" textLength="4.442996" font-size="8px">5</text>
<text x="59.817444" y="27.760376" textLength="5.329997" font-size="8px">Y</text>
<text x="45.898712" y="27.760376" textLength="4.442996" font-size="8px">6</text>
<text x="40.558319" y="27.760376" textLength="5.329997" font-size="8px">Y</text>
<text x="28.739624" y="27.760376" textLength="4.442996" font-size="8px">7</text>
<text x="23.459976" y="27.760376" textLength="5.329997" font-size="8px">Y</text>
<text x="82.200226" y="27.760376" textLength="4.442996" font-size="8px">4</text>
<text x="76.859833" y="27.760376" textLength="5.329997" font-size="8px">Y</text>
<text x="227.996063" y="27.100342" textLength="4.442996" font-size="8px">5</text>
<text x="208.797668" y="27.100342" textLength="4.442996" font-size="8px">6</text>
<text x="191.638580" y="27.100342" textLength="4.442996" font-size="8px">7</text>
<text x="245.099152" y="27.100342" textLength="4.442996" font-size="8px">4</text>
<text x="239.758759" y="27.100342" textLength="5.329997" font-size="8px">X</text>
<text x="136.917816" y="28.300598" textLength="4.442996" font-size="8px">1</text>
<text x="117.719421" y="28.300598" textLength="4.442996" font-size="8px">2</text>
<text x="112.379028" y="28.300598" textLength="5.329997" font-size="8px">Y</text>
<text x="148.679749" y="28.300598" textLength="5.329997" font-size="8px">Y</text>
<text x="299.338104" y="27.160278" textLength="4.442996" font-size="8px">1</text>
<text x="293.997711" y="27.160278" textLength="5.329997" font-size="8px">X</text>
<text x="195.239319" y="89.439758" textLength="4.442996" font-size="8px">4</text>
<text x="189.959656" y="89.439758" textLength="5.329997" font-size="8px">Y</text>
<text x="159.960632" y="89.439758" textLength="4.442996" font-size="8px">5</text>
<text x="266.340027" y="89.439758" textLength="4.442996" font-size="8px">0</text>
<text x="249.358551" y="89.439758" textLength="4.442996" font-size="8px">1</text>
<text x="177.660858" y="89.439758" textLength="4.442996" font-size="8px">5</text>
<text x="285.660034" y="89.439758" textLength="4.442996" font-size="8px">0</text>
<text x="280.319641" y="89.439758" textLength="5.329997" font-size="8px">X</text>
<text x="161.099274" y="10.239807" textLength="3.887607" font-size="8px">0</text>
<text x="186.837219" y="11.439636" textLength="3.887607" font-size="8px">5</text>
<text x="208.739471" y="89.439758" textLength="5.329997" font-size="8px">X</text>
<text x="311.039276" y="27.160278" textLength="5.329997" font-size="8px">X</text>
<text x="260.999634" y="89.439758" textLength="5.329997" font-size="8px">Y</text>
<text x="225.777740" y="89.439758" textLength="5.329997" font-size="8px">Y</text>
<text x="100.620270" y="28.300598" textLength="4.442996" font-size="8px">3</text>
<text x="280.078979" y="27.160278" textLength="4.442996" font-size="8px">2</text>
<text x="257.639435" y="27.160278" textLength="5.329997" font-size="8px">X</text>
<text x="131.638153" y="28.300598" textLength="5.329997" font-size="8px">Y</text>
<text x="274.738586" y="27.160278" textLength="5.329997" font-size="8px">X</text>
<text x="143.223480" y="89.620300" textLength="4.882501" font-size="8px">T</text>
<text x="15.479004" y="11.020142" textLength="3.887607" font-size="8px">2</text>
<text x="11.158630" y="26.800659" textLength="5.769502" font-size="8px">C</text>
<text x="154.620239" y="89.439758" textLength="5.329997" font-size="8px">Y</text>
<text x="316.379669" y="27.160278" textLength="4.442996" font-size="8px">0</text>
<text x="95.279892" y="28.300598" textLength="5.329997" font-size="8px">Y</text>
<text x="214.079865" y="89.439758" textLength="4.442996" font-size="8px">4</text>
<text x="222.716400" y="27.100342" textLength="5.329997" font-size="8px">X</text>
<text x="231.118134" y="89.439758" textLength="4.442996" font-size="8px">1</text>
<text x="172.320465" y="89.439758" textLength="5.329997" font-size="8px">X</text>
<text x="244.018158" y="89.439758" textLength="5.329997" font-size="8px">X</text>
<text x="0.000000" y="26.800659" textLength="5.329997" font-size="8px">S</text>
<text x="203.457275" y="27.100342" textLength="5.329997" font-size="8px">X</text>
<text x="186.358917" y="27.100342" textLength="5.329997" font-size="8px">X</text>
<text x="154.020142" y="28.300598" textLength="4.442996" font-size="8px">0</text>
<text x="149.217590" y="10.000000" textLength="3.887607" font-size="8px">1</text>
<text x="262.979828" y="27.160278" textLength="4.442996" font-size="8px">3</text>
</svg>
<figcaption>Figure 4-23.  256-bit VPUNPCKLDQ Instruction Operation
</figcaption></figure>
```


When the source data comes from a 128-bit memory operand, an implementation may fetch only the appropriate 64 bits; however, alignment to a 16-byte boundary and normal segment checking will still be enforced.

The (V)PUNPCKLBW instruction interleaves the low-order bytes of the source and destination operands, the (V)PUNPCKLWD instruction interleaves the low-order words of the source and destination operands, the (V)PUNPCKLDQ instruction interleaves the low-order doubleword (or doublewords) of the source and destination operands, and the (V)PUNPCKLQDQ instruction interleaves the low-order quadwords of the source and destination operands.

These instructions can be used to convert bytes to words, words to doublewords, doublewords to quadwords, and quadwords to double quadwords, respectively, by placing all 0s in the source operand. Here, if the source operand contains all 0s, the result (stored in the destination operand) contains zero extensions of the high-order data elements from the original value in the destination operand. For example, with the (V)PUNPCKLBW instruction the high-order bytes are zero extended (that is, unpacked into unsigned word integers), and with the (V)PUNPCKLWD instruction, the high-order words are zero extended (unpacked into unsigned doubleword integers).

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE versions 64-bit operand: The source operand can be an MMX technology register or a 32-bit memory location. The destination operand is an MMX technology register. 

128-bit Legacy SSE versions: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded versions: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. Bits (MAX_VL-1:256) of the corresponding ZMM register are zeroed.



EVEX encoded VPUNPCKLDQ/QDQ: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is conditionally updated with writemask k1.

EVEX encoded VPUNPCKLWD/BW: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is conditionally updated with writemask k1.


### Operation
#### PUNPCKLBW instruction with 64-bit operands:
```info-verb
    DEST[63:56] <- SRC[31:24];
    DEST[55:48] <- DEST[31:24];
    DEST[47:40] <- SRC[23:16];
    DEST[39:32] <- DEST[23:16];
    DEST[31:24] <- SRC[15:8];
    DEST[23:16] <- DEST[15:8];
    DEST[15:8] <- SRC[7:0];
    DEST[7:0] <- DEST[7:0];
```
#### PUNPCKLWD instruction with 64-bit operands:
```info-verb
    DEST[63:48] <- SRC[31:16];
    DEST[47:32] <- DEST[31:16];
    DEST[31:16] <- SRC[15:0];
    DEST[15:0] <- DEST[15:0];
```
#### PUNPCKLDQ instruction with 64-bit operands:
```info-verb
    DEST[63:32] <- SRC[31:0];
    DEST[31:0] <- DEST[31:0];
INTERLEAVE_BYTES_512b (SRC1, SRC2)
TMP_DEST[255:0] <-  INTERLEAVE_BYTES_256b(SRC1[255:0], SRC[255:0])
TMP_DEST[511:256] <-  INTERLEAVE_BYTES_256b(SRC1[511:256], SRC[511:256])
INTERLEAVE_BYTES_256b (SRC1, SRC2) 
DEST[7:0] <-  SRC1[7:0]
DEST[15:8] <-  SRC2[7:0]
DEST[23:16] <-  SRC1[15:8]
DEST[31:24] <-  SRC2[15:8]
DEST[39:32] <-  SRC1[23:16]
DEST[47:40] <-  SRC2[23:16]
DEST[55:48] <-  SRC1[31:24]
DEST[63:56] <-  SRC2[31:24]
DEST[71:64] <-  SRC1[39:32]
DEST[79:72] <-  SRC2[39:32]
DEST[87:80] <-  SRC1[47:40]
DEST[95:88] <-  SRC2[47:40]
DEST[103:96] <-  SRC1[55:48]
DEST[111:104] <-  SRC2[55:48]
DEST[119:112] <-  SRC1[63:56]
DEST[127:120] <-  SRC2[63:56]
DEST[135:128] <-  SRC1[135:128]
DEST[143:136] <-  SRC2[135:128]
DEST[151:144] <-  SRC1[143:136]
DEST[159:152] <-  SRC2[143:136]
DEST[167:160] <-  SRC1[151:144]
DEST[175:168] <-  SRC2[151:144]
DEST[183:176] <-  SRC1[159:152]
DEST[191:184] <-  SRC2[159:152]
DEST[199:192] <-  SRC1[167:160]
DEST[207:200] <-  SRC2[167:160]
DEST[215:208] <-  SRC1[175:168]
DEST[223:216] <-  SRC2[175:168]
DEST[231:224] <-  SRC1[183:176]
DEST[239:232] <-  SRC2[183:176]
DEST[247:240] <-  SRC1[191:184]
DEST[255:248] <-  SRC2[191:184]
INTERLEAVE_BYTES (SRC1, SRC2) 
DEST[7:0] <-  SRC1[7:0]
DEST[15:8] <-  SRC2[7:0]
DEST[23:16] <-  SRC2[15:8]
DEST[31:24] <-  SRC2[15:8]
DEST[39:32] <-  SRC1[23:16]
DEST[47:40] <-  SRC2[23:16]
DEST[55:48] <-  SRC1[31:24]
DEST[63:56] <-  SRC2[31:24]
DEST[71:64] <-  SRC1[39:32]
DEST[79:72] <-  SRC2[39:32]
DEST[87:80] <-  SRC1[47:40]
DEST[95:88] <-  SRC2[47:40]
DEST[103:96] <-  SRC1[55:48]
DEST[111:104] <-  SRC2[55:48]
DEST[119:112] <-  SRC1[63:56]
DEST[127:120] <-  SRC2[63:56]
INTERLEAVE_WORDS_512b (SRC1, SRC2)
TMP_DEST[255:0] <-  INTERLEAVE_WORDS_256b(SRC1[255:0], SRC[255:0])
TMP_DEST[511:256] <-  INTERLEAVE_WORDS_256b(SRC1[511:256], SRC[511:256])
INTERLEAVE_WORDS_256b(SRC1, SRC2)
DEST[15:0] <-  SRC1[15:0]
DEST[31:16] <-  SRC2[15:0]
DEST[47:32] <-  SRC1[31:16]
DEST[63:48] <-  SRC2[31:16]
DEST[79:64] <-  SRC1[47:32]
DEST[95:80] <-  SRC2[47:32]
DEST[111:96] <-  SRC1[63:48]
DEST[127:112] <-  SRC2[63:48]
DEST[143:128] <-  SRC1[143:128]
DEST[159:144] <-  SRC2[143:128]
DEST[175:160] <-  SRC1[159:144]
DEST[191:176] <-  SRC2[159:144]
DEST[207:192] <-  SRC1[175:160]
DEST[223:208] <-  SRC2[175:160]
DEST[239:224] <-  SRC1[191:176]
DEST[255:240] <-  SRC2[191:176]
INTERLEAVE_WORDS (SRC1, SRC2)
DEST[15:0] <-  SRC1[15:0]
DEST[31:16] <-  SRC2[15:0]
DEST[47:32] <-  SRC1[31:16]
DEST[63:48] <-  SRC2[31:16]
DEST[79:64] <-  SRC1[47:32]
DEST[95:80] <-  SRC2[47:32]
DEST[111:96] <-  SRC1[63:48]
DEST[127:112] <-  SRC2[63:48]
INTERLEAVE_DWORDS_512b (SRC1, SRC2)
TMP_DEST[255:0] <-  INTERLEAVE_DWORDS_256b(SRC1[255:0], SRC2[255:0])
TMP_DEST[511:256] <-  INTERLEAVE_DWORDS_256b(SRC1[511:256], SRC2[511:256])
INTERLEAVE_DWORDS_256b(SRC1, SRC2)
DEST[31:0] <-  SRC1[31:0]
DEST[63:32] <-  SRC2[31:0]
DEST[95:64] <-  SRC1[63:32]
DEST[127:96] <-  SRC2[63:32]
DEST[159:128] <-  SRC1[159:128]
DEST[191:160] <-  SRC2[159:128]
DEST[223:192] <-  SRC1[191:160]
DEST[255:224] <-  SRC2[191:160]
INTERLEAVE_DWORDS(SRC1, SRC2)
DEST[31:0] <-  SRC1[31:0]
DEST[63:32] <-  SRC2[31:0]
DEST[95:64] <-  SRC1[63:32]
DEST[127:96] <-  SRC2[63:32]
INTERLEAVE_QWORDS_512b (SRC1, SRC2)
TMP_DEST[255:0] <-  INTERLEAVE_QWORDS_256b(SRC1[255:0], SRC2[255:0])
TMP_DEST[511:256] <-  INTERLEAVE_QWORDS_256b(SRC1[511:256], SRC2[511:256])
INTERLEAVE_QWORDS_256b(SRC1, SRC2)
DEST[63:0] <-  SRC1[63:0]
DEST[127:64] <-  SRC2[63:0]
DEST[191:128] <-  SRC1[191:128]
DEST[255:192] <-  SRC2[191:128]
INTERLEAVE_QWORDS(SRC1, SRC2)
DEST[63:0] <-  SRC1[63:0]
DEST[127:64] <-  SRC2[63:0]
```
#### PUNPCKLBW
```info-verb
DEST[127:0] <- INTERLEAVE_BYTES(DEST, SRC)
DEST[255:127] (Unmodified)
```
#### VPUNPCKLBW (VEX.128 encoded instruction)
```info-verb
DEST[127:0] <- INTERLEAVE_BYTES(SRC1, SRC2)
DEST[511:127] <- 0
```
#### VPUNPCKLBW (VEX.256 encoded instruction)
```info-verb
DEST[255:0] <- INTERLEAVE_BYTES_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0
```
#### VPUNPCKLBW (EVEX.512 encoded instruction)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
IF VL = 128
    TMP_DEST[VL-1:0] <-  INTERLEAVE_BYTES(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0] <-  INTERLEAVE_BYTES_256b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0] <-  INTERLEAVE_BYTES_512b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  TMP_DEST[i+7:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
DEST[511:0] <-  INTERLEAVE_BYTES_512b(SRC1, SRC2)
```
#### PUNPCKLWD
```info-verb
DEST[127:0] <- INTERLEAVE_WORDS(DEST, SRC)
DEST[255:127] (Unmodified)
```
#### VPUNPCKLWD (VEX.128 encoded instruction)
```info-verb
DEST[127:0] <- INTERLEAVE_WORDS(SRC1, SRC2)
DEST[511:127] <- 0
```
#### VPUNPCKLWD (VEX.256 encoded instruction)
```info-verb
DEST[255:0] <- INTERLEAVE_WORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0
```
#### VPUNPCKLWD (EVEX.512 encoded instruction)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[VL-1:0] <-  INTERLEAVE_WORDS(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0] <-  INTERLEAVE_WORDS_256b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0] <-  INTERLEAVE_WORDS_512b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
THEN DEST[i+15:i] <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
DEST[511:0] <-  INTERLEAVE_WORDS_512b(SRC1, SRC2)
```
#### PUNPCKLDQ
```info-verb
DEST[127:0] <- INTERLEAVE_DWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPUNPCKLDQ (VEX.128 encoded instruction)
```info-verb
DEST[127:0] <- INTERLEAVE_DWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPUNPCKLDQ (VEX.256 encoded instruction)
```info-verb
DEST[255:0] <- INTERLEAVE_DWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0
```
#### VPUNPCKLDQ (EVEX encoded instructions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+31:i] <-  SRC2[31:0]
          ELSE TMP_SRC2[i+31:i] <-  SRC2[i+31:i]
    FI;
ENDFOR;
IF VL = 128
    TMP_DEST[VL-1:0] <-  INTERLEAVE_DWORDS(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0] <-  INTERLEAVE_DWORDS_256b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0] <-  INTERLEAVE_DWORDS_512b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
FOR j <-  0 TO KL-1
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
DEST511:0] <- INTERLEAVE_DWORDS_512b(SRC1, SRC2)
DEST[MAX_VL-1:VL] <-  0
```
#### PUNPCKLQDQ
```info-verb
DEST[127:0] <- INTERLEAVE_QWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPUNPCKLQDQ (VEX.128 encoded instruction)
```info-verb
DEST[127:0] <- INTERLEAVE_QWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPUNPCKLQDQ (VEX.256 encoded instruction)
```info-verb
DEST[255:0] <- INTERLEAVE_QWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0
```
#### VPUNPCKLQDQ (EVEX encoded instructions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+63:i] <-  SRC2[63:0]
          ELSE TMP_SRC2[i+63:i] <-  SRC2[i+63:i]
    FI;
ENDFOR;
IF VL = 128
    TMP_DEST[VL-1:0] <-  INTERLEAVE_QWORDS(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0] <-  INTERLEAVE_QWORDS_256b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0] <-  INTERLEAVE_QWORDS_512b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
FOR j <-  0 TO KL-1
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
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPUNPCKLBW __m512i _mm512_unpacklo_epi8(__m512i a, __m512i b);
VPUNPCKLBW __m512i _mm512_mask_unpacklo_epi8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPUNPCKLBW __m512i _mm512_maskz_unpacklo_epi8( __mmask64 k, __m512i a, __m512i b);
VPUNPCKLBW __m256i _mm256_mask_unpacklo_epi8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPUNPCKLBW __m256i _mm256_maskz_unpacklo_epi8( __mmask32 k, __m256i a, __m256i b);
VPUNPCKLBW __m128i _mm_mask_unpacklo_epi8(v s, __mmask16 k, __m128i a, __m128i b);
VPUNPCKLBW __m128i _mm_maskz_unpacklo_epi8( __mmask16 k, __m128i a, __m128i b);
VPUNPCKLWD __m512i _mm512_unpacklo_epi16(__m512i a, __m512i b);
VPUNPCKLWD __m512i _mm512_mask_unpacklo_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPUNPCKLWD __m512i _mm512_maskz_unpacklo_epi16( __mmask32 k, __m512i a, __m512i b);
VPUNPCKLWD __m256i _mm256_mask_unpacklo_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPUNPCKLWD __m256i _mm256_maskz_unpacklo_epi16( __mmask16 k, __m256i a, __m256i b);
VPUNPCKLWD __m128i _mm_mask_unpacklo_epi16(v s, __mmask8 k, __m128i a, __m128i b);
VPUNPCKLWD __m128i _mm_maskz_unpacklo_epi16( __mmask8 k, __m128i a, __m128i b);
VPUNPCKLDQ __m512i _mm512_unpacklo_epi32(__m512i a, __m512i b);
VPUNPCKLDQ __m512i _mm512_mask_unpacklo_epi32(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPUNPCKLDQ __m512i _mm512_maskz_unpacklo_epi32( __mmask16 k, __m512i a, __m512i b);
VPUNPCKLDQ __m256i _mm256_mask_unpacklo_epi32(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPUNPCKLDQ __m256i _mm256_maskz_unpacklo_epi32( __mmask8 k, __m256i a, __m256i b);
VPUNPCKLDQ __m128i _mm_mask_unpacklo_epi32(v s, __mmask8 k, __m128i a, __m128i b);
VPUNPCKLDQ __m128i _mm_maskz_unpacklo_epi32( __mmask8 k, __m128i a, __m128i b);
VPUNPCKLQDQ __m512i _mm512_unpacklo_epi64(__m512i a, __m512i b);
VPUNPCKLQDQ __m512i _mm512_mask_unpacklo_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPUNPCKLQDQ __m512i _mm512_maskz_unpacklo_epi64( __mmask8 k, __m512i a, __m512i b);
VPUNPCKLQDQ __m256i _mm256_mask_unpacklo_epi64(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPUNPCKLQDQ __m256i _mm256_maskz_unpacklo_epi64( __mmask8 k, __m256i a, __m256i b);
VPUNPCKLQDQ __m128i _mm_mask_unpacklo_epi64(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPUNPCKLQDQ __m128i _mm_maskz_unpacklo_epi64( __mmask8 k, __m128i a, __m128i b);
PUNPCKLBW:__m64 _mm_unpacklo_pi8 (__m64 m1, __m64 m2)
(V)PUNPCKLBW:__m128i _mm_unpacklo_epi8 (__m128i m1, __m128i m2)
VPUNPCKLBW:__m256i _mm256_unpacklo_epi8 (__m256i m1, __m256i m2)
PUNPCKLWD:__m64 _mm_unpacklo_pi16 (__m64 m1, __m64 m2)
(V)PUNPCKLWD:__m128i _mm_unpacklo_epi16 (__m128i m1, __m128i m2)
VPUNPCKLWD:__m256i _mm256_unpacklo_epi16 (__m256i m1, __m256i m2)
PUNPCKLDQ:__m64 _mm_unpacklo_pi32 (__m64 m1, __m64 m2)
(V)PUNPCKLDQ:__m128i _mm_unpacklo_epi32 (__m128i m1, __m128i m2)
VPUNPCKLDQ:__m256i _mm256_unpacklo_epi32 (__m256i m1, __m256i m2)
(V)PUNPCKLQDQ:__m128i _mm_unpacklo_epi64 (__m128i m1, __m128i m2)
VPUNPCKLQDQ:__m256i _mm256_unpacklo_epi64 (__m256i m1, __m256i m2)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPUNPCKLDQ/QDQ, see Exceptions Type E4NF.

EVEX-encoded VPUNPCKLBW/WD, see Exceptions Type E4NF.nb.

