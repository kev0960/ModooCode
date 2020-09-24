----------------------------
title : VPGATHERDD, VPGATHERDQs (Intel x86/64 assembly instruction)
cat_title : VPGATHERDD, VPGATHERDQ
ref_title : VPGATHERDD, VPGATHERDQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPGATHERDD, VPGATHERDQ

**Gather Packed Dword, Packed Qword with Signed Dword Indices**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.128.66.0F38.W0 90 /vsib `\newline{}`VPGATHERDD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, gather dword values from memory using writemask k1 for merging-masking.|
|`EVEX.256.66.0F38.W0 90 /vsib `\newline{}`VPGATHERDD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{vm32y}{To-vm32x} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, gather dword values from memory using writemask k1 for merging-masking.|
|`EVEX.512.66.0F38.W0 90 /vsib `\newline{}`VPGATHERDD` zmm1 \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{vm32z}{To-vm32x} |T1S|V/V|AVX512F|Using signed dword indices, gather dword values from memory using writemask k1 for merging-masking.|
|`EVEX.128.66.0F38.W1 90 /vsib `\newline{}`VPGATHERDQ` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, gather quadword values from memory using writemask k1 for merging-masking.|
|`EVEX.256.66.0F38.W1 90 /vsib `\newline{}`VPGATHERDQ` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, gather quadword values from memory using writemask k1 for merging-masking.|
|`EVEX.512.66.0F38.W1 90 /vsib `\newline{}`VPGATHERDQ` zmm1 \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{vm32y}{To-vm32x} |T1S|V/V|AVX512F|Using signed dword indices, gather quadword values from memory using writemask k1 for merging-masking.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|ModRM:reg (w)|BaseReg (R): VSIB:base,VectorReg(R): VSIB:index|NA|NA|
### Description


A set of 16 or 8 doubleword/quadword memory locations pointed to by base address BASE\esc{_}ADDR and index vector VINDEX with scale SCALE are gathered. The result is written into vector zmm1. The elements are specified via the VSIB (i.e., the index register is a zmm, holding packed indices). Elements will only be loaded if their corresponding mask bit is one. If an element's mask bit is not set, the corresponding element of the destination register (zmm1) is left unchanged. The entire mask register will be set to zero by this instruction unless it triggers an exception.

This instruction can be suspended by an exception if at least one element is already gathered (i.e., if the exception is triggered by an element other than the rightmost one with its mask bit set). When this happens, the destination register and the mask register (k1) are partially updated; those elements that have been gathered are placed into the destination register and have their mask bits set to zero. If any traps or interrupts are pending from already gathered elements, they will be delivered in lieu of the exception; in this case, EFLAG.RF is set to one so an instruc-tion breakpoint is not re-triggered when the instruction is continued.

If the data element size is less than the index element size, the higher part of the destination register and the mask register do not correspond to any elements being gathered. This instruction sets those higher parts to zero. It may update these unused elements to one or both of those registers even if the instruction triggers an exception, and even if the instruction triggers the exception before gathering any elements.

Note that:

*  The values may be read from memory in any order. Memory ordering with other instructions follows the Intel-64 memory-ordering model.

*  Faults are delivered in a right-to-left manner. That is, if a fault is triggered by an element and delivered, all elements closer to the LSB of the destination zmm will be completed (and non-faulting). Individual elements closer to the MSB may or may not be completed. If a given element triggers multiple faults, they are delivered in the conventional order.

*  Elements may be gathered in any order, but faults must be delivered in a right-to-left order; thus, elements to the left of a faulting one may be gathered before the fault is delivered. A given implementation of this instruction is repeatable - given the same input values and architectural state, the same set of elements to the left of the faulting one will be gathered.

*  This instruction does not perform AC checks, and so will never deliver an AC fault.

*  Not valid with 16-bit effective addresses. Will deliver a #UD fault.

*  These instructions do not accept zeroing-masking since the 0 values in k1 are used to determine completion.



Note that the presence of VSIB byte is enforced in this instruction. Hence, the instruction will #UD fault if ModRM.rm is different than 100b.

This instruction has the same disp8\htmlonly{\esc{*}}N and alignment rules as for scalar instructions (Tuple 1).

The instruction will #UD fault if the destination vector zmm1 is the same as index vector VINDEX. The instruction will #UD fault if the k0 mask register is specified.

The scaled index may require more bits to represent than the address bits used by the processor (e.g., in 32-bit mode, if the scale is greater than one). In this case, the most significant bits beyond the number of address bits are ignored.


### Operation
#### VPGATHERDD (EVEX encoded version)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j]
          THEN DEST[i+31:i] <-  MEM[BASE_ADDR +SignExtend(VINDEX[i+31:i]) * SCALE + DISP]), 1)
                k1[j] <-  0
          ELSE *DEST[i+31:i] <-  remains unchanged*   ; Only merging masking is allowed
    FI;
ENDFOR
k1[MAX_KL-1:KL] <-  0
DEST[MAX_VL-1:VL] <-  0
```
#### VPGATHERDQ (EVEX encoded version)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    k <-  j * 32
    IF k1[j]
          THEN DEST[i+63:i] <-  
                MEM[BASE_ADDR + SignExtend(VINDEX[k+31:k]) * SCALE + DISP])
                k1[j] <-  0
          ELSE *DEST[i+63:i] <-  remains unchanged*   ; Only merging masking is allowed
    FI;
ENDFOR
k1[MAX_KL-1:KL] <-  0
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPGATHERDD __m512i _mm512_i32gather_epi32( __m512i vdx, void * base, int scale);
VPGATHERDD __m512i _mm512_mask_i32gather_epi32(__m512i s, __mmask16 k, __m512i vdx, void * base, int scale);
VPGATHERDD __m256i _mm256_mmask_i32gather_epi32(__m256i s, __mmask8 k, __m256i vdx, void * base, int scale);
VPGATHERDD __m128i _mm_mmask_i32gather_epi32(__m128i s, __mmask8 k, __m128i vdx, void * base, int scale);
VPGATHERDQ __m512i _mm512_i32logather_epi64( __m256i vdx, void * base, int scale);
VPGATHERDQ __m512i _mm512_mask_i32logather_epi64(__m512i s, __mmask8 k, __m256i vdx, void * base, int scale);
VPGATHERDQ __m256i _mm256_mmask_i32logather_epi64(__m256i s, __mmask8 k, __m128i vdx, void * base, int scale);
VPGATHERDQ __m128i _mm_mmask_i32gather_epi64(__m128i s, __mmask8 k, __m128i vdx, void * base, int scale);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E12.

