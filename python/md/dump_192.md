----------------
title : C++ 레퍼런스 - istream::gcount 함수
cat_title :  istream::gcount
ref_title : gcount
publish_date : 2012-11-07
path : /C++ Reference/iostream
--------------

##@ cpp-ref-start

#@ istream::gcount

`<istream>` 에 정의됨

```cpp
streamsize  gcount () const;
```

마지막 서식화 되지 않은 (unformatted) 입력 작업에서 읽어들인 문자의 개수를 리턴한다.


서식화 되지 않는 작업을 하는 함수들은 [get](http://itguru.tistory.com/191), [getline](http://itguru.tistory.com/149), `ignore`, [peek](http://itguru.tistory.com/194), `read`, `readsome`, `putback`, `unget` 을 들 수 있는데, [peek](http://itguru.tistory.com/194), `putback`, `unget` 의 경우 문자를 추출하는 함수가 아니기 때문에 `gcount` 의 리턴값은 항상 0 이 되게 된다.

###  인자

없음

###  리턴값

`streamsize` 타입의 정수값으로, 마지막 서식화되지 않는 입력 작업에서 읽어들인 문자의 수를 리턴한다.

###  실행 예제


```cpp-formatted
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  char str[256];
  ifstream is;

  cout << "Enter the name of an existing text file: ";
  cin.get(str, 256);

  is.open(str);          // open file
  is.getline(str, 256);  // 파일의 내용을 읽는다.

  cout << str << endl;
  cout << is.gcount() << endl;  // 입력 받은 문자의 수

  is.close();  // close file

  return 0;
}
```



실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F1320A43E509A5E7910D3F4)


###  템플릿 멤버 정의


```cpp-formatted
(basic_istream<charT, traits>)streamsize gcount() const;
```

###  참고 자료

*  [istream::get](http://itguru.tistory.com/191): 스트림에서 서식화 되지 않은 데이터를 입력 받는다.
*  [istream::getline](http://itguru.tistory.com/149): 스트림에서 한 줄 입력받는다.
*  [istream::ignore](http://itguru.tistory.com/193): 스트림에서 문자를 받고 버린다.
* `istream::read` : 한 데이터 블록을 읽는다.
* `istream::readsome` : 버퍼에 가능한 데이터 블록을 읽는다.