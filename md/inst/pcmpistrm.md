----------------------------
title : PCMPISTRM (Intel x86/64 assembly instruction)
cat_title : PCMPISTRM
ref_title : PCMPISTRM
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PCMPISTRM

** Packed Compare Implicit Length Strings, Return Mask**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 3A 62 /r imm8\newline{}PCMPISTRM xmm1, xmm2/m128, imm8|RM|V/V|SSE4_2|Perform a packed comparison of string data with implicit lengths, generating a mask, and storing the result in XMM0.|
|VEX.128.66.0F3A.WIG 62 /r ib\newline{}VPCMPISTRM xmm1, xmm2/m128, imm8|RM|V/V|AVX|Perform a packed comparison of string data with implicit lengths, generating a Mask, and storing the result in XMM0.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r)|ModRM:r/m (r)|imm8|NA|
### Description


The instruction compares data from two strings based on the encoded value in the imm8 byte (see Section 4.1, "Imm8 Control Byte Operation for `PCMPESTRI` / `PCMPESTRM` / `PCMPISTRI` / PCMPISTRM") generating a mask stored to XMM0.

Each string is represented by a single value. The value is an xmm (or possibly m128 for the second operand) which contains the data elements of the string (byte or word data). Each input byte/word is augmented with a valid/invalid tag. A byte/word is considered valid only if it has a lower index than the least significant null byte/word. (The least significant null byte/word is also considered invalid.) 

The comparison and aggregation operation are performed according to the encoded value of Imm8 bit fields (see Section 4.1). As defined by imm8[6], IntRes2 is then either stored to the least significant bits of XMM0 (zero extended to 128 bits) or expanded into a byte/word-mask and then stored to XMM0.

Note that the Arithmetic Flags are written in a non-standard manner in order to supply the most relevant informa-tion:

    CFlag - Reset if IntRes2 is equal to zero, set otherwise

    ZFlag - Set if any byte/word of xmm2/mem128 is null, reset otherwise

    SFlag - Set if any byte/word of xmm1 is null, reset otherwise

    OFlag - IntRes2[0]

    AFlag - Reset

    PFlag - Reset

Note: In VEX.128 encoded versions, bits (VLMAX-1:128) of XMM0 are zeroed. VEX.vvvv is reserved and must be 1111b, VEX.L must be 0, otherwise the instruction will #UD.

### Effective Operand Size


|**Operating mode/size**|**Operand1**|**Operand 2**|**Result**|
|-----------------------|------------|-------------|----------|
|16 bit|xmm|xmm/m128|XMM0|
|32 bit|xmm|xmm/m128|XMM0|
|64 bit|xmm|xmm/m128|XMM0|
### Intel C/C++ Compiler Intrinsic Equivalent For Returning Mask


__m128i _mm_cmpistrm (__m128i a, __m128i b, const int mode);

### Intel C/C++ Compiler Intrinsics For Reading EFlag Results


int     _mm_cmpistra (__m128i a, __m128i b, const int mode);

int     _mm_cmpistrc (__m128i a, __m128i b, const int mode);

int     _mm_cmpistro (__m128i a, __m128i b, const int mode);

int     _mm_cmpistrs (__m128i a, __m128i b, const int mode);

int     _mm_cmpistrz (__m128i a, __m128i b, const int mode);

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally, this instruction does not cause #GP if the memory operand is not aligned to 16 Byte boundary, and

#UD If VEX.L = 1.

                              If VEX.vvvv ->  1111B.
