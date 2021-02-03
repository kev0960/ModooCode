----------------------------
title : MOV (Intel x86/64 assembly instruction)
cat_title : MOV
ref_title : MOV
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/M
publish_date: 2020-09-01
----------------------------


#@ MOV

**Move**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|88 /r|`MOV` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{r8}{1 바이트 짜리 범용 레지스터를 의미 (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, SIL). 64 비트 모드에 경우 추가적으로 R8L 부터 R16L 까지 가능} |MR|Valid|Valid|Move r8 to r/m8.|
|REX + 88 /r|`MOV` r/m8\footnote{\htmlonly{*}\htmlonly{*}\htmlonly{*} } r8\footnote{\htmlonly{*}\htmlonly{*}\htmlonly{*}} |MR|Valid|N.E.|Move r8 to r/m8.|
|89 /r|`MOV` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |MR|Valid|Valid|Move r16 to r/m16.|
|89 /r|`MOV` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |MR|Valid|Valid|Move r32 to r/m32.|
|REX.W + 89 /r|`MOV` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |MR|Valid|N.E.|Move r64 to r/m64.|
|8A /r|`MOV` \tooltip{r8}{1 바이트 짜리 범용 레지스터를 의미 (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, SIL). 64 비트 모드에 경우 추가적으로 R8L 부터 R16L 까지 가능} \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|Move r/m8 to r8.|
|REX + 8A /r|`MOV` r8\htmlonly{*}\htmlonly{*}\htmlonly{*} r/m8\htmlonly{*}\htmlonly{*}\htmlonly{*} |RM|Valid|N.E.|Move r/m8 to r8.|
|8B /r|`MOV` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } |RM|Valid|Valid|Move r/m16 to r16.|
|8B /r|`MOV` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |RM|Valid|Valid|Move r/m32 to r32.|
|REX.W + 8B /r|`MOV` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |RM|Valid|N.E.|Move r/m64 to r64.|
|8C /r|`MOV` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } Sreg\htmlonly{*}\htmlonly{*} |MR|Valid|Valid|Move segment register to r/m16.|
|REX.W + 8C /r|`MOV` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} Sreg\htmlonly{*}\htmlonly{*} |MR|Valid|Valid|Move zero extended 16-bit segment register to r/m64.|
|8E /r|`MOV` \tooltip{Sreg}{세그먼트 레지스터} r/m16\htmlonly{*}\htmlonly{*} |RM|Valid|Valid|Move r/m16 to segment register.|
|REX.W + 8E /r|`MOV` \tooltip{Sreg}{세그먼트 레지스터} r/m64\htmlonly{*}\htmlonly{*} |RM|Valid|Valid|Move lower 16 bits of r/m64 to segment register.|
|A0|`MOV` AL moffs8\htmlonly{*} |FD|Valid|Valid|Move byte at (seg:offset) to AL.|
|REX.W + A0|`MOV` AL moffs8\htmlonly{*} |FD| Valid|N.E.|Move byte at 2offset) to AL.|
|A1|`MOV` AX moffs16\htmlonly{*} |FD|Valid|Valid|Move word at (seg:offset) to AX.|
|A1|`MOV` EAX moffs32\htmlonly{*} |FD|Valid|Valid|Move doubleword at (seg:offset) to EAX.|
|REX.W + A1|`MOV` RAX moffs64\htmlonly{*} |FD|Valid|N.E.|Move quadword at (offset) to RAX.|
|A2|`MOV` \tooltip{moffs8}{MOV 명령어에서만 사용되는데, 현재 세그먼트 베이스로 부터의 오프셋을 표현한다. 이 때 해당 명령어의 경우 ModR/M 은 사용되지 않는다.} AL |TD| Valid|Valid|Move AL to (seg:offset).|
|REX.W + A2|`MOV` moffs8\footnote{\htmlonly{*}\htmlonly{*}\htmlonly{*}} AL |TD|Valid|N.E.|Move AL to (offset).|
|A3|`MOV` moffs16\htmlonly{*} AX |TD|Valid|Valid|Move AX to (seg:offset).|
|A3|`MOV` moffs32\htmlonly{*} EAX |TD|Valid|Valid|Move EAX to (seg:offset).|
|REX.W + A3|`MOV` moffs64\htmlonly{*} RAX |TD|Valid|N.E.|Move RAX to (offset).|
|B0+ rb ib|`MOV` \tooltip{r8}{1 바이트 짜리 범용 레지스터를 의미 (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, SIL). 64 비트 모드에 경우 추가적으로 R8L 부터 R16L 까지 가능} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |OI|Valid|Valid|Move imm8 to r8.|
|REX + B0+ rb ib|`MOV` r8\footnote{\htmlonly{*}\htmlonly{*}\htmlonly{*}} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |OI|Valid|N.E.|Move imm8 to r8.|
|B8+ rw iw|`MOV` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |OI|Valid|Valid|Move imm16 to r16.|
|B8+ rd id|`MOV` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |OI|Valid|Valid|Move imm32 to r32.|
|REX.W + B8+ rd io|`MOV` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{imm64}{8 바이트 짜리 명시적 데이터. -9,223,372,036,854,775,808 부터 9,223,372,036,854,775,807 까지의 정수를 표현한다. } |OI|Valid|N.E.|Move imm64 to r64.|
|C6 /0 ib|`MOV` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|Valid|Move imm8 to r/m8.|
|REX + C6 /0 ib|`MOV` r/m8\htmlonly{*}\htmlonly{*}\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Move imm8 to r/m8.|
|C7 /0 iw|`MOV` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm16}{2 바이트 짜리 명시적 데이터. -32,768 부터 32,767 까지의 정수를 표현한다. } |MI|Valid|Valid|Move imm16 to r/m16.|
|C7 /0 id|`MOV` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |MI|Valid|Valid|Move imm32 to r/m32.|
|REX.W + C7 /0 id|`MOV` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm32}{4 바이트 짜리 명시적 데이터. -2,147,483,648 부터 2,147,483,647 까지의 정수를 표현한다. } |MI|Valid |N.E.|Move imm32 sign extended to 64-bits to r/m64.|

