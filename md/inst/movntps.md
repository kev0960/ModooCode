----------------------------
title : MOVNTPS (Intel x86/64 assembly instruction)
cat_title : MOVNTPS
ref_title : MOVNTPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVNTPS

**Store Packed Single-Precision Floating-Point Values Using Non-Temporal Hint**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 2B /r`\newline{}`MOVNTPS` \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|SSE|Move packed single-precision values xmm1 to mem using non-temporal hint.|
|`VEX.128.0F.WIG 2B /r`\newline{}VMOVNTPS \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move packed single-precision values xmm1 to mem using non-temporal hint.|
|`VEX.256.0F.WIG 2B /r`\newline{}VMOVNTPS \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move packed single-precision values ymm1 to mem using non-temporal hint.|
|`EVEX.128.0F.W0 2B /r`\newline{}VMOVNTPS \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move packed single-precision values in xmm1 to m128 using non-temporal hint.|
|`EVEX.256.0F.W0 2B /r`\newline{}VMOVNTPS \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move packed single-precision values in ymm1 to m256 using non-temporal hint.|
|`EVEX.512.0F.W0 2B /r`\newline{}VMOVNTPS \tooltip{m512}{64 바이트 메모리 데이터} zmm1 |FVM|V/V|AVX512F|Move packed single-precision values in zmm1 to m512 using non-temporal hint.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|FVM|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Moves the packed single-precision floating-point values in the source operand (second operand) to the destination operand (first operand) using a non-temporal hint to prevent caching of the data during the write to memory. The source operand is an XMM register, YMM register or ZMM register, which is assumed to contain packed single-preci-sion, floating-pointing. The destination operand is a 128-bit, 256-bit or 512-bit memory location. The memory operand must be aligned on a 16-byte (128-bit version), 32-byte (VEX.256 encoded version) or 64-byte (EVEX.512 encoded version) boundary otherwise a general-protection exception (#GP) will be generated. 

The non-temporal hint is implemented by using a write combining (WC) memory type protocol when writing the data to memory. Using this protocol, the processor does not write the data into the cache hierarchy, nor does it fetch the corresponding cache line from memory into the cache hierarchy. The memory type of the region being written to can override the non-temporal hint, if the memory address specified for the non-temporal store is in an uncacheable (UC) or write protected (WP) memory region. For more information on non-temporal stores, see "Caching of Temporal vs. Non-Temporal Data" in Chapter 10 in the IA-32 Intel Architecture Software Developer's Manual, Volume 1.

Because the WC protocol uses a weakly-ordered memory consistency model, a fencing operation implemented with the `SFENCE` or `MFENCE` instruction should be used in conjunction with `MOVNTPS` instructions if multiple processors might use different memory types to read/write the destination memory locations.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VMOVNTPS (EVEX encoded versions) 
```info-verb
VL = 128, 256, 512
DEST[VL-1:0] <-  SRC[VL-1:0]
DEST[MAX_VL-1:VL] <-  0
```
```sidenote


1. ModRM.MOD = 011B required
```

**MOVNTPS**

DEST <-  SRC


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVNTPS void _mm512_stream_ps(float * p, __m512d a);
MOVNTPS void _mm_stream_ps (float * p, __m128d a);
VMOVNTPS void _mm256_stream_ps (float * p, __m256 a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type1.SSE; additionally

EVEX-encoded instruction, see Exceptions Type E1NF.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

