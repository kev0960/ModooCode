----------------------------
title : VTESTPD, VTESTPSs (Intel x86/64 assembly instruction)
cat_title : VTESTPD, VTESTPS
ref_title : VTESTPD, VTESTPS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/V
publish_date: 2020-09-01
----------------------------


#@ VTESTPD, VTESTPS

**Packed Bit Test**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.128.66.0F38.W0 0E /r`\newline{}`VTESTPS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Set ZF and CF depending on sign bit AND and ANDN of packed single-precision floating-point sources.|
|`VEX.256.66.0F38.W0 0E /r`\newline{}`VTESTPS` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX|Set ZF and CF depending on sign bit AND and ANDN of packed single-precision floating-point sources.|
|`VEX.128.66.0F38.W0 0F /r`\newline{}`VTESTPD` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|AVX|Set ZF and CF depending on sign bit AND and ANDN of packed double-precision floating-point sources.|
|`VEX.256.66.0F38.W0 0F /r`\newline{}`VTESTPD` \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RM|V/V|AVX|Set ZF and CF depending on sign bit AND and ANDN of packed double-precision floating-point sources.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r)|ModRM:r/m (r)|NA|NA|
### Description


VTESTPS performs a bitwise comparison of all the sign bits of the packed single-precision elements in the first source operation and corresponding sign bits in the second source operand. If the `AND` of the source sign bits with the dest sign bits produces all zeros, the ZF is set else the ZF is clear. If the `AND` of the source sign bits with the inverted dest sign bits produces all zeros the CF is set else the CF is clear. An attempt to execute `VTESTPS` with VEX.W=1 will cause #UD.

VTESTPD performs a bitwise comparison of all the sign bits of the double-precision elements in the first source operation and corresponding sign bits in the second source operand. If the `AND` of the source sign bits with the dest sign bits produces all zeros, the ZF is set else the ZF is clear. If the `AND` the source sign bits with the inverted dest sign bits produces all zeros the CF is set else the CF is clear. An attempt to execute `VTESTPS` with VEX.W=1 will cause #UD.

The first source register is specified by the ModR/M reg field.

128-bit version: The first source register is an XMM register. The second source register can be an XMM register or a 128-bit memory location. The destination register is not modified.

VEX.256 encoded version: The first source register is a YMM register. The second source register can be a YMM register or a 256-bit memory location. The destination register is not modified.

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### VTESTPS (128-bit version)
```info-verb
TEMP[127:0] <-  SRC[127:0] AND DEST[127:0]
IF (TEMP[31] = TEMP[63] = TEMP[95] = TEMP[127] = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
TEMP[127:0] <-  SRC[127:0] AND NOT DEST[127:0]
IF (TEMP[31] = TEMP[63] = TEMP[95] = TEMP[127] = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
DEST (unmodified)
AF <-  OF <-  PF <-  SF <-  0;
```
#### VTESTPS (VEX.256 encoded version)
```info-verb
TEMP[255:0] <-  SRC[255:0] AND DEST[255:0]
IF (TEMP[31] = TEMP[63] = TEMP[95] = TEMP[127]= TEMP[160] =TEMP[191] = TEMP[224] = TEMP[255] = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
TEMP[255:0] <-  SRC[255:0] AND NOT DEST[255:0]
IF (TEMP[31] = TEMP[63] = TEMP[95] = TEMP[127]= TEMP[160] =TEMP[191] = TEMP[224] = TEMP[255] = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
DEST (unmodified)
AF <-  OF <-  PF <-  SF <-  0;
```
#### VTESTPD (128-bit version)
```info-verb
TEMP[127:0] <-  SRC[127:0] AND DEST[127:0]
IF ( TEMP[63] = TEMP[127] = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
TEMP[127:0] <-  SRC[127:0] AND NOT DEST[127:0]
IF ( TEMP[63] = TEMP[127] = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
DEST (unmodified)
AF <-  OF <-  PF <-  SF <-  0;
```
#### VTESTPD (VEX.256 encoded version)
```info-verb
TEMP[255:0] <-  SRC[255:0] AND DEST[255:0]
IF (TEMP[63] = TEMP[127] = TEMP[191] = TEMP[255] = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
TEMP[255:0] <-  SRC[255:0] AND NOT DEST[255:0]
IF (TEMP[63] = TEMP[127] = TEMP[191] = TEMP[255] = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
DEST (unmodified)
AF <-  OF <-  PF <-  SF <-  0;
```

### Intel C/C++ Compiler Intrinsic Equivalent
#### VTESTPS
```cpp
    int _mm256_testz_ps (__m256 s1, __m256 s2);
    int _mm256_testc_ps (__m256 s1, __m256 s2);
    int _mm256_testnzc_ps (__m256 s1, __m128 s2);
    int _mm_testz_ps (__m128 s1, __m128 s2);
    int _mm_testc_ps (__m128 s1, __m128 s2);
    int _mm_testnzc_ps (__m128 s1, __m128 s2);
```
#### VTESTPD
```cpp
    int _mm256_testz_pd (__m256d s1, __m256d s2);
    int _mm256_testc_pd (__m256d s1, __m256d s2);
    int _mm256_testnzc_pd (__m256d s1, __m256d s2);
    int _mm_testz_pd (__m128d s1, __m128d s2);
    int _mm_testc_pd (__m128d s1, __m128d s2);
    int _mm_testnzc_pd (__m128d s1, __m128d s2);
```
### Flags Affected


The 0F, AF, PF, SF flags are cleared and the ZF, CF flags are set according to the operation.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.vvvv ->  1111B.

                              If VEX.W = 1 for VTESTPS or VTESTPD.

