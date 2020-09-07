----------------------------
title : PSLLW, PSLLD, PSLLQs (Intel x86/64 assembly instruction)
cat_title : PSLLW, PSLLD, PSLLQ
ref_title : PSLLW, PSLLD, PSLLQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PSLLW, PSLLD, PSLLQ

**Shift Packed Data Left Logical**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F F1 /r\footnote{1}\newline{}\newline{}PSLLW mm, mm/m64|RM|V/V |MMX|Shift words in mm left mm/m64 while shifting in 0s.|
|66 0F F1 /r\newline{}\newline{}PSLLW xmm1, xmm2/m128|RM|V/V |SSE2|Shift words in xmm1 left by xmm2/m128 while shifting in 0s.|
|0F 71 /6 ib\newline{}\newline{}PSLLW mm1, imm8|MI|V/V|MMX|Shift words in mm left by imm8 while shifting in 0s.|
|66 0F 71 /6 ib\newline{}\newline{}PSLLW xmm1, imm8|MI|V/V|SSE2|Shift words in xmm1 left by imm8 while shifting in 0s.|
|0F F2 /r\footnote{1}\newline{}\newline{}PSLLD mm, mm/m64|RM|V/V |MMX|Shift doublewords in mm left by mm/m64 while shifting in 0s.|
|66 0F F2 /r\newline{}\newline{}PSLLD xmm1, xmm2/m128|RM|V/V|SSE2|Shift doublewords in xmm1 left by xmm2/m128 while shifting in 0s.|
|0F 72 /6 ib\footnote{1}\newline{}\newline{}PSLLD mm, imm8|MI|V/V|MMX|Shift doublewords in mm left by imm8 while shifting in 0s.|
|66 0F 72 /6 ib\newline{}\newline{}PSLLD xmm1, imm8|MI|V/V|SSE2|Shift doublewords in xmm1 left by imm8 while shifting in 0s.|
|0F F3 /r\footnote{1}\newline{}\newline{}PSLLQ mm, mm/m64|RM|V/V|MMX|Shift quadword in mm left by mm/m64 while shifting in 0s.|
|66 0F F3 /r\newline{}\newline{}PSLLQ xmm1, xmm2/m128|RM|V/V|SSE2|Shift quadwords in xmm1 left by xmm2/m128 while shifting in 0s.|
|0F 73 /6 ib\footnote{1}\newline{}\newline{}PSLLQ mm, imm8|MI|V/V|MMX|Shift quadword in mm left by imm8 while shifting in 0s.|
|66 0F 73 /6 ib\newline{}\newline{}PSLLQ xmm1, imm8|MI|V/V|SSE2|Shift quadwords in xmm1 left by imm8 while shifting in 0s.|
|VEX.NDS.128.66.0F.WIG F1 /r\newline{}\newline{}VPSLLW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Shift words in xmm2 left by amount specified in xmm3/m128 while shifting in 0s.|
|VEX.NDD.128.66.0F.WIG 71 /6 ib\newline{}\newline{}VPSLLW xmm1, xmm2, imm8|VMI|V/V|AVX|Shift words in xmm2 left by imm8 while shifting in 0s.|
|VEX.NDS.128.66.0F.WIG F2 /r\newline{}\newline{}VPSLLD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Shift doublewords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s.|
|VEX.NDD.128.66.0F.WIG 72 /6 ib\newline{}\newline{}VPSLLD xmm1, xmm2, imm8|VMI|V/V|AVX|Shift doublewords in xmm2 left by imm8 while shifting in 0s.|
|VEX.NDS.128.66.0F.WIG F3 /r\newline{}\newline{}VPSLLQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Shift quadwords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s.|
|VEX.NDD.128.66.0F.WIG 73 /6 ib\newline{}\newline{}VPSLLQ xmm1, xmm2, imm8|VMI|V/V|AVX|Shift quadwords in xmm2 left by imm8 while shifting in 0s.|
|VEX.NDS.256.66.0F.WIG F1 /r\newline{}\newline{}VPSLLW ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift words in ymm2 left by amount specified in xmm3/m128 while shifting in 0s.|
|VEX.NDD.256.66.0F.WIG 71 /6 ib\newline{}\newline{}VPSLLW ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift words in ymm2 left by imm8 while shifting in 0s.|


