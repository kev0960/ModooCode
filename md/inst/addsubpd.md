----------------------------
title : ADDSUBPD (Intel x86/64 assembly instruction)
cat_title : ADDSUBPD
ref_title : ADDSUBPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/A
publish_date: 2020-09-01
----------------------------
#@ ADDSUBPD

**Packed Double-FP Add/Subtract**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|66 0F D0 /r\newline{}\newline{}ADDSUBPD xmm1, xmm2/m128|RM|V/V|SSE3|Add/subtract double-precision floating-point values from xmm2/m128 to xmm1.|
|VEX.NDS.128.66.0F.WIG D0 /r\newline{}\newline{}VADDSUBPD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Add/subtract packed double-precision floating-point values from xmm3/mem to xmm2 and stores result in xmm1.|
|VEX.NDS.256.66.0F.WIG D0 /r\newline{}\newline{}VADDSUBPD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Add / subtract packed double-precision floating-point values from ymm3/mem to ymm2 and stores result in ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Adds odd-numbered double-precision floating-point values of the first source operand (second operand) with the corresponding double-precision floating-point values from the second source operand (third operand); stores the result in the odd-numbered values of the destination operand (first operand). Subtracts the even-numbered double-precision floating-point values from the second source operand from the corresponding double-precision floating values in the first source operand; stores the result into the even-numbered values of the destination operand. 

In 64-bit mode, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified. See Figure 3-3.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 

