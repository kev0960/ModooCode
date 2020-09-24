----------------------------
title : AESKEYGENASSIST (Intel x86/64 assembly instruction)
cat_title : AESKEYGENASSIST
ref_title : AESKEYGENASSIST
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/A
publish_date: 2020-09-01
----------------------------


#@ AESKEYGENASSIST

**AES Round Key Generation Assist**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A DF /r ib`\newline{}`AESKEYGENASSIST` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|AES|Assist in AES round key generation using an 8 bits Round Constant (RCON) specified in the immediate byte, operating on 128 bits of data specified in xmm2/m128 and stores the result in xmm1.|
|`VEX.128.66.0F3A.WIG DF /r ib`\newline{}VAESKEYGENASSIST \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|Both AES andAVX flags|Assist in AES round key generation using 8 bits Round Constant (RCON) specified in the immediate byte, operating on 128 bits of data specified in xmm2/m128 and stores the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|Operand3|Operand4|
|-----|---------|--------|--------|--------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
### Description


Assist in expanding the AES cipher key, by computing steps towards generating a round key for encryption, using 128-bit data specified in the source operand and an 8-bit round constant specified as an immediate, store the result in the destination operand.

The destination operand is an XMM register. The source operand can be an XMM register or a 128-bit memory loca-tion.

128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination YMM register are zeroed.

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### AESKEYGENASSIST
```info-verb
X3[31:0] <- SRC [127: 96];
X2[31:0] <- SRC [95: 64];
X1[31:0] <- SRC [63: 32];
X0[31:0] <- SRC [31: 0];
RCON[31:0] <- ZeroExtend(Imm8[7:0]);
DEST[31:0] <- SubWord(X1);
DEST[63:32 ] <- RotWord( SubWord(X1) ) XOR RCON;
DEST[95:64] <- SubWord(X3);
DEST[127:96] <- RotWord( SubWord(X3) ) XOR RCON;
DEST[VLMAX-1:128] (Unmodified)
```
#### VAESKEYGENASSIST 
```info-verb
X3[31:0] <-  SRC [127: 96];
X2[31:0] <-  SRC [95: 64];
X1[31:0] <-  SRC [63: 32];
X0[31:0] <-  SRC [31: 0];
RCON[31:0] <-  ZeroExtend(Imm8[7:0]);
DEST[31:0] <-  SubWord(X1);
DEST[63:32 ] <-  RotWord( SubWord(X1) ) XOR RCON;
DEST[95:64] <-  SubWord(X3);
DEST[127:96] <-  RotWord( SubWord(X3) ) XOR RCON;
DEST[VLMAX-1:128] <-  0;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
(V)AESKEYGENASSIST: __m128i _mm_aeskeygenassist (__m128i, const int)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.vvvv ->  1111B.

