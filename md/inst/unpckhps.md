### UNPCKHPS--Unpack and Interleave High Packed Single-Precision Floating-Point Values


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 15 /rUNPCKHPS xmm1, xmm2/m128|RM|V/V|SSE|Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm1 and xmm2/m128.|
|VEX.NDS.128.0F.WIG 15 /rVUNPCKHPS xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm2 and xmm3/m128.|
|VEX.NDS.256.0F.WIG 15 /rVUNPCKHPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Unpacks and Interleaves single-precision floating-point values from high quadwords of ymm2 and ymm3/m256.|
|EVEX.NDS.128.0F.W0 15 /rVUNPCKHPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VLAVX512F|Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm2 and xmm3/m128/m32bcst and write result to xmm1 subject to writemask k1.|
|EVEX.NDS.256.0F.W0 15 /rVUNPCKHPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VLAVX512F|Unpacks and Interleaves single-precision floating-point values from high quadwords of ymm2 and ymm3/m256/m32bcst and write result to ymm1 subject to writemask k1.|
|EVEX.NDS.512.0F.W0 15 /rVUNPCKHPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Unpacks and Interleaves single-precision floating-point values from high quadwords of zmm2 and zmm3/m512/m32bcst and write result to zmm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs an interleaved unpack of the high single-precision floating-point values from the first source operand and the second source operand. 

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified. When unpacking from a memory operand, an implementation may fetch only the appropriate 64 bits; however, alignment to 16-byte boundary and normal segment checking will still be enforced.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

VEX.256 encoded version: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers.

