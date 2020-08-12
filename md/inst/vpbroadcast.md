----------------------------
title : VPBROADCAST (Intel x86/64 assembly instruction)
cat_title : VPBROADCAST
ref_title : VPBROADCAST
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VPBROADCAST

**Load Integer and Broadcast**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.128.66.0F38.W0 78 /r\newline{}VPBROADCASTB xmm1, xmm2/m8|RM|V/V|AVX2|Broadcast a byte integer in the source operand to sixteen locations in xmm1.|
|VEX.256.66.0F38.W0 78 /r\newline{}VPBROADCASTB ymm1, xmm2/m8|RM|V/V|AVX2|Broadcast a byte integer in the source operand to thirty-two locations in ymm1.|
|EVEX.128.66.0F38.W0 78 /r\newline{}VPBROADCASTB xmm1{k1}{z}, xmm2/m8|T1S|V/V|AVX512VLAVX512BW|Broadcast a byte integer in the source operand to locations in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.W0 78 /r\newline{}VPBROADCASTB ymm1{k1}{z}, xmm2/m8|T1S|V/V|AVX512VLAVX512BW|Broadcast a byte integer in the source operand to locations in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.W0 78 /r\newline{}VPBROADCASTB zmm1{k1}{z}, xmm2/m8|T1S|V/V|AVX512BW|Broadcast a byte integer in the source operand to 64 locations in zmm1 subject to writemask k1.|
|VEX.128.66.0F38.W0 79 /r\newline{}VPBROADCASTW xmm1, xmm2/m16|RM|V/V|AVX2|Broadcast a word integer in the source operand to eight locations in xmm1.|
|VEX.256.66.0F38.W0 79 /r\newline{}VPBROADCASTW ymm1, xmm2/m16|RM|V/V|AVX2|Broadcast a word integer in the source operand to sixteen locations in ymm1.|
|EVEX.128.66.0F38.W0 79 /r\newline{}VPBROADCASTW xmm1{k1}{z}, xmm2/m16|T1S|V/V|AVX512VLAVX512BW|Broadcast a word integer in the source operand to locations in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.W0 79 /r\newline{}VPBROADCASTW ymm1{k1}{z}, xmm2/m16|T1S|V/V|AVX512VLAVX512BW|Broadcast a word integer in the source operand to locations in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.W0 79 /r\newline{}VPBROADCASTW zmm1{k1}{z}, xmm2/m16|T1S|V/V|AVX512BW|Broadcast a word integer in the source operand to 32 locations in zmm1 subject to writemask k1.|
|VEX.128.66.0F38.W0 58 /r\newline{}VPBROADCASTD xmm1, xmm2/m32|RM|V/V|AVX2|Broadcast a dword integer in the source operand to four locations in xmm1.|
|VEX.256.66.0F38.W0 58 /r\newline{}VPBROADCASTD ymm1, xmm2/m32|RM|V/V|AVX2|Broadcast a dword integer in the source operand to eight locations in ymm1.|
|EVEX.128.66.0F38.W0 58 /r\newline{}VPBROADCASTD xmm1 {k1}{z}, xmm2/m32|T1S|V/V|AVX512VLAVX512F|Broadcast a dword integer in the source operand to locations in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.W0 58 /r\newline{}VPBROADCASTD ymm1 {k1}{z}, xmm2/m32|T1S|V/V|AVX512VLAVX512F|Broadcast a dword integer in the source operand to locations in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.W0 58 /r\newline{}VPBROADCASTD zmm1 {k1}{z}, xmm2/m32|T1S|V/V|AVX512F|Broadcast a dword integer in the source operand to locations in zmm1 subject to writemask k1.|
|VEX.128.66.0F38.W0 59 /r\newline{}VPBROADCASTQ xmm1, xmm2/m64|RM|V/V|AVX2|Broadcast a qword element in source operand to two locations in xmm1.|
|VEX.256.66.0F38.W0 59 /r\newline{}VPBROADCASTQ ymm1, xmm2/m64|RM|V/V|AVX2|Broadcast a qword element in source operand to four locations in ymm1.|
|EVEX.128.66.0F38.W1 59 /r\newline{}VPBROADCASTQ xmm1 {k1}{z}, xmm2/m64|T1S|V/V|AVX512VLAVX512F|Broadcast a qword element in source operand to locations in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.W1 59 /r\newline{}VPBROADCASTQ ymm1 {k1}{z}, xmm2/m64|T1S|V/V|AVX512VLAVX512F|Broadcast a qword element in source operand to locations in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.W1 59 /r\newline{}VPBROADCASTQ zmm1 {k1}{z}, xmm2/m64|T1S|V/V|AVX512F|Broadcast a qword element in source operand to locations in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.W0 59 /rVBROADCASTI32x2 xmm1 {k1}{z}, xmm2/m64|T2|V/V|AVX512VLAVX512DQ|Broadcast two dword elements in source operand to locations in xmm1 subject to writemask k1.|


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.256.66.0F38.W0 59 /rVBROADCASTI32x2 ymm1 {k1}{z}, xmm2/m64|T2|V/V|AVX512VLAVX512DQ|Broadcast two dword elements in source operand to locations in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.W0 59 /rVBROADCASTI32x2 zmm1 {k1}{z}, xmm2/m64|T2|V/V|AVX512DQ|Broadcast two dword elements in source operand to locations in zmm1 subject to writemask k1.|
|VEX.256.66.0F38.W0 5A /rVBROADCASTI128 ymm1, m128|RM|V/V|AVX2|Broadcast 128 bits of integer data in mem to low and high 128-bits in ymm1.|
|EVEX.256.66.0F38.W0 5A /rVBROADCASTI32X4 ymm1 {k1}{z}, m128|T4|V/V|AVX512VLAVX512F|Broadcast 128 bits of 4 doubleword integer data in mem to locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W0 5A /rVBROADCASTI32X4 zmm1 {k1}{z}, m128|T4|V/V|AVX512F|Broadcast 128 bits of 4 doubleword integer data in mem to locations in zmm1 using writemask k1.|
|EVEX.256.66.0F38.W1 5A /rVBROADCASTI64X2 ymm1 {k1}{z}, m128|T2|V/V|AVX512VLAVX512DQ|Broadcast 128 bits of 2 quadword integer data in mem to locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W1 5A /rVBROADCASTI64X2 zmm1 {k1}{z}, m128|T2|V/V|AVX512DQ|Broadcast 128 bits of 2 quadword integer data in mem to locations in zmm1 using writemask k1.|
|EVEX.512.66.0F38.W0 5B /rVBROADCASTI32X8 zmm1 {k1}{z}, m256|T8|V/V|AVX512DQ|Broadcast 256 bits of 8 doubleword integer data in mem to locations in zmm1 using writemask k1.|
|EVEX.512.66.0F38.W1 5B /rVBROADCASTI64X4 zmm1 {k1}{z}, m256|T4|V/V|AVX512F|Broadcast 256 bits of 4 quadword integer data in mem to locations in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1S, T2, T4, T8|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Load integer data from the source operand (the second operand) and broadcast to all elements of the destination operand (the first operand).

