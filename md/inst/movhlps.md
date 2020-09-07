----------------------------
title : MOVHLPS (Intel x86/64 assembly instruction)
cat_title : MOVHLPS
ref_title : MOVHLPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MOVHLPS

**Move Packed Single-Precision Floating-Point Values High to Low**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 12 /r\newline{}MOVHLPS xmm1, xmm2|RM|V/V|SSE|Move two packed single-precision floating-point values from high quadword of xmm2 to low quadword of xmm1.|
|VEX.NDS.128.0F.WIG 12 /r\newline{}VMOVHLPS xmm1, xmm2, xmm3|RVM|V/V|AVX|Merge two packed single-precision floating-point values from high quadword of xmm3 and low quadword of xmm2.|
|EVEX.NDS.128.0F.W0 12 /r\newline{}VMOVHLPS xmm1, xmm2, xmm3|RVM|V/V|AVX512F|Merge two packed single-precision floating-point values from high quadword of xmm3 and low quadword of xmm2.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|vvvv (r)|ModRM:r/m (r)|NA|
### Description


This instruction cannot be used for memory to register moves.

128-bit two-argument form:

Moves two packed single-precision floating-point values from the high quadword of the second XMM argument (second operand) to the low quadword of the first XMM register (first argument). The quadword at bits 127:64 of the destination operand is left unchanged. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

128-bit and EVEX three-argument form

Moves two packed single-precision floating-point values from the high quadword of the third XMM argument (third operand) to the low quadword of the destination (first operand). Copies the high quadword from the second XMM argument (second operand) to the high quadword of the destination (first operand). Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

If VMOVHLPS is encoded with VEX.L or EVEX.L'L= 1, an attempt to execute the instruction encoded with VEX.L or EVEX.L'L= 1 will cause an #UD exception.


### Operation
#### MOVHLPS (128-bit two-argument form)
```info-verb
DEST[63:0] <-  SRC[127:64]
DEST[MAX_VL-1:64] (Unmodified)
```
#### VMOVHLPS (128-bit three-argument form - VEX & EVEX)
```info-verb
DEST[63:0] <-  SRC2[127:64]
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVHLPS __m128 _mm_movehl_ps(__m128 a, __m128 b)
```
### SIMD Floating-Point Exceptions


None

```sidenote


1. ModRM.MOD = 011B required
```### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 7; additionally

#UD If VEX.L = 1.

EVEX-encoded instruction, see Exceptions Type E7NM.128.

