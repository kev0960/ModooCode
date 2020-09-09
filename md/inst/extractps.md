----------------------------
title : EXTRACTPS (Intel x86/64 assembly instruction)
cat_title : EXTRACTPS
ref_title : EXTRACTPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/E
publish_date: 2020-09-01
----------------------------


#@ EXTRACTPS

**Extract Packed Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 3A 17 /r ib\newline{}EXTRACTPS reg/m32, xmm1, imm8|RMI|VV|SSE4_1|Extract one single-precision floating-point value from xmm1 at the offset specified by imm8 and store the result in reg or m32. Zero extend the results in 64-bit register if applicable.|
|VEX.128.66.0F3A.WIG 17 /r ib\newline{}VEXTRACTPS reg/m32, xmm1, imm8|RMI|V/V|AVX|Extract one single-precision floating-point value from xmm1 at the offset specified by imm8 and store the result in reg or m32. Zero extend the results in 64-bit register if applicable.|
|EVEX.128.66.0F3A.WIG 17 /r ib\newline{}VEXTRACTPS reg/m32, xmm1, imm8|T1S|V/V|AVX512F|Extract one single-precision floating-point value from xmm1 at the offset specified by imm8 and store the result in reg or m32. Zero extend the results in 64-bit register if applicable.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:r/m (w)|ModRM:reg (r)|Imm8|NA|
|T1S|ModRM:r/m (w)|ModRM:reg (r)|Imm8|NA|
### Description


Extracts a single-precision floating-point value from the source operand (second operand) at the 32-bit offset spec-ified from imm8. Immediate bits higher than the most significant offset for the vector length are ignored.

The extracted single-precision floating-point value is stored in the low 32-bits of the destination operand

In 64-bit mode, destination register operand has default operand size of 64 bits. The upper 32-bits of the register are filled with zero. REX.W is ignored.

VEX.128 and EVEX encoded version: When VEX.W1 or EVEX.W1 form is used in 64-bit mode with a general purpose register (GPR) as a destination operand, the packed single quantity is zero extended to 64 bits. 

VEX.vvvv/EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

128-bit Legacy SSE version: When a REX.W prefix is used in 64-bit mode with a general purpose register (GPR) as a destination operand, the packed single quantity is zero extended to 64 bits.

The source register is an XMM register. Imm8[1:0] determine the starting DWORD offset from which to extract the 32-bit floating-point value.

If VEXTRACTPS is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.


### Operation
#### VEXTRACTPS (EVEX and VEX.128 encoded version)
```info-verb
SRC_OFFSET <-  IMM8[1:0]
IF (64-Bit Mode and DEST is register)
    DEST[31:0] <-  (SRC[127:0] >> (SRC_OFFSET*32)) AND 0FFFFFFFFh
    DEST[63:32] <-  0
ELSE
    DEST[31:0] <-  (SRC[127:0] >> (SRC_OFFSET*32)) AND 0FFFFFFFFh
FI
```
#### EXTRACTPS (128-bit Legacy SSE version)
```info-verb
SRC_OFFSET <- IMM8[1:0]
IF (64-Bit Mode and DEST is register)
    DEST[31:0] <- (SRC[127:0] >> (SRC_OFFSET*32)) AND 0FFFFFFFFh
    DEST[63:32] <- 0
ELSE
    DEST[31:0] <- (SRC[127:0] >> (SRC_OFFSET*32)) AND 0FFFFFFFFh
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
EXTRACTPS int _mm_extract_ps (__m128 a, const int nidx);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 5; Additionally

EVEX-encoded instructions, see Exceptions Type E9NF.

#UD  IF VEX.L = 0.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.
