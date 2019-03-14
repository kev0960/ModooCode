----------------
title : C++ 레퍼런스 - ios_base::register_callback 함수
cat_title :  ios_base::register_callback
publish_date : 2011-08-20
ref_title : ios_base::register_callback, register_callback
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios_base::register_callback

```cpp-formatted
void register_callback(event_callback fn, int index);
```


이벤트 콜백 함수를 등록한다.

인자 `fn` 으로 전달된 함수를 등록(register)하고 특정 이벤트가 발생시 이 함수가 자동으로 호출되게 된다. `index` 는 함수 호출 시 전달되는 인자이다. 만일 한 개 이상의 콜백 함수가 등록 되어 있다면 이들은 등록된 순서 반대로 호출되게 된다. (즉 나중에 등록된 것이 먼저 호출됨)

이 때 콜백 함수는 `event_callback` 타입이여야만 하는데 이는

```cpp-formatted
(*fn)(ev, *this, index)
```


위와 같다. 이 때 `index` 는 이 함수를 등록시 사용되는 인자이고, `*this` 는 호출한 객체를 가리키는 포인터, 그리고 `ev` 는 객체의 `enum` 형의 멤버로, 어떠한 이벤트가 발생되었는지 알려주게 된다. 이 값은 아래의 값들 중 하나일 수 있다.

|값|발생한 이벤트|
|---|--------|
|`copyfmt_event`|`ios::copyfmt` 를 호출하였을 때 (정확히 말하면, 서식 플래그가 복사가 되었지만 예외 마스크는 복사가 되기 직전일 때)|
|`erase_event`|소멸자 호출시(또한 `ios::copyfmt` 시작시에도 호출된다)|
|`imbue_event`|[imbue](http://itguru.tistory.com/158) 함수 종료 바로 직전에|

모든 등록된 함수들은 위의 상황 발생 시 호출된다. 이 때 함수 자체에서 어떠한 이벤트가 발생하였는지는 `ev` 인자를 통해 알아낼 수 있다


###  인자

`fn`

호출하고 싶은 함수를 가리키는 포인터. 이 때 `event_callback` 타입은 아래와 같다.

```cpp-formatted
typedef void (*event_callback)(event ev, ios_base& ios, int index);
```


`index`

  콜백 함수 호출시 인자로 전달되는 정수값이다. 이는 콜백 함수에서 사용될 인자들의 값들을 지정하는데 사용할 수 있다.



###  리턴값




없다.



###  실행 예제




```cpp-formatted
/*

testfn 이 imbue 함수 호출시와 ostream 객체 소멸시 두 번 호출된다
이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/register_callback/
에서 가져왔습니다.

*/
#include <fstream>
#include <iostream>
using namespace std;

void testfn(ios_base::event ev, ios_base& iosobj, int index) {
  switch (ev) {
    case ios_base::copyfmt_event:
      cout << "copyfmt_event\n";
      break;
    case ios_base::imbue_event:
      cout << "imbue_event\n";
      break;
    case ios_base::erase_event:
      cout << "erase_event\n";
      break;
  }
  cout << "인자로 전달된 인덱스" << index << endl;
}

int main() {
  ofstream filestr;
  filestr.register_callback(testfn, 0);
  filestr.imbue(cout.getloc());
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F150F314E4E4E7FA61FBD71)





###  연관된 것들

*  [ios_base::imbue](http://itguru.tistory.com/158) :  로케일(locale) 을 설정한다.
* `ios::copyfmt`  :  서식 정보를 복사한다.
* `ios_base::event`  :  이벤트를 나타내기 위한 타입