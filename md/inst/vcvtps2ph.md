----------------------------
title : VCVTPS2PH (Intel x86/64 assembly instruction)
cat_title : VCVTPS2PH
ref_title : VCVTPS2PH
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VCVTPS2PH

**Convert Single-Precision FP value to 16-bit FP value**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.128.66.0F3A.W0 1D /r ib\newline{}VCVTPS2PH xmm1/m64, xmm2, imm8|MRI|V/V|F16C|Convert four packed single-precision floating-point values in xmm2 to packed half-precision (16-bit) floating-point values in xmm1/m64. Imm8 provides rounding controls.|
|VEX.256.66.0F3A.W0 1D /r ib\newline{}VCVTPS2PH xmm1/m128, ymm2, imm8|MRI|V/V|F16C|Convert eight packed single-precision floating-point values in ymm2 to packed half-precision (16-bit) floating-point values in xmm1/m128. Imm8 provides rounding controls.|
|EVEX.128.66.0F3A.W0 1D /r ib\newline{}VCVTPS2PH xmm1/m64 {k1}{z}, xmm2, imm8|HVM|V/V|AVX512VL\newline{}AVX512F|Convert four packed single-precision floating-point values in xmm2 to packed half-precision (16-bit) floating-point values in xmm1/m64. Imm8 provides rounding controls.|
|EVEX.256.66.0F3A.W0 1D /r ib\newline{}VCVTPS2PH xmm1/m128 {k1}{z}, ymm2, imm8|HVM|V/V|AVX512VL\newline{}AVX512F|Convert eight packed single-precision floating-point values in ymm2 to packed half-precision (16-bit) floating-point values in xmm1/m128. Imm8 provides rounding controls.|
|EVEX.512.66.0F3A.W0 1D /r ib\newline{}VCVTPS2PH ymm1/m256 {k1}{z}, zmm2{sae}, imm8|HVM|V/V|AVX512F|Convert sixteen packed single-precision floating-point values in zmm2 to packed half-precision (16-bit) floating-point values in ymm1/m256. Imm8 provides rounding controls.|
###                                                      Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

 MRI ModRM:r/m (w) ModRM:reg (r) Imm8 NA

HVM ModRM:r/m (w) ModRM:reg (r) Imm8 NA

### Description


Convert packed single-precision floating values in the source operand to half-precision (16-bit) floating-point values and store to the destination operand. The rounding mode is specified using the immediate field (imm8).

Underflow results (i.e., tiny results) are converted to denormals. MXCSR.FTZ is ignored. If a source element is denormal relative to the input format with DM masked and at least one of PM or UM unmasked; a SIMD exception will be raised with DE, UE and PE set.

The immediate byte defines several bit fields that control rounding operation. The effect and encoding of the RC field are listed in Table 5-3.

