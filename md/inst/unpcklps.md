----------------------------
title : UNPCKLPS (Intel x86/64 assembly instruction)
cat_title : UNPCKLPS
ref_title : UNPCKLPS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ UNPCKLPS

**Unpack and Interleave Low Packed Single-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 14 /rUNPCKLPS xmm1, xmm2/m128|RM|V/V|SSE|Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm1 and xmm2/m128.|
|VEX.NDS.128.0F.WIG 14 /rVUNPCKLPS xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm2 and xmm3/m128.|
|VEX.NDS.256.0F.WIG 14 /rVUNPCKLPS ymm1,ymm2,ymm3/m256|RVM|V/V|AVX|Unpacks and Interleaves single-precision floating-point values from low quadwords of ymm2 and ymm3/m256.|
|EVEX.NDS.128.0F.W0 14 /rVUNPCKLPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VLAVX512F|Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm2 and xmm3/mem and write result to xmm1 subject to write mask k1.|
|EVEX.NDS.256.0F.W0 14 /rVUNPCKLPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VLAVX512F|Unpacks and Interleaves single-precision floating-point values from low quadwords of ymm2 and ymm3/mem and write result to ymm1 subject to write mask k1.|
|EVEX.NDS.512.0F.W0 14 /rVUNPCKLPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Unpacks and Interleaves single-precision floating-point values from low quadwords of zmm2 and zmm3/m512/m32bcst and write result to zmm1 subject to write mask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Performs an interleaved unpack of the low single-precision floating-point values from the first source operand and the second source operand. 

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified. When unpacking from a memory operand, an implementation may fetch only the appropriate 64 bits; however, alignment to 16-byte boundary and normal segment checking will still be enforced.

VEX.128 encoded version: The first source operand is a XMM register. The second source operand can be a XMM register or a 128-bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register.

