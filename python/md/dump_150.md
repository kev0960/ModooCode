 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과저의 모토인 '지식전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios::exceptions


```cpp
iostate exceptions ( ) const;
void exceptions ( iostate except );
```


예외 마스크(exception mask) 를 얻거나 설정한다.

첫번째 형태의 함수는 현재 스트림의 예외 마스크를 리턴한다.

두번째 형태의 함수는 새로운 예외 마스크를 설정하고 clear(rdstate()) 를 호출한다.

  예외 마스크는 모든 스트림 객체가 각각 가지고 있는 데이터로,예외마스크에 해당하는 상태 플래그가 설정 되었을 시 반드시 예외를 throw 해야만 한다. 이 마스크는 ios_base::iostate 타입의 객체로, 아래와 같은 멤버 상수들의 조합으로 값이 결정된다.

[if gte mso 9]><xml> <w:WordDocument>  <w:View>Normal</w:View>  <w:Zoom>0</w:Zoom>  <w:TrackMoves/>  <w:TrackFormatting/>  <w:DisplayHorizontalDrawingGridEvery>0</w:DisplayHorizontalDrawingGridEvery>  <w:DisplayVerticalDrawingGridEvery>2</w:DisplayVerticalDrawingGridEvery>  <w:ValidateAgainstSchemas/>  <w:SaveIfXMLInvalid>false</w:SaveIfXMLInvalid>  <w:IgnoreMixedContent>false</w:IgnoreMixedContent>  <w:AlwaysShowPlaceholderText>false</w:AlwaysShowPlaceholderText>  <w:DoNotPromoteQF/>  <w:LidThemeOther>EN-US</w:LidThemeOther>  <w:LidThemeAsian>KO</w:LidThemeAsian>  <w:LidThemeComplexScript>X-NONE</w:LidThemeComplexScript>  <w:Compatibility>   <w:SpaceForUL/>   <w:BalanceSingleByteDoubleByteWidth/>   <w:DoNotLeaveBackslashAlone/>   <w:ULTrailSpace/>   <w:DoNotExpandShiftReturn/>   <w:AdjustLineHeightInTable/>   <w:BreakWrappedTables/>   <w:SnapToGridInCell/>   <w:WrapTextWithPunct/>   <w:UseAsianBreakRules/>   <w:DontGrowAutofit/>   <w:SplitPgBreakAndParaMark/>   <w:DontVertAlignCellWithSp/>   <w:DontBreakConstrainedForcedTables/>   <w:DontVertAlignInTxbx/>   <w:Word11KerningPairs/>   <w:CachedColBalance/>   <w:UseFELayout/>  </w:Compatibility>  <w:BrowserLevel>MicrosoftInternetExplorer4</w:BrowserLevel>  <m:mathPr>   <m:mathFont m:val="Cambria Math"/>   <m:brkBin m:val="before"/>   <m:brkBinSub m:val="&#45;-"/>   <m:smallFrac m:val="off"/>   <m:dispDef/>   <m:lMargin m:val="0"/>   <m:rMargin m:val="0"/>   <m:defJc m:val="centerGroup"/>   <m:wrapIndent m:val="1440"/>   <m:intLim m:val="subSup"/>   <m:naryLim m:val="undOvr"/>  </m:mathPr></w:WordDocument></xml><![endif][if gte mso 9]><xml> <w:LatentStyles DefLockedState="false" DefUnhideWhenUsed="true"  DefSemiHidden="true" DefQFormat="false" DefPriority="99"  LatentStyleCount="267">  <w:LsdException Locked="false" Priority="0" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Normal"/>  <w:LsdException Locked="false" Priority="9" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="heading 1"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 2"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 3"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 4"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 5"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 6"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 7"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 8"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 9"/>  <w:LsdException Locked="false" Priority="39" Name="toc 1"/>  <w:LsdException Locked="false" Priority="39" Name="toc 2"/>  <w:LsdException Locked="false" Priority="39" Name="toc 3"/>  <w:LsdException Locked="false" Priority="39" Name="toc 4"/>  <w:LsdException Locked="false" Priority="39" Name="toc 5"/>  <w:LsdException Locked="false" Priority="39" Name="toc 6"/>  <w:LsdException Locked="false" Priority="39" Name="toc 7"/>  <w:LsdException Locked="false" Priority="39" Name="toc 8"/>  <w:LsdException Locked="false" Priority="39" Name="toc 9"/>  <w:LsdException Locked="false" Priority="35" QFormat="true" Name="caption"/>  <w:LsdException Locked="false" Priority="10" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Title"/>  <w:LsdException Locked="false" Priority="1" Name="Default Paragraph Font"/>  <w:LsdException Locked="false" Priority="11" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtitle"/>  <w:LsdException Locked="false" Priority="22" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Strong"/>  <w:LsdException Locked="false" Priority="20" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Emphasis"/>  <w:LsdException Locked="false" Priority="59" SemiHidden="false"   UnhideWhenUsed="false" Name="Table Grid"/>  <w:LsdException Locked="false" UnhideWhenUsed="false" Name="Placeholder Text"/>  <w:LsdException Locked="false" Priority="1" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="No Spacing"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 1"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 1"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 1"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 1"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 1"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 1"/>  <w:LsdException Locked="false" UnhideWhenUsed="false" Name="Revision"/>  <w:LsdException Locked="false" Priority="34" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="List Paragraph"/>  <w:LsdException Locked="false" Priority="29" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Quote"/>  <w:LsdException Locked="false" Priority="30" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Quote"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 1"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 1"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 1"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 1"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 1"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 1"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 1"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 1"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 2"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 2"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 2"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 2"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 2"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 2"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 2"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 2"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 2"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 2"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 2"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 2"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 2"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 2"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 3"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 3"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 3"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 3"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 3"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 3"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 3"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 3"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 3"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 3"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 3"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 3"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 3"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 3"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 4"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 4"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 4"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 4"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 4"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 4"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 4"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 4"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 4"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 4"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 4"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 4"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 4"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 4"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 5"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 5"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 5"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 5"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 5"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 5"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 5"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 5"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 5"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 5"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 5"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 5"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 5"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 5"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 6"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 6"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 6"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 6"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 6"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 6"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 6"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 6"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 6"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 6"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 6"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 6"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 6"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 6"/>  <w:LsdException Locked="false" Priority="19" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtle Emphasis"/>  <w:LsdException Locked="false" Priority="21" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Emphasis"/>  <w:LsdException Locked="false" Priority="31" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtle Reference"/>  <w:LsdException Locked="false" Priority="32" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Reference"/>  <w:LsdException Locked="false" Priority="33" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Book Title"/>  <w:LsdException Locked="false" Priority="37" Name="Bibliography"/>  <w:LsdException Locked="false" Priority="39" QFormat="true" Name="TOC Heading"/> </w:LatentStyles></xml><![endif][if gte mso 10]><style> /* Style Definitions */ table.MsoNormalTable	{mso-style-name:"표준 표";	mso-tstyle-rowband-size:0;	mso-tstyle-colband-size:0;	mso-style-noshow:yes;	mso-style-priority:99;	mso-style-qformat:yes;	mso-style-parent:"";	mso-padding-alt:0cm 5.4pt 0cm 5.4pt;	mso-para-margin:0cm;	mso-para-margin-bottom:.0001pt;	mso-pagination:widow-orphan;	font-size:10.0pt;	mso-bidi-font-size:11.0pt;	font-family:"맑은 고딕";	mso-ascii-font-family:"맑은 고딕";	mso-ascii-theme-font:minor-latin;	mso-fareast-font-family:"맑은 고딕";	mso-fareast-theme-font:minor-fareast;	mso-hansi-font-family:"맑은 고딕";	mso-hansi-theme-font:minor-latin;	mso-font-kerning:1.0pt;}table.MsoTableGrid	{mso-style-name:"표 구분선";	mso-tstyle-rowband-size:0;	mso-tstyle-colband-size:0;	mso-style-priority:59;	mso-style-unhide:no;	border:solid windowtext 1.0pt;	mso-border-alt:solid windowtext .5pt;	mso-padding-alt:0cm 5.4pt 0cm 5.4pt;	mso-border-insideh:.5pt solid windowtext;	mso-border-insidev:.5pt solid windowtext;	mso-para-margin:0cm;	mso-para-margin-bottom:.0001pt;	mso-pagination:widow-orphan;	font-size:10.0pt;	mso-bidi-font-size:11.0pt;	font-family:"맑은 고딕";	mso-ascii-font-family:"맑은 고딕";	mso-ascii-theme-font:minor-latin;	mso-fareast-font-family:"맑은 고딕";	mso-fareast-theme-font:minor-fareast;	mso-hansi-font-family:"맑은 고딕";	mso-hansi-theme-font:minor-latin;	mso-font-kerning:1.0pt;}</style><![endif]
플래그 값
의미
eofbit
스트림으로부터 추출 작업(extracting operation)을 수행 중 End – Of –  File에 도달하는 경우
failbit
마지막 입력 작업이 자체의 내부 오류 때문에 실패하였을  경우
badbit
스트림 버퍼의 입출력 작업이 실패하여 발생한 오류
goodbit
오류가 없다.

  한 개 이상의 상태 플래그를 OR 연산자로 조합하여 하나의 비트 마스크(bit mask)를 만들 수 있게 된다. 기본값로 스트림 객체는 goodbit 예외 마스크를 가지고 있는데, 이 말은 어떠한 상태 플래그가 설정 되어도 예외를 던지지 않는다는 의미 이다.

 인자

