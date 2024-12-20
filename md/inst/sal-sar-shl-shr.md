----------------------------
title : SAL, SAR, SHL, SHRs (Intel x86/64 assembly instruction)
cat_title : SAL, SAR, SHL, SHR
ref_title : SAL, SAR, SHL, SHR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/S
publish_date: 2020-09-01
----------------------------


#@ SAL, SAR, SHL, SHR

**Shift**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}\htmlonly{*}\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------------------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|D0 /4|`SAL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Multiply r/m8 by 2, once. |
|REX + D0 /4|`SAL` r/m8\htmlonly{*}\htmlonly{*} 1 |M1|Valid|N.E.|Multiply r/m8 by 2, once. |
|D2 /4|`SAL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Multiply r/m8 by 2, CL times.|
|REX + D2 /4|`SAL` r/m8\htmlonly{*}\htmlonly{*} CL |MC|Valid|N.E.|Multiply r/m8 by 2, CL times.|
|C0 /4 ib|`SAL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Multiply r/m8 by 2, imm8 times.|
|REX + C0 /4 ib|`SAL` r/m8\htmlonly{*}\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Multiply r/m8 by 2, imm8 times.|
|D1 /4|`SAL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Multiply r/m16 by 2, once.|
|D3 /4|`SAL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Multiply r/m16 by 2, CL times.|
|C1 /4 ib|`SAL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Multiply r/m16 by 2, imm8 times.|
|D1 /4|`SAL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Multiply r/m32 by 2, once.|
|REX.W + D1 /4|`SAL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Multiply r/m64 by 2, once.|
|D3 /4|`SAL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Multiply r/m32 by 2, CL times.|
|REX.W + D3 /4|`SAL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Multiply r/m64 by 2, CL times.|
|C1 /4 ib|`SAL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Multiply r/m32 by 2, imm8 times.|
|REX.W + C1 /4 ib|`SAL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Multiply r/m64 by 2, imm8 times.|
|D0 /7|`SAR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Signed divide\htmlonly{*} r/m8 by 2, once.|
|REX + D0 /7|`SAR` r/m8\htmlonly{*}\htmlonly{*} 1 |M1|Valid|N.E.|Signed divide\htmlonly{*} r/m8 by 2, once.|
|D2 /7|`SAR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Signed divide\htmlonly{*} r/m8 by 2, CL times.|
|REX + D2 /7|`SAR` r/m8\htmlonly{*}\htmlonly{*} CL |MC|Valid|N.E.|Signed divide\htmlonly{*} r/m8 by 2, CL times.|
|C0 /7 ib|`SAR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Signed divide\htmlonly{*} r/m8 by 2, imm8 time.|
|REX + C0 /7 ib|`SAR` r/m8\htmlonly{*}\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Signed divide\htmlonly{*} r/m8 by 2, imm8 times.|
|D1 /7|`SAR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Signed divide\htmlonly{*} r/m16 by 2, once.|
|D3 /7|`SAR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Signed divide\htmlonly{*} r/m16 by 2, CL times.|
|C1 /7 ib|`SAR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Signed divide\htmlonly{*}\footnote{ } r/m16 by 2, imm8 times.|
|D1 /7|`SAR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Signed divide\htmlonly{*} r/m32 by 2, once.|
|REX.W + D1 /7|`SAR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Signed divide\htmlonly{*} r/m64 by 2, once.|
|D3 /7|`SAR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Signed divide\htmlonly{*}\footnote{ } r/m32 by 2, CL times.|
|REX.W + D3 /7|`SAR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Signed divide\htmlonly{*}\footnote{ } r/m64 by 2, CL times.|
|C1 /7 ib|`SAR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Signed divide\htmlonly{*}\footnote{ } r/m32 by 2, imm8 times.|
|REX.W + C1 /7 ib|`SAR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Signed divide\htmlonly{*}\footnote{ } r/m64 by 2, imm8 times|
|D0 /4|`SHL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Multiply r/m8 by 2, once.|
|REX + D0 /4|`SHL` r/m8\htmlonly{*}\htmlonly{*} 1 |M1|Valid|N.E.|Multiply r/m8 by 2, once.|
|D2 /4|`SHL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Multiply r/m8 by 2, CL times.|
|REX + D2 /4|`SHL` r/m8\htmlonly{*}\htmlonly{*} CL |MC|Valid|N.E.|Multiply r/m8 by 2, CL times.|
|C0 /4 ib|`SHL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Multiply r/m8 by 2, imm8 times.|
|REX + C0 /4 ib|`SHL` r/m8\htmlonly{*}\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Multiply r/m8 by 2, imm8 times.|
|D1 /4|`SHL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Multiply r/m16 by 2, once.|
|D3 /4|`SHL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Multiply r/m16 by 2, CL times.|
|C1 /4 ib|`SHL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Multiply r/m16 by 2, imm8 times.|
|D1 /4|`SHL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Multiply r/m32 by 2, once.|


|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|REX.W + D1 /4|`SHL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Multiply r/m64 by 2, once.|
|D3 /4|`SHL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Multiply r/m32 by 2, CL times.|
|REX.W + D3 /4|`SHL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Multiply r/m64 by 2, CL times.|
|C1 /4 ib|`SHL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Multiply r/m32 by 2, imm8 times.|
|REX.W + C1 /4 ib|`SHL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Multiply r/m64 by 2, imm8 times.|
|D0 /5|`SHR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Unsigned divide r/m8 by 2, once.|
|REX + D0 /5|`SHR` r/m8\htmlonly{*}\htmlonly{*} 1 |M1|Valid|N.E.|Unsigned divide r/m8 by 2, once.|
|D2 /5|`SHR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Unsigned divide r/m8 by 2, CL times.|
|REX + D2 /5|`SHR` r/m8\htmlonly{*}\htmlonly{*} CL |MC|Valid|N.E.|Unsigned divide r/m8 by 2, CL times.|
|C0 /5 ib|`SHR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Unsigned divide r/m8 by 2, imm8 times.|
|REX + C0 /5 ib|`SHR` r/m8\htmlonly{*}\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Unsigned divide r/m8 by 2, imm8 times.|
|D1 /5|`SHR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Unsigned divide r/m16 by 2, once.|
|D3 /5|`SHR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Unsigned divide r/m16 by 2, CL times|
|C1 /5 ib|`SHR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Unsigned divide r/m16 by 2, imm8 times.|
|D1 /5|`SHR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Unsigned divide r/m32 by 2, once.|
|REX.W + D1 /5|`SHR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Unsigned divide r/m64 by 2, once.|
|D3 /5|`SHR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Unsigned divide r/m32 by 2, CL times.|
|REX.W + D3 /5|`SHR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Unsigned divide r/m64 by 2, CL times.|
|C1 /5 ib|`SHR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Unsigned divide r/m32 by 2, imm8 times.|
|REX.W + C1 /5 ib|`SHR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |N.E.|Unsigned divide r/m64 by 2, imm8 times.|

