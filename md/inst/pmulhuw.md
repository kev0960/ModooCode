----------------------------
title : PMULHUW (Intel x86/64 assembly instruction)
cat_title : PMULHUW
ref_title : PMULHUW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PMULHUW

**Multiply Packed Unsigned Integers and Store High Result**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F E4 /r\footnote{1}\newline{}\newline{}PMULHUW mm1, mm2/m64|RM|V/V|SSE|Multiply the packed unsigned word integers in mm1 register and mm2/m64, and store the high 16 bits of the results in mm1. |
|66 0F E4 /r\newline{}\newline{}PMULHUW xmm1, xmm2/m128|RM|V/V|SSE2|Multiply the packed unsigned word integers in xmm1 and xmm2/m128, and store the high 16 bits of the results in xmm1.|
|VEX.NDS.128.66.0F.WIG E4 /r\newline{}\newline{}VPMULHUW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Multiply the packed unsigned word integers in xmm2 and xmm3/m128, and store the high 16 bits of the results in xmm1.|
|VEX.NDS.256.66.0F.WIG E4 /r\newline{}\newline{}VPMULHUW ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Multiply the packed unsigned word integers in ymm2 and ymm3/m256, and store the high 16 bits of the results in ymm1.|
|EVEX.NDS.128.66.0F.WIG E4 /r\newline{}VPMULHUW xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed unsigned word integers in xmm2 and xmm3/m128, and store the high 16 bits of the results in xmm1 under writemask k1.|
|EVEX.NDS.256.66.0F.WIG E4 /r\newline{}VPMULHUW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed unsigned word integers in ymm2 and ymm3/m256, and store the high 16 bits of the results in ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F.WIG E4 /r\newline{}VPMULHUW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Multiply the packed unsigned word integers in zmm2 and zmm3/m512, and store the high 16 bits of the results in zmm1 under writemask k1.|

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


Performs a SIMD unsigned multiply of the packed unsigned word integers in the destination operand (first operand) and the source operand (second operand), and stores the high 16 bits of each 32-bit intermediate results in the destination operand. (Figure 4-12 shows this operation when using 64-bit operands.)

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version 64-bit operand: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an MMX technology register.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.



VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.L must be 0, otherwise the instruction will #UD.

VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers.

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1.

