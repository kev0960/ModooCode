----------------------------
title : RDPMC (Intel x86/64 assembly instruction)
cat_title : RDPMC
ref_title : RDPMC
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RDPMC

**Read Performance-Monitoring Counters**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 33|`RDPMC` |NP|Valid |Valid|Read performance-monitoring counter specified by ECX into EDX:EAX.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


The EAX register is loaded with the low-order 32 bits. The EDX register is loaded with the supported high-order bits of the counter. The number of high-order bits loaded into EDX is implementation specific on processors that do no support architectural performance monitoring. The width of fixed-function and general-purpose performance coun-ters on processors supporting architectural performance monitoring are reported by `CPUID` 0AH leaf. See below for the treatment of the EDX register for "fast" reads.

The ECX register specifies the counter type (if the processor supports architectural performance monitoring) and counter index. Counter type is specified in ECX[30] to select one of two type of performance counters. If the processor does not support architectural performance monitoring, ECX[30:0] specifies the counter index; other-wise ECX[29:0] specifies the index relative to the base of each counter type. ECX[31] selects "fast" read mode if supported. The two counter types are: 

*  General-purpose or special-purpose performance counters are specified with ECX[30] = 0: The number of general-purpose performance counters on processor supporting architectural performance monitoring are reported by `CPUID` 0AH leaf. The number of general-purpose counters is model specific if the processor does not support architectural performance monitoring, see Chapter 18, "Performance Monitoring" of Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B. Special-purpose counters are available only in selected processor members, see Table 4-16.

*  Fixed-function performance counter are specified with ECX[30] = 1. The number fixed-function performance counters is enumerated by `CPUID` 0AH leaf. See Chapter 30 of Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B. This counter type is selected if ECX[30] is set.

The width of fixed-function performance counters and general-purpose performance counters on processor supporting architectural performance monitoring are reported by `CPUID` 0AH leaf. The width of general-purpose performance counters are 40-bits for processors that do not support architectural performance monitoring coun-ters. The width of special-purpose performance counters are implementation specific. 

Table 4-16 lists valid indices of the general-purpose and special-purpose performance counters according to the DisplayFamily\esc{_}DisplayModel values of `CPUID` encoding for each processor family (see `CPUID` instruction in Chapter 3, "Instruction Set Reference, A-L" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A). 

### Table 4-16.  Valid General and Special Purpose Performance Counter Index Range for RDPMC


|**Processor Family**|**DisplayFamily_DisplayModel/ **\newline{}**Other Signatures**|**Valid PMC Index **\newline{}**Range**|**General-purpose **\newline{}**Counters**|
|--------------------|--------------------------------------------------------------|---------------------------------------|------------------------------------------|
|P6|06H_01H, 06H_03H, 06H_05H, 06H_06H, 06H_07H, 06H_08H, 06H_0AH, 06H_0BH|0, 1|0, 1|
|Processors Based on Intel NetBurst microarchitecture (No L3)|0FH_00H, 0FH_01H, 0FH_02H, 0FH_03H, 0FH_04H, 0FH_06H|>= 0 and <= 17|>= 0 and <= 17|
|Pentium M processors|06H_09H, 06H_0DH|0, 1|0, 1|
|Processors Based on Intel NetBurst microarchitecture (No L3)|0FH_03H, 0FH_04H) and (L3 is present)|>= 0 and <= 25|>= 0 and <= 17|
###           Table 4-16.  Valid General and Special Purpose Performance Counter Index Range for RDPMC (Contd.)


Processors based on Intel NetBurst microarchitecture support "fast" (32-bit) and "slow" (40-bit) reads on the first 18 performance counters. Selected this option using ECX[31]. If bit 31 is set, RDPMC reads only the low 32 bits of the selected performance counter. If bit 31 is clear, all 40 bits are read. A 32-bit result is returned in EAX and EDX is set to 0. A 32-bit read executes faster on these processors than a full 40-bit read.

On processors based on Intel NetBurst microarchitecture with L3, performance counters with indices 18-25 are 32-bit counters. EDX is cleared after executing RDPMC for these counters. 

In Intel Core 2 processor family, Intel Xeon processor 3000, 5100, 5300 and 7400 series, the fixed-function perfor-mance counters are 40-bits wide; they can be accessed by RDMPC with ECX between from 4000_0000H and 4000_0002H.

