----------------------------
title : BLENDVPD (Intel x86/64 assembly instruction)
cat_title : BLENDVPD
ref_title : BLENDVPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BLENDVPD

** Variable Blend Packed Double Precision Floating-Point Values**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`66 0F 38 15 /r`\newline{}`BLENDVPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{<XMM0>}{M0 레지스터가 사용됨을 의미.} |RM0|V/V|SSE4_1|Select packed DP FP values from xmm1 and xmm2 from mask specified in XMM0 and store the values in xmm1.|
|`VEX.NDS.128.66.0F3A.W0 4B /r /is4`\newline{}VBLENDVPD \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{xmm4}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |RVMR|V/V|AVX|Conditionally copy double-precision floating-point values from xmm2 or xmm3/m128 to xmm1, based on mask bits in the mask operand, xmm4.|
|`VEX.NDS.256.66.0F3A.W0 4B /r /is4`\newline{}VBLENDVPD \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} \tooltip{ymm4}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |RVMR|V/V|AVX|Conditionally copy double-precision floating-point values from ymm2 or ymm3/m256 to ymm1, based on mask bits in the mask operand, ymm4.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM0|ModRM:reg (r, w)|ModRM:r/m (r)|implicit XMM0|NA|
|RVMR|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8[7:4]|
### Description


Conditionally copy each quadword data element of double-precision floating-point value from the second source operand and the first source operand depending on mask bits defined in the mask register operand. The mask bits are the most significant bit in each quadword element of the mask register.

Each quadword element of the destination operand is copied from:

*  the corresponding quadword element in the second source operand, if a mask bit is "1"; or

*  the corresponding quadword element in the first source operand, if a mask bit is "0"

The register assignment of the implicit mask operand for `BLENDVPD` is defined to be the architectural register XMM0.

128-bit Legacy SSE version: The first source operand and the destination operand is the same. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged. The mask register operand is implicitly defined to be the architectural register XMM0. An attempt to execute `BLENDVPD` with a VEX prefix will cause #UD.

VEX.128 encoded version: The first source operand and the destination operand are XMM registers. The second source operand is an XMM register or 128-bit memory location. The mask operand is the third source register, and encoded in bits[7:4] of the immediate byte(imm8). The bits[3:0] of imm8 are ignored. In 32-bit mode, imm8[7] is ignored. The upper bits (VLMAX-1:128) of the corresponding YMM register (destination register) are zeroed. VEX.W must be 0, otherwise, the instruction will #UD.

VEX.256 encoded version: The first source operand and destination operand are YMM registers. The second source operand can be a YMM register or a 256-bit memory location. The mask operand is the third source register, and encoded in bits[7:4] of the immediate byte(imm8). The bits[3:0] of imm8 are ignored. In 32-bit mode, imm8[7] is ignored. VEX.W must be 0, otherwise, the instruction will #UD.

VBLENDVPD permits the mask to be any XMM or YMM register. In contrast, `BLENDVPD` treats XMM0 implicitly as the mask and do not support non-destructive destination operation. 


### Operation
#### BLENDVPD (128-bit Legacy SSE version)
```info-verb
MASK <-  XMM0
IF (MASK[63] = 0) THEN DEST[63:0] <-  DEST[63:0]
          ELSE DEST [63:0] <-  SRC[63:0] FI
IF (MASK[127] = 0) THEN DEST[127:64] <-  DEST[127:64]
          ELSE DEST [127:64] <-  SRC[127:64] FI
DEST[VLMAX-1:128] (Unmodified)
```
#### VBLENDVPD (VEX.128 encoded version)
```info-verb
MASK <-  SRC3
IF (MASK[63] = 0) THEN DEST[63:0] <-  SRC1[63:0]
          ELSE DEST [63:0] <-  SRC2[63:0] FI
IF (MASK[127] = 0) THEN DEST[127:64] <-  SRC1[127:64]
          ELSE DEST [127:64] <-  SRC2[127:64] FI
DEST[VLMAX-1:128] <-  0
```
#### VBLENDVPD (VEX.256 encoded version)
```info-verb
MASK <-  SRC3
IF (MASK[63] = 0) THEN DEST[63:0] <-  SRC1[63:0]
          ELSE DEST [63:0] <-  SRC2[63:0] FI
IF (MASK[127] = 0) THEN DEST[127:64] <-  SRC1[127:64]
          ELSE DEST [127:64] <-  SRC2[127:64] FI
IF (MASK[191] = 0) THEN DEST[191:128] <-  SRC1[191:128]
          ELSE DEST [191:128] <-  SRC2[191:128] FI
IF (MASK[255] = 0) THEN DEST[255:192] <-  SRC1[255:192]
          ELSE DEST [255:192] <-  SRC2[255:192] FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BLENDVPD: __m128d _mm_blendv_pd(__m128d v1, __m128d v2, __m128d v3);
VBLENDVPD: __m128 _mm_blendv_pd (__m128d a, __m128d b, __m128d mask);
VBLENDVPD: __m256 _mm256_blendv_pd (__m256d a, __m256d b, __m256d mask);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4; additionally

#UD  If VEX.W = 1.

