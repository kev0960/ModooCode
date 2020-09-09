----------------------------
title : VFPCLASSPS (Intel x86/64 assembly instruction)
cat_title : VFPCLASSPS
ref_title : VFPCLASSPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFPCLASSPS

**Tests Types Of a Packed Float32 Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F3A.W0 66 /r ib\newline{}VFPCLASSPS k2 {k1}, xmm2/m128/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
|EVEX.256.66.0F3A.W0 66 /r ib\newline{}VFPCLASSPS k2 {k1}, ymm2/m256/m32bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
|EVEX.512.66.0F3A.W0 66 /r ib\newline{}VFPCLASSPS k2 {k1}, zmm2/m512/m32bcst, imm8|FV|V/V|AVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|FV|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


The FPCLASSPS instruction checks the packed single-precision floating point values for special categories, specified by the set bits in the imm8 byte. Each set bit in imm8 specifies a category of floating-point values that the input data element is classified against. The classified results of all specified categories of an input value are ORed together to form the final boolean result for the input element. The result of each element is written to the corre-sponding bit in a mask register k2 according to the writemask k1. Bits [MAX\esc{_}KL-1:16/8/4] of the destination are cleared.

The classification categories specified by imm8 are shown in Figure 5-13. The classification test for each category is listed in Table 5-6.

The source operand is a ZMM/YMM/XMM register, a 512/256/128-bit memory location, or a 512/256/128-bit vector broadcasted from a 32-bit memory location.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VFPCLASSPS (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN 
                IF (EVEX.b == 1) AND (SRC *is memory*)
                      THEN
                            DEST[j] <-  CheckFPClassDP(SRC1[31:0], imm8[7:0]);
                      ELSE 
                            DEST[j] <-  CheckFPClassDP(SRC1[i+31:i], imm8[7:0]);
                FI;
          ELSE  DEST[j] <-  0 ; zeroing-masking only
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFPCLASSPS __mmask16 _mm512_fpclass_ps_mask( __m512 a, int c);
VFPCLASSPS __mmask16 _mm512_mask_fpclass_ps_mask( __mmask16 m, __m512 a, int c)
VFPCLASSPS __mmask8 _mm256_fpclass_ps_mask( __m256 a, int c)
VFPCLASSPS __mmask8 _mm256_mask_fpclass_ps_mask( __mmask8 m, __m256 a, int c)
VFPCLASSPS __mmask8 _mm_fpclass_ps_mask( __m128 a, int c)
VFPCLASSPS __mmask8 _mm_mask_fpclass_ps_mask( __mmask8 m, __m128 a, int c)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E4

#UD If EVEX.vvvv != 1111B.

