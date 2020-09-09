----------------------------
title : SHA256MSG2 (Intel x86/64 assembly instruction)
cat_title : SHA256MSG2
ref_title : SHA256MSG2
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SHA256MSG2

**Perform a Final Calculation for the Next Four SHA256 Message Dwords**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 38 CD /r \newline{}SHA256MSG2 xmm1, xmm2/m128|RM|V/V|SHA|Performs the final calculation for the next four SHA256 message dwords using previous message dwords from xmm1 and xmm2/m128, storing the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|
### Description


The `SHA256MSG2` instruction is one of two SHA2 message scheduling instructions. The instruction performs the final calculation for the next four SHA256 message dwords.


### Operation
#### SHA256MSG2 
```info-verb
W14 <-  SRC2[95:64] ; 
W15 <-  SRC2[127:96] ; 
W16 <-  SRC1[31: 0] + 1( W14) ; 
W17 <-  SRC1[63: 32] + 1( W15) ; 
W18 <-  SRC1[95: 64] + 1( W16) ; 
W19 <-  SRC1[127: 96] + 1( W17) ; 
DEST[127:96] <-  W19 ; 
DEST[95:64] <-  W18 ; 
DEST[63:32] <-  W17 ; 
DEST[31:0] <-  W16; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA256MSG2 : __m128i _mm_sha256msg2_epu32(__m128i, __m128i);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

