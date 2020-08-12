----------------------------
title : PUNPCKHBW, PUNPCKHWD, PUNPCKHDQ, PUNPCKHQDQs (Intel x86/64 assembly instruction)
cat_title : PUNPCKHBW, PUNPCKHWD, PUNPCKHDQ, PUNPCKHQDQ
ref_title : PUNPCKHBW, PUNPCKHWD, PUNPCKHDQ, PUNPCKHQDQ
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PUNPCKHBW, PUNPCKHWD, PUNPCKHDQ, PUNPCKHQDQ

** Unpack High Data**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 68 /r\footnote{1}\newline{}\newline{}PUNPCKHBW mm, mm/m64|RM|V/V|MMX|Unpack and interleave high-order bytes from mm and mm/m64 into mm.|
|66 0F 68 /r\newline{}\newline{}PUNPCKHBW xmm1, xmm2/m128|RM|V/V|SSE2|Unpack and interleave high-order bytes from xmm1 and xmm2/m128 into xmm1.|
|0F 69 /r\footnote{1}\newline{}\newline{}PUNPCKHWD mm, mm/m64|RM|V/V|MMX|Unpack and interleave high-order words from mm and mm/m64 into mm.|
|66 0F 69 /r\newline{}\newline{}PUNPCKHWD xmm1, xmm2/m128|RM|V/V|SSE2|Unpack and interleave high-order words from xmm1 and xmm2/m128 into xmm1.|
|0F 6A /r\footnote{1}\newline{}\newline{}PUNPCKHDQ mm, mm/m64|RM|V/V|MMX|Unpack and interleave high-order doublewords from mm and mm/m64 into mm.|
|66 0F 6A /r\newline{}\newline{}PUNPCKHDQ xmm1, xmm2/m128|RM|V/V|SSE2|Unpack and interleave high-order doublewords from xmm1 and xmm2/m128 into xmm1.|
|66 0F 6D /r\newline{}\newline{}PUNPCKHQDQ xmm1, xmm2/m128|RM|V/V|SSE2|Unpack and interleave high-order quadwords from xmm1 and xmm2/m128 into xmm1.|
|VEX.NDS.128.66.0F.WIG 68/r\newline{}\newline{}VPUNPCKHBW xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Interleave high-order bytes from xmm2 and xmm3/m128 into xmm1.|
|VEX.NDS.128.66.0F.WIG 69/r\newline{}\newline{}VPUNPCKHWD xmm1,xmm2, xmm3/m128|RVM|V/V|AVX|Interleave high-order words from xmm2 and xmm3/m128 into xmm1.|
|VEX.NDS.128.66.0F.WIG 6A/r\newline{}\newline{}VPUNPCKHDQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Interleave high-order doublewords from xmm2 and xmm3/m128 into xmm1.|
|VEX.NDS.128.66.0F.WIG 6D/r\newline{}VPUNPCKHQDQ xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Interleave high-order quadword from xmm2 and xmm3/m128 into xmm1 register.|
|VEX.NDS.256.66.0F.WIG 68 /r\newline{}VPUNPCKHBW ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Interleave high-order bytes from ymm2 and ymm3/m256 into ymm1 register.|
|VEX.NDS.256.66.0F.WIG 69 /r\newline{}VPUNPCKHWD ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Interleave high-order words from ymm2 and ymm3/m256 into ymm1 register.|
|VEX.NDS.256.66.0F.WIG 6A /r\newline{}VPUNPCKHDQ ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Interleave high-order doublewords from ymm2 and ymm3/m256 into ymm1 register.|
|VEX.NDS.256.66.0F.WIG 6D /r\newline{}VPUNPCKHQDQ ymm1, ymm2, ymm3/m256|RVM|V/V|AVX2|Interleave high-order quadword from ymm2 and ymm3/m256 into ymm1 register.|
|EVEX.NDS.128.66.0F.WIG 68 /r\newline{}VPUNPCKHBW xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VLAVX512BW|Interleave high-order bytes from xmm2 and xmm3/m128 into xmm1 register using k1 write mask.|
|EVEX.NDS.128.66.0F.WIG 69 /r\newline{}VPUNPCKHWD xmm1 {k1}{z}, xmm2, xmm3/m128|FVM|V/V|AVX512VLAVX512BW|Interleave high-order words from xmm2 and xmm3/m128 into xmm1 register using k1 write mask.|
|EVEX.NDS.128.66.0F.W0 6A /r\newline{}VPUNPCKHDQ xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV|V/V|AVX512VLAVX512F|Interleave high-order doublewords from xmm2 and xmm3/m128/m32bcst into xmm1 register using k1 write mask.|
|EVEX.NDS.128.66.0F.W1 6D /r\newline{}VPUNPCKHQDQ xmm1 {k1}{z}, xmm2, xmm3/m128/m64bcst|FV|V/V|AVX512VLAVX512F|Interleave high-order quadword from xmm2 and xmm3/m128/m64bcst into xmm1 register using k1 write mask.|


|EVEX.NDS.256.66.0F.WIG 68 /r\newline{}VPUNPCKHBW ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VL\newline{}AVX512BW|Interleave high-order bytes from ymm2 and \newline{}ymm3/m256 into ymm1 register using k1 \newline{}write mask.|
|------------------------------------------------------------------------------|---|---|--------------------------|---------------------------------------------------------------------------------------------------------------|
|EVEX.NDS.256.66.0F.WIG 69 /rVPUNPCKHWD ymm1 {k1}{z}, ymm2, ymm3/m256|FVM|V/V|AVX512VLAVX512BW|Interleave high-order words from ymm2 and ymm3/m256 into ymm1 register using k1 write mask.|
|EVEX.NDS.256.66.0F.W0 6A /rVPUNPCKHDQ ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV|V/V|AVX512VLAVX512F|Interleave high-order doublewords from ymm2 and ymm3/m256/m32bcst into ymm1 register using k1 write mask.|
|EVEX.NDS.256.66.0F.W1 6D /rVPUNPCKHQDQ ymm1 {k1}{z}, ymm2, ymm3/m256/m64bcst|FV|V/V|AVX512VLAVX512F|Interleave high-order quadword from ymm2 and ymm3/m256/m64bcst into ymm1 register using k1 write mask.|
|EVEX.NDS.512.66.0F.WIG 68/rVPUNPCKHBW zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Interleave high-order bytes from zmm2 and zmm3/m512 into zmm1 register.|
|EVEX.NDS.512.66.0F.WIG 69/rVPUNPCKHWD zmm1 {k1}{z}, zmm2, zmm3/m512|FVM|V/V|AVX512BW|Interleave high-order words from zmm2 and zmm3/m512 into zmm1 register.|
|EVEX.NDS.512.66.0F.W0 6A /rVPUNPCKHDQ zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV|V/V|AVX512F|Interleave high-order doublewords from zmm2 and zmm3/m512/m32bcst into zmm1 register using k1 write mask.|
|EVEX.NDS.512.66.0F.W1 6D /rVPUNPCKHQDQ zmm1 {k1}{z}, zmm2, zmm3/m512/m64bcst|FV|V/V|AVX512F|Interleave high-order quadword from zmm2 and zmm3/m512/m64bcst into zmm1 register using k1 write mask.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Unpacks and interleaves the high-order data elements (bytes, words, doublewords, or quadwords) of the destina-tion operand (first operand) and source operand (second operand) into the destination operand. Figure 4-20 shows the unpack operation for bytes in 64-bit operands. The low-order data elements are ignored. 

