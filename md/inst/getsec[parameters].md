----------------------------
title : GETSEC[PARAMETERS] (Intel x86/64 assembly instruction)
cat_title : GETSEC[PARAMETERS]
ref_title : GETSEC[PARAMETERS]
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/G
publish_date: 2020-09-01
----------------------------
#@ GETSEC[PARAMETERS]

**Report the SMX Parameters**### Description


The `GETSEC[PARAMETERS]` instruction returns specific parameter information for SMX features supported by the processor. Parameter information is returned in EAX, EBX, and ECX, with the input parameter selected using EBX.

Software retrieves parameter information by searching with an input index for EBX starting at 0, and then reading the returned results in EAX, EBX, and ECX. EAX[4:0] is designated to return a parameter type field indicating if a parameter is available and what type it is. If EAX[4:0] is returned with 0, this designates a null parameter and indi-cates no more parameters are available. 

Table 6-7 defines the parameter types supported in current and future implementations.

### Table 6-7.  SMX Reporting Parameters Format 


|**Parameter **\newline{}**Type EAX[4:0]**|**Parameter Description**|**EAX[31:5]**|**EBX[31:0]**|**ECX[31:0]**|
|-----------------------------------------|-------------------------|-------------|-------------|-------------|
|0|NULL|Reserved (0 returned)|Reserved (unmodified)|Reserved (unmodified)|
|1|Supported AC module versions|Reserved (0 returned)|Version comparison mask|Version numbers supported|
|2|Max size of authenticated code execution area|Multiply by 32 for size in bytes|Reserved (unmodified)|Reserved (unmodified)|
|3|External memory types supported during AC mode|Memory type bit mask|Reserved (unmodified)|Reserved (unmodified)|
|4|Selective SENTER functionality control|EAX[14:8] correspond to available SENTER function disable controls|Reserved (unmodified)|Reserved (unmodified)|
|5|TXT extensions support|TXT Feature Extensions Flags (see Table6-8)|Reserved |Reserved |
|6-31|Undefined|Reserved (unmodified)|Reserved (unmodified)|Reserved (unmodified)|
###                                                       Table 6-8.  TXT Feature Extensions Flags


Supported AC module versions (as defined by the AC module HeaderVersion field) can be determined for a partic-ular SMX capable processor by the type 1 parameter. Using EBX to index through the available parameters reported by GETSEC[PARAMETERS] for each unique parameter set returned for type 1, software can determine the complete list of AC module version(s) supported. 

For each parameter set, EBX returns the comparison mask and ECX returns the available HeaderVersion field values supported, after AND'ing the target HeaderVersion with the comparison mask. Software can then determine if a particular AC module version is supported by following the pseudo-code search routine given below:

parameter_search_index= 0do {EBX= parameter_search_index++EAX= 6GETSECif (EAX[4:0] = 1) {if ((version_query & EBX) = ECX) {version_is_supported= 1break}}

} while (EAX[4:0] ->  0)

If only AC modules with a HeaderVersion of 0 are supported by the processor, then only one parameter set of type 1 will be returned, as follows: EAX = 00000001H, 

EBX = FFFFFFFFH and ECX = 00000000H.

The maximum capacity for an authenticated code execution area supported by the processor is reported with the parameter type of 2. The maximum supported size in bytes is determined by multiplying the returned size in EAX[31:5] by 32. Thus, for a maximum supported authenticated RAM size of 32KBytes, EAX returns with 00008002H. 

Supportable memory types for memory mapped outside of the authenticated code execution area are reported with the parameter type of 3. While is active, as initiated by the GETSEC functions SENTER and ENTERACCS and terminated by EXITAC, there are restrictions on what memory types are allowed for the rest of system memory. It is the responsibility of the system software to initialize the memory type range register (MTRR) MSRs and/or the page attribute table (PAT) to only map memory types consistent with the reporting of this parameter. The reporting of supportable memory types of external memory is indicated using a bit map returned in EAX[31:8]. These bit positions correspond to the memory type encodings defined for the MTRR MSR and PAT programming. See Table 6-9.

The parameter type of 4 is used for enumerating the availability of selective GETSEC[SENTER] function disable controls. If a 1 is reported in bits 14:8 of the returned parameter EAX, then this indicates a disable control capa-



