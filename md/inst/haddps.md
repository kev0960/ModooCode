----------------------------
title : HADDPS (Intel x86/64 assembly instruction)
cat_title : HADDPS
ref_title : HADDPS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ HADDPS

**Packed Single-FP Horizontal Add**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|F2 0F 7C /r\newline{}HADDPS xmm1, xmm2/m128|RM|V/V|SSE3|Horizontal add packed single-precision floating-point values from xmm2/m128 to xmm1.|
|VEX.NDS.128.F2.0F.WIG 7C /r\newline{}VHADDPS xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Horizontal add packed single-precision floating-point values from xmm2 and xmm3/mem.|
|VEX.NDS.256.F2.0F.WIG 7C /r\newline{}VHADDPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Horizontal add packed single-precision floating-point values from ymm2 and ymm3/mem.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Adds the single-precision floating-point values in the first and second dwords of the destination operand and stores the result in the first dword of the destination operand.

Adds single-precision floating-point values in the third and fourth dword of the destination operand and stores the result in the second dword of the destination operand.

Adds single-precision floating-point values in the first and second dword of the source operand and stores the result in the third dword of the destination operand.

Adds single-precision floating-point values in the third and fourth dword of the source operand and stores the result in the fourth dword of the destination operand. 

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).



See Figure3-18 for HADDPS; see Figure3-19 for VHADDPS.

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register.

