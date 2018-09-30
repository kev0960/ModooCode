----------------
title : C++ 레퍼런스 - ios_base::precision 함수
cat_title :  ios_base::precision
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/iostream/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ ios_base::precision

```cpp
streamsize precision ( ) const;
streamsize precision ( streamsize prec );
```


부동 소수점 정밀도를 설정하거나, 알아온다.
첫 번째 형태의 함수는 현재 스트림의 부동 소수점 정밀도(floating `point precision)` 값을 리턴한다.
두 번째 형태의 함수는 정밀도를 새로운 값으로 설정한다.

  부동 소수점 정밀도는 부동 소수점 데이터(실수 데이터)를 출력시 최대 얼마의 정밀도로 나타낼 것인지를 의미한다. 어떠한 방식으로 해석될지는 [floatfield 서식 플래그](http://itguru.tistory.com/154)에 의해 결정되는데 이는 과학적 표기법(scientific) 과 고정 소수점 표기(fixed) 그리고 기본 표기(default `notation)` 이 있다. 기본 표기는 `scientific` 과 `fixed` 모두 설정 되어 있지 않은 경우를 의미한다.

  기본 표기(default)시, 정밀도는 소수점 앞 뒤에 나타나는 숫자의 최대 개수를 의미한다. 여기서최대자리수 임에 주의해야 하는데, 다시 말해 표시되는 숫자가 정밀도 보다 적다면 0 을 붙여서 정밀도 개수로 맞추어 주지 않는다는 것이다. `fixed` 나 `scientific` 이 설정되어 있다면 정밀도의 의미가 달라진다. 여기서 정밀도는 소수점 '뒤' 에 존재하는 숫자의 개수를 의미한다. 또한 정밀도가 설정되어 있는 `precision` 보다 적다면 뒤에 0 을 붙여서 그 수를 맞추어 주게 된다. 이 때 소수점 앞에 있는 숫자의 개수는 무시한다.

   정밀도는 인자를 가지는 조작자인 `setprecision` 을 통해서도 변경할 수 있다.



###  인자



`prec`

  새로운 부동 소수점 정밀도 값. 이는 `streamsize` 타입의 정수형이다.



###  리턴값




함수 호출 이전의 `precision` 값이다.



###  실행 예제




```cpp
/*

이 예제는
http://www.cplusplus.com/reference/iostream/ios_base/precision/
에서 가져왔습니다.

*/
#include <iostream>
using namespace std;

int main ()
{
    double f = 3.14159;
    cout.setf(0,ios::floatfield);            // floatfield 설정 안됨
    cout.precision(5);
    cout << f << endl;
    cout.precision(10);
    cout << f << endl;
    cout.setf(ios::fixed,ios::floatfield);   // floatfield 를 fixed 로 설정
    cout << f << endl;
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F1318CA544E4E091A309789)





###  연관된 것들




* setprecision  :  정밀도를 설정한다.
*  [ios_base::width](http://itguru.tistory.com/152):  필드 너비(field `width)` 를 설정한다.
*  [ios_base::setf](http://itguru.tistory.com/155):  특정 서식 플래그를 설정한다.
