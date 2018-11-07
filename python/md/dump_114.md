----------------
title : C 언어 레퍼런스 - time 함수
cat_title :  time
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ time

```info
#include <time.h> // C++ 에서는 <ctime>

time_t time ( time_t * timer );
```


현재 시간을 구한다.

현재 시간을 [time_t 형](http://itguru.tistory.com/113)으로 구한다. (즉, 1970년 1 월 1 일 0 시 (UTC) 부터 현재 까지 흐른 초 수를 구한다고 보면 된다)

이 때 이 함수는 구한 [time_t](http://itguru.tistory.com/113) 형 값을 리턴하기도 하고, 인자로 받은 `timer` 가 가리키는 변수를 구한 `time_t` 형 값으로 설정한다.



###  인자




`timer`

[time_t](http://itguru.tistory.com/113) 형 변수를 가리키는 포인터로, 이 곳에 구해진 `time_t` 값이 전달된다. 물론 이 함수는 동일한 값을 친절하게 리턴도 해주기 때문에 `timer` 에 `NULL` 을 전달하고 리턴값을 받아도 된다.




###  리턴값




 [time_t](http://itguru.tistory.com/113) 형으로 구한 현재 시간을 리턴한다. 만일 그 값을 알아 올 수 없을 경우 -1 을 리턴한다.



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/time/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

int main() {
  time_t seconds;

  seconds = time(NULL);
  printf("%ld hours since January 1, 1970 \n", seconds / 3600);

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F133D89414D16827029ED76)




###  연관된 함수


* [asctime](http://itguru.tistory.com/116)  :  `tm` 구조체를 문자열로 바꾼다.
*  [gmtime](http://itguru.tistory.com/119)  :  `time_t` 를 `UTC` 시간에 따라 `tm` 구조체로 바꾼다.
*  [localtime](http://itguru.tistory.com/120)  : `time_t` 를 지역 시간에 따라 `tm` 구조체로 바꾼다.