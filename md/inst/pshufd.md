### PSHUFD--Shuffle Packed Doublewords


|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 70 /r ib\newline{}PSHUFD xmm1, xmm2/m128, imm8|RMI|V/V| SSE2|Shuffle the doublewords in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.|
|VEX.128.66.0F.WIG 70 /r ib\newline{}VPSHUFD xmm1, xmm2/m128, imm8|RMI|V/V|AVX|Shuffle the doublewords in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.|
|VEX.256.66.0F.WIG 70 /r ib\newline{}VPSHUFD ymm1, ymm2/m256, imm8|RMI|V/V|AVX2|Shuffle the doublewords in ymm2/m256 based on the encoding in imm8 and store the result in ymm1.|
|EVEX.128.66.0F.W0 70 /r ibVPSHUFD xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FV|V/V|AVX512VLAVX512F|Shuffle the doublewords in xmm2/m128/m32bcst based on the encoding in imm8 and store the result in xmm1 using writemask k1.|
|EVEX.256.66.0F.W0 70 /r ibVPSHUFD ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FV|V/V|AVX512VLAVX512F|Shuffle the doublewords in ymm2/m256/m32bcst based on the encoding in imm8 and store the result in ymm1 using writemask k1.|
|EVEX.512.66.0F.W0 70 /r ibVPSHUFD zmm1 {k1}{z}, zmm2/m512/m32bcst, imm8|FV|V/V|AVX512F|Shuffle the doublewords in zmm2/m512/m32bcst based on the encoding in imm8 and store the result in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (w)|ModRM:r/m (r)|imm8|NA|
|FV|ModRM:reg (w)|ModRM:r/m (r)|Imm8|NA|
### Description


Copies doublewords from source operand (second operand) and inserts them in the destination operand (first operand) at the locations selected with the order operand (third operand). Figure 4-16 shows the operation of the 256-bit VPSHUFD instruction and the encoding of the order operand. Each 2-bit field in the order operand selects the contents of one doubleword location within a 128-bit lane and copy to the target element in the destination operand. For example, bits 0 and 1 of the order operand targets the first doubleword element in the low and high 128-bit lane of the destination operand for 256-bit VPSHUFD. The encoded value of bits 1:0 of the order operand (see the field encoding in Figure 4-16) determines which doubleword element (from the respective 128-bit lane) of the source operand will be copied to doubleword 0 of the destination operand. 

For 128-bit operation, only the low 128-bit lane are operative. The source operand can be an XMM register or a 128-bit memory location. The destination operand is an XMM register. The order operand is an 8-bit immediate. Note that this instruction permits a doubleword in the source operand to be copied to more than one doubleword location in the destination operand.

