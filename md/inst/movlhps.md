----------------------------
title : MOVLHPS (Intel x86/64 assembly instruction)
cat_title : MOVLHPS
ref_title : MOVLHPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MOVLHPS

**Move Packed Single-Precision Floating-Point Values Low to High**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 16 /r\newline{}MOVLHPS xmm1, xmm2|RM|V/V|SSE|Move two packed single-precision floating-point values from low quadword of xmm2 to high quadword of xmm1.|
|VEX.NDS.128.0F.WIG 16 /r\newline{}VMOVLHPS xmm1, xmm2, xmm3|RVM|V/V|AVX|Merge two packed single-precision floating-point values from low quadword of xmm3 and low quadword of xmm2.|
|EVEX.NDS.128.0F.W0 16 /r\newline{}VMOVLHPS xmm1, xmm2, xmm3|RVM|V/V|AVX512F|Merge two packed single-precision floating-point values from low quadword of xmm3 and low quadword of xmm2.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|vvvv (r)|ModRM:r/m (r)|NA|
### Description


This instruction cannot be used for memory to register moves.

128-bit two-argument form:

Moves two packed single-precision floating-point values from the low quadword of the second XMM argument (second operand) to the high quadword of the first XMM register (first argument). The low quadword of the desti-nation operand is left unchanged. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are unmodified.

128-bit three-argument forms:

Moves two packed single-precision floating-point values from the low quadword of the third XMM argument (third operand) to the high quadword of the destination (first operand). Copies the low quadword from the second XMM argument (second operand) to the low quadword of the destination (first operand). Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

If VMOVLHPS is encoded with VEX.L or EVEX.L'L= 1, an attempt to execute the instruction encoded with VEX.L or EVEX.L'L= 1 will cause an #UD exception.


### Operation
#### MOVLHPS (128-bit two-argument form)
```info-verb
DEST[63:0] (Unmodified)
DEST[127:64] <-  SRC[63:0]
DEST[MAX_VL-1:128] (Unmodified)
```
#### VMOVLHPS (128-bit three-argument form - VEX & EVEX)
```info-verb
DEST[63:0] <-  SRC1[63:0]
DEST[127:64] <-  SRC2[63:0]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVLHPS __m128 _mm_movelh_ps(__m128 a, __m128 b)
```
### SIMD Floating-Point Exceptions


None

```sidenote


1. ModRM.MOD = 011B required
```### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 7; additionally

#UD If VEX.L = 1.

EVEX-encoded instruction, see Exceptions Type E7NM.128.

