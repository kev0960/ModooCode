----------------------------
title : MPSADBW instruction(Intel x86/64 assembly instruction)
cat_title : MPSADBW
----------------------------
### MPSADBW -- Compute Multiple Packed Sums of Absolute Difference


|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|--------------------------------|--------------------------------------------------|---------------|
|66 0F 3A 42 /r ib\newline{}MPSADBW xmm1, xmm2/m128, imm8|RMI|V/V|SSE4_1|Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm1 and xmm2/m128 and writes the results in xmm1. Starting offsets within xmm1 and xmm2/m128 are determined by imm8.|
|VEX.NDS.128.66.0F3A.WIG 42 /r ib\newline{}VMPSADBW xmm1, xmm2, xmm3/m128, imm8|RVMI|V/V|AVX|Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm2 and xmm3/m128 and writes the results in xmm1. Starting offsets within xmm2 and xmm3/m128 are determined by imm8.|
|VEX.NDS.256.66.0F3A.WIG 42 /r ib\newline{}VMPSADBW ymm1, ymm2, ymm3/m256, imm8|RVMI|V/V|AVX2|Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm2 and ymm3/m128 and writes the results in ymm1. Starting offsets within ymm2 and xmm3/m128 are determined by imm8.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RMI|ModRM:reg (r, w)|ModRM:r/m (r)|imm8|NA|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
### Description


(V)MPSADBW calculates packed word results of sum-absolute-difference (SAD) of unsigned bytes from two blocks of 32-bit dword elements, using two select fields in the immediate byte to select the offsets of the two blocks within the first source operand and the second operand. Packed SAD word results are calculated within each 128-bit lane. Each SAD word result is calculated between a stationary block_2 (whose offset within the second source operand is selected by a two bit select control, multiplied by 32 bits) and a sliding block_1 at consecutive byte-granular position within the first source operand. The offset of the first 32-bit block of block_1 is selectable using a one bit select control, multiplied by 32 bits.

128-bit Legacy SSE version: Imm8[1:0]*32 specifies the bit offset of block_2 within the second source operand. Imm[2]*32 specifies the initial bit offset of the block_1 within the first source operand. The first source operand and destination operand are the same. The first source and destination operands are XMM registers. The second source operand is either an XMM register or a 128-bit memory location. Bits (VLMAX-1:128) of the corresponding YMM destination register remain unchanged. Bits 7:3 of the immediate byte are ignored.

VEX.128 encoded version: Imm8[1:0]*32 specifies the bit offset of block_2 within the second source operand. Imm[2]*32 specifies the initial bit offset of the block_1 within the first source operand. The first source and desti-nation operands are XMM registers. The second source operand is either an XMM register or a 128-bit memory location. Bits (127:128) of the corresponding YMM register are zeroed. Bits 7:3 of the immediate byte are ignored.

VEX.256 encoded version: The sum-absolute-difference (SAD) operation is repeated 8 times for MPSADW between the same block_2 (fixed offset within the second source operand) and a variable block_1 (offset is shifted by 8 bits for each SAD operation) in the first source operand. Each 16-bit result of eight SAD operations between block_2 and block_1 is written to the respective word in the lower 128 bits of the destination operand. 

Additionally, VMPSADBW performs another eight SAD operations on block_4 of the second source operand and block_3 of the first source operand. (Imm8[4:3]*32 + 128) specifies the bit offset of block_4 within the second source operand. (Imm[5]*32+128) specifies the initial bit offset of the block_3 within the first source operand. Each 16-bit result of eight SAD operations between block_4 and block_3 is written to the respective word in the upper 128 bits of the destination operand. 



The first source operand is a YMM register. The second source register can be a YMM register or a 256-bit memory location. The destination operand is a YMM register. Bits 7:6 of the immediate byte are ignored.

Note: If VMPSADBW is encoded with VEX.L= 1, an attempt to execute the instruction encoded with VEX.L= 1 will cause an #UD exception.