```embed
<figure>
<svg viewBox="0 0 396.480042 165.779999">
<rect x="0.000000" y="10.000031" width="0.480000" height="138.539993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000031" width="0.480040" height="138.539993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="148.599991" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.180023" y="129.399994" width="40.020000" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="288.180023" y="129.399994" width="40.020000" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.220001" y="129.399994" width="39.959999" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="248.220001" y="129.399994" width="39.959999" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.200012" y="129.399994" width="40.020000" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.200012" y="129.399994" width="40.020000" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.240021" y="129.399994" width="39.959999" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.240021" y="129.399994" width="39.959999" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.260002" y="129.399994" width="79.980003" height="10.320000" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<rect x="88.260002" y="129.399994" width="79.980003" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="8.279999" y="129.399994" width="79.980003" height="10.320000" fill-rule="nonzero"  fill=" rgb(193,193,193) " stroke="black" />
<rect x="8.279999" y="129.399994" width="79.980003" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.220001" y="46.540009" width="79.980003" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="248.220001" y="46.540009" width="79.980003" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.240021" y="46.540009" width="79.980003" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.240021" y="46.540009" width="79.980003" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.260002" y="46.540009" width="79.980003" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="88.260002" y="46.540009" width="79.980003" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="8.279999" y="46.540009" width="79.980003" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="8.279999" y="46.540009" width="79.980003" height="10.320000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.180023,56.860016 L288.180023,67.240021 L308.220032,67.240021 L308.220032,129.220016" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M208.200012,56.860016 L208.200012,77.620010 L268.200012,77.620010 L268.200012,129.400024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M128.220001,56.860016 L128.220001,87.940018 L228.239990,87.940018 L228.239990,129.400024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M48.239983,56.860016 L48.239983,98.320007 L188.219971,98.320007 L188.219971,129.400024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="293.940002" y="69.819992" width="28.500000" height="10.380000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="34.500008" y="67.239990" width="28.500000" height="10.380000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="193.980011" y="64.660004" width="28.440001" height="10.320000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="114.000008" y="67.239990" width="28.440001" height="10.380000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<text x="123.479454" y="74.380005" textLength="3.735931" font-size="8px">n</text>
<text x="119.760323" y="74.380005" textLength="3.735931" font-size="8px">o</text>
<text x="214.317169" y="71.800003" textLength="2.237527" font-size="8px">r</text>
<text x="210.538239" y="71.800003" textLength="3.735931" font-size="8px">e</text>
<text x="56.817848" y="74.380005" textLength="1.867965" font-size="8px">t</text>
<text x="54.777870" y="74.380005" textLength="2.237527" font-size="8px">r</text>
<text x="43.919472" y="74.380005" textLength="3.735931" font-size="8px">n</text>
<text x="40.191597" y="74.380005" textLength="3.735931" font-size="8px">o</text>
<text x="314.277161" y="76.960007" textLength="2.237527" font-size="8px">r</text>
<text x="310.498230" y="76.960007" textLength="3.735931" font-size="8px">e</text>
<text x="307.198395" y="76.960007" textLength="3.359650" font-size="8px">v</text>
<text x="299.700317" y="76.960007" textLength="3.735931" font-size="8px">o</text>
<text x="208.862427" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="203.462799" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="199.322388" y="32.979736" textLength="1.867965" font-size="8px"> </text>
<text x="192.242920" y="32.979736" textLength="3.735931" font-size="8px">2</text>
<text x="186.782806" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="181.383179" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="178.083344" y="32.979736" textLength="3.359650" font-size="8px">x</text>
<text x="170.583923" y="32.979736" textLength="3.735931" font-size="8px">4</text>
<text x="166.804993" y="32.979736" textLength="3.735931" font-size="8px">6</text>
<text x="160.984741" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="151.797455" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="150.118286" y="32.979736" textLength="1.867965" font-size="8px">/</text>
<text x="146.399170" y="32.979736" textLength="3.735931" font-size="8px">1</text>
<text x="131.818970" y="32.979736" textLength="3.359650" font-size="8px">x</text>
<text x="130.558441" y="32.979736" textLength="1.867965" font-size="8px"> </text>
<text x="125.579430" y="32.979736" textLength="4.851335" font-size="8px">H</text>
<text x="120.959236" y="32.979736" textLength="4.481773" font-size="8px">P</text>
<text x="117.240105" y="32.979736" textLength="3.735931" font-size="8px">2</text>
<text x="113.459831" y="32.979736" textLength="4.481773" font-size="8px">S</text>
<text x="108.899437" y="32.979736" textLength="4.481773" font-size="8px">P</text>
<text x="104.758339" y="32.979736" textLength="4.105492" font-size="8px">T</text>
<text x="100.138145" y="32.979736" textLength="4.481773" font-size="8px">V</text>
<text x="95.159142" y="32.979736" textLength="4.851335" font-size="8px">C</text>
<text x="90.598747" y="32.979736" textLength="4.481773" font-size="8px">V</text>
<text x="354.659180" y="53.679993" textLength="3.735931" font-size="8px">2</text>
<text x="343.859924" y="53.679993" textLength="5.597177" font-size="8px">m</text>
<text x="340.499603" y="53.679993" textLength="3.359650" font-size="8px">x</text>
<text x="378.830566" y="136.540421" textLength="3.735931" font-size="8px">4</text>
<text x="365.925446" y="136.540421" textLength="3.735931" font-size="8px">e</text>
<text x="358.424011" y="136.540421" textLength="1.867965" font-size="8px">/</text>
<text x="349.245453" y="136.540421" textLength="5.597177" font-size="8px">m</text>
<text x="340.499603" y="136.540421" textLength="3.359650" font-size="8px">x</text>
<text x="75.631477" y="43.299835" textLength="3.735931" font-size="8px">6</text>
<text x="71.852547" y="43.299835" textLength="3.735931" font-size="8px">9</text>
<text x="70.171379" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="61.885139" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="60.203972" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="58.522804" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="55.160469" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="53.539101" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="51.857933" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="50.176765" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="136.377136" y="74.380005" textLength="1.867965" font-size="8px">t</text>
<text x="48.495598" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="46.874229" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="45.193062" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="41.830727" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="38.528191" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="35.165855" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="33.484688" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="31.863319" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="30.182152" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="26.819817" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="25.198448" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="199.740326" y="71.800003" textLength="3.735931" font-size="8px">o</text>
<text x="23.517281" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="21.836113" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="18.116982" y="43.299835" textLength="3.735931" font-size="8px">7</text>
<text x="10.618919" y="43.299835" textLength="3.735931" font-size="8px">1</text>
<text x="151.416443" y="43.299835" textLength="3.735931" font-size="8px">6</text>
<text x="146.432739" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="144.751587" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="141.449036" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="139.767883" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="136.405548" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="134.784180" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="133.102997" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="129.740662" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="128.059509" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="126.438133" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="124.756966" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="123.075798" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="118.092094" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="116.410927" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="343.845825" y="136.540421" textLength="5.597177" font-size="8px">m</text>
<text x="114.729759" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="113.108391" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="111.427223" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="109.746056" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="108.064888" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="103.081184" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="98.097481" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="94.318550" y="43.299835" textLength="3.735931" font-size="8px">5</text>
<text x="231.397339" y="43.299835" textLength="3.735931" font-size="8px">3</text>
<text x="228.094788" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="226.413605" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="223.051239" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="219.748688" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="216.386322" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="214.764954" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="213.083771" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="206.418854" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="204.737671" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="201.375305" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="196.391571" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="193.089020" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="191.407837" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="189.726654" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="184.742920" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="183.061737" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="181.380554" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="178.078003" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="179.699371" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="174.299072" y="43.299835" textLength="3.735931" font-size="8px">3</text>
<text x="170.579926" y="43.299835" textLength="3.735931" font-size="8px">6</text>
<text x="314.740204" y="43.299835" textLength="3.735931" font-size="8px">0</text>
<text x="155.195404" y="43.299835" textLength="3.735931" font-size="8px">4</text>
<text x="313.059021" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="306.394104" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="304.712921" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="303.031738" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="301.410370" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="299.729187" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="298.048004" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="296.366821" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="293.064270" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="289.701904" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="288.080536" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="284.718170" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="283.036987" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="279.734436" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="278.053253" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="276.372070" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="273.069519" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="271.388336" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="268.025970" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="36.847023" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="266.344788" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="264.723419" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="263.042236" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="259.679871" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="258.058502" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="254.279572" y="43.299835" textLength="3.735931" font-size="8px">1</text>
<text x="250.560425" y="43.299835" textLength="3.735931" font-size="8px">3</text>
<text x="51.000587" y="53.679993" textLength="3.735931" font-size="8px">3</text>
<text x="41.820000" y="53.679993" textLength="4.481773" font-size="8px">V</text>
<text x="126.420189" y="53.679993" textLength="4.481773" font-size="8px">S</text>
<text x="121.799995" y="53.679993" textLength="4.481773" font-size="8px">V</text>
<text x="201.779999" y="53.679993" textLength="4.481773" font-size="8px">V</text>
<text x="290.940582" y="53.679993" textLength="3.735931" font-size="8px">0</text>
<text x="281.760010" y="53.679993" textLength="4.481773" font-size="8px">V</text>
<text x="68.549248" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="66.868080" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="65.186913" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="63.505745" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="61.884377" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="58.522041" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="175.982208" y="32.979736" textLength="1.867965" font-size="8px"> </text>
<text x="56.840874" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="55.159706" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="51.857170" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="50.176003" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="48.494835" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="46.873466" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="40.208595" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="38.527428" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="36.846260" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="35.165092" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="33.483925" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="201.783661" y="32.979736" textLength="1.491685" font-size="8px">i</text>
<text x="28.500221" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="18.116219" y="126.160004" textLength="3.735931" font-size="8px">7</text>
<text x="14.337288" y="126.160004" textLength="3.735931" font-size="8px">2</text>
<text x="10.618156" y="126.160004" textLength="3.735931" font-size="8px">1</text>
<text x="155.194641" y="126.160004" textLength="3.735931" font-size="8px">4</text>
<text x="148.113159" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="143.069641" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="141.448273" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="139.767120" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="138.085938" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="134.783417" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="133.102234" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="131.421082" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="128.058746" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="126.437370" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="119.772499" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="114.728996" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="113.107628" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="109.745293" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="104.761589" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="99.718086" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="94.317787" y="126.160004" textLength="3.735931" font-size="8px">5</text>
<text x="90.598656" y="126.160004" textLength="3.735931" font-size="8px">9</text>
<text x="194.709625" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="188.044708" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="184.742157" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="181.379791" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="101.400017" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="310.919464" y="136.540009" textLength="3.735931" font-size="8px">0</text>
<text x="191.407074" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="36.840004" y="74.380005" textLength="3.359650" font-size="8px">c</text>
<text x="311.377838" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="129.739899" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="14.338051" y="43.299835" textLength="3.735931" font-size="8px">2</text>
<text x="25.197685" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="319.694031" y="126.160004" textLength="3.735931" font-size="8px">0</text>
<text x="43.511894" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="144.750824" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="221.429871" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="190.979248" y="136.540009" textLength="3.735931" font-size="8px">3</text>
<text x="98.096718" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="186.363525" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="354.645081" y="136.540421" textLength="3.735931" font-size="8px">1</text>
<text x="290.520020" y="126.160004" textLength="3.735931" font-size="8px">1</text>
<text x="151.415680" y="126.160004" textLength="3.735931" font-size="8px">6</text>
<text x="261.779999" y="136.540009" textLength="4.481773" font-size="8px">V</text>
<text x="65.187675" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="101.399254" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="274.690125" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="214.318451" y="126.160004" textLength="3.735931" font-size="8px">7</text>
<text x="71.851784" y="126.160004" textLength="3.735931" font-size="8px">9</text>
<text x="21.835350" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="138.086700" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="200.169739" y="126.160004" textLength="3.735931" font-size="8px">8</text>
<text x="206.400177" y="53.679993" textLength="4.481773" font-size="8px">S</text>
<text x="46.440193" y="53.679993" textLength="4.481773" font-size="8px">S</text>
<text x="136.404785" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="281.355804" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="130.558228" y="74.380005" textLength="3.735931" font-size="8px">e</text>
<text x="111.426460" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="116.410164" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="264.722656" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="135.179291" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="28.500984" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="183.060974" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="99.718849" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="134.337158" y="74.380005" textLength="2.237527" font-size="8px">r</text>
<text x="214.322540" y="32.979736" textLength="3.735931" font-size="8px">8</text>
<text x="266.340393" y="136.540009" textLength="4.851335" font-size="8px">H</text>
<text x="148.113922" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="266.344025" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="311.347931" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="209.721405" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="63.506508" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="140.578918" y="32.979736" textLength="5.597177" font-size="8px">m</text>
<text x="178.077240" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="286.399353" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="294.745453" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="303.419464" y="76.960007" textLength="3.735931" font-size="8px">n</text>
<text x="170.579163" y="126.160004" textLength="3.735931" font-size="8px">6</text>
<text x="41.829964" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="299.699280" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="45.192299" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="224.702515" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="146.431976" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="360.525146" y="136.540421" textLength="5.597177" font-size="8px">m</text>
<text x="276.371307" y="126.160004" textLength="3.735931" font-size="8px">1</text>
<text x="174.298309" y="126.160004" textLength="3.735931" font-size="8px">3</text>
<text x="90.599419" y="43.299835" textLength="3.735931" font-size="8px">9</text>
<text x="219.718781" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="210.960571" y="53.679993" textLength="3.735931" font-size="8px">1</text>
<text x="56.841637" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="221.399963" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="186.360413" y="136.540009" textLength="4.851335" font-size="8px">H</text>
<text x="106.383720" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="294.298950" y="126.160004" textLength="3.735931" font-size="8px">5</text>
<text x="291.383087" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="224.732422" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="304.683014" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="211.402588" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="218.067505" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="226.380402" y="136.540009" textLength="4.851335" font-size="8px">H</text>
<text x="309.726562" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="229.716156" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="207.238403" y="71.800003" textLength="3.359650" font-size="8px">v</text>
<text x="303.001831" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="296.339996" y="76.960007" textLength="3.359650" font-size="8px">c</text>
<text x="228.064880" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="143.070404" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="230.939453" y="136.540009" textLength="3.735931" font-size="8px">2</text>
<text x="268.025208" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="47.647346" y="74.380005" textLength="3.359650" font-size="8px">v</text>
<text x="221.820007" y="136.540009" textLength="4.481773" font-size="8px">V</text>
<text x="313.029114" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="349.259552" y="53.679993" textLength="5.597177" font-size="8px">m</text>
<text x="149.734528" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="131.421844" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="308.075287" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="23.516518" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="280.150238" y="126.160004" textLength="3.735931" font-size="8px">6</text>
<text x="123.075035" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="199.753937" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="309.756470" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="43.511131" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="196.380005" y="71.800003" textLength="3.359650" font-size="8px">c</text>
<text x="70.170616" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="196.390808" y="126.160004" textLength="3.735931" font-size="8px">4</text>
<text x="369.647949" y="136.540421" textLength="5.597177" font-size="8px">m</text>
<text x="116.400002" y="74.380005" textLength="3.359650" font-size="8px">c</text>
<text x="66.868843" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="121.394630" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="208.040222" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="103.080421" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="226.383698" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="306.364197" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="195.962067" y="32.979736" textLength="1.867965" font-size="8px">,</text>
<text x="104.762352" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="223.021332" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="210.539520" y="126.160004" textLength="3.735931" font-size="8px">4</text>
<text x="197.641205" y="32.979736" textLength="1.867965" font-size="8px"> </text>
<text x="149.735291" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="60.203209" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="119.773262" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="53.538338" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="235.176270" y="43.299835" textLength="3.735931" font-size="8px">2</text>
<text x="50.998940" y="74.380005" textLength="3.735931" font-size="8px">e</text>
<text x="106.382957" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="375.108063" y="136.540421" textLength="3.735931" font-size="8px">6</text>
<text x="216.357147" y="71.800003" textLength="1.867965" font-size="8px">t</text>
<text x="218.037598" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="31.862556" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="118.091331" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="30.181389" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="259.679108" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="194.710388" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="68.550011" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="174.303070" y="32.979736" textLength="1.867965" font-size="8px">,</text>
<text x="108.064125" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="250.559662" y="126.160004" textLength="3.735931" font-size="8px">3</text>
<text x="316.376953" y="76.960007" textLength="1.867965" font-size="8px">t</text>
<text x="40.209358" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="127.258385" y="74.380005" textLength="3.359650" font-size="8px">v</text>
<text x="186.364288" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="130.980591" y="53.679993" textLength="3.735931" font-size="8px">2</text>
<text x="198.072754" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="286.380188" y="53.679993" textLength="4.481773" font-size="8px">S</text>
<text x="261.361053" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="269.707153" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="121.393867" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="179.698608" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="274.690887" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="193.088257" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="75.630714" y="126.160004" textLength="3.735931" font-size="8px">6</text>
<text x="258.057739" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="26.819054" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="157.205811" y="32.979736" textLength="3.735931" font-size="8px">e</text>
<text x="124.756203" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="188.045471" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="203.459473" y="71.800003" textLength="3.735931" font-size="8px">n</text>
<text x="203.056488" y="43.299835" textLength="1.867965" font-size="8px"> </text>
<text x="301.800018" y="136.540009" textLength="4.481773" font-size="8px">V</text>
<text x="306.360413" y="136.540009" textLength="4.851335" font-size="8px">H</text>
<text x="270.959229" y="136.540009" textLength="3.735931" font-size="8px">1</text>
<text x="181.800018" y="136.540009" textLength="4.481773" font-size="8px">V</text>
<text x="298.018097" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="301.380463" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="308.045380" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="314.710297" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="316.391479" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="318.012848" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="254.278809" y="126.160004" textLength="3.735931" font-size="8px">1</text>
<text x="261.360291" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="263.041473" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="269.706390" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="189.725891" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="271.387573" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="273.068756" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="229.746063" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="231.367432" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="233.048615" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="234.729797" y="126.160004" textLength="1.867965" font-size="8px"> </text>
<text x="236.410980" y="126.160004" textLength="3.735931" font-size="8px">3</text>
<text x="240.130127" y="126.160004" textLength="3.735931" font-size="8px">2</text>
</svg>
<figcaption>Figure 5-7.  VCVTPS2PH (128-bit Version)
</figcaption></figure>
```
###                      Table 5-3. Immediate Byte Encoding for 16-bit Floating-Point Conversion Instructions


