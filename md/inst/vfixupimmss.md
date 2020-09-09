----------------------------
title : VFIXUPIMMSS (Intel x86/64 assembly instruction)
cat_title : VFIXUPIMMSS
ref_title : VFIXUPIMMSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFIXUPIMMSS

**Fix Up Special Scalar Float32 Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.NDS.LIG.66.0F3A.W0 55 /r ib\newline{}VFIXUPIMMSS xmm1 {k1}{z}, xmm2, xmm3/m32{sae}, imm8|T1S|V/V|AVX512F|Fix up a float32 number in the low doubleword element in xmm2 using scalar int32 table in xmm3/m32 and store the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (r, w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Perform a fix-up of the low doubleword element encoded in single-precision floating-point format in the first source operand (the second operand) using a 32-bit, two-level look-up table specified in the low doubleword element of the second source operand (the third operand) with exception reporting specifier imm8. The element that is fixed-up is selected by mask bit of 1 specified in the opmask k1. Mask bit of 0 in the opmask k1 or table response action of 0000b preserves the corresponding element of the first operand. The fixed-up element from the first source operand or the preserved element in the first operand becomes the low doubleword element of the destination operand (the first operand) Bits 127:32 of the destination operand is copied from the corresponding bits of the first source operand. The destination and first source operands are XMM registers. The second source operand can be a XMM register or a 32-bit memory location.

The two-level look-up table perform a fix-up of each SP FP input data in the first source operand by decoding the input data encoding into 8 token types. A response table is defined for each token type that converts the input encoding in the first source operand with one of 16 response actions. 

This instruction is specifically intended for use in fixing up the results of arithmetic calculations involving one source so that they match the spec, although it is generally useful for fixing up the results of multiple-instruction sequences to reflect special-number inputs. For example, consider rcp(0). Input 0 to rcp, and you should get INF according to the DX10 spec. However, evaluating rcp via Newton-Raphson, where x=approx(1/0), yields an incor-rect result. To deal with this, `VFIXUPIMMPD` can be used after the N-R reciprocal sequence to set the result to the correct value (i.e. INF when the input is 0).

If MXCSR.DAZ is not set, denormal input elements in the first source operand are considered as normal inputs and do not trigger any fixup nor fault reporting.

Imm8 is used to set the required flags reporting. It supports #ZE and #IE fault reporting (see details below).

MXCSR.DAZ is used and refer to zmm2 only (i.e. zmm1 is not considered as zero in case MXCSR.DAZ is set).

MXCSR mask bits are ignored and are treated as if all mask bits are set to masked response). If any of the imm8 bits is set and the condition met for fault reporting, MXCSR.IE or MXCSR.ZE might be updated.


