----------------------------
title : CLI (Intel x86/64 assembly instruction)
cat_title : CLI
ref_title : CLI
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CLI

** Clear Interrupt Flag**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|FA|CLI|NP|Valid|Valid|Clear interrupt flag; interrupts disabled when interrupt flag cleared.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


If protected-mode virtual interrupts are not enabled, `CLI` clears the IF flag in the EFLAGS register. No other flags are affected. Clearing the IF flag causes the processor to ignore maskable external interrupts. The IF flag and the `CLI` and `STI` instruction have no affect on the generation of exceptions and NMI interrupts.

When protected-mode virtual interrupts are enabled, CPL is 3, and IOPL is less than 3; `CLI` clears the VIF flag in the EFLAGS register, leaving IF unaffected. Table 3-7 indicates the action of the `CLI` instruction depending on the processor operating mode and the CPL/IOPL of the running program or procedure. 

Operation is the same in all modes.

### Table 3-7.  Decision Table for CLI Results


|**PE**|**VM**|**IOPL**|**CPL**|**PVI**|**VIP**|**VME**|**CLI Result**|
|------|------|--------|-------|-------|-------|-------|--------------|
|0|X|X|X|X|X|X|**IF** = **0**|
|1|0|>= CPL|X|X|X|X|**IF **= **0**|
|1|0|< CPL|3|1|X|X|**VIF **=** 0**|
|1|0|< CPL|< 3|X|X|X|**GP Fault**|
|1|0|< CPL|X|0|X|X|**GP Fault**|
|1|1|3|X|X|X|X|**IF **=** 0**|
|1|1|< 3|X|X|X|1|**VIF** = **0**|
|1|1|< 3|X|X|X|0|**GP Fault**|

```note
\htmlonly{*} X = This setting has no impact
```

### Operation

```info-verb
IF PE = 0
    THEN
          IF <- 0; (* Reset Interrupt Flag *)
    ELSE
          IF VM = 0;
                THEN
                      IF IOPL >= CPL
                            THEN
                                  IF <- 0; (* Reset Interrupt Flag *)
                      ELSE
                            IF ((IOPL < CPL) and (CPL = 3) and (PVI = 1))
                                  THEN
                                        VIF <- 0; (* Reset Virtual Interrupt Flag *)
                                  ELSE
                                        #GP(0);
FI;
                      FI;
                ELSE (* VM = 1 *)
                      IF IOPL = 3
                            THEN
                                  IF <- 0; (* Reset Interrupt Flag *)
                            ELSE 
                                  IF (IOPL < 3) AND (VME = 1)
                                        THEN
                                              VIF <- 0; (* Reset Virtual Interrupt Flag *)
                                        ELSE
                                              #GP(0);
                                  FI;
                      FI;
          FI;
FI;
```
### Flags Affected


If protected-mode virtual interrupts are not enabled, IF is set to 0 if the CPL is equal to or less than the IOPL; other-wise, it is not affected. Other flags are unaffected.

When protected-mode virtual interrupts are enabled, CPL is 3, and IOPL is less than 3; CLI clears the VIF flag in the EFLAGS register, leaving IF unaffected. Other flags are unaffected.


### Protected Mode Exceptions

#### #GP(0)
* If the CPL is greater (has less privilege) than the IOPL of the current program or procedure. 

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If the CPL is greater (has less privilege) than the IOPL of the current program or procedure. 

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the CPL is greater (has less privilege) than the IOPL of the current program or procedure. 

#### #UD
* If the LOCK prefix is used.
