----------------------------
title : VGETEXPPS (Intel x86/64 assembly instruction)
cat_title : VGETEXPPS
ref_title : VGETEXPPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VGETEXPPS

**Convert Exponents of Packed SP FP Values to SP FP Values**

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W0 42 /r\newline{}VGETEXPPS xmm1 {k1}{z}, xmm2/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Convert the exponent of packed single-precision floating-point values in the source operand to SP FP results representing unbiased integer exponents and stores the results in the destination register.|
|EVEX.256.66.0F38.W0 42 /r\newline{}VGETEXPPS ymm1 {k1}{z}, ymm2/m256/m32bcst|FV|V/V|AVX512VL\newline{}AVX512F|Convert the exponent of packed single-precision floating-point values in the source operand to SP FP results representing unbiased integer exponents and stores the results in the destination register.|
|EVEX.512.66.0F38.W0 42 /r\newline{}VGETEXPPS zmm1 {k1}{z}, zmm2/m512/m32bcst{sae}|FV|V/V|AVX512F|Convert the exponent of packed single-precision floating-point values in the source operand to SP FP results representing unbiased integer exponents and stores the results in the destination register.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Extracts the biased exponents from the normalized SP FP representation of each dword element of the source operand (the second operand) as unbiased signed integer value, or convert the denormal representation of input data to unbiased negative integer values. Each integer value of the unbiased exponent is converted to single-preci-sion FP value and written to the corresponding dword elements of the destination operand (the first operand) as SP FP numbers. 

The destination operand is a ZMM/YMM/XMM register and updated under the writemask. The source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 32-bit memory location.

EVEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.

Each GETEXP operation converts the exponent value into a FP number (permitting input value in denormal repre-sentation). Special cases of input values are listed in Table 5-8.

The formula is:

GETEXP(x) = floor(log2(|x|)) 

Notation floor(x) stands for maximal integer not exceeding real number x. 

Software usage of VGETEXPxx and VGETMANTxx instructions generally involve a combination of GETEXP operation and GETMANT operation (see VGETMANTPD). Thus VGETEXPxx instruction do not require software to handle SIMD FP exceptions.

### Table 5-8. VGETEXPPS/SS Special Cases


|**Input Operand**|**Result**|**Comments**|
|-----------------|----------|------------|
|src1 = NaN|QNaN(src1)|No Exceptions|
|0 < |src1| < INF|floor(log2(|src1|)) ||
|| src1| = +INF|+INF||
|| src1| = 0|-INF||


Figure 5-14 illustrates the VGETEXPPS functionality on input values with normalized representation.