```embed
<figure>
<svg viewBox="0 0 317.219299 262.320007">
<rect x="25.319305" y="9.760010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="25.319305" y="9.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.439301" y="9.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="25.079300" y="27.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="25.079300" y="9.520020" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.679306" y="9.760010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="61.679306" y="9.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.799301" y="9.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.439301" y="27.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.439301" y="9.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="98.039291" y="9.760010" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="98.039291" y="9.520020" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.219315" y="9.760010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.799301" y="27.520020" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.799301" y="9.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.459305" y="9.760010" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.459305" y="9.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.579300" y="9.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.219315" y="27.520020" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.219315" y="9.520020" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="25.259308" y="62.920044" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="25.259308" y="62.680054" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.379303" y="62.920044" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="25.019302" y="80.680054" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="25.019302" y="62.680054" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.619308" y="62.920044" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="61.619308" y="62.680054" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.799301" y="62.920044" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.379303" y="80.680054" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="61.379303" y="62.680054" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="98.039291" y="62.920044" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="98.039291" y="62.680054" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.159317" y="62.920044" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.799301" y="80.680054" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="97.799301" y="62.680054" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.399307" y="62.920044" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="134.399307" y="62.680054" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.519302" y="62.920044" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.159317" y="80.680054" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.159317" y="62.680054" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.639282,55.420044 L308.159302,55.540039 L308.399292,56.560059 L308.879272,56.440063" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.339294,56.080017 L309.719299,55.179993 L310.619324,54.580017 L310.499329,55.660034 L310.139282,61.239990 L310.079285,63.040039 L309.239319,61.480042 L306.599304,56.559998 L306.059326,55.600037 L307.079285,55.780029 L307.439331,56.020020 L310.079285,60.940002 L309.239319,61.480042 L309.179321,61.179993 L309.539307,55.600037 L310.499329,55.660034 L310.319336,56.020020 L308.939331,56.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.079285,55.780029 L308.699280,56.020020 L308.939270,56.920044 L308.759277,57.040039 L308.579285,56.980042 L306.959290,56.740051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.639282,56.500000 L310.019287,55.599976 L309.659302,61.179993 L307.019287,56.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.819275,29.440002 L302.759277,29.200012 L302.279297,29.320007 L302.339294,29.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M308.639282,55.420044 L308.699280,55.660034 L308.219299,55.780029 L308.159302,55.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.819275,29.440002 L302.339294,29.559998 L308.159302,55.539978 L308.639282,55.419983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.279312" y="102.820007" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="209.039291" y="103.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.039291" y="120.820007" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.039291" y="102.820007" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.039291" y="102.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.039291" y="103.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.039291" y="102.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.039291" y="103.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="155.039291" y="102.820007" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="155.039291" y="103.059998" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.859314,83.200012 L295.979309,83.679993 L296.999329,83.500000 L296.879272,83.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.519287,83.559998 L295.679321,82.179993 L295.079285,81.279968 L296.159302,81.400024 L301.739319,81.820007 L303.479309,81.940002 L301.979309,82.719971 L296.999329,85.299988 L296.039307,85.840027 L296.219299,84.820007 L296.459290,84.460022 L301.439331,81.880005 L301.979309,82.719971 L301.679321,82.779968 L296.099304,82.359985 L296.159302,81.400024 L296.519287,81.580017 L297.359314,82.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.219299,84.820007 L296.459290,83.200012 L297.359314,82.960022 L297.479309,83.140015 L297.419312,83.320007 L297.179321,84.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.939331,83.260010 L296.099304,81.880005 L301.679321,82.299988 L296.699341,84.880005" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.739304,102.880005 L199.499313,102.940002 L199.619308,103.419983 L199.859299,103.359985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.859314,83.200012 L296.099304,83.140015 L296.219299,83.619995 L295.979309,83.679993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.739304,102.880005 L199.859299,103.359985 L295.979309,83.679993 L295.859314,83.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.239304,83.859985 L249.359299,84.339966 L250.319290,84.039978 L250.199295,83.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.839310,84.100037 L248.879318,82.780029 L248.219315,82.000061 L249.359299,81.940063 L254.939316,81.880066 L256.619324,81.940063 L255.179306,82.840027 L250.499313,85.840027 L249.659317,86.380066 L249.719315,85.420044 L249.959305,85.000061 L254.639297,82.000061 L255.179306,82.840027 L254.879318,82.900024 L249.299301,82.960022 L249.359299,81.940063 L249.719315,82.180054 L250.679306,83.500061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.719315,85.420044 L249.779312,83.800049 L250.679306,83.500061 L250.799301,83.620056 L250.799301,83.860046 L250.739304,85.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.259293,83.799988 L249.299301,82.479980 L254.879288,82.419983 L250.199295,85.419983" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.579300,103.420044 L182.339310,103.480042 L182.459305,103.960022 L182.699295,103.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.239304,83.859985 L249.479294,83.799988 L249.599289,84.279968 L249.359299,84.339966" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.579300,103.420044 L182.699295,103.900024 L249.359299,84.340027 L249.239304,83.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.739304,85.540039 L160.979294,85.060059 L160.019302,84.580017 L159.779312,85.060059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.439316,84.880005 L160.259323,86.500000 L160.199326,87.520020 L155.159317,83.200012 L153.839310,82.059998 L155.579330,82.299988 L161.099319,83.140015 L162.119308,83.320007 L161.399307,84.039978 L160.919327,84.160034 L155.459305,83.320007 L155.579330,82.299988 L155.819321,82.479980 L160.019302,86.080017 L159.359329,86.799988 L159.239304,86.320007 L159.419327,84.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.399307,84.040039 L160.259293,85.180054 L159.419296,84.700012 L159.419296,84.520020 L159.539322,84.460022 L160.679306,83.320068" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M159.899307,84.820007 L159.719315,86.440002 L155.519302,82.840027 L161.039322,83.679993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M197.759293,102.580017 L197.939285,102.640015 L198.119278,102.220032 L197.939285,102.160034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.799301,85.540039 L160.619308,85.480042 L160.799301,85.060059 L160.979294,85.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M197.759293,102.580017 L197.939285,102.160034 L160.979294,85.119995 L160.799301,85.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M128.339310,86.380005 L128.459305,85.900024 L127.439316,85.599976 L127.319321,86.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M127.919296,85.840027 L127.979294,87.460022 L128.039291,88.480042 L127.139297,87.880005 L122.459305,84.820007 L120.959305,83.860046 L122.759293,83.860046 L128.339310,83.980042 L129.299301,83.980042 L128.759293,84.760010 L128.339310,85.000000 L122.759293,84.880005 L122.759293,83.860046 L122.999283,83.980042 L127.679306,87.040039 L127.139297,87.880005 L126.899307,87.460022 L126.839310,85.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M128.759293,84.760010 L127.799301,86.080017 L126.839279,85.840027 L126.839279,85.660034 L126.959305,85.540039 L127.919296,84.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M127.379318,85.840027 L127.439316,87.460022 L122.759323,84.400024 L128.339310,84.520020" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M180.359299,102.580017 L180.599289,102.640015 L180.719284,102.160034 L180.479294,102.100037" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M128.339310,86.380005 L128.099319,86.320007 L128.219315,85.840027 L128.459305,85.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M180.359299,102.580017 L180.479294,102.100037 L128.459305,85.900024 L128.339310,86.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.979309,56.080017 L301.619324,56.440002 L302.459290,57.100037 L302.819275,56.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.159302,56.739990 L302.699341,55.179993 L302.999329,54.219971 L303.599304,55.119995 L306.719299,59.739990 L307.739319,61.179993 L306.119324,60.459961 L301.019287,58.239990 L300.059326,57.820007 L300.959290,57.339966 L301.439331,57.339966 L306.539307,59.559998 L306.119324,60.459961 L305.879333,60.279968 L302.759338,55.659973 L303.599304,55.119995 L303.659302,55.539978 L303.119324,57.099976" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M300.959290,57.340027 L302.399292,56.500000 L303.119324,57.100037 L303.059326,57.280029 L302.879333,57.340027 L301.439331,58.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M302.639282,56.920044 L303.179321,55.360046 L306.299316,59.980042 L301.199280,57.760071" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.719299,27.760010 L267.539307,27.640015 L267.239319,28.000000 L267.419312,28.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M301.979309,56.080017 L302.159302,56.200012 L301.859314,56.559998 L301.679321,56.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.719299,27.760010 L267.419312,28.119995 L301.679321,56.440002 L301.979309,56.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.799316,60.220032 L295.559326,60.700012 L296.519287,61.240051 L296.759277,60.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.159302,60.940002 L296.339294,59.260010 L296.459290,58.239990 L297.179321,58.960022 L301.259338,62.859985 L302.519287,64.059998 L300.839294,63.700012 L295.319336,62.559998 L294.299316,62.380005 L295.019287,61.720032 L295.499329,61.599976 L301.019287,62.739990 L300.839294,63.700012 L300.599304,63.580017 L296.519287,59.679993 L297.179321,58.960022 L297.299316,59.380005 L297.119324,61.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.019287,61.720032 L296.279297,60.640015 L297.119324,61.060059 L297.119324,61.240051 L296.999329,61.360046 L295.739319,62.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.639282,61.000000 L296.819275,59.320007 L300.899292,63.219971 L295.379272,62.080017" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.619308,29.020020 L235.439316,28.900024 L235.199295,29.320007 L235.379318,29.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M295.799316,60.280029 L295.979309,60.400024 L295.739319,60.820007 L295.559326,60.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M235.619308,29.020020 L235.379318,29.440002 L295.559326,60.700012 L295.799316,60.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M282.599304,60.220032 L282.479309,60.700012 L283.439331,61.000061 L283.559326,60.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M282.959290,60.760010 L282.959290,58.119995 L283.799316,58.720032 L288.359314,61.960022 L289.799316,62.979980 L288.059326,62.919983 L282.479309,62.619995 L281.459290,62.559998 L282.059326,61.780029 L282.539307,61.600037 L288.119324,61.900024 L288.059326,62.919983 L287.759277,62.799988 L283.199280,59.559998 L283.799316,58.720032 L284.039307,59.140015 L284.039307,60.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M282.059326,61.780029 L283.079285,60.460022 L284.039307,60.760010 L284.039307,60.940002 L283.919312,61.060059 L282.899292,62.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M283.499329,60.760010 L283.499329,59.140015 L288.059326,62.380005 L282.479309,62.080017" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.039291,29.500000 L193.799301,29.440002 L193.619278,29.919983 L193.859299,29.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M282.659302,60.220032 L282.899292,60.280029 L282.719299,60.760010 L282.479309,60.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.039291,29.500000 L193.859299,29.979980 L282.479309,60.700012 L282.659302,60.219971" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.299301" y="62.500000" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.299301" y="62.260010" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.419296" y="62.500000" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.059311" y="80.260010" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.059311" y="62.260010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.659317" y="62.500000" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.659317" y="62.260010" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.779312" y="62.500000" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.419296" y="80.260010" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.419296" y="62.260010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.019302" y="62.500000" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="244.019302" y="62.260010" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.139282" y="62.500000" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.779312" y="80.260010" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.779312" y="62.260010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.379333" y="62.500000" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.379333" y="62.260010" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.559326" y="62.500000" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.139282" y="80.260010" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.139282" y="62.260010" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.479294" y="9.940002" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.479294" y="9.700012" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.599319" y="9.940002" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.239304" y="27.700012" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.239304" y="9.700012" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.839310" y="9.940002" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.839310" y="9.700012" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.959305" y="9.940002" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.599319" y="27.700012" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.599319" y="9.700012" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.199295" y="9.940002" width="36.419998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="244.199295" y="9.700012" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.379333" y="9.940002" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.959305" y="27.700012" width="36.660000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.959305" y="9.700012" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.619324" y="9.940002" width="36.360001" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.619324" y="9.700012" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.739319" y="9.940002" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.379333" y="27.700012" width="36.599998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.379333" y="9.700012" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.079300,82.420044 L223.199295,82.900024 L224.219315,82.600037 L224.099289,82.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.739304,82.660034 L222.719315,81.340027 L222.119308,80.560059 L223.139297,80.500061 L228.719315,80.320007 L230.459305,80.260010 L229.019302,81.280029 L224.399307,84.400024 L223.559311,85.000061 L223.559311,83.980042 L223.859299,83.560059 L228.479294,80.440063 L229.019302,81.280029 L228.779312,81.340027 L223.199295,81.520020 L223.139297,80.500061 L223.559311,80.740051 L224.579300,82.060059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.559311,83.980042 L223.619308,82.360046 L224.579300,82.060059 L224.699326,82.180054 L224.699326,82.360046 L224.639297,83.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.159317,82.359985 L223.139328,81.039978 L228.719315,80.859985 L224.099319,83.979980" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.959305,100.900024 L165.719315,100.960022 L165.839310,101.440002 L166.079300,101.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M223.079300,82.420044 L223.319290,82.360046 L223.439285,82.840027 L223.199295,82.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M165.959305,100.900024 L166.079300,101.380005 L223.199295,82.900024 L223.079300,82.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.819290,83.679993 L189.059280,84.159973 L190.019302,83.679993 L189.779282,83.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.539291,83.799988 L188.339279,82.659973 L187.619278,82.000000 L188.639297,81.820007 L194.159286,80.859985 L195.899277,80.500000 L194.579300,81.700012 L190.439285,85.419983 L189.659286,86.140015 L189.539291,85.119995 L189.779282,84.700012 L193.919296,80.979980 L194.579300,81.700012 L194.339279,81.820007 L188.819290,82.779968 L188.639297,81.820007 L189.059280,81.940002 L190.259293,83.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.539291,85.119995 L189.359299,83.500000 L190.259293,83.080017 L190.379288,83.200012 L190.379288,83.380005 L190.559280,85.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.899307,83.440002 L188.699295,82.299988 L194.219315,81.340027 L190.079300,85.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.699295,101.559998 L152.519302,101.679993 L152.759293,102.099976 L152.939285,101.979980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.819290,83.739990 L188.999283,83.619995 L189.239304,84.039978 L189.059280,84.159973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.699295,101.559998 L152.939285,101.979980 L189.059280,84.159973 L188.819290,83.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M54.899307,82.960022 L55.019302,82.480042 L53.939301,82.240051 L53.819305,82.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M54.359299,82.420044 L54.599304,84.100037 L54.779297,85.120056 L53.819305,84.580017 L48.899292,81.880066 L47.459305,81.040039 L49.139297,80.980042 L54.719299,80.620056 L55.799301,80.500061 L55.199295,81.400024 L54.779297,81.580017 L49.199295,81.940063 L49.139297,80.980042 L49.439301,81.040039 L54.359299,83.740051 L53.819305,84.580017 L53.639297,84.220032 L53.399292,82.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M55.199310,81.400024 L54.299316,82.780029 L53.399307,82.540039 L53.339310,82.360046 L53.459305,82.180054 L54.359314,80.800049" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M53.879303,82.480042 L54.119308,84.160034 L49.199310,81.460022 L54.779297,81.100037" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.359299,103.179993 L144.599289,103.239990 L144.719284,102.760010 L144.479294,102.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M54.899307,82.960022 L54.659302,82.900024 L54.779312,82.420044 L55.019302,82.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.359299,103.179993 L144.479294,102.700012 L55.019302,82.479980 L54.899307,82.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.819305,83.920044 L89.939301,83.440063 L88.919312,83.200073 L88.799301,83.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.339310,83.380005 L89.519302,85.000000 L89.699310,86.020020 L88.739304,85.479980 L83.879303,82.720032 L82.439316,81.880005 L84.119308,81.760010 L89.699310,81.580017 L90.779312,81.520020 L90.179306,82.359985 L89.759308,82.539978 L84.179306,82.780029 L84.119308,81.760010 L84.419312,81.880005 L89.279312,84.640015 L88.739304,85.479980 L88.559311,85.119995 L88.379303,83.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M90.179306,82.359985 L89.279312,83.739990 L88.379303,83.500000 L88.319305,83.320007 L88.439301,83.140015 L89.339310,81.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.859299,83.440002 L89.039291,85.059998 L84.179306,82.299988 L89.759293,82.059998" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.359299,101.980042 L162.599289,102.040039 L162.719284,101.560059 L162.479294,101.500061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M89.819305,83.920044 L89.579300,83.860046 L89.699310,83.380066 L89.939301,83.440063" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.359299,101.980042 L162.479294,101.500061 L89.939301,83.440063 L89.819290,83.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.619308,55.000000 L160.139297,55.119995 L160.379318,56.140015 L160.859299,56.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.319290,55.660034 L161.699295,54.760010 L162.539291,54.160034 L162.479294,55.240051 L162.179276,60.820007 L162.119278,62.500061 L161.279282,61.060059 L158.579300,56.200012 L158.039291,55.300049 L159.059280,55.420044 L159.419296,55.660034 L162.119278,60.520020 L161.279282,61.060059 L161.219284,60.760010 L161.519302,55.180054 L162.479294,55.240051 L162.299301,55.600037 L160.919296,56.500061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M159.059311,55.420044 L160.679306,55.600037 L160.919296,56.500061 L160.739304,56.620056 L160.559311,56.560059 L158.939316,56.380066" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.619308,56.080017 L161.999313,55.179993 L161.699295,60.760010 L158.999313,55.900024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.799301,29.020020 L154.739304,28.780029 L154.259293,28.900024 L154.319290,29.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.619308,55.000000 L160.679306,55.239990 L160.199295,55.359985 L160.139297,55.119995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.799301,29.020020 L154.319290,29.140015 L160.139297,55.119995 L160.619308,55.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.959305,55.660034 L153.599319,56.020020 L154.439316,56.740051 L154.799301,56.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.139297,56.380005 L154.679306,54.820007 L154.979294,53.799988 L155.579300,54.760010 L158.759293,59.380005 L159.779312,60.820007 L158.159286,60.099976 L152.999283,57.820007 L152.039291,57.400024 L152.939285,56.919983 L153.419296,56.919983 L158.579300,59.200012 L158.159286,60.099976 L157.919296,59.919983 L154.739304,55.299988 L155.579300,54.760010 L155.639297,55.179993 L155.099289,56.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M152.939316,56.920044 L154.379318,56.140015 L155.099319,56.740051 L155.039322,56.920044 L154.859329,56.980042 L153.419327,57.760071" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.619308,56.559998 L155.159317,55.000000 L158.339310,59.619995 L153.179306,57.340027" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M119.699295,27.340027 L119.519302,27.220032 L119.219284,27.580017 L119.399307,27.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.959305,55.660034 L154.139297,55.780029 L153.839310,56.140015 L153.659317,56.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M119.699295,27.340027 L119.399307,27.700012 L153.659286,56.020020 L153.959305,55.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.779312,59.859985 L147.539322,60.339966 L148.499313,60.820007 L148.739304,60.339966" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.139297,60.520020 L148.319290,58.900024 L148.379288,57.880005 L149.159286,58.600037 L153.239304,62.440002 L154.499283,63.640015 L152.819290,63.280029 L147.359299,62.140015 L146.339310,61.960022 L147.059311,61.300049 L147.539291,61.179993 L152.999283,62.320007 L152.819290,63.280029 L152.579300,63.160034 L148.499283,59.320007 L149.159286,58.600037 L149.279312,59.020020 L149.099289,60.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.059311,61.299988 L148.259323,60.219971 L149.099319,60.640015 L149.099319,60.820007 L148.979324,60.940002 L147.779312,62.019958" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.619308,60.580017 L148.799301,58.960022 L152.879318,62.799988 L147.419296,61.660034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M87.659302,28.600037 L87.479309,28.480042 L87.239304,28.900024 L87.419296,29.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.779312,59.920044 L147.959305,60.040039 L147.719315,60.460022 L147.539322,60.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M87.659302,28.600037 L87.419296,29.020020 L147.539291,60.340027 L147.779312,59.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.579300,59.799988 L134.459305,60.279968 L135.479294,60.640015 L135.599289,60.159973" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.999313,60.400024 L134.939316,58.720032 L134.939316,57.700012 L135.779312,58.300049 L140.339310,61.540039 L141.779312,62.559998 L140.039322,62.500000 L134.459305,62.200012 L133.439316,62.140015 L134.039322,61.360046 L134.519302,61.180054 L140.099319,61.480042 L140.039322,62.500000 L139.739304,62.380005 L135.179306,59.140015 L135.779312,58.300049 L136.019302,58.720032 L136.079300,60.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.039291,61.359985 L135.119278,60.099976 L136.079300,60.399963 L136.019302,60.579956 L135.959305,60.700012 L134.879288,61.959961" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M135.539291,60.400024 L135.479294,58.720032 L140.039291,61.960022 L134.459305,61.660034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M46.019302,29.080017 L45.779297,29.020020 L45.599304,29.500000 L45.839310,29.559998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M134.639297,59.799988 L134.879288,59.859985 L134.699295,60.339966 L134.459305,60.279968" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M46.019302,29.080017 L45.839310,29.559998 L134.459305,60.280029 L134.639297,59.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="45.903152" y="128.201416" textLength="4.442996" font-size="8px">d</text>
<text x="41.470551" y="128.201416" textLength="4.442996" font-size="8px">n</text>
<text x="37.037949" y="128.201416" textLength="4.442996" font-size="8px">a</text>
<text x="34.397720" y="128.201416" textLength="2.661003" font-size="8px">r</text>
<text x="25.466187" y="128.201416" textLength="4.442996" font-size="8px">p</text>
<text x="33.532318" y="119.261108" textLength="5.769502" font-size="8px">D</text>
<text x="27.759613" y="119.261108" textLength="5.769502" font-size="8px">R</text>
<text x="21.539413" y="119.261108" textLength="6.216998" font-size="8px">O</text>
<text x="45.880783" y="110.320801" textLength="4.442996" font-size="8px">n</text>
<text x="41.833344" y="110.320801" textLength="2.221498" font-size="8px"> </text>
<text x="37.845840" y="110.320801" textLength="3.995500" font-size="8px">s</text>
<text x="33.410828" y="110.320801" textLength="4.442996" font-size="8px">d</text>
<text x="31.644821" y="110.320801" textLength="1.774002" font-size="8px">l</text>
<text x="25.443802" y="110.320801" textLength="1.774002" font-size="8px">i</text>
<text x="20.569290" y="110.320801" textLength="4.882501" font-size="8px">F</text>
<text x="45.894394" y="101.441223" textLength="4.442996" font-size="8px">g</text>
<text x="30.800995" y="101.441223" textLength="4.442996" font-size="8px">o</text>
<text x="26.807892" y="101.441223" textLength="3.995500" font-size="8px">c</text>
<text x="17.039688" y="101.441223" textLength="5.329997" font-size="8px">E</text>
<text x="67.857651" y="128.020874" textLength="5.329997" font-size="8px">B</text>
<text x="86.274506" y="119.080566" textLength="4.442996" font-size="8px">6</text>
<text x="75.998077" y="119.080566" textLength="2.661003" font-size="8px">-</text>
<text x="73.776581" y="119.080566" textLength="2.221498" font-size="8px"> </text>
<text x="68.452972" y="119.080566" textLength="5.329997" font-size="8px">B</text>
<text x="59.579773" y="119.080566" textLength="4.442996" font-size="8px">1</text>
<text x="86.274506" y="110.140259" textLength="4.442996" font-size="8px">5</text>
<text x="80.874191" y="110.140259" textLength="5.329997" font-size="8px">X</text>
<text x="78.652695" y="110.140259" textLength="2.221498" font-size="8px"> </text>
<text x="75.998077" y="110.140259" textLength="2.661003" font-size="8px">-</text>
<text x="68.452972" y="110.140259" textLength="5.329997" font-size="8px">B</text>
<text x="64.016373" y="110.140259" textLength="4.442996" font-size="8px">1</text>
<text x="80.874191" y="101.199951" textLength="5.329997" font-size="8px">X</text>
<text x="75.998077" y="101.199951" textLength="2.661003" font-size="8px">-</text>
<text x="73.776581" y="101.199951" textLength="2.221498" font-size="8px"> </text>
<text x="236.441360" y="106.600342" textLength="4.442996" font-size="8px">o</text>
<text x="229.318039" y="75.580017" textLength="4.442996" font-size="8px">2</text>
<text x="154.316971" y="75.400024" textLength="4.442996" font-size="8px">4</text>
<text x="41.453796" y="101.441223" textLength="4.442996" font-size="8px">n</text>
<text x="242.682480" y="133.420044" textLength="4.442996" font-size="8px">a</text>
<text x="44.638214" y="119.261108" textLength="5.769502" font-size="8px">R</text>
<text x="86.274506" y="101.199951" textLength="4.442996" font-size="8px">4</text>
<text x="239.982315" y="133.420044" textLength="2.661003" font-size="8px">r</text>
<text x="11.699295" y="110.320801" textLength="4.442996" font-size="8px">o</text>
<text x="249.757584" y="115.540649" textLength="1.774002" font-size="8px">i</text>
<text x="283.748901" y="133.179993" textLength="2.221498" font-size="8px"> </text>
<text x="175.679001" y="128.080017" textLength="4.071600" font-size="8px">3</text>
<text x="44.114777" y="110.320801" textLength="1.774002" font-size="8px">i</text>
<text x="36.839310" y="21.220032" textLength="5.329997" font-size="8px">X</text>
<text x="108.819504" y="114.760010" textLength="5.769502" font-size="8px">R</text>
<text x="16.134293" y="110.320801" textLength="2.221498" font-size="8px">f</text>
<text x="269.097412" y="133.179993" textLength="4.442996" font-size="8px">1</text>
<text x="112.557602" y="75.400024" textLength="5.329997" font-size="8px">Y</text>
<text x="151.136185" y="21.220032" textLength="4.442996" font-size="8px">4</text>
<text x="18.347794" y="110.320801" textLength="2.221498" font-size="8px"> </text>
<text x="39.305023" y="119.261108" textLength="5.329997" font-size="8px">E</text>
<text x="78.652695" y="101.199951" textLength="2.221498" font-size="8px"> </text>
<text x="114.592209" y="114.760010" textLength="5.769502" font-size="8px">D</text>
<text x="247.536087" y="115.540649" textLength="2.221498" font-size="8px"> </text>
<text x="281.648071" y="106.419800" textLength="2.661003" font-size="8px">-</text>
<text x="73.198044" y="128.020874" textLength="2.221498" font-size="8px"> </text>
<text x="15.537704" y="21.040222" textLength="5.769502" font-size="8px">C</text>
<text x="149.398727" y="128.080017" textLength="4.071600" font-size="8px">6</text>
<text x="22.367294" y="101.441223" textLength="4.442996" font-size="8px">n</text>
<text x="40.019302" y="75.400024" textLength="5.329997" font-size="8px">Y</text>
<text x="279.426575" y="106.419800" textLength="2.221498" font-size="8px"> </text>
<text x="279.426575" y="115.360107" textLength="2.221498" font-size="8px"> </text>
<text x="284.348206" y="106.419800" textLength="2.221498" font-size="8px"> </text>
<text x="68.452972" y="101.199951" textLength="5.329997" font-size="8px">B</text>
<text x="9.768997" y="21.040222" textLength="5.769502" font-size="8px">R</text>
<text x="217.318893" y="115.540649" textLength="4.442996" font-size="8px">o</text>
<text x="222.658493" y="106.600342" textLength="5.329997" font-size="8px">E</text>
<text x="302.756104" y="75.580017" textLength="4.442996" font-size="8px">0</text>
<text x="188.399307" y="75.580017" textLength="5.329997" font-size="8px">Y</text>
<text x="59.579773" y="110.140259" textLength="4.442996" font-size="8px">0</text>
<text x="269.645569" y="106.419800" textLength="4.442996" font-size="8px">0</text>
<text x="229.438095" y="23.020020" textLength="4.442996" font-size="8px">2</text>
<text x="63.418655" y="128.020874" textLength="4.442996" font-size="8px">1</text>
<text x="223.988205" y="115.540649" textLength="2.221498" font-size="8px"> </text>
<text x="16.443878" y="74.200378" textLength="4.882501" font-size="8px">T</text>
<text x="29.898788" y="128.201416" textLength="4.442996" font-size="8px">e</text>
<text x="243.538193" y="115.540649" textLength="3.995500" font-size="8px">s</text>
<text x="274.092590" y="106.419800" textLength="5.329997" font-size="8px">B</text>
<text x="120.364914" y="114.760010" textLength="5.329997" font-size="8px">E</text>
<text x="286.569702" y="106.419800" textLength="5.329997" font-size="8px">X</text>
<text x="80.281265" y="128.020874" textLength="5.329997" font-size="8px">X</text>
<text x="72.358521" y="21.220032" textLength="5.329997" font-size="8px">X</text>
<text x="59.579773" y="101.199951" textLength="4.442996" font-size="8px">0</text>
<text x="11.109085" y="74.200378" textLength="5.329997" font-size="8px">S</text>
<text x="269.645569" y="124.239685" textLength="4.442996" font-size="8px">0</text>
<text x="233.292099" y="124.480957" textLength="5.769502" font-size="8px">R</text>
<text x="297.594910" y="23.020020" textLength="5.329997" font-size="8px">X</text>
<text x="75.419540" y="128.020874" textLength="2.661003" font-size="8px">-</text>
<text x="78.059769" y="128.020874" textLength="2.221498" font-size="8px"> </text>
<text x="279.426575" y="124.239685" textLength="2.221498" font-size="8px"> </text>
<text x="59.579773" y="128.020874" textLength="4.442996" font-size="8px">1</text>
<text x="224.879318" y="133.420044" textLength="6.216998" font-size="8px">O</text>
<text x="291.300354" y="133.179993" textLength="4.442996" font-size="8px">3</text>
<text x="73.776581" y="110.140259" textLength="2.221498" font-size="8px"> </text>
<text x="261.176758" y="23.020020" textLength="5.329997" font-size="8px">X</text>
<text x="227.993271" y="106.600342" textLength="4.442996" font-size="8px">n</text>
<text x="0.000000" y="74.200378" textLength="5.769502" font-size="8px">D</text>
<text x="205.139297" y="128.080017" textLength="4.071600" font-size="8px">0</text>
<text x="265.198608" y="133.179993" textLength="4.442996" font-size="8px">1</text>
<text x="244.855850" y="124.480957" textLength="5.329997" font-size="8px">E</text>
<text x="291.903687" y="106.419800" textLength="4.442996" font-size="8px">0</text>
<text x="35.241592" y="101.441223" textLength="4.442996" font-size="8px">d</text>
<text x="117.897995" y="75.400024" textLength="4.442996" font-size="8px">5</text>
<text x="85.681580" y="128.020874" textLength="4.442996" font-size="8px">7</text>
<text x="266.337158" y="75.580017" textLength="4.442996" font-size="8px">1</text>
<text x="39.682190" y="101.441223" textLength="1.774002" font-size="8px">i</text>
<text x="5.774292" y="74.200378" textLength="5.329997" font-size="8px">E</text>
<text x="193.378983" y="128.080017" textLength="4.071600" font-size="8px">1</text>
<text x="240.889145" y="106.600342" textLength="4.442996" font-size="8px">d</text>
<text x="114.718002" y="21.220032" textLength="4.442996" font-size="8px">5</text>
<text x="80.874191" y="119.080566" textLength="5.329997" font-size="8px">X</text>
<text x="149.036514" y="75.400024" textLength="5.329997" font-size="8px">Y</text>
<text x="19.259583" y="128.201416" textLength="6.216998" font-size="8px">O</text>
<text x="284.348206" y="115.360107" textLength="2.221498" font-size="8px"> </text>
<text x="273.536377" y="133.179993" textLength="5.329997" font-size="8px">B</text>
<text x="251.533981" y="115.540649" textLength="4.442996" font-size="8px">n</text>
<text x="297.415710" y="75.580017" textLength="5.329997" font-size="8px">Y</text>
<text x="274.092590" y="124.239685" textLength="5.329997" font-size="8px">B</text>
<text x="64.016373" y="119.080566" textLength="4.442996" font-size="8px">0</text>
<text x="193.919693" y="23.020020" textLength="4.442996" font-size="8px">3</text>
<text x="239.110336" y="124.480957" textLength="5.769502" font-size="8px">D</text>
<text x="27.209808" y="110.320801" textLength="4.442996" font-size="8px">e</text>
<text x="78.652695" y="119.080566" textLength="2.221498" font-size="8px"> </text>
<text x="157.438919" y="128.080017" textLength="4.071600" font-size="8px">5</text>
<text x="232.870987" y="115.540649" textLength="4.442996" font-size="8px">e</text>
<text x="42.179703" y="21.220032" textLength="4.442996" font-size="8px">7</text>
<text x="77.698898" y="21.220032" textLength="4.442996" font-size="8px">6</text>
<text x="109.377609" y="21.220032" textLength="5.329997" font-size="8px">X</text>
<text x="145.856522" y="21.220032" textLength="5.329997" font-size="8px">X</text>
<text x="4.439804" y="21.040222" textLength="5.329997" font-size="8px">S</text>
<text x="45.359695" y="75.400024" textLength="4.442996" font-size="8px">7</text>
<text x="75.538513" y="75.400024" textLength="5.329997" font-size="8px">Y</text>
<text x="80.878891" y="75.400024" textLength="4.442996" font-size="8px">6</text>
<text x="102.599319" y="114.760010" textLength="6.216998" font-size="8px">O</text>
<text x="125.698105" y="114.760010" textLength="5.769502" font-size="8px">R</text>
<text x="265.198608" y="106.419800" textLength="4.442996" font-size="8px">0</text>
<text x="265.198608" y="115.360107" textLength="4.442996" font-size="8px">0</text>
<text x="269.645569" y="115.360107" textLength="4.442996" font-size="8px">1</text>
<text x="274.092590" y="115.360107" textLength="5.329997" font-size="8px">B</text>
<text x="281.648071" y="115.360107" textLength="2.661003" font-size="8px">-</text>
<text x="286.569702" y="115.360107" textLength="5.329997" font-size="8px">X</text>
<text x="291.903687" y="115.360107" textLength="4.442996" font-size="8px">1</text>
<text x="265.198608" y="124.239685" textLength="4.442996" font-size="8px">1</text>
<text x="281.648071" y="124.239685" textLength="2.661003" font-size="8px">-</text>
<text x="284.348206" y="124.239685" textLength="2.221498" font-size="8px"> </text>
<text x="286.569702" y="124.239685" textLength="5.329997" font-size="8px">X</text>
<text x="291.903687" y="124.239685" textLength="4.442996" font-size="8px">2</text>
<text x="278.866394" y="133.179993" textLength="2.221498" font-size="8px"> </text>
<text x="281.087891" y="133.179993" textLength="2.661003" font-size="8px">-</text>
<text x="285.970398" y="133.179993" textLength="5.329997" font-size="8px">X</text>
<text x="232.441055" y="106.600342" textLength="3.995500" font-size="8px">c</text>
<text x="245.336929" y="106.600342" textLength="1.774002" font-size="8px">i</text>
<text x="247.115738" y="106.600342" textLength="4.442996" font-size="8px">n</text>
<text x="251.563522" y="106.600342" textLength="4.442996" font-size="8px">g</text>
<text x="221.764297" y="115.540649" textLength="2.221498" font-size="8px">f</text>
<text x="226.209702" y="115.540649" textLength="4.882501" font-size="8px">F</text>
<text x="231.094589" y="115.540649" textLength="1.774002" font-size="8px">i</text>
<text x="237.316391" y="115.540649" textLength="1.774002" font-size="8px">l</text>
<text x="239.092789" y="115.540649" textLength="4.442996" font-size="8px">d</text>
<text x="227.099075" y="124.480957" textLength="6.216998" font-size="8px">O</text>
<text x="250.196243" y="124.480957" textLength="5.769502" font-size="8px">R</text>
<text x="185.878891" y="128.080017" textLength="4.071600" font-size="8px">2</text>
<text x="167.098709" y="128.080017" textLength="4.071600" font-size="8px">4</text>
<text x="139.798813" y="128.080017" textLength="4.071600" font-size="8px">7</text>
<text x="231.096329" y="133.420044" textLength="4.442996" font-size="8px">p</text>
<text x="235.539322" y="133.420044" textLength="4.442996" font-size="8px">e</text>
<text x="247.125473" y="133.420044" textLength="4.442996" font-size="8px">n</text>
<text x="251.568466" y="133.420044" textLength="4.442996" font-size="8px">d</text>
<text x="193.678970" y="75.580017" textLength="4.442996" font-size="8px">3</text>
<text x="223.977646" y="75.580017" textLength="5.329997" font-size="8px">Y</text>
<text x="260.996765" y="75.580017" textLength="5.329997" font-size="8px">Y</text>
<text x="188.579300" y="23.020020" textLength="5.329997" font-size="8px">X</text>
<text x="224.158432" y="23.020020" textLength="5.329997" font-size="8px">X</text>
<text x="266.456421" y="23.020020" textLength="4.442996" font-size="8px">1</text>
<text x="302.935303" y="23.020020" textLength="4.442996" font-size="8px">0</text>
<text x="64.016373" y="101.199951" textLength="4.442996" font-size="8px">0</text>
</svg>
<figcaption>Figure 4-16.  256-bit VPSHUFD Instruction Operation
</figcaption></figure>
```


