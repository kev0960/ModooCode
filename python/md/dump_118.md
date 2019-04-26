----------------
title : C 언어 레퍼런스 - ctime 함수
cat_title :  ctime
publish_date : 2010-12-29
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ ctime

```info-format
#include <time.h> // C++ 에서는 <ctime>

char * ctime ( const time_t * timer );
```


`time_t` 값을 문자열로 바꾼다.
`timer` 가 가리키는 [ time_t](http://itguru.tistory.com/113)형 변수를 읽어들여서, 그 값을 해석하여 지역 시간에 맞추어 아래와 같은 형식으로 문자열로 바꾼다.

`Www Mmm dd` hh:mm:ss `yyyy`

`Www` 는 요일, `Mmm` 은 월 이름, `dd` 는 몇일인지, hh:mm:ss 는 현재 시간, `yyyy` 는 현재 년도를 말한다.이 때 문자열 끝에는 자동으로 \n 과 `NULL` 문자가 들어가게 된다.

참고로 이 함수는 `asctime(localtime(timer))` 와 동일하다.



###  인자




`timer`

`time_t` 형 변수를 가리키는 포인터



###  리턴값




 [time_t](http://itguru.tistory.com/113)값을 해석해서 만든 문자열이 리턴된다. 이 때 이 문자열은 정적으로 할당되었으며 `ctime` 함수와 `asctime` 함수가 동시에 사용한다. 따라서 이들 함수를 호출하게 되면 이 문자열에 들어가 있던 내용에 덮어 씌우게 된다. 따라서 이들 함수가 호출한 문자열 내용을 영구적으로 보관하려면 다른 메모리 공간에 보관해야 한다.



###  실행 예제


```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/ctime/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;

  time(&rawtime);
  printf("The current local time is: %s", ctime(&rawtime));

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F120E3A574D1AF68D20F071)




###  참고 자료


*  [asctime](http://itguru.tistory.com/116)  :  `tm` 구조체를 문자열로 변환한다.
*  [gmtime](http://itguru.tistory.com/119)  :  `time_t` 값을 `tm` 구조체로 변환하되, `UTC` 시간으로 한다.
*  [localtime](http://itguru.tistory.com/120)  :  `time_t` 값을 `tm` 구조체로 변환하되 지역 시간으로 한다.
*  [time](http://itguru.tistory.com/114)  :  현재 시간을 알아온다.