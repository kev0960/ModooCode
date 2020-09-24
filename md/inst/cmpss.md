----------------------------
title : CMPSS (Intel x86/64 assembly instruction)
cat_title : CMPSS
ref_title : CMPSS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CMPSS

**Compare Scalar Single-Precision Floating-Point Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F C2 /r ib`\newline{}`CMPSS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE|Compare low single-precision floating-point value in xmm2/m32 and xmm1 using bits 2:0 of imm8 as comparison predicate.|
|`VEX.NDS.128.F3.0F.WIG C2 /r ib`\newline{}VCMPSS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RVMI|V/V|AVX|Compare low single-precision floating-point value in xmm3/m32 and xmm2 using bits 4:0 of imm8 as comparison predicate.|
|`EVEX.NDS.LIG.F3.0F.W0 C2 /r ib`\newline{}VCMPSS \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} {k2} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm3/m32{sae} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |T1S|V/V|AVX512F|Compare low single-precision floating-point value in xmm3/m32 and xmm2 using bits 4:0 of imm8 as comparison predicate with writemask k2 and leave the result in mask register k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv|ModRM:r/m (r)|Imm8|
|T1S|ModRM:reg (w)|EVEX.vvvv|ModRM:r/m (r)|Imm8|
### Description


Compares the low single-precision floating-point values in the second source operand and the first source operand and returns the results of the comparison to the destination operand. The comparison predicate operand (imme-diate operand) specifies the type of comparison performed. 

128-bit Legacy SSE version: The first source and destination operand (first operand) is an XMM register. The second source operand (second operand) can be an XMM register or 32-bit memory location. Bits (MAX\esc{_}VL-1:32) of the corresponding YMM destination register remain unchanged. The comparison result is a doubleword mask of all 1s (comparison true) or all 0s (comparison false). 

VEX.128 encoded version: The first source operand (second operand) is an XMM register. The second source operand (third operand) can be an XMM register or a 32-bit memory location. The result is stored in the low 32 bits of the destination operand; bits 128:32 of the destination operand are copied from the first source operand. Bits (MAX\esc{_}VL-1:128) of the destination ZMM register are zeroed. The comparison result is a doubleword mask of all 1s (comparison true) or all 0s (comparison false). 

EVEX encoded version: The first source operand (second operand) is an XMM register. The second source operand can be a XMM register or a 32-bit memory location. The destination operand (first operand) is an opmask register. The comparison result is a single mask bit of 1 (comparison true) or 0 (comparison false), written to the destination starting from the LSB according to the writemask k2. Bits (MAX\esc{_}KL-1:128) of the destination register are cleared. 

The comparison predicate operand is an 8-bit immediate: 

*  For instructions encoded using the VEX prefix, bits 4:0 define the type of comparison to be performed (see Table 3-1). Bits 5 through 7 of the immediate are reserved. 

*  For instruction encodings that do not use VEX prefix, bits 2:0 define the type of comparison to be made (see the first 8 rows of Table 3-1). Bits 3 through 7 of the immediate are reserved. 

The unordered relationship is true when at least one of the two source operands being compared is a NaN; the ordered relationship is true when neither source operand is a NaN. 

A subsequent computational instruction that uses the mask result in the destination operand as an input operand will not generate an exception, because a mask of all 0s corresponds to a floating-point value of +0.0 and a mask of all 1s corresponds to a QNaN. 

Note that processors with "CPUID.1H:ECX.AVX =0" do not implement the "greater-than", "greater-than-or-equal", "not-greater than", and "not-greater-than-or-equal relations" predicates. These comparisons can be made either 



