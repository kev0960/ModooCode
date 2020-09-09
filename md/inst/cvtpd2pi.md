----------------------------
title : CVTPD2PI (Intel x86/64 assembly instruction)
cat_title : CVTPD2PI
ref_title : CVTPD2PI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTPD2PI

**Convert Packed Double-Precision FP Values to Packed Dword Integers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|66 0F 2D /r\newline{}\newline{}CVTPD2PI mm, xmm/m128|RM|Valid|Valid|Convert two packed double-precision floating-point values from xmm/m128 to two packed signed doubleword integers in mm.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two packed double-precision floating-point values in the source operand (second operand) to two packed signed doubleword integers in the destination operand (first operand).

The source operand can be an XMM register or a 128-bit memory location. The destination operand is an MMX tech-nology register. 

When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register. If a converted result is larger than the maximum signed doubleword integer, the floating-point invalid exception is raised, and if this exception is masked, the indefinite integer value (80000000H) is returned.

This instruction causes a transition from x87 FPU to MMX technology operation (that is, the x87 FPU top-of-stack pointer is set to 0 and the x87 FPU tag word is set to all 0s [valid]). If this instruction is executed while an x87 FPU floating-point exception is pending, the exception is handled before the `CVTPD2PI` instruction is executed.

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).


### Operation

```info-verb
DEST[31:0] <- Convert_Double_Precision_Floating_Point_To_Integer32(SRC[63:0]);
DEST[63:32] <- Convert_Double_Precision_Floating_Point_To_Integer32(SRC[127:64]);
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
CVTPD1PI: __m64 _mm_cvtpd_pi32(__m128d a)
```
### SIMD Floating-Point Exceptions


Invalid, Precision.

### Other Exceptions


See Table 22-4, "Exception Conditions for Legacy SIMD/MMX Instructions with FP Exception and 16-Byte Align-ment," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B.

