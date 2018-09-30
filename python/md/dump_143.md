----------------
title : C++ IOstream (입출력) 라이브러리
--------------


```warning
  이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 [저의 모토인 '지식전파'](http://itguru.tistory.com/notice/107) 를 위해 모든 이들에게 공개하도록 하겠습니다.
```



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F180EB4384E4A8EC128AFA3)

`iostream` 라이브러리의 전체 개요도. 참고로 모두 `char` 형으로 특수화 된 것들이다. 사실은 모두 템플릿으로, 예컨대 `basic_ios<>, basic_iostream<>, basic_streambuf<>` 등이다.

  `iostream` 라이브러리는 객체지향 라이브러리로, 스트림을 이용하여 입출력 기능을 제공한다.

  스트림이란, 여러 장치에 입출력 작업이 실행되는 것을 '추상화' 하여 나타낸 것이다. 보통 스트림은 디스크나 키보드, 혹은 콘솔과 같이 문자들을 이러한 장치들로 부터 주고받을 때 사용된다. 따라서 사용자는 어떤 장치들에 입출력 연산을 하냐에 무관하게, 스트림을 통해 편리하게 입출력을 사용할 수 있게 된다. 예컨대, 파일 스트림은 C++ 객체로 파일들을 수정하고, 여러가지 상호작용할 수 있도록 만들어진 것이다. 또한, 파일 스트림을 디스크의 특정 파일과 연관시켰다면, 파일 스트림에 단순히 작업하므로써 사용자는 실제 디스크의 파일에 물리적 작업(쓰거나 읽거나 등등) 을 할 수 있게 된다.

  스트림과 작업하기 위해서는 C++ 은 아래와 같은 표준 입출력 라이브러리 (standard iostream library) 를 지원하여, 아래와 같은 것들을 가지고 있다. (참고적으로 C 의 경우 C 표준 입출력 라이브러리 (stdio) 를 지원하며 C++ 에서 역시 사용 가능한데, 이 경우 `cstdio.h` 를 참조하면 된다)



### `iostream` 라이브러리는 무엇으로 구성되어 있나?


