----------------------------
title : CVTSD2SI (Intel x86/64 assembly instruction)
cat_title : CVTSD2SI
ref_title : CVTSD2SI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CVTSD2SI

**Convert Scalar Double-Precision Floating-Point Value to Doubleword Integer**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F 2D /r\newline{}CVTSD2SI r32, xmm1/m64|RM|V/V|SSE2|Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer r32.|
|F2 REX.W 0F 2D /r\newline{}CVTSD2SI r64, xmm1/m64|RM|V/N.E.|SSE2|Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer sign-extended into r64.|
|VEX.128.F2.0F.W0 2D /r\newline{}VCVTSD2SI r32, xmm1/m64|RM|V/V|AVX|Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer r32.|
|VEX.128.F2.0F.W1 2D /r\newline{}VCVTSD2SI r64, xmm1/m64|RM|V/N.E.\footnote{1}|AVX|Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer sign-extended into r64.|
|EVEX.LIG.F2.0F.W0 2D /r\newline{}VCVTSD2SI r32, xmm1/m64{er}|T1F|V/V|AVX512F|Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer r32.|
|EVEX.LIG.F2.0F.W1 2D /r\newline{}VCVTSD2SI r64, xmm1/m64{er}|T1F|V/N.E.\footnote{1}|AVX512F|Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer sign-extended into r64.|
||||||

```note
1. VEX.W1/EVEX.W1 in non-64 bit is ignored; the instructions behaves as if the W0 version is used
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1F|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Converts a double-precision floating-point value in the source operand (the second operand) to a signed double-word integer in the destination operand (first operand). The source operand can be an XMM register or a 64-bit memory location. The destination operand is a general-purpose register. When the source operand is an XMM register, the double-precision floating-point value is contained in the low quadword of the register.

When a conversion is inexact, the value returned is rounded according to the rounding control bits in the MXCSR register. 

If a converted result exceeds the range limits of signed doubleword integer (in non-64-bit modes or 64-bit mode with REX.W/VEX.W/EVEX.W=0), the floating-point invalid exception is raised, and if this exception is masked, the indefinite integer value (80000000H) is returned.

If a converted result exceeds the range limits of signed quadword integer (in 64-bit mode and REX.W/VEX.W/EVEX.W = 1), the floating-point invalid exception is raised, and if this exception is masked, the indefinite integer value (80000000\esc{_}00000000H) is returned.

Legacy SSE instruction: Use of the REX.W prefix promotes the instruction to produce 64-bit data in 64-bit mode. See the summary chart at the beginning of this section for encoding data and limits.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

Software should ensure VCVTSD2SI is encoded with VEX.L=0. Encoding VCVTSD2SI with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### VCVTSD2SI (EVEX encoded version)
```info-verb
IF SRC *is register* AND (EVEX.b = 1) 
    THEN
          SET_RM(EVEX.RC);
    ELSE 
          SET_RM(MXCSR.RM);
FI;
IF 64-Bit Mode and OperandSize = 64
    THEN DEST[63:0] <-  Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0]);
    ELSE DEST[31:0] <-  Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0]);
FI
```
#### (V)CVTSD2SI 
```info-verb
IF 64-Bit Mode and OperandSize = 64
THEN
    DEST[63:0] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0]);
ELSE
    DEST[31:0] <- Convert_Double_Precision_Floating_Point_To_Integer(SRC[63:0]);
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCVTSD2SI int _mm_cvtsd_i32(__m128d);
VCVTSD2SI int _mm_cvt_roundsd_i32(__m128d, int r);
VCVTSD2SI __int64 _mm_cvtsd_i64(__m128d);
VCVTSD2SI __int64 _mm_cvt_roundsd_i64(__m128d, int r);
CVTSD2SI __int64 _mm_cvtsd_si64(__m128d);
CVTSD2SI int _mm_cvtsd_si32(__m128d a)
```
### SIMD Floating-Point Exceptions


Invalid, Precision

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3; 

EVEX-encoded instructions, see Exceptions Type E3NF.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

