----------------------------
title : PSRLW, PSRLD, PSRLQs (Intel x86/64 assembly instruction)
cat_title : PSRLW, PSRLD, PSRLQ
ref_title : PSRLW, PSRLD, PSRLQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSRLW, PSRLD, PSRLQ

**Shift Packed Data Right Logical**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F D1 /r\footnote{1}`\newline{}`PSRLW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Shift words in mm right by amount specified in mm/m64 while shifting in 0s.|
|`66 0F D1 /r`\newline{}`PSRLW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Shift words in xmm1 right by amount specified in xmm2/m128 while shifting in 0s.|
|`0F 71 /2 ib\footnote{1}`\newline{}`PSRLW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|MMX|Shift words in mm right by imm8 while shifting in 0s.|
|`66 0F 71 /2 ib`\newline{}`PSRLW` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|SSE2|Shift words in xmm1 right by imm8 while shifting in 0s.|
|`0F D2 /r\footnote{1}`\newline{}`PSRLD` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Shift doublewords in mm right by amount specified in mm/m64 while shifting in 0s.|
|`66 0F D2 /r`\newline{}`PSRLD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Shift doublewords in xmm1 right by amount specified in xmm2 /m128 while shifting in 0s.|
|`0F 72 /2 ib\footnote{1}`\newline{}`PSRLD` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|MMX|Shift doublewords in mm right by imm8 while shifting in 0s.|
|`66 0F 72 /2 ib`\newline{}`PSRLD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|SSE2|Shift doublewords in xmm1 right by imm8 while shifting in 0s.|
|`0F D3 /r\footnote{1}`\newline{}`PSRLQ` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Shift mm right by amount specified in mm/m64 while shifting in 0s.|
|`66 0F D3 /r`\newline{}`PSRLQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Shift quadwords in xmm1 right by amount specified in xmm2/m128 while shifting in 0s.|
|`0F 73 /2 ib\footnote{1}`\newline{}`PSRLQ` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|MMX|Shift mm right by imm8 while shifting in0s.|
|`66 0F 73 /2 ib`\newline{}`PSRLQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|V/V|SSE2|Shift quadwords in xmm1 right by imm8 while shifting in 0s.|
|`VEX.NDS.128.66.0F.WIG D1 /r`\newline{}VPSRLW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in 0s.|
|`VEX.NDD.128.66.0F.WIG 71 /2 ib`\newline{}VPSRLW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |VMI|V/V|AVX|Shift words in xmm2 right by imm8 while shifting in 0s.|
|`VEX.NDS.128.66.0F.WIG D2 /r`\newline{}VPSRLD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s.|
|`VEX.NDD.128.66.0F.WIG 72 /2 ib`\newline{}VPSRLD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |VMI|V/V|AVX|Shift doublewords in xmm2 right by imm8 while shifting in 0s.|
|`VEX.NDS.128.66.0F.WIG D3 /r`\newline{}VPSRLQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Shift quadwords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s.|
|`VEX.NDD.128.66.0F.WIG 73 /2 ib`\newline{}VPSRLQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |VMI|V/V|AVX|Shift quadwords in xmm2 right by imm8 while shifting in 0s.|
|`VEX.NDS.256.66.0F.WIG D1 /r`\newline{}VPSRLW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX2|Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in 0s.|
|`VEX.NDD.256.66.0F.WIG 71 /2 ib`\newline{}VPSRLW \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |VMI|V/V|AVX2|Shift words in ymm2 right by imm8 while shifting in 0s.|