The source operand can be an XMM register or a 128-bit memory location. The destination operand is an XMM register. The order operand is an 8-bit immediate. Note that this instruction permits a doubleword in the source operand to be copied to more than one doubleword location in the destination operand.

In 64-bit mode and not encoded in VEX/EVEX, using REX.R permits this instruction to access XMM8-XMM15.

128-bit Legacy SSE version: Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged.

VEX.128 encoded version: The source operand can be an XMM register or a 128-bit memory location. The destina-tion operand is an XMM register. Bits (MAX_VL-1:128) of the corresponding ZMM register are zeroed.

VEX.256 encoded version: The source operand can be an YMM register or a 256-bit memory location. The destina-tion operand is an YMM register. Bits (MAX_VL-1:256) of the corresponding ZMM register are zeroed. Bits (255-1:128) of the destination stores the shuffled results of the upper 16 bytes of the source operand using the imme-diate byte as the order operand.

EVEX encoded version: The source operand can be an ZMM/YMM/XMM register, a 512/256/128-bit memory loca-tion, or a 512/256/128-bit vector broadcasted from a 32-bit memory location. The destination operand is a ZMM/YMM/XMM register updated according to the writemask. 

Each 128-bit lane of the destination stores the shuffled results of the respective lane of the source operand using the immediate byte as the order operand.