```note
\htmlonly{*} The moffs8, moffs16, moffs32 and moffs64 operands specify a simple offset relative to the segment base, where 8, 16, 32 and 64 refer to the size of the data. The address-size attribute of the instruction determines the size of the offset, either 16, 32 or 64 bits.

\htmlonly{*}\htmlonly{*}In 32-bit mode, the assembler may insert the 16-bit operand-size prefix with this instruction (see the following���eV scription���eV c-tion for further information�.�

\htmlonly{*}\htmlonly{*}\htmlonly{*}In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|MR|ModRM:r/m (w)|ModRM:reg (r��|NA|NA|
|RM|ModRM:reg (w��|ModRM:r/m (r)|NA|NA|
|FD|AL/AX/EAX/RAX|Moffs|NA|NA|
|TD|Moffs (w)|AL/AX/EAX/RAX|NA|NA|
|OI|opcode + rd (w)|imm8/16/32/64|NA|NA|
|MI|ModRM:r/m (w)|imm8/16/32/64|NA|NA|
### Description


Copies the second operand (source operand) to the first operand (destination operand). The source operand can be an immediate value, general-purpose register, segment register, or memory location; the destination register can be a general-purpose register, segment register, or memory location. Both operands must be the same size, which can be a byte, a word, a doubleword, or a quadword.

The `MOV` instruction cannot be used to load the CS register. Attempting to do so results in an invalid opcode excep-tion (#UD). To load the CS register, use the far JMP, CALL, or RET instruction.

If the destination operand is a segment register (DS, ES, FS, GS, or SS), the source operand must be a valid segment selector. In protected mode, moving a segment selector into a segment register automatically causes the segment descriptor information associated with that segment selector to be loaded into the hidden (shadow) part of the segment register. While loading this information, the segment selector and segment descriptor information is validated (see the "Operation" algorithm below). The segment descriptor data is obtained from the GDT or LDT entry for the specified segment selector. 

A NULL segment selector (values 0000-0003) can be loaded into the DS, ES, FS, and GS registers without causing a protection exception. However, any subsequent attempt to reference a segment whose corresponding segment register is loaded with a NULL value causes a general protection exception (#GP) and no memory reference occurs.

Loading the SS register with a `MOV` instruction inhibits all interrupts until after the execution of the next instruc-tion. This operation allows a stack pointer to be loaded into the ESP register with the next instruction (MOV ESP, stack-pointer value) before an interrupt occurs\footnote{1} . Be aware that the LSS instruction offers a more efficient method of loading the SS and ESP registers.

When executing `MOV` Reg, Sreg, the processor copies the content of Sreg to the 16 least significant bits of the general-purpose register. The upper bits of the destination register are zero for most IA-32 processors (Pentium 

```sidenote


