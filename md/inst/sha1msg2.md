----------------------------
title : SHA1MSG2 (Intel x86/64 assembly instruction)
cat_title : SHA1MSG2
ref_title : SHA1MSG2
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SHA1MSG2

**Perform a Final Calculation for the Next Four SHA1 Message Dwords**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 CA /r `\newline{}`SHA1MSG2` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SHA|Performs the final calculation for the next four SHA1 message dwords using intermediate results from xmm1 and the previous message dwords from xmm2/m128, storing the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|
### Description


The `SHA1MSG2` instruction is one of two SHA1 message scheduling instructions. The instruction performs the final calculation to derive the next four SHA1 message dwords.


### Operation
#### SHA1MSG2 
```info-verb
W13 <-  SRC2[95:64] ; 
W14 <-  SRC2[63: 32] ; 
W15 <-  SRC2[31: 0] ; 
W16 <-  (SRC1[127:96] XOR W13 ) ROL 1; 
W17 <-  (SRC1[95:64] XOR W14) ROL 1; 
W18 <-  (SRC1[63: 32] XOR W15) ROL 1; 
W19 <-  (SRC1[31: 0] XOR W16) ROL 1; 
DEST[127:96] <-  W16; 
DEST[95:64] <-  W17; 
DEST[63:32] <-  W18; 
DEST[31:0] <-  W19; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA1MSG2: __m128i _mm_sha1msg2_epu32(__m128i, __m128i);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

