----------------------------
title : VFIXUPIMMSD (Intel x86/64 assembly instruction)
cat_title : VFIXUPIMMSD
ref_title : VFIXUPIMMSD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VFIXUPIMMSD

**Fix Up Special Scalar Float64 Value**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F3A.W1 55 /r ib\newline{}VFIXUPIMMSD xmm1 {k1}{z}, xmm2, xmm3/m64{sae}, imm8|T1S|V/V|AVX512F|Fix up a float64 number in the low quadword element of xmm2 using scalar int32 table in xmm3/m64 and store the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (r, w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Perform a fix-up of the low quadword element encoded in double-precision floating-point format in the first source operand (the second operand) using a 32-bit, two-level look-up table specified in the low quadword element of the second source operand (the third operand) with exception reporting specifier imm8. The element that is fixed-up is selected by mask bit of 1 specified in the opmask k1. Mask bit of 0 in the opmask k1 or table response action of 0000b preserves the corresponding element of the first operand. The fixed-up element from the first source operand or the preserved element in the first operand becomes the low quadword element of the destination operand (the first operand). Bits 127:64 of the destination operand is copied from the corresponding bits of the first source operand. The destination and first source operands are XMM registers. The second source operand can be a XMM register or a 64- bit memory location.

The two-level look-up table perform a fix-up of each DP FP input data in the first source operand by decoding the input data encoding into 8 token types. A response table is defined for each token type that converts the input encoding in the first source operand with one of 16 response actions. 

This instruction is specifically intended for use in fixing up the results of arithmetic calculations involving one source so that they match the spec, although it is generally useful for fixing up the results of multiple-instruction sequences to reflect special-number inputs. For example, consider rcp(0). Input 0 to rcp, and you should get INF according to the DX10 spec. However, evaluating rcp via Newton-Raphson, where x=approx(1/0), yields an incor-rect result. To deal with this, `VFIXUPIMMPD` can be used after the N-R reciprocal sequence to set the result to the correct value (i.e. INF when the input is 0).

If MXCSR.DAZ is not set, denormal input elements in the first source operand are considered as normal inputs and do not trigger any fixup nor fault reporting.

Imm8 is used to set the required flags reporting. It supports #ZE and #IE fault reporting (see details below).

MXCSR.DAZ is used and refer to zmm2 only (i.e. zmm1 is not considered as zero in case MXCSR.DAZ is set).

MXCSR mask bits are ignored and are treated as if all mask bits are set to masked response). If any of the imm8 bits is set and the condition met for fault reporting, MXCSR.IE or MXCSR.ZE might be updated.


