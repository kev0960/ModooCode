----------------------------
title : PDEP (Intel x86/64 assembly instruction)
cat_title : PDEP
ref_title : PDEP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PDEP

** Parallel Bits Deposit**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.LZ.F2.0F38.W0 F5 /r`\newline{}`PDEP` r32a r32b \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RVM|V/V|BMI2|Parallel deposit of bits from r32b using mask in r/m32, result is writ-ten to r32a.|
|`VEX.NDS.LZ.F2.0F38.W1 F5 /r`\newline{}`PDEP` r64a r64b \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RVM|V/N.E.|BMI2|Parallel deposit of bits from r64b using mask in r/m64, result is writ-ten to r64a.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


PDEP uses a mask in the second source operand (the third operand) to transfer/scatter contiguous low order bits in the first source operand (the second operand) into the destination (the first operand). PDEP takes the low bits from the first source operand and deposit them in the destination operand at the corresponding bit locations that are set in the second source operand (mask). All other bits (bits not set in mask) in destination are set to zero.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.

```embed
<figure>
<svg viewBox="0 0 349.410004 174.160004">
<rect x="247.500610" y="10.300018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="247.500610" y="10.059998" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.640625" y="10.299988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="247.260620" y="28.180023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="247.260620" y="10.059998" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.480621" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="189.480621" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.620636" y="10.239990" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.240631" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.240631" y="10.000000" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.860626" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.860626" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.000610" y="10.239990" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.620636" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.620636" y="10.000000" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.240631" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="228.240631" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="247.380615" y="10.239990" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.000610" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.000610" y="10.000000" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="112.320610" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="112.320610" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.460632" y="10.239990" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="112.080620" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="112.080620" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.880623" y="10.300018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="92.880623" y="10.059998" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="112.020622" y="10.299988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.640617" y="28.180023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.640617" y="10.059998" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="34.860619" y="10.240021" width="19.320000" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="34.860619" y="10.000000" width="19.559999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.940620" y="10.239990" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="34.620613" y="28.119995" width="19.559999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="34.620613" y="10.000000" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="54.180611" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="54.180611" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="73.320610" y="10.239990" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.940620" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.940620" y="10.000000" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="73.560616" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="73.560616" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.700615" y="10.239990" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="73.320610" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="73.320610" y="10.000000" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="324.720612" y="10.300018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="324.720612" y="10.059998" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="343.860626" y="10.299988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="324.480621" y="28.180023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="324.480621" y="10.059998" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.700623" y="10.360016" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="266.700623" y="10.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="285.840637" y="10.359985" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.460632" y="28.240021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="266.460632" y="10.119995" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="286.080627" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="286.080627" y="10.000000" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.220612" y="10.239990" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="285.840637" y="28.119995" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="285.840637" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.460632" y="9.760010" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="305.460632" y="9.519989" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="324.600616" y="9.760010" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.220612" y="27.640015" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.220612" y="9.520020" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.720612" y="57.459991" width="19.379999" height="18.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="249.720612" y="57.220001" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.860626" y="57.459991" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.480621" y="75.699982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.480621" y="57.220001" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640625" y="57.760010" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.640625" y="57.520020" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.780640" y="57.760010" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.400635" y="75.640015" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.400635" y="57.520020" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="211.020630" y="57.760010" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="211.020630" y="57.520020" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.160614" y="57.760010" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.780640" y="75.640015" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.780640" y="57.520020" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.400635" y="57.760010" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="230.400635" y="57.520020" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.540619" y="57.760010" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.160614" y="75.640015" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.160614" y="57.520020" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.540611" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="114.540611" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.680634" y="57.700012" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.300621" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.300621" y="57.460022" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="95.040611" y="57.760010" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="95.040611" y="57.520020" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.180611" y="57.760010" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.800621" y="75.640015" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.800621" y="57.520020" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="37.020622" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="37.020622" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.160622" y="57.700012" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.780617" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.780617" y="57.460022" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400612" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.400612" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.540611" y="57.700012" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.160622" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.160622" y="57.460022" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.780617" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="75.780617" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.920616" y="57.700012" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.540611" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.540611" y="57.460022" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.940613" y="57.399994" width="19.379999" height="18.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="326.940613" y="57.160004" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="346.080627" y="57.399994" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.700623" y="75.640015" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.700623" y="57.160004" width="0.479980" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.920624" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="268.920624" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.060638" y="57.700012" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.680634" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.680634" y="57.460022" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.300629" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="288.300629" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.440613" y="57.700012" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.060638" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.060638" y="57.460022" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.680634" y="57.700012" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="307.680634" y="57.460022" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.820618" y="57.700012" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.440613" y="75.580017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.440613" y="57.460022" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.720612" y="98.440002" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="249.720612" y="98.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.860626" y="98.440002" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.480621" y="116.320007" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.480621" y="98.200012" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.640625" y="98.380005" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.640625" y="98.139984" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.780640" y="98.380005" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.400635" y="116.260010" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.400635" y="98.140015" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="211.020630" y="98.380005" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="211.020630" y="98.139984" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.160614" y="98.380005" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.780640" y="116.260010" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.780640" y="98.140015" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.400635" y="98.380005" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="230.400635" y="98.139984" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.540619" y="98.380005" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.160614" y="116.260010" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.160614" y="98.140015" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.540611" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="114.540611" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.680634" y="98.320007" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.300621" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.300621" y="98.080017" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="95.040611" y="98.380005" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="95.040611" y="98.139984" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.180611" y="98.380005" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.800621" y="116.260010" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.800621" y="98.140015" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="37.020622" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="37.020622" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.160622" y="98.320007" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.780617" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.780617" y="98.080017" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.400612" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="56.400612" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.540611" y="98.320007" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.160622" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="56.160622" y="98.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.780617" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="75.780617" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.920616" y="98.320007" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.540611" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.540611" y="98.080017" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.940613" y="98.380005" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="326.940613" y="98.139984" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="346.080627" y="98.380005" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.700623" y="116.260010" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.700623" y="98.140015" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.920624" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="268.920624" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.060638" y="98.320007" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.680634" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.680634" y="98.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.300629" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="288.300629" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.440613" y="98.320007" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.060638" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="288.060638" y="98.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.680634" y="98.320007" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="307.680634" y="98.080017" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.820618" y="98.320007" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.440613" y="116.199982" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.440613" y="98.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.540619,91.660004 L212.100616,93.760010 L212.460632,94.360016 L211.860626,94.540009 L202.860626,97.839996 L201.240631,98.440002 L202.320618,97.059998 L208.620605,88.959991 L208.980621,89.500000 L208.980621,90.100006 L203.100616,97.660004 L202.320618,97.059998 L202.560608,96.880005 L211.560608,93.580017 L211.860626,94.540009 L211.320618,94.360016 L209.760620,92.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.980621,89.500000 L210.540619,91.660004 L209.760620,92.260010 L208.200623,90.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.180634,91.960022 L211.740631,94.060028 L202.740631,97.360016 L208.620636,89.800018" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.460632,29.140015 L296.640625,29.020020 L296.340637,28.660004 L296.160645,28.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.720612,91.839996 L210.540619,91.959991 L210.240601,91.600006 L210.420624,91.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.460632,29.140015 L296.160645,28.780029 L210.420624,91.480011 L210.720642,91.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.200615,95.740021 L116.220619,98.200012 L116.520622,98.800018 L115.800621,98.920013 L106.260612,100.060028 L104.520622,100.240021 L105.900612,99.160034 L113.400612,93.160034 L113.940620,92.740021 L114.180611,93.340027 L114.060616,93.940033 L106.560616,99.940033 L105.900612,99.160034 L106.200615,99.040009 L115.740608,97.900024 L115.800621,98.920013 L115.320610,98.560028 L114.300621,96.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M114.180611,93.339996 L115.200615,95.739990 L114.300606,96.100006 L113.280617,93.699982" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M114.780617,95.920013 L115.800621,98.380005 L106.260612,99.520020 L113.760612,93.520020" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.360626,28.540009 L276.540619,28.480011 L276.360626,28.059998 L276.180634,28.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M115.320610,95.980011 L115.140617,96.040009 L114.960609,95.620026 L115.140617,95.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.360626,28.540009 L276.180634,28.119995 L115.140617,95.559998 L115.320625,95.980011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.900635,91.119995 L251.760620,93.040009 L252.180634,93.519989 L251.580627,93.820007 L243.000641,98.199982 L241.440643,98.979980 L242.340637,97.479980 L247.260620,89.260010 L247.620636,88.720001 L248.100647,89.199982 L248.160645,89.739990 L243.240631,97.959991 L242.340637,97.479980 L242.580627,97.299988 L251.160645,92.919983 L251.580627,93.820007 L250.980621,93.699982 L249.120636,91.779999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M248.100616,89.200012 L249.900604,91.120026 L249.120605,91.779999 L247.320618,89.860016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.540619,91.420013 L251.400604,93.340027 L242.820618,97.720001 L247.740631,89.500000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M315.840637,29.740021 L316.020630,29.620026 L315.720642,29.260010 L315.540649,29.380035" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.140625,91.240021 L249.960632,91.360016 L249.660614,91.000031 L249.840637,90.880035" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M315.840637,29.740021 L315.540649,29.380035 L249.840637,90.880005 L250.140625,91.240021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.660614,88.179993 L306.000610,89.380005 L306.540619,89.739990 L306.120605,90.160004 L299.460602,97.059998 L298.200623,98.320007 L298.620605,96.639984 L300.600616,87.279999 L300.720612,86.619995 L301.320618,86.919983 L301.560608,87.459991 L299.580627,96.820007 L298.620605,96.639984 L298.740601,96.339996 L305.400604,89.440002 L306.120605,90.160004 L305.520599,90.279999 L303.180603,89.079987" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.320618,86.920013 L303.660614,88.180023 L303.180603,89.080017 L300.840607,87.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.420624,88.600006 L305.760620,89.800018 L299.100616,96.700012 L301.080627,87.339996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M335.280640,29.080017 L335.400635,28.900024 L334.980652,28.660004 L334.860626,28.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.900635,88.240021 L303.780640,88.420013 L303.360626,88.180023 L303.480621,88.000031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M335.280640,29.080017 L334.860626,28.840027 L303.480652,88.000000 L303.900635,88.240021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="297.300629" y="74.980011" width="0.480010" height="23.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.040619" y="75.520020" width="0.480010" height="23.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="200.820618" y="75.520020" width="0.480010" height="23.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="101.400612" y="75.520020" width="0.480010" height="23.580000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.640625" y="19.720032" width="4.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="148.380615" y="19.720032" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.840637" y="19.720032" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.300629" y="19.720032" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="140.880615" y="65.620026" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="151.620636" y="65.620026" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="166.020630" y="65.620026" width="8.220000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.480621" y="65.620026" width="4.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.740631" y="107.440033" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="153.480621" y="107.440033" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="167.940613" y="107.440033" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="182.400635" y="107.440033" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.120613,125.800018 L72.120613,129.100006 L71.460609,128.920013 L62.280617,126.280029 L60.600609,125.800018 L62.280617,125.320007 L71.460609,122.680023 L72.120613,122.500031 L72.120613,123.160004 L71.760612,123.640015 L62.580620,126.280029 L62.280617,125.320007 L62.580620,125.320007 L71.760612,127.960022 L71.460609,128.920013 L71.100609,128.440033 L71.100609,125.800018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.100624" y="123.160004" width="1.020000" height="2.640000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M71.640617,125.800018 L71.640617,128.440033 L62.460625,125.800018 L71.640617,123.160004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="318.540619" y="125.559998" width="4.200000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.620636" y="125.559998" width="7.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="290.700623" y="125.559998" width="7.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="276.780640" y="125.559998" width="7.980000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.920624" y="125.559998" width="7.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.000610" y="125.559998" width="7.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="235.080627" y="125.559998" width="7.920000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.900635" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.160614" y="125.559998" width="7.740000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="214.980621" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.300629" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.060638" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="193.380615" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.140625" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="179.460632" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.280640" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.540619" y="125.559998" width="7.740000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.360626" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="151.680634" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.440613" y="125.559998" width="0.240020" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.760620" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.520630" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.840614" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="117.660622" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.920616" y="125.559998" width="7.740000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.740623" y="125.559998" width="0.240010" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="96.060616" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.820610" y="125.559998" width="0.239990" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.140617" y="125.559998" width="7.680000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.900612" y="125.559998" width="0.240010" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.940620" y="125.559998" width="3.960000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="51.906944" y="130.299988" textLength="5.724000" font-size="8px">1</text>
<text x="31.440941" y="130.299988" textLength="5.607000" font-size="8px">b</text>
<text x="340.501801" y="127.779999" textLength="3.168000" font-size="8px"> </text>
<text x="334.515015" y="127.779999" textLength="2.466000" font-size="8px">i</text>
<text x="105.420616" y="111.460022" textLength="4.579200" font-size="8px">3</text>
<text x="99.300621" y="109.179993" textLength="6.156000" font-size="8px">S</text>
<text x="293.760620" y="109.119995" textLength="6.156000" font-size="8px">S</text>
<text x="338.880615" y="23.080017" textLength="4.579200" font-size="8px">0</text>
<text x="332.760620" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="312.840637" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="300.240631" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="294.120636" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="279.600616" y="23.080017" textLength="4.579200" font-size="8px">3</text>
<text x="273.480621" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="231.840637" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="119.580620" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="106.022285" y="23.080017" textLength="4.579200" font-size="8px">8</text>
<text x="101.400612" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="95.280617" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="88.562538" y="23.080017" textLength="4.579200" font-size="8px">9</text>
<text x="84.000618" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="77.820610" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="203.940613" y="112.000000" textLength="4.579200" font-size="8px">2</text>
<text x="28.277992" y="73.720032" textLength="4.086000" font-size="8px">)</text>
<text x="4.087799" y="73.720032" textLength="8.757000" font-size="8px">m</text>
<text x="0.000000" y="73.720032" textLength="4.086000" font-size="8px">(</text>
<text x="18.658806" y="62.800323" textLength="5.724000" font-size="8px">2</text>
<text x="20.519096" y="17.800323" textLength="5.724000" font-size="8px">1</text>
<text x="242.700623" y="110.800018" textLength="4.579200" font-size="8px">1</text>
<text x="67.322533" y="23.080017" textLength="4.579200" font-size="8px">0</text>
<text x="1.860298" y="17.800323" textLength="6.156000" font-size="8px">S</text>
<text x="81.900002" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="125.640007" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="220.020325" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="256.260620" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="315.660614" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="40.620903" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="97.500908" y="67.179993" textLength="5.724000" font-size="8px">1</text>
<text x="120.000908" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="274.380615" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="316.860626" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="214.381226" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="46.198250" y="130.299988" textLength="5.724000" font-size="8px">3</text>
<text x="255.000916" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="219.900635" y="23.080017" textLength="4.579200" font-size="8px">6</text>
<text x="343.686005" y="127.779999" textLength="5.724000" font-size="8px">0</text>
<text x="335.640625" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="201.780640" y="23.080017" textLength="4.579200" font-size="8px">7</text>
<text x="48.842537" y="23.080017" textLength="4.579200" font-size="8px">1</text>
<text x="257.880615" y="23.080017" textLength="4.579200" font-size="8px">4</text>
<text x="12.846596" y="73.720032" textLength="5.409000" font-size="8px">a</text>
<text x="37.032646" y="130.299988" textLength="2.466000" font-size="8px">i</text>
<text x="239.401215" y="67.179993" textLength="5.724000" font-size="8px">1</text>
<text x="195.600616" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="62.760612" y="23.080017" textLength="4.579200" font-size="8px">3</text>
<text x="15.101997" y="107.800323" textLength="6.156000" font-size="8px">S</text>
<text x="238.020630" y="23.080017" textLength="4.579200" font-size="8px">5</text>
<text x="236.520630" y="108.520020" textLength="6.156000" font-size="8px">S</text>
<text x="113.460625" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="328.920624" y="127.779999" textLength="5.607000" font-size="8px">b</text>
<text x="65.640907" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="213.720612" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="39.483345" y="130.299988" textLength="3.546000" font-size="8px">t</text>
<text x="197.820618" y="109.779999" textLength="6.156000" font-size="8px">S</text>
<text x="2.519997" y="107.800323" textLength="6.939000" font-size="8px">D</text>
<text x="14.281197" y="17.800323" textLength="6.282000" font-size="8px">C</text>
<text x="12.420906" y="62.800323" textLength="6.282000" font-size="8px">C</text>
<text x="278.160309" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="47.519997" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="0.000000" y="62.800323" textLength="6.156000" font-size="8px">S</text>
<text x="319.020630" y="23.080017" textLength="4.579200" font-size="8px">1</text>
<text x="6.183907" y="62.800323" textLength="6.255000" font-size="8px">R</text>
<text x="22.948189" y="73.720032" textLength="5.328000" font-size="8px">k</text>
<text x="38.100624" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="201.241211" y="67.179993" textLength="5.724000" font-size="8px">1</text>
<text x="335.040619" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="18.257393" y="73.720032" textLength="4.689000" font-size="8px">s</text>
<text x="124.142540" y="23.080017" textLength="4.579200" font-size="8px">7</text>
<text x="9.436501" y="107.800323" textLength="5.688000" font-size="8px">E</text>
<text x="63.782097" y="108.460022" textLength="5.724000" font-size="8px">0</text>
<text x="8.044197" y="17.800323" textLength="6.255000" font-size="8px">R</text>
<text x="56.580620" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="296.880615" y="67.179993" textLength="5.724000" font-size="8px">1</text>
<text x="44.280617" y="23.080017" textLength="4.579200" font-size="8px">3</text>
<text x="82.500603" y="67.179993" textLength="5.724000" font-size="8px">0</text>
<text x="299.940613" y="111.339996" textLength="4.579200" font-size="8px">0</text>
<text x="336.968414" y="127.779999" textLength="3.546000" font-size="8px">t</text>
<text x="251.760620" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="43.014046" y="130.299988" textLength="3.168000" font-size="8px"> </text>
<text x="21.235497" y="107.800323" textLength="5.544000" font-size="8px">T</text>
</svg>
<figcaption>Figure 4-8.  PDEP Example
</figcaption></figure>
```

### Operation

```info-verb
TEMP <- SRC1;
MASK <- SRC2;
DEST <- 0 ;
m<- 0, k<- 0;
DOWHILE m< OperandSize
          IF MASK[ m] = 1 THEN
                DEST[ m] <- TEMP[ k];
               k <- k+ 1;
          FI
          m <- m+ 1;
OD
```
### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PDEP: unsigned __int32 _pdep_u32(unsigned __int32 src, unsigned __int32 mask);
PDEP: unsigned __int64 _pdep_u64(unsigned __int64 src, unsigned __int32 mask);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