|VEX.NDS.256.66.0F.WIG D2 /r\newline{}VPSRLD ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift doublewords in ymm2 right by amount \newline{}specified in xmm3/m128 while shifting in 0s.|
|-----------------------------------------------------------------|---|---|----|------------------------------------------------------------------------------------------------|
|VEX.NDD.256.66.0F.WIG 72 /2 ib\newline{}VPSRLD ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift doublewords in ymm2 right by imm8 while shifting in 0s.|
|VEX.NDS.256.66.0F.WIG D3 /r\newline{}VPSRLQ ymm1, ymm2, xmm3/m128|RVM|V/V|AVX2|Shift quadwords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s.|
|VEX.NDD.256.66.0F.WIG 73 /2 ib\newline{}VPSRLQ ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift quadwords in ymm2 right by imm8 while shifting in 0s.|
|EVEX.NDS.128.66.0F.WIG D1 /rVPSRLW xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512BW|Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F.WIG D1 /rVPSRLW ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512BW|Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F.WIG D1 /rVPSRLW zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512BW|Shift words in zmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDD.128.66.0F.WIG 71 /2 ibVPSRLW xmm1 {k1}{z}, xmm2/m128, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Shift words in xmm2/m128 right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.256.66.0F.WIG 71 /2 ibVPSRLW ymm1 {k1}{z}, ymm2/m256, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Shift words in ymm2/m256 right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.512.66.0F.WIG 71 /2 ibVPSRLW zmm1 {k1}{z}, zmm2/m512, imm8|FVM|V/V|AVX512BW|Shift words in zmm2/m512 right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDS.128.66.0F.W0 D2 /rVPSRLD xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F.W0 D2 /rVPSRLD ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F.W0 D2 /rVPSRLD zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512F|Shift doublewords in zmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDD.128.66.0F.W0 72 /2 ibVPSRLD xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in xmm2/m128/m32bcst right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.256.66.0F.W0 72 /2 ibVPSRLD ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Shift doublewords in ymm2/m256/m32bcst right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.512.66.0F.W0 72 /2 ibVPSRLD zmm1 {k1}{z}, zmm2/m512/m32bcst, imm8|FVI|V/V|AVX512F|Shift doublewords in zmm2/m512/m32bcst right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDS.128.66.0F.W1 D3 /rVPSRLQ xmm1 {k1}{z}, xmm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.256.66.0F.W1 D3 /rVPSRLQ ymm1 {k1}{z}, ymm2, xmm3/m128|M128|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|
|EVEX.NDS.512.66.0F.W1 D3 /rVPSRLQ zmm1 {k1}{z}, zmm2, xmm3/m128|M128|V/V|AVX512F|Shift quadwords in zmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.|


|EVEX.NDD.128.66.0F.W1 73 /2 ib\newline{}VPSRLQ xmm1 {k1}{z}, xmm2/m128/m64bcst, \newline{}imm8|FV|V/V|AVX512VL\newline{}\newline{}AVX512F|Shift quadwords in xmm2/m128/m64bcst \newline{}right by imm8 while shifting in 0s using \newline{}writemask k1.|
|----------------------------------------------------------------------------------------------|--|---|-----------------------------------|---------------------------------------------------------------------------------------------------------------|
|EVEX.NDD.256.66.0F.W1 73 /2 ibVPSRLQ ymm1 {k1}{z}, ymm2/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Shift quadwords in ymm2/m256/m64bcst right by imm8 while shifting in 0s using writemask k1.|
|EVEX.NDD.512.66.0F.W1 73 /2 ibVPSRLQ zmm1 {k1}{z}, zmm2/m512/m64bcst, imm8|FVI|V/V|AVX512F|Shift quadwords in zmm2/m512/m64bcst right by imm8 while shifting in 0s using writemask k1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|MI|ModRM:r/m (r, w)|imm8|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|VMI|VEX.vvvv (w)|ModRM:r/m (r)|imm8|NA|
|FVM|EVEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
|FVI|EVEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
|M128|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Shifts the bits in the individual data elements (words, doublewords, or quadword) in the destination operand (first operand) to the right by the number of bits specified in the count operand (second operand). As the bits in the data elements are shifted right, the empty high-order bits are cleared (set to 0). If the value specified by the count operand is greater than 15 (for words), 31 (for doublewords), or 63 (for a quadword), then the destination operand is set to all 0s. Figure 4-19 gives an example of shifting words in a 64-bit operand. 

Note that only the low 64-bits of a 128-bit count operand are checked to compute the count.

The (V)PSRLW instruction shifts each of the words in the destination operand to the right by the number of bits specified in the count operand; the (V)PSRLD instruction shifts each of the doublewords in the destination operand; and the `PSRLQ` instruction shifts the quadword (or quadwords) in the destination operand.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

Legacy SSE instruction 64-bit operand: The destination operand is an MMX technology register; the count operand can be either an MMX technology register or an 64-bit memory location.

