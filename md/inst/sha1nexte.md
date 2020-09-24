----------------------------
title : SHA1NEXTE (Intel x86/64 assembly instruction)
cat_title : SHA1NEXTE
ref_title : SHA1NEXTE
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SHA1NEXTE

**Calculate SHA1 State Variable E after Four Rounds**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 C8 /r `\newline{}`SHA1NEXTE` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SHA|Calculates SHA1 state variable E after four rounds of operation from the current SHA1 state variable A in xmm1. The calculated value of the SHA1 state variable E is added to the scheduled dwords in xmm2/m128, and stored with some of the scheduled dwords in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|
### Description


The `SHA1NEXTE` calculates the SHA1 state variable E after four rounds of operation from the current SHA1 state variable A in the destination operand. The calculated value of the SHA1 state variable E is added to the source operand, which contains the scheduled dwords.


### Operation
#### SHA1NEXTE 
```info-verb
TMP <-  (SRC1[127:96] ROL 30); 
DEST[127:96] <-  SRC2[127:96] + TMP; 
DEST[95:64] <-  SRC2[95:64]; 
DEST[63:32] <-  SRC2[63:32]; 
DEST[31:0] <-  SRC2[31:0]; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA1NEXTE: __m128i _mm_sha1nexte_epu32(__m128i, __m128i);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

