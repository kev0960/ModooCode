----------------------------
title : UCOMISS (Intel x86/64 assembly instruction)
cat_title : UCOMISS
ref_title : UCOMISS
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/U
publish_date: 2020-09-01
----------------------------


#@ UCOMISS

**Unordered Compare Scalar Single-Precision Floating-Point Values and Set EFLAGS **

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op / **\newline{}**En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 2E /r`\newline{}`UCOMISS` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/V|SSE|Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.|
|`VEX.128.0F.WIG 2E /r`\newline{}VUCOMISS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m32}{8 비트 XMM 레지스터 혹은 32 비트 메모리 데이터.} |RM|V/V|AVX|Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.|
|`EVEX.LIG.0F.W0 2E /r`\newline{}VUCOMISS \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} xmm2/m32{sae} |T1S|V/V|AVX512F|Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r)|ModRM:r/m (r)|NA|NA|
|T1S|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


Compares the single-precision floating-point values in the low doublewords of operand 1 (first operand) and operand 2 (second operand), and sets the ZF, PF, and CF flags in the EFLAGS register according to the result (unor-dered, greater than, less than, or equal). The OF, SF and AF flags in the EFLAGS register are set to 0. The unor-dered result is returned if either source operand is a NaN (QNaN or SNaN).

Operand 1 is an XMM register; operand 2 can be an XMM register or a 32 bit memory location. 

The `UCOMISS` instruction differs from the `COMISS` instruction in that it signals a SIMD floating-point invalid opera-tion exception (#I) only if a source operand is an SNaN. The `COMISS` instruction signals an invalid numeric excep-tion when a source operand is either a QNaN or SNaN.

The EFLAGS register is not updated if an unmasked SIMD floating-point exception is generated.

Note: VEX.vvvv and EVEX.vvvv are reserved and must be 1111b, otherwise instructions will #UD.

Software should ensure VCOMISS is encoded with VEX.L=0. Encoding VCOMISS with VEX.L=1 may encounter unpredictable behavior across different processor generations.


### Operation
#### (V)UCOMISS (all versions)
```info-verb
RESULT !=<- UnorderedCompare(DEST[31:0] <> SRC[31:0]) {
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
VUCOMISS int _mm_comi_round_ss(__m128 a, __m128 b, int imm, int sae); 
UCOMISS int _mm_ucomieq_ss(__m128 a, __m128 b);
UCOMISS  int _mm_ucomilt_ss(__m128 a, __m128 b);
UCOMISS  int _mm_ucomile_ss(__m128 a, __m128 b);
UCOMISS  int _mm_ucomigt_ss(__m128 a, __m128 b);
UCOMISS  int _mm_ucomige_ss(__m128 a, __m128 b);
UCOMISS int _mm_ucomineq_ss(__m128 a, __m128 b);
```
### SIMD Floating-Point Exceptions


Invalid (if SNaN Operands), Denormal

### Other Exceptions


VEX-encoded instructions, see Exceptions Type 3; additionally

#UD If VEX.vvvv != 1111B.

EVEX-encoded instructions, see Exceptions Type E3NF.