```embed
<figure>
<svg viewBox="0 0 379.679993 109.820007">
<rect x="0.000000" y="10.000000" width="0.480000" height="87.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="87.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="97.659988" width="379.679993" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.559998" y="20.859985" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="82.559998" y="20.619965" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.199997" y="20.859985" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.320007" y="38.619995" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="82.320007" y="20.619995" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.439987" y="20.859985" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="145.439987" y="20.619965" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.080002" y="20.859985" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.199997" y="38.619995" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="145.199997" y="20.619995" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.319992" y="20.859985" width="62.939999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.319992" y="20.619965" width="63.180000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="20.859985" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.080002" y="38.619995" width="63.180000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="208.080002" y="20.619995" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.260010" y="20.859985" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="271.260010" y="20.619965" width="63.119999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="333.900024" y="20.859985" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="38.619995" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="20.619995" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.960007" y="73.899994" width="62.939999" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="81.960007" y="73.659988" width="63.180000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.659988" y="73.899979" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.720001" y="91.659988" width="63.180000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="81.720001" y="73.659988" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.900009" y="73.899994" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="144.900009" y="73.659988" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.539993" y="73.899979" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.659988" y="91.659988" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.659988" y="73.659988" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.780014" y="73.899994" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.780014" y="73.659988" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.419983" y="73.899979" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.539993" y="91.659988" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.539993" y="73.659988" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.659973" y="73.899994" width="62.880001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="270.659973" y="73.659988" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="333.299988" y="73.899979" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.419983" y="91.659988" width="63.119999" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.419983" y="73.659988" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="308.400024" y="66.459991" width="0.479980" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.460022,67.059998 L310.020020,66.520004 L310.979980,66.160004 L310.679993,67.179993 L309.119995,72.520004 L308.640015,74.139999 L308.160034,72.520004 L306.600037,67.179993 L306.299988,66.160004 L307.260010,66.520004 L307.559998,66.880005 L309.119995,72.220001 L308.160034,72.520004 L308.160034,72.220001 L309.720032,66.880005 L310.679993,67.179993 L310.380005,67.479996 L308.820007,68.020004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.260010,66.519989 L308.820007,67.059982 L308.820007,68.019989 L308.640015,68.079987 L308.460022,68.019989 L306.900024,67.479996" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.640015,67.539993 L310.200012,67.000000 L308.640015,72.339996 L307.080017,67.000000" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.659973" y="39.099991" width="0.479980" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.900024" y="53.559998" width="25.980000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="308.400024" y="53.800003" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.240005" y="66.459991" width="0.480010" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.300003,67.059998 L127.800003,66.459991 L128.760010,66.039993 L126.960007,72.520004 L126.479996,74.199997 L126.000000,72.520004 L124.440002,67.119995 L124.139999,66.099991 L125.100006,66.459991 L125.400009,66.819992 L126.960007,72.220001 L126.000000,72.520004 L126.000000,72.220001 L127.500000,66.819992 L128.460007,67.119995 L128.160004,67.419998 L126.660004,68.020004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.100006,66.459991 L126.660004,67.059998 L126.660004,68.019989 L126.480011,68.079987 L126.300003,68.019989 L124.740005,67.419998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.479996,67.539993 L127.979996,66.939987 L126.479996,72.339996 L124.919998,66.939987" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="100.500000" y="39.099991" width="0.480000" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="100.740005" y="53.559998" width="25.980000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="126.240005" y="53.800003" width="0.480010" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.960007" y="66.399994" width="0.479980" height="1.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.020004,66.999985 L191.520004,66.459991 L192.479996,66.039978 L192.180008,67.119980 L190.680008,72.459991 L190.199997,74.079987 L189.720016,72.459991 L188.160019,67.119980 L187.860001,66.099991 L188.819992,66.459991 L189.120010,66.819992 L190.680008,72.159988 L189.720016,72.459991 L189.720016,72.159988 L191.220016,66.819992 L192.180008,67.119980 L191.879990,67.419983 L190.379990,67.959991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.819992,66.459991 L190.379990,66.999985 L190.379990,67.959991 L190.199997,68.019989 L190.020004,67.959991 L188.460007,67.419998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M190.199997,67.479996 L191.699997,66.940002 L190.199997,72.279999 L188.639999,66.940002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.219986" y="39.039993" width="0.479980" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="164.460007" y="53.500000" width="25.980000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="189.960007" y="53.739990" width="0.479980" height="12.900000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659988" y="66.939987" width="0.479980" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.719986,67.479996 L248.279984,66.940002 L249.239975,66.580002 L248.939987,67.599991 L247.379990,73.000000 L246.899979,74.739990 L246.419998,73.000000 L244.919998,67.599991 L244.619980,66.580002 L245.579971,66.940002 L245.879990,67.300003 L247.379990,72.699997 L246.419998,73.000000 L246.419998,72.699997 L247.979996,67.300003 L248.939987,67.599991 L248.639999,67.899994 L247.079971,68.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M245.580002,66.939987 L247.080002,67.479980 L247.080002,68.439987 L246.900009,68.499985 L246.720016,68.439987 L245.220016,67.899994" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.900009,67.959991 L248.460007,67.419998 L246.900009,72.819992 L245.400009,67.419998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="220.979996" y="39.519989" width="0.480010" height="14.940000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.219986" y="53.979996" width="25.920000" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="246.659988" y="54.219986" width="0.479980" height="12.960000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="74.705780" y="65.680069" textLength="3.695760" font-size="8px">n</text>
<text x="66.362122" y="65.680069" textLength="3.104160" font-size="8px">s</text>
<text x="59.036728" y="65.680069" textLength="3.647040" font-size="8px">e</text>
<text x="68.339478" y="57.879990" textLength="3.647040" font-size="8px">e</text>
<text x="62.761032" y="57.879990" textLength="1.719120" font-size="8px"> </text>
<text x="49.559998" y="57.879990" textLength="5.373120" font-size="8px">w</text>
<text x="135.537369" y="86.859985" textLength="4.882501" font-size="8px">T</text>
<text x="129.779053" y="86.859985" textLength="5.769502" font-size="8px">N</text>
<text x="104.279831" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="92.093307" y="86.859985" textLength="4.442996" font-size="8px">3</text>
<text x="86.760117" y="86.859985" textLength="5.329997" font-size="8px">X</text>
<text x="199.272568" y="86.859985" textLength="4.882501" font-size="8px">T</text>
<text x="193.514267" y="86.859985" textLength="5.769502" font-size="8px">N</text>
<text x="168.000076" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="160.318893" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="150.540298" y="86.859985" textLength="5.329997" font-size="8px">X</text>
<text x="236.759995" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="231.240097" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="225.780014" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="219.113724" y="86.859985" textLength="4.442996" font-size="8px">1</text>
<text x="213.780533" y="86.859985" textLength="5.329997" font-size="8px">X</text>
<text x="238.859512" y="33.100525" textLength="4.442996" font-size="8px">1</text>
<text x="177.840225" y="33.100525" textLength="4.442996" font-size="8px">2</text>
<text x="172.499832" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="114.121567" y="33.100525" textLength="4.442996" font-size="8px">3</text>
<text x="108.781189" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="317.339050" y="86.859985" textLength="5.769502" font-size="8px">N</text>
<text x="311.580750" y="86.859985" textLength="5.769502" font-size="8px">U</text>
<text x="305.399719" y="86.859985" textLength="6.216998" font-size="8px">O</text>
<text x="299.581482" y="86.859985" textLength="5.769502" font-size="8px">C</text>
<text x="291.899841" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="286.380005" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="284.159546" y="86.859436" textLength="2.221498" font-size="8px"> </text>
<text x="274.380127" y="86.859436" textLength="5.329997" font-size="8px">X</text>
<text x="301.079651" y="33.099976" textLength="4.442996" font-size="8px">0</text>
<text x="295.799988" y="33.099976" textLength="5.329997" font-size="8px">X</text>
<text x="75.664658" y="50.619995" textLength="2.610000" font-size="8px">t</text>
<text x="72.062851" y="50.619995" textLength="3.695760" font-size="8px">h</text>
<text x="68.477753" y="50.619995" textLength="3.605280" font-size="8px">g</text>
<text x="66.976486" y="50.619995" textLength="1.510320" font-size="8px">i</text>
<text x="62.716965" y="50.619995" textLength="4.196880" font-size="8px">R</text>
<text x="54.257095" y="50.619995" textLength="1.510320" font-size="8px">i</text>
<text x="46.860001" y="50.619995" textLength="3.695760" font-size="8px">S</text>
<text x="71.508484" y="81.879379" textLength="1.774002" font-size="8px">i</text>
<text x="67.057495" y="81.879379" textLength="4.442996" font-size="8px">h</text>
<text x="59.050522" y="81.879379" textLength="2.661003" font-size="8px">-</text>
<text x="52.868683" y="81.879379" textLength="3.995500" font-size="8px">s</text>
<text x="48.417694" y="81.879379" textLength="4.442996" font-size="8px">o</text>
<text x="76.740189" y="29.019714" textLength="2.221498" font-size="8px">t</text>
<text x="74.578629" y="29.019714" textLength="2.221498" font-size="8px">f</text>
<text x="72.839783" y="29.019714" textLength="1.774002" font-size="8px">i</text>
<text x="68.397583" y="29.019714" textLength="4.442996" font-size="8px">h</text>
<text x="63.068390" y="29.019714" textLength="5.329997" font-size="8px">S</text>
<text x="60.428162" y="29.019714" textLength="2.661003" font-size="8px">-</text>
<text x="55.929230" y="29.019714" textLength="4.442996" font-size="8px">e</text>
<text x="47.939835" y="29.019714" textLength="5.329997" font-size="8px">P</text>
<text x="74.883881" y="37.299988" textLength="4.882501" font-size="8px">T</text>
<text x="64.214294" y="37.299988" textLength="5.329997" font-size="8px">E</text>
<text x="58.440002" y="37.299988" textLength="5.769502" font-size="8px">D</text>
<text x="68.498718" y="89.859985" textLength="5.329997" font-size="8px">S</text>
<text x="63.219070" y="89.859985" textLength="5.329997" font-size="8px">E</text>
<text x="57.419998" y="89.859985" textLength="5.769502" font-size="8px">D</text>
<text x="162.539993" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="61.037521" y="50.619995" textLength="1.719120" font-size="8px"> </text>
<text x="54.958176" y="57.879990" textLength="1.510320" font-size="8px">i</text>
<text x="52.690598" y="65.680069" textLength="3.702720" font-size="8px">x</text>
<text x="279.713318" y="86.859436" textLength="4.442996" font-size="8px">0</text>
<text x="323.157288" y="86.859985" textLength="4.882501" font-size="8px">T</text>
<text x="173.520004" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="98.759995" y="86.859985" textLength="5.468040" font-size="8px">></text>
<text x="187.696030" y="86.859985" textLength="5.769502" font-size="8px">U</text>
<text x="96.539505" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="109.740005" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="262.494202" y="86.859985" textLength="4.882501" font-size="8px">T</text>
<text x="49.019897" y="65.680069" textLength="3.654000" font-size="8px">E</text>
<text x="62.700470" y="65.680069" textLength="3.695760" font-size="8px">n</text>
<text x="181.495010" y="86.859985" textLength="6.216998" font-size="8px">O</text>
<text x="71.044815" y="65.680069" textLength="3.654000" font-size="8px">o</text>
<text x="64.500336" y="57.879990" textLength="4.008960" font-size="8px">Z</text>
<text x="55.818222" y="50.619995" textLength="2.582160" font-size="8px">f</text>
<text x="73.858276" y="89.859985" textLength="4.882501" font-size="8px">T</text>
<text x="250.961594" y="86.859985" textLength="5.769502" font-size="8px">U</text>
<text x="74.400940" y="57.879990" textLength="3.654000" font-size="8px">o</text>
<text x="175.741501" y="86.859985" textLength="5.769502" font-size="8px">C</text>
<text x="123.960800" y="86.859985" textLength="5.769502" font-size="8px">U</text>
<text x="58.397598" y="50.619995" textLength="2.610000" font-size="8px">t</text>
<text x="233.519119" y="33.100525" textLength="5.329997" font-size="8px">X</text>
<text x="56.410019" y="65.680069" textLength="2.610000" font-size="8px">t</text>
<text x="43.079712" y="81.879379" textLength="5.329997" font-size="8px">P</text>
<text x="61.719513" y="81.879379" textLength="5.329997" font-size="8px">S</text>
<text x="69.549088" y="37.299988" textLength="5.329997" font-size="8px">S</text>
<text x="56.829025" y="81.879379" textLength="2.221498" font-size="8px">t</text>
<text x="53.269028" y="29.019714" textLength="2.661003" font-size="8px">r</text>
<text x="69.483688" y="65.680069" textLength="1.510320" font-size="8px">i</text>
<text x="75.408890" y="81.879379" textLength="2.221498" font-size="8px">t</text>
<text x="111.961502" y="86.859985" textLength="5.769502" font-size="8px">C</text>
<text x="59.039520" y="57.879990" textLength="3.695760" font-size="8px">h</text>
<text x="73.247330" y="81.879379" textLength="2.221498" font-size="8px">f</text>
<text x="223.559921" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="256.727905" y="86.859985" textLength="5.769502" font-size="8px">N</text>
<text x="117.779755" y="86.859985" textLength="6.216998" font-size="8px">O</text>
<text x="155.819962" y="86.859985" textLength="4.442996" font-size="8px">2</text>
<text x="238.981491" y="86.859985" textLength="5.769502" font-size="8px">C</text>
<text x="50.535583" y="50.619995" textLength="3.695760" font-size="8px">h</text>
<text x="244.747787" y="86.859985" textLength="6.216998" font-size="8px">O</text>
<text x="297.359985" y="86.859985" textLength="2.221498" font-size="8px"> </text>
<text x="56.459442" y="57.879990" textLength="2.610000" font-size="8px">t</text>
<text x="71.999741" y="57.879990" textLength="2.526480" font-size="8px">r</text>
</svg>
<figcaption>Figure 4-19.  PSRLW, PSRLD, and PSRLQ Instruction Operation Using 64-bit Operand
</figcaption></figure>
```


