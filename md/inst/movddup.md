----------------------------
title : MOVDDUP instruction(Intel x86/64 assembly instruction)
cat_title : MOVDDUP
----------------------------
### MOVDDUP--Replicate Double FP Values


|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F 12 /rMOVDDUP xmm1, xmm2/m64|RM|V/V|SSE3|Move double-precision floating-point value from xmm2/m64 and duplicate into xmm1.|
|VEX.128.F2.0F.WIG 12 /rVMOVDDUP xmm1, xmm2/m64|RM|V/V|AVX|Move double-precision floating-point value from xmm2/m64 and duplicate into xmm1.|
|VEX.256.F2.0F.WIG 12 /rVMOVDDUP ymm1, ymm2/m256|RM|V/V|AVX|Move even index double-precision floating-point values from ymm2/mem and duplicate each element into ymm1.|
|EVEX.128.F2.0F.W1 12 /rVMOVDDUP xmm1 {k1}{z}, xmm2/m64|DUP-RM|V/V|AVX512VLAVX512F|Move double-precision floating-point value from xmm2/m64 and duplicate each element into xmm1 subject to writemask k1.|
|EVEX.256.F2.0F.W1 12 /rVMOVDDUP ymm1 {k1}{z}, ymm2/m256|DUP-RM|V/V|AVX512VLAVX512F|Move even index double-precision floating-point values from ymm2/m256 and duplicate each element into ymm1 subject to writemask k1.|
|EVEX.512.F2.0F.W1 12 /rVMOVDDUP zmm1 {k1}{z}, zmm2/m512|DUP-RM|V/V|AVX512F|Move even index double-precision floating-point values from zmm2/m512 and duplicate each element into zmm1 subject to writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|DUP-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


For 256-bit or higher versions: Duplicates even-indexed double-precision floating-point values from the source operand (the second operand) and into adjacent pair and store to the destination operand (the first operand).

For 128-bit versions: Duplicates the low double-precision floating-point value from the source operand (the second operand) and store to the destination operand (the first operand).

128-bit Legacy SSE version: Bits (MAX_VL-1:128) of the corresponding destination register are unchanged. The source operand is XMM register or a 64-bit memory location.

VEX.128 and EVEX.128 encoded version: Bits (MAX_VL-1:128) of the destination register are zeroed. The source operand is XMM register or a 64-bit memory location. The destination is updated conditionally under the writemask for EVEX version.

VEX.256 and EVEX.256 encoded version: Bits (MAX_VL-1:256) of the destination register are zeroed. The source operand is YMM register or a 256-bit memory location. The destination is updated conditionally under the writemask for EVEX version.

