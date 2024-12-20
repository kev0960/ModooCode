----------------------------
title : LDMXCSR (Intel x86/64 assembly instruction)
cat_title : LDMXCSR
ref_title : LDMXCSR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/L
publish_date: 2020-09-01
----------------------------


#@ LDMXCSR

**Load MXCSR Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|`0F AE /2`\newline{}`LDMXCSR` \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} |M|V/V|SSE|Load MXCSR register from m32.|
|`VEX.LZ.0F.WIG AE /2`\newline{}VLDMXCSR \tooltip{m32}{DS:(E)SI, ES:(E)DI 로 표현되는 4 바이트 짜리 메모리를 나타낸다. 주로 문자열 연산에서 사용된다. 64 비트의 경우 RSI 또는 RDI 레지스터로 표현된다.} |M|V/V|AVX|Load MXCSR register from m32.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M|ModRM:r/m (r)|NA|NA|NA|
### Description


Loads the source operand into the MXCSR control/status register. The source operand is a 32-bit memory location. See "MXCSR Control and Status Register" in Chapter 10, of the Intel(R) 64 and IA-32 Architectures Software Devel-oper's Manual, Volume 1, for a description of the MXCSR register and its contents.

The `LDMXCSR` instruction is typically used in conjunction with the (V)STMXCSR instruction, which stores the contents of the MXCSR register in memory.

The default MXCSR value at reset is 1F80H.

If a (V)LDMXCSR instruction clears a SIMD floating-point exception mask bit and sets the corresponding exception flag bit, a SIMD floating-point exception will not be immediately generated. The exception will be generated only upon the execution of the next instruction that meets both conditions below:

*  the instruction must operate on an XMM or YMM register operand,

*  the instruction causes that particular SIMD floating-point exception to be reported. 

This instruction's operation is the same in non-64-bit modes and 64-bit mode.

If VLDMXCSR is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.

Note: In VEX-encoded versions, VEX.vvvv is reserved and must be 1111b, otherwise instructions will #UD.


### Operation

```info-verb
MXCSR <- m32;
```
### C/C++ Compiler Intrinsic Equivalent


_mm_setcsr(unsigned int i)

### Numeric Exceptions


None

### Other Exceptions


See Exceptions Type 5; additionally

#GP For an attempt to set reserved bits in MXCSR.

#UD If VEX.vvvv ->  1111B.