```embed
<figure>
<svg viewBox="0 0 396.480042 248.820007">
<rect x="0.000000" y="10.000000" width="0.480000" height="151.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="151.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="161.680054" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M331.380005,94.479980 L331.920013,94.299988 L332.100006,94.179993 L332.220001,94.000000 L332.279999,93.880005 L332.339996,93.639954 L332.399994,93.459961 L332.339996,93.279968 C332.205994 92.890991,332.210999 92.683960,331.739990 92.559998  L331.380005,92.440002 L331.200012,92.500000 C330.255005 92.583984,330.101013 94.031982,330.959991 94.359985  L331.200012,94.419983 L331.380005,94.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M331.380005,93.460022 L336.360016,93.460022 L336.179993,94.119995 L331.860016,109.119995 L331.380005,110.800049 L330.899994,109.119995 L326.580017,94.119995 L326.399994,93.460022 L327.059998,93.460022 L327.540009,93.820007 L331.860016,108.820007 L330.899994,109.119995 L330.899994,108.820007 L335.220001,93.820007 L336.179993,94.119995 L335.700012,94.480042 L331.380005,94.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="327.059998" y="93.459961" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M331.380005,93.940002 L335.700012,93.940002 L331.380005,108.940002 L327.059998,93.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="330.420013" y="56.739990" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M309.779999,99.940002 L310.139984,100.179993 C310.931000 100.596008,311.963989 99.596008,311.399994 98.799988  L311.279999,98.619995 L311.160004,98.500000 C310.376007 97.830994,309.321991 98.692993,309.600006 99.580017  L309.660004,99.760010 L309.779999,99.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M310.559998,99.280029 L313.380005,102.520020 L313.799988,103.060059 L313.200012,103.300049 L299.160004,110.020020 L297.600006,110.800049 L298.500000,109.300049 L306.839996,96.160034 L307.260010,95.560059 L307.679993,96.100037 L307.739990,96.700012 L299.399994,109.840027 L298.500000,109.300049 L298.739990,109.120056 L312.779999,102.400024 L313.200012,103.300049 L312.600006,103.180054 L309.779999,99.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.680023,96.100037 L310.560028,99.280029 L309.780029,99.940063 L306.900024,96.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M310.200012,99.580017 L313.020020,102.820007 L298.980011,109.540039 L307.320007,96.400024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.680023,84.520020 L327.360016,83.020020 L309.900024,98.559998 L311.220032,100.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.520020" y="43.239990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="314.520020" y="43.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="351.360016" y="43.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="56.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="43.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.380005" y="43.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="277.380005" y="43.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="43.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="56.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="43.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.240021" y="43.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="240.240021" y="43.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="43.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="56.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="43.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="203.100006" y="43.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="203.100006" y="43.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="43.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="56.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="43.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.520020" y="70.239990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="314.520020" y="70.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="351.360016" y="70.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="83.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="70.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.380005" y="70.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="277.380005" y="70.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="70.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="83.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="70.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.240021" y="70.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="240.240021" y="70.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="70.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="83.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="70.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="203.100006" y="70.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="203.100006" y="70.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="70.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="83.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="70.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.520020" y="110.739990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="314.520020" y="110.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="351.360016" y="110.739990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="124.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="110.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.380005" y="110.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="277.380005" y="110.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="314.279999" y="110.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="124.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="110.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.240021" y="110.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="240.240021" y="110.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="277.140015" y="110.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="124.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="110.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="203.100006" y="110.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="203.100006" y="110.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.000000" y="110.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="124.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="110.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.020020" y="110.739990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="166.020020" y="110.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="110.739990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="124.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="110.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.880005" y="110.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.880005" y="110.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="110.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="124.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="110.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.739998" y="110.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="91.739998" y="110.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="110.739990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="124.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="110.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.599998" y="110.739990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="54.599998" y="110.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="110.739990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.360008" y="124.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.360008" y="110.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.020020" y="43.239990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="166.020020" y="43.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="43.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="56.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="43.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.880005" y="43.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.880005" y="43.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="43.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="56.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="43.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.739998" y="43.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="91.739998" y="43.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="43.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="56.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="43.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.599998" y="43.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="54.599998" y="43.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="43.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.360008" y="56.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.360008" y="43.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.020020" y="70.239990" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="166.020020" y="70.000000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="202.860016" y="70.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="83.500000" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="70.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.880005" y="70.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.880005" y="70.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.779999" y="70.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="83.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="70.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.739998" y="70.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="91.739998" y="70.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="70.239990" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="83.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="70.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.599998" y="70.239990" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="54.599998" y="70.000000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.500008" y="70.239990" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.360008" y="83.500000" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.360008" y="70.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M266.880005,97.720032 L267.059998,97.840027 L267.239990,97.900024 C268.265991 98.051025,268.895996 97.013062,268.260010 96.280029  L268.080017,96.100037 L267.899994,96.040039 C266.988007 95.592041,266.192993 96.551025,266.640015 97.420044  L266.760010,97.600037 L266.880005,97.720032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.480011,96.940002 L270.960022,99.520020 L271.440002,99.940002 L270.960022,100.299988 L258.480011,109.720032 L257.040009,110.799988 L257.700012,109.179993 L263.279999,94.599976 L263.520020,93.940002 L264.059998,94.359985 L264.240021,94.900024 L258.660004,109.479980 L257.700012,109.179993 L257.880005,108.940002 L270.360016,99.520020 L270.960022,100.299988 L270.360016,100.299988 L266.880005,97.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.059998,94.359985 L267.480011,96.940002 L266.880005,97.719971 L263.459991,95.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.180023,97.299988 L270.660034,99.880005 L258.180023,109.299988 L263.760010,94.719971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M298.380005,57.340027 L296.820007,56.140015 L266.700012,96.340027 L268.260010,97.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.619995,104.979980 L238.679993,105.159973 L238.799988,105.279968 L238.979980,105.399963 L239.100006,105.519958 L239.339996,105.579956 L239.699982,105.579956 L239.880005,105.519958 L240.059998,105.459961 L240.239990,105.339966 L240.359985,105.159973 L240.479980,105.039978 L240.540009,104.859985 L240.540009,104.440002 L240.479980,104.260010 L240.359985,104.079956 C239.889008 103.247009,238.550995 103.594971,238.559998 104.559998  L238.559998,104.739990 L238.619995,104.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.520020,104.619995 L241.020020,108.640015 L241.200012,109.299988 L240.600006,109.359985 L225.060028,110.679993 L223.320007,110.799988 L224.700012,109.779968 L237.180023,100.419983 L237.780029,100.000000 L237.960022,100.599976 L237.840027,101.200012 L225.360016,110.559998 L224.700012,109.779968 L225.000031,109.659973 L240.540009,108.339966 L240.600006,109.359985 L240.120026,109.000000 L238.620026,104.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.960022,100.600037 L239.520020,104.620056 L238.620026,104.980042 L237.060028,100.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.100006,104.799988 L240.600006,108.820007 L225.059998,110.140015 L237.540009,100.779968" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M294.600006,84.700012 L293.880005,82.840027 L239.160004,103.720032 L239.880005,105.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.240021,94.479980 L186.420013,94.419983 L186.660034,94.359985 C187.519012 94.031982,187.365021 92.583984,186.420013 92.500000  L186.240021,92.440002 L185.700012,92.619995 L185.520020,92.739990 L185.400024,92.919983 L185.340027,93.099976 L185.220032,93.459961 C185.338013 93.766968,185.330017 94.132996,185.700012 94.299988  L186.240021,94.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.240021,93.460022 L191.220032,93.460022 L191.040009,94.119995 L186.720032,109.119995 L186.240021,110.800049 L185.760010,109.119995 L181.440033,94.119995 L181.260010,93.460022 L181.920013,93.460022 L182.400024,93.820007 L186.720032,108.820007 L185.760010,109.119995 L185.760010,108.820007 L190.080017,93.820007 L191.040009,94.119995 L190.560028,94.480042 L186.240021,94.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.920013" y="93.459961" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.240021,93.940002 L190.560028,93.940002 L186.240021,108.940002 L181.920013,93.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="185.279999" y="56.739990" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M164.700012,99.940002 L164.820007,100.059998 L165.000000,100.179993 L165.180023,100.239990 L165.720001,100.239990 L166.080017,100.000000 L166.200012,99.880005 L166.320007,99.700012 L166.380005,99.520020 L166.440002,99.340027 L166.440002,99.159973 L166.320007,98.799988 L166.200012,98.619995 L166.020020,98.440002 L165.480011,98.260010 L165.300018,98.260010 L164.940002,98.380005 L164.760010,98.500000 L164.520020,98.859985 L164.460022,99.039978 L164.400024,99.220032 L164.460022,99.400024 L164.460022,99.580017 L164.580017,99.760010 L164.700012,99.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.420013,99.280029 L168.240021,102.520020 L168.660004,103.060059 L168.060028,103.300049 L154.020020,110.020020 L152.460022,110.800049 L153.360016,109.300049 L161.700012,96.160034 L162.120026,95.560059 L162.540009,96.100037 L162.600006,96.700012 L154.260010,109.840027 L153.360016,109.300049 L153.600006,109.120056 L167.640015,102.400024 L168.060028,103.300049 L167.460022,103.180054 L164.640015,99.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.540009,96.100037 L165.420013,99.280029 L164.640015,99.940063 L161.760010,96.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.059998,99.580017 L167.880005,102.820007 L153.839996,109.540039 L162.179993,96.400024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.540009,84.520020 L182.220001,83.020020 L164.760010,98.559998 L166.080017,100.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.799995,97.720032 L121.919991,97.840027 L122.159996,97.900024 C123.112999 98.058044,123.775993 97.022034,123.120003 96.280029  L122.999992,96.100037 L122.820000,96.040039 C121.885002 95.586060,121.040993 96.517029,121.499992 97.420044  L121.620003,97.600037 L121.799995,97.720032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.400002,96.940002 L125.820000,99.520020 L126.299995,99.940002 L125.820000,100.299988 L113.400002,109.720032 L111.959999,110.799988 L112.620003,109.179993 L118.140007,94.599976 L118.379997,93.940002 L118.920006,94.359985 L119.099998,94.900024 L113.580009,109.479980 L112.620003,109.179993 L112.799995,108.940002 L125.220009,99.520020 L125.820000,100.299988 L125.220009,100.299988 L121.799995,97.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.920006,94.359985 L122.400002,96.940002 L121.800011,97.719971 L118.320000,95.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.099998,97.299988 L125.519997,99.880005 L113.099998,109.299988 L118.620003,94.719971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.300018,57.340027 L151.740021,56.140015 L121.620018,96.340027 L123.180016,97.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.480003,104.979980 L93.540001,105.159973 L93.659996,105.279968 L94.019997,105.519958 L94.200005,105.579956 L94.560005,105.579956 L94.739998,105.519958 L94.920006,105.459961 L95.099998,105.339966 L95.220009,105.159973 L95.340004,105.039978 L95.400002,104.859985 L95.400002,104.440002 L95.340004,104.260010 L95.280006,104.079956 C94.698006 103.242004,93.429008 103.625977,93.420006 104.559998  L93.420006,104.739990 L93.480003,104.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.379997,104.619995 L95.879997,108.640015 L96.059990,109.299988 L95.459999,109.359985 L79.919991,110.679993 L78.180000,110.799988 L79.559990,109.779968 L92.040001,100.419983 L92.639992,100.000000 L92.820000,100.599976 L92.700005,101.200012 L80.219994,110.559998 L79.559990,109.779968 L79.859993,109.659973 L95.400002,108.339966 L95.459999,109.359985 L94.980003,109.000000 L93.480003,104.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.820000,100.600037 L94.379997,104.620056 L93.480003,104.980042 L91.920006,100.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.959999,104.799988 L95.459999,108.820007 L79.920006,110.140015 L92.400002,100.779968" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M149.459991,84.700012 L148.739990,82.840027 L94.019997,103.720032 L94.739998,105.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="74.040001" y="78.760010" textLength="4.170000" font-size="8px">7</text>
<text x="111.180000" y="78.760010" textLength="4.170000" font-size="8px">6</text>
<text x="106.200005" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="180.420013" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="148.380005" y="51.760010" textLength="4.170000" font-size="8px">5</text>
<text x="143.339996" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="185.400024" y="51.760010" textLength="4.170000" font-size="8px">4</text>
<text x="180.420013" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="74.040001" y="119.260010" textLength="4.170000" font-size="8px">5</text>
<text x="111.180000" y="119.260010" textLength="4.170000" font-size="8px">5</text>
<text x="106.200005" y="119.260010" textLength="5.002500" font-size="8px">X</text>
<text x="148.380005" y="119.260010" textLength="4.170000" font-size="8px">4</text>
<text x="180.420013" y="119.260010" textLength="5.002500" font-size="8px">X</text>
<text x="222.540009" y="119.260010" textLength="4.170000" font-size="8px">1</text>
<text x="217.559998" y="119.260010" textLength="5.002500" font-size="8px">Y</text>
<text x="254.700012" y="119.260010" textLength="5.002500" font-size="8px">X</text>
<text x="334.020020" y="119.260010" textLength="4.170000" font-size="8px">0</text>
<text x="259.680023" y="78.760010" textLength="4.170000" font-size="8px">2</text>
<text x="254.700012" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="291.839996" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="328.980011" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="222.540009" y="51.760010" textLength="4.170000" font-size="8px">3</text>
<text x="217.559998" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="259.680023" y="51.760010" textLength="4.170000" font-size="8px">2</text>
<text x="334.020020" y="51.760010" textLength="4.170000" font-size="8px">0</text>
<text x="328.980011" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="50.216988" y="78.820007" textLength="4.170000" font-size="8px">2</text>
<text x="39.419991" y="78.820007" textLength="5.415000" font-size="8px">R</text>
<text x="50.398506" y="53.440002" textLength="4.170000" font-size="8px">1</text>
<text x="49.798485" y="119.320007" textLength="4.582500" font-size="8px">T</text>
<text x="44.818489" y="119.320007" textLength="5.002500" font-size="8px">S</text>
<text x="39.838493" y="119.320007" textLength="5.002500" font-size="8px">E</text>
<text x="34.379997" y="119.320007" textLength="5.415000" font-size="8px">D</text>
<text x="291.839996" y="119.260010" textLength="5.002500" font-size="8px">Y</text>
<text x="44.818489" y="78.820007" textLength="5.415000" font-size="8px">C</text>
<text x="254.700012" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="259.680023" y="119.260010" textLength="4.170000" font-size="8px">1</text>
<text x="45.001503" y="53.440002" textLength="5.415000" font-size="8px">C</text>
<text x="69.060005" y="119.260010" textLength="5.002500" font-size="8px">Y</text>
<text x="334.020020" y="78.760010" textLength="4.170000" font-size="8px">0</text>
<text x="143.339996" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="296.880005" y="78.760010" textLength="4.170000" font-size="8px">1</text>
<text x="106.200005" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="143.339996" y="119.260010" textLength="5.002500" font-size="8px">Y</text>
<text x="111.180000" y="51.760010" textLength="4.170000" font-size="8px">6</text>
<text x="148.380005" y="78.760010" textLength="4.170000" font-size="8px">5</text>
<text x="39.604500" y="53.440002" textLength="5.415000" font-size="8px">R</text>
<text x="34.379997" y="78.820007" textLength="5.002500" font-size="8px">S</text>
<text x="185.400024" y="119.260010" textLength="4.170000" font-size="8px">4</text>
<text x="69.060005" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
<text x="291.839996" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="296.880005" y="51.760010" textLength="4.170000" font-size="8px">1</text>
<text x="34.620003" y="53.440002" textLength="5.002500" font-size="8px">S</text>
<text x="328.980011" y="119.260010" textLength="5.002500" font-size="8px">X</text>
<text x="296.880005" y="119.260010" textLength="4.170000" font-size="8px">0</text>
<text x="74.040001" y="51.760010" textLength="4.170000" font-size="8px">7</text>
<text x="69.060005" y="51.760010" textLength="5.002500" font-size="8px">X</text>
<text x="185.400024" y="78.760010" textLength="4.170000" font-size="8px">4</text>
<text x="222.540009" y="78.760010" textLength="4.170000" font-size="8px">3</text>
<text x="217.559998" y="78.760010" textLength="5.002500" font-size="8px">Y</text>
</svg>
<figcaption>Figure 4-28.  VUNPCKLPS Operation
</figcaption></figure>
```


