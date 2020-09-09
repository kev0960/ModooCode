----------------------------
title : CLTS (Intel x86/64 assembly instruction)
cat_title : CLTS
ref_title : CLTS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CLTS

**Clear Task-Switched Flag in CR0**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 06|CLTS|NP|Valid|Valid|Clears TS flag in CR0.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Clears the task-switched (TS) flag in the CR0 register. This instruction is intended for use in operating-system procedures. It is a privileged instruction that can only be executed at a CPL of 0. It is allowed to be executed in real-address mode to allow initialization for protected mode.

The processor sets the TS flag every time a task switch occurs. The flag is used to synchronize the saving of FPU context in multitasking applications. See the description of the TS flag in the section titled "Control Registers" in Chapter 2 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A, for more information about this flag. 

CLTS operation is the same in non-64-bit modes and 64-bit mode.

See Chapter 25, "VMX Non-Root Operation," of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3C, for more information about the behavior of this instruction in VMX non-root operation.


### Operation

```info-verb
CR0.TS[bit 3] <- 0;
```
### Flags Affected


The TS flag in CR0 register is cleared.


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* CLTS is not recognized in virtual-8086 mode.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the CPL is greater than 0.

#### #UD
* If the LOCK prefix is used.
