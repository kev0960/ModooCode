----------------------------
title : CVTSS2SD (Intel x86/64 assembly instruction)
cat_title : CVTSS2SD
ref_title : CVTSS2SD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTSS2SD

**Convert Scalar Single-Precision Floating-Point Value to Scalar Double-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 5A /r\newline{}CVTSS2SD xmm1, xmm2/m32|RM|V/V|SSE2|Convert one single-precision floating-point value in xmm2/m32 to one double-precision floating-point value in xmm1.|
|VEX.NDS.128.F3.0F.WIG 5A /r\newline{}VCVTSS2SD xmm1, xmm2, xmm3/m32|RVM|V/V|AVX|Convert one single-precision floating-point value in xmm3/m32 to one double-precision floating-point value and merge with high bits of xmm2.|
|EVEX.NDS.LIG.F3.0F.W0 5A /r\newline{}VCVTSS2SD xmm1 {k1}{z}, xmm2, xmm3/m32{sae}|T1S|V/V|AVX512F|Convert one single-precision floating-point value in xmm3/m32 to one double-precision floating-point value and merge with high bits of xmm2 under writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
### Description


Converts a single-precision floating-point value in the "convert-from" source operand to a double-precision floating-point value in the destination operand. When the "convert-from" source operand is an XMM register, the single-precision floating-point value is contained in the low doubleword of the register. The result is stored in the low quadword of the destination operand.

128-bit Legacy SSE version: The "convert-from" source operand (the second operand) is an XMM register or memory location. Bits (MAX\esc{_}VL-1:64) of the corresponding destination register remain unchanged. The destina-tion operand is an XMM register. 

VEX.128 and EVEX encoded versions: The "convert-from" source operand (the third operand) can be an XMM register or a 32-bit memory location. The first source and destination operands are XMM registers. Bits (127:64) of the XMM register destination are copied from the corresponding bits in the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.

Software should ensure VCVTSS2SD is encoded with VEX.L=0. Encoding VCVTSS2SD with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### VCVTSS2SD (EVEX encoded version)
```info-verb
IF k1[0] or *no writemask*
    THEN DEST[63:0] <-  Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC2[31:0]);
    ELSE 
          IF *merging-masking* ; merging-masking
                THEN *DEST[63:0] remains unchanged*
                ELSE  ; zeroing-masking
                      THEN DEST[63:0] = 0
          FI;
FI;
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VCVTSS2SD (VEX.128 encoded version)
```info-verb
DEST[63:0] <- Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC2[31:0])
DEST[127:64] <- SRC1[127:64]
DEST[MAX_VL-1:128] <- 0
```
#### CVTSS2SD (128-bit Legacy SSE version)
```info-verb
DEST[63:0] <- Convert_Single_Precision_To_Double_Precision_Floating_Point(SRC[31:0]);
DEST[MAX_VL-1:64] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTSS2SD __m128d _mm_cvt_roundss_sd(__m128d a, __m128 b, int r);
VCVTSS2SD __m128d _mm_mask_cvt_roundss_sd(__m128d s, __mmask8 m, __m128d a,__m128 b, int r);
VCVTSS2SD __m128d _mm_maskz_cvt_roundss_sd(__mmask8 k, __m128d a, __m128 a, int r);
VCVTSS2SD __m128d _mm_mask_cvtss_sd(__m128d s, __mmask8 m, __m128d a,__m128 b);
VCVTSS2SD __m128d _mm_maskz_cvtss_sd(__mmask8 m, __m128d a,__m128 b);
CVTSS2SD __m128d_mm_cvtss_sd(__m128d a, __m128 a);
```
### SIMD Floating-Point Exceptions


Invalid, Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.

