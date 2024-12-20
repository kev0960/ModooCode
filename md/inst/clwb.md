----------------------------
title : CLWB (Intel x86/64 assembly instruction)
cat_title : CLWB
ref_title : CLWB
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CLWB

**Cache Line Write Back**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|------------------------------------|---------------|
|`66 0F AE /6`\newline{}`CLWB` \tooltip{m8}{DS:(E)SI, ES:(E)DI 로 표현되는 1 바이트 짜리 메모리를 나타낸다. 주로 배열의 이름을 나타내는데 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다. } |M|V/V|CLWB|Writes back modified cache line containing m8, and may retain the line in cache hierarchy in non-modified state.|
###                                                       Instruction Operand Encoding\footnote{1}


Op/En Operand 1 Operand 2 Operand 3 Operand 4

  M ModRM:r/m (w) NA NA NA

### Description


Writes back to memory the cache line (if modified) that contains the linear address specified with the memory operand from any level of the cache hierarchy in the cache coherence domain. The line may be retained in the cache hierarchy in non-modified state. Retaining the line in the cache hierarchy is a performance optimization (treated as a hint by hardware) to reduce the possibility of cache miss on a subsequent access. Hardware may choose to retain the line at any of the levels in the cache hierarchy, and in some cases, may invalidate the line from the cache hierarchy. The source operand is a byte memory location. 

The availability of `CLWB` instruction is indicated by the presence of the `CPUID` feature flag `CLWB` (bit 24 of the EBX register, see "CPUID -- CPU Identification" in this chapter). The aligned cache line size affected is also indicated with the `CPUID` instruction (bits 8 through 15 of the EBX register when the initial value in the EAX register is 1).

The memory attribute of the page containing the affected line has no effect on the behavior of this instruction. It should be noted that processors are free to speculatively fetch and cache data from system memory regions that are assigned a memory-type allowing for speculative reads (such as, the WB, WC, and WT memory types). `PREFETCHh` instructions can be used to provide the processor with hints for this speculative behavior. Because this speculative fetching can occur at any time and is not tied to instruction execution, the `CLWB` instruction is not ordered with respect to `PREFETCHh` instructions or any of the speculative fetching mechanisms (that is, data can be speculatively loaded into a cache line just before, during, or after the execution of a `CLWB` instruction that refer-ences the cache line). 

CLWB instruction is ordered only by store-fencing operations. For example, software can use an `SFENCE`, `MFENCE`, `XCHG`, or LOCK-prefixed instructions to ensure that previous stores are included in the write-back. `CLWB` instruc-tion need not be ordered by another `CLWB` or `CLFLUSHOPT` instruction. `CLWB` is implicitly ordered with older stores executed by the logical processor to the same address.

For usages that require only writing back modified data from cache lines to memory (do not require the line to be invalidated), and expect to subsequently access the data, software is recommended to use `CLWB` (with appropriate fencing) instead of `CLFLUSH` or `CLFLUSHOPT` for improved performance.

The `CLWB` instruction can be used at all privilege levels and is subject to all permission checking and faults associ-ated with a byte load. Like a load, the `CLWB` instruction sets the accessed flag but not the dirty flag in the page tables.

In some implementations, the `CLWB` instruction may always cause transactional abort with Transactional Synchro-nization Extensions (TSX). `CLWB` instruction is not expected to be commonly used inside typical transactional regions. However, programmers must not rely on `CLWB` instruction to force a transactional abort, since whether they cause transactional abort is implementation dependent.


### Operation

```info-verb
Cache_Line_Write_Back(m8);
```
### Flags Affected


None.

```sidenote


1. ModRM.MOD != 011B
```### C/C++ Compiler Intrinsic Equivalent


CLWB void _mm_clwb(void const \htmlonly{*}p);


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.CLWB[bit 24] = 0.

#### #GP(0)
* For an illegal memory operand effective address in the CS, DS, ES, FS or GS segments.

#### #SS(0)
* For an illegal address in the SS segment. 

#### #PF(fault-code)
* For a page fault.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.CLWB[bit 24] = 0.

#### #GP
* If any part of the operand lies outside the effective address space from 0 to FFFFH.

### Virtual-8086 Mode Exceptions

#### #PF(fault-code)
* For a page fault.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.CLWB[bit 24] = 0.

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* For a page fault.
