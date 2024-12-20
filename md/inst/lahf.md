----------------------------
title : LAHF (Intel x86/64 assembly instruction)
cat_title : LAHF
ref_title : LAHF
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LAHF

**Load Status Flags into AH Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|9F |`LAHF` |NP|Invalid\htmlonly{*}|Valid|Load: AH <- EFLAGS(SF:ZF:0:AF:0:PF:1:CF).|

```note
\htmlonly{*}Valid in specific steppings. See Description section
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


This instruction executes as described above in compatibility mode and legacy mode. It is valid in 64-bit mode only if `CPUID`.80000001H:ECX.LAHF-SAHF[bit 0] = 1. 


### Operation

```info-verb
IF 64-Bit ModeTHENIF CPUID.80000001H:ECX.LAHF-SAHF[bit 0] = 1;THEN AH <- RFLAGS(SF:ZF:0:AF:0:PF:1:CF);ELSE #UD; FI;ELSEAH <- EFLAGS(SF:ZF:0:AF:0:PF:1:CF);FI;
```
### Flags Affected


None. The state of the flags in the EFLAGS register is not affected.


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions



Same exceptions as in protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If CPUID.80000001H:ECX.LAHF-SAHF[bit 0] = 0.
* If the LOCK prefix is used.
