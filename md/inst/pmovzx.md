----------------------------
title : PMOVZX (Intel x86/64 assembly instruction)
cat_title : PMOVZX
ref_title : PMOVZX
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PMOVZX

**Packed Move with Zero Extend **

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0f 38 30 /r\newline{}PMOVZXBW xmm1, xmm2/m64|RM|V/V|SSE4_1|Zero extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 16-bit integers in xmm1.|
|66 0f 38 31 /r\newline{}PMOVZXBD xmm1, xmm2/m32|RM|V/V|SSE4_1|Zero extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 32-bit integers in xmm1.|
|66 0f 38 32 /r\newline{}PMOVZXBQ xmm1, xmm2/m16|RM|V/V|SSE4_1|Zero extend 2 packed 8-bit integers in the low 2 bytes of xmm2/m16 to 2 packed 64-bit integers in xmm1.|
|66 0f 38 33 /r\newline{}PMOVZXWD xmm1, xmm2/m64|RM|V/V|SSE4_1|Zero extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 32-bit integers in xmm1.|
|66 0f 38 34 /r\newline{}PMOVZXWQ xmm1, xmm2/m32|RM|V/V|SSE4_1|Zero extend 2 packed 16-bit integers in the low 4 bytes of xmm2/m32 to 2 packed 64-bit integers in xmm1.|
|66 0f 38 35 /r\newline{}PMOVZXDQ xmm1, xmm2/m64|RM|V/V|SSE4_1|Zero extend 2 packed 32-bit integers in the low 8 bytes of xmm2/m64 to 2 packed 64-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 30 /r\newline{}VPMOVZXBW xmm1, xmm2/m64|RM|V/V|AVX|Zero extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 16-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 31 /r\newline{}VPMOVZXBD xmm1, xmm2/m32|RM|V/V|AVX|Zero extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 32-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 32 /r\newline{}VPMOVZXBQ xmm1, xmm2/m16|RM|V/V|AVX|Zero extend 2 packed 8-bit integers in the low 2 bytes of xmm2/m16 to 2 packed 64-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 33 /r\newline{}VPMOVZXWD xmm1, xmm2/m64|RM|V/V|AVX|Zero extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 32-bit integers in xmm1.|
|VEX.128.66.0F38.WIG 34 /r\newline{}VPMOVZXWQ xmm1, xmm2/m32|RM|V/V|AVX|Zero extend 2 packed 16-bit integers in the low 4 bytes of xmm2/m32 to 2 packed 64-bit integers in xmm1.|
|VEX.128.66.0F 38.WIG 35 /r\newline{}VPMOVZXDQ xmm1, xmm2/m64|RM|V/V|AVX|Zero extend 2 packed 32-bit integers in the low 8 bytes of xmm2/m64 to 2 packed 64-bit integers in xmm1.|
|VEX.256.66.0F38.WIG 30 /r\newline{}VPMOVZXBW ymm1, xmm2/m128|RM|V/V|AVX2|Zero extend 16 packed 8-bit integers in xmm2/m128 to 16 packed 16-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 31 /r\newline{}VPMOVZXBD ymm1, xmm2/m64|RM|V/V|AVX2|Zero extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 32-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 32 /r\newline{}VPMOVZXBQ ymm1, xmm2/m32|RM|V/V|AVX2|Zero extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 64-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 33 /r\newline{}VPMOVZXWD ymm1, xmm2/m128|RM|V/V|AVX2|Zero extend 8 packed 16-bit integers xmm2/m128 to 8 packed 32-bit integers in ymm1.|
|VEX.256.66.0F38.WIG 34 /r\newline{}VPMOVZXWQ ymm1, xmm2/m64|RM|V/V|AVX2|Zero extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 64-bit integers in xmm1.|
|VEX.256.66.0F38.WIG 35 /r\newline{}VPMOVZXDQ ymm1, xmm2/m128|RM|V/V|AVX2|Zero extend 4 packed 32-bit integers in xmm2/m128 to 4 packed 64-bit integers in ymm1.|


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38 30.WIG /r\newline{}VPMOVZXBW xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512BW|Zero extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 16-bit integers in xmm1.|
|EVEX.256.66.0F38.WIG 30 /r\newline{}VPMOVZXBW ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512BW|Zero extend 16 packed 8-bit integers in xmm2/m128 to 16 packed 16-bit integers in ymm1.|
|EVEX.512.66.0F38.WIG 30 /r\newline{}VPMOVZXBW zmm1 {k1}{z}, ymm2/m256|HVM|V/V|AVX512BW|Zero extend 32 packed 8-bit integers in ymm2/m256 to 32 packed 16-bit integers in zmm1.|
|EVEX.128.66.0F38.WIG 31 /r\newline{}VPMOVZXBD xmm1 {k1}{z}, xmm2/m32|QVM|V/V|AVX512VLAVX512F|Zero extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 32-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 31 /r\newline{}VPMOVZXBD ymm1 {k1}{z}, xmm2/m64|QVM|V/V|AVX512VLAVX512F|Zero extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 32-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 31 /r\newline{}VPMOVZXBD zmm1 {k1}{z}, xmm2/m128|QVM|V/V|AVX512F|Zero extend 16 packed 8-bit integers in xmm2/m128 to 16 packed 32-bit integers in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.WIG 32 /r\newline{}VPMOVZXBQ xmm1 {k1}{z}, xmm2/m16|OVM|V/V|AVX512VLAVX512F|Zero extend 2 packed 8-bit integers in the low 2 bytes of xmm2/m16 to 2 packed 64-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 32 /r\newline{}VPMOVZXBQ ymm1 {k1}{z}, xmm2/m32|OVM|V/V|AVX512VLAVX512F|Zero extend 4 packed 8-bit integers in the low 4 bytes of xmm2/m32 to 4 packed 64-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 32 /r\newline{}VPMOVZXBQ zmm1 {k1}{z}, xmm2/m64|OVM|V/V|AVX512F|Zero extend 8 packed 8-bit integers in the low 8 bytes of xmm2/m64 to 8 packed 64-bit integers in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.WIG 33 /r\newline{}VPMOVZXWD xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512F|Zero extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 32-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 33 /r\newline{}VPMOVZXWD ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512F|Zero extend 8 packed 16-bit integers in xmm2/m128 to 8 packed 32-bit integers in zmm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 33 /r\newline{}VPMOVZXWD zmm1 {k1}{z}, ymm2/m256|HVM|V/V|AVX512F|Zero extend 16 packed 16-bit integers in ymm2/m256 to 16 packed 32-bit integers in zmm1 subject to writemask k1.|
|EVEX.128.66.0F38.WIG 34 /r\newline{}VPMOVZXWQ xmm1 {k1}{z}, xmm2/m32|QVM|V/V|AVX512VLAVX512F|Zero extend 2 packed 16-bit integers in the low 4 bytes of xmm2/m32 to 2 packed 64-bit integers in xmm1 subject to writemask k1.|
|EVEX.256.66.0F38.WIG 34 /r\newline{}VPMOVZXWQ ymm1 {k1}{z}, xmm2/m64|QVM|V/V|AVX512VLAVX512F|Zero extend 4 packed 16-bit integers in the low 8 bytes of xmm2/m64 to 4 packed 64-bit integers in ymm1 subject to writemask k1.|
|EVEX.512.66.0F38.WIG 34 /r\newline{}VPMOVZXWQ zmm1 {k1}{z}, xmm2/m128|QVM|V/V|AVX512F|Zero extend 8 packed 16-bit integers in xmm2/m128 to 8 packed 64-bit integers in zmm1 subject to writemask k1.|


