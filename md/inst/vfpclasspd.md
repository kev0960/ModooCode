----------------------------
title : VFPCLASSPD (Intel x86/64 assembly instruction)
cat_title : VFPCLASSPD
ref_title : VFPCLASSPD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VFPCLASSPD

**Tests Types Of a Packed Float64 Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F3A.W1 66 /r ib\newline{}VFPCLASSPD k2 {k1}, xmm2/m128/m64bcst, imm8|FV|V/V|AVX512VLAVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
|EVEX.256.66.0F3A.W1 66 /r ib\newline{}VFPCLASSPD k2 {k1}, ymm2/m256/m64bcst, imm8|FV|V/V|AVX512VLAVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
|EVEX.512.66.0F3A.W1 66 /r ib\newline{}VFPCLASSPD k2 {k1}, zmm2/m512/m64bcst, imm8|FV|V/V|AVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


The FPCLASSPD instruction checks the packed double precision floating point values for special categories, speci-fied by the set bits in the imm8 byte. Each set bit in imm8 specifies a category of floating-point values that the input data element is classified against. The classified results of all specified categories of an input value are ORed together to form the final boolean result for the input element. The result of each element is written to the corre-sponding bit in a mask register k2 according to the writemask k1. Bits [MAX_KL-1:8/4/2] of the destination are cleared.

The classification categories specified by imm8 are shown in Figure 5-13. The classification test for each category is listed in Table 5-6.

```embed
<figure>
<svg viewBox="0 0 499.200043 80.320007">
<rect x="0.060001" y="9.999969" width="0.480000" height="53.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="498.720001" y="9.999969" width="0.479980" height="53.099998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="499.200012" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="63.159973" width="499.200012" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="101.580002" y="36.819977" width="298.799988" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="399.899994" y="37.059998" width="0.479980" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="101.339996" y="50.079987" width="298.799988" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="101.339996" y="36.819977" width="0.480000" height="13.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.260010" y="37.059998" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.260010" y="37.299988" width="0.479980" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="250.619995" y="37.059998" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="250.619995" y="37.299988" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="175.980011" y="37.059998" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="175.980011" y="37.299988" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="362.580017" y="37.059998" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="362.580017" y="37.299988" width="0.479980" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.940002" y="37.059998" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.940002" y="37.299988" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.300018" y="37.059998" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.300018" y="37.299988" width="0.480010" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="138.720001" y="37.059998" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="138.720001" y="37.299988" width="0.480000" height="13.260000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="333.538818" y="46.419983" textLength="3.510000" font-size="8px">0</text>
<text x="330.120026" y="46.419983" textLength="3.450000" font-size="8px">+</text>
<text x="297.655792" y="45.879974" textLength="3.900000" font-size="8px">N</text>
<text x="266.992798" y="45.879974" textLength="3.900000" font-size="8px">N</text>
<text x="265.592407" y="45.879974" textLength="1.398000" font-size="8px">I</text>
<text x="244.221008" y="45.399963" textLength="3.150000" font-size="8px">F</text>
<text x="238.915802" y="45.399963" textLength="1.398000" font-size="8px">I</text>
<text x="236.335815" y="45.399963" textLength="1.140000" font-size="8px">.</text>
<text x="230.043610" y="45.399963" textLength="3.144000" font-size="8px">e</text>
<text x="226.140015" y="45.399963" textLength="3.900000" font-size="8px">N</text>
<text x="201.160828" y="45.879974" textLength="2.982000" font-size="8px">a</text>
<text x="196.526428" y="45.879974" textLength="4.632000" font-size="8px">m</text>
<text x="191.165421" y="45.879974" textLength="3.150000" font-size="8px">o</text>
<text x="184.856415" y="45.879974" textLength="3.144000" font-size="8px">e</text>
<text x="160.864227" y="45.879974" textLength="3.186000" font-size="8px">n</text>
<text x="159.603027" y="45.879974" textLength="1.302000" font-size="8px">i</text>
<text x="153.782425" y="45.879974" textLength="1.140000" font-size="8px">.</text>
<text x="150.723022" y="45.879974" textLength="3.108000" font-size="8px">g</text>
<text x="143.640015" y="45.879974" textLength="3.900000" font-size="8px">N</text>
<text x="110.640015" y="44.919983" textLength="3.186000" font-size="8px">S</text>
<text x="385.443024" y="45.879974" textLength="3.900000" font-size="8px">N</text>
<text x="378.531006" y="45.879974" textLength="3.900000" font-size="8px">N</text>
<text x="374.640015" y="45.879974" textLength="3.876000" font-size="8px">Q</text>
<text x="342.360016" y="32.019989" textLength="3.510000" font-size="8px">1</text>
<text x="268.200012" y="32.019989" textLength="3.510000" font-size="8px">3</text>
<text x="157.019989" y="32.019989" textLength="3.510000" font-size="8px">6</text>
<text x="231.119995" y="32.019989" textLength="3.510000" font-size="8px">4</text>
<text x="379.440002" y="32.019989" textLength="3.510000" font-size="8px">0</text>
<text x="117.741623" y="44.919983" textLength="2.982000" font-size="8px">a</text>
<text x="154.923019" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="194.346024" y="45.879974" textLength="2.178000" font-size="8px">r</text>
<text x="181.137619" y="45.879974" textLength="3.690000" font-size="8px">D</text>
<text x="164.052628" y="45.879974" textLength="1.302000" font-size="8px">i</text>
<text x="156.422424" y="45.879974" textLength="3.150000" font-size="8px">F</text>
<text x="167.637024" y="45.879974" textLength="3.144000" font-size="8px">e</text>
<text x="120.731430" y="44.919983" textLength="3.900000" font-size="8px">N</text>
<text x="310.456787" y="45.879974" textLength="3.510000" font-size="8px">0</text>
<text x="204.145233" y="45.879974" textLength="1.284000" font-size="8px">l</text>
<text x="305.279999" y="32.019989" textLength="3.510000" font-size="8px">2</text>
<text x="307.815002" y="45.879974" textLength="1.140000" font-size="8px">.</text>
<text x="119.940002" y="32.019989" textLength="3.510000" font-size="8px">7</text>
<text x="262.140015" y="45.879974" textLength="3.450000" font-size="8px">+</text>
<text x="240.317413" y="45.399963" textLength="3.900000" font-size="8px">N</text>
<text x="187.977020" y="45.879974" textLength="3.186000" font-size="8px">n</text>
<text x="301.558197" y="45.879974" textLength="3.144000" font-size="8px">e</text>
<text x="113.833817" y="44.919983" textLength="3.900000" font-size="8px">N</text>
<text x="308.957397" y="45.879974" textLength="1.482000" font-size="8px"> </text>
<text x="165.357025" y="45.879974" textLength="2.250000" font-size="8px">t</text>
<text x="237.416412" y="45.399963" textLength="1.482000" font-size="8px"> </text>
<text x="304.704590" y="45.879974" textLength="3.108000" font-size="8px">g</text>
<text x="194.040009" y="32.019989" textLength="3.510000" font-size="8px">5</text>
<text x="233.224213" y="45.399963" textLength="3.108000" font-size="8px">g</text>
<text x="270.895203" y="45.879974" textLength="3.150000" font-size="8px">F</text>
<text x="382.446014" y="45.879974" textLength="2.982000" font-size="8px">a</text>
<text x="147.542419" y="45.879974" textLength="3.144000" font-size="8px">e</text>
</svg>
<figcaption>Figure 5-13.  Imm8 Byte Specifier of Special Case FP Values for VFPCLASSPD/SD/PS/SS
</figcaption></figure>
```
###                                          Table 5-6. Classifier Operations for VFPCLASSPD/SD/PS/SS