by using the inverse relationship (that is, use the "not-less-than-or-equal" to make a "greater-than" comparison) or by using software emulation. When using software emulation, the program must swap the operands (copying registers when necessary to protect the data that will now be in the destination), and then perform the compare using a different predicate. The predicate to be used for these emulations is listed in the first 8 rows of Table 3-7 (Intel 64 and IA-32 Architectures Software Developer's Manual Volume 2A) under the heading Emulation. 

Compilers and assemblers may implement the following two-operand pseudo-ops in addition to the three-operand `CMPSS` instruction, for processors with "CPUID.1H:ECX.AVX =0". See Table 3-8. Compiler should treat reserved Imm8 values as illegal syntax.:

###                                                 Table 3-8. Pseudo-Op and CMPSS Implementation


The greater-than relations that the processor does not implement require more than one instruction to emulate in software and therefore should not be implemented as pseudo-ops. (For these, the programmer should reverse the operands of the corresponding less than relations and use move instructions to ensure that the mask is moved to the correct destination register and that the source operand is left intact.) 

Processors with "CPUID.1H:ECX.AVX =1" implement the full complement of 32 predicates shown in Table 3-7, soft-ware emulation is no longer needed. Compilers and assemblers may implement the following three-operand pseudo-ops in addition to the four-operand VCMPSS instruction. See Table 3-9, where the notations of reg1 reg2, and reg3 represent either XMM registers or YMM registers. Compiler should treat reserved Imm8 values as illegal syntax. Alternately, intrinsics can map the pseudo-ops to pre-defined constants to support a simpler intrinsic inter-face. Compilers and assemblers may implement three-operand pseudo-ops for EVEX encoded VCMPSS instructions in a similar fashion by extending the syntax listed in Table 3-9.:



|**Pseudo-Op**|**CMPSS Implementation**|
|-------------|------------------------|
|CMPEQSS xmm1, xmm2|CMPSS xmm1, xmm2, 0|
|CMPLTSS xmm1, xmm2|CMPSS xmm1, xmm2, 1|
|CMPLESS xmm1, xmm2|CMPSS xmm1, xmm2, 2|
|CMPUNORDSS xmm1, xmm2|CMPSS xmm1, xmm2, 3|
|CMPNEQSS xmm1, xmm2|CMPSS xmm1, xmm2, 4|
|CMPNLTSS xmm1, xmm2|CMPSS xmm1, xmm2, 5|
|CMPNLESS xmm1, xmm2|CMPSS xmm1, xmm2, 6|
|CMPORDSS xmm1, xmm2|CMPSS xmm1, xmm2, 7|
### Table 3-9. Pseudo-Op and VCMPSS Implementation


|**Pseudo-Op**|**CMPSS Implementation**|
|-------------|------------------------|
|VCMPEQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0|
|VCMPLTSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1|
|VCMPLESS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 2|
|VCMPUNORDSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 3|
|VCMPNEQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 4|
|VCMPNLTSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 5|
|VCMPNLESS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 6|
|VCMPORDSS reg1, reg2, reg3\newline{}VCMPEQ_UQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 7\newline{}VCMPSS reg1, reg2, reg3, 8|
|VCMPNGESS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 9|
|VCMPNGTSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0AH|
|VCMPFALSESS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0BH|
|VCMPNEQ_OQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0CH|
|VCMPGESS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0DH|
###                                                Table 3-9. Pseudo-Op and VCMPSS Implementation


Software should ensure VCMPSS is encoded with VEX.L=0. Encoding VCMPSS with VEX.L=1 may encounter unpre-dictable behavior across different processor generations.



|**Pseudo-Op**|**CMPSS Implementation**|
|-------------|------------------------|
|VCMPGTSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0EH|
|VCMPTRUESS reg1, reg2, reg3\newline{}VCMPEQ_OSSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 0FH\newline{}VCMPSS reg1, reg2, reg3, 10H|
|VCMPLT_OQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 11H|
|VCMPLE_OQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 12H|
|VCMPUNORD_SSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 13H|
|VCMPNEQ_USSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 14H|
|VCMPNLT_UQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 15H|
|VCMPNLE_UQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 16H|
|VCMPORD_SSS reg1, reg2, reg3\newline{}VCMPEQ_USSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 17H\newline{}VCMPSS reg1, reg2, reg3, 18H|
|VCMPNGE_UQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 19H|
|VCMPNGT_UQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1AH|
|VCMPFALSE_OSSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1BH|
|VCMPNEQ_OSSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1CH|
|VCMPGE_OQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1DH|
|VCMPGT_OQSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1EH|
|VCMPTRUE_USSS reg1, reg2, reg3|VCMPSS reg1, reg2, reg3, 1FH|

### Operation
#### VCMPSS (EVEX encoded version) 
```info-verb
CMP0 <-  SRC1[31:0] OP5 SRC2[31:0];
IF k2[0] or *no writemask*
    THEN IF CMP0 = TRUE
                      THEN DEST[0] <-  1;
                      ELSE DEST[0] <-  0; FI;
    ELSE  DEST[0] <-  0 ; zeroing-masking only
FI;
DEST[MAX_KL-1:1] <-  0
```
#### CMPSS (128-bit Legacy SSE version)
```info-verb
CMP0 <- DEST[31:0] OP3 SRC[31:0];
IF CMP0 = TRUE
THEN DEST[31:0] <- FFFFFFFFH;
ELSE DEST[31:0] <- 00000000H; FI;
DEST[MAX_VL-1:32] (Unmodified)
```
#### VCMPSS (VEX.128 encoded version)
```info-verb
CMP0 <- SRC1[31:0] OP5 SRC2[31:0];
IF CMP0 = TRUE
THEN DEST[31:0] <- FFFFFFFFH;
ELSE DEST[31:0] <- 00000000H; FI;
DEST[127:32] <- SRC1[127:32]
DEST[MAX_VL-1:128] <- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCMPSS __mmask8 _mm_cmp_ss_mask( __m128 a, __m128 b, int imm);
VCMPSS __mmask8 _mm_cmp_round_ss_mask( __m128 a, __m128 b, int imm, int sae);
VCMPSS __mmask8 _mm_mask_cmp_ss_mask( __mmask8 k1, __m128 a, __m128 b, int imm);
VCMPSS __mmask8 _mm_mask_cmp_round_ss_mask( __mmask8 k1, __m128 a, __m128 b, int imm, int sae);
(V)CMPSS __m128 _mm_cmp_ss(__m128 a, __m128 b, const int imm)
```
### SIMD Floating-Point Exceptions


Invalid if SNaN operand, Invalid if QNaN and predicate as listed in Table 3-1, Denormal.

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3.

EVEX-encoded instructions, see Exceptions Type E3.