```embed
<figure>
<svg viewBox="0 0 379.679993 194.940002">
<rect x="0.000000" y="10.000000" width="0.480000" height="96.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="96.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="106.780029" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.259995" y="82.479980" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="52.259995" y="82.239990" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.020004" y="82.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.020004" y="100.239990" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.020004" y="82.239990" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="87.839996" y="82.239990" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="87.839996" y="82.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.899994" y="82.239990" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.899994" y="82.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.960007" y="82.239990" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.960007" y="82.479980" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.020004" y="82.239990" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="178.020004" y="82.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.020004" y="82.239990" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.020004" y="82.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.020004" y="82.239990" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.020004" y="82.479980" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="70.020004" y="82.239990" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="70.020004" y="82.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.319992" y="19.719971" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="196.319992" y="19.479980" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.080017" y="19.719971" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.080002" y="37.479980" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.080002" y="19.479980" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="231.960007" y="19.479980" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="231.960007" y="19.719971" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="267.960022" y="19.479980" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="267.960022" y="19.719971" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.020020" y="19.479980" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.020020" y="19.719971" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="322.080017" y="19.479980" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="322.080017" y="19.719971" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="250.080002" y="19.479980" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="250.080002" y="19.719971" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="286.080017" y="19.479980" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="286.080017" y="19.719971" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="214.080002" y="19.479980" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="214.080002" y="19.719971" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="34.080002" y="19.839966" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="34.080002" y="19.600037" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.840012" y="19.840027" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="33.839996" y="37.600037" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="33.839996" y="19.599976" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.660004" y="19.599976" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.660004" y="19.840027" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="105.720001" y="19.599976" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="105.720001" y="19.840027" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="141.779999" y="19.599976" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="141.779999" y="19.840027" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.840012" y="19.599976" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.840012" y="19.840027" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="87.839996" y="19.599976" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="87.839996" y="19.840027" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.839996" y="19.599976" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.839996" y="19.840027" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="51.839996" y="19.599976" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="51.839996" y="19.840027" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M86.639999,80.140015 L86.520004,79.660034 L85.500000,80.020020 L85.619995,80.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M85.979996,79.899963 L87.000000,81.159973 L87.659988,81.999939 L86.580002,82.059937 L81.000000,82.419983 L79.259995,82.479980 L80.699997,81.459961 L85.199997,78.219971 L86.099991,77.619934 L86.099991,78.639954 L85.860001,79.059937 L81.300003,82.299988 L80.699997,81.459961 L80.940002,81.399963 L86.519989,81.039978 L86.580002,82.059937 L86.159988,81.879944 L85.139999,80.619934" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M86.100006,78.640015 L86.100006,80.260010 L85.139999,80.619995 L85.020004,80.260010 L85.020004,78.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M85.559998,80.260010 L86.580002,81.520020 L81.000000,81.880005 L85.559998,78.640015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.319992,37.719971 L205.559982,37.659973 L205.379990,37.179993 L205.139999,37.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M86.699997,80.140015 L86.459991,80.200012 L86.279999,79.720032 L86.520004,79.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.319992,37.719971 L205.139999,37.239990 L86.519989,79.659973 L86.699997,80.139954" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M123.479996,79.779968 L123.239990,79.299988 L122.279999,79.659973 L122.519989,80.139954" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.759995,79.539978 L123.899994,80.799988 L124.619995,81.579956 L123.539993,81.699951 L117.959991,82.359985 L116.220001,82.539978 L117.599991,81.459961 L121.979996,77.919983 L122.819992,77.259949 L122.879990,78.279968 L122.639999,78.699951 L118.259995,82.239990 L117.599991,81.459961 L117.899994,81.339966 L123.479996,80.679993 L123.539993,81.699951 L123.179993,81.519958 L122.039993,80.259949" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.880005,78.279968 L122.940002,79.899963 L122.040009,80.259949 L121.919998,80.079956 L121.860001,79.899963 L121.800003,78.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.399994,79.899963 L123.539993,81.159973 L117.959991,81.819946 L122.339996,78.279968" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.020004,37.719971 L223.199997,37.659973 L223.020004,37.239990 L222.840012,37.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M123.479996,79.779968 L123.300003,79.839966 L123.119995,79.419983 L123.300003,79.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.020004,37.719971 L222.840012,37.299988 L123.300003,79.359985 L123.479996,79.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M158.099991,79.299988 L157.860001,78.820007 L156.899979,79.299988 L157.139999,79.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M157.379990,79.179993 L158.580002,80.320007 L159.360001,80.979980 L158.279984,81.159973 L152.819992,82.179993 L151.139999,82.479980 L152.399979,81.339966 L156.479996,77.559998 L157.259995,76.839966 L157.319992,77.859985 L157.139999,78.279968 L153.059982,82.059998 L152.399979,81.339966 L152.639999,81.219971 L158.099991,80.200012 L158.279984,81.159973 L157.860001,81.039978 L156.659988,79.899963" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M157.319992,77.859985 L157.559982,79.479980 L156.659988,79.899963 L156.539993,79.779968 L156.539993,79.599976 L156.360001,77.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M157.020004,79.539978 L158.220016,80.679993 L152.759995,81.699951 L156.840012,77.919983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M241.800003,37.719971 L241.979996,37.599976 L241.740005,37.179993 L241.560013,37.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M158.099991,79.299988 L157.919998,79.419983 L157.679977,79.000000 L157.860001,78.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M241.800003,37.719971 L241.560013,37.299988 L157.860001,78.879944 L158.099991,79.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.139999,78.640015 L192.900009,78.280029 L191.999985,78.820007 L192.240005,79.179993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M192.419998,78.580017 L193.680008,79.600037 L194.520004,80.260010 L193.499985,80.500000 L188.099991,82.000000 L186.419998,82.480042 L187.560013,81.220032 L191.340012,77.080017 L192.060013,76.299988 L192.240005,77.260010 L192.120010,77.739990 L188.340012,81.880005 L187.560013,81.220032 L187.800003,81.040039 L193.199997,79.540039 L193.499985,80.500000 L193.080002,80.440002 L191.819992,79.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M192.240005,77.260010 L192.599991,78.880005 L191.819992,79.419983 L191.639999,79.299988 L191.639999,79.119995 L191.280014,77.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M192.120010,79.000000 L193.380020,80.020020 L187.979996,81.520020 L191.760025,77.380005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.900024,37.719971 L259.080017,37.599976 L258.840027,37.179993 L258.660034,37.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.139999,78.700012 L192.960007,78.820007 L192.719986,78.400024 L192.900009,78.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.900024,37.719971 L258.660034,37.299988 L192.900009,78.279968 L193.139999,78.699951" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.819992,78.279968 L161.580002,78.639954 L162.479996,79.179993 L162.719986,78.819946" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.120010,78.880005 L162.479996,77.260010 L162.660019,76.299988 L163.380020,77.080017 L167.160019,81.280029 L168.300003,82.539978 L166.620010,82.059998 L161.220016,80.500000 L160.199997,80.260010 L161.040024,79.599976 L161.520004,79.539978 L166.919998,81.099976 L166.620010,82.059998 L166.380020,81.940002 L162.600021,77.739990 L163.380020,77.080017 L163.440018,77.500000 L163.080002,79.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.039993,79.599976 L162.300003,78.579956 L163.080002,79.119995 L163.080002,79.299988 L162.899979,79.419983 L161.639999,80.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.599991,79.000000 L162.959976,77.380005 L166.740005,81.580017 L161.339981,80.020020" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M97.680008,38.380005 L97.500015,38.260010 L97.260010,38.679993 L97.440002,38.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.819992,78.279968 L161.999985,78.399963 L161.759995,78.819946 L161.580002,78.699951" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M97.680008,38.380005 L97.440002,38.799988 L161.580002,78.700012 L161.820023,78.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M127.619995,77.500000 L127.259995,77.859985 L128.099991,78.520020 L128.459991,78.159973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M127.800003,78.159973 L128.339996,76.599976 L128.639999,75.639954 L129.240005,76.539978 L132.419998,81.099976 L133.440002,82.479980 L131.820007,81.819946 L126.660004,79.659973 L125.699997,79.239990 L126.600006,78.759949 L127.020004,78.759949 L132.180008,80.919983 L131.820007,81.819946 L131.580002,81.639954 L128.400009,77.079956 L129.240005,76.539978 L129.300003,76.959961 L128.760010,78.519958" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.600006,78.760010 L128.040009,77.919983 L128.760010,78.520020 L128.700012,78.700012 L128.520004,78.760010 L127.080002,79.600037" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M128.279999,78.339966 L128.819992,76.779968 L132.000000,81.339966 L126.839996,79.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M78.419998,37.839966 L78.240005,37.719971 L77.940002,38.079956 L78.119995,38.199951" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M127.619995,77.500000 L127.799988,77.619995 L127.500000,77.979980 L127.319992,77.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M78.419998,37.839966 L78.119995,38.199951 L127.319992,77.859985 L127.619995,77.499939" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.279999,76.419983 L91.919998,76.779968 L92.580002,77.559998 L92.940002,77.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.339996,77.140015 L93.179993,75.760010 L93.660004,74.859985 L94.080002,75.820007 L96.300003,80.920044 L96.959991,82.480042 L95.580002,81.520020 L90.959991,78.400024 L90.119995,77.859985 L90.959991,77.559998 L91.500000,77.559998 L96.119995,80.679993 L95.580002,81.520020 L95.399994,81.340027 L93.179993,76.239990 L94.080002,75.820007 L94.019989,76.239990 L93.179993,77.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M90.960007,77.559998 L92.520004,76.960022 L93.180008,77.619995 L93.120010,77.799988 L92.940002,77.859985 L91.380005,78.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.759995,77.380005 L93.599991,76.000000 L95.819992,81.099976 L91.199997,77.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M60.240005,37.899963 L60.120010,37.719971 L59.760010,38.019958 L59.880005,38.199951" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.279999,76.479980 L92.399994,76.659973 L92.039993,76.959961 L91.919998,76.779968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M60.240005,37.899963 L59.880005,38.199951 L91.919998,76.779968 L92.280014,76.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M59.039993,75.279968 L58.559998,75.399963 L58.979996,76.419983 L59.459991,76.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M58.860001,76.000000 L60.059998,74.919983 L60.839996,74.200012 L60.960007,75.280029 L61.500000,80.799988 L61.619995,82.479980 L60.600006,81.159973 L57.180008,76.780029 L56.520004,75.940002 L57.539993,75.880005 L57.960007,76.119995 L61.380005,80.500000 L60.600006,81.159973 L60.479996,80.859985 L59.940002,75.340027 L60.960007,75.280029 L60.779999,75.640015 L59.580002,76.719971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M57.539993,75.880005 L59.219986,75.820007 L59.579987,76.720032 L59.399994,76.840027 L59.219986,76.900024 L57.539993,76.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M59.220001,76.359985 L60.419998,75.279968 L60.960007,80.799988 L57.540009,76.419983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M44.220001,37.959961 L44.160004,37.779968 L43.740005,37.959961 L43.800003,38.139954" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M59.039993,75.279968 L59.099991,75.459961 L58.679993,75.639954 L58.619995,75.459961" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M44.220001,37.959961 L43.800003,38.139954 L58.619995,75.459961 L59.039993,75.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="45.123886" y="93.941284" textLength="4.882501" font-size="8px">T</text>
<text x="353.767456" y="31.421326" textLength="5.329997" font-size="8px">S</text>
<text x="348.432678" y="31.421326" textLength="5.329997" font-size="8px">E</text>
<text x="25.857590" y="31.060913" textLength="5.769502" font-size="8px">C</text>
<text x="20.039337" y="31.060913" textLength="5.769502" font-size="8px">R</text>
<text x="74.577927" y="32.020630" textLength="5.329997" font-size="8px">Y</text>
<text x="60.659195" y="32.020630" textLength="4.442996" font-size="8px">6</text>
<text x="38.219666" y="32.020630" textLength="5.329997" font-size="8px">Y</text>
<text x="96.959915" y="32.020630" textLength="4.442996" font-size="8px">4</text>
<text x="91.619522" y="32.020630" textLength="5.329997" font-size="8px">Y</text>
<text x="242.817276" y="31.360596" textLength="4.442996" font-size="8px">5</text>
<text x="237.476883" y="31.360596" textLength="5.329997" font-size="8px">X</text>
<text x="206.459000" y="31.360596" textLength="4.442996" font-size="8px">7</text>
<text x="201.118607" y="31.360596" textLength="5.329997" font-size="8px">X</text>
<text x="259.858826" y="31.360596" textLength="4.442996" font-size="8px">4</text>
<text x="254.518448" y="31.360596" textLength="5.329997" font-size="8px">X</text>
<text x="132.479111" y="32.620789" textLength="4.442996" font-size="8px">2</text>
<text x="163.439438" y="32.620789" textLength="5.329997" font-size="8px">Y</text>
<text x="314.097778" y="31.420532" textLength="4.442996" font-size="8px">1</text>
<text x="308.757385" y="31.420532" textLength="5.329997" font-size="8px">X</text>
<text x="294.898621" y="31.420532" textLength="4.442996" font-size="8px">2</text>
<text x="289.558228" y="31.420532" textLength="5.329997" font-size="8px">X</text>
<text x="272.399109" y="31.420532" textLength="5.329997" font-size="8px">X</text>
<text x="331.078674" y="31.420532" textLength="4.442996" font-size="8px">0</text>
<text x="325.799011" y="31.420532" textLength="5.329997" font-size="8px">X</text>
<text x="127.678925" y="93.700012" textLength="5.329997" font-size="8px">Y</text>
<text x="97.200455" y="93.700012" textLength="4.442996" font-size="8px">6</text>
<text x="61.861069" y="93.700012" textLength="4.442996" font-size="8px">7</text>
<text x="56.520676" y="93.700012" textLength="5.329997" font-size="8px">Y</text>
<text x="168.300400" y="93.700012" textLength="4.442996" font-size="8px">4</text>
<text x="151.319687" y="93.700012" textLength="4.442996" font-size="8px">5</text>
<text x="145.979294" y="93.700012" textLength="5.329997" font-size="8px">X</text>
<text x="115.980270" y="93.700012" textLength="4.442996" font-size="8px">6</text>
<text x="74.220917" y="93.700012" textLength="5.329997" font-size="8px">X</text>
<text x="182.280014" y="93.700012" textLength="5.329997" font-size="8px">X</text>
<text x="79.561295" y="93.700012" textLength="4.442996" font-size="8px">7</text>
<text x="14.759689" y="31.060913" textLength="5.329997" font-size="8px">S</text>
<text x="359.102234" y="31.421326" textLength="4.882501" font-size="8px">T</text>
<text x="168.779831" y="32.620789" textLength="4.442996" font-size="8px">0</text>
<text x="79.918320" y="32.020630" textLength="4.442996" font-size="8px">5</text>
<text x="187.620407" y="93.700012" textLength="4.442996" font-size="8px">4</text>
<text x="151.738235" y="32.620789" textLength="4.442996" font-size="8px">1</text>
<text x="277.739502" y="31.420532" textLength="4.442996" font-size="8px">3</text>
<text x="43.560043" y="32.020630" textLength="4.442996" font-size="8px">7</text>
<text x="110.039581" y="32.620789" textLength="5.329997" font-size="8px">Y</text>
<text x="110.639893" y="93.700012" textLength="5.329997" font-size="8px">X</text>
<text x="127.138718" y="32.620789" textLength="5.329997" font-size="8px">Y</text>
<text x="28.680008" y="93.941284" textLength="5.769502" font-size="8px">D</text>
<text x="146.397842" y="32.620789" textLength="5.329997" font-size="8px">Y</text>
<text x="34.454300" y="93.941284" textLength="5.329997" font-size="8px">E</text>
<text x="218.217758" y="31.360596" textLength="5.329997" font-size="8px">X</text>
<text x="115.379959" y="32.620789" textLength="4.442996" font-size="8px">3</text>
<text x="162.960007" y="93.700012" textLength="5.329997" font-size="8px">Y</text>
<text x="55.318802" y="32.020630" textLength="5.329997" font-size="8px">Y</text>
<text x="91.860077" y="93.700012" textLength="5.329997" font-size="8px">Y</text>
<text x="39.789093" y="93.941284" textLength="5.329997" font-size="8px">S</text>
<text x="342.658386" y="31.421326" textLength="5.769502" font-size="8px">D</text>
<text x="133.019302" y="93.700012" textLength="4.442996" font-size="8px">5</text>
<text x="223.558151" y="31.360596" textLength="4.442996" font-size="8px">6</text>
</svg>
<figcaption>Figure 4-20.  PUNPCKHBW Instruction Operation Using 64-bit Operands
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 326.207245 163.119995">
<rect x="150.359650" y="78.160492" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="150.359650" y="77.920532" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.119659" y="78.160522" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.119659" y="95.920532" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.119659" y="77.920502" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="185.939636" y="77.920502" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.999634" y="77.920502" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="258.059631" y="77.920502" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="276.119659" y="77.920502" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.119659" y="77.920502" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="240.119659" y="77.920502" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.119659" y="77.920502" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.559631" y="15.400513" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="181.559631" y="15.160522" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="325.319641" y="15.400513" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.319641" y="33.160522" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="181.319641" y="15.160522" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.139648" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.199646" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="289.259644" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.319641" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.319641" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.319641" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="199.319641" y="15.160522" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.319641" y="15.520508" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="19.319641" y="15.280457" width="144.240005" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="163.079651" y="15.520508" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.079651" y="33.280457" width="144.240005" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.079651" y="15.280518" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.899643" y="15.280518" width="0.480000" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.959641" y="15.280518" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="127.019638" y="15.280518" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.079651" y="15.280518" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="73.079651" y="15.280518" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.079651" y="15.280518" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="37.079651" y="15.280518" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.979645,70.600494 L178.499634,70.480499 L178.259644,71.560486 L178.739655,71.680481" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.439636,71.140503 L180.059631,70.900513 L181.079651,70.660492 L180.539642,71.680511 L177.899628,76.600494 L177.059631,78.040497 L176.999634,76.360504 L176.639648,70.780518 L176.519623,69.700500 L177.419647,70.300507 L177.599640,70.720490 L177.959625,76.300507 L176.999634,76.360504 L177.059631,76.060516 L179.699646,71.140503 L180.539642,71.680511 L180.179626,71.860504 L178.559631,72.100494" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M177.419647,70.300507 L178.799652,71.200500 L178.559662,72.100494 L178.379639,72.160492 L178.199646,72.040497 L176.819641,71.140503" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.499634,71.620483 L180.119629,71.380493 L177.479645,76.300476 L177.119629,70.720490" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.079651,34.660522 L187.139648,34.420532 L186.659637,34.300537 L186.599640,34.540527" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.979645,70.600494 L178.919647,70.840485 L178.439636,70.720490 L178.499634,70.480499" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.079651,34.660522 L186.599640,34.540527 L178.499664,70.480530 L178.979645,70.600525" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M212.399658,70.420502 L211.919647,70.420502 L212.039673,71.440491 L212.519653,71.440491" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M212.039642,70.960510 L213.539642,70.240509 L214.499634,69.820496 L214.259644,70.840515 L213.239655,76.360504 L212.939636,78.100525 L212.279633,76.480499 L210.239655,71.320496 L209.879639,70.360504 L210.779633,70.600525 L211.199646,70.900513 L213.239655,76.060516 L212.279633,76.480499 L212.279633,76.180511 L213.299652,70.660522 L214.259644,70.840515 L214.019653,71.200500 L212.519653,71.920502" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.779633,70.600494 L212.339630,70.960480 L212.519623,71.920502 L212.339630,71.980499 L212.159637,71.920502 L210.599640,71.560486" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M212.279633,71.440491 L213.779633,70.720490 L212.759644,76.240479 L210.719635,71.080505" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.679657,33.400513 L208.679657,33.160522 L208.199646,33.220520 L208.199646,33.460510" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M212.399658,70.420502 L212.399658,70.660492 L211.919647,70.720490 L211.919647,70.480499" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.679657,33.400513 L208.199646,33.460510 L211.919647,70.480530 L212.399658,70.420502" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.119659,70.840485 L251.639648,70.720490 L251.339661,71.740479 L251.819672,71.860474" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M251.579651,71.260498 L254.219666,71.260498 L253.619659,72.100494 L250.379639,76.660492 L249.359650,78.100494 L249.419647,76.360504 L249.719666,70.780487 L249.779663,69.760498 L250.559662,70.360504 L250.739655,70.840485 L250.439636,76.420502 L249.419647,76.360504 L249.539642,76.060486 L252.779663,71.500488 L253.619659,72.100494 L253.199646,72.340485 L251.579651,72.340485" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.559631,70.360504 L251.879639,71.380493 L251.579620,72.340515 L251.399628,72.280518 L251.279633,72.220490 L249.959625,71.200500" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M251.579651,71.800507 L253.199646,71.800507 L249.959656,76.360504 L250.259644,70.780518" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.479645,35.320496 L264.539642,35.080505 L264.059631,34.900513 L263.999634,35.140503" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.119659,70.900513 L252.059662,71.140503 L251.579651,70.960510 L251.639648,70.720520" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.479645,35.320496 L263.999634,35.140503 L251.639648,70.720490 L252.119659,70.900513" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.859650,70.360504 L283.379639,70.360504 L283.499664,71.440491 L283.979645,71.440491" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.499634,70.960510 L284.999634,70.300507 L285.959625,69.820496 L285.719635,70.900513 L284.579620,76.360504 L284.219635,78.040497 L283.619629,76.480499 L281.639648,71.260498 L281.279633,70.300507 L282.179626,70.540497 L282.599640,70.840515 L284.579620,76.060516 L283.619629,76.480499 L283.619629,76.180511 L284.759644,70.720520 L285.719635,70.900513 L285.479645,71.260498 L283.979645,71.920502" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M282.179657,70.540497 L283.799652,70.960510 L283.979645,71.920502 L283.799652,71.980499 L283.619659,71.920502 L281.999664,71.500488" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.739655,71.440491 L285.239655,70.780487 L284.099640,76.240479 L282.119659,71.020477" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M281.279633,34.600525 L281.279633,34.360535 L280.799622,34.420532 L280.799622,34.660522" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.859650,70.360504 L283.859650,70.600494 L283.379639,70.660492 L283.379639,70.420502" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M281.279633,34.600525 L280.799622,34.660522 L283.379639,70.420532 L283.859619,70.360535" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.279633,75.640503 L260.159637,76.120514 L261.179626,76.420502 L261.299622,75.940491" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.699646,76.240509 L260.579651,74.620514 L260.459656,73.540497 L261.419647,74.140503 L266.159637,77.140503 L267.659637,78.100494 L265.919647,78.100494 L260.339661,78.040497 L259.259644,77.980499 L259.859650,77.200500 L260.279633,77.020508 L265.859650,77.080505 L265.919647,78.100494 L265.619659,77.980499 L260.879639,74.980499 L261.419647,74.140503 L261.659637,74.500519 L261.779633,76.120514" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.859650,77.200500 L260.819641,75.880493 L261.779663,76.120514 L261.779663,76.360504 L261.659637,76.480499 L260.699646,77.800507" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M261.239655,76.180511 L261.119659,74.560516 L265.859650,77.560516 L260.279663,77.500519" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.499649,34.360474 L121.259644,34.300476 L121.139648,34.780457 L121.379654,34.840454" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M260.279633,75.640503 L260.519623,75.700500 L260.399628,76.180511 L260.159637,76.120514" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M121.499649,34.360474 L121.379654,34.840454 L260.159637,76.120483 L260.279633,75.640472" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.379639,75.340485 L223.259644,75.820496 L224.279633,76.180481 L224.399628,75.700470" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.799652,75.940491 L223.739655,74.320496 L223.679657,73.300476 L224.579651,73.900482 L229.199646,77.080505 L230.699646,78.100494 L228.899658,78.040497 L223.319641,77.740479 L222.299652,77.680481 L222.899658,76.900482 L223.379639,76.720490 L228.959656,77.020477 L228.899658,78.040497 L228.659637,77.920502 L224.039642,74.740479 L224.579651,73.900482 L224.819641,74.320496 L224.879639,75.940491" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.899658,76.900513 L223.919647,75.640503 L224.879669,75.940521 L224.879669,76.120514 L224.759644,76.240509 L223.739655,77.500519" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.339630,75.940491 L224.279633,74.320496 L228.899628,77.500488 L223.319641,77.200500" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.759644,34.360474 L101.519638,34.300476 L101.339645,34.780457 L101.579651,34.840454" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.439636,75.340485 L223.679626,75.400482 L223.499634,75.880493 L223.259644,75.820496" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.759644,34.360474 L101.579651,34.840454 L223.259644,75.820465 L223.439636,75.340485" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.439636,76.120483 L187.319641,76.600494 L188.339630,76.900482 L188.459625,76.420471" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.859650,76.720490 L187.739655,75.100494 L187.619659,74.020477 L188.579651,74.620483 L193.319641,77.620483 L194.759644,78.580475 L193.079651,78.580475 L187.439636,78.520477 L186.359650,78.460480 L186.959656,77.680481 L187.379639,77.500488 L193.019653,77.560486 L193.079651,78.580475 L192.779663,78.460480 L188.039642,75.460480 L188.579651,74.620483 L188.819641,74.980499 L188.939636,76.600494" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.959656,77.680511 L187.979645,76.360504 L188.939667,76.600525 L188.939667,76.840515 L188.819641,76.960510 L187.799652,78.280518" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.399658,76.660492 L188.279663,75.040497 L193.019653,78.040497 L187.379669,77.980499" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M50.699646,34.360474 L50.459641,34.300476 L50.339645,34.780457 L50.579651,34.840454" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.439636,76.120483 L187.679626,76.180481 L187.559631,76.660492 L187.319641,76.600494" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M50.699646,34.360474 L50.579651,34.840454 L187.319641,76.600464 L187.439667,76.120483" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.619659,75.340485 L151.499664,75.820496 L152.519653,76.180481 L152.639648,75.700470" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.039642,75.940491 L151.979645,74.260498 L151.979645,73.240479 L152.819641,73.840485 L157.439636,77.080505 L158.939636,78.100494 L157.139648,78.040497 L151.559631,77.740479 L150.539642,77.680481 L151.139648,76.900482 L151.619629,76.720490 L157.199646,77.020477 L157.139648,78.040497 L156.899628,77.920502 L152.279633,74.680481 L152.819641,73.840485 L153.059631,74.260498 L153.119629,75.940491" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.139648,76.900513 L152.159637,75.640503 L153.119659,75.940521 L153.119659,76.120514 L152.999634,76.240509 L151.979645,77.500519" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.579651,75.940491 L152.519653,74.260498 L157.139648,77.500488 L151.559662,77.200500" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M29.159637,33.760498 L28.919632,33.700500 L28.739639,34.180481 L28.979645,34.240479" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.679657,75.340485 L151.919647,75.400482 L151.739655,75.880493 L151.499664,75.820496" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M29.159637,33.760498 L28.979645,34.240479 L151.499634,75.820496 L151.679626,75.340515" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="149.217590" y="10.000000" textLength="3.887607" font-size="8px">1</text>
<text x="145.318787" y="10.000000" textLength="3.887607" font-size="8px">3</text>
<text x="23.216461" y="11.020142" textLength="3.887607" font-size="8px">5</text>
<text x="15.479004" y="11.020142" textLength="3.887607" font-size="8px">2</text>
<text x="292.919250" y="73.000214" textLength="3.887607" font-size="8px">0</text>
<text x="186.837219" y="11.380249" textLength="3.887607" font-size="8px">5</text>
<text x="182.938416" y="11.380249" textLength="3.887607" font-size="8px">5</text>
<text x="322.319641" y="11.800476" textLength="3.887607" font-size="8px">0</text>
<text x="137.888702" y="89.620972" textLength="5.329997" font-size="8px">S</text>
<text x="132.553925" y="89.620972" textLength="5.329997" font-size="8px">E</text>
<text x="126.779617" y="89.620972" textLength="5.769502" font-size="8px">D</text>
<text x="5.359558" y="26.741394" textLength="5.769502" font-size="8px">R</text>
<text x="0.000000" y="26.741394" textLength="5.329997" font-size="8px">S</text>
<text x="65.097092" y="27.701111" textLength="4.442996" font-size="8px">5</text>
<text x="59.817444" y="27.701111" textLength="5.329997" font-size="8px">Y</text>
<text x="40.558319" y="27.701111" textLength="5.329997" font-size="8px">Y</text>
<text x="28.739624" y="27.701111" textLength="4.442996" font-size="8px">7</text>
<text x="23.459976" y="27.701111" textLength="5.329997" font-size="8px">Y</text>
<text x="82.200226" y="27.701111" textLength="4.442996" font-size="8px">4</text>
<text x="76.859833" y="27.701111" textLength="5.329997" font-size="8px">Y</text>
<text x="227.996063" y="27.101013" textLength="4.442996" font-size="8px">5</text>
<text x="208.797668" y="27.101013" textLength="4.442996" font-size="8px">6</text>
<text x="191.638580" y="27.101013" textLength="4.442996" font-size="8px">7</text>
<text x="95.279892" y="28.301270" textLength="5.329997" font-size="8px">Y</text>
<text x="148.679749" y="28.301270" textLength="5.329997" font-size="8px">Y</text>
<text x="280.078979" y="27.101013" textLength="4.442996" font-size="8px">2</text>
<text x="262.979828" y="27.101013" textLength="4.442996" font-size="8px">3</text>
<text x="257.639435" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="316.379669" y="27.101013" textLength="4.442996" font-size="8px">0</text>
<text x="245.099152" y="27.101013" textLength="4.442996" font-size="8px">4</text>
<text x="231.118134" y="89.380493" textLength="4.442996" font-size="8px">3</text>
<text x="225.777740" y="89.380493" textLength="5.329997" font-size="8px">Y</text>
<text x="189.959656" y="89.380493" textLength="5.329997" font-size="8px">Y</text>
<text x="159.960632" y="89.380493" textLength="4.442996" font-size="8px">7</text>
<text x="154.620239" y="89.380493" textLength="5.329997" font-size="8px">Y</text>
<text x="260.999634" y="89.380493" textLength="5.329997" font-size="8px">Y</text>
<text x="249.358551" y="89.380493" textLength="4.442996" font-size="8px">3</text>
<text x="244.018158" y="89.380493" textLength="5.329997" font-size="8px">X</text>
<text x="214.079865" y="89.380493" textLength="4.442996" font-size="8px">6</text>
<text x="208.739471" y="89.380493" textLength="5.329997" font-size="8px">X</text>
<text x="172.320465" y="89.380493" textLength="5.329997" font-size="8px">X</text>
<text x="280.319641" y="89.380493" textLength="5.329997" font-size="8px">X</text>
<text x="186.358917" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="100.620270" y="28.301270" textLength="4.442996" font-size="8px">3</text>
<text x="117.719421" y="28.301270" textLength="4.442996" font-size="8px">2</text>
<text x="274.738586" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="148.377838" y="72.219879" textLength="3.887607" font-size="8px">5</text>
<text x="152.216492" y="72.219879" textLength="3.887607" font-size="8px">5</text>
<text x="45.898712" y="27.701111" textLength="4.442996" font-size="8px">6</text>
<text x="131.638153" y="28.301270" textLength="5.329997" font-size="8px">Y</text>
<text x="11.158630" y="26.741394" textLength="5.769502" font-size="8px">C</text>
<text x="136.917816" y="28.301270" textLength="4.442996" font-size="8px">1</text>
<text x="19.377792" y="11.020142" textLength="3.887607" font-size="8px">5</text>
<text x="266.340027" y="89.380493" textLength="4.442996" font-size="8px">2</text>
<text x="285.660034" y="89.380493" textLength="4.442996" font-size="8px">2</text>
<text x="308.879425" y="11.620056" textLength="3.887607" font-size="8px">3</text>
<text x="143.223480" y="89.620972" textLength="4.882501" font-size="8px">T</text>
<text x="239.758759" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="222.716400" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="311.039276" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="293.997711" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="203.457275" y="27.101013" textLength="5.329997" font-size="8px">X</text>
<text x="144.479034" y="72.219879" textLength="3.887607" font-size="8px">2</text>
<text x="177.660858" y="89.380493" textLength="4.442996" font-size="8px">7</text>
<text x="161.099274" y="10.180420" textLength="3.887607" font-size="8px">0</text>
<text x="112.379028" y="28.301270" textLength="5.329997" font-size="8px">Y</text>
<text x="299.338104" y="27.101013" textLength="4.442996" font-size="8px">1</text>
<text x="154.020142" y="28.301270" textLength="4.442996" font-size="8px">0</text>
<text x="179.099762" y="11.380249" textLength="3.887607" font-size="8px">2</text>
<text x="195.239319" y="89.380493" textLength="4.442996" font-size="8px">6</text>
<text x="312.778229" y="11.620056" textLength="3.887607" font-size="8px">1</text>
</svg>
<figcaption>Figure 4-21.  256-bit VPUNPCKHDQ Instruction Operation
</figcaption></figure>
```


