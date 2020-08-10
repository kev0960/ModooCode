### SHUFPD--Packed Interleave Shuffle of Pairs of Double-Precision Floating-Point Values


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F C6 /r ibSHUFPD xmm1, xmm2/m128, imm8|RMI|V/V|SSE2|Shuffle two pairs of double-precision floating-point values from xmm1 and xmm2/m128 using imm8 to select from each pair, interleaved result is stored in xmm1.|
|VEX.NDS.128.66.0F.WIG C6 /r ibVSHUFPD xmm1, xmm2, xmm3/m128, imm8|RVMI|V/V|AVX|Shuffle two pairs of double-precision floating-point values from xmm2 and xmm3/m128 using imm8 to select from each pair, interleaved result is stored in xmm1.|
|VEX.NDS.256.66.0F.WIG C6 /r ibVSHUFPD ymm1, ymm2, ymm3/m256, imm8|RVMI|V/V|AVX|Shuffle four pairs of double-precision floating-point values from ymm2 and ymm3/m256 using imm8 to select from each pair, interleaved result is stored in xmm1.|
|EVEX.NDS.128.66.0F.W1 C6 /r ibVSHUFPD xmm1{k1}{z}, xmm2, xmm3/m128/m64bcst, imm8|FV|V/V|AVX512VLAVX512F|Shuffle two paris of double-precision floating-point values from xmm2 and xmm3/m128/m64bcst using imm8 to select from each pair. store interleaved results in xmm1 subject to writemask k1.|
|EVEX.NDS.256.66.0F.W1 C6 /r ibVSHUFPD ymm1{k1}{z}, ymm2, ymm3/m256/m64bcst, imm8|FV|V/V|AVX512VLAVX512F|Shuffle four paris of double-precision floating-point values from ymm2 and ymm3/m256/m64bcst using imm8 to select from each pair. store interleaved results in ymm1 subject to writemask k1.|
|EVEX.NDS.512.66.0F.W1 C6 /r ibVSHUFPD zmm1{k1}{z}, zmm2, zmm3/m512/m64bcst, imm8|FV|V/V|AVX512F|Shuffle eight paris of double-precision floating-point values from zmm2 and zmm3/m512/m64bcst using imm8 to select from each pair. store interleaved results in zmm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|Imm8|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description


Selects a double-precision floating-point value of an input pair using a bit control and move to a designated element of the destination operand. The low-to-high order of double-precision element of the destination operand is interleaved between the first source operand and the second source operand at the granularity of input pair of 128 bits. Each bit in the imm8 byte, starting from bit 0, is the select control of the corresponding element of the destination to received the shuffled result of an input pair. 

EVEX encoded versions: The first source operand is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location The destination operand is a ZMM/YMM/XMM register updated according to the writemask. The select controls are the lower 8/4/2 bits of the imm8 byte.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. The select controls are the bit 3:0 of the imm8 byte, imm8[7:4) are ignored.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed. The select controls are the bit 1:0 of the imm8 byte, imm8[7:2) are ignored.



128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation operand and the first source operand is the same and is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified. The select controls are the bit 1:0 of the imm8 byte, imm8[7:2) are ignored.

