

```warning
이 레퍼런스의 모든 내용은 http://www.cplusplus.com/reference/iostream/
 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ 
Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 씹어먹는 C++ 강좌는 어때요?
```

ios::operator void*
```info
operator void * ( ) const;
```


포인터로 변환한다. (형 변환 연산자 이다)
ios 로 부터 얻어진 스트림 객체는 포인터로 캐스팅 될 수 있다. 만일 오류 플래그 (error flag - failbit 혹은 badbit) 중 어느 하나가 설정된다면 포인터는 NULL 포인터가 되고, 아니면 NULL 이 아닌 포인터가 된다. 

리턴된 포인터는 다른 어떤 변수를 가리키는 것이 아니고 단순히 오류 플래그가 설정되었는지, 아닌지만 알려주는 역할을 한다. 

 인자

없다

 리턴값

만일 failbit 이나 badbit 이 설정되어 있으면 NULL 포인터를 리턴하고 아니면 NULL 포인터가 아닌 것을 리턴한다.

 실행 예제

```cpp
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios/operator_voidpt/
에서 가져왔습니다.

*/
#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
    ifstream is;
    is.open ("test.txt");

    if ( (void*)is == 0)
        cerr << "Error opening 'test.txt'\n";

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F202325454F004D441E9371)

 템플릿 멤버 정의

```cpp
( basic_ios<charT,traits> )
operator void * () const;
```


 연관된 것들

* ios::fail  :  failbit 나 badbit 이 설정되었는지 확인한다.ios::operator! :  스트림 객체를 확인한다.
공감sns신고저작자표시'C++ Reference > IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios::setstate 함수(0)
2012.03.25C++ 레퍼런스 - ios::rdstate 함수(0)
2012.03.25C++ 레퍼런스 - ios::operator void*(0)
2012.01.01C++ 레퍼런스 - ios::operator!(2)
2011.10.23C++ 레퍼런스 - ios::eof 함수(0)
2011.10.23C++ 레퍼런스 - ios::bad 함수(0)
2011.10.23

