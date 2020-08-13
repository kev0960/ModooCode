----------------------------
title : VRANGEPD (Intel x86/64 assembly instruction)
cat_title : VRANGEPD
ref_title : VRANGEPD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VRANGEPD

**Range Restriction Calculation For Packed Pairs of Float64 Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.128.66.0F3A.W1 50 /r ib\newline{}VRANGEPD xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Calculate two RANGE operation output value from 2 pairs of double-precision floating-point values in xmm2 and xmm3/m128/m32bcst, store the results to xmm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.|
|EVEX.NDS.256.66.0F3A.W1 50 /r ib\newline{}VRANGEPD ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Calculate four RANGE operation output value from 4pairs of double-precision floating-point values in ymm2 and ymm3/m256/m32bcst, store the results to ymm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.|
|EVEX.NDS.512.66.0F3A.W1 50 /r ib\newline{}VRANGEPD zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst{sae}, imm8|FV|V/V|AVX512DQ|Calculate eight RANGE operation output value from 8 pairs of double-precision floating-point values in zmm2 and zmm3/m512/m32bcst, store the results to zmm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description


This instruction calculates 2/4/8 range operation outputs from two sets of packed input double-precision FP values in the first source operand (the second operand) and the second source operand (the third operand). The range outputs are written to the destination operand (the first operand) under the writemask k1. 

Bits7:4 of imm8 byte must be zero. The range operation output is performed in two parts, each configured by a two-bit control field within imm8[3:0]:

*  Imm8[1:0] specifies the initial comparison operation to be one of max, min, max absolute value or min absolute value of the input value pair. Each comparison of two input values produces an intermediate result that combines with the sign selection control (Imm8[3:2]) to determine the final range operation output.

*  Imm8[3:2] specifies the sign of the range operation output to be one of the following: from the first input value, from the comparison result, set or clear.

The encodings of Imm8[1:0] and Imm8[3:2] are shown in Figure 5-27.

