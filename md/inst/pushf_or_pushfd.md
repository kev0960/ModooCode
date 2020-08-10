### PUSHF/PUSHFD--Push EFLAGS Register onto the Stack


|**Opcode***|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|-----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|9C|PUSHF|NP|Valid|Valid|Push lower 16 bits of EFLAGS.|
|9C|PUSHFD|NP|N.E.|Valid|Push EFLAGS.|
|9C|PUSHFQ|NP|Valid|N.E.|Push RFLAGS.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Decrements the stack pointer by 4 (if the current operand-size attribute is 32) and pushes the entire contents of the EFLAGS register onto the stack, or decrements the stack pointer by 2 (if the operand-size attribute is 16) and pushes the lower 16 bits of the EFLAGS register (that is, the FLAGS register) onto the stack. These instructions reverse the operation of the POPF/POPFD instructions. 

When copying the entire EFLAGS register to the stack, the VM and RF flags (bits 16 and 17) are not copied; instead, the values for these flags are cleared in the EFLAGS image stored on the stack. See Chapter 3 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for more information about the EFLAGS register. 

The PUSHF (push flags) and PUSHFD (push flags double) mnemonics reference the same opcode. The PUSHF instruction is intended for use when the operand-size attribute is 16 and the PUSHFD instruction for when the operand-size attribute is 32. Some assemblers may force the operand size to 16 when PUSHF is used and to 32 when PUSHFD is used. Others may treat these mnemonics as synonyms (PUSHF/PUSHFD) and use the current setting of the operand-size attribute to determine the size of values to be pushed from the stack, regardless of the mnemonic used.

In 64-bit mode, the instruction's default operation is to decrement the stack pointer (RSP) by 8 and pushes RFLAGS on the stack. 16-bit operation is supported using the operand size override prefix 66H. 32-bit operand size cannot be encoded in this mode. When copying RFLAGS to the stack, the VM and RF flags (bits 16 and 17) are not copied; instead, values for these flags are cleared in the RFLAGS image stored on the stack.

When in virtual-8086 mode and the I/O privilege level (IOPL) is less than 3, the PUSHF/PUSHFD instruction causes a general protection exception (#GP).

In the real-address mode, if the ESP or SP register is 1 when PUSHF/PUSHFD instruction executes: an #SS excep-tion is generated but not delivered (the stack error reported prevents #SS delivery). Next, the processor generates a #DF exception and enters a shutdown state as described in the #DF discussion in Chapter 6 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.


### Operation

```info-verb
IF (PE = 0) or (PE = 1 and ((VM = 0) or (VM = 1 and IOPL = 3)))
(\htmlonly{*} Real-Address Mode, Protected mode, or Virtual-8086 mode with IOPL equal to 3 \htmlonly{*})
 THEN
   IF OperandSize = 32
    THEN 
      push (EFLAGS AND 00FCFFFFH);
      (\htmlonly{*} VM and RF EFLAG bits are cleared in image stored on the stack \htmlonly{*})
    ELSE 
      push (EFLAGS); (\htmlonly{*} Lower 16 bits only \htmlonly{*})
   FI;
 ELSE IF 64-bit MODE (\htmlonly{*} In 64-bit Mode \htmlonly{*})
   IF OperandSize = 64
THEN 
      push (RFLAGS AND 00000000_00FCFFFFH);
      (* VM and RF RFLAG bits are cleared in image stored on the stack; *)
    ELSE 
      push (EFLAGS); (* Lower 16 bits only *)
   FI;
 ELSE (* In Virtual-8086 Mode with IOPL less than 3 *)
   #GP(0); (* Trap to virtual-8086 monitor *)
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #SS(0)
* If the new value of the ESP register is outside the stack segment boundary. 

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If the I/O privilege level is less than 3.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.
