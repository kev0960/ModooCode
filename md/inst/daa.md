----------------------------
title : DAA (Intel x86/64 assembly instruction)
cat_title : DAA
ref_title : DAA
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/D
publish_date: 2020-09-01
----------------------------


#@ DAA

**Decimal Adjust AL after Addition**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|27|`DAA` |NP|Invalid|Valid|Decimal adjust AL after addition.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Adjusts the sum of two packed BCD values to create a packed BCD result. The AL register is the implied source and destination operand. The `DAA` instruction is only useful when it follows an `ADD` instruction that adds (binary addi-tion) two 2-digit, packed BCD values and stores a byte result in the AL register. The `DAA` instruction then adjusts the contents of the AL register to contain the correct 2-digit, packed BCD result. If a decimal carry is detected, the CF and AF flags are set accordingly.

This instruction executes as described above in compatibility mode and legacy mode. It is not valid in 64-bit mode.


### Operation

```info-verb
IF 64-Bit Mode
    THEN#UD;
    ELSE
          old_AL <- AL;
          old_CF <- CF;
          CF <- 0;
          IF (((AL AND 0FH) > 9) or AF = 1)
                 THEN
                       AL <- AL + 6;
                       CF <- old_CF or (Carry from AL <- AL + 6);
                       AF <- 1;
   ELSE
   AF <- 0;
          FI;
          IF ((old_AL > 99H) or (old_CF = 1))
  THEN
                       AL <- AL + 60H;
   CF <- 1;
                ELSE
                       CF <- 0;
          FI;
FI;
```
### Example


ADD  AL, BL  Before: AL=79H BL=35H EFLAGS(OSZAPC)=XXXXXX

                      After: AL=AEH BL=35H EFLAGS(0SZAPC)=110000

DAA Before: AL=AEH BL=35H EFLAGS(OSZAPC)=110000

                      After: AL=14H BL=35H EFLAGS(0SZAPC)=X00111

DAA Before: AL=2EH BL=35H EFLAGS(OSZAPC)=110000

                      After: AL=34H BL=35H EFLAGS(0SZAPC)=X00101

### Flags Affected


The CF and AF flags are set if the adjustment of the value results in a decimal carry in either digit of the result (see the "Operation" section above). The SF, ZF, and PF flags are set according to the result. The OF flag is undefined.


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions

#### #UD
* If the LOCK prefix is used.

### 64-Bit Mode Exceptions

#### #UD
* If in 64-bit mode.