The source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 64-bit memory location.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.



|**Bits**|**Imm8[0]**|**Imm8[1]**|**Imm8[2]**|**Imm8[3]**|**Imm8[4]**|**Imm8[5]**|**Imm8[6]**|**Imm8[7]**|
|--------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|
|Category|QNAN|PosZero|NegZero|PosINF|NegINF|Denormal|Negative|SNAN|
|Classifier|Checks for QNaN|Checks for +0|Checks for -0|Checks for +INF|Checks for -INF|Checks for Denormal|Checks for Negative finite|Checks for SNaN|

### Operation
#### VFPCLASSPD (EVEX Encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-   0 TO KL-1
    i <-   j * 64
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b == 1) AND (SRC *is memory*)
                      THEN
                            DEST[j]  <-  CheckFPClassDP(SRC1[63:0], imm8[7:0]);
                      ELSE 
                            DEST[j] <-   CheckFPClassDP(SRC1[i+63:i], imm8[7:0]);
                FI;
          ELSE DEST[j] <-   0 ; zeroing-masking only
    FI;
ENDFOR
DEST[MAX_KL-1:KL]  <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFPCLASSPD __mmask8 _mm512_fpclass_pd_mask( __m512d a, int c);
VFPCLASSPD __mmask8 _mm512_mask_fpclass_pd_mask( __mmask8 m, __m512d a, int c)
VFPCLASSPD __mmask8 _mm256_fpclass_pd_mask( __m256d a, int c)
VFPCLASSPD __mmask8 _mm256_mask_fpclass_pd_mask( __mmask8 m, __m256d a, int c)
VFPCLASSPD __mmask8 _mm_fpclass_pd_mask( __m128d a, int c)
VFPCLASSPD __mmask8 _mm_mask_fpclass_pd_mask( __mmask8 m, __m128d a, int c)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4

#UD If EVEX.vvvv != 1111B.

