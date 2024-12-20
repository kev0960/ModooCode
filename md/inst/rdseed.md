----------------------------
title : RDSEED (Intel x86/64 assembly instruction)
cat_title : RDSEED
ref_title : RDSEED
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RDSEED

**Read Random SEED**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F C7 /7`\newline{}`RDSEED` \tooltip{r16}{2 바이트 짜리 범용 레지스터를 의미 (AX, CX, DX, BX, SP, BP, SI, DI). 64 비트 모드의 경우 추가적으로 R8 부터 R15 까지 가능.} |M|V/V|RDSEED|Read a 16-bit NIST SP800-90B & C compliant random value and store in the destination register.|
|`0F C7 /7`\newline{}`RDSEED` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} |M|V/V|RDSEED|Read a 32-bit NIST SP800-90B & C compliant random value and store in the destination register.|
|`REX.W + 0F C7 /7`\newline{}`RDSEED` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} |M|V/I|RDSEED|Read a 64-bit NIST SP800-90B & C compliant random value and store in the destination register.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (w)|NA|NA|NA|
### Description


Loads a hardware generated random value and store it in the destination register. The random value is generated from an Enhanced NRBG (Non Deterministic Random Bit Generator) that is compliant to NIST SP800-90B and NIST SP800-90C in the `XOR` construction mode. The size of the random value is determined by the destination register size and operating mode. The Carry Flag indicates whether a random value is available at the time the instruction is executed. CF=1 indicates that the data in the destination is valid. Otherwise CF=0 and the data in the destination operand will be returned as zeros for the specified width. All other flags are forced to 0 in either situation. Software must check the state of CF=1 for determining if a valid random seed value has been returned, otherwise it is expected to loop and retry execution of `RDSEED` (see Section 1.2).

The `RDSEED` instruction is available at all privilege levels. The `RDSEED` instruction executes normally either inside or outside a transaction region.

In 64-bit mode, the instruction's default operation size is 32 bits. Using a REX prefix in the form of REX.B permits access to additional registers (R8-R15). Using a REX prefix in the form of REX.W promotes operation to 64 bit oper-ands. See the summary chart at the beginning of this section for encoding data and limits.


### Operation

```info-verb
IF HW_NRND_GEN.ready = 1
    THEN 
          CASE of
                osize is 64: DEST[63:0] <- HW_NRND_GEN.data;
                osize is 32: DEST[31:0] <- HW_NRND_GEN.data;
                osize is 16: DEST[15:0] <- HW_NRND_GEN.data;
          ESAC;
          CF <- 1;
    ELSE
          CASE of
                osize is 64: DEST[63:0] <- 0;
                osize is 32: DEST[31:0] <- 0;
                osize is 16: DEST[15:0] <- 0;
          ESAC;
          CF <- 0;
FI;
OF, SF, ZF, AF, PF <- 0;
```
### Flags Affected


The CF flag is set according to the result (see the "Operation" section above). The OF, SF, ZF, AF, and PF flags are set to 0.

### C/C++ Compiler Intrinsic Equivalent


RDSEED int _rdseed16_step( unsigned short \htmlonly{*} );

RDSEED int _rdseed32_step( unsigned int \htmlonly{*} );

RDSEED int _rdseed64_step( unsigned __int64 \htmlonly{*});


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the F2H or F3H prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.RDSEED[bit 18] = 0.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the F2H or F3H prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.RDSEED[bit 18] = 0.

### Virtual-8086 Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the F2H or F3H prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.RDSEED[bit 18] = 0.

### Compatibility Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the F2H or F3H prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.RDSEED[bit 18] = 0.

### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used.
* If the F2H or F3H prefix is used.
* If CPUID.(EAX=07H, ECX=0H):EBX.RDSEED[bit 18] = 0.
