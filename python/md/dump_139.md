----------------
title : C 언어 레퍼런스 - rand 함수
cat_title :  rand
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ rand

```info
#include <stdlib.h> // C++ 에서는 <cstdlib>

int rand ( void );

```

난수를 생성한다.
`0` 부터 `RAND_MAX` 범위의 정수들로 의사 난수(pseudo-random) 를 생성한다. 의사 난수란 실질적인 난수가 아니라 컴퓨터 상에서 일련의 복잡한 연산에 의해 만들어지는 난수 같아 보이는 수들을 말한다 0 부터 `RAND_MAX` 범위의 정수들로 의사 난수(pseudo-random) 를 생성한다. 의사 난수란 실질적인 난수가 아니라 컴퓨터 상에서 일련의 복잡한 연산에 의해 만들어지는 난수 같아 보이는 수들을 말한다.

`rand` 함수를 실행할 때 마다 특정한 알고리즘에 의해 연관성이 없어 보이는 수들이 생성된다. 이 알고리즘은 난순열을 생성하기 위해 초기값이 필요한데, `srand` 함수를 통해 이 초기값을 설정할 수 있다.



###  인자


없음



###  리턴값




`0` 과 `RAND_MAX` 사이의 정 0 과 `RAND_MAX` 사이의 정수



###  실행 예제


```cpp
/*

숫자 맞추기
이 예제는
http://www.cplusplus.com/reference/clibrary/cstdlib/rand/
에서 가져왔습니다

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int iSecret, iGuess;

    /* initialize random seed: */
    srand ( time(NULL) );

    /* generate secret number: */
    iSecret = rand() % 10 + 1;

    do {
        printf ("Guess the number (1 to 10): ");
        scanf ("%d",&iGuess);
        if (iSecret<iGuess) puts ("The secret number is lower");
        else if (iSecret>iGuess) puts ("The secret number is higher");
    } while (iSecret!=iGuess);

    puts ("Congratulations!");
    return 0;
}

```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F206A0F394DC2B23C3487C4)


위 예제에서 난수의 초기값으로 `time()` 함수의 리턴값 (1970 년 부터 현재 까지 지난 초 수) 를 사용하였다. 대부분의 경우 이 방법을 사용한다.



###  연관된 함수

*  [srand](http://itguru.tistory.com/140)  :  난순열의 초기값을 설정한다.







