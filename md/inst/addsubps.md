----------------------------
title : ADDSUBPS (Intel x86/64 assembly instruction)
cat_title : ADDSUBPS
ref_title : ADDSUBPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/A
publish_date: 2020-09-01
----------------------------


#@ ADDSUBPS

**Packed Single-FP Add/Subtract**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|F2 0F D0 /r\newline{}\newline{}ADDSUBPS xmm1, xmm2/m128|RM|V/V|SSE3|Add/subtract single-precision floating-point values from xmm2/m128 to xmm1.|
|VEX.NDS.128.F2.0F.WIG D0 /r\newline{}\newline{}VADDSUBPS xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Add/subtract single-precision floating-point values from xmm3/mem to xmm2 and stores result in xmm1.|
|VEX.NDS.256.F2.0F.WIG D0 /r\newline{}\newline{}VADDSUBPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Add / subtract single-precision floating-point values from ymm3/mem to ymm2 and stores result in ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Adds odd-numbered single-precision floating-point values of the first source operand (second operand) with the corresponding single-precision floating-point values from the second source operand (third operand); stores the result in the odd-numbered values of the destination operand (first operand). Subtracts the even-numbered single-precision floating-point values from the second source operand from the corresponding single-precision floating values in the first source operand; stores the result into the even-numbered values of the destination operand.

In 64-bit mode, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified. See Figure 3-4.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 