On Intel Xeon processor 7400 series, there are eight 32-bit special-purpose counters addressable with indices 2-9, ECX[30]=0. 

When in protected or virtual 8086 mode, the performance-monitoring counters enabled (PCE) flag in register CR4 restricts the use of the RDPMC instruction as follows. When the PCE flag is set, the RDPMC instruction can be executed at any privilege level; when the flag is clear, the instruction can only be executed at privilege level 0. (When in real-address mode, the RDPMC instruction is always enabled.)

The performance-monitoring counters can also be read with the RDMSR instruction, when executing at privilege level 0.

The performance-monitoring counters are event counters that can be programmed to count events such as the number of instructions decoded, number of interrupts received, or number of cache loads. Chapter 19, "Perfor-mance Monitoring Events," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3B, lists the events that can be counted for various processors in the Intel 64 and IA-32 architecture families.

The RDPMC instruction is not a serializing instruction; that is, it does not imply that all the events caused by the preceding instructions have been completed or that events caused by subsequent instructions have not begun. If 



|**Processor Family**|**DisplayFamily_DisplayModel/ **\newline{}**Other Signatures**|**Valid PMC Index **\newline{}**Range**|**General-purpose **\newline{}**Counters**|
|--------------------|--------------------------------------------------------------|---------------------------------------|------------------------------------------|
|Intel\footnote{(R)}  Core(tm) Solo and Intel\footnote{(R)}  Core(tm) Duo processors, Dual-core Intel\footnote{(R)}  Xeon\footnote{(R)}  processor LV|06H_0EH|0, 1|0, 1|
|Intel\footnote{(R)}  Core(tm)2 Duo processor, Intel Xeon processor 3000, 5100, 5300, 7300 Series - general-purpose PMC|06H_0FH|0, 1|0, 1|
|Intel\footnote{(R)}  Core(tm)2 Duo processor family, Intel Xeon processor 3100, 3300, 5200, 5400 series - general-purpose PMC|06H_17H|0, 1|0, 1|
|Intel Xeon processors 7400 series |(06H_1DH) |>= 0 and <= 9|0, 1|
|45 nm and 32 nm Intel\footnote{(R)}  Atom(tm) processors|06H_1CH, 06_26H, 06_27H, 06_35H, 06_36H|0, 1|0, 1|
|Intel\footnote{(R)}  Atom(tm) processors based on Silvermont or Airmont microarchitectures|06H_37H, 06_4AH, 06_4DH, 06_5AH, 06_5DH, 06_4CH|0, 1|0, 1|
|Next Generation Intel\footnote{(R)}  Atom(tm) processors based on Goldmont microarchitecture|06H_5CH, 06_5FH |0-3|0-3|
|Intel\footnote{(R)}  processors based on the Nehalem, Westmere microarchitectures|06H_1AH, 06H_1EH, 06H_1FH, 06_25H, 06_2CH, 06H_2EH, 06_2FH|0-3 |0-3 |
|Intel\footnote{(R)}  processors based on the Sandy Bridge, Ivy Bridge microarchitecture|06H_2AH, 06H_2DH, 06H_3AH, 06H_3EH|0-3 (0-7 if HyperThreading is off)|0-3 (0-7 if HyperThreading is off)|
|Intel\footnote{(R)}  processors based on the Haswell, Broadwell, SkyLake microarchitectures|06H_3CH, 06H_45H, 06H_46H, 06H_3FH, 06_3DH, 06_47H, 4FH, 06_56H, 06_4EH, 06_5EH|0-3 (0-7 if HyperThreading is off)|0-3 (0-7 if HyperThreading is off)|


an exact event count is desired, software must insert a serializing instruction (such as the CPUID instruction) before and/or after the RDPMC instruction.

Performing back-to-back fast reads are not guaranteed to be monotonic. To guarantee monotonicity on back-to-back reads, a serializing instruction must be placed between the two RDPMC instructions.

The RDPMC instruction can execute in 16-bit addressing mode or virtual-8086 mode; however, the full contents of the ECX register are used to select the counter, and the event count is stored in the full EAX and EDX registers. The RDPMC instruction was introduced into the IA-32 Architecture in the Pentium Pro processor and the Pentium processor with MMX technology. The earlier Pentium processors have performance-monitoring counters, but they must be read with the RDMSR instruction.


