----------------------------
title : VGETMANTPD (Intel x86/64 assembly instruction)
cat_title : VGETMANTPD
ref_title : VGETMANTPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VGETMANTPD

**Extract Float64 Vector of Normalized Mantissas from Float64 Vector**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F3A.W1 26 /r ib\newline{}VGETMANTPD xmm1 {k1}{z}, xmm2/m128/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Get Normalized Mantissa from float64 vector xmm2/m128/m64bcst and store the result in xmm1, using imm8 for sign control and mantissa interval normalization, under writemask.|
|EVEX.256.66.0F3A.W1 26 /r ib\newline{}VGETMANTPD ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Get Normalized Mantissa from float64 vector ymm2/m256/m64bcst and store the result in ymm1, using imm8 for sign control and mantissa interval normalization, under writemask.|
|EVEX.512.66.0F3A.W1 26 /r ib\newline{}VGETMANTPD zmm1 {k1}{z}, zmm2/m512/m64bcst{sae}, imm8|FV|V/V|AVX512F|Get Normalized Mantissa from float64 vector zmm2/m512/m64bcst and store the result in zmm1, using imm8 for sign control and mantissa interval normalization, under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FVI|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description


Convert double-precision floating values in the source operand (the second operand) to DP FP values with the mantissa normalization and sign control specified by the imm8 byte, see Figure 5-15. The converted results are written to the destination operand (the first operand) using writemask k1. The normalized mantissa is specified by interv (imm8[1:0]) and the sign control (sc) is specified by bits 3:2 of the immediate byte. 

The destination operand is a ZMM/YMM/XMM register updated under the writemask. The source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 64-bit memory location.

For each input DP FP value x, The conversion operation is:

            GetMant(x) = $$\pm$$2k|x.significand|

where:

            1 <= |x.significand| < 2

Unbiased exponent k depends on the interval range defined by interv and whether the exponent of the source is even or odd. The sign of the final result is determined by sc and the source sign.

