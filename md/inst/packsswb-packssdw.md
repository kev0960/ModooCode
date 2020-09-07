----------------------------
title : PACKSSWB, PACKSSDWs (Intel x86/64 assembly instruction)
cat_title : PACKSSWB, PACKSSDW
ref_title : PACKSSWB, PACKSSDW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PACKSSWB, PACKSSDW

**Pack with Signed Saturation**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|------------------------------------|---------------|
|0F 63 /r\footnote{1}\newline{}\newline{}PACKSSWB mm1, mm2/m64|RM|V/V |MMX|Converts 4 packed signed word integers from mm1 and from mm2/m64 into 8 packed signed byte integers in mm1 using signed saturation.|
|66 0F 63 /r\newline{}\newline{}PACKSSWB xmm1, xmm2/m128|RM|V/V|SSE2|Converts 8 packed signed word integers from xmm1 and from xxm2/m128 into 16 packed signed byte integers in xxm1 using signed saturation.|
|0F 6B /r\footnote{1}\newline{}\newline{}PACKSSDW mm1, mm2/m64|RM|V/V|MMX|Converts 2 packed signed doubleword integers from mm1 and from mm2/m64 into 4 packed signed word integers in mm1 using signed saturation.|
|66 0F 6B /r\newline{}\newline{}PACKSSDW xmm1, xmm2/m128|RM|V/V|SSE2|Converts 4 packed signed doubleword integers from xmm1 and from xxm2/m128 into 8 packed signed word integers in xxm1 using signed saturation.|
|VEX.NDS.128.66.0F.WIG 63 /r\newline{}\newline{}VPACKSSWB xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Converts 8 packed signed word integers from xmm2 and from xmm3/m128 into 16 packed signed byte integers in xmm1 using signed saturation.|
|VEX.NDS.128.66.0F.WIG 6B /r\newline{}\newline{}VPACKSSDW xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Converts 4 packed signed doubleword integers from xmm2 and from xmm3/m128 into 8 packed signed word integers in xmm1 using signed saturation.|
|VEX.NDS.256.66.0F.WIG 63 /r\newline{}\newline{}VPACKSSWB ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Converts 16 packed signed word integers from ymm2 and from ymm3/m256 into 32 packed signed byte integers in ymm1 using signed saturation.|
|VEX.NDS.256.66.0F.WIG 6B /r\newline{}\newline{}VPACKSSDW ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Converts 8 packed signed doubleword integers from ymm2 and from ymm3/m256 into 16 packed signed word integers in ymm1using signed saturation.|
|EVEX.NDS.128.66.0F.WIG 63 /r\newline{}VPACKSSWB xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Converts packed signed word integers from xmm2 and from xmm3/m128 into packed signed byte integers in xmm1 using signed saturation under writemask k1.|
|EVEX.NDS.256.66.0F.WIG 63 /r\newline{}VPACKSSWB ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Converts packed signed word integers from ymm2 and from ymm3/m256 into packed signed byte integers in ymm1 using signed saturation under writemask k1.|
|EVEX.NDS.512.66.0F.WIG 63 /r\newline{}VPACKSSWB zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Converts packed signed word integers from zmm2 and from zmm3/m512 into packed signed byte integers in zmm1 using signed saturation under writemask k1.|
|EVEX.NDS.128.66.0F.W0 6B /r\newline{}VPACKSSDW xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VL\newline{}AVX512BW|Converts packed signed doubleword integers from xmm2 and from xmm3/m128/m32bcst into packed signed word integers in xmm1 using signed saturation under writemask k1.|


|EVEX.NDS.256.66.0F.W0 6B /r\newline{}VPACKSSDW ymm1 {k1}{z}, ymm2, \newline{}ymm3/m256/m32bcst|FV|V/V|AVX512VL\newline{}\newline{}AVX512BW|Converts packed signed doubleword integers \newline{}from ymm2 and from ymm3/m256/m32bcst \newline{}into packed signed word integers in ymm1 \newline{}using signed saturation under writemask k1.|
|----------------------------------------------------------------------------------------------|--|---|------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|EVEX.NDS.512.66.0F.W0 6B /rVPACKSSDW zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512BW|Converts packed signed doubleword integers from zmm2 and from zmm3/m512/m32bcst into packed signed word integers in zmm1 using signed saturation under writemask k1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Converts packed signed word integers into packed signed byte integers (PACKSSWB) or converts packed signed doubleword integers into packed signed word integers (PACKSSDW), using saturation to handle overflow condi-tions. See Figure 4-6 for an example of the packing operation.

PACKSSWB converts packed signed word integers in the first and second source operands into packed signed byte integers using signed saturation to handle overflow conditions beyond the range of signed byte integers. If the signed doubleword value is beyond the range of an unsigned word (i.e. greater than 7FH or less than 80H), the saturated signed byte integer value of 7FH or 80H, respectively, is stored in the destination. `PACKSSDW` converts packed signed doubleword integers in the first and second source operands into packed signed word integers using signed saturation to handle overflow conditions beyond 7FFFH and 8000H.

