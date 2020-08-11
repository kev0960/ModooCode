----------------------------
title : CPUID instruction(Intel x86/64 assembly instruction)
cat_title : CPUID
----------------------------
### CPUID--CPU Identification


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F A2|CPUID|NP|Valid|Valid|Returns processor identification and feature information to the EAX, EBX, ECX, and EDX registers, as determined by input entered in EAX (in some cases, ECX as well).|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


The ID flag (bit 21) in the EFLAGS register indicates support for the CPUID instruction. If a software procedure can set and clear this flag, the processor executing the procedure supports the CPUID instruction. This instruction oper-ates the same in non-64-bit modes and 64-bit mode.

CPUID returns processor identification and feature information in the EAX, EBX, ECX, and EDX registers.\footnote{1}  The instruction's output is dependent on the contents of the EAX register upon execution (in some cases, ECX as well). For example, the following pseudocode loads EAX with 00H and causes CPUID to return a Maximum Return Value and the Vendor Identification String in the appropriate registers:

 MOV EAX, 00H

 CPUID

Table 3-8 shows information returned, depending on the initial value loaded into the EAX register. 

Two types of information are returned: basic and extended function information. If a value entered for CPUID.EAX is higher than the maximum input value for basic or extended function for that processor then the data for the highest basic information leaf is returned. For example, using the Intel Core i7 processor, the following is true:

 CPUID.EAX = 05H (* Returns MONITOR/MWAIT leaf. *) 

 CPUID.EAX = 0AH (* Returns Architectural Performance Monitoring leaf. *) 

 CPUID.EAX = 0BH (* Returns Extended Topology Enumeration leaf. *) 

 CPUID.EAX = 0CH (* INVALID: Returns the same information as CPUID.EAX = 0BH. *) 

 CPUID.EAX = 80000008H (* Returns linear/physical address size data. *)

 CPUID.EAX = 8000000AH (* INVALID: Returns same information as CPUID.EAX = 0BH. *)

If a value entered for CPUID.EAX is less than or equal to the maximum input value and the leaf is not supported on that processor then 0 is returned in all the registers.

When CPUID returns the highest basic leaf information as a result of an invalid input EAX value, any dependence on input ECX value in the basic leaf is honored.

CPUID can be executed at any privilege level to serialize instruction execution. Serializing instruction execution guarantees that any modifications to flags, registers, and memory for previous instructions are completed before the next instruction is fetched and executed.

See also: 

"Serializing Instructions" in Chapter 8, "Multiple-Processor Management," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

"Caching Translation Information" in Chapter 4, "Paging," in the Intel(R) 64 and IA-32 Architectures Software Devel-oper's Manual, Volume 3A.



1.On Intel 64 processors, CPUID clears the high 32 bits of the RAX/RBX/RCX/RDX registers in all modes.

### Table 3-8.  Information Returned by CPUID Instruction


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
|||
||Basic CPUID Information|
|0H|EAX Maximum Input Value for Basic CPUID Information.\newline{}EBX "Genu"\newline{}ECX "ntel"\newline{}EDX "ineI"|
|01H|EAX Version Information: Type, Family, Model, and Stepping ID (see Figure3-6).\newline{}EBX Bits 07 - 00: Brand Index.Bits 15 - 08: CLFLUSH line size (Value `*` 8 = cache line size in bytes; used also by CLFLUSHOPT).Bits 23 - 16: Maximum number of addressable IDs for logical processors in this physical package*. Bits 31 - 24: Initial APIC ID.\newline{}ECX Feature Information (see Figure3-7 and Table 3-10).\newline{}EDX Feature Information (see Figure3-8 and Table 3-11).\newline{}\newline{}###     NOTES: 
\newline{}\newline{}*The nearest power-of-2 integer that is not smaller than EBX[23:16] is the number of unique initial APICIDs reserved for addressing different logical processors in a physical package. This field is only valid ifCPUID.1.EDX.HTT[bit 28]= 1.|
|02H|EAX Cache and TLB Information (see Table 3-12).\newline{}EBX Cache and TLB Information.\newline{}ECX Cache and TLB Information.\newline{}EDX Cache and TLB Information.|
|03H|EAX Reserved.\newline{}EBX Reserved.\newline{}ECX Bits 00 - 31 of 96 bit processor serial number. (Available in Pentium III processor only; otherwise, the value in this register is reserved.)\newline{}EDX Bits 32 - 63 of 96 bit processor serial number. (Available in Pentium III processor only; otherwise, the value in this register is reserved.)\newline{}\newline{}###     NOTES: 
\newline{}\newline{}Processor serial number (PSN) is not supported in the Pentium 4 processor or later. On all models, usethe PSN flag (returned using CPUID) to check for PSN support before accessing the feature. |
|CPUID leaves a|bove 2 and below 80000000H are visible only when IA32_MISC_ENABLE[bit 22] has its default value of 0.|
||Deterministic Cache Parameters Leaf |
|04H|###     NOTES:
\newline{}\newline{}Leaf 04H output depends on the initial value in ECX.* \newline{}     See also: "INPUT EAX = 04H: Returns Deterministic Cache Parameters for Each Level" on page214.\newline{}EAX Bits 04 - 00: Cache Type Field.0 = Null - No more caches.1 = Data Cache. 2 = Instruction Cache.3 = Unified Cache.4-31 = Reserved.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Bits 07 - 05: Cache Level (starts at 1). Bit 08: Self Initializing cache level (does not need SW initialization).Bit 09: Fully Associative cache.\newline{}    Bits 13 - 10: Reserved.Bits 25 - 14: Maximum number of addressable IDs for logical processors sharing this cache**,***. Bits 31 - 26: Maximum number of addressable IDs for processor cores in the physical package**,****,*****.\newline{}EBX Bits 11 - 00: L = System Coherency Line Size**.Bits 21 - 12: P = Physical Line partitions**.Bits 31 - 22: W = Ways of associativity**.\newline{}ECX Bits 31-00: S = Number of Sets**.\newline{}EDX Bit 00: Write-Back Invalidate/Invalidate.0=WBINVD/INVD from threads sharing this cache acts upon lower level caches for threads sharing this cache.1=WBINVD/INVD is not guaranteed to act upon lower level caches of non-originating threads sharing this cache.Bit 01: Cache Inclusiveness.0=Cache is not inclusive of lower cache levels.1=Cache is inclusive of lower cache levels.Bit 02: Complex Cache Indexing.0=Direct mapped cache.1=A complex function is used to index the cache, potentially using all address bits.Bits 31 - 03: Reserved = 0.\newline{}\newline{}###     NOTES:
\newline{}\newline{}* If ECX contains an invalid sub leaf index, EAX/EBX/ECX/EDX return 0. Sub-leaf index n+1 is invalid if sub-leaf n returns EAX[4:0] as 0.\newline{}    **Add one to the return value to get the result. \newline{}    ***The nearest power-of-2 integer that is not smaller than (1 + EAX[25:14]) is the number of unique ini-tial APIC IDs reserved for addressing different logical processors sharing this cache.\newline{}    **** The nearest power-of-2 integer that is not smaller than (1 + EAX[31:26]) is the number of unique Core_IDs reserved for addressing different processor cores in a physical package. Core ID is a subset of bits of the initial APIC ID. \newline{}    ***** The returned value is constant for valid initial values in ECX. Valid ECX values start from 0. |
||MONITOR/MWAIT Leaf |
|05H|EAX Bits 15 - 00: Smallest monitor-line size in bytes (default is processor's monitor granularity). Bits 31 - 16: Reserved = 0.\newline{}EBX Bits 15 - 00: Largest monitor-line size in bytes (default is processor's monitor granularity). Bits 31 - 16: Reserved = 0.\newline{}ECX Bit 00: Enumeration of Monitor-Mwait extensions (beyond EAX and EBX registers) supported.\newline{}    Bit 01: Supports treating interrupts as break-event for MWAIT, even when interrupts disabled.\newline{}    Bits 31 - 02: Reserved. |
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||EDX Bits 03 - 00: Number of C0* sub C-states supported using MWAIT.Bits 07 - 04: Number of C1* sub C-states supported using MWAIT.Bits 11 - 08: Number of C2* sub C-states supported using MWAIT.Bits 15 - 12: Number of C3* sub C-states supported using MWAIT.Bits 19 - 16: Number of C4* sub C-states supported using MWAIT.Bits 23 - 20: Number of C5* sub C-states supported using MWAIT.Bits 27 - 24: Number of C6* sub C-states supported using MWAIT.Bits 31 - 28: Number of C7* sub C-states supported using MWAIT.\newline{}\newline{}###     NOTE:
\newline{}\newline{}* The definition of C0 through C7 states for MWAIT extension are processor-specific C-states, not ACPI C-states.|
||Thermal and Power Management Leaf |
|06H|EAX Bit 00: Digital temperature sensor is supported if set.Bit 01: Intel Turbo Boost Technology Available (see description of IA32_MISC_ENABLE[38]).Bit 02: ARAT. APIC-Timer-always-running feature is supported if set.Bit 03: Reserved.Bit 04: PLN. Power limit notification controls are supported if set.Bit 05: ECMD. Clock modulation duty cycle extension is supported if set.Bit 06: PTM. Package thermal management is supported if set.Bit 07: HWP. HWP base registers (IA32_PM_ENABLE[bit 0], IA32_HWP_CAPABILITIES, IA32_HWP_REQUEST, IA32_HWP_STATUS) are supported if set.Bit 08: HWP_Notification. IA32_HWP_INTERRUPT MSR is supported if set.Bit 09: HWP_Activity_Window. IA32_HWP_REQUEST[bits 41:32] is supported if set.Bit 10: HWP_Energy_Performance_Preference. IA32_HWP_REQUEST[bits 31:24] is supported if set.Bit 11: HWP_Package_Level_Request. IA32_HWP_REQUEST_PKG MSR is supported if set.Bit 12: Reserved.Bit 13: HDC. HDC base registers IA32_PKG_HDC_CTL, IA32_PM_CTL1, IA32_THREAD_STALL MSRs are supported if set.Bits 31 - 15: Reserved.\newline{}EBX Bits 03 - 00: Number of Interrupt Thresholds in Digital Thermal Sensor.Bits 31 - 04: Reserved. \newline{}ECX Bit 00: Hardware Coordination Feedback Capability (Presence of IA32_MPERF and IA32_APERF). The capability to provide a measure of delivered processor performance (since last reset of the counters), as a percentage of the expected processor performance when running at the TSC frequency.Bits 02 - 01: Reserved = 0.Bit 03: The processor supports performance-energy bias preference if CPUID.06H:ECX.SETBH[bit 3] is set and it also implies the presence of a new architectural MSR called IA32_ENERGY_PERF_BIAS (1B0H).Bits 31 - 04: Reserved = 0.\newline{}EDX Reserved = 0.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Structured Extended Feature Flags Enumeration Leaf (Output depends on ECX input value)|
|07H|Sub-leaf 0 (Input ECX = 0). *\newline{}EAX Bits 31 - 00: Reports the maximum input value for supported leaf 7 sub-leaves.\newline{}EBX Bit 00: FSGSBASE. Supports RDFSBASE/RDGSBASE/WRFSBASE/WRGSBASE if 1.Bit 01: IA32_TSC_ADJUST MSR is supported if 1.Bit 02: SGX. Supports Intel(R) Software Guard Extensions (Intel(R) SGX Extensions) if 1.Bit 03: BMI1.Bit 04: HLE.Bit 05: AVX2.Bit 06: FDP_EXCPTN_ONLY. x87 FPU Data Pointer updated only on x87 exceptions if 1.Bit 07: SMEP. Supports Supervisor-Mode Execution Prevention if 1.Bit 08: BMI2.Bit 09: Supports Enhanced REP MOVSB/STOSB if 1.Bit 10: INVPCID. If 1, supports INVPCID instruction for system software that manages process-context identifiers.Bit 11: RTM.Bit 12: RDT-M. Supports Intel(R) Resource Director Technology (Intel(R) RDT) Monitoring capability if 1.Bit 13: Deprecates FPU CS and FPU DS values if 1.Bit 14: MPX. Supports Intel(R) Memory Protection Extensions if 1.Bit 15: RDT-A. Supports Intel(R) Resource Director Technology (Intel(R) RDT) Allocation capability if 1.Bits 17:16: Reserved.Bit 18: RDSEED.Bit 19: ADX.Bit 20: SMAP. Supports Supervisor-Mode Access Prevention (and the CLAC/STAC instructions) if 1.Bits 22 - 21: Reserved.Bit 23: CLFLUSHOPT.Bit 24: CLWB.Bit 25: Intel Processor Trace.Bits 28 - 26: Reserved.Bit 29: SHA. supports Intel(R) Secure Hash Algorithm Extensions (Intel(R) SHA Extensions) if 1.Bits 31 - 30: Reserved.\newline{}ECX Bit 00: PREFETCHWT1.Bit 01: Reserved.Bit 02: UMIP. Supports user-mode instruction prevention if 1.Bit 03: PKU. Supports protection keys for user-mode pages if 1.Bit 04: OSPKE. If 1, OS has set CR4.PKE to enable protection keys (and the RDPKRU/WRPKRU instruc-tions).Bits 16 - 5: Reserved.Bits 21 - 17: The value of MAWAU used by the BNDLDX and BNDSTX instructions in 64-bit mode.Bit 22: RDPID. Supports Read Processor ID if 1.Bits 29 - 23: Reserved.Bit 30: SGX_LC. Supports SGX Launch Configuration if 1.Bit 31: Reserved. \newline{}EDX Reserved.\newline{}\newline{}###     NOTE:
\newline{}\newline{}* If ECX contains an invalid sub-leaf index, EAX/EBX/ECX/EDX return 0. Sub-leaf index n is invalid if n exceeds the value that sub-leaf 0 returns in EAX.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Direct Cache Access Information Leaf |
|09H|EAX Value of bits [31:0] of IA32_PLATFORM_DCA_CAP MSR (address 1F8H).\newline{}EBX Reserved. \newline{}ECX Reserved.\newline{}EDX Reserved. |
||Architectural Performance Monitoring Leaf |
|0AH|EAX Bits 07 - 00: Version ID of architectural performance monitoring.Bits 15 - 08: Number of general-purpose performance monitoring counter per logical processor.Bits 23 - 16: Bit width of general-purpose, performance monitoring counter.Bits 31 - 24: Length of EBX bit vector to enumerate architectural performance monitoring events.\newline{}EBX Bit 00: Core cycle event not available if 1.Bit 01: Instruction retired event not available if 1.Bit 02: Reference cycles event not available if 1.Bit 03: Last-level cache reference event not available if 1.Bit 04: Last-level cache misses event not available if 1.Bit 05: Branch instruction retired event not available if 1.Bit 06: Branch mispredict retired event not available if 1.Bits 31 - 07: Reserved = 0.\newline{}ECX Reserved = 0.\newline{}EDX Bits 04 - 00: Number of fixed-function performance counters (if Version ID > 1).Bits 12 - 05: Bit width of fixed-function performance counters (if Version ID > 1).Reserved = 0.|
||Extended Topology Enumeration Leaf |
|0BH|###     NOTES:
\newline{}\newline{}Most of Leaf 0BH output depends on the initial value in ECX. \newline{}     The EDX output of leaf 0BH is always valid and does not vary with input value in ECX.\newline{}     Output value in ECX[7:0] always equals input value in ECX[7:0].\newline{}     For sub-leaves that return an invalid level-type of 0 in ECX[15:8]; EAX and EBX will return 0.\newline{}      If an input value n in ECX returns the invalid level-type of 0 in ECX[15:8], other input values with ECX > n also return 0 in ECX[15:8].\newline{}EAX Bits 04 - 00: Number of bits to shift right on x2APIC ID to get a unique topology ID of the next level type*. All logical processors with the same next level ID share current level.Bits 31 - 05: Reserved.\newline{}EBX Bits 15 - 00: Number of logical processors at this level type. The number reflects configuration as shipped by Intel**.Bits 31- 16: Reserved.\newline{}ECX Bits 07 - 00: Level number. Same value in ECX input.Bits 15 - 08: Level type***.Bits 31 - 16: Reserved.\newline{}EDX Bits 31- 00: x2APIC ID the current logical processor.\newline{}\newline{}###     NOTES:
\newline{}\newline{}* Software should use this field (EAX[4:0]) to enumerate processor topology of the system.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||** Software must not use EBX[15:0] to enumerate processor topology of the system. This value in this field (EBX[15:0]) is only intended for display/diagnostic purposes. The actual number of logical processors available to BIOS/OS/Applications may be different from the value of EBX[15:0], depending on software and platform hardware configurations. \newline{}*** The value of the "level type" field is not related to level numbers in any way, higher "level type" val-ues do not mean higher levels. Level type field has the following encoding:0: Invalid.1: SMT.2: Core.3-255: Reserved.|
||Processor Extended State Enumeration Main Leaf (EAX = 0DH, ECX = 0)|
|0DH|###     NOTES:
\newline{}\newline{}Leaf 0DH main leaf (ECX = 0). \newline{}EAX Bits 31 - 00: Reports the supported bits of the lower 32 bits of XCR0. XCR0[n] can be set to 1 only if EAX[n] is 1.Bit 00: x87 state. Bit 01: SSE state.Bit 02: AVX state.Bits 04 - 03: MPX state.Bits 07 - 05: AVX-512 state.Bit 08: Used for IA32_XSS.Bit 09: PKRU state.Bits 31 - 10: Reserved.\newline{}EBX Bits 31 - 00: Maximum size (bytes, from the beginning of the XSAVE/XRSTOR save area) required by enabled features in XCR0. May be different than ECX if some features at the end of the XSAVE save area are not enabled.\newline{}ECX Bit 31 - 00: Maximum size (bytes, from the beginning of the XSAVE/XRSTOR save area) of the XSAVE/XRSTOR save area required by all supported features in the processor, i.e., all the valid bit fields in XCR0. \newline{}EDX Bit 31 - 00: Reports the supported bits of the upper 32 bits of XCR0. XCR0[n+32] can be set to 1 only if EDX[n] is 1.Bits 31 - 00: Reserved.|
||Processor Extended State Enumeration Sub-leaf (EAX = 0DH, ECX = 1)|
|0DH|EAX Bit 00: XSAVEOPT is available.Bit 01: Supports XSAVEC and the compacted form of XRSTOR if set.Bit 02: Supports XGETBV with ECX = 1 if set.Bit 03: Supports XSAVES/XRSTORS and IA32_XSS if set.Bits 31 - 04: Reserved.\newline{}EBX Bits 31 - 00: The size in bytes of the XSAVE area containing all states enabled by XCRO | IA32_XSS.\newline{}ECX Bits 31 - 00: Reports the supported bits of the lower 32 bits of the IA32_XSS MSR. IA32_XSS[n] can be set to 1 only if ECX[n] is 1.Bits 07 - 00: Used for XCR0.Bit 08: PT state.Bit 09: Used for XCR0.Bits 31 - 10: Reserved.\newline{}EDX  Bits 31 - 00: Reports the supported bits of the upper 32 bits of the IA32_XSS MSR. IA32_XSS[n+32] can be set to 1 only if EDX[n] is 1.Bits 31 - 00: Reserved.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Processor Extended State Enumeration Sub-leaves (EAX = 0DH, ECX = n, n > 1)|
|0DH|###     NOTES:
\newline{}\newline{}Leaf 0DH output depends on the initial value in ECX. \newline{}     Each sub-leaf index (starting at position 2) is supported if it corresponds to a supported bit in either the XCR0 register or the IA32_XSS MSR.\newline{}     * If ECX contains an invalid sub-leaf index, EAX/EBX/ECX/EDX return 0. Sub-leaf n (0  " n  " 31) is invalid if sub-leaf 0 returns 0 in EAX[n] and sub-leaf 1 returns 0 in ECX[n]. Sub-leaf n (32 "  n "  63) is invalid if sub-leaf 0 returns 0 in EDX[n-32] and sub-leaf 1 returns 0 in EDX[n-32].\newline{}EAX Bits 31 - 0: The size in bytes (from the offset specified in EBX) of the save area for an extended state feature associated with a valid sub-leaf index, n.\newline{}EBX Bits 31 - 0: The offset in bytes of this extended state component's save area from the beginning of the XSAVE/XRSTOR area.This field reports 0 if the sub-leaf index, n, does not map to a valid bit in the XCR0 register*.\newline{}ECX Bit 00 is set if the bit n (corresponding to the sub-leaf index) is supported in the IA32_XSS MSR; it is clear if bit n is instead supported in XCR0.Bit 01 is set if, when the compacted format of an XSAVE area is used, this extended state component located on the next 64-byte boundary following the preceding state component (otherwise, it is located immediately following the preceding state component).Bits 31 - 02 are reserved.This field reports 0 if the sub-leaf index, n, is invalid*.\newline{}EDX This field reports 0 if the sub-leaf index, n, is invalid*; otherwise it is reserved.|
||Intel Resource Director Technology (Intel RDT) Monitoring Enumeration Sub-leaf (EAX = 0FH, ECX = 0)|
|0FH|###     NOTES:
\newline{}\newline{}Leaf 0FH output depends on the initial value in ECX. \newline{}     Sub-leaf index 0 reports valid resource type starting at bit position 1 of EDX.\newline{}EAX Reserved.\newline{}EBX Bits 31 - 00: Maximum range (zero-based) of RMID within this physical processor of all types.\newline{}ECX Reserved.\newline{}EDX Bit 00: Reserved.Bit 01: Supports L3 Cache Intel RDT Monitoring if 1.Bits 31 - 02: Reserved.|
||L3 Cache Intel RDT Monitoring Capability Enumeration Sub-leaf (EAX = 0FH, ECX = 1)|
|0FH|###     NOTES:
\newline{}\newline{}Leaf 0FH output depends on the initial value in ECX. \newline{}EAX Reserved.\newline{}EBX Bits 31 - 00: Conversion factor from reported IA32_QM_CTR value to occupancy metric (bytes).\newline{}ECX Maximum range (zero-based) of RMID of this resource type.\newline{}EDX Bit 00: Supports L3 occupancy monitoring if 1.Bit 01: Supports L3 Total Bandwidth monitoring if 1.Bit 02: Supports L3 Local Bandwidth monitoring if 1.Bits 31 - 03: Reserved.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Intel Resource Director Technology (Intel RDT) Allocation Enumeration Sub-leaf (EAX = 10H, ECX = 0)|
|10H|###     NOTES:
\newline{}\newline{}Leaf 10H output depends on the initial value in ECX. \newline{}     Sub-leaf index 0 reports valid resource identification (ResID) starting at bit position 1 of EBX.\newline{}EAX Reserved.\newline{}EBX Bit 00: Reserved.Bit 01: Supports L3 Cache Allocation Technology if 1.Bit 02: Supports L2 Cache Allocation Technology if 1.Bits 31 - 03: Reserved.\newline{}ECX Reserved.\newline{}EDX Reserved.|
||L3 Cache Allocation Technology Enumeration Sub-leaf (EAX = 10H, ECX = ResID =1)|
|10H|###     NOTES:
\newline{}\newline{}Leaf 10H output depends on the initial value in ECX. \newline{}EAX Bits 4 - 00: Length of the capacity bit mask for the corresponding ResID using minus-one notation.Bits 31 - 05: Reserved.\newline{}EBX Bits 31 - 00: Bit-granular map of isolation/contention of allocation units.\newline{}ECX Bit 00: Reserved.Bit 01: Updates of COS should be infrequent if 1.Bit 02: Code and Data Prioritization Technology supported if 1.Bits 31 - 03: Reserved.\newline{}EDX Bits 15 - 00: Highest COS number supported for this ResID.Bits 31 - 16: Reserved.|
||L2 Cache Allocation Technology Enumeration Sub-leaf (EAX = 10H, ECX = ResID =2)|
|10H|###     NOTES:
\newline{}\newline{}Leaf 10H output depends on the initial value in ECX. \newline{}EAX Bits 4 - 00: Length of the capacity bit mask for the corresponding ResID using minus-one notation.Bits 31 - 05: Reserved.\newline{}EBX Bits 31 - 00: Bit-granular map of isolation/contention of allocation units.\newline{}ECX Bits 31 - 00: Reserved.\newline{}EDX Bits 15 - 00: Highest COS number supported for this ResID.Bits 31 - 16: Reserved.|
||Intel SGX Capability Enumeration Leaf, sub-leaf 0 (EAX = 12H, ECX = 0)|
|12H|###     NOTES:
\newline{}\newline{}Leaf 12H sub-leaf 0 (ECX = 0) is supported if CPUID.(EAX=07H, ECX=0H):EBX[SGX] = 1. \newline{}EAX Bit 00: SGX1. If 1, Indicates Intel SGX supports the collection of SGX1 leaf functions.Bit 01: SGX2. If 1, Indicates Intel SGX supports the collection of SGX2 leaf functions.Bit 31 - 02: Reserved. \newline{}EBX Bit 31 - 00: MISCSELECT. Bit vector of supported extended SGX features.\newline{}ECX Bit 31 - 00: Reserved.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||EDX Bit 07 - 00: MaxEnclaveSize_Not64. The maximum supported enclave size in non-64-bit mode is 2^(EDX[7:0]).Bit 15 - 08: MaxEnclaveSize_64. The maximum supported enclave size in 64-bit mode is 2^(EDX[15:8]).Bits 31 - 16: Reserved.|
||Intel SGX Attributes Enumeration Leaf, sub-leaf 1 (EAX = 12H, ECX = 1)|
|12H|###     NOTES:
\newline{}\newline{}Leaf 12H sub-leaf 1 (ECX = 1) is supported if CPUID.(EAX=07H, ECX=0H):EBX[SGX] = 1. \newline{}EAX Bit 31 - 00: Reports the valid bits of SECS.ATTRIBUTES[31:0] that software can set with ECREATE.\newline{}EBX Bit 31 - 00: Reports the valid bits of SECS.ATTRIBUTES[63:32] that software can set with ECREATE.\newline{}ECX Bit 31 - 00: Reports the valid bits of SECS.ATTRIBUTES[95:64] that software can set with ECREATE.\newline{}EDX Bit 31 - 00: Reports the valid bits of SECS.ATTRIBUTES[127:96] that software can set with ECREATE.|
||Intel SGX EPC Enumeration Leaf, sub-leaves (EAX = 12H, ECX = 2 or higher)|
|12H|###     NOTES:
\newline{}\newline{}Leaf 12H sub-leaf 2 or higher (ECX >= 2) is supported if CPUID.(EAX=07H, ECX=0H):EBX[SGX] = 1. \newline{}     For sub-leaves (ECX = 2 or higher), definition of EDX,ECX,EBX,EAX[31:4] depends on the sub-leaf typelisted below. \newline{}EAX Bit 03 - 00: Sub-leaf Type0000b: Indicates this sub-leaf is invalid. 0001b: This sub-leaf enumerates an EPC section. EBX:EAX and EDX:ECX provide information on the Enclave Page Cache (EPC) section.All other type encodings are reserved.\newline{}Type 0000b. This sub-leaf is invalid. \newline{}     EDX:ECX:EBX:EAX return 0.\newline{}Type 0001b. This sub-leaf enumerates an EPC sections with EDX:ECX, EBX:EAX defined as follows. \newline{}     EAX[11:04]: Reserved (enumerate 0). EAX[31:12]: Bits 31:12 of the physical address of the base of the EPC section. \newline{}     EBX[19:00]: Bits 51:32 of the physical address of the base of the EPC section. EBX[31:20]: Reserved.\newline{}     ECX[03:00]: EPC section property encoding defined as follows: If EAX[3:0] 0000b, then all bits of the EDX:ECX pair are enumerated as 0.If EAX[3:0] 0001b, then this section has confidentiality and integrity protection.All other encodings are reserved.ECX[11:04]: Reserved (enumerate 0). ECX[31:12]: Bits 31:12 of the size of the corresponding EPC section within the Processor Reserved Memory.\newline{}     EDX[19:00]: Bits 51:32 of the size of the corresponding EPC section within the Processor Reserved Memory. EDX[31:20]: Reserved.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Intel Processor Trace Enumeration Main Leaf (EAX = 14H, ECX = 0)|
|14H|###     NOTES:
\newline{}\newline{}Leaf 14H main leaf (ECX = 0). \newline{}EAX Bits 31 - 00: Reports the maximum sub-leaf supported in leaf 14H.\newline{}EBX Bit 00: If 1, indicates that IA32_RTIT_CTL.CR3Filter can be set to 1, and that IA32_RTIT_CR3_MATCH MSR can be accessed.Bit 01: If 1, indicates support of Configurable PSB and Cycle-Accurate Mode.Bit 02: If 1, indicates support of IP Filtering, TraceStop filtering, and preservation of Intel PT MSRs across warm reset.Bit 03: If 1, indicates support of MTC timing packet and suppression of COFI-based packets.Bit 04: If 1, indicates support of PTWRITE. Writes can set IA32_RTIT_CTL[12] (PTWEn) and IA32_RTIT_CTL[5] (FUPonPTW), and PTWRITE can generate packets.Bit 05: If 1, indicates support of Power Event Trace. Writes can set IA32_RTIT_CTL[4] (PwrEvtEn), enabling Power Event Trace packet generation.Bit 31 - 06: Reserved. \newline{}ECX Bit 00: If 1, Tracing can be enabled with IA32_RTIT_CTL.ToPA = 1, hence utilizing the ToPA output scheme; IA32_RTIT_OUTPUT_BASE and IA32_RTIT_OUTPUT_MASK_PTRS MSRs can be accessed.Bit 01: If 1, ToPA tables can hold any number of output entries, up to the maximum allowed by the Mas-kOrTableOffset field of IA32_RTIT_OUTPUT_MASK_PTRS.Bit 02: If 1, indicates support of Single-Range Output scheme.Bit 03: If 1, indicates support of output to Trace Transport subsystem.Bit 30 - 04: Reserved.Bit 31: If 1, generated packets which contain IP payloads have LIP values, which include the CS base com-ponent.\newline{}EDX Bits 31 - 00: Reserved.|
||Intel Processor Trace Enumeration Sub-leaf (EAX = 14H, ECX = 1)|
|14H|EAX Bits 02 - 00: Number of configurable Address Ranges for filtering.Bits 15 - 03: Reserved.Bits 31 - 16: Bitmap of supported MTC period encodings.\newline{}EBX Bits 15 - 00: Bitmap of supported Cycle Threshold value encodings.Bit 31 - 16: Bitmap of supported Configurable PSB frequency encodings.\newline{}ECX Bits 31 - 00: Reserved.\newline{}EDX  Bits 31 - 00: Reserved.|
||Time Stamp Counter and Nominal Core Crystal Clock Information Leaf |
|15H|###     NOTES:
\newline{}\newline{}If EBX[31:0] is 0, the TSC/"core crystal clock" ratio is not enumerated.\newline{}     EBX[31:0]/EAX[31:0] indicates the ratio of the TSC frequency and the core crystal clock frequency.\newline{}     If ECX is 0, the nominal core crystal clock frequency is not enumerated.\newline{}     "TSC frequency" = "core crystal clock frequency" * EBX/EAX.\newline{}     The core crystal clock may differ from the reference clock, bus clock, or core clock frequencies.\newline{}EAX Bits 31 - 00: An unsigned integer which is the denominator of the TSC/"core crystal clock" ratio.\newline{}EBX Bits 31 - 00: An unsigned integer which is the numerator of the TSC/"core crystal clock" ratio.\newline{}ECX Bits 31 - 00: An unsigned integer which is the nominal frequency of the core crystal clock in Hz.\newline{}EDX Bits 31 - 00: Reserved = 0.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||Processor Frequency Information Leaf |
|16H|EAX Bits 15 - 00: Processor Base Frequency (in MHz).Bits 31 - 16: Reserved =0.\newline{}EBX Bits 15 - 00: Maximum Frequency (in MHz).Bits 31 - 16: Reserved = 0.\newline{}ECX Bits 15 - 00: Bus (Reference) Frequency (in MHz).Bits 31 - 16: Reserved = 0.\newline{}EDX Reserved.\newline{}\newline{}###     NOTES:
\newline{}\newline{}* Data is returned from this interface in accordance with the processor's specification and does not reflect actual values. Suitable use of this data includes the display of processor information in like manner to the processor brand string and for determining the appropriate range to use when displaying processor information e.g. frequency history graphs. The returned information should not be used for any other purpose as the returned information does not accurately correlate to information / counters returned by other processor interfaces. \newline{}    While a processor may support the Processor Frequency Information leaf, fields that return a value of zero are not supported.|
||System-On-Chip Vendor Attribute Enumeration Main Leaf (EAX = 17H, ECX = 0)|
|17H|###     NOTES:
\newline{}\newline{}Leaf 17H main leaf (ECX = 0).\newline{}     Leaf 17H output depends on the initial value in ECX.\newline{}     Leaf 17H sub-leaves 1 through 3 reports SOC Vendor Brand String.\newline{}     Leaf 17H is valid if MaxSOCID_Index >= 3.\newline{}     Leaf 17H sub-leaves 4 and above are reserved.\newline{}EAX Bits 31 - 00: MaxSOCID_Index. Reports the maximum input value of supported sub-leaf in leaf 17H.\newline{}EBX Bits 15 - 00: SOC Vendor ID.Bit 16: IsVendorScheme. If 1, the SOC Vendor ID field is assigned via an industry standard enumerationscheme. Otherwise, the SOC Vendor ID field is assigned by Intel.Bits 31 - 17: Reserved = 0.\newline{}ECX Bits 31 - 00: Project ID. A unique number an SOC vendor assigns to its SOC projects.\newline{}EDX Bits 31 - 00: Stepping ID. A unique number within an SOC project that an SOC vendor assigns.|
||System-On-Chip Vendor Attribute Enumeration Sub-leaf (EAX = 17H, ECX = 1..3)|
|17H|EAX Bit 31 - 00: SOC Vendor Brand String. UTF-8 encoded string.\newline{}EBX Bit 31 - 00: SOC Vendor Brand String. UTF-8 encoded string.\newline{}ECX Bit 31 - 00: SOC Vendor Brand String. UTF-8 encoded string.\newline{}EDX Bit 31 - 00: SOC Vendor Brand String. UTF-8 encoded string.\newline{}\newline{}###     NOTES:
\newline{}\newline{}Leaf 17H output depends on the initial value in ECX.\newline{}     SOC Vendor Brand String is a UTF-8 encoded string padded with trailing bytes of 00H.\newline{}     The complete SOC Vendor Brand String is constructed by concatenating in ascending order of\newline{}     EAX:EBX:ECX:EDX and from the sub-leaf 1 fragment towards sub-leaf 3.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
||System-On-Chip Vendor Attribute Enumeration Sub-leaves (EAX = 17H, ECX > MaxSOCID_Index)|
|17H|###     NOTES:
\newline{}\newline{}Leaf 17H output depends on the initial value in ECX.\newline{}EAX Bits 31 - 00: Reserved = 0.\newline{}EBX Bits 31 - 00: Reserved = 0.\newline{}ECX Bits 31 - 00: Reserved = 0.\newline{}EDX Bits 31 - 00: Reserved = 0.|
||Unimplemented CPUID Leaf Functions|
|40000000H -4FFFFFFFH|Invalid. No existing or future CPU will return processor identification or feature information if the initial EAX value is in the range 40000000H to 4FFFFFFFH.|
||Extended Function CPUID Information|
|80000000H|EAX Maximum Input Value for Extended Function CPUID Information.\newline{}EBX Reserved.\newline{}ECX Reserved.\newline{}EDX Reserved.|
|80000001H|EAX Extended Processor Signature and Feature Bits.\newline{}EBX Reserved.\newline{}ECX Bit 00: LAHF/SAHF available in 64-bit mode.Bits 04 - 01: Reserved.Bit 05: LZCNT.Bits 07 - 06: Reserved.Bit 08: PREFETCHW.Bits 31 - 09: Reserved.\newline{}EDX Bits 10 - 00: Reserved.Bit 11: SYSCALL/SYSRET available in 64-bit mode.Bits 19 - 12: Reserved = 0.Bit 20: Execute Disable Bit available.Bits 25 - 21: Reserved = 0.Bit26: 1-GByte pages are available if 1.Bit 27: RDTSCP and IA32_TSC_AUX are available if 1.Bit 28: Reserved = 0.\newline{}    Bit 29: Intel\footnote{(R)}  64 Architecture available if 1.Bits 31 - 30: Reserved = 0.|
|80000002H|EAX Processor Brand String.EBX Processor Brand String Continued.ECX Processor Brand String Continued.EDX Processor Brand String Continued.|
|80000003H|EAX Processor Brand String Continued.EBX Processor Brand String Continued.ECX Processor Brand String Continued.EDX Processor Brand String Continued.|
### Table 3-8.  Information Returned by CPUID Instruction (Contd.)


|**Initial EAX **\newline{}**Value**|**Information Provided about the Processor**|
|-----------------------------------|--------------------------------------------|
|80000004H|EAX Processor Brand String Continued.EBX Processor Brand String Continued.ECX Processor Brand String Continued.EDX Processor Brand String Continued.|
|80000005H|EAX Reserved = 0.EBX Reserved = 0.ECX Reserved = 0.EDX Reserved = 0.|
|80000006H|EAX Reserved = 0.EBX Reserved = 0.\newline{}ECX Bits 07 - 00: Cache Line size in bytes.Bits 11 - 08: Reserved.Bits 15 - 12: L2 Associativity field *.Bits 31 - 16: Cache size in 1K units.EDX Reserved = 0.\newline{}\newline{}###     NOTES:
\newline{}\newline{}* L2 associativity field encodings:00H - Disabled.01H - Direct mapped.02H - 2-way.04H - 4-way.06H - 8-way.08H - 16-way.0FH - Fully associative.|
|80000007H|EAX Reserved = 0.EBX Reserved = 0.ECX Reserved = 0.EDX Bits 07 - 00: Reserved = 0.Bit 08: Invariant TSC available if 1.Bits 31 - 09: Reserved = 0.|
|80000008H|EAX Linear/Physical Address size.Bits 07 - 00: #Physical Address Bits*.Bits 15 - 08: #Linear Address Bits.Bits 31 - 16: Reserved = 0.\newline{}EBX Reserved = 0.ECX Reserved = 0.EDX Reserved = 0.\newline{}\newline{}###     NOTES:
\newline{}\newline{}* If CPUID.80000008H:EAX[7:0] is supported, the maximum physical address number supported should come from this field.|
### INPUT EAX = 0: Returns CPUID's Highest Value for Basic Processor Information and the Vendor Identification String