EVEX.512 encoded version: The destination is updated according to the writemask. The source operand is ZMM register or a 512-bit memory location.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.539978 200.700012">
<rect x="0.000000" y="10.000000" width="0.480000" height="103.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="103.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="113.500000" width="396.540009" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.880005" y="92.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.880005" y="92.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="92.260010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="105.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="92.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.160004" y="92.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.160004" y="92.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="105.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="92.020020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.379990" y="92.260010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.379990" y="92.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="105.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="92.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.659973" y="92.260010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.659973" y="92.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="356.640015" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="105.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="92.020020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.880005" y="24.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.880005" y="24.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="24.760010" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="38.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="24.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.160004" y="24.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.160004" y="24.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="38.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="24.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M248.879990,75.940002 L249.119980,75.940002 L249.300003,75.880005 C250.106003 75.539001,250.120987 74.284973,249.119980 73.960022  L248.699997,73.960022 C247.705002 74.161011,247.602982 75.596985,248.520004 75.880005  L248.699997,75.940002 L248.879990,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M248.879990,74.979980 L253.860001,74.979980 L253.679977,75.639954 L249.360001,90.639954 L248.879990,92.320007 L248.399979,90.639954 L244.139999,75.639954 L243.959976,74.979980 L244.619980,74.979980 L245.099991,75.339966 L249.360001,90.339966 L248.399979,90.639954 L248.399979,90.339966 L252.719986,75.339966 L253.679977,75.639954 L253.199997,76.000000 L248.879990,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.620010" y="74.979980" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M248.879990,75.460022 L253.199997,75.460022 L248.879990,90.460022 L244.619980,75.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="247.919998" y="65.260010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M174.659988,75.940002 L174.839981,75.940002 L175.019974,75.880005 C175.927994 75.515991,175.775986 74.198975,174.839981 73.960022  L174.419998,73.960022 C173.483994 74.198975,173.331985 75.515991,174.239975 75.880005  L174.419998,75.940002 L174.659988,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M174.659988,74.979980 L179.580002,74.979980 L179.399979,75.639954 L175.139999,90.639954 L174.659988,92.320007 L174.179977,90.639954 L169.860001,75.639954 L169.679977,74.979980 L170.339981,74.979980 L170.819992,75.339966 L175.139999,90.339966 L174.179977,90.639954 L174.179977,90.339966 L178.439987,75.339966 L179.399979,75.639954 L178.919998,76.000000 L174.659988,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.340012" y="74.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M174.659988,75.460022 L178.919998,75.460022 L174.659988,90.460022 L170.339981,75.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.699997" y="38.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.380005,75.940002 L100.559998,75.940002 L100.800003,75.880005 C101.662003 75.491028,101.519012 74.146973,100.559998 73.960022  L100.200012,73.960022 C99.205002 74.161011,99.103012 75.596985,100.020004 75.880005  L100.200012,75.940002 L100.380005,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.380005,74.979980 L105.360001,74.979980 L105.180008,75.639954 L100.860001,90.639954 L100.380005,92.320007 L99.900009,90.639954 L95.580002,75.639954 L95.400009,74.979980 L96.059998,74.979980 L96.540009,75.339966 L100.860001,90.339966 L99.900009,90.639954 L99.900009,90.339966 L104.220001,75.339966 L105.180008,75.639954 L104.700012,76.000000 L100.380005,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.059998" y="74.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.380005,75.460022 L104.700012,75.460022 L100.380005,90.460022 L96.059998,75.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="99.419998" y="65.260010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.379990" y="24.760010" width="74.279999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.379990" y="24.520020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="38.020020" width="74.519997" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="24.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.659973" y="24.760010" width="74.220001" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.659973" y="24.520020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="356.640015" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="38.020020" width="74.459999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="24.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M323.159973,75.940002 L323.339966,75.940002 L323.519958,75.880005 C324.445007 75.569031,324.273010 74.142029,323.339966 73.960022  L322.919983,73.960022 C321.984009 74.198975,321.831970 75.515991,322.739990 75.880005  L322.919983,75.940002 L323.159973,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M323.159973,74.979980 L328.080017,74.979980 L327.899963,75.639954 L323.640015,90.639954 L323.159973,92.320007 L322.679993,90.639954 L318.359985,75.639954 L318.179993,74.979980 L318.839966,74.979980 L319.320007,75.339966 L323.640015,90.339966 L322.679993,90.639954 L322.679993,90.339966 L326.940002,75.339966 L327.899963,75.639954 L327.419983,76.000000 L323.159973,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="318.840027" y="74.979980" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M323.159973,75.460022 L327.419983,75.460022 L323.159973,90.460022 L318.839966,75.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="322.200012" y="38.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="100.380005" y="64.300049" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.879990" y="64.300049" width="74.279999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="323.520020" y="33.280029" textLength="4.170000" font-size="8px">0</text>
<text x="318.479980" y="33.280029" textLength="5.002500" font-size="8px">X</text>
<text x="244.199997" y="33.280029" textLength="5.002500" font-size="8px">X</text>
<text x="50.338486" y="34.900024" textLength="5.415000" font-size="8px">C</text>
<text x="44.879990" y="34.900024" textLength="5.415000" font-size="8px">R</text>
<text x="169.979996" y="33.280029" textLength="5.002500" font-size="8px">X</text>
<text x="50.035522" y="100.780029" textLength="5.002500" font-size="8px">S</text>
<text x="45.054016" y="100.780029" textLength="5.002500" font-size="8px">E</text>
<text x="323.520020" y="100.780029" textLength="4.170000" font-size="8px">0</text>
<text x="173.880020" y="100.780029" textLength="4.170000" font-size="8px">2</text>
<text x="168.840012" y="100.780029" textLength="5.002500" font-size="8px">X</text>
<text x="99.600006" y="100.780029" textLength="4.170000" font-size="8px">2</text>
<text x="94.620010" y="100.780029" textLength="5.002500" font-size="8px">X</text>
<text x="249.180008" y="100.780029" textLength="4.170000" font-size="8px">0</text>
<text x="244.199997" y="100.780029" textLength="5.002500" font-size="8px">X</text>
<text x="174.960007" y="33.280029" textLength="4.170000" font-size="8px">2</text>
<text x="100.679993" y="33.280029" textLength="4.170000" font-size="8px">3</text>
<text x="39.660019" y="100.780029" textLength="5.415000" font-size="8px">D</text>
<text x="318.479980" y="100.780029" textLength="5.002500" font-size="8px">X</text>
<text x="55.017029" y="100.780029" textLength="4.582500" font-size="8px">T</text>
<text x="249.180008" y="33.280029" textLength="4.170000" font-size="8px">1</text>
<text x="95.699997" y="33.280029" textLength="5.002500" font-size="8px">X</text>
<text x="39.899994" y="34.900024" textLength="5.002500" font-size="8px">S</text>
</svg>
<figcaption>Figure 4-2.  VMOVDDUP Operation
</figcaption></figure>
```

### Operation
#### VMOVDDUP (EVEX encoded versions) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
TMP_SRC[63:0] <-  SRC[63:0] 
TMP_SRC[127:64] <-  SRC[63:0]
IF VL >= 256
 TMP_SRC[191:128]  <- SRC[191:128]
 TMP_SRC[255:192] <-  SRC[191:128]
FI;
IF VL >= 512
 TMP_SRC[319:256]  <- SRC[319:256]
 TMP_SRC[383:320]  <- SRC[319:256]
 TMP_SRC[477:384]  <- SRC[477:384]
 TMP_SRC[511:484]  <- SRC[477:384]
FI;
FOR j <-  0 TO KL-1
 i <-  j \htmlonly{*} 64
 IF k1[j] OR \htmlonly{*}no writemask\htmlonly{*}
   THEN DEST[i+63:i] <-  TMP_SRC[i+63:i]
   ELSE 
    IF \htmlonly{*}merging-masking\htmlonly{*} ; merging-masking
      THEN \htmlonly{*}DEST[i+63:i] remains unchanged\htmlonly{*}
      ELSE  ; zeroing-masking
        DEST[i+63:i] <-  0  ; zeroing-masking
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDDUP (VEX.256 encoded version)
```info-verb
DEST[63:0]  <-SRC[63:0]
DEST[127:64] <- SRC[63:0]
DEST[191:128] <- SRC[191:128]
DEST[255:192]  <-SRC[191:128]
DEST[MAX_VL-1:256]  <-0
```
#### VMOVDDUP (VEX.128 encoded version)
```info-verb
DEST[63:0]  <-SRC[63:0]
DEST[127:64] <- SRC[63:0]
DEST[MAX_VL-1:128] <- 0
```
#### MOVDDUP (128-bit Legacy SSE version)
```info-verb
DEST[63:0]  <-SRC[63:0]
DEST[127:64]  <-SRC[63:0]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVDDUP __m512d _mm512_movedup_pd( __m512d a);
VMOVDDUP __m512d _mm512_mask_movedup_pd(__m512d s, __mmask8 k, __m512d a);
VMOVDDUP __m512d _mm512_maskz_movedup_pd( __mmask8 k, __m512d a);
VMOVDDUP __m256d _mm256_mask_movedup_pd(__m256d s, __mmask8 k, __m256d a);
VMOVDDUP __m256d _mm256_maskz_movedup_pd( __mmask8 k, __m256d a);
VMOVDDUP __m128d _mm_mask_movedup_pd(__m128d s, __mmask8 k, __m128d a);
VMOVDDUP __m128d _mm_maskz_movedup_pd( __mmask8 k, __m128d a);
MOVDDUP __m256d _mm256_movedup_pd (__m256d a);
MOVDDUP __m128d _mm_movedup_pd (__m128d a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; 

EVEX-encoded instruction, see Exceptions Type E5NF.

#UD If EVEX.vvvv != 1111B or VEX.vvvv != 1111B.

