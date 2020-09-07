----------------------------
title : MOVHPS (Intel x86/64 assembly instruction)
cat_title : MOVHPS
ref_title : MOVHPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MOVHPS

**Move High Packed Single-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 16 /r\newline{}MOVHPS xmm1, m64|RM|V/V|SSE|Move two packed single-precision floating-point values from m64 to high quadword of xmm1.|
|VEX.NDS.128.0F.WIG 16 /r\newline{}VMOVHPS xmm2, xmm1, m64|RVM|V/V|AVX|Merge two packed single-precision floating-point values from m64 and the low quadword of xmm1.|
|EVEX.NDS.128.0F.W0 16 /r\newline{}VMOVHPS xmm2, xmm1, m64|T2|V/V|AVX512F|Merge two packed single-precision floating-point values from m64 and the low quadword of xmm1.|
|0F 17 /r\newline{}MOVHPS m64, xmm1|MR|V/V|SSE|Move two packed single-precision floating-point values from high quadword of xmm1 to m64.|
|VEX.128.0F.WIG 17 /r\newline{}VMOVHPS m64, xmm1|MR|V/V|AVX|Move two packed single-precision floating-point values from high quadword of xmm1 to m64.|
|EVEX.128.0F.W0 17 /r\newline{}VMOVHPS m64, xmm1|T2-MR|V/V|AVX512F|Move two packed single-precision floating-point values from high quadword of xmm1 to m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|T2|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
|T2-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


This instruction cannot be used for register to register or memory to memory moves.

128-bit Legacy SSE load:

Moves two packed single-precision floating-point values from the source 64-bit memory operand and stores them in the high 64-bits of the destination XMM register. The lower 64bits of the XMM register are preserved. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are preserved.

VEX.128 & EVEX encoded load:

Loads two single-precision floating-point values from the source 64-bit memory operand (the third operand) and stores it in the upper 64-bits of the destination XMM register (first operand). The low 64-bits from the first source operand (the second operand) are copied to the lower 64-bits of the destination. Bits (MAX\esc{_}VL-1:128) of the corre-sponding destination register are zeroed.

128-bit store:

Stores two packed single-precision floating-point values from the high 64-bits of the XMM register source (second operand) to the 64-bit memory location (first operand).

Note: VMOVHPS (store) (VEX.NDS.128.0F 17 /r) is legal and has the same behavior as the existing 0F 17 store. For VMOVHPS (store) VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instruction will #UD.

If VMOVHPS is encoded with VEX.L or EVEX.L'L= 1, an attempt to execute the instruction encoded with VEX.L or EVEX.L'L= 1 will cause an #UD exception.


### Operation
#### MOVHPS (128-bit Legacy SSE load)
```info-verb
DEST[63:0] (Unmodified)
DEST[127:64] <-  SRC[63:0]
DEST[MAX_VL-1:128] (Unmodified)
```
#### VMOVHPS (VEX.128 and EVEX encoded load)
```info-verb
DEST[63:0] <-  SRC1[63:0]
DEST[127:64] <-  SRC2[63:0]
DEST[MAX_VL-1:128] <-  0
```
#### VMOVHPS (store)
```info-verb
DEST[63:0] <-  SRC[127:64]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVHPS __m128 _mm_loadh_pi ( __m128 a, __m64 *p)
MOVHPS void _mm_storeh_pi (__m64 *p, __m128 a)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; additionally

#UD If VEX.L = 1.

EVEX-encoded instruction, see Exceptions Type E9NF.

