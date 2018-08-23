 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios_base::fmtflags

스트림 서식 플래그(format flag) 를 위한 타입
스트림 서식 플래그를 나타내기 위한 비트 마스크(bit mask) 형태의 타입이다.  이 타입은flags,setf,unsetf 와 같은 함수들의 인자 혹은 리턴 타입에 사용된다. 이들 함수에 전달되는 값들은 아래와 같은 멤버 상수들의 조합(OR 연산) 으로 이루어진다.

[if gte mso 9]><xml> <w:WordDocument>  <w:View>Normal</w:View>  <w:Zoom>0</w:Zoom>  <w:TrackMoves/>  <w:TrackFormatting/>  <w:DisplayHorizontalDrawingGridEvery>0</w:DisplayHorizontalDrawingGridEvery>  <w:DisplayVerticalDrawingGridEvery>2</w:DisplayVerticalDrawingGridEvery>  <w:ValidateAgainstSchemas/>  <w:SaveIfXMLInvalid>false</w:SaveIfXMLInvalid>  <w:IgnoreMixedContent>false</w:IgnoreMixedContent>  <w:AlwaysShowPlaceholderText>false</w:AlwaysShowPlaceholderText>  <w:DoNotPromoteQF/>  <w:LidThemeOther>EN-US</w:LidThemeOther>  <w:LidThemeAsian>KO</w:LidThemeAsian>  <w:LidThemeComplexScript>X-NONE</w:LidThemeComplexScript>  <w:Compatibility>   <w:SpaceForUL/>   <w:BalanceSingleByteDoubleByteWidth/>   <w:DoNotLeaveBackslashAlone/>   <w:ULTrailSpace/>   <w:DoNotExpandShiftReturn/>   <w:AdjustLineHeightInTable/>   <w:BreakWrappedTables/>   <w:SnapToGridInCell/>   <w:WrapTextWithPunct/>   <w:UseAsianBreakRules/>   <w:DontGrowAutofit/>   <w:SplitPgBreakAndParaMark/>   <w:DontVertAlignCellWithSp/>   <w:DontBreakConstrainedForcedTables/>   <w:DontVertAlignInTxbx/>   <w:Word11KerningPairs/>   <w:CachedColBalance/>   <w:UseFELayout/>  </w:Compatibility>  <w:BrowserLevel>MicrosoftInternetExplorer4</w:BrowserLevel>  <m:mathPr>   <m:mathFont m:val="Cambria Math"/>   <m:brkBin m:val="before"/>   <m:brkBinSub m:val="&#45;-"/>   <m:smallFrac m:val="off"/>   <m:dispDef/>   <m:lMargin m:val="0"/>   <m:rMargin m:val="0"/>   <m:defJc m:val="centerGroup"/>   <m:wrapIndent m:val="1440"/>   <m:intLim m:val="subSup"/>   <m:naryLim m:val="undOvr"/>  </m:mathPr></w:WordDocument></xml><![endif][if gte mso 9]><xml> <w:LatentStyles DefLockedState="false" DefUnhideWhenUsed="true"  DefSemiHidden="true" DefQFormat="false" DefPriority="99"  LatentStyleCount="267">  <w:LsdException Locked="false" Priority="0" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Normal"/>  <w:LsdException Locked="false" Priority="9" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="heading 1"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 2"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 3"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 4"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 5"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 6"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 7"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 8"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 9"/>  <w:LsdException Locked="false" Priority="39" Name="toc 1"/>  <w:LsdException Locked="false" Priority="39" Name="toc 2"/>  <w:LsdException Locked="false" Priority="39" Name="toc 3"/>  <w:LsdException Locked="false" Priority="39" Name="toc 4"/>  <w:LsdException Locked="false" Priority="39" Name="toc 5"/>  <w:LsdException Locked="false" Priority="39" Name="toc 6"/>  <w:LsdException Locked="false" Priority="39" Name="toc 7"/>  <w:LsdException Locked="false" Priority="39" Name="toc 8"/>  <w:LsdException Locked="false" Priority="39" Name="toc 9"/>  <w:LsdException Locked="false" Priority="35" QFormat="true" Name="caption"/>  <w:LsdException Locked="false" Priority="10" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Title"/>  <w:LsdException Locked="false" Priority="1" Name="Default Paragraph Font"/>  <w:LsdException Locked="false" Priority="11" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtitle"/>  <w:LsdException Locked="false" Priority="22" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Strong"/>  <w:LsdException Locked="false" Priority="20" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Emphasis"/>  <w:LsdException Locked="false" Priority="59" SemiHidden="false"   UnhideWhenUsed="false" Name="Table Grid"/>  <w:LsdException Locked="false" UnhideWhenUsed="false" Name="Placeholder Text"/>  <w:LsdException Locked="false" Priority="1" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="No Spacing"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 1"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 1"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 1"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 1"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 1"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 1"/>  <w:LsdException Locked="false" UnhideWhenUsed="false" Name="Revision"/>  <w:LsdException Locked="false" Priority="34" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="List Paragraph"/>  <w:LsdException Locked="false" Priority="29" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Quote"/>  <w:LsdException Locked="false" Priority="30" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Quote"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 1"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 1"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 1"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 1"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 1"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 1"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 1"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 1"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 2"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 2"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 2"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 2"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 2"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 2"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 2"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 2"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 2"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 2"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 2"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 2"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 2"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 2"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 3"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 3"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 3"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 3"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 3"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 3"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 3"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 3"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 3"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 3"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 3"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 3"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 3"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 3"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 4"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 4"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 4"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 4"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 4"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 4"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 4"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 4"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 4"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 4"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 4"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 4"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 4"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 4"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 5"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 5"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 5"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 5"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 5"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 5"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 5"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 5"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 5"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 5"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 5"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 5"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 5"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 5"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 6"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 6"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 6"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 6"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 6"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 6"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 6"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 6"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 6"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 6"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 6"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 6"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 6"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 6"/>  <w:LsdException Locked="false" Priority="19" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtle Emphasis"/>  <w:LsdException Locked="false" Priority="21" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Emphasis"/>  <w:LsdException Locked="false" Priority="31" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtle Reference"/>  <w:LsdException Locked="false" Priority="32" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Reference"/>  <w:LsdException Locked="false" Priority="33" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Book Title"/>  <w:LsdException Locked="false" Priority="37" Name="Bibliography"/>  <w:LsdException Locked="false" Priority="39" QFormat="true" Name="TOC Heading"/> </w:LatentStyles></xml><![endif][if gte mso 10]><style> /* Style Definitions */ table.MsoNormalTable	{mso-style-name:"표준 표";	mso-tstyle-rowband-size:0;	mso-tstyle-colband-size:0;	mso-style-noshow:yes;	mso-style-priority:99;	mso-style-qformat:yes;	mso-style-parent:"";	mso-padding-alt:0cm 5.4pt 0cm 5.4pt;	mso-para-margin:0cm;	mso-para-margin-bottom:.0001pt;	mso-pagination:widow-orphan;	font-size:10.0pt;	mso-bidi-font-size:11.0pt;	font-family:"맑은 고딕";	mso-ascii-font-family:"맑은 고딕";	mso-ascii-theme-font:minor-latin;	mso-fareast-font-family:"맑은 고딕";	mso-fareast-theme-font:minor-fareast;	mso-hansi-font-family:"맑은 고딕";	mso-hansi-theme-font:minor-latin;	mso-font-kerning:1.0pt;}table.MsoTableGrid	{mso-style-name:"표 구분선";	mso-tstyle-rowband-size:0;	mso-tstyle-colband-size:0;	mso-style-priority:59;	mso-style-unhide:no;	border:solid windowtext 1.0pt;	mso-border-alt:solid windowtext .5pt;	mso-padding-alt:0cm 5.4pt 0cm 5.4pt;	mso-border-insideh:.5pt solid windowtext;	mso-border-insidev:.5pt solid windowtext;	mso-para-margin:0cm;	mso-para-margin-bottom:.0001pt;	mso-pagination:widow-orphan;	font-size:10.0pt;	mso-bidi-font-size:11.0pt;	font-family:"맑은 고딕";	mso-ascii-font-family:"맑은 고딕";	mso-ascii-theme-font:minor-latin;	mso-fareast-font-family:"맑은 고딕";	mso-fareast-theme-font:minor-fareast;	mso-hansi-font-family:"맑은 고딕";	mso-hansi-theme-font:minor-latin;	mso-font-kerning:1.0pt;}</style><![endif]
필드
멤버 상수
하는 일
독립적인
플래그들
boolalpha

