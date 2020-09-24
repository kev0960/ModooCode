----------------------------
title : CVTPI2PS (Intel x86/64 assembly instruction)
cat_title : CVTPI2PS
ref_title : CVTPI2PS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTPI2PS

**Convert Packed Dword Integers to Packed Single-Precision FP Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|`0F 2A /r`\newline{}`CVTPI2PS` \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|Valid|Valid|Convert two signed doubleword integers from mm/m64 to two single-precision floating-point values in xmm.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts two packed signed doubleword integers in the source operand (second operand) to two packed single-precision floating-point values in the destination operand (first operand). 

The source operand can be an MMX technology register or a 64-bit memory location. The destination operand is an XMM register. The results are stored in the low quadword of the destination operand, and the high quadword remains unchanged. When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register. 

This instruction causes a transition from x87 FPU to MMX technology operation (that is, the x87 FPU top-of-stack pointer is set to 0 and the x87 FPU tag word is set to all 0s [valid]). If this instruction is executed while an x87 FPU floating-point exception is pending, the exception is handled before the `CVTPI2PS` instruction is executed.

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).


### Operation

```info-verb
DEST[31:0] <- Convert_Integer_To_Single_Precision_Floating_Point(SRC[31:0]);
DEST[63:32] <- Convert_Integer_To_Single_Precision_Floating_Point(SRC[63:32]);
(* High quadword of destination unchanged *)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
CVTPI2PS: __m128 _mm_cvtpi32_ps(__m128 a, __m64 b)
```
### SIMD Floating-Point Exceptions


Precision

### Other Exceptions


See Table 22-5, "Exception Conditions for Legacy SIMD/MMX Instructions with XMM and FP Exception," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B.

