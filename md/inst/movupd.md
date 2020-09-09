----------------------------
title : MOVUPD (Intel x86/64 assembly instruction)
cat_title : MOVUPD
ref_title : MOVUPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVUPD

**Move Unaligned Packed Double-Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 10 /r\newline{}MOVUPD xmm1, xmm2/m128|RM|V/V|SSE2|Move unaligned packed double-precision floating-point from xmm2/mem to xmm1.|
|66 0F 11 /r\newline{}MOVUPD xmm2/m128, xmm1|MR|V/V|SSE2|Move unaligned packed double-precision floating-point from xmm1 to xmm2/mem.|
|VEX.128.66.0F.WIG 10 /r\newline{}VMOVUPD xmm1, xmm2/m128|RM|V/V|AVX|Move unaligned packed double-precision floating-point from xmm2/mem to xmm1.|
|VEX.128.66.0F.WIG 11 /r\newline{}VMOVUPD xmm2/m128, xmm1|MR|V/V|AVX|Move unaligned packed double-precision floating-point from xmm1 to xmm2/mem.|
|VEX.256.66.0F.WIG 10 /r\newline{}VMOVUPD ymm1, ymm2/m256|RM|V/V|AVX|Move unaligned packed double-precision floating-point from ymm2/mem to ymm1.|
|VEX.256.66.0F.WIG 11 /r\newline{}VMOVUPD ymm2/m256, ymm1|MR|V/V|AVX|Move unaligned packed double-precision floating-point from ymm1 to ymm2/mem.|
|EVEX.128.66.0F.W1 10 /r\newline{}VMOVUPD xmm1 {k1}{z}, xmm2/m128|FVM-RM|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed double-precision floating-point from xmm2/m128 to xmm1 using writemask k1.|
|EVEX.128.66.0F.W1 11 /r\newline{}VMOVUPD xmm2/m128 {k1}{z}, xmm1|FVM-MR|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed double-precision floating-point from xmm1 to xmm2/m128 using writemask k1.|
|EVEX.256.66.0F.W1 10 /r\newline{}VMOVUPD ymm1 {k1}{z}, ymm2/m256|FVM-RM|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed double-precision floating-point from ymm2/m256 to ymm1 using writemask k1.|
|EVEX.256.66.0F.W1 11 /r\newline{}VMOVUPD ymm2/m256 {k1}{z}, ymm1|FVM-MR|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed double-precision floating-point from ymm1 to ymm2/m256 using writemask k1.|
|EVEX.512.66.0F.W1 10 /r\newline{}VMOVUPD zmm1 {k1}{z}, zmm2/m512|FVM-RM|V/V|AVX512F|Move unaligned packed double-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.|
|EVEX.512.66.0F.W1 11 /r\newline{}VMOVUPD zmm2/m512 {k1}{z}, zmm1|FVM-MR|V/V|AVX512F|Move unaligned packed double-precision floating-point values from zmm1 to zmm2/m512 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|FVM-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|RVM-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Note: VEX.vvvv and EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

EVEX.512 encoded version:

Moves 512 bits of packed double-precision floating-point values from the source operand (second operand) to the destination operand (first operand). This instruction can be used to load a ZMM register from a float64 memory location, to store the contents of a ZMM register into a memory. The destination operand is updated according to the writemask.



VEX.256 encoded version:

Moves 256 bits of packed double-precision floating-point values from the source operand (second operand) to the destination operand (first operand). This instruction can be used to load a YMM register from a 256-bit memory location, to store the contents of a YMM register into a 256-bit memory location, or to move data between two YMM registers. Bits (MAX\esc{_}VL-1:256) of the destination register are zeroed.

128-bit versions:

Moves 128 bits of packed double-precision floating-point values from the source operand (second operand) to the destination operand (first operand). This instruction can be used to load an XMM register from a 128-bit memory location, to store the contents of an XMM register into a 128-bit memory location, or to move data between two XMM registers. 

128-bit Legacy SSE version: Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

When the source or destination operand is a memory operand, the operand may be unaligned on a 16-byte boundary without causing a general-protection exception (#GP) to be generated

VEX.128 and EVEX.128 encoded versions: Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.


### Operation
#### VMOVUPD (EVEX encoded versions, register-copy form)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  DEST[i+63:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVUPD (EVEX encoded versions, store-form) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i]<-  SRC[i+63:i]
          ELSE *DEST[i+63:i] remains unchanged* ; merging-masking
    FI;
ENDFOR;
```
#### VMOVUPD (EVEX encoded versions, load-form) 
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-  SRC[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE  DEST[i+63:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
VMOVUPD (VEX.256 encoded version, load - and register copy)
DEST[255:0] <-  SRC[255:0]
DEST[MAX_VL-1:256] <-  0
```
#### VMOVUPD (VEX.256 encoded version, store-form)
```info-verb
DEST[255:0] <-  SRC[255:0]
```
#### VMOVUPD (VEX.128 encoded version)
```info-verb
DEST[127:0] <-  SRC[127:0]
DEST[MAX_VL-1:128] <-  0
```
#### MOVUPD (128-bit load- and register-copy- form Legacy SSE version)
```info-verb
DEST[127:0] <-  SRC[127:0]
DEST[MAX_VL-1:128] (Unmodified)
```
#### (V)MOVUPD (128-bit store-form version)
```info-verb
DEST[127:0] <-  SRC[127:0]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVUPD __m512d _mm512_loadu_pd( void * s);
VMOVUPD __m512d _mm512_mask_loadu_pd(__m512d a, __mmask8 k, void * s);
VMOVUPD __m512d _mm512_maskz_loadu_pd( __mmask8 k, void * s);
VMOVUPD void _mm512_storeu_pd( void * d, __m512d a);
VMOVUPD void _mm512_mask_storeu_pd( void * d, __mmask8 k, __m512d a);
VMOVUPD __m256d _mm256_mask_loadu_pd(__m256d s, __mmask8 k, void * m);
VMOVUPD __m256d _mm256_maskz_loadu_pd( __mmask8 k, void * m);
VMOVUPD void _mm256_mask_storeu_pd( void * d, __mmask8 k, __m256d a);
VMOVUPD __m128d _mm_mask_loadu_pd(__m128d s, __mmask8 k, void * m);
VMOVUPD __m128d _mm_maskz_loadu_pd( __mmask8 k, void * m);
VMOVUPD void _mm_mask_storeu_pd( void * d, __mmask8 k, __m128d a);
MOVUPD __m256d _mm256_loadu_pd (double * p);
MOVUPD void _mm256_storeu_pd( double *p, __m256d a);
MOVUPD __m128d _mm_loadu_pd (double * p);
MOVUPD void _mm_storeu_pd( double *p, __m128d a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

Note treatment of #AC varies; additionally

#UD If VEX.vvvv != 1111B.

EVEX-encoded instruction, see Exceptions Type E4.nb.
