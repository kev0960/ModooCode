----------------
title : C 언어 레퍼런스 - strcpy 함수
cat_title :  strcpy
publish_date : 2010-05-02
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strcpy

```info-format
#include <string.h> // C++ 에서는 <cstring>

char * strcpy ( char * destination, const char * source );
```


문자열을 복사한다.

`source` 가 가리키는 C 형식의 문자열 (널 종료 문자열) 을 `destination` 이 가리키는 곳에 복사한다. 이 때, 널도 포함해서 복사한다.

오버플로우를 방지하기 위해서, `destination` 이 가리키는 배열의 크기는 반드시 `source` 문자열의 크기와 같거나 이보다 커야 한다. 또한, 복사하는 영역이 `source` 와 겹치면 안된다.

참고로 위와 같은 오버플로우 문제를 방지하기 위해 `ISO/IEC TR 24731` 에서 제안된 `strcpy_s` 함수를 이용하면 된다. 이 함수는 마이크로소프트 C 런타임 라이브러리와 일부 C 라이브러리에서 사용 가능하다. 

하지만 `GLibc` 와 같은 라이브러리 에서는 지원되지 않는다. 일각에서는 마이크로소프트 컴파일러가 `strcpy` 나 `strncpy` 함수를 사용시 경고 메세지를 뜨게 하는 이유가, 자사의 플랫폼에만 묶어두기 위한 계획이라고도 한다. 이 `strcpy_s` 함수는 만일 `source` 의 크기가 `destination` 보다 크다면 복사를 수행하지 않고 0 이 아닌 값을 리턴하며, (호출자가 리턴값을 무시하였을 때를 대비하여) 버퍼를 비워버린다.



###  간단한 `strcpy` 함수의 구현




별다른 변수들을 사용하지 않고도 다음과 같이 간단하게 구현할 수 있다.

```cpp-formatted
/* 이 소스는 http://www.jbox.dk/sanos/source/lib/string.c.html#:38  에서
 * 가져옴*/
char *strcpy(char *dst, const char *src) {
  char *cp = dst;
  while (*cp++ = *src++)
    ;
  return dst;
}
```




###  인자




`destination`

문자열이 복사될 곳을 가리키는 포인터

`source`

복사할 문자열을 보관하고 있는 포인터



###  리턴값




`destination` 이 리턴된다.



###  실행 예제




```cpp-formatted
/*

str2 에 str1 의 내용, 즉 "Sample string" 을 복사하고, str3 에는 "copy
successful" 을 복사한다. 이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strcpy/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "Sample string";
  char str2[40];
  char str3[40];
  strcpy(str2, str1);
  strcpy(str3, "copy successful");
  printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F1344D41A4BDD61EA254EAF)



###  참고 자료

*  [strncpy](http://itguru.tistory.com/80) : 문자열에서 일부 문자들을 복사한다.
*  [memcpy](http://itguru.tistory.com/77)  :  메모리 블록을 복사한다.
*  [memmove](http://itguru.tistory.com/78) :  메모리 블록을 옮긴다.
*  [memchr](http://itguru.tistory.com/92)  :  메모리 블록에 문자를 위치시킨다.
*  [memcmp](http://itguru.tistory.com/84)  :  두 개의 메모리 블록을 비교한다.
* `memset`  :  메모리 블록을 채운다.