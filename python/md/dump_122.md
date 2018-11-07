----------------
title : C 언어 레퍼런스 - strftime 함수
cat_title :  strftime
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strftime

```info
#include <time.h> // C++ 에서는 <ctime>

size_t strftime ( char * ptr, size_t maxsize, const char * format, const struct tm * timeptr );
```


시간을 사용자가 원하는 형식에 맞추어 출력한다.
`format` 에 들어있는 형식에 맞추어서 `timeptr` 이 가리키는 `tm` 구조체의 값을 해석하여 현재 시간을 출력한다. 이 때, 출력되는 문자열의 최대 길이는 `maxsize` 로 한다.



###  인자




`ptr`

C 형식 문자열이 복사되는 배열을 가리키는 포인 C 형식 문자열이 복사되는 배열을 가리키는 포인터

`maxsize`

`ptr` 에 복사되는 문자열의 최대 길이

`format`

C 형식 문자열로 특정한 형식 지정자(format specifier) 들을 포함하고 있다. 이는 `printf` 에서 `%d` 나 `%c` 와 같이 사용하는 것과 유사하다. 다만 `printf` 는 인자로 지정한 변수들의 값을 출력하지만 `strftime` 함수는 인자로 지정한 `timeptr` 의 값을 해석하여 형식 지정자에 따라 문자열을 출력하게 된다. `printf` 와 같이 모든 형식 지정자의 앞에는 `%` 를 붙이면 된다.

|형식 지정자| 형식 지정자를 대체하여 들어가는 값|예시|
|---------|---------------------------|----|
|`%a`|요일 이름을 약자로 표기|`Thu`|
|`%A`|요일 이름을 완전하게 표기|`Thursday`|
|`%b`|월 이름을 약자로 표기|`Aug`|
|`%B`|월 이름을 완전하게 표기|`August`|
|`%c`|날짜와 시간 표시 형식|`Thu Aug 23 14:55:02 2001`|
|`%d`|몇 일인지 (01-31)|`23`|
|`%H`|24 시간 형식으로 시간을 표기 (00-23)|`14`|
|`%I`|12 시간 형식으로 시간을 표기 (01-12)|`02`|
|`%j`|1 년 중 몇 번째 일인지 (001-366)|`235`|
|`%m`|월을 숫자로 표시 (01-12)|`08`|
|`%M`|몇 분인지 (00-59)|`55`|
|`%p`|`AM` 또는 `PM` 을 나타낸다.|`PM`|
|`%S`|몇 초 인지(00-61)|`02`|
|`%U`|그 해의 첫번째 일요일을 첫 번째 주의 시작이라고 할 때 몇 번째 주인지 표시한다(00-53)|`33`|
|`%w`|요일을 숫자로 표시한다. (일요일은 0, 0 부터 6까지)|`4`|
|`%W`|그 해의 첫번째 월요일을 첫 번째 주의 시작이라고 할 때 몇 번째 주인지 표시한다 (00-53)|`34`|
|`%x`|날짜 표시|`08/23/01`|
|`%X`|시간 표시|`14:55:02`|
|`%y`|Y 년도를 끝 두 자리만 표시 `01`|
|`%Y`|년도 표시|`2001`|
|`%Z`|시간대(Timezone) 을 표시|`CDT`|
|`%%`|`%` 기호를 표시|`%`|

`timeptr`

`tm` 구조체를 가리키는 포인터




###  리턴값


만일 만들어지는 문자열의 길이가 종료 널 문자를 포함하여 `maxsize` 보다 작다면 `ptr` 에 복사된 문자의 수가 리턴되고 (이 때에는 종료 널 문자를 포함하지 않는다), 보다 크다면 0 이 리턴된다. 이 때 `ptr` 에 복사되는 문자열의 내용은 알 수 없다.




###  이식성


C++ 에서의 `strftime` 함수는 1990 년의 `ISO-C` 표준에서와 동일하다. C 컴파일러는 위에 나타나 있는 형식 지정자 말고도 부가적인 형식 지정자를 더 가질 수 있는데 위의 C 표준에서는 나타나 있지 않다.



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/ctime/strftime/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm* timeinfo;
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "Now it's %I:%M%p.", timeinfo);
  puts(buffer);

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F111039584D246E6A33FF6E)

###  연관된 함수

* [asctime](http://itguru.tistory.com/116)  :  `tm` 구조체를 문자열로 변환한다.
* [ctime](http://itguru.tistory.com/118)  :  `time_t` 값을 토대로 `asctime` 함수와 동일한 작업을 한다.