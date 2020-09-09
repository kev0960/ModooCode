----------------------------
title : RSM (Intel x86/64 assembly instruction)
cat_title : RSM
ref_title : RSM
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RSM

**Resume from System Management Mode**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F AA|RSM|NP|Valid|Valid|Resume operation of interrupted program.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Returns program control from system management mode (SMM) to the application program or operating-system procedure that was interrupted when the processor received an SMM interrupt. The processor's state is restored from the dump created upon entering SMM. If the processor detects invalid state information during state restora-tion, it enters the shutdown state. The following invalid information can cause a shutdown:

*  Any reserved bit of CR4 is set to 1.

*  Any illegal combination of bits in CR0, such as (PG=1 and PE=0) or (NW=1 and CD=0).

*  (Intel Pentium and Intel486(tm) processors only.) The value stored in the state dump base field is not a 32-KByte aligned address.

The contents of the model-specific registers are not affected by a return from SMM.

The SMM state map used by `RSM` supports resuming processor context for non-64-bit modes and 64-bit mode. 

See Chapter 34, "System Management Mode," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3C, for more information about SMM and the behavior of the `RSM` instruction.


### Operation

```info-verb
ReturnFromSMM;
IF (IA-32e mode supported) or (CPUID DisplayFamily_DisplayModel = 06H_0CH )
    THEN
          ProcessorState <- Restore(SMMDump(IA-32e SMM STATE MAP));
    Else
          ProcessorState <- Restore(SMMDump(Non-32-Bit-Mode SMM STATE MAP));
FI
```
### Flags Affected


All.


### Protected Mode Exceptions

#### #UD
* If an attempt is made to execute this instruction when the processor is not in SMM.
* If the LOCK prefix is used.

### Real-Address Mode Exceptions



Same exceptions as in protected mode.


### Virtual-8086 Mode Exceptions



Same exceptions as in protected mode.


### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Same exceptions as in protected mode.

