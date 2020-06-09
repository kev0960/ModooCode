----------------
title : C++ 레퍼런스 - ios::tie 함수
cat_title :  ios::tie
publish_date : 2012-11-07
ref_title  : ios::tie, tie
--------------

##@ cpp-ref-start

#@ ios::tie


```info-format
ostream* tie ( ) const;
ostream* tie ( ostream* tiestr );
```



엮여진(tied) 스트림을 얻거나설정한다.

첫 번째 함수는 엮여진 출력 스트림을 가리키는 포인터를 리턴한다.

두 번째 함수는 `tiestr` 이 가리키는 객체와 엮고, 이전에 엮여져 있던 객체를 가리키는 포인터를 리턴한다.

디폴트로, 표준 객체인인 `cin`, `cerr`, `clog` 는 `cout` 에 엮여져 있고, 그들의 `wide character` 버전인 `wcin`, `wcerr`, `wclog` 는 `wcout` 에 엮여져 있다.



###  인자


`tiestr` : 엮을 출력 스트림

###  리턴값


호출 이전에 엮여있던 스트림 객체를 가리키는 포인터를 리턴한다. 만일 엮여있던 객체가 없다면 널 포인터를 리턴한다.



###  실행 예제




```cpp-formatted
/*
처음에 *cin.tie() 를 통해 cout 에 내용을 출력한 뒤, cin.tie(&ofs) 로 파일에 엮여진
출력스트림을 변경 한 뒤, 다시 그 내용을 출력한다.

이 예제는 http://www.cplusplus.com/reference/iostream/ios/tie/  에서 가져왔습니다.
*/

#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ostream *prevstr;
  ofstream ofs;
  ofs.open("test.txt");

  cout << "tie example:" << endl;

  *cin.tie() << "This is inserted into cout";
  prevstr = cin.tie(&ofs);
  *cin.tie() << "This is inserted into the file";
  cin.tie(prevstr);

  ofs.close();

  return 0;
}
```



실행 결과



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F155C9141509A42E43CB76F)



파일에 출력된 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F0160DD43509A432F0179D7)




###  템플릿 멤버 정의


```cpp-formatted
(basic_ios<charT, traits>)basic_ostream<charT, traits>* tie() const;
basic_ostream<charT, traits>* tie(basic_ostream<charT, traits> tiestr);
```