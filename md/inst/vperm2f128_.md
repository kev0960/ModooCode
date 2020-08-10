### VPERM2F128 -- Permute Floating-Point Values


|**Opcode/**\newline{}**Instruction**|**Op/ **\newline{}**En**|**64/32 bit **\newline{}**Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|------------------------|------------------------------------------------------|--------------------------------------------------|---------------|
|VEX.NDS.256.66.0F3A.W0 06 /r ibVPERM2F128 ymm1, ymm2, ymm3/m256, imm8|RVMI|V/V|AVX|Permute 128-bit floating-point fields in ymm2 and ymm3/mem using controls from imm8 and store result in ymm1.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|RVMI|ModRM:reg (w)|VEX.vvvv (r)|ModRM:r/m (r)|imm8|
### Description


Permute 128 bit floating-point-containing fields from the first source operand (second operand) and second source operand (third operand) using bits in the 8-bit immediate and store results in the destination operand (first operand). The first source operand is a YMM register, the second source operand is a YMM register or a 256-bit memory location, and the destination operand is a YMM register.

Imm8[1:0] select the source for the first destination 128-bit field, imm8[5:4] select the source for the second destination field. If imm8[3] is set, the low 128-bit field is zeroed. If imm8[7] is set, the high 128-bit field is zeroed.

VEX.L must be 1, otherwise the instruction will #UD.

```embed
<figure>
<svg viewBox="0 0 317.460022 216.040009">
<path d="M109.800003,114.399994 L109.860001,114.579987 L109.979996,114.759979 L110.339996,115.000000 L110.520004,115.059998 L110.880005,115.059998 L111.240005,114.940002 L111.419998,114.820007 L111.540009,114.639984 L111.659988,114.519989 L111.720016,114.339996 L111.720016,113.919983 L111.659988,113.739990 L111.600006,113.559998 C111.130997 112.725983,109.707001 113.035004,109.740005 114.040009  L109.740005,114.220001 L109.800003,114.399994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M110.759995,114.100006 L112.199997,118.119995 L112.319992,118.779999 L111.719986,118.839996 L96.179993,119.920013 L94.439987,120.040009 L95.819992,119.020020 L108.419998,109.839996 L109.019989,109.420013 L109.259995,110.020020 L109.080002,110.619995 L96.479996,119.800018 L95.819992,119.020020 L96.119995,118.899994 L111.659988,117.820007 L111.719986,118.839996 L111.239990,118.480011 L109.799988,114.459991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M109.259995,110.020020 L110.759995,114.100006 L109.799988,114.460022 L108.299988,110.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M110.279999,114.279999 L111.719986,118.299988 L96.179993,119.380005 L108.779999,110.200012" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M243.360001,66.940002 L242.699997,65.080017 L110.460007,113.200012 L111.119995,115.059998" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.719986" y="52.480011" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.719986" y="52.240021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.979980" y="52.480011" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="65.740021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="52.240021" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M242.999985,103.720001 L243.359970,103.600006 C244.254990 103.304016,244.109970 101.825012,243.179977 101.739990  L242.999985,101.679993 L242.759995,101.739990 C241.829971 101.825012,241.684982 103.304016,242.579971 103.600006  L242.759995,103.660004 L242.999985,103.720001" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M242.999985,102.700012 L247.919998,102.700012 L247.739975,103.360016 L243.479996,118.360016 L242.999985,120.040009 L242.519974,118.360016 L238.199997,103.360016 L238.019974,102.700012 L238.679977,102.700012 L239.159988,103.059998 L243.479996,118.059998 L242.519974,118.360016 L242.519974,118.059998 L246.779984,103.059998 L247.739975,103.360016 L247.259995,103.720001 L242.999985,103.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="238.680008" y="102.700012" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M242.999985,103.179993 L247.259995,103.179993 L242.999985,118.179993 L238.679977,103.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="242.039993" y="65.980011" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M227.639999,114.399994 L227.699997,114.220001 L227.699997,114.040009 C227.682999 113.000000,226.378006 112.751007,225.840012 113.559998  L225.780014,113.739990 L225.719986,113.919983 L225.719986,114.339996 L225.840012,114.519989 L225.900009,114.639984 L226.020004,114.820007 L226.199997,114.940002 L226.560013,115.059998 L226.979996,115.059998 L227.159988,115.000000 L227.280014,114.880005 L227.460007,114.759979 L227.580002,114.579987 L227.639999,114.399994" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M226.680008,114.100006 L228.180008,110.020020 L228.479996,109.420013 L229.020004,109.839996 L241.620010,119.020020 L243.000015,120.040009 L241.259995,119.920013 L225.720016,118.839996 L225.060013,118.779999 L225.240005,118.119995 L225.780014,117.820007 L241.320023,118.899994 L241.259995,119.920013 L240.960007,119.800018 L228.360001,110.619995 L229.020004,109.839996 L229.139999,110.380005 L227.639999,114.459991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.240005,118.119995 L226.680008,114.100006 L227.639999,114.459991 L226.199997,118.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M227.159988,114.279999 L228.659988,110.200012 L241.259995,119.380005 L225.719986,118.299988" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.860001,65.080017 L94.199997,66.940002 L226.439987,115.060028 L227.100021,113.200012" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.500000,103.720001 L94.860001,103.600006 C95.755005 103.304016,95.610001 101.824005,94.679993 101.739990  L94.500000,101.679993 L94.259995,101.739990 C93.330002 101.825012,93.184998 103.304016,94.080002 103.600006  L94.259995,103.660004 L94.500000,103.720001" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.500000,102.700012 L99.419998,102.700012 L99.240005,103.360016 L94.979996,118.360016 L94.500000,120.040009 L94.020004,118.360016 L89.699997,103.360016 L89.520004,102.700012 L90.179993,102.700012 L90.660004,103.059998 L94.979996,118.059998 L94.020004,118.360016 L94.020004,118.059998 L98.279999,103.059998 L99.240005,103.360016 L98.759995,103.720001 L94.500000,103.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.179993" y="102.700012" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M94.500000,103.179993 L98.759995,103.179993 L94.500000,118.179993 L90.179993,103.179993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="93.539993" y="65.980011" width="1.980000" height="36.720001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.220001" y="52.480011" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.220001" y="52.240021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="52.480011" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="65.740021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="52.240021" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.719986" y="119.980011" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.719986" y="119.740021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.979980" y="119.980011" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="133.240021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="119.740021" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.220001" y="119.980011" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.220001" y="119.740021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="119.980011" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="133.240021" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="119.740021" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.719986" y="9.760010" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="168.719986" y="9.520020" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.979980" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="23.020020" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="9.520020" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="20.220001" y="9.760010" width="148.500000" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="20.220001" y="9.520020" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="168.479996" y="9.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="23.020020" width="148.740005" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="19.979996" y="9.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.719986,104.800018 L249.959976,104.800018 L250.139999,104.740021 L250.259995,104.620026 L250.439987,104.500031 L250.559982,104.380005 L250.679977,104.200012 L250.739975,104.020020 L250.739975,103.600006 C250.617996 103.123016,250.379990 103.149017,250.139999 102.880005  L249.959976,102.820007 L249.539993,102.820007 L249.360001,102.880005 L248.999985,103.120026 L248.879990,103.240021 L248.819992,103.420013 L248.759995,103.600006 L248.759995,104.020020 L248.819992,104.200012 L248.879990,104.380005 L248.999985,104.500031 L249.360001,104.740021 L249.539993,104.800018 L249.719986,104.800018" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.719986,103.839996 L254.699997,103.839996 L254.519974,104.500000 L250.199997,119.500000 L249.719986,121.179993 L249.239975,119.500000 L244.979996,104.500000 L244.799973,103.839996 L245.459976,103.839996 L245.939987,104.199982 L250.199997,119.199982 L249.239975,119.500000 L249.239975,119.199982 L253.559982,104.199982 L254.519974,104.500000 L254.039993,104.859985 L249.719986,104.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="245.460007" y="103.840027" width="4.260000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M249.719986,104.320007 L254.039993,104.320007 L249.719986,119.320007 L245.459976,104.320007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="248.759995" y="23.259979" width="1.980000" height="80.580002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M87.720001,104.800018 L87.899994,104.800018 L88.139999,104.740021 L88.259995,104.620026 L88.440002,104.500031 L88.559998,104.380005 L88.680008,104.020020 L88.740005,103.840027 L88.680008,103.600006 L88.559998,103.240021 L88.440002,103.120026 L88.259995,103.000031 L88.139999,102.880005 L87.899994,102.820007 L87.540009,102.820007 C86.548004 103.081024,86.425003 104.318024,87.360001 104.740021  L87.540009,104.800018 L87.720001,104.800018" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M87.720001,103.839996 L92.699997,103.839996 L92.520004,104.500000 L88.199997,119.500000 L87.720001,121.179993 L87.240005,119.500000 L82.919998,104.500000 L82.740005,103.839996 L83.399994,103.839996 L83.880005,104.199982 L88.199997,119.199982 L87.240005,119.500000 L87.240005,119.199982 L91.559998,104.199982 L92.520004,104.500000 L92.040009,104.859985 L87.720001,104.859985" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="83.399994" y="103.840027" width="4.320000" height="1.020000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M87.720001,104.320007 L92.040009,104.320007 L87.720001,119.320007 L83.399994,104.320007" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="86.759995" y="23.259979" width="1.980000" height="80.580002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.780014,109.119995 L225.900009,108.760010 C226.029007 107.759003,224.882004 107.238983,224.160019 107.919983  L224.040024,108.100006 L223.980026,108.279999 C223.605026 109.161987,224.750015 110.003998,225.480026 109.419983  L225.660019,109.299988 L225.780014,109.119995" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M224.939987,108.640015 L227.159988,104.980011 L227.519974,104.380005 L227.999985,104.920013 L238.499985,116.500000 L239.639999,117.760010 L237.959976,117.280029 L222.959976,113.020020 L222.299973,112.840027 L222.659988,112.300018 L223.259995,112.060028 L238.199997,116.320007 L237.959976,117.280029 L237.719986,117.160004 L227.219986,105.580017 L227.999985,104.920013 L228.059982,105.520020 L225.839981,109.180023" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M222.659988,112.300018 L224.939987,108.640015 L225.839981,109.180023 L223.559982,112.840027" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M225.360001,108.880005 L227.580002,105.220001 L238.080002,116.800018 L223.080002,112.540009" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M88.259995,22.420013 L87.239990,24.100006 L224.460007,109.420013 L225.479996,107.740021" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M108.419998,109.240021 L108.539993,109.420013 L108.660004,109.540009 L108.839996,109.660034 L109.020004,109.720032 L109.380005,109.720032 L109.619995,109.660034 L109.800003,109.600006 L110.039993,109.360016 L110.160004,109.180023 L110.279999,108.820007 L110.220001,108.580017 L110.220001,108.400024 L109.979996,108.040009 C109.278000 107.362030,108.186996 107.947021,108.240005 108.880035  L108.300003,109.060028 L108.419998,109.240021" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M109.259995,108.760010 L111.479996,112.420013 L111.779984,113.020020 L111.179993,113.140015 L96.119995,117.279999 L94.439987,117.760010 L95.580002,116.500000 L106.199997,105.040009 L106.679993,104.500000 L107.039993,105.100006 L106.979996,105.700012 L96.360001,117.160004 L95.580002,116.500000 L95.879990,116.320007 L110.939987,112.180023 L111.179993,113.140015 L110.580002,112.960022 L108.360001,109.300018" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M107.039993,105.100006 L109.259995,108.760010 L108.360001,109.300018 L106.139999,105.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M108.839996,109.000000 L111.059998,112.660004 L96.000000,116.799988 L106.619995,105.339996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M250.259995,24.100006 L249.240005,22.420013 L108.779999,107.920013 L109.799988,109.600006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="10.381500" y="19.899994" textLength="5.415000" font-size="8px">C</text>
<text x="0.000000" y="19.899994" textLength="5.002500" font-size="8px">S</text>
<text x="269.162964" y="127.899994" textLength="4.170000" font-size="8px">1</text>
<text x="264.190491" y="127.899994" textLength="5.002500" font-size="8px">Y</text>
<text x="262.088989" y="127.899994" textLength="2.085000" font-size="8px"> </text>
<text x="259.628967" y="127.899994" textLength="2.497500" font-size="8px">r</text>
<text x="255.430496" y="127.899994" textLength="4.170000" font-size="8px">o</text>
<text x="253.328995" y="127.899994" textLength="2.085000" font-size="8px"> </text>
<text x="242.103012" y="127.899994" textLength="5.002500" font-size="8px">Y</text>
<text x="237.946518" y="127.899994" textLength="2.085000" font-size="8px">,</text>
<text x="224.572525" y="127.899994" textLength="2.085000" font-size="8px">,</text>
<text x="220.432510" y="127.899994" textLength="4.170000" font-size="8px">0</text>
<text x="215.460007" y="127.899994" textLength="5.002500" font-size="8px">X</text>
<text x="239.580002" y="18.279999" textLength="5.002500" font-size="8px">Y</text>
<text x="91.080002" y="18.279999" textLength="5.002500" font-size="8px">Y</text>
<text x="116.951248" y="129.640015" textLength="2.085000" font-size="8px"> </text>
<text x="114.491257" y="129.640015" textLength="2.497500" font-size="8px">r</text>
<text x="110.292770" y="129.640015" textLength="4.170000" font-size="8px">o</text>
<text x="108.251266" y="129.640015" textLength="2.085000" font-size="8px"> </text>
<text x="106.149765" y="129.640015" textLength="2.085000" font-size="8px">,</text>
<text x="101.951263" y="129.640015" textLength="4.170000" font-size="8px">0</text>
<text x="96.978012" y="129.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="94.876511" y="129.640015" textLength="2.085000" font-size="8px"> </text>
<text x="88.622253" y="129.640015" textLength="4.170000" font-size="8px">1</text>
<text x="83.649002" y="129.640015" textLength="5.002500" font-size="8px">X</text>
<text x="81.547501" y="129.640015" textLength="2.085000" font-size="8px"> </text>
<text x="79.491745" y="129.640015" textLength="2.085000" font-size="8px">,</text>
<text x="70.319992" y="129.640015" textLength="5.002500" font-size="8px">X</text>
<text x="96.059998" y="61.000000" textLength="4.170000" font-size="8px">1</text>
<text x="244.560013" y="61.000000" textLength="4.170000" font-size="8px">0</text>
<text x="16.076996" y="62.619995" textLength="4.170000" font-size="8px">1</text>
<text x="10.618500" y="62.619995" textLength="5.415000" font-size="8px">C</text>
<text x="5.223007" y="62.619995" textLength="5.415000" font-size="8px">R</text>
<text x="15.357010" y="128.500000" textLength="4.582500" font-size="8px">T</text>
<text x="0.240005" y="62.619995" textLength="5.002500" font-size="8px">S</text>
<text x="5.393997" y="128.500000" textLength="5.002500" font-size="8px">E</text>
<text x="0.000000" y="128.500000" textLength="5.415000" font-size="8px">D</text>
<text x="96.059998" y="18.279999" textLength="4.170000" font-size="8px">1</text>
<text x="247.075516" y="127.899994" textLength="4.170000" font-size="8px">0</text>
<text x="239.580002" y="61.000000" textLength="5.002500" font-size="8px">X</text>
<text x="226.674026" y="127.899994" textLength="2.085000" font-size="8px"> </text>
<text x="233.748032" y="127.899994" textLength="4.170000" font-size="8px">1</text>
<text x="92.820755" y="129.640015" textLength="2.085000" font-size="8px">,</text>
<text x="75.293243" y="129.640015" textLength="4.170000" font-size="8px">0</text>
<text x="4.984497" y="19.899994" textLength="5.415000" font-size="8px">R</text>
<text x="228.775528" y="127.899994" textLength="5.002500" font-size="8px">X</text>
<text x="91.080002" y="61.000000" textLength="5.002500" font-size="8px">X</text>
<text x="251.274002" y="127.899994" textLength="2.085000" font-size="8px">,</text>
<text x="119.052750" y="129.640015" textLength="5.002500" font-size="8px">Y</text>
<text x="10.375504" y="128.500000" textLength="5.002500" font-size="8px">S</text>
<text x="240.001511" y="127.899994" textLength="2.085000" font-size="8px"> </text>
<text x="244.560013" y="18.279999" textLength="4.170000" font-size="8px">0</text>
<text x="124.025986" y="129.640015" textLength="4.170000" font-size="8px">1</text>
<text x="15.778503" y="19.899994" textLength="4.170000" font-size="8px">2</text>
</svg>
<figcaption>Figure 5-21.  VPERM2F128 Operation
</figcaption></figure>
```

### Operation
#### VPERM2F128
```info-verb
CASE IMM8[1:0] of 
0: DEST[127:0]  <- SRC1[127:0]
1: DEST[127:0]  <- SRC1[255:128]
2: DEST[127:0] <-  SRC2[127:0]
3: DEST[127:0] <-  SRC2[255:128]
ESAC
CASE IMM8[5:4] of 
0: DEST[255:128] <-  SRC1[127:0]
1: DEST[255:128] <-  SRC1[255:128]
2: DEST[255:128] <-  SRC2[127:0]
3: DEST[255:128] <-  SRC2[255:128]
ESAC
IF (imm8[3])
DEST[127:0] <-  0
FI
IF (imm8[7])
DEST[VLMAX-1:128]  <- 0
FI
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
VPERM2F128:  __m256 _mm256_permute2f128_ps (__m256 a, __m256 b, int control)
VPERM2F128:  __m256d _mm256_permute2f128_pd (__m256d a, __m256d b, int control)
VPERM2F128:  __m256i _mm256_permute2f128_si256 (__m256i a, __m256i b, int control)
```
### SIMD Floating-Point Exceptions


None.

### Other Exceptions


See Exceptions Type 6; additionally

#UD If VEX.L = 0

         If VEX.W = 1.

