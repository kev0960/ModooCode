----------------------------
title : KANDW, KANDB, KANDQ, KANDDs (Intel x86/64 assembly instruction)
cat_title : KANDW, KANDB, KANDQ, KANDD
ref_title : KANDW, KANDB, KANDQ, KANDD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KANDW, KANDB, KANDQ, KANDD

**Bitwise Logical AND Masks**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.L1.0F.W0 41 /r \newline{}KANDW k1, k2, k3|RVR|V/V|AVX512F|Bitwise AND 16 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W0 41 /r \newline{}KANDB k1, k2, k3|RVR|V/V|AVX512DQ|Bitwise AND 8 bits masks k2 and k3 and place result in k1. |
|VEX.L1.0F.W1 41 /r \newline{}KANDQ k1, k2, k3|RVR|V/V|AVX512BW|Bitwise AND 64 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W1 41 /r \newline{}KANDD k1, k2, k3|RVR|V/V|AVX512BW|Bitwise AND 32 bits masks k2 and k3 and place result in k1. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RVR|ModRM:reg (w)|VEX.1vvv (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise `AND` between the vector mask k2 and the vector mask k3, and writes the result into vector mask k1.


### Operation
#### KANDW
```info-verb
DEST[15:0] <-  SRC1[15:0] BITWISE AND SRC2[15:0]
DEST[MAX_KL-1:16] <-  0
```
#### KANDB
```info-verb
DEST[7:0] <-  SRC1[7:0] BITWISE AND SRC2[7:0]
DEST[MAX_KL-1:8] <-  0
```
#### KANDQ
```info-verb
DEST[63:0] <-  SRC1[63:0] BITWISE AND SRC2[63:0]
DEST[MAX_KL-1:64] <-  0
```
#### KANDD
```info-verb
DEST[31:0] <-  SRC1[31:0] BITWISE AND SRC2[31:0]
DEST[MAX_KL-1:32] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KANDW __mmask16 _mm512_kand(__mmask16 a, __mmask16 b);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

