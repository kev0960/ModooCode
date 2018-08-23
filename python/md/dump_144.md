 itguru Top itguru Top

```warning
  이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과저의 모토인 '지식전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?

```

ios_base


표준 스트림 클래스의 타입과 무관한 멤버들을 포함하고 있는 기초 클래스(base class) 이다.






  ios_base 클래스는 모든 stream 클래스의 기초 클래스가 되도록 만들어졌다. 이 클래스에서는 스트림의 가장 기초적인 부분을 담당하게 되는데, 이는 모든 스트램 객체의 공통적인 부분을 의미한다. 따라서 이 클래스에서 객체를 직접적으로 만들어내는 경우는 없다.

  ios_base 클래스와 파생 클래스 모두 스트림 객체가 입력이냐, 출력이냐에 무관한, 다시 말해 모든 스트림 객체들이 포함해야 하는 멤버들을 포함하고 있다.  이들 중에서 ios_base 는 템플릿 인자 (앞서 말한 두 인자들, http://itguru.tistory.com/143 참조) 들에 무관한 멤버들을 포함하고 있게 된다. 반면에 ios 는 타입에 무관하지 않은 경우를 담당하고 있다.

  구체적으로 말하자면 ios_base 클래스는 스트림의 아래와 같은 정보들을 관리한다고 보면 된다.

서식 정보(Formatting information)



* 서식 플래그(format flag) :  입출력 작업들이 어떠한 형식으로 해석되어야 할지를 지시하는 내부 지시자들의 집합이다. 이 지시자들의 상태는flags,setf 나unsetf 함수들을 호출함으로써 알아내거나 수정될 수 있다.

* 필드 너비(field width) : 출력될 다음 원소의 너비에 대한 정보이다. 이 값은width 함수 호출을 통해 수정되거나 얻어질 수 있다.

* 출력 정밀도(display precision) :  부동 소수점 데이터를 출력시 어떠한 정밀도로 표시할 것인지를 나타낸다. 이 값은precision 함수를 통해 얻어질 수 있다.
* 로케일 객체(locale object) : 입출력 작업을 서식화 할 때 고려해야 할 로케일 정보(언어 문화권의 차이에 따라 달라지는 특성) 들을 담고 있다. 로케일 객체는getloc 함수를 호출함으로써 얻어진다.


상태 정보


* 오류 상태(error state) : 내부 지시자가 현재 스트림의 오류 상태를 나타내고 있다. 객체는ios::rdstate 함수를 호출함으로써 얻어지고, ios::clear 와ios::setstate 함수를 호출함을 통해 수정될 수 있다. 각각의 값은ios::good,ios::eof,ios::fail,ios::bad 를 호출함으로써 얻어진다.

* 예외 마스크(exception mask) : 내부 예외 상태 지시자.ios::exceptions 를 통해 이 값을 얻어낼거나 수정할 수 있다.


그 외


* 이벤트 함수 스택(event function stack) : 특정 이벤트가 일어낼 때 호출되었던 콜백 함수들을 가리키는 포인터들의 스택. 추가적인 콜백 함수들은register_callback 함수를 호출함으로써 스택에 등록할 수 있다.
* 내부 확장 가능 배열(internal extensible arrays) : 두 개의 배열로 long 객체와 void 포인터들을 저장하기 위한 것이다. 이 배열은xalloc 함수를 호출함으로써 확장될 수 있고, 각각의 객체들의 레퍼런스는iword 나pword 함수를 호출함으로써 얻어진다.

 멤버 함수들


* 생성자
* 소멸자

서식


* flags :  서식 플래그를 수정하거나 얻어온다.
* setf  :  특정 서식 플래그를 설정한다.

* unsetf :  특정 서식 플래그를 초기화 한다.

* precision  :  부동 소수점 정밀도를 수정하거나 얻어온다.

* width  :  필드의 너비를 수정하거나 얻어온다.


로케일


* imbue  :  로케일을 채운다.
* getloc  :  현재 로케일을 얻어온다.


내부 확장 가능 배열(internal extensible array)


* xalloc  :  내부 확장 가능 배열의 새로운 인덱스를 리턴한다. (정적 함수)

* iword  :  내부 확장 가능 배열의 특정 정수 원소의 레퍼런스를 얻는다.
* pword  :  내부 확장 가능 배열의 포인터의 레퍼런스를 얻는다.
그 외


* register_callback  :  이벤트 콜백 함수를 등록한다.
* sync_with_stdio :  iostream 과 cstdio 스트림과의 동기화를 활성화 하거나 비활성화 한다.


 멤버 타입들


* event  :  이벤트를 표시하기 위한 타입
* event_callback  :  이벤트 콜백 함수 타입
* fmtflags  :  스트림 서식 플래그를 위한 타입
* iostate  :  스트림 상태 플래그를 위한 타입
* openmode  :  스트림 열기 모드 플래그(opening mode flag)를 위한 타입
* seekdir  :  방향 찾기 플래그를 위한 타입


멤버 클래스


* failure  :  스트림 예외를 위한 기초 클래스
* Init :  표준 스트림 객체를 초기화 한다.



공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - istream::getline 함수(0)2011.08.18C++ 레퍼런스 - istream::operator>> (추출 연산자)(0)2011.08.17C++ 레퍼런스 - istream 클래스(0)2011.08.17C++ 레퍼런스 - ios 클래스(0)2011.08.17C++ 레퍼런스 - ios_base 클래스(0)2011.08.17C++ IOstream (입출력) 라이브러리(1)2011.08.17