bool데이터를 문자열로 나타내고,그렇게 입력 받는다. (true, false)
showbase
정수 표기시,진법을  명시한다. (0x같은 것)
showpoint
부동 소수점 표기시,소수점을 명시한다
showpos
양수를 표기시 +부호를  붙인다.
skipws
입력 작업시 앞에 나오는 공백 문자(whitespace)를 무시한다.
unitbuf
매 출력 작업 마다flush한다.
uppercase
출력 작업시 소문자를 대문자로 출력한다.
진법 관련
(basefield)
dec
정수를 10진수  형태로 입출력 한다
hex
정수를 16진수  형태로 입출력 한다.
oct
정수를 8진수  형태로 입출력 한다.
부동소수점 관련
(floatfield)
fixed
부동 소수점 데이터를 고정 소수점 (fixed-point)형태로 표기한다.
scientific
부동 소수점 데이터를 과학적 표기(scientific notation)로 출력한다.
너비 맞추기
(adjustfield)
internal
필드 너비(field  width)에 맞게 채우기 문자(fill character)을 덧붙이되,내부의 특정 지점에 덧붙여 진다.
left
필드 너비에 맞게 채우기 문자를 덧붙이되,왼쪽에 덧붙인다.
right
필드 너비에 맞게 채우기 문자를 덧붙이되,오른쪽에 덧붙인다.

