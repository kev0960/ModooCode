----------------------------
title : PHMINPOSUW (Intel x86/64 assembly instruction)
cat_title : PHMINPOSUW
ref_title : PHMINPOSUW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PHMINPOSUW

** Packed Horizontal Word Minimum**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 38 41 /r\newline{}PHMINPOSUW xmm1, xmm2/m128|RM|V/V|SSE4_1|Find the minimum unsigned word in xmm2/m128 and place its value in the low word of xmm1 and its index in the second-lowest word of xmm1.|
|VEX.128.66.0F38.WIG 41 /r\newline{}VPHMINPOSUW xmm1, xmm2/m128|RM|V/V|AVX|Find the minimum unsigned word in xmm2/m128 and place its value in the low word of xmm1 and its index in the second-lowest word of xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Determine the minimum unsigned word value in the source operand (second operand) and place the unsigned word in the low word (bits 0-15) of the destination operand (first operand).  The word index of the minimum value is stored in bits 16-18 of the destination operand.  The remaining upper bits of the destination are set to zero. 

128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.vvvv is reserved and must be 1111b, VEX.L must be 0, otherwise the instruction will #UD.


### Operation
#### PHMINPOSUW (128-bit Legacy SSE version)
```info-verb
INDEX <-  0;
MIN <-  SRC[15:0]
IF (SRC[31:16] < MIN) 
    THEN INDEX <-  1;  MIN <-  SRC[31:16]; FI;
IF (SRC[47:32] < MIN) 
    THEN INDEX <-  2;  MIN <-  SRC[47:32]; FI;
* Repeat operation for words 3 through 6
IF (SRC[127:112] < MIN) 
    THEN INDEX <-  7;  MIN <-  SRC[127:112]; FI;
DEST[15:0] <-  MIN;
DEST[18:16] <-  INDEX;
DEST[127:19] <-  0000000000000000000000000000H;
```
#### VPHMINPOSUW (VEX.128 encoded version)
```info-verb
INDEX <-  0
MIN <-  SRC[15:0]
IF (SRC[31:16] < MIN) THEN INDEX <-  1; MIN <-  SRC[31:16]
IF (SRC[47:32] < MIN) THEN INDEX <-  2; MIN <-  SRC[47:32]
* Repeat operation for words 3 through 6
IF (SRC[127:112] < MIN) THEN INDEX <-  7; MIN <-  SRC[127:112]
DEST[15:0] <-  MIN
DEST[18:16] <-  INDEX
DEST[127:19] <-  0000000000000000000000000000H
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PHMINPOSUW: __m128i _mm_minpos_epu16( __m128i packed_words);
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1.

                              If VEX.vvvv ->  1111B.

