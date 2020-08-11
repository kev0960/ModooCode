----------------------------
title : NOP instruction(Intel x86/64 assembly instruction)
cat_title : NOP
----------------------------
### NOP--No Operation


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|90|NOP|NP|Valid|Valid|One byte no-operation instruction.|
|0F 1F /0|NOP r/m16|M|Valid|Valid|Multi-byte no-operation instruction.|
|0F 1F /0|NOP r/m32|M|Valid|Valid|Multi-byte no-operation instruction.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


This instruction performs no operation. It is a one-byte or multi-byte NOP that takes up space in the instruction stream but does not impact machine context, except for the EIPregister.

The multi-byte form of NOP is available on processors with model encoding:

*  CPUID.01H.EAX[Bytes 11:8] = 0110B or 1111B

The multi-byte NOP instruction does not alter the content of a register and will not issue a memory operation. The instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
The one-byte NOP instruction is an alias mnemonic for the XCHG (E)AX, (E)AX instruction.
The multi-byte NOP instruction performs no operation on supported processors and generates undefined opcode exception on processors that do not support the multi-byte NOP instruction.
The memory operand form of the instruction allows software to create a byte sequence of "no operation" as one instruction. For situations where multiple-byte NOPs are needed, the recommended operations (32-bit mode and 64-bit mode) are: 
```
### Table 4-12.  Recommended Multi-Byte Sequence of NOP Instruction


|**Length**|**Assembly**|**Byte Sequence**|
|----------|------------|-----------------|
|2 bytes\newline{}3 bytes\newline{}4 bytes\newline{}5 bytes\newline{}6 bytes\newline{}7 bytes\newline{}8 bytes\newline{}9 bytes|66 NOP\newline{}NOP DWORD ptr [EAX]\newline{}NOP DWORD ptr [EAX + 00H]\newline{}NOP DWORD ptr [EAX + EAX*1 + 00H]\newline{}66 NOP DWORD ptr [EAX + EAX*1 + 00H]\newline{}NOP DWORD ptr [EAX + 00000000H]\newline{}NOP DWORD ptr [EAX + EAX*1 + 00000000H]\newline{}66 NOP DWORD ptr [EAX + EAX*1 + 00000000H]|66 90H\newline{}0F 1F 00H\newline{}0F 1F 40 00H\newline{}0F 1F 44 00 00H\newline{}66 0F 1F 44 00 00H\newline{}0F 1F 80 00 00 00 00H\newline{}0F 1F 84 00 00 00 00 00H\newline{}66 0F 1F 84 00 00 00 00 00H|
### Flags Affected


None

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

