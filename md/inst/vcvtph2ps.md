----------------------------
title : VCVTPH2PS (Intel x86/64 assembly instruction)
cat_title : VCVTPH2PS
ref_title : VCVTPH2PS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VCVTPH2PS

**Convert 16-bit FP values to Single-Precision FP values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.128.66.0F38.W0 13 /r \newline{}VCVTPH2PS xmm1, xmm2/m64|RM|V/V|F16C|Convert four packed half precision (16-bit) floating-point values in xmm2/m64 to packed single-precision floating-point value in xmm1. |
|VEX.256.66.0F38.W0 13 /r \newline{}VCVTPH2PS ymm1, xmm2/m128|RM|V/V|F16C|Convert eight packed half precision (16-bit) floating-point values in xmm2/m128 to packed single-precision floating-point value in ymm1. |
|EVEX.128.66.0F38.W0 13 /r \newline{}VCVTPH2PS xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512F|Convert four packed half precision (16-bit) floating-point values in xmm2/m64 to packed single-precision floating-point values in xmm1. |
|EVEX.256.66.0F38.W0 13 /r \newline{}VCVTPH2PS ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512F|Convert eight packed half precision (16-bit) floating-point values in xmm2/m128 to packed single-precision floating-point values in ymm1. |
|EVEX.512.66.0F38.W0 13 /r \newline{}VCVTPH2PS zmm1 {k1}{z}, ymm2/m256 {sae}|HVM|V/V|AVX512F|Convert sixteen packed half precision (16-bit) floating-point values in ymm2/m256 to packed single-precision floating-point values in zmm1. |
###                                                        Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

 RM ModRM:reg (w) ModRM:r/m (r) NA NA

HVM ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts packed half precision (16-bits) floating-point values in the low-order bits of the source operand (the second operand) to packed single-precision floating-point values and writes the converted values into the destina-tion operand (the first operand).

If case of a denormal operand, the correct normal result is returned. MXCSR.DAZ is ignored and is treated as if it 0. No denormal exception is reported on MXCSR.

VEX.128 version: The source operand is a XMM register or 64-bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:128) of the corresponding destination register are zeroed.

VEX.256 version: The source operand is a XMM register or 128-bit memory location. The destination operand is a YMM register. Bits (MAX_VL-1:256) of the corresponding destination register are zeroed.

EVEX encoded versions: The source operand is a YMM/XMM/XMM (low 64-bits) register or a 256/128/64-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1. 

The diagram below illustrates how data is converted from four packed half precision (in 64 bits) to four single preci-sion (in 128 bits) FP values.

Note: VEX.vvvv and EVEX.vvvv are reserved (must be 1111b).

