----------------------------
title : VRNDSCALEPD (Intel x86/64 assembly instruction)
cat_title : VRNDSCALEPD
ref_title : VRNDSCALEPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VRNDSCALEPD

**Round Packed Float64 Values To Include A Given Number Of Fraction Bits**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F3A.W1 09 /r ib\newline{}VRNDSCALEPD xmm1 {k1}{z}, xmm2/m128/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Rounds packed double-precision floating point values in xmm2/m128/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register. Under writemask.|
|EVEX.256.66.0F3A.W1 09 /r ib\newline{}VRNDSCALEPD ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Rounds packed double-precision floating point values in ymm2/m256/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register. Under writemask.|
|EVEX.512.66.0F3A.W1 09 /r ib\newline{}VRNDSCALEPD zmm1 {k1}{z}, zmm2/m512/m64bcst{sae}, imm8|FV|V/V|AVX512F|Rounds packed double-precision floating-point values in zmm2/m512/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description


Round the double-precision floating-point values in the source operand by the rounding mode specified in the immediate operand (see Figure 5-29) and places the result in the destination operand.

The destination operand (the first operand) is a ZMM/YMM/XMM register conditionally updated according to the writemask. The source operand (the second operand) can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 64-bit memory location.

The rounding process rounds the input to an integral value, plus number bits of fraction that are specified by imm8[7:4] (to be included in the result) and returns the result as a double-precision floating-point value.

It should be noticed that no overflow is induced while executing this instruction (although the source is scaled by the imm8[7:4] value).

The immediate operand also specifies control fields for the rounding operation, three bit fields are defined and shown in the "Immediate Control Description" figure below. Bit 3 of the immediate byte controls the processor behavior for a precision exception, bit 2 selects the source of rounding mode control. Bits 1:0 specify a non-sticky rounding-mode value (Immediate control table below lists the encoded values for rounding-mode field).

The Precision Floating-Point Exception is signaled according to the immediate operand. If any source operand is an SNaN then it will be converted to a QNaN. If DAZ is set to '1 then denormals will be converted to zero before rounding. 

The sign of the result of this instruction is preserved, including the sign of zero.

The formula of the operation on each data element for `VRNDSCALEPD` is

     ROUND(x) = 2\footnote{-M} \htmlonly{\esc{*}}Round\esc{_}to\esc{_}INT(x\htmlonly{\esc{*}}2\footnote{M} , round\esc{_}ctrl), 

     round\esc{_}ctrl = imm[3:0];

     M=imm[7:4];

The operation of x\htmlonly{\esc{*}}2\footnote{M}  is computed as if the exponent range is unlimited (i.e. no overflow ever occurs).



VRNDSCALEPD is a more general form of the VEX-encoded VROUNDPD instruction. In VROUNDPD, the formula of the operation on each element is

     ROUND(x) = Round\esc{_}to\esc{_}INT(x, round\esc{_}ctrl), 

     round\esc{_}ctrl = imm[3:0];

Note: EVEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.

Handling of special case of input values are listed in Table 5-22.

