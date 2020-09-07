----------------------------
title : CMPPD (Intel x86/64 assembly instruction)
cat_title : CMPPD
ref_title : CMPPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------
#@ CMPPD

**Compare Packed Double-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F C2 /r ib\newline{}CMPPD xmm1, xmm2/m128, imm8|RMI|V/V|SSE2|Compare packed double-precision floating-point values in xmm2/m128 and xmm1 using bits 2:0 of imm8 as a comparison predicate.|
|VEX.NDS.128.66.0F.WIG C2 /r ib\newline{}VCMPPD xmm1, xmm2, xmm3/m128, imm8|RVMI|V/V|AVX|Compare packed double-precision floating-point values in xmm3/m128 and xmm2 using bits 4:0 of imm8 as a comparison predicate.|
|VEX.NDS.256.66.0F.WIG C2 /r ib\newline{}VCMPPD ymm1, ymm2, ymm3/m256, imm8|RVMI|V/V|AVX|Compare packed double-precision floating-point values in ymm3/m256 and ymm2 using bits 4:0 of imm8 as a comparison predicate.|
|EVEX.NDS.128.66.0F.W1 C2 /r ib\newline{}VCMPPD k1 {k2}, xmm2, xmm3/m128/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed double-precision floating-point values in xmm3/m128/m64bcst and xmm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.256.66.0F.W1 C2 /r ib\newline{}VCMPPD k1 {k2}, ymm2, ymm3/m256/m64bcst, imm8|FV|V/V|AVX512VL\newline{}AVX512F|Compare packed double-precision floating-point values in ymm3/m256/m64bcst and ymm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
|EVEX.NDS.512.66.0F.W1 C2 /r ib\newline{}VCMPPD k1 {k2}, zmm2, zmm3/m512/m64bcst{sae}, imm8|FV|V/V|AVX512F|Compare packed double-precision floating-point values in zmm3/m512/m64bcst and zmm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
|FV|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Performs a SIMD compare of the packed double-precision floating-point values in the second source operand and the first source operand and returns the results of the comparison to the destination operand. The comparison predicate operand (immediate byte) specifies the type of comparison performed on each pair of packed values in the two source operands. 

EVEX encoded versions: The first source operand (second operand) is a ZMM/YMM/XMM register. The second source operand can be a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 64-bit memory location. The destination operand (first operand) is an opmask register. Comparison results are written to the destination operand under the writemask k2. Each comparison result is a single mask bit of 1 (comparison true) or 0 (comparison false).

VEX.256 encoded version: The first source operand (second operand) is a YMM register. The second source operand (third operand) can be a YMM register or a 256-bit memory location. The destination operand (first operand) is a YMM register. Four comparisons are performed with results written to the destination operand. The result of each comparison is a quadword mask of all 1s (comparison true) or all 0s (comparison false).

128-bit Legacy SSE version: The first source and destination operand (first operand) is an XMM register. The second source operand (second operand) can be an XMM register or 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the corresponding ZMM destination register remain unchanged. Two comparisons are performed with results written to bits 127:0 of the destination operand. The result of each comparison is a quadword mask of all 1s (comparison true) or all 0s (comparison false).



VEX.128 encoded version: The first source operand (second operand) is an XMM register. The second source operand (third operand) can be an XMM register or a 128-bit memory location. Bits (MAX\esc{_}VL-1:128) of the desti-nation ZMM register are zeroed. Two comparisons are performed with results written to bits 127:0 of the destina-tion operand.

The comparison predicate operand is an 8-bit immediate:

*  For instructions encoded using the VEX or EVEX prefix, bits 4:0 define the type of comparison to be performed (see Table 3-1). Bits 5 through 7 of the immediate are reserved. 

*  For instruction encodings that do not use VEX prefix, bits 2:0 define the type of comparison to be made (see the first 8 rows of Table 3-1). Bits 3 through 7 of the immediate are reserved. 

### Table 3-1. Comparison Predicate for CMPPD and CMPPS Instructions 


