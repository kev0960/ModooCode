----------------------------
title : PSRAW, PSRAD, PSRAQs (Intel x86/64 assembly instruction)
cat_title : PSRAW, PSRAD, PSRAQ
ref_title : PSRAW, PSRAD, PSRAQ
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PSRAW, PSRAD, PSRAQ

**Shift Packed Data Right Arithmetic**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F E1 /r\footnote{1}\newline{}\newline{}PSRAW mm, mm/m64|RM|V/V|MMX|Shift words in mm right by mm/m64 while shifting in sign bits.|
|66 0F E1 /r\newline{}\newline{}PSRAW xmm1, xmm2/m128|RM|V/V|SSE2|Shift words in xmm1 right by xmm2/m128 while shifting in sign bits.|
|0F 71 /4 ib\footnote{1}\newline{}\newline{}PSRAW mm, imm8|MI|V/V|MMX|Shift words in mm right by imm8 while shifting in sign bits|
|66 0F 71 /4 ib\newline{}\newline{}PSRAW xmm1, imm8|MI|V/V|SSE2|Shift words in xmm1 right by imm8 while shifting in sign bits|
|0F E2 /r\footnote{1}\newline{}\newline{}PSRAD mm, mm/m64|RM|V/V|MMX|Shift doublewords in mm right by mm/m64 while shifting in sign bits.|
|66 0F E2 /r\newline{}\newline{}PSRAD xmm1, xmm2/m128|RM|V/V|SSE2|Shift doubleword in xmm1 right by xmm2 /m128 while shifting in sign bits.|
|0F 72 /4 ib\footnote{1}\newline{}\newline{}PSRAD mm, imm8|MI|V/V|MMX|Shift doublewords in mm right by imm8 while shifting in sign bits.|
|66 0F 72 /4 ib\newline{}\newline{}PSRAD xmm1, imm8|MI|V/V|SSE2|Shift doublewords in xmm1 right by imm8 while shifting in sign bits.|
|VEX.NDS.128.66.0F.WIG E1 /r\newline{}\newline{}VPSRAW xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits.|
|VEX.NDD.128.66.0F.WIG 71 /4 ib\newline{}\newline{}VPSRAW xmm1, xmm2, imm8|VMI|V/V|AVX|Shift words in xmm2 right by imm8 while shifting in sign bits.|
|VEX.NDS.128.66.0F.WIG E2 /r\newline{}\newline{}VPSRAD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits.|
|VEX.NDD.128.66.0F.WIG 72 /4 ib\newline{}\newline{}VPSRAD xmm1, xmm2, imm8|VMI|V/V|AVX|Shift doublewords in xmm2 right by imm8 while shifting in sign bits.|
|VEX.NDS.256.66.0F.WIG E1 /r\newline{}\newline{}VPSRAW ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits.|
|VEX.NDD.256.66.0F.WIG 71 /4 ib\newline{}\newline{}VPSRAW ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift words in ymm2 right by imm8 while shifting in sign bits.|
|VEX.NDS.256.66.0F.WIG E2 /r\newline{}\newline{}VPSRAD ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits.|
|VEX.NDD.256.66.0F.WIG 72 /4 ib\newline{}\newline{}VPSRAD ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift doublewords in ymm2 right by imm8 while shifting in sign bits.|
|EVEX.NDS.128.66.0F.WIG E1 /r\newline{}VPSRAW xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VLAVX512BW|Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDS.256.66.0F.WIG E1 /r\newline{}VPSRAW ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VLAVX512BW|Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDS.512.66.0F.WIG E1 /r\newline{}VPSRAW zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512BW|Shift words in zmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|