```embed
<figure>
<svg viewBox="0 0 499.200012 140.279999">
<rect x="0.000000" y="10.000000" width="0.480000" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="498.719971" y="10.000000" width="0.479980" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="499.200012" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="117.099991" width="499.200012" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="60.600002" y="37.239990" width="185.399994" height="12.780000" fill-rule="nonzero"  fill=" rgb(230,230,230) " stroke="black" />
<path d="M60.600002,37.239990 L246.000000,37.239990 L246.000000,50.019989 L60.600002,50.019989 L60.600002,37.239990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="60.060001" y="36.820007" width="373.260010" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="432.839996" y="37.059998" width="0.480010" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.819996" y="50.080017" width="373.260010" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.819996" y="36.820007" width="0.480000" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.600006" y="37.059998" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.600006" y="37.299988" width="0.479980" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.359985" y="37.059998" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.359985" y="37.299988" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.139984,72.339996 L203.159988,73.720001" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M208.859985,75.220001 L203.159988,73.720001 L207.299988,69.519989" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M286.619995,50.739990 L208.139984,72.339996" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M390.600006,57.039978 L390.600006,62.199982" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M393.600006,57.039978 L390.600006,62.199982 L387.660004,57.039978" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M390.600006,49.719971 L390.600006,57.039978" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="40.201191" y="44.199951" textLength="3.510000" font-size="8px">8</text>
<text x="35.581188" y="44.199951" textLength="4.632000" font-size="8px">m</text>
<text x="434.154510" y="101.379944" textLength="2.088000" font-size="8px">/</text>
<text x="430.674500" y="101.379944" textLength="3.510000" font-size="8px">3</text>
<text x="429.175110" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="427.975708" y="101.379944" textLength="1.218000" font-size="8px">,</text>
<text x="424.447113" y="101.379944" textLength="3.510000" font-size="8px">4</text>
<text x="416.999908" y="101.379944" textLength="1.842000" font-size="8px">[</text>
<text x="411.545319" y="101.379944" textLength="1.302000" font-size="8px">i</text>
<text x="410.105927" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="408.785339" y="101.379944" textLength="1.284000" font-size="8px">l</text>
<text x="405.845947" y="101.379944" textLength="2.982000" font-size="8px">a</text>
<text x="402.846558" y="101.379944" textLength="3.096000" font-size="8px">v</text>
<text x="390.807556" y="101.379944" textLength="1.398000" font-size="8px">I</text>
<text x="386.667572" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="380.060974" y="101.379944" textLength="3.510000" font-size="8px">1</text>
<text x="376.532379" y="101.379944" textLength="3.510000" font-size="8px">1</text>
<text x="375.092987" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="370.161011" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="368.300415" y="101.379944" textLength="1.842000" font-size="8px">]</text>
<text x="364.820404" y="101.379944" textLength="3.510000" font-size="8px">0</text>
<text x="363.631805" y="101.379944" textLength="1.170000" font-size="8px">:</text>
<text x="360.151794" y="101.379944" textLength="3.510000" font-size="8px">1</text>
<text x="358.291199" y="101.379944" textLength="1.842000" font-size="8px">[</text>
<text x="354.811188" y="101.379944" textLength="3.510000" font-size="8px">8</text>
<text x="350.160583" y="101.379944" textLength="4.632000" font-size="8px">m</text>
<text x="345.480591" y="101.379944" textLength="4.632000" font-size="8px">m</text>
<text x="344.099976" y="101.379944" textLength="1.398000" font-size="8px">I</text>
<text x="435.661072" y="91.539948" textLength="1.728000" font-size="8px">)</text>
<text x="432.131287" y="91.539948" textLength="3.510000" font-size="8px">1</text>
<text x="425.952484" y="91.539948" textLength="3.510000" font-size="8px">2</text>
<text x="423.853088" y="91.539948" textLength="2.088000" font-size="8px">/</text>
<text x="420.373077" y="91.539948" textLength="3.510000" font-size="8px">1</text>
<text x="417.011902" y="91.539948" textLength="1.842000" font-size="8px">[</text>
<text x="415.572510" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="412.876709" y="91.539948" textLength="2.676000" font-size="8px">s</text>
<text x="405.855530" y="91.539948" textLength="2.982000" font-size="8px">a</text>
<text x="400.658325" y="91.539948" textLength="2.178000" font-size="8px">r</text>
<text x="395.317719" y="91.539948" textLength="2.250000" font-size="8px">t</text>
<text x="390.815948" y="91.539948" textLength="1.398000" font-size="8px">I</text>
<text x="388.175354" y="91.539948" textLength="1.170000" font-size="8px">:</text>
<text x="386.675964" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="383.548157" y="91.539948" textLength="3.108000" font-size="8px">b</text>
<text x="380.068146" y="91.539948" textLength="3.510000" font-size="8px">0</text>
<text x="376.538361" y="91.539948" textLength="3.510000" font-size="8px">1</text>
<text x="370.165771" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="364.823975" y="91.539948" textLength="3.510000" font-size="8px">0</text>
<text x="363.634186" y="91.539948" textLength="1.170000" font-size="8px">:</text>
<text x="360.154175" y="91.539948" textLength="3.510000" font-size="8px">1</text>
<text x="350.160583" y="91.539948" textLength="4.632000" font-size="8px">m</text>
<text x="430.696167" y="81.699951" textLength="3.510000" font-size="8px">2</text>
<text x="429.196167" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="427.996155" y="81.699951" textLength="1.218000" font-size="8px">,</text>
<text x="422.359741" y="81.699951" textLength="2.088000" font-size="8px">/</text>
<text x="418.879150" y="81.699951" textLength="3.510000" font-size="8px">1</text>
<text x="417.017944" y="81.699951" textLength="1.842000" font-size="8px">[</text>
<text x="415.577942" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="412.882751" y="81.699951" textLength="2.676000" font-size="8px">s</text>
<text x="410.121552" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="408.800354" y="81.699951" textLength="1.284000" font-size="8px">l</text>
<text x="397.541962" y="81.699951" textLength="3.144000" font-size="8px">e</text>
<text x="390.818359" y="81.699951" textLength="1.398000" font-size="8px">I</text>
<text x="388.176575" y="81.699951" textLength="1.170000" font-size="8px">:</text>
<text x="383.549377" y="81.699951" textLength="3.108000" font-size="8px">b</text>
<text x="376.539581" y="81.699951" textLength="3.510000" font-size="8px">0</text>
<text x="371.666382" y="81.699951" textLength="3.414000" font-size="8px">=</text>
<text x="370.166382" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="368.305176" y="81.699951" textLength="1.842000" font-size="8px">]</text>
<text x="408.794922" y="91.539948" textLength="1.284000" font-size="8px">l</text>
<text x="364.824585" y="81.699951" textLength="3.510000" font-size="8px">0</text>
<text x="360.154785" y="81.699951" textLength="3.510000" font-size="8px">1</text>
<text x="358.293579" y="81.699951" textLength="1.842000" font-size="8px">[</text>
<text x="354.812988" y="81.699951" textLength="3.510000" font-size="8px">8</text>
<text x="350.161774" y="81.699951" textLength="4.632000" font-size="8px">m</text>
<text x="417.005981" y="71.859955" textLength="1.842000" font-size="8px">[</text>
<text x="411.550201" y="71.859955" textLength="1.302000" font-size="8px">i</text>
<text x="402.851440" y="71.859955" textLength="3.096000" font-size="8px">v</text>
<text x="400.654236" y="71.859955" textLength="2.178000" font-size="8px">r</text>
<text x="389.312439" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="388.171234" y="71.859955" textLength="1.170000" font-size="8px">:</text>
<text x="386.671844" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="383.544647" y="71.859955" textLength="3.108000" font-size="8px">b</text>
<text x="380.064636" y="71.859955" textLength="3.510000" font-size="8px">0</text>
<text x="376.535431" y="71.859955" textLength="3.510000" font-size="8px">0</text>
<text x="375.096039" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="370.163452" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="368.302246" y="71.859955" textLength="1.842000" font-size="8px">]</text>
<text x="363.633026" y="71.859955" textLength="1.170000" font-size="8px">:</text>
<text x="360.153015" y="71.859955" textLength="3.510000" font-size="8px">1</text>
<text x="358.291809" y="71.859955" textLength="1.842000" font-size="8px">[</text>
<text x="354.811798" y="71.859955" textLength="3.510000" font-size="8px">8</text>
<text x="350.160583" y="71.859955" textLength="4.632000" font-size="8px">m</text>
<text x="345.480591" y="71.859955" textLength="4.632000" font-size="8px">m</text>
<text x="310.985382" y="99.879959" textLength="1.140000" font-size="8px">.</text>
<text x="309.128967" y="99.879959" textLength="1.842000" font-size="8px">]</text>
<text x="303.792542" y="99.879959" textLength="1.842000" font-size="8px">[</text>
<text x="300.312531" y="99.879959" textLength="3.510000" font-size="8px">8</text>
<text x="281.446167" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="278.804962" y="99.879959" textLength="2.676000" font-size="8px">s</text>
<text x="276.103760" y="99.879959" textLength="2.676000" font-size="8px">s</text>
<text x="272.983154" y="99.879959" textLength="3.144000" font-size="8px">e</text>
<text x="271.722565" y="99.879959" textLength="1.284000" font-size="8px">l</text>
<text x="268.603180" y="99.879959" textLength="3.108000" font-size="8px">d</text>
<text x="266.561981" y="99.879959" textLength="2.178000" font-size="8px">r</text>
<text x="260.443176" y="99.879959" textLength="3.108000" font-size="8px">g</text>
<text x="253.781982" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="252.582581" y="99.879959" textLength="1.218000" font-size="8px">,</text>
<text x="244.190369" y="99.879959" textLength="3.414000" font-size="8px">=</text>
<text x="405.860352" y="81.699951" textLength="2.982000" font-size="8px">a</text>
<text x="243.011963" y="99.879959" textLength="1.164000" font-size="8px">!</text>
<text x="241.572571" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="358.292389" y="91.539948" textLength="1.842000" font-size="8px">[</text>
<text x="172.010376" y="90.399963" textLength="3.108000" font-size="8px">b</text>
<text x="411.561554" y="81.699951" textLength="1.302000" font-size="8px">i</text>
<text x="397.537720" y="91.539948" textLength="3.144000" font-size="8px">e</text>
<text x="198.014954" y="99.879959" textLength="2.226000" font-size="8px">f</text>
<text x="408.239990" y="32.019989" textLength="3.510000" font-size="8px">0</text>
<text x="290.986145" y="99.879959" textLength="4.632000" font-size="8px">m</text>
<text x="194.954361" y="99.879959" textLength="3.144000" font-size="8px">e</text>
<text x="187.253967" y="99.879959" textLength="1.398000" font-size="8px">I</text>
<text x="273.599976" y="45.879974" textLength="3.186000" font-size="8px">S</text>
<text x="289.724945" y="99.879959" textLength="1.302000" font-size="8px">i</text>
<text x="415.560516" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="363.635376" y="81.699951" textLength="1.170000" font-size="8px">:</text>
<text x="166.896561" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="411.554901" y="91.539948" textLength="1.302000" font-size="8px">i</text>
<text x="30.961185" y="44.199951" textLength="4.632000" font-size="8px">m</text>
<text x="236.649567" y="99.879959" textLength="3.150000" font-size="8px">C</text>
<text x="386.676575" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="132.599976" y="99.879959" textLength="1.398000" font-size="8px">I</text>
<text x="177.790146" y="80.859985" textLength="1.482000" font-size="8px"> </text>
<text x="157.054184" y="45.879974" textLength="3.144000" font-size="8px">e</text>
<text x="365.187561" y="45.879974" textLength="2.178000" font-size="8px">r</text>
<text x="371.662842" y="71.859955" textLength="3.414000" font-size="8px">=</text>
<text x="375.099579" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="358.139954" y="45.879974" textLength="3.900000" font-size="8px">N</text>
<text x="247.618774" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="177.780579" y="90.399963" textLength="1.482000" font-size="8px"> </text>
<text x="299.569794" y="45.879974" textLength="3.150000" font-size="8px">o</text>
<text x="389.316559" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="160.138779" y="90.399963" textLength="3.414000" font-size="8px">=</text>
<text x="418.867188" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="397.533630" y="71.859955" textLength="3.144000" font-size="8px">e</text>
<text x="371.660400" y="101.379944" textLength="3.414000" font-size="8px">=</text>
<text x="400.649963" y="101.379944" textLength="2.178000" font-size="8px">r</text>
<text x="239.830170" y="99.879959" textLength="1.728000" font-size="8px">)</text>
<text x="392.192444" y="71.859955" textLength="3.186000" font-size="8px">n</text>
<text x="344.099976" y="91.539948" textLength="1.398000" font-size="8px">I</text>
<text x="367.364349" y="45.879974" textLength="4.632000" font-size="8px">m</text>
<text x="163.526932" y="80.859985" textLength="1.482000" font-size="8px"> </text>
<text x="229.969147" y="99.879959" textLength="3.186000" font-size="8px">S</text>
<text x="392.199554" y="81.699951" textLength="3.186000" font-size="8px">n</text>
<text x="362.038757" y="45.879974" textLength="3.150000" font-size="8px">o</text>
<text x="153.755386" y="45.879974" textLength="3.456000" font-size="8px">Z</text>
<text x="153.332336" y="80.859985" textLength="3.510000" font-size="8px">2</text>
<text x="412.871399" y="71.859955" textLength="2.676000" font-size="8px">s</text>
<text x="257.322571" y="99.879959" textLength="3.144000" font-size="8px">e</text>
<text x="132.599976" y="90.399963" textLength="1.398000" font-size="8px">I</text>
<text x="386.758759" y="45.879974" textLength="3.150000" font-size="8px">o</text>
<text x="164.998779" y="90.399963" textLength="3.510000" font-size="8px">0</text>
<text x="408.790222" y="71.859955" textLength="1.284000" font-size="8px">l</text>
<text x="188.694565" y="99.879959" textLength="3.186000" font-size="8px">n</text>
<text x="394.591766" y="45.879974" textLength="1.398000" font-size="8px">I</text>
<text x="410.115509" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="389.318359" y="81.699951" textLength="1.482000" font-size="8px"> </text>
<text x="171.019775" y="99.879959" textLength="3.108000" font-size="8px">q</text>
<text x="423.846588" y="71.859955" textLength="1.218000" font-size="8px">,</text>
<text x="138.655151" y="80.859985" textLength="4.632000" font-size="8px">m</text>
<text x="392.196533" y="91.539948" textLength="3.186000" font-size="8px">n</text>
<text x="204.751160" y="99.879959" textLength="1.302000" font-size="8px">i</text>
<text x="163.499374" y="90.399963" textLength="1.482000" font-size="8px"> </text>
<text x="418.860504" y="101.379944" textLength="3.510000" font-size="8px">3</text>
<text x="160.312759" y="99.879959" textLength="3.510000" font-size="8px">1</text>
<text x="289.006805" y="45.879974" textLength="3.150000" font-size="8px">o</text>
<text x="429.432495" y="91.539948" textLength="1.218000" font-size="8px">,</text>
<text x="361.859985" y="32.019989" textLength="3.510000" font-size="8px">1</text>
<text x="405.850830" y="71.859955" textLength="2.982000" font-size="8px">a</text>
<text x="153.295776" y="90.399963" textLength="3.510000" font-size="8px">2</text>
<text x="282.945557" y="99.879959" textLength="3.150000" font-size="8px">o</text>
<text x="436.253906" y="101.379944" textLength="3.510000" font-size="8px">2</text>
<text x="212.885345" y="99.879959" textLength="1.302000" font-size="8px">i</text>
<text x="383.177948" y="45.879974" textLength="2.250000" font-size="8px">t</text>
<text x="375.098969" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="145.598969" y="45.879974" textLength="3.546000" font-size="8px">B</text>
<text x="377.537964" y="45.879974" textLength="2.778000" font-size="8px">z</text>
<text x="434.176758" y="81.699951" textLength="1.728000" font-size="8px">)</text>
<text x="395.321350" y="81.699951" textLength="2.250000" font-size="8px">t</text>
<text x="374.975952" y="45.879974" textLength="1.302000" font-size="8px">i</text>
<text x="222.779968" y="32.019989" textLength="3.510000" font-size="8px">4</text>
<text x="389.907562" y="45.879974" textLength="3.186000" font-size="8px">n</text>
<text x="189.571152" y="80.859985" textLength="1.728000" font-size="8px">(</text>
<text x="130.019958" y="32.019989" textLength="3.510000" font-size="8px">6</text>
<text x="418.873688" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="402.856140" y="91.539948" textLength="3.096000" font-size="8px">v</text>
<text x="211.445953" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="255.281372" y="99.879959" textLength="2.178000" font-size="8px">r</text>
<text x="422.340515" y="101.379944" textLength="2.088000" font-size="8px">/</text>
<text x="395.988556" y="45.879974" textLength="3.186000" font-size="8px">n</text>
<text x="420.366577" y="71.859955" textLength="3.510000" font-size="8px">1</text>
<text x="404.450348" y="45.879974" textLength="2.178000" font-size="8px">r</text>
<text x="390.811829" y="71.859955" textLength="1.398000" font-size="8px">I</text>
<text x="409.670929" y="45.879974" textLength="2.982000" font-size="8px">a</text>
<text x="263.565582" y="99.879959" textLength="2.982000" font-size="8px">a</text>
<text x="133.980576" y="99.879959" textLength="4.632000" font-size="8px">m</text>
<text x="400.663147" y="81.699951" textLength="2.178000" font-size="8px">r</text>
<text x="288.225555" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="380.358551" y="45.879974" textLength="2.982000" font-size="8px">a</text>
<text x="425.045990" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="201.550766" y="99.879959" textLength="3.186000" font-size="8px">n</text>
<text x="305.648956" y="99.879959" textLength="3.510000" font-size="8px">2</text>
<text x="144.099564" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="383.540985" y="101.379944" textLength="3.108000" font-size="8px">b</text>
<text x="415.566589" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="176.639374" y="90.399963" textLength="1.170000" font-size="8px">:</text>
<text x="380.068787" y="81.699951" textLength="3.510000" font-size="8px">1</text>
<text x="134.010559" y="80.859985" textLength="4.632000" font-size="8px">m</text>
<text x="371.995148" y="45.879974" textLength="2.982000" font-size="8px">a</text>
<text x="368.303986" y="91.539948" textLength="1.842000" font-size="8px">]</text>
<text x="354.812378" y="91.539948" textLength="3.510000" font-size="8px">8</text>
<text x="181.930756" y="80.859985" textLength="1.302000" font-size="8px">i</text>
<text x="138.600571" y="90.399963" textLength="4.632000" font-size="8px">m</text>
<text x="310.376404" y="45.879974" textLength="3.150000" font-size="8px">C</text>
<text x="131.639954" y="45.879974" textLength="4.386000" font-size="8px">M</text>
<text x="160.166336" y="80.859985" textLength="3.414000" font-size="8px">=</text>
<text x="139.192764" y="45.879974" textLength="2.676000" font-size="8px">s</text>
<text x="364.822235" y="71.859955" textLength="3.510000" font-size="8px">0</text>
<text x="225.026337" y="99.879959" textLength="3.186000" font-size="8px">n</text>
<text x="424.466949" y="81.699951" textLength="3.510000" font-size="8px">2</text>
<text x="138.600571" y="99.879959" textLength="4.632000" font-size="8px">m</text>
<text x="133.980576" y="90.399963" textLength="4.632000" font-size="8px">m</text>
<text x="430.691895" y="91.539948" textLength="1.482000" font-size="8px"> </text>
<text x="426.545380" y="71.859955" textLength="3.510000" font-size="8px">2</text>
<text x="412.865906" y="101.379944" textLength="2.676000" font-size="8px">s</text>
<text x="233.169556" y="99.879959" textLength="3.618000" font-size="8px">R</text>
<text x="152.315979" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="178.056580" y="99.879959" textLength="2.982000" font-size="8px">a</text>
<text x="136.016357" y="45.879974" textLength="3.186000" font-size="8px">u</text>
<text x="201.170944" y="80.859985" textLength="1.728000" font-size="8px">)</text>
<text x="412.610321" y="45.879974" textLength="1.284000" font-size="8px">l</text>
<text x="392.188171" y="101.379944" textLength="3.186000" font-size="8px">n</text>
<text x="402.860352" y="81.699951" textLength="3.096000" font-size="8px">v</text>
<text x="345.480591" y="91.539948" textLength="4.632000" font-size="8px">m</text>
<text x="148.616959" y="99.879959" textLength="3.510000" font-size="8px">3</text>
<text x="176.399963" y="32.019989" textLength="3.510000" font-size="8px">5</text>
<text x="295.666138" y="99.879959" textLength="4.632000" font-size="8px">m</text>
<text x="401.329742" y="45.879974" textLength="3.144000" font-size="8px">e</text>
<text x="162.275986" y="45.879974" textLength="3.150000" font-size="8px">o</text>
<text x="388.166962" y="101.379944" textLength="1.170000" font-size="8px">:</text>
<text x="168.548935" y="80.859985" textLength="3.510000" font-size="8px">0</text>
<text x="302.690399" y="45.879974" textLength="1.284000" font-size="8px">l</text>
<text x="315.479980" y="32.019989" textLength="3.510000" font-size="8px">2</text>
<text x="286.006165" y="99.879959" textLength="2.226000" font-size="8px">f</text>
<text x="344.099976" y="71.859955" textLength="1.398000" font-size="8px">I</text>
<text x="217.941528" y="99.879959" textLength="2.676000" font-size="8px">s</text>
<text x="183.251953" y="80.859985" textLength="3.108000" font-size="8px">g</text>
<text x="149.135376" y="45.879974" textLength="3.144000" font-size="8px">e</text>
<text x="395.313629" y="71.859955" textLength="2.250000" font-size="8px">t</text>
<text x="249.058167" y="99.879959" textLength="3.510000" font-size="8px">0</text>
<text x="181.052979" y="99.879959" textLength="3.186000" font-size="8px">n</text>
<text x="439.733917" y="101.379944" textLength="1.728000" font-size="8px">)</text>
<text x="397.529358" y="101.379944" textLength="3.144000" font-size="8px">e</text>
<text x="430.074585" y="71.859955" textLength="1.728000" font-size="8px">)</text>
<text x="292.187408" y="45.879974" textLength="3.186000" font-size="8px">n</text>
<text x="221.903931" y="99.879959" textLength="3.108000" font-size="8px">g</text>
<text x="395.309357" y="101.379944" textLength="2.250000" font-size="8px">t</text>
<text x="385.457947" y="45.879974" textLength="1.302000" font-size="8px">i</text>
<text x="160.234787" y="45.879974" textLength="2.178000" font-size="8px">r</text>
<text x="169.580368" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="179.289551" y="80.859985" textLength="2.676000" font-size="8px">s</text>
<text x="344.099976" y="81.699951" textLength="1.398000" font-size="8px">I</text>
<text x="132.599960" y="80.859985" textLength="1.398000" font-size="8px">I</text>
<text x="158.639374" y="90.399963" textLength="1.482000" font-size="8px"> </text>
<text x="175.149536" y="80.859985" textLength="1.482000" font-size="8px"> </text>
<text x="158.813354" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="29.639988" y="44.199951" textLength="1.302000" font-size="8px">i</text>
<text x="146.815140" y="80.859985" textLength="1.842000" font-size="8px">[</text>
<text x="389.308167" y="101.379944" textLength="1.482000" font-size="8px"> </text>
<text x="307.174194" y="45.879974" textLength="3.186000" font-size="8px">S</text>
<text x="83.639999" y="32.019989" textLength="3.510000" font-size="8px">7</text>
<text x="269.099976" y="32.019989" textLength="3.510000" font-size="8px">3</text>
<text x="376.276764" y="45.879974" textLength="1.302000" font-size="8px">i</text>
<text x="371.665161" y="91.539948" textLength="3.414000" font-size="8px">=</text>
<text x="393.092377" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="399.109741" y="45.879974" textLength="2.250000" font-size="8px">t</text>
<text x="406.671539" y="45.879974" textLength="3.096000" font-size="8px">v</text>
<text x="141.859161" y="45.879974" textLength="2.250000" font-size="8px">t</text>
<text x="143.335144" y="80.859985" textLength="3.510000" font-size="8px">8</text>
<text x="148.669739" y="80.859985" textLength="3.510000" font-size="8px">3</text>
<text x="152.149734" y="80.859985" textLength="1.170000" font-size="8px">:</text>
<text x="156.812332" y="80.859985" textLength="1.842000" font-size="8px">]</text>
<text x="158.666931" y="80.859985" textLength="1.482000" font-size="8px"> </text>
<text x="165.026337" y="80.859985" textLength="3.510000" font-size="8px">0</text>
<text x="172.028931" y="80.859985" textLength="3.108000" font-size="8px">b</text>
<text x="176.648941" y="80.859985" textLength="1.170000" font-size="8px">:</text>
<text x="186.372559" y="80.859985" textLength="3.186000" font-size="8px">n</text>
<text x="191.311752" y="80.859985" textLength="3.186000" font-size="8px">S</text>
<text x="194.510345" y="80.859985" textLength="3.618000" font-size="8px">R</text>
<text x="197.990341" y="80.859985" textLength="3.150000" font-size="8px">C</text>
<text x="276.802185" y="45.879974" textLength="1.302000" font-size="8px">i</text>
<text x="278.120392" y="45.879974" textLength="3.108000" font-size="8px">g</text>
<text x="281.244598" y="45.879974" textLength="3.186000" font-size="8px">n</text>
<text x="284.446808" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="285.886200" y="45.879974" textLength="3.150000" font-size="8px">C</text>
<text x="295.248596" y="45.879974" textLength="2.250000" font-size="8px">t</text>
<text x="297.468597" y="45.879974" textLength="2.178000" font-size="8px">r</text>
<text x="303.990601" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="305.429993" y="45.879974" textLength="1.728000" font-size="8px">(</text>
<text x="313.542603" y="45.879974" textLength="1.728000" font-size="8px">)</text>
<text x="143.280579" y="90.399963" textLength="3.510000" font-size="8px">8</text>
<text x="146.760574" y="90.399963" textLength="1.842000" font-size="8px">[</text>
<text x="148.624176" y="90.399963" textLength="3.510000" font-size="8px">3</text>
<text x="152.104172" y="90.399963" textLength="1.170000" font-size="8px">:</text>
<text x="345.481171" y="81.699951" textLength="4.632000" font-size="8px">m</text>
<text x="156.775772" y="90.399963" textLength="1.842000" font-size="8px">]</text>
<text x="168.530380" y="90.399963" textLength="3.510000" font-size="8px">1</text>
<text x="175.139969" y="90.399963" textLength="1.482000" font-size="8px"> </text>
<text x="179.279984" y="90.399963" textLength="3.510000" font-size="8px">0</text>
<text x="143.280563" y="99.879959" textLength="3.510000" font-size="8px">8</text>
<text x="146.760559" y="99.879959" textLength="1.842000" font-size="8px">[</text>
<text x="152.096954" y="99.879959" textLength="1.842000" font-size="8px">]</text>
<text x="153.953354" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="174.142181" y="99.879959" textLength="3.900000" font-size="8px">N</text>
<text x="410.110809" y="71.859955" textLength="1.482000" font-size="8px"> </text>
<text x="155.452759" y="99.879959" textLength="3.414000" font-size="8px">=</text>
<text x="168.395966" y="99.879959" textLength="1.170000" font-size="8px">:</text>
<text x="184.253372" y="99.879959" textLength="3.036000" font-size="8px">_</text>
<text x="163.837158" y="99.879959" textLength="3.108000" font-size="8px">b</text>
<text x="191.894958" y="99.879959" textLength="3.108000" font-size="8px">d</text>
<text x="200.234360" y="99.879959" textLength="1.302000" font-size="8px">i</text>
<text x="206.067566" y="99.879959" textLength="2.250000" font-size="8px">t</text>
<text x="208.287567" y="99.879959" textLength="3.144000" font-size="8px">e</text>
<text x="214.201752" y="99.879959" textLength="2.226000" font-size="8px">f</text>
<text x="216.442139" y="99.879959" textLength="1.482000" font-size="8px"> </text>
<text x="220.582733" y="99.879959" textLength="1.302000" font-size="8px">i</text>
<text x="228.226746" y="99.879959" textLength="1.728000" font-size="8px">(</text>
</svg>
<figcaption>Figure 5-15.  Imm8 Controls for VGETMANTPD/SD/PS/SS
</figcaption></figure>
```