When CPUID executes with EAX set to 0, the processor returns the highest value the CPUID recognizes for returning basic processor information. The value is returned in the EAX register and is processor specific.



A vendor identification string is also returned in EBX, EDX, and ECX. For Intel processors, the string is "Genuin-eIntel" and is expressed:

 EBX <- 756e6547h (* "Genu", with G in the low eight bits of BL *)

 EDX <- 49656e69h (* "ineI", with i in the low eight bits of DL *)

 ECX <- 6c65746eh (* "ntel", with n in the low eight bits of CL *)

### INPUT EAX = 80000000H: Returns CPUID's Highest Value for Extended Processor Information


When CPUID executes with EAX set to 80000000H, the processor returns the highest value the processor recog-nizes for returning extended processor information. The value is returned in the EAX register and is processor specific.

### IA32_BIOS_SIGN_ID Returns Microcode Update Signature


For processors that support the microcode update facility, the IA32_BIOS_SIGN_ID MSR is loaded with the update signature whenever CPUID executes. The signature is returned in the upper DWORD. For details, see Chapter 9 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A. 

### INPUT EAX = 01H: Returns Model, Family, Stepping Information


When CPUID executes with EAX set to 01H, version information is returned in EAX (see Figure3-6). For example: model, family, and processor type for the Intel Xeon processor 5100 series is as follows:

*  Model -- 1111B

*  Family -- 0101B

*  Processor Type -- 00B

See Table 3-9 for available processor type values. Stepping IDs are provided as needed.

```embed
<figure>
<svg viewBox="0 0 379.679993 219.740005">
<rect x="0.000000" y="10.000000" width="0.480000" height="190.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.199982" y="10.000000" width="0.479980" height="190.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="200.500000" width="379.679993" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="9.419998" y="26.739990" width="360.899994" height="166.020004" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="201.239990" y="39.459991" width="20.280001" height="40.619999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="38.879997" y="39.459991" width="40.560001" height="40.619999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<path d="M323.040009,39.459991 L323.040009,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M282.420013,39.459991 L282.420013,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M241.860016,39.459991 L241.860016,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M221.520020,39.459991 L221.520020,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M201.240021,39.459991 L201.240021,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M160.620026,39.459991 L160.620026,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M79.440041,39.459991 L79.440041,80.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="38.879997" y="39.459991" width="324.779999" height="40.619999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M300.540009,80.200012 L300.540009,150.040009 L62.040016,150.040009" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M262.500000,80.080017 L262.500000,136.060028 L216.839996,136.060028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M234.600006,80.080017 L234.600006,123.400024 L84.840019,123.400024" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M186.359985,80.200012 L186.359985,112.540009 L110.819984,112.540009" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M138.179993,80.200012 L138.179993,99.100006 L112.799995,99.100006" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="11.279999" y="165.880005" width="15.240000" height="15.180000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="11.279999" y="165.880005" width="15.240000" height="15.180000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<text x="57.525581" y="174.339996" textLength="4.526950" font-size="8px">v</text>
<text x="54.465370" y="174.339996" textLength="3.014949" font-size="8px">r</text>
<text x="40.025307" y="174.339996" textLength="5.033968" font-size="8px">e</text>
<text x="87.247627" y="114.041168" textLength="2.516984" font-size="8px"> </text>
<text x="78.188286" y="114.041168" textLength="2.516984" font-size="8px">I</text>
<text x="73.628731" y="114.041168" textLength="2.009966" font-size="8px">l</text>
<text x="68.649986" y="114.041168" textLength="5.033968" font-size="8px">e</text>
<text x="63.671242" y="114.041168" textLength="5.033968" font-size="8px">d</text>
<text x="48.610970" y="114.041168" textLength="2.516984" font-size="8px"> </text>
<text x="23.657494" y="114.041168" textLength="5.033968" font-size="8px">e</text>
<text x="21.135979" y="114.041168" textLength="2.516984" font-size="8px">t</text>
<text x="10.680527" y="114.041168" textLength="6.038951" font-size="8px">E</text>
<text x="100.606621" y="99.521423" textLength="3.014949" font-size="8px">)</text>
<text x="95.508369" y="99.521423" textLength="5.033968" font-size="8px">0</text>
<text x="92.554085" y="99.521423" textLength="3.014949" font-size="8px">(</text>
<text x="89.972816" y="99.521423" textLength="2.516984" font-size="8px"> </text>
<text x="73.951927" y="99.521423" textLength="4.526950" font-size="8px">y</text>
<text x="62.314034" y="99.521423" textLength="7.541899" font-size="8px">m</text>
<text x="57.340721" y="99.521423" textLength="5.033968" font-size="8px">a</text>
<text x="49.288185" y="99.521423" textLength="2.516984" font-size="8px"> </text>
<text x="44.314873" y="99.521423" textLength="5.033968" font-size="8px">d</text>
<text x="34.368248" y="99.521423" textLength="5.033968" font-size="8px">d</text>
<text x="11.340553" y="99.521423" textLength="6.038951" font-size="8px">E</text>
<text x="357.118011" y="57.400879" textLength="5.033968" font-size="8px">g</text>
<text x="352.135651" y="57.400879" textLength="5.033968" font-size="8px">n</text>
<text x="345.114349" y="57.400879" textLength="5.033968" font-size="8px">p</text>
<text x="335.149628" y="57.400879" textLength="5.033968" font-size="8px">e</text>
<text x="297.892822" y="62.800629" textLength="5.033968" font-size="8px">o</text>
<text x="290.400726" y="62.800629" textLength="7.541899" font-size="8px">M</text>
<text x="271.141266" y="57.399994" textLength="4.526950" font-size="8px">y</text>
<text x="267.068817" y="57.399994" textLength="2.009966" font-size="8px">i</text>
<text x="192.478271" y="68.200378" textLength="6.536916" font-size="8px">D</text>
<text x="189.897003" y="68.200378" textLength="2.516984" font-size="8px">I</text>
<text x="187.375488" y="68.200378" textLength="2.516984" font-size="8px"> </text>
<text x="185.336548" y="68.200378" textLength="2.009966" font-size="8px">l</text>
<text x="180.357819" y="68.200378" textLength="5.033968" font-size="8px">e</text>
<text x="175.379089" y="68.200378" textLength="5.033968" font-size="8px">d</text>
<text x="189.904266" y="57.399994" textLength="5.033968" font-size="8px">e</text>
<text x="179.950409" y="57.399994" textLength="5.033968" font-size="8px">n</text>
<text x="174.973480" y="57.399994" textLength="5.033968" font-size="8px">e</text>
<text x="172.392212" y="57.399994" textLength="2.516984" font-size="8px">t</text>
<text x="132.840271" y="68.200378" textLength="6.536916" font-size="8px">D</text>
<text x="123.256721" y="68.200378" textLength="4.526950" font-size="8px">y</text>
<text x="121.292931" y="68.200378" textLength="2.009966" font-size="8px">l</text>
<text x="119.253990" y="68.200378" textLength="2.009966" font-size="8px">i</text>
<text x="106.706184" y="68.200378" textLength="5.033968" font-size="8px">a</text>
<text x="134.109619" y="57.399994" textLength="5.033968" font-size="8px">d</text>
<text x="124.152138" y="57.399994" textLength="5.033968" font-size="8px">d</text>
<text x="119.129036" y="57.399994" textLength="5.033968" font-size="8px">n</text>
<text x="111.644173" y="57.399994" textLength="2.516984" font-size="8px">t</text>
<text x="107.128090" y="57.399994" textLength="4.526950" font-size="8px">x</text>
<text x="101.099998" y="57.399994" textLength="6.038951" font-size="8px">E</text>
<text x="35.874916" y="151.539978" textLength="2.516984" font-size="8px"> </text>
<text x="33.835976" y="151.539978" textLength="2.009966" font-size="8px">l</text>
<text x="203.811188" y="137.500092" textLength="3.014949" font-size="8px">)</text>
<text x="199.250732" y="137.500092" textLength="4.526950" font-size="8px">y</text>
<text x="195.173767" y="137.500092" textLength="2.009966" font-size="8px">i</text>
<text x="177.153809" y="137.500092" textLength="5.531933" font-size="8px">F</text>
<text x="171.572083" y="137.500092" textLength="3.014949" font-size="8px">r</text>
<text x="166.584290" y="137.500092" textLength="5.033968" font-size="8px">o</text>
<text x="259.500671" y="57.399994" textLength="7.541899" font-size="8px">m</text>
<text x="143.166382" y="137.500092" textLength="5.033968" font-size="8px">o</text>
<text x="140.106171" y="137.500092" textLength="3.014949" font-size="8px">r</text>
<text x="124.142326" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="116.582314" y="137.500092" textLength="7.541899" font-size="8px">m</text>
<text x="102.055321" y="137.500092" textLength="5.033968" font-size="8px">n</text>
<text x="97.067528" y="137.500092" textLength="5.033968" font-size="8px">e</text>
<text x="91.074745" y="137.500092" textLength="6.038951" font-size="8px">P</text>
<text x="88.493477" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="83.505684" y="137.500092" textLength="5.033968" font-size="8px">e</text>
<text x="73.474861" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="70.414650" y="137.500092" textLength="3.014949" font-size="8px">r</text>
<text x="75.666771" y="114.041168" textLength="2.516984" font-size="8px"> </text>
<text x="65.435905" y="137.500092" textLength="5.033968" font-size="8px">o</text>
<text x="53.842384" y="137.500092" textLength="6.536916" font-size="8px">H</text>
<text x="48.356621" y="137.500092" textLength="5.531933" font-size="8px">F</text>
<text x="43.377876" y="137.500092" textLength="5.033968" font-size="8px">0</text>
<text x="40.317665" y="137.500092" textLength="3.014949" font-size="8px">(</text>
<text x="37.855904" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="29.394936" y="99.521423" textLength="5.033968" font-size="8px">n</text>
<text x="29.373299" y="137.500092" textLength="2.009966" font-size="8px">i</text>
<text x="16.825493" y="137.500092" textLength="5.033968" font-size="8px">a</text>
<text x="13.500000" y="62.799988" textLength="6.038951" font-size="8px">E</text>
<text x="43.917610" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="40.198616" y="35.140015" textLength="3.763675" font-size="8px">3</text>
<text x="74.397285" y="35.140015" textLength="3.763675" font-size="8px">8</text>
<text x="84.537544" y="35.140015" textLength="3.763675" font-size="8px">7</text>
<text x="155.577576" y="35.140015" textLength="3.763675" font-size="8px">0</text>
<text x="196.197510" y="35.140015" textLength="3.763675" font-size="8px">6</text>
<text x="206.337769" y="35.140015" textLength="3.763675" font-size="8px">5</text>
<text x="216.478027" y="35.140015" textLength="3.763675" font-size="8px">4</text>
<text x="222.899292" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="326.279846" y="35.140015" textLength="3.763675" font-size="8px">3</text>
<text x="360.839996" y="35.140015" textLength="3.763675" font-size="8px">0</text>
<text x="68.684731" y="125.500000" textLength="5.033968" font-size="8px">e</text>
<text x="63.697838" y="125.500000" textLength="5.033968" font-size="8px">p</text>
<text x="59.217964" y="125.500000" textLength="4.526950" font-size="8px">y</text>
<text x="53.733116" y="125.500000" textLength="5.531933" font-size="8px">T</text>
<text x="48.183983" y="125.500000" textLength="3.014949" font-size="8px">r</text>
<text x="43.145485" y="125.500000" textLength="5.033968" font-size="8px">o</text>
<text x="29.198845" y="125.500000" textLength="5.033968" font-size="8px">e</text>
<text x="19.732079" y="125.500000" textLength="5.033968" font-size="8px">o</text>
<text x="10.680000" y="125.500000" textLength="6.038951" font-size="8px">P</text>
<text x="357.659424" y="189.399994" textLength="3.763675" font-size="8px">5</text>
<text x="353.940430" y="189.399994" textLength="3.763675" font-size="8px">6</text>
<text x="350.221436" y="189.399994" textLength="3.763675" font-size="8px">1</text>
<text x="339.299988" y="189.399994" textLength="5.266438" font-size="8px">O</text>
<text x="344.521759" y="189.399994" textLength="5.638743" font-size="8px">M</text>
<text x="33.674736" y="114.041168" textLength="5.033968" font-size="8px">d</text>
<text x="134.113403" y="137.500092" textLength="6.038951" font-size="8px">P</text>
<text x="131.591888" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="194.881195" y="57.399994" textLength="5.033968" font-size="8px">d</text>
<text x="51.132484" y="114.041168" textLength="7.541899" font-size="8px">M</text>
<text x="339.901123" y="68.201263" textLength="2.516984" font-size="8px">I</text>
<text x="161.940399" y="57.399994" textLength="6.038951" font-size="8px">E</text>
<text x="285.659912" y="35.140015" textLength="3.763675" font-size="8px">7</text>
<text x="126.604088" y="137.500092" textLength="5.033968" font-size="8px">4</text>
<text x="361.378418" y="189.399994" textLength="3.763675" font-size="8px">2</text>
<text x="101.220421" y="68.200378" textLength="5.531933" font-size="8px">F</text>
<text x="51.151848" y="125.500000" textLength="2.516984" font-size="8px"> </text>
<text x="92.849266" y="114.041168" textLength="5.033968" font-size="8px">0</text>
<text x="97.947517" y="114.041168" textLength="3.014949" font-size="8px">)</text>
<text x="148.154175" y="137.500092" textLength="4.526950" font-size="8px">c</text>
<text x="34.185738" y="125.500000" textLength="4.526950" font-size="8px">s</text>
<text x="162.840363" y="68.200378" textLength="7.541899" font-size="8px">M</text>
<text x="73.671623" y="125.500000" textLength="2.516984" font-size="8px"> </text>
<text x="246.898804" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="170.400360" y="68.200378" textLength="5.033968" font-size="8px">o</text>
<text x="33.540001" y="174.339996" textLength="6.536916" font-size="8px">R</text>
<text x="71.912987" y="99.521423" textLength="2.009966" font-size="8px">l</text>
<text x="275.519653" y="35.140015" textLength="3.763675" font-size="8px">8</text>
<text x="233.039551" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="18.899742" y="151.539978" textLength="5.033968" font-size="8px">o</text>
<text x="89.889549" y="114.041168" textLength="3.014949" font-size="8px">(</text>
<text x="16.664253" y="114.041168" textLength="4.526950" font-size="8px">x</text>
<text x="83.494743" y="99.521423" textLength="6.536916" font-size="8px">D</text>
<text x="260.401550" y="68.200378" textLength="6.536916" font-size="8px">D</text>
<text x="24.421623" y="99.521423" textLength="5.033968" font-size="8px">e</text>
<text x="33.375130" y="137.500092" textLength="4.526950" font-size="8px">y</text>
<text x="62.854637" y="137.500092" textLength="2.516984" font-size="8px">f</text>
<text x="340.131989" y="57.400879" textLength="5.033968" font-size="8px">p</text>
<text x="19.500023" y="62.799988" textLength="6.038951" font-size="8px">A</text>
<text x="269.105042" y="57.399994" textLength="2.009966" font-size="8px">l</text>
<text x="174.632294" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="80.769554" y="114.041168" textLength="6.536916" font-size="8px">D</text>
<text x="326.581024" y="57.400879" textLength="6.038951" font-size="8px">S</text>
<text x="236.758545" y="35.140015" textLength="3.763675" font-size="8px">2</text>
<text x="78.391960" y="99.521423" textLength="2.516984" font-size="8px"> </text>
<text x="23.878487" y="151.539978" textLength="5.033968" font-size="8px">d</text>
<text x="157.622742" y="137.500092" textLength="4.526950" font-size="8px">s</text>
<text x="167.922302" y="57.399994" textLength="4.526950" font-size="8px">x</text>
<text x="129.130890" y="57.399994" textLength="5.033968" font-size="8px">e</text>
<text x="165.717834" y="35.140015" textLength="3.763675" font-size="8px">9</text>
<text x="16.671867" y="125.500000" textLength="3.014949" font-size="8px">r</text>
<text x="80.818550" y="35.140015" textLength="3.763675" font-size="8px">2</text>
<text x="254.521942" y="57.399994" textLength="5.033968" font-size="8px">a</text>
<text x="350.096710" y="57.400879" textLength="2.009966" font-size="8px">i</text>
<text x="151.858582" y="35.140015" textLength="3.763675" font-size="8px">2</text>
<text x="365.097412" y="189.399994" textLength="3.763675" font-size="8px">5</text>
<text x="69.874046" y="99.521423" textLength="2.009966" font-size="8px">i</text>
<text x="342.422638" y="68.201263" textLength="6.536916" font-size="8px">D</text>
<text x="11.339737" y="137.500092" textLength="5.531933" font-size="8px">F</text>
<text x="49.483009" y="174.339996" textLength="5.033968" font-size="8px">e</text>
<text x="80.973228" y="99.521423" textLength="2.516984" font-size="8px">I</text>
<text x="226.618286" y="35.140015" textLength="3.763675" font-size="8px">3</text>
<text x="302.931305" y="62.800629" textLength="5.033968" font-size="8px">d</text>
<text x="314.999664" y="35.140015" textLength="3.763675" font-size="8px">4</text>
<text x="21.840355" y="99.521423" textLength="2.516984" font-size="8px">t</text>
<text x="202.618774" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="43.632225" y="114.041168" textLength="5.033968" font-size="8px">d</text>
<text x="182.639557" y="137.500092" textLength="5.033968" font-size="8px">a</text>
<text x="111.603569" y="137.500092" textLength="5.033968" font-size="8px">u</text>
<text x="28.636238" y="114.041168" textLength="5.033968" font-size="8px">n</text>
<text x="38.653481" y="114.041168" textLength="5.033968" font-size="8px">e</text>
<text x="28.857231" y="151.539978" textLength="5.033968" font-size="8px">e</text>
<text x="60.333122" y="137.500092" textLength="2.516984" font-size="8px"> </text>
<text x="21.813286" y="137.500092" textLength="7.541899" font-size="8px">m</text>
<text x="257.820282" y="68.200378" textLength="2.516984" font-size="8px">I</text>
<text x="127.737495" y="68.200378" textLength="2.516984" font-size="8px"> </text>
<text x="25.500038" y="62.799988" textLength="6.038951" font-size="8px">X</text>
<text x="212.759033" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="67.007729" y="174.339996" textLength="5.033968" font-size="8px">d</text>
<text x="187.678040" y="137.500092" textLength="7.541899" font-size="8px">m</text>
<text x="24.718971" y="125.500000" textLength="4.526950" font-size="8px">c</text>
<text x="58.692497" y="114.041168" textLength="5.033968" font-size="8px">o</text>
<text x="38.665611" y="125.500000" textLength="4.526950" font-size="8px">s</text>
<text x="11.339737" y="151.539978" textLength="7.541899" font-size="8px">M</text>
<text x="78.517891" y="137.500092" textLength="5.033968" font-size="8px">h</text>
<text x="249.060638" y="57.399994" textLength="5.531933" font-size="8px">F</text>
<text x="162.103516" y="137.500092" textLength="4.526950" font-size="8px">s</text>
<text x="70.678291" y="35.140015" textLength="3.763675" font-size="8px">2</text>
<text x="39.341560" y="99.521423" textLength="5.033968" font-size="8px">e</text>
<text x="161.998840" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="107.043114" y="137.500092" textLength="2.516984" font-size="8px">t</text>
<text x="192.478516" y="35.140015" textLength="3.763675" font-size="8px">1</text>
<text x="109.564629" y="137.500092" textLength="2.009966" font-size="8px">i</text>
<text x="62.025368" y="174.339996" textLength="5.033968" font-size="8px">e</text>
<text x="111.693977" y="68.200378" textLength="7.541899" font-size="8px">m</text>
<text x="51.869453" y="99.521423" textLength="5.531933" font-size="8px">F</text>
<text x="184.927338" y="57.399994" textLength="5.033968" font-size="8px">d</text>
<text x="17.400322" y="99.521423" textLength="4.526950" font-size="8px">x</text>
<text x="307.915466" y="62.800629" textLength="5.033968" font-size="8px">e</text>
<text x="130.259003" y="68.200378" textLength="2.516984" font-size="8px">I</text>
<text x="45.007668" y="174.339996" textLength="4.526950" font-size="8px">s</text>
<text x="31.411339" y="137.500092" textLength="2.009966" font-size="8px">l</text>
<text x="152.634949" y="137.500092" textLength="5.033968" font-size="8px">e</text>
<text x="197.211792" y="137.500092" textLength="2.009966" font-size="8px">l</text>
<text x="312.899628" y="62.800629" textLength="2.009966" font-size="8px">l</text>
<text x="114.150291" y="57.399994" textLength="5.033968" font-size="8px">e</text>
<text x="332.568359" y="57.400879" textLength="2.516984" font-size="8px">t</text>
<text x="75.996376" y="137.500092" textLength="2.516984" font-size="8px">t</text>
<text x="243.179810" y="35.140015" textLength="3.763675" font-size="8px">1</text>
</svg>
<figcaption>Figure 3-6.  Version Information Returned by CPUID in EAX
</figcaption></figure>
```
### Table 3-9.  Processor Type Field


|**Type**|**Encoding**|
|--------|------------|
|Original OEM Processor|00B|
|Intel OverDrive\footnote{(R)}  Processor|01B|
|Dual processor (not applicable to Intel486 processors)|10B|
|Intel reserved|11B|
###                         NOTE


See Chapter 19 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for information on identifying earlier IA-32 processors.

The Extended Family ID needs to be examined only when the Family ID is 0FH. Integrate the fields into a display using the following rule:

 IF Family_ID != 0FH

   THEN DisplayFamily = Family_ID;

   ELSE DisplayFamily = Extended_Family_ID + Family_ID;

   (* Right justify and zero-extend 4-bit field. *)

 FI;

 (* Show DisplayFamily as HEX field. *)

The Extended Model ID needs to be examined only when the Family ID is 06H or 0FH. Integrate the field into a display using the following rule:

 IF (Family_ID = 06H or Family_ID = 0FH)

   THEN DisplayModel = (Extended_Model_ID << 4) + Model_ID;

   (* Right justify and zero-extend 4-bit field; display Model_ID as HEX field.*)

   ELSE DisplayModel = Model_ID;

 FI;

 (* Show DisplayModel as HEX field. *)

### INPUT EAX = 01H: Returns Additional Information in EBX


When CPUID executes with EAX set to 01H, additional information is returned to the EBX register: 

*  Brand index (low byte of EBX) -- this number provides an entry into a brand string table that contains brand strings for IA-32 processors. More information about this field is provided later in this section. 

*  CLFLUSH instruction cache line size (second byte of EBX) -- this number indicates the size of the cache line flushed by the CLFLUSH and CLFLUSHOPT instructions in 8-byte increments. This field was introduced in the Pentium 4 processor.

*  Local APIC ID (high byte of EBX) -- this number is the 8-bit ID that is assigned to the local APIC on the processor during power up. This field was introduced in the Pentium 4 processor.

### INPUT EAX = 01H: Returns Feature Information in ECX and EDX


When CPUID executes with EAX set to 01H, feature information is returned in ECX and EDX.

*  Figure3-7 and Table 3-10 show encodings for ECX.

*  Figure3-8 and Table 3-11 show encodings for EDX.

For all feature flags, a 1 indicates that the feature is supported. Use Intel to properly interpret feature flags.

###                     NOTE


Software must confirm that a processor feature is present using feature flags returned by CPUID prior to using the feature. Software should not depend on future offerings retaining all features.

