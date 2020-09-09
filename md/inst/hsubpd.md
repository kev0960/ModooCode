----------------------------
title : HSUBPD (Intel x86/64 assembly instruction)
cat_title : HSUBPD
ref_title : HSUBPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/H
publish_date: 2020-09-01
----------------------------


#@ HSUBPD

**Packed Double-FP Horizontal Subtract**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|66 0F 7D /r\newline{}\newline{}HSUBPD xmm1, xmm2/m128|RM|V/V|SSE3|Horizontal subtract packed double-precision floating-point values from xmm2/m128 to xmm1.|
|VEX.NDS.128.66.0F.WIG 7D /r\newline{}VHSUBPD xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Horizontal subtract packed double-precision floating-point values from xmm2 and xmm3/mem.|
|VEX.NDS.256.66.0F.WIG 7D /r\newline{}VHSUBPD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Horizontal subtract packed double-precision floating-point values from ymm2 and ymm3/mem.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


The `HSUBPD` instruction subtracts horizontally the packed DP FP numbers of both operands. 

Subtracts the double-precision floating-point value in the high quadword of the destination operand from the low quadword of the destination operand and stores the result in the low quadword of the destination operand. 

Subtracts the double-precision floating-point value in the high quadword of the source operand from the low quad-word of the source operand and stores the result in the high quadword of the destination operand. 

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).

See Figure 3-20 for HSUBPD; see Figure 3-21 for VHSUBPD.

