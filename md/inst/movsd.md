----------------------------
title : MOVSD (Intel x86/64 assembly instruction)
cat_title : MOVSD
ref_title : MOVSD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MOVSD

**Move or Merge Scalar Double-Precision Floating-Point Value**

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F 10 /r\newline{}MOVSD xmm1, xmm2|RM|V/V|SSE2|Move scalar double-precision floating-point value from xmm2 to xmm1 register.|
|F2 0F 10 /r\newline{}MOVSD xmm1, m64|RM|V/V|SSE2|Load scalar double-precision floating-point value from m64 to xmm1 register.|
|F2 0F 11 /r\newline{}MOVSD xmm1/m64, xmm2|MR|V/V|SSE2|Move scalar double-precision floating-point value from xmm2 register to xmm1/m64.|
|VEX.NDS.LIG.F2.0F.WIG 10 /r\newline{}VMOVSD xmm1, xmm2, xmm3|RVM|V/V|AVX|Merge scalar double-precision floating-point value from xmm2 and xmm3 to xmm1 register.|
|VEX.LIG.F2.0F.WIG 10 /r\newline{}VMOVSD xmm1, m64|XM|V/V|AVX|Load scalar double-precision floating-point value from m64 to xmm1 register.|
|VEX.NDS.LIG.F2.0F.WIG 11 /r\newline{}VMOVSD xmm1, xmm2, xmm3|MVR|V/V|AVX|Merge scalar double-precision floating-point value from xmm2 and xmm3 registers to xmm1.|
|VEX.LIG.F2.0F.WIG 11 /r\newline{}VMOVSD m64, xmm1|MR|V/V|AVX|Store scalar double-precision floating-point value from xmm1 register to m64.|
|EVEX.NDS.LIG.F2.0F.W1 10 /r\newline{}VMOVSD xmm1 {k1}{z}, xmm2, xmm3|RVM|V/V|AVX512F|Merge scalar double-precision floating-point value from xmm2 and xmm3 registers to xmm1 under writemask k1.|
|EVEX.LIG.F2.0F.W1 10 /r\newline{}VMOVSD xmm1 {k1}{z}, m64|T1S-RM|V/V|AVX512F|Load scalar double-precision floating-point value from m64 to xmm1 register under writemask k1.|
|EVEX.NDS.LIG.F2.0F.W1 11 /r\newline{}VMOVSD xmm1 {k1}{z}, xmm2, xmm3|MVR|V/V|AVX512F|Merge scalar double-precision floating-point value from xmm2 and xmm3 registers to xmm1 under writemask k1.|
|EVEX.LIG.F2.0F.W1 11 /r\newline{}VMOVSD m64 {k1}, xmm1|T1S-MR|V/V|AVX512F|Store scalar double-precision floating-point value from xmm1 register to m64 under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|XM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|MVR|ModRM:r/m (w)|vvvv (r)|ModRM:reg (r)|NA|
|T1S-RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|T1S-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Moves a scalar double-precision floating-point value from the source operand (second operand) to the destination operand (first operand). The source and destination operands can be XMM registers or 64-bit memory locations. This instruction can be used to move a double-precision floating-point value to and from the low quadword of an XMM register and a 64-bit memory location, or to move a double-precision floating-point value between the low quadwords of two XMM registers. The instruction cannot be used to transfer data between memory locations.

Legacy version: When the source and destination operands are XMM registers, bits MAX\esc{_}VL:64 of the destination operand remains unchanged. When the source operand is a memory location and destination operand is an XMM registers, the quadword at bits 127:64 of the destination operand is cleared to all 0s, bits MAX\esc{_}VL:128 of the desti-nation operand remains unchanged. 

VEX and EVEX encoded register-register syntax: Moves a scalar double-precision floating-point value from the second source operand (the third operand) to the low quadword element of the destination operand (the first operand). Bits 127:64 of the destination operand are copied from the first source operand (the second operand). Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

VEX and EVEX encoded memory store syntax: When the source operand is a memory location and destination operand is an XMM registers, bits MAX\esc{_}VL:64 of the destination operand is cleared to all 0s.

EVEX encoded versions: The low quadword of the destination is updated according to the writemask.

Note: For VMOVSD (memory store and load forms), VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instruction will #UD.


### Operation
#### VMOVSD (EVEX.NDS.LIG.F2.0F 10 /r: VMOVSD xmm1, m64 with support for 32 registers)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  SRC[63:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] <-  0
          FI;
FI;
DEST[511:64] <-  0
```
#### VMOVSD (EVEX.NDS.LIG.F2.0F 11 /r: VMOVSD m64, xmm1 with support for 32 registers)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  SRC[63:0]
    ELSE *DEST[63:0] remains unchanged*  ; merging-masking
FI;
```
#### VMOVSD (EVEX.NDS.LIG.F2.0F 11 /r: VMOVSD xmm1, xmm2, xmm3)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  SRC2[63:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] <-  0
          FI;
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### MOVSD (128-bit Legacy SSE version: MOVSD XMM1, XMM2)
```info-verb
DEST[63:0] <- SRC[63:0]
DEST[MAX_VL-1:64] (Unmodified)
```
#### VMOVSD (VEX.NDS.128.F2.0F 11 /r: VMOVSD xmm1, xmm2, xmm3)
```info-verb
DEST[63:0] <- SRC2[63:0]
DEST[127:64] <- SRC1[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### VMOVSD (VEX.NDS.128.F2.0F 10 /r: VMOVSD xmm1, xmm2, xmm3)
```info-verb
DEST[63:0] <- SRC2[63:0]
DEST[127:64] <- SRC1[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### VMOVSD (VEX.NDS.128.F2.0F 10 /r: VMOVSD xmm1, m64)
```info-verb
DEST[63:0] <- SRC[63:0]
DEST[MAX_VL-1:64] <- 0
```
#### MOVSD/VMOVSD (128-bit versions: MOVSD m64, xmm1 or VMOVSD m64, xmm1)
```info-verb
DEST[63:0] <- SRC[63:0]
```
#### MOVSD (128-bit Legacy SSE version: MOVSD XMM1, m64)
```info-verb
DEST[63:0] <- SRC[63:0]
DEST[127:64] <- 0
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVSD __m128d _mm_mask_load_sd(__m128d s, __mmask8 k, double * p); 
VMOVSD __m128d _mm_maskz_load_sd( __mmask8 k, double * p); 
VMOVSD __m128d _mm_mask_move_sd(__m128d sh, __mmask8 k, __m128d sl, __m128d a); 
VMOVSD __m128d _mm_maskz_move_sd( __mmask8 k, __m128d s, __m128d a); 
VMOVSD void _mm_mask_store_sd(double * p, __mmask8 k, __m128d s); 
MOVSD __m128d _mm_load_sd (double *p)
MOVSD void _mm_store_sd (double *p, __m128d a)
MOVSD __m128d _mm_move_sd ( __m128d a, __m128d b)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; additionally

#UD If VEX.vvvv != 1111B.

EVEX-encoded instruction, see Exceptions Type E10.