```embed
<figure>
<svg viewBox="0 0 472.500031 141.979980">
<rect x="0.000000" y="10.000000" width="0.480010" height="114.779999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="472.019989" y="10.000000" width="0.480040" height="114.779999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519958" width="472.500000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="124.839966" width="472.500000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.100006" y="95.619995" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="89.100006" y="95.380005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="95.619995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.860001" y="108.880005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.860001" y="95.380005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.380005" y="95.619995" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="163.380005" y="95.380005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="95.619995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="108.880005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="95.380005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.600006" y="95.619995" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.600006" y="95.380005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="95.619995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="108.880005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="95.380005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.880005" y="95.619995" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="311.880005" y="95.380005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="385.859985" y="95.619995" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="108.880005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="95.380005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.100006" y="28.119995" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="89.100006" y="27.880005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="28.119995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.860001" y="41.380005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.860001" y="27.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.380005" y="28.119995" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="163.380005" y="27.880005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="28.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="41.380005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="27.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M278.100006,79.299988 L278.339996,79.299988 L278.520020,79.239990 C279.424011 78.804016,279.278992 77.546997,278.339996 77.320007  L277.920013,77.320007 C276.973999 77.533997,276.811005 78.804993,277.740021 79.239990  L277.920013,79.299988 L278.100006,79.299988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M278.100006,78.340027 L283.080017,78.340027 L282.899994,79.000000 L278.580017,93.940002 L278.100006,95.620056 L277.619995,93.940002 L273.360016,79.000000 L273.179993,78.340027 L273.839996,78.340027 L274.320007,78.700012 L278.580017,93.640015 L277.619995,93.940002 L277.619995,93.640015 L281.940002,78.700012 L282.899994,79.000000 L282.420013,79.360046 L278.100006,79.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.839996" y="78.339966" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M278.100006,78.820007 L282.420013,78.820007 L278.100006,93.760010 L273.839996,78.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.139984" y="71.980042" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.600006" y="28.119995" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.600006" y="27.880005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="28.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="41.380005" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="27.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.880005" y="28.119995" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="311.880005" y="27.880005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="385.859985" y="28.119995" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="41.380005" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="27.880005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M352.380005,79.299988 L352.559998,79.299988 L352.739990,79.239990 L353.100006,79.000000 L353.220001,78.880005 L353.279999,78.700012 L353.339996,78.519958 L353.399994,78.279968 L353.339996,78.099976 C353.274017 77.789978,353.076996 77.446960,352.739990 77.380005  L352.559998,77.320007 L352.200012,77.320007 L351.959991,77.380005 L351.839996,77.440002 L351.540009,77.739990 L351.420013,78.099976 L351.360016,78.279968 C351.484009 78.661011,351.436005 78.925964,351.839996 79.119995  L351.959991,79.239990 L352.200012,79.299988 L352.380005,79.299988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M352.380005,78.340027 L357.300018,78.340027 L357.119995,79.000000 L352.860016,93.940002 L352.380005,95.620056 L351.899994,93.940002 L347.580017,79.000000 L347.399994,78.340027 L348.059998,78.340027 L348.540009,78.700012 L352.860016,93.640015 L351.899994,93.940002 L351.899994,93.640015 L356.160004,78.700012 L357.119995,79.000000 L356.640015,79.360046 L352.380005,79.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="348.059998" y="78.339966" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M352.380005,78.820007 L356.640015,78.820007 L352.380005,93.760010 L348.059998,78.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="351.420013" y="41.620056" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.600006" y="67.660034" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="278.100006" y="67.660034" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.100006" y="58.479980" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="89.100006" y="58.240051" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="58.480042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.860001" y="71.740051" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.860001" y="58.239990" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.380005" y="58.479980" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="163.380005" y="58.240051" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="58.480042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="71.740051" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.139999" y="58.239990" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.600006" y="58.479980" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.600006" y="58.240051" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="58.480042" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="71.740051" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.359985" y="58.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.880005" y="58.479980" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="311.880005" y="58.240051" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="385.859985" y="58.480042" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="71.740051" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="311.639984" y="58.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M339.000000,86.320007 L339.059998,86.140015 L339.119995,85.900024 C339.455994 85.030029,338.069000 84.288025,337.500000 85.000000  L337.320007,85.119995 L337.260010,85.299988 L337.200012,85.539978 L337.140015,85.720032 L337.200012,85.900024 L337.260010,86.080017 L337.320007,86.260010 L337.619995,86.559998 L338.160004,86.739990 L338.339996,86.679993 L338.519989,86.679993 L338.880005,86.440002 L339.000000,86.320007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M338.160004,85.720032 L340.619995,82.180054 L341.040009,81.640015 L341.459991,82.180054 L351.300018,94.240051 L352.380005,95.620056 L350.760010,95.020020 L336.000000,90.040039 L335.339996,89.800049 L335.700012,89.260010 L336.300018,89.080017 L351.059998,94.060059 L350.760010,95.020020 L350.519989,94.840027 L340.679993,82.780029 L341.459991,82.180054 L341.459991,82.780029 L339.000000,86.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M335.700012,89.260010 L338.160004,85.720032 L339.000000,86.320007 L336.540009,89.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M338.579987,86.020020 L341.039978,82.480042 L350.879974,94.540039 L336.119995,89.559998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M275.339996,40.840027 L274.199982,42.460022 L337.619995,86.560059 L338.759979,84.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M293.579987,90.460022 L293.639984,90.640015 L293.759979,90.820007 L293.939972,90.940002 L294.059998,91.000000 L294.239990,91.119995 L294.659973,91.119995 L295.019989,91.000000 C295.404999 90.769043,295.434998 90.615051,295.559998 90.220032  L295.500000,90.040039 L295.500000,89.800049 L295.379974,89.619995 C294.897980 88.791016,293.669983 89.088013,293.519989 90.040039  L293.519989,90.220032 L293.579987,90.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M294.540009,90.100037 L295.920013,94.180054 L296.040009,94.840027 L295.440002,94.900024 L279.839996,95.560059 L278.100006,95.620056 L279.540009,94.600037 L292.380005,85.780029 L292.920013,85.420044 L293.160004,86.020020 L292.920013,86.620056 L280.080017,95.440063 L279.540009,94.600037 L279.779999,94.540039 L295.380005,93.880066 L295.440002,94.900024 L294.899994,94.540039 L293.520020,90.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M293.160004,86.020020 L294.540009,90.100037 L293.519989,90.460022 L292.140015,86.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M294.059998,90.280029 L295.440002,94.360046 L279.839996,95.020020 L292.679993,86.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M349.320007,72.940002 L348.720001,71.080017 L294.240021,89.200012 L294.839996,91.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.240005,79.299988 L126.419998,79.299988 L126.600006,79.239990 L126.960007,79.000000 L127.080002,78.880005 L127.139999,78.700012 L127.200012,78.519958 L127.260010,78.279968 L127.200012,78.099976 C127.134003 77.789978,126.937012 77.446960,126.600006 77.380005  L126.419998,77.320007 L126.060013,77.320007 L125.820007,77.380005 L125.700012,77.440002 L125.400009,77.739990 L125.340012,77.919983 L125.279999,78.099976 L125.220001,78.279968 C125.344009 78.661011,125.296005 78.925964,125.700012 79.119995  L125.820007,79.239990 L126.060013,79.299988 L126.240005,79.299988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.240005,78.340027 L131.220001,78.340027 L131.040009,79.000000 L126.720001,93.940002 L126.240005,95.620056 L125.760010,93.940002 L121.440002,79.000000 L121.260010,78.340027 L121.919998,78.340027 L122.400009,78.700012 L126.720001,93.640015 L125.760010,93.940002 L125.760010,93.640015 L130.080002,78.700012 L131.040009,79.000000 L130.560013,79.360046 L126.240005,79.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="121.919998" y="78.339966" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.240005,78.820007 L130.560013,78.820007 L126.240005,93.760010 L121.919998,78.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="125.279999" y="71.980042" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.080002,86.320007 L187.199997,86.140015 L187.259995,85.900024 C187.414001 84.911011,186.283997 84.361023,185.580002 85.000000  L185.460007,85.119995 L185.339996,85.299988 C184.983002 86.231018,186.024002 87.093994,186.839996 86.559998  L187.080002,86.320007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.300003,85.720032 L188.760010,82.180054 L189.180008,81.640015 L189.600006,82.180054 L199.440002,94.240051 L200.519989,95.620056 L198.899994,95.020020 L184.139999,90.040039 L183.479996,89.800049 L183.839996,89.260010 L184.440002,89.080017 L199.200012,94.060059 L198.899994,95.020020 L198.660004,94.840027 L188.820007,82.780029 L189.600006,82.180054 L189.600006,82.780029 L187.139999,86.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.839996,89.260010 L186.300003,85.720032 L187.139999,86.320007 L184.679993,89.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.720001,86.020020 L189.180008,82.480042 L199.019989,94.540039 L184.259995,89.559998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M123.479996,40.840027 L122.339996,42.460022 L185.759995,86.560059 L186.899994,84.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M141.720001,90.460022 L141.779999,90.640015 L141.899994,90.820007 C142.565002 91.476013,143.746002 91.025024,143.639999 90.040039  L143.580002,89.800049 L143.520004,89.619995 C143.048996 88.772034,141.695999 89.112000,141.660004 90.040039  L141.660004,90.220032 L141.720001,90.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M142.679993,90.100037 L144.000000,94.180054 L144.119995,94.840027 L143.519989,94.900024 L127.979996,95.560059 L126.239990,95.620056 L127.679993,94.600037 L140.519989,85.780029 L141.059998,85.420044 L141.299988,86.020020 L141.059998,86.620056 L128.219986,95.440063 L127.679993,94.600037 L127.919998,94.540039 L143.459991,93.880066 L143.519989,94.900024 L142.979996,94.540039 L141.659988,90.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M141.300003,86.020020 L142.680008,90.100037 L141.660004,90.460022 L140.279999,86.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M142.199997,90.280029 L143.520004,94.360046 L127.979996,95.020020 L140.819992,86.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M197.399994,72.940002 L196.799988,71.080017 L142.379990,89.200012 L142.979996,91.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M200.519989,79.299988 L200.699982,79.299988 L200.879974,79.239990 C201.783997 78.804016,201.638977 77.546997,200.699982 77.320007  L200.279999,77.320007 C199.341003 77.546997,199.195984 78.804016,200.099976 79.239990  L200.279999,79.299988 L200.519989,79.299988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M200.519989,78.340027 L205.440002,78.340027 L205.259979,79.000000 L201.000000,93.940002 L200.519989,95.620056 L200.039978,93.940002 L195.720001,79.000000 L195.539978,78.340027 L196.199982,78.340027 L196.679993,78.700012 L201.000000,93.640015 L200.039978,93.940002 L200.039978,93.640015 L204.299988,78.700012 L205.259979,79.000000 L204.779999,79.360046 L200.519989,79.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.200012" y="78.339966" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M200.519989,78.820007 L204.779999,78.820007 L200.519989,93.760010 L196.199982,78.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.559998" y="41.620056" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="73.920029" y="68.619995" textLength="5.415000" font-size="8px">R</text>
<text x="68.880035" y="68.619995" textLength="5.002500" font-size="8px">S</text>
<text x="352.680023" y="67.000000" textLength="4.170000" font-size="8px">0</text>
<text x="347.700012" y="67.000000" textLength="5.002500" font-size="8px">Y</text>
<text x="273.480011" y="67.000000" textLength="5.002500" font-size="8px">Y</text>
<text x="204.180023" y="67.000000" textLength="4.170000" font-size="8px">2</text>
<text x="124.979996" y="67.000000" textLength="5.002500" font-size="8px">Y</text>
<text x="352.680023" y="36.580017" textLength="4.170000" font-size="8px">0</text>
<text x="74.104507" y="38.260010" textLength="5.415000" font-size="8px">R</text>
<text x="204.180023" y="36.580017" textLength="4.170000" font-size="8px">2</text>
<text x="199.200012" y="36.580017" textLength="5.002500" font-size="8px">X</text>
<text x="129.959991" y="36.580017" textLength="4.170000" font-size="8px">3</text>
<text x="124.979996" y="36.580017" textLength="5.002500" font-size="8px">X</text>
<text x="79.315491" y="104.140015" textLength="5.002500" font-size="8px">S</text>
<text x="74.275497" y="104.140015" textLength="5.002500" font-size="8px">E</text>
<text x="353.452484" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="350.932495" y="104.140015" textLength="2.497500" font-size="8px">r</text>
<text x="344.690979" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="286.199982" y="104.140015" textLength="4.170000" font-size="8px">1</text>
<text x="281.224487" y="104.140015" textLength="5.002500" font-size="8px">Y</text>
<text x="279.122986" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="270.358490" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="211.973999" y="104.140015" textLength="4.170000" font-size="8px">3</text>
<text x="204.892487" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="202.372498" y="104.140015" textLength="2.497500" font-size="8px">r</text>
<text x="191.932495" y="104.140015" textLength="4.170000" font-size="8px">2</text>
<text x="137.700012" y="104.140015" textLength="4.170000" font-size="8px">3</text>
<text x="130.623016" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="128.103012" y="104.140015" textLength="2.497500" font-size="8px">r</text>
<text x="123.960007" y="104.140015" textLength="4.170000" font-size="8px">o</text>
<text x="117.715500" y="104.140015" textLength="4.170000" font-size="8px">2</text>
<text x="112.740005" y="104.140015" textLength="5.002500" font-size="8px">Y</text>
<text x="84.717026" y="68.619995" textLength="4.170000" font-size="8px">2</text>
<text x="346.792480" y="104.140015" textLength="4.170000" font-size="8px">o</text>
<text x="266.215485" y="104.140015" textLength="4.170000" font-size="8px">0</text>
<text x="355.493988" y="104.140015" textLength="5.002500" font-size="8px">X</text>
<text x="68.880005" y="104.140015" textLength="5.415000" font-size="8px">D</text>
<text x="84.898514" y="38.260010" textLength="4.170000" font-size="8px">1</text>
<text x="199.200012" y="67.000000" textLength="5.002500" font-size="8px">Y</text>
<text x="273.480011" y="36.580017" textLength="5.002500" font-size="8px">X</text>
<text x="261.239990" y="104.140015" textLength="5.002500" font-size="8px">Y</text>
<text x="84.298492" y="104.140015" textLength="4.582500" font-size="8px">T</text>
<text x="129.959991" y="67.000000" textLength="4.170000" font-size="8px">3</text>
<text x="186.959991" y="104.140015" textLength="5.002500" font-size="8px">X</text>
<text x="335.519989" y="104.140015" textLength="5.002500" font-size="8px">X</text>
<text x="276.602997" y="104.140015" textLength="2.497500" font-size="8px">r</text>
<text x="278.520020" y="67.000000" textLength="4.170000" font-size="8px">1</text>
<text x="132.724518" y="104.140015" textLength="5.002500" font-size="8px">Y</text>
<text x="79.501511" y="38.260010" textLength="5.415000" font-size="8px">C</text>
<text x="340.492493" y="104.140015" textLength="4.170000" font-size="8px">0</text>
<text x="79.318527" y="68.619995" textLength="5.415000" font-size="8px">C</text>
<text x="121.858505" y="104.140015" textLength="2.085000" font-size="8px"> </text>
<text x="198.232483" y="104.140015" textLength="4.170000" font-size="8px">o</text>
<text x="360.533997" y="104.140015" textLength="4.170000" font-size="8px">1</text>
<text x="206.933990" y="104.140015" textLength="5.002500" font-size="8px">X</text>
<text x="69.120010" y="38.260010" textLength="5.002500" font-size="8px">S</text>
<text x="347.700012" y="36.580017" textLength="5.002500" font-size="8px">X</text>
<text x="272.459991" y="104.140015" textLength="4.170000" font-size="8px">o</text>
<text x="278.520020" y="36.580017" textLength="4.170000" font-size="8px">1</text>
<text x="196.130981" y="104.140015" textLength="2.085000" font-size="8px"> </text>
</svg>
<figcaption>Figure 4-25.  256-bit VSHUFPD Operation of Four Pairs of DP FP Values
</figcaption></figure>
```

