 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

time.h (ctime)

이는 C 언어에서 시간 관련 함수를 모아놓은 라이브러리이다.


시간 관련 함수들


* clock  :  시계 프로그램

* difftime  :  두 개 시간의 차이를 구한다.

* mktime  :  tm 구조체를 time_t 로 바꾼다.
* time  :  현재 시간을 구한다.

변환 관련


* asctime  :  tm 구조체를 문자열로 바꾼다.

* ctime  :  time_t 값을 문자열로 바꾼다.

* gmtime  :  time_t 를 UTC 시간으로 하여 tm 으로 바꾼다.

* localtime  :  time_t 를 현지 시간으로 하여 tm 으로 바꾼다.
* strftime  :  특정한 형식(사용자가 지정한 형식 문자열)으로 시간을 출력한다.


매크로


* CLOCKS_PER_SEC  :  1 초 당 클록 수

* NULL  :  널 포인터


타입


* clock_t  :  클록 타입

* size_t  :  부호 없는 정수형

* time_t  :  시간 타입

* struct tm  :  시간 구조체


공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >time.h (ctime)' 카테고리의 다른 글C 언어 레퍼런스 - mktime 함수(0)2010.12.26C 언어 레퍼런스 - time_t 형(1)2010.12.25C 언어 레퍼런스 - difftime 함수(0)2010.12.25C 언어 레퍼런스 - clock 함수(2)2010.12.25C 언어 레퍼런스 - struct tm ( tm 구조체 )(0)2010.12.25C 언어 레퍼런스 - time.h 헤더파일(0)2010.12.25