기초적인 클래스 템플릿들 (Basic class templates)

  입출력 라이브러리는 클래스 템플릿들의 상속 관계로 이루어져 있다. 이러한 클래스 템플릿들은 라이브러리를 타입에 영향을 받지 않게 독립적(type-independent)으로 만들어주게 된다. 이들은 클래스 템플릿의 집합으로, 각각은 2 개의 템플릿 인자를 가지고 있다. 하나는 `char` 로(charT) 입출력될 데이터들을 어떠한 문자로 조작(manipulate) 할 지 결정하고 (예컨대 `char, wchar_t` 등등), 다른 하나는 `trait` 인자로, 입출력될 데이터 처리시 부가적인 성질을 부여하게 된다.

  이 클래스 템플릿들로 부터 `char` 형으로 특수화 된 클래스들 (즉 `char_traits` 에 `char` 이 전달된 경우) 은 템플릿 이름 앞에 붙은 `basic_` 을 뺀 이름을 가지고 있다. 예컨대 `istream` 은 `basic_istream` 으로 부터 `char` 형으로 특수화 된 클래스 이다. 또한 `fstream` 은 `basic_fstream` 으로 부터 특수화 된 것이다. 유일한 예외는 [ios_base](http://itguru.tistory.com/144)인데, 이는 그 자체로 타입에 무관하기 대문에 템플릿을 기반으로 하지 않지만 어쨋든 클래스 이다.

클래스 템플릿 특수화

  이 라이브러리에는 기본적으로 `iostream` 클래스 템플릿에서 두 가지 형태로 특수화 된 클래스 들이 존재한다. 하나는 위에서도 말했지만 `char` 형태로 데이터들을 조작하는 것이고 다른 하나는 `wchar_t` 형태로 데이터를 조작하는 클래스들이다.

  이 `char` 형으로 특수화 된 클래스들이 위 사진에서도 잘 나와있듯이 `iostream` 라이브러리에서는 더 잘 알려진 형태이다. 이들을 보통 `narrow-oriented` 되었다고 부르는데, [ios](http://itguru.tistory.com/145), [ istream](http://itguru.tistory.com/146)`, ofstream` 과 같은 경우이다. 반대로 `wchar_t` 형태로 특수화 된 경우(wide-oriented 되었다고 부른다), 클래스 이름 앞에 `w` 가 붙게 되는데, 예컨대 `wios, wistream, wofstream` 등이 있다.

표준 객체(standard `object)`

  `iostream` 라이브러리의 일부로, 해더파일 `<iostream>` 에서는 표준 입력과 출력에 입출력 작업을 실행할 객체들이 정의되어 있다. `narrow-oriented` 객체들의 경우 우리에게 친숙한 `cin, cout, cerr, clog` 가 정의되어 있고, `wide-oriented` 객체들의 경우 `wcin, wcout, wcerr, wclog` 들이 있다.

타입

  `iostream` 클래스들은 `trait` 를 기반으로 한 타입과 이들을 특수화 한 타입들을 주로 사용한다.

조작자(Manipulator)

  조작자들은 전역 함수들로, `iostream` 스트림 객체에 삽입(insertion, `<<)` 과 추출(extraction, [>>](http://itguru.tistory.com/147)) 작업과 함께 사용되는 것들이다. 이들은 스트림의 성질이나, 설정된 서식등을 바꾼다. 예를 들어 `endl, hex, scientific` 등을 들 수 있다.




### 전체의 대략적 구성
### 




라이브러리와 이들와 관계로 분류하였다.

* `<`
 [ios](http://itguru.tistory.com/145)`>, <`
 [istream](http://itguru.tistory.com/146)`>, <ostream>,` <streambuf>,<iosfwd>들은 C++ 프로그램들에서 직접적으로 사용되지 않는다. 이들은 단순히 기초 클래스(base `class)` 로 파생 클래스들을 사용시 자동으로 헤더에 포함된다.



* ` <iostream>` 은 표준 입력과 출력에 소통할 수 있도록 하는 객체들을 정의하게 된다 (cin, cout 등)



* `<fstream>` 은 파일 스트림 클래스 및 템플릿 (예컨대 템플릿 `basic_ifstream` 이나 `ofstream` 클래스 등) 들과 `basic_filebuf` 와 사용되는 버퍼 객체들을 정의하고 있다. 이 클래스들은 스트림을 이용하여 파일을 조작하는데 사용된다.

* `<sstream>` 에 들어있는 클래스들은 스트림에 들어있는 문자열 객체들을 조작하는데 사용된다.



* `<iomanip>` 은 추출/삽입 연산자들과 사용되어 플래그들과 서식 옵션들을 수정하는데 쓰이는 표준 조작자와 그것의 인자들을 정의한다.





참고사항

  이 레퍼런스에 수록된 이름들과 원형들, 그리고 예시들은 모두 클래스 템플릿 그 자체 보다는 `char` 형으로 특수화 된 경우이다. 물론 클래스 템플릿들이 다른 타입으로 특수화 될 수 있지만 이렇게 `char` 형으로 특수화 된 경우를 수록한 것이 보기에 더 편하고, 원래 템플릿 이름을 알아내는데 훨씬 용이하므로 이 형태로 나타내었다.



### 표준 입출력 라이브러리(iostream) 의 구성 요소들
### 



클래스


*  [ios_base](http://itguru.tistory.com/144)  :  기초 클래스(base)로 표준 입출력 라이브러리와 타입과 무관한(type-independent) 멤버들만 가지고 있다.

*  [ios](http://itguru.tistory.com/145):  기초 클래스로 표준 입출력 라이브러리의 타입 의존적 멤버들을 가지고 있다.

*  [istream](http://itguru.tistory.com/146)  :  입력(Input) 클래스

* ostream  :  출력(Output) 클래스

* iostream  :  입출력 스트림 클래스

*  [ifstream](http://itguru.tistory.com/151)  :  파일 입력 스트림 클래스



* `ofstream` :  파일 출력 스트림 클래스

* fstream  :  파일 입출력 스트림 클래스

* istringstream  :  입력 문자열 스트림 클래스



* ostringstream  :  출력 문자열 스트림 클래스



* stringstream  :  입출력 문자열 스트림 클래스

* streambuf  :  스트림들의 기초 버퍼 클래스

* filebuf  : 파일 스트림 머퍼 클래스



* stringbuf  :  문자열 스트림 버퍼 클래스




객체


* cin  :  표준 입력 스트림

* cout  :  표준 출력 스트림



* cerr  :  표준 오류 출력 스트림

* `clog` :  표준 로그(log) 출력 스트림




타입


* fpos  :  스트림 위치 클래스 템플릿



* streamoff  :  스트림 오프셋 타입

* streampos  :  스트림 위치 타입



* `streamsize` :  스트림 크기 타입




조작자(Manipulator) - 모두 함수이다.


* boolalpha  :  `bool` 값을 문자열로(true, `false)`

* dec  :  십진수를 사용

* `endl` :  새로운 줄을 추가하고 `flush` 한다.



* `ends` :  `null` 문자를 추가한다.



* fixed  :  고정점 표기를 사용한다.



* `flush` :  스트림 버퍼를 `flush` 한다.



* hex  :  16 진수를 사용한다.



* internal  :  특정 지점에 문자들을 추가하여 폭을 조절한다.



* `left` :  출력을 왼쪽으로 조정한다.



* noboolalpha  :  `bool` 값에 문자열을 사용하지 않는다 (0,1)



* `noshowbase` :  몇 진법으로 나타냈는지 표시하지 않는다.



* `noshowpoint` :  소수점을 표시하지 않는다.



* noshowpos  :  `+` 부호를 표시하지 않는다.



* `noskipws` :  공백문자(whitespace) 를 생략하지 않는다.



* nounitbuf  :  입력(insertion) 뒤 강제로 `flush` 하지 않는다.



* nouppercase  :  대문자를 사용하지 않는다.



* oct  :  8 진수를 사용한다.



* resetiosflags  :  서식 플래그를 초기화 한다.



* right  :  출력을 오른쪽으로 조절한다.



* scientific  :  과학적 표기법을 사용한다.



* setbase  :  진법 플래그를 설정한다.



* setfill  :  어떤 문자로 채울지 설정한다.

* setiosflags  :  서식 플래그를 설정한다.

* setprecision  :  소수점 몇 째 자리 까지 표시할지 설정한다.



* setw  :  출력할 너비를 조절한다.



* showbase  :  몇 진법으로 표시됬는지 표시한다.



* showpoint  :  소수점을 표시한다.



* showpos  :  `+` 부호를 표시한다.



* skipws  :  공백 문자(whitespace)를 생략한다.



* unitbuf  :  입력(insertion) 뒤 버퍼를 `flush` 한다.

* uppercase  :  대문자로만 표시한다.



* ws  :  공백문자를 추출한다.







