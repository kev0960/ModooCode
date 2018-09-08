----------------
title : C 언어 레퍼런스 - stdio.h (cstdio) 헤더파일
--------------




```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?
```

#@ Stdio.h (cstdio)

  C 언어에서 입출력 연산은 표준 입출력 라이브러리 (Standard Input and Output Library) 를 이용해서 수행될 수 있다. (C++ 에서는 cstdio 라는 이름으로 사용된다). 이 라이브러리는 스트림(stream) 을 이용해서 키보드나 프린터, 터미널과 같은 장비들이나 시스템이 지원하는 특정한 형태의 파일들과 작업할 수 있다. 모든 스트림들은 작업하고자 하는 장비들과 관계 없이 공통된 특징들을 가지고 있기 때문이 매우 편리하다.

  `FILE` 객체에 대한 포인터는 각각의 스트림들을 구분하기 때문에 스트림을 이용한 작업시 인자로 전달된다.

  또한 `stdio.h` 라이브러리를 사용하는 프로그램에서 자동으로 생성되고 열리는(open) 표준 스트림들이 있는데 이는`stdin, stdout, stderr``` 이다.



###  스트림의 특징




  스트림의 속성 중에는 "어떠한 함수들 만이 스트림을 사용할 수 있다" 와 "이 스트림이 어떠한 방식으로 데이터를 입출력 하느냐" 가 있다. 이러한 속성들은 `fopen` 함수를 통해 스트림이 파일과 어떠한 방식으로 연관되어 있는지에 따라 달라지게 된다.

읽기 쓰기 권한 (Read/Write Access)

이 스트림이 연관된 물리 장비로 부터 읽거나 쓸 수 있는지 (또는 둘 다)에 대한 정보를 알려준다.

텍스트 `/` 바이너리 (Text/Binary)

