----------------------------
title : ROUNDPD (Intel x86/64 assembly instruction)
cat_title : ROUNDPD
ref_title : ROUNDPD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ ROUNDPD

** Round Packed Double Precision Floating-Point Values**

|**Opcode\htmlonly{*}/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 3A 09 /r ibROUNDPD xmm1, xmm2/m128, imm8|RMI|V/V|SSE4_1|Round packed double precision floating-point values in xmm2/m128 and place the result in xmm1. The rounding mode is determined by imm8.|
|VEX.128.66.0F3A.WIG 09 /r ibVROUNDPD xmm1, xmm2/m128, imm8|RMI|V/V|AVX|Round packed double-precision floating-point values in xmm2/m128 and place the result in xmm1. The rounding mode is determined by imm8.|
|VEX.256.66.0F3A.WIG 09 /r ibVROUNDPD ymm1, ymm2/m256, imm8|RMI|V/V|AVX|Round packed double-precision floating-point values in ymm2/m256 and place the result in ymm1. The rounding mode is determined by imm8.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
### Description


Round the 2 double-precision floating-point values in the source operand (second operand) using the rounding mode specified in the immediate operand (third operand) and place the results in the destination operand (first operand). The rounding process rounds each input floating-point value to an integer value and returns the integer result as a double-precision floating-point value. 

The immediate operand specifies control fields for the rounding operation, three bit fields are defined and shown in Figure 4-24. Bit 3 of the immediate byte controls processor behavior for a precision exception, bit 2 selects the source of rounding mode control. Bits 1:0 specify a non-sticky rounding-mode value (Table 4-18 lists the encoded values for rounding-mode field). 

The Precision Floating-Point Exception is signaled according to the immediate operand. If any source operand is an SNaN then it will be converted to a QNaN. If DAZ is set to '1 then denormals will be converted to zero before rounding.

