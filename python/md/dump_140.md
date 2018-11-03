----------------
title : C 언어 레퍼런스 - srand 함수
path : /C Reference/stdlib.h
cat_title :  srand
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ srand

```info
#include <stdlib.h> // C++ 에서는 <cstdlib>

void srand ( unsigned int seed );

```

난수 생성기를 초기화 한다.

**의사 난수(psudo-random) 생성기**의 초기값을 인자로 전달된 값으로 초기화 한다. 이때 의사 난수란 실제 난수는 아니지만 일련의 알고리즘에 의해 생성된 수들로 전혀 규칙성이 없어보이는 수들이다.

`srand` 에 다른 `seed` 값을 전달하게 된다면 `rand` 함수로 부터 생성되는 난순열은 전혀 다를 것이라 생각해보도 무방하다. 하지만 동일한 `seed` 값을 이용한 두 `rand` 함수는 동일한 난순열을 만들어내게 된다.

만일 `seed` 를 1 로 설정한다면 `rand` 함수가 호출되기 전의 맨 처음 초기값으로 설정이 된다.

진짜 난수 같은 수열을 생성해 내고 싶다면 `srand` 는 보통 시간에 관련된 함수로 초기화 하는 것이 좋다. 예를 들어 `<time.h>` (C++ 에서는 `<ctime>`) 에 정의되어 있는 `time` 함수의 경우 매 초당 다른 값을 주기 때문에 매우 좋은 예가 될 수 있다. 실제로 대부분의 경우 `srand` 는 `time(NULL)` 값으로 초기화 하는 것이 대다수 이다.


###  인자

`seed`

난순열을 생성 알고리즘을 위한 초기 정수 값이다.이 `seed` 값을 바탕으로 난순열이 생성된다.



###  리턴값




없음



###  실행 예제




```cpp
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstdlib/srand/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    printf ("First number: %d\n", rand() % 100);
    srand ( time(NULL) );
    printf ("Random number: %d\n", rand() % 100);
    srand ( 1 );
    printf ("Again the first number: %d\n", rand() %100);

    return 0;
}

```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F13223D3B4DC8A03528E793)



###  연관된 함수

*  [rand](http://itguru.tistory.com/139)  :  난수를 생성한다.