```embed
<figure>
<svg viewBox="0 0 370.200012 276.119995">
<rect x="0.000000" y="9.256958" width="370.200012" height="163.440002" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.749001" y="10.000000" width="360.015015" height="139.505997" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.749001" y="149.505981" width="360.015015" height="-139.505997" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.510010,79.092957 L277.510010,62.881958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M280.269989,78.732971 L277.509979,84.252991 L274.750000,78.732971 L280.269989,78.732971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="239.259003" y="84.252991" width="76.502998" height="38.251999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="239.259003" y="122.505005" width="76.502998" height="-38.251999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="239.259003" y="35.875977" width="76.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="239.259003" y="62.876953" width="76.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M201.006989,79.092957 L201.006989,62.881958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M203.766998,78.732971 L201.006989,84.252991 L198.247009,78.732971 L203.766998,78.732971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.756012" y="84.252991" width="76.502998" height="38.251999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="162.756012" y="122.505005" width="76.502998" height="-38.251999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.756012" y="35.875977" width="76.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="162.756012" y="62.876953" width="76.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M124.503998,79.092957 L124.503998,62.881958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M127.264008,78.732971 L124.504013,84.252991 L121.744003,78.732971 L127.264008,78.732971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="86.253006" y="84.252991" width="76.502998" height="38.251999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="86.253006" y="122.505005" width="76.502998" height="-38.251999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="86.253006" y="35.875977" width="76.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="86.253006" y="62.876953" width="76.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M48.001007,79.092957 L48.001007,62.881958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M50.761002,78.732971 L48.001007,84.252991 L45.240997,78.732971 L50.761002,78.732971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="9.749001" y="84.252991" width="76.502998" height="38.251999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="9.749001" y="122.505005" width="76.502998" height="-38.251999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="9.749001" y="35.875977" width="76.502998" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="9.749001" y="62.876953" width="76.502998" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<text x="274.181946" y="133.855286" textLength="4.448167" font-size="8px">1</text>
<text x="269.733765" y="133.855286" textLength="4.448167" font-size="8px">3</text>
<text x="267.509674" y="133.855286" textLength="2.224083" font-size="8px">[</text>
<text x="206.579376" y="133.855286" textLength="4.448167" font-size="8px">2</text>
<text x="199.907104" y="133.855286" textLength="2.224083" font-size="8px">:</text>
<text x="188.786652" y="133.855286" textLength="2.224083" font-size="8px">[</text>
<text x="114.507874" y="133.855286" textLength="4.448167" font-size="8px">9</text>
<text x="60.239426" y="133.855286" textLength="2.224083" font-size="8px">]</text>
<text x="55.791260" y="133.855286" textLength="4.448167" font-size="8px">6</text>
<text x="49.119003" y="133.855286" textLength="2.224083" font-size="8px">:</text>
<text x="44.670837" y="133.855286" textLength="4.448167" font-size="8px">7</text>
<text x="35.774506" y="133.855286" textLength="4.448167" font-size="8px">1</text>
<text x="60.229019" y="51.776978" textLength="2.224083" font-size="8px">]</text>
<text x="51.332687" y="51.776978" textLength="4.448167" font-size="8px">9</text>
<text x="40.212265" y="51.776978" textLength="4.448167" font-size="8px">2</text>
<text x="35.764099" y="51.776978" textLength="4.448167" font-size="8px">1</text>
<text x="80.181488" y="110.584290" textLength="2.021894" font-size="8px">]</text>
<text x="76.137695" y="110.584290" textLength="4.043788" font-size="8px">6</text>
<text x="72.093903" y="110.584290" textLength="4.043788" font-size="8px">9</text>
<text x="61.984421" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="57.940628" y="110.584290" textLength="4.043788" font-size="8px">1</text>
<text x="55.918732" y="110.584290" textLength="2.021894" font-size="8px">[</text>
<text x="47.831146" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="43.787354" y="110.584290" textLength="4.043788" font-size="8px">1</text>
<text x="35.707047" y="110.584290" textLength="2.021894" font-size="8px">/</text>
<text x="19.546432" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="70.763672" y="100.983948" textLength="4.247432" font-size="8px">+</text>
<text x="58.632294" y="100.983948" textLength="4.043788" font-size="8px">9</text>
<text x="56.610397" y="100.983948" textLength="2.021894" font-size="8px">:</text>
<text x="48.522812" y="100.983948" textLength="4.043788" font-size="8px">2</text>
<text x="42.457123" y="100.983948" textLength="2.021894" font-size="8px">[</text>
<text x="32.354919" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="26.296509" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="22.660004" y="100.983948" textLength="3.636500" font-size="8px">x</text>
<text x="134.514847" y="51.776978" textLength="2.224083" font-size="8px">]</text>
<text x="130.066681" y="51.776978" textLength="4.448167" font-size="8px">4</text>
<text x="123.394424" y="51.776978" textLength="2.224083" font-size="8px">:</text>
<text x="118.946259" y="51.776978" textLength="4.448167" font-size="8px">5</text>
<text x="114.498093" y="51.776978" textLength="4.448167" font-size="8px">9</text>
<text x="112.274002" y="51.776978" textLength="2.224083" font-size="8px">[</text>
<text x="139.298874" y="110.584290" textLength="4.043788" font-size="8px">4</text>
<text x="38.413330" y="100.983948" textLength="4.043788" font-size="8px">1</text>
<text x="129.189392" y="110.584290" textLength="4.043788" font-size="8px">5</text>
<text x="44.660431" y="51.776978" textLength="4.448167" font-size="8px">7</text>
<text x="125.145599" y="110.584290" textLength="4.043788" font-size="8px">9</text>
<text x="123.123703" y="110.584290" textLength="2.021894" font-size="8px">[</text>
<text x="115.036118" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="110.992325" y="110.584290" textLength="4.043788" font-size="8px">1</text>
<text x="158.773804" y="100.983948" textLength="2.021894" font-size="8px">/</text>
<text x="154.730011" y="100.983948" textLength="4.043788" font-size="8px">2</text>
<text x="138.976685" y="100.983948" textLength="3.636500" font-size="8px">x</text>
<text x="136.954788" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="130.489090" y="100.983948" textLength="2.021894" font-size="8px">]</text>
<text x="126.445297" y="100.983948" textLength="4.043788" font-size="8px">4</text>
<text x="122.401505" y="100.983948" textLength="4.043788" font-size="8px">6</text>
<text x="116.335815" y="100.983948" textLength="4.043788" font-size="8px">5</text>
<text x="49.108597" y="51.776978" textLength="2.224083" font-size="8px">:</text>
<text x="110.270126" y="100.983948" textLength="2.021894" font-size="8px">[</text>
<text x="106.226334" y="100.983948" textLength="4.043788" font-size="8px">1</text>
<text x="94.109512" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="211.017914" y="51.776978" textLength="2.224083" font-size="8px">]</text>
<text x="206.569733" y="51.776978" textLength="4.448167" font-size="8px">2</text>
<text x="227.059875" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="206.840942" y="110.584290" textLength="4.043788" font-size="8px">8</text>
<text x="186.629272" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="180.570862" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="174.512451" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="280.854218" y="133.855286" textLength="4.448167" font-size="8px">0</text>
<text x="199.897461" y="51.776978" textLength="2.224083" font-size="8px">:</text>
<text x="221.685822" y="100.983948" textLength="4.247432" font-size="8px">+</text>
<text x="225.933258" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="217.642059" y="100.983948" textLength="2.021894" font-size="8px">]</text>
<text x="197.423126" y="100.983948" textLength="2.021894" font-size="8px">[</text>
<text x="187.320923" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="181.262512" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="177.626007" y="100.983948" textLength="3.636500" font-size="8px">x</text>
<text x="274.172272" y="51.776978" textLength="4.448167" font-size="8px">1</text>
<text x="269.724091" y="51.776978" textLength="4.448167" font-size="8px">3</text>
<text x="267.500000" y="51.776978" textLength="2.224083" font-size="8px">[</text>
<text x="291.369568" y="110.584290" textLength="4.043788" font-size="8px">3</text>
<text x="281.260101" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="265.092224" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="259.033813" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="252.975403" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="249.338898" y="110.584290" textLength="3.636500" font-size="8px">x</text>
<text x="299.406921" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="296.985016" y="100.983948" textLength="2.421909" font-size="8px">-</text>
<text x="294.963135" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="288.897461" y="100.983948" textLength="4.043788" font-size="8px">0</text>
<text x="276.766113" y="100.983948" textLength="2.021894" font-size="8px">[</text>
<text x="272.722321" y="100.983948" textLength="4.043788" font-size="8px">1</text>
<text x="266.663910" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="260.605499" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="256.968994" y="100.983948" textLength="3.636500" font-size="8px">x</text>
<text x="331.324524" y="56.577881" textLength="4.448167" font-size="8px">2</text>
<text x="337.540741" y="46.977539" textLength="4.448167" font-size="8px">2</text>
<text x="330.876495" y="46.977539" textLength="6.664250" font-size="8px">m</text>
<text x="337.540741" y="110.579956" textLength="4.448167" font-size="8px">1</text>
<text x="66.719879" y="100.983948" textLength="2.021894" font-size="8px">]</text>
<text x="330.876495" y="110.579956" textLength="6.664250" font-size="8px">m</text>
<text x="320.212097" y="110.579956" textLength="4.000150" font-size="8px">x</text>
<text x="350.293243" y="100.979614" textLength="2.224083" font-size="8px">:</text>
<text x="342.436951" y="100.979614" textLength="4.448167" font-size="8px">L</text>
<text x="336.660736" y="100.979614" textLength="5.776217" font-size="8px">U</text>
<text x="325.988312" y="100.979614" textLength="5.336200" font-size="8px">E</text>
<text x="320.212097" y="100.979614" textLength="5.776217" font-size="8px">R</text>
<text x="212.100098" y="26.463989" textLength="4.448167" font-size="8px">2</text>
<text x="207.651917" y="26.463989" textLength="4.448167" font-size="8px">1</text>
<text x="198.763580" y="26.463989" textLength="2.224083" font-size="8px">/</text>
<text x="194.315399" y="26.463989" textLength="4.448167" font-size="8px">2</text>
<text x="187.651154" y="26.463989" textLength="6.664250" font-size="8px">m</text>
<text x="180.986908" y="26.463989" textLength="6.664250" font-size="8px">m</text>
<text x="176.986755" y="26.463989" textLength="4.000150" font-size="8px">x</text>
<text x="172.538574" y="26.463989" textLength="2.224083" font-size="8px">,</text>
<text x="195.449280" y="51.776978" textLength="4.448167" font-size="8px">3</text>
<text x="168.090393" y="26.463989" textLength="4.448167" font-size="8px">1</text>
<text x="161.426147" y="26.463989" textLength="6.664250" font-size="8px">m</text>
<text x="154.761902" y="26.463989" textLength="6.664250" font-size="8px">m</text>
<text x="150.761749" y="26.463989" textLength="4.000150" font-size="8px">x</text>
<text x="148.537659" y="26.463989" textLength="2.224083" font-size="8px"> </text>
<text x="143.201447" y="26.463989" textLength="5.336200" font-size="8px">S</text>
<text x="137.865234" y="26.463989" textLength="5.336200" font-size="8px">P</text>
<text x="115.640411" y="26.463989" textLength="5.776217" font-size="8px">D</text>
<text x="104.528000" y="26.463989" textLength="5.336200" font-size="8px">A</text>
<text x="358.277802" y="163.805969" textLength="3.336111" font-size="8px">2</text>
<text x="354.941681" y="163.805969" textLength="3.336111" font-size="8px">9</text>
<text x="348.269440" y="163.805969" textLength="3.336111" font-size="8px">5</text>
<text x="335.266998" y="163.805969" textLength="4.668155" font-size="8px">O</text>
<text x="219.663940" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="132.510986" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="112.283783" y="133.855286" textLength="2.224083" font-size="8px">[</text>
<text x="51.343094" y="133.855286" textLength="4.448167" font-size="8px">9</text>
<text x="90.473007" y="100.983948" textLength="3.636500" font-size="8px">x</text>
<text x="134.532883" y="100.983948" textLength="2.421909" font-size="8px">-</text>
<text x="305.522827" y="110.584290" textLength="2.021894" font-size="8px">]</text>
<text x="37.728943" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="277.216309" y="110.584290" textLength="4.043788" font-size="8px">1</text>
<text x="123.404205" y="133.855286" textLength="2.224083" font-size="8px">:</text>
<text x="118.956039" y="133.855286" textLength="4.448167" font-size="8px">5</text>
<text x="170.875946" y="110.584290" textLength="3.636500" font-size="8px">x</text>
<text x="51.874939" y="110.584290" textLength="4.043788" font-size="8px">8</text>
<text x="286.875580" y="100.983948" textLength="2.021894" font-size="8px">:</text>
<text x="198.753357" y="110.584290" textLength="4.043788" font-size="8px">1</text>
<text x="193.379333" y="100.983948" textLength="4.043788" font-size="8px">1</text>
<text x="112.292023" y="100.983948" textLength="4.043788" font-size="8px">9</text>
<text x="33.540009" y="51.776978" textLength="2.224083" font-size="8px">[</text>
<text x="195.458923" y="133.855286" textLength="4.448167" font-size="8px">3</text>
<text x="75.011108" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="220.994202" y="110.584290" textLength="2.021894" font-size="8px">:</text>
<text x="271.157898" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="25.604843" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="31.663254" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="100.167923" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="33.550415" y="133.855286" textLength="2.224083" font-size="8px">[</text>
<text x="121.416626" y="26.463989" textLength="5.336200" font-size="8px">S</text>
<text x="223.016083" y="110.584290" textLength="4.043788" font-size="8px">3</text>
<text x="130.076462" y="133.855286" textLength="4.448167" font-size="8px">4</text>
<text x="52.566605" y="100.983948" textLength="4.043788" font-size="8px">7</text>
<text x="44.479019" y="100.983948" textLength="4.043788" font-size="8px">1</text>
<text x="40.222672" y="133.855286" textLength="4.448167" font-size="8px">2</text>
<text x="192.694946" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="174.762665" y="26.463989" textLength="2.224083" font-size="8px"> </text>
<text x="341.988922" y="46.977539" textLength="2.224083" font-size="8px">/</text>
<text x="134.524628" y="133.855286" textLength="2.224083" font-size="8px">]</text>
<text x="335.772705" y="56.577881" textLength="4.448167" font-size="8px">8</text>
<text x="68.741776" y="100.983948" textLength="2.021894" font-size="8px"> </text>
<text x="142.613190" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="278.630127" y="133.855286" textLength="2.224083" font-size="8px">:</text>
<text x="320.212097" y="46.977539" textLength="4.000150" font-size="8px">x</text>
<text x="216.548279" y="26.463989" textLength="4.448167" font-size="8px">8</text>
<text x="351.605560" y="163.805969" textLength="3.336111" font-size="8px">9</text>
<text x="133.233185" y="110.584290" textLength="2.021894" font-size="8px">:</text>
<text x="278.620453" y="51.776978" textLength="2.224083" font-size="8px">:</text>
<text x="191.001099" y="51.776978" textLength="4.448167" font-size="8px">6</text>
<text x="202.797150" y="110.584290" textLength="4.043788" font-size="8px">2</text>
<text x="295.413361" y="110.584290" textLength="4.043788" font-size="8px">1</text>
<text x="104.933914" y="110.584290" textLength="6.058409" font-size="8px">m</text>
<text x="285.302399" y="133.855286" textLength="2.224083" font-size="8px">]</text>
<text x="301.479034" y="110.584290" textLength="4.043788" font-size="8px">0</text>
<text x="126.752823" y="26.463989" textLength="5.776217" font-size="8px">U</text>
<text x="211.027557" y="133.855286" textLength="2.224083" font-size="8px">]</text>
<text x="280.844543" y="51.776978" textLength="4.448167" font-size="8px">0</text>
<text x="346.293091" y="100.979614" textLength="4.888184" font-size="8px">T</text>
<text x="231.103668" y="110.584290" textLength="2.021894" font-size="8px">]</text>
<text x="285.292725" y="51.776978" textLength="2.224083" font-size="8px">]</text>
<text x="125.628296" y="133.855286" textLength="4.448167" font-size="8px">6</text>
<text x="212.906616" y="110.584290" textLength="4.043788" font-size="8px">6</text>
<text x="148.671600" y="100.983948" textLength="6.058409" font-size="8px">m</text>
<text x="188.777008" y="51.776978" textLength="2.224083" font-size="8px">[</text>
<text x="339.935150" y="163.805969" textLength="4.998167" font-size="8px">M</text>
<text x="200.987671" y="26.463989" textLength="6.664250" font-size="8px">m</text>
<text x="320.212097" y="56.577881" textLength="6.664250" font-size="8px">m</text>
<text x="269.136017" y="110.584290" textLength="2.021894" font-size="8px">/</text>
<text x="66.028214" y="110.584290" textLength="4.043788" font-size="8px">7</text>
<text x="289.347687" y="110.584290" textLength="2.021894" font-size="8px">[</text>
<text x="62.676086" y="100.983948" textLength="4.043788" font-size="8px">6</text>
<text x="15.909927" y="110.584290" textLength="3.636500" font-size="8px">x</text>
<text x="120.379608" y="100.983948" textLength="2.021894" font-size="8px">:</text>
<text x="278.787994" y="100.983948" textLength="4.043788" font-size="8px">3</text>
<text x="282.831787" y="100.983948" textLength="4.043788" font-size="8px">1</text>
<text x="324.212250" y="110.579956" textLength="6.664250" font-size="8px">m</text>
<text x="125.618515" y="51.776978" textLength="4.448167" font-size="8px">6</text>
<text x="213.598267" y="100.983948" textLength="4.043788" font-size="8px">2</text>
<text x="299.457153" y="110.584290" textLength="2.021894" font-size="8px">:</text>
<text x="109.864197" y="26.463989" textLength="5.776217" font-size="8px">D</text>
<text x="190.673065" y="110.584290" textLength="2.021894" font-size="8px">/</text>
<text x="119.079910" y="110.584290" textLength="4.043788" font-size="8px">8</text>
<text x="285.303894" y="110.584290" textLength="4.043788" font-size="8px">8</text>
<text x="209.554474" y="100.983948" textLength="4.043788" font-size="8px">3</text>
<text x="143.342651" y="110.584290" textLength="2.021894" font-size="8px">]</text>
<text x="326.876343" y="56.577881" textLength="4.448167" font-size="8px">1</text>
<text x="55.780853" y="51.776978" textLength="4.448167" font-size="8px">6</text>
<text x="292.941254" y="100.983948" textLength="2.021894" font-size="8px">]</text>
<text x="331.324524" y="100.979614" textLength="5.336200" font-size="8px">S</text>
<text x="70.072006" y="110.584290" textLength="2.021894" font-size="8px">:</text>
<text x="135.255081" y="110.584290" textLength="4.043788" font-size="8px">6</text>
<text x="132.529037" y="26.463989" textLength="5.336200" font-size="8px">B</text>
<text x="216.950409" y="110.584290" textLength="4.043788" font-size="8px">3</text>
<text x="191.010742" y="133.855286" textLength="4.448167" font-size="8px">6</text>
<text x="324.212250" y="46.977539" textLength="6.664250" font-size="8px">m</text>
<text x="203.488800" y="100.983948" textLength="4.043788" font-size="8px">3</text>
<text x="202.121552" y="51.776978" textLength="4.448167" font-size="8px">3</text>
<text x="207.532593" y="100.983948" textLength="2.021894" font-size="8px">:</text>
<text x="199.445007" y="100.983948" textLength="4.043788" font-size="8px">6</text>
<text x="202.131195" y="133.855286" textLength="4.448167" font-size="8px">3</text>
<text x="210.884735" y="110.584290" textLength="2.021894" font-size="8px">[</text>
<text x="344.933319" y="163.805969" textLength="3.336111" font-size="8px">1</text>
</svg>
<figcaption>Figure 3-4.  ADDSUBPS--Packed Single-FP Add/Subtract
</figcaption></figure>
```