128-bit Legacy SSE version: The destination operand is an XMM register; the count operand can be either an XMM register or a 128-bit memory location, or an 8-bit immediate. If the count operand is a memory address, 128 bits are loaded but the upper 64 bits are ignored. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The destination operand is an XMM register; the count operand can be either an XMM register or a 128-bit memory location, or an 8-bit immediate. If the count operand is a memory address, 128 bits are loaded but the upper 64 bits are ignored. Bits (VLMAX-1:128) of the destination YMM register are zeroed.

VEX.256 encoded version: The destination operand is a YMM register. The source operand is a YMM register or a memory location. The count operand can come either from an XMM register or a memory location or an 8-bit imme-diate. Bits (MAX_VL-1:256) of the corresponding ZMM register are zeroed.

EVEX encoded versions: The destination operand is a ZMM register updated according to the writemask. The count operand is either an 8-bit immediate (the immediate count version) or an 8-bit value from an XMM register or a memory location (the variable count version). For the immediate count version, the source operand (the second operand) can be a ZMM register, a 512-bit memory location or a 512-bit vector broadcasted from a 32/64-bit memory location. For the variable count version, the first source operand (the second operand) is a ZMM register, the second source operand (the third operand, 8-bit variable count) can be an XMM register or a memory location.

Note: In VEX/EVEX encoded versions of shifts with an immediate count, vvvv of VEX/EVEX encode the destination register, and VEX.B/EVEX.B + ModRM.r/m encodes the source register.

