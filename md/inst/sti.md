----------------------------
title : STI (Intel x86/64 assembly instruction)
cat_title : STI
ref_title : STI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ STI

**Set Interrupt Flag**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FB|`STI` |NP|Valid|Valid|Set interrupt flag; external, maskable interrupts enabled at the end of the next instruction.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


If protected-mode virtual interrupts are not enabled, `STI` sets the interrupt flag (IF) in the EFLAGS register. After the IF flag is set, the processor begins responding to external, maskable interrupts after the next instruction is executed. The delayed effect of this instruction is provided to allow interrupts to be enabled just before returning from a procedure (or subroutine). For instance, if an `STI` instruction is followed by an `RET` instruction, the `RET` instruction is allowed to execute before external interrupts are recognized\footnote{1} . If the `STI` instruction is followed by a `CLI` instruction (which clears the IF flag), the effect of the `STI` instruction is negated. 

The IF flag and the `STI` and `CLI` instructions do not prohibit the generation of exceptions and NMI interrupts. NMI interrupts (and SMIs) may be blocked for one macroinstruction following an `STI`.

When protected-mode virtual interrupts are enabled, CPL is 3, and IOPL is less than 3; `STI` sets the VIF flag in the EFLAGS register, leaving IF unaffected.

Table 4-19 indicates the action of the `STI` instruction depending on the processor's mode of operation and the CPL/IOPL settings of the running program or procedure.

Operation is the same in all modes.

### Table 4-19.  Decision Table for STI Results 


|**CR0.PE**|**EFLAGS.VM**|**EFLAGS.IOPL**|**CS.CPL**|**CR4.PVI**|**EFLAGS.VIP**|**CR4.VME**|**STI Result**|
|----------|-------------|---------------|----------|-----------|--------------|-----------|--------------|
|0|X|X|X|X|X|X|**IF** = **1**|
|1|0|>= CPL|X|X|X|X|**IF **= **1**|
|1|0|< CPL|3|1|X|X|**VIF **=** 1**|
|1|0|< CPL|< 3|X|X|X|**GP Fault**|
|1|0|< CPL|X|0|X|X|**GP Fault**|
|1|0|< CPL|X|X|1|X|**GP Fault**|
|1|1|3|X|X|X|X|**IF** = **1**|
|1|1|< 3|X|X|0|1|**VIF = 1**|
|1|1|< 3|X|X|1|X|**GP Fault**|
|1|1|< 3|X|X|X|0|**GP Fault**|

```note
X = This setting has no impact
```
```sidenote


1. The STI instruction delays recognition of interrupts only if it is executed with EFLAGS.IF = 0. In a sequence of STI instructions, only the first instruction in the sequence is guaranteed to delay interrupts.

    In the following instruction sequence, interrupts may be recognized before RET executes:STISTIRET
```
### Operation

```info-verb
IF PE = 0  (* Executing in real-address mode *)
    THEN 
          IF <- 1; (* Set Interrupt Flag *)
    ELSE  (* Executing in protected mode or virtual-8086 mode *)
          IF VM = 0  (* Executing in protected mode*)
                THEN
                      IF IOPL >= CPL
                            THEN
                                  IF <- 1;  (* Set Interrupt Flag *)
                      ELSE
                            IF (IOPL < CPL) and (CPL = 3) and (PVI = 1)
                                  THEN 
                                        VIF <- 1;  (* Set Virtual Interrupt Flag *)
                                  ELSE 
                                        #GP(0);
                            FI;
                      FI;
                ELSE  (* Executing in Virtual-8086 mode *)
                      IF IOPL = 3
                            THEN
                                  IF <- 1;  (* Set Interrupt Flag *)
                      ELSE 
                            IF ((IOPL < 3) and (VIP = 0) and (VME = 1))
                                  THEN
                                        VIF <- 1;  (* Set Virtual Interrupt Flag *)
                            ELSE
                                  #GP(0); (* Trap to virtual-8086 monitor *)
                            FI;)
                      FI;
          FI; 
FI;
```
### Flags Affected


The IF flag is set to 1; or the VIF flag is set to 1. Other flags are unaffected.


### Protected Mode Exceptions

#### #GP(0)
* If the CPL is greater (has less privilege) than the IOPL of the current program or procedure. 

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