|**Predicate**|**imm8 **|**Description**|**Result: A I**|**s 1st Ope**|**rand, B Is 2**|**nd Operand**|**Signals **|
|-------------|---------|---------------|---------------|-------------|----------------|--------------|------------|
||**Value**||**A >B**|**A < B**|**A = B**|**Unordered\footnote{1**}|**#IA on ****QNAN**|
|EQ_OQ (EQ)|0H|Equal (ordered, non-signaling)|False|False|True|False|No|
|LT_OS (LT)|1H|Less-than (ordered, signaling)|False|True|False|False|Yes|
|LE_OS (LE)|2H|Less-than-or-equal (ordered, signaling)|False|True|True|False|Yes|
|UNORD_Q (UNORD)|3H|Unordered (non-signaling)|False|False|False|True|No|
|NEQ_UQ (NEQ)|4H|Not-equal (unordered, non-signaling)|True|True|False|True|No|
|NLT_US (NLT)|5H|Not-less-than (unordered, signaling)|True|False|True|True|Yes|
|NLE_US (NLE)|6H|Not-less-than-or-equal (unordered, signaling)|True|False|False|True|Yes|
|ORD_Q (ORD)|7H|Ordered (non-signaling)|True|True|True|False|No|
|EQ_UQ|8H|Equal (unordered, non-signaling)|False|False|True|True|No|
|NGE_US (NGE)|9H|Not-greater-than-or-equal (unordered, signaling)|False|True|False|True|Yes|
|NGT_US (NGT)|AH|Not-greater-than (unordered, signaling)|False|True|True|True|Yes|
|FALSE_OQ(FALSE)|BH|False (ordered, non-signaling)|False|False|False|False|No|
|NEQ_OQ|CH|Not-equal (ordered, non-signaling)|True|True|False|False|No|
|GE_OS (GE)|DH|Greater-than-or-equal (ordered, signaling)|True|False|True|False|Yes|
|GT_OS (GT)|EH|Greater-than (ordered, signaling)|True|False|False|False|Yes|
|TRUE_UQ(TRUE)|FH|True (unordered, non-signaling)|True|True|True|True|No|
|EQ_OS|10H|Equal (ordered, signaling)|False|False|True|False|Yes|
|LT_OQ|11H|Less-than (ordered, nonsignaling)|False|True|False|False|No|
|LE_OQ|12H|Less-than-or-equal (ordered, nonsignaling)|False|True|True|False|No|
|UNORD_S|13H|Unordered (signaling)|False|False|False|True|Yes|
|NEQ_US|14H|Not-equal (unordered, signaling)|True|True|False|True|Yes|
|NLT_UQ|15H|Not-less-than (unordered, nonsignaling)|True|False|True|True|No|
|NLE_UQ|16H|Not-less-than-or-equal (unordered, nonsig-naling)|True|False|False|True|No|
|ORD_S|17H|Ordered (signaling)|True|True|True|False|Yes|
|EQ_US|18H|Equal (unordered, signaling)|False|False|True|True|Yes|
|NGE_UQ|19H|Not-greater-than-or-equal (unordered, non-signaling)|False|True|False|True|No|
### Table 3-1. Comparison Predicate for CMPPD and CMPPS Instructions  (Contd.)


|**Predicate**|**imm8 **|**Description**|**Result: A I**|**s 1st Ope**|**rand, B Is 2**|**nd Operand**|**Signals **|
|-------------|---------|---------------|---------------|-------------|----------------|--------------|------------|
||**Value**||**A >B**|**A < B**|**A = B**|**Unordered\footnote{1**}|**#IA on ****QNAN**|
|NGT_UQ|1AH|Not-greater-than (unordered, nonsignaling)|False|True|True|True|No|
|FALSE_OS|1BH|False (ordered, signaling)|False|False|False|False|Yes|
|NEQ_OS|1CH|Not-equal (ordered, signaling)|True|True|False|False|Yes|
|GE_OQ|1DH|Greater-than-or-equal (ordered, nonsignal-ing)|True|False|True|False|No|
|GT_OQ|1EH|Greater-than (ordered, nonsignaling)|True|False|False|False|No|
|TRUE_US|1FH|True (unordered, signaling)|True|True|True|True|Yes|
|||||||||

