----------------------------
title : MOVNTI (Intel x86/64 assembly instruction)
cat_title : MOVNTI
ref_title : MOVNTI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVNTI

**Store Doubleword Using Non-Temporal Hint**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F C3 /r|`MOVNTI` \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |MR|Valid|Valid|Move doubleword from r32 to m32 using non-temporal hint.|
|REX.W + 0F C3 /r|`MOVNTI` \tooltip{m64}{메모리 상의 8 바이트 데이터를 표현한다.} \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |MR|Valid |N.E.|Move quadword from r64 to m64 using non-temporal hint.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Moves the doubleword integer in the source operand (second operand) to the destination operand (first operand) using a non-temporal hint to minimize cache pollution during the write to memory. The source operand is a general-purpose register. The destination operand is a 32-bit memory location.

The non-temporal hint is implemented by using a write combining (WC) memory type protocol when writing the data to memory. Using this protocol, the processor does not write the data into the cache hierarchy, nor does it fetch the corresponding cache line from memory into the cache hierarchy. The memory type of the region being written to can override the non-temporal hint, if the memory address specified for the non-temporal store is in an uncacheable (UC) or write protected (WP) memory region. For more information on non-temporal stores, see "Caching of Temporal vs. Non-Temporal Data" in Chapter 10 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1.

Because the WC protocol uses a weakly-ordered memory consistency model, a fencing operation implemented with the `SFENCE` or `MFENCE` instruction should be used in conjunction with `MOVNTI` instructions if multiple processors might use different memory types to read/write the destination memory locations.

In 64-bit mode, the instruction's default operation size is 32 bits. Use of the REX.R prefix permits access to addi-tional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
DEST <- SRC;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVNTI: void _mm_stream_si32 (int *p, int a)
MOVNTI: void _mm_stream_si64(__int64 *p, __int64 a)
```
### SIMD Floating-Point Exceptions


None.


### Protected Mode Exceptions

#### #GP(0)
* For an illegal memory operand effective address in the CS, DS, ES, FS or GS segments.

#### #SS(0)
* For an illegal address in the SS segment. 

#### #PF(fault-code)
* For a page fault.

#### #UD
* If CPUID.01H:EDX.SSE2[bit 26] = 0.
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If any part of the operand lies outside the effective address space from 0 to FFFFH.

#### #UD
* If CPUID.01H:EDX.SSE2[bit 26] = 0.
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #PF(fault-code)
* For a page fault.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* For a page fault.

#### #UD
* If CPUID.01H:EDX.SSE2[bit 26] = 0.
* If the LOCK prefix is used.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.
