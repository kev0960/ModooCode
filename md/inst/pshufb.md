----------------------------
title : PSHUFB (Intel x86/64 assembly instruction)
cat_title : PSHUFB
ref_title : PSHUFB
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ PSHUFB

** Packed Shuffle Bytes**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|`0F 38 00 /r\footnote{1 }`\newline{}`PSHUFB` mm1 mm2/m64 |RM|V/V|SSSE3|Shuffle bytes in mm1 according to contents of mm2/m64. |
|`66 0F 38 00 /r `\newline{}`PSHUFB` \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RM|V/V|SSSE3|Shuffle bytes in xmm1 according to contents of xmm2/m128.|
|`VEX.NDS.128.66.0F38.WIG 00 /r`\newline{}VPSHUFB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |RVM|V/V|AVX|Shuffle bytes in xmm2 according to contents of xmm3/m128.|
|`VEX.NDS.256.66.0F38.WIG 00 /r`\newline{}VPSHUFB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |RVM|V/V|AVX2|Shuffle bytes in ymm2 according to contents of ymm3/m256.|
|`EVEX.NDS.128.66.0F38.WIG 00 /r`\newline{}VPSHUFB \tooltip{xmm1}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{xmm2}{128 비트 XMM 레지스터로 XMM0 부터 XMM7 까지 있다. 64 비트 모드에서는 XMM8 부터 XMM15 까지 추가적으로 사용할 수 있다.} \tooltip{xmm3/m128}{128 비트 XMM 레지스터 혹은 128 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Shuffle bytes in xmm2 according to contents of xmm3/m128 under write mask k1.|
|`EVEX.NDS.256.66.0F38.WIG 00 /r`\newline{}VPSHUFB \tooltip{ymm1}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} \tooltip{ymm2}{256 비트 YMM 레지스터로 YMM0 부터 YMM7 까지 있다. 64 비트 모드에서는 YMM8 부터 YMM15 까지 추가적으로 사용할 수 있다.} \tooltip{ymm3/m256}{YMM 레지스터나 256 비트 메모리 데이터.} |FVM|V/V|AVX512VL\newline{}AVX512BW|Shuffle bytes in ymm2 according to contents of ymm3/m256 under write mask k1.|
|`EVEX.NDS.512.66.0F38.WIG 00 /r`\newline{}VPSHUFB zmm1 \tooltip{\{k1\}\{z\}}{쓰기 마스크 (write mask) 레지스터로 64 비트 k 레지스터로 k1 부터 k7 까지 사용 가능하다. 쓰기 마스크는 오직 EVEX 접두사가 있을 경우에만 사용 가능하다. 마스크 방식으로 마스크 되지 않는 부분의 값을 유지하는 병합 마스크 (merge mask) 가 있고, 해당 부분을 아예 0 으로 지워버리는 zeroing mask 방식이 있다. 어떤 식으로 마스크를 할 지는 EVEX.z 필드의 비트값에 따라 달라진다.} zmm2 \tooltip{zmm3/m512}{ZMM 레지스터나 512 비트 메모리 데이터.} |FVM|V/V|AVX512BW|Shuffle bytes in zmm2 according to contents of zmm3/m512 under write mask k1.|

```note
1. See note in Section 2.4, "AVX and SSE Instruction Exception Specification" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 2A and Section 22.25.3, "Exception Conditions of Legacy SIMD Instructions Operating on MMX Registers" in the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3A
```
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RM|ModRM:reg (r, w)|ModRM:r/m (r)|NA|NA|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|FVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


