----------------------------
title : MOVBE (Intel x86/64 assembly instruction)
cat_title : MOVBE
ref_title : MOVBE
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOVBE

**Move Data After Swapping Bytes**### Instruction Operand Encoding


```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Performs a byte swap operation on the data copied from the second operand (source operand) and store the result in the first operand (destination operand). The source operand can be a general-purpose register, or memory loca-tion; the destination register can be a general-purpose register, or a memory location; however, both operands can not be registers, and only one operand can be a memory location. Both operands must be the same size, which can be a word, a doubleword or quadword. 

The `MOVBE` instruction is provided for swapping the bytes on a read from memory or on a write to memory; thus providing support for converting little-endian values to big-endian format and vice versa.

In 64-bit mode, the instruction's default operation size is 32 bits. Use of the REX.R prefix permits access to addi-tional registers (R8-R15). Use of the REX.W prefix promotes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
TEMP <- SRC
IF ( OperandSize = 16)THENDEST[7:0] <- TEMP[15:8];
          DEST[15:8] <- TEMP[7:0];
    ELES IF ( OperandSize = 32) 
          DEST[7:0] <- TEMP[31:24];
          DEST[15:8] <- TEMP[23:16];
          DEST[23:16] <- TEMP[15:8];
          DEST[31:23] <- TEMP[7:0];
    ELSE IF ( OperandSize = 64) 
          DEST[7:0] <- TEMP[63:56];
          DEST[15:8] <- TEMP[55:48];
          DEST[23:16] <- TEMP[47:40];
          DEST[31:24] <- TEMP[39:32];
          DEST[39:32] <- TEMP[31:24];
          DEST[47:40] <- TEMP[23:16];
          DEST[55:48] <- TEMP[15:8];
          DEST[63:56] <- TEMP[7:0];
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #GP(0)
* If the destination operand is in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If CPUID.01H:ECX.MOVBE[bit 22] = 0.
* If the LOCK prefix is used.
* If REP (F3H) prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If CPUID.01H:ECX.MOVBE[bit 22] = 0.
* If the LOCK prefix is used.
* If REP (F3H) prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If CPUID.01H:ECX.MOVBE[bit 22] = 0.
* If the LOCK prefix is used.
* If REP (F3H) prefix is used.
* If REPNE (F2H) prefix is used and CPUID.01H:ECX.SSE4_2[bit 20] = 0.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If CPUID.01H:ECX.MOVBE[bit 22] = 0.
* If the LOCK prefix is used.
* If REP (F3H) prefix is used.