```note
1. If either operand A or B is a NAN.

The unordered relationship is true when at least one of the two source operands being compared is a NaN; the ordered relationship is true when neither source operand is a NaN. 

A subsequent computational instruction that uses the mask result in the destination operand as an input operand will not generate an exception, because a mask of all 0s corresponds to a floating-point value of +0.0 and a mask of all 1s corresponds to a QNaN. 

Note that processors with "CPUID.1H:ECX.AVX =0" do not implement the "greater-than", "greater-than-or-equal", "not-greater than", and "not-greater-than-or-equal relations" predicates. These comparisons can be made either by using the inverse relationship (that is, use the "not-less-than-or-equal" to make a "greater-than" comparison) or by using software emulation. When using software emulation, the program must swap the operands (copying registers when necessary to protect the data that will now be in the destination), and then perform the compare using a different predicate. The predicate to be used for these emulations is listed in the first 8 rows of Table 3-7 (Intel 64 and IA-32 Architectures Software Developer's Manual Volume 2A) under the heading Emulation. 

Compilers and assemblers may implement the following two-operand pseudo-ops in addition to the three-operand CMPPD instruction, for processors with "CPUID.1H:ECX.AVX =0". See Table 3-2. Compiler should treat reserved Imm8 values as illegal syntax.
```
###                                                 Table 3-2. Pseudo-Op and CMPPD Implementation


The greater-than relations that the processor does not implement require more than one instruction to emulate in software and therefore should not be implemented as pseudo-ops. (For these, the programmer should reverse the operands of the corresponding less than relations and use move instructions to ensure that the mask is moved to the correct destination register and that the source operand is left intact.)

Processors with "CPUID.1H:ECX.AVX =1" implement the full complement of 32 predicates shown in Table 3-3, soft-ware emulation is no longer needed. Compilers and assemblers may implement the following three-operand pseudo-ops in addition to the four-operand VCMPPD instruction. See Table 3-3, where the notations of reg1 reg2, and reg3 represent either XMM registers or YMM registers. Compiler should treat reserved Imm8 values as illegal 



|**Pseudo-Op**|**CMPPD Implementation**|
|-------------|------------------------|
|CMPEQPD xmm1, xmm2|CMPPD xmm1, xmm2, 0|
|CMPLTPD xmm1, xmm2|CMPPD xmm1, xmm2, 1|
|CMPLEPD xmm1, xmm2|CMPPD xmm1, xmm2, 2|
|CMPUNORDPD xmm1, xmm2|CMPPD xmm1, xmm2, 3|
|CMPNEQPD xmm1, xmm2|CMPPD xmm1, xmm2, 4|
|CMPNLTPD xmm1, xmm2|CMPPD xmm1, xmm2, 5|
|CMPNLEPD xmm1, xmm2|CMPPD xmm1, xmm2, 6|
|CMPORDPD xmm1, xmm2|CMPPD xmm1, xmm2, 7|


syntax. Alternately, intrinsics can map the pseudo-ops to pre-defined constants to support a simpler intrinsic inter-face. Compilers and assemblers may implement three-operand pseudo-ops for EVEX encoded VCMPPD instructions in a similar fashion by extending the syntax listed in Table 3-3.:

### Table 3-3. Pseudo-Op and VCMPPD Implementation


|**Pseudo-Op**|**CMPPD Implementation**|
|-------------|------------------------|
|VCMPEQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0|
|VCMPLTPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1|
|VCMPLEPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 2|
|VCMPUNORDPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 3|
|VCMPNEQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 4|
|VCMPNLTPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 5|
|VCMPNLEPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 6|
|VCMPORDPD reg1, reg2, reg3\newline{}VCMPEQ_UQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 7\newline{}VCMPPD reg1, reg2, reg3, 8|
|VCMPNGEPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 9|
|VCMPNGTPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0AH|
|VCMPFALSEPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0BH|
|VCMPNEQ_OQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0CH|
|VCMPGEPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0DH|
|VCMPGTPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0EH|
|VCMPTRUEPD reg1, reg2, reg3\newline{}VCMPEQ_OSPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 0FH\newline{}VCMPPD reg1, reg2, reg3, 10H|
|VCMPLT_OQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 11H|
|VCMPLE_OQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 12H|
|VCMPUNORD_SPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 13H|
|VCMPNEQ_USPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 14H|
|VCMPNLT_UQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 15H|
|VCMPNLE_UQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 16H|
|VCMPORD_SPD reg1, reg2, reg3\newline{}VCMPEQ_USPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 17H\newline{}VCMPPD reg1, reg2, reg3, 18H|
|VCMPNGE_UQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 19H|
|VCMPNGT_UQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1AH|
|VCMPFALSE_OSPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1BH|
|VCMPNEQ_OSPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1CH|
|VCMPGE_OQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1DH|
|VCMPGT_OQPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1EH|
|VCMPTRUE_USPD reg1, reg2, reg3|VCMPPD reg1, reg2, reg3, 1FH|

