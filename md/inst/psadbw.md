----------------------------
title : PSADBW (Intel x86/64 assembly instruction)
cat_title : PSADBW
ref_title : PSADBW
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PSADBW

**Compute Sum of Absolute Differences**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|------------------------------------|---------------|
|0F F6 /r\footnote{1}\newline{}\newline{}PSADBW mm1, mm2/m64|RM|V/V|SSE|Computes the absolute differences of the packed unsigned byte integers from mm2 /m64 and mm1; differences are then summed to produce an unsigned word integer result.|
|66 0F F6 /r\newline{}\newline{}PSADBW xmm1, xmm2/m128|RM|V/V|SSE2|Computes the absolute differences of the packed unsigned byte integers from xmm2 /m128 and xmm1; the 8 low differences and 8 high differences are then summed separately to produce two unsigned word integer results.|
|VEX.NDS.128.66.0F.WIG F6 /r\newline{}\newline{}VPSADBW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Computes the absolute differences of the packed unsigned byte integers from xmm3 /m128 and xmm2; the 8 low differences and 8 high differences are then summed separately to produce two unsigned word integer results.|
|VEX.NDS.256.66.0F.WIG F6 /r\newline{}\newline{}VPSADBW ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Computes the absolute differences of the packed unsigned byte integers from ymm3 /m256 and ymm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.|
|EVEX.NDS.128.66.0F.WIG F6 /r\newline{}VPSADBW xmm1, xmm2, xmm3/m128|FVM|V/V|AVX512VLAVX512BW|Computes the absolute differences of the packed unsigned byte integers from xmm3 /m128 and xmm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.|
|EVEX.NDS.256.66.0F.WIG F6 /r\newline{}VPSADBW ymm1, ymm2, ymm3/m256|FVM|V/V|AVX512VLAVX512BW|Computes the absolute differences of the packed unsigned byte integers from ymm3 /m256 and ymm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.|
|EVEX.NDS.512.66.0F.WIG F6 /r\newline{}VPSADBW zmm1, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Computes the absolute differences of the packed unsigned byte integers from zmm3 /m512 and zmm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Computes the absolute value of the difference of 8 unsigned byte integers from the source operand (second 



operand) and from the destination operand (first operand). These 8 differences are then summed to produce an unsigned word integer result that is stored in the destination operand. Figure 4-14 shows the operation of the `PSADBW` instruction when using 64-bit operands.

When operating on 64-bit operands, the word integer result is stored in the low word of the destination operand, and the remaining bytes in the destination operand are cleared to all 0s.

When operating on 128-bit operands, two packed results are computed. Here, the 8 low-order bytes of the source and destination operands are operated on to produce a word result that is stored in the low word of the destination operand, and the 8 high-order bytes are operated on to produce a word result that is stored in bits 64 through 79 of the destination operand. The remaining bytes of the destination operand are cleared.

For 256-bit version, the third group of 8 differences are summed to produce an unsigned word in bits[143:128] of the destination register and the fourth group of 8 differences are summed to produce an unsigned word in bits[207:192] of the destination register. The remaining words of the destination are set to 0. 

For 512-bit version, the fifth group result is stored in bits [271:256] of the destination. The result from the sixth group is stored in bits [335:320]. The results for the seventh and eighth group are stored respectively in bits [399:384] and bits [463:447], respectively. The remaining bits in the destination are set to 0.

In 64-bit mode and not encoded by VEX/EVEX prefix, using a REX prefix in the form of REX.R permits this instruc-tion to access additional registers (XMM8-XMM15).

Legacy SSE version: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an MMX technology register.

128-bit Legacy SSE version: The first source operand and destination register are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX_VL-1:128) of the corresponding ZMM destination register remain unchanged.

VEX.128 and EVEX.128 encoded versions: The first source operand and destination register are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (MAX_VL-1:128) of the corre-sponding ZMM register are zeroed.

VEX.256 and EVEX.256 encoded versions: The first source operand and destination register are YMM registers. The second source operand is an YMM register or a 256-bit memory location. Bits (MAX_VL-1:256) of the corre-sponding ZMM register are zeroed.

EVEX.512 encoded version: The first source operand and destination register are ZMM registers. The second source operand is a ZMM register or a 512-bit memory location.