|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|EVEX.128.66.0F38.W0 35 /r\newline{}VPMOVZXDQ xmm1 {k1}{z}, xmm2/m64|HVM|V/V|AVX512VLAVX512F|Zero extend 2 packed 32-bit integers in the low 8 bytes of xmm2/m64 to 2 packed 64-bit integers in zmm1 using writemask k1.|
|EVEX.256.66.0F38.W0 35 /r\newline{}VPMOVZXDQ ymm1 {k1}{z}, xmm2/m128|HVM|V/V|AVX512VLAVX512F|Zero extend 4 packed 32-bit integers in xmm2/m128 to 4 packed 64-bit integers in zmm1 using writemask k1.|
|EVEX.512.66.0F38.W0 35 /r\newline{}VPMOVZXDQ zmm1 {k1}{z}, ymm2/m256|HVM|V/V|AVX512F|Zero extend 8 packed 32-bit integers in ymm2/m256 to 8 packed 64-bit integers in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|HVM, QVM, OVM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Legacy, VEX and EVEX encoded versions: Packed byte, word, or dword integers starting from the low bytes of the source operand (second operand) are zero extended to word, dword, or quadword integers and stored in packed signed bytes the destination operand.

128-bit Legacy SSE version: Bits (MAX_VL-1:128) of the corresponding destination register remain unchanged.

