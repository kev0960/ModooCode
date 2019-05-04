----------------
title : C++ 레퍼런스 - ios::operator void*
cat_title :  ios::operator void*
publish_date : 2012-01-01
--------------



##@ cpp-ref-start

#@ ios::operator `void*`

```info-format
operator void * ( ) const;
```


포인터로 변환한다. (형 변환 연산자 이다)
`ios` 로 부터 얻어진 스트림 객체는 포인터로 캐스팅 될 수 있다. 만일 오류 플래그 (error flag - failbit 혹은 badbit) 중 어느 하나가 설정된다면 포인터는 `NULL` 포인터가 되고, 아니면 `NULL` 이 아닌 포인터가 된다.

리턴된 포인터는 다른 어떤 변수를 가리키는 것이 아니고 단순히 오류 플래그가 설정되었는지, 아닌지만 알려주는 역할을 한다.



###  인자




없다



###  리턴값




만일 `failbit` 이나 `badbit` 이 설정되어 있으면 `NULL` 포인터를 리턴하고 아니면 `NULL` 포인터가 아닌 것을 리턴한다.



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios/operator_voidpt/
에서 가져왔습니다.

*/
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream is;
  is.open("test.txt");

  if ((void*)is == 0) cerr << "Error opening 'test.txt'\n";

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F202325454F004D441E9371)



###  템플릿 멤버 정의




```cpp-formatted
(basic_ios<charT, traits>)operator void*() const;
```




###  연관된 것들

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 나 `badbit` 이 설정되었는지 확인한다.
*  [ios::operator!](http://itguru.tistory.com/168):  스트림 객체를 확인한다.