|VEX.NDS.256.66.0F.WIG F2 /r\newline{}VPSLLD ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift doublewords in ymm2 left by amount \newline{}specified in xmm3/m128 while shifting in 0s.|
|-----------------------------------------------------------------|---|---|----|-----------------------------------------------------------------------------------------------|
|VEX.NDD.256.66.0F.WIG 72 /6 ib\newline{}VPSLLD ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift doublewords in ymm2 left by imm8 while shifting in 0s.|
|VEX.NDS.256.66.0F.WIG F3 /r\newline{}VPSLLQ ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift quadwords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s.|
|VEX.NDD.256.66.0F.WIG 73 /6 ib\newline{}VPSLLQ ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift quadwords in ymm2 left by imm8 while shifting in 0s.|
|EVEX.NDS.128.66.0F.WIG F1 /rVPSLLW xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512BW|Shift words in xmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F.WIG F1 /rVPSLLW ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512BW|Shift words in ymm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F.WIG F1 /rVPSLLW zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512BW|Shift words in zmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDD.128.66.0F.WIG 71 /6 ibVPSLLW xmm1 {k1}{z}, xmm2/m128, imm8|FVMI|V/V|AVX512VL\newline{}AVX512BW|Shift words in xmm2/m128 left by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.256.66.0F.WIG 71 /6 ibVPSLLW ymm1 {k1}{z}, ymm2/m256, imm8|FVMI|V/V|AVX512VL\newline{}AVX512BW|Shift words in ymm2/m256 left by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.512.66.0F.WIG 71 /6 ibVPSLLW zmm1 {k1}{z}, zmm2/m512, imm8|FVMI|V/V|AVX512BW|Shift words in zmm2/m512 left by imm8 while shifting in 0 using writemask k1.|
|EVEX.NDS.128.66.0F.W0 F2 /rVPSLLD xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s under writemask k1.|
|EVEX.NDS.256.66.0F.W0 F2 /rVPSLLD ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s under writemask k1.|
|EVEX.NDS.512.66.0F.W0 F2 /rVPSLLD zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512F|Shift doublewords in zmm2 left by amount specified in xmm3/m128 while shifting in 0s under writemask k1.|
|EVEX.NDD.128.66.0F.W0 72 /6 ibVPSLLD xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FVI|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in xmm2/m128/m32bcst left by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.256.66.0F.W0 72 /6 ibVPSLLD ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FVI|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in ymm2/m256/m32bcst left by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.512.66.0F.W0 72 /6 ibVPSLLD zmm1 {k1}{z}, zmm2/m512/m32bcst, imm8|FVI|V/V|AVX512F|Shift doublewords in zmm2/m512/m32bcst left by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDS.128.66.0F.W1 F3 /rVPSLLQ xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F.W1 F3 /rVPSLLQ ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F.W1 F3 /rVPSLLQ zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512F|Shift quadwords in zmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|


|EVEX.NDD.128.66.0F.W1 73 /6 ib\newline{}VPSLLQ xmm1 {k1}{z}, xmm2/m128/m64bcst, \newline{}imm8|FVI|V/V|AVX512VL\newline{}\newline{}AVX512F|Shift quadwords in xmm2/m128/m64bcst left \newline{}by imm8 while shifting in 0s using writemask k1.|
|----------------------------------------------------------------------------------------------|---|---|-----------------------------------|----------------------------------------------------------------------------------------------------|
|EVEX.NDD.256.66.0F.W1 73 /6 ibVPSLLQ ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FVI|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in ymm2/m256/m64bcst left by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.512.66.0F.W1 73 /6 ibVPSLLQ zmm1 {k1}{z}, zmm2/m512/m64bcst, imm8|FVI|V/V|AVX512F|Shift quadwords in zmm2/m512/m64bcst left by imm8 while shifting in 0s using writemask k1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|MI|ModRM:r/m (r, w)|imm8|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|VMI|VEX.vvvv (w)|ModRM:r/m (r)|imm8|NA|
|FVMI|EVEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
|FVI|EVEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
|M128|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Shifts the bits in the individual data elements (words, doublewords, or quadword) in the destination operand (first operand) to the left by the number of bits specified in the count operand (second operand). As the bits in the data elements are shifted left, the empty low-order bits are cleared (set to 0). If the value specified by the count operand is greater than 15 (for words), 31 (for doublewords), or 63 (for a quadword), then the destination operand is set to all 0s. Figure 4-17 gives an example of shifting words in a 64-bit operand. 

The (V)PSLLW instruction shifts each of the words in the destination operand to the left by the number of bits spec-ified in the count operand; the (V)PSLLD instruction shifts each of the doublewords in the destination operand; and the (V)PSLLQ instruction shifts the quadword (or quadwords) in the destination operand.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE instructions 64-bit operand: The destination operand is an MMX technology register; the count operand can be either an MMX technology register or an 64-bit memory location.

