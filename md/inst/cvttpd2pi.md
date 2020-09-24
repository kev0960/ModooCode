----------------------------
title : CVTTPD2PI (Intel x86/64 assembly instruction)
cat_title : CVTTPD2PI
ref_title : CVTTPD2PI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTTPD2PI

**Convert with Truncation Packed Double-Precision FP Values to Packed Dword Integers**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|`66 0F 2C /r`\newline{}`CVTTPD2PI` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{xmm/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|Valid|Valid|Convert two packer double-precision floating-point values from xmm/m128 to two packed signed doubleword integers in mm using truncation.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two packed double-precision floating-point values in the source operand (second operand) to two packed signed doubleword integers in the destination operand (first operand). The source operand can be an XMM register or a 128-bit memory location. The destination operand is an MMX technology register. 

When a conversion is inexact, a truncated (round toward zero) result is returned. If a converted result is larger than the maximum signed doubleword integer, the floating-point invalid exception is raised, and if this exception is masked, the indefinite integer value (80000000H) is returned.

This instruction causes a transition from x87 FPU to MMX technology operation (that is, the x87 FPU top-of-stack pointer is set to 0 and the x87 FPU tag word is set to all 0s [valid]). If this instruction is executed while an x87 FPU floating-point exception is pending, the exception is handled before the `CVTTPD2PI` instruction is executed.

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).


### Operation

```info-verb
DEST[31:0] <- Convert_Double_Precision_Floating_Point_To_Integer32_Truncate(SRC[63:0]);
DEST[63:32] <- Convert_Double_Precision_Floating_Point_To_Integer32_
                      Truncate(SRC[127:64]);
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
CVTTPD1PI:  __m64 _mm_cvttpd_pi32(__m128d a)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Mode Exceptions


See Table 22-4, "Exception Conditions for Legacy SIMD/MMX Instructions with FP Exception and 16-Byte Align-ment," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B.

