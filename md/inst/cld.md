### CLD--Clear Direction Flag


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FC|CLD|NP|Valid|Valid|Clear DF flag.|
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

