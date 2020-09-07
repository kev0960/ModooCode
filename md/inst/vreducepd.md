----------------------------
title : VREDUCEPD (Intel x86/64 assembly instruction)
cat_title : VREDUCEPD
ref_title : VREDUCEPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VREDUCEPD

**Perform Reduction Transformation on Packed Float64 Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F3A.W1 56 /r ib\newline{}VREDUCEPD xmm1 {k1}{z}, xmm2/m128/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Perform reduction transformation on packed double-precision floating point values in xmm2/m128/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register under writemask k1.|
|EVEX.256.66.0F3A.W1 56 /r ib\newline{}VREDUCEPD ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Perform reduction transformation on packed double-precision floating point values in ymm2/m256/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register under writemask k1.|
|EVEX.512.66.0F3A.W1 56 /r ib\newline{}VREDUCEPD zmm1 {k1}{z}, zmm2/m512/m64bcst{sae}, imm8|FV|V/V|AVX512DQ|Perform reduction transformation on double-precision floating point values in zmm2/m512/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description


Perform reduction transformation of the packed binary encoded double-precision FP values in the source operand (the second operand) and store the reduced results in binary FP format to the destination operand (the first operand) under the writemask k1. 

The reduction transformation subtracts the integer part and the leading M fractional bits from the binary FP source value, where M is a unsigned integer specified by imm8[7:4], see Figure 5-28. Specifically, the reduction transfor-mation can be expressed as:

dest = src - (ROUND(2\footnote{M} \htmlonly{\esc{*}}src))\htmlonly{\esc{*}}2\footnote{-M} ;

where "Round()" treats "src", "2\footnote{M} ", and their product as binary FP numbers with normalized significand and bi-ased exponents.

The magnitude of the reduced result can be expressed by considering src= 2\footnote{p} \htmlonly{\esc{*}}man2,

where 'man2' is the normalized significand and 'p' is the unbiased exponent 

Then if RC = RNE: 0<=|Reduced Result|<=2\footnote{p-M-1}

Then if RC ->  RNE: 0<=|Reduced Result|<2\footnote{p-M}

