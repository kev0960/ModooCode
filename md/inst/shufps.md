----------------------------
title : SHUFPS (Intel x86/64 assembly instruction)
cat_title : SHUFPS
ref_title : SHUFPS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ SHUFPS

**Packed Interleave Shuffle of Quadruplets of Single-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F C6 /r ib\newline{}SHUFPS xmm1, xmm3/m128, imm8|RMI|V/V|SSE|Select from quadruplet of single-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1.|
|VEX.NDS.128.0F.WIG C6 /r ib\newline{}VSHUFPS xmm1, xmm2, xmm3/m128, imm8|RVMI|V/V|AVX|Select from quadruplet of single-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1.|
|VEX.NDS.256.0F.WIG C6 /r ib\newline{}VSHUFPS ymm1, ymm2, ymm3/m256, imm8|RVMI|V/V|AVX|Select from quadruplet of single-precision floating-point values in ymm2 and ymm3/m256 using imm8, interleaved result pairs are stored in ymm1.|
|EVEX.NDS.128.0F.W0 C6 /r ib\newline{}VSHUFPS xmm1{k1}{z}, xmm2, xmm3/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Select from quadruplet of single-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1, subject to writemask k1.|
|EVEX.NDS.256.0F.W0 C6 /r ib\newline{}VSHUFPS ymm1{k1}{z}, ymm2, ymm3/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Select from quadruplet of single-precision floating-point values in ymm2 and ymm3/m256 using imm8, interleaved result pairs are stored in ymm1, subject to writemask k1.|
|EVEX.NDS.512.0F.W0 C6 /r ib\newline{}VSHUFPS zmm1{k1}{z}, zmm2, zmm3/m512/m32bcst, imm8|FV|V/V|AVX512F|Select from quadruplet of single-precision floating-point values in zmm2 and zmm3/m512 using imm8, interleaved result pairs are stored in zmm1, subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|Imm8|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description


Selects a single-precision floating-point value of an input quadruplet using a two-bit control and move to a desig-nated element of the destination operand. Each 64-bit element-pair of a 128-bit lane of the destination operand is interleaved between the corresponding lane of the first source operand and the second source operand at the gran-ularity 128 bits. Each two bits in the imm8 byte, starting from bit 0, is the select control of the corresponding element of a 128-bit lane of the destination to received the shuffled result of an input quadruplet. The two lower elements of a 128-bit lane in the destination receives shuffle results from the quadruple of the first source operand. The next two elements of the destination receives shuffle results from the quadruple of the second source operand. 

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register updated according to the writemask. Imm8[7:0] provides 4 select controls for each applicable 128-bit lane of the destination.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. Imm8[7:0] provides 4 select controls for the high and low 128-bit of the destination.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed. Imm8[7:0] provides 4 select controls for each element of the destination.



128-bit Legacy SSE version: The source can be an XMM register or an 128-bit memory location. The destination is not distinct from the first source XMM register and the upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified. Imm8[7:0] provides 4 select controls for each element of the destination.

