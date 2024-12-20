----------------------------
title : MOVSLDUP (Intel x86/64 assembly instruction)
cat_title : MOVSLDUP
ref_title : MOVSLDUP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVSLDUP

**Replicate Single FP Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 12 /r`\newline{}`MOVSLDUP` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |A|V/V|SSE3|Move even index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.|
|`VEX.128.F3.0F.WIG 12 /r`\newline{}VMOVSLDUP \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Move even index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.|
|`VEX.256.F3.0F.WIG 12 /r`\newline{}VMOVSLDUP \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX|Move even index single-precision floating-point values from ymm2/mem and duplicate each element into ymm1.|
|`EVEX.128.F3.0F.W0 12 /r`\newline{}VMOVSLDUP \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move even index single-precision floating-point values from xmm2/m128 and duplicate each element into xmm1 under writemask.|
|`EVEX.256.F3.0F.W0 12 /r`\newline{}VMOVSLDUP \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move even index single-precision floating-point values from ymm2/m256 and duplicate each element into ymm1 under writemask.|
|`EVEX.512.F3.0F.W0 12 /r`\newline{}VMOVSLDUP zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512F|Move even index single-precision floating-point values from zmm2/m512 and duplicate each element into zmm1 under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FVM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Duplicates even-indexed single-precision floating-point values from the source operand (the second operand). See Figure 4-4. The source operand is an XMM, YMM or ZMM register or 128, 256 or 512-bit memory location and the destination operand is an XMM, YMM or ZMM register.

128-bit Legacy SSE version: Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 encoded version: Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

VEX.256 encoded version: Bits (MAX\esc{_}VL-1:256) of the destination register are zeroed.

EVEX encoded version: The destination operand is updated at 32-bit granularity according to the writemask.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.480042 130.699997">
<rect x="0.000000" y="10.059998" width="0.480000" height="103.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.059998" width="0.480040" height="103.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="113.560013" width="396.480011" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.600006,76.000015 L336.839996,75.940018 L337.020020,75.880020 C337.931000 75.542023,337.770020 74.187012,336.839996 74.020020  L336.600006,73.960022 L336.420013,74.020020 C335.490021 74.187012,335.329010 75.542023,336.240021 75.880020  L336.600006,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.600006,74.980011 L341.580017,74.980011 L341.399994,75.640015 L337.080017,90.640015 L336.600006,92.320007 L336.119995,90.640015 L331.860016,75.640015 L331.679993,74.980011 L332.339996,74.980011 L332.820007,75.340012 L337.080017,90.340012 L336.119995,90.640015 L336.119995,90.340012 L340.440002,75.340012 L341.399994,75.640015 L340.920013,76.000015 L336.600006,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="332.339996" y="74.980011" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.600006,75.460007 L340.920013,75.460007 L336.600006,90.460007 L332.339996,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.640015" y="38.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.240021" y="24.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.240021" y="24.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.140015" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000000" y="38.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000000" y="24.520004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.100006" y="24.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.100006" y="24.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000000" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.860016" y="38.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.860016" y="24.520004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.959999" y="24.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="96.959999" y="24.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.860016" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.720009" y="38.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.720009" y="24.520004" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.879997" y="24.760010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.879997" y="24.520020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.720009" y="24.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.640007" y="38.020020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.640007" y="24.520004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.740021" y="92.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="319.740021" y="92.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="356.640015" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="105.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="92.020004" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.600006" y="92.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.600006" y="92.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="92.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.360016" y="105.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.360016" y="92.020004" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.520020" y="92.260010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="245.520020" y="92.020020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.360016" y="92.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.279999" y="105.520020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.279999" y="92.020004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.380005" y="92.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.380005" y="92.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.279999" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.140015" y="105.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.140015" y="92.020004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.240021" y="92.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.240021" y="92.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.140015" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000000" y="105.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000000" y="92.020004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.100006" y="92.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.100006" y="92.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000000" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.860016" y="105.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.860016" y="92.020004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.959999" y="92.260010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="96.959999" y="92.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.860016" y="92.260010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.720009" y="105.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.720009" y="92.020004" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.879997" y="92.260010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.879997" y="92.020020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.720009" y="92.260010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.640007" y="105.520020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.640007" y="92.020004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.740021" y="24.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="319.740021" y="24.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="356.640015" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="38.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="24.520004" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.600006" y="24.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.600006" y="24.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="24.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.360016" y="38.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.360016" y="24.520004" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.520020" y="24.760010" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="245.520020" y="24.520020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.360016" y="24.760010" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.279999" y="38.020020" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.279999" y="24.520004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.380005" y="24.760010" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.380005" y="24.520020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.279999" y="24.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.140015" y="38.020020" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.140015" y="24.520004" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.880005,76.000015 L303.420013,75.820023 L303.600006,75.700012 L303.720001,75.520020 L303.779999,75.400009 L303.839996,75.160019 L303.899994,74.980011 L303.839996,74.800018 C303.705994 74.411011,303.710999 74.204010,303.239990 74.080017  L302.880005,73.960022 L302.700012,74.020020 C301.755005 74.104019,301.601013 75.552017,302.459991 75.880020  L302.700012,75.940018 L302.880005,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.880005,74.980011 L307.860016,74.980011 L307.679993,75.640015 L303.360016,90.640015 L302.880005,92.320007 L302.399994,90.640015 L298.080017,75.640015 L297.899994,74.980011 L298.559998,74.980011 L299.040009,75.340012 L303.360016,90.340012 L302.399994,90.640015 L302.399994,90.340012 L306.720001,75.340012 L307.679993,75.640015 L307.200012,76.000015 L302.880005,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.559998" y="74.980011" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.880005,75.460007 L307.200012,75.460007 L302.880005,90.460007 L298.559998,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="301.920013" y="65.260010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="302.880005" y="64.300018" width="33.720001" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.380005,76.000015 L262.920013,75.820023 L263.100006,75.700012 L263.220001,75.520020 L263.279999,75.400009 L263.339996,75.160019 L263.399994,74.980011 L263.339996,74.800018 C263.205994 74.411011,263.210999 74.204010,262.739990 74.080017  L262.380005,73.960022 L262.140015,74.020020 C261.229004 74.177017,261.097015 75.572021,261.959991 75.880020  L262.140015,75.940018 L262.380005,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.380005,74.980011 L267.300018,74.980011 L267.119995,75.640015 L262.860016,90.640015 L262.380005,92.320007 L261.899994,90.640015 L257.580017,75.640015 L257.399994,74.980011 L258.059998,74.980011 L258.540009,75.340012 L262.860016,90.340012 L261.899994,90.640015 L261.899994,90.340012 L266.160004,75.340012 L267.119995,75.640015 L266.640015,76.000015 L262.380005,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="258.059998" y="74.980011" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.380005,75.460007 L266.640015,75.460007 L262.380005,90.460007 L258.059998,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.420013" y="38.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.600006,76.000015 L228.839996,75.940018 L229.020020,75.880020 C229.931000 75.542023,229.770020 74.187012,228.839996 74.020020  L228.600006,73.960022 L228.420013,74.020020 C227.490021 74.187012,227.329010 75.542023,228.240021 75.880020  L228.600006,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.600006,74.980011 L233.580017,74.980011 L233.399994,75.640015 L229.080017,90.640015 L228.600006,92.320007 L228.119995,90.640015 L223.860016,75.640015 L223.679993,74.980011 L224.339996,74.980011 L224.820007,75.340012 L229.080017,90.340012 L228.119995,90.640015 L228.119995,90.340012 L232.440002,75.340012 L233.399994,75.640015 L232.920013,76.000015 L228.600006,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.339996" y="74.980011" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.600006,75.460007 L232.920013,75.460007 L228.600006,90.460007 L224.339996,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="227.640015" y="65.260010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.600006" y="64.300018" width="33.779999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.100006,76.000015 L188.339996,75.940018 L188.520020,75.880020 C189.431000 75.542023,189.270020 74.187012,188.339996 74.020020  L188.100006,73.960022 L187.920013,74.020020 C186.936005 74.167023,186.859009 75.625015,187.740021 75.880020  L188.100006,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.100006,74.980011 L193.080017,74.980011 L192.899994,75.640015 L188.580017,90.640015 L188.100006,92.320007 L187.619995,90.640015 L183.360016,75.640015 L183.179993,74.980011 L183.839996,74.980011 L184.320007,75.340012 L188.580017,90.340012 L187.619995,90.640015 L187.619995,90.340012 L191.940002,75.340012 L192.899994,75.640015 L192.420013,76.000015 L188.100006,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="183.839996" y="74.980011" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.100006,75.460007 L192.420013,75.460007 L188.100006,90.460007 L183.839996,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.140015" y="38.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.380005,76.000015 L154.920013,75.820023 L155.100006,75.700012 L155.220001,75.520020 L155.279999,75.400009 L155.339996,75.160019 L155.339996,74.800018 C155.205994 74.411011,155.210999 74.204010,154.739990 74.080017  L154.380005,73.960022 L154.140015,74.020020 C153.209991 74.187012,153.049011 75.542023,153.959991 75.880020  L154.140015,75.940018 L154.380005,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.380005,74.980011 L159.300018,74.980011 L159.119995,75.640015 L154.860016,90.640015 L154.380005,92.320007 L153.899994,90.640015 L149.579987,75.640015 L149.399994,74.980011 L150.059998,74.980011 L150.540009,75.340012 L154.860016,90.340012 L153.899994,90.640015 L153.899994,90.340012 L158.160004,75.340012 L159.119995,75.640015 L158.640015,76.000015 L154.380005,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.059998" y="74.980011" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.380005,75.460007 L158.640015,75.460007 L154.380005,90.460007 L150.059998,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="153.420013" y="65.260010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.380005" y="64.300018" width="33.720001" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.879997,76.000015 L114.419991,75.820023 L114.599998,75.700012 L114.719994,75.520020 L114.779991,75.400009 L114.840004,75.160019 L114.840004,74.800018 C114.706001 74.411011,114.710991 74.204010,114.239998 74.080017  L113.879997,73.960022 L113.639992,74.020020 C112.709999 74.187012,112.549004 75.542023,113.459999 75.880020  L113.639992,75.940018 L113.879997,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.879997,74.980011 L118.799995,74.980011 L118.620003,75.640015 L114.359993,90.640015 L113.879997,92.320007 L113.400002,90.640015 L109.079994,75.640015 L108.900002,74.980011 L109.559990,74.980011 L110.040001,75.340012 L114.359993,90.340012 L113.400002,90.640015 L113.400002,90.340012 L117.659996,75.340012 L118.620003,75.640015 L118.139992,76.000015 L113.879997,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.560005" y="74.980011" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.879997,75.460007 L118.139992,75.460007 L113.879997,90.460007 L109.559990,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="112.920006" y="38.260010" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.099998,76.000015 L80.340004,75.940018 L80.519997,75.880020 C81.430992 75.542023,81.269997 74.187012,80.340004 74.020020  L80.099998,73.960022 L79.560005,74.140015 L79.379997,74.260010 L79.260002,74.440018 L79.139992,74.800018 L79.139992,75.160019 L79.200005,75.400009 L79.260002,75.520020 L79.379997,75.700012 L79.560005,75.820023 L80.099998,76.000015" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.099998,74.980011 L85.079994,74.980011 L84.900002,75.640015 L80.579994,90.640015 L80.099998,92.320007 L79.620003,90.640015 L75.359993,75.640015 L75.180000,74.980011 L75.840004,74.980011 L76.320000,75.340012 L80.579994,90.340012 L79.620003,90.640015 L79.620003,90.340012 L83.939995,75.340012 L84.900002,75.640015 L84.420006,76.000015 L80.099998,76.000015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.840004" y="74.980011" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.099998,75.460007 L84.420006,75.460007 L80.099998,90.460007 L75.840004,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="79.140007" y="65.260010" width="1.980000" height="9.720000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.099998" y="64.300018" width="33.779999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="264.960022" y="33.280014" textLength="4.170000" font-size="8px">2</text>
<text x="259.980011" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="339.180023" y="33.280014" textLength="4.170000" font-size="8px">0</text>
<text x="334.200012" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="79.379997" y="100.780014" textLength="4.170000" font-size="8px">6</text>
<text x="74.340004" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="116.400002" y="100.780014" textLength="4.170000" font-size="8px">6</text>
<text x="190.680023" y="100.780014" textLength="4.170000" font-size="8px">4</text>
<text x="264.960022" y="100.780014" textLength="4.170000" font-size="8px">2</text>
<text x="259.980011" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="302.040009" y="100.780014" textLength="4.170000" font-size="8px">0</text>
<text x="297.059998" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="339.180023" y="100.780014" textLength="4.170000" font-size="8px">0</text>
<text x="74.340004" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="116.400002" y="33.280014" textLength="4.170000" font-size="8px">6</text>
<text x="111.420006" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="190.680023" y="33.280014" textLength="4.170000" font-size="8px">4</text>
<text x="44.879997" y="34.960007" textLength="5.415000" font-size="8px">R</text>
<text x="39.900002" y="34.960007" textLength="5.002500" font-size="8px">S</text>
<text x="49.975502" y="100.840012" textLength="5.002500" font-size="8px">S</text>
<text x="39.599998" y="100.840012" textLength="5.415000" font-size="8px">D</text>
<text x="302.040009" y="33.280014" textLength="4.170000" font-size="8px">1</text>
<text x="297.059998" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="185.700012" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="79.379997" y="33.280014" textLength="4.170000" font-size="8px">7</text>
<text x="227.880005" y="33.280014" textLength="4.170000" font-size="8px">3</text>
<text x="185.700012" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="222.839996" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="111.420006" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="148.559998" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="44.993996" y="100.840012" textLength="5.002500" font-size="8px">E</text>
<text x="153.540009" y="33.280014" textLength="4.170000" font-size="8px">5</text>
<text x="54.957008" y="100.840012" textLength="4.582500" font-size="8px">T</text>
<text x="334.200012" y="100.780014" textLength="5.002500" font-size="8px">X</text>
<text x="153.540009" y="100.780014" textLength="4.170000" font-size="8px">4</text>
<text x="227.880005" y="100.780014" textLength="4.170000" font-size="8px">2</text>
<text x="222.839996" y="33.280014" textLength="5.002500" font-size="8px">X</text>
<text x="50.338493" y="34.960007" textLength="5.415000" font-size="8px">C</text>
<text x="148.559998" y="33.280014" textLength="5.002500" font-size="8px">X</text>
</svg>
<figcaption>Figure 4-4.  MOVSLDUP Operation
</figcaption></figure>
```

