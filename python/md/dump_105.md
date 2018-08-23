 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

strerror
```info
#include <string.h> // C++ 에서는 <cstring>

char * strerror ( int errnum );
```

오류 메세지 문자열을 가리키는 포인터를 얻어온다.
errnum 의 값을 통해 발생하였던 오류에 알맞은 오류 메세지를 가리키는 포인터를 리턴한다. 이 때 리턴되는 포인터는문자열 리터럴을 가리키고 있기 때문에 그 내용이 바뀔 수 없다. 참고로 strerror 에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.

### 인자

errnum

오류 번호

### 리턴값

오류 번호에 해당하는 오류 문자열을 가리키는 포인터

### 놀라운 사실

이 함수는 C 표준 함수 중에서 이름에 r 이 가장 많이 포함되어 있는 함수 이다. 무려 r 이 4 개나 있다.


### 실행 예제

```cpp
/*

존재하지 않는 파일 unexist.ent 를 열라고 해 오류가 발생한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strerror/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main ()
{
    FILE * pFile;
    pFile = fopen ("unexist.ent","r");
    if (pFile == NULL)
        printf ("Error opening file unexist.ent: %s\n",strerror(errno));
    return 0;
}

```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F146390194D039BFE0DBDB8)

### 연관된 함수

* perror :  오류 메세지를 출력한다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strlen 함수(0)2010.12.12C 언어 레퍼런스 - strerror 함수(0)2010.12.12C 언어 레퍼런스 - memset 함수(5)2010.11.28C 언어 레퍼런스 - strtok 함수(0)2010.11.27C 언어 레퍼런스 - strstr 함수(3)2010.11.27C 언어 레퍼런스 - strspn 함수(0)2010.11.21