```embed
<figure>
<svg viewBox="0 0 379.679993 451.760010">
<rect x="0.000000" y="10.060059" width="0.480000" height="413.579987" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="379.200012" y="10.060059" width="0.479980" height="413.579987" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="379.679993" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="423.640015" width="379.679993" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="46.619995" y="45.640015" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="46.619995" y="45.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="118.380005" y="45.640015" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="46.380005" y="63.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="46.380005" y="45.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="118.619995" y="45.640015" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="118.619995" y="45.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.379990" y="45.640015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="118.380005" y="63.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="118.380005" y="45.400024" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.620010" y="45.640015" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="190.620010" y="45.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.380005" y="45.640015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.379990" y="63.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.379990" y="45.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.619995" y="45.640015" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="262.619995" y="45.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="334.380005" y="45.640015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.380005" y="63.400024" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.380005" y="45.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.960022,91.480042 L258.600037,91.840027 L259.500000,92.620056 L259.859985,92.260071" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.200012,92.260010 L259.859985,90.400024 L260.159973,89.440002 L260.760010,90.340027 L264.479980,95.799988 L265.500000,97.239990 L263.880005,96.520020 L257.880005,93.880005 L256.919983,93.460022 L257.820007,92.979980 L258.299988,92.979980 L264.299988,95.619995 L263.880005,96.520020 L263.640015,96.340027 L259.919983,90.880005 L260.760010,90.340027 L260.820007,90.760010 L260.159973,92.619995" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.820007,92.980042 L259.440002,92.020020 L260.159973,92.620056 L260.099976,92.800049 L259.919983,92.860046 L258.299988,93.820068" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M259.679993,92.440002 L260.340027,90.580017 L264.059998,96.039978 L258.059998,93.400024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.479996,66.400024 L228.300003,66.280029 L227.999985,66.640015 L228.180008,66.760010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M258.960022,91.480042 L259.140015,91.600037 L258.840027,91.960022 L258.660034,91.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.479996,66.400024 L228.180008,66.760010 L258.659973,91.840027 L258.960022,91.480042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.479980,139.120056 L297.419983,138.100037 L297.419983,138.160034 L297.179993,137.200073 L297.239990,137.260071 L296.880005,136.300049 L296.400024,135.400085 L296.400024,135.460083 L295.799988,134.620056 L295.080017,133.780029 L295.140015,133.780029 L294.299988,133.000061 L293.400024,132.280029 L293.400024,132.340027 L292.380005,131.740051 L291.239990,131.140076 L291.299988,131.140076 L290.099976,130.660034 L288.839966,130.240051 L287.520020,129.940063 L287.580017,129.940063 L286.200012,129.700073 L284.820007,129.520081 L283.320007,129.460083 L281.880005,129.520081 L281.940002,129.520081 L280.500000,129.700073 L279.119995,129.940063 L277.799988,130.240051 L277.859985,130.240051 L276.599976,130.660034 L275.400024,131.140076 L274.260010,131.740051 L273.239990,132.340027 L273.299988,132.280029 L272.400024,133.000061 L271.559998,133.780029 L270.839966,134.620056 L270.900024,134.620056 L270.299988,135.460083 L270.299988,135.400085 L269.820007,136.300049 L269.460022,137.260071 L269.460022,137.200073 L269.219971,138.160034 L269.219971,138.100037 L269.159973,139.120056 L269.219971,140.140076 L269.219971,140.080078 L269.460022,141.040039 L269.820007,142.000061 L269.820007,141.940063 L270.299988,142.840027 L270.900024,143.740051 L270.839966,143.740051 L271.559998,144.520081 L271.559998,144.460083 L272.400024,145.240051 L273.299988,145.960083 L273.239990,145.960083 L274.260010,146.560059 L274.020020,146.980042 L273.000000,146.380066 L273.000000,146.320068 C270.339966 144.518066,268.231018 141.392029,268.739990 138.040039  L268.979980,137.080078 L269.039978,137.080078 L269.400024,136.120056 L269.400024,136.060059 L269.880005,135.160034 L270.479980,134.320068 L271.200012,133.480042 L271.260010,133.420044 L272.099976,132.640076 L273.000000,131.920044 L274.020020,131.320068 L275.159973,130.720032 L275.219971,130.720032 L276.419983,130.240051 L276.419983,130.180054 L277.679993,129.760071 L279.000000,129.460083 L279.059998,129.460083 L280.440002,129.220032 L281.880005,129.040039 L283.320007,128.980042 L284.820007,129.040039 L284.880005,129.040039 L286.260010,129.220032 L287.640015,129.460083 L288.960022,129.760071 L289.020020,129.760071 L290.279968,130.180054 L290.279968,130.240051 L291.479980,130.720032 C293.560974 131.750061,294.744019 132.458069,296.159973 134.320068  L296.219971,134.320068 L296.820007,135.160034 C297.333008 135.982056,297.752014 137.162048,297.900024 138.100037  L297.960022,139.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.260010,146.560059 L275.400024,147.160065 L276.599976,147.640045 L276.599976,147.580048 L277.859985,148.000061 L277.799988,148.000061 L279.119995,148.360046 L280.500000,148.600067 L281.940002,148.720062 L281.880005,148.720062 L283.320007,148.780060 L284.820007,148.720062 L286.200012,148.600067 L287.580017,148.360046 L287.520020,148.360046 L288.839966,148.000061 L290.099976,147.580048 L290.099976,147.640045 L291.299988,147.160065 L291.239990,147.160065 L292.380005,146.560059 L293.399963,145.960083 L294.299988,145.240051 L295.140015,144.460083 L295.080017,144.520081 L295.799988,143.740051 L296.399963,142.840088 L296.880005,141.940063 L296.880005,142.000061 L297.239990,141.040039 L297.179993,141.040039 L297.419983,140.080078 L297.419983,140.140076 L297.479980,139.120056 L297.960022,139.120056 L297.899963,140.140076 L297.899963,140.200073 C297.341980 143.633057,294.515015 146.190063,291.479980 147.580048  L290.279968,148.060059 L289.020020,148.480072 L288.960022,148.480072 L287.640015,148.840057 L286.260010,149.080048 L284.880005,149.200073 L284.820007,149.200073 L283.320007,149.260071 L281.880005,149.200073 C279.908997 149.124054,278.263000 148.733063,276.419983 148.060059  L275.219971,147.580048 L275.159973,147.580048 L274.020020,146.980072" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.859985" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="298.859985" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="332.219971" y="167.020050" width="0.479980" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.619995" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.619995" y="166.780029" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.440002" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="265.440002" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="298.799988" y="167.020050" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.200012" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.200012" y="166.780029" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="232.020004" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="232.020004" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.380005" y="167.020050" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="231.780014" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="231.780014" y="166.780029" width="0.479980" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.659988" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="198.659988" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="232.020004" y="167.020050" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.419998" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.419998" y="166.780029" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.240005" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="165.240005" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.599991" y="167.020050" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.000015" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.000015" y="166.780029" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.820007" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="131.820007" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.180008" y="167.020050" width="0.479980" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.580002" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.580002" y="166.780029" width="0.480000" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="98.399994" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="98.399994" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="131.759995" y="167.020050" width="0.480000" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="98.160004" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="98.160004" y="166.780029" width="0.480000" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="65.039993" y="167.020020" width="33.599998" height="18.059999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="65.039993" y="166.780029" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="98.399994" y="167.020050" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="64.800003" y="184.840027" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="64.800003" y="166.780029" width="0.480000" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.800003" y="127.420044" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="88.800003" y="127.180054" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="149.159988" y="127.420044" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.559998" y="145.180054" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="88.559998" y="127.180054" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.619995" y="123.100037" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="109.619995" y="122.860046" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="169.979996" y="123.100037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.380005" y="140.860046" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="109.380005" y="122.860046" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.380005" y="118.780029" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="130.380005" y="118.539978" width="60.840000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.740005" y="118.780029" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.139999" y="136.539978" width="60.840000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="130.139999" y="118.540039" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="151.139999" y="114.400024" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="151.139999" y="114.159973" width="60.840000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="211.500015" y="114.400024" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.900009" y="132.159973" width="60.840000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.900009" y="114.160034" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.900009" y="110.080017" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="171.900009" y="109.840027" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="232.259995" y="110.080017" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.659988" y="127.839966" width="60.840000" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="171.659988" y="109.840027" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="192.659988" y="105.760010" width="60.660000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="192.659988" y="105.520020" width="60.900002" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.080002" y="105.760010" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="192.419998" y="123.520020" width="60.900002" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="192.419998" y="105.520020" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.479996" y="101.380005" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="213.479996" y="101.140076" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.840027" y="101.380066" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.240005" y="119.140076" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="213.240005" y="101.140015" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.240005" y="97.060059" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="234.240005" y="96.820068" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.599976" y="97.060059" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.000015" y="114.820068" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.000015" y="96.820068" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.460022" y="98.140015" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.460022" y="98.380066" width="0.479980" height="17.040001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="278.640015" y="97.719971" width="0.480010" height="0.240050" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="278.640015" y="97.960022" width="0.480010" height="17.459999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="247.620010" y="96.940063" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="247.620010" y="97.180054" width="0.479980" height="18.059999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.620010" y="45.640015" width="71.400002" height="17.459999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="190.620010" y="45.400024" width="71.639999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="261.780029" y="45.640015" width="0.479980" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.379990" y="62.859985" width="71.639999" height="0.480040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.379990" y="45.400024" width="0.480010" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="225.060013" y="45.760010" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="225.060013" y="46.000000" width="0.479980" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000015" y="45.700012" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.000015" y="45.940002" width="0.479980" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.460007" y="45.340027" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="206.460007" y="45.580017" width="0.479980" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M273.059998,78.100037 L273.000000,77.020020 L273.000000,77.080017 L272.700012,75.940063 L272.760010,76.000061 L272.280029,74.920044 L272.280029,74.980042 L271.559998,73.960022 L270.780029,73.000061 L270.840027,73.000061 L269.820007,72.100037 L268.679993,71.260010 L268.679993,71.320007 L267.419983,70.540039 L265.980042,69.820007 L266.040039,69.820007 L264.540039,69.160034 L262.919983,68.620056 L261.179993,68.140015 L259.320007,67.780029 L259.380005,67.780029 L257.520020,67.480042 L255.540024,67.300049 L253.500015,67.240051 L251.520004,67.300049 L251.580002,67.300049 L249.600021,67.480042 L247.680008,67.780029 L245.880020,68.140015 L244.139999,68.620056 L244.200027,68.620056 L242.580002,69.160034 L241.020004,69.820007 L239.640030,70.540039 L238.380020,71.320007 L238.440018,71.260010 L237.300003,72.100037 L236.280014,73.000061 L235.440018,73.960022 L235.500015,73.900024 L234.840012,74.920044 L234.360001,76.000061 L234.360001,75.940063 L234.060013,77.080017 L233.940018,78.160034 L233.940018,78.100037 L234.060013,79.240051 L234.060013,79.180054 L234.360001,80.320007 L234.840012,81.340027 L234.840012,81.280029 L235.500015,82.300049 L235.440018,82.300049 L236.280014,83.320007 L236.280014,83.260010 L237.300003,84.160034 L238.440018,85.000061 L238.380020,85.000061 L239.640030,85.780029 L241.020004,86.500061 L240.840012,86.920044 L240.780014,86.920044 L239.400009,86.200012 L238.140030,85.420044 L238.140030,85.360046 L237.000015,84.520020 L235.979996,83.620056 L235.919998,83.620056 L235.080002,82.600037 L235.080002,82.540039 L234.419998,81.520020 L233.940018,80.500061 L233.880020,80.440063 L233.580002,79.300049 L233.460007,78.160034 L233.460007,78.100037 L233.580002,77.020020 L233.580002,76.960022 L233.880020,75.820007 L233.940018,75.820007 L234.419998,74.740051 L234.419998,74.680054 L235.080002,73.660034 L235.919998,72.700012 L235.979996,72.640015 L237.000015,71.740051 L238.140030,70.900024 L239.400009,70.120056 L240.780014,69.400024 L240.840012,69.400024 L242.400009,68.740051 L242.400009,68.680054 L244.020004,68.140015 L245.760025,67.660034 L247.560013,67.300049 L247.620010,67.300049 L249.540024,67.000061 L251.520004,66.820007 L253.500015,66.760010 L255.540024,66.820007 C257.897034 66.956055,260.783020 67.438049,263.040039 68.140015  L263.100037,68.140015 L264.720032,68.680054 L264.720032,68.740051 L266.220032,69.400024 C268.192017 70.318054,270.729004 71.793030,271.919983 73.660034  L271.980042,73.660034 L272.700012,74.680054 L272.700012,74.740051 L273.179993,75.820007 L273.480042,76.960022 L273.480042,77.020020 L273.540039,78.100037" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M241.020004,86.500000 L242.580002,87.159973 L242.580002,87.099976 L244.199997,87.640015 L244.139999,87.640015 L245.879990,88.119995 L247.680008,88.479980 L249.599991,88.780029 L251.580002,88.960022 L251.520004,88.960022 L255.539993,88.960022 L257.520020,88.780029 L259.380005,88.479980 L259.320007,88.479980 L261.179993,88.119995 L262.919983,87.640015 L264.539978,87.099976 L264.539978,87.159973 L266.039978,86.500000 L265.979980,86.500000 L267.419983,85.780029 L268.679993,85.000000 L269.820007,84.159973 L270.840027,83.260010 L270.780029,83.320007 L271.559998,82.299988 L272.280029,81.280029 L272.280029,81.340027 L272.760010,80.320007 L272.700012,80.320007 L273.000000,79.179993 L273.000000,79.239990 L273.059998,78.099976 L273.539978,78.099976 L273.479980,79.239990 L273.479980,79.299988 L273.179993,80.440002 L273.179993,80.500000 L272.700012,81.520020 L272.700012,81.580017 L271.979980,82.599976 L271.919983,82.599976 C266.065002 90.189026,250.722000 90.895020,242.400009 87.580017  L240.840012,86.919983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M271.140015,156.220032 L270.659973,156.340027 L271.020020,157.420044 L271.500000,157.300018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M270.900024,157.000031 L272.400024,155.740021 L273.179993,155.020020 L273.299988,156.100037 L273.780029,162.700043 L273.900024,164.440033 L272.880005,163.060028 L268.979980,157.720032 L268.320007,156.820038 L269.340027,156.820038 L269.760010,157.060028 L273.660034,162.400024 L272.880005,163.060028 L272.760010,162.760040 L272.280029,156.160034 L273.299988,156.100037 L273.119995,156.460022 L271.619995,157.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M269.340027,156.820038 L271.260010,156.820038 L271.619995,157.720032 L271.440002,157.840027 L271.260010,157.900024 L269.340027,157.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M271.260010,157.360016 L272.760010,156.100006 L273.239990,162.700012 L269.339966,157.360016" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.760010,120.160034 L257.700012,119.920044 L257.219971,120.100037 L257.279968,120.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M271.140015,156.220032 L271.200012,156.460022 L270.719971,156.640045 L270.659973,156.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M257.760010,120.160034 L257.279968,120.340027 L270.659973,156.400024 L271.140015,156.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.419998,102.580017 L209.939987,102.340027 L209.460007,103.420044 L209.939987,103.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M209.699997,103.000000 L211.620010,103.119995 L212.699997,103.179993 L211.979996,104.020020 L207.779984,109.059998 L206.639999,110.380005 L206.879990,108.640015 L207.779984,102.099976 L207.960007,101.080017 L208.680008,101.799988 L208.800003,102.219971 L207.900009,108.760010 L206.879990,108.640015 L206.999985,108.400024 L211.199997,103.359985 L211.979996,104.020020 L211.559982,104.200012 L209.639999,104.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M208.680008,101.800049 L210.060013,103.180054 L209.639999,104.080078 L209.460007,104.020020 L207.960007,102.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M209.699997,103.540039 L211.620010,103.660034 L207.419998,108.700012 L208.319992,102.160034" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.719986,68.080017 L225.779984,67.900024 L225.360001,67.720032 L225.299973,67.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.419998,102.580017 L210.360001,102.760010 L209.939987,102.580017 L209.999985,102.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.719986,68.080017 L225.299973,67.900024 L209.999985,102.400024 L210.419998,102.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M247.379990,156.700043 L246.899979,156.820038 L247.259995,157.960052 L247.739975,157.840057" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M247.199997,157.480042 L248.699997,156.220032 L249.479996,155.620056 L249.539993,156.640045 L249.840012,163.240051 L249.900009,164.980042 L248.879990,163.540039 L245.159988,158.140045 L244.559982,157.300049 L245.580002,157.300049 L245.999985,157.600037 L249.719986,163.000031 L248.879990,163.540039 L248.819992,163.300049 L248.520004,156.700043 L249.539993,156.640045 L249.300003,157.060028 L247.800003,158.320038" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M245.580002,157.300018 L247.500015,157.360016 L247.800003,158.320007 L247.680008,158.440033 L247.500015,158.440033 L245.580002,158.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M247.500015,157.900024 L249.000015,156.640015 L249.300003,163.240021 L245.580002,157.840027" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.400009,124.000000 L236.340012,123.760010 L235.860001,123.940002 L235.919998,124.179993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M247.379990,156.700043 L247.439987,156.940033 L246.959976,157.120056 L246.899979,156.880035" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.400009,124.000000 L235.919998,124.179993 L246.900009,156.880005 L247.380020,156.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.659973,158.380035 L306.299988,158.740021 L307.080017,159.580048 L307.440002,159.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.780029,159.160034 L307.679993,157.480042 L308.160034,156.520020 L308.640015,157.540039 L311.520020,163.420044 L312.299988,164.980042 L310.799988,164.080048 L305.220032,160.600037 L304.320007,160.000031 L305.280029,159.640045 L305.760010,159.700043 L311.340027,163.180023 L310.799988,164.080048 L310.619995,163.840027 L307.739990,157.960022 L308.640015,157.540039 L308.640015,157.960022 L307.739990,159.640045" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M305.280029,159.640015 L307.080017,158.920013 L307.739990,159.640015 L307.619995,159.820007 L307.440002,159.880005 L305.640015,160.600006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.260010,159.400024 L308.159973,157.720032 L311.039978,163.600037 L305.460022,160.120026" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M268.320007,115.720032 L268.200012,115.540039 L267.839966,115.840027 L267.960022,116.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.659973,158.440033 L306.779968,158.620026 L306.419983,158.920044 L306.299988,158.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M268.320007,115.720032 L267.960022,116.020020 L306.299988,158.740021 L306.659973,158.440033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M229.319992,100.540039 L228.839981,100.540039 L228.899979,101.680054 L229.379990,101.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.960007,101.200012 L230.759995,100.480042 L231.660019,100.059998 L231.419998,101.140015 L229.860001,107.559998 L229.440018,109.239990 L228.900009,107.559998 L226.800003,101.260010 L226.440018,100.299988 L227.460007,100.600037 L227.759995,100.960022 L229.860001,107.260010 L228.900009,107.559998 L228.900009,107.260010 L230.460007,100.840027 L231.419998,101.140015 L231.120010,101.440002 L229.319992,102.160034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M227.460007,100.600037 L229.319992,101.200012 L229.319992,102.160034 L229.139999,102.220032 L228.960007,102.160034 L227.100021,101.560059" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M229.139999,101.680054 L230.939987,100.960083 L229.379990,107.380066 L227.280014,101.080078" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="227.460007" y="68.140015" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="228.840012" y="100.540039" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M227.939987,68.380005 L227.459976,68.380005 L228.839981,100.539978 L229.319992,100.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.539993,108.040039 L189.180008,107.680054 L188.460007,108.580017 L188.819992,108.940063" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.819992,108.280029 L190.619980,108.940002 L191.580002,109.240051 L190.679977,109.840027 L185.279984,113.560059 L183.839981,114.580017 L184.559982,112.960022 L187.139999,106.900024 L187.559982,105.940002 L188.039993,106.840027 L188.039993,107.320007 L185.460007,113.320007 L184.559982,112.960022 L184.740005,112.720032 L190.139999,109.000000 L190.679977,109.840027 L190.259995,109.900024 L188.460007,109.240051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.039993,106.840027 L189.059982,108.520020 L188.460007,109.240051 L188.279984,109.180054 L188.219986,109.000000 L187.199997,107.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.639999,108.760010 L190.439987,109.419983 L185.039993,113.140015 L187.620010,107.080017" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.840012,67.180054 L222.960007,67.000061 L222.600021,66.700073 L222.480026,66.880066" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M189.539993,108.040039 L189.419998,108.220032 L189.059982,107.920044 L189.180008,107.740051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.840012,67.180054 L222.480026,66.880066 L189.180008,107.740051 L189.540024,108.040039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.539993" y="155.740021" width="0.480010" height="1.140000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.599991,156.400024 L218.459976,155.740021 L219.419998,155.380035 L219.119980,156.400024 L217.319992,162.760010 L216.839981,164.440033 L216.360001,162.760010 L214.499985,156.400024 L214.199997,155.380035 L215.159988,155.740021 L215.459976,156.100037 L217.319992,162.460022 L216.360001,162.760010 L216.360001,162.460022 L218.159988,156.100037 L219.119980,156.400024 L218.819992,156.700012 L216.959976,157.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M215.159988,155.740021 L216.959976,156.400024 L216.959976,157.360016 L216.779984,157.420013 L216.599991,157.360016 L214.800003,156.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.780014,156.880035 L218.639999,156.220032 L216.840012,162.580048 L214.980026,156.220032" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.300003" y="129.400024" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="216.539993" y="155.740051" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.780014,129.640015 L216.300003,129.640015 L216.540024,155.740021 L217.020004,155.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.939987,157.240021 L188.459976,157.000031 L187.979996,158.080017 L188.459976,158.320007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.280014,157.660034 L190.200027,157.780029 L191.220016,157.900024 L190.500015,158.680023 L186.180008,163.660034 L185.040024,164.980042 L185.280014,163.240021 L186.300003,156.760040 L186.480026,155.740021 L187.200027,156.460022 L187.320023,156.940033 L186.300003,163.420044 L185.280014,163.240021 L185.460007,163.000031 L189.780014,158.020020 L190.500015,158.680023 L190.080002,158.860046 L188.160019,158.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M187.199997,156.460022 L188.580002,157.840027 L188.159988,158.740021 L187.979996,158.680023 L186.479996,157.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.219986,158.200043 L190.139999,158.320038 L185.819992,163.300049 L186.839981,156.820038" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.560013,134.140015 L199.620010,133.960022 L199.200027,133.780029 L199.139999,133.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.939987,157.240021 L188.879990,157.420013 L188.459976,157.240021 L188.519974,157.060028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M199.560013,134.140015 L199.139999,133.960022 L188.520004,157.060028 L188.940018,157.240021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.120010,157.960022 L161.760025,157.600037 L160.919998,158.440033 L161.280014,158.800018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.340012,158.140015 L163.080002,158.980011 L163.980026,159.460022 L163.020004,159.940002 L155.639999,163.780029 L156.480026,162.280029 L159.840012,156.580017 L160.380020,155.680023 L160.800003,156.640015 L160.740005,157.060028 L157.380020,162.760010 L156.480026,162.280029 L156.720016,162.100006 L162.600021,159.040009 L163.020004,159.940002 L162.600021,159.940002 L160.860001,159.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M160.800003,156.640015 L161.580002,158.440002 L160.860001,159.100006 L160.740005,158.980011 L160.620010,158.800018 L159.840012,157.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M161.099991,158.620026 L162.839981,159.460022 L156.959976,162.520020 L160.319992,156.820038" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.939987,138.040039 L183.119980,137.860046 L182.759995,137.500061 L182.580002,137.680054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M162.120010,157.960022 L161.940018,158.140015 L161.580002,157.780029 L161.760025,157.600037" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M182.939987,138.040039 L182.580002,137.680054 L161.759995,157.600037 L162.119980,157.960052" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M133.139999,160.600037 L132.899994,160.240051 L131.940002,160.840027 L132.179993,161.200043" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M132.360001,160.600037 L133.860001,161.800049 L134.699997,162.460022 L133.680008,162.700043 L127.320007,164.500031 L125.639999,164.980042 L126.779999,163.720032 L131.220001,158.800049 L131.940002,158.020050 L132.119995,158.980042 L132.000000,159.460022 L127.559998,164.380035 L126.779999,163.720032 L127.020004,163.540039 L133.380005,161.740051 L133.680008,162.700043 L133.259995,162.640045 L131.759995,161.440033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M132.119995,158.980042 L132.539993,160.900055 L131.759995,161.440033 L131.580002,161.320038 L131.580002,161.140045 L131.159988,159.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M132.059998,161.020020 L133.559998,162.220032 L127.199997,164.020020 L131.639999,159.100006" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M163.259995,141.880005 L163.439987,141.760010 L163.199997,141.340027 L163.020004,141.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M133.139999,160.660034 L132.960007,160.780029 L132.720001,160.360046 L132.899994,160.240021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M163.259995,141.880005 L163.020004,141.460022 L132.899994,160.239990 L133.139999,160.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M95.460007,162.820038 L95.340012,162.340027 L94.260010,162.760040 L94.380005,163.240051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.680008,162.640015 L95.940002,164.080017 L96.660004,164.860016 L95.580002,164.980011 L88.980011,165.460022 L87.180008,165.580017 L88.620010,164.560028 L93.960007,160.720001 L94.860001,160.060028 L94.860001,161.080017 L94.620010,161.500000 L89.280014,165.340027 L88.620010,164.560028 L88.920013,164.440002 L95.520004,163.960022 L95.580002,164.980011 L95.220001,164.800018 L93.960007,163.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.860001,161.080017 L94.860001,163.000031 L93.960007,163.360016 L93.839996,163.180023 L93.779999,163.000031 L93.779999,161.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.320007,163.000031 L95.580002,164.440033 L88.980011,164.920044 L94.320007,161.080017" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.839996,146.860016 L139.080002,146.800018 L138.899994,146.320007 L138.660004,146.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M95.520004,162.820038 L95.279999,162.880035 L95.100006,162.400024 L95.340012,162.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.839996,146.860016 L138.660004,146.380005 L95.339996,162.340027 L95.520004,162.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.479996,108.580017 L171.120010,108.220032 L170.219986,108.940002 L170.580002,109.299988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M170.639999,108.700012 L172.319992,109.660034 L173.219986,110.140015 L172.259995,110.559998 L166.259995,113.260010 L164.639999,113.980042 L165.659988,112.540039 L169.319992,107.080017 L169.860001,106.179993 L170.219986,107.140015 L170.159988,107.619995 L166.499985,113.080017 L165.659988,112.540039 L165.840012,112.359985 L171.840012,109.660034 L172.259995,110.559998 L171.840012,110.500000 L170.159988,109.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M170.219986,107.140015 L170.879990,108.940002 L170.159988,109.540039 L169.979996,109.480042 L169.919998,109.299988 L169.259995,107.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M170.400009,109.120056 L172.080002,110.080078 L166.080002,112.780029 L169.740005,107.320068" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.080002,67.360046 L220.259995,67.240051 L219.960007,66.880066 L219.780014,67.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M171.479996,108.580017 L171.300003,108.700012 L170.999985,108.340027 L171.180008,108.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.080002,67.360046 L219.780014,67.000061 L171.180008,108.220032 L171.479996,108.580078" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.680008,114.220032 L148.440018,113.860046 L147.539993,114.520020 L147.780014,114.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.960007,114.280029 L149.520004,115.420044 L150.360001,116.020020 L149.340012,116.320007 L143.100006,118.420044 L141.480011,118.960022 L142.560013,117.640015 L146.699997,112.540039 L147.300003,111.760010 L147.600021,112.660034 L147.479996,113.140015 L143.340012,118.240051 L142.560013,117.640015 L142.800003,117.460022 L149.039993,115.360046 L149.340012,116.320007 L148.919998,116.260010 L147.360001,115.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.599991,112.660034 L148.139999,114.520020 L147.360001,115.120056 L147.240005,115.000061 L147.179977,114.820007 L146.639999,112.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M147.659988,114.700012 L149.219986,115.840027 L142.979996,117.940002 L147.119980,112.840027" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.479996,67.420044 L216.659988,67.300049 L216.360001,66.880066 L216.180008,67.000061" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.740005,114.280029 L148.560013,114.400024 L148.259995,113.980042 L148.440018,113.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.479996,67.420044 L216.180008,67.000061 L148.439987,113.860046 L148.740005,114.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.479996,117.940002 L126.239990,117.580017 L125.220001,118.179993 L125.459991,118.539978" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.639999,117.940002 L127.139999,119.200012 L127.979996,119.859985 L126.899994,120.099976 L120.479996,121.720032 L118.800003,122.200012 L120.000000,120.940002 L124.559998,116.140015 L125.279999,115.359985 L125.460007,116.380005 L125.339996,116.799988 L120.779999,121.599976 L120.000000,120.940002 L120.300003,120.760010 L126.720001,119.140015 L126.899994,120.099976 L126.539993,120.039978 L125.039993,118.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.460007,116.380005 L125.820007,118.299988 L125.040009,118.780029 L124.860001,118.660034 L124.860001,118.419983 L124.500000,116.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M125.339996,118.360046 L126.839996,119.620056 L120.419998,121.240051 L124.979996,116.440063" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M213.419998,66.820007 L213.599991,66.700012 L213.360001,66.280029 L213.180008,66.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M126.479996,118.000000 L126.300003,118.119995 L126.059998,117.700012 L126.239990,117.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M213.419998,66.820007 L213.180008,66.400024 L126.240005,117.580017 L126.479996,118.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M102.839996,121.540039 L102.599991,121.060059 L101.580002,121.600037 L101.819992,122.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M102.059998,121.480042 L104.220001,123.460022 L103.199997,123.640015 L96.720001,125.020020 L95.099991,125.380066 L96.300003,124.180054 L101.039993,119.560059 L101.759995,118.840027 L101.880005,119.860046 L101.759995,120.280029 L97.020004,124.900024 L96.300003,124.180054 L96.539993,124.060059 L103.020004,122.680054 L103.199997,123.640015 L102.779999,123.520020 L101.339996,122.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.880005,119.860046 L102.180008,121.780029 L101.340012,122.200073 L101.220001,122.080017 L101.220001,121.900024 L100.919998,119.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.699997,121.840027 L103.139999,123.160034 L96.660004,124.540039 L101.399994,119.920044" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.620010,66.820007 L205.800003,66.700012 L205.560013,66.280029 L205.380020,66.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M102.839996,121.540039 L102.660004,121.660034 L102.419998,121.240051 L102.599991,121.120056" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.620010,66.820007 L205.380020,66.400024 L102.600021,121.119995 L102.840012,121.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="262.260010" y="38.140015" width="0.480010" height="4.080000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="294.659973" y="87.940063" width="0.479980" height="4.680000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.199997" y="243.880035" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="52.199997" y="243.640045" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.960007" y="243.880035" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="51.960007" y="261.640045" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="51.960007" y="243.640045" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="124.199997" y="243.880035" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="124.199997" y="243.640045" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="195.960007" y="243.880035" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.960007" y="261.640045" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="123.960007" y="243.640045" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.199997" y="243.880035" width="72.059998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="196.199997" y="243.640045" width="72.300003" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.020020" y="243.880035" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="195.960007" y="261.640045" width="72.300003" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="195.960007" y="243.640045" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.260010" y="243.880035" width="72.000000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="268.260010" y="243.640045" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.020020" y="243.880035" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.020020" y="261.640045" width="72.239998" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.020020" y="243.640045" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.599976,289.720032 L264.239990,290.080017 L265.140015,290.800018 L265.500000,290.440033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.840027,290.440033 L265.440002,288.640045 L265.739990,287.620026 L266.340027,288.580048 L270.119995,293.980042 L271.140015,295.420044 L269.520020,294.700043 L263.460022,292.060028 L262.500000,291.640045 L263.400024,291.160034 L263.880005,291.160034 L269.940002,293.800018 L269.520020,294.700043 L269.280029,294.520020 L265.500000,289.120026 L266.340027,288.580048 L266.400024,289.000031 L265.799988,290.800018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.400024,291.160034 L265.080017,290.200043 L265.799988,290.800049 L265.739990,290.980042 L265.559998,291.040039 L263.880005,292.000031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M265.320007,290.620026 L265.919983,288.820038 L269.700012,294.220032 L263.640015,291.580017" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.060013,264.580017 L233.880020,264.460022 L233.580002,264.820007 L233.760025,264.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M264.599976,289.720032 L264.779968,289.840027 L264.479980,290.200043 L264.299988,290.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.060013,264.580017 L233.760025,264.940002 L264.299988,290.080017 L264.600037,289.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M303.059998,337.360016 L303.000000,336.340027 L303.000000,336.400024 L302.820007,335.380005 L302.880005,335.440002 L302.520020,334.540009 L302.040039,333.580017 L302.040039,333.640015 L301.380005,332.800018 L300.660034,331.960022 L300.720032,331.960022 L299.940002,331.240021 L298.980042,330.520020 L298.980042,330.580017 L297.960022,329.920013 L296.880005,329.380005 L296.940002,329.380005 L295.739990,328.900024 L294.480042,328.480011 L293.160034,328.120026 L293.220032,328.120026 L291.840027,327.880005 L290.400024,327.700012 L287.460022,327.700012 L287.520020,327.700012 L286.080017,327.880005 L284.700012,328.120026 L283.380005,328.480011 L283.440002,328.480011 L282.179993,328.900024 L280.980042,329.380005 L279.900024,329.920013 L278.880005,330.580017 L278.940002,330.520020 L277.980042,331.240021 L277.140015,331.960022 L276.419983,332.800018 L276.480042,332.800018 L275.880005,333.640015 L275.880005,333.580017 L275.400024,334.540009 L275.040039,335.440002 L275.040039,335.380005 L274.859985,336.400024 L274.739990,337.420013 L274.739990,337.360016 L274.859985,338.320007 L275.040039,339.340027 L275.040039,339.280029 L275.400024,340.240021 L275.400024,340.180023 L275.880005,341.080017 L276.480042,341.920013 L276.419983,341.920013 L277.140015,342.760010 L277.140015,342.700012 L277.980042,343.480011 L278.940002,344.140015 L278.880005,344.140015 L279.900024,344.800018 L279.660034,345.220001 L278.640015,344.560028 L277.679993,343.900024 L277.679993,343.840027 L276.840027,343.060028 L276.780029,343.060028 L276.059998,342.220001 L275.460022,341.380005 L275.460022,341.320007 L274.980042,340.420013 L274.619995,339.460022 L274.559998,339.400024 L274.380005,338.380005 L274.260010,337.420013 L274.260010,337.360016 L274.380005,336.340027 L274.559998,335.320007 L274.619995,335.260010 L274.980042,334.360016 L274.980042,334.300018 L275.460022,333.340027 L276.059998,332.500031 L276.780029,331.660004 L276.840027,331.600006 L277.679993,330.880005 L278.640015,330.160004 L279.660034,329.500031 L280.739990,328.960022 L280.799988,328.960022 L282.000000,328.480011 L282.000000,328.420013 L283.260010,328.000031 L284.580017,327.640015 L284.640015,327.640015 L286.020020,327.400024 L287.460022,327.220001 L290.460022,327.220001 L291.900024,327.400024 L293.280029,327.640015 L294.600037,328.000031 L294.660034,328.000031 L295.919983,328.420013 L295.919983,328.480011 L297.119995,328.960022 C299.484985 330.076019,300.900024 331.210022,302.400024 333.340027  L302.460022,333.340027 L302.940002,334.300018 L302.940002,334.360016 L303.299988,335.260010 L303.299988,335.320007 L303.480042,336.340027 L303.540039,337.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M279.900024,344.800018 L280.979980,345.340027 L282.179993,345.880005 L282.179993,345.820007 L283.440002,346.240021 L283.380005,346.240021 L284.700012,346.540009 L286.080017,346.780029 L287.520020,346.960022 L287.460022,346.960022 L288.900024,347.020020 L290.400024,346.960022 L291.840027,346.780029 L293.220032,346.540009 L293.160034,346.540009 L294.479980,346.240021 L295.739990,345.820007 L295.739990,345.880005 L296.940002,345.340027 L296.880005,345.340027 L297.960022,344.800018 L298.979980,344.140015 L299.940002,343.480011 L299.880005,343.480011 L300.660034,342.700012 L300.660034,342.760010 L301.380005,341.920013 L302.039978,341.080017 L302.520020,340.180023 L302.520020,340.240021 L302.880005,339.280029 L302.820007,339.340027 L303.000000,338.320007 L303.059998,337.360016 L303.539978,337.360016 L303.479980,338.320007 C303.309021 340.741028,301.871033 342.196014,300.239990 343.840027  L300.239990,343.900024 L299.280029,344.560028 L299.220032,344.560028 C297.059021 346.078033,294.509033 346.941010,291.900024 347.260010  L290.460022,347.440033 L290.400024,347.440033 C287.687988 347.696014,283.249023 347.081024,280.799988 345.760010  L280.739990,345.760010 L279.660034,345.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.440002" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="304.440002" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="337.799988" y="365.260040" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.200012" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.200012" y="365.020050" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="271.020020" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="304.380005" y="365.260040" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.780029" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="270.780029" y="365.020050" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.659988" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="237.659988" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="271.020020" y="365.260040" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.419998" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.419998" y="365.020050" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.240005" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="204.240005" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.599991" y="365.260040" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.000015" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.000015" y="365.020050" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.819992" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="170.819992" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.180008" y="365.260040" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.580002" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.580002" y="365.020050" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.399994" y="365.260040" width="33.660000" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="137.399994" y="365.020020" width="33.900002" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.819992" y="365.260040" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.160004" y="383.020020" width="33.900002" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.160004" y="365.020050" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.039993" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="104.039993" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.399994" y="365.260040" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.800003" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.800003" y="365.020050" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="70.619995" y="365.260040" width="33.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="70.619995" y="365.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.979996" y="365.260040" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="70.380005" y="383.020020" width="33.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="70.380005" y="365.020050" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.440002" y="325.660034" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.440002" y="325.420044" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="154.800003" y="325.660034" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.199997" y="343.420044" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.199997" y="325.420044" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="115.199997" y="321.340027" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="115.199997" y="321.100006" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="175.560013" y="321.340027" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.960007" y="339.100006" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.960007" y="321.100037" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="135.960007" y="316.960022" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="135.960007" y="316.720032" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.319992" y="316.960052" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="135.720001" y="334.720032" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="135.720001" y="316.720032" width="0.480000" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="156.719986" y="312.640015" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="156.719986" y="312.400024" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.080002" y="312.640045" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="156.479996" y="330.400024" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="156.479996" y="312.400024" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.539993" y="308.260040" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="177.539993" y="308.020020" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="237.900009" y="308.260040" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.300003" y="326.020050" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="177.300003" y="308.020050" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.300003" y="303.940033" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="198.300003" y="303.700043" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="258.659973" y="303.940033" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.060013" y="321.700043" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="198.060013" y="303.700043" width="0.479980" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="219.060013" y="299.620026" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="219.060013" y="299.380035" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.419983" y="299.620026" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="218.819992" y="317.380035" width="60.840000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="218.819992" y="299.380035" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="239.819992" y="295.240021" width="60.599998" height="18.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="239.819992" y="295.000031" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="300.179993" y="295.240051" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="239.580002" y="313.000031" width="60.840000" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="239.580002" y="295.000031" width="0.480010" height="18.240000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="269.039978" y="296.320038" width="0.479980" height="17.280001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="284.219971" y="295.960022" width="0.479980" height="17.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="253.259995" y="295.120056" width="0.480010" height="18.299999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.259995" y="243.820038" width="71.400002" height="17.459999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="196.259995" y="243.580017" width="71.639999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="267.419983" y="243.820007" width="0.480010" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.020004" y="261.040039" width="71.639999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="196.020004" y="243.580017" width="0.480010" height="17.700001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="230.699997" y="244.000031" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.580002" y="243.880035" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="212.099991" y="243.520020" width="0.480010" height="17.940001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M278.700012,276.400024 L278.580017,275.260010 L278.279968,274.180023 L278.340027,274.240021 L277.859985,273.160034 L277.200012,272.140015 L277.200012,272.200012 L276.359985,271.240021 L276.419983,271.240021 L275.400024,270.280029 L274.260010,269.440033 L274.260010,269.500031 L273.000000,268.720032 L271.619995,268.000031 L271.679993,268.000031 L270.119995,267.340027 L268.500000,266.800018 L266.760010,266.320038 L264.960022,265.960022 L265.020020,265.960022 L263.099976,265.720032 L261.119995,265.540039 L259.140015,265.480011 L257.099976,265.540039 L257.159973,265.540039 L255.180008,265.720032 L253.319992,265.960022 L251.460007,266.320038 L249.719986,266.800018 L249.779984,266.800018 L248.159988,267.340027 L246.659988,268.000031 L245.219986,268.720032 L243.960007,269.500031 L244.020004,269.440033 L242.879990,270.280029 L241.919998,271.240021 L241.080002,272.200012 L241.139999,272.140015 L240.479996,273.160034 L239.939987,274.240021 L239.939987,274.180023 L239.639999,275.260010 L239.639999,275.200012 L239.580002,276.340027 L239.639999,277.480011 L239.639999,277.420013 L239.939987,278.500031 L239.939987,278.440033 L240.479996,279.520020 L241.139999,280.540039 L241.080002,280.540039 L241.919998,281.500031 L241.919998,281.440033 L242.879990,282.340027 L244.020004,283.240021 L243.960007,283.240021 L245.219986,284.020020 L246.659988,284.740021 L246.479996,285.160034 L246.419998,285.160034 L244.979996,284.440033 L243.719986,283.660034 L243.719986,283.600037 L242.580002,282.700012 C240.781998 281.256012,238.939987 278.784027,239.099991 276.340027  L239.159988,275.200012 L239.159988,275.140015 C240.038010 271.548035,243.155991 269.004028,246.419998 267.580017  L246.479996,267.580017 L247.979996,266.920013 L247.979996,266.860016 L249.599991,266.320038 L251.339981,265.840027 L253.199997,265.480011 L253.259995,265.480011 L255.120010,265.240021 L257.099976,265.060028 L259.140015,265.000031 L261.119995,265.060028 C263.724976 265.253021,266.119019 265.510010,268.619995 266.320038  L268.679993,266.320038 L270.299988,266.860016 L270.299988,266.920013 L271.859985,267.580017 C274.218018 268.771027,275.950989 269.778015,277.559998 271.900024  L277.619995,271.900024 L278.279968,272.920013 L278.279968,272.980011 L278.760010,274.060028 L279.059998,275.140015 L279.059998,275.200012 L279.179993,276.340027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M246.659988,284.740021 L248.159988,285.340027 L248.159988,285.280029 L249.779984,285.880035 L249.719986,285.880035 L251.459976,286.300018 L253.319992,286.720032 L255.179977,286.960022 L257.159973,287.140015 L257.099976,287.140015 L259.140015,287.200012 L261.119995,287.140015 L263.099976,286.960022 L265.019958,286.720032 L264.959961,286.720032 L266.760010,286.300018 L268.500000,285.880035 L270.119995,285.280029 L270.119995,285.340027 L271.679993,284.740021 L271.619995,284.740021 L273.000000,284.020020 L274.260010,283.240021 L275.399963,282.340027 L276.419983,281.440033 L276.359985,281.500031 L277.200012,280.540009 L277.859985,279.520020 L277.859985,279.580017 L278.339966,278.500031 L278.279968,278.500031 L278.580017,277.420013 L278.580017,277.480011 L278.700012,276.340027 L278.700012,276.400024 L279.179993,276.340027 L279.179993,276.400024 C278.071960 288.172028,256.200012 289.574036,247.979996 285.760010  L246.479996,285.160034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.719971,354.400024 L276.239990,354.520020 L276.659973,355.600037 L277.140015,355.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.539978,355.180023 L277.979980,353.920013 L278.760010,353.140015 L278.880005,354.280029 L279.419983,360.880035 L279.479980,362.560028 L278.520020,361.240021 L274.559998,355.900024 L273.899963,355.000031 L274.919983,355.000031 L275.339966,355.240021 L279.299988,360.580017 L278.520020,361.240021 L278.399963,360.940033 L277.859985,354.340027 L278.880005,354.280029 L278.700012,354.640015 L277.260010,355.900024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M274.919983,355.000031 L276.900024,355.000031 L277.260010,355.900024 L277.080017,356.020020 L276.900024,356.080017 L274.919983,356.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.900024,355.540039 L278.340027,354.280029 L278.880005,360.880035 L274.919983,355.540039" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.400024,318.400024 L263.340027,318.160034 L262.859985,318.340027 L262.919983,318.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M276.719971,354.400024 L276.779968,354.640015 L276.299988,354.820038 L276.239990,354.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M263.400024,318.400024 L262.919983,318.580017 L276.239990,354.580017 L276.720032,354.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.000015,300.760040 L215.520004,300.520050 L215.100021,301.600037 L215.580002,301.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M215.340012,301.180023 L217.260025,301.300018 L218.340012,301.360016 L217.620010,302.200012 L213.360001,307.300018 L212.220016,308.620026 L212.460007,306.880035 L213.360001,300.340027 L213.480026,299.380035 L214.199997,299.980011 L214.380020,300.460022 L213.480026,307.000031 L212.460007,306.880035 L212.580002,306.640015 L216.840012,301.540009 L217.620010,302.200012 L217.199997,302.380035 L215.280014,302.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M214.199997,299.980042 L215.639999,301.300049 L215.279984,302.260040 L215.099991,302.200043 L214.979996,302.080048 L213.539993,300.760040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M215.340012,301.720032 L217.260025,301.840027 L213.000015,306.940033 L213.900009,300.400024" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.300003,266.320038 L231.360001,266.140045 L230.940018,265.960052 L230.879990,266.140045" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M216.000015,300.760040 L215.940018,300.940033 L215.520004,300.760040 L215.580002,300.580048" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.300003,266.320038 L230.879990,266.140045 L215.580002,300.580048 L216.000015,300.760040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.960007,354.940033 L252.479996,355.060028 L252.840012,356.140045 L253.319992,356.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.780014,355.660034 L254.280014,354.460022 L255.060013,353.860046 L255.120010,354.880035 L255.420029,361.480042 L255.480026,363.220032 L254.460007,361.780029 L250.740005,356.320038 L250.139999,355.480042 L251.160019,355.480042 L251.580002,355.780029 L255.300003,361.240021 L254.460007,361.780029 L254.400009,361.540039 L254.100021,354.940033 L255.120010,354.880035 L254.880020,355.300049 L253.380020,356.500031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M251.159988,355.480042 L253.080002,355.540039 L253.379990,356.500031 L253.259995,356.620056 L253.080002,356.620056 L251.159988,356.560028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M253.080002,356.080017 L254.580002,354.880005 L254.879990,361.480011 L251.159988,356.020020" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M241.979996,322.180023 L241.919998,321.940033 L241.439987,322.120026 L241.499985,322.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M252.960007,354.940033 L253.020004,355.180023 L252.539993,355.360046 L252.479996,355.120026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M241.979996,322.180023 L241.499985,322.360016 L252.479996,355.120026 L252.960007,354.940033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M312.299988,356.560028 L311.940002,356.920013 L312.720032,357.760040 L313.080017,357.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M312.419983,357.340027 L313.320007,355.660034 L313.799988,354.760040 L314.279968,355.720032 L317.159973,361.660034 L317.940002,363.220032 L316.440002,362.320038 L310.859985,358.840027 L310.020020,358.300018 L310.859985,357.940033 L311.400024,357.940033 L316.979980,361.420013 L316.440002,362.320038 L316.260010,362.080017 L313.380005,356.140015 L314.279968,355.720032 L314.279968,356.140015 L313.380005,357.820038" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M310.859985,357.940033 L312.659973,357.160034 L313.380005,357.820038 L313.260010,358.000031 L313.080017,358.060028 L311.280029,358.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M312.900024,357.580017 L313.799988,355.900024 L316.679993,361.840027 L311.100037,358.360016" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M273.900024,313.960022 L273.780029,313.780029 L273.419983,314.080017 L273.540039,314.260010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M312.299988,356.620026 L312.419983,356.800018 L312.059998,357.100037 L311.940002,356.920013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M273.900024,313.960022 L273.540039,314.260010 L311.940002,356.920013 L312.299988,356.620026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.479996" y="298.720032" width="0.480010" height="1.200000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.539993,299.440033 L236.339981,298.660034 L237.240005,298.180023 L236.999985,299.320038 L235.499985,305.740021 L235.080002,307.420044 L234.539993,305.740021 L232.439987,299.500031 L232.080002,298.540039 L233.099991,298.840027 L233.399979,299.200043 L235.499985,305.440033 L234.539993,305.740021 L234.539993,305.440033 L236.039993,299.020020 L236.999985,299.320038 L236.699997,299.620026 L234.899979,300.400024" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M233.099991,298.840027 L234.899979,299.440033 L234.899979,300.400024 L234.719986,300.460022 L232.740005,299.800018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M234.719986,299.920044 L236.519974,299.140045 L235.019974,305.560059 L232.919998,299.320038" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="233.039993" y="266.320038" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.479996" y="298.720032" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M233.520004,266.560028 L233.039993,266.560028 L234.479996,298.720032 L234.960007,298.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.120010,306.280029 L194.760025,305.920044 L194.040024,306.820038 L194.400009,307.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.400009,306.520020 L196.199997,307.120026 L197.220016,307.420013 L196.259995,308.020020 L190.860001,311.800018 L189.419998,312.820007 L190.139999,311.200012 L192.720016,305.140015 L193.139999,304.180023 L193.620010,305.080017 L193.620010,305.560028 L191.040024,311.560028 L190.139999,311.200012 L190.320023,310.960022 L195.720016,307.180023 L196.259995,308.020020 L195.840012,308.080017 L194.040024,307.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.620010,305.080017 L194.639999,306.760010 L194.040024,307.480011 L193.860001,307.420013 L193.800003,307.240021 L192.780014,305.560028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.219986,307.000031 L196.019974,307.600037 L190.619980,311.380035 L193.199997,305.320038" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.479996,265.360016 L228.599991,265.180023 L228.240005,264.880005 L228.120010,265.060028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M195.120010,306.280029 L195.000015,306.460022 L194.639999,306.160034 L194.760025,305.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M228.479996,265.360016 L228.120010,265.060028 L194.759995,305.980011 L195.120010,306.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="222.180008" y="353.920013" width="0.480010" height="1.140000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.240005,354.580017 L224.039993,353.920013 L225.000015,353.500031 L224.699997,354.580017 L222.960007,360.940002 L222.479996,362.560028 L222.000015,360.940002 L220.080002,354.640015 L219.780014,353.680023 L220.680008,353.980011 L221.039993,354.340027 L222.960007,360.640015 L222.000015,360.940002 L222.000015,360.640015 L223.740005,354.280029 L224.699997,354.580017 L224.400009,354.880005 L222.599991,355.540009" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M220.680008,353.980042 L222.539993,354.580048 L222.600021,355.540039 L222.419998,355.600037 L222.240005,355.540039 L220.380020,354.940033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.419998,355.060028 L224.219986,354.400024 L222.479996,360.760040 L220.560013,354.460022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="221.879990" y="327.640045" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="222.180008" y="353.920044" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.360001,327.880035 L221.879990,327.880035 L222.180008,353.920044 L222.659988,353.920044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.520004,355.420044 L194.039993,355.180054 L193.560013,356.260040 L194.039993,356.500031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.860001,355.840027 L195.780014,356.020020 L196.800003,356.080017 L196.080002,356.920013 L191.819992,361.900024 L190.680008,363.160034 L190.919998,361.480042 L191.879990,354.940033 L192.060013,353.920013 L192.780014,354.640015 L192.900009,355.120026 L191.939987,361.660034 L190.919998,361.480042 L191.099991,361.240021 L195.360001,356.260040 L196.080002,356.920013 L195.659988,357.100037 L193.740005,356.920013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M192.780014,354.640015 L194.160019,356.020020 L193.740005,356.920013 L193.560013,356.860016 L192.060013,355.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M193.800003,356.380035 L195.720016,356.560028 L191.460007,361.540039 L192.419998,355.000031" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.199997,332.380035 L205.259995,332.200043 L204.840012,332.020050 L204.779984,332.200043" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M194.520004,355.420044 L194.460007,355.600037 L194.039993,355.420044 L194.099991,355.240051" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M205.199997,332.380035 L204.779984,332.200043 L194.099991,355.240051 L194.520004,355.420044" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M167.699997,356.200043 L167.340012,355.840057 L166.499985,356.620056 L166.860001,356.980042" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.919998,356.320038 L168.659988,357.160034 L169.560013,357.640045 L168.599991,358.120026 L162.779984,361.180023 L161.279984,361.960052 L162.120010,360.460052 L165.419998,354.760040 L165.960007,353.860046 L166.379990,354.820038 L166.319992,355.240051 L163.020004,360.940033 L162.120010,360.460052 L162.360001,360.280029 L168.180008,357.220032 L168.599991,358.120026 L168.180008,358.120026 L166.439987,357.280029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.379990,354.820038 L167.159988,356.620026 L166.439987,357.280029 L166.319992,357.160034 L166.199997,356.980042 L165.419998,355.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M166.680008,356.800018 L168.419998,357.640015 L162.600021,360.700012 L165.900009,355.000031" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.520004,336.220032 L188.699997,336.040039 L188.340012,335.680023 L188.160019,335.860046" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M167.699997,356.200043 L167.520004,356.380035 L167.159988,356.020050 L167.340012,355.840057" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M188.520004,336.220032 L188.160019,335.860046 L167.340012,355.840027 L167.699997,356.200043" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.720001,358.780029 L138.479996,358.420044 L137.520004,359.020020 L137.759995,359.380035" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M137.940002,358.780029 L139.440002,359.980042 L140.279999,360.640015 L139.260010,360.880035 L131.279999,363.160034 L132.419998,361.900024 L136.800003,357.040039 L137.520004,356.260040 L137.699997,357.220032 L137.580002,357.700043 L133.199997,362.560028 L132.419998,361.900024 L132.660004,361.720032 L138.960007,359.920044 L139.260010,360.880035 L138.839996,360.820038 L137.339996,359.620026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M137.699997,357.220032 L138.119995,359.080017 L137.339996,359.620026 L137.160004,359.500031 L137.160004,359.320038 L136.739990,357.460022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M137.639999,359.200043 L139.139999,360.400055 L132.839996,362.200043 L137.220001,357.340057" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M168.840012,340.120026 L169.020004,340.000031 L168.780014,339.580017 L168.600021,339.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.720001,358.840027 L138.540009,358.960022 L138.300003,358.540039 L138.479996,358.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M168.840012,340.120026 L168.600021,339.700012 L138.480011,358.420013 L138.720016,358.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.039993,361.060028 L100.919998,360.580017 L99.839996,360.940033 L99.959991,361.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.259995,360.820038 L101.519989,362.320038 L102.239990,363.100037 L101.159988,363.220032 L94.559998,363.700043 L92.819992,363.820038 L94.199997,362.800049 L99.539993,358.900024 L100.439987,358.240051 L100.439987,359.260040 L100.199997,359.680023 L94.860001,363.580048 L94.199997,362.800049 L94.500000,362.680023 L101.099991,362.200043 L101.159988,363.220032 L100.799988,363.040039 L99.539993,361.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M100.440002,359.260040 L100.440002,361.180054 L99.540009,361.540039 L99.419998,361.360046 L99.360001,361.180054 L99.360001,359.260040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M99.899994,361.180023 L101.159988,362.680023 L94.559998,363.160034 L99.899994,359.260010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,345.100037 L144.719986,345.040039 L144.539993,344.560028 L144.300003,344.620026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M101.100006,361.060028 L100.860001,361.120026 L100.680008,360.640015 L100.920013,360.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.479996,345.100037 L144.300003,344.620026 L100.919998,360.580048 L101.099991,361.060028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M177.060013,306.760040 L176.700027,306.400055 L175.800003,307.180054 L176.160019,307.540039" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M176.219986,306.940033 L177.899979,307.900024 L178.799973,308.380035 L177.839981,308.800018 L171.839981,311.500031 L170.219986,312.220032 L171.239975,310.780029 L174.899979,305.260040 L175.439987,304.360046 L175.799973,305.320038 L175.739975,305.800018 L172.079971,311.320038 L171.239975,310.780029 L171.419998,310.600037 L177.419998,307.900024 L177.839981,308.800018 L177.419998,308.740021 L175.739975,307.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M175.800003,305.320038 L176.460007,307.180023 L175.740005,307.780029 L175.560013,307.720032 L175.500015,307.540039 L174.840012,305.680023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M175.979996,307.360016 L177.659988,308.320007 L171.659988,311.020020 L175.319992,305.500031" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.659988,265.540039 L225.839981,265.420044 L225.539993,265.060028 L225.360001,265.180054" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M177.060013,306.760040 L176.880020,306.880035 L176.580002,306.520050 L176.760025,306.400055" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.659988,265.540039 L225.360001,265.180054 L176.759995,306.400024 L177.059982,306.760040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.319992,312.460022 L154.080002,312.100037 L153.119980,312.760010 L153.360001,313.120026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.539993,312.520020 L155.099991,313.600006 L155.939987,314.200012 L154.919998,314.500031 L148.680008,316.600006 L147.059982,317.200012 L148.139999,315.820007 L152.339981,310.720032 L152.999985,309.880005 L153.240005,310.900024 L153.119980,311.320007 L148.919998,316.420013 L148.139999,315.820007 L148.379990,315.640015 L154.619980,313.540009 L154.919998,314.500031 L154.499985,314.440033 L152.939987,313.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.240005,310.900024 L153.720016,312.820038 L152.940018,313.360016 L152.819992,313.240021 L152.759995,313.060028 L152.280014,311.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M153.240005,312.940033 L154.800003,314.020020 L148.560013,316.120026 L152.759995,311.020020" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.060013,265.600037 L222.240005,265.480042 L221.940018,265.060028 L221.760025,265.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M154.379990,312.520020 L154.199997,312.640015 L153.899979,312.220032 L154.080002,312.100006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.060013,265.600037 L221.760025,265.180023 L154.080002,312.100037 L154.380020,312.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M132.059998,316.180023 L131.819992,315.820038 L130.800003,316.420013 L131.039993,316.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M131.220001,316.180023 L132.720001,317.380035 L133.619995,318.040009 L132.479996,318.280029 L126.119995,319.960022 L124.500000,320.380035 L125.639999,319.180023 L130.139999,314.380035 L130.860001,313.600037 L131.040009,314.620026 L130.919998,315.040009 L126.419998,319.840027 L125.639999,319.180023 L125.940002,319.000031 L132.300003,317.320038 L132.479996,318.280029 L132.119995,318.220032 L130.619995,317.020020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M131.039993,314.620026 L131.399994,316.540039 L130.619995,317.020020 L130.439987,316.900024 L130.439987,316.660034 L130.079987,314.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M130.919998,316.600037 L132.419998,317.800049 L126.059998,319.480042 L130.559998,314.680023" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M219.000015,265.000031 L219.180008,264.880035 L218.940018,264.460022 L218.760025,264.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M132.059998,316.240021 L131.880005,316.360016 L131.639999,315.940033 L131.819992,315.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M219.000015,265.000031 L218.760025,264.580017 L131.820023,315.820038 L132.060013,316.240021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M108.419998,319.780029 L108.179993,319.300018 L107.160004,319.840027 L107.399994,320.320038" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.639999,319.720032 L109.080002,320.980042 L109.860001,321.580017 L108.779999,321.820038 L102.360001,323.200043 L100.679993,323.620026 L101.940002,322.360046 L106.679993,317.800018 L107.399994,317.080017 L107.520004,318.100037 L107.399994,318.520020 L102.660004,323.080017 L101.940002,322.360046 L102.179993,322.240021 L108.600006,320.860046 L108.779999,321.820038 L108.360001,321.700043 L106.919998,320.440033" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.520004,318.100037 L107.760010,320.020050 L106.919998,320.440033 L106.800003,320.320038 L106.800003,320.140045 L106.559998,318.220032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.279999,320.080017 L108.720001,321.340027 L102.300003,322.720032 L107.039993,318.160004" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.199997,265.000031 L211.379990,264.880035 L211.139999,264.460022 L210.960007,264.580017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M108.419998,319.780029 L108.240005,319.900024 L108.000000,319.480042 L108.179993,319.360016" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M211.199997,265.000031 L210.960007,264.580017 L108.180008,319.360046 L108.419998,319.780029" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="267.840027" y="236.320038" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="267.840027" y="236.560028" width="0.479980" height="3.840000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="300.239990" y="286.120026" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="300.239990" y="286.360016" width="0.480010" height="4.440000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="69.016953" y="328.960480" textLength="4.442996" font-size="8px">1</text>
<text x="65.011856" y="328.960480" textLength="3.995500" font-size="8px">c</text>
<text x="57.001678" y="328.960480" textLength="5.329997" font-size="8px">S</text>
<text x="77.754288" y="194.141113" textLength="4.442996" font-size="8px">n</text>
<text x="73.311295" y="194.141113" textLength="4.442996" font-size="8px">o</text>
<text x="71.537292" y="194.141113" textLength="1.774002" font-size="8px">i</text>
<text x="64.872803" y="194.141113" textLength="4.442996" font-size="8px">a</text>
<text x="60.429810" y="194.141113" textLength="4.442996" font-size="8px">n</text>
<text x="52.438812" y="194.141113" textLength="3.995500" font-size="8px">s</text>
<text x="112.681335" y="241.360718" textLength="4.442996" font-size="8px">9</text>
<text x="58.919479" y="241.121002" textLength="4.442996" font-size="8px">7</text>
<text x="54.480484" y="241.121002" textLength="4.442996" font-size="8px">2</text>
<text x="50.041489" y="241.121002" textLength="4.442996" font-size="8px">1</text>
<text x="336.060181" y="240.341095" textLength="4.442996" font-size="8px">0</text>
<text x="295.500244" y="361.180206" textLength="4.442996" font-size="8px">1</text>
<text x="72.300430" y="362.139923" textLength="4.442996" font-size="8px">2</text>
<text x="67.861435" y="362.139923" textLength="4.442996" font-size="8px">1</text>
<text x="80.575348" y="394.359314" textLength="4.442996" font-size="8px">n</text>
<text x="76.076416" y="394.359314" textLength="4.442996" font-size="8px">o</text>
<text x="74.337570" y="394.359314" textLength="1.774002" font-size="8px">i</text>
<text x="67.666672" y="394.359314" textLength="4.442996" font-size="8px">a</text>
<text x="61.443283" y="394.359314" textLength="1.774002" font-size="8px">i</text>
<text x="55.219879" y="394.359314" textLength="3.995500" font-size="8px">s</text>
<text x="50.773682" y="394.359314" textLength="4.442996" font-size="8px">e</text>
<text x="45.000977" y="394.359314" textLength="5.769502" font-size="8px">D</text>
<text x="65.835922" y="274.779572" textLength="4.442996" font-size="8px">2</text>
<text x="334.080017" y="361.360016" textLength="4.442996" font-size="8px">0</text>
<text x="61.830826" y="274.779572" textLength="3.995500" font-size="8px">c</text>
<text x="59.160233" y="274.779572" textLength="2.661003" font-size="8px">r</text>
<text x="53.820648" y="274.779572" textLength="5.329997" font-size="8px">S</text>
<text x="326.700500" y="281.739746" textLength="4.442996" font-size="8px">2</text>
<text x="319.142639" y="281.739746" textLength="3.108499" font-size="8px">*</text>
<text x="312.422180" y="281.739746" textLength="4.442996" font-size="8px">2</text>
<text x="310.199097" y="281.739746" textLength="2.221498" font-size="8px">[</text>
<text x="294.659790" y="281.739746" textLength="2.221498" font-size="8px">I</text>
<text x="293.880615" y="231.760040" textLength="4.442996" font-size="8px">3</text>
<text x="290.771301" y="231.760040" textLength="3.108499" font-size="8px">*</text>
<text x="288.549011" y="231.760040" textLength="2.221498" font-size="8px">]</text>
<text x="281.882935" y="231.760040" textLength="2.221498" font-size="8px">:</text>
<text x="277.439148" y="231.760040" textLength="4.442996" font-size="8px">1</text>
<text x="275.216858" y="231.760040" textLength="2.221498" font-size="8px">[</text>
<text x="259.679993" y="231.760040" textLength="2.221498" font-size="8px">I</text>
<text x="290.279419" y="338.980042" textLength="6.656503" font-size="8px">m</text>
<text x="280.500000" y="338.980042" textLength="5.329997" font-size="8px">S</text>
<text x="273.236572" y="278.500031" textLength="2.221498" font-size="8px">.</text>
<text x="271.015076" y="278.500031" textLength="2.221498" font-size="8px">f</text>
<text x="267.192993" y="278.500031" textLength="1.774002" font-size="8px">i</text>
<text x="259.195618" y="278.500031" textLength="2.221498" font-size="8px"> </text>
<text x="256.967712" y="278.500031" textLength="2.221498" font-size="8px">.</text>
<text x="62.341263" y="328.960480" textLength="2.661003" font-size="8px">r</text>
<text x="252.965805" y="278.500031" textLength="3.995500" font-size="8px">s</text>
<text x="243.180008" y="278.500031" textLength="5.329997" font-size="8px">A</text>
<text x="189.359116" y="43.360474" textLength="4.442996" font-size="8px">2</text>
<text x="184.920120" y="43.360474" textLength="4.442996" font-size="8px">9</text>
<text x="180.481125" y="43.360474" textLength="4.442996" font-size="8px">1</text>
<text x="303.541016" y="281.739746" textLength="6.656503" font-size="8px">m</text>
<text x="115.919418" y="43.120728" textLength="4.442996" font-size="8px">4</text>
<text x="111.480423" y="43.120728" textLength="4.442996" font-size="8px">2</text>
<text x="107.041428" y="43.120728" textLength="4.442996" font-size="8px">2</text>
<text x="44.461502" y="42.940918" textLength="4.442996" font-size="8px">2</text>
<text x="330.480164" y="42.161011" textLength="4.442996" font-size="8px">1</text>
<text x="265.434204" y="80.320007" textLength="2.221498" font-size="8px">f</text>
<text x="322.201599" y="281.739746" textLength="4.442996" font-size="8px">3</text>
<text x="261.902283" y="231.760040" textLength="6.656503" font-size="8px">m</text>
<text x="261.593750" y="80.320007" textLength="1.774002" font-size="8px">i</text>
<text x="53.339493" y="42.940918" textLength="4.442996" font-size="8px">5</text>
<text x="297.959351" y="83.559692" textLength="6.656503" font-size="8px">m</text>
<text x="53.535477" y="76.539612" textLength="2.661003" font-size="8px">r</text>
<text x="296.882874" y="281.739746" textLength="6.656503" font-size="8px">m</text>
<text x="42.181564" y="194.141113" textLength="5.769502" font-size="8px">D</text>
<text x="54.631042" y="133.719238" textLength="3.995500" font-size="8px">c</text>
<text x="321.058105" y="83.559692" textLength="4.442996" font-size="8px">2</text>
<text x="330.169434" y="83.559692" textLength="4.442996" font-size="8px">1</text>
<text x="71.159439" y="163.959869" textLength="4.442996" font-size="8px">5</text>
<text x="285.833191" y="338.980042" textLength="4.442996" font-size="8px">u</text>
<text x="190.500107" y="241.540527" textLength="4.442996" font-size="8px">4</text>
<text x="332.939026" y="163.120026" textLength="4.442996" font-size="8px">2</text>
<text x="278.520447" y="33.520020" textLength="4.442996" font-size="8px">3</text>
<text x="66.720444" y="163.959869" textLength="4.442996" font-size="8px">5</text>
<text x="59.218582" y="394.359314" textLength="2.221498" font-size="8px">t</text>
<text x="268.973389" y="278.500031" textLength="2.221498" font-size="8px">f</text>
<text x="242.925980" y="80.320007" textLength="4.442996" font-size="8px">b</text>
<text x="289.860352" y="162.940216" textLength="4.442996" font-size="8px">1</text>
<text x="268.559570" y="231.760040" textLength="6.656503" font-size="8px">m</text>
<text x="186.061111" y="241.540527" textLength="4.442996" font-size="8px">6</text>
<text x="339.358154" y="42.161011" textLength="4.442996" font-size="8px">8</text>
<text x="56.434311" y="194.141113" textLength="2.221498" font-size="8px">t</text>
<text x="69.315796" y="194.141113" textLength="2.221498" font-size="8px">t</text>
<text x="248.516403" y="278.500031" textLength="4.442996" font-size="8px">b</text>
<text x="58.636139" y="133.719238" textLength="4.442996" font-size="8px">1</text>
<text x="316.921143" y="281.739746" textLength="2.221498" font-size="8px">]</text>
<text x="284.639404" y="140.740051" textLength="6.656503" font-size="8px">m</text>
<text x="63.220474" y="394.359314" textLength="4.442996" font-size="8px">n</text>
<text x="47.999817" y="194.141113" textLength="4.442996" font-size="8px">e</text>
<text x="284.105225" y="231.760040" textLength="4.442996" font-size="8px">0</text>
<text x="288.293457" y="33.520020" textLength="4.442996" font-size="8px">3</text>
<text x="325.501892" y="83.559692" textLength="4.666744" font-size="8px">+</text>
<text x="292.736450" y="33.520020" textLength="4.442996" font-size="8px">2</text>
<text x="289.079773" y="83.559692" textLength="2.221498" font-size="8px">I</text>
<text x="269.634460" y="33.520020" textLength="2.221498" font-size="8px">[</text>
<text x="311.282715" y="83.559692" textLength="2.221498" font-size="8px">]</text>
<text x="247.364975" y="80.320007" textLength="3.995500" font-size="8px">s</text>
<text x="58.655807" y="194.141113" textLength="1.774002" font-size="8px">i</text>
<text x="298.324402" y="231.760040" textLength="4.442996" font-size="8px">2</text>
<text x="334.919189" y="42.161011" textLength="4.442996" font-size="8px">2</text>
<text x="72.112869" y="394.359314" textLength="2.221498" font-size="8px">t</text>
<text x="276.298950" y="33.520020" textLength="2.221498" font-size="8px">:</text>
<text x="261.417114" y="278.500031" textLength="5.769502" font-size="8px">D</text>
<text x="262.977966" y="33.520020" textLength="6.656503" font-size="8px">m</text>
<text x="285.184937" y="33.520020" textLength="3.108499" font-size="8px">*</text>
<text x="263.332581" y="80.320007" textLength="2.221498" font-size="8px">f</text>
<text x="274.859985" y="140.740051" textLength="5.329997" font-size="8px">S</text>
<text x="271.855957" y="33.520020" textLength="4.442996" font-size="8px">4</text>
<text x="48.900497" y="42.940918" textLength="4.442996" font-size="8px">5</text>
<text x="62.281448" y="163.959869" textLength="4.442996" font-size="8px">2</text>
<text x="76.739426" y="362.139923" textLength="4.442996" font-size="8px">7</text>
<text x="280.193176" y="140.740051" textLength="4.442996" font-size="8px">u</text>
<text x="117.120331" y="241.360718" textLength="4.442996" font-size="8px">6</text>
<text x="48.180710" y="76.539612" textLength="5.329997" font-size="8px">S</text>
<text x="297.179443" y="33.520020" textLength="4.666744" font-size="8px">+</text>
<text x="339.057007" y="83.559692" textLength="4.442996" font-size="8px">8</text>
<text x="237.599991" y="80.320007" textLength="5.329997" font-size="8px">A</text>
<text x="251.325302" y="80.320007" textLength="2.221498" font-size="8px">.</text>
<text x="253.546799" y="80.320007" textLength="2.221498" font-size="8px"> </text>
<text x="267.655701" y="80.320007" textLength="2.221498" font-size="8px">.</text>
<text x="254.099991" y="33.520020" textLength="2.221498" font-size="8px">I</text>
<text x="256.321472" y="33.520020" textLength="6.656503" font-size="8px">m</text>
<text x="306.289185" y="33.520020" textLength="4.442996" font-size="8px">2</text>
<text x="282.963440" y="33.520020" textLength="2.221498" font-size="8px">]</text>
<text x="301.846191" y="33.520020" textLength="4.442996" font-size="8px">1</text>
<text x="310.732178" y="33.520020" textLength="4.442996" font-size="8px">8</text>
<text x="291.302063" y="83.559692" textLength="6.656503" font-size="8px">m</text>
<text x="299.939270" y="361.180206" textLength="4.442996" font-size="8px">6</text>
<text x="51.960449" y="133.719238" textLength="2.661003" font-size="8px">r</text>
<text x="304.616638" y="83.559692" textLength="2.221498" font-size="8px">[</text>
<text x="255.828232" y="80.320007" textLength="5.769502" font-size="8px">D</text>
<text x="306.838928" y="83.559692" textLength="4.442996" font-size="8px">5</text>
<text x="294.299316" y="162.940216" textLength="4.442996" font-size="8px">4</text>
<text x="313.505005" y="83.559692" textLength="3.108499" font-size="8px">*</text>
<text x="316.614319" y="83.559692" textLength="4.442996" font-size="8px">3</text>
<text x="334.613220" y="83.559692" textLength="4.442996" font-size="8px">2</text>
<text x="56.221252" y="76.539612" textLength="3.995500" font-size="8px">c</text>
<text x="60.181595" y="76.539612" textLength="4.442996" font-size="8px">2</text>
<text x="46.620865" y="133.719238" textLength="5.329997" font-size="8px">S</text>
<text x="328.500000" y="163.120026" textLength="4.442996" font-size="8px">1</text>
<text x="337.377991" y="163.120026" textLength="4.442996" font-size="8px">8</text>
<text x="298.798279" y="162.940216" textLength="4.442996" font-size="8px">4</text>
</svg>
<figcaption>Figure 4-5.  256-bit VMPSADBW Operation
</figcaption></figure>
```

