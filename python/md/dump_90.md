 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

strncmp
```info
#include <string.h> // C++ 에서는 <cstring>

int strncmp ( const char * str1, const char * str2, size_t num );
```


두 문자열의 일부 문자들을 비교한다.
C 형식 문자열인 str1 의 처음 num 개의 문자를 다른 C 형식 문자열인 str2 의 처음 num 개의 문자와 비교한다.
이 함수는 처음 문자들 부터 비교를 수행하되, 다른 문자가 나타나거나 NULL 에 도달하거나, num 개의 문자들을 비교할 때 까지 비교를 수행하게 된다.

### 인자

str1

비교할 C 형식 문자열

str2

비교할 C 형식 문자열

num

(처음 부터) 비교할 최대 문자의 개수

### 리턴값


리턴값은 다음과 같이 정해진다.
만일 num 개의 문자가 모두 일치한다면 0 을 리턴한다.
비교한 num 개의 문자 중 최초로 일치하지 않는 문자의 값이 str1 이 더 큰 경우 0 보다 큰 값을, str2  가 더 큰 경우 0 보다 작은 값을 리턴한다.

### 실행 예제

```cpp
/*

"R2xx" 의 처음 두 문자, 즉 R2 와 str 의 각 문자열들의 처음 두 문자를 비교한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strncmp/
에서 가져왔습니다.

*/
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n;
    puts ("Looking for R2 astromech droids...");
    for (n=0 ; n<3 ; n++)
        if (strncmp (str[n],"R2xx",2) == 0)
        {
            printf ("found %s\n",str[n]);
        }
        return 0;
}

```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F11111F374C54DB6A68C480)



### 연관된 함수


* strcmp :  두 문자열을 비교한다.

* memcmp  :  두 메모리 블록을 비교한다.

* strrchr  :  문자열에서 지정한 문자의 마지막 위치를 얻는다.
* strspn  :  문자열의 일치된 정도를 얻는다. (자세한 내용은 레퍼런스 참조)


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - memchr 함수(0)2010.08.01C 언어 레퍼런스 - strxfrm 함수(0)2010.08.01C 언어 레퍼런스 - strncmp 함수(0)2010.08.01C 언어 레퍼런스- strcoll 함수(0)2010.07.10C 언어 레퍼런스 - memcmp 함수(1)2010.06.25C 언어 레퍼런스 - strncat 함수(0)2010.05.23

