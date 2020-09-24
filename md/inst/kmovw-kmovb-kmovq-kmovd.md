----------------------------
title : KMOVW, KMOVB, KMOVQ, KMOVDs (Intel x86/64 assembly instruction)
cat_title : KMOVW, KMOVB, KMOVQ, KMOVD
ref_title : KMOVW, KMOVB, KMOVQ, KMOVD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KMOVW, KMOVB, KMOVQ, KMOVD

**Move from and to Mask Registers **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.L0.0F.W0 90 /r`\newline{}`KMOVW` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2/m16 |RM|V/V|AVX512F|Move 16 bits mask from k2/m16 and store the result in k1.|
|`VEX.L0.66.0F.W0 90 /r `\newline{}`KMOVB` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2/m8 |RM|V/V|AVX512DQ|Move 8 bits mask from k2/m8 and store the result in k1. |
|`VEX.L0.0F.W1 90 /r `\newline{}`KMOVQ` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2/m64 |RM|V/V|AVX512BW|Move 64 bits mask from k2/m64 and store the result in k1.|
|`VEX.L0.66.0F.W1 90 /r `\newline{}`KMOVD` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2/m32 |RM|V/V|AVX512BW|Move 32 bits mask from k2/m32 and store the result in k1. |
|`VEX.L0.0F.W0 91 /r `\newline{}`KMOVW` \tooltip{m16}{DS:(E)SI, ES:(E)DI 로 표현되는 2 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |MR|V/V|AVX512F|Move 16 bits mask from k1 and store the result in m16.|
|`VEX.L0.66.0F.W0 91 /r `\newline{}`KMOVB` \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |MR|V/V|AVX512DQ|Move 8 bits mask from k1 and store the result in m8. |
|`VEX.L0.0F.W1 91 /r `\newline{}`KMOVQ` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |MR|V/V|AVX512BW|Move 64 bits mask from k1 and store the result in m64.|
|`VEX.L0.66.0F.W1 91 /r `\newline{}`KMOVD` \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |MR|V/V|AVX512BW|Move 32 bits mask from k1 and store the result in m32.|
|`VEX.L0.0F.W0 92 /r `\newline{}`KMOVW` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |RR|V/V|AVX512F|Move 16 bits mask from r32 to k1.|
|`VEX.L0.66.0F.W0 92 /r `\newline{}`KMOVB` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |RR|V/V|AVX512DQ|Move 8 bits mask from r32 to k1.|
|`VEX.L0.F2.0F.W1 92 /r `\newline{}`KMOVQ` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |RR|V/I|AVX512BW|Move 64 bits mask from r64 to k1.|
|`VEX.L0.F2.0F.W0 92 /r `\newline{}`KMOVD` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |RR|V/V|AVX512BW|Move 32 bits mask from r32 to k1.|
|`VEX.L0.0F.W0 93 /r `\newline{}`KMOVW` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RR|V/V|AVX512F|Move 16 bits mask from k1 to r32.|
|`VEX.L0.66.0F.W0 93 /r `\newline{}`KMOVB` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RR|V/V|AVX512DQ|Move 8 bits mask from k1 to r32.|
|`VEX.L0.F2.0F.W1 93 /r `\newline{}`KMOVQ` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RR|V/I|AVX512BW|Move 64 bits mask from k1 to r64.|
|`VEX.L0.F2.0F.W0 93 /r `\newline{}`KMOVD` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RR|V/V|AVX512BW|Move 32 bits mask from k1 to r32.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|
|-----|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|
|MR|ModRM:r/m (w, ModRM:[7:6] must not be 11b)|ModRM:reg (r)|
|RR|ModRM:reg (w)|ModRM:r/m (r, ModRM:[7:6] must be 11b) |
### Description


Copies values from the source operand (second operand) to the destination operand (first operand). The source and destination operands can be mask registers, memory location or general purpose. The instruction cannot be used to transfer data between general purpose registers and or memory locations.

When moving to a mask register, the result is zero extended to MAX\esc{_}KL size (i.e., 64 bits currently). When moving to a general-purpose register (GPR), the result is zero-extended to the size of the destination. In 32-bit mode, the default GPR destination's size is 32 bits. In 64-bit mode, the default GPR destination's size is 64 bits. Note that REX.W cannot be used to modify the size of the general-purpose destination.


### Operation
#### KMOVW
```info-verb
IF *destination is a memory location*
    DEST[15:0] <-  SRC[15:0]
IF *destination is a mask register or a GPR *
    DEST <-  ZeroExtension(SRC[15:0])
```
#### KMOVB
```info-verb
IF *destination is a memory location*
    DEST[7:0] <-  SRC[7:0]
IF *destination is a mask register or a GPR *
    DEST <-  ZeroExtension(SRC[7:0])
```
#### KMOVQ
```info-verb
IF *destination is a memory location or a GPR*
    DEST[63:0] <-  SRC[63:0]
IF *destination is a mask register*
    DEST <-  ZeroExtension(SRC[63:0])
```
#### KMOVD
```info-verb
IF *destination is a memory location*
    DEST[31:0] <-  SRC[31:0]
IF *destination is a mask register or a GPR *
    DEST <-  ZeroExtension(SRC[31:0])
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KMOVW __mmask16 _mm512_kmov(__mmask16 a);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


Instructions with RR operand encoding See Exceptions Type K20.

Instructions with RM or MR operand encoding See Exceptions Type K21.

