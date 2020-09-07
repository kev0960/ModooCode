----------------------------
title : KANDNW, KANDNB, KANDNQ, KANDNDs (Intel x86/64 assembly instruction)
cat_title : KANDNW, KANDNB, KANDNQ, KANDND
ref_title : KANDNW, KANDNB, KANDNQ, KANDND
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------
#@ KANDNW, KANDNB, KANDNQ, KANDND

**Bitwise Logical AND NOT Masks**

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.L1.0F.W0 42 /r \newline{}KANDNW k1, k2, k3|RVR|V/V|AVX512F|Bitwise AND NOT 16 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W0 42 /r \newline{}KANDNB k1, k2, k3|RVR|V/V|AVX512DQ|Bitwise AND NOT 8 bits masks k1 and k2 and place result in k1.|
|VEX.L1.0F.W1 42 /r \newline{}KANDNQ k1, k2, k3|RVR|V/V|AVX512BW|Bitwise AND NOT 64 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W1 42 /r \newline{}KANDND k1, k2, k3|RVR|V/V|AVX512BW|Bitwise AND NOT 32 bits masks k2 and k3 and place result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RVR|ModRM:reg (w)|VEX.1vvv (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise `AND` `NOT` between the vector mask k2 and the vector mask k3, and writes the result into vector mask k1.


### Operation
#### KANDNW
```info-verb
DEST[15:0] <-  (BITWISE NOT SRC1[15:0]) BITWISE AND SRC2[15:0]
DEST[MAX_KL-1:16] <-  0
```
#### KANDNB
```info-verb
DEST[7:0] <-  (BITWISE NOT SRC1[7:0]) BITWISE AND SRC2[7:0]
DEST[MAX_KL-1:8] <-  0
```
#### KANDNQ
```info-verb
DEST[63:0] <-  (BITWISE NOT SRC1[63:0]) BITWISE AND SRC2[63:0]
DEST[MAX_KL-1:64] <-  0
```
#### KANDND
```info-verb
DEST[31:0] <-  (BITWISE NOT SRC1[31:0]) BITWISE AND SRC2[31:0]
DEST[MAX_KL-1:32] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KANDNW __mmask16 _mm512_kandn(__mmask16 a, __mmask16 b);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

