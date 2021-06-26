----------------
title : C++ 레퍼런스 - ios_base::imbue
cat_title :  ios_base::imbue
publish_date : 2011-08-20
ref_title : imbue, ios_base::imbue
path : /C++ Reference/iostream
--------------



##@ cpp-ref-start

#@ ios_base::imbue

```cpp-formatted
locale imbue(const locale& loc);
```


로케일을 설정(imbue) 한다.
`loc` 를 스트림의 새로운 로케일(locale) 객체로 사용하여, 로케일과 관련있는 작업에 이를 사용한다.

`imbue` 함수 종료 직전에 `imbue_event` 가 발생되며 [register_callback](http://itguru.tistory.com/159)함수를 통해 등록되었던 함수들이 모두 호출되게 된다.





###  인자




`loc`

  스트림의 새롭게 설정될 로케일 객체이다.




###  리턴값




  함수 호출 이전 상태의 로케일 객체



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/imbue/
에서 가져왔습니다.

*/
#include <iostream>
#include <locale>
using namespace std;

int main() {
  locale mylocale("french");  // 로케일 객체를 '프랑스' 로 설정한다.
  cout.imbue(mylocale);       // 이를 cout 로케일로 설정한다.
  cout << (double)3.14159
       << endl;  //프랑스에서는 . 대신 , 를 사용하므로 3,14159 로 표시된다.
  return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F13095D574E4E10412DED75)



###  연관된 것들

*  [ios_base::getloc](http://itguru.tistory.com/160): 현재 로케일을 알아온다.