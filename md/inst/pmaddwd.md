----------------------------
title : PMADDWD (Intel x86/64 assembly instruction)
cat_title : PMADDWD
ref_title : PMADDWD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PMADDWD

**Multiply and Add Packed Integers**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F F5 /r\footnote{1}\newline{}\newline{}PMADDWD mm, mm/m64|RM|V/V|MMX|Multiply the packed words in mm by the packed words in mm/m64, add adjacent doubleword results, and store in mm.|
|66 0F F5 /r\newline{}\newline{}PMADDWD xmm1, xmm2/m128|RM|V/V|SSE2|Multiply the packed word integers in xmm1 by the packed word integers in xmm2/m128, add adjacent doubleword results, and store in xmm1.|
|VEX.NDS.128.66.0F.WIG F5 /r\newline{}\newline{}VPMADDWD xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Multiply the packed word integers in xmm2 by the packed word integers in xmm3/m128, add adjacent doubleword results, and store in xmm1.|
|VEX.NDS.256.66.0F.WIG F5 /r\newline{}\newline{}VPMADDWD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Multiply the packed word integers in ymm2 by the packed word integers in ymm3/m256, add adjacent doubleword results, and store in ymm1.|
|EVEX.NDS.128.66.0F.WIG F5 /r\newline{}VPMADDWD xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed word integers in xmm2 by the packed word integers in xmm3/m128, add adjacent doubleword results, and store in xmm1 under writemask k1.|
|EVEX.NDS.256.66.0F.WIG F5 /r\newline{}VPMADDWD ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Multiply the packed word integers in ymm2 by the packed word integers in ymm3/m256, add adjacent doubleword results, and store in ymm1 under writemask k1.|
|EVEX.NDS.512.66.0F.WIG F5 /r\newline{}VPMADDWD zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Multiply the packed word integers in zmm2 by the packed word integers in zmm3/m512, add adjacent doubleword results, and store in zmm1 under writemask k1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Multiplies the individual signed words of the destination operand (first operand) by the corresponding signed words of the source operand (second operand), producing temporary signed, doubleword results. The adjacent double-word results are then summed and stored in the destination operand. For example, the corresponding low-order words (15-0) and (31-16) in the source and destination operands are multiplied by one another and the double-word results are added together and stored in the low doubleword of the destination register (31-0). The same operation is performed on the other pairs of adjacent words. (Figure 4-11 shows this operation when using 64-bit operands).



The (V)PMADDWD instruction wraps around only in one situation: when the 2 pairs of words being operated on in a group are all 8000H. In this case, the result wraps around to 80000000H.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE version: The first source and destination operands are MMX registers. The second source operand is an MMX register or a 64-bit memory location. 

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destina-tion register remain unchanged.

VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand is an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The second source operand can be an YMM register or a 256-bit memory location. The first source and destination operands are YMM registers.

EVEX.512 encoded version: The second source operand can be an ZMM register or a 512-bit memory location. The first source and destination operands are ZMM registers.

