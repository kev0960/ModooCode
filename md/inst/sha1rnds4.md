----------------------------
title : SHA1RNDS4 (Intel x86/64 assembly instruction)
cat_title : SHA1RNDS4
ref_title : SHA1RNDS4
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SHA1RNDS4

**Perform Four Rounds of SHA1 Operation**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 3A CC /r ib`\newline{}`SHA1RNDS4` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SHA|Performs four rounds of SHA1 operation operating on SHA1 state (A,B,C,D) from xmm1, with a pre-computed sum of the next 4 round message dwords and state variable E from xmm2/m128. The immediate byte controls logic functions and round constants.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|
### Description


The `SHA1RNDS4` instruction performs four rounds of SHA1 operation using an initial SHA1 state (A,B,C,D) from the first operand (which is a source operand and the destination operand) and some pre-computed sum of the next 4 round message dwords, and state variable E from the second operand (a source operand). The updated SHA1 state (A,B,C,D) after four rounds of processing is stored in the destination operand.


### Operation
#### SHA1RNDS4 
```info-verb
The function f() and Constant K are dependent on the value of the immediate.
IF ( imm8[1:0] = 0 )
    THEN f() <-  f0(), K <-  K0; 
ELSE IF ( imm8[1:0] = 1 ) 
    THEN f() <-  f1(), K <-  K1; 
ELSE IF ( imm8[1:0] = 2 ) 
    THEN f() <-  f2(), K <-  K2; 
ELSE IF ( imm8[1:0] = 3 ) 
    THEN f() <-  f3(), K <-  K3; 
FI;
A <-  SRC1[127:96]; 
B <-  SRC1[95:64]; 
C <-  SRC1[63:32]; 
D <-  SRC1[31:0]; 
W0E <-  SRC2[127:96]; 
W1 <-  SRC2[95:64]; 
W2 <-  SRC2[63:32]; 
W3 <-  SRC2[31:0]; 
Round i = 0 operation:
A_1 <-  f (B, C, D) + (A ROL 5) +W0E +K; 
B_1 <-  A; 
C_1 <-  B ROL 30; 
D_1 <-  C; 
E_1 <-  D; 
FOR i = 1 to 3
    A_(i +1) <-  f (B_i, C_i, D_i) + (A_i ROL 5) +Wi+ E_i +K; 
    B_(i +1) <-  A_i; 
C_(i +1) <-  B_i ROL 30; 
    D_(i +1) <-  C_i; 
    E_(i +1) <-  D_i; 
ENDFOR
DEST[127:96] <-  A_4; 
DEST[95:64] <-  B_4; 
DEST[63:32] <-  C_4; 
DEST[31:0] <-  D_4; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA1RNDS4: __m128i _mm_sha1rnds4_epu32(__m128i, __m128i, const int);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

