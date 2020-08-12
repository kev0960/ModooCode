----------------------------
title : CVTDQ2PD (Intel x86/64 assembly instruction)
cat_title : CVTDQ2PD
ref_title : CVTDQ2PD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ CVTDQ2PD

**Convert Packed Doubleword Integers to Packed Double-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F E6 /r\newline{}CVTDQ2PD xmm1, xmm2/m64|RM|V/V|SSE2|Convert two packed signed doubleword integers from xmm2/mem to two packed double-precision floating-point values in xmm1.|
|VEX.128.F3.0F.WIG E6 /r\newline{}VCVTDQ2PD xmm1, xmm2/m64|RM|V/V|AVX|Convert two packed signed doubleword integers from xmm2/mem to two packed double-precision floating-point values in xmm1.|
|VEX.256.F3.0F.WIG E6 /r\newline{}VCVTDQ2PD ymm1, xmm2/m128|RM|V/V|AVX|Convert four packed signed doubleword integers from xmm2/mem to four packed double-precision floating-point values in ymm1.|
|EVEX.128.F3.0F.W0 E6 /r\newline{}VCVTDQ2PD xmm1 {k1}{z}, xmm2/m128/m32bcst |HV|V/V|AVX512VLAVX512F|Convert 2 packed signed doubleword integers from xmm2/m128/m32bcst to eight packed double-precision floating-point values in xmm1 with writemask k1.|
|EVEX.256.F3.0F.W0 E6 /r\newline{}VCVTDQ2PD ymm1 {k1}{z}, xmm2/m128/m32bcst |HV|V/V|AVX512VLAVX512F|Convert 4 packed signed doubleword integers from xmm2/m128/m32bcst to 4 packed double-precision floating-point values in ymm1 with writemask k1.|
|EVEX.512.F3.0F.W0 E6 /r\newline{}VCVTDQ2PD zmm1 {k1}{z}, ymm2/m256/m32bcst |HV|V/V|AVX512F|Convert eight packed signed doubleword integers from ymm2/m256/m32bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|HV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two, four or eight packed signed doubleword integers in the source operand (the second operand) to two, four or eight packed double-precision floating-point values in the destination operand (the first operand). 

EVEX encoded versions: The source operand can be a YMM/XMM/XMM (low 64 bits) register, a 256/128/64-bit memory location or a 256/128/64-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1. Attempt to encode this instruction with EVEX embedded rounding is ignored.

VEX.256 encoded version: The source operand is an XMM register or 128- bit memory location. The destination operand is a YMM register. 

VEX.128 encoded version: The source operand is an XMM register or 64- bit memory location. The destination operand is a XMM register. The upper Bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The source operand is an XMM register or 64- bit memory location. The destination operand is an XMM register. The upper Bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified.

VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.480042 214.619995">
<rect x="0.000000" y="10.000000" width="0.480000" height="117.480003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="117.480003" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="127.480042" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M114.599998,93.700012 L114.659996,93.880005 L114.779991,94.000000 L115.139992,94.239990 L115.320000,94.299988 L115.680000,94.299988 L115.859993,94.239990 L116.040001,94.119995 C116.460991 93.898987,116.353996 93.731995,116.519997 93.340027  L116.459999,93.100037 L116.340004,92.739990 L116.219994,92.619995 L115.859993,92.380005 L115.680000,92.320007 L115.320000,92.320007 L115.139992,92.380005 C114.633003 92.744019,114.715996 92.541016,114.540001 93.100037  L114.480003,93.280029 L114.540001,93.520020 L114.599998,93.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.439995,93.340027 L117.059990,97.300049 L117.299995,97.960022 L116.639992,98.020020 L101.159996,99.700012 L99.419991,99.880005 L100.799995,98.800049 L113.040001,89.140015 L113.579994,88.720032 L113.820000,89.320007 L113.699989,89.920044 L101.459999,99.580017 L100.799995,98.800049 L101.099998,98.680054 L116.579994,97.000000 L116.639992,98.020020 L116.159996,97.660034 L114.540001,93.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.820000,89.320007 L115.439995,93.340027 L114.540001,93.700012 L112.920006,89.679993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.019997,93.520020 L116.639992,97.480042 L101.159996,99.160034 L113.400002,89.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.540009,46.840027 L230.760010,44.980042 L115.140007,92.380005 L115.920006,94.240051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.619995" y="32.380005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="325.619995" y="32.140015" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="362.520020" y="32.380005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.380005" y="45.640015" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.380005" y="32.140015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M327.960022,84.580017 L328.140015,84.640015 L328.380035,84.700012 C329.360016 84.506042,329.706024 83.420044,328.860016 82.840027  L328.680023,82.720032 L328.500031,82.660034 C327.526031 82.515015,326.877014 83.791016,327.660034 84.400024  L327.780029,84.520020 L327.960022,84.580017" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.320007,83.739990 L332.339996,85.239990 L332.940002,85.479980 L332.520020,86.020020 L323.220001,98.559998 L322.200012,99.940002 L322.320007,98.200012 L323.580017,82.659973 L323.700012,82.000000 L324.300018,82.239990 L324.600006,82.719971 L323.339996,98.260010 L322.320007,98.200012 L322.440002,97.899963 L331.740021,85.359985 L332.520020,86.020020 L331.980011,86.140015 L327.960022,84.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M324.300018,82.239990 L328.320007,83.739990 L327.960022,84.640015 L323.940033,83.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.140015,84.160034 L332.160004,85.660034 L322.860016,98.200012 L324.120026,82.660034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M343.440002,46.239990 L341.580017,45.520020 L327.420013,83.320007 L329.279999,84.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.920013,88.359985 L263.040009,88.479980 L263.220001,88.539978 C264.096008 88.984009,265.023010 87.846008,264.420013 87.099976  L264.300018,86.919983 L264.180023,86.799988 L263.820007,86.679993 L263.580017,86.619995 L263.040009,86.799988 L262.920013,86.919983 C262.611023 87.406006,262.610016 87.247009,262.620026 87.820007  L262.680023,88.000000 L262.920013,88.359985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.640015,87.640015 L266.640015,90.700012 L267.060028,91.239990 L252.900024,99.100037 L251.340027,99.940002 L252.180023,98.380005 L259.740021,84.700012 L260.100006,84.160034 L260.580017,84.580017 L260.640015,85.179993 L253.080017,98.859985 L252.180023,98.380005 L252.420013,98.200012 L266.040009,90.640015 L266.520020,91.540039 L265.920013,91.420044 L262.920013,88.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.580017,84.580017 L263.640015,87.640015 L262.920013,88.360046 L259.860016,85.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.279999,88.000000 L266.279999,91.059998 L252.660004,98.619995 L260.220001,84.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.119995,46.600037 L304.739990,45.220032 L262.919983,86.980042 L264.299988,88.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M191.160004,91.540039 L191.279999,91.720032 L191.399994,91.840027 C192.127014 92.496033,193.303009 91.580017,192.959991 90.700012  L192.839996,90.520020 L192.720001,90.400024 C192.199005 89.599060,190.806000 90.309021,191.040009 91.180054  L191.040009,91.360046 L191.160004,91.540039" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M192.000000,91.059998 L194.160004,94.779968 L194.459991,95.380005 L193.799988,95.500000 L178.799988,99.400024 L177.059998,99.880005 L178.260010,98.619995 L188.940002,87.340027 L189.420013,86.799988 L189.779999,87.400024 L189.720001,88.000000 L179.040009,99.279968 L178.260010,98.619995 L178.559998,98.440002 L193.619995,94.539978 L193.799988,95.500000 L193.260010,95.320007 L191.100006,91.599976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.779999,87.400024 L192.000000,91.059998 L191.100006,91.600037 L188.880005,87.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M191.580017,91.299988 L193.740021,95.019958 L178.680023,98.919983 L189.360016,87.640015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M268.800018,46.720032 L267.780029,45.040039 L191.520020,90.220032 L192.540009,91.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.480011" y="32.380005" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="288.480011" y="32.140015" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.380005" y="32.380005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.240021" y="45.640015" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.240021" y="32.140015" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.400024" y="32.380005" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="251.400024" y="32.140015" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.240021" y="32.380005" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.160004" y="45.640015" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.160004" y="32.140015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.760010" y="32.020020" width="38.639999" height="13.860000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="212.760010" y="31.780029" width="38.880001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.160004" y="32.020020" width="0.480010" height="14.100000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.520020" y="45.640015" width="38.880001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.520020" y="31.780029" width="0.479980" height="14.100000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.940002" y="99.880005" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="287.940002" y="99.640015" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="361.920013" y="99.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="113.140015" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="99.640015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="65.159996" y="99.880005" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="65.159996" y="99.640015" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="139.200012" y="99.880005" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="64.920006" y="113.140015" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="64.920006" y="99.640015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.600006" y="99.880005" width="84.059998" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="129.600006" y="99.640015" width="84.300003" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.420013" y="99.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.360016" y="113.140015" width="84.300003" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.360016" y="99.640015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.660004" y="99.880005" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="213.660004" y="99.640015" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="99.880005" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.420013" y="113.140015" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.420013" y="99.640015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="321.659180" y="108.400024" textLength="5.530430" font-size="8px">X</text>
<text x="173.160004" y="108.400024" textLength="5.002500" font-size="8px">X</text>
<text x="93.839989" y="108.400024" textLength="4.170000" font-size="8px">3</text>
<text x="88.799995" y="108.400024" textLength="5.002500" font-size="8px">X</text>
<text x="230.280029" y="40.900024" textLength="4.170000" font-size="8px">3</text>
<text x="267.480011" y="40.900024" textLength="4.170000" font-size="8px">2</text>
<text x="262.440002" y="40.900024" textLength="5.002500" font-size="8px">X</text>
<text x="299.580017" y="40.900024" textLength="5.002500" font-size="8px">X</text>
<text x="341.700012" y="40.900024" textLength="4.170000" font-size="8px">0</text>
<text x="56.098503" y="42.520020" textLength="5.415000" font-size="8px">C</text>
<text x="45.480003" y="111.760010" textLength="5.415000" font-size="8px">D</text>
<text x="45.720009" y="42.520020" textLength="5.002500" font-size="8px">S</text>
<text x="247.500000" y="108.400024" textLength="5.530430" font-size="8px">X</text>
<text x="50.703011" y="42.520020" textLength="5.415000" font-size="8px">R</text>
<text x="225.300018" y="40.900024" textLength="5.002500" font-size="8px">X</text>
<text x="55.915489" y="111.760010" textLength="5.002500" font-size="8px">S</text>
<text x="60.898491" y="111.760010" textLength="4.582500" font-size="8px">T</text>
<text x="50.875496" y="111.760010" textLength="5.002500" font-size="8px">E</text>
<text x="336.720001" y="40.900024" textLength="5.002500" font-size="8px">X</text>
<text x="178.140015" y="108.400024" textLength="4.170000" font-size="8px">2</text>
<text x="253.020477" y="108.400024" textLength="4.610074" font-size="8px">1</text>
<text x="304.560028" y="40.900024" textLength="4.170000" font-size="8px">1</text>
<text x="327.119141" y="108.400024" textLength="4.610074" font-size="8px">0</text>
</svg>
<figcaption>Figure 3-11.  CVTDQ2PD (VEX.256 encoded version)
</figcaption></figure>
```

### Operation
#### VCVTDQ2PD (EVEX encoded versions) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j  <-  0 TO KL-1
    i  <-  j * 64
    k <-   j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <- 
                Convert_Integer_To_Double_Precision_Floating_Point(SRC[k+31:k])
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VCVTDQ2PD (EVEX encoded versions) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j  <-  0 TO KL-1
    i <-   j * 64
    k  <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) 
                      THEN
                            DEST[i+63:i] <- 
                Convert_Integer_To_Double_Precision_Floating_Point(SRC[31:0])
                      ELSE 
                            DEST[i+63:i] <- 
                Convert_Integer_To_Double_Precision_Floating_Point(SRC[k+31:k])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VCVTDQ2PD (VEX.256 encoded version)
```info-verb
DEST[63:0]  <-  Convert_Integer_To_Double_Precision_Floating_Point(SRC[31:0])
DEST[127:64] <-   Convert_Integer_To_Double_Precision_Floating_Point(SRC[63:32])
DEST[191:128] <-   Convert_Integer_To_Double_Precision_Floating_Point(SRC[95:64])
DEST[255:192] <-   Convert_Integer_To_Double_Precision_Floating_Point(SRC[127:96)
DEST[MAX_VL-1:256]  <-  0
```
#### VCVTDQ2PD (VEX.128 encoded version)
```info-verb
DEST[63:0]  <-  Convert_Integer_To_Double_Precision_Floating_Point(SRC[31:0])
DEST[127:64]  <-  Convert_Integer_To_Double_Precision_Floating_Point(SRC[63:32])
DEST[MAX_VL-1:128] <-   0
```
#### CVTDQ2PD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <-   Convert_Integer_To_Double_Precision_Floating_Point(SRC[31:0])
DEST[127:64]  <-  Convert_Integer_To_Double_Precision_Floating_Point(SRC[63:32])
DEST[MAX_VL-1:128] (unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTDQ2PD __m512d _mm512_cvtepi32_pd( __m256i a);
VCVTDQ2PD __m512d _mm512_mask_cvtepi32_pd( __m512d s, __mmask8 k, __m256i a);
VCVTDQ2PD __m512d _mm512_maskz_cvtepi32_pd( __mmask8 k, __m256i a);
VCVTDQ2PD __m256d _mm256_mask_cvtepi32_pd( __m256d s, __mmask8 k, __m256i a);
VCVTDQ2PD __m256d _mm256_maskz_cvtepi32_pd( __mmask8 k, __m256i a);
VCVTDQ2PD __m128d _mm_mask_cvtepi32_pd( __m128d s, __mmask8 k, __m128i a);
VCVTDQ2PD __m128d _mm_maskz_cvtepi32_pd( __mmask8 k, __m128i a);
CVTDQ2PD __m256d _mm256_cvtepi32_pd (__m128i src)
CVTDQ2PD __m128d _mm_cvtepi32_pd (__m128i src)
```
### Other Exceptions


VEX-encoded instructions, see Exceptions Type 5; 

EVEX-encoded instructions, see Exceptions Type E5.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

