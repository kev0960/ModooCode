 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

stdlib.h (cstdlib)

C 표준 유틸리티 함수들을 모아놓은 헤더파일
이 헤더파일에는 프로그래밍시에 범용적으로 사용되는 여러가지 함수들을 모아 놓고 있는데, 예를 들면 동적 할당 관련 함수, 난수 생성 함수, 정수의 연산 함수, 검색 및 정렬 함수 등 이다.


### 문자열 변환 함수

   문자열로 입력받은 데이터를 수로 변환한다. 예를 들어 문자열로 "123" 을 입력 받았다면 이를 실제 정수인 123 으로 변환하는 함수들이다.


* atof  :  문자열을 double 형으로 변환한다.

* atoi  :  문자열을 정수형으로 변환한다.

* atol  :  문자열을 long 형 정수로 변환한다.

* strtod  :  문자열을 double 형으로 변환한다.
* strtol  :  문자열을 long 형 정수로 변환한다.

* strtoul  :  문자열을 unsigned long 형 정수로 변환하다.


### 난수 생성 함수

의사 난수 (Pseudo random) 를 생성한다. 참고로 의사 난수란, 실제 난순열이 아닌 특정한 알고리즘에 따라 난수 처럼 나타나는 수열이다.


* rand  :  난수를 생성한다.

* srand  :  난수 생성을 위한 초기값을 설정한다.

### 동적 할당 관련 함수

동적 할당 관련 함수들이다.다음 강좌를 보면 동적 할당 함수를 사용하는 방법을 볼 수 있다.


* calloc  :  메모리에 배열을 위한 공간을 할당한다.

* free :  메모리에서 공간을 사용 해제한다.

* malloc  :  메모리에서 공간을 할당한다.

* realloc  :  메모리에서 공간을 재할당 한다.

### 실행 환경 관련 변수들


* abort  :  현재 프로세스를 종료한다.

* atexit  :  특정 함수를 종료시 실행되게 설정한다.
* exit  :  호출한 프로세스를 종료한다.

* getenv  :  환경 문자열을 얻는다.
* system  :  시스템 명령어를 수행한다.


### 검색 및 정렬 함수들


* bsearch  :  배열에서 이진 탐색을 수행한다.
* qsort  :  배열의 원소들을 정렬한다.

### 정수 관련 연산 함수들


* abs  :  절대값을 구한다.
* div  :  정수 나눗셈을 수행한다.

* labs :  절대값을 구한다.
* ldiv  :  정수 나눗셈을 수행한다.


### 다중 바이트(multibyte) 문자 관련 함수

다중 바이트 문자열이란, 한 문자의 크기가 1 바이트 이상인 문자열을 의미한다. 예를 들면 유니코드가 있는데, 유니코드의 경우 한 글자를 2 바이트로 나타낸다.


* mblen  :  멀티바이트 문자의 크기를 구한다.
* mbtowc  :  멀티바이트 문자를 wchar_t 형 문자로 변환한다.

* wctomb  :  wchar_t 형 문자를 멀티바이트 문자로 변환한다.


### 다중 바이트(multibyte) 문자열 관련 함수


* mbstowcs  :  멀티바이트 문자열을 wchar_t 형 문자열로 변환한다.
* wcstombs  :  wchar_t 형 문자열을 멀티바이트 문자열로 변환한다.

### 매크로


* EXIT_FAILURE  :  비정상 종료 코드

* EXIT_SUCCESS  :  정상 종료 코드

* MB_CUR_MAX  :  멀티바이트 문자의 최대 크기
* NULL  :  널 포인터
* RAND_MAX  :  rand 함수가 리턴하는 난수의 최대 크기

### 타입들


* div_t  :  div 가 리턴하는 구조체
* ldiv_t  :  div 와 ldiv 가 리턴하는 구조체
* size_t  :  부호 없는 정수 타입


공감1sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >stdlib.h (cstdlib)' 카테고리의 다른 글C 언어 레퍼런스 - srand 함수(0)2011.05.05C 언어 레퍼런스 - rand 함수(2)2011.05.05C 언어 레퍼런스 - atol 함수(4)2011.01.27C 언어 레퍼런스 - atoi 함수(0)2011.01.27C 언어 레퍼런스 - atof 함수(0)2011.01.09C 언어 레퍼런스 - stdlib.h (cstlib)(1)2011.01.05

