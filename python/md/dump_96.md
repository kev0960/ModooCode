----------------
title : C 언어 레퍼런스 - strrchr 함수
cat_title :  strrchr
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strrchr



```info
#include <string.h> // C++ 에서는 <cstring>

const char * strrchr ( const char * str, int character );
      char * strrchr (       char * str, int character );
```


문자열에서 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾는다. 그리고 이를 가리키는 포인터를 리턴한다.
이 때 문자열의 널 종료 문자 역시 C 문자열의 일부분이라 생각한다. 따라서 이 함수는 문자열의 널 종료 문자를 가리키는데 사용될 수 도 있다.

C++ 에서는 함수 오버로딩이 가능하므로 위와 같이 두 개의 원형을 가져도 되지만 C 에서는 불가능 하므로 아래와 같은 하나의 원형만을 가진다 C++ 에서는 함수 오버로딩이 가능하므로 위와 같이 두 개의 원형을 가져도 되지만 C 에서는 불가능 하므로 아래와 같은 하나의 원형만을 가진다.

```info
char * strrchr ( const char *, int );
```




###  인자




`str`

C 문자 C 문자열

`character`

`str` 에서 찾을 문자로 `int` 로 전달되지만 함수 내부적으로는 다시 `char` 로 변환되어 처리된다.



###  리턴값


`str` 에서 찾은 문자의 위치를 리턴한다. 만일 찾지 못한다면 널을 리턴한다.





###  함수의 구현


```cpp-formatted
/*

이 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/

char *strrchr(const char *s, int ch) {
  char *start = (char *)s;
  while (*s++)
    ;
  while (--s != start && *s != (char)ch)
    ;
  if (*s == (char)ch) return (char *)s;
  return NULL;
}
```




###  실행 예제




```cpp-formatted
/*

strrchr 함수를 통해 str 에서 s 가 포함된 가장 오른쪽 위치를 찾는다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strrchr/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "This is a sample string";
  char* pch;
  pch = strrchr(str, 's');
  printf("Last occurence of 's' found at %d \n", pch - str + 1);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F1132541D4C5629879BDA45)




###  연관된 함수

*  [strchr](http://itguru.tistory.com/93)  :   특정한 문자가 포함되어 있는 가장 왼쪽 위치를 찾는다.
*  [memchr](http://itguru.tistory.com/92)  :  메모리에서 특정한 문자를 찾는다.
*  [strpbrk](http://itguru.tistory.com/95)  :  다른 문자들의 문자를 검색어로 삼아 특정한 문자열의 문자들을 찾는다.