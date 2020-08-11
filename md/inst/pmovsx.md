----------------------------
title : PMOVSX (Intel x86/64 assembly instruction)
cat_title : PMOVSX
ref_title : PMOVSX
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PMOVSX

**Packed Move with Sign Extend **

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0f 38 20 /rPMOVSXBW xmm1, xmm2/m64|RM|V/V|SSE4_1|Sign extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 16-bit integers in xmm1.|
|66 0f 38 21 /rPMOVSXBD xmm1, xmm2/m32|RM|V/V|SSE4_1|Sign extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 32-bit integers in xmm1.|
|66 0f 38 22 /rPMOVSXBQ xmm1, xmm2/m16|RM|V/V|SSE4_1|Sign extend 2 packed 8-bit integers in the low 2 bytes of xmm2/m16 to 2 packed 64-bit integers in xmm1.|
|66 0f 38 23/rPMOVSXWD xmm1, xmm2/m64|RM|V/V|SSE4_1|Sign extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 32-bit integers in xmm1.|
|66 0f 38 24 /rPMOVSXWQ xmm1, xmm2/m32|RM|V/V|SSE4_1|Sign extend 2 packed 16-bit integers in the low 4 bytes of xmm2/m32 to 2 packed 64-bit integers in xmm1.|
|66 0f 38 25 /rPMOVSXDQ xmm1, xmm2/m64|RM|V/V|SSE4_1|Sign extend 2 packed 32-bit integers in the low 8 bytes of xmm2/m64 to 2 packed 64-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 20 /rVPMOVSXBW xmm1, xmm2/m64|RM|V/V|AVX|Sign extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 16-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 21 /rVPMOVSXBD xmm1, xmm2/m32|RM|V/V|AVX|Sign extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 32-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 22 /rVPMOVSXBQ xmm1, xmm2/m16|RM|V/V|AVX|Sign extend 2 packed 8-bit integers in the low 2 bytes of xmm2/m16 to 2 packed 64-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 23 /rVPMOVSXWD xmm1, xmm2/m64|RM|V/V|AVX|Sign extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 32-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 24 /rVPMOVSXWQ xmm1, xmm2/m32|RM|V/V|AVX|Sign extend 2 packed 16-bit integers in the low 4 bytes of xmm2/m32 to 2 packed 64-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 25 /rVPMOVSXDQ xmm1, xmm2/m64|RM|V/V|AVX|Sign extend 2 packed 32-bit integers in the low 8 bytes of xmm2/m64 to 2 packed 64-bit integers in xmm1.|
|VEX.256.66.0F38.WIG 20 /rVPMOVSXBW ymm1, xmm2/m128|RM|V/V|AVX2|Sign extend 16 packed 8-bit integers in xmm2/m128 to 16 packed 16-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 21 /rVPMOVSXBD ymm1, xmm2/m64|RM|V/V|AVX2|Sign extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 32-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 22 /rVPMOVSXBQ ymm1, xmm2/m32|RM|V/V|AVX2|Sign extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 64-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 23 /rVPMOVSXWD ymm1, xmm2/m128|RM|V/V|AVX2|Sign extend 8 packed 16-bit integers in the low 16 bytes of xmm2/m128 to 8 packed 32-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 24 /rVPMOVSXWQ ymm1, xmm2/m64|RM|V/V|AVX2|Sign extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 64-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 25 /rVPMOVSXDQ ymm1, xmm2/m128|RM|V/V|AVX2|Sign extend 4 packed 32-bit integers in the low 16 bytes of xmm2/m128 to 4 packed 64-bit integers in ymm1.|
|EVEX.128.66.0F38.WIG 20 /rVPMOVSXBW xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512BW|Sign extend 8 packed 8-bit integers in xmm2/m64 to 8 packed 16-bit integers in zmm1.|
|EVEX.256.66.0F38.WIG 20 /rVPMOVSXBW ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512BW|Sign extend 16 packed 8-bit integers in xmm2/m128 to 16 packed 16-bit integers in ymm1.|
|EVEX.512.66.0F38.WIG 20 /rVPMOVSXBW zmm1 {k1}{z}, ymm2/m256|HVM|V/V|AVX512BW|Sign extend 32 packed 8-bit integers in ymm2/m256 to 32 packed 16-bit integers in zmm1.|
|EVEX.128.66.0F38.WIG 21 /rVPMOVSXBD xmm1 {k1}{z}, xmm2/m32|QVM|V/V|AVX512VLAVX512F|Sign extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 32-bit integers in xmm1 subject to writemask k1.|


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.256.66.0F38.WIG 21 /rVPMOVSXBD ymm1 {k1}{z}, xmm2/m64|QVM|V/V|AVX512VLAVX512F|Sign extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 32-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 21 /rVPMOVSXBD zmm1 {k1}{z}, xmm2/m128|QVM|V/V|AVX512F|Sign extend 16 packed 8-bit integers in the low 16 bytes of xmm2/m128 to 16 packed 32-bit integers in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.WIG 22 /rVPMOVSXBQ xmm1 {k1}{z}, xmm2/m16|OVM|V/V|AVX512VLAVX512F|Sign extend 2 packed 8-bit integers in the low 2 bytes of xmm2/m16 to 2 packed 64-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 22 /rVPMOVSXBQ ymm1 {k1}{z}, xmm2/m32|OVM|V/V|AVX512VLAVX512F|Sign extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 64-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 22 /rVPMOVSXBQ zmm1 {k1}{z}, xmm2/m64|OVM|V/V|AVX512F|Sign extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 64-bit integers in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.WIG 23 /rVPMOVSXWD xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512F|Sign extend 4 packed 16-bit integers in the low 8 bytes of ymm2/mem to 4 packed 32-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 23 /rVPMOVSXWD ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512F|Sign extend 8 packed 16-bit integers in the low 16 bytes of ymm2/m128 to 8 packed 32-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 23 /rVPMOVSXWD zmm1 {k1}{z}, ymm2/m256|HVM|V/V|AVX512F|Sign extend 16 packed 16-bit integers in the low 32 bytes of ymm2/m256 to 16 packed 32-bit integers in zmm1 subject to writemask k1. |
|EVEX.128.66.0F38.WIG 24 /rVPMOVSXWQ xmm1 {k1}{z}, xmm2/m32|QVM|V/V|AVX512VLAVX512F|Sign extend 2 packed 16-bit integers in the low 4 bytes of xmm2/m32 to 2 packed 64-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 24 /rVPMOVSXWQ ymm1 {k1}{z}, xmm2/m64|QVM|V/V|AVX512VLAVX512F|Sign extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 64-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 24 /rVPMOVSXWQ zmm1 {k1}{z}, xmm2/m128|QVM|V/V|AVX512F|Sign extend 8 packed 16-bit integers in the low 16 bytes of xmm2/m128 to 8 packed 64-bit integers in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.W0 25 /rVPMOVSXDQ xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512F|Sign extend 2 packed 32-bit integers in the low 8 bytes of xmm2/m64 to 2 packed 64-bit integers in zmm1 using writemask k1.|
|EVEX.256.66.0F38.W0 25 /rVPMOVSXDQ ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512F|Sign extend 4 packed 32-bit integers in the low 16 bytes of xmm2/m128 to 4 packed 64-bit integers in zmm1 using writemask k1.|
|EVEX.512.66.0F38.W0 25 /rVPMOVSXDQ zmm1 {k1}{z}, ymm2/m256|HVM|V/V|AVX512F|Sign extend 8 packed 32-bit integers in the low 32 bytes of ymm2/m256 to 8 packed 64-bit integers in zmm1 using writemask k1. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|HVM, QVM, OVM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Legacy and VEX encoded versions: Packed byte, word, or dword integers in the low bytes of the source operand (second operand) are sign extended to word, dword, or quadword integers and stored in packed signed bytes the destination operand.

