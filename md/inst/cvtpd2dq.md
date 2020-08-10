### CVTPD2DQ--Convert Packed Double-Precision Floating-Point Values to Packed Doubleword Integers


|**Opcode**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|-----------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F E6 /rCVTPD2DQ xmm1, xmm2/m128|RM|V/V|SSE2|Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1.|
|VEX.128.F2.0F.WIG E6 /rVCVTPD2DQ xmm1, xmm2/m128|RM|V/V|AVX|Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1.|
|VEX.256.F2.0F.WIG E6 /rVCVTPD2DQ xmm1, ymm2/m256|RM|V/V|AVX|Convert four packed double-precision floating-point values in ymm2/mem to four signed doubleword integers in xmm1.|
|EVEX.128.F2.0F.W1 E6 /rVCVTPD2DQ xmm1 {k1}{z}, xmm2/m128/m64bcst|FV|V/V|AVX512VLAVX512F|Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two signed doubleword integers in xmm1 subject to writemask k1.|
|EVEX.256.F2.0F.W1 E6 /rVCVTPD2DQ xmm1 {k1}{z}, ymm2/m256/m64bcst|FV|V/V|AVX512VLAVX512F|Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four signed doubleword integers in xmm1 subject to writemask k1.|
|EVEX.512.F2.0F.W1 E6 /rVCVTPD2DQ ymm1 {k1}{z}, zmm2/m512/m64bcst{er}|FV|V/V|AVX512F|Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight signed doubleword integers in ymm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts packed double-precision floating-point values in the source operand (second operand) to packed signed doubleword integers in the destination operand (first operand). 

When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register or the embedded rounding control bits. If a converted result cannot be represented in the destination format, the floating-point invalid exception is raised, and if this exception is masked, the indefinite integer value (2\footnote{w-1} , where w represents the number of bits in the destination format) is returned.

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register, a 512-bit memory location, or a 512-bit vector broadcasted from a 64-bit memory location. The destination operand is a ZMM/YMM/XMM register condi-tionally updated with writemask k1. The upper bits (MAX_VL-1:256/128/64) of the corresponding destination are zeroed.

VEX.256 encoded version: The source operand is a YMM register or 256- bit memory location. The destination operand is an XMM register. The upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are zeroed.

VEX.128 encoded version: The source operand is an XMM register or 128- bit memory location. The destination operand is a XMM register. The upper bits (MAX_VL-1:64) of the corresponding ZMM register destination are zeroed.

128-bit Legacy SSE version: The source operand is an XMM register or 128- bit memory location. The destination operand is an XMM register. Bits[127:64] of the destination XMM register are zeroed. However, the upper bits (MAX_VL-1:128) of the corresponding ZMM register destination are unmodified. 

VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.539978 222.059998">
<rect x="0.000000" y="10.000000" width="0.480000" height="124.919998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.479980" height="124.919998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="134.919983" width="396.540009" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.599991,98.440002 L183.659988,98.260010 L183.659988,98.020020 C183.668991 97.054993,182.330978 96.707031,181.860001 97.539978  L181.740005,97.720032 L181.679977,97.900024 C181.569992 98.887024,182.740982 99.512024,183.419998 98.739990  L183.539993,98.619995 L183.599991,98.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.759995,98.080017 L184.259995,94.059998 L184.499985,93.460022 L185.039993,93.880005 L197.520004,103.179993 L198.899979,104.200012 L197.159988,104.080017 L181.619980,102.820007 L180.960007,102.700012 L181.199997,102.100037 L181.680008,101.799988 L197.219986,103.059998 L197.159988,104.080017 L196.860001,103.960022 L184.379990,94.660034 L185.039993,93.880005 L185.159988,94.420044 L183.659988,98.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M181.199997,102.100037 L182.759995,98.080017 L183.659988,98.440063 L182.099991,102.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M183.180008,98.260010 L184.680008,94.239990 L197.160019,103.540039 L181.620010,102.280029" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.260010,52.600037 L63.540009,54.460022 L182.340012,99.040039 L183.060013,97.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.039978" y="104.140015" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="290.039978" y="103.900024" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.880005" y="104.140015" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.799988" y="117.400024" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.799988" y="103.900024" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.739990,88.660034 L301.919983,88.600037 L302.099976,88.480042 L302.220032,88.360046 L302.340027,88.180054 L302.400024,88.000061 L302.400024,87.640015 L302.340027,87.400024 L302.280029,87.220032 C301.843994 86.710022,302.164001 86.992004,301.500000 86.740051  L301.320007,86.740051 L301.080017,86.800049 L300.900024,86.860046 L300.780029,86.980042 L300.599976,87.100037 L300.479980,87.460022 L300.419983,87.640015 L300.419983,87.880005 L300.479980,88.060059 C300.689026 88.691040,300.835022 88.458008,301.140015 88.720032  L301.559998,88.720032 L301.739990,88.660034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.380005,87.700012 L305.459961,86.380005 L306.119995,86.260010 L306.179993,86.859985 L306.839966,102.400024 L306.899963,104.140015 L305.880005,102.700012 L297.059998,89.859985 L296.700012,89.320007 L297.299988,89.080017 L297.899963,89.320007 L306.719971,102.160034 L305.880005,102.700012 L305.820007,102.460022 L305.159973,86.919983 L306.179993,86.859985 L305.820007,87.400024 L301.739990,88.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.299988,89.080017 L301.380005,87.700012 L301.739990,88.720032 L297.659973,90.100037" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.559998,88.179993 L305.640015,86.859985 L306.299988,102.399963 L297.480042,89.559998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M291.000000,53.200012 L289.140015,53.799988 L300.540039,88.059998 L302.400024,87.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.659973,92.260010 L258.779968,92.080017 L258.899963,91.900024 C259.216980 90.971008,258.352966 90.195984,257.459961 90.640015  L257.279968,90.760010 L257.159973,90.940002 C256.601990 91.658997,257.339966 92.807983,258.299988 92.440002  L258.479980,92.380005 L258.659973,92.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.000000,91.479980 L261.119995,88.599976 L261.600037,88.179993 L261.900024,88.779968 L268.980042,102.639954 L269.760010,104.199951 L268.260010,103.299988 L254.940018,95.260010 L254.400009,94.899963 L254.880020,94.419983 L255.420029,94.359985 L268.739990,102.399963 L268.260010,103.299988 L268.080017,103.059998 L261.000000,89.199951 L261.900024,88.779968 L261.780029,89.380005 L258.660034,92.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M254.879990,94.419983 L258.000000,91.479980 L258.659973,92.260010 L255.539993,95.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.299988,91.840027 L261.419983,88.960022 L268.500000,102.820007 L255.180008,94.780029" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.259995,52.840027 L221.819992,54.220032 L257.219971,92.200012 L258.659973,90.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.759995,96.220032 L221.879990,95.860046 C221.990005 94.821045,220.715988 94.421021,220.139999 95.080017  L220.020004,95.260010 L219.960007,95.440002 C219.589005 96.359009,220.759995 97.182007,221.520004 96.520020  L221.639999,96.400024 L221.759995,96.220032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.919998,95.739990 L223.020004,92.020020 L223.379990,91.479980 L223.860001,91.899963 L234.779984,102.940002 L236.039993,104.200012 L234.360001,103.779968 L219.180008,100.239990 L218.520004,100.119995 L218.819992,99.520020 L219.360001,99.279968 L234.539993,102.820007 L234.360001,103.779968 L234.060013,103.659973 L223.080002,92.619995 L223.860001,91.899963 L223.919998,92.500000 L221.819992,96.219971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M218.819992,99.520020 L220.919998,95.739990 L221.819992,96.220032 L219.719986,100.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.340012,95.979980 L223.440018,92.260010 L234.419998,103.299988 L219.240005,99.760010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M145.380005,52.660034 L144.419998,54.400024 L220.380020,96.640015 L221.340012,94.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.900009" y="104.140015" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.900009" y="103.900024" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.799988" y="104.140015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="117.400024" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="103.900024" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.759995" y="104.140015" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="215.759995" y="103.900024" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="104.140015" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520004" y="117.400024" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520004" y="103.900024" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.620010" y="104.140015" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.620010" y="103.900024" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="215.520004" y="104.140015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="117.400024" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="103.900024" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.900009" y="40.000000" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="252.900009" y="39.760010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.880005" y="40.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="53.260010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="39.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="30.120010" y="40.000000" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="30.120010" y="39.760010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.160004" y="40.000000" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.880005" y="53.260010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="29.880005" y="39.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.400009" y="40.000000" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="104.400009" y="39.760010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="40.000000" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.160004" y="53.260010" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.160004" y="39.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.620010" y="40.000000" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="178.620010" y="39.760010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.659988" y="40.000000" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="53.260010" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.379990" y="39.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.220001" y="104.140015" width="145.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="32.220001" y="103.900024" width="145.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.479996" y="104.140015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.979996" y="117.400024" width="145.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.979996" y="103.900024" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="101.699997" y="112.660034" textLength="4.170000" font-size="8px">0</text>
<text x="212.460007" y="48.580017" textLength="5.530430" font-size="8px">X</text>
<text x="143.100006" y="48.580017" textLength="4.170000" font-size="8px">2</text>
<text x="138.120010" y="48.580017" textLength="5.002500" font-size="8px">X</text>
<text x="58.740005" y="48.580017" textLength="4.170000" font-size="8px">3</text>
<text x="194.700027" y="112.660034" textLength="4.170000" font-size="8px">3</text>
<text x="231.900009" y="112.660034" textLength="4.170000" font-size="8px">2</text>
<text x="226.860001" y="112.660034" textLength="5.002500" font-size="8px">X</text>
<text x="268.980042" y="112.660034" textLength="4.170000" font-size="8px">1</text>
<text x="264.000000" y="112.660034" textLength="5.002500" font-size="8px">X</text>
<text x="301.080017" y="112.660034" textLength="5.002500" font-size="8px">X</text>
<text x="20.338501" y="48.580017" textLength="5.415000" font-size="8px">C</text>
<text x="20.335503" y="112.660034" textLength="5.002500" font-size="8px">S</text>
<text x="15.295502" y="112.660034" textLength="5.002500" font-size="8px">E</text>
<text x="9.900002" y="112.660034" textLength="5.415000" font-size="8px">D</text>
<text x="286.618347" y="48.580017" textLength="5.530430" font-size="8px">X</text>
<text x="217.979660" y="48.580017" textLength="4.610074" font-size="8px">1</text>
<text x="292.078308" y="48.580017" textLength="4.610074" font-size="8px">0</text>
<text x="306.059998" y="112.660034" textLength="4.170000" font-size="8px">0</text>
<text x="25.318497" y="112.660034" textLength="4.582500" font-size="8px">T</text>
<text x="14.940002" y="48.580017" textLength="5.415000" font-size="8px">R</text>
<text x="9.900002" y="48.580017" textLength="5.002500" font-size="8px">S</text>
<text x="189.720016" y="112.660034" textLength="5.002500" font-size="8px">X</text>
<text x="53.760010" y="48.580017" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 3-12.  VCVTPD2DQ (VEX.256 encoded version)
</figcaption></figure>
```

### Operation
#### VCVTPD2DQ (EVEX encoded versions) when src operand is a register
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
   THEN DEST[i+31:i]  <-
    Convert_Double_Precision_Floating_Point_To_Integer(SRC[k+63:k])
   ELSE 
    IF \htmlonly{*}merging-masking\htmlonly{*} ; merging-masking
      THEN \htmlonly{*}DEST[i+31:i] remains unchanged\htmlonly{*}
      ELSE  ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```