```embed
<figure>
<svg viewBox="0 0 396.480042 252.780029">
<rect x="0.000000" y="10.000000" width="0.480000" height="155.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="155.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="165.640015" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M320.400024,101.859985 L320.520020,101.739990 L320.580017,101.500000 L320.580017,100.959961 L320.340027,100.599976 L320.220032,100.479980 L320.040039,100.359985 L319.860016,100.299988 L319.500031,100.299988 L319.260010,100.359985 L319.140015,100.419983 L318.960022,100.539978 L318.840027,100.659973 L318.720032,100.839966 C318.223022 101.818970,319.321014 102.554993,320.100037 102.159973  L320.280029,102.039978 L320.400024,101.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M319.619995,101.260010 L322.260010,97.840027 L322.679993,97.359985 L323.040009,97.840027 L332.339996,110.380005 L333.419983,111.820007 L331.739990,111.160034 L317.279999,105.460022 L316.619995,105.220032 L317.040009,104.679993 L317.579987,104.500000 L332.100006,110.200012 L331.739990,111.160034 L331.500000,110.979980 L322.260010,98.440002 L323.040009,97.840027 L323.040009,98.440002 L320.399994,101.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M317.040009,104.679993 L319.619995,101.260010 L320.399994,101.859985 L317.820007,105.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M319.980011,101.559998 L322.620026,98.140015 L331.920013,110.679993 L317.400024,104.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.100006,56.979980 L261.899994,58.539978 L319.020020,102.039978 L320.220001,100.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M286.440002,102.160034 L286.559998,101.980042 L286.619995,101.800049 C286.748016 100.788025,285.737000 100.242004,284.940002 100.840027  L284.820007,101.020020 L284.700012,101.200012 C284.382996 102.129028,285.246002 102.904053,286.140015 102.460022  L286.320007,102.340027 L286.440002,102.160034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M285.660004,101.559998 L288.179993,98.080017 L288.600006,97.599976 L288.959991,98.080017 L298.559998,110.380005 L299.640015,111.760010 L298.019989,111.159973 L283.380005,105.820007 L282.720001,105.580017 L283.140015,105.039978 L283.679993,104.859985 L298.320007,110.200012 L298.019989,111.159973 L297.779999,110.979980 L288.179993,98.679993 L288.959991,98.080017 L288.959991,98.679993 L286.440002,102.159973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.140015,105.040039 L285.660004,101.560059 L286.440002,102.160034 L283.920013,105.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M286.020020,101.859985 L288.540009,98.380005 L298.140015,110.679993 L283.500031,105.339966" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.100006,83.979980 L261.959991,85.599976 L285.059998,102.399963 L286.200012,100.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.500000" y="44.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="316.500000" y="44.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="353.400024" y="44.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="57.519958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="44.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.360016" y="44.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="279.360016" y="44.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="44.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="57.519958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="44.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.220001" y="44.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="242.220001" y="44.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="44.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="57.519958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="44.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.140015" y="44.260010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.140015" y="44.020020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="44.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="57.519958" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="44.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.500000" y="71.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="316.500000" y="71.019958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="353.400024" y="71.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="84.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="71.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.360016" y="71.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="279.360016" y="71.019958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="71.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="84.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="71.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.220001" y="71.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="242.220001" y="71.019958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="71.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="84.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="71.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.140015" y="71.260010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.140015" y="71.019958" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="71.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="84.520020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="71.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.500000" y="111.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="316.500000" y="111.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="353.400024" y="111.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="125.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="111.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.940002" y="120.820007" width="4.200000" height="0.539980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.360016" y="111.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="279.360016" y="111.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.260010" y="111.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="125.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="111.520020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.220001" y="111.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="242.220001" y="111.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.119995" y="111.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="125.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="111.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.140015" y="111.760010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.140015" y="111.520020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="241.980011" y="111.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="125.020020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="111.520020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.000000" y="111.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.000000" y="111.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="111.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="125.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="111.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.860016" y="111.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="130.860016" y="111.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="111.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="125.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="111.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.720009" y="111.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="93.720009" y="111.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="111.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="125.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="111.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.640007" y="111.760010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.640007" y="111.520020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="111.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400002" y="125.020020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400002" y="111.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.000000" y="44.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.000000" y="44.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="44.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="57.519958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="44.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.860016" y="44.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="130.860016" y="44.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="44.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="57.519958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="44.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.720009" y="44.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="93.720009" y="44.020020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="44.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="57.519958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="44.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.640007" y="44.260010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.640007" y="44.020020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="44.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400002" y="57.519958" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400002" y="44.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.000000" y="71.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.000000" y="71.019958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.900024" y="71.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="84.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="71.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.860016" y="71.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="130.860016" y="71.019958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.760010" y="71.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="84.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="71.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.720009" y="71.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="93.720009" y="71.019958" width="37.380001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.619995" y="71.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="84.520020" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="71.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.640007" y="71.260010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.640007" y="71.019958" width="37.320000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.480003" y="71.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400002" y="84.520020" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400002" y="71.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.500000,97.960022 L250.619995,97.840027 L250.739990,97.660034 C251.308014 96.914001,250.516998 95.762024,249.600006 96.160034  L249.420013,96.220032 L249.239990,96.400024 C248.545990 97.151001,249.221008 98.218994,250.079987 98.080017  L250.320007,98.020020 L250.500000,97.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.960022,97.119995 L253.620026,94.839966 L254.160034,94.479980 L254.340027,95.140015 L258.660034,110.080017 L259.140015,111.760010 L257.880035,110.619995 L246.300018,100.239990 L245.760010,99.760010 L246.360016,99.400024 L246.960022,99.460022 L258.540009,109.839966 L257.880035,110.619995 L257.700012,110.320007 L253.380035,95.440002 L254.340027,95.140015 L254.160034,95.739990 L250.500031,98.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.360016,99.400024 L249.960022,97.119995 L250.500031,98.020020 L246.900024,100.300049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.200012,97.540039 L253.860016,95.260010 L258.180023,110.200012 L246.600006,99.820068" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M226.200012,57.280029 L224.520020,58.300049 L249.120026,97.660034 L250.800018,96.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.360016,95.440002 L225.600006,95.440002 L225.780029,95.380005 C226.585022 95.039001,226.601013 93.784973,225.600006 93.460022  L225.180023,93.460022 C224.185028 93.661011,224.083008 95.096985,225.000031 95.380005  L225.180023,95.440002 L225.360016,95.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.360016,94.479980 L230.340027,94.479980 L230.160004,95.139954 L225.840027,110.139954 L225.360016,111.820007 L224.880005,110.139954 L220.620026,95.139954 L220.440002,94.479980 L221.100006,94.479980 L221.580017,94.839966 L225.840027,109.839966 L224.880005,110.139954 L224.880005,109.839966 L229.200012,94.839966 L230.160004,95.139954 L229.680023,95.500000 L225.360016,95.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.100006" y="94.479980" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.360016,94.960022 L229.680023,94.960022 L225.360016,109.960022 L221.100006,94.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.400024" y="84.760010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.900024,101.859985 L172.020020,101.739990 L172.080017,101.500000 L172.080017,100.959961 L171.840027,100.599976 L171.720032,100.479980 L171.540039,100.359985 C171.234039 100.227966,170.879028 100.305969,170.580017 100.419983  L170.460022,100.539978 L170.280029,100.659973 L170.220032,100.839966 C169.723022 101.818970,170.821014 102.554993,171.600037 102.159973  L171.780029,102.039978 L171.900024,101.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.119995,101.260010 L173.760010,97.840027 L174.179993,97.359985 L174.540009,97.840027 L183.839996,110.380005 L184.919983,111.820007 L183.239990,111.160034 L168.779999,105.460022 L168.119995,105.220032 L168.540009,104.679993 L169.079987,104.500000 L183.600006,110.200012 L183.239990,111.160034 L183.000000,110.979980 L173.760010,98.440002 L174.540009,97.840027 L174.540009,98.440002 L171.899994,101.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M168.540009,104.679993 L171.119995,101.260010 L171.899994,101.859985 L169.320007,105.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.480011,101.559998 L174.120026,98.140015 L183.420013,110.679993 L168.900024,104.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M114.599998,56.979980 L113.400002,58.539978 L170.520020,102.039978 L171.720001,100.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M137.940002,102.160034 L138.059998,101.980042 L138.119995,101.800049 C138.247986 100.788025,137.237000 100.242004,136.440002 100.840027  L136.320007,101.020020 L136.199982,101.200012 C135.897003 102.139038,136.721008 102.908020,137.639984 102.460022  L137.820007,102.340027 L137.940002,102.160034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M137.160004,101.559998 L139.679993,98.080017 L140.100006,97.599976 L140.459991,98.080017 L150.059998,110.380005 L151.139984,111.760010 L149.519989,111.159973 L134.880005,105.820007 L134.220001,105.580017 L134.639984,105.039978 L135.179993,104.859985 L149.820007,110.200012 L149.519989,111.159973 L149.279999,110.979980 L139.679993,98.679993 L140.459991,98.080017 L140.459991,98.679993 L137.940002,102.159973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.640015,105.040039 L137.160004,101.560059 L137.940002,102.160034 L135.420013,105.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M137.519989,101.859985 L140.040009,98.380005 L149.639984,110.679993 L135.000000,105.339966" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M114.599998,83.979980 L113.459999,85.599976 L136.559998,102.399963 L137.700012,100.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M102.000008,97.960022 L102.120003,97.840027 L102.240013,97.660034 C102.806007 96.905029,102.024010 95.777039,101.100014 96.160034  L100.920006,96.220032 L100.740013,96.400024 L100.620003,96.520020 L100.560005,96.700012 L100.440010,96.880005 L100.440010,97.240051 L100.500008,97.420044 L100.740013,97.780029 L100.860008,97.900024 L101.040001,98.020020 L101.220009,98.080017 L101.580009,98.080017 L101.820015,98.020020 L102.000008,97.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.459999,97.119995 L105.120003,94.839966 L105.659996,94.479980 L105.840004,95.140015 L110.159996,110.080017 L110.640007,111.700012 L109.379997,110.619995 L97.739998,100.239990 L97.200005,99.760010 L97.799995,99.400024 L98.400002,99.460022 L110.040001,109.839966 L109.379997,110.619995 L109.200005,110.320007 L104.879997,95.440002 L105.840004,95.140015 L105.659996,95.739990 L101.999992,98.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M97.799995,99.400024 L101.459999,97.119995 L101.999992,98.020020 L98.339989,100.300049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.700005,97.540039 L105.360008,95.260010 L109.680000,110.200012 L98.040001,99.820068" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M77.700005,57.280029 L76.020012,58.300049 L100.620003,97.660034 L102.300011,96.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.860008,95.440002 L77.040001,95.440002 L77.280006,95.380005 C78.142006 94.991028,77.999016 93.646973,77.040001 93.460022  L76.680016,93.460022 C75.685005 93.661011,75.583015 95.096985,76.500008 95.380005  L76.680016,95.440002 L76.860008,95.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.860008,94.479980 L81.840004,94.479980 L81.660011,95.139954 L77.340004,110.139954 L76.860008,111.820007 L76.380013,110.139954 L72.060005,95.139954 L71.880013,94.479980 L72.540001,94.479980 L73.020012,94.839966 L77.340004,109.839966 L76.380013,110.139954 L76.380013,109.839966 L80.700005,94.839966 L81.660011,95.139954 L81.180016,95.500000 L76.860008,95.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="72.540001" y="94.479980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M76.860008,94.960022 L81.180016,94.960022 L76.860008,109.960022 L72.540001,94.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.900002" y="84.760010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="76.079994" y="79.780029" textLength="4.170000" font-size="8px">7</text>
<text x="113.159996" y="79.780029" textLength="4.170000" font-size="8px">6</text>
<text x="108.180000" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="150.359985" y="79.780029" textLength="4.170000" font-size="8px">5</text>
<text x="145.320007" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="76.079994" y="52.780029" textLength="4.170000" font-size="8px">7</text>
<text x="71.099998" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="108.180000" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="108.180000" y="120.280029" textLength="5.002500" font-size="8px">X</text>
<text x="150.359985" y="120.280029" textLength="4.170000" font-size="8px">6</text>
<text x="145.320007" y="120.280029" textLength="5.002500" font-size="8px">Y</text>
<text x="187.440033" y="120.280029" textLength="4.170000" font-size="8px">6</text>
<text x="182.460022" y="120.280029" textLength="5.002500" font-size="8px">X</text>
<text x="224.580017" y="120.280029" textLength="4.170000" font-size="8px">3</text>
<text x="256.680023" y="120.280029" textLength="5.002500" font-size="8px">X</text>
<text x="293.820007" y="120.280029" textLength="5.002500" font-size="8px">Y</text>
<text x="330.960022" y="120.280029" textLength="5.002500" font-size="8px">X</text>
<text x="224.580017" y="79.780029" textLength="4.170000" font-size="8px">3</text>
<text x="219.600006" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="298.860016" y="79.780029" textLength="4.170000" font-size="8px">1</text>
<text x="336.000031" y="79.780029" textLength="4.170000" font-size="8px">0</text>
<text x="330.960022" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="224.580017" y="52.780029" textLength="4.170000" font-size="8px">3</text>
<text x="256.680023" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="330.960022" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="46.798500" y="79.780029" textLength="5.415000" font-size="8px">C</text>
<text x="41.400002" y="79.780029" textLength="5.415000" font-size="8px">R</text>
<text x="52.378517" y="54.400024" textLength="4.170000" font-size="8px">1</text>
<text x="46.981514" y="54.400024" textLength="5.415000" font-size="8px">C</text>
<text x="36.600014" y="54.400024" textLength="5.002500" font-size="8px">S</text>
<text x="335.940033" y="120.280029" textLength="4.170000" font-size="8px">2</text>
<text x="46.798500" y="120.280029" textLength="5.002500" font-size="8px">S</text>
<text x="36.360008" y="120.280029" textLength="5.415000" font-size="8px">D</text>
<text x="261.660034" y="52.780029" textLength="4.170000" font-size="8px">2</text>
<text x="150.359985" y="52.780029" textLength="4.170000" font-size="8px">5</text>
<text x="52.196999" y="79.780029" textLength="4.170000" font-size="8px">2</text>
<text x="293.820007" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="36.360008" y="79.780029" textLength="5.002500" font-size="8px">S</text>
<text x="261.660034" y="120.280029" textLength="4.170000" font-size="8px">3</text>
<text x="336.000031" y="52.780029" textLength="4.170000" font-size="8px">0</text>
<text x="145.320007" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="76.079994" y="120.280029" textLength="4.170000" font-size="8px">7</text>
<text x="187.440033" y="79.780029" textLength="4.170000" font-size="8px">4</text>
<text x="182.460022" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="51.778496" y="120.280029" textLength="4.582500" font-size="8px">T</text>
<text x="256.680023" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="113.159996" y="52.780029" textLength="4.170000" font-size="8px">6</text>
<text x="187.440033" y="52.780029" textLength="4.170000" font-size="8px">4</text>
<text x="219.600006" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="293.820007" y="52.780029" textLength="5.002500" font-size="8px">X</text>
<text x="298.860016" y="52.780029" textLength="4.170000" font-size="8px">1</text>
<text x="71.099998" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="71.099998" y="120.280029" textLength="5.002500" font-size="8px">Y</text>
<text x="182.460022" y="79.780029" textLength="5.002500" font-size="8px">Y</text>
<text x="298.860016" y="120.280029" textLength="4.170000" font-size="8px">2</text>
<text x="261.660034" y="79.780029" textLength="4.170000" font-size="8px">2</text>
<text x="219.600006" y="120.280029" textLength="5.002500" font-size="8px">Y</text>
<text x="41.818504" y="120.280029" textLength="5.002500" font-size="8px">E</text>
<text x="113.159996" y="120.280029" textLength="4.170000" font-size="8px">7</text>
<text x="41.584511" y="54.400024" textLength="5.415000" font-size="8px">R</text>
</svg>
<figcaption>Figure 4-27.  VUNPCKHPS Operation
</figcaption></figure>
```