```embed
<figure>
<svg viewBox="0 0 379.679993 143.279999">
<rect x="0.000000" y="10.000000" width="0.480000" height="121.139999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.199982" y="10.000000" width="0.479980" height="121.139999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="131.139984" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.659996" y="76.420013" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="57.659996" y="76.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.420013" y="76.420013" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.420006" y="94.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.420006" y="76.180023" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.660004" y="76.420013" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.660004" y="76.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="76.420013" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.420013" y="94.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.420013" y="76.180023" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.660004" y="76.420013" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.660004" y="76.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.419983" y="76.420013" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="94.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="76.180023" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.660004" y="76.420013" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="273.660004" y="76.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="345.419983" y="76.420013" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.419983" y="94.180023" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.419983" y="76.180023" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="20.380005" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.640015" y="20.139984" width="36.660000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.820007" y="20.380005" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.399994" y="38.139984" width="36.660000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.399994" y="20.140015" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.059998" y="20.380005" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.059998" y="20.139984" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.820007" y="38.139984" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.820007" y="20.140015" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="20.380005" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.419983" y="20.139984" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.540009" y="20.380005" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="38.139984" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.179993" y="20.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.779999" y="20.380005" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.779999" y="20.139984" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.899994" y="20.380005" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.540009" y="38.139984" width="36.599998" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.540009" y="20.140015" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.640015" y="46.600006" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="128.640015" y="46.360016" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.759979" y="46.600006" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.399994" y="64.360016" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.399994" y="46.360016" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.000000" y="46.600006" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.000000" y="46.360016" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.119995" y="46.600006" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.759979" y="64.360016" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.759979" y="46.360016" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.359985" y="46.600006" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.359985" y="46.360016" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.479980" y="46.600006" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.119995" y="64.360016" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.119995" y="46.360016" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.720001" y="46.600006" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.720001" y="46.360016" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.899994" y="46.600006" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.479980" y="64.360016" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.479980" y="46.360016" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.540009" y="104.440002" width="72.239998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.540009" y="104.200012" width="72.480003" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.540009" y="104.440033" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.299988" y="122.200012" width="72.480003" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.299988" y="104.200012" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.660004" y="104.440002" width="73.379997" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.660004" y="104.200012" width="73.620003" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="274.799988" y="104.440033" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="122.200012" width="73.620003" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.419983" y="104.200012" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="48.590385" y="88.299988" textLength="5.329997" font-size="8px">P</text>
<text x="31.680626" y="88.299988" textLength="4.882501" font-size="8px">T</text>
<text x="198.275391" y="116.680023" textLength="2.661003" font-size="8px">)</text>
<text x="188.519989" y="116.680023" textLength="5.329997" font-size="8px">Y</text>
<text x="184.500000" y="116.680023" textLength="3.990000" font-size="8px">`*`</text>
<text x="180.066101" y="116.680023" textLength="4.442996" font-size="8px">2</text>
<text x="174.739288" y="116.680023" textLength="5.329997" font-size="8px">X</text>
<text x="172.081482" y="116.680023" textLength="2.661003" font-size="8px">(</text>
<text x="169.859985" y="116.680023" textLength="2.221498" font-size="8px"> </text>
<text x="163.187622" y="116.680023" textLength="2.221498" font-size="8px"> </text>
<text x="160.535400" y="116.680023" textLength="2.661003" font-size="8px">)</text>
<text x="146.759979" y="116.680023" textLength="3.990000" font-size="8px">`*`</text>
<text x="136.995728" y="116.680389" textLength="5.329997" font-size="8px">X</text>
<text x="134.340302" y="116.680389" textLength="2.661003" font-size="8px">(</text>
<text x="260.339996" y="116.320007" textLength="5.329997" font-size="8px">Y</text>
<text x="256.320007" y="116.320007" textLength="3.990000" font-size="8px">`*`</text>
<text x="246.559296" y="116.320007" textLength="5.329997" font-size="8px">X</text>
<text x="243.901489" y="116.320007" textLength="2.661003" font-size="8px">(</text>
<text x="241.679993" y="116.320007" textLength="2.221498" font-size="8px"> </text>
<text x="237.299988" y="116.320007" textLength="4.381020" font-size="8px">+</text>
<text x="227.951569" y="116.320007" textLength="4.442996" font-size="8px">1</text>
<text x="214.139832" y="116.320007" textLength="4.442996" font-size="8px">1</text>
<text x="257.697601" y="59.080017" textLength="4.442996" font-size="8px">0</text>
<text x="252.357208" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="215.938232" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="184.259521" y="59.080017" textLength="4.442996" font-size="8px">2</text>
<text x="178.919128" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="148.680389" y="59.080017" textLength="4.442996" font-size="8px">3</text>
<text x="107.465080" y="113.200623" textLength="4.882501" font-size="8px">T</text>
<text x="96.795494" y="113.200623" textLength="5.329997" font-size="8px">E</text>
<text x="91.021202" y="113.200623" textLength="5.769502" font-size="8px">D</text>
<text x="106.384697" y="57.880524" textLength="4.882501" font-size="8px">T</text>
<text x="101.049904" y="57.880524" textLength="5.329997" font-size="8px">S</text>
<text x="95.715111" y="57.880524" textLength="5.329997" font-size="8px">E</text>
<text x="95.270012" y="31.120270" textLength="5.769502" font-size="8px">R</text>
<text x="89.940819" y="31.120270" textLength="5.329997" font-size="8px">S</text>
<text x="319.858673" y="87.460022" textLength="4.442996" font-size="8px">0</text>
<text x="314.521484" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="312.299988" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="308.279999" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="306.059723" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="301.611145" y="87.460022" textLength="4.442996" font-size="8px">0</text>
<text x="296.275543" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="243.299988" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="232.611053" y="87.460022" textLength="4.442996" font-size="8px">1</text>
<text x="227.275452" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="163.798187" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="159.299255" y="87.460022" textLength="4.442996" font-size="8px">2</text>
<text x="99.121437" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="96.840004" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="90.659752" y="87.459686" textLength="2.221498" font-size="8px"> </text>
<text x="86.213554" y="87.459686" textLength="4.442996" font-size="8px">3</text>
<text x="80.880363" y="87.459686" textLength="5.329997" font-size="8px">X</text>
<text x="254.517609" y="31.779999" textLength="4.442996" font-size="8px">0</text>
<text x="218.098602" y="31.779999" textLength="4.442996" font-size="8px">1</text>
<text x="212.758209" y="31.779999" textLength="5.329997" font-size="8px">X</text>
<text x="175.739105" y="31.779999" textLength="5.329997" font-size="8px">X</text>
<text x="208.860168" y="116.320007" textLength="5.329997" font-size="8px">X</text>
<text x="143.339996" y="59.080017" textLength="5.329997" font-size="8px">Y</text>
<text x="102.130287" y="113.200623" textLength="5.329997" font-size="8px">S</text>
<text x="222.600006" y="116.320007" textLength="5.329997" font-size="8px">Y</text>
<text x="165.419983" y="116.680023" textLength="4.381020" font-size="8px">+</text>
<text x="249.177216" y="31.779999" textLength="5.329997" font-size="8px">X</text>
<text x="200.927612" y="116.680023" textLength="2.221498" font-size="8px"> </text>
<text x="245.521484" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="172.201477" y="87.460022" textLength="5.329997" font-size="8px">Y</text>
<text x="104.401085" y="87.460022" textLength="4.442996" font-size="8px">3</text>
<text x="177.537079" y="87.460022" textLength="4.442996" font-size="8px">2</text>
<text x="235.098724" y="116.320007" textLength="2.221498" font-size="8px"> </text>
<text x="36.576714" y="88.299988" textLength="5.329997" font-size="8px">E</text>
<text x="237.059631" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="270.119385" y="116.320007" textLength="2.661003" font-size="8px">)</text>
<text x="251.886108" y="116.320007" textLength="4.442996" font-size="8px">0</text>
<text x="265.673187" y="116.320007" textLength="4.442996" font-size="8px">0</text>
<text x="232.416138" y="116.320007" textLength="2.661003" font-size="8px">)</text>
<text x="154.019592" y="87.460022" textLength="5.329997" font-size="8px">X</text>
<text x="156.101196" y="116.680023" textLength="4.442996" font-size="8px">3</text>
<text x="41.920296" y="88.299988" textLength="6.656503" font-size="8px">M</text>
<text x="145.500366" y="31.779999" textLength="4.442996" font-size="8px">3</text>
<text x="239.279999" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="221.278625" y="59.080017" textLength="4.442996" font-size="8px">1</text>
<text x="142.320129" y="116.680389" textLength="4.442996" font-size="8px">3</text>
<text x="193.841187" y="116.680023" textLength="4.442996" font-size="8px">2</text>
<text x="250.857086" y="87.460022" textLength="4.442996" font-size="8px">1</text>
<text x="166.019989" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="206.160004" y="116.320007" textLength="2.661003" font-size="8px">(</text>
<text x="169.979980" y="87.460022" textLength="2.221498" font-size="8px"> </text>
<text x="92.879997" y="87.460022" textLength="3.990000" font-size="8px">`*`</text>
<text x="101.038719" y="31.120270" textLength="5.769502" font-size="8px">C</text>
<text x="140.160004" y="31.779999" textLength="5.329997" font-size="8px">X</text>
<text x="218.639984" y="116.320007" textLength="3.990000" font-size="8px">`*`</text>
<text x="89.940819" y="57.880524" textLength="5.769502" font-size="8px">D</text>
<text x="150.779999" y="116.680023" textLength="5.329997" font-size="8px">Y</text>
<text x="181.079498" y="31.779999" textLength="4.442996" font-size="8px">2</text>
</svg>
<figcaption>Figure 4-11.  PMADDWD Execution Model Using 64-bit Operands
</figcaption></figure>
```