except

  ios_base::iostate 형의 비트 마스크 값으로 오류 상태 플래그 비트들(badbit, eofbit, failbit) 의 조합에 의해 설정된다.


 리턴값

  ios_base::iostate 타입의 비트 마스크로 이 함수를 호출하기 직전의 예외 마스크를 리턴한다.

 실행 예제

```cpp
/*

사용자가 file 의 exception 에 failbit 와 badbit 를 등록하였으므로 이들 비트가 설정
될 때 예외를 throw 하게 된다. 나의 경우 test.txt 파일에 내용이 존재하지 않았으므로
failbit 가 설정되어서 예외가 throw 된 것이다.

*/
#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ifstream file;
    file.exceptions ( ifstream::failbit | ifstream::badbit );

    try
    {
        file.open ("test.txt");
        file.get();
    }

    catch (ifstream::failure e)
    {
        cout << "Exception opening/reading file";
    }

    file.close();

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F145ED6344E4BEA8A334FD9)


 템플릿 멤버 정의

```cpp
// ( basic_ios<charT,traits> )
iostate exceptions () const;
iostate exceptions ( iostate except );
```



 연관된 함수


* ios::rdstate  :  오류 상태 플래그를 얻는다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios_base::width(0)2011.08.18C++ 레퍼런스 - ifstream 클래스(0)2011.08.18C++ 레퍼런스 - ios::exceptions(0)2011.08.18C++ 레퍼런스 - istream::getline 함수(0)2011.08.18C++ 레퍼런스 - istream::operator>> (추출 연산자)(0)2011.08.17C++ 레퍼런스 - istream 클래스(0)2011.08.17