EVEX.512 encoded version: The first source operand is a ZMM register. The second source operand is a ZMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 32-bit memory location. The destina-tion operand is a ZMM register, conditionally updated using writemask k1. 

EVEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register, a 256-bit memory location, or a 256-bit vector broadcasted from a 32-bit memory location. The destina-tion operand is a YMM register, conditionally updated using writemask k1. 

EVEX.128 encoded version: The first source operand is an XMM register. The second source operand is a XMM register, a 128-bit memory location, or a 128-bit vector broadcasted from a 32-bit memory location. The destina-tion operand is a XMM register, conditionally updated using writemask k1. 


### Operation
#### VUNPCKLPS (EVEX encoded version when SRC2 is a ZMM register)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF VL >= 128
 TMP_DEST[31:0] <-  SRC1[31:0]
 TMP_DEST[63:32]  <- SRC2[31:0]
 TMP_DEST[95:64]  <- SRC1[63:32]
 TMP_DEST[127:96] <-  SRC2[63:32]
FI;
IF VL >= 256
 TMP_DEST[159:128]  <- SRC1[159:128]
 TMP_DEST[191:160] <-  SRC2[159:128]
 TMP_DEST[223:192] <-  SRC1[191:160]
 TMP_DEST[255:224] <-  SRC2[191:160]
