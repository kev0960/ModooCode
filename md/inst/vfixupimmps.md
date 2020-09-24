----------------------------
title : VFIXUPIMMPS (Intel x86/64 assembly instruction)
cat_title : VFIXUPIMMPS
ref_title : VFIXUPIMMPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFIXUPIMMPS

**Fix Up Special Packed Float32 Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.NDS.128.66.0F3A.W0 54 /r`\newline{}`VFIXUPIMMPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m128/m32bcst \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512VL\newline{}AVX512F|Fix up special numbers in float32 vector xmm1, float32 vector xmm2 and int32 vector xmm3/m128/m32bcst and store the result in xmm1, under writemask.|
|`EVEX.NDS.256.66.0F3A.W0 54 /r`\newline{}`VFIXUPIMMPS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} ymm3/m256/m32bcst \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512VL\newline{}AVX512F|Fix up special numbers in float32 vector ymm1, float32 vector ymm2 and int32 vector ymm3/m256/m32bcst and store the result in ymm1, under writemask.|
|`EVEX.NDS.512.66.0F3A.W0 54 /r ib`\newline{}`VFIXUPIMMPS` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 zmm3/m512/m32bcst{sae} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |FV|V/V|AVX512F|Fix up elements of float32 vector in zmm2 using int32 vector table in zmm3/m512/m32bcst, combine with preserved elements from zmm1, and store the result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (r, w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Perform fix-up of doubleword elements encoded in single-precision floating-point format in the first source operand (the second operand) using a 32-bit, two-level look-up table specified in the corresponding doubleword element of the second source operand (the third operand) with exception reporting specifier imm8. The elements that are fixed-up are selected by mask bits of 1 specified in the opmask k1. Mask bits of 0 in the opmask k1 or table response action of 0000b preserves the corresponding element of the first operand. The fixed-up elements from the first source operand and the preserved element in the first operand are combined as the final results in the destination operand (the first operand). 

The destination and the first source operands are ZMM/YMM/XMM registers. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location.

The two-level look-up table perform a fix-up of each SP FP input data in the first source operand by decoding the input data encoding into 8 token types. A response table is defined for each token type that converts the input encoding in the first source operand with one of 16 response actions. 

This instruction is specifically intended for use in fixing up the results of arithmetic calculations involving one source so that they match the spec, although it is generally useful for fixing up the results of multiple-instruction sequences to reflect special-number inputs. For example, consider rcp(0). Input 0 to rcp, and you should get INF according to the DX10 spec. However, evaluating rcp via Newton-Raphson, where x=approx(1/0), yields an incor-rect result. To deal with this, `VFIXUPIMMPS` can be used after the N-R reciprocal sequence to set the result to the correct value (i.e. INF when the input is 0).

If MXCSR.DAZ is not set, denormal input elements in the first source operand are considered as normal inputs and do not trigger any fixup nor fault reporting.

Imm8 is used to set the required flags reporting. It supports #ZE and #IE fault reporting (see details below).

MXCSR.DAZ is used and refer to zmm2 only (i.e. zmm1 is not considered as zero in case MXCSR.DAZ is set).

MXCSR mask bits are ignored and are treated as if all mask bits are set to masked response). If any of the imm8 bits is set and the condition met for fault reporting, MXCSR.IE or MXCSR.ZE might be updated.


### Operation
#### VFIXUPIMMPS (EVEX)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            DEST[i+31:i] <-  FIXUPIMM_SP(DEST[i+31:i], SRC1[i+31:i], SRC2[31:0], imm8 [7:0])
                      ELSE 
                            DEST[i+31:i] <-  FIXUPIMM_SP(DEST[i+31:i], SRC1[i+31:i], SRC2[i+31:i], imm8 [7:0])
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  DEST[i+31:i] <-  0 ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
Immediate Control Description:
```
```embed
<figure>
<svg viewBox="0 0 396.480042 223.399994">
<rect x="0.000000" y="10.000000" width="0.480000" height="196.199997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="196.199997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="206.260010" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,62.260010 L225.420013,62.260010 L225.420013,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M221.700012,53.979980 L225.420013,44.260010 L228.420013,53.979980 L221.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,80.260010 L242.700012,80.260010 L242.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M239.700012,53.979980 L242.700012,44.260010 L246.420013,53.979980 L239.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,98.260010 L260.700012,98.260010 L260.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M257.700012,53.979980 L260.700012,44.260010 L264.480011,53.979980 L257.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,116.260010 L278.700012,116.260010 L278.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M275.700012,53.979980 L278.700012,44.260010 L282.480011,53.979980 L275.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,134.260010 L296.700012,134.260010 L296.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M293.700012,53.979980 L296.700012,44.260010 L300.480011,53.979980 L293.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,152.260010 L314.700012,152.260010 L314.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M311.700012,53.979980 L314.700012,44.260010 L317.700012,53.979980 L311.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,169.479980 L332.700012,169.479980 L332.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M329.700012,53.979980 L332.700012,44.260010 L335.700012,53.979980 L329.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.420013,187.479980 L350.700012,187.479980 L350.700012,53.260010" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M347.700012,53.979980 L350.700012,44.260010 L353.700012,53.979980 L347.700012,53.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.420013" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="216.420013" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.420013" y="26.260010" width="17.280001" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="234.420013" y="26.260010" width="17.280001" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="251.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="251.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="269.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="287.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="305.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="305.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="323.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="341.700012" y="26.260010" width="18.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(250,250,250) " stroke="black" />
<rect x="341.700012" y="26.260010" width="18.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="53.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="53.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="89.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="89.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="107.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="107.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="71.260010" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="71.260010" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="125.260010" width="108.000000" height="17.219999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="125.260010" width="108.000000" height="17.219999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="142.479980" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="142.479980" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="160.479980" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="160.479980" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420006" y="178.479980" width="108.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420006" y="178.479980" width="108.000000" height="18.000000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<text x="130.919128" y="191.260010" textLength="7.201860" font-size="8px">E</text>
<text x="115.920052" y="191.260010" textLength="7.201860" font-size="8px">#</text>
<text x="84.420311" y="191.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420311" y="191.260010" textLength="0.000000" font-size="8px"> </text>
<text x="80.698174" y="191.260010" textLength="7.201860" font-size="8px"> </text>
<text x="73.198631" y="191.260010" textLength="7.201860" font-size="8px">O</text>
<text x="58.199547" y="191.260010" textLength="7.201860" font-size="8px">E</text>
<text x="50.700005" y="191.260010" textLength="7.201860" font-size="8px">Z</text>
<text x="80.698174" y="173.260010" textLength="7.201860" font-size="8px"> </text>
<text x="73.198631" y="173.260010" textLength="7.201860" font-size="8px">O</text>
<text x="65.699089" y="173.260010" textLength="7.201860" font-size="8px">R</text>
<text x="50.700005" y="173.260010" textLength="7.201860" font-size="8px">Z</text>
<text x="130.919373" y="155.260010" textLength="7.201860" font-size="8px">E</text>
<text x="123.419838" y="155.260010" textLength="7.201860" font-size="8px">Z</text>
<text x="115.920296" y="155.260010" textLength="7.201860" font-size="8px">#</text>
<text x="76.918633" y="155.260010" textLength="7.201860" font-size="8px"> </text>
<text x="69.419090" y="155.260010" textLength="7.201860" font-size="8px">E</text>
<text x="54.420006" y="155.260010" textLength="7.201860" font-size="8px">O</text>
<text x="130.919373" y="138.040039" textLength="7.201860" font-size="8px">E</text>
<text x="115.920296" y="138.040039" textLength="7.201860" font-size="8px">#</text>
<text x="84.418175" y="138.040039" textLength="7.201860" font-size="8px"> </text>
<text x="69.419090" y="138.040039" textLength="7.201860" font-size="8px">E</text>
<text x="61.919548" y="138.040039" textLength="7.201860" font-size="8px">N</text>
<text x="130.919312" y="84.040039" textLength="7.201860" font-size="8px">E</text>
<text x="123.419762" y="84.040039" textLength="7.201860" font-size="8px">I</text>
<text x="115.920219" y="84.040039" textLength="7.201860" font-size="8px">#</text>
<text x="83.699104" y="84.040039" textLength="7.201860" font-size="8px"> </text>
<text x="61.200478" y="84.040039" textLength="7.201860" font-size="8px">V</text>
<text x="45.420006" y="84.040039" textLength="7.201860" font-size="8px">-</text>
<text x="130.919128" y="120.040039" textLength="7.201860" font-size="8px">E</text>
<text x="84.420311" y="120.040039" textLength="0.000000" font-size="8px"> </text>
<text x="84.420311" y="120.040039" textLength="0.000000" font-size="8px"> </text>
<text x="80.698174" y="120.040039" textLength="7.201860" font-size="8px"> </text>
<text x="65.699089" y="120.040039" textLength="7.201860" font-size="8px">a</text>
<text x="58.199547" y="120.040039" textLength="7.201860" font-size="8px">N</text>
<text x="130.919312" y="102.040039" textLength="7.201860" font-size="8px">E</text>
<text x="84.420479" y="102.040039" textLength="0.000000" font-size="8px"> </text>
<text x="84.420479" y="102.040039" textLength="0.000000" font-size="8px"> </text>
<text x="64.919044" y="102.040039" textLength="7.201860" font-size="8px">N</text>
<text x="123.419762" y="66.040039" textLength="7.201860" font-size="8px">I</text>
<text x="84.420479" y="66.040039" textLength="0.000000" font-size="8px"> </text>
<text x="84.420479" y="66.040039" textLength="0.000000" font-size="8px"> </text>
<text x="79.918129" y="66.040039" textLength="7.201860" font-size="8px"> </text>
<text x="45.420006" y="102.040039" textLength="7.201860" font-size="8px">-</text>
<text x="349.980011" y="39.040039" textLength="6.673724" font-size="8px">0</text>
<text x="331.980011" y="39.040039" textLength="6.673724" font-size="8px">1</text>
<text x="313.980011" y="39.040039" textLength="6.673724" font-size="8px">2</text>
<text x="277.980011" y="39.040039" textLength="6.673724" font-size="8px">4</text>
<text x="259.980011" y="39.040039" textLength="6.673724" font-size="8px">5</text>
<text x="57.419502" y="66.040039" textLength="7.201860" font-size="8px">I</text>
<text x="79.918129" y="102.040039" textLength="7.201860" font-size="8px"> </text>
<text x="50.700005" y="120.040039" textLength="7.201860" font-size="8px">S</text>
<text x="84.420555" y="137.259949" textLength="0.000000" font-size="8px"> </text>
<text x="84.420555" y="137.259949" textLength="0.000000" font-size="8px"> </text>
<text x="130.919128" y="173.260010" textLength="7.201860" font-size="8px">E</text>
<text x="123.419838" y="138.040039" textLength="7.201860" font-size="8px">I</text>
<text x="223.980011" y="39.040039" textLength="6.673724" font-size="8px">7</text>
<text x="58.199547" y="173.260010" textLength="7.201860" font-size="8px">E</text>
<text x="241.980011" y="39.040039" textLength="6.673724" font-size="8px">6</text>
<text x="45.420006" y="66.040039" textLength="7.201860" font-size="8px">+</text>
<text x="73.198631" y="120.040039" textLength="7.201860" font-size="8px">N</text>
<text x="72.418587" y="102.040039" textLength="7.201860" font-size="8px">F</text>
<text x="115.920219" y="102.040039" textLength="7.201860" font-size="8px">#</text>
<text x="130.919312" y="66.040039" textLength="7.201860" font-size="8px">E</text>
<text x="64.919044" y="66.040039" textLength="7.201860" font-size="8px">N</text>
<text x="123.419594" y="173.260010" textLength="7.201860" font-size="8px">I</text>
<text x="76.918633" y="138.040039" textLength="7.201860" font-size="8px"> </text>
<text x="115.920052" y="173.260010" textLength="7.201860" font-size="8px">#</text>
<text x="54.420006" y="138.040039" textLength="7.201860" font-size="8px">O</text>
<text x="84.420555" y="155.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420555" y="155.260010" textLength="0.000000" font-size="8px"> </text>
<text x="123.419594" y="120.040039" textLength="7.201860" font-size="8px">I</text>
<text x="115.920219" y="66.040039" textLength="7.201860" font-size="8px">#</text>
<text x="61.919548" y="155.260010" textLength="7.201860" font-size="8px">N</text>
<text x="295.980011" y="39.040039" textLength="6.673724" font-size="8px">3</text>
<text x="84.420311" y="173.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420311" y="173.260010" textLength="0.000000" font-size="8px"> </text>
<text x="84.420479" y="84.040039" textLength="0.000000" font-size="8px"> </text>
<text x="84.420479" y="84.040039" textLength="0.000000" font-size="8px"> </text>
<text x="57.419502" y="102.040039" textLength="7.201860" font-size="8px">I</text>
<text x="65.699089" y="191.260010" textLength="7.201860" font-size="8px">R</text>
<text x="123.419594" y="191.260010" textLength="7.201860" font-size="8px">Z</text>
<text x="68.700020" y="84.040039" textLength="7.201860" font-size="8px">E</text>
<text x="84.418175" y="155.260010" textLength="7.201860" font-size="8px"> </text>
<text x="76.199562" y="84.040039" textLength="7.201860" font-size="8px"> </text>
<text x="123.419762" y="102.040039" textLength="7.201860" font-size="8px">I</text>
<text x="72.418587" y="66.040039" textLength="7.201860" font-size="8px">F</text>
<text x="115.920052" y="120.040039" textLength="7.201860" font-size="8px">#</text>
</svg>
<figcaption>Figure 5-10.  VFIXUPIMMPS Immediate Control Description
</figcaption></figure>
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFIXUPIMMPS __m512 _mm512_fixupimm_ps( __m512 a, __m512i tbl, int imm);
VFIXUPIMMPS __m512 _mm512_mask_fixupimm_ps(__m512 s, __mmask16 k, __m512 a, __m512i tbl, int imm);
VFIXUPIMMPS __m512 _mm512_maskz_fixupimm_ps( __mmask16 k, __m512 a, __m512i tbl, int imm);
VFIXUPIMMPS __m512 _mm512_fixupimm_round_ps( __m512 a, __m512i tbl, int imm, int sae);
VFIXUPIMMPS __m512 _mm512_mask_fixupimm_round_ps(__m512 s, __mmask16 k, __m512 a, __m512i tbl, int imm, int sae);
VFIXUPIMMPS __m512 _mm512_maskz_fixupimm_round_ps( __mmask16 k, __m512 a, __m512i tbl, int imm, int sae);
VFIXUPIMMPS __m256 _mm256_fixupimm_ps( __m256 a, __m256i tbl, int imm);
VFIXUPIMMPS __m256 _mm256_mask_fixupimm_ps(__m256 s, __mmask8 k, __m256 a, __m256i tbl, int imm);
VFIXUPIMMPS __m256 _mm256_maskz_fixupimm_ps( __mmask8 k, __m256 a, __m256i tbl, int imm);
VFIXUPIMMPS __m128 _mm_fixupimm_ps( __m128 a, __m128i tbl, int imm);
VFIXUPIMMPS __m128 _mm_mask_fixupimm_ps(__m128 s, __mmask8 k, __m128 a, __m128i tbl, int imm);
VFIXUPIMMPS __m128 _mm_maskz_fixupimm_ps( __mmask8 k, __m128 a, __m128i tbl, int imm);
```
### SIMD Floating-Point Exceptions


Zero, Invalid

### Other Exceptions


See Exceptions Type E2.

