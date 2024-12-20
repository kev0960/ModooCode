----------------------------
title : VGATHERDPS, VGATHERQPSs (Intel x86/64 assembly instruction)
cat_title : VGATHERDPS, VGATHERQPS
ref_title : VGATHERDPS, VGATHERQPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VGATHERDPS, VGATHERQPS

** Gather Packed SP FP values Using Signed Dword/Qword Indices **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|`VEX.DDS.128.66.0F38.W0 92 /r`\newline{}`VGATHERDPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |RMV|V/V|AVX2|Using dword indices specified in vm32x, gather single-preci-sion FP values from memory conditioned on mask specified by xmm2. Conditionally gathered elements are merged into xmm1.|
|`VEX.DDS.128.66.0F38.W0 93 /r`\newline{}`VGATHERQPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{vm64x}{vm32x 와 비슷하지만 이 경우 64 비트 주소값을 읽는다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |RMV|V/V|AVX2|Using qword indices specified in vm64x, gather single-preci-sion FP values from memory conditioned on mask specified by xmm2. Conditionally gathered elements are merged into xmm1.|
|`VEX.DDS.256.66.0F38.W0 92 /r`\newline{}`VGATHERDPS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{vm32y}{To-vm32x} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |RMV|V/V|AVX2|Using dword indices specified in vm32y, gather single-preci-sion FP values from memory conditioned on mask specified by ymm2. Conditionally gathered elements are merged into ymm1.|
|`VEX.DDS.256.66.0F38.W0 93 /r`\newline{}`VGATHERQPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{vm64y}{To-vm64x} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |RMV|V/V|AVX2|Using qword indices specified in vm64y, gather single-preci-sion FP values from memory conditioned on mask specified by xmm2. Conditionally gathered elements are merged into xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|A|ModRM:reg (r,w)|BaseReg (R): VSIB:base,VectorReg(R): VSIB:index|VEX.vvvv (r, w)|NA|
### Description


The instruction conditionally loads up to 4 or 8 single-precision floating-point values from memory addresses spec-ified by the memory operand (the second operand) and using dword indices. The memory operand uses the VSIB form of the SIB byte to specify a general purpose register operand as the common base, a vector register for an array of indices relative to the base and a constant scale factor.

The mask operand (the third operand) specifies the conditional load operation from each memory address and the corresponding update of each data element of the destination operand (the first operand). Conditionality is speci-fied by the most significant bit of each data element of the mask register. If an element's mask bit is not set, the corresponding element of the destination register is left unchanged. The width of data element in the destination register and mask register are identical. The entire mask register will be set to zero by this instruction unless the instruction causes an exception. 

Using qword indices, the instruction conditionally loads up to 2 or 4 single-precision floating-point values from the VSIB addressing memory operand, and updates the lower half of the destination register. The upper 128 or 256 bits of the destination register are zero'ed with qword indices.

This instruction can be suspended by an exception if at least one element is already gathered (i.e., if the exception is triggered by an element other than the rightmost one with its mask bit set).  When this happens, the destination register and the mask operand are partially updated; those elements that have been gathered are placed into the destination register and have their mask bits set to zero.  If any traps or interrupts are pending from already gath-ered elements, they will be delivered in lieu of the exception; in this case, EFLAG.RF is set to one so an instruction breakpoint is not re-triggered when the instruction is continued.

If the data size and index size are different, part of the destination register and part of the mask register do not correspond to any elements being gathered.  This instruction sets those parts to zero.  It may do this to one or both of those registers even if the instruction triggers an exception, and even if the instruction triggers the exception before gathering any elements.



VEX.128 version: For dword indices, the instruction will gather four single-precision floating-point values.  For qword indices, the instruction will gather two values and zeroes the upper 64 bits of the destination.

VEX.256 version: For dword indices, the instruction will gather eight single-precision floating-point values.  For qword indices, the instruction will gather four values and zeroes the upper 128 bits of the destination.

Note that:

*  If any pair of the index, mask, or destination registers are the same, this instruction results a UD fault.

*  The values may be read from memory in any order.  Memory ordering with other instructions follows the Intel-64 memory-ordering model.

*  Faults are delivered in a right-to-left manner.  That is, if a fault is triggered by an element and delivered, all elements closer to the LSB of the destination will be completed (and non-faulting).  Individual elements closer to the MSB may or may not be completed.  If a given element triggers multiple faults, they are delivered in the conventional order.

*  Elements may be gathered in any order, but faults must be delivered in a right-to-left order; thus, elements to the left of a faulting one may be gathered before the fault is delivered.  A given implementation of this instruction is repeatable - given the same input values and architectural state, the same set of elements to the left of the faulting one will be gathered.

*  This instruction does not perform AC checks, and so will never deliver an AC fault.

*  This instruction will cause a #UD if the address size attribute is 16-bit.

*  This instruction will cause a #UD if the memory operand is encoded without the SIB byte.

*  This instruction should not be used to access memory mapped I/O as the ordering of the individual loads it does is implementation specific, and some implementations may use loads larger than the data element size or load elements an indeterminate number of times.

*  The scaled index may require more bits to represent than the address bits used by the processor (e.g., in 32-bit mode, if the scale is greater than one).  In this case, the most significant bits beyond the number of address bits are ignored.


### Operation
#### VGATHERDPS (VEX.128 version)
```info-verb
FOR j<-  0 to 3
    i <-  j * 32;
    IF MASK[31+i] THEN
          MASK[i +31:i] <-  FFFFFFFFH; // extend from most significant bit
    ELSE
          MASK[i +31:i] <-  0;
    FI;
ENDFOR
MASK[VLMAX-1:128] <-  0;
FOR j<-  0 to 3 
    i <-  j * 32;
    DATA_ADDR <-  BASE_ADDR + (SignExtend(VINDEX[i+31:i])*SCALE + DISP;
    IF MASK[31+i] THEN
          DEST[i +31:i] <-  FETCH_32BITS(DATA_ADDR); // a fault exits the instruction
    FI;
    MASK[i +31:i] <-  0;
ENDFOR
DEST[VLMAX-1:128] <-  0;
(non-masked elements of the mask register have the content of respective element  cleared)
```
#### VGATHERQPS (VEX.128 version)
```info-verb
FOR j<-  0 to 3
    i <-  j * 32;
    IF MASK[31+i] THEN
          MASK[i +31:i] <-  FFFFFFFFH; // extend from most significant bit
    ELSE
          MASK[i +31:i] <-  0;
    FI;
ENDFOR
MASK[VLMAX-1:128] <-  0;
FOR j<-  0 to 1 
    k <-  j * 64;
    i <-  j * 32;
    DATA_ADDR <-  BASE_ADDR + (SignExtend(VINDEX1[k+63:k])*SCALE + DISP;
    IF MASK[31+i] THEN
          DEST[i +31:i] <-  FETCH_32BITS(DATA_ADDR); // a fault exits the instruction
    FI;
    MASK[i +31:i] <-  0;
ENDFOR
MASK[127:64] <-  0;
DEST[VLMAX-1:64] <-  0;
(non-masked elements of the mask register have the content of respective element  cleared)
```
#### VGATHERDPS (VEX.256 version)
```info-verb
FOR j<-  0 to 7
    i <-  j * 32;
    IF MASK[31+i] THEN
          MASK[i +31:i] <-  FFFFFFFFH; // extend from most significant bit
    ELSE
          MASK[i +31:i] <-  0;
    FI;
ENDFOR
FOR j<-  0 to 7
    i <-  j * 32;
    DATA_ADDR <-  BASE_ADDR + (SignExtend(VINDEX1[i+31:i])*SCALE + DISP;
    IF MASK[31+i] THEN
          DEST[i +31:i] <-  FETCH_32BITS(DATA_ADDR); // a fault exits the instruction
    FI;
    MASK[i +31:i] <-  0;
ENDFOR
(non-masked elements of the mask register have the content of respective element  cleared)
```
#### VGATHERQPS (VEX.256 version)
```info-verb
FOR j<-  0 to 7
    i <-  j * 32;
    IF MASK[31+i] THEN
          MASK[i +31:i] <-  FFFFFFFFH; // extend from most significant bit
    ELSE
          MASK[i +31:i] <-  0;
    FI;
ENDFOR
FOR j<-  0 to 3
    k <-  j * 64;
    i <-  j * 32;
    DATA_ADDR <-  BASE_ADDR + (SignExtend(VINDEX1[k+63:k])*SCALE + DISP;
    IF MASK[31+i] THEN
          DEST[i +31:i] <-  FETCH_32BITS(DATA_ADDR); // a fault exits the instruction
    FI;
    MASK[i +31:i] <-  0;
ENDFOR
MASK[VLMAX-1:128] <-  0;
DEST[VLMAX-1:128] <-  0;
(non-masked elements of the mask register have the content of respective element  cleared)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VGATHERDPS: __m128 _mm_i32gather_ps (float const * base, __m128i index, const int scale);
VGATHERDPS: __m128 _mm_mask_i32gather_ps (__m128 src, float const * base, __m128i index, __m128 mask, const int scale);
VGATHERDPS: __m256 _mm256_i32gather_ps (float const * base, __m256i index, const int scale);
VGATHERDPS: __m256 _mm256_mask_i32gather_ps (__m256 src, float const * base, __m256i index, __m256 mask, const int scale);
VGATHERQPS: __m128 _mm_i64gather_ps (float const * base, __m128i index, const int scale);
VGATHERQPS: __m128 _mm_mask_i64gather_ps (__m128 src, float const * base, __m128i index, __m128 mask, const int scale);
VGATHERQPS: __m128 _mm256_i64gather_ps (float const * base, __m256i index, const int scale);
VGATHERQPS: __m128 _mm256_mask_i64gather_ps (__m128 src, float const * base, __m256i index, __m128 mask, const int scale);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 12

