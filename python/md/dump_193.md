 itguru Top itguru Top





```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```




istream::ignore


```info

istream&  ignore ( streamsize n = 1, int delim = EOF );
```



문자를 스트림에서 입력 받고 버린다.


문자를 스트림에서 입력 받는 작업은 n 개의 문자를 읽어들이고 버렸거나, 제한 문자 delim 을 만났을 때 중단된다. 참고로, 후자의 경우 제한 문자 delim 역시 스트림에서 추출된다.




 인자



n


추출할 최대 문자의 개수. 이는 streamsize 타입이다.


delim


제한 문자




 리턴값




*this 를 리턴한다.


작업 도중 오류 발생시 다음과 같은 내부 상태 플래그의 값이 변화될 수 있다.



플래그
오류
eofbit
작업 중 문자들의 끝에 도달하였을 때
failbit
-

badbit
위 같은 일들 외의 다른 오류가 발생시








위와 같은 플래그들이ios::exceptions함수로 설정되었다면, ios_base::failure 가 throw 된다.




 실행 예제






```cpp

/*


이 예제는
http://www.cplusplus.com/reference/iostream/istream/ignore/
에서 가져왔습니다.


*/
#include <iostream>
using namespace std;


int main ()
{
char first, last;


cout << "Enter your first and last names: ";


first=cin.get();
cin.ignore(256,' '); // 스트림에서 ' ' 를 지워버린다.


last=cin.get();


cout << "Your initials are " << first << last;


return 0;
}
```




실행 결과











 템플릿 멤버 정의


```cpp

( basic_istream<charT,traits> )
typedef traits::int_type int_type;
basic_istream& ignore (streamsize n = 1, int_type delim = traits::eof() );
```










 연관된 함수








* istream::peek : 그 다음 문자를 추출하지는 않고 읽기만 한다.
* istream::get : 스트림에서 서식화 되지 않는 데이터를 얻는다.
* istream::getline : 스트림에서 한 줄 입력받는다.
* istream::read : 데이터 블록을 읽는다.
* istream::readsome : 버퍼에 가능한 데이터 블록을 읽는다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - istream::peak 함수(0)2012.11.09C++ 레퍼런스 - istream::ignore 함수(1)2012.11.07C++ 레퍼런스 - istream::gcount 함수(0)2012.11.07C++ 레퍼런스 - istream::get 함수(0)2012.11.07C++ 레퍼런스 - ios::tie 함수(0)2012.11.07C++ 레퍼런스 - ios::rdbuf 함수(0)2012.03.25

