----------------------------
title : VFPCLASSSS (Intel x86/64 assembly instruction)
cat_title : VFPCLASSSS
ref_title : VFPCLASSSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFPCLASSSS

**Tests Types Of a Scalar Float32 Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.LIG.66.0F3A.W0 67 /r\newline{}VFPCLASSSS k2 {k1}, xmm2/m32, imm8|T1S|V/V|AVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


The FPCLASSSS instruction checks the low single-precision floating point value in the source operand for special categories, specified by the set bits in the imm8 byte. Each set bit in imm8 specifies a category of floating-point values that the input data element is classified against. The classified results of all specified categories of an input value are ORed together to form the final boolean result for the input element. The result is written to the low bit in a mask register k2 according to the writemask k1. Bits MAX\esc{_}KL-1: 1 of the destination are cleared.

The classification categories specified by imm8 are shown in Figure 5-13. The classification test for each category is listed in Table 5-6.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VFPCLASSSS (EVEX encoded version)
```info-verb
IF k1[0] OR *no writemask*
    THEN DEST[0] <-  
                CheckFPClassSP(SRC1[31:0], imm8[7:0])
    ELSE  DEST[0] <-  0 ; zeroing-masking only
FI;
DEST[MAX_KL-1:1] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFPCLASSSS __mmask8 _mm_fpclass_ss_mask( __m128 a, int c)
VFPCLASSSS __mmask8 _mm_mask_fpclass_ss_mask( __mmask8 m, __m128 a, int c)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E6

#UD If EVEX.vvvv != 1111B.

