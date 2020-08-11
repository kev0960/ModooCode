----------------------------
title : CVTPS2PD (Intel x86/64 assembly instruction)
cat_title : CVTPS2PD
ref_title : CVTPS2PD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ CVTPS2PD

**Convert Packed Single-Precision Floating-Point Values to Packed Double-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 5A /rCVTPS2PD xmm1, xmm2/m64|RM|V/V|SSE2|Convert two packed single-precision floating-point values in xmm2/m64 to two packed double-precision floating-point values in xmm1.|
|VEX.128.0F.WIG 5A /rVCVTPS2PD xmm1, xmm2/m64|RM|V/V|AVX|Convert two packed single-precision floating-point values in xmm2/m64 to two packed double-precision floating-point values in xmm1.|
|VEX.256.0F.WIG 5A /rVCVTPS2PD ymm1, xmm2/m128|RM|V/V|AVX|Convert four packed single-precision floating-point values in xmm2/m128 to four packed double-precision floating-point values in ymm1.|
|EVEX.128.0F.W0 5A /rVCVTPS2PD xmm1 {k1}{z}, xmm2/m64/m32bcst |HV|V/V|AVX512VLAVX512F|Convert two packed single-precision floating-point values in xmm2/m64/m32bcst to packed double-precision floating-point values in xmm1 with writemask k1.|
|EVEX.256.0F.W0 5A /rVCVTPS2PD ymm1 {k1}{z}, xmm2/m128/m32bcst |HV|V/V|AVX512VL|Convert four packed single-precision floating-point values in xmm2/m128/m32bcst to packed double-precision floating-point values in ymm1 with writemask k1.|
|EVEX.512.0F.W0 5A /rVCVTPS2PD zmm1 {k1}{z}, ymm2/m256/m32bcst{sae} |HV|V/V|AVX512F|Convert eight packed single-precision floating-point values in ymm2/m256/b32bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|HV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two, four or eight packed single-precision floating-point values in the source operand (second operand) to two, four or eight packed double-precision floating-point values in the destination operand (first operand). 

EVEX encoded versions: The source operand is a YMM/XMM/XMM (low 64-bits) register, a 256/128/64-bit memory location or a 256/128/64-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register conditionally updated with writemask k1. 

VEX.256 encoded version: The source operand is an XMM register or 128- bit memory location. The destination operand is a YMM register. Bits (MAX_VL-1:256) of the corresponding destination ZMM register are zeroed.