```embed
<figure>
<svg viewBox="0 0 334.619995 235.899994">
<rect x="0.000000" y="9.322021" width="334.619995" height="206.940002" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.690994" y="10.001007" width="327.997986" height="179.304993" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.690994" y="189.304993" width="327.997986" height="-179.304993" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="158.129990" y="35.146027" width="131.199005" height="26.240000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="158.129990" y="61.386993" width="131.199005" height="-26.240000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="26.931000" y="35.146027" width="131.199005" height="26.240000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="26.931000" y="61.386993" width="131.199005" height="-26.240000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="158.129990" y="82.159012" width="131.199005" height="26.240000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="158.129990" y="108.400024" width="131.199005" height="-26.240000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="26.931000" y="82.159012" width="131.199005" height="26.240000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="26.931000" y="108.400024" width="131.199005" height="-26.240000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.531006,133.998016 L92.531006,128.079010 L13.811005,128.079010 L13.811005,71.771027 L223.730026,71.771027 L223.730026,61.382019" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M95.212997,133.648010 L92.530991,139.013016 L89.847992,133.648010 L95.212997,133.648010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="26.931000" y="139.012009" width="131.199005" height="26.240000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="26.931000" y="165.253021" width="131.199005" height="-26.240000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="158.129990" y="139.012009" width="131.199005" height="26.240000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="158.129990" y="165.253021" width="131.199005" height="-26.240000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.729996,133.998016 L223.729996,119.333023 L92.530991,119.333023 L92.530991,108.400024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M226.412003,133.648010 L223.729996,139.013016 L221.047012,133.648010 L226.412003,133.648010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.531006,61.386017 L92.531006,71.775024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M223.730026,108.399017 L223.730026,119.332016" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="269.957825" y="154.465012" textLength="2.161367" font-size="8px">]</text>
<text x="261.312378" y="154.465012" textLength="4.322733" font-size="8px">6</text>
<text x="259.151001" y="154.465012" textLength="2.161367" font-size="8px">:</text>
<text x="246.182846" y="154.465012" textLength="4.322733" font-size="8px">1</text>
<text x="239.698746" y="154.465012" textLength="4.322733" font-size="8px">1</text>
<text x="226.746109" y="154.465012" textLength="6.476325" font-size="8px">m</text>
<text x="220.697372" y="154.465012" textLength="2.161367" font-size="8px"> </text>
<text x="213.785629" y="154.465012" textLength="2.161367" font-size="8px">]</text>
<text x="209.462906" y="154.465012" textLength="4.322733" font-size="8px">0</text>
<text x="202.978806" y="154.465012" textLength="4.322733" font-size="8px">3</text>
<text x="185.695663" y="154.465012" textLength="6.476325" font-size="8px">m</text>
<text x="175.331985" y="154.465012" textLength="3.887350" font-size="8px">x</text>
<text x="125.802322" y="159.129654" textLength="2.161367" font-size="8px">]</text>
<text x="121.479599" y="159.129654" textLength="4.322733" font-size="8px">4</text>
<text x="95.543198" y="159.129654" textLength="4.322733" font-size="8px">8</text>
<text x="91.220459" y="159.129654" textLength="4.322733" font-size="8px">2</text>
<text x="86.897720" y="159.129654" textLength="4.322733" font-size="8px">1</text>
<text x="60.984665" y="159.129654" textLength="6.476325" font-size="8px">m</text>
<text x="119.100555" y="149.800018" textLength="2.161367" font-size="8px">]</text>
<text x="112.616455" y="149.800018" textLength="2.161367" font-size="8px">:</text>
<text x="108.293716" y="149.800018" textLength="4.322733" font-size="8px">3</text>
<text x="103.970978" y="149.800018" textLength="4.322733" font-size="8px">6</text>
<text x="80.203720" y="149.800018" textLength="2.161367" font-size="8px">/</text>
<text x="75.880981" y="149.800018" textLength="4.322733" font-size="8px">2</text>
<text x="62.928345" y="149.800018" textLength="6.476325" font-size="8px">m</text>
<text x="304.892029" y="159.129318" textLength="6.476325" font-size="8px">m</text>
<text x="294.528381" y="149.799683" textLength="5.613334" font-size="8px">R</text>
<text x="104.414413" y="97.612015" textLength="2.161367" font-size="8px">]</text>
<text x="100.091675" y="97.612015" textLength="4.322733" font-size="8px">4</text>
<text x="93.607574" y="97.612015" textLength="2.161367" font-size="8px">:</text>
<text x="89.284836" y="97.612015" textLength="4.322733" font-size="8px">7</text>
<text x="84.962097" y="97.612015" textLength="4.322733" font-size="8px">2</text>
<text x="80.639359" y="97.612015" textLength="4.322733" font-size="8px">1</text>
<text x="78.477997" y="97.612015" textLength="2.161367" font-size="8px">[</text>
<text x="226.970200" y="97.612015" textLength="4.322733" font-size="8px">0</text>
<text x="224.808823" y="97.612015" textLength="2.161367" font-size="8px">:</text>
<text x="220.486099" y="97.612015" textLength="4.322733" font-size="8px">3</text>
<text x="235.675430" y="177.437012" textLength="2.161367" font-size="8px">]</text>
<text x="229.191330" y="177.437012" textLength="2.161367" font-size="8px">:</text>
<text x="100.101776" y="177.437012" textLength="4.322733" font-size="8px">4</text>
<text x="95.779037" y="177.437012" textLength="4.322733" font-size="8px">6</text>
<text x="89.294937" y="177.437012" textLength="4.322733" font-size="8px">7</text>
<text x="84.972198" y="177.437012" textLength="4.322733" font-size="8px">2</text>
<text x="78.488098" y="177.437012" textLength="2.161367" font-size="8px">[</text>
<text x="104.414413" y="50.598999" textLength="2.161367" font-size="8px">]</text>
<text x="95.768936" y="50.598999" textLength="4.322733" font-size="8px">6</text>
<text x="89.284836" y="50.598999" textLength="4.322733" font-size="8px">7</text>
<text x="84.962097" y="50.598999" textLength="4.322733" font-size="8px">2</text>
<text x="215.947006" y="154.465012" textLength="2.161367" font-size="8px"> </text>
<text x="121.261917" y="149.800018" textLength="2.161367" font-size="8px"> </text>
<text x="78.477997" y="50.598999" textLength="2.161367" font-size="8px">[</text>
<text x="226.970200" y="50.598999" textLength="4.322733" font-size="8px">0</text>
<text x="224.808823" y="50.598999" textLength="2.161367" font-size="8px">:</text>
<text x="220.486099" y="50.598999" textLength="4.322733" font-size="8px">3</text>
<text x="303.165039" y="55.264008" textLength="4.322733" font-size="8px">1</text>
<text x="294.527344" y="55.264008" textLength="2.161367" font-size="8px">/</text>
<text x="294.527344" y="45.934357" textLength="3.887350" font-size="8px">x</text>
<text x="311.367310" y="97.612000" textLength="4.322733" font-size="8px">1</text>
<text x="183.608047" y="26.000000" textLength="4.322733" font-size="8px">2</text>
<text x="177.131729" y="26.000000" textLength="6.476325" font-size="8px">m</text>
<text x="170.655411" y="26.000000" textLength="6.476325" font-size="8px">m</text>
<text x="166.768051" y="26.000000" textLength="3.887350" font-size="8px">x</text>
<text x="158.122574" y="26.000000" textLength="4.322733" font-size="8px">1</text>
<text x="145.169937" y="26.000000" textLength="6.476325" font-size="8px">m</text>
<text x="141.282578" y="26.000000" textLength="3.887350" font-size="8px">x</text>
<text x="128.322128" y="26.000000" textLength="5.185725" font-size="8px">P</text>
<text x="117.523056" y="26.000000" textLength="5.613334" font-size="8px">U</text>
<text x="112.337326" y="26.000000" textLength="5.185725" font-size="8px">S</text>
<text x="106.723999" y="26.000000" textLength="5.613334" font-size="8px">H</text>
<text x="326.803894" y="207.576019" textLength="3.242036" font-size="8px">5</text>
<text x="323.561829" y="207.576019" textLength="3.242036" font-size="8px">9</text>
<text x="317.077759" y="207.576019" textLength="3.242036" font-size="8px">5</text>
<text x="313.835754" y="207.576019" textLength="3.242036" font-size="8px">1</text>
<text x="308.978516" y="207.576019" textLength="4.857223" font-size="8px">M</text>
<text x="231.352707" y="177.437012" textLength="4.322733" font-size="8px">0</text>
<text x="304.890991" y="45.934357" textLength="6.476325" font-size="8px">m</text>
<text x="73.937302" y="159.129654" textLength="4.322733" font-size="8px">2</text>
<text x="231.292923" y="50.598999" textLength="2.161367" font-size="8px">]</text>
<text x="218.384506" y="177.437012" textLength="2.161367" font-size="8px">[</text>
<text x="97.486877" y="149.800018" textLength="4.322733" font-size="8px">8</text>
<text x="114.995514" y="159.129654" textLength="2.161367" font-size="8px">:</text>
<text x="216.163376" y="50.598999" textLength="4.322733" font-size="8px">6</text>
<text x="99.865936" y="159.129654" textLength="2.161367" font-size="8px">[</text>
<text x="88.841400" y="149.800018" textLength="4.322733" font-size="8px">1</text>
<text x="80.639359" y="50.598999" textLength="4.322733" font-size="8px">1</text>
<text x="200.891190" y="26.000000" textLength="4.322733" font-size="8px">2</text>
<text x="162.445297" y="26.000000" textLength="2.161367" font-size="8px">,</text>
<text x="164.606674" y="26.000000" textLength="2.161367" font-size="8px"> </text>
<text x="308.351807" y="149.799683" textLength="4.322733" font-size="8px">u</text>
<text x="93.607574" y="50.598999" textLength="2.161367" font-size="8px">:</text>
<text x="110.672775" y="159.129654" textLength="4.322733" font-size="8px">7</text>
<text x="304.464417" y="149.799683" textLength="3.887350" font-size="8px">s</text>
<text x="233.222427" y="154.465012" textLength="6.476325" font-size="8px">m</text>
<text x="123.423294" y="149.800018" textLength="2.588975" font-size="8px">-</text>
<text x="218.108383" y="154.465012" textLength="2.588975" font-size="8px">-</text>
<text x="187.930771" y="26.000000" textLength="2.161367" font-size="8px">/</text>
<text x="192.171982" y="154.465012" textLength="4.322733" font-size="8px">1</text>
<text x="102.027298" y="159.129654" textLength="4.322733" font-size="8px">1</text>
<text x="294.528381" y="159.129318" textLength="3.887350" font-size="8px">x</text>
<text x="307.487732" y="55.264008" textLength="4.322733" font-size="8px">2</text>
<text x="254.828293" y="154.465012" textLength="4.322733" font-size="8px">7</text>
<text x="207.301529" y="154.465012" textLength="2.161367" font-size="8px">:</text>
<text x="214.001999" y="50.598999" textLength="2.161367" font-size="8px">[</text>
<text x="123.136398" y="26.000000" textLength="5.185725" font-size="8px">B</text>
<text x="311.367310" y="45.934357" textLength="4.322733" font-size="8px">2</text>
<text x="250.505569" y="154.465012" textLength="4.322733" font-size="8px">2</text>
<text x="316.561890" y="149.799683" textLength="2.161367" font-size="8px">:</text>
<text x="224.868607" y="177.437012" textLength="4.322733" font-size="8px">3</text>
<text x="220.545883" y="177.437012" textLength="4.322733" font-size="8px">6</text>
<text x="101.809616" y="149.800018" textLength="2.161367" font-size="8px">[</text>
<text x="311.810486" y="55.264008" textLength="4.322733" font-size="8px">8</text>
<text x="59.041000" y="149.800018" textLength="3.887350" font-size="8px">x</text>
<text x="114.777817" y="149.800018" textLength="4.322733" font-size="8px">0</text>
<text x="222.858749" y="154.465012" textLength="3.887350" font-size="8px">x</text>
<text x="151.646255" y="26.000000" textLength="6.476325" font-size="8px">m</text>
<text x="294.527344" y="97.612000" textLength="3.887350" font-size="8px">x</text>
<text x="198.656082" y="154.465012" textLength="4.322733" font-size="8px">6</text>
<text x="69.404663" y="149.800018" textLength="6.476325" font-size="8px">m</text>
<text x="80.649460" y="177.437012" textLength="4.322733" font-size="8px">1</text>
<text x="304.890991" y="97.612000" textLength="6.476325" font-size="8px">m</text>
<text x="216.163376" y="97.612015" textLength="4.322733" font-size="8px">6</text>
<text x="179.219345" y="154.465012" textLength="6.476325" font-size="8px">m</text>
<text x="117.156876" y="159.129654" textLength="4.322733" font-size="8px">6</text>
<text x="95.768936" y="97.612015" textLength="4.322733" font-size="8px">6</text>
<text x="190.092148" y="26.000000" textLength="6.476325" font-size="8px">m</text>
<text x="304.442017" y="207.576019" textLength="4.536518" font-size="8px">O</text>
<text x="214.001999" y="97.612015" textLength="2.161367" font-size="8px">[</text>
<text x="196.494705" y="154.465012" textLength="2.161367" font-size="8px">[</text>
<text x="106.350037" y="159.129654" textLength="4.322733" font-size="8px">2</text>
<text x="82.365082" y="149.800018" textLength="6.476325" font-size="8px">m</text>
<text x="320.319824" y="207.576019" textLength="3.242036" font-size="8px">9</text>
<text x="296.688721" y="55.264008" textLength="6.476325" font-size="8px">m</text>
<text x="100.091675" y="50.598999" textLength="4.322733" font-size="8px">4</text>
<text x="80.421402" y="159.129654" textLength="6.476325" font-size="8px">m</text>
<text x="104.424515" y="177.437012" textLength="2.161367" font-size="8px">]</text>
<text x="139.121201" y="26.000000" textLength="2.161367" font-size="8px"> </text>
<text x="67.460983" y="159.129654" textLength="6.476325" font-size="8px">m</text>
<text x="298.414673" y="97.612000" textLength="6.476325" font-size="8px">m</text>
<text x="298.414673" y="45.934357" textLength="6.476325" font-size="8px">m</text>
<text x="244.021469" y="154.465012" textLength="2.161367" font-size="8px">[</text>
<text x="93.164139" y="149.800018" textLength="4.322733" font-size="8px">2</text>
<text x="205.213913" y="26.000000" textLength="4.322733" font-size="8px">8</text>
<text x="57.097321" y="159.129654" textLength="3.887350" font-size="8px">x</text>
<text x="300.141724" y="149.799683" textLength="4.322733" font-size="8px">e</text>
<text x="311.368347" y="159.129318" textLength="4.322733" font-size="8px">1</text>
<text x="231.292923" y="97.612015" textLength="2.161367" font-size="8px">]</text>
<text x="133.507858" y="26.000000" textLength="5.613334" font-size="8px">D</text>
<text x="265.635132" y="154.465012" textLength="4.322733" font-size="8px">4</text>
<text x="312.674500" y="149.799683" textLength="1.725984" font-size="8px">l</text>
<text x="78.260040" y="159.129654" textLength="2.161367" font-size="8px">/</text>
<text x="298.415710" y="159.129318" textLength="6.476325" font-size="8px">m</text>
<text x="314.400513" y="149.799683" textLength="2.161367" font-size="8px">t</text>
<text x="93.617676" y="177.437012" textLength="2.161367" font-size="8px">:</text>
<text x="196.568466" y="26.000000" textLength="4.322733" font-size="8px">1</text>
</svg>
<figcaption>Figure 3-20.  HSUBPD--Packed Double-FP Horizontal Subtract
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 317.519989 251.280029">
<rect x="20.279984" y="77.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.279984" y="77.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="77.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039978" y="90.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039978" y="77.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.499985" y="77.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.499985" y="77.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="90.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="77.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.779968" y="77.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.779968" y="77.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="90.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="77.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.059998" y="77.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.059998" y="77.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="90.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="77.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.279984" y="9.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.279984" y="9.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="9.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039978" y="23.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039978" y="9.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.499985" y="9.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.499985" y="9.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="23.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="9.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.859985,67.720032 L121.919983,67.540039 L121.979980,67.360046 L122.039978,67.120056 L122.039978,66.940002 L121.919983,66.580017 L121.619995,66.280029 L121.439972,66.220032 C121.048981 66.089050,120.924988 65.989014,120.539978 66.280029  L120.359985,66.400024 L120.239990,66.520020 L120.119995,66.700012 C119.819000 67.658020,120.614990 68.413025,121.559998 67.960022  L121.679993,67.840027 L121.859985,67.720032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.079987,67.120056 L123.599976,63.640076 L124.019989,63.160034 L124.379974,63.640076 L133.979980,75.940063 L135.059998,77.320068 L133.439972,76.720032 L118.799988,71.380066 L118.139984,71.140076 L118.559998,70.600037 L119.099976,70.420044 L133.739990,75.760071 L133.439972,76.720032 L133.199982,76.540039 L123.599976,64.240051 L124.379974,63.640076 L124.379974,64.240051 L121.859985,67.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.559998,70.600037 L121.079987,67.120056 L121.859985,67.720032 L119.339996,71.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.439972,67.420044 L123.959961,63.940063 L133.559967,76.240051 L118.919983,70.900024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M61.379990,22.480042 L60.239990,24.100037 L120.479980,67.960022 L121.619995,66.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.779968" y="9.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.779968" y="9.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="23.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="9.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.059998" y="9.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.059998" y="9.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="23.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="9.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.559998,61.000000 L283.919983,60.880005 C284.830994 60.541992,284.669983 59.187012,283.739990 59.020020  L283.559998,58.960022 L283.320007,59.020020 C282.389984 59.187012,282.229004 60.541992,283.139984 60.880005  L283.320007,60.940002 L283.559998,61.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.559998,59.980042 L288.480011,59.980042 L288.299988,60.640015 L284.040009,75.640015 L283.559998,77.320068 L283.079987,75.640015 L278.760010,60.640015 L278.579987,59.980042 L279.239990,59.980042 L279.720001,60.340027 L284.040009,75.340027 L283.079987,75.640015 L283.079987,75.340027 L287.339996,60.340027 L288.299988,60.640015 L287.820007,61.000061 L283.559998,61.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.239990" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.559998,60.460022 L287.820007,60.460022 L283.559998,75.460022 L279.239990,60.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.599976" y="23.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="60.779984" y="49.300049" width="74.220001" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="209.279968" y="49.300049" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.279984" y="40.180054" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.279984" y="39.940063" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="40.180054" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039978" y="53.440063" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039978" y="39.940063" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.499985" y="40.180054" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.499985" y="39.940063" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="40.180054" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="53.440063" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259979" y="39.940063" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.779968" y="40.180054" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.779968" y="39.940063" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="40.180054" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="53.440063" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539978" y="39.940063" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.059998" y="40.180054" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.059998" y="39.940063" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="40.180054" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="53.440063" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819977" y="39.940063" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.179993,67.960022 L270.239990,67.780029 L270.299988,67.600037 C270.427002 66.591003,269.386993 65.991028,268.619995 66.700012  L268.500000,66.820007 L268.380005,67.179993 L268.320007,67.420044 L268.320007,67.600037 L268.380005,67.780029 L268.500000,67.960022 L268.739990,68.200012 L268.919983,68.320007 L269.100006,68.380005 L269.519989,68.380005 L269.880005,68.260010 L270.179993,67.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M269.339996,67.420044 L271.799988,63.880066 L272.220001,63.340027 L272.639984,63.880066 L282.480011,75.940063 L283.559998,77.320068 L281.940002,76.720032 L267.179993,71.680054 L266.519989,71.440063 L266.880005,70.900024 L267.480011,70.720032 L282.239990,75.760071 L281.940002,76.720032 L281.699982,76.540039 L271.859985,64.480042 L272.639984,63.880066 L272.639984,64.480042 L270.179993,68.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M266.879974,70.900024 L269.339966,67.420044 L270.179962,68.020020 L267.719971,71.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M269.759979,67.720032 L272.219971,64.180054 L282.059967,76.240051 L267.299988,71.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.519989,22.480042 L205.379974,24.100037 L268.799988,68.260010 L269.940002,66.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.999969,61.000000 L135.239960,60.940002 L135.419983,60.880005 C136.330963 60.541992,136.169983 59.187012,135.239960 59.020020  L134.999969,58.960022 L134.819977,59.020020 C133.889984 59.187012,133.728973 60.541992,134.639984 60.880005  L134.999969,61.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.999969,59.980042 L139.979980,59.980042 L139.799957,60.640015 L135.479980,75.640015 L134.999969,77.320068 L134.519958,75.640015 L130.259979,60.640015 L130.079956,59.980042 L130.739960,59.980042 L131.219971,60.340027 L135.479980,75.340027 L134.519958,75.640015 L134.519958,75.340027 L138.839966,60.340027 L139.799957,60.640015 L139.319977,61.000061 L134.999969,61.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.739990" y="59.979980" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.999969,60.460022 L139.319977,60.460022 L134.999969,75.460022 L130.739960,60.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.039978" y="23.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.419983,61.000000 L57.779984,60.880005 C58.690979 60.541992,58.529984 59.187012,57.599976 59.020020  L57.419983,58.960022 L57.179977,59.020020 C56.249985 59.187012,56.088989 60.541992,56.999985 60.880005  L57.179977,60.940002 L57.419983,61.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.419983,59.980042 L62.339981,59.980042 L62.159988,60.640015 L57.899979,75.640015 L57.419983,77.320068 L56.939987,75.640015 L52.619980,60.640015 L52.439987,59.980042 L53.099976,59.980042 L53.579987,60.340027 L57.899979,75.340027 L56.939987,75.640015 L56.939987,75.340027 L61.199982,60.340027 L62.159988,60.640015 L61.679977,61.000061 L57.419983,61.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.099976" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.419983,60.460022 L61.679977,60.460022 L57.419983,75.460022 L53.099976,60.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.459976" y="53.680054" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.919983,61.000000 L206.459991,60.820007 L206.639984,60.700012 L206.759979,60.520020 L206.819977,60.400024 L206.879974,60.159973 L206.879974,59.799988 C206.745972 59.411011,206.750977 59.203979,206.279968 59.080017  L205.919983,58.960022 L205.679993,59.020020 C204.749969 59.187012,204.588989 60.541992,205.499969 60.880005  L205.679993,60.940002 L205.919983,61.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.919983,59.980042 L210.839996,59.980042 L210.659973,60.640015 L206.399994,75.640015 L205.919983,77.320068 L205.439972,75.640015 L201.119995,60.640015 L200.939972,59.980042 L201.599976,59.980042 L202.079987,60.340027 L206.399994,75.340027 L205.439972,75.640015 L205.439972,75.340027 L209.699982,60.340027 L210.659973,60.640015 L210.179993,61.000061 L205.919983,61.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.599976" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.919983,60.460022 L210.179993,60.460022 L205.919983,75.460022 L201.599976,60.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.959991" y="53.680054" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.839981,72.160034 L72.959976,72.340027 L73.079987,72.460022 C73.848984 73.248047,74.843979 72.645020,74.819977 71.680054  L74.699982,71.320007 C74.242981 70.471008,72.826981 70.767029,72.839981 71.740051  L72.839981,72.160034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.799988,71.800049 L75.179993,75.880066 L75.299988,76.540039 L74.699982,76.600037 L59.099991,77.260071 L57.359985,77.320068 L58.799988,76.300049 L71.699982,67.480042 L72.239990,67.120056 L72.479980,67.720032 L72.239990,68.320068 L59.339981,77.140076 L58.799988,76.300049 L59.039993,76.240051 L74.639984,75.580078 L74.699982,76.600037 L74.159988,76.240051 L72.779984,72.160034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.479980,67.720032 L73.799988,71.800049 L72.779984,72.160034 L71.459976,68.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.319977,71.980042 L74.699982,76.060059 L59.099976,76.720032 L71.999969,67.900024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M128.579987,54.640015 L127.979980,52.780029 L73.499985,70.900024 L74.099991,72.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.639984,71.920044 L224.759979,72.100037 L224.879974,72.220032 C225.480988 73.003052,226.711975 72.393066,226.619995 71.440063  L226.559998,71.260071 L226.499969,71.080017 C226.020996 70.253052,224.634979 70.514038,224.639984 71.500061  L224.639984,71.920044" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.599976,71.560059 L227.039978,75.640076 L227.159973,76.300049 L226.559967,76.360046 L211.019989,77.200073 L209.279968,77.260071 L210.719971,76.240051 L223.439972,67.240051 L223.979980,66.880066 L224.219971,67.480042 L224.039978,68.080078 L211.319977,77.080078 L210.719971,76.240051 L210.959961,76.180054 L226.499969,75.340088 L226.559967,76.360046 L226.079987,76.000061 L224.639984,71.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.219971,67.480042 L225.599976,71.560059 L224.639984,71.920044 L223.199982,67.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.119995,71.740051 L226.559998,75.820068 L211.019989,76.660034 L223.739990,67.660034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.139984,54.640015 L276.479980,52.780029 L225.299988,70.660034 L225.959991,72.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="278.879974" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="61.079971" y="48.640015" textLength="4.170000" font-size="8px">3</text>
<text x="56.099976" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="278.879974" y="18.280029" textLength="5.002500" font-size="8px">X</text>
<text x="10.738464" y="19.960022" textLength="5.415000" font-size="8px">C</text>
<text x="5.339966" y="19.960022" textLength="5.415000" font-size="8px">R</text>
<text x="135.419983" y="18.280029" textLength="4.170000" font-size="8px">2</text>
<text x="130.379974" y="18.280029" textLength="5.002500" font-size="8px">X</text>
<text x="61.079971" y="18.280029" textLength="4.170000" font-size="8px">3</text>
<text x="56.099976" y="18.280029" textLength="5.002500" font-size="8px">X</text>
<text x="5.395493" y="85.840027" textLength="5.002500" font-size="8px">E</text>
<text x="282.476959" y="85.840027" textLength="5.002500" font-size="8px">X</text>
<text x="280.375458" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="271.615479" y="85.840027" textLength="4.170000" font-size="8px">0</text>
<text x="206.153229" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="203.693237" y="85.840027" textLength="2.497500" font-size="8px">-</text>
<text x="197.453247" y="85.840027" textLength="4.170000" font-size="8px">0</text>
<text x="192.419983" y="85.840027" textLength="5.002500" font-size="8px">Y</text>
<text x="133.976959" y="85.840027" textLength="5.002500" font-size="8px">X</text>
<text x="131.875458" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="123.115479" y="85.840027" textLength="4.170000" font-size="8px">2</text>
<text x="118.139984" y="85.840027" textLength="5.002500" font-size="8px">X</text>
<text x="59.754745" y="85.840027" textLength="5.002500" font-size="8px">Y</text>
<text x="55.193237" y="85.840027" textLength="2.497500" font-size="8px">-</text>
<text x="48.953232" y="85.840027" textLength="4.170000" font-size="8px">2</text>
<text x="43.919983" y="85.840027" textLength="5.002500" font-size="8px">Y</text>
<text x="130.379974" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="4.983002" y="50.320007" textLength="5.415000" font-size="8px">R</text>
<text x="209.579987" y="18.280029" textLength="4.170000" font-size="8px">1</text>
<text x="204.599976" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="277.855469" y="85.840027" textLength="2.497500" font-size="8px">-</text>
<text x="15.836990" y="50.320007" textLength="4.170000" font-size="8px">2</text>
<text x="129.355469" y="85.840027" textLength="2.497500" font-size="8px">-</text>
<text x="208.254730" y="85.840027" textLength="5.002500" font-size="8px">Y</text>
<text x="283.859985" y="18.280029" textLength="4.170000" font-size="8px">0</text>
<text x="135.419983" y="48.640015" textLength="4.170000" font-size="8px">2</text>
<text x="10.378494" y="85.840027" textLength="5.002500" font-size="8px">S</text>
<text x="127.313965" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="53.091736" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="213.234741" y="85.840027" textLength="4.170000" font-size="8px">1</text>
<text x="201.591736" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="283.859985" y="48.640015" textLength="4.170000" font-size="8px">0</text>
<text x="64.734741" y="85.840027" textLength="4.170000" font-size="8px">3</text>
<text x="57.653244" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="10.378494" y="50.320007" textLength="5.415000" font-size="8px">C</text>
<text x="209.579987" y="48.640015" textLength="4.170000" font-size="8px">1</text>
<text x="287.452454" y="85.840027" textLength="4.170000" font-size="8px">1</text>
<text x="15.418488" y="85.840027" textLength="4.582500" font-size="8px">T</text>
<text x="266.639984" y="85.840027" textLength="5.002500" font-size="8px">X</text>
<text x="138.952454" y="85.840027" textLength="4.170000" font-size="8px">3</text>
<text x="0.299973" y="19.960022" textLength="5.002500" font-size="8px">S</text>
<text x="275.813965" y="85.840027" textLength="2.085000" font-size="8px"> </text>
<text x="16.136963" y="19.960022" textLength="4.170000" font-size="8px">1</text>
<text x="0.000000" y="50.320007" textLength="5.002500" font-size="8px">S</text>
<text x="204.599976" y="18.280029" textLength="5.002500" font-size="8px">X</text>
<text x="0.000000" y="85.840027" textLength="5.415000" font-size="8px">D</text>
</svg>
<figcaption>Figure 3-21.  VHSUBPD operation
</figcaption></figure>
```


128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### HSUBPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC1[127:64] 
DEST[127:64] <-  SRC2[63:0] - SRC2[127:64] 
DEST[VLMAX-1:128] (Unmodified)
```
#### VHSUBPD (VEX.128 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC1[127:64] 
DEST[127:64] <-  SRC2[63:0] - SRC2[127:64] 
DEST[VLMAX-1:128] <-  0
```
#### VHSUBPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC1[127:64] 
DEST[127:64] <-  SRC2[63:0] - SRC2[127:64] 
DEST[191:128] <-  SRC1[191:128] - SRC1[255:192]
DEST[255:192] <-  SRC2[191:128] - SRC2[255:192]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
HSUBPD: __m128d _mm_hsub_pd(__m128d a, __m128d b)
VHSUBPD: __m256d _mm256_hsub_pd (__m256d a, __m256d b);
```
### Exceptions


When the source operand is a memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated.

### Numeric Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


See Exceptions Type 2.