VEX.128 encoded version: Bits (MAX_VL-1:128) of the corresponding destination register are zeroed.

VEX.256 encoded version: Bits (MAX_VL-1:256) of the corresponding destination register are zeroed. 

EVEX encoded versions: Packed dword integers starting from the low bytes of the source operand (second operand) are zero extended to quadword integers and stored to the destination operand under the writemask.The destination register is XMM, YMM or ZMM Register.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### Packed_Zero_Extend_BYTE_to_WORD(DEST, SRC)
```info-verb
DEST[15:0] <-  ZeroExtend(SRC[7:0]);
DEST[31:16] <-  ZeroExtend(SRC[15:8]);
DEST[47:32] <-  ZeroExtend(SRC[23:16]);
DEST[63:48]  <- ZeroExtend(SRC[31:24]);
DEST[79:64] <-  ZeroExtend(SRC[39:32]);
DEST[95:80]  <- ZeroExtend(SRC[47:40]);
DEST[111:96]  <- ZeroExtend(SRC[55:48]);
DEST[127:112]  <- ZeroExtend(SRC[63:56]);
Packed_Zero_Extend_BYTE_to_DWORD(DEST, SRC)
DEST[31:0] <-  ZeroExtend(SRC[7:0]);
DEST[63:32]  <- ZeroExtend(SRC[15:8]);
DEST[95:64]  <- ZeroExtend(SRC[23:16]);
DEST[127:96] <-  ZeroExtend(SRC[31:24]);
```
#### Packed_Zero_Extend_BYTE_to_QWORD(DEST, SRC)
```info-verb
DEST[63:0]  <- ZeroExtend(SRC[7:0]);
DEST[127:64]  <- ZeroExtend(SRC[15:8]);
```
#### Packed_Zero_Extend_WORD_to_DWORD(DEST, SRC)
```info-verb
DEST[31:0]  <- ZeroExtend(SRC[15:0]);
DEST[63:32] <-  ZeroExtend(SRC[31:16]);
DEST[95:64]  <- ZeroExtend(SRC[47:32]);
DEST[127:96]  <- ZeroExtend(SRC[63:48]);
```
#### Packed_Zero_Extend_WORD_to_QWORD(DEST, SRC)
```info-verb
DEST[63:0]  <- ZeroExtend(SRC[15:0]);
DEST[127:64] <-  ZeroExtend(SRC[31:16]);
```
#### Packed_Zero_Extend_DWORD_to_QWORD(DEST, SRC)
```info-verb
DEST[63:0] <-  ZeroExtend(SRC[31:0]);
DEST[127:64]  <- ZeroExtend(SRC[63:32]);
```
#### VPMOVZXBW (EVEX encoded versions)
```info-verb
(KL, VL) = (8, 128), (16, 256), (32, 512)
Packed_Zero_Extend_BYTE_to_WORD(TMP_DEST[127:0], SRC[63:0])
IF VL >= 256
    Packed_Zero_Extend_BYTE_to_WORD(TMP_DEST[255:128], SRC[127:64])
FI;
IF VL >= 512
    Packed_Zero_Extend_BYTE_to_WORD(TMP_DEST[383:256], SRC[191:128])
    Packed_Zero_Extend_BYTE_to_WORD(TMP_DEST[511:384], SRC[255:192])
FI;
FOR j <-   0 TO KL-1
    i  <-  j * 16
    IF k1[j] OR *no writemask*
          THEN DEST[i+15:i] <-   TEMP_DEST[i+15:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+15:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+15:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPMOVZXBD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
Packed_Zero_Extend_BYTE_to_DWORD(TMP_DEST[127:0], SRC[31:0])
IF VL >= 256
    Packed_Zero_Extend_BYTE_to_DWORD(TMP_DEST[255:128], SRC[63:32])
FI;
IF VL >= 512
    Packed_Zero_Extend_BYTE_to_DWORD(TMP_DEST[383:256], SRC[95:64])
    Packed_Zero_Extend_BYTE_to_DWORD(TMP_DEST[511:384], SRC[127:96])
FI;
FOR j  <-  0 TO KL-1
    i <-   j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i]  <-  TEMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPMOVZXBQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
Packed_Zero_Extend_BYTE_to_QWORD(TMP_DEST[127:0], SRC[15:0])
IF VL >= 256
    Packed_Zero_Extend_BYTE_to_QWORD(TMP_DEST[255:128], SRC[31:16])
FI;
IF VL >= 512
    Packed_Zero_Extend_BYTE_to_QWORD(TMP_DEST[383:256], SRC[47:32])
    Packed_Zero_Extend_BYTE_to_QWORD(TMP_DEST[511:384], SRC[63:48])
FI;
FOR j  <-  0 TO KL-1
    i  <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i]  <-  TEMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPMOVZXWD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
Packed_Zero_Extend_WORD_to_DWORD(TMP_DEST[127:0], SRC[63:0])
IF VL >= 256
    Packed_Zero_Extend_WORD_to_DWORD(TMP_DEST[255:128], SRC[127:64])
FI;
IF VL >= 512
    Packed_Zero_Extend_WORD_to_DWORD(TMP_DEST[383:256], SRC[191:128])
    Packed_Zero_Extend_WORD_to_DWORD(TMP_DEST[511:384], SRC[256:192])
FI;
FOR j  <-  0 TO KL-1
    i <-   j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-   TEMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+31:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPMOVZXWQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
Packed_Zero_Extend_WORD_to_QWORD(TMP_DEST[127:0], SRC[31:0])
IF VL >= 256
    Packed_Zero_Extend_WORD_to_QWORD(TMP_DEST[255:128], SRC[63:32])
FI;
IF VL >= 512
    Packed_Zero_Extend_WORD_to_QWORD(TMP_DEST[383:256], SRC[95:64])
    Packed_Zero_Extend_WORD_to_QWORD(TMP_DEST[511:384], SRC[127:96])
FI;
FOR j <-   0 TO KL-1
    i  <-  j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i] <-   TEMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL]  <-  0
```
#### VPMOVZXDQ (EVEX encoded versions)
```info-verb
(KL, VL) = (2, 128), (4, 256), (8, 512)
Packed_Zero_Extend_DWORD_to_QWORD(TEMP_DEST[127:0], SRC[63:0])
IF VL >= 256
    Packed_Zero_Extend_DWORD_to_QWORD(TEMP_DEST[255:128], SRC[127:64])
FI;
IF VL >= 512
    Packed_Zero_Extend_DWORD_to_QWORD(TEMP_DEST[383:256], SRC[191:128])
    Packed_Zero_Extend_DWORD_to_QWORD(TEMP_DEST[511:384], SRC[255:192])
FI;
FOR j  <-  0 TO KL-1
    i <-   j * 64
    IF k1[j] OR *no writemask*
          THEN DEST[i+63:i]  <-  TEMP_DEST[i+63:i]
          ELSE 
                IF *merging-masking* ; merging-masking
                      THEN *DEST[i+63:i] remains unchanged*
                      ELSE *zeroing-masking* ; zeroing-masking
                            DEST[i+63:i]  <-  0
                FI
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-   0
```
#### VPMOVZXBW (VEX.256 encoded version)
```info-verb
Packed_Zero_Extend_BYTE_to_WORD(DEST[127:0], SRC[63:0])
Packed_Zero_Extend_BYTE_to_WORD(DEST[255:128], SRC[127:64])
DEST[MAX_VL-1:256] <-   0
```
#### VPMOVZXBD (VEX.256 encoded version)
```info-verb
Packed_Zero_Extend_BYTE_to_DWORD(DEST[127:0], SRC[31:0])
Packed_Zero_Extend_BYTE_to_DWORD(DEST[255:128], SRC[63:32])
DEST[MAX_VL-1:256]  <-  0
```
#### VPMOVZXBQ (VEX.256 encoded version)
```info-verb
Packed_Zero_Extend_BYTE_to_QWORD(DEST[127:0], SRC[15:0])
Packed_Zero_Extend_BYTE_to_QWORD(DEST[255:128], SRC[31:16])
DEST[MAX_VL-1:256] <-   0
```
#### VPMOVZXWD (VEX.256 encoded version)
```info-verb
Packed_Zero_Extend_WORD_to_DWORD(DEST[127:0], SRC[63:0])
Packed_Zero_Extend_WORD_to_DWORD(DEST[255:128], SRC[127:64])
DEST[MAX_VL-1:256] <-   0
```
#### VPMOVZXWQ (VEX.256 encoded version)
```info-verb
Packed_Zero_Extend_WORD_to_QWORD(DEST[127:0], SRC[31:0])
Packed_Zero_Extend_WORD_to_QWORD(DEST[255:128], SRC[63:32])
DEST[MAX_VL-1:256] <-   0
```
#### VPMOVZXDQ (VEX.256 encoded version)
```info-verb
Packed_Zero_Extend_DWORD_to_QWORD(DEST[127:0], SRC[63:0])
Packed_Zero_Extend_DWORD_to_QWORD(DEST[255:128], SRC[127:64])
DEST[MAX_VL-1:256] <-   0
```
#### VPMOVZXBW (VEX.128 encoded version)
```info-verb
Packed_Zero_Extend_BYTE_to_WORD()
DEST[MAX_VL-1:128]  <- 0
```
#### VPMOVZXBD (VEX.128 encoded version)
```info-verb
Packed_Zero_Extend_BYTE_to_DWORD()
DEST[MAX_VL-1:128] <-  0
```
#### VPMOVZXBQ (VEX.128 encoded version)
```info-verb
Packed_Zero_Extend_BYTE_to_QWORD()
DEST[MAX_VL-1:128]  <- 0
```
#### VPMOVZXWD (VEX.128 encoded version)
```info-verb
Packed_Zero_Extend_WORD_to_DWORD()
DEST[MAX_VL-1:128]  <- 0
```
#### VPMOVZXWQ (VEX.128 encoded version)
```info-verb
Packed_Zero_Extend_WORD_to_QWORD()
DEST[MAX_VL-1:128] <-  0
```
#### VPMOVZXDQ (VEX.128 encoded version
```info-verb
)
Packed_Zero_Extend_DWORD_to_QWORD()
DEST[MAX_VL-1:128] <-  0
```
#### PMOVZXBW
```info-verb
Packed_Zero_Extend_BYTE_to_WORD()
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVZXBD
```info-verb
Packed_Zero_Extend_BYTE_to_DWORD()
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVZXBQ
```info-verb
Packed_Zero_Extend_BYTE_to_QWORD()
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVZXWD
```info-verb
Packed_Zero_Extend_WORD_to_DWORD()
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVZXWQ
```info-verb
Packed_Zero_Extend_WORD_to_QWORD()
DEST[MAX_VL-1:128] (Unmodified)
```
#### PMOVZXDQ
```info-verb
Packed_Zero_Extend_DWORD_to_QWORD()
DEST[MAX_VL-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPMOVZXBW __m512i _mm512_cvtepu8_epi16(__m256i a);
VPMOVZXBW __m512i _mm512_mask_cvtepu8_epi16(__m512i a, __mmask32 k, __m256i b);
VPMOVZXBW __m512i _mm512_maskz_cvtepu8_epi16( __mmask32 k, __m256i b);
VPMOVZXBD __m512i _mm512_cvtepu8_epi32(__m128i a);
VPMOVZXBD __m512i _mm512_mask_cvtepu8_epi32(__m512i a, __mmask16 k, __m128i b);
VPMOVZXBD __m512i _mm512_maskz_cvtepu8_epi32( __mmask16 k, __m128i b);
VPMOVZXBQ __m512i _mm512_cvtepu8_epi64(__m128i a);
VPMOVZXBQ __m512i _mm512_mask_cvtepu8_epi64(__m512i a, __mmask8 k, __m128i b);
VPMOVZXBQ __m512i _mm512_maskz_cvtepu8_epi64( __mmask8 k, __m128i a);
VPMOVZXDQ __m512i _mm512_cvtepu32_epi64(__m256i a);
VPMOVZXDQ __m512i _mm512_mask_cvtepu32_epi64(__m512i a, __mmask8 k, __m256i b);
VPMOVZXDQ __m512i _mm512_maskz_cvtepu32_epi64( __mmask8 k, __m256i a);
VPMOVZXWD __m512i _mm512_cvtepu16_epi32(__m128i a);
VPMOVZXWD __m512i _mm512_mask_cvtepu16_epi32(__m512i a, __mmask16 k, __m128i b);
VPMOVZXWD __m512i _mm512_maskz_cvtepu16_epi32(__mmask16 k, __m128i a);
VPMOVZXWQ __m512i _mm512_cvtepu16_epi64(__m256i a);
VPMOVZXWQ __m512i _mm512_mask_cvtepu16_epi64(__m512i a, __mmask8 k, __m256i b);
VPMOVZXWQ __m512i _mm512_maskz_cvtepu16_epi64( __mmask8 k, __m256i a);
VPMOVZXBW __m256i _mm256_cvtepu8_epi16(__m256i a);
VPMOVZXBW __m256i  _mm256_mask_cvtepu8_epi16(__m256i a, __mmask16 k, __m128i b);
VPMOVZXBW __m256i _mm256_maskz_cvtepu8_epi16( __mmask16 k, __m128i b);
VPMOVZXBD __m256i _mm256_cvtepu8_epi32(__m128i a);
VPMOVZXBD __m256i _mm256_mask_cvtepu8_epi32(__m256i a, __mmask8 k, __m128i b);
VPMOVZXBD __m256i _mm256_maskz_cvtepu8_epi32( __mmask8 k, __m128i b);
VPMOVZXBQ __m256i _mm256_cvtepu8_epi64(__m128i a);
VPMOVZXBQ __m256i _mm256_mask_cvtepu8_epi64(__m256i a, __mmask8 k, __m128i b);
VPMOVZXBQ __m256i _mm256_maskz_cvtepu8_epi64( __mmask8 k, __m128i a);
VPMOVZXDQ __m256i _mm256_cvtepu32_epi64(__m128i a);
VPMOVZXDQ __m256i _mm256_mask_cvtepu32_epi64(__m256i a, __mmask8 k, __m128i b);
VPMOVZXDQ __m256i _mm256_maskz_cvtepu32_epi64( __mmask8 k, __m128i a);
VPMOVZXWD __m256i _mm256_cvtepu16_epi32(__m128i a);
VPMOVZXWD __m256i _mm256_mask_cvtepu16_epi32(__m256i a, __mmask16 k, __m128i b);
VPMOVZXWD __m256i _mm256_maskz_cvtepu16_epi32(__mmask16 k, __m128i a);
VPMOVZXWQ __m256i _mm256_cvtepu16_epi64(__m128i a);
VPMOVZXWQ __m256i _mm256_mask_cvtepu16_epi64(__m256i a, __mmask8 k, __m128i b);
VPMOVZXWQ __m256i _mm256_maskz_cvtepu16_epi64( __mmask8 k, __m128i a);
VPMOVZXBW __m128i  _mm_mask_cvtepu8_epi16(__m128i a, __mmask8 k, __m128i b);
VPMOVZXBW __m128i _mm_maskz_cvtepu8_epi16( __mmask8 k, __m128i b);
VPMOVZXBD __m128i _mm_mask_cvtepu8_epi32(__m128i a, __mmask8 k, __m128i b);
VPMOVZXBD __m128i _mm_maskz_cvtepu8_epi32( __mmask8 k, __m128i b);
VPMOVZXBQ __m128i _mm_mask_cvtepu8_epi64(__m128i a, __mmask8 k, __m128i b);
VPMOVZXBQ __m128i _mm_maskz_cvtepu8_epi64( __mmask8 k, __m128i a);
VPMOVZXDQ __m128i _mm_mask_cvtepu32_epi64(__m128i a, __mmask8 k, __m128i b);
VPMOVZXDQ __m128i _mm_maskz_cvtepu32_epi64( __mmask8 k, __m128i a);
VPMOVZXWD __m128i _mm_mask_cvtepu16_epi32(__m128i a, __mmask16 k, __m128i b);
VPMOVZXWD __m128i _mm_maskz_cvtepu16_epi32(__mmask8 k, __m128i a);
VPMOVZXWQ __m128i _mm_mask_cvtepu16_epi64(__m128i a, __mmask8 k, __m128i b);
VPMOVZXWQ __m128i _mm_maskz_cvtepu16_epi64( __mmask8 k, __m128i a);
PMOVZXBW __m128i _mm_ cvtepu8_epi16 ( __m128i a);
PMOVZXBD __m128i _mm_ cvtepu8_epi32 ( __m128i a);
PMOVZXBQ __m128i _mm_ cvtepu8_epi64 ( __m128i a);
PMOVZXWD __m128i _mm_ cvtepu16_epi32 ( __m128i a);
PMOVZXWQ __m128i _mm_ cvtepu16_epi64 ( __m128i a);
PMOVZXDQ __m128i _mm_ cvtepu32_epi64 ( __m128i a);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 5.

EVEX-encoded instruction, see Exceptions Type E5.

#UD  If VEX.vvvv != 1111B, or EVEX.vvvv != 1111B.