```embed
<figure>
<svg viewBox="0 0 493.860016 152.179993">
<rect x="0.000000" y="10.060059" width="0.480000" height="126.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="493.379974" y="10.060059" width="0.480040" height="126.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="493.859985" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="136.059998" width="493.859985" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="62.760002" y="24.760010" width="368.279999" height="103.559998" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.480011" y="25.239990" width="9.840000" height="17.459999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="138.839996" y="25.239990" width="75.660004" height="17.459999" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<rect x="214.019989" y="25.239990" width="216.539993" height="17.459999" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<rect x="138.839996" y="42.160156" width="75.660004" height="8.999900" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<path d="M354.959991,59.140015 L430.559998,59.140015 L430.559998,68.080017 L354.959991,68.080017" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<rect x="129.480011" y="76.059998" width="225.960007" height="8.940000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M354.959991,76.060059 L430.559998,76.060059 L430.559998,85.000061 L354.959991,85.000061" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<rect x="129.480011" y="92.979919" width="291.720001" height="8.940100" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="420.720001" y="92.979919" width="9.840000" height="8.940100" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<rect x="129.480011" y="109.900024" width="9.840000" height="8.940000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="138.839996" y="109.900024" width="75.660004" height="8.940000" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<rect x="214.019989" y="109.900024" width="216.539993" height="8.940000" fill-rule="nonzero"  fill=" rgb(204,204,204) " stroke="black" />
<path d="M62.760002,24.760010 L62.760002,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M129.480011,24.760010 L129.480011,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M138.839996,24.760010 L138.839996,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M148.260010,24.760010 L148.260010,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M157.679993,24.760010 L157.679993,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M167.040009,24.760010 L167.040009,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M176.459991,24.760010 L176.459991,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M185.820007,24.760010 L185.820007,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M195.239990,24.760010 L195.239990,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M204.600006,24.760010 L204.600006,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M214.019989,24.760010 L214.019989,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M223.440002,24.760010 L223.440002,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M232.799988,24.760010 L232.799988,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M242.220001,24.760010 L242.220001,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M251.579987,24.760010 L251.579987,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M261.000000,24.760010 L261.000000,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M270.359985,24.760010 L270.359985,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M279.779999,24.760010 L279.779999,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M289.199982,24.760010 L289.199982,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M298.559998,24.760010 L298.559998,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M307.979980,24.760010 L307.979980,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M317.339996,24.760010 L317.339996,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M326.759979,24.760010 L326.759979,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M336.179993,24.760010 L336.179993,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M345.539978,24.760010 L345.539978,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M354.959991,24.760010 L354.959991,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M364.319977,24.760010 L364.319977,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M373.739990,24.760010 L373.739990,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M383.100006,24.760010 L383.100006,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M392.519989,24.760010 L392.519989,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M401.940002,24.760010 L401.940002,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M411.299988,24.760010 L411.299988,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M420.720001,24.760010 L420.720001,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="24.760071" width="367.320007" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M430.079987,24.760010 L430.079987,24.280029" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<path d="M63.239998,33.220032 L129.000000,33.220032" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="33.220032" width="65.760002" height="0.479980" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,33.220032 L138.420013,33.220032" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="33.220032" width="8.460000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,33.220032 L213.540009,33.220032" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="33.220032" width="74.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,33.220032 L429.660004,33.220032" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="33.220032" width="215.160004" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,42.160034 L129.000000,42.160034" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="42.160095" width="65.760002" height="0.539920" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M148.260010,25.240051 L148.260010,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="148.260010" y="25.239990" width="0.480000" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M157.679993,25.240051 L157.679993,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="157.679993" y="25.239990" width="0.420010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M167.040009,25.240051 L167.040009,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="167.040009" y="25.239990" width="0.480000" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M176.459991,25.240051 L176.459991,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="176.459991" y="25.239990" width="0.420000" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M185.820007,25.240051 L185.820007,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="185.820007" y="25.239990" width="0.480000" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.239990,25.240051 L195.239990,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="195.239990" y="25.239990" width="0.480000" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.600006,25.240051 L204.600006,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="204.600006" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.440002,25.240051 L223.440002,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="223.440002" y="25.239990" width="0.419980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M232.799988,25.240051 L232.799988,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="232.799988" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M242.220001,25.240051 L242.220001,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="242.220001" y="25.239990" width="0.479980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M251.579987,25.240051 L251.579987,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="251.579987" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M261.000000,25.240051 L261.000000,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="261.000000" y="25.239990" width="0.479980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.359985,25.240051 L270.359985,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="270.359985" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M279.779999,25.240051 L279.779999,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="279.779999" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M289.199982,25.240051 L289.199982,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="289.199982" y="25.239990" width="0.420010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M298.559998,25.240051 L298.559998,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="298.559998" y="25.239990" width="0.479980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.979980,25.240051 L307.979980,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="307.979980" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M317.339996,25.240051 L317.339996,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="317.339996" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M326.759979,25.240051 L326.759979,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="326.759979" y="25.239990" width="0.479980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.179993,25.240051 L336.179993,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="336.179993" y="25.239990" width="0.420010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M345.539978,25.240051 L345.539978,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="345.539978" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M354.959991,25.240051 L354.959991,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="354.959991" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M364.319977,25.240051 L364.319977,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="364.319977" y="25.239990" width="0.479980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M373.739990,25.240051 L373.739990,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="373.739990" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M383.100006,25.240051 L383.100006,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="383.100006" y="25.239990" width="0.480040" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M392.519989,25.240051 L392.519989,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="392.519989" y="25.239990" width="0.479980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M401.940002,25.240051 L401.940002,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="401.940002" y="25.239990" width="0.419980" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M411.299988,25.240051 L411.299988,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="411.299988" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M420.720001,25.240051 L420.720001,33.700073" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="420.720001" y="25.239990" width="0.480010" height="8.460000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.959991" y="41.679993" width="300.600006" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,50.680054 L129.000000,50.680054" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="50.680054" width="65.760002" height="0.479980" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,50.680054 L138.420013,50.680054" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="50.680054" width="8.460000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,50.680054 L213.540009,50.680054" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="50.680054" width="74.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,50.680054 L429.660004,50.680054" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="50.680054" width="215.160004" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,59.140015 L129.000000,59.140015" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="59.140076" width="65.760002" height="0.479980" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,59.140015 L138.420013,59.140015" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="59.140076" width="8.460000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,59.140015 L213.540009,59.140015" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="59.140076" width="74.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,59.140015 L429.660004,59.140015" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="59.140076" width="215.160004" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,67.600037 L129.000000,67.600037" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="67.599976" width="65.760002" height="0.480040" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,67.600037 L138.420013,67.600037" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="67.599976" width="8.460000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,67.600037 L213.540009,67.600037" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="67.599976" width="74.220001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,67.600037 L429.660004,67.600037" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="67.599976" width="215.160004" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,76.060059 L129.000000,76.060059" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="76.059998" width="65.760002" height="0.480040" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,76.060059 L138.420013,76.060059" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="76.059998" width="8.460000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,76.060059 L213.540009,76.060059" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="76.059998" width="74.220001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,76.060059 L429.660004,76.060059" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="76.059998" width="215.160004" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,84.520020 L129.000000,84.520020" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="84.520020" width="65.760002" height="0.479980" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,84.520020 L138.420013,84.520020" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="84.520020" width="8.460000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,84.520020 L213.540009,84.520020" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="84.520020" width="74.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,84.520020 L429.660004,84.520020" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="84.520020" width="215.160004" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,92.980042 L129.000000,92.980042" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="92.979980" width="65.760002" height="0.480040" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,92.980042 L138.420013,92.980042" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="92.979980" width="8.460000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,92.980042 L213.540009,92.980042" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="92.979980" width="74.220001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,92.980042 L429.660004,92.980042" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="92.979980" width="215.160004" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,101.440002 L129.000000,101.440002" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="101.440002" width="65.760002" height="0.480040" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,101.440002 L138.420013,101.440002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="101.440002" width="8.460000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,101.440002 L213.540009,101.440002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="101.440002" width="74.220001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,101.440002 L429.660004,101.440002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="101.440002" width="215.160004" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,109.900024 L129.000000,109.900024" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="109.900024" width="65.760002" height="0.479980" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,109.900024 L138.420013,109.900024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="109.900024" width="8.460000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,109.900024 L213.540009,109.900024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="109.900024" width="74.220001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,109.900024 L429.660004,109.900024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="109.900024" width="215.160004" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M63.239998,118.360046 L129.000000,118.360046" stoke="black"  stroke=" rgb(193,193,193) " fill="white" fill-opacity="0" />
<rect x="63.239998" y="118.359985" width="65.760002" height="0.480040" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<path d="M129.959991,118.360046 L138.420013,118.360046" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="129.959991" y="118.359985" width="8.460000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.320007,118.360046 L213.540009,118.360046" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="139.320007" y="118.359985" width="74.220001" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.500000,118.360046 L429.660004,118.360046" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="214.500000" y="118.359985" width="215.160004" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="62.760002" y="24.760010" width="0.480010" height="103.080002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.000000" y="25.240051" width="0.959990" height="102.599998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="138.420013" y="25.240051" width="0.899990" height="102.599998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.260010,42.700012 L148.260010,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="148.260010" y="42.700012" width="0.480000" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M157.679993,42.700012 L157.679993,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="157.679993" y="42.700012" width="0.420010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M167.040009,42.700012 L167.040009,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="167.040009" y="42.700012" width="0.480000" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M176.459991,42.700012 L176.459991,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="176.459991" y="42.700012" width="0.420000" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M185.820007,42.700012 L185.820007,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="185.820007" y="42.700012" width="0.480000" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.239990,42.700012 L195.239990,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="195.239990" y="42.700012" width="0.480000" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.600006,42.700012 L204.600006,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="204.600006" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.539978" y="25.240051" width="0.960020" height="102.599998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.440002,42.700012 L223.440002,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="223.440002" y="42.700012" width="0.419980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M232.799988,42.700012 L232.799988,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="232.799988" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M242.220001,42.700012 L242.220001,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="242.220001" y="42.700012" width="0.479980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M251.579987,42.700012 L251.579987,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="251.579987" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M261.000000,42.700012 L261.000000,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="261.000000" y="42.700012" width="0.479980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.359985,42.700012 L270.359985,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="270.359985" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M279.779999,42.700012 L279.779999,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="279.779999" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M289.199982,42.700012 L289.199982,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="289.199982" y="42.700012" width="0.420010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M298.559998,42.700012 L298.559998,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="298.559998" y="42.700012" width="0.479980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.979980,42.700012 L307.979980,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="307.979980" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M317.339996,42.700012 L317.339996,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="317.339996" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M326.759979,42.700012 L326.759979,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="326.759979" y="42.700012" width="0.479980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.179993,42.700012 L336.179993,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="336.179993" y="42.700012" width="0.420010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M345.539978,42.700012 L345.539978,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="345.539978" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M354.959991,42.700012 L354.959991,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="354.959991" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M364.319977,42.700012 L364.319977,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="364.319977" y="42.700012" width="0.479980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M373.739990,42.700012 L373.739990,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="373.739990" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M383.100006,42.700012 L383.100006,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="383.100006" y="42.700012" width="0.480040" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M392.519989,42.700012 L392.519989,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="392.519989" y="42.700012" width="0.479980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M401.940002,42.700012 L401.940002,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="401.940002" y="42.700012" width="0.419980" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M411.299988,42.700012 L411.299988,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="411.299988" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M420.720001,42.700012 L420.720001,126.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="420.720001" y="42.700012" width="0.480010" height="84.120003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="63.239998" y="126.820007" width="367.320007" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="429.660004" y="25.240051" width="0.899990" height="102.599998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="326.755737" y="39.519531" textLength="3.598710" font-size="8px">o</text>
<text x="323.456055" y="39.519531" textLength="1.799355" font-size="8px">t</text>
<text x="320.156372" y="39.519531" textLength="3.236250" font-size="8px">c</text>
<text x="314.997803" y="39.519531" textLength="2.155343" font-size="8px">r</text>
<text x="311.276764" y="39.519531" textLength="3.954697" font-size="8px">F</text>
<text x="178.318054" y="39.519531" textLength="3.598710" font-size="8px">p</text>
<text x="425.841949" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="407.063934" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="397.645142" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="388.285919" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="360.089111" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="350.670319" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="341.311096" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="322.533081" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="303.695496" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="294.336273" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="247.361450" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="237.942657" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="228.583435" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="219.164642" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="190.967865" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="181.608643" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="134.633820" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="120.054527" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="117.716011" y="116.199219" textLength="3.035603" font-size="8px">^</text>
<text x="114.416328" y="116.199219" textLength="3.598710" font-size="8px">2</text>
<text x="108.775551" y="116.199219" textLength="3.779940" font-size="8px">=</text>
<text x="106.914711" y="116.199219" textLength="1.799355" font-size="8px"> </text>
<text x="105.058403" y="116.199219" textLength="2.155343" font-size="8px">)</text>
<text x="101.758720" y="116.199219" textLength="3.598710" font-size="8px">h</text>
<text x="89.038963" y="116.199219" textLength="4.317157" font-size="8px">S</text>
<text x="84.838951" y="116.199219" textLength="4.317157" font-size="8px">P</text>
<text x="81.539268" y="116.199219" textLength="3.598710" font-size="8px">2</text>
<text x="80.158043" y="116.199219" textLength="1.799355" font-size="8px">I</text>
<text x="72.598824" y="116.199219" textLength="3.598710" font-size="8px">_</text>
<text x="70.737984" y="116.199219" textLength="1.799355" font-size="8px">t</text>
<text x="68.398178" y="116.199219" textLength="3.236250" font-size="8px">v</text>
<text x="64.199471" y="116.199219" textLength="4.673145" font-size="8px">C</text>
<text x="425.847809" y="99.279480" textLength="3.598710" font-size="8px">1</text>
<text x="416.429016" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="407.069794" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="397.651001" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="378.872986" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="360.094971" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="350.676178" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="322.538940" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="313.120148" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="294.342133" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="284.923340" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="256.726532" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="247.367310" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="237.948517" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="228.589294" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="200.392487" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="181.614471" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="172.195709" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="143.998901" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="95.639626" y="99.279480" textLength="3.779940" font-size="8px">=</text>
<text x="93.778786" y="99.279480" textLength="1.799355" font-size="8px"> </text>
<text x="90.479103" y="99.279480" textLength="3.236250" font-size="8px">s</text>
<text x="77.820198" y="99.279480" textLength="2.155343" font-size="8px">-</text>
<text x="64.199471" y="99.279480" textLength="3.954697" font-size="8px">T</text>
<text x="416.427094" y="82.359741" textLength="3.598710" font-size="8px">0</text>
<text x="397.649078" y="82.359741" textLength="3.598710" font-size="8px">0</text>
<text x="388.289856" y="82.359741" textLength="3.598710" font-size="8px">0</text>
<text x="369.452271" y="82.359741" textLength="3.598710" font-size="8px">0</text>
<text x="341.315033" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="331.896240" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="322.537018" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="313.118225" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="284.921417" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="275.562195" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="256.724609" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="237.946594" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="219.168579" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="209.809357" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="200.390564" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="181.612549" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="172.193787" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="162.834534" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="143.996979" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="74.997536" y="82.359741" textLength="3.236250" font-size="8px">s</text>
<text x="81.541237" y="99.279480" textLength="4.317157" font-size="8px">B</text>
<text x="71.698509" y="82.359741" textLength="3.598710" font-size="8px">a</text>
<text x="266.139465" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="70.259674" y="82.359741" textLength="1.436895" font-size="8px">i</text>
<text x="66.059669" y="82.359741" textLength="4.317157" font-size="8px">B</text>
<text x="64.199471" y="82.359741" textLength="2.155343" font-size="8px">-</text>
<text x="425.845825" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="416.427032" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="407.067810" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="397.649017" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="350.674194" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="331.896179" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="322.536957" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="294.340149" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="284.921356" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="275.562134" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="256.724548" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="228.587311" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="219.168518" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="209.809296" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="200.390503" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="190.971741" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="181.612488" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="172.193726" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="162.834473" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="153.415710" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="143.996918" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="112.559349" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="109.260323" y="65.440002" textLength="3.598710" font-size="8px">8</text>
<text x="105.961296" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="100.320518" y="65.440002" textLength="3.779940" font-size="8px">=</text>
<text x="98.459679" y="65.440002" textLength="1.799355" font-size="8px"> </text>
<text x="95.160652" y="65.440002" textLength="3.598710" font-size="8px">3</text>
<text x="90.000786" y="65.440002" textLength="1.799355" font-size="8px"> </text>
<text x="88.139946" y="65.440002" textLength="1.799355" font-size="8px">,</text>
<text x="84.839622" y="65.440002" textLength="3.236250" font-size="8px">c</text>
<text x="82.979424" y="65.440002" textLength="2.155343" font-size="8px">r</text>
<text x="75.899162" y="99.279480" textLength="1.799355" font-size="8px"> </text>
<text x="78.719231" y="65.440002" textLength="4.317157" font-size="8px">S</text>
<text x="68.399475" y="65.440002" textLength="4.317157" font-size="8px">A</text>
<text x="407.067841" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="388.289825" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="303.699432" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="360.093018" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="350.674225" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="341.315002" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="294.340179" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="284.921387" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="275.562164" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="266.143372" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="256.724579" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="247.365356" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="228.587341" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="219.168549" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="209.809326" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="200.390533" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="322.536987" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="190.971771" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="162.834503" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="378.871002" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="153.415741" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="143.996948" y="48.520264" textLength="3.598710" font-size="8px">1</text>
<text x="84.359993" y="48.520264" textLength="3.035603" font-size="8px">^</text>
<text x="81.060966" y="48.520264" textLength="3.598710" font-size="8px">2</text>
<text x="75.420189" y="48.520264" textLength="3.779940" font-size="8px">=</text>
<text x="303.699402" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="73.559349" y="48.520264" textLength="1.799355" font-size="8px"> </text>
<text x="70.259674" y="48.520264" textLength="3.236250" font-size="8px">c</text>
<text x="68.399475" y="48.520264" textLength="2.155343" font-size="8px">r</text>
<text x="130.859741" y="39.520264" textLength="3.236250" font-size="8px">s</text>
<text x="425.827820" y="31.060059" textLength="3.598710" font-size="8px">0</text>
<text x="416.409027" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="407.049805" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="397.631012" y="31.060059" textLength="3.598710" font-size="8px">3</text>
<text x="388.271790" y="31.060059" textLength="3.598710" font-size="8px">4</text>
<text x="378.852997" y="31.060059" textLength="3.598710" font-size="8px">5</text>
<text x="360.074982" y="31.060059" textLength="3.598710" font-size="8px">7</text>
<text x="350.656189" y="31.060059" textLength="3.598710" font-size="8px">8</text>
<text x="331.878174" y="31.060059" textLength="3.598710" font-size="8px">0</text>
<text x="328.579132" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="322.520233" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="319.221191" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="309.803040" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="303.683929" y="31.060059" textLength="3.598710" font-size="8px">3</text>
<text x="294.325989" y="31.060059" textLength="3.598710" font-size="8px">4</text>
<text x="291.026947" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="284.907837" y="31.060059" textLength="3.598710" font-size="8px">5</text>
<text x="281.608795" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="275.549896" y="31.060059" textLength="3.598710" font-size="8px">6</text>
<text x="272.250854" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="247.355652" y="31.060059" textLength="3.598710" font-size="8px">9</text>
<text x="237.937500" y="31.060059" textLength="3.598710" font-size="8px">0</text>
<text x="303.699371" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="228.579559" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="225.280518" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="219.161407" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="215.862366" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="209.803467" y="31.060059" textLength="3.598710" font-size="8px">3</text>
<text x="101.280403" y="99.279480" textLength="3.598710" font-size="8px">1</text>
<text x="200.385345" y="31.060059" textLength="3.598710" font-size="8px">4</text>
<text x="197.086304" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="190.967224" y="31.060059" textLength="3.598710" font-size="8px">5</text>
<text x="181.609283" y="31.060059" textLength="3.598710" font-size="8px">6</text>
<text x="178.310242" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="172.191162" y="31.060059" textLength="3.598710" font-size="8px">7</text>
<text x="168.892120" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="162.833221" y="31.060059" textLength="3.598710" font-size="8px">8</text>
<text x="153.415100" y="31.060059" textLength="3.598710" font-size="8px">9</text>
<text x="150.116058" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="143.996979" y="31.060059" textLength="3.598710" font-size="8px">0</text>
<text x="140.758118" y="31.060059" textLength="3.598710" font-size="8px">3</text>
<text x="262.832703" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="303.701355" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="284.917480" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="75.897850" y="116.199219" textLength="4.317157" font-size="8px">P</text>
<text x="175.018372" y="39.519531" textLength="3.236250" font-size="8px">x</text>
<text x="98.459038" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="67.440254" y="99.279480" textLength="5.391593" font-size="8px">m</text>
<text x="187.728363" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="416.423157" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="388.291779" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="95.159355" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="378.871033" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="313.114288" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="93.299156" y="116.199219" textLength="2.155343" font-size="8px">(</text>
<text x="331.892303" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="330.054779" y="39.519531" textLength="3.598710" font-size="8px">n</text>
<text x="153.411835" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="134.637726" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="331.898163" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="143.993073" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="378.867126" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="388.289795" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="294.340210" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="228.587372" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="266.143402" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="91.861626" y="65.440002" textLength="3.598710" font-size="8px">2</text>
<text x="64.199471" y="65.440002" textLength="4.317157" font-size="8px">S</text>
<text x="341.314972" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="104.100456" y="65.440002" textLength="1.799355" font-size="8px"> </text>
<text x="253.474762" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="64.199471" y="48.520264" textLength="4.317157" font-size="8px">S</text>
<text x="134.637756" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="325.316895" y="39.519531" textLength="1.436895" font-size="8px">i</text>
<text x="206.504425" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="369.452209" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="256.720673" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="234.638458" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="425.845886" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="209.805420" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="266.145325" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="87.180077" y="99.279480" textLength="3.598710" font-size="8px">a</text>
<text x="425.845856" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="275.564117" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="300.445099" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="341.316956" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="190.971802" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="369.454193" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="79.680397" y="99.279480" textLength="1.799355" font-size="8px"> </text>
<text x="172.189850" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="181.612518" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="313.118164" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="79.200127" y="48.520264" textLength="1.799355" font-size="8px"> </text>
<text x="369.448334" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="378.871063" y="82.359741" textLength="3.598710" font-size="8px">0</text>
<text x="275.558258" y="116.199219" textLength="3.598710" font-size="8px">0</text>
<text x="360.093048" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="162.836456" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="369.452240" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="313.118195" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="115.858376" y="65.440002" textLength="3.598710" font-size="8px">h</text>
<text x="162.830627" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="219.170502" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="237.946564" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="266.131744" y="31.060059" textLength="3.598710" font-size="8px">7</text>
<text x="247.365326" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="171.719330" y="39.519531" textLength="3.598710" font-size="8px">e</text>
<text x="341.296967" y="31.060059" textLength="3.598710" font-size="8px">9</text>
<text x="112.555489" y="116.199219" textLength="1.799355" font-size="8px"> </text>
<text x="76.858391" y="65.440002" textLength="1.799355" font-size="8px"> </text>
<text x="244.056610" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="72.600128" y="99.279480" textLength="3.598710" font-size="8px">p</text>
<text x="72.599480" y="65.440002" textLength="4.673145" font-size="8px">R</text>
<text x="416.427063" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="153.415771" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="360.092987" y="65.440002" textLength="3.598710" font-size="8px">1</text>
<text x="266.143341" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="134.639679" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="190.973724" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="172.193756" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="316.917542" y="39.519531" textLength="3.598710" font-size="8px">a</text>
<text x="153.417694" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="134.639038" y="31.060059" textLength="3.598710" font-size="8px">1</text>
<text x="369.434204" y="31.060059" textLength="3.598710" font-size="8px">6</text>
<text x="159.534180" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="237.946533" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="331.896210" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="350.674255" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="86.698509" y="48.520264" textLength="3.598710" font-size="8px">1</text>
<text x="131.339996" y="31.060059" textLength="3.598710" font-size="8px">3</text>
<text x="209.811279" y="99.279480" textLength="3.598710" font-size="8px">0</text>
<text x="407.067871" y="82.359741" textLength="3.598710" font-size="8px">0</text>
<text x="256.713593" y="31.060059" textLength="3.598710" font-size="8px">8</text>
<text x="313.102081" y="31.060059" textLength="3.598710" font-size="8px">2</text>
<text x="397.649048" y="48.520264" textLength="3.598710" font-size="8px">0</text>
<text x="200.386658" y="116.199219" textLength="3.598710" font-size="8px">1</text>
<text x="134.637695" y="65.440002" textLength="3.598710" font-size="8px">0</text>
<text x="99.419563" y="99.279480" textLength="1.799355" font-size="8px"> </text>
<text x="247.365387" y="82.359741" textLength="3.598710" font-size="8px">1</text>
<text x="85.801430" y="99.279480" textLength="1.436895" font-size="8px">i</text>
</svg>
<figcaption>Figure 5-14.  VGETEXPPS Functionality On Normal Input values
</figcaption></figure>
```

