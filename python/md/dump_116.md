

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


asctime


```info
#include <time.h> // C++ 에서는 <ctime>

char * asctime ( const struct tm * timeptr );
```


tm 구조체를 문자열로 바꾼다.

timeptr 이 가리키는 tm 구조체를 읽어들여서 아래와 같은 형식으로 문자열을 만들어서 출력한다. 

Www Mmm dd hh:mm:ss yyyy

이 때 Www 는 요일 이름, Mmm 은 월 이름, dd 는 몇 일인지, 그리고 hh:mm:ss 는 현재 시간, yyyy 는 년도를 말한다. 예를 들면

Sun Dec 25 09:00:12 2010

과 같은 형식의 출력이 가능하다. 이 때, 리턴되는 문자열은 자동으로 끝에 \n 과 널 종료 문자열이 포함되어 있다. 

###  인자
### 
timeptr

tm 구조체를 가리키는 포인터 이다. 이 구조체에 들어있는 값을 토대로 문자열이 생성된다.

###  리턴값
### 
timeptr 을 읽어서 위에서 말한 형식으로 만은 C 형식 문자열을 리턴한다. 이 때, 이 문자열은 정적으로 할당된 메모리 공간을 차지하고 있는데 ctime 과 asctime 함수가 같이 사용하고 있다. 따라서 이들 함수를 호출할 때 마다 이 문자열에 있는 내용이 덮어쓰기 되므로, 리턴된 문자열을 보관하기 위해서는 사용자가 직접 메모리 공간을 할당하여서 그 내용을 복사해 넣어야만 한다. 

###  실행 예제
### 
```cpp
/* 

이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/asctime/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

int main ()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "The current date/time is: %s", asctime (timeinfo) );

    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F131466354D168E052284C6)


###  연관된 함수
### * ctime  :  time_t 를 가지고 asctime 과 동일한 작업을 한다.gmtime  :  time_t 변수를 UTC 시간의 tm 구조체로 바꾼다.localtime  :  time_t 변수를 지역 시간의 tm 구조체로 바꾼다. 
time  :  현재 시간을 구한다.

공감sns신고저작자표시'C Reference > time.h (ctime)' 카테고리의 다른 글C 언어 레퍼런스 - gmtime 함수(0)
2010.12.29C 언어 레퍼런스 - ctime 함수(0)
2010.12.29C 언어 레퍼런스 - asctime 함수(0)
2010.12.26C 언어 레퍼런스 - time 함수(2)
2010.12.26C 언어 레퍼런스 - mktime 함수(0)
2010.12.26C 언어 레퍼런스 - time_t 형(1)
2010.12.25