Note: EVEX.vvvv and VEX.vvvv are reserved and must be 1111b otherwise instructions will #UD.


### Operation
#### PSHUFD (128-bit Legacy SSE version)
```info-verb
DEST[31:0] <-  (SRC >> (ORDER[1:0] \htmlonly{*} 32))[31:0];
DEST[63:32] <-  (SRC >> (ORDER[3:2] \htmlonly{*} 32))[31:0];
DEST[95:64]  <- (SRC >> (ORDER[5:4] \htmlonly{*} 32))[31:0];
DEST[127:96]  <- (SRC >> (ORDER[7:6] \htmlonly{*} 32))[31:0];
DEST[VLMAX-1:128] (Unmodified)
```
#### VPSHUFD (VEX.128 encoded version)
```info-verb
DEST[31:0]  <- (SRC >> (ORDER[1:0] \htmlonly{*} 32))[31:0];
DEST[63:32] <-  (SRC >> (ORDER[3:2] \htmlonly{*} 32))[31:0];
DEST[95:64] <-  (SRC >> (ORDER[5:4] \htmlonly{*} 32))[31:0];
DEST[127:96]  <- (SRC >> (ORDER[7:6] \htmlonly{*} 32))[31:0];
DEST[VLMAX-1:128] <-  0
```
#### VPSHUFD (VEX.256 encoded version)
```info-verb
DEST[31:0]  <- (SRC[127:0] >> (ORDER[1:0] * 32))[31:0];
DEST[63:32]  <- (SRC[127:0] >> (ORDER[3:2] * 32))[31:0];
DEST[95:64]  <- (SRC[127:0] >> (ORDER[5:4] * 32))[31:0];
DEST[127:96] <-  (SRC[127:0] >> (ORDER[7:6] * 32))[31:0];
DEST[159:128]  <- (SRC[255:128] >> (ORDER[1:0] * 32))[31:0];
DEST[191:160] <-  (SRC[255:128] >> (ORDER[3:2] * 32))[31:0];
DEST[223:192]  <- (SRC[255:128] >> (ORDER[5:4] * 32))[31:0];
DEST[255:224] <-  (SRC[255:128] >> (ORDER[7:6] * 32))[31:0];
DEST[VLMAX-1:256] <-  0
```
#### VPSHUFD (EVEX encoded versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j  <- 0 TO KL-1
 i  <- j * 32
 IF (EVEX.b = 1) AND (SRC *is memory*)
   THEN TMP_SRC[i+31:i] <-  SRC[31:0]
   ELSE TMP_SRC[i+31:i]  <- SRC[i+31:i]
 FI;