VEX256-encoded VPBROADCASTB/W/D/Q: The source operand is 8-bit, 16-bit, 32-bit, 64-bit memory location or the low 8-bit, 16-bit 32-bit, 64-bit data in an XMM register. The destination operand is a YMM register. VPBROADCASTI128 support the source operand of 128-bit memory location. Register source encodings for VPBROADCASTI128 is reserved and will #UD. Bits (MAX_VL-1:256) of the destination register are zeroed.

EVEX-encoded VPBROADCASTD/Q: The source operand is a 32-bit, 64-bit memory location or the low 32-bit, 64-bit data in an XMM register. The destination operand is a ZMM/YMM/XMM register and updated according to the writemask k1. 

VPBROADCASTI32X4 and VPBROADCASTI64X4: The destination operand is a ZMM register and updated according to the writemask k1. The source operand is 128-bit or 256-bit memory location. Register source encodings for VBROADCASTI32X4 and VBROADCASTI64X4 are reserved and will #UD.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

If VPBROADCASTI128 is encoded with VEX.L= 0, an attempt to execute the instruction encoded with VEX.L= 0 will cause an #UD exception.

```embed
<figure>
<svg viewBox="0 0 396.480042 212.580017">
<rect x="0.000000" y="10.000000" width="0.480000" height="115.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="115.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="125.440002" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.260010,88.239990 L223.380005,88.359985 L223.500000,88.539978 C224.274017 89.153015,225.390015 88.471985,225.119995 87.459961  L225.059998,87.279968 L224.940002,87.159973 C224.401001 86.320007,223.072998 86.841003,223.140015 87.820007  L223.200012,88.000000 L223.260010,88.239990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.100006,87.760010 L226.080017,91.540039 L226.380005,92.140015 L225.720001,92.260010 L210.420013,95.320007 L208.679993,95.679993 L210.000000,94.479980 L221.399994,83.799988 L221.880005,83.380005 L222.179993,83.919983 L222.059998,84.520020 L210.660004,95.200012 L210.000000,94.479980 L210.240021,94.359985 L225.540009,91.299988 L225.720001,92.260010 L225.179993,92.020020 L223.200012,88.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.180023,83.919983 L224.100037,87.760010 L223.200012,88.239990 L221.280029,84.399963" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.680023,88.000000 L225.660034,91.780029 L210.360016,94.840027 L221.760010,84.159973" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.640015,39.220032 L319.740021,37.480042 L223.740021,86.920044 L224.640015,88.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="24.820007" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="24.579956" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="24.820007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="38.079956" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="24.580017" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.279999,79.359985 L320.519989,79.359985 L320.700012,79.299988 C321.578003 78.945984,321.510010 77.580994,320.519989 77.380005  L320.100006,77.380005 C319.139984 77.703979,319.010986 78.799011,319.920013 79.299988  L320.100006,79.359985 L320.279999,79.359985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,78.400024 L324.600006,78.460022 L325.260010,78.520020 L325.079987,79.119995 L320.639984,94.059998 L320.160004,95.740051 L319.679993,94.059998 L315.540009,79.000000 L315.359985,78.340027 L316.019989,78.340027 L316.500000,78.700012 L320.639984,93.760010 L319.679993,94.059998 L319.679993,93.760010 L324.119995,78.820007 L325.079987,79.119995 L324.600006,79.480042 L320.339996,79.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M316.020020,78.340027 L320.340027,78.400024 L320.340027,79.420044 L316.020020,79.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,78.880005 L324.600006,78.940002 L320.160004,93.880005 L316.019989,78.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.720001,38.320007 L319.739990,38.320007 L319.380005,78.400024 L321.360016,78.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.900024,82.000000 L292.260010,82.119995 C293.216034 82.364014,293.831024 81.065002,293.100037 80.440002  L292.980011,80.320007 L292.800018,80.200012 L292.620026,80.200012 L292.380035,80.140015 L292.200012,80.200012 L291.840027,80.320007 L291.720032,80.440002 L291.480011,80.799988 L291.420013,80.979980 L291.420013,81.340027 L291.480011,81.520020 L291.600037,81.700012 L291.720032,81.880005 L291.900024,82.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.380005,81.160034 L295.980011,83.500061 L296.520020,83.920044 L296.040009,84.340027 L284.279999,94.600037 L282.959991,95.740051 L283.500000,94.060059 L288.059998,79.120056 L288.239990,78.460022 L288.779999,78.820007 L289.020020,79.420044 L284.459991,94.360046 L283.500000,94.060059 L283.619995,93.820007 L295.380005,83.560059 L296.040009,84.340027 L295.440002,84.400024 L291.839996,82.060059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.779999,78.820007 L292.380005,81.160034 L291.839996,82.059998 L288.239990,79.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.140015,81.580017 L295.740021,83.920044 L283.980011,94.179993 L288.540009,79.239990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.000000,38.859985 L319.320007,37.779968 L291.600006,80.619995 L293.279999,81.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.779999,85.720032 L258.959991,85.840027 L259.079987,85.960022 C259.933990 86.508057,260.964996 85.495056,260.459991 84.640015  L260.399994,84.520020 L260.100006,84.220032 L259.739990,84.100037 L259.500000,84.100037 L259.139984,84.220032 L258.959991,84.340027 C258.730988 84.533020,258.559998 84.876038,258.600006 85.180054  L258.600006,85.360046 L258.660004,85.540039 L258.779999,85.720032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.559998,85.119995 L262.200012,88.479980 L262.619995,89.020020 L262.019989,89.260010 L247.500000,95.080017 L245.820007,95.739990 L246.899994,94.299988 L256.139984,81.760010 L256.559998,81.159973 L256.919983,81.700012 L256.919983,82.299988 L247.679993,94.900024 L246.899994,94.299988 L247.139984,94.119995 L261.660004,88.299988 L262.019989,89.260010 L261.419983,89.080017 L258.779999,85.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.920013,81.700012 L259.560028,85.119995 L258.779999,85.780029 L256.140015,82.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.200012,85.419983 L261.840027,88.779968 L247.320007,94.599976 L256.559998,82.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.760010,39.100037 L319.559998,37.540039 L258.960022,84.340027 L260.160004,85.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="95.679993" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="95.440002" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="95.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="108.940002" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="95.440002" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.020020" y="95.679993" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="229.020020" y="95.440002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="95.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="108.940002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="95.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.160004" y="95.679993" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="266.160004" y="95.440002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="95.679993" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="108.940002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="95.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.800018" y="95.679993" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="154.800018" y="95.440002" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="95.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="108.940002" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="95.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.880005" y="95.679993" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.880005" y="95.440002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="95.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="108.940002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="95.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.519997" y="95.679993" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="80.519997" y="95.440002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="95.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="108.940002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="95.440002" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.659996" y="95.679993" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="117.659996" y="95.440002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="95.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="108.940002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="95.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.379997" y="95.679993" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="43.379997" y="95.440002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="95.679993" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="108.940002" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="95.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.200012,89.679993 L190.260010,89.859985 L190.380005,90.039978 C191.207001 90.653015,192.140015 90.182983,192.120026 89.140015  L192.059998,88.960022 L191.940002,88.779968 C191.506012 87.940002,190.023010 88.364990,190.140015 89.320007  L190.140015,89.500000 L190.200012,89.679993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M191.040009,89.320007 L192.660004,93.340027 L192.899994,94.000000 L192.240021,94.059998 L176.700012,95.559998 L174.960022,95.679993 L176.339996,94.660034 L188.700012,85.119995 L189.240021,84.700012 L189.480011,85.299988 L189.360016,85.900024 L177.000000,95.440002 L176.339996,94.660034 L176.640015,94.539978 L192.180023,93.039978 L192.240021,94.059998 L191.760010,93.700012 L190.140015,89.679993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.480011,85.299988 L191.040009,89.320007 L190.140015,89.679993 L188.580017,85.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.619995,89.500000 L192.239990,93.520020 L176.699982,95.020020 L189.059998,85.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.520020,39.280029 L319.800018,37.420044 L190.740021,88.420044 L191.460022,90.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M150.119995,90.880005 L150.179993,91.059998 L150.299988,91.239990 C150.946991 91.940979,152.127014 91.424988,152.040009 90.460022  L151.920013,90.099976 C151.440002 89.268982,150.255005 89.413025,150.059998 90.460022  L150.059998,90.640015 L150.119995,90.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.080017,90.580017 L152.340027,94.720032 L152.460022,95.320007 L151.800018,95.380005 L136.260010,95.679993 L134.460022,95.679993 L135.960022,94.720032 L148.980011,86.200012 L149.520020,85.840027 L149.760010,86.500000 L149.520020,87.040039 L136.500000,95.559998 L135.960022,94.720032 L136.260010,94.660034 L151.860016,94.360046 L151.800018,95.380005 L151.320007,95.020020 L150.059998,90.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M149.760010,86.500000 L151.080017,90.580017 L150.059998,90.880005 L148.739990,86.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M150.600006,90.700012 L151.859985,94.840027 L136.260010,95.140015 L149.279999,86.619995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.460022,39.280029 L319.860016,37.360046 L150.780029,89.620056 L151.380005,91.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.519997,91.540039 L116.639992,91.720032 L116.699989,91.900024 C117.292992 92.722046,118.583992 92.222046,118.499992 91.240051  L118.499992,91.060059 L118.379997,90.880066 L118.320000,90.700012 L118.139992,90.580017 L118.019997,90.460022 L117.840004,90.340027 L117.659996,90.340027 L117.480003,90.280029 L117.239998,90.340027 C116.946999 90.387024,116.626991 90.707031,116.579994 91.000061  L116.519997,91.180054 L116.519997,91.540039" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M117.480003,91.299988 L118.620003,95.440002 L118.739998,96.099976 L118.080009,96.039978 L102.480003,95.739990 L100.739998,95.679993 L102.239998,94.779968 L115.620003,86.859985 L116.220009,86.500000 L116.400002,87.159973 L116.159996,87.700012 L102.780006,95.619995 L102.239998,94.779968 L102.540001,94.719971 L118.140007,95.080017 L118.080009,96.039978 L117.599998,95.679993 L116.459999,91.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.400002,87.160034 L117.480003,91.300049 L116.459999,91.540039 L115.379997,87.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M117.000008,91.419983 L118.140007,95.559998 L102.540001,95.200012 L115.920006,87.279968" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.400024,39.280029 L319.920013,37.360046 L117.240013,90.340027 L117.720024,92.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.200005,92.140015 L76.260002,92.380005 L76.320000,92.559998 L76.500008,92.679993 L76.620003,92.799988 L77.160011,92.980042 L77.400002,92.920044 L77.580009,92.859985 L77.760002,92.739990 L78.000008,92.500000 L78.120003,92.320007 L78.120003,92.140015 L78.180000,91.960022 L78.120003,91.720032 L78.000008,91.359985 L77.879997,91.239990 L77.520012,91.000000 L77.340004,90.940002 L77.160011,90.940002 L76.920006,91.000000 C76.532997 91.112000,76.401009 91.148987,76.260002 91.600037  L76.140007,91.960022 L76.200005,92.140015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M77.159996,91.960022 L78.059990,96.160034 L78.120003,96.820007 L77.519997,96.760010 L61.980003,95.800049 L60.239998,95.740051 L61.739998,94.900024 L75.419991,87.460022 L76.019997,87.160034 L76.199989,87.760010 L75.959999,88.300049 L62.279991,95.740051 L61.739998,94.900024 L62.040001,94.840027 L77.579994,95.800049 L77.519997,96.760010 L77.040001,96.400024 L76.139992,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.200005,87.760010 L77.160011,91.960022 L76.140007,92.200012 L75.180000,88.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.680000,92.080017 L77.579994,96.280029 L62.040001,95.320007 L75.719994,87.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.400024,39.280029 L319.980011,37.360046 L76.980019,91.000000 L77.400017,92.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="62.460472" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="131.220001" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="94.019997" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="173.820496" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="279.720001" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="247.979980" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="322.320496" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="316.800018" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="319.320007" y="33.340027" textLength="4.170000" font-size="8px">0</text>
<text x="275.458527" y="34.960022" textLength="4.170000" font-size="8px">2</text>
<text x="271.308014" y="34.960022" textLength="4.170000" font-size="8px">3</text>
<text x="34.078499" y="104.200012" textLength="5.002500" font-size="8px">S</text>
<text x="23.700005" y="104.200012" textLength="5.415000" font-size="8px">D</text>
<text x="29.095497" y="104.200012" textLength="5.002500" font-size="8px">E</text>
<text x="314.339996" y="33.340027" textLength="5.002500" font-size="8px">X</text>
<text x="56.939995" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="39.118492" y="104.200012" textLength="4.582500" font-size="8px">T</text>
<text x="205.440002" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="136.679962" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="242.520020" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="168.300018" y="105.820007" textLength="5.530430" font-size="8px">X</text>
<text x="265.080017" y="34.960022" textLength="6.247500" font-size="8px">m</text>
<text x="210.960480" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="99.479942" y="105.820007" textLength="4.610074" font-size="8px">0</text>
<text x="285.179962" y="105.820007" textLength="4.610074" font-size="8px">0</text>
</svg>
<figcaption>Figure 5-16.  VPBROADCASTD Operation (VEX.256 encoded version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.480042 164.979675">
<rect x="0.000000" y="10.000000" width="0.480000" height="115.919998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="115.919998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519958" width="396.480011" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="125.920013" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.260010,89.380035 L223.380005,89.560028 L223.500000,89.680023 C224.249023 90.287048,225.376007 89.620026,225.119995 88.660034  L225.059998,88.480042 L224.940002,88.300049 C224.412018 87.557037,223.044006 87.956024,223.140015 88.960022  L223.200012,89.200043 L223.260010,89.380035" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.100006,88.900024 L226.080017,92.740021 L226.380005,93.340027 L225.720001,93.460022 L210.420013,96.460022 L208.679993,96.820038 L210.000000,95.620026 L221.399994,84.940033 L221.880005,84.520020 L222.179993,85.060028 L222.059998,85.660034 L210.660004,96.340027 L210.000000,95.620026 L210.240021,95.500031 L225.540009,92.500031 L225.720001,93.460022 L225.179993,93.220032 L223.200012,89.380035" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.180023,85.060028 L224.100037,88.900024 L223.200012,89.380035 L221.280029,85.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.680023,89.140015 L225.660034,92.980011 L210.360016,95.980011 L221.760010,85.300018" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.640015,40.360016 L319.740021,38.619995 L223.740021,88.060028 L224.640015,89.800018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="25.960022" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="25.719971" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="25.960022" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="39.220032" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="25.720032" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.279999,80.560028 L320.519989,80.500031 L320.880005,80.380035 L321.000000,80.260040 L321.239990,79.900024 L321.299988,79.720032 L321.299988,79.360016 C321.165985 78.971039,321.170990 78.764038,320.700012 78.640015  L320.339996,78.520020 L320.100006,78.520020 C319.164001 78.759033,319.011993 80.076019,319.920013 80.440033  L320.279999,80.560028" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,79.540039 L324.600006,79.600037 L325.260010,79.660034 L325.079987,80.260040 L320.639984,95.200043 L320.160004,96.880035 L319.679993,95.200043 L315.540009,80.140045 L315.359985,79.480042 L316.019989,79.480042 L316.500000,79.840027 L320.639984,94.900024 L319.679993,95.200043 L319.679993,94.900024 L324.119995,79.960052 L325.079987,80.260040 L324.600006,80.620026 L320.339996,80.560028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M316.020020,79.480042 L320.340027,79.540039 L320.340027,80.560028 L316.020020,80.500031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,80.020020 L324.600006,80.080017 L320.160004,95.020020 L316.019989,79.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.720001,39.460022 L319.739990,39.460022 L319.380005,79.540039 L321.360016,79.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.900024,83.140015 L292.080017,83.260010 L292.260010,83.320007 C293.286011 83.356018,293.790039 82.308014,293.100037 81.580017  L292.980011,81.460022 L292.800018,81.400024 C291.844025 80.926025,291.000031 82.236023,291.600037 82.840027  L291.720032,83.020020 L291.900024,83.140015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.380005,82.300018 L295.980011,84.640015 L296.520020,85.060028 L296.040009,85.480011 L284.279999,95.740021 L282.959991,96.880005 L283.500000,95.200012 L288.059998,80.260010 L288.239990,79.600006 L288.779999,79.960022 L289.020020,80.560028 L284.459991,95.500031 L283.500000,95.200012 L283.619995,94.960022 L295.380005,84.700012 L296.040009,85.480011 L295.440002,85.540009 L291.839996,83.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.779999,79.960022 L292.380005,82.300018 L291.839996,83.200012 L288.239990,80.860016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.140015,82.720032 L295.740021,85.060028 L283.980011,95.320038 L288.540009,80.380035" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.000000,40.000031 L319.320007,38.920044 L291.600006,81.760040 L293.279999,82.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.779999,86.860016 L258.959991,87.040009 L259.079987,87.100006 C260.003998 87.706024,260.936005 86.538025,260.459991 85.840027  L260.399994,85.660004 L260.100006,85.360016 L259.739990,85.240021 L259.500000,85.240021 L259.139984,85.360016 L258.959991,85.480011 L258.839996,85.600006 L258.720001,85.780029 L258.600006,86.140015 L258.600006,86.500031 L258.660004,86.680023 L258.779999,86.860016" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.559998,86.260040 L262.200012,89.680054 L262.619995,90.220032 L262.019989,90.460052 L247.500000,96.220032 L245.820007,96.880035 L246.899994,95.440033 L256.139984,82.900055 L256.559998,82.300049 L256.919983,82.840027 L256.919983,83.440033 L247.679993,96.040039 L246.899994,95.440033 L247.139984,95.260040 L261.660004,89.500031 L262.019989,90.460052 L261.419983,90.280029 L258.779999,86.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.920013,82.840027 L259.560028,86.260040 L258.779999,86.920013 L256.140015,83.500031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.200012,86.560028 L261.840027,89.980042 L247.320007,95.740021 L256.559998,83.140015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.760010,40.240021 L319.559998,38.679993 L258.960022,85.480011 L260.160004,87.040009" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="96.820038" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="96.580017" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="96.820038" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="110.080017" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="96.580048" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.020020" y="96.820038" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="229.020020" y="96.580017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="96.820038" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="110.080017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="96.580048" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.160004" y="96.820038" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="266.160004" y="96.580017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="96.820038" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="110.080017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="96.580048" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.800018" y="96.820038" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="154.800018" y="96.580017" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="96.820038" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="110.080017" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="96.580048" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.880005" y="96.820038" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.880005" y="96.580017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="96.820038" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="110.080017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="96.580048" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.519997" y="96.820038" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="80.519997" y="96.580017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="96.820038" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="110.080017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="96.580048" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.659996" y="96.820038" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="117.659996" y="96.580017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="96.820038" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="110.080017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="96.580048" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.379997" y="96.820038" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="43.379997" y="96.580017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="96.820038" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="110.080017" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="96.580048" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="94.019997" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="205.440002" y="107.020020" textLength="5.530430" font-size="8px">X</text>
<text x="285.179962" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="279.720001" y="107.020020" textLength="5.530430" font-size="8px">X</text>
<text x="247.979980" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="242.520020" y="107.020020" textLength="5.530430" font-size="8px">X</text>
<text x="322.320496" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="265.080017" y="36.100037" textLength="6.247500" font-size="8px">m</text>
<text x="34.078499" y="105.340027" textLength="5.002500" font-size="8px">S</text>
<text x="29.095497" y="105.340027" textLength="5.002500" font-size="8px">E</text>
<text x="23.700005" y="105.340027" textLength="5.415000" font-size="8px">D</text>
<text x="56.939995" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="319.320007" y="34.480042" textLength="4.170000" font-size="8px">0</text>
<text x="271.308014" y="36.100037" textLength="4.170000" font-size="8px">3</text>
<text x="39.118492" y="105.340027" textLength="4.582500" font-size="8px">T</text>
<text x="168.300018" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="210.960480" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="316.800018" y="107.020020" textLength="5.530430" font-size="8px">X</text>
<text x="131.220001" y="107.020020" textLength="4.610074" font-size="8px">0</text>
<text x="275.458527" y="36.100037" textLength="4.170000" font-size="8px">2</text>
<text x="314.339996" y="34.480042" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-17.  VPBROADCASTD Operation (128-bit version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.480042 171.139221">
<rect x="0.000000" y="10.059998" width="0.480000" height="121.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.059998" width="0.480040" height="121.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="131.680008" width="396.480011" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.660004,92.320007 L237.959991,92.619995 L238.320007,92.740021 L238.500000,92.740021 L238.739990,92.679993 L238.920013,92.619995 L239.100006,92.500000 L239.220001,92.380005 C239.423004 92.128021,239.489014 91.796021,239.459991 91.480011  L239.339996,91.300018 L239.279999,91.119995 L238.980011,90.820007 L238.619995,90.700012 L238.380005,90.700012 L238.019989,90.820007 L237.839996,90.940002 L237.720001,91.059998 L237.600006,91.240021 L237.540009,91.420013 L237.480011,91.600006 L237.480011,91.960022 L237.540009,92.140015 L237.660004,92.320007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.440002,91.720001 L241.080017,95.140015 L241.500000,95.679993 L240.899994,95.920013 L226.380005,101.679993 L224.700012,102.339996 L225.779999,100.899994 L235.019989,88.360016 L235.440002,87.760010 L235.799988,88.299988 L235.799988,88.899994 L226.559998,101.500000 L225.779999,100.899994 L226.019989,100.720001 L240.540009,94.959991 L240.899994,95.920013 L240.299988,95.739990 L237.660004,92.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.800018,88.299988 L238.440033,91.720001 L237.660004,92.379974 L235.020020,88.959991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.080017,92.019989 L240.720032,95.440002 L226.200012,101.199982 L235.440002,88.599976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.640015,45.700012 L298.440002,44.140015 L237.840027,90.940002 L239.040009,92.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.900024" y="31.420013" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="261.900024" y="31.179993" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.880005" y="31.420013" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.660004" y="44.680023" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.660004" y="31.180023" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.040009,86.019989 L299.580017,85.839996 L299.760010,85.720001 L299.880005,85.539978 L299.940002,85.359985 L300.000000,85.179993 L300.000000,84.819977 C299.940002 84.473999,299.779022 84.168976,299.399994 84.099976  L299.040009,83.979980 L298.800018,84.039978 C297.851013 84.190979,297.733002 85.571991,298.619995 85.899994  L298.800018,85.959991 L299.040009,86.019989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.040009,85.000000 L303.960022,85.000000 L303.779999,85.660004 L299.520020,100.660004 L299.040009,102.339996 L298.559998,100.660004 L294.240021,85.660004 L294.059998,85.000000 L294.720001,85.000000 L295.200012,85.359985 L299.520020,100.359985 L298.559998,100.660004 L298.559998,100.359985 L302.820007,85.359985 L303.779999,85.660004 L303.300018,86.019989 L299.040009,86.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.720001" y="85.000000" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.040009,85.480011 L303.300018,85.480011 L299.040009,100.480011 L294.720001,85.480011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.080017" y="44.919983" width="1.980000" height="40.080002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.720001,96.399994 L165.959991,96.759979 C166.579987 97.497986,167.796997 96.828003,167.640015 95.919983  L167.579987,95.679993 L167.519989,95.500000 C166.860992 94.709991,165.661987 95.091980,165.660004 96.040009  L165.660004,96.220001 L165.720001,96.399994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.619995,96.040009 L168.179993,100.059998 L168.359985,100.720001 L167.760010,100.779999 L152.220001,102.160004 L150.479980,102.279999 L151.859985,101.260010 L164.279999,91.899994 L164.880005,91.480011 L165.059998,92.080017 L164.940002,92.680023 L152.519989,102.040009 L151.859985,101.260010 L152.159973,101.140015 L167.699982,99.760010 L167.760010,100.779999 L167.279999,100.420013 L165.720001,96.399994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.059998,92.080017 L166.619995,96.040009 L165.720001,96.400024 L164.160004,92.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.200012,96.220001 L167.760010,100.239990 L152.220001,101.619995 L164.640015,92.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.400024,45.880005 L298.680023,44.020020 L166.320007,95.140015 L167.040039,97.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.680000,98.260010 L88.739998,98.500000 L88.859993,98.619995 C89.381004 99.440002,90.706001 98.988007,90.659996 98.020020  L90.659996,97.779999 L90.540001,97.600006 L90.480003,97.420013 L90.299995,97.300018 L90.180000,97.180023 L89.820000,97.059998 L89.400002,97.059998 C89.107002 97.106995,88.786995 97.427002,88.739998 97.720001  L88.680000,97.900024 L88.680000,98.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.640007,98.019989 L90.720009,102.220001 L90.780006,102.879974 L90.180000,102.819977 L74.580009,102.339996 L72.840004,102.339996 L74.340004,101.440002 L87.840004,93.579987 L88.440010,93.220001 L88.620003,93.879974 L88.380013,94.419983 L74.880013,102.279999 L74.340004,101.440002 L74.640007,101.379974 L90.240013,101.859985 L90.180000,102.819977 L89.700005,102.459991 L88.620003,98.259979" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.620003,93.880005 L89.640007,98.020020 L88.620003,98.260010 L87.599998,94.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.159996,98.140015 L90.239998,102.340027 L74.639992,101.860016 L88.139992,94.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.279999,45.880005 L298.799988,43.959991 L89.399986,97.059998 L89.879997,98.980011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.900024" y="102.279999" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="261.900024" y="102.039978" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.880005" y="102.279999" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.660004" y="115.539978" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.660004" y="102.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.619995" y="102.279999" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="187.619995" y="102.039978" width="74.519997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.660004" y="102.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.380005" y="115.539978" width="74.519997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.380005" y="102.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.400002" y="102.279999" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="113.400002" y="102.039978" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.380005" y="102.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.159996" y="115.539978" width="74.459999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.159996" y="102.040009" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="39.120003" y="102.279999" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="39.120003" y="102.039978" width="74.519997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.159996" y="102.279999" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="38.879997" y="115.539978" width="74.519997" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="38.879997" y="102.040009" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="74.519997" y="112.480011" textLength="4.170000" font-size="8px">0</text>
<text x="69.540001" y="112.480011" textLength="5.002500" font-size="8px">X</text>
<text x="223.020020" y="112.480011" textLength="4.170000" font-size="8px">0</text>
<text x="218.040009" y="112.480011" textLength="5.002500" font-size="8px">X</text>
<text x="34.858498" y="110.860016" textLength="4.582500" font-size="8px">T</text>
<text x="29.875496" y="110.860016" textLength="5.002500" font-size="8px">S</text>
<text x="224.760010" y="39.940002" textLength="6.247500" font-size="8px">m</text>
<text x="231.018005" y="39.940002" textLength="4.170000" font-size="8px">6</text>
<text x="24.835503" y="110.860016" textLength="5.002500" font-size="8px">E</text>
<text x="297.300018" y="112.480011" textLength="4.170000" font-size="8px">0</text>
<text x="19.440002" y="110.860016" textLength="5.415000" font-size="8px">D</text>
<text x="292.260010" y="112.480011" textLength="5.002500" font-size="8px">X</text>
<text x="148.799988" y="112.480011" textLength="4.170000" font-size="8px">0</text>
<text x="297.300018" y="41.559998" textLength="4.170000" font-size="8px">0</text>
<text x="292.260010" y="41.559998" textLength="5.002500" font-size="8px">X</text>
<text x="235.198517" y="39.940002" textLength="4.170000" font-size="8px">4</text>
<text x="143.760010" y="112.480011" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-18.  VPBROADCASTQ Operation (256-bit version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.480042 153.439468">
<rect x="0.000000" y="10.000000" width="0.480000" height="104.820000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="104.820000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="114.819984" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.660004,71.020004 L259.200012,70.840012 L259.380005,70.720001 L259.500000,70.540009 L259.559998,70.419998 L259.619995,70.180008 L259.619995,69.820007 C259.485992 69.431000,259.490997 69.223999,259.019989 69.100006  L258.660004,68.980011 L258.420013,69.040009 C257.489990 69.207001,257.329010 70.562012,258.239990 70.900009  L258.420013,70.960007 L258.660004,71.020004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.660004,70.000000 L263.580017,70.000000 L263.399994,70.660004 L259.140015,85.660004 L258.660004,87.339996 L258.179993,85.660004 L253.860016,70.660004 L253.679993,70.000000 L254.339996,70.000000 L254.820007,70.360001 L259.140015,85.360001 L258.179993,85.660004 L258.179993,85.360001 L262.440002,70.360001 L263.399994,70.660004 L262.920013,71.020004 L258.660004,71.020004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.339996" y="70.000000" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.660004,70.479996 L262.920013,70.479996 L258.660004,85.479996 L254.339996,70.479996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.700012" y="46.959991" width="1.980000" height="23.040001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.500000" y="32.919998" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="190.500000" y="32.680008" width="148.740005" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="338.760010" y="32.919998" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.260010" y="46.180008" width="148.740005" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.260010" y="32.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.879997,83.019997 L125.939995,83.199997 L126.059990,83.379997 C126.702003 84.112999,127.831993 83.740997,127.859993 82.719994  L127.799995,82.479996 L127.739998,82.299995 L127.620003,82.180000 L127.499992,82.000000 L127.320000,81.879997 L126.959999,81.759995 L126.779991,81.759995 L126.599998,81.820000 L126.359993,81.879997 L126.239998,82.000000 L126.059990,82.119995 L125.999992,82.299995 L125.879997,82.419998 L125.820000,82.659996 L125.820000,82.839996 L125.879997,83.019997" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.840004,82.779999 L127.980003,86.919998 L128.100006,87.580002 L127.440010,87.519997 L111.840004,87.339996 L110.099998,87.279999 L111.599998,86.379997 L124.920006,78.339996 L125.519997,77.979996 L125.700005,78.639999 L125.459999,79.180000 L112.140007,87.220001 L111.599998,86.379997 L111.900002,86.320000 L127.500008,86.559998 L127.440010,87.519997 L126.959999,87.159996 L125.820000,83.019997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.700005,78.639999 L126.840004,82.779999 L125.820000,83.019997 L124.680000,78.879997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.360008,82.900002 L127.500008,87.040001 L111.900002,86.800003 L125.220009,78.760002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.960022,47.919998 L258.420013,46.000000 L126.600014,81.820000 L127.140007,83.739998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.160004" y="87.279999" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.160004" y="87.039986" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.420013" y="87.279999" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.920013" y="100.539986" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.920013" y="87.040001" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.659996" y="87.279999" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="42.659996" y="87.039986" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.920013" y="87.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.420006" y="100.539986" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.420006" y="87.040001" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="251.220001" y="43.119995" textLength="5.002500" font-size="8px">X</text>
<text x="181.416016" y="41.500000" textLength="4.170000" font-size="8px">8</text>
<text x="177.256531" y="41.500000" textLength="4.170000" font-size="8px">2</text>
<text x="173.097015" y="41.500000" textLength="4.170000" font-size="8px">1</text>
<text x="166.860016" y="41.500000" textLength="6.247500" font-size="8px">m</text>
<text x="33.358498" y="95.860001" textLength="5.002500" font-size="8px">S</text>
<text x="28.375496" y="95.860001" textLength="5.002500" font-size="8px">E</text>
<text x="256.200012" y="43.119995" textLength="4.170000" font-size="8px">0</text>
<text x="256.860016" y="97.479996" textLength="4.170000" font-size="8px">0</text>
<text x="38.398491" y="95.860001" textLength="4.582500" font-size="8px">T</text>
<text x="108.359993" y="97.479996" textLength="4.170000" font-size="8px">0</text>
<text x="103.379997" y="97.479996" textLength="5.002500" font-size="8px">X</text>
<text x="22.980003" y="95.860001" textLength="5.415000" font-size="8px">D</text>
<text x="251.880005" y="97.479996" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-19.  VBROADCASTI128 Operation (256-bit version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.539978 202.320007">
<rect x="0.000000" y="10.000000" width="0.480000" height="104.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="104.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="114.160034" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,69.700012 L258.839966,69.640015 L259.080017,69.580017 C259.938965 69.252014,259.784973 67.804016,258.839966 67.720032  L258.659973,67.660034 L258.119995,67.840027 L257.940002,67.960022 L257.820007,68.140015 L257.640015,68.679993 C257.757996 68.987000,257.750000 69.353027,258.119995 69.520020  L258.659973,69.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,68.679993 L263.640015,68.679993 L263.459961,69.339966 L259.140015,84.339966 L258.659973,86.020020 L258.179993,84.339966 L253.860001,69.339966 L253.679977,68.679993 L254.339981,68.679993 L254.819992,69.039978 L259.140015,84.039978 L258.179993,84.339966 L258.179993,84.039978 L262.500000,69.039978 L263.459961,69.339966 L262.979980,69.700012 L258.659973,69.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.340012" y="68.679993" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,69.159973 L262.979980,69.159973 L258.659973,84.159973 L254.339981,69.159973" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.700012" y="46.239990" width="1.980000" height="22.440001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="188.520004" y="32.260010" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="188.520004" y="32.020020" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="336.780029" y="32.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="188.280014" y="45.520020" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="188.280014" y="32.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.940002,81.760010 L126.000000,81.940002 L126.059998,82.119995 L126.240005,82.239990 L126.360001,82.359985 L126.540009,82.479980 L126.720001,82.479980 L126.960007,82.540039 L127.320007,82.419983 C127.705002 82.189026,127.735001 82.035034,127.860001 81.640015  L127.860001,81.280029 L127.800003,81.040039 L127.680008,80.919983 L127.559998,80.739990 L127.380005,80.619995 L127.199997,80.559998 L127.020004,80.500000 L126.839996,80.500000 L126.600006,80.559998 C126.283005 80.624023,126.063995 80.875000,125.940002 81.160034  L125.880005,81.400024 L125.880005,81.580017 L125.940002,81.760010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.900009,81.520020 L127.980011,85.660034 L128.160004,86.320007 L127.440002,86.260010 L111.840012,86.080017 L110.100006,86.020020 L111.600006,85.119995 L124.980011,77.080017 L125.580002,76.720032 L125.760010,77.380005 L125.520004,77.920044 L112.140015,85.960022 L111.600006,85.119995 L111.900009,85.059998 L127.500015,85.300049 L127.440002,86.260010 L126.960007,85.900024 L125.880005,81.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.760010,77.380005 L126.900009,81.520020 L125.880005,81.760010 L124.740005,77.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.419998,81.640015 L127.500000,85.780029 L111.899994,85.540039 L125.279999,77.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.960022,47.200012 L258.419983,45.280029 L126.660004,80.559998 L127.200012,82.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.159988" y="85.959961" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.159988" y="85.720032" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.419983" y="85.960022" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="99.220032" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="85.719971" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.660004" y="85.959961" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="42.660004" y="85.720032" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="85.960022" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.419998" y="99.220032" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.419998" y="85.719971" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="108.419998" y="96.159973" textLength="4.170000" font-size="8px">0</text>
<text x="256.920044" y="96.159973" textLength="4.170000" font-size="8px">0</text>
<text x="249.300003" y="42.459961" textLength="5.002500" font-size="8px">X</text>
<text x="175.276505" y="40.839966" textLength="4.170000" font-size="8px">5</text>
<text x="38.398499" y="94.539978" textLength="4.582500" font-size="8px">T</text>
<text x="28.375504" y="94.539978" textLength="5.002500" font-size="8px">E</text>
<text x="179.435989" y="40.839966" textLength="4.170000" font-size="8px">6</text>
<text x="251.940018" y="96.159973" textLength="5.002500" font-size="8px">X</text>
<text x="33.358505" y="94.539978" textLength="5.002500" font-size="8px">S</text>
<text x="22.980003" y="94.539978" textLength="5.415000" font-size="8px">D</text>
<text x="171.116989" y="40.839966" textLength="4.170000" font-size="8px">2</text>
<text x="254.280014" y="42.459961" textLength="4.170000" font-size="8px">0</text>
<text x="164.879990" y="40.839966" textLength="6.247500" font-size="8px">m</text>
<text x="103.440002" y="96.159973" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-20.  VBROADCASTI256 Operation (512-bit version)
</figcaption></figure>
```

