----------------------------
title : XABORT (Intel x86/64 assembly instruction)
cat_title : XABORT
ref_title : XABORT
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/X
publish_date: 2020-09-01
----------------------------


#@ XABORT

** Transactional Abort**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|-----------------------------------------------------|--------------------------------------------------|---------------|
|`C6 F8 ib`\newline{}`XABORT` \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |A|V/V|RTM|Causes an RTM abort if in RTM execution|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand2|Operand3|Operand4|
|-----|---------|--------|--------|--------|
|A|imm8|NA|NA|NA|
### Description


XABORT forces an RTM abort. Following an RTM abort, the logical processor resumes execution at the fallback address computed through the outermost `XBEGIN` instruction. The EAX register is updated to reflect an `XABORT` instruction caused the abort, and the imm8 argument will be provided in bits 31:24 of EAX. 


### Operation
#### XABORT
```info-verb
IF RTM_ACTIVE = 0
    THEN 
          Treat as NOP;
    ELSE
          GOTO RTM_ABORT_PROCESSING;
FI;
(* For any RTM abort condition encountered during RTM execution *)
RTM_ABORT_PROCESSING:
    Restore architectural register state;
    Discard memory updates performed in transaction;
    Update EAX with status and XABORT argument;
    RTM_NEST_COUNT <- 0;
    RTM_ACTIVE <- 0;
    IF 64-bit Mode
          THEN
                RIP <- fallbackRIP;
          ELSE
                EIP <- fallbackEIP;
    FI;
END
```
### Flags Affected


None


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
XABORT: void _xabort( unsigned int);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


#UD CPUID.(EAX=7, ECX=0):EBX.RTM[bit 11] = 0.

                              If LOCK prefix is used.

