 itguru Top itguru Top

strcat

```info
#include <string.h> // C++ 에서는 <cstring>

char * strcat ( char * destination, const char * source );

```

문자열을 덧붙인다.
destination 끝에 source 를 더하게 된다. 이 때, destination 의 맨 마지막 널 문자는 source 의 첫번째 문자가 덮어 씌우게 된다. 그리고, source 의 마지막 널 문자가 destination 끝에 붙어서 새로운 문자열을 형성하게 된다. 다시말해, destination = "ab" 이고, source="c" 였다면 strcat 후, destination 은 "abc" 가 된다.

### 인자

destination

destination 배열을 가리키는 배열로, C 형식의 문자열을 포함하고 있어야만 하고, 합쳐진 문자열을 포함할 만큼 배열의 크기가 커야 한다.

source

destination 에 덧붙여질 C 형식 문자열. 이 때, destination 과 위치가 겹쳐지면 안된다.

### 리턴값

destination 이 리턴된다.

### 실행 예제

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

### 함수 구현 예

```cpp
/*

아래 코드는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다.

*/
char *strcat(char *dst, const char *src)
{
    char *cp = dst;
    while (*cp) cp++;
    while (*cp++ = *src++);
    return dst;
}

```



### 연관된 함수

* strcpy : 문자열을 복사한다.

* memcpy  :  메모리 블록을 복사한다.
* strncat: 문자열에서 일부 문자들만 덧붙인다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - memcmp 함수(1)2010.06.25C 언어 레퍼런스 - strncat 함수(0)2010.05.23C 언어 레퍼런스 - strcat 함수(0)2010.05.21C 언어 레퍼런스 - strncpy 함수(5)2010.05.09C 언어 레퍼런스 - strcpy 함수(8)2010.05.02C 언어 레퍼런스 - memmove 함수(7)2010.04.25