#### VCVTPD2DQ (EVEX encoded versions) when src operand is a memory source
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
 i <-  j * 32
 k  <- j * 64
 IF k1[j] OR *no writemask*
   THEN 
    IF (EVEX.b = 1) 
      THEN
        DEST[i+31:i]  <-
    Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0])
      ELSE 
        DEST[i+31:i]  <-
    Convert_Double_Precision_Floating_Point_To_Integer(SRC[k+63:k])
    FI;
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE  ; zeroing-masking
        DEST[i+31:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL/2] <-  0
```
#### VCVTPD2DQ (VEX.256 encoded version)
```info-verb
DEST[31:0]  <-Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0])
DEST[63:32] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[127:64])
DEST[95:64] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[191:128])
DEST[127:96] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[255:192)
DEST[MAX_VL-1:128]<- 0
```
#### VCVTPD2DQ (VEX.128 encoded version)
```info-verb
DEST[31:0] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0])
DEST[63:32]  <-Convert_Double_Precision_Floating_Point_To_Integer(SRC[127:64])
DEST[MAX_VL-1:64] <-0
```
#### CVTPD2DQ (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0])
DEST[63:32]  <-Convert_Double_Precision_Floating_Point_To_Integer(SRC[127:64])
DEST[127:64] <- 0
DEST[MAX_VL-1:128] (unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTPD2DQ __m256i _mm512_cvtpd_epi32( __m512d a);
VCVTPD2DQ __m256i _mm512_mask_cvtpd_epi32( __m256i s, __mmask8 k, __m512d a);
VCVTPD2DQ __m256i _mm512_maskz_cvtpd_epi32( __mmask8 k, __m512d a);
VCVTPD2DQ __m256i _mm512_cvt_roundpd_epi32( __m512d a, int r);
VCVTPD2DQ __m256i _mm512_mask_cvt_roundpd_epi32( __m256i s, __mmask8 k, __m512d a, int r);
VCVTPD2DQ __m256i _mm512_maskz_cvt_roundpd_epi32( __mmask8 k, __m512d a, int r);
VCVTPD2DQ __m128i _mm256_mask_cvtpd_epi32( __m128i s, __mmask8 k, __m256d a);
VCVTPD2DQ __m128i _mm256_maskz_cvtpd_epi32( __mmask8 k, __m256d a);
VCVTPD2DQ __m128i _mm_mask_cvtpd_epi32( __m128i s, __mmask8 k, __m128d a);
VCVTPD2DQ __m128i _mm_maskz_cvtpd_epi32( __mmask8 k, __m128d a);
VCVTPD2DQ __m128i _mm256_cvtpd_epi32 (__m256d src)
CVTPD2DQ __m128i _mm_cvtpd_epi32 (__m128d src)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


See Exceptions Type 2; additionally

EVEX-encoded instructions, see Exceptions Type E2.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

