----------------------------
title : CVTTPD2DQ (Intel x86/64 assembly instruction)
cat_title : CVTTPD2DQ
ref_title : CVTTPD2DQ
path : /X86-64 명령어 레퍼런스
----------------------------
#@ CVTTPD2DQ

**Convert with Truncation Packed Double-Precision Floating-Point Values to Packed Doubleword Integers**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F E6 /rCVTTPD2DQ xmm1, xmm2/m128|RM|V/V|SSE2|Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1 using truncation.|
|VEX.128.66.0F.WIG E6 /rVCVTTPD2DQ xmm1, xmm2/m128|RM|V/V|AVX|Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1 using truncation.|
|VEX.256.66.0F.WIG E6 /rVCVTTPD2DQ xmm1, ymm2/m256|RM|V/V|AVX|Convert four packed double-precision floating-point values in ymm2/mem to four signed doubleword integers in xmm1 using truncation.|
|EVEX.128.66.0F.W1 E6 /rVCVTTPD2DQ xmm1 {k1}{z}, xmm2/m128/m64bcst|FV|V/V|AVX512VLAVX512F|Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two signed doubleword integers in xmm1 using truncation subject to writemask k1.|
|EVEX.256.66.0F.W1 E6 /rVCVTTPD2DQ xmm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V|AVX512VLAVX512F|Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four signed doubleword integers in xmm1 using truncation subject to writemask k1.|
|EVEX.512.66.0F.W1 E6 /rVCVTTPD2DQ ymm1 {k1}{z}, zmm2/m512/m64bcst{sae}|FV|V/V|AVX512F|Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight signed doubleword integers in ymm1 using truncation subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two, four or eight packed double-precision floating-point values in the source operand (second operand) to two, four or eight packed signed doubleword integers in the destination operand (first operand). 

When a conversion is inexact, a truncated (round toward zero) value is returned. If a converted result is larger than the maximum signed doubleword integer, the floating-point invalid exception is raised, and if this exception is masked, the indefinite integer value (80000000H) is returned.

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand is a YMM/XMM/XMM (low 64 bits) register conditionally updated with writemask k1. The upper bits (MAX_VL-1:256) of the corresponding destination are zeroed.

VEX.256 encoded version: The source operand is a YMM register or 256- bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

