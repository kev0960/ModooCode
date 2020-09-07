----------------------------
title : SHA256RNDS2 (Intel x86/64 assembly instruction)
cat_title : SHA256RNDS2
ref_title : SHA256RNDS2
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------
#@ SHA256RNDS2

**Perform Two Rounds of SHA256 Operation**

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 38 CB /r \newline{}SHA256RNDS2 xmm1, xmm2/m128, <XMM0>|RM0|V/V|SHA|Perform 2 rounds of SHA256 operation using an initial SHA256 state (C,D,G,H) from xmm1, an initial SHA256 state (A,B,E,F) from xmm2/m128, and a pre-computed sum of the next 2 round mes-sage dwords and the corresponding round constants from the implicit operand XMM0, storing the updated SHA256 state (A,B,E,F) result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|Implicit XMM0 (r)|
### Description


The `SHA256RNDS2` instruction performs 2 rounds of SHA256 operation using an initial SHA256 state (C,D,G,H) from the first operand, an initial SHA256 state (A,B,E,F) from the second operand, and a pre-computed sum of the next 2 round message dwords and the corresponding round constants from the implicit operand xmm0. Note that only the two lower dwords of XMM0 are used by the instruction.

The updated SHA256 state (A,B,E,F) is written to the first operand, and the second operand can be used as the updated state (C,D,G,H) in later rounds.


### Operation
#### SHA256RNDS2 
```info-verb
A_0 <-  SRC2[127:96]; 
B_0 <-  SRC2[95:64]; 
C_0 <-  SRC1[127:96]; 
D_0 <-  SRC1[95:64]; 
E_0 <-  SRC2[63:32]; 
F_0 <-  SRC2[31:0]; 
G_0 <-  SRC1[63:32]; 
H_0 <-  SRC1[31:0]; 
WK0 <-  XMM0[31: 0]; 
WK1 <-  XMM0[63: 32]; 
FOR i = 0 to 1
    A_(i +1) <-  Ch (E_i, F_i, G_i) +1( E_i) +WKi+ H_i + Maj(A_i , B_i, C_i) +0( A_i); 
    B_(i +1) <-  A_i; 
    C_(i +1) <-  B_i ; 
    D_(i +1) <-  C_i; 
    E_(i +1) <-  Ch (E_i, F_i, G_i) +1( E_i) +WKi+ H_i + D_i; 
    F_(i +1) <-  E_i ; 
    G_(i +1) <-  F_i; 
    H_(i +1) <-  G_i; 
ENDFOR
DEST[127:96] <-  A_2; 
DEST[95:64] <-  B_2; 
DEST[63:32] <-  E_2; 
DEST[31:0] <-  F_2; 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
SHA256RNDS2: __m128i _mm_sha256rnds2_epu32(__m128i, __m128i, __m128i);
```
### Flags Affected


None

### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4.

