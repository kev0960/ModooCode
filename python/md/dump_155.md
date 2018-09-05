----------------
title : C++ 레퍼런스 - ios_base::setf 함수
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

ios_base::setf




```cpp
fmtflags setf ( fmtflags fmtfl );
fmtflags setf ( fmtflags fmtfl, fmtflags mask );
```


특정 서식 플래그를 설정한다.
  첫번째 형태의 함수의 경우 스트림의 서식 플래그(format `flag)` 의 비트들 중, `fmtfl` 에 해당하는 것만 설정(set)하고 나머지는 그대로 놔둔다. 이는 마치 `fmtfl | flags()` 를 한 것과 동일하다. ( [flags](http://itguru.tistory.com/153)`` 함수는 현재 자신의 서식 플래그를 리턴하므로, 이와 `OR` 연산하는 것과 동일하다)

  두번째 형태의 함수의 경우 서식 플래그 중 `fmtfl` 과 `mask` 둘 다 설정되니 비트들을 설정하고, 마스크 에는 설정되어 있지만 `fmftl` 에 설정되어 있지 않은 비트는 초기화(clear) 해버린다. 참고로 마스크에 대한 설명은 아래를 참조.두 형태의 함수 모두 함수 호출 이전 상태의 서식 플래그를 리턴한다.

서식 플래그는 스트림에서 데이터를 어떻게 해석하고, 또 어떻게 출력하는지 결정하는데 중요한 역할을 한다. [ios_base::fmtflags](http://itguru.tistory.com/154)`` 를 보면 함수의 인자로 어떠한 값들이 가능한지 알 수 잇다.

보통 첫번째 형태의 `setf` 함수의 경우, 단항 서식 플래그(독립적으로 기능을 수행하는 것)들, `boolalpha, showbase, showpoint, showpos, skipws, unitbuf, uppercase` 를 설정하기 위해 사용되고, 이들 역시 `unsetf` 에서도 사용된다. 반면에 선택적인 플래그들(반드시 하나만 켜져 있어야 한다) 을 조작하기 위해서는 아래와 같은 비트 마스크와 플래그 값들을 이용한다.

`fmtfl`
서식 플래그 값
`mask`
필드 비트마스크
`left``,``right``,``internal``adjustfield``dec``,``oct``,``hex``basefield``scientific``,``fixed``floatfield`

  각각이 무엇인지 자세한 설명은 [ios_base::fmtflags](http://itguru.tistory.com/154)`` 를 참조하면 된다.

또한 인자를 가지는 조작자인 `setiosflags` 역시 비슷한 작업을 한다.



###  인자




`fmtfl`

  설정될 서식 플래그. 만일 두번재 형태의 함수가 사용된다면 스트림 서식 플래그에서 `fmtfl` 과 `mask` 에서 모두 설정된 비트만 켜지게 된다. 또한 `mask` 에서 켜졌지만 `fmtfl` 에서 설정 안된 비트는 꺼진다.

`mask`
    수정할 플래그를 포함하고 있는 비트마스크




###  리턴값




  함수 호출 이전 상태의 서식 플래그



###  실행 예제




```cpp
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/setf/
에서 가져왔습니다

*/
#include <iostream>
using namespace std;

int main ()
{
    cout.setf ( ios::hex, ios::basefield );       // hex 를 설정한다.
    cout.setf ( ios::showbase );                  // showbase 를 설정
    cout << 100 << endl;
    cout.setf ( 0, ios::showbase );               // showbase 를 끈다.
    cout << 100 << endl;
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F1743DC364E4D51B505E4D8)



###  연관된 것들






*  [ios_base::flags](http://itguru.tistory.com/153)  :  서식 플래그를 설정하거나 얻는다.

*  [ios_base::unsetf](http://itguru.tistory.com/156)  :  서식 플래그를 초기화한다.

*  [ios_base::fmtflags](http://itguru.tistory.com/154)  :  스트림 서식 플래그 타입

* `setiosflags` :  서식 플래그를 설정한다.

* resetiosflags  :  서식  플래그를 재설정 한다.





