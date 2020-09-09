----------------------------
title : RSQRTPS (Intel x86/64 assembly instruction)
cat_title : RSQRTPS
ref_title : RSQRTPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RSQRTPS

**Compute Reciprocals of Square Roots of Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 52 /r\newline{}RSQRTPS xmm1, xmm2/m128|RM|V/V|SSE|Computes the approximate reciprocals of the square roots of the packed single-precision floating-point values in xmm2/m128 and stores the results in xmm1.|
|VEX.128.0F.WIG 52 /r\newline{}VRSQRTPS xmm1, xmm2/m128|RM|V/V|AVX|Computes the approximate reciprocals of the square roots of packed single-precision values in xmm2/mem and stores the results in xmm1.|
|VEX.256.0F.WIG 52 /r\newline{}VRSQRTPS ymm1, ymm2/m256|RM|V/V|AVX|Computes the approximate reciprocals of the square roots of packed single-precision values in ymm2/mem and stores the results in ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Performs a SIMD computation of the approximate reciprocals of the square roots of the four packed single-preci-sion floating-point values in the source operand (second operand) and stores the packed single-precision floating-point results in the destination operand. The source operand can be an XMM register or a 128-bit memory location. The destination operand is an XMM register. See Figure 10-5 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for an illustration of a SIMD single-precision floating-point operation.

The relative error for this approximation is:

    |Relative Error| <= 1.5 `\esc{*}` 2\footnote{-12}  

The `RSQRTPS` instruction is not affected by the rounding control bits in the MXCSR register. When a source value is a 0.0, an $$\infty$$ of the sign of the source value is returned. A denormal source value is treated as a 0.0 (of the same sign). When a source value is a negative value (other than -0.0), a floating-point indefinite is returned. When a source value is an SNaN or QNaN, the SNaN is converted to a QNaN or the source QNaN is returned. 

In 64-bit mode, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

128-bit Legacy SSE version: The second source can be an XMM register or an 128-bit memory location. The desti-nation is not distinct from the first source XMM register and the upper bits (VLMAX-1:128) of the corresponding YMM register destination are unmodified.

VEX.128 encoded version: the first source operand is an XMM register or 128-bit memory location. The destination operand is an XMM register. The upper bits (VLMAX-1:128) of the corresponding YMM register destination are zeroed.

VEX.256 encoded version: The first source operand is a YMM register. The second source operand can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. 

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### RSQRTPS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  APPROXIMATE(1/SQRT(SRC[31:0]))
DEST[63:32] <-  APPROXIMATE(1/SQRT(SRC1[63:32]))
DEST[95:64] <-  APPROXIMATE(1/SQRT(SRC1[95:64]))
DEST[127:96] <-  APPROXIMATE(1/SQRT(SRC2[127:96]))
DEST[VLMAX-1:128] (Unmodified)
```
#### VRSQRTPS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  APPROXIMATE(1/SQRT(SRC[31:0]))
DEST[63:32] <-  APPROXIMATE(1/SQRT(SRC1[63:32]))
DEST[95:64] <-  APPROXIMATE(1/SQRT(SRC1[95:64]))
DEST[127:96] <-  APPROXIMATE(1/SQRT(SRC2[127:96]))
DEST[VLMAX-1:128] <-  0
```
#### VRSQRTPS (VEX.256 encoded version)
```info-verb
DEST[31:0] <-  APPROXIMATE(1/SQRT(SRC[31:0]))
DEST[63:32] <-  APPROXIMATE(1/SQRT(SRC1[63:32]))
DEST[95:64] <-  APPROXIMATE(1/SQRT(SRC1[95:64]))
DEST[127:96] <-  APPROXIMATE(1/SQRT(SRC2[127:96]))
DEST[159:128] <-  APPROXIMATE(1/SQRT(SRC2[159:128]))
DEST[191:160] <-  APPROXIMATE(1/SQRT(SRC2[191:160]))
DEST[223:192] <-  APPROXIMATE(1/SQRT(SRC2[223:192]))
DEST[255:224] <-  APPROXIMATE(1/SQRT(SRC2[255:224]))
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
RSQRTPS: __m128 _mm_rsqrt_ps(__m128 a)
RSQRTPS:  __m256 _mm256_rsqrt_ps (__m256 a);
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.vvvv ->  1111B.

