----------------
title : C 언어 레퍼런스 - string.h (cstring) 헤더파일
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`<string.h> (cstring)`




이 헤더파일에는 C 형식 문자열 (널 종료 문자열) 을 다룰 수 있는 함수들을 포함하고 있다. 이 `string.h` 는 C 표준 라이브러리에 들어간 이후, 널리 쓰이게 되어 대부분의 C 를 지원하는 곳에서는 이 헤더파일에 정의되어 있는 함수들의 사용을 가능케 한다.

문자열 복사 함수


*  [memcpy](http://itguru.tistory.com/77)  :  메모리의 특정한 블록을 복사한다.



*  [memmove](http://itguru.tistory.com/78)  :  메모리의 특정한 블록을 이동시킨다.



*  [strcpy](http://itguru.tistory.com/79)  :  문자열을 복사한다.

*  [strncpy](http://itguru.tistory.com/80)`` :  문자열에서 지정한 부분 만큼 복사한다.




문자열 합치는 함수


*  [strcat](http://itguru.tistory.com/81)  :  두 개의 문자열을 합친다.

*  [strncat](http://itguru.tistory.com/82)  :  두 개의 문자열을 지정한 부분 만큼 합친다.


문자열 비교 함수


*  [memcmp](http://itguru.tistory.com/84)  :  메모리의 두 부분을 비교한다.

*  [strcmp](http://itguru.tistory.com/85)  :  두 개의 문자열을 비교한다.



*  [strcoll](http://itguru.tistory.com/86)  :   `locale` 을 이용하여 두 개의 문자열을 비교한다.



*  [strncmp](http://itguru.tistory.com/90)  :  두 개의 문자열의 일부분을 비교한다.

*  [strxfrm](http://itguru.tistory.com/91)`` :  `locale` 을 이용하여 문자열을 변환한다.




문자열 검색함수 [[각주:](#footnote_76_1)`1 1`]`


*  [memchr](http://itguru.tistory.com/92)`` :  메모리 블록에서 특정한 문자를 찾는다.



*  [strchr](http://itguru.tistory.com/93)  :  문자열에서 특정한 문자를 찾아 그 위치를 구한다.



*  [strcspn](http://itguru.tistory.com/94)  :  특정한 문자열에 포함된 문자들을 다른 문자열에서 찾아 가장 먼저 나오는 것을 구한다.



*  [strpbrk](http://itguru.tistory.com/95)`` :  특정한 문자열에 포함된 문자들을 다른 문자열에서 찾아 일치되는 것을 가리킨다.



*  [strrchr](http://itguru.tistory.com/96)  :  문자열에서 특정한 문자를 찾되, 뒤에서 부터 찾는다.



*  [strspn](http://itguru.tistory.com/97)  :  특정한 문자열에서 다른 문자열에 포함되어 있는 부분을 찾되, 처음 부터 연속된 부분으로 구한다.

*  [strstr](http://itguru.tistory.com/101)  :  특정한 문자열을 다른 문자열에서 검색한다.



*  [strtok](http://itguru.tistory.com/102)  :  문자열을 토큰으로 분리한다.


다른 잡다한 함수들


*  [memset](http://itguru.tistory.com/104)  :  메모리 블록을 채운다.



*  [strerror](http://itguru.tistory.com/105)  :  오류 메세지 문자열을 가리키는 포인터를 구한다.

*  [strlen](http://itguru.tistory.com/106)  :  문자열의 길이를 잰다.




매크로


* NULL  :  널 포인터




타입


* size_t  :  부호없는 정수





1. 각 함수에 대한 설명이 복잡하므로 함수 이름을 클릭해서 보도록 하는 것이 좋다.
 [[본문으로]](#footnote_link_76_1)



