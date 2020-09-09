----------------------------
title : XSAVES (Intel x86/64 assembly instruction)
cat_title : XSAVES
ref_title : XSAVES
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/X
publish_date: 2020-09-01
----------------------------


#@ XSAVES

**Save Processor Extended States Supervisor**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F C7 /5|XSAVES mem|M|Valid|Valid|Save state components specified by EDX:EAX to mem with compaction, optimizing if possible.|
|REX.W+ 0F C7 /5|XSAVES64 mem|M|Valid|N.E.|Save state components specified by EDX:EAX to mem with compaction, optimizing if possible.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Performs a full or partial save of processor state components to the `XSAVE` area located at the memory address specified by the destination operand. The implicit EDX:EAX register pair specifies a 64-bit instruction mask. The specific state components saved correspond to the bits set in the requested-feature bitmap (RFBM), the logical-AND of EDX:EAX and the logical-OR of XCR0 with the IA32\esc{_}XSS MSR. `XSAVES` may be executed only if CPL = 0.

The format of the `XSAVE` area is detailed in Section 13.4, "XSAVE Area," of Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 1.

Section 13.11, "Operation of `XSAVES`," of Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1 provides a detailed description of the operation of the `XSAVES` instruction. The following items provide a high-level outline:

*  Execution of `XSAVES` is similar to that of `XSAVEC`. `XSAVES` differs from `XSAVEC` in that it can save state components corresponding to bits set in the IA32\esc{_}XSS MSR and that it may use the modified optimization.

*  `XSAVES` saves state component i only if RFBM[i] = 1 and XINUSE[i] = 1.\footnote{1}  (XINUSE is a bitmap by which the processor tracks the status of various state components. See Section 13.6, "Processor Tracking of XSAVE-Managed State.") Even if both bits are 1, `XSAVES` may optimize and not save state component i if (1) state component i has not been modified since the last execution of XRTOR or XRSTORS; and (2) this execution of `XSAVES` correspond to that last execution of XRTOR or `XRSTORS` as determined by XRSTOR\esc{_}INFO (see the Operation section below).

*  `XSAVES` does not modify bytes 511:464 of the legacy region of the `XSAVE` area (see Section 13.4.1, "Legacy Region of an `XSAVE` Area").

*  `XSAVES` writes the logical `AND` of RFBM and XINUSE to the XSTATE\esc{_}BV field of the `XSAVE` header.\footnote{2}  (See Section 13.4.2, "XSAVE Header.") `XSAVES` sets bit 63 of the XCOMP\esc{_}BV field and sets bits 62:0 of that field to RFBM[62:0]. `XSAVES` does not write to any parts of the `XSAVE` header other than the XSTATE\esc{_}BV and XCOMP\esc{_}BV fields.

*  `XSAVES` always uses the compacted format of the extended region of the `XSAVE` area (see Section 13.4.3, "Extended Region of an `XSAVE` Area").

Use of a destination operand not aligned to 64-byte boundary (in either 64-bit or 32-bit modes) results in a general-protection (#GP) exception. In 64-bit mode, the upper 32 bits of RDX and RAX are ignored.

```sidenote


1. There is an exception for state component 1 (SSE). MXCSR is part of SSE state, but XINUSE[1] may be 0 even if MXCSR does not have its initial value of 1F80H. In this case, the init optimization does not apply and XSAVEC will save SSE state as long as RFBM[1]= 1 and the modified optimization is not being applied.

2. There is an exception for state component 1 (SSE). MXCSR is part of SSE state, but XINUSE[1] may be 0 even if MXCSR does not have its initial value of 1F80H. In this case, XSAVES sets XSTATE_BV[1] to 1 as long as RFBM[1]= 1.
```
### Operation

```info-verb
RFBM <- (XCR0 OR IA32_XSS) AND EDX:EAX; /* bitwise logical OR and AND */
IF in VMX non-root operation
    THEN VMXNR <- 1;
    ELSE VMXNR <- 0;
FI;
LAXA <- linear address of XSAVE area;
COMPMASK <- RFBM OR 80000000_00000000H;
IF XRSTOR_INFO= < CPL,VMXNR,LAXA,COMPMASK>
    THEN MODOPT <- 1;
    ELSE MODOPT <- 0;
FI;
IF RFBM[0]= 1 and XINUSE[0]= 1
    THEN store x87 state into legacy region of XSAVE area;
    /* might avoid saving if x87 state is not modified and MODOPT= 1 */
FI;
IF RFBM[1]= 1 and (XINUSE[1]= 1 or MXCSR ->  1F80H)
    THEN store SSE state into legacy region of XSAVE area;
    /* might avoid saving if SSE state is not modified and MODOPT= 1 */
FI;
IF RFBM[2]= 1 AND XINUSE[2]= 1
    THEN store AVX state into extended region of XSAVE area;
    /* might avoid saving if AVX state is not modified and MODOPT= 1 */
FI;
XSTATE_BV field in XSAVE header <- XINUSE AND RFBM;\footnote{1}
XCOMP_BV field in XSAVE header <- COMPMASK;
```
### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XSAVES: void _xsaves( void * , unsigned __int64);
XSAVES64: void _xsaves64( void * , unsigned __int64);
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
* If CPUID.01H:ECX.XSAVE[bit 26] = 0 or CPUID.(EAX=0DH,ECX=1):EAX.XSS[bit 3] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If any of the LOCK, 66H, F3H or F2H prefixes is used.

#### #AC
* If this exception is disabled a general protection exception (#GP) is signaled if the memory operand is not aligned on a 16-byte boundary, as described above. If the alignment check 
```sidenote


1. If MXCSR does not have its initial value of 1F80H, XSAVES sets XSTATE_BV[1] to 1 as long as RFBM[1] = 1, regardless of the value of XINUSE[1].
```

exception (#AC) is enabled (and the CPL is 3), signaling of #AC is not guaranteed and may vary with implementation, as follows. In all implementations where #AC is not signaled, a general protection exception is signaled in its place. In addition, the width of the alignment check may also vary with implementation. For instance, for a given implementation, an align-ment check exception might be signaled for a 2-byte misalignment, whereas a general protec-tion exception might be signaled for all other misalignments (4-, 8-, or 16-byte misalignments).


### Real-Address Mode Exceptions

#### #GP
* If a memory operand is not aligned on a 64-byte boundary, regardless of segment.
* If any part of the operand lies outside the effective address space from 0 to FFFFH.

#### #NM
* If CR0.TS[bit 3] = 1.

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0 or CPUID.(EAX=0DH,ECX=1):EAX.XSS[bit 3] = 0.
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
* If CPUID.01H:ECX.XSAVE[bit 26] = 0 or CPUID.(EAX=0DH,ECX=1):EAX.XSS[bit 3] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If any of the LOCK, 66H, F3H or F2H prefixes is used.

#### #AC
* If this exception is disabled a general protection exception (#GP) is signaled if the memory operand is not aligned on a 16-byte boundary, as described above. If the alignment check exception (#AC) is enabled (and the CPL is 3), signaling of #AC is not guaranteed and may vary with implementation, as follows. In all implementations where #AC is not signaled, a general protection exception is signaled in its place. In addition, the width of the alignment check may also vary with implementation. For instance, for a given implementation, an align-ment check exception might be signaled for a 2-byte misalignment, whereas a general protec-tion exception might be signaled for all other misalignments (4-, 8-, or 16-byte misalignments).
