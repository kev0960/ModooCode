----------------------------
title : BNDMOV (Intel x86/64 assembly instruction)
cat_title : BNDMOV
ref_title : BNDMOV
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/B
publish_date: 2020-09-01
----------------------------
#@ BNDMOV

**Move Bounds**

|**Opcode/**\newline{}**Instruction**|**Op/En**|**64/32 **\newline{}**bit Mode **\newline{}**Support**|**CPUID **\newline{}**Feature **\newline{}**Flag**|**Description**|
|------------------------------------|---------|------------------------------------------------------|--------------------------------------------------|---------------|
|66 0F 1A /r\newline{}BNDMOV bnd1, bnd2/m64|RM|NE/V|MPX|Move lower and upper bound from bnd2/m64 to bound register bnd1.|
|66 0F 1A /r\newline{}BNDMOV bnd1, bnd2/m128|RM|V/NE|MPX|Move lower and upper bound from bnd2/m128 to bound register bnd1.|
|66 0F 1B /r\newline{}BNDMOV bnd1/m64, bnd2|MR|NE/V|MPX|Move lower and upper bound from bnd2 to bnd1/m64.|
|66 0F 1B /r\newline{}BNDMOV bnd1/m128, bnd2|MR|V/NE|MPX|Move lower and upper bound from bnd2 to bound register bnd1/m128.|
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|
|-----|---------|---------|---------|
|RM|ModRM:reg (w)|ModRM:r/m (r)|NA|
|MR|ModRM:r/m (w)|ModRM:reg (r)|NA|
### Description


BNDMOV moves a pair of lower and upper bound values from the source operand (the second operand) to the destination (the first operand). Each operation is 128-bit move. The exceptions are same as the `MOV` instruction. The memory format for loading/store bounds in 64-bit mode is shown in Figure 3-5.

This instruction does not change flags.

```embed
<figure>
<svg viewBox="0 0 497.340027 209.160004">
<rect x="0.000000" y="10.000000" width="0.480000" height="181.979996" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="496.859985" y="10.000000" width="0.479980" height="181.979996" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="9.519989" width="497.339996" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="0.000000" y="191.980011" width="497.339996" height="0.480000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="30.719997" y="33.579987" width="285.899994" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="30.719997" y="33.339996" width="286.140015" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="316.380005" y="33.580017" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="30.480000" y="46.839996" width="286.140015" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="30.480000" y="33.339996" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="179.699997" y="33.160004" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="179.699997" y="33.400024" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.899994" y="76.360016" width="320.100006" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="90.899994" y="76.119995" width="320.339996" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="410.760010" y="76.360016" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.660004" y="89.619995" width="320.339996" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="90.660004" y="76.120026" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="260.340027" y="76.000000" width="0.479980" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="260.340027" y="76.240021" width="0.479980" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M379.920013,71.140015 L380.460022,68.560028 L380.640015,67.960022 L381.240021,68.260010 L389.700012,72.700012 L391.200012,73.480011 L389.460022,73.600006 L379.920013,74.320007 L379.260010,74.380005 L379.380005,73.720001 L379.860016,73.360016 L389.400024,72.640015 L389.460022,73.600006 L389.160004,73.540009 L380.700012,69.100006 L381.240021,68.260010 L381.480011,68.800018 L380.940002,71.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M379.380005,73.720001 L379.920013,71.140015 L380.940002,71.380005 L380.399994,73.959991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M380.400024,71.260010 L380.940033,68.680023 L389.400024,73.119995 L379.860016,73.839996" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.860016,52.899994 L292.620026,52.839996 L292.500031,53.320007 L292.740021,53.380005" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M379.980011,70.959991 L380.220001,71.019989 L380.100006,71.500000 L379.860016,71.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M292.860016,52.899994 L292.740021,53.380005 L379.860016,71.440002 L379.980011,70.959991" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.300003,68.980011 L231.840012,66.339996 L232.020004,65.740021 L232.620010,66.040009 L241.139999,70.540009 L242.639999,71.320007 L240.900009,71.440002 L231.300003,72.160004 L230.639999,72.220001 L230.759995,71.559998 L231.240005,71.200012 L240.840012,70.480011 L240.900009,71.440002 L240.599991,71.380005 L232.080002,66.880005 L232.620010,66.040009 L232.860001,66.580017 L232.319992,69.220001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M230.759995,71.559998 L231.300003,68.980011 L232.319992,69.220001 L231.779984,71.799988" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.779984,69.100006 L232.319992,66.459991 L240.839981,70.959991 L231.239975,71.679993" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.239990,50.679993 L143.999985,50.619995 L143.879990,51.100006 L144.119995,51.160004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M231.360001,68.739990 L231.599991,68.799988 L231.479996,69.279999 L231.240005,69.220001" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M144.239990,50.679993 L144.119995,51.160004 L231.239975,69.220001 L231.360001,68.739990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="23.100002" y="117.760010" width="285.899994" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="23.100002" y="117.520020" width="286.140015" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="308.760010" y="117.760010" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="22.860004" y="131.019989" width="286.140015" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="22.860004" y="117.520020" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.139999" y="117.400024" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="172.139999" y="117.640015" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="83.339996" y="160.540009" width="320.100006" height="13.500000" fill-rule="nonzero"  fill=" rgb(255,255,255) " stroke="black" />
<rect x="83.339996" y="160.300018" width="320.339996" height="0.479980" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="403.200012" y="160.540009" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="83.099991" y="173.799988" width="320.339996" height="0.480010" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="83.099991" y="160.300018" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.719986" y="160.180023" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="252.719986" y="160.420013" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M374.100006,162.820007 L375.300018,159.820007 L375.839996,160.240021 L383.399994,166.179993 L384.779999,167.260010 L383.040009,167.080017 L373.500000,166.000000 L372.779999,165.880005 L373.080017,165.279999 L373.559998,164.980011 L383.100006,166.059998 L383.040009,167.080017 L382.740021,166.960022 L375.179993,161.020020 L375.839996,160.240021 L375.959991,160.779999 L375.000000,163.179993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M373.080017,165.279999 L374.100006,162.820007 L375.000031,163.179993 L373.980011,165.639984" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M374.520020,163.000000 L375.480011,160.600006 L383.040009,166.540009 L373.500031,165.459991" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.840027,127.540009 L288.660034,127.480011 L288.480042,127.899994 L288.660034,127.960022" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M374.160004,162.640015 L374.339996,162.700012 L374.160004,163.120026 L373.980011,163.060028" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M288.840027,127.540009 L288.660034,127.960022 L373.980042,163.059998 L374.160034,162.640015" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M309.900024,163.360016 L310.440033,160.780029 L310.560028,160.180023 L311.220032,160.480011 L319.740021,164.920013 L321.180023,165.700012 L319.500031,165.820007 L309.900024,166.600006 L309.240021,166.660004 L309.360016,166.000031 L309.840027,165.640015 L319.440033,164.860016 L319.500031,165.820007 L319.200012,165.760010 L310.680023,161.320007 L311.220032,160.480011 L311.460022,161.020020 L310.920013,163.600006" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M309.360016,166.000000 L309.900024,163.359985 L310.920013,163.600006 L310.380005,166.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M310.380005,163.480011 L310.920013,160.900024 L319.440002,165.339996 L309.839996,166.120026" fill-rule="evenodd"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.779999,127.959991 L138.539993,127.899994 L138.419998,128.380005 L138.660004,128.440002" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M309.960022,163.179993 L310.200012,163.239990 L310.080017,163.720001 L309.840027,163.660004" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<path d="M138.779999,127.959991 L138.660004,128.440002 L309.840027,163.660004 L309.960022,163.179993" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="332.220001" y="160.660004" width="0.480010" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="332.220001" y="160.899994" width="0.480010" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.699997" y="161.200012" width="0.480000" height="0.239990" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<rect x="170.699997" y="161.440002" width="0.480000" height="13.740000" fill-rule="nonzero"  fill=" rgb(0,0,0) " stroke="black" />
<text x="326.100006" y="156.519989" textLength="3.854359" font-size="8px">4</text>
<text x="441.256165" y="122.919983" textLength="3.854359" font-size="8px">e</text>
<text x="437.477356" y="122.919983" textLength="3.854359" font-size="8px">d</text>
<text x="433.632690" y="122.919983" textLength="3.854359" font-size="8px">o</text>
<text x="427.867798" y="122.919983" textLength="5.774606" font-size="8px">m</text>
<text x="425.946869" y="122.919983" textLength="1.927179" font-size="8px"> </text>
<text x="424.085541" y="122.919983" textLength="1.927179" font-size="8px">t</text>
<text x="422.556274" y="122.919983" textLength="1.538971" font-size="8px">i</text>
<text x="416.412872" y="122.919983" textLength="2.308456" font-size="8px">-</text>
<text x="412.573761" y="122.919983" textLength="3.854359" font-size="8px">2</text>
<text x="406.874023" y="122.919983" textLength="1.927179" font-size="8px"> </text>
<text x="403.029358" y="122.919983" textLength="3.854359" font-size="8px">n</text>
<text x="401.500092" y="122.919983" textLength="1.538971" font-size="8px">i</text>
<text x="399.638763" y="122.919983" textLength="1.927179" font-size="8px"> </text>
<text x="396.182312" y="122.919983" textLength="3.466150" font-size="8px">y</text>
<text x="380.500061" y="122.919983" textLength="3.854359" font-size="8px">e</text>
<text x="374.735168" y="122.919983" textLength="5.774606" font-size="8px">m</text>
<text x="372.873840" y="122.919983" textLength="1.927179" font-size="8px"> </text>
<text x="369.029175" y="122.919983" textLength="3.854359" font-size="8px">o</text>
<text x="367.111694" y="122.919983" textLength="1.927179" font-size="8px">t</text>
<text x="360.570374" y="122.919983" textLength="4.623844" font-size="8px">V</text>
<text x="355.229034" y="122.919983" textLength="5.393330" font-size="8px">O</text>
<text x="344.533875" y="122.919983" textLength="5.005121" font-size="8px">D</text>
<text x="334.978394" y="122.919983" textLength="4.623844" font-size="8px">B</text>
<text x="440.160126" y="156.819977" textLength="1.927179" font-size="8px">t</text>
<text x="432.896454" y="156.819977" textLength="3.466150" font-size="8px">s</text>
<text x="429.178650" y="156.819977" textLength="1.927179" font-size="8px">f</text>
<text x="425.334686" y="156.819977" textLength="3.854359" font-size="8px">o</text>
<text x="417.718170" y="156.819977" textLength="1.927179" font-size="8px">t</text>
<text x="339.538452" y="122.919983" textLength="5.005121" font-size="8px">N</text>
<text x="409.678101" y="156.819977" textLength="4.623844" font-size="8px">B</text>
<text x="74.999115" y="156.459991" textLength="3.854359" font-size="8px">6</text>
<text x="398.039001" y="156.039978" textLength="3.854359" font-size="8px">0</text>
<text x="251.363846" y="126.820007" textLength="2.308456" font-size="8px">)</text>
<text x="246.754562" y="126.820007" textLength="4.623844" font-size="8px">B</text>
<text x="242.914749" y="126.820007" textLength="3.854359" font-size="8px">L</text>
<text x="238.699936" y="126.820007" textLength="1.927179" font-size="8px"> </text>
<text x="234.921127" y="126.820007" textLength="3.854359" font-size="8px">d</text>
<text x="231.081314" y="126.820007" textLength="3.854359" font-size="8px">n</text>
<text x="223.401688" y="126.820007" textLength="3.854359" font-size="8px">o</text>
<text x="218.841629" y="126.820007" textLength="4.623844" font-size="8px">B</text>
<text x="205.796432" y="126.820007" textLength="5.005121" font-size="8px">w</text>
<text x="201.957336" y="126.820007" textLength="3.854359" font-size="8px">o</text>
<text x="126.779312" y="126.820007" textLength="2.308456" font-size="8px">)</text>
<text x="112.990967" y="126.820007" textLength="1.927179" font-size="8px"> </text>
<text x="105.372375" y="126.820007" textLength="3.854359" font-size="8px">n</text>
<text x="101.532578" y="126.820007" textLength="3.854359" font-size="8px">u</text>
<text x="93.132706" y="126.820007" textLength="4.623844" font-size="8px">B</text>
<text x="88.917862" y="126.820007" textLength="2.308456" font-size="8px">r</text>
<text x="85.078064" y="126.820007" textLength="3.854359" font-size="8px">e</text>
<text x="72.479996" y="126.820007" textLength="5.005121" font-size="8px">U</text>
<text x="448.964111" y="38.739990" textLength="3.854359" font-size="8px">e</text>
<text x="441.347595" y="38.739990" textLength="3.854359" font-size="8px">o</text>
<text x="435.589630" y="38.739990" textLength="5.774606" font-size="8px">m</text>
<text x="431.758148" y="38.739990" textLength="1.927179" font-size="8px">t</text>
<text x="430.235809" y="38.739990" textLength="1.538971" font-size="8px">i</text>
<text x="227.241501" y="126.820007" textLength="3.854359" font-size="8px">u</text>
<text x="426.398102" y="38.739990" textLength="3.854359" font-size="8px">b</text>
<text x="424.106293" y="38.739990" textLength="2.308456" font-size="8px">-</text>
<text x="420.268585" y="38.739990" textLength="3.854359" font-size="8px">4</text>
<text x="414.509949" y="38.739990" textLength="1.927179" font-size="8px"> </text>
<text x="410.731140" y="38.739990" textLength="3.854359" font-size="8px">n</text>
<text x="409.172058" y="38.739990" textLength="1.538971" font-size="8px">i</text>
<text x="407.251129" y="38.739990" textLength="1.927179" font-size="8px"> </text>
<text x="403.801605" y="38.739990" textLength="3.466150" font-size="8px">y</text>
<text x="397.672089" y="38.739990" textLength="3.854359" font-size="8px">o</text>
<text x="391.914124" y="38.739990" textLength="5.774606" font-size="8px">m</text>
<text x="388.135315" y="38.739990" textLength="3.854359" font-size="8px">e</text>
<text x="382.377350" y="38.739990" textLength="5.774606" font-size="8px">m</text>
<text x="380.456421" y="38.739990" textLength="1.927179" font-size="8px"> </text>
<text x="419.634949" y="156.819977" textLength="3.854359" font-size="8px">e</text>
<text x="374.755981" y="38.739990" textLength="1.927179" font-size="8px">t</text>
<text x="368.214661" y="38.739990" textLength="4.623844" font-size="8px">V</text>
<text x="362.873322" y="38.739990" textLength="5.393330" font-size="8px">O</text>
<text x="352.194122" y="38.739990" textLength="5.005121" font-size="8px">D</text>
<text x="347.205627" y="38.739990" textLength="5.005121" font-size="8px">N</text>
<text x="342.598419" y="38.739990" textLength="4.623844" font-size="8px">B</text>
<text x="443.935425" y="72.639984" textLength="3.854359" font-size="8px">e</text>
<text x="440.475525" y="72.639984" textLength="3.466150" font-size="8px">s</text>
<text x="438.554596" y="72.639984" textLength="1.927179" font-size="8px">f</text>
<text x="432.965088" y="72.639984" textLength="3.854359" font-size="8px">o</text>
<text x="109.212173" y="126.820007" textLength="3.854359" font-size="8px">d</text>
<text x="431.044159" y="72.639984" textLength="1.927179" font-size="8px"> </text>
<text x="427.196045" y="72.639984" textLength="3.854359" font-size="8px">e</text>
<text x="425.275116" y="72.639984" textLength="1.927179" font-size="8px">t</text>
<text x="417.237793" y="72.639984" textLength="4.623844" font-size="8px">B</text>
<text x="82.619110" y="72.279999" textLength="3.854359" font-size="8px">6</text>
<text x="78.779999" y="72.279999" textLength="3.854359" font-size="8px">1</text>
<text x="254.392532" y="42.639984" textLength="4.623844" font-size="8px">B</text>
<text x="250.554825" y="42.639984" textLength="3.854359" font-size="8px">L</text>
<text x="238.666672" y="42.639984" textLength="3.854359" font-size="8px">n</text>
<text x="234.887863" y="42.639984" textLength="3.854359" font-size="8px">u</text>
<text x="231.050156" y="42.639984" textLength="3.854359" font-size="8px">o</text>
<text x="222.241959" y="42.639984" textLength="2.308456" font-size="8px">r</text>
<text x="209.636948" y="42.639984" textLength="3.854359" font-size="8px">o</text>
<text x="134.470001" y="42.579987" textLength="2.308456" font-size="8px">)</text>
<text x="129.862106" y="42.579987" textLength="4.623844" font-size="8px">B</text>
<text x="124.872925" y="42.579987" textLength="5.005121" font-size="8px">U</text>
<text x="105.365448" y="42.579987" textLength="3.854359" font-size="8px">o</text>
<text x="100.805374" y="42.579987" textLength="4.623844" font-size="8px">B</text>
<text x="98.884430" y="42.579987" textLength="1.927179" font-size="8px"> </text>
<text x="96.544785" y="42.579987" textLength="2.308456" font-size="8px">r</text>
<text x="88.927582" y="42.579987" textLength="3.854359" font-size="8px">p</text>
<text x="85.089172" y="42.579987" textLength="3.854359" font-size="8px">p</text>
<text x="80.099991" y="42.579987" textLength="5.005121" font-size="8px">U</text>
<text x="418.711609" y="122.919983" textLength="3.854359" font-size="8px">b</text>
<text x="390.044464" y="122.919983" textLength="3.854359" font-size="8px">o</text>
<text x="210.787003" y="126.820007" textLength="3.854359" font-size="8px">e</text>
<text x="81.238266" y="126.820007" textLength="3.854359" font-size="8px">p</text>
<text x="109.203857" y="42.579987" textLength="3.854359" font-size="8px">u</text>
<text x="408.794952" y="122.919983" textLength="3.854359" font-size="8px">3</text>
<text x="252.719986" y="72.339996" textLength="3.854359" font-size="8px">8</text>
<text x="213.474655" y="42.639984" textLength="5.005121" font-size="8px">w</text>
<text x="423.413757" y="156.819977" textLength="1.927179" font-size="8px"> </text>
<text x="245.099991" y="156.519989" textLength="3.854359" font-size="8px">8</text>
<text x="240.620865" y="126.820007" textLength="2.308456" font-size="8px">(</text>
<text x="258.952606" y="42.639984" textLength="2.308456" font-size="8px">)</text>
<text x="117.251556" y="126.820007" textLength="5.005121" font-size="8px">U</text>
<text x="433.668701" y="38.739990" textLength="1.927179" font-size="8px"> </text>
<text x="113.042267" y="42.579987" textLength="3.854359" font-size="8px">n</text>
<text x="71.160004" y="156.459991" textLength="3.854359" font-size="8px">1</text>
<text x="224.581619" y="42.639984" textLength="1.927179" font-size="8px"> </text>
<text x="357.113281" y="38.739990" textLength="5.774606" font-size="8px">M</text>
<text x="376.617310" y="38.739990" textLength="3.854359" font-size="8px">o</text>
<text x="218.463150" y="42.639984" textLength="3.854359" font-size="8px">e</text>
<text x="92.765991" y="42.579987" textLength="3.854359" font-size="8px">e</text>
<text x="122.170029" y="126.820007" textLength="4.623844" font-size="8px">B</text>
<text x="205.799240" y="42.639984" textLength="3.854359" font-size="8px">L</text>
<text x="198.178543" y="126.820007" textLength="3.854359" font-size="8px">L</text>
<text x="401.509796" y="38.739990" textLength="2.308456" font-size="8px">r</text>
<text x="242.504379" y="42.639984" textLength="3.854359" font-size="8px">d</text>
<text x="372.835052" y="38.739990" textLength="1.927179" font-size="8px"> </text>
<text x="214.626816" y="126.820007" textLength="2.308456" font-size="8px">r</text>
<text x="120.659470" y="42.579987" textLength="1.927179" font-size="8px"> </text>
<text x="384.344727" y="122.919983" textLength="5.774606" font-size="8px">m</text>
<text x="414.238159" y="156.819977" textLength="3.466150" font-size="8px">y</text>
<text x="365.190765" y="122.919983" textLength="1.927179" font-size="8px"> </text>
<text x="416.430878" y="38.739990" textLength="3.854359" font-size="8px">6</text>
<text x="405.658997" y="71.799988" textLength="3.854359" font-size="8px">0</text>
<text x="77.398468" y="126.820007" textLength="3.854359" font-size="8px">p</text>
<text x="393.883575" y="122.919983" textLength="2.308456" font-size="8px">r</text>
<text x="430.979675" y="156.819977" textLength="1.927179" font-size="8px">f</text>
<text x="248.263016" y="42.639984" textLength="2.308456" font-size="8px">(</text>
<text x="421.855408" y="72.639984" textLength="3.466150" font-size="8px">y</text>
<text x="436.316162" y="156.819977" textLength="3.854359" font-size="8px">e</text>
<text x="447.714233" y="72.639984" textLength="1.927179" font-size="8px">t</text>
<text x="114.911911" y="126.820007" textLength="2.308456" font-size="8px">(</text>
<text x="97.692780" y="126.820007" textLength="3.854359" font-size="8px">o</text>
<text x="246.342087" y="42.639984" textLength="1.927179" font-size="8px"> </text>
<text x="436.813202" y="72.639984" textLength="1.927179" font-size="8px">f</text>
<text x="226.442947" y="42.639984" textLength="4.623844" font-size="8px">B</text>
<text x="216.920700" y="126.820007" textLength="1.927179" font-size="8px"> </text>
<text x="116.821060" y="42.579987" textLength="3.854359" font-size="8px">d</text>
<text x="349.529297" y="122.919983" textLength="5.774606" font-size="8px">M</text>
<text x="445.126404" y="38.739990" textLength="3.854359" font-size="8px">d</text>
<text x="122.580414" y="42.579987" textLength="2.308456" font-size="8px">(</text>
<text x="91.211761" y="126.820007" textLength="1.927179" font-size="8px"> </text>
</svg>
<figcaption>Figure 3-5.  Memory Layout of BNDMOV to/from Memory
</figcaption></figure>
```

### Operation
#### BNDMOV register to register
```info-verb
DEST.LB <-  SRC.LB; 
DEST.UB <-  SRC.UB; 
```
#### BNDMOV from memory
```info-verb
IF 64-bit mode THEN
          DEST.LB <-  LOAD_QWORD(SRC); 
          DEST.UB <-  LOAD_QWORD(SRC+8); 
    ELSE
          DEST.LB <-  LOAD_DWORD_ZERO_EXT(SRC); 
          DEST.UB <-  LOAD_DWORD_ZERO_EXT(SRC+4); 
FI;
```
#### BNDMOV to memory
```info-verb
IF 64-bit mode THEN
          DEST[63:0] <-  SRC.LB; 
          DEST[127:64] <-  SRC.UB; 
    ELSE
          DEST[31:0] <-  SRC.LB; 
          DEST[63:32] <-  SRC.UB; 
FI;
```

### Intel C/C++ Compiler Intrinsic Equivalent

```cpp
BNDMOV  void * _bnd_copy_ptr_bounds(const void *q, const void *r)
```
### Flags Affected


None


### Protected Mode Exceptions

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 67H prefix is not used and CS.D=0.
* If 67H prefix is used and CS.D=1.

#### #SS(0)
* If the memory operand effective address is outside the SS segment limit.

#### #GP(0)
* If the memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.
* If the destination operand points to a non-writable segment
* If the DS, ES, FS, or GS segment register contains a NULL segment selector.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while CPL is 3.

#### #PF(fault
* code) If a page fault occurs.

### Real-Address Mode Exceptions

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

#### #GP(0)
* If the memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS
* If the memory operand effective address is outside the SS segment limit.

### Virtual-8086 Mode Exceptions

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.
* If ModRM.r/m encodes BND4-BND7 when Intel MPX is enabled.
* If 16-bit addressing is used.

#### #GP(0)
* If the memory operand effective address is outside the CS, DS, ES, FS, or GS segment limit.

#### #SS(0)
* If the memory operand effective address is outside the SS segment limit.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while CPL is 3.

#### #PF(fault
* code) If a page fault occurs.

### Compatibility Mode Exceptions



Same exceptions as in protected mode.


### 64-Bit Mode Exceptions

#### #UD
* If the LOCK prefix is used but the destination is not a memory operand.
* If ModRM.r/m and REX encodes BND4-BND15 when Intel MPX is enabled.

#### #SS(0)
* If the memory address referencing the SS segment is in a non-canonical form.

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while CPL is 3.

#### #PF(fault
* code) If a page fault occurs.