```embed
<figure>
<svg viewBox="0 0 396.480042 224.460022">
<rect x="0.000000" y="10.000000" width="0.480000" height="127.320000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="127.320000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="137.320007" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.760010" y="44.440002" width="39.840000" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="247.980011" y="44.440002" width="39.779999" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.200012" y="44.440002" width="39.779999" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.360016" y="44.440002" width="39.840000" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="88.799995" y="44.440002" width="79.559998" height="9.360000" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<rect x="9.180000" y="44.440002" width="79.620003" height="9.360000" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<rect x="247.980011" y="119.260010" width="79.620003" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.360016" y="119.260010" width="79.620003" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="88.799995" y="119.260010" width="79.559998" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="9.180000" y="119.260010" width="79.620003" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="253.680023" y="77.140015" width="28.379999" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="293.520020" y="77.140015" width="28.320000" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="114.420006" y="86.500000" width="28.320000" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="34.799995" y="86.500000" width="28.320000" height="9.360000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<text x="208.863556" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="201.784271" y="32.139832" textLength="1.484603" font-size="8px">i</text>
<text x="195.960876" y="32.139832" textLength="1.859097" font-size="8px">,</text>
<text x="188.513794" y="32.139832" textLength="3.718194" font-size="8px">6</text>
<text x="183.113708" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="179.390167" y="32.139832" textLength="3.718194" font-size="8px">e</text>
<text x="173.990082" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="171.949097" y="32.139832" textLength="1.859097" font-size="8px">/</text>
<text x="168.170044" y="32.139832" textLength="3.718194" font-size="8px">2</text>
<text x="162.830170" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="154.081024" y="32.139832" textLength="3.343700" font-size="8px">x</text>
<text x="150.358826" y="32.139832" textLength="1.859097" font-size="8px">,</text>
<text x="140.819916" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="135.419861" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="132.119629" y="32.139832" textLength="3.343700" font-size="8px">x</text>
<text x="118.018562" y="32.139832" textLength="3.718194" font-size="8px">2</text>
<text x="113.879738" y="32.139832" textLength="4.828303" font-size="8px">H</text>
<text x="109.319603" y="32.139832" textLength="4.460495" font-size="8px">P</text>
<text x="100.618629" y="32.139832" textLength="4.460495" font-size="8px">V</text>
<text x="95.639854" y="32.139832" textLength="4.828303" font-size="8px">C</text>
<text x="353.939362" y="125.740356" textLength="3.718194" font-size="8px">1</text>
<text x="343.139191" y="125.740356" textLength="5.570604" font-size="8px">m</text>
<text x="199.323303" y="32.139832" textLength="1.859097" font-size="8px"> </text>
<text x="339.838959" y="125.740356" textLength="3.343700" font-size="8px">x</text>
<text x="374.278442" y="50.859924" textLength="3.718194" font-size="8px">6</text>
<text x="359.759399" y="50.859924" textLength="5.570604" font-size="8px">m</text>
<text x="357.658234" y="50.859924" textLength="1.859097" font-size="8px">/</text>
<text x="353.939362" y="50.859924" textLength="3.718194" font-size="8px">2</text>
<text x="343.139191" y="50.859924" textLength="5.570604" font-size="8px">m</text>
<text x="339.838959" y="50.859924" textLength="3.343700" font-size="8px">x</text>
<text x="57.054253" y="92.979980" textLength="1.859097" font-size="8px">t</text>
<text x="55.014595" y="92.979980" textLength="2.226904" font-size="8px">r</text>
<text x="44.222450" y="92.979980" textLength="3.718194" font-size="8px">n</text>
<text x="40.500237" y="92.979980" textLength="3.718194" font-size="8px">o</text>
<text x="37.200005" y="92.979980" textLength="3.343700" font-size="8px">c</text>
<text x="130.851715" y="92.979980" textLength="3.718194" font-size="8px">e</text>
<text x="127.552147" y="92.979980" textLength="3.343700" font-size="8px">v</text>
<text x="123.829933" y="92.979980" textLength="3.718194" font-size="8px">n</text>
<text x="120.107719" y="92.979980" textLength="3.718194" font-size="8px">o</text>
<text x="315.774200" y="83.619995" textLength="1.859097" font-size="8px">t</text>
<text x="313.734558" y="83.619995" textLength="2.226904" font-size="8px">r</text>
<text x="295.920013" y="83.619995" textLength="3.343700" font-size="8px">c</text>
<text x="275.991730" y="83.619995" textLength="1.859097" font-size="8px">t</text>
<text x="270.170349" y="83.619995" textLength="3.718194" font-size="8px">e</text>
<text x="263.148590" y="83.619995" textLength="3.718194" font-size="8px">n</text>
<text x="259.427063" y="83.619995" textLength="3.718194" font-size="8px">o</text>
<text x="256.080017" y="83.619995" textLength="3.343700" font-size="8px">c</text>
<text x="76.170845" y="116.379639" textLength="3.718194" font-size="8px">6</text>
<text x="70.770775" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="69.149742" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="67.468529" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="65.847496" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="64.166283" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="57.501610" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="54.199364" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="52.518150" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="45.913658" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="30.963280" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="29.282066" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="197.642090" y="32.139832" textLength="1.859097" font-size="8px"> </text>
<text x="25.979820" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="15.179665" y="116.379639" textLength="3.718194" font-size="8px">2</text>
<text x="11.460800" y="116.379639" textLength="3.718194" font-size="8px">1</text>
<text x="155.373749" y="116.379639" textLength="3.718194" font-size="8px">4</text>
<text x="151.654877" y="116.379639" textLength="3.718194" font-size="8px">6</text>
<text x="149.973663" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="146.671417" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="144.990204" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="141.687958" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="138.385712" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="136.704498" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="135.083466" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="133.402252" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="131.721039" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="130.100006" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="128.418793" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="125.116539" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="123.435326" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="121.754112" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="118.451866" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="115.149620" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="113.468407" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="111.847374" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="106.863914" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="103.501488" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="100.199242" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="98.518028" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="94.799171" y="116.379639" textLength="3.718194" font-size="8px">5</text>
<text x="91.080315" y="116.379639" textLength="3.718194" font-size="8px">9</text>
<text x="234.993286" y="116.379639" textLength="3.718194" font-size="8px">2</text>
<text x="231.274414" y="116.379639" textLength="3.718194" font-size="8px">3</text>
<text x="229.593201" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="227.911987" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="226.290955" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="214.203430" y="32.139832" textLength="3.718194" font-size="8px">8</text>
<text x="222.928528" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="221.307495" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="218.005249" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="216.324036" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="211.340576" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="209.659363" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="208.038330" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="206.357117" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="204.675903" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="203.054871" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="224.609741" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="201.373657" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="199.692444" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="198.071411" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="194.769165" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="193.087952" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="188.104492" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="186.423279" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="181.439819" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="178.137573" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="203.463470" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="170.699829" y="116.379639" textLength="3.718194" font-size="8px">6</text>
<text x="314.196167" y="116.379639" textLength="3.718194" font-size="8px">0</text>
<text x="312.514954" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="310.833740" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="309.212708" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="307.531494" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="305.850281" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="146.639954" y="32.139832" textLength="3.718194" font-size="8px">1</text>
<text x="270.598969" y="50.859985" textLength="3.718194" font-size="8px">1</text>
<text x="348.539276" y="125.740356" textLength="5.570604" font-size="8px">m</text>
<text x="105.178764" y="32.139832" textLength="4.086001" font-size="8px">T</text>
<text x="37.627953" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="304.202423" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="133.402252" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="47.944664" y="92.979980" textLength="3.343700" font-size="8px">v</text>
<text x="184.802246" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="365.159485" y="50.859924" textLength="3.718194" font-size="8px">e</text>
<text x="125.116539" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="42.611412" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="219.626282" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="264.362244" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="120.133080" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="284.295410" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="302.942444" y="83.619995" textLength="3.718194" font-size="8px">n</text>
<text x="110.166161" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="317.471588" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="377.997314" y="50.859924" textLength="3.718194" font-size="8px">4</text>
<text x="55.880577" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="287.597656" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="27.661034" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="190.978973" y="50.859985" textLength="3.718194" font-size="8px">3</text>
<text x="189.785706" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="103.501488" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="72.451988" y="116.379639" textLength="3.718194" font-size="8px">9</text>
<text x="183.121033" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="105.182701" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="24.298607" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="40.930199" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="34.265526" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="64.166283" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="42.599998" y="125.739990" textLength="4.460495" font-size="8px">V</text>
<text x="273.891876" y="83.619995" textLength="2.226904" font-size="8px">r</text>
<text x="141.687958" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="143.369171" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="267.724670" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="261.059998" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="113.468407" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="146.671417" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="32.644493" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="143.369171" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="178.137573" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="101.880455" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="35.946739" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="101.880455" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="293.818878" y="41.500000" textLength="3.718194" font-size="8px">5</text>
<text x="140.006744" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="250.319336" y="116.379639" textLength="3.718194" font-size="8px">3</text>
<text x="295.943542" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="18.958717" y="116.379639" textLength="3.718194" font-size="8px">7</text>
<text x="272.707458" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="259.438293" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="348.539276" y="50.859924" textLength="5.570604" font-size="8px">m</text>
<text x="262.741211" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="264.361572" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="49.215904" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="122.159996" y="125.739990" textLength="4.460495" font-size="8px">V</text>
<text x="192.237335" y="32.139832" textLength="3.718194" font-size="8px">4</text>
<text x="292.581116" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="196.390198" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="44.232445" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="259.438965" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="126.297554" y="32.139832" textLength="4.460495" font-size="8px">S</text>
<text x="47.160133" y="125.739990" textLength="4.460495" font-size="8px">S</text>
<text x="140.006744" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="301.260010" y="50.859985" textLength="4.460495" font-size="8px">V</text>
<text x="186.420166" y="50.859985" textLength="4.828303" font-size="8px">H</text>
<text x="136.669067" y="92.979980" textLength="1.859097" font-size="8px">t</text>
<text x="174.418701" y="41.500000" textLength="3.718194" font-size="8px">3</text>
<text x="55.880577" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="281.400024" y="125.739990" textLength="4.460495" font-size="8px">V</text>
<text x="184.802246" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="130.100006" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="300.927002" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="70.770775" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="50.897118" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="307.504669" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="174.418701" y="116.379639" textLength="3.718194" font-size="8px">3</text>
<text x="290.960083" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="309.185883" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="294.262329" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="29.282066" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="306.664642" y="83.619995" textLength="3.343700" font-size="8px">v</text>
<text x="200.109070" y="41.500000" textLength="3.718194" font-size="8px">8</text>
<text x="214.642822" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="51.292381" y="92.979980" textLength="3.718194" font-size="8px">e</text>
<text x="39.248985" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="266.040161" y="50.859985" textLength="4.828303" font-size="8px">H</text>
<text x="310.012360" y="83.619995" textLength="3.718194" font-size="8px">e</text>
<text x="25.979820" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="148.352631" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="126.737572" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="59.182823" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="224.582245" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="266.043457" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="126.737572" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="106.863914" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="319.152802" y="41.500000" textLength="3.718194" font-size="8px">0</text>
<text x="30.963280" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="297.564575" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="152.040039" y="32.139832" textLength="1.859097" font-size="8px"> </text>
<text x="210.900299" y="125.739990" textLength="3.718194" font-size="8px">1</text>
<text x="157.430084" y="32.139832" textLength="5.570604" font-size="8px">m</text>
<text x="108.484947" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="50.897118" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="310.439148" y="50.859985" textLength="3.718194" font-size="8px">0</text>
<text x="131.721039" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="274.329163" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="32.644493" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="115.149620" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="118.451866" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="22.677582" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="368.878357" y="50.859924" textLength="5.570604" font-size="8px">m</text>
<text x="94.799171" y="41.500000" textLength="3.718194" font-size="8px">5</text>
<text x="91.079720" y="32.139832" textLength="4.460495" font-size="8px">V</text>
<text x="213.021790" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="116.770653" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="24.298607" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="60.864037" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="271.026917" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="155.373749" y="41.500000" textLength="3.718194" font-size="8px">4</text>
<text x="254.038879" y="41.500000" textLength="3.718194" font-size="8px">1</text>
<text x="120.133080" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="60.864037" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="40.930199" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="221.279999" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="299.220245" y="83.619995" textLength="3.718194" font-size="8px">o</text>
<text x="121.754112" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="302.521210" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="123.435326" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="300.900177" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="266.870117" y="83.619995" textLength="3.343700" font-size="8px">v</text>
<text x="250.320007" y="41.500000" textLength="3.718194" font-size="8px">3</text>
<text x="299.218964" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="257.757751" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="134.630096" y="92.979980" textLength="2.226904" font-size="8px">r</text>
<text x="149.973663" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="148.352631" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="128.418793" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="65.847496" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="181.860016" y="50.859985" textLength="4.460495" font-size="8px">V</text>
<text x="257.757080" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="231.246918" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="131.280273" y="125.739990" textLength="3.718194" font-size="8px">2</text>
<text x="271.026245" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="51.720268" y="125.739990" textLength="3.718194" font-size="8px">3</text>
<text x="42.611412" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="144.990204" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="193.087952" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="226.260162" y="50.859985" textLength="4.828303" font-size="8px">H</text>
<text x="267.723999" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="62.485069" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="299.245789" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="135.083466" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="221.700012" y="50.859985" textLength="4.460495" font-size="8px">V</text>
<text x="121.737419" y="32.139832" textLength="4.460495" font-size="8px">P</text>
<text x="179.818787" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="47.534691" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="305.820160" y="50.859985" textLength="4.828303" font-size="8px">H</text>
<text x="206.340149" y="125.739990" textLength="4.460495" font-size="8px">S</text>
<text x="52.518150" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="130.857697" y="32.139832" textLength="1.859097" font-size="8px"> </text>
<text x="191.406738" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="22.677582" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="191.406738" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="261.480011" y="50.859985" textLength="4.460495" font-size="8px">V</text>
<text x="290.100006" y="41.500000" textLength="3.718194" font-size="8px">1</text>
<text x="116.770653" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="297.537750" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="305.823456" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="116.760002" y="92.979980" textLength="3.343700" font-size="8px">c</text>
<text x="310.806915" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="312.488129" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="314.169342" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="126.720131" y="125.739990" textLength="4.460495" font-size="8px">S</text>
<text x="315.790375" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="269.345703" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="272.708130" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="276.010376" y="41.500000" textLength="3.718194" font-size="8px">1</text>
<text x="279.729248" y="41.500000" textLength="3.718194" font-size="8px">6</text>
<text x="210.479828" y="41.500000" textLength="3.718194" font-size="8px">4</text>
<text x="214.198700" y="41.500000" textLength="3.718194" font-size="8px">7</text>
<text x="217.977753" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="219.598785" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="222.901031" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="226.263458" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="227.884491" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="229.565704" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="232.867950" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="234.549164" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="230.818970" y="50.859985" textLength="3.718194" font-size="8px">2</text>
<text x="108.484947" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="236.230377" y="41.500000" textLength="3.718194" font-size="8px">3</text>
<text x="239.949249" y="41.500000" textLength="3.718194" font-size="8px">2</text>
<text x="170.699829" y="41.500000" textLength="3.718194" font-size="8px">6</text>
<text x="179.818787" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="181.439819" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="183.121033" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="186.423279" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="189.785706" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="194.769165" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="196.390198" y="41.500000" textLength="3.718194" font-size="8px">4</text>
<text x="91.080315" y="41.500000" textLength="3.718194" font-size="8px">9</text>
<text x="98.518028" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="100.199242" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="105.182701" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="110.166161" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="111.847374" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="136.704498" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="49.215904" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="138.385712" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="151.654877" y="41.500000" textLength="3.718194" font-size="8px">6</text>
<text x="11.460800" y="41.500000" textLength="3.718194" font-size="8px">1</text>
<text x="34.265526" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="54.199364" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="15.179665" y="41.500000" textLength="3.718194" font-size="8px">2</text>
<text x="45.913658" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="18.958717" y="41.500000" textLength="3.718194" font-size="8px">7</text>
<text x="27.661034" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="37.627953" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="35.946739" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="39.248985" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="44.232445" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="47.534691" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="188.104492" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="57.501610" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="59.182823" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="62.485069" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="67.468529" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="69.149742" y="41.500000" textLength="1.859097" font-size="8px"> </text>
<text x="72.451988" y="41.500000" textLength="3.718194" font-size="8px">9</text>
<text x="76.170845" y="41.500000" textLength="3.718194" font-size="8px">6</text>
<text x="285.960175" y="125.739990" textLength="4.460495" font-size="8px">S</text>
<text x="290.520325" y="125.739990" textLength="3.718194" font-size="8px">0</text>
<text x="201.779999" y="125.739990" textLength="4.460495" font-size="8px">V</text>
<text x="254.038208" y="116.379639" textLength="3.718194" font-size="8px">1</text>
<text x="261.059326" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="262.740540" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="266.042786" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="269.345032" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="274.328491" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="276.009705" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="277.690918" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="279.311951" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="280.993164" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="282.674377" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="285.976624" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="289.278870" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="302.548035" y="116.379639" textLength="1.859097" font-size="8px"> </text>
<text x="304.229248" y="116.379639" textLength="1.859097" font-size="8px"> </text>
</svg>
<figcaption>Figure 5-6.  VCVTPH2PS (128-bit Version)
</figcaption></figure>
```

