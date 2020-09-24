----------------------------
title : VFPCLASSSD (Intel x86/64 assembly instruction)
cat_title : VFPCLASSSD
ref_title : VFPCLASSSD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VFPCLASSSD

**Tests Types Of a Scalar Float64 Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.LIG.66.0F3A.W1 67 /r ib`\newline{}`VFPCLASSSD` k2 \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{xmm2/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S|V/V|AVX512DQ|Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


The FPCLASSSD instruction checks the low double precision floating point value in the source operand for special categories, specified by the set bits in the imm8 byte. Each set bit in imm8 specifies a category of floating-point values that the input data element is classified against. The classified results of all specified categories of an input value are ORed together to form the final boolean result for the input element. The result is written to the low bit in a mask register k2 according to the writemask k1. Bits MAX\esc{_}KL-1: 1 of the destination are cleared.

The classification categories specified by imm8 are shown in Figure 5-13. The classification test for each category is listed in Table 5-6.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VFPCLASSSD (EVEX encoded version)
```info-verb
IF k1[0] OR *no writemask*
    THEN DEST[0] <-  
                CheckFPClassDP(SRC1[63:0], imm8[7:0])
    ELSE  DEST[0] <-  0 ; zeroing-masking only
FI;
DEST[MAX_KL-1:1] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VFPCLASSSD __mmask8 _mm_fpclass_sd_mask( __m128d a, int c)
VFPCLASSSD __mmask8 _mm_mask_fpclass_sd_mask( __mmask8 m, __m128d a, int c)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E6

#UD If EVEX.vvvv != 1111B.

