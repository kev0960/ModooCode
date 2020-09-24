----------------------------
title : KORTESTW, KORTESTB, KORTESTQ, KORTESTDs (Intel x86/64 assembly instruction)
cat_title : KORTESTW, KORTESTB, KORTESTQ, KORTESTD
ref_title : KORTESTW, KORTESTB, KORTESTQ, KORTESTD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------


#@ KORTESTW, KORTESTB, KORTESTQ, KORTESTD

**OR Masks And Set Flags**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/**\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`VEX.L0.0F.W0 98 /r `\newline{}`KORTESTW` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 |RR|V/V|AVX512F|Bitwise OR 16 bits masks k1 and k2 and update ZF and CF accordingly.|
|`VEX.L0.66.0F.W0 98 /r`\newline{}`KORTESTB` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 |RR|V/V|AVX512DQ|Bitwise OR 8 bits masks k1 and k2 and update ZF and CF accordingly.|
|`VEX.L0.0F.W1 98 /r `\newline{}`KORTESTQ` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 |RR|V/V|AVX512BW|Bitwise OR 64 bits masks k1 and k2 and update ZF and CF accordingly.|
|`VEX.L0.66.0F.W1 98 /r `\newline{}`KORTESTD` \tooltip{k1}{마스크 레지스터를 지칭 (k0 부터 k7 까지 가능)} k2 |RR|V/V|AVX512BW|Bitwise OR 32 bits masks k1 and k2 and update ZF and CF accordingly.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|
|-----|---------|---------|
|RR|ModRM:reg (w)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise `OR` between the vector mask register k2, and the vector mask register k1, and sets CF and ZF based on the operation result. 

ZF flag is set if both sources are 0x0. CF is set if, after the `OR` operation is done, the operation result is all 1's.


### Operation
#### KORTESTW 
```info-verb
TMP[15:0] <-  DEST[15:0] BITWISE OR SRC[15:0]
IF(TMP[15:0]=0)
    THEN ZF <-  1
    ELSE ZF <-  0
FI;
IF(TMP[15:0]=FFFFh)
    THEN CF <-  1
    ELSE CF <-  0
FI;
```
#### KORTESTB 
```info-verb
TMP[7:0] <-  DEST[7:0] BITWISE OR SRC[7:0]
IF(TMP[7:0]=0)
    THEN ZF <-  1
    ELSE ZF <-  0
FI;
IF(TMP[7:0]==FFh)
    THEN CF <-  1
    ELSE CF <-  0
FI;
```
#### KORTESTQ 
```info-verb
TMP[63:0] <-  DEST[63:0] BITWISE OR SRC[63:0]
IF(TMP[63:0]=0)
    THEN ZF <-  1
    ELSE ZF <-  0
FI;
IF(TMP[63:0]==FFFFFFFF_FFFFFFFFh)
    THEN CF <-  1
    ELSE CF <-  0
FI;
```
#### KORTESTD 
```info-verb
TMP[31:0] <-  DEST[31:0] BITWISE OR SRC[31:0]
IF(TMP[31:0]=0)
    THEN ZF <-  1
    ELSE ZF <-  0
FI;
IF(TMP[31:0]=FFFFFFFFh)
    THEN CF <-  1
    ELSE CF <-  0
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
KORTESTW __mmask16 _mm512_kortest[cz](__mmask16 a, __mmask16 b);
```
### Flags Affected


The ZF flag is set if the result of OR-ing both sources is all 0s.

The CF flag is set if the result of OR-ing both sources is all 1s.

The OF, SF, AF, and PF flags are set to 0.

### Other Exceptions


See Exceptions Type K20.

