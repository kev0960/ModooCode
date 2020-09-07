----------------------------
title : KXORW, KXORB, KXORQ, KXORDs (Intel x86/64 assembly instruction)
cat_title : KXORW, KXORB, KXORQ, KXORD
ref_title : KXORW, KXORB, KXORQ, KXORD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------
#@ KXORW, KXORB, KXORQ, KXORD

**Bitwise Logical XOR Masks**

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.L1.0F.W0 47 /r \newline{}KXORW k1, k2, k3|RVR|V/V|AVX512F|Bitwise XOR 16 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W0 47 /r\newline{}KXORB k1, k2, k3|RVR|V/V|AVX512DQ|Bitwise XOR 8 bits masks k2 and k3 and place result in k1.|
|VEX.L1.0F.W1 47 /r \newline{}KXORQ k1, k2, k3|RVR|V/V|AVX512BW|Bitwise XOR 64 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W1 47 /r \newline{}KXORD k1, k2, k3|RVR|V/V|AVX512BW|Bitwise XOR 32 bits masks k2 and k3 and place result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RVR|ModRM:reg (w)|VEX.1vvv (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise `XOR` between the vector mask k2 and the vector mask k3, and writes the result into vector mask k1 (three-operand form).


### Operation
#### KXORW
```info-verb
DEST[15:0] <-  SRC1[15:0] BITWISE XOR SRC2[15:0]
DEST[MAX_KL-1:16] <-  0
```
#### KXORB
```info-verb
DEST[7:0] <-  SRC1[7:0] BITWISE XOR SRC2[7:0]
DEST[MAX_KL-1:8] <-  0
```
#### KXORQ
```info-verb
DEST[63:0] <-  SRC1[63:0] BITWISE XOR SRC2[63:0]
DEST[MAX_KL-1:64] <-  0
```
#### KXORD
```info-verb
DEST[31:0] <-  SRC1[31:0] BITWISE XOR SRC2[31:0]
DEST[MAX_KL-1:32] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KXORW __mmask16 _mm512_kxor(__mmask16 a, __mmask16 b);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

