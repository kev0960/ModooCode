 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과저의 모토인 '지식전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

istream::operator>>


```info
istream& operator>> (bool& val );
istream& operator>> (short& val );
istream& operator>> (unsigned short& val );
istream& operator>> (int& val );
istream& operator>> (unsigned int& val );
istream& operator>> (long& val );
istream& operator>> (unsigned long& val );
istream& operator>> (float& val );
istream& operator>> (double& val );
istream& operator>> (long double& val );
istream& operator>> (void*& val );

istream& operator>> (streambuf* sb );

istream& operator>> (istream& ( *pf )(istream&));
istream& operator>> (ios& ( *pf )(ios&));
istream& operator>> (ios_base& ( *pf )(ios_base&));

// 아래 함수들은 멤버들이 아니라, 전역 함수들이다.

istream& operator>> (istream& is, char& ch );
istream& operator>> (istream& is, signed char& ch );
istream& operator>> (istream& is, unsigned char& ch );

istream& operator>> (istream& is, char* str );
istream& operator>> (istream& is, signed char* str );
istream& operator>> (istream& is, unsigned char* str );
```

서식화 된 데이터를 추출(extract)한다.

  이 연산자(>>) 은 입력 스트림에서 사용되는데, '추출 연산자(extraction operator)' 이라 불리기도 한다. 이는 오른쪽 쉬프트 연산자와 다른 것이다. 이 연산자는 스트림에서 데이터의 해석을 필요로 하는 입력 작업을 수행하게 된다. 예를 들어, 입력 받은 숫자 데이터 (문자 형태로 입력될 것이다) 를 사용자가 지정한 수치 형태로 변환한다든지 등 말이다.

  참고적으로 3 가지 종류의 멤버 함수들과, 한 가지 종류의 전역 함수들이istream 객체에 적용되는 추출 연산자에서 오버로드 된다.


* 첫번재 종류의 멤버 함수는 산술 추출자(arithmetic extractor) 이다. 이들은 입력 데이터로 부터 문자들을 받아서 이 추출자의 인자의 특정 타입의 형태로 값을 해석하게 된다. 그 결과값은 인자로 전달된 변수에 저장되게 된다. (위 소스에서 상단 부분)

* streambuf 형태의 복사는 연산자 우변에 전달된 스트림 버퍼 객체로 부터 더 이상 복사 할 수 없을 때 까지 최대한 많은 문자들을 복사한다.

* 마지막 종류의 멤버 함수는 인자로 함수 포인터를 가지고 있다. 이들은 조작자(manipulator) 함수로 사용되게 만들어졌다. 조작자 함수는 이 연산자와 함께 사용되도록 특이적으로 만들어진 함수들이다. (위 소스에서 세번째 부분)

* 전역 함수가 오버로드 하는 경우는 인자가 문자거나 C 형식 문자열일 때 연산자를 오버로드 하는데, 이들은 입력스트림으로 부터 한 개의 문자 혹은 문자들의 나열을 입력 받는다. (위 소스에서 마지막 부분)


  이 함수들이 연산자 오버로딩 함수들이기 때문에 이 연산자를 사용하기 위해서는

```cpp
strm >> variable;
```

 와 같이 사용하면 된다. 이 때 strm 은istream 객체의 이름이고, variable 은 우변으로 전달되는 인자이다. 물론 이 연산자를 아래처럼 쭉 이어나가서 사용해도 된다.

```cpp
strm >> variable1 >> variable2 >> variable3; //...
```

이는 strm 객체에 추출 연산을 계속 진행하는 것과 다름 없다.

  표준istream 객체에 사용시 효과가 있는 조작자들은


* boolalpha  :  bool 값을 문자열로(true, false)
* dec  :  십진수를 사용
* hex  :  16 진수를 사용한다.

* noboolalpha  :  bool 값에 문자열을 사용하지 않는다 (0,1)

* noskipws :  공백문자(whitespace) 를 생략하지 않는다.
* oct  :  8 진수를 사용한다.

