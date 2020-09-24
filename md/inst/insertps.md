----------------------------
title : INSERTPS (Intel x86/64 assembly instruction)
cat_title : INSERTPS
ref_title : INSERTPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/I
publish_date: 2020-09-01
----------------------------


#@ INSERTPS

**Insert Scalar Single-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A 21 /r ib`\newline{}`INSERTPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE4_1|Insert a single-precision floating-point value selected by imm8 from xmm2/m32 into xmm1 at the specified destination element specified by imm8 and zero out destination elements in xmm1 as indicated in imm8.|
|`VEX.NDS.128.66.0F3A.WIG 21 /r ib`\newline{}VINSERTPS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Insert a single-precision floating-point value selected by imm8 from xmm3/m32 and merge with values in xmm2 at the specified destination element specified by imm8 and write out the result and zero out destination elements in xmm1 as indicated in imm8.|
|`EVEX.NDS.128.66.0F3A.W0 21 /r ib`\newline{}VINSERTPS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S|V/V|AVX512F|Insert a single-precision floating-point value selected by imm8 from xmm3/m32 and merge with values in xmm2 at the specified destination element specified by imm8 and write out the result and zero out destination elements in xmm1 as indicated in imm8.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


(register source form)

Select a single-precision floating-point element from second source as indicated by Count\esc{_}S bits of the immediate operand and destination operand it into the first source at the location indicated by the Count\esc{_}D bits of the imme-diate operand. Store in the destination and zero out destination elements based on the ZMask bits of the immediate operand. 

(memory source form)

Load a floating-point element from a 32-bit memory location and destination operand it into the first source at the location indicated by the Count\esc{_}D bits of the immediate operand. Store in the destination and zero out destination elements based on the ZMask bits of the immediate operand. 

128-bit Legacy SSE version: The first source register is an XMM register. The second source operand is either an XMM register or a 32-bit memory location. The destination is not distinct from the first source XMM register and the upper bits (MAX\esc{_}VL-1:128) of the corresponding register destination are unmodified.

VEX.128 and EVEX encoded version: The destination and first source register is an XMM register. The second source operand is either an XMM register or a 32-bit memory location. The upper bits (MAX\esc{_}VL-1:128) of the corre-sponding register destination are zeroed.

If VINSERTPS is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.


### Operation
#### VINSERTPS (VEX.128 and EVEX encoded version)
```info-verb
IF (SRC = REG) THEN COUNT_S <-  imm8[7:6]
    ELSE COUNT_S <-  0
COUNT_D <-  imm8[5:4]
ZMASK <-  imm8[3:0]
CASE (COUNT_S) OF
    0: TMP <-  SRC2[31:0]
    1: TMP <-  SRC2[63:32]
    2: TMP <-  SRC2[95:64]
    3: TMP <-  SRC2[127:96]
ESAC;
CASE (COUNT_D) OF
    0: TMP2[31:0] <-  TMP
          TMP2[127:32] <-  SRC1[127:32]
    1: TMP2[63:32] <-  TMP
          TMP2[31:0] <-  SRC1[31:0]
          TMP2[127:64] <-  SRC1[127:64]
    2: TMP2[95:64] <-  TMP
          TMP2[63:0] <-  SRC1[63:0]
          TMP2[127:96] <-  SRC1[127:96]
    3: TMP2[127:96] <-  TMP
          TMP2[95:0] <-  SRC1[95:0]
ESAC;
IF (ZMASK[0] = 1) THEN DEST[31:0] <-  00000000H
    ELSE DEST[31:0] <-  TMP2[31:0]
IF (ZMASK[1] = 1) THEN DEST[63:32] <-  00000000H
    ELSE DEST[63:32] <-  TMP2[63:32]
IF (ZMASK[2] = 1) THEN DEST[95:64] <-  00000000H
    ELSE DEST[95:64] <-  TMP2[95:64]
IF (ZMASK[3] = 1) THEN DEST[127:96] <-  00000000H
    ELSE DEST[127:96] <-  TMP2[127:96]
DEST[MAX_VL-1:128] <-  0
```
#### INSERTPS (128-bit Legacy SSE version)
```info-verb
IF (SRC = REG) THEN COUNT_S <- imm8[7:6]
    ELSE COUNT_S <- 0
COUNT_D <- imm8[5:4]
ZMASK <- imm8[3:0]
CASE (COUNT_S) OF
    0: TMP <- SRC[31:0]
    1: TMP <- SRC[63:32]
    2: TMP <- SRC[95:64]
    3: TMP <- SRC[127:96]
ESAC;
CASE (COUNT_D) OF
    0: TMP2[31:0] <- TMP
          TMP2[127:32] <- DEST[127:32]
    1: TMP2[63:32] <- TMP
          TMP2[31:0] <- DEST[31:0]
          TMP2[127:64] <- DEST[127:64]
    2: TMP2[95:64] <- TMP
TMP2[63:0] <- DEST[63:0]
          TMP2[127:96] <- DEST[127:96]
    3: TMP2[127:96] <- TMP
          TMP2[95:0] <- DEST[95:0]
ESAC;
IF (ZMASK[0] = 1) THEN DEST[31:0] <- 00000000H
    ELSE DEST[31:0] <- TMP2[31:0]
IF (ZMASK[1] = 1) THEN DEST[63:32] <- 00000000H
    ELSE DEST[63:32] <- TMP2[63:32]
IF (ZMASK[2] = 1) THEN DEST[95:64] <- 00000000H
    ELSE DEST[95:64] <- TMP2[95:64]
IF (ZMASK[3] = 1) THEN DEST[127:96] <- 00000000H
    ELSE DEST[127:96] <- TMP2[127:96]
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VINSERTPS __m128 _mm_insert_ps(__m128 dst, __m128 src, const int nidx);
INSETRTPS __m128 _mm_insert_ps(__m128 dst, __m128 src, const int nidx);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; additionally

#UD If VEX.L = 0.

EVEX-encoded instruction, see Exceptions Type E9NF.

