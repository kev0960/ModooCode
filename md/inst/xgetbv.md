----------------------------
title : XGETBV (Intel x86/64 assembly instruction)
cat_title : XGETBV
ref_title : XGETBV
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/X
publish_date: 2020-09-01
----------------------------


#@ XGETBV

**Get Value of Extended Control Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 01 D0|`XGETBV` |NP|Valid|Valid|Reads an XCR specified by ECX into EDX:EAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Reads the contents of the extended control register (XCR) specified in the ECX register into registers EDX:EAX. (On processors that support the Intel 64 architecture, the high-order 32 bits of RCX are ignored.) The EDX register is loaded with the high-order 32 bits of the XCR and the EAX register is loaded with the low-order 32 bits. (On proces-sors that support the Intel 64 architecture, the high-order 32 bits of each of RAX and RDX are cleared.) If fewer than 64 bits are implemented in the XCR being read, the values returned to EDX:EAX in unimplemented bit loca-tions are undefined.

XCR0 is supported on any processor that supports the `XGETBV` instruction. If `CPUID`.(EAX=0DH,ECX=1):EAX.XG1[bit 2] = 1, executing `XGETBV` with ECX = 1 returns in EDX:EAX the logical-AND of XCR0 and the current value of the XINUSE state-component bitmap. This allows software to discover the state of the init optimization used by `XSAVEOPT` and `XSAVES`. See Chapter 13, "Managing State Using the `XSAVE` Feature Set," in Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1.

Use of any other value for ECX results in a general-protection (#GP) exception.


### Operation

```info-verb
EDX:EAX <- XCR[ECX];
```
### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XGETBV: unsigned __int64 _xgetbv( unsigned int);
```

### Protected Mode Exceptions

#### #GP(0)
* If an invalid XCR is specified in ECX (includes ECX = 1 if CPUID.(EAX=0DH,ECX=1):EAX.XG1[bit 2] = 0).

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If the LOCK prefix is used.
* If 66H, F3H or F2H prefix is used.

### Real-Address Mode Exceptions

#### #GP(0)
* If an invalid XCR is specified in ECX (includes ECX = 1 if CPUID.(EAX=0DH,ECX=1):EAX.XG1[bit 2] = 0).

#### #UD
* If CPUID.01H:ECX.XSAVE[bit 26] = 0.
* If CR4.OSXSAVE[bit 18] = 0.
* If the LOCK prefix is used.
* If 66H, F3H or F2H prefix is used.

### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

