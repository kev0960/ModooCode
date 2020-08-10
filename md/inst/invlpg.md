### INVLPG--Invalidate TLB Entries


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 01/7|INVLPG m|M|Valid|Valid|Invalidate TLB entries for page containing m.|
### NOTES:


*See the IA-32 Architecture Compatibility section below.

### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Invalidates any translation lookaside buffer (TLB) entries specified with the source operand. The source operand is a memory address. The processor determines the page that contains that address and flushes all TLB entries for that page.\footnote{1}

The INVLPG instruction is a privileged instruction. When the processor is running in protected mode, the CPL must be 0 to execute this instruction.

The INVLPG instruction normally flushes TLB entries only for the specified page; however, in some cases, it may flush more entries, even the entire TLB. The instruction is guaranteed to invalidates only TLB entries associated with the current PCID. (If PCIDs are disabled-- CR4.PCIDE= 0-- the current PCID is 000H.) The instruction also invalidates any global TLB entries for the specified page, regardless of PCID.

For more details on operations that flush the TLB, see "MOV--Move to/from Control Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2B and Section 4.10.4.1, "Operations that Invalidate TLBs and Paging-Structure Caches," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

This instruction's operation is the same in all non-64-bit modes. It also operates the same in 64-bit mode, except if the memory address is in non-canonical form. In this case, INVLPG is the same as a NOP.

### IA-32 Architecture Compatibility


The INVLPG instruction is implementation dependent, and its function may be implemented differently on different families of Intel 64 or IA-32 processors. This instruction is not supported on IA-32 processors earlier than the Intel486 processor.


### Operation

```info-verb
Invalidate(RelevantTLBEntries);
Continue; (\htmlonly{*} Continue execution \htmlonly{*})
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.

#### #UD
* Operand is a register.
* If the LOCK prefix is used.
* 1.If the paging structures map the linear address using a page larger than 4 KBytes and there are multiple TLB entries for that page (see Section 4.10.2.3, "Details of TLB Use," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A), the instruction invalidates all of them.

### Real-Address Mode Exceptions

#### #UD
* Operand is a register.
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* The INVLPG instruction cannot be executed at the virtual-8086 mode.

### 64-Bit Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.

#### #UD
* Operand is a register.
* If the LOCK prefix is used.