텍스트 스트림들은 말그대로 문장을 중심으로 작동하며 각 문장은 개행 문자로 끝나게 된다. 텍스트 스트림은 받아들인 각 문자를 번역을 하게 되는데 프로그램이 작동되는 환경에 따라 일부 문자들을 다른 방식으로 번역할 수 도 있다. 실제 예로, 애플의 매킨 토시 컴퓨터들은 개행 문자(new-line character)로 `CR` (캐리지 리턴, `carriage return)` 한 문자를 사용한다. 하지만 리눅스와 같은 유닉스 기반 컴퓨터들은 개행문자로 `LF` (라인 피드, `line feed)` 한 문자를 사용한다. 그러나 `DOS` 나 윈도우즈, `OS/2` 계열의 운영체제들은 `CR + LF` 를 사용해서 두 문자로 개행 문자임을 표시한다. [[각주:](#footnote_34_1)`1 1`]`이렇게, 운영체제 마다 똑같은 개행 문자를 다른 방식으로 번역하기 때문에 텍스트 스트림에 경우 각 프로그램의 작동 환경에 영향을 받을 수 밖에 없다. 그러나 바이너리 스트림 (이진 스트림) 의 경우 단순히 장비로 부터 순차적으로 이진 데이터를 입력 받는 것이기 때문에 번역 과정이 필요 없을 뿐더러 각 환경에 영향을 받지도 않는다.

버퍼(Buffer)

버퍼는 메모리의 일부분으로 장치나 파일로 부터 읽거나 쓰기 전에 저장되는 곳이다. 스트림은`fully buffered, line buffered, unbuffered`중 하나가 될 수 있다. `fully buffered` 스트림의 경우, 데이터는 버퍼가 꽉 찰 경우 데이터가 읽어/쓰여 지고, `line buffered` 스트림의 경우 개행 문자가 버퍼에 들어왔을 때, `unbuffered` 스트림의 경우 어떠한 상태에서도 바로 데이터가 읽어/쓰여지는 스트림이다. 기본적으로 `stdin` 은 `fully bufferd, stderr` 은 `unbuffered, stdout` 은 터미널일 경우 `line buffered,` 아니면 `fully buffered` 상태로 설정되어 있다. [[각주:](#footnote_34_2)`2 2`]`


###  스트림 상태 표시자(indicator)



   스트림은 현재의 상태를 나타내기 위해 특정한 표시자가 있으며, 이는 스트림의 입출력 형태에 영향을 줄 수 있다.

오류 표시자 (Error indicator)

이 표시자는 스트림 관련한 연산에서 오류가 발생하였을 때 설정(set) 된다. 이 표시자의 상태는 `ferror` 함수를 통해 확인할 수 있으며 `clearerr` 함수나 [rewind](http://itguru.tistory.com/75)`,` [fseek](http://itguru.tistory.com/72)`,` [fsetpos](http://itguru.tistory.com/73)`` 함수들을 통해 표시자의 상태를 초기화 할 수 있다.

파일 끝 표시자 (End-Of-File indicator)

이 표시자가 설정되면 스트림의 읽기 혹은 쓰기 연산이 파일의 끝 부분에 도달하였다는 뜻을 나타낸다. 이는 [feof](http://itguru.tistory.com/51)`` 함수를 통해 확인할 수 있으며 `clearerr` 함수나 [rewind](http://itguru.tistory.com/75)`,` [fseek](http://itguru.tistory.com/72)`,` [fsetpos](http://itguru.tistory.com/73)`` 함수를 통해 초기화 할 수 있다.

위치 표시자 (Position Indicator)

이는 포인터로 스트림이 입출력 연산에서 다음으로 읽거나 쓸 문자를 가리킨다. 이 표시자가 가리키는 값은 [ftell](http://itguru.tistory.com/74)`` 이나 `fgetpos` 함수를 통해 알아낼 수 있으며 역시 [rewind](http://itguru.tistory.com/75)`,` [fseek](http://itguru.tistory.com/72)`,` [fsetpos](http://itguru.tistory.com/73)`` 함수를 이용해서 표시자의 값을 바꿀 수 있다.




###  stdio.h 에 정의된 함수들




파일 작업 관련:


* `remove` : 파일을 삭제한다

* `rename` : 파일 이름을 변경한다.

* `tempfile` : 임시 파일을 연다

* `tempnam` : 임시 파일의 이름을 생성한다.


파일 접근 관련:


*  [fclose](http://itguru.tistory.com/54)`` : 파일을 닫는다

*  [fflush](http://itguru.tistory.com/57)`` : 스트림을 비운다 (flush)

*  [fopen](http://itguru.tistory.com/58)`` : 파일을 연다

*  [freopen](http://itguru.tistory.com/59)`` : 다른 파일이나 모드로 스트림을 다시 연다.

*  [setbuf](http://itguru.tistory.com/61)`` : 스트림 버퍼를 설정한다.

*  [setvbuf](http://itguru.tistory.com/62)`` : 스트림의 버퍼 및 모드(fully `buffered, line buffered, unbuffered)` 까지 설정한다.


형식 있는(formatted) 입출력:


*  [fprintf](http://itguru.tistory.com/64)`` : 형식 있는 데이터를 스트림에 쓴다.

*  [fscanf](http://itguru.tistory.com/65)`` : 형식 있는 데이터를 스트림에서 읽는다.

*  [printf](http://itguru.tistory.com/35)`` : `stdout` 에 형식 있는 데이터를 출력한다.

*  [scanf](http://itguru.tistory.com/36)`` : 형식 있는 데이터를 `stdin` 에서 읽는다.

*  [sprintf](http://itguru.tistory.com/66)`` : 문자열에 형식 있는 데이터를 쓴다.

*  [sscanf](http://itguru.tistory.com/67)`` : 문자열에서 형식 있는 데이터를 읽는다.

* `vfprintf` : 스트림에 형식 있는 가변 인자 목록(variable `argument` list)을 쓴다.

* `vprintf` : `stdout` 에 가변 인자 목록을 출력한다.

* `vsprintf` : 문자열에 가변 인자 목록을 출력한다.


문자(character) 입출력:


*  [fgetc](http://itguru.tistory.com/37)`` : 스트림에서 문자를 받는다.



*  [fgets](http://itguru.tistory.com/38)`` : 스트림에서 문자열을 받는다.



*  [fputc](http://itguru.tistory.com/39)`` : 스트림에 문자를 쓴다.

*  [fputs](http://itguru.tistory.com/40)`` : 스트림에 문자열을 쓴다.

*  [getc](http://itguru.tistory.com/41)`` : 스트림에서 문자를 받는다.



*  [getchar](http://itguru.tistory.com/44)`` : `stdin` 에서 문자를 받는다.

*  [gets](http://itguru.tistory.com/45)`` :  `stdin` 에서 문자열을 받는다.



*  [putc](http://itguru.tistory.com/46)`` : 스트림에 문자를 쓴다.

*  [putchar](http://itguru.tistory.com/47)`` : 문자를 `stdout` 에 쓴다.



*  [puts](http://itguru.tistory.com/48)`` : 문자열을 `stdout` 에 쓴다.

*  [ungetc](http://itguru.tistory.com/49)`` : 스트림으로부터 문자를 `unget` 한다. (마지막으로 읽어들인 위치로 되돌림)


직접적인 입출력:


*  [fread](http://itguru.tistory.com/68)`` : 스트림으로 부터 데이터 블록을 읽는다.

*  [fwrite](http://itguru.tistory.com/69)`` : 스트림에 데이터 블록을 쓴다.


파일 위치 지정:


*  [fgetpos](http://itguru.tistory.com/70)`` : 현재 스트림의 (읽어들이는) 위치를 얻는다.

*  [fseek](http://itguru.tistory.com/72)`` : 스트림 위치 표시자의 위치를 재조정한다.

*  [fsetpos](http://itguru.tistory.com/73)`` : 스트림의 위치 표시자를 설정한다.

*  [ftell](http://itguru.tistory.com/74)`` : 스트림의 현재 위치를 얻는다.

*  [rewind](http://itguru.tistory.com/75)`` : 위치 표시자의 위치를 맨 앞으로 조정한다.


오류 처리:


*  [clearerr](http://itguru.tistory.com/50)`` : 오류 표시자를 초기화한다.



*  [feof](http://itguru.tistory.com/51)`` : 파일 끝 표시자 (End of file indicator) 을 확인한다.

*  [ferror](http://itguru.tistory.com/52)`` : 오류 표시자를 확인한다.

*  [perror](http://itguru.tistory.com/53)`` : 오류 메세지를 출력한다.




###  매크로






* `EOF` : 파일 끝(end `of file)`



* `FILENAME_MAX` : 파일 이름의 최대 길이

* `NULL` : 널 포인터



* `TMP_MAX` : 임시 파일의 (최대) 개수

이 외에도 `_IOFBF, _IOLBF, _IONBF, BUFSIZ, FOPEN_MAX, L_tmpnam, SEEK_CUR, SEEK_END, SEEK_SET` 이 있는데 이는 이들을 이용하는 함수들에 설명되어 있다.





###  타입 (형)





* `FILE` : 스트림을 제어하는 정보를 가지고 있는 객체

* `fpos_t` : 파일의 (읽어들이는) 위치를 설정하기 위한 정보를 가지는 객체

* `size_t` : 부호 없는 정수


`*` 위 글의 모든 자료들은 다음 사이트에서 번역한 내용입니다. [http://www.cplusplus.com/](http://www.cplusplus.com/)


1. http://www.felgall.com/cplus4.htm
 [[본문으로]](#footnote_link_34_1)
1. http://www.pixelbeat.org/programming/stdio_buffering/
 [[본문으로]](#footnote_link_34_2)