1. If a code instruction breakpoint (for debug) is placed on an instruction located immediately after a MOV SS instruction, the break-point may not be triggered. However, in a sequence of instructions that load the SS register, only the first instruction in the sequence is guaranteed to delay an interrupt.

    In the following sequence, interrupts may be recognized before MOV ESP, EBP executes:

    MOV SS, EDXMOV SS, EAXMOV ESP, EBP
```

Pro processors and later) and all Intel 64 processors, with the exception that bits 31:16 are undefined for Intel Quark X1000 processors, Pentium and earlier processors.

In 64-bit mode, the instruction's default operation size is 32 bits. Use of the REX.R prefix permits access to addi-tional registers (R8-R15��. Use of the REX.W prefix proomtes operation to 64 bits. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
DEST 0 SRC;
Loading a segment register while in protected mode results in special checks and actions, as described in the following listing. These checks are performed on the segment selector and the segment descriptor to which it points.
IF SS is loaded
    THEN
          IF segment selector is NULL
                THEN #GP(0); FI;
          IF segment selector index is outside descriptor table limits 
          or segment selector's RPL 0 CPL
          or segment is not a writable data segmentor DPL 0 CPL
                THEN #GP(selector); FI;
          IF segment not marked present 
                THEN #SS�s� elector); 
                ELSE
                      SS 0 segment selector;
                      SS 0 segment descriptor; FI;
FI;
IF DS, ES, FS, or GS is loaded with non-NULL selector
THEN
    IF segment selector index is outside descriptor table limits
    or segment is not a data or readable code segment
    or ((segment is a data or nonconforming code segment)
    or ((RPL > DPL) and (CPL > DPL))
          THEN #GP(selector); FI;
    IF segment not marked present
          THEN #NP(selector);
          ELSE
                SegmentRegister 0 segment selector;
                SegmentRegister 0 segment descriptor; FI;
FI;
IF DS, ES, FS, or GS is loaded with NULL selector
    THEN
          SegmentRegister 0 segment selector;
          SegmentRegister 0 segment descriptor;
FI;
```
### Flags Affected


None


### Protected Mode Exceptions

#### #GP(0)
* If attempt is made to load SS register with NULL segment selector.
* If the destination operand is in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #GP(selectorp�
* If segment selector index is outside descriptor table limits. 
* If the SS register is being loaded and the segment selector's RPL and the segment descriptorp�s DPL are not equal to the CPL. 
* If the SS register is being loaded and the segment pointed to is a non-writable data segment.
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is not a data or readable code segment.
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is a data or nonconforming code segment, but both the RPL and the CPL are greater than the DPL.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #SS(selector)
* If the SS register is being loaded and the segment pointed to is marked not present.

#### #NP
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is marked not present.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0p�
* If alignment checking is enabled and a unnaligned memory reference is made while the current privilege level is 3.

#### #UD
* If attempt is made to load the CS register.
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #GP
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If a memory operand effective address is outside the SS segment limit.

#### #UD
* If attempt is made to load the CS register.
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0p�
* If alignment checking is enabled and an unaligned memory reference is made.

#### #UD
* If attempt is made to load the CS register.
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.
* If an attempt is made to load SS register with NULL segment selector when CPL = 3.
* If an attempt is made to load SS register with NULL segment selector when CPL < 3 and CPL 0 RPL.

#### #GP(selector)
* If segment selector index is outside descriptor table limits. 
* If the memory access to the descriptor table is non-canonical.
* If the SS register is being loaded and the segment selector's RPL and the segment descriptorP�s DPL are not equal to the CPL.
* If the SS register is being loaded and the segment pointed to is a nonwritable data segment.
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is not a data or readable code segment.
* If the DS, ES, FS, or GS register is being loaded and the segment pointed to is a data or nonconforming code segment, but both the RPL and the CPL are greater than the DPL.

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #SS(selector)
* If the SS register is being loaded and the segment pointed to is marked not present.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0P�
* If alignment checking is enabled and a unnaligned memory reference is made while the current privilege level is 3.

#### #UD
* If attempt is made to load the CS register.
* If the LOCK prefix is used.
