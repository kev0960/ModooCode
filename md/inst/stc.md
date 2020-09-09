----------------------------
title : STC (Intel x86/64 assembly instruction)
cat_title : STC
ref_title : STC
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ STC

**Set Carry Flag**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|F9|STC|NP|Valid|Valid|Set CF flag.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Sets the CF flag in the EFLAGS register. Operation is the same in all modes.


### Operation

```info-verb
CF <- 1;
```
### Flags Affected


The CF flag is set. The OF, ZF, SF, AF, and PF flags are unaffected.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