```embed
<figure>
<svg viewBox="0 0 380.280029 467.160004">
<rect x="0.000000" y="10.000000" width="0.480010" height="369.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.799988" y="10.000000" width="0.479980" height="369.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="380.279999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="379.000000" width="380.279999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="5.579994" y="20.709961" width="369.119995" height="356.549988" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="208.620010" y="37.059937" width="8.820000" height="35.220001" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<path d="M349.380005,37.059998 L349.380005,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M340.559998,37.059998 L340.559998,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M331.739990,37.059998 L331.739990,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M322.979980,37.059998 L322.979980,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M314.159973,37.059998 L314.159973,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M305.339966,37.059998 L305.339966,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M296.579956,37.059998 L296.579956,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M287.759949,37.059998 L287.759949,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M278.939941,37.059998 L278.939941,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M270.059937,37.059998 L270.059937,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M261.239929,37.059998 L261.239929,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M252.419907,37.059998 L252.419907,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M243.659897,37.059998 L243.659897,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M234.839890,37.059998 L234.839890,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M226.019882,37.059998 L226.019882,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M217.259872,37.059998 L217.259872,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M208.439865,37.059998 L208.439865,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M199.619858,37.059998 L199.619858,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M190.799850,37.059998 L190.799850,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M182.039841,37.059998 L182.039841,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M173.219833,37.059998 L173.219833,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M164.399826,37.059998 L164.399826,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M155.639816,37.059998 L155.639816,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M146.819809,37.059998 L146.819809,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M137.999802,37.059998 L137.999802,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M129.179794,37.059998 L129.179794,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M120.419800,37.059998 L120.419800,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M111.599808,37.059998 L111.599808,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M102.779800,37.059998 L102.779800,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M94.019806,37.059998 L94.019806,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M85.199814,37.059998 L85.199814,72.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="76.319992" y="37.059998" width="281.880005" height="35.099998" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="6.959999" y="359.679993" width="13.200000" height="13.200000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<path d="M6.959999,372.880005<rect x="6.959999" y="359.679993" width="13.200000" height="13.200000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.260010,72.160034 L292.260010,280.120056 L197.400009,280.120056" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M283.440002,72.160034 L283.440002,270.760040 L109.259995,270.760040" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M265.619995,72.160034 L265.619995,251.920044 L111.479980,251.920044" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M318.959961,72.160034 L318.959961,308.320038 L153.359970,308.320038" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M327.479980,72.160034 L327.479980,317.740051 L131.339966,317.740051" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M345.059937,72.160034 L345.059937,336.580048 L164.339951,336.580048" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M309.840027,72.159973 L309.840027,298.959961 L142.320007,298.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M274.619995,72.159973 L274.619995,261.279968 L124.680008,261.279968" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M230.639999,72.159973 L230.639999,213.699951 L93.899994,213.699951" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M239.460007,72.159973 L239.460007,222.459961 L74.040009,222.459961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M221.819992,72.159973 L221.819992,204.939941 L151.139999,204.939941" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M301.080017,72.159973 L301.080017,289.479980 L129.119995,289.479980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M186.539993,72.159973 L186.539993,178.479980 L87.239990,178.479980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M151.319992,72.159973 L151.319992,143.380005 L49.860001,143.380005" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M177.719986,72.159973 L177.719986,169.719971 L87.239975,169.719971" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M195.120010,72.159973 L195.120010,187.239990 L122.460007,187.239990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M168.900009,72.159973 L168.900009,160.959961 L45.480011,160.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M133.679993,72.159973 L133.679993,125.799988 L34.439987,125.799988" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M107.099991,72.159973 L107.099991,99.459961 L34.439987,99.459961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M115.919998,72.159973 L115.919998,108.279968 L56.460007,108.279968" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M124.919998,72.159973 L124.919998,117.039978 L45.479996,117.039978" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M353.880005,72.159973 L353.880005,345.939972 L115.919983,345.939972" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M248.219986,72.159973 L248.219986,231.279968 L115.919983,231.279968" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M203.939987,72.159973 L203.939987,196.119995 L144.539993,196.119995" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M336.059998,72.159973 L336.059998,327.159973 L115.919983,327.159973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M159.900009,72.159973 L159.900009,152.139954 L47.639999,152.139954" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M142.319992,72.159973 L142.319992,134.619995 L67.499985,134.619995" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M98.279999,72.159973 L98.279999,90.699951 L38.819992,90.699951" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M89.520004,72.159973 L89.520004,81.940002 L52.020004,81.940002" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M258.419983,72.159973 L258.419983,242.199951 L41.099991,242.199951" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="24.958878" y="244.539978" textLength="5.204334" font-size="8px">B</text>
<text x="19.259857" y="244.539978" textLength="5.633477" font-size="8px">D</text>
<text x="41.931870" y="84.100037" textLength="5.633477" font-size="8px">D</text>
<text x="31.080017" y="84.100037" textLength="5.204334" font-size="8px">A</text>
<text x="25.439514" y="84.100037" textLength="5.633477" font-size="8px">R</text>
<text x="19.740494" y="84.100037" textLength="5.633477" font-size="8px">D</text>
<text x="23.580170" y="92.859985" textLength="4.338245" font-size="8px">6</text>
<text x="19.204468" y="92.859985" textLength="4.338245" font-size="8px">1</text>
<text x="14.399620" y="92.859985" textLength="4.767388" font-size="8px">F</text>
<text x="54.761703" y="136.719971" textLength="4.338245" font-size="8px">n</text>
<text x="52.999100" y="136.719971" textLength="1.732177" font-size="8px">i</text>
<text x="38.060226" y="136.719971" textLength="4.338245" font-size="8px">e</text>
<text x="32.396317" y="136.719971" textLength="5.633477" font-size="8px">D</text>
<text x="29.815994" y="136.719971" textLength="2.598266" font-size="8px">-</text>
<text x="37.381012" y="154.419983" textLength="5.204334" font-size="8px">E</text>
<text x="20.940140" y="154.419983" textLength="6.070423" font-size="8px">O</text>
<text x="107.312195" y="329.500000" textLength="4.338245" font-size="8px">a</text>
<text x="100.300003" y="329.500000" textLength="2.598266" font-size="8px">r</text>
<text x="82.072342" y="329.500000" textLength="5.633477" font-size="8px">D</text>
<text x="75.983200" y="329.500000" textLength="1.732177" font-size="8px">i</text>
<text x="71.544296" y="329.500000" textLength="4.338245" font-size="8px">b</text>
<text x="60.214127" y="329.500000" textLength="4.338245" font-size="8px">6</text>
<text x="55.831406" y="329.500000" textLength="2.169123" font-size="8px"> </text>
<text x="45.953323" y="329.500000" textLength="2.169123" font-size="8px"> </text>
<text x="29.808197" y="329.500000" textLength="5.204334" font-size="8px">S</text>
<text x="19.767807" y="329.500000" textLength="4.767388" font-size="8px">T</text>
<text x="135.740112" y="198.279968" textLength="3.901300" font-size="8px">s</text>
<text x="133.100494" y="198.279968" textLength="2.598266" font-size="8px">r</text>
<text x="126.941895" y="198.279968" textLength="1.732177" font-size="8px">i</text>
<text x="124.785263" y="198.279968" textLength="2.169123" font-size="8px">f</text>
<text x="116.530121" y="198.279968" textLength="4.338245" font-size="8px">n</text>
<text x="112.091217" y="198.279968" textLength="4.338245" font-size="8px">e</text>
<text x="107.712402" y="198.279968" textLength="4.338245" font-size="8px">d</text>
<text x="32.161072" y="154.419983" textLength="5.204334" font-size="8px">B</text>
<text x="105.555771" y="198.279968" textLength="2.169123" font-size="8px">I</text>
<text x="90.797958" y="198.279968" textLength="2.169123" font-size="8px">t</text>
<text x="75.571198" y="198.279968" textLength="2.598266" font-size="8px">-</text>
<text x="59.433090" y="198.279968" textLength="3.901300" font-size="8px">c</text>
<text x="92.978821" y="329.500000" textLength="2.169123" font-size="8px"> </text>
<text x="54.994186" y="198.279968" textLength="4.338245" font-size="8px">o</text>
<text x="45.001404" y="198.279968" textLength="2.169123" font-size="8px"> </text>
<text x="32.768494" y="198.279968" textLength="2.169123" font-size="8px"> </text>
<text x="24.990875" y="198.279968" textLength="2.169123" font-size="8px">I</text>
<text x="19.291855" y="198.279968" textLength="5.633477" font-size="8px">C</text>
<text x="14.099998" y="198.279968" textLength="5.204334" font-size="8px">P</text>
<text x="107.412827" y="348.280304" textLength="3.901300" font-size="8px">s</text>
<text x="103.034012" y="348.280304" textLength="4.338245" font-size="8px">n</text>
<text x="78.104706" y="348.280304" textLength="3.901300" font-size="8px">x</text>
<text x="61.054474" y="348.280304" textLength="5.204334" font-size="8px">E</text>
<text x="55.884476" y="348.280304" textLength="5.204334" font-size="8px">S</text>
<text x="103.394455" y="198.279968" textLength="2.169123" font-size="8px"> </text>
<text x="48.553162" y="348.280304" textLength="2.169123" font-size="8px"> </text>
<text x="46.391846" y="348.280304" textLength="2.169123" font-size="8px"> </text>
<text x="19.270004" y="348.280304" textLength="5.204334" font-size="8px">S</text>
<text x="14.099998" y="348.280304" textLength="5.204334" font-size="8px">S</text>
<text x="91.794388" y="233.380005" textLength="3.901300" font-size="8px">y</text>
<text x="90.038803" y="233.380005" textLength="1.732177" font-size="8px">l</text>
<text x="85.677155" y="233.380005" textLength="4.338245" font-size="8px">p</text>
<text x="83.921570" y="233.380005" textLength="1.732177" font-size="8px">i</text>
<text x="75.565765" y="233.380005" textLength="4.338245" font-size="8px">u</text>
<text x="54.156204" y="233.380005" textLength="3.901300" font-size="8px">s</text>
<text x="45.003754" y="233.380005" textLength="4.767388" font-size="8px">F</text>
<text x="40.681122" y="233.380005" textLength="2.169123" font-size="8px"> </text>
<text x="32.855118" y="233.380005" textLength="7.802600" font-size="8px">—</text>
<text x="18.890793" y="233.380005" textLength="6.499566" font-size="8px">M</text>
<text x="24.959793" y="128.379761" textLength="5.204334" font-size="8px">S</text>
<text x="34.268951" y="348.280304" textLength="2.169123" font-size="8px"> </text>
<text x="19.739853" y="128.379761" textLength="5.204334" font-size="8px">E</text>
<text x="19.739853" y="101.619995" textLength="5.204334" font-size="8px">V</text>
<text x="35.339844" y="119.199890" textLength="5.204334" font-size="8px">E</text>
<text x="30.119904" y="119.199890" textLength="5.204334" font-size="8px">V</text>
<text x="19.740097" y="119.199890" textLength="5.204334" font-size="8px">S</text>
<text x="14.580231" y="119.199890" textLength="5.204334" font-size="8px">X</text>
<text x="30.840073" y="145.599976" textLength="5.633477" font-size="8px">C</text>
<text x="33.263336" y="163.179993" textLength="2.169123" font-size="8px">I</text>
<text x="18.479736" y="163.179993" textLength="4.338245" font-size="8px">2</text>
<text x="110.031754" y="189.519958" textLength="3.901300" font-size="8px">s</text>
<text x="92.633514" y="189.519958" textLength="5.204334" font-size="8px">A</text>
<text x="86.093384" y="189.519958" textLength="4.338245" font-size="8px">e</text>
<text x="81.654480" y="189.519958" textLength="4.338245" font-size="8px">h</text>
<text x="65.516373" y="189.519958" textLength="2.169123" font-size="8px"> </text>
<text x="63.349594" y="189.519958" textLength="2.169123" font-size="8px">t</text>
<text x="59.450638" y="189.519958" textLength="3.901300" font-size="8px">c</text>
<text x="55.071823" y="189.519958" textLength="4.338245" font-size="8px">e</text>
<text x="52.432205" y="189.519958" textLength="2.598266" font-size="8px">r</text>
<text x="32.871872" y="189.519958" textLength="7.802600" font-size="8px">—</text>
<text x="19.731506" y="189.519958" textLength="5.633477" font-size="8px">C</text>
<text x="55.379242" y="171.939941" textLength="2.169123" font-size="8px"> </text>
<text x="53.217926" y="171.939941" textLength="2.169123" font-size="8px"> </text>
<text x="45.357590" y="171.939941" textLength="7.802600" font-size="8px">—</text>
<text x="30.119888" y="171.939941" textLength="4.338245" font-size="8px">4</text>
<text x="19.680008" y="171.939941" textLength="5.204334" font-size="8px">S</text>
<text x="35.986679" y="110.439880" textLength="5.204334" font-size="8px">A</text>
<text x="87.740158" y="329.500000" textLength="5.204334" font-size="8px">S</text>
<text x="30.819794" y="110.439880" textLength="5.204334" font-size="8px">S</text>
<text x="79.636734" y="180.760010" textLength="4.338245" font-size="8px">1</text>
<text x="77.492584" y="180.760010" textLength="2.169123" font-size="8px">.</text>
<text x="73.173843" y="180.760010" textLength="4.338245" font-size="8px">4</text>
<text x="57.434433" y="180.760010" textLength="5.204334" font-size="8px">S</text>
<text x="55.273117" y="180.760010" textLength="2.169123" font-size="8px"> </text>
<text x="53.111801" y="180.760010" textLength="2.169123" font-size="8px"> </text>
<text x="30.079315" y="180.760010" textLength="4.338245" font-size="8px">4</text>
<text x="134.704071" y="300.399994" textLength="3.901300" font-size="8px">s</text>
<text x="111.438293" y="300.399994" textLength="4.338245" font-size="8px">e</text>
<text x="109.276978" y="300.399994" textLength="2.169123" font-size="8px">t</text>
<text x="89.238358" y="300.399994" textLength="4.338245" font-size="8px">n</text>
<text x="83.030609" y="300.399994" textLength="4.338245" font-size="8px">h</text>
<text x="68.155746" y="300.399994" textLength="6.499566" font-size="8px">M</text>
<text x="50.701340" y="300.399994" textLength="2.598266" font-size="8px">r</text>
<text x="33.781403" y="300.399994" textLength="7.802600" font-size="8px">—</text>
<text x="26.340073" y="300.399994" textLength="5.204334" font-size="8px">X</text>
<text x="14.579994" y="300.399994" textLength="5.204334" font-size="8px">V</text>
<text x="136.846603" y="207.039978" textLength="5.204334" font-size="8px">S</text>
<text x="128.145142" y="207.039978" textLength="2.169123" font-size="8px"> </text>
<text x="122.045074" y="207.039978" textLength="2.169123" font-size="8px">t</text>
<text x="120.275452" y="207.039978" textLength="1.732177" font-size="8px">i</text>
<text x="93.499268" y="207.039978" textLength="5.633477" font-size="8px">C</text>
<text x="91.398026" y="207.039978" textLength="2.169123" font-size="8px"> </text>
<text x="82.583420" y="207.039978" textLength="4.338245" font-size="8px">u</text>
<text x="73.768814" y="207.039978" textLength="4.338245" font-size="8px">e</text>
<text x="68.129883" y="207.039978" textLength="5.633477" font-size="8px">D</text>
<text x="56.795837" y="207.039978" textLength="4.338245" font-size="8px">e</text>
<text x="51.554047" y="207.039978" textLength="5.204334" font-size="8px">P</text>
<text x="47.171326" y="207.039978" textLength="2.169123" font-size="8px"> </text>
<text x="39.331268" y="207.039978" textLength="7.802600" font-size="8px">—</text>
<text x="37.230026" y="207.039978" textLength="2.169123" font-size="8px"> </text>
<text x="30.629807" y="207.039978" textLength="6.499566" font-size="8px">M</text>
<text x="111.299301" y="263.620483" textLength="4.338245" font-size="8px">n</text>
<text x="106.920486" y="263.620483" textLength="4.338245" font-size="8px">o</text>
<text x="81.207809" y="263.620483" textLength="5.204334" font-size="8px">E</text>
<text x="79.046494" y="263.620483" textLength="2.169123" font-size="8px"> </text>
<text x="69.267502" y="263.620483" textLength="5.204334" font-size="8px">E</text>
<text x="64.101395" y="263.620483" textLength="5.204334" font-size="8px">S</text>
<text x="58.881454" y="263.620483" textLength="5.204334" font-size="8px">S</text>
<text x="35.052322" y="263.620483" textLength="4.338245" font-size="8px">3</text>
<text x="20.432968" y="110.439880" textLength="5.204334" font-size="8px">S</text>
<text x="29.652145" y="263.620483" textLength="5.204334" font-size="8px">E</text>
<text x="19.266098" y="263.620483" textLength="5.204334" font-size="8px">S</text>
<text x="14.099998" y="263.620483" textLength="5.204334" font-size="8px">S</text>
<text x="14.399994" y="180.760010" textLength="5.204334" font-size="8px">S</text>
<text x="87.054306" y="215.859985" textLength="1.732177" font-size="8px">l</text>
<text x="82.675491" y="215.859985" textLength="4.338245" font-size="8px">o</text>
<text x="73.447357" y="215.859985" textLength="4.338245" font-size="8px">n</text>
<text x="58.080917" y="233.380005" textLength="4.338245" font-size="8px">e</text>
<text x="63.346115" y="215.859985" textLength="5.633477" font-size="8px">C</text>
<text x="56.817673" y="215.859985" textLength="4.338245" font-size="8px">e</text>
<text x="80.004669" y="233.380005" textLength="1.732177" font-size="8px">l</text>
<text x="50.277542" y="215.859985" textLength="4.338245" font-size="8px">a</text>
<text x="35.820877" y="215.859985" textLength="5.633477" font-size="8px">U</text>
<text x="33.659561" y="215.859985" textLength="2.169123" font-size="8px"> </text>
<text x="27.960541" y="215.859985" textLength="5.633477" font-size="8px">R</text>
<text x="22.800674" y="215.859985" textLength="5.204334" font-size="8px">P</text>
<text x="17.999741" y="215.859985" textLength="4.767388" font-size="8px">T</text>
<text x="111.786194" y="290.920258" textLength="4.338245" font-size="8px">o</text>
<text x="79.911026" y="329.500000" textLength="2.169123" font-size="8px"> </text>
<text x="110.047775" y="290.920258" textLength="1.732177" font-size="8px">i</text>
<text x="67.833740" y="180.760010" textLength="5.204334" font-size="8px">E</text>
<text x="95.189285" y="290.920258" textLength="2.169123" font-size="8px">t</text>
<text x="86.113312" y="290.920258" textLength="5.204334" font-size="8px">E</text>
<text x="83.951996" y="290.920258" textLength="2.169123" font-size="8px"> </text>
<text x="70.755463" y="290.920258" textLength="4.338245" font-size="8px">o</text>
<text x="106.148041" y="290.920258" textLength="3.901300" font-size="8px">s</text>
<text x="62.054001" y="290.920258" textLength="2.169123" font-size="8px"> </text>
<text x="81.980240" y="198.279968" textLength="4.338245" font-size="8px">o</text>
<text x="59.414383" y="290.920258" textLength="2.598266" font-size="8px">r</text>
<text x="52.834442" y="290.920258" textLength="2.169123" font-size="8px">f</text>
<text x="33.257736" y="290.920258" textLength="7.802600" font-size="8px">—</text>
<text x="25.816391" y="290.920258" textLength="5.204334" font-size="8px">X</text>
<text x="19.276245" y="290.920258" textLength="6.499566" font-size="8px">M</text>
<text x="14.099998" y="290.920258" textLength="5.204334" font-size="8px">S</text>
<text x="58.616959" y="224.619995" textLength="4.338245" font-size="8px">6</text>
<text x="54.178055" y="224.619995" textLength="4.338245" font-size="8px">1</text>
<text x="47.996841" y="224.619995" textLength="6.070423" font-size="8px">G</text>
<text x="36.658890" y="224.619995" textLength="5.633477" font-size="8px">C</text>
<text x="31.499023" y="224.619995" textLength="5.204334" font-size="8px">X</text>
<text x="40.672134" y="189.519958" textLength="2.169123" font-size="8px"> </text>
<text x="26.339157" y="224.619995" textLength="5.204334" font-size="8px">P</text>
<text x="14.099998" y="224.619995" textLength="5.633477" font-size="8px">C</text>
<text x="49.004257" y="368.680908" textLength="4.338245" font-size="8px">e</text>
<text x="45.104523" y="368.680908" textLength="3.901300" font-size="8px">v</text>
<text x="42.460999" y="368.680908" textLength="2.598266" font-size="8px">r</text>
<text x="24.060135" y="368.680908" textLength="5.633477" font-size="8px">R</text>
<text x="156.702744" y="338.921021" textLength="4.338245" font-size="8px">n</text>
<text x="152.326279" y="338.921021" textLength="4.338245" font-size="8px">o</text>
<text x="150.555862" y="338.921021" textLength="1.732177" font-size="8px">i</text>
<text x="148.454636" y="338.921021" textLength="2.169123" font-size="8px">t</text>
<text x="144.015747" y="338.921021" textLength="4.338245" font-size="8px">a</text>
<text x="136.575180" y="338.921021" textLength="1.732177" font-size="8px">l</text>
<text x="132.198700" y="338.921021" textLength="4.338245" font-size="8px">p</text>
<text x="130.460281" y="338.921021" textLength="1.732177" font-size="8px">i</text>
<text x="128.298965" y="338.921021" textLength="2.169123" font-size="8px">t</text>
<text x="126.528549" y="338.921021" textLength="1.732177" font-size="8px">l</text>
<text x="102.939621" y="329.500000" textLength="4.338245" font-size="8px">e</text>
<text x="122.152069" y="338.921021" textLength="4.338245" font-size="8px">u</text>
<text x="115.614273" y="338.921021" textLength="6.499566" font-size="8px">M</text>
<text x="109.553223" y="338.921021" textLength="3.901300" font-size="8px">s</text>
<text x="101.214584" y="338.921021" textLength="4.338245" font-size="8px">e</text>
<text x="61.171539" y="207.039978" textLength="2.598266" font-size="8px">r</text>
<text x="92.907928" y="338.921021" textLength="2.598266" font-size="8px">r</text>
<text x="90.271423" y="338.921021" textLength="2.598266" font-size="8px">r</text>
<text x="64.155243" y="290.920258" textLength="6.499566" font-size="8px">M</text>
<text x="85.832520" y="338.921021" textLength="4.338245" font-size="8px">a</text>
<text x="77.999496" y="338.921021" textLength="2.169123" font-size="8px"> </text>
<text x="51.982513" y="338.921021" textLength="5.633477" font-size="8px">D</text>
<text x="25.413773" y="233.380005" textLength="5.204334" font-size="8px">A</text>
<text x="29.335464" y="338.921021" textLength="6.499566" font-size="8px">M</text>
<text x="92.959274" y="198.279968" textLength="4.338245" font-size="8px">e</text>
<text x="77.755524" y="189.519958" textLength="3.901300" font-size="8px">c</text>
<text x="19.259964" y="338.921021" textLength="5.633477" font-size="8px">C</text>
<text x="123.731339" y="320.080872" textLength="4.767388" font-size="8px">T</text>
<text x="42.178040" y="145.599976" textLength="4.767388" font-size="8px">T</text>
<text x="121.570023" y="320.080872" textLength="2.169123" font-size="8px">I</text>
<text x="116.410156" y="320.080872" textLength="5.204334" font-size="8px">A</text>
<text x="83.703217" y="320.080872" textLength="4.767388" font-size="8px">T</text>
<text x="81.601974" y="320.080872" textLength="2.169123" font-size="8px">I</text>
<text x="86.373917" y="263.620483" textLength="3.901300" font-size="8px">x</text>
<text x="75.913879" y="320.080872" textLength="5.633477" font-size="8px">N</text>
<text x="69.852814" y="320.080872" textLength="6.070423" font-size="8px">O</text>
<text x="45.367477" y="320.080872" textLength="5.633477" font-size="8px">R</text>
<text x="39.306412" y="320.080872" textLength="6.070423" font-size="8px">O</text>
<text x="32.403458" y="320.080872" textLength="2.169123" font-size="8px">I</text>
<text x="145.443619" y="310.660797" textLength="4.338245" font-size="8px">e</text>
<text x="142.810226" y="310.660797" textLength="2.598266" font-size="8px">r</text>
<text x="101.222260" y="263.620483" textLength="3.901300" font-size="8px">s</text>
<text x="138.436874" y="310.660797" textLength="4.338245" font-size="8px">o</text>
<text x="136.275558" y="310.660797" textLength="2.169123" font-size="8px">t</text>
<text x="39.431137" y="263.620483" textLength="2.169123" font-size="8px"> </text>
<text x="131.036118" y="310.660797" textLength="5.204334" font-size="8px">S</text>
<text x="128.934875" y="310.660797" textLength="2.169123" font-size="8px"> </text>
<text x="124.495972" y="310.660797" textLength="4.338245" font-size="8px">g</text>
<text x="111.310364" y="310.660797" textLength="4.338245" font-size="8px">e</text>
<text x="94.668198" y="310.660797" textLength="4.338245" font-size="8px">e</text>
<text x="92.900909" y="310.660797" textLength="1.732177" font-size="8px">i</text>
<text x="88.972305" y="310.660797" textLength="1.732177" font-size="8px">i</text>
<text x="87.205017" y="310.660797" textLength="1.732177" font-size="8px">l</text>
<text x="82.831665" y="310.660797" textLength="4.338245" font-size="8px">a</text>
<text x="78.392761" y="310.660797" textLength="4.338245" font-size="8px">u</text>
<text x="72.331696" y="310.660797" textLength="6.070423" font-size="8px">Q</text>
<text x="70.230453" y="310.660797" textLength="2.169123" font-size="8px"> </text>
<text x="65.791550" y="310.660797" textLength="4.338245" font-size="8px">L</text>
<text x="60.631683" y="310.660797" textLength="5.204334" font-size="8px">P</text>
<text x="54.963089" y="310.660797" textLength="5.633477" font-size="8px">C</text>
<text x="14.579994" y="101.619995" textLength="5.204334" font-size="8px">A</text>
<text x="42.840195" y="310.660797" textLength="2.169123" font-size="8px"> </text>
<text x="95.140137" y="329.500000" textLength="5.204334" font-size="8px">A</text>
<text x="14.579994" y="163.179993" textLength="3.901300" font-size="8px">x</text>
<text x="186.274582" y="282.460632" textLength="4.338245" font-size="8px">g</text>
<text x="175.693466" y="282.460632" textLength="4.338245" font-size="8px">o</text>
<text x="166.945175" y="282.460632" textLength="4.338245" font-size="8px">h</text>
<text x="158.606522" y="282.460632" textLength="4.338245" font-size="8px">e</text>
<text x="153.803238" y="282.460632" textLength="4.767388" font-size="8px">T</text>
<text x="149.539108" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="139.378571" y="282.460632" textLength="4.338245" font-size="8px">p</text>
<text x="118.854645" y="282.460632" textLength="4.338245" font-size="8px">e</text>
<text x="114.415741" y="282.460632" textLength="4.338245" font-size="8px">e</text>
<text x="104.877060" y="282.460632" textLength="5.204334" font-size="8px">S</text>
<text x="102.714966" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="36.479019" y="145.599976" textLength="5.633477" font-size="8px">N</text>
<text x="100.552872" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="94.345901" y="282.460632" textLength="4.338245" font-size="8px">e</text>
<text x="92.184586" y="282.460632" textLength="2.169123" font-size="8px">t</text>
<text x="85.644455" y="282.460632" textLength="2.169123" font-size="8px">I</text>
<text x="76.946136" y="282.460632" textLength="4.338245" font-size="8px">d</text>
<text x="59.886551" y="282.460632" textLength="4.338245" font-size="8px">a</text>
<text x="55.447647" y="282.460632" textLength="4.338245" font-size="8px">h</text>
<text x="51.068832" y="282.460632" textLength="4.338245" font-size="8px">n</text>
<text x="67.711639" y="198.279968" textLength="3.901300" font-size="8px">s</text>
<text x="107.479187" y="233.380005" textLength="4.338245" font-size="8px">d</text>
<text x="41.584778" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="26.581161" y="282.460632" textLength="4.767388" font-size="8px">T</text>
<text x="21.421295" y="282.460632" textLength="5.204334" font-size="8px">S</text>
<text x="14.100113" y="282.460632" textLength="5.204334" font-size="8px">E</text>
<text x="96.710144" y="273.100647" textLength="2.598266" font-size="8px">r</text>
<text x="92.336792" y="273.100647" textLength="4.338245" font-size="8px">o</text>
<text x="73.061249" y="273.100647" textLength="6.499566" font-size="8px">M</text>
<text x="69.132645" y="273.100647" textLength="1.732177" font-size="8px">l</text>
<text x="64.693741" y="273.100647" textLength="4.338245" font-size="8px">a</text>
<text x="55.525681" y="273.100647" textLength="2.598266" font-size="8px">r</text>
<text x="14.100113" y="310.660797" textLength="5.633477" font-size="8px">D</text>
<text x="46.713425" y="273.100647" textLength="4.338245" font-size="8px">h</text>
<text x="39.809677" y="273.100647" textLength="2.169123" font-size="8px"> </text>
<text x="31.971970" y="273.100647" textLength="7.802600" font-size="8px">—</text>
<text x="29.810654" y="273.100647" textLength="2.169123" font-size="8px"> </text>
<text x="18.902618" y="273.100647" textLength="6.499566" font-size="8px">M</text>
<text x="78.207718" y="207.039978" textLength="4.338245" font-size="8px">b</text>
<text x="14.100113" y="273.100647" textLength="4.767388" font-size="8px">T</text>
<text x="181.900436" y="282.460632" textLength="4.338245" font-size="8px">o</text>
<text x="65.819641" y="57.279968" textLength="5.204334" font-size="8px">X</text>
<text x="60.175247" y="57.279968" textLength="5.633477" font-size="8px">C</text>
<text x="80.696808" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="77.457779" y="33.279968" textLength="3.253656" font-size="8px">3</text>
<text x="97.995987" y="300.399994" textLength="2.169123" font-size="8px"> </text>
<text x="98.277069" y="33.279968" textLength="3.253656" font-size="8px">9</text>
<text x="95.097733" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="115.917038" y="33.279968" textLength="3.253656" font-size="8px">7</text>
<text x="112.678009" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="130.258286" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="139.078262" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="59.877197" y="300.399994" textLength="4.338245" font-size="8px">a</text>
<text x="151.137253" y="33.279968" textLength="3.253656" font-size="8px">3</text>
<text x="147.898239" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="160.017502" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="156.778488" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="168.837479" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="165.598465" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="177.597794" y="33.279968" textLength="3.253656" font-size="8px">0</text>
<text x="174.418442" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="183.178726" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="19.738937" y="224.619995" textLength="6.499566" font-size="8px">M</text>
<text x="195.237717" y="33.279968" textLength="3.253656" font-size="8px">8</text>
<text x="200.818680" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="212.817978" y="33.279968" textLength="3.253656" font-size="8px">6</text>
<text x="209.578964" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="221.637955" y="33.279968" textLength="3.253656" font-size="8px">5</text>
<text x="230.457932" y="33.279968" textLength="3.253656" font-size="8px">4</text>
<text x="227.218918" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="239.218246" y="33.279968" textLength="3.253656" font-size="8px">3</text>
<text x="42.833450" y="189.519958" textLength="2.169123" font-size="8px"> </text>
<text x="236.038895" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="244.799179" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="262.439148" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="272.879517" y="33.279968" textLength="3.253656" font-size="8px">9</text>
<text x="25.620132" y="145.599976" textLength="5.204334" font-size="8px">P</text>
<text x="281.699463" y="33.279968" textLength="3.253656" font-size="8px">8</text>
<text x="290.519470" y="33.279968" textLength="3.253656" font-size="8px">7</text>
<text x="299.279724" y="33.279968" textLength="3.253656" font-size="8px">6</text>
<text x="325.679993" y="33.279968" textLength="3.253656" font-size="8px">3</text>
<text x="100.385040" y="254.380005" textLength="5.633477" font-size="8px">D</text>
<text x="45.921448" y="338.921021" textLength="6.070423" font-size="8px">Q</text>
<text x="96.068649" y="254.380005" textLength="2.169123" font-size="8px"> </text>
<text x="93.913574" y="254.380005" textLength="2.169123" font-size="8px">t</text>
<text x="14.100113" y="320.080872" textLength="6.499566" font-size="8px">M</text>
<text x="90.013840" y="254.380005" textLength="3.901300" font-size="8px">x</text>
<text x="120.122620" y="310.660797" textLength="4.338245" font-size="8px">u</text>
<text x="83.473694" y="254.380005" textLength="2.169123" font-size="8px">t</text>
<text x="79.034790" y="254.380005" textLength="4.338245" font-size="8px">n</text>
<text x="58.092621" y="254.380005" textLength="4.338245" font-size="8px">L</text>
<text x="45.909637" y="254.380005" textLength="2.169123" font-size="8px"> </text>
<text x="40.210617" y="254.380005" textLength="5.633477" font-size="8px">D</text>
<text x="105.653488" y="338.921021" textLength="3.901300" font-size="8px">s</text>
<text x="35.409683" y="254.380005" textLength="2.598266" font-size="8px">-</text>
<text x="25.418457" y="254.380005" textLength="5.204334" font-size="8px">X</text>
<text x="362.584534" y="363.699982" textLength="3.253656" font-size="8px">b</text>
<text x="359.165283" y="363.699982" textLength="3.253656" font-size="8px">4</text>
<text x="349.425354" y="363.699982" textLength="3.253656" font-size="8px">6</text>
<text x="346.246033" y="363.699982" textLength="3.253656" font-size="8px">1</text>
<text x="341.325745" y="363.699982" textLength="4.874633" font-size="8px">M</text>
<text x="336.779968" y="363.699982" textLength="4.552778" font-size="8px">O</text>
<text x="67.864960" y="171.939941" textLength="5.204334" font-size="8px">E</text>
<text x="43.742981" y="300.399994" textLength="5.204334" font-size="8px">V</text>
<text x="30.573639" y="233.380005" textLength="2.169123" font-size="8px"> </text>
<text x="47.162720" y="198.279968" textLength="5.204334" font-size="8px">P</text>
<text x="125.890259" y="300.399994" textLength="4.338245" font-size="8px">o</text>
<text x="88.525223" y="320.080872" textLength="6.070423" font-size="8px">O</text>
<text x="53.337051" y="320.080872" textLength="7.802600" font-size="8px">—</text>
<text x="120.908936" y="198.279968" textLength="2.169123" font-size="8px">t</text>
<text x="31.036331" y="290.920258" textLength="2.169123" font-size="8px"> </text>
<text x="34.564774" y="320.080872" textLength="4.767388" font-size="8px">T</text>
<text x="124.151840" y="300.399994" textLength="1.732177" font-size="8px">i</text>
<text x="191.998703" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="86.959122" y="207.039978" textLength="4.338245" font-size="8px">g</text>
<text x="54.975479" y="290.920258" textLength="4.338245" font-size="8px">e</text>
<text x="58.159058" y="273.100647" textLength="6.499566" font-size="8px">m</text>
<text x="107.097061" y="33.279968" textLength="3.253656" font-size="8px">8</text>
<text x="93.617172" y="300.399994" textLength="4.338245" font-size="8px">e</text>
<text x="315.899719" y="33.279968" textLength="3.253656" font-size="8px">4</text>
<text x="248.038193" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="14.399994" y="110.439880" textLength="6.070423" font-size="8px">O</text>
<text x="30.118744" y="244.539978" textLength="6.070423" font-size="8px">G</text>
<text x="22.918640" y="163.179993" textLength="5.204334" font-size="8px">A</text>
<text x="45.898727" y="215.859985" textLength="4.338245" font-size="8px">d</text>
<text x="98.229965" y="254.380005" textLength="2.169123" font-size="8px">I</text>
<text x="24.958878" y="207.039978" textLength="5.633477" font-size="8px">C</text>
<text x="72.934708" y="348.280304" textLength="5.204334" font-size="8px">E</text>
<text x="96.843445" y="263.620483" textLength="4.338245" font-size="8px">n</text>
<text x="27.588470" y="310.660797" textLength="5.633477" font-size="8px">C</text>
<text x="53.387756" y="368.680908" textLength="4.338245" font-size="8px">d</text>
<text x="120.603912" y="290.920258" textLength="3.901300" font-size="8px">s</text>
<text x="51.055573" y="320.080872" textLength="2.169123" font-size="8px"> </text>
<text x="265.618469" y="33.279968" textLength="3.253656" font-size="8px">0</text>
<text x="92.464630" y="263.620483" textLength="4.338245" font-size="8px">e</text>
<text x="43.792007" y="329.500000" textLength="2.169123" font-size="8px"> </text>
<text x="25.437302" y="273.100647" textLength="4.338245" font-size="8px">2</text>
<text x="120.252106" y="300.399994" textLength="3.901300" font-size="8px">s</text>
<text x="48.010880" y="254.380005" textLength="7.802600" font-size="8px">—</text>
<text x="64.260681" y="282.460632" textLength="4.338245" font-size="8px">n</text>
<text x="140.116013" y="338.921021" textLength="3.901300" font-size="8px">c</text>
<text x="308.099731" y="33.279968" textLength="3.253656" font-size="8px">5</text>
<text x="110.036926" y="282.460632" textLength="4.338245" font-size="8px">p</text>
<text x="89.516785" y="33.279968" textLength="3.253656" font-size="8px">0</text>
<text x="35.049973" y="198.279968" textLength="7.802600" font-size="8px">—</text>
<text x="88.408188" y="273.100647" textLength="1.732177" font-size="8px">i</text>
<text x="24.959793" y="101.619995" textLength="5.204334" font-size="8px">X</text>
<text x="108.989883" y="320.080872" textLength="7.365654" font-size="8px">W</text>
<text x="63.298630" y="320.080872" textLength="6.499566" font-size="8px">M</text>
<text x="43.746872" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="77.749710" y="329.500000" textLength="2.169123" font-size="8px">t</text>
<text x="46.373505" y="110.439880" textLength="5.204334" font-size="8px">E</text>
<text x="83.969284" y="273.100647" textLength="4.338245" font-size="8px">n</text>
<text x="98.784805" y="282.460632" textLength="1.732177" font-size="8px">l</text>
<text x="65.968567" y="207.039978" textLength="2.169123" font-size="8px">/</text>
<text x="50.714478" y="348.280304" textLength="5.204334" font-size="8px">S</text>
<text x="14.099998" y="215.859985" textLength="3.901300" font-size="8px">x</text>
<text x="78.091431" y="198.279968" textLength="3.901300" font-size="8px">c</text>
<text x="36.291367" y="84.100037" textLength="5.633477" font-size="8px">N</text>
<text x="49.332642" y="207.039978" textLength="2.169123" font-size="8px"> </text>
<text x="334.499939" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="34.122360" y="368.680908" textLength="3.901300" font-size="8px">s</text>
<text x="14.099998" y="329.500000" textLength="5.633477" font-size="8px">D</text>
<text x="80.160812" y="338.921021" textLength="5.633477" font-size="8px">C</text>
<text x="151.641129" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="69.068542" y="215.859985" textLength="4.338245" font-size="8px">o</text>
<text x="97.330322" y="290.920258" textLength="4.338245" font-size="8px">e</text>
<text x="24.839874" y="171.939941" textLength="5.204334" font-size="8px">E</text>
<text x="43.256348" y="171.939941" textLength="2.169123" font-size="8px"> </text>
<text x="63.807251" y="207.039978" textLength="2.169123" font-size="8px">f</text>
<text x="69.042786" y="233.380005" textLength="6.499566" font-size="8px">M</text>
<text x="24.960037" y="119.199890" textLength="5.204334" font-size="8px">A</text>
<text x="14.100113" y="338.921021" textLength="5.204334" font-size="8px">P</text>
<text x="19.577026" y="145.599976" textLength="6.070423" font-size="8px">O</text>
<text x="14.099998" y="233.380005" textLength="4.767388" font-size="8px">F</text>
<text x="97.338089" y="198.279968" textLength="3.901300" font-size="8px">x</text>
<text x="90.472198" y="189.519958" textLength="2.169123" font-size="8px"> </text>
<text x="138.179993" y="300.399994" textLength="3.253656" font-size="8px"> </text>
<text x="28.090988" y="163.179993" textLength="5.204334" font-size="8px">P</text>
<text x="105.377243" y="300.399994" textLength="3.901300" font-size="8px">x</text>
<text x="99.041550" y="310.660797" textLength="4.338245" font-size="8px">d</text>
<text x="72.572006" y="282.460632" textLength="4.338245" font-size="8px">e</text>
<text x="19.259979" y="282.460632" textLength="2.169123" font-size="8px">I</text>
<text x="99.170197" y="207.039978" textLength="4.338245" font-size="8px">a</text>
<text x="41.459824" y="215.859985" textLength="4.338245" font-size="8px">p</text>
<text x="19.579361" y="180.760010" textLength="5.204334" font-size="8px">S</text>
<text x="66.795639" y="254.380005" textLength="2.169123" font-size="8px"> </text>
<text x="27.147507" y="198.279968" textLength="5.633477" font-size="8px">D</text>
<text x="55.442200" y="300.399994" textLength="4.338245" font-size="8px">u</text>
<text x="55.871216" y="254.380005" textLength="2.169123" font-size="8px"> </text>
<text x="124.206390" y="207.039978" textLength="3.901300" font-size="8px">y</text>
<text x="115.738205" y="263.620483" textLength="3.901300" font-size="8px">s</text>
<text x="14.579994" y="128.379761" textLength="5.204334" font-size="8px">A</text>
<text x="95.544434" y="338.921021" textLength="3.901300" font-size="8px">y</text>
<text x="41.581665" y="300.399994" textLength="2.169123" font-size="8px"> </text>
<text x="18.897812" y="136.719971" textLength="5.204334" font-size="8px">S</text>
<text x="92.956955" y="348.280304" textLength="3.901300" font-size="8px">s</text>
<text x="132.843124" y="282.460632" textLength="2.169123" font-size="8px">t</text>
<text x="74.655975" y="254.380005" textLength="4.338245" font-size="8px">o</text>
<text x="59.130386" y="136.719971" textLength="4.338245" font-size="8px">e</text>
<text x="94.586288" y="320.080872" textLength="5.633477" font-size="8px">R</text>
<text x="103.480453" y="310.660797" textLength="2.169123" font-size="8px"> </text>
<text x="50.693787" y="189.519958" textLength="1.732177" font-size="8px">i</text>
<text x="25.430527" y="189.519958" textLength="5.204334" font-size="8px">A</text>
<text x="14.099998" y="84.100037" textLength="5.633477" font-size="8px">R</text>
<text x="105.652939" y="189.519958" textLength="4.338245" font-size="8px">e</text>
<text x="42.842438" y="233.380005" textLength="2.169123" font-size="8px"> </text>
<text x="20.654297" y="320.080872" textLength="6.070423" font-size="8px">O</text>
<text x="101.709137" y="290.920258" textLength="4.338245" font-size="8px">n</text>
<text x="24.489944" y="348.280304" textLength="5.204334" font-size="8px">E</text>
<text x="14.100372" y="189.519958" textLength="5.633477" font-size="8px">D</text>
<text x="79.020004" y="62.619995" textLength="3.253656" font-size="8px">0</text>
<text x="86.359055" y="198.279968" textLength="4.338245" font-size="8px">n</text>
<text x="256.858154" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="14.399994" y="145.599976" textLength="5.204334" font-size="8px">P</text>
<text x="75.838181" y="338.921021" textLength="2.169123" font-size="8px"> </text>
<text x="19.259857" y="207.039978" textLength="5.633477" font-size="8px">D</text>
<text x="26.715363" y="320.080872" textLength="5.633477" font-size="8px">N</text>
<text x="54.656357" y="215.859985" textLength="2.169123" font-size="8px">t</text>
<text x="73.376709" y="189.519958" textLength="4.338245" font-size="8px">a</text>
<text x="34.438629" y="171.939941" textLength="4.338245" font-size="8px">_</text>
<text x="70.773392" y="348.280304" textLength="2.169123" font-size="8px"> </text>
<text x="343.319946" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="35.873260" y="338.921021" textLength="5.633477" font-size="8px">U</text>
<text x="38.531509" y="348.280304" textLength="7.802600" font-size="8px">—</text>
<text x="101.237823" y="198.279968" textLength="2.169123" font-size="8px">t</text>
<text x="42.840088" y="198.279968" textLength="2.169123" font-size="8px"> </text>
<text x="88.518051" y="348.280304" textLength="4.338245" font-size="8px">n</text>
<text x="66.334488" y="348.280304" textLength="4.338245" font-size="8px">3</text>
<text x="355.918640" y="363.699982" textLength="3.253656" font-size="8px">2</text>
<text x="57.992722" y="329.500000" textLength="2.169123" font-size="8px"> </text>
<text x="79.745193" y="171.939941" textLength="4.338245" font-size="8px">2</text>
<text x="80.035873" y="215.859985" textLength="2.598266" font-size="8px">r</text>
<text x="52.801773" y="310.660797" textLength="2.169123" font-size="8px"> </text>
<text x="142.317291" y="33.279968" textLength="3.253656" font-size="8px">4</text>
<text x="44.994766" y="189.519958" textLength="5.633477" font-size="8px">D</text>
<text x="61.137314" y="320.080872" textLength="2.169123" font-size="8px"> </text>
<text x="68.911697" y="329.500000" textLength="2.598266" font-size="8px">-</text>
<text x="57.540558" y="171.939941" textLength="5.204334" font-size="8px">S</text>
<text x="75.134277" y="290.920258" textLength="4.338245" font-size="8px">d</text>
<text x="14.460075" y="171.939941" textLength="5.204334" font-size="8px">S</text>
<text x="143.752701" y="282.460632" textLength="5.750516" font-size="8px">®</text>
<text x="352.671997" y="363.699982" textLength="3.253656" font-size="8px">5</text>
<text x="14.099998" y="136.719971" textLength="4.767388" font-size="8px">T</text>
<text x="38.771408" y="180.760010" textLength="4.338245" font-size="8px">1</text>
<text x="130.269073" y="300.399994" textLength="4.338245" font-size="8px">n</text>
<text x="48.455627" y="290.920258" textLength="4.338245" font-size="8px">a</text>
<text x="77.583878" y="171.939941" textLength="2.169123" font-size="8px">.</text>
<text x="123.228775" y="282.460632" textLength="4.338245" font-size="8px">d</text>
<text x="45.311539" y="180.760010" textLength="7.802600" font-size="8px">—</text>
<text x="163.045425" y="282.460632" textLength="3.901300" font-size="8px">c</text>
<text x="218.398941" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="35.046860" y="329.500000" textLength="4.338245" font-size="8px">6</text>
<text x="99.343521" y="273.100647" textLength="2.169123" font-size="8px"> </text>
<text x="107.984802" y="207.039978" textLength="4.338245" font-size="8px">a</text>
<text x="43.279388" y="290.920258" textLength="5.204334" font-size="8px">S</text>
<text x="79.595932" y="273.100647" textLength="4.338245" font-size="8px">o</text>
<text x="19.739853" y="300.399994" textLength="6.499566" font-size="8px">M</text>
<text x="186.417740" y="33.279968" textLength="3.253656" font-size="8px">9</text>
<text x="14.399994" y="154.419983" textLength="6.499566" font-size="8px">M</text>
<text x="19.768707" y="310.660797" textLength="5.204334" font-size="8px">S</text>
<text x="121.497986" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="66.881470" y="233.380005" textLength="2.169123" font-size="8px"> </text>
<text x="68.037918" y="338.921021" textLength="7.802600" font-size="8px">—</text>
<text x="42.357910" y="224.619995" textLength="5.633477" font-size="8px">H</text>
<text x="31.382095" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="35.400467" y="163.179993" textLength="5.633477" font-size="8px">C</text>
<text x="127.602905" y="282.460632" textLength="5.204334" font-size="8px">S</text>
<text x="30.608749" y="254.380005" textLength="4.767388" font-size="8px">T</text>
<text x="27.001205" y="154.419983" textLength="5.204334" font-size="8px">V</text>
<text x="81.320267" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="41.544968" y="338.921021" textLength="4.338245" font-size="8px">L</text>
<text x="24.486038" y="263.620483" textLength="5.204334" font-size="8px">S</text>
<text x="90.333740" y="263.620483" textLength="2.169123" font-size="8px">t</text>
<text x="91.289551" y="290.920258" textLength="3.901300" font-size="8px">x</text>
<text x="45.001511" y="310.660797" textLength="7.802600" font-size="8px">—</text>
<text x="113.452957" y="338.921021" textLength="2.169123" font-size="8px"> </text>
<text x="53.340958" y="300.399994" textLength="2.169123" font-size="8px">t</text>
<text x="142.006470" y="207.039978" textLength="5.633477" font-size="8px">R</text>
<text x="98.595108" y="348.280304" textLength="4.338245" font-size="8px">o</text>
<text x="96.856689" y="348.280304" textLength="1.732177" font-size="8px">i</text>
<text x="63.715286" y="338.921021" textLength="2.169123" font-size="8px"> </text>
<text x="99.444168" y="338.921021" textLength="1.732177" font-size="8px">l</text>
<text x="36.370193" y="348.280304" textLength="2.169123" font-size="8px"> </text>
<text x="24.958984" y="338.921021" textLength="4.338245" font-size="8px">L</text>
<text x="79.513092" y="290.920258" textLength="4.338245" font-size="8px">e</text>
<text x="87.805771" y="282.460632" textLength="4.338245" font-size="8px">n</text>
<text x="81.760254" y="233.380005" textLength="2.169123" font-size="8px">t</text>
<text x="41.592453" y="263.620483" textLength="7.802600" font-size="8px">—</text>
<text x="87.409424" y="300.399994" textLength="1.732177" font-size="8px">i</text>
<text x="102.435699" y="320.080872" textLength="6.499566" font-size="8px">M</text>
<text x="67.677689" y="189.519958" textLength="5.633477" font-size="8px">C</text>
<text x="29.830048" y="348.280304" textLength="4.338245" font-size="8px">3</text>
<text x="62.702759" y="171.939941" textLength="5.204334" font-size="8px">S</text>
<text x="103.858032" y="33.279968" textLength="3.253656" font-size="8px">2</text>
<text x="57.654221" y="338.921021" textLength="6.070423" font-size="8px">Q</text>
<text x="64.653030" y="329.500000" textLength="4.338245" font-size="8px">4</text>
<text x="73.144974" y="171.939941" textLength="4.338245" font-size="8px">4</text>
<text x="355.739990" y="33.279968" textLength="3.253656" font-size="8px">0</text>
<text x="115.817108" y="300.399994" textLength="4.338245" font-size="8px">n</text>
<text x="43.150223" y="180.760010" textLength="2.169123" font-size="8px"> </text>
<text x="138.345596" y="338.921021" textLength="1.732177" font-size="8px">i</text>
<text x="63.332825" y="198.279968" textLength="4.338245" font-size="8px">e</text>
<text x="62.416824" y="254.380005" textLength="4.338245" font-size="8px">1</text>
<text x="77.874557" y="215.859985" textLength="2.169123" font-size="8px">t</text>
<text x="118.505829" y="207.039978" textLength="1.732177" font-size="8px">l</text>
<text x="14.099998" y="254.380005" textLength="5.633477" font-size="8px">C</text>
<text x="51.236496" y="136.719971" textLength="1.732177" font-size="8px">l</text>
<text x="38.049301" y="254.380005" textLength="2.169123" font-size="8px">I</text>
<text x="71.611374" y="198.279968" textLength="3.901300" font-size="8px">s</text>
<text x="123.065567" y="198.279968" textLength="1.732177" font-size="8px">i</text>
<text x="46.867813" y="136.719971" textLength="4.338245" font-size="8px">d</text>
<text x="24.057678" y="136.719971" textLength="5.633477" font-size="8px">C</text>
<text x="34.458130" y="180.760010" textLength="4.338245" font-size="8px">_</text>
<text x="27.898911" y="92.859985" textLength="5.633477" font-size="8px">C</text>
<text x="112.360504" y="207.039978" textLength="4.338245" font-size="8px">b</text>
<text x="74.667679" y="263.620483" textLength="4.338245" font-size="8px">3</text>
<text x="38.817444" y="171.939941" textLength="4.338245" font-size="8px">2</text>
<text x="24.799301" y="180.760010" textLength="5.204334" font-size="8px">E</text>
<text x="52.354568" y="198.279968" textLength="2.598266" font-size="8px">r</text>
<text x="90.739594" y="310.660797" textLength="2.169123" font-size="8px">f</text>
<text x="101.145142" y="273.100647" textLength="4.338245" font-size="8px">2</text>
<text x="65.876602" y="338.921021" textLength="2.169123" font-size="8px"> </text>
<text x="204.057693" y="33.279968" textLength="3.253656" font-size="8px">7</text>
<text x="41.153564" y="110.439880" textLength="5.204334" font-size="8px">V</text>
<text x="61.244873" y="215.859985" textLength="2.169123" font-size="8px"> </text>
<text x="68.634811" y="282.460632" textLength="3.901300" font-size="8px">c</text>
<text x="190.713486" y="282.460632" textLength="3.901300" font-size="8px">y</text>
<text x="105.121994" y="263.620483" textLength="1.732177" font-size="8px">i</text>
<text x="95.719101" y="233.380005" textLength="2.169123" font-size="8px"> </text>
<text x="116.736206" y="207.039978" textLength="1.732177" font-size="8px">i</text>
<text x="45.908966" y="282.460632" textLength="5.204334" font-size="8px">E</text>
<text x="97.793381" y="189.519958" textLength="3.901300" font-size="8px">c</text>
<text x="31.499924" y="300.399994" textLength="2.169123" font-size="8px"> </text>
<text x="115.749268" y="310.660797" textLength="4.338245" font-size="8px">b</text>
<text x="62.613800" y="180.760010" textLength="5.204334" font-size="8px">S</text>
<text x="74.752060" y="300.399994" textLength="4.338245" font-size="8px">a</text>
<text x="53.715347" y="263.620483" textLength="5.204334" font-size="8px">S</text>
<text x="135.004440" y="282.460632" textLength="4.338245" font-size="8px">e</text>
<text x="180.132370" y="282.460632" textLength="1.732177" font-size="8px">l</text>
<text x="101.693115" y="189.519958" textLength="3.901300" font-size="8px">c</text>
<text x="62.519821" y="233.380005" textLength="4.338245" font-size="8px">d</text>
<text x="14.099998" y="244.539978" textLength="5.204334" font-size="8px">S</text>
<text x="128.661591" y="198.279968" textLength="4.338245" font-size="8px">e</text>
<text x="65.994431" y="300.399994" textLength="2.169123" font-size="8px"> </text>
<text x="14.099998" y="207.039978" textLength="5.204334" font-size="8px">P</text>
<text x="25.599854" y="110.439880" textLength="5.204334" font-size="8px">X</text>
<text x="38.466843" y="310.660797" textLength="4.338245" font-size="8px">L</text>
<text x="97.880417" y="233.380005" textLength="5.204334" font-size="8px">A</text>
<text x="64.256012" y="300.399994" textLength="1.732177" font-size="8px">l</text>
<text x="90.175476" y="273.100647" textLength="2.169123" font-size="8px">t</text>
<text x="41.910919" y="273.100647" textLength="4.767388" font-size="8px">T</text>
<text x="38.022095" y="368.680908" textLength="4.338245" font-size="8px">e</text>
<text x="51.554031" y="263.620483" textLength="2.169123" font-size="8px"> </text>
<text x="54.959991" y="57.279968" textLength="5.204334" font-size="8px">E</text>
<text x="103.040283" y="233.380005" textLength="4.338245" font-size="8px">d</text>
<text x="100.157303" y="300.399994" textLength="5.204334" font-size="8px">E</text>
<text x="19.719437" y="254.380005" textLength="5.633477" font-size="8px">N</text>
<text x="83.482361" y="282.460632" textLength="2.169123" font-size="8px"> </text>
<text x="113.930710" y="189.519958" textLength="3.901300" font-size="8px">s</text>
<text x="116.225098" y="290.920258" textLength="4.338245" font-size="8px">n</text>
<text x="42.499130" y="136.719971" textLength="4.338245" font-size="8px">a</text>
<text x="133.497314" y="33.279968" textLength="3.253656" font-size="8px">5</text>
<text x="41.118073" y="290.920258" textLength="2.169123" font-size="8px"> </text>
<text x="85.574936" y="254.380005" textLength="4.338245" font-size="8px">e</text>
<text x="100.274384" y="320.080872" textLength="2.169123" font-size="8px">/</text>
<text x="39.419434" y="329.500000" textLength="4.338245" font-size="8px">4</text>
<text x="47.994476" y="329.500000" textLength="7.802600" font-size="8px">—</text>
<text x="124.737015" y="33.279968" textLength="3.253656" font-size="8px">6</text>
<text x="70.899933" y="273.100647" textLength="2.169123" font-size="8px"> </text>
<text x="48.902847" y="300.399994" textLength="1.732177" font-size="8px">i</text>
<text x="86.277756" y="33.279968" textLength="3.253656" font-size="8px">3</text>
<text x="24.569534" y="329.500000" textLength="5.204334" font-size="8px">E</text>
<text x="62.875610" y="224.619995" textLength="5.204334" font-size="8px">B</text>
<text x="253.619156" y="33.279968" textLength="3.253656" font-size="8px">1</text>
<text x="25.008148" y="310.660797" textLength="2.598266" font-size="8px">-</text>
<text x="33.784515" y="282.460632" textLength="7.802600" font-size="8px">—</text>
<text x="33.227402" y="310.660797" textLength="5.204334" font-size="8px">P</text>
<text x="84.139236" y="348.280304" textLength="4.338245" font-size="8px">e</text>
<text x="49.392715" y="263.620483" textLength="2.169123" font-size="8px"> </text>
<text x="105.641769" y="310.660797" textLength="5.633477" font-size="8px">D</text>
<text x="103.545898" y="207.039978" textLength="4.338245" font-size="8px">p</text>
<text x="79.130875" y="300.399994" textLength="3.901300" font-size="8px">c</text>
<text x="130.246384" y="207.039978" textLength="6.499566" font-size="8px">M</text>
<text x="29.738861" y="368.680908" textLength="4.338245" font-size="8px">e</text>
<text x="171.319321" y="282.460632" textLength="4.338245" font-size="8px">n</text>
<text x="82.004440" y="348.280304" textLength="2.169123" font-size="8px">t</text>
<text x="49.794556" y="233.380005" textLength="4.338245" font-size="8px">u</text>
<text x="68.956955" y="254.380005" textLength="5.633477" font-size="8px">C</text>
<text x="51.152328" y="273.100647" textLength="4.338245" font-size="8px">e</text>
<text x="30.590393" y="189.519958" textLength="2.169123" font-size="8px"> </text>
</svg>
<figcaption>Figure 3-7.  Feature Information Returned in the ECX Register
</figcaption></figure>
```
###           Table 3-10.  Feature Information Returned in the ECX Register 


