 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

memset

```info
#include <string.h> // C++ 에서는 <cstring>

void * memset ( void * ptr, int value, size_t num );
```


메모리 블록을 채운다.
ptr 로 시작하는 메모리 주소 부터 num 개의 바이트를 value 값으로 채운다. 이 때, value 는 unsigned char 로 형변환 된다.

### 인자

ptr

값을 채울 메모리의 시작 주소

value

채울 값. 인자로는 int 로 전달되지만 함수 내부적으로는 unsigned char 로 형변환 되어서 사용된다.

num

value 로 채울 바이트 수

### 리턴값

ptr 이 리턴된다.

### 실행 예제

```cpp
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/memset/
에서 가져왔습니다.

*/
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] = "almost every programmer should know memset!";
    memset (str,'-',6);
    puts (str);
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F19727B194CF1A1D02D9726)


### 연관된 함수


* memcpy  :   메모리 블록을 복사한다.

* strncpy  :  문자열의 일부분을 복사한다.

* memcmp :  두 개의 메모리 블록을 비교한다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strlen 함수(0)2010.12.12C 언어 레퍼런스 - strerror 함수(0)2010.12.12C 언어 레퍼런스 - memset 함수(5)2010.11.28C 언어 레퍼런스 - strtok 함수(0)2010.11.27C 언어 레퍼런스 - strstr 함수(3)2010.11.27C 언어 레퍼런스 - strspn 함수(0)2010.11.21

