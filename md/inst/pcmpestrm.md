----------------------------
title : PCMPESTRM (Intel x86/64 assembly instruction)
cat_title : PCMPESTRM
ref_title : PCMPESTRM
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PCMPESTRM

** Packed Compare Explicit Length Strings, Return Mask**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`66 0F 3A 60 /r imm8`\newline{}`PCMPESTRM` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|SSE4_2|Perform a packed comparison of string data with explicit lengths, generating a mask, and storing the result in XMM0.|
|`VEX.128.66.0F3A 60 /r ib`\newline{}VPCMPESTRM \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |RMI|V/V|AVX|Perform a packed comparison of string data with explicit lengths, generating a mask, and storing the result in XMM0.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r)|ModRM:r/m (r)|imm8|NA|
### Description


The instruction compares data from two string fragments based on the encoded value in the imm8 contol byte (see Section 4.1, "Imm8 Control Byte Operation for `PCMPESTRI` / `PCMPESTRM` / `PCMPISTRI` / PCMPISTRM"), and gener-ates a mask stored to XMM0.

Each string fragment is represented by two values. The first value is an xmm (or possibly m128 for the second operand) which contains the data elements of the string (byte or word data). The second value is stored in an input length register. The input length register is EAX/RAX (for xmm1) or EDX/RDX (for xmm2/m128). The length repre-sents the number of bytes/words which are valid for the respective xmm/m128 data.  

The length of each input is interpreted as being the absolute-value of the value in the length register. The absolute-value computation saturates to 16 (for bytes) and 8 (for words), based on the value of imm8[bit3] when the value in the length register is greater than 16 (8) or less than -16 (-8).

The comparison and aggregation operations are performed according to the encoded value of Imm8 bit fields (see Section 4.1). As defined by imm8[6], IntRes2 is then either stored to the least significant bits of XMM0 (zero extended to 128 bits) or expanded into a byte/word-mask and then stored to XMM0.

Note that the Arithmetic Flags are written in a non-standard manner in order to supply the most relevant informa-tion:

    CFlag - Reset if IntRes2 is equal to zero, set otherwise

    ZFlag - Set if absolute-value of EDX is < 16 (8), reset otherwise

    SFlag - Set if absolute-value of EAX is < 16 (8), reset otherwise

    OFlag -IntRes2[0]

    AFlag - Reset

    PFlag - Reset

Note: In VEX.128 encoded versions, bits (VLMAX-1:128) of XMM0 are zeroed. VEX.vvvv is reserved and must be 1111b, VEX.L must be 0, otherwise the instruction will #UD.

### Effective Operand Size


|**Operating mode/size**|**Operand1**|**Operand 2**|**Length1**|**Length2**|**Result**|
|-----------------------|------------|-------------|-----------|-----------|----------|
|16 bit|xmm|xmm/m128|EAX|EDX|XMM0|
|32 bit|xmm|xmm/m128|EAX|EDX|XMM0|
|64 bit|xmm|xmm/m128|EAX|EDX|XMM0|
|64 bit + REX.W|xmm|xmm/m128|RAX|RDX|XMM0|
### Intel C/C++ Compiler Intrinsic Equivalent For Returning Mask


__m128i _mm_cmpestrm (__m128i a, int la, __m128i b, int lb, const int mode);

### Intel C/C++ Compiler Intrinsics For Reading EFlag Results


int     _mm_cmpestra (__m128i a, int la, __m128i b, int lb, const int mode);

int     _mm_cmpestrc (__m128i a, int la, __m128i b, int lb, const int mode);

int     _mm_cmpestro (__m128i a, int la, __m128i b, int lb, const int mode);

int     _mm_cmpestrs (__m128i a, int la, __m128i b, int lb, const int mode);

int     _mm_cmpestrz (__m128i a, int la, __m128i b, int lb, const int mode);

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 4; additionally, this instruction does not cause #GP if the memory operand is not aligned to 16 Byte boundary, and

#UD If VEX.L = 1.

                              If VEX.vvvv ->  1111B.