```embed
<figure>
<svg viewBox="0 0 360.779968 265.140015">
<rect x="0.000000" y="9.256958" width="360.779999" height="138.990005" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.722992" y="10.000000" width="360.015015" height="126.004997" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="0.722992" y="136.005005" width="360.015015" height="-126.004997" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="14.222992" y="35.875977" width="144.005997" height="27.000999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="14.222992" y="62.876953" width="144.005997" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="14.222992" y="84.252991" width="144.005997" height="27.000999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="14.222992" y="111.253967" width="144.005997" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="158.228989" y="84.252991" width="144.005997" height="27.000999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="158.228989" y="111.253967" width="144.005997" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="158.228989" y="35.875977" width="144.005997" height="27.000999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="158.228989" y="62.876953" width="144.005997" height="-27.000999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M86.225998,79.092957 L86.225998,62.881958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M88.985992,78.732971 L86.225998,84.252991 L83.465988,78.732971 L88.985992,78.732971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M230.232010,79.092957 L230.232010,62.881958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M232.991989,78.732971 L230.231979,84.252991 L227.472000,78.732971 L232.991989,78.732971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<text x="341.347534" y="51.776672" textLength="4.448167" font-size="8px">2</text>
<text x="336.899353" y="51.776672" textLength="4.448167" font-size="8px">1</text>
<text x="330.235107" y="51.776672" textLength="6.664250" font-size="8px">m</text>
<text x="328.011047" y="51.776672" textLength="2.224083" font-size="8px">/</text>
<text x="316.898621" y="51.776672" textLength="6.664250" font-size="8px">m</text>
<text x="310.234375" y="51.776672" textLength="6.664250" font-size="8px">m</text>
<text x="306.234192" y="51.776672" textLength="4.000150" font-size="8px">x</text>
<text x="316.898621" y="104.953857" textLength="6.664250" font-size="8px">m</text>
<text x="336.315369" y="95.353516" textLength="2.224083" font-size="8px">:</text>
<text x="328.459045" y="95.353516" textLength="4.448167" font-size="8px">L</text>
<text x="322.682861" y="95.353516" textLength="5.776217" font-size="8px">U</text>
<text x="312.010437" y="95.353516" textLength="5.336200" font-size="8px">E</text>
<text x="306.234192" y="95.353516" textLength="5.776217" font-size="8px">R</text>
<text x="212.241135" y="26.463745" textLength="4.448167" font-size="8px">8</text>
<text x="203.344772" y="26.463745" textLength="4.448167" font-size="8px">1</text>
<text x="190.008255" y="26.463745" textLength="4.448167" font-size="8px">2</text>
<text x="170.455521" y="26.463745" textLength="2.224083" font-size="8px"> </text>
<text x="168.231430" y="26.463745" textLength="2.224083" font-size="8px">,</text>
<text x="157.119003" y="26.463745" textLength="6.664250" font-size="8px">m</text>
<text x="150.454758" y="26.463745" textLength="6.664250" font-size="8px">m</text>
<text x="146.454605" y="26.463745" textLength="4.000150" font-size="8px">x</text>
<text x="144.230515" y="26.463745" textLength="2.224083" font-size="8px"> </text>
<text x="127.781876" y="26.463745" textLength="5.336200" font-size="8px">B</text>
<text x="122.005661" y="26.463745" textLength="5.776217" font-size="8px">U</text>
<text x="116.669464" y="26.463745" textLength="5.336200" font-size="8px">S</text>
<text x="110.893250" y="26.463745" textLength="5.776217" font-size="8px">D</text>
<text x="105.117035" y="26.463745" textLength="5.776217" font-size="8px">D</text>
<text x="99.780838" y="26.463745" textLength="5.336200" font-size="8px">A</text>
<text x="238.023697" y="123.804993" textLength="2.224083" font-size="8px">]</text>
<text x="231.351425" y="123.804993" textLength="2.224083" font-size="8px">:</text>
<text x="226.903244" y="123.804993" textLength="4.448167" font-size="8px">3</text>
<text x="222.455063" y="123.804993" textLength="4.448167" font-size="8px">6</text>
<text x="220.230972" y="123.804993" textLength="2.224083" font-size="8px">[</text>
<text x="89.567673" y="123.804993" textLength="4.448167" font-size="8px">6</text>
<text x="87.343582" y="123.804993" textLength="2.224083" font-size="8px">:</text>
<text x="196.680527" y="26.463745" textLength="6.664250" font-size="8px">m</text>
<text x="78.447250" y="123.804993" textLength="4.448167" font-size="8px">2</text>
<text x="71.774994" y="123.804993" textLength="2.224083" font-size="8px">[</text>
<text x="238.014725" y="51.776978" textLength="2.224083" font-size="8px">]</text>
<text x="233.566544" y="51.776978" textLength="4.448167" font-size="8px">0</text>
<text x="226.894272" y="51.776978" textLength="4.448167" font-size="8px">3</text>
<text x="222.446091" y="51.776978" textLength="4.448167" font-size="8px">6</text>
<text x="220.222000" y="51.776978" textLength="2.224083" font-size="8px">[</text>
<text x="277.806091" y="100.153992" textLength="2.224083" font-size="8px">:</text>
<text x="273.357910" y="100.153992" textLength="4.448167" font-size="8px">3</text>
<text x="266.685608" y="100.153992" textLength="2.224083" font-size="8px">[</text>
<text x="262.237427" y="100.153992" textLength="4.448167" font-size="8px">8</text>
<text x="257.789246" y="100.153992" textLength="4.448167" font-size="8px">2</text>
<text x="253.341080" y="100.153992" textLength="4.448167" font-size="8px">1</text>
<text x="114.776581" y="100.153992" textLength="4.448167" font-size="8px">2</text>
<text x="98.455002" y="51.776978" textLength="2.224083" font-size="8px">]</text>
<text x="345.795715" y="51.776672" textLength="4.448167" font-size="8px">8</text>
<text x="323.562866" y="104.953857" textLength="4.448167" font-size="8px">1</text>
<text x="133.118088" y="26.463745" textLength="5.336200" font-size="8px">P</text>
<text x="280.030151" y="100.153992" textLength="4.448167" font-size="8px">0</text>
<text x="163.783249" y="26.463745" textLength="4.448167" font-size="8px">1</text>
<text x="202.219101" y="100.153992" textLength="4.448167" font-size="8px">3</text>
<text x="98.464005" y="123.804993" textLength="2.224083" font-size="8px">]</text>
<text x="71.765991" y="51.776978" textLength="2.224083" font-size="8px">[</text>
<text x="284.478333" y="100.153992" textLength="2.224083" font-size="8px">]</text>
<text x="57.198395" y="100.153992" textLength="2.224083" font-size="8px">:</text>
<text x="268.909729" y="100.153992" textLength="4.448167" font-size="8px">6</text>
<text x="89.558670" y="51.776978" textLength="4.448167" font-size="8px">6</text>
<text x="52.750229" y="100.153992" textLength="4.448167" font-size="8px">7</text>
<text x="217.787735" y="100.153992" textLength="2.664100" font-size="8px">-</text>
<text x="208.891373" y="100.153992" textLength="4.448167" font-size="8px">0</text>
<text x="207.792953" y="26.463745" textLength="4.448167" font-size="8px">2</text>
<text x="19.852997" y="100.153992" textLength="4.000150" font-size="8px">x</text>
<text x="150.361984" y="100.153992" textLength="2.224083" font-size="8px">]</text>
<text x="134.793350" y="100.153992" textLength="4.448167" font-size="8px">7</text>
<text x="82.895416" y="123.804993" textLength="4.448167" font-size="8px">7</text>
<text x="43.853897" y="100.153992" textLength="4.448167" font-size="8px">1</text>
<text x="41.629807" y="100.153992" textLength="2.224083" font-size="8px">[</text>
<text x="94.015839" y="123.804993" textLength="4.448167" font-size="8px">4</text>
<text x="332.315186" y="95.353516" textLength="4.888184" font-size="8px">T</text>
<text x="323.562866" y="51.776672" textLength="4.448167" font-size="8px">2</text>
<text x="141.465622" y="100.153992" textLength="4.448167" font-size="8px">6</text>
<text x="103.664169" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="125.897003" y="100.153992" textLength="4.448167" font-size="8px">1</text>
<text x="110.328415" y="100.153992" textLength="4.448167" font-size="8px">1</text>
<text x="172.679611" y="26.463745" textLength="4.000150" font-size="8px">x</text>
<text x="177.770157" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="139.241531" y="100.153992" textLength="2.224083" font-size="8px">:</text>
<text x="184.434402" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="317.346619" y="95.353516" textLength="5.336200" font-size="8px">S</text>
<text x="138.454300" y="26.463745" textLength="5.776217" font-size="8px">D</text>
<text x="79.663269" y="100.153992" textLength="4.000150" font-size="8px">x</text>
<text x="83.663422" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="244.452744" y="100.153992" textLength="2.224083" font-size="8px">/</text>
<text x="176.679764" y="26.463745" textLength="6.664250" font-size="8px">m</text>
<text x="246.676834" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="231.342453" y="51.776978" textLength="2.224083" font-size="8px">:</text>
<text x="222.675919" y="100.153992" textLength="4.000150" font-size="8px">x</text>
<text x="220.451828" y="100.153992" textLength="2.224083" font-size="8px"> </text>
<text x="310.234375" y="104.953857" textLength="6.664250" font-size="8px">m</text>
<text x="194.456436" y="26.463745" textLength="2.224083" font-size="8px">/</text>
<text x="119.224747" y="100.153992" textLength="4.448167" font-size="8px">8</text>
<text x="48.302063" y="100.153992" textLength="4.448167" font-size="8px">2</text>
<text x="73.999084" y="123.804993" textLength="4.448167" font-size="8px">1</text>
<text x="82.886414" y="51.776978" textLength="4.448167" font-size="8px">7</text>
<text x="59.422485" y="100.153992" textLength="4.448167" font-size="8px">6</text>
<text x="183.344009" y="26.463745" textLength="6.664250" font-size="8px">m</text>
<text x="213.339554" y="100.153992" textLength="2.224083" font-size="8px">]</text>
<text x="233.575516" y="123.804993" textLength="4.448167" font-size="8px">0</text>
<text x="72.766998" y="100.153992" textLength="4.672175" font-size="8px">+</text>
<text x="77.439178" y="100.153992" textLength="2.224083" font-size="8px"> </text>
<text x="94.006836" y="51.776978" textLength="4.448167" font-size="8px">4</text>
<text x="73.990082" y="51.776978" textLength="4.448167" font-size="8px">1</text>
<text x="78.438248" y="51.776978" textLength="4.448167" font-size="8px">2</text>
<text x="87.334579" y="51.776978" textLength="2.224083" font-size="8px">:</text>
<text x="23.853149" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="30.517395" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="37.181641" y="100.153992" textLength="4.448167" font-size="8px">1</text>
<text x="63.870651" y="100.153992" textLength="4.448167" font-size="8px">4</text>
<text x="68.318817" y="100.153992" textLength="2.224083" font-size="8px">]</text>
<text x="70.542908" y="100.153992" textLength="2.224083" font-size="8px"> </text>
<text x="90.327667" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="96.991913" y="100.153992" textLength="4.448167" font-size="8px">2</text>
<text x="101.440079" y="100.153992" textLength="2.224083" font-size="8px">/</text>
<text x="123.672913" y="100.153992" textLength="2.224083" font-size="8px">[</text>
<text x="130.345169" y="100.153992" textLength="4.448167" font-size="8px">2</text>
<text x="145.913803" y="100.153992" textLength="4.448167" font-size="8px">4</text>
<text x="306.234192" y="104.953857" textLength="4.000150" font-size="8px">x</text>
<text x="173.770004" y="100.153992" textLength="4.000150" font-size="8px">x</text>
<text x="191.098648" y="100.153992" textLength="4.448167" font-size="8px">1</text>
<text x="195.546829" y="100.153992" textLength="2.224083" font-size="8px">[</text>
<text x="197.770920" y="100.153992" textLength="4.448167" font-size="8px">6</text>
<text x="206.667282" y="100.153992" textLength="2.224083" font-size="8px">:</text>
<text x="215.563644" y="100.153992" textLength="2.224083" font-size="8px"> </text>
<text x="226.676071" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="233.340317" y="100.153992" textLength="6.664250" font-size="8px">m</text>
<text x="240.004562" y="100.153992" textLength="4.448167" font-size="8px">2</text>
</svg>
<figcaption>Figure 3-3.  ADDSUBPD--Packed Double-FP Add/Subtract
</figcaption></figure>
```

### Operation
#### ADDSUBPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-  DEST[63:0] - SRC[63:0]
DEST[127:64] <-  DEST[127:64] + SRC[127:64]
DEST[VLMAX-1:128] (Unmodified)
```
#### VADDSUBPD (VEX.128 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC2[63:0]
DEST[127:64] <-  SRC1[127:64] + SRC2[127:64]
DEST[VLMAX-1:128] <-  0
```
#### VADDSUBPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  SRC1[63:0] - SRC2[63:0]
DEST[127:64] <-  SRC1[127:64] + SRC2[127:64]
DEST[191:128] <-  SRC1[191:128] - SRC2[191:128]
DEST[255:192] <-  SRC1[255:192] + SRC2[255:192]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
ADDSUBPD: __m128d _mm_addsub_pd(__m128d a, __m128d b)
VADDSUBPD: __m256d _mm256_addsub_pd (__m256d a, __m256d b)
```
### Exceptions


When the source operand is a memory operand, it must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated.

### SIMD Floating-Point Exceptions


Overflow, Underflow, Invalid, Precision, Denormal.

### Other Exceptions


See Exceptions Type 2.

