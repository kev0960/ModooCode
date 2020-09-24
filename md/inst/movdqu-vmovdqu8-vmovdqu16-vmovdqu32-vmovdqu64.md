----------------------------
title : MOVDQU, VMOVDQU8, VMOVDQU16, VMOVDQU32, VMOVDQU64s (Intel x86/64 assembly instruction)
cat_title : MOVDQU, VMOVDQU8, VMOVDQU16, VMOVDQU32, VMOVDQU64
ref_title : MOVDQU, VMOVDQU8, VMOVDQU16, VMOVDQU32, VMOVDQU64
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVDQU, VMOVDQU8, VMOVDQU16, VMOVDQU32, VMOVDQU64

**Move Unaligned Packed Integer Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`F3 0F 6F /r`\newline{}`MOVDQU` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSE2|Move unaligned packed integer values from xmm2/m128 to xmm1. |
|`F3 0F 7F /r`\newline{}`MOVDQU` \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|SSE2|Move unaligned packed integer values from xmm1 to xmm2/m128. |
|`VEX.128.F3.0F.WIG 6F /r`\newline{}VMOVDQU \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Move unaligned packed integer values from xmm2/m128 to xmm1. |
|`VEX.128.F3.0F.WIG 7F /r`\newline{}VMOVDQU \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move unaligned packed integer values from xmm1 to xmm2/m128.|
|`VEX.256.F3.0F.WIG 6F /r`\newline{}VMOVDQU \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX|Move unaligned packed integer values from ymm2/m256 to ymm1.|
|`VEX.256.F3.0F.WIG 7F /r`\newline{}VMOVDQU \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |MR|V/V|AVX|Move unaligned packed integer values from ymm1 to ymm2/m256.|
|`EVEX.128.F2.0F.W0 6F /r`\newline{}`VMOVDQU8` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed byte integer values from xmm2/m128 to xmm1 using writemask k1.|
|`EVEX.256.F2.0F.W0 6F /r`\newline{}`VMOVDQU8` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed byte integer values from ymm2/m256 to ymm1 using writemask k1.|
|`EVEX.512.F2.0F.W0 6F /r`\newline{}`VMOVDQU8` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM-RM|V/V|AVX512BW|Move unaligned packed byte integer values from zmm2/m512 to zmm1 using writemask k1.|
|`EVEX.128.F2.0F.W0 7F /r`\newline{}`VMOVDQU8` \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed byte integer values from xmm1 to xmm2/m128 using writemask k1.|
|`EVEX.256.F2.0F.W0 7F /r`\newline{}`VMOVDQU8` \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed byte integer values from ymm1 to ymm2/m256 using writemask k1.|
|`EVEX.512.F2.0F.W0 7F /r`\newline{}`VMOVDQU8` \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm1 |FVM-MR|V/V|AVX512BW|Move unaligned packed byte integer values from zmm1 to zmm2/m512 using writemask k1.|
|`EVEX.128.F2.0F.W1 6F /r`\newline{}`VMOVDQU16` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed word integer values from xmm2/m128 to xmm1 using writemask k1.|
|`EVEX.256.F2.0F.W1 6F /r`\newline{}`VMOVDQU16` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed word integer values from ymm2/m256 to ymm1 using writemask k1.|
|`EVEX.512.F2.0F.W1 6F /r`\newline{}`VMOVDQU16` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM-RM|V/V|AVX512BW|Move unaligned packed word integer values from zmm2/m512 to zmm1 using writemask k1.|
|`EVEX.128.F2.0F.W1 7F /r`\newline{}`VMOVDQU16` \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed word integer values from xmm1 to xmm2/m128 using writemask k1.|
|`EVEX.256.F2.0F.W1 7F /r`\newline{}`VMOVDQU16` \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512BW|Move unaligned packed word integer values from ymm1 to ymm2/m256 using writemask k1.|
|`EVEX.512.F2.0F.W1 7F /r`\newline{}`VMOVDQU16` \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm1 |FVM-MR|V/V|AVX512BW|Move unaligned packed word integer values from zmm1 to zmm2/m512 using writemask k1.|
|`EVEX.128.F3.0F.W0 6F /r`\newline{}`VMOVDQU32` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} xmm2/mm128 |FVM-RM|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.|


