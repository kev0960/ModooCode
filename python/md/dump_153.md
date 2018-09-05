----------------
title : C++ 레퍼런스 - ios_base::flags 함수
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

ios_base::flags




```cpp
fmtflags flags ( ) const;
fmtflags flags ( fmtflags fmtfl );
```


서식 플래그를 얻어오거나 설정한다.
첫번째 형태의 경우, 현재 스트림의 서식 플래그가 어떻게 설정되어 있는지 불러온다.
두번째 형태의 경우 스트림의 서식 플래그를 새롭게 설정하고, 원래 설정되어있던 것을 리턴한다.

서식 플래그는 입출력시 데이터가 어떻게 해석되고, 또 어떻게 출력되는지 결정해준다. `fmtfl` 로 무슨 값이 올 수 있는지 알려면 [ios_base::fmtflags](http://itguru.tistory.com/154)`` 를 참조하여라

`fmtfl` 에 서식 플래그를 전달할 때, 기존의 스트림의 서식 플래그의 내용은 모두 지워지고, 전달된 `fmtfl` 의 내용으로 덮어 씌워지게 된다. 다른 서식 플래그를 바꾸지 않고, 한 개의 서식 플래그 만 바꾸기 위해서는 [setf](http://itguru.tistory.com/155)`` 함수나 [unsetf](http://itguru.tistory.com/156)`` 함수를 이용하면 된다.



###  인자





`fmtfl`

  스트림에서 사용되는 서식 플래그. 이 값은 [ios_base::fmtflags](http://itguru.tistory.com/154)형이다.




###  리턴값



함수 호출 직전의 서식 플래그






###  실행 예제



```cpp
/*

cout 의 서식 플래그로 right, hex, showbase 를 전달한다.
이를 통해 100 은 오른쪽에 10 크기로 맞추어서, 16 진수로, 무슨 진법으로(0x) 표시하였는지 명시되어 출력된다.
이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/flags/
에서 가져왔습니다

*/
#include <iostream>
using namespace std;

int main ()
{
    cout.flags ( ios::right | ios::hex | ios::showbase );
    cout.width (10);
    cout << 100;
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F110B09414E4D3E30316DF2)





###  연관된 것들




*  [ios_base::setf](http://itguru.tistory.com/155)  :  특정 서식 플래그를 설정한다.

*  [ios_base::unsetf](http://itguru.tistory.com/156)  :  특정 서식 플래그를 초기화 한다.

*  [ios_base::fmtflags](http://itguru.tistory.com/154)  :  스트림 서식 플래그의 타입

* setiosflags  :  서식 플래그를 설정한다.







