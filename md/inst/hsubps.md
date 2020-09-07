----------------------------
title : HSUBPS (Intel x86/64 assembly instruction)
cat_title : HSUBPS
ref_title : HSUBPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/H
publish_date: 2020-09-01
----------------------------
#@ HSUBPS

**Packed Single-FP Horizontal Subtract**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|F2 0F 7D /r\newline{}\newline{}HSUBPS xmm1, xmm2/m128|RM|V/V|SSE3|Horizontal subtract packed single-precision floating-point values from xmm2/m128 to xmm1.|
|VEX.NDS.128.F2.0F.WIG 7D /r\newline{}\newline{}VHSUBPS xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Horizontal subtract packed single-precision floating-point values from xmm2 and xmm3/mem.|
|VEX.NDS.256.F2.0F.WIG 7D /r\newline{}VHSUBPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Horizontal subtract packed single-precision floating-point values from ymm2 and ymm3/mem.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Subtracts the single-precision floating-point value in the second dword of the destination operand from the first dword of the destination operand and stores the result in the first dword of the destination operand. 

Subtracts the single-precision floating-point value in the fourth dword of the destination operand from the third dword of the destination operand and stores the result in the second dword of the destination operand. 

Subtracts the single-precision floating-point value in the second dword of the source operand from the first dword of the source operand and stores the result in the third dword of the destination operand. 

Subtracts the single-precision floating-point value in the fourth dword of the source operand from the third dword of the source operand and stores the result in the fourth dword of the destination operand. 

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).

See Figure 3-22 for HSUBPS; see Figure 3-23 for VHSUBPS.