If interv != 0 then k = -1, otherwise K = 0. The encoded value of imm8[1:0] and sign control are shown in 

Figure 5-15.

Each converted DP FP result is encoded according to the sign control, the unbiased exponent k (adding bias) and a mantissa normalized to the range specified by interv.

The GetMant() function follows Table 5-9 when dealing with floating-point special numbers.

This instruction is writemasked, so only those elements with the corresponding bit set in vector mask register k1 are computed and stored into the destination. Elements in zmm1 with the corresponding bit clear in k1 retain their previous values.

 Note: EVEX.vvvv is reserved and must be 1111b; otherwise instructions will #UD.

### Table 5-9. GetMant() Special Float Values Behavior


|**Input**|**Result**|**Exceptions / Comments**|
|---------|----------|-------------------------|
|NaN|QNaN(SRC)|Ignore intervIf (SRC = SNaN) then #IE|
|+'|1.0|Ignore interv|
|+0|1.0 |Ignore interv|
|-0|IF (SC[0]) THEN +1.0                  ELSE -1.0|Ignore interv|
|-'|IF (SC[1]) THEN {QNaN_Indefinite} ELSE {   IF (SC[0]) THEN +1.0                     ELSE -1.0|Ignore intervIf (SC[1]) then #IE|
|negative|SC[1] ? QNaN_Indefinite : Getmant(SRC)|If (SC[1]) then #IE|

