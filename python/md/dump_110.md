


```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`clock`



```info
#include <time.h> // C++ 에서는 <ctime>

clock_t clock ( void );
```


프로그램 실행 후 몇 클록이 지나갔는지 알려준다.
우리는 `CLOCKS_PER_SEC` 매크로를 통해 1 초에 몇 클록인지 알 수 있다. 참고로 여기서의 클록은 `CPU` 의 클록 수 와는 의미가 다르다.

참고로 이 함수가 '프로그램의 시작' 으로 잡는 위치는 플랫폼 마다 다를 수 있다. 따라서 특정 프로그램의 실행 시간을 알기 위해서는 프로그램 시작시 `clock` 함수를 호출한 값과 프로그램 종료시 `clock` 함수를 한 번 더 호출하여서 그 값을 비교해야만 한다.



###  인자


없다




###  리턴값




프로그램이 시작했을 때 부터 몇 클록이 지나갔는지 그 값을 리턴한다.
만일 그 값을 읽는데 실패하였다면 -1 을 리턴한다.

참고로 `clock_t` 는 `<time.h>` (혹은 `<ctime> )` 에 정의되어 있으며 통상적으로 `long` 형 이다.



###  실행 예제




```cpp
/*

10 초를 카운트 다운 한다.

이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/clock/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

void wait ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

int main ()
{
    int n;
    printf ("Starting countdown...\n");
    for (n=10; n>0; n--)
    {
        printf ("%d\n",n);
        wait (1);
    }
    printf ("FIRE!!!\n");
    return 0;
}

```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F1445DF5A4D15652D1B7F62)




###  연관된 함수


*  [time](http://itguru.tistory.com/114)  :  현재 시각을 알아온다.



*  [difftime](http://itguru.tistory.com/111)  :  두 개 시각의 차이를 구한다.







