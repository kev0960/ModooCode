----------------------------
title : VBROADCAST (Intel x86/64 assembly instruction)
cat_title : VBROADCAST
ref_title : VBROADCAST
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VBROADCAST

**Load with Broadcast Floating-Point Data**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|--------------------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.128.66.0F38.W0 18 /r\newline{}VBROADCASTSS xmm1, m32|RM|V/V|AVX|Broadcast single-precision floating-point element in mem to four locations in xmm1.|
|VEX.256.66.0F38.W0 18 /r\newline{}VBROADCASTSS ymm1, m32|RM|V/V|AVX|Broadcast single-precision floating-point element in mem to eight locations in ymm1.|
|VEX.256.66.0F38.W0 19 /r\newline{}VBROADCASTSD ymm1, m64|RM|V/V|AVX|Broadcast double-precision floating-point element in mem to four locations in ymm1.|
|VEX.256.66.0F38.W0 1A /r\newline{}VBROADCASTF128 ymm1, m128|RM|V/V|AVX|Broadcast 128 bits of floating-point data in mem to low and high 128-bits in ymm1.|
|EVEX.256.66.0F38.W1 19 /r\newline{}VBROADCASTSD ymm1 {k1}{z}, xmm2/m64|T1S|V/V|AVX512VL\newline{}AVX512F|Broadcast low double-precision floating-point element in xmm2/m64 to four locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W1 19 /r\newline{}VBROADCASTSD zmm1 {k1}{z}, xmm2/m64|T1S|V/V|AVX512F|Broadcast low double-precision floating-point element in xmm2/m64 to eight locations in zmm1 using writemask k1.|
|EVEX.256.66.0F38.W0 19 /r\newline{}VBROADCASTF32X2 ymm1 {k1}{z}, xmm2/m64|T2|V/V|AVX512VL\newline{}AVX512DQ|Broadcast two single-precision floating-point elements in xmm2/m64 to locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W0 19 /r\newline{}VBROADCASTF32X2 zmm1 {k1}{z}, xmm2/m64|T2|V/V|AVX512DQ|Broadcast two single-precision floating-point elements in xmm2/m64 to locations in zmm1 using writemask k1.|
|EVEX.128.66.0F38.W0 18 /r\newline{}VBROADCASTSS xmm1 {k1}{z}, xmm2/m32|T1S|V/V|AVX512VL\newline{}AVX512F|Broadcast low single-precision floating-point element in xmm2/m32 to all locations in xmm1 using writemask k1.|
|EVEX.256.66.0F38.W0 18 /r\newline{}VBROADCASTSS ymm1 {k1}{z}, xmm2/m32|T1S|V/V|AVX512VL\newline{}AVX512F|Broadcast low single-precision floating-point element in xmm2/m32 to all locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W0 18 /r\newline{}VBROADCASTSS zmm1 {k1}{z}, xmm2/m32|T1S|V/V|AVX512F|Broadcast low single-precision floating-point element in xmm2/m32 to all locations in zmm1 using writemask k1.|
|EVEX.256.66.0F38.W0 1A /r\newline{}VBROADCASTF32X4 ymm1 {k1}{z}, m128|T4|V/V|AVX512VL\newline{}AVX512F|Broadcast 128 bits of 4 single-precision floating-point data in mem to locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W0 1A /r\newline{}VBROADCASTF32X4 zmm1 {k1}{z}, m128|T4|V/V|AVX512F|Broadcast 128 bits of 4 single-precision floating-point data in mem to locations in zmm1 using writemask k1.|
|EVEX.256.66.0F38.W1 1A /r\newline{}VBROADCASTF64X2 ymm1 {k1}{z}, m128|T2|V/V|AVX512VL\newline{}AVX512DQ|Broadcast 128 bits of 2 double-precision floating-point data in mem to locations in ymm1 using writemask k1.|
|EVEX.512.66.0F38.W1 1A /r\newline{}VBROADCASTF64X2 zmm1 {k1}{z}, m128|T2|V/V|AVX512DQ|Broadcast 128 bits of 2 double-precision floating-point data in mem to locations in zmm1 using writemask k1.|
|EVEX.512.66.0F38.W0 1B /r\newline{}VBROADCASTF32X8 zmm1 {k1}{z}, m256|T8|V/V|AVX512DQ|Broadcast 256 bits of 8 single-precision floating-point data in mem to locations in zmm1 using writemask k1.|
|EVEX.512.66.0F38.W1 1B /r\newline{}VBROADCASTF64X4 zmm1 {k1}{z}, m256|T4|V/V|AVX512F|Broadcast 256 bits of 4 double-precision floating-point data in mem to locations in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1S, T2, T4, T8|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


VBROADCASTSD/VBROADCASTSS/VBROADCASTF128 load floating-point values as one tuple from the source operand (second operand) in memory and broadcast to all elements of the destination operand (first operand). 

     VEX256-encoded versions: The destination operand is a YMM register. The source operand is either a 32-bit,64-bit, or 128-bit memory location. Register source encodings are reserved and will #UD. Bits (MAX_VL-1:256) of the destination register are zeroed.

     EVEX-encoded versions: The destination operand is a ZMM/YMM/XMM register and updated according to thewritemask  k1.  The  source  operand  is  either  a  32-bit,  64-bit  memory  location  or  the  lowdoubleword/quadword element of an XMM register. 

VBROADCASTF32X2/VBROADCASTF32X4/VBROADCASTF64X2/VBROADCASTF32X8/VBROADCASTF64X4 load floating-point values as tuples from the source operand (the second operand) in memory or register and broadcast to all elements of the destination operand (the first operand). The destination operand is a YMM/ZMM register updated according to the writemask k1. The source operand is either a register or 64-bit/128-bit/256-bit memory location.

VBROADCASTSD and VBROADCASTF128,F32x4 and F64x2 are only supported as 256-bit and 512-bit wide versions and up. VBROADCASTSS is supported in 128-bit, 256-bit and 512-bit wide versions. F32x8 and F64x4 are only supported as 512-bit wide versions.

VBROADCASTF32X2/VBROADCASTF32X4/VBROADCASTF32X8 have 32-bit granularity. VBROADCASTF64X2 and VBROADCASTF64X4 have 64-bit granularity. 

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

