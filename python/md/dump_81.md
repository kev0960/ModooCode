----------------
title : C 언어 레퍼런스 - strcat 함수
--------------


`strcat`




```info
#include <string.h> // C++ 에서는 <cstring>

char * strcat ( char * destination, const char * source );

```

문자열을 덧붙인다.
`destination` 끝에 `source` 를 더하게 된다. 이 때, `destination` 의 맨 마지막 널 문자는 `source` 의 첫번째 문자가 덮어 씌우게 된다. 그리고, `source` 의 마지막 널 문자가 `destination` 끝에 붙어서 새로운 문자열을 형성하게 된다. 다시말해, `destination =` "ab" 이고, source="c" 였다면 `strcat` 후, `destination` 은 "abc" 가 된다.



###  인자




`destination`

`destination` 배열을 가리키는 배열로, C 형식의 문자열을 포함하고 있어야만 하고, 합쳐진 문자열을 포함할 만큼 배열의 크기가 커야 한다.

`source`

`destination` 에 덧붙여질 C 형식 문자열. 이 때, `destination` 과 위치가 겹쳐지면 안된다.



###  리턴값




`destination` 이 리턴된다.



###  실행 예제




```cpp
/*

str 에 각 문자열들을 덧붙인다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strncat/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[80];
    strcpy (str,"these ");
    strcat (str,"strings ");
    strcat (str,"are ");
    strcat (str,"concatenated.");
    puts (str);
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F135F1E174BF5FA1D265DDE)



###  함수 구현 예




```cpp

/*아래 코드는http://www.jbox.dk/sanos/source/lib/string.c.html에서 가져왔습니다.*/char *strcat(char *dst, const char *src){    char *cp = dst;    while (*cp) cp++;    while (*cp++ = *src++);    return dst;}
```





###  연관된 함수





*  [strcpy](http://itguru.tistory.com/79)`` : 문자열을 복사한다.



*  [memcpy](http://itguru.tistory.com/77)  :  메모리 블록을 복사한다.

*  [strncat](http://itguru.tistory.com/82): 문자열에서 일부 문자들만 덧붙인다.