```embed
<figure>
<svg viewBox="0 0 367.440002 268.640015">
<rect x="0.000000" y="9.276978" width="367.440002" height="236.970001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.725998" y="10.000000" width="361.140015" height="216.009003" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.725998" y="226.009003" width="361.140015" height="-216.009003" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.360992" y="154.768982" width="67.502998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="240.360992" y="201.920990" width="67.502998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.360992" y="37.000977" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="240.360992" y="64.001953" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.858002" y="154.768982" width="67.502998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="172.858002" y="201.920990" width="67.502998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.858002" y="37.000977" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="172.858002" y="64.001953" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.360992" y="96.398010" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="240.360992" y="123.398926" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.858002" y="96.398010" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="172.858002" y="123.398926" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="105.355995" y="154.768982" width="67.502998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="105.355995" y="201.920990" width="67.502998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="105.355995" y="37.000977" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="105.355995" y="64.001953" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.728004" y="154.768982" width="68.627998" height="47.152000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="36.728004" y="201.920990" width="68.627998" height="-47.152000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.728004" y="37.000977" width="68.627998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.728004" y="64.001953" width="68.627998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="105.355995" y="96.398010" width="67.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="105.355995" y="123.398926" width="67.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.728004" y="96.398010" width="68.627998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.728004" y="123.398926" width="68.627998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.609985,123.398987 L206.609985,131.508972 L274.112976,131.508972 L274.112976,150.690002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M276.152985,150.690002 L274.112976,154.770020 L272.072998,150.690002 L276.152985,150.690002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.112976,133.623962 L274.112976,123.403992" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M71.604988,123.398987 L71.604988,136.010010 L206.609985,136.010010 L206.609985,150.690002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M208.649994,150.690002 L206.609985,154.770020 L204.570007,150.690002 L208.649994,150.690002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.106995,136.005005 L139.106995,123.395020" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M139.106995,64.002014 L139.106995,84.252991 L29.603004,84.252991 C29.603004 82.596008,28.259010 81.252991,26.601997 81.252991  C24.945000 81.252991,23.601997 82.596008,23.601997 84.252991  L15.351997,84.252991 L15.351997,145.005005 L71.604012,145.005005 L71.604012,150.825012" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M73.644005,150.825989 L71.604012,154.906006 L69.564003,150.825989 L73.644005,150.825989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.609985,64.001953 L206.609985,75.251953" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M274.112976,64.001953 L274.112976,75.251953 L142.107971,75.251953 C142.107971 73.594971,140.764954 72.251953,139.106995 72.251953  C137.449982 72.251953,136.106995 73.594971,136.106995 75.251953  L74.604988,75.251953 C74.604988 73.594971,73.261986 72.251953,71.604988 72.251953  C69.947990 72.251953,68.604988 73.594971,68.604988 75.251953  L26.602989,75.251953 L26.602989,140.504944 L139.106995,140.504944 L139.106995,150.824951" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M141.147003,150.825989 L139.106995,154.906006 L137.067017,150.825989 L141.147003,150.825989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M71.603996,64.001953 L71.603996,84.252930" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="83.288002" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="72.167580" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="67.719414" y="112.297974" textLength="4.448167" font-size="8px">7</text>
<text x="140.221497" y="112.297974" textLength="4.448167" font-size="8px">6</text>
<text x="137.997406" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="133.549255" y="112.297974" textLength="4.448167" font-size="8px">5</text>
<text x="129.101074" y="112.297974" textLength="4.448167" font-size="8px">9</text>
<text x="149.128113" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="144.679932" y="214.958466" textLength="4.448167" font-size="8px">4</text>
<text x="138.007660" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="133.559509" y="214.958466" textLength="4.448167" font-size="8px">5</text>
<text x="129.111328" y="214.958466" textLength="4.448167" font-size="8px">9</text>
<text x="126.887245" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="74.946892" y="214.958466" textLength="4.448167" font-size="8px">9</text>
<text x="72.722801" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="63.826469" y="214.958466" textLength="4.448167" font-size="8px">2</text>
<text x="59.378304" y="214.958466" textLength="4.448167" font-size="8px">1</text>
<text x="83.288002" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="67.719414" y="52.901978" textLength="4.448167" font-size="8px">7</text>
<text x="63.271248" y="52.901978" textLength="4.448167" font-size="8px">2</text>
<text x="58.823082" y="52.901978" textLength="4.448167" font-size="8px">1</text>
<text x="87.907478" y="190.350677" textLength="4.043788" font-size="8px">6</text>
<text x="83.863686" y="190.350677" textLength="4.043788" font-size="8px">9</text>
<text x="81.841789" y="190.350677" textLength="2.021894" font-size="8px">:</text>
<text x="74.391670" y="52.901978" textLength="4.448167" font-size="8px">9</text>
<text x="257.398346" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="336.116638" y="48.101501" textLength="2.224083" font-size="8px">/</text>
<text x="209.091797" y="175.949951" textLength="4.043788" font-size="8px">5</text>
<text x="320.116028" y="175.907104" textLength="5.336200" font-size="8px">E</text>
<text x="144.669678" y="112.297974" textLength="4.448167" font-size="8px">4</text>
<text x="56.598991" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="279.624634" y="185.550293" textLength="4.043788" font-size="8px">3</text>
<text x="318.339966" y="48.101501" textLength="6.664250" font-size="8px">m</text>
<text x="201.008881" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="76.220497" y="180.750305" textLength="3.636500" font-size="8px">x</text>
<text x="252.691986" y="175.949951" textLength="3.636500" font-size="8px">x</text>
<text x="275.222443" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="83.590218" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="51.754097" y="180.750305" textLength="4.043788" font-size="8px">5</text>
<text x="264.101990" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="183.229004" y="175.949951" textLength="3.636500" font-size="8px">x</text>
<text x="55.797890" y="180.750305" textLength="2.021894" font-size="8px">:</text>
<text x="126.876991" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="47.710304" y="180.750305" textLength="4.043788" font-size="8px">9</text>
<text x="272.489105" y="175.949951" textLength="2.021894" font-size="8px">[</text>
<text x="69.710411" y="190.350677" textLength="4.043788" font-size="8px">1</text>
<text x="55.557137" y="190.350677" textLength="4.043788" font-size="8px">1</text>
<text x="73.488014" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="192.112518" y="214.958466" textLength="4.448167" font-size="8px">6</text>
<text x="96.017616" y="180.750305" textLength="2.021894" font-size="8px">/</text>
<text x="262.386902" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="176.747498" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="336.564667" y="175.907104" textLength="4.448167" font-size="8px">L</text>
<text x="314.339813" y="57.701843" textLength="6.664250" font-size="8px">m</text>
<text x="77.797997" y="190.350677" textLength="4.043788" font-size="8px">7</text>
<text x="127.849617" y="27.587952" textLength="5.776217" font-size="8px">D</text>
<text x="296.955444" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="266.326080" y="112.297974" textLength="4.448167" font-size="8px">3</text>
<text x="56.598991" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="204.106171" y="185.550293" textLength="2.021894" font-size="8px">[</text>
<text x="201.051270" y="112.297974" textLength="4.448167" font-size="8px">3</text>
<text x="57.154213" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="163.850983" y="27.587952" textLength="4.448167" font-size="8px">1</text>
<text x="194.378998" y="52.901978" textLength="2.224083" font-size="8px">[</text>
<text x="225.266937" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="117.748100" y="180.750305" textLength="4.043788" font-size="8px">3</text>
<text x="277.446533" y="112.297974" textLength="4.448167" font-size="8px">0</text>
<text x="346.035309" y="240.059967" textLength="3.336111" font-size="8px">1</text>
<text x="91.951271" y="190.350677" textLength="2.021894" font-size="8px">]</text>
<text x="336.368988" y="240.059967" textLength="4.668155" font-size="8px">O</text>
<text x="331.668457" y="185.507446" textLength="4.448167" font-size="8px">1</text>
<text x="215.157471" y="175.949951" textLength="4.043788" font-size="8px">6</text>
<text x="155.710968" y="171.149963" textLength="4.043788" font-size="8px">8</text>
<text x="285.690308" y="185.550293" textLength="4.043788" font-size="8px">3</text>
<text x="331.668457" y="48.101501" textLength="4.448167" font-size="8px">2</text>
<text x="228.368896" y="185.550293" textLength="2.021894" font-size="8px">]</text>
<text x="318.339966" y="185.507446" textLength="6.664250" font-size="8px">m</text>
<text x="196.603088" y="52.901978" textLength="4.448167" font-size="8px">6</text>
<text x="288.664246" y="175.949951" textLength="2.021894" font-size="8px">]</text>
<text x="223.245056" y="175.949951" textLength="2.021894" font-size="8px">]</text>
<text x="281.894714" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="138.962036" y="27.587952" textLength="5.336200" font-size="8px">S</text>
<text x="121.791893" y="180.750305" textLength="4.043788" font-size="8px">1</text>
<text x="194.378998" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="149.117859" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="293.777893" y="185.550293" textLength="2.021894" font-size="8px">]</text>
<text x="216.619904" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="151.667175" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="359.379791" y="240.059967" textLength="3.336111" font-size="8px">4</text>
<text x="129.638733" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="183.411743" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="126.876991" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="207.681152" y="214.958466" textLength="4.448167" font-size="8px">2</text>
<text x="282.598572" y="175.949951" textLength="2.021894" font-size="8px">:</text>
<text x="135.945160" y="180.750305" textLength="4.247432" font-size="8px">+</text>
<text x="55.305504" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="325.004211" y="48.101501" textLength="6.664250" font-size="8px">m</text>
<text x="289.734100" y="185.550293" textLength="4.043788" font-size="8px">2</text>
<text x="49.498726" y="190.350677" textLength="6.058409" font-size="8px">m</text>
<text x="74.391670" y="112.297974" textLength="4.448167" font-size="8px">9</text>
<text x="68.274635" y="214.958466" textLength="4.448167" font-size="8px">7</text>
<text x="194.524170" y="27.587952" textLength="2.224083" font-size="8px">/</text>
<text x="268.611450" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="281.894714" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="321.004059" y="57.701843" textLength="4.448167" font-size="8px">1</text>
<text x="314.339813" y="48.101501" textLength="4.000150" font-size="8px">x</text>
<text x="275.222443" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="123.382500" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="198.982330" y="175.949951" textLength="4.043788" font-size="8px">1</text>
<text x="189.888428" y="214.958466" textLength="2.224083" font-size="8px">[</text>
<text x="119.745995" y="171.149963" textLength="3.636500" font-size="8px">x</text>
<text x="207.723541" y="52.901978" textLength="4.448167" font-size="8px">3</text>
<text x="224.325104" y="185.550293" textLength="4.043788" font-size="8px">6</text>
<text x="340.420807" y="175.907104" textLength="4.888184" font-size="8px">T</text>
<text x="270.774261" y="112.297974" textLength="4.448167" font-size="8px">1</text>
<text x="227.288818" y="175.949951" textLength="4.247432" font-size="8px">+</text>
<text x="283.668427" y="185.550293" textLength="2.021894" font-size="8px">:</text>
<text x="284.620453" y="175.949951" textLength="4.043788" font-size="8px">0</text>
<text x="67.422325" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="157.945251" y="190.350677" textLength="2.021894" font-size="8px">]</text>
<text x="231.536255" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="263.456757" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="129.440918" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="51.668999" y="171.149963" textLength="3.636500" font-size="8px">x</text>
<text x="150.522491" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="349.371429" y="240.059967" textLength="3.336111" font-size="8px">5</text>
<text x="341.037140" y="240.059967" textLength="4.998167" font-size="8px">M</text>
<text x="140.231750" y="214.958466" textLength="4.448167" font-size="8px">6</text>
<text x="79.395058" y="214.958466" textLength="4.448167" font-size="8px">6</text>
<text x="63.271248" y="112.297974" textLength="4.448167" font-size="8px">2</text>
<text x="329.900421" y="57.701843" textLength="4.448167" font-size="8px">8</text>
<text x="74.198601" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="205.048004" y="175.949951" textLength="4.043788" font-size="8px">9</text>
<text x="207.860687" y="27.587952" textLength="4.448167" font-size="8px">2</text>
<text x="269.515167" y="185.550293" textLength="4.043788" font-size="8px">1</text>
<text x="143.791992" y="190.350677" textLength="4.043788" font-size="8px">3</text>
<text x="205.499451" y="112.297974" textLength="2.224083" font-size="8px">:</text>
<text x="264.101990" y="112.297974" textLength="2.224083" font-size="8px">[</text>
<text x="203.232971" y="214.958466" textLength="4.448167" font-size="8px">3</text>
<text x="133.625824" y="27.587952" textLength="5.336200" font-size="8px">P</text>
<text x="281.955994" y="214.958466" textLength="4.448167" font-size="8px">0</text>
<text x="135.499329" y="171.149963" textLength="4.043788" font-size="8px">2</text>
<text x="286.404175" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="137.726318" y="190.350677" textLength="2.021894" font-size="8px">[</text>
<text x="212.308868" y="27.587952" textLength="4.448167" font-size="8px">8</text>
<text x="214.215637" y="185.550293" textLength="4.043788" font-size="8px">7</text>
<text x="218.259430" y="185.550293" textLength="2.021894" font-size="8px">:</text>
<text x="162.011597" y="180.750305" textLength="2.021894" font-size="8px">/</text>
<text x="144.669678" y="52.901978" textLength="4.448167" font-size="8px">4</text>
<text x="78.839836" y="112.297974" textLength="4.448167" font-size="8px">6</text>
<text x="352.707550" y="240.059967" textLength="3.336111" font-size="8px">9</text>
<text x="110.960991" y="27.587952" textLength="5.776217" font-size="8px">H</text>
<text x="290.686127" y="175.949951" textLength="2.021894" font-size="8px"> </text>
<text x="196.560699" y="214.958466" textLength="4.448167" font-size="8px">3</text>
<text x="116.737206" y="27.587952" textLength="5.336200" font-size="8px">A</text>
<text x="122.073402" y="27.587952" textLength="5.776217" font-size="8px">D</text>
<text x="253.761841" y="185.550293" textLength="3.636500" font-size="8px">x</text>
<text x="61.363914" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="144.298248" y="27.587952" textLength="2.224083" font-size="8px"> </text>
<text x="146.522339" y="27.587952" textLength="4.000150" font-size="8px">x</text>
<text x="273.558960" y="185.550293" textLength="2.021894" font-size="8px">[</text>
<text x="157.186737" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="168.299164" y="27.587952" textLength="2.224083" font-size="8px">,</text>
<text x="170.523254" y="27.587952" textLength="2.224083" font-size="8px"> </text>
<text x="119.536522" y="190.350677" textLength="6.058409" font-size="8px">m</text>
<text x="172.747345" y="27.587952" textLength="4.000150" font-size="8px">x</text>
<text x="190.075989" y="27.587952" textLength="4.448167" font-size="8px">2</text>
<text x="58.823082" y="112.297974" textLength="4.448167" font-size="8px">1</text>
<text x="356.043671" y="240.059967" textLength="3.336111" font-size="8px">9</text>
<text x="196.748260" y="27.587952" textLength="6.664250" font-size="8px">m</text>
<text x="292.708008" y="175.949951" textLength="4.247432" font-size="8px">+</text>
<text x="67.929268" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="203.412506" y="27.587952" textLength="4.448167" font-size="8px">1</text>
<text x="314.339813" y="175.907104" textLength="5.776217" font-size="8px">R</text>
<text x="125.594933" y="190.350677" textLength="4.043788" font-size="8px">1</text>
<text x="325.452240" y="175.907104" textLength="5.336200" font-size="8px">S</text>
<text x="330.788452" y="175.907104" textLength="5.776217" font-size="8px">U</text>
<text x="344.420959" y="175.907104" textLength="2.224083" font-size="8px">:</text>
<text x="314.339813" y="185.507446" textLength="4.000150" font-size="8px">x</text>
<text x="325.004211" y="185.507446" textLength="6.664250" font-size="8px">m</text>
<text x="325.452240" y="57.701843" textLength="4.448167" font-size="8px">2</text>
<text x="256.328491" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="65.907372" y="180.750305" textLength="2.021894" font-size="8px">]</text>
<text x="268.445312" y="175.949951" textLength="4.043788" font-size="8px">1</text>
<text x="274.510986" y="175.949951" textLength="4.043788" font-size="8px">3</text>
<text x="278.554779" y="175.949951" textLength="4.043788" font-size="8px">1</text>
<text x="275.283722" y="214.958466" textLength="4.448167" font-size="8px">1</text>
<text x="266.326080" y="52.901978" textLength="4.448167" font-size="8px">3</text>
<text x="129.101074" y="52.901978" textLength="4.448167" font-size="8px">9</text>
<text x="270.774261" y="52.901978" textLength="4.448167" font-size="8px">1</text>
<text x="277.446533" y="52.901978" textLength="4.448167" font-size="8px">0</text>
<text x="192.923920" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="203.026123" y="175.949951" textLength="2.021894" font-size="8px">[</text>
<text x="79.546425" y="171.149963" textLength="4.043788" font-size="8px">1</text>
<text x="213.135590" y="175.949951" textLength="2.021894" font-size="8px">:</text>
<text x="219.201263" y="175.949951" textLength="4.043788" font-size="8px">4</text>
<text x="184.309052" y="185.550293" textLength="3.636500" font-size="8px">x</text>
<text x="194.003967" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="200.062378" y="185.550293" textLength="4.043788" font-size="8px">1</text>
<text x="206.128052" y="185.550293" textLength="4.043788" font-size="8px">1</text>
<text x="210.171844" y="185.550293" textLength="4.043788" font-size="8px">2</text>
<text x="220.281311" y="185.550293" textLength="4.043788" font-size="8px">9</text>
<text x="201.051270" y="52.901978" textLength="4.448167" font-size="8px">3</text>
<text x="205.499451" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="212.171722" y="52.901978" textLength="4.448167" font-size="8px">2</text>
<text x="59.600929" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="216.619904" y="52.901978" textLength="2.224083" font-size="8px">]</text>
<text x="212.129333" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="270.835541" y="214.958466" textLength="4.448167" font-size="8px">3</text>
<text x="72.167580" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="279.731903" y="214.958466" textLength="2.224083" font-size="8px">:</text>
<text x="314.338715" y="112.297791" textLength="4.000150" font-size="8px">x</text>
<text x="318.338867" y="112.297791" textLength="6.664250" font-size="8px">m</text>
<text x="325.003113" y="112.297791" textLength="6.664250" font-size="8px">m</text>
<text x="331.667358" y="112.297791" textLength="4.448167" font-size="8px">1</text>
<text x="196.603088" y="112.297974" textLength="4.448167" font-size="8px">6</text>
<text x="207.723541" y="112.297974" textLength="4.448167" font-size="8px">3</text>
<text x="187.945557" y="185.550293" textLength="6.058409" font-size="8px">m</text>
<text x="212.171722" y="112.297974" textLength="4.448167" font-size="8px">2</text>
<text x="139.543091" y="171.149963" textLength="2.021894" font-size="8px">/</text>
<text x="141.564972" y="171.149963" textLength="6.058409" font-size="8px">m</text>
<text x="147.623383" y="171.149963" textLength="4.043788" font-size="8px">1</text>
<text x="186.865509" y="175.949951" textLength="6.058409" font-size="8px">m</text>
<text x="115.726204" y="180.750305" textLength="2.021894" font-size="8px">[</text>
<text x="125.835686" y="180.750305" textLength="2.021894" font-size="8px">:</text>
<text x="275.580841" y="185.550293" textLength="4.043788" font-size="8px">6</text>
<text x="127.857582" y="180.750305" textLength="4.043788" font-size="8px">0</text>
<text x="131.901367" y="180.750305" textLength="2.021894" font-size="8px">]</text>
<text x="133.923279" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="140.192596" y="180.750305" textLength="2.021894" font-size="8px"> </text>
<text x="67.688515" y="190.350677" textLength="2.021894" font-size="8px">[</text>
<text x="142.214478" y="180.750305" textLength="3.636500" font-size="8px">x</text>
<text x="145.850983" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="149.117859" y="112.297974" textLength="2.224083" font-size="8px">]</text>
<text x="83.843224" y="214.958466" textLength="2.224083" font-size="8px">]</text>
<text x="151.909393" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="157.967804" y="180.750305" textLength="4.043788" font-size="8px">2</text>
<text x="73.754204" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="78.839836" y="52.901978" textLength="4.448167" font-size="8px">6</text>
<text x="133.682526" y="190.350677" textLength="4.043788" font-size="8px">8</text>
<text x="139.748199" y="190.350677" textLength="4.043788" font-size="8px">6</text>
<text x="147.835785" y="190.350677" textLength="2.021894" font-size="8px">:</text>
<text x="149.857666" y="190.350677" textLength="4.043788" font-size="8px">3</text>
<text x="153.901459" y="190.350677" textLength="4.043788" font-size="8px">2</text>
<text x="133.549255" y="52.901978" textLength="4.448167" font-size="8px">5</text>
<text x="137.997406" y="52.901978" textLength="2.224083" font-size="8px">:</text>
<text x="140.221497" y="52.901978" textLength="4.448167" font-size="8px">6</text>
<text x="71.466118" y="171.149963" textLength="2.021894" font-size="8px">/</text>
<text x="87.634010" y="171.149963" textLength="4.043788" font-size="8px">8</text>
<text x="45.688408" y="180.750305" textLength="2.021894" font-size="8px">[</text>
<text x="57.819786" y="180.750305" textLength="4.043788" font-size="8px">6</text>
<text x="61.863579" y="180.750305" textLength="4.043788" font-size="8px">4</text>
<text x="69.951164" y="180.750305" textLength="4.247432" font-size="8px">+</text>
<text x="79.857002" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="85.915413" y="180.750305" textLength="6.058409" font-size="8px">m</text>
<text x="91.973824" y="180.750305" textLength="4.043788" font-size="8px">2</text>
<text x="63.644722" y="190.350677" textLength="4.043788" font-size="8px">8</text>
</svg>
<figcaption>Figure 3-18.  HADDPS--Packed Single-FP Horizontal Add
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 317.520020 201.279999">
<path d="M105.539993,63.820007 L105.719986,63.700012 L105.839981,63.520020 L105.960007,63.160004 L105.960007,62.800018 L105.899979,62.619995 L105.659988,62.260010 L105.539993,62.140015 L105.180008,62.020020 L104.939987,61.960022 L104.399994,62.140015 L104.279999,62.320007 C103.501999 62.968994,104.302994 64.218018,105.180008 63.940002  L105.539993,63.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M104.939987,62.979980 L108.479996,60.519989 L109.080002,60.159973 L109.259995,60.819977 L114.239975,75.639984 L114.839981,77.319977 L113.459976,76.179993 L101.399994,66.279968 L100.859985,65.859985 L101.399994,65.439972 L101.999985,65.499969 L114.059982,75.399994 L113.459976,76.179993 L113.279984,75.939972 L108.299973,61.119995 L109.259995,60.819977 L109.080002,61.359985 L105.539993,63.819977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.399994,65.440002 L104.939987,62.980011 L105.539993,63.820007 L102.000000,66.279999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M105.240005,63.399994 L108.780014,60.940002 L113.759995,75.759979 L101.700012,65.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M78.479996,22.720001 L76.860001,23.860016 L104.220001,63.580017 L105.839981,62.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.580002,67.660004 L101.699997,67.480011 L101.759995,67.300018 C101.921997 66.273010,100.847000 65.674011,100.080002 66.339996  L99.960007,66.459991 L99.900009,66.640015 C99.335007 67.477997,100.570999 68.489014,101.279999 67.899994  L101.460007,67.779999 L101.580002,67.660004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.800003,67.059998 L103.380005,63.579987 L103.800003,63.100006 L104.160004,63.579987 L113.699997,75.880005 L114.780014,77.260010 L113.159988,76.660004 L98.520004,71.320007 L97.860001,71.079987 L98.279999,70.540009 L98.820007,70.359985 L113.460007,75.700012 L113.159988,76.660004 L112.919998,76.480011 L103.380005,64.179993 L104.160004,63.579987 L104.160004,64.179993 L101.580002,67.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M98.279999,70.539978 L100.800003,67.059967 L101.580002,67.659973 L99.059998,71.139984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.160004,67.359985 L103.740005,63.879974 L113.280014,76.179993 L98.639999,70.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M41.099991,22.479980 L39.959991,24.099976 L100.259995,67.899963 L101.399994,66.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.960007,67.359985 L247.020004,67.179993 L247.139999,67.000000 C247.271011 66.021973,246.263992 65.364990,245.460007 65.979980  L245.220016,66.339996 C244.900009 67.245972,245.794998 68.143982,246.660019 67.599976  L246.780014,67.479980 L246.960007,67.359985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.180008,66.759979 L248.759995,63.339966 L249.120010,62.799988 L249.539993,63.339966 L259.979980,77.259979 L258.299988,76.599976 L243.840012,70.959991 L243.180008,70.719971 L243.600021,70.179993 L244.139999,69.999969 L258.660034,75.639984 L258.299988,76.599976 L258.059998,76.419983 L248.759995,63.939972 L249.539993,63.339966 L249.539993,63.939972 L246.960007,67.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M243.599991,70.179993 L246.179977,66.759979 L246.959976,67.359985 L244.379990,70.779999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.539993,67.059998 L249.119980,63.639984 L258.479980,76.119995 L243.960007,70.480011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.599991,22.479980 L188.399979,24.039978 L245.519974,67.539978 L246.719986,65.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.680008,63.820007 L250.800003,63.700012 L250.919998,63.520020 C251.544998 62.766022,250.547012 61.648010,249.720016 62.080017  L249.539993,62.140015 L249.360001,62.320007 C248.712997 62.994995,249.410995 64.235016,250.320023 63.940002  L250.680008,63.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.080002,62.979980 L253.620010,60.519989 L254.220016,60.159973 L254.400009,60.819977 L259.380005,75.639984 L259.979980,77.259979 L258.599976,76.179993 L246.539993,66.279968 L246.000015,65.859985 L246.539993,65.439972 L247.139999,65.499969 L259.200012,75.399994 L258.599976,76.179993 L258.419983,75.939972 L253.439987,61.119995 L254.400009,60.819977 L254.220016,61.359985 L250.680008,63.819977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.539993,65.440002 L250.080002,62.980011 L250.680008,63.820007 L247.139999,66.279999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.379990,63.399994 L253.919998,60.940002 L258.899963,75.759979 L246.839981,65.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.620010,22.720001 L222.000015,23.860016 L249.300003,63.580017 L250.919998,62.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919998,60.940002 L152.099991,60.940002 L152.279984,60.880005 L152.639999,60.640015 L152.759995,60.519989 L152.879990,60.160004 L152.879990,59.739990 C152.814011 59.429993,152.616989 59.087006,152.279984 59.019989  L152.099991,58.959991 L151.680008,58.959991 C150.741013 59.187012,150.595993 60.444000,151.499985 60.880005  L151.680008,60.940002 L151.919998,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919998,59.979980 L156.840012,59.979980 L156.659988,60.639984 L152.400009,75.579987 L151.919998,77.259979 L151.439987,75.579987 L147.120010,60.639984 L146.939987,59.979980 L147.599991,59.979980 L148.080002,60.339966 L152.400009,75.279968 L151.439987,75.579987 L151.439987,75.279968 L155.699997,60.339966 L156.659988,60.639984 L156.180008,60.999969 L151.919998,60.999969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="147.599991" y="59.980011" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.919998,60.459991 L156.180008,60.459991 L151.919998,75.399994 L147.599991,60.459991" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.960007" y="23.259979" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M142.139999,64.179993 L142.259995,64.059998 L142.379990,63.880005 L142.439987,63.699982 L142.499985,63.519989 L142.499985,63.160004 L142.439987,62.979980 L142.319992,62.799988 L142.199997,62.679993 C141.883011 62.481995,141.712997 62.255005,141.300003 62.440002  L141.120010,62.500000 L140.759995,62.739990 C140.130997 63.498993,140.874985 64.623993,141.780014 64.359985  L141.960007,64.299988 L142.139999,64.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M141.539993,63.459991 L144.960007,60.880005 L145.499985,60.459991 L145.740005,61.119995 L151.319992,75.699982 L151.979996,77.319977 L150.539993,76.239990 L138.059982,66.819977 L137.520004,66.399994 L138.059982,66.039978 L138.659988,66.039978 L151.139999,75.459991 L150.539993,76.239990 L150.360001,76.000000 L144.779984,61.419983 L145.740005,61.119995 L145.559982,61.660004 L142.139999,64.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.060013,66.039978 L141.540024,63.459991 L142.139999,64.239990 L138.660019,66.819977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M141.840012,63.820007 L145.260025,61.240021 L150.840012,75.820007 L138.360001,66.399994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M112.199997,22.660004 L110.639999,23.860016 L140.759995,64.000000 L142.319992,62.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.279999" y="77.259979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.279999" y="77.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="90.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="77.019989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500000" y="77.259979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500000" y="77.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="90.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="77.019989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.779984" y="77.259979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.779984" y="77.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="90.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="77.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.060013" y="77.259979" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.060013" y="77.019989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="90.519989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="77.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.140015" y="9.759979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.140015" y="9.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="23.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="9.519989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.059998,60.940002 L297.239990,60.940002 L297.419983,60.880005 C298.324036 60.444000,298.179016 59.187012,297.239990 58.959991  L296.820007,58.959991 C295.881042 59.187012,295.736023 60.444000,296.640015 60.880005  L296.820007,60.940002 L297.059998,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.059998,59.979980 L301.980042,59.979980 L301.799988,60.639984 L297.540039,75.579987 L297.059998,77.259979 L296.580017,75.579987 L292.260010,60.639984 L292.080017,59.979980 L292.739990,59.979980 L293.220032,60.339966 L297.540039,75.279968 L296.580017,75.579987 L296.580017,75.279968 L300.840027,60.339966 L301.799988,60.639984 L301.320007,60.999969 L297.059998,60.999969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.739990" y="59.980011" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.059998,60.459991 L301.320007,60.459991 L297.059998,75.399994 L292.739990,60.459991" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="296.099976" y="23.259979" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.820007,63.820007 L287.940002,63.700012 L288.059998,63.520020 C288.695007 62.768005,287.671997 61.657013,286.859985 62.080017  L286.679993,62.140015 L286.500000,62.320007 C285.862976 63.029022,286.502991 64.210999,287.460022 63.940002  L287.820007,63.820007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.219971,62.979980 L290.760010,60.519989 L291.359985,60.219971 L291.539978,60.819977 L296.459961,75.639984 L297.059998,77.319977 L295.679993,76.179993 L283.679993,66.279968 L283.140015,65.859985 L283.679993,65.439972 L284.279968,65.499969 L296.279968,75.399994 L295.679993,76.179993 L295.500000,75.939972 L290.579956,61.119995 L291.539978,60.819977 L291.359985,61.359985 L287.820007,63.819977" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.679993,65.440002 L287.220032,62.980011 L287.820007,63.820007 L284.280029,66.279999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M287.520020,63.399994 L291.059998,60.940002 L295.979980,75.759979 L283.979980,65.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.760010,22.720001 L259.140015,23.860016 L286.440002,63.580017 L288.059998,62.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.060013" y="9.759979" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.060013" y="9.519989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="23.019989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="9.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.919998" y="9.759979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.919998" y="9.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="23.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="9.519989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.779984" y="9.759979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.779984" y="9.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="23.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="9.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.639999" y="9.759979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.639999" y="9.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="23.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="9.519989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500000" y="9.759979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500000" y="9.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="23.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="9.519989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.419998" y="9.759979" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.419998" y="9.519989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="9.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="23.019989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="9.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.279999" y="9.759979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.279999" y="9.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="23.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="9.519989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.140015" y="40.119995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.140015" y="39.880005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="40.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="53.380005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="39.880005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.060013" y="40.119995" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.060013" y="39.880005" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="40.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="53.380005" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="39.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.919998" y="40.119995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.919998" y="39.880005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="53.380005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="39.880005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.779984" y="40.119995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.779984" y="39.880005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="40.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="53.380005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="39.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.639999" y="40.119995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.639999" y="39.880005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="53.380005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="39.880005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500000" y="40.119995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500000" y="39.880005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="40.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="53.380005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="39.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.419998" y="40.119995" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.419998" y="39.880005" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="40.119995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="53.380005" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="39.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.279999" y="40.119995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.279999" y="39.880005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="53.380005" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="39.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.140015" y="77.259979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.140015" y="77.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.039978" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="90.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.900024" y="77.019989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.419998" y="77.259979" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.419998" y="77.019989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="77.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="90.519989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.179993" y="77.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.639999" y="77.259979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.639999" y="77.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.539993" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="90.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.400009" y="77.019989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.919998" y="77.259979" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.919998" y="77.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.819992" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="90.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.680008" y="77.019989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M37.139999,60.940002 L37.380005,60.940002 L37.559998,60.880005 L37.679993,60.760010 L37.860001,60.640015 L37.979996,60.519989 L38.100006,60.339996 L38.100006,60.160004 L38.160004,59.920013 L38.100006,59.739990 L38.100006,59.559998 L37.979996,59.380005 L37.679993,59.080017 L37.559998,59.019989 L37.380005,58.959991 L36.960007,58.959991 L36.600006,59.080017 L36.300003,59.380005 L36.179993,59.739990 L36.119995,59.920013 C36.244003 60.300995,36.195999 60.566010,36.600006 60.760010  L36.779999,60.880005 L36.960007,60.940002 L37.139999,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M37.139999,59.979980 L42.119995,59.979980 L41.940002,60.639984 L37.619995,75.579987 L37.139999,77.259979 L36.660004,75.579987 L32.399994,60.639984 L32.220001,59.979980 L32.880005,59.979980 L33.360001,60.339966 L37.619995,75.279968 L36.660004,75.579987 L36.660004,75.279968 L40.979996,60.339966 L41.940002,60.639984 L41.460007,60.999969 L37.139999,60.999969" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.880005" y="59.980011" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M37.139999,60.459991 L41.460007,60.459991 L37.139999,75.399994 L32.880005,60.459991" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.179993" y="53.619995" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M50.880005,68.500000 L51.180008,68.799988 L51.720001,68.980011 L52.260010,68.799988 L52.440002,68.679993 C52.770004 68.234009,52.748001 68.372009,52.740005 67.779999  L52.620010,67.420013 L52.440002,67.239990 C51.719009 66.561005,50.602005 67.178986,50.760010 68.140015  L50.820007,68.320007 L50.880005,68.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M51.720001,67.959991 L54.059998,71.619995 L54.360001,72.220001 L53.759995,72.339996 L38.820007,76.720001 L37.139999,77.259979 L38.279999,75.940002 L48.600006,64.299988 L49.080002,63.759979 L49.440002,64.359985 L49.380005,64.959991 L39.059998,76.600006 L38.279999,75.940002 L38.520004,75.759979 L53.460007,71.380005 L53.759995,72.339996 L53.160004,72.160004 L50.820007,68.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M49.440002,64.359985 L51.720001,67.959991 L50.820007,68.500000 L48.540009,64.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M51.300003,68.199982 L53.639999,71.859985 L38.699997,76.239990 L49.020004,64.599976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M74.819992,54.459991 L73.739990,52.779999 L51.179993,67.119995 L52.259995,68.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.119995,72.100006 L93.179993,72.279999 L93.299988,72.459991 L93.479996,72.580017 L93.599991,72.640015 L93.779999,72.760010 L94.199997,72.760010 L94.559998,72.640015 L94.739990,72.520020 L94.860001,72.399994 L94.979996,72.220001 L95.039993,72.040009 L95.039993,71.440002 L94.919998,71.260010 C94.417999 70.440002,93.224991 70.690002,93.059998 71.679993  L93.059998,71.860016 L93.119995,72.100006" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.080002,71.739990 L95.460007,75.819977 L95.580002,76.479980 L94.979996,76.539978 L79.380005,77.199982 L77.639999,77.259979 L79.080002,76.239990 L91.919998,67.419983 L92.460007,67.059998 L92.699997,67.660004 L92.460007,68.259979 L79.619995,77.079987 L79.080002,76.239990 L79.320007,76.179993 L94.919998,75.519989 L94.979996,76.539978 L94.440002,76.179993 L93.059998,72.099976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.699997,67.660004 L94.080002,71.739990 L93.059998,72.100006 L91.679993,68.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.599991,71.919983 L94.979996,75.999969 L79.379990,76.659973 L92.219986,67.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.800003,54.579987 L148.199997,52.720001 L93.779999,70.839996 L94.380005,72.699982" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M91.380005,68.500000 L91.559998,68.619995 L91.680008,68.799988 L92.220001,68.980011 L92.760010,68.799988 L92.940002,68.679993 C93.270004 68.234009,93.248001 68.372009,93.240005 67.779999  L93.120010,67.420013 L92.940002,67.239990 C92.219009 66.561005,91.102005 67.178986,91.260010 68.140015  L91.320007,68.320007 L91.380005,68.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.220001,67.959991 L94.559998,71.619995 L94.860001,72.220001 L94.259995,72.339996 L79.320007,76.720001 L77.639999,77.259979 L78.779999,75.940002 L89.100006,64.299988 L89.580002,63.759979 L89.940002,64.359985 L89.880005,64.959991 L79.559998,76.600006 L78.779999,75.940002 L79.020004,75.759979 L93.960007,71.380005 L94.259995,72.339996 L93.660004,72.160004 L91.320007,68.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.940002,64.359985 L92.220001,67.959991 L91.320007,68.500000 L89.040009,64.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M91.800003,68.199982 L94.139999,71.859985 L79.199997,76.239990 L89.520004,64.599976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.319992,54.459991 L114.240005,52.779999 L91.679993,67.119995 L92.759995,68.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.360001,61.119995 L183.539993,61.059998 L183.719986,60.940002 L183.900009,60.880005 L184.020004,60.699982 L184.080002,60.519989 L184.199997,60.339996 L184.199997,59.979980 L184.139999,59.799988 L184.080002,59.619995 L183.960007,59.440002 L183.780014,59.320007 L183.659988,59.199982 L183.479996,59.139984 L183.060013,59.139984 L182.699997,59.260010 L182.520004,59.380005 L182.400009,59.500000 L182.280014,59.679993 L182.219986,59.859985 L182.219986,60.279999 L182.340012,60.639984 L182.460007,60.760010 L182.580002,60.940002 L183.120010,61.119995 L183.360001,61.119995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.240005,60.100006 L187.500015,59.500000 L188.160019,59.500000 L188.039993,60.100006 L185.880020,75.580017 L185.639999,77.320007 L184.979996,75.700012 L178.620010,61.480011 L178.319992,60.880005 L178.979996,60.760010 L179.520004,61.059998 L185.880020,75.279999 L184.979996,75.700012 L184.919998,75.399994 L187.080002,59.920013 L188.039993,60.100006 L187.620010,60.520020 L183.360001,61.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.979996,60.759979 L183.240005,60.099976 L183.360001,61.119965 L179.099991,61.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.300003,60.579987 L187.560013,59.979980 L185.400009,75.459991 L179.039993,61.239990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.300003,53.500000 L181.319992,53.799988 L182.220016,60.279999 L184.199997,59.980011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.020004,67.899994 L199.139999,68.019989 L199.319992,68.139984 C200.085007 68.722992,201.108994 67.885986,200.759995 66.940002  L200.520004,66.579987 C199.741013 65.992981,198.669998 66.514008,198.840012 67.540009  L198.900009,67.720001 L199.020004,67.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.860001,67.299988 L202.319992,70.839996 L202.620010,71.440002 L202.020004,71.619995 L187.259995,76.659973 L185.639999,77.259979 L186.719986,75.879974 L196.560013,63.759979 L196.979996,63.220001 L197.400009,63.759979 L197.340012,64.359985 L187.500015,76.479980 L186.719986,75.879974 L186.960007,75.699982 L201.719986,70.659973 L202.020004,71.619995 L201.479996,71.440002 L199.020004,67.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M197.400009,63.759979 L199.860001,67.299988 L199.020004,67.899994 L196.560013,64.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.439987,67.600006 L201.899979,71.140015 L187.139999,76.179993 L196.979996,64.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.020004,54.459991 L218.879990,52.839996 L199.319992,66.519989 L200.460007,68.139984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.259995,72.100006 L238.319992,72.279999 L238.439987,72.459991 C239.063980 73.110016,240.345993 72.664001,240.180008 71.679993  L240.119980,71.440002 L240.059982,71.260010 L239.939987,71.080017 L239.819992,70.959991 L239.639999,70.899994 L239.460007,70.779999 L239.099991,70.779999 L238.860001,70.839996 L238.680008,70.899994 L238.559982,71.020020 L238.379990,71.140015 L238.319992,71.320007 L238.199997,71.679993 L238.199997,71.860016 L238.259995,72.100006" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.219986,71.739990 L240.539993,75.819977 L240.659988,76.479980 L240.059982,76.539978 L224.519974,77.199982 L222.779984,77.259979 L224.219986,76.239990 L237.059982,67.419983 L237.599991,67.059998 L237.839981,67.660004 L237.599991,68.259979 L224.759995,77.079987 L224.219986,76.239990 L224.459976,76.179993 L239.999985,75.519989 L240.059982,76.539978 L239.519974,76.179993 L238.199997,72.099976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.840012,67.660004 L239.220016,71.739990 L238.199997,72.100006 L236.820023,68.019989" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M238.740005,71.919983 L240.060013,75.999969 L224.520004,76.659973 L237.360001,67.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M293.940002,54.579987 L293.339966,52.720001 L238.919998,70.839996 L239.519974,72.699982" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.159988,67.899994 L236.399979,68.139984 C237.157974 68.785004,238.269974 67.781006,237.899979 66.940002  L237.659988,66.579987 C236.880997 65.992981,235.809982 66.514008,235.979996 67.540009  L236.039993,67.720001 L236.159988,67.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.939987,67.299988 L239.459976,70.839996 L239.759995,71.440002 L239.159988,71.619995 L224.399979,76.659973 L222.779984,77.259979 L223.860001,75.879974 L233.639999,63.759979 L234.059982,63.220001 L234.479996,63.759979 L234.419998,64.359985 L224.639999,76.479980 L223.860001,75.879974 L224.099991,75.699982 L238.860001,70.659973 L239.159988,71.619995 L238.619980,71.440002 L236.099991,67.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.479996,63.759979 L236.939987,67.299988 L236.099991,67.899994 L233.639999,64.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.520004,67.600006 L239.039993,71.140015 L224.280014,76.179993 L234.060013,64.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.159973,54.459991 L256.019958,52.839996 L236.399979,66.519989 L237.539993,68.139984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="224.153275" y="85.779999" textLength="5.530430" font-size="8px">Y</text>
<text x="219.347519" y="85.779999" textLength="4.842236" font-size="8px">+</text>
<text x="214.773941" y="85.779999" textLength="4.610074" font-size="8px">0</text>
<text x="209.279984" y="85.779999" textLength="5.530430" font-size="8px">Y</text>
<text x="156.956955" y="85.779999" textLength="4.170000" font-size="8px">5</text>
<text x="151.958969" y="85.779999" textLength="5.002500" font-size="8px">X</text>
<text x="143.417984" y="85.779999" textLength="4.170000" font-size="8px">4</text>
<text x="79.317001" y="85.779999" textLength="4.170000" font-size="8px">5</text>
<text x="74.319000" y="85.779999" textLength="5.002500" font-size="8px">Y</text>
<text x="60.779999" y="85.779999" textLength="5.002500" font-size="8px">Y</text>
<text x="302.096985" y="87.399994" textLength="4.170000" font-size="8px">1</text>
<text x="297.098999" y="87.399994" textLength="5.002500" font-size="8px">X</text>
<text x="288.557983" y="87.399994" textLength="4.170000" font-size="8px">0</text>
<text x="283.559998" y="87.399994" textLength="5.002500" font-size="8px">X</text>
<text x="36.360001" y="48.639984" textLength="4.170000" font-size="8px">7</text>
<text x="68.459991" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="110.639999" y="48.639984" textLength="4.170000" font-size="8px">5</text>
<text x="105.599991" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="147.780014" y="48.639984" textLength="4.170000" font-size="8px">4</text>
<text x="142.740005" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="184.860001" y="48.639984" textLength="4.170000" font-size="8px">3</text>
<text x="179.879990" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="221.940018" y="48.639984" textLength="4.170000" font-size="8px">2</text>
<text x="216.960007" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="254.099991" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="31.380005" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="68.459991" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="105.599991" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="142.740005" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="184.860001" y="18.279999" textLength="4.170000" font-size="8px">3</text>
<text x="221.940018" y="18.279999" textLength="4.170000" font-size="8px">2</text>
<text x="216.960007" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="254.099991" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="15.778503" y="50.259979" textLength="4.170000" font-size="8px">2</text>
<text x="4.984497" y="50.259979" textLength="5.415000" font-size="8px">R</text>
<text x="0.000000" y="50.259979" textLength="5.002500" font-size="8px">S</text>
<text x="296.280029" y="18.279999" textLength="4.170000" font-size="8px">0</text>
<text x="291.239990" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="10.678497" y="19.899994" textLength="5.415000" font-size="8px">C</text>
<text x="0.300003" y="19.899994" textLength="5.002500" font-size="8px">S</text>
<text x="15.357010" y="85.779999" textLength="4.582500" font-size="8px">T</text>
<text x="10.375504" y="85.779999" textLength="5.002500" font-size="8px">S</text>
<text x="5.393997" y="85.779999" textLength="5.002500" font-size="8px">E</text>
<text x="0.000000" y="85.779999" textLength="5.415000" font-size="8px">D</text>
<text x="264.956970" y="87.399994" textLength="4.170000" font-size="8px">3</text>
<text x="251.417984" y="87.399994" textLength="4.170000" font-size="8px">2</text>
<text x="246.419998" y="87.399994" textLength="5.002500" font-size="8px">X</text>
<text x="186.968521" y="85.779999" textLength="5.530430" font-size="8px">Y</text>
<text x="177.619034" y="85.779999" textLength="4.610074" font-size="8px">2</text>
<text x="119.816971" y="85.779999" textLength="4.170000" font-size="8px">7</text>
<text x="114.818985" y="85.779999" textLength="5.002500" font-size="8px">X</text>
<text x="110.443497" y="85.779999" textLength="4.380000" font-size="8px">+</text>
<text x="106.278000" y="85.779999" textLength="4.170000" font-size="8px">6</text>
<text x="101.279999" y="85.779999" textLength="5.002500" font-size="8px">X</text>
<text x="42.177002" y="85.779999" textLength="4.170000" font-size="8px">7</text>
<text x="37.179001" y="85.779999" textLength="5.002500" font-size="8px">Y</text>
<text x="32.803497" y="85.779999" textLength="4.380000" font-size="8px">+</text>
<text x="65.778000" y="85.779999" textLength="4.170000" font-size="8px">4</text>
<text x="259.080017" y="18.279999" textLength="4.170000" font-size="8px">1</text>
<text x="229.613235" y="85.779999" textLength="4.610074" font-size="8px">1</text>
<text x="16.136993" y="19.899994" textLength="4.170000" font-size="8px">1</text>
<text x="291.239990" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="292.723511" y="87.399994" textLength="4.380000" font-size="8px">+</text>
<text x="69.943497" y="85.779999" textLength="4.380000" font-size="8px">+</text>
<text x="192.488998" y="85.779999" textLength="4.610074" font-size="8px">3</text>
<text x="10.381500" y="50.259979" textLength="5.415000" font-size="8px">C</text>
<text x="179.879990" y="18.279999" textLength="5.002500" font-size="8px">X</text>
<text x="259.958984" y="87.399994" textLength="5.002500" font-size="8px">X</text>
<text x="255.583481" y="87.399994" textLength="4.380000" font-size="8px">+</text>
<text x="31.380005" y="48.639984" textLength="5.002500" font-size="8px">Y</text>
<text x="296.280029" y="48.639984" textLength="4.170000" font-size="8px">0</text>
<text x="23.639999" y="85.779999" textLength="5.002500" font-size="8px">Y</text>
<text x="147.780014" y="18.279999" textLength="4.170000" font-size="8px">4</text>
<text x="259.080017" y="48.639984" textLength="4.170000" font-size="8px">1</text>
<text x="138.419998" y="85.779999" textLength="5.002500" font-size="8px">X</text>
<text x="182.177689" y="85.779999" textLength="4.842236" font-size="8px">+</text>
<text x="172.139999" y="85.779999" textLength="5.530430" font-size="8px">Y</text>
<text x="36.360001" y="18.279999" textLength="4.170000" font-size="8px">7</text>
<text x="73.439987" y="48.639984" textLength="4.170000" font-size="8px">6</text>
<text x="28.638000" y="85.779999" textLength="4.170000" font-size="8px">6</text>
<text x="73.439987" y="18.279999" textLength="4.170000" font-size="8px">6</text>
<text x="147.583481" y="85.779999" textLength="4.380000" font-size="8px">+</text>
<text x="5.283005" y="19.899994" textLength="5.415000" font-size="8px">R</text>
<text x="110.639999" y="18.279999" textLength="4.170000" font-size="8px">5</text>
</svg>
<figcaption>Figure 3-19.  VHADDPS operation
</figcaption></figure>
```