### Operation
#### ADDSUBPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  DEST[31:0] - SRC[31:0]
DEST[63:32] <-  DEST[63:32] + SRC[63:32]
DEST[95:64] <-  DEST[95:64] - SRC[95:64]
DEST[127:96] <-  DEST[127:96] + SRC[127:96]
DEST[VLMAX-1:128] (Unmodified)
```
#### VADDSUBPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] + SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] - SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] + SRC2[127:96]
DEST[VLMAX-1:128] <-  0
```
#### VADDSUBPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC1[31:0] - SRC2[31:0]
DEST[63:32] <-  SRC1[63:32] + SRC2[63:32]
DEST[95:64] <-  SRC1[95:64] - SRC2[95:64]
DEST[127:96] <-  SRC1[127:96] + SRC2[127:96]
DEST[159:128] <-  SRC1[159:128] - SRC2[159:128]
DEST[191:160]<-  SRC1[191:160] + SRC2[191:160]
DEST[223:192] <-  SRC1[223:192] - SRC2[223:192]
DEST[255:224] <-  SRC1[255:224] + SRC2[255:224].
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
ADDSUBPS: __m128 _mm_addsub_ps(__m128 a, __m128 b)
VADDSUBPS: __m256 _mm256_addsub_ps (__m256 a, __m256 b)
```
### Exceptions


When the source operand is a memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated.

### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal.

### Other Exceptions


See Exceptions Type 2.

