----------------------------
title : VCVTTSD2USI (Intel x86/64 assembly instruction)
cat_title : VCVTTSD2USI
ref_title : VCVTTSD2USI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCVTTSD2USI

**Convert with Truncation Scalar Double-Precision Floating-Point Value to Unsigned Integer**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.LIG.F2.0F.W0 78 /r\newline{}VCVTTSD2USI r32, xmm1/m64{sae}|T1F|V/V|AVX512F|Convert one double-precision floating-point value from xmm1/m64 to one unsigned doubleword integer r32 using truncation.|
|EVEX.LIG.F2.0F.W1 78 /r\newline{}VCVTTSD2USI r64, xmm1/m64{sae}|T1F|V/N.E.\footnote{1}|AVX512F|Convert one double-precision floating-point value from xmm1/m64 to one unsigned quadword integer zero-extended into r64 using truncation.|
||||||

```note
1. For this specific instruction, EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 version isused
```
###                                                        Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

 T1F ModRM:reg (w) ModRM:r/m (r) NA NA

### Description


Converts with truncation a double-precision floating-point value in the source operand (the second operand) to an unsigned doubleword integer (or unsigned quadword integer if operand size is 64 bits) in the destination operand (the first operand). The source operand can be an XMM register or a 64-bit memory location. The destination operand is a general-purpose register. When the source operand is an XMM register, the double-precision floating-point value is contained in the low quadword of the register.

When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register. If a converted result cannot be represented in the destination format, the floating-point invalid exception is raised, and if this exception is masked, the integer value 2\footnote{w}  - 1 is returned, where w represents the number of bits in the destination format.

EVEX.W1 version: promotes the instruction to produce 64-bit data in 64-bit mode.


### Operation
#### VCVTTSD2USI (EVEX encoded version)
```info-verb
IF 64-Bit Mode and OperandSize = 64
    THEN DEST[63:0] <-  Convert_Double_Precision_Floating_Point_To_UInteger_Truncate(SRC[63:0]);
    ELSE DEST[31:0] <-  Convert_Double_Precision_Floating_Point_To_UInteger_Truncate(SRC[63:0]);
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTTSD2USI unsigned int _mm_cvttsd_u32(__m128d);
VCVTTSD2USI unsigned int _mm_cvtt_roundsd_u32(__m128d, int sae);
VCVTTSD2USI unsigned __int64 _mm_cvttsd_u64(__m128d);
VCVTTSD2USI unsigned __int64 _mm_cvtt_roundsd_u64(__m128d, int sae);
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E3NF.