128-bit Legacy SSE version: Bits (MAX_VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 and EVEX.128 encoded versions: Bits (MAX_VL-1:128) of the corresponding destination register are zeroed.

VEX.256 and EVEX.256 encoded versions: Bits (MAX_VL-1:256) of the corresponding destination register are zeroed. 

EVEX encoded versions: Packed byte, word or dword integers starting from the low bytes of the source operand (second operand) are sign extended to word, dword or quadword integers and stored to the destination operand under the writemask. The destination register is XMM, YMM or ZMM Register.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### Packed_Sign_Extend_BYTE_to_WORD(DEST, SRC)
```info-verb
DEST[15:0] <- SignExtend(SRC[7:0]);
DEST[31:16] <- SignExtend(SRC[15:8]);
DEST[47:32]  <-SignExtend(SRC[23:16]);
DEST[63:48]  <-SignExtend(SRC[31:24]);
DEST[79:64]  <-SignExtend(SRC[39:32]);
DEST[95:80] <- SignExtend(SRC[47:40]);
DEST[111:96] <- SignExtend(SRC[55:48]);
DEST[127:112]  <-SignExtend(SRC[63:56]);
```
#### Packed_Sign_Extend_BYTE_to_DWORD(DEST, SRC)
```info-verb
DEST[31:0]  <-SignExtend(SRC[7:0]);
DEST[63:32]  <-SignExtend(SRC[15:8]);
DEST[95:64] <- SignExtend(SRC[23:16]);
DEST[127:96]  <-SignExtend(SRC[31:24]);
```
#### Packed_Sign_Extend_BYTE_to_QWORD(DEST, SRC)
```info-verb
DEST[63:0] <- SignExtend(SRC[7:0]);
DEST[127:64]  <-SignExtend(SRC[15:8]);
```
#### Packed_Sign_Extend_WORD_to_DWORD(DEST, SRC)
```info-verb
DEST[31:0]  <-SignExtend(SRC[15:0]);
DEST[63:32] <- SignExtend(SRC[31:16]);
DEST[95:64]  <-SignExtend(SRC[47:32]);
DEST[127:96] <- SignExtend(SRC[63:48]);
```
#### Packed_Sign_Extend_WORD_to_QWORD(DEST, SRC)
```info-verb
DEST[63:0] <- SignExtend(SRC[15:0]);
DEST[127:64] <- SignExtend(SRC[31:16]);
```
#### Packed_Sign_Extend_DWORD_to_QWORD(DEST, SRC)
```info-verb
DEST[63:0]  <-SignExtend(SRC[31:0]);
DEST[127:64] <- SignExtend(SRC[63:32]);
```
#### VPMOVSXBW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
Packed_Sign_Extend_BYTE_to_WORD(TMP_DEST[127:0], SRC[63:0])
IF VL >= 256
 Packed_Sign_Extend_BYTE_to_WORD(TMP_DEST[255:128], SRC[127:64])
FI;
IF VL >= 512
 Packed_Sign_Extend_BYTE_to_WORD(TMP_DEST[383:256], SRC[191:128])
 Packed_Sign_Extend_BYTE_to_WORD(TMP_DEST[511:384], SRC[255:192])
FI;
FOR j  <- 0 TO KL-1
 i  <- j * 16
 IF k1[j] OR *no writemask*
   THEN DEST[i+15:i] <-  TEMP_DEST[i+15:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+15:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+15:i]  <- 0
FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VPMOVSXBD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
Packed_Sign_Extend_BYTE_to_DWORD(TMP_DEST[127:0], SRC[31:0])
IF VL >= 256
 Packed_Sign_Extend_BYTE_to_DWORD(TMP_DEST[255:128], SRC[63:32])
FI;
IF VL >= 512
 Packed_Sign_Extend_BYTE_to_DWORD(TMP_DEST[383:256], SRC[95:64])
 Packed_Sign_Extend_BYTE_to_DWORD(TMP_DEST[511:384], SRC[127:96])
FI;
FOR j  <- 0 TO KL-1
 i <-  j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i]  <- TEMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VPMOVSXBQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
