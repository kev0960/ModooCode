----------------------------
title : SHA1MSG1 (Intel x86/64 assembly instruction)
cat_title : SHA1MSG1
ref_title : SHA1MSG1
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SHA1MSG1

**Perform an Intermediate Calculation for the Next Four SHA1 Message Dwords**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 C9 /r `\newline{}`SHA1MSG1` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SHA|Performs an intermediate calculation for the next four SHA1 message dwords using previous message dwords from xmm1 and xmm2/m128, storing the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|
### Description


The `SHA1MSG1` instruction is one of two SHA1 message scheduling instructions. The instruction performs an inter-mediate calculation for the next four SHA1 message dwords.


### Operation
#### SHA1MSG1 
```info-verb
W0 <-  SRC1[127:96] ; 
W1 <-  SRC1[95:64] ; 
W2 <-  SRC1[63: 32] ; 
W3 <-  SRC1[31: 0] ; 
W4 <-  SRC2[127:96] ; 
W5 <-  SRC2[95:64] ; 
DEST[127:96] <-  W2 XOR W0; 
DEST[95:64] <-  W3 XOR W1; 
DEST[63:32] <-  W4 XOR W2; 
DEST[31:0] <-  W5 XOR W3; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA1MSG1: __m128i _mm_sha1msg1_epu32(__m128i, __m128i);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

