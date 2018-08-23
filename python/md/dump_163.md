 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

ios_base::pword


```info
void* & pword (int idx);

```

내부 확장 가능 배열을 가리키는 포인터의 레퍼런스를 얻는다.
  내부 확장 가능 배열의 idx 번째의 원소를 가리키는 포인터의 레퍼런스를 리턴한다. 만일 idx 가 새로운 원소의 인덱스이고, 내부 확장 가능 배열의 크기가 충분하지 않을 경우, 이 함수는 자동으로 0 으로 초기화 된 원소들을 할당하게 된다.

idx 의 값은 이전의xalloc 함수의 호출을 통해 얻어진 값이여야만 한다.

xalloc 함수를 통해 얻어진 인덱스 값은 스트림에 다른 작업 (pword 를 호출하는 것을 포함한) 이 수행되기 전 까지 사용가능하다. 만일 다른 작업이 수행된다면, 인덱스 값은 무용지물이 된다. 물론, pword 를 연속으로 두 번 호출하는 것은 내부 확장 가능 배열의 동일한 포인터의 레퍼런스를 얻게 되는 것이겠지만 말이다.

  내부 확장 가능 배열은 범용의 word 크기의 원소들을 가진 배열로, 스트림 객체 마다 하나 씩 가지게 된다. 이 내부 확장 가능 배열은 임시적으로 데이터를 저장하는데 사용된다.

 인자

idx

  내부 확장 가능 배열의 특정 원소의 인덱스 값이다. 이 값은 이전의xalloc 함수 호출을 통해 얻어져야 한다.

 리턴값

  idx 번째의 원소를 가리키는 포인터의 레퍼런스를 얻는다. 이 때, 이 값은 void* 타입 객체의 레퍼런스가 된다. 실패시, 값이 0 인 void*& 가 리턴된다.

 실행 예제

```cpp
/*

이 예제는
http://msdn.microsoft.com/en-us/library/77z9kz41.aspx
에서 가져왔습니다.

pword 로 cin 객체의 내부 확장 가능 배열의 i 번째 원소에 testing 의 주소를 넣고 이를 출력한다.
*/
#include <iostream>
using namespace std;

int main( )
{
    static const int i = ios_base::xalloc();
    cin.pword( i ) = "testing";
    cout << ( char * )cin.pword( i ) << endl;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F133CFD414EA216FB40D60D)

 연관된 함수


* ios_base::xalloc  :  내부 확장 가능 배열의 새로운 인덱스를 리턴하게 된다. (정적 함수)
* ios_base::iword  :  내부 확장 가능 배열의 정수 원소의 레퍼런스를 리턴한다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios::fail 함수(0)2011.10.23C++ 레퍼런스 - ios::good 함수(0)2011.10.23C++ 레퍼런스 - ios_base::pword 함수(0)2011.10.22C++ 레퍼런스 - ios_base::iword(0)2011.10.22C++ 레퍼런스 - ios_base::xalloc 함수(0)2011.10.22C++ 레퍼런스 - ios_base::getloc 함수(1)2011.08.20

