----------------------------
title : MOVQ (Intel x86/64 assembly instruction)
cat_title : MOVQ
ref_title : MOVQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVQ

**Move Quadword**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|----------|--------------------------------|--------------------------------------------------|---------------|
|`0F 6F /r`\newline{}`MOVQ` \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|MMX|Move quadword from mm/m64 to mm.|
|`0F 7F /r`\newline{}`MOVQ` \tooltip{mm/m64}{MMX 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } |MR|V/V|MMX|Move quadword from mm to mm/m64.|
|`F3 0F 7E /r`\newline{}`MOVQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|SSE2|Move quadword from xmm2/mem64 to xmm1.|
|`VEX.128.F3.0F.WIG 7E /r`\newline{}VMOVQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} |RM|V/V|AVX|Move quadword from xmm2 to xmm1.|
|`EVEX.128.F3.0F.W1 7E /r`\newline{}VMOVQ \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} |T1S-RM|V/V|AVX512F|Move quadword from xmm2/m64 to xmm1.|
|`66 0F D6 /r`\newline{}`MOVQ` \tooltip{xmm2/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|SSE2|Move quadword from xmm1 to xmm2/mem64.|
|`VEX.128.66.0F.WIG D6 /r`\newline{}VMOVQ \tooltip{xmm1/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move quadword from xmm2 register to xmm1/m64.|
|`EVEX.128.66.0F.W1 D6 /r`\newline{}VMOVQ \tooltip{xmm1/m64}{128 비트 XMM 레지스터 혹은 64 비트 메모리 데이터.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S-MR|V/V|AVX512F|Move quadword from xmm2 register to xmm1/m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|T1S-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1S-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Copies a quadword from the source operand (second operand) to the destination operand (first operand). The source and destination operands can be MMX technology registers, XMM registers, or 64-bit memory locations. This instruction can be used to move a quadword between two MMX technology registers or between an MMX tech-nology register and a 64-bit memory location, or to move data between two XMM registers or between an XMM register and a 64-bit memory location. The instruction cannot be used to transfer data between memory locations. 

When the source operand is an XMM register, the low quadword is moved; when the destination operand is an XMM register, the quadword is stored to the low quadword of the register, and the high quadword is cleared to all 0s.

In 64-bit mode and if not encoded using VEX/EVEX, use of the REX prefix in the form of REX.R permits this instruc-tion to access additional registers (XMM8-XMM15).

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

If VMOVQ is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.


### Operation
#### VMOVQ (7E - EVEX encoded version) with XMM register source and destination:
```info-verb
DEST[63:0] <-  SRC[63:0]
DEST[MAX_VL-1:64] <-  0
```
#### VMOVQ (D6 - EVEX encoded version) with XMM register source and destination:
```info-verb
DEST[63:0] <-  SRC[63:0]
DEST[MAX_VL-1:64] <-  0
VMOVQ (7E) with memory source:
DEST[63:0] <- SRC[63:0]
DEST[VLMAX-1:64] <- 0
```
#### VMOVQ (7E - EVEX encoded version) with memory source:
```info-verb
DEST[63:0] <-  SRC[63:0]
DEST[:MAX_VL-1:64] <-  0
VMOVQ (D6) with memory dest:
DEST[63:0] <- SRC2[63:0]
```
### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVQ __m128i _mm_loadu_si64( void * s);
VMOVQ void _mm_storeu_si64( void * d, __m128i s);
MOVQ m128i _mm_mov_epi64(__m128i a)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Table 22-8, "Exception Conditions for Legacy SIMD/MMX Instructions without FP Exception," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B.

