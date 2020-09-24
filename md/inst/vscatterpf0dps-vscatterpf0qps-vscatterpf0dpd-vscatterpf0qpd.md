----------------------------
title : VSCATTERPF0DPS, VSCATTERPF0QPS, VSCATTERPF0DPD, VSCATTERPF0QPDs (Intel x86/64 assembly instruction)
cat_title : VSCATTERPF0DPS, VSCATTERPF0QPS, VSCATTERPF0DPD, VSCATTERPF0QPD
ref_title : VSCATTERPF0DPS, VSCATTERPF0QPS, VSCATTERPF0DPD, VSCATTERPF0QPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VSCATTERPF0DPS, VSCATTERPF0QPS, VSCATTERPF0DPD, VSCATTERPF0QPD

**Sparse Prefetch Packed SP/DP Data Values with Signed Dword, Signed Qword Indices Using T0 Hint with Intent to Write**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.512.66.0F38.W0 C6 /5 /vsib `\newline{}`VSCATTERPF0DPS` \tooltip{vm32z}{To-vm32x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} |T1S|V/V|AVX512PF|Using signed dword indices, prefetch sparse byte memory locations containing single-precision data using writemask k1 and T0 hint with intent to write.|
|`EVEX.512.66.0F38.W0 C7 /5 /vsib `\newline{}`VSCATTERPF0QPS` \tooltip{vm64z}{To-vm64x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} |T1S|V/V|AVX512PF|Using signed qword indices, prefetch sparse byte memory locations containing single-precision data using writemask k1 and T0 hint with intent to write.|
|`EVEX.512.66.0F38.W1 C6 /5 /vsib `\newline{}`VSCATTERPF0DPD` \tooltip{vm32y}{To-vm32x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} |T1S|V/V|AVX512PF|Using signed dword indices, prefetch sparse byte memory locations containing double-precision data using writemask k1 and T0 hint with intent to write.|
|`EVEX.512.66.0F38.W1 C7 /5 /vsib`\newline{}`VSCATTERPF0QPD` \tooltip{vm64z}{To-vm64x} \tooltip{\{k1\}}{\{k1\}\{z\} 와는 다르게 \{z\} 가 없다. 이 경우 병합 마스크 방식만 지원하고 zeroing mask 는 지원하지 않는다.} |T1S|V/V|AVX512PF|Using signed qword indices, prefetch sparse byte memory locations containing double-precision data using writemask k1 and T0 hint with intent to write.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|T1S|BaseReg (R): VSIB:base,VectorReg(R): VSIB:index|NA|NA|NA|
### Description


The instruction conditionally prefetches up to sixteen 32-bit or eight 64-bit integer byte data elements. The elements are specified via the VSIB (i.e., the index register is an zmm, holding packed indices). Elements will only be prefetched if their corresponding mask bit is one. 

cache lines will be brought into exclusive state (RFO) specified by a locality hint (T0):

*  T0 (temporal data)--prefetch data into the first level cache.

[PS data] For dword indices, the instruction will prefetch sixteen memory locations. For qword indices, the instruc-tion will prefetch eight values.

[PD data] For dword and qword indices, the instruction will prefetch eight memory locations. 

Note that:

(1) The prefetches may happen in any order (or not at all). The instruction is a hint.

(2) The mask is left unchanged.

(3) Not valid with 16-bit effective addresses. Will deliver a #UD fault.

(4) No FP nor memory faults may be produced by this instruction.

(5) Prefetches do not handle cache line splits

(6) A #UD is signaled if the memory operand is encoded without the SIB byte.


### Operation
#### VSCATTERPF0DPS (EVEX encoded version)
```info-verb
(KL, VL) = (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] 
          Prefetch( [BASE_ADDR + SignExtend(VINDEX[i+31:i]) * SCALE + DISP], Level=0, RFO = 1)
    FI;
ENDFOR
```
#### VSCATTERPF0DPD (EVEX encoded version)
```info-verb
(KL, VL) = (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    k <-  j * 32
    IF k1[j] 
          Prefetch( [BASE_ADDR + SignExtend(VINDEX[k+31:k]) * SCALE + DISP], Level=0, RFO = 1)
    FI;
ENDFOR
```
#### VSCATTERPF0QPS (EVEX encoded version)
```info-verb
(KL, VL) = (8, 256)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] 
          Prefetch( [BASE_ADDR + SignExtend(VINDEX[i+63:i]) * SCALE + DISP], Level=0, RFO = 1)
    FI;
ENDFOR
```
#### VSCATTERPF0QPD (EVEX encoded version)
```info-verb
(KL, VL) = (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    k <-  j * 64
    IF k1[j] 
          Prefetch( [BASE_ADDR + SignExtend(VINDEX[k+63:k]) * SCALE + DISP], Level=0, RFO = 1)
    FI;
ENDFOR
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VSCATTERPF0DPD void _mm512_prefetch_i32scatter_pd(void *base, __m256i vdx, int scale, int hint);
VSCATTERPF0DPD void _mm512_mask_prefetch_i32scatter_pd(void *base, __mmask8 m, __m256i vdx, int scale, int hint);
VSCATTERPF0DPS void _mm512_prefetch_i32scatter_ps(void *base, __m512i vdx, int scale, int hint);
VSCATTERPF0DPS void _mm512_mask_prefetch_i32scatter_ps(void *base, __mmask16 m, __m512i vdx, int scale, int hint);
VSCATTERPF0QPD void _mm512_prefetch_i64scatter_pd(void * base, __m512i vdx, int scale, int hint);
VSCATTERPF0QPD void _mm512_mask_prefetch_i64scatter_pd(void * base, __mmask8 m, __m512i vdx, int scale, int hint);
VSCATTERPF0QPS void _mm512_prefetch_i64scatter_ps(void * base, __m512i vdx, int scale, int hint);
VSCATTERPF0QPS void _mm512_mask_prefetch_i64scatter_ps(void * base, __mmask8 m, __m512i vdx, int scale, int hint);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type E12NP.