### Operation
#### VPBROADCASTB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j  <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i]  <-  SRC[7:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+7:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPBROADCASTW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-   0 TO KL-1
    i  <- j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i]  <-  SRC[15:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-   0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPBROADCASTD (128 bit version)
```info-verb
temp <-   SRC[31:0]
DEST[31:0]  <-  temp
DEST[63:32] <-   temp
DEST[95:64]  <-  temp
DEST[127:96]  <-  temp
DEST[MAX_VL-1:128]  <-  0
```
#### VPBROADCASTD (VEX.256 encoded version)
```info-verb
temp  <-  SRC[31:0]
DEST[31:0]  <-  temp
DEST[63:32]  <-  temp
DEST[95:64]  <-  temp
DEST[127:96] <-   temp
DEST[159:128] <-   temp
DEST[191:160] <-   temp
DEST[223:192]  <-  temp
DEST[255:224]  <-  temp
DEST[MAX_VL-1:256]  <-  0
VPBROADCASTD (EVEX encoded versions)
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i  <- j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-   SRC[31:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPBROADCASTQ (VEX.256 encoded version)
```info-verb
temp <-   SRC[63:0]
DEST[63:0]  <-  temp
DEST[127:64] <-   temp
DEST[191:128]  <-  temp
DEST[255:192]  <-  temp
DEST[MAX_VL-1:256] <-   0
```
#### VPBROADCASTQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-   0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-   SRC[63:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
VBROADCASTI32x2 (EVEX encoded versions)
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i  <- != j * 32
    n  <- != (j mod 2) * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-   SRC[n+31:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VBROADCASTI128 (VEX.256 encoded version)
```info-verb
temp  <-  SRC[127:0]
DEST[127:0] <-   temp
DEST[255:128]  <-  temp
DEST[MAX_VL-1:256]  <-  0
```
#### VBROADCASTI32X4 (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i  <- != j* 32
    n  <- != (j modulo 4) * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-   SRC[n+31:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VBROADCASTI64X2 (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i  <-  j * 64
    n <-  (j modulo 2) * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i]  <-  SRC[n+63:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] = 0
                FI
    FI;
ENDFOR;
```
#### VBROADCASTI32X8 (EVEX.U1.512 encoded version)
```info-verb
FOR j  <-  0 TO 15
    i <-   j * 32
    n <-  (j modulo 8) * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-   SRC[n+31:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-   0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VBROADCASTI64X4 (EVEX.512 encoded version)
```info-verb
FOR j  <-  0 TO 7
    i <-   j * 64
    n  <- != (j modulo 4) * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i]  <-  SRC[n+63:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPBROADCASTB __m512i _mm512_broadcastb_epi8( __m128i a);
VPBROADCASTB __m512i _mm512_mask_broadcastb_epi8(__m512i s, __mmask64 k, __m128i a);
VPBROADCASTB __m512i _mm512_maskz_broadcastb_epi8( __mmask64 k, __m128i a);
VPBROADCASTB __m256i _mm256_broadcastb_epi8(__m128i a);
VPBROADCASTB __m256i _mm256_mask_broadcastb_epi8(__m256i s, __mmask32 k, __m128i a);
VPBROADCASTB __m256i _mm256_maskz_broadcastb_epi8( __mmask32 k, __m128i a);
VPBROADCASTB __m128i _mm_mask_broadcastb_epi8(__m128i s, __mmask16 k, __m128i a);
VPBROADCASTB __m128i _mm_maskz_broadcastb_epi8( __mmask16 k, __m128i a);
VPBROADCASTB __m128i _mm_broadcastb_epi8(__m128i a);
VPBROADCASTD __m512i _mm512_broadcastd_epi32( __m128i a);
VPBROADCASTD __m512i _mm512_mask_broadcastd_epi32(__m512i s, __mmask16 k, __m128i a);
VPBROADCASTD __m512i _mm512_maskz_broadcastd_epi32( __mmask16 k, __m128i a);
VPBROADCASTD __m256i _mm256_broadcastd_epi32( __m128i a);
VPBROADCASTD __m256i _mm256_mask_broadcastd_epi32(__m256i s, __mmask8 k, __m128i a);
VPBROADCASTD __m256i _mm256_maskz_broadcastd_epi32( __mmask8 k, __m128i a);
VPBROADCASTD __m128i _mm_broadcastd_epi32(__m128i a);
VPBROADCASTD __m128i _mm_mask_broadcastd_epi32(__m128i s, __mmask8 k, __m128i a);
VPBROADCASTD __m128i _mm_maskz_broadcastd_epi32( __mmask8 k, __m128i a);
VPBROADCASTQ __m512i _mm512_broadcastq_epi64( __m128i a);
VPBROADCASTQ __m512i _mm512_mask_broadcastq_epi64(__m512i s, __mmask8 k, __m128i a);
VPBROADCASTQ __m512i _mm512_maskz_broadcastq_epi64( __mmask8 k, __m128i a);
VPBROADCASTQ __m256i _mm256_broadcastq_epi64(__m128i a);
VPBROADCASTQ __m256i _mm256_mask_broadcastq_epi64(__m256i s, __mmask8 k, __m128i a);
VPBROADCASTQ __m256i _mm256_maskz_broadcastq_epi64( __mmask8 k, __m128i a);
VPBROADCASTQ __m128i _mm_broadcastq_epi64(__m128i a);
VPBROADCASTQ __m128i _mm_mask_broadcastq_epi64(__m128i s, __mmask8 k, __m128i a);
VPBROADCASTQ __m128i _mm_maskz_broadcastq_epi64( __mmask8 k, __m128i a);
VPBROADCASTW __m512i _mm512_broadcastw_epi16(__m128i a);
VPBROADCASTW __m512i _mm512_mask_broadcastw_epi16(__m512i s, __mmask32 k, __m128i a);
VPBROADCASTW __m512i _mm512_maskz_broadcastw_epi16( __mmask32 k, __m128i a);
VPBROADCASTW __m256i _mm256_broadcastw_epi16(__m128i a);
VPBROADCASTW __m256i _mm256_mask_broadcastw_epi16(__m256i s, __mmask16 k, __m128i a);
VPBROADCASTW __m256i _mm256_maskz_broadcastw_epi16( __mmask16 k, __m128i a);
VPBROADCASTW __m128i _mm_broadcastw_epi16(__m128i a);
VPBROADCASTW __m128i _mm_mask_broadcastw_epi16(__m128i s, __mmask8 k, __m128i a);
VPBROADCASTW __m128i _mm_maskz_broadcastw_epi16( __mmask8 k, __m128i a);
VBROADCASTI32x2 __m512i _mm512_broadcast_i32x2( __m128i a);
VBROADCASTI32x2 __m512i _mm512_mask_broadcast_i32x2(__m512i s, __mmask16 k, __m128i a);
VBROADCASTI32x2 __m512i _mm512_maskz_broadcast_i32x2( __mmask16 k, __m128i a);
VBROADCASTI32x2 __m256i _mm256_broadcast_i32x2( __m128i a);
VBROADCASTI32x2 __m256i _mm256_mask_broadcast_i32x2(__m256i s, __mmask8 k, __m128i a);
VBROADCASTI32x2 __m256i _mm256_maskz_broadcast_i32x2( __mmask8 k, __m128i a);
VBROADCASTI32x2 __m128i _mm_broadcastq_i32x2(__m128i a);
VBROADCASTI32x2 __m128i _mm_mask_broadcastq_i32x2(__m128i s, __mmask8 k, __m128i a);
VBROADCASTI32x2 __m128i _mm_maskz_broadcastq_i32x2( __mmask8 k, __m128i a);
VBROADCASTI32x4 __m512i _mm512_broadcast_i32x4( __m128i a);
VBROADCASTI32x4 __m512i _mm512_mask_broadcast_i32x4(__m512i s, __mmask16 k, __m128i a);
VBROADCASTI32x4 __m512i _mm512_maskz_broadcast_i32x4( __mmask16 k, __m128i a);
VBROADCASTI32x4 __m256i _mm256_broadcast_i32x4( __m128i a);
VBROADCASTI32x4 __m256i _mm256_mask_broadcast_i32x4(__m256i s, __mmask8 k, __m128i a);
VBROADCASTI32x4 __m256i _mm256_maskz_broadcast_i32x4( __mmask8 k, __m128i a);
VBROADCASTI32x8 __m512i _mm512_broadcast_i32x8( __m256i a);
VBROADCASTI32x8 __m512i _mm512_mask_broadcast_i32x8(__m512i s, __mmask16 k, __m256i a);
VBROADCASTI32x8 __m512i _mm512_maskz_broadcast_i32x8( __mmask16 k, __m256i a);
VBROADCASTI64x2 __m512i _mm512_broadcast_i64x2( __m128i a);
VBROADCASTI64x2 __m512i _mm512_mask_broadcast_i64x2(__m512i s, __mmask8 k, __m128i a);
VBROADCASTI64x2 __m512i _mm512_maskz_broadcast_i64x2( __mmask8 k, __m128i a);
VBROADCASTI64x2 __m256i _mm256_broadcast_i64x2( __m128i a);
VBROADCASTI64x2 __m256i _mm256_mask_broadcast_i64x2(__m256i s, __mmask8 k, __m128i a);
VBROADCASTI64x2 __m256i _mm256_maskz_broadcast_i64x2( __mmask8 k, __m128i a);
VBROADCASTI64x4 __m512i _mm512_broadcast_i64x4( __m256i a);
VBROADCASTI64x4 __m512i _mm512_mask_broadcast_i64x4(__m512i s, __mmask8 k, __m256i a);
VBROADCASTI64x4 __m512i _mm512_maskz_broadcast_i64x4( __mmask8 k, __m256i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type 6; 

EVEX-encoded instructions, syntax with reg/mem operand, see Exceptions Type E6.

#UD If VEX.L = 0 for VPBROADCASTQ, VPBROADCASTI128.

                              If EVEX.L'L = 0 for VBROADCASTI32X4/VBROADCASTI64X2.

                              If EVEX.L'L < 10b for VBROADCASTI32X8/VBROADCASTI64X4.