EVEX.512 encoded version: The first source operand is a ZMM register. The second source operand is a ZMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 32-bit memory location. The destina-tion operand is a ZMM register, conditionally updated using writemask k1. 

EVEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register, a 256-bit memory location, or a 256-bit vector broadcasted from a 32-bit memory location. The destina-tion operand is a YMM register, conditionally updated using writemask k1. 

EVEX.128 encoded version: The first source operand is a XMM register. The second source operand is a XMM register, a 128-bit memory location, or a 128-bit vector broadcasted from a 32-bit memory location. The destina-tion operand is a XMM register, conditionally updated using writemask k1. 


### Operation
#### VUNPCKHPS (EVEX encoded version when SRC2 is a register)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF VL >= 128
 TMP_DEST[31:0]  <- SRC1[95:64]
 TMP_DEST[63:32] <-  SRC2[95:64]
 TMP_DEST[95:64] <-  SRC1[127:96]
 TMP_DEST[127:96]  <- SRC2[127:96]
FI;
IF VL >= 256
 TMP_DEST[159:128] <-  SRC1[223:192]
 TMP_DEST[191:160] <-  SRC2[223:192]
 TMP_DEST[223:192]  <- SRC1[255:224]
 TMP_DEST[255:224] <-  SRC2[255:224]
