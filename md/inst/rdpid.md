----------------------------
title : RDPID (Intel x86/64 assembly instruction)
cat_title : RDPID
ref_title : RDPID
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RDPID

**Read Processor ID**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-**\newline{}**bit **\newline{}**Mode**|**CPUID**\newline{}**Feature Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|-----------------------------------|---------------|
|F3 0F C7 /7\newline{}RDPID r32|M|N.E./V|RDPID|Read IA32_TSC_AUX into r32.|
|F3 0F C7 /7\newline{}RDPID r64|M|V/N.E.|RDPID|Read IA32_TSC_AUX into r64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Reads the value of the IA32\esc{_}TSC\esc{_}AUX MSR (address C0000103H) into the destination register. The value of CS.D and operand-size prefixes (66H and REX.W) do not affect the behavior of the `RDPID` instruction.


### Operation

```info-verb
DEST <- IA32_TSC_AUX 
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the F2 prefix is used.
* If CPUID.7H.0:ECX.RDPID[bit 22] = 0.

### Real-Address Mode Exceptions



Same exceptions as in protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