When the source data comes from a 64-bit memory operand, the full 64-bit operand is accessed from memory, but the instruction uses only the high-order 32 bits. When the source data comes from a 128-bit memory operand, an implementation may fetch only the appropriate 64 bits; however, alignment to a 16-byte boundary and normal segment checking will still be enforced.

The (V)PUNPCKHBW instruction interleaves the high-order bytes of the source and destination operands, the (V)PUNPCKHWD instruction interleaves the high-order words of the source and destination operands, the (V)PUNPCKHDQ instruction interleaves the high-order doubleword (or doublewords) of the source and destination operands, and the (V)PUNPCKHQDQ instruction interleaves the high-order quadwords of the source and destina-tion operands.

These instructions can be used to convert bytes to words, words to doublewords, doublewords to quadwords, and quadwords to double quadwords, respectively, by placing all 0s in the source operand. Here, if the source operand contains all 0s, the result (stored in the destination operand) contains zero extensions of the high-order data elements from the original value in the destination operand. For example, with the (V)PUNPCKHBW instruction the high-order bytes are zero extended (that is, unpacked into unsigned word integers), and with the (V)PUNPCKHWD instruction, the high-order words are zero extended (unpacked into unsigned doubleword integers).

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE versions 64-bit operand: The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an MMX technology register.