```embed
<figure>
<svg viewBox="0 0 379.679993 109.320007">
<rect x="0.000000" y="10.000000" width="0.480000" height="87.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="87.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="97.120010" width="379.679993" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.240005" y="20.380005" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="81.240005" y="20.139984" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.879990" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.000000" y="38.139984" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.000000" y="20.140015" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.120010" y="20.380005" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="144.120010" y="20.139984" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.759995" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.879990" y="38.139984" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.879990" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.000015" y="20.380005" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.000015" y="20.139984" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.640015" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.759995" y="38.139984" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.759995" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M269.880005,20.380005 L332.820007,20.380005 L332.820007,38.380005 L269.880005,38.380005" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="269.880005" y="20.139984" width="63.180000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="332.580017" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.640015" y="38.139984" width="63.180000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.640015" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.639999" y="73.360016" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="80.639999" y="73.120010" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.279999" y="73.360001" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.399994" y="91.120010" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.399994" y="73.120010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.520004" y="73.360016" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="143.520004" y="73.120010" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.159988" y="73.360001" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.279999" y="91.120010" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.279999" y="73.120010" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.400009" y="73.360016" width="62.939999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="206.400009" y="73.120010" width="63.180000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.099976" y="73.360001" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.159988" y="91.120010" width="63.180000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.159988" y="73.120010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.340027" y="73.360016" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="269.340027" y="73.120010" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="331.979980" y="73.360001" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.099976" y="91.120010" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.099976" y="73.120010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="281.340027" y="65.980011" width="0.479980" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M281.400024,66.580017 L282.960022,65.980011 L283.919983,65.620010 L283.619995,66.640015 L282.059998,72.040024 L281.580017,73.720016 L281.100037,72.040024 L279.540039,66.640015 L279.239990,65.620010 L280.200012,65.980011 L280.500000,66.340012 L282.059998,71.740021 L281.100037,72.040024 L281.100037,71.740021 L282.660034,66.340012 L283.619995,66.640015 L283.320007,66.940018 L281.760010,67.540024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M280.200012,65.980011 L281.760010,66.580017 L281.760010,67.540009 L281.580017,67.600006 L281.400024,67.540009 L279.840027,66.940018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M281.580017,67.060013 L283.140015,66.460007 L281.580017,71.860016 L280.020020,66.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.080017" y="38.619995" width="0.480010" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="281.340027" y="53.080017" width="25.980000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="281.340027" y="53.320007" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.180008" y="65.920013" width="0.480010" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M99.240005,66.520004 L100.740005,65.980011 L101.700012,65.559998 L101.400009,66.639999 L99.900009,71.980011 L99.419998,73.600006 L98.940002,71.980011 L97.380005,66.639999 L97.080002,65.620010 L98.040009,65.980011 L98.340012,66.340012 L99.900009,71.680008 L98.940002,71.980011 L98.940002,71.680008 L100.440002,66.340012 L101.400009,66.639999 L101.100006,66.940002 L99.600006,67.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M98.039993,65.980011 L99.599991,66.520004 L99.599991,67.480011 L99.419998,67.540009 L99.239990,67.480011 L97.679993,66.940018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M99.419998,67.000015 L100.919998,66.460022 L99.419998,71.800018 L97.860001,66.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="124.860001" y="38.559998" width="0.480000" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.180008" y="53.020020" width="25.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.180008" y="53.260010" width="0.480010" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.900009" y="65.919998" width="0.479980" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.960007,66.460007 L164.460007,65.920013 L165.419998,65.500000 L163.620010,71.980011 L163.139999,73.660004 L162.660019,71.980011 L161.100021,66.580002 L160.800003,65.560013 L161.759995,65.920013 L162.060013,66.280014 L163.620010,71.680008 L162.660019,71.980011 L162.660019,71.680008 L164.160019,66.280014 L165.120010,66.580002 L164.819992,66.880005 L163.319992,67.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.759995,65.920013 L163.319992,66.460007 L163.319992,67.420013 L163.139999,67.480011 L162.960007,67.420013 L161.400009,66.880020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M163.139999,66.940002 L164.639999,66.400009 L163.139999,71.800003 L161.580002,66.400009" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="188.580002" y="38.500000" width="0.480010" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.900009" y="52.960022" width="25.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.900009" y="53.200012" width="0.479980" height="12.960000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="219.659988" y="66.400009" width="0.479980" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M219.719986,67.000015 L221.219986,66.400009 L222.179977,65.980011 L220.379990,72.460022 L219.899979,74.140015 L219.419998,72.460022 L217.860001,67.060013 L217.559982,66.040009 L218.519974,66.400009 L218.819992,66.760010 L220.379990,72.160019 L219.419998,72.460022 L219.419998,72.160019 L220.919998,66.760010 L221.879990,67.060013 L221.579971,67.360016 L220.079971,67.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M218.520004,66.400009 L220.080002,67.000015 L220.080002,67.960007 L219.900009,68.020004 L219.720016,67.960007 L218.160019,67.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M219.900009,67.480011 L221.400009,66.880005 L219.900009,72.280014 L218.340012,66.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.340012" y="39.040009" width="0.479980" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="219.659988" y="53.500000" width="25.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="219.659988" y="53.740021" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="74.463699" y="63.580093" textLength="3.695760" font-size="8px">n</text>
<text x="62.446564" y="63.580093" textLength="3.695760" font-size="8px">n</text>
<text x="56.163071" y="63.580093" textLength="2.610000" font-size="8px">t</text>
<text x="52.447128" y="63.580093" textLength="3.702720" font-size="8px">x</text>
<text x="48.779907" y="63.580093" textLength="3.654000" font-size="8px">E</text>
<text x="74.163712" y="55.780014" textLength="3.654000" font-size="8px">o</text>
<text x="71.762512" y="55.780014" textLength="2.526480" font-size="8px">r</text>
<text x="68.102249" y="55.780014" textLength="3.647040" font-size="8px">e</text>
<text x="64.263107" y="55.780014" textLength="4.008960" font-size="8px">Z</text>
<text x="62.583664" y="55.780014" textLength="1.719120" font-size="8px"> </text>
<text x="56.222229" y="55.780014" textLength="2.610000" font-size="8px">t</text>
<text x="54.720963" y="55.780014" textLength="1.510320" font-size="8px">i</text>
<text x="134.154236" y="86.320007" textLength="4.882501" font-size="8px">T</text>
<text x="122.621613" y="86.320007" textLength="5.769502" font-size="8px">U</text>
<text x="116.407806" y="86.320007" textLength="6.216998" font-size="8px">O</text>
<text x="108.419998" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="102.900070" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="90.773300" y="86.320007" textLength="4.442996" font-size="8px">3</text>
<text x="85.440109" y="86.320007" textLength="5.329997" font-size="8px">X</text>
<text x="197.934189" y="86.320007" textLength="4.882501" font-size="8px">T</text>
<text x="192.167892" y="86.320007" textLength="5.769502" font-size="8px">N</text>
<text x="186.401596" y="86.320007" textLength="5.769502" font-size="8px">U</text>
<text x="180.187790" y="86.320007" textLength="6.216998" font-size="8px">O</text>
<text x="166.680069" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="154.553482" y="86.320007" textLength="4.442996" font-size="8px">2</text>
<text x="149.220291" y="86.320007" textLength="5.329997" font-size="8px">X</text>
<text x="261.174194" y="86.320007" textLength="4.882501" font-size="8px">T</text>
<text x="222.239853" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="217.793655" y="86.320007" textLength="4.442996" font-size="8px">1</text>
<text x="212.460464" y="86.320007" textLength="5.329997" font-size="8px">X</text>
<text x="237.539444" y="32.560547" textLength="4.442996" font-size="8px">1</text>
<text x="232.199051" y="32.560547" textLength="5.329997" font-size="8px">X</text>
<text x="176.520157" y="32.560547" textLength="4.442996" font-size="8px">2</text>
<text x="171.179764" y="32.560547" textLength="5.329997" font-size="8px">X</text>
<text x="112.801498" y="32.560547" textLength="4.442996" font-size="8px">3</text>
<text x="107.461121" y="32.560547" textLength="5.329997" font-size="8px">X</text>
<text x="321.714172" y="86.320007" textLength="4.882501" font-size="8px">T</text>
<text x="310.181580" y="86.320007" textLength="5.769502" font-size="8px">U</text>
<text x="298.201477" y="86.320007" textLength="5.769502" font-size="8px">C</text>
<text x="290.520081" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="285.059998" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="278.393311" y="86.319458" textLength="4.442996" font-size="8px">0</text>
<text x="273.060120" y="86.319458" textLength="5.329997" font-size="8px">X</text>
<text x="65.779755" y="47.920013" textLength="3.452160" font-size="8px">L</text>
<text x="64.040451" y="47.920013" textLength="1.719120" font-size="8px"> </text>
<text x="57.318481" y="47.920013" textLength="1.510320" font-size="8px">i</text>
<text x="53.596970" y="47.920013" textLength="3.695760" font-size="8px">h</text>
<text x="74.104080" y="81.339401" textLength="2.221498" font-size="8px">t</text>
<text x="65.774246" y="81.339401" textLength="4.442996" font-size="8px">h</text>
<text x="60.438660" y="81.339401" textLength="5.329997" font-size="8px">S</text>
<text x="57.772064" y="81.339401" textLength="2.661003" font-size="8px">-</text>
<text x="51.543869" y="81.339401" textLength="3.995500" font-size="8px">s</text>
<text x="41.759689" y="81.339401" textLength="5.329997" font-size="8px">P</text>
<text x="75.298721" y="28.479736" textLength="2.221498" font-size="8px">t</text>
<text x="61.618927" y="28.479736" textLength="5.329997" font-size="8px">S</text>
<text x="58.978699" y="28.479736" textLength="2.661003" font-size="8px">-</text>
<text x="51.839539" y="28.479736" textLength="2.661003" font-size="8px">r</text>
<text x="46.559891" y="28.479736" textLength="5.329997" font-size="8px">P</text>
<text x="62.894287" y="36.760010" textLength="5.329997" font-size="8px">E</text>
<text x="72.483871" y="89.320007" textLength="4.882501" font-size="8px">T</text>
<text x="61.814285" y="89.320007" textLength="5.329997" font-size="8px">E</text>
<text x="56.039993" y="89.320007" textLength="5.769502" font-size="8px">D</text>
<text x="69.272934" y="63.580093" textLength="1.510320" font-size="8px">i</text>
<text x="294.479980" y="32.559998" textLength="5.329997" font-size="8px">X</text>
<text x="315.947876" y="86.320007" textLength="5.769502" font-size="8px">N</text>
<text x="237.661484" y="86.320007" textLength="5.769502" font-size="8px">C</text>
<text x="54.539703" y="28.479736" textLength="4.442996" font-size="8px">e</text>
<text x="174.421494" y="86.320007" textLength="5.769502" font-size="8px">C</text>
<text x="303.967773" y="86.320007" textLength="6.216998" font-size="8px">O</text>
<text x="49.919998" y="47.920013" textLength="3.695760" font-size="8px">S</text>
<text x="229.979843" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="158.999680" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="95.219498" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="57.119995" y="36.760010" textLength="5.769502" font-size="8px">D</text>
<text x="71.398315" y="28.479736" textLength="1.774002" font-size="8px">i</text>
<text x="161.219986" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="58.860062" y="55.780014" textLength="3.695760" font-size="8px">h</text>
<text x="55.544968" y="81.339401" textLength="2.221498" font-size="8px">t</text>
<text x="282.839539" y="86.319458" textLength="2.221498" font-size="8px"> </text>
<text x="97.440002" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="70.222839" y="81.339401" textLength="1.774002" font-size="8px">i</text>
<text x="224.460007" y="86.320007" textLength="5.468040" font-size="8px"><</text>
<text x="49.320007" y="55.780014" textLength="5.373120" font-size="8px">w</text>
<text x="66.155548" y="63.580093" textLength="3.104160" font-size="8px">s</text>
<text x="235.439987" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="243.427780" y="86.320007" textLength="6.216998" font-size="8px">O</text>
<text x="69.139343" y="47.920013" textLength="3.647040" font-size="8px">e</text>
<text x="72.002441" y="81.339401" textLength="2.221498" font-size="8px">f</text>
<text x="68.229080" y="36.760010" textLength="5.329997" font-size="8px">S</text>
<text x="73.197083" y="28.479736" textLength="2.221498" font-size="8px">f</text>
<text x="47.095276" y="81.339401" textLength="4.442996" font-size="8px">o</text>
<text x="61.449249" y="47.920013" textLength="2.610000" font-size="8px">t</text>
<text x="110.641495" y="86.320007" textLength="5.769502" font-size="8px">C</text>
<text x="172.199997" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="299.820374" y="32.559998" textLength="4.442996" font-size="8px">0</text>
<text x="128.387924" y="86.320007" textLength="5.769502" font-size="8px">N</text>
<text x="255.407883" y="86.320007" textLength="5.769502" font-size="8px">N</text>
<text x="249.641586" y="86.320007" textLength="5.769502" font-size="8px">U</text>
<text x="66.959320" y="28.479736" textLength="4.442996" font-size="8px">h</text>
<text x="75.243271" y="47.920013" textLength="2.610000" font-size="8px">t</text>
<text x="58.810013" y="47.920013" textLength="2.582160" font-size="8px">f</text>
<text x="70.796478" y="63.580093" textLength="3.654000" font-size="8px">o</text>
<text x="73.563873" y="36.760010" textLength="4.882501" font-size="8px">T</text>
<text x="295.979980" y="86.320007" textLength="2.221498" font-size="8px"> </text>
<text x="67.149078" y="89.320007" textLength="5.329997" font-size="8px">S</text>
<text x="72.679901" y="47.920013" textLength="2.582160" font-size="8px">f</text>
<text x="58.786301" y="63.580093" textLength="3.647040" font-size="8px">e</text>
</svg>
<figcaption>Figure 4-17.  PSLLW, PSLLD, and PSLLQ Instruction Operation Using 64-bit Operand
</figcaption></figure>
```


