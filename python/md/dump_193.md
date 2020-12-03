----------------
title : C++ 레퍼런스 - istream::ignore 함수
cat_title :  istream::ignore
ref_title : ignore
publish_date : 2012-11-07
--------------

##@ cpp-ref-start

#@ istream::ignore

`<istream>` 에 정의됨

```cpp
istream&  ignore ( streamsize n = 1, int delim = EOF );
```

문자를 스트림에서 입력 받고 버린다.


문자를 스트림에서 입력 받는 작업은 `n` 개의 문자를 읽어들이고 버렸거나, 제한 문자 `delim` 을 만났을 때 중단된다. 참고로, 후자의 경우 제한 문자 `delim` 역시 스트림에서 추출된다.

###  인자

* `n` : 추출할 최대 문자의 개수. 이는 `streamsize` 타입이다.
* `delim` : 제한 문자

###  리턴값


`*this` 를 리턴한다.
작업 도중 오류 발생시 다음과 같은 내부 상태 플래그의 값이 변화될 수 있다.

|플래그|오류|
|-----|----|
|`eofbit`|작업 중 문자들의 끝에 도달하였을 때|
|`failbit`| -|
|`badbit`|위 같은 일들 외의 다른 오류가 발생시|



위와 같은 플래그들이 [ios::exceptions](http://itguru.tistory.com/150)함수로 설정되었다면, `ios_base::failure` 가 `throw` 된다.


###  실행 예제





```cpp-formatted
/*

이 예제는 http://www.cplusplus.com/reference/iostream/istream/ignore/ 
에서 가져왔습니다.

*/

#include <iostream>
using namespace std;

int main() {
  char first, last;

  cout << "Enter your first and last names: ";

  first = cin.get();
  cin.ignore(256, ' ');  // 스트림에서 ' ' 를 지워버린다.

  last = cin.get();

  cout << "Your initials are " << first << last;

  return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F01016F33509A678D2D4CCE)


###  템플릿 멤버 정의


```cpp-formatted
(basic_istream<charT, traits>)typedef traits::int_type int_type;
basic_istream& ignore(streamsize n = 1, int_type delim = traits::eof());
```

###  참고 자료

*  [istream::peek](http://itguru.tistory.com/194): 그 다음 문자를 추출하지는 않고 읽기만 한다.
*  [istream::get](http://itguru.tistory.com/191): 스트림에서 서식화 되지 않는 데이터를 얻는다.
*  [istream::getline](http://itguru.tistory.com/149): 스트림에서 한 줄 입력받는다.
* istream::read : 데이터 블록을 읽는다.
* istream::readsome : 버퍼에 가능한 데이터 블록을 읽는다.