### Operation
#### VFIXUPIMMSS (EVEX encoded version)
```info-verb
IF k1[0] OR *no writemask*
    THEN DEST[31:0] <-  FIXUPIMM_SP(DEST[31:0], SRC1[31:0], SRC2[31:0], imm8 [7:0])
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  DEST[31:0] <-  0 ; zeroing-masking
          FI
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
Immediate Control Description:
```
```embed
<figure>
<svg viewBox="0 0 396.480042 223.399994">
<rect x="0.000000" y="10.000000" width="0.480000" height="196.199997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="196.199997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519958" width="396.480011" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="206.260010" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,62.260010 L225.420013,62.260010 L225.420013,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M221.700012,53.980011 L225.420013,44.260010 L228.420013,53.980011 L221.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,80.260010 L242.700012,80.260010 L242.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M239.700012,53.980011 L242.700012,44.260010 L246.420013,53.980011 L239.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,98.260010 L260.700012,98.260010 L260.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M257.700012,53.980011 L260.700012,44.260010 L264.480011,53.980011 L257.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,116.260010 L278.700012,116.260010 L278.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M275.700012,53.980011 L278.700012,44.260010 L282.480011,53.980011 L275.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,134.260010 L296.700012,134.260010 L296.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M293.700012,53.980011 L296.700012,44.260010 L300.480011,53.980011 L293.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,152.260010 L314.700012,152.260010 L314.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M311.700012,53.980011 L314.700012,44.260010 L317.700012,53.980011 L311.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,169.480011 L332.700012,169.480011 L332.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M329.700012,53.980011 L332.700012,44.260010 L335.700012,53.980011 L329.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,187.480011 L350.700012,187.480011 L350.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M347.700012,53.980011 L350.700012,44.260010 L353.700012,53.980011 L347.700012,53.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.420013" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="216.420013" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.420013" y="26.260010" width="17.280001" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="234.420013" y="26.260010" width="17.280001" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="251.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
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
<rect x="36.420006" y="53.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="53.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="89.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="89.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="107.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="107.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="71.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="71.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="125.260010" width="108.000000" height="17.219999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="125.260010" width="108.000000" height="17.219999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="142.480011" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="142.480011" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="160.480011" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="160.480011" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="178.480011" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="178.480011" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<text x="130.921906" y="191.260010" textLength="7.200601" font-size="8px">E</text>
<text x="123.421272" y="191.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="115.920647" y="191.260010" textLength="7.200601" font-size="8px">#</text>
<text x="84.420418" y="191.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420418" y="191.260010" textLength="0.000000" font-size="8px"> </text>
<text x="58.200630" y="191.260010" textLength="7.200601" font-size="8px">E</text>
<text x="50.700005" y="191.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="123.421272" y="173.260010" textLength="7.200601" font-size="8px">I</text>
<text x="80.702507" y="173.260010" textLength="7.200601" font-size="8px"> </text>
<text x="65.701256" y="173.260010" textLength="7.200601" font-size="8px">R</text>
<text x="58.200630" y="173.260010" textLength="7.200601" font-size="8px">E</text>
<text x="130.921600" y="155.260010" textLength="7.200601" font-size="8px">E</text>
<text x="123.420967" y="155.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="115.920341" y="155.260010" textLength="7.200601" font-size="8px">#</text>
<text x="84.420113" y="155.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420113" y="155.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.421303" y="155.260010" textLength="7.200601" font-size="8px"> </text>
<text x="76.921883" y="155.260010" textLength="7.200601" font-size="8px"> </text>
<text x="69.421257" y="155.260010" textLength="7.200601" font-size="8px">E</text>
<text x="130.921600" y="138.040009" textLength="7.200601" font-size="8px">E</text>
<text x="123.420967" y="138.040009" textLength="7.200601" font-size="8px">I</text>
<text x="115.920341" y="138.040009" textLength="7.200601" font-size="8px">#</text>
<text x="84.420113" y="137.259918" textLength="0.000000" font-size="8px"> </text>
<text x="84.420113" y="137.259918" textLength="0.000000" font-size="8px"> </text>
<text x="54.420006" y="138.040009" textLength="7.200601" font-size="8px">O</text>
<text x="123.420509" y="84.040009" textLength="7.200601" font-size="8px">I</text>
<text x="115.919884" y="84.040009" textLength="7.200601" font-size="8px">#</text>
<text x="84.419655" y="84.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.419655" y="84.040009" textLength="0.000000" font-size="8px"> </text>
<text x="83.700798" y="84.040009" textLength="7.200601" font-size="8px"> </text>
<text x="76.200172" y="84.040009" textLength="7.200601" font-size="8px"> </text>
<text x="61.200127" y="84.040009" textLength="7.200601" font-size="8px">V</text>
<text x="130.921906" y="120.040009" textLength="7.200601" font-size="8px">E</text>
<text x="123.421272" y="120.040009" textLength="7.200601" font-size="8px">I</text>
<text x="73.201881" y="120.040009" textLength="7.200601" font-size="8px">N</text>
<text x="123.420509" y="102.040009" textLength="7.200601" font-size="8px">I</text>
<text x="84.419655" y="102.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.419655" y="102.040009" textLength="0.000000" font-size="8px"> </text>
<text x="79.920479" y="102.040009" textLength="7.200601" font-size="8px"> </text>
<text x="72.419853" y="102.040009" textLength="7.200601" font-size="8px">F</text>
<text x="64.919228" y="102.040009" textLength="7.200601" font-size="8px">N</text>
<text x="45.420006" y="102.040009" textLength="7.200601" font-size="8px">-</text>
<text x="130.921143" y="66.040009" textLength="7.200601" font-size="8px">E</text>
<text x="84.419655" y="66.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.419655" y="66.040009" textLength="0.000000" font-size="8px"> </text>
<text x="79.920479" y="66.040009" textLength="7.200601" font-size="8px"> </text>
<text x="72.419853" y="66.040009" textLength="7.200601" font-size="8px">F</text>
<text x="64.919228" y="66.040009" textLength="7.200601" font-size="8px">N</text>
<text x="57.419807" y="66.040009" textLength="7.200601" font-size="8px">I</text>
<text x="45.420006" y="66.040009" textLength="7.200601" font-size="8px">+</text>
<text x="349.980011" y="39.040009" textLength="6.672556" font-size="8px">0</text>
<text x="331.980011" y="39.040009" textLength="6.672556" font-size="8px">1</text>
<text x="295.980011" y="39.040009" textLength="6.672556" font-size="8px">3</text>
<text x="277.980011" y="39.040009" textLength="6.672556" font-size="8px">4</text>
<text x="259.980011" y="39.040009" textLength="6.672556" font-size="8px">5</text>
<text x="241.980011" y="39.040009" textLength="6.672556" font-size="8px">6</text>
<text x="223.980011" y="39.040009" textLength="6.672556" font-size="8px">7</text>
<text x="69.421257" y="138.040009" textLength="7.200601" font-size="8px">E</text>
<text x="61.920631" y="155.260010" textLength="7.200601" font-size="8px">N</text>
<text x="50.700005" y="120.040009" textLength="7.200601" font-size="8px">S</text>
<text x="50.700005" y="173.260010" textLength="7.200601" font-size="8px">Z</text>
<text x="57.419807" y="102.040009" textLength="7.200601" font-size="8px">I</text>
<text x="76.921883" y="138.040009" textLength="7.200601" font-size="8px"> </text>
<text x="73.201881" y="173.260010" textLength="7.200601" font-size="8px">O</text>
<text x="115.919884" y="66.040009" textLength="7.200601" font-size="8px">#</text>
<text x="130.921143" y="84.040009" textLength="7.200601" font-size="8px">E</text>
<text x="65.701256" y="191.260010" textLength="7.200601" font-size="8px">R</text>
<text x="54.420006" y="155.260010" textLength="7.200601" font-size="8px">O</text>
<text x="80.702507" y="191.260010" textLength="7.200601" font-size="8px"> </text>
<text x="65.701256" y="120.040009" textLength="7.200601" font-size="8px">a</text>
<text x="73.201881" y="191.260010" textLength="7.200601" font-size="8px">O</text>
<text x="313.980011" y="39.040009" textLength="6.672556" font-size="8px">2</text>
<text x="68.700752" y="84.040009" textLength="7.200601" font-size="8px">E</text>
<text x="130.921143" y="102.040009" textLength="7.200601" font-size="8px">E</text>
<text x="115.920647" y="120.040009" textLength="7.200601" font-size="8px">#</text>
<text x="123.420509" y="66.040009" textLength="7.200601" font-size="8px">I</text>
<text x="84.420418" y="173.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420418" y="173.260010" textLength="0.000000" font-size="8px"> </text>
<text x="130.921906" y="173.260010" textLength="7.200601" font-size="8px">E</text>
<text x="115.919884" y="102.040009" textLength="7.200601" font-size="8px">#</text>
<text x="45.420006" y="84.040009" textLength="7.200601" font-size="8px">-</text>
<text x="115.920647" y="173.260010" textLength="7.200601" font-size="8px">#</text>
<text x="84.421303" y="138.040009" textLength="7.200601" font-size="8px"> </text>
<text x="84.420418" y="120.040009" textLength="0.000000" font-size="8px"> </text>
<text x="84.420418" y="120.040009" textLength="0.000000" font-size="8px"> </text>
<text x="61.920631" y="138.040009" textLength="7.200601" font-size="8px">N</text>
<text x="58.200630" y="120.040009" textLength="7.200601" font-size="8px">N</text>
<text x="80.702507" y="120.040009" textLength="7.200601" font-size="8px"> </text>
</svg>
<figcaption>Figure 5-12.  VFIXUPIMMSS Immediate Control Description
</figcaption></figure>
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFIXUPIMMSS __m128 _mm_fixupimm_ss( __m128 a, __m128i tbl, int imm);
VFIXUPIMMSS __m128 _mm_mask_fixupimm_ss(__m128 s, __mmask8 k, __m128 a, __m128i tbl, int imm);
VFIXUPIMMSS __m128 _mm_maskz_fixupimm_ss( __mmask8 k, __m128 a, __m128i tbl, int imm);
VFIXUPIMMSS __m128 _mm_fixupimm_round_ss( __m128 a, __m128i tbl, int imm, int sae);
VFIXUPIMMSS __m128 _mm_mask_fixupimm_round_ss(__m128 s, __mmask8 k, __m128 a, __m128i tbl, int imm, int sae);
VFIXUPIMMSS __m128 _mm_maskz_fixupimm_round_ss( __mmask8 k, __m128 a, __m128i tbl, int imm, int sae);
```
### SIMD Floating-Point Exceptions


Zero, Invalid

### Other Exceptions


See Exceptions Type E3.

