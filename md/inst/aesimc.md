----------------------------
title : AESIMC (Intel x86/64 assembly instruction)
cat_title : AESIMC
ref_title : AESIMC
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/A
publish_date: 2020-09-01
----------------------------


#@ AESIMC

**Perform the AES InvMixColumn Transformation**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|66 0F 38 DB /r\newline{}AESIMC xmm1, xmm2/m128|RM|V/V|AES|Perform the InvMixColumn transformation on a 128-bit round key from xmm2/m128 and store the result in xmm1.|
|VEX.128.66.0F38.WIG DB /r\newline{}VAESIMC xmm1, xmm2/m128|RM|V/V|Both AES andAVX flags|Perform the InvMixColumn transformation on a 128-bit round key from xmm2/m128 and store the result in xmm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|Operand3|Operand4|
|-----|---------|--------|--------|--------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Perform the InvMixColumns transformation on the source operand and store the result in the destination operand. The destination operand is an XMM register. The source operand can be an XMM register or a 128-bit memory loca-tion. 

Note: the `AESIMC` instruction should be applied to the expanded AES round keys (except for the first and last round key) in order to prepare them for decryption using the "Equivalent Inverse Cipher" (defined in FIPS 197). 

128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: Bits (VLMAX-1:128) of the destination YMM register are zeroed.

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation
#### AESIMC
```info-verb
DEST[127:0] <- InvMixColumns( SRC );
DEST[VLMAX-1:128] (Unmodified)
```
#### VAESIMC 
```info-verb
DEST[127:0] <-  InvMixColumns( SRC );
DEST[VLMAX-1:128] <-  0;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
(V)AESIMC: __m128i _mm_aesimc (__m128i)
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.vvvv ->  1111B.

