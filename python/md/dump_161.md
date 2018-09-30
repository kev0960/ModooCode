----------------
title : C++ 레퍼런스 - ios_base::iword
cat_title :  ios_base::iword
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios_base::iword

```info
long& iword (int idx);
```


내부 확장 가능한 배열의 정수 원소의 레퍼런스를 얻는다.
  내부 확장 가능 배열(internal `extensible array)` 에서 `long` 형의 `idx` 번째의 원소의 레퍼런스를 얻는다. 만일 `idx` 가 새로운 원소의 번호이고, 내부 확장 가능 배열의 크기 보다 더 큰 값을 가진다면 (즉, 아직 할당 되지 않았다면), 이 함수는 이에 해당하는 만큼 메모리를 확장하고, 새롭게 생성된 원소들의 값을 0 으로 초기화 한다.

`idx` 의 값은 이전에 [xalloc](http://itguru.tistory.com/162)에 의해 리턴된 값이여야만 한다.

  한 번 `iword` 가 리턴한 레퍼런스는 스트림에 다른 연산( `iword` 를 호출하는 것을 포함해서) 이 수행되기 전 까지 사용될 수 있다. 만일 스트림이 다른 작업을 수행한다면, 리턴된 레퍼런스를 사용하지 못할 수 있다.

  내부 확장 가능 배열은 스트림에서 여러 용도(general purpose)로 사용되는 `word` 크기의 원소들을 가진 배열로 데이터를 임시적으로 저장하는데 사용된다.



###  인자




`idx`

  내부 확장 가능 배열의 특정 원소의 인덱스값. 이 값은 이전의 `xalloc` 함수 호출을 통해 얻어진 값이여야 한다.



###  리턴값




  인덱스가 `idx` 인 내부 확장 가능 배열의 원소의 레퍼런스를 리턴한다. 이 때, 그 레퍼런스는 `long` 형의 원소의 레퍼런스 이다. 실패시, 값이 0 인, `long` 형 원소의 레퍼런스가 리턴된다.



###  실행 예제




```cpp
/*

이 예제는
http://msdn.microsoft.com/en-us/library/77z9kz41.aspx
에서 가져왔습니다.

i, j 가 각각 xalloc 을 통해 얻어낸 index 들이고, cout 과 cin 의 내부 확장 가능 배열의 i , j 번째 원소에 각각 11 과 13 을 넣는다.
*/
#include <iostream>
using namespace std;
int main( )
{
    static const int i = ios_base::xalloc();
    static const int j = ios_base::xalloc();

    cout.iword( i ) = 11;
    cin.iword( j ) = 13;

    cout << cout.iword( i ) << endl;
    cout << cin.iword( j ) << endl;

}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F1701413C4EA213713E82A5)




###  연관된 함수

*  [ios_base::](http://itguru.tistory.com/162) [xalloc](http://itguru.tistory.com/162) :  내부 확장 가능 배열의 새로운 인덱스를 리턴한다.
*  [ios_base::pword](http://itguru.tistory.com/163)  :  내부 확장 가능 배열의 포인터의 레퍼런스를 얻는다.
