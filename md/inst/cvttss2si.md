----------------------------
title : CVTTSS2SI (Intel x86/64 assembly instruction)
cat_title : CVTTSS2SI
ref_title : CVTTSS2SI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTTSS2SI

**Convert with Truncation Scalar Single-Precision Floating-Point Value to Integer**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 2C /r`\newline{}`CVTTSS2SI` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/V|SSE|Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32 using truncation.|
|`F3 REX.W 0F 2C /r`\newline{}`CVTTSS2SI` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/N.E.|SSE|Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64 using truncation.|
|`VEX.128.F3.0F.W0 2C /r`\newline{}VCVTTSS2SI \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/V|AVX|Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32 using truncation.|
|`VEX.128.F3.0F.W1 2C /r`\newline{}VCVTTSS2SI \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{xmm1/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/N.E.\footnote{1}|AVX|Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64 using truncation.|
|`EVEX.LIG.F3.0F.W0 2C /r`\newline{}VCVTTSS2SI \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} xmm1/m32{sae} |T1F|V/V|AVX512F|Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32 using truncation.|
|`EVEX.LIG.F3.0F.W1 2C /r`\newline{}VCVTTSS2SI \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} xmm1/m32{sae} |T1F|V/N.E.\footnote{1}|AVX512F|Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64 using truncation.|
|``\newline{} |||||

```note
1. For this specific instruction, VEX.W/EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 ver-sion is used
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1F|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts a single-precision floating-point value in the source operand (the second operand) to a signed doubleword integer (or signed quadword integer if operand size is 64 bits) in the destination operand (the first operand). The source operand can be an XMM register or a 32-bit memory location. The destination operand is a general purpose register. When the source operand is an XMM register, the single-precision floating-point value is contained in the low doubleword of the register. 

When a conversion is inexact, a truncated (round toward zero) result is returned. If a converted result is larger than the maximum signed doubleword integer, the floating-point invalid exception is raised. If this exception is masked, the indefinite integer value (80000000H or 80000000\esc{_}00000000H if operand size is 64 bits) is returned.

Legacy SSE instructions: In 64-bit mode, Use of the REX.W prefix promotes the instruction to 64-bit operation. See the summary chart at the beginning of this section for encoding data and limits.

VEX.W1 and EVEX.W1 versions: promotes the instruction to produce 64-bit data in 64-bit mode.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

Software should ensure VCVTTSS2SI is encoded with VEX.L=0. Encoding VCVTTSS2SI with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### (V)CVTTSS2SI (All versions)
```info-verb
IF 64-Bit Mode and OperandSize = 64
THEN
    DEST[63:0] <-  Convert_Single_Precision_Floating_Point_To_Integer_Truncate(SRC[31:0]);
ELSE
    DEST[31:0] <-  Convert_Single_Precision_Floating_Point_To_Integer_Truncate(SRC[31:0]);
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTTSS2SI int _mm_cvttss_i32( __m128 a);
VCVTTSS2SI int _mm_cvtt_roundss_i32( __m128 a, int sae);
VCVTTSS2SI __int64 _mm_cvttss_i64( __m128 a);
VCVTTSS2SI __int64 _mm_cvtt_roundss_i64( __m128 a, int sae);
CVTTSS2SI int _mm_cvttss_si32( __m128 a);
CVTTSS2SI __int64 _mm_cvttss_si64( __m128 a);
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


See Exceptions Type 3; additionally

#UD  If VEX.vvvv != 1111B.

EVEX-encoded instructions, see Exceptions Type E3NF.

