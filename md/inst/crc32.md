----------------------------
title : CRC32 (Intel x86/64 assembly instruction)
cat_title : CRC32
ref_title : CRC32
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ CRC32

** Accumulate CRC32 Value**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|------------------------------------|------------------------|-----------------------------|---------------------------------|---------------|
|`F2 0F 38 F0 /r`\newline{}`CRC32` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|Accumulate CRC32 on r/m8.|
|`F2 REX 0F 38 F0 /r`\newline{}`CRC32` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} r/m8\htmlonly{*} |RM|Valid|N.E.|Accumulate CRC32 on r/m8.|
|`F2 0F 38 F1 /r`\newline{}`CRC32` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|Accumulate CRC32 on r/m16.|
|`F2 0F 38 F1 /r`\newline{}`CRC32` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|Valid|Valid|Accumulate CRC32 on r/m32.|
|`F2 REX.W 0F 38 F0 /r`\newline{}`CRC32` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |RM|Valid|N.E.|Accumulate CRC32 on r/m8.|
|`F2 REX.W 0F 38 F1 /r`\newline{}`CRC32` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|Valid|N.E.|Accumulate CRC32 on r/m64.|

```note
\htmlonly{*}In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
### Description


Starting with an initial value in the first operand (destination operand), accumulates a `CRC32` (polynomial 11EDC6F41H) value for the second operand (source operand) and stores the result in the destination operand. The source operand can be a register or a memory location. The destination operand must be an r32 or r64 register. If the destination is an r64 register, then the 32-bit result is stored in the least significant double word and 00000000H is stored in the most significant double word of the r64 register.

The initial value supplied in the destination operand is a double word integer stored in the r32 register or the least significant double word of the r64 register. To incrementally accumulate a `CRC32` value, software retains the result of the previous `CRC32` operation in the destination operand, then executes the `CRC32` instruction again with new input data in the source operand. Data contained in the source operand is processed in reflected bit order. This means that the most significant bit of the source operand is treated as the least significant bit of the quotient, and so on, for all the bits of the source operand. Likewise, the result of the CRC operation is stored in the destination operand in reflected bit order. This means that the most significant bit of the resulting CRC (bit 31) is stored in the least significant bit of the destination operand (bit 0), and so on, for all the bits of the CRC.


### Operation
### Notes:


BIT_REFLECT64: DST[63-0] = SRC[0-63]

    BIT_REFLECT32: DST[31-0] = SRC[0-31]

    BIT_REFLECT16: DST[15-0] = SRC[0-15]

    BIT_REFLECT8: DST[7-0] = SRC[0-7]

    MOD2: Remainder from Polynomial division modulus 2



CRC32 instruction for 64-bit source operand and 64-bit destination operand:

    TEMP1[63-0] <-  BIT_REFLECT64 (SRC[63-0])

    TEMP2[31-0] <-  BIT_REFLECT32 (DEST[31-0])

    TEMP3[95-0] <-  TEMP1[63-0] << 32

    TEMP4[95-0] <-  TEMP2[31-0] << 64

    TEMP5[95-0] <-  TEMP3[95-0] XOR TEMP4[95-0]

    TEMP6[31-0] <-  TEMP5[95-0] MOD2 11EDC6F41H

    DEST[31-0] <-  BIT_REFLECT (TEMP6[31-0])

    DEST[63-32] <-  00000000H

CRC32 instruction for 32-bit source operand and 32-bit destination operand:

    TEMP1[31-0] <-  BIT_REFLECT32 (SRC[31-0])

    TEMP2[31-0] <-  BIT_REFLECT32 (DEST[31-0])

    TEMP3[63-0] <-  TEMP1[31-0] << 32

    TEMP4[63-0] <-  TEMP2[31-0] << 32

    TEMP5[63-0] <-  TEMP3[63-0] XOR TEMP4[63-0]

    TEMP6[31-0] <-  TEMP5[63-0] MOD2 11EDC6F41H

    DEST[31-0] <-  BIT_REFLECT (TEMP6[31-0])

CRC32 instruction for 16-bit source operand and 32-bit destination operand:

    TEMP1[15-0] <-  BIT_REFLECT16 (SRC[15-0])

    TEMP2[31-0] <-  BIT_REFLECT32 (DEST[31-0])

    TEMP3[47-0] <-  TEMP1[15-0] << 32

    TEMP4[47-0] <-  TEMP2[31-0] << 16

    TEMP5[47-0] <-  TEMP3[47-0] XOR TEMP4[47-0]

    TEMP6[31-0] <-  TEMP5[47-0] MOD2 11EDC6F41H

    DEST[31-0] <-  BIT_REFLECT (TEMP6[31-0])

CRC32 instruction for 8-bit source operand and 64-bit destination operand:

    TEMP1[7-0] <-  BIT_REFLECT8(SRC[7-0])

    TEMP2[31-0] <-  BIT_REFLECT32 (DEST[31-0])

    TEMP3[39-0] <-  TEMP1[7-0] << 32

    TEMP4[39-0] <-  TEMP2[31-0] << 8

    TEMP5[39-0] <-  TEMP3[39-0] XOR TEMP4[39-0]

    TEMP6[31-0] <-  TEMP5[39-0] MOD2 11EDC6F41H

    DEST[31-0] <-  BIT_REFLECT (TEMP6[31-0])

    DEST[63-32] <-  00000000H

CRC32 instruction for 8-bit source operand and 32-bit destination operand:

    TEMP1[7-0] <-  BIT_REFLECT8(SRC[7-0])

    TEMP2[31-0] <-  BIT_REFLECT32 (DEST[31-0])

    TEMP3[39-0] <-  TEMP1[7-0] << 32

    TEMP4[39-0] <-  TEMP2[31-0] << 8

    TEMP5[39-0] <-  TEMP3[39-0] XOR TEMP4[39-0]

    TEMP6[31-0] <-  TEMP5[39-0] MOD2 11EDC6F41H

    DEST[31-0] <-  BIT_REFLECT (TEMP6[31-0])

### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
unsigned int _mm_crc32_u8( unsigned int crc, unsigned char data )
unsigned int _mm_crc32_u16( unsigned int crc, unsigned short data )
unsigned int _mm_crc32_u32( unsigned int crc, unsigned int data )
unsinged __int64 _mm_crc32_u64( unsinged __int64 crc, unsigned __int64 data )
```
### SIMD Floating Point Exceptions


None


### Protected Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS or GS segments.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF
* (fault-code) For a page fault.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If CPUID.01H:ECX.SSE4_2 [Bit 20] = 0.
* If LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP(0)
* If any part of the operand lies outside of the effective address space from 0 to 0FFFFH.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If CPUID.01H:ECX.SSE4_2 [Bit 20] = 0.
* If LOCK prefix is used.
### Virtual 8086 Mode Exceptions


#GP(0)  If any part of the operand lies outside of the effective address space from 0 to 0FFFFH.

#SS(0) If a memory operand effective address is outside the SS segment limit.

#PF (fault-code) For a page fault.

#AC(0) If alignment checking is enabled and an unaligned memory reference is made.

#UD If CPUID.01H:ECX.SSE4_2 [Bit 20] = 0.

                              If LOCK prefix is used.


### Compatibility Mode Exceptions



Same exceptions as in Protected Mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #PF
* (fault-code) For a page fault.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If CPUID.01H:ECX.SSE4_2 [Bit 20] = 0.
* If LOCK prefix is used.
