----------------------------
title : KXNORW, KXNORB, KXNORQ, KXNORDs (Intel x86/64 assembly instruction)
cat_title : KXNORW, KXNORB, KXNORQ, KXNORD
ref_title : KXNORW, KXNORB, KXNORQ, KXNORD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KXNORW, KXNORB, KXNORQ, KXNORD

**Bitwise Logical XNOR Masks**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.L1.0F.W0 46 /r \newline{}KXNORW k1, k2, k3|RVR|V/V|AVX512F|Bitwise XNOR 16 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W0 46 /r \newline{}KXNORB k1, k2, k3|RVR|V/V|AVX512DQ|Bitwise XNOR 8 bits masks k2 and k3 and place result in k1.|
|VEX.L1.0F.W1 46 /r \newline{}KXNORQ k1, k2, k3|RVR|V/V|AVX512BW|Bitwise XNOR 64 bits masks k2 and k3 and place result in k1.|
|VEX.L1.66.0F.W1 46 /r \newline{}KXNORD k1, k2, k3|RVR|V/V|AVX512BW|Bitwise XNOR 32 bits masks k2 and k3 and place result in k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RVR|ModRM:reg (w)|VEX.1vvv (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise XNOR between the vector mask k2 and the vector mask k3, and writes the result into vector mask k1 (three-operand form).


### Operation
#### KXNORW
```info-verb
DEST[15:0] <-  NOT (SRC1[15:0] BITWISE XOR SRC2[15:0])
DEST[MAX_KL-1:16] <-  0
```
#### KXNORB
```info-verb
DEST[7:0] <-  NOT (SRC1[7:0] BITWISE XOR SRC2[7:0])
DEST[MAX_KL-1:8] <-  0
```
#### KXNORQ
```info-verb
DEST[63:0] <-  NOT (SRC1[63:0] BITWISE XOR SRC2[63:0])
DEST[MAX_KL-1:64] <-  0
```
#### KXNORD
```info-verb
DEST[31:0] <-  NOT (SRC1[31:0] BITWISE XOR SRC2[31:0])
DEST[MAX_KL-1:32] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KXNORW __mmask16 _mm512_kxnor(__mmask16 a, __mmask16 b);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