VEX.128 version: The source operand is a XMM register. The destination operand is a XMM register or 64-bit memory location. If the destination operand is a register then the upper bits (MAX_VL-1:64) of corresponding register are zeroed.

VEX.256 version: The source operand is a YMM register. The destination operand is a XMM register or 128-bit memory location. If the destination operand is a register, the upper bits (MAX_VL-1:128) of the corresponding destination register are zeroed.

Note: VEX.vvvv and EVEX.vvvv are reserved (must be 1111b).

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register. The destination operand is a YMM/XMM/XMM (low 64-bits) register or a 256/128/64-bit memory location, conditionally updated with writemask k1. Bits (MAX_VL-1:256/128/64) of the corresponding destination register are zeroed.



|**Bits**|**Field Name/value**|**Description**|**Comment**|
|--------|--------------------|---------------|-----------|
|Imm[1:0]|RC=00B|Round to nearest even|If Imm[2] = 0|
||RC=01B|Round down||
||RC=10B|Round up||
||RC=11B|Truncate||
|Imm[2]|MS1=0|Use imm[1:0] for rounding|Ignore MXCSR.RC |
||MS1=1|Use MXCSR.RC for rounding||
|Imm[7:3]|Ignored|Ignored by processor||

### Operation
#### VCVTPS2PH (EVEX encoded versions) when dest is a register
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    k <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-
                vCvt_s2h(SRC[k+31:k])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+15:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```
#### VCVTPS2PH (EVEX encoded versions) when dest is memory
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    k <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-
                vCvt_s2h(SRC[k+31:k])
          ELSE 
                *DEST[i+15:i] remains unchanged* ; merging-masking
    FI;
ENDFOR
```
#### VCVTPS2PH (VEX.256 encoded version)
```info-verb
DEST[15:0] <- vCvt_s2h(SRC1[31:0]);
DEST[31:16] <- vCvt_s2h(SRC1[63:32]);
DEST[47:32] <- vCvt_s2h(SRC1[95:64]);
DEST[63:48] <- vCvt_s2h(SRC1[127:96]);
DEST[79:64] <- vCvt_s2h(SRC1[159:128]);
DEST[95:80] <- vCvt_s2h(SRC1[191:160]);
DEST[111:96] <- vCvt_s2h(SRC1[223:192]);
DEST[127:112] <- vCvt_s2h(SRC1[255:224]);
DEST[MAX_VL-1:128] <-  0
```
#### VCVTPS2PH (VEX.128 encoded version) 
```info-verb
DEST[15:0] <- vCvt_s2h(SRC1[31:0]);
DEST[31:16] <- vCvt_s2h(SRC1[63:32]);
DEST[47:32] <- vCvt_s2h(SRC1[95:64]);
DEST[63:48] <- vCvt_s2h(SRC1[127:96]);
DEST[MAX_VL-1:64] <-  0
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTPS2PH __m256i _mm512_cvtps_ph(__m512 a);
VCVTPS2PH __m256i _mm512_mask_cvtps_ph(__m256i s, __mmask16 k,__m512 a);
VCVTPS2PH __m256i _mm512_maskz_cvtps_ph(__mmask16 k,__m512 a);
VCVTPS2PH __m256i _mm512_cvt_roundps_ph(__m512 a, const int imm);
VCVTPS2PH __m256i _mm512_mask_cvt_roundps_ph(__m256i s, __mmask16 k,__m512 a, const int imm);
VCVTPS2PH __m256i _mm512_maskz_cvt_roundps_ph(__mmask16 k,__m512 a, const int imm);
VCVTPS2PH __m128i _mm256_mask_cvtps_ph(__m128i s, __mmask8 k,__m256 a);
VCVTPS2PH __m128i _mm256_maskz_cvtps_ph(__mmask8 k,__m256 a);
VCVTPS2PH __m128i _mm_mask_cvtps_ph(__m128i s, __mmask8 k,__m128 a);
VCVTPS2PH __m128i _mm_maskz_cvtps_ph(__mmask8 k,__m128 a);
VCVTPS2PH __m128i _mm_cvtps_ph ( __m128 m1, const int imm);
VCVTPS2PH __m128i _mm256_cvtps_ph(__m256 m1, const int imm);
```
### SIMD Floating-Point Exceptions


Invalid, Underflow, Overflow, Precision, Denormal (if MXCSR.DAZ=0);

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 11 (do not report #AC); 

EVEX-encoded instructions, see Exceptions Type E11.

#UD If VEX.W=1.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