128-bit Legacy SSE version: The second source can be an XMM register or 128-bit memory location. The destina-tion is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the source operand second source operand or a 128-bit memory location. The destina-tion operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The source operand is a YMM register or a 256-bit memory location. The destination operand is a YMM register. 

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 380.640015 188.700012">
<rect x="0.000000" y="10.059998" width="0.480010" height="98.519997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="380.160004" y="10.059998" width="0.479980" height="98.519997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="380.640015" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="108.580078" width="380.640015" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.759995" y="27.040039" width="237.600006" height="27.240000" fill-rule="nonzero"  fill=" rgb(230,230,230) " stroke="black" />
<rect x="164.459991" y="94.599976" width="159.300003" height="0.300050" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.459991" y="53.920044" width="0.299990" height="40.799999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="260.820007" y="85.420044" width="45.779999" height="0.299990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="306.299988" y="54.040039" width="0.300020" height="31.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.940002" y="26.560059" width="270.839996" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="327.299988" y="26.799988" width="0.480010" height="27.780001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.699997" y="54.099976" width="270.839996" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.699997" y="26.559998" width="0.480000" height="27.780001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.000000" y="26.740051" width="0.299990" height="0.120000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.000000" y="26.860046" width="0.299990" height="27.420000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="302.100006" y="26.740051" width="0.299990" height="0.120000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="302.100006" y="26.860046" width="0.299990" height="27.420000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.500000" y="26.740051" width="0.299990" height="0.120000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="310.500000" y="26.860046" width="0.299990" height="27.420000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="259.019989" y="76.480042" width="39.180000" height="0.299990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="297.899994" y="54.160034" width="0.300020" height="22.440001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="183.467529" y="42.820007" textLength="4.442996" font-size="8px">e</text>
<text x="179.472015" y="42.820007" textLength="3.995500" font-size="8px">v</text>
<text x="172.368011" y="42.820007" textLength="4.442996" font-size="8px">e</text>
<text x="163.929504" y="42.820007" textLength="4.442996" font-size="8px">e</text>
<text x="219.535370" y="77.980042" textLength="2.221498" font-size="8px">t</text>
<text x="207.101349" y="77.980042" textLength="3.995500" font-size="8px">x</text>
<text x="196.441376" y="77.980042" textLength="1.774002" font-size="8px">i</text>
<text x="187.555389" y="77.980042" textLength="4.442996" font-size="8px">1</text>
<text x="183.112396" y="77.980042" textLength="2.221498" font-size="8px">,</text>
<text x="181.338379" y="77.980042" textLength="1.774002" font-size="8px">l</text>
<text x="167.577881" y="77.980042" textLength="2.661003" font-size="8px">r</text>
<text x="163.138885" y="77.980042" textLength="4.442996" font-size="8px">o</text>
<text x="156.418457" y="77.980042" textLength="2.221498" font-size="8px"> </text>
<text x="149.753967" y="77.980042" textLength="4.442996" font-size="8px">0</text>
<text x="145.310974" y="77.980042" textLength="2.221498" font-size="8px">;</text>
<text x="132.876968" y="77.980042" textLength="4.442996" font-size="8px">a</text>
<text x="126.220459" y="77.980042" textLength="6.656503" font-size="8px">M</text>
<text x="119.555969" y="77.980042" textLength="4.442996" font-size="8px">n</text>
<text x="115.112976" y="77.980042" textLength="4.442996" font-size="8px">o</text>
<text x="103.573975" y="77.980042" textLength="3.995500" font-size="8px">c</text>
<text x="99.130981" y="77.980042" textLength="4.442996" font-size="8px">e</text>
<text x="91.139984" y="77.980042" textLength="5.329997" font-size="8px">P</text>
<text x="73.379990" y="77.980042" textLength="5.329997" font-size="8px">P</text>
<text x="304.380341" y="23.619690" textLength="3.887607" font-size="8px">2</text>
<text x="144.635834" y="96.819641" textLength="4.442996" font-size="8px">d</text>
<text x="122.438416" y="96.819641" textLength="4.442996" font-size="8px">n</text>
<text x="116.226212" y="96.819641" textLength="4.442996" font-size="8px">d</text>
<text x="86.826523" y="96.819641" textLength="7.991000" font-size="8px">�</text>
<text x="245.085114" y="88.000000" textLength="5.769502" font-size="8px">R</text>
<text x="231.766510" y="88.000000" textLength="6.656503" font-size="8px">m</text>
<text x="222.890106" y="88.000000" textLength="2.221498" font-size="8px">I</text>
<text x="198.215363" y="77.980042" textLength="4.442996" font-size="8px">n</text>
<text x="209.505981" y="88.000000" textLength="2.221498" font-size="8px">,</text>
<text x="197.968567" y="88.000000" textLength="5.769502" font-size="8px">R</text>
<text x="173.552063" y="88.000000" textLength="5.329997" font-size="8px">X</text>
<text x="142.854645" y="88.000000" textLength="4.442996" font-size="8px">e</text>
<text x="141.081436" y="88.000000" textLength="1.774002" font-size="8px">l</text>
<text x="136.639236" y="88.000000" textLength="4.442996" font-size="8px">e</text>
<text x="130.423035" y="88.000000" textLength="2.221498" font-size="8px"> </text>
<text x="125.980835" y="88.000000" textLength="4.442996" font-size="8px">g</text>
<text x="121.538635" y="88.000000" textLength="4.442996" font-size="8px">n</text>
<text x="115.323227" y="88.000000" textLength="4.442996" font-size="8px">d</text>
<text x="110.881027" y="88.000000" textLength="4.442996" font-size="8px">n</text>
<text x="101.996628" y="88.000000" textLength="4.442996" font-size="8px">o</text>
<text x="154.196960" y="77.980042" textLength="2.221498" font-size="8px">:</text>
<text x="72.720001" y="88.000000" textLength="5.769502" font-size="8px">R</text>
<text x="133.541107" y="96.819641" textLength="6.656503" font-size="8px">m</text>
<text x="184.649963" y="88.000000" textLength="5.329997" font-size="8px">S</text>
<text x="149.076447" y="96.819641" textLength="4.442996" font-size="8px">e</text>
<text x="242.864410" y="88.000000" textLength="2.221498" font-size="8px">.</text>
<text x="153.512238" y="88.000000" textLength="2.221498" font-size="8px">;</text>
<text x="164.674866" y="88.000000" textLength="2.221498" font-size="8px"> </text>
<text x="202.658356" y="77.980042" textLength="4.442996" font-size="8px">e</text>
<text x="80.880341" y="77.980042" textLength="7.991000" font-size="8px">�</text>
<text x="97.086166" y="96.819641" textLength="5.769502" font-size="8px">R</text>
<text x="158.160004" y="42.820007" textLength="5.769502" font-size="8px">R</text>
<text x="187.910522" y="42.820007" textLength="4.442996" font-size="8px">d</text>
<text x="211.096863" y="77.980042" textLength="4.442996" font-size="8px">a</text>
<text x="185.333893" y="77.980042" textLength="2.221498" font-size="8px"> </text>
<text x="155.732941" y="88.000000" textLength="2.221498" font-size="8px"> </text>
<text x="132.644531" y="88.000000" textLength="3.995500" font-size="8px">s</text>
<text x="102.904419" y="96.819641" textLength="4.442996" font-size="8px">o</text>
<text x="107.345016" y="96.819641" textLength="4.442996" font-size="8px">u</text>
<text x="119.765427" y="88.000000" textLength="1.774002" font-size="8px">i</text>
<text x="195.747864" y="88.000000" textLength="2.221498" font-size="8px">.</text>
<text x="220.668610" y="88.000000" textLength="2.221498" font-size="8px"> </text>
<text x="96.238312" y="88.000000" textLength="5.769502" font-size="8px">R</text>
<text x="203.737274" y="88.000000" textLength="5.769502" font-size="8px">C</text>
<text x="178.881256" y="88.000000" textLength="5.769502" font-size="8px">C</text>
<text x="111.785614" y="96.819641" textLength="4.442996" font-size="8px">n</text>
<text x="170.238892" y="77.980042" textLength="6.656503" font-size="8px">m</text>
<text x="57.119995" y="23.200012" textLength="3.887607" font-size="8px">8</text>
<text x="250.853821" y="88.000000" textLength="5.769502" font-size="8px">C</text>
<text x="131.319611" y="96.819641" textLength="2.221498" font-size="8px"> </text>
<text x="238.422211" y="88.000000" textLength="4.442996" font-size="8px">8</text>
<text x="147.532471" y="77.980042" textLength="2.221498" font-size="8px"> </text>
<text x="107.569473" y="77.980042" textLength="1.774002" font-size="8px">i</text>
<text x="106.438828" y="88.000000" textLength="4.442996" font-size="8px">u</text>
<text x="78.538254" y="88.000000" textLength="5.329997" font-size="8px">S</text>
<text x="73.080399" y="96.819641" textLength="5.769502" font-size="8px">R</text>
<text x="141.315460" y="77.980042" textLength="3.995500" font-size="8px">k</text>
<text x="157.954437" y="88.000000" textLength="4.442996" font-size="8px">1</text>
<text x="218.447113" y="88.000000" textLength="2.221498" font-size="8px">:</text>
<text x="296.279999" y="23.440002" textLength="3.887607" font-size="8px">3</text>
<text x="120.666809" y="96.819641" textLength="1.774002" font-size="8px">i</text>
<text x="147.296844" y="88.000000" textLength="3.995500" font-size="8px">c</text>
<text x="151.291534" y="88.000000" textLength="2.221498" font-size="8px">t</text>
<text x="137.319962" y="77.980042" textLength="3.995500" font-size="8px">s</text>
<text x="162.453369" y="88.000000" textLength="2.221498" font-size="8px">:</text>
<text x="176.811005" y="42.820007" textLength="2.661003" font-size="8px">r</text>
<text x="213.948181" y="88.000000" textLength="4.442996" font-size="8px">0</text>
<text x="96.469986" y="77.980042" textLength="2.661003" font-size="8px">r</text>
<text x="194.219879" y="77.980042" textLength="2.221498" font-size="8px"> </text>
<text x="225.110809" y="88.000000" textLength="6.656503" font-size="8px">m</text>
<text x="168.372498" y="42.820007" textLength="3.995500" font-size="8px">s</text>
<text x="126.879013" y="96.819641" textLength="4.442996" font-size="8px">g</text>
<text x="211.726685" y="88.000000" textLength="2.221498" font-size="8px"> </text>
<text x="78.847504" y="96.819641" textLength="5.769502" font-size="8px">C</text>
<text x="215.539856" y="77.980042" textLength="3.995500" font-size="8px">c</text>
<text x="312.960358" y="23.440002" textLength="3.887607" font-size="8px">1</text>
<text x="123.998962" y="77.980042" textLength="2.221498" font-size="8px"> </text>
<text x="158.639954" y="77.980042" textLength="4.442996" font-size="8px">n</text>
<text x="113.338974" y="77.980042" textLength="1.774002" font-size="8px">i</text>
<text x="321.419403" y="23.440002" textLength="3.887607" font-size="8px">0</text>
<text x="166.896362" y="88.000000" textLength="6.656503" font-size="8px">M</text>
<text x="86.038605" y="88.000000" textLength="7.991000" font-size="8px">�</text>
<text x="191.998383" y="77.980042" textLength="2.221498" font-size="8px">:</text>
<text x="109.343475" y="77.980042" textLength="3.995500" font-size="8px">s</text>
<text x="140.195221" y="96.819641" textLength="4.442996" font-size="8px">o</text>
<text x="176.895386" y="77.980042" textLength="4.442996" font-size="8px">a</text>
<text x="189.979156" y="88.000000" textLength="5.769502" font-size="8px">R</text>
</svg>
<figcaption>Figure 4-24.  Bit Control Fields of Immediate Byte for ROUNDxx Instruction
</figcaption></figure>
```
### Table 4-18.  Rounding Modes and Encoding of Rounding Control (RC) Field


|**Rounding **\newline{}**Mode**|**RC Field **\newline{}**Setting**|**Description**|
|-------------------------------|----------------------------------|---------------|
|Round to nearest (even)|00B|Rounded result is the closest to the infinitely precise result. If two values are equally close, the result is the even value (i.e., the integer value with the least-significant bit of zero). |
|Round down (toward -$$\infty$$)|01B|Rounded result is closest to but no greater than the infinitely precise result.|
|Round up (toward +$$\infty$$)|10B|Rounded result is closest to but no less than the infinitely precise result.|
|Round toward zero (Truncate)|11B|Rounded result is closest to but no greater in absolute value than the infinitely precise result.|

### Operation
#### ROUNDPD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-   RoundToInteger(SRC[63:0]], ROUND_CONTROL)
DEST[127:64] <-   RoundToInteger(SRC[127:64]], ROUND_CONTROL)
DEST[VLMAX-1:128] (Unmodified)
```
#### VROUNDPD (VEX.128 encoded version)
```info-verb
DEST[63:0]  <-  RoundToInteger(SRC[63:0]], ROUND_CONTROL)
DEST[127:64]  <-  RoundToInteger(SRC[127:64]], ROUND_CONTROL)
DEST[VLMAX-1:128]  <-  0
```
#### VROUNDPD (VEX.256 encoded version)
```info-verb
DEST[63:0] <-   RoundToInteger(SRC[63:0], ROUND_CONTROL)
DEST[127:64] <-   RoundToInteger(SRC[127:64]], ROUND_CONTROL)
DEST[191:128]  <-  RoundToInteger(SRC[191:128]], ROUND_CONTROL)
DEST[255:192] <-   RoundToInteger(SRC[255:192] ], ROUND_CONTROL)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
__m128 _mm_round_pd(__m128d s1, int iRoundMode);
__m128 _mm_floor_pd(__m128d s1);
__m128 _mm_ceil_pd(__m128d s1)
__m256 _mm256_round_pd(__m256d s1, int iRoundMode);
__m256 _mm256_floor_pd(__m256d s1);
__m256 _mm256_ceil_pd(__m256d s1)
```
### SIMD Floating-Point Exceptions


Invalid (signaled only if SRC = SNaN)

Precision (signaled only if imm[3] = '0; if imm[3] = '1, then the Precision Mask in the MXSCSR is ignored and preci-sion exception is not signaled.)

Note that Denormal is not signaled by ROUNDPD.

### Other Exceptions


See Exceptions Type 2; additionally

#UD If VEX.vvvv  ->  1111B.

