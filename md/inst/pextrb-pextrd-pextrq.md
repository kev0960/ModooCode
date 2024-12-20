----------------------------
title : PEXTRB, PEXTRD, PEXTRQs (Intel x86/64 assembly instruction)
cat_title : PEXTRB, PEXTRD, PEXTRQ
ref_title : PEXTRB, PEXTRD, PEXTRQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PEXTRB, PEXTRD, PEXTRQ

** Extract Byte/Dword/Qword**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|----------|------------------------------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A 14/r ib`\newline{}`PEXTRB` reg/m8 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MRI|V/V|SSE4_1|Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r32 or r64 are zeroed.|
|`66 0F 3A 16/r ib`\newline{}`PEXTRD` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MRI|V/V|SSE4_1|Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r/m32.|
|`66 REX.W 0F 3A 16/r ib`\newline{}`PEXTRQ` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MRI|V/N.E.|SSE4_1|Extract a qword integer value from xmm2 at the source qword offset specified by imm8 into r/m64.|
|`VEX.128.66.0F3A.W0 14 /r ib`\newline{}VPEXTRB reg/m8 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MRI|V\footnote{1} /V|AVX|Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r64/r32 is filled with zeros.|
|`VEX.128.66.0F3A.W0 16 /r ib`\newline{}VPEXTRD r32/m32 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MRI|V/V|AVX|Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r32/m32.|
|`VEX.128.66.0F3A.W1 16 /r ib`\newline{}VPEXTRQ r64/m64 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MRI|V/i|AVX|Extract a qword integer value from xmm2 at the source dword offset specified by imm8 into r64/m64.|
|`EVEX.128.66.0F3A.WIG 14 /r ib`\newline{}VPEXTRB reg/m8 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S-MRI|V/V|AVX512BW|Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r64/r32 is filled with zeros.|
|`EVEX.128.66.0F3A.W0 16 /r ib`\newline{}VPEXTRD r32/m32 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S-MRI|V/V|AVX512DQ|Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r32/m32.|
|`EVEX.128.66.0F3A.W1 16 /r ib`\newline{}VPEXTRQ r64/m64 \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S-MRI|V/N.E.\footnote{1}|**AVX512DQ**|**Extract a qword integer value from xmm2 at the ****source dword offset specified by imm8 into ****r64/m64.**|

```note
**1. In 64-bit mode, VEX.W1 is ignored for VPEXTRB (similar to legacy REX.W=1 prefix in PEXTRB).**

**2. VEX.W/EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 version is used.*
```
### Instruction Operand Encoding


|**Op/En**|**Operand 1**|**Operand 2**|**Operand 3**|**Operand 4**|
|---------|-------------|-------------|-------------|-------------|
|**MRI**|**ModRM:r/m (w)**|**ModRM:reg (r)**|**imm8**|**NA**|
### Description


Extract a byte/dword/qword integer value from the source XMM register at a byte/dword/qword offset determined from imm8[3:0]. The destination can be a register or byte/dword/qword memory location. If the destination is a register, the upper bits of the register are zero extended.

In legacy non-VEX encoded version and if the destination operand is a register, the default operand size in 64-bit mode for PEXTRB/PEXTRD is 64 bits, the bits above the least significant byte/dword data are filled with zeros. `PEXTRQ` is not encodable in non-64-bit modes and requires REX.W in 64-bit mode.



Note: In VEX.128 encoded versions, VEX.vvvv is reserved and must be 1111b, VEX.L must be 0, otherwise the instruction will #UD. In EVEX.128 encoded versions, EVEX.vvvv is reserved and must be 1111b, EVEX.L"L must be 0, otherwise the instruction will #UD. If the destination operand is a register, the default operand size in 64-bit mode for VPEXTRB/VPEXTRD is 64 bits, the bits above the least significant byte/word/dword data are filled with zeros. Attempt to execute VPEXTRQ in non-64-bit mode will cause #UD.


### Operation
#### VPEXTRTD/VPEXTRQ
```info-verb
IF (64-Bit Mode and 64-bit dest operand)
THEN
    Src_Offset <-  Imm8[0]
    r64/m64 <- (Src >> Src_Offset * 64)
ELSE
    Src_Offset <-  Imm8[1:0]
    r32/m32 <-  ((Src >> Src_Offset *32) AND 0FFFFFFFFh);
FI
```
#### VPEXTRB ( dest=m8)
```info-verb
SRC_Offset <-  Imm8[3:0]
Mem8 <-  (Src >> Src_Offset*8)
```
#### VPEXTRB ( dest=reg)
```info-verb
IF (64-Bit Mode )
THEN
    SRC_Offset <-  Imm8[3:0] 
    DEST[7:0] <-  ((Src >> Src_Offset*8) AND 0FFh)
    DEST[63:8] <-!= ZERO_FILL;
ELSE
    SRC_Offset <- . Imm8[3:0];
    DEST[7:0] <-  ((Src >> Src_Offset*8) AND 0FFh);
    DEST[31:8] <-!= ZERO_FILL;
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PEXTRB: int _mm_extract_epi8 (__m128i src, const int ndx);
PEXTRD:  int _mm_extract_epi32 (__m128i src, const int ndx);
PEXTRQ: __int64 _mm_extract_epi64 (__m128i src, const int ndx);
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; 

EVEX-encoded instruction, see Exceptions Type E9NF.

#UD If VEX.L = 1 or EVEX.L'L > 0.

                              If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

                              If VPEXTRQ in non-64-bit mode, VEX.W=1.