FI;
IF VL >= 512
 TMP_DEST[287:256] <-  SRC1[351:320]
 TMP_DEST[319:288] <-  SRC2[351:320]
 TMP_DEST[351:320] <-  SRC1[383:352]
 TMP_DEST[383:352]  <- SRC2[383:352]
 TMP_DEST[415:384] <-  SRC1[479:448]
 TMP_DEST[447:416]  <- SRC2[479:448]
 TMP_DEST[479:448]  <- SRC1[511:480]
 TMP_DEST[511:480]  <- SRC2[511:480]
FI;
FOR j <-  0 TO KL-1
 i  <- j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i]  <- TMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VUNPCKHPS (EVEX encoded version when SRC2 is memory)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <- 0 TO KL-1
 i <-  j * 32
 IF (EVEX.b = 1)
   THEN TMP_SRC2[i+31:i] <-  SRC2[31:0]
   ELSE TMP_SRC2[i+31:i]  <- SRC2[i+31:i]
 FI;
ENDFOR;
IF VL >= 128
 TMP_DEST[31:0]  <- SRC1[95:64]
 TMP_DEST[63:32] <-  TMP_SRC2[95:64]
 TMP_DEST[95:64] <-  SRC1[127:96]
 TMP_DEST[127:96]  <- TMP_SRC2[127:96]