```embed
<figure>
<svg viewBox="0 0 379.679993 152.940002">
<rect x="0.000000" y="10.000000" width="0.480000" height="130.740005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="130.740005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="140.800018" width="379.679993" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.339996" y="22.540009" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.339996" y="22.300018" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.460007" y="22.540009" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.100006" y="40.300018" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.100006" y="22.300018" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.699997" y="22.540009" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="92.699997" y="22.300018" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.820007" y="22.540009" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.460007" y="40.300018" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.460007" y="22.300018" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.059998" y="22.540009" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.059998" y="22.300018" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="22.540009" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.820007" y="40.300018" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.820007" y="22.300018" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.419998" y="22.540009" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.419998" y="22.300018" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.599991" y="22.540009" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="40.300018" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="22.300018" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.020004" y="22.480011" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.020004" y="22.240021" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.139999" y="22.480011" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.780014" y="40.240021" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.780014" y="22.240021" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.379990,22.480011 L274.739990,22.480011 L274.739990,40.480011 L238.379990,40.480011" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.379990" y="22.240021" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.500000" y="22.480011" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.139999" y="40.240021" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.139999" y="22.240021" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.739990" y="22.480011" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="274.739990" y="22.240021" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.859985" y="22.480011" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.500000" y="40.240021" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.500000" y="22.240021" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.099976" y="22.480011" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="311.099976" y="22.240021" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="347.280029" y="22.480011" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.859985" y="40.240021" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.859985" y="22.240021" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.740005" y="52.480011" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="55.740005" y="52.239990" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.860001" y="52.480011" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.500000" y="70.239990" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.500000" y="52.240021" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.100006" y="52.480011" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="92.100006" y="52.239990" width="36.660000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.279999" y="52.480011" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.860001" y="70.239990" width="36.660000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.860001" y="52.240021" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.520004" y="52.480011" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.520004" y="52.239990" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.639999" y="52.480011" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.279999" y="70.239990" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.279999" y="52.240021" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.879990" y="52.480011" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="164.879990" y="52.239990" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.000015" y="52.480011" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.639999" y="70.239990" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.639999" y="52.240021" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419998" y="53.080017" width="36.360001" height="17.340000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.419998" y="52.840027" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.539993" y="53.080017" width="0.480010" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.180008" y="70.179993" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.180008" y="52.840027" width="0.479980" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.780014" y="53.080017" width="36.419998" height="17.340000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.780014" y="52.840027" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.960022" y="53.080017" width="0.479980" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.539993" y="70.179993" width="36.660000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.539993" y="52.840027" width="0.480010" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="53.080017" width="36.360001" height="17.340000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="274.200012" y="52.840027" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.320007" y="53.080017" width="0.480010" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.960022" y="70.179993" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.960022" y="52.840027" width="0.479980" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.559998" y="53.080017" width="36.360001" height="17.340000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="310.559998" y="52.840027" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="346.679993" y="53.080017" width="0.480010" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.320007" y="70.179993" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.320007" y="52.840027" width="0.480010" height="17.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.279999" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.279999" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.399994" y="81.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.039993" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.039993" y="81.160004" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.639999" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="92.639999" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.759995" y="81.400024" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.399994" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.399994" y="81.160004" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.059998" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.059998" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="81.400024" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.820007" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.820007" y="81.160004" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.419998" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.419998" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.539993" y="81.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="81.160004" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.960007" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.080002" y="81.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.719986" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.719986" y="81.160004" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="81.400024" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.319992" y="81.160034" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.500000" y="81.400024" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.080002" y="99.160019" width="36.660000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.080002" y="81.160004" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.739990" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="274.739990" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.859985" y="81.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.500000" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.500000" y="81.160004" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.099976" y="81.400024" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="311.099976" y="81.160034" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="347.219971" y="81.400024" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.859985" y="99.160019" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.859985" y="81.160004" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.580002" y="115.120010" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.580002" y="114.880020" width="36.660000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.759995" y="115.120010" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.339996" y="132.880020" width="36.660000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.339996" y="114.880005" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.000000" y="115.120010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="93.000000" y="114.880020" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="115.120010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.759995" y="132.880020" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.759995" y="114.880005" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.360001" y="115.120010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.360001" y="114.880020" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="115.120010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="132.880020" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="114.880005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.719986" y="115.120010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.719986" y="114.880020" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.840012" y="115.120010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="132.880020" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="114.880005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.259995" y="115.060013" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.259995" y="114.820007" width="36.660000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.439987" y="115.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.020004" y="132.820007" width="36.660000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.020004" y="114.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.680008" y="115.060013" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.680008" y="114.820007" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.799988" y="115.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.439987" y="132.820007" width="36.599998" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.439987" y="114.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.039978" y="115.060013" width="71.220001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="275.039978" y="114.820007" width="71.459999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="346.020020" y="115.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.799988" y="132.820007" width="71.459999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.799988" y="114.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="332.155823" y="125.260010" textLength="4.002000" font-size="8px">P</text>
<text x="327.157227" y="125.260010" textLength="4.998000" font-size="8px">M</text>
<text x="323.154602" y="125.260010" textLength="4.002000" font-size="8px">E</text>
<text x="317.806824" y="125.260010" textLength="1.668000" font-size="8px">.</text>
<text x="316.185608" y="125.260010" textLength="1.668000" font-size="8px">.</text>
<text x="314.517029" y="125.260010" textLength="1.668000" font-size="8px">.</text>
<text x="311.180420" y="125.260010" textLength="3.336000" font-size="8px">7</text>
<text x="307.220398" y="125.260010" textLength="4.002000" font-size="8px">P</text>
<text x="302.180420" y="125.260010" textLength="4.998000" font-size="8px">M</text>
<text x="294.553833" y="125.260010" textLength="3.666000" font-size="8px">T</text>
<text x="279.179993" y="125.260010" textLength="4.002000" font-size="8px">S</text>
<text x="112.978943" y="126.940002" textLength="5.769502" font-size="8px">H</text>
<text x="145.019669" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="140.520737" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="188.038406" y="126.940002" textLength="5.769502" font-size="8px">H</text>
<text x="183.599411" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="212.939987" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="31.860001" y="125.380005" textLength="5.769502" font-size="8px">D</text>
<text x="307.333801" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="303.975037" y="92.680023" textLength="3.336000" font-size="8px">1</text>
<text x="300.015015" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="298.326660" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="281.009460" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="270.927063" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="267.628235" y="92.680023" textLength="3.336000" font-size="8px">2</text>
<text x="263.605835" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="261.917480" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="252.616257" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="248.593857" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="234.731461" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="231.375046" y="92.680023" textLength="3.336000" font-size="8px">3</text>
<text x="227.355057" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="218.355057" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="216.375046" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="185.946060" y="92.680023" textLength="3.336000" font-size="8px">4</text>
<text x="181.986069" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="180.006058" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="168.001266" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="152.521225" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="149.222427" y="92.680023" textLength="3.336000" font-size="8px">5</text>
<text x="145.202438" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="143.222443" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="125.702423" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="122.343628" y="92.680023" textLength="3.336000" font-size="8px">6</text>
<text x="118.383621" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="113.338821" y="92.680023" textLength="3.336000" font-size="8px">6</text>
<text x="109.378815" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="107.360413" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="99.378006" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="88.935608" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="85.636810" y="92.680023" textLength="3.336000" font-size="8px">7</text>
<text x="72.604813" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="70.624817" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="58.620010" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="339.781860" y="92.680023" textLength="3.336000" font-size="8px">0</text>
<text x="335.762451" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="330.778259" y="92.680023" textLength="3.336000" font-size="8px">0</text>
<text x="326.758850" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="324.778809" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="316.739990" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="324.117065" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="256.558777" y="64.300018" textLength="4.442996" font-size="8px">2</text>
<text x="251.218369" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="218.819656" y="64.300018" textLength="4.442996" font-size="8px">3</text>
<text x="110.581345" y="34.300018" textLength="4.442996" font-size="8px">6</text>
<text x="141.720688" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="180.300430" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="47.825653" y="93.639587" textLength="5.329997" font-size="8px">P</text>
<text x="41.170746" y="93.639587" textLength="6.656503" font-size="8px">M</text>
<text x="30.961441" y="93.639587" textLength="4.882501" font-size="8px">T</text>
<text x="42.970306" y="62.680054" textLength="5.329997" font-size="8px">S</text>
<text x="37.635513" y="62.680054" textLength="5.329997" font-size="8px">E</text>
<text x="47.398926" y="33.759827" textLength="5.769502" font-size="8px">C</text>
<text x="324.717834" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="81.614410" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="293.998840" y="34.300018" textLength="4.442996" font-size="8px">1</text>
<text x="257.159485" y="34.300018" textLength="4.442996" font-size="8px">2</text>
<text x="219.420395" y="34.300018" textLength="4.442996" font-size="8px">3</text>
<text x="312.780029" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="285.031860" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="244.571457" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="204.370255" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="31.861221" y="62.680054" textLength="5.769502" font-size="8px">D</text>
<text x="276.987061" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="217.378983" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="319.488037" y="125.260010" textLength="3.666000" font-size="8px">T</text>
<text x="179.700516" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="189.305466" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="288.991821" y="92.680023" textLength="1.998000" font-size="8px">(</text>
<text x="62.580017" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="288.057678" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="251.819107" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="294.970215" y="92.680023" textLength="3.336000" font-size="8px">1</text>
<text x="283.182617" y="125.260010" textLength="4.332000" font-size="8px">U</text>
<text x="158.224838" y="92.680023" textLength="3.336000" font-size="8px">5</text>
<text x="339.457825" y="125.260010" textLength="1.998000" font-size="8px">)</text>
<text x="41.630219" y="33.759827" textLength="5.769502" font-size="8px">R</text>
<text x="141.120773" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="104.100952" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="108.539948" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="69.241013" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="103.400406" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="334.077026" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="258.618652" y="92.680023" textLength="3.336000" font-size="8px">2</text>
<text x="105.240967" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="73.680008" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="222.377457" y="92.680023" textLength="3.336000" font-size="8px">3</text>
<text x="104.641052" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="37.634293" y="125.380005" textLength="5.329997" font-size="8px">E</text>
<text x="78.119003" y="126.940002" textLength="5.769502" font-size="8px">H</text>
<text x="139.202438" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="190.993851" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="225.733871" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="259.554688" y="126.940002" textLength="5.769502" font-size="8px">H</text>
<text x="214.080002" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="75.121506" y="64.300018" textLength="4.442996" font-size="8px">7</text>
<text x="287.515198" y="125.260010" textLength="4.998000" font-size="8px">M</text>
<text x="185.640823" y="34.300018" textLength="4.442996" font-size="8px">4</text>
<text x="70.381027" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="250.676682" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="95.355606" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="48.303879" y="125.380005" textLength="4.882501" font-size="8px">T</text>
<text x="42.969086" y="125.380005" textLength="5.329997" font-size="8px">S</text>
<text x="171.961258" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="76.627213" y="92.680023" textLength="3.336000" font-size="8px">7</text>
<text x="175.983658" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="75.721420" y="34.300018" textLength="4.442996" font-size="8px">7</text>
<text x="154.202438" y="92.680023" textLength="4.002000" font-size="8px">Y</text>
<text x="146.461166" y="64.300018" textLength="4.442996" font-size="8px">5</text>
<text x="240.611465" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="213.539993" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="288.658447" y="34.300018" textLength="5.329997" font-size="8px">X</text>
<text x="255.115677" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="131.222427" y="92.680023" textLength="4.002000" font-size="8px">A</text>
<text x="179.160416" y="126.940002" textLength="4.442996" font-size="8px">0</text>
<text x="66.602417" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="79.926010" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="135.242432" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="149.458664" y="126.940002" textLength="5.769502" font-size="8px">H</text>
<text x="330.058228" y="34.300018" textLength="4.442996" font-size="8px">0</text>
<text x="69.781113" y="64.300018" textLength="5.329997" font-size="8px">Y</text>
<text x="48.305099" y="62.680054" textLength="4.882501" font-size="8px">T</text>
<text x="293.398071" y="64.300018" textLength="4.442996" font-size="8px">1</text>
<text x="147.000351" y="34.300018" textLength="4.442996" font-size="8px">5</text>
<text x="292.513794" y="125.260010" textLength="1.998000" font-size="8px">(</text>
<text x="116.695221" y="92.680023" textLength="1.668000" font-size="8px">:</text>
<text x="320.759399" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="329.457458" y="64.300018" textLength="4.442996" font-size="8px">0</text>
<text x="161.581253" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="35.842346" y="93.639587" textLength="5.329997" font-size="8px">E</text>
<text x="336.158386" y="125.260010" textLength="3.336000" font-size="8px">0</text>
<text x="194.953842" y="92.680023" textLength="3.336000" font-size="8px">4</text>
<text x="298.220398" y="125.260010" textLength="4.002000" font-size="8px">E</text>
<text x="109.981430" y="64.300018" textLength="4.442996" font-size="8px">6</text>
<text x="208.392654" y="92.680023" textLength="4.002000" font-size="8px">B</text>
<text x="212.352646" y="92.680023" textLength="4.002000" font-size="8px">S</text>
<text x="291.010254" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="221.817978" y="126.940002" textLength="5.769502" font-size="8px">H</text>
<text x="185.040909" y="64.300018" textLength="4.442996" font-size="8px">4</text>
<text x="343.080627" y="92.680023" textLength="1.998000" font-size="8px">)</text>
<text x="36.301025" y="33.759827" textLength="5.329997" font-size="8px">S</text>
<text x="254.596268" y="92.680023" textLength="4.002000" font-size="8px">X</text>
<text x="198.310257" y="92.680023" textLength="1.998000" font-size="8px">)</text>
</svg>
<figcaption>Figure 4-14.  PSADBW Instruction Operation Using 64-bit Operands
</figcaption></figure>
```