### Operation

```info-verb
(* Intel processors that support architectural performance monitoring *)
Most significant counter bit (MSCB) = 47
IF ((CR4.PCE = 1) or (CPL = 0) or (CR0.PE = 0))
    THEN IF (ECX[30] = 1 and ECX[29:0] in valid fixed-counter range)
          EAX <- IA32_FIXED_CTR(ECX)[30:0];
          EDX <- IA32_FIXED_CTR(ECX)[MSCB:32];
    ELSE IF (ECX[30] = 0 and ECX[29:0] in valid general-purpose counter range)
          EAX <- PMC(ECX[30:0])[31:0];
          EDX <- PMC(ECX[30:0])[MSCB:32];
    ELSE (* ECX is not valid or CR4.PCE is 0 and CPL is 1, 2, or 3 and CR0.PE is 1 *)
          #GP(0); 
FI;
(* Intel Core 2 Duo processor family and Intel Xeon processor 3000, 5100, 5300, 7400 series*)
Most significant counter bit (MSCB) = 39
IF ((CR4.PCE = 1) or (CPL = 0) or (CR0.PE = 0))
    THEN IF (ECX[30] = 1 and ECX[29:0] in valid fixed-counter range)
          EAX <- IA32_FIXED_CTR(ECX)[30:0];
          EDX <- IA32_FIXED_CTR(ECX)[MSCB:32];
    ELSE IF (ECX[30] = 0 and ECX[29:0] in valid general-purpose counter range)
          EAX <- PMC(ECX[30:0])[31:0];
          EDX <- PMC(ECX[30:0])[MSCB:32];
    ELSE IF (ECX[30] = 0 and ECX[29:0] in valid special-purpose counter range)
          EAX <- PMC(ECX[30:0])[31:0]; (* 32-bit read *)
    ELSE (* ECX is not valid or CR4.PCE is 0 and CPL is 1, 2, or 3 and CR0.PE is 1 *)
          #GP(0); 
FI;
(* P6 family processors and Pentium processor with MMX technology *)
IF (ECX = 0 or 1) and ((CR4.PCE = 1) or (CPL = 0) or (CR0.PE = 0))
    THEN 
          EAX <- PMC(ECX)[31:0];
          EDX <- PMC(ECX)[39:32];
    ELSE (* ECX is not 0 or 1 or CR4.PCE is 0 and CPL is 1, 2, or 3 and CR0.PE is 1 *)
          #GP(0); 
FI;
(* Processors based on Intel NetBurst microarchitecture *)
IF ((CR4.PCE = 1) or (CPL = 0) or (CR0.PE = 0))
    THEN IF (ECX[30:0] = 0:17)
          THEN IF ECX[31] = 0
THEN
                      EAX <- PMC(ECX[30:0])[31:0]; (* 40-bit read *)
                      EDX <- PMC(ECX[30:0])[39:32];
          ELSE (* ECX[31] = 1*)
                THEN
                      EAX <- PMC(ECX[30:0])[31:0]; (* 32-bit read *)
                      EDX <- 0;
          FI;
    ELSE IF (*64-bit Intel processor based on Intel NetBurst microarchitecture with L3 *)
          THEN IF (ECX[30:0] = 18:25 )
                EAX <- PMC(ECX[30:0])[31:0]; (* 32-bit read *)
                EDX <- 0;
          FI;
    ELSE (* Invalid PMC index in ECX[30:0], see Table 4-19. *)
          GP(0); 
    FI;
ELSE (* CR4.PCE = 0 and (CPL = 1, 2, or 3) and CR0.PE = 1 *)
    #GP(0); 
FI; 
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0 and the PCE flag in the CR4 register is clear.
* If an invalid performance counter index is specified (see Table 4-16).

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If an invalid performance counter index is specified (see Table 4-16).

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If the PCE flag in the CR4 register is clear.
* If an invalid performance counter index is specified (see Table 4-16).

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0 and the PCE flag in the CR4 register is clear.
* If an invalid performance counter index is specified (see Table 4-16).

#### #UD
* If the LOCK prefix is used.
