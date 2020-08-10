### CBW/CWDE/CDQE--Convert Byte to Word/Convert Word to Doubleword/Convert Doubleword to Quadword


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|98|CBW|NP|Valid|Valid|AX <- sign-extend of AL.|
|98|CWDE|NP|Valid|Valid|EAX <- sign-extend of AX.|
|REX.W + 98|CDQE|NP|Valid|N.E.|RAX <- sign-extend of EAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Double the size of the source operand by means of sign extension. The CBW (convert byte to word) instruction copies the sign (bit 7) in the source operand into every bit in the AH register. The CWDE (convert word to double-word) instruction copies the sign (bit 15) of the word in the AX register into the high 16 bits of the EAX register. 

CBW and CWDE reference the same opcode. The CBW instruction is intended for use when the operand-size attri-bute is 16; CWDE is intended for use when the operand-size attribute is 32. Some assemblers may force the operand size. Others may treat these two mnemonics as synonyms (CBW/CWDE) and use the setting of the operand-size attribute to determine the size of values to be converted.

In 64-bit mode, the default operation size is the size of the destination register. Use of the REX.W prefix promotes this instruction (CDQE when promoted) to operate on 64-bit operands. In which case, CDQE copies the sign (bit 31) of the doubleword in the EAX register into the high 32 bits of RAX.


### Operation

```info-verb
IF OperandSize = 16 (\htmlonly{*} Instruction = CBW \htmlonly{*})
 THEN 
   AX <- SignExtend(AL);
 ELSE IF (OperandSize = 32, Instruction = CWDE)
   EAX <- SignExtend(AX); FI;
 ELSE (\htmlonly{*} 64-Bit Mode, OperandSize = 64, Instruction = CDQE\htmlonly{*})
   RAX <- SignExtend(EAX);
FI;
```
### Flags Affected


None.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

