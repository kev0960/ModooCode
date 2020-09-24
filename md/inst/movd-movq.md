----------------------------
title : MOVD, MOVQs (Intel x86/64 assembly instruction)
cat_title : MOVD, MOVQ
ref_title : MOVD, MOVQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVD, MOVQ

**Move Doubleword/Move Quadword**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|----------|--------------------------------|--------------------------------------------------|---------------|
|`0F 6E /r`\newline{}`MOVD` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|V/V|MMX|Move doubleword from r/m32 to mm.|
|`REX.W + 0F 6E /r`\newline{}`MOVQ` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|V/N.E.|MMX|Move quadword from r/m64 to mm.|
|`0F 7E /r`\newline{}`MOVD` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } |MR|V/V|MMX|Move doubleword from mm to r/m32.|
|`REX.W + 0F 7E /r`\newline{}`MOVQ` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } |MR|V/N.E.|MMX|Move quadword from mm to r/m64.|
|`66 0F 6E /r`\newline{}`MOVD` \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|V/V|SSE2|Move doubleword from r/m32 to xmm.|
|`66 REX.W 0F 6E /r`\newline{}`MOVQ` \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|V/N.E.|SSE2|Move quadword from r/m64 to xmm.|
|`66 0F 7E /r`\newline{}`MOVD` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|SSE2|Move doubleword from xmm register to r/m32.|
|` 66 REX.W 0F 7E /r`\newline{}`MOVQ` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/N.E.|SSE2|Move quadword from xmm register to r/m64.|
|`VEX.128.66.0F.W0 6E /`\newline{}VMOVD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r32/m32 |RM|V/V|AVX|Move doubleword from r/m32 to xmm1.|
|`VEX.128.66.0F.W1 6E /r`\newline{}VMOVQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r64/m64 |RM|V/N.E\footnote{1} .|AVX|Move quadword from r/m64 to xmm1.|
|`VEX.128.66.0F.W0 7E /r`\newline{}VMOVD r32/m32 \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move doubleword from xmm1 register to r/m32.|
|`VEX.128.66.0F.W1 7E /r`\newline{}VMOVQ r64/m64 \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/N.E\footnote{1} .|AVX|Move quadword from xmm1 register to r/m64.|
|`EVEX.128.66.0F.W0 6E /r`\newline{}VMOVD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r32/m32 |T1S-RM|V/V|AVX512F|Move doubleword from r/m32 to xmm1.|
|`EVEX.128.66.0F.W1 6E /r`\newline{}VMOVQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} r64/m64 |T1S-RM|V/N.E.\footnote{1}|AVX512F|Move quadword from r/m64 to xmm1.|
|`EVEX.128.66.0F.W0 7E /r`\newline{}VMOVD r32/m32 \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S-MR|V/V|AVX512F|Move doubleword from xmm1 register to r/m32.|
|`EVEX.128.66.0F.W1 7E /r`\newline{}VMOVQ r64/m64 \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S-MR|V/N.E.\footnote{1}|AVX512F|Move quadword from xmm1 register to r/m64.|
|``\newline{} |||||

