----------------
title : C 언어 레퍼런스 - atol 함수
path : /C Reference/stdlib.h
cat_title :  atol
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ atol

```info
#include <stdlib.h> // C++ 에서는 <cstdlib>

long int atol ( const char * str ); // long atol (const char *str) 인 경우도 있음
```


문자열을 `long` 형 정수로 변환한다.
C 형식 문자열을 `long` 형 정수로 변환하여 변환된 값을 리턴한다 C 형식 문자열을 `long` 형 정수로 변환하여 변환된 값을 리턴한다.

이 함수는 C 형식 문자열에서 비-공백 문자가 나오기 전 까지 최대한 많은 공백 문자(' ', '\t', \n') 들을 무시한다. 그 다음에 첫 번째 비-공백 문자부터 최대한 많은 숫자들을 수로 변환한다. 이 때, 숫자의 맨 앞부분에는 `+` 나 `-` 가 올 수 도 있다. 숫자들 다음에 나타나는 문자들은 모두 무시된다. 예를 들면

\n\n-123aaa

이라는 문자열이 있다면 -123 으로 변환된다.
만일 문자열에서 첫 번째로 나타나는 비-공백 문자가 숫자 혹은 `+` 나 `-` 가 아니라면 어떠한 변환도 이루어 지지 않는다. 또한 문자열이 공백 문자로만 이루어져 있어도 변환이 이루어 지지 않는다. 예로

`a123`

의 경우 123 이 있지만 첫번째 비-공백 문자가 `a` 이기 때문에 변환이 이루어지지 않는다. 변환이 이루어 지지 않는 경우 0 이 리턴된다.



###  인자


`str`

정수를 포함하고 있는 C 형식 문자열



###  리턴값




성공적으로 변환하였다면 변환된 `long` 형 정수를 리턴한다.
만일 변환이 실패하였다면 0 이 리턴된다.
변환된 수가 `long` 형으로 표현 가능한 범위를 넘어갔다면 `LONG_MAX` 혹은 `LONG_MIN` 이 리턴된다.



###  실행 예제


```cpp-formatted
/*

문자열로 데이터를 입력 받아서 long int 형으로 변환한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstdlib/atol/
에서 가져왔습니다.


*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  long int li;
  char szInput[256];
  printf("Enter a long number: ");
  gets(szInput);
  li = atol(szInput);
  printf("The value entered is %d. The double is %d.\n", li, li * 2);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F1130654A4D414D3E29BE90)





###  연관된 함수

*  [atoi](http://itguru.tistory.com/131)  :  문자열을 정수로 변환한다.
*  [atof](http://itguru.tistory.com/124)  :  문자열을 `double` 형으로 변환한다.
* strtol  :  문자열을 `long` 형으로 변환한다.