FI;
IF VL >= 256
 TMP_DEST[159:128]  <- SRC1[223:192]
 TMP_DEST[191:160]  <- TMP_SRC2[223:192]
 TMP_DEST[223:192] <-  SRC1[255:224]
 TMP_DEST[255:224] <-  TMP_SRC2[255:224]
FI;
IF VL >= 512
 TMP_DEST[287:256]  <- SRC1[351:320]
 TMP_DEST[319:288]  <- TMP_SRC2[351:320]
 TMP_DEST[351:320]  <- SRC1[383:352]
 TMP_DEST[383:352] <-  TMP_SRC2[383:352]
 TMP_DEST[415:384]  <- SRC1[479:448]
 TMP_DEST[447:416]  <- TMP_SRC2[479:448]
 TMP_DEST[479:448]  <- SRC1[511:480]
 TMP_DEST[511:480]  <- TMP_SRC2[511:480]
FI;
FOR j <-  0 TO KL-1
 i  <- j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i]  <- TMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i]  <- 0
FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VUNPCKHPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <- SRC1[95:64]
DEST[63:32]  <-SRC2[95:64]
DEST[95:64]  <-SRC1[127:96]
DEST[127:96] <- SRC2[127:96]
DEST[159:128] <- SRC1[223:192]
DEST[191:160] <- SRC2[223:192]
DEST[223:192] <- SRC1[255:224]
DEST[255:224] <- SRC2[255:224]
DEST[MAX_VL-1:256] <-  0
```
#### VUNPCKHPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- SRC1[95:64]
DEST[63:32]  <-SRC2[95:64]
DEST[95:64] <- SRC1[127:96]
DEST[127:96] <- SRC2[127:96]
DEST[MAX_VL-1:128] <- 0
```
#### UNPCKHPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0]  <-SRC1[95:64]
DEST[63:32] <- SRC2[95:64]
DEST[95:64] <- SRC1[127:96]
DEST[127:96] <- SRC2[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VUNPCKHPS __m512 _mm512_unpackhi_ps( __m512 a, __m512 b);
VUNPCKHPS __m512 _mm512_mask_unpackhi_ps(__m512 s, __mmask16 k, __m512 a, __m512 b);
VUNPCKHPS __m512 _mm512_maskz_unpackhi_ps(__mmask16 k, __m512 a, __m512 b);
VUNPCKHPS __m256 _mm256_unpackhi_ps (__m256 a, __m256 b);
VUNPCKHPS __m256 _mm256_mask_unpackhi_ps(__m256 s, __mmask8 k, __m256 a, __m256 b);
VUNPCKHPS __m256 _mm256_maskz_unpackhi_ps(__mmask8 k, __m256 a, __m256 b);
UNPCKHPS __m128 _mm_unpackhi_ps (__m128 a, __m128 b);
VUNPCKHPS __m128 _mm_mask_unpackhi_ps(__m128 s, __mmask8 k, __m128 a, __m128 b);
VUNPCKHPS __m128 _mm_maskz_unpackhi_ps(__mmask8 k, __m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instructions, see Exceptions Type 4.

EVEX-encoded instructions, see Exceptions Type E4NF.