* skipws  :  공백 문자(whitespace)를 생략한다
* ws  :  공백문자를 추출한다.

  다른 조작자들도istream 객체에 사용 가능하지만 효과는 없다.

  아래의 인자를 가지는 조작자들은 istream 객체에 영향이 있다. 이들은 <iomanip> 헤더파일에 정의되어 있으며 명시적으로 include 를 시켜 주어야만 한다.


* setiosflags  :  서식 플래그를 설정한다.
* setbase  :  진법 플래그를 설정한다.

* resetiosflags : 서식 플래그를 재설정 한다.

 인자들


val

  입력 시퀀스(sequence)에서 문자들을 추출하여 주어진 인자의 타입에 맞게 수치값으로 해석하려 한다. 만일 성공적으로 해석하였다면 그 값은 val 에 저장된다. 데이터가 정확히 어떠한 방식으로 해석될지는 이전에 스트림에 적용된 조작자와, 로케일(locale) 에 의해 결정된다.

sb

  입력 시퀀스로 부터 문자들을 추출하여 End Of File 이 나타나기 전이나, 버퍼가 성공적으로 문자를 삽입(insert)할 때 까지 sb 에 저장한다.

pf

  pf(*this) 를 호출하는데, 보통 조작자 함수이다.

ch

  단일 문자를 추출하여 ch 에 저장한다.

str

  문자를 추출하여 C 형식 문자열로 저장한다. (즉 str 이 문자열의 시작 부분을 가리키고, null 문자로 문자열이 끝난다) 추출은 다음 문자가 공백 문자(whitespace) 이거나 널 문자 혹은 End of file 에 도달하였을 때 종료된다. 입력 받은 문자열 끝에는 자동적으로 널 문자가 붙게 된다.

  이 때 만일 필드의 너비가 0 보다 크게 설정되었다면 (이는ios_base::width 혹은 setw 로 설정할 수 있다)  입력 받을 문자의 수를 제한할 수 도 있다(버퍼 오버플로우 문제를 막기 위해). 이 경우 입력 받은 문자의 수가 필드 너비 값에 도달하기 하나 전에, 입력을 중단하고 나머지 한 문자를 널 종료 문자(null terminating character) 로 채운다. 그리고 자동으로 필드 너비 값이 0 으로 재설정 되버린다.

is

  작업이 수행될 스트림 객체. 이는 전역 함수의 첫 번째 인자로 연산자의 왼쪽에 위치한다.


 리턴값

객체 자기 자신을 리턴한다 (*this)

발생된 오류는 내부 플래그를 변화시키게 된다.