Note: For shifts with an immediate count (VEX.128.66.0F 71-73 /2, or EVEX.128.66.0F 71-73 /2), VEX.vvvv/EVEX.vvvv encodes the destination register.


### Operation
#### PSRLW (with 64-bit operand)
```info-verb
    IF (COUNT > 15)
    THEN 
          DEST[64:0] <- 0000000000000000H
    ELSE
          DEST[15:0] <- ZeroExtend(DEST[15:0] >> COUNT);
          (* Repeat shift operation for 2nd and 3rd words *)
          DEST[63:48] <- ZeroExtend(DEST[63:48] >> COUNT);
    FI;
```
#### PSRLD (with 64-bit operand)
```info-verb
    IF (COUNT > 31)
    THEN 
          DEST[64:0] <- 0000000000000000H
    ELSE
          DEST[31:0] <- ZeroExtend(DEST[31:0] >> COUNT);
          DEST[63:32] <- ZeroExtend(DEST[63:32] >> COUNT);
    FI;
```
#### PSRLQ (with 64-bit operand)
```info-verb
    IF (COUNT > 63)
    THEN 
          DEST[64:0] <- 0000000000000000H
    ELSE
          DEST <- ZeroExtend(DEST >> COUNT);
    FI;
LOGICAL_RIGHT_SHIFT_DWORDS1(SRC, COUNT_SRC)
COUNT <-  COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[31:0] <-  0
ELSE
DEST[31:0] <-  ZeroExtend(SRC[31:0] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_QWORDS1(SRC, COUNT_SRC)
COUNT <-  COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[63:0] <-  0
ELSE
    DEST[63:0] <-  ZeroExtend(SRC[63:0] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 15)
THEN
    DEST[255:0] <- 0
ELSE
    DEST[15:0] <- ZeroExtend(SRC[15:0] >> COUNT);
    (* Repeat shift operation for 2nd through 15th words *)
    DEST[255:240] <- ZeroExtend(SRC[255:240] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_WORDS(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 15)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
ELSE
    DEST[15:0] <- ZeroExtend(SRC[15:0] >> COUNT);
    (* Repeat shift operation for 2nd through 7th words *)
    DEST[127:112] <- ZeroExtend(SRC[127:112] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_DWORDS_256b(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[255:0] <- 0
ELSE
    DEST[31:0] <- ZeroExtend(SRC[31:0] >> COUNT);
    (* Repeat shift operation for 2nd through 3rd words *)
    DEST[255:224] <- ZeroExtend(SRC[255:224] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_DWORDS(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 31)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
ELSE
    DEST[31:0] <- ZeroExtend(SRC[31:0] >> COUNT);
    (* Repeat shift operation for 2nd through 3rd words *)
    DEST[127:96] <- ZeroExtend(SRC[127:96] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[255:0] <- 0
ELSE
    DEST[63:0] <- ZeroExtend(SRC[63:0] >> COUNT);
    DEST[127:64] <- ZeroExtend(SRC[127:64] >> COUNT);
    DEST[191:128] <- ZeroExtend(SRC[191:128] >> COUNT);
    DEST[255:192] <- ZeroExtend(SRC[255:192] >> COUNT);
FI;
LOGICAL_RIGHT_SHIFT_QWORDS(SRC, COUNT_SRC)
COUNT <- COUNT_SRC[63:0];
IF (COUNT > 63)
THEN
    DEST[127:0] <- 00000000000000000000000000000000H
ELSE
    DEST[63:0] <- ZeroExtend(SRC[63:0] >> COUNT);
    DEST[127:64] <- ZeroExtend(SRC[127:64] >> COUNT);
FI;
```
#### VPSRLW (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[511:256], SRC2)
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSRLW (EVEX versions, imm8)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_128b(SRC1[127:0], imm8)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], imm8)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[255:0], imm8)
    TMP_DEST[511:256] <-  LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1[511:256], imm8)
