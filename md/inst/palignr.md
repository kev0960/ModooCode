----------------------------
title : PALIGNR (Intel x86/64 assembly instruction)
cat_title : PALIGNR
ref_title : PALIGNR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PALIGNR

** Packed Align Right **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 3A 0F /r ib\footnote{1}`\newline{}`PALIGNR` mm1 mm2/m64 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSSE3|Concatenate destination and source operands, extract byte-aligned result shifted to the right by constant value in imm8 into mm1. |
|`66 0F 3A 0F /r ib`\newline{}`PALIGNR` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSSE3|Concatenate destination and source operands, extract byte-aligned result shifted to the right by constant value in imm8 into xmm1.|
|`VEX.NDS.128.66.0F3A.WIG 0F /r ib`\newline{}VPALIGNR \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Concatenate xmm2 and xmm3/m128, extract byte aligned result shifted to the right by constant value in imm8 and result is stored in xmm1.|
|`VEX.NDS.256.66.0F3A.WIG 0F /r ib`\newline{}VPALIGNR \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX2|Concatenate pairs of 16 bytes in ymm2 and ymm3/m256 into 32-byte intermediate result, extract byte-aligned, 16-byte result shifted to the right by constant values in imm8 from each intermediate result, and two 16-byte results are stored in ymm1.|
|`EVEX.NDS.128.66.0F3A.WIG 0F /r ib`\newline{}VPALIGNR \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVM|V/V|AVX512VL\newline{}AVX512BW|Concatenate xmm2 and xmm3/m128 into a 32-byte intermediate result, extract byte aligned result shifted to the right by constant value in imm8 and result is stored in xmm1.|
|`EVEX.NDS.256.66.0F3A.WIG 0F /r ib`\newline{}VPALIGNR \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVM|V/V|AVX512VL\newline{}AVX512BW|Concatenate pairs of 16 bytes in ymm2 and ymm3/m256 into 32-byte intermediate result, extract byte-aligned, 16-byte result shifted to the right by constant values in imm8 from each intermediate result, and two 16-byte results are stored in ymm1.|
|`EVEX.NDS.512.66.0F3A.WIG 0F /r ib`\newline{}VPALIGNR zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FVM|V/V|AVX512BW|Concatenate pairs of 16 bytes in zmm2 and zmm3/m512 into 32-byte intermediate result, extract byte-aligned, 16-byte result shifted to the right by constant values in imm8 from each intermediate result, and four 16-byte results are stored in zmm1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


(V)PALIGNR concatenates the destination operand (the first operand) and the source operand (the second operand) into an intermediate composite, shifts the composite at byte granularity to the right by a constant imme-diate, and extracts the right-aligned result into the destination. The first and the second operands can be an MMX, 



XMM or a YMM register. The immediate value is considered unsigned. Immediate shift counts larger than the 2L (i.e. 32 for 128-bit operands, or 16 for 64-bit operands) produce a zero result. Both operands can be MMX regis-ters, XMM registers or YMM registers. When the source operand is a 128-bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

In 64-bit mode and not encoded by VEX/EVEX prefix, use the REX prefix to access additional registers.

128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

EVEX.512 encoded version: The first source operand is a ZMM register and contains four 16-byte blocks. The second source operand is a ZMM register or a 512-bit memory location containing four 16-byte block. The destina-tion operand is a ZMM register and contain four 16-byte results. The imm8[7:0] is the common shift count

used for each of the four successive 16-byte block sources. The low 16-byte block of the two source operands produce the low 16-byte result of the destination operand, the high 16-byte block of the two source operands produce the high 16-byte result of the destination operand and so on for the blocks in the middle.

VEX.256 and EVEX.256 encoded versions: The first source operand is a YMM register and contains two 16-byte blocks. The second source operand is a YMM register or a 256-bit memory location containing two 16-byte block. The destination operand is a YMM register and contain two 16-byte results. The imm8[7:0] is the common shift count used for the two lower 16-byte block sources and the two upper 16-byte block sources. The low 16-byte block of the two source operands produce the low 16-byte result of the destination operand, the high 16-byte block of the two source operands produce the high 16-byte result of the destination operand. The upper bits (MAX_VL-1:256) of the corresponding ZMM register destination are zeroed.

VEX.128 and EVEX.128 encoded versions: The first source operand is an XMM register. The second source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

Concatenation is done with 128-bit data in the first and second source operand for both 128-bit and 256-bit instructions. The high 128-bits of the intermediate composite 256-bit result came from the 128-bit data from the first source operand; the low 128-bits of the intermediate result came from the 128-bit data of the second source operand.

Note: VEX.L must be 0, otherwise the instruction will #UD.

```embed
<figure>
<svg viewBox="0 0 371.188416 216.860001">
<rect x="76.259552" y="14.800110" width="33.959999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="76.259552" y="14.560120" width="34.200001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.979553" y="14.800110" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="76.019547" y="32.560120" width="34.200001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="76.019547" y="14.560120" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="110.219559" y="14.800110" width="34.020000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="110.219559" y="14.560120" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.999557" y="14.800110" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.979553" y="32.560120" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.979553" y="14.560120" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.239548" y="14.800110" width="34.020000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="144.239548" y="14.560120" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.019547" y="14.800110" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.999557" y="32.560120" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.999557" y="14.560120" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.259537" y="14.800110" width="34.020000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.259537" y="14.560120" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.039566" y="14.800110" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.019547" y="32.560120" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.019547" y="14.560120" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.879562" y="14.920105" width="34.020000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="212.879562" y="14.680115" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659561" y="14.920105" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.639542" y="32.680084" width="34.259998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.639542" y="14.680115" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.899551" y="14.920105" width="34.020000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="246.899551" y="14.680115" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.679565" y="14.920105" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659561" y="32.680084" width="34.259998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659561" y="14.680115" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.919556" y="14.920105" width="33.959999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.919556" y="14.680115" width="34.200001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.639526" y="14.920105" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.679565" y="32.680084" width="34.200001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.679565" y="14.680115" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.879578" y="14.920105" width="34.020000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="314.879578" y="14.680115" width="34.259998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="348.659546" y="14.920105" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.639526" y="32.680084" width="34.259998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.639526" y="14.680115" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="331.679565" y="14.680115" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="331.679565" y="14.920105" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="297.659546" y="15.460114" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="297.659546" y="15.700104" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.039551" y="14.500092" width="0.479980" height="0.240020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.039551" y="14.740112" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.479538" y="15.280121" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.479538" y="15.520111" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="194.999557" y="15.460114" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="194.999557" y="15.700104" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="160.979538" y="15.700104" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="160.979538" y="15.940125" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.359558" y="15.880096" width="0.479980" height="0.240020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.359558" y="16.120117" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.879547" y="15.460114" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.879547" y="15.700104" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="308.279541" y="26.680115" width="0.239990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.319565" y="26.680115" width="120.959999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="24.299545" y="64.540100" width="34.980000" height="17.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="24.299545" y="64.300079" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.039551" y="64.540100" width="0.480000" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="24.059555" y="81.940125" width="35.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="24.059555" y="64.300110" width="0.480010" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.279556" y="64.540100" width="34.980000" height="17.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.279556" y="64.300079" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.019547" y="64.540100" width="0.480000" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.039551" y="81.940125" width="35.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.039551" y="64.300110" width="0.480000" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259552" y="64.540100" width="34.919998" height="17.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.259552" y="64.300079" width="35.160000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.939545" y="64.540100" width="0.480010" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.019547" y="81.940125" width="35.160000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.019547" y="64.300110" width="0.480000" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.179550" y="64.540100" width="34.980000" height="17.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.179550" y="64.300079" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.919540" y="64.540100" width="0.480010" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.939545" y="81.940125" width="35.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.939545" y="64.300110" width="0.480010" height="17.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.819565" y="64.660095" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="164.819565" y="64.420105" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.559555" y="64.660095" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.579544" y="82.120117" width="35.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.579544" y="64.420105" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.799545" y="64.660095" width="34.919998" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="199.799545" y="64.420105" width="35.160000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.479538" y="64.660095" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.559555" y="82.120117" width="35.160000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.559555" y="64.420105" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.719559" y="64.660095" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="234.719559" y="64.420105" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.459534" y="64.660095" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.479538" y="82.120117" width="35.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.479538" y="64.420105" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.699524" y="64.660095" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="269.699524" y="64.420105" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.439575" y="64.660095" width="0.479980" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.459534" y="82.120117" width="35.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.459534" y="64.420105" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="286.979553" y="64.420105" width="0.480010" height="18.180000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.999557" y="65.260101" width="0.479980" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.419540" y="64.240112" width="0.480010" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.839554" y="65.020111" width="0.480010" height="18.180000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="146.399551" y="65.260101" width="0.480000" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="111.419556" y="65.440125" width="0.480000" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.839554" y="65.620117" width="0.480010" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="41.459549" y="65.260101" width="0.480000" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.859558" y="127.840103" width="34.919998" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="58.859558" y="127.600113" width="35.160000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.539551" y="127.840103" width="0.480000" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.619553" y="145.300095" width="35.160000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.619553" y="127.600098" width="0.480000" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.779556" y="127.840103" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="93.779556" y="127.600113" width="35.220001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.519547" y="127.840103" width="0.480000" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.539551" y="145.300095" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.539551" y="127.600098" width="0.480000" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.759552" y="127.840103" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.759552" y="127.600113" width="35.220001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.499557" y="127.840103" width="0.479980" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.519547" y="145.300095" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.519547" y="127.600098" width="0.480000" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.739548" y="127.840103" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="163.739548" y="127.600113" width="35.220001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.479538" y="127.840103" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.499557" y="145.300095" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.499557" y="127.600098" width="0.479980" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.319565" y="127.960114" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="199.319565" y="127.720093" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.059555" y="127.960098" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.079544" y="145.420105" width="35.220001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.079544" y="127.720108" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.299545" y="127.960114" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="234.299545" y="127.720093" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.039551" y="127.960098" width="0.479980" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.059555" y="145.420105" width="35.220001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.059555" y="127.720108" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.279541" y="127.960114" width="34.980000" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="269.279541" y="127.720093" width="35.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.019531" y="127.960098" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.039551" y="145.420105" width="35.220001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.039551" y="127.720108" width="0.479980" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.259521" y="127.960114" width="34.919998" height="17.700001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="304.259521" y="127.720093" width="35.160000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="338.939575" y="127.960098" width="0.479980" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.019531" y="145.420105" width="35.160000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.019531" y="127.720108" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="321.479553" y="127.780106" width="0.479980" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="286.499573" y="128.560104" width="0.479980" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="250.919540" y="127.540100" width="0.480010" height="18.180000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.339554" y="128.320099" width="0.480010" height="18.180000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.959549" y="128.560104" width="0.480010" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.979553" y="128.740112" width="0.480000" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="110.399551" y="128.920105" width="0.480000" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.959549" y="128.560104" width="0.480000" height="18.120001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.439560,128.320099 L207.959549,128.440094 L208.199570,129.520096 L208.679550,129.400101" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.139542,129.040100 L209.519547,128.140106 L210.419540,127.600098 L210.299545,128.620102 L209.879532,134.200104 L209.759537,135.940094 L208.979538,134.440094 L206.399551,129.520096 L205.859543,128.560104 L206.879532,128.740097 L207.239548,128.980103 L209.819534,133.900101 L208.979538,134.440094 L208.919540,134.140106 L209.339554,128.560104 L210.299545,128.620102 L210.119553,128.980103 L208.739548,129.880096" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.879562,128.740112 L208.499557,128.980118 L208.739548,129.880112 L208.559555,130.000107 L208.379562,129.940109 L206.759567,129.700119" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.439560,129.460098 L209.819565,128.560104 L209.399551,134.140091 L206.819565,129.220093" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.199539,26.860107 L187.139542,26.620117 L186.659531,26.740112 L186.719528,26.980103" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.439560,128.320099 L208.499557,128.560104 L208.019547,128.680099 L207.959549,128.440094" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.199539,26.860107 L186.719528,26.980103 L207.959549,128.440109 L208.439529,128.320099" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="138.119553" y="75.100098" width="121.199997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M329.519531,129.340103 L329.039551,129.460098 L329.219543,130.480103 L329.699524,130.360107" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M329.159546,130.000107 L330.599548,129.160110 L331.499573,128.620102 L331.379578,129.640106 L330.899536,135.220108 L330.779541,136.960114 L329.999573,135.460114 L327.419556,130.480103 L326.879578,129.520111 L327.899536,129.700104 L328.259583,129.940109 L330.839539,134.920105 L329.999573,135.460114 L329.939575,135.160110 L330.419556,129.580109 L331.379578,129.640106 L331.139587,130.000107 L329.699585,130.840103" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M327.899536,129.700104 L329.519531,129.940109 L329.699524,130.840103 L329.519531,130.960098 L329.399536,130.900101 L327.779541,130.660110" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M329.459534,130.420105 L330.899536,129.580109 L330.419556,135.160110 L327.839539,130.180099" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.999573,28.060120 L308.939575,27.820129 L308.459534,27.940125 L308.519531,28.180115" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M329.519531,129.340103 L329.579529,129.580109 L329.099548,129.700104 L329.039551,129.460098" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.999573,28.060120 L308.519531,28.180115 L329.039551,129.460114 L329.519531,129.340118" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.819565,132.580109 L194.459579,132.220108 L193.619553,132.940109 L193.979568,133.300110" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.039566,132.700104 L195.479568,133.480103 L196.379562,133.960098 L195.419571,134.380096 L190.319565,136.720108 L188.699570,137.440109 L189.719559,136.000107 L192.839554,131.320099 L193.379562,130.420105 L193.739578,131.380096 L193.679581,131.860107 L190.559555,136.540100 L189.719559,136.000107 L189.899551,135.820099 L194.999557,133.480103 L195.419571,134.380096 L194.999557,134.320099 L193.559555,133.540100" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.739548,131.380112 L194.279556,132.940109 L193.559555,133.540115 L193.379562,133.480118 L193.319534,133.300110 L192.779556,131.740112" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.799545,133.120102 L195.239548,133.900101 L190.139542,136.240097 L193.259537,131.560104" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.519531,76.240112 L260.699524,76.120117 L260.399536,75.760101 L260.219543,75.880127" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.819565,132.580109 L194.639572,132.700104 L194.339554,132.340103 L194.519577,132.220108" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.519531,76.240112 L260.219543,75.880127 L194.519547,132.220108 L194.819534,132.580109" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M74.699554,133.480103 L74.339554,133.120102 L73.559555,133.840103 L73.919556,134.200104" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.979553,133.540100 L75.419556,134.320099 L76.319550,134.800095 L75.359558,135.280106 L70.319550,137.680099 L68.819550,138.400101 L69.659546,136.960098 L72.599548,132.220093 L73.139557,131.380096 L73.559555,132.280106 L73.499557,132.760101 L70.559555,137.500107 L69.659546,136.960098 L69.899551,136.780106 L74.939560,134.380096 L75.359558,135.280106 L74.939560,135.280106 L73.499557,134.500107" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.559555,132.280106 L74.219559,133.840103 L73.499557,134.500107 L73.319550,134.380112 L73.259552,134.200104 L72.599548,132.640106" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.739548,134.020111 L75.179550,134.800110 L70.139542,137.200104 L73.079544,132.460114" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.079544,75.820099 L139.259537,75.700104 L138.959549,75.340088 L138.779541,75.460114" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M74.699554,133.480103 L74.519562,133.600098 L74.219559,133.240097 L74.399551,133.120102" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.079544,75.820099 L138.779541,75.460114 L74.399551,133.120102 L74.699539,133.480103" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.579529" y="88.960114" width="0.480010" height="9.600000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.959534" y="88.960114" width="0.480010" height="9.600000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.219543" y="36.100098" width="0.480010" height="9.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.199524" y="36.100098" width="0.479980" height="9.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.319580,40.480103 L328.319580,43.780090 L327.659546,43.600098 L316.739563,40.480103 L327.659546,37.360107 L328.319580,37.180115 L328.319580,37.840088 L327.959595,38.320099 L318.719543,40.960114 L318.419556,40.000092 L318.719543,40.000092 L327.959595,42.640106 L327.659546,43.600098 L327.299561,43.120117 L327.299561,40.480103" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="327.299561" y="37.840088" width="1.020000" height="2.640000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M327.839539,40.480103 L327.839539,43.120117 L318.599548,40.480103 L327.839539,37.840088" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M337.199524,40.480103 L337.199524,37.180115 L337.859558,37.360107 L348.779541,40.480103 L337.859558,43.600098 L337.199524,43.780090 L337.199524,43.120117 L337.559509,42.640106 L346.799561,40.000092 L347.099548,40.960114 L346.799561,40.960114 L337.559509,38.320099 L337.859558,37.360107 L338.219543,37.840088 L338.219543,40.480103" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="337.199524" y="40.480103" width="1.020000" height="2.640000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M337.679565,40.480103 L337.679565,37.840088 L346.919556,40.480103 L337.679565,43.120117" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="328.079529" y="40.240082" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="328.319580" y="40.240082" width="9.120000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M281.219543,92.500092 L281.219543,95.800079 L280.559570,95.620087 L269.639587,92.500092 L280.559570,89.380096 L281.219543,89.200104 L281.219543,89.860077 L280.859558,90.340088 L271.619568,92.980103 L271.319580,92.020081 L271.619568,92.020081 L280.859558,94.660095 L280.559570,95.620087 L280.199585,95.140106 L280.199585,92.500092" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.199524" y="89.860077" width="1.020000" height="2.640000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M280.739563,92.500092 L280.739563,95.140106 L271.499573,92.500092 L280.739563,89.860077" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.899536,92.500092 L291.899536,89.200104 L292.559570,89.380096 L303.479553,92.500092 L292.559570,95.620087 L291.899536,95.800079 L291.899536,95.140106 L292.259521,94.660095 L301.499573,92.020081 L301.799561,92.980103 L301.499573,92.980103 L292.259521,90.340088 L292.559570,89.380096 L292.919556,89.860077 L292.919556,92.500092" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="291.899536" y="92.500092" width="1.020000" height="2.640000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.379578,92.500092 L292.379578,89.860077 L301.619568,92.500092 L292.379578,95.140106" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.979553" y="92.260101" width="0.240020" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="281.219543" y="92.260101" width="10.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="357.358093" y="139.120468" textLength="4.650932" font-size="8px">T</text>
<text x="352.197876" y="139.120468" textLength="5.077204" font-size="8px">S</text>
<text x="209.337387" y="123.160110" textLength="4.232272" font-size="8px">7</text>
<text x="200.819565" y="123.160110" textLength="4.232272" font-size="8px">1</text>
<text x="50.278778" y="138.880402" textLength="4.650932" font-size="8px">T</text>
<text x="40.078705" y="138.880402" textLength="5.077204" font-size="8px">E</text>
<text x="34.499863" y="138.880402" textLength="5.495864" font-size="8px">D</text>
<text x="193.617294" y="123.160278" textLength="4.232272" font-size="8px">8</text>
<text x="68.637375" y="123.760101" textLength="4.232272" font-size="8px">5</text>
<text x="64.378464" y="123.760101" textLength="4.232272" font-size="8px">5</text>
<text x="60.119553" y="123.760101" textLength="4.232272" font-size="8px">2</text>
<text x="323.216675" y="75.820465" textLength="4.232272" font-size="8px">2</text>
<text x="317.697998" y="75.820465" textLength="5.495864" font-size="8px">C</text>
<text x="302.994690" y="59.860107" textLength="4.232272" font-size="8px">2</text>
<text x="298.735779" y="59.860107" textLength="4.232272" font-size="8px">1</text>
<text x="166.259537" y="59.860107" textLength="4.232272" font-size="8px">2</text>
<text x="10.678871" y="75.580414" textLength="5.495864" font-size="8px">C</text>
<text x="5.100037" y="75.580414" textLength="5.495864" font-size="8px">R</text>
<text x="0.000000" y="75.580414" textLength="5.077204" font-size="8px">S</text>
<text x="34.077377" y="60.460114" textLength="4.232272" font-size="8px">5</text>
<text x="366.956177" y="26.260132" textLength="4.232272" font-size="8px">2</text>
<text x="351.179504" y="26.260132" textLength="5.077204" font-size="8px">S</text>
<text x="222.596848" y="10.000092" textLength="4.232272" font-size="8px">7</text>
<text x="214.319565" y="10.000092" textLength="4.232272" font-size="8px">1</text>
<text x="309.316406" y="106.419983" textLength="3.108499" font-size="8px">*</text>
<text x="307.093323" y="106.419983" textLength="2.221498" font-size="8px">]</text>
<text x="302.648743" y="106.419983" textLength="4.442996" font-size="8px">0</text>
<text x="300.425659" y="106.419983" textLength="2.221498" font-size="8px">:</text>
<text x="293.757996" y="106.419983" textLength="2.221498" font-size="8px">[</text>
<text x="289.259094" y="106.419983" textLength="4.442996" font-size="8px">8</text>
<text x="282.600952" y="106.419983" textLength="6.656503" font-size="8px">m</text>
<text x="273.719788" y="106.419983" textLength="2.221498" font-size="8px">I</text>
<text x="359.231506" y="53.020111" textLength="3.108499" font-size="8px">*</text>
<text x="352.568604" y="53.020111" textLength="4.442996" font-size="8px">0</text>
<text x="343.626648" y="53.020111" textLength="2.221498" font-size="8px">[</text>
<text x="332.522339" y="53.020111" textLength="6.656503" font-size="8px">m</text>
<text x="323.639526" y="53.020111" textLength="2.221498" font-size="8px">I</text>
<text x="68.337326" y="26.019836" textLength="4.232272" font-size="8px">1</text>
<text x="62.938889" y="26.019836" textLength="5.495864" font-size="8px">C</text>
<text x="52.620071" y="26.019836" textLength="5.077204" font-size="8px">S</text>
<text x="81.598190" y="10.600098" textLength="4.232272" font-size="8px">2</text>
<text x="350.407043" y="53.020111" textLength="2.221498" font-size="8px">:</text>
<text x="170.518448" y="59.860107" textLength="4.232272" font-size="8px">5</text>
<text x="343.135132" y="10.000092" textLength="4.232272" font-size="8px">0</text>
<text x="205.199570" y="10.000000" textLength="4.232272" font-size="8px">0</text>
<text x="312.426514" y="106.419983" textLength="4.442996" font-size="8px">8</text>
<text x="362.342407" y="53.020111" textLength="4.442996" font-size="8px">8</text>
<text x="154.798386" y="59.860291" textLength="4.232272" font-size="8px">2</text>
<text x="29.818466" y="60.460114" textLength="4.232272" font-size="8px">5</text>
<text x="25.559555" y="60.460114" textLength="4.232272" font-size="8px">2</text>
<text x="347.097839" y="139.120468" textLength="5.077204" font-size="8px">E</text>
<text x="341.579163" y="139.120468" textLength="5.495864" font-size="8px">D</text>
<text x="16.197571" y="75.580414" textLength="4.232272" font-size="8px">1</text>
<text x="85.736832" y="10.600098" textLength="4.232272" font-size="8px">7</text>
<text x="357.007568" y="53.020111" textLength="2.221498" font-size="8px">]</text>
<text x="150.539474" y="59.860291" textLength="4.232272" font-size="8px">1</text>
<text x="295.981079" y="106.419983" textLength="4.442996" font-size="8px">7</text>
<text x="57.599838" y="26.019836" textLength="5.495864" font-size="8px">R</text>
<text x="361.557739" y="26.260132" textLength="5.495864" font-size="8px">C</text>
<text x="189.358383" y="123.160278" textLength="4.232272" font-size="8px">2</text>
<text x="356.159302" y="26.260132" textLength="5.495864" font-size="8px">R</text>
<text x="159.057297" y="59.860291" textLength="4.232272" font-size="8px">8</text>
<text x="339.181274" y="53.020111" textLength="4.442996" font-size="8px">8</text>
<text x="185.099472" y="123.160278" textLength="4.232272" font-size="8px">1</text>
<text x="77.459549" y="10.600098" textLength="4.232272" font-size="8px">1</text>
<text x="312.119141" y="75.820465" textLength="5.495864" font-size="8px">R</text>
<text x="307.313721" y="59.860107" textLength="4.232272" font-size="8px">8</text>
<text x="45.178741" y="138.880402" textLength="5.077204" font-size="8px">S</text>
<text x="174.837509" y="59.860107" textLength="4.232272" font-size="8px">5</text>
<text x="325.863464" y="53.020111" textLength="6.656503" font-size="8px">m</text>
<text x="205.078476" y="123.160110" textLength="4.232272" font-size="8px">2</text>
<text x="275.942871" y="106.419983" textLength="6.656503" font-size="8px">m</text>
<text x="307.019104" y="75.820465" textLength="5.077204" font-size="8px">S</text>
<text x="218.458206" y="10.000092" textLength="4.232272" font-size="8px">2</text>
<text x="345.908081" y="53.020111" textLength="4.442996" font-size="8px">7</text>
<text x="333.295776" y="123.160110" textLength="4.232272" font-size="8px">0</text>
</svg>
<figcaption>Figure 4-7.  256-bit VPALIGN Instruction Operation
</figcaption></figure>
```

### Operation
#### PALIGNR (with 64-bit operands)
```info-verb
    temp1[127:0] = CONCATENATE(DEST,SRC)>>(imm8*8) 
    DEST[63:0] = temp1[63:0] 
```
#### PALIGNR (with 128-bit operands)
```info-verb
temp1[255:0] <-  ((DEST[127:0] << 128) OR SRC[127:0])>>(imm8*8);
DEST[127:0] <-  temp1[127:0]
DEST[VLMAX-1:128] (Unmodified)
```
#### VPALIGNR (VEX.128 encoded version)
```info-verb
temp1[255:0] <-  ((SRC1[127:0] << 128) OR SRC2[127:0])>>(imm8*8);
DEST[127:0] <-  temp1[127:0]
DEST[VLMAX-1:128] <-  0
```
#### VPALIGNR (VEX.256 encoded version)
```info-verb
temp1[255:0] <-  ((SRC1[127:0] << 128) OR SRC2[127:0])>>(imm8[7:0]*8);
DEST[127:0] <-  temp1[127:0]
temp1[255:0] <-  ((SRC1[255:128] << 128) OR SRC2[255:128])>>(imm8[7:0]*8);
DEST[MAX_VL-1:128] <-  temp1[127:0]
```
#### VPALIGNR (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR l <-  0 TO VL-1 with increments of 128
    temp1[255:0] <- ((SRC1[l+127:l] << 128) OR SRC2[l+127:l])>>(imm8[7:0]*8);
    TMP_DEST[l+127:l] <- temp1[127:0]
ENDFOR;
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  TMP_DEST[i+7:i]
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

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
PALIGNR:  __m64 _mm_alignr_pi8 (__m64 a, __m64 b, int n)
(V)PALIGNR:  __m128i _mm_alignr_epi8 (__m128i a, __m128i b, int n)
VPALIGNR:  __m256i _mm256_alignr_epi8 (__m256i a, __m256i b, const int n)
VPALIGNR __m512i _mm512_alignr_epi8 (__m512i a, __m512i b, const int n)
VPALIGNR __m512i _mm512_mask_alignr_epi8 (__m512i s, __mmask64 m, __m512i a, __m512i b, const int n)
VPALIGNR __m512i _mm512_maskz_alignr_epi8 ( __mmask64 m, __m512i a, __m512i b, const int n)
VPALIGNR __m256i _mm256_mask_alignr_epi8 (__m256i s, __mmask32 m, __m256i a, __m256i b, const int n)
VPALIGNR __m256i _mm256_maskz_alignr_epi8 (__mmask32 m, __m256i a, __m256i b, const int n)
VPALIGNR __m128i _mm_mask_alignr_epi8 (__m128i s, __mmask16 m, __m128i a, __m128i b, const int n)
VPALIGNR __m128i _mm_maskz_alignr_epi8 (__mmask16 m, __m128i a, __m128i b, const int n)
```
### SIMD Floating-Point Exceptions 


None. 

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

