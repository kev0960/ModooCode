----------------
title : C 언어 레퍼런스 - strcmp 함수
cat_title :  strcmp
publish_date : 2010-06-25
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strcmp

```info-format
#include <string.h> // C++ 에서는 <cstring>

int strcmp ( const char * str1, const char * str2 );
```


두 개의 문자열을 비교한다.

C 문자열 형식의 `str1` 과 `str2` 를 비교한다.

이 함수는 각 문자열의 첫 번째 문자 부터 비교를 시작한다. 만일 같다면 두 문자가 다를 때 까지나 `NULL` 에 도달할 때 까지 계속 비교를 수행한다.



###  인자

`str1`

비교할 C 형식 문자열

`str2`

비교할 C 형식 문자열



###  리턴값


두 문자열의 관계에 따라 정수값을 리턴한다.

만일 두 문자열이 정확하게 일치한다면 0 을 리턴한다.

일치하지 않을 경우, 일치 하지 않는 첫 번째 문자를 비교해 `str1` 이 `str2` 보다 크다면 0 보다  큰 값을 아니면 0 보다 작은 값을 리턴한다.



###  strcmp 함수의 간단한 구현





```cpp-formatted
/*

다음 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/
int strcmp(const char *s1, const char *s2) {
  int ret = 0;
  while (!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s2)
    ++s1, ++s2;

  if (ret < 0)
    ret = -1;
  else if (ret > 0)
    ret = 1;

  return ret;
}
```



###  실행 예제




```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strcmp/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main() {
  char szKey[] = "apple";
  char szInput[80];
  do {
    printf("Guess my favourite fruit? ");
    scanf("%s", szInput);
  } while (strcmp(szKey, szInput) != 0);

  puts("Correct answer!");
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F193B1B1E4C24BABDAC1454)

###  연관된 함수

*  [strncmp](http://itguru.tistory.com/90)  :  두 문자열의 일부 문자를 비교한다.
*  [memcmp](http://itguru.tistory.com/84)  :  두 메모리 블록을 비교한다.
*  [strrchr](http://itguru.tistory.com/96)  :  문자열에서 특정한 문자가 마지막으로 나타나는 위치를 찾는다.
*  [strspn](http://itguru.tistory.com/97)  :  특정한 문자열이 다른 문자열에서 차지하는 길이를 계산한다.