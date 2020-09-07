----------------------------
title : KTESTW, KTESTB, KTESTQ, KTESTDs (Intel x86/64 assembly instruction)
cat_title : KTESTW, KTESTB, KTESTQ, KTESTD
ref_title : KTESTW, KTESTB, KTESTQ, KTESTD
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/K
publish_date: 2020-09-01
----------------------------
#@ KTESTW, KTESTB, KTESTQ, KTESTD

**Packed Bit Test Masks and Set Flags**

|**Opcode/**\newline{}**Instruction**|**Op **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.L0.0F.W0 99 /r\newline{}KTESTW k1, k2|RR|V/V|AVX512DQ|Set ZF and CF depending on sign bit AND and ANDN of 16 bits mask register sources.|
|VEX.L0.66.0F.W0 99 /r\newline{}KTESTB k1, k2|RR|V/V|AVX512DQ|Set ZF and CF depending on sign bit AND and ANDN of 8 bits mask register sources.|
|VEX.L0.0F.W1 99 /r\newline{}KTESTQ k1, k2|RR|V/V|AVX512BW|Set ZF and CF depending on sign bit AND and ANDN of 64 bits mask register sources.|
|VEX.L0.66.0F.W1 99 /r\newline{}KTESTD k1, k2|RR|V/V|AVX512BW|Set ZF and CF depending on sign bit AND and ANDN of 32 bits mask register sources.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|
|-----|---------|--------|
|RR|ModRM:reg (r)|ModRM:r/m (r, ModRM:[7:6] must be 11b)|
### Description


Performs a bitwise comparison of the bits of the first source operand and corresponding bits in the second source operand. If the `AND` operation produces all zeros, the ZF is set else the ZF is clear. If the bitwise `AND` operation of the inverted first source operand with the second source operand produces all zeros the CF is set else the CF is clear. Only the EFLAGS register is updated.

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### KTESTW
```info-verb
 
TEMP[15:0] <-  SRC2[15:0] AND SRC1[15:0]
IF (TEMP[15:0] = = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
FI;
TEMP[15:0] <-  SRC2[15:0] AND NOT SRC1[15:0]
IF (TEMP[15:0] = = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
FI;
AF <-  OF <-  PF <-  SF <-  0;
```
#### KTESTB
```info-verb
 
TEMP[7:0] <-  SRC2[7:0] AND SRC1[7:0]
IF (TEMP[7:0] = = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
FI;
TEMP[7:0] <-  SRC2[7:0] AND NOT SRC1[7:0]
IF (TEMP[7:0] = = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
FI;
AF <-  OF <-  PF <-  SF <-  0;
```
#### KTESTQ 
```info-verb
TEMP[63:0] <-  SRC2[63:0] AND SRC1[63:0]
IF (TEMP[63:0] = = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
FI;
TEMP[63:0] <-  SRC2[63:0] AND NOT SRC1[63:0]
IF (TEMP[63:0] = = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
FI;
AF <-  OF <-  PF <-  SF <-  0;
```
#### KTESTD 
```info-verb
TEMP[31:0] <-  SRC2[31:0] AND SRC1[31:0]
IF (TEMP[31:0] = = 0)
    THEN ZF <- 1;
    ELSE ZF <-  0;
FI;
TEMP[31:0] <-  SRC2[31:0] AND NOT SRC1[31:0]
IF (TEMP[31:0] = = 0)
    THEN CF <- 1;
    ELSE CF <-  0;
FI;
AF <-  OF <-  PF <-  SF <-  0;
```

### Intel C/C++ Compiler Intrinsic Equivalent
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type K20.

