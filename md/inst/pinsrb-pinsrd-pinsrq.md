----------------------------
title : PINSRB, PINSRD, PINSRQs (Intel x86/64 assembly instruction)
cat_title : PINSRB, PINSRD, PINSRQ
ref_title : PINSRB, PINSRD, PINSRQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PINSRB, PINSRD, PINSRQ

** Insert Byte/Dword/Qword**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|----------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 3A 20 /r ib\newline{}PINSRB xmm1, r32/m8, imm8|RMI|V/V|SSE4_1|Insert a byte integer value from r32/m8 into xmm1 at the destination element in xmm1 specified by imm8.|
|66 0F 3A 22 /r ib\newline{}PINSRD xmm1, r/m32, imm8|RMI|V/V|SSE4_1|Insert a dword integer value from r/m32 into the xmm1 at the destination element specified by imm8.|
|66 REX.W 0F 3A 22 /r ib\newline{}PINSRQ xmm1, r/m64, imm8|RMI|V/N. E.|SSE4_1|Insert a qword integer value from r/m64 into the xmm1 at the destination element specified by imm8.|
|VEX.NDS.128.66.0F3A.W0 20 /r ib\newline{}VPINSRB xmm1, xmm2, r32/m8, imm8|RVMI|V\footnote{1} /V|AVX|Merge a byte integer value from r32/m8 and rest from xmm2 into xmm1 at the byte offset in imm8.|
|VEX.NDS.128.66.0F3A.W0 22 /r ib\newline{}VPINSRD xmm1, xmm2, r/m32, imm8|RVMI|V/V|AVX|Insert a dword integer value from r32/m32 and rest from xmm2 into xmm1 at the dword offset in imm8.|
|VEX.NDS.128.66.0F3A.W1 22 /r ib\newline{}VPINSRQ xmm1, xmm2, r/m64, imm8|RVMI|V/I|AVX|Insert a qword integer value from r64/m64 and rest from xmm2 into xmm1 at the qword offset in imm8.|
|EVEX.NDS.128.66.0F3A.WIG 20 /r ib\newline{}VPINSRB xmm1, xmm2, r32/m8, imm8|T1S-RVMI|V/V|AVX512BW|Merge a byte integer value from r32/m8 and rest from xmm2 into xmm1 at the byte offset in imm8.|
|EVEX.NDS.128.66.0F3A.W0 22 /r ib\newline{}VPINSRD xmm1, xmm2, r32/m32, imm8|T1S-RVMI|V/V|AVX512DQ|Insert a dword integer value from r32/m32 and rest from xmm2 into xmm1 at the dword offset in imm8.|
|EVEX.NDS.128.66.0F3A.W1 22 /r ib\newline{}VPINSRQ xmm1, xmm2, r64/m64, imm8|T1S-RVMI|V/N.E.\footnote{1}|AVX512DQ|Insert a qword integer value from r64/m64 and rest from xmm2 into xmm1 at the qword offset in imm8.|

```note
1. In 64-bit mode, VEX.W1 is ignored for VPINSRB (similar to legacy REX.W=1 prefix with PINSRB)
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
|T1S-RVMI|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|Imm8|
### Description


Copies a byte/dword/qword from the source operand (second operand) and inserts it in the destination operand (first operand) at the location specified with the count operand (third operand). (The other elements in the desti-nation register are left untouched.) The source operand can be a general-purpose register or a memory location. (When the source operand is a general-purpose register, `PINSRB` copies the low byte of the register.) The destina-tion operand is an XMM register. The count operand is an 8-bit immediate. When specifying a qword[dword, byte] location in an XMM register, the [2, 4] least-significant bit(s) of the count operand specify the location.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15, R8-15). Use of REX.W permits the use of 64 bit general purpose regis-ters.



128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination register are zeroed. VEX.L must be 0, otherwise the instruction will #UD. Attempt to execute VPINSRQ in non-64-bit mode will cause #UD.

EVEX.128 encoded version: Bits (VLMAX-1:128) of the destination register are zeroed. EVEX.L'L must be 0, other-wise the instruction will #UD. 


### Operation
#### VPINSRB (VEX/EVEX encoded version)
```info-verb
SEL <-  imm8[3:0]
DEST[127:0] <-  write_b_element(SEL, SRC2, SRC1)
DEST[VLMAX-1:128] <-  0
```
#### VPINSRD (VEX/EVEX encoded version)
```info-verb
SEL <-  imm8[1:0]
DEST[127:0] <-  write_d_element(SEL, SRC2, SRC1)
DEST[VLMAX-1:128] <-  0
```
#### VPINSRQ (VEX/EVEX encoded version)
```info-verb
SEL <-  imm8[0]
DEST[127:0] <-  write_q_element(SEL, SRC2, SRC1)
DEST[VLMAX-1:128] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PINSRB:  __m128i _mm_insert_epi8 (__m128i s1, int s2, const int ndx);
PINSRD:  __m128i _mm_insert_epi32 (__m128i s2, int s, const int ndx);
PINSRQ:  __m128i _mm_insert_epi64(__m128i s2, __int64 s, const int ndx);
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type 5; 

EVEX-encoded instruction, see Exceptions Type E9NF.



#UD  If VEX.L = 1 or EVEX.L'L > 0.

                              If VPINSRQ in non-64-bit mode with VEX.W=1.