Packed_Sign_Extend_BYTE_to_QWORD(TMP_DEST[127:0], SRC[15:0])
IF VL >= 256
 Packed_Sign_Extend_BYTE_to_QWORD(TMP_DEST[255:128], SRC[31:16])
FI;
IF VL >= 512
 Packed_Sign_Extend_BYTE_to_QWORD(TMP_DEST[383:256], SRC[47:32])
 Packed_Sign_Extend_BYTE_to_QWORD(TMP_DEST[511:384], SRC[63:48])
FI;
FOR j  <- 0 TO KL-1
 i  <- j * 64
 IF k1[j] OR *no writemask*
   THEN DEST[i+63:i] <-  TEMP_DEST[i+63:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+63:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VPMOVSXWD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
Packed_Sign_Extend_WORD_to_DWORD(TMP_DEST[127:0], SRC[63:0])
IF VL >= 256
 Packed_Sign_Extend_WORD_to_DWORD(TMP_DEST[255:128], SRC[127:64])
FI;
IF VL >= 512
 Packed_Sign_Extend_WORD_to_DWORD(TMP_DEST[383:256], SRC[191:128])
 Packed_Sign_Extend_WORD_to_DWORD(TMP_DEST[511:384], SRC[256:192])
FI;
FOR j <-  0 TO KL-1
 i <-  j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i] <-  TEMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL] <-  0
