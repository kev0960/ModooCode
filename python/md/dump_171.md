----------------
title : C++ 레퍼런스 - ios::rdstate 함수
--------------



```warning
이 레퍼런스의 모든 내용은 http://www.cplusplus.com/reference/iostream/
 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ 
Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파' 를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 씹어먹는 C++ 강좌는 어때요?
```


ios::rdstate




```info
iostate rdstate ( ) const;
```

오류 상태 플래그(error state flag)를 얻어온다
현재 스트림의 오류 상태 플래그를 리턴한다.

오류 상태 플래그는 입출력 함수를 호출할 때 발생하는 오류에 따라 자동으로 설정되는 플래그이다. 



###  인자




없다



###  리턴값




ios_base::iostate 타입의 객체로, 아래 상태 플래그 상수들의 조합(OR 연산) 으로 구성된다.  


플래그 값의미eofbit스트림으로부터 추출 작업(extracting operation) 을 수행 중 End – Of –
  File 에 도달하는 경우failbit마지막 입력 작업이 자체의 내부 오류 때문에 실패하였을
  경우 badbit스트림 버퍼의 입출력 작업이 실패하여 발생한 오류goodbit오류가 없다. 
이 값들은 ios_base 에 정적 상수 멤버로 정의되어 있다.

goodbit 을 제외한 다른 오류 플래그가 설정되어 있는지 확인하려면, 그 오류 플래그와 AND 연산을 취해보면 된다. 즉, failbit 가 설정되어 있는지 확인하려면 rdstate 가 리턴한 객체와 비트 AND 연산을 취해서 값이 1 이면 설정된 것이고 0 이면 failbit 가 설정되지 않은 것이다. 

위 방법이 귀찮다면 그냥 eof, fail, bad, good 함수들을 이용해서 각각의 비트가 설정되었는지 아닌지 확인할 수 도 있다. 



###  실행 예제





```cpp
/*이 예제는http://www.cplusplus.com/reference/iostream/ios/rdstate/에서 가져왔습니다.*/#include <iostream>#include <fstream>using namespace std;int main () {    ifstream is;    is.open ("test.txt");    if ( (is.rdstate() & ifstream::failbit ) != 0 )        cerr << "Error opening 'test.txt'\n";    return 0;}
```


실행 결과

같은 디렉토리 내에 test.txt 가 없다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F193DD94F4F6E6A952D5EB7)




###  템플릿 멤버 정의





```cpp
( basic_ios<charT,traits> )iostate rdstate () const;
```




###  연관된 함수






* ios::fail
  :  failbit 이나 badbit 이 설정되어 있는지 확인한다. 



* ios::bad
  :  badbit 이 설정되어 있는지 확인한다.  



* ios::good
 :  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.

* ios::eof
  :  eofbit 이 설정되어 있는지 확인한다. 

* ios::clear
  :  오류 상태 플래그를 설정한다.





공감sns신고
저작자표시

'C++ Reference > IOstream' 카테고리의 다른 글C++ 레퍼런스 - ios::clear(0)
2012.03.25C++ 레퍼런스 - ios::setstate 함수(0)
2012.03.25C++ 레퍼런스 - ios::rdstate 함수(0)
2012.03.25C++ 레퍼런스 - ios::operator void*(0)
2012.01.01C++ 레퍼런스 - ios::operator!(2)
2011.10.23C++ 레퍼런스 - ios::eof 함수(0)
2011.10.23

