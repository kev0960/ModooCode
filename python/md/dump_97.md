----------------
title : C 언어 레퍼런스 - strspn 함수
cat_title :  strspn
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strspn

```info
#include <string.h> // C++ 에서는 <cstring>

size_t strspn ( const char * str1, const char * str2 );
```


`str2` 의 문자들만을 포함하고 있는 `str1` 의 처음 부분의 길이를 구한다.
다시 말하면 `str2` 에 "12346" 이 들어있고 `str1` 에는 "321ab" 가 들어 있다면 `str1` 의 맨 처음 부터 문자들을 비교하는데, `str2` 에 들어 있는 문자들 만을 포함한 곳 까지의 길이, 즉 이 경우에는 `3,2,1` 이 해당하므로 3 이 리턴된다. 이 때 중요한 점은 `str1` 의 맨 처음 부터 비교한다는 점인데 만일 `str1` 에 "ab321" 이였다면 리턴값이 0 이 된다.



###  인자




`str1`

검색을 수행되는 C 문자열

`str2`

검색할 문자들을 포함하고 있는 문자열



###  리턴값




`str1` 에서 오직 `str2` 에 포함되어 있는 문자들만이 있는 부분의 길이로, `str1` 의 맨 처음 부분 부터 잰다. 따라서 만일 `str1` 에 있는 모든 문자들이 `str2` 에 포함되어 있다면 리턴값은 `str1` 의 길이와 동일하겠지만, 만일 `str1` 에 있는 첫 번째 문자가 `str2` 에 없다면 리턴값은 0 이 된다.



###  구현 예


```cpp-formatted
/*

 이 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/

size_t strspn(const char *string, const char *control) {
  const unsigned char *str = string;
  const unsigned char *ctrl = control;
  unsigned char map[32];
  int count;  // Clear out bit map
  for (count = 0; count < 32; count++)
    map[count] = 0;  // Set bits in control map
  while (*ctrl) {
    map[*ctrl >> 3] |= (1 << (*ctrl & 7));
    ctrl++;
  }  // 1st char NOT in control map stops search
  if (*str) {
    count = 0;
    while (map[*str >> 3] & (1 << (*str & 7))) {
      count++;
      str++;
    }
    return count;
  }
  return 0;
}
```

위 예는 상당히 복잡하고도 참신한 아이디어를 방법으로 `strspn` 함수를 구현하였는데, 위 코드에 대한 자세한 설명을 위해서는 [http://itguru.tistory.com/94](http://itguru.tistory.com/94) 를 참조하면 된다.



###  실행 예제

```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strstr/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main() {
  int i;
  char strtext[] = "129th";
  char cset[] = "1234567890";

  i = strspn(strtext, cset);
  printf("The length of initial number is %d.\n", i);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F207075134CE88952A5D63C)



###  연관된 함수

*  [strcspn](http://itguru.tistory.com/94): 특정한 문자열을 키로 하여 다른 문자열을 검색하되 첫번째로 검색된 곳의 거리를 리턴
*  [strstr](http://itguru.tistory.com/101)  :    특정한 문자열을 키로 하여 다른 문자열에서 '키' 의 위치를 리턴
*  [strncmp](http://itguru.tistory.com/90)  :   두 문자열의 일부분을 비교한다.