128-bit Legacy SSE versions: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded versions: The second source operand is an XMM register or a 128-bit memory location. The first source operand and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The second source operand is an YMM register or an 256-bit memory location. The first source operand and destination operands are YMM registers. 



EVEX encoded VPUNPCKHDQ/QDQ: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32/64-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is conditionally updated with writemask k1.

EVEX encoded VPUNPCKHWD/BW: The second source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is conditionally updated with writemask k1.


### Operation
#### PUNPCKHBW instruction with 64-bit operands:
```info-verb
    DEST[7:0] <- DEST[39:32];
    DEST[15:8] <- SRC[39:32];
    DEST[23:16] <- DEST[47:40];
    DEST[31:24] <- SRC[47:40];
    DEST[39:32] <- DEST[55:48];
    DEST[47:40] <- SRC[55:48];
    DEST[55:48] <- DEST[63:56];
    DEST[63:56] <- SRC[63:56];
```
#### PUNPCKHW instruction with 64-bit operands:
```info-verb
    DEST[15:0] <- DEST[47:32]; 
    DEST[31:16] <- SRC[47:32];
    DEST[47:32] <- DEST[63:48];
    DEST[63:48] <- SRC[63:48];
```
#### PUNPCKHDQ instruction with 64-bit operands:
```info-verb
    DEST[31:0] <- DEST[63:32];
    DEST[63:32] <- SRC[63:32];
INTERLEAVE_HIGH_BYTES_512b (SRC1, SRC2)
TMP_DEST[255:0] <-   INTERLEAVE_HIGH_BYTES_256b(SRC1[255:0], SRC[255:0])
TMP_DEST[511:256]  <-  INTERLEAVE_HIGH_BYTES_256b(SRC1[511:256], SRC[511:256])
INTERLEAVE_HIGH_BYTES_256b (SRC1, SRC2) 
DEST[7:0]  <-  SRC1[71:64]
DEST[15:8]  <-  SRC2[71:64]
DEST[23:16] <-   SRC1[79:72]
DEST[31:24]  <-  SRC2[79:72]
DEST[39:32]  <-  SRC1[87:80]
DEST[47:40] <-   SRC2[87:80]
DEST[55:48]  <-  SRC1[95:88]
DEST[63:56] <-   SRC2[95:88]
DEST[71:64] <-   SRC1[103:96]
DEST[79:72] <-   SRC2[103:96]
DEST[87:80] <-   SRC1[111:104]
DEST[95:88]  <-  SRC2[111:104]
DEST[103:96]  <-  SRC1[119:112]
DEST[111:104]  <-  SRC2[119:112]
DEST[119:112] <-   SRC1[127:120]
DEST[127:120] <-   SRC2[127:120]
DEST[135:128] <-   SRC1[199:192]
DEST[143:136] <-   SRC2[199:192]
DEST[151:144]  <-  SRC1[207:200]
DEST[159:152]  <-  SRC2[207:200]
DEST[167:160] <-   SRC1[215:208]
DEST[175:168]  <-  SRC2[215:208]
DEST[183:176]  <-  SRC1[223:216]
DEST[191:184]  <-  SRC2[223:216]
DEST[199:192] <-   SRC1[231:224]
DEST[207:200] <-   SRC2[231:224]
DEST[215:208]  <-  SRC1[239:232]
DEST[223:216]  <-  SRC2[239:232]
DEST[231:224]  <-  SRC1[247:240]
DEST[239:232] <-   SRC2[247:240]
DEST[247:240] <-   SRC1[255:248]
DEST[255:248]  <-  SRC2[255:248]
INTERLEAVE_HIGH_BYTES (SRC1, SRC2) 
DEST[7:0] <-   SRC1[71:64]
DEST[15:8]  <-  SRC2[71:64]
DEST[23:16]  <-  SRC1[79:72]
DEST[31:24]  <-  SRC2[79:72]
DEST[39:32] <-   SRC1[87:80]
DEST[47:40] <-   SRC2[87:80]
DEST[55:48] <-   SRC1[95:88]
DEST[63:56]  <-  SRC2[95:88]
DEST[71:64] <-   SRC1[103:96]
DEST[79:72]  <-  SRC2[103:96]
DEST[87:80]  <-  SRC1[111:104]
DEST[95:88] <-   SRC2[111:104]
DEST[103:96] <-   SRC1[119:112]
DEST[111:104]  <-  SRC2[119:112]
DEST[119:112]  <-  SRC1[127:120]
DEST[127:120] <-   SRC2[127:120]
INTERLEAVE_HIGH_WORDS_512b (SRC1, SRC2)
TMP_DEST[255:0] <-   INTERLEAVE_HIGH_WORDS_256b(SRC1[255:0], SRC[255:0])
TMP_DEST[511:256]  <-  INTERLEAVE_HIGH_WORDS_256b(SRC1[511:256], SRC[511:256])
INTERLEAVE_HIGH_WORDS_256b(SRC1, SRC2)
DEST[15:0] <-   SRC1[79:64]
DEST[31:16]  <-  SRC2[79:64]
DEST[47:32] <-   SRC1[95:80]
DEST[63:48]  <-  SRC2[95:80]
DEST[79:64]  <-  SRC1[111:96]
DEST[95:80]  <-  SRC2[111:96]
DEST[111:96] <-   SRC1[127:112]
DEST[127:112] <-   SRC2[127:112]
DEST[143:128] <-   SRC1[207:192]
DEST[159:144]  <-  SRC2[207:192]
DEST[175:160]  <-  SRC1[223:208]
DEST[191:176]  <-  SRC2[223:208]
DEST[207:192] <-   SRC1[239:224]
DEST[223:208] <-   SRC2[239:224]
DEST[239:224] <-   SRC1[255:240]
DEST[255:240] <-   SRC2[255:240]
INTERLEAVE_HIGH_WORDS (SRC1, SRC2)
DEST[15:0] <-   SRC1[79:64]
DEST[31:16] <-   SRC2[79:64]
DEST[47:32]  <-  SRC1[95:80]
DEST[63:48]  <-  SRC2[95:80]
DEST[79:64]  <-  SRC1[111:96]
DEST[95:80] <-   SRC2[111:96]
DEST[111:96]  <-  SRC1[127:112]
DEST[127:112]  <-  SRC2[127:112]
INTERLEAVE_HIGH_DWORDS_512b (SRC1, SRC2)
TMP_DEST[255:0] <-   INTERLEAVE_HIGH_DWORDS_256b(SRC1[255:0], SRC2[255:0])
TMP_DEST[511:256]  <-  INTERLEAVE_HIGH_DWORDS_256b(SRC1[511:256], SRC2[511:256])
INTERLEAVE_HIGH_DWORDS_256b(SRC1, SRC2)
DEST[31:0] <-   SRC1[95:64]
DEST[63:32] <-   SRC2[95:64]
DEST[95:64]  <-  SRC1[127:96]
DEST[127:96]  <-  SRC2[127:96]
DEST[159:128]  <-  SRC1[223:192]
DEST[191:160]  <-  SRC2[223:192]
DEST[223:192] <-   SRC1[255:224]
DEST[255:224] <-   SRC2[255:224]
INTERLEAVE_HIGH_DWORDS(SRC1, SRC2)
DEST[31:0] <-   SRC1[95:64]
DEST[63:32]  <-  SRC2[95:64]
DEST[95:64]  <-  SRC1[127:96]
DEST[127:96] <-   SRC2[127:96]
INTERLEAVE_HIGH_QWORDS_512b (SRC1, SRC2)
TMP_DEST[255:0]  <-  INTERLEAVE_HIGH_QWORDS_256b(SRC1[255:0], SRC2[255:0])
TMP_DEST[511:256] <-   INTERLEAVE_HIGH_QWORDS_256b(SRC1[511:256], SRC2[511:256])
INTERLEAVE_HIGH_QWORDS_256b(SRC1, SRC2)
DEST[63:0]  <-  SRC1[127:64]
DEST[127:64]  <-  SRC2[127:64]
DEST[191:128] <-   SRC1[255:192]
DEST[255:192] <-   SRC2[255:192]
INTERLEAVE_HIGH_QWORDS(SRC1, SRC2)
DEST[63:0] <-   SRC1[127:64]
DEST[127:64]  <-  SRC2[127:64]
```
#### PUNPCKHBW (128-bit Legacy SSE Version)
```info-verb
DEST[127:0] <-  INTERLEAVE_HIGH_BYTES(DEST, SRC)
DEST[255:127] (Unmodified)
```
#### VPUNPCKHBW (VEX.128 encoded version)
```info-verb
DEST[127:0] <-  INTERLEAVE_HIGH_BYTES(SRC1, SRC2)
DEST[511:127]  <- 0
```
#### VPUNPCKHBW (VEX.256 encoded version)
```info-verb
DEST[255:0]  <- INTERLEAVE_HIGH_BYTES_256b(SRC1, SRC2)
DEST[MAX_VL-1:256]  <- 0
```
#### VPUNPCKHBW (EVEX encoded versions)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
IF VL = 128
    TMP_DEST[VL-1:0]  <-  INTERLEAVE_HIGH_BYTES(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0] <-   INTERLEAVE_HIGH_BYTES_256b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0]  <-  INTERLEAVE_HIGH_BYTES_512b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
