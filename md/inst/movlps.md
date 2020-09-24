----------------------------
title : MOVLPS (Intel x86/64 assembly instruction)
cat_title : MOVLPS
ref_title : MOVLPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVLPS

**Move Low Packed Single-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 12 /r`\newline{}`MOVLPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} |RM|V/V|SSE|Move two packed single-precision floating-point values from m64 to low quadword of xmm1.|
|`VEX.NDS.128.0F.WIG 12 /r`\newline{}VMOVLPS \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} |RVM|V/V|AVX|Merge two packed single-precision floating-point values from m64 and the high quadword of xmm1.|
|`EVEX.NDS.128.0F.W0 12 /r`\newline{}VMOVLPS \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} |T2|V/V|AVX512F|Merge two packed single-precision floating-point values from m64 and the high quadword of xmm1.|
|`0F 13/r`\newline{}`MOVLPS` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|SSE|Move two packed single-precision floating-point values from low quadword of xmm1 to m64.|
|`VEX.128.0F.WIG 13/r`\newline{}VMOVLPS \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move two packed single-precision floating-point values from low quadword of xmm1 to m64.|
|`EVEX.128.0F.W0 13/r`\newline{}VMOVLPS \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T2-MR|V/V|AVX512F|Move two packed single-precision floating-point values from low quadword of xmm1 to m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|T2|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|NA|
|T2-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


This instruction cannot be used for register to register or memory to memory moves.

128-bit Legacy SSE load:

Moves two packed single-precision floating-point values from the source 64-bit memory operand and stores them in the low 64-bits of the destination XMM register. The upper 64bits of the XMM register are preserved. Bits (MAX\esc{_}VL-1:128) of the corresponding destination register are preserved.

VEX.128 & EVEX encoded load:

Loads two packed single-precision floating-point values from the source 64-bit memory operand (the third operand), merges them with the upper 64-bits of the first source operand (the second operand), and stores them in the low 128-bits of the destination register (the first operand). Bits (MAX\esc{_}VL-1:128) of the corresponding desti-nation register are zeroed.

128-bit store:

Loads two packed single-precision floating-point values from the low 64-bits of the XMM register source (second operand) to the 64-bit memory location (first operand).

Note: VMOVLPS (store) (VEX.128.0F 13 /r) is legal and has the same behavior as the existing 0F 13 store. For VMOVLPS (store) VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instruction will #UD.

If VMOVLPS is encoded with VEX.L or EVEX.L'L= 1, an attempt to execute the instruction encoded with VEX.L or EVEX.L'L= 1 will cause an #UD exception.


### Operation
#### MOVLPS (128-bit Legacy SSE load)
```info-verb
DEST[63:0] <-  SRC[63:0]
DEST[MAX_VL-1:64] (Unmodified)
```
#### VMOVLPS (VEX.128 & EVEX encoded load)
```info-verb
DEST[63:0] <-  SRC2[63:0]
DEST[127:64] <-  SRC1[127:64]
DEST[MAX_VL-1:128] <-  0
```
#### VMOVLPS (store)
```info-verb
DEST[63:0] <-  SRC[63:0]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVLPS __m128 _mm_loadl_pi ( __m128 a, __m64 *p)
MOVLPS void _mm_storel_pi (__m64 *p, __m128 a)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5; additionally

#UD If VEX.L = 1.

EVEX-encoded instruction, see Exceptions Type E9NF.