### Operation
#### HADDPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0]  <- SRC1[63:32] + SRC1[31:0]
DEST[63:32] <-  SRC1[127:96] + SRC1[95:64]
DEST[95:64] <-  SRC2[63:32] + SRC2[31:0]
DEST[127:96] <-  SRC2[127:96] + SRC2[95:64] 
DEST[VLMAX-1:128] (Unmodified)
```
#### VHADDPS (VEX.128 encoded version)
```info-verb
DEST[31:0]  <- SRC1[63:32] + SRC1[31:0]
DEST[63:32] <-  SRC1[127:96] + SRC1[95:64]
DEST[95:64]  <- SRC2[63:32] + SRC2[31:0]
DEST[127:96]  <- SRC2[127:96] + SRC2[95:64] 
DEST[VLMAX-1:128] <-  0
```
#### VHADDPS (VEX.256 encoded version)
```info-verb
DEST[31:0]  <- SRC1[63:32] + SRC1[31:0]
DEST[63:32]  <- SRC1[127:96] + SRC1[95:64]
DEST[95:64]  <- SRC2[63:32] + SRC2[31:0]
DEST[127:96] <-  SRC2[127:96] + SRC2[95:64] 
DEST[159:128] <-  SRC1[191:160] + SRC1[159:128]
DEST[191:160] <-  SRC1[255:224] + SRC1[223:192]
DEST[223:192]  <- SRC2[191:160] + SRC2[159:128]
DEST[255:224]  <- SRC2[255:224] + SRC2[223:192]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
HADDPS:  __m128 _mm_hadd_ps (__m128 a, __m128 b);
VHADDPS:__m256 _mm256_hadd_ps (__m256 a, __m256 b);
```
### Exceptions


When the source operand is a memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated.

### Numeric Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


See Exceptions Type 2.

