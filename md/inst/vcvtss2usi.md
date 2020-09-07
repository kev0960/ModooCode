----------------------------
title : VCVTSS2USI (Intel x86/64 assembly instruction)
cat_title : VCVTSS2USI
ref_title : VCVTSS2USI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------
#@ VCVTSS2USI

**Convert Scalar Single-Precision Floating-Point Value to Unsigned Doubleword Integer**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.LIG.F3.0F.W0 79 /r\newline{}VCVTSS2USI r32, xmm1/m32{er}|T1F|V/V|AVX512F|Convert one single-precision floating-point value from xmm1/m32 to one unsigned doubleword integer in r32.|
|EVEX.LIG.F3.0F.W1 79 /r\newline{}VCVTSS2USI r64, xmm1/m32{er}|T1F|V/N.E.\footnote{1}|AVX512F|Convert one single-precision floating-point value from xmm1/m32 to one unsigned quadword integer in r64.|
||||||

```note
1. EVEX.W1 in non-64 bit is ignored; the instructions behaves as if the W0 version is used
```
###                                                        Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

 T1F ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts a single-precision floating-point value in the source operand (the second operand) to an unsigned double-word integer (or unsigned quadword integer if operand size is 64 bits) in the destination operand (the first operand). The source operand can be an XMM register or a memory location. The destination operand is a general-purpose register. When the source operand is an XMM register, the single-precision floating-point value is contained in the low doubleword of the register.

When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register or the embedded rounding control bits. If a converted result cannot be represented in the destination format, the floating-point invalid exception is raised, and if this exception is masked, the integer value 2\footnote{w}  - 1 is returned, where w represents the number of bits in the destination format.

VEX.W1 and EVEX.W1 versions: promotes the instruction to produce 64-bit data in 64-bit mode.

Note: EVEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### VCVTSS2USI (EVEX encoded version)
```info-verb
IF (SRC *is register*) AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF 64-bit Mode and OperandSize = 64
THEN
    DEST[63:0] <-  Convert_Single_Precision_Floating_Point_To_UInteger(SRC[31:0]);
ELSE
    DEST[31:0] <-  Convert_Single_Precision_Floating_Point_To_UInteger(SRC[31:0]);
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTSS2USI unsigned _mm_cvtss_u32( __m128 a);
VCVTSS2USI unsigned _mm_cvt_roundss_u32( __m128 a, int r);
VCVTSS2USI unsigned __int64 _mm_cvtss_u64( __m128 a);
VCVTSS2USI unsigned __int64 _mm_cvt_roundss_u64( __m128 a, int r);
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E3NF.

