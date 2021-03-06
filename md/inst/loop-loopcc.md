----------------------------
title : LOOP, LOOPccs (Intel x86/64 assembly instruction)
cat_title : LOOP, LOOPcc
ref_title : LOOP, LOOPcc
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LOOP, LOOPcc

**Loop According to ECX Counter**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|E2 cb|`LOOP` \tooltip{rel8}{현재 명령어로 부터 최대 128 바이트 이전 혹은 127 바이트 이후 까지의 주소} |D|Valid|Valid|Decrement count; jump short if count != 0.|
|E1 cb|LOOPE \tooltip{rel8}{현재 명령어로 부터 최대 128 바이트 이전 혹은 127 바이트 이후 까지의 주소} |D|Valid|Valid|Decrement count; jump short if count != 0 and ZF = 1.|
|E0 cb|LOOPNE \tooltip{rel8}{현재 명령어로 부터 최대 128 바이트 이전 혹은 127 바이트 이후 까지의 주소} |D|Valid|Valid|Decrement count; jump short if count != 0 and ZF = 0.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|D|Offset|NA|NA|NA|
### Description


Performs a loop operation using the RCX, ECX or CX register as a counter (depending on whether address size is 64 bits, 32 bits, or 16 bits). Note that the `LOOP` instruction ignores REX.W; but 64-bit address size can be over-ridden using a 67H prefix.

Each time the `LOOP` instruction is executed, the count register is decremented, then checked for 0. If the count is 0, the loop is terminated and program execution continues with the instruction following the `LOOP` instruction. If the count is not zero, a near jump is performed to the destination (target) operand, which is presumably the instruction at the beginning of the loop.

The target instruction is specified with a relative offset (a signed offset relative to the current value of the instruc-tion pointer in the IP/EIP/RIP register). This offset is generally specified as a label in assembly code, but at the machine code level, it is encoded as a signed, 8-bit immediate value, which is added to the instruction pointer. Offsets of -128 to +127 are allowed with this instruction.

Some forms of the loop instruction (LOOPcc) also accept the ZF flag as a condition for terminating the loop before the count reaches zero. With these forms of the instruction, a condition code (cc) is associated with each instruction to indicate the condition being tested for. Here, the `LOOPcc` instruction itself does not affect the state of the ZF flag; the ZF flag is changed by other instructions in the loop.


### Operation

```info-verb
IF (AddressSize = 32)THEN Count is ECX;ELSE IF (AddressSize = 64)Count is RCX;
ELSE Count is CX; 
FI;
Count <- Count - 1;
IF Instruction is not LOOP
    THEN
          IF (Instruction <- LOOPE) or (Instruction <- LOOPZ)
                THEN IF (ZF = 1) and (Count != 0)
                            THEN BranchCond <- 1;
                            ELSE BranchCond <- 0;
                      FI;
                ELSE (Instruction = LOOPNE) or (Instruction = LOOPNZ)
                      IF (ZF = 0 ) and (Count != 0)
                            THEN BranchCond <- 1;
                            ELSE BranchCond <- 0;
FI;
          FI;
    ELSE (* Instruction = LOOP *)
          IF (Count != 0)
                THEN BranchCond <- 1;
                ELSE BranchCond <- 0;
          FI;
FI;
IF BranchCond = 1
    THEN
          IF OperandSize = 32
                THEN EIP <- EIP + SignExtend(DEST);
                ELSE IF OperandSize = 64
                      THEN RIP <- RIP + SignExtend(DEST);
                      FI;
                ELSE IF OperandSize = 16
                      THEN EIP <- EIP AND 0000FFFFH;
                      FI;
          FI;
          IF OperandSize = (32 or 64)
                THEN IF (R/E)IP < CS.Base or (R/E)IP > CS.Limit
                      #GP; FI;
                      FI;
          FI;
    ELSE
          Terminate loop and continue program execution at (R/E)IP;
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #GP(0)
* If the offset being jumped to is beyond the limits of the CS segment.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If the offset being jumped to is beyond the limits of the CS segment or is outside of the effec-tive address space from 0 to FFFFH. This condition can occur if a 32-bit address size override prefix is used.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions



Same exceptions as in real address mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the offset being jumped to is in a non-canonical form.

#### #UD
* If the LOCK prefix is used.