|EVEX.NDD.128.66.0F.WIG 71 /4 ib\newline{}VPSRAW xmm1 {k1}{z}, xmm2/m128, imm8|FVMI|V/V|AVX512VL\newline{}AVX512BW|Shift words in xmm2/m128 right by imm8 while \newline{}shifting in sign bits using writemask k1.|
|-----------------------------------------------------------------------------|----|---|--------------------------|------------------------------------------------------------------------------------------------|
|EVEX.NDD.256.66.0F.WIG 71 /4 ibVPSRAW ymm1 {k1}{z}, ymm2/m256, imm8|FVMI|V/V|AVX512VLAVX512BW|Shift words in ymm2/m256 right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDD.512.66.0F.WIG 71 /4 ibVPSRAW zmm1 {k1}{z}, zmm2/m512, imm8|FVMI|V/V|AVX512BW|Shift words in zmm2/m512 right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDS.128.66.0F.W0 E2 /rVPSRAD xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VLAVX512F|Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDS.256.66.0F.W0 E2 /rVPSRAD ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VLAVX512F|Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDS.512.66.0F.W0 E2 /rVPSRAD zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512F|Shift doublewords in zmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDD.128.66.0F.W0 72 /4 ibVPSRAD xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FVI|V/V|AVX512VLAVX512F|Shift doublewords in xmm2/m128/m32bcst right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDD.256.66.0F.W0 72 /4 ibVPSRAD ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FVI|V/V|AVX512VLAVX512F|Shift doublewords in ymm2/m256/m32bcst right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDD.512.66.0F.W0 72 /4 ibVPSRAD zmm1 {k1}{z}, zmm2/m512/m32bcst, imm8|FVI|V/V|AVX512F|Shift doublewords in zmm2/m512/m32bcst right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDS.128.66.0F.W1 E2 /rVPSRAQ xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VLAVX512F|Shift quadwords in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDS.256.66.0F.W1 E2 /rVPSRAQ ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VLAVX512F|Shift quadwords in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDS.512.66.0F.W1 E2 /rVPSRAQ zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512F|Shift quadwords in zmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.|
|EVEX.NDD.128.66.0F.W1 72 /4 ibVPSRAQ xmm1 {k1}{z}, xmm2/m128/m64bcst, imm8|FVI|V/V|AVX512VLAVX512F|Shift quadwords in xmm2/m128/m64bcst right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDD.256.66.0F.W1 72 /4 ibVPSRAQ ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FVI|V/V|AVX512VLAVX512F|Shift quadwords in ymm2/m256/m64bcst right by imm8 while shifting in sign bits using writemask k1.|
|EVEX.NDD.512.66.0F.W1 72 /4 ibVPSRAQ zmm1 {k1}{z}, zmm2/m512/m64bcst, imm8|FVI|V/V|AVX512F|Shift quadwords in zmm2/m512/m64bcst right by imm8 while shifting in sign bits using writemask k1.|

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
|M128|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Shifts the bits in the individual data elements (words, doublewords or quadwords) in the destination operand (first operand) to the right by the number of bits specified in the count operand (second operand). As the bits in the data elements are shifted right, the empty high-order bits are filled with the initial value of the sign bit of the data element. If the value specified by the count operand is greater than 15 (for words), 31 (for doublewords), or 63 (for quadwords), each destination data element is filled with the initial value of the sign bit of the element. (Figure 4-18 gives an example of shifting words in a 64-bit operand.)

Note that only the first 64-bits of a 128-bit count operand are checked to compute the count. If the second source operand is a memory address, 128 bits are loaded.

The (V)PSRAW instruction shifts each of the words in the destination operand to the right by the number of bits specified in the count operand, and the (V)PSRAD instruction shifts each of the doublewords in the destination operand.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE instructions 64-bit operand: The destination operand is an MMX technology register; the count operand can be either an MMX technology register or an 64-bit memory location. 

128-bit Legacy SSE version: The destination and first source operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged. The count operand can be either an XMM register or a 128-bit memory location or an 8-bit immediate. If the count operand is a memory address, 128 bits are loaded but the upper 64 bits are ignored.

VEX.128 encoded version: The destination and first source operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. The count operand can be either an XMM register or a 128-bit memory loca-tion or an 8-bit immediate. If the count operand is a memory address, 128 bits are loaded but the upper 64 bits are ignored.

VEX.256 encoded version: The destination operand is a YMM register. The source operand is a YMM register or a memory location. The count operand can come either from an XMM register or a memory location or an 8-bit immediate. Bits (MAX_VL-1:256) of the corresponding ZMM register are zeroed.