VEX.128 encoded version: The source operand is an XMM register or 128- bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:64) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The source operand is an XMM register or 128- bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.539978 255.780029">
<rect x="0.000000" y="10.000000" width="0.480000" height="158.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.479980" height="158.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="168.640015" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.599991,115.600037 L183.659988,115.420044 L183.659988,115.000061 L183.599991,114.820007 L183.479996,114.700012 L183.360001,114.520020 L183.240005,114.400024 L183.059982,114.340027 L182.819992,114.280029 C182.413986 114.273010,182.296982 114.248047,181.979996 114.580017  L181.860001,114.700012 L181.740005,114.880066 L181.679977,115.120056 C181.666977 116.107056,182.636978 116.611023,183.419998 115.960022  L183.539993,115.780029 L183.599991,115.600037" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.759995,115.239990 L184.259995,111.219971 L184.499985,110.619995 L185.039993,111.039978 L197.520004,120.339966 L198.899979,121.359985 L197.159988,121.239990 L181.619980,119.979980 L180.960007,119.859985 L181.199997,119.260010 L181.680008,118.959961 L197.219986,120.219971 L197.159988,121.239990 L196.860001,121.119995 L184.379990,111.820007 L185.039993,111.039978 L185.159988,111.580017 L183.659988,115.599976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M181.199997,119.260010 L182.759995,115.239990 L183.659988,115.600037 L182.099991,119.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.180008,115.419983 L184.680008,111.399963 L197.160019,120.700012 L181.620010,119.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.260010,69.820007 L63.540009,71.679993 L182.340012,116.200012 L183.060013,114.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.039978" y="121.299988" width="37.080002" height="13.560000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="290.039978" y="121.060059" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.880005" y="121.300049" width="0.479980" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.799988" y="134.620056" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.799988" y="121.059998" width="0.480010" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.739990,105.880005 L302.099976,105.640015 C302.772034 105.093994,302.285034 103.843994,301.320007 103.900024  L301.080017,103.960022 L300.900024,104.020020 C300.117981 104.609009,300.325989 105.755981,301.320007 105.940002  L301.559998,105.880005 L301.739990,105.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.380005,104.919983 L305.459961,103.539978 L306.119995,103.419983 L306.179993,104.019958 L306.839966,119.619995 L306.899963,121.359985 L305.880005,119.919983 L297.059998,107.019958 L296.700012,106.479980 L297.299988,106.239990 L297.899963,106.479980 L306.719971,119.380005 L305.880005,119.919983 L305.820007,119.679993 L305.159973,104.079956 L306.179993,104.019958 L305.820007,104.559998 L301.739990,105.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.299988,106.239990 L301.380005,104.919983 L301.739990,105.940002 L297.659973,107.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.559998,105.400024 L305.640015,104.020020 L306.299988,119.619995 L297.480042,106.720032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.000000,70.419983 L289.140015,71.019958 L300.540039,105.219971 L302.400024,104.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,109.419983 L258.899963,109.059998 C259.216980 108.130981,258.352966 107.355957,257.459961 107.799988  L257.279968,107.919983 L257.159973,108.099976 C256.601990 108.818970,257.339966 109.967957,258.299988 109.599976  L258.479980,109.539978 L258.659973,109.419983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.000000,108.700012 L261.119995,105.760010 L261.600037,105.340027 L261.900024,105.940002 L268.980042,119.799988 L269.760010,121.359985 L268.260010,120.460022 L254.940018,112.480042 L254.400009,112.119995 L254.880020,111.640015 L255.420029,111.580017 L268.739990,119.559998 L268.260010,120.460022 L268.080017,120.220032 L261.000000,106.359985 L261.900024,105.940002 L261.780029,106.540039 L258.660034,109.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M254.879990,111.640015 L258.000000,108.700012 L258.659973,109.480042 L255.539993,112.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.299988,109.059998 L261.419983,106.119995 L268.500000,119.979980 L255.180008,112.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.259995,70.059998 L221.819992,71.440002 L257.219971,109.419983 L258.659973,108.039978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.759995,113.440002 L221.819992,113.200012 L221.879990,113.020020 C222.029007 112.046997,220.625992 111.543030,220.139999 112.299988  L220.020004,112.419983 L219.960007,112.599976 L219.900009,112.840027 L219.900009,113.200012 L220.020004,113.380005 L220.080002,113.559998 L220.259995,113.679993 L220.379990,113.799988 C220.912003 113.971985,220.850998 113.971008,221.339981 113.799988  L221.520004,113.739990 L221.639999,113.559998 L221.759995,113.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.919998,112.960022 L223.319992,108.640015 L223.860001,109.059998 L234.779984,120.100037 L236.039993,121.360046 L234.360001,120.940002 L219.180008,117.400024 L218.520004,117.280029 L218.819992,116.679993 L219.360001,116.440002 L234.539993,119.980042 L234.360001,120.940002 L234.060013,120.820007 L223.080002,109.780029 L223.860001,109.059998 L223.919998,109.660034 L221.819992,113.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M218.819992,116.679993 L220.919998,112.960022 L221.819992,113.440002 L219.719986,117.159973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.340012,113.200012 L223.440018,109.419983 L234.419998,120.460022 L219.240005,116.919983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M145.380005,69.880005 L144.419998,71.619995 L220.380020,113.799988 L221.340012,112.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.900009" y="121.299988" width="37.139999" height="13.560000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.900009" y="121.060059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.799988" y="121.300049" width="0.480010" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="134.620056" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="121.059998" width="0.479980" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.759995" y="121.299988" width="37.139999" height="13.560000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="215.759995" y="121.060059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="121.300049" width="0.479980" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520004" y="134.620056" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520004" y="121.059998" width="0.480010" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.620010" y="121.299988" width="37.139999" height="13.560000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.620010" y="121.060059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520004" y="121.300049" width="0.480010" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="134.620056" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="121.059998" width="0.480010" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.900009" y="57.220032" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.900009" y="56.980042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.880005" y="57.220032" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="70.480042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="56.980042" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="30.120010" y="57.220032" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="30.120010" y="56.980042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.160004" y="57.220032" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.880005" y="70.480042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.880005" y="56.980042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.400009" y="57.220032" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="104.400009" y="56.980042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="57.220032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.160004" y="70.480042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.160004" y="56.980042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.620010" y="57.220032" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.620010" y="56.980042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="57.220032" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="70.480042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="56.980042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.220001" y="121.299988" width="145.500000" height="13.560000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="32.220001" y="121.060059" width="145.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.479996" y="121.300049" width="0.480010" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.979996" y="134.620056" width="145.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.979996" y="121.059998" width="0.480000" height="13.800000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="292.078308" y="65.739990" textLength="4.610074" font-size="8px">0</text>
<text x="286.618347" y="65.739990" textLength="5.530430" font-size="8px">X</text>
<text x="217.979660" y="65.739990" textLength="4.610074" font-size="8px">1</text>
<text x="212.460007" y="65.739990" textLength="5.530430" font-size="8px">X</text>
<text x="58.740005" y="65.739990" textLength="4.170000" font-size="8px">3</text>
<text x="189.720016" y="129.880005" textLength="5.002500" font-size="8px">X</text>
<text x="231.900009" y="129.880005" textLength="4.170000" font-size="8px">2</text>
<text x="226.860001" y="129.880005" textLength="5.002500" font-size="8px">X</text>
<text x="268.980042" y="129.880005" textLength="4.170000" font-size="8px">1</text>
<text x="264.000000" y="129.880005" textLength="5.002500" font-size="8px">X</text>
<text x="306.059998" y="129.880005" textLength="4.170000" font-size="8px">0</text>
<text x="301.080017" y="129.880005" textLength="5.002500" font-size="8px">X</text>
<text x="20.338501" y="65.739990" textLength="5.415000" font-size="8px">C</text>
<text x="9.900002" y="65.739990" textLength="5.002500" font-size="8px">S</text>
<text x="25.318497" y="129.880005" textLength="4.582500" font-size="8px">T</text>
<text x="9.900002" y="129.880005" textLength="5.415000" font-size="8px">D</text>
<text x="138.120010" y="65.739990" textLength="5.002500" font-size="8px">X</text>
<text x="194.700027" y="129.880005" textLength="4.170000" font-size="8px">3</text>
<text x="53.760010" y="65.739990" textLength="5.002500" font-size="8px">X</text>
<text x="15.295502" y="129.880005" textLength="5.002500" font-size="8px">E</text>
<text x="14.940002" y="65.739990" textLength="5.415000" font-size="8px">R</text>
<text x="20.335503" y="129.880005" textLength="5.002500" font-size="8px">S</text>
<text x="101.699997" y="129.880005" textLength="4.170000" font-size="8px">0</text>
<text x="143.100006" y="65.739990" textLength="4.170000" font-size="8px">2</text>
</svg>
<figcaption>Figure 3-15.  VCVTTPD2DQ (VEX.256 encoded version)
</figcaption></figure>
```

### Operation
#### VCVTTPD2DQ (EVEX encoded versions) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
 i <-  j * 32
 k <-  j * 64
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i]  <-
    Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[k+63:k])
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE  ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL/2]  <- 0
```
#### VCVTTPD2DQ (EVEX encoded versions) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j  <- 0 TO KL-1
 i <-  j * 32
 k <-  j * 64
 IF k1[j] OR *no writemask*
   THEN 
    IF (EVEX.b = 1) 
      THEN
        DEST[i+31:i] <- 
    Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[63:0])
      ELSE 
        DEST[i+31:i] <- 
    Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[k+63:k])
    FI;
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE  ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```
#### VCVTTPD2DQ (VEX.256 encoded version)
```info-verb
DEST[31:0]  <-Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[63:0])
DEST[63:32]  <-Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[127:64])
DEST[95:64]  <-Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[191:128])
DEST[127:96] <- Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[255:192)
DEST[MAX_VL-1:128] <-0
```
#### VCVTTPD2DQ (VEX.128 encoded version)
```info-verb
DEST[31:0] <- Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[63:0])
DEST[63:32]  <-Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[127:64])
DEST[MAX_VL-1:64] <-0
```
#### CVTTPD2DQ (128-bit Legacy SSE version)
```info-verb
DEST[31:0]  <-Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[63:0])
DEST[63:32]  <-Convert_Double_Precision_Floating_Point_To_Integer_Truncate(SRC[127:64])
DEST[127:64] <- 0
DEST[MAX_VL-1:128] (unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTTPD2DQ __m256i _mm512_cvttpd_epi32( __m512d a);
VCVTTPD2DQ __m256i _mm512_mask_cvttpd_epi32( __m256i s, __mmask8 k, __m512d a);
VCVTTPD2DQ __m256i _mm512_maskz_cvttpd_epi32( __mmask8 k, __m512d a);
VCVTTPD2DQ __m256i _mm512_cvtt_roundpd_epi32( __m512d a, int sae);
VCVTTPD2DQ __m256i _mm512_mask_cvtt_roundpd_epi32( __m256i s, __mmask8 k, __m512d a, int sae);
VCVTTPD2DQ __m256i _mm512_maskz_cvtt_roundpd_epi32( __mmask8 k, __m512d a, int sae);
VCVTTPD2DQ __m128i _mm256_mask_cvttpd_epi32( __m128i s, __mmask8 k, __m256d a);
VCVTTPD2DQ __m128i _mm256_maskz_cvttpd_epi32( __mmask8 k, __m256d a);
VCVTTPD2DQ __m128i _mm_mask_cvttpd_epi32( __m128i s, __mmask8 k, __m128d a);
VCVTTPD2DQ __m128i _mm_maskz_cvttpd_epi32( __mmask8 k, __m128d a);
VCVTTPD2DQ __m128i _mm256_cvttpd_epi32 (__m256d src);
CVTTPD2DQ __m128i _mm_cvttpd_epi32 (__m128d src);
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2; 

EVEX-encoded instructions, see Exceptions Type E2.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

