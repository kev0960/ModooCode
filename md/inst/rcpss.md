----------------------------
title : RCPSS (Intel x86/64 assembly instruction)
cat_title : RCPSS
ref_title : RCPSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------
#@ RCPSS

**Compute Reciprocal of Scalar Single-Precision Floating-Point Values **

|**Opcode\htmlonly{*}/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F3 0F 53 /r\newline{}RCPSS xmm1, xmm2/m32|RM|V/V|SSE|Computes the approximate reciprocal of the scalar single-precision floating-point value in xmm2/m32 and stores the result in xmm1.|
|VEX.NDS.LIG.F3.0F.WIG 53 /r\newline{}VRCPSS xmm1, xmm2, xmm3/m32|RVM|V/V|AVX|Computes the approximate reciprocal of the scalar single-precision floating-point value in xmm3/m32 and stores the result in xmm1. Also, upper single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description


Computes of an approximate reciprocal of the low single-precision floating-point value in the source operand (second operand) and stores the single-precision floating-point result in the destination operand. The source operand can be an XMM register or a 32-bit memory location. The destination operand is an XMM register. The three high-order doublewords of the destination operand remain unchanged. See Figure 10-6 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for an illustration of a scalar single-precision floating-point operation.

The relative error for this approximation is:

    |Relative Error| <= 1.5 `\esc{*}` 2\footnote{-12}  

The `RCPSS` instruction is not affected by the rounding control bits in the MXCSR register. When a source value is a 0.0, an $$\infty$$ of the sign of the source value is returned. A denormal source value is treated as a 0.0 (of the same sign). Tiny results (see Section 4.9.1.5, "Numeric Underflow Exception (#U)" in Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 1) are always flushed to 0.0, with the sign of the operand. (Input values greater than or equal to |1.11111111110100000000000B`\esc{*}`2\footnote{125} | are guaranteed to not produce tiny results; input values less than or equal to |1.00000000000110000000001B\htmlonly{\esc{*}}2\footnote{126} | are guaranteed to produce tiny results, which are in turn flushed to 0.0; and input values in between this range may or may not produce tiny results, depending on the implementation.) When a source value is an SNaN or QNaN, the SNaN is converted to a QNaN or the source QNaN is returned.

In 64-bit mode, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

128-bit Legacy SSE version: The first source operand and the destination operand are the same. Bits (VLMAX-1:32) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination YMM register are zeroed.


### Operation
#### RCPSS (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  APPROXIMATE(1/SRC[31:0])
DEST[VLMAX-1:32] (Unmodified)
```
#### VRCPSS (VEX.128 encoded version)
```info-verb
DEST[31:0] <-  APPROXIMATE(1/SRC2[31:0])
DEST[127:32] <-  SRC1[127:32]
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
RCPSS: __m128 _mm_rcp_ss(__m128 a)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 5.