[if gte mso 9]><xml> <w:WordDocument>  <w:View>Normal</w:View>  <w:Zoom>0</w:Zoom>  <w:TrackMoves/>  <w:TrackFormatting/>  <w:DisplayHorizontalDrawingGridEvery>0</w:DisplayHorizontalDrawingGridEvery>  <w:DisplayVerticalDrawingGridEvery>2</w:DisplayVerticalDrawingGridEvery>  <w:ValidateAgainstSchemas/>  <w:SaveIfXMLInvalid>false</w:SaveIfXMLInvalid>  <w:IgnoreMixedContent>false</w:IgnoreMixedContent>  <w:AlwaysShowPlaceholderText>false</w:AlwaysShowPlaceholderText>  <w:DoNotPromoteQF/>  <w:LidThemeOther>EN-US</w:LidThemeOther>  <w:LidThemeAsian>KO</w:LidThemeAsian>  <w:LidThemeComplexScript>X-NONE</w:LidThemeComplexScript>  <w:Compatibility>   <w:SpaceForUL/>   <w:BalanceSingleByteDoubleByteWidth/>   <w:DoNotLeaveBackslashAlone/>   <w:ULTrailSpace/>   <w:DoNotExpandShiftReturn/>   <w:AdjustLineHeightInTable/>   <w:BreakWrappedTables/>   <w:SnapToGridInCell/>   <w:WrapTextWithPunct/>   <w:UseAsianBreakRules/>   <w:DontGrowAutofit/>   <w:SplitPgBreakAndParaMark/>   <w:DontVertAlignCellWithSp/>   <w:DontBreakConstrainedForcedTables/>   <w:DontVertAlignInTxbx/>   <w:Word11KerningPairs/>   <w:CachedColBalance/>   <w:UseFELayout/>  </w:Compatibility>  <w:BrowserLevel>MicrosoftInternetExplorer4</w:BrowserLevel>  <m:mathPr>   <m:mathFont m:val="Cambria Math"/>   <m:brkBin m:val="before"/>   <m:brkBinSub m:val="&#45;-"/>   <m:smallFrac m:val="off"/>   <m:dispDef/>   <m:lMargin m:val="0"/>   <m:rMargin m:val="0"/>   <m:defJc m:val="centerGroup"/>   <m:wrapIndent m:val="1440"/>   <m:intLim m:val="subSup"/>   <m:naryLim m:val="undOvr"/>  </m:mathPr></w:WordDocument></xml><![endif][if gte mso 9]><xml> <w:LatentStyles DefLockedState="false" DefUnhideWhenUsed="true"  DefSemiHidden="true" DefQFormat="false" DefPriority="99"  LatentStyleCount="267">  <w:LsdException Locked="false" Priority="0" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Normal"/>  <w:LsdException Locked="false" Priority="9" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="heading 1"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 2"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 3"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 4"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 5"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 6"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 7"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 8"/>  <w:LsdException Locked="false" Priority="9" QFormat="true" Name="heading 9"/>  <w:LsdException Locked="false" Priority="39" Name="toc 1"/>  <w:LsdException Locked="false" Priority="39" Name="toc 2"/>  <w:LsdException Locked="false" Priority="39" Name="toc 3"/>  <w:LsdException Locked="false" Priority="39" Name="toc 4"/>  <w:LsdException Locked="false" Priority="39" Name="toc 5"/>  <w:LsdException Locked="false" Priority="39" Name="toc 6"/>  <w:LsdException Locked="false" Priority="39" Name="toc 7"/>  <w:LsdException Locked="false" Priority="39" Name="toc 8"/>  <w:LsdException Locked="false" Priority="39" Name="toc 9"/>  <w:LsdException Locked="false" Priority="35" QFormat="true" Name="caption"/>  <w:LsdException Locked="false" Priority="10" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Title"/>  <w:LsdException Locked="false" Priority="1" Name="Default Paragraph Font"/>  <w:LsdException Locked="false" Priority="11" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtitle"/>  <w:LsdException Locked="false" Priority="22" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Strong"/>  <w:LsdException Locked="false" Priority="20" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Emphasis"/>  <w:LsdException Locked="false" Priority="59" SemiHidden="false"   UnhideWhenUsed="false" Name="Table Grid"/>  <w:LsdException Locked="false" UnhideWhenUsed="false" Name="Placeholder Text"/>  <w:LsdException Locked="false" Priority="1" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="No Spacing"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 1"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 1"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 1"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 1"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 1"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 1"/>  <w:LsdException Locked="false" UnhideWhenUsed="false" Name="Revision"/>  <w:LsdException Locked="false" Priority="34" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="List Paragraph"/>  <w:LsdException Locked="false" Priority="29" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Quote"/>  <w:LsdException Locked="false" Priority="30" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Quote"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 1"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 1"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 1"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 1"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 1"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 1"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 1"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 1"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 2"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 2"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 2"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 2"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 2"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 2"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 2"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 2"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 2"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 2"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 2"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 2"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 2"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 2"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 3"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 3"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 3"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 3"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 3"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 3"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 3"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 3"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 3"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 3"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 3"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 3"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 3"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 3"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 4"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 4"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 4"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 4"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 4"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 4"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 4"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 4"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 4"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 4"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 4"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 4"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 4"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 4"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 5"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 5"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 5"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 5"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 5"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 5"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 5"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 5"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 5"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 5"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 5"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 5"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 5"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 5"/>  <w:LsdException Locked="false" Priority="60" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Shading Accent 6"/>  <w:LsdException Locked="false" Priority="61" SemiHidden="false"   UnhideWhenUsed="false" Name="Light List Accent 6"/>  <w:LsdException Locked="false" Priority="62" SemiHidden="false"   UnhideWhenUsed="false" Name="Light Grid Accent 6"/>  <w:LsdException Locked="false" Priority="63" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 1 Accent 6"/>  <w:LsdException Locked="false" Priority="64" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Shading 2 Accent 6"/>  <w:LsdException Locked="false" Priority="65" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 1 Accent 6"/>  <w:LsdException Locked="false" Priority="66" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium List 2 Accent 6"/>  <w:LsdException Locked="false" Priority="67" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 1 Accent 6"/>  <w:LsdException Locked="false" Priority="68" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 2 Accent 6"/>  <w:LsdException Locked="false" Priority="69" SemiHidden="false"   UnhideWhenUsed="false" Name="Medium Grid 3 Accent 6"/>  <w:LsdException Locked="false" Priority="70" SemiHidden="false"   UnhideWhenUsed="false" Name="Dark List Accent 6"/>  <w:LsdException Locked="false" Priority="71" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Shading Accent 6"/>  <w:LsdException Locked="false" Priority="72" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful List Accent 6"/>  <w:LsdException Locked="false" Priority="73" SemiHidden="false"   UnhideWhenUsed="false" Name="Colorful Grid Accent 6"/>  <w:LsdException Locked="false" Priority="19" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtle Emphasis"/>  <w:LsdException Locked="false" Priority="21" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Emphasis"/>  <w:LsdException Locked="false" Priority="31" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Subtle Reference"/>  <w:LsdException Locked="false" Priority="32" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Intense Reference"/>  <w:LsdException Locked="false" Priority="33" SemiHidden="false"   UnhideWhenUsed="false" QFormat="true" Name="Book Title"/>  <w:LsdException Locked="false" Priority="37" Name="Bibliography"/>  <w:LsdException Locked="false" Priority="39" QFormat="true" Name="TOC Heading"/> </w:LatentStyles></xml><![endif][if gte mso 10]><style> /* Style Definitions */ table.MsoNormalTable	{mso-style-name:"표준 표";	mso-tstyle-rowband-size:0;	mso-tstyle-colband-size:0;	mso-style-noshow:yes;	mso-style-priority:99;	mso-style-qformat:yes;	mso-style-parent:"";	mso-padding-alt:0cm 5.4pt 0cm 5.4pt;	mso-para-margin:0cm;	mso-para-margin-bottom:.0001pt;	mso-pagination:widow-orphan;	font-size:10.0pt;	;	font-family:"맑은 고딕";	mso-ascii-font-family:"맑은 고딕";	mso-ascii-theme-font:minor-latin;	mso-fareast-font-family:"맑은 고딕";	mso-fareast-theme-font:minor-fareast;	mso-hansi-font-family:"맑은 고딕";	mso-hansi-theme-font:minor-latin;	mso-font-kerning:1.0pt;}table.MsoTableGrid	{mso-style-name:"표 구분선";	mso-tstyle-rowband-size:0;	mso-tstyle-colband-size:0;	mso-style-priority:59;	mso-style-unhide:no;	border:solid windowtext 1.0pt;	mso-border-alt:solid windowtext .5pt;	mso-padding-alt:0cm 5.4pt 0cm 5.4pt;	mso-border-insideh:.5pt solid windowtext;	mso-border-insidev:.5pt solid windowtext;	mso-para-margin:0cm;	mso-para-margin-bottom:.0001pt;	mso-pagination:widow-orphan;	font-size:10.0pt;	;	font-family:"맑은 고딕";	mso-ascii-font-family:"맑은 고딕";	mso-ascii-theme-font:minor-latin;	mso-fareast-font-family:"맑은 고딕";	mso-fareast-theme-font:minor-fareast;	mso-hansi-font-family:"맑은 고딕";	mso-hansi-theme-font:minor-latin;	mso-font-kerning:1.0pt;}</style><![endif]
플래그
오류
eofbit
작업 중 문자들의 끝에 도달하였을 때
failbit
입력받은 데이터가 올바른 타입으로 해석이 되지 않을  경우

