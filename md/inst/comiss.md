----------------------------
title : COMISS (Intel x86/64 assembly instruction)
cat_title : COMISS
ref_title : COMISS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/C
publish_date: 2020-09-01
----------------------------


#@ COMISS

**Compare Scalar Ordered Single-Precision Floating-Point Values and Set EFLAGS**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|0F 2F /r\newline{}COMISS xmm1, xmm2/m32|RM|V/V|SSE|Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.|
|VEX.128.0F.WIG 2F /r\newline{}VCOMISS xmm1, xmm2/m32|RM|V/V|AVX|Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.|
|EVEX.LIG.0F.W0 2F /r\newline{}VCOMISS xmm1, xmm2/m32{sae}|T1S|V/V|AVX512F|Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|T1S|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Compares the single-precision floating-point values in the low quadwords of operand 1 (first operand) and operand 2 (second operand), and sets the ZF, PF, and CF flags in the EFLAGS register according to the result (unordered, greater than, less than, or equal). The OF, SF and AF flags in the EFLAGS register are set to 0. The unordered result is returned if either source operand is a NaN (QNaN or SNaN).

Operand 1 is an XMM register; operand 2 can be an XMM register or a 32 bit memory location. 

The `COMISS` instruction differs from the `UCOMISS` instruction in that it signals a SIMD floating-point invalid opera-tion exception (#I) when a source operand is either a QNaN or SNaN. The `UCOMISS` instruction signals an invalid numeric exception only if a source operand is an SNaN.

The EFLAGS register is not updated if an unmasked SIMD floating-point exception is generated.

VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

Software should ensure VCOMISS is encoded with VEX.L=0. Encoding VCOMISS with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### COMISS (all versions)
```info-verb
RESULT !=<- OrderedCompare(DEST[31:0] <> SRC[31:0]) {
(* Set EFLAGS *) CASE (RESULT) OF
    UNORDERED: ZF,PF,CF <-  111;
    GREATER_THAN: ZF,PF,CF <-  000;
    LESS_THAN: ZF,PF,CF <-  001;
    EQUAL: ZF,PF,CF <-  100;
ESAC;
OF, AF, SF <-  0; }
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VCOMISS int _mm_comi_round_ss(__m128 a, __m128 b, int imm, int sae); 
VCOMISS int _mm_comieq_ss (__m128 a, __m128 b)
VCOMISS int _mm_comilt_ss (__m128 a, __m128 b)
VCOMISS int _mm_comile_ss (__m128 a, __m128 b)
VCOMISS int _mm_comigt_ss (__m128 a, __m128 b)
VCOMISS int _mm_comige_ss (__m128 a, __m128 b)
VCOMISS int _mm_comineq_ss (__m128 a, __m128 b)
```
### SIMD Floating-Point Exceptions


Invalid (if SNaN or QNaN operands), Denormal.

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3; 

EVEX-encoded instructions, see Exceptions Type E3NF.

#UD If VEX.vvvv != 1111B or EVEX.vvvv != 1111B.

