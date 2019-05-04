----------------
title : C++ 레퍼런스 - ios::operator!
cat_title :  ios::operator!
publish_date : 2011-10-23
--------------

##@ cpp-ref-start

#@ ios::operator!

`<istream>` 에 정의됨

```info-format
bool operator ! ( ) const;
```


스트림 객체의 오류 상태 플래그를 확인한다.
만일 스트림의 오류 상태 플래그인 `failbit` 와 `badbit` 중 어느 하나라도 설정되어 있다면 `true` 를 리턴하고 아니면 `false` 를 리턴한다.

이 연산자는 [fail()](http://itguru.tistory.com/165)함수의 동일한 작업을 한다.



###  인자


없다



### 
 리턴값




`failbit` 나 `badbit` 어느 하나라도 설정되어 있다면 `true` 를 리턴한다.
아니면 `false`



###  템플릿 멤버 정의




```cpp-formatted
(basic_ios<charT, traits>)bool operator!() const;
```




###  실행 예제



```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios/operatornot/
에서 가져왔습니다.

*/
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream is;
  is.open("test.txt");
  if (!is) cerr << "Error opening 'test.txt'\n";
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1265704E4EA3679D21067B)

###  참고 자료

*  [ios::fail](http://itguru.tistory.com/165)  :  `failbit` 이나 `badbit` 이 설정되어 있는지 확인한다.
*  [ios::good](http://itguru.tistory.com/164):  스트림에 어떠한 오류 플래그도 설정되지 않았는지 확인한다.