### Operation
#### VSHUFPD (EVEX encoded versions when SRC2 is a vector register)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF IMM0[0] = 0
 THEN TMP_DEST[63:0] <-  SRC1[63:0]
 ELSE TMP_DEST[63:0]  <- SRC1[127:64] FI;
IF IMM0[1] = 0
 THEN TMP_DEST[127:64] <-  SRC2[63:0]
 ELSE TMP_DEST[127:64] <-  SRC2[127:64] FI;
IF VL >= 256
 IF IMM0[2] = 0
   THEN TMP_DEST[191:128] <-  SRC1[191:128]
   ELSE TMP_DEST[191:128]  <- SRC1[255:192] FI;
 IF IMM0[3] = 0
   THEN TMP_DEST[255:192] <-  SRC2[191:128]
   ELSE TMP_DEST[255:192] <-  SRC2[255:192] FI;
FI;
IF VL >= 512
 IF IMM0[4] = 0
   THEN TMP_DEST[319:256] <-  SRC1[319:256]
   ELSE TMP_DEST[319:256]  <- SRC1[383:320] FI;
 IF IMM0[5] = 0
   THEN TMP_DEST[383:320] <-  SRC2[319:256]
   ELSE TMP_DEST[383:320]  <- SRC2[383:320] FI;
 IF IMM0[6] = 0
   THEN TMP_DEST[447:384]  <- SRC1[447:384]
   ELSE TMP_DEST[447:384]  <- SRC1[511:448] FI;
 IF IMM0[7] = 0
   THEN TMP_DEST[511:448]  <- SRC2[447:384]
   ELSE TMP_DEST[511:448] <-  SRC2[511:448] FI;