(참고로 eofbit시 failbit도 참이 된다)
badbit
위 같은 일들 외의 다른 오류가 발생시
(ios_base::iostate를 참조)

  추가적으로ios::exceptions 의 멤버 함수를 통해 적절하게 플래그가 설정되어있다면, 위와 같은 상황 발생 시 ios_base::failure 예외가 throw 된다.


 실행 예제

```cpp
/*

cin 으로 여러 작업을 수행한다.
이 예제는
http://www.cplusplus.com/reference/iostream/istream/operator%3E%3E/
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main ()
{
    int n;
    char str[10];

    cout << "Enter a number: ";
    cin >> n;
    cout << "You have entered: " << n << endl;

    cout << "Enter a hexadecimal number: ";
    cin >> hex >> n;            // manipulator
    cout << "Its decimal equivalent is: " << n << endl;

    cout << "Enter a word: ";
    cin.width (10);        // limit width
    cin >> str;
    cout << "The first 9 chars of your word are: " << str << endl;

    return 0;
}

```

  실행 결과



 템플릿 멤버 정의

```cpp
// basic_istream<charT,traits>
// 맨 위에 나와 있는 예는 charT 에 char 을 전달한 것들.<여기> 참조
basic_istream& operator>> (bool& val );
basic_istream& operator>> (short& val );
basic_istream& operator>> (unsigned short& val );
basic_istream& operator>> (int& val );
basic_istream& operator>> (unsigned int& val );
basic_istream& operator>> (long& val );
basic_istream& operator>> (unsigned long& val );
basic_istream& operator>> (float& val );
basic_istream& operator>> (double& val );
basic_istream& operator>> (long double& val );
basic_istream& operator>> (void*& val );
basic_istream& operator>> (basic_streambuf<charT,traits>* sb );
basic_istream& operator>> (basic_istream& ( *pf )(istream&));
basic_istream& operator>> (basic_ios<charT,traits>& ( *pf )(basic_ios<charT,traits>&));
basic_istream& operator>> (ios_base& ( *pf )(ios_base&));
```




 템플릿 전역 함수들

