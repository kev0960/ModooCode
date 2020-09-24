----------------------------
title : MOVMSKPD (Intel x86/64 assembly instruction)
cat_title : MOVMSKPD
ref_title : MOVMSKPD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVMSKPD

**Extract Packed Double-Precision Floating-Point Sign Mask**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`66 0F 50 /r`\newline{}`MOVMSKPD` reg \tooltip{xmm}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |RM|V/V|SSE2|Extract 2-bit sign mask from xmm and store in reg. The upper bits of r32 or r64 are filled with zeros.|
|`VEX.128.66.0F.WIG 50 /r`\newline{}VMOVMSKPD reg \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} |RM|V/V|AVX|Extract 2-bit sign mask from xmm2 and store in reg. The upper bits of r32 or r64 are zeroed.|
|`VEX.256.66.0F.WIG 50 /r`\newline{}VMOVMSKPD reg \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} |RM|V/V|AVX|Extract 4-bit sign mask from ymm2 and store in reg. The upper bits of r32 or r64 are zeroed.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Extracts the sign bits from the packed double-precision floating-point values in the source operand (second operand), formats them into a 2-bit mask, and stores the mask in the destination operand (first operand). The source operand is an XMM register, and the destination operand is a general-purpose register. The mask is stored in the 2 low-order bits of the destination operand. Zero-extend the upper bits of the destination.

In 64-bit mode, the instruction can access additional registers (XMM8-XMM15, R8-R15) when used with a REX.R prefix. The default operand size is 64-bit in 64-bit mode.

128-bit versions: The source operand is a YMM register. The destination operand is a general purpose register.

VEX.256 encoded version: The source operand is a YMM register. The destination operand is a general purpose register. 

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### (V)MOVMSKPD (128-bit versions)
```info-verb
DEST[0] <-  SRC[63]
DEST[1] <-  SRC[127]
IF DEST = r32
    THEN DEST[31:2] <-  0;
    ELSE DEST[63:2] <-  0;
FI
```
#### VMOVMSKPD (VEX.256 encoded version)
```info-verb
DEST[0] <-  SRC[63]
DEST[1] <-  SRC[127]
DEST[2] <-  SRC[191]
DEST[3] <-  SRC[255]
IF DEST = r32
    THEN DEST[31:4] <-  0;
    ELSE DEST[63:4] <-  0;
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
MOVMSKPD: int _mm_movemask_pd ( __m128d a)
VMOVMSKPD: _mm256_movemask_pd(__m256d a)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 7; additionally

#UD  If VEX.vvvv ->  1111B.