### Operation
#### VMOVSLDUP (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
TMP_SRC[31:0] <-  SRC[31:0]
TMP_SRC[63:32] <-  SRC[31:0]
TMP_SRC[95:64] <-  SRC[95:64]
TMP_SRC[127:96] <-  SRC[95:64]
IF VL >= 256
    TMP_SRC[159:128] <-  SRC[159:128]
    TMP_SRC[191:160] <-  SRC[159:128]
    TMP_SRC[223:192] <-  SRC[223:192]
    TMP_SRC[255:224] <-  SRC[223:192]
FI;
IF VL >= 512
    TMP_SRC[287:256] <-  SRC[287:256]
    TMP_SRC[319:288] <-  SRC[287:256]
    TMP_SRC[351:320] <-  SRC[351:320]
    TMP_SRC[383:352] <-  SRC[351:320]
    TMP_SRC[415:384] <-  SRC[415:384]
    TMP_SRC[447:416] <-  SRC[415:384]
    TMP_SRC[479:448] <-  SRC[479:448]
    TMP_SRC[511:480] <-  SRC[479:448]
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_SRC[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  ; zeroing-masking
                            DEST[i+31:i] <-  0 
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVSLDUP (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC[31:0]
DEST[63:32] <-  SRC[31:0]
DEST[95:64] <-  SRC[95:64]
DEST[127:96] <-  SRC[95:64]
DEST[159:128] <-  SRC[159:128]
DEST[191:160] <-  SRC[159:128]
DEST[223:192] <-  SRC[223:192]
DEST[255:224] <-  SRC[223:192]
DEST[MAX_VL-1:256] <-  0
```
#### VMOVSLDUP (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  SRC[31:0]
DEST[63:32] <-  SRC[31:0]
DEST[95:64] <-  SRC[95:64]
DEST[127:96] <-  SRC[95:64]
DEST[MAX_VL-1:128] <-  0
```
#### MOVSLDUP (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- SRC[31:0]
DEST[63:32] <- SRC[31:0]
DEST[95:64] <- SRC[95:64]
DEST[127:96] <- SRC[95:64]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVSLDUP __m512 _mm512_moveldup_ps( __m512 a);
VMOVSLDUP __m512 _mm512_mask_moveldup_ps(__m512 s, __mmask16 k, __m512 a);
VMOVSLDUP __m512 _mm512_maskz_moveldup_ps( __mmask16 k, __m512 a);
VMOVSLDUP __m256 _mm256_mask_moveldup_ps(__m256 s, __mmask8 k, __m256 a);
VMOVSLDUP __m256 _mm256_maskz_moveldup_ps( __mmask8 k, __m256 a);
VMOVSLDUP __m128 _mm_mask_moveldup_ps(__m128 s, __mmask8 k, __m128 a);
VMOVSLDUP __m128 _mm_maskz_moveldup_ps( __mmask8 k, __m128 a);
VMOVSLDUP __m256 _mm256_moveldup_ps (__m256 a);
VMOVSLDUP __m128 _mm_moveldup_ps (__m128 a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4; 

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

#UD If EVEX.vvvv != 1111B or VEX.vvvv != 1111B.