```note
1. For this specific instruction, VEX.W/EVEX.W in non-64 bit is ignored; the instructions behaves as if the W0 ver-sion is used
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|T1S-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1S-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Copies a doubleword from the source operand (second operand) to the destination operand (first operand). The source and destination operands can be general-purpose registers, MMX technology registers, XMM registers, or 32-bit memory locations. This instruction can be used to move a doubleword to and from the low doubleword of an MMX technology register and a general-purpose register or a 32-bit memory location, or to and from the low doubleword of an XMM register and a general-purpose register or a 32-bit memory location. The instruction cannot be used to transfer data between MMX technology registers, between XMM registers, between general-purpose registers, or between memory locations.

When the destination operand is an MMX technology register, the source operand is written to the low doubleword of the register, and the register is zero-extended to 64 bits. When the destination operand is an XMM register, the source operand is written to the low doubleword of the register, and the register is zero-extended to 128 bits.

In 64-bit mode, the instruction's default operation size is 32 bits. Use of the REX.R prefix permits access to addi-tional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.

MOVD/Q with XMM destination:

Moves a dword/qword integer from the source operand and stores it in the low 32/64-bits of the destination XMM register. The upper bits of the destination are zeroed. The source operand can be a 32/64-bit register or 32/64-bit memory location. 

128-bit Legacy SSE version: Bits (MAX\esc{_}VL-1:128) of the corresponding YMM destination register remain unchanged. Qword operation requires the use of REX.W=1.

VEX.128 encoded version: Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed. Qword operation requires the use of VEX.W=1.

EVEX.128 encoded version: Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed. Qword operation requires the use of EVEX.W=1.

MOVD/Q with 32/64 reg/mem destination:

Stores the low dword/qword of the source XMM register to 32/64-bit memory location or general-purpose register. Qword operation requires the use of REX.W=1, VEX.W=1, or EVEX.W=1.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

If VMOVD or VMOVQ is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.


### Operation
#### MOVD (when destination operand is MMX technology register)
```info-verb
    DEST[31:0] <- SRC;
    DEST[63:32] <- 00000000H;
```
#### MOVD (when destination operand is XMM register)
```info-verb
    DEST[31:0] <- SRC;
    DEST[127:32] <- 000000000000000000000000H;
    DEST[VLMAX-1:128] (Unmodified)
```
#### MOVD (when source operand is MMX technology or XMM register)
```info-verb
    DEST <- SRC[31:0];
```
#### VMOVD (VEX-encoded version when destination is an XMM register)
```info-verb
    DEST[31:0] <-  SRC[31:0]
    DEST[VLMAX-1:32] <-  0
```
#### MOVQ (when destination operand is XMM register)
```info-verb
    DEST[63:0] <- SRC[63:0];
    DEST[127:64] <- 0000000000000000H;
    DEST[VLMAX-1:128] (Unmodified)
```
#### MOVQ (when destination operand is r/m64)
```info-verb
    DEST[63:0] <- SRC[63:0];
```
#### MOVQ (when source operand is XMM register or r/m64)
```info-verb
    DEST <- SRC[63:0];
```
#### VMOVQ (VEX-encoded version when destination is an XMM register)
```info-verb
    DEST[63:0] <-  SRC[63:0]
    DEST[VLMAX-1:64] <-  0
```
#### VMOVD (EVEX-encoded version when destination is an XMM register)
```info-verb
DEST[31:0] <-  SRC[31:0]
DEST[511:32] <-  0H
```
#### VMOVQ (EVEX-encoded version when destination is an XMM register)
```info-verb
DEST[63:0] <-  SRC[63:0]
DEST[511:64] <-  0H
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVD: __m64 _mm_cvtsi32_si64 (int i )
MOVD: int _mm_cvtsi64_si32 ( __m64m ) 
MOVD: __m128i _mm_cvtsi32_si128 (int a) 
MOVD: int _mm_cvtsi128_si32 ( __m128i a)
MOVQ: __int64 _mm_cvtsi128_si64(__m128i); 
MOVQ: __m128i _mm_cvtsi64_si128(__int64);
VMOVD  __m128i _mm_cvtsi32_si128( int);
VMOVD  int _mm_cvtsi128_si32( __m128i );
VMOVQ  __m128i _mm_cvtsi64_si128 (__int64);
VMOVQ  __int64 _mm_cvtsi128_si64(__m128i );
VMOVQ  __m128i _mm_loadl_epi64( __m128i * s);
VMOVQ  void _mm_storel_epi64( __m128i * d, __m128i s);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5.

EVEX-encoded instruction, see Exceptions Type E9NF.

#UD  If VEX.L = 1.

                              If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

