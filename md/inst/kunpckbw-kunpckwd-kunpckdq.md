----------------------------
title : KUNPCKBW, KUNPCKWD, KUNPCKDQs (Intel x86/64 assembly instruction)
cat_title : KUNPCKBW, KUNPCKWD, KUNPCKDQ
ref_title : KUNPCKBW, KUNPCKWD, KUNPCKDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KUNPCKBW, KUNPCKWD, KUNPCKDQ

**Unpack for Mask Registers **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDS.L1.66.0F.W0 4B /r`\newline{}`KUNPCKBW` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 k3 |RVR|V/V|AVX512F|Unpack and interleave 8 bits masks in k2 and k3 and write word result in k1.|
|`VEX.NDS.L1.0F.W0 4B /r `\newline{}`KUNPCKWD` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 k3 |RVR|V/V|AVX512BW|Unpack and interleave 16 bits in k2 and k3 and write double-word result in k1.|
|`VEX.NDS.L1.0F.W1 4B /r `\newline{}`KUNPCKDQ` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 k3 |RVR|V/V|AVX512BW|Unpack and interleave 32 bits masks in k2 and k3 and write quadword result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RVR|ModRM:reg (w)|VEX.1vvv (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Unpacks the lower 8/16/32 bits of the second and third operands (source operands) into the low part of the first operand (destination operand), starting from the low bytes. The result is zero-extended in the destination.


### Operation
#### KUNPCKBW
```info-verb
DEST[7:0] <-  SRC2[7:0]
DEST[15:8] <-  SRC1[7:0]
DEST[MAX_KL-1:16] <-  0
```
#### KUNPCKWD
```info-verb
DEST[15:0] <-  SRC2[15:0]
DEST[31:16] <-  SRC1[15:0]DEST[MAX_KL-1:32] <-  0
```
#### KUNPCKDQ
```info-verb
DEST[31:0] <-  SRC2[31:0]
DEST[63:32] <-  SRC1[31:0]DEST[MAX_KL-1:64] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KUNPCKBW __mmask16 _mm512_kunpackb(__mmask16 a, __mmask16 b);
KUNPCKDQ __mmask64 _mm512_kunpackd(__mmask64 a, __mmask64 b);
KUNPCKWD __mmask32 _mm512_kunpackw(__mmask32 a, __mmask32 b);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