### Operation
#### VMPSADBW (VEX.256 encoded version)
```info-verb
BLK2_OFFSET <-  imm8[1:0]\htmlonly{*}32
BLK1_OFFSET  <- imm8[2]\htmlonly{*}32
SRC1_BYTE0  <- SRC1[BLK1_OFFSET+7:BLK1_OFFSET]
SRC1_BYTE1  <- SRC1[BLK1_OFFSET+15:BLK1_OFFSET+8]
SRC1_BYTE2 <-  SRC1[BLK1_OFFSET+23:BLK1_OFFSET+16]
SRC1_BYTE3 <-  SRC1[BLK1_OFFSET+31:BLK1_OFFSET+24]
SRC1_BYTE4 <- SRC1[BLK1_OFFSET+39:BLK1_OFFSET+32]
SRC1_BYTE5 <-  SRC1[BLK1_OFFSET+47:BLK1_OFFSET+40]
SRC1_BYTE6 <-  SRC1[BLK1_OFFSET+55:BLK1_OFFSET+48]
SRC1_BYTE7  <- SRC1[BLK1_OFFSET+63:BLK1_OFFSET+56]
SRC1_BYTE8 <-  SRC1[BLK1_OFFSET+71:BLK1_OFFSET+64]
SRC1_BYTE9  <- SRC1[BLK1_OFFSET+79:BLK1_OFFSET+72]
SRC1_BYTE10  <- SRC1[BLK1_OFFSET+87:BLK1_OFFSET+80]
SRC2_BYTE0  <-SRC2[BLK2_OFFSET+7:BLK2_OFFSET]
SRC2_BYTE1  <- SRC2[BLK2_OFFSET+15:BLK2_OFFSET+8]
SRC2_BYTE2 <-  SRC2[BLK2_OFFSET+23:BLK2_OFFSET+16]
SRC2_BYTE3  <- SRC2[BLK2_OFFSET+31:BLK2_OFFSET+24]
TEMP0  <- ABS(SRC1_BYTE0 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE1 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE2 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE3 - SRC2_BYTE3)
DEST[15:0] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE1 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE2 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE3 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE4 - SRC2_BYTE3)
DEST[31:16]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE2 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE3 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE4 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE5 - SRC2_BYTE3)
DEST[47:32] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE3 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE4 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE5 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE6 - SRC2_BYTE3)
DEST[63:48] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE4 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE5 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE6 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE7 - SRC2_BYTE3)
DEST[79:64]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE5 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE6 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE7 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE8 - SRC2_BYTE3)
DEST[95:80]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE6 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE7 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE8 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE9 - SRC2_BYTE3)
DEST[111:96]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE7 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE8 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE9 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE10 - SRC2_BYTE3)
DEST[127:112] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
BLK2_OFFSET  <- imm8[4:3]*32 + 128
BLK1_OFFSET <-  imm8[5]*32 + 128
SRC1_BYTE0  <- SRC1[BLK1_OFFSET+7:BLK1_OFFSET]
SRC1_BYTE1 <-  SRC1[BLK1_OFFSET+15:BLK1_OFFSET+8]
SRC1_BYTE2  <- SRC1[BLK1_OFFSET+23:BLK1_OFFSET+16]
SRC1_BYTE3  <- SRC1[BLK1_OFFSET+31:BLK1_OFFSET+24]
SRC1_BYTE4 <-  SRC1[BLK1_OFFSET+39:BLK1_OFFSET+32]
SRC1_BYTE5  <- SRC1[BLK1_OFFSET+47:BLK1_OFFSET+40]
SRC1_BYTE6  <- SRC1[BLK1_OFFSET+55:BLK1_OFFSET+48]
SRC1_BYTE7  <- SRC1[BLK1_OFFSET+63:BLK1_OFFSET+56]
SRC1_BYTE8  <- SRC1[BLK1_OFFSET+71:BLK1_OFFSET+64]
SRC1_BYTE9 <-  SRC1[BLK1_OFFSET+79:BLK1_OFFSET+72]
SRC1_BYTE10  <- SRC1[BLK1_OFFSET+87:BLK1_OFFSET+80]
SRC2_BYTE0  <-SRC2[BLK2_OFFSET+7:BLK2_OFFSET]
SRC2_BYTE1  <- SRC2[BLK2_OFFSET+15:BLK2_OFFSET+8]
SRC2_BYTE2  <- SRC2[BLK2_OFFSET+23:BLK2_OFFSET+16]
SRC2_BYTE3  <- SRC2[BLK2_OFFSET+31:BLK2_OFFSET+24]
TEMP0  <- ABS(SRC1_BYTE0 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE1 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE2 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE3 - SRC2_BYTE3)
DEST[143:128] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <- ABS(SRC1_BYTE1 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE2 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE3 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE4 - SRC2_BYTE3)
DEST[159:144] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE2 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE3 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE4 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE5 - SRC2_BYTE3)
DEST[175:160] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <-ABS(SRC1_BYTE3 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE4 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE5 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE6 - SRC2_BYTE3)
DEST[191:176]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE4 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE5 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE6 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE7 - SRC2_BYTE3)
DEST[207:192]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE5 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE6 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE7 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE8 - SRC2_BYTE3)
DEST[223:208] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE6 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE7 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE8 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE9 - SRC2_BYTE3)
DEST[239:224]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE7 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE8 - SRC2_BYTE1)
TEMP2  <- ABS(SRC1_BYTE9 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE10 - SRC2_BYTE3)
DEST[255:240]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
```
#### VMPSADBW (VEX.128 encoded version)
```info-verb
BLK2_OFFSET <-  imm8[1:0]*32
BLK1_OFFSET <-  imm8[2]*32
SRC1_BYTE0 <-  SRC1[BLK1_OFFSET+7:BLK1_OFFSET]
SRC1_BYTE1  <- SRC1[BLK1_OFFSET+15:BLK1_OFFSET+8]
SRC1_BYTE2  <- SRC1[BLK1_OFFSET+23:BLK1_OFFSET+16]
SRC1_BYTE3  <- SRC1[BLK1_OFFSET+31:BLK1_OFFSET+24]
SRC1_BYTE4  <- SRC1[BLK1_OFFSET+39:BLK1_OFFSET+32]
SRC1_BYTE5  <- SRC1[BLK1_OFFSET+47:BLK1_OFFSET+40]
SRC1_BYTE6 <-  SRC1[BLK1_OFFSET+55:BLK1_OFFSET+48]
SRC1_BYTE7  <- SRC1[BLK1_OFFSET+63:BLK1_OFFSET+56]
SRC1_BYTE8  <- SRC1[BLK1_OFFSET+71:BLK1_OFFSET+64]
SRC1_BYTE9 <-  SRC1[BLK1_OFFSET+79:BLK1_OFFSET+72]
SRC1_BYTE10  <- SRC1[BLK1_OFFSET+87:BLK1_OFFSET+80]
SRC2_BYTE0  <-SRC2[BLK2_OFFSET+7:BLK2_OFFSET]
SRC2_BYTE1 <-  SRC2[BLK2_OFFSET+15:BLK2_OFFSET+8]
SRC2_BYTE2 <-  SRC2[BLK2_OFFSET+23:BLK2_OFFSET+16]
SRC2_BYTE3  <- SRC2[BLK2_OFFSET+31:BLK2_OFFSET+24]
TEMP0 <-  ABS(SRC1_BYTE0 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE1 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE2 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE3 - SRC2_BYTE3)
DEST[15:0]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE1 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE2 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE3 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE4 - SRC2_BYTE3)
DEST[31:16]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE2 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE3 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE4 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE5 - SRC2_BYTE3)
DEST[47:32]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE3 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE4 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE5 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE6 - SRC2_BYTE3)
DEST[63:48]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS(SRC1_BYTE4 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE5 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE6 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE7 - SRC2_BYTE3)
DEST[79:64]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE5 - SRC2_BYTE0)
TEMP1 <-  ABS(SRC1_BYTE6 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE7 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE8 - SRC2_BYTE3)
DEST[95:80]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE6 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE7 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE8 - SRC2_BYTE2)
TEMP3 <-  ABS(SRC1_BYTE9 - SRC2_BYTE3)
DEST[111:96]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS(SRC1_BYTE7 - SRC2_BYTE0)
TEMP1  <- ABS(SRC1_BYTE8 - SRC2_BYTE1)
TEMP2 <-  ABS(SRC1_BYTE9 - SRC2_BYTE2)
TEMP3  <- ABS(SRC1_BYTE10 - SRC2_BYTE3)
DEST[127:112] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
DEST[VLMAX-1:128] <-  0
```
#### MPSADBW (128-bit Legacy SSE version)
```info-verb
SRC_OFFSET <-  imm8[1:0]*32
DEST_OFFSET  <- imm8[2]*32
DEST_BYTE0 <-  DEST[DEST_OFFSET+7:DEST_OFFSET]
DEST_BYTE1 <-  DEST[DEST_OFFSET+15:DEST_OFFSET+8]
DEST_BYTE2  <- DEST[DEST_OFFSET+23:DEST_OFFSET+16]
DEST_BYTE3  <- DEST[DEST_OFFSET+31:DEST_OFFSET+24]
DEST_BYTE4  <- DEST[DEST_OFFSET+39:DEST_OFFSET+32]
DEST_BYTE5 <-  DEST[DEST_OFFSET+47:DEST_OFFSET+40]
DEST_BYTE6 <-  DEST[DEST_OFFSET+55:DEST_OFFSET+48]
DEST_BYTE7 <-  DEST[DEST_OFFSET+63:DEST_OFFSET+56]
DEST_BYTE8  <- DEST[DEST_OFFSET+71:DEST_OFFSET+64]
DEST_BYTE9 <-  DEST[DEST_OFFSET+79:DEST_OFFSET+72]
DEST_BYTE10  <- DEST[DEST_OFFSET+87:DEST_OFFSET+80]
SRC_BYTE0 <-  SRC[SRC_OFFSET+7:SRC_OFFSET]
SRC_BYTE1 <-  SRC[SRC_OFFSET+15:SRC_OFFSET+8]
SRC_BYTE2 <-  SRC[SRC_OFFSET+23:SRC_OFFSET+16]
SRC_BYTE3  <- SRC[SRC_OFFSET+31:SRC_OFFSET+24]
TEMP0  <- ABS( DEST_BYTE0 - SRC_BYTE0) 
TEMP1  <- ABS( DEST_BYTE1 - SRC_BYTE1) 
TEMP2 <-  ABS( DEST_BYTE2 - SRC_BYTE2) 
TEMP3  <- ABS( DEST_BYTE3 - SRC_BYTE3) 
DEST[15:0] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS( DEST_BYTE1 - SRC_BYTE0) 
TEMP1  <- ABS( DEST_BYTE2 - SRC_BYTE1) 
TEMP2  <- ABS( DEST_BYTE3 - SRC_BYTE2) 
TEMP3  <- ABS( DEST_BYTE4 - SRC_BYTE3) 
DEST[31:16]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS( DEST_BYTE2 - SRC_BYTE0) 
TEMP1  <- ABS( DEST_BYTE3 - SRC_BYTE1) 
TEMP2 <-  ABS( DEST_BYTE4 - SRC_BYTE2) 
TEMP3 <-  ABS( DEST_BYTE5 - SRC_BYTE3) 
DEST[47:32] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS( DEST_BYTE3 - SRC_BYTE0) 
TEMP1  <- ABS( DEST_BYTE4 - SRC_BYTE1) 
TEMP2 <-  ABS( DEST_BYTE5 - SRC_BYTE2) 
TEMP3 <-  ABS( DEST_BYTE6 - SRC_BYTE3) 
DEST[63:48] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS( DEST_BYTE4 - SRC_BYTE0) 
TEMP1 <-  ABS( DEST_BYTE5 - SRC_BYTE1) 
TEMP2 <-  ABS( DEST_BYTE6 - SRC_BYTE2) 
TEMP3 <-  ABS( DEST_BYTE7 - SRC_BYTE3) 
DEST[79:64] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS( DEST_BYTE5 - SRC_BYTE0) 
TEMP1  <- ABS( DEST_BYTE6 - SRC_BYTE1) 
TEMP2  <- ABS( DEST_BYTE7 - SRC_BYTE2) 
TEMP3 <-  ABS( DEST_BYTE8 - SRC_BYTE3) 
DEST[95:80]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0 <-  ABS( DEST_BYTE6 - SRC_BYTE0) 
TEMP1 <-  ABS( DEST_BYTE7 - SRC_BYTE1) 
TEMP2  <- ABS( DEST_BYTE8 - SRC_BYTE2) 
TEMP3 <-  ABS( DEST_BYTE9 - SRC_BYTE3) 
DEST[111:96] <-  TEMP0 + TEMP1 + TEMP2 + TEMP3
TEMP0  <- ABS( DEST_BYTE7 - SRC_BYTE0) 
TEMP1 <-  ABS( DEST_BYTE8 - SRC_BYTE1) 
TEMP2 <-  ABS( DEST_BYTE9 - SRC_BYTE2) 
TEMP3  <- ABS( DEST_BYTE10 - SRC_BYTE3) 
DEST[127:112]  <- TEMP0 + TEMP1 + TEMP2 + TEMP3
DEST[VLMAX-1:128] (Unmodified)
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
(V)MPSADBW:  __m128i _mm_mpsadbw_epu8 (__m128i s1, __m128i s2, const int mask);
VMPSADBW:  __m256i _mm256_mpsadbw_epu8 (__m256i s1, __m256i s2, const int mask);
```
### Flags Affected


None

### Other Exceptions


See Exceptions Type 4; additionally

#UD If VEX.L = 1.