### Operation
#### VGETEXPPS (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN
                            DEST[i+31:i] <-
                ConvertExpSPFP(SRC[31:0])
                      ELSE 
                            DEST[i+31:i] <-
                ConvertExpSPFP(SRC[i+31:i])
                FI;
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

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VGETEXPPS __m512 _mm512_getexp_ps( __m512 a);
VGETEXPPS __m512 _mm512_mask_getexp_ps(__m512 s, __mmask16 k, __m512 a);
VGETEXPPS __m512 _mm512_maskz_getexp_ps( __mmask16 k, __m512 a);
VGETEXPPS __m512 _mm512_getexp_round_ps( __m512 a, int sae);
VGETEXPPS __m512 _mm512_mask_getexp_round_ps(__m512 s, __mmask16 k, __m512 a, int sae);
VGETEXPPS __m512 _mm512_maskz_getexp_round_ps( __mmask16 k, __m512 a, int sae);
VGETEXPPS __m256 _mm256_getexp_ps(__m256 a);
VGETEXPPS __m256 _mm256_mask_getexp_ps(__m256 s, __mmask8 k, __m256 a);
VGETEXPPS __m256 _mm256_maskz_getexp_ps( __mmask8 k, __m256 a);
VGETEXPPS __m128 _mm_getexp_ps(__m128 a);
VGETEXPPS __m128 _mm_mask_getexp_ps(__m128 s, __mmask8 k, __m128 a);
VGETEXPPS __m128 _mm_maskz_getexp_ps( __mmask8 k, __m128 a);
```
### SIMD Floating-Point Exceptions


Invalid, Denormal

### Other Exceptions


See Exceptions Type E2.

#UD If EVEX.vvvv != 1111B.