FOR j <-   0 TO KL-1
    i <-   j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-   TMP_DEST[i+7:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+7:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### PUNPCKHWD (128-bit Legacy SSE Version)
```info-verb
DEST[127:0] <-  INTERLEAVE_HIGH_WORDS(DEST, SRC)
DEST[255:127] (Unmodified)
```
#### VPUNPCKHWD (VEX.128 encoded version)
```info-verb
DEST[127:0] <-  INTERLEAVE_HIGH_WORDS(SRC1, SRC2)
DEST[511:127] <-  0
```
#### VPUNPCKHWD (VEX.256 encoded version)
```info-verb
DEST[255:0] <-  INTERLEAVE_HIGH_WORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <-  0
VPUNPCKHWD (EVEX encoded versions)
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[VL-1:0]  <-  INTERLEAVE_HIGH_WORDS(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0] <-   INTERLEAVE_HIGH_WORDS_256b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0]  <-  INTERLEAVE_HIGH_WORDS_512b(SRC1[VL-1:0], SRC2[VL-1:0])
FI;
FOR j <-   0 TO KL-1
    i <-   j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-   TMP_DEST[i+15:i]
ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### PUNPCKHDQ (128-bit LegacySSE Version)
```info-verb
DEST[127:0] <-  INTERLEAVE_HIGH_DWORDS(DEST, SRC)
DEST[255:127] (Unmodified)
```
#### VPUNPCKHDQ (VEX.128 encoded version)
```info-verb
DEST[127:0] <-  INTERLEAVE_HIGH_DWORDS(SRC1, SRC2)
DEST[511:127] <-  0
```
#### VPUNPCKHDQ (VEX.256 encoded version)
```info-verb
DEST[255:0]  <- INTERLEAVE_HIGH_DWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256]  <- 0
```
#### VPUNPCKHDQ (EVEX.512 encoded version)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <-  0 TO KL-1
    i <-   j * 32
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+31:i] <-   SRC2[31:0]
          ELSE TMP_SRC2[i+31:i] <-   SRC2[i+31:i]
    FI;
ENDFOR;
IF VL = 128
    TMP_DEST[VL-1:0] <-   INTERLEAVE_HIGH_DWORDS(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0]  <-  INTERLEAVE_HIGH_DWORDS_256b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0] <-   INTERLEAVE_HIGH_DWORDS_512b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
FOR j  <-  0 TO KL-1
    i  <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i]  <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i] <-   0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### PUNPCKHQDQ (128-bit Legacy SSE Version)
```info-verb
DEST[127:0]  <- INTERLEAVE_HIGH_QWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPUNPCKHQDQ (VEX.128 encoded version)
```info-verb
DEST[127:0]  <- INTERLEAVE_HIGH_QWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <-  0
```
#### VPUNPCKHQDQ (VEX.256 encoded version)
```info-verb
DEST[255:0] <-  INTERLEAVE_HIGH_QWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256]  <- 0
```
#### VPUNPCKHQDQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j  <-  0 TO KL-1
    i <-   j * 64
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+63:i] <-   SRC2[63:0]
          ELSE TMP_SRC2[i+63:i]  <-  SRC2[i+63:i]
    FI;
