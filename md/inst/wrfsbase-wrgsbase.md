----------------------------
title : WRFSBASE, WRGSBASEs (Intel x86/64 assembly instruction)
cat_title : WRFSBASE, WRGSBASE
ref_title : WRFSBASE, WRGSBASE
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/W
publish_date: 2020-09-01
----------------------------


#@ WRFSBASE, WRGSBASE

**Write FS/GS Segment Base**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-**\newline{}**bit **\newline{}**Mode**|**CPUID Fea-**\newline{}**ture Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|-------------------------------------|---------------|
|`F3 0F AE /2`\newline{}`WRFSBASE` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |M|V/I|FSGSBASE|Load the FS base address with the 32-bit value in the source register.|
|`F3 REX.W 0F AE /2`\newline{}`WRFSBASE` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |M|V/I|FSGSBASE|Load the FS base address with the 64-bit value in the source register.|
|`F3 0F AE /3`\newline{}`WRGSBASE` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |M|V/I|FSGSBASE|Load the GS base address with the 32-bit value in the source register.|
|`F3 REX.W 0F AE /3`\newline{}`WRGSBASE` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |M|V/I|FSGSBASE|Load the GS base address with the 64-bit value in the source register.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Loads the FS or GS segment base address with the general-purpose register indicated by the modR/M:r/m field.

The source operand may be either a 32-bit or a 64-bit general-purpose register. The REX.W prefix indicates the operand size is 64 bits. If no REX.W prefix is used, the operand size is 32 bits; the upper 32 bits of the source register are ignored and upper 32 bits of the base address (for FS or GS) are cleared. 

This instruction is supported only in 64-bit mode.


### Operation

```info-verb
FS/GS segment base address <- SRC;
```
### Flags Affected


None

### C/C++ Compiler Intrinsic Equivalent


WRFSBASE:  void _writefsbase_u32( unsigned int );

WRFSBASE:  _writefsbase_u64( unsigned __int64 );

WRGSBASE:  void _writegsbase_u32( unsigned int );

WRGSBASE:  _writegsbase_u64( unsigned __int64 );


### Protected Mode Exceptions

#### #UD
* The WRFSBASE and WRGSBASE instructions are not recognized in protected mode.

### Real-Address Mode Exceptions

#### #UD
* The WRFSBASE and WRGSBASE instructions are not recognized in real-address mode.

### Virtual-8086 Mode Exceptions

#### #UD
* The WRFSBASE and WRGSBASE instructions are not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions

#### #UD
* The WRFSBASE and WRGSBASE instructions are not recognized in compatibility mode.

### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If CR4.FSGSBASE[bit 16] = 0.
* If CPUID.07H.0H:EBX.FSGSBASE[bit 0] = 0

#### #GP(0)
* If the source register contains a non-canonical address.