This instruction might end up with a precision exception set. However, in case of SPE set (i.e. Suppress Precision Exception, which is imm8[3]=1), no precision exception is reported.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 515.880005 134.319901">
<rect x="0.000000" y="10.000015" width="0.480010" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="515.400024" y="10.000015" width="0.479980" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520004" width="515.880005" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="117.159996" width="515.880005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="49.019997" y="36.820007" width="373.260010" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="421.799988" y="37.060013" width="0.480010" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="48.779999" y="50.080017" width="373.260010" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="48.779999" y="36.820007" width="0.480000" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="328.559998" y="37.059998" width="0.479980" height="0.240010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="328.559998" y="37.300018" width="0.479980" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.259979" y="37.059998" width="0.480010" height="0.240010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.259979" y="37.300018" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.599998,70.960007 L89.400002,73.900009" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M95.279991,73.420013 L89.399986,73.900009 L91.859993,68.560013" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M115.499992,55.720016 L93.599998,70.960022" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M396.420013,63.040024 L400.440002,66.220016" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M398.279999,60.700027 L400.440002,66.220032 L394.619995,65.380020" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M379.559998,49.720032 L396.420013,63.040024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="283.259979" y="38.020020" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="283.259979" y="38.260010" width="0.480010" height="11.700000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.419983,66.580002 L306.959991,71.680008" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M309.359985,66.279999 L306.959991,71.679993 L303.479980,66.940002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M304.559998,50.259995 L306.419983,66.580002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M236.639984,62.440002 L232.019989,64.720001" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M237.899994,65.139999 L232.019989,64.720001 L235.320007,59.800003" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M258.479980,51.759995 L236.639984,62.439987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="238.982971" y="90.459991" textLength="2.676000" font-size="8px">s</text>
<text x="233.173767" y="90.459991" textLength="3.144000" font-size="8px">e</text>
<text x="228.000580" y="90.459991" textLength="3.108000" font-size="8px">p</text>
<text x="221.699951" y="90.459991" textLength="3.186000" font-size="8px">u</text>
<text x="218.518738" y="90.459991" textLength="3.186000" font-size="8px">S</text>
<text x="217.019348" y="90.459991" textLength="1.482000" font-size="8px"> </text>
<text x="214.385956" y="90.459991" textLength="1.482000" font-size="8px"> </text>
<text x="206.293182" y="90.459991" textLength="1.482000" font-size="8px"> </text>
<text x="202.871979" y="90.459991" textLength="3.414000" font-size="8px">=</text>
<text x="201.372559" y="90.459991" textLength="1.482000" font-size="8px"> </text>
<text x="196.026581" y="90.459991" textLength="3.510000" font-size="8px">3</text>
<text x="186.060577" y="90.459991" textLength="4.632000" font-size="8px">m</text>
<text x="279.791351" y="80.619995" textLength="2.982000" font-size="8px">a</text>
<text x="275.170746" y="80.619995" textLength="4.632000" font-size="8px">m</text>
<text x="270.496765" y="80.619995" textLength="3.186000" font-size="8px">n</text>
<text x="263.774963" y="80.619995" textLength="2.250000" font-size="8px">t</text>
<text x="257.714966" y="80.619995" textLength="3.144000" font-size="8px">e</text>
<text x="255.075562" y="80.619995" textLength="2.604000" font-size="8px">c</text>
<text x="247.576752" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="240.742157" y="80.619995" textLength="3.186000" font-size="8px">S</text>
<text x="237.603546" y="80.619995" textLength="3.150000" font-size="8px">C</text>
<text x="229.628357" y="80.619995" textLength="4.386000" font-size="8px">M</text>
<text x="222.295166" y="80.619995" textLength="2.676000" font-size="8px">s</text>
<text x="217.015167" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="199.561188" y="80.619995" textLength="1.842000" font-size="8px">]</text>
<text x="194.221802" y="80.619995" textLength="1.842000" font-size="8px">[</text>
<text x="181.440582" y="80.619995" textLength="4.632000" font-size="8px">m</text>
<text x="180.000000" y="80.619995" textLength="1.398000" font-size="8px">I</text>
<text x="277.756134" y="70.779999" textLength="1.482000" font-size="8px"> </text>
<text x="272.420929" y="70.779999" textLength="3.510000" font-size="8px">3</text>
<text x="267.085724" y="70.779999" textLength="3.510000" font-size="8px">8</text>
<text x="257.795319" y="70.779999" textLength="4.632000" font-size="8px">m</text>
<text x="254.944733" y="70.779999" textLength="1.482000" font-size="8px"> </text>
<text x="247.441742" y="70.779999" textLength="3.150000" font-size="8px">o</text>
<text x="243.846558" y="70.779999" textLength="2.250000" font-size="8px">t</text>
<text x="237.786560" y="70.779999" textLength="3.144000" font-size="8px">e</text>
<text x="235.169373" y="70.779999" textLength="2.604000" font-size="8px">c</text>
<text x="232.110565" y="70.779999" textLength="3.192000" font-size="8px">x</text>
<text x="228.989960" y="70.779999" textLength="3.150000" font-size="8px">E</text>
<text x="227.490570" y="70.779999" textLength="1.482000" font-size="8px"> </text>
<text x="224.291382" y="70.779999" textLength="3.186000" font-size="8px">n</text>
<text x="219.855591" y="70.779999" textLength="1.302000" font-size="8px">i</text>
<text x="217.154388" y="70.779999" textLength="2.676000" font-size="8px">s</text>
<text x="215.893188" y="70.779999" textLength="1.302000" font-size="8px">i</text>
<text x="213.253784" y="70.779999" textLength="2.604000" font-size="8px">c</text>
<text x="210.133209" y="70.779999" textLength="3.144000" font-size="8px">e</text>
<text x="208.092010" y="70.779999" textLength="2.178000" font-size="8px">r</text>
<text x="204.664795" y="70.779999" textLength="3.414000" font-size="8px">P</text>
<text x="203.165405" y="70.779999" textLength="1.482000" font-size="8px"> </text>
<text x="192.601196" y="70.779999" textLength="2.178000" font-size="8px">r</text>
<text x="189.481781" y="70.779999" textLength="3.108000" font-size="8px">p</text>
<text x="186.422394" y="70.779999" textLength="3.108000" font-size="8px">p</text>
<text x="183.241180" y="70.779999" textLength="3.186000" font-size="8px">u</text>
<text x="180.000000" y="70.779999" textLength="3.186000" font-size="8px">S</text>
<text x="361.997375" y="99.400009" textLength="3.618000" font-size="8px">R</text>
<text x="358.756165" y="99.400009" textLength="3.186000" font-size="8px">S</text>
<text x="347.641174" y="99.400009" textLength="4.386000" font-size="8px">M</text>
<text x="340.337372" y="99.400009" textLength="2.676000" font-size="8px">s</text>
<text x="275.900940" y="70.779999" textLength="1.842000" font-size="8px">]</text>
<text x="336.537567" y="99.400009" textLength="3.792000" font-size="8px">U</text>
<text x="333.896973" y="99.400009" textLength="1.170000" font-size="8px">:</text>
<text x="332.397583" y="99.400009" textLength="1.482000" font-size="8px"> </text>
<text x="329.278198" y="99.400009" textLength="3.108000" font-size="8px">b</text>
<text x="324.298798" y="99.400009" textLength="1.482000" font-size="8px"> </text>
<text x="320.876984" y="99.400009" textLength="3.414000" font-size="8px">=</text>
<text x="308.740204" y="99.400009" textLength="3.510000" font-size="8px">8</text>
<text x="304.100403" y="99.400009" textLength="4.632000" font-size="8px">m</text>
<text x="299.460602" y="99.400009" textLength="4.632000" font-size="8px">m</text>
<text x="367.199432" y="89.560013" textLength="1.170000" font-size="8px">:</text>
<text x="363.719421" y="89.560013" textLength="3.510000" font-size="8px">1</text>
<text x="361.865417" y="89.560013" textLength="1.842000" font-size="8px">[</text>
<text x="358.343414" y="89.560013" textLength="3.510000" font-size="8px">8</text>
<text x="353.699402" y="89.560013" textLength="4.632000" font-size="8px">m</text>
<text x="347.674774" y="89.560013" textLength="1.398000" font-size="8px">I</text>
<text x="346.175385" y="89.560013" textLength="1.482000" font-size="8px"> </text>
<text x="340.366791" y="89.560013" textLength="2.676000" font-size="8px">s</text>
<text x="336.562805" y="89.560013" textLength="3.792000" font-size="8px">U</text>
<text x="332.422821" y="89.560013" textLength="1.482000" font-size="8px"> </text>
<text x="329.303436" y="89.560013" textLength="3.108000" font-size="8px">b</text>
<text x="324.324036" y="89.560013" textLength="1.482000" font-size="8px"> </text>
<text x="320.898041" y="89.560013" textLength="3.414000" font-size="8px">=</text>
<text x="314.124634" y="89.560013" textLength="3.510000" font-size="8px">2</text>
<text x="312.270630" y="89.560013" textLength="1.842000" font-size="8px">[</text>
<text x="304.104614" y="89.560013" textLength="4.632000" font-size="8px">m</text>
<text x="299.460602" y="89.560013" textLength="4.632000" font-size="8px">m</text>
<text x="298.079987" y="89.560013" textLength="1.398000" font-size="8px">I</text>
<text x="355.295990" y="79.720016" textLength="1.482000" font-size="8px"> </text>
<text x="348.124176" y="79.720016" textLength="1.842000" font-size="8px">[</text>
<text x="340.001373" y="79.720016" textLength="4.632000" font-size="8px">m</text>
<text x="335.378967" y="79.720016" textLength="4.632000" font-size="8px">m</text>
<text x="333.938354" y="79.720016" textLength="1.398000" font-size="8px">I</text>
<text x="329.057373" y="79.720016" textLength="2.250000" font-size="8px">t</text>
<text x="323.283569" y="79.720016" textLength="3.144000" font-size="8px">e</text>
<text x="322.009155" y="79.720016" textLength="1.284000" font-size="8px">l</text>
<text x="315.652161" y="79.720016" textLength="3.186000" font-size="8px">S</text>
<text x="314.152771" y="79.720016" textLength="1.482000" font-size="8px"> </text>
<text x="307.916992" y="79.720016" textLength="3.186000" font-size="8px">n</text>
<text x="304.740601" y="79.720016" textLength="3.186000" font-size="8px">u</text>
<text x="298.079987" y="79.720016" textLength="3.618000" font-size="8px">R</text>
<text x="260.162384" y="45.400009" textLength="3.150000" font-size="8px">E</text>
<text x="19.861156" y="44.259995" textLength="4.632000" font-size="8px">m</text>
<text x="461.220001" y="102.940002" textLength="3.144000" font-size="8px">e</text>
<text x="459.005402" y="102.940002" textLength="2.250000" font-size="8px">t</text>
<text x="456.126007" y="102.940002" textLength="2.982000" font-size="8px">a</text>
<text x="453.557404" y="102.940002" textLength="2.604000" font-size="8px">c</text>
<text x="450.316193" y="102.940002" textLength="3.186000" font-size="8px">n</text>
<text x="440.295593" y="102.940002" textLength="1.482000" font-size="8px"> </text>
<text x="437.595001" y="102.940002" textLength="1.482000" font-size="8px"> </text>
<text x="430.982391" y="102.940002" textLength="3.510000" font-size="8px">1</text>
<text x="422.587799" y="102.940002" textLength="3.414000" font-size="8px">=</text>
<text x="421.088409" y="102.940002" textLength="1.482000" font-size="8px"> </text>
<text x="415.741791" y="102.940002" textLength="3.510000" font-size="8px">0</text>
<text x="414.607178" y="102.940002" textLength="1.170000" font-size="8px">:</text>
<text x="411.067169" y="102.940002" textLength="3.510000" font-size="8px">1</text>
<text x="409.260559" y="102.940002" textLength="1.842000" font-size="8px">[</text>
<text x="405.720551" y="102.940002" textLength="3.510000" font-size="8px">8</text>
<text x="396.480560" y="102.940002" textLength="4.632000" font-size="8px">m</text>
<text x="395.039948" y="102.940002" textLength="1.398000" font-size="8px">I</text>
<text x="459.363556" y="93.100006" textLength="3.186000" font-size="8px">u</text>
<text x="454.765167" y="93.100006" textLength="3.108000" font-size="8px">d</text>
<text x="451.588165" y="93.100006" textLength="3.186000" font-size="8px">n</text>
<text x="448.411163" y="93.100006" textLength="3.186000" font-size="8px">u</text>
<text x="445.230560" y="93.100006" textLength="3.150000" font-size="8px">o</text>
<text x="439.109955" y="93.100006" textLength="1.170000" font-size="8px">:</text>
<text x="434.551178" y="93.100006" textLength="3.108000" font-size="8px">b</text>
<text x="431.011169" y="93.100006" textLength="3.510000" font-size="8px">0</text>
<text x="427.510162" y="93.100006" textLength="3.510000" font-size="8px">1</text>
<text x="426.010773" y="93.100006" textLength="1.482000" font-size="8px"> </text>
<text x="419.306976" y="93.100006" textLength="1.842000" font-size="8px">]</text>
<text x="415.766968" y="93.100006" textLength="3.510000" font-size="8px">0</text>
<text x="411.065948" y="93.100006" textLength="3.510000" font-size="8px">1</text>
<text x="409.266541" y="93.100006" textLength="1.842000" font-size="8px">[</text>
<text x="470.161163" y="83.260010" textLength="3.186000" font-size="8px">n</text>
<text x="462.420563" y="83.260010" textLength="3.150000" font-size="8px">o</text>
<text x="459.352753" y="83.260010" textLength="3.108000" font-size="8px">d</text>
<text x="451.552734" y="83.260010" textLength="3.186000" font-size="8px">n</text>
<text x="448.371521" y="83.260010" textLength="3.186000" font-size="8px">u</text>
<text x="465.481171" y="83.260010" textLength="4.632000" font-size="8px">w</text>
<text x="445.190918" y="83.260010" textLength="3.150000" font-size="8px">o</text>
<text x="440.271515" y="83.260010" textLength="1.482000" font-size="8px"> </text>
<text x="439.070312" y="83.260010" textLength="1.170000" font-size="8px">:</text>
<text x="437.570923" y="83.260010" textLength="1.482000" font-size="8px"> </text>
<text x="434.503113" y="83.260010" textLength="3.108000" font-size="8px">b</text>
<text x="425.993927" y="83.260010" textLength="1.482000" font-size="8px"> </text>
<text x="422.573334" y="83.260010" textLength="3.414000" font-size="8px">=</text>
<text x="421.073944" y="83.260010" textLength="1.482000" font-size="8px"> </text>
<text x="419.272156" y="83.260010" textLength="1.842000" font-size="8px">]</text>
<text x="415.732147" y="83.260010" textLength="3.510000" font-size="8px">0</text>
<text x="414.602356" y="83.260010" textLength="1.170000" font-size="8px">:</text>
<text x="411.062347" y="83.260010" textLength="3.510000" font-size="8px">1</text>
<text x="409.260559" y="83.260010" textLength="1.842000" font-size="8px">[</text>
<text x="405.720551" y="83.260010" textLength="3.510000" font-size="8px">8</text>
<text x="401.100555" y="83.260010" textLength="4.632000" font-size="8px">m</text>
<text x="395.039948" y="83.260010" textLength="1.398000" font-size="8px">I</text>
<text x="489.382172" y="73.420013" textLength="3.186000" font-size="8px">n</text>
<text x="486.250153" y="73.420013" textLength="3.144000" font-size="8px">e</text>
<text x="480.190155" y="73.420013" textLength="3.144000" font-size="8px">e</text>
<text x="478.690765" y="73.420013" textLength="1.482000" font-size="8px"> </text>
<text x="476.452789" y="73.420013" textLength="2.250000" font-size="8px">t</text>
<text x="473.788788" y="73.420013" textLength="2.676000" font-size="8px">s</text>
<text x="468.615570" y="73.420013" textLength="2.178000" font-size="8px">r</text>
<text x="465.645569" y="73.420013" textLength="2.982000" font-size="8px">a</text>
<text x="462.513580" y="73.420013" textLength="3.144000" font-size="8px">e</text>
<text x="459.339569" y="73.420013" textLength="3.186000" font-size="8px">n</text>
<text x="454.744171" y="73.420013" textLength="3.108000" font-size="8px">d</text>
<text x="451.570160" y="73.420013" textLength="3.186000" font-size="8px">n</text>
<text x="445.215546" y="73.420013" textLength="3.150000" font-size="8px">o</text>
<text x="427.498169" y="73.420013" textLength="3.510000" font-size="8px">0</text>
<text x="422.596771" y="73.420013" textLength="3.414000" font-size="8px">=</text>
<text x="419.297974" y="73.420013" textLength="1.842000" font-size="8px">]</text>
<text x="414.599976" y="73.420013" textLength="1.170000" font-size="8px">:</text>
<text x="411.059967" y="73.420013" textLength="3.510000" font-size="8px">1</text>
<text x="405.720551" y="73.420013" textLength="3.510000" font-size="8px">8</text>
<text x="401.100555" y="73.420013" textLength="4.632000" font-size="8px">m</text>
<text x="419.281799" y="102.940002" textLength="1.842000" font-size="8px">]</text>
<text x="304.679962" y="45.400009" textLength="3.186000" font-size="8px">S</text>
<text x="301.079956" y="45.400009" textLength="3.618000" font-size="8px">R</text>
<text x="218.514557" y="80.619995" textLength="3.792000" font-size="8px">U</text>
<text x="153.447632" y="82.900009" textLength="2.250000" font-size="8px">t</text>
<text x="147.868805" y="82.900009" textLength="2.982000" font-size="8px">a</text>
<text x="145.827606" y="82.900009" textLength="2.178000" font-size="8px">r</text>
<text x="140.608215" y="82.900009" textLength="3.108000" font-size="8px">b</text>
<text x="134.723419" y="82.900009" textLength="2.676000" font-size="8px">s</text>
<text x="133.283997" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="127.943398" y="82.900009" textLength="2.250000" font-size="8px">t</text>
<text x="126.443993" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="123.802788" y="82.900009" textLength="2.676000" font-size="8px">s</text>
<text x="121.541389" y="82.900009" textLength="2.250000" font-size="8px">t</text>
<text x="118.480186" y="82.900009" textLength="3.186000" font-size="8px">n</text>
<text x="114.046181" y="82.900009" textLength="3.150000" font-size="8px">o</text>
<text x="110.926781" y="82.900009" textLength="3.108000" font-size="8px">p</text>
<text x="109.427376" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="103.187370" y="82.900009" textLength="3.144000" font-size="8px">e</text>
<text x="98.875175" y="82.900009" textLength="1.302000" font-size="8px">i</text>
<text x="96.637779" y="82.900009" textLength="2.226000" font-size="8px">f</text>
<text x="95.138374" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="92.918968" y="82.900009" textLength="2.226000" font-size="8px">f</text>
<text x="88.418968" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="86.197762" y="82.900009" textLength="2.178000" font-size="8px">r</text>
<text x="75.314362" y="82.900009" textLength="4.632000" font-size="8px">m</text>
<text x="72.116959" y="82.900009" textLength="3.186000" font-size="8px">u</text>
<text x="68.205559" y="82.900009" textLength="3.900000" font-size="8px">N</text>
<text x="65.564964" y="82.900009" textLength="1.170000" font-size="8px">:</text>
<text x="58.732162" y="82.900009" textLength="3.510000" font-size="8px">4</text>
<text x="57.590965" y="82.900009" textLength="1.170000" font-size="8px">:</text>
<text x="54.069565" y="82.900009" textLength="3.510000" font-size="8px">7</text>
<text x="52.216164" y="82.900009" textLength="1.842000" font-size="8px">[</text>
<text x="48.736160" y="82.900009" textLength="3.510000" font-size="8px">8</text>
<text x="163.084747" y="45.940002" textLength="3.186000" font-size="8px">h</text>
<text x="157.744751" y="45.940002" textLength="3.108000" font-size="8px">g</text>
<text x="154.588165" y="45.940002" textLength="3.186000" font-size="8px">n</text>
<text x="415.757965" y="73.420013" textLength="3.510000" font-size="8px">0</text>
<text x="151.407562" y="45.940002" textLength="3.144000" font-size="8px">e</text>
<text x="150.152954" y="45.940002" textLength="1.284000" font-size="8px">l</text>
<text x="143.311768" y="45.940002" textLength="3.186000" font-size="8px">n</text>
<text x="138.858551" y="45.940002" textLength="3.150000" font-size="8px">o</text>
<text x="441.735535" y="73.420013" textLength="3.618000" font-size="8px">R</text>
<text x="128.040558" y="45.940002" textLength="3.144000" font-size="8px">e</text>
<text x="125.041756" y="45.940002" textLength="3.192000" font-size="8px">x</text>
<text x="123.720558" y="45.940002" textLength="1.302000" font-size="8px">i</text>
<text x="402.977966" y="45.940002" textLength="3.144000" font-size="8px">e</text>
<text x="399.871765" y="45.940002" textLength="3.108000" font-size="8px">d</text>
<text x="391.038544" y="45.940002" textLength="3.144000" font-size="8px">e</text>
<text x="388.039154" y="45.940002" textLength="3.096000" font-size="8px">v</text>
<text x="384.260345" y="45.940002" textLength="3.822000" font-size="8px">O</text>
<text x="382.760956" y="45.940002" textLength="1.482000" font-size="8px"> </text>
<text x="441.734985" y="102.940002" textLength="3.456000" font-size="8px">T</text>
<text x="378.298157" y="45.940002" textLength="3.150000" font-size="8px">o</text>
<text x="376.256958" y="45.940002" textLength="2.178000" font-size="8px">r</text>
<text x="373.976959" y="45.940002" textLength="2.250000" font-size="8px">t</text>
<text x="370.915771" y="45.940002" textLength="3.186000" font-size="8px">n</text>
<text x="367.735168" y="45.940002" textLength="3.150000" font-size="8px">o</text>
<text x="363.175171" y="45.940002" textLength="1.482000" font-size="8px"> </text>
<text x="360.068970" y="45.940002" textLength="3.108000" font-size="8px">d</text>
<text x="194.642395" y="70.779999" textLength="3.144000" font-size="8px">e</text>
<text x="356.884766" y="45.940002" textLength="3.186000" font-size="8px">n</text>
<text x="353.700562" y="45.940002" textLength="3.186000" font-size="8px">u</text>
<text x="347.039948" y="45.940002" textLength="3.618000" font-size="8px">R</text>
<text x="350.819977" y="32.020004" textLength="3.510000" font-size="8px">1</text>
<text x="258.059967" y="32.020004" textLength="3.510000" font-size="8px">3</text>
<text x="165.299957" y="32.020004" textLength="3.510000" font-size="8px">5</text>
<text x="331.297760" y="79.720016" textLength="1.170000" font-size="8px">:</text>
<text x="118.979973" y="32.020004" textLength="3.510000" font-size="8px">6</text>
<text x="304.439972" y="32.020004" textLength="3.510000" font-size="8px">2</text>
<text x="397.139984" y="32.020004" textLength="3.510000" font-size="8px">0</text>
<text x="72.599998" y="32.020004" textLength="3.510000" font-size="8px">7</text>
<text x="395.039948" y="73.420013" textLength="1.398000" font-size="8px">I</text>
<text x="371.861450" y="89.560013" textLength="1.842000" font-size="8px">]</text>
<text x="224.881165" y="90.459991" textLength="3.108000" font-size="8px">p</text>
<text x="317.604645" y="89.560013" textLength="1.842000" font-size="8px">]</text>
<text x="448.396149" y="73.420013" textLength="3.186000" font-size="8px">u</text>
<text x="18.539955" y="44.259995" textLength="1.302000" font-size="8px">i</text>
<text x="83.077164" y="82.900009" textLength="3.144000" font-size="8px">e</text>
<text x="273.671356" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="131.161163" y="45.940002" textLength="3.108000" font-size="8px">d</text>
<text x="181.440582" y="90.459991" textLength="4.632000" font-size="8px">m</text>
<text x="150.868225" y="82.900009" textLength="2.604000" font-size="8px">c</text>
<text x="260.835571" y="80.619995" textLength="3.108000" font-size="8px">p</text>
<text x="234.002960" y="80.619995" textLength="3.774000" font-size="8px">X</text>
<text x="39.449356" y="82.900009" textLength="4.632000" font-size="8px">m</text>
<text x="207.761993" y="80.619995" textLength="3.510000" font-size="8px">0</text>
<text x="457.864166" y="93.100006" textLength="1.482000" font-size="8px"> </text>
<text x="146.432953" y="45.940002" textLength="2.250000" font-size="8px">t</text>
<text x="89.858376" y="82.900009" textLength="3.150000" font-size="8px">o</text>
<text x="421.106384" y="93.100006" textLength="1.482000" font-size="8px"> </text>
<text x="405.726532" y="93.100006" textLength="3.510000" font-size="8px">8</text>
<text x="434.522400" y="102.940002" textLength="3.108000" font-size="8px">b</text>
<text x="266.054962" y="80.619995" textLength="1.302000" font-size="8px">i</text>
<text x="318.828552" y="79.720016" textLength="3.144000" font-size="8px">e</text>
<text x="206.262573" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="325.823425" y="89.560013" textLength="3.510000" font-size="8px">0</text>
<text x="344.623779" y="79.720016" textLength="3.510000" font-size="8px">8</text>
<text x="396.480560" y="73.420013" textLength="4.632000" font-size="8px">m</text>
<text x="282.761963" y="80.619995" textLength="2.676000" font-size="8px">s</text>
<text x="470.656769" y="73.420013" textLength="3.144000" font-size="8px">e</text>
<text x="262.440521" y="70.779999" textLength="4.632000" font-size="8px">m</text>
<text x="200.464203" y="70.779999" textLength="2.676000" font-size="8px">s</text>
<text x="143.547607" y="82.900009" textLength="2.250000" font-size="8px">t</text>
<text x="148.653564" y="45.940002" textLength="1.482000" font-size="8px"> </text>
<text x="137.410797" y="82.900009" textLength="3.186000" font-size="8px">u</text>
<text x="326.417969" y="79.720016" textLength="2.604000" font-size="8px">c</text>
<text x="120.539955" y="45.940002" textLength="3.150000" font-size="8px">F</text>
<text x="447.134979" y="102.940002" textLength="3.186000" font-size="8px">u</text>
<text x="215.856567" y="80.619995" textLength="1.170000" font-size="8px">:</text>
<text x="196.021179" y="80.619995" textLength="3.510000" font-size="8px">3</text>
<text x="346.141785" y="99.400009" textLength="1.482000" font-size="8px"> </text>
<text x="333.922211" y="89.560013" textLength="1.170000" font-size="8px">:</text>
<text x="430.996155" y="73.420013" textLength="3.510000" font-size="8px">0</text>
<text x="395.039948" y="93.100006" textLength="1.398000" font-size="8px">I</text>
<text x="352.034973" y="99.400009" textLength="3.774000" font-size="8px">X</text>
<text x="256.747192" y="45.400009" textLength="3.414000" font-size="8px">P</text>
<text x="180.000000" y="90.459991" textLength="1.398000" font-size="8px">I</text>
<text x="381.478760" y="45.940002" textLength="1.284000" font-size="8px">l</text>
<text x="79.957764" y="82.900009" textLength="3.108000" font-size="8px">b</text>
<text x="211.679962" y="32.020004" textLength="3.510000" font-size="8px">4</text>
<text x="421.097382" y="73.420013" textLength="1.482000" font-size="8px"> </text>
<text x="440.296143" y="73.420013" textLength="1.482000" font-size="8px"> </text>
<text x="117.166786" y="82.900009" textLength="1.302000" font-size="8px">i</text>
<text x="414.605957" y="93.100006" textLength="1.170000" font-size="8px">:</text>
<text x="350.579956" y="45.940002" textLength="3.150000" font-size="8px">o</text>
<text x="285.426575" y="80.619995" textLength="2.856000" font-size="8px">k</text>
<text x="364.674561" y="45.940002" textLength="3.150000" font-size="8px">C</text>
<text x="253.761536" y="70.779999" textLength="1.170000" font-size="8px">:</text>
<text x="396.395355" y="45.940002" textLength="2.178000" font-size="8px">r</text>
<text x="317.587799" y="99.400009" textLength="1.842000" font-size="8px">]</text>
<text x="394.219147" y="45.940002" textLength="2.178000" font-size="8px">r</text>
<text x="439.094940" y="73.420013" textLength="1.170000" font-size="8px">:</text>
<text x="319.437592" y="99.400009" textLength="1.482000" font-size="8px"> </text>
<text x="194.220581" y="90.459991" textLength="1.842000" font-size="8px">[</text>
<text x="308.748627" y="89.560013" textLength="3.510000" font-size="8px">8</text>
<text x="349.956573" y="79.720016" textLength="3.510000" font-size="8px">2</text>
<text x="207.792572" y="90.459991" textLength="3.510000" font-size="8px">1</text>
<text x="422.605774" y="93.100006" textLength="3.414000" font-size="8px">=</text>
<text x="437.595551" y="73.420013" textLength="1.482000" font-size="8px"> </text>
<text x="38.039955" y="82.900009" textLength="1.398000" font-size="8px">I</text>
<text x="24.481155" y="44.259995" textLength="4.632000" font-size="8px">m</text>
<text x="441.750549" y="93.100006" textLength="3.618000" font-size="8px">R</text>
<text x="439.094391" y="102.940002" textLength="1.170000" font-size="8px">:</text>
<text x="368.381439" y="89.560013" textLength="3.510000" font-size="8px">0</text>
<text x="134.280548" y="45.940002" textLength="1.482000" font-size="8px"> </text>
<text x="349.055389" y="89.560013" textLength="4.632000" font-size="8px">m</text>
<text x="211.260590" y="80.619995" textLength="3.108000" font-size="8px">b</text>
<text x="199.566559" y="90.459991" textLength="1.842000" font-size="8px">]</text>
<text x="355.635559" y="99.400009" textLength="3.150000" font-size="8px">C</text>
<text x="409.260559" y="73.420013" textLength="1.842000" font-size="8px">[</text>
<text x="246.126556" y="70.779999" textLength="1.302000" font-size="8px">i</text>
<text x="430.963104" y="83.260010" textLength="3.510000" font-size="8px">1</text>
<text x="437.610565" y="93.100006" textLength="1.482000" font-size="8px"> </text>
<text x="325.798187" y="99.400009" textLength="3.510000" font-size="8px">1</text>
<text x="426.008392" y="102.940002" textLength="1.482000" font-size="8px"> </text>
<text x="228.128967" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="457.840179" y="73.420013" textLength="1.482000" font-size="8px"> </text>
<text x="214.357178" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="240.907166" y="70.779999" textLength="3.108000" font-size="8px">p</text>
<text x="425.998779" y="73.420013" textLength="1.482000" font-size="8px"> </text>
<text x="483.250763" y="73.420013" textLength="3.096000" font-size="8px">v</text>
<text x="211.266571" y="90.459991" textLength="3.108000" font-size="8px">b</text>
<text x="457.853363" y="83.260010" textLength="1.482000" font-size="8px"> </text>
<text x="427.493317" y="83.260010" textLength="3.510000" font-size="8px">0</text>
<text x="332.498962" y="79.720016" textLength="1.482000" font-size="8px"> </text>
<text x="202.859985" y="80.619995" textLength="3.414000" font-size="8px">=</text>
<text x="64.065567" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="454.733948" y="83.260010" textLength="3.108000" font-size="8px">d</text>
<text x="301.559998" y="79.720016" textLength="3.150000" font-size="8px">o</text>
<text x="398.571564" y="45.940002" textLength="1.302000" font-size="8px">i</text>
<text x="353.496582" y="79.720016" textLength="1.842000" font-size="8px">]</text>
<text x="215.885345" y="90.459991" textLength="1.170000" font-size="8px">:</text>
<text x="314.107788" y="99.400009" textLength="3.510000" font-size="8px">2</text>
<text x="396.480560" y="93.100006" textLength="4.632000" font-size="8px">m</text>
<text x="256.384125" y="70.779999" textLength="1.398000" font-size="8px">I</text>
<text x="186.061188" y="80.619995" textLength="4.632000" font-size="8px">m</text>
<text x="298.079987" y="99.400009" textLength="1.398000" font-size="8px">I</text>
<text x="62.212166" y="82.900009" textLength="1.842000" font-size="8px">]</text>
<text x="44.092758" y="82.900009" textLength="4.632000" font-size="8px">m</text>
<text x="319.458649" y="89.560013" textLength="1.482000" font-size="8px"> </text>
<text x="270.565735" y="70.779999" textLength="1.842000" font-size="8px">[</text>
<text x="401.100555" y="102.940002" textLength="4.632000" font-size="8px">m</text>
<text x="312.257996" y="99.400009" textLength="1.842000" font-size="8px">[</text>
<text x="335.038177" y="99.400009" textLength="1.482000" font-size="8px"> </text>
<text x="396.480560" y="83.260010" textLength="4.632000" font-size="8px">m</text>
<text x="236.281769" y="90.459991" textLength="2.676000" font-size="8px">s</text>
<text x="444.973785" y="102.940002" textLength="2.178000" font-size="8px">r</text>
<text x="401.103546" y="93.100006" textLength="4.632000" font-size="8px">m</text>
<text x="427.507782" y="102.940002" textLength="3.510000" font-size="8px">1</text>
<text x="267.376160" y="80.619995" textLength="3.150000" font-size="8px">o</text>
<text x="434.536163" y="73.420013" textLength="3.108000" font-size="8px">b</text>
<text x="335.063416" y="89.560013" textLength="1.482000" font-size="8px"> </text>
<text x="249.016144" y="80.619995" textLength="3.144000" font-size="8px">e</text>
<text x="29.101158" y="44.259995" textLength="3.510000" font-size="8px">8</text>
<text x="231.072571" y="90.459991" textLength="2.178000" font-size="8px">r</text>
<text x="160.864166" y="45.940002" textLength="2.250000" font-size="8px">t</text>
<text x="243.916748" y="80.619995" textLength="3.618000" font-size="8px">R</text>
<text x="190.680573" y="90.459991" textLength="3.510000" font-size="8px">8</text>
<text x="253.559998" y="45.400009" textLength="3.186000" font-size="8px">S</text>
<text x="221.170776" y="70.779999" textLength="3.150000" font-size="8px">o</text>
<text x="190.681793" y="80.619995" textLength="3.510000" font-size="8px">8</text>
<text x="311.093384" y="79.720016" textLength="3.108000" font-size="8px">d</text>
<text x="343.054779" y="89.560013" textLength="3.144000" font-size="8px">e</text>
<text x="142.039154" y="45.940002" textLength="1.302000" font-size="8px">i</text>
<text x="462.540558" y="93.100006" textLength="3.108000" font-size="8px">p</text>
<text x="441.710907" y="83.260010" textLength="3.618000" font-size="8px">R</text>
<text x="440.311157" y="93.100006" textLength="1.482000" font-size="8px"> </text>
<text x="252.016754" y="80.619995" textLength="3.192000" font-size="8px">x</text>
<text x="100.188576" y="82.900009" textLength="3.192000" font-size="8px">x</text>
<text x="224.996368" y="80.619995" textLength="3.144000" font-size="8px">e</text>
<text x="135.779968" y="45.940002" textLength="3.108000" font-size="8px">p</text>
<text x="106.307976" y="82.900009" textLength="3.108000" font-size="8px">d</text>
<text x="66.706161" y="82.900009" textLength="1.482000" font-size="8px"> </text>
<text x="343.021179" y="99.400009" textLength="3.144000" font-size="8px">e</text>
<text x="201.360565" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="250.562347" y="70.779999" textLength="3.186000" font-size="8px">n</text>
<text x="197.822998" y="70.779999" textLength="2.676000" font-size="8px">s</text>
<text x="130.103394" y="82.900009" textLength="3.150000" font-size="8px">o</text>
</svg>
<figcaption>Figure 5-28.  Imm8 Controls for VREDUCEPD/SD/PS/SS
</figcaption></figure>
```


Handling of special case of input values are listed in Table 5-21.

###                                             Table 5-21. VREDUCEPD/SD/PS/SS Special Cases


\htmlonly{*} Round control = (imm8.MS1)? MXCSR.RC: imm8.RC



||**Round Mode**|**Returned value **|
||--------------|-------------------|
||Src1| < 2\footnote{-M-1}|RNE|Src1|
||RPI, Src1 > 0|Round (Src1-2\footnote{-M} ) \htmlonly{*}|
||RPI, Src1 "  0|Src1|
||RNI, Src1 *   0|Src1|
||Src1| < 2\footnote{-M}|RNI, Src1 < 0|Round (Src1+2\footnote{-M} ) \htmlonly{*}|
|Src1 = $$\pm$$0, or|NOT RNI|+0.0|
|Dest = $$\pm$$0 (Src1!=INF)|RNI|-0.0|
|Src1 = $$\pm$$INF|any|+0.0|
|Src1= $$\pm$$NAN|n/a|QNaN(Src1)|

### Operation
#### VREDUCEPD 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b == 1) AND (SRC *is memory*)
                      THEN DEST[i+63:i] <-  ReduceArgumentDP(SRC[63:0], imm8[7:0]);
                      ELSE DEST[i+63:i] <-  ReduceArgumentDP(SRC[i+63:i], imm8[7:0]);
                FI;
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[i+63:i] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[i+63:i] = 0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VREDUCEPD __m512d _mm512_mask_reduce_pd( __m512d a, int imm, int sae)
VREDUCEPD __m512d _mm512_mask_reduce_pd(__m512d s, __mmask8 k, __m512d a, int imm, int sae)
VREDUCEPD __m512d _mm512_maskz_reduce_pd(__mmask8 k, __m512d a, int imm, int sae)
VREDUCEPD __m256d _mm256_mask_reduce_pd( __m256d a, int imm)
VREDUCEPD __m256d _mm256_mask_reduce_pd(__m256d s, __mmask8 k, __m256d a, int imm)
VREDUCEPD __m256d _mm256_maskz_reduce_pd(__mmask8 k, __m256d a, int imm)
VREDUCEPD __m128d _mm_mask_reduce_pd( __m128d a, int imm)
VREDUCEPD __m128d _mm_mask_reduce_pd(__m128d s, __mmask8 k, __m128d a, int imm)
VREDUCEPD __m128d _mm_maskz_reduce_pd(__mmask8 k, __m128d a, int imm)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

If SPE is enabled, precision exception is not reported (regardless of MXCSR exception mask).

### Other Exceptions


See Exceptions Type E2, additionally

#UD  If EVEX.vvvv != 1111B.

