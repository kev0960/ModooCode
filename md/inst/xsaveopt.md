----------------------------
title : XSAVEOPT (Intel x86/64 assembly instruction)
cat_title : XSAVEOPT
ref_title : XSAVEOPT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/X
publish_date: 2020-09-01
----------------------------


#@ XSAVEOPT

**Save Processor Extended States Optimized**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F AE /6`\newline{}`XSAVEOPT` mem |M|V/V|XSAVEOPT|Save state components specified by EDX:EAX to mem, optimizing if possible.|
|`REX.W + 0F AE /6`\newline{}XSAVEOPT64 mem |M|V/V|XSAVEOPT|Save state components specified by EDX:EAX to mem, optimizing if possible.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Performs a full or partial save of processor state components to the `XSAVE` area located at the memory address specified by the destination operand. The implicit EDX:EAX register pair specifies a 64-bit instruction mask. The specific state components saved correspond to the bits set in the requested-feature bitmap (RFBM), which is the logical-AND of EDX:EAX and XCR0.

The format of the `XSAVE` area is detailed in Section 13.4, "XSAVE Area," of Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 1.

Section 13.9, "Operation of `XSAVEOPT`," of Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1 provides a detailed description of the operation of the `XSAVEOPT` instruction. The following items provide a high-level outline:

*  Execution of `XSAVEOPT` is similar to that of `XSAVE`. `XSAVEOPT` differs from `XSAVE` in that it uses compaction and that it may use the init and modified optimizations. The performance of `XSAVEOPT` will be equal to or better than that of `XSAVE`.

*  `XSAVEOPT` saves state component i only if RFBM[i] = 1 and XINUSE[i] = 1.\footnote{1}  (XINUSE is a bitmap by which the processor tracks the status of various state components. See Section 13.6, "Processor Tracking of XSAVE-Managed State.") Even if both bits are 1, `XSAVEOPT` may optimize and not save state component i if (1) state component i has not been modified since the last execution of XRTOR or XRSTORS; and (2) this execution of `XSAVES` corresponds to that last execution of XRTOR or `XRSTORS` as determined by the internal value XRSTOR\esc{_}INFO (see the Operation section below).

*  `XSAVEOPT` does not modify bytes 511:464 of the legacy region of the `XSAVE` area (see Section 13.4.1, "Legacy Region of an `XSAVE` Area").

*  `XSAVEOPT` reads the XSTATE\esc{_}BV field of the `XSAVE` header (see Section 13.4.2, "XSAVE Header") and writes a modified value back to memory as follows. If RFBM[i] = 1, `XSAVEOPT` writes XSTATE\esc{_}BV[i] with the value of XINUSE[i]. If RFBM[i] = 0, `XSAVEOPT` writes XSTATE\esc{_}BV[i] with the value that it read from memory (it does not modify the bit). `XSAVEOPT` does not write to any part of the `XSAVE` header other than the XSTATE\esc{_}BV field.

*  `XSAVEOPT` always uses the standard format of the extended region of the `XSAVE` area (see Section 13.4.3, "Extended Region of an `XSAVE` Area").

Use of a destination operand not aligned to 64-byte boundary (in either 64-bit or 32-bit modes) will result in a general-protection (#GP) exception. In 64-bit mode, the upper 32 bits of RDX and RAX are ignored.


### Operation

```info-verb
RFBM <- XCR0 AND EDX:EAX; /* bitwise logical AND */
OLD_BV <- XSTATE_BV field from XSAVE header;
```
```sidenote


1. There is an exception made for MXCSR and MXCSR_MASK, which belong to state component 1 -- SSE. XSAVEOPT always saves these to memory if RFBM[1]= 1 or RFBM[2]= 1, regardless of the value of XINUSE.
```

IF in VMX non-root operation

    THEN VMXNR <- 1;

    ELSE VMXNR <- 0;

FI;

LAXA <- linear address of XSAVE area;

COMPMASK <- 00000000_00000000H;

IF XRSTOR_INFO= < CPL,VMXNR,LAXA,COMPMASK>

    THEN MODOPT <- 1;

    ELSE MODOPT <- 0;

FI;

IF RFBM[0]= 1 and XINUSE[0]= 1

    THEN store x87 state into legacy region of XSAVE area;

    /\htmlonly{*} might avoid saving if x87 state is not modified and MODOPT= 1 \htmlonly{*}/

FI;

IF RFBM[1]= 1 and XINUSE[1]

    THEN store XMM registers into legacy region of XSAVE area;

    /\htmlonly{*} might avoid saving if XMM registers are not modified and MODOPT= 1 \htmlonly{*}/

FI;

IF RFBM[2]= 1 AND XINUSE[2]= 1

    THEN store AVX state into extended region of XSAVE area;

    /\htmlonly{*} might avoid saving if AVX state is not modified and MODOPT= 1 \htmlonly{*}/

FI;

IF RFBM[1]= 1 or RFBM[2]= 1

    THEN store MXCSR and MXCSR_MASK into legacy region of XSAVE area;

FI;

XSTATE_BV field in XSAVE header <- (OLD_BV AND ~RFBM) OR (XINUSE AND RFBM);

### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XSAVEOPT: void _xsaveopt( void * , unsigned __int64);
XSAVEOPT: void _xsaveopt64( void * , unsigned __int64);
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
* If CPUID.01H:ECX.XSAVE[bit 26] = 0 or CPUID.(EAX=0DH,ECX=1):EAX.XSAVEOPT[bit 0] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If the LOCK prefix is used.
* If 66H, F3H or F2H prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand is not aligned on a 64-byte boundary, regardless of segment.
* If any part of the operand lies outside the effective address space from 0 to FFFFH.

#### #NM
* If CR0.TS[bit 3] = 1.

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0 or CPUID.(EAX=0DH,ECX=1):EAX.XSAVEOPT[bit 0] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If the LOCK prefix is used.
* If 66H, F3H or F2H prefix is used.

### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.
* If a memory operand is not aligned on a 64-byte boundary, regardless of segment.

#### #PF(fault-code)
* If a page fault occurs.

#### #NM
* If CR0.TS[bit 3] = 1.

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0 or CPUID.(EAX=0DH,ECX=1):EAX.XSAVEOPT[bit 0] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If the LOCK prefix is used.
* If 66H, F3H or F2H prefix is used.