### Operation
#### VFIXUPIMMSD (EVEX encoded version)
```info-verb
IF k1[0] OR *no writemask*
    THEN DEST[63:0] <-  FIXUPIMM_DP(DEST[63:0], SRC1[63:0], SRC2[63:0], imm8 [7:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  DEST[63:0] <-  0 ; zeroing-masking
          FI
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
Immediate Control Description:
```
```embed
<figure>
<svg viewBox="0 0 396.539978 223.399994">
<rect x="0.000000" y="10.000000" width="0.480000" height="196.199997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="196.199997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="206.260010" width="396.540009" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,62.260010 L225.479996,62.260010 L225.479996,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M221.699997,53.980011 L225.479996,44.260010 L228.479996,53.980011 L221.699997,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,80.260010 L242.699997,80.260010 L242.699997,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M239.699997,53.980011 L242.699997,44.260010 L246.479996,53.980011 L239.699997,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,98.260010 L260.700012,98.260010 L260.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M257.700012,53.980011 L260.700012,44.260010 L264.479980,53.980011 L257.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,116.260010 L278.700012,116.260010 L278.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M275.700012,53.980011 L278.700012,44.260010 L282.479980,53.980011 L275.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,134.260010 L296.700012,134.260010 L296.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M293.700012,53.980011 L296.700012,44.260010 L300.479980,53.980011 L293.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,152.260010 L314.700012,152.260010 L314.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M311.700012,53.980011 L314.700012,44.260010 L317.700012,53.980011 L311.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,169.480011 L332.700012,169.480011 L332.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M329.700012,53.980011 L332.700012,44.260010 L335.700012,53.980011 L329.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,187.480011 L350.700012,187.480011 L350.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M347.700012,53.980011 L350.700012,44.260010 L353.700012,53.980011 L347.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.479996" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="216.479996" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.479996" y="26.260010" width="17.219999" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="234.479996" y="26.260010" width="17.219999" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.699997" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="251.699997" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="269.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="287.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="305.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="323.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="341.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="341.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="53.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="53.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="89.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="89.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="107.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="107.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="71.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="71.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="125.260010" width="108.000000" height="17.219999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="125.260010" width="108.000000" height="17.219999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="142.480011" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="142.480011" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="160.480011" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="160.480011" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.479996" y="178.480011" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.479996" y="178.480011" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<text x="130.981903" y="191.260010" textLength="7.200601" font-size="8px">E</text>
<text x="123.481277" y="191.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="115.980652" y="191.260010" textLength="7.200601" font-size="8px">#</text>
<text x="84.480423" y="191.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.480423" y="191.260010" textLength="0.000000" font-size="8px"> </text>
<text x="73.261887" y="191.260010" textLength="7.200601" font-size="8px">O</text>
<text x="123.481277" y="173.260010" textLength="7.200601" font-size="8px">I</text>
<text x="115.980652" y="173.260010" textLength="7.200601" font-size="8px">#</text>
<text x="65.761261" y="173.260010" textLength="7.200601" font-size="8px">R</text>
<text x="50.760010" y="173.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="123.480957" y="155.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="115.980331" y="155.260010" textLength="7.200601" font-size="8px">#</text>
<text x="84.480103" y="155.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.480103" y="155.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.483704" y="155.260010" textLength="7.200601" font-size="8px"> </text>
<text x="76.981873" y="155.260010" textLength="7.200601" font-size="8px"> </text>
<text x="69.481247" y="155.260010" textLength="7.200601" font-size="8px">E</text>
<text x="61.980621" y="155.260010" textLength="7.200601" font-size="8px">N</text>
<text x="84.480103" y="137.259918" textLength="0.000000" font-size="8px"> </text>
<text x="84.480103" y="137.259918" textLength="0.000000" font-size="8px"> </text>
<text x="84.483704" y="138.040009" textLength="7.200601" font-size="8px"> </text>
<text x="76.981873" y="138.040009" textLength="7.200601" font-size="8px"> </text>
<text x="69.481247" y="138.040009" textLength="7.200601" font-size="8px">E</text>
<text x="115.979874" y="84.040009" textLength="7.200601" font-size="8px">#</text>
<text x="84.479645" y="84.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.479645" y="84.040009" textLength="0.000000" font-size="8px"> </text>
<text x="83.761993" y="84.040009" textLength="7.200601" font-size="8px"> </text>
<text x="76.261368" y="84.040009" textLength="7.200601" font-size="8px"> </text>
<text x="61.260117" y="84.040009" textLength="7.200601" font-size="8px">V</text>
<text x="130.981903" y="120.040009" textLength="7.200601" font-size="8px">E</text>
<text x="84.480423" y="120.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.480423" y="120.040009" textLength="0.000000" font-size="8px"> </text>
<text x="80.762512" y="120.040009" textLength="7.200601" font-size="8px"> </text>
<text x="65.761261" y="120.040009" textLength="7.200601" font-size="8px">a</text>
<text x="130.981125" y="102.040009" textLength="7.200601" font-size="8px">E</text>
<text x="84.479645" y="102.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.479645" y="102.040009" textLength="0.000000" font-size="8px"> </text>
<text x="72.479843" y="102.040009" textLength="7.200601" font-size="8px">F</text>
<text x="57.479797" y="102.040009" textLength="7.200601" font-size="8px">I</text>
<text x="45.479996" y="102.040009" textLength="7.200601" font-size="8px">-</text>
<text x="123.480499" y="66.040009" textLength="7.200601" font-size="8px">I</text>
<text x="115.979874" y="66.040009" textLength="7.200601" font-size="8px">#</text>
<text x="84.479645" y="66.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.479645" y="66.040009" textLength="0.000000" font-size="8px"> </text>
<text x="79.979263" y="66.040009" textLength="7.200601" font-size="8px"> </text>
<text x="64.979218" y="66.040009" textLength="7.200601" font-size="8px">N</text>
<text x="45.479996" y="66.040009" textLength="7.200601" font-size="8px">+</text>
<text x="349.979980" y="39.040039" textLength="6.672556" font-size="8px">0</text>
<text x="331.979980" y="39.040039" textLength="6.672556" font-size="8px">1</text>
<text x="295.979980" y="39.040039" textLength="6.672556" font-size="8px">3</text>
<text x="259.979980" y="39.040039" textLength="6.672556" font-size="8px">5</text>
<text x="241.979996" y="39.040039" textLength="6.672556" font-size="8px">6</text>
<text x="73.261887" y="120.040009" textLength="7.200601" font-size="8px">N</text>
<text x="45.479996" y="84.040009" textLength="7.200601" font-size="8px">-</text>
<text x="115.979874" y="102.040009" textLength="7.200601" font-size="8px">#</text>
<text x="54.479996" y="138.040009" textLength="7.200601" font-size="8px">O</text>
<text x="80.762512" y="191.260010" textLength="7.200601" font-size="8px"> </text>
<text x="72.479843" y="66.040009" textLength="7.200601" font-size="8px">F</text>
<text x="57.479797" y="66.040009" textLength="7.200601" font-size="8px">I</text>
<text x="115.980652" y="120.040009" textLength="7.200601" font-size="8px">#</text>
<text x="130.981583" y="138.040009" textLength="7.200601" font-size="8px">E</text>
<text x="54.479996" y="155.260010" textLength="7.200601" font-size="8px">O</text>
<text x="58.260635" y="120.040009" textLength="7.200601" font-size="8px">N</text>
<text x="130.981903" y="173.260010" textLength="7.200601" font-size="8px">E</text>
<text x="123.480499" y="84.040009" textLength="7.200601" font-size="8px">I</text>
<text x="277.979980" y="39.040039" textLength="6.672556" font-size="8px">4</text>
<text x="61.980621" y="138.040009" textLength="7.200601" font-size="8px">N</text>
<text x="64.979218" y="102.040009" textLength="7.200601" font-size="8px">N</text>
<text x="123.480957" y="138.040009" textLength="7.200601" font-size="8px">I</text>
<text x="313.979980" y="39.040039" textLength="6.672556" font-size="8px">2</text>
<text x="123.480499" y="102.040009" textLength="7.200601" font-size="8px">I</text>
<text x="115.980331" y="138.040009" textLength="7.200601" font-size="8px">#</text>
<text x="58.260635" y="173.260010" textLength="7.200601" font-size="8px">E</text>
<text x="65.761261" y="191.260010" textLength="7.200601" font-size="8px">R</text>
<text x="130.981583" y="155.260010" textLength="7.200601" font-size="8px">E</text>
<text x="223.979996" y="39.040039" textLength="6.672556" font-size="8px">7</text>
<text x="50.760010" y="191.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="123.481277" y="120.040009" textLength="7.200601" font-size="8px">I</text>
<text x="79.979263" y="102.040009" textLength="7.200601" font-size="8px"> </text>
<text x="58.260635" y="191.260010" textLength="7.200601" font-size="8px">E</text>
<text x="130.981125" y="66.040009" textLength="7.200601" font-size="8px">E</text>
<text x="80.762512" y="173.260010" textLength="7.200601" font-size="8px"> </text>
<text x="50.760010" y="120.040009" textLength="7.200601" font-size="8px">S</text>
<text x="73.261887" y="173.260010" textLength="7.200601" font-size="8px">O</text>
<text x="68.760742" y="84.040009" textLength="7.200601" font-size="8px">E</text>
<text x="84.480423" y="173.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.480423" y="173.260010" textLength="0.000000" font-size="8px"> </text>
<text x="130.981125" y="84.040009" textLength="7.200601" font-size="8px">E</text>
</svg>
<figcaption>Figure 5-11.  VFIXUPIMMSD Immediate Control Description
</figcaption></figure>
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFIXUPIMMSD __m128d _mm_fixupimm_sd( __m128d a, __m128i tbl, int imm);
VFIXUPIMMSD __m128d _mm_mask_fixupimm_sd(__m128d s, __mmask8 k, __m128d a, __m128i tbl, int imm);
VFIXUPIMMSD __m128d _mm_maskz_fixupimm_sd( __mmask8 k, __m128d a, __m128i tbl, int imm);
VFIXUPIMMSD __m128d _mm_fixupimm_round_sd( __m128d a, __m128i tbl, int imm, int sae);
VFIXUPIMMSD __m128d _mm_mask_fixupimm_round_sd(__m128d s, __mmask8 k, __m128d a, __m128i tbl, int imm, int sae);
VFIXUPIMMSD __m128d _mm_maskz_fixupimm_round_sd( __mmask8 k, __m128d a, __m128i tbl, int imm, int sae);
```
### SIMD Floating-Point Exceptions


Zero, Invalid

### Other Exceptions


See Exceptions Type E3.