```cpp
template <class charT, class traits>
  basic_istream<charT,traits>& operator>> (basic_istream<charT,traits>& is, charT& ch );

template <class charT, class traits>
  basic_istream<charT,traits>& operator>> (basic_istream<charT,traits>& is, signed char& ch );

template <class charT, class traits>
  basic_istream<charT,traits>& operator>> (basic_istream<charT,traits>& is, unsigned char& ch );

template <class charT, class traits>
  basic_istream<charT,traits>& operator>> (basic_istream<charT,traits>& is, charT* str );

template <class charT, class traits>
  basic_istream<charT,traits>& operator>> (basic_istream<charT,traits>& is, signed char* str );

template <class charT, class traits>
  basic_istream<charT,traits>& operator>> (basic_istream<charT,traits>& is, unsigned char* str );

```


 연관된 함수


* istream::get :  서식화 되지 않는 데이터를 스트림에서 가져온다.
* istream::getline  :  스트림에서 한 줄을 입력 받는다.
* ostream::operator<<  :  서식에 맞게 데이터를 삽입한다.
* istream::sentry  :  예외에 안전한 접두/접미 작업을 수행한다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios::exceptions(0)2011.08.18C++ 레퍼런스 - istream::getline 함수(0)2011.08.18C++ 레퍼런스 - istream::operator>> (추출 연산자)(0)2011.08.17C++ 레퍼런스 - istream 클래스(0)2011.08.17C++ 레퍼런스 - ios 클래스(0)2011.08.17C++ 레퍼런스 - ios_base 클래스(0)2011.08.17