PSHUFB performs in-place shuffles of bytes in the destination operand (the first operand) according to the shuffle control mask in the source operand (the second operand). The instruction permutes the data in the destination operand, leaving the shuffle mask unaffected. If the most significant bit (bit[7]) of each byte of the shuffle control mask is set, then constant zero is written in the result byte. Each byte in the shuffle control mask forms an index to permute the corresponding byte in the destination operand. The value of each index is the least significant 4 bits (128-bit operation) or 3 bits (64-bit operation) of the shuffle control byte. When the source operand is a 128-bit memory operand, the operand must be aligned on a 16-byte boundary or a general-protection exception (#GP) will be generated. 

In 64-bit mode and not encoded with VEX/EVEX, use the REX prefix to access XMM8-XMM15 registers. 

Legacy SSE version 64-bit operand: Both operands can be MMX registers.

128-bit Legacy SSE version: The first source operand and the destination operand are the same. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The destination operand is the first operand, the first source operand is the second operand, the second source operand is the third operand. Bits (VLMAX-1:128) of the destination YMM register are zeroed. 

VEX.256 encoded version: Bits (255:128) of the destination YMM register stores the 16-byte shuffle result of the upper 16 bytes of the first source operand, using the upper 16-bytes of the second source operand as control mask. 



The value of each index is for the high 128-bit lane is the least significant 4 bits of the respective shuffle control byte. The index value selects a source data element within each 128-bit lane.

EVEX encoded version: The second source operand is an ZMM/YMM/XMM register or an 512/256/128-bit memory location. The first source operand and destination operands are ZMM/YMM/XMM registers. The destination is condi-tionally updated with writemask k1.

EVEX and VEX encoded version: Four/two in-lane 128-bit shuffles.

### Operation 


**PSHUFB (with 64 bit operands)**

TEMP <- DEST

for i = 0 to 7 { 

    if (SRC[(i \htmlonly{*} 8)+7] = 1 ) then

          DEST[(i\htmlonly{*}8)+7...(i\htmlonly{*}8)+0] <- 0;

    else 

          index[2..0] <- SRC[(i\htmlonly{*}8)+2 .. (i\htmlonly{*}8)+0];

          DEST[(i\htmlonly{*}8)+7...(i\htmlonly{*}8)+0] <- TEMP[(index\htmlonly{*}8+7)..(index\htmlonly{*}8+0)];

    endif;

}

**PSHUFB (with 128 bit operands)**

TEMP <- DEST

for i = 0 to 15 { 

    if (SRC[(i \htmlonly{*} 8)+7] = 1 ) then

          DEST[(i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <- 0;

     else index[3..0] <- SRC[(i\htmlonly{*}8)+3 .. (i\htmlonly{*}8)+0];DEST[(i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <- TEMP[(index\htmlonly{*}8+7)..(index\htmlonly{*}8+0)];

    endif

}

**VPSHUFB (VEX.128 encoded version)**

for i = 0 to 15 {

    if (SRC2[(i \htmlonly{*} 8)+7] = 1) then

          DEST[(i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <-  0;

          else

          index[3..0] <-  SRC2[(i\htmlonly{*}8)+3 .. (i\htmlonly{*}8)+0];

          DEST[(i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <-  SRC1[(index\htmlonly{*}8+7)..(index\htmlonly{*}8+0)];

    endif

}

DEST[VLMAX-1:128] <-  0

**VPSHUFB (VEX.256 encoded version)**

for i = 0 to 15 {

    if (SRC2[(i \htmlonly{*} 8)+7] == 1 ) then

          DEST[(i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <-  0;

          else

          index[3..0] <-  SRC2[(i\htmlonly{*}8)+3 .. (i\htmlonly{*}8)+0];

          DEST[(i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <-  SRC1[(index\htmlonly{*}8+7)..(index\htmlonly{*}8+0)];

    endif

    if (SRC2[128 + (i \htmlonly{*} 8)+7] == 1 ) then

          DEST[128 + (i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <-  0;

          else

          index[3..0] <-  SRC2[128 + (i\htmlonly{*}8)+3 .. (i\htmlonly{*}8)+0];

          DEST[128 + (i\htmlonly{*}8)+7..(i\htmlonly{*}8)+0] <-  SRC1[128 + (index\htmlonly{*}8+7)..(index\htmlonly{*}8+0)];



endif

}

**VPSHUFB (EVEX encoded versions)**

(KL, VL) = (16, 128), (32, 256), (64, 512)

jmask <-  (KL-1) & ~0xF  // 0x00, 0x10, 0x30 depending on the VL

FOR j = 0 TO KL-1 // dest

    IF kl[ i ] or no_masking

          index <-  src.byte[ j ];

          IF index & 0x80

                Dest.byte[ j ] <-  0;

          ELSE

                index <-  (index & 0xF) + (j & jmask); // 16-element in-lane lookup

                Dest.byte[ j ] <-  src.byte[ index ];

    ELSE if zeroing

          Dest.byte[ j ] <-  0;

DEST[MAX_VL-1:VL] <-  0;

```embed
<figure>
<svg viewBox="0 0 383.760010 221.359985">
<rect x="0.000000" y="10.000000" width="0.480000" height="168.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="383.279999" y="10.000000" width="0.479980" height="168.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="383.760010" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="178.119995" width="383.760010" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="5.820000" y="22.959991" width="369.119995" height="151.559998" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<path d="M8.967003,135.097992 L10.098000,136.229980" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.812012,40.984009 L8.971008,40.984009" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.812012,65.929016 L8.971008,65.929016" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M99.678009,40.985016 L99.678009,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M54.323013,40.985016 L54.323013,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.811035,40.985016 L371.811035,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M326.455048,40.985016 L326.455048,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M145.034042,40.985016 L145.034042,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M190.390045,40.985016 L190.390045,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M235.745056,40.985016 L235.745056,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M281.101044,40.985016 L281.101044,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M8.969055,40.985016 L8.969055,65.930023" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.814056,80.670013 L8.973053,80.670013" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.814056,105.615021 L8.973053,105.615021" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M99.680054,80.671021 L99.680054,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M54.325058,80.671021 L54.325058,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.813049,80.671021 L371.813049,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M326.457062,80.671021 L326.457062,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M145.036057,80.671021 L145.036057,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M190.392059,80.671021 L190.392059,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M235.747070,80.671021 L235.747070,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M281.103058,80.671021 L281.103058,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M8.971069,80.671021 L8.971069,105.616028" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.816071,133.962006 L8.975067,133.962006" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.816071,158.907990 L8.975067,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M99.682068,133.962982 L99.682068,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M54.327072,133.962982 L54.327072,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M371.815063,133.962982 L371.815063,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M326.459076,133.962982 L326.459076,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M145.038071,133.962982 L145.038071,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M190.394073,133.962982 L190.394073,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M235.749084,133.962982 L235.749084,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M281.105072,133.962982 L281.105072,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M8.973083,133.962982 L8.973083,158.907990" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M303.778992,105.614014 L226.086975,131.170013" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M227.018005,133.997009 L217.606995,133.959015 L225.158020,128.342010 L227.018005,133.997009" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M321.755005,128.429016 L321.979004,128.245026 L349.132019,105.620026 L265.226013,133.965027" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M323.867004,130.545990 L315.079010,133.912994 L320.088013,125.946991 L323.867004,130.545990" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M349.135010,133.963989 L347.852997,106.688995" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M294.609009,124.036987 L275.554993,130.473999" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M276.507996,133.294006 L267.096985,133.332001 L274.601990,127.654999 L276.507996,133.294006" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M348.493011,120.360016 L348.890015,131.144012" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M351.096008,131.063995 L349.132019,137.764984 L346.682007,131.225983 L351.096008,131.063995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M72.462997,133.964996 L31.645996,105.619995 L31.645996,125.036987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M34.622009,125.036987 L31.646011,133.964996 L28.670013,125.036987 L34.622009,125.036987" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M59.533005,124.985992 L69.024002,130.592987" stoke="black"  stroke=" rgb(0,0,0) " fill="white" fill-opacity="0" />
<path d="M70.147995,128.692993 L74.727997,133.963989 L67.901993,132.494995 L70.147995,128.692993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M8.968002,169.114990 L12.368004,169.114990" stoke="black"  stroke=" rgb(255,255,255) " fill="white" fill-opacity="0" />
<path d="M11.176003,166.907013 L8.968002,169.115021 L11.176003,171.322998" stoke="black"  stroke=" rgb(255,255,255) " fill="white" fill-opacity="0" />
<path d="M371.812012,171.381012 L368.980011,171.381012" stoke="black"  stroke=" rgb(255,255,255) " fill="white" fill-opacity="0" />
<path d="M369.604004,173.588989 L371.812012,171.380981 L369.604004,169.173004" stoke="black"  stroke=" rgb(255,255,255) " fill="white" fill-opacity="0" />
<path d="M8.968002,33.049011 L12.368004,33.049011" stoke="black"  stroke=" rgb(255,255,255) " fill="white" fill-opacity="0" />
<path d="M11.176003,30.841003 L8.968002,33.049011 L11.176003,35.256989" stoke="black"  stroke=" rgb(255,255,255) " fill="white" fill-opacity="0" />
<text x="171.367279" y="131.099396" textLength="4.448112" font-size="8px">1</text>
<text x="164.703125" y="131.099396" textLength="6.664167" font-size="8px">M</text>
<text x="172.151306" y="35.449005" textLength="4.448112" font-size="8px">2</text>
<text x="165.487152" y="35.449005" textLength="6.664167" font-size="8px">M</text>
<text x="158.822998" y="35.449005" textLength="6.664167" font-size="8px">M</text>
<text x="343.000244" y="146.575317" textLength="4.448112" font-size="8px">1</text>
<text x="336.328064" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="334.104004" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="329.655884" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="325.207764" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="322.983704" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="316.311523" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="314.087463" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="294.966949" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="292.742889" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="279.398529" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="274.950409" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="272.726349" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="268.278229" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="263.830109" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="258.053955" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="253.605835" y="146.575317" textLength="4.448112" font-size="8px">1</text>
<text x="249.157715" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="244.709595" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="242.485535" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="240.261475" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="235.813354" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="231.365234" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="229.141174" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="226.917114" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="224.693054" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="204.692535" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="195.796295" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="191.348175" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="189.124115" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="184.675995" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="182.451935" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="175.779755" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="170.003601" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="158.883301" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="156.659241" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="154.435181" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="152.211121" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="149.987061" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="147.763000" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="145.538956" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="143.314896" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="141.090836" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="129.970535" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="110.850067" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="108.626007" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="106.401947" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="99.729767" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="95.281647" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="86.385406" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="84.161346" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="62.816818" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="60.592758" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="56.144638" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="53.920578" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="51.696518" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="49.472458" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="47.248398" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="41.472260" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="37.024155" y="146.575317" textLength="4.448112" font-size="8px">4</text>
<text x="345.184326" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="340.736206" y="94.414001" textLength="4.448112" font-size="8px">1</text>
<text x="336.288086" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="331.839966" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="327.391846" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="316.271545" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="303.823212" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="298.935089" y="94.414001" textLength="4.888123" font-size="8px">F</text>
<text x="294.046967" y="94.414001" textLength="4.888123" font-size="8px">F</text>
<text x="287.374786" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="282.926666" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="280.702606" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="276.254486" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="267.358246" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="262.910126" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="260.686066" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="306.087250" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="246.013672" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="241.565552" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="239.341492" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="237.117432" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="234.893372" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="230.445251" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="228.221191" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="225.997131" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="221.549011" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="211.324738" y="94.414001" textLength="4.448112" font-size="8px">2</text>
<text x="206.876617" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="197.980377" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="195.756317" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="189.084137" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="180.187897" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="175.739777" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="173.515717" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="167.739563" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="325.167786" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="156.619263" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="152.171143" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="145.498962" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="143.274902" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="141.050842" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="138.826782" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="134.378662" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="127.706482" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="119.706284" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="115.258179" y="94.414001" textLength="4.448112" font-size="8px">7</text>
<text x="110.810074" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="101.913834" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="99.689774" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="95.241653" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="206.916595" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="90.793533" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="88.569473" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="84.121353" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="81.897293" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="69.448990" y="94.414001" textLength="4.448112" font-size="8px">1</text>
<text x="56.104645" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="186.860077" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="53.880585" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="51.656525" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="30.311996" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="336.288116" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="136.642715" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="334.064056" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="331.839996" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="325.167816" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="320.719696" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="316.271576" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="314.047516" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="290.478882" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="288.254822" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="277.174469" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="286.030762" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="283.806702" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="279.358582" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="277.134521" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="268.238281" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="266.014221" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="251.341827" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="244.669647" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="242.445587" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="240.221527" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="235.773407" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="229.101227" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="226.877167" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="222.429047" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="309.599365" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="216.652893" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="201.084473" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="198.860413" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="192.188232" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="189.964172" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="185.516052" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="178.843872" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="174.395752" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="168.619598" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="164.171478" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="159.723358" y="53.692993" textLength="4.448112" font-size="8px">8</text>
<text x="155.275238" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="153.051178" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="148.603058" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="139.706818" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="137.482758" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="133.034637" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="120.586319" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="115.698196" y="53.692993" textLength="4.888123" font-size="8px">F</text>
<text x="110.810074" y="53.692993" textLength="4.888123" font-size="8px">F</text>
<text x="58.368698" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="104.137894" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="101.913834" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="88.569473" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="86.345413" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="84.121353" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="79.673233" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="130.810577" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="73.897095" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="65.000885" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="62.776825" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="56.104645" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="53.880585" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="49.432465" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="47.208405" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="44.984344" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="34.760101" y="53.692993" textLength="4.448112" font-size="8px">7</text>
<text x="30.311996" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="281.622589" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="311.823425" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="347.448364" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="303.823242" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="278.478546" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="202.468475" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="104.137894" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="320.759644" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="286.070709" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="157.499298" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="291.822906" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="281.582642" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="176.619812" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="81.937286" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="34.760101" y="94.414001" textLength="4.448112" font-size="8px">4</text>
<text x="172.151306" y="75.866028" textLength="4.448112" font-size="8px">1</text>
<text x="93.057587" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="73.897095" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="232.669312" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="65.040878" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="184.636017" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="327.391876" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="58.328705" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="71.713043" y="146.575317" textLength="4.448112" font-size="8px">4</text>
<text x="294.927002" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="250.461792" y="94.414001" textLength="4.448112" font-size="8px">2</text>
<text x="318.495605" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="132.154602" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="49.432465" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="187.740112" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="76.161148" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="193.572235" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="270.462341" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="272.686401" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="203.308533" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="289.598846" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="233.549347" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="129.930542" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="144.154938" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="202.428497" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="106.361954" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="108.586014" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="60.552765" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="204.652557" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="209.140656" y="146.575317" textLength="4.888123" font-size="8px">F</text>
<text x="101.953827" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="165.555481" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="198.020355" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="150.827118" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="270.502289" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="340.736237" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="224.653107" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="69.448990" y="53.692993" textLength="4.448112" font-size="8px">7</text>
<text x="177.963837" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="90.833527" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="223.773071" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="113.074127" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="207.756653" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="182.411957" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="67.264938" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="311.823456" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="44.984344" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="194.412292" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="60.552765" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="231.325287" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="104.177887" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="154.395203" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="183.291992" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="132.194595" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="214.028778" y="146.575317" textLength="4.888123" font-size="8px">F</text>
<text x="274.030426" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="79.673233" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="238.037415" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="149.947083" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="99.689774" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="215.772858" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="108.586014" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="329.615906" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="186.900055" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="90.793533" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="121.970337" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="327.431824" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="81.897293" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="97.465714" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="299.375122" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="191.308197" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="181.067932" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="39.208206" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="178.003815" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="158.822998" y="75.866028" textLength="6.664167" font-size="8px">M</text>
<text x="165.487152" y="75.866028" textLength="6.664167" font-size="8px">M</text>
<text x="127.746475" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="311.863403" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="285.150726" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="136.602722" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="97.465714" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="58.328705" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="180.227875" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="106.361954" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="331.879944" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="205.532593" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="263.790161" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="32.576050" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="345.184357" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="62.776825" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="39.208206" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="218.916901" y="146.575317" textLength="5.776145" font-size="8px">H</text>
<text x="309.599396" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="141.930878" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="47.208405" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="65.000885" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="88.609467" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="196.636353" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="117.522232" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="243.789612" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="297.191010" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="274.910461" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="318.535583" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="322.943726" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="318.495636" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="97.505707" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="265.134186" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="314.047485" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="95.241653" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="271.806366" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="161.107361" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="200.204437" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="261.566101" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="283.846649" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="93.017593" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="292.702942" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="237.997467" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="51.656525" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="322.943756" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="200.244415" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="93.017593" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="193.532257" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="290.518829" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="135.258698" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="233.589294" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="334.064026" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="254.909912" y="94.414001" textLength="5.776145" font-size="8px">H</text>
<text x="128.586517" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="288.294769" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="125.482422" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="147.723022" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="246.893707" y="53.692993" textLength="4.448112" font-size="8px">0</text>
<text x="301.639130" y="146.575317" textLength="4.448112" font-size="8px">1</text>
<text x="246.933655" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="158.038971" y="131.099396" textLength="6.664167" font-size="8px">M</text>
<text x="212.204773" y="53.692993" textLength="4.448112" font-size="8px">1</text>
<text x="163.291443" y="94.414001" textLength="4.448112" font-size="8px">3</text>
<text x="329.615936" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="158.843323" y="94.414001" textLength="4.448112" font-size="8px">0</text>
<text x="266.054169" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="320.719666" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="255.789948" y="53.692993" textLength="5.776145" font-size="8px">H</text>
<text x="134.418655" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="338.552124" y="146.575317" textLength="4.448112" font-size="8px">0</text>
<text x="146.378998" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="138.866776" y="146.575317" textLength="2.224056" font-size="8px"> </text>
<text x="269.582306" y="94.414001" textLength="2.224056" font-size="8px"> </text>
<text x="126.362457" y="53.692993" textLength="2.224056" font-size="8px"> </text>
<text x="86.345413" y="94.414001" textLength="2.224056" font-size="8px"> </text>
</svg>
<figcaption>Figure 4-15.  PSHUFB with 64-Bit Operands
</figcaption></figure>
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPSHUFB __m512i _mm512_shuffle_epi8(__m512i a, __m512i b);
VPSHUFB __m512i _mm512_mask_shuffle_epi8(__m512i s, __mmask64 k, __m512i a, __m512i b);
VPSHUFB __m512i _mm512_maskz_shuffle_epi8( __mmask64 k, __m512i a, __m512i b);
VPSHUFB __m256i _mm256_mask_shuffle_epi8(__m256i s, __mmask32 k, __m256i a, __m256i b);
VPSHUFB __m256i _mm256_maskz_shuffle_epi8( __mmask32 k, __m256i a, __m256i b);
VPSHUFB __m128i _mm_mask_shuffle_epi8(__m128i s, __mmask16 k, __m128i a, __m128i b);
VPSHUFB __m128i _mm_maskz_shuffle_epi8( __mmask16 k, __m128i a, __m128i b);
PSHUFB: __m64 _mm_shuffle_pi8 (__m64 a, __m64 b)
(V)PSHUFB: __m128i _mm_shuffle_epi8 (__m128i a, __m128i b)
VPSHUFB:__m256i _mm256_shuffle_epi8(__m256i a, __m256i b)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.nb.