EVEX encoded PACKSSWB: The first source operand is a ZMM/YMM/XMM register. The second source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operand is a ZMM/YMM/XMM register, updated conditional under the writemask k1.

EVEX encoded PACKSSDW: The first source operand is a ZMM/YMM/XMM register. The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register, updated conditional under the writemask k1.

```embed
<figure>
<svg viewBox="0 0 379.679993 115.660004">
<rect x="0.000000" y="10.000000" width="0.480000" height="93.480003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="93.480003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="103.480011" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.300003" y="30.279999" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="99.300003" y="30.039978" width="72.239998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.060013" y="30.279999" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.059998" y="48.039978" width="72.239998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.059998" y="30.040009" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="135.059998" y="30.040009" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="135.059998" y="30.279999" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.780014" y="69.760010" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="150.780014" y="69.520020" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="222.539993" y="69.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.539993" y="87.520020" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.539993" y="69.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="69.520020" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="69.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="186.539993" y="69.520020" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="186.539993" y="69.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.539993" y="69.520020" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.539993" y="69.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M172.919998,62.500000 L172.680008,62.859985 L173.580002,63.579987 L173.819992,63.220001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M173.219986,63.279999 L173.759995,61.420013 L173.939987,60.399994 L174.659988,61.239990 L178.739975,66.399994 L179.819992,67.779999 L178.199997,67.179993 L172.019974,64.959991 L170.999985,64.600006 L171.839981,64.059998 L172.319992,64.000000 L178.499985,66.220001 L178.199997,67.179993 L177.959976,67.000000 L173.879990,61.839996 L174.659988,61.239990 L174.719986,61.660004 L174.179977,63.519989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.840012,64.059998 L173.400009,62.980011 L174.180008,63.519989 L174.120010,63.700012 L174.000015,63.820007 L172.440018,64.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M173.699997,63.399994 L174.240005,61.540009 L178.319992,66.699982 L172.139999,64.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.539993,48.519989 L153.360001,48.399994 L153.059982,48.759979 L153.240005,48.879974" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M172.979996,62.500000 L173.159988,62.619995 L172.860001,62.980011 L172.680008,62.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.539993,48.519989 L153.240005,48.879974 L172.680008,62.859985 L172.979996,62.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.080002,63.880005 L153.840012,64.360016 L154.860001,64.899994 L155.099991,64.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.439987,64.600006 L154.619980,62.619995 L154.739975,61.600006 L155.519974,62.320007 L160.499985,66.640015 L161.819992,67.779999 L160.080002,67.540009 L153.599991,66.520020 L152.580002,66.339996 L153.299973,65.619995 L153.779984,65.500000 L160.259995,66.520020 L160.080002,67.540009 L159.839981,67.360016 L154.860001,63.040009 L155.519974,62.320007 L155.699997,62.740021 L155.519974,64.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.300003,65.619995 L154.620010,64.299988 L155.520004,64.720001 L155.460007,64.899994 L154.020004,66.339996" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.979996,64.660004 L155.159988,62.679993 L160.139999,67.000000 L153.659988,65.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.500000,47.559998 L118.320007,47.500000 L118.139999,47.919983 L118.320007,47.980011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.080002,63.940002 L154.259995,64.000000 L154.080002,64.420013 L153.900009,64.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.500000,47.559998 L118.320007,47.980011 L153.900009,64.359985 L154.080002,63.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.080002,63.040009 L204.840012,62.680023 L203.879990,63.339996 L204.120010,63.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.300003,63.100006 L205.860001,64.240021 L206.759995,64.779999 L205.680008,65.140015 L199.440018,67.240021 L197.759995,67.839996 L198.900009,66.459991 L203.099991,61.360016 L203.759995,60.520020 L204.000015,61.540009 L203.879990,61.959991 L199.680008,67.059998 L198.900009,66.459991 L199.139999,66.279999 L205.379990,64.179993 L205.680008,65.140015 L205.259995,65.080017 L203.699997,63.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.000015,61.540009 L204.480026,63.399994 L203.700027,63.940002 L203.580002,63.820007 L203.520004,63.640015 L203.040024,61.779999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M204.000015,63.519989 L205.560013,64.660004 L199.320023,66.759979 L203.520004,61.660004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.060013,49.480011 L225.240005,49.360016 L224.940018,48.940002 L224.760025,49.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.139999,63.100006 L204.960007,63.220001 L204.659988,62.800018 L204.840012,62.679993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.060013,49.480011 L224.760025,49.059998 L204.840012,62.680023 L205.139999,63.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.919998,64.779999 L223.680008,64.299988 L222.659988,64.720001 L222.840012,65.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.080002,64.600006 L224.400009,66.040009 L225.120010,66.820007 L224.039993,66.940002 L217.500015,67.600006 L215.759995,67.779999 L217.139999,66.700012 L222.300003,62.679993 L223.139999,62.020020 L223.199997,63.040009 L222.960007,63.459991 L217.800003,67.480011 L217.139999,66.700012 L217.439987,66.580017 L223.979996,65.920013 L224.039993,66.940002 L223.680008,66.760010 L222.360001,65.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.199997,63.040009 L223.259995,64.960022 L222.360001,65.320007 L222.240005,65.140015 L222.180008,64.960022 L222.120010,63.040009" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.719986,64.959991 L224.039993,66.399994 L217.499985,67.059998 L222.659988,63.039978" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.520020,49.959991 L260.700012,49.899994 L260.520020,49.479980 L260.340027,49.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.919998,64.779999 L223.740005,64.839996 L223.560013,64.420013 L223.740005,64.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.520020,49.959991 L260.340027,49.539978 L223.740005,64.359985 L223.919998,64.779999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.419998" y="31.239990" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.419998" y="31.000000" width="72.239998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.179993" y="31.240021" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.180008" y="49.000000" width="72.239998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.180008" y="31.000000" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.180008" y="31.000000" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.180008" y="31.240021" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="221.460007" y="42.220001" textLength="4.716180" font-size="8px">B</text>
<text x="260.106201" y="27.399445" textLength="4.596480" font-size="8px">T</text>
<text x="241.805649" y="27.399445" textLength="2.992500" font-size="8px">t</text>
<text x="240.060410" y="27.399445" textLength="1.731660" font-size="8px">i</text>
<text x="232.803421" y="27.399445" textLength="2.513700" font-size="8px">-</text>
<text x="223.439713" y="27.399445" textLength="4.668300" font-size="8px">6</text>
<text x="210.299850" y="81.999390" textLength="4.971540" font-size="8px">A</text>
<text x="196.981216" y="81.279602" textLength="1.412460" font-size="8px">'</text>
<text x="178.980759" y="81.519806" textLength="1.412460" font-size="8px">'</text>
<text x="174.780075" y="81.519806" textLength="4.189500" font-size="8px">C</text>
<text x="201.316238" y="97.360016" textLength="5.349073" font-size="8px">S</text>
<text x="196.036148" y="97.360016" textLength="5.349073" font-size="8px">E</text>
<text x="190.249191" y="97.360016" textLength="5.790151" font-size="8px">D</text>
<text x="188.087906" y="97.360016" textLength="2.229449" font-size="8px"> </text>
<text x="184.084549" y="97.360016" textLength="1.780351" font-size="8px">i</text>
<text x="176.071365" y="97.360016" textLength="2.670527" font-size="8px">-</text>
<text x="171.615677" y="97.360016" textLength="4.458898" font-size="8px">4</text>
<text x="167.159988" y="97.360016" textLength="4.458898" font-size="8px">6</text>
<text x="141.009369" y="25.959991" textLength="4.811940" font-size="8px">R</text>
<text x="136.758423" y="25.959991" textLength="4.237380" font-size="8px">S</text>
<text x="125.351013" y="25.959991" textLength="4.716180" font-size="8px">B</text>
<text x="122.823746" y="25.959991" textLength="2.513700" font-size="8px">-</text>
<text x="149.939590" y="42.039795" textLength="4.189500" font-size="8px">C</text>
<text x="115.619995" y="42.279999" textLength="4.907700" font-size="8px">D</text>
<text x="118.141876" y="25.959991" textLength="4.668300" font-size="8px">4</text>
<text x="244.811722" y="27.399445" textLength="1.971060" font-size="8px"> </text>
<text x="156.300003" y="81.760010" textLength="4.907700" font-size="8px">D</text>
<text x="255.855240" y="27.399445" textLength="4.237380" font-size="8px">S</text>
<text x="130.032074" y="25.959991" textLength="1.731660" font-size="8px">i</text>
<text x="131.773315" y="25.959991" textLength="2.992500" font-size="8px">t</text>
<text x="161.158218" y="81.760010" textLength="1.412460" font-size="8px">'</text>
<text x="113.460007" y="25.959991" textLength="4.668300" font-size="8px">6</text>
<text x="134.779388" y="25.959991" textLength="1.971060" font-size="8px"> </text>
<text x="185.861679" y="97.360016" textLength="2.229449" font-size="8px">t</text>
<text x="228.121567" y="27.399445" textLength="4.668300" font-size="8px">4</text>
<text x="206.662094" y="97.360016" textLength="4.899976" font-size="8px">T</text>
<text x="251.652176" y="27.399445" textLength="4.189500" font-size="8px">E</text>
<text x="192.300156" y="81.279602" textLength="4.716180" font-size="8px">B</text>
<text x="258.959595" y="43.480042" textLength="4.971540" font-size="8px">A</text>
<text x="178.738693" y="97.360016" textLength="5.349073" font-size="8px">B</text>
<text x="214.979324" y="81.999390" textLength="1.412460" font-size="8px">'</text>
<text x="235.330673" y="27.399445" textLength="4.716180" font-size="8px">B</text>
<text x="145.688828" y="25.959991" textLength="4.189500" font-size="8px">C</text>
<text x="246.730911" y="27.399445" textLength="4.907700" font-size="8px">D</text>
</svg>
<figcaption>Figure 4-6.  Operation of the PACKSSDW Instruction Using 64-bit Operands
</figcaption></figure>
```


