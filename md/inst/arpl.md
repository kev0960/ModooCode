----------------------------
title : ARPL (Intel x86/64 assembly instruction)
cat_title : ARPL
ref_title : ARPL
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/A
publish_date: 2020-09-01
----------------------------


#@ ARPL

**Adjust RPL Field of Segment Selector**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|63 /r|`ARPL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |NP|N. E.|Valid|Adjust RPL of r/m16 to not less than RPL of r16.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|ModRM:r/m (w)|ModRM:reg (r)|NA|NA|
### Description


Compares the RPL fields of two segment selectors. The first operand (the destination operand) contains one segment selector and the second operand (source operand) contains the other. (The RPL field is located in bits 0 and 1 of each operand.) If the RPL field of the destination operand is less than the RPL field of the source operand, the ZF flag is set and the RPL field of the destination operand is increased to match that of the source operand. Otherwise, the ZF flag is cleared and no change is made to the destination operand. (The destination operand can be a word register or a memory location; the source operand must be a word register.)

The `ARPL` instruction is provided for use by operating-system procedures (however, it can also be used by applica-tions). It is generally used to adjust the RPL of a segment selector that has been passed to the operating system by an application program to match the privilege level of the application program. Here the segment selector passed to the operating system is placed in the destination operand and segment selector for the application program's code segment is placed in the source operand. (The RPL field in the source operand represents the priv-ilege level of the application program.) Execution of the `ARPL` instruction then ensures that the RPL of the segment selector received by the operating system is no lower (does not have a higher privilege) than the privilege level of the application program (the segment selector for the application program's code segment can be read from the stack following a procedure call).

This instruction executes as described in compatibility mode and legacy mode. It is not encodable in 64-bit mode. 

See "Checking Caller Access Privileges" in Chapter 3, "Protected-Mode Memory Management," of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A, for more information about the use of this instruc-tion.


### Operation

```info-verb
IF 64-BIT MODETHENSee MOVSXD;ELSEIF DEST[RPL] < SRC[RPL]
                THEN
                      ZF <- 1;
                      DEST[RPL] <- SRC[RPL];
                ELSE
                      ZF <- 0;
          FI;
FI;
```
### Flags Affected


The ZF flag is set to 1 if the RPL field of the destination operand is less than that of the source operand; otherwise, it is set to 0.


### Protected Mode Exceptions

#### #GP(0)
* If the destination is located in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register is used to access memory and it contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* The ARPL instruction is not recognized in real-address mode.
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #UD
* The ARPL instruction is not recognized in virtual-8086 mode.
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions



Not applicable.

