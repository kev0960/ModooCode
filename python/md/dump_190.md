 itguru Top itguru Top





```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/iostream/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```




ios::tie


```info

ostream* tie ( ) const;
ostream* tie ( ostream* tiestr );
```



엮여진(tied) 스트림을 얻거나설정한다.
첫 번째 함수는 엮여진 출력 스트림을 가리키는 포인터를 리턴한다.
두 번째 함수는 tiestr 이 가리키는 객체와 엮고, 이전에 엮여져 있던 객체를 가리키는 포인터를 리턴한다.

디폴트로, 표준 객체인인 cin, cerr, clog 는 cout 에 엮여져 있고, 그들의 wide character 버전인 wcin, wcerr, wclog 는 wcout 에 엮여져 있다.




 인자



tiestr


엮을 출력 스트림




 리턴값



호출 이전에 엮여있던스트림 객체를 가리키는 포인터를 리턴한다. 만일 엮여있던 객체가 없다면 널 포인터를 리턴한다.




 실행 예제



```cpp

/*


 처음에 *cin.tie() 를 통해 cout 에 내용을 출력한 뒤, cin.tie(&ofs) 로
 파일으로 엮여진 출력스트림을 변경 한 뒤, 다시 그 내용을 출력한다.
 이 예제는


http://www.cplusplus.com/reference/iostream/ios/tie/


 에서 가져왔습니다.


*/
#include <iostream>
#include <fstream>
using namespace std;


int main ()
{
ostream *prevstr;
ofstream ofs;
ofs.open ("test.txt");


cout << "tie example:" << endl;


*cin.tie() << "This is inserted into cout";
prevstr = cin.tie (&ofs);
*cin.tie() << "This is inserted into the file";
cin.tie (prevstr);


ofs.close();


return 0;
}
```

실행 결과




파일에 출력된 모습




 템플릿 멤버 정의




```cpp

(basic_ios<charT,traits>)
basic_ostream<charT,traits> * tie () const;
basic_ostream<charT,traits> * tie ( basic_ostream<charT,traits> tiestr );
```



공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >IOstream' 카테고리의 다른 글C++ 레퍼런스 - istream::gcount 함수(0)2012.11.07C++ 레퍼런스 - istream::get 함수(0)2012.11.07C++ 레퍼런스 - ios::tie 함수(0)2012.11.07C++ 레퍼런스 - ios::rdbuf 함수(0)2012.03.25C++ 레퍼런스 - ios::fill 함수(0)2012.03.25C++ 레퍼런스 - ios::clear(0)2012.03.25

