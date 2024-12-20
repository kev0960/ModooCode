----------------------------
title : MOVNTQ (Intel x86/64 assembly instruction)
cat_title : MOVNTQ
ref_title : MOVNTQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVNTQ

**Store of Quadword Using Non-Temporal Hint**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F E7 /r|`MOVNTQ` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} \tooltip{mm}{64 비트 MMX 레지스터로 MM0 부터 MM7 까지 가능하다. } |MR|Valid|Valid|Move quadword from mm to m64 using non-temporal hint.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Moves the quadword in the source operand (second operand) to the destination operand (first operand) using a non-temporal hint to minimize cache pollution during the write to memory. The source operand is an MMX tech-nology register, which is assumed to contain packed integer data (packed bytes, words, or doublewords). The destination operand is a 64-bit memory location.

The non-temporal hint is implemented by using a write combining (WC) memory type protocol when writing the data to memory. Using this protocol, the processor does not write the data into the cache hierarchy, nor does it fetch the corresponding cache line from memory into the cache hierarchy. The memory type of the region being written to can override the non-temporal hint, if the memory address specified for the non-temporal store is in an uncacheable (UC) or write protected (WP) memory region. For more information on non-temporal stores, see "Caching of Temporal vs. Non-Temporal Data" in Chapter 10 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1.

Because the WC protocol uses a weakly-ordered memory consistency model, a fencing operation implemented with the `SFENCE` or `MFENCE` instruction should be used in conjunction with `MOVNTQ` instructions if multiple processors might use different memory types to read/write the destination memory locations.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
DEST <- SRC;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVNTQ: void _mm_stream_pi(__m64 * p, __m64 a)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Table 22-8, "Exception Conditions for Legacy SIMD/MMX Instructions without FP Exception," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

