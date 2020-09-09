----------------------------
title : KNOTW, KNOTB, KNOTQ, KNOTDs (Intel x86/64 assembly instruction)
cat_title : KNOTW, KNOTB, KNOTQ, KNOTD
ref_title : KNOTW, KNOTB, KNOTQ, KNOTD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KNOTW, KNOTB, KNOTQ, KNOTD

**NOT Mask Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|------------------------------------|---------------|
|VEX.L0.0F.W0 44 /r \newline{}KNOTW k1, k2|RR|V/V|AVX512F|Bitwise NOT of 16 bits mask k2.|
|VEX.L0.66.0F.W0 44 /r \newline{}KNOTB k1, k2|RR|V/V|AVX512DQ|Bitwise NOT of 8 bits mask k2.|
|VEX.L0.0F.W1 44 /r \newline{}KNOTQ k1, k2|RR|V/V|AVX512BW|Bitwise NOT of 64 bits mask k2.|
|VEX.L0.66.0F.W1 44 /r \newline{}KNOTD k1, k2|RR|V/V|AVX512BW|Bitwise NOT of 32 bits mask k2.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|
|-----|---------|---------|
|RR|ModRM:reg (w)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise `NOT` of vector mask k2 and writes the result into vector mask k1.


### Operation
#### KNOTW
```info-verb
DEST[15:0] <-  BITWISE NOT SRC[15:0]
DEST[MAX_KL-1:16] <-  0
```
#### KNOTB
```info-verb
DEST[7:0] <-  BITWISE NOT SRC[7:0]
DEST[MAX_KL-1:8] <-  0
```
#### KNOTQ
```info-verb
DEST[63:0] <-  BITWISE NOT SRC[63:0]
DEST[MAX_KL-1:64] <-  0
```
#### KNOTD
```info-verb
DEST[31:0] <-  BITWISE NOT SRC[31:0]
DEST[MAX_KL-1:32] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KNOTW __mmask16 _mm512_knot(__mmask16 a);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

