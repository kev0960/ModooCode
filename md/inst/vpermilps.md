----------------------------
title : VPERMILPS (Intel x86/64 assembly instruction)
cat_title : VPERMILPS
ref_title : VPERMILPS
path : /X86-64 명령어 레퍼런스
----------------------------
#@ VPERMILPS

**Permute In-Lane of Quadruples of Single-Precision Floating-Point Values**

|**Opcode/**\newline{}**Instruction**|**Op / En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|-----------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.128.66.0F38.W0 0C /r \newline{}VPERMILPS xmm1, xmm2, xmm3/m128|RVM|V/V|AVX|Permute single-precision floating-point values in xmm2 using controls from xmm3/m128 and store result in xmm1.|
|VEX.128.66.0F3A.W0 04 /r ib\newline{}VPERMILPS xmm1, xmm2/m128, imm8|RM|V/V|AVX|Permute single-precision floating-point values in xmm2/m128 using controls from imm8 and store result in xmm1.|
|VEX.NDS.256.66.0F38.W0 0C /r \newline{}VPERMILPS ymm1, ymm2, ymm3/m256|RVM|V/V|AVX|Permute single-precision floating-point values in ymm2 using controls from ymm3/m256 and store result in ymm1.|
|VEX.256.66.0F3A.W0 04 /r ib\newline{}VPERMILPS ymm1, ymm2/m256, imm8|RM|V/V|AVX|Permute single-precision floating-point values in ymm2/m256 using controls from imm8 and store result in ymm1.|
|EVEX.NDS.128.66.0F38.W0 0C /r\newline{}VPERMILPS xmm1 {k1}{z}, xmm2, xmm3/m128/m32bcst|FV-RVM|V/V|AVX512VL\newline{}AVX512F|Permute single-precision floating-point values xmm2 using control from xmm3/m128/m32bcst and store the result in xmm1 using writemask k1.|
|EVEX.NDS.256.66.0F38.W0 0C /r \newline{}VPERMILPS ymm1 {k1}{z}, ymm2, ymm3/m256/m32bcst|FV-RVM|V/V|AVX512VL\newline{}AVX512F|Permute single-precision floating-point values ymm2 using control from ymm3/m256/m32bcst and store the result in ymm1 using writemask k1.|
|EVEX.NDS.512.66.0F38.W0 0C /r \newline{}VPERMILPS zmm1 {k1}{z}, zmm2, zmm3/m512/m32bcst|FV-RVM|V/V|AVX512F|Permute single-precision floating-point values zmm2 using control from zmm3/m512/m32bcst and store the result in zmm1 using writemask k1.|
|EVEX.128.66.0F3A.W0 04 /r ib\newline{}VPERMILPS xmm1 {k1}{z}, xmm2/m128/m32bcst, imm8|FV-RM|V/V|AVX512VL\newline{}AVX512F|Permute single-precision floating-point values xmm2/m128/m32bcst using controls from imm8 and store the result in xmm1 using writemask k1.|
|EVEX.256.66.0F3A.W0 04 /r ib\newline{}VPERMILPS ymm1 {k1}{z}, ymm2/m256/m32bcst, imm8|FV-RM|V/V|AVX512VL\newline{}AVX512F|Permute single-precision floating-point values ymm2/m256/m32bcst using controls from imm8 and store the result in ymm1 using writemask k1.|
|EVEX.512.66.0F3A.W0 04 /r ib\newline{}VPERMILPS zmm1 {k1}{z}, zmm2/m512/m32bcst, imm8|FV-RM|V/V|AVX512F|Permute single-precision floating-point values zmm2/m512/m32bcst using controls from imm8 and store the result in zmm1 using writemask k1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
|FV-RVM|ModRM:reg (w)|EVEX.vvvv (r)|ModRM:r/m (r)|NA|
|FV-RM|ModRM:reg (w)|ModRM:r/m (r)|NA|NA|
### Description


(variable control version)

Permute quadruples of single-precision floating-point values in the first source operand (second operand), each quadruplet using a 2-bit control field in the corresponding dword element of the second source operand. Permuted results are stored in the destination operand (first operand). 

The 2-bit control fields are located at the low two bits of each dword element (see Figure 5-26). Each control deter-mines which of the source element in an input quadruple is selected for the destination element. Each quadruple of source elements must lie in the same 128-bit region as the destination.

EVEX version: The second source operand (third operand) is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. Permuted results are written to the destination under the writemask.

(immediate control version)

Permute quadruples of single-precision floating-point values in the first source operand (second operand), each quadruplet using a 2-bit control field in the imm8 byte. Each 128-bit lane in the destination operand (first operand) use the four control fields of the same imm8 byte.

VEX version: The source operand is a YMM/XMM register or a 256/128-bit memory location and the destination operand is a YMM/XMM register. 

EVEX version: The source operand (second operand) is a ZMM/YMM/XMM register, a 512/256/128-bit memory location or a 512/256/128-bit vector broadcasted from a 32-bit memory location. Permuted results are written to the destination under the writemask.

Note: For the imm8 version, VEX.vvvv and EVEX.vvvv are reserved and must be 1111b otherwise instruction will #UD.

```embed
<figure>
<svg viewBox="0 0 396.480042 158.779999">
<rect x="0.000000" y="10.000000" width="0.480000" height="131.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="131.639999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="141.639984" width="396.480011" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.340004" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="32.340004" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.239998" y="103.720001" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.099998" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.099998" y="103.480011" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.620003" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="106.620003" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.519989" y="103.720001" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.379997" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.379997" y="103.480011" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.839996" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="180.839996" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.740021" y="103.720001" width="0.479980" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.600006" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.600006" y="103.480011" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="255.119995" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="255.119995" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.020020" y="103.720001" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.880005" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.880005" y="103.480011" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M212.640015,92.200012 L212.820007,92.320007 L213.360016,92.500000 L213.900024,92.320007 L214.080017,92.200012 L214.200012,92.020020 C214.348022 91.443024,214.475006 91.683014,214.260010 91.120026  L214.200012,90.940002 L214.080017,90.760010 L213.720001,90.520020 L213.540009,90.520020 L213.360016,90.460022 L213.180023,90.520020 L213.000000,90.520020 L212.640015,90.760010 L212.400024,91.120026 L212.400024,91.300018 L212.340027,91.480011 L212.400024,91.660004 L212.400024,91.840027 L212.640015,92.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M213.360016,91.480011 L216.420013,94.480011 L216.840027,95.020020 L216.300018,95.320007 L202.620026,102.880005 L201.060028,103.720001 L201.900024,102.160004 L209.460022,88.540009 L209.820007,88.000000 L210.300018,88.420013 L210.360016,89.020020 L202.800018,102.640015 L201.900024,102.160004 L202.140015,101.980011 L215.820007,94.420013 L216.300018,95.320007 L215.700012,95.200012 L212.640015,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M210.300018,88.420013 L213.360016,91.480011 L212.640015,92.200012 L209.580017,89.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M213.000000,91.839996 L216.059998,94.839996 L202.380005,102.399994 L209.940002,88.779999" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M255.839996,50.440002 L254.459991,49.059998 L212.700012,90.820007 L214.079987,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.260010" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="292.260010" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="329.160004" y="36.220032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.020020" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.020020" y="35.980042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.600006,92.200012 L297.839996,91.840027 L297.839996,91.660004 L297.899994,91.480011 L297.839996,91.300018 L297.839996,91.120026 L297.600006,90.760010 L297.420013,90.640015 C297.164001 90.416016,296.822998 90.500000,296.520020 90.520020  L296.160004,90.760010 L296.040009,90.940002 L295.980011,91.120026 L295.860016,91.480011 L296.040009,92.020020 L296.160004,92.200012 L296.339996,92.320007 L296.880005,92.500000 L297.420013,92.320007 L297.600006,92.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M296.880005,91.480011 L299.940002,88.420013 L300.420013,88.000000 L300.779999,88.540009 L308.339996,102.160004 L309.179993,103.720001 L307.619995,102.880005 L293.940002,95.320007 L293.399994,94.960022 L293.820007,94.480011 L294.420013,94.420013 L308.100006,101.980011 L307.619995,102.880005 L307.440002,102.640015 L299.880005,89.020020 L300.779999,88.540009 L300.660004,89.140015 L297.600006,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M293.820007,94.480011 L296.880005,91.480011 L297.600006,92.200012 L294.540009,95.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M297.240021,91.839996 L300.300018,88.779999 L307.860016,102.399994 L294.180023,94.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M255.839996,49.059998 L254.459991,50.440002 L296.220001,92.200012 L297.600006,90.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.119995,88.119995 L267.299988,88.059998 L267.479980,87.940002 C268.207001 87.263000,267.752991 86.195984,266.760010 86.199982  L266.519989,86.260010 L266.339996,86.320007 C265.449982 86.778992,265.839996 88.165985,266.760010 88.179993  L266.940002,88.179993 L267.119995,88.119995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M266.880005,87.220001 L270.959991,85.899994 L271.559998,85.779999 L271.619995,86.380005 L271.980011,101.980011 L271.980011,103.779999 L271.020020,102.279999 L262.440002,89.260010 L262.080017,88.720001 L262.739990,88.480011 L263.279999,88.720001 L271.860016,101.739990 L271.020020,102.279999 L270.959991,101.980011 L270.600006,86.380005 L271.619995,86.380005 L271.260010,86.920013 L267.179993,88.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M262.740021,88.480011 L266.880035,87.220001 L267.180023,88.240021 L263.040009,89.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.000000,87.700012 L271.079987,86.380005 L271.440002,101.980011 L262.859985,88.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.080017,49.419983 L254.160004,50.019958 L265.860016,87.519989 L267.780029,86.919983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.600006,88.420013 L240.779999,88.480011 L241.200012,88.480011 L241.380005,88.420013 L241.500000,88.300018 L241.679993,88.180023 L241.800018,88.060028 L241.860016,87.880005 L241.920013,87.640015 C241.927002 87.234009,241.951996 87.117004,241.619995 86.800018  L241.500000,86.680023 L241.320007,86.560028 L241.080017,86.500000 C240.093018 86.487000,239.589020 87.456024,240.240021 88.240021  L240.420013,88.360016 L240.600006,88.420013" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.960022,87.580017 L244.980011,89.080017 L245.580017,89.320007 L245.160034,89.860016 L235.860016,102.400024 L234.840027,103.780029 L234.960022,102.040009 L236.220032,86.440002 L236.340027,85.780029 L236.940033,86.020020 L237.240021,86.500031 L235.980011,102.100006 L234.960022,102.040009 L235.080017,101.740021 L244.380035,89.200012 L245.160034,89.860016 L244.620026,89.980011 L240.600037,88.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M236.940002,86.020020 L240.959991,87.580017 L240.600006,88.480011 L236.580017,86.920013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M240.779999,88.000000 L244.799988,89.500000 L235.500000,102.040009 L236.760010,86.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M256.080017,50.080017 L254.220032,49.360046 L240.060028,87.160034 L241.920013,87.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="255.119995" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="255.119995" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.020020" y="36.220032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.880005" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.880005" y="35.980042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.980011" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="217.980011" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.880005" y="36.220032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.740021" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.740021" y="35.980042" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.839996" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="180.839996" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.740021" y="36.220032" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.600006" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.600006" y="35.980042" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.760010" y="36.220032" width="37.080002" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="143.760010" y="35.980042" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.600006" y="36.220032" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.519989" y="49.480042" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.519989" y="35.980042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.620003" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="106.620003" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.519989" y="36.220032" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.379997" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.379997" y="35.980042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.480003" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="69.480003" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.379997" y="36.220032" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.239998" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.239998" y="35.980042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.340004" y="36.220032" width="37.139999" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="32.340004" y="35.980042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.239998" y="36.220032" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.099998" y="49.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="32.099998" y="35.980042" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.260010" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="292.260010" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="329.160004" y="103.720001" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.020020" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="292.020020" y="103.480011" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.480003" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="69.480003" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.379997" y="103.720001" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.239998" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.239998" y="103.480011" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.760010" y="103.720032" width="37.080002" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="143.760010" y="103.480042" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="180.600006" y="103.720001" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.519989" y="127.120026" width="37.320000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="143.519989" y="103.480011" width="0.480000" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.980011" y="103.720032" width="37.139999" height="23.639999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="217.980011" y="103.480042" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="254.880005" y="103.720001" width="0.480010" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.740021" y="127.120026" width="37.380001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="217.740021" y="103.480011" width="0.479980" height="23.879999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.140007,92.200012 L64.320000,92.320007 L64.500008,92.380005 C65.410011 92.776001,66.147011 91.778015,65.700005 90.940002  L65.580009,90.760010 L65.400002,90.640015 C64.611000 90.120026,63.549004 90.927002,63.900002 91.840027  L64.140007,92.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.860008,91.480011 L67.920006,94.480011 L68.340004,95.020020 L67.800011,95.320007 L54.120003,102.880005 L52.560005,103.720001 L53.400002,102.160004 L60.960014,88.540009 L61.320015,88.000000 L61.800011,88.420013 L61.860008,89.020020 L54.300011,102.640015 L53.400002,102.160004 L53.640007,101.980011 L67.320015,94.420013 L67.800011,95.320007 L67.200005,95.200012 L64.140007,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M61.799995,88.420013 L64.859993,91.480011 L64.139992,92.200012 L61.079994,89.140015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M64.500008,91.839996 L67.560005,94.839996 L53.880013,102.399994 L61.440010,88.779999" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.340004,50.440002 L105.959999,49.059998 L64.200005,90.820007 L65.580009,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M149.100006,92.200012 L149.220001,92.020020 L149.279999,91.840027 C149.679993 90.949005,148.631989 90.104004,147.839996 90.640015  L147.660004,90.760010 L147.540009,90.940002 L147.480011,91.120026 L147.359985,91.480011 L147.540009,92.020020 L147.660004,92.200012 L147.839996,92.320007 L148.380005,92.500000 L148.920013,92.320007 L149.100006,92.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.380005,91.480011 L151.440002,88.420013 L151.919983,88.000000 L152.279999,88.540009 L159.839996,102.160004 L160.679993,103.720001 L159.119995,102.880005 L145.440002,95.320007 L144.899994,94.960022 L145.320007,94.480011 L145.919983,94.420013 L159.600006,101.980011 L159.119995,102.880005 L158.940002,102.640015 L151.380005,89.020020 L152.279999,88.540009 L152.160004,89.140015 L149.100006,92.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M145.320007,94.480011 L148.380005,91.480011 L149.100006,92.200012 L146.040009,95.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M148.739990,91.839996 L151.799988,88.779999 L159.360016,102.399994 L145.679993,94.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.340004,49.059998 L105.959999,50.440002 L147.720001,92.200012 L149.100006,90.820007" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.620003,88.119995 L118.799995,88.059998 L118.980003,87.940002 C119.728996 87.237000,119.220009 86.152008,118.200005 86.199982  L117.840004,86.320007 C116.978004 86.739990,117.301003 88.208984,118.260002 88.179993  L118.440010,88.179993 L118.620003,88.119995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.379997,87.220001 L122.459999,85.899994 L123.059990,85.779999 L123.120003,86.380005 L123.480003,101.980011 L123.480003,103.779999 L122.519997,102.279999 L113.939995,89.260010 L113.579994,88.720001 L114.239998,88.480011 L114.779991,88.720001 L123.359993,101.739990 L122.519997,102.279999 L122.459999,101.980011 L122.099998,86.380005 L123.120003,86.380005 L122.760002,86.920013 L118.680000,88.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M114.239998,88.480011 L118.379997,87.220001 L118.680000,88.240021 L114.540001,89.500000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M118.500008,87.700012 L122.580009,86.380005 L122.940010,101.980011 L114.360008,88.960022" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.580009,49.419983 L105.660011,50.019958 L117.360008,87.519989 L119.280006,86.919983" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.099998,88.420013 L92.279991,88.480011 L92.700005,88.480011 L92.879997,88.420013 L92.999992,88.300018 L93.180000,88.180023 L93.299995,88.060028 L93.359993,87.880005 L93.420006,87.640015 C93.426994 87.234009,93.452003 87.117004,93.120003 86.800018  L92.999992,86.680023 L92.820000,86.560028 L92.579994,86.500000 L92.400002,86.500000 L91.859993,86.680023 L91.739998,86.800018 L91.499992,87.160004 L91.439995,87.340027 L91.439995,87.760010 L91.499992,87.940002 L91.620003,88.060028 L91.739998,88.240021 L91.920006,88.360016 L92.099998,88.420013" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.459999,87.580017 L96.480003,89.080017 L97.079994,89.320007 L96.659996,89.860016 L87.359993,102.400024 L86.340004,103.780029 L86.459999,102.040009 L87.719994,86.440002 L87.840004,85.780029 L88.439995,86.020020 L88.739998,86.500031 L87.480003,102.100006 L86.459999,102.040009 L86.579994,101.740021 L95.879997,89.200012 L96.659996,89.860016 L96.120003,89.980011 L92.099998,88.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.439995,86.020020 L92.459999,87.580017 L92.099998,88.480011 L88.079994,86.920013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M92.280006,88.000000 L96.300011,89.500000 L87.000008,102.040009 L88.260002,86.440002" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.580009,50.080017 L105.720009,49.360046 L91.560005,87.160034 L93.420006,87.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="233.700165" y="112.240021" textLength="2.305037" font-size="8px">.</text>
<text x="226.799957" y="112.240021" textLength="4.610074" font-size="8px">3</text>
<text x="163.808258" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="161.700012" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="159.598511" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="155.460022" y="112.240021" textLength="4.170000" font-size="8px">7</text>
<text x="150.480011" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="86.169762" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="72.840004" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="313.084503" y="113.860016" textLength="5.002500" font-size="8px">X</text>
<text x="43.439995" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="80.580009" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="122.700005" y="44.739990" textLength="4.170000" font-size="8px">5</text>
<text x="117.720009" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="159.780029" y="44.739990" textLength="4.170000" font-size="8px">4</text>
<text x="266.220001" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="308.280029" y="44.739990" textLength="4.170000" font-size="8px">0</text>
<text x="303.300018" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="17.344498" y="46.359985" textLength="5.415000" font-size="8px">R</text>
<text x="12.360001" y="46.359985" textLength="5.002500" font-size="8px">S</text>
<text x="27.538506" y="112.240021" textLength="4.582500" font-size="8px">T</text>
<text x="275.958008" y="113.860016" textLength="5.002500" font-size="8px">X</text>
<text x="271.808258" y="113.860016" textLength="2.085000" font-size="8px">.</text>
<text x="269.700012" y="113.860016" textLength="2.085000" font-size="8px">.</text>
<text x="267.598511" y="113.860016" textLength="2.085000" font-size="8px"> </text>
<text x="263.460022" y="113.860016" textLength="4.170000" font-size="8px">3</text>
<text x="206.715057" y="112.240021" textLength="4.610074" font-size="8px">0</text>
<text x="194.357391" y="112.240021" textLength="2.305037" font-size="8px"> </text>
<text x="184.260010" y="112.240021" textLength="5.530430" font-size="8px">X</text>
<text x="130.821014" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="122.518501" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="118.320000" y="112.240021" textLength="4.170000" font-size="8px">7</text>
<text x="58.265266" y="112.240021" textLength="4.170000" font-size="8px">4</text>
<text x="44.931755" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="28.138496" y="46.359985" textLength="4.170000" font-size="8px">1</text>
<text x="273.916504" y="113.860016" textLength="2.085000" font-size="8px"> </text>
<text x="51.190514" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="310.983002" y="113.860016" textLength="2.085000" font-size="8px"> </text>
<text x="234.120026" y="44.739990" textLength="4.170000" font-size="8px">2</text>
<text x="304.738495" y="113.860016" textLength="2.085000" font-size="8px"> </text>
<text x="189.768890" y="112.240021" textLength="4.610074" font-size="8px">3</text>
<text x="126.669762" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="47.033257" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="318.064514" y="113.860016" textLength="4.170000" font-size="8px">0</text>
<text x="165.916504" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="40.733253" y="112.240021" textLength="4.170000" font-size="8px">7</text>
<text x="300.600006" y="113.860016" textLength="4.170000" font-size="8px">3</text>
<text x="172.983765" y="112.240021" textLength="4.170000" font-size="8px">4</text>
<text x="196.639221" y="112.240021" textLength="2.305037" font-size="8px">.</text>
<text x="280.983765" y="113.860016" textLength="4.170000" font-size="8px">0</text>
<text x="22.741501" y="46.359985" textLength="5.415000" font-size="8px">C</text>
<text x="258.480011" y="113.860016" textLength="5.002500" font-size="8px">X</text>
<text x="221.339996" y="112.240021" textLength="5.530430" font-size="8px">X</text>
<text x="88.279518" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="135.848267" y="112.240021" textLength="4.170000" font-size="8px">4</text>
<text x="154.800018" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="113.340004" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="128.779510" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="231.418335" y="112.240021" textLength="2.305037" font-size="8px"> </text>
<text x="308.941498" y="113.860016" textLength="2.085000" font-size="8px">.</text>
<text x="35.760002" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="77.820000" y="112.240021" textLength="4.170000" font-size="8px">7</text>
<text x="84.060005" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="196.920013" y="44.739990" textLength="4.170000" font-size="8px">3</text>
<text x="53.292015" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="167.958008" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="17.515503" y="112.240021" textLength="5.002500" font-size="8px">E</text>
<text x="82.018501" y="112.240021" textLength="2.085000" font-size="8px"> </text>
<text x="243.723785" y="112.240021" textLength="4.610074" font-size="8px">0</text>
<text x="306.839996" y="113.860016" textLength="2.085000" font-size="8px">.</text>
<text x="229.080017" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="238.263824" y="112.240021" textLength="5.530430" font-size="8px">X</text>
<text x="49.089012" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="48.419991" y="44.739990" textLength="4.170000" font-size="8px">7</text>
<text x="90.321022" y="112.240021" textLength="5.002500" font-size="8px">X</text>
<text x="191.940002" y="44.739990" textLength="5.002500" font-size="8px">X</text>
<text x="198.922699" y="112.240021" textLength="2.305037" font-size="8px">.</text>
<text x="95.348274" y="112.240021" textLength="4.170000" font-size="8px">4</text>
<text x="271.260010" y="44.739990" textLength="4.170000" font-size="8px">1</text>
<text x="85.620003" y="44.739990" textLength="4.170000" font-size="8px">6</text>
<text x="124.560005" y="112.240021" textLength="2.085000" font-size="8px">.</text>
<text x="295.619995" y="113.860016" textLength="5.002500" font-size="8px">X</text>
<text x="235.981995" y="112.240021" textLength="2.305037" font-size="8px">.</text>
<text x="22.555504" y="112.240021" textLength="5.002500" font-size="8px">S</text>
<text x="201.206177" y="112.240021" textLength="5.530430" font-size="8px">X</text>
<text x="12.120003" y="112.240021" textLength="5.415000" font-size="8px">D</text>
</svg>
<figcaption>Figure 5-25.  VPERMILPS Operation
</figcaption></figure>
```
```embed
<figure>
<svg viewBox="0 0 396.480042 165.300171">
<rect x="0.000000" y="10.000000" width="0.480000" height="102.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="396.000000" y="10.000000" width="0.480040" height="102.000000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.520020" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="112.000031" width="396.480011" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.560005" y="39.820007" width="22.200001" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="106.560005" y="39.340027" width="22.740000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.279999" y="39.820007" width="1.020000" height="36.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.080009" y="75.340027" width="22.680000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.080009" y="39.339996" width="1.020000" height="36.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.820007" y="39.820007" width="22.200001" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="257.820007" y="39.340027" width="22.740000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="279.540009" y="39.820007" width="1.020000" height="36.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.339996" y="75.340027" width="22.680000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="257.339996" y="39.339996" width="1.020000" height="36.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="364.800018" y="39.820007" width="22.200001" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="364.800018" y="39.340027" width="22.740000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="386.520020" y="39.820007" width="1.020000" height="36.540001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="364.320007" y="75.340027" width="22.680000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="364.320007" y="39.339996" width="1.020000" height="36.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="21.959999" y="39.820007" width="83.040001" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="21.959999" y="39.580017" width="83.279999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="104.760002" y="39.820007" width="0.480000" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="21.720001" y="75.580017" width="83.279999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="21.720001" y="39.580017" width="0.480000" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.500000" y="39.279999" width="82.980003" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="172.500000" y="39.040009" width="83.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="255.240021" y="39.280029" width="0.479980" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.260010" y="75.040009" width="83.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.260010" y="39.040009" width="0.480010" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.500000" y="39.279999" width="82.980003" height="36.000000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="280.500000" y="39.040009" width="83.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="363.240021" y="39.280029" width="0.479980" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.260010" y="75.040009" width="83.220001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="280.260010" y="39.040009" width="0.480010" height="36.240002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="178.260071" y="34.240021" textLength="3.292750" font-size="8px">3</text>
<text x="175.020020" y="34.240021" textLength="3.292750" font-size="8px">6</text>
<text x="222.879364" y="61.240021" textLength="4.564900" font-size="8px">d</text>
<text x="218.896942" y="61.240021" textLength="4.053631" font-size="8px">e</text>
<text x="215.927917" y="61.240021" textLength="3.040223" font-size="8px">r</text>
<text x="211.434235" y="61.240021" textLength="4.564900" font-size="8px">o</text>
<text x="206.940552" y="61.240021" textLength="4.564900" font-size="8px">n</text>
<text x="202.446869" y="61.240021" textLength="4.564900" font-size="8px">g</text>
<text x="28.020073" y="34.780121" textLength="3.480000" font-size="8px">5</text>
<text x="24.480217" y="34.780121" textLength="3.480000" font-size="8px">2</text>
<text x="118.625862" y="96.760010" textLength="2.490000" font-size="8px"> </text>
<text x="113.586098" y="96.760010" textLength="4.980000" font-size="8px">d</text>
<text x="110.808250" y="96.760010" textLength="2.768880" font-size="8px">l</text>
<text x="98.052483" y="96.760010" textLength="5.537760" font-size="8px">F</text>
<text x="95.592369" y="96.760010" textLength="2.490000" font-size="8px"> </text>
<text x="92.770699" y="96.760010" textLength="2.768880" font-size="8px">l</text>
<text x="258.808838" y="96.760010" textLength="2.768880" font-size="8px">l</text>
<text x="254.379639" y="96.760010" textLength="4.422240" font-size="8px">e</text>
<text x="243.539185" y="96.760010" textLength="2.490000" font-size="8px"> </text>
<text x="240.763336" y="96.760010" textLength="2.768880" font-size="8px">l</text>
<text x="229.676880" y="96.760010" textLength="2.768880" font-size="8px">t</text>
<text x="224.689911" y="96.760010" textLength="4.980000" font-size="8px">n</text>
<text x="375.580841" y="96.760010" textLength="2.490000" font-size="8px"> </text>
<text x="355.070251" y="96.760010" textLength="5.537760" font-size="8px">F</text>
<text x="352.550385" y="96.760010" textLength="2.490000" font-size="8px"> </text>
<text x="344.746735" y="96.760010" textLength="4.980000" font-size="8px">o</text>
<text x="341.435028" y="96.760010" textLength="3.316680" font-size="8px">r</text>
<text x="333.633362" y="96.760010" textLength="4.980000" font-size="8px">n</text>
<text x="61.045555" y="61.779999" textLength="4.564900" font-size="8px">o</text>
<text x="56.533607" y="61.779999" textLength="4.564900" font-size="8px">n</text>
<text x="49.500008" y="61.779999" textLength="2.538084" font-size="8px">i</text>
<text x="123.240623" y="62.260010" textLength="2.282450" font-size="8px"> </text>
<text x="126.359596" y="34.240021" textLength="3.480000" font-size="8px">4</text>
<text x="91.980003" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="154.500000" y="65.800018" textLength="4.500000" font-size="8px"> </text>
<text x="145.500000" y="65.800018" textLength="4.500000" font-size="8px"> </text>
<text x="141.000000" y="65.800018" textLength="4.500000" font-size="8px">.</text>
<text x="274.321808" y="62.260010" textLength="2.282450" font-size="8px"> </text>
<text x="267.836914" y="62.260010" textLength="4.053631" font-size="8px">e</text>
<text x="264.300018" y="62.260010" textLength="3.551492" font-size="8px">s</text>
<text x="271.860046" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="268.380035" y="34.240021" textLength="3.480000" font-size="8px">3</text>
<text x="259.680023" y="34.240021" textLength="3.480000" font-size="8px">3</text>
<text x="244.020020" y="34.240021" textLength="3.292750" font-size="8px">3</text>
<text x="380.178192" y="24.760010" textLength="2.768880" font-size="8px">i</text>
<text x="378.755463" y="62.260010" textLength="2.538084" font-size="8px">l</text>
<text x="371.279999" y="62.260010" textLength="3.551492" font-size="8px">s</text>
<text x="373.500000" y="24.760010" textLength="6.643320" font-size="8px">B</text>
<text x="119.399605" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="378.100708" y="96.760010" textLength="4.980000" font-size="8px">1</text>
<text x="378.479736" y="34.240021" textLength="3.480000" font-size="8px">0</text>
<text x="232.452728" y="96.760010" textLength="3.316680" font-size="8px">r</text>
<text x="71.700310" y="96.760010" textLength="4.980000" font-size="8px">o</text>
<text x="219.650146" y="96.760010" textLength="4.980000" font-size="8px">o</text>
<text x="113.280006" y="62.260010" textLength="3.551492" font-size="8px">s</text>
<text x="122.879601" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="68.472649" y="61.779999" textLength="4.053631" font-size="8px">e</text>
<text x="199.980011" y="61.240021" textLength="2.538084" font-size="8px">i</text>
<text x="349.786499" y="96.760010" textLength="2.768880" font-size="8px">l</text>
<text x="52.021660" y="61.779999" textLength="4.564900" font-size="8px">g</text>
<text x="251.603790" y="96.760010" textLength="2.768880" font-size="8px">i</text>
<text x="366.480011" y="34.240021" textLength="3.480000" font-size="8px">1</text>
<text x="338.673126" y="96.760010" textLength="2.768880" font-size="8px">t</text>
<text x="72.473320" y="61.779999" textLength="4.564900" font-size="8px">d</text>
<text x="87.781731" y="96.760010" textLength="4.980000" font-size="8px">o</text>
<text x="235.776367" y="96.760010" textLength="4.980000" font-size="8px">o</text>
<text x="307.980011" y="61.240021" textLength="2.538084" font-size="8px">i</text>
<text x="271.798340" y="62.260010" textLength="2.538084" font-size="8px">l</text>
<text x="381.228729" y="62.260010" textLength="2.282450" font-size="8px"> </text>
<text x="370.605835" y="96.760010" textLength="4.980000" font-size="8px">d</text>
<text x="98.999855" y="34.240021" textLength="3.480000" font-size="8px">6</text>
<text x="247.260071" y="34.240021" textLength="3.292750" font-size="8px">4</text>
<text x="326.896942" y="61.240021" textLength="4.053631" font-size="8px">e</text>
<text x="261.584686" y="96.760010" textLength="4.980000" font-size="8px">d</text>
<text x="103.599205" y="96.760010" textLength="2.768880" font-size="8px">i</text>
<text x="367.841949" y="96.760010" textLength="2.768880" font-size="8px">l</text>
<text x="323.927917" y="61.240021" textLength="3.040223" font-size="8px">r</text>
<text x="322.020020" y="96.760010" textLength="6.643320" font-size="8px">C</text>
<text x="95.519859" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="116.748421" y="62.260010" textLength="4.053631" font-size="8px">e</text>
<text x="310.446869" y="61.240021" textLength="4.564900" font-size="8px">g</text>
<text x="382.981934" y="24.760010" textLength="2.768880" font-size="8px">t</text>
<text x="286.260284" y="33.759766" textLength="3.292750" font-size="8px">1</text>
<text x="328.658356" y="96.760010" textLength="4.980000" font-size="8px">o</text>
<text x="31.500069" y="34.780121" textLength="3.480000" font-size="8px">5</text>
<text x="117.659599" y="34.240021" textLength="1.740000" font-size="8px"> </text>
<text x="120.718971" y="62.260010" textLength="2.538084" font-size="8px">l</text>
<text x="360.603027" y="96.760010" textLength="2.768880" font-size="8px">i</text>
<text x="64.980293" y="96.760010" textLength="6.643320" font-size="8px">C</text>
<text x="110.639748" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="266.571655" y="96.760010" textLength="2.490000" font-size="8px"> </text>
<text x="330.879364" y="61.240021" textLength="4.564900" font-size="8px">d</text>
<text x="319.434235" y="61.240021" textLength="4.564900" font-size="8px">o</text>
<text x="263.160034" y="34.240021" textLength="3.480000" font-size="8px">3</text>
<text x="266.640045" y="34.240021" textLength="1.740000" font-size="8px"> </text>
<text x="314.940552" y="61.240021" textLength="4.564900" font-size="8px">n</text>
<text x="363.424683" y="96.760010" textLength="4.422240" font-size="8px">e</text>
<text x="114.119743" y="34.240021" textLength="3.480000" font-size="8px">5</text>
<text x="76.689278" y="96.760010" textLength="4.980000" font-size="8px">n</text>
<text x="81.678246" y="96.760010" textLength="2.768880" font-size="8px">t</text>
<text x="269.091522" y="96.760010" textLength="4.980000" font-size="8px">2</text>
<text x="121.085976" y="96.760010" textLength="4.980000" font-size="8px">7</text>
<text x="106.377052" y="96.760010" textLength="4.422240" font-size="8px">e</text>
<text x="159.000000" y="65.800018" textLength="4.500000" font-size="8px">.</text>
<text x="283.020233" y="33.759766" textLength="3.292750" font-size="8px">3</text>
<text x="212.999847" y="96.760010" textLength="6.643320" font-size="8px">C</text>
<text x="84.456093" y="96.760010" textLength="3.316680" font-size="8px">r</text>
<text x="107.159752" y="34.240021" textLength="3.480000" font-size="8px">2</text>
<text x="150.000000" y="65.800018" textLength="4.500000" font-size="8px">.</text>
<text x="65.485374" y="61.779999" textLength="3.040223" font-size="8px">r</text>
<text x="374.766663" y="62.260010" textLength="4.053631" font-size="8px">e</text>
<text x="246.059052" y="96.760010" textLength="5.537760" font-size="8px">F</text>
</svg>
<figcaption>Figure 5-26.  VPERMILPS Shuffle Control
</figcaption></figure>
```

### Operation
#### VPERMILPS (EVEX immediate versions)
```info-verb
(KL, VL) = (4, 128), (8, 256), (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF (EVEX.b = 1) AND (SRC1 *is memory*)
          THEN TMP_SRC1[i+31:i] <-  SRC1[31:0];
          ELSE TMP_SRC1[i+31:i] <-  SRC1[i+31:i];
    FI;
ENDFOR;
TMP_DEST[31:0] <-  Select4(TMP_SRC1[127:0], imm8[1:0]);
TMP_DEST[63:32] <-  Select4(TMP_SRC1[127:0], imm8[3:2]);
TMP_DEST[95:64] <-  Select4(TMP_SRC1[127:0], imm8[5:4]);
TMP_DEST[127:96] <-  Select4(TMP_SRC1[127:0], imm8[7:6]); FI;
IF VL >= 256
    TMP_DEST[159:128] <-  Select4(TMP_SRC1[255:128], imm8[1:0]); FI;
    TMP_DEST[191:160] <-  Select4(TMP_SRC1[255:128], imm8[3:2]); FI;
    TMP_DEST[223:192] <-  Select4(TMP_SRC1[255:128], imm8[5:4]); FI;
    TMP_DEST[255:224] <-  Select4(TMP_SRC1[255:128], imm8[7:6]); FI; 
FI;
IF VL >= 512
    TMP_DEST[287:256] <-  Select4(TMP_SRC1[383:256], imm8[1:0]); FI;
    TMP_DEST[319:288] <-  Select4(TMP_SRC1[383:256], imm8[3:2]); FI;
    TMP_DEST[351:320] <-  Select4(TMP_SRC1[383:256], imm8[5:4]); FI;
    TMP_DEST[383:352] <-  Select4(TMP_SRC1[383:256], imm8[7:6]); FI;
    TMP_DEST[415:384] <-  Select4(TMP_SRC1[511:384], imm8[1:0]); FI;
    TMP_DEST[447:416] <-  Select4(TMP_SRC1[511:384], imm8[3:2]); FI;
    TMP_DEST[479:448] <-  Select4(TMP_SRC1[511:384], imm8[5:4]); FI;
    TMP_DEST[511:480] <-  Select4(TMP_SRC1[511:384], imm8[7:6]); FI;
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking*
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE DEST[i+31:i] <-  0 ;zeroing-masking
                FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-!= 0
```
#### VPERMILPS (256-bit immediate version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], imm8[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], imm8[3:2]);
DEST[95:64] <- Select4(SRC1[127:0], imm8[5:4]);
DEST[127:96] <- Select4(SRC1[127:0], imm8[7:6]);
DEST[159:128] <- Select4(SRC1[255:128], imm8[1:0]);
DEST[191:160] <- Select4(SRC1[255:128], imm8[3:2]);
DEST[223:192] <- Select4(SRC1[255:128], imm8[5:4]);
DEST[255:224] <- Select4(SRC1[255:128], imm8[7:6]);
```
#### VPERMILPS (128-bit immediate version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], imm8[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], imm8[3:2]);
DEST[95:64] <- Select4(SRC1[127:0], imm8[5:4]);
DEST[127:96] <- Select4(SRC1[127:0], imm8[7:6]);
DEST[MAX_VL-1:128]<- 0
```
#### VPERMILPS (EVEX variable versions)
```info-verb
(KL, VL) = (16, 512)
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF (EVEX.b = 1) AND (SRC2 *is memory*)
          THEN TMP_SRC2[i+31:i] <-  SRC2[31:0];
          ELSE TMP_SRC2[i+31:i] <-  SRC2[i+31:i];
    FI;
ENDFOR;
TMP_DEST[31:0] <-  Select4(SRC1[127:0], TMP_SRC2[1:0]);
TMP_DEST[63:32] <-  Select4(SRC1[127:0], TMP_SRC2[33:32]);
TMP_DEST[95:64] <-  Select4(SRC1[127:0], TMP_SRC2[65:64]);
TMP_DEST[127:96] <-  Select4(SRC1[127:0], TMP_SRC2[97:96]);
IF VL >= 256
    TMP_DEST[159:128] <-  Select4(SRC1[255:128], TMP_SRC2[129:128]);
    TMP_DEST[191:160] <-  Select4(SRC1[255:128], TMP_SRC2[161:160]);
    TMP_DEST[223:192] <-  Select4(SRC1[255:128], TMP_SRC2[193:192]);
    TMP_DEST[255:224] <-  Select4(SRC1[255:128], TMP_SRC2[225:224]);
FI;
IF VL >= 512
    TMP_DEST[287:256] <-  Select4(SRC1[383:256], TMP_SRC2[257:256]);
    TMP_DEST[319:288] <-  Select4(SRC1[383:256], TMP_SRC2[289:288]);
    TMP_DEST[351:320] <-  Select4(SRC1[383:256], TMP_SRC2[321:320]);
    TMP_DEST[383:352] <-  Select4(SRC1[383:256], TMP_SRC2[353:352]);
    TMP_DEST[415:384] <-  Select4(SRC1[511:384], TMP_SRC2[385:384]);
    TMP_DEST[447:416] <-  Select4(SRC1[511:384], TMP_SRC2[417:416]);
    TMP_DEST[479:448] <-  Select4(SRC1[511:384], TMP_SRC2[449:448]);
    TMP_DEST[511:480] <-  Select4(SRC1[511:384], TMP_SRC2[481:480]);
FI;
FOR j <-  0 TO KL-1
    i <-  j * 32
    IF k1[j] OR *no writemask*
          THEN DEST[i+31:i] <-  TMP_DEST[i+31:i]
          ELSE 
                IF *merging-masking*
                      THEN *DEST[i+31:i] remains unchanged*
                      ELSE DEST[i+31:i] <-  0 ;zeroing-masking
FI;
    FI;
ENDFOR
DEST[MAX_VL-1:VL] <-!= 0
```
#### VPERMILPS (256-bit variable version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], SRC2[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], SRC2[33:32]);
DEST[95:64] <- Select4(SRC1[127:0], SRC2[65:64]);
DEST[127:96] <- Select4(SRC1[127:0], SRC2[97:96]);
DEST[159:128] <- Select4(SRC1[255:128], SRC2[129:128]);
DEST[191:160] <- Select4(SRC1[255:128], SRC2[161:160]);
DEST[223:192] <- Select4(SRC1[255:128], SRC2[193:192]);
DEST[255:224] <- Select4(SRC1[255:128], SRC2[225:224]);
DEST[MAX_VL-1:256]<- 0
```
#### VPERMILPS (128-bit variable version)
```info-verb
DEST[31:0] <- Select4(SRC1[127:0], SRC2[1:0]);
DEST[63:32] <- Select4(SRC1[127:0], SRC2[33:32]);
DEST[95:64] <- Select4(SRC1[127:0], SRC2[65:64]);
DEST[127:96] <- Select4(SRC1[127:0], SRC2[97:96]);
DEST[MAX_VL-1:128]<- 0
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPERMILPS __m512 _mm512_permute_ps( __m512 a, int imm);
VPERMILPS __m512 _mm512_mask_permute_ps(__m512 s, __mmask16 k, __m512 a, int imm);
VPERMILPS __m512 _mm512_maskz_permute_ps( __mmask16 k, __m512 a, int imm);
VPERMILPS __m256 _mm256_mask_permute_ps(__m256 s, __mmask8 k, __m256 a, int imm);
VPERMILPS __m256 _mm256_maskz_permute_ps( __mmask8 k, __m256 a, int imm);
VPERMILPS __m128 _mm_mask_permute_ps(__m128 s, __mmask8 k, __m128 a, int imm);
VPERMILPS __m128 _mm_maskz_permute_ps( __mmask8 k, __m128 a, int imm);
VPERMILPS __m512 _mm512_permutevar_ps( __m512i i, __m512 a);
VPERMILPS __m512 _mm512_mask_permutevar_ps(__m512 s, __mmask16 k, __m512i i, __m512 a);
VPERMILPS __m512 _mm512_maskz_permutevar_ps( __mmask16 k, __m512i i, __m512 a);
VPERMILPS __m256 _mm256_mask_permutevar_ps(__m256 s, __mmask8 k, __m256 i, __m256 a);
VPERMILPS __m256 _mm256_maskz_permutevar_ps( __mmask8 k, __m256 i, __m256 a);
VPERMILPS __m128 _mm_mask_permutevar_ps(__m128 s, __mmask8 k, __m128 i, __m128 a);
VPERMILPS __m128 _mm_maskz_permutevar_ps( __mmask8 k, __m128 i, __m128 a);
VPERMILPS __m128 _mm_permute_ps (__m128 a, int control);
VPERMILPS __m256 _mm256_permute_ps (__m256 a, int control);
VPERMILPS __m128 _mm_permutevar_ps (__m128 a, __m128i control);
VPERMILPS __m256 _mm256_permutevar_ps (__m256 a, __m256i control);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


Non-EVEX-encoded instruction, see Exceptions Type 4; 

#UD If VEX.W = 1.

EVEX-encoded instruction, see Exceptions Type E4NF.

#UD If either (E)VEX.vvvv != 1111B and with imm8.

