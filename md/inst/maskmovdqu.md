----------------------------
title : MASKMOVDQU (Intel x86/64 assembly instruction)
cat_title : MASKMOVDQU
ref_title : MASKMOVDQU
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------
#@ MASKMOVDQU

**Store Selected Bytes of Double Quadword**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|66 0F F7 /r\newline{}\newline{}MASKMOVDQU xmm1, xmm2|RM|V/V|SSE2|Selectively write bytes from xmm1 to memory location using the byte mask in xmm2. The default memory location is specified by DS:DI/EDI/RDI.|
|VEX.128.66.0F.WIG F7 /r\newline{}\newline{}VMASKMOVDQU xmm1, xmm2|RM|V/V|AVX|Selectively write bytes from xmm1 to memory location using the byte mask in xmm2. The default memory location is specified by DS:DI/EDI/RDI.|
### Instruction Operand Encoding\footnote{1}


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r)|ModRM:r/m (r)|NA|NA|
### Description


Stores selected bytes from the source operand (first operand) into an 128-bit memory location. The mask operand (second operand) selects which bytes from the source operand are written to memory. The source and mask oper-ands are XMM registers. The memory location specified by the effective address in the DI/EDI/RDI register (the default segment register is DS, but this may be overridden with a segment-override prefix). The memory location does not need to be aligned on a natural boundary. (The size of the store address depends on the address-size attribute.)

The most significant bit in each byte of the mask operand determines whether the corresponding byte in the source operand is written to the corresponding byte location in memory: 0 indicates no write and 1 indicates write. 

The `MASKMOVDQU` instruction generates a non-temporal hint to the processor to minimize cache pollution. The non-temporal hint is implemented by using a write combining (WC) memory type protocol (see "Caching of Temporal vs. Non-Temporal Data" in Chapter 10, of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1). Because the WC protocol uses a weakly-ordered memory consistency model, a fencing opera-tion implemented with the `SFENCE` or `MFENCE` instruction should be used in conjunction with `MASKMOVDQU` instructions if multiple processors might use different memory types to read/write the destination memory loca-tions.

Behavior with a mask of all 0s is as follows:

*  No data will be written to memory. 

*  Signaling of breakpoints (code or data) is not guaranteed; different processor implementations may signal or not signal these breakpoints.

*  Exceptions associated with addressing memory and page faults may still be signaled (implementation dependent).

*  If the destination memory region is mapped as UC or WP, enforcement of associated semantics for these memory types is not guaranteed (that is, is reserved) and is implementation-specific. 

The `MASKMOVDQU` instruction can be used to improve performance of algorithms that need to merge data on a byte-by-byte basis. `MASKMOVDQU` should not cause a read for ownership; doing so generates unnecessary band-width since data is to be written directly using the byte-mask without allocating old data prior to the store. 

In 64-bit mode, use of the REX.R prefix permits this instruction to access additional registers (XMM8-XMM15).

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

If VMASKMOVDQU is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.

```sidenote


1.ModRM.MOD = 011B required
```
### Operation

```info-verb
IF (MASK[7] = 1)
    THEN DEST[DI/EDI] <- SRC[7:0] ELSE (* Memory location unchanged *); FI;
IF (MASK[15] = 1) 
    THEN DEST[DI/EDI +1] <- SRC[15:8] ELSE (* Memory location unchanged *); FI;
    (* Repeat operation for 3rd through 14th bytes in source operand *)
IF (MASK[127] = 1) 
    THEN DEST[DI/EDI +15] <- SRC[127:120] ELSE (* Memory location unchanged *); FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
void _mm_maskmoveu_si128(__m128i d, __m128i n, char * p)
```
### Other Exceptions


See Exceptions Type 4; additionally

#UD  If VEX.L= 1

                              If VEX.vvvv ->  1111B.

