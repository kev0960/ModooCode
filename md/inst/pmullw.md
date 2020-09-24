----------------------------
title : PMULLW (Intel x86/64 assembly instruction)
cat_title : PMULLW
ref_title : PMULLW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PMULLW

**Multiply Packed Signed Integers and Store Low Result**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F D5 /r\footnote{1}`\newline{}`PMULLW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Multiply the packed signed word integers in mm1 register and mm2/m64, and store the low 16 bits of the results in mm1. |
|`66 0F D5 /r`\newline{}`PMULLW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Multiply the packed signed word integers in xmm1 and xmm2/m128, and store the low 16 bits of the results in xmm1. |
|`VEX.NDS.128.66.0F.WIG D5 /r`\newline{}VPMULLW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Multiply the packed dword signed integers in xmm2 and xmm3/m128 and store the low 32 bits of each product in xmm1.|
|`VEX.NDS.256.66.0F.WIG D5 /r`\newline{}VPMULLW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Multiply the packed signed word integers in ymm2 and ymm3/m256, and store the low 16 bits of the results in ymm1.|
|`EVEX.NDS.128.66.0F.WIG D5 /r`\newline{}VPMULLW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed signed word integers in xmm2 and xmm3/m128, and store the low 16 bits of the results in xmm1 under writemask k1.|
|`EVEX.NDS.256.66.0F.WIG D5 /r`\newline{}VPMULLW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed signed word integers in ymm2 and ymm3/m256, and store the low 16 bits of the results in ymm1 under writemask k1.|
|`EVEX.NDS.512.66.0F.WIG D5 /r`\newline{}VPMULLW zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Multiply the packed signed word integers in zmm2 and zmm3/m512, and store the low 16 bits of the results in zmm1 under writemask k1.|

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


Performs a SIMD signed multiply of the packed signed word integers in the destination operand (first operand) and the source operand (second operand), and stores the low 16 bits of each intermediate 32-bit result in the destina-tion operand. (Figure 4-12 shows this operation when using 64-bit operands.)

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version 64-bit operand: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an MMX technology register.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.L must be 0, otherwise the instruction will #UD.



VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand is conditionally updated based on writemask k1.

```embed
<figure>
<svg viewBox="0 0 379.679993 139.520020">
<rect x="0.000000" y="10.000000" width="0.480000" height="117.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="117.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="127.359985" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.440002" y="76.359985" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="58.440002" y="76.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.199997" y="76.359985" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.199997" y="94.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.199997" y="76.119995" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.440002" y="76.359985" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="130.440002" y="76.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="76.359985" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.199997" y="94.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.199997" y="76.119995" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.439987" y="76.359985" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.439987" y="76.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="76.359985" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="94.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="76.119995" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.440002,76.359985 L346.440002,76.359985 L346.440002,94.359985 L274.440002,94.359985" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="274.440002" y="76.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="346.200012" y="76.359985" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="94.119995" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="76.119995" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.419998" y="20.320007" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.419998" y="20.080017" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.599991" y="20.320007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="38.080017" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="20.080017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.840012" y="20.320007" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.840012" y="20.080017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="20.320007" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.599991" y="38.080017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.599991" y="20.080017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="20.320007" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.199997" y="20.080017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="20.320007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="38.080017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="20.080017" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.560013" y="20.320007" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.560013" y="20.080017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.679993" y="20.320007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="38.080017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="20.080017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.419998" y="46.539978" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.419998" y="46.299988" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.539993" y="46.539978" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="64.299988" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="46.299988" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.780014" y="46.539978" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.780014" y="46.299988" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="46.539978" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.539993" y="64.299988" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.539993" y="46.299988" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.139999" y="46.539978" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.139999" y="46.299988" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="46.539978" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="64.299988" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="46.299988" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.560013" y="46.539978" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.560013" y="46.299988" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.679993" y="46.539978" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="64.299988" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="46.299988" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.360001" y="102.760010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.360001" y="102.519958" width="36.599998" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="102.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="120.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="102.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.719986" y="102.760010" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.719986" y="102.519958" width="36.660000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="102.760010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="120.520020" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="102.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.139999" y="102.760010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.139999" y="102.519958" width="36.599998" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.259995" y="102.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="120.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="102.520020" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.500015" y="102.760010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.500015" y="102.519958" width="36.599998" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.619995" y="102.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.259995" y="120.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.259995" y="102.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="267.700256" y="114.520020" textLength="2.136720" font-size="8px">]</text>
<text x="262.238770" y="114.520020" textLength="1.357200" font-size="8px">:</text>
<text x="254.074692" y="114.520020" textLength="4.071600" font-size="8px">1</text>
<text x="251.927536" y="114.520020" textLength="2.136720" font-size="8px">[</text>
<text x="247.845505" y="114.520020" textLength="4.071600" font-size="8px">0</text>
<text x="243.826096" y="114.520020" textLength="4.008960" font-size="8px">Z</text>
<text x="225.885300" y="114.520020" textLength="1.357200" font-size="8px">:</text>
<text x="221.803268" y="114.520020" textLength="4.071600" font-size="8px">5</text>
<text x="215.563644" y="114.520020" textLength="2.136720" font-size="8px">[</text>
<text x="211.423141" y="114.520020" textLength="4.071600" font-size="8px">1</text>
<text x="194.324509" y="114.520020" textLength="2.136720" font-size="8px">]</text>
<text x="180.640457" y="114.520020" textLength="4.071600" font-size="8px">1</text>
<text x="174.400833" y="114.520020" textLength="4.071600" font-size="8px">2</text>
<text x="170.381424" y="114.520020" textLength="4.008960" font-size="8px">Z</text>
<text x="158.682358" y="114.520020" textLength="2.136720" font-size="8px">]</text>
<text x="153.232681" y="114.520020" textLength="1.357200" font-size="8px">:</text>
<text x="149.150650" y="114.520020" textLength="4.071600" font-size="8px">5</text>
<text x="142.921448" y="114.520020" textLength="2.136720" font-size="8px">[</text>
<text x="49.324371" y="88.239929" textLength="5.329997" font-size="8px">P</text>
<text x="32.460159" y="88.239929" textLength="4.882501" font-size="8px">T</text>
<text x="253.137222" y="59.020020" textLength="5.329997" font-size="8px">Y</text>
<text x="179.699142" y="59.020020" textLength="5.329997" font-size="8px">Y</text>
<text x="149.460403" y="59.020020" textLength="4.442996" font-size="8px">3</text>
<text x="144.120010" y="59.020020" textLength="5.329997" font-size="8px">Y</text>
<text x="102.909866" y="113.199768" textLength="5.329997" font-size="8px">S</text>
<text x="107.165070" y="57.880493" textLength="4.882501" font-size="8px">T</text>
<text x="101.830276" y="57.880493" textLength="5.329997" font-size="8px">S</text>
<text x="101.819092" y="31.060303" textLength="5.769502" font-size="8px">C</text>
<text x="96.050385" y="31.060303" textLength="5.769502" font-size="8px">R</text>
<text x="90.721191" y="31.060303" textLength="5.329997" font-size="8px">S</text>
<text x="327.358704" y="87.459961" textLength="4.442996" font-size="8px">0</text>
<text x="322.021484" y="87.459961" textLength="5.329997" font-size="8px">Y</text>
<text x="303.841492" y="87.459961" textLength="5.329997" font-size="8px">X</text>
<text x="294.973450" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="290.531250" y="87.459961" textLength="4.442996" font-size="8px">0</text>
<text x="258.350708" y="87.459961" textLength="4.442996" font-size="8px">1</text>
<text x="253.021500" y="87.459961" textLength="5.329997" font-size="8px">Y</text>
<text x="246.780014" y="87.459961" textLength="3.990000" font-size="8px">`*`</text>
<text x="234.781509" y="87.459961" textLength="5.329997" font-size="8px">X</text>
<text x="221.555222" y="87.459961" textLength="4.442996" font-size="8px">1</text>
<text x="185.102676" y="87.459961" textLength="4.442996" font-size="8px">2</text>
<text x="173.520004" y="87.459961" textLength="3.990000" font-size="8px">`*`</text>
<text x="171.300095" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="161.521500" y="87.459961" textLength="5.329997" font-size="8px">X</text>
<text x="159.300003" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="152.639267" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="106.681427" y="87.459961" textLength="5.329997" font-size="8px">Y</text>
<text x="98.159286" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="93.713898" y="87.459961" textLength="4.442996" font-size="8px">3</text>
<text x="86.160004" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="79.560349" y="87.459595" textLength="2.221498" font-size="8px"> </text>
<text x="255.297623" y="31.719971" textLength="4.442996" font-size="8px">0</text>
<text x="249.957230" y="31.719971" textLength="5.329997" font-size="8px">X</text>
<text x="140.940002" y="31.719971" textLength="5.329997" font-size="8px">X</text>
<text x="91.800781" y="113.199768" textLength="5.769502" font-size="8px">D</text>
<text x="96.495483" y="57.880493" textLength="5.329997" font-size="8px">E</text>
<text x="216.661545" y="87.459961" textLength="4.882501" font-size="8px">Z</text>
<text x="217.662766" y="114.520020" textLength="4.071600" font-size="8px">1</text>
<text x="88.381500" y="87.459961" textLength="5.329997" font-size="8px">X</text>
<text x="231.346817" y="114.520020" textLength="2.136720" font-size="8px">]</text>
<text x="285.649536" y="87.459961" textLength="4.882501" font-size="8px">Z</text>
<text x="319.799988" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="226.009415" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="81.779999" y="87.459961" textLength="4.381020" font-size="8px">=</text>
<text x="108.244659" y="113.199768" textLength="4.882501" font-size="8px">T</text>
<text x="258.477600" y="59.020020" textLength="4.442996" font-size="8px">0</text>
<text x="154.919998" y="87.459961" textLength="4.381020" font-size="8px">=</text>
<text x="176.519119" y="31.719971" textLength="5.329997" font-size="8px">X</text>
<text x="146.280380" y="31.719971" textLength="4.442996" font-size="8px">3</text>
<text x="185.039536" y="59.020020" textLength="4.442996" font-size="8px">2</text>
<text x="190.184006" y="114.520020" textLength="4.071600" font-size="8px">0</text>
<text x="145.068619" y="114.520020" textLength="4.071600" font-size="8px">1</text>
<text x="179.761490" y="87.459961" textLength="5.329997" font-size="8px">Y</text>
<text x="100.380005" y="87.459961" textLength="3.990000" font-size="8px">`*`</text>
<text x="313.619324" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="148.200272" y="87.459961" textLength="4.442996" font-size="8px">2</text>
<text x="37.341064" y="88.239929" textLength="5.329997" font-size="8px">E</text>
<text x="301.619995" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="188.862991" y="114.520020" textLength="1.357200" font-size="8px">:</text>
<text x="104.399994" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="90.721191" y="57.880493" textLength="5.769502" font-size="8px">D</text>
<text x="309.173889" y="87.459961" textLength="4.442996" font-size="8px">0</text>
<text x="154.600327" y="114.520020" textLength="4.071600" font-size="8px">0</text>
<text x="250.800003" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="177.539993" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="218.878616" y="31.719971" textLength="4.442996" font-size="8px">1</text>
<text x="138.839401" y="114.520020" textLength="4.071600" font-size="8px">3</text>
<text x="240.113907" y="87.459961" textLength="4.442996" font-size="8px">1</text>
<text x="228.180008" y="87.459961" textLength="4.381020" font-size="8px">=</text>
<text x="263.559753" y="114.520020" textLength="4.071600" font-size="8px">0</text>
<text x="227.206314" y="114.520020" textLength="4.071600" font-size="8px">0</text>
<text x="75.061417" y="87.459595" textLength="4.442996" font-size="8px">3</text>
<text x="222.058640" y="59.020020" textLength="4.442996" font-size="8px">1</text>
<text x="181.859512" y="31.719971" textLength="4.442996" font-size="8px">2</text>
<text x="178.541336" y="114.520020" textLength="2.136720" font-size="8px">[</text>
<text x="207.403732" y="114.520020" textLength="4.008960" font-size="8px">Z</text>
<text x="166.801163" y="87.459961" textLength="4.442996" font-size="8px">2</text>
<text x="42.669464" y="88.239929" textLength="6.656503" font-size="8px">M</text>
<text x="111.975464" y="87.459961" textLength="4.442996" font-size="8px">3</text>
<text x="315.840027" y="87.459961" textLength="3.990000" font-size="8px">`*`</text>
<text x="184.780960" y="114.520020" textLength="4.071600" font-size="8px">5</text>
<text x="143.353729" y="87.459961" textLength="4.882501" font-size="8px">Z</text>
<text x="297.239990" y="87.459961" textLength="4.381020" font-size="8px">=</text>
<text x="97.575073" y="113.199768" textLength="5.329997" font-size="8px">E</text>
<text x="258.156738" y="114.520020" textLength="4.071600" font-size="8px">5</text>
<text x="216.718246" y="59.020020" textLength="5.329997" font-size="8px">Y</text>
<text x="232.560013" y="87.459961" textLength="2.221498" font-size="8px"> </text>
<text x="70.200485" y="87.459595" textLength="4.882501" font-size="8px">Z</text>
<text x="213.538223" y="31.719971" textLength="5.329997" font-size="8px">X</text>
<text x="134.820007" y="114.520020" textLength="4.008960" font-size="8px">Z</text>
<text x="244.559311" y="87.459961" textLength="2.221498" font-size="8px"> </text>
</svg>
<figcaption>Figure 4-13.  PMULLU Instruction Operation Using 64-bit Operands
</figcaption></figure>
```

### Operation
#### PMULLW (with 64-bit operands)
```info-verb
    TEMP0[31:0] <-  DEST[15:0] `*` SRC[15:0]; (* Signed multiplication *)
    TEMP1[31:0] <-  DEST[31:16] `*` SRC[31:16];
    TEMP2[31:0] <-  DEST[47:32] `*` SRC[47:32];
    TEMP3[31:0] <- DEST[63:48] `*` SRC[63:48];
    DEST[15:0] <-  TEMP0[15:0];
    DEST[31:16] <-  TEMP1[15:0];
    DEST[47:32] <-  TEMP2[15:0];
    DEST[63:48] <-  TEMP3[15:0];
```
#### PMULLW (with 128-bit operands)
```info-verb
    TEMP0[31:0] <-  DEST[15:0] `*` SRC[15:0]; (* Signed multiplication *)
    TEMP1[31:0] <- DEST[31:16] `*` SRC[31:16];
    TEMP2[31:0] <-  DEST[47:32] `*` SRC[47:32];
    TEMP3[31:0] <- DEST[63:48] `*` SRC[63:48];
    TEMP4[31:0] <- DEST[79:64] `*` SRC[79:64];
    TEMP5[31:0] <-  DEST[95:80] `*` SRC[95:80];
    TEMP6[31:0] <-  DEST[111:96] `*` SRC[111:96];
    TEMP7[31:0] <- DEST[127:112] `*` SRC[127:112];
    DEST[15:0] <-  TEMP0[15:0];
    DEST[31:16] <-  TEMP1[15:0];
    DEST[47:32] <-  TEMP2[15:0];
    DEST[63:48] <-  TEMP3[15:0];
    DEST[79:64] <-  TEMP4[15:0];
    DEST[95:80] <-  TEMP5[15:0];
    DEST[111:96] <-  TEMP6[15:0];
    DEST[127:112] <- TEMP7[15:0];
DEST[VLMAX-1:256] <-  0
```
#### VPMULLW (VEX.128 encoded version)
```info-verb
Temp0[31:0] <-  SRC1[15:0] * SRC2[15:0]
Temp1[31:0] <-  SRC1[31:16] * SRC2[31:16]
Temp2[31:0] <-  SRC1[47:32] * SRC2[47:32]
Temp3[31:0] <-  SRC1[63:48] * SRC2[63:48]
Temp4[31:0] <-  SRC1[79:64] * SRC2[79:64]
Temp5[31:0] <-  SRC1[95:80] * SRC2[95:80]
Temp6[31:0] <-  SRC1[111:96] * SRC2[111:96]
Temp7[31:0] <-  SRC1[127:112] * SRC2[127:112]
DEST[15:0] <-  Temp0[15:0]
DEST[31:16] <-  Temp1[15:0]
DEST[47:32] <-  Temp2[15:0]
DEST[63:48] <-  Temp3[15:0]
DEST[79:64] <-  Temp4[15:0]
DEST[95:80] <-  Temp5[15:0]
DEST[111:96] <-  Temp6[15:0]
DEST[127:112] <-  Temp7[15:0]
DEST[VLMAX-1:128] <-  0
```
#### PMULLW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN 
                temp[31:0] <-  SRC1[i+15:i] * SRC2[i+15:i]
                DEST[i+15:i] <-  temp[15:0]
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
VPMULLW __m512i _mm512_mullo_epi16(__m512i a, __m512i b);
VPMULLW __m512i _mm512_mask_mullo_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPMULLW __m512i _mm512_maskz_mullo_epi16( __mmask32 k, __m512i a, __m512i b);
VPMULLW __m256i _mm256_mask_mullo_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMULLW __m256i _mm256_maskz_mullo_epi16( __mmask16 k, __m256i a, __m256i b);
VPMULLW __m128i _mm_mask_mullo_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMULLW __m128i _mm_maskz_mullo_epi16( __mmask8 k, __m128i a, __m128i b);
PMULLW: __m64 _mm_mullo_pi16(__m64 m1, __m64 m2)
(V)PMULLW: __m128i _mm_mullo_epi16 ( __m128i a, __m128i b)
VPMULLW:__m256i _mm256_mullo_epi16 ( __m256i a, __m256i b);
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.nb.

