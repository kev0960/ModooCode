----------------------------
title : XSAVE (Intel x86/64 assembly instruction)
cat_title : XSAVE
ref_title : XSAVE
path : /X86-64 명령어 레퍼런스
----------------------------
#@ XSAVE

**Save Processor Extended States**

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F AE /4|XSAVE mem|M|Valid|Valid|Save state components specified by EDX:EAX to mem.|
|REX.W+ 0F AE /4|XSAVE64 mem|M|Valid|N.E.|Save state components specified by EDX:EAX to mem.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Performs a full or partial save of processor state components to the `XSAVE` area located at the memory address specified by the destination operand. The implicit EDX:EAX register pair specifies a 64-bit instruction mask. The specific state components saved correspond to the bits set in the requested-feature bitmap (RFBM), which is the logical-AND of EDX:EAX and XCR0.

The format of the `XSAVE` area is detailed in Section 13.4, "XSAVE Area," of Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 1.

Section 13.7, "Operation of `XSAVE`," of Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1 provides a detailed description of the operation of the `XSAVE` instruction. The following items provide a high-level outline:*  `XSAVE` saves state component i if and only if RFBM[i] = 1.\footnote{1}

*  `XSAVE` does not modify bytes 511:464 of the legacy region of the `XSAVE` area (see Section 13.4.1, "Legacy Region of an `XSAVE` Area").

*  `XSAVE` reads the XSTATE_BV field of the `XSAVE` header (see Section 13.4.2, "XSAVE Header") and writes a modified value back to memory as follows. If RFBM[i] = 1, `XSAVE` writes XSTATE_BV[i] with the value of XINUSE[i]. (XINUSE is a bitmap by which the processor tracks the status of various state components. See Section 13.6, "Processor Tracking of XSAVE-Managed State.") If RFBM[i] = 0, `XSAVE` writes XSTATE_BV[i] with the value that it read from memory (it does not modify the bit). `XSAVE` does not write to any part of the `XSAVE` header other than the XSTATE_BV field.

*  `XSAVE` always uses the standard format of the extended region of the `XSAVE` area (see Section 13.4.3, "Extended Region of an `XSAVE` Area").

Use of a destination operand not aligned to 64-byte boundary (in either 64-bit or 32-bit modes) results in a general-protection (#GP) exception. In 64-bit mode, the upper 32 bits of RDX and RAX are ignored.


### Operation

```info-verb
RFBM <- XCR0 AND EDX:EAX; /* bitwise logical AND */
OLD_BV <- XSTATE_BV field from XSAVE header;
IF RFBM[0]= 1
    THEN store x87 state into legacy region of XSAVE area;
FI;
IF RFBM[1]= 1
    THEN store XMM registers into legacy region of XSAVE area;
FI;
```
```sidenote


1. An exception is made for MXCSR and MXCSR_MASK, which belong to state component 1 -- SSE. XSAVE saves these values to mem-ory if either RFBM[1] or RFBM[2] is 1.
```

IF RFBM[2]= 1

    THEN store AVX state into extended region of XSAVE area;

FI;

IF RFBM[1]= 1 or RFBM[2]= 1

    THEN store MXCSR and MXCSR_MASK into legacy region of XSAVE area;

FI;

XSTATE_BV field in XSAVE header <- (OLD_BV AND ~RFBM) OR (XINUSE AND RFBM);

### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XSAVE: void _xsave( void * , unsigned __int64);
XSAVE: void _xsave64( void * , unsigned __int64);
```

### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If a memory operand is not aligned on a 64-byte boundary, regardless of segment.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #NM
* If CR0.TS[bit 3] = 1.

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If any of the LOCK, 66H, F3H or F2H prefixes is used.

#### #AC
* If this exception is disabled a general protection exception (#GP) is signaled if the memory operand is not aligned on a 16-byte boundary, as described above. If the alignment check exception (#AC) is enabled (and the CPL is 3), signaling of #AC is not guaranteed and may vary with implementation, as follows. In all implementations where #AC is not signaled, a general protection exception is signaled in its place. In addition, the width of the alignment check may also vary with implementation. For instance, for a given implementation, an align-ment check exception might be signaled for a 2-byte misalignment, whereas a general protec-tion exception might be signaled for all other misalignments (4-, 8-, or 16-byte misalignments).

### Real-Address Mode Exceptions

#### #GP
* If a memory operand is not aligned on a 64-byte boundary, regardless of segment.
* If any part of the operand lies outside the effective address space from 0 to FFFFH.

#### #NM
* If CR0.TS[bit 3] = 1.

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If any of the LOCK, 66H, F3H or F2H prefixes is used.

### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.
* If a memory operand is not aligned on a 64-byte boundary, regardless of segment.

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #NM
* If CR0.TS[bit 3] = 1.

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If any of the LOCK, 66H, F3H or F2H prefixes is used.

#### #AC
* If this exception is disabled a general protection exception (#GP) is signaled if the memory operand is not aligned on a 16-byte boundary, as described above. If the alignment check exception (#AC) is enabled (and the CPL is 3), signaling of #AC is not guaranteed and may vary with implementation, as follows. In all implementations where #AC is not signaled, a general protection exception is signaled in its place. In addition, the width of the alignment check may also vary with implementation. For instance, for a given implementation, an align-ment check exception might be signaled for a 2-byte misalignment, whereas a general protec-tion exception might be signaled for all other misalignments (4-, 8-, or 16-byte misalignments).