FI;
IF VL >= 512
 TMP_DEST[287:256] <-  SRC1[287:256]
 TMP_DEST[319:288] <-  SRC2[287:256]
 TMP_DEST[351:320]  <- SRC1[319:288]
 TMP_DEST[383:352]  <- SRC2[319:288]
 TMP_DEST[415:384] <-  SRC1[415:384]
 TMP_DEST[447:416]  <- SRC2[415:384]
 TMP_DEST[479:448] <-  SRC1[447:416]
 TMP_DEST[511:480]  <- SRC2[447:416]
FI;
FOR j <-  0 TO KL-1
 i  <- j * 32
IF k1[j] OR *no writemask*
   THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VUNPCKLPS (EVEX encoded version when SRC2 is memory)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <- 0 TO KL-1
 i  <- j * 31
 IF (EVEX.b = 1)
   THEN TMP_SRC2[i+31:i] <-  SRC2[31:0]
   ELSE TMP_SRC2[i+31:i] <-  SRC2[i+31:i]
 FI;
ENDFOR;
IF VL >= 128
TMP_DEST[31:0]  <- SRC1[31:0]
TMP_DEST[63:32]  <- TMP_SRC2[31:0]
TMP_DEST[95:64]  <- SRC1[63:32]
TMP_DEST[127:96]  <- TMP_SRC2[63:32]
FI;
IF VL >= 256
 TMP_DEST[159:128]  <- SRC1[159:128]
 TMP_DEST[191:160] <-  TMP_SRC2[159:128]
 TMP_DEST[223:192] <-  SRC1[191:160]
 TMP_DEST[255:224]  <- TMP_SRC2[191:160]
