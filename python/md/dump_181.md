----------------
title : C++ 레퍼런스 - ios::fill 함수
cat_title :  ios::fill
ref_title : ios::fill
publish_date : 2012-03-25
--------------



##@ cpp-ref-start

#@ ios::fill

```cpp
char fill ( ) const;
char fill ( char fillch );
```


현재 채우기 문자(fill character)를 얻거나 설정한다.

첫번째 형태의 함수의 경우 채우기 문자를 리턴한다.
두번째 형태의 함수의 경우 `fillch` 로 현재의 채우기 문자를 설정하고, 이전의 채우기 문자를 리턴한다.

인자를 가지는 조작자 (manipulator) `setfill` 역시 채우기 문자를 설정하는데 사용할 수 있다.




###  인자





`fillch`

새롭게 사용할 채우기 문자



###  리턴값



함수 호출 이전에 설정되어 있던 채우기 문자.





###  실행 예제




```cpp-formatted
/*

채우기 문자를 'x' 로 설정하고 이를 사용한다.

이 예제는
http://www.cplusplus.com/reference/iostream/ios/fill/
에서 가져왔습니다

*/
#include <iostream>
using namespace std;

int main() {
  char prev;

  cout.width(10);
  cout << 40 << endl;

  prev = cout.fill('x');
  cout.width(10);
  cout << 40 << endl;

  cout.fill(prev);

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1609C6464F6E78A9187FE3)





###  템플릿 멤버 정의





```cpp-formatted
(basic_ios<charT, traits>)

  typedef charT char_type;
char_type fill() const;
char_type fill(char_type fillch);
```




###  참고 자료


* `setfill` : 채우기 문자를 설정한다. (조작자)
* `ios_base::width` : 필드 폭을 설정하거나 그 값을 얻어온다.