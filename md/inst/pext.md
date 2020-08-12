----------------------------
title : PEXT (Intel x86/64 assembly instruction)
cat_title : PEXT
ref_title : PEXT
path : /X86-64 명령어 레퍼런스
----------------------------
#@ PEXT

** Parallel Bits Extract**

|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32**\newline{}**-bit **\newline{}**Mode**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|----------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.LZ.F3.0F38.W0 F5 /r\newline{}PEXT r32a, r32b, r/m32|RVM|V/V|BMI2|Parallel extract of bits from r32b using mask in r/m32, result is writ-ten to r32a.|
|VEX.NDS.LZ.F3.0F38.W1 F5 /r\newline{}PEXT r64a, r64b, r/m64|RVM|V/N.E.|BMI2|Parallel extract of bits from r64b using mask in r/m64, result is writ-ten to r64a.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVM|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|NA|
### Description 


PEXT uses a mask in the second source operand (the third operand) to transfer either contiguous or non-contig-uous bits in the first source operand (the second operand) to contiguous low order bit positions in the destination (the first operand). For each bit set in the MASK, PEXT extracts the corresponding bits from the first source operand and writes them into contiguous lower bits of destination operand. The remaining upper bits of destination are zeroed.

This instruction is not supported in real mode and virtual-8086 mode. The operand size is always 32 bits if not in 64-bit mode. In 64-bit mode operand size 64 requires VEX.W1. VEX.W1 is ignored in non-64-bit modes. An attempt to execute this instruction with VEX.L not equal to 0 will cause #UD.