### Operation
#### VPSADBW (EVEX encoded versions)
```info-verb
VL = 128, 256, 512
TEMP0 <-   ABS(SRC1[7:0] - SRC2[7:0])
(* Repeat operation for bytes 1 through 15 *)
TEMP15  <-  ABS(SRC1[127:120] - SRC2[127:120])
DEST[15:0]  <- SUM(TEMP0:TEMP7)
DEST[63:16] <-   000000000000H
DEST[79:64]  <-  SUM(TEMP8:TEMP15)
DEST[127:80] <-   00000000000H
IF VL >= 256
    (* Repeat operation for bytes 16 through 31*)
    TEMP31 <-   ABS(SRC1[255:248] - SRC2[255:248])
    DEST[143:128] <-  SUM(TEMP16:TEMP23)
    DEST[191:144] <-   000000000000H
    DEST[207:192]  <-  SUM(TEMP24:TEMP31)
    DEST[223:208]  <-  00000000000H
FI;
IF VL >= 512
(* Repeat operation for bytes 32 through 63*)
    TEMP63 <-   ABS(SRC1[511:504] - SRC2[511:504])
    DEST[271:256]  <- SUM(TEMP0:TEMP7)
    DEST[319:272]  <-  000000000000H
    DEST[335:320]  <-  SUM(TEMP8:TEMP15)
    DEST[383:336] <-   00000000000H
    DEST[399:384]  <- SUM(TEMP16:TEMP23)
    DEST[447:400] <-   000000000000H
    DEST[463:448]  <-  SUM(TEMP24:TEMP31)
    DEST[511:464]  <-  00000000000H
FI;
DEST[MAX_VL-1:VL] <-   0
```
#### VPSADBW (VEX.256 encoded version)
```info-verb
TEMP0  <-  ABS(SRC1[7:0] - SRC2[7:0])
(* Repeat operation for bytes 2 through 30*)
TEMP31 <-   ABS(SRC1[255:248] - SRC2[255:248])
DEST[15:0]  <- SUM(TEMP0:TEMP7)
DEST[63:16]  <-  000000000000H
DEST[79:64]  <-  SUM(TEMP8:TEMP15)
DEST[127:80] <-   00000000000H
DEST[143:128] <-  SUM(TEMP16:TEMP23)
DEST[191:144] <-   000000000000H
DEST[207:192] <-   SUM(TEMP24:TEMP31)
DEST[223:208]  <-  00000000000H
DEST[MAX_VL-1:256]  <-  0
```
#### VPSADBW (VEX.128 encoded version)
```info-verb
TEMP0 <-   ABS(SRC1[7:0] - SRC2[7:0])
(* Repeat operation for bytes 2 through 14 *)
TEMP15 <-   ABS(SRC1[127:120] - SRC2[127:120])
DEST[15:0] <-  SUM(TEMP0:TEMP7)
DEST[63:16] <-   000000000000H
DEST[79:64] <-   SUM(TEMP8:TEMP15)
DEST[127:80]  <-  00000000000H
DEST[MAX_VL-1:128] <-   0
```
#### PSADBW (128-bit Legacy SSE version)
```info-verb
TEMP0  <-  ABS(DEST[7:0] - SRC[7:0])
(* Repeat operation for bytes 2 through 14 *)
TEMP15 <-   ABS(DEST[127:120] - SRC[127:120])
DEST[15:0]  <- SUM(TEMP0:TEMP7)
DEST[63:16]  <-  000000000000H
DEST[79:64] <-   SUM(TEMP8:TEMP15)
DEST[127:80]  <-  00000000000
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSADBW (64-bit operand)
```info-verb
TEMP0  <-  ABS(DEST[7:0] - SRC[7:0])
(* Repeat operation for bytes 2 through 6 *)
TEMP7 <-   ABS(DEST[63:56] - SRC[63:56])
DEST[15:0]  <- SUM(TEMP0:TEMP7)
DEST[63:16] <-   000000000000H
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPSADBW __m512i _mm512_sad_epu8( __m512i a, __m512i b)
PSADBW:__m64 _mm_sad_pu8(__m64 a,__m64 b)
(V)PSADBW:__m128i _mm_sad_epu8(__m128i a, __m128i b)
VPSADBW:__m256i _mm256_sad_epu8( __m256i a, __m256i b)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

