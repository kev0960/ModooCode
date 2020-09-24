----------------------------
title : PINSRW (Intel x86/64 assembly instruction)
cat_title : PINSRW
ref_title : PINSRW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PINSRW

**Insert Word**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|----------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F C4 /r ib\footnote{1}`\newline{}`PINSRW` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } r32/m16 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE|Insert the low word from r32 or from m16 into mm at the word position specified by imm8.|
|`66 0F C4 /r ib`\newline{}`PINSRW` \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r32/m16 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE2|Move the low word of r32 or from m16 into xmm at the word position specified by imm8.|
|`VEX.NDS.128.66.0F.W0 C4 /r ib`\newline{}VPINSRW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r32/m16 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V\footnote{2} /V|AVX|Insert a word integer value from r32/m16 and rest from xmm2 into xmm1 at the word offset in imm8.|
|`EVEX.NDS.128.66.0F.WIG C4 /r ib`\newline{}VPINSRW \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r32/m16 \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S-RVMI|V/V|AVX512BW|Insert a word integer value from r32/m16 and rest from xmm2 into xmm1 at the word offset in imm8.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

2. In 64-bit mode, VEX.W1 is ignored for VPINSRW (similar to legacy REX.W=1 prefix in PINSRW)
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
|T1S-RVMI|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description


Copies a word from the source operand (second operand) and inserts it in the destination operand (first operand) at the location specified with the count operand (third operand). (The other words in the destination register are left untouched.) The source operand can be a general-purpose register or a 16-bit memory location. (When the source operand is a general-purpose register, the low word of the register is copied.) The destination operand can be an MMX technology register or an XMM register. The count operand is an 8-bit immediate. When specifying a word location in an MMX technology register, the 2 least-significant bits of the count operand specify the location; for an XMM register, the 3 least-significant bits specify the location.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15, R8-15). 

128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination YMM register are zeroed. VEX.L must be 0, other-wise the instruction will #UD.

EVEX.128 encoded version: Bits (VLMAX-1:128) of the destination register are zeroed. EVEX.L'L must be 0, other-wise the instruction will #UD. 


### Operation
#### PINSRW (with 64-bit source operand)
```info-verb
    SEL <- COUNT AND 3H;
          CASE (Determine word position) OF
                SEL <- 0: MASK <- 000000000000FFFFH;
SEL <- 1: MASK <- 00000000FFFF0000H;
                SEL <- 2: MASK <- 0000FFFF00000000H;
                SEL <- 3: MASK <- FFFF000000000000H;
    DEST <- (DEST AND NOT MASK) OR (((SRC << (SEL `*` 16)) AND MASK);
```
#### PINSRW (with 128-bit source operand)
```info-verb
    SEL <- COUNT AND 7H;
          CASE (Determine word position) OF
                SEL <- 0: MASK <- 0000000000000000000000000000FFFFH;
                SEL <- 1: MASK <- 000000000000000000000000FFFF0000H;
                SEL <- 2: MASK <- 00000000000000000000FFFF00000000H;
                SEL <- 3: MASK <- 0000000000000000FFFF000000000000H;
                SEL <- 4: MASK <- 000000000000FFFF0000000000000000H;
                SEL <- 5: MASK <- 00000000FFFF00000000000000000000H;
                SEL <- 6: MASK <- 0000FFFF000000000000000000000000H;
                SEL <- 7: MASK <- FFFF0000000000000000000000000000H;
    DEST <- (DEST AND NOT MASK) OR (((SRC << (SEL `*` 16)) AND MASK);
```
#### VPINSRW (VEX/EVEX encoded version)
```info-verb
SEL <-  imm8[2:0]
DEST[127:0] <-  write_w_element(SEL, SRC2, SRC1)
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PINSRW:  __m64 _mm_insert_pi16 (__m64 a, int d, int n)
PINSRW:  __m128i _mm_insert_epi16 ( __m128i a, int b, int imm)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type 5; 

EVEX-encoded instruction, see Exceptions Type E9NF.

#UD  If VEX.L = 1 or EVEX.L'L > 0.

