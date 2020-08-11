----------------------------
title : CVTPD2PS instruction(Intel x86/64 assembly instruction)
cat_title : CVTPD2PS
----------------------------
### CVTPD2PS--Convert Packed Double-Precision Floating-Point Values to Packed Single-Precision Floating-Point Values


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 5A /rCVTPD2PS xmm1, xmm2/m128|RM|V/V|SSE2|Convert two packed double-precision floating-point values in xmm2/mem to two single-precision floating-point values in xmm1.|
|VEX.128.66.0F.WIG 5A /rVCVTPD2PS xmm1, xmm2/m128|RM|V/V|AVX|Convert two packed double-precision floating-point values in xmm2/mem to two single-precision floating-point values in xmm1.|
| VEX.256.66.0F.WIG 5A /rVCVTPD2PS xmm1, ymm2/m256|RM|V/V|AVX|Convert four packed double-precision floating-point values in ymm2/mem to four single-precision floating-point values in xmm1.|
|EVEX.128.66.0F.W1 5A /rVCVTPD2PS xmm1 {k1}{z}, xmm2/m128/m64bcst|FV|V/V|AVX512VLAVX512F|Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two single-precision floating-point values in xmm1with writemask k1.|
|EVEX.256.66.0F.W1 5A /rVCVTPD2PS xmm1 {k1}{z}, ymm2/m256/m64bcst |FV|V/V|AVX512VLAVX512F|Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four single-precision floating-point values in xmm1with writemask k1.|
|EVEX.512.66.0F.W1 5A /rVCVTPD2PS ymm1 {k1}{z}, zmm2/m512/m64bcst{er}|FV|V/V|AVX512F|Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight single-precision floating-point values in ymm1with writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two, four or eight packed double-precision floating-point values in the source operand (second operand) to two, four or eight packed single-precision floating-point values in the destination operand (first operand). 

When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register or the embedded rounding control bits. 

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand is a YMM/XMM/XMM (low 64-bits) register conditionally updated with writemask k1. The upper bits (MAX_VL-1:256/128/64) of the corresponding destination are zeroed.

VEX.256 encoded version: The source operand is a YMM register or 256- bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

VEX.128 encoded version: The source operand is an XMM register or 128- bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:64) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The source operand is an XMM register or 128- bit memory location. The destination operand is an XMM register. Bits[127:64] of the destination XMM register are zeroed. However, the upper Bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified.

VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.480042 222.059998">
<rect x="0.000000" y="10.000000" width="0.480000" height="124.860001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="124.860001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="134.919983" width="396.480011" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.600006,96.100037 L183.660004,95.920044 L183.660004,95.740051 C183.695007 94.773010,182.399994 94.429016,181.800018 95.200012  L181.740021,95.380066 L181.679993,95.620056 C181.567993 96.507019,182.559021 97.130066,183.420013 96.460022  L183.540009,96.280029 L183.600006,96.100037" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.700012,95.739990 L184.200012,91.719971 L184.440002,91.119995 L184.980011,91.539978 L197.520020,100.839966 L198.900024,101.859985 L197.160004,101.739990 L181.620026,100.479980 L180.960022,100.359985 L181.200012,99.760010 L181.680023,99.459961 L197.220001,100.719971 L197.160004,101.739990 L196.860016,101.619995 L184.320007,92.320007 L184.980011,91.539978 L185.100006,92.080017 L183.600006,96.099976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M181.200012,99.760010 L182.700012,95.739990 L183.600006,96.100037 L182.100006,100.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.119995,95.919983 L184.619995,91.899963 L197.160004,101.200012 L181.619995,99.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.200005,50.320007 L63.480003,52.179993 L182.280029,96.700012 L183.000000,94.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.980011" y="101.799988" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="289.980011" y="101.560059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.880005" y="101.800049" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.740021" y="115.060059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.740021" y="101.559998" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.740021,86.380005 L301.920013,86.260010 L302.040009,86.140015 C302.815033 85.567017,302.215027 84.268005,301.260010 84.400024  L300.900024,84.520020 L300.720032,84.640015 L300.600006,84.820007 L300.480011,84.940002 L300.420013,85.119995 L300.420013,85.539978 L300.480011,85.720032 C300.527008 86.013000,300.847015 86.333008,301.140015 86.380005  L301.320007,86.440002 L301.500031,86.380005 L301.740021,86.380005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.380005,85.419983 L305.459991,84.039978 L306.119995,83.919983 L306.179993,84.519958 L306.839996,100.119995 L306.899994,101.859985 L305.880005,100.419983 L297.059998,87.519958 L296.700012,86.979980 L297.300018,86.739990 L297.899994,86.979980 L306.720001,99.880005 L305.880005,100.419983 L305.820007,100.179993 L305.160004,84.579956 L306.179993,84.519958 L305.820007,85.059998 L301.739990,86.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.300018,86.739990 L301.380005,85.419983 L301.740021,86.440002 L297.660004,87.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.559998,85.900024 L305.639984,84.520020 L306.299988,100.119995 L297.480011,87.220032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M290.940002,50.919983 L289.080017,51.519958 L300.480011,85.719971 L302.339996,85.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.600006,89.919983 L258.779999,89.739990 L258.839996,89.559998 L258.899994,89.380005 L258.959991,89.200012 L258.899994,89.019958 L258.899994,88.839966 L258.660004,88.479980 L258.540009,88.359985 L258.360016,88.239990 L258.179993,88.179993 L257.760010,88.179993 L257.399994,88.299988 L257.100006,88.599976 L256.980011,88.959961 L256.920013,89.139954 L256.980011,89.320007 L256.980011,89.500000 L257.220001,89.859985 C257.567993 90.223999,257.679993 90.156006,258.119995 90.159973  L258.480011,90.039978 L258.600006,89.919983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.000000,89.200012 L261.119995,86.260010 L261.600006,85.840027 L261.899994,86.440002 L268.980011,100.299988 L269.760010,101.859985 L268.260010,100.960022 L254.880005,92.980042 L254.339996,92.619995 L254.820007,92.140015 L255.420013,92.080017 L268.739990,100.059998 L268.260010,100.960022 L268.079987,100.720032 L261.000000,86.859985 L261.899994,86.440002 L261.779999,87.040039 L258.660004,89.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M254.820007,92.140015 L258.000000,89.200012 L258.660004,89.980042 L255.480011,92.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.300018,89.559998 L261.420013,86.619995 L268.500031,100.479980 L255.120026,92.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.200012,50.559998 L221.760010,51.940002 L257.220001,89.919983 L258.660004,88.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.760010,93.940002 L221.820007,93.700012 L221.880005,93.520020 C221.950012 92.588989,220.682007 92.017029,220.140015 92.799988  L220.020020,92.919983 L219.900024,93.099976 C219.714020 94.190979,220.613007 94.710999,221.460022 94.239990  L221.760010,93.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.860016,93.400024 L222.960022,89.680054 L223.320007,89.140015 L223.800018,89.559998 L234.780029,100.600037 L236.040009,101.860046 L234.360016,101.440002 L219.180023,97.900024 L218.520020,97.780029 L218.820007,97.180054 L219.360016,96.940002 L234.540009,100.480042 L234.360016,101.440002 L234.060028,101.320007 L223.020020,90.280029 L223.800018,89.559998 L223.860016,90.160034 L221.760010,93.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M218.820007,97.179993 L220.860016,93.399963 L221.760010,93.880005 L219.720001,97.659973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.279999,93.640015 L223.380005,89.920044 L234.420013,100.960022 L219.239990,97.420044" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M145.320007,50.380005 L144.359985,52.119995 L220.380005,94.299988 L221.339996,92.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.900024" y="101.799988" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.900024" y="101.560059" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.740021" y="101.800049" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.660004" y="115.060059" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.660004" y="101.559998" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.760010" y="101.799988" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="215.760010" y="101.560059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.660004" y="101.800049" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520020" y="115.060059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520020" y="101.559998" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.619995" y="101.799988" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.619995" y="101.560059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520020" y="101.800049" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.380005" y="115.060059" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.380005" y="101.559998" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.900024" y="37.720032" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.900024" y="37.480042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.880005" y="37.720032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.660004" y="50.980042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.660004" y="37.480042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="30.120003" y="37.720032" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="30.120003" y="37.480042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.099998" y="37.720032" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.879997" y="50.980042" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.879997" y="37.480042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.340004" y="37.720032" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="104.340004" y="37.480042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.380005" y="37.720032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.099998" y="50.980042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.099998" y="37.480042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.619995" y="37.720032" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.619995" y="37.480042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.660004" y="37.720032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.380005" y="50.980042" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.380005" y="37.480042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.159996" y="101.799988" width="145.559998" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="32.159996" y="101.560059" width="145.800003" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.480011" y="101.800049" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.920006" y="115.060059" width="145.800003" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.920006" y="101.559998" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="292.078339" y="46.239990" textLength="4.610074" font-size="8px">0</text>
<text x="286.618378" y="46.239990" textLength="5.530430" font-size="8px">X</text>
<text x="143.100006" y="46.239990" textLength="4.170000" font-size="8px">2</text>
<text x="53.760002" y="46.239990" textLength="5.002500" font-size="8px">X</text>
<text x="194.700012" y="110.380005" textLength="4.170000" font-size="8px">3</text>
<text x="301.080017" y="110.380005" textLength="5.002500" font-size="8px">X</text>
<text x="14.880005" y="46.239990" textLength="5.415000" font-size="8px">R</text>
<text x="9.840004" y="46.239990" textLength="5.002500" font-size="8px">S</text>
<text x="25.258507" y="110.380005" textLength="4.582500" font-size="8px">T</text>
<text x="15.235504" y="110.380005" textLength="5.002500" font-size="8px">E</text>
<text x="9.840004" y="110.380005" textLength="5.415000" font-size="8px">D</text>
<text x="231.840027" y="110.380005" textLength="4.170000" font-size="8px">2</text>
<text x="226.800018" y="110.380005" textLength="5.002500" font-size="8px">X</text>
<text x="217.979675" y="46.239990" textLength="4.610074" font-size="8px">1</text>
<text x="58.739998" y="46.239990" textLength="4.170000" font-size="8px">3</text>
<text x="306.060028" y="110.380005" textLength="4.170000" font-size="8px">0</text>
<text x="263.940002" y="110.380005" textLength="5.002500" font-size="8px">X</text>
<text x="189.720001" y="110.380005" textLength="5.002500" font-size="8px">X</text>
<text x="268.920013" y="110.380005" textLength="4.170000" font-size="8px">1</text>
<text x="138.119995" y="46.239990" textLength="5.002500" font-size="8px">X</text>
<text x="20.275505" y="110.380005" textLength="5.002500" font-size="8px">S</text>
<text x="101.700005" y="110.380005" textLength="4.170000" font-size="8px">0</text>
<text x="20.278503" y="46.239990" textLength="5.415000" font-size="8px">C</text>
<text x="212.460022" y="46.239990" textLength="5.530430" font-size="8px">X</text>
</svg>
<figcaption>Figure 3-13.  VCVTPD2PS (VEX.256 encoded version)
</figcaption></figure>
```

### Operation
#### VCVTPD2PS (EVEX encoded version) when src operand is a register
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
IF (VL = 512) AND (EVEX.b = 1) 
 THEN
   SET_RM(EVEX.RC);
 ELSE 
   SET_RM(MXCSR.RM);
FI;
FOR j  <- 0 TO KL-1
 i  <- j \htmlonly{*} 32
 k  <- j \htmlonly{*} 64
 IF k1[j] OR \htmlonly{*}no writemask\htmlonly{*}
   THEN 
    DEST[i+31:i] <-  Convert_Double_Precision_Floating_Point_To_Single_Precision_Floating_Point(SRC[k+63:k])
   ELSE 
    IF \htmlonly{*}merging-masking\htmlonly{*} ; merging-masking
      THEN \htmlonly{*}DEST[i+31:i] remains unchanged\htmlonly{*}
      ELSE  ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL/2]  <- 0
```
#### VCVTPD2PS (EVEX encoded version) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
 i <-  j * 32
 k  <- j * 64
 IF k1[j] OR *no writemask*
   THEN 
    IF (EVEX.b = 1) 
      THEN
        DEST[i+31:i]  <-Convert_Double_Precision_Floating_Point_To_Single_Precision_Floating_Point(SRC[63:0])
      ELSE 
        DEST[i+31:i]  <- Convert_Double_Precision_Floating_Point_To_Single_Precision_Floating_Point(SRC[k+63:k])
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
#### VCVTPD2PS (VEX.256 encoded version)
```info-verb
DEST[31:0]  <- Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[63:0])
DEST[63:32] <-  Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[127:64])
DEST[95:64]  <- Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[191:128])
DEST[127:96]  <- Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[255:192)
DEST[MAX_VL-1:128] <-  0
```
#### VCVTPD2PS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[63:0])
DEST[63:32]  <- Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[127:64])
DEST[MAX_VL-1:64]  <- 0
```
#### CVTPD2PS (128-bit Legacy SSE version)
```info-verb
DEST[31:0]  <- Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[63:0])
DEST[63:32] <-  Convert_Double_Precision_To_Single_Precision_Floating_Point(SRC[127:64])
DEST[127:64]  <- 0
DEST[MAX_VL-1:128] (unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTPD2PS __m256 _mm512_cvtpd_ps( __m512d a);
VCVTPD2PS __m256 _mm512_mask_cvtpd_ps( __m256 s, __mmask8 k, __m512d a);
VCVTPD2PS __m256 _mm512_maskz_cvtpd_ps( __mmask8 k, __m512d a);
VCVTPD2PS __m256 _mm512_cvt_roundpd_ps( __m512d a, int r);
VCVTPD2PS __m256 _mm512_mask_cvt_roundpd_ps( __m256 s, __mmask8 k, __m512d a, int r);
VCVTPD2PS __m256 _mm512_maskz_cvt_roundpd_ps( __mmask8 k, __m512d a, int r);
VCVTPD2PS __m128 _mm256_mask_cvtpd_ps( __m128 s, __mmask8 k, __m256d a);
VCVTPD2PS __m128 _mm256_maskz_cvtpd_ps( __mmask8 k, __m256d a);
VCVTPD2PS __m128 _mm_mask_cvtpd_ps( __m128 s, __mmask8 k, __m128d a);
VCVTPD2PS __m128 _mm_maskz_cvtpd_ps( __mmask8 k, __m128d a);
VCVTPD2PS __m128 _mm256_cvtpd_ps (__m256d a)
CVTPD2PS __m128 _mm_cvtpd_ps (__m128d a)
```
### SIMD Floating-Point Exceptions


Invalid, Precision, Underflow, Overflow, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2; 

EVEX-encoded instructions, see Exceptions Type E2.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