0  SSE3 ** Streaming SIMD Extensions 3 (SSE3).** A value of 1 indicates the processor supports this technology.



|**Bit # **|**Mnemonic **|**Description**|
|----------|-------------|---------------|


|1|PCLMULQDQ|**PCLMULQDQ.** A value of 1 indicates the processor supports the PCLMULQDQ instruction.|
|-|---------|---------------------------------------------------------------------------------------|
|2|DTES64|**64-bit DS Area.** A value of 1 indicates the processor supports DS area using 64-bit layout.|
|3 |MONITOR |**MONITOR/MWAIT.** A value of 1 indicates the processor supports this feature. |
|4 |DS-CPL |**CPL Qualified Debug Store.** A value of 1 indicates the processor supports the extensions to the Debug Store feature to allow for branch message storage qualified by CPL.|
|5|VMX|**Virtual Machine Extensions.** A value of 1 indicates that the processor supports this technology.|
|6|SMX|**Safer Mode Extensions. **A value of 1 indicates that the processor supports this technology. See Chapter 6, "Safer Mode Extensions Reference".|
|7 |EIST |**Enhanced Intel SpeedStep(R) technology. **A value of 1 indicates that the processor supports this technology.|
|8 |TM2 |**Thermal Monitor 2.** A value of 1 indicates whether the processor supports this technology. |
|9|SSSE3|A value of 1 indicates the presence of the Supplemental Streaming SIMD Extensions 3 (SSSE3). A value of 0 indicates the instruction extensions are not present in the processor.|
###         Table 3-10.  Feature Information Returned in the ECX Register  (Contd.)


10 CNXT-ID** L1 Context ID. **A value of 1 indicates the L1 data cache mode can be set to either adaptive mode or shared mode. A value of 0 indicates this feature is not supported. See definition of the IA32_MISC_ENABLE MSR Bit 24 (L1 Data Cache Context Mode) for details.



|**Bit # **|**Mnemonic **|**Description**|
|----------|-------------|---------------|


|11|SDBG|A value of 1 indicates the processor supports IA32_DEBUG_INTERFACE MSR for silicon debug.|
|--|----|-----------------------------------------------------------------------------------------|
|12|FMA|A value of 1 indicates the processor supports FMA extensions using YMM state.|
|13|CMPXCHG16B|**CMPXCHG16B Available. **A value of 1 indicates that the feature is available. See the "CMPXCHG8B/CMPXCHG16B--Compare and Exchange Bytes" section in this chapter for a description.|
|14|xTPR Update Control|**xTPR Update Control. **A value of 1 indicates that the processor supports changing IA32_MISC_ENABLE[bit 23]. |
|15|PDCM|**Perfmon and Debug Capability: **A value of 1 indicates the processor supports the performance and debug feature indication MSR IA32_PERF_CAPABILITIES.|
|16|Reserved|Reserved|
|17|PCID|**Process-context identifiers.** A value of 1 indicates that the processor supports PCIDs and that software may set CR4.PCIDE to 1.|
|18 |DCA| A value of 1 indicates the processor supports the ability to prefetch data from a memory mapped device.|
|19|SSE4.1|A value of 1 indicates that the processor supports SSE4.1. |
|20|SSE4.2|A value of 1 indicates that the processor supports SSE4.2. |
|21|x2APIC|A value of 1 indicates that the processor supports x2APIC feature.|
|22|MOVBE|A value of 1 indicates that the processor supports MOVBE instruction.|
|23|POPCNT|A value of 1 indicates that the processor supports the POPCNT instruction.|
|24|TSC-Deadline|A value of 1 indicates that the processor's local APIC timer supports one-shot operation using a TSC deadline value.|
|25 |AESNI|A value of 1 indicates that the processor supports the AESNI instruction extensions.|
|26|XSAVE|A value of 1 indicates that the processor supports the XSAVE/XRSTOR processor extended states feature, the XSETBV/XGETBV instructions, and XCR0.|
|27|OSXSAVE|A value of 1 indicates that the OS has set CR4.OSXSAVE[bit 18] to enable XSETBV/XGETBV instructions to access XCR0 and to support processor extended state management using XSAVE/XRSTOR.|
|28|AVX|A value of 1 indicates the processor supports the AVX instruction extensions.|
|29|F16C|A value of 1 indicates that processor supports 16-bit floating-point conversion instructions.|
|30|RDRAND|A value of 1 indicates that processor supports RDRAND instruction.|
|31 |Not Used|Always returns 0.|


 