FI;
IF VL >= 512
 TMP_DEST[287:256]  <- SRC1[287:256]
 TMP_DEST[319:288] <-  TMP_SRC2[287:256]
 TMP_DEST[351:320] <-  SRC1[319:288]
 TMP_DEST[383:352] <-  TMP_SRC2[319:288]
 TMP_DEST[415:384]  <- SRC1[415:384]
 TMP_DEST[447:416] <-  TMP_SRC2[415:384]
 TMP_DEST[479:448]  <- SRC1[447:416]
 TMP_DEST[511:480]  <- TMP_SRC2[447:416]
FI;
FOR j <-  0 TO KL-1
 i  <- j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### UNPCKLPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0]
DEST[63:32] <- SRC2[31:0]
DEST[95:64] <- SRC1[63:32]
DEST[127:96]  <-SRC2[63:32]
DEST[159:128]  <-SRC1[159:128]
DEST[191:160] <- SRC2[159:128]
DEST[223:192]  <-SRC1[191:160]
DEST[255:224]  <-SRC2[191:160]
DEST[MAX_VL-1:256]  <- 0
```
#### VUNPCKLPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <- SRC1[31:0]
DEST[63:32] <- SRC2[31:0]
DEST[95:64]  <-SRC1[63:32]
DEST[127:96] <- SRC2[63:32]
DEST[MAX_VL-1:128] <- 0
```
#### UNPCKLPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0]  <-SRC1[31:0]
DEST[63:32]  <-SRC2[31:0]
DEST[95:64]  <-SRC1[63:32]
DEST[127:96]  <-SRC2[63:32]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VUNPCKLPS __m512 _mm512_unpacklo_ps(__m512 a, __m512 b);
VUNPCKLPS __m512 _mm512_mask_unpacklo_ps(__m512 s, __mmask16 k, __m512 a, __m512 b);
VUNPCKLPS __m512 _mm512_maskz_unpacklo_ps(__mmask16 k, __m512 a, __m512 b);
VUNPCKLPS __m256 _mm256_unpacklo_ps (__m256 a, __m256 b);
VUNPCKLPS __m256 _mm256_mask_unpacklo_ps(__m256 s, __mmask8 k, __m256 a, __m256 b);
VUNPCKLPS __m256 _mm256_maskz_unpacklo_ps(__mmask8 k, __m256 a, __m256 b);
UNPCKLPS __m128 _mm_unpacklo_ps (__m128 a, __m128 b);
VUNPCKLPS __m128 _mm_mask_unpacklo_ps(__m128 s, __mmask8 k, __m128 a, __m128 b);
VUNPCKLPS __m128 _mm_maskz_unpacklo_ps(__mmask8 k, __m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instructions, see Exceptions Type 4.

EVEX-encoded instructions, see Exceptions Type E4NF.

### CHAPTER 5
### INSTRUCTION SET REFERENCE, V-Z
### 5.1  TERNARY BIT VECTOR LOGIC TABLE 


VPTERNLOGD/VPTERNLOGQ instructions operate on dword/qword elements and take three bit vectors of the respective input data elements to form a set of 32/64 indices, where each 3-bit value provides an index into an 8-bit lookup table represented by the imm8 byte of the instruction. The 256 possible values of the imm8 byte is constructed as a 16x16 boolean logic table. The 16 rows of the table uses the lower 4 bits of imm8 as row index. The 16 columns are referenced by imm8[7:4]. The 16 columns of the table are present in two halves, with 8 columns shown in Table 5-1 for the column index value between 0:7, followed by Table 5-2 showing the 8 columns corresponding to column index 8:15. This section presents the two-halves of the 256-entry table using a short-hand notation representing simple or compound boolean logic expressions with three input bit source data. 

The three input bit source data will be denoted with the capital letters: A, B, C; where A represents a bit from the first source operand (also the destination operand), B and C represent a bit from the 2nd and 3rd source operands. 

Each map entry takes the form of a logic expression consisting of one of more component expressions. Each component expression consists of either a unary or binary boolean operator and associated operands. Each binary boolean operator is expressed in lowercase letters, and operands concatenated after the logic operator. The unary operator 'not' is expressed using '!'. Additionally, the conditional expression "A?B:C" expresses a result returning B if A is set, returning C otherwise.

A binary boolean operator is followed by two operands, e.g. andAB. For a compound binary expression that contain commutative components and comprising the same logic operator, the 2nd logic operator is omitted and three operands can be concatenated in sequence, e.g. andABC. When the 2nd operand of the first binary boolean expres-sion comes from the result of another boolean expression, the 2nd boolean expression is concatenated after the uppercase operand of the first logic expression, e.g. norBnandAC. When the result is independent of an operand, that operand is omitted in the logic expression, e.g. zeros or norCB.

The 3-input expression "majorABC" returns 0 if two or more input bits are 0, returns 1 if two or more input bits are 1. The 3-input expression "minorABC" returns 1 if two or more input bits are 0, returns 0 if two or more input bits are 1.

The building-block bit logic functions used in Table 5-1 and Table 5-2 include;

*  Constants: TRUE (1), FALSE (0);

*  Unary function: Not (!);

*  Binary functions: and, nand, or, nor, xor, xnor;

*  Conditional function: Select (?:);

*  Tertiary functions: major, minor.



:

###       Table 5-1. Low 8 columns of the 16x16 Map of VPTERNLOG Boolean Logic Operations


Table 5-2 shows the half of 256-entry map corresponding to column index values 8:15.



|**Imm**||||[7:|4]||||
|-------||||---|--||||
|**[3:0]**|0H|1H|2H|3H|4H|5H|6H|7H|
|00H|FALSE|andAnorBC|norBnandAC|andA!B|norCnandBA|andA!C|andAxorBC|andAnandBC|
|01H|norABC|norCB|norBxorAC|A?!B:norBC|norCxorBA|A?!C:norBC|A?xorBC:norBC|A?nandBC:norBC|
|02H|andCnorBA|norBxnorAC|andC!B|norBnorAC|C?norBA:andBA|C?norBA:A|C?!B:andBA|C?!B:A|
|03H|norBA|norBandAC|C?!B:norBA|!B|C?norBA:xnorBA|A?!C:!B|A?xorBC:!B|A?nandBC:!B|
|04H|andBnorAC|norCxnorBA|B?norAC:andAC|B?norAC:A|andB!C|norCnorBA|B?!C:andAC|B?!C:A|
|05H|norCA|norCandBA|B?norAC:xnorAC|A?!B:!C|B?!C:norAC|!C|A?xorBC:!C|A?nandBC:!C|
|06H|norAxnorBC|A?norBC:xorBC|B?norAC:C|xorBorAC|C?norBA:B|xorCorBA|xorCB|B?!C:orAC|
|07H|norAandBC|minorABC|C?!B:!A|nandBorAC|B?!C:!A|nandCorBA|A?xorBC:nandBC|nandCB|
|08H|norAnandBC|A?norBC:andBC|andCxorBA|A?!B:andBC|andBxorAC|A?!C:andBC|A?xorBC:andBC|xorAandBC|
|09H|norAxorBC|A?norBC:xnorBC|C?xorBA:norBA|A?!B:xnorBC|B?xorAC:norAC|A?!C:xnorBC|xnorABC|A?nandBC:xnorBC|
|0AH|andC!A|A?norBC:C|andCnandBA|A?!B:C|C?!A:andBA|xorCA|xorCandBA|A?nandBC:C|
|0BH|C?!A:norBA|C?!A:!B|C?nandBA:norBA|C?nandBA:!B|B?xorAC:!A|B?xorAC:nandAC|C?nandBA:xnorBA|nandBxnorAC|
|0CH|andB!A|A?norBC:B|B?!A:andAC|xorBA|andBnandAC|A?!C:B|xorBandAC|A?nandBC:B|
|0DH|B?!A:norAC|B?!A:!C|B?!A:xnorAC|C?xorBA:nandBA|B?nandAC:norAC|B?nandAC:!C|B?nandAC:xnorAC|nandCxnorBA|
|0EH|norAnorBC|xorAorBC|B?!A:C|A?!B:orBC|C?!A:B|A?!C:orBC|B?nandAC:C|A?nandBC:orBC|
|0FH|!A|nandAorBC|C?nandBA:!A|nandBA|B?nandAC:!A|nandCA|nandAxnorBC|nandABC|


:

###       Table 5-2. Low 8 columns of the 16x16 Map of VPTERNLOG Boolean Logic Operations


Table 5-1 and Table 5-2 translate each of the possible value of the imm8 byte to a Boolean expression. These tables can also be used by software to translate Boolean expressions to numerical constants to form the imm8 value needed to construct the VPTERNLOG syntax. There is a unique set of three byte constants (F0H, CCH, AAH) that can be used for this purpose as input operands in conjunction with the Boolean expressions defined in those tables. The reverse mapping can be expressed as:

Result_imm8 = Table_Lookup_Entry( 0F0H, 0CCH, 0AAH)

Table_Lookup_Entry is the Boolean expression defined in Table 5-1 and Table 5-2.



|**Imm**||||[7:|4]||||
|-------||||---|--||||
|**[3:0]**|08H|09H|0AH|0BH|0CH|0DH|0EH|0FH|
|00H|andABC|andAxnorBC|andCA|B?andAC:A|andBA|C?andBA:A|andAorBC|A|
|01H|A?andBC:norBC|B?andAC:!C|A?C:norBC|C?A:!B|A?B:norBC|B?A:!C|xnorAorBC|orAnorBC|
|02H|andCxnorBA|B?andAC:xorAC|B?andAC:C|B?andAC:orAC|C?xnorBA:andBA|B?A:xorAC|B?A:C|B?A:orAC|
|03H|A?andBC:!B|xnorBandAC|A?C:!B|nandBnandAC|xnorBA|B?A:nandAC|A?orBC:!B|orA!B|
|04H|andBxnorAC|C?andBA:xorBA|B?xnorAC:andAC|B?xnorAC:A|C?andBA:B|C?andBA:orBA|C?A:B|C?A:orBA|
|05H|A?andBC:!C|xnorCandBA|xnorCA|C?A:nandBA|A?B:!C|nandCnandBA|A?orBC:!C|orA!C|
|06H|A?andBC:xorBC|xorABC|A?C:xorBC|B?xnorAC:orAC|A?B:xorBC|C?xnorBA:orBA|A?orBC:xorBC|orAxorBC|
|07H|xnorAandBC|A?xnorBC:nandBC|A?C:nandBC|nandBxorAC|A?B:nandBC|nandCxorBA|A?orBCnandBC|orAnandBC|
|08H|andCB|A?xnorBC:andBC|andCorAB|B?C:A|andBorAC|C?B:A|majorABC|orAandBC|
|09H|B?C:norAC|xnorCB|xnorCorBA|C?orBA:!B|xnorBorAC|B?orAC:!C|A?orBC:xnorBC|orAxnorBC|
|0AH|A?andBC:C|A?xnorBC:C|C|B?C:orAC|A?B:C|B?orAC:xorAC|orCandBA|orCA|
|0BH|B?C:!A|B?C:nandAC|orCnorBA|orC!B|B?orAC:!A|B?orAC:nandAC|orCxnorBA|nandBnorAC|
|0CH|A?andBC:B|A?xnorBC:B|A?C:B|C?orBA:xorBA|B|C?B:orBA|orBandAC|orBA|
|0DH|C?B!A|C?B:nandBA|C?orBA:!A|C?orBA:nandBA|orBnorAC|orB!C|orBxnorAC|nandCnorBA|
|0EH|A?andBC:orBC|A?xnorBC:orBC|A?C:orBC|orCxorBA|A?B:orBC|orBxorAC|orCB|orABC|
|0FH|nandAnandBC|nandAxorBC|orC!A|orCnandBA|orB!A|orBnandAC|nandAnorBC|TRUE|
### 5.2  INSTRUCTIONS (V-Z)


Chapter 5 continues an alphabetical discussion of Intel\footnote{(R)}  64 and IA-32 instructions (V-Z). See also: Chapter 3, "Instruction Set Reference, A-L," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A, and Chapter 4, "Instruction Set Reference, M-U," in the Intel(R) 64 and IA-32 Architectures Software Devel-oper's Manual, Volume 2B.

