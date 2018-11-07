----------------
title : C 언어 레퍼런스 - strpbrk 함수
cat_title :  strpbrk
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strpbrk

```info
#include <string.h> // C++ 에서는 <cstring>

const char * strpbrk ( const char * str1, const char * str2 );
      char * strpbrk (       char * str1, const char * str2 );
```


문자열에서 다른 문자열에 들어 있는 문자들을 검색어로 생각하여 찾는다.

이 때, 가장 첫번째로 일치되는 문자를 가리키는 포인터를 반환한다. 만일 일치되는 것이 없다면 `NULL` 을 반환하게 된다.

또한 이 함수는 문자열의 `NULL` 종료 문자는 문자열에 포함되어 있지 않다고 생각한다.

위에 나온 두 원형은 C++ 에서만 적용된다. (C++ 에서는 함수 오버로딩이 가능하므로) 다만 C 에서는 아래와 같은 하나의 원형만을 가진다.

```info
char * strpbrk ( const char *, const char * );
```





###  인자


`str1`

검색을 수행할 문자열

`str2`

검색어들을 포함하고 있는 문자열



###  리턴값


`str2` 의 문자들 중 `str1` 의 문자들과 첫번째로 일치하는 문자를 가리키게 된다. 만일 `str1` 의 널 문자 이전 까지 일치하는 것이 없다면 널을 리턴한다.



###  함수의 구현


```cpp-formatted
/*

다음 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/

char *strpbrk(const char *string, const char *control) {
  const unsigned char *str = string;
  const unsigned char *ctrl = control;
  unsigned char map[32];
  int count;  // Clear out bit map    for (count = 0; count < 32; count++)
              // map[count] = 0;    // Set bits in control map    while (*ctrl)
              // {        map[*ctrl >> 3] |= (1 << (*ctrl & 7));        ctrl++;
              // }    // 1st char in control map stops search    while (*str) {
              // if (map[*str >> 3] & (1 << (*str & 7))) return (char *) str;
              // str++;    }    return NULL;}
```


위 함수의 작동 원리에 대해 이해가 잘 안되는 분들은 [http://itguru.tistory.com/94](http://itguru.tistory.com/94)을 보시기 바랍니다.



###  실행 예제




```cpp-formatted
/*

strpbrk 로 일치하는 문자를 찾았다면 포인터의 값을 1 증가시켜서 그 다음 부분 부터
계속 검색을 수행한다. 즉 str 에 포함된 모든 vowel 들의 위치를 구하게 된다. 이
예제는 http://www.cplusplus.com/reference/clibrary/cstring/strpbrk/ 에서
가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char* pch;
  printf("Vowels in '%s': ", str);
  pch = strpbrk(str, key);

  while (pch != NULL) {
    printf("%c ", *pch);
    pch = strpbrk(pch + 1, key);
  }
  printf("\n");

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F194FCA104C562317E980E9)



###  연관된 함수


* 

 [strcspn](http://itguru.tistory.com/94)  :  이 함수와 동일한 검색을 수행하되, 찾은 문자까지 거리를 구한다.
*  [strchr](http://itguru.tistory.com/93):  특정한 문자를 검색하는데 가장 먼저 나타나는 위치를 찾는다.
* strrchr  :  특정한 문자를 검색하는데 가장 마지막으로 나타나는 위치를 찾는다.
*  [memchr](http://itguru.tistory.com/92)  :  메모리에서 특정한 문자를 찾는다.