FI;
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  TMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+15:i] = 0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSRLW (ymm, ymm, xmm/m128) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLW (ymm, imm8) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_RIGHT_SHIFT_WORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLW (xmm, xmm, xmm/m128) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_WORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPSRLW (xmm, imm8) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_WORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <- 0
```
#### PSRLW (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_WORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSRLW (xmm, imm8)
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_WORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSRLD (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_RIGHT_SHIFT_DWORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_DWORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_DWORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <-  LOGICAL_RIGHT_SHIFT_DWORDS_256b(SRC1[511:256], SRC2)
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSRLD (EVEX versions, imm8)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+31:i] <-  LOGICAL_RIGHT_SHIFT_DWORDS1(SRC1[31:0], imm8)
                      ELSE DEST[i+31:i] <-  LOGICAL_RIGHT_SHIFT_DWORDS1(SRC1[i+31:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+31:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSRLD (ymm, ymm, xmm/m128) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_RIGHT_SHIFT_DWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLD (ymm, imm8) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_RIGHT_SHIFT_DWORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLD (xmm, xmm, xmm/m128) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_DWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPSRLD (xmm, imm8) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_DWORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <- 0
```
#### PSRLD (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_DWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSRLD (xmm, imm8)
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_DWORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```
#### VPSRLQ (EVEX versions, xmm/m128)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1[255:0], SRC2)
TMP_DEST[511:256] <-  LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1[511:256], SRC2)
IF VL = 128
    TMP_DEST[127:0] <-  LOGICAL_RIGHT_SHIFT_QWORDS_128b(SRC1[127:0], SRC2)
FI;
IF VL = 256
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1[255:0], SRC2)
FI;
IF VL = 512
    TMP_DEST[255:0] <-  LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1[255:0], SRC2)
    TMP_DEST[511:256] <-  LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1[511:256], SRC2)
FI;
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  TMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSRLQ (EVEX versions, imm8)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask* THEN
                IF (EVEX.b = 1) AND (SRC1 *is memory*)
                      THEN DEST[i+63:i] <-  LOGICAL_RIGHT_SHIFT_QWORDS1(SRC1[63:0], imm8)
                      ELSE DEST[i+63:i] <-  LOGICAL_RIGHT_SHIFT_QWORDS1(SRC1[i+63:i], imm8)
                FI;
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking 
                            DEST[i+63:i] <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPSRLQ (ymm, ymm, xmm/m128) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1, SRC2)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLQ (ymm, imm8) - VEX.256 encoding
```info-verb
DEST[255:0] <- LOGICAL_RIGHT_SHIFT_QWORDS_256b(SRC1, imm8)
DEST[MAX_VL-1:256] <- 0;
```
#### VPSRLQ (xmm, xmm, xmm/m128) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_QWORDS(SRC1, SRC2)
DEST[MAX_VL-1:128] <- 0
```
#### VPSRLQ (xmm, imm8) - VEX.128 encoding
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_QWORDS(SRC1, imm8)
DEST[MAX_VL-1:128] <- 0
```
#### PSRLQ (xmm, xmm, xmm/m128)
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_QWORDS(DEST, SRC)
DEST[MAX_VL-1:128] (Unmodified)
```
#### PSRLQ (xmm, imm8)
```info-verb
DEST[127:0] <- LOGICAL_RIGHT_SHIFT_QWORDS(DEST, imm8)
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
VPSRLD __m512i _mm512_srli_epi32(__m512i a, unsigned int imm);
VPSRLD __m512i _mm512_mask_srli_epi32(__m512i s, __mmask16 k, __m512i a, unsigned int imm);
VPSRLD __m512i _mm512_maskz_srli_epi32( __mmask16 k, __m512i a, unsigned int imm);
VPSRLD __m256i _mm256_mask_srli_epi32(__m256i s, __mmask8 k, __m256i a, unsigned int imm);
VPSRLD __m256i _mm256_maskz_srli_epi32( __mmask8 k, __m256i a, unsigned int imm);
VPSRLD __m128i _mm_mask_srli_epi32(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSRLD __m128i _mm_maskz_srli_epi32( __mmask8 k, __m128i a, unsigned int imm);
VPSRLD __m512i _mm512_srl_epi32(__m512i a, __m128i cnt);
VPSRLD __m512i _mm512_mask_srl_epi32(__m512i s, __mmask16 k, __m512i a, __m128i cnt);
VPSRLD __m512i _mm512_maskz_srl_epi32( __mmask16 k, __m512i a, __m128i cnt);
VPSRLD __m256i _mm256_mask_srl_epi32(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSRLD __m256i _mm256_maskz_srl_epi32( __mmask8 k, __m256i a, __m128i cnt);
VPSRLD __m128i _mm_mask_srl_epi32(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRLD __m128i _mm_maskz_srl_epi32( __mmask8 k, __m128i a, __m128i cnt);
VPSRLQ __m512i _mm512_srli_epi64(__m512i a, unsigned int imm);
VPSRLQ __m512i _mm512_mask_srli_epi64(__m512i s, __mmask8 k, __m512i a, unsigned int imm);
VPSRLQ __m512i _mm512_mask_srli_epi64( __mmask8 k, __m512i a, unsigned int imm);
VPSRLQ __m256i _mm256_mask_srli_epi64(__m256i s, __mmask8 k, __m256i a, unsigned int imm);
VPSRLQ __m256i _mm256_maskz_srli_epi64( __mmask8 k, __m256i a, unsigned int imm);
VPSRLQ __m128i _mm_mask_srli_epi64(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSRLQ __m128i _mm_maskz_srli_epi64( __mmask8 k, __m128i a, unsigned int imm);
VPSRLQ __m512i _mm512_srl_epi64(__m512i a, __m128i cnt);
VPSRLQ __m512i _mm512_mask_srl_epi64(__m512i s, __mmask8 k, __m512i a, __m128i cnt);
VPSRLQ __m512i _mm512_mask_srl_epi64( __mmask8 k, __m512i a, __m128i cnt);
VPSRLQ __m256i _mm256_mask_srl_epi64(__m256i s, __mmask8 k, __m256i a, __m128i cnt);
VPSRLQ __m256i _mm256_maskz_srl_epi64( __mmask8 k, __m256i a, __m128i cnt);
VPSRLQ __m128i _mm_mask_srl_epi64(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRLQ __m128i _mm_maskz_srl_epi64( __mmask8 k, __m128i a, __m128i cnt);
VPSRLW __m512i _mm512_srli_epi16(__m512i a, unsigned int imm);
VPSRLW __m512i _mm512_mask_srli_epi16(__m512i s, __mmask32 k, __m512i a, unsigned int imm);
VPSRLW __m512i _mm512_maskz_srli_epi16( __mmask32 k, __m512i a, unsigned int imm);
VPSRLW __m256i _mm256_mask_srlii_epi16(__m256i s, __mmask16 k, __m256i a, unsigned int imm);
VPSRLW __m256i _mm256_maskz_srli_epi16( __mmask16 k, __m256i a, unsigned int imm);
VPSRLW __m128i _mm_mask_srli_epi16(__m128i s, __mmask8 k, __m128i a, unsigned int imm);
VPSRLW __m128i _mm_maskz_srli_epi16( __mmask8 k, __m128i a, unsigned int imm);
VPSRLW __m512i _mm512_srl_epi16(__m512i a, __m128i cnt);
VPSRLW __m512i _mm512_mask_srl_epi16(__m512i s, __mmask32 k, __m512i a, __m128i cnt);
VPSRLW __m512i _mm512_maskz_srl_epi16( __mmask32 k, __m512i a, __m128i cnt);
VPSRLW __m256i _mm256_mask_srl_epi16(__m256i s, __mmask16 k, __m256i a, __m128i cnt);
VPSRLW __m256i _mm256_maskz_srl_epi16( __mmask8 k, __mmask16 a, __m128i cnt);
VPSRLW __m128i _mm_mask_srl_epi16(__m128i s, __mmask8 k, __m128i a, __m128i cnt);
VPSRLW __m128i _mm_maskz_srl_epi16( __mmask8 k, __m128i a, __m128i cnt);
PSRLW:__m64 _mm_srli_pi16(__m64 m, int  count)
PSRLW:__m64 _mm_srl_pi16 (__m64 m, __m64 count)
(V)PSRLW:__m128i _mm_srli_epi16 (__m128i m, int count)
(V)PSRLW:__m128i _mm_srl_epi16 (__m128i m, __m128i count)
VPSRLW:__m256i _mm256_srli_epi16 (__m256i m, int count)
VPSRLW:__m256i _mm256_srl_epi16 (__m256i m, __m128i count)
PSRLD:__m64 _mm_srli_pi32 (__m64 m, int  count)
PSRLD:__m64 _mm_srl_pi32 (__m64 m, __m64 count)
(V)PSRLD:__m128i _mm_srli_epi32 (__m128i m, int  count)
(V)PSRLD:__m128i _mm_srl_epi32 (__m128i m, __m128i count)
VPSRLD:__m256i _mm256_srli_epi32 (__m256i m, int count)
VPSRLD:__m256i _mm256_srl_epi32 (__m256i m, __m128i count)
PSRLQ:__m64 _mm_srli_si64 (__m64 m, int  count)
PSRLQ:__m64 _mm_srl_si64 (__m64 m, __m64 count)
(V)PSRLQ:__m128i _mm_srli_epi64 (__m128i m, int  count)
(V)PSRLQ:__m128i _mm_srl_epi64 (__m128i m, __m128i count)
VPSRLQ:__m256i _mm256_srli_epi64 (__m256i m, int count)
VPSRLQ:__m256i _mm256_srl_epi64 (__m256i m, __m128i count)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


VEX-encoded instructions:

                              Syntax with RM/RVM operand encoding, see Exceptions Type 4.

                              Syntax with MI/VMI operand encoding, see Exceptions Type 7.

EVEX-encoded VPSRLW, see Exceptions Type E4NF.nb.

EVEX-encoded VPSRLD/Q:

                              Syntax with M128 operand encoding, see Exceptions Type E4NF.nb.

                              Syntax with FVI operand encoding, see Exceptions Type E4.