```note
\htmlonly{*} Not the same form of division as IDIV; rounding is toward negative infinity.

\htmlonly{*}\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.

\htmlonly{*}\htmlonly{*}\htmlonly{*}See IA-32 Architecture Compatibility section below
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M1|ModRM:r/m (r, w)|1|NA|NA|
|MC|ModRM:r/m (r, w)|CL|NA|NA|
|MI|ModRM:r/m (r, w)|imm8|NA|NA|
### Description


Shifts the bits in the first operand (destination operand) to the left or right by the number of bits specified in the second operand (count operand). Bits shifted beyond the destination operand boundary are first shifted into the CF flag, then discarded. At the end of the shift operation, the CF flag contains the last bit shifted out of the destination operand. 

The destination operand can be a register or a memory location. The count operand can be an immediate value or the CL register. The count is masked to 5 bits (or 6 bits if in 64-bit mode and REX.W is used). The count range is limited to 0 to 31 (or 63 if 64-bit mode and REX.W is used). A special opcode encoding is provided for a count of 1.

The shift arithmetic left (SAL) and shift logical left (SHL) instructions perform the same operation; they shift the bits in the destination operand to the left (toward more significant bit locations). For each shift count, the most significant bit of the destination operand is shifted into the CF flag, and the least significant bit is cleared (see Figure 7-7 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1).



The shift arithmetic right (SAR) and shift logical right (SHR) instructions shift the bits of the destination operand to the right (toward less significant bit locations). For each shift count, the least significant bit of the destination operand is shifted into the CF flag, and the most significant bit is either set or cleared depending on the instruction type. The `SHR` instruction clears the most significant bit (see Figure 7-8 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1); the `SAR` instruction sets or clears the most significant bit to correspond to the sign (most significant bit) of the original value in the destination operand. In effect, the `SAR` instruction fills the empty bit position's shifted value with the sign of the unshifted value (see Figure 7-9 in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1).

The `SAR` and `SHR` instructions can be used to perform signed or unsigned division, respectively, of the destination operand by powers of 2. For example, using the `SAR` instruction to shift a signed integer 1 bit to the right divides the value by 2.

Using the `SAR` instruction to perform a division operation does not produce the same result as the `IDIV` instruction. The quotient from the `IDIV` instruction is rounded toward zero, whereas the "quotient" of the `SAR` instruction is rounded toward negative infinity. This difference is apparent only for negative numbers. For example, when the `IDIV` instruction is used to divide -9 by 4, the result is -2 with a remainder of -1. If the `SAR` instruction is used to shift -9 right by two bits, the result is -3 and the "remainder" is +3; however, the `SAR` instruction stores only the most significant bit of the remainder (in the CF flag). 

The OF flag is affected only on 1-bit shifts. For left shifts, the OF flag is set to 0 if the most-significant bit of the result is the same as the CF flag (that is, the top two bits of the original operand were the same); otherwise, it is set to 1. For the `SAR` instruction, the OF flag is cleared for all 1-bit shifts. For the `SHR` instruction, the OF flag is set to the most-significant bit of the original operand.

In 64-bit mode, the instruction's default operation size is 32 bits and the mask width for CL is 5 bits. Using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). Using a REX prefix in the form of REX.W promotes operation to 64-bits and sets the mask width for CL to 6 bits. See the summary chart at the beginning of this section for encoding data and limits.

### IA-32 Architecture Compatibility


The 8086 does not mask the shift count. However, all other IA-32 processors (starting with the Intel 286 processor) do mask the shift count to 5 bits, resulting in a maximum count of 31. This masking is done in all operating modes (including the virtual-8086 mode) to reduce the maximum execution time of the instructions.


### Operation

```info-verb
IF 64-Bit Mode and using REX.W
    THEN
          countMASK <- 3FH;
    ELSE
          countMASK <- 1FH;
