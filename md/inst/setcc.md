----------------------------
title : SETcc (Intel x86/64 assembly instruction)
cat_title : SETcc
ref_title : SETcc
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SETcc

**Set Byte on Condition**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|0F 97|SETA \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if above (CF=0 and ZF=0).|
|REX + 0F 97|SETA r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if above (CF=0 and ZF=0).|
|0F 93|SETAE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if above or equal (CF=0).|
|REX + 0F 93|SETAE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if above or equal (CF=0).|
|0F 92|SETB \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if below (CF=1).|
|REX + 0F 92|SETB r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if below (CF=1).|
|0F 96|SETBE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if below or equal (CF=1 or ZF=1).|
|REX + 0F 96|SETBE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if below or equal (CF=1 or ZF=1).|
|0F 92|SETC \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if carry (CF=1).|
|REX + 0F 92|SETC r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if carry (CF=1).|
|0F 94|SETE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if equal (ZF=1).|
|REX + 0F 94|SETE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if equal (ZF=1).|
|0F 9F|SETG \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if greater (ZF=0 and SF=OF).|
|REX + 0F 9F|SETG r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if greater (ZF=0 and SF=OF).|
|0F 9D|SETGE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if greater or equal (SF=OF).|
|REX + 0F 9D|SETGE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if greater or equal (SF=OF).|
|0F 9C|SETL \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if less (SF!= OF).|
|REX + 0F 9C|SETL r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if less (SF!= OF).|
|0F 9E|SETLE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if less or equal (ZF=1 or SF!= OF).|
|REX + 0F 9E|SETLE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if less or equal (ZF=1 or SF!= OF).|
|0F 96|SETNA \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not above (CF=1 or ZF=1).|
|REX + 0F 96|SETNA r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not above (CF=1 or ZF=1).|
|0F 92|SETNAE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not above or equal (CF=1).|
|REX + 0F 92|SETNAE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not above or equal (CF=1).|
|0F 93|SETNB \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not below (CF=0).|
|REX + 0F 93|SETNB r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not below (CF=0).|
|0F 97|SETNBE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not below or equal (CF=0 and ZF=0).|
|REX + 0F 97|SETNBE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not below or equal (CF=0 and ZF=0).|
|0F 93|SETNC \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not carry (CF=0).|
|REX + 0F 93|SETNC r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not carry (CF=0).|
|0F 95|SETNE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not equal (ZF=0).|
|REX + 0F 95|SETNE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not equal (ZF=0).|
|0F 9E|SETNG \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not greater (ZF=1 or SF!= OF)|
|REX + 0F 9E|SETNG r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not greater (ZF=1 or SF!= OF).|
|0F 9C|SETNGE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not greater or equal (SF!= OF).|
|REX + 0F 9C|SETNGE r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not greater or equal (SF!= OF).|
|0F 9D|SETNL \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not less (SF=OF).|
|REX + 0F 9D|SETNL r/m8\htmlonly{*} |M|Valid|N.E.|Set byte if not less (SF=OF).|
|0F 9F|SETNLE \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |M|Valid |Valid|Set byte if not less or equal (ZF=0 and SF=OF).|


|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|
|---------------|------------------------|-----------------------------|---------------------------------|
|SETNLE r/m8\htmlonly{*}|M|Valid|N.E.|
|SETNO r/m8|M|Valid |Valid|
|SETNO r/m8\htmlonly{*}|M|Valid|N.E.|
|SETNP r/m8|M|Valid|Valid|
|SETNP r/m8\htmlonly{*}|M|Valid|N.E.|
|SETNS r/m8|M|Valid |Valid|
|SETNS r/m8\htmlonly{*}|M|Valid|N.E.|
|SETNZ r/m8|M|Valid |Valid|
|SETNZ r/m8\htmlonly{*}|M|Valid|N.E.|
|SETO r/m8|M|Valid |Valid|
|SETO r/m8\htmlonly{*}|M|Valid|N.E.|
|SETP r/m8|M|Valid |Valid|
|SETP r/m8\htmlonly{*}|M|Valid|N.E.|
|SETPE r/m8|M|Valid |Valid|
|SETPE r/m8\htmlonly{*}|M|Valid|N.E.|
|SETPO r/m8|M|Valid |Valid|
|SETPO r/m8\htmlonly{*}|M|Valid|N.E.|
|SETS r/m8|M|Valid |Valid|
|SETS r/m8\htmlonly{*}|M|Valid|N.E.|
|SETZ r/m8|M|Valid |Valid|
|SETZ r/m8\htmlonly{*}|M|Valid |N.E.|


**Opcode Description**

REX + 0F 9F Set byte if not less or equal (ZF=0 and SF=OF).

0F 91 Set byte if not overflow (OF=0).

REX + 0F 91 Set byte if not overflow (OF=0).

0F 9B Set byte if not parity (PF=0).

REX + 0F 9B Set byte if not parity (PF=0).

0F 99 Set byte if not sign (SF=0).

REX + 0F 99 Set byte if not sign (SF=0).

0F 95 Set byte if not zero (ZF=0).

REX + 0F 95 Set byte if not zero (ZF=0).

0F 90 Set byte if overflow (OF=1)

REX + 0F 90 Set byte if overflow (OF=1).

0F 9A Set byte if parity (PF=1).

REX + 0F 9A Set byte if parity (PF=1).

0F 9A Set byte if parity even (PF=1).

REX + 0F 9A Set byte if parity even (PF=1).

0F 9B Set byte if parity odd (PF=0).

REX + 0F 9B Set byte if parity odd (PF=0).

0F 98 Set byte if sign (SF=1).

REX + 0F 98 Set byte if sign (SF=1).

0F 94 Set byte if zero (ZF=1).

REX + 0F 94 Set byte if zero (ZF=1).


```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Sets the destination operand to 0 or 1 depending on the settings of the status flags (CF, SF, OF, ZF, and PF) in the EFLAGS register. The destination operand points to a byte register or a byte in memory. The condition code suffix (cc) indicates the condition being tested for. 

The terms "above" and "below" are associated with the CF flag and refer to the relationship between two unsigned integer values. The terms "greater" and "less" are associated with the SF and OF flags and refer to the relationship between two signed integer values.

Many of the `SETcc` instruction opcodes have alternate mnemonics. For example, SETG (set byte if greater) and SETNLE (set if not less or equal) have the same opcode and test for the same condition: ZF equals 0 and SF equals OF. These alternate mnemonics are provided to make code more intelligible. Appendix B, "EFLAGS Condition Codes," in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, shows the alternate mnemonics for various test conditions.

Some languages represent a logical one as an integer with all bits set. This representation can be obtained by choosing the logically opposite condition for the `SETcc` instruction, then decrementing the result. For example, to test for overflow, use the SETNO instruction, then decrement the result.



In IA-64 mode, the operand size is fixed at 8 bits. Use of REX prefix enable uniform addressing to additional byte registers. Otherwise, this instruction's operation is the same as in legacy mode and compatibility mode. 


### Operation

```info-verb
IF condition
    THEN DEST <- 1; 
    ELSE DEST <- 0; 
FI;
```
### Flags Affected


None.


### Protected Mode Exceptions

#### #GP(0)
* If the destination is located in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #SS(0)
* If a memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #UD
* If the LOCK prefix is used.
