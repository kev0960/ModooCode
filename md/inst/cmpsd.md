----------------------------
title : CMPSD (Intel x86/64 assembly instruction)
cat_title : CMPSD
ref_title : CMPSD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------
#@ CMPSD

**Compare Scalar Double-Precision Floating-Point Value**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|F2 0F C2 /r ib\newline{}CMPSD xmm1, xmm2/m64, imm8|RMI|V/V|SSE2|Compare low double-precision floating-point value in xmm2/m64 and xmm1 using bits 2:0 of imm8 as comparison predicate.|
|VEX.NDS.128.F2.0F.WIG C2 /r ib\newline{}VCMPSD xmm1, xmm2, xmm3/m64, imm8|RVMI|V/V|AVX|Compare low double-precision floating-point value in xmm3/m64 and xmm2 using bits 4:0 of imm8 as comparison predicate.|
|EVEX.NDS.LIG.F2.0F.W1 C2 /r ib\newline{}VCMPSD k1 {k2}, xmm2, xmm3/m64{sae}, imm8|T1S|V/V|AVX512F|Compare low double-precision floating-point value in xmm3/m64 and xmm2 using bits 4:0 of imm8 as comparison predicate with writemask k2 and leave the result in mask register k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Compares the low double-precision floating-point values in the second source operand and the first source operand and returns the results in of the comparison to the destination operand. The comparison predicate operand (imme-diate operand) specifies the type of comparison performed. 

128-bit Legacy SSE version: The first source and destination operand (first operand) is an XMM register. The second source operand (second operand) can be an XMM register or 64-bit memory location. Bits (MAX\esc{_}VL-1:64) of the corresponding YMM destination register remain unchanged. The comparison result is a quadword mask of all 1s (comparison true) or all 0s (comparison false). 

VEX.128 encoded version: The first source operand (second operand) is an XMM register. The second source operand (third operand) can be an XMM register or a 64-bit memory location. The result is stored in the low quad-word of the destination operand; the high quadword is filled with the contents of the high quadword of the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination ZMM register are zeroed. The comparison result is a quad-word mask of all 1s (comparison true) or all 0s (comparison false). 

EVEX encoded version: The first source operand (second operand) is an XMM register. The second source operand can be a XMM register or a 64-bit memory location. The destination operand (first operand) is an opmask register. The comparison result is a single mask bit of 1 (comparison true) or 0 (comparison false), written to the destination starting from the LSB according to the writemask k2. Bits (MAX\esc{_}KL-1:128) of the destination register are cleared.

The comparison predicate operand is an 8-bit immediate: 

*  For instructions encoded using the VEX prefix, bits 4:0 define the type of comparison to be performed (see Table 3-1). Bits 5 through 7 of the immediate are reserved. 

*  For instruction encodings that do not use VEX prefix, bits 2:0 define the type of comparison to be made (see the first 8 rows of Table 3-1). Bits 3 through 7 of the immediate are reserved. 

The unordered relationship is true when at least one of the two source operands being compared is a NaN; the ordered relationship is true when neither source operand is a NaN. 

A subsequent computational instruction that uses the mask result in the destination operand as an input operand will not generate an exception, because a mask of all 0s corresponds to a floating-point value of +0.0 and a mask of all 1s corresponds to a QNaN. 

Note that processors with "CPUID.1H:ECX.AVX =0" do not implement the "greater-than", "greater-than-or-equal", "not-greater than", and "not-greater-than-or-equal relations" predicates. These comparisons can be made either by using the inverse relationship (that is, use the "not-less-than-or-equal" to make a "greater-than" comparison) 



