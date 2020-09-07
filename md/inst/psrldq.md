----------------------------
title : PSRLDQ (Intel x86/64 assembly instruction)
cat_title : PSRLDQ
ref_title : PSRLDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------
#@ PSRLDQ

**Shift Double Quadword Right Logical**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 73 /3 ib\newline{}\newline{}PSRLDQ xmm1, imm8|MI|V/V|SSE2|Shift xmm1 right by imm8 while shifting in 0s.|
|VEX.NDD.128.66.0F.WIG 73 /3 ib\newline{}\newline{}VPSRLDQ xmm1, xmm2, imm8|VMI|V/V|AVX|Shift xmm2 right by imm8 bytes while shifting in 0s.|
|VEX.NDD.256.66.0F.WIG 73 /3 ib\newline{}\newline{}VPSRLDQ ymm1, ymm2, imm8|VMI|V/V|AVX2|Shift ymm1 right by imm8 bytes while shifting in 0s.|
|EVEX.NDD.128.66.0F.WIG 73 /3 ib\newline{}VPSRLDQ xmm1, xmm2/m128, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Shift xmm2/m128 right by imm8 bytes while shifting in 0s and store result in xmm1.|
|EVEX.NDD.256.66.0F.WIG 73 /3 ib\newline{}VPSRLDQ ymm1, ymm2/m256, imm8|FVM|V/V|AVX512VL\newline{}AVX512BW|Shift ymm2/m256 right by imm8 bytes while shifting in 0s and store result in ymm1.|
|EVEX.NDD.512.66.0F.WIG 73 /3 ib\newline{}VPSRLDQ zmm1, zmm2/m512, imm8|FVM|V/V|AVX512BW|Shift zmm2/m512 right by imm8 bytes while shifting in 0s and store result in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MI|ModRM:r/m (r, w)|imm8|NA|NA|
|VMI|VEX.vvvv (w)|ModRM:r/m (r)|imm8|NA|
|FVM|EVEX.vvvv (w)|ModRM:r/m (R)|Imm8|NA|
### Description


Shifts the destination operand (first operand) to the right by the number of bytes specified in the count operand (second operand). The empty high-order bytes are cleared (set to all 0s). If the value specified by the count operand is greater than 15, the destination operand is set to all 0s. The count operand is an 8-bit immediate.

In 64-bit mode and not encoded with VEX/EVEX, using a REX prefix in the form of REX.R permits this instruction to access additional registers (XMM8-XMM15).

128-bit Legacy SSE version: The source and destination operands are the same. Bits (VLMAX-1:128) of the corre-sponding YMM destination register remain unchanged.

VEX.128 encoded version: The source and destination operands are XMM registers. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: The source operand is a YMM register. The destination operand is a YMM register. The count operand applies to both the low and high 128-bit lanes.

VEX.256 encoded version: The source operand is YMM register. The destination operand is an YMM register. Bits (MAX\esc{_}VL-1:256) of the corresponding ZMM register are zeroed. The count operand applies to both the low and high 128-bit lanes.

EVEX encoded versions: The source operand is a ZMM/YMM/XMM register or a 512/256/128-bit memory location. The destination operand is a ZMM/YMM/XMM register. The count operand applies to each 128-bit lanes.

Note: VEX.vvvv/EVEX.vvvv encodes the destination register.


### Operation
#### VPSRLDQ (EVEX.512 encoded version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST[127:0] <-  SRC[127:0] >> (TEMP * 8)
DEST[255:128] <-  SRC[255:128] >> (TEMP * 8)
DEST[383:256] <-  SRC[383:256] >> (TEMP * 8)
DEST[511:384] <-  SRC[511:384] >> (TEMP * 8)
DEST[MAX_VL-1:512] <-  0;
```
#### VPSRLDQ (VEX.256 and EVEX.256 encoded version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST[127:0] <-  SRC[127:0] >> (TEMP * 8)
DEST[255:128] <-  SRC[255:128] >> (TEMP * 8)
DEST[MAX_VL-1:256] <-  0;
```
#### VPSRLDQ (VEX.128 and EVEX.128 encoded version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST <-  SRC >> (TEMP * 8)
DEST[MAX_VL-1:128] <-  0;
```
#### PSRLDQ(128-bit Legacy SSE version)
```info-verb
TEMP <-  COUNT
IF (TEMP > 15) THEN TEMP <-  16; FI
DEST <-  DEST >> (TEMP * 8)
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalents

```cpp
(V)PSRLDQ __m128i _mm_srli_si128 ( __m128i a, int imm)
VPSRLDQ __m256i _mm256_bsrli_epi128 ( __m256i, const int)
VPSRLDQ __m512i _mm512_bsrli_epi128 ( __m512i, int)
```
### Flags Affected


None.

### Numeric Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 7.

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

