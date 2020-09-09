----------------------------
title : MOVHPD (Intel x86/64 assembly instruction)
cat_title : MOVHPD
ref_title : MOVHPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVHPD

**Move High Packed Double-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 16 /r\newline{}MOVHPD xmm1, m64|RM|V/V|SSE2|Move double-precision floating-point value from m64 to high quadword of xmm1.|
|VEX.NDS.128.66.0F.WIG 16 /r\newline{}VMOVHPD xmm2, xmm1, m64|RVM|V/V|AVX|Merge double-precision floating-point value from m64 and the low quadword of xmm1.|
|EVEX.NDS.128.66.0F.W1 16 /r\newline{}VMOVHPD xmm2, xmm1, m64|T1S|V/V|AVX512F|Merge double-precision floating-point value from m64 and the low quadword of xmm1.|
|66 0F 17 /r\newline{}MOVHPD m64, xmm1|MR|V/V|SSE2|Move double-precision floating-point value from high quadword of xmm1 to m64.|
|VEX.128.66.0F.WIG 17 /r\newline{}VMOVHPD m64, xmm1|MR|V/V|AVX|Move double-precision floating-point value from high quadword of xmm1 to m64.|
|EVEX.128.66.0F.W1 17 /r\newline{}VMOVHPD m64, xmm1|T1S-MR|V/V|AVX512F|Move double-precision floating-point value from high quadword of xmm1 to m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
|T1S-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


This instruction cannot be used for register to register or memory to memory moves.

128-bit Legacy SSE load:

Moves a double-precision floating-point value from the source 64-bit memory operand and stores it in the high 64-bits of the destination XMM register. The lower 64bits of the XMM register are preserved. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are preserved.

VEX.128 & EVEX encoded load:

Loads a double-precision floating-point value from the source 64-bit memory operand (the third operand) and stores it in the upper 64-bits of the destination XMM register (first operand). The low 64-bits from the first source operand (second operand) are copied to the low 64-bits of the destination. Bits (MAX\esc{_}VL-1:128) of the corre-sponding destination register are zeroed.

128-bit store:

Stores a double-precision floating-point value from the high 64-bits of the XMM register source (second operand) to the 64-bit memory location (first operand).

Note: VMOVHPD (store) (VEX.128.66.0F 17 /r) is legal and has the same behavior as the existing 66 0F 17 store. For VMOVHPD (store) VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instruction will #UD.

If VMOVHPD is encoded with VEX.L or EVEX.L'L= 1, an attempt to execute the instruction encoded with VEX.L or EVEX.L'L= 1 will cause an #UD exception.


### Operation
#### MOVHPD (128-bit Legacy SSE load)
```info-verb
DEST[63:0] (Unmodified)
DEST[127:64] <-  SRC[63:0]
DEST[MAX_VL-1:128] (Unmodified)
```
#### VMOVHPD (VEX.128 & EVEX encoded load)
```info-verb
DEST[63:0] <-  SRC1[63:0]
DEST[127:64] <-  SRC2[63:0]
DEST[MAX_VL-1:128] <-  0
```
#### VMOVHPD (store)
```info-verb
DEST[63:0] <-  SRC[127:64]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVHPD __m128d _mm_loadh_pd ( __m128d a, double *p)
MOVHPD void _mm_storeh_pd (double *p, __m128d a)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; additionally

#UD If VEX.L = 1.

EVEX-encoded instruction, see Exceptions Type E9NF.

