----------------------------
title : SHA256MSG1 (Intel x86/64 assembly instruction)
cat_title : SHA256MSG1
ref_title : SHA256MSG1
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SHA256MSG1

**Perform an Intermediate Calculation for the Next Four SHA256 Message Dwords**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 38 CC /r \newline{}SHA256MSG1 xmm1, xmm2/m128|RM|V/V|SHA|Performs an intermediate calculation for the next four SHA256 message dwords using previous message dwords from xmm1 and xmm2/m128, storing the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|
### Description


The `SHA256MSG1` instruction is one of two SHA256 message scheduling instructions. The instruction performs an intermediate calculation for the next four SHA256 message dwords.


### Operation
#### SHA256MSG1 
```info-verb
W4 <-  SRC2[31: 0] ; 
W3 <-  SRC1[127:96] ; 
W2 <-  SRC1[95:64] ; 
W1 <-  SRC1[63: 32] ; 
W0 <-  SRC1[31: 0] ; 
DEST[127:96] <-  W3 + 0( W4); 
DEST[95:64] <-  W2 + 0( W3); 
DEST[63:32] <-  W1 + 0( W2); 
DEST[31:0] <-  W0 + 0( W1); 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA256MSG1: __m128i _mm_sha256msg1_epu32(__m128i, __m128i);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