### Operation
#### VGETMANTPD (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC *is memory*)
                      THEN
                            DEST[i+63:i] !=<- GetNormalizedMantissaDP(SRC[63:0], sc, interv)
                      ELSE 
                            DEST[i+63:i] !=<- GetNormalizedMantissaDP(SRC[i+63:i], sc, interv)
                FI;
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
VGETMANTPD __m512d _mm512_getmant_pd( __m512d a, enum intv, enum sgn);
VGETMANTPD __m512d _mm512_mask_getmant_pd(__m512d s, __mmask8 k, __m512d a, enum intv, enum sgn);
VGETMANTPD __m512d _mm512_maskz_getmant_pd( __mmask8 k, __m512d a, enum intv, enum sgn);
VGETMANTPD __m512d _mm512_getmant_round_pd( __m512d a, enum intv, enum sgn, int r);
VGETMANTPD __m512d _mm512_mask_getmant_round_pd(__m512d s, __mmask8 k, __m512d a, enum intv, enum sgn, int r);
VGETMANTPD __m512d _mm512_maskz_getmant_round_pd( __mmask8 k, __m512d a, enum intv, enum sgn, int r);
VGETMANTPD __m256d _mm256_getmant_pd( __m256d a, enum intv, enum sgn);
VGETMANTPD __m256d _mm256_mask_getmant_pd(__m256d s, __mmask8 k, __m256d a, enum intv, enum sgn);
VGETMANTPD __m256d _mm256_maskz_getmant_pd( __mmask8 k, __m256d a, enum intv, enum sgn);
VGETMANTPD __m128d _mm_getmant_pd( __m128d a, enum intv, enum sgn);
VGETMANTPD __m128d _mm_mask_getmant_pd(__m128d s, __mmask8 k, __m128d a, enum intv, enum sgn);
VGETMANTPD __m128d _mm_maskz_getmant_pd( __mmask8 k, __m128d a, enum intv, enum sgn);
```
### SIMD Floating-Point Exceptions


Denormal, Invalid

### Other Exceptions


See Exceptions Type E2.

#UD  If EVEX.vvvv != 1111B.

