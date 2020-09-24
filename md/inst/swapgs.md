----------------------------
title : SWAPGS (Intel x86/64 assembly instruction)
cat_title : SWAPGS
ref_title : SWAPGS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SWAPGS

**Swap GS Base Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 01 F8|`SWAPGS` |NP|Valid|Invalid|Exchanges the current GS base register value with the value contained in MSR address C0000102H.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


SWAPGS exchanges the current GS base register value with the value contained in MSR address C0000102H (IA32\esc{_}KERNEL\esc{_}GS\esc{_}BASE). The `SWAPGS` instruction is a privileged instruction intended for use by system soft-ware. 

When using `SYSCALL` to implement system calls, there is no kernel stack at the OS entry point. Neither is there a straightforward method to obtain a pointer to kernel structures from which the kernel stack pointer could be read. Thus, the kernel cannot save general purpose registers or reference memory. 

By design, `SWAPGS` does not require any general purpose registers or memory operands. No registers need to be saved before using the instruction. `SWAPGS` exchanges the CPL 0 data pointer from the IA32\esc{_}KERNEL\esc{_}GS\esc{_}BASE MSR with the GS base register. The kernel can then use the GS prefix on normal memory references to access kernel data structures. Similarly, when the OS kernel is entered using an interrupt or exception (where the kernel stack is already set up), `SWAPGS` can be used to quickly get a pointer to the kernel data structures.

The IA32\esc{_}KERNEL\esc{_}GS\esc{_}BASE MSR itself is only accessible using RDMSR/WRMSR instructions. Those instructions are only accessible at privilege level 0. The `WRMSR` instruction ensures that the IA32\esc{_}KERNEL\esc{_}GS\esc{_}BASE MSR contains a canonical address.


### Operation

```info-verb
IF CS.L != 1 (* Not in 64-Bit Mode *)
    THEN
          #UD; FI;
IF CPL != 0
    THEN #GP(0); FI;
tmp <- GS.base;
GS.base <- IA32_KERNEL_GS_BASE;
IA32_KERNEL_GS_BASE <- tmp;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #UD
* If Mode != 64-Bit.

### Real-Address Mode Exceptions

#### #UD
* If Mode != 64-Bit.

### Virtual-8086 Mode Exceptions

#### #UD
* If Mode != 64-Bit.

### Compatibility Mode Exceptions

#### #UD
* If Mode != 64-Bit.

### 64-Bit Mode Exceptions

#### #GP(0)
* If CPL != 0.
* If the LOCK prefix is used.
