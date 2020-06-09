----------------
title : C 언어 레퍼런스 - localtime 함수
cat_title :  localtime
publish_date : 2010-12-30
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ localtime

```info-format
#include <time.h> // C++ 에서는 <ctime>

struct tm * localtime ( const time_t * timer );
```


 [time_t](http://itguru.tistory.com/113)값을 이용하여 지역 시간을 기준으로 [ tm 구조체](http://itguru.tistory.com/109)를 초기화한다.
`timer` 가 가리키는 [time_t](http://itguru.tistory.com/113)형 변수의 값을 이용하여 [tm 구조체](http://itguru.tistory.com/109)의 멤버들을 초기화 한 뒤 이를 가리키는 포인터를 리턴한다.
참고적으로 현재 시간을 구해와야 하는 경우 십중 팔구 이 함수를 사용하게 된다.



###  현재 시각을 구해오는 가장 간단한 방법



```cpp-formatted
time_t rawtime;
struct tm* timeinfo;
time(&rawtime);
timeinfo = localtime(&rawtime);
```


를 통해 `timeinfo` 가 가리키는 구조체에 현재 시각에 관련한 정보가 포함되게 된다. 예를 들어 `timeinfo->tm_hour` 을 하면 현재 몇 시인지 알아내올 수 있다. `tm` 구조체에 관련한 설명은 [여기](http://itguru.tistory.com/109)를 참조하여라.



###  인자




`timer`

 [time_t](http://itguru.tistory.com/113)형 변수를 가리키는 포인터



###  리턴값




멤버들이 초기화된 [tm 구조체](http://itguru.tistory.com/109)를 가리키는 포인터가 리턴된다.

이 때 이 `tm` 구조체는 정적으로 할당된 메모리에 자리하고 있는데, `gmtime` 함수와 `localtime` 함수가 공유하고 있는 공간이다. 따라서 이들 함수들을 호출하게 되면 이 구조체에 쓰여져 있던 내용이 덮어 씌워지게 된다. 만일 이 함수가 리턴한 `tm` 구조체를 사용할 일이 있으면 다른 구조체에 복사해 놓는 것이 좋다.



###  실행 예제




```cpp-formatted
/*

현재 시각을 출력한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/localtime/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("Current local time and date: %s", asctime(timeinfo));

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F121528504D1C9BC50A04E3)




###  참고 자료

* [asctime](http://itguru.tistory.com/116)  :  `tm` 구조체를 문자열로 변환한다.
* [ctime](http://itguru.tistory.com/118)  :  `time_t` 값을 토대로 `asctime` 함수와 동일한 작업을 한다.
*  [gmtime](http://itguru.tistory.com/119): `time_t` 값을 토대로 `UTC` 시간에 맞추어 `tm` 구조체를 초기화한다.
*  [mktime](http://itguru.tistory.com/112)  :  `tm` 구조체 내용을 토대로 `time_t` 형 값을 계산한다.
*  [time](http://itguru.tistory.com/114)  :  현재 시간을 구한다.