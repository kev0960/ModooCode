----------------------------
title : PHADDW, PHADDDs (Intel x86/64 assembly instruction)
cat_title : PHADDW, PHADDD
ref_title : PHADDW, PHADDD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PHADDW, PHADDD

** Packed Horizontal Add**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 01 /r\footnote{1}  `\newline{}`PHADDW` mm1 mm2/m64 |RM|V/V|SSSE3|Add 16-bit integers horizontally, pack to mm1. |
|`66 0F 38 01 /r`\newline{}`PHADDW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Add 16-bit integers horizontally, pack to xmm1.|
|`0F 38 02 /r `\newline{}`PHADDD` mm1 mm2/m64 |RM|V/V|SSSE3|Add 32-bit integers horizontally, pack to mm1. |
|`66 0F 38 02 /r`\newline{}`PHADDD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Add 32-bit integers horizontally, pack to xmm1. |
|`VEX.NDS.128.66.0F38.WIG 01 /r`\newline{}VPHADDW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Add 16-bit integers horizontally, pack to xmm1.|
|`VEX.NDS.128.66.0F38.WIG 02 /r`\newline{}VPHADDD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Add 32-bit integers horizontally, pack to xmm1.|
|`VEX.NDS.256.66.0F38.WIG 01 /r`\newline{}VPHADDW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Add 16-bit signed integers horizontally, pack to ymm1.|
|`VEX.NDS.256.66.0F38.WIG 02 /r`\newline{}VPHADDD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Add 32-bit signed integers horizontally, pack to ymm1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


(V)PHADDW adds two adjacent 16-bit signed integers horizontally from the source and destination operands and packs the 16-bit signed results to the destination operand (first operand). (V)PHADDD adds two adjacent 32-bit signed integers horizontally from the source and destination operands and packs the 32-bit signed results to the destination operand (first operand). When the source operand is a 128-bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated.

Note that these instructions can operate on either unsigned or signed (two's complement notation) integers; however, it does not set bits in the EFLAGS register to indicate overflow and/or a carry. To prevent undetected over-flow conditions, software must control the ranges of the values operated on. 

Legacy SSE instructions: Both operands can be MMX registers. The second source operand can be an MMX register or a 64-bit memory location.

128-bit Legacy SSE version: The first source and destination operands are XMM registers. The second source operand can be an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

In 64-bit mode, use the REX prefix to access additional registers. 



VEX.128 encoded version: The first source and destination operands are XMM registers. The second source operand can be an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM register are zeroed.

VEX.256 encoded version: Horizontal addition of two adjacent data elements of the low 16-bytes of the first and second source operands are packed into the low 16-bytes of the destination operand. Horizontal addition of two adjacent data elements of the high 16-bytes of the first and second source operands are packed into the high 16-bytes of the destination operand. The first source and destination operands are YMM registers. The second source operand can be an YMM register or a 256-bit memory location. 

Note: VEX.L must be 0, otherwise the instruction will #UD.

```embed
<figure>
<svg viewBox="0 0 343.161682 193.880005">
<rect x="173.758408" y="10.000000" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="173.758408" y="9.760071" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="317.518433" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.518417" y="27.760071" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.518417" y="9.760010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="209.338394" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="209.338394" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.398422" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.398422" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="281.458435" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="281.458435" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="299.518433" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="299.518433" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="227.518417" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="227.518417" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.518433" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.518433" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.518417" y="9.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.518417" y="10.000061" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="21.718414" y="10.059998" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="21.718414" y="9.820068" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.478409" y="10.060059" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="21.478409" y="27.820068" width="144.240005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="21.478409" y="9.820007" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.298416" y="9.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="57.298416" y="10.060059" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.358414" y="9.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.358414" y="10.060059" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.418411" y="9.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.418411" y="10.060059" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="147.478409" y="9.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="147.478409" y="10.060059" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.478409" y="9.820007" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.478409" y="10.060059" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="111.478409" y="9.820007" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="111.478409" y="10.060059" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="39.478409" y="9.820007" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="39.478409" y="10.060059" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.298416,53.260010 L185.818405,53.380005 L186.178421,54.340027 L186.658401,54.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.118423,53.860046 L187.378433,52.840027 L188.158432,52.240051 L188.218430,53.260071 L188.458420,58.900024 L188.518417,60.640076 L187.498428,59.200073 L184.318436,54.580017 L183.778427,53.800049 L184.678421,53.800049 L185.158432,54.040039 L188.338425,58.660034 L187.498428,59.200073 L187.438431,58.960022 L187.198410,53.320068 L188.218430,53.260071 L187.978409,53.680054 L186.718430,54.700073" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M184.678421,53.800049 L186.358414,53.800049 L186.718430,54.700073 L186.598434,54.820068 L184.738419,54.820068" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.418411,54.280029 L187.678421,53.260010 L187.918411,58.900024 L184.738419,54.280029" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.078415,28.540039 L178.018417,28.300049 L177.538406,28.480042 L177.598404,28.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.298416,53.260010 L186.358414,53.500000 L185.878403,53.679993 L185.818405,53.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M178.078415,28.540039 L177.598404,28.720032 L185.818405,53.440063 L186.298416,53.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.838379,53.260010 L297.358398,53.380005 L297.718384,54.400024 L298.198364,54.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.658386,53.920044 L298.918396,52.840027 L299.638428,52.180054 L299.758423,53.260071 L300.058411,58.900024 L300.118408,60.640015 L299.098389,59.200073 L295.918396,54.580017 L295.318420,53.740051 L296.338379,53.740051 L296.758423,54.040039 L299.938416,58.660034 L299.098389,59.200073 L299.038391,58.960022 L298.738403,53.320068 L299.758423,53.260071 L299.518372,53.680054 L298.258423,54.760071" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.338379,53.740051 L297.958374,53.800049 L298.258423,54.760071 L298.138367,54.880066 L297.958374,54.880066 L296.338379,54.820068" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.958435,54.340027 L299.218445,53.260010 L299.518433,58.900024 L296.338440,54.280029" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M290.158386,30.520020 L290.098389,30.280029 L289.618408,30.460022 L289.678406,30.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.838379,53.260010 L297.898376,53.500000 L297.418396,53.679993 L297.358398,53.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M290.158386,30.520020 L289.678406,30.700012 L297.358398,53.440002 L297.838379,53.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.078430,53.680054 L306.598389,53.560059 L306.418396,54.580078 L306.898438,54.700073" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.538391,54.160034 L308.158386,53.920044 L309.178406,53.680054 L308.698425,54.640015 L306.238403,59.620056 L305.518433,61.180054 L305.338379,59.500061 L304.738403,53.980042 L304.558411,52.960022 L305.398376,53.380005 L305.698425,53.800049 L306.298401,59.320007 L305.338379,59.500061 L305.338379,59.200012 L307.798401,54.220032 L308.698425,54.640015 L308.338379,54.880005 L306.718384,55.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M305.398438,53.380005 L306.838440,54.160034 L306.718445,55.119995 L306.538452,55.179993 L306.418396,55.059998 L304.978394,54.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.658386,54.640015 L308.278381,54.400024 L305.818420,59.380005 L305.218384,53.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M311.278381,29.860046 L311.278381,29.620056 L310.798401,29.560059 L310.798401,29.800049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.078430,53.680054 L307.078430,53.920044 L306.598389,53.860046 L306.598389,53.620056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M311.278381,29.860046 L310.798401,29.800049 L306.598389,53.620056 L307.078369,53.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.778381,52.900024 L264.298401,52.780029 L263.878418,53.740051 L264.358398,53.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.118408,53.260010 L265.798401,53.320007 L266.818420,53.380005 L266.158447,54.220032 L262.738403,58.660034 L261.718445,60.040039 L261.838440,58.299988 L262.378418,52.720032 L262.498413,51.640015 L263.278442,52.359985 L263.398438,52.780029 L262.858398,58.359985 L261.838440,58.299988 L261.958435,58.000000 L265.378418,53.559998 L266.158447,54.220032 L265.798401,54.400024 L264.118408,54.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.278381,52.360046 L264.478394,53.440063 L264.118408,54.340027 L263.938416,54.280029 L263.758423,54.160034 L262.558411,53.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.118408,53.800049 L265.798401,53.860046 L262.378418,58.300049 L262.918396,52.720032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.078430,29.320007 L274.138428,29.140015 L273.718445,28.960022 L273.658386,29.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.778381,52.960022 L264.718384,53.140015 L264.298401,52.960022 L264.358398,52.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.078430,29.320007 L273.658386,29.140015 L264.358398,52.780029 L264.778442,52.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.638412,50.920044 L152.158401,50.800049 L151.858414,51.820068 L152.338425,51.940063" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.098404,51.340027 L153.718399,51.280029 L154.738419,51.220032 L154.138412,52.120056 L151.078415,56.740051 L150.118393,58.180054 L150.118393,56.440002 L150.238419,50.860046 L150.298416,49.840027 L151.078415,50.440002 L151.258408,50.920044 L151.138412,56.500000 L150.118393,56.440002 L150.238419,56.200012 L153.298416,51.580017 L154.138412,52.120056 L153.718399,52.360046 L152.098404,52.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.078415,50.440002 L152.398422,51.460022 L152.098404,52.419983 L151.918411,52.419983 L151.798416,52.299988 L150.478409,51.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.098404,51.880005 L153.718399,51.820007 L150.658401,56.440002 L150.778397,50.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M159.478409,29.440002 L159.538406,29.200012 L159.058395,29.080017 L158.998398,29.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.638412,50.920044 L152.578415,51.160034 L152.098404,51.040039 L152.158401,50.800049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M159.478409,29.440002 L158.998398,29.320007 L152.158401,50.799988 L152.638412,50.919983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.638412,54.340027 L116.158417,54.220032 L115.918411,55.240051 L116.398407,55.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.098404,54.820007 L117.718399,54.640015 L118.738403,54.460022 L118.198410,55.419983 L115.498398,60.340027 L114.658401,61.840027 L114.598404,60.100037 L114.298401,54.520020 L114.178406,53.500000 L115.018402,54.039978 L115.258408,54.460022 L115.558411,60.039978 L114.598404,60.100037 L114.658401,59.799988 L117.358398,54.880005 L118.198410,55.419983 L117.838409,55.600037 L116.218399,55.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.018402,54.040039 L116.398407,54.880066 L116.218399,55.780029 L116.038406,55.840027 L115.858398,55.720032 L114.478409,54.880066" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.158401,55.300049 L117.778397,55.120056 L115.078400,60.040039 L114.778397,54.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.278412,29.440002 L122.338409,29.200012 L121.858414,29.080017 L121.798416,29.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M116.638412,54.340027 L116.578415,54.580017 L116.098419,54.460022 L116.158417,54.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M122.278412,29.440002 L121.798416,29.320007 L116.158417,54.220032 L116.638412,54.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M40.438416,51.160034 L39.958420,51.280029 L40.138412,52.300049 L40.618408,52.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M40.138412,51.820007 L41.518417,51.039978 L42.358414,50.500000 L42.238419,51.580017 L41.638412,57.100037 L41.458420,58.840027 L40.738419,57.220032 L38.338409,52.239990 L37.918411,51.340027 L38.818405,51.520020 L39.238419,51.820007 L41.638412,56.799988 L40.738419,57.220032 L40.678406,56.919983 L41.278412,51.400024 L42.238419,51.580017 L41.998413,51.880005 L40.618408,52.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M38.818405,51.520020 L40.438400,51.760010 L40.618408,52.660034 L40.498398,52.780029 L40.258408,52.720032 L38.638412,52.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M40.378403,52.240051 L41.758408,51.460022 L41.158401,56.980042 L38.758408,52.000061" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M36.478409,28.600037 L36.478409,28.360046 L35.998413,28.420044 L35.998413,28.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M40.438416,51.220032 L40.438416,51.460022 L39.958420,51.520020 L39.958420,51.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M36.478409,28.600037 L35.998413,28.660034 L39.958405,51.280029 L40.438416,51.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.898407,53.260010 L72.418411,53.380005 L72.778412,54.340027 L73.258408,54.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.718414,53.860046 L73.978409,52.840027 L74.758408,52.240051 L74.818420,53.260071 L75.058411,58.900024 L75.118408,60.640076 L74.098419,59.200073 L70.918411,54.580017 L70.378418,53.800049 L71.278412,53.800049 L71.758408,54.040039 L74.938416,58.660034 L74.098419,59.200073 L74.038422,58.960022 L73.798416,53.320068 L74.818420,53.260071 L74.578415,53.680054 L73.318420,54.700073" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M71.278412,53.800049 L72.958405,53.800049 L73.318405,54.700073 L73.198410,54.820068 L71.338409,54.820068" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M73.018402,54.280029 L74.278397,53.260010 L74.518402,58.900024 L71.338409,54.280029" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.678406,28.540039 L64.618408,28.300049 L64.138412,28.480042 L64.198410,28.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.898407,53.260010 L72.958405,53.500000 L72.478409,53.679993 L72.418411,53.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.678406,28.540039 L64.198410,28.720032 L72.418411,53.440063 L72.898407,53.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="119.098404" y="114.100037" width="144.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="119.098404" y="113.860016" width="144.240005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.858398" y="114.100037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="118.858414" y="131.860016" width="144.240005" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="118.858414" y="113.860046" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.678421" y="113.860016" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.738419" y="113.860016" width="0.479980" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="226.798416" y="113.860016" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.858414" y="113.860016" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.858414" y="113.860016" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.858414" y="113.860016" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="136.858414" y="113.860016" width="0.480010" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.578430,105.040039 L263.218445,104.680054 L262.378418,105.340027 L262.738403,105.700043" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.798401,105.100037 L264.238403,105.940033 L265.138428,106.420044 L264.178406,106.840027 L259.078430,109.120026 L257.458435,109.840027 L258.478394,108.400024 L261.598389,103.720032 L262.138428,102.820038 L262.498413,103.780029 L262.438416,104.260040 L259.318420,108.940033 L258.478394,108.400024 L258.658386,108.220032 L263.758423,105.940033 L264.178406,106.840027 L263.758423,106.780029 L262.318420,105.940033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.498413,103.780029 L263.038391,105.340027 L262.318420,105.940033 L262.138428,105.880035 L262.078369,105.700043 L261.538391,104.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.558411,105.520020 L263.998413,106.360016 L258.898376,108.640015 L262.018372,103.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.018433,73.360046 L301.198425,73.240051 L300.898438,72.880066 L300.718445,73.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.578430,105.040039 L263.398438,105.160034 L263.098389,104.800049 L263.278442,104.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.018433,73.360046 L300.718445,73.000061 L263.278442,104.680054 L263.578430,105.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.318405,107.620026 L211.078415,107.980011 L212.038406,108.520020 L212.278397,108.160034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.678421,108.280029 L211.918411,106.660034 L211.978409,105.580017 L212.818436,106.420044 L216.718430,110.380035 L217.918411,111.580017 L216.238419,111.160034 L210.838425,109.840027 L209.758408,109.600037 L210.598434,108.940033 L211.018417,108.880035 L216.418411,110.200043 L216.238419,111.160034 L215.938431,111.040039 L212.038406,107.080017 L212.818436,106.420044 L212.878433,106.780029 L212.638412,108.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.598404,108.940033 L211.858414,107.920044 L212.638412,108.400024 L212.638412,108.580048 L212.458389,108.760040 L211.198410,109.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M212.158401,108.340027 L212.398392,106.720032 L216.298416,110.680023 L210.898392,109.360016" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.978409,73.840027 L151.798416,73.720032 L151.558395,74.140015 L151.738419,74.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.318405,107.620026 L211.498398,107.740021 L211.258408,108.160034 L211.078415,108.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M151.978409,73.840027 L151.738419,74.260010 L211.078415,108.040039 L211.318405,107.620026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.178421,108.760010 L188.938431,109.119995 L189.838425,109.600006 L190.078415,109.240021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.478409,109.360016 L189.778397,107.800018 L189.898422,106.720001 L190.678421,107.560028 L194.578415,111.580017 L195.778397,112.840027 L194.098404,112.360016 L188.638412,110.980011 L187.558395,110.740021 L188.398422,110.080017 L188.818405,110.020020 L194.278397,111.400024 L194.098404,112.360016 L193.798416,112.240021 L189.898422,108.220001 L190.678421,107.560028 L190.738419,107.920013 L190.438400,109.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.398422,110.080017 L189.658432,109.000031 L190.438431,109.480011 L190.438431,109.720032 L190.258408,109.840027 L188.998428,110.920013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.958420,109.420013 L190.258408,107.860016 L194.158432,111.880005 L188.698410,110.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M120.958405,68.800049 L120.778412,68.680054 L120.538406,69.100037 L120.718399,69.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.178421,108.760010 L189.358414,108.880005 L189.118423,109.300018 L188.938431,109.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M120.958405,68.800049 L120.718399,69.220032 L188.938400,109.180054 L189.178421,108.760040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.738403,107.320038 L118.498398,107.800049 L119.458405,108.280029 L119.698410,107.800049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M119.098404,107.980011 L119.278397,106.360016 L119.278397,105.339996 L120.118408,106.059998 L124.258408,109.839996 L125.578400,111.040009 L123.838409,110.740021 L118.318405,109.660004 L117.298401,109.480011 L118.018402,108.820007 L118.498398,108.700012 L124.018402,109.720001 L123.838409,110.740021 L123.598404,110.559998 L119.458405,106.779999 L120.118408,106.059998 L120.238403,106.480011 L120.058411,108.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.018402,108.820038 L119.218399,107.680023 L120.058395,108.100037 L120.058395,108.280029 L119.938400,108.400024 L118.738403,109.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M119.578415,108.040039 L119.758408,106.420044 L123.898422,110.200043 L118.378418,109.180054" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M43.738403,70.000000 L43.558411,69.880005 L43.318405,70.299988 L43.498398,70.419983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.738403,107.380035 L118.918396,107.500031 L118.678406,107.920044 L118.498398,107.800049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M43.738403,70.000000 L43.498398,70.419983 L118.498398,107.799988 L118.738403,107.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.998413,54.220032 L257.518372,54.340027 L257.698425,55.360046 L258.178406,55.240051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.638428,54.880005 L259.018433,54.039978 L259.918396,53.440002 L259.798401,54.520020 L259.438416,60.099976 L259.318420,61.840027 L258.538391,60.340027 L255.898422,55.359985 L255.358414,54.400024 L256.378418,54.580017 L256.738403,54.820007 L259.378418,59.799988 L258.538391,60.340027 L258.478394,60.039978 L258.838440,54.460022 L259.798401,54.520020 L259.618408,54.880005 L258.238403,55.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.378418,54.580017 L257.998413,54.820007 L258.238403,55.720032 L258.058411,55.840027 L257.878418,55.780029 L256.258423,55.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.938416,55.300049 L259.318420,54.460022 L258.958374,60.040039 L256.318420,55.060059" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.718399,28.720032 L252.658401,28.480042 L252.178391,28.600037 L252.238388,28.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.998413,54.220032 L258.058411,54.460022 L257.578369,54.580017 L257.518372,54.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.718399,28.720032 L252.238388,28.840027 L257.518372,54.340027 L257.998413,54.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.478409,51.400024 L224.998398,51.580017 L225.358414,52.540039 L225.838394,52.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.298416,52.000000 L226.558426,51.039978 L227.338425,50.380005 L227.398422,51.520020 L227.518417,57.099976 L227.518417,58.780029 L226.558426,57.340027 L223.498428,52.659973 L222.958420,51.820007 L223.978409,51.820007 L224.338425,52.119995 L227.398422,56.799988 L226.558426,57.340027 L226.498428,57.039978 L226.378403,51.460022 L227.398422,51.520020 L227.158401,51.880005 L225.898422,52.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.978409,51.820007 L225.658401,51.880005 L225.898422,52.840027 L225.778397,52.960022 L225.538406,52.960022 L223.858414,52.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.598404,52.420044 L226.858414,51.460022 L226.978409,57.040039 L223.918411,52.360046" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M218.698410,28.960022 L218.638412,28.720032 L218.158401,28.840027 L218.218399,29.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.478409,51.400024 L225.538406,51.640015 L225.058395,51.760010 L224.998398,51.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M218.698410,28.960022 L218.218399,29.080017 L224.998398,51.520020 L225.478409,51.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M233.398422,50.680054 L232.918411,50.560059 L232.678421,51.640076 L233.158432,51.760071" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M232.858414,51.220032 L234.478409,50.920044 L235.498428,50.680054 L234.958420,51.640015 L231.658401,58.240051 L231.538406,56.500061 L231.058426,50.920044 L230.938400,49.900024 L231.778427,50.440002 L232.018417,50.860046 L232.498428,56.440002 L231.538406,56.500061 L231.598404,56.260010 L234.118423,51.220032 L234.958420,51.640015 L234.598404,51.880005 L232.978409,52.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.778397,50.440002 L233.158401,51.280029 L232.978409,52.179993 L232.798386,52.239990 L232.678391,52.119995 L231.298386,51.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M232.918411,51.700012 L234.538406,51.400024 L232.018417,56.440002 L231.538406,50.859985" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.478409,29.260010 L237.478409,29.020020 L236.998398,28.960022 L236.998398,29.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M233.398422,50.680054 L233.398422,50.920044 L232.918411,50.860046 L232.918411,50.620056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.478409,29.260010 L236.998398,29.200012 L232.918411,50.619995 L233.398422,50.679993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.838394,52.420044 L195.358383,52.300049 L195.178391,53.380066 L195.658401,53.500061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.298416,52.960022 L196.918411,52.600037 L197.938431,52.300049 L197.458420,53.320007 L195.178421,58.420044 L194.518417,60.040039 L194.278427,58.300049 L193.498428,52.780029 L193.318405,51.700012 L194.218430,52.240051 L194.458420,52.600037 L195.238419,58.119995 L194.278427,58.300049 L194.278427,58.000000 L196.558426,52.900024 L197.458420,53.320007 L197.158401,53.559998 L195.538406,53.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.218399,52.240051 L195.658401,53.020081 L195.538406,53.920044 L195.358414,53.980042 L195.178391,53.860046 L193.738388,53.080078" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.418411,53.440002 L197.038406,53.080017 L194.758408,58.179993 L193.978409,52.659973" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.318405,28.240051 L199.318405,28.000061 L198.838394,27.940063 L198.838394,28.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.838394,52.420044 L195.838394,52.660034 L195.358383,52.600037 L195.358383,52.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.318405,28.240051 L198.838394,28.180054 L195.358414,52.360046 L195.838394,52.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.958420,53.020020 L144.478409,53.140015 L144.838425,54.160034 L145.318405,54.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.778397,53.680054 L146.038406,52.660034 L146.818405,52.000061 L146.878403,53.080078 L147.118393,58.660034 L147.178391,60.400024 L146.158401,58.960083 L142.978409,54.340027 L142.378403,53.500061 L143.398392,53.500061 L143.818405,53.800049 L146.998398,58.420044 L146.158401,58.960083 L146.098404,58.720032 L145.858383,53.140076 L146.878403,53.080078 L146.638382,53.500061 L145.378403,54.520081" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M143.398422,53.500000 L145.078415,53.559998 L145.378433,54.520020 L145.258408,54.640015 L145.078415,54.640015 L143.398422,54.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M145.078415,54.100037 L146.338425,53.080017 L146.578415,58.660034 L143.398422,54.040039" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M136.738419,28.360046 L136.678421,28.120056 L136.198410,28.300049 L136.258408,28.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.958420,53.020020 L145.018417,53.260010 L144.538406,53.440002 L144.478409,53.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M136.738419,28.360046 L136.258408,28.540039 L144.478409,53.200073 L144.958420,53.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M109.558411,53.619995 L109.078415,53.739990 L109.438416,54.760010 L109.918411,54.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M109.378403,54.280029 L110.638397,53.260010 L111.418396,52.600037 L111.478409,53.680054 L111.718399,59.260010 L111.778397,61.000000 L110.758408,59.560059 L107.578400,54.940002 L106.978409,54.100037 L107.998398,54.100037 L108.418396,54.400024 L111.598404,59.020020 L110.758408,59.560059 L110.698410,59.320007 L110.458405,53.740051 L111.478409,53.680054 L111.238403,54.100037 L109.978409,55.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.998413,54.100037 L109.678406,54.160034 L109.978409,55.120056 L109.858414,55.240051 L109.678406,55.240051 L107.998413,55.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M109.678406,54.700012 L110.938400,53.679993 L111.178406,59.260010 L107.998413,54.640015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.338409,28.960022 L101.278412,28.720032 L100.798416,28.900024 L100.858414,29.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M109.558411,53.619995 L109.618408,53.859985 L109.138412,54.039978 L109.078415,53.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.338409,28.960022 L100.858414,29.140015 L109.078415,53.800049 L109.558411,53.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M79.618408,53.980042 L79.138412,53.860046 L78.898407,54.880066 L79.378403,55.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M79.078415,54.460022 L80.758408,54.220032 L81.778412,54.040039 L81.238419,55.000000 L78.538422,59.920044 L77.698410,61.360046 L77.638412,59.679993 L77.278412,54.100037 L77.158417,53.020020 L78.058411,53.619995 L78.238419,54.040039 L78.598419,59.619995 L77.638412,59.679993 L77.698410,59.380005 L80.398422,54.460022 L81.238419,55.000000 L80.878418,55.179993 L79.198410,55.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M78.058411,53.619995 L79.438416,54.520020 L79.198410,55.419983 L79.018417,55.479980 L78.838409,55.359985 L77.458405,54.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M79.138412,54.940002 L80.818405,54.700012 L78.118408,59.619995 L77.758408,54.039978" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M85.258408,29.080017 L85.318405,28.840027 L84.838409,28.720032 L84.778412,28.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M79.618408,53.980042 L79.558411,54.220032 L79.078415,54.100037 L79.138412,53.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M85.258408,29.080017 L84.778412,28.960022 L79.138412,53.860046 L79.618408,53.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M46.318405,51.940002 L45.838409,51.820007 L45.658401,52.840027 L46.138412,52.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M45.838409,52.420044 L47.458405,52.180054 L48.478409,51.940063 L47.938416,52.960022 L45.298416,57.940063 L44.518402,59.380066 L44.398407,57.700073 L43.978409,52.120056 L43.858414,51.160034 L44.698410,51.640015 L44.938416,52.060059 L45.358414,57.640015 L44.398407,57.700073 L44.458405,57.400024 L47.098404,52.420044 L47.938416,52.960022 L47.578415,53.140015 L45.958405,53.380066" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M44.698410,51.640015 L46.138412,52.480042 L45.958405,53.380005 L45.778412,53.440002 L45.598404,53.320007 L44.158417,52.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M45.898407,52.900024 L47.518402,52.660034 L44.878403,57.640015 L44.458405,52.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M51.298416,28.660034 L51.358414,28.420044 L50.878418,28.300049 L50.818420,28.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M46.318405,51.940002 L46.258408,52.179993 L45.778412,52.059998 L45.838409,51.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M51.298416,28.660034 L50.818420,28.540039 L45.838409,51.820007 L46.318420,51.940063" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.718399,103.360016 L240.358414,103.120026 L239.818405,104.020020 L240.178391,104.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.118423,103.660034 L241.738419,104.020020 L242.758438,104.140045 L241.918411,104.920044 L237.778427,108.700043 L236.518417,109.780029 L236.998428,108.160034 L238.498428,102.760040 L238.738419,101.740021 L239.398422,102.580048 L239.458420,103.060028 L237.958420,108.400024 L236.998428,108.160034 L237.118423,107.920044 L241.258438,104.140045 L241.918411,104.920044 L241.498428,104.980042 L239.878433,104.620026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.398422,102.580017 L240.418411,103.840027 L239.878433,104.620026 L239.698410,104.620026 L239.578415,104.440002 L238.558426,103.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M239.998398,104.140015 L241.618393,104.500000 L237.478409,108.280029 L238.978409,102.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.318420,73.540039 L259.438416,73.360046 L259.018433,73.120056 L258.898376,73.300049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.778397,103.360016 L240.658401,103.540009 L240.238388,103.300018 L240.358383,103.120026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.318420,73.540039 L258.898376,73.300049 L240.358414,103.120026 L240.778397,103.360046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.958420,106.000031 L186.598434,105.640045 L185.758408,106.360016 L186.118423,106.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.178421,106.120026 L187.618423,106.900024 L188.518417,107.380035 L187.558426,107.800018 L182.458420,110.080017 L180.838425,110.800018 L181.858414,109.360016 L184.978409,104.740021 L185.518417,103.840027 L185.878433,104.800018 L185.818436,105.280029 L182.698410,109.900024 L181.858414,109.360016 L182.038406,109.180023 L187.138412,106.900024 L187.558426,107.800018 L187.138412,107.740021 L185.698410,106.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M185.878403,104.800018 L186.418411,106.360016 L185.698410,106.960022 L185.518417,106.900024 L185.458389,106.720032 L184.918411,105.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M185.938400,106.540039 L187.378403,107.320038 L182.278397,109.600037 L185.398392,104.980042" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.458420,74.380005 L224.638412,74.260010 L224.338425,73.900024 L224.158432,74.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M186.958420,106.000031 L186.778427,106.120026 L186.478409,105.760040 L186.658432,105.640045" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.458420,74.380005 L224.158432,74.020020 L186.658432,105.640015 L186.958420,106.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.678421,104.800018 L169.318436,104.560028 L168.718430,105.460022 L169.078415,105.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.018417,105.100037 L170.578415,105.520050 L171.598404,105.760040 L170.758408,106.420044 L166.438431,109.900024 L165.058426,110.980042 L165.658432,109.360046 L167.458420,104.080048 L167.758408,103.060028 L168.358414,103.900024 L168.418411,104.380035 L166.618423,109.660034 L165.658432,109.360046 L165.838425,109.120026 L170.158432,105.640045 L170.758408,106.420044 L170.338425,106.480042 L168.778427,106.060028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M168.358414,103.900024 L169.318405,105.280029 L168.778427,106.060028 L168.598404,106.000031 L168.478409,105.880035 L167.518417,104.500031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M168.898422,105.580017 L170.458420,106.000031 L166.138412,109.480011 L167.938431,104.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M191.698410,73.360046 L191.818405,73.180054 L191.398422,72.880066 L191.278397,73.060059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M169.738419,104.860016 L169.618423,105.040009 L169.198410,104.740021 L169.318405,104.560028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M191.698410,73.360046 L191.278397,73.060059 L169.318405,104.560059 L169.738419,104.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.498398,107.320038 L139.258408,107.680023 L140.158401,108.220032 L140.398392,107.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.798416,107.920013 L140.158401,106.360016 L140.278427,105.340027 L141.058426,106.180023 L144.778427,110.320007 L145.918411,111.580017 L144.238419,111.100006 L138.838425,109.540009 L137.818405,109.300018 L138.658401,108.640015 L139.138412,108.580017 L144.538406,110.140015 L144.238419,111.100006 L143.998428,110.980011 L140.278427,106.840027 L141.058426,106.180023 L141.118423,106.600006 L140.758408,108.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.658401,108.640015 L139.978409,107.620026 L140.758408,108.160004 L140.758408,108.340027 L140.578415,108.460022 L139.258408,109.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M140.278397,108.040039 L140.638382,106.480042 L144.358383,110.620026 L138.958389,109.060028" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M82.378403,71.440002 L82.198410,71.320007 L81.958405,71.739990 L82.138397,71.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M139.498398,107.320038 L139.678391,107.440033 L139.438400,107.860046 L139.258408,107.740051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M82.378403,71.440002 L82.138397,71.859985 L139.258408,107.739990 L139.498398,107.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="113.338104" y="70.599976" textLength="4.442996" font-size="8px">3</text>
<text x="108.058456" y="70.599976" textLength="5.329997" font-size="8px">S</text>
<text x="262.376709" y="70.599976" textLength="4.442996" font-size="8px">1</text>
<text x="257.036316" y="70.599976" textLength="5.329997" font-size="8px">S</text>
<text x="223.857651" y="70.599976" textLength="5.329997" font-size="8px">S</text>
<text x="114.012772" y="125.380035" textLength="2.221498" font-size="8px">t</text>
<text x="110.008484" y="125.380035" textLength="3.995500" font-size="8px">s</text>
<text x="296.638733" y="70.599304" textLength="5.329997" font-size="8px">S</text>
<text x="11.158630" y="21.939697" textLength="5.769502" font-size="8px">C</text>
<text x="67.496796" y="22.300110" textLength="4.442996" font-size="8px">5</text>
<text x="62.217148" y="22.300110" textLength="5.329997" font-size="8px">Y</text>
<text x="48.298416" y="22.300110" textLength="4.442996" font-size="8px">6</text>
<text x="42.958023" y="22.300110" textLength="5.329997" font-size="8px">Y</text>
<text x="25.859680" y="22.300110" textLength="5.329997" font-size="8px">Y</text>
<text x="84.599930" y="22.300110" textLength="4.442996" font-size="8px">4</text>
<text x="220.196060" y="21.640076" textLength="4.442996" font-size="8px">5</text>
<text x="200.997665" y="21.640076" textLength="4.442996" font-size="8px">6</text>
<text x="195.657272" y="21.640076" textLength="5.329997" font-size="8px">X</text>
<text x="183.838577" y="21.640076" textLength="4.442996" font-size="8px">7</text>
<text x="178.558914" y="21.640076" textLength="5.329997" font-size="8px">X</text>
<text x="231.958755" y="21.640076" textLength="5.329997" font-size="8px">X</text>
<text x="139.378220" y="22.900269" textLength="4.442996" font-size="8px">1</text>
<text x="120.119095" y="22.900269" textLength="4.442996" font-size="8px">2</text>
<text x="114.778702" y="22.900269" textLength="5.329997" font-size="8px">Y</text>
<text x="97.679565" y="22.900269" textLength="5.329997" font-size="8px">Y</text>
<text x="286.196838" y="21.700012" textLength="5.329997" font-size="8px">X</text>
<text x="272.278137" y="21.700012" textLength="4.442996" font-size="8px">2</text>
<text x="266.937744" y="21.700012" textLength="5.329997" font-size="8px">X</text>
<text x="249.838577" y="21.700012" textLength="5.329997" font-size="8px">X</text>
<text x="303.238403" y="21.700012" textLength="5.329997" font-size="8px">X</text>
<text x="237.299149" y="21.640076" textLength="4.442996" font-size="8px">4</text>
<text x="142.678085" y="70.600159" textLength="5.329997" font-size="8px">S</text>
<text x="99.778412" y="125.380035" textLength="5.769502" font-size="8px">D</text>
<text x="5.359558" y="21.939697" textLength="5.769502" font-size="8px">R</text>
<text x="291.537231" y="21.700012" textLength="4.442996" font-size="8px">1</text>
<text x="332.925232" y="22.120178" textLength="5.769502" font-size="8px">C</text>
<text x="0.000000" y="21.939697" textLength="5.329997" font-size="8px">S</text>
<text x="156.419815" y="22.900269" textLength="4.442996" font-size="8px">0</text>
<text x="79.259537" y="22.300110" textLength="5.329997" font-size="8px">Y</text>
<text x="134.037827" y="22.900269" textLength="5.329997" font-size="8px">Y</text>
<text x="31.139328" y="22.300110" textLength="4.442996" font-size="8px">7</text>
<text x="111.659210" y="108.519653" textLength="4.442996" font-size="8px">2</text>
<text x="229.137314" y="70.599976" textLength="4.442996" font-size="8px">2</text>
<text x="338.718689" y="22.120178" textLength="4.442996" font-size="8px">1</text>
<text x="255.178970" y="21.700012" textLength="4.442996" font-size="8px">3</text>
<text x="71.279068" y="70.599976" textLength="5.329997" font-size="8px">S</text>
<text x="265.078430" y="108.880035" textLength="4.442996" font-size="8px">0</text>
<text x="187.077682" y="70.600159" textLength="5.329997" font-size="8px">S</text>
<text x="327.131714" y="22.120178" textLength="5.769502" font-size="8px">R</text>
<text x="308.578796" y="21.700012" textLength="4.442996" font-size="8px">0</text>
<text x="37.859116" y="70.599976" textLength="5.329997" font-size="8px">S</text>
<text x="116.098206" y="108.519653" textLength="4.442996" font-size="8px">5</text>
<text x="76.619461" y="70.599976" textLength="4.442996" font-size="8px">3</text>
<text x="151.079422" y="22.900269" textLength="5.329997" font-size="8px">Y</text>
<text x="148.018478" y="70.600159" textLength="4.442996" font-size="8px">4</text>
<text x="301.979126" y="70.599304" textLength="4.442996" font-size="8px">0</text>
<text x="105.556702" y="125.380035" textLength="4.442996" font-size="8px">e</text>
<text x="192.418076" y="70.600159" textLength="4.442996" font-size="8px">3</text>
<text x="214.916397" y="21.640076" textLength="5.329997" font-size="8px">X</text>
<text x="321.777771" y="22.120178" textLength="5.329997" font-size="8px">S</text>
<text x="16.857010" y="21.939697" textLength="4.442996" font-size="8px">2</text>
<text x="43.199509" y="70.599976" textLength="4.442996" font-size="8px">7</text>
<text x="120.537201" y="108.519653" textLength="4.442996" font-size="8px">5</text>
<text x="103.019943" y="22.900269" textLength="4.442996" font-size="8px">3</text>
</svg>
<figcaption>Figure 4-10.  256-bit VPHADDD Instruction Operation
</figcaption></figure>
```
### Operation 


**PHADDW (with 64-bit operands)**

    mm1[15-0]  = mm1[31-16] + mm1[15-0]; 

    mm1[31-16] = mm1[63-48] + mm1[47-32]; 

    mm1[47-32] = mm2/m64[31-16] + mm2/m64[15-0]; 

    mm1[63-48] = mm2/m64[63-48] + mm2/m64[47-32]; 

**PHADDW (with 128-bit operands)**

    xmm1[15-0] = xmm1[31-16] + xmm1[15-0]; 

    xmm1[31-16] = xmm1[63-48] + xmm1[47-32]; 

    xmm1[47-32] = xmm1[95-80] + xmm1[79-64]; 

    xmm1[63-48] = xmm1[127-112] + xmm1[111-96]; 

    xmm1[79-64] = xmm2/m128[31-16] + xmm2/m128[15-0]; 

    xmm1[95-80] = xmm2/m128[63-48] + xmm2/m128[47-32]; 

    xmm1[111-96] = xmm2/m128[95-80] + xmm2/m128[79-64]; 

    xmm1[127-112] = xmm2/m128[127-112] + xmm2/m128[111-96]; 

**VPHADDW (VEX.128 encoded version)**

DEST[15:0] <-  SRC1[31:16] + SRC1[15:0]

DEST[31:16] <-  SRC1[63:48] + SRC1[47:32]

DEST[47:32] <-  SRC1[95:80] + SRC1[79:64]

DEST[63:48] <-  SRC1[127:112] + SRC1[111:96]

DEST[79:64] <-  SRC2[31:16] + SRC2[15:0]

DEST[95:80] <-  SRC2[63:48] + SRC2[47:32]

DEST[111:96] <-  SRC2[95:80] + SRC2[79:64]

DEST[127:112] <-  SRC2[127:112] + SRC2[111:96]

DEST[VLMAX-1:128] <-  0



**VPHADDW (VEX.256 encoded version)**

DEST[15:0] <-  SRC1[31:16] + SRC1[15:0]

DEST[31:16] <-  SRC1[63:48] + SRC1[47:32]

DEST[47:32] <-  SRC1[95:80] + SRC1[79:64]

DEST[63:48] <-  SRC1[127:112] + SRC1[111:96]

DEST[79:64] <-  SRC2[31:16] + SRC2[15:0]

DEST[95:80] <-  SRC2[63:48] + SRC2[47:32]

DEST[111:96] <-  SRC2[95:80] + SRC2[79:64]

DEST[127:112] <-  SRC2[127:112] + SRC2[111:96]

DEST[143:128] <-  SRC1[159:144] + SRC1[143:128]

DEST[159:144] <-  SRC1[191:176] + SRC1[175:160]

DEST[175:160] <-  SRC1[223:208] + SRC1[207:192]

DEST[191:176] <-  SRC1[255:240] + SRC1[239:224]

DEST[207:192] <-  SRC2[127:112] + SRC2[143:128]

DEST[223:208] <-  SRC2[159:144] + SRC2[175:160]

DEST[239:224] <-  SRC2[191:176] + SRC2[207:192]

DEST[255:240] <-  SRC2[223:208] + SRC2[239:224]

**PHADDD (with 64-bit operands)**

    mm1[31-0]  = mm1[63-32] + mm1[31-0]; 

    mm1[63-32] = mm2/m64[63-32] + mm2/m64[31-0]; 

**PHADDD (with 128-bit operands)**

    xmm1[31-0] = xmm1[63-32] + xmm1[31-0]; 

    xmm1[63-32] = xmm1[127-96] + xmm1[95-64]; 

    xmm1[95-64] = xmm2/m128[63-32] + xmm2/m128[31-0]; 

    xmm1[127-96] = xmm2/m128[127-96] + xmm2/m128[95-64]; 

**VPHADDD (VEX.128 encoded version)**

DEST[31-0] <-  SRC1[63-32] + SRC1[31-0]

DEST[63-32] <-  SRC1[127-96] + SRC1[95-64]

DEST[95-64] <-  SRC2[63-32] + SRC2[31-0]

DEST[127-96] <-  SRC2[127-96] + SRC2[95-64]

DEST[VLMAX-1:128] <-  0

**VPHADDD (VEX.256 encoded version)**

DEST[31-0] <-  SRC1[63-32] + SRC1[31-0]

DEST[63-32] <-  SRC1[127-96] + SRC1[95-64]

DEST[95-64] <-  SRC2[63-32] + SRC2[31-0]

DEST[127-96] <-  SRC2[127-96] + SRC2[95-64]

DEST[159-128] <-  SRC1[191-160] + SRC1[159-128]

DEST[191-160] <-  SRC1[255-224] + SRC1[223-192]

DEST[223-192] <-  SRC2[191-160] + SRC2[159-128]

DEST[255-224] <-  SRC2[255-224] + SRC2[223-192]


### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
PHADDW: __m64 _mm_hadd_pi16 (__m64 a, __m64 b)
PHADDD: __m64 _mm_hadd_pi32 (__m64 a, __m64 b)
(V)PHADDW: __m128i _mm_hadd_epi16 (__m128i a, __m128i b)
(V)PHADDD: __m128i _mm_hadd_epi32 (__m128i a, __m128i b)
VPHADDW: __m256i _mm256_hadd_epi16 (__m256i a, __m256i b)
VPHADDD: __m256i _mm256_hadd_epi32 (__m256i a, __m256i b)
```
### SIMD Floating-Point Exceptions 


None. 

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1.