```embed
<figure>
<svg viewBox="0 0 379.679993 133.420013">
<rect x="0.000000" y="10.000000" width="0.480000" height="104.279999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="104.279999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="114.279999" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.559998" y="20.920013" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="82.559998" y="20.680023" width="63.119999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.199997" y="20.920013" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.320007" y="38.680023" width="63.119999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.320007" y="20.680023" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.439987" y="20.920013" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="145.439987" y="20.680023" width="63.119999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.080002" y="20.920013" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.199997" y="38.680023" width="63.119999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.199997" y="20.680023" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.319992" y="20.920013" width="62.939999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.319992" y="20.680023" width="63.180000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="20.920013" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.080002" y="38.680023" width="63.180000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.080002" y="20.680023" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.260010" y="20.920013" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="271.260010" y="20.680023" width="63.119999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="333.900024" y="20.920013" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="38.680023" width="63.119999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="20.680023" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.960007" y="73.900024" width="62.939999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="81.960007" y="73.660004" width="63.180000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.659988" y="73.900024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.720001" y="91.660004" width="63.180000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.720001" y="73.660034" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.900009" y="73.900024" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="144.900009" y="73.660004" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.539993" y="73.900024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.659988" y="91.660004" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.659988" y="73.660034" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.780014" y="73.900024" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.780014" y="73.660004" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.419983" y="73.900024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.539993" y="91.660004" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.539993" y="73.660034" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.659973" y="73.900024" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="270.659973" y="73.660004" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="333.299988" y="73.900024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.419983" y="91.660004" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.419983" y="73.660034" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="308.400024" y="66.520020" width="0.479980" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.460022,67.059998 L310.020020,66.519989 L310.979980,66.160004 L310.679993,67.179993 L309.119995,72.579987 L308.640015,74.260010 L308.160034,72.579987 L306.600037,67.179993 L306.299988,66.160004 L307.260010,66.519989 L307.559998,66.880005 L309.119995,72.279999 L308.160034,72.579987 L308.160034,72.279999 L309.720032,66.880005 L310.679993,67.179993 L310.380005,67.480011 L308.820007,68.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.260010,66.520020 L308.820007,67.060028 L308.820007,68.020020 L308.640015,68.080017 L308.460022,68.020020 L306.900024,67.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.640015,67.540009 L310.200012,67.000000 L308.640015,72.399994 L307.080017,67.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.659973" y="39.100006" width="0.479980" height="15.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.900024" y="53.620026" width="25.980000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="308.400024" y="53.860016" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.240005" y="66.460022" width="0.480010" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.300003,67.059998 L127.800003,66.459991 L128.760010,66.040009 L126.960007,72.519989 L126.479996,74.200012 L126.000000,72.519989 L124.440002,67.119995 L124.139999,66.100006 L125.100006,66.459991 L125.400009,66.820007 L126.960007,72.220001 L126.000000,72.519989 L126.000000,72.220001 L127.500000,66.820007 L128.460007,67.119995 L128.160004,67.419983 L126.660004,68.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.100006,66.460022 L126.660004,67.060028 L126.660004,68.020020 L126.480011,68.080017 L126.300003,68.020020 L124.740005,67.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.479996,67.540009 L127.979996,66.940002 L126.479996,72.339996 L124.919998,66.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="100.500000" y="39.100006" width="0.480000" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="100.740005" y="53.559998" width="25.980000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.240005" y="53.800018" width="0.480010" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.960007" y="66.400024" width="0.479980" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.020004,67.000000 L191.520004,66.459991 L192.479996,66.040009 L192.180008,67.119995 L190.680008,72.459991 L190.199997,74.079987 L189.720016,72.459991 L188.160019,67.119995 L187.860001,66.100006 L188.819992,66.459991 L189.120010,66.820007 L190.680008,72.160004 L189.720016,72.459991 L189.720016,72.160004 L191.220016,66.820007 L192.180008,67.119995 L191.879990,67.420013 L190.379990,67.959991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.819992,66.460022 L190.379990,67.000031 L190.379990,67.960022 L190.199997,68.020020 L190.020004,67.960022 L188.460007,67.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.199997,67.480011 L191.699997,66.940002 L190.199997,72.279999 L188.639999,66.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.219986" y="39.040009" width="0.479980" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.460007" y="53.500000" width="25.980000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.960007" y="53.740021" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659988" y="66.940033" width="0.479980" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.719986,67.480011 L248.279984,66.940002 L249.239975,66.580017 L248.939987,67.600006 L247.379990,73.000000 L246.899979,74.740021 L246.419998,73.000000 L244.919998,67.600006 L244.619980,66.580017 L245.579971,66.940002 L245.879990,67.300018 L247.379990,72.700012 L246.419998,73.000000 L246.419998,72.700012 L247.979996,67.300018 L248.939987,67.600006 L248.639999,67.900024 L247.079971,68.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M245.580002,66.940002 L247.080002,67.480011 L247.080002,68.440002 L246.900009,68.500000 L246.720016,68.440002 L245.220016,67.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.900009,67.960022 L248.460007,67.420013 L246.900009,72.820007 L245.400009,67.420013" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="220.979996" y="39.580017" width="0.480010" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.219986" y="54.040009" width="25.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659988" y="54.280029" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="74.706177" y="65.680084" textLength="3.695760" font-size="8px">n</text>
<text x="69.484085" y="65.680084" textLength="1.510320" font-size="8px">i</text>
<text x="66.362518" y="65.680084" textLength="3.104160" font-size="8px">s</text>
<text x="59.037125" y="65.680084" textLength="3.647040" font-size="8px">e</text>
<text x="74.712418" y="57.880005" textLength="3.695760" font-size="8px">n</text>
<text x="71.073029" y="57.880005" textLength="3.605280" font-size="8px">g</text>
<text x="69.571762" y="57.880005" textLength="1.510320" font-size="8px">i</text>
<text x="65.841904" y="57.880005" textLength="3.695760" font-size="8px">S</text>
<text x="64.162460" y="57.880005" textLength="1.719120" font-size="8px"> </text>
<text x="60.432602" y="57.880005" textLength="3.695760" font-size="8px">h</text>
<text x="56.287231" y="57.880005" textLength="1.510320" font-size="8px">i</text>
<text x="50.880005" y="57.880005" textLength="5.373120" font-size="8px">w</text>
<text x="129.779053" y="86.860016" textLength="5.769502" font-size="8px">N</text>
<text x="117.779755" y="86.860016" textLength="6.216998" font-size="8px">O</text>
<text x="109.740005" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="104.279831" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="98.759995" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="96.539505" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="92.093307" y="86.860016" textLength="4.442996" font-size="8px">3</text>
<text x="193.514267" y="86.860016" textLength="5.769502" font-size="8px">N</text>
<text x="187.696030" y="86.860016" textLength="5.769502" font-size="8px">U</text>
<text x="181.495010" y="86.860016" textLength="6.216998" font-size="8px">O</text>
<text x="173.520004" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="168.000076" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="160.318893" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="262.494202" y="86.860016" textLength="4.882501" font-size="8px">T</text>
<text x="256.727905" y="86.860016" textLength="5.769502" font-size="8px">N</text>
<text x="250.961594" y="86.860016" textLength="5.769502" font-size="8px">U</text>
<text x="244.747787" y="86.860016" textLength="6.216998" font-size="8px">O</text>
<text x="238.981491" y="86.860016" textLength="5.769502" font-size="8px">C</text>
<text x="231.240097" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="223.559921" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="238.859512" y="33.100555" textLength="4.442996" font-size="8px">1</text>
<text x="114.121567" y="33.100555" textLength="4.442996" font-size="8px">3</text>
<text x="317.339050" y="86.860016" textLength="5.769502" font-size="8px">N</text>
<text x="305.399719" y="86.860016" textLength="6.216998" font-size="8px">O</text>
<text x="297.359985" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="286.380005" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="274.380127" y="86.859467" textLength="5.329997" font-size="8px">X</text>
<text x="301.079651" y="33.100006" textLength="4.442996" font-size="8px">0</text>
<text x="295.799988" y="33.100006" textLength="5.329997" font-size="8px">X</text>
<text x="66.976486" y="50.619995" textLength="1.510320" font-size="8px">i</text>
<text x="62.716965" y="50.619995" textLength="4.196880" font-size="8px">R</text>
<text x="75.408890" y="81.879425" textLength="2.221498" font-size="8px">t</text>
<text x="73.247330" y="81.879425" textLength="2.221498" font-size="8px">f</text>
<text x="71.508484" y="81.879425" textLength="1.774002" font-size="8px">i</text>
<text x="67.057495" y="81.879425" textLength="4.442996" font-size="8px">h</text>
<text x="61.719513" y="81.879425" textLength="5.329997" font-size="8px">S</text>
<text x="59.050522" y="81.879425" textLength="2.661003" font-size="8px">-</text>
<text x="56.829025" y="81.879425" textLength="2.221498" font-size="8px">t</text>
<text x="52.868683" y="81.879425" textLength="3.995500" font-size="8px">s</text>
<text x="48.417694" y="81.879425" textLength="4.442996" font-size="8px">o</text>
<text x="43.079712" y="81.879425" textLength="5.329997" font-size="8px">P</text>
<text x="76.740189" y="29.019745" textLength="2.221498" font-size="8px">t</text>
<text x="177.840225" y="33.100555" textLength="4.442996" font-size="8px">2</text>
<text x="74.578629" y="29.019745" textLength="2.221498" font-size="8px">f</text>
<text x="68.397583" y="29.019745" textLength="4.442996" font-size="8px">h</text>
<text x="60.428162" y="29.019745" textLength="2.661003" font-size="8px">-</text>
<text x="47.939835" y="29.019745" textLength="5.329997" font-size="8px">P</text>
<text x="74.883881" y="37.300018" textLength="4.882501" font-size="8px">T</text>
<text x="69.549088" y="37.300018" textLength="5.329997" font-size="8px">S</text>
<text x="64.214294" y="37.300018" textLength="5.329997" font-size="8px">E</text>
<text x="68.498718" y="89.860016" textLength="5.329997" font-size="8px">S</text>
<text x="63.219070" y="89.860016" textLength="5.329997" font-size="8px">E</text>
<text x="57.419998" y="89.860016" textLength="5.769502" font-size="8px">D</text>
<text x="49.020294" y="65.680084" textLength="3.654000" font-size="8px">E</text>
<text x="279.713318" y="86.859467" textLength="4.442996" font-size="8px">0</text>
<text x="75.664658" y="50.619995" textLength="2.610000" font-size="8px">t</text>
<text x="323.157288" y="86.860016" textLength="4.882501" font-size="8px">T</text>
<text x="299.581482" y="86.860016" textLength="5.769502" font-size="8px">C</text>
<text x="73.858276" y="89.860016" textLength="4.882501" font-size="8px">T</text>
<text x="111.961502" y="86.860016" textLength="5.769502" font-size="8px">C</text>
<text x="108.781189" y="33.100555" textLength="5.329997" font-size="8px">X</text>
<text x="58.397598" y="50.619995" textLength="2.610000" font-size="8px">t</text>
<text x="311.580750" y="86.860016" textLength="5.769502" font-size="8px">U</text>
<text x="123.960800" y="86.860016" textLength="5.769502" font-size="8px">U</text>
<text x="150.540298" y="86.860016" textLength="5.329997" font-size="8px">X</text>
<text x="225.780014" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="199.272568" y="86.860016" textLength="4.882501" font-size="8px">T</text>
<text x="219.113724" y="86.860016" textLength="4.442996" font-size="8px">1</text>
<text x="284.159546" y="86.859467" textLength="2.221498" font-size="8px"> </text>
<text x="291.899841" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="50.535583" y="50.619995" textLength="3.695760" font-size="8px">h</text>
<text x="135.537369" y="86.860016" textLength="4.882501" font-size="8px">T</text>
<text x="55.929230" y="29.019745" textLength="4.442996" font-size="8px">e</text>
<text x="72.062851" y="50.619995" textLength="3.695760" font-size="8px">h</text>
<text x="68.477753" y="50.619995" textLength="3.605280" font-size="8px">g</text>
<text x="162.539993" y="86.860016" textLength="5.468040" font-size="8px">></text>
<text x="72.839783" y="29.019745" textLength="1.774002" font-size="8px">i</text>
<text x="52.690994" y="65.680084" textLength="3.702720" font-size="8px">x</text>
<text x="62.700867" y="65.680084" textLength="3.695760" font-size="8px">n</text>
<text x="155.819962" y="86.860016" textLength="4.442996" font-size="8px">2</text>
<text x="46.860001" y="50.619995" textLength="3.695760" font-size="8px">S</text>
<text x="54.257095" y="50.619995" textLength="1.510320" font-size="8px">i</text>
<text x="53.269028" y="29.019745" textLength="2.661003" font-size="8px">r</text>
<text x="172.499832" y="33.100555" textLength="5.329997" font-size="8px">X</text>
<text x="61.037521" y="50.619995" textLength="1.719120" font-size="8px"> </text>
<text x="63.068390" y="29.019745" textLength="5.329997" font-size="8px">S</text>
<text x="213.780533" y="86.860016" textLength="5.329997" font-size="8px">X</text>
<text x="236.759995" y="86.860016" textLength="2.221498" font-size="8px"> </text>
<text x="86.760117" y="86.860016" textLength="5.329997" font-size="8px">X</text>
<text x="58.440002" y="37.300018" textLength="5.769502" font-size="8px">D</text>
<text x="233.519119" y="33.100555" textLength="5.329997" font-size="8px">X</text>
<text x="71.045212" y="65.680084" textLength="3.654000" font-size="8px">o</text>
<text x="175.741501" y="86.860016" textLength="5.769502" font-size="8px">C</text>
<text x="57.788498" y="57.880005" textLength="2.610000" font-size="8px">t</text>
<text x="56.410416" y="65.680084" textLength="2.610000" font-size="8px">t</text>
<text x="55.818222" y="50.619995" textLength="2.582160" font-size="8px">f</text>
</svg>
<figcaption>Figure 4-18.  PSRAW and PSRAD Instruction Operation Using a 64-bit Operand
</figcaption></figure>
```


