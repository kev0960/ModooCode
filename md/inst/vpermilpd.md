----------------------------
title : VPERMILPD (Intel x86/64 assembly instruction)
cat_title : VPERMILPD
ref_title : VPERMILPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPERMILPD

**Permute In-Lane of Pairs of Double-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.128.66.0F38.W0 0D /r`\newline{}`VPERMILPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Permute double-precision floating-point values in xmm2 using controls from xmm3/m128 and store result in xmm1.|
|`VEX.NDS.256.66.0F38.W0 0D /r`\newline{}`VPERMILPD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX|Permute double-precision floating-point values in ymm2 using controls from ymm3/m256 and store result in ymm1.|
|`EVEX.NDS.128.66.0F38.W1 0D /r`\newline{}`VPERMILPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m64bcst |FV-RVM|V/V|AVX512VL\newline{}AVX512F|Permute double-precision floating-point values in xmm2 using control from xmm3/m128/m64bcst and store the result in xmm1 using writemask k1. |
|`EVEX.NDS.256.66.0F38.W1 0D /r`\newline{}`VPERMILPD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m64bcst |FV-RVM|V/V|AVX512VL\newline{}AVX512F|Permute double-precision floating-point values in ymm2 using control from ymm3/m256/m64bcst and store the result in ymm1 using writemask k1. |
|`EVEX.NDS.512.66.0F38.W1 0D /r `\newline{}`VPERMILPD` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512/m64bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 64 비트 메모리 주소값에 불러온 벡터 데이터.} |FV-RVM|V/V|AVX512F|Permute double-precision floating-point values in zmm2 using control from zmm3/m512/m64bcst and store the result in zmm1 using writemask k1. |
|`VEX.128.66.0F3A.W0 05 /r ib`\newline{}`VPERMILPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RM|V/V|AVX|Permute double-precision floating-point values in xmm2/m128 using controls from imm8.|
|`VEX.256.66.0F3A.W0 05 /r ib`\newline{}`VPERMILPD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RM|V/V|AVX|Permute double-precision floating-point values in ymm2/m256 using controls from imm8.|
|`EVEX.128.66.0F3A.W1 05 /r ib`\newline{}`VPERMILPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} xmm2/m128/m64bcst \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV-RM|V/V|AVX512VL\newline{}AVX512F|Permute double-precision floating-point values in xmm2/m128/m64bcst using controls from imm8 and store the result in xmm1 using writemask k1. |
|`EVEX.256.66.0F3A.W1 05 /r ib`\newline{}`VPERMILPD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} ymm2/m256/m64bcst \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV-RM|V/V|AVX512VL\newline{}AVX512F|Permute double-precision floating-point values in ymm2/m256/m64bcst using controls from imm8 and store the result in ymm1 using writemask k1. |
|`EVEX.512.66.0F3A.W1 05 /r ib`\newline{}`VPERMILPD` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512/m64bcst}{ZMM 레지스터나 512 비트 메모리 데이터나, 64 비트 메모리 주소값에 불러온 벡터 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV-RM|V/V|AVX512F|Permute double-precision floating-point values in zmm2/m512/m64bcst using controls from imm8 and store the result in zmm1 using writemask k1. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FV-RVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


(variable control version)

Permute pairs of double-precision floating-point values in the first source operand (second operand), each using a 1-bit control field residing in the corresponding quadword element of the second source operand (third operand). Permuted results are stored in the destination operand (first operand). 

The control bits are located at bit 0 of each quadword element (see Figure 5-24). Each control determines which of the source element in an input pair is selected for the destination element. Each pair of source elements must lie in the same 128-bit region as the destination.

EVEX version: The second source operand (third operand) is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. Permuted results are written to the destination under the writemask.

VEX.256 encoded version: Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed. 

(immediate control version)

Permute pairs of double-precision floating-point values in the first source operand (second operand), each pair using a 1-bit control field in the imm8 byte. Each element in the destination operand (first operand) use a separate control bit of the imm8 byte.

VEX version: The source operand is a YMM/XMM register or a 256/128-bit memory location and the destination operand is a YMM/XMM register. Imm8 byte provides the lower 4/2 bit as permute control fields.

EVEX version: The source operand (second operand) is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. Permuted results are written to the destination under the writemask. Imm8 byte provides the lower 8/4/2 bit as permute control fields.

Note: For the imm8 versions, VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instruction will #UD.

```embed
<figure>
<svg viewBox="0 0 479.220032 143.959991">
<rect x="0.000000" y="10.000000" width="0.480010" height="116.820000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="478.679993" y="10.000000" width="0.480040" height="116.820000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="479.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="126.820007" width="479.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.139999" y="99.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="103.139999" y="99.519989" width="74.519997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.179993" y="99.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="102.899994" y="113.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="102.899994" y="99.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.419998" y="99.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="177.419998" y="99.519989" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400009" y="99.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.179993" y="113.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.179993" y="99.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.639999" y="99.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="251.639999" y="99.519989" width="74.519997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.679993" y="99.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400009" y="113.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400009" y="99.520020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.919983" y="99.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="325.919983" y="99.519989" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="399.900024" y="99.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.679993" y="113.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.679993" y="99.520020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.139999" y="32.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="103.139999" y="32.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.179993" y="32.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="102.899994" y="45.519958" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="102.899994" y="32.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.419998" y="32.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="177.419998" y="32.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400009" y="32.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.179993" y="45.519958" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.179993" y="32.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M300.780029,85.960022 L301.140015,86.080017 L301.559998,86.080017 L301.739990,86.020020 L301.920044,85.900024 L302.040039,85.780029 L302.280029,85.420013 L302.280029,85.240021 L302.340027,85.060028 L302.280029,84.880035 L302.220032,84.700012 L302.160034,84.520020 L301.980042,84.400024 L301.859985,84.280029 L301.679993,84.160034 L301.500000,84.100037 L301.080017,84.100037 L300.900024,84.160034 L300.720032,84.280029 L300.600037,84.400024 L300.480042,84.580017 C300.189026 84.964020,300.289001 85.089020,300.420044 85.480011  L300.480042,85.660034 L300.600037,85.840027 L300.780029,85.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.320007,85.119995 L304.919983,87.399994 L305.460022,87.820007 L304.979980,88.239990 L293.399963,98.679993 L292.140015,99.820007 L292.619995,98.139984 L296.940002,83.139984 L297.119995,82.479980 L297.659973,82.839996 L297.899963,83.440002 L293.580017,98.380005 L292.619995,98.139984 L292.739990,97.899994 L304.320007,87.459991 L304.979980,88.239990 L304.380005,88.299988 L300.779968,86.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.659973,82.839996 L301.320007,85.119995 L300.779968,86.019989 L297.119995,83.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.080017,85.540009 L304.679993,87.820007 L293.099976,98.260010 L297.419983,83.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M326.760010,46.299988 L325.080017,45.279968 L300.479980,84.639984 L302.159973,85.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.139999,86.740021 L208.259995,86.620026 L208.379990,86.440033 C208.849014 85.440033,208.030991 84.709015,207.060013 85.000031  L206.939987,85.120026 L206.759995,85.240021 C206.134995 86.105011,206.732010 87.056030,207.780014 86.920013  L207.960007,86.860016 L208.139999,86.740021" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M207.539993,85.960022 L210.960007,83.380035 L211.559982,83.020020 L211.740005,83.620026 L217.259995,98.200012 L217.919998,99.820007 L216.479996,98.740021 L204.059982,89.320007 L203.520004,88.900024 L204.059982,88.540009 L204.659988,88.540009 L217.080002,97.960022 L216.479996,98.740021 L216.300003,98.500031 L210.779984,83.920013 L211.740005,83.620026 L211.559982,84.160034 L208.139999,86.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.060013,88.540009 L207.540024,85.960022 L208.139999,86.740021 L204.660019,89.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M207.840012,86.320007 L211.260025,83.740021 L216.780014,98.320007 L204.360001,88.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.199997,45.160034 L176.639999,46.360046 L206.759995,86.500031 L208.319992,85.300049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.639999" y="32.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="251.639999" y="32.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.679993" y="32.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400009" y="45.519958" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400009" y="32.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.919983" y="32.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="325.919983" y="32.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="399.900024" y="32.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.679993" y="45.519958" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.679993" y="32.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M356.640015,86.740021 L356.760010,86.620026 L356.880005,86.440033 C357.349976 85.391022,356.507996 84.725006,355.559998 85.000031  L355.440002,85.120026 L355.260010,85.240021 C354.630981 86.083008,355.281982 87.060028,356.280029 86.920013  L356.460022,86.860016 L356.640015,86.740021" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M356.039978,85.960022 L359.460022,83.380035 L360.059998,83.020020 L360.239990,83.620026 L365.760010,98.200012 L366.419983,99.820007 L364.979980,98.740021 L352.559998,89.320007 L352.020020,88.900024 L352.559998,88.540009 L353.159973,88.540009 L365.580017,97.960022 L364.979980,98.740021 L364.799988,98.500031 L359.279968,83.920013 L360.239990,83.620026 L360.059998,84.160034 L356.640015,86.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M352.559998,88.540009 L356.040039,85.960022 L356.640015,86.740021 L353.160034,89.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M356.340027,86.320007 L359.760010,83.740021 L365.280029,98.320007 L352.859985,88.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M326.700012,45.160034 L325.140015,46.360046 L355.260010,86.500031 L356.820007,85.300049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.279999,85.960022 L152.639999,86.080017 L153.059998,86.080017 L153.240005,86.020020 L153.360001,85.900024 L153.539993,85.780029 L153.660004,85.600037 L153.779999,85.240021 L153.779999,84.880035 L153.720001,84.700012 L153.600006,84.520020 L153.360001,84.280029 L153.179993,84.160034 L152.940002,84.100037 L152.580002,84.100037 L152.399994,84.160034 L152.220001,84.280029 L152.100006,84.400024 L151.979996,84.580017 C151.688995 84.964020,151.789001 85.089020,151.919998 85.480011  L151.979996,85.660034 L152.100006,85.840027 L152.279999,85.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.759995,85.119995 L156.419998,87.399994 L156.959991,87.820007 L156.479996,88.239990 L144.899994,98.679993 L143.639999,99.820007 L144.119995,98.139984 L148.439987,83.139984 L148.619995,82.479980 L149.159988,82.839996 L149.399994,83.440002 L145.080002,98.380005 L144.119995,98.139984 L144.239990,97.899994 L155.819992,87.459991 L156.479996,88.239990 L155.879990,88.299988 L152.220001,86.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M149.160004,82.839996 L152.760010,85.119995 L152.220001,86.019989 L148.620010,83.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.520004,85.540009 L156.180008,87.820007 L144.600006,98.260010 L148.919998,83.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.259995,46.299988 L176.580002,45.279968 L151.979996,84.639984 L153.659988,85.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="366.720032" y="40.780029" textLength="4.170000" font-size="8px">0</text>
<text x="361.739990" y="40.780029" textLength="5.002500" font-size="8px">X</text>
<text x="292.440002" y="40.780029" textLength="4.170000" font-size="8px">1</text>
<text x="98.996994" y="42.400024" textLength="4.170000" font-size="8px">1</text>
<text x="88.199997" y="42.400024" textLength="5.415000" font-size="8px">R</text>
<text x="218.280014" y="40.780029" textLength="4.170000" font-size="8px">2</text>
<text x="213.240005" y="40.780029" textLength="5.002500" font-size="8px">X</text>
<text x="380.041504" y="108.279999" textLength="4.170000" font-size="8px">1</text>
<text x="372.960022" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="366.720032" y="108.279999" textLength="4.170000" font-size="8px">0</text>
<text x="361.739990" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="305.762207" y="108.279999" textLength="4.170000" font-size="8px">1</text>
<text x="300.789001" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="298.687500" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="296.631714" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="292.433228" y="108.279999" textLength="4.170000" font-size="8px">0</text>
<text x="221.218491" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="212.099991" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="137.880005" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="82.860031" y="108.279999" textLength="5.415000" font-size="8px">D</text>
<text x="287.460022" y="40.780029" textLength="5.002500" font-size="8px">X</text>
<text x="225.421494" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="93.238525" y="108.279999" textLength="5.002500" font-size="8px">S</text>
<text x="149.160004" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="83.160004" y="42.400024" textLength="5.002500" font-size="8px">S</text>
<text x="138.960007" y="40.780029" textLength="5.002500" font-size="8px">X</text>
<text x="93.598495" y="42.400024" textLength="5.415000" font-size="8px">C</text>
<text x="217.080002" y="108.279999" textLength="4.170000" font-size="8px">2</text>
<text x="98.278519" y="108.279999" textLength="4.582500" font-size="8px">T</text>
<text x="223.319992" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="375.061523" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="151.201508" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="147.058502" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="142.860001" y="108.279999" textLength="4.170000" font-size="8px">2</text>
<text x="143.940002" y="40.780029" textLength="4.170000" font-size="8px">3</text>
<text x="230.401505" y="108.279999" textLength="4.170000" font-size="8px">3</text>
<text x="287.460022" y="108.279999" textLength="5.002500" font-size="8px">X</text>
<text x="370.858521" y="108.279999" textLength="2.085000" font-size="8px">.</text>
<text x="88.255524" y="108.279999" textLength="5.002500" font-size="8px">E</text>
<text x="156.241501" y="108.279999" textLength="4.170000" font-size="8px">3</text>
</svg>
<figcaption>Figure 5-23.  VPERMILPD Operation
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 471.840057 137.039795">
<rect x="0.000000" y="10.060028" width="0.480000" height="109.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="471.360016" y="10.060028" width="0.480040" height="109.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="471.839996" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="119.620026" width="471.839996" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="383.820007" y="46.240021" width="17.219999" height="35.520000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="383.820007" y="45.760010" width="17.760000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="400.559998" y="46.240021" width="1.020000" height="36.060001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="383.339996" y="81.280029" width="17.700001" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="383.339996" y="45.760010" width="1.020000" height="36.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.040001" y="46.000000" width="71.459999" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="53.040001" y="45.760010" width="71.699997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="124.260002" y="46.000031" width="0.480000" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.800003" y="81.760010" width="71.699997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.800003" y="45.760010" width="0.480000" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="401.339996" y="46.000000" width="19.020000" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="401.339996" y="45.520020" width="19.559999" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="419.880005" y="46.000000" width="1.020000" height="36.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="400.860016" y="81.520020" width="19.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="400.860016" y="45.519989" width="1.020000" height="36.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.800018" y="46.240021" width="17.219999" height="35.520000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="274.800018" y="45.760010" width="17.760000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="291.540009" y="46.240021" width="1.020000" height="36.060001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.320007" y="81.280029" width="17.700001" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.320007" y="45.760010" width="1.020000" height="36.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.320007" y="46.000000" width="19.020000" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="292.320007" y="45.520020" width="19.559999" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.860016" y="46.000000" width="1.020000" height="36.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="291.839996" y="81.520020" width="19.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="291.839996" y="45.519989" width="1.020000" height="36.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="125.820000" y="46.240021" width="17.219999" height="35.520000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="125.820000" y="45.760010" width="17.760000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.559998" y="46.240021" width="1.020000" height="36.060001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="125.340004" y="81.280029" width="17.700001" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="125.340004" y="45.760010" width="1.020000" height="36.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.339996" y="46.000000" width="18.959999" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="143.339996" y="45.520020" width="19.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="161.820007" y="46.000000" width="1.020000" height="36.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.860016" y="81.520020" width="19.440001" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.860016" y="45.519989" width="1.020000" height="36.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.500000" y="45.460022" width="71.519997" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.500000" y="45.220001" width="71.760002" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.779999" y="45.460022" width="0.479980" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.260010" y="81.220032" width="71.760002" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.260010" y="45.220032" width="0.480010" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M311.040009,46.000000 L382.559998,46.000000 L382.559998,82.000000 L311.040009,82.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="311.040009" y="45.760010" width="71.760002" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="382.320007" y="46.000031" width="0.480010" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.800018" y="81.760010" width="71.760002" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.800018" y="45.760010" width="0.480010" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="361.958679" y="67.960022" textLength="4.564900" font-size="8px">d</text>
<text x="355.005432" y="67.960022" textLength="3.040223" font-size="8px">r</text>
<text x="339.000000" y="67.960022" textLength="2.538084" font-size="8px">i</text>
<text x="202.499969" y="42.220093" textLength="4.980000" font-size="8px">1</text>
<text x="253.518890" y="67.420013" textLength="4.564900" font-size="8px">d</text>
<text x="249.511810" y="67.420013" textLength="4.053631" font-size="8px">e</text>
<text x="241.999817" y="67.420013" textLength="4.564900" font-size="8px">o</text>
<text x="58.079758" y="42.700012" textLength="4.980000" font-size="8px">5</text>
<text x="53.040001" y="42.700012" textLength="4.980000" font-size="8px">2</text>
<text x="137.219666" y="42.220001" textLength="4.980000" font-size="8px">3</text>
<text x="132.179901" y="42.220001" textLength="4.980000" font-size="8px">9</text>
<text x="286.321808" y="68.440002" textLength="2.282450" font-size="8px"> </text>
<text x="283.200012" y="42.220001" textLength="4.980000" font-size="8px">5</text>
<text x="149.568146" y="104.200012" textLength="2.490000" font-size="8px"> </text>
<text x="144.586151" y="104.200012" textLength="4.980000" font-size="8px">d</text>
<text x="123.738884" y="104.200012" textLength="2.768880" font-size="8px">l</text>
<text x="118.756889" y="104.200012" textLength="4.980000" font-size="8px">o</text>
<text x="102.645592" y="104.200012" textLength="4.980000" font-size="8px">o</text>
<text x="289.841766" y="104.200012" textLength="2.768880" font-size="8px">l</text>
<text x="282.602844" y="104.200012" textLength="2.768880" font-size="8px">i</text>
<text x="277.070068" y="104.200012" textLength="5.537760" font-size="8px">F</text>
<text x="260.672943" y="104.200012" textLength="2.768880" font-size="8px">t</text>
<text x="406.627686" y="104.200012" textLength="4.980000" font-size="8px">1</text>
<text x="380.791504" y="104.200012" textLength="2.768880" font-size="8px">l</text>
<text x="364.675262" y="104.200012" textLength="4.980000" font-size="8px">n</text>
<text x="99.972649" y="67.960022" textLength="4.053631" font-size="8px">e</text>
<text x="92.545555" y="67.960022" textLength="4.564900" font-size="8px">o</text>
<text x="83.521660" y="67.960022" textLength="4.564900" font-size="8px">g</text>
<text x="185.519989" y="71.980011" textLength="4.500000" font-size="8px"> </text>
<text x="392.819214" y="68.440002" textLength="2.538084" font-size="8px">l</text>
<text x="385.320007" y="68.440002" textLength="3.551492" font-size="8px">s</text>
<text x="389.700012" y="41.740021" textLength="4.980000" font-size="8px">1</text>
<text x="230.520020" y="67.420013" textLength="2.538084" font-size="8px">i</text>
<text x="394.391846" y="104.200012" textLength="4.422240" font-size="8px">e</text>
<text x="207.539734" y="42.220093" textLength="4.980000" font-size="8px">2</text>
<text x="130.818542" y="68.440002" textLength="4.053631" font-size="8px">e</text>
<text x="107.685356" y="104.200012" textLength="4.980000" font-size="8px">n</text>
<text x="271.786316" y="104.200012" textLength="2.768880" font-size="8px">l</text>
<text x="375.805542" y="104.200012" textLength="4.980000" font-size="8px">o</text>
<text x="404.520020" y="32.200012" textLength="6.643320" font-size="8px">B</text>
<text x="372.482880" y="104.200012" textLength="3.316680" font-size="8px">r</text>
<text x="88.033607" y="67.960022" textLength="4.564900" font-size="8px">n</text>
<text x="388.818542" y="68.440002" textLength="4.053631" font-size="8px">e</text>
<text x="311.039948" y="42.700073" textLength="4.980000" font-size="8px">6</text>
<text x="257.520020" y="41.740021" textLength="4.980000" font-size="8px">6</text>
<text x="103.973320" y="67.960022" textLength="4.564900" font-size="8px">d</text>
<text x="297.580658" y="104.200012" textLength="2.490000" font-size="8px"> </text>
<text x="383.613159" y="104.200012" textLength="2.490000" font-size="8px"> </text>
<text x="369.661224" y="104.200012" textLength="2.768880" font-size="8px">t</text>
<text x="96.985374" y="67.960022" textLength="3.040223" font-size="8px">r</text>
<text x="212.519745" y="42.220093" textLength="4.980000" font-size="8px">7</text>
<text x="152.088043" y="104.200012" textLength="4.980000" font-size="8px">4</text>
<text x="263.434845" y="104.200012" textLength="3.316680" font-size="8px">r</text>
<text x="115.438225" y="104.200012" textLength="3.316680" font-size="8px">r</text>
<text x="112.667351" y="104.200012" textLength="2.768880" font-size="8px">t</text>
<text x="357.975342" y="67.960022" textLength="4.053631" font-size="8px">e</text>
<text x="134.819214" y="68.440002" textLength="2.538084" font-size="8px">l</text>
<text x="126.509758" y="104.200012" textLength="2.490000" font-size="8px"> </text>
<text x="172.019989" y="71.980011" textLength="4.500000" font-size="8px">.</text>
<text x="274.550201" y="104.200012" textLength="2.490000" font-size="8px"> </text>
<text x="244.019836" y="104.200012" textLength="6.643320" font-size="8px">C</text>
<text x="118.019768" y="42.220001" textLength="4.980000" font-size="8px">4</text>
<text x="127.320000" y="68.440002" textLength="3.551492" font-size="8px">s</text>
<text x="137.340851" y="68.440002" textLength="2.282450" font-size="8px"> </text>
<text x="359.689301" y="104.200012" textLength="4.980000" font-size="8px">o</text>
<text x="341.521637" y="67.960022" textLength="4.564900" font-size="8px">g</text>
<text x="398.820068" y="104.200012" textLength="2.768880" font-size="8px">l</text>
<text x="283.798340" y="68.440002" textLength="2.538084" font-size="8px">l</text>
<text x="237.481476" y="67.420013" textLength="4.564900" font-size="8px">n</text>
<text x="137.391052" y="104.200012" textLength="4.422240" font-size="8px">e</text>
<text x="276.300018" y="68.440002" textLength="3.551492" font-size="8px">s</text>
<text x="112.980003" y="42.220001" textLength="4.980000" font-size="8px">9</text>
<text x="266.746552" y="104.200012" textLength="4.980000" font-size="8px">o</text>
<text x="81.000008" y="67.960022" textLength="2.538084" font-size="8px">i</text>
<text x="108.000008" y="42.220001" textLength="4.980000" font-size="8px">1</text>
<text x="176.519989" y="71.980011" textLength="4.500000" font-size="8px"> </text>
<text x="285.424500" y="104.200012" textLength="4.422240" font-size="8px">e</text>
<text x="181.019989" y="71.980011" textLength="4.500000" font-size="8px">.</text>
<text x="141.815277" y="104.200012" textLength="2.768880" font-size="8px">l</text>
<text x="129.029633" y="104.200012" textLength="5.537760" font-size="8px">F</text>
<text x="366.059998" y="42.220001" textLength="4.980000" font-size="8px">2</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">d</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">e</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">r</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">o</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">n</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">g</text>
<text x="154.320007" y="77.740021" textLength="0.000000" font-size="8px">i</text>
<text x="413.942169" y="32.200012" textLength="2.768880" font-size="8px">t</text>
<text x="63.059761" y="42.700012" textLength="4.980000" font-size="8px">5</text>
<text x="279.836914" y="68.440002" textLength="4.053631" font-size="8px">e</text>
<text x="278.220001" y="42.220001" textLength="4.980000" font-size="8px">6</text>
<text x="411.168304" y="32.200012" textLength="2.768880" font-size="8px">i</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">d</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">e</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">r</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">o</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">n</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">g</text>
<text x="412.320007" y="77.740021" textLength="0.000000" font-size="8px">i</text>
<text x="386.073273" y="104.200012" textLength="5.537760" font-size="8px">F</text>
<text x="391.617004" y="104.200012" textLength="2.768880" font-size="8px">i</text>
<text x="300.100525" y="104.200012" textLength="4.980000" font-size="8px">2</text>
<text x="350.510834" y="67.960022" textLength="4.564900" font-size="8px">o</text>
<text x="134.569397" y="104.200012" textLength="2.768880" font-size="8px">i</text>
<text x="255.633179" y="104.200012" textLength="4.980000" font-size="8px">n</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">d</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">e</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">r</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">o</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">n</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">g</text>
<text x="303.300018" y="77.740021" textLength="0.000000" font-size="8px">i</text>
<text x="250.658173" y="104.200012" textLength="4.980000" font-size="8px">o</text>
<text x="292.605652" y="104.200012" textLength="4.980000" font-size="8px">d</text>
<text x="346.016235" y="67.960022" textLength="4.564900" font-size="8px">n</text>
<text x="96.000282" y="104.200012" textLength="6.643320" font-size="8px">C</text>
<text x="127.199898" y="42.220001" textLength="4.980000" font-size="8px">1</text>
<text x="316.019958" y="42.700073" textLength="4.980000" font-size="8px">3</text>
<text x="190.019989" y="71.980011" textLength="4.500000" font-size="8px">.</text>
<text x="353.040009" y="104.200012" textLength="6.643320" font-size="8px">C</text>
<text x="401.641724" y="104.200012" textLength="4.980000" font-size="8px">d</text>
<text x="246.518158" y="67.420013" textLength="3.040223" font-size="8px">r</text>
<text x="233.041656" y="67.420013" textLength="4.564900" font-size="8px">g</text>
<text x="262.500031" y="41.740021" textLength="4.980000" font-size="8px">6</text>
<text x="395.340851" y="68.440002" textLength="2.282450" font-size="8px"> </text>
</svg>
<figcaption>Figure 5-24.  VPERMILPD Shuffle Control
</figcaption></figure>
```

### Operation
#### VPERMILPD (EVEX immediate versions)
```info-verb
(KL, VL) = (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF (EVEX.b = 1) AND (SRC1 *is memory*)
          THEN TMP_SRC1[i+63:i] <-  SRC1[63:0];
          ELSE TMP_SRC1[i+63:i] <-  SRC1[i+63:i];
    FI;
ENDFOR;
IF (imm8[0] = 0) THEN TMP_DEST[63:0] <-  SRC1[63:0]; FI;
IF (imm8[0] = 1) THEN TMP_DEST[63:0] <-  TMP_SRC1[127:64]; FI;
IF (imm8[1] = 0) THEN TMP_DEST[127:64] <-  TMP_SRC1[63:0]; FI;
IF (imm8[1] = 1) THEN TMP_DEST[127:64] <-  TMP_SRC1[127:64]; FI;
IF VL >= 256
    IF (imm8[2] = 0) THEN TMP_DEST[191:128] <-  TMP_SRC1[191:128]; FI;
    IF (imm8[2] = 1) THEN TMP_DEST[191:128] <-  TMP_SRC1[255:192]; FI;
    IF (imm8[3] = 0) THEN TMP_DEST[255:192] <-  TMP_SRC1[191:128]; FI;
    IF (imm8[3] = 1) THEN TMP_DEST[255:192] <-  TMP_SRC1[255:192]; FI;
FI;
IF VL >= 512
    IF (imm8[4] = 0) THEN TMP_DEST[319:256] <-  TMP_SRC1[319:256]; FI;
    IF (imm8[4] = 1) THEN TMP_DEST[319:256] <-  TMP_SRC1[383:320]; FI;
    IF (imm8[5] = 0) THEN TMP_DEST[383:320] <-  TMP_SRC1[319:256]; FI;
    IF (imm8[5] = 1) THEN TMP_DEST[383:320] <-  TMP_SRC1[383:320]; FI;
    IF (imm8[6] = 0) THEN TMP_DEST[447:384] <-  TMP_SRC1[447:384]; FI;
    IF (imm8[6] = 1) THEN TMP_DEST[447:384] <-  TMP_SRC1[511:448]; FI;
    IF (imm8[7] = 0) THEN TMP_DEST[511:448] <-  TMP_SRC1[447:384]; FI;
    IF (imm8[7] = 1) THEN TMP_DEST[511:448] <-  TMP_SRC1[511:448]; FI;
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
DEST[MAX_VL-1:VL] <-!= 0 
```
#### VPERMILPD (256-bit immediate version)
```info-verb
IF (imm8[0] = 0) THEN DEST[63:0]<- SRC1[63:0]
IF (imm8[0] = 1) THEN DEST[63:0]<- SRC1[127:64]
IF (imm8[1] = 0) THEN DEST[127:64]<- SRC1[63:0]
IF (imm8[1] = 1) THEN DEST[127:64]<- SRC1[127:64]
IF (imm8[2] = 0) THEN DEST[191:128]<- SRC1[191:128]
IF (imm8[2] = 1) THEN DEST[191:128]<- SRC1[255:192]
IF (imm8[3] = 0) THEN DEST[255:192]<- SRC1[191:128]
IF (imm8[3] = 1) THEN DEST[255:192]<- SRC1[255:192]
DEST[MAX_VL-1:256]<- 0
```
#### VPERMILPD (128-bit immediate version)
```info-verb
IF (imm8[0] = 0) THEN DEST[63:0]<- SRC1[63:0]
IF (imm8[0] = 1) THEN DEST[63:0]<- SRC1[127:64]
IF (imm8[1] = 0) THEN DEST[127:64]<- SRC1[63:0]
IF (imm8[1] = 1) THEN DEST[127:64]<- SRC1[127:64]
DEST[MAX_VL-1:128]<- 0
```
#### VPERMILPD (EVEX variable versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+63:i] <-  SRC2[63:0];
          ELSE TMP_SRC2[i+63:i] <-  SRC2[i+63:i];
    FI;
ENDFOR;
IF (TMP_SRC2[1] = 0) THEN TMP_DEST[63:0] <-  SRC1[63:0]; FI;
IF (TMP_SRC2[1] = 1) THEN TMP_DEST[63:0] <-  SRC1[127:64]; FI;
IF (TMP_SRC2[65] = 0) THEN TMP_DEST[127:64] <-  SRC1[63:0]; FI;
IF (TMP_SRC2[65] = 1) THEN TMP_DEST[127:64] <-  SRC1[127:64]; FI;
IF VL >= 256
    IF (TMP_SRC2[129] = 0) THEN TMP_DEST[191:128] <-  SRC1[191:128]; FI;
    IF (TMP_SRC2[129] = 1) THEN TMP_DEST[191:128] <-  SRC1[255:192]; FI;
    IF (TMP_SRC2[193] = 0) THEN TMP_DEST[255:192] <-  SRC1[191:128]; FI;
    IF (TMP_SRC2[193] = 1) THEN TMP_DEST[255:192] <-  SRC1[255:192]; FI;
FI;
IF VL >= 512
    IF (TMP_SRC2[257] = 0) THEN TMP_DEST[319:256] <-  SRC1[319:256]; FI;
    IF (TMP_SRC2[257] = 1) THEN TMP_DEST[319:256] <-  SRC1[383:320]; FI;
    IF (TMP_SRC2[321] = 0) THEN TMP_DEST[383:320] <-  SRC1[319:256]; FI;
    IF (TMP_SRC2[321] = 1) THEN TMP_DEST[383:320] <-  SRC1[383:320]; FI;
    IF (TMP_SRC2[385] = 0) THEN TMP_DEST[447:384] <-  SRC1[447:384]; FI;
    IF (TMP_SRC2[385] = 1) THEN TMP_DEST[447:384] <-  SRC1[511:448]; FI;
    IF (TMP_SRC2[449] = 0) THEN TMP_DEST[511:448] <-  SRC1[447:384]; FI;
    IF (TMP_SRC2[449] = 1) THEN TMP_DEST[511:448] <-  SRC1[511:448]; FI;
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
DEST[MAX_VL-1:VL] <-!= 0
```
#### VPERMILPD (256-bit variable version)
```info-verb
IF (SRC2[1] = 0) THEN DEST[63:0]<- SRC1[63:0]
IF (SRC2[1] = 1) THEN DEST[63:0]<- SRC1[127:64]
IF (SRC2[65] = 0) THEN DEST[127:64]<- SRC1[63:0]
IF (SRC2[65] = 1) THEN DEST[127:64]<- SRC1[127:64]
IF (SRC2[129] = 0) THEN DEST[191:128]<- SRC1[191:128]
IF (SRC2[129] = 1) THEN DEST[191:128]<- SRC1[255:192]
IF (SRC2[193] = 0) THEN DEST[255:192]<- SRC1[191:128]
IF (SRC2[193] = 1) THEN DEST[255:192]<- SRC1[255:192]
DEST[MAX_VL-1:256]<- 0
```
#### VPERMILPD (128-bit variable version)
```info-verb
IF (SRC2[1] = 0) THEN DEST[63:0]<- SRC1[63:0]
IF (SRC2[1] = 1) THEN DEST[63:0]<- SRC1[127:64]
IF (SRC2[65] = 0) THEN DEST[127:64]<- SRC1[63:0]
IF (SRC2[65] = 1) THEN DEST[127:64]<- SRC1[127:64]
DEST[MAX_VL-1:128]<- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPERMILPD __m512d _mm512_permute_pd( __m512d a, int imm);
VPERMILPD __m512d _mm512_mask_permute_pd(__m512d s, __mmask8 k, __m512d a, int imm);
VPERMILPD __m512d _mm512_maskz_permute_pd( __mmask8 k, __m512d a, int imm);
VPERMILPD __m256d _mm256_mask_permute_pd(__m256d  s, __mmask8 k, __m256d a, int imm);
VPERMILPD __m256d _mm256_maskz_permute_pd( __mmask8 k, __m256d a, int imm);
VPERMILPD __m128d _mm_mask_permute_pd(__m128d s, __mmask8 k, __m128d a, int imm);
VPERMILPD __m128d _mm_maskz_permute_pd( __mmask8 k, __m128d a, int imm);
VPERMILPD __m512d _mm512_permutevar_pd( __m512i i, __m512d a);
VPERMILPD __m512d _mm512_mask_permutevar_pd(__m512d s, __mmask8 k, __m512i i, __m512d a);
VPERMILPD __m512d _mm512_maskz_permutevar_pd( __mmask8 k, __m512i i, __m512d a);
VPERMILPD __m256d _mm256_mask_permutevar_pd(__m256d s, __mmask8 k, __m256d i, __m256d a);
VPERMILPD __m256d _mm256_maskz_permutevar_pd( __mmask8 k, __m256d i, __m256d a);
VPERMILPD __m128d _mm_mask_permutevar_pd(__m128d s, __mmask8 k, __m128d i, __m128d a);
VPERMILPD __m128d _mm_maskz_permutevar_pd( __mmask8 k, __m128d i, __m128d a);
VPERMILPD __m128d _mm_permute_pd (__m128d a, int control)
VPERMILPD __m256d _mm256_permute_pd (__m256d a, int control)
VPERMILPD __m128d _mm_permutevar_pd (__m128d a, __m128i control);
VPERMILPD __m256d _mm256_permutevar_pd (__m256d a, __m256i control);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4; additionally

#UD If VEX.W = 1.

EVEX-encoded instruction, see Exceptions Type E4NF.

#UD If either (E)VEX.vvvv != 1111B and with imm8.

