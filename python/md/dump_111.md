

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


difftime
```info
#include <time.h> // C++ 에서는 <ctime>

double difftime ( time_t time2, time_t time1 );
```


두 개 시각의 차이를 구한다.
time1 과 time2 가 몇 초 차이나는지 계산한다. 

###  인자
### 
time2

  time_t 형 변수로 나중 시각을 나타낸다. 

time1

  time_t 형 변수로 이전 시각을 나타낸다. 

###  리턴값
### 
time2 와 time1 가 몇 초 차이 나는지를 double 형으로 리턴한다. 

###  실행 예제### 

```cpp
/* 

이름을 쓰는데 얼마나 걸리는지 알아온다.
이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/difftime/
에서 가져왔습니다.

*/
#include <stdio.h>
#include <time.h>

int main ()
{
    time_t start,end;
    char szInput [256];
    double dif;

    time (&start);
    printf ("Please, enter your name: ");
    gets (szInput);
    time (&end);
    dif = difftime (end,start);
    printf ("Hi %s.\n", szInput);
    printf ("It took you %.2lf seconds to type your name.\n", dif );

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F177A173A4D15F9B43D6540)

###  연관된 함수
### * asctime :  tm 구조체를 문자열로 변환한다.    
gmtime  :  time_t 를 tm 으로 바꾸되 UTC 형식 시간으로 바꾼다. 
localtime  :  time_t 를 tm 으로 바꾸되 지역 시간으로 바꾼다. time  :  현재 시각을 구한다.

공감sns신고저작자표시'C Reference > time.h (ctime)' 카테고리의 다른 글C 언어 레퍼런스 - mktime 함수(0)
2010.12.26C 언어 레퍼런스 - time_t 형(1)
2010.12.25C 언어 레퍼런스 - difftime 함수(0)
2010.12.25C 언어 레퍼런스 - clock 함수(2)
2010.12.25C 언어 레퍼런스 - struct tm ( tm 구조체 )(0)
2010.12.25C 언어 레퍼런스 - time.h 헤더파일(0)
2010.12.25