FI;
FOR j <-  0 TO KL-1
 i <-  j \htmlonly{*} 64
 IF k1[j] OR \htmlonly{*}no writemask\htmlonly{*}
   THEN DEST[i+63:i]  <- TMP_DEST[i+63:i]
   ELSE 
IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+63:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSHUFPD (EVEX encoded versions when SRC2 is memory)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
 i  <- j * 64
 IF (EVEX.b = 1) 
   THEN TMP_SRC2[i+63:i] <-  SRC2[63:0]
   ELSE TMP_SRC2[i+63:i] <-  SRC2[i+63:i]
 FI;
ENDFOR;
IF IMM0[0] = 0
 THEN TMP_DEST[63:0]  <- SRC1[63:0]
 ELSE TMP_DEST[63:0]  <- SRC1[127:64] FI;
IF IMM0[1] = 0
 THEN TMP_DEST[127:64]  <- TMP_SRC2[63:0]
 ELSE TMP_DEST[127:64]  <- TMP_SRC2[127:64] FI;
IF VL >= 256
 IF IMM0[2] = 0
   THEN TMP_DEST[191:128]  <- SRC1[191:128]
   ELSE TMP_DEST[191:128] <-  SRC1[255:192] FI;
 IF IMM0[3] = 0
   THEN TMP_DEST[255:192]  <- TMP_SRC2[191:128]
   ELSE TMP_DEST[255:192] <-  TMP_SRC2[255:192] FI;