ENDFOR;
IF VL >= 128
 TMP_DEST[31:0] <-  (TMP_SRC[127:0] >> (ORDER[1:0] * 32))[31:0];
 TMP_DEST[63:32] <-  (TMP_SRC[127:0] >> (ORDER[3:2] * 32))[31:0];
 TMP_DEST[95:64] <-  (TMP_SRC[127:0] >> (ORDER[5:4] * 32))[31:0];
 TMP_DEST[127:96] <-  (TMP_SRC[127:0] >> (ORDER[7:6] * 32))[31:0];
FI;
IF VL >= 256
 TMP_DEST[159:128] <-  (TMP_SRC[255:128] >> (ORDER[1:0] * 32))[31:0];
 TMP_DEST[191:160]  <- (TMP_SRC[255:128] >> (ORDER[3:2] * 32))[31:0];
 TMP_DEST[223:192] <-  (TMP_SRC[255:128] >> (ORDER[5:4] * 32))[31:0];
 TMP_DEST[255:224] <-  (TMP_SRC[255:128] >> (ORDER[7:6] * 32))[31:0];
FI;
IF VL >= 512
 TMP_DEST[287:256]  <- (TMP_SRC[383:256] >> (ORDER[1:0] * 32))[31:0];
 TMP_DEST[319:288]  <- (TMP_SRC[383:256] >> (ORDER[3:2] * 32))[31:0];
 TMP_DEST[351:320] <-  (TMP_SRC[383:256] >> (ORDER[5:4] * 32))[31:0];
 TMP_DEST[383:352]  <- (TMP_SRC[383:256] >> (ORDER[7:6] * 32))[31:0];
 TMP_DEST[415:384] <-  (TMP_SRC[511:384] >> (ORDER[1:0] * 32))[31:0];
 TMP_DEST[447:416] <-  (TMP_SRC[511:384] >> (ORDER[3:2] * 32))[31:0];
 TMP_DEST[479:448]  <-(TMP_SRC[511:384] >> (ORDER[5:4] * 32))[31:0];
 TMP_DEST[511:480] <-  (TMP_SRC[511:384] >> (ORDER[7:6] * 32))[31:0];
