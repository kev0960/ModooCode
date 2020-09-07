----------------------------
title : SAHF (Intel x86/64 assembly instruction)
cat_title : SAHF
ref_title : SAHF
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------
#@ SAHF

**Store AH into Flags**

|**Opcode\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|9E|SAHF|NP|Invalid\htmlonly{*}|Valid|Loads SF, ZF, AF, PF, and CF from AH into EFLAGS register.|

```note
\htmlonly{*} Valid in specific steppings. See Description section
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Loads the SF, ZF, AF, PF, and CF flags of the EFLAGS register with values from the corresponding bits in the AH register (bits 7, 6, 4, 2, and 0, respectively). Bits 1, 3, and 5 of register AH are ignored; the corresponding reserved bits (1, 3, and 5) in the EFLAGS register remain as shown in the "Operation" section below.

This instruction executes as described above in compatibility mode and legacy mode. It is valid in 64-bit mode only if `CPUID`.80000001H:ECX.LAHF-SAHF[bit 0] = 1.


### Operation

```info-verb
IF IA-64 Mode
    THEN
          IF CPUID.80000001H.ECX[0] = 1;THENRFLAGS(SF:ZF:0:AF:0:PF:1:CF) <- AH;ELSE
                      #UD;
          FI
    ELSE
          EFLAGS(SF:ZF:0:AF:0:PF:1:CF) <- AH;
FI;
```
### Flags Affected


The SF, ZF, AF, PF, and CF flags are loaded with values from the AH register. Bits 1, 3, and 5 of the EFLAGS register are unaffected, with the values remaining 1, 0, and 0, respectively.


### Protected Mode Exceptions



None.


### Real-Address Mode Exceptions



None.


### Virtual-8086 Mode Exceptions



None.


### Compatibility Mode Exceptions



None.


### 64-Bit Mode Exceptions

#### #UD
* If CPUID.80000001H.ECX[0] = 0.
* If the LOCK prefix is used.
