----------------------------
title : RCL, RCR, ROL, RORs (Intel x86/64 assembly instruction)
cat_title : RCL, RCR, ROL, ROR
ref_title : RCL, RCR, ROL, ROR
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/R
publish_date: 2020-09-01
----------------------------


#@ RCL, RCR, ROL, ROR

**Rotate**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode\htmlonly{*}\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|D0 /2|`RCL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 9 bits (CF, r/m8) left once.|
|REX + D0 /2|`RCL` r/m8\htmlonly{*} 1 |M1|Valid|N.E.|Rotate 9 bits (CF, r/m8) left once. |
|D2 /2|`RCL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 9 bits (CF, r/m8) left CL times. |
|REX + D2 /2|`RCL` r/m8\htmlonly{*} CL |MC|Valid|N.E.|Rotate 9 bits (CF, r/m8) left CL times. |
|C0 /2 ib|`RCL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 9 bits (CF, r/m8) left imm8 times.|
|REX + C0 /2 ib|`RCL` r/m8\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 9 bits (CF, r/m8) left imm8 times.|
|D1 /2|`RCL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 17 bits (CF, r/m16) left once.|
|D3 /2|`RCL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 17 bits (CF, r/m16) left CL times.|
|C1 /2 ib|`RCL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 17 bits (CF, r/m16) left imm8 times.|
|D1 /2|`RCL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Rotate 33 bits (CF, r/m32) left once.|
|REX.W + D1 /2|`RCL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Rotate 65 bits (CF, r/m64) left once. Uses a 6 bit count.|
|D3 /2|`RCL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Rotate 33 bits (CF, r/m32) left CL times.|
|REX.W + D3 /2|`RCL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Rotate 65 bits (CF, r/m64) left CL times. Uses a 6 bit count.|
|C1 /2 ib|`RCL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 33 bits (CF, r/m32) left imm8 times.|
|REX.W + C1 /2 ib|`RCL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 65 bits (CF, r/m64) left imm8 times. Uses a 6 bit count.|
|D0 /3|`RCR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 9 bits (CF, r/m8) right once. |
|REX + D0 /3|`RCR` r/m8\htmlonly{*} 1 |M1|Valid|N.E.|Rotate 9 bits (CF, r/m8) right once. |
|D2 /3|`RCR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 9 bits (CF, r/m8) right CL times. |
|REX + D2 /3|`RCR` r/m8\htmlonly{*} CL |MC|Valid|N.E.|Rotate 9 bits (CF, r/m8) right CL times. |
|C0 /3 ib|`RCR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 9 bits (CF, r/m8) right imm8 times. |
|REX + C0 /3 ib|`RCR` r/m8\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 9 bits (CF, r/m8) right imm8 times. |
|D1 /3|`RCR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 17 bits (CF, r/m16) right once.|
|D3 /3|`RCR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 17 bits (CF, r/m16) right CL times.|
|C1 /3 ib|`RCR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 17 bits (CF, r/m16) right imm8 times.|
|D1 /3|`RCR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Rotate 33 bits (CF, r/m32) right once. Uses a 6 bit count.|
|REX.W + D1 /3|`RCR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Rotate 65 bits (CF, r/m64) right once. Uses a 6 bit count.|
|D3 /3|`RCR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Rotate 33 bits (CF, r/m32) right CL times.|
|REX.W + D3 /3|`RCR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Rotate 65 bits (CF, r/m64) right CL times. Uses a 6 bit count.|
|C1 /3 ib|`RCR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 33 bits (CF, r/m32) right imm8 times.|
|REX.W + C1 /3 ib|`RCR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 65 bits (CF, r/m64) right imm8 times. Uses a 6 bit count.|
|D0 /0|`ROL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 8 bits r/m8 left once.|
|REX + D0 /0|`ROL` r/m8\htmlonly{*} 1 |M1|Valid|N.E.|Rotate 8 bits r/m8 left once|
|D2 /0|`ROL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 8 bits r/m8 left CL times.|
|REX + D2 /0|`ROL` r/m8\htmlonly{*} CL |MC|Valid|N.E.|Rotate 8 bits r/m8 left CL times.|
|C0 /0 ib|`ROL` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 8 bits r/m8 left imm8 times.|