```embed
<figure>
<svg viewBox="0 0 481.200012 156.320007">
<rect x="0.000000" y="10.000000" width="0.480000" height="128.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="480.719971" y="10.000000" width="0.479980" height="128.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="481.200012" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="138.160034" width="481.200012" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.059998" y="103.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="90.059998" y="103.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="103.239990" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.819992" y="116.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.819992" y="103.000000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.279999" y="103.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="164.279999" y="103.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="103.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="116.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="103.000000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.559998" y="103.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.559998" y="103.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="103.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="116.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="103.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.839996" y="103.239990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="312.839996" y="103.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="103.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="116.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="103.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M273.720001,96.700012 L273.839996,96.880005 L273.959991,97.059998 C274.739990 97.658020,275.796997 97.106018,275.640015 96.100037  L275.579987,95.919983 L275.459991,95.739990 C274.990997 94.903015,273.634003 95.353027,273.660004 96.340027  L273.660004,96.520020 L273.720001,96.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.619995,96.339966 L276.359985,100.299988 L276.600006,100.899963 L275.940002,101.019958 L260.459991,103.059937 L258.779999,103.239990 L260.100006,102.159973 L272.100006,92.199951 L272.639984,91.779968 L272.880005,92.379944 L272.760010,92.979980 L260.760010,102.939941 L260.100006,102.159973 L260.399994,102.039978 L275.880005,99.999939 L275.940002,101.019958 L275.459991,100.719971 L273.720001,96.759949" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M272.880005,92.380005 L274.619995,96.340027 L273.720001,96.760010 L271.980011,92.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.199982,96.520020 L275.939972,100.480042 L260.459991,102.520020 L272.459991,92.559998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M313.260010,80.500000 L312.480011,78.700012 L274.320007,95.440002 L275.100006,97.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.919983" y="35.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="349.919983" y="35.499939" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="386.820007" y="35.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="49.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="35.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M355.260010,91.719971 L355.440002,91.539978 L355.500000,91.359985 C355.822021 90.394958,354.932007 89.737976,354.059998 90.159973  L353.880005,90.279968 L353.760010,90.459961 C353.145020 91.192993,354.122009 92.355957,354.960022 91.959961  L355.140015,91.839966 L355.260010,91.719971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M354.600006,91.000000 L357.600006,87.940002 L358.140015,87.520020 L358.440002,88.059998 L366.000000,101.739990 L366.839996,103.299988 L365.279999,102.460022 L351.660004,94.900024 L351.119995,94.539978 L351.540009,94.059998 L352.140015,94.000000 L365.760010,101.559998 L365.279999,102.460022 L365.100006,102.219971 L357.540009,88.539978 L358.440002,88.059998 L358.320007,88.659973 L355.320007,91.719971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M351.540009,94.059998 L354.600006,91.000000 L355.320007,91.719971 L352.260010,94.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M354.959991,91.359985 L357.959991,88.299988 L365.519989,101.979980 L351.899994,94.419983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M313.559998,48.580017 L312.179993,49.960022 L353.940002,91.720032 L355.320007,90.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M324.839996,87.700012 L325.019989,87.580017 L325.199982,87.520020 L325.320007,87.340027 L325.440002,87.220032 L325.500000,87.040039 L325.500000,86.440002 L325.380005,86.260010 L325.320007,86.080017 L325.139984,85.960022 L325.019989,85.840027 L324.839996,85.780029 L324.600006,85.720032 L324.419983,85.720032 L324.059998,85.840027 C323.148987 86.320984,323.493988 87.742004,324.419983 87.700012  L324.839996,87.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M324.540009,86.739990 L328.680023,85.419983 L329.279999,85.299988 L329.339996,85.899963 L329.700012,101.500000 L329.700012,103.299988 L328.740021,101.799988 L320.160004,88.779968 L319.800018,88.239990 L320.460022,88.000000 L321.000000,88.239990 L329.580017,101.260010 L328.740021,101.799988 L328.680023,101.500000 L328.320007,85.899963 L329.339996,85.899963 L328.980011,86.440002 L324.839996,87.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.459991,88.000000 L324.539978,86.739990 L324.839996,87.760010 L320.759979,89.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M324.660004,87.219971 L328.800018,85.899963 L329.160004,101.500000 L320.580017,88.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M313.799988,48.940002 L311.879974,49.539978 L323.579987,87.039978 L325.500000,86.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.179993,90.880005 L303.359985,91.000000 L303.539978,91.059998 C304.367004 91.364990,305.220978 90.286987,304.619995 89.500000  L304.500000,89.380005 L304.139984,89.140015 L303.539978,89.140015 L303.359985,89.200012 L303.239990,89.320007 L303.059998,89.440002 L302.940002,89.619995 L302.820007,89.979980 L302.820007,90.160034 L302.880005,90.400024 L302.940002,90.580017 L303.059998,90.700012 L303.179993,90.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.779999,90.159973 L307.079987,92.919983 L307.559998,93.399963 L307.019989,93.699951 L294.000000,102.279968 L292.559998,103.239990 L293.279999,101.679993 L299.760010,87.519958 L300.059998,86.919983 L300.540009,87.339966 L300.660004,87.940002 L294.179993,102.099976 L293.279999,101.679993 L293.459991,101.440002 L306.480011,92.859985 L307.019989,93.699951 L306.420013,93.699951 L303.119995,90.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M300.540009,87.339966 L303.779999,90.159973 L303.119995,90.939941 L299.880005,88.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.479980,90.520020 L306.779968,93.280029 L293.759979,101.860046 L300.239990,87.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M313.619995,80.260010 L312.119995,79.000000 L303.119995,89.500000 L304.619995,90.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.839996" y="35.739990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="312.839996" y="35.499939" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="35.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="49.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="35.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M275.699982,35.739990 L312.839966,35.739990 L312.839966,49.239990 L275.699982,49.239990" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="275.699982" y="35.499939" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="35.739990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="49.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="35.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.559998" y="35.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.559998" y="35.499939" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="35.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="49.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="35.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="35.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.419983" y="35.499939" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="35.739990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="49.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="35.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.279999" y="35.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="164.279999" y="35.499939" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="35.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="49.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="35.500000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="127.199997" y="35.739990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="127.199997" y="35.499939" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="35.739990" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="49.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="35.500000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.059998" y="35.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="90.059998" y="35.499939" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="35.739990" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.819992" y="49.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.819992" y="35.500000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.919983" y="66.099976" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="349.919983" y="65.859985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="386.820007" y="66.099976" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="79.359985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="65.859985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.839996" y="66.099976" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="312.839996" y="65.859985" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="66.099976" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="79.359985" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="65.859985" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M275.699982,66.099976 L312.839966,66.099976 L312.839966,79.599976 L275.699982,79.599976" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="275.699982" y="65.859985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="66.099976" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="79.359985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="65.859985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.559998" y="66.099976" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="238.559998" y="65.859985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="66.099976" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="79.359985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="65.859985" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="66.099976" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.419983" y="65.859985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="66.099976" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="79.359985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="65.859985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.279999" y="66.099976" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="164.279999" y="65.859985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="66.099976" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="79.359985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="65.859985" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="127.199997" y="66.099976" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="127.199997" y="65.859985" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="66.099976" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="79.359985" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="65.859985" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.059998" y="66.099976" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="90.059998" y="65.859985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="66.099976" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.819992" y="79.359985" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.819992" y="65.859985" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.919983" y="103.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="349.919983" y="103.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="386.820007" y="103.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="116.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="349.679993" y="103.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="127.199997" y="103.239990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="127.199997" y="103.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.039993" y="103.239990" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="116.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.959991" y="103.000000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="103.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.419983" y="103.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.320007" y="103.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="116.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="103.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M275.699982,103.239990 L312.839966,103.239990 L312.839966,116.739990 L275.699982,116.739990" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="275.699982" y="103.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="312.600006" y="103.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="116.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="275.459991" y="103.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.220001,96.700012 L125.339996,96.880005 L125.460007,97.059998 C126.240005 97.658020,127.296997 97.106018,127.139999 96.100037  L127.080002,95.919983 L126.960007,95.739990 C126.486008 94.893982,125.130997 95.363037,125.160004 96.340027  L125.160004,96.520020 L125.220001,96.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.119995,96.339966 L127.860001,100.299988 L128.099991,100.899963 L127.440002,101.019958 L111.959991,103.059937 L110.279999,103.239990 L111.599991,102.159973 L123.599991,92.199951 L124.139999,91.779968 L124.379990,92.379944 L124.259995,92.979980 L112.259995,102.939941 L111.599991,102.159973 L111.899994,102.039978 L127.379990,99.999939 L127.440002,101.019958 L126.959991,100.719971 L125.220001,96.759949" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M124.379990,92.380005 L126.119995,96.340027 L125.219986,96.760010 L123.479996,92.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.699997,96.520020 L127.440002,100.480042 L111.959991,102.520020 L123.959991,92.559998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M164.699997,80.500000 L163.919998,78.700012 L125.819992,95.440002 L126.600006,97.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.760010,91.719971 L206.940002,91.539978 L207.000000,91.359985 C207.318024 90.355957,206.424011 89.747986,205.500000 90.159973  L205.380005,90.279968 L205.260010,90.459961 C204.688019 91.120972,205.502014 92.370972,206.460022 91.959961  L206.640015,91.839966 L206.760010,91.719971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.040009,91.000000 L209.100006,87.940002 L209.580017,87.520020 L209.940002,88.059998 L217.500000,101.739990 L218.339996,103.299988 L216.779999,102.460022 L203.160004,94.900024 L202.619995,94.539978 L203.040009,94.059998 L203.640015,94.000000 L217.260010,101.559998 L216.779999,102.460022 L216.600006,102.219971 L209.040009,88.539978 L209.940002,88.059998 L209.820007,88.659973 L206.760010,91.719971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M203.040009,94.059998 L206.040009,91.000000 L206.760010,91.719971 L203.760010,94.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.399994,91.359985 L209.459991,88.299988 L217.019989,101.979980 L203.399994,94.419983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.000000,48.580017 L163.619995,49.960022 L205.440002,91.720032 L206.820007,90.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M176.339996,87.700012 L176.519989,87.580017 L176.639999,87.520020 C177.422989 86.868042,176.907990 85.703003,175.919998 85.720032  L175.559998,85.840027 C174.649002 86.320984,174.994003 87.742004,175.919998 87.700012  L176.339996,87.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M176.039993,86.739990 L180.179993,85.419983 L180.779999,85.299988 L180.839996,85.899963 L181.199997,101.500000 L181.199997,103.299988 L180.239990,101.799988 L171.659988,88.779968 L171.299988,88.239990 L171.959991,88.000000 L172.500000,88.239990 L181.079987,101.260010 L180.239990,101.799988 L180.179993,101.500000 L179.819992,85.899963 L180.839996,85.899963 L180.479996,86.440002 L176.339996,87.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.959991,88.000000 L176.039993,86.739990 L176.339996,87.760010 L172.259995,89.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M176.159988,87.219971 L180.299988,85.899963 L180.659988,101.500000 L172.079987,88.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.239990,48.940002 L163.379990,49.539978 L175.139984,87.039978 L176.999985,86.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.679993,90.880005 L154.859985,91.000000 L155.039993,91.059998 C155.866989 91.364990,156.720993 90.286987,156.119995 89.500000  L155.939987,89.380005 L155.819992,89.260010 C154.953995 88.737000,153.967987 89.664978,154.439987 90.580017  L154.500000,90.700012 L154.679993,90.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M155.279999,90.159973 L158.580002,92.919983 L159.059998,93.399963 L158.520004,93.699951 L145.500000,102.279968 L144.059998,103.239990 L144.779999,101.679993 L151.259995,87.519958 L151.559998,86.919983 L152.039993,87.339966 L152.160004,87.940002 L145.679993,102.099976 L144.779999,101.679993 L144.959991,101.440002 L157.979996,92.859985 L158.520004,93.699951 L157.919998,93.699951 L154.619995,90.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.039993,87.339966 L155.279999,90.159973 L154.619995,90.939941 L151.379990,88.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.979996,90.520020 L158.279999,93.280029 L145.259995,101.860046 L151.739990,87.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.059998,80.260010 L163.559998,79.000000 L154.619995,89.500000 L156.119995,90.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="301.439636" y="111.760010" textLength="4.610074" font-size="8px">0</text>
<text x="293.633179" y="111.760010" textLength="2.305037" font-size="8px">.</text>
<text x="289.069519" y="111.760010" textLength="2.305037" font-size="8px"> </text>
<text x="221.510986" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="217.367981" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="219.469482" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="208.199982" y="111.760010" textLength="5.002500" font-size="8px">X</text>
<text x="143.934006" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="375.845215" y="113.380005" textLength="4.170000" font-size="8px">0</text>
<text x="362.511719" y="113.380005" textLength="2.085000" font-size="8px"> </text>
<text x="358.313232" y="113.380005" textLength="4.170000" font-size="8px">3</text>
<text x="353.339996" y="113.380005" textLength="5.002500" font-size="8px">X</text>
<text x="106.139984" y="74.679993" textLength="4.170000" font-size="8px">7</text>
<text x="138.239990" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="175.379990" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="212.519989" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="328.860016" y="74.679993" textLength="4.170000" font-size="8px">1</text>
<text x="323.880005" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="366.000000" y="74.679993" textLength="4.170000" font-size="8px">0</text>
<text x="361.019989" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="101.159988" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="180.359985" y="44.260010" textLength="4.170000" font-size="8px">5</text>
<text x="254.700012" y="44.260010" textLength="4.170000" font-size="8px">3</text>
<text x="328.860016" y="44.260010" textLength="4.170000" font-size="8px">1</text>
<text x="323.880005" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="80.158493" y="76.299988" textLength="5.415000" font-size="8px">C</text>
<text x="74.763000" y="76.299988" textLength="5.415000" font-size="8px">R</text>
<text x="153.057007" y="111.760010" textLength="4.170000" font-size="8px">4</text>
<text x="366.000000" y="44.260010" textLength="4.170000" font-size="8px">0</text>
<text x="85.916977" y="45.880005" textLength="4.170000" font-size="8px">1</text>
<text x="80.518478" y="45.880005" textLength="5.415000" font-size="8px">C</text>
<text x="75.119980" y="45.880005" textLength="5.415000" font-size="8px">R</text>
<text x="80.158478" y="111.760010" textLength="5.002500" font-size="8px">S</text>
<text x="333.713989" y="113.380005" textLength="5.002500" font-size="8px">X</text>
<text x="331.612488" y="113.380005" textLength="2.085000" font-size="8px"> </text>
<text x="327.469482" y="113.380005" textLength="2.085000" font-size="8px">.</text>
<text x="325.367981" y="113.380005" textLength="2.085000" font-size="8px"> </text>
<text x="256.552032" y="111.760010" textLength="2.305037" font-size="8px">.</text>
<text x="254.271027" y="111.760010" textLength="2.305037" font-size="8px">.</text>
<text x="247.384918" y="111.760010" textLength="4.610074" font-size="8px">3</text>
<text x="241.919983" y="111.760010" textLength="5.530430" font-size="8px">Y</text>
<text x="186.475510" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="184.434006" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="180.224258" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="171.059998" y="111.760010" textLength="5.002500" font-size="8px">X</text>
<text x="115.923752" y="111.760010" textLength="4.170000" font-size="8px">4</text>
<text x="104.639999" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="98.399994" y="111.760010" textLength="4.170000" font-size="8px">7</text>
<text x="366.668976" y="113.380005" textLength="2.085000" font-size="8px">.</text>
<text x="110.897995" y="111.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="135.585754" y="111.760010" textLength="4.170000" font-size="8px">7</text>
<text x="217.559998" y="44.260010" textLength="4.170000" font-size="8px">4</text>
<text x="75.175476" y="111.760010" textLength="5.002500" font-size="8px">E</text>
<text x="338.694000" y="113.380005" textLength="4.170000" font-size="8px">0</text>
<text x="368.770477" y="113.380005" textLength="2.085000" font-size="8px"> </text>
<text x="188.577011" y="111.760010" textLength="5.002500" font-size="8px">X</text>
<text x="85.198471" y="111.760010" textLength="4.582500" font-size="8px">T</text>
<text x="69.779999" y="76.299988" textLength="5.002500" font-size="8px">S</text>
<text x="70.079987" y="45.880005" textLength="5.002500" font-size="8px">S</text>
<text x="141.825760" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="223.612488" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="212.519989" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="291.779999" y="44.260010" textLength="4.170000" font-size="8px">2</text>
<text x="230.694000" y="111.760010" textLength="4.170000" font-size="8px">4</text>
<text x="102.538498" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="254.700012" y="74.679993" textLength="4.170000" font-size="8px">3</text>
<text x="295.974701" y="111.760010" textLength="5.530430" font-size="8px">Y</text>
<text x="329.510986" y="113.380005" textLength="2.085000" font-size="8px">.</text>
<text x="264.298798" y="111.760010" textLength="4.610074" font-size="8px">0</text>
<text x="69.779984" y="111.760010" textLength="5.415000" font-size="8px">D</text>
<text x="145.975510" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="130.559998" y="111.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="213.229492" y="111.760010" textLength="4.170000" font-size="8px">7</text>
<text x="106.748245" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="143.219986" y="44.260010" textLength="4.170000" font-size="8px">6</text>
<text x="249.660004" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="286.799988" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="108.856491" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="279.059998" y="111.760010" textLength="5.530430" font-size="8px">Y</text>
<text x="175.379990" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="291.779999" y="74.679993" textLength="4.170000" font-size="8px">2</text>
<text x="286.799988" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="176.085754" y="111.760010" textLength="4.170000" font-size="8px">7</text>
<text x="370.871979" y="113.380005" textLength="5.002500" font-size="8px">X</text>
<text x="106.139984" y="44.260010" textLength="4.170000" font-size="8px">7</text>
<text x="138.239990" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="93.419998" y="111.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="225.713989" y="111.760010" textLength="5.002500" font-size="8px">X</text>
<text x="85.616989" y="76.299988" textLength="4.170000" font-size="8px">2</text>
<text x="291.351349" y="111.760010" textLength="2.305037" font-size="8px">.</text>
<text x="258.833862" y="111.760010" textLength="5.530430" font-size="8px">Y</text>
<text x="182.325760" y="111.760010" textLength="2.085000" font-size="8px">.</text>
<text x="180.359985" y="74.679993" textLength="4.170000" font-size="8px">5</text>
<text x="148.077011" y="111.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="364.613220" y="113.380005" textLength="2.085000" font-size="8px">.</text>
<text x="193.557007" y="111.760010" textLength="4.170000" font-size="8px">4</text>
<text x="321.229492" y="113.380005" textLength="4.170000" font-size="8px">3</text>
<text x="316.199982" y="113.380005" textLength="5.002500" font-size="8px">X</text>
<text x="249.660004" y="44.260010" textLength="5.002500" font-size="8px">X</text>
<text x="217.559998" y="74.679993" textLength="4.170000" font-size="8px">4</text>
<text x="139.724258" y="111.760010" textLength="2.085000" font-size="8px"> </text>
<text x="143.219986" y="74.679993" textLength="4.170000" font-size="8px">6</text>
<text x="251.929504" y="111.760010" textLength="2.305037" font-size="8px"> </text>
<text x="101.159988" y="74.679993" textLength="5.002500" font-size="8px">Y</text>
<text x="284.524933" y="111.760010" textLength="4.610074" font-size="8px">3</text>
<text x="361.019989" y="44.260010" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 4-26.  256-bit VSHUFPS Operation of Selection from Input Quadruplet and Pair-wise Interleaved Result
</figcaption></figure>
```

