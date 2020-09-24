----------------------------
title : CLD (Intel x86/64 assembly instruction)
cat_title : CLD
ref_title : CLD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CLD

**Clear Direction Flag**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FC|`CLD` |NP|Valid|Valid|Clear DF flag.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Clears the DF flag in the EFLAGS register. When the DF flag is set to 0, string operations increment the index regis-ters (ESI and/or EDI). Operation is the same in all modes.


### Operation

```info-verb
DF <- 0;
```
### Flags Affected


The DF flag is set to 0. The CF, OF, ZF, SF, AF, and PF flags are unaffected.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

