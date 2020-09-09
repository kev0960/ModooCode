----------------------------
title : KADDW, KADDB, KADDQ, KADDDs (Intel x86/64 assembly instruction)
cat_title : KADDW, KADDB, KADDQ, KADDD
ref_title : KADDW, KADDB, KADDQ, KADDD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KADDW, KADDB, KADDQ, KADDD

**ADD Two Masks**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.L1.0F.W0 4A /r \newline{}KADDW k1, k2, k3|RVR|V/V|AVX512DQ|Add 16 bits masks in k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W0 4A /r \newline{}KADDB k1, k2, k3|RVR|V/V|AVX512DQ|Add 8 bits masks in k2 and k3 and place result in k1.|
|VEX.L1.0F.W1 4A /r \newline{}KADDQ k1, k2, k3|RVR|V/V|AVX512BW|Add 64 bits masks in k2 and k3 and place result in k1. |
|VEX.L1.66.0F.W1 4A /r \newline{}KADDD k1, k2, k3|RVR|V/V|AVX512BW|Add 32 bits masks in k2 and k3 and place result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RVR|ModRM:reg (w)|VEX.1vvv (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Adds the vector mask k2 and the vector mask k3, and writes the result into vector mask k1.


### Operation
#### KADDW
```info-verb
DEST[15:0] <-  SRC1[15:0] + SRC2[15:0]
DEST[MAX_KL-1:16] <-  0
```
#### KADDB
```info-verb
DEST[7:0] <-  SRC1[7:0] + SRC2[7:0]
DEST[MAX_KL-1:8] <-  0
```
#### KADDQ
```info-verb
DEST[63:0] <-  SRC1[63:0] + SRC2[63:0]
DEST[MAX_KL-1:64] <-  0
```
#### KADDD
```info-verb
DEST[31:0] <-  SRC1[31:0] + SRC2[31:0]
DEST[MAX_KL-1:32] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