### Operation
#### VPSHUFPS (EVEX encoded versions when SRC2 is a vector register)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
TMP_DEST[31:0] <-  Select4(SRC1[127:0], imm8[1:0]);
TMP_DEST[63:32] <-  Select4(SRC1[127:0], imm8[3:2]);
TMP_DEST[95:64] <-  Select4(SRC2[127:0], imm8[5:4]);
TMP_DEST[127:96] <-  Select4(SRC2[127:0], imm8[7:6]);
IF VL >= 256
    TMP_DEST[159:128] <-  Select4(SRC1[255:128], imm8[1:0]);
    TMP_DEST[191:160] <-  Select4(SRC1[255:128], imm8[3:2]);
    TMP_DEST[223:192] <-  Select4(SRC2[255:128], imm8[5:4]);
    TMP_DEST[255:224] <-  Select4(SRC2[255:128], imm8[7:6]);
FI;
IF VL >= 512
    TMP_DEST[287:256] <-  Select4(SRC1[383:256], imm8[1:0]);
    TMP_DEST[319:288] <-  Select4(SRC1[383:256], imm8[3:2]);
    TMP_DEST[351:320] <-  Select4(SRC2[383:256], imm8[5:4]);
    TMP_DEST[383:352] <-  Select4(SRC2[383:256], imm8[7:6]);
    TMP_DEST[415:384] <-  Select4(SRC1[511:384], imm8[1:0]);
    TMP_DEST[447:416] <-  Select4(SRC1[511:384], imm8[3:2]);
    TMP_DEST[479:448] <- Select4(SRC2[511:384], imm8[5:4]);
    TMP_DEST[511:480] <-  Select4(SRC2[511:384], imm8[7:6]);
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
#### VPSHUFPS (EVEX encoded versions when SRC2 is memory)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF (EVEX.b = 1) 
          THEN TMP_SRC2[i+31:i] <-  SRC2[31:0]
          ELSE TMP_SRC2[i+31:i] <-  SRC2[i+31:i]
    FI;