```embed
<figure>
<svg viewBox="0 0 499.200043 134.320007">
<rect x="0.060001" y="10.000000" width="0.480000" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="498.720001" y="10.000000" width="0.479980" height="107.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="499.200012" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="117.159988" width="499.200012" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="60.600002" y="37.239990" width="185.460007" height="12.840000" fill-rule="nonzero"  fill=" rgb(230,230,230) " stroke="black" />
<path d="M60.600002,37.239990 L246.060028,37.239990 L246.060028,50.079987 L60.600002,50.079987 L60.600002,37.239990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="60.119999" y="36.819977" width="373.260010" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="432.899994" y="37.059998" width="0.479980" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.880001" y="50.080002" width="373.260010" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.880001" y="36.819992" width="0.480010" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.600006" y="37.059982" width="0.480010" height="0.240010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="339.600006" y="37.300003" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.360016" y="37.059982" width="0.479980" height="0.240010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.360016" y="37.300003" width="0.479980" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M158.040009,73.539993 L152.940002,74.439987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M158.520004,76.479996 L152.940002,74.440002 L157.500000,70.659988" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M286.620026,50.739990 L158.040024,73.539993" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M390.660034,57.039993 L390.660034,62.199997" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M393.600037,57.099991 L390.660034,62.199997 L387.660034,57.099991" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M390.660034,49.719986 L390.660034,57.039993" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="203.119843" y="107.919983" textLength="3.150000" font-size="8px">o</text>
<text x="199.460434" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="193.131638" y="107.919983" textLength="3.108000" font-size="8px">g</text>
<text x="191.870438" y="107.919983" textLength="1.302000" font-size="8px">i</text>
<text x="189.177032" y="107.919983" textLength="2.676000" font-size="8px">s</text>
<text x="187.677628" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="179.253632" y="107.919983" textLength="3.186000" font-size="8px">S</text>
<text x="177.754227" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="176.613022" y="107.919983" textLength="1.170000" font-size="8px">:</text>
<text x="172.054214" y="107.919983" textLength="3.108000" font-size="8px">b</text>
<text x="168.574219" y="107.919983" textLength="3.510000" font-size="8px">1</text>
<text x="160.186203" y="107.919983" textLength="3.414000" font-size="8px">=</text>
<text x="158.686798" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="153.347397" y="107.919983" textLength="3.510000" font-size="8px">2</text>
<text x="148.680008" y="107.919983" textLength="3.510000" font-size="8px">3</text>
<text x="146.820602" y="107.919983" textLength="1.842000" font-size="8px">[</text>
<text x="132.660004" y="107.919983" textLength="1.398000" font-size="8px">I</text>
<text x="40.201153" y="44.259979" textLength="3.510000" font-size="8px">8</text>
<text x="35.581150" y="44.259979" textLength="4.632000" font-size="8px">m</text>
<text x="29.639950" y="44.259979" textLength="1.302000" font-size="8px">i</text>
<text x="438.601074" y="101.439972" textLength="3.186000" font-size="8px">u</text>
<text x="437.340485" y="101.439972" textLength="1.284000" font-size="8px">l</text>
<text x="431.341705" y="101.439972" textLength="3.096000" font-size="8px">v</text>
<text x="427.209503" y="101.439972" textLength="2.676000" font-size="8px">s</text>
<text x="424.090118" y="101.439972" textLength="3.108000" font-size="8px">b</text>
<text x="412.361328" y="101.439972" textLength="2.982000" font-size="8px">a</text>
<text x="407.958527" y="101.439972" textLength="4.386000" font-size="8px">M</text>
<text x="404.179138" y="101.439972" textLength="2.250000" font-size="8px">t</text>
<text x="401.599731" y="101.439972" textLength="2.604000" font-size="8px">c</text>
<text x="390.854919" y="101.439972" textLength="3.186000" font-size="8px">S</text>
<text x="389.355530" y="101.439972" textLength="1.482000" font-size="8px"> </text>
<text x="388.214325" y="101.439972" textLength="1.170000" font-size="8px">:</text>
<text x="386.714935" y="101.439972" textLength="1.482000" font-size="8px"> </text>
<text x="380.110138" y="101.439972" textLength="3.510000" font-size="8px">1</text>
<text x="376.583344" y="101.439972" textLength="3.510000" font-size="8px">1</text>
<text x="375.143951" y="101.439972" textLength="1.482000" font-size="8px"> </text>
<text x="371.713165" y="101.439972" textLength="3.414000" font-size="8px">=</text>
<text x="370.213776" y="101.439972" textLength="1.482000" font-size="8px"> </text>
<text x="368.354980" y="101.439972" textLength="1.842000" font-size="8px">]</text>
<text x="364.874969" y="101.439972" textLength="3.510000" font-size="8px">0</text>
<text x="360.208160" y="101.439972" textLength="3.510000" font-size="8px">1</text>
<text x="354.869354" y="101.439972" textLength="3.510000" font-size="8px">8</text>
<text x="350.220551" y="101.439972" textLength="4.632000" font-size="8px">m</text>
<text x="345.540558" y="101.439972" textLength="4.632000" font-size="8px">m</text>
<text x="344.159943" y="101.439972" textLength="1.398000" font-size="8px">I</text>
<text x="440.105377" y="91.599976" textLength="3.144000" font-size="8px">e</text>
<text x="435.663574" y="91.599976" textLength="1.284000" font-size="8px">l</text>
<text x="432.664185" y="91.599976" textLength="2.982000" font-size="8px">a</text>
<text x="429.664795" y="91.599976" textLength="3.096000" font-size="8px">v</text>
<text x="428.225403" y="91.599976" textLength="1.482000" font-size="8px"> </text>
<text x="425.535614" y="91.599976" textLength="2.676000" font-size="8px">s</text>
<text x="422.416199" y="91.599976" textLength="3.108000" font-size="8px">b</text>
<text x="406.432190" y="91.599976" textLength="1.482000" font-size="8px"> </text>
<text x="404.152191" y="91.599976" textLength="2.250000" font-size="8px">t</text>
<text x="401.572784" y="91.599976" textLength="2.604000" font-size="8px">c</text>
<text x="394.033783" y="91.599976" textLength="3.144000" font-size="8px">e</text>
<text x="389.334595" y="91.599976" textLength="1.482000" font-size="8px"> </text>
<text x="388.193390" y="91.599976" textLength="1.170000" font-size="8px">:</text>
<text x="380.092194" y="91.599976" textLength="3.510000" font-size="8px">0</text>
<text x="376.568390" y="91.599976" textLength="3.510000" font-size="8px">1</text>
<text x="375.128998" y="91.599976" textLength="1.482000" font-size="8px"> </text>
<text x="371.701202" y="91.599976" textLength="3.414000" font-size="8px">=</text>
<text x="368.346008" y="91.599976" textLength="1.842000" font-size="8px">]</text>
<text x="364.865997" y="91.599976" textLength="3.510000" font-size="8px">0</text>
<text x="363.682190" y="91.599976" textLength="1.170000" font-size="8px">:</text>
<text x="360.202179" y="91.599976" textLength="3.510000" font-size="8px">1</text>
<text x="358.346375" y="91.599976" textLength="1.842000" font-size="8px">[</text>
<text x="354.866364" y="91.599976" textLength="3.510000" font-size="8px">8</text>
<text x="350.220551" y="91.599976" textLength="4.632000" font-size="8px">m</text>
<text x="425.941101" y="81.759979" textLength="1.284000" font-size="8px">l</text>
<text x="422.941711" y="81.759979" textLength="2.982000" font-size="8px">a</text>
<text x="418.502930" y="81.759979" textLength="1.482000" font-size="8px"> </text>
<text x="415.294739" y="81.759979" textLength="3.192000" font-size="8px">x</text>
<text x="412.355347" y="81.759979" textLength="2.982000" font-size="8px">a</text>
<text x="143.340607" y="107.919983" textLength="3.510000" font-size="8px">8</text>
<text x="407.953156" y="81.759979" textLength="4.386000" font-size="8px">M</text>
<text x="406.453766" y="81.759979" textLength="1.482000" font-size="8px"> </text>
<text x="404.173767" y="81.759979" textLength="2.250000" font-size="8px">t</text>
<text x="398.473755" y="81.759979" textLength="3.144000" font-size="8px">e</text>
<text x="397.173553" y="81.759979" textLength="1.284000" font-size="8px">l</text>
<text x="394.052948" y="81.759979" textLength="3.144000" font-size="8px">e</text>
<text x="390.850739" y="81.759979" textLength="3.186000" font-size="8px">S</text>
<text x="388.210144" y="81.759979" textLength="1.170000" font-size="8px">:</text>
<text x="386.710754" y="81.759979" textLength="1.482000" font-size="8px"> </text>
<text x="383.586548" y="81.759979" textLength="3.108000" font-size="8px">b</text>
<text x="376.580322" y="81.759979" textLength="3.510000" font-size="8px">0</text>
<text x="375.140930" y="81.759979" textLength="1.482000" font-size="8px"> </text>
<text x="371.710724" y="81.759979" textLength="3.414000" font-size="8px">=</text>
<text x="370.211334" y="81.759979" textLength="1.482000" font-size="8px"> </text>
<text x="368.353149" y="81.759979" textLength="1.842000" font-size="8px">]</text>
<text x="364.873138" y="81.759979" textLength="3.510000" font-size="8px">0</text>
<text x="363.686951" y="81.759979" textLength="1.170000" font-size="8px">:</text>
<text x="354.868744" y="81.759979" textLength="3.510000" font-size="8px">8</text>
<text x="350.220551" y="81.759979" textLength="4.632000" font-size="8px">m</text>
<text x="345.540558" y="81.759979" textLength="4.632000" font-size="8px">m</text>
<text x="344.159943" y="81.759979" textLength="1.398000" font-size="8px">I</text>
<text x="424.264099" y="71.919983" textLength="1.284000" font-size="8px">l</text>
<text x="421.264709" y="71.919983" textLength="2.982000" font-size="8px">a</text>
<text x="418.265320" y="71.919983" textLength="3.096000" font-size="8px">v</text>
<text x="416.765930" y="71.919983" textLength="1.482000" font-size="8px"> </text>
<text x="413.568542" y="71.919983" textLength="3.186000" font-size="8px">n</text>
<text x="412.307343" y="71.919983" textLength="1.302000" font-size="8px">i</text>
<text x="397.135132" y="71.919983" textLength="1.284000" font-size="8px">l</text>
<text x="389.317749" y="71.919983" textLength="1.482000" font-size="8px"> </text>
<text x="388.176544" y="71.919983" textLength="1.170000" font-size="8px">:</text>
<text x="398.452179" y="91.599976" textLength="3.144000" font-size="8px">e</text>
<text x="386.677155" y="71.919983" textLength="1.482000" font-size="8px"> </text>
<text x="383.557770" y="71.919983" textLength="3.108000" font-size="8px">b</text>
<text x="376.556366" y="71.919983" textLength="3.510000" font-size="8px">0</text>
<text x="375.116974" y="71.919983" textLength="1.482000" font-size="8px"> </text>
<text x="371.691559" y="71.919983" textLength="3.414000" font-size="8px">=</text>
<text x="370.192169" y="71.919983" textLength="1.482000" font-size="8px"> </text>
<text x="368.338776" y="71.919983" textLength="1.842000" font-size="8px">]</text>
<text x="364.858765" y="71.919983" textLength="3.510000" font-size="8px">0</text>
<text x="360.197357" y="71.919983" textLength="3.510000" font-size="8px">1</text>
<text x="354.863953" y="71.919983" textLength="3.510000" font-size="8px">8</text>
<text x="345.540558" y="71.919983" textLength="4.632000" font-size="8px">m</text>
<text x="344.159943" y="71.919983" textLength="1.398000" font-size="8px">I</text>
<text x="207.782318" y="99.939987" textLength="3.510000" font-size="8px">0</text>
<text x="203.163513" y="99.939987" textLength="3.150000" font-size="8px">o</text>
<text x="201.004120" y="99.939987" textLength="2.250000" font-size="8px">t</text>
<text x="199.505325" y="99.939987" textLength="1.482000" font-size="8px"> </text>
<text x="429.902313" y="101.439972" textLength="1.482000" font-size="8px"> </text>
<text x="196.303131" y="99.939987" textLength="3.186000" font-size="8px">n</text>
<text x="191.918320" y="99.939987" textLength="1.302000" font-size="8px">i</text>
<text x="189.226120" y="99.939987" textLength="2.676000" font-size="8px">s</text>
<text x="185.507919" y="99.939987" textLength="2.250000" font-size="8px">t</text>
<text x="182.507919" y="99.939987" textLength="3.144000" font-size="8px">e</text>
<text x="177.806931" y="99.939987" textLength="1.482000" font-size="8px"> </text>
<text x="176.666336" y="99.939987" textLength="1.170000" font-size="8px">:</text>
<text x="175.167542" y="99.939987" textLength="1.482000" font-size="8px"> </text>
<text x="172.043335" y="99.939987" textLength="3.108000" font-size="8px">b</text>
<text x="156.821350" y="99.939987" textLength="1.842000" font-size="8px">]</text>
<text x="153.341949" y="99.939987" textLength="3.510000" font-size="8px">2</text>
<text x="152.155746" y="99.939987" textLength="1.170000" font-size="8px">:</text>
<text x="146.818146" y="99.939987" textLength="1.842000" font-size="8px">[</text>
<text x="143.338745" y="99.939987" textLength="3.510000" font-size="8px">8</text>
<text x="138.659348" y="99.939987" textLength="4.632000" font-size="8px">m</text>
<text x="134.039948" y="99.939987" textLength="4.632000" font-size="8px">m</text>
<text x="249.661713" y="90.399994" textLength="1.728000" font-size="8px">)</text>
<text x="247.395508" y="90.399994" textLength="2.250000" font-size="8px">t</text>
<text x="242.933289" y="90.399994" textLength="3.186000" font-size="8px">u</text>
<text x="240.232697" y="90.399994" textLength="2.676000" font-size="8px">s</text>
<text x="233.573303" y="90.399994" textLength="3.618000" font-size="8px">R</text>
<text x="230.573303" y="90.399994" textLength="3.036000" font-size="8px">_</text>
<text x="227.393311" y="90.399994" textLength="3.144000" font-size="8px">e</text>
<text x="225.352722" y="90.399994" textLength="2.178000" font-size="8px">r</text>
<text x="219.295105" y="90.399994" textLength="3.108000" font-size="8px">p</text>
<text x="214.646912" y="90.399994" textLength="4.632000" font-size="8px">m</text>
<text x="208.360718" y="90.399994" textLength="3.150000" font-size="8px">C</text>
<text x="203.479721" y="90.399994" textLength="3.186000" font-size="8px">n</text>
<text x="200.355515" y="90.399994" textLength="3.108000" font-size="8px">g</text>
<text x="196.345108" y="90.399994" textLength="2.676000" font-size="8px">s</text>
<text x="192.626907" y="90.399994" textLength="2.250000" font-size="8px">t</text>
<text x="190.048111" y="90.399994" textLength="2.604000" font-size="8px">c</text>
<text x="186.928116" y="90.399994" textLength="3.144000" font-size="8px">e</text>
<text x="176.666336" y="90.399994" textLength="1.170000" font-size="8px">:</text>
<text x="175.167542" y="90.399994" textLength="1.482000" font-size="8px"> </text>
<text x="168.563934" y="90.399994" textLength="3.510000" font-size="8px">1</text>
<text x="165.037735" y="90.399994" textLength="3.510000" font-size="8px">0</text>
<text x="163.538940" y="90.399994" textLength="1.482000" font-size="8px"> </text>
<text x="158.679550" y="90.399994" textLength="1.482000" font-size="8px"> </text>
<text x="156.821350" y="90.399994" textLength="1.842000" font-size="8px">]</text>
<text x="152.155746" y="90.399994" textLength="1.170000" font-size="8px">:</text>
<text x="146.818146" y="90.399994" textLength="1.842000" font-size="8px">[</text>
<text x="143.338745" y="90.399994" textLength="3.510000" font-size="8px">8</text>
<text x="138.659348" y="90.399994" textLength="4.632000" font-size="8px">m</text>
<text x="134.039948" y="90.399994" textLength="4.632000" font-size="8px">m</text>
<text x="313.602570" y="45.939987" textLength="1.728000" font-size="8px">)</text>
<text x="305.489960" y="45.939987" textLength="1.728000" font-size="8px">(</text>
<text x="304.050568" y="45.939987" textLength="1.482000" font-size="8px"> </text>
<text x="302.750366" y="45.939987" textLength="1.284000" font-size="8px">l</text>
<text x="297.528564" y="45.939987" textLength="2.178000" font-size="8px">r</text>
<text x="281.304565" y="45.939987" textLength="3.186000" font-size="8px">n</text>
<text x="278.180359" y="45.939987" textLength="3.108000" font-size="8px">g</text>
<text x="221.780396" y="80.919983" textLength="1.728000" font-size="8px">)</text>
<text x="218.300385" y="80.919983" textLength="3.510000" font-size="8px">1</text>
<text x="215.119781" y="80.919983" textLength="3.150000" font-size="8px">C</text>
<text x="211.579773" y="80.919983" textLength="3.618000" font-size="8px">R</text>
<text x="208.398560" y="80.919983" textLength="3.186000" font-size="8px">S</text>
<text x="200.387939" y="80.919983" textLength="3.108000" font-size="8px">g</text>
<text x="199.067337" y="80.919983" textLength="1.302000" font-size="8px">i</text>
<text x="196.372742" y="80.919983" textLength="2.676000" font-size="8px">s</text>
<text x="194.933334" y="80.919983" textLength="1.482000" font-size="8px"> </text>
<text x="190.073929" y="80.919983" textLength="2.604000" font-size="8px">c</text>
<text x="185.650726" y="80.919983" textLength="1.284000" font-size="8px">l</text>
<text x="182.530121" y="80.919983" textLength="3.144000" font-size="8px">e</text>
<text x="179.325516" y="80.919983" textLength="3.186000" font-size="8px">S</text>
<text x="176.684906" y="80.919983" textLength="1.170000" font-size="8px">:</text>
<text x="350.220551" y="71.919983" textLength="4.632000" font-size="8px">m</text>
<text x="175.185501" y="80.919983" textLength="1.482000" font-size="8px"> </text>
<text x="168.578903" y="80.919983" textLength="3.510000" font-size="8px">0</text>
<text x="165.050308" y="80.919983" textLength="3.510000" font-size="8px">0</text>
<text x="160.189697" y="80.919983" textLength="3.414000" font-size="8px">=</text>
<text x="158.690292" y="80.919983" textLength="1.482000" font-size="8px"> </text>
<text x="153.349701" y="80.919983" textLength="3.510000" font-size="8px">2</text>
<text x="152.161102" y="80.919983" textLength="1.170000" font-size="8px">:</text>
<text x="146.820511" y="80.919983" textLength="1.842000" font-size="8px">[</text>
<text x="138.660522" y="80.919983" textLength="4.632000" font-size="8px">m</text>
<text x="132.659927" y="80.919983" textLength="1.398000" font-size="8px">I</text>
<text x="162.275955" y="45.939987" textLength="3.150000" font-size="8px">o</text>
<text x="160.234756" y="45.939987" textLength="2.178000" font-size="8px">r</text>
<text x="157.054153" y="45.939987" textLength="3.144000" font-size="8px">e</text>
<text x="152.315948" y="45.939987" textLength="1.482000" font-size="8px"> </text>
<text x="149.135345" y="45.939987" textLength="3.144000" font-size="8px">e</text>
<text x="144.099533" y="45.939987" textLength="1.482000" font-size="8px"> </text>
<text x="139.192734" y="45.939987" textLength="2.676000" font-size="8px">s</text>
<text x="418.853271" y="45.939987" textLength="2.604000" font-size="8px">c</text>
<text x="411.296265" y="45.939987" textLength="3.144000" font-size="8px">e</text>
<text x="408.136078" y="45.939987" textLength="3.186000" font-size="8px">S</text>
<text x="406.636688" y="45.939987" textLength="1.482000" font-size="8px"> </text>
<text x="403.476501" y="45.939987" textLength="3.186000" font-size="8px">n</text>
<text x="400.295898" y="45.939987" textLength="3.150000" font-size="8px">o</text>
<text x="399.019684" y="45.939987" textLength="1.302000" font-size="8px">i</text>
<text x="393.860291" y="45.939987" textLength="2.982000" font-size="8px">a</text>
<text x="391.819092" y="45.939987" textLength="2.178000" font-size="8px">r</text>
<text x="388.700897" y="45.939987" textLength="3.144000" font-size="8px">e</text>
<text x="381.785309" y="45.939987" textLength="3.822000" font-size="8px">O</text>
<text x="369.050934" y="45.939987" textLength="3.108000" font-size="8px">p</text>
<text x="361.264130" y="45.939987" textLength="3.150000" font-size="8px">o</text>
<text x="425.524689" y="71.919983" textLength="3.186000" font-size="8px">u</text>
<text x="176.399933" y="32.019989" textLength="3.510000" font-size="8px">5</text>
<text x="130.019928" y="32.019989" textLength="3.510000" font-size="8px">6</text>
<text x="222.779938" y="32.019989" textLength="3.510000" font-size="8px">4</text>
<text x="310.436371" y="45.939987" textLength="3.150000" font-size="8px">C</text>
<text x="315.479950" y="32.019989" textLength="3.510000" font-size="8px">2</text>
<text x="408.239960" y="32.019989" textLength="3.510000" font-size="8px">0</text>
<text x="207.739838" y="107.919983" textLength="3.510000" font-size="8px">1</text>
<text x="394.057709" y="101.439972" textLength="3.144000" font-size="8px">e</text>
<text x="152.160004" y="107.919983" textLength="1.170000" font-size="8px">:</text>
<text x="397.178314" y="101.439972" textLength="1.284000" font-size="8px">l</text>
<text x="413.592590" y="91.599976" textLength="3.186000" font-size="8px">n</text>
<text x="434.341095" y="101.439972" textLength="2.982000" font-size="8px">a</text>
<text x="358.348755" y="81.759979" textLength="1.842000" font-size="8px">[</text>
<text x="185.457626" y="107.919983" textLength="2.250000" font-size="8px">t</text>
<text x="163.547409" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="211.480713" y="90.399994" textLength="3.150000" font-size="8px">o</text>
<text x="430.382904" y="81.759979" textLength="3.144000" font-size="8px">e</text>
<text x="380.345917" y="45.939987" textLength="1.482000" font-size="8px"> </text>
<text x="383.572205" y="91.599976" textLength="3.108000" font-size="8px">b</text>
<text x="156.829697" y="80.919983" textLength="1.842000" font-size="8px">]</text>
<text x="358.343964" y="71.919983" textLength="1.842000" font-size="8px">[</text>
<text x="199.037308" y="90.399994" textLength="1.302000" font-size="8px">i</text>
<text x="363.688171" y="101.439972" textLength="1.170000" font-size="8px">:</text>
<text x="358.349365" y="101.439972" textLength="1.842000" font-size="8px">[</text>
<text x="406.459137" y="101.439972" textLength="1.482000" font-size="8px"> </text>
<text x="193.178925" y="99.939987" textLength="3.108000" font-size="8px">g</text>
<text x="153.755356" y="45.939987" textLength="3.456000" font-size="8px">Z</text>
<text x="419.942322" y="81.759979" textLength="3.096000" font-size="8px">v</text>
<text x="299.629761" y="45.939987" textLength="3.150000" font-size="8px">o</text>
<text x="412.331390" y="91.599976" textLength="1.302000" font-size="8px">i</text>
<text x="206.681915" y="90.399994" textLength="1.728000" font-size="8px">(</text>
<text x="143.340515" y="80.919983" textLength="3.510000" font-size="8px">8</text>
<text x="360.206940" y="81.759979" textLength="3.510000" font-size="8px">1</text>
<text x="397.154388" y="91.599976" textLength="1.284000" font-size="8px">l</text>
<text x="385.581512" y="45.939987" textLength="3.108000" font-size="8px">p</text>
<text x="160.178345" y="99.939987" textLength="3.414000" font-size="8px">=</text>
<text x="172.043335" y="90.399994" textLength="3.108000" font-size="8px">b</text>
<text x="414.414459" y="45.939987" textLength="1.284000" font-size="8px">l</text>
<text x="148.676346" y="90.399994" textLength="3.510000" font-size="8px">3</text>
<text x="398.479126" y="101.439972" textLength="3.144000" font-size="8px">e</text>
<text x="289.066772" y="45.939987" textLength="3.150000" font-size="8px">o</text>
<text x="182.457031" y="107.919983" textLength="3.144000" font-size="8px">e</text>
<text x="132.659943" y="90.399994" textLength="1.398000" font-size="8px">I</text>
<text x="284.506775" y="45.939987" textLength="1.482000" font-size="8px"> </text>
<text x="361.859955" y="32.019989" textLength="3.510000" font-size="8px">1</text>
<text x="200.959839" y="107.919983" textLength="2.250000" font-size="8px">t</text>
<text x="179.305725" y="99.939987" textLength="3.186000" font-size="8px">S</text>
<text x="148.676346" y="99.939987" textLength="3.510000" font-size="8px">3</text>
<text x="131.639923" y="45.939987" textLength="4.386000" font-size="8px">M</text>
<text x="383.590149" y="101.439972" textLength="3.108000" font-size="8px">b</text>
<text x="138.660599" y="107.919983" textLength="4.632000" font-size="8px">m</text>
<text x="160.178345" y="90.399994" textLength="3.414000" font-size="8px">=</text>
<text x="246.135498" y="90.399994" textLength="1.284000" font-size="8px">l</text>
<text x="394.014526" y="71.919983" textLength="3.144000" font-size="8px">e</text>
<text x="182.507919" y="90.399994" textLength="3.144000" font-size="8px">e</text>
<text x="185.627914" y="90.399994" textLength="1.284000" font-size="8px">l</text>
<text x="177.806931" y="90.399994" textLength="1.482000" font-size="8px"> </text>
<text x="172.058899" y="80.919983" textLength="3.108000" font-size="8px">b</text>
<text x="177.826111" y="80.919983" textLength="1.482000" font-size="8px"> </text>
<text x="163.550903" y="80.919983" textLength="1.482000" font-size="8px"> </text>
<text x="192.653336" y="80.919983" textLength="2.250000" font-size="8px">t</text>
<text x="364.444733" y="45.939987" textLength="4.632000" font-size="8px">m</text>
<text x="428.705902" y="71.919983" textLength="3.144000" font-size="8px">e</text>
<text x="377.227722" y="45.939987" textLength="3.144000" font-size="8px">e</text>
<text x="175.113617" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="436.924164" y="91.599976" textLength="3.186000" font-size="8px">u</text>
<text x="206.283508" y="99.939987" textLength="1.482000" font-size="8px"> </text>
<text x="222.353912" y="90.399994" textLength="2.982000" font-size="8px">a</text>
<text x="407.931580" y="91.599976" textLength="4.386000" font-size="8px">M</text>
<text x="285.946167" y="45.939987" textLength="3.150000" font-size="8px">C</text>
<text x="163.538940" y="99.939987" textLength="1.482000" font-size="8px"> </text>
<text x="398.430542" y="71.919983" textLength="3.144000" font-size="8px">e</text>
<text x="145.598938" y="45.939987" textLength="3.546000" font-size="8px">B</text>
<text x="441.782288" y="101.439972" textLength="3.144000" font-size="8px">e</text>
<text x="372.170319" y="45.939987" textLength="2.982000" font-size="8px">a</text>
<text x="194.906311" y="90.399994" textLength="1.482000" font-size="8px"> </text>
<text x="404.130554" y="71.919983" textLength="2.250000" font-size="8px">t</text>
<text x="134.040527" y="80.919983" textLength="4.632000" font-size="8px">m</text>
<text x="389.351349" y="81.759979" textLength="1.482000" font-size="8px"> </text>
<text x="165.046814" y="107.919983" textLength="3.510000" font-size="8px">1</text>
<text x="415.300720" y="101.439972" textLength="3.192000" font-size="8px">x</text>
<text x="416.792389" y="91.599976" textLength="1.890000" font-size="8px">-</text>
<text x="295.308563" y="45.939987" textLength="2.250000" font-size="8px">t</text>
<text x="307.234161" y="45.939987" textLength="3.186000" font-size="8px">S</text>
<text x="415.672668" y="45.939987" textLength="3.144000" font-size="8px">e</text>
<text x="363.677368" y="71.919983" textLength="1.170000" font-size="8px">:</text>
<text x="390.833984" y="91.599976" textLength="3.186000" font-size="8px">S</text>
<text x="276.862152" y="45.939987" textLength="1.302000" font-size="8px">i</text>
<text x="407.909943" y="71.919983" textLength="4.386000" font-size="8px">M</text>
<text x="187.727325" y="99.939987" textLength="1.482000" font-size="8px"> </text>
<text x="186.953323" y="80.919983" textLength="3.144000" font-size="8px">e</text>
<text x="134.040604" y="107.919983" textLength="4.632000" font-size="8px">m</text>
<text x="269.159943" y="32.019989" textLength="3.510000" font-size="8px">3</text>
<text x="206.240448" y="107.919983" textLength="1.482000" font-size="8px"> </text>
<text x="203.514542" y="80.919983" textLength="3.186000" font-size="8px">n</text>
<text x="168.563934" y="99.939987" textLength="3.510000" font-size="8px">0</text>
<text x="396.739685" y="45.939987" textLength="2.250000" font-size="8px">t</text>
<text x="141.859131" y="45.939987" textLength="2.250000" font-size="8px">t</text>
<text x="237.112701" y="90.399994" textLength="3.144000" font-size="8px">e</text>
<text x="30.961147" y="44.259979" textLength="4.632000" font-size="8px">m</text>
<text x="148.681107" y="80.919983" textLength="3.510000" font-size="8px">3</text>
<text x="165.037735" y="99.939987" textLength="3.510000" font-size="8px">1</text>
<text x="420.370117" y="101.439972" textLength="3.738000" font-size="8px">A</text>
<text x="401.551147" y="71.919983" textLength="2.604000" font-size="8px">c</text>
<text x="273.659943" y="45.939987" textLength="3.186000" font-size="8px">S</text>
<text x="386.694000" y="91.599976" textLength="1.482000" font-size="8px"> </text>
<text x="153.341949" y="90.399994" textLength="3.510000" font-size="8px">2</text>
<text x="344.159943" y="91.599976" textLength="1.398000" font-size="8px">I</text>
<text x="196.257034" y="107.919983" textLength="3.186000" font-size="8px">n</text>
<text x="401.594360" y="81.759979" textLength="2.604000" font-size="8px">c</text>
<text x="380.077759" y="71.919983" textLength="3.510000" font-size="8px">0</text>
<text x="179.305725" y="90.399994" textLength="3.186000" font-size="8px">S</text>
<text x="132.659943" y="99.939987" textLength="1.398000" font-size="8px">I</text>
<text x="418.696198" y="91.599976" textLength="3.738000" font-size="8px">A</text>
<text x="136.016327" y="45.939987" textLength="3.186000" font-size="8px">u</text>
<text x="390.817139" y="71.919983" textLength="3.186000" font-size="8px">S</text>
<text x="421.431458" y="45.939987" textLength="2.250000" font-size="8px">t</text>
<text x="345.540558" y="91.599976" textLength="4.632000" font-size="8px">m</text>
<text x="156.827393" y="107.919983" textLength="1.842000" font-size="8px">]</text>
<text x="406.410553" y="71.919983" textLength="1.482000" font-size="8px"> </text>
<text x="206.719147" y="80.919983" textLength="1.728000" font-size="8px">(</text>
<text x="358.139923" y="45.939987" textLength="3.150000" font-size="8px">C</text>
<text x="370.201813" y="91.599976" textLength="1.482000" font-size="8px"> </text>
<text x="292.247375" y="45.939987" textLength="3.186000" font-size="8px">n</text>
<text x="375.126526" y="45.939987" textLength="2.178000" font-size="8px">r</text>
<text x="380.106537" y="81.759979" textLength="3.510000" font-size="8px">1</text>
<text x="427.201691" y="81.759979" textLength="3.186000" font-size="8px">u</text>
<text x="83.639999" y="32.019989" textLength="3.510000" font-size="8px">7</text>
<text x="418.509521" y="101.439972" textLength="1.890000" font-size="8px">-</text>
<text x="158.679550" y="99.939987" textLength="1.482000" font-size="8px"> </text>
</svg>
<figcaption>Figure 5-27.  Imm8 Controls for VRANGEPD/SD/PS/SS
</figcaption></figure>
```