128-bit Legacy SSE version: The destination and first source operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged. The count operand can be either an XMM register or a 128-bit memory location or an 8-bit immediate. If the count operand is a memory address, 128 bits are loaded but the upper 64 bits are ignored.

VEX.128 encoded version: The destination and first source operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. The count operand can be either an XMM register or a 128-bit memory loca-tion or an 8-bit immediate. If the count operand is a memory address, 128 bits are loaded but the upper 64 bits are ignored.

VEX.256 encoded version: The destination operand is a YMM register. The source operand is a YMM register or a memory location. The count operand can come either from an XMM register or a memory location or an 8-bit imme-diate. Bits (MAX_VL-1:256) of the corresponding ZMM register are zeroed.

EVEX encoded versions: The destination operand is a ZMM register updated according to the writemask. The count operand is either an 8-bit immediate (the immediate count version) or an 8-bit value from an XMM register or a memory location (the variable count version). For the immediate count version, the source operand (the second operand) can be a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32/64-bit memory location. For the variable count version, the first source operand (the second operand) is a ZMM register, the second source operand (the third operand, 8-bit variable count) can be an XMM register or a memory location.

Note: In VEX/EVEX encoded versions of shifts with an immediate count, vvvv of VEX/EVEX encode the destination register, and VEX.B/EVEX.B + ModRM.r/m encodes the source register.