```embed
<figure>
<svg viewBox="0 0 372.059998 362.399994">
<rect x="0.000000" y="9.276978" width="372.059998" height="239.699997" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="5.351997" y="10.000000" width="361.139008" height="216.009003" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="5.351997" y="226.009003" width="361.139008" height="-216.009003" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.987000" y="154.768982" width="67.502998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="244.987000" y="201.920990" width="67.502998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.987000" y="37.000977" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="244.987000" y="64.001953" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.484009" y="154.768982" width="67.502998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="177.484009" y="201.920990" width="67.502998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.484009" y="37.000977" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="177.484009" y="64.001953" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.987000" y="96.398010" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="244.987000" y="123.398926" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.484009" y="96.398010" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="177.484009" y="123.398926" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.981995" y="154.768982" width="67.502998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="109.981995" y="201.920990" width="67.502998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.981995" y="37.000977" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="109.981995" y="64.001953" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="41.354004" y="154.768982" width="68.627998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="41.354004" y="201.920990" width="68.627998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="41.354004" y="37.000977" width="68.627998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="41.354004" y="64.001953" width="68.627998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.981995" y="96.398010" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="109.981995" y="123.398926" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="41.354004" y="96.398010" width="68.627998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="41.354004" y="123.398926" width="68.627998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.235992,123.398987 L211.235992,131.508972 L278.738983,131.508972 L278.738983,150.690002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M280.777985,150.690002 L278.737976,154.770020 L276.697998,150.690002 L280.777985,150.690002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M278.738007,133.623962 L278.738007,123.403992" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M76.230011,123.398987 L76.230011,136.010010 L211.235016,136.010010 L211.235016,150.690002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M213.276001,150.690002 L211.235992,154.770020 L209.196014,150.690002 L213.276001,150.690002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M143.733002,136.005005 L143.733002,123.395020" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M143.733002,64.002014 L143.733002,75.252014 L19.977997,75.252014 L19.977997,145.005005 L76.230011,145.005005 L76.230011,150.825012" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M78.270004,150.825989 L76.230011,154.906006 L74.190002,150.825989 L78.270004,150.825989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.235992,64.001953 L211.235992,85.382935" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M278.738983,64.001953 L278.738983,85.372925 L31.228989,85.372925 L31.228989,140.504944 L143.733978,140.504944 L143.733978,150.824951" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M145.773010,150.825989 L143.733002,154.906006 L141.693024,150.825989 L145.773010,150.825989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M75.666992,64.001953 L75.666992,75.251953" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="294.169250" y="175.949951" textLength="2.021894" font-size="8px">]</text>
<text x="201.154236" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="207.818481" y="27.587952" textLength="4.448167" font-size="8px">1</text>
<text x="63.449081" y="112.297974" textLength="4.448167" font-size="8px">1</text>
<text x="72.345413" y="52.901978" textLength="4.448167" font-size="8px">7</text>
<text x="330.077454" y="175.769531" textLength="5.336200" font-size="8px">S</text>
<text x="79.572891" y="214.958466" textLength="4.448167" font-size="8px">9</text>
<text x="199.005005" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="161.592712" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="222.885376" y="185.550293" textLength="2.021894" font-size="8px">:</text>
<text x="92.259003" y="171.149963" textLength="4.043788" font-size="8px">8</text>
<text x="84.021057" y="214.958466" textLength="4.448167" font-size="8px">6</text>
<text x="172.705139" y="27.587952" textLength="2.224083" font-size="8px">,</text>
<text x="330.077454" y="57.701843" textLength="4.448167" font-size="8px">2</text>
<text x="143.882568" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="298.213013" y="175.949951" textLength="2.421909" font-size="8px">-</text>
<text x="148.417267" y="190.350677" textLength="4.043788" font-size="8px">3</text>
<text x="232.794800" y="175.949951" textLength="2.421909" font-size="8px">-</text>
<text x="78.379196" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="149.294708" y="52.901978" textLength="4.448167" font-size="8px">4</text>
<text x="286.520721" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="325.629272" y="57.701843" textLength="4.448167" font-size="8px">1</text>
<text x="336.293671" y="48.101501" textLength="4.448167" font-size="8px">2</text>
<text x="96.576263" y="190.350677" textLength="2.021894" font-size="8px">]</text>
<text x="212.349548" y="52.901978" textLength="4.448167" font-size="8px">3</text>
<text x="154.482941" y="190.350677" textLength="4.043788" font-size="8px">3</text>
<text x="60.182129" y="190.350677" textLength="4.043788" font-size="8px">1</text>
<text x="138.307800" y="190.350677" textLength="4.043788" font-size="8px">8</text>
<text x="208.732117" y="185.550293" textLength="2.021894" font-size="8px">[</text>
<text x="188.934998" y="185.550293" textLength="3.636500" font-size="8px">x</text>
<text x="155.599365" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="300.634918" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="360.669342" y="240.059967" textLength="3.336056" font-size="8px">9</text>
<text x="88.215210" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="216.755341" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="138.185501" y="214.958466" textLength="4.448167" font-size="8px">5</text>
<text x="73.444473" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="165.701569" y="180.750305" textLength="2.021894" font-size="8px">/</text>
<text x="144.846527" y="52.901978" textLength="4.448167" font-size="8px">6</text>
<text x="273.950317" y="175.949951" textLength="4.043788" font-size="8px">1</text>
<text x="124.371994" y="171.149963" textLength="3.636500" font-size="8px">x</text>
<text x="201.229095" y="52.901978" textLength="4.448167" font-size="8px">6</text>
<text x="138.031815" y="27.587952" textLength="5.336200" font-size="8px">P</text>
<text x="87.914001" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="214.797791" y="185.550293" textLength="4.043788" font-size="8px">2</text>
<text x="162.570526" y="190.350677" textLength="2.021894" font-size="8px">]</text>
<text x="181.153473" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="153.754120" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="87.914001" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="153.742889" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="152.461060" y="190.350677" textLength="2.021894" font-size="8px">:</text>
<text x="216.797729" y="112.297974" textLength="4.448167" font-size="8px">2</text>
<text x="76.793579" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="76.091110" y="171.149963" textLength="2.021894" font-size="8px">/</text>
<text x="64.225922" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="235.216705" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="212.307159" y="214.958466" textLength="4.448167" font-size="8px">2</text>
<text x="322.964874" y="112.297791" textLength="6.664250" font-size="8px">m</text>
<text x="131.501999" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="148.704224" y="27.587952" textLength="2.224083" font-size="8px"> </text>
<text x="144.373474" y="190.350677" textLength="4.043788" font-size="8px">6</text>
<text x="158.526733" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="144.857758" y="214.958466" textLength="4.448167" font-size="8px">6</text>
<text x="79.017670" y="52.901978" textLength="4.448167" font-size="8px">9</text>
<text x="199.005005" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="133.726089" y="52.901978" textLength="4.448167" font-size="8px">9</text>
<text x="290.315277" y="185.550293" textLength="4.043788" font-size="8px">3</text>
<text x="284.357910" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="261.833496" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="205.677277" y="112.297974" textLength="4.448167" font-size="8px">3</text>
<text x="160.336975" y="171.149963" textLength="4.043788" font-size="8px">8</text>
<text x="79.910172" y="180.750305" textLength="3.636500" font-size="8px">x</text>
<text x="140.125320" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="142.622437" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="201.229095" y="112.297974" textLength="4.448167" font-size="8px">6</text>
<text x="353.997223" y="240.059967" textLength="3.336056" font-size="8px">5</text>
<text x="99.707291" y="180.750305" textLength="2.021894" font-size="8px">/</text>
<text x="216.797729" y="52.901978" textLength="4.448167" font-size="8px">2</text>
<text x="133.726089" y="112.297974" textLength="4.448167" font-size="8px">9</text>
<text x="275.461548" y="214.958466" textLength="4.448167" font-size="8px">3</text>
<text x="218.841583" y="185.550293" textLength="4.043788" font-size="8px">7</text>
<text x="205.634888" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="76.793579" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="92.532471" y="190.350677" textLength="4.043788" font-size="8px">6</text>
<text x="61.224991" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="61.780212" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="270.952087" y="52.901978" textLength="4.448167" font-size="8px">3</text>
<text x="137.416870" y="180.750305" textLength="2.021894" font-size="8px">]</text>
<text x="221.245911" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="59.930496" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="296.191132" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="340.741852" y="48.101501" textLength="2.224083" font-size="8px">/</text>
<text x="324.741241" y="175.769531" textLength="5.336200" font-size="8px">E</text>
<text x="340.994995" y="240.059967" textLength="4.668078" font-size="8px">O</text>
<text x="139.438766" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="56.293991" y="171.149963" textLength="3.636500" font-size="8px">x</text>
<text x="121.583206" y="27.587952" textLength="5.336200" font-size="8px">S</text>
<text x="68.269714" y="190.350677" textLength="4.043788" font-size="8px">8</text>
<text x="86.466782" y="190.350677" textLength="2.021894" font-size="8px">:</text>
<text x="57.269302" y="180.750305" textLength="4.043788" font-size="8px">5</text>
<text x="210.125458" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="115.806992" y="27.587952" textLength="5.776217" font-size="8px">H</text>
<text x="149.294708" y="112.297974" textLength="4.448167" font-size="8px">4</text>
<text x="134.066910" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="318.965027" y="185.369873" textLength="4.000150" font-size="8px">x</text>
<text x="336.293671" y="185.369873" textLength="4.448167" font-size="8px">1</text>
<text x="161.657776" y="180.750305" textLength="4.043788" font-size="8px">2</text>
<text x="67.897247" y="112.297974" textLength="4.448167" font-size="8px">2</text>
<text x="88.488678" y="190.350677" textLength="4.043788" font-size="8px">9</text>
<text x="318.965027" y="57.701843" textLength="6.664250" font-size="8px">m</text>
<text x="280.205811" y="185.550293" textLength="4.043788" font-size="8px">6</text>
<text x="156.293182" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="232.994843" y="185.550293" textLength="2.021894" font-size="8px">]</text>
<text x="188.734985" y="175.949951" textLength="3.636500" font-size="8px">x</text>
<text x="53.225510" y="180.750305" textLength="4.043788" font-size="8px">9</text>
<text x="284.249603" y="185.550293" textLength="4.043788" font-size="8px">3</text>
<text x="95.663498" y="180.750305" textLength="4.043788" font-size="8px">2</text>
<text x="279.848450" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="77.348801" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="141.460663" y="180.750305" textLength="2.421909" font-size="8px">-</text>
<text x="187.817719" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="288.293396" y="185.550293" textLength="2.021894" font-size="8px">:</text>
<text x="198.930145" y="27.587952" textLength="2.224083" font-size="8px">/</text>
<text x="230.772919" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="345.663086" y="240.059967" textLength="4.998084" font-size="8px">M</text>
<text x="350.661163" y="240.059967" textLength="3.336056" font-size="8px">1</text>
<text x="357.333282" y="240.059967" textLength="3.336056" font-size="8px">9</text>
<text x="364.005402" y="240.059967" textLength="3.336056" font-size="8px">6</text>
<text x="126.919403" y="27.587952" textLength="5.776217" font-size="8px">U</text>
<text x="132.695618" y="27.587952" textLength="5.336200" font-size="8px">B</text>
<text x="144.846527" y="112.297974" textLength="4.448167" font-size="8px">6</text>
<text x="150.928314" y="27.587952" textLength="4.000150" font-size="8px">x</text>
<text x="329.629120" y="112.297791" textLength="6.664250" font-size="8px">m</text>
<text x="154.928467" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="168.256958" y="27.587952" textLength="4.448167" font-size="8px">1</text>
<text x="177.153320" y="27.587952" textLength="4.000150" font-size="8px">x</text>
<text x="194.481964" y="27.587952" textLength="4.448167" font-size="8px">2</text>
<text x="212.266663" y="27.587952" textLength="4.448167" font-size="8px">2</text>
<text x="216.714844" y="27.587952" textLength="4.448167" font-size="8px">8</text>
<text x="318.965027" y="175.769531" textLength="5.776217" font-size="8px">R</text>
<text x="341.189880" y="175.769531" textLength="4.448167" font-size="8px">L</text>
<text x="345.046021" y="175.769531" textLength="4.888184" font-size="8px">T</text>
<text x="349.046173" y="175.769531" textLength="2.224083" font-size="8px">:</text>
<text x="322.965179" y="185.369873" textLength="6.664250" font-size="8px">m</text>
<text x="128.008499" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="329.629425" y="185.369873" textLength="6.664250" font-size="8px">m</text>
<text x="318.965027" y="48.101501" textLength="4.000150" font-size="8px">x</text>
<text x="322.965179" y="48.101501" textLength="6.664250" font-size="8px">m</text>
<text x="144.169098" y="171.149963" textLength="2.021894" font-size="8px">/</text>
<text x="329.629425" y="48.101501" textLength="6.664250" font-size="8px">m</text>
<text x="334.525635" y="57.701843" textLength="4.448167" font-size="8px">8</text>
<text x="258.196991" y="175.949951" textLength="3.636500" font-size="8px">x</text>
<text x="267.891907" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="133.373077" y="180.750305" textLength="4.043788" font-size="8px">0</text>
<text x="143.368011" y="27.587952" textLength="5.336200" font-size="8px">S</text>
<text x="277.994110" y="175.949951" textLength="2.021894" font-size="8px">[</text>
<text x="280.015991" y="175.949951" textLength="4.043788" font-size="8px">3</text>
<text x="284.059784" y="175.949951" textLength="4.043788" font-size="8px">1</text>
<text x="288.103577" y="175.949951" textLength="2.021894" font-size="8px">:</text>
<text x="290.125458" y="175.949951" textLength="4.043788" font-size="8px">0</text>
<text x="221.245911" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="262.023315" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="142.633667" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="268.081726" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="274.140137" y="185.550293" textLength="4.043788" font-size="8px">1</text>
<text x="278.183929" y="185.550293" textLength="2.021894" font-size="8px">[</text>
<text x="294.359070" y="185.550293" textLength="4.043788" font-size="8px">2</text>
<text x="153.742889" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="298.402863" y="185.550293" textLength="2.021894" font-size="8px">]</text>
<text x="268.727997" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="68.452469" y="214.958466" textLength="4.448167" font-size="8px">2</text>
<text x="275.400269" y="52.901978" textLength="4.448167" font-size="8px">1</text>
<text x="282.072540" y="52.901978" textLength="4.448167" font-size="8px">0</text>
<text x="192.371490" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="198.429901" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="204.488312" y="175.949951" textLength="4.043788" font-size="8px">1</text>
<text x="208.532104" y="175.949951" textLength="2.021894" font-size="8px">[</text>
<text x="131.501999" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="210.553986" y="175.949951" textLength="4.043788" font-size="8px">9</text>
<text x="214.597778" y="175.949951" textLength="4.043788" font-size="8px">5</text>
<text x="88.469223" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="218.641571" y="175.949951" textLength="2.021894" font-size="8px">:</text>
<text x="61.224991" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="220.663452" y="175.949951" textLength="4.043788" font-size="8px">6</text>
<text x="224.707245" y="175.949951" textLength="4.043788" font-size="8px">4</text>
<text x="228.751038" y="175.949951" textLength="2.021894" font-size="8px">]</text>
<text x="192.571503" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="258.386810" y="185.550293" textLength="3.636500" font-size="8px">x</text>
<text x="198.629913" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="204.688324" y="185.550293" textLength="4.043788" font-size="8px">1</text>
<text x="224.907257" y="185.550293" textLength="4.043788" font-size="8px">9</text>
<text x="149.305939" y="214.958466" textLength="4.448167" font-size="8px">4</text>
<text x="335.413666" y="175.769531" textLength="5.776217" font-size="8px">U</text>
<text x="228.951050" y="185.550293" textLength="4.043788" font-size="8px">6</text>
<text x="205.677277" y="52.901978" textLength="4.448167" font-size="8px">3</text>
<text x="210.125458" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="196.738525" y="214.958466" textLength="4.448167" font-size="8px">6</text>
<text x="201.186707" y="214.958466" textLength="4.448167" font-size="8px">3</text>
<text x="210.753998" y="185.550293" textLength="4.043788" font-size="8px">1</text>
<text x="207.858978" y="214.958466" textLength="4.448167" font-size="8px">3</text>
<text x="273.237457" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="174.929230" y="27.587952" textLength="2.224083" font-size="8px"> </text>
<text x="279.909729" y="214.958466" textLength="4.448167" font-size="8px">1</text>
<text x="286.582001" y="214.958466" textLength="4.448167" font-size="8px">0</text>
<text x="291.030182" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="318.964722" y="112.297791" textLength="4.000150" font-size="8px">x</text>
<text x="336.293365" y="112.297791" textLength="4.448167" font-size="8px">1</text>
<text x="268.727997" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="270.952087" y="112.297974" textLength="4.448167" font-size="8px">3</text>
<text x="275.400269" y="112.297974" textLength="4.448167" font-size="8px">1</text>
<text x="282.072540" y="112.297974" textLength="4.448167" font-size="8px">0</text>
<text x="286.520721" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="212.349548" y="112.297974" textLength="4.448167" font-size="8px">3</text>
<text x="146.190979" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="152.249390" y="171.149963" textLength="4.043788" font-size="8px">1</text>
<text x="123.263596" y="180.750305" textLength="4.043788" font-size="8px">3</text>
<text x="121.241699" y="180.750305" textLength="2.021894" font-size="8px">[</text>
<text x="127.307388" y="180.750305" textLength="4.043788" font-size="8px">1</text>
<text x="279.848450" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="131.351181" y="180.750305" textLength="2.021894" font-size="8px">:</text>
<text x="145.904449" y="180.750305" textLength="3.636500" font-size="8px">x</text>
<text x="149.540955" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="124.161804" y="190.350677" textLength="6.058409" font-size="8px">m</text>
<text x="130.220215" y="190.350677" textLength="4.043788" font-size="8px">1</text>
<text x="134.264008" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="194.514435" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="83.465836" y="112.297974" textLength="4.448167" font-size="8px">6</text>
<text x="142.351593" y="190.350677" textLength="2.021894" font-size="8px">[</text>
<text x="138.174255" y="52.901978" textLength="4.448167" font-size="8px">5</text>
<text x="65.988907" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="72.047318" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="78.113007" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="84.171417" y="171.149963" textLength="4.043788" font-size="8px">1</text>
<text x="51.203613" y="180.750305" textLength="2.021894" font-size="8px">[</text>
<text x="61.313095" y="180.750305" textLength="2.021894" font-size="8px">:</text>
<text x="63.334991" y="180.750305" textLength="4.043788" font-size="8px">6</text>
<text x="67.378784" y="180.750305" textLength="4.043788" font-size="8px">4</text>
<text x="71.422577" y="180.750305" textLength="2.021894" font-size="8px">]</text>
<text x="75.466370" y="180.750305" textLength="2.421909" font-size="8px">-</text>
<text x="77.888275" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="83.546677" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="89.605087" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="54.123718" y="190.350677" textLength="6.058409" font-size="8px">m</text>
<text x="72.313507" y="190.350677" textLength="2.021894" font-size="8px">[</text>
<text x="74.335403" y="190.350677" textLength="4.043788" font-size="8px">1</text>
<text x="82.422989" y="190.350677" textLength="4.043788" font-size="8px">7</text>
<text x="63.449081" y="52.901978" textLength="4.448167" font-size="8px">1</text>
<text x="64.004303" y="214.958466" textLength="4.448167" font-size="8px">1</text>
<text x="67.897247" y="52.901978" textLength="4.448167" font-size="8px">2</text>
<text x="83.465836" y="52.901978" textLength="4.448167" font-size="8px">6</text>
<text x="72.900635" y="214.958466" textLength="4.448167" font-size="8px">7</text>
<text x="131.513245" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="133.737335" y="214.958466" textLength="4.448167" font-size="8px">9</text>
<text x="138.174255" y="112.297974" textLength="4.448167" font-size="8px">5</text>
<text x="142.622437" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="72.345413" y="112.297974" textLength="4.448167" font-size="8px">7</text>
<text x="79.017670" y="112.297974" textLength="4.448167" font-size="8px">9</text>
</svg>
<figcaption>Figure 3-22.  HSUBPS--Packed Single-FP Horizontal Subtract
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 317.520020 202.000000">
<path d="M105.539993,64.059998 L105.779984,63.820007 C106.382980 63.039001,105.507004 61.960999,104.580002 62.320007  L104.219986,62.559998 C103.629990 63.268005,104.128983 64.420990,105.180008 64.239990  L105.360001,64.179993 L105.539993,64.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M104.940018,63.220001 L108.480026,60.820007 L109.080032,60.459991 L109.260025,61.119995 L114.240005,75.880005 L114.840012,77.559998 L113.460007,76.420013 L101.400009,66.519989 L100.860031,66.100006 L101.400009,65.679993 L102.000015,65.739990 L114.060013,75.640015 L113.460007,76.420013 L113.280014,76.179993 L108.300003,61.420013 L109.260025,61.119995 L109.080032,61.660004 L105.540024,64.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.400009,65.679993 L104.940018,63.220001 L105.540024,64.059998 L102.000015,66.519989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M105.240005,63.639984 L108.780014,61.239990 L113.759995,75.999969 L101.699997,66.099976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M78.480011,22.959991 L76.860016,24.100006 L104.160019,63.880005 L105.780014,62.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.580002,67.899994 L101.699997,67.720001 L101.759995,67.540009 C101.888016 66.527985,100.876999 65.981995,100.080002 66.579987  L99.840012,66.940002 C99.522995 67.868988,100.387009 68.643982,101.280014 68.199982  L101.460007,68.079987 L101.580002,67.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.800003,67.299988 L103.319992,63.879974 L103.680008,63.339996 L104.099991,63.879974 L113.699997,76.119995 L114.780014,77.500000 L113.159988,76.899994 L98.520004,71.559998 L97.860001,71.319977 L98.279999,70.779999 L98.819992,70.599976 L113.460007,75.940002 L113.159988,76.899994 L112.919998,76.720001 L103.319992,64.479980 L104.099991,63.879974 L104.099991,64.479980 L101.580002,67.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M98.280014,70.779999 L100.800003,67.299988 L101.580002,67.899994 L99.060013,71.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.160019,67.599976 L103.680008,64.179962 L113.280014,76.419983 L98.640015,71.079987" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M41.100006,22.720001 L39.960007,24.339996 L100.259995,68.200012 L101.400009,66.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.900009,67.599976 L247.020004,67.479980 L247.080002,67.299988 C247.397018 66.293976,246.248001 65.655975,245.460007 66.279968  L245.340012,66.399963 L245.220016,66.579987 C244.849014 67.509979,245.759018 68.359985,246.660019 67.899963  L246.780014,67.779968 L246.900009,67.599976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.180008,67.000000 L248.759995,63.579987 L249.180008,63.100006 L249.539993,63.579987 L258.900024,76.119995 L259.979980,77.559998 L243.780014,71.200012 L243.120010,70.959991 L243.539993,70.420013 L244.080002,70.239990 L258.660034,75.940002 L258.299988,76.899994 L258.059998,76.720001 L248.759995,64.179993 L249.539993,63.579987 L249.539993,64.179993 L246.960007,67.600006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M243.539993,70.419983 L246.180008,66.999969 L246.960007,67.599976 L244.319992,71.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.539993,67.299988 L249.119980,63.879974 L258.479980,76.419983 L243.899979,70.720001" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.600021,22.720001 L188.400009,24.279999 L245.520035,67.779999 L246.720016,66.220001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.680008,64.059998 L250.919998,63.820007 C251.522995 63.039001,250.647018 61.960999,249.720016 62.320007  L249.360001,62.559998 C248.776993 63.281982,249.264023 64.414001,250.320023 64.239990  L250.500015,64.179993 L250.680008,64.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.080002,63.220001 L253.620010,60.820007 L254.220016,60.519989 L254.400009,61.119995 L259.320007,75.880005 L259.919983,77.559998 L258.539978,76.420013 L246.539993,66.519989 L246.000015,66.100006 L246.539993,65.679993 L247.139999,65.739990 L259.140015,75.640015 L258.539978,76.420013 L258.359985,76.179993 L253.439987,61.420013 L254.400009,61.119995 L254.220016,61.660004 L250.680008,64.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.539993,65.679993 L250.080002,63.220001 L250.680008,64.059998 L247.139999,66.519989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.380020,63.639984 L253.920029,61.239990 L258.840027,75.999969 L246.840012,66.099976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.620010,22.959991 L222.000015,24.100006 L249.300003,63.880005 L250.919998,62.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919998,61.179993 L152.099991,61.179993 L152.279984,61.119995 C153.188004 60.755981,153.035995 59.438995,152.099991 59.199982  L151.680008,59.199982 C150.744003 59.438995,150.591995 60.755981,151.499985 61.119995  L151.680008,61.179993 L151.919998,61.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919998,60.220001 L156.840012,60.220001 L156.659988,60.880005 L152.400009,75.880005 L151.919998,77.559998 L151.439987,75.880005 L147.120010,60.880005 L146.939987,60.220001 L147.599991,60.220001 L148.080002,60.579987 L152.400009,75.579987 L151.439987,75.880005 L151.439987,75.579987 L155.699997,60.579987 L156.659988,60.880005 L156.180008,61.239990 L151.919998,61.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="147.600021" y="60.220001" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919998,60.699982 L156.180008,60.699982 L151.919998,75.699982 L147.599991,60.699982" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.960007" y="23.500000" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M142.139999,64.479980 L142.259995,64.359985 L142.379990,64.179993 C142.849014 63.179993,142.030991 62.448975,141.060013 62.739990  L140.939987,62.859985 L140.759995,62.979980 C140.143997 63.843994,140.725998 64.794983,141.780014 64.659973  L141.960007,64.599976 L142.139999,64.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M141.539993,63.699982 L144.960007,61.119995 L145.559982,60.759979 L145.740005,61.359985 L151.259995,75.939972 L151.919998,77.559967 L150.479996,76.479980 L138.059982,67.059967 L137.520004,66.639984 L138.059982,66.279968 L138.659988,66.279968 L151.080002,75.699982 L150.479996,76.479980 L150.300003,76.239990 L144.779984,61.659973 L145.740005,61.359985 L145.559982,61.899994 L142.139999,64.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.060013,66.279999 L141.540024,63.700012 L142.139999,64.480011 L138.660019,67.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M141.840012,64.059998 L145.260025,61.480011 L150.780014,76.059998 L138.360001,66.639984" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M112.199997,22.899994 L110.639999,24.100006 L140.759995,64.239990 L142.319992,63.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.280014" y="77.500000" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.280014" y="77.260010" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="77.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.040009" y="90.760010" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.040009" y="77.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500015" y="77.500000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500015" y="77.260010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="77.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="90.760010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="77.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.780014" y="77.500000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.780014" y="77.260010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="77.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="90.760010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000015" y="77.500000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.000015" y="77.260010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="77.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="90.760010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.140015" y="10.000000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.140015" y="9.759979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="10.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="23.259979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.000000,61.179993 L297.239990,61.179993 L297.420044,61.119995 C298.328003 60.755981,298.176025 59.438995,297.239990 59.199982  L296.820007,59.199982 C295.884033 59.438995,295.731995 60.755981,296.640015 61.119995  L296.820007,61.179993 L297.000000,61.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.000000,60.220001 L301.980042,60.220001 L301.799988,60.880005 L297.480042,75.880005 L297.000000,77.559998 L296.520020,75.880005 L292.260010,60.880005 L292.080017,60.220001 L292.739990,60.220001 L293.220032,60.579987 L297.480042,75.579987 L296.520020,75.880005 L296.520020,75.579987 L300.840027,60.579987 L301.799988,60.880005 L301.320007,61.239990 L297.000000,61.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.739990" y="60.220001" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.000000,60.699982 L301.320007,60.699982 L297.000000,75.699982 L292.739990,60.699982" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="296.039978" y="23.500000" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.760010,64.059998 L287.940002,63.940002 L288.059998,63.820007 C288.567017 63.028992,287.804993 61.947998,286.859985 62.320007  L286.500000,62.559998 L286.380005,62.739990 L286.260010,62.859985 L286.260010,63.040009 L286.200012,63.279999 L286.320007,63.639984 L286.380005,63.820007 L286.500000,64.000000 L286.679993,64.119995 L287.039978,64.239990 L287.400024,64.239990 L287.580017,64.179993 L287.760010,64.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.220032,63.220001 L290.760010,60.820007 L291.360046,60.519989 L291.540039,61.119995 L296.460022,75.880005 L297.059998,77.559998 L295.679993,76.420013 L283.679993,66.519989 L283.140015,66.100006 L283.679993,65.679993 L284.280029,65.739990 L296.280029,75.640015 L295.679993,76.420013 L295.500000,76.179993 L290.580017,61.420013 L291.540039,61.119995 L291.360046,61.660004 L287.820007,64.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.679993,65.679993 L287.220032,63.220001 L287.820007,64.059998 L284.280029,66.519989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.520020,63.639984 L291.059998,61.239990 L295.979980,75.999969 L283.979980,66.099976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.760010,22.959991 L259.140015,24.100006 L286.440002,63.880005 L288.059998,62.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000015" y="10.000000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.000015" y="9.759979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="10.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="23.259979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.919998,10.000000 L243.000015,10.000000 L243.000015,23.500000 L205.919998,23.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.919998" y="9.759979" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="10.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="23.259979" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.780014" y="10.000000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.780014" y="9.759979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="10.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="23.259979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.639999" y="10.000000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.639999" y="9.759979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="10.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="23.259979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500015" y="10.000000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500015" y="9.759979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="10.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="23.259979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="9.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.360001" y="10.000000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.360001" y="9.759979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="10.000000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="23.259979" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.280014" y="10.000000" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.280014" y="9.759979" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="10.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.040009" y="23.259979" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.040009" y="9.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.140015" y="40.359985" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.140015" y="40.119965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="40.359985" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="53.619965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000015" y="40.359985" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.000015" y="40.119965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="40.359985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="53.619965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.919998,40.359985 L243.000015,40.359985 L243.000015,53.859985 L205.919998,53.859985" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.919998" y="40.119965" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="40.359985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="53.619965" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.780014" y="40.359985" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.780014" y="40.119965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="40.359985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="53.619965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="40.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.639999" y="40.359985" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.639999" y="40.119965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="40.359985" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="53.619965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500015" y="40.359985" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500015" y="40.119965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="40.359985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="53.619965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="40.119995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.360001" y="40.359985" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.360001" y="40.119965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="40.359985" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="53.619965" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.280014" y="40.359985" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.280014" y="40.119965" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="40.359985" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.040009" y="53.619965" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.040009" y="40.119995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.140015" y="77.500000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.140015" y="77.260010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="77.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="90.760010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.360001" y="77.500000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.360001" y="77.260010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260010" y="77.500000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="90.760010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.120010" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.639999" y="77.500000" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.639999" y="77.260010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="77.500000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="90.760010" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.919998,77.500000 L243.000015,77.500000 L243.000015,91.000000 L205.919998,91.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.919998" y="77.260010" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759995" y="77.500000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="90.760010" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M37.140015,61.179993 L37.320007,61.179993 L37.500015,61.119995 C38.417007 60.837006,38.315018 59.401001,37.320007 59.199982  L36.960022,59.199982 C36.001007 59.386993,35.858017 60.730988,36.720016 61.119995  L36.960022,61.179993 L37.140015,61.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M37.140015,60.220001 L42.120010,60.220001 L41.940018,60.880005 L37.620010,75.880005 L37.140015,77.559998 L36.660019,75.880005 L32.340012,60.880005 L32.160019,60.220001 L32.820007,60.220001 L33.300018,60.579987 L37.620010,75.579987 L36.660019,75.880005 L36.660019,75.579987 L40.980011,60.579987 L41.940018,60.880005 L41.460022,61.239990 L37.140015,61.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.820007" y="60.220001" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M37.140015,60.699982 L41.460022,60.699982 L37.140015,75.699982 L32.820007,60.699982" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.180008" y="53.860016" width="1.980000" height="6.360000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M50.880005,68.739990 L51.000000,68.919983 L51.360001,69.160004 L51.540009,69.220001 L51.900009,69.220001 L52.080002,69.160004 L52.440002,68.919983 C52.772003 68.602997,52.747009 68.485992,52.740005 68.079987  L52.680008,67.839996 L52.559998,67.660004 L52.440002,67.539978 C51.819000 66.847992,50.632004 67.341980,50.760010 68.380005  L50.820007,68.559998 L50.880005,68.739990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M51.720001,68.259979 L54.059998,71.859985 L54.360001,72.459991 L53.759995,72.579987 L38.759995,77.019989 L37.080002,77.559967 L38.220001,76.239990 L48.600006,64.539978 L49.080002,63.999969 L49.440002,64.599976 L49.380005,65.199982 L39.000000,76.899994 L38.220001,76.239990 L38.460007,76.059967 L53.460007,71.619965 L53.759995,72.579987 L53.160004,72.399994 L50.820007,68.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M49.440002,64.599976 L51.720001,68.259979 L50.820007,68.799988 L48.540009,65.139984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M51.300003,68.500000 L53.639999,72.100006 L38.639999,76.540009 L49.020004,64.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M74.820007,54.699982 L73.740005,53.019989 L51.180008,67.359985 L52.260010,69.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.120010,72.339996 L93.180008,72.519989 L93.300003,72.699982 C93.991013 73.483002,95.125015 72.865997,95.040009 71.919983  L94.980011,71.739990 L94.920013,71.559998 L94.800003,71.380005 L94.680008,71.260010 L94.500015,71.139984 L94.140015,71.019989 L93.960007,71.019989 L93.720016,71.079987 C93.325012 71.334991,93.245010 71.296997,93.120010 71.799988  L93.060013,71.980011 L93.060013,72.160004 L93.120010,72.339996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.080002,72.039978 L95.400009,76.119965 L95.520004,76.779968 L94.919998,76.839966 L79.380005,77.499969 L77.639999,77.559967 L79.080002,76.539978 L91.919998,67.719971 L92.460007,67.359985 L92.699997,67.959991 L92.460007,68.559967 L79.619995,77.379974 L79.080002,76.539978 L79.320007,76.479980 L94.860001,75.819977 L94.919998,76.839966 L94.380005,76.479980 L93.059998,72.399963" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.700012,67.959991 L94.080017,72.039978 L93.060013,72.399994 L91.680008,68.319977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.600006,72.220001 L94.920013,76.299988 L79.380005,76.959991 L92.220001,68.140015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.800003,54.819977 L148.199997,52.959991 L93.779999,71.139984 L94.380005,72.999969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M91.380005,68.739990 L91.500000,68.919983 L91.860001,69.160004 L92.040009,69.220001 L92.400009,69.220001 L92.580002,69.160004 L92.940002,68.919983 C93.272003 68.602997,93.247009 68.485992,93.240005 68.079987  L93.180008,67.839996 L93.059998,67.660004 L92.940002,67.539978 C92.337997 66.859985,91.130005 67.328979,91.260010 68.380005  L91.320007,68.559998 L91.380005,68.739990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.220001,68.259979 L94.559998,71.859985 L94.860001,72.459991 L94.259995,72.579987 L79.259995,77.019989 L77.580002,77.559967 L78.720001,76.239990 L89.100006,64.539978 L89.580002,63.999969 L89.940002,64.599976 L89.880005,65.199982 L79.500000,76.899994 L78.720001,76.239990 L78.960007,76.059967 L93.960007,71.619965 L94.259995,72.579987 L93.660004,72.399994 L91.320007,68.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.940002,64.599976 L92.220001,68.259979 L91.320007,68.799988 L89.040009,65.139984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M91.800003,68.500000 L94.139999,72.100006 L79.139999,76.540009 L89.520004,64.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.320023,54.699982 L114.240036,53.019989 L91.680023,67.359985 L92.760025,69.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.360001,61.359985 L183.719986,61.239990 L183.840012,61.119995 L184.020004,61.000000 L184.080002,60.819977 L184.199997,60.459991 L184.199997,60.219971 L184.139999,60.039978 L184.080002,59.859985 L183.780014,59.559998 L183.659988,59.500000 L183.479996,59.439972 L183.240005,59.379974 L183.060013,59.379974 L182.879990,59.439972 C181.930008 59.652985,182.039993 61.156982,182.939987 61.359985  L183.360001,61.359985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.180008,60.399994 L187.440018,59.799988 L188.100021,59.739990 L187.979996,60.399994 L185.880020,75.820007 L185.639999,77.559998 L184.979996,75.940002 L178.620010,61.720001 L178.320023,61.119995 L178.979996,61.000000 L179.520004,61.299988 L185.880020,75.519989 L184.979996,75.940002 L184.919998,75.639984 L187.020004,60.220001 L187.979996,60.399994 L187.560013,60.820007 L183.300003,61.419983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.979996,61.000000 L183.180008,60.399994 L183.300003,61.420013 L179.099991,62.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.240005,60.879974 L187.500015,60.279968 L185.400009,75.699982 L179.039993,61.479980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.300003,53.739990 L181.319992,53.979980 L182.220016,60.519989 L184.199997,60.279999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.020004,68.139984 L199.139999,68.319977 L199.259995,68.439972 C200.125015 68.899994,201.112015 68.109985,200.759995 67.179993  L200.639999,66.999969 L200.520004,66.879974 C199.753006 66.170990,198.712997 66.770996,198.840012 67.779999  L198.900009,67.959991 L199.020004,68.139984" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.800003,67.599976 L202.319992,71.079987 L202.680008,71.619965 L202.020004,71.859985 L187.259995,76.959961 L185.639999,77.559967 L186.720016,76.179962 L196.500015,64.059967 L196.919998,63.519989 L197.340012,64.059967 L197.280014,64.659973 L187.500015,76.779968 L186.720016,76.179962 L186.960007,75.999969 L201.720016,70.899963 L202.020004,71.859985 L201.479996,71.679962 L198.960007,68.199982" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M197.340012,64.059998 L199.800003,67.600006 L198.960007,68.200012 L196.500015,64.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.380020,67.899994 L201.900009,71.380005 L187.140030,76.479980 L196.920029,64.359985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.020004,54.699982 L218.879990,53.079987 L199.259995,66.819977 L200.400009,68.439972" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.259995,72.339996 L238.319992,72.519989 L238.439987,72.699982 C239.070999 73.489990,240.262009 72.833008,240.180008 71.919983  L240.059982,71.559998 C239.529984 70.647003,238.272995 70.971008,238.199997 71.980011  L238.199997,72.160004 L238.259995,72.339996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.220016,72.039978 L240.540024,76.119965 L240.660019,76.779968 L240.060013,76.839966 L224.520004,77.499969 L222.780014,77.559967 L224.220016,76.539978 L237.060013,67.719971 L237.600021,67.359985 L237.840012,67.959991 L237.600021,68.559967 L224.760025,77.379974 L224.220016,76.539978 L224.460007,76.479980 L240.000015,75.819977 L240.060013,76.839966 L239.520004,76.479980 L238.200027,72.399963" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.840012,67.959991 L239.220016,72.039978 L238.199997,72.399994 L236.820023,68.319977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.740005,72.220001 L240.060013,76.299988 L224.520004,76.959991 L237.360001,68.140015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M293.940002,54.819977 L293.340027,52.959991 L238.860001,71.139984 L239.460007,72.999969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.100021,68.139984 L236.400009,68.439972 C237.306015 68.895996,238.253036 68.102997,237.840012 67.179993  L237.780014,66.999969 L237.660019,66.879974 L237.300034,66.639984 L237.120010,66.579987 L236.760025,66.579987 L236.520035,66.639984 L236.400009,66.759979 L236.220016,66.879974 L236.100021,67.059998 L235.980026,67.419983 L235.920029,67.599976 L236.100021,68.139984" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.940018,67.599976 L239.400009,71.079987 L239.760025,71.619965 L239.100021,71.859985 L224.400009,76.959961 L222.780014,77.559967 L223.860031,76.179962 L233.640030,64.059967 L234.060013,63.519989 L234.480026,64.059967 L234.420029,64.659973 L224.640030,76.779968 L223.860031,76.179962 L224.100021,75.999969 L238.800003,70.899963 L239.100021,71.859985 L238.560013,71.679962 L236.100021,68.199982" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.479996,64.059998 L236.939987,67.600006 L236.099991,68.200012 L233.639999,64.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.520004,67.899994 L238.979996,71.380005 L224.280014,76.479980 L234.060013,64.359985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.100037,54.699982 L255.960007,53.079987 L236.400009,66.819977 L237.540024,68.439972" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="209.280014" y="86.019989" textLength="5.530430" font-size="8px">Y</text>
<text x="150.058487" y="86.019989" textLength="5.002500" font-size="8px">X</text>
<text x="147.590988" y="86.019989" textLength="2.497500" font-size="8px">-</text>
<text x="143.392502" y="86.019989" textLength="4.170000" font-size="8px">4</text>
<text x="77.458511" y="86.019989" textLength="4.170000" font-size="8px">5</text>
<text x="72.478516" y="86.019989" textLength="5.002500" font-size="8px">Y</text>
<text x="69.951019" y="86.019989" textLength="2.497500" font-size="8px">-</text>
<text x="300.122253" y="87.639984" textLength="4.170000" font-size="8px">1</text>
<text x="295.145996" y="87.639984" textLength="5.002500" font-size="8px">X</text>
<text x="283.500000" y="87.639984" textLength="5.002500" font-size="8px">X</text>
<text x="36.300003" y="48.940002" textLength="4.170000" font-size="8px">7</text>
<text x="31.320007" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="73.440002" y="48.940002" textLength="4.170000" font-size="8px">6</text>
<text x="68.460007" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="110.640030" y="48.940002" textLength="4.170000" font-size="8px">5</text>
<text x="105.600021" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="147.780014" y="48.940002" textLength="4.170000" font-size="8px">4</text>
<text x="142.740005" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="184.860031" y="48.940002" textLength="4.170000" font-size="8px">3</text>
<text x="179.880020" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="221.940018" y="48.940002" textLength="4.170000" font-size="8px">2</text>
<text x="216.960007" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="254.100021" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="291.239990" y="48.940002" textLength="5.002500" font-size="8px">Y</text>
<text x="36.300003" y="18.519989" textLength="4.170000" font-size="8px">7</text>
<text x="31.320007" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="68.460007" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="105.600021" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="147.780014" y="18.519989" textLength="4.170000" font-size="8px">4</text>
<text x="142.740005" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="179.880020" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="221.940018" y="18.519989" textLength="4.170000" font-size="8px">2</text>
<text x="15.778519" y="50.559998" textLength="4.170000" font-size="8px">2</text>
<text x="10.381516" y="50.559998" textLength="5.415000" font-size="8px">C</text>
<text x="296.280029" y="18.519989" textLength="4.170000" font-size="8px">0</text>
<text x="291.239990" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="16.076996" y="20.139984" textLength="4.170000" font-size="8px">1</text>
<text x="10.618500" y="20.139984" textLength="5.415000" font-size="8px">C</text>
<text x="5.393997" y="86.019989" textLength="5.002500" font-size="8px">E</text>
<text x="0.000000" y="86.019989" textLength="5.415000" font-size="8px">D</text>
<text x="263.098511" y="87.639984" textLength="4.170000" font-size="8px">3</text>
<text x="258.058472" y="87.639984" textLength="5.002500" font-size="8px">X</text>
<text x="246.419998" y="87.639984" textLength="5.002500" font-size="8px">X</text>
<text x="117.958511" y="86.019989" textLength="4.170000" font-size="8px">7</text>
<text x="112.978500" y="86.019989" textLength="5.002500" font-size="8px">X</text>
<text x="35.338516" y="86.019989" textLength="5.002500" font-size="8px">Y</text>
<text x="32.811020" y="86.019989" textLength="2.497500" font-size="8px">-</text>
<text x="28.672516" y="86.019989" textLength="4.170000" font-size="8px">6</text>
<text x="23.640015" y="86.019989" textLength="5.002500" font-size="8px">Y</text>
<text x="259.080017" y="48.940002" textLength="4.170000" font-size="8px">1</text>
<text x="110.640030" y="18.519989" textLength="4.170000" font-size="8px">5</text>
<text x="73.440002" y="18.519989" textLength="4.170000" font-size="8px">6</text>
<text x="259.080017" y="18.519989" textLength="4.170000" font-size="8px">1</text>
<text x="182.157791" y="86.019989" textLength="2.761070" font-size="8px">-</text>
<text x="227.594315" y="86.019989" textLength="4.610074" font-size="8px">1</text>
<text x="219.389023" y="86.019989" textLength="2.761070" font-size="8px">-</text>
<text x="155.098495" y="86.019989" textLength="4.170000" font-size="8px">5</text>
<text x="216.960007" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="15.357010" y="86.019989" textLength="4.582500" font-size="8px">T</text>
<text x="255.590988" y="87.639984" textLength="2.497500" font-size="8px">-</text>
<text x="110.451004" y="86.019989" textLength="2.497500" font-size="8px">-</text>
<text x="138.419998" y="86.019989" textLength="5.002500" font-size="8px">X</text>
<text x="0.240005" y="20.139984" textLength="5.002500" font-size="8px">S</text>
<text x="5.223007" y="20.139984" textLength="5.415000" font-size="8px">R</text>
<text x="0.000015" y="50.559998" textLength="5.002500" font-size="8px">S</text>
<text x="292.674744" y="87.639984" textLength="2.497500" font-size="8px">-</text>
<text x="172.139999" y="86.019989" textLength="5.530430" font-size="8px">Y</text>
<text x="101.280014" y="86.019989" textLength="5.002500" font-size="8px">X</text>
<text x="106.312515" y="86.019989" textLength="4.170000" font-size="8px">6</text>
<text x="288.476257" y="87.639984" textLength="4.170000" font-size="8px">0</text>
<text x="40.318512" y="86.019989" textLength="4.170000" font-size="8px">7</text>
<text x="222.134354" y="86.019989" textLength="5.530430" font-size="8px">Y</text>
<text x="251.392502" y="87.639984" textLength="4.170000" font-size="8px">2</text>
<text x="214.794693" y="86.019989" textLength="4.610074" font-size="8px">0</text>
<text x="177.609085" y="86.019989" textLength="4.610074" font-size="8px">2</text>
<text x="184.918045" y="86.019989" textLength="5.530430" font-size="8px">Y</text>
<text x="4.984512" y="50.559998" textLength="5.415000" font-size="8px">R</text>
<text x="254.100021" y="18.519989" textLength="5.002500" font-size="8px">X</text>
<text x="190.378006" y="86.019989" textLength="4.610074" font-size="8px">3</text>
<text x="296.280029" y="48.940002" textLength="4.170000" font-size="8px">0</text>
<text x="184.860031" y="18.519989" textLength="4.170000" font-size="8px">3</text>
<text x="10.375504" y="86.019989" textLength="5.002500" font-size="8px">S</text>
<text x="65.812515" y="86.019989" textLength="4.170000" font-size="8px">4</text>
<text x="60.780014" y="86.019989" textLength="5.002500" font-size="8px">Y</text>
</svg>
<figcaption>Figure 3-23.  VHSUBPS operation
</figcaption></figure>
```