```
#### VPMOVSXWQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
Packed_Sign_Extend_WORD_to_QWORD(TMP_DEST[127:0], SRC[31:0])
IF VL >= 256
 Packed_Sign_Extend_WORD_to_QWORD(TMP_DEST[255:128], SRC[63:32])
FI;
IF VL >= 512
 Packed_Sign_Extend_WORD_to_QWORD(TMP_DEST[383:256], SRC[95:64])
 Packed_Sign_Extend_WORD_to_QWORD(TMP_DEST[511:384], SRC[127:96])
FI;
FOR j <-  0 TO KL-1
 i  <- j * 64
 IF k1[j] OR *no writemask*
   THEN DEST[i+63:i]  <- TEMP_DEST[i+63:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+63:i]  <- 0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VPMOVSXDQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
Packed_Sign_Extend_DWORD_to_QWORD(TEMP_DEST[127:0], SRC[63:0])
IF VL >= 256
 Packed_Sign_Extend_DWORD_to_QWORD(TEMP_DEST[255:128], SRC[127:64])
FI;
IF VL >= 512
 Packed_Sign_Extend_DWORD_to_QWORD(TEMP_DEST[383:256], SRC[191:128])
 Packed_Sign_Extend_DWORD_to_QWORD(TEMP_DEST[511:384], SRC[255:192])
FI;
FOR j  <- 0 TO KL-1
 i <-  j * 64
 IF k1[j] OR *no writemask*
   THEN DEST[i+63:i]  <- TEMP_DEST[i+63:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+63:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+63:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0
```
#### VPMOVSXBW (VEX.256 encoded version)
```info-verb
Packed_Sign_Extend_BYTE_to_WORD(DEST[127:0], SRC[63:0])
Packed_Sign_Extend_BYTE_to_WORD(DEST[255:128], SRC[127:64])
DEST[MAX_VL-1:256] <-  0
```
#### VPMOVSXBD (VEX.256 encoded version)
```info-verb
Packed_Sign_Extend_BYTE_to_DWORD(DEST[127:0], SRC[31:0])
Packed_Sign_Extend_BYTE_to_DWORD(DEST[255:128], SRC[63:32])
DEST[MAX_VL-1:256] <-  0
```
#### VPMOVSXBQ (VEX.256 encoded version)
```info-verb
Packed_Sign_Extend_BYTE_to_QWORD(DEST[127:0], SRC[15:0])
Packed_Sign_Extend_BYTE_to_QWORD(DEST[255:128], SRC[31:16])
DEST[MAX_VL-1:256] <-  0
```
#### VPMOVSXWD (VEX.256 encoded version)
```info-verb
Packed_Sign_Extend_WORD_to_DWORD(DEST[127:0], SRC[63:0])
Packed_Sign_Extend_WORD_to_DWORD(DEST[255:128], SRC[127:64])
DEST[MAX_VL-1:256] <-  0
```
#### VPMOVSXWQ (VEX.256 encoded version)
```info-verb
Packed_Sign_Extend_WORD_to_QWORD(DEST[127:0], SRC[31:0])
Packed_Sign_Extend_WORD_to_QWORD(DEST[255:128], SRC[63:32])
DEST[MAX_VL-1:256]  <- 0
```
#### VPMOVSXDQ (VEX.256 encoded version)
```info-verb
Packed_Sign_Extend_DWORD_to_QWORD(DEST[127:0], SRC[63:0])
Packed_Sign_Extend_DWORD_to_QWORD(DEST[255:128], SRC[127:64])
DEST[MAX_VL-1:256] <-  0
```
#### VPMOVSXBW (VEX.128 encoded version)
```info-verb
Packed_Sign_Extend_BYTE_to_WORDDEST[127:0], SRC[127:0]()
DEST[MAX_VL-1:128]  <-0
```
#### VPMOVSXBD (VEX.128 encoded version)
```info-verb
Packed_Sign_Extend_BYTE_to_DWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128]  <-0
```
#### VPMOVSXBQ (VEX.128 encoded version)
```info-verb
Packed_Sign_Extend_BYTE_to_QWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128]  <-0
```
#### VPMOVSXWD (VEX.128 encoded version)
```info-verb
Packed_Sign_Extend_WORD_to_DWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] <- 0
```
#### VPMOVSXWQ (VEX.128 encoded version)
```info-verb
Packed_Sign_Extend_WORD_to_QWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] <- 0
```
#### VPMOVSXDQ (VEX.128 encoded version)
```info-verb
Packed_Sign_Extend_DWORD_to_QWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128]  <-0
```
#### PMOVSXBW
```info-verb
Packed_Sign_Extend_BYTE_to_WORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVSXBD
```info-verb
Packed_Sign_Extend_BYTE_to_DWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVSXBQ
```info-verb
Packed_Sign_Extend_BYTE_to_QWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVSXWD
```info-verb
Packed_Sign_Extend_WORD_to_DWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVSXWQ
```info-verb
Packed_Sign_Extend_WORD_to_QWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVSXDQ
```info-verb
Packed_Sign_Extend_DWORD_to_QWORD(DEST[127:0], SRC[127:0])
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMOVSXBW __m512i _mm512_cvtepi8_epi16(__m512i a);
VPMOVSXBW __m512i _mm512_mask_cvtepi8_epi16(__m512i a, __mmask32 k, __m512i b);
VPMOVSXBW __m512i _mm512_maskz_cvtepi8_epi16( __mmask32 k, __m512i b);
VPMOVSXBD __m512i _mm512_cvtepi8_epi32(__m512i a);
VPMOVSXBD __m512i _mm512_mask_cvtepi8_epi32(__m512i a, __mmask16 k, __m512i b);
VPMOVSXBD __m512i _mm512_maskz_cvtepi8_epi32( __mmask16 k, __m512i b);
VPMOVSXBQ __m512i _mm512_cvtepi8_epi64(__m512i a);
VPMOVSXBQ __m512i _mm512_mask_cvtepi8_epi64(__m512i a, __mmask8 k, __m512i b);
VPMOVSXBQ __m512i _mm512_maskz_cvtepi8_epi64( __mmask8 k, __m512i a);
VPMOVSXDQ __m512i _mm512_cvtepi32_epi64(__m512i a);
VPMOVSXDQ __m512i _mm512_mask_cvtepi32_epi64(__m512i a, __mmask8 k, __m512i b);
VPMOVSXDQ __m512i _mm512_maskz_cvtepi32_epi64( __mmask8 k, __m512i a);
VPMOVSXWD __m512i _mm512_cvtepi16_epi32(__m512i a);
VPMOVSXWD __m512i _mm512_mask_cvtepi16_epi32(__m512i a, __mmask16 k, __m512i b);
VPMOVSXWD __m512i _mm512_maskz_cvtepi16_epi32(__mmask16 k, __m512i a);
VPMOVSXWQ __m512i _mm512_cvtepi16_epi64(__m512i a);
VPMOVSXWQ __m512i _mm512_mask_cvtepi16_epi64(__m512i a, __mmask8 k, __m512i b);
VPMOVSXWQ __m512i _mm512_maskz_cvtepi16_epi64( __mmask8 k, __m512i a);
VPMOVSXBW __m256i _mm256_cvtepi8_epi16(__m256i a);
VPMOVSXBW __m256i  _mm256_mask_cvtepi8_epi16(__m256i a, __mmask16 k, __m256i b);
VPMOVSXBW __m256i _mm256_maskz_cvtepi8_epi16( __mmask16 k, __m256i b);
VPMOVSXBD __m256i _mm256_cvtepi8_epi32(__m256i a);
VPMOVSXBD __m256i _mm256_mask_cvtepi8_epi32(__m256i a, __mmask8 k, __m256i b);
VPMOVSXBD __m256i _mm256_maskz_cvtepi8_epi32( __mmask8 k, __m256i b);
VPMOVSXBQ __m256i _mm256_cvtepi8_epi64(__m256i a);
VPMOVSXBQ __m256i _mm256_mask_cvtepi8_epi64(__m256i a, __mmask8 k, __m256i b);
VPMOVSXBQ __m256i _mm256_maskz_cvtepi8_epi64( __mmask8 k, __m256i a);
VPMOVSXDQ __m256i _mm256_cvtepi32_epi64(__m256i a);
VPMOVSXDQ __m256i _mm256_mask_cvtepi32_epi64(__m256i a, __mmask8 k, __m256i b);
VPMOVSXDQ __m256i _mm256_maskz_cvtepi32_epi64( __mmask8 k, __m256i a);
VPMOVSXWD __m256i _mm256_cvtepi16_epi32(__m256i a);
VPMOVSXWD __m256i _mm256_mask_cvtepi16_epi32(__m256i a, __mmask16 k, __m256i b);
VPMOVSXWD __m256i _mm256_maskz_cvtepi16_epi32(__mmask16 k, __m256i a);
VPMOVSXWQ __m256i _mm256_cvtepi16_epi64(__m256i a);
VPMOVSXWQ __m256i _mm256_mask_cvtepi16_epi64(__m256i a, __mmask8 k, __m256i b);
VPMOVSXWQ __m256i _mm256_maskz_cvtepi16_epi64( __mmask8 k, __m256i a);
VPMOVSXBW __m128i  _mm_mask_cvtepi8_epi16(__m128i a, __mmask8 k, __m128i b);
VPMOVSXBW __m128i _mm_maskz_cvtepi8_epi16( __mmask8 k, __m128i b);
VPMOVSXBD __m128i _mm_mask_cvtepi8_epi32(__m128i a, __mmask8 k, __m128i b);
VPMOVSXBD __m128i _mm_maskz_cvtepi8_epi32( __mmask8 k, __m128i b);
VPMOVSXBQ __m128i _mm_mask_cvtepi8_epi64(__m128i a, __mmask8 k, __m128i b);
VPMOVSXBQ __m128i _mm_maskz_cvtepi8_epi64( __mmask8 k, __m128i a);
VPMOVSXDQ __m128i _mm_mask_cvtepi32_epi64(__m128i a, __mmask8 k, __m128i b);
VPMOVSXDQ __m128i _mm_maskz_cvtepi32_epi64( __mmask8 k, __m128i a);
VPMOVSXWD __m128i _mm_mask_cvtepi16_epi32(__m128i a, __mmask16 k, __m128i b);
VPMOVSXWD __m128i _mm_maskz_cvtepi16_epi32(__mmask16 k, __m128i a);
VPMOVSXWQ __m128i _mm_mask_cvtepi16_epi64(__m128i a, __mmask8 k, __m128i b);
VPMOVSXWQ __m128i _mm_maskz_cvtepi16_epi64( __mmask8 k, __m128i a);
PMOVSXBW __m128i _mm_ cvtepi8_epi16 ( __m128i a);
PMOVSXBD __m128i _mm_ cvtepi8_epi32 ( __m128i a);
PMOVSXBQ __m128i _mm_ cvtepi8_epi64 ( __m128i a);
PMOVSXWD __m128i _mm_ cvtepi16_epi32 ( __m128i a);
PMOVSXWQ __m128i _mm_ cvtepi16_epi64 ( __m128i a);
PMOVSXDQ __m128i _mm_ cvtepi32_epi64 ( __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5.

EVEX-encoded instruction, see Exceptions Type E5.

#UD  If VEX.vvvv != 1111B, or EVEX.vvvv != 1111B.