```embed
<figure>
<svg viewBox="0 0 515.880005 135.260010">
<rect x="0.000000" y="10.000000" width="0.480010" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="515.400024" y="10.000000" width="0.479980" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519958" width="515.880005" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="117.100037" width="515.880005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="49.019997" y="36.819946" width="373.260010" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="421.799988" y="37.059998" width="0.480010" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="48.779999" y="50.080017" width="373.260010" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="48.779999" y="36.820007" width="0.480000" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="328.559998" y="37.059937" width="0.479980" height="0.240050" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="328.559998" y="37.299988" width="0.479980" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.259979" y="37.059937" width="0.480010" height="0.240050" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.259979" y="37.299988" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.599998,70.959961 L89.400002,73.899963" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M95.279991,73.419983 L89.399986,73.899963 L91.859993,68.559998" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M115.499992,55.719971 L93.599998,70.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M396.420013,63.039978 L400.440002,66.219971" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M398.279999,60.699951 L400.440002,66.219971 L394.619995,65.319946" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M379.559998,49.719971 L396.420013,63.039978" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="283.259979" y="37.960022" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="283.259979" y="38.199951" width="0.480010" height="11.760000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.419983,66.580017 L306.959991,71.679993" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M309.359985,66.280029 L306.959991,71.680054 L303.479980,66.940002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M304.559998,50.200012 L306.419983,66.580017" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M236.639984,62.440002 L232.019989,64.720032" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M237.899994,65.080017 L232.019989,64.720032 L235.320007,59.799988" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M258.479980,51.700012 L236.639984,62.440002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="238.982971" y="90.460022" textLength="2.676000" font-size="8px">s</text>
<text x="236.281769" y="90.460022" textLength="2.676000" font-size="8px">s</text>
<text x="224.881165" y="90.460022" textLength="3.108000" font-size="8px">p</text>
<text x="215.885345" y="90.460022" textLength="1.170000" font-size="8px">:</text>
<text x="207.792572" y="90.460022" textLength="3.510000" font-size="8px">1</text>
<text x="206.293182" y="90.460022" textLength="1.482000" font-size="8px"> </text>
<text x="202.871979" y="90.460022" textLength="3.414000" font-size="8px">=</text>
<text x="201.372559" y="90.460022" textLength="1.482000" font-size="8px"> </text>
<text x="199.566559" y="90.460022" textLength="1.842000" font-size="8px">]</text>
<text x="196.026581" y="90.460022" textLength="3.510000" font-size="8px">3</text>
<text x="190.680573" y="90.460022" textLength="3.510000" font-size="8px">8</text>
<text x="180.000000" y="90.460022" textLength="1.398000" font-size="8px">I</text>
<text x="275.170746" y="80.619995" textLength="4.632000" font-size="8px">m</text>
<text x="273.671356" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="270.496765" y="80.619995" textLength="3.186000" font-size="8px">n</text>
<text x="263.774963" y="80.619995" textLength="2.250000" font-size="8px">t</text>
<text x="257.714966" y="80.619995" textLength="3.144000" font-size="8px">e</text>
<text x="249.016144" y="80.619995" textLength="3.144000" font-size="8px">e</text>
<text x="229.628357" y="80.619995" textLength="4.386000" font-size="8px">M</text>
<text x="222.295166" y="80.619995" textLength="2.676000" font-size="8px">s</text>
<text x="215.856567" y="80.619995" textLength="1.170000" font-size="8px">:</text>
<text x="214.357178" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="211.260590" y="80.619995" textLength="3.108000" font-size="8px">b</text>
<text x="206.262573" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="196.021179" y="80.619995" textLength="3.510000" font-size="8px">3</text>
<text x="186.061188" y="80.619995" textLength="4.632000" font-size="8px">m</text>
<text x="277.756134" y="70.779968" textLength="1.482000" font-size="8px"> </text>
<text x="275.900940" y="70.779968" textLength="1.842000" font-size="8px">]</text>
<text x="270.565735" y="70.779968" textLength="1.842000" font-size="8px">[</text>
<text x="254.944733" y="70.779968" textLength="1.482000" font-size="8px"> </text>
<text x="253.761536" y="70.779968" textLength="1.170000" font-size="8px">:</text>
<text x="202.859985" y="80.619995" textLength="3.414000" font-size="8px">=</text>
<text x="247.441742" y="70.779968" textLength="3.150000" font-size="8px">o</text>
<text x="243.846558" y="70.779968" textLength="2.250000" font-size="8px">t</text>
<text x="237.786560" y="70.779968" textLength="3.144000" font-size="8px">e</text>
<text x="235.169373" y="70.779968" textLength="2.604000" font-size="8px">c</text>
<text x="227.490570" y="70.779968" textLength="1.482000" font-size="8px"> </text>
<text x="221.170776" y="70.779968" textLength="3.150000" font-size="8px">o</text>
<text x="181.440582" y="90.460022" textLength="4.632000" font-size="8px">m</text>
<text x="215.893188" y="70.779968" textLength="1.302000" font-size="8px">i</text>
<text x="189.481781" y="70.779968" textLength="3.108000" font-size="8px">p</text>
<text x="186.422394" y="70.779968" textLength="3.108000" font-size="8px">p</text>
<text x="358.756165" y="99.400024" textLength="3.186000" font-size="8px">S</text>
<text x="355.635559" y="99.400024" textLength="3.150000" font-size="8px">C</text>
<text x="346.141785" y="99.400024" textLength="1.482000" font-size="8px"> </text>
<text x="336.537567" y="99.400024" textLength="3.792000" font-size="8px">U</text>
<text x="335.038177" y="99.400024" textLength="1.482000" font-size="8px"> </text>
<text x="325.798187" y="99.400024" textLength="3.510000" font-size="8px">1</text>
<text x="324.298798" y="99.400024" textLength="1.482000" font-size="8px"> </text>
<text x="320.876984" y="99.400024" textLength="3.414000" font-size="8px">=</text>
<text x="314.107788" y="99.400024" textLength="3.510000" font-size="8px">2</text>
<text x="312.257996" y="99.400024" textLength="1.842000" font-size="8px">[</text>
<text x="353.699402" y="89.559998" textLength="4.632000" font-size="8px">m</text>
<text x="347.674774" y="89.559998" textLength="1.398000" font-size="8px">I</text>
<text x="207.761993" y="80.619995" textLength="3.510000" font-size="8px">0</text>
<text x="336.562805" y="89.559998" textLength="3.792000" font-size="8px">U</text>
<text x="335.063416" y="89.559998" textLength="1.482000" font-size="8px"> </text>
<text x="329.303436" y="89.559998" textLength="3.108000" font-size="8px">b</text>
<text x="324.324036" y="89.559998" textLength="1.482000" font-size="8px"> </text>
<text x="312.270630" y="89.559998" textLength="1.842000" font-size="8px">[</text>
<text x="308.748627" y="89.559998" textLength="3.510000" font-size="8px">8</text>
<text x="353.496582" y="79.719971" textLength="1.842000" font-size="8px">]</text>
<text x="343.021179" y="99.400024" textLength="3.144000" font-size="8px">e</text>
<text x="349.956573" y="79.719971" textLength="3.510000" font-size="8px">2</text>
<text x="348.124176" y="79.719971" textLength="1.842000" font-size="8px">[</text>
<text x="344.623779" y="79.719971" textLength="3.510000" font-size="8px">8</text>
<text x="333.938354" y="79.719971" textLength="1.398000" font-size="8px">I</text>
<text x="304.104614" y="89.559998" textLength="4.632000" font-size="8px">m</text>
<text x="332.498962" y="79.719971" textLength="1.482000" font-size="8px"> </text>
<text x="323.283569" y="79.719971" textLength="3.144000" font-size="8px">e</text>
<text x="315.652161" y="79.719971" textLength="3.186000" font-size="8px">S</text>
<text x="314.152771" y="79.719971" textLength="1.482000" font-size="8px"> </text>
<text x="307.916992" y="79.719971" textLength="3.186000" font-size="8px">n</text>
<text x="301.559998" y="79.719971" textLength="3.150000" font-size="8px">o</text>
<text x="256.747192" y="45.399963" textLength="3.414000" font-size="8px">P</text>
<text x="253.559998" y="45.399963" textLength="3.186000" font-size="8px">S</text>
<text x="29.101158" y="44.200134" textLength="3.510000" font-size="8px">8</text>
<text x="24.481155" y="44.200134" textLength="4.632000" font-size="8px">m</text>
<text x="19.861156" y="44.200134" textLength="4.632000" font-size="8px">m</text>
<text x="461.220001" y="102.880127" textLength="3.144000" font-size="8px">e</text>
<text x="459.005402" y="102.880127" textLength="2.250000" font-size="8px">t</text>
<text x="453.557404" y="102.880127" textLength="2.604000" font-size="8px">c</text>
<text x="450.316193" y="102.880127" textLength="3.186000" font-size="8px">n</text>
<text x="447.134979" y="102.880127" textLength="3.186000" font-size="8px">u</text>
<text x="444.973785" y="102.880127" textLength="2.178000" font-size="8px">r</text>
<text x="440.295593" y="102.880127" textLength="1.482000" font-size="8px"> </text>
<text x="439.094391" y="102.880127" textLength="1.170000" font-size="8px">:</text>
<text x="437.595001" y="102.880127" textLength="1.482000" font-size="8px"> </text>
<text x="361.865417" y="89.559998" textLength="1.842000" font-size="8px">[</text>
<text x="434.522400" y="102.880127" textLength="3.108000" font-size="8px">b</text>
<text x="427.507782" y="102.880127" textLength="3.510000" font-size="8px">1</text>
<text x="426.008392" y="102.880127" textLength="1.482000" font-size="8px"> </text>
<text x="422.587799" y="102.880127" textLength="3.414000" font-size="8px">=</text>
<text x="421.088409" y="102.880127" textLength="1.482000" font-size="8px"> </text>
<text x="211.266571" y="90.460022" textLength="3.108000" font-size="8px">b</text>
<text x="411.067169" y="102.880127" textLength="3.510000" font-size="8px">1</text>
<text x="409.260559" y="102.880127" textLength="1.842000" font-size="8px">[</text>
<text x="405.720551" y="102.880127" textLength="3.510000" font-size="8px">8</text>
<text x="396.480560" y="102.880127" textLength="4.632000" font-size="8px">m</text>
<text x="395.039948" y="102.880127" textLength="1.398000" font-size="8px">I</text>
<text x="459.363556" y="93.040100" textLength="3.186000" font-size="8px">u</text>
<text x="454.765167" y="93.040100" textLength="3.108000" font-size="8px">d</text>
<text x="451.588165" y="93.040100" textLength="3.186000" font-size="8px">n</text>
<text x="440.311157" y="93.040100" textLength="1.482000" font-size="8px"> </text>
<text x="439.109955" y="93.040100" textLength="1.170000" font-size="8px">:</text>
<text x="434.551178" y="93.040100" textLength="3.108000" font-size="8px">b</text>
<text x="457.864166" y="93.040100" textLength="1.482000" font-size="8px"> </text>
<text x="427.510162" y="93.040100" textLength="3.510000" font-size="8px">1</text>
<text x="426.010773" y="93.040100" textLength="1.482000" font-size="8px"> </text>
<text x="224.996368" y="80.619995" textLength="3.144000" font-size="8px">e</text>
<text x="422.605774" y="93.040100" textLength="3.414000" font-size="8px">=</text>
<text x="421.106384" y="93.040100" textLength="1.482000" font-size="8px"> </text>
<text x="414.607178" y="102.880127" textLength="1.170000" font-size="8px">:</text>
<text x="405.726532" y="93.040100" textLength="3.510000" font-size="8px">8</text>
<text x="401.103546" y="93.040100" textLength="4.632000" font-size="8px">m</text>
<text x="243.916748" y="80.619995" textLength="3.618000" font-size="8px">R</text>
<text x="396.480560" y="93.040100" textLength="4.632000" font-size="8px">m</text>
<text x="470.161163" y="83.260071" textLength="3.186000" font-size="8px">n</text>
<text x="465.481171" y="83.260071" textLength="4.632000" font-size="8px">w</text>
<text x="462.420563" y="83.260071" textLength="3.150000" font-size="8px">o</text>
<text x="457.853363" y="83.260071" textLength="1.482000" font-size="8px"> </text>
<text x="454.733948" y="83.260071" textLength="3.108000" font-size="8px">d</text>
<text x="448.371521" y="83.260071" textLength="3.186000" font-size="8px">u</text>
<text x="247.576752" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="194.221802" y="80.619995" textLength="1.842000" font-size="8px">[</text>
<text x="441.710907" y="83.260071" textLength="3.618000" font-size="8px">R</text>
<text x="340.337372" y="99.400024" textLength="2.676000" font-size="8px">s</text>
<text x="439.070312" y="83.260071" textLength="1.170000" font-size="8px">:</text>
<text x="427.493317" y="83.260071" textLength="3.510000" font-size="8px">0</text>
<text x="425.993927" y="83.260071" textLength="1.482000" font-size="8px"> </text>
<text x="419.272156" y="83.260071" textLength="1.842000" font-size="8px">]</text>
<text x="340.366791" y="89.559998" textLength="2.676000" font-size="8px">s</text>
<text x="415.732147" y="83.260071" textLength="3.510000" font-size="8px">0</text>
<text x="411.062347" y="83.260071" textLength="3.510000" font-size="8px">1</text>
<text x="409.260559" y="83.260071" textLength="1.842000" font-size="8px">[</text>
<text x="401.100555" y="83.260071" textLength="4.632000" font-size="8px">m</text>
<text x="395.039948" y="83.260071" textLength="1.398000" font-size="8px">I</text>
<text x="489.382172" y="73.420044" textLength="3.186000" font-size="8px">n</text>
<text x="483.250763" y="73.420044" textLength="3.096000" font-size="8px">v</text>
<text x="478.690765" y="73.420044" textLength="1.482000" font-size="8px"> </text>
<text x="476.452789" y="73.420044" textLength="2.250000" font-size="8px">t</text>
<text x="473.788788" y="73.420044" textLength="2.676000" font-size="8px">s</text>
<text x="468.615570" y="73.420044" textLength="2.178000" font-size="8px">r</text>
<text x="465.645569" y="73.420044" textLength="2.982000" font-size="8px">a</text>
<text x="457.840179" y="73.420044" textLength="1.482000" font-size="8px"> </text>
<text x="454.744171" y="73.420044" textLength="3.108000" font-size="8px">d</text>
<text x="451.570160" y="73.420044" textLength="3.186000" font-size="8px">n</text>
<text x="459.339569" y="73.420044" textLength="3.186000" font-size="8px">n</text>
<text x="445.215546" y="73.420044" textLength="3.150000" font-size="8px">o</text>
<text x="440.296143" y="73.420044" textLength="1.482000" font-size="8px"> </text>
<text x="430.996155" y="73.420044" textLength="3.510000" font-size="8px">0</text>
<text x="421.073944" y="83.260071" textLength="1.482000" font-size="8px"> </text>
<text x="422.596771" y="73.420044" textLength="3.414000" font-size="8px">=</text>
<text x="421.097382" y="73.420044" textLength="1.482000" font-size="8px"> </text>
<text x="419.297974" y="73.420044" textLength="1.842000" font-size="8px">]</text>
<text x="415.757965" y="73.420044" textLength="3.510000" font-size="8px">0</text>
<text x="346.175385" y="89.559998" textLength="1.482000" font-size="8px"> </text>
<text x="401.100555" y="73.420044" textLength="4.632000" font-size="8px">m</text>
<text x="396.480560" y="73.420044" textLength="4.632000" font-size="8px">m</text>
<text x="304.679962" y="45.400024" textLength="3.186000" font-size="8px">S</text>
<text x="151.065613" y="82.900024" textLength="3.096000" font-size="8px">v</text>
<text x="148.904419" y="82.900024" textLength="2.178000" font-size="8px">r</text>
<text x="409.266541" y="93.040100" textLength="1.842000" font-size="8px">[</text>
<text x="145.745422" y="82.900024" textLength="3.144000" font-size="8px">e</text>
<text x="143.104218" y="82.900024" textLength="2.676000" font-size="8px">s</text>
<text x="134.781036" y="82.900024" textLength="3.108000" font-size="8px">p</text>
<text x="133.341614" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="126.501610" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="123.860405" y="82.900024" textLength="2.676000" font-size="8px">s</text>
<text x="201.360565" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="121.595406" y="82.900024" textLength="2.250000" font-size="8px">t</text>
<text x="114.096596" y="82.900024" textLength="3.150000" font-size="8px">o</text>
<text x="110.973595" y="82.900024" textLength="3.108000" font-size="8px">p</text>
<text x="109.474190" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="106.351189" y="82.900024" textLength="3.108000" font-size="8px">d</text>
<text x="96.673790" y="82.900024" textLength="2.226000" font-size="8px">f</text>
<text x="92.954979" y="82.900024" textLength="2.226000" font-size="8px">f</text>
<text x="88.454979" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="86.233772" y="82.900024" textLength="2.178000" font-size="8px">r</text>
<text x="361.997375" y="99.400024" textLength="3.618000" font-size="8px">R</text>
<text x="75.343163" y="82.900024" textLength="4.632000" font-size="8px">m</text>
<text x="72.142166" y="82.900024" textLength="3.186000" font-size="8px">u</text>
<text x="355.295990" y="79.719971" textLength="1.482000" font-size="8px"> </text>
<text x="68.227165" y="82.900024" textLength="3.900000" font-size="8px">N</text>
<text x="66.727768" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="64.087173" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="58.750168" y="82.900024" textLength="3.510000" font-size="8px">4</text>
<text x="39.452957" y="82.900024" textLength="4.632000" font-size="8px">m</text>
<text x="163.084747" y="45.880005" textLength="3.186000" font-size="8px">h</text>
<text x="160.864166" y="45.880005" textLength="2.250000" font-size="8px">t</text>
<text x="154.588165" y="45.880005" textLength="3.186000" font-size="8px">n</text>
<text x="146.432953" y="45.880005" textLength="2.250000" font-size="8px">t</text>
<text x="143.311768" y="45.880005" textLength="3.186000" font-size="8px">n</text>
<text x="480.190155" y="73.420044" textLength="3.144000" font-size="8px">e</text>
<text x="138.858551" y="45.880005" textLength="3.150000" font-size="8px">o</text>
<text x="54.083969" y="82.900024" textLength="3.510000" font-size="8px">7</text>
<text x="134.280548" y="45.880005" textLength="1.482000" font-size="8px"> </text>
<text x="125.041756" y="45.880005" textLength="3.192000" font-size="8px">x</text>
<text x="120.539955" y="45.880005" textLength="3.150000" font-size="8px">F</text>
<text x="272.420929" y="70.779968" textLength="3.510000" font-size="8px">3</text>
<text x="260.162384" y="45.399963" textLength="3.150000" font-size="8px">E</text>
<text x="396.395355" y="45.880005" textLength="2.178000" font-size="8px">r</text>
<text x="388.039154" y="45.880005" textLength="3.096000" font-size="8px">v</text>
<text x="384.260345" y="45.880005" textLength="3.822000" font-size="8px">O</text>
<text x="382.760956" y="45.880005" textLength="1.482000" font-size="8px"> </text>
<text x="320.898041" y="89.559998" textLength="3.414000" font-size="8px">=</text>
<text x="381.478760" y="45.880005" textLength="1.284000" font-size="8px">l</text>
<text x="378.298157" y="45.880005" textLength="3.150000" font-size="8px">o</text>
<text x="364.674561" y="45.880005" textLength="3.150000" font-size="8px">C</text>
<text x="360.068970" y="45.880005" textLength="3.108000" font-size="8px">d</text>
<text x="353.700562" y="45.880005" textLength="3.186000" font-size="8px">u</text>
<text x="350.579956" y="45.880005" textLength="3.150000" font-size="8px">o</text>
<text x="57.608971" y="82.900024" textLength="1.170000" font-size="8px">:</text>
<text x="347.039948" y="45.880005" textLength="3.618000" font-size="8px">R</text>
<text x="350.819977" y="32.020020" textLength="3.510000" font-size="8px">1</text>
<text x="317.587799" y="99.400024" textLength="1.842000" font-size="8px">]</text>
<text x="335.378967" y="79.719971" textLength="4.632000" font-size="8px">m</text>
<text x="128.001007" y="82.900024" textLength="2.250000" font-size="8px">t</text>
<text x="118.534203" y="82.900024" textLength="3.186000" font-size="8px">n</text>
<text x="165.299957" y="32.020020" textLength="3.510000" font-size="8px">5</text>
<text x="118.979973" y="32.020020" textLength="3.510000" font-size="8px">6</text>
<text x="397.139984" y="32.020020" textLength="3.510000" font-size="8px">0</text>
<text x="445.190918" y="83.260071" textLength="3.150000" font-size="8px">o</text>
<text x="257.795319" y="70.779968" textLength="4.632000" font-size="8px">m</text>
<text x="267.085724" y="70.779968" textLength="3.510000" font-size="8px">8</text>
<text x="304.100403" y="99.400024" textLength="4.632000" font-size="8px">m</text>
<text x="83.113167" y="82.900024" textLength="3.144000" font-size="8px">e</text>
<text x="394.219147" y="45.880005" textLength="2.178000" font-size="8px">r</text>
<text x="437.610565" y="93.040100" textLength="1.482000" font-size="8px"> </text>
<text x="326.417969" y="79.719971" textLength="2.604000" font-size="8px">c</text>
<text x="211.679962" y="32.020020" textLength="3.510000" font-size="8px">4</text>
<text x="217.015167" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="279.791351" y="80.619995" textLength="2.982000" font-size="8px">a</text>
<text x="370.915771" y="45.880005" textLength="3.186000" font-size="8px">n</text>
<text x="224.291382" y="70.779968" textLength="3.186000" font-size="8px">n</text>
<text x="210.133209" y="70.779968" textLength="3.144000" font-size="8px">e</text>
<text x="228.000580" y="90.460022" textLength="3.108000" font-size="8px">p</text>
<text x="367.199432" y="89.559998" textLength="1.170000" font-size="8px">:</text>
<text x="218.518738" y="90.460022" textLength="3.186000" font-size="8px">S</text>
<text x="194.642395" y="70.779968" textLength="3.144000" font-size="8px">e</text>
<text x="250.562347" y="70.779968" textLength="3.186000" font-size="8px">n</text>
<text x="52.226967" y="82.900024" textLength="1.842000" font-size="8px">[</text>
<text x="200.464203" y="70.779968" textLength="2.676000" font-size="8px">s</text>
<text x="437.570923" y="83.260071" textLength="1.482000" font-size="8px"> </text>
<text x="186.060577" y="90.460022" textLength="4.632000" font-size="8px">m</text>
<text x="183.241180" y="70.779968" textLength="3.186000" font-size="8px">u</text>
<text x="299.460602" y="99.400024" textLength="4.632000" font-size="8px">m</text>
<text x="318.828552" y="79.719971" textLength="3.144000" font-size="8px">e</text>
<text x="258.059967" y="32.020020" textLength="3.510000" font-size="8px">3</text>
<text x="317.604645" y="89.559998" textLength="1.842000" font-size="8px">]</text>
<text x="233.173767" y="90.460022" textLength="3.144000" font-size="8px">e</text>
<text x="343.054779" y="89.559998" textLength="3.144000" font-size="8px">e</text>
<text x="459.352753" y="83.260071" textLength="3.108000" font-size="8px">d</text>
<text x="331.297760" y="79.719971" textLength="1.170000" font-size="8px">:</text>
<text x="197.822998" y="70.779968" textLength="2.676000" font-size="8px">s</text>
<text x="255.075562" y="80.619995" textLength="2.604000" font-size="8px">c</text>
<text x="371.861450" y="89.559998" textLength="1.842000" font-size="8px">]</text>
<text x="395.039948" y="73.420044" textLength="1.398000" font-size="8px">I</text>
<text x="347.641174" y="99.400024" textLength="4.386000" font-size="8px">M</text>
<text x="79.990166" y="82.900024" textLength="3.108000" font-size="8px">b</text>
<text x="157.744751" y="45.880005" textLength="3.108000" font-size="8px">g</text>
<text x="395.039948" y="93.040100" textLength="1.398000" font-size="8px">I</text>
<text x="48.746964" y="82.900024" textLength="3.510000" font-size="8px">8</text>
<text x="434.503113" y="83.260071" textLength="3.108000" font-size="8px">b</text>
<text x="440.271515" y="83.260071" textLength="1.482000" font-size="8px"> </text>
<text x="356.884766" y="45.880005" textLength="3.186000" font-size="8px">n</text>
<text x="462.513580" y="73.420044" textLength="3.144000" font-size="8px">e</text>
<text x="154.065033" y="82.900024" textLength="3.144000" font-size="8px">e</text>
<text x="437.595551" y="73.420044" textLength="1.482000" font-size="8px"> </text>
<text x="402.977966" y="45.880005" textLength="3.144000" font-size="8px">e</text>
<text x="441.735535" y="73.420044" textLength="3.618000" font-size="8px">R</text>
<text x="298.079987" y="89.559998" textLength="1.398000" font-size="8px">I</text>
<text x="367.735168" y="45.880005" textLength="3.150000" font-size="8px">o</text>
<text x="445.230560" y="93.040100" textLength="3.150000" font-size="8px">o</text>
<text x="486.250153" y="73.420044" textLength="3.144000" font-size="8px">e</text>
<text x="228.989960" y="70.779968" textLength="3.150000" font-size="8px">E</text>
<text x="256.384125" y="70.779968" textLength="1.398000" font-size="8px">I</text>
<text x="98.914787" y="82.900024" textLength="1.302000" font-size="8px">i</text>
<text x="181.440582" y="80.619995" textLength="4.632000" font-size="8px">m</text>
<text x="401.100555" y="102.880127" textLength="4.632000" font-size="8px">m</text>
<text x="430.982391" y="102.880127" textLength="3.510000" font-size="8px">1</text>
<text x="462.540558" y="93.040100" textLength="3.108000" font-size="8px">p</text>
<text x="65.586571" y="82.900024" textLength="1.170000" font-size="8px">:</text>
<text x="396.480560" y="83.260071" textLength="4.632000" font-size="8px">m</text>
<text x="304.439972" y="32.020020" textLength="3.510000" font-size="8px">2</text>
<text x="240.742157" y="80.619995" textLength="3.186000" font-size="8px">S</text>
<text x="237.603546" y="80.619995" textLength="3.150000" font-size="8px">C</text>
<text x="221.699951" y="90.460022" textLength="3.186000" font-size="8px">u</text>
<text x="260.835571" y="80.619995" textLength="3.108000" font-size="8px">p</text>
<text x="262.440521" y="70.779968" textLength="4.632000" font-size="8px">m</text>
<text x="137.904022" y="82.900024" textLength="2.178000" font-size="8px">r</text>
<text x="451.552734" y="83.260071" textLength="3.186000" font-size="8px">n</text>
<text x="190.681793" y="80.619995" textLength="3.510000" font-size="8px">8</text>
<text x="192.601196" y="70.779968" textLength="2.178000" font-size="8px">r</text>
<text x="123.720558" y="45.880005" textLength="1.302000" font-size="8px">i</text>
<text x="266.054962" y="80.619995" textLength="1.302000" font-size="8px">i</text>
<text x="431.011169" y="93.040100" textLength="3.510000" font-size="8px">0</text>
<text x="419.306976" y="93.040100" textLength="1.842000" font-size="8px">]</text>
<text x="352.034973" y="99.400024" textLength="3.774000" font-size="8px">X</text>
<text x="409.260559" y="73.420044" textLength="1.842000" font-size="8px">[</text>
<text x="308.740204" y="99.400024" textLength="3.510000" font-size="8px">8</text>
<text x="131.161163" y="45.880005" textLength="3.108000" font-size="8px">d</text>
<text x="150.152954" y="45.880005" textLength="1.284000" font-size="8px">l</text>
<text x="399.871765" y="45.880005" textLength="3.108000" font-size="8px">d</text>
<text x="329.278198" y="99.400024" textLength="3.108000" font-size="8px">b</text>
<text x="301.079956" y="45.400024" textLength="3.618000" font-size="8px">R</text>
<text x="72.599998" y="32.020020" textLength="3.510000" font-size="8px">7</text>
<text x="329.057373" y="79.719971" textLength="2.250000" font-size="8px">t</text>
<text x="135.779968" y="45.880005" textLength="3.108000" font-size="8px">p</text>
<text x="285.426575" y="80.619995" textLength="2.856000" font-size="8px">k</text>
<text x="299.460602" y="89.559998" textLength="4.632000" font-size="8px">m</text>
<text x="434.536163" y="73.420044" textLength="3.108000" font-size="8px">b</text>
<text x="100.231789" y="82.900024" textLength="3.192000" font-size="8px">x</text>
<text x="398.571564" y="45.880005" textLength="1.302000" font-size="8px">i</text>
<text x="231.072571" y="90.460022" textLength="2.178000" font-size="8px">r</text>
<text x="208.092010" y="70.779968" textLength="2.178000" font-size="8px">r</text>
<text x="325.823425" y="89.559998" textLength="3.510000" font-size="8px">0</text>
<text x="311.093384" y="79.719971" textLength="3.108000" font-size="8px">d</text>
<text x="62.230171" y="82.900024" textLength="1.842000" font-size="8px">]</text>
<text x="363.175171" y="45.880005" textLength="1.482000" font-size="8px"> </text>
<text x="282.761963" y="80.619995" textLength="2.676000" font-size="8px">s</text>
<text x="470.656769" y="73.420044" textLength="3.144000" font-size="8px">e</text>
<text x="456.126007" y="102.880127" textLength="2.982000" font-size="8px">a</text>
<text x="332.422821" y="89.559998" textLength="1.482000" font-size="8px"> </text>
<text x="376.256958" y="45.880005" textLength="2.178000" font-size="8px">r</text>
<text x="252.016754" y="80.619995" textLength="3.192000" font-size="8px">x</text>
<text x="363.719421" y="89.559998" textLength="3.510000" font-size="8px">1</text>
<text x="441.750549" y="93.040100" textLength="3.618000" font-size="8px">R</text>
<text x="415.766968" y="93.040100" textLength="3.510000" font-size="8px">0</text>
<text x="422.573334" y="83.260071" textLength="3.414000" font-size="8px">=</text>
<text x="419.281799" y="102.880127" textLength="1.842000" font-size="8px">]</text>
<text x="414.602356" y="83.260071" textLength="1.170000" font-size="8px">:</text>
<text x="89.894386" y="82.900024" textLength="3.150000" font-size="8px">o</text>
<text x="18.539955" y="44.200134" textLength="1.302000" font-size="8px">i</text>
<text x="44.099960" y="82.900024" textLength="4.632000" font-size="8px">m</text>
<text x="411.065948" y="93.040100" textLength="3.510000" font-size="8px">1</text>
<text x="240.907166" y="70.779968" textLength="3.108000" font-size="8px">p</text>
<text x="38.039955" y="82.900024" textLength="1.398000" font-size="8px">I</text>
<text x="194.220581" y="90.460022" textLength="1.842000" font-size="8px">[</text>
<text x="430.963104" y="83.260071" textLength="3.510000" font-size="8px">1</text>
<text x="117.217201" y="82.900024" textLength="1.302000" font-size="8px">i</text>
<text x="373.976959" y="45.880005" textLength="2.250000" font-size="8px">t</text>
<text x="232.110565" y="70.779968" textLength="3.192000" font-size="8px">x</text>
<text x="349.055389" y="89.559998" textLength="4.632000" font-size="8px">m</text>
<text x="319.458649" y="89.559998" textLength="1.482000" font-size="8px"> </text>
<text x="415.741791" y="102.880127" textLength="3.510000" font-size="8px">0</text>
<text x="148.653564" y="45.880005" textLength="1.482000" font-size="8px"> </text>
<text x="199.561188" y="80.619995" textLength="1.842000" font-size="8px">]</text>
<text x="439.094940" y="73.420044" textLength="1.170000" font-size="8px">:</text>
<text x="151.407562" y="45.880005" textLength="3.144000" font-size="8px">e</text>
<text x="441.734985" y="102.880127" textLength="3.456000" font-size="8px">T</text>
<text x="414.605957" y="93.040100" textLength="1.170000" font-size="8px">:</text>
<text x="246.126556" y="70.779968" textLength="1.302000" font-size="8px">i</text>
<text x="448.396149" y="73.420044" textLength="3.186000" font-size="8px">u</text>
<text x="411.059967" y="73.420044" textLength="3.510000" font-size="8px">1</text>
<text x="139.945221" y="82.900024" textLength="3.144000" font-size="8px">e</text>
<text x="203.165405" y="70.779968" textLength="1.482000" font-size="8px"> </text>
<text x="95.174385" y="82.900024" textLength="1.482000" font-size="8px"> </text>
<text x="304.740601" y="79.719971" textLength="3.186000" font-size="8px">u</text>
<text x="180.000000" y="70.779968" textLength="3.186000" font-size="8px">S</text>
<text x="448.411163" y="93.040100" textLength="3.186000" font-size="8px">u</text>
<text x="219.855591" y="70.779968" textLength="1.302000" font-size="8px">i</text>
<text x="333.896973" y="99.400024" textLength="1.170000" font-size="8px">:</text>
<text x="368.381439" y="89.559998" textLength="3.510000" font-size="8px">0</text>
<text x="298.079987" y="99.400024" textLength="1.398000" font-size="8px">I</text>
<text x="103.230583" y="82.900024" textLength="3.144000" font-size="8px">e</text>
<text x="234.002960" y="80.619995" textLength="3.774000" font-size="8px">X</text>
<text x="217.154388" y="70.779968" textLength="2.676000" font-size="8px">s</text>
<text x="319.437592" y="99.400024" textLength="1.482000" font-size="8px"> </text>
<text x="405.720551" y="83.260071" textLength="3.510000" font-size="8px">8</text>
<text x="333.922211" y="89.559998" textLength="1.170000" font-size="8px">:</text>
<text x="218.514557" y="80.619995" textLength="3.792000" font-size="8px">U</text>
<text x="332.397583" y="99.400024" textLength="1.482000" font-size="8px"> </text>
<text x="391.038544" y="45.880005" textLength="3.144000" font-size="8px">e</text>
<text x="128.040558" y="45.880005" textLength="3.144000" font-size="8px">e</text>
<text x="358.343414" y="89.559998" textLength="3.510000" font-size="8px">8</text>
<text x="405.720551" y="73.420044" textLength="3.510000" font-size="8px">8</text>
<text x="214.385956" y="90.460022" textLength="1.482000" font-size="8px"> </text>
<text x="267.376160" y="80.619995" textLength="3.150000" font-size="8px">o</text>
<text x="217.019348" y="90.460022" textLength="1.482000" font-size="8px"> </text>
<text x="130.161011" y="82.900024" textLength="3.150000" font-size="8px">o</text>
<text x="322.009155" y="79.719971" textLength="1.284000" font-size="8px">l</text>
<text x="142.039154" y="45.880005" textLength="1.302000" font-size="8px">i</text>
<text x="204.664795" y="70.779968" textLength="3.414000" font-size="8px">P</text>
<text x="298.079987" y="79.719971" textLength="3.618000" font-size="8px">R</text>
<text x="314.124634" y="89.559998" textLength="3.510000" font-size="8px">2</text>
<text x="427.498169" y="73.420044" textLength="3.510000" font-size="8px">0</text>
<text x="180.000000" y="80.619995" textLength="1.398000" font-size="8px">I</text>
<text x="213.253784" y="70.779968" textLength="2.604000" font-size="8px">c</text>
<text x="414.599976" y="73.420044" textLength="1.170000" font-size="8px">:</text>
<text x="425.998779" y="73.420044" textLength="1.482000" font-size="8px"> </text>
<text x="228.128967" y="80.619995" textLength="1.482000" font-size="8px"> </text>
<text x="340.001373" y="79.719971" textLength="4.632000" font-size="8px">m</text>
</svg>
<figcaption>Figure 5-29.  Imm8 Controls for VRNDSCALEPD/SD/PS/SS
</figcaption></figure>
```
### Table 5-22. VRNDSCALEPD/SD/PS/SS Special Cases


