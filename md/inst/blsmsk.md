----------------------------
title : BLSMSK (Intel x86/64 assembly instruction)
cat_title : BLSMSK
ref_title : BLSMSK
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------


#@ BLSMSK

** Get Mask Up to Lowest Set Bit**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|----------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|`VEX.NDD.LZ.0F38.W0 F3 /2`\newline{}`BLSMSK` \tooltip{r32}{4 바이트 짜리 범용 레지스터를 의미 (EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI). 64 비트 모드의 경우 추가적으로 R8D 부터 R15D 까지 가능.} \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} |VM|V/V|BMI1|Set all lower bits in r32 to "1" starting from bit 0 to lowest set bit in r/m32.|
|`VEX.NDD.LZ.0F38.W1 F3 /2`\newline{}`BLSMSK` \tooltip{r64}{8 바이트 짜리 범용 레지스터를 의미 (RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8–R15). 이들은 64비트 모드에서만 사용 가능하다.} \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} |VM|V/N.E.|BMI1|Set all lower bits in r64 to "1" starting from bit 0 to lowest set bit in r/m64.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|VM|VEX.vvvv (w)|ModRM:r/m (r)|NA|NA|
### Description


Sets all the lower bits of the destination operand to "1" up to and including lowest set bit (=1) in the source operand. If source operand is zero, `BLSMSK` sets all bits of the destination operand to 1 and also sets CF to 1.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.


### Operation

```info-verb
temp <- (SRC-1) XOR (SRC) ;
SF <- temp[OperandSize -1];
ZF <- 0;
IF SRC = 0
    CF <- 1;
ELSE
    CF <- 0;
FI
DEST <- temp;
```
### Flags Affected


SF is updated based on the result. CF is set if the source if zero. ZF and OF flags are cleared. AF and PF flag are undefined.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BLSMSK: unsigned __int32 _blsmsk_u32(unsigned __int32 src);
BLSMSK: unsigned __int64 _blsmsk_u64(unsigned __int64 src);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

