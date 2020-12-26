----------------
title : C++ 레퍼런스 - ios_base::getloc 함수
cat_title :  ios_base::getloc
publish_date : 2011-08-20
ref_title : getloc, ios_base::getloc
path : /C++ Reference/iostream
--------------



##@ cpp-ref-start

#@ ios_base::getloc

```cpp-formatted
locale getloc() const;
```

현재 로케일(locale) 을 알아낸다.

스트림 객체의 로케일을 리턴한다.

###  인자


없다.




###  리턴값


스트림의 로케일 객체를 리턴한다.

###  실행 예제

```cpp-formatted
// 로케일 이름을 출력한다.
#include <iostream>
#include <locale>
using namespace std;

int main() {
  locale current = cout.getloc();
  cout << current.name() << endl;  // 현재 로케일 이름을 출력한다.
  return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F161A3C3B4E4E83B81B0A87)



###  참고 자료

*  [ios_base::imbue](http://itguru.tistory.com/158)  :  로케일을 설정한다.