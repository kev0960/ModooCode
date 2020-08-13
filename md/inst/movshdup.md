----------------------------
title : MOVSHDUP (Intel x86/64 assembly instruction)
cat_title : MOVSHDUP
ref_title : MOVSHDUP
path : /X86-64 명령어 레퍼런스
----------------------------
#@ MOVSHDUP

**Replicate Single FP Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 16 /r\newline{}MOVSHDUP xmm1, xmm2/m128|RM|V/V|SSE3|Move odd index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.|
|VEX.128.F3.0F.WIG 16 /r\newline{}VMOVSHDUP xmm1, xmm2/m128|RM|V/V|AVX|Move odd index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.|
|VEX.256.F3.0F.WIG 16 /r\newline{}VMOVSHDUP ymm1, ymm2/m256|RM|V/V|AVX|Move odd index single-precision floating-point values from ymm2/mem and duplicate each element into ymm1.|
|EVEX.128.F3.0F.W0 16 /r\newline{}VMOVSHDUP xmm1 {k1}{z}, xmm2/m128|FVM|V/V|AVX512VL\newline{}AVX512F|Move odd index single-precision floating-point values from xmm2/m128 and duplicate each element into xmm1 under writemask.|
|EVEX.256.F3.0F.W0 16 /r\newline{}VMOVSHDUP ymm1 {k1}{z}, ymm2/m256|FVM|V/V|AVX512VL\newline{}AVX512F|Move odd index single-precision floating-point values from ymm2/m256 and duplicate each element into ymm1 under writemask.|
|EVEX.512.F3.0F.W0 16 /r\newline{}VMOVSHDUP zmm1 {k1}{z}, zmm2/m512|FVM|V/V|AVX512F|Move odd index single-precision floating-point values from zmm2/m512 and duplicate each element into zmm1 under writemask.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FVM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Duplicates odd-indexed single-precision floating-point values from the source operand (the second operand) to adjacent element pair in the destination operand (the first operand). See Figure 4-3. The source operand is an XMM, YMM or ZMM register or 128, 256 or 512-bit memory location and the destination operand is an XMM, YMM or ZMM register.