Note: For shifts with an immediate count (VEX.128.66.0F 71-73 /6, or EVEX.128.66.0F 71-73 /6), VEX.vvvv/EVEX.vvvv encodes the destination register. 


### Operation
#### PSLLW (with 64-bit operand)
```info-verb
    IF (COUNT > 15)
    THEN 
          DEST[64:0] <- 0000000000000000H;
    ELSE
          DEST[15:0] <- ZeroExtend(DEST[15:0] << COUNT);
          (* Repeat shift operation for 2nd and 3rd words *)
          DEST[63:48] <- ZeroExtend(DEST[63:48] << COUNT);
    FI;
```
#### PSLLD (with 64-bit operand)
```info-verb
    IF (COUNT > 31)
    THEN 
          DEST[64:0] <- 0000000000000000H;
    ELSE
          DEST[31:0] <- ZeroExtend(DEST[31:0] << COUNT);
          DEST[63:32] <- ZeroExtend(DEST[63:32] << COUNT);
    FI;
```
#### PSLLQ (with 64-bit operand)
```info-verb
    IF (COUNT > 63)
    THEN 
          DEST[64:0] <- 0000000000000000H;
    ELSE
          DEST <- ZeroExtend(DEST << COUNT);
    FI;
LOGICAL_LEFT_SHIFT_WORDS(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 15)
THEN
DEST[127:0] <- 00000000000000000000000000000000H
ELSE
    DEST[15:0] <- ZeroExtend(SRC[15:0] << COUNT);
    (* Repeat shift operation for 2nd through 7th words *)
    DEST[127:112] <- ZeroExtend(SRC[127:112] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_DWORDS1(SRC, COUNT_SRC)
COUNT <-  COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[31:0] <-  0
ELSE
    DEST[31:0] <-  ZeroExtend(SRC[31:0] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_DWORDS(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
ELSE
    DEST[31:0] <- ZeroExtend(SRC[31:0] << COUNT);
    (* Repeat shift operation for 2nd through 3rd words *)
    DEST[127:96] <- ZeroExtend(SRC[127:96] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_QWORDS1(SRC, COUNT_SRC)
COUNT <-  COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[63:0] <-  0
ELSE
    DEST[63:0] <-  ZeroExtend(SRC[63:0] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_QWORDS(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
ELSE
    DEST[63:0] <- ZeroExtend(SRC[63:0] << COUNT);
    DEST[127:64] <- ZeroExtend(SRC[127:64] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_WORDS_256b(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 15)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
    DEST[255:128] <- 00000000000000000000000000000000H
ELSE
    DEST[15:0] <- ZeroExtend(SRC[15:0] << COUNT);
    (* Repeat shift operation for 2nd through 15th words *)
DEST[255:240] <- ZeroExtend(SRC[255:240] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_DWORDS_256b(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
    DEST[255:128] <- 00000000000000000000000000000000H
ELSE
    DEST[31:0] <- ZeroExtend(SRC[31:0] << COUNT);
    (* Repeat shift operation for 2nd through 7th words *)
    DEST[255:224] <- ZeroExtend(SRC[255:224] << COUNT);
FI;
LOGICAL_LEFT_SHIFT_QWORDS_256b(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
    DEST[255:128] <- 00000000000000000000000000000000H
ELSE
    DEST[63:0] <- ZeroExtend(SRC[63:0] << COUNT);
    DEST[127:64] <- ZeroExtend(SRC[127:64] << COUNT)
    DEST[191:128] <- ZeroExtend(SRC[191:128] << COUNT);
    DEST[255:192] <- ZeroExtend(SRC[255:192] << COUNT);
FI;
```
#### VPSLLW (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_LEFT_SHIFT_WORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_LEFT_SHIFT_WORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_LEFT_SHIFT_WORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <-  LOGICAL_LEFT_SHIFT_WORDS_256b(SRC1[511:256], SRC2)
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSLLW (EVEX versions, imm8)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_LEFT_SHIFT_WORDS_128b(SRC1[127:0], imm8)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], imm8)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_LEFT_SHIFT_WORDS_256b(SRC1[255:0], imm8)
    TMP_DEST[511:256] <-  LOGICAL_LEFT_SHIFT_WORDS_256b(SRC1[511:256], imm8)
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSLLW (ymm, ymm, xmm/m128) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_LEFT_SHIFT_WORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSLLW (ymm, imm8) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_LEFT_SHIFT_WORD_256b(SRC1, imm8)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSLLW (xmm, xmm, xmm/m128) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_WORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPSLLW (xmm, imm8) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_WORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <- 0
```
#### PSLLW (xmm, xmm, xmm/m128) 
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_WORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSLLW (xmm, imm8)
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_WORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSLLD (EVEX versions, imm8)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+31:i] <-  LOGICAL_LEFT_SHIFT_DWORDS1(SRC1[31:0], imm8)
                      ELSE DEST[i+31:i] <-  LOGICAL_LEFT_SHIFT_DWORDS1(SRC1[i+31:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSLLD (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_LEFT_SHIFT_DWORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_LEFT_SHIFT_DWORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_LEFT_SHIFT_DWORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <-  LOGICAL_LEFT_SHIFT_DWORDS_256b(SRC1[511:256], SRC2)
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
DEST[MAX_VL-1:VL] <-  0
```
#### VPSLLD (ymm, ymm, xmm/m128) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_LEFT_SHIFT_DWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSLLD (ymm, imm8) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_LEFT_SHIFT_DWORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSLLD (xmm, xmm, xmm/m128) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_DWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPSLLD (xmm, imm8) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_DWORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <- 0
```
#### PSLLD (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_DWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSLLD (xmm, imm8)
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_DWORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSLLQ (EVEX versions, imm8)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+63:i] <-  LOGICAL_LEFT_SHIFT_QWORDS1(SRC1[63:0], imm8)
                      ELSE DEST[i+63:i] <-  LOGICAL_LEFT_SHIFT_QWORDS1(SRC1[i+63:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
```
#### VPSLLQ (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_LEFT_SHIFT_QWORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_LEFT_SHIFT_QWORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0] <- LOGICAL_LEFT_SHIFT_QWORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <- LOGICAL_LEFT_SHIFT_QWORDS_256b(SRC1[511:256], SRC2)
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
DEST[MAX_VL-1:VL] <- 0
```
#### VPSLLQ (ymm, ymm, xmm/m128) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_LEFT_SHIFT_QWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0;
VPSLLQ (ymm, imm8) - VEX.256 
```
#### encoding
```info-verb
DEST[255:0] <- LOGICAL_LEFT_SHIFT_QWORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSLLQ (xmm, xmm, xmm/m128) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_QWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPSLLQ (xmm, imm8) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_QWORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <- 0
```
#### PSLLQ (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_QWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSLLQ (xmm, imm8)
```info-verb
DEST[127:0] <- LOGICAL_LEFT_SHIFT_QWORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPSLLD __m512i _mm512_slli_epi32(__m512i a, unsigned int imm);
VPSLLD __m512i _mm512_mask_slli_epi32(__m512i s, __mmask16 k, __m512i a, unsigned int imm);
VPSLLD __m512i _mm512_maskz_slli_epi32( __mmask16 k, __m512i a, unsigned int imm);
VPSLLD __m256i _mm256_mask_slli_epi32(__m256i s, __mmask8 k, __m256i a, unsigned int imm);
VPSLLD __m256i _mm256_maskz_slli_epi32( __mmask8 k, __m256i a, unsigned int imm);
VPSLLD __m128i _mm_mask_slli_epi32(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSLLD __m128i _mm_maskz_slli_epi32( __mmask8 k, __m128i a, unsigned int imm);
VPSLLD __m512i _mm512_sll_epi32(__m512i a, __m128i cnt);
VPSLLD __m512i _mm512_mask_sll_epi32(__m512i s, __mmask16 k, __m512i a, __m128i cnt);
VPSLLD __m512i _mm512_maskz_sll_epi32( __mmask16 k, __m512i a, __m128i cnt);
VPSLLD __m256i _mm256_mask_sll_epi32(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSLLD __m256i _mm256_maskz_sll_epi32( __mmask8 k, __m256i a, __m128i cnt);
VPSLLD __m128i _mm_mask_sll_epi32(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSLLD __m128i _mm_maskz_sll_epi32( __mmask8 k, __m128i a, __m128i cnt);
VPSLLQ __m512i _mm512_mask_slli_epi64(__m512i a, unsigned int imm);
VPSLLQ __m512i _mm512_mask_slli_epi64(__m512i s, __mmask8 k, __m512i a, unsigned int imm);
VPSLLQ __m512i _mm512_maskz_slli_epi64( __mmask8 k, __m512i a, unsigned int imm);
VPSLLQ __m256i _mm256_mask_slli_epi64(__m256i s, __mmask8 k, __m256i a, unsigned int imm);
VPSLLQ __m256i _mm256_maskz_slli_epi64( __mmask8 k, __m256i a, unsigned int imm);
VPSLLQ __m128i _mm_mask_slli_epi64(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSLLQ __m128i _mm_maskz_slli_epi64( __mmask8 k, __m128i a, unsigned int imm);
VPSLLQ __m512i _mm512_mask_sll_epi64(__m512i a, __m128i cnt);
VPSLLQ __m512i _mm512_mask_sll_epi64(__m512i s, __mmask8 k, __m512i a, __m128i cnt);
VPSLLQ __m512i _mm512_maskz_sll_epi64( __mmask8 k, __m512i a, __m128i cnt);
VPSLLQ __m256i _mm256_mask_sll_epi64(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSLLQ __m256i _mm256_maskz_sll_epi64( __mmask8 k, __m256i a, __m128i cnt);
VPSLLQ __m128i _mm_mask_sll_epi64(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSLLQ __m128i _mm_maskz_sll_epi64( __mmask8 k, __m128i a, __m128i cnt);
VPSLLW __m512i _mm512_slli_epi16(__m512i a, unsigned int imm);
VPSLLW __m512i _mm512_mask_slli_epi16(__m512i s, __mmask32 k, __m512i a, unsigned int imm);
VPSLLW __m512i _mm512_maskz_slli_epi16( __mmask32 k, __m512i a, unsigned int imm);
VPSLLW __m256i _mm256_mask_sllii_epi16(__m256i s, __mmask16 k, __m256i a, unsigned int imm);
VPSLLW __m256i _mm256_maskz_slli_epi16( __mmask16 k, __m256i a, unsigned int imm);
VPSLLW __m128i _mm_mask_slli_epi16(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSLLW __m128i _mm_maskz_slli_epi16( __mmask8 k, __m128i a, unsigned int imm);
VPSLLW __m512i _mm512_sll_epi16(__m512i a, __m128i cnt);
VPSLLW __m512i _mm512_mask_sll_epi16(__m512i s, __mmask32 k, __m512i a, __m128i cnt);
VPSLLW __m512i _mm512_maskz_sll_epi16( __mmask32 k, __m512i a, __m128i cnt);
VPSLLW __m256i _mm256_mask_sll_epi16(__m256i s, __mmask16 k, __m256i a, __m128i cnt);
VPSLLW __m256i _mm256_maskz_sll_epi16( __mmask16 k, __m256i a, __m128i cnt);
VPSLLW __m128i _mm_mask_sll_epi16(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSLLW __m128i _mm_maskz_sll_epi16( __mmask8 k, __m128i a, __m128i cnt);
PSLLW:__m64 _mm_slli_pi16 (__m64 m, int count)
PSLLW:__m64 _mm_sll_pi16(__m64 m, __m64 count)
(V)PSLLW:__m128i _mm_slli_pi16(__m64 m, int count)
(V)PSLLW:__m128i _mm_slli_pi16(__m128i m, __m128i count)
VPSLLW:__m256i _mm256_slli_epi16 (__m256i m, int count)
VPSLLW:__m256i _mm256_sll_epi16 (__m256i m, __m128i count)
PSLLD:__m64 _mm_slli_pi32(__m64 m, int  count)
PSLLD:__m64 _mm_sll_pi32(__m64 m, __m64 count)
(V)PSLLD:__m128i _mm_slli_epi32(__m128i m, int  count)
(V)PSLLD:__m128i _mm_sll_epi32(__m128i m, __m128i count)
VPSLLD:__m256i _mm256_slli_epi32 (__m256i m, int count)
VPSLLD:__m256i _mm256_sll_epi32 (__m256i m, __m128i count)
PSLLQ:__m64 _mm_slli_si64(__m64 m, int  count)
PSLLQ:__m64 _mm_sll_si64(__m64 m, __m64 count)
(V)PSLLQ:__m128i _mm_slli_epi64(__m128i m, int  count)
(V)PSLLQ:__m128i _mm_sll_epi64(__m128i m, __m128i count)
VPSLLQ:__m256i _mm256_slli_epi64 (__m256i m, int count)
VPSLLQ:__m256i _mm256_sll_epi64 (__m256i m, __m128i count)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


VEX-encoded instructions:

     Syntax with RM/RVM operand encoding, see Exceptions Type 4.

     Syntax with MI/VMI operand encoding, see Exceptions Type 7.

EVEX-encoded VPSLLW, see Exceptions Type E4NF.nb.

EVEX-encoded VPSLLD/Q:

     Syntax with M128 operand encoding, see Exceptions Type E4NF.nb.

     Syntax with FVI operand encoding, see Exceptions Type E4.