```embed
<figure>
<svg viewBox="0 0 346.289673 193.519989">
<rect x="234.780304" y="27.640015" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="234.780304" y="27.880005" width="0.479980" height="28.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="297.900299" y="27.640015" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="297.900299" y="27.880005" width="0.480010" height="28.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.500298" y="28.120026" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="103.500298" y="28.360016" width="0.480000" height="28.980000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.200287,106.300018 L330.180298,104.500031 L330.660278,104.080017 L330.960297,104.680023 L335.280273,113.260010 L336.060272,114.820007 L334.560272,113.920013 L326.340302,109.000031 L325.800293,108.640015 L326.280273,108.160004 L326.880280,108.100006 L335.040283,113.020020 L334.560272,113.920013 L334.380280,113.680023 L330.060272,105.100006 L330.960297,104.680023 L330.840302,105.280029 L328.860291,107.080017" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M326.280304,108.160004 L328.200317,106.300018 L328.860291,107.080017 L326.940308,108.940002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.500275,106.660004 L330.480286,104.860016 L334.800262,113.440002 L326.580261,108.519989" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.700287,75.400024 L299.580292,75.220032 L299.220276,75.520020 L299.340302,75.700012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M328.380280,106.180023 L328.500275,106.360016 L328.140289,106.660034 L328.020294,106.480011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M299.700287,75.400024 L299.340302,75.700012 L328.020294,106.480011 L328.380280,106.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.500275,109.240021 L308.640289,106.840027 L308.940277,106.240021 L309.420288,106.660034 L316.620270,113.020020 L317.940277,114.160034 L316.200287,113.920013 L306.780273,112.300018 L306.120270,112.120026 L306.420288,111.580017 L306.960266,111.280029 L316.380280,112.900024 L316.200287,113.920013 L315.960266,113.740021 L308.760284,107.380035 L309.420288,106.660034 L309.540283,107.260010 L308.400269,109.660034" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M306.420288,111.580017 L307.500275,109.240021 L308.400299,109.660004 L307.320282,112.000031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.920288,109.420013 L309.060303,107.020020 L316.260284,113.380005 L306.840302,111.760010" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.000275,75.340027 L236.820282,75.280029 L236.640289,75.700012 L236.820282,75.760040" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M307.620300,109.000000 L307.800293,109.059998 L307.620300,109.480011 L307.440308,109.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M237.000275,75.340027 L236.820282,75.760040 L307.440277,109.420044 L307.620270,109.000031" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M285.120300,109.060028 L286.140289,106.600037 L286.440308,106.000031 L286.920288,106.420013 L294.420288,112.360016 L295.800293,113.440033 L294.060303,113.260040 L284.520294,112.240021 L283.800293,112.120026 L284.100311,111.520020 L284.580292,111.220032 L294.120300,112.240021 L294.060303,113.260040 L293.760315,113.140015 L286.260315,107.200043 L286.920288,106.420013 L287.040314,106.960022 L286.020294,109.420013" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M284.100281,111.520020 L285.120270,109.060028 L286.020294,109.420013 L285.000275,111.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M285.540283,109.240021 L286.560272,106.780029 L294.060272,112.720032 L284.520294,111.700012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M201.960297,75.100006 L201.780304,75.040009 L201.600311,75.459991 L201.780304,75.520020" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M285.180298,108.880005 L285.360291,108.940002 L285.180298,109.360016 L285.000305,109.300018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M201.960297,75.100006 L201.780304,75.520020 L285.000305,109.300018 L285.180298,108.880005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.240295,109.480011 L267.780304,106.900024 L267.900299,106.300018 L268.560303,106.600006 L277.020294,111.100006 L278.520294,111.940002 L276.780304,112.000000 L267.240295,112.660004 L266.580292,112.720001 L266.700287,112.059998 L267.180298,111.700012 L276.720306,111.040009 L276.780304,112.000000 L276.480286,111.940002 L268.020294,107.440002 L268.560303,106.600006 L268.800293,107.140015 L268.260284,109.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M266.700287,112.060028 L267.240295,109.480042 L268.260284,109.720032 L267.720276,112.300018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.720276,109.600006 L268.260284,107.020020 L276.720276,111.520020 L267.180267,112.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M105.660301,74.500000 L105.420296,74.440002 L105.300301,74.920013 L105.540306,74.980011" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M267.300293,109.240021 L267.540283,109.300018 L267.420288,109.780029 L267.180298,109.720032" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M105.660301,74.500000 L105.540306,74.980011 L267.180298,109.720001 L267.300293,109.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.000275" y="28.120026" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="201.000275" y="28.360016" width="0.479980" height="29.040001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="244.080292" y="10.300018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="244.080292" y="10.060028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.220276" y="10.299988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.840302" y="28.180023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.840302" y="10.059998" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="186.060303" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="186.060303" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.200287" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="185.820282" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="185.820282" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.440277" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="205.440277" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.580292" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.200287" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="205.200287" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.820282" y="10.240021" width="19.320000" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="224.820282" y="10.000031" width="19.559999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="243.900299" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.580292" y="28.120026" width="19.559999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="224.580292" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="108.900291" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="108.900291" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.040283" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="108.660301" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="108.660301" y="10.000000" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.400291" y="10.300018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="89.400291" y="10.060028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="108.540291" y="10.299988" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.160301" y="28.180023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.160301" y="10.059998" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.380302" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="31.380302" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="50.520302" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.140297" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="31.140297" y="10.000000" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="50.760292" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="50.760292" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.900291" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="50.520302" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="50.520302" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="70.140297" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="70.140297" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="89.280296" y="10.239990" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.900291" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="69.900291" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="321.300293" y="10.300018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="321.300293" y="10.060028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="340.440277" y="10.299988" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="321.060303" y="28.180023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="321.060303" y="10.059998" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.280304" y="10.360016" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="263.280304" y="10.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.420288" y="10.359985" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.040283" y="28.240021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="263.040283" y="10.119995" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.660278" y="10.240021" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="282.660278" y="10.000031" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="301.800293" y="10.239990" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.420288" y="28.120026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="282.420288" y="10.000000" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="302.040283" y="9.760010" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="302.040283" y="9.519989" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="321.180298" y="9.760010" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="301.800293" y="27.640015" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="301.800293" y="9.520020" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.220276" y="19.720032" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="144.960297" y="19.720032" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="159.360291" y="19.720032" width="8.220000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="173.820282" y="19.720032" width="4.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.940277" y="56.559998" width="19.379999" height="18.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="245.940277" y="56.320007" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.080292" y="56.560028" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.700287" y="74.800018" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.700287" y="56.320007" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.920288" y="56.860016" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="187.920288" y="56.620026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.060303" y="56.859985" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.680298" y="74.740021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="187.680298" y="56.619995" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.300293" y="56.860016" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="207.300293" y="56.620026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="226.440277" y="56.859985" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.060303" y="74.740021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="207.060303" y="56.619995" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="226.680298" y="56.860016" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="226.680298" y="56.620026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.820282" y="56.859985" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="226.440277" y="74.740021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="226.440277" y="56.619995" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="110.760292" y="56.800018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="110.760292" y="56.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="129.900299" y="56.799988" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="110.520302" y="74.680023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="110.520302" y="56.559998" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.320290" y="56.860016" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="91.320290" y="56.620026" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="110.460304" y="56.859985" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.080299" y="74.740021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.080299" y="56.619995" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="33.300301" y="56.800018" width="19.320000" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="33.300301" y="56.560028" width="19.559999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.380302" y="56.799988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="33.060295" y="74.680023" width="19.559999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="33.060295" y="56.559998" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.620293" y="56.800018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="52.620293" y="56.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.760292" y="56.799988" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.380302" y="74.680023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="52.380302" y="56.559998" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="72.000298" y="56.800018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="72.000298" y="56.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="91.140297" y="56.799988" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.760292" y="74.680023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="71.760292" y="56.559998" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.160278" y="56.500000" width="19.379999" height="18.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="323.160278" y="56.260010" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="342.300293" y="56.500000" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="322.920288" y="74.740021" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="322.920288" y="56.260010" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="265.140289" y="56.800018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="265.140289" y="56.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="284.280304" y="56.799988" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="264.900299" y="74.680023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="264.900299" y="56.559998" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="284.520294" y="56.800018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="284.520294" y="56.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.660278" y="56.799988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="284.280304" y="74.680023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="284.280304" y="56.559998" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.900299" y="56.800018" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="303.900299" y="56.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="323.040283" y="56.799988" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.660278" y="74.680023" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="303.660278" y="56.559998" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="137.100281" y="64.720032" width="4.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="147.840302" y="64.720032" width="8.220000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.300293" y="64.720032" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="176.760284" y="64.720032" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="249.060303" y="112.779999" width="19.379999" height="18.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="249.060303" y="112.540009" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.200287" y="112.779999" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.820282" y="131.019989" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.820282" y="112.540009" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="191.040283" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="191.040283" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.180298" y="113.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.800293" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.800293" y="112.840027" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.420288" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="210.420288" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.560303" y="113.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.180298" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="210.180298" y="112.840027" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.800293" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="229.800293" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.940277" y="113.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.560303" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="229.560303" y="112.840027" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.880302" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="113.880302" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="133.020294" y="113.080017" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.640297" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.640297" y="112.840027" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.440300" y="113.140015" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="94.440300" y="112.900024" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="113.580299" y="113.140015" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.200294" y="131.019989" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.200294" y="112.900024" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.420296" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="36.420296" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.560295" y="113.080017" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.180290" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="36.180290" y="112.840027" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.800301" y="113.080017" width="19.320000" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="55.800301" y="112.840027" width="19.559999" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="74.880302" y="113.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.560295" y="130.959991" width="19.559999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="55.560295" y="112.840027" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="75.120293" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="75.120293" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="94.260292" y="113.080017" width="0.480000" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="74.880302" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="74.880302" y="112.840027" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.340302" y="112.779999" width="19.320000" height="18.480000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="326.340302" y="112.540009" width="19.559999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="345.420288" y="112.779999" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.100281" y="131.019989" width="19.559999" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.100281" y="112.540009" width="0.480010" height="18.719999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.260284" y="113.080017" width="19.379999" height="18.719999" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="268.260284" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.400299" y="113.080017" width="0.480010" height="18.959999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.020294" y="131.560028" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="268.020294" y="112.840027" width="0.480010" height="18.959999" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.640289" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="287.640289" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="306.780304" y="113.080017" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.400299" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.400299" y="112.840027" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="307.020294" y="113.080017" width="19.379999" height="18.120001" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="307.020294" y="112.840027" width="19.620001" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="326.160278" y="113.080017" width="0.480010" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="306.780304" y="130.959991" width="19.620001" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="306.780304" y="112.840027" width="0.479980" height="18.360001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="140.220276" y="120.940033" width="4.500000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="150.960297" y="120.940033" width="8.220000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="165.420288" y="120.940033" width="8.160000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="179.880280" y="120.940033" width="4.440000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M69.000298,143.620026 L69.000298,146.980011 L68.340294,146.800018 L59.160301,144.100037 L57.480293,143.620026 L59.160301,143.140015 L68.340294,140.500031 L69.000298,140.320038 L69.000298,140.980011 L68.640297,141.460022 L59.460304,144.100037 L59.160301,143.140015 L59.460304,143.140015 L68.640297,145.840027 L68.340294,146.800018 L67.980293,146.320038 L67.980293,143.620026" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="67.980293" y="140.980011" width="1.020000" height="2.640000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M68.520302,143.620026 L68.520302,146.320038 L59.340309,143.620026 L68.520302,140.980011" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="315.420288" y="143.380035" width="4.200000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="301.500275" y="143.380035" width="7.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="287.580292" y="143.380035" width="7.980000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="273.720276" y="143.380035" width="7.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="259.800293" y="143.380035" width="7.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.880280" y="143.380035" width="7.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="231.960297" y="143.380035" width="7.980000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="218.100281" y="143.380035" width="7.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="204.180298" y="143.380035" width="7.920000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="197.940277" y="143.380035" width="0.240020" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="190.260284" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="184.020294" y="143.380035" width="0.239990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="176.340302" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.160278" y="143.380035" width="0.240020" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="162.480286" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="156.240295" y="143.380035" width="0.239990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="148.560303" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="142.320282" y="143.380035" width="0.240020" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="134.640289" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="128.400299" y="143.380035" width="0.240010" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="120.720299" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="114.540291" y="143.380035" width="0.239990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="106.860298" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="100.620293" y="143.380035" width="0.239990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="92.940300" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="86.700294" y="143.380035" width="0.240010" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="79.020302" y="143.380035" width="7.680000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="72.780296" y="143.380035" width="0.239990" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="68.820290" y="143.380035" width="3.960000" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="43.077934" y="148.119995" textLength="5.724000" font-size="8px">3</text>
<text x="39.893730" y="148.119995" textLength="3.168000" font-size="8px"> </text>
<text x="340.565674" y="145.600006" textLength="5.724000" font-size="8px">0</text>
<text x="337.381470" y="145.600006" textLength="3.168000" font-size="8px"> </text>
<text x="331.394684" y="145.600006" textLength="2.466000" font-size="8px">i</text>
<text x="325.800293" y="145.600006" textLength="5.607000" font-size="8px">b</text>
<text x="270.660278" y="65.500000" textLength="5.724000" font-size="8px">0</text>
<text x="40.020302" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="96.900307" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="119.400307" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="200.640594" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="213.780609" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="238.740295" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="254.400299" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="290.040283" y="122.560028" textLength="6.156000" font-size="8px">S</text>
<text x="316.800293" y="124.780029" textLength="4.579200" font-size="8px">5</text>
<text x="310.620300" y="122.560028" textLength="6.156000" font-size="8px">S</text>
<text x="330.660278" y="121.300018" textLength="6.156000" font-size="8px">S</text>
<text x="36.900887" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="116.280891" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="210.661194" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="235.620880" y="66.280029" textLength="5.724000" font-size="8px">1</text>
<text x="313.140594" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="315.540283" y="23.080017" textLength="4.579200" font-size="8px">1</text>
<text x="254.460297" y="23.080017" textLength="4.579200" font-size="8px">4</text>
<text x="276.180298" y="23.080017" textLength="4.579200" font-size="8px">3</text>
<text x="270.060303" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="216.420288" y="23.080017" textLength="4.579200" font-size="8px">6</text>
<text x="210.300293" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="97.980293" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="91.860298" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="74.400291" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="63.901970" y="23.080017" textLength="4.579200" font-size="8px">0</text>
<text x="59.280296" y="23.080017" textLength="4.579200" font-size="8px">3</text>
<text x="40.860298" y="23.080017" textLength="4.579200" font-size="8px">3</text>
<text x="12.846596" y="72.579437" textLength="5.409000" font-size="8px">a</text>
<text x="18.658806" y="61.659729" textLength="5.724000" font-size="8px">2</text>
<text x="12.420906" y="61.659729" textLength="6.282000" font-size="8px">C</text>
<text x="0.000000" y="61.659729" textLength="6.156000" font-size="8px">S</text>
<text x="14.281197" y="16.659729" textLength="6.282000" font-size="8px">C</text>
<text x="14.521492" y="122.920013" textLength="6.156000" font-size="8px">S</text>
<text x="1.860298" y="122.920013" textLength="6.939000" font-size="8px">D</text>
<text x="290.640289" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="0.000000" y="72.579437" textLength="4.086000" font-size="8px">(</text>
<text x="296.160278" y="124.780029" textLength="4.579200" font-size="8px">7</text>
<text x="296.820282" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="18.257393" y="72.579437" textLength="4.689000" font-size="8px">s</text>
<text x="110.040291" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="329.340302" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="102.542213" y="23.080017" textLength="4.579200" font-size="8px">8</text>
<text x="282.002197" y="125.500000" textLength="4.579200" font-size="8px">8</text>
<text x="8.044197" y="16.659729" textLength="6.255000" font-size="8px">R</text>
<text x="61.860588" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="36.363029" y="148.119995" textLength="3.546000" font-size="8px">t</text>
<text x="53.160301" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="116.160301" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="228.420288" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="45.422218" y="23.080017" textLength="4.579200" font-size="8px">1</text>
<text x="28.277992" y="72.579437" textLength="4.086000" font-size="8px">)</text>
<text x="48.786629" y="148.119995" textLength="5.724000" font-size="8px">1</text>
<text x="336.780304" y="123.580017" textLength="4.579200" font-size="8px">2</text>
<text x="234.540283" y="23.080017" textLength="4.579200" font-size="8px">5</text>
<text x="64.980003" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="277.440277" y="125.500000" textLength="4.579200" font-size="8px">2</text>
<text x="20.519096" y="16.659729" textLength="5.724000" font-size="8px">1</text>
<text x="248.340302" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="81.900002" y="122.560028" textLength="5.724000" font-size="8px">0</text>
<text x="78.780586" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="80.520302" y="23.080017" textLength="4.579200" font-size="8px">2</text>
<text x="309.420288" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="271.260590" y="123.219696" textLength="6.156000" font-size="8px">S</text>
<text x="335.460297" y="23.080017" textLength="4.579200" font-size="8px">0</text>
<text x="1.860298" y="16.659729" textLength="6.156000" font-size="8px">S</text>
<text x="293.160583" y="66.280029" textLength="5.724000" font-size="8px">1</text>
<text x="198.300293" y="23.080017" textLength="4.579200" font-size="8px">7</text>
<text x="120.722221" y="23.080017" textLength="4.579200" font-size="8px">7</text>
<text x="251.280884" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="197.521179" y="66.280029" textLength="5.724000" font-size="8px">1</text>
<text x="34.680290" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="333.848083" y="145.600006" textLength="3.546000" font-size="8px">t</text>
<text x="28.320625" y="148.119995" textLength="5.607000" font-size="8px">b</text>
<text x="6.183907" y="61.659729" textLength="6.255000" font-size="8px">R</text>
<text x="33.912331" y="148.119995" textLength="2.466000" font-size="8px">i</text>
<text x="22.948189" y="72.579437" textLength="5.328000" font-size="8px">k</text>
<text x="331.260284" y="66.280029" textLength="5.724000" font-size="8px">0</text>
<text x="85.082222" y="23.080017" textLength="4.579200" font-size="8px">9</text>
<text x="93.780891" y="66.280029" textLength="5.724000" font-size="8px">1</text>
<text x="8.816399" y="122.920013" textLength="5.688000" font-size="8px">E</text>
<text x="20.645088" y="122.920013" textLength="5.544000" font-size="8px">T</text>
<text x="192.180298" y="20.800018" textLength="6.156000" font-size="8px">S</text>
<text x="4.087799" y="72.579437" textLength="8.757000" font-size="8px">m</text>
</svg>
<figcaption>Figure 4-9.  PEXT Example
</figcaption></figure>
```

### Operation

```info-verb
TEMP <- SRC1;
MASK <- SRC2;
DEST <- 0 ;
m<- 0, k<- 0;
DOWHILE m< OperandSize
          IF MASK[ m] = 1 THEN
                DEST[ k] <- TEMP[ m];
               k <- k+ 1;
          FI
m <- m+ 1;
OD
```
### Flags Affected


None.


### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
PEXT: unsigned __int32 _pext_u32(unsigned __int32 src, unsigned __int32 mask);
PEXT: unsigned __int64 _pext_u64(unsigned __int64 src, unsigned __int32 mask);
```
### SIMD Floating-Point Exceptions


None

### Other Exceptions


See Section 2.5.1, "Exception Conditions for VEX-Encoded GPR Instructions", Table 2-29; additionally

#UD  If VEX.W = 1.