```embed
<figure>
<svg viewBox="0 0 379.679993 157.579987">
<rect x="0.000000" y="10.000000" width="0.480000" height="118.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="118.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="128.440002" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.440002" y="76.419983" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="58.440002" y="76.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.199997" y="76.420044" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.199997" y="94.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="58.199997" y="76.179993" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.440002" y="76.419983" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="130.440002" y="76.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="76.420044" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.199997" y="94.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.199997" y="76.179993" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.439987" y="76.419983" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.439987" y="76.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="76.420044" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="94.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="76.179993" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.440002,76.419983 L346.440002,76.419983 L346.440002,94.419983 L274.440002,94.419983" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="274.440002" y="76.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="346.200012" y="76.420044" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="94.180054" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.200012" y="76.179993" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.419998" y="20.380005" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.419998" y="20.140015" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.599991" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="38.140015" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.840012" y="20.380005" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.840012" y="20.140015" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="20.380005" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.599991" y="38.140015" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.599991" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.199997" y="20.380005" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.199997" y="20.140015" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="38.140015" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.960007" y="20.140015" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.560013" y="20.380005" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.560013" y="20.140015" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.679993" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="38.140015" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.419998" y="46.600037" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.419998" y="46.360046" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.539993" y="46.600037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="64.360046" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.180008" y="46.360046" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.780014" y="46.600037" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.780014" y="46.360046" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="46.600037" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.539993" y="64.360046" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.539993" y="46.360046" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.139999" y="46.600037" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.139999" y="46.360046" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="46.600037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="64.360046" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="46.360046" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.560013" y="46.600037" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.560013" y="46.360046" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.679993" y="46.600037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="64.360046" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.319992" y="46.360046" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.360001" y="102.820007" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.360001" y="102.580017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="102.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="120.580017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.119995" y="102.580017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.719986" y="102.820007" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.719986" y="102.580017" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="102.820007" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="120.580017" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.479996" y="102.580017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.139999" y="102.820007" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="202.139999" y="102.580017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.259995" y="102.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="120.580017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.900009" y="102.580017" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.500015" y="102.820007" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.500015" y="102.580017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.619995" y="102.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.259995" y="120.580017" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.259995" y="102.580017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="266.256165" y="115.240021" textLength="4.071600" font-size="8px">6</text>
<text x="262.172729" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="252.636856" y="115.240021" textLength="4.071600" font-size="8px">3</text>
<text x="250.488297" y="115.240021" textLength="2.136720" font-size="8px">[</text>
<text x="246.404861" y="115.240021" textLength="4.071600" font-size="8px">0</text>
<text x="242.384079" y="115.240021" textLength="4.008960" font-size="8px">Z</text>
<text x="220.305557" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="216.222122" y="115.240021" textLength="4.071600" font-size="8px">3</text>
<text x="209.990128" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="196.910202" y="115.240021" textLength="2.136720" font-size="8px">]</text>
<text x="192.826767" y="115.240021" textLength="4.071600" font-size="8px">6</text>
<text x="187.374313" y="115.240021" textLength="1.357200" font-size="8px">:</text>
<text x="183.290878" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="172.975449" y="115.240021" textLength="4.071600" font-size="8px">2</text>
<text x="161.335556" y="115.240021" textLength="2.136720" font-size="8px">]</text>
<text x="153.168686" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="141.484238" y="115.240021" textLength="2.136720" font-size="8px">[</text>
<text x="137.400803" y="115.240021" textLength="4.071600" font-size="8px">3</text>
<text x="42.669464" y="88.299927" textLength="6.656503" font-size="8px">M</text>
<text x="37.341064" y="88.299927" textLength="5.329997" font-size="8px">E</text>
<text x="32.460159" y="88.299927" textLength="4.882501" font-size="8px">T</text>
<text x="253.137222" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="216.718246" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="185.039536" y="59.080017" textLength="4.442996" font-size="8px">2</text>
<text x="149.460403" y="59.080017" textLength="4.442996" font-size="8px">3</text>
<text x="144.120010" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="108.244659" y="113.200653" textLength="4.882501" font-size="8px">T</text>
<text x="97.575073" y="113.200653" textLength="5.329997" font-size="8px">E</text>
<text x="91.800781" y="113.200653" textLength="5.769502" font-size="8px">D</text>
<text x="107.165070" y="57.880554" textLength="4.882501" font-size="8px">T</text>
<text x="101.830276" y="57.880554" textLength="5.329997" font-size="8px">S</text>
<text x="96.495483" y="57.880554" textLength="5.329997" font-size="8px">E</text>
<text x="90.721191" y="57.880554" textLength="5.769502" font-size="8px">D</text>
<text x="224.388992" y="115.240021" textLength="1.357200" font-size="8px">:</text>
<text x="327.358704" y="87.460022" textLength="4.442996" font-size="8px">0</text>
<text x="322.021484" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="319.799988" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="313.619324" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="309.173889" y="87.460022" textLength="4.442996" font-size="8px">0</text>
<text x="301.619995" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="253.021500" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="250.800003" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="244.559311" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="177.539993" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="173.520004" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="166.801163" y="87.460022" textLength="4.442996" font-size="8px">2</text>
<text x="161.521500" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="159.300003" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="98.159286" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="93.713898" y="87.460022" textLength="4.442996" font-size="8px">3</text>
<text x="88.381500" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="86.160004" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="70.200485" y="87.459717" textLength="4.882501" font-size="8px">Z</text>
<text x="255.297623" y="31.780029" textLength="4.442996" font-size="8px">0</text>
<text x="181.859512" y="31.780029" textLength="4.442996" font-size="8px">2</text>
<text x="176.519119" y="31.780029" textLength="5.329997" font-size="8px">X</text>
<text x="151.799667" y="115.240021" textLength="1.357200" font-size="8px">:</text>
<text x="154.919998" y="87.460022" textLength="4.381020" font-size="8px">=</text>
<text x="258.477600" y="59.080017" textLength="4.442996" font-size="8px">0</text>
<text x="256.720276" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="96.050385" y="31.060364" textLength="5.769502" font-size="8px">R</text>
<text x="232.560013" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="152.639267" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="218.878616" y="31.780029" textLength="4.442996" font-size="8px">1</text>
<text x="101.819092" y="31.060364" textLength="5.769502" font-size="8px">C</text>
<text x="260.803711" y="115.240021" textLength="1.357200" font-size="8px">:</text>
<text x="214.073563" y="115.240021" textLength="2.136720" font-size="8px">[</text>
<text x="179.207443" y="115.240021" textLength="4.071600" font-size="8px">3</text>
<text x="229.841446" y="115.240021" textLength="4.071600" font-size="8px">6</text>
<text x="315.840027" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="102.909866" y="113.200653" textLength="5.329997" font-size="8px">S</text>
<text x="221.555222" y="87.460022" textLength="4.442996" font-size="8px">1</text>
<text x="171.300095" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="147.716232" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="79.560349" y="87.459717" textLength="2.221498" font-size="8px"> </text>
<text x="100.380005" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="216.661545" y="87.460022" textLength="4.882501" font-size="8px">Z</text>
<text x="111.975464" y="87.460022" textLength="4.442996" font-size="8px">3</text>
<text x="75.061417" y="87.459717" textLength="4.442996" font-size="8px">3</text>
<text x="185.102676" y="87.460022" textLength="4.442996" font-size="8px">2</text>
<text x="143.353729" y="87.460022" textLength="4.882501" font-size="8px">Z</text>
<text x="246.780014" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="240.113907" y="87.460022" textLength="4.442996" font-size="8px">1</text>
<text x="188.743332" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="168.954666" y="115.240021" textLength="4.008960" font-size="8px">Z</text>
<text x="222.058640" y="59.080017" textLength="4.442996" font-size="8px">1</text>
<text x="81.779999" y="87.460022" textLength="4.381020" font-size="8px">=</text>
<text x="148.200272" y="87.460022" textLength="4.442996" font-size="8px">2</text>
<text x="258.350708" y="87.460022" textLength="4.442996" font-size="8px">1</text>
<text x="146.280380" y="31.780029" textLength="4.442996" font-size="8px">3</text>
<text x="106.681427" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="294.973450" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="234.781509" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="225.758011" y="115.240021" textLength="4.071600" font-size="8px">1</text>
<text x="213.538223" y="31.780029" textLength="5.329997" font-size="8px">X</text>
<text x="270.339600" y="115.240021" textLength="2.136720" font-size="8px">]</text>
<text x="49.324371" y="88.299927" textLength="5.329997" font-size="8px">P</text>
<text x="297.239990" y="87.460022" textLength="4.381020" font-size="8px">=</text>
<text x="177.058884" y="115.240021" textLength="2.136720" font-size="8px">[</text>
<text x="143.632797" y="115.240021" textLength="4.071600" font-size="8px">3</text>
<text x="290.531250" y="87.460022" textLength="4.442996" font-size="8px">0</text>
<text x="285.649536" y="87.460022" textLength="4.882501" font-size="8px">Z</text>
<text x="205.969345" y="115.240021" textLength="4.008960" font-size="8px">Z</text>
<text x="90.721191" y="31.060364" textLength="5.329997" font-size="8px">S</text>
<text x="249.957230" y="31.780029" textLength="5.329997" font-size="8px">X</text>
<text x="179.699142" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="303.841492" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="179.761490" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="233.924881" y="115.240021" textLength="2.136720" font-size="8px">]</text>
<text x="226.009415" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="104.399994" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="157.252121" y="115.240021" textLength="4.071600" font-size="8px">6</text>
<text x="140.940002" y="31.780029" textLength="5.329997" font-size="8px">X</text>
<text x="133.380005" y="115.240021" textLength="4.008960" font-size="8px">Z</text>
<text x="228.180008" y="87.460022" textLength="4.381020" font-size="8px">=</text>
</svg>
<figcaption>Figure 4-12.  PMULHUW and PMULHW Instruction Operation Using 64-bit Operands
</figcaption></figure>
```