|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|`EVEX.256.F3.0F.W0 6F /r`\newline{}`VMOVDQU32` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.|
|`EVEX.512.F3.0F.W0 6F /r`\newline{}`VMOVDQU32` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM-RM|V/V|AVX512F|Move unaligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.|
|`EVEX.128.F3.0F.W0 7F /r`\newline{}`VMOVDQU32` \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.|
|`EVEX.256.F3.0F.W0 7F /r`\newline{}`VMOVDQU32` \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.|
|`EVEX.512.F3.0F.W0 7F /r`\newline{}`VMOVDQU32` \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm1 |FVM-MR|V/V|AVX512F|Move unaligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.|
|`EVEX.128.F3.0F.W1 6F /r`\newline{}`VMOVDQU64` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed quadword integer values from xmm2/m128 to xmm1 using writemask k1.|
|`EVEX.256.F3.0F.W1 6F /r`\newline{}`VMOVDQU64` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM-RM|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed quadword integer values from ymm2/m256 to ymm1 using writemask k1.|
|`EVEX.512.F3.0F.W1 6F /r`\newline{}`VMOVDQU64` zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM-RM|V/V|AVX512F|Move unaligned packed quadword integer values from zmm2/m512 to zmm1 using writemask k1.|
|`EVEX.128.F3.0F.W1 7F /r`\newline{}`VMOVDQU64` \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed quadword integer values from xmm1 to xmm2/m128 using writemask k1.|
|`EVEX.256.F3.0F.W1 7F /r`\newline{}`VMOVDQU64` \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |FVM-MR|V/V|AVX512VL\newline{}AVX512F|Move unaligned packed quadword integer values from ymm1 to ymm2/m256 using writemask k1.|
|`EVEX.512.F3.0F.W1 7F /r`\newline{}`VMOVDQU64` \tooltip{zmm2/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm1 |FVM-MR|V/V|AVX512F|Move unaligned packed quadword integer values from zmm1 to zmm2/m512 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
|FVM-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FVM-MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.

EVEX encoded versions:

Moves 128, 256 or 512 bits of packed byte/word/doubleword/quadword integer values from the source operand (the second operand) to the destination operand (first operand). This instruction can be used to load a vector register from a memory location, to store the contents of a vector register into a memory location, or to move data between two vector registers. 



The destination operand is updated at 8-bit (VMOVDQU8), 16-bit (VMOVDQU16), 32-bit (VMOVDQU32), or 64-bit (VMOVDQU64) granularity according to the writemask.

VEX.256 encoded version:

Moves 256 bits of packed integer values from the source operand (second operand) to the destination operand (first operand). This instruction can be used to load a YMM register from a 256-bit memory location, to store the contents of a YMM register into a 256-bit memory location, or to move data between two YMM registers. 

Bits (MAX\esc{_}VL-1:256) of the destination register are zeroed.

128-bit versions:

Moves 128 bits of packed integer values from the source operand (second operand) to the destination operand (first operand). This instruction can be used to load an XMM register from a 128-bit memory location, to store the contents of an XMM register into a 128-bit memory location, or to move data between two XMM registers. 

128-bit Legacy SSE version: Bits (MAX\esc{_}VL-1:128) of the corresponding destination register remain unchanged.

When the source or destination operand is a memory operand, the operand may be unaligned to any alignment without causing a general-protection exception (#GP) to be generated

VEX.128 encoded version: Bits (MAX\esc{_}VL-1:128) of the destination register are zeroed.


### Operation
#### VMOVDQU8 (EVEX encoded versions, register-copy form)
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SRC[i+7:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE  DEST[i+7:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDQU8 (EVEX encoded versions, store-form) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i]<-  
                SRC[i+7:i]
          ELSE *DEST[i+7:i] remains unchanged* ; merging-masking
    FI;
ENDFOR;
```
#### VMOVDQU8 (EVEX encoded versions, load-form) 
```info-verb
(KL, VL) = (16, 128), (32, 256), (64, 512)
FOR j <-  0 TO KL-1
    i <-  j * 8
    IF k1[j] OR *no writemask*
          THEN DEST[i+7:i] <-  SRC[i+7:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+7:i] remains unchanged*
                      ELSE  DEST[i+7:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDQU16 (EVEX encoded versions, register-copy form)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SRC[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  DEST[i+15:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDQU16 (EVEX encoded versions, store-form) 
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i]<-  
                SRC[i+15:i]
          ELSE *DEST[i+15:i] remains unchanged* ; merging-masking
    FI;
ENDFOR;
```
#### VMOVDQU16 (EVEX encoded versions, load-form) 
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
FOR j <-  0 TO KL-1
    i <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-  SRC[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE  DEST[i+15:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDQU32 (EVEX encoded versions, register-copy form)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  DEST[i+31:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDQU32 (EVEX encoded versions, store-form) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i]<-  
                SRC[i+31:i]
          ELSE *DEST[i+31:i] remains unchanged* ; merging-masking
    FI;
ENDFOR;
```
#### VMOVDQU32 (EVEX encoded versions, load-form) 
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  SRC[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE  DEST[i+31:i] <-  0  ; zeroing-masking
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VMOVDQU64 (EVEX encoded versions, register-copy form)
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
#### VMOVDQU64 (EVEX encoded versions, store-form) 
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
#### VMOVDQU64 (EVEX encoded versions, load-form) 
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
#### VMOVDQU (VEX.256 encoded version, load - and register copy)
```info-verb
DEST[255:0] <-  SRC[255:0]
DEST[MAX_VL-1:256] <-  0
```
#### VMOVDQU (VEX.256 encoded version, store-form)
```info-verb
DEST[255:0] <-  SRC[255:0]
VMOVDQU (VEX.128 encoded version)
DEST[127:0] <-  SRC[127:0]
DEST[MAX_VL-1:128] <-  0
```
#### VMOVDQU (128-bit load- and register-copy- form Legacy SSE version)
```info-verb
DEST[127:0] <-  SRC[127:0]
DEST[MAX_VL-1:128] (Unmodified)
```
#### (V)MOVDQU (128-bit store-form version)
```info-verb
DEST[127:0] <-  SRC[127:0]
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VMOVDQU16 __m512i _mm512_mask_loadu_epi16(__m512i s, __mmask32 k, void * sa); 
VMOVDQU16 __m512i _mm512_maskz_loadu_epi16( __mmask32 k, void * sa); 
VMOVDQU16 void _mm512_mask_storeu_epi16(void * d, __mmask32 k, __m512i a); 
VMOVDQU16 __m256i _mm256_mask_loadu_epi16(__m256i s, __mmask16 k, void * sa); 
VMOVDQU16 __m256i _mm256_maskz_loadu_epi16( __mmask16 k, void * sa); 
VMOVDQU16 void _mm256_mask_storeu_epi16(void * d, __mmask16 k, __m256i a); 
VMOVDQU16 void _mm256_maskz_storeu_epi16(void * d, __mmask16 k); 
VMOVDQU16 __m128i _mm_mask_loadu_epi16(__m128i s, __mmask8 k, void * sa); 
VMOVDQU16 __m128i _mm_maskz_loadu_epi16( __mmask8 k, void * sa); 
VMOVDQU16 void _mm_mask_storeu_epi16(void * d, __mmask8 k, __m128i a); 
VMOVDQU32 __m512i _mm512_loadu_epi32( void * sa); 
VMOVDQU32 __m512i _mm512_mask_loadu_epi32(__m512i s, __mmask16 k, void * sa); 
VMOVDQU32 __m512i _mm512_maskz_loadu_epi32( __mmask16 k, void * sa); 
VMOVDQU32 void _mm512_storeu_epi32(void * d, __m512i a); 
VMOVDQU32 void _mm512_mask_storeu_epi32(void * d, __mmask16 k, __m512i a); 
VMOVDQU32 __m256i _mm256_mask_loadu_epi32(__m256i s, __mmask8 k, void * sa); 
VMOVDQU32 __m256i _mm256_maskz_loadu_epi32( __mmask8 k, void * sa); 
VMOVDQU32 void _mm256_storeu_epi32(void * d, __m256i a); 
VMOVDQU32 void _mm256_mask_storeu_epi32(void * d, __mmask8 k, __m256i a); 
VMOVDQU32 __m128i _mm_mask_loadu_epi32(__m128i s, __mmask8 k, void * sa); 
VMOVDQU32 __m128i _mm_maskz_loadu_epi32( __mmask8 k, void * sa); 
VMOVDQU32 void _mm_storeu_epi32(void * d, __m128i a); 
VMOVDQU32 void _mm_mask_storeu_epi32(void * d, __mmask8 k, __m128i a); 
VMOVDQU64 __m512i _mm512_loadu_epi64( void * sa); 
VMOVDQU64 __m512i _mm512_mask_loadu_epi64(__m512i s, __mmask8 k, void * sa); 
VMOVDQU64 __m512i _mm512_maskz_loadu_epi64( __mmask8 k, void * sa); 
VMOVDQU64 void _mm512_storeu_epi64(void * d, __m512i a); 
VMOVDQU64 void _mm512_mask_storeu_epi64(void * d, __mmask8 k, __m512i a); 
VMOVDQU64 __m256i _mm256_mask_loadu_epi64(__m256i s, __mmask8 k, void * sa); 
VMOVDQU64 __m256i _mm256_maskz_loadu_epi64( __mmask8 k, void * sa); 
VMOVDQU64 void _mm256_storeu_epi64(void * d, __m256i a); 
VMOVDQU64 void _mm256_mask_storeu_epi64(void * d, __mmask8 k, __m256i a); 
VMOVDQU64 __m128i _mm_mask_loadu_epi64(__m128i s, __mmask8 k, void * sa); 
VMOVDQU64 __m128i _mm_maskz_loadu_epi64( __mmask8 k, void * sa); 
VMOVDQU64 void _mm_storeu_epi64(void * d, __m128i a); 
VMOVDQU64 void _mm_mask_storeu_epi64(void * d, __mmask8 k, __m128i a); 
VMOVDQU8 __m512i _mm512_mask_loadu_epi8(__m512i s, __mmask64 k, void * sa); 
VMOVDQU8 __m512i _mm512_maskz_loadu_epi8( __mmask64 k, void * sa); 
VMOVDQU8 void _mm512_mask_storeu_epi8(void * d, __mmask64 k, __m512i a); 
VMOVDQU8 __m256i _mm256_mask_loadu_epi8(__m256i s, __mmask32 k, void * sa); 
VMOVDQU8 __m256i _mm256_maskz_loadu_epi8( __mmask32 k, void * sa); 
VMOVDQU8 void _mm256_mask_storeu_epi8(void * d, __mmask32 k, __m256i a); 
VMOVDQU8 void _mm256_maskz_storeu_epi8(void * d, __mmask32 k); 
VMOVDQU8 __m128i _mm_mask_loadu_epi8(__m128i s, __mmask16 k, void * sa); 
VMOVDQU8 __m128i _mm_maskz_loadu_epi8( __mmask16 k, void * sa); 
VMOVDQU8 void _mm_mask_storeu_epi8(void * d, __mmask16 k, __m128i a); 
MOVDQU __m256i _mm256_loadu_si256 (__m256i * p);
MOVDQU _mm256_storeu_si256(_m256i *p, __m256i a);
MOVDQU __m128i _mm_loadu_si128 (__m128i * p);
MOVDQU _mm_storeu_si128(__m128i *p, __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4; 

EVEX-encoded instruction, see Exceptions Type E4.nb.

#UD If EVEX.vvvv != 1111B or VEX.vvvv != 1111B.