FI
tempCOUNT <- (COUNT AND countMASK);
tempDEST <- DEST;
WHILE (tempCOUNT != 0)
DO
    IF instruction is SAL or SHL
          THEN 
                CF <- MSB(DEST);
          ELSE (* Instruction is SAR or SHR *)
                CF <- LSB(DEST);
    FI;
    IF instruction is SAL or SHL
          THEN 
                DEST <- DEST `*` 2;
          ELSE 
                IF instruction is SAR
THEN 
                            DEST <- DEST / 2; (* Signed divide, rounding toward negative infinity *)
                      ELSE (* Instruction is SHR *)
                            DEST <- DEST / 2 ; (* Unsigned divide *)
                FI;
    FI;
    tempCOUNT <- tempCOUNT - 1;
OD;
(* Determine overflow for the various instructions *)
IF (COUNT and countMASK) = 1
    THEN
          IF instruction is SAL or SHL
                THEN 
                      OF <- MSB(DEST) XOR CF;
                ELSE 
                      IF instruction is SAR
                            THEN 
                                  OF <- 0;
                            ELSE (* Instruction is SHR *)
                                  OF <- MSB(tempDEST);
                      FI;
          FI;
    ELSE IF (COUNT AND countMASK) = 0
          THEN
                All flags unchanged;
          ELSE (* COUNT not 1 or 0 *)
                OF <- undefined;
    FI;
FI;
```
### Flags Affected


The CF flag contains the value of the last bit shifted out of the destination operand; it is undefined for SHL and SHR instructions where the count is greater than or equal to the size (in bits) of the destination operand. The OF flag is affected only for 1-bit shifts (see "Description" above); otherwise, it is undefined. The SF, ZF, and PF flags are set according to the result. If the count is 0, the flags are not affected. For a non-zero count, the AF flag is undefined.


### Protected Mode Exceptions

#### #GP(0)
* If the destination is located in a non-writable segment.
* If a memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the DS, ES, FS, or GS register contains a NULL segment selector.

#### #SS(0)
* If a memory operand effective address is outside the SS segment limit.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

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

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made.

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

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
