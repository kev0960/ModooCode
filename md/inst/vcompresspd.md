----------------------------
title : VCOMPRESSPD (Intel x86/64 assembly instruction)
cat_title : VCOMPRESSPD
ref_title : VCOMPRESSPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VCOMPRESSPD

**Store Sparse Packed Double-Precision Floating-Point Values into Dense Memory**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W1 8A /r\newline{}VCOMPRESSPD xmm1/m128 {k1}{z}, xmm2|T1S|V/V|AVX512VL\newline{}AVX512F|Compress packed double-precision floating-point values from xmm2 to xmm1/m128 using writemask k1.|
|EVEX.256.66.0F38.W1 8A /r\newline{}VCOMPRESSPD ymm1/m256 {k1}{z}, ymm2|T1S|V/V|AVX512VL\newline{}AVX512F|Compress packed double-precision floating-point values from ymm2 to ymm1/m256 using writemask k1.|
|EVEX.512.66.0F38.W1 8A /r\newline{}VCOMPRESSPD zmm1/m512 {k1}{z}, zmm2|T1S|V/V|AVX512F|Compress packed double-precision floating-point values from zmm2 using control mask k1 to zmm1/m512.|
###                                                       Instruction Operand Encoding


Op/En Operand 1 Operand 2 Operand 3 Operand 4

 T1S ModRM:r/m (w) ModRM:reg (r) NA NA

### Description 


Compress (store) up to 8 double-precision floating-point values from the source operand (the second operand) as a contiguous vector to the destination operand (the first operand) The source operand is a ZMM/YMM/XMM register, the destination operand can be a ZMM/YMM/XMM register or a 512/256/128-bit memory location.

The opmask register k1 selects the active elements (partial vector or possibly non-contiguous if less than 8 active elements) from the source operand to compress into a contiguous vector. The contiguous vector is written to the destination starting from the low element of the destination operand.

Memory destination version: Only the contiguous vector is written to the destination memory location. EVEX.z must be zero.

Register destination version: If the vector length of the contiguous vector is less than that of the input vector in the source operand, the upper bits of the destination register are unmodified if EVEX.z is not set, otherwise the upper bits are zeroed.

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.

Note that the compressed displacement assumes a pre-scaling (N) corresponding to the size of one single element instead of the size of the full vector.


### Operation
#### VCOMPRESSPD (EVEX encoded versions) store form
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
SIZE <-!= 64
k <-  0
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                DEST[k+SIZE-1:k]<-  SRC[i+63:i]
                k <-  k + SIZE
    FI;
ENDFOR
```
#### VCOMPRESSPD (EVEX encoded versions) reg-reg form
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
SIZE <-!= 64
k <-  0
FOR j <-  0 TO KL-1
    i <-  j * 64
    IF k1[j] OR *no writemask*
          THEN 
                DEST[k+SIZE-1:k]<-  SRC[i+63:i]
                k <-  k + SIZE
    FI;
ENDFOR
IF *merging-masking* 
           THEN *DEST[VL-1:k] remains unchanged*
           ELSE DEST[VL-1:k] <- 0
FI
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCOMPRESSPD __m512d _mm512_mask_compress_pd( __m512d s, __mmask8 k, __m512d a);
VCOMPRESSPD __m512d _mm512_maskz_compress_pd( __mmask8 k, __m512d a);
VCOMPRESSPD void _mm512_mask_compressstoreu_pd( void * d, __mmask8 k, __m512d a);
VCOMPRESSPD __m256d _mm256_mask_compress_pd( __m256d s, __mmask8 k, __m256d a);
VCOMPRESSPD __m256d _mm256_maskz_compress_pd( __mmask8 k, __m256d a);
VCOMPRESSPD void _mm256_mask_compressstoreu_pd( void * d, __mmask8 k, __m256d a);
VCOMPRESSPD __m128d _mm_mask_compress_pd( __m128d s, __mmask8 k, __m128d a);
VCOMPRESSPD __m128d _mm_maskz_compress_pd( __mmask8 k, __m128d a);
VCOMPRESSPD void _mm_mask_compressstoreu_pd( void * d, __mmask8 k, __m128d a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instructions, see Exceptions Type E4.nb.

#UD  If EVEX.vvvv != 1111B.
