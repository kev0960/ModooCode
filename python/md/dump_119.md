----------------
title : C 언어 레퍼런스 - gmtime 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ gmtime

```info
#include <time.h> // C++ 에서는 <ctime>

struct tm * gmtime ( const time_t * timer );
```


 [time_t](http://itguru.tistory.com/113)`` 형 값을 입력 받아서 `UTC` 형식 시간에 따른 `tm` 구조체를 만들어서 리턴한다.
`timer` 가 가리키는 [time_t](http://itguru.tistory.com/113)`` 형 변수의 값을 받아 그 값을 토대로 [ tm 구조체](http://itguru.tistory.com/109)의 멤버들을 초기화 한다.



###  인자


`timer`

`time_t` 형 변수를 가리키는 포인터



###  리턴값




  인자로 받은 [time_t](http://itguru.tistory.com/113)`` 형 변수의 값을 토대로 멤버가 초기화 된 [tm 구조체](http://itguru.tistory.com/109)`` 변수를 가리키는 포인터가 리턴된다. 이 때, 이 구조체 변수는 정적으로 할당된 변수로 `gmtime` 함수와 `localtime` 함수 모두 공통으로 사용한다. 따라서 이들 함수를 호출하게 되면 구조체 변수의 내용이 덮어 씌워지기 때문에 리턴된 구조체 변수를 이용하기 위해서는 동일한 `tm` 구조체 변수에 복사해 넣는 것이 중요하다.



###  실행 예제


```cpp
/*

세계 몇몇 도시의 시각을 보여준다.
이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/gmtime/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

#define MST (-7)
#define UTC (0)
#define CCT (+8)
#define GMT (+9)

int main ()
{
    time_t rawtime;
    struct tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );

    puts ("Current time around the World:");
    printf ("Phoenix, AZ (U.S.) :  %2d:%02d\n", (ptm->tm_hour+MST)%24, ptm->tm_min);
    printf ("Reykjavik (Iceland) : %2d:%02d\n", (ptm->tm_hour+UTC)%24, ptm->tm_min);
    printf ("Beijing (China) :     %2d:%02d\n", (ptm->tm_hour+CCT)%24, ptm->tm_min);
    printf ("Seoul (Korea) :       %2d:%02d\n", (ptm->tm_hour+GMT)%24, ptm->tm_min);

    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F13155B484D1B14B32FA168)




###  연관된 함수


*  [asctime](http://itguru.tistory.com/116)  :  `tm` 구조체를 문자열로 변환한다.
*  [ctime](http://itguru.tistory.com/118)  :  `time_t` 값을 토대로 `asctime` 함수와 동일한 작업을 한다.
*  [localtime](http://itguru.tistory.com/120)  :  `time_t` 값을 토대로 `tm` 구조체를 지역 시간으로 설정한다.
* [mktime](http://itguru.tistory.com/112)  :  `tm` 구조체 내용을 토대로 `time_t` 형 값을 계산한다.
*  [time](http://itguru.tistory.com/114)  :  현재 시간을 구한다.
