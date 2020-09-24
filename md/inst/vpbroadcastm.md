----------------------------
title : VPBROADCASTM (Intel x86/64 assembly instruction)
cat_title : VPBROADCASTM
ref_title : VPBROADCASTM
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VPBROADCASTM

**Broadcast Mask to Vector Register **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.128.F3.0F38.W1 2A /r`\newline{}VPBROADCASTMB2Q \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RM |V/V |AVX512VL\newline{}AVX512CD|Broadcast low byte value in k1 to two locations in xmm1.|
|`EVEX.256.F3.0F38.W1 2A /r`\newline{}VPBROADCASTMB2Q \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RM |V/V |AVX512VL\newline{}AVX512CD|Broadcast low byte value in k1 to four locations in ymm1.|
|`EVEX.512.F3.0F38.W1 2A /r`\newline{}VPBROADCASTMB2Q zmm1 \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RM |V/V |AVX512CD|Broadcast low byte value in k1 to eight locations in zmm1.|
|`EVEX.128.F3.0F38.W0 3A /r`\newline{}VPBROADCASTMW2D \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RM |V/V |AVX512VL\newline{}AVX512CD|Broadcast low word value in k1 to four locations in xmm1.|
|`EVEX.256.F3.0F38.W0 3A /r`\newline{}VPBROADCASTMW2D \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RM |V/V |AVX512VL\newline{}AVX512CD|Broadcast low word value in k1 to eight locations in ymm1.|
|`EVEX.512.F3.0F38.W0 3A /r`\newline{}VPBROADCASTMW2D zmm1 \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} |RM |V/V |AVX512CD|Broadcast low word value in k1 to sixteen locations in zmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Broadcasts the zero-extended 64/32 bit value of the low byte/word of the source operand (the second operand) to each 64/32 bit element of the destination operand (the first operand). The source operand is an opmask register. The destination operand is a ZMM register (EVEX.512), YMM register (EVEX.256), or XMM register (EVEX.128).

EVEX.vvvv is reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### VPBROADCASTMB2Q
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
FOR j <-  0 TO KL-1
    i <-  j*64
    DEST[i+63:i] <-  ZeroExtend(SRC[7:0])
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPBROADCASTMW2D
```info-verb
(KL, VL) = (4, 128), (8, 256),(16, 512)
FOR j <-  0 TO KL-1
    i <-  j*32
    DEST[i+31:i] <-  ZeroExtend(SRC[15:0])
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPBROADCASTMB2Q __m512i _mm512_broadcastmb_epi64( __mmask8);
VPBROADCASTMW2D __m512i _mm512_broadcastmw_epi32( __mmask16);
VPBROADCASTMB2Q __m256i _mm256_broadcastmb_epi64( __mmask8);
VPBROADCASTMW2D __m256i _mm256_broadcastmw_epi32( __mmask8);
VPBROADCASTMB2Q __m128i _mm_broadcastmb_epi64( __mmask8);
VPBROADCASTMW2D __m128i _mm_broadcastmw_epi32( __mmask8);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


EVEX-encoded instruction, see Exceptions Type E6NF.

