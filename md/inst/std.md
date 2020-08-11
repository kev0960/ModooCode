----------------------------
title : STD (Intel x86/64 assembly instruction)
cat_title : STD
ref_title : STD
path : /X86-64 명령어 레퍼런스
----------------------------
#@ STD

**Set Direction Flag**

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FD|STD|NP|Valid|Valid|Set DF flag.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Sets the DF flag in the EFLAGS register. When the DF flag is set to 1, string operations decrement the index regis-ters (ESI and/or EDI). Operation is the same in all modes.


### Operation

```info-verb
DF <- 1;
```
### Flags Affected


The DF flag is set. The CF, OF, ZF, SF, AF, and PF flags are unaffected.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

