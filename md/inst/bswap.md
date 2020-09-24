----------------------------
title : BSWAP (Intel x86/64 assembly instruction)
cat_title : BSWAP
ref_title : BSWAP
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BSWAP

**Byte Swap**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F C8+rd|`BSWAP` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |O|Valid\htmlonly{*}|Valid|Reverses the byte order of a 32-bit register.|
|REX.W + 0F C8+rd|`BSWAP` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |O|Valid|N.E.|Reverses the byte order of a 64-bit register.|

```note
\htmlonly{*} See IA-32 Architecture Compatibility section below
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|O|opcode + rd (r, w)|NA|NA|NA|
### Description


Reverses the byte order of a 32-bit or 64-bit (destination) register. This instruction is provided for converting little-endian values to big-endian format and vice versa. To swap bytes in a word value (16-bit register), use the `XCHG` instruction. When the `BSWAP` instruction references a 16-bit register, the result is undefined.

In 64-bit mode, the instruction's default operation size is 32 bits. Using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). Using a REX prefix in the form of REX.W promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.

### IA-32 Architecture Legacy Compatibility


The BSWAP instruction is not supported on IA-32 processors earlier than the Intel486(tm) processor family. For compatibility with this instruction, software should include functionally equivalent code for execution on Intel processors earlier than the Intel486 processor family.


### Operation

```info-verb
TEMP <- DEST
IF 64-bit mode AND OperandSize = 64
    THENDEST[7:0] <- TEMP[63:56];
          DEST[15:8] <- TEMP[55:48];
          DEST[23:16] <- TEMP[47:40];
          DEST[31:24] <- TEMP[39:32];
          DEST[39:32] <- TEMP[31:24];
          DEST[47:40] <- TEMP[23:16];
          DEST[55:48] <- TEMP[15:8];
          DEST[63:56] <- TEMP[7:0];
    ELSEDEST[7:0] <- TEMP[31:24];
          DEST[15:8] <- TEMP[23:16];
          DEST[23:16] <- TEMP[15:8];
          DEST[31:24] <- TEMP[7:0];
FI;
```
### Flags Affected


None.

### Exceptions (All Operating Modes)


#UD  If the LOCK prefix is used.