128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### HSUBPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC1[63:32]
DEST[63:32] <-  SRC1[95:64] - SRC1[127:96]
DEST[95:64] <-  SRC2[31:0] - SRC2[63:32]
DEST[127:96] <-  SRC2[95:64] - SRC2[127:96] 
DEST[VLMAX-1:128] (Unmodified)
```
#### VHSUBPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC1[63:32]
DEST[63:32] <-  SRC1[95:64] - SRC1[127:96]
DEST[95:64] <-  SRC2[31:0] - SRC2[63:32]
DEST[127:96] <-  SRC2[95:64] - SRC2[127:96] 
DEST[VLMAX-1:128] <-  0
```
#### VHSUBPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC1[63:32]
DEST[63:32] <-  SRC1[95:64] - SRC1[127:96]
DEST[95:64] <-  SRC2[31:0] - SRC2[63:32]
DEST[127:96] <-  SRC2[95:64] - SRC2[127:96] 
DEST[159:128] <-  SRC1[159:128] - SRC1[191:160]
DEST[191:160] <-  SRC1[223:192] - SRC1[255:224]
DEST[223:192] <-  SRC2[159:128] - SRC2[191:160]
DEST[255:224] <-  SRC2[223:192] - SRC2[255:224]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
HSUBPS: __m128 _mm_hsub_ps(__m128 a, __m128 b);
VHSUBPS: __m256 _mm256_hsub_ps (__m256 a, __m256 b);
```
### Exceptions


When the source operand is a memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated.

### Numeric Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


See Exceptions Type 2.