### Operation
#### PMULHUW (with 64-bit operands)
```info-verb
    TEMP0[31:0] <- DEST[15:0] `*` SRC[15:0]; (* Unsigned multiplication *)
    TEMP1[31:0] <- DEST[31:16] `*` SRC[31:16];
    TEMP2[31:0] <-  DEST[47:32] `*` SRC[47:32];
    TEMP3[31:0] <- DEST[63:48] `*` SRC[63:48];
    DEST[15:0] <-  TEMP0[31:16];
    DEST[31:16] <-  TEMP1[31:16];
    DEST[47:32] <-  TEMP2[31:16];
    DEST[63:48] <-  TEMP3[31:16];
```
#### PMULHUW (with 128-bit operands)
```info-verb
    TEMP0[31:0] <-  DEST[15:0] `*` SRC[15:0]; (* Unsigned multiplication *)
    TEMP1[31:0] <- DEST[31:16] `*` SRC[31:16];
    TEMP2[31:0] <-  DEST[47:32] `*` SRC[47:32];
    TEMP3[31:0] <- DEST[63:48] `*` SRC[63:48];
    TEMP4[31:0] <- DEST[79:64] `*` SRC[79:64];
    TEMP5[31:0] <-  DEST[95:80] `*` SRC[95:80];
    TEMP6[31:0] <-  DEST[111:96] `*` SRC[111:96];
    TEMP7[31:0] <- DEST[127:112] `*` SRC[127:112];
    DEST[15:0] <-  TEMP0[31:16];
    DEST[31:16] <-  TEMP1[31:16];
    DEST[47:32] <-  TEMP2[31:16];
    DEST[63:48] <-  TEMP3[31:16];
    DEST[79:64] <-  TEMP4[31:16];
    DEST[95:80] <-  TEMP5[31:16];
    DEST[111:96] <-  TEMP6[31:16];
    DEST[127:112] <- TEMP7[31:16];
```
#### VPMULHUW (VEX.128 encoded version)
```info-verb
TEMP0[31:0] <-  SRC1[15:0] * SRC2[15:0]
TEMP1[31:0] <-  SRC1[31:16] * SRC2[31:16]
TEMP2[31:0] <-  SRC1[47:32] * SRC2[47:32]
TEMP3[31:0] <-  SRC1[63:48] * SRC2[63:48]
TEMP4[31:0] <-  SRC1[79:64] * SRC2[79:64]
TEMP5[31:0] <-  SRC1[95:80] * SRC2[95:80]
TEMP6[31:0] <-  SRC1[111:96] * SRC2[111:96]
TEMP7[31:0] <-  SRC1[127:112] * SRC2[127:112]
DEST[15:0] <-  TEMP0[31:16]
DEST[31:16] <-  TEMP1[31:16]
DEST[47:32] <-  TEMP2[31:16]
DEST[63:48] <-  TEMP3[31:16]
DEST[79:64] <-  TEMP4[31:16]
DEST[95:80] <-  TEMP5[31:16]
DEST[111:96] <-  TEMP6[31:16]
DEST[127:112] <-  TEMP7[31:16]
DEST[VLMAX-1:128] <-  0
```
#### PMULHUW (VEX.256 encoded version)
```info-verb
TEMP0[31:0] <-  SRC1[15:0] * SRC2[15:0]
TEMP1[31:0] <-  SRC1[31:16] * SRC2[31:16]
TEMP2[31:0] <-  SRC1[47:32] * SRC2[47:32]
TEMP3[31:0] <-  SRC1[63:48] * SRC2[63:48]
TEMP4[31:0] <-  SRC1[79:64] * SRC2[79:64]
TEMP5[31:0] <-  SRC1[95:80] * SRC2[95:80]
TEMP6[31:0] <-  SRC1[111:96] * SRC2[111:96]
TEMP7[31:0] <-  SRC1[127:112] * SRC2[127:112]
TEMP8[31:0] <-  SRC1[143:128] * SRC2[143:128]
TEMP9[31:0] <-  SRC1[159:144] * SRC2[159:144]
TEMP10[31:0] <-  SRC1[175:160] * SRC2[175:160]
TEMP11[31:0] <-  SRC1[191:176] * SRC2[191:176]
TEMP12[31:0] <-  SRC1[207:192] * SRC2[207:192]
TEMP13[31:0] <-  SRC1[223:208] * SRC2[223:208]
TEMP14[31:0] <-  SRC1[239:224] * SRC2[239:224]
TEMP15[31:0] <-  SRC1[255:240] * SRC2[255:240]
DEST[15:0] <-  TEMP0[31:16]
DEST[31:16] <-  TEMP1[31:16]
DEST[47:32] <-  TEMP2[31:16]
DEST[63:48] <-  TEMP3[31:16]
DEST[79:64] <-  TEMP4[31:16]
DEST[95:80] <-  TEMP5[31:16]
DEST[111:96] <-  TEMP6[31:16]
DEST[127:112] <-  TEMP7[31:16]
DEST[143:128] <-  TEMP8[31:16]
DEST[159:144] <-  TEMP9[31:16]
DEST[175:160] <-  TEMP10[31:16]
DEST[191:176] <-  TEMP11[31:16]
DEST[207:192] <-  TEMP12[31:16]
DEST[223:208] <-  TEMP13[31:16]
DEST[239:224] <-  TEMP14[31:16]
DEST[255:240] <-  TEMP15[31:16]
DEST[MAX_VL-1:256] <-  0
```
#### PMULHUW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN 
                temp[31:0] <-  SRC1[i+15:i] * SRC2[i+15:i]
                DEST[i+15:i] <-  tmp[31:16]
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
VPMULHUW __m512i _mm512_mulhi_epu16(__m512i a, __m512i b);
VPMULHUW __m512i _mm512_mask_mulhi_epu16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPMULHUW __m512i _mm512_maskz_mulhi_epu16( __mmask32 k, __m512i a, __m512i b);
VPMULHUW __m256i _mm256_mask_mulhi_epu16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPMULHUW __m256i _mm256_maskz_mulhi_epu16( __mmask16 k, __m256i a, __m256i b);
VPMULHUW __m128i _mm_mask_mulhi_epu16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMULHUW __m128i _mm_maskz_mulhi_epu16( __mmask8 k, __m128i a, __m128i b);
PMULHUW:__m64 _mm_mulhi_pu16(__m64 a, __m64 b)
(V)PMULHUW:__m128i _mm_mulhi_epu16 ( __m128i a, __m128i b)
VPMULHUW:__m256i _mm256_mulhi_epu16 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4.nb.