or by using software emulation. When using software emulation, the program must swap the operands (copying registers when necessary to protect the data that will now be in the destination), and then perform the compare using a different predicate. The predicate to be used for these emulations is listed in the first 8 rows of Table 3-7 (Intel 64 and IA-32 Architectures Software Developer's Manual Volume 2A) under the heading Emulation. 

Compilers and assemblers may implement the following two-operand pseudo-ops in addition to the three-operand `CMPSD` instruction, for processors with "CPUID.1H:ECX.AVX =0". See Table 3-6. Compiler should treat reserved Imm8 values as illegal syntax.:

###                                                 Table 3-6. Pseudo-Op and CMPSD Implementation


The greater-than relations that the processor does not implement require more than one instruction to emulate in software and therefore should not be implemented as pseudo-ops. (For these, the programmer should reverse the operands of the corresponding less than relations and use move instructions to ensure that the mask is moved to the correct destination register and that the source operand is left intact.) 

Processors with "CPUID.1H:ECX.AVX =1" implement the full complement of 32 predicates shown in Table 3-7, soft-ware emulation is no longer needed. Compilers and assemblers may implement the following three-operand pseudo-ops in addition to the four-operand VCMPSD instruction. See Table 3-7, where the notations of reg1 reg2, and reg3 represent either XMM registers or YMM registers. Compiler should treat reserved Imm8 values as illegal syntax. Alternately, intrinsics can map the pseudo-ops to pre-defined constants to support a simpler intrinsic inter-face. Compilers and assemblers may implement three-operand pseudo-ops for EVEX encoded VCMPSD instructions in a similar fashion by extending the syntax listed in Table 3-7.:



|**Pseudo-Op**|**CMPSD Implementation**|
|-------------|------------------------|
|CMPEQSD xmm1, xmm2|CMPSD xmm1, xmm2, 0|
|CMPLTSD xmm1, xmm2|CMPSD xmm1, xmm2, 1|
|CMPLESD xmm1, xmm2|CMPSD xmm1, xmm2, 2|
|CMPUNORDSD xmm1, xmm2|CMPSD xmm1, xmm2, 3|
|CMPNEQSD xmm1, xmm2|CMPSD xmm1, xmm2, 4|
|CMPNLTSD xmm1, xmm2|CMPSD xmm1, xmm2, 5|
|CMPNLESD xmm1, xmm2|CMPSD xmm1, xmm2, 6|
|CMPORDSD xmm1, xmm2|CMPSD xmm1, xmm2, 7|
### Table 3-7. Pseudo-Op and VCMPSD Implementation


|**Pseudo-Op**|**CMPSD Implementation**|
|-------------|------------------------|
|VCMPEQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0|
|VCMPLTSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1|
|VCMPLESD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 2|
|VCMPUNORDSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 3|
|VCMPNEQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 4|
|VCMPNLTSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 5|
|VCMPNLESD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 6|
|VCMPORDSD reg1, reg2, reg3\newline{}VCMPEQ_UQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 7\newline{}VCMPSD reg1, reg2, reg3, 8|
|VCMPNGESD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 9|
|VCMPNGTSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0AH|
|VCMPFALSESD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0BH|
|VCMPNEQ_OQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0CH|
|VCMPGESD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0DH|
###                                                Table 3-7. Pseudo-Op and VCMPSD Implementation


Software should ensure VCMPSD is encoded with VEX.L=0. Encoding VCMPSD with VEX.L=1 may encounter unpre-dictable behavior across different processor generations.



|**Pseudo-Op**|**CMPSD Implementation**|
|-------------|------------------------|
|VCMPGTSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0EH|
|VCMPTRUESD reg1, reg2, reg3\newline{}VCMPEQ_OSSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 0FH\newline{}VCMPSD reg1, reg2, reg3, 10H|
|VCMPLT_OQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 11H|
|VCMPLE_OQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 12H|
|VCMPUNORD_SSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 13H|
|VCMPNEQ_USSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 14H|
|VCMPNLT_UQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 15H|
|VCMPNLE_UQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 16H|
|VCMPORD_SSD reg1, reg2, reg3\newline{}VCMPEQ_USSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 17H\newline{}VCMPSD reg1, reg2, reg3, 18H|
|VCMPNGE_UQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 19H|
|VCMPNGT_UQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1AH|
|VCMPFALSE_OSSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1BH|
|VCMPNEQ_OSSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1CH|
|VCMPGE_OQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1DH|
|VCMPGT_OQSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1EH|
|VCMPTRUE_USSD reg1, reg2, reg3|VCMPSD reg1, reg2, reg3, 1FH|

### Operation
#### VCMPSD (EVEX encoded version) 
```info-verb
CMP0 <-  SRC1[63:0] OP5 SRC2[63:0];
IF k2[0] or *no writemask*
    THEN IF CMP0 = TRUE
                      THEN DEST[0] <-  1;
                      ELSE DEST[0] <-  0; FI;
    ELSE  DEST[0] <-  0 ; zeroing-masking only
FI;
DEST[MAX_KL-1:1] <-  0
```
#### CMPSD (128-bit Legacy SSE version)
```info-verb
CMP0 <- DEST[63:0] OP3 SRC[63:0];
IF CMP0 = TRUE
THEN DEST[63:0] <- FFFFFFFFFFFFFFFFH;
ELSE DEST[63:0] <- 0000000000000000H; FI;
DEST[MAX_VL-1:64] (Unmodified)
```
#### VCMPSD (VEX.128 encoded version)
```info-verb
CMP0 <- SRC1[63:0] OP5 SRC2[63:0];
IF CMP0 = TRUE
THEN DEST[63:0] <- FFFFFFFFFFFFFFFFH;
ELSE DEST[63:0] <- 0000000000000000H; FI;
DEST[127:64] <- SRC1[127:64]
DEST[MAX_VL-1:128] <- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCMPSD __mmask8 _mm_cmp_sd_mask( __m128d a, __m128d b, int imm);
VCMPSD __mmask8 _mm_cmp_round_sd_mask( __m128d a, __m128d b, int imm, int sae);
VCMPSD __mmask8 _mm_mask_cmp_sd_mask( __mmask8 k1, __m128d a, __m128d b, int imm);
VCMPSD __mmask8 _mm_mask_cmp_round_sd_mask( __mmask8 k1, __m128d a, __m128d b, int imm, int sae);
(V)CMPSD __m128d _mm_cmp_sd(__m128d a, __m128d b, const int imm)
```
### SIMD Floating-Point Exceptions


Invalid if SNaN operand, Invalid if QNaN and predicate as listed in Table 3-1 Denormal.

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.

