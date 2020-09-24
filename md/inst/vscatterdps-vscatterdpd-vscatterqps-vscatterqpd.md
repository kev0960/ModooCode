----------------------------
title : VSCATTERDPS, VSCATTERDPD, VSCATTERQPS, VSCATTERQPDs (Intel x86/64 assembly instruction)
cat_title : VSCATTERDPS, VSCATTERDPD, VSCATTERQPS, VSCATTERQPD
ref_title : VSCATTERDPS, VSCATTERDPD, VSCATTERQPS, VSCATTERQPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VSCATTERDPS, VSCATTERDPD, VSCATTERQPS, VSCATTERQPD

**Scatter Packed Single, Packed Double with Signed Dword and Qword Indices**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/E**\newline{}**n**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.128.66.0F38.W0 A2 /vsib `\newline{}`VSCATTERDPS` \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, scatter single-precision floating-point values to memory using writemask k1.|
|`EVEX.256.66.0F38.W0 A2 /vsib `\newline{}`VSCATTERDPS` \tooltip{vm32y}{To-vm32x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, scatter single-precision floating-point values to memory using writemask k1.|
|`EVEX.512.66.0F38.W0 A2 /vsib `\newline{}`VSCATTERDPS` \tooltip{vm32z}{To-vm32x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} zmm1 |T1S|V/V|AVX512F|Using signed dword indices, scatter single-precision floating-point values to memory using writemask k1.|
|`EVEX.128.66.0F38.W1 A2 /vsib`\newline{}`VSCATTERDPD` \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, scatter double-precision floating-point values to memory using writemask k1.|
|`EVEX.256.66.0F38.W1 A2 /vsib `\newline{}`VSCATTERDPD` \tooltip{vm32x}{VSIB 메모리 주소값 방식을 사용한 벡터 메모리 데이터 배열들. 메모리 주소 배열은 베이스 레지스터, scale, 벡터 인덱스 레지스터와 XMM (vm32x), YMM (vm32y), ZMM (vm32z) 레지스터들에 들어 있는 32 비트 주소값을 통해 결정된다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed dword indices, scatter double-precision floating-point values to memory using writemask k1.|
|`EVEX.512.66.0F38.W1 A2 /vsib `\newline{}`VSCATTERDPD` \tooltip{vm32y}{To-vm32x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} zmm1 |T1S|V/V|AVX512F|Using signed dword indices, scatter double-precision floating-point values to memory using writemask k1.|
|`EVEX.128.66.0F38.W0 A3 /vsib`\newline{}`VSCATTERQPS` \tooltip{vm64x}{vm32x 와 비슷하지만 이 경우 64 비트 주소값을 읽는다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed qword indices, scatter single-precision floating-point values to memory using writemask k1.|
|`EVEX.256.66.0F38.W0 A3 /vsib `\newline{}`VSCATTERQPS` \tooltip{vm64y}{To-vm64x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed qword indices, scatter single-precision floating-point values to memory using writemask k1.|
|`EVEX.512.66.0F38.W0 A3 /vsib `\newline{}`VSCATTERQPS` \tooltip{vm64z}{To-vm64x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512F|Using signed qword indices, scatter single-precision floating-point values to memory using writemask k1.|
|`EVEX.128.66.0F38.W1 A3 /vsib `\newline{}`VSCATTERQPD` \tooltip{vm64x}{vm32x 와 비슷하지만 이 경우 64 비트 주소값을 읽는다.} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed qword indices, scatter double-precision floating-point values to memory using writemask k1.|
|`EVEX.256.66.0F38.W1 A3 /vsib `\newline{}`VSCATTERQPD` \tooltip{vm64y}{To-vm64x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |T1S|V/V|AVX512VL\newline{}AVX512F|Using signed qword indices, scatter double-precision floating-point values to memory using writemask k1.|
|`EVEX.512.66.0F38.W1 A3 /vsib `\newline{}`VSCATTERQPD` \tooltip{vm64z}{To-vm64x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} zmm1 |T1S|V/V|AVX512F|Using signed qword indices, scatter double-precision floating-point values to memory using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|BaseReg (R): VSIB:base,VectorReg(R): VSIB:index|ModRM:reg (r)|NA|NA|
### Description


Stores up to 16 elements (or 8 elements) in doubleword/quadword vector zmm1 to the memory locations pointed by base address BASE\esc{_}ADDR and index vector VINDEX, with scale SCALE. The elements are specified via the VSIB (i.e., the index register is a vector register, holding packed indices). Elements will only be stored if their corre-sponding mask bit is one. The entire mask register will be set to zero by this instruction unless it triggers an excep-tion.

This instruction can be suspended by an exception if at least one element is already scattered (i.e., if the exception is triggered by an element other than the rightmost one with its mask bit set). When this happens, the destination register and the mask register (k1) are partially updated. If any traps or interrupts are pending from already scat-tered elements, they will be delivered in lieu of the exception; in this case, EFLAG.RF is set to one so an instruction breakpoint is not re-triggered when the instruction is continued.

Note that:

*  Only writes to overlapping vector indices are guaranteed to be ordered with respect to each other (from LSB to MSB of the source registers). Note that this also include partially overlapping vector indices. Writes that are not overlapped may happen in any order. Memory ordering with other instructions follows the Intel-64 memory ordering model. Note that this does not account for non-overlapping indices that map into the same physical address locations.



*  If two or more destination indices completely overlap, the "earlier" write(s) may be skipped.

*  Faults are delivered in a right-to-left manner. That is, if a fault is triggered by an element and delivered, all elements closer to the LSB of the destination zmm will be completed (and non-faulting). Individual elements closer to the MSB may or may not be completed. If a given element triggers multiple faults, they are delivered in the conventional order.

*  Elements may be scattered in any order, but faults must be delivered in a right-to left order; thus, elements to the left of a faulting one may be gathered before the fault is delivered. A given implementation of this instruction is repeatable - given the same input values and architectural state, the same set of elements to the left of the faulting one will be gathered.

*  This instruction does not perform AC checks, and so will never deliver an AC fault.

*  Not valid with 16-bit effective addresses. Will deliver a #UD fault.

*  If this instruction overwrites itself and then takes a fault, only a subset of elements may be completed before the fault is delivered (as described above). If the fault handler completes and attempts to re-execute this instruction, the new instruction will be executed, and the scatter will not complete.

Note that the presence of VSIB byte is enforced in this instruction. Hence, the instruction will #UD fault if ModRM.rm is different than 100b.

This instruction has special disp8\htmlonly{\esc{*}}N and alignment rules. N is considered to be the size of a single vector element.

The scaled index may require more bits to represent than the address bits used by the processor (e.g., in 32-bit mode, if the scale is greater than one). In this case, the most significant bits beyond the number of address bits are ignored.

The instruction will #UD fault if the k0 mask register is specified


### Operation
#### VSCATTERDPS (EVEX encoded versions)
```info-verb
(KL, VL)= (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN MEM[BASE_ADDR +SignExtend(VINDEX[i+31:i]) * SCALE + DISP] <-
                SRC[i+31:i]
                k1[j] <-  0
    FI;
ENDFOR
k1[MAX_KL-1:KL] <-  0
```
#### VSCATTERDPD (EVEX encoded versions)
```info-verb
(KL, VL)= (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    k <-  j * 32
    IF k1[j] OR *no writemask*
          THEN MEM[BASE_ADDR +SignExtend(VINDEX[k+31:k]) * SCALE + DISP] <-
                SRC[i+63:i]
                k1[j] <-  0
    FI;
ENDFOR
k1[MAX_KL-1:KL] <-  0
```
#### VSCATTERQPS (EVEX encoded versions)
```info-verb
(KL, VL)= (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    k <-  j * 64
    IF k1[j] OR *no writemask*
          THEN MEM[BASE_ADDR + (VINDEX[k+63:k]) * SCALE + DISP] <-
                SRC[i+31:i]
                k1[j] <-  0
    FI;
ENDFOR
k1[MAX_KL-1:KL] <-  0
```
#### VSCATTERQPD (EVEX encoded versions)
```info-verb
(KL, VL)= (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN MEM[BASE_ADDR + (VINDEX[i+63:i]) * SCALE + DISP] <-
                SRC[i+63:i]
                k1[j] <-  0
    FI;
ENDFOR
k1[MAX_KL-1:KL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSCATTERDPD void _mm512_i32scatter_pd(void * base, __m256i vdx, __m512d a, int scale);
VSCATTERDPD void _mm512_mask_i32scatter_pd(void * base, __mmask8 k, __m256i vdx, __m512d a, int scale);
VSCATTERDPS void _mm512_i32scatter_ps(void * base, __m512i vdx, __m512 a, int scale);
VSCATTERDPS void _mm512_mask_i32scatter_ps(void * base, __mmask16 k, __m512i vdx, __m512 a, int scale);
VSCATTERQPD void _mm512_i64scatter_pd(void * base, __m512i vdx, __m512d a, int scale);
VSCATTERQPD void _mm512_mask_i64scatter_pd(void * base, __mmask8 k, __m512i vdx, __m512d a, int scale);
VSCATTERQPS void _mm512_i64scatter_ps(void * base, __m512i vdx, __m256 a, int scale);
VSCATTERQPS void _mm512_mask_i64scatter_ps(void * base, __mmask8 k, __m512i vdx, __m256 a, int scale);
VSCATTERDPD void _mm256_i32scatter_pd(void * base, __m128i vdx, __m256d a, int scale);
VSCATTERDPD void _mm256_mask_i32scatter_pd(void * base, __mmask8 k, __m128i vdx, __m256d a, int scale);
VSCATTERDPS void _mm256_i32scatter_ps(void * base, __m256i vdx, __m256 a, int scale);
VSCATTERDPS void _mm256_mask_i32scatter_ps(void * base, __mmask8 k, __m256i vdx, __m256 a, int scale);
VSCATTERQPD void _mm256_i64scatter_pd(void * base, __m256i vdx, __m256d a, int scale);
VSCATTERQPD void _mm256_mask_i64scatter_pd(void * base, __mmask8 k, __m256i vdx, __m256d a, int scale);
VSCATTERQPS void _mm256_i64scatter_ps(void * base, __m256i vdx, __m128 a, int scale);
VSCATTERQPS void _mm256_mask_i64scatter_ps(void * base, __mmask8 k, __m256i vdx, __m128 a, int scale);
VSCATTERDPD void _mm_i32scatter_pd(void * base, __m128i vdx, __m128d a, int scale);
VSCATTERDPD void _mm_mask_i32scatter_pd(void * base, __mmask8 k, __m128i vdx, __m128d a, int scale);
VSCATTERDPS void _mm_i32scatter_ps(void * base, __m128i vdx, __m128 a, int scale);
VSCATTERDPS void _mm_mask_i32scatter_ps(void * base, __mmask8 k, __m128i vdx, __m128 a, int scale);
VSCATTERQPD void _mm_i64scatter_pd(void * base, __m128i vdx, __m128d a, int scale);
VSCATTERQPD void _mm_mask_i64scatter_pd(void * base, __mmask8 k, __m128i vdx, __m128d a, int scale);
VSCATTERQPS void _mm_i64scatter_ps(void * base, __m128i vdx, __m128 a, int scale);
VSCATTERQPS void _mm_mask_i64scatter_ps(void * base, __mmask8 k, __m128i vdx, __m128 a, int scale);
```
### SIMD Floating-Point Exceptions


Invalid, Overflow, Underflow, Precision, Denormal

### Other Exceptions


See Exceptions Type E12.