이 때 아래와 같은 비트마스크 상수들은 위 플래그들의 몇 개의 조합을 의미한다. 이들은 setf 나 unsetf 에서 사용된다.


플래그 값
오른쪽과 동일하다
adjustfieldleft | right | internalbasefielddec | oct | hexfloatfieldscientific | fixed
플래그들은 OR 연산자를 통해 하나의 fmtflags 로 조합될 수 있다.

이 상수들은 ios_base 클래스의 public 멤버로 정의되므로, ios_base::hex 와 같이 ios_base 의 멤버라는 것을 직접적으로 명시하여 접근하거나, 이를 상속한 클래스나, 이들의 객체에서 ios::hex 나 cout.hex 와 같이도 접근 가능하다.

참고로 ios_base::fmtflags 타입의 이 값들은 같은 이름을 가진 전역 함수인 조작자들과 혼동되서는 안된다. 이 조작자들은 ios_base::fmtflags 타입으로 사용될 수 없으며 (사실 그들은 함수이다!), 이들 상수를 조작자로도 사용할 수 없다. 예컨대 아래와 같은 차이가 있다.

```cpp
ios_base::skipws     // ios_base::fmtflags 타입의 상수
skipws               // 조작자 (전역 함수)
```


꽤 많은 수의 조작자들이 위 플래그들과 이름이 동일하다. 이들에 대한 설명은 조작자를 참고하면 된다. 이러한 조작자들의 기능은 위 플래그들이 하는 일들과 꽤 유사하다. 예를 들어서 showbase 를 조작자로 사용한다면, 역시 정수 데이터를 표기시 진법을 명시하게 되는데,ios_base::setf 에서 인자로 ios_base::showbase 를 전달했다면 이 경우 역시 정수 데이터 표기시 진법을 명시해 달라는 의미이다. 하는 일을 비슷하지만 절대로 혼동해서 사용해서는 안된다.

 실행 예제

```cpp
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/fmtflags/
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main ()
{
  // fmtflags 타입 상수들을 직접 이용하기
  cout.setf (ios_base::hex , ios_base::basefield);
  cout.setf (ios_base::showbase);
  cout << 100 << endl;

  // ios_base 를 상속 받은 ios 에서도 이 멤버들에 접근할 수 있다.
  cout.setf (ios::hex , ios::basefield);
  cout.setf (ios::showbase);
  cout << 100 << endl;

  // 역시 이들을 객체의 멤버 상수들로도 접근할 수 있다.
  cout.setf (cout.hex , cout.basefield);
  cout.setf (cout.showbase);
  cout << 100 << endl;

  // fmtflags 를 타입 자체로도 사용할 수 있다.
  ios_base::fmtflags ff;
  ff = cout.flags();
  ff &= ~cout.basefield;   // basefield 비트들을 초기화 시켜버린다.
  ff |= cout.hex;          // hex 를 설정
  ff |= cout.showbase;     // showbase 를 설정
  cout.flags(ff);
  cout << 100 << endl;

  // 아래는 fmtflags 타입 멤버들을 이용한 것은 아니고
  // 이름이 동일한 조작자 showbase 를 이용한 것이다
  cout << hex << showbase << 100 << endl;

  return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F12059E574E4D4B4D011E0C)


 연관된 것들


* ios_base::flags :  서식 플래그를 설정하거나 얻는다.
* ios_base::setf  :  특정 서식 플래그를 설정한다.
* ios_base::unsetf  :  특정 서식 플래그를 초기화 한다.
* setiosflags  :  서식 플래그들을 설정한다 (조작자)

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios_base::usetf 함수(0)2011.08.19C++ 레퍼런스 - ios_base::setf 함수(0)2011.08.19C++ 레퍼런스 - ios_base::fmtflags 타입(0)2011.08.19C++ 레퍼런스 - ios_base::flags 함수(0)2011.08.19C++ 레퍼런스 - ios_base::width(0)2011.08.18C++ 레퍼런스 - ifstream 클래스(0)2011.08.18