VEX.128 encoded version: The source operand is an XMM register or 64- bit memory location. The destination operand is a XMM register. The upper Bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The source operand is an XMM register or 64- bit memory location. The destination operand is an XMM register. The upper Bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.539978 256.799988">
<rect x="0.000000" y="10.000000" width="0.480000" height="159.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.479980" height="159.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="169.659973" width="396.540009" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M79.320007,111.100037 L79.440002,111.280029 L79.560013,111.400024 L79.680008,111.520020 L79.860001,111.640015 L80.040009,111.700012 L80.460007,111.700012 L80.640015,111.640015 L81.000000,111.400024 L81.120010,111.280029 L81.240005,110.920044 L81.240005,110.500061 L81.120010,110.140015 C80.545013 109.360046,79.279007 109.684021,79.260010 110.680054  L79.260010,110.860046 L79.320007,111.100037" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.220001,110.679993 L81.839996,114.700012 L82.080002,115.359985 L81.419998,115.419983 L65.940002,117.099976 L64.199997,117.279968 L65.580002,116.200012 L77.820007,106.539978 L78.360001,106.119995 L78.600006,106.719971 L78.479996,107.320007 L66.240005,116.979980 L65.580002,116.200012 L65.880005,116.080017 L81.360001,114.399963 L81.419998,115.419983 L80.940002,115.059998 L79.320007,111.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M78.600006,106.720032 L80.220001,110.680054 L79.320007,111.040039 L77.700012,107.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M79.800003,110.859985 L81.419998,114.880005 L65.940002,116.559998 L78.180008,106.899963" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M196.319992,64.239990 L195.539993,62.380005 L79.919998,109.779968 L80.699997,111.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.400024" y="49.780029" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="290.400024" y="49.540039" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="327.299988" y="49.780029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.159973" y="63.040039" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.159973" y="49.540039" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.739990,101.979980 L292.919983,102.039978 L293.160034,102.039978 C293.974976 102.080994,294.515015 100.859985,293.640015 100.239990  L293.460022,100.119995 L293.220032,100.059998 C292.233032 100.046997,291.729004 101.015991,292.380005 101.799988  L292.559998,101.919983 L292.739990,101.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M293.099976,101.140015 L297.119995,102.640015 L297.719971,102.880005 L297.299988,103.420044 L288.000000,115.900024 L286.979980,117.280029 L287.099976,115.540039 L288.359985,100.000000 L288.479980,99.340027 L289.080017,99.580017 L289.380005,100.059998 L288.119995,115.600037 L287.099976,115.540039 L287.219971,115.239990 L296.520020,102.760010 L297.299988,103.420044 L296.760010,103.540039 L292.739990,102.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M289.080017,99.580017 L293.099976,101.140015 L292.739990,102.040039 L288.720032,100.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.919983,101.559998 L296.940002,103.059998 L287.640015,115.539978 L288.900024,100.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.220032,63.640015 L306.360046,62.920044 L292.200012,100.720032 L294.059998,101.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M227.639999,105.760010 L227.819992,105.880005 L227.999985,105.940002 C228.811996 106.363037,229.835007 105.252014,229.199997 104.500000  L229.080002,104.320007 L228.900009,104.200012 C228.055008 103.699036,227.133011 104.426025,227.460007 105.400024  L227.520004,105.580017 L227.639999,105.760010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.360001,105.040039 L231.419998,108.040039 L231.840012,108.580017 L231.300003,108.880066 L217.680008,116.440063 L216.120010,117.280029 L216.960007,115.720032 L224.520004,102.100037 L224.879990,101.560059 L225.360001,101.980042 L225.419998,102.580017 L217.860001,116.200012 L216.960007,115.720032 L217.199997,115.540039 L230.819992,107.980042 L231.300003,108.880066 L230.699997,108.760010 L227.639999,105.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.360001,101.979980 L228.360001,105.039978 L227.639999,105.760010 L224.639999,102.699951" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.000015,105.400024 L231.060013,108.400024 L217.440018,115.960022 L225.000015,102.340027" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.840027,64.000000 L269.460022,62.619995 L227.700027,104.380005 L229.080002,105.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M155.940018,108.940002 L156.060013,109.119995 L156.180008,109.239990 L156.360031,109.359985 L156.540024,109.419983 L157.080032,109.419983 L157.440018,109.179993 C157.772018 108.862976,157.747025 108.746033,157.740005 108.340027  L157.740005,108.099976 L157.620010,107.919983 L157.500015,107.799988 L157.380020,107.619995 L156.840012,107.440002 L156.660019,107.440002 L156.420029,107.500000 L156.240005,107.559998 C155.764023 108.013977,155.992020 107.796997,155.760025 108.400024  L155.760025,108.580017 L155.820023,108.760010 L155.940018,108.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M156.780014,108.460022 L158.940018,112.179993 L159.240005,112.780029 L158.580002,112.900024 L143.580017,116.800049 L141.840012,117.280029 L143.040009,116.020020 L153.720016,104.679993 L154.200027,104.140015 L154.560013,104.740051 L154.500015,105.340027 L143.820007,116.679993 L143.040009,116.020020 L143.340012,115.840027 L158.400009,111.940002 L158.580002,112.900024 L158.040024,112.720032 L155.880020,109.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.560013,104.739990 L156.780014,108.459961 L155.880020,109.000000 L153.660019,105.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M156.360001,108.700012 L158.520004,112.419983 L143.460007,116.320007 L154.139999,104.980042" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M233.580002,64.119995 L232.560013,62.440002 L156.300003,107.619995 L157.319992,109.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.259995" y="49.780029" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="253.259995" y="49.540039" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.159973" y="49.780029" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.020004" y="63.040039" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.020004" y="49.540039" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.120010" y="49.780029" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="216.120010" y="49.540039" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.020004" y="49.780029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.879990" y="63.040039" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.879990" y="49.540039" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="179.039993" y="49.780029" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="179.039993" y="49.540039" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.879990" y="49.780029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.800003" y="63.040039" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.800003" y="49.540039" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.720016" y="117.280029" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.720016" y="117.039978" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.700012" y="117.280029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.479996" y="130.539978" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.479996" y="117.040039" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.940002" y="117.280029" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="29.940002" y="117.039978" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.979996" y="117.280029" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.699997" y="130.539978" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.699997" y="117.040039" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.220001" y="117.280029" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="104.220001" y="117.039978" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.199997" y="117.280029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.979996" y="130.539978" width="74.459999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.979996" y="117.040039" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.440018" y="117.280029" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.440018" y="117.039978" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.479996" y="117.280029" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.199997" y="130.539978" width="74.519997" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.199997" y="117.040039" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="291.958862" y="125.799988" textLength="4.610074" font-size="8px">0</text>
<text x="212.280014" y="125.799988" textLength="5.530430" font-size="8px">X</text>
<text x="190.080002" y="58.299988" textLength="5.002500" font-size="8px">X</text>
<text x="264.359985" y="58.299988" textLength="5.002500" font-size="8px">X</text>
<text x="306.540039" y="58.299988" textLength="4.170000" font-size="8px">0</text>
<text x="301.500000" y="58.299988" textLength="5.002500" font-size="8px">X</text>
<text x="20.938507" y="59.920044" textLength="5.415000" font-size="8px">C</text>
<text x="15.480003" y="59.920044" textLength="5.415000" font-size="8px">R</text>
<text x="10.500000" y="59.920044" textLength="5.002500" font-size="8px">S</text>
<text x="20.638504" y="129.160034" textLength="5.002500" font-size="8px">S</text>
<text x="15.655502" y="129.160034" textLength="5.002500" font-size="8px">E</text>
<text x="10.260002" y="129.160034" textLength="5.415000" font-size="8px">D</text>
<text x="53.580002" y="125.799988" textLength="5.002500" font-size="8px">X</text>
<text x="286.439209" y="125.799988" textLength="5.530430" font-size="8px">X</text>
<text x="195.060013" y="58.299988" textLength="4.170000" font-size="8px">3</text>
<text x="217.739975" y="125.799988" textLength="4.610074" font-size="8px">1</text>
<text x="232.200027" y="58.299988" textLength="4.170000" font-size="8px">2</text>
<text x="137.940002" y="125.799988" textLength="5.002500" font-size="8px">X</text>
<text x="58.559998" y="125.799988" textLength="4.170000" font-size="8px">3</text>
<text x="227.220016" y="58.299988" textLength="5.002500" font-size="8px">X</text>
<text x="269.340027" y="58.299988" textLength="4.170000" font-size="8px">1</text>
<text x="25.678497" y="129.160034" textLength="4.582500" font-size="8px">T</text>
<text x="142.919998" y="125.799988" textLength="4.170000" font-size="8px">2</text>
</svg>
<figcaption>Figure 3-14.  `CVTPS2PD` (VEX.256 encoded version)
</figcaption></figure>
```

### Operation
#### VCVTPS2PD (EVEX encoded versions) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j  <- 0 TO KL-1
 i  <- j * 64
 k <-  j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+63:i] <- 
    Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[k+31:k])
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
      ELSE  ; zeroing-masking
        DEST[i+63:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VCVTPS2PD (EVEX encoded versions) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
 i  <- j * 64
 k  <- j * 32
 IF k1[j] OR *no writemask*
   THEN 
    IF (EVEX.b = 1) 
      THEN
        DEST[i+63:i]  <-
    Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[31:0])
      ELSE 
        DEST[i+63:i]  <-
    Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[k+31:k])
    FI;
   ELSE 
IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
      ELSE  ; zeroing-masking
        DEST[i+63:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VCVTPS2PD (VEX.256 encoded version)
```info-verb
DEST[63:0] <-  Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[31:0])
DEST[127:64] <-  Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[63:32])
DEST[191:128]  <- Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[95:64])
DEST[255:192]  <- Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[127:96)
DEST[MAX_VL-1:256] <-  0
```
#### VCVTPS2PD (VEX.128 encoded version)
```info-verb
DEST[63:0]  <- Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[31:0])
DEST[127:64] <-  Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[63:32])
DEST[MAX_VL-1:128] <-  0
```
#### CVTPS2PD (128-bit Legacy SSE version)
```info-verb
DEST[63:0]  <- Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[31:0])
DEST[127:64] <-  Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[63:32])
DEST[MAX_VL-1:128] (unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTPS2PD __m512d _mm512_cvtps_pd( __m256 a);
VCVTPS2PD __m512d _mm512_mask_cvtps_pd( __m512d s, __mmask8 k, __m256 a);
VCVTPS2PD __m512d _mm512_maskz_cvtps_pd( __mmask8 k, __m256 a);
VCVTPS2PD __m512d _mm512_cvt_roundps_pd( __m256 a, int sae);
VCVTPS2PD __m512d _mm512_mask_cvt_roundps_pd( __m512d s, __mmask8 k, __m256 a, int sae);
VCVTPS2PD __m512d _mm512_maskz_cvt_roundps_pd( __mmask8 k, __m256 a, int sae);
VCVTPS2PD __m256d _mm256_mask_cvtps_pd( __m256d s, __mmask8 k, __m128 a);
VCVTPS2PD __m256d _mm256_maskz_cvtps_pd( __mmask8 k, __m128a);
VCVTPS2PD __m128d _mm_mask_cvtps_pd( __m128d s, __mmask8 k, __m128 a);
VCVTPS2PD __m128d _mm_maskz_cvtps_pd( __mmask8 k, __m128 a);
VCVTPS2PD __m256d _mm256_cvtps_pd (__m128 a)
CVTPS2PD __m128d _mm_cvtps_pd (__m128 a)
```
### SIMD Floating-Point Exceptions


Invalid, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3; 

EVEX-encoded instructions, see Exceptions Type E3.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