EVEX encoded versions: The destination operand is a ZMM register updated according to the writemask. The count operand is either an 8-bit immediate (the immediate count version) or an 8-bit value from an XMM register or a memory location (the variable count version). For the immediate count version, the source operand (the second operand) can be a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32/64-bit memory location. For the variable count version, the first source operand (the second operand) is a ZMM register, the second source operand (the third operand, 8-bit variable count) can be an XMM register or a memory location.

Note: In VEX/EVEX encoded versions of shifts with an immediate count, vvvv of VEX/EVEX encode the destination register, and VEX.B/EVEX.B + ModRM.r/m encodes the source register.

Note: For shifts with an immediate count (VEX.128.66.0F 71-73 /4, EVEX.128.66.0F 71-73 /4), VEX.vvvv/EVEX.vvvv encodes the destination register.


### Operation
#### PSRAW (with 64-bit operand)
```info-verb
    IF (COUNT > 15)
          THEN COUNT <- 16;
    FI;
    DEST[15:0] <- SignExtend(DEST[15:0] >> COUNT);
    (* Repeat shift operation for 2nd and 3rd words *)
    DEST[63:48] <- SignExtend(DEST[63:48] >> COUNT);
```
#### PSRAD (with 64-bit operand)
```info-verb
    IF (COUNT > 31)
          THEN COUNT <- 32;
    FI;
    DEST[31:0] <- SignExtend(DEST[31:0] >> COUNT);
    DEST[63:32] <- SignExtend(DEST[63:32] >> COUNT);
ARITHMETIC_RIGHT_SHIFT_DWORDS1(SRC, COUNT_SRC)
COUNT  <-  COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[31:0] <-   SignBit
ELSE
    DEST[31:0]  <-  SignExtend(SRC[31:0] >> COUNT);
FI;
ARITHMETIC_RIGHT_SHIFT_QWORDS1(SRC, COUNT_SRC)
COUNT <-   COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[63:0] <-   SignBit
ELSE
    DEST[63:0]  <-  SignExtend(SRC[63:0] >> COUNT);
FI;
ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC, COUNT_SRC)
COUNT  <-  COUNT_SRC[63:0];
IF (COUNT > 15)
    THEN COUNT  <-  16;
FI;
DEST[15:0]  <-  SignExtend(SRC[15:0] >> COUNT);
    (* Repeat shift operation for 2nd through 15th words *)
DEST[255:240] <-   SignExtend(SRC[255:240] >> COUNT);
ARITHMETIC_RIGHT_SHIFT_DWORDS_256b(SRC, COUNT_SRC)
COUNT <-   COUNT_SRC[63:0];
IF (COUNT > 31)
    THEN COUNT  <-  32;
FI;
DEST[31:0] <-   SignExtend(SRC[31:0] >> COUNT);
    (* Repeat shift operation for 2nd through 7th words *)
DEST[255:224]  <-  SignExtend(SRC[255:224] >> COUNT);
ARITHMETIC_RIGHT_SHIFT_QWORDS(SRC, COUNT_SRC, VL)  ; VL: 128b, 256b or 512b
COUNT  <-  COUNT_SRC[63:0];
IF (COUNT > 63)
    THEN COUNT  <-  64;
FI;
DEST[63:0] <-   SignExtend(SRC[63:0] >> COUNT);
    (* Repeat shift operation for 2nd through 7th words *)
DEST[VL-1:VL-64]  <-  SignExtend(SRC[VL-1:VL-64] >> COUNT);
ARITHMETIC_RIGHT_SHIFT_WORDS(SRC, COUNT_SRC)
COUNT  <-  COUNT_SRC[63:0];
IF (COUNT > 15)
    THEN COUNT <-   16;
FI;
DEST[15:0]  <-  SignExtend(SRC[15:0] >> COUNT);
    (* Repeat shift operation for 2nd through 7th words *)
DEST[127:112] <-   SignExtend(SRC[127:112] >> COUNT);
ARITHMETIC_RIGHT_SHIFT_DWORDS(SRC, COUNT_SRC)
COUNT  <-  COUNT_SRC[63:0];
IF (COUNT > 31)
    THEN COUNT  <-  32;
FI;
DEST[31:0] <-   SignExtend(SRC[31:0] >> COUNT);
    (* Repeat shift operation for 2nd through 3rd words *)
DEST[127:96]  <-  SignExtend(SRC[127:96] >> COUNT);
```
#### VPSRAW (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[127:0] <-   ARITHMETIC_RIGHT_SHIFT_WORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0]  <-  ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0]  <-  ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256]  <-  ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1[511:256], SRC2)
FI;
FOR j <-   0 TO KL-1
    i  <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i]  <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPSRAW (EVEX versions, imm8)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[127:0] <-   ARITHMETIC_RIGHT_SHIFT_WORDS_128b(SRC1[127:0], imm8)
