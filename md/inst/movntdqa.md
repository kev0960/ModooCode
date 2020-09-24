----------------------------
title : MOVNTDQA (Intel x86/64 assembly instruction)
cat_title : MOVNTDQA
ref_title : MOVNTDQA
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVNTDQA

**Load Double Quadword Non-Temporal Aligned Hint**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|------------------------------------|---------------|
|`66 0F 38 2A /r`\newline{}`MOVNTDQA` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} |RM|V/V|SSE4_1|Move double quadword from m128 to xmm1 using non-temporal hint if WC memory type.|
|`VEX.128.66.0F38.WIG 2A /r`\newline{}VMOVNTDQA \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} |RM|V/V|AVX|Move double quadword from m128 to xmm using non-temporal hint if WC memory type.|
|`VEX.256.66.0F38.WIG 2A /r`\newline{}VMOVNTDQA \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} |RM|V/V|AVX2|Move 256-bit data from m256 to ymm using non-temporal hint if WC memory type.|
|`EVEX.128.66.0F38.W0 2A /r`\newline{}VMOVNTDQA \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m128}{메모리 상의 16 바이트 데이터를 표현한다.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move 128-bit data from m128 to xmm using non-temporal hint if WC memory type.|
|`EVEX.256.66.0F38.W0 2A /r`\newline{}VMOVNTDQA \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{m256}{32 바이트 메모리 데이터. 이는 AVX 명령어들에만 사용된다.} |FVM|V/V|AVX512VL\newline{}AVX512F|Move 256-bit data from m256 to ymm using non-temporal hint if WC memory type.|
|`EVEX.512.66.0F38.W0 2A /r`\newline{}VMOVNTDQA zmm1 \tooltip{m512}{64 바이트 메모리 데이터} |FVM|V/V|AVX512F|Move 512-bit data from m512 to zmm using non-temporal hint if WC memory type.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FVM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


MOVNTDQA loads a double quadword from the source operand (second operand) to the destination operand (first operand) using a non-temporal hint if the memory source is WC (write combining) memory type. For WC memory type, the nontemporal hint may be implemented by loading a temporary internal buffer with the equivalent of an aligned cache line without filling this data to the cache. Any memory-type aliased lines in the cache will be snooped and flushed. Subsequent `MOVNTDQA` reads to unread portions of the WC cache line will receive data from the temporary internal buffer if data is available. The temporary internal buffer may be flushed by the processor at any time for any reason, for example:

*  A load operation other than a `MOVNTDQA` which references memory already resident in a temporary internal buffer.

*  A non-WC reference to memory already resident in a temporary internal buffer.

*  Interleaving of reads and writes to a single temporary internal buffer.

*  Repeated (V)MOVNTDQA loads of a particular 16-byte item in a streaming line.

*  Certain micro-architectural conditions including resource shortages, detection of

a mis-speculation condition, and various fault conditions

The non-temporal hint is implemented by using a write combining (WC) memory type protocol when reading the data from memory. Using this protocol, the processor

does not read the data into the cache hierarchy, nor does it fetch the corresponding cache line from memory into the cache hierarchy. The memory type of the region being read can override the non-temporal hint, if the memory address specified for the non-temporal read is not a WC memory region. Information on non-temporal reads and writes can be found in "Caching of Temporal vs. Non-Temporal Data" in Chapter 10 in the Intel(R) 64 and IA-32 Architecture Software Developer's Manual, Volume 3A.

Because the WC protocol uses a weakly-ordered memory consistency model, a fencing operation implemented with a `MFENCE` instruction should be used in conjunction with `MOVNTDQA` instructions if multiple processors might use different memory types for the referenced memory locations or to synchronize reads of a processor with writes by other agents in the system. A processor's implementation of the streaming load hint does not override the effective memory type, but the implementation of the hint is processor dependent. For example, a processor implementa-

```sidenote


1. ModRM.MOD = 011B required
```

tion may choose to ignore the hint and process the instruction as a normal MOVDQA for any memory type. Alter-natively, another implementation may optimize cache reads generated by MOVNTDQA on WB memory type to reduce cache evictions.

The 128-bit (V)MOVNTDQA addresses must be 16-byte aligned or the instruction will cause a #GP.

The 256-bit VMOVNTDQA addresses must be 32-byte aligned or the instruction will cause a #GP.

The 512-bit VMOVNTDQA addresses must be 64-byte aligned or the instruction will cause a #GP.


### Operation
#### MOVNTDQA (128bit- Legacy SSE form)
```info-verb
DEST <- SRC
DEST[MAX_VL-1:128] (Unmodified)
```
#### VMOVNTDQA (VEX.128 and EVEX.128 encoded form)
```info-verb
DEST <-  SRC
DEST[MAX_VL-1:128] <-  0 
```
#### VMOVNTDQA (VEX.256 and EVEX.256 encoded forms)
```info-verb
DEST[255:0] <-  SRC[255:0]
DEST[MAX_VL-1:256] <-  0
```
#### VMOVNTDQA (EVEX.512 encoded form)
```info-verb
DEST[511:0] <-  SRC[511:0]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVNTDQA __m512i _mm512_stream_load_si512(void * p);
MOVNTDQA __m128i _mm_stream_load_si128 (__m128i *p);
VMOVNTDQA __m256i _mm_stream_load_si256 (__m256i *p);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type1; 

EVEX-encoded instruction, see Exceptions Type E1NF.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

