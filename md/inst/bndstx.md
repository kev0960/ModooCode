----------------------------
title : BNDSTX (Intel x86/64 assembly instruction)
cat_title : BNDSTX
ref_title : BNDSTX
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BNDSTX

**Store Extended Bounds Using Address Translation**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 1B /r`\newline{}`BNDSTX` \tooltip{mib}{SIB 주소 표현 형태를 사용하는 메모리 데이터로, 인덱스 레지스터가 주소값 계산에 사용되지 않으며 scale 역시 무시된다. 오직 베이스 와 변위 값만 유효 주소값을 계산하는데 사용된다. } \tooltip{bnd}{128 비트 바운드 레지스터. BND0 부터 BND3 까지 가능하다. } |MR|V/V|MPX|Store the bounds in bnd and the pointer value in the index regis-ter of mib to a bound table entry (BTE) with address translation using the base of mib.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|MR|SIB.base (r): Address of pointerSIB.index(r)|ModRM:reg (r)|NA|
### Description


BNDSTX uses the linear address constructed from the displacement and base register of the SIB-addressing form of the memory operand (mib) to perform address translation to store to a bound table entry. The bounds in the source operand bnd are written to the lower and upper bounds in the BTE. The content of the index register of mib is written to the pointer value field in the BTE. 

This instruction does not cause memory access to the linear address of mib nor the effective address referenced by the base, and does not read or write any flags. 

Segment overrides apply to the linear address computation with the base of mib, and are used during address translation to generate the address of the bound table entry. By default, the address of the BTE is assumed to be linear address. There are no segmentation checks performed on the base of mib. 

The base of mib will not be checked for canonical address violation as it does not access memory. 

Any encoding of this instruction that does not specify base or index register will treat those registers as zero (constant). The reg-reg form of this instruction will remain a `NOP`.

The scale field of the SIB byte has no effect on these instructions and is ignored.

The bound register may be partially updated on memory faults. The order in which memory operands are loaded is implementation specific.


### Operation
#### Outside 64-bit mode
```info-verb
A_BDE[31:0] <-  (Zero_extend32(base[31:12] << 2) + (BNDCFG[31:12] <<12 );
A_BT[31:0] <-  LoadFrom(A_BDE);
IF A_BT[0] equal 0 Then
    BNDSTATUS <-  A_BDE | 02H; 
    #BR; 
FI;
A_DEST[31:0] <-  (Zero_extend32(base[11:2] << 4) + (A_BT[31:2] << 2 ); // address of Bound table entry
A_DEST[8][31:0] <-  ptr_value; 
A_DEST[0][31:0] <-  BND.LB; 
A_DEST[4][31:0] <-  BND.UB; 
```
#### In 64-bit mode
```info-verb
A_BDE[63:0] <-  (Zero_extend64(base[47+MAWA:20] << 3) + (BNDCFG[63:20] <<12 );\footnote{1}
A_BT[63:0] <-  LoadFrom(A_BDE);
IF A_BT[0] equal 0 Then
    BNDSTATUS <-  A_BDE | 02H; 
    #BR; 
FI;
A_DEST[63:0] <-  (Zero_extend64(base[19:3] << 5) + (A_BT[63:3] << 3 ); // address of Bound table entry
A_DEST[16][63:0] <-  ptr_value; 
A_DEST[0][63:0] <-  BND.LB; 
A_DEST[8][63:0] <-  BND.UB; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BNDSTX: _bnd_store_ptr_bounds(const void **ptr_addr, const void *ptr_val); 
```
### Flags Affected


None


### Protected Mode Exceptions

#### #BR
* If the bound directory entry is invalid.

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 67H prefix is not used and CS.D=0.
* If 67H prefix is used and CS.D=1.

#### #GP(0)
* If a destination effective address of the Bound Table entry is outside the DS segment limit.
* If DS register contains a NULL segment selector.
* If the destination operand points to a non-writable segment

#### #PF(fault
* code) If a page fault occurs.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

#### #GP(0)
* If a destination effective address of the Bound Table entry is outside the DS segment limit.

### Virtual-8086 Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

#### #GP(0)
* If a destination effective address of the Bound Table entry is outside the DS segment limit.

#### #PF(fault
* code) If a page fault occurs.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.

```sidenote


1. If CPL< 3, the supervisor MAWA (MAWAS) is used; this value is 0. If CPL= 3, the user MAWA (MAWAU) is used; this value is enumer-ated in CPUID.(EAX=07H,ECX=0H):ECX.MAWAU[bits 21:17]. See Section 17.3.1 of Intel(R) 64 and IA-32 Architectures Software Devel-oper's Manual, Volume 1.
```
### 64-Bit Mode Exceptions

#### #BR
* If the bound directory entry is invalid.

#### #UD
* If ModRM is RIP relative.
* If the LOCK prefix is used.
* If ModRM.r/m and REX encodes BND4-BND15 when Intel MPX is enabled.

#### #GP(0)
* If the memory address (A_BDE or A_BTE) is in a non-canonical form.
* If the destination operand points to a non-writable segment

#### #PF(fault
* code) If a page fault occurs.