If VBROADCASTSD or VBROADCASTF128 is encoded with VEX.L= 0, an attempt to execute the instruction encoded with VEX.L= 0 will cause an #UD exception.

```embed
<figure>
<svg viewBox="0 0 396.480042 139.839996">
<rect x="0.000000" y="10.000000" width="0.480000" height="112.620003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="112.620003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="122.679993" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.260010,88.839996 L223.380005,89.019989 L223.500000,89.139984 C224.249023 89.747009,225.376007 89.079987,225.119995 88.119995  L225.059998,87.940002 L224.940002,87.760010 C224.390015 87.005981,223.076019 87.429993,223.140015 88.419983  L223.200012,88.660004 L223.260010,88.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.100006,88.359985 L226.080017,92.199982 L226.380005,92.799988 L225.720001,92.919983 L210.420013,95.919983 L208.679993,96.279999 L210.000000,95.079987 L221.399994,84.399994 L221.880005,83.979980 L222.179993,84.519989 L222.059998,85.119995 L210.660004,95.799988 L210.000000,95.079987 L210.240021,94.959991 L225.540009,91.959991 L225.720001,92.919983 L225.179993,92.679993 L223.200012,88.839996" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.180023,84.519989 L224.100037,88.359985 L223.200012,88.839996 L221.280029,85.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.680023,88.599976 L225.660034,92.439972 L210.360016,95.439972 L221.760010,84.759979" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.640015,39.819977 L319.740021,38.079987 L223.740021,87.519989 L224.640015,89.259979" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="25.419983" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="25.179993" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="25.420013" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="38.679993" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="25.179993" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.279999,80.019989 L320.519989,79.959991 L320.880005,79.839996 L321.000000,79.720001 L321.119995,79.539978 L321.239990,79.419983 L321.299988,79.179993 L321.299988,78.819977 C321.165985 78.431000,321.170990 78.223999,320.700012 78.099976  L320.339996,77.979980 L320.100006,78.039978 C319.151001 78.112976,319.035004 79.608002,319.920013 79.899994  L320.279999,80.019989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,79.000000 L324.600006,79.059998 L325.260010,79.119995 L325.079987,79.720001 L320.639984,94.660004 L320.160004,96.339996 L319.679993,94.660004 L315.540009,79.660004 L315.359985,79.000000 L316.019989,79.000000 L316.500000,79.359985 L320.639984,94.359985 L319.679993,94.660004 L319.679993,94.359985 L324.119995,79.420013 L325.079987,79.720001 L324.600006,80.079987 L320.339996,80.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.020020" y="79.000000" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,79.479980 L324.600006,79.539978 L320.160004,94.479980 L316.019989,79.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.720001,38.919983 L319.739990,38.919983 L319.380005,79.000000 L321.360016,79.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.900024,82.599976 L292.080017,82.719971 L292.260010,82.779968 C293.286011 82.815979,293.790039 81.767975,293.100037 81.039978  L292.980011,80.919983 L292.800018,80.859985 C291.869019 80.409973,291.002014 81.603973,291.600037 82.359985  L291.720032,82.479980 L291.900024,82.599976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.380005,81.759979 L295.980011,84.099976 L296.520020,84.519989 L296.040009,84.939972 L284.279999,95.199982 L282.959991,96.339966 L283.500000,94.659973 L288.059998,79.719971 L288.239990,79.059967 L288.779999,79.419983 L289.020020,80.019989 L284.459991,94.959991 L283.500000,94.659973 L283.619995,94.419983 L295.380005,84.159973 L296.040009,84.939972 L295.440002,84.999969 L291.839996,82.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.779999,79.419983 L292.380005,81.759979 L291.839996,82.659973 L288.239990,80.319977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.140015,82.179993 L295.740021,84.519989 L283.980011,94.779999 L288.540009,79.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.000000,39.459991 L319.320007,38.380005 L291.600006,81.220001 L293.279999,82.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.779999,86.319977 L258.959991,86.499969 L259.079987,86.559967 C260.003998 87.165985,260.936005 85.997986,260.459991 85.299988  L260.399994,85.119965 L260.100006,84.819977 L259.739990,84.699982 L259.500000,84.699982 L259.139984,84.819977 L258.959991,84.939972 L258.839996,85.059967 L258.720001,85.239990 L258.660004,85.419983 L258.600006,85.599976 L258.600006,85.959991 L258.660004,86.139984 L258.779999,86.319977" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.559998,85.720001 L262.200012,89.140015 L262.619995,89.679993 L262.019989,89.920013 L247.500000,95.679993 L245.820007,96.339996 L246.899994,94.899994 L256.139984,82.360016 L256.559998,81.760010 L256.919983,82.299988 L256.919983,82.899994 L247.679993,95.500000 L246.899994,94.899994 L247.139984,94.720001 L261.660004,88.959991 L262.019989,89.920013 L261.419983,89.739990 L258.779999,86.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.920013,82.299988 L259.560028,85.720001 L258.779999,86.379974 L256.140015,82.959991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.200012,86.019989 L261.840027,89.440002 L247.320007,95.199982 L256.559998,82.599976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.760010,39.699982 L319.559998,38.139984 L258.960022,84.939972 L260.160004,86.499969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="96.279999" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="96.039978" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="96.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="109.540009" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="96.040009" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.020020" y="96.279999" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="229.020020" y="96.039978" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="96.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="109.540009" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="96.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.160004" y="96.279999" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="266.160004" y="96.039978" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="96.279999" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="109.540009" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="96.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.800018" y="96.279999" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="154.800018" y="96.039978" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="96.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="109.540009" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="96.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.880005" y="96.279999" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.880005" y="96.039978" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="96.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="109.540009" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="96.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.519997" y="96.279999" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="80.519997" y="96.039978" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="96.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="109.540009" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="96.040009" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.659996" y="96.279999" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="117.659996" y="96.039978" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="96.279999" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="109.540009" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="96.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.379997" y="96.279999" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="43.379997" y="96.039978" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="96.279999" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="109.540009" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="96.040009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.200012,90.279999 L190.260010,90.459991 L190.380005,90.639984 C191.160004 91.351013,192.171997 90.742004,192.120026 89.739990  L192.059998,89.559998 L191.940002,89.380005 L191.820007,89.260010 L191.700012,89.079987 L191.340027,88.959991 L190.920013,88.959991 L190.740021,89.019989 C190.410004 89.096008,190.200012 89.420990,190.140015 89.739990  L190.140015,90.100006 L190.200012,90.279999" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M191.040009,89.919983 L192.660004,93.939972 L192.899994,94.599976 L192.240021,94.659973 L176.700012,96.159973 L174.960022,96.279968 L176.339996,95.259979 L188.700012,85.779968 L189.240021,85.359985 L189.480011,85.959991 L189.360016,86.559998 L177.000000,96.039978 L176.339996,95.259979 L176.640015,95.139984 L192.180023,93.639984 L192.240021,94.659973 L191.760010,94.299988 L190.140015,90.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.480011,85.959991 L191.040009,89.919983 L190.140015,90.279999 L188.580017,86.319977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.619995,90.099976 L192.239990,94.119965 L176.699982,95.619965 L189.059998,86.139984" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.520020,39.880005 L319.800018,38.020020 L190.740021,89.020020 L191.460022,90.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M150.119995,91.479980 L150.179993,91.659973 L150.299988,91.839966 C151.002991 92.588989,152.088013 92.079987,152.040009 91.059967  L151.920013,90.699982 L151.799988,90.519989 L151.679993,90.399994 L151.500000,90.279968 L151.320007,90.219971 L150.779999,90.219971 L150.540009,90.279968 L150.420013,90.399994 L150.299988,90.579987 L150.179993,90.699982 L150.059998,91.059967 L150.059998,91.299988 L150.119995,91.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.080017,91.239990 L152.340027,95.319977 L152.520020,95.919983 L151.800018,95.979980 L136.260010,96.279999 L134.460022,96.279999 L135.960022,95.319977 L148.980011,86.799988 L149.520020,86.440002 L149.760010,87.099976 L149.520020,87.639984 L136.500000,96.160004 L135.960022,95.319977 L136.260010,95.259979 L151.860016,94.959991 L151.800018,95.979980 L151.320007,95.619995 L150.059998,91.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M149.760010,87.099976 L151.080017,91.239990 L150.059998,91.539978 L148.739990,87.399963" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M150.600006,91.359985 L151.859985,95.439972 L136.260010,95.739990 L149.279999,87.219971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.460022,39.880005 L319.860016,37.959991 L150.780029,90.220001 L151.380005,92.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.519997,92.199982 L116.639992,92.379974 L116.699989,92.499969 C117.150993 93.274994,118.599998 92.925995,118.499992 91.839996  L118.499992,91.659973 L118.379997,91.479980 L118.320000,91.299988 L118.139992,91.179993 L118.019997,91.059967 L117.659996,90.939972 L117.239998,90.939972 C116.946999 90.986969,116.626991 91.306976,116.579994 91.599976  L116.519997,91.779968 L116.519997,92.199982" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M117.480003,91.899994 L118.620003,96.100006 L118.739998,96.759979 L118.080009,96.699982 L102.480003,96.399994 L100.739998,96.339996 L102.239998,95.440002 L115.620003,87.459991 L116.220009,87.100006 L116.400002,87.759979 L116.159996,88.299988 L102.780006,96.279999 L102.239998,95.440002 L102.540001,95.380005 L118.140007,95.739990 L118.080009,96.699982 L117.599998,96.339996 L116.459999,92.139984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.400002,87.759979 L117.480003,91.899994 L116.459999,92.139984 L115.379997,87.999969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M117.000008,92.019989 L118.140007,96.220001 L102.540001,95.859985 L115.920006,87.879974" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.400024,39.880005 L319.920013,37.959991 L117.240013,90.940002 L117.720024,92.860016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.200005,92.799988 L76.320000,93.159973 L76.500008,93.279999 L76.620003,93.399994 L76.800011,93.519989 L76.980003,93.519989 L77.160011,93.579987 L77.400002,93.519989 L77.760002,93.399994 L77.879997,93.279999 L78.120003,92.919983 L78.120003,92.739990 L78.180000,92.559998 L78.120003,92.379974 L78.060005,92.139984 L78.000008,91.959991 L77.879997,91.839996 L77.700005,91.720001 L77.160011,91.539978 L76.920006,91.599976 L76.560005,91.720001 L76.440010,91.899994 L76.320000,92.019989 L76.140007,92.559998 L76.200005,92.799988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M77.159996,92.559998 L78.059990,96.760010 L78.120003,97.419983 L77.519997,97.359985 L61.980003,96.399994 L60.239998,96.339996 L61.739998,95.500000 L75.419991,88.059998 L76.019997,87.760010 L76.199989,88.359985 L75.959999,88.899994 L62.279991,96.339996 L61.739998,95.500000 L62.040001,95.440002 L77.579994,96.399994 L77.519997,97.359985 L77.040001,97.000000 L76.139992,92.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.200005,88.359985 L77.160011,92.559998 L76.140007,92.799988 L75.180000,88.599976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.680000,92.679993 L77.579994,96.880005 L62.040001,95.919983 L75.719994,88.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.400024,39.880005 L319.980011,37.959991 L76.980019,91.600006 L77.400017,93.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="62.460472" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="56.939995" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="136.679962" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="285.179962" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="279.720001" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="247.979980" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="242.520020" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="316.800018" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="319.320007" y="33.940002" textLength="4.170000" font-size="8px">0</text>
<text x="265.080017" y="35.559998" textLength="6.247500" font-size="8px">m</text>
<text x="39.118492" y="104.859985" textLength="4.582500" font-size="8px">T</text>
<text x="210.960480" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="94.019997" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="275.458527" y="35.559998" textLength="4.170000" font-size="8px">2</text>
<text x="168.300018" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="23.700005" y="104.859985" textLength="5.415000" font-size="8px">D</text>
<text x="34.078499" y="104.859985" textLength="5.002500" font-size="8px">S</text>
<text x="29.095497" y="104.859985" textLength="5.002500" font-size="8px">E</text>
<text x="314.339996" y="33.940002" textLength="5.002500" font-size="8px">X</text>
<text x="99.479942" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="322.320496" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="205.440002" y="106.479980" textLength="5.530430" font-size="8px">X</text>
<text x="173.820496" y="106.479980" textLength="4.610074" font-size="8px">0</text>
<text x="271.308014" y="35.559998" textLength="4.170000" font-size="8px">3</text>
<text x="131.220001" y="106.479980" textLength="5.530430" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-1.  VBROADCASTSS Operation (VEX.256 encoded version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.480042 161.400085">
<rect x="0.000000" y="10.000000" width="0.480000" height="113.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="113.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520004" width="396.480011" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="123.099998" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.260010,89.260010 L223.380005,89.440010 L223.500000,89.560013 C224.249023 90.167007,225.376007 89.500008,225.119995 88.540009  L225.059998,88.360008 L224.940002,88.180008 C224.302002 87.407013,223.061005 87.900009,223.140015 88.900009  L223.260010,89.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.100006,88.780006 L226.080017,92.620003 L226.380005,93.220009 L225.720001,93.340004 L210.420013,96.400009 L208.679993,96.760010 L210.000000,95.560005 L221.399994,84.820007 L221.880005,84.400009 L222.179993,84.940002 L222.059998,85.540009 L210.660004,96.280006 L210.000000,95.560005 L210.240021,95.440002 L225.540009,92.380005 L225.720001,93.340004 L225.179993,93.100006 L223.200012,89.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.180023,84.940002 L224.100037,88.779999 L223.200012,89.260002 L221.280029,85.419998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.680023,89.020004 L225.660034,92.860001 L210.360016,95.920006 L221.760010,85.180008" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.640015,40.240005 L319.740021,38.500000 L223.740021,87.940002 L224.640015,89.680008" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="25.840012" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="25.600006" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="25.839996" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="39.100006" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="25.600006" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.279999,80.440002 L320.519989,80.380005 L320.880005,80.260010 L321.119995,80.020004 L321.239990,79.839996 L321.299988,79.660004 L321.299988,79.240005 C321.165985 78.850998,321.170990 78.643997,320.700012 78.520004  L320.339996,78.400009 L320.100006,78.460007 C319.151001 78.611008,319.032990 79.992004,319.920013 80.320007  L320.279999,80.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,79.420013 L324.600006,79.480011 L325.260010,79.540009 L325.079987,80.140015 L320.639984,95.080017 L320.160004,96.760010 L319.679993,95.080017 L315.540009,80.080017 L315.359985,79.420013 L316.019989,79.420013 L316.500000,79.780014 L320.639984,94.780014 L319.679993,95.080017 L319.679993,94.780014 L324.119995,79.840012 L325.079987,80.140015 L324.600006,80.500015 L320.339996,80.440018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.020020" y="79.419998" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.339996,79.900009 L324.600006,79.960007 L320.160004,94.900009 L316.019989,79.900009" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.720001,39.340012 L319.739990,39.340012 L319.380005,79.420013 L321.360016,79.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.900024,83.020004 L292.080017,83.139999 L292.260010,83.199997 L292.620026,83.199997 L292.800018,83.139999 L293.160034,82.900009 L293.280029,82.720001 L293.340027,82.540009 C293.471039 82.250000,293.396027 81.921005,293.280029 81.639999  L292.980011,81.340012 L292.800018,81.279999 C291.900024 80.902008,290.990021 81.994003,291.600037 82.779999  L291.720032,82.900009 L291.900024,83.020004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.380005,82.180008 L295.980011,84.520004 L296.520020,84.940002 L296.040009,85.360001 L284.279999,95.620010 L282.959991,96.760010 L283.500000,95.080009 L288.059998,80.140015 L288.239990,79.480011 L288.779999,79.840012 L289.020020,80.440002 L284.459991,95.380005 L283.500000,95.080009 L283.619995,94.840012 L295.380005,84.580002 L296.040009,85.360001 L295.440002,85.420013 L291.839996,83.080002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.779999,79.840012 L292.380005,82.180008 L291.839996,83.080017 L288.239990,80.740005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.140015,82.600006 L295.740021,84.940002 L283.980011,95.200005 L288.540009,80.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.000000,39.880005 L319.320007,38.800003 L291.600006,81.639999 L293.279999,82.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.779999,86.740005 L259.079987,87.040009 L259.440002,87.160004 L259.679993,87.160004 L260.040009,87.040009 L260.220001,86.920006 L260.339996,86.800003 C260.542999 86.548004,260.609009 86.216003,260.579987 85.900009  L260.459991,85.720001 L260.399994,85.540009 L260.220001,85.360001 C259.384003 84.788010,258.502991 85.391006,258.600006 86.380005  L258.660004,86.560013 L258.779999,86.740005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.559998,86.139999 L262.200012,89.559998 L262.619995,90.099998 L262.019989,90.339996 L247.500000,96.099998 L245.820007,96.760002 L246.899994,95.320000 L256.139984,82.839996 L256.559998,82.240005 L256.919983,82.779999 L256.919983,83.380005 L247.679993,95.919998 L246.899994,95.320000 L247.139984,95.139999 L261.660004,89.379997 L262.019989,90.339996 L261.419983,90.159996 L258.779999,86.800003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.920013,82.779999 L259.560028,86.139999 L258.779999,86.799995 L256.140015,83.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.200012,86.440002 L261.840027,89.860001 L247.320007,95.620003 L256.559998,83.080002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.760010,40.120010 L319.559998,38.560013 L258.960022,85.360016 L260.160004,86.920013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.300018" y="96.700005" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.300018" y="96.459991" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.140015" y="96.700005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="109.959991" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="96.460007" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.020020" y="96.700005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="229.020020" y="96.459991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="96.700005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="109.959991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="96.460007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.160004" y="96.700005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="266.160004" y="96.459991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.059998" y="96.700005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="109.959991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.920013" y="96.460007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.800018" y="96.700005" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="154.800018" y="96.459991" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="96.700005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="109.959991" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="96.460007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.880005" y="96.700005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.880005" y="96.459991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.779999" y="96.700005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="109.959991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640015" y="96.460007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.519997" y="96.700005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="80.519997" y="96.459991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="96.700005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="109.959991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="96.460007" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.659996" y="96.700005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="117.659996" y="96.459991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.559998" y="96.700005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="109.959991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.420006" y="96.460007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.379997" y="96.700005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="43.379997" y="96.459991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.280006" y="96.700005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="109.959991" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="43.140007" y="96.460007" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="94.019997" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="168.300018" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="247.979980" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="271.308014" y="35.980011" textLength="4.170000" font-size="8px">3</text>
<text x="265.080017" y="35.980011" textLength="6.247500" font-size="8px">m</text>
<text x="39.118492" y="105.280006" textLength="4.582500" font-size="8px">T</text>
<text x="23.700005" y="105.280006" textLength="5.415000" font-size="8px">D</text>
<text x="131.220001" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="56.939995" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="314.339996" y="34.360001" textLength="5.002500" font-size="8px">X</text>
<text x="34.078499" y="105.280006" textLength="5.002500" font-size="8px">S</text>
<text x="275.458527" y="35.980011" textLength="4.170000" font-size="8px">2</text>
<text x="29.095497" y="105.280006" textLength="5.002500" font-size="8px">E</text>
<text x="322.320496" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="285.179962" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="205.440002" y="106.900009" textLength="5.530430" font-size="8px">X</text>
<text x="279.720001" y="106.900009" textLength="5.530430" font-size="8px">X</text>
<text x="242.520020" y="106.900009" textLength="5.530430" font-size="8px">X</text>
<text x="210.960480" y="106.900009" textLength="4.610074" font-size="8px">0</text>
<text x="319.320007" y="34.360001" textLength="4.170000" font-size="8px">0</text>
<text x="316.800018" y="106.900009" textLength="5.530430" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-2.  VBROADCASTSS Operation (VEX.128-bit version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.539978 204.599976">
<rect x="0.000000" y="10.000000" width="0.480000" height="107.459999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="107.459999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="117.459961" width="396.540009" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.720016,85.540039 L237.840012,85.720032 L238.020004,85.780029 C238.770004 86.347046,239.795029 85.354065,239.400009 84.520020  L239.280014,84.340027 L239.160019,84.160034 C238.452011 83.524048,237.215012 84.274048,237.540024 85.180054  L237.600021,85.360046 L237.720016,85.540039" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.440018,84.940002 L241.080032,88.359985 L241.500015,88.900024 L240.900009,89.140015 L226.380020,94.900024 L224.700027,95.559998 L225.780014,94.119995 L235.020004,81.580017 L235.440018,80.979980 L235.800003,81.520020 L235.800003,82.119995 L226.560013,94.720032 L225.780014,94.119995 L226.020004,93.940002 L240.540024,88.179993 L240.900009,89.140015 L240.300003,88.960022 L237.660019,85.599976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.800003,81.520020 L238.440018,84.940002 L237.659988,85.600037 L235.020004,82.179993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.080002,85.239990 L240.720016,88.659973 L226.199997,94.419983 L235.439987,81.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.640015,38.919983 L298.440002,37.359985 L237.900009,84.159973 L239.099991,85.719971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.900024" y="24.640015" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="261.900024" y="24.400024" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.940002" y="24.640015" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.659973" y="37.900024" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.659973" y="24.400024" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.039978,79.239990 L299.219971,79.179993 L299.460022,79.119995 C300.294983 78.781006,300.195007 77.356018,299.219971 77.260010  L299.039978,77.200012 L298.500000,77.380005 L298.320007,77.500000 L298.200012,77.679993 L298.140015,77.799988 L298.080017,78.039978 L298.020020,78.219971 L298.200012,78.760010 L298.320007,78.940002 L298.500000,79.059998 L299.039978,79.239990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.039978,78.220032 L304.020020,78.220032 L303.839966,78.880005 L299.520020,93.880005 L299.039978,95.560059 L298.559998,93.880005 L294.239990,78.880005 L294.059998,78.220032 L294.719971,78.220032 L295.200012,78.580017 L299.520020,93.580017 L298.559998,93.880005 L298.559998,93.580017 L302.880005,78.580017 L303.839966,78.880005 L303.359985,79.240051 L299.039978,79.240051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.720032" y="78.219971" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.039978,78.700012 L303.359985,78.700012 L299.039978,93.700012 L294.719971,78.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.080017" y="38.140015" width="1.980000" height="40.080002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.720016,89.619995 L165.960007,89.979980 C166.547012 90.729004,167.897018 90.026001,167.640030 89.140015  L167.640030,88.900024 L167.520004,88.719971 L167.400009,88.599976 L167.220016,88.479980 L167.100021,88.359985 L166.920029,88.299988 L166.500015,88.299988 L166.320023,88.359985 C165.849014 88.484009,165.854019 88.690979,165.720016 89.080017  L165.660019,89.260010 L165.720016,89.440002 L165.720016,89.619995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.620010,89.260010 L168.180008,93.280029 L168.360001,93.940002 L167.760025,94.000000 L152.220016,95.380005 L150.480011,95.500000 L151.860016,94.479980 L164.280014,85.119995 L164.880020,84.700012 L165.060013,85.299988 L164.940018,85.900024 L152.520004,95.260010 L151.860016,94.479980 L152.160004,94.359985 L167.699997,92.979980 L167.760025,94.000000 L167.280014,93.640015 L165.720016,89.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.060013,85.299988 L166.620010,89.260010 L165.720016,89.619995 L164.160019,85.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.199997,89.440002 L167.759995,93.460022 L152.220001,94.840027 L164.639999,85.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.400024,39.100037 L298.679993,37.240051 L166.320023,88.360046 L167.039993,90.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.740005,91.479980 L88.800003,91.719971 L88.860001,91.839966 C89.464005 92.652954,90.676010 92.239990,90.660004 91.239990  L90.660004,91.000000 L90.600006,90.820007 C90.131012 90.005005,88.853012 90.085999,88.680008 91.119995  L88.680008,91.299988 L88.740005,91.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.699997,91.239990 L90.720001,95.440002 L90.779999,96.099976 L90.179993,96.039978 L74.580002,95.559998 L72.839996,95.559998 L74.339996,94.659973 L87.839996,86.799988 L88.440002,86.440002 L88.619995,87.099976 L88.379990,87.640015 L74.879990,95.500000 L74.339996,94.659973 L74.639999,94.599976 L90.239990,95.080017 L90.179993,96.039978 L89.699997,95.679993 L88.679993,91.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.620010,87.100037 L89.700012,91.240051 L88.680008,91.480042 L87.600006,87.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.220001,91.359985 L90.240005,95.559998 L74.639999,95.079956 L88.139999,87.219971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.280029,39.100037 L298.799988,37.180054 L89.460007,90.280029 L89.940018,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.900024" y="95.500000" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="261.900024" y="95.260010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.940002" y="95.500000" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.659973" y="108.760010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.659973" y="95.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.680008" y="95.500000" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="187.680008" y="95.260010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.659973" y="95.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.440018" y="108.760010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.440018" y="95.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.400009" y="95.500000" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="113.400009" y="95.260010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.440018" y="95.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.160004" y="108.760010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.160004" y="95.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="39.180008" y="95.500000" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="39.180008" y="95.260010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.160004" y="95.500000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="38.940002" y="108.760010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="38.940002" y="95.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="74.520004" y="105.700012" textLength="4.170000" font-size="8px">0</text>
<text x="143.760010" y="105.700012" textLength="5.002500" font-size="8px">X</text>
<text x="218.039993" y="105.700012" textLength="5.002500" font-size="8px">X</text>
<text x="292.320007" y="105.700012" textLength="5.002500" font-size="8px">X</text>
<text x="292.320007" y="34.780029" textLength="5.002500" font-size="8px">X</text>
<text x="235.258499" y="33.160034" textLength="4.170000" font-size="8px">4</text>
<text x="224.819992" y="33.160034" textLength="6.247500" font-size="8px">m</text>
<text x="34.918488" y="104.080017" textLength="4.582500" font-size="8px">T</text>
<text x="19.500000" y="104.080017" textLength="5.415000" font-size="8px">D</text>
<text x="24.895493" y="104.080017" textLength="5.002500" font-size="8px">E</text>
<text x="29.935486" y="104.080017" textLength="5.002500" font-size="8px">S</text>
<text x="223.020004" y="105.700012" textLength="4.170000" font-size="8px">0</text>
<text x="148.800003" y="105.700012" textLength="4.170000" font-size="8px">0</text>
<text x="231.077988" y="33.160034" textLength="4.170000" font-size="8px">6</text>
<text x="297.359985" y="105.700012" textLength="4.170000" font-size="8px">0</text>
<text x="69.540009" y="105.700012" textLength="5.002500" font-size="8px">X</text>
<text x="297.359985" y="34.780029" textLength="4.170000" font-size="8px">0</text>
</svg>
<figcaption>Figure 5-3.  VBROADCASTSD Operation (VEX.256-bit version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.539978 159.600311">
<rect x="0.000000" y="10.000000" width="0.480000" height="110.459999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="110.459999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519958" width="396.540009" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="120.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,81.460022 L258.839966,81.460022 L259.080017,81.400024 L259.200012,81.280029 L259.380005,81.160034 L259.500000,81.040009 L259.619995,80.680023 L259.679993,80.500031 L259.619995,80.260010 L259.559998,80.080017 L259.500000,79.900024 L259.380005,79.780029 L259.200012,79.660034 L259.080017,79.540009 L258.839966,79.480011 L258.479980,79.480011 C257.487976 79.741028,257.364990 80.979034,258.299988 81.400024  L258.479980,81.460022 L258.659973,81.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,80.500000 L263.640015,80.500000 L263.459961,81.160004 L259.140015,96.160004 L258.659973,97.839996 L258.179993,96.160004 L253.860001,81.160004 L253.679977,80.500000 L254.339981,80.500000 L254.819992,80.859985 L259.140015,95.859985 L258.179993,96.160004 L258.179993,95.859985 L262.500000,80.859985 L263.459961,81.160004 L262.979980,81.519989 L258.659973,81.519989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.340012" y="80.500031" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,80.980011 L262.979980,80.980011 L258.659973,95.980011 L254.339981,80.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.700012" y="40.419983" width="1.980000" height="40.080002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.159988" y="26.919983" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.159988" y="26.680054" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.419983" y="26.920044" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="40.180054" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="26.679993" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.339996,91.899994 L125.580002,92.259979 C126.272995 92.911987,127.511993 92.346985,127.259995 91.359985  L127.259995,91.179993 L127.019989,90.820007 L126.899994,90.699982 L126.360001,90.519989 L126.119995,90.579987 L125.940002,90.579987 C125.432999 90.944000,125.515991 90.740997,125.339996 91.299988  L125.279999,91.479980 L125.339996,91.720001 L125.339996,91.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.240005,91.540009 L127.800003,95.559998 L127.980011,96.220001 L127.380005,96.279999 L111.840012,97.660004 L110.100006,97.779999 L111.480011,96.760010 L123.900009,87.339996 L124.500000,86.920013 L124.680008,87.520020 L124.560013,88.119995 L112.139999,97.540009 L111.480011,96.760010 L111.779999,96.640015 L127.320007,95.260010 L127.380005,96.279999 L126.900009,95.920013 L125.340012,91.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M124.680008,87.520020 L126.240005,91.540009 L125.340012,91.900024 L123.780014,87.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.820007,91.720001 L127.380005,95.739990 L111.840012,97.119995 L124.260010,87.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.020020,41.380005 L258.299988,39.520020 L125.940002,90.640015 L126.660004,92.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.159988" y="97.779999" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.159988" y="97.540039" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.419983" y="97.780029" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="111.040009" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="97.540009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.660004" y="97.779999" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="42.660004" y="97.540039" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="97.780029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.419998" y="111.040009" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.419998" y="97.540009" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="108.419998" y="107.920013" textLength="4.170000" font-size="8px">0</text>
<text x="251.940018" y="107.920013" textLength="5.002500" font-size="8px">X</text>
<text x="256.920044" y="37.059998" textLength="4.170000" font-size="8px">0</text>
<text x="177.916519" y="35.440002" textLength="4.170000" font-size="8px">2</text>
<text x="173.757004" y="35.440002" textLength="4.170000" font-size="8px">1</text>
<text x="38.398499" y="106.300018" textLength="4.582500" font-size="8px">T</text>
<text x="33.358505" y="106.300018" textLength="5.002500" font-size="8px">S</text>
<text x="167.520004" y="35.440002" textLength="6.247500" font-size="8px">m</text>
<text x="256.920044" y="107.920013" textLength="4.170000" font-size="8px">0</text>
<text x="28.375504" y="106.300018" textLength="5.002500" font-size="8px">E</text>
<text x="22.980003" y="106.300018" textLength="5.415000" font-size="8px">D</text>
<text x="103.440002" y="107.920013" textLength="5.002500" font-size="8px">X</text>
<text x="251.940018" y="37.059998" textLength="5.002500" font-size="8px">X</text>
<text x="182.076004" y="35.440002" textLength="4.170000" font-size="8px">8</text>
</svg>
<figcaption>Figure 5-4.  VBROADCASTF128 Operation (VEX.256-bit version)
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.539978 161.220154">
<rect x="0.000000" y="10.000000" width="0.480000" height="113.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="113.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="396.540009" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="123.159973" width="396.540009" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,82.119995 L258.839966,82.119995 L259.080017,82.059998 L259.200012,81.940002 L259.380005,81.820007 L259.500000,81.699982 L259.559998,81.519989 L259.619995,81.339996 L259.679993,81.160004 L259.619995,80.919983 L259.500000,80.559998 L259.380005,80.440002 L259.200012,80.320007 L259.080017,80.199982 L258.839966,80.139984 L258.479980,80.139984 C257.487976 80.401001,257.364990 81.639008,258.299988 82.059998  L258.479980,82.119995 L258.659973,82.119995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,81.160004 L263.640015,81.160004 L263.459961,81.820007 L259.140015,96.820007 L258.659973,98.500000 L258.179993,96.820007 L253.860001,81.820007 L253.679977,81.160004 L254.339981,81.160004 L254.819992,81.519989 L259.140015,96.519989 L258.179993,96.820007 L258.179993,96.519989 L262.500000,81.519989 L263.459961,81.820007 L262.979980,82.179993 L258.659973,82.179993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.340012" y="81.160004" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,81.639984 L262.979980,81.639984 L258.659973,96.639984 L254.339981,81.639984" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.700012" y="41.079987" width="1.980000" height="40.080002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.159988" y="27.579987" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.159988" y="27.339996" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.419983" y="27.580017" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="40.839996" width="148.740005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="27.339996" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.339996,92.559998 L125.580002,92.919983 C126.291992 93.606995,127.500992 92.996002,127.259995 92.019989  L127.259995,91.839996 L127.139999,91.660004 L127.019989,91.540009 L126.899994,91.359985 L126.360001,91.179993 L126.119995,91.239990 L125.940002,91.299988 C125.560989 91.376984,125.442993 91.626984,125.339996 91.959991  L125.279999,92.200012 L125.339996,92.380005 L125.339996,92.559998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.240005,92.199982 L127.800003,96.219971 L127.980011,96.879974 L127.380005,96.939972 L111.840012,98.319977 L110.100006,98.439972 L111.480011,97.419983 L123.900009,87.999969 L124.500000,87.579987 L124.680008,88.179993 L124.560013,88.779968 L112.139999,98.199982 L111.480011,97.419983 L111.779999,97.299988 L127.320007,95.919983 L127.380005,96.939972 L126.900009,96.579987 L125.340012,92.559967" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M124.680008,88.179993 L126.240005,92.199982 L125.340012,92.559998 L123.780014,88.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.820007,92.380005 L127.380005,96.399994 L111.840012,97.779999 L124.260010,88.360016" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.020020,42.040009 L258.299988,40.180023 L125.940002,91.300018 L126.660004,93.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.159988" y="98.440002" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.159988" y="98.200012" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.419983" y="98.440002" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="111.700012" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="98.200012" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.660004" y="98.440002" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="42.660004" y="98.200012" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.919998" y="98.440002" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.419998" y="111.700012" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="42.419998" y="98.200012" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="103.440002" y="108.579987" textLength="5.002500" font-size="8px">X</text>
<text x="256.920044" y="37.720001" textLength="4.170000" font-size="8px">0</text>
<text x="173.757004" y="36.100006" textLength="4.170000" font-size="8px">2</text>
<text x="28.375504" y="106.959991" textLength="5.002500" font-size="8px">E</text>
<text x="22.980003" y="106.959991" textLength="5.415000" font-size="8px">D</text>
<text x="167.520004" y="36.100006" textLength="6.247500" font-size="8px">m</text>
<text x="108.419998" y="108.579987" textLength="4.170000" font-size="8px">0</text>
<text x="256.920044" y="108.579987" textLength="4.170000" font-size="8px">0</text>
<text x="182.076004" y="36.100006" textLength="4.170000" font-size="8px">6</text>
<text x="33.358505" y="106.959991" textLength="5.002500" font-size="8px">S</text>
<text x="251.940018" y="108.579987" textLength="5.002500" font-size="8px">X</text>
<text x="38.398499" y="106.959991" textLength="4.582500" font-size="8px">T</text>
<text x="177.916519" y="36.100006" textLength="4.170000" font-size="8px">5</text>
<text x="251.940018" y="37.720001" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 5-5.  VBROADCASTF64X4 Operation (512-bit version with writemask all 1s)
</figcaption></figure>
```