```embed
<figure>
<svg viewBox="0 0 379.739990 405.380005">
<rect x="0.000000" y="10.000000" width="0.480000" height="392.220001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.199982" y="10.000000" width="0.479980" height="392.220001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.739990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="402.220001" width="379.739990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="6.239998" y="36.039978" width="367.260010" height="356.100006" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="268.859985" y="48.039978" width="9.000000" height="35.939999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="178.799988" y="48.039978" width="9.000000" height="35.939999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<rect x="88.860008" y="48.039978" width="9.000000" height="35.939999" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<path d="M358.799988,48.039978 L358.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M349.799988,48.039978 L349.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M340.799988,48.039978 L340.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M331.799988,48.039978 L331.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M322.859985,48.039978 L322.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M313.859985,48.039978 L313.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M304.859985,48.039978 L304.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M295.859985,48.039978 L295.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M286.859985,48.039978 L286.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M277.859985,48.039978 L277.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M268.859985,48.039978 L268.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M259.799988,48.039978 L259.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M250.799988,48.039978 L250.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M241.799988,48.039978 L241.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M232.799988,48.039978 L232.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M223.799988,48.039978 L223.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M214.799988,48.039978 L214.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M205.799988,48.039978 L205.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M196.799988,48.039978 L196.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M187.799988,48.039978 L187.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M178.799988,48.039978 L178.799988,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M169.859985,48.039978 L169.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M160.859985,48.039978 L160.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M151.859985,48.039978 L151.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M142.859985,48.039978 L142.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M133.859985,48.039978 L133.859985,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M124.859993,48.039978 L124.859993,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M115.859993,48.039978 L115.859993,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M106.859993,48.039978 L106.859993,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M97.859993,48.039978 L97.859993,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M88.859993,48.039978 L88.859993,83.979980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="79.920006" y="48.039978" width="287.880005" height="35.939999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="10.139999" y="365.259979" width="13.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(206,206,206) " stroke="black" />
<path d="M10.139999,378.759979<rect x="10.139999" y="365.259979" width="13.500000" height="13.500000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M111.359993,83.979980 L111.359993,117.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M102.359993,83.979980 L102.359993,109.539978 L79.919991,109.539978" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M84.419991,83.979980 L84.419991,100.539978 L81.179985,100.539978" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M120.359993,84.159973 L120.359993,128.019958 L64.079994,128.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M129.359985,84.159973 L129.359985,137.019958 L96.959999,137.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M138.359985,84.159973 L138.359985,146.199951 L87.959999,146.199951" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M147.359985,84.159973 L147.359985,154.599976 L106.859993,154.599976" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M156.359985,84.159973 L156.359985,164.019958 L94.079994,164.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M165.359985,84.159973 L165.359985,172.599976 L143.940002,172.599976" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M174.359985,84.159973 L174.359985,181.959961 L70.919991,181.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M192.299988,84.159973 L192.299988,189.880005 L115.859993,189.880005" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M210.299988,84.159973 L210.299988,207.819977 L124.859993,207.819977" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M219.299988,84.159973 L219.299988,217.959961 L102.359993,217.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M228.299988,84.159973 L228.299988,227.019958 L174.359985,227.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M237.299988,84.159973 L237.299988,236.019958 L131.579987,236.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M246.299988,84.159973 L246.299988,245.019958 L83.219994,245.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M255.299988,84.159973 L255.299988,254.019958 L147.359985,254.019958" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M264.359985,84.159973 L264.359985,262.359985 L124.859993,262.359985" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M282.359985,84.159973 L282.359985,271.959961 L82.079994,271.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M291.359985,84.159973 L291.359985,280.959961 L95.579994,280.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M300.359985,84.159973 L300.359985,289.959961 L124.859993,289.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M309.359985,84.159973 L309.359985,298.959961 L133.859985,298.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M318.359985,84.159973 L318.359985,307.959961 L140.579987,307.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M327.359985,84.159973 L327.359985,316.899963 L104.579994,316.899963" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M336.299988,84.159973 L336.299988,324.819977 L107.760002,324.819977" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M345.299988,84.159973 L345.299988,334.899963 L106.859993,334.899963" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M201.299988,84.159973 L201.299988,199.959961 L120.359993,199.959961" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M354.299988,84.159973 L354.299988,343.899963 L148.439972,343.899963" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M363.299988,84.159973 L363.299988,352.899963 L91.079994,352.899963" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M111.360008,117.820007 L88.860008,117.820007" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="53.107628" y="374.985840" textLength="4.442996" font-size="8px">e</text>
<text x="46.439140" y="374.985840" textLength="2.661003" font-size="8px">r</text>
<text x="37.906349" y="374.985840" textLength="3.995500" font-size="8px">s</text>
<text x="27.599556" y="374.985840" textLength="5.769502" font-size="8px">R</text>
<text x="78.108269" y="355.366333" textLength="4.442996" font-size="8px">h</text>
<text x="70.067726" y="355.366333" textLength="2.221498" font-size="8px"> </text>
<text x="58.921089" y="355.366333" textLength="2.221498" font-size="8px"> </text>
<text x="47.822395" y="355.366333" textLength="5.329997" font-size="8px">P</text>
<text x="40.788704" y="355.366333" textLength="2.221498" font-size="8px"> </text>
<text x="12.252045" y="355.366333" textLength="5.329997" font-size="8px">P</text>
<text x="144.341736" y="346.306152" textLength="2.221498" font-size="8px">t</text>
<text x="135.345459" y="346.306152" textLength="4.442996" font-size="8px">e</text>
<text x="124.135689" y="346.306152" textLength="4.442996" font-size="8px">e</text>
<text x="120.175346" y="346.306152" textLength="3.995500" font-size="8px">c</text>
<text x="115.677208" y="346.306152" textLength="4.442996" font-size="8px">n</text>
<text x="111.179070" y="346.306152" textLength="4.442996" font-size="8px">a</text>
<text x="106.680931" y="346.306152" textLength="4.442996" font-size="8px">h</text>
<text x="102.182793" y="346.306152" textLength="4.442996" font-size="8px">n</text>
<text x="90.183510" y="346.306152" textLength="4.442996" font-size="8px">e</text>
<text x="85.685371" y="346.306152" textLength="4.442996" font-size="8px">d</text>
<text x="74.527534" y="346.306152" textLength="6.656503" font-size="8px">M</text>
<text x="72.485832" y="346.306152" textLength="2.221498" font-size="8px"> </text>
<text x="67.987694" y="346.306152" textLength="4.442996" font-size="8px">6</text>
<text x="63.489555" y="346.306152" textLength="4.442996" font-size="8px">8</text>
<text x="58.991417" y="346.306152" textLength="4.442996" font-size="8px">0</text>
<text x="51.836281" y="346.306152" textLength="2.661003" font-size="8px">-</text>
<text x="50.097435" y="346.306152" textLength="1.774002" font-size="8px">l</text>
<text x="34.424690" y="346.306152" textLength="1.774002" font-size="8px">i</text>
<text x="29.084297" y="346.306152" textLength="5.329997" font-size="8px">V</text>
<text x="19.320091" y="346.306152" textLength="5.329997" font-size="8px">E</text>
<text x="90.485558" y="337.305878" textLength="4.442996" font-size="8px">o</text>
<text x="80.174767" y="337.305878" textLength="4.442996" font-size="8px">n</text>
<text x="75.675835" y="337.305878" textLength="4.442996" font-size="8px">e</text>
<text x="69.434059" y="337.305878" textLength="3.995500" font-size="8px">x</text>
<text x="51.205788" y="337.305878" textLength="1.774002" font-size="8px">i</text>
<text x="46.711647" y="337.305878" textLength="4.442996" font-size="8px">g</text>
<text x="18.420296" y="337.305878" textLength="4.442996" font-size="8px">–</text>
<text x="13.140648" y="337.305878" textLength="5.329997" font-size="8px">E</text>
<text x="7.320000" y="337.305878" textLength="5.769502" font-size="8px">D</text>
<text x="97.389717" y="328.426270" textLength="4.442996" font-size="8px">n</text>
<text x="78.083473" y="328.426270" textLength="4.442996" font-size="8px">e</text>
<text x="75.861977" y="328.426270" textLength="2.221498" font-size="8px">t</text>
<text x="64.340553" y="328.426270" textLength="2.221498" font-size="8px"> </text>
<text x="59.841621" y="328.426270" textLength="4.442996" font-size="8px">e</text>
<text x="48.802864" y="328.426270" textLength="5.329997" font-size="8px">S</text>
<text x="46.581367" y="328.426270" textLength="2.221498" font-size="8px"> </text>
<text x="42.086433" y="328.426270" textLength="4.442996" font-size="8px">e</text>
<text x="33.096565" y="328.426270" textLength="4.442996" font-size="8px">a</text>
<text x="72.289223" y="355.366333" textLength="5.769502" font-size="8px">C</text>
<text x="17.940041" y="328.426270" textLength="5.329997" font-size="8px">E</text>
<text x="12.660385" y="328.426270" textLength="5.329997" font-size="8px">S</text>
<text x="99.284370" y="319.306152" textLength="2.661003" font-size="8px">r</text>
<text x="94.787041" y="319.306152" textLength="4.442996" font-size="8px">e</text>
<text x="88.068214" y="319.306152" textLength="4.442996" font-size="8px">n</text>
<text x="42.217506" y="337.305878" textLength="4.442996" font-size="8px">g</text>
<text x="66.596413" y="319.306152" textLength="4.442996" font-size="8px">p</text>
<text x="59.885567" y="319.306152" textLength="6.656503" font-size="8px">m</text>
<text x="55.388237" y="319.306152" textLength="4.442996" font-size="8px">a</text>
<text x="53.226677" y="319.306152" textLength="2.221498" font-size="8px">t</text>
<text x="47.947029" y="319.306152" textLength="5.329997" font-size="8px">S</text>
<text x="45.725533" y="319.306152" textLength="2.221498" font-size="8px"> </text>
<text x="41.228203" y="319.306152" textLength="4.442996" font-size="8px">e</text>
<text x="33.229225" y="337.305878" textLength="4.442996" font-size="8px">b</text>
<text x="32.718590" y="319.306152" textLength="1.774002" font-size="8px">i</text>
<text x="23.360329" y="319.306152" textLength="4.442996" font-size="8px">–</text>
<text x="41.948997" y="374.985840" textLength="4.442996" font-size="8px">e</text>
<text x="17.536491" y="319.306152" textLength="5.769502" font-size="8px">C</text>
<text x="12.256844" y="319.306152" textLength="5.329997" font-size="8px">S</text>
<text x="7.320000" y="319.306152" textLength="4.882501" font-size="8px">T</text>
<text x="136.266754" y="310.365814" textLength="2.221498" font-size="8px">t</text>
<text x="120.062614" y="310.365814" textLength="4.442996" font-size="8px">p</text>
<text x="110.286430" y="310.365814" textLength="5.329997" font-size="8px">S</text>
<text x="108.064934" y="310.365814" textLength="2.221498" font-size="8px"> </text>
<text x="102.306618" y="310.365814" textLength="5.769502" font-size="8px">R</text>
<text x="84.339653" y="355.366333" textLength="4.442996" font-size="8px">p</text>
<text x="96.966240" y="310.365814" textLength="5.329997" font-size="8px">S</text>
<text x="90.306541" y="310.365814" textLength="6.656503" font-size="8px">M</text>
<text x="84.483498" y="310.365814" textLength="5.769502" font-size="8px">R</text>
<text x="74.664955" y="310.365814" textLength="2.221498" font-size="8px"> </text>
<text x="70.168419" y="310.365814" textLength="4.442996" font-size="8px">d</text>
<text x="61.175346" y="310.365814" textLength="4.442996" font-size="8px">a</text>
<text x="53.195534" y="310.365814" textLength="5.769502" font-size="8px">R</text>
<text x="25.132744" y="310.365814" textLength="4.442996" font-size="8px">–</text>
<text x="19.309700" y="310.365814" textLength="5.769502" font-size="8px">R</text>
<text x="14.030045" y="310.365814" textLength="5.329997" font-size="8px">S</text>
<text x="122.332100" y="301.365540" textLength="4.442996" font-size="8px">n</text>
<text x="116.027199" y="301.365540" textLength="1.774002" font-size="8px">i</text>
<text x="112.066856" y="301.365540" textLength="3.995500" font-size="8px">s</text>
<text x="107.579903" y="301.365540" textLength="4.442996" font-size="8px">n</text>
<text x="103.092949" y="301.365540" textLength="4.442996" font-size="8px">e</text>
<text x="100.871452" y="301.365540" textLength="2.221498" font-size="8px">t</text>
<text x="91.570717" y="301.365540" textLength="5.329997" font-size="8px">E</text>
<text x="85.369713" y="301.365540" textLength="3.995500" font-size="8px">s</text>
<text x="81.409370" y="301.365540" textLength="3.995500" font-size="8px">s</text>
<text x="74.217461" y="301.365540" textLength="2.661003" font-size="8px">r</text>
<text x="65.243553" y="301.365540" textLength="4.442996" font-size="8px">d</text>
<text x="59.903160" y="301.365540" textLength="5.329997" font-size="8px">A</text>
<text x="57.741600" y="301.365540" textLength="2.221498" font-size="8px"> </text>
<text x="47.397255" y="301.365540" textLength="3.995500" font-size="8px">c</text>
<text x="58.953850" y="310.365814" textLength="2.221498" font-size="8px"> </text>
<text x="45.579308" y="301.365540" textLength="1.774002" font-size="8px">i</text>
<text x="41.618965" y="301.365540" textLength="3.995500" font-size="8px">s</text>
<text x="33.080589" y="301.365540" textLength="4.442996" font-size="8px">h</text>
<text x="23.313988" y="301.365540" textLength="4.442996" font-size="8px">–</text>
<text x="17.940041" y="301.365540" textLength="5.329997" font-size="8px">E</text>
<text x="7.320000" y="301.365540" textLength="5.329997" font-size="8px">P</text>
<text x="118.079979" y="292.365265" textLength="4.442996" font-size="8px">n</text>
<text x="113.589043" y="292.365265" textLength="4.442996" font-size="8px">o</text>
<text x="111.767097" y="292.365265" textLength="1.774002" font-size="8px">i</text>
<text x="109.545601" y="292.365265" textLength="2.221498" font-size="8px">t</text>
<text x="85.081963" y="292.365265" textLength="2.221498" font-size="8px"> </text>
<text x="27.800941" y="301.365540" textLength="5.329997" font-size="8px">P</text>
<text x="81.121620" y="292.365265" textLength="3.995500" font-size="8px">k</text>
<text x="77.078178" y="292.365265" textLength="3.995500" font-size="8px">c</text>
<text x="72.587242" y="292.365265" textLength="4.442996" font-size="8px">e</text>
<text x="68.096306" y="292.365265" textLength="4.442996" font-size="8px">h</text>
<text x="60.117302" y="292.365265" textLength="2.221498" font-size="8px"> </text>
<text x="61.932915" y="337.305878" textLength="2.221498" font-size="8px"> </text>
<text x="55.626366" y="292.365265" textLength="4.442996" font-size="8px">e</text>
<text x="51.135429" y="292.365265" textLength="4.442996" font-size="8px">n</text>
<text x="49.313484" y="292.365265" textLength="1.774002" font-size="8px">i</text>
<text x="36.280174" y="292.365265" textLength="4.442996" font-size="8px">a</text>
<text x="87.303459" y="292.365265" textLength="5.329997" font-size="8px">E</text>
<text x="29.620476" y="292.365265" textLength="6.656503" font-size="8px">M</text>
<text x="7.320000" y="292.365265" textLength="6.656503" font-size="8px">M</text>
<text x="90.905846" y="283.364990" textLength="2.221498" font-size="8px">t</text>
<text x="86.859200" y="283.364990" textLength="3.995500" font-size="8px">s</text>
<text x="82.360268" y="283.364990" textLength="4.442996" font-size="8px">n</text>
<text x="37.723366" y="337.305878" textLength="4.442996" font-size="8px">u</text>
<text x="72.697563" y="283.364990" textLength="5.329997" font-size="8px">B</text>
<text x="35.387596" y="310.365814" textLength="5.769502" font-size="8px">D</text>
<text x="68.258568" y="283.364990" textLength="4.442996" font-size="8px">8</text>
<text x="105.054665" y="292.365265" textLength="4.442996" font-size="8px">p</text>
<text x="56.199348" y="283.364990" textLength="5.769502" font-size="8px">H</text>
<text x="45.101448" y="283.364990" textLength="5.329997" font-size="8px">X</text>
<text x="84.613762" y="337.305878" textLength="3.995500" font-size="8px">s</text>
<text x="39.821800" y="283.364990" textLength="5.329997" font-size="8px">P</text>
<text x="33.114159" y="283.364990" textLength="6.656503" font-size="8px">M</text>
<text x="22.914436" y="283.364990" textLength="4.442996" font-size="8px">–</text>
<text x="13.140648" y="283.364990" textLength="5.329997" font-size="8px">X</text>
<text x="7.320000" y="283.364990" textLength="5.769502" font-size="8px">C</text>
<text x="74.565865" y="274.364716" textLength="4.442996" font-size="8px">p</text>
<text x="60.266777" y="274.364716" textLength="2.221498" font-size="8px"> </text>
<text x="41.101158" y="346.306152" textLength="4.442996" font-size="8px">u</text>
<text x="12.660385" y="301.365540" textLength="5.329997" font-size="8px">A</text>
<text x="55.777428" y="274.364716" textLength="4.442996" font-size="8px">n</text>
<text x="51.288078" y="274.364716" textLength="4.442996" font-size="8px">o</text>
<text x="43.310661" y="274.364716" textLength="5.769502" font-size="8px">C</text>
<text x="41.089165" y="274.364716" textLength="2.221498" font-size="8px">I</text>
<text x="35.809517" y="274.364716" textLength="5.329997" font-size="8px">P</text>
<text x="30.529869" y="274.364716" textLength="5.329997" font-size="8px">A</text>
<text x="17.940041" y="274.364716" textLength="2.221498" font-size="8px">I</text>
<text x="12.660385" y="274.364716" textLength="5.329997" font-size="8px">P</text>
<text x="40.779106" y="292.365265" textLength="3.995500" font-size="8px">c</text>
<text x="7.320000" y="274.364716" textLength="5.329997" font-size="8px">A</text>
<text x="115.121788" y="265.364441" textLength="2.221498" font-size="8px">I</text>
<text x="52.944633" y="337.305878" textLength="4.442996" font-size="8px">n</text>
<text x="109.838936" y="265.364441" textLength="5.329997" font-size="8px">X</text>
<text x="104.556084" y="265.364441" textLength="5.329997" font-size="8px">E</text>
<text x="93.932838" y="265.364441" textLength="5.329997" font-size="8px">Y</text>
<text x="86.428490" y="265.364441" textLength="2.221498" font-size="8px"> </text>
<text x="81.989494" y="265.364441" textLength="4.442996" font-size="8px">d</text>
<text x="72.991631" y="265.364441" textLength="4.442996" font-size="8px">a</text>
<text x="70.770134" y="265.364441" textLength="2.221498" font-size="8px"> </text>
<text x="59.672234" y="265.364441" textLength="5.329997" font-size="8px">E</text>
<text x="54.750572" y="265.364441" textLength="4.882501" font-size="8px">T</text>
<text x="49.028221" y="265.364441" textLength="5.769502" font-size="8px">N</text>
<text x="43.745369" y="265.364441" textLength="5.329997" font-size="8px">E</text>
<text x="38.404991" y="265.364441" textLength="5.329997" font-size="8px">S</text>
<text x="33.122139" y="265.364441" textLength="5.329997" font-size="8px">Y</text>
<text x="37.591499" y="328.426270" textLength="4.442996" font-size="8px">g</text>
<text x="17.940041" y="265.364441" textLength="5.329997" font-size="8px">P</text>
<text x="142.251282" y="256.424103" textLength="3.995500" font-size="8px">s</text>
<text x="139.541534" y="256.424103" textLength="2.661003" font-size="8px">r</text>
<text x="128.867950" y="256.424103" textLength="3.995500" font-size="8px">s</text>
<text x="127.045189" y="256.424103" textLength="1.774002" font-size="8px">i</text>
<text x="118.061699" y="256.424103" textLength="4.442996" font-size="8px">e</text>
<text x="112.243446" y="256.424103" textLength="5.769502" font-size="8px">R</text>
<text x="110.081886" y="256.424103" textLength="2.221498" font-size="8px"> </text>
<text x="96.606651" y="256.424103" textLength="4.442996" font-size="8px">n</text>
<text x="86.296654" y="256.424103" textLength="5.769502" font-size="8px">R</text>
<text x="84.075157" y="256.424103" textLength="2.221498" font-size="8px"> </text>
<text x="27.816917" y="328.426270" textLength="5.329997" font-size="8px">P</text>
<text x="66.168922" y="256.424103" textLength="4.882501" font-size="8px">T</text>
<text x="64.007362" y="256.424103" textLength="2.221498" font-size="8px"> </text>
<text x="59.963112" y="256.424103" textLength="3.995500" font-size="8px">y</text>
<text x="57.253365" y="256.424103" textLength="2.661003" font-size="8px">r</text>
<text x="30.413185" y="256.424103" textLength="4.442996" font-size="8px">–</text>
<text x="122.553444" y="256.424103" textLength="4.442996" font-size="8px">g</text>
<text x="14.025246" y="256.424103" textLength="4.882501" font-size="8px">T</text>
<text x="7.320000" y="256.424103" textLength="6.656503" font-size="8px">M</text>
<text x="79.020821" y="247.423828" textLength="2.221498" font-size="8px">t</text>
<text x="77.222054" y="247.423828" textLength="1.774002" font-size="8px">i</text>
<text x="71.881660" y="247.423828" textLength="5.329997" font-size="8px">B</text>
<text x="69.720100" y="247.423828" textLength="2.221498" font-size="8px"> </text>
<text x="67.892555" y="247.423828" textLength="1.774002" font-size="8px">l</text>
<text x="63.396019" y="247.423828" textLength="4.442996" font-size="8px">a</text>
<text x="58.899483" y="247.423828" textLength="4.442996" font-size="8px">b</text>
<text x="44.201637" y="247.423828" textLength="2.221498" font-size="8px"> </text>
<text x="34.001137" y="247.423828" textLength="4.882501" font-size="8px">T</text>
<text x="28.721489" y="247.423828" textLength="5.329997" font-size="8px">P</text>
<text x="122.919365" y="238.423553" textLength="2.661003" font-size="8px">r</text>
<text x="91.068840" y="328.426270" textLength="1.774002" font-size="8px">i</text>
<text x="107.734077" y="238.423553" textLength="4.442996" font-size="8px">e</text>
<text x="105.572517" y="238.423553" textLength="2.221498" font-size="8px">t</text>
<text x="87.250755" y="238.423553" textLength="5.329997" font-size="8px">A</text>
<text x="85.029259" y="238.423553" textLength="2.221498" font-size="8px"> </text>
<text x="81.068916" y="238.423553" textLength="3.995500" font-size="8px">k</text>
<text x="72.544121" y="238.423553" textLength="4.442996" font-size="8px">e</text>
<text x="32.200783" y="139.420776" textLength="5.329997" font-size="8px">S</text>
<text x="27.835289" y="130.420532" textLength="4.442996" font-size="8px">e</text>
<text x="37.118446" y="166.421509" textLength="6.656503" font-size="8px">M</text>
<text x="12.660385" y="130.420532" textLength="5.329997" font-size="8px">S</text>
<text x="210.296478" y="44.559998" textLength="3.887607" font-size="8px">7</text>
<text x="18.956490" y="112.479980" textLength="4.442996" font-size="8px">–</text>
<text x="77.115791" y="157.421265" textLength="5.769502" font-size="8px">R</text>
<text x="65.264366" y="121.420288" textLength="4.442996" font-size="8px">d</text>
<text x="49.139320" y="121.420288" textLength="4.442996" font-size="8px">h</text>
<text x="41.205849" y="310.365814" textLength="6.656503" font-size="8px">M</text>
<text x="26.039711" y="175.361816" textLength="4.442996" font-size="8px">–</text>
<text x="135.049774" y="256.424103" textLength="4.442996" font-size="8px">e</text>
<text x="44.217659" y="121.420288" textLength="2.661003" font-size="8px">-</text>
<text x="358.920197" y="389.139984" textLength="3.332219" font-size="8px">6</text>
<text x="65.671883" y="310.365814" textLength="4.442996" font-size="8px">n</text>
<text x="81.991066" y="175.361816" textLength="4.442996" font-size="8px">o</text>
<text x="57.749626" y="193.362305" textLength="5.769502" font-size="8px">U</text>
<text x="101.098396" y="256.424103" textLength="4.442996" font-size="8px">g</text>
<text x="40.317253" y="121.420288" textLength="2.221498" font-size="8px">t</text>
<text x="77.030266" y="238.423553" textLength="3.995500" font-size="8px">c</text>
<text x="37.731361" y="184.362061" textLength="4.442996" font-size="8px">u</text>
<text x="60.099739" y="175.361816" textLength="2.221498" font-size="8px"> </text>
<text x="7.320000" y="355.366333" textLength="4.882501" font-size="8px">F</text>
<text x="22.925636" y="121.420288" textLength="4.442996" font-size="8px">–</text>
<text x="59.232735" y="157.421265" textLength="5.329997" font-size="8px">E</text>
<text x="13.135849" y="121.420288" textLength="4.882501" font-size="8px">T</text>
<text x="107.097221" y="211.422729" textLength="1.774002" font-size="8px">i</text>
<text x="55.923653" y="301.365540" textLength="1.774002" font-size="8px">l</text>
<text x="12.660385" y="247.423828" textLength="6.216998" font-size="8px">G</text>
<text x="7.320000" y="121.420288" textLength="5.769502" font-size="8px">H</text>
<text x="7.320000" y="310.365814" textLength="6.656503" font-size="8px">M</text>
<text x="22.555641" y="130.420532" textLength="5.329997" font-size="8px">S</text>
<text x="68.398430" y="112.479980" textLength="2.221498" font-size="8px">t</text>
<text x="125.455681" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="32.330223" y="130.420532" textLength="1.774002" font-size="8px">l</text>
<text x="19.832314" y="238.423553" textLength="5.329997" font-size="8px">A</text>
<text x="67.377953" y="103.479980" textLength="5.329997" font-size="8px">E</text>
<text x="23.698341" y="175.361816" textLength="2.221498" font-size="8px">I</text>
<text x="78.162621" y="166.421509" textLength="1.774002" font-size="8px">l</text>
<text x="99.273232" y="265.364441" textLength="5.329997" font-size="8px">S</text>
<text x="39.889732" y="112.479980" textLength="6.656503" font-size="8px">m</text>
<text x="37.179985" y="112.479980" textLength="2.661003" font-size="8px">r</text>
<text x="71.507729" y="220.363068" textLength="2.221498" font-size="8px">t</text>
<text x="28.196495" y="112.479980" textLength="4.442996" font-size="8px">h</text>
<text x="60.594398" y="69.279968" textLength="7.211769" font-size="8px">D</text>
<text x="87.892448" y="211.422729" textLength="3.995500" font-size="8px">x</text>
<text x="53.939995" y="69.279968" textLength="6.662396" font-size="8px">E</text>
<text x="61.957664" y="283.364990" textLength="6.216998" font-size="8px">G</text>
<text x="84.353340" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="93.353554" y="44.559998" textLength="3.887607" font-size="8px">0</text>
<text x="116.455452" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="156.355164" y="44.559998" textLength="3.887607" font-size="8px">3</text>
<text x="18.064705" y="121.420288" textLength="4.882501" font-size="8px">T</text>
<text x="215.397919" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="165.355408" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="38.496910" y="121.420288" textLength="1.774002" font-size="8px">l</text>
<text x="170.456848" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="192.295990" y="44.559998" textLength="3.887607" font-size="8px">9</text>
<text x="188.397186" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="31.803627" y="355.366333" textLength="4.442996" font-size="8px">8</text>
<text x="102.353783" y="44.559998" textLength="3.887607" font-size="8px">9</text>
<text x="93.574074" y="229.423279" textLength="4.442996" font-size="8px">e</text>
<text x="99.702385" y="202.362549" textLength="6.656503" font-size="8px">m</text>
<text x="237.297211" y="44.559998" textLength="3.887607" font-size="8px">4</text>
<text x="246.297455" y="44.559998" textLength="3.887607" font-size="8px">3</text>
<text x="242.398651" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="251.458313" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="40.728004" y="202.362549" textLength="3.995500" font-size="8px">c</text>
<text x="18.420296" y="283.364990" textLength="4.442996" font-size="8px">8</text>
<text x="46.101921" y="256.424103" textLength="6.656503" font-size="8px">m</text>
<text x="38.539223" y="130.420532" textLength="5.329997" font-size="8px">S</text>
<text x="49.118538" y="166.421509" textLength="2.221498" font-size="8px"> </text>
<text x="101.884651" y="328.426270" textLength="3.995500" font-size="8px">s</text>
<text x="280.379059" y="44.559998" textLength="3.887607" font-size="8px">9</text>
<text x="23.340355" y="265.364441" textLength="4.442996" font-size="8px">–</text>
<text x="12.660385" y="211.422729" textLength="5.329997" font-size="8px">S</text>
<text x="40.769524" y="238.423553" textLength="3.995500" font-size="8px">c</text>
<text x="17.531700" y="355.366333" textLength="5.769502" font-size="8px">U</text>
<text x="289.379303" y="44.559998" textLength="3.887607" font-size="8px">8</text>
<text x="75.396111" y="139.420776" textLength="3.995500" font-size="8px">s</text>
<text x="42.227104" y="184.362061" textLength="4.442996" font-size="8px">g</text>
<text x="343.319885" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="78.483849" y="103.479980" textLength="2.221498" font-size="8px">.</text>
<text x="46.488670" y="103.479980" textLength="2.221498" font-size="8px">.</text>
<text x="12.660385" y="265.364441" textLength="5.329997" font-size="8px">E</text>
<text x="37.610664" y="103.479980" textLength="4.442996" font-size="8px">n</text>
<text x="27.832085" y="103.479980" textLength="5.329997" font-size="8px">P</text>
<text x="79.990166" y="166.421509" textLength="4.442996" font-size="8px">o</text>
<text x="43.818871" y="130.420532" textLength="4.442996" font-size="8px">n</text>
<text x="27.857658" y="319.306152" textLength="4.882501" font-size="8px">T</text>
<text x="132.990479" y="229.423279" textLength="2.221498" font-size="8px"> </text>
<text x="48.313805" y="130.420532" textLength="4.442996" font-size="8px">o</text>
<text x="12.653191" y="103.479980" textLength="5.329997" font-size="8px">B</text>
<text x="69.730507" y="301.365540" textLength="4.442996" font-size="8px">d</text>
<text x="68.057976" y="238.423553" textLength="4.442996" font-size="8px">h</text>
<text x="365.279999" y="44.559998" textLength="3.887607" font-size="8px">0</text>
<text x="43.721382" y="148.421021" textLength="2.221498" font-size="8px"> </text>
<text x="7.320000" y="103.479980" textLength="5.329997" font-size="8px">P</text>
<text x="92.894783" y="328.426270" textLength="4.442996" font-size="8px">o</text>
<text x="69.169548" y="166.421509" textLength="4.442996" font-size="8px">n</text>
<text x="324.419525" y="44.559998" textLength="3.887607" font-size="8px">4</text>
<text x="32.688240" y="112.479980" textLength="4.442996" font-size="8px">e</text>
<text x="368.817963" y="389.139984" textLength="3.332219" font-size="8px">3</text>
<text x="46.917824" y="121.420288" textLength="2.221498" font-size="8px">t</text>
<text x="350.641205" y="389.139984" textLength="4.992335" font-size="8px">M</text>
<text x="54.402946" y="247.423828" textLength="4.442996" font-size="8px">o</text>
<text x="38.053398" y="157.421265" textLength="5.329997" font-size="8px">X</text>
<text x="27.839287" y="265.364441" textLength="5.329997" font-size="8px">S</text>
<text x="91.351723" y="175.361816" textLength="4.442996" font-size="8px">a</text>
<text x="135.136780" y="175.361816" textLength="2.221498" font-size="8px">t</text>
<text x="111.354012" y="44.559998" textLength="3.887607" font-size="8px">8</text>
<text x="56.385551" y="184.362061" textLength="4.442996" font-size="8px">o</text>
<text x="62.083931" y="112.479980" textLength="4.442996" font-size="8px">n</text>
<text x="103.054573" y="211.422729" textLength="3.995500" font-size="8px">s</text>
<text x="92.565544" y="319.306152" textLength="2.221498" font-size="8px">t</text>
<text x="17.940041" y="139.420776" textLength="5.329997" font-size="8px">E</text>
<text x="23.333153" y="103.479980" textLength="4.442996" font-size="8px">–</text>
<text x="45.599297" y="346.306152" textLength="4.442996" font-size="8px">a</text>
<text x="138.354706" y="44.559998" textLength="3.887607" font-size="8px">5</text>
<text x="260.458557" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="12.660385" y="148.421021" textLength="5.329997" font-size="8px">S</text>
<text x="67.798180" y="69.279968" textLength="6.662396" font-size="8px">X</text>
<text x="307.319641" y="44.559998" textLength="3.887607" font-size="8px">6</text>
<text x="87.021400" y="328.426270" textLength="3.995500" font-size="8px">s</text>
<text x="13.142242" y="184.362061" textLength="5.329997" font-size="8px">S</text>
<text x="12.660385" y="346.306152" textLength="6.656503" font-size="8px">M</text>
<text x="23.350746" y="355.366333" textLength="4.442996" font-size="8px">–</text>
<text x="62.261299" y="175.361816" textLength="6.656503" font-size="8px">M</text>
<text x="7.320000" y="112.479980" textLength="4.882501" font-size="8px">T</text>
<text x="161.449585" y="229.423279" textLength="1.774002" font-size="8px">i</text>
<text x="37.579521" y="301.365540" textLength="3.995500" font-size="8px">y</text>
<text x="42.820808" y="139.420776" textLength="5.329997" font-size="8px">E</text>
<text x="76.386253" y="202.362549" textLength="2.661003" font-size="8px">r</text>
<text x="80.514671" y="44.559998" textLength="3.887607" font-size="8px">3</text>
<text x="75.118858" y="112.479980" textLength="2.661003" font-size="8px">r</text>
<text x="53.578316" y="121.420288" textLength="2.661003" font-size="8px">r</text>
<text x="95.230568" y="238.423553" textLength="3.995500" font-size="8px">c</text>
<text x="183.295746" y="44.559998" textLength="3.887607" font-size="8px">0</text>
<text x="85.034889" y="229.423279" textLength="4.442996" font-size="8px">o</text>
<text x="27.304710" y="121.420288" textLength="6.656503" font-size="8px">M</text>
<text x="81.187233" y="346.306152" textLength="4.442996" font-size="8px">o</text>
<text x="224.398163" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="50.381096" y="283.364990" textLength="5.769502" font-size="8px">C</text>
<text x="62.488274" y="274.364716" textLength="5.769502" font-size="8px">C</text>
<text x="7.320000" y="220.363068" textLength="5.329997" font-size="8px">P</text>
<text x="107.046028" y="175.361816" textLength="5.769502" font-size="8px">C</text>
<text x="150.760040" y="229.423279" textLength="4.442996" font-size="8px">u</text>
<text x="133.552216" y="310.365814" textLength="2.661003" font-size="8px">r</text>
<text x="57.597771" y="374.985840" textLength="4.442996" font-size="8px">d</text>
<text x="24.705223" y="346.306152" textLength="4.442996" font-size="8px">–</text>
<text x="106.405235" y="202.362549" textLength="4.442996" font-size="8px">b</text>
<text x="82.600807" y="355.366333" textLength="1.774002" font-size="8px">i</text>
<text x="62.245323" y="238.423553" textLength="5.769502" font-size="8px">C</text>
<text x="219.296722" y="44.559998" textLength="3.887607" font-size="8px">6</text>
<text x="71.093742" y="319.306152" textLength="2.221498" font-size="8px"> </text>
<text x="52.604179" y="247.423828" textLength="1.774002" font-size="8px">l</text>
<text x="57.303673" y="130.420532" textLength="4.442996" font-size="8px">p</text>
<text x="23.335564" y="112.479980" textLength="4.882501" font-size="8px">T</text>
<text x="60.775017" y="121.420288" textLength="4.442996" font-size="8px">a</text>
<text x="48.710991" y="112.479980" textLength="2.221498" font-size="8px"> </text>
<text x="65.575188" y="355.366333" textLength="4.442996" font-size="8px">n</text>
<text x="104.485802" y="193.362305" textLength="4.442996" font-size="8px">o</text>
<text x="174.355652" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="26.040520" y="274.364716" textLength="4.442996" font-size="8px">–</text>
<text x="83.125847" y="193.362305" textLength="3.995500" font-size="8px">s</text>
<text x="35.005623" y="211.422729" textLength="2.221498" font-size="8px"> </text>
<text x="93.178490" y="283.364990" textLength="2.221498" font-size="8px">.</text>
<text x="22.558846" y="193.362305" textLength="5.329997" font-size="8px">S</text>
<text x="64.386177" y="202.362549" textLength="2.221498" font-size="8px"> </text>
<text x="69.753716" y="121.420288" textLength="1.774002" font-size="8px">i</text>
<text x="94.681648" y="346.306152" textLength="2.221498" font-size="8px"> </text>
<text x="47.915886" y="310.365814" textLength="5.329997" font-size="8px">S</text>
<text x="34.904930" y="256.424103" textLength="6.656503" font-size="8px">M</text>
<text x="273.357605" y="44.559998" textLength="3.887607" font-size="8px">0</text>
<text x="23.324379" y="148.421021" textLength="4.442996" font-size="8px">–</text>
<text x="76.886452" y="310.365814" textLength="7.543504" font-size="8px">W</text>
<text x="41.597404" y="211.422729" textLength="2.221498" font-size="8px"> </text>
<text x="126.819054" y="301.365540" textLength="3.995500" font-size="8px">s</text>
<text x="352.320129" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="269.458801" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="140.007294" y="175.361816" textLength="1.774002" font-size="8px">l</text>
<text x="28.739891" y="157.421265" textLength="4.442996" font-size="8px">–</text>
<text x="78.161034" y="220.363068" textLength="2.221498" font-size="8px"> </text>
<text x="72.745522" y="274.364716" textLength="1.774002" font-size="8px">i</text>
<text x="56.285667" y="121.420288" textLength="4.442996" font-size="8px">e</text>
<text x="42.538750" y="121.420288" textLength="1.774002" font-size="8px">i</text>
<text x="65.096519" y="103.479980" textLength="2.221498" font-size="8px"> </text>
<text x="62.875023" y="103.479980" textLength="2.221498" font-size="8px">.</text>
<text x="66.575676" y="112.479980" textLength="1.774002" font-size="8px">i</text>
<text x="58.037285" y="211.422729" textLength="4.442996" font-size="8px">e</text>
<text x="92.049416" y="193.362305" textLength="4.442996" font-size="8px">u</text>
<text x="19.835503" y="229.423279" textLength="6.216998" font-size="8px">O</text>
<text x="18.060707" y="130.420532" textLength="4.442996" font-size="8px">–</text>
<text x="60.881294" y="184.362061" textLength="2.661003" font-size="8px">r</text>
<text x="97.532814" y="229.423279" textLength="2.221498" font-size="8px">/</text>
<text x="127.097832" y="175.361816" textLength="2.221498" font-size="8px"> </text>
<text x="66.914482" y="157.421265" textLength="4.882501" font-size="8px">F</text>
<text x="7.320000" y="175.361816" textLength="5.329997" font-size="8px">A</text>
<text x="129.354462" y="44.559998" textLength="3.887607" font-size="8px">6</text>
<text x="44.688347" y="202.362549" textLength="4.442996" font-size="8px">e</text>
<text x="88.660408" y="337.305878" textLength="1.774002" font-size="8px">i</text>
<text x="108.918373" y="211.422729" textLength="4.442996" font-size="8px">o</text>
<text x="110.120247" y="229.423279" textLength="6.656503" font-size="8px">m</text>
<text x="41.624580" y="220.363068" textLength="4.442996" font-size="8px">e</text>
<text x="71.841698" y="328.426270" textLength="3.995500" font-size="8px">x</text>
<text x="362.219452" y="389.139984" textLength="3.332219" font-size="8px">5</text>
<text x="41.598198" y="229.423279" textLength="4.442996" font-size="8px">o</text>
<text x="147.354919" y="44.559998" textLength="3.887607" font-size="8px">4</text>
<text x="99.874184" y="229.423279" textLength="5.769502" font-size="8px">C</text>
<text x="18.841423" y="247.423828" textLength="5.329997" font-size="8px">E</text>
<text x="7.320000" y="265.364441" textLength="5.329997" font-size="8px">S</text>
<text x="27.821709" y="139.420776" textLength="4.442996" font-size="8px">–</text>
<text x="58.914680" y="103.479980" textLength="3.995500" font-size="8px">k</text>
<text x="72.711143" y="103.479980" textLength="5.769502" font-size="8px">N</text>
<text x="123.137489" y="175.361816" textLength="3.995500" font-size="8px">k</text>
<text x="20.161537" y="274.364716" textLength="5.769502" font-size="8px">C</text>
<text x="24.224953" y="247.423828" textLength="4.442996" font-size="8px">–</text>
<text x="80.391304" y="211.422729" textLength="2.221498" font-size="8px"> </text>
<text x="129.055695" y="310.365814" textLength="4.442996" font-size="8px">o</text>
<text x="28.735085" y="337.305878" textLength="4.442996" font-size="8px">e</text>
<text x="60.701485" y="220.363068" textLength="1.774002" font-size="8px">i</text>
<text x="50.573692" y="229.423279" textLength="4.442996" font-size="8px">d</text>
<text x="355.620941" y="389.139984" textLength="3.332219" font-size="8px">1</text>
<text x="143.456146" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="66.399834" y="148.421021" textLength="3.995500" font-size="8px">s</text>
<text x="66.562050" y="328.426270" textLength="5.329997" font-size="8px">E</text>
<text x="7.320000" y="130.420532" textLength="5.329997" font-size="8px">S</text>
<text x="90.179451" y="139.420776" textLength="3.995500" font-size="8px">s</text>
<text x="50.934868" y="103.479980" textLength="5.329997" font-size="8px">B</text>
<text x="29.610893" y="238.423553" textLength="6.656503" font-size="8px">M</text>
<text x="94.979698" y="337.305878" textLength="4.442996" font-size="8px">n</text>
<text x="12.251244" y="112.479980" textLength="6.656503" font-size="8px">M</text>
<text x="228.296967" y="44.559998" textLength="3.887607" font-size="8px">5</text>
<text x="96.911110" y="301.365540" textLength="3.995500" font-size="8px">x</text>
<text x="23.321983" y="328.426270" textLength="4.442996" font-size="8px">–</text>
<text x="120.354240" y="44.559998" textLength="3.887607" font-size="8px">7</text>
<text x="68.246590" y="274.364716" textLength="4.442996" font-size="8px">h</text>
<text x="38.921989" y="247.423828" textLength="5.329997" font-size="8px">E</text>
<text x="70.619926" y="112.479980" textLength="4.442996" font-size="8px">o</text>
<text x="17.940041" y="202.362549" textLength="5.769502" font-size="8px">N</text>
<text x="48.612694" y="157.421265" textLength="5.329997" font-size="8px">A</text>
<text x="54.082512" y="328.426270" textLength="1.774002" font-size="8px">i</text>
<text x="92.530403" y="238.423553" textLength="2.661003" font-size="8px">r</text>
<text x="43.778145" y="166.421509" textLength="5.329997" font-size="8px">X</text>
<text x="7.320000" y="346.306152" textLength="5.329997" font-size="8px">V</text>
<text x="34.156166" y="130.420532" textLength="2.221498" font-size="8px">f</text>
<text x="12.660385" y="175.361816" textLength="5.769502" font-size="8px">C</text>
<text x="73.454338" y="337.305878" textLength="2.221498" font-size="8px">t</text>
<text x="71.574059" y="121.420288" textLength="4.442996" font-size="8px">n</text>
<text x="81.183174" y="148.421021" textLength="3.995500" font-size="8px">s</text>
<text x="43.333046" y="157.421265" textLength="5.329997" font-size="8px">S</text>
<text x="42.109596" y="103.479980" textLength="4.442996" font-size="8px">d</text>
<text x="79.073555" y="319.306152" textLength="4.442996" font-size="8px">o</text>
<text x="116.258873" y="238.423553" textLength="2.221498" font-size="8px">t</text>
<text x="125.623512" y="238.423553" textLength="4.442996" font-size="8px">e</text>
<text x="36.317726" y="130.420532" textLength="2.221498" font-size="8px"> </text>
<text x="100.333595" y="175.361816" textLength="4.442996" font-size="8px">d</text>
<text x="89.752769" y="220.363068" textLength="4.442996" font-size="8px">b</text>
<text x="14.019653" y="238.423553" textLength="5.769502" font-size="8px">C</text>
<text x="48.884407" y="184.362061" textLength="5.329997" font-size="8px">S</text>
<text x="134.455902" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="255.357117" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="38.939598" y="346.306152" textLength="2.221498" font-size="8px">t</text>
<text x="233.398407" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="34.007561" y="121.420288" textLength="4.442996" font-size="8px">u</text>
<text x="152.456360" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="125.796989" y="229.423279" textLength="2.661003" font-size="8px">r</text>
<text x="345.899994" y="389.139984" textLength="4.662709" font-size="8px">O</text>
<text x="36.296165" y="355.366333" textLength="4.442996" font-size="8px">7</text>
<text x="46.489494" y="112.479980" textLength="2.221498" font-size="8px">.</text>
<text x="95.842659" y="175.361816" textLength="4.442996" font-size="8px">n</text>
<text x="17.932838" y="103.479980" textLength="5.329997" font-size="8px">E</text>
<text x="89.454765" y="44.559998" textLength="3.887607" font-size="8px">3</text>
<text x="76.063408" y="121.420288" textLength="4.442996" font-size="8px">g</text>
<text x="35.391579" y="175.361816" textLength="4.442996" font-size="8px">h</text>
<text x="99.269218" y="238.423553" textLength="4.442996" font-size="8px">h</text>
<text x="33.416206" y="374.985840" textLength="4.442996" font-size="8px">e</text>
<text x="26.019737" y="166.421509" textLength="4.442996" font-size="8px">–</text>
<text x="92.114906" y="256.424103" textLength="4.442996" font-size="8px">a</text>
<text x="53.598289" y="211.422729" textLength="4.442996" font-size="8px">g</text>
<text x="7.320000" y="139.420776" textLength="5.329997" font-size="8px">S</text>
<text x="12.660385" y="139.420776" textLength="5.329997" font-size="8px">S</text>
<text x="23.324379" y="139.420776" textLength="4.442996" font-size="8px">2</text>
<text x="44.822548" y="292.365265" textLength="4.442996" font-size="8px">h</text>
<text x="37.480431" y="139.420776" textLength="5.329997" font-size="8px">S</text>
<text x="7.320000" y="211.422729" textLength="5.329997" font-size="8px">P</text>
<text x="42.890343" y="355.366333" textLength="4.882501" font-size="8px">F</text>
<text x="64.757713" y="211.422729" textLength="5.329997" font-size="8px">S</text>
<text x="49.294319" y="238.423553" textLength="1.774002" font-size="8px">i</text>
<text x="48.281059" y="139.420776" textLength="4.442996" font-size="8px">2</text>
<text x="52.778389" y="139.420776" textLength="2.221498" font-size="8px"> </text>
<text x="117.343285" y="265.364441" textLength="4.882501" font-size="8px">T</text>
<text x="105.632500" y="229.423279" textLength="4.442996" font-size="8px">o</text>
<text x="54.880028" y="139.420776" textLength="5.329997" font-size="8px">E</text>
<text x="56.214516" y="103.479980" textLength="2.661003" font-size="8px">r</text>
<text x="107.455223" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="27.300697" y="220.363068" textLength="5.329997" font-size="8px">P</text>
<text x="60.159676" y="139.420776" textLength="3.995500" font-size="8px">x</text>
<text x="64.179955" y="139.420776" textLength="2.221498" font-size="8px">t</text>
<text x="66.401451" y="139.420776" textLength="4.442996" font-size="8px">e</text>
<text x="79.356453" y="139.420776" textLength="1.774002" font-size="8px">i</text>
<text x="81.184792" y="139.420776" textLength="4.442996" font-size="8px">o</text>
<text x="85.682121" y="139.420776" textLength="4.442996" font-size="8px">n</text>
<text x="49.147285" y="374.985840" textLength="3.995500" font-size="8px">v</text>
<text x="96.603386" y="292.365265" textLength="3.995500" font-size="8px">c</text>
<text x="62.278862" y="292.365265" textLength="5.769502" font-size="8px">C</text>
<text x="7.320000" y="148.421021" textLength="5.329997" font-size="8px">S</text>
<text x="264.357361" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="17.940041" y="148.421021" textLength="5.329997" font-size="8px">E</text>
<text x="33.101357" y="148.421021" textLength="5.329997" font-size="8px">S</text>
<text x="94.244514" y="220.363068" textLength="1.774002" font-size="8px">l</text>
<text x="148.054291" y="229.423279" textLength="2.661003" font-size="8px">r</text>
<text x="38.381004" y="148.421021" textLength="5.329997" font-size="8px">E</text>
<text x="55.183678" y="148.421021" textLength="2.221498" font-size="8px">t</text>
<text x="57.405174" y="148.421021" textLength="4.442996" font-size="8px">e</text>
<text x="334.319641" y="44.559998" textLength="3.887607" font-size="8px">3</text>
<text x="45.882942" y="148.421021" textLength="5.329997" font-size="8px">E</text>
<text x="61.902504" y="148.421021" textLength="4.442996" font-size="8px">n</text>
<text x="112.804344" y="175.361816" textLength="1.774002" font-size="8px">l</text>
<text x="70.360176" y="148.421021" textLength="1.774002" font-size="8px">i</text>
<text x="72.188515" y="148.421021" textLength="4.442996" font-size="8px">o</text>
<text x="197.397430" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="201.296234" y="44.559998" textLength="3.887607" font-size="8px">8</text>
<text x="104.824532" y="175.361816" textLength="2.221498" font-size="8px"> </text>
<text x="27.838493" y="193.362305" textLength="5.769502" font-size="8px">H</text>
<text x="76.685844" y="148.421021" textLength="4.442996" font-size="8px">n</text>
<text x="64.951881" y="265.364441" textLength="5.769502" font-size="8px">R</text>
<text x="78.626915" y="193.362305" textLength="4.442996" font-size="8px">n</text>
<text x="115.383934" y="202.362549" textLength="2.661003" font-size="8px">r</text>
<text x="75.144417" y="256.424103" textLength="4.442996" font-size="8px">p</text>
<text x="52.761620" y="256.424103" textLength="4.442996" font-size="8px">o</text>
<text x="62.536217" y="211.422729" textLength="2.221498" font-size="8px"> </text>
<text x="12.240860" y="157.421265" textLength="5.329997" font-size="8px">X</text>
<text x="17.520515" y="157.421265" textLength="5.329997" font-size="8px">S</text>
<text x="141.872467" y="229.423279" textLength="3.995500" font-size="8px">s</text>
<text x="22.860909" y="157.421265" textLength="5.769502" font-size="8px">R</text>
<text x="33.132545" y="157.421265" textLength="4.882501" font-size="8px">F</text>
<text x="51.436699" y="301.365540" textLength="4.442996" font-size="8px">a</text>
<text x="64.692986" y="157.421265" textLength="2.221498" font-size="8px">/</text>
<text x="71.836143" y="157.421265" textLength="5.329997" font-size="8px">X</text>
<text x="53.953087" y="157.421265" textLength="5.329997" font-size="8px">V</text>
<text x="82.934044" y="157.421265" textLength="5.329997" font-size="8px">S</text>
<text x="7.320000" y="166.421509" textLength="6.656503" font-size="8px">M</text>
<text x="30.398811" y="166.421509" textLength="6.656503" font-size="8px">M</text>
<text x="71.100166" y="256.424103" textLength="3.995500" font-size="8px">y</text>
<text x="89.445137" y="202.362549" textLength="5.769502" font-size="8px">N</text>
<text x="51.280098" y="166.421509" textLength="4.882501" font-size="8px">T</text>
<text x="46.722847" y="184.362061" textLength="2.221498" font-size="8px"> </text>
<text x="56.216133" y="166.421509" textLength="4.442996" font-size="8px">e</text>
<text x="60.712669" y="166.421509" textLength="3.995500" font-size="8px">c</text>
<text x="64.673012" y="166.421509" textLength="4.442996" font-size="8px">h</text>
<text x="48.713371" y="103.479980" textLength="2.221498" font-size="8px"> </text>
<text x="73.666084" y="166.421509" textLength="4.442996" font-size="8px">o</text>
<text x="77.977211" y="283.364990" textLength="2.221498" font-size="8px"> </text>
<text x="84.486702" y="166.421509" textLength="4.442996" font-size="8px">g</text>
<text x="88.983238" y="166.421509" textLength="3.995500" font-size="8px">y</text>
<text x="86.489998" y="175.361816" textLength="2.661003" font-size="8px">r</text>
<text x="22.921623" y="220.363068" textLength="4.442996" font-size="8px">–</text>
<text x="56.831444" y="229.423279" textLength="2.221498" font-size="8px">t</text>
<text x="18.418694" y="175.361816" textLength="5.329997" font-size="8px">P</text>
<text x="30.530647" y="175.361816" textLength="4.882501" font-size="8px">T</text>
<text x="7.320000" y="247.423828" textLength="5.329997" font-size="8px">P</text>
<text x="39.882515" y="175.361816" textLength="4.442996" font-size="8px">e</text>
<text x="61.082649" y="355.366333" textLength="4.442996" font-size="8px">o</text>
<text x="99.286812" y="157.421265" textLength="5.769502" font-size="8px">R</text>
<text x="44.373451" y="175.361816" textLength="2.661003" font-size="8px">r</text>
<text x="47.082405" y="175.361816" textLength="6.656503" font-size="8px">m</text>
<text x="55.012688" y="229.423279" textLength="1.774002" font-size="8px">i</text>
<text x="53.786858" y="175.361816" textLength="4.442996" font-size="8px">a</text>
<text x="108.984734" y="193.362305" textLength="4.442996" font-size="8px">n</text>
<text x="58.277794" y="175.361816" textLength="1.774002" font-size="8px">l</text>
<text x="68.965752" y="175.361816" textLength="4.442996" font-size="8px">o</text>
<text x="113.408516" y="211.422729" textLength="4.442996" font-size="8px">n</text>
<text x="73.456688" y="175.361816" textLength="4.442996" font-size="8px">n</text>
<text x="77.947624" y="175.361816" textLength="1.774002" font-size="8px">i</text>
<text x="53.102043" y="355.366333" textLength="5.769502" font-size="8px">U</text>
<text x="29.629280" y="310.365814" textLength="5.769502" font-size="8px">R</text>
<text x="18.956490" y="256.424103" textLength="5.769502" font-size="8px">R</text>
<text x="102.708611" y="193.362305" textLength="1.774002" font-size="8px">i</text>
<text x="14.030045" y="166.421509" textLength="6.656503" font-size="8px">M</text>
<text x="79.769569" y="175.361816" textLength="2.221498" font-size="8px">t</text>
<text x="89.130226" y="175.361816" textLength="2.221498" font-size="8px"> </text>
<text x="114.603111" y="175.361816" textLength="4.442996" font-size="8px">o</text>
<text x="88.649986" y="265.364441" textLength="5.329997" font-size="8px">S</text>
<text x="161.456604" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="119.094048" y="175.361816" textLength="3.995500" font-size="8px">c</text>
<text x="17.940041" y="220.363068" textLength="4.882501" font-size="8px">T</text>
<text x="100.563728" y="292.365265" textLength="4.442996" font-size="8px">e</text>
<text x="137.298340" y="175.361816" textLength="2.661003" font-size="8px">r</text>
<text x="18.421898" y="184.362061" textLength="4.442996" font-size="8px">–</text>
<text x="22.917641" y="184.362061" textLength="5.769502" font-size="8px">D</text>
<text x="55.779823" y="220.363068" textLength="2.221498" font-size="8px">t</text>
<text x="28.739876" y="184.362061" textLength="4.442996" font-size="8px">e</text>
<text x="60.871696" y="229.423279" textLength="4.442996" font-size="8px">o</text>
<text x="33.235619" y="184.362061" textLength="4.442996" font-size="8px">b</text>
<text x="121.309242" y="229.423279" textLength="4.442996" font-size="8px">a</text>
<text x="57.592186" y="112.479980" textLength="4.442996" font-size="8px">o</text>
<text x="54.164055" y="184.362061" textLength="2.221498" font-size="8px">t</text>
<text x="63.595039" y="184.362061" textLength="4.442996" font-size="8px">e</text>
<text x="137.373535" y="229.423279" textLength="4.442996" font-size="8px">n</text>
<text x="22.914436" y="337.305878" textLength="5.769502" font-size="8px">D</text>
<text x="88.213692" y="157.421265" textLength="4.882501" font-size="8px">T</text>
<text x="7.320000" y="193.362305" textLength="5.769502" font-size="8px">C</text>
<text x="17.940041" y="211.422729" textLength="5.329997" font-size="8px">E</text>
<text x="49.177696" y="202.362549" textLength="3.995500" font-size="8px">s</text>
<text x="13.138245" y="193.362305" textLength="4.442996" font-size="8px">L</text>
<text x="64.154411" y="337.305878" textLength="5.329997" font-size="8px">E</text>
<text x="34.517357" y="319.306152" textLength="6.656503" font-size="8px">m</text>
<text x="95.203453" y="202.362549" textLength="4.442996" font-size="8px">u</text>
<text x="17.637184" y="193.362305" textLength="4.882501" font-size="8px">F</text>
<text x="155.247772" y="229.423279" textLength="3.995500" font-size="8px">c</text>
<text x="112.220222" y="238.423553" textLength="3.995500" font-size="8px">c</text>
<text x="38.057396" y="193.362305" textLength="5.769502" font-size="8px">C</text>
<text x="71.858513" y="211.422729" textLength="3.995500" font-size="8px">z</text>
<text x="117.845146" y="301.365540" textLength="4.442996" font-size="8px">o</text>
<text x="43.830101" y="193.362305" textLength="4.442996" font-size="8px">L</text>
<text x="48.329033" y="193.362305" textLength="4.882501" font-size="8px">F</text>
<text x="92.583107" y="292.365265" textLength="3.995500" font-size="8px">x</text>
<text x="105.590141" y="256.424103" textLength="4.442996" font-size="8px">e</text>
<text x="53.250694" y="193.362305" textLength="4.442996" font-size="8px">L</text>
<text x="49.126518" y="274.364716" textLength="2.221498" font-size="8px"> </text>
<text x="63.522331" y="193.362305" textLength="5.329997" font-size="8px">S</text>
<text x="57.438774" y="337.305878" textLength="4.442996" font-size="8px">g</text>
<text x="52.808739" y="130.420532" textLength="4.442996" font-size="8px">o</text>
<text x="13.134254" y="229.423279" textLength="6.656503" font-size="8px">M</text>
<text x="68.855522" y="193.362305" textLength="5.769502" font-size="8px">H</text>
<text x="41.610176" y="256.424103" textLength="4.442996" font-size="8px">e</text>
<text x="49.099358" y="211.422729" textLength="4.442996" font-size="8px">a</text>
<text x="74.628227" y="193.362305" textLength="2.221498" font-size="8px"> </text>
<text x="98.454994" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="76.849724" y="193.362305" textLength="1.774002" font-size="8px">i</text>
<text x="298.379547" y="44.559998" textLength="3.887607" font-size="8px">7</text>
<text x="37.107262" y="211.422729" textLength="4.442996" font-size="8px">–</text>
<text x="87.124550" y="193.362305" textLength="2.221498" font-size="8px">t</text>
<text x="89.349251" y="193.362305" textLength="2.661003" font-size="8px">r</text>
<text x="96.548347" y="193.362305" textLength="3.995500" font-size="8px">c</text>
<text x="100.547050" y="193.362305" textLength="2.221498" font-size="8px">t</text>
<text x="55.597618" y="238.423553" textLength="4.442996" font-size="8px">e</text>
<text x="7.320000" y="202.362549" textLength="5.329997" font-size="8px">P</text>
<text x="70.898781" y="139.420776" textLength="4.442996" font-size="8px">n</text>
<text x="12.660385" y="202.362549" textLength="5.329997" font-size="8px">S</text>
<text x="27.843285" y="355.366333" textLength="3.995500" font-size="8px">x</text>
<text x="23.819023" y="202.362549" textLength="4.442996" font-size="8px">–</text>
<text x="7.320000" y="229.423279" textLength="5.769502" font-size="8px">C</text>
<text x="28.198097" y="202.362549" textLength="5.329997" font-size="8px">P</text>
<text x="33.538490" y="202.362549" textLength="2.661003" font-size="8px">r</text>
<text x="36.238655" y="202.362549" textLength="4.442996" font-size="8px">o</text>
<text x="7.320000" y="328.426270" textLength="5.329997" font-size="8px">P</text>
<text x="124.559151" y="310.365814" textLength="4.442996" font-size="8px">p</text>
<text x="206.397675" y="44.559998" textLength="3.887607" font-size="8px">1</text>
<text x="65.359444" y="229.423279" textLength="4.442996" font-size="8px">n</text>
<text x="61.678825" y="202.362549" textLength="2.661003" font-size="8px">r</text>
<text x="66.607674" y="202.362549" textLength="5.329997" font-size="8px">S</text>
<text x="7.320000" y="184.362061" textLength="5.769502" font-size="8px">D</text>
<text x="71.887321" y="202.362549" textLength="4.442996" font-size="8px">e</text>
<text x="54.552422" y="346.306152" textLength="4.442996" font-size="8px">8</text>
<text x="79.093605" y="202.362549" textLength="1.774002" font-size="8px">i</text>
<text x="139.843597" y="346.306152" textLength="4.442996" font-size="8px">n</text>
<text x="80.913948" y="202.362549" textLength="4.442996" font-size="8px">a</text>
<text x="98.564430" y="211.422729" textLength="4.442996" font-size="8px">n</text>
<text x="316.319885" y="44.559998" textLength="3.887607" font-size="8px">5</text>
<text x="7.320000" y="238.423553" textLength="6.656503" font-size="8px">M</text>
<text x="7.320000" y="157.421265" textLength="4.882501" font-size="8px">F</text>
<text x="85.403297" y="202.362549" textLength="1.774002" font-size="8px">l</text>
<text x="87.223640" y="202.362549" textLength="2.221498" font-size="8px"> </text>
<text x="20.740089" y="166.421509" textLength="5.329997" font-size="8px">X</text>
<text x="110.894585" y="202.362549" textLength="4.442996" font-size="8px">e</text>
<text x="128.633820" y="346.306152" textLength="6.656503" font-size="8px">m</text>
<text x="33.611198" y="193.362305" textLength="4.442996" font-size="8px">–</text>
<text x="23.317192" y="211.422729" textLength="2.661003" font-size="8px">-</text>
<text x="26.025337" y="211.422729" textLength="4.442996" font-size="8px">3</text>
<text x="118.420433" y="238.423553" textLength="4.442996" font-size="8px">u</text>
<text x="30.515480" y="211.422729" textLength="4.442996" font-size="8px">6</text>
<text x="163.268341" y="229.423279" textLength="4.442996" font-size="8px">o</text>
<text x="99.473839" y="337.305878" textLength="3.995500" font-size="8px">s</text>
<text x="82.582405" y="328.426270" textLength="4.442996" font-size="8px">n</text>
<text x="25.121544" y="292.365265" textLength="4.442996" font-size="8px">–</text>
<text x="60.083763" y="238.423553" textLength="2.221498" font-size="8px"> </text>
<text x="43.758965" y="211.422729" textLength="5.329997" font-size="8px">P</text>
<text x="93.045845" y="157.421265" textLength="6.216998" font-size="8px">O</text>
<text x="70.037361" y="211.422729" textLength="1.774002" font-size="8px">i</text>
<text x="24.714806" y="256.424103" textLength="5.769502" font-size="8px">R</text>
<text x="75.901161" y="211.422729" textLength="4.442996" font-size="8px">e</text>
<text x="79.636162" y="256.424103" textLength="4.442996" font-size="8px">e</text>
<text x="46.423134" y="247.423828" textLength="6.216998" font-size="8px">G</text>
<text x="82.612801" y="211.422729" textLength="5.329997" font-size="8px">E</text>
<text x="91.852791" y="211.422729" textLength="2.221498" font-size="8px">t</text>
<text x="25.111961" y="238.423553" textLength="4.442996" font-size="8px">–</text>
<text x="89.409157" y="301.365540" textLength="2.221498" font-size="8px"> </text>
<text x="94.074287" y="211.422729" textLength="4.442996" font-size="8px">e</text>
<text x="73.315239" y="319.306152" textLength="5.769502" font-size="8px">C</text>
<text x="33.111732" y="103.479980" textLength="4.442996" font-size="8px">e</text>
<text x="12.660385" y="220.363068" textLength="5.329997" font-size="8px">A</text>
<text x="32.641090" y="220.363068" textLength="4.442996" font-size="8px">a</text>
<text x="132.828278" y="256.424103" textLength="2.221498" font-size="8px">t</text>
<text x="37.132835" y="220.363068" textLength="4.442996" font-size="8px">g</text>
<text x="35.783943" y="229.423279" textLength="5.769502" font-size="8px">C</text>
<text x="57.179893" y="202.362549" textLength="4.442996" font-size="8px">o</text>
<text x="46.116325" y="220.363068" textLength="2.221498" font-size="8px"> </text>
<text x="48.277885" y="220.363068" textLength="5.329997" font-size="8px">A</text>
<text x="53.618263" y="220.363068" textLength="2.221498" font-size="8px">t</text>
<text x="58.001320" y="220.363068" textLength="2.661003" font-size="8px">r</text>
<text x="103.755363" y="238.423553" textLength="1.774002" font-size="8px">i</text>
<text x="62.524239" y="220.363068" textLength="4.442996" font-size="8px">b</text>
<text x="67.015984" y="220.363068" textLength="4.442996" font-size="8px">u</text>
<text x="77.490562" y="265.364441" textLength="4.442996" font-size="8px">n</text>
<text x="73.669289" y="220.363068" textLength="4.442996" font-size="8px">e</text>
<text x="55.881279" y="328.426270" textLength="3.995500" font-size="8px">z</text>
<text x="80.382530" y="220.363068" textLength="4.882501" font-size="8px">T</text>
<text x="19.841896" y="292.365265" textLength="5.329997" font-size="8px">E</text>
<text x="27.821709" y="148.421021" textLength="5.329997" font-size="8px">S</text>
<text x="85.313774" y="220.363068" textLength="4.442996" font-size="8px">a</text>
<text x="96.067268" y="220.363068" textLength="4.442996" font-size="8px">e</text>
<text x="26.016548" y="229.423279" textLength="5.329997" font-size="8px">V</text>
<text x="115.566078" y="310.365814" textLength="4.442996" font-size="8px">u</text>
<text x="76.922417" y="301.365540" textLength="4.442996" font-size="8px">e</text>
<text x="31.296196" y="229.423279" textLength="4.442996" font-size="8px">–</text>
<text x="59.052940" y="229.423279" textLength="1.774002" font-size="8px">i</text>
<text x="69.847191" y="229.423279" textLength="4.442996" font-size="8px">a</text>
<text x="80.198708" y="283.364990" textLength="2.221498" font-size="8px">I</text>
<text x="179.396942" y="44.559998" textLength="3.887607" font-size="8px">2</text>
<text x="74.334938" y="229.423279" textLength="1.774002" font-size="8px">l</text>
<text x="76.153694" y="229.423279" textLength="2.221498" font-size="8px"> </text>
<text x="78.375191" y="229.423279" textLength="6.656503" font-size="8px">M</text>
<text x="89.533821" y="229.423279" textLength="3.995500" font-size="8px">v</text>
<text x="116.821495" y="229.423279" textLength="4.442996" font-size="8px">p</text>
<text x="53.219551" y="202.362549" textLength="3.995500" font-size="8px">s</text>
<text x="128.502747" y="229.423279" textLength="4.442996" font-size="8px">e</text>
<text x="50.932487" y="112.479980" textLength="6.656503" font-size="8px">M</text>
<text x="135.152039" y="229.423279" textLength="2.221498" font-size="8px">I</text>
<text x="83.570885" y="319.306152" textLength="4.442996" font-size="8px">u</text>
<text x="44.808174" y="238.423553" textLength="4.442996" font-size="8px">h</text>
<text x="145.832794" y="229.423279" textLength="2.221498" font-size="8px">t</text>
<text x="14.024452" y="292.365265" textLength="5.769502" font-size="8px">C</text>
<text x="129.319336" y="175.361816" textLength="5.769502" font-size="8px">C</text>
<text x="159.288025" y="229.423279" textLength="2.221498" font-size="8px">t</text>
<text x="27.293510" y="283.364990" textLength="5.769502" font-size="8px">C</text>
<text x="365.518707" y="389.139984" textLength="3.332219" font-size="8px">2</text>
<text x="167.756073" y="229.423279" textLength="4.442996" font-size="8px">n</text>
<text x="36.223457" y="346.306152" textLength="2.661003" font-size="8px">r</text>
<text x="51.223335" y="148.421021" textLength="3.995500" font-size="8px">x</text>
<text x="36.270592" y="238.423553" textLength="4.442996" font-size="8px">a</text>
<text x="96.903145" y="346.306152" textLength="5.329997" font-size="8px">E</text>
<text x="46.085945" y="229.423279" textLength="4.442996" font-size="8px">n</text>
<text x="51.111473" y="238.423553" textLength="4.442996" font-size="8px">n</text>
</svg>
<figcaption>Figure 3-8.  Feature Information Returned in the EDX Register
</figcaption></figure>
```
### Table 3-11.  More on Feature Information Returned in the EDX Register