VEX.256 encoded version: The first source operand is a YMM register. The second source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. The upper bits (MAX_VL-1:256) of the corresponding ZMM register destination are zeroed. 

VEX.128 encoded version: The first source operand is an XMM register. The second source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The first source operand is an XMM register. The second operand can be an XMM register or an 128-bit memory location. The destination is not distinct from the first source XMM register and the upper bits (MAX_VL-1:128) of the corresponding ZMM destination register destination are unmodified.


### Operation
#### PACKSSWB instruction (128-bit Legacy SSE version)
```info-verb
    DEST[7:0] <-  SaturateSignedWordToSignedByte (DEST[15:0]);
    DEST[15:8] <-  SaturateSignedWordToSignedByte (DEST[31:16]); 
    DEST[23:16] <-  SaturateSignedWordToSignedByte (DEST[47:32]);
    DEST[31:24] <-  SaturateSignedWordToSignedByte (DEST[63:48]);
    DEST[39:32] <-  SaturateSignedWordToSignedByte (DEST[79:64]);
    DEST[47:40] <-  SaturateSignedWordToSignedByte (DEST[95:80]);
    DEST[55:48] <-  SaturateSignedWordToSignedByte (DEST[111:96]);
    DEST[63:56] <-  SaturateSignedWordToSignedByte (DEST[127:112]);
    DEST[71:64] <-  SaturateSignedWordToSignedByte (SRC[15:0]);
    DEST[79:72] <-  SaturateSignedWordToSignedByte (SRC[31:16]);
    DEST[87:80] <-  SaturateSignedWordToSignedByte (SRC[47:32]);
    DEST[95:88] <-  SaturateSignedWordToSignedByte (SRC[63:48]);
    DEST[103:96] <-  SaturateSignedWordToSignedByte (SRC[79:64]);
    DEST[111:104] <-  SaturateSignedWordToSignedByte (SRC[95:80]);
    DEST[119:112] <-  SaturateSignedWordToSignedByte (SRC[111:96]);
    DEST[127:120] <-  SaturateSignedWordToSignedByte (SRC[127:112]);
    DEST[MAX_VL-1:128] (Unmodified)
```
#### PACKSSDW instruction (128-bit Legacy SSE version)
```info-verb
    DEST[15:0] <-  SaturateSignedDwordToSignedWord (DEST[31:0]);
    DEST[31:16] <-  SaturateSignedDwordToSignedWord (DEST[63:32]);
    DEST[47:32] <-  SaturateSignedDwordToSignedWord (DEST[95:64]);
    DEST[63:48] <-  SaturateSignedDwordToSignedWord (DEST[127:96]);
    DEST[79:64] <-  SaturateSignedDwordToSignedWord (SRC[31:0]);
    DEST[95:80] <-  SaturateSignedDwordToSignedWord (SRC[63:32]);
    DEST[111:96] <-  SaturateSignedDwordToSignedWord (SRC[95:64]);
    DEST[127:112] <-  SaturateSignedDwordToSignedWord (SRC[127:96]);
    DEST[MAX_VL-1:128] (Unmodified)
```
#### VPACKSSWB instruction (VEX.128 encoded version)
```info-verb
    DEST[7:0] <-  SaturateSignedWordToSignedByte (SRC1[15:0]);
    DEST[15:8] <-  SaturateSignedWordToSignedByte (SRC1[31:16]); 
    DEST[23:16] <-  SaturateSignedWordToSignedByte (SRC1[47:32]);
    DEST[31:24] <-  SaturateSignedWordToSignedByte (SRC1[63:48]);
    DEST[39:32] <-  SaturateSignedWordToSignedByte (SRC1[79:64]);
    DEST[47:40] <-  SaturateSignedWordToSignedByte (SRC1[95:80]);
    DEST[55:48] <-  SaturateSignedWordToSignedByte (SRC1[111:96]);
    DEST[63:56] <-  SaturateSignedWordToSignedByte (SRC1[127:112]);
    DEST[71:64] <-  SaturateSignedWordToSignedByte (SRC2[15:0]);
    DEST[79:72] <-  SaturateSignedWordToSignedByte (SRC2[31:16]);
    DEST[87:80] <-  SaturateSignedWordToSignedByte (SRC2[47:32]);
    DEST[95:88] <-  SaturateSignedWordToSignedByte (SRC2[63:48]);
    DEST[103:96] <-  SaturateSignedWordToSignedByte (SRC2[79:64]);
    DEST[111:104] <-  SaturateSignedWordToSignedByte (SRC2[95:80]);
    DEST[119:112] <-  SaturateSignedWordToSignedByte (SRC2[111:96]);
    DEST[127:120] <-  SaturateSignedWordToSignedByte (SRC2[127:112]);
    DEST[MAX_VL-1:128] <-  0;
```
#### VPACKSSDW instruction (VEX.128 encoded version)
```info-verb
    DEST[15:0] <-  SaturateSignedDwordToSignedWord (SRC1[31:0]);
    DEST[31:16] <-  SaturateSignedDwordToSignedWord (SRC1[63:32]);
    DEST[47:32] <-  SaturateSignedDwordToSignedWord (SRC1[95:64]);
    DEST[63:48] <-  SaturateSignedDwordToSignedWord (SRC1[127:96]);
    DEST[79:64] <-  SaturateSignedDwordToSignedWord (SRC2[31:0]);
    DEST[95:80] <-  SaturateSignedDwordToSignedWord (SRC2[63:32]);
    DEST[111:96] <-  SaturateSignedDwordToSignedWord (SRC2[95:64]);
    DEST[127:112] <-  SaturateSignedDwordToSignedWord (SRC2[127:96]);
    DEST[MAX_VL-1:128] <-  0;
```
#### VPACKSSWB instruction (VEX.256 encoded version)
```info-verb
    DEST[7:0] <-  SaturateSignedWordToSignedByte (SRC1[15:0]);
    DEST[15:8] <-  SaturateSignedWordToSignedByte (SRC1[31:16]); 
    DEST[23:16] <-  SaturateSignedWordToSignedByte (SRC1[47:32]);
    DEST[31:24] <-  SaturateSignedWordToSignedByte (SRC1[63:48]);
    DEST[39:32] <-  SaturateSignedWordToSignedByte (SRC1[79:64]);
    DEST[47:40] <-  SaturateSignedWordToSignedByte (SRC1[95:80]);
    DEST[55:48] <-  SaturateSignedWordToSignedByte (SRC1[111:96]);
    DEST[63:56] <-  SaturateSignedWordToSignedByte (SRC1[127:112]);
    DEST[71:64] <-  SaturateSignedWordToSignedByte (SRC2[15:0]);
    DEST[79:72] <-  SaturateSignedWordToSignedByte (SRC2[31:16]);
    DEST[87:80] <-  SaturateSignedWordToSignedByte (SRC2[47:32]);
    DEST[95:88] <-  SaturateSignedWordToSignedByte (SRC2[63:48]);
    DEST[103:96] <-  SaturateSignedWordToSignedByte (SRC2[79:64]);
    DEST[111:104] <-  SaturateSignedWordToSignedByte (SRC2[95:80]);
    DEST[119:112] <-  SaturateSignedWordToSignedByte (SRC2[111:96]);
    DEST[127:120] <-  SaturateSignedWordToSignedByte (SRC2[127:112]);
    DEST[135:128] <-  SaturateSignedWordToSignedByte (SRC1[143:128]);
    DEST[143:136] <-  SaturateSignedWordToSignedByte (SRC1[159:144]); 
    DEST[151:144] <-  SaturateSignedWordToSignedByte (SRC1[175:160]);
    DEST[159:152] <-  SaturateSignedWordToSignedByte (SRC1[191:176]);
    DEST[167:160] <-  SaturateSignedWordToSignedByte (SRC1[207:192]);
    DEST[175:168] <-  SaturateSignedWordToSignedByte (SRC1[223:208]);
    DEST[183:176] <-  SaturateSignedWordToSignedByte (SRC1[239:224]);
DEST[191:184] <-  SaturateSignedWordToSignedByte (SRC1[255:240]);
    DEST[199:192] <-  SaturateSignedWordToSignedByte (SRC2[143:128]);
    DEST[207:200] <-  SaturateSignedWordToSignedByte (SRC2[159:144]);
    DEST[215:208] <-  SaturateSignedWordToSignedByte (SRC2[175:160]);
    DEST[223:216] <-  SaturateSignedWordToSignedByte (SRC2[191:176]);
    DEST[231:224] <-  SaturateSignedWordToSignedByte (SRC2[207:192]);
    DEST[239:232] <-  SaturateSignedWordToSignedByte (SRC2[223:208]);
    DEST[247:240] <-  SaturateSignedWordToSignedByte (SRC2[239:224]);
    DEST[255:248] <-  SaturateSignedWordToSignedByte (SRC2[255:240]);
    DEST[MAX_VL-1:256] <-  0;
```
#### VPACKSSDW instruction (VEX.256 encoded version)
```info-verb
    DEST[15:0] <-  SaturateSignedDwordToSignedWord (SRC1[31:0]);
    DEST[31:16] <-  SaturateSignedDwordToSignedWord (SRC1[63:32]);
    DEST[47:32] <-  SaturateSignedDwordToSignedWord (SRC1[95:64]);
    DEST[63:48] <-  SaturateSignedDwordToSignedWord (SRC1[127:96]);
    DEST[79:64] <-  SaturateSignedDwordToSignedWord (SRC2[31:0]);
    DEST[95:80] <-  SaturateSignedDwordToSignedWord (SRC2[63:32]);
    DEST[111:96] <-  SaturateSignedDwordToSignedWord (SRC2[95:64]);
    DEST[127:112] <-  SaturateSignedDwordToSignedWord (SRC2[127:96]);
    DEST[143:128] <-  SaturateSignedDwordToSignedWord (SRC1[159:128]);
    DEST[159:144] <-  SaturateSignedDwordToSignedWord (SRC1[191:160]);
    DEST[175:160] <-  SaturateSignedDwordToSignedWord (SRC1[223:192]);
    DEST[191:176] <-  SaturateSignedDwordToSignedWord (SRC1[255:224]);
    DEST[207:192] <-  SaturateSignedDwordToSignedWord (SRC2[159:128]);
    DEST[223:208] <-  SaturateSignedDwordToSignedWord (SRC2[191:160]);
    DEST[239:224] <-  SaturateSignedDwordToSignedWord (SRC2[223:192]);
    DEST[255:240] <-  SaturateSignedDwordToSignedWord (SRC2[255:224]);
    DEST[MAX_VL-1:256] <-  0;
```
#### VPACKSSWB (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
TMP_DEST[7:0] <-  SaturateSignedWordToSignedByte (SRC1[15:0]);
TMP_DEST[15:8] <-  SaturateSignedWordToSignedByte (SRC1[31:16]); 
TMP_DEST[23:16] <-  SaturateSignedWordToSignedByte (SRC1[47:32]);
TMP_DEST[31:24] <-  SaturateSignedWordToSignedByte (SRC1[63:48]);
TMP_DEST[39:32] <-  SaturateSignedWordToSignedByte (SRC1[79:64]);
TMP_DEST[47:40] <-  SaturateSignedWordToSignedByte (SRC1[95:80]);
TMP_DEST[55:48] <-  SaturateSignedWordToSignedByte (SRC1[111:96]);
TMP_DEST[63:56] <-  SaturateSignedWordToSignedByte (SRC1[127:112]);
TMP_DEST[71:64] <-  SaturateSignedWordToSignedByte (SRC2[15:0]);
TMP_DEST[79:72] <-  SaturateSignedWordToSignedByte (SRC2[31:16]);
TMP_DEST[87:80] <-  SaturateSignedWordToSignedByte (SRC2[47:32]);
TMP_DEST[95:88] <-  SaturateSignedWordToSignedByte (SRC2[63:48]);
TMP_DEST[103:96] <-  SaturateSignedWordToSignedByte (SRC2[79:64]);
TMP_DEST[111:104] <-  SaturateSignedWordToSignedByte (SRC2[95:80]);
TMP_DEST[119:112] <-  SaturateSignedWordToSignedByte (SRC2[111:96]);
TMP_DEST[127:120] <-  SaturateSignedWordToSignedByte (SRC2[127:112]);
IF VL >= 256
    TMP_DEST[135:128]<-  SaturateSignedWordToSignedByte (SRC1[143:128]);
    TMP_DEST[143:136] <-  SaturateSignedWordToSignedByte (SRC1[159:144]); 
    TMP_DEST[151:144] <-  SaturateSignedWordToSignedByte (SRC1[175:160]);
    TMP_DEST[159:152] <-  SaturateSignedWordToSignedByte (SRC1[191:176]);
    TMP_DEST[167:160] <-  SaturateSignedWordToSignedByte (SRC1[207:192]);