FI;
IF VL >= 512
 IF IMM0[4] = 0
   THEN TMP_DEST[319:256]  <- SRC1[319:256]
   ELSE TMP_DEST[319:256] <-  SRC1[383:320] FI;
 IF IMM0[5] = 0
   THEN TMP_DEST[383:320] <-  TMP_SRC2[319:256]
   ELSE TMP_DEST[383:320]  <- TMP_SRC2[383:320] FI;
 IF IMM0[6] = 0
   THEN TMP_DEST[447:384] <-  SRC1[447:384]
   ELSE TMP_DEST[447:384] <-  SRC1[511:448] FI;
 IF IMM0[7] = 0
   THEN TMP_DEST[511:448] <-  TMP_SRC2[447:384]
   ELSE TMP_DEST[511:448] <-  TMP_SRC2[511:448] FI;
FI;
FOR j <-  0 TO KL-1
 i  <- j * 64
 IF k1[j] OR *no writemask*
   THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+63:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VSHUFPD (VEX.256 encoded version)
```info-verb
IF IMM0[0] = 0
 THEN DEST[63:0]  <-SRC1[63:0]
 ELSE DEST[63:0]  <-SRC1[127:64] FI;
IF IMM0[1] = 0
 THEN DEST[127:64]  <-SRC2[63:0]
 ELSE DEST[127:64] <- SRC2[127:64] FI;
IF IMM0[2] = 0
 THEN DEST[191:128]  <-SRC1[191:128]
 ELSE DEST[191:128] <- SRC1[255:192] FI;
IF IMM0[3] = 0
 THEN DEST[255:192] <- SRC2[191:128]
 ELSE DEST[255:192]  <-SRC2[255:192] FI;
DEST[MAX_VL-1:256] (Unmodified)
```
#### VSHUFPD (VEX.128 encoded version)
```info-verb
IF IMM0[0] = 0
 THEN DEST[63:0] <- SRC1[63:0]
 ELSE DEST[63:0]  <-SRC1[127:64] FI;
IF IMM0[1] = 0
 THEN DEST[127:64] <- SRC2[63:0]
 ELSE DEST[127:64] <- SRC2[127:64] FI;
DEST[MAX_VL-1:128] <- 0
```
#### VSHUFPD (128-bit Legacy SSE version)
```info-verb
IF IMM0[0] = 0
 THEN DEST[63:0]  <-SRC1[63:0]
 ELSE DEST[63:0]  <-SRC1[127:64] FI;
IF IMM0[1] = 0
 THEN DEST[127:64] <- SRC2[63:0]
 ELSE DEST[127:64] <- SRC2[127:64] FI;
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSHUFPD __m512d _mm512_shuffle_pd(__m512d a, __m512d b, int imm);
VSHUFPD __m512d _mm512_mask_shuffle_pd(__m512d s, __mmask8 k, __m512d a, __m512d b, int imm);
VSHUFPD __m512d _mm512_maskz_shuffle_pd( __mmask8 k, __m512d a, __m512d b, int imm);
VSHUFPD __m256d _mm256_shuffle_pd (__m256d a, __m256d b, const int select);
VSHUFPD __m256d _mm256_mask_shuffle_pd(__m256d s, __mmask8 k, __m256d a, __m256d b, int imm);
VSHUFPD __m256d _mm256_maskz_shuffle_pd( __mmask8 k, __m256d a, __m256d b, int imm);
SHUFPD __m128d _mm_shuffle_pd (__m128d a, __m128d b, const int select);
VSHUFPD __m128d _mm_mask_shuffle_pd(__m128d s, __mmask8 k, __m128d a, __m128d b, int imm);
VSHUFPD __m128d _mm_maskz_shuffle_pd( __mmask8 k, __m128d a, __m128d b, int imm);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.