128-bit Legacy SSE version: Bits (MAX_VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 encoded version: Bits (MAX_VL-1:128) of the destination register are zeroed.

VEX.256 encoded version: Bits (MAX_VL-1:256) of the destination register are zeroed.

EVEX encoded version: The destination operand is updated at 32-bit granularity according to the writemask.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

```embed
<figure>
<svg viewBox="0 0 396.539978 130.679993">
<rect x="0.000000" y="10.000000" width="0.480000" height="103.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.059998" y="10.000000" width="0.479980" height="103.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="396.540009" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="113.500000" width="396.540009" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.880005,75.940002 L303.119995,75.940002 L303.299988,75.880005 C304.211975 75.378006,304.075989 74.283005,303.119995 73.960007  L302.700012,73.960007 L302.520020,74.020004 L302.159973,74.260010 L302.039978,74.380005 L301.979980,74.559998 L301.919983,74.740005 L301.919983,75.160004 L301.979980,75.339996 L302.039978,75.520004 L302.159973,75.639999 L302.520020,75.880005 L302.700012,75.940002 L302.880005,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.880005,74.979996 L307.859985,74.979996 L307.679993,75.639999 L303.359985,90.639999 L302.880005,92.319992 L302.399963,90.639999 L298.140015,75.639999 L297.959961,74.979996 L298.619995,74.979996 L299.099976,75.339996 L303.359985,90.339996 L302.399963,90.639999 L302.399963,90.339996 L306.719971,75.339996 L307.679993,75.639999 L307.200012,76.000000 L302.880005,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.619995" y="74.979996" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.880005,75.460007 L307.200012,75.460007 L302.880005,90.460007 L298.619995,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="301.919983" y="38.259995" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.240005" y="24.759995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.240005" y="24.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="24.759995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000015" y="38.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000015" y="24.519989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.160004" y="24.759995" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.160004" y="24.519989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000015" y="24.759995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="38.019989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="24.519989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.020004" y="24.759995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="97.020004" y="24.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="24.759995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.779999" y="38.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.779999" y="24.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.880005" y="24.759995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.880005" y="24.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.779999" y="24.759995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="38.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="24.519989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.739990" y="92.259995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="319.739990" y="92.020004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="356.640015" y="92.259995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="105.520004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="92.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.659973" y="92.259995" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.659973" y="92.020004" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="92.259995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="105.520004" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="92.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.520004" y="92.259995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="245.520004" y="92.020004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="92.259995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.280014" y="105.520004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.280014" y="92.019989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.379990" y="92.259995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.379990" y="92.020004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.280014" y="92.259995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="105.520004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="92.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.240005" y="92.259995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.240005" y="92.020004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="92.259995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000015" y="105.520004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000015" y="92.019989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.160004" y="92.259995" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.160004" y="92.020004" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.000015" y="92.259995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="105.520004" width="37.320000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="92.019989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.020004" y="92.259995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="97.020004" y="92.020004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.919998" y="92.259995" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.779999" y="105.520004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.779999" y="92.019989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.880005" y="92.259995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="59.880005" y="92.020004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.779999" y="92.259995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="105.520004" width="37.380001" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="59.639999" y="92.019989" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.739990" y="24.759995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="319.739990" y="24.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="356.640015" y="24.759995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="38.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="24.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.659973" y="24.759995" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.659973" y="24.519989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="319.500000" y="24.759995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="38.019989" width="37.320000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="24.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.520004" y="24.759995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="245.520004" y="24.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.419983" y="24.759995" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.280014" y="38.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.280014" y="24.519989" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.379990" y="24.759995" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.379990" y="24.519989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.280014" y="24.759995" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="38.019989" width="37.380001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.139999" y="24.519989" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="302.880005" y="64.300003" width="33.779999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.659973,75.940002 L336.839966,75.940002 L337.019958,75.880005 C337.937012 75.432999,337.807007 74.237000,336.839966 73.960007  L336.419983,73.960007 C335.463989 74.283005,335.328003 75.378006,336.239990 75.880005  L336.419983,75.940002 L336.659973,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.659973,74.979996 L341.580017,74.979996 L341.399963,75.639999 L337.140015,90.639999 L336.659973,92.319992 L336.179993,90.639999 L331.859985,75.639999 L331.679993,74.979996 L332.339966,74.979996 L332.820007,75.339996 L337.140015,90.339996 L336.179993,90.639999 L336.179993,90.339996 L340.440002,75.339996 L341.399963,75.639999 L340.919983,76.000000 L336.659973,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="332.340027" y="74.979996" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M336.659973,75.460007 L340.919983,75.460007 L336.659973,90.460007 L332.339966,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="335.700012" y="65.259995" width="1.980000" height="9.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.659988,75.940002 L228.839981,75.940002 L229.019974,75.880005 C229.931992 75.378006,229.795975 74.283005,228.839981 73.960007  L228.419998,73.960007 C227.463974 74.283005,227.327988 75.378006,228.239975 75.880005  L228.419998,75.940002 L228.659988,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.659988,74.979996 L233.580002,74.979996 L233.399979,75.639999 L229.139999,90.639999 L228.659988,92.319992 L228.179977,90.639999 L223.860001,75.639999 L223.679977,74.979996 L224.339981,74.979996 L224.819992,75.339996 L229.139999,90.339996 L228.179977,90.639999 L228.179977,90.339996 L232.439987,75.339996 L233.399979,75.639999 L232.919998,76.000000 L228.659988,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.340012" y="74.979996" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.659988,75.460007 L232.919998,75.460007 L228.659988,90.460007 L224.339981,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="227.699997" y="38.259995" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.659988" y="64.300003" width="33.720001" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.380005,75.940002 L262.619995,75.940002 L262.799988,75.880005 L262.919983,75.760010 L263.099976,75.639999 L263.219971,75.520004 L263.339966,75.339996 L263.339966,75.160004 L263.399963,74.919998 L263.339966,74.740005 L263.339966,74.559998 L263.219971,74.380005 L263.099976,74.260010 L262.919983,74.139999 L262.799988,74.020004 L262.619995,73.960007 L262.200012,73.960007 C261.205017 74.223007,261.086975 75.458008,262.020020 75.880005  L262.200012,75.940002 L262.380005,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.380005,74.979996 L267.359985,74.979996 L267.179993,75.639999 L262.859985,90.639999 L262.380005,92.319992 L261.899963,90.639999 L257.640015,75.639999 L257.459961,74.979996 L258.119995,74.979996 L258.599976,75.339996 L262.859985,90.339996 L261.899963,90.639999 L261.899963,90.339996 L266.219971,75.339996 L267.179993,75.639999 L266.700012,76.000000 L262.380005,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="258.119995" y="74.979996" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.380005,75.460007 L266.700012,75.460007 L262.380005,90.460007 L258.119995,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.419983" y="65.259995" width="1.980000" height="9.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.379990,75.940002 L154.559982,75.940002 L154.800003,75.880005 L154.919998,75.760010 L155.099991,75.639999 L155.219986,75.520004 L155.339981,75.160004 L155.399979,74.919998 L155.219986,74.380005 L155.099991,74.260010 L154.919998,74.139999 L154.800003,74.020004 L154.559982,73.960007 L154.199997,73.960007 C153.205002 74.223007,153.086990 75.458008,154.020004 75.880005  L154.199997,75.940002 L154.379990,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.379990,74.979996 L159.360001,74.979996 L159.179977,75.639999 L154.860001,90.639999 L154.379990,92.319992 L153.899979,90.639999 L149.579987,75.639999 L149.399994,74.979996 L150.059982,74.979996 L150.539993,75.339996 L154.860001,90.339996 L153.899979,90.639999 L153.899979,90.339996 L158.219986,75.339996 L159.179977,75.639999 L158.699997,76.000000 L154.379990,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.059998" y="74.979996" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.379990,75.460007 L158.699997,75.460007 L154.379990,90.460007 L150.059982,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="153.419998" y="38.259995" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.379990" y="64.300003" width="33.779999" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.159988,75.940002 L188.339981,75.940002 L188.519974,75.880005 C189.431992 75.378006,189.295975 74.283005,188.339981 73.960007  L187.919998,73.960007 C186.963974 74.283005,186.827988 75.378006,187.739975 75.880005  L187.919998,75.940002 L188.159988,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.159988,74.979996 L193.080002,74.979996 L192.899979,75.639999 L188.639999,90.639999 L188.159988,92.319992 L187.679977,90.639999 L183.360001,75.639999 L183.179977,74.979996 L183.839981,74.979996 L184.319992,75.339996 L188.639999,90.339996 L187.679977,90.639999 L187.679977,90.339996 L191.939987,75.339996 L192.899979,75.639999 L192.419998,76.000000 L188.159988,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="183.840012" y="74.979996" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.159988,75.460007 L192.419998,75.460007 L188.159988,90.460007 L183.839981,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.199997" y="65.259995" width="1.980000" height="9.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.160004,75.940002 L80.339996,75.940002 L80.520004,75.880005 C81.432007 75.378006,81.296005 74.283005,80.339996 73.960007  L79.919998,73.960007 C78.964005 74.283005,78.828003 75.378006,79.740005 75.880005  L79.919998,75.940002 L80.160004,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.160004,74.979996 L85.080002,74.979996 L84.900009,75.639999 L80.639999,90.639999 L80.160004,92.319992 L79.680008,90.639999 L75.360001,75.639999 L75.180008,74.979996 L75.839996,74.979996 L76.320007,75.339996 L80.639999,90.339996 L79.680008,90.639999 L79.680008,90.339996 L83.940002,75.339996 L84.900009,75.639999 L84.419998,76.000000 L80.160004,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.839996" y="74.979996" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M80.160004,75.460007 L84.419998,75.460007 L80.160004,90.460007 L75.839996,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="79.199997" y="38.259995" width="1.980000" height="36.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="80.160004" y="64.300003" width="33.720001" height="1.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.880005,75.940002 L114.059998,75.940002 L114.300003,75.880005 L114.419998,75.760010 L114.600006,75.639999 L114.720001,75.520004 L114.840012,75.160004 L114.900009,74.919998 L114.720001,74.380005 L114.600006,74.260010 L114.419998,74.139999 L114.300003,74.020004 L114.059998,73.960007 L113.700012,73.960007 C112.705002 74.223007,112.587006 75.458008,113.520004 75.880005  L113.700012,75.940002 L113.880005,75.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.880005,74.979996 L118.860001,74.979996 L118.680008,75.639999 L114.360001,90.639999 L113.880005,92.319992 L113.400009,90.639999 L109.080002,75.639999 L108.900009,74.979996 L109.559998,74.979996 L110.040009,75.339996 L114.360001,90.339996 L113.400009,90.639999 L113.400009,90.339996 L117.720001,75.339996 L118.680008,75.639999 L118.200012,76.000000 L113.880005,76.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.559998" y="74.979996" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M113.880005,75.460007 L118.200012,75.460007 L113.880005,90.460007 L109.559998,75.460007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="112.919998" y="65.259995" width="1.980000" height="9.660000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="222.840012" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="259.979980" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="302.100037" y="33.220001" textLength="4.170000" font-size="8px">1</text>
<text x="74.339996" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="185.699997" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="259.979980" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="302.100037" y="100.779999" textLength="4.170000" font-size="8px">1</text>
<text x="79.379990" y="33.220001" textLength="4.170000" font-size="8px">7</text>
<text x="148.620010" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="190.680008" y="33.220001" textLength="4.170000" font-size="8px">4</text>
<text x="185.699997" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="45.054001" y="100.779999" textLength="5.002500" font-size="8px">E</text>
<text x="39.660004" y="100.779999" textLength="5.415000" font-size="8px">D</text>
<text x="222.840012" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="111.479996" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="334.200012" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="148.620010" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="264.960022" y="33.220001" textLength="4.170000" font-size="8px">2</text>
<text x="39.900009" y="34.899994" textLength="5.002500" font-size="8px">S</text>
<text x="227.880020" y="100.779999" textLength="4.170000" font-size="8px">3</text>
<text x="153.600021" y="33.220001" textLength="4.170000" font-size="8px">5</text>
<text x="227.880020" y="33.220001" textLength="4.170000" font-size="8px">3</text>
<text x="55.017014" y="100.779999" textLength="4.582500" font-size="8px">T</text>
<text x="111.479996" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="79.379990" y="100.779999" textLength="4.170000" font-size="8px">7</text>
<text x="50.338501" y="34.899994" textLength="5.415000" font-size="8px">C</text>
<text x="339.179993" y="100.779999" textLength="4.170000" font-size="8px">1</text>
<text x="297.119995" y="100.779999" textLength="5.002500" font-size="8px">X</text>
<text x="116.459991" y="33.220001" textLength="4.170000" font-size="8px">6</text>
<text x="44.880005" y="34.899994" textLength="5.415000" font-size="8px">R</text>
<text x="116.459991" y="100.779999" textLength="4.170000" font-size="8px">7</text>
<text x="297.119995" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="334.200012" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="264.960022" y="100.779999" textLength="4.170000" font-size="8px">3</text>
<text x="74.339996" y="33.220001" textLength="5.002500" font-size="8px">X</text>
<text x="190.680008" y="100.779999" textLength="4.170000" font-size="8px">5</text>
<text x="153.600021" y="100.779999" textLength="4.170000" font-size="8px">5</text>
<text x="50.035507" y="100.779999" textLength="5.002500" font-size="8px">S</text>
<text x="339.179993" y="33.220001" textLength="4.170000" font-size="8px">0</text>
</svg>
<figcaption>Figure 4-3.  MOVSHDUP Operation
</figcaption></figure>
```

### Operation
#### VMOVSHDUP (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
TMP_SRC[31:0] <-  SRC[63:32]
TMP_SRC[63:32] <-  SRC[63:32]
TMP_SRC[95:64] <-  SRC[127:96]
TMP_SRC[127:96] <-  SRC[127:96]
IF VL >= 256
    TMP_SRC[159:128] <-  SRC[191:160]
    TMP_SRC[191:160] <-  SRC[191:160]
    TMP_SRC[223:192] <-  SRC[255:224]
    TMP_SRC[255:224] <-  SRC[255:224]
FI;
IF VL >= 512
    TMP_SRC[287:256] <-  SRC[319:288]
    TMP_SRC[319:288] <-  SRC[319:288]
    TMP_SRC[351:320] <-  SRC[383:352]
    TMP_SRC[383:352] <-  SRC[383:352]
    TMP_SRC[415:384] <-  SRC[447:416]
    TMP_SRC[447:416] <-  SRC[447:416]
    TMP_SRC[479:448] <-  SRC[511:480]
    TMP_SRC[511:480] <-  SRC[511:480]
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
#### VMOVSHDUP (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  SRC[63:32]
DEST[63:32] <-  SRC[63:32]
DEST[95:64] <-  SRC[127:96]
DEST[127:96] <-  SRC[127:96]
DEST[159:128] <-  SRC[191:160]
DEST[191:160] <-  SRC[191:160]
DEST[223:192] <-  SRC[255:224]
DEST[255:224] <-  SRC[255:224]
DEST[MAX_VL-1:256] <-  0
```
#### VMOVSHDUP (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  SRC[63:32]
DEST[63:32] <-  SRC[63:32]
DEST[95:64] <-  SRC[127:96]
DEST[127:96] <-  SRC[127:96]
DEST[MAX_VL-1:128] <-  0
```
#### MOVSHDUP (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <- SRC[63:32]
DEST[63:32] <- SRC[63:32]
DEST[95:64] <- SRC[127:96]
DEST[127:96] <- SRC[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVSHDUP __m512 _mm512_movehdup_ps( __m512 a);
VMOVSHDUP __m512 _mm512_mask_movehdup_ps(__m512 s, __mmask16 k, __m512 a);
VMOVSHDUP __m512 _mm512_maskz_movehdup_ps( __mmask16 k, __m512 a);
VMOVSHDUP __m256 _mm256_mask_movehdup_ps(__m256 s, __mmask8 k, __m256 a);
VMOVSHDUP __m256 _mm256_maskz_movehdup_ps( __mmask8 k, __m256 a);
VMOVSHDUP __m128 _mm_mask_movehdup_ps(__m128 s, __mmask8 k, __m128 a);
VMOVSHDUP __m128 _mm_maskz_movehdup_ps( __mmask8 k, __m128 a);
VMOVSHDUP __m256 _mm256_movehdup_ps (__m256 a);
VMOVSHDUP __m128 _mm_movehdup_ps (__m128 a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4; 

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

#UD If EVEX.vvvv != 1111B or VEX.vvvv != 1111B.