TMP_DEST[175:168] <-  SaturateSignedWordToSignedByte (SRC1[223:208]);
    TMP_DEST[183:176] <-  SaturateSignedWordToSignedByte (SRC1[239:224]);
    TMP_DEST[191:184] <-  SaturateSignedWordToSignedByte (SRC1[255:240]);
    TMP_DEST[199:192] <-  SaturateSignedWordToSignedByte (SRC2[143:128]);
    TMP_DEST[207:200] <-  SaturateSignedWordToSignedByte (SRC2[159:144]);
    TMP_DEST[215:208] <-  SaturateSignedWordToSignedByte (SRC2[175:160]);
    TMP_DEST[223:216] <-  SaturateSignedWordToSignedByte (SRC2[191:176]);
    TMP_DEST[231:224] <-  SaturateSignedWordToSignedByte (SRC2[207:192]);
    TMP_DEST[239:232] <-  SaturateSignedWordToSignedByte (SRC2[223:208]);
    TMP_DEST[247:240] <-  SaturateSignedWordToSignedByte (SRC2[239:224]);
    TMP_DEST[255:248] <-  SaturateSignedWordToSignedByte (SRC2[255:240]);
FI;
IF VL >= 512
    TMP_DEST[263:256] <-  SaturateSignedWordToSignedByte (SRC1[271:256]);
    TMP_DEST[271:264] <-  SaturateSignedWordToSignedByte (SRC1[287:272]); 
    TMP_DEST[279:272] <-  SaturateSignedWordToSignedByte (SRC1[303:288]);
    TMP_DEST[287:280] <-  SaturateSignedWordToSignedByte (SRC1[319:304]);
    TMP_DEST[295:288] <-  SaturateSignedWordToSignedByte (SRC1[335:320]);
    TMP_DEST[303:296] <-  SaturateSignedWordToSignedByte (SRC1[351:336]);
    TMP_DEST[311:304] <-  SaturateSignedWordToSignedByte (SRC1[367:352]);
    TMP_DEST[319:312] <-  SaturateSignedWordToSignedByte (SRC1[383:368]);
    TMP_DEST[327:320] <-  SaturateSignedWordToSignedByte (SRC2[271:256]);
    TMP_DEST[335:328] <-  SaturateSignedWordToSignedByte (SRC2[287:272]); 
    TMP_DEST[343:336] <-  SaturateSignedWordToSignedByte (SRC2[303:288]);
    TMP_DEST[351:344] <-  SaturateSignedWordToSignedByte (SRC2[319:304]);
    TMP_DEST[359:352] <-  SaturateSignedWordToSignedByte (SRC2[335:320]);
    TMP_DEST[367:360] <-  SaturateSignedWordToSignedByte (SRC2[351:336]);
    TMP_DEST[375:368] <-  SaturateSignedWordToSignedByte (SRC2[367:352]);
    TMP_DEST[383:376] <-  SaturateSignedWordToSignedByte (SRC2[383:368]);
    TMP_DEST[391:384] <-  SaturateSignedWordToSignedByte (SRC1[399:384]);
    TMP_DEST[399:392] <-  SaturateSignedWordToSignedByte (SRC1[415:400]);
    TMP_DEST[407:400] <-  SaturateSignedWordToSignedByte (SRC1[431:416]);
    TMP_DEST[415:408] <-  SaturateSignedWordToSignedByte (SRC1[447:432]);
    TMP_DEST[423:416] <-  SaturateSignedWordToSignedByte (SRC1[463:448]);
    TMP_DEST[431:424] <-  SaturateSignedWordToSignedByte (SRC1[479:464]);
    TMP_DEST[439:432] <-  SaturateSignedWordToSignedByte (SRC1[495:480]);
    TMP_DEST[447:440] <-  SaturateSignedWordToSignedByte (SRC1[511:496]);
    TMP_DEST[455:448] <-  SaturateSignedWordToSignedByte (SRC2[399:384]);
    TMP_DEST[463:456] <-  SaturateSignedWordToSignedByte (SRC2[415:400]);
    TMP_DEST[471:464] <-  SaturateSignedWordToSignedByte (SRC2[431:416]);
    TMP_DEST[479:472] <-  SaturateSignedWordToSignedByte (SRC2[447:432]);
    TMP_DEST[487:480] <-  SaturateSignedWordToSignedByte (SRC2[463:448]);
    TMP_DEST[495:488] <-  SaturateSignedWordToSignedByte (SRC2[479:464]);
    TMP_DEST[503:496] <-  SaturateSignedWordToSignedByte (SRC2[495:480]);
    TMP_DEST[511:504] <-  SaturateSignedWordToSignedByte (SRC2[511:496]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN 
                DEST[i+7:i] <-  TMP_DEST[i+7:i]
ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```
#### VPACKSSDW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO ((KL/2) - 1)
    i <-  j * 32
    IF (EVEX.b == 1) AND (SRC2 *is memory*)
          THEN
                TMP_SRC2[i+31:i] <-  SRC2[31:0]
          ELSE 
                TMP_SRC2[i+31:i] <-  SRC2[i+31:i]
    FI;
ENDFOR;
TMP_DEST[15:0] <-  SaturateSignedDwordToSignedWord (SRC1[31:0]);
TMP_DEST[31:16] <-  SaturateSignedDwordToSignedWord (SRC1[63:32]);
TMP_DEST[47:32] <-  SaturateSignedDwordToSignedWord (SRC1[95:64]);
TMP_DEST[63:48] <-  SaturateSignedDwordToSignedWord (SRC1[127:96]);
TMP_DEST[79:64] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[31:0]);
TMP_DEST[95:80] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[63:32]);
TMP_DEST[111:96] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[95:64]);
TMP_DEST[127:112] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[127:96]);
IF VL >= 256
    TMP_DEST[143:128] <-  SaturateSignedDwordToSignedWord (SRC1[159:128]);
    TMP_DEST[159:144] <-  SaturateSignedDwordToSignedWord (SRC1[191:160]);
    TMP_DEST[175:160] <-  SaturateSignedDwordToSignedWord (SRC1[223:192]);
    TMP_DEST[191:176] <-  SaturateSignedDwordToSignedWord (SRC1[255:224]);
    TMP_DEST[207:192] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[159:128]);
    TMP_DEST[223:208] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[191:160]);
    TMP_DEST[239:224] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[223:192]);
    TMP_DEST[255:240] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[255:224]);
FI;
IF VL >= 512
    TMP_DEST[271:256] <-  SaturateSignedDwordToSignedWord (SRC1[287:256]);
    TMP_DEST[287:272] <-  SaturateSignedDwordToSignedWord (SRC1[319:288]);
    TMP_DEST[303:288] <-  SaturateSignedDwordToSignedWord (SRC1[351:320]);
    TMP_DEST[319:304] <-  SaturateSignedDwordToSignedWord (SRC1[383:352]);
    TMP_DEST[335:320] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[287:256]);
    TMP_DEST[351:336] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[319:288]);
    TMP_DEST[367:352] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[351:320]);
    TMP_DEST[383:368] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[383:352]);
    TMP_DEST[399:384] <-  SaturateSignedDwordToSignedWord (SRC1[415:384]);
    TMP_DEST[415:400] <-  SaturateSignedDwordToSignedWord (SRC1[447:416]);
    TMP_DEST[431:416] <-  SaturateSignedDwordToSignedWord (SRC1[479:448]);
TMP_DEST[447:432] <-  SaturateSignedDwordToSignedWord (SRC1[511:480]);
    TMP_DEST[463:448] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[415:384]);
    TMP_DEST[479:464] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[447:416]);
    TMP_DEST[495:480] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[479:448]);
    TMP_DEST[511:496] <-  SaturateSignedDwordToSignedWord (TMP_SRC2[511:480]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPACKSSDW__m512i _mm512_packs_epi32(__m512i m1, __m512i m2);
VPACKSSDW__m512i _mm512_mask_packs_epi32(__m512i s, __mmask32 k, __m512i m1, __m512i m2);
VPACKSSDW__m512i _mm512_maskz_packs_epi32( __mmask32 k, __m512i m1, __m512i m2);
VPACKSSDW__m256i _mm256_mask_packs_epi32( __m256i s, __mmask16 k, __m256i m1, __m256i m2);
VPACKSSDW__m256i _mm256_maskz_packs_epi32( __mmask16 k, __m256i m1, __m256i m2);
VPACKSSDW__m128i _mm_mask_packs_epi32( __m128i s, __mmask8 k, __m128i m1, __m128i m2);
VPACKSSDW__m128i _mm_maskz_packs_epi32( __mmask8 k, __m128i m1, __m128i m2);
VPACKSSWB__m512i _mm512_packs_epi16(__m512i m1, __m512i m2);
VPACKSSWB__m512i _mm512_mask_packs_epi16(__m512i s, __mmask32 k, __m512i m1, __m512i m2);
VPACKSSWB__m512i _mm512_maskz_packs_epi16( __mmask32 k, __m512i m1, __m512i m2);
VPACKSSWB__m256i _mm256_mask_packs_epi16( __m256i s, __mmask16 k, __m256i m1, __m256i m2);
VPACKSSWB__m256i _mm256_maskz_packs_epi16( __mmask16 k, __m256i m1, __m256i m2);
VPACKSSWB__m128i _mm_mask_packs_epi16( __m128i s, __mmask8 k, __m128i m1, __m128i m2);
VPACKSSWB__m128i _mm_maskz_packs_epi16( __mmask8 k, __m128i m1, __m128i m2);
PACKSSWB __m128i _mm_packs_epi16(__m128i m1, __m128i m2)
PACKSSDW __m128i _mm_packs_epi32(__m128i m1, __m128i m2)
VPACKSSWB __m256i _mm256_packs_epi16(__m256i m1, __m256i m2)
VPACKSSDW __m256i _mm256_packs_epi32(__m256i m1, __m256i m2)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPACKSSDW, see Exceptions Type E4NF.

EVEX-encoded VPACKSSWB, see Exceptions Type E4NF.nb.