ENDFOR;
TMP_DEST[31:0] <-  Select4(SRC1[127:0], imm8[1:0]);
TMP_DEST[63:32] <-  Select4(SRC1[127:0], imm8[3:2]);
TMP_DEST[95:64] <-  Select4(TMP_SRC2[127:0], imm8[5:4]);
TMP_DEST[127:96] <-  Select4(TMP_SRC2[127:0], imm8[7:6]);
IF VL >= 256
    TMP_DEST[159:128] <-  Select4(SRC1[255:128], imm8[1:0]);
    TMP_DEST[191:160] <-  Select4(SRC1[255:128], imm8[3:2]);
    TMP_DEST[223:192] <-  Select4(TMP_SRC2[255:128], imm8[5:4]);
    TMP_DEST[255:224] <-  Select4(TMP_SRC2[255:128], imm8[7:6]);
FI;
IF VL >= 512
    TMP_DEST[287:256] <-  Select4(SRC1[383:256], imm8[1:0]);
    TMP_DEST[319:288] <-  Select4(SRC1[383:256], imm8[3:2]);
    TMP_DEST[351:320] <-  Select4(TMP_SRC2[383:256], imm8[5:4]);
    TMP_DEST[383:352] <-  Select4(TMP_SRC2[383:256], imm8[7:6]);
    TMP_DEST[415:384] <-  Select4(SRC1[511:384], imm8[1:0]);
    TMP_DEST[447:416] <-  Select4(SRC1[511:384], imm8[3:2]);
    TMP_DEST[479:448] <- Select4(TMP_SRC2[511:384], imm8[5:4]);
    TMP_DEST[511:480] <-  Select4(TMP_SRC2[511:384], imm8[7:6]);
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
#### VSHUFPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], imm8[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], imm8[3:2]);
DEST[95:64] <- Select4(SRC2[127:0], imm8[5:4]);
DEST[127:96] <- Select4(SRC2[127:0], imm8[7:6]);
DEST[159:128] <- Select4(SRC1[255:128], imm8[1:0]);
DEST[191:160] <- Select4(SRC1[255:128], imm8[3:2]);
DEST[223:192] <- Select4(SRC2[255:128], imm8[5:4]);
DEST[255:224] <- Select4(SRC2[255:128], imm8[7:6]);
DEST[MAX_VL-1:256] <- 0
```
#### VSHUFPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], imm8[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], imm8[3:2]);
DEST[95:64] <- Select4(SRC2[127:0], imm8[5:4]);
DEST[127:96] <- Select4(SRC2[127:0], imm8[7:6]);
DEST[MAX_VL-1:128] <- 0
```
#### SHUFPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], imm8[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], imm8[3:2]);
DEST[95:64] <- Select4(SRC2[127:0], imm8[5:4]);
DEST[127:96] <- Select4(SRC2[127:0], imm8[7:6]);
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSHUFPS __m512 _mm512_shuffle_ps(__m512 a, __m512 b, int imm);
VSHUFPS __m512 _mm512_mask_shuffle_ps(__m512 s, __mmask16 k, __m512 a, __m512 b, int imm);
VSHUFPS __m512 _mm512_maskz_shuffle_ps(__mmask16 k, __m512 a, __m512 b, int imm);
VSHUFPS __m256 _mm256_shuffle_ps (__m256 a, __m256 b, const int select);
VSHUFPS __m256 _mm256_mask_shuffle_ps(__m256 s, __mmask8 k, __m256 a, __m256 b, int imm);
VSHUFPS __m256 _mm256_maskz_shuffle_ps(__mmask8 k, __m256 a, __m256 b, int imm);
SHUFPS __m128 _mm_shuffle_ps (__m128 a, __m128 b, const int select);
VSHUFPS __m128 _mm_mask_shuffle_ps(__m128 s, __mmask8 k, __m128 a, __m128 b, int imm);
VSHUFPS __m128 _mm_maskz_shuffle_ps(__mmask8 k, __m128 a, __m128 b, int imm);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.

