 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

strcoll

```info
#include <string.h> // C++ 에서는 <cstring>

int strcoll ( const char * str1, const char * str2 );
```

locale 을 이용하여 두 개의 문자열을 비교한다.
C 형식 문자열인 str1 과 str2 를 LC_COLLATE 에 정의되어 있는 방식에 따라 해석 된 후 비교하게 된다. 이 함수 역시 문자 하나 하나를 일일히 비교하여 두 개의 문자가 다른 것이 나타날 때 까지나 NULL 에 도달할 때 까지 비교를 수행한다.

### 인자

str1

비교할 C 형식 문자열

str2

비교할 C 형식 문자열


### 리턴값

아래와 같은 규칙으로 값을 리턴한다.
두 문자열이 일치하면 0 을 반환한다.
만일 str1 과 str2 에서 최초로 일치하지 않는 문자의 값이 str1 이 더 크다면 0 보다 큰 값을 반환하고 그렇지 않다면 0 보다 작은 값을 반환하게 된다.

### 연관된 함수

* strcmp  :  두 문자열을 비교한다.

* strncmp  :  두 문자열의 일부분을 비교한다.
* memcmp  :  두 메모리 블록을 비교한다.


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strxfrm 함수(0)2010.08.01C 언어 레퍼런스 - strncmp 함수(0)2010.08.01C 언어 레퍼런스- strcoll 함수(0)2010.07.10C 언어 레퍼런스 - memcmp 함수(1)2010.06.25C 언어 레퍼런스 - strncat 함수(0)2010.05.23C 언어 레퍼런스 - strcat 함수(0)2010.05.21

