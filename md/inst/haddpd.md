----------------------------
title : HADDPD (Intel x86/64 assembly instruction)
cat_title : HADDPD
ref_title : HADDPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/H
publish_date: 2020-09-01
----------------------------


#@ HADDPD

**Packed Double-FP Horizontal Add**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`66 0F 7C /r`\newline{}`HADDPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE3|Horizontal add packed double-precision floating-point values from xmm2/m128 to xmm1.|
|`VEX.NDS.128.66.0F.WIG 7C /r`\newline{}VHADDPD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Horizontal add packed double-precision floating-point values from xmm2 and xmm3/mem.|
|`VEX.NDS.256.66.0F.WIG 7C /r`\newline{}VHADDPD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX|Horizontal add packed double-precision floating-point values from ymm2 and ymm3/mem.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Adds the double-precision floating-point values in the high and low quadwords of the destination operand and stores the result in the low quadword of the destination operand. 

Adds the double-precision floating-point values in the high and low quadwords of the source operand and stores the result in the high quadword of the destination operand. 

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).

See Figure 3-16 for HADDPD; see Figure 3-17 for VHADDPD.

```embed
<figure>
<svg viewBox="0 0 338.279999 254.660004">
<rect x="0.000000" y="9.265991" width="338.279999" height="209.220001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.682007" y="10.000000" width="331.565002" height="181.255997" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.682007" y="191.255997" width="331.565002" height="-181.255997" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.833008" y="35.421021" width="132.626007" height="26.525000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="159.833008" y="61.945007" width="132.626007" height="-26.525000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="27.207001" y="35.421021" width="132.626007" height="26.525000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="27.207001" y="61.945007" width="132.626007" height="-26.525000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.833008" y="82.945007" width="132.626007" height="26.525000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="159.833008" y="109.470001" width="132.626007" height="-26.525000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="27.207001" y="82.945007" width="132.626007" height="26.525000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="27.207001" y="109.470001" width="132.626007" height="-26.525000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.520004,135.347000 L93.520004,129.363998 L13.944000,129.363998 L13.944000,72.442993 L226.146027,72.442993 L226.146027,61.941010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M96.232010,134.992996 L93.520004,140.416000 L90.809006,134.992996 L96.232010,134.992996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="27.207001" y="140.417007" width="132.626007" height="26.525000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="27.207001" y="166.940994" width="132.626007" height="-26.525000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.833008" y="140.417007" width="132.626007" height="26.525000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="159.833008" y="166.940994" width="132.626007" height="-26.525000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M226.145996,135.347000 L226.145996,120.522003 L93.519989,120.522003 L93.519989,109.470001" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M228.858002,134.992996 L226.147003,140.416000 L223.434998,134.992996 L228.858002,134.992996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M93.520004,61.946014 L93.520004,72.448029" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M226.146027,109.470016 L226.146027,120.522018" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="265.128693" y="156.037003" textLength="4.369771" font-size="8px">6</text>
<text x="258.574036" y="156.037003" textLength="4.369771" font-size="8px">7</text>
<text x="254.204254" y="156.037003" textLength="4.369771" font-size="8px">2</text>
<text x="249.834473" y="156.037003" textLength="4.369771" font-size="8px">1</text>
<text x="247.649597" y="156.037003" textLength="2.184886" font-size="8px">[</text>
<text x="226.256592" y="156.037003" textLength="3.929650" font-size="8px">x</text>
<text x="224.071716" y="156.037003" textLength="2.184886" font-size="8px"> </text>
<text x="219.481873" y="156.037003" textLength="4.589831" font-size="8px">+</text>
<text x="217.296997" y="156.037003" textLength="2.184886" font-size="8px"> </text>
<text x="210.742340" y="156.037003" textLength="4.369771" font-size="8px">0</text>
<text x="204.187683" y="156.037003" textLength="4.369771" font-size="8px">3</text>
<text x="197.633026" y="156.037003" textLength="2.184886" font-size="8px">[</text>
<text x="193.263245" y="156.037003" textLength="4.369771" font-size="8px">1</text>
<text x="186.716461" y="156.037003" textLength="6.546797" font-size="8px">m</text>
<text x="180.169678" y="156.037003" textLength="6.546797" font-size="8px">m</text>
<text x="176.240021" y="156.037003" textLength="3.929650" font-size="8px">x</text>
<text x="116.229797" y="160.752167" textLength="2.184886" font-size="8px">:</text>
<text x="103.120499" y="160.752167" textLength="4.369771" font-size="8px">1</text>
<text x="100.935608" y="160.752167" textLength="2.184886" font-size="8px">[</text>
<text x="96.565842" y="160.752167" textLength="4.369771" font-size="8px">8</text>
<text x="74.724854" y="160.752167" textLength="4.369771" font-size="8px">2</text>
<text x="68.178055" y="160.752167" textLength="6.546797" font-size="8px">m</text>
<text x="61.631256" y="160.752167" textLength="6.546797" font-size="8px">m</text>
<text x="123.766876" y="151.320999" textLength="4.589831" font-size="8px">+</text>
<text x="121.581985" y="151.320999" textLength="2.184886" font-size="8px"> </text>
<text x="115.027328" y="151.320999" textLength="4.369771" font-size="8px">0</text>
<text x="112.842438" y="151.320999" textLength="2.184886" font-size="8px">:</text>
<text x="101.918015" y="151.320999" textLength="2.184886" font-size="8px">[</text>
<text x="97.548248" y="151.320999" textLength="4.369771" font-size="8px">8</text>
<text x="69.160461" y="151.320999" textLength="6.546797" font-size="8px">m</text>
<text x="58.684006" y="151.320999" textLength="3.929650" font-size="8px">x</text>
<text x="314.738739" y="160.751724" textLength="4.369771" font-size="8px">1</text>
<text x="308.191956" y="160.751724" textLength="6.546797" font-size="8px">m</text>
<text x="297.715515" y="160.751724" textLength="3.929650" font-size="8px">x</text>
<text x="319.988770" y="151.320557" textLength="2.184886" font-size="8px">:</text>
<text x="311.689362" y="151.320557" textLength="4.369771" font-size="8px">u</text>
<text x="307.759705" y="151.320557" textLength="3.929650" font-size="8px">s</text>
<text x="303.389923" y="151.320557" textLength="4.369771" font-size="8px">e</text>
<text x="90.239426" y="98.565002" textLength="4.369771" font-size="8px">7</text>
<text x="85.869659" y="98.565002" textLength="4.369771" font-size="8px">2</text>
<text x="81.499893" y="98.565002" textLength="4.369771" font-size="8px">1</text>
<text x="79.315002" y="98.565002" textLength="2.184886" font-size="8px">[</text>
<text x="227.236450" y="98.565002" textLength="2.184886" font-size="8px">:</text>
<text x="222.866669" y="98.565002" textLength="4.369771" font-size="8px">3</text>
<text x="218.496887" y="98.565002" textLength="4.369771" font-size="8px">6</text>
<text x="238.222992" y="179.259201" textLength="2.184886" font-size="8px">]</text>
<text x="231.668335" y="179.259201" textLength="2.184886" font-size="8px">:</text>
<text x="227.298553" y="179.259201" textLength="4.369771" font-size="8px">3</text>
<text x="220.743896" y="179.259201" textLength="2.184886" font-size="8px">[</text>
<text x="105.543839" y="179.259201" textLength="2.184886" font-size="8px">]</text>
<text x="101.174072" y="179.259201" textLength="4.369771" font-size="8px">4</text>
<text x="85.879883" y="179.259201" textLength="4.369771" font-size="8px">2</text>
<text x="81.510117" y="179.259201" textLength="4.369771" font-size="8px">1</text>
<text x="79.325226" y="179.259201" textLength="2.184886" font-size="8px">[</text>
<text x="105.533615" y="51.041016" textLength="2.184886" font-size="8px">]</text>
<text x="96.794083" y="51.041016" textLength="4.369771" font-size="8px">6</text>
<text x="94.609192" y="51.041016" textLength="2.184886" font-size="8px">:</text>
<text x="90.239426" y="51.041016" textLength="4.369771" font-size="8px">7</text>
<text x="81.499893" y="51.041016" textLength="4.369771" font-size="8px">1</text>
<text x="79.315002" y="51.041016" textLength="2.184886" font-size="8px">[</text>
<text x="233.791107" y="51.041016" textLength="2.184886" font-size="8px">]</text>
<text x="229.421326" y="51.041016" textLength="4.369771" font-size="8px">0</text>
<text x="227.236450" y="51.041016" textLength="2.184886" font-size="8px">:</text>
<text x="222.866669" y="51.041016" textLength="4.369771" font-size="8px">3</text>
<text x="216.312012" y="51.041016" textLength="2.184886" font-size="8px">[</text>
<text x="310.816498" y="55.756409" textLength="4.369771" font-size="8px">2</text>
<text x="306.446716" y="55.756409" textLength="4.369771" font-size="8px">1</text>
<text x="308.191498" y="46.325256" textLength="6.546797" font-size="8px">m</text>
<text x="301.644714" y="46.325256" textLength="6.546797" font-size="8px">m</text>
<text x="314.738281" y="98.565247" textLength="4.369771" font-size="8px">1</text>
<text x="308.191498" y="98.565247" textLength="6.546797" font-size="8px">m</text>
<text x="301.644714" y="98.565247" textLength="6.546797" font-size="8px">m</text>
<text x="207.645813" y="26.174011" textLength="4.369771" font-size="8px">8</text>
<text x="203.276031" y="26.174011" textLength="4.369771" font-size="8px">2</text>
<text x="198.906250" y="26.174011" textLength="4.369771" font-size="8px">1</text>
<text x="185.804810" y="26.174011" textLength="4.369771" font-size="8px">2</text>
<text x="108.472672" y="151.320999" textLength="4.369771" font-size="8px">3</text>
<text x="172.711243" y="26.174011" textLength="6.546797" font-size="8px">m</text>
<text x="164.411835" y="26.174011" textLength="2.184886" font-size="8px">,</text>
<text x="160.042053" y="26.174011" textLength="4.369771" font-size="8px">1</text>
<text x="153.495270" y="26.174011" textLength="6.546797" font-size="8px">m</text>
<text x="146.948486" y="26.174011" textLength="6.546797" font-size="8px">m</text>
<text x="143.018829" y="26.174011" textLength="3.929650" font-size="8px">x</text>
<text x="140.833954" y="26.174011" textLength="2.184886" font-size="8px"> </text>
<text x="124.242981" y="26.174011" textLength="5.674415" font-size="8px">D</text>
<text x="118.568573" y="26.174011" textLength="5.674415" font-size="8px">D</text>
<text x="113.326416" y="26.174011" textLength="5.242153" font-size="8px">A</text>
<text x="107.652008" y="26.174011" textLength="5.674415" font-size="8px">H</text>
<text x="330.341003" y="209.725998" textLength="3.277287" font-size="8px">3</text>
<text x="320.509155" y="209.725998" textLength="3.277287" font-size="8px">5</text>
<text x="323.786438" y="209.725998" textLength="3.277287" font-size="8px">9</text>
<text x="317.231873" y="209.725998" textLength="3.277287" font-size="8px">1</text>
<text x="307.735992" y="209.725998" textLength="4.585843" font-size="8px">O</text>
<text x="216.312012" y="98.565002" textLength="2.184886" font-size="8px">[</text>
<text x="92.196075" y="160.752167" textLength="4.369771" font-size="8px">2</text>
<text x="96.804306" y="179.259201" textLength="4.369771" font-size="8px">6</text>
<text x="297.715057" y="46.325256" textLength="3.929650" font-size="8px">x</text>
<text x="111.860031" y="160.752167" textLength="4.369771" font-size="8px">7</text>
<text x="90.249649" y="179.259201" textLength="4.369771" font-size="8px">7</text>
<text x="297.715057" y="98.565247" textLength="3.929650" font-size="8px">x</text>
<text x="233.791107" y="98.565002" textLength="2.184886" font-size="8px">]</text>
<text x="316.059143" y="151.320557" textLength="1.744765" font-size="8px">l</text>
<text x="190.174591" y="26.174011" textLength="2.184886" font-size="8px">/</text>
<text x="81.279510" y="160.752167" textLength="6.546797" font-size="8px">m</text>
<text x="301.645172" y="160.751724" textLength="6.546797" font-size="8px">m</text>
<text x="179.258026" y="26.174011" textLength="6.546797" font-size="8px">m</text>
<text x="299.899933" y="55.756409" textLength="6.546797" font-size="8px">m</text>
<text x="118.414688" y="160.752167" textLength="4.369771" font-size="8px">6</text>
<text x="135.159546" y="26.174011" textLength="5.674415" font-size="8px">D</text>
<text x="192.359467" y="26.174011" textLength="6.546797" font-size="8px">m</text>
<text x="297.715515" y="151.320557" textLength="5.674415" font-size="8px">R</text>
<text x="222.928772" y="179.259201" textLength="4.369771" font-size="8px">6</text>
<text x="243.279816" y="156.037003" textLength="4.369771" font-size="8px">1</text>
<text x="297.715057" y="55.756409" textLength="2.184886" font-size="8px">/</text>
<text x="236.733032" y="156.037003" textLength="6.546797" font-size="8px">m</text>
<text x="85.869659" y="51.041016" textLength="4.369771" font-size="8px">2</text>
<text x="122.784454" y="160.752167" textLength="4.369771" font-size="8px">4</text>
<text x="229.421326" y="98.565002" textLength="4.369771" font-size="8px">0</text>
<text x="230.186249" y="156.037003" textLength="6.546797" font-size="8px">m</text>
<text x="94.619415" y="179.259201" textLength="2.184886" font-size="8px">:</text>
<text x="107.490265" y="160.752167" textLength="4.369771" font-size="8px">2</text>
<text x="119.397095" y="151.320999" textLength="2.184886" font-size="8px">]</text>
<text x="218.496887" y="51.041016" textLength="4.369771" font-size="8px">6</text>
<text x="208.557465" y="156.037003" textLength="2.184886" font-size="8px">:</text>
<text x="127.154236" y="160.752167" textLength="2.184886" font-size="8px">]</text>
<text x="315.186279" y="55.756409" textLength="4.369771" font-size="8px">8</text>
<text x="57.701599" y="160.752167" textLength="3.929650" font-size="8px">x</text>
<text x="93.178482" y="151.320999" textLength="4.369771" font-size="8px">2</text>
<text x="199.817902" y="156.037003" textLength="4.369771" font-size="8px">6</text>
<text x="168.781586" y="26.174011" textLength="3.929650" font-size="8px">x</text>
<text x="104.102905" y="151.320999" textLength="4.369771" font-size="8px">6</text>
<text x="105.533615" y="98.565002" textLength="2.184886" font-size="8px">]</text>
<text x="101.163849" y="98.565002" textLength="4.369771" font-size="8px">4</text>
<text x="94.609192" y="98.565002" textLength="2.184886" font-size="8px">:</text>
<text x="312.321838" y="209.725998" textLength="4.910035" font-size="8px">M</text>
<text x="233.853210" y="179.259201" textLength="4.369771" font-size="8px">0</text>
<text x="317.803894" y="151.320557" textLength="2.184886" font-size="8px">t</text>
<text x="101.163849" y="51.041016" textLength="4.369771" font-size="8px">4</text>
<text x="166.596710" y="26.174011" textLength="2.184886" font-size="8px"> </text>
<text x="96.794083" y="98.565002" textLength="4.369771" font-size="8px">6</text>
<text x="129.917389" y="26.174011" textLength="5.242153" font-size="8px">P</text>
<text x="262.943817" y="156.037003" textLength="2.184886" font-size="8px">:</text>
<text x="215.112122" y="156.037003" textLength="2.184886" font-size="8px">]</text>
<text x="75.707260" y="151.320999" textLength="4.369771" font-size="8px">2</text>
<text x="314.738281" y="46.325256" textLength="4.369771" font-size="8px">2</text>
<text x="82.261917" y="151.320999" textLength="6.546797" font-size="8px">m</text>
<text x="88.808716" y="151.320999" textLength="4.369771" font-size="8px">1</text>
<text x="269.498474" y="156.037003" textLength="4.369771" font-size="8px">4</text>
<text x="62.613663" y="151.320999" textLength="6.546797" font-size="8px">m</text>
<text x="80.077026" y="151.320999" textLength="2.184886" font-size="8px">/</text>
<text x="273.868256" y="156.037003" textLength="2.184886" font-size="8px">]</text>
<text x="327.063721" y="209.725998" textLength="3.277287" font-size="8px">9</text>
<text x="79.094620" y="160.752167" textLength="2.184886" font-size="8px">/</text>
<text x="87.826309" y="160.752167" textLength="4.369771" font-size="8px">1</text>
</svg>
<figcaption>Figure 3-16.  HADDPD--Packed Double-FP Horizontal Add
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 317.460022 253.320007">
<rect x="20.220001" y="77.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.220001" y="77.019958" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="77.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="90.519958" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="77.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500000" y="77.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500000" y="77.019958" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="77.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="90.519958" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="77.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.720001" y="77.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.720001" y="77.019958" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="77.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="90.519958" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="77.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000000" y="77.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.000000" y="77.019958" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.979980" y="77.260010" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="90.519958" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="77.020020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.220001" y="9.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.220001" y="9.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="9.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="23.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="9.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500000" y="9.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500000" y="9.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="23.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="9.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.799988,67.659973 L121.919983,67.479980 L121.979980,67.299988 C122.129974 66.289978,121.080994 65.742981,120.299988 66.339966  L120.179993,66.459961 L120.059998,66.639954 C119.656982 67.687988,120.875977 68.424988,121.500000 67.899963  L121.679993,67.779968 L121.799988,67.659973" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.019989,67.059998 L123.539978,63.580017 L123.959991,63.099976 L124.319977,63.580017 L133.919983,75.880005 L135.000000,77.260010 L133.379974,76.659973 L118.739990,71.320007 L118.079987,71.080017 L118.500000,70.539978 L119.039978,70.359985 L133.679993,75.700012 L133.379974,76.659973 L133.139984,76.479980 L123.539978,64.179993 L124.319977,63.580017 L124.319977,64.179993 L121.799988,67.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.500000,70.539978 L121.019989,67.059998 L121.799988,67.659973 L119.279999,71.139954" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.380005,67.359985 L123.899994,63.880005 L133.500000,76.179993 L118.860016,70.839966" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M61.319992,22.479980 L60.179993,24.099976 L120.479980,67.899963 L121.619995,66.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.720001" y="9.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.720001" y="9.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="9.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="23.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="9.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000000" y="9.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.000000" y="9.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.979980" y="9.760010" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="23.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="9.520020" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.500000,60.940002 L283.679993,60.940002 L283.859985,60.880005 C284.792999 60.458008,284.674988 59.223022,283.679993 58.960022  L283.320007,58.960022 L283.079987,59.020020 L282.959991,59.140015 L282.779999,59.260010 L282.660004,59.380005 L282.600006,59.559998 L282.540009,59.739990 L282.480011,59.919983 C282.604004 60.301025,282.556000 60.565979,282.959991 60.760010  L283.079987,60.880005 L283.320007,60.940002 L283.500000,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.500000,59.979980 L288.480011,59.979980 L288.299988,60.639954 L283.980011,75.639954 L283.500000,77.320007 L283.019989,75.639954 L278.700012,60.639954 L278.519989,59.979980 L279.179993,59.979980 L279.660004,60.339966 L283.980011,75.339966 L283.019989,75.639954 L283.019989,75.339966 L287.339996,60.339966 L288.299988,60.639954 L287.820007,61.000000 L283.500000,61.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.179993" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.500000,60.459961 L287.820007,60.459961 L283.500000,75.459961 L279.179993,60.459961" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.540009" y="23.260010" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="60.720001" y="49.299988" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="209.220001" y="49.299988" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.220001" y="40.119995" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.220001" y="39.879944" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="40.119995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="53.379944" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="39.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.500000" y="40.119995" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.500000" y="39.879944" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="40.119995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="53.379944" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.259995" y="39.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.720001" y="40.119995" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.720001" y="39.879944" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="40.119995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="53.379944" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479980" y="39.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000000" y="40.119995" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="243.000000" y="39.879944" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.979980" y="40.119995" width="0.480040" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="53.379944" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.759979" y="39.880005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.119995,67.959961 L270.239990,67.599976 C270.566986 66.696960,269.319000 65.937988,268.619995 66.639954  L268.440002,66.819946 L268.380005,66.999939 C267.932983 67.930969,269.190002 68.743958,269.820007 68.199951  L270.000000,68.079956 L270.119995,67.959961" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M269.279999,67.359985 L271.739990,63.820007 L272.160004,63.279968 L272.579987,63.820007 L282.420013,75.940002 L283.500000,77.320007 L281.880005,76.719971 L267.119995,71.679993 L266.459991,71.440002 L266.820007,70.899963 L267.420013,70.719971 L282.179993,75.760010 L281.880005,76.719971 L281.639984,76.539978 L271.799988,64.419983 L272.579987,63.820007 L272.579987,64.419983 L270.119995,67.959961" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M266.820007,70.899963 L269.279999,67.359985 L270.119995,67.959961 L267.660004,71.499939" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M269.699982,67.659973 L272.159973,64.119995 L281.999969,76.239990 L267.239990,71.199951" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.459991,22.479980 L205.319977,24.099976 L268.739990,68.199951 L269.879974,66.579956" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M135.000000,60.940002 L135.179993,60.940002 L135.359985,60.880005 L135.720001,60.640015 L135.839996,60.520020 L135.959991,60.159973 L135.959991,59.739990 C135.783997 59.181030,135.867004 59.383972,135.359985 59.020020  L135.179993,58.960022 L134.760010,58.960022 C133.803986 59.283020,133.667999 60.377991,134.579987 60.880005  L134.760010,60.940002 L135.000000,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M135.000000,59.979980 L139.920013,59.979980 L139.739990,60.639954 L135.480011,75.639954 L135.000000,77.320007 L134.519989,75.639954 L130.200012,60.639954 L130.019989,59.979980 L130.679993,59.979980 L131.160004,60.339966 L135.480011,75.339966 L134.519989,75.639954 L134.519989,75.339966 L138.779999,60.339966 L139.739990,60.639954 L139.260010,61.000000 L135.000000,61.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.679993" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M135.000000,60.459961 L139.260010,60.459961 L135.000000,75.459961 L130.679993,60.459961" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.040009" y="23.260010" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.360001,60.940002 L57.539993,60.940002 L57.720001,60.880005 C58.653000 60.458008,58.535004 59.223022,57.539993 58.960022  L57.180008,58.960022 L56.940002,59.020020 L56.820007,59.140015 L56.639999,59.260010 L56.520004,59.380005 L56.460007,59.559998 L56.399994,59.739990 L56.339996,59.919983 C56.464005 60.301025,56.416000 60.565979,56.820007 60.760010  L56.940002,60.880005 L57.180008,60.940002 L57.360001,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.360001,59.979980 L62.339996,59.979980 L62.160004,60.639954 L57.839996,75.639954 L57.360001,77.320007 L56.880005,75.639954 L52.559998,60.639954 L52.380005,59.979980 L53.039993,59.979980 L53.520004,60.339966 L57.839996,75.339966 L56.880005,75.639954 L56.880005,75.339966 L61.199997,60.339966 L62.160004,60.639954 L61.680008,61.000000 L57.360001,61.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.039993" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.360001,60.459961 L61.680008,60.459961 L57.360001,75.459961 L53.039993,60.459961" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.399994" y="53.619995" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.859985,60.940002 L206.039978,60.940002 L206.279999,60.880005 L206.399994,60.760010 L206.579987,60.640015 L206.699982,60.520020 L206.819977,60.159973 L206.879974,59.919983 L206.819977,59.739990 L206.759979,59.559998 L206.699982,59.380005 L206.579987,59.260010 L206.399994,59.140015 L206.279999,59.020020 L206.039978,58.960022 L205.679993,58.960022 C204.684998 59.223022,204.566986 60.458008,205.500000 60.880005  L205.679993,60.940002 L205.859985,60.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.859985,59.979980 L210.839996,59.979980 L210.659973,60.639954 L206.339996,75.639954 L205.859985,77.320007 L205.379974,75.639954 L201.059998,60.639954 L200.879974,59.979980 L201.539978,59.979980 L202.019989,60.339966 L206.339996,75.339966 L205.379974,75.639954 L205.379974,75.339966 L209.699982,60.339966 L210.659973,60.639954 L210.179993,61.000000 L205.859985,61.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.540009" y="59.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.859985,60.459961 L210.179993,60.459961 L205.859985,75.459961 L201.539978,60.459961" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.899994" y="53.619995" width="1.980000" height="6.300000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.839996,72.099976 L72.899994,72.279968 L73.019989,72.459961 C73.684998 73.115967,74.865997 72.664978,74.759995 71.679993  L74.699997,71.440002 L74.639999,71.259949 L74.519989,71.139954 L74.399994,70.959961 L73.860001,70.779968 L73.679993,70.779968 L73.440002,70.839966 C73.098999 70.922974,72.927002 71.210999,72.779999 71.500000  L72.779999,71.919983 L72.839996,72.099976" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.799988,71.739990 L75.119995,75.820007 L75.239990,76.479980 L74.639984,76.539978 L59.099991,77.200012 L57.359985,77.260010 L58.799988,76.239990 L71.639984,67.419983 L72.179993,67.059998 L72.419983,67.659973 L72.179993,68.260010 L59.339981,77.080017 L58.799988,76.239990 L59.039993,76.179993 L74.579987,75.520020 L74.639984,76.539978 L74.099991,76.179993 L72.779984,72.099976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.419998,67.659973 L73.800003,71.739990 L72.779999,72.099976 L71.399994,68.019958" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.319992,71.919983 L74.639999,76.000000 L59.099991,76.659973 L71.939987,67.839966" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M128.519989,54.580017 L127.919983,52.720032 L73.499985,70.900024 L74.099991,72.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.639984,71.859985 L224.699982,72.039978 L224.819977,72.219971 L224.999969,72.339966 L225.119995,72.459961 L225.299988,72.519958 L225.719971,72.519958 L226.079987,72.399963 L226.259979,72.279968 L226.379974,72.099976 L226.499969,71.979980 L226.559998,71.799988 L226.559998,71.380005 L226.439972,71.019958 C225.939972 70.112000,224.544983 70.583008,224.579987 71.440002  L224.579987,71.679993 L224.639984,71.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.600006,71.500000 L226.980011,75.580017 L227.100006,76.239990 L226.500000,76.299988 L210.959991,77.200012 L209.220001,77.260010 L210.660004,76.239990 L223.380005,67.239990 L223.920013,66.880005 L224.160004,67.479980 L223.980011,68.080017 L211.260010,77.080017 L210.660004,76.239990 L210.899994,76.179993 L226.440002,75.280029 L226.500000,76.299988 L226.020020,75.940002 L224.640015,71.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.160004,67.479980 L225.600006,71.500000 L224.640015,71.859985 L223.140015,67.839966" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.119995,71.679993 L226.500000,75.760010 L210.959991,76.659973 L223.679993,67.659973" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M277.079987,54.580017 L276.419983,52.720032 L225.299988,70.660034 L225.959991,72.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="15.778534" y="50.260010" textLength="4.170000" font-size="8px">2</text>
<text x="4.984528" y="50.260010" textLength="5.415000" font-size="8px">R</text>
<text x="278.820007" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="61.079987" y="48.640015" textLength="4.170000" font-size="8px">3</text>
<text x="56.099991" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="278.820007" y="18.279968" textLength="5.002500" font-size="8px">X</text>
<text x="209.580017" y="18.279968" textLength="4.170000" font-size="8px">1</text>
<text x="16.076996" y="19.899963" textLength="4.170000" font-size="8px">1</text>
<text x="130.320007" y="18.279968" textLength="5.002500" font-size="8px">X</text>
<text x="10.375504" y="85.779968" textLength="5.002500" font-size="8px">S</text>
<text x="289.331970" y="85.779968" textLength="4.170000" font-size="8px">1</text>
<text x="271.625977" y="85.779968" textLength="4.170000" font-size="8px">0</text>
<text x="210.046478" y="85.779968" textLength="5.002500" font-size="8px">Y</text>
<text x="207.944977" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="203.583740" y="85.779968" textLength="4.380000" font-size="8px">+</text>
<text x="197.343750" y="85.779968" textLength="4.170000" font-size="8px">0</text>
<text x="192.359985" y="85.779968" textLength="5.002500" font-size="8px">Y</text>
<text x="140.771973" y="85.779968" textLength="4.170000" font-size="8px">3</text>
<text x="135.785980" y="85.779968" textLength="5.002500" font-size="8px">X</text>
<text x="127.219482" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="123.065979" y="85.779968" textLength="4.170000" font-size="8px">2</text>
<text x="66.530258" y="85.779968" textLength="4.170000" font-size="8px">3</text>
<text x="61.546509" y="85.779968" textLength="5.002500" font-size="8px">Y</text>
<text x="48.843750" y="85.779968" textLength="4.170000" font-size="8px">2</text>
<text x="209.580017" y="48.640015" textLength="4.170000" font-size="8px">1</text>
<text x="283.800018" y="18.279968" textLength="4.170000" font-size="8px">0</text>
<text x="10.618500" y="19.899963" textLength="5.415000" font-size="8px">C</text>
<text x="55.083755" y="85.779968" textLength="4.380000" font-size="8px">+</text>
<text x="284.345978" y="85.779968" textLength="5.002500" font-size="8px">X</text>
<text x="135.300018" y="48.640015" textLength="4.170000" font-size="8px">2</text>
<text x="204.600006" y="18.279968" textLength="5.002500" font-size="8px">X</text>
<text x="5.223007" y="19.899963" textLength="5.415000" font-size="8px">R</text>
<text x="282.244476" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="283.800018" y="48.640015" textLength="4.170000" font-size="8px">0</text>
<text x="201.542236" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="59.445007" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="130.320007" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="61.079987" y="18.279968" textLength="4.170000" font-size="8px">3</text>
<text x="277.880981" y="85.779968" textLength="4.380000" font-size="8px">+</text>
<text x="5.393997" y="85.779968" textLength="5.002500" font-size="8px">E</text>
<text x="15.357010" y="85.779968" textLength="4.582500" font-size="8px">T</text>
<text x="204.600006" y="48.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="275.779480" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="215.030243" y="85.779968" textLength="4.170000" font-size="8px">1</text>
<text x="0.000031" y="50.260010" textLength="5.002500" font-size="8px">S</text>
<text x="266.639984" y="85.779968" textLength="5.002500" font-size="8px">X</text>
<text x="0.240005" y="19.899963" textLength="5.002500" font-size="8px">S</text>
<text x="133.684479" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="53.042252" y="85.779968" textLength="2.085000" font-size="8px"> </text>
<text x="118.079987" y="85.779968" textLength="5.002500" font-size="8px">X</text>
<text x="0.000000" y="85.779968" textLength="5.415000" font-size="8px">D</text>
<text x="129.320984" y="85.779968" textLength="4.380000" font-size="8px">+</text>
<text x="43.860001" y="85.779968" textLength="5.002500" font-size="8px">Y</text>
<text x="135.300018" y="18.279968" textLength="4.170000" font-size="8px">2</text>
<text x="56.099991" y="18.279968" textLength="5.002500" font-size="8px">X</text>
<text x="10.381531" y="50.260010" textLength="5.415000" font-size="8px">C</text>
</svg>
<figcaption>Figure 3-17.  VHADDPD operation
</figcaption></figure>
```


128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 


### Operation
#### HADDPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-  SRC1[127:64] + SRC1[63:0]
DEST[127:64] <-  SRC2[127:64] + SRC2[63:0]
DEST[VLMAX-1:128] (Unmodified)
```
#### VHADDPD (VEX.128 encoded version)
```info-verb
DEST[63:0] <-  SRC1[127:64] + SRC1[63:0]
DEST[127:64] <-  SRC2[127:64] + SRC2[63:0]
DEST[VLMAX-1:128] <-  0
```
#### VHADDPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  SRC1[127:64] + SRC1[63:0]
DEST[127:64] <-  SRC2[127:64] + SRC2[63:0]
DEST[191:128] <-  SRC1[255:192] + SRC1[191:128]
DEST[255:192] <-  SRC2[255:192] + SRC2[191:128]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VHADDPD: __m256d _mm256_hadd_pd (__m256d a, __m256d b);
HADDPD: __m128d _mm_hadd_pd (__m128d a, __m128d b);
```
### Exceptions


When the source operand is a memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

### Numeric Exceptions


Overflow, Underflow, Invalid, Precision, Denormal

### Other Exceptions


See Exceptions Type 2.

