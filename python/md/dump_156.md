----------------
title : C++ 레퍼런스 - ios_base::unsetf 함수
cat_title :  ios_base::unsetf
ref_title : unsetf
publish_date : 2011-08-19
--------------



##@ cpp-ref-start

#@ ios_base::unsetf

```cpp-formatted
void unsetf(fmtflags mask);
```


특정 서식 플래그를 끈다(clear)
인자로 전달되는 `mask` 에 켜져 있는 서식 플래그가 꺼지게 된다.

인자를 가지는 조작자인 `resetiosflags` 역시 동일한 작업을 수행한다.



###  인자





`mask`

  어떤 서식 플래그를 끌지 나타내는 비트마스크. 이 비트마스크는 `fmtflags` 타입의 상수들의 조합(OR 연산) 으로 나타낼 수 있다. 아래 실행 예제를 참고하여라.



###  리턴값




없다



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/unsetf/
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main() {
  cout.setf(ios::hex, ios::basefield);  // hex 를 설정한다.
  cout.setf(ios::showbase);             // showbase 를 설정
  cout << 100 << endl;
  cout.unsetf(ios::showbase);  // showbase 를 끝다.
  cout << 100 << endl;
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F12714A584E4DE70D317643)




###  연관된 것들

*  [ios_base::flags](http://itguru.tistory.com/153)  :  서식 플래그를 설정하거나 얻는다.
*  [ios_base::setf](http://itguru.tistory.com/155)  :  특정 서식 플래그를 설정한다.
*  [ios_base::fmtflags](http://itguru.tistory.com/154)  :  스트림 서식 플래그의 타입
* `resetiosflags` :  서식 플래그를 끈다.