### Operation
#### VBROADCASTSS (128 bit version VEX and legacy)
```info-verb
temp <-  SRC[31:0]
DEST[31:0] <-  temp
DEST[63:32] <-  temp
DEST[95:64] <-  temp
DEST[127:96] <-  temp
DEST[MAX_VL-1:128] <-  0
```
#### VBROADCASTSS (VEX.256 encoded version)
```info-verb
temp <-  SRC[31:0]
DEST[31:0] <-  temp
DEST[63:32] <-  temp
DEST[95:64] <-  temp
DEST[127:96] <-  temp
DEST[159:128] <-  temp
DEST[191:160] <-  temp
DEST[223:192] <-  temp
DEST[255:224] <-  temp
DEST[MAX_VL-1:256] <-  0
```
#### VBROADCASTSS (EVEX encoded versions)
```info-verb
(KL, VL) (4, 128), (8, 256),= (16, 512)
FOR j <-  0 TO KL-1
    i <- j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[31:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VBROADCASTSD (VEX.256 encoded version)
```info-verb
temp <-  SRC[63:0]
DEST[63:0] <-  temp
DEST[127:64] <-  temp
DEST[191:128] <-  temp
DEST[255:192] <-  temp
DEST[MAX_VL-1:256] <-  0
```
#### VBROADCASTSD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <- j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC[63:0]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VBROADCASTF32x2 (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-!= j * 32
    n <-!= (j mod 2) * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[n+31:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VBROADCASTF128 (VEX.256 encoded version)
```info-verb
temp <-  SRC[127:0]
DEST[127:0] <-  temp
DEST[255:128] <-  temp
DEST[MAX_VL-1:256] <-  0
```
#### VBROADCASTF32X4 (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-!= j* 32
    n <-!= (j modulo 4) * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[n+31:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VBROADCASTF64X2 (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    n <- (j modulo 2) * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC[n+63:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] = 0
                FI
    FI;
ENDFOR;
```
#### VBROADCASTF32X8 (EVEX.U1.512 encoded version)
```info-verb
FOR j <-  0 TO 15
    i <-  j * 32
    n <- (j modulo 8) * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[n+31:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VBROADCASTF64X4 (EVEX.512 encoded version)
```info-verb
FOR j <-  0 TO 7
    i <-  j * 64
    n <-!= (j modulo 4) * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC[n+63:n]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VBROADCASTF32x2 __m512 _mm512_broadcast_f32x2( __m128 a);
