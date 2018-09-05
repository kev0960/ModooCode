----------------
title : C 언어 레퍼런스 - strncat 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`strncat`




```info
#include <string.h> // C++ 에서는 <cstring>

char * strncat ( char * destination, char * source, size_t num );
```


문자열에 일부 문자들을 덧붙인다.
`source` 의 처음 `num` 개의 문자들을 `destination` 끝에 덧붙인다. 이 때, `destination` 끝에는 자동으로 `NULL` 문자 까지 붙여진다. 만일, `source` 의 문자열의 길이가 `num` 보다 작다면, `source` 의 `NULL` 문자 까지만 붙여진다.



###  인자




`destination`

`destination` 배열을 가리키는 포인터로, C 문자열을 보관하며 (널 문자를 포함한) 합쳐진 문자열이 들어갈 만큼 충분히 크기가 커야만 한다.

`source`

덧붙여질 C 문자열이다.

`num`

`source` 에서 붙일 문자의 (최대) 개수이다.



###  리턴값


`destination` 이 리턴된다.



###  실행 예제


```cpp
/*

str1 의 "To be " 와 str2 의 "or not to be" 를 합쳐서 str1 에 저장한다
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strncat/
에서 가져왔습니다.

*/
#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[20];
    char str2[20];
    strcpy (str1,"To be ");
    strcpy (str2,"or not to be");
    strncat (str1, str2, 6);
    puts (str1);
    return 0;
}

```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F201608194C14EF7D2681EB)



###  함수 구현 예


```cpp
/*

이 소스는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/


char *strncat(char *s1, const char *s2, size_t count){    char *start = s1;    while (*s1++);    s1--;    while (count--)    {        if (!(*s1++ = *s2++)) return start;    }    *s1 = '\0';    return start;}
```



###  연관된 함수


* 
 [strcat](http://itguru.tistory.com/81)  :  문자열을 합친다.



*  [strncpy](http://itguru.tistory.com/80)  :  문자열의 일부분을 복사한다.

*  [memcpy](http://itguru.tistory.com/77)`` :  메모리의 일부분을 복사한다.






