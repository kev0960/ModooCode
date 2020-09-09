----------------------------
title : BEXTR (Intel x86/64 assembly instruction)
cat_title : BEXTR
ref_title : BEXTR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BEXTR

** Bit Field Extract**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.LZ.0F38.W0 F7 /rBEXTR r32a, r/m32, r32b|RMV|V/V|BMI1|Contiguous bitwise extract from r/m32 using r32b as control; store result in r32a.|
|VEX.NDS.LZ.0F38.W1 F7 /rBEXTR r64a, r/m64, r64b|RMV|V/N.E.|BMI1|Contiguous bitwise extract from r/m64 using r64b as control; store result in r64a|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMV|ModRM:reg (w)|ModRM:r/m (r)|VEX.vvvv (r)|NA|
### Description


Extracts contiguous bits from the first source operand (the second operand) using an index value and length value specified in the second source operand (the third operand). Bit 7:0 of the second source operand specifies the starting bit position of bit extraction. A START value exceeding the operand size will not extract any bits from the second source operand. Bit 15:8 of the second source operand specifies the maximum number of bits (LENGTH) beginning at the START position to extract. Only bit positions up to (OperandSize -1) of the first source operand are extracted. The extracted bits are written to the destination register, starting from the least significant bit. All higher order bits in the destination operand (starting at bit position LENGTH) are zeroed. The destination register is cleared if no bits are extracted.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.


### Operation

```info-verb
START <- SRC2[7:0];
LEN <- SRC2[15:8];
TEMP <- ZERO_EXTEND_TO_512 (SRC1 );
DEST <- ZERO_EXTEND(TEMP[START+LEN -1: START]);
ZF <- (DEST = 0);
```
### Flags Affected


ZF is updated based on the result. AF, SF, and PF are undefined. All other flags are cleared. 


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BEXTR: unsigned __int32 _bextr_u32(unsigned __int32 src, unsigned __int32 start. unsigned __int32 len);
BEXTR: unsigned __int64 _bextr_u64(unsigned __int64 src, unsigned __int32 start. unsigned __int32 len);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