VBROADCASTF32x2 __m512 _mm512_mask_broadcast_f32x2(__m512 s, __mmask16 k, __m128 a);
VBROADCASTF32x2 __m512 _mm512_maskz_broadcast_f32x2( __mmask16 k, __m128 a);
VBROADCASTF32x2 __m256 _mm256_broadcast_f32x2( __m128 a);
VBROADCASTF32x2 __m256 _mm256_mask_broadcast_f32x2(__m256 s, __mmask8 k, __m128 a);
VBROADCASTF32x2 __m256 _mm256_maskz_broadcast_f32x2( __mmask8 k, __m128 a);
VBROADCASTF32x4 __m512 _mm512_broadcast_f32x4( __m128 a);
VBROADCASTF32x4 __m512 _mm512_mask_broadcast_f32x4(__m512 s, __mmask16 k, __m128 a);
VBROADCASTF32x4 __m512 _mm512_maskz_broadcast_f32x4( __mmask16 k, __m128 a);
VBROADCASTF32x4 __m256 _mm256_broadcast_f32x4( __m128 a);
VBROADCASTF32x4 __m256 _mm256_mask_broadcast_f32x4(__m256 s, __mmask8 k, __m128 a);
VBROADCASTF32x4 __m256 _mm256_maskz_broadcast_f32x4( __mmask8 k, __m128 a);
VBROADCASTF32x8 __m512 _mm512_broadcast_f32x8( __m256 a);
VBROADCASTF32x8 __m512 _mm512_mask_broadcast_f32x8(__m512 s, __mmask16 k, __m256 a);
VBROADCASTF32x8 __m512 _mm512_maskz_broadcast_f32x8( __mmask16 k, __m256 a);
VBROADCASTF64x2 __m512d _mm512_broadcast_f64x2( __m128d a);
VBROADCASTF64x2 __m512d _mm512_mask_broadcast_f64x2(__m512d s, __mmask8 k, __m128d a);
VBROADCASTF64x2 __m512d _mm512_maskz_broadcast_f64x2( __mmask8 k, __m128d a);
VBROADCASTF64x2 __m256d _mm256_broadcast_f64x2( __m128d a);
VBROADCASTF64x2 __m256d _mm256_mask_broadcast_f64x2(__m256d s, __mmask8 k, __m128d a);
VBROADCASTF64x2 __m256d _mm256_maskz_broadcast_f64x2( __mmask8 k, __m128d a);
VBROADCASTF64x4 __m512d _mm512_broadcast_f64x4( __m256d a);
VBROADCASTF64x4 __m512d _mm512_mask_broadcast_f64x4(__m512d s, __mmask8 k, __m256d a);
VBROADCASTF64x4 __m512d _mm512_maskz_broadcast_f64x4( __mmask8 k, __m256d a);
VBROADCASTSD __m512d _mm512_broadcastsd_pd( __m128d a); 
VBROADCASTSD __m512d _mm512_mask_broadcastsd_pd(__m512d s, __mmask8 k, __m128d a); 
VBROADCASTSD __m512d _mm512_maskz_broadcastsd_pd(__mmask8 k, __m128d a); 
VBROADCASTSD __m256d _mm256_broadcastsd_pd(__m128d a);
VBROADCASTSD __m256d _mm256_mask_broadcastsd_pd(__m256d s, __mmask8 k, __m128d a);
VBROADCASTSD __m256d _mm256_maskz_broadcastsd_pd( __mmask8 k, __m128d a);
VBROADCASTSD __m256d _mm256_broadcast_sd(double *a);
VBROADCASTSS __m512 _mm512_broadcastss_ps( __m128 a); 
VBROADCASTSS __m512 _mm512_mask_broadcastss_ps(__m512 s, __mmask16 k, __m128 a); 
VBROADCASTSS __m512 _mm512_maskz_broadcastss_ps( __mmask16 k, __m128 a); 
VBROADCASTSS __m256 _mm256_broadcastss_ps(__m128 a);
VBROADCASTSS __m256 _mm256_mask_broadcast_ss(__m256 s, __mmask8 k, __m128 a);
VBROADCASTSS __m256 _mm256_maskz_broadcast_ss( __mmask8 k, __m128 a);
VBROADCASTSS __m128 _mm_broadcastss_ps(__m128 a);
VBROADCASTSS __m128 _mm_mask_broadcast_ss(__m128 s, __mmask8 k, __m128 a);
VBROADCASTSS __m128 _mm_maskz_broadcast_ss( __mmask8 k, __m128 a);
VBROADCASTSS __m128 _mm_broadcast_ss(float *a);
VBROADCASTSS __m256 _mm256_broadcast_ss(float *a);
VBROADCASTF128 __m256 _mm256_broadcast_ps(__m128 * a);
VBROADCASTF128 __m256d _mm256_broadcast_pd(__m128d * a);
```
### Exceptions


VEX-encoded instructions, see Exceptions Type 6; 

EVEX-encoded instructions, see Exceptions Type E6.

#UD If VEX.L = 0 for VBROADCASTSD or VBROADCASTF128.

                              If EVEX.L'L = 0 for VBROADCASTSD/VBROADCASTF32X2/VBROADCASTF32X4/VBROADCASTF64X2.

                              If EVEX.L'L < 10b for VBROADCASTF32X8/VBROADCASTF64X4.

