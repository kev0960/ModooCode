----------------------------
title : CVTPS2PI (Intel x86/64 assembly instruction)
cat_title : CVTPS2PI
ref_title : CVTPS2PI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTPS2PI

**Convert Packed Single-Precision FP Values to Packed Dword Integers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|`0F 2D /r`\newline{}`CVTPS2PI` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{xmm/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} |RM|Valid|Valid|Convert two packed single-precision floating-point values from xmm/m64 to two packed signed doubleword integers in mm.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two packed single-precision floating-point values in the source operand (second operand) to two packed signed doubleword integers in the destination operand (first operand).

The source operand can be an XMM register or a 128-bit memory location. The destination operand is an MMX tech-nology register. When the source operand is an XMM register, the two single-precision floating-point values are contained in the low quadword of the register. When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register. If a converted result is larger than the maximum signed doubleword integer, the floating-point invalid exception is raised, and if this exception is masked, the indef-inite integer value (80000000H) is returned.

CVTPS2PI causes a transition from x87 FPU to MMX technology operation (that is, the x87 FPU top-of-stack pointer is set to 0 and the x87 FPU tag word is set to all 0s [valid]). If this instruction is executed while an x87 FPU floating-point exception is pending, the exception is handled before the `CVTPS2PI` instruction is executed.

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).


### Operation

```info-verb
DEST[31:0] <- Convert_Single_Precision_Floating_Point_To_Integer(SRC[31:0]);
DEST[63:32] <- Convert_Single_Precision_Floating_Point_To_Integer(SRC[63:32]);
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
CVTPS2PI: __m64 _mm_cvtps_pi32(__m128 a)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


See Table 22-5, "Exception Conditions for Legacy SIMD/MMX Instructions with XMM and FP Exception," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B.