### Operation
#### VCMPPD (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k2[j] OR *no writemask*
          THEN 
                IF (EVEX.b = 1) AND (SRC2 *is memory*)
                      THEN
                            CMP <-  SRC1[i+63:i] OP5 SRC2[63:0]
                      ELSE 
                            CMP <-  SRC1[i+63:i] OP5 SRC2[i+63:i]
                FI;
                IF CMP = TRUE
                      THEN DEST[j] <-  1;
                      ELSE DEST[j] <-  0; FI;
          ELSE  DEST[j] <-  0  ; zeroing-masking only
    FI;
ENDFOR
DEST[MAX_KL-1:KL] <-  0
```
#### VCMPPD (VEX.256 encoded version)
```info-verb
CMP0 <-  SRC1[63:0] OP5 SRC2[63:0];
CMP1 <-  SRC1[127:64] OP5 SRC2[127:64];
CMP2 <-  SRC1[191:128] OP5 SRC2[191:128];
CMP3 <-  SRC1[255:192] OP5 SRC2[255:192];
IF CMP0 = TRUE
    THEN DEST[63:0] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[63:0] <-  0000000000000000H; FI;
IF CMP1 = TRUE
    THEN DEST[127:64] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[127:64] <-  0000000000000000H; FI;
IF CMP2 = TRUE
    THEN DEST[191:128] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[191:128] <-  0000000000000000H; FI;
IF CMP3 = TRUE
    THEN DEST[255:192] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[255:192] <-  0000000000000000H; FI;
DEST[MAX_VL-1:256] <-  0
```
#### VCMPPD (VEX.128 encoded version)
```info-verb
CMP0 <-  SRC1[63:0] OP5 SRC2[63:0];
CMP1 <-  SRC1[127:64] OP5 SRC2[127:64];
IF CMP0 = TRUE
    THEN DEST[63:0] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[63:0] <-  0000000000000000H; FI;
IF CMP1 = TRUE
    THEN DEST[127:64] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[127:64] <-  0000000000000000H; FI;
DEST[MAX_VL-1:128] <-  0
```
#### CMPPD (128-bit Legacy SSE version)
```info-verb
CMP0 <-  SRC1[63:0] OP3 SRC2[63:0];
CMP1 <-  SRC1[127:64] OP3 SRC2[127:64];
IF CMP0 = TRUE
    THEN DEST[63:0] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[63:0] <-  0000000000000000H; FI;
IF CMP1 = TRUE
    THEN DEST[127:64] <-  FFFFFFFFFFFFFFFFH;
    ELSE DEST[127:64] <-  0000000000000000H; FI;
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCMPPD __mmask8 _mm512_cmp_pd_mask( __m512d a, __m512d b, int imm);
VCMPPD __mmask8 _mm512_cmp_round_pd_mask( __m512d a, __m512d b, int imm, int sae);
VCMPPD __mmask8 _mm512_mask_cmp_pd_mask( __mmask8 k1, __m512d a, __m512d b, int imm);
VCMPPD __mmask8 _mm512_mask_cmp_round_pd_mask( __mmask8 k1, __m512d a, __m512d b, int imm, int sae);
VCMPPD __mmask8 _mm256_cmp_pd_mask( __m256d a, __m256d b, int imm);
VCMPPD __mmask8 _mm256_mask_cmp_pd_mask( __mmask8 k1, __m256d a, __m256d b, int imm);
VCMPPD __mmask8 _mm_cmp_pd_mask( __m128d a, __m128d b, int imm);
VCMPPD __mmask8 _mm_mask_cmp_pd_mask( __mmask8 k1, __m128d a, __m128d b, int imm);
VCMPPD __m256 _mm256_cmp_pd(__m256d a, __m256d b, int imm)
(V)CMPPD __m128 _mm_cmp_pd(__m128d a, __m128d b, int imm)
```
### SIMD Floating-Point Exceptions


Invalid if SNaN operand and invalid if QNaN and predicate as listed in Table 3-1.

Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 2.

EVEX-encoded instructions, see Exceptions Type E2.