|**Bit # **|**Mnemonic **|**Description**|
|----------|-------------|---------------|
|0 |FPU |**Floating Point Unit On-Chip.** The processor contains an x87 FPU.|
|1 |VME |**Virtual 8086 Mode Enhancements.** Virtual 8086 mode enhancements, including CR4.VME for controlling the feature, CR4.PVI for protected mode virtual interrupts, software interrupt indirection, expansion of the TSS with the software indirection bitmap, and EFLAGS.VIF and EFLAGS.VIP flags. |
|2 |DE |**Debugging Extensions.** Support for I/O breakpoints, including CR4.DE for controlling the feature, and optional trapping of accesses to DR4 and DR5. |
|3 |PSE |**Page Size Extension.** Large pages of size 4 MByte are supported, including CR4.PSE for controlling the feature, the defined dirty bit in PDE (Page Directory Entries), optional reserved bit trapping in CR3, PDEs, and PTEs. |
|4 |TSC |**Time Stamp Counter.** The RDTSC instruction is supported, including CR4.TSD for controlling privilege.|
|5 |MSR |**Model Specific Registers RDMSR and WRMSR Instructions.** The RDMSR and WRMSR instructions are supported. Some of the MSRs are implementation dependent.|
|6 |PAE |**Physical Address Extension.** Physical addresses greater than 32 bits are supported: extended page table entry formats, an extra level in the page translation tables is defined, 2-MByte pages are supported instead of 4 Mbyte pages if PAE bit is 1. |
|7 |MCE |**Machine Check Exception.** Exception 18 is defined for Machine Checks, including CR4.MCE for controlling the feature. This feature does not define the model-specific implementations of machine-check error logging, reporting, and processor shutdowns. Machine Check exception handlers may have to depend on processor version to do model specific processing of the exception, or test for the presence of the Machine Check feature.|
|8 |CX8 |**CMPXCHG8B Instruction.** The compare-and-exchange 8 bytes (64 bits) instruction is supported (implicitly locked and atomic). |
|9 |APIC |**APIC On-Chip. **The processor contains an Advanced Programmable Interrupt Controller (APIC), responding to memory mapped commands in the physical address range FFFE0000H to FFFE0FFFH (by default - some processors permit the APIC to be relocated). |
|10 |Reserved |Reserved |
|11|SEP |**SYSENTER and SYSEXIT Instructions.** The SYSENTER and SYSEXIT and associated MSRs are supported. |
|12 |MTRR |**Memory Type Range Registers.** MTRRs are supported. The MTRRcap MSR contains feature bits that describe what memory types are supported, how many variable MTRRs are supported, and whether fixed MTRRs are supported. |
|13 |PGE |**Page Global Bit.** The global bit is supported in paging-structure entries that map a page, indicating TLB entries that are common to different processes and need not be flushed. The CR4.PGE bit controls this feature. |
|14 |MCA |**Machine Check Architecture.** A value of 1 indicates the Machine Check Architecture of reporting machine errors is supported. The MCG_CAP MSR contains feature bits describing how many banks of error reporting MSRs are supported. |
|15 |CMOV |**Conditional Move Instructions.** The conditional move instruction CMOV is supported. In addition, if x87 FPU is present as indicated by the CPUID.FPU feature bit, then the FCOMI and FCMOV instructions are supported |
|16 |PAT |**Page Attribute Table.** Page Attribute Table is supported. This feature augments the Memory Type Range Registers (MTRRs), allowing an operating system to specify attributes of memory accessed through a linear address on a 4KB granularity.|
|17 |PSE-36 |**36-Bit Page Size Extension.** 4-MByte pages addressing physical memory beyond 4 GBytes are supported with 32-bit paging. This feature indicates that upper bits of the physical address of a 4-MByte page are encoded in bits20:13 of the page-directory entry. Such physical addresses are limited by MAXPHYADDR and may be up to 40 bits in size.|
|18 |PSN |**Processor Serial Number. **The processor supports the 96-bit processor identification number feature and the feature is enabled.|
|19 |CLFSH|**CLFLUSH Instruction.** CLFLUSH Instruction is supported.|
|20|Reserved |Reserved|
### Table 3-11.  More on Feature Information Returned in the EDX Register (Contd.)


|**Bit # **|**Mnemonic **|**Description**|
|----------|-------------|---------------|
|21 |DS |**Debug Store.** The processor supports the ability to write debug information into a memory resident buffer. This feature is used by the branch trace store (BTS) and precise event-based sampling (PEBS) facilities (see Chapter 23, "Introduction to Virtual-Machine Extensions," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3C).|
|22 |ACPI|**Thermal Monitor and Software Controlled Clock Facilities.** The processor implements internal MSRs that allow processor temperature to be monitored and processor performance to be modulated in predefined duty cycles under software control.|
|23 |MMX|**Intel MMX Technology. **The processor supports the Intel MMX technology.|
|24 |FXSR |**FXSAVE and FXRSTOR Instructions.** The FXSAVE and FXRSTOR instructions are supported for fast save and restore of the floating point context. Presence of this bit also indicates that CR4.OSFXSR is available for an operating system to indicate that it supports the FXSAVE and FXRSTOR instructions.|
|25 |SSE |**SSE.** The processor supports the SSE extensions.|
|26 |SSE2 |**SSE2.** The processor supports the SSE2 extensions.|
|27|SS|**Self Snoop.** The processor supports the management of conflicting memory types by performing a snoop of its own cache structure for transactions issued to the bus.|
|28|HTT|**Max APIC IDs reserved field is Valid.** A value of 0 for HTT indicates there is only a single logical processor in the package and software should assume only a single APIC ID is reserved. A value of 1 for HTT indicates the value in CPUID.1.EBX[23:16] (the Maximum number of addressable IDs for logical processors in this package) is valid for the package.|
|29|TM|**Thermal Monitor.** The processor implements the thermal monitor automatic thermal control circuitry (TCC).|
|30|Reserved|Reserved|
|31|PBE|**Pending Break Enable. **The processor supports the use of the FERR#/PBE# pin when the processor is in the stop-clock state (STPCLK# is asserted) to signal the processor that an interrupt is pending and that the processor should return to normal operation to handle the interrupt. Bit 10 (PBE enable) in the IA32_MISC_ENABLE MSR enables this capability.|
### INPUT EAX = 02H: TLB/Cache/Prefetch Information Returned in EAX, EBX, ECX, EDX


When CPUID executes with EAX set to 02H, the processor returns information about the processor's internal TLBs, cache and prefetch hardware in the EAX, EBX, ECX, and EDX registers. The information is reported in encoded form and fall into the following categories:

*  The least-significant byte in register EAX (register AL) will always return 01H. Software should ignore this value and not interpret it as an informational descriptor.

*  The most significant bit (bit 31) of each register indicates whether the register contains valid information (set to 0) or is reserved (set to 1).

*  If a register contains valid information, the information is contained in 1 byte descriptors. There are four types of encoding values for the byte descriptor, the encoding type is noted in the second column of Table 3-12. Table 3-12 lists the encoding of these descriptors. Note that the order of descriptors in the EAX, EBX, ECX, and EDX registers is not defined; that is, specific bytes are not designated to contain descriptors for specific cache, prefetch, or TLB types. The descriptors may appear in any order. Note also a processor may report a general descriptor type (FFH) and not report any byte descriptor of "cache type" via CPUID leaf 2.

### Table 3-12.  Encoding of CPUID Leaf 2 Descriptors 


|** Value**|**Type**|**Description**|
|----------|--------|---------------|
|00H|General|Null descriptor, this byte contains no information|
|01H|TLB|Instruction TLB: 4 KByte pages, 4-way set associative, 32 entries|
|02H|TLB|Instruction TLB: 4 MByte pages, fully associative, 2 entries|
|03H|TLB|Data TLB: 4 KByte pages, 4-way set associative, 64 entries|
|04H|TLB|Data TLB: 4 MByte pages, 4-way set associative, 8 entries|
|05H|TLB|Data TLB1: 4 MByte pages, 4-way set associative, 32 entries|
|06H|Cache|1st-level instruction cache: 8 KBytes, 4-way set associative, 32 byte line size|
|08H|Cache|1st-level instruction cache: 16 KBytes, 4-way set associative, 32 byte line size|
|09H|Cache|1st-level instruction cache: 32KBytes, 4-way set associative, 64 byte line size|
|0AH|Cache|1st-level data cache: 8 KBytes, 2-way set associative, 32 byte line size|
|0BH|TLB|Instruction TLB: 4 MByte pages, 4-way set associative, 4 entries|
|0CH|Cache|1st-level data cache: 16 KBytes, 4-way set associative, 32 byte line size|
|0DH|Cache|1st-level data cache: 16 KBytes, 4-way set associative, 64 byte line size|
|0EH|Cache|1st-level data cache: 24 KBytes, 6-way set associative, 64 byte line size|
|1DH|Cache|2nd-level cache: 128 KBytes, 2-way set associative, 64 byte line size|
|21H|Cache|2nd-level cache: 256 KBytes, 8-way set associative, 64 byte line size|
|22H|Cache|3rd-level cache: 512 KBytes, 4-way set associative, 64 byte line size, 2 lines per sector|
|23H|Cache|3rd-level cache: 1 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector|
|24H|Cache|2nd-level cache: 1 MBytes, 16-way set associative, 64 byte line size|
|25H|Cache|3rd-level cache: 2 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector|
|29H|Cache|3rd-level cache: 4 MBytes, 8-way set associative, 64 byte line size, 2 lines per sector|
|2CH|Cache|1st-level data cache: 32 KBytes, 8-way set associative, 64 byte line size|
|30H|Cache|1st-level instruction cache: 32 KBytes, 8-way set associative, 64 byte line size|
|40H|Cache|No 2nd-level cache or, if processor contains a valid 2nd-level cache, no 3rd-level cache|
|41H|Cache|2nd-level cache: 128 KBytes, 4-way set associative, 32 byte line size|
|42H|Cache|2nd-level cache: 256 KBytes, 4-way set associative, 32 byte line size|
|43H|Cache|2nd-level cache: 512 KBytes, 4-way set associative, 32 byte line size|
|44H|Cache|2nd-level cache: 1 MByte, 4-way set associative, 32 byte line size|
|45H|Cache|2nd-level cache: 2 MByte, 4-way set associative, 32 byte line size|
|46H|Cache|3rd-level cache: 4 MByte, 4-way set associative, 64 byte line size|
|47H|Cache|3rd-level cache: 8 MByte, 8-way set associative, 64 byte line size|
|48H|Cache|2nd-level cache: 3MByte, 12-way set associative, 64 byte line size|
|49H|Cache|3rd-level cache: 4MB, 16-way set associative, 64-byte line size (Intel Xeon processor MP, Family 0FH, Model 06H);\newline{}2nd-level cache: 4 MByte, 16-way set associative, 64 byte line size|
|4AH|Cache|3rd-level cache: 6MByte, 12-way set associative, 64 byte line size|
|4BH|Cache|3rd-level cache: 8MByte, 16-way set associative, 64 byte line size|
|4CH|Cache|3rd-level cache: 12MByte, 12-way set associative, 64 byte line size|
|4DH|Cache|3rd-level cache: 16MByte, 16-way set associative, 64 byte line size|
|4EH|Cache|2nd-level cache: 6MByte, 24-way set associative, 64 byte line size|
|4FH |TLB|Instruction TLB: 4 KByte pages, 32 entries|
### Table 3-12.  Encoding of CPUID Leaf 2 Descriptors  (Contd.)


|** Value**|**Type**|**Description**|
|----------|--------|---------------|
|50H |TLB |Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 64 entries|
|51H|TLB|Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 128 entries|
|52H|TLB|Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 256 entries|
|55H|TLB|Instruction TLB: 2-MByte or 4-MByte pages, fully associative, 7 entries|
|56H|TLB|Data TLB0: 4 MByte pages, 4-way set associative, 16 entries|
|57H|TLB|Data TLB0: 4 KByte pages, 4-way associative, 16 entries|
|59H|TLB|Data TLB0: 4 KByte pages, fully associative, 16 entries|
|5AH|TLB|Data TLB0: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries|
|5BH|TLB|Data TLB: 4 KByte and 4 MByte pages, 64 entries|
|5CH|TLB|Data TLB: 4 KByte and 4 MByte pages,128 entries|
|5DH|TLB|Data TLB: 4 KByte and 4 MByte pages,256 entries|
|60H|Cache|1st-level data cache: 16 KByte, 8-way set associative, 64 byte line size|
|61H|TLB|Instruction TLB: 4 KByte pages, fully associative, 48 entries|
|63H|TLB|Data TLB: 2 MByte or 4 MByte pages, 4-way set associative, 32 entries and a separate array with 1 GByte pages, 4-way set associative, 4 entries|
|64H|TLB|Data TLB: 4 KByte pages, 4-way set associative, 512 entries|
|66H|Cache|1st-level data cache: 8 KByte, 4-way set associative, 64 byte line size|
|67H|Cache|1st-level data cache: 16 KByte, 4-way set associative, 64 byte line size|
|68H|Cache|1st-level data cache: 32 KByte, 4-way set associative, 64 byte line size|
|6AH|Cache|uTLB: 4 KByte pages, 8-way set associative, 64 entries|
|6BH|Cache|DTLB: 4 KByte pages, 8-way set associative, 256 entries|
|6CH|Cache|DTLB: 2M/4M pages, 8-way set associative, 128 entries|
|6DH|Cache|DTLB: 1 GByte pages, fully associative, 16 entries|
|70H|Cache|Trace cache: 12 K-µop, 8-way set associative|
|71H|Cache|Trace cache: 16 K-µop, 8-way set associative|
|72H|Cache|Trace cache: 32 K-µop, 8-way set associative|
|76H|TLB|Instruction TLB: 2M/4M pages, fully associative, 8 entries |
|78H|Cache|2nd-level cache: 1 MByte, 4-way set associative, 64byte line size|
|79H|Cache|2nd-level cache: 128 KByte, 8-way set associative, 64 byte line size, 2 lines per sector|
|7AH|Cache|2nd-level cache: 256 KByte, 8-way set associative, 64 byte line size, 2 lines per sector|
|7BH|Cache|2nd-level cache: 512 KByte, 8-way set associative, 64 byte line size, 2 lines per sector|
|7CH|Cache|2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size, 2 lines per sector|
|7DH|Cache|2nd-level cache: 2 MByte, 8-way set associative, 64byte line size|
|7FH|Cache|2nd-level cache: 512 KByte, 2-way set associative, 64-byte line size|
|80H|Cache|2nd-level cache: 512 KByte, 8-way set associative, 64-byte line size|
|82H|Cache|2nd-level cache: 256 KByte, 8-way set associative, 32 byte line size|
|83H|Cache|2nd-level cache: 512 KByte, 8-way set associative, 32 byte line size|
|84H|Cache|2nd-level cache: 1 MByte, 8-way set associative, 32 byte line size|
|85H|Cache|2nd-level cache: 2 MByte, 8-way set associative, 32 byte line size|
|86H|Cache|2nd-level cache: 512 KByte, 4-way set associative, 64 byte line size|
|87H|Cache|2nd-level cache: 1 MByte, 8-way set associative, 64 byte line size|
### Table 3-12.  Encoding of CPUID Leaf 2 Descriptors  (Contd.)


|** Value**|**Type**|**Description**|
|----------|--------|---------------|
|A0H|DTLB|DTLB: 4k pages, fully associative, 32 entries|
|B0H|TLB|Instruction TLB: 4 KByte pages, 4-way set associative, 128 entries|
|B1H|TLB|Instruction TLB: 2M pages, 4-way, 8 entries or 4M pages, 4-way, 4 entries|
|B2H|TLB|Instruction TLB: 4KByte pages, 4-way set associative, 64 entries|
|B3H|TLB|Data TLB: 4 KByte pages, 4-way set associative, 128 entries|
|B4H|TLB|Data TLB1: 4 KByte pages, 4-way associative, 256 entries|
|B5H|TLB|Instruction TLB: 4KByte pages, 8-way set associative, 64 entries|
|B6H|TLB|Instruction TLB: 4KByte pages, 8-way set associative, 128 entries|
|BAH|TLB|Data TLB1: 4 KByte pages, 4-way associative, 64 entries|
|C0H|TLB|Data TLB: 4 KByte and 4 MByte pages, 4-way associative, 8 entries|
|C1H|STLB|Shared 2nd-Level TLB: 4 KByte/2MByte pages, 8-way associative, 1024 entries|
|C2H|DTLB|DTLB: 4 KByte/2 MByte pages, 4-way associative, 16 entries|
|C3H|STLB|Shared 2nd-Level TLB: 4 KByte /2 MByte pages, 6-way associative, 1536 entries. Also 1GBbyte pages, 4-way, 16 entries.|
|C4H|DTLB|DTLB: 2M/4M Byte pages, 4-way associative, 32 entries|
|CAH|STLB|Shared 2nd-Level TLB: 4 KByte pages, 4-way associative, 512 entries|
|D0H|Cache|3rd-level cache: 512 KByte, 4-way set associative, 64 byte line size|
|D1H|Cache|3rd-level cache: 1 MByte, 4-way set associative, 64 byte line size|
|D2H|Cache|3rd-level cache: 2 MByte, 4-way set associative, 64 byte line size|
|D6H|Cache|3rd-level cache: 1 MByte, 8-way set associative, 64 byte line size|
|D7H|Cache|3rd-level cache: 2 MByte, 8-way set associative, 64 byte line size|
|D8H|Cache|3rd-level cache: 4 MByte, 8-way set associative, 64 byte line size|
|DCH|Cache|3rd-level cache: 1.5 MByte, 12-way set associative, 64 byte line size|
|DDH|Cache|3rd-level cache: 3 MByte, 12-way set associative, 64 byte line size|
|DEH|Cache|3rd-level cache: 6 MByte, 12-way set associative, 64 byte line size|
|E2H|Cache|3rd-level cache: 2 MByte, 16-way set associative, 64 byte line size|
|E3H|Cache|3rd-level cache: 4 MByte, 16-way set associative, 64 byte line size|
|E4H|Cache|3rd-level cache: 8 MByte, 16-way set associative, 64 byte line size|
|EAH|Cache|3rd-level cache: 12MByte, 24-way set associative, 64 byte line size|
|EBH|Cache|3rd-level cache: 18MByte, 24-way set associative, 64 byte line size|
|ECH|Cache|3rd-level cache: 24MByte, 24-way set associative, 64 byte line size|
|F0H|Prefetch|64-Byte prefetching|
|F1H|Prefetch|128-Byte prefetching|
|FFH|General|CPUID leaf 2 does not report cache descriptor information, use CPUID leaf 4 to query cache parameters|
### Example 3-1.  Example of Cache and TLB Interpretation


The first member of the family of Pentium 4 processors returns the following information about caches and TLBs when the CPUID executes with an input value of 2:

 EAX 66 5B 50 01HEBX 0HECX 0HEDX 00 7A 70 00H



Which means:

*  The least-significant byte (byte 0) of register EAX is set to 01H. This value should be ignored.

*  The most-significant bit of all four registers (EAX, EBX, ECX, and EDX) is set to 0, indicating that each register contains valid 1-byte descriptors.

*  Bytes 1, 2, and 3 of register EAX indicate that the processor has:

 --50H - a 64-entry instruction TLB, for mapping 4-KByte and 2-MByte or 4-MByte pages.

 --5BH - a 64-entry data TLB, for mapping 4-KByte and 4-MByte pages.

 --66H - an 8-KByte 1st level data cache, 4-way set associative, with a 64-Byte cache line size.

*  The descriptors in registers EBX and ECX are valid, but contain NULL descriptors.

*  Bytes 0, 1, 2, and 3 of register EDX indicate that the processor has:

 --00H - NULL descriptor.

 --70H - Trace cache: 12 K-µop, 8-way set associative.

 --7AH - a 256-KByte 2nd level cache, 8-way set associative, with a sectored, 64-byte cache line size.

 --00H - NULL descriptor.

### INPUT EAX = 04H: Returns Deterministic Cache Parameters for Each Level


When CPUID executes with EAX set to 04H and ECX contains an index value, the processor returns encoded data that describe a set of deterministic cache parameters (for the cache level associated with the input in ECX). Valid index values start from 0.

Software can enumerate the deterministic cache parameters for each level of the cache hierarchy starting with an index value of 0, until the parameters report the value associated with the cache type field is 0. The architecturally defined fields reported by deterministic cache parameters are documented in Table 3-8.

This Cache Size in Bytes

= (Ways + 1) * (Partitions + 1) * (Line_Size + 1) * (Sets + 1)

= (EBX[31:22] + 1) * (EBX[21:12] + 1) * (EBX[11:0] + 1) * (ECX + 1)

The CPUID leaf 04H also reports data that can be used to derive the topology of processor cores in a physical package. This information is constant for all valid index values. Software can query the raw data reported by executing CPUID with EAX=04H and ECX=0 and use it as part of the topology enumeration algorithm described in Chapter 8, "Multiple-Processor Management," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A.

### INPUT EAX = 05H: Returns MONITOR and MWAIT Features


When CPUID executes with EAX set to 05H, the processor returns information about features available to MONITOR/MWAIT instructions. The MONITOR instruction is used for address-range monitoring in conjunction with MWAIT instruction. The MWAIT instruction optionally provides additional extensions for advanced power manage-ment. See Table 3-8. 

### INPUT EAX = 06H: Returns Thermal and Power Management Features


When CPUID executes with EAX set to 06H, the processor returns information about thermal and power manage-ment features. See Table 3-8. 

### INPUT EAX = 07H: Returns Structured Extended Feature Enumeration Information


When CPUID executes with EAX set to 07H and ECX = 0, the processor returns information about the maximum input value for sub-leaves that contain extended feature flags. See Table 3-8. 

When CPUID executes with EAX set to 07H and the input value of ECX is invalid (see leaf 07H entry in Table 3-8), the processor returns 0 in EAX/EBX/ECX/EDX. In subleaf 0, EAX returns the maximum input value of the highest leaf 7 sub-leaf, and EBX, ECX & EDX contain information of extended feature flags.

### INPUT EAX = 09H: Returns Direct Cache Access Information


When CPUID executes with EAX set to 09H, the processor returns information about Direct Cache Access capabili-ties. See Table 3-8. 

### INPUT EAX = 0AH: Returns Architectural Performance Monitoring Features


When CPUID executes with EAX set to 0AH, the processor returns information about support for architectural performance monitoring capabilities. Architectural performance monitoring is supported if the version ID (see Table 3-8) is greater than Pn0. See Table 3-8.

For each version of architectural performance monitoring capability, software must enumerate this leaf to discover the programming facilities and the architectural performance events available in the processor. The details are described in Chapter 23, "Introduction to Virtual-Machine Extensions," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3C.

### INPUT EAX = 0BH: Returns Extended Topology Information


When CPUID executes with EAX set to 0BH, the processor returns information about extended topology enumera-tion data. Software must detect the presence of CPUID leaf 0BH by verifying (a) the highest leaf index supported by CPUID is >= 0BH, and (b) CPUID.0BH:EBX[15:0] reports a non-zero value. See Table 3-8.

### INPUT EAX = 0DH: Returns Processor Extended States Enumeration Information


When CPUID executes with EAX set to 0DH and ECX = 0, the processor returns information about the bit-vector representation of all processor state extensions that are supported in the processor and storage size requirements of the XSAVE/XRSTOR area. See Table 3-8. 

When CPUID executes with EAX set to 0DH and ECX = n (n > 1, and is a valid sub-leaf index), the processor returns information about the size and offset of each processor extended state save area within the XSAVE/XRSTOR area. See Table 3-8. Software can use the forward-extendable technique depicted below to query the valid sub-leaves and obtain size and offset information for each processor extended state save area:

For i = 2 to 62 // sub-leaf 1 is reservedIF (CPUID.(EAX=0DH, ECX=0):VECTOR[i] = 1 ) // VECTOR is the 64-bit value of EDX:EAXExecute CPUID.(EAX=0DH, ECX = i) to examine size and offset for sub-leaf i; FI;

### INPUT EAX = 0FH: Returns Intel Resource Director Technology (Intel RDT) Monitoring Enumeration Information


When CPUID executes with EAX set to 0FH and ECX = 0, the processor returns information about the bit-vector representation of QoS monitoring resource types that are supported in the processor and maximum range of RMID values the processor can use to monitor of any supported resource types. Each bit, starting from bit 1, corresponds to a specific resource type if the bit is set. The bit position corresponds to the sub-leaf index (or ResID) that soft-ware must use to query QoS monitoring capability available for that type. See Table 3-8.

When CPUID executes with EAX set to 0FH and ECX = n (n >= 1, and is a valid ResID), the processor returns infor-mation software can use to program IA32_PQR_ASSOC, IA32_QM_EVTSEL MSRs before reading QoS data from the IA32_QM_CTR MSR.

### INPUT EAX = 10H: Returns Intel Resource Director Technology (Intel RDT) Allocation Enumeration Information


When CPUID executes with EAX set to 10H and ECX = 0, the processor returns information about the bit-vector representation of QoS Enforcement resource types that are supported in the processor. Each bit, starting from bit 1, corresponds to a specific resource type if the bit is set. The bit position corresponds to the sub-leaf index (or ResID) that software must use to query QoS enforcement capability available for that type. See Table 3-8.

When CPUID executes with EAX set to 10H and ECX = n (n >= 1, and is a valid ResID), the processor returns infor-mation about available classes of service and range of QoS mask MSRs that software can use to configure each class of services using capability bit masks in the QoS Mask registers, IA32_resourceType_Mask_n.

### INPUT EAX = 12H: Returns Intel SGX Enumeration Information


When CPUID executes with EAX set to 12H and ECX = 0H, the processor returns information about Intel SGX capa-bilities. See Table 3-8. 

When CPUID executes with EAX set to 12H and ECX = 1H, the processor returns information about Intel SGX attri-butes. See Table 3-8. 

When CPUID executes with EAX set to 12H and ECX = n (n > 1), the processor returns information about Intel SGX Enclave Page Cache. See Table 3-8.

### INPUT EAX = 14H: Returns Intel Processor Trace Enumeration Information


When CPUID executes with EAX set to 14H and ECX = 0H, the processor returns information about Intel Processor Trace extensions. See Table 3-8. 

When CPUID executes with EAX set to 14H and ECX = n (n > 0 and less than the number of non-zero bits in CPUID.(EAX=14H, ECX= 0H).EAX), the processor returns information about packet generation in Intel Processor Trace. See Table 3-8. 

### INPUT EAX = 15H: Returns Time Stamp Counter and Nominal Core Crystal Clock Information


When CPUID executes with EAX set to 15H and ECX = 0H, the processor returns information about Time Stamp Counter and Core Crystal Clock. See Table 3-8.

### INPUT EAX = 16H: Returns Processor Frequency Information


When CPUID executes with EAX set to 16H, the processor returns information about Processor Frequency Informa-tion. See Table 3-8. 

### INPUT EAX = 17H: Returns System-On-Chip Information


When CPUID executes with EAX set to 17H, the processor returns information about the System-On-Chip Vendor Attribute Enumeration. See Table 3-8. 

### METHODS FOR RETURNING BRANDING INFORMATION


Use the following techniques to access branding information:

1.Processor brand string method.

2.Processor brand index; this method uses a software supplied brand string table.

These two methods are discussed in the following sections. For methods that are available in early processors, see Section: "Identification of Earlier IA-32 Processors" in Chapter 19 of the Intel(R) 64 and IA-32 Architectures Soft-ware Developer's Manual, Volume 1.

### The Processor Brand String Method


Figure3-9 describes the algorithm used for detection of the brand string. Processor brand identification software should execute this algorithm on all Intel 64 and IA-32 processors. 

This method (introduced with Pentium 4 processors) returns an ASCII brand identification string and the Processor Base frequency of the processor to the EAX, EBX, ECX, and EDX registers.

