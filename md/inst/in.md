----------------------------
title : IN instruction(Intel x86/64 assembly instruction)
cat_title : IN
----------------------------
### IN--Input from Port


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|E4 ib|IN AL, imm8|I|Valid|Valid|Input byte from imm8 I/O port address into AL.|
|E5 ib|IN AX, imm8|I|Valid|Valid|Input word from imm8 I/O port address into AX.|
|E5 ib|IN EAX, imm8|I|Valid|Valid|Input dword from imm8 I/O port address into EAX.|
|EC|IN AL,DX|NP|Valid|Valid|Input byte from I/O port in DX into AL.|
|ED|IN AX,DX|NP|Valid|Valid|Input word from I/O port in DX into AX.|
|ED|IN EAX,DX|NP|Valid|Valid|Input doubleword from I/O port in DX into EAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|I|imm8|NA|NA|NA|
|NP|NA|NA|NA|NA|
### Description


Copies the value from the I/O port specified with the second operand (source operand) to the destination operand (first operand). The source operand can be a byte-immediate or the DX register; the destination operand can be register AL, AX, or EAX, depending on the size of the port being accessed (8, 16, or 32 bits, respectively). Using the DX register as a source operand allows I/O port addresses from 0 to 65,535 to be accessed; using a byte imme-diate allows I/O port addresses 0 to 255 to be accessed.

When accessing an 8-bit I/O port, the opcode determines the port size; when accessing a 16- and 32-bit I/O port, the operand-size attribute determines the port size. At the machine code level, I/O instructions are shorter when accessing 8-bit I/O ports. Here, the upper eight bits of the port address will be 0.

This instruction is only useful for accessing I/O ports located in the processor's I/O address space. See Chapter 18, "Input/Output," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for more infor-mation on accessing I/O ports in the I/O address space.

This instruction's operation is the same in non-64-bit modes and 64-bit mode.


### Operation

```info-verb
IF ((PE = 1) and ((CPL > IOPL) or (VM = 1)))
 THEN (\htmlonly{*} Protected mode with CPL > IOPL or virtual-8086 mode \htmlonly{*})
   IF (Any I/O Permission Bit for I/O port being accessed = 1)
    THEN (\htmlonly{*} I/O operation is not allowed \htmlonly{*})
      #GP(0);
    ELSE ( \htmlonly{*} I/O operation is allowed \htmlonly{*}) 
      DEST <- SRC; (\htmlonly{*} Read from selected I/O port \htmlonly{*})
   FI;
 ELSE (Real Mode or Protected Mode with CPL <= IOPL \htmlonly{*})
   DEST <- SRC; (\htmlonly{*} Read from selected I/O port \htmlonly{*})
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #GP(0)
* If the CPL is greater than (has less privilege) the I/O privilege level (IOPL) and any of the corresponding I/O permission bits in TSS for the I/O port being accessed is 1.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If any of the I/O permission bits in the TSS for the I/O port being accessed is 1.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the CPL is greater than (has less privilege) the I/O privilege level (IOPL) and any of the corresponding I/O permission bits in TSS for the I/O port being accessed is 1.

#### #UD
* If the LOCK prefix is used.
