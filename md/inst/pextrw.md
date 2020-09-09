----------------------------
title : PEXTRW (Intel x86/64 assembly instruction)
cat_title : PEXTRW
ref_title : PEXTRW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PEXTRW

**Extract Word**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F C5 /r ib\footnote{1}\newline{}\newline{}PEXTRW reg, mm, imm8 |RMI|V/V|SSE|Extract the word specified by imm8 from mm and move it to reg, bits 15-0. The upper bits of r32 or r64 is zeroed.|
|66 0F C5 /r ib\newline{}\newline{}PEXTRW reg, xmm, imm8 |RMI|V/V|SSE2|Extract the word specified by imm8 from xmm and move it to reg, bits 15-0. The upper bits of r32 or r64 is zeroed.|
|66 0F 3A 15/r ib\newline{}PEXTRW reg/m16, xmm, imm8|MRI|V/V|SSE4_1|Extract the word specified by imm8 from xmm and copy it to lowest 16 bits of reg or m16. Zero-extend the result in the destination, r32 or r64.|
|VEX.128.66.0F.W0 C5 /r ib\newline{}VPEXTRW reg, xmm1, imm8|RMI|V\footnote{2} /V|AVX|Extract the word specified by imm8 from xmm1 and move it to reg, bits 15:0. Zero-extend the result. The upper bits of r64/r32 is filled with zeros.|
|VEX.128.66.0F3A.W0 15 /r ib\newline{}VPEXTRW reg/m16, xmm2, imm8|MRI|V/V|AVX|Extract a word integer value from xmm2 at the source word offset specified by imm8 into reg or m16. The upper bits of r64/r32 is filled with zeros.|
|EVEX.128.66.0F.WIG C5 /r ib\newline{}VPEXTRW reg, xmm1, imm8|RMI|V/V|AVX512BW|Extract the word specified by imm8 from xmm1 and move it to reg, bits 15:0. Zero-extend the result. The upper bits of r64/r32 is filled with zeros.|
|EVEX.128.66.0F3A.WIG 15 /r ib\newline{}VPEXTRW reg/m16, xmm2, imm8|T1S-MRI|V/V|AVX512BW|Extract a word integer value from xmm2 at the source word offset specified by imm8 into reg or m16. The upper bits of r64/r32 is filled with zeros.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

2. In 64-bit mode, VEX.W1 is ignored for VPEXTRW (similar to legacy REX.W=1 prefix in PEXTRW)
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
|MRI|ModRM:r/m (w)|ModRM:reg (r)|imm8|NA|
### Description


Copies the word in the source operand (second operand) specified by the count operand (third operand) to the destination operand (first operand). The source operand can be an MMX technology register or an XMM register. The destination operand can be the low word of a general-purpose register or a 16-bit memory address. The count operand is an 8-bit immediate. When specifying a word location in an MMX technology register, the 2 least-signifi-cant bits of the count operand specify the location; for an XMM register, the 3 least-significant bits specify the loca-tion. The content of the destination register above bit 16 is cleared (set to all 0s).

In 64-bit mode, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15, R8-15). If the destination operand is a general-purpose register, the default operand size is 64-bits in 64-bit mode. 



Note: In VEX.128 encoded versions, VEX.vvvv is reserved and must be 1111b, VEX.L must be 0, otherwise the instruction will #UD. In EVEX.128 encoded versions, EVEX.vvvv is reserved and must be 1111b, EVEX.L must be 0, otherwise the instruction will #UD. If the destination operand is a register, the default operand size in 64-bit mode for VPEXTRW is 64 bits, the bits above the least significant byte/word/dword data are filled with zeros.


### Operation
#### VPEXTRW ( dest=m16)
```info-verb
SRC_Offset <-  Imm8[2:0]
Mem16 <-  (Src >> Src_Offset*16)
```
#### VPEXTRW ( dest=reg)
```info-verb
IF (64-Bit Mode )
THEN
    SRC_Offset <-  Imm8[2:0]
    DEST[15:0] <-  ((Src >> Src_Offset*16) AND 0FFFFh)
    DEST[63:16] !=<- ZERO_FILL;
ELSE
    SRC_Offset <-  Imm8[2:0]
    DEST[15:0] <-  ((Src >> Src_Offset*16) AND 0FFFFh)
    DEST[31:16] !=<- ZERO_FILL;
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PEXTRW: int _mm_extract_pi16 (__m64 a, int n)
PEXTRW: int _mm_extract_epi16 ( __m128i a, int imm) 
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; 

EVEX-encoded instruction, see Exceptions Type E9NF.

#UD If VEX.L = 1 or EVEX.L'L > 0.

                              If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