FI;
IF VL = 256
    TMP_DEST[255:0] <-   ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], imm8)
FI;
IF VL = 512
    TMP_DEST[255:0] <-   ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], imm8)
    TMP_DEST[511:256]  <-  ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1[511:256], imm8)
FI;
FOR j  <-  0 TO KL-1
    i  <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i]  <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPSRAW (ymm, ymm, xmm/m128) - VEX
```info-verb
DEST[255:0] <-   ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <-   0
```
#### VPSRAW (ymm, imm8) - VEX
```info-verb
DEST[255:0]  <-  ARITHMETIC_RIGHT_SHIFT_WORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256]  <-  0
```
#### VPSRAW (xmm, xmm, xmm/m128) - VEX
```info-verb
DEST[127:0]  <-  ARITHMETIC_RIGHT_SHIFT_WORDS(SRC1, SRC2)
DEST[MAX_VL-1:128]  <-  0
```
#### VPSRAW (xmm, imm8) - VEX
```info-verb
DEST[127:0] <-   ARITHMETIC_RIGHT_SHIFT_WORDS(SRC1, imm8)
DEST[MAX_VL-1:128]  <-  0
```
#### PSRAW (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0]  <- ARITHMETIC_RIGHT_SHIFT_WORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSRAW (xmm, imm8)
```info-verb
DEST[127:0]  <- ARITHMETIC_RIGHT_SHIFT_WORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSRAD (EVEX versions, imm8)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i  <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+31:i]  <-  ARITHMETIC_RIGHT_SHIFT_DWORDS1(SRC1[31:0], imm8)
                      ELSE DEST[i+31:i] <-   ARITHMETIC_RIGHT_SHIFT_DWORDS1(SRC1[i+31:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPSRAD (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF VL = 128
    TMP_DEST[127:0] <-   ARITHMETIC_RIGHT_SHIFT_DWORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0]  <-  ARITHMETIC_RIGHT_SHIFT_DWORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0]  <-  ARITHMETIC_RIGHT_SHIFT_DWORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <-   ARITHMETIC_RIGHT_SHIFT_DWORDS_256b(SRC1[511:256], SRC2)
FI;
FOR j  <-  0 TO KL-1
    i  <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-   TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPSRAD (ymm, ymm, xmm/m128) - VEX
```info-verb
DEST[255:0] <-  ARITHMETIC_RIGHT_SHIFT_DWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256]  <-  0
```
#### VPSRAD (ymm, imm8) - VEX
```info-verb
DEST[255:0]  <- ARITHMETIC_RIGHT_SHIFT_DWORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256]  <-  0
```
#### VPSRAD (xmm, xmm, xmm/m128) - VEX
```info-verb
DEST[127:0] <-  ARITHMETIC_RIGHT_SHIFT_DWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <-  0
```
#### VPSRAD (xmm, imm8) - VEX
```info-verb
DEST[127:0]  <- ARITHMETIC_RIGHT_SHIFT_DWORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <-  0
```
#### PSRAD (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0] <-  ARITHMETIC_RIGHT_SHIFT_DWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSRAD (xmm, imm8)
```info-verb
DEST[127:0]  <- ARITHMETIC_RIGHT_SHIFT_DWORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSRAQ (EVEX versions, imm8)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j  <-  0 TO KL-1
    i <-   j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+63:i] <-   ARITHMETIC_RIGHT_SHIFT_QWORDS1(SRC1[63:0], imm8)
                      ELSE DEST[i+63:i] <-   ARITHMETIC_RIGHT_SHIFT_QWORDS1(SRC1[i+63:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+63:i]  <-  0
FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPSRAQ (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
TMP_DEST[VL-1:0] <-   ARITHMETIC_RIGHT_SHIFT_QWORDS(SRC1[VL-1:0], SRC2, VL)
FOR j  <-  0 TO 7
    i <-   j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i]  <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPSRAD __m512i _mm512_srai_epi32(__m512i a, unsigned int imm);
VPSRAD __m512i _mm512_mask_srai_epi32(__m512i s, __mmask16 k, __m512i a, unsigned int imm);
VPSRAD __m512i _mm512_maskz_srai_epi32( __mmask16 k, __m512i a, unsigned int imm);
VPSRAD __m256i _mm256_mask_srai_epi32(__m256i s, __mmask8 k, __m256i a, unsigned int imm);
VPSRAD __m256i _mm256_maskz_srai_epi32( __mmask8 k, __m256i a, unsigned int imm);
VPSRAD __m128i _mm_mask_srai_epi32(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSRAD __m128i _mm_maskz_srai_epi32( __mmask8 k, __m128i a, unsigned int imm);
VPSRAD __m512i _mm512_sra_epi32(__m512i a, __m128i cnt);
VPSRAD __m512i _mm512_mask_sra_epi32(__m512i s, __mmask16 k, __m512i a, __m128i cnt);
VPSRAD __m512i _mm512_maskz_sra_epi32( __mmask16 k, __m512i a, __m128i cnt);
VPSRAD __m256i _mm256_mask_sra_epi32(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSRAD __m256i _mm256_maskz_sra_epi32( __mmask8 k, __m256i a, __m128i cnt);
VPSRAD __m128i _mm_mask_sra_epi32(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRAD __m128i _mm_maskz_sra_epi32( __mmask8 k, __m128i a, __m128i cnt);
VPSRAQ __m512i _mm512_srai_epi64(__m512i a, unsigned int imm);
VPSRAQ __m512i _mm512_mask_srai_epi64(__m512i s, __mmask8 k, __m512i a, unsigned int imm)
VPSRAQ __m512i _mm512_maskz_srai_epi64( __mmask8 k, __m512i a, unsigned int imm)
VPSRAQ __m256i _mm256_mask_srai_epi64(__m256i s, __mmask8 k, __m256i a, unsigned int imm);
VPSRAQ __m256i _mm256_maskz_srai_epi64( __mmask8 k, __m256i a, unsigned int imm);
VPSRAQ __m128i _mm_mask_srai_epi64(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSRAQ __m128i _mm_maskz_srai_epi64( __mmask8 k, __m128i a, unsigned int imm);
VPSRAQ __m512i _mm512_sra_epi64(__m512i a, __m128i cnt);
VPSRAQ __m512i _mm512_mask_sra_epi64(__m512i s, __mmask8 k, __m512i a, __m128i cnt)
VPSRAQ __m512i _mm512_maskz_sra_epi64( __mmask8 k, __m512i a, __m128i cnt)
VPSRAQ __m256i _mm256_mask_sra_epi64(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSRAQ __m256i _mm256_maskz_sra_epi64( __mmask8 k, __m256i a, __m128i cnt);
VPSRAQ __m128i _mm_mask_sra_epi64(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRAQ __m128i _mm_maskz_sra_epi64( __mmask8 k, __m128i a, __m128i cnt);
VPSRAW __m512i _mm512_srai_epi16(__m512i a, unsigned int imm);
VPSRAW __m512i _mm512_mask_srai_epi16(__m512i s, __mmask32 k, __m512i a, unsigned int imm);
VPSRAW __m512i _mm512_maskz_srai_epi16( __mmask32 k, __m512i a, unsigned int imm);
VPSRAW __m256i _mm256_mask_srai_epi16(__m256i s, __mmask16 k, __m256i a, unsigned int imm);
VPSRAW __m256i _mm256_maskz_srai_epi16( __mmask16 k, __m256i a, unsigned int imm);
VPSRAW __m128i _mm_mask_srai_epi16(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSRAW __m128i _mm_maskz_srai_epi16( __mmask8 k, __m128i a, unsigned int imm);
VPSRAW __m512i _mm512_sra_epi16(__m512i a, __m128i cnt);
VPSRAW __m512i _mm512_mask_sra_epi16(__m512i s, __mmask16 k, __m512i a, __m128i cnt);
VPSRAW __m512i _mm512_maskz_sra_epi16( __mmask16 k, __m512i a, __m128i cnt);
VPSRAW __m256i _mm256_mask_sra_epi16(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSRAW __m256i _mm256_maskz_sra_epi16( __mmask8 k, __m256i a, __m128i cnt);
VPSRAW __m128i _mm_mask_sra_epi16(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRAW __m128i _mm_maskz_sra_epi16( __mmask8 k, __m128i a, __m128i cnt);
PSRAW:__m64 _mm_srai_pi16 (__m64 m, int count)
PSRAW:__m64 _mm_sra_pi16 (__m64 m, __m64 count)
(V)PSRAW:__m128i _mm_srai_epi16(__m128i m, int  count)
(V)PSRAW:__m128i _mm_sra_epi16(__m128i m, __m128i count)
VPSRAW:__m256i _mm256_srai_epi16 (__m256i m, int count)
VPSRAW:__m256i _mm256_sra_epi16 (__m256i m, __m128i count)
PSRAD:__m64 _mm_srai_pi32 (__m64 m, int count)
PSRAD:__m64 _mm_sra_pi32 (__m64 m, __m64 count)
(V)PSRAD:__m128i _mm_srai_epi32 (__m128i m, int  count)
(V)PSRAD:__m128i _mm_sra_epi32 (__m128i m, __m128i count)
VPSRAD:__m256i _mm256_srai_epi32 (__m256i m, int count)
VPSRAD:__m256i _mm256_sra_epi32 (__m256i m, __m128i count)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


VEX-encoded instructions:

     Syntax with RM/RVM operand encoding, see Exceptions Type 4.

     Syntax with MI/VMI operand encoding, see Exceptions Type 7.

EVEX-encoded VPSRAW, see Exceptions Type E4NF.nb.

EVEX-encoded VPSRAD/Q:

     Syntax with M128 operand encoding, see Exceptions Type E4NF.nb.

     Syntax with FVI operand encoding, see Exceptions Type E4.