||**Returned value **|
||-------------------|
|**Src1=$$\pm$$inf **|Src1|
|**Src1=$$\pm$$NAN**|Src1 converted to QNAN|
|**Src1=$$\pm$$0**|Src1|

### Operation
#### VRNDSCALEPD (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF *src is a memory operand*
    THEN TMP_SRC <-  BROADCAST64(SRC, VL, k1)
    ELSE TMP_SRC <-  SRC
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  RoundToIntegerDP((TMP_SRC[i+63:i], imm8[7:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[i+63:i] remains unchanged*
                ELSE  ; zeroing-masking
                      DEST[i+63:i] <-  0
          FI;
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRNDSCALEPD __m512d _mm512_roundscale_pd( __m512d a, int imm);
VRNDSCALEPD __m512d _mm512_roundscale_round_pd( __m512d a, int imm, int sae);
VRNDSCALEPD __m512d _mm512_mask_roundscale_pd(__m512d s, __mmask8 k, __m512d a, int imm);
VRNDSCALEPD __m512d _mm512_mask_roundscale_round_pd(__m512d s, __mmask8 k, __m512d a, int imm, int sae);
VRNDSCALEPD __m512d _mm512_maskz_roundscale_pd( __mmask8 k, __m512d a, int imm);
VRNDSCALEPD __m512d _mm512_maskz_roundscale_round_pd( __mmask8 k, __m512d a, int imm, int sae);
VRNDSCALEPD __m256d _mm256_roundscale_pd( __m256d a, int imm);
VRNDSCALEPD __m256d _mm256_mask_roundscale_pd(__m256d s, __mmask8 k, __m256d a, int imm);
VRNDSCALEPD __m256d _mm256_maskz_roundscale_pd( __mmask8 k, __m256d a, int imm);
VRNDSCALEPD __m128d _mm_roundscale_pd( __m128d a, int imm);
VRNDSCALEPD __m128d _mm_mask_roundscale_pd(__m128d s, __mmask8 k, __m128d a, int imm);
VRNDSCALEPD __m128d _mm_maskz_roundscale_pd( __mmask8 k, __m128d a, int imm);
```
### SIMD Floating-Point Exceptions


Invalid, Precision

If SPE is enabled, precision exception is not reported (regardless of MXCSR exception mask).

### Other Exceptions


See Exceptions Type E2.