### Operation
#### PMADDWD (with 64-bit operands)
```info-verb
    DEST[31:0] <- (DEST[15:0] `*` SRC[15:0]) + (DEST[31:16] `*` SRC[31:16]);
    DEST[63:32] <- (DEST[47:32] `*` SRC[47:32]) + (DEST[63:48] `*` SRC[63:48]);
```
#### PMADDWD (with 128-bit operands)
```info-verb
    DEST[31:0] <- (DEST[15:0] `*` SRC[15:0]) + (DEST[31:16] `*` SRC[31:16]);
    DEST[63:32] <- (DEST[47:32] `*` SRC[47:32]) + (DEST[63:48] `*` SRC[63:48]);
    DEST[95:64] <- (DEST[79:64] `*` SRC[79:64]) + (DEST[95:80] `*` SRC[95:80]);
    DEST[127:96] <- (DEST[111:96] `*` SRC[111:96]) + (DEST[127:112] `*` SRC[127:112]);
```
#### VPMADDWD (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  (SRC1[15:0] * SRC2[15:0]) + (SRC1[31:16] * SRC2[31:16])
DEST[63:32] <-  (SRC1[47:32] * SRC2[47:32]) + (SRC1[63:48] * SRC2[63:48])
DEST[95:64] <-  (SRC1[79:64] * SRC2[79:64]) + (SRC1[95:80] * SRC2[95:80])
DEST[127:96] <-  (SRC1[111:96] * SRC2[111:96]) + (SRC1[127:112] * SRC2[127:112])
DEST[VLMAX-1:128] <-  0
```
#### VPMADDWD (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  (SRC1[15:0] * SRC2[15:0]) + (SRC1[31:16] * SRC2[31:16])
DEST[63:32] <-  (SRC1[47:32] * SRC2[47:32]) + (SRC1[63:48] * SRC2[63:48])
DEST[95:64] <-  (SRC1[79:64] * SRC2[79:64]) + (SRC1[95:80] * SRC2[95:80])
DEST[127:96] <-  (SRC1[111:96] * SRC2[111:96]) + (SRC1[127:112] * SRC2[127:112])
DEST[159:128] <-  (SRC1[143:128] * SRC2[143:128]) + (SRC1[159:144] * SRC2[159:144])
DEST[191:160] <-  (SRC1[175:160] * SRC2[175:160]) + (SRC1[191:176] * SRC2[191:176])
DEST[223:192] <-  (SRC1[207:192] * SRC2[207:192]) + (SRC1[223:208] * SRC2[223:208])
DEST[255:224] <-  (SRC1[239:224] * SRC2[239:224]) + (SRC1[255:240] * SRC2[255:240])
DEST[VLMAX-1:256] <-  0
```
#### VPMADDWD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  (SRC2[i+31:i+16]* SRC1[i+31:i+16]) + (SRC2[i+15:i]*SRC1[i+15:i])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] = 0
                FI
    FI;
ENDFOR;
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMADDWD __m512i _mm512_mdd_epi16( __m512i a, __m512i b);
VPMADDWD __m512i _mm512_mask_mdd_epi16(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPMADDWD __m512i _mm512_maskz_mdd_epi16( __mmask16 k, __m512i a, __m512i b);
VPMADDWD __m256i _mm256_mask_mdd_epi16(__m256i s, __mmask8 k, __m256i a, __m256i b);
VPMADDWD __m256i _mm256_maskz_mdd_epi16( __mmask8 k, __m256i a, __m256i b);
VPMADDWD __m128i _mm_mask_mdd_epi16(__m128i s, __mmask8 k, __m128i a, __m128i b);
VPMADDWD __m128i _mm_maskz_madd_epi16( __mmask8 k, __m128i a, __m128i b);
PMADDWD:__m64 _mm_madd_pi16(__m64 m1, __m64 m2)
(V)PMADDWD:__m128i _mm_madd_epi16 ( __m128i a, __m128i b)
VPMADDWD:__m256i _mm256_madd_epi16 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