```embed
<figure>
<svg viewBox="0 0 379.679993 414.779999">
<rect x="0.000000" y="10.000000" width="0.480000" height="316.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.000000" width="0.479980" height="316.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="326.619965" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.039993" y="26.739990" width="318.600006" height="288.600006" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M21.600006,106.239990 L83.820007,77.020020 L146.039993,106.239990 L83.820007,135.459961 L21.600006,106.239990" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M21.600006,106.239990 L83.820007,77.020020 L146.039993,106.239990 L83.820007,135.459961 L21.600006,106.239990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M83.820007,47.799988 L83.820007,73.659973" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M83.820007,77.020020 L81.660004,72.640015 C83.040009 73.300049,84.600006 73.300049,86.040009 72.640015  L83.820007,77.020020" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M21.600006,269.380005 L83.820007,240.160004 L146.039993,269.380005 L83.820007,298.600006 L21.600006,269.380005" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M21.600006,269.380005 L83.820007,240.160004 L146.039993,269.380005 L83.820007,298.600006 L21.600006,269.380005" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M83.820007,210.940002 L83.820007,236.799988" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M83.820007,240.160004 L81.660004,235.720001 C83.040009 236.440002,84.600006 236.440002,86.040009 235.720001  L83.820007,240.160004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M83.820007,135.459961 L83.820007,178.359985" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M83.820007,181.719971 L81.660004,177.279968 C83.040009 178.000000,84.600006 178.000000,86.040009 177.279968  L83.820007,181.719971" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="35.940002" y="181.719971" width="95.760002" height="36.540001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="35.940002" y="181.719971" width="95.760002" height="36.540001" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="35.940002" y="28.360046" width="95.760002" height="29.219999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="35.940002" y="28.360046" width="95.760002" height="29.219999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="232.199997" y="88.000000" width="95.699997" height="36.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="232.199997" y="88.000000" width="95.699997" height="36.480000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M146.039993,106.239990 L228.899979,106.239990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M232.199997,106.239990 L227.819992,108.459961 C228.539993 107.080017,228.539993 105.459961,227.819992 104.080017  L232.199997,106.239990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="232.199997" y="251.079987" width="95.699997" height="36.540001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="232.199997" y="251.079987" width="95.699997" height="36.540001" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M146.039993,269.380005 L228.899979,269.380005" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M232.199997,269.380005 L227.819992,271.600006 C228.539993 270.160004,228.539993 268.540009,227.819992 267.160004  L232.199997,269.380005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<text x="193.920151" y="264.519989" textLength="4.963746" font-size="8px">e</text>
<text x="189.121567" y="264.519989" textLength="4.963746" font-size="8px">u</text>
<text x="307.973083" y="278.319855" textLength="4.963746" font-size="8px">d</text>
<text x="283.257019" y="278.319855" textLength="4.963746" font-size="8px">p</text>
<text x="278.458435" y="278.319855" textLength="4.963746" font-size="8px">u</text>
<text x="260.939819" y="278.319855" textLength="4.963746" font-size="8px">n</text>
<text x="253.739731" y="278.319855" textLength="2.481873" font-size="8px">t</text>
<text x="248.159988" y="278.319855" textLength="5.954709" font-size="8px">S</text>
<text x="307.194702" y="267.759979" textLength="4.963746" font-size="8px">d</text>
<text x="302.396118" y="267.759979" textLength="4.963746" font-size="8px">n</text>
<text x="297.597534" y="267.759979" textLength="4.963746" font-size="8px">a</text>
<text x="294.417480" y="267.759979" textLength="2.972891" font-size="8px">r</text>
<text x="288.837769" y="267.759979" textLength="5.954709" font-size="8px">B</text>
<text x="286.436218" y="267.759979" textLength="2.481873" font-size="8px"> </text>
<text x="278.457642" y="267.759979" textLength="4.963746" font-size="8px">o</text>
<text x="274.497314" y="267.759979" textLength="4.463800" font-size="8px">s</text>
<text x="270.477234" y="267.759979" textLength="4.463800" font-size="8px">s</text>
<text x="256.919739" y="267.759979" textLength="4.963746" font-size="8px">o</text>
<text x="248.159988" y="267.759979" textLength="5.954709" font-size="8px">P</text>
<text x="190.738693" y="101.380005" textLength="4.463800" font-size="8px">s</text>
<text x="290.455383" y="120.099548" textLength="4.963746" font-size="8px">e</text>
<text x="284.873840" y="120.099548" textLength="2.972891" font-size="8px">r</text>
<text x="280.075256" y="120.099548" textLength="4.963746" font-size="8px">o</text>
<text x="275.276672" y="120.099548" textLength="4.963746" font-size="8px">p</text>
<text x="270.478088" y="120.099548" textLength="4.963746" font-size="8px">p</text>
<text x="265.679504" y="120.099548" textLength="4.963746" font-size="8px">u</text>
<text x="260.099731" y="120.099548" textLength="5.954709" font-size="8px">S</text>
<text x="296.815369" y="110.319885" textLength="2.481873" font-size="8px">t</text>
<text x="283.257019" y="110.319885" textLength="2.481873" font-size="8px"> </text>
<text x="278.458435" y="110.319885" textLength="4.963746" font-size="8px">g</text>
<text x="272.101135" y="110.319885" textLength="1.981927" font-size="8px">i</text>
<text x="260.939819" y="110.319885" textLength="5.954709" font-size="8px">S</text>
<text x="307.194702" y="99.760010" textLength="4.963746" font-size="8px">d</text>
<text x="302.396118" y="99.760010" textLength="4.963746" font-size="8px">n</text>
<text x="297.597534" y="99.760010" textLength="4.963746" font-size="8px">a</text>
<text x="294.417480" y="99.760010" textLength="2.972891" font-size="8px">r</text>
<text x="274.497314" y="99.760010" textLength="4.463800" font-size="8px">s</text>
<text x="270.477234" y="99.760010" textLength="4.463800" font-size="8px">s</text>
<text x="265.678650" y="99.760010" textLength="4.963746" font-size="8px">e</text>
<text x="261.718323" y="99.760010" textLength="4.463800" font-size="8px">c</text>
<text x="256.919739" y="99.760010" textLength="4.963746" font-size="8px">o</text>
<text x="248.159988" y="99.760010" textLength="5.954709" font-size="8px">P</text>
<text x="103.009140" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="98.210556" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="83.874619" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="88.613388" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="74.277451" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="65.518585" y="51.099854" textLength="4.463800" font-size="8px">x</text>
<text x="288.055603" y="278.319855" textLength="4.963746" font-size="8px">p</text>
<text x="60.720001" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="106.200745" y="40.539978" textLength="2.481873" font-size="8px"> </text>
<text x="286.436218" y="99.760010" textLength="2.481873" font-size="8px"> </text>
<text x="101.371811" y="40.539978" textLength="5.213718" font-size="8px">=</text>
<text x="90.231949" y="40.539978" textLength="5.954709" font-size="8px">A</text>
<text x="84.662018" y="40.539978" textLength="5.954709" font-size="8px">E</text>
<text x="268.921082" y="110.319885" textLength="2.972891" font-size="8px">r</text>
<text x="70.318436" y="72.159973" textLength="6.445727" font-size="8px">D</text>
<text x="61.501648" y="214.239746" textLength="4.963746" font-size="8px">u</text>
<text x="115.740295" y="270.220001" textLength="4.963746" font-size="8px">u</text>
<text x="98.218170" y="214.239746" textLength="4.963746" font-size="8px">d</text>
<text x="63.899231" y="159.039856" textLength="2.481873" font-size="8px">t</text>
<text x="253.739731" y="267.759979" textLength="2.972891" font-size="8px">r</text>
<text x="261.718323" y="267.759979" textLength="4.463800" font-size="8px">c</text>
<text x="96.601929" y="153.339905" textLength="2.972891" font-size="8px">r</text>
<text x="189.120132" y="101.380005" textLength="1.981927" font-size="8px">l</text>
<text x="91.020386" y="153.339905" textLength="5.454763" font-size="8px">T</text>
<text x="98.999344" y="193.119995" textLength="4.963746" font-size="8px">a</text>
<text x="59.100998" y="203.679871" textLength="2.481873" font-size="8px"> </text>
<text x="265.678650" y="267.759979" textLength="4.963746" font-size="8px">e</text>
<text x="117.355377" y="193.119995" textLength="5.213718" font-size="8px">=</text>
<text x="83.884933" y="109.539978" textLength="4.463800" font-size="8px">x</text>
<text x="51.119736" y="193.119995" textLength="5.954709" font-size="8px">A</text>
<text x="303.174500" y="278.319855" textLength="4.963746" font-size="8px">e</text>
<text x="180.360001" y="264.519989" textLength="5.454763" font-size="8px">T</text>
<text x="79.086349" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="69.478867" y="51.099854" textLength="4.963746" font-size="8px">8</text>
<text x="68.698715" y="148.479980" textLength="2.481873" font-size="8px">I</text>
<text x="80.636993" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="95.032745" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="184.381363" y="101.380005" textLength="4.963746" font-size="8px">a</text>
<text x="273.659851" y="110.319885" textLength="4.963746" font-size="8px">n</text>
<text x="55.924500" y="270.220001" textLength="5.954709" font-size="8px">E</text>
<text x="39.180008" y="109.539978" textLength="2.481873" font-size="8px">I</text>
<text x="71.100601" y="193.119995" textLength="4.963746" font-size="8px">e</text>
<text x="99.781937" y="153.339905" textLength="4.963746" font-size="8px">u</text>
<text x="92.643799" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="292.016785" y="110.319885" textLength="4.963746" font-size="8px">o</text>
<text x="67.082260" y="203.679871" textLength="4.463800" font-size="8px">x</text>
<text x="125.337463" y="270.220001" textLength="2.481873" font-size="8px"> </text>
<text x="297.592957" y="278.319855" textLength="2.972891" font-size="8px">r</text>
<text x="73.503876" y="203.679871" textLength="4.963746" font-size="8px">e</text>
<text x="270.477173" y="278.319855" textLength="2.481873" font-size="8px"> </text>
<text x="185.941544" y="264.519989" textLength="2.972891" font-size="8px">r</text>
<text x="87.845215" y="109.539978" textLength="4.963746" font-size="8px">8</text>
<text x="110.940536" y="153.339905" textLength="0.000000" font-size="8px"> </text>
<text x="110.940536" y="153.339905" textLength="0.000000" font-size="8px">•</text>
<text x="256.141235" y="278.319855" textLength="2.972891" font-size="8px">r</text>
<text x="91.018066" y="193.119995" textLength="2.481873" font-size="8px"> </text>
<text x="64.681656" y="193.119995" textLength="6.445727" font-size="8px">R</text>
<text x="72.658875" y="40.539978" textLength="4.963746" font-size="8px">u</text>
<text x="117.357697" y="163.899780" textLength="4.963746" font-size="8px">e</text>
<text x="63.123825" y="109.539978" textLength="5.954709" font-size="8px">X</text>
<text x="278.457642" y="99.760010" textLength="4.963746" font-size="8px">o</text>
<text x="57.544083" y="109.539978" textLength="5.954709" font-size="8px">A</text>
<text x="63.121521" y="40.539978" textLength="4.963746" font-size="8px">n</text>
<text x="104.580521" y="153.339905" textLength="4.963746" font-size="8px">e</text>
<text x="111.777390" y="203.679871" textLength="6.445727" font-size="8px">U</text>
<text x="283.256226" y="267.759979" textLength="2.972891" font-size="8px">r</text>
<text x="43.199997" y="270.220001" textLength="2.481873" font-size="8px">I</text>
<text x="79.076035" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="90.234161" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="178.740005" y="101.380005" textLength="5.454763" font-size="8px">F</text>
<text x="97.379929" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="300.773010" y="278.319855" textLength="2.481873" font-size="8px">t</text>
<text x="67.084000" y="270.220001" textLength="5.954709" font-size="8px">X</text>
<text x="67.079544" y="280.779877" textLength="4.463800" font-size="8px">x</text>
<text x="45.541702" y="270.220001" textLength="5.454763" font-size="8px">F</text>
<text x="79.079193" y="214.239746" textLength="4.963746" font-size="8px">o</text>
<text x="93.411972" y="51.099854" textLength="4.963746" font-size="8px">0</text>
<text x="76.684830" y="109.539978" textLength="2.481873" font-size="8px"> </text>
<text x="87.839813" y="203.679871" textLength="4.963746" font-size="8px">e</text>
<text x="288.837769" y="99.760010" textLength="5.954709" font-size="8px">B</text>
<text x="109.382950" y="270.220001" textLength="4.963746" font-size="8px">a</text>
<text x="111.775681" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="75.899185" y="193.119995" textLength="2.481873" font-size="8px">t</text>
<text x="67.916916" y="72.159973" textLength="2.481873" font-size="8px">I</text>
<text x="61.504257" y="270.220001" textLength="5.954709" font-size="8px">A</text>
<text x="56.758942" y="148.479980" textLength="5.954709" font-size="8px">P</text>
<text x="253.739731" y="99.760010" textLength="2.972891" font-size="8px">r</text>
<text x="81.484207" y="270.220001" textLength="4.963746" font-size="8px">e</text>
<text x="272.878723" y="278.319855" textLength="5.954709" font-size="8px">S</text>
<text x="86.219482" y="193.119995" textLength="4.963746" font-size="8px">n</text>
<text x="78.242645" y="203.679871" textLength="4.963746" font-size="8px">n</text>
<text x="77.454895" y="148.479980" textLength="2.481873" font-size="8px"> </text>
<text x="75.065262" y="270.220001" textLength="6.445727" font-size="8px">R</text>
<text x="265.678589" y="278.319855" textLength="4.963746" font-size="8px">g</text>
<text x="96.603088" y="270.220001" textLength="4.963746" font-size="8px">n</text>
<text x="104.570099" y="280.779877" textLength="4.963746" font-size="8px">4</text>
<text x="53.520309" y="280.779877" textLength="0.000000" font-size="8px"> </text>
<text x="53.520309" y="280.779877" textLength="0.000000" font-size="8px">•</text>
<text x="55.140366" y="159.039856" textLength="4.963746" font-size="8px">n</text>
<text x="55.920105" y="214.239746" textLength="5.454763" font-size="8px">F</text>
<text x="91.020386" y="163.899780" textLength="5.954709" font-size="8px">E</text>
<text x="314.340942" y="312.399994" textLength="5.408419" font-size="8px">M</text>
<text x="106.977097" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="295.194153" y="120.099548" textLength="4.963746" font-size="8px">d</text>
<text x="194.698990" y="101.380005" textLength="4.963746" font-size="8px">e</text>
<text x="126.111618" y="109.539978" textLength="2.972891" font-size="8px">)</text>
<text x="47.939362" y="169.599731" textLength="4.963746" font-size="8px">p</text>
<text x="285.658569" y="110.319885" textLength="6.445727" font-size="8px">N</text>
<text x="47.940613" y="203.679871" textLength="4.963746" font-size="8px">a</text>
<text x="107.755524" y="214.239746" textLength="4.463800" font-size="8px">x</text>
<text x="91.018066" y="214.239746" textLength="2.481873" font-size="8px">I</text>
<text x="93.419586" y="193.119995" textLength="5.954709" font-size="8px">V</text>
<text x="116.574265" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="78.240891" y="193.119995" textLength="4.963746" font-size="8px">u</text>
<text x="99.771515" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="95.801880" y="40.539978" textLength="5.954709" font-size="8px">X</text>
<text x="52.739197" y="203.679871" textLength="4.463800" font-size="8px">x</text>
<text x="85.435577" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="55.918228" y="72.159973" textLength="5.954709" font-size="8px">P</text>
<text x="120.538879" y="270.220001" textLength="4.963746" font-size="8px">e</text>
<text x="71.102356" y="203.679871" textLength="2.481873" font-size="8px">t</text>
<text x="292.794373" y="278.319855" textLength="4.963746" font-size="8px">o</text>
<text x="48.784317" y="109.539978" textLength="2.972891" font-size="8px">(</text>
<text x="71.094879" y="148.479980" textLength="6.445727" font-size="8px">D</text>
<text x="309.599976" y="312.399994" textLength="5.051321" font-size="8px">O</text>
<text x="319.920776" y="312.399994" textLength="3.609941" font-size="8px">1</text>
<text x="72.655411" y="169.599731" textLength="4.963746" font-size="8px">d</text>
<text x="323.159973" y="312.399994" textLength="3.609941" font-size="8px">5</text>
<text x="37.560135" y="169.599731" textLength="5.954709" font-size="8px">S</text>
<text x="283.256226" y="99.760010" textLength="2.972891" font-size="8px">r</text>
<text x="326.338806" y="312.399994" textLength="3.609941" font-size="8px">1</text>
<text x="329.517639" y="312.399994" textLength="3.609941" font-size="8px">9</text>
<text x="114.953857" y="193.119995" textLength="2.481873" font-size="8px"> </text>
<text x="332.696472" y="312.399994" textLength="3.609941" font-size="8px">4</text>
<text x="83.039474" y="193.119995" textLength="2.972891" font-size="8px">r</text>
<text x="41.581528" y="109.539978" textLength="5.454763" font-size="8px">F</text>
<text x="51.964325" y="109.539978" textLength="5.954709" font-size="8px">E</text>
<text x="68.703568" y="109.539978" textLength="2.481873" font-size="8px"> </text>
<text x="110.155273" y="193.119995" textLength="4.963746" font-size="8px">e</text>
<text x="66.300232" y="214.239746" textLength="4.963746" font-size="8px">n</text>
<text x="71.105087" y="109.539978" textLength="5.954709" font-size="8px">&</text>
<text x="114.181534" y="270.220001" textLength="1.981927" font-size="8px">l</text>
<text x="102.178513" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="79.858978" y="40.539978" textLength="2.481873" font-size="8px">:</text>
<text x="121.313034" y="109.539978" textLength="4.963746" font-size="8px">0</text>
<text x="49.559998" y="72.159973" textLength="6.445727" font-size="8px">C</text>
<text x="61.497971" y="72.159973" textLength="6.445727" font-size="8px">U</text>
<text x="65.515121" y="169.599731" textLength="2.481873" font-size="8px">t</text>
<text x="101.401672" y="270.220001" textLength="2.481873" font-size="8px"> </text>
<text x="72.663742" y="270.220001" textLength="2.481873" font-size="8px"> </text>
<text x="86.222977" y="270.220001" textLength="2.481873" font-size="8px">t</text>
<text x="88.624496" y="270.220001" textLength="4.963746" font-size="8px">u</text>
<text x="259.321289" y="278.319855" textLength="1.981927" font-size="8px">i</text>
<text x="92.638397" y="203.679871" textLength="4.963746" font-size="8px">d</text>
<text x="93.423080" y="270.220001" textLength="2.972891" font-size="8px">r</text>
<text x="266.519592" y="110.319885" textLength="2.481873" font-size="8px">t</text>
<text x="103.803192" y="270.220001" textLength="5.954709" font-size="8px">V</text>
<text x="62.340775" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="105.356689" y="193.119995" textLength="4.963746" font-size="8px">u</text>
<text x="71.099640" y="280.779877" textLength="4.963746" font-size="8px">8</text>
<text x="75.898224" y="280.779877" textLength="4.963746" font-size="8px">0</text>
<text x="109.368683" y="280.779877" textLength="2.972891" font-size="8px">)</text>
<text x="62.338699" y="148.479980" textLength="6.445727" font-size="8px">U</text>
<text x="44.760239" y="159.039856" textLength="5.454763" font-size="8px">F</text>
<text x="50.341782" y="159.039856" textLength="4.963746" font-size="8px">u</text>
<text x="59.938950" y="159.039856" textLength="4.463800" font-size="8px">c</text>
<text x="66.300751" y="159.039856" textLength="1.981927" font-size="8px">i</text>
<text x="67.919327" y="159.039856" textLength="4.963746" font-size="8px">o</text>
<text x="72.658096" y="159.039856" textLength="4.963746" font-size="8px">n</text>
<text x="43.200592" y="169.599731" textLength="4.963746" font-size="8px">u</text>
<text x="52.737946" y="169.599731" textLength="4.963746" font-size="8px">p</text>
<text x="57.536530" y="169.599731" textLength="4.963746" font-size="8px">o</text>
<text x="62.335114" y="169.599731" textLength="2.972891" font-size="8px">r</text>
<text x="67.916641" y="169.599731" textLength="4.963746" font-size="8px">e</text>
<text x="109.379105" y="153.339905" textLength="2.481873" font-size="8px"> </text>
<text x="96.600143" y="163.899780" textLength="4.463800" font-size="8px">x</text>
<text x="51.123245" y="270.220001" textLength="2.481873" font-size="8px"> </text>
<text x="100.620239" y="163.899780" textLength="2.481873" font-size="8px">t</text>
<text x="103.021759" y="163.899780" textLength="4.963746" font-size="8px">e</text>
<text x="107.760529" y="163.899780" textLength="4.963746" font-size="8px">n</text>
<text x="112.559113" y="163.899780" textLength="4.963746" font-size="8px">d</text>
<text x="122.156281" y="163.899780" textLength="4.963746" font-size="8px">d</text>
<text x="45.539993" y="193.119995" textLength="5.954709" font-size="8px">E</text>
<text x="56.760193" y="193.119995" textLength="5.954709" font-size="8px">X</text>
<text x="47.163071" y="109.539978" textLength="2.481873" font-size="8px"> </text>
<text x="62.339951" y="193.119995" textLength="2.481873" font-size="8px"> </text>
<text x="82.260498" y="40.539978" textLength="2.481873" font-size="8px"> </text>
<text x="103.797928" y="193.119995" textLength="1.981927" font-size="8px">l</text>
<text x="40.800323" y="203.679871" textLength="7.436691" font-size="8px">M</text>
<text x="56.759293" y="203.679871" textLength="2.481873" font-size="8px">.</text>
<text x="61.502518" y="203.679871" textLength="5.954709" font-size="8px">E</text>
<text x="83.041229" y="203.679871" textLength="4.963746" font-size="8px">d</text>
<text x="52.744492" y="270.220001" textLength="2.972891" font-size="8px">(</text>
<text x="97.377167" y="203.679871" textLength="2.481873" font-size="8px"> </text>
<text x="99.778687" y="203.679871" textLength="6.445727" font-size="8px">C</text>
<text x="106.197632" y="203.679871" textLength="5.954709" font-size="8px">P</text>
<text x="118.135620" y="203.679871" textLength="2.481873" font-size="8px">I</text>
<text x="50.339996" y="148.479980" textLength="6.445727" font-size="8px">C</text>
<text x="120.537140" y="203.679871" textLength="6.445727" font-size="8px">D</text>
<text x="288.053833" y="120.099548" textLength="2.481873" font-size="8px">t</text>
<text x="71.098816" y="214.239746" textLength="4.463800" font-size="8px">c</text>
<text x="75.059097" y="214.239746" textLength="2.481873" font-size="8px">t</text>
<text x="77.460617" y="214.239746" textLength="1.981927" font-size="8px">i</text>
<text x="83.817963" y="214.239746" textLength="4.963746" font-size="8px">n</text>
<text x="88.616547" y="214.239746" textLength="2.481873" font-size="8px"> </text>
<text x="93.419586" y="214.239746" textLength="4.963746" font-size="8px">n</text>
<text x="103.016754" y="214.239746" textLength="4.963746" font-size="8px">e</text>
<text x="60.720001" y="40.539978" textLength="2.481873" font-size="8px">I</text>
<text x="67.920105" y="40.539978" textLength="4.963746" font-size="8px">p</text>
<text x="77.457458" y="40.539978" textLength="2.481873" font-size="8px">t</text>
</svg>
<figcaption>Figure 3-9.  Determination of Support for the Processor Brand String
</figcaption></figure>
```
### How Brand Strings Work


To use the brand string method, execute CPUID with EAX input of 8000002H through 80000004H. For each input value, CPUID returns 16 ASCII characters using EAX, EBX, ECX, and EDX. The returned string will be NULL-termi-nated.



Table 3-13 shows the brand string that is returned by the first processor in the Pentium 4 processor family.

### Table 3-13.  Processor Brand String Returned with Pentium 4 Processor 


|**EAX Input Value**|**Return Values**|**ASCII Equivalent**|
|-------------------|-----------------|--------------------|
|80000002H|EAX = 20202020H\newline{}EBX = 20202020H\newline{}ECX = 20202020H\newline{}EDX = 6E492020H|" " \newline{}""\newline{}""\newline{}"nI  "|
|80000003H|EAX = 286C6574H\newline{}EBX = 50202952H\newline{}ECX = 69746E65H\newline{}EDX = 52286D75H|"(let"\newline{}"P )R"\newline{}"itne"\newline{}"R(mu"|
|80000004H|EAX = 20342029H\newline{}EBX = 20555043H\newline{}ECX = 30303531H\newline{}EDX = 007A484DH|" 4 )"\newline{}" UPC"\newline{}"0051"\newline{}"\0zHM"|
### Extracting the Processor Frequency from Brand Strings


Figure3-10 provides an algorithm which software can use to extract the Processor Base frequency from the processor brand string.