### Operation
#### VCVTPH2PS (EVEX encoded versions) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i  <-  j * 32
    k <-   j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i]  <-
                vCvt_h2s(SRC[k+15:k])
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
#### VCVTPH2PS (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  vCvt_h2s(SRC1[15:0]);
DEST[63:32] <-  vCvt_h2s(SRC1[31:16]);
DEST[95:64]  <- vCvt_h2s(SRC1[47:32]);
DEST[127:96] <-  vCvt_h2s(SRC1[63:48]);
DEST[159:128] <-  vCvt_h2s(SRC1[79:64]);
DEST[191:160]  <- vCvt_h2s(SRC1[95:80]);
DEST[223:192] <-  vCvt_h2s(SRC1[111:96]);
DEST[255:224]  <- vCvt_h2s(SRC1[127:112]);
DEST[MAX_VL-1:256] <-   0
```
#### VCVTPH2PS (VEX.128 encoded version) 
```info-verb
DEST[31:0]  <- vCvt_h2s(SRC1[15:0]);
DEST[63:32] <-  vCvt_h2s(SRC1[31:16]);
DEST[95:64] <-  vCvt_h2s(SRC1[47:32]);
DEST[127:96]  <- vCvt_h2s(SRC1[63:48]);
DEST[MAX_VL-1:128]  <-  0
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTPH2PS __m512 _mm512_cvtph_ps( __m256i a);
VCVTPH2PS __m512 _mm512_mask_cvtph_ps(__m512 s, __mmask16 k, __m256i a);
VCVTPH2PS __m512 _mm512_maskz_cvtph_ps(__mmask16 k, __m256i a);
VCVTPH2PS __m512 _mm512_cvt_roundph_ps( __m256i a, int sae);
VCVTPH2PS __m512 _mm512_mask_cvt_roundph_ps(__m512 s, __mmask16 k, __m256i a, int sae);
VCVTPH2PS __m512 _mm512_maskz_cvt_roundph_ps( __mmask16 k, __m256i a, int sae);
VCVTPH2PS __m256 _mm256_mask_cvtph_ps(__m256 s, __mmask8 k, __m128i a);
VCVTPH2PS __m256 _mm256_maskz_cvtph_ps(__mmask8 k, __m128i a);
VCVTPH2PS __m128 _mm_mask_cvtph_ps(__m128 s, __mmask8 k, __m128i a);
VCVTPH2PS __m128 _mm_maskz_cvtph_ps(__mmask8 k, __m128i a);
VCVTPH2PS __m128 _mm_cvtph_ps ( __m128i m1);
VCVTPH2PS __m256 _mm256_cvtph_ps ( __m128i m1)
```
### SIMD Floating-Point Exceptions


Invalid

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 11 (do not report #AC); 

EVEX-encoded instructions, see Exceptions Type E11.

#UD If VEX.W=1.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

