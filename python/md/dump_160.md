 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios_base::getloc

```cpp
locale getloc ( ) const;
```


현재 로케일(locale) 을 알아낸다.
스트림 객체의 로케일을 리턴한다.


 인자


없다.


 리턴값


스트림의 로케일 객체를 리턴한다.


 실행 예제

```cpp
// 로케일 이름을 출력한다.
#include <iostream>
#include <locale>
using namespace std;

int main ()
{
    locale current = cout.getloc();
    cout << current.name() << endl; // 현재 로케일 이름을 출력한다.
    return 0;
}
```


실행 결과



 연관된 함수


* ios_base::imbue  :  로케일을 설정한다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios_base::iword(0)2011.10.22C++ 레퍼런스 - ios_base::xalloc 함수(0)2011.10.22C++ 레퍼런스 - ios_base::getloc 함수(1)2011.08.20C++ 레퍼런스 - ios_base::imbue(0)2011.08.20C++ 레퍼런스 - ios_base::register_callback 함수(0)2011.08.20C++ 레퍼런스 - ios_base::precision 함수(0)2011.08.19