|**Bit**|**Definition**|**Description**|
|-------|--------------|---------------|
|5|Processor based S-CRTM support|Returns 1 if this processor implements a processor-rooted S-CRTM capability and 0 if not (S-CRTM is rooted in BIOS).This flag cannot be used to infer whether the chipset supports TXT or whether the processor support SMX.|
|6|Machine Check Handling|Returns 1 if it machine check status registers can be preserved through ENTERACCS and SENTER. If this bit is 1, the caller of ENTERACCS and SENTER is not required to clear machine check error status bits before invoking these GETSEC leaves.\newline{}If this bit returns 0, the caller of ENTERACCS and SENTER must clear all machine check error status bits before invoking these GETSEC leaves.|
|31:7|Reserved|Reserved for future use. Will return 0.|


bility exists with SENTER for a particular function. The enumerated field in bits 14:8 corresponds to use of the EDX input parameter bits 6:0 for SENTER. If an enumerated field bit is set to 1, then the corresponding EDX input parameter bit of EDX may be set to 1 to disable that designated function. If the enumerated field bit is 0 or this parameter is not reported, then no disable capability exists with the corresponding EDX input parameter for SENTER, and EDX bit(s) must be cleared to 0 to enable execution of SENTER. If no selective disable capability for SENTER exists as enumerated, then the corresponding bits in the IA32_FEATURE_CONTROL MSR bits 14:8 must also be programmed to 1 if the SENTER global enable bit 15 of the MSR is set. This is required to enable future extensibility of SENTER selective disable capability with respect to potentially separate software initialization of the MSR.

###                                              Table 6-9.  External Memory Types Using Parameter 3


If the GETSEC[PARAMETERS] leaf or specific parameter is not present for a given SMX capable processor, then default parameter values should be assumed. These are defined in Table 6-10.



|**EAX Bit Position**|**Parameter Description**|
|--------------------|-------------------------|
|8\newline{}9\newline{}11:10\newline{}12\newline{}13\newline{}14\newline{}31:15|Uncacheable (UC)\newline{}Write Combining (WC)\newline{}Reserved\newline{}Write-through (WT)\newline{}Write-protected (WP)\newline{}Write-back (WB)\newline{}Reserved|
### Table 6-10.  Default Parameter Values


|**Parameter Type EAX[4:0]**|**Default Setting**|**Parameter Description**|
|---------------------------|-------------------|-------------------------|
|1\newline{}2\newline{}3\newline{}4|0.0 only\newline{}32 KBytes\newline{}UC only\newline{}None|Supported AC module versions. \newline{}Authenticated code execution area size.\newline{}External memory types supported during AC execution mode.\newline{}Available SENTER selective disable controls.|

### Operation

```info-verb
(* example of a processor supporting only a 0.0 HeaderVersion, 32K ACRAM size, memory types UC and WC *)
IF (CR4.SMXE=0)
    THEN #UD;
ELSE IF (in VMX non-root operation)
    THEN VM Exit (reason="GETSEC instruction");
ELSE IF (GETSEC leaf unsupported)
    THEN #UD;
    (* example of a processor supporting a 0.0 HeaderVersion *)
IF (EBX=0) THEN
    EAX<- 00000001h;
    EBX<- FFFFFFFFh;
    ECX<- 00000000h;
ELSE IF (EBX=1)
    (* example of a processor supporting a 32K ACRAM size *)
THEN EAX<- 00008002h;
ESE IF (EBX= 2)
    (* example of a processor supporting external memory types of UC and WC *)
    THEN EAX<- 00000303h;
ESE IF (EBX= other value(s) less than unsupported index value)
    (* EAX value varies. Consult Table 6-7 and Table 6-8*)
ELSE (* unsupported index*)
    EAX'' 00000000h;
END;
```
### Flags Affected


None.

### Use of Prefixes


LOCK Causes #UD.

REP\htmlonly{*} Cause #UD (includes REPNE/REPNZ and REP/REPE/REPZ).

Operand size Causes #UD.

Segment overrides Ignored.

Address size Ignored.

REX Ignored.


### Protected Mode Exceptions

#### #UD
* If CR4.SMXE = 0.
* If GETSEC[PARAMETERS] is not reported as supported by GETSEC[CAPABILITIES].

### Real-Address Mode Exceptions

#### #UD
* If CR4.SMXE = 0.
* If GETSEC[PARAMETERS] is not reported as supported by GETSEC[CAPABILITIES].

### Virtual-8086 Mode Exceptions

#### #UD
* If CR4.SMXE = 0.
* If GETSEC[PARAMETERS] is not reported as supported by GETSEC[CAPABILITIES].

### Compatibility Mode Exceptions



All protected mode exceptions apply.


### 64-Bit Mode Exceptions



All protected mode exceptions apply.

### VM-Exit Condition


Reason (GETSEC) IF in VMX non-root operation.

