### INVPCID--Invalidate Process-Context Identifier


|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32-**\newline{}**bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|66 0F 38 82 /rINVPCID r32, m128|RM|NE/V|INVPCID|Invalidates entries in the TLBs and paging-structure caches based on invalidation type in r32 and descrip-tor in m128.|
|66 0F 38 82 /rINVPCID r64, m128|RM|V/NE|INVPCID|Invalidates entries in the TLBs and paging-structure caches based on invalidation type in r64 and descrip-tor in m128.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (R)|ModRM:r/m (R)|NA|NA|
### Description


Invalidates mappings in the translation lookaside buffers (TLBs) and paging-structure caches based on process-context identifier (PCID). (See Section 4.10, "Caching Translation Information," in Intel64 and IA-32 Architecture Software Developer's Manual, Volume 3A.) Invalidation is based on the INVPCID type specified in the register operand and the INVPCID descriptor specified in the memory operand.

Outside 64-bit mode, the register operand is always 32 bits, regardless of the value of CS.D. In 64-bit mode the register operand has 64 bits.

There are four INVPCID types currently defined:

*  Individual-address invalidation: If the INVPCID type is 0, the logical processor invalidates mappings--except global translations--for the linear address and PCID specified in the INVPCID descriptor.\footnote{1}  In some cases, the instruction may invalidate global translations or mappings for other linear addresses (or other PCIDs) as well.

*  Single-context invalidation: If the INVPCID type is 1, the logical processor invalidates all mappings--except global translations--associated with the PCID specified in the INVPCID descriptor. In some cases, the instruction may invalidate global translations or mappings for other PCIDs as well.

*  All-context invalidation, including global translations: If the INVPCID type is 2, the logical processor invalidates all mappings--including global translations--associated with any PCID. 

*  All-context invalidation: If the INVPCID type is 3, the logical processor invalidates all mappings--except global translations--associated with any PCID. In some case, the instruction may invalidate global translations as well. 

The INVPCID descriptor comprises 128 bits and consists of a PCID and a linear address as shown in Figure 3-24. For INVPCID type 0, the processor uses the full 64 bits of the linear address even outside 64-bit mode; the linear address is not used for other INVPCID types.

```embed
<figure>
<svg viewBox="0 0 379.679993 102.080002">
<rect x="0.000000" y="10.059982" width="0.480000" height="74.879997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.059982" width="0.479980" height="74.879997" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520004" width="379.679993" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="84.940018" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="41.460007" y="38.799988" width="306.059998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="41.460007" y="38.319992" width="306.600006" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="347.039978" y="38.800003" width="1.020000" height="18.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="40.979996" y="56.319992" width="306.540009" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="40.979996" y="38.319992" width="1.020000" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="194.520004" y="38.799988" width="124.260002" height="18.000000" fill-rule="nonzero"  fill=" rgb(179,179,179) " stroke="black" />
<rect x="194.520004" y="38.319992" width="124.800003" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="318.299988" y="38.800003" width="1.020000" height="18.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="194.039993" y="56.319992" width="124.739998" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="194.039993" y="38.319992" width="1.020000" height="18.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="328.281311" y="50.500183" textLength="6.536916" font-size="8px">C</text>
<text x="322.281250" y="50.500183" textLength="6.038951" font-size="8px">P</text>
<text x="139.658676" y="50.500183" textLength="4.526950" font-size="8px">s</text>
<text x="134.669067" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="131.698486" y="50.500183" textLength="3.014949" font-size="8px">r</text>
<text x="126.708878" y="50.500183" textLength="5.033968" font-size="8px">d</text>
<text x="121.719269" y="50.500183" textLength="5.033968" font-size="8px">d</text>
<text x="113.203171" y="50.500183" textLength="2.516984" font-size="8px"> </text>
<text x="105.242981" y="50.500183" textLength="5.033968" font-size="8px">a</text>
<text x="93.249268" y="50.500183" textLength="2.009966" font-size="8px">i</text>
<text x="88.259659" y="50.500183" textLength="5.033968" font-size="8px">L</text>
<text x="295.000793" y="50.500183" textLength="3.014949" font-size="8px">r</text>
<text x="290.008484" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="285.523193" y="50.500183" textLength="4.526950" font-size="8px">z</text>
<text x="283.001709" y="50.500183" textLength="2.516984" font-size="8px"> </text>
<text x="278.009399" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="270.495544" y="50.500183" textLength="2.516984" font-size="8px"> </text>
<text x="267.974060" y="50.500183" textLength="2.516984" font-size="8px">t</text>
<text x="263.488770" y="50.500183" textLength="4.526950" font-size="8px">s</text>
<text x="250.996201" y="50.500183" textLength="7.541899" font-size="8px">m</text>
<text x="248.022903" y="50.500183" textLength="3.014949" font-size="8px">(</text>
<text x="240.582413" y="50.500183" textLength="5.033968" font-size="8px">d</text>
<text x="235.543930" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="231.058640" y="50.500183" textLength="4.526950" font-size="8px">v</text>
<text x="213.615433" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="343.915527" y="35.199997" textLength="5.033968" font-size="8px">0</text>
<text x="194.877457" y="35.199997" textLength="5.033968" font-size="8px">6</text>
<text x="218.607742" y="50.500183" textLength="4.526950" font-size="8px">s</text>
<text x="42.838745" y="35.199997" textLength="5.033968" font-size="8px">2</text>
<text x="334.773865" y="50.500183" textLength="2.516984" font-size="8px">I</text>
<text x="110.232590" y="50.500183" textLength="3.014949" font-size="8px">r</text>
<text x="207.120163" y="50.500183" textLength="6.536916" font-size="8px">R</text>
<text x="188.338730" y="35.199997" textLength="5.033968" font-size="8px">4</text>
<text x="323.399353" y="35.199997" textLength="5.033968" font-size="8px">1</text>
<text x="319.080688" y="35.199997" textLength="5.033968" font-size="8px">1</text>
<text x="47.817490" y="35.199997" textLength="5.033968" font-size="8px">7</text>
<text x="297.974121" y="50.500183" textLength="5.033968" font-size="8px">o</text>
<text x="144.141251" y="50.500183" textLength="4.526950" font-size="8px">s</text>
<text x="199.856186" y="35.199997" textLength="5.033968" font-size="8px">3</text>
<text x="183.360001" y="35.199997" textLength="5.033968" font-size="8px">6</text>
<text x="258.496460" y="50.500183" textLength="5.033968" font-size="8px">u</text>
<text x="100.253372" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="228.085342" y="50.500183" textLength="3.014949" font-size="8px">r</text>
<text x="337.295349" y="50.500183" textLength="6.536916" font-size="8px">D</text>
<text x="245.561142" y="50.500183" textLength="2.516984" font-size="8px"> </text>
<text x="115.724686" y="50.500183" textLength="6.038951" font-size="8px">A</text>
<text x="223.093033" y="50.500183" textLength="5.033968" font-size="8px">e</text>
<text x="307.560486" y="35.199997" textLength="5.033968" font-size="8px">1</text>
<text x="273.017090" y="50.500183" textLength="5.033968" font-size="8px">b</text>
<text x="312.539246" y="35.199997" textLength="5.033968" font-size="8px">2</text>
<text x="95.214874" y="50.500183" textLength="5.033968" font-size="8px">n</text>
<text x="302.966431" y="50.500183" textLength="3.014949" font-size="8px">)</text>
<text x="37.860001" y="35.199997" textLength="5.033968" font-size="8px">1</text>
</svg>
<figcaption>Figure 3-24.  INVPCID Descriptor
</figcaption></figure>
```


1.If the paging structures map the linear address using a page larger than 4 KBytes and there are multiple TLB entries for that page (see Section 4.10.2.3, "Details of TLB Use," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A), the instruction invalidates all of them.



If CR4.PCIDE= 0, a logical processor does not cache information for any PCID other than 000H. In this case, executions with INVPCID types 0 and 1 are allowed only if the PCID specified in the INVPCID descriptor is 000H; executions with INVPCID types 2 and 3 invalidate mappings only for PCID 000H. Note that CR4.PCIDE must be 0 outside 64-bit mode (see Chapter 4.10.1, "Process-Context Identifiers (PCIDs)," of the Intel(R) 64 and IA-32 Archi-tectures Software Developer's Manual, Volume 3A).


### Operation

```info-verb
INVPCID_TYPE <- value of register operand;  // must be in the range of 0-3
INVPCID_DESC <- value of memory operand;
CASE INVPCID_TYPE OF
 0: // individual-address invalidation
   PCID <- INVPCID_DESC[11:0];
   L_ADDR <- INVPCID_DESC[127:64];
   Invalidate mappings for L_ADDR associated with PCID except global translations;
   BREAK;
 1: // single PCID invalidation
   PCID <- INVPCID_DESC[11:0];
   Invalidate all mappings associated with PCID except global translations;
   BREAK;
 2: // all PCID invalidation including global translations
   Invalidate all mappings for all PCIDs, including global translations;
   BREAK;
 3: // all PCID invalidation retaining global translations
   Invalidate all mappings for all PCIDs except global translations;
   BREAK;
ESAC;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
INVPCID: void _invpcid(unsigned __int32 type, void * descriptor);
```
### SIMD Floating-Point Exceptions


None


### Protected Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If the memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains an unusable segment.
* If the source operand is located in an execute-only code segment.
* If an invalid type is specified in the register operand, i.e., INVPCID_TYPE > 3.
* If bits 63:12 of INVPCID_DESC are not all zero.
* If INVPCID_TYPE is either 0 or 1 and INVPCID_DESC[11:0] is not zero.
* If INVPCID_TYPE is 0 and the linear address in INVPCID_DESC[127:64] is not canonical.

#### #PF(fault-code)
* If a page fault occurs in accessing the memory operand.

#### #SS(0)
* If the memory operand effective address is outside the SS segment limit.
* If the SS register contains an unusable segment.

#### #UD
* If if CPUID.(EAX=07H, ECX=0H):EBX.INVPCID (bit 10) = 0.
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If an invalid type is specified in the register operand, i.e., INVPCID_TYPE > 3.
* If bits 63:12 of INVPCID_DESC are not all zero.
* If INVPCID_TYPE is either 0 or 1 and INVPCID_DESC[11:0] is not zero.
* If INVPCID_TYPE is 0 and the linear address in INVPCID_DESC[127:64] is not canonical.

#### #UD
* If CPUID.(EAX=07H, ECX=0H):EBX.INVPCID (bit 10) = 0.
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* The INVPCID instruction is not recognized in virtual-8086 mode.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the current privilege level is not 0.
* If the memory operand is in the CS, DS, ES, FS, or GS segments and the memory address is in a non-canonical form.
* If an invalid type is specified in the register operand, i.e., INVPCID_TYPE > 3.
* If bits 63:12 of INVPCID_DESC are not all zero.
* If CR4.PCIDE=0, INVPCID_TYPE is either 0 or 1, and INVPCID_DESC[11:0] is not zero.
* If INVPCID_TYPE is 0 and the linear address in INVPCID_DESC[127:64] is not canonical.

#### #PF(fault-code)
* If a page fault occurs in accessing the memory operand.

#### #SS(0)
* If the memory destination operand is in the SS segment and the memory address is in a non-canonical form.

#### #UD
* If the LOCK prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.INVPCID (bit 10) = 0.
