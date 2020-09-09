----------------------------
title : ROUNDSS (Intel x86/64 assembly instruction)
cat_title : ROUNDSS
ref_title : ROUNDSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ ROUNDSS

** Round Scalar Single Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 3A 0A /r ibROUNDSS xmm1, xmm2/m32, imm8|RMI|V/V|SSE4_1|Round the low packed single precision floating-point value in xmm2/m32 and place the result in xmm1.  The rounding mode is determined by imm8.|
|VEX.NDS.LIG.66.0F3A.WIG 0A /r ibVROUNDSS xmm1, xmm2, xmm3/m32, imm8|RVMI|V/V|AVX|Round the low packed single precision floating-point value in xmm3/m32 and place the result in xmm1. The rounding mode is determined by imm8. Also, upper packed single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
### Description


Round the single-precision floating-point value in the lowest dword of the source operand (second operand) using the rounding mode specified in the immediate operand (third operand) and place the result in the destination operand (first operand). The rounding process rounds a single-precision floating-point input to an integer value and returns the result as a single-precision floating-point value in the lowest position. The upper three single-precision floating-point values in the destination are retained. 

The immediate operand specifies control fields for the rounding operation, three bit fields are defined and shown in Figure 4-24. Bit 3 of the immediate byte controls processor behavior for a precision exception, bit 2 selects the source of rounding mode control. Bits 1:0 specify a non-sticky rounding-mode value (Table 4-18 lists the encoded values for rounding-mode field). 

The Precision Floating-Point Exception is signaled according to the immediate operand. If any source operand is an SNaN then it will be converted to a QNaN. If DAZ is set to '1 then denormals will be converted to zero before rounding.

128-bit Legacy SSE version: The first source operand and the destination operand are the same. Bits (VLMAX-1:32) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination YMM register are zeroed.


### Operation
#### ROUNDSS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  RoundToInteger(SRC[31:0], ROUND_CONTROL)
DEST[VLMAX-1:32] (Unmodified)
```
#### VROUNDSS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  RoundToInteger(SRC2[31:0], ROUND_CONTROL)
DEST[127:32] <-  SRC1[127:32]
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
ROUNDSS: __m128 mm_round_ss(__m128 dst, __m128 s1, int iRoundMode);__m128 mm_floor_ss(__m128 dst, __m128 s1);__m128 mm_ceil_ss(__m128 dst, __m128 s1);
```
### SIMD Floating-Point Exceptions


Invalid (signaled only if SRC = SNaN) 

Precision (signaled only if imm[3] = '0; if imm[3] = '1, then the Precision Mask in the MXSCSR is ignored and preci-sion exception is not signaled.)

Note that Denormal is not signaled by ROUNDSS.

### Other Exceptions


See Exceptions Type 3.

