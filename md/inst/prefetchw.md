----------------------------
title : PREFETCHW (Intel x86/64 assembly instruction)
cat_title : PREFETCHW
ref_title : PREFETCHW
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PREFETCHW

**Prefetch Data into Caches in Anticipation of a Write**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 0D /1`\newline{}`PREFETCHW` \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |A|V/V|PRFCHW|Move data from m8 closer to the processor in anticipation of a write.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Fetches the cache line of data from memory that contains the byte specified with the source operand to a location in the 1st or 2nd level cache and invalidates other cached instances of the line.

The source operand is a byte memory location. If the line selected is already present in the lowest level cache and is already in an exclusively owned state, no data movement occurs. Prefetches from non-writeback memory are ignored.

The `PREFETCHW` instruction is merely a hint and does not affect program behavior. If executed, this instruction moves data closer to the processor and invalidates other cached copies in anticipation of the line being written to in the future.

The characteristic of prefetch locality hints is implementation-dependent, and can be overloaded or ignored by a processor implementation. The amount of data prefetched is also processor implementation-dependent. It will, however, be a minimum of 32 bytes. Additional details of the implementation-dependent locality hints are described in Section 7.4 of Intel(R) 64 and IA-32 Architectures Optimization Reference Manual.

It should be noted that processors are free to speculatively fetch and cache data with exclusive ownership from system memory regions that permit such accesses (that is, the WB memory type). A `PREFETCHW` instruction is considered a hint to this speculative behavior. Because this speculative fetching can occur at any time and is not tied to instruction execution, a `PREFETCHW` instruction is not ordered with respect to the fence instructions (MFENCE, `SFENCE`, and LFENCE) or locked memory references. A `PREFETCHW` instruction is also unordered with respect to `CLFLUSH` and `CLFLUSHOPT` instructions, other `PREFETCHW` instructions, or any other general instruction

It is ordered with respect to serializing instructions such as `CPUID`, `WRMSR`, `OUT`, and `MOV` CR.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
FETCH_WITH_EXCLUSIVE_OWNERSHIP (m8);
```
### Flags Affected


All flags are affected

### C/C++ Compiler Intrinsic Equivalent


void _m_prefetchw( void \htmlonly{*} );


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used.
