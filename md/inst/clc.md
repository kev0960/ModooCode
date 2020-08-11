----------------------------
title : CLC (Intel x86/64 assembly instruction)
cat_title : CLC
ref_title : CLC
path : /X86-64 명령어 레퍼런스
----------------------------
#@ CLC

**Clear Carry Flag**

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|F8|CLC|NP|Valid|Valid|Clear CF flag.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Clears the CF flag in the EFLAGS register. Operation is the same in all modes.


### Operation

```info-verb
CF <- 0;
```
### Flags Affected


The CF flag is set to 0. The OF, ZF, SF, AF, and PF flags are unaffected.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