```embed
<figure>
<svg viewBox="0 0 379.679993 336.799988">
<rect x="0.000000" y="10.000000" width="0.480000" height="323.579987" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.199982" y="10.000000" width="0.479980" height="323.579987" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="379.679993" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="333.640015" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="33.299995" y="26.739990" width="311.040009" height="301.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M40.980003,110.079987 L94.200005,85.419983 L147.480011,110.079987 L94.200005,134.679993 L40.980003,110.079987" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M40.980003,110.079987 L94.200005,85.419983 L147.480011,110.079987 L94.200005,134.679993 L40.980003,110.079987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M94.200005,52.660004 L94.200005,82.600006" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M94.200005,85.419983 L92.400002,81.819977 L92.879997,81.999969 C94.320000 82.285980,94.264000 82.229980,95.700005 81.999969  L96.120003,81.819977 L94.200005,85.419983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.200005,198.219986 L94.200005,219.939987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M94.200005,222.759995 L92.400002,219.039993 L92.879997,219.220001 C93.647011 219.671997,94.923012 219.610992,95.700005 219.220001  L96.120003,219.039993 L94.200005,222.759995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.200005,134.679993 L94.200005,170.799988" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M94.200005,173.619995 L92.400002,169.899994 L92.879997,170.079987 C94.730003 170.432007,93.848000 170.351990,95.700005 170.079987  L96.120003,169.899994 L94.200005,173.619995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.220009" y="173.619995" width="81.959999" height="30.660000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="53.220009" y="173.619995" width="81.959999" height="30.660000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.220009" y="28.119995" width="81.959999" height="24.540001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="53.220009" y="28.119995" width="81.959999" height="24.540001" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.339996" y="94.720001" width="81.959999" height="30.660000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="221.339996" y="94.720001" width="81.959999" height="30.660000" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.479980,110.079987 L160.319977,110.079987 L160.319977,121.119995 L221.339996,121.119995 L221.339996,112.839996" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M221.339996,110.079987 L223.139984,113.739990 L223.139984,113.859985 L222.720001,113.559998 C222.088989 113.315979,220.510986 113.295990,219.899994 113.559998  L219.480011,113.859985 L219.419983,113.739990 L221.339996,110.079987" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.540009,237.579987 L221.339996,237.579987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M135.720001,237.579987 L139.500000,235.779984 L139.260010,236.259979 L139.080017,236.679993 L139.020020,237.159988 L139.020020,238.119980 L139.080017,238.599991 L139.260010,239.079987 L139.500000,239.499985 L135.720001,237.579987" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.200005,247.359985 L94.200005,269.199982" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M94.200005,271.899994 L92.400002,268.239990 L92.879997,268.479980 C94.730003 268.832001,93.847008 268.752014,95.700005 268.479980  L96.120003,268.239990 L94.200005,271.899994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="53.220009" y="222.759995" width="81.959999" height="30.780001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="53.220009" y="222.759995" width="81.959999" height="30.780001" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M221.339996,237.579987 L274.619995,213.039978 L327.839996,237.579987 L274.619995,262.239990 L221.339996,237.579987" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M221.339996,237.579987 L274.619995,213.039978 L327.839996,237.579987 L274.619995,262.239990 L221.339996,237.579987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<rect x="53.220009" y="271.899994" width="81.959999" height="30.780001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="53.220009" y="271.899994" width="81.959999" height="30.780001" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="233.639984" y="280.659973" width="81.900002" height="30.719999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="233.639984" y="280.659973" width="81.900002" height="30.719999" stoke="black"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.619995,262.239990 L274.619995,277.839996" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M274.619995,280.659973 L272.760010,276.940002 L273.239990,277.179993 C273.855988 277.450989,275.436981 277.415985,276.059998 277.179993  L276.479980,276.940002 L274.619995,280.659973" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.320007,155.139984 L172.140015,155.139984 L138.120026,178.839996" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M135.179993,180.699982 L137.640015,176.259979 L137.820007,176.799988 C137.946014 177.759979,139.009003 179.266968,139.859985 179.739990  L140.279999,179.979980 L135.179993,180.699982" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.320007,175.599976 L172.140015,175.599976 L138.480011,187.839981" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M135.179993,188.979996 L138.720001,185.259995 L138.720001,186.459991 L138.839996,187.000000 L139.019989,187.539993 L139.260010,188.080002 L139.559998,188.619995 L140.279999,189.580002 L135.179993,188.979996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.320007,196.659988 L138.720001,196.659988" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M135.179993,196.659988 L139.859985,194.379990 L139.559998,194.919983 C139.139008 195.835983,139.139008 197.483994,139.559998 198.399994  L139.859985,198.939987 L135.179993,196.659988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M206.279999,204.279984 L308.760010,204.279984 L342.899994,187.899979 L240.420013,187.899979 L206.279999,204.279984" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M206.279999,204.279984 L308.760010,204.279984 L342.899994,187.899979 L240.420013,187.899979 L206.279999,204.279984" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M206.279999,183.819977 L308.760010,183.819977 L342.899994,167.439972 L240.420013,167.439972 L206.279999,183.819977" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M206.279999,183.819977 L308.760010,183.819977 L342.899994,167.439972 L240.420013,167.439972 L206.279999,183.819977" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M206.279999,163.359985 L308.760010,163.359985 L342.899994,146.979980 L240.420013,146.979980 L206.279999,163.359985" fill-rule="evenodd"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M206.279999,163.359985 L308.760010,163.359985 L342.899994,146.979980 L240.420013,146.979980 L206.279999,163.359985" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<text x="301.919983" y="153.880005" textLength="2.631159" font-size="8px">6</text>
<text x="297.909576" y="157.359985" textLength="4.047902" font-size="8px">0</text>
<text x="293.831818" y="157.359985" textLength="4.047902" font-size="8px">1</text>
<text x="291.790405" y="157.359985" textLength="2.023951" font-size="8px"> </text>
<text x="286.148834" y="157.359985" textLength="2.023951" font-size="8px"> </text>
<text x="280.090088" y="157.359985" textLength="2.023951" font-size="8px"> </text>
<text x="265.850342" y="157.359985" textLength="1.616249" font-size="8px">i</text>
<text x="264.204254" y="157.359985" textLength="1.616249" font-size="8px">l</text>
<text x="297.909576" y="177.819977" textLength="4.047902" font-size="8px">0</text>
<text x="293.831818" y="177.819977" textLength="4.047902" font-size="8px">1</text>
<text x="288.190247" y="177.819977" textLength="3.640200" font-size="8px">x</text>
<text x="286.148834" y="177.819977" textLength="2.023951" font-size="8px"> </text>
<text x="282.071075" y="177.819977" textLength="4.047902" font-size="8px">1</text>
<text x="280.090088" y="177.819977" textLength="2.023951" font-size="8px"> </text>
<text x="274.028412" y="177.819977" textLength="2.023951" font-size="8px"> </text>
<text x="271.574188" y="177.819977" textLength="2.424373" font-size="8px">r</text>
<text x="267.496429" y="177.819977" textLength="4.047902" font-size="8px">e</text>
<text x="275.769897" y="177.819977" textLength="4.251753" font-size="8px">=</text>
<text x="265.850342" y="177.819977" textLength="1.616249" font-size="8px">i</text>
<text x="264.204254" y="177.819977" textLength="1.616249" font-size="8px">l</text>
<text x="256.438263" y="177.819977" textLength="2.023951" font-size="8px">t</text>
<text x="254.792175" y="177.819977" textLength="1.616249" font-size="8px">l</text>
<text x="244.619995" y="177.819977" textLength="6.064573" font-size="8px">M</text>
<text x="303.299194" y="194.799988" textLength="2.631159" font-size="8px">2</text>
<text x="300.660004" y="194.799988" textLength="2.631159" font-size="8px">1</text>
<text x="296.623047" y="198.279984" textLength="4.047902" font-size="8px">0</text>
<text x="292.527832" y="198.279984" textLength="4.047902" font-size="8px">1</text>
<text x="290.486420" y="198.279984" textLength="2.023951" font-size="8px"> </text>
<text x="286.826569" y="198.279984" textLength="3.640200" font-size="8px">x</text>
<text x="284.845581" y="198.279984" textLength="2.023951" font-size="8px"> </text>
<text x="280.750366" y="198.279984" textLength="4.047902" font-size="8px">1</text>
<text x="278.708954" y="198.279984" textLength="2.023951" font-size="8px"> </text>
<text x="274.448456" y="198.279984" textLength="4.251753" font-size="8px">=</text>
<text x="266.080353" y="198.279984" textLength="4.047902" font-size="8px">e</text>
<text x="257.083954" y="198.279984" textLength="1.616249" font-size="8px">i</text>
<text x="255.102966" y="198.279984" textLength="2.023951" font-size="8px">t</text>
<text x="253.439392" y="198.279984" textLength="1.616249" font-size="8px">l</text>
<text x="249.360199" y="198.279984" textLength="4.047902" font-size="8px">u</text>
<text x="201.303101" y="192.820358" textLength="2.584542" font-size="8px">"</text>
<text x="196.862061" y="192.820358" textLength="4.448324" font-size="8px">T</text>
<text x="191.583038" y="192.820358" textLength="5.256449" font-size="8px">H</text>
<text x="185.343018" y="192.820358" textLength="2.584542" font-size="8px">"</text>
<text x="181.260895" y="192.820358" textLength="2.023951" font-size="8px">f</text>
<text x="201.962677" y="172.060303" textLength="2.584542" font-size="8px">"</text>
<text x="196.321838" y="172.060303" textLength="5.664151" font-size="8px">G</text>
<text x="190.983124" y="172.060303" textLength="5.256449" font-size="8px">H</text>
<text x="187.382965" y="172.060303" textLength="3.640200" font-size="8px">z</text>
<text x="182.701691" y="172.060303" textLength="2.023951" font-size="8px"> </text>
<text x="178.739716" y="172.060303" textLength="2.023951" font-size="8px">I</text>
<text x="187.626190" y="151.059998" textLength="3.640200" font-size="8px">z</text>
<text x="185.106445" y="151.059998" textLength="2.584542" font-size="8px">"</text>
<text x="178.979980" y="151.059998" textLength="2.023951" font-size="8px">I</text>
<text x="205.566742" y="247.599991" textLength="2.424373" font-size="8px">r</text>
<text x="201.489716" y="247.599991" textLength="4.047902" font-size="8px">e</text>
<text x="197.412689" y="247.599991" textLength="4.047902" font-size="8px">d</text>
<text x="194.952637" y="247.599991" textLength="2.424373" font-size="8px">r</text>
<text x="189.311066" y="247.599991" textLength="5.664151" font-size="8px">O</text>
<text x="183.192627" y="247.599991" textLength="4.047902" font-size="8px">e</text>
<text x="179.523315" y="247.599991" textLength="3.640200" font-size="8px">s</text>
<text x="172.992798" y="247.599991" textLength="4.047902" font-size="8px">e</text>
<text x="169.323486" y="247.599991" textLength="3.640200" font-size="8px">v</text>
<text x="157.979889" y="247.599991" textLength="2.023951" font-size="8px"> </text>
<text x="153.840973" y="247.599991" textLength="4.047902" font-size="8px">n</text>
<text x="151.859985" y="247.599991" textLength="2.023951" font-size="8px">I</text>
<text x="295.973328" y="303.940338" textLength="2.584542" font-size="8px">"</text>
<text x="279.734406" y="303.940338" textLength="4.448324" font-size="8px">Z</text>
<text x="277.133118" y="303.940338" textLength="2.584542" font-size="8px">"</text>
<text x="275.152130" y="303.940338" textLength="2.023951" font-size="8px"> </text>
<text x="270.831940" y="303.940338" textLength="4.251753" font-size="8px">=</text>
<text x="268.910645" y="303.940338" textLength="2.023951" font-size="8px"> </text>
<text x="265.310486" y="303.940338" textLength="3.640200" font-size="8px">s</text>
<text x="263.269775" y="303.940338" textLength="2.023951" font-size="8px">t</text>
<text x="261.636780" y="303.940338" textLength="1.616249" font-size="8px">i</text>
<text x="257.572144" y="303.940338" textLength="4.047902" font-size="8px">g</text>
<text x="67.265129" y="46.959747" textLength="4.047902" font-size="8px">e</text>
<text x="78.360909" y="290.200012" textLength="2.424373" font-size="8px">r</text>
<text x="251.644043" y="112.839996" textLength="4.047902" font-size="8px">p</text>
<text x="180.720703" y="172.060303" textLength="2.023951" font-size="8px">f</text>
<text x="119.494209" y="76.720032" textLength="1.616249" font-size="8px">i</text>
<text x="120.064064" y="46.959747" textLength="4.047902" font-size="8px">e</text>
<text x="52.275658" y="150.880005" textLength="6.064573" font-size="8px">m</text>
<text x="97.197487" y="290.200012" textLength="4.047902" font-size="8px">n</text>
<text x="187.923187" y="192.820358" textLength="3.640200" font-size="8px">z</text>
<text x="173.967590" y="232.779770" textLength="1.616249" font-size="8px">i</text>
<text x="41.580009" y="159.580078" textLength="4.047902" font-size="8px">a</text>
<text x="120.960670" y="112.839996" textLength="4.047902" font-size="8px">e</text>
<text x="101.017464" y="112.839996" textLength="6.064573" font-size="8px">M</text>
<text x="258.747528" y="198.279984" textLength="4.047902" font-size="8px">p</text>
<text x="109.079903" y="240.879990" textLength="2.424373" font-size="8px">r</text>
<text x="254.408752" y="245.079773" textLength="2.023951" font-size="8px"> </text>
<text x="282.864166" y="245.079773" textLength="2.023951" font-size="8px"> </text>
<text x="68.154930" y="150.880005" textLength="2.023951" font-size="8px"> </text>
<text x="104.598091" y="240.879990" textLength="4.448324" font-size="8px">F</text>
<text x="101.001015" y="38.199982" textLength="4.856027" font-size="8px">S</text>
<text x="159.960876" y="247.599991" textLength="5.256449" font-size="8px">R</text>
<text x="77.163582" y="191.739990" textLength="6.064573" font-size="8px">m</text>
<text x="68.607658" y="191.739990" textLength="2.023951" font-size="8px">t</text>
<text x="79.086311" y="46.959747" textLength="2.424373" font-size="8px">r</text>
<text x="260.065338" y="177.819977" textLength="4.047902" font-size="8px">p</text>
<text x="101.980064" y="240.879990" textLength="2.584542" font-size="8px">"</text>
<text x="108.599815" y="67.899841" textLength="2.023951" font-size="8px">t</text>
<text x="193.904236" y="232.779770" textLength="3.640200" font-size="8px">k</text>
<text x="105.905128" y="46.959747" textLength="2.023951" font-size="8px"> </text>
<text x="294.064392" y="294.279968" textLength="2.023951" font-size="8px"> </text>
<text x="99.663353" y="298.239777" textLength="4.047902" font-size="8px">u</text>
<text x="103.802254" y="298.239777" textLength="1.616249" font-size="8px">l</text>
<text x="318.779999" y="325.419983" textLength="4.248035" font-size="8px">O</text>
<text x="76.977318" y="150.880005" textLength="2.424373" font-size="8px">r</text>
<text x="191.264343" y="224.019989" textLength="1.616249" font-size="8px">i</text>
<text x="269.368500" y="245.079773" textLength="1.616249" font-size="8px">i</text>
<text x="87.656532" y="282.219971" textLength="3.640200" font-size="8px">s</text>
<text x="125.264641" y="76.720032" textLength="4.047902" font-size="8px">g</text>
<text x="65.700294" y="298.239777" textLength="4.448324" font-size="8px">F</text>
<text x="107.161400" y="112.839996" textLength="4.047902" font-size="8px">a</text>
<text x="90.829994" y="112.839996" textLength="4.047902" font-size="8px">n</text>
<text x="244.619995" y="157.359985" textLength="6.064573" font-size="8px">M</text>
<text x="104.508232" y="67.899841" textLength="4.047902" font-size="8px">a</text>
<text x="184.743103" y="172.060303" textLength="2.584542" font-size="8px">"</text>
<text x="126.170082" y="38.199982" textLength="4.047902" font-size="8px">n</text>
<text x="43.695702" y="150.880005" textLength="2.023951" font-size="8px">t</text>
<text x="185.699097" y="106.000000" textLength="3.640200" font-size="8px">s</text>
<text x="101.508217" y="282.219971" textLength="2.023951" font-size="8px"> </text>
<text x="61.980476" y="63.519989" textLength="3.640200" font-size="8px">z</text>
<text x="260.276733" y="236.319992" textLength="3.640200" font-size="8px">v</text>
<text x="187.269653" y="247.599991" textLength="2.023951" font-size="8px"> </text>
<text x="89.283974" y="46.959747" textLength="2.023951" font-size="8px"> </text>
<text x="111.537758" y="240.879990" textLength="4.047902" font-size="8px">e</text>
<text x="105.800987" y="38.199982" textLength="2.023951" font-size="8px">t</text>
<text x="100.238594" y="240.879990" textLength="2.023951" font-size="8px"> </text>
<text x="181.024323" y="151.059998" textLength="2.023951" font-size="8px">f</text>
<text x="185.522278" y="224.019989" textLength="1.616249" font-size="8px">i</text>
<text x="272.647278" y="198.279984" textLength="2.023951" font-size="8px"> </text>
<text x="264.461182" y="198.279984" textLength="1.616249" font-size="8px">i</text>
<text x="68.103477" y="112.839996" textLength="4.856027" font-size="8px">S</text>
<text x="94.851311" y="191.739990" textLength="2.584542" font-size="8px">"</text>
<text x="243.299988" y="198.279984" textLength="6.064573" font-size="8px">M</text>
<text x="61.980293" y="46.959747" textLength="5.256449" font-size="8px">R</text>
<text x="256.512115" y="294.279968" textLength="2.424373" font-size="8px">r</text>
<text x="80.820961" y="290.200012" textLength="4.047902" font-size="8px">e</text>
<text x="84.328011" y="240.879990" textLength="6.064573" font-size="8px">m</text>
<text x="79.437370" y="150.880005" textLength="4.047902" font-size="8px">e</text>
<text x="77.877922" y="159.580078" textLength="1.616249" font-size="8px">l</text>
<text x="74.112526" y="81.099976" textLength="3.640200" font-size="8px">z</text>
<text x="65.999977" y="72.220062" textLength="5.256449" font-size="8px">H</text>
<text x="274.028412" y="157.359985" textLength="2.023951" font-size="8px"> </text>
<text x="76.792976" y="38.199982" textLength="2.584542" font-size="8px">"</text>
<text x="271.557770" y="294.279968" textLength="4.251753" font-size="8px">=</text>
<text x="70.588661" y="191.739990" textLength="4.047902" font-size="8px">e</text>
<text x="113.221611" y="112.839996" textLength="3.640200" font-size="8px">c</text>
<text x="273.617004" y="112.839996" textLength="2.424373" font-size="8px">r</text>
<text x="83.584602" y="282.219971" textLength="4.047902" font-size="8px">e</text>
<text x="185.686127" y="232.779770" textLength="4.047902" font-size="8px">a</text>
<text x="45.676704" y="150.880005" textLength="4.047902" font-size="8px">e</text>
<text x="81.870155" y="240.879990" textLength="2.424373" font-size="8px">r</text>
<text x="255.893280" y="303.940338" textLength="1.616249" font-size="8px">i</text>
<text x="73.400047" y="282.219971" textLength="2.424373" font-size="8px">r</text>
<text x="259.860718" y="112.839996" textLength="2.424373" font-size="8px">r</text>
<text x="262.314941" y="112.839996" textLength="2.023951" font-size="8px">t</text>
<text x="81.541466" y="72.220062" textLength="2.023951" font-size="8px"> </text>
<text x="289.072235" y="303.940338" textLength="2.023951" font-size="8px">.</text>
<text x="77.788765" y="240.879990" textLength="4.047902" font-size="8px">e</text>
<text x="61.621010" y="112.839996" textLength="4.448324" font-size="8px">F</text>
<text x="116.464333" y="298.239777" textLength="4.047902" font-size="8px">e</text>
<text x="269.576050" y="294.279968" textLength="2.023951" font-size="8px"> </text>
<text x="191.286041" y="151.059998" textLength="5.256449" font-size="8px">H</text>
<text x="93.109840" y="191.739990" textLength="2.023951" font-size="8px"> </text>
<text x="68.498573" y="159.580078" textLength="1.616249" font-size="8px">l</text>
<text x="116.881462" y="112.839996" textLength="4.047902" font-size="8px">h</text>
<text x="58.306007" y="159.580078" textLength="6.064573" font-size="8px">M</text>
<text x="124.407570" y="191.739990" textLength="2.424373" font-size="8px">r</text>
<text x="270.175568" y="198.279984" textLength="2.424373" font-size="8px">r</text>
<text x="175.596954" y="232.779770" textLength="1.616249" font-size="8px">l</text>
<text x="177.226318" y="232.779770" textLength="2.023951" font-size="8px"> </text>
<text x="99.020012" y="38.199982" textLength="2.023951" font-size="8px"> </text>
<text x="274.134247" y="236.319992" textLength="4.047902" font-size="8px">e</text>
<text x="258.419250" y="157.359985" textLength="1.616249" font-size="8px">i</text>
<text x="250.714417" y="177.819977" textLength="4.047902" font-size="8px">u</text>
<text x="260.065338" y="157.359985" textLength="4.047902" font-size="8px">p</text>
<text x="117.041252" y="191.739990" textLength="1.616249" font-size="8px">l</text>
<text x="183.241882" y="192.820358" textLength="2.023951" font-size="8px"> </text>
<text x="296.106537" y="294.279968" textLength="1.616249" font-size="8px">i</text>
<text x="170.051453" y="224.019989" textLength="4.047902" font-size="8px">a</text>
<text x="280.249756" y="236.319992" textLength="5.256449" font-size="8px">D</text>
<text x="256.438263" y="157.359985" textLength="2.023951" font-size="8px">t</text>
<text x="87.535347" y="150.880005" textLength="2.584542" font-size="8px">"</text>
<text x="63.059975" y="38.199982" textLength="3.640200" font-size="8px">c</text>
<text x="124.528358" y="38.199982" textLength="1.616249" font-size="8px">i</text>
<text x="289.623352" y="294.279968" textLength="4.448324" font-size="8px">Z</text>
<text x="83.259880" y="298.239777" textLength="2.023951" font-size="8px"> </text>
<text x="96.157204" y="240.879990" textLength="4.047902" font-size="8px">e</text>
<text x="192.895874" y="224.019989" textLength="2.023951" font-size="8px">t</text>
<text x="94.881111" y="38.199982" textLength="4.047902" font-size="8px">d</text>
<text x="327.600403" y="325.419983" textLength="3.035871" font-size="8px">1</text>
<text x="68.519997" y="282.219971" textLength="4.856027" font-size="8px">P</text>
<text x="267.496429" y="157.359985" textLength="4.047902" font-size="8px">e</text>
<text x="91.325401" y="46.959747" textLength="4.856027" font-size="8px">B</text>
<text x="66.719826" y="38.199982" textLength="4.047902" font-size="8px">a</text>
<text x="124.202965" y="46.959747" textLength="2.424373" font-size="8px">r</text>
<text x="111.397667" y="76.720032" textLength="3.640200" font-size="8px">s</text>
<text x="284.821198" y="294.279968" textLength="4.856027" font-size="8px">Y</text>
<text x="84.900169" y="290.200012" textLength="4.047902" font-size="8px">q</text>
<text x="258.419250" y="177.819977" textLength="1.616249" font-size="8px">i</text>
<text x="34.320000" y="150.880005" textLength="5.256449" font-size="8px">D</text>
<text x="165.246460" y="247.599991" textLength="4.047902" font-size="8px">e</text>
<text x="55.785530" y="159.580078" textLength="2.584542" font-size="8px">"</text>
<text x="81.539085" y="46.959747" textLength="3.640200" font-size="8px">s</text>
<text x="167.869537" y="232.779770" textLength="4.047902" font-size="8px">n</text>
<text x="94.920921" y="282.219971" textLength="4.047902" font-size="8px">o</text>
<text x="284.199463" y="303.940338" textLength="4.856027" font-size="8px">Y</text>
<text x="70.015800" y="150.880005" textLength="2.584542" font-size="8px">"</text>
<text x="336.598297" y="325.419983" textLength="3.035871" font-size="8px">9</text>
<text x="70.793205" y="38.199982" textLength="4.047902" font-size="8px">n</text>
<text x="62.340126" y="72.220062" textLength="3.640200" font-size="8px">z</text>
<text x="166.451294" y="224.019989" textLength="3.640200" font-size="8px">c</text>
<text x="115.053154" y="76.720032" textLength="2.023951" font-size="8px">t</text>
<text x="115.987770" y="46.959747" textLength="4.047902" font-size="8px">d</text>
<text x="256.202637" y="236.319992" textLength="4.047902" font-size="8px">e</text>
<text x="81.540001" y="63.519989" textLength="2.023951" font-size="8px"> </text>
<text x="174.190369" y="224.019989" textLength="4.047902" font-size="8px">n</text>
<text x="194.935120" y="224.019989" textLength="3.640200" font-size="8px">s</text>
<text x="255.721802" y="112.839996" textLength="4.047902" font-size="8px">o</text>
<text x="263.943146" y="236.319992" textLength="4.047902" font-size="8px">e</text>
<text x="79.920372" y="282.219971" textLength="3.640200" font-size="8px">c</text>
<text x="301.919983" y="174.339996" textLength="2.631159" font-size="8px">9</text>
<text x="111.353798" y="191.739990" textLength="1.616249" font-size="8px">i</text>
<text x="268.017242" y="236.319992" textLength="2.424373" font-size="8px">r</text>
<text x="79.558998" y="63.519989" textLength="2.023951" font-size="8px">,</text>
<text x="76.919121" y="63.519989" textLength="2.584542" font-size="8px">"</text>
<text x="122.486931" y="38.199982" textLength="2.023951" font-size="8px"> </text>
<text x="289.645111" y="245.079773" textLength="4.047902" font-size="8px">a</text>
<text x="83.582893" y="72.220062" textLength="4.047902" font-size="8px">o</text>
<text x="245.820068" y="245.079773" textLength="4.448324" font-size="8px">T</text>
<text x="266.276917" y="112.839996" textLength="4.856027" font-size="8px">E</text>
<text x="252.010651" y="294.279968" textLength="4.448324" font-size="8px">F</text>
<text x="74.727562" y="191.739990" textLength="2.424373" font-size="8px">r</text>
<text x="295.401733" y="245.079773" textLength="4.047902" font-size="8px">u</text>
<text x="114.785469" y="298.239777" textLength="1.616249" font-size="8px">i</text>
<text x="202.682770" y="151.059998" textLength="2.584542" font-size="8px">"</text>
<text x="84.710075" y="112.839996" textLength="2.023951" font-size="8px">t</text>
<text x="288.190247" y="157.359985" textLength="3.640200" font-size="8px">x</text>
<text x="291.790405" y="177.819977" textLength="2.023951" font-size="8px"> </text>
<text x="291.248962" y="236.319992" textLength="1.616249" font-size="8px">i</text>
<text x="271.574188" y="157.359985" textLength="2.424373" font-size="8px">r</text>
<text x="88.901466" y="298.239777" textLength="2.023951" font-size="8px"> </text>
<text x="177.069824" y="247.599991" textLength="2.424373" font-size="8px">r</text>
<text x="117.034157" y="76.720032" textLength="2.424373" font-size="8px">r</text>
<text x="87.518623" y="159.580078" textLength="2.584542" font-size="8px">"</text>
<text x="275.769897" y="157.359985" textLength="4.251753" font-size="8px">=</text>
<text x="299.480927" y="245.079773" textLength="4.047902" font-size="8px">e</text>
<text x="261.647644" y="245.079773" textLength="4.047902" font-size="8px">e</text>
<text x="63.179817" y="298.239777" textLength="2.584542" font-size="8px">"</text>
<text x="183.005310" y="151.059998" textLength="2.023951" font-size="8px"> </text>
<text x="83.581429" y="63.519989" textLength="4.047902" font-size="8px">o</text>
<text x="323.040588" y="325.419983" textLength="4.548347" font-size="8px">M</text>
<text x="330.599701" y="325.419983" textLength="3.035871" font-size="8px">5</text>
<text x="333.598999" y="325.419983" textLength="3.035871" font-size="8px">1</text>
<text x="339.597595" y="325.419983" textLength="3.035871" font-size="8px">5</text>
<text x="196.562866" y="151.059998" textLength="6.064573" font-size="8px">M</text>
<text x="66.062050" y="112.839996" textLength="2.023951" font-size="8px"> </text>
<text x="72.903450" y="112.839996" textLength="4.047902" font-size="8px">u</text>
<text x="59.640007" y="112.839996" textLength="2.023951" font-size="8px">I</text>
<text x="76.982658" y="112.839996" textLength="4.047902" font-size="8px">b</text>
<text x="81.109917" y="112.839996" textLength="3.640200" font-size="8px">s</text>
<text x="293.784027" y="245.079773" textLength="1.616249" font-size="8px">l</text>
<text x="86.751503" y="112.839996" textLength="2.424373" font-size="8px">r</text>
<text x="250.714417" y="157.359985" textLength="4.047902" font-size="8px">u</text>
<text x="89.211555" y="112.839996" textLength="1.616249" font-size="8px">i</text>
<text x="94.909203" y="112.839996" textLength="4.047902" font-size="8px">g</text>
<text x="99.036461" y="112.839996" textLength="2.023951" font-size="8px"> </text>
<text x="111.240608" y="112.839996" textLength="2.023951" font-size="8px">t</text>
<text x="125.099571" y="112.839996" textLength="4.047902" font-size="8px">d</text>
<text x="59.459999" y="63.519989" textLength="2.584542" font-size="8px">"</text>
<text x="70.201759" y="298.239777" textLength="2.424373" font-size="8px">r</text>
<text x="65.640327" y="63.519989" textLength="5.256449" font-size="8px">H</text>
<text x="70.919350" y="63.519989" textLength="6.064573" font-size="8px">M</text>
<text x="77.760735" y="81.099976" textLength="5.256449" font-size="8px">H</text>
<text x="87.660637" y="63.519989" textLength="2.424373" font-size="8px">r</text>
<text x="282.779785" y="294.279968" textLength="2.023951" font-size="8px">.</text>
<text x="90.120689" y="63.519989" textLength="2.023951" font-size="8px"> </text>
<text x="59.819649" y="72.220062" textLength="2.584542" font-size="8px">"</text>
<text x="71.278999" y="72.220062" textLength="5.664151" font-size="8px">G</text>
<text x="85.301308" y="298.239777" textLength="3.640200" font-size="8px">x</text>
<text x="76.920586" y="72.220062" textLength="2.584542" font-size="8px">"</text>
<text x="79.560463" y="72.220062" textLength="2.023951" font-size="8px">,</text>
<text x="87.662102" y="72.220062" textLength="2.424373" font-size="8px">r</text>
<text x="71.519981" y="81.099976" textLength="2.584542" font-size="8px">"</text>
<text x="83.025185" y="81.099976" textLength="4.448324" font-size="8px">T</text>
<text x="87.481514" y="81.099976" textLength="2.584542" font-size="8px">"</text>
<text x="49.815605" y="150.880005" textLength="2.424373" font-size="8px">r</text>
<text x="58.335869" y="150.880005" textLength="1.616249" font-size="8px">i</text>
<text x="59.987785" y="150.880005" textLength="4.047902" font-size="8px">n</text>
<text x="89.039070" y="290.200012" textLength="4.047902" font-size="8px">u</text>
<text x="64.071358" y="150.880005" textLength="4.047902" font-size="8px">e</text>
<text x="72.536278" y="150.880005" textLength="4.448324" font-size="8px">F</text>
<text x="281.185303" y="245.079773" textLength="1.616249" font-size="8px">l</text>
<text x="83.576271" y="150.880005" textLength="4.047902" font-size="8px">q</text>
<text x="39.612129" y="150.880005" textLength="4.047902" font-size="8px">e</text>
<text x="64.548103" y="191.739990" textLength="4.047902" font-size="8px">e</text>
<text x="282.071075" y="157.359985" textLength="4.047902" font-size="8px">1</text>
<text x="45.652672" y="159.580078" textLength="4.047902" font-size="8px">n</text>
<text x="49.791573" y="159.580078" textLength="4.047902" font-size="8px">d</text>
<text x="53.864235" y="159.580078" textLength="2.023951" font-size="8px"> </text>
<text x="64.425911" y="159.580078" textLength="4.047902" font-size="8px">u</text>
<text x="70.139580" y="159.580078" textLength="2.023951" font-size="8px">t</text>
<text x="72.120583" y="159.580078" textLength="1.616249" font-size="8px">i</text>
<text x="73.739021" y="159.580078" textLength="4.047902" font-size="8px">p</text>
<text x="114.240669" y="67.899841" textLength="4.047902" font-size="8px">h</text>
<text x="79.518929" y="159.580078" textLength="1.616249" font-size="8px">i</text>
<text x="110.580818" y="67.899841" textLength="3.640200" font-size="8px">c</text>
<text x="81.159935" y="159.580078" textLength="4.047902" font-size="8px">e</text>
<text x="250.620087" y="303.940338" textLength="5.256449" font-size="8px">D</text>
<text x="294.908813" y="236.319992" textLength="3.640200" font-size="8px">s</text>
<text x="85.298836" y="159.580078" textLength="2.424373" font-size="8px">r</text>
<text x="71.649940" y="240.879990" textLength="4.047902" font-size="8px">e</text>
<text x="97.859688" y="154.360046" textLength="4.448324" font-size="8px">T</text>
<text x="102.300728" y="154.360046" textLength="2.424373" font-size="8px">r</text>
<text x="104.760780" y="154.360046" textLength="4.047902" font-size="8px">u</text>
<text x="262.842743" y="198.279984" textLength="1.616249" font-size="8px">l</text>
<text x="59.280006" y="191.739990" textLength="5.256449" font-size="8px">D</text>
<text x="89.050285" y="191.739990" textLength="4.047902" font-size="8px">e</text>
<text x="97.491188" y="191.739990" textLength="6.064573" font-size="8px">M</text>
<text x="103.611092" y="191.739990" textLength="4.047902" font-size="8px">u</text>
<text x="107.690300" y="191.739990" textLength="1.616249" font-size="8px">l</text>
<text x="109.318199" y="191.739990" textLength="2.023951" font-size="8px">t</text>
<text x="107.334480" y="76.720032" textLength="4.047902" font-size="8px">b</text>
<text x="112.981697" y="191.739990" textLength="4.047902" font-size="8px">p</text>
<text x="83.283485" y="191.739990" textLength="1.616249" font-size="8px">i</text>
<text x="179.990540" y="106.000000" textLength="4.047902" font-size="8px">a</text>
<text x="118.669151" y="191.739990" textLength="1.616249" font-size="8px">i</text>
<text x="120.348015" y="191.739990" textLength="4.047902" font-size="8px">e</text>
<text x="285.532410" y="236.319992" textLength="1.616249" font-size="8px">i</text>
<text x="126.627357" y="191.739990" textLength="2.584542" font-size="8px">"</text>
<text x="58.260002" y="38.199982" textLength="4.856027" font-size="8px">S</text>
<text x="74.932106" y="38.199982" textLength="2.023951" font-size="8px"> </text>
<text x="84.284492" y="38.199982" textLength="2.424373" font-size="8px">r</text>
<text x="86.734352" y="38.199982" textLength="4.047902" font-size="8px">a</text>
<text x="90.807732" y="38.199982" textLength="4.047902" font-size="8px">n</text>
<text x="107.842415" y="38.199982" textLength="2.424373" font-size="8px">r</text>
<text x="110.292274" y="38.199982" textLength="1.616249" font-size="8px">i</text>
<text x="111.933998" y="38.199982" textLength="4.047902" font-size="8px">n</text>
<text x="116.007378" y="38.199982" textLength="4.047902" font-size="8px">g</text>
<text x="249.479980" y="294.279968" textLength="2.584542" font-size="8px">"</text>
<text x="119.966454" y="38.199982" textLength="2.584542" font-size="8px">"</text>
<text x="71.341423" y="46.959747" textLength="3.640200" font-size="8px">v</text>
<text x="92.075813" y="240.879990" textLength="4.047902" font-size="8px">n</text>
<text x="85.207680" y="46.959747" textLength="4.047902" font-size="8px">e</text>
<text x="84.911385" y="191.739990" textLength="4.047902" font-size="8px">n</text>
<text x="96.125374" y="46.959747" textLength="3.640200" font-size="8px">y</text>
<text x="99.785225" y="46.959747" textLength="2.023951" font-size="8px">t</text>
<text x="101.766228" y="46.959747" textLength="4.047902" font-size="8px">e</text>
<text x="107.886131" y="46.959747" textLength="5.664151" font-size="8px">O</text>
<text x="113.527718" y="46.959747" textLength="2.424373" font-size="8px">r</text>
<text x="242.279999" y="112.839996" textLength="5.256449" font-size="8px">R</text>
<text x="264.295929" y="112.839996" textLength="2.023951" font-size="8px"> </text>
<text x="276.071228" y="112.839996" textLength="4.047902" font-size="8px">o</text>
<text x="280.148987" y="112.839996" textLength="2.424373" font-size="8px">r</text>
<text x="175.500000" y="106.000000" textLength="4.448324" font-size="8px">F</text>
<text x="184.080658" y="106.000000" textLength="1.616249" font-size="8px">l</text>
<text x="189.358948" y="106.000000" textLength="4.047902" font-size="8px">e</text>
<text x="161.579987" y="224.019989" textLength="4.856027" font-size="8px">S</text>
<text x="90.122154" y="72.220062" textLength="2.023951" font-size="8px"> </text>
<text x="75.848442" y="282.219971" textLength="4.047902" font-size="8px">o</text>
<text x="178.269562" y="224.019989" textLength="2.023951" font-size="8px"> </text>
<text x="179.279907" y="192.820358" textLength="2.023951" font-size="8px">I</text>
<text x="179.267731" y="232.779770" textLength="4.856027" font-size="8px">B</text>
<text x="180.250549" y="224.019989" textLength="5.256449" font-size="8px">D</text>
<text x="101.336388" y="290.200012" textLength="3.640200" font-size="8px">c</text>
<text x="79.402992" y="38.199982" textLength="4.856027" font-size="8px">B</text>
<text x="187.201141" y="224.019989" textLength="4.047902" font-size="8px">g</text>
<text x="198.535278" y="224.019989" textLength="2.023951" font-size="8px"> </text>
<text x="162.599976" y="232.779770" textLength="5.256449" font-size="8px">U</text>
<text x="171.930542" y="232.779770" textLength="2.023951" font-size="8px">t</text>
<text x="184.067688" y="232.779770" textLength="1.616249" font-size="8px">l</text>
<text x="189.825043" y="232.779770" textLength="4.047902" font-size="8px">n</text>
<text x="254.792175" y="157.359985" textLength="1.616249" font-size="8px">l</text>
<text x="98.399971" y="67.899841" textLength="6.064573" font-size="8px">M</text>
<text x="98.399971" y="76.720032" textLength="4.856027" font-size="8px">S</text>
<text x="103.271294" y="76.720032" textLength="4.047902" font-size="8px">u</text>
<text x="121.125740" y="76.720032" textLength="4.047902" font-size="8px">n</text>
<text x="66.360008" y="240.879990" textLength="5.256449" font-size="8px">D</text>
<text x="75.731331" y="240.879990" textLength="2.023951" font-size="8px">t</text>
<text x="90.426079" y="240.879990" textLength="1.616249" font-size="8px">i</text>
<text x="115.619148" y="240.879990" textLength="4.047902" font-size="8px">q</text>
<text x="119.517799" y="240.879990" textLength="2.584542" font-size="8px">"</text>
<text x="250.919983" y="236.319992" textLength="5.256449" font-size="8px">R</text>
<text x="93.592949" y="298.239777" textLength="6.064573" font-size="8px">M</text>
<text x="109.084190" y="298.239777" textLength="4.047902" font-size="8px">p</text>
<text x="267.045380" y="294.279968" textLength="2.584542" font-size="8px">"</text>
<text x="278.208344" y="236.319992" textLength="2.023951" font-size="8px"> </text>
<text x="287.174866" y="236.319992" textLength="4.047902" font-size="8px">g</text>
<text x="108.899681" y="154.360046" textLength="4.047902" font-size="8px">e</text>
<text x="292.927826" y="236.319992" textLength="2.023951" font-size="8px">t</text>
<text x="256.389740" y="245.079773" textLength="5.256449" font-size="8px">D</text>
<text x="271.162781" y="112.839996" textLength="2.424373" font-size="8px">r</text>
<text x="265.726837" y="245.079773" textLength="3.640200" font-size="8px">c</text>
<text x="270.467834" y="236.319992" textLength="3.640200" font-size="8px">s</text>
<text x="76.685677" y="298.239777" textLength="4.047902" font-size="8px">q</text>
<text x="270.986206" y="245.079773" textLength="6.064573" font-size="8px">m</text>
<text x="277.106110" y="245.079773" textLength="4.047902" font-size="8px">a</text>
<text x="284.845154" y="245.079773" textLength="4.856027" font-size="8px">V</text>
<text x="91.320763" y="282.219971" textLength="3.640200" font-size="8px">s</text>
<text x="99.059822" y="282.219971" textLength="2.424373" font-size="8px">r</text>
<text x="103.489220" y="282.219971" textLength="4.856027" font-size="8px">B</text>
<text x="108.369270" y="282.219971" textLength="4.047902" font-size="8px">a</text>
<text x="112.441200" y="282.219971" textLength="3.640200" font-size="8px">s</text>
<text x="116.105431" y="282.219971" textLength="4.047902" font-size="8px">e</text>
<text x="73.919868" y="290.200012" textLength="4.448324" font-size="8px">F</text>
<text x="93.118279" y="290.200012" textLength="4.047902" font-size="8px">e</text>
<text x="104.936546" y="290.200012" textLength="3.640200" font-size="8px">y</text>
<text x="108.596397" y="290.200012" textLength="2.023951" font-size="8px"> </text>
<text x="110.337868" y="290.200012" textLength="4.251753" font-size="8px">=</text>
<text x="72.631950" y="298.239777" textLength="4.047902" font-size="8px">e</text>
<text x="80.739403" y="298.239777" textLength="2.584542" font-size="8px">"</text>
<text x="291.053223" y="303.940338" textLength="4.856027" font-size="8px">X</text>
<text x="247.566284" y="112.839996" textLength="4.047902" font-size="8px">e</text>
<text x="91.002586" y="298.239777" textLength="2.584542" font-size="8px">"</text>
<text x="105.424324" y="298.239777" textLength="2.023951" font-size="8px">t</text>
<text x="107.405327" y="298.239777" textLength="1.616249" font-size="8px">i</text>
<text x="113.163399" y="298.239777" textLength="1.616249" font-size="8px">l</text>
<text x="75.010017" y="46.959747" textLength="4.047902" font-size="8px">e</text>
<text x="120.518059" y="298.239777" textLength="2.424373" font-size="8px">r</text>
<text x="122.678154" y="298.239777" textLength="2.584542" font-size="8px">"</text>
<text x="258.972168" y="294.279968" textLength="4.047902" font-size="8px">e</text>
<text x="263.051361" y="294.279968" textLength="4.047902" font-size="8px">q</text>
<text x="275.877960" y="294.279968" textLength="2.023951" font-size="8px"> </text>
<text x="277.859680" y="294.279968" textLength="4.856027" font-size="8px">X</text>
<text x="250.269836" y="245.079773" textLength="4.047902" font-size="8px">o</text>
<text x="297.724976" y="294.279968" textLength="2.023951" font-size="8px">f</text>
</svg>
<figcaption>Figure 3-10.  Algorithm for Extracting Processor Frequency
</figcaption></figure>
```
### The Processor Brand Index Method


The brand index method (introduced with Pentium\footnote{(R)}  III Xeon\footnote{(R)}  processors) provides an entry point into a brand identification table that is maintained in memory by system software and is accessible from system- and user-level code. In this table, each brand index is associate with an ASCII brand identification string that identifies the official Intel family and model number of a processor.

When CPUID executes with EAX set to 1, the processor returns a brand index to the low byte in EBX. Software can then use this index to locate the brand identification string for the processor in the brand identification table. The first entry (brand index 0) in this table is reserved, allowing for backward compatibility with processors that do not support the brand identification feature. Starting with processor signature family ID = 0FH, model = 03H, brand index method is no longer supported. Use brand string method instead.

Table 3-14 shows brand indices that have identification strings associated with them.

###      Table 3-14.  Mapping of Brand Indices; and Intel 64 and IA-32 Processor Brand Strings


NOTES:

1.Indicates versions of these processors that were introduced after the Pentium III 



|**Brand Index**|**Brand String**|
|---------------|----------------|
|00H|This processor does not support the brand identification feature|
|01H|Intel(R) Celeron(R) processor\footnote{1}|
|02H|Intel(R) Pentium(R) III processor\footnote{1}|
|03H|Intel(R) Pentium(R) III Xeon(R) processor; If processor signature = 000006B1h, then Intel(R) Celeron(R) processor|
|04H|Intel(R) Pentium(R) III processor|
|06H|Mobile Intel(R) Pentium(R) III processor-M|
|07H|Mobile Intel(R) Celeron(R) processor\footnote{1}|
|08H|Intel(R) Pentium(R) 4 processor|
|09H|Intel(R) Pentium(R) 4 processor|
|0AH|Intel(R) Celeron(R) processor\footnote{1}|
|0BH|Intel(R) Xeon(R) processor; If processor signature = 00000F13h, then Intel(R) Xeon(R) processor MP|
|0CH|Intel(R) Xeon(R) processor MP|
|0EH|Mobile Intel(R) Pentium(R) 4 processor-M; If processor signature = 00000F13h, then Intel(R) Xeon(R) processor|
|0FH|Mobile Intel(R) Celeron(R) processor\footnote{1}|
|11H|Mobile Genuine Intel(R) processor|
|12H|Intel(R) Celeron(R) M processor|
|13H|Mobile Intel(R) Celeron(R) processor\footnote{1}|
|14H|Intel(R) Celeron(R) processor|
|15H|Mobile Genuine Intel(R) processor|
|16H|Intel(R) Pentium(R) M processor|
|17H|Mobile Intel(R) Celeron(R) processor\footnote{1}|
|18H - 0FFH|RESERVED|
### IA-32 Architecture Compatibility


CPUID is not supported in early models of the Intel486 processor or in any IA-32 processor earlier than the Intel486 processor.


### Operation

```info-verb
IA32_BIOS_SIGN_ID MSR <- Update with installed microcode revision number;
CASE (EAX) OF
 EAX = 0:
   EAX <- Highest basic function input value understood by CPUID;
   EBX <- Vendor identification string;
   EDX <- Vendor identification string;
   ECX <- Vendor identification string;
 BREAK;
 EAX = 1H:
   EAX[3:0] <- Stepping ID; 
   EAX[7:4] <- Model; 
   EAX[11:8] <- Family; 
   EAX[13:12] <- Processor type; 
   EAX[15:14] <- Reserved;
   EAX[19:16] <- Extended Model;
   EAX[27:20] <- Extended Family;
   EAX[31:28] <- Reserved;
   EBX[7:0] <- Brand Index; (\htmlonly{*} Reserved if the value is zero. \htmlonly{*})
   EBX[15:8] <- CLFLUSH Line Size;
   EBX[16:23] <- Reserved; (\htmlonly{*} Number of threads enabled = 2 if MT enable fuse set. \htmlonly{*})
   EBX[24:31] <- Initial APIC ID;
   ECX <- Feature flags; (\htmlonly{*} See Figure3-7. \htmlonly{*})
   EDX <- Feature flags; (\htmlonly{*} See Figure3-8. \htmlonly{*})
 BREAK;
 EAX = 2H:
   EAX <- Cache and TLB information; 
  EBX <- Cache and TLB information; 
  ECX <- Cache and TLB information; 
   EDX <- Cache and TLB information; 
 BREAK;
 EAX = 3H:
   EAX <- Reserved; 
  EBX <- Reserved; 
  ECX <- ProcessorSerialNumber[31:0]; 
   (\htmlonly{*} Pentium III processors only, otherwise reserved. \htmlonly{*})
   EDX <- ProcessorSerialNumber[63:32]; 
   (\htmlonly{*} Pentium III processors only, otherwise reserved. \htmlonly{*}
 BREAK
 EAX = 4H:
   EAX <- Deterministic Cache Parameters Leaf; (\htmlonly{*} See Table 3-8. \htmlonly{*})
   EBX <- Deterministic Cache Parameters Leaf; 
  ECX <- Deterministic Cache Parameters Leaf; 
   EDX <- Deterministic Cache Parameters Leaf; 
 BREAK;
 EAX = 5H:
   EAX <- MONITOR/MWAIT Leaf; (\htmlonly{*} See Table 3-8. \htmlonly{*})
  EBX <- MONITOR/MWAIT Leaf; 
  ECX <- MONITOR/MWAIT Leaf; 
   EDX <- MONITOR/MWAIT Leaf; 
 BREAK;
EAX = 6H:
   EAX <- Thermal and Power Management Leaf; (* See Table 3-8. *)
  EBX <- Thermal and Power Management Leaf; 
  ECX <- Thermal and Power Management Leaf; 
   EDX <- Thermal and Power Management Leaf; 
 BREAK;
 EAX = 7H:
   EAX <- Structured Extended Feature Flags Enumeration Leaf; (* See Table 3-8. *)
   EBX <- Structured Extended Feature Flags Enumeration Leaf; 
  ECX <- Structured Extended Feature Flags Enumeration Leaf; 
   EDX <- Structured Extended Feature Flags Enumeration Leaf; 
 BREAK;
 EAX = 8H:
   EAX <- Reserved = 0;
  EBX <- Reserved = 0; 
  ECX <- Reserved = 0; 
   EDX <- Reserved = 0; 
 BREAK;
 EAX = 9H:
   EAX <- Direct Cache Access Information Leaf; (* See Table 3-8. *)
  EBX <- Direct Cache Access Information Leaf; 
  ECX <- Direct Cache Access Information Leaf; 
   EDX <- Direct Cache Access Information Leaf; 
 BREAK;
 EAX = AH:
   EAX <- Architectural Performance Monitoring Leaf; (* See Table 3-8. *)
  EBX <- Architectural Performance Monitoring Leaf; 
  ECX <- Architectural Performance Monitoring Leaf; 
   EDX <- Architectural Performance Monitoring Leaf; 
   BREAK
 EAX = BH:
   EAX <- Extended Topology Enumeration Leaf; (* See Table 3-8. *)
   EBX <- Extended Topology Enumeration Leaf; 
  ECX <- Extended Topology Enumeration Leaf; 
   EDX <- Extended Topology Enumeration Leaf; 
 BREAK;
 EAX = CH:
   EAX <- Reserved = 0;
  EBX <- Reserved = 0; 
  ECX <- Reserved = 0; 
   EDX <- Reserved = 0; 
 BREAK;
 EAX = DH:
   EAX <- Processor Extended State Enumeration Leaf; (* See Table 3-8. *)
  EBX <- Processor Extended State Enumeration Leaf; 
  ECX <- Processor Extended State Enumeration Leaf; 
   EDX <- Processor Extended State Enumeration Leaf; 
 BREAK;
 EAX = EH:
   EAX <- Reserved = 0;
  EBX <- Reserved = 0; 
  ECX <- Reserved = 0; 
   EDX <- Reserved = 0; 
 BREAK;
EAX = FH:
   EAX <- Intel Resource Director Technology Monitoring Enumeration Leaf; (* See Table 3-8. *)
  EBX <- Intel Resource Director Technology Monitoring Enumeration Leaf; 
  ECX <- Intel Resource Director Technology Monitoring Enumeration Leaf; 
   EDX <- Intel Resource Director Technology Monitoring Enumeration Leaf; 
 BREAK;
 EAX = 10H:
   EAX <- Intel Resource Director Technology Allocation Enumeration Leaf; (* See Table 3-8. *)
  EBX <- Intel Resource Director Technology Allocation Enumeration Leaf; 
  ECX <- Intel Resource Director Technology Allocation Enumeration Leaf; 
   EDX <- Intel Resource Director Technology Allocation Enumeration Leaf; 
 BREAK;
   EAX = 12H:
   EAX <- Intel SGX Enumeration Leaf; (* See Table 3-8. *)
  EBX <- Intel SGX Enumeration Leaf; 
  ECX <- Intel SGX Enumeration Leaf; 
   EDX <- Intel SGX Enumeration Leaf; 
 BREAK;
 EAX = 14H:
   EAX <- Intel Processor Trace Enumeration Leaf; (* See Table 3-8. *)
  EBX <- Intel Processor Trace Enumeration Leaf; 
  ECX <- Intel Processor Trace Enumeration Leaf; 
   EDX <- Intel Processor Trace Enumeration Leaf; 
 BREAK;
 EAX = 15H:
   EAX <- Time Stamp Counter and Nominal Core Crystal Clock Information Leaf; (* See Table 3-8. *)
  EBX <- Time Stamp Counter and Nominal Core Crystal Clock Information Leaf; 
  ECX <- Time Stamp Counter and Nominal Core Crystal Clock Information Leaf; 
   EDX <- Time Stamp Counter and Nominal Core Crystal Clock Information Leaf; 
 BREAK;
 EAX = 16H:
   EAX <- Processor Frequency Information Enumeration Leaf; (* See Table 3-8. *)
  EBX <- Processor Frequency Information Enumeration Leaf; 
  ECX <- Processor Frequency Information Enumeration Leaf; 
   EDX <- Processor Frequency Information Enumeration Leaf; 
 BREAK;
 EAX = 17H:
   EAX <- System-On-Chip Vendor Attribute Enumeration Leaf; (* See Table 3-8. *)
  EBX <- System-On-Chip Vendor Attribute Enumeration Leaf; 
  ECX <- System-On-Chip Vendor Attribute Enumeration Leaf; 
   EDX <- System-On-Chip Vendor Attribute Enumeration Leaf; 
 BREAK;
 EAX = 80000000H:
   EAX <- Highest extended function input value understood by CPUID;
   EBX <- Reserved; 
   ECX <- Reserved; 
   EDX <- Reserved; 
 BREAK;
 EAX = 80000001H:
   EAX <- Reserved; 
   EBX <- Reserved; 
   ECX <- Extended Feature Bits (* See Table 3-8.*); 
   EDX <- Extended Feature Bits (* See Table 3-8. *); 
 BREAK;
EAX = 80000002H:
   EAX <- Processor Brand String; 
   EBX <- Processor Brand String, continued;
   ECX <- Processor Brand String, continued; 
   EDX <- Processor Brand String, continued; 
 BREAK;
 EAX = 80000003H:
   EAX <- Processor Brand String, continued; 
   EBX <- Processor Brand String, continued; 
   ECX <- Processor Brand String, continued; 
   EDX <- Processor Brand String, continued; 
 BREAK;
 EAX = 80000004H:
   EAX <- Processor Brand String, continued; 
   EBX <- Processor Brand String, continued; 
   ECX <- Processor Brand String, continued; 
   EDX <- Processor Brand String, continued;
 BREAK;
 EAX = 80000005H:
   EAX <- Reserved = 0; 
   EBX <- Reserved = 0; 
   ECX <- Reserved = 0; 
   EDX <- Reserved = 0; 
 BREAK;
 EAX = 80000006H:
   EAX <- Reserved = 0; 
   EBX <- Reserved = 0; 
   ECX <- Cache information; 
   EDX <- Reserved = 0; 
 BREAK;
 EAX = 80000007H:
   EAX <- Reserved = 0; 
   EBX <- Reserved = 0; 
   ECX <- Reserved = 0; 
   EDX <- Reserved = Misc Feature Flags; 
 BREAK;
 EAX = 80000008H:
   EAX <- Reserved = Physical Address Size Information; 
   EBX <- Reserved = Virtual Address Size Information; 
   ECX <- Reserved = 0; 
   EDX <- Reserved = 0; 
 BREAK;
 EAX >= 40000000H and EAX <= 4FFFFFFFH:
 DEFAULT: (* EAX = Value outside of recognized range for CPUID. *)
   (* If the highest basic information leaf data depend on ECX input value, ECX is honored.*)
   EAX <- Reserved; (* Information returned for highest basic information leaf. *)
   EBX <- Reserved; (* Information returned for highest basic information leaf. *)
   ECX <- Reserved; (* Information returned for highest basic information leaf. *)
   EDX <- Reserved; (* Information returned for highest basic information leaf. *)
 BREAK;
ESAC;
```
### Flags Affected


None.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

         In earlier IA-32 processors that do not support the CPUID instruction, execution of the instruc-tion results in an invalid opcode (#UD) exception being generated.