ENDFOR;
IF VL = 128
    TMP_DEST[VL-1:0] <-   INTERLEAVE_HIGH_QWORDS(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 256
    TMP_DEST[VL-1:0]  <-  INTERLEAVE_HIGH_QWORDS_256b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
IF VL = 512
    TMP_DEST[VL-1:0] <-   INTERLEAVE_HIGH_QWORDS_512b(SRC1[VL-1:0], TMP_SRC2[VL-1:0])
FI;
FOR j  <-  0 TO KL-1
    i <-   j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-   TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i] <-   0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPUNPCKHBW __m512i _mm512_unpackhi_epi8(__m512i a, __m512i b);
VPUNPCKHBW __m512i _mm512_mask_unpackhi_epi8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPUNPCKHBW __m512i _mm512_maskz_unpackhi_epi8( __mmask64 k, __m512i a, __m512i b);
VPUNPCKHBW __m256i _mm256_mask_unpackhi_epi8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPUNPCKHBW __m256i _mm256_maskz_unpackhi_epi8( __mmask32 k, __m256i a, __m256i b);
VPUNPCKHBW __m128i _mm_mask_unpackhi_epi8(v s, __mmask16 k, __m128i a, __m128i b);
VPUNPCKHBW __m128i _mm_maskz_unpackhi_epi8( __mmask16 k, __m128i a, __m128i b);
VPUNPCKHWD __m512i _mm512_unpackhi_epi16(__m512i a, __m512i b);
VPUNPCKHWD __m512i _mm512_mask_unpackhi_epi16(__m512i s, __mmask32 k, __m512i a, __m512i b);
VPUNPCKHWD __m512i _mm512_maskz_unpackhi_epi16( __mmask32 k, __m512i a, __m512i b);
VPUNPCKHWD __m256i _mm256_mask_unpackhi_epi16(__m256i s, __mmask16 k, __m256i a, __m256i b);
VPUNPCKHWD __m256i _mm256_maskz_unpackhi_epi16( __mmask16 k, __m256i a, __m256i b);
VPUNPCKHWD __m128i _mm_mask_unpackhi_epi16(v s, __mmask8 k, __m128i a, __m128i b);
VPUNPCKHWD __m128i _mm_maskz_unpackhi_epi16( __mmask8 k, __m128i a, __m128i b);
VPUNPCKHDQ __m512i _mm512_unpackhi_epi32(__m512i a, __m512i b);
VPUNPCKHDQ __m512i _mm512_mask_unpackhi_epi32(__m512i s, __mmask16 k, __m512i a, __m512i b);
VPUNPCKHDQ __m512i _mm512_maskz_unpackhi_epi32( __mmask16 k, __m512i a, __m512i b);
VPUNPCKHDQ __m256i _mm256_mask_unpackhi_epi32(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPUNPCKHDQ __m256i _mm256_maskz_unpackhi_epi32( __mmask8 k, __m512i a, __m512i b);
VPUNPCKHDQ __m128i _mm_mask_unpackhi_epi32(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPUNPCKHDQ __m128i _mm_maskz_unpackhi_epi32( __mmask8 k, __m512i a, __m512i b);
VPUNPCKHQDQ __m512i _mm512_unpackhi_epi64(__m512i a, __m512i b);
VPUNPCKHQDQ __m512i _mm512_mask_unpackhi_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPUNPCKHQDQ __m512i _mm512_maskz_unpackhi_epi64( __mmask8 k, __m512i a, __m512i b);
VPUNPCKHQDQ __m256i _mm256_mask_unpackhi_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPUNPCKHQDQ __m256i _mm256_maskz_unpackhi_epi64( __mmask8 k, __m512i a, __m512i b);
VPUNPCKHQDQ __m128i _mm_mask_unpackhi_epi64(__m512i s, __mmask8 k, __m512i a, __m512i b);
VPUNPCKHQDQ __m128i _mm_maskz_unpackhi_epi64( __mmask8 k, __m512i a, __m512i b);
PUNPCKHBW:__m64 _mm_unpackhi_pi8(__m64 m1, __m64 m2)
(V)PUNPCKHBW:__m128i _mm_unpackhi_epi8(__m128i m1, __m128i m2)
VPUNPCKHBW:__m256i _mm256_unpackhi_epi8(__m256i m1, __m256i m2)
PUNPCKHWD:__m64 _mm_unpackhi_pi16(__m64 m1,__m64 m2)
(V)PUNPCKHWD:__m128i _mm_unpackhi_epi16(__m128i m1,__m128i m2)
VPUNPCKHWD:__m256i _mm256_unpackhi_epi16(__m256i m1,__m256i m2)
PUNPCKHDQ:__m64 _mm_unpackhi_pi32(__m64 m1, __m64 m2)
(V)PUNPCKHDQ:__m128i _mm_unpackhi_epi32(__m128i m1, __m128i m2)
VPUNPCKHDQ:__m256i _mm256_unpackhi_epi32(__m256i m1, __m256i m2)
(V)PUNPCKHQDQ:__m128i _mm_unpackhi_epi64 ( __m128i a, __m128i b)
VPUNPCKHQDQ:__m256i _mm256_unpackhi_epi64 ( __m256i a, __m256i b)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded VPUNPCKHQDQ/QDQ, see Exceptions Type E4NF.

EVEX-encoded VPUNPCKHBW/WD, see Exceptions Type E4NF.nb.

