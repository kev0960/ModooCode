----------------------------
title : MOVSS (Intel x86/64 assembly instruction)
cat_title : MOVSS
ref_title : MOVSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MOVSS

**Move or Merge Scalar Single-Precision Floating-Point Value**

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 10 /r\newline{}MOVSS xmm1, xmm2|RM|V/V|SSE|Merge scalar single-precision floating-point value from xmm2 to xmm1 register.|
|F3 0F 10 /r\newline{}MOVSS xmm1, m32|RM|V/V|SSE|Load scalar single-precision floating-point value from m32 to xmm1 register.|
|VEX.NDS.LIG.F3.0F.WIG 10 /r\newline{}VMOVSS xmm1, xmm2, xmm3|RVM|V/V|AVX|Merge scalar single-precision floating-point value from xmm2 and xmm3 to xmm1 register|
|VEX.LIG.F3.0F.WIG 10 /r\newline{}VMOVSS xmm1, m32|XM|V/V|AVX|Load scalar single-precision floating-point value from m32 to xmm1 register.|
|F3 0F 11 /r\newline{}MOVSS xmm2/m32, xmm1|MR|V/V|SSE|Move scalar single-precision floating-point value from xmm1 register to xmm2/m32.|
|VEX.NDS.LIG.F3.0F.WIG 11 /r\newline{}VMOVSS xmm1, xmm2, xmm3|MVR|V/V|AVX|Move scalar single-precision floating-point value from xmm2 and xmm3 to xmm1 register.|
|VEX.LIG.F3.0F.WIG 11 /r\newline{}VMOVSS m32, xmm1|MR|V/V|AVX|Move scalar single-precision floating-point value from xmm1 register to m32.|
|EVEX.NDS.LIG.F3.0F.W0 10 /r\newline{}VMOVSS xmm1 {k1}{z}, xmm2, xmm3|RVM|V/V|AVX512F|Move scalar single-precision floating-point value from xmm2 and xmm3 to xmm1 register under writemask k1.|
|EVEX.LIG.F3.0F.W0 10 /r\newline{}VMOVSS xmm1 {k1}{z}, m32|T1S-RM|V/V|AVX512F|Move scalar single-precision floating-point values from m32 to xmm1 under writemask k1.|
|EVEX.NDS.LIG.F3.0F.W0 11 /r\newline{}VMOVSS xmm1 {k1}{z}, xmm2, xmm3|MVR|V/V|AVX512F|Move scalar single-precision floating-point value from xmm2 and xmm3 to xmm1 register under writemask k1.|
|EVEX.LIG.F3.0F.W0 11 /r\newline{}VMOVSS m32 {k1}, xmm1|T1S-MR|V/V|AVX512F|Move scalar single-precision floating-point values from xmm1 to m32 under writemask k1.|
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


Moves a scalar single-precision floating-point value from the source operand (second operand) to the destination operand (first operand). The source and destination operands can be XMM registers or 32-bit memory locations. This instruction can be used to move a single-precision floating-point value to and from the low doubleword of an XMM register and a 32-bit memory location, or to move a single-precision floating-point value between the low doublewords of two XMM registers. The instruction cannot be used to transfer data between memory locations.

Legacy version: When the source and destination operands are XMM registers, bits (MAX\esc{_}VL-1:32) of the corre-sponding destination register are unmodified. When the source operand is a memory location and destination operand is an XMM registers, Bits (127:32) of the destination operand is cleared to all 0s, bits MAX\esc{_}VL:128 of the destination operand remains unchanged. 

VEX and EVEX encoded register-register syntax: Moves a scalar single-precision floating-point value from the second source operand (the third operand) to the low doubleword element of the destination operand (the first operand). Bits 127:32 of the destination operand are copied from the first source operand (the second operand). Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are zeroed.

VEX and EVEX encoded memory load syntax: When the source operand is a memory location and destination operand is an XMM registers, bits MAX\esc{_}VL:32 of the destination operand is cleared to all 0s.

EVEX encoded versions: The low doubleword of the destination is updated according to the writemask.

Note: For memory store form instruction "VMOVSS m32, xmm1", VEX.vvvv is reserved and must be 1111b other-wise instruction will #UD. For memory store form instruction "VMOVSS mv {k1}, xmm1", EVEX.vvvv is reserved and must be 1111b otherwise instruction will #UD.

Software should ensure VMOVSS is encoded with VEX.L=0. Encoding VMOVSS with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### VMOVSS (EVEX.NDS.LIG.F3.0F.W0 11 /r when the source operand is memory and the destination is an XMM register)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  SRC[31:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[511:32] <-  0
```
#### VMOVSS (EVEX.NDS.LIG.F3.0F.W0 10 /r when the source operand is an XMM register and the destination is memory)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  SRC[31:0]
    ELSE *DEST[31:0] remains unchanged*  ; merging-masking
FI;
```
#### VMOVSS (EVEX.NDS.LIG.F3.0F.W0 10/11 /r where the source and destination are XMM registers)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[31:0] <-  SRC2[31:0]
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[31:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[31:0] <-  0
          FI;
FI;
DEST[127:32] <-  SRC1[127:32]
DEST[MAX_VL-1:128] <-  0
```
#### MOVSS (Legacy SSE version when the source and destination operands are both XMM registers)
```info-verb
DEST[31:0] <- SRC[31:0]
DEST[MAX_VL-1:32] (Unmodified)
```
#### VMOVSS (VEX.NDS.128.F3.0F 11 /r where the destination is an XMM register)
```info-verb
DEST[31:0] <- SRC2[31:0]
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### VMOVSS (VEX.NDS.128.F3.0F 10 /r where the source and destination are XMM registers)
```info-verb
DEST[31:0] <- SRC2[31:0]
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```
#### VMOVSS (VEX.NDS.128.F3.0F 10 /r when the source operand is memory and the destination is an XMM register)
```info-verb
DEST[31:0] <- SRC[31:0]
DEST[MAX_VL-1:32] <- 0
```
#### MOVSS/VMOVSS (when the source operand is an XMM register and the destination is memory)
```info-verb
DEST[31:0] <- SRC[31:0]
```
#### MOVSS (Legacy SSE version when the source operand is memory and the destination is an XMM register)
```info-verb
DEST[31:0] <- SRC[31:0]
DEST[127:32] <- 0
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVSS __m128 _mm_mask_load_ss(__m128 s, __mmask8 k, float * p); 
VMOVSS __m128 _mm_maskz_load_ss( __mmask8 k, float * p); 
VMOVSS __m128 _mm_mask_move_ss(__m128 sh, __mmask8 k, __m128 sl, __m128 a); 
VMOVSS __m128 _mm_maskz_move_ss( __mmask8 k, __m128 s, __m128 a); 
VMOVSS void _mm_mask_store_ss(float * p, __mmask8 k, __m128 a); 
MOVSS __m128 _mm_load_ss(float * p)
MOVSS void_mm_store_ss(float * p, __m128 a)
MOVSS __m128 _mm_move_ss(__m128 a, __m128 b)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; additionally

#UD If VEX.vvvv != 1111B.

EVEX-encoded instruction, see Exceptions Type E10.