|**Opcode\htmlonly{*}\htmlonly{*}**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------------------------------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|REX + C0 /0 ib|`ROL` r/m8\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 8 bits r/m8 left imm8 times.|
|D1 /0|`ROL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 16 bits r/m16 left once.|
|D3 /0|`ROL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 16 bits r/m16 left CL times.|
|C1 /0 ib|`ROL` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 16 bits r/m16 left imm8 times.|
|D1 /0|`ROL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Rotate 32 bits r/m32 left once.|
|REX.W + D1 /0|`ROL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Rotate 64 bits r/m64 left once. Uses a 6 bit count.|
|D3 /0|`ROL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Rotate 32 bits r/m32 left CL times.|
|REX.W + D3 /0|`ROL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Rotate 64 bits r/m64 left CL times. Uses a 6 bit count.|
|C1 /0 ib|`ROL` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 32 bits r/m32 left imm8 times.|
|REX.W + C1 /0 ib|`ROL` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 64 bits r/m64 left imm8 times. Uses a 6 bit count.|
|D0 /1|`ROR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 8 bits r/m8 right once.|
|REX + D0 /1|`ROR` r/m8\htmlonly{*} 1 |M1|Valid|N.E.|Rotate 8 bits r/m8 right once.|
|D2 /1|`ROR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 8 bits r/m8 right CL times.|
|REX + D2 /1|`ROR` r/m8\htmlonly{*} CL |MC|Valid|N.E.|Rotate 8 bits r/m8 right CL times.|
|C0 /1 ib|`ROR` \tooltip{r/m8}{1 바이트 짜리 피연산자로, 1 바이트 범용 레지스터나 (r8 의 레지스터들), 1 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 8 bits r/m16 right imm8 times.|
|REX + C0 /1 ib|`ROR` r/m8\htmlonly{*} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid|N.E.|Rotate 8 bits r/m16 right imm8 times.|
|D1 /1|`ROR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } 1 |M1|Valid |Valid|Rotate 16 bits r/m16 right once.|
|D3 /1|`ROR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } CL |MC|Valid |Valid|Rotate 16 bits r/m16 right CL times.|
|C1 /1 ib|`ROR` \tooltip{r/m16}{2 바이트 짜리 피연산자로, 2 바이트 범용 레지스터나 (r16 의 레지스터들), 2 바이트 메모리 데이터를 의미한다. } \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 16 bits r/m16 right imm8 times.|
|D1 /1|`ROR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid |Valid|Rotate 32 bits r/m32 right once.|
|REX.W + D1 /1|`ROR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} 1 |M1|Valid|N.E.|Rotate 64 bits r/m64 right once. Uses a 6 bit count.|
|D3 /1|`ROR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} CL |MC|Valid |Valid|Rotate 32 bits r/m32 right CL times.|
|REX.W + D3 /1|`ROR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} CL |MC|Valid|N.E.|Rotate 64 bits r/m64 right CL times. Uses a 6 bit count.|
|C1 /1 ib|`ROR` \tooltip{r/m32}{4 바이트 짜리 피연산자로, 4 바이트 범용 레지스터나 (r32 의 레지스터들), 4 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |Valid|Rotate 32 bits r/m32 right imm8 times.|
|REX.W + C1 /1 ib|`ROR` \tooltip{r/m64}{8 바이트 짜리 피연산자로, 8 바이트 범용 레지스터나 (r64 의 레지스터들), 8 바이트 메모리 데이터를 의미한다.} \tooltip{imm8}{1 바이트 짜리 명시적 데이터 (immediate value). imm8 의 경우 부호 있는 정수를 의미하며, -128 부터 127 까지의 값을 표현할 수 있다. 참고로 만일 imm8 이 1 바이트 보다 큰 피연산자를 가지는 명령어와 사용될 경우, 명시적 데이터는 부호를 유지한채 해당 크기로 확장이 된다. (쉽게 말해 0b11000000 은 0b11111111 11000000 로 확장되며 0b00110000 은 0b00000000 00110000 으로 확장된다.)} |MI|Valid |N.E.|Rotate 64 bits r/m64 right imm8 times. Uses a 6 bit count.|

```note
\htmlonly{*} In 64-bit mode, r/m8 can not be encoded to access the following byte registers if a REX prefix is used: AH, BH, CH, DH.

\htmlonly{*}\htmlonly{*}See IA-32 Architecture Compatibility section below
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|M1|ModRM:r/m (w)|1|NA|NA|
|MC|ModRM:r/m (w)|CL|NA|NA|
|MI|ModRM:r/m (w)|imm8|NA|NA|
### Description


Shifts (rotates) the bits of the first operand (destination operand) the number of bit positions specified in the second operand (count operand) and stores the result in the destination operand. The destination operand can be a register or a memory location; the count operand is an unsigned integer that can be an immediate or a value in the CL register. The count is masked to 5 bits (or 6 bits if in 64-bit mode and REX.W = 1).

The rotate left (ROL) and rotate through carry left (RCL) instructions shift all the bits toward more-significant bit positions, except for the most-significant bit, which is rotated to the least-significant bit location. The rotate right (ROR) and rotate through carry right (RCR) instructions shift all the bits toward less significant bit positions, except for the least-significant bit, which is rotated to the most-significant bit location.

The `RCL` and `RCR` instructions include the CF flag in the rotation. The `RCL` instruction shifts the CF flag into the least-significant bit and shifts the most-significant bit into the CF flag. The `RCR` instruction shifts the CF flag into the most-significant bit and shifts the least-significant bit into the CF flag. For the `ROL` and `ROR` instructions, the original value of the CF flag is not a part of the result, but the CF flag receives a copy of the bit that was shifted from one end to the other.

The OF flag is defined only for the 1-bit rotates; it is undefined in all other cases (except `RCL` and `RCR` instructions only: a zero-bit rotate does nothing, that is affects no flags). For left rotates, the OF flag is set to the exclusive `OR` of the CF bit (after the rotate) and the most-significant bit of the result. For right rotates, the OF flag is set to the exclusive `OR` of the two most-significant bits of the result.

In 64-bit mode, using a REX prefix in the form of REX.R permits access to additional registers (R8-R15). Use of REX.W promotes the first operand to 64 bits and causes the count operand to become a 6-bit counter.

### IA-32 Architecture Compatibility


The 8086 does not mask the rotation count. However, all other IA-32 processors (starting with the Intel 286 processor) do mask the rotation count to 5 bits, resulting in a maximum count of 31. This masking is done in all operating modes (including the virtual-8086 mode) to reduce the maximum execution time of the instructions.


### Operation

```info-verb
(* RCL and RCR instructions *)
SIZE <- OperandSize;
CASE (determine count) OF
    SIZE <- 8: tempCOUNT <- (COUNT AND 1FH) MOD 9;
    SIZE <- 16: tempCOUNT <- (COUNT AND 1FH) MOD 17;
    SIZE <- 32: tempCOUNT <- COUNT AND 1FH;
    SIZE <- 64: tempCOUNT <- COUNT AND 3FH;
ESAC;
(* RCL instruction operation *)
WHILE (tempCOUNT != 0)
    DO
          tempCF <- MSB(DEST);
          DEST <- (DEST `*` 2) + CF;
          CF <- tempCF;
          tempCOUNT <- tempCOUNT - 1;
    OD;
ELIHW;
IF (COUNT & COUNTMASK) = 1
    THEN OF <- MSB(DEST) XOR CF;
    ELSE OF is undefined;
FI;
(* RCR instruction operation *)
IF (COUNT & COUNTMASK) = 1
    THEN OF <- MSB(DEST) XOR CF;
    ELSE OF is undefined;
FI;
WHILE (tempCOUNT != 0)
    DO
          tempCF <- LSB(SRC);
          DEST <- (DEST / 2) + (CF * 2\footnote{SIZE} );
          CF <- tempCF;
          tempCOUNT <- tempCOUNT - 1;
    OD;
(* ROL and ROR instructions *)
IF OperandSize = 64
    THEN COUNTMASK = 3FH;
    ELSE COUNTMASK = 1FH;
FI;
(* ROL instruction operation *)
tempCOUNT <- (COUNT & COUNTMASK) MOD SIZE
WHILE (tempCOUNT != 0)
    DO
          tempCF <- MSB(DEST);
          DEST <- (DEST `*` 2) + tempCF;
          tempCOUNT <- tempCOUNT - 1;
    OD;
ELIHW;
IF (COUNT & COUNTMASK) ->  0
    THEN CF <- LSB(DEST);
FI;
IF (COUNT & COUNTMASK) = 1
    THEN OF <- MSB(DEST) XOR CF;
    ELSE OF is undefined;
FI;
(* ROR instruction operation *)
tempCOUNT <- (COUNT & COUNTMASK) MOD SIZE
WHILE (tempCOUNT != 0)
    DO
          tempCF <- LSB(SRC);
          DEST <- (DEST / 2) + (tempCF `*` 2\footnote{SIZE} );
          tempCOUNT <- tempCOUNT - 1;
    OD;
ELIHW;
IF (COUNT & COUNTMASK) ->  0
    THEN CF <- MSB(DEST);
FI;
IF (COUNT & COUNTMASK) = 1
    THEN OF <- MSB(DEST) XOR MSB - 1(DEST);
    ELSE OF is undefined;
FI;
```
### Flags Affected


If the masked count is 0, the flags are not affected. If the masked count is 1, then the OF flag is affected, otherwise (masked count is greater than 1) the OF flag is undefined. The CF flag is affected when the masked count is non-zero. The SF, ZF, AF, and PF flags are always unaffected.


### Protected Mode Exceptions

#### #GP(0)
* If the source operand is located in a non-writable segment.
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
* If the source operand is located in a nonwritable segment.
* If the memory address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