When one or more of the input value is a NAN, the comparison operation may signal invalid exception (IE). Details with one of more input value is NAN is listed in Table 5-12. If the comparison raises an IE, the sign select control (Imm8[3:2] has no effect to the range operation output, this is indicated also in Table 5-12.

When both input values are zeros of opposite signs, the comparison operation of MIN/MAX in the range compare operation is slightly different from the conceptually similar FP MIN/MAX operation that are found in the instructions VMAXPD/VMINPD. The details of MIN/MAX/MIN_ABS/MAX_ABS operation for VRANGEPD/PS/SD/SS for magni-tude-0, opposite-signed input cases are listed in Table 5-13.

Additionally, non-zero, equal-magnitude with opposite-sign input values perform MIN_ABS or MAX_ABS compar-ison operation with result listed in Table 5-14.

### Table 5-12. Signaling of Comparison Operation of One or More NaN Input Values and Effect of Imm8[3:2]


|**Src1**|**Src2**|**Result**|**IE Signaling Due to Comparison**|**Imm8[3:2] Effect to Range Output**|
|--------|--------|----------|----------------------------------|------------------------------------|
|sNaN1|sNaN2|Quiet(sNaN1)|Yes|Ignored|
|sNaN1|qNaN2|Quiet(sNaN1)|Yes|Ignored|
|sNaN1|Norm2|Quiet(sNaN1)|Yes|Ignored|
|qNaN1|sNaN2|Quiet(sNaN2)|Yes|Ignored|
|qNaN1|qNaN2|qNaN1|No|Applicable|
|qNaN1|Norm2|Norm2|No|Applicable|
|Norm1|sNaN2|Quiet(sNaN2)|Yes|Ignored|
|Norm1|qNaN2|Norm1|No|Applicable|
### Table 5-13. Comparison Result for Opposite-Signed Zero Cases for MIN, MIN_ABS and MAX, MAX_ABS


||**MIN and MIN_AB**|**S**||**MAX and MAX_A**|**BS**|
||------------------|-----||-----------------|------|
|**Src1**|**Src2**|**Result**|**Src1**|**Src2**|**Result**|
|+0|-0|-0|+0|-0|+0|
|-0|+0|-0|-0|+0|+0|
### Table 5-14. Comparison Result of Equal-Magnitude Input Cases for MIN_ABS and MAX_ABS, (|a| = |b|, a>0, b<0)


|**M**|**IN_ABS (|a| = |b|, a>**|**0, b<0)**|**M**|**AX_ABS (|a| = |b|, a>**|**0, b<0)**|
|-----|----------|-|---|-|------|-----------|-----|----------|-|---|-|------|-----------|
|**Src1**|**Src2**|**Result**|**Src1**|**Src2**|**Result**|
|a|b|b|a|b|a|
|b|a|b|b|a|a|

### Operation
#### VRANGEPD (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b == 1) AND (SRC2 *is memory*)
                      THEN DEST[i+63:i] <-  RangeDP (SRC1[i+63:i], SRC2[63:0], CmpOpCtl[1:0], SignSelCtl[1:0]);
                      ELSE DEST[i+63:i] <-  RangeDP (SRC1[i+63:i], SRC2[i+63:i], DAZ, CmpOpCtl[1:0], SignSelCtl[1:0]);
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
The following example describes a common usage of this instruction for checking that the input operand isbounded between $$\pm$$1023.
VRANGEPD zmm_dst, zmm_src, zmm_1023, 02h;
Where:
            zmm_dst is the destination operand.
            zmm_src is the input operand to compare against $$\pm$$1023 (this is SRC1).
            zmm_1023 is the reference operand, contains the value of 1023 (and this is SRC2).
            IMM=02(imm8[1:0]='10) selects the Min Absolute value operation with selection of SRC1.sign.
In case |zmm_src| < 1023 (i.e. SRC1 is smaller than 1023 in magnitude), then its value will be written intozmm_dst. Otherwise, the value stored in zmm_dst will get the value of 1023 (received on zmm_1023, which isSRC2).
However, the sign control (imm8[3:2]='00) instructs to select the sign of SRC1 received from zmm_src. So, evenin the case of |zmm_src| *   1023, the selected sign of SRC1 is kept. 
Thus, if zmm_src < -1023, the result of VRANGEPD will be the minimal value of -1023 while if zmm_src > +1023,the result of VRANGE will be the maximal value of +1023.
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VRANGEPD __m512d _mm512_range_pd ( __m512d a, __m512d b, int imm);
VRANGEPD __m512d _mm512_range_round_pd ( __m512d a, __m512d b, int imm, int sae);
VRANGEPD __m512d _mm512_mask_range_pd (__m512 ds, __mmask8 k, __m512d a, __m512d b, int imm);
VRANGEPD __m512d _mm512_mask_range_round_pd (__m512d s, __mmask8 k, __m512d a, __m512d b, int imm, int sae);
VRANGEPD __m512d _mm512_maskz_range_pd ( __mmask8 k, __m512d a, __m512d b, int imm);
VRANGEPD __m512d _mm512_maskz_range_round_pd ( __mmask8 k, __m512d a, __m512d b, int imm, int sae);
VRANGEPD __m256d _mm256_range_pd ( __m256d a, __m256d b, int imm);
VRANGEPD __m256d _mm256_mask_range_pd (__m256d s, __mmask8 k, __m256d a, __m256d b, int imm);
VRANGEPD __m256d _mm256_maskz_range_pd ( __mmask8 k, __m256d a, __m256d b, int imm);
VRANGEPD __m128d _mm_range_pd ( __m128 a, __m128d b, int imm);
VRANGEPD __m128d _mm_mask_range_pd (__m128 s, __mmask8 k, __m128d a, __m128d b, int imm);
VRANGEPD __m128d _mm_maskz_range_pd ( __mmask8 k, __m128d a, __m128d b, int imm);
```
### SIMD Floating-Point Exceptions


Invalid, Denormal

### Other Exceptions


See Exceptions Type E2.

