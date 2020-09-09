----------------------------
title : WRPKRU (Intel x86/64 assembly instruction)
cat_title : WRPKRU
ref_title : WRPKRU
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/W
publish_date: 2020-09-01
----------------------------


#@ WRPKRU

**Write Data to User Page Key Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64/32bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|---------------|------------------------|-----------------------------------------------------|--------------------------------------------------|---------------|
|0F 01 EF|WRPKRU|NP|V/V|OSPKE|Writes EAX into PKRU.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Writes the value of EAX into PKRU. ECX and EDX must be 0 when `WRPKRU` is executed; otherwise, a general-protection exception (#GP) occurs.

WRPKRU can be executed only if CR4.PKE = 1; otherwise, an invalid-opcode exception (#UD) occurs. Software can discover the value of CR4.PKE by examining `CPUID`.(EAX=07H,ECX=0H):ECX.OSPKE [bit 4].

On processors that support the Intel 64 Architecture, the high-order 32-bits of RCX, RDX and RAX are ignored.


### Operation

```info-verb
IF (ECX = 0 AND EDX = 0) 
    THEN PKRU <- EAX;
    ELSE #GP(0); 
FI;
```
### Flags Affected


None.

### C/C++ Compiler Intrinsic Equivalent


WRPKRU: void _wrpkru(uint32_t);


### Protected Mode Exceptions

#### #GP(0)
* If ECX >=B  0.
* If EDX >=B  0.

#### #UD
* If the LOCK prefix is used.
* If CR4.PKE = 0.

### Real-Address Mode Exceptions



Same exceptions as in protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