FI;
FOR j  <- 0 TO KL-1
 i  <- j * 32
 IF k1[j] OR *no writemask*
   THEN DEST[i+31:i]  <- TMP_DEST[i+31:i]
   ELSE 
    IF *merging-masking* ; merging-masking
      THEN *DEST[i+31:i] remains unchanged*
      ELSE *zeroing-masking* ; zeroing-masking
        DEST[i+31:i] <-  0
    FI
 FI;
ENDFOR
DEST[MAX_VL-1:VL]  <- 0 
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPSHUFD __m512i _mm512_shuffle_epi32(__m512i a, int n );
VPSHUFD __m512i _mm512_mask_shuffle_epi32(__m512i s, __mmask16 k, __m512i a, int n );
VPSHUFD __m512i _mm512_maskz_shuffle_epi32( __mmask16 k, __m512i a, int n );
VPSHUFD __m256i _mm256_mask_shuffle_epi32(__m256i s, __mmask8 k, __m256i a, int n );
VPSHUFD __m256i _mm256_maskz_shuffle_epi32( __mmask8 k, __m256i a, int n );
VPSHUFD __m128i _mm_mask_shuffle_epi32(__m128i s, __mmask8 k, __m128i a, int n );
VPSHUFD __m128i _mm_maskz_shuffle_epi32( __mmask8 k, __m128i a, int n );
(V)PSHUFD:__m128i _mm_shuffle_epi32(__m128i a, int n)
VPSHUFD:__m256i _mm256_shuffle_epi32(__m256i a, const int n)
```
### Flags Affected


None.

### SIMD Floating-Point Exceptions


None.

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4.

EVEX-encoded instruction, see Exceptions Type E4NF.

#UD If VEX.vvvv ->  1111B or EVEX.vvvv ->  1111B.

