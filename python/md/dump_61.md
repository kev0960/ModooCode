----------------
title : C 언어 레퍼런스 - setbuf 함수
cat_title :  setbuf
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ setbuf



```info
#include <stdio.h> // C++ 에서는 <cstdio>

void setbuf ( FILE * stream, char * buffer );
```


스트림 버퍼를 설정한다.
특정한 스트림의 입출력 작업을 위한 버퍼를 설정하며 이는 보통 `fully buffered` 스트림으로 설정된다. (fully buffered 나 뒤에 나오는 unbuffered, line buffered 에 대한 설명은 [stdio.h](http://itguru.tistory.com/34) 를 참조하세요) 만일 두 번째 인자가 `NULL` 이라면 이 스트림은 unbuffered 스트림으로 설정된다.

두 번째 인자는 반드시 `BUFSIZ` 이상의 길이를 가지는 배열을 가리켜야만 한다. (BUFSIZ 는 <stdio.h> (C++ 은 <cstdio> 에 정의되어 있는 상수이다) fully buffered 스트림의 경우 쓰기 작업은 스트림과 연관되는 장비(예를 들어 파일 입출력을 한다면 연관되는 장비는 하드 디스크가 된다) 에 바로 쓰이지 않는다. 그 대신, 쓰여질 데이터가 버퍼에 한 데 모인뒤, 한 블록이 채워지면 그제서야 쓰기를 시작하게 된다.

물론, 블록이 다 채워지지 않았는데도 불구하고 강제적으로 스트림을 비우므로써 (flush) 데이터가 쓰여지게 할 수 있고 이 작업은 [fflush](http://itguru.tistory.com/57)함수를 호출하거나, [fclose](http://itguru.tistory.com/54) 함수를 호출해 파일을 닫아버리면 된다. 참고로 모든 버퍼들은 프로그램이 종료 될 때 자동적으로 비워진다.

unbuffered 스트림의 경우, 데이터는 fully buffered 스트림과는 달리 한 블록이 될 동안 모이지 않고 매 쓰기 작업마다 장비에 직접적으로 쓰게 된다.

파일을 열게 되면 기본적으로 할당된 버퍼를 가지게 된다. 하지만 이 함수를 호출함으로써 사용자-정의 된 버퍼를 사용하거나 특정한 스트림을 unbuffered 스트림으로 만들어버릴 수 있다.

보통 시스템 표준 스트림들, 예를들면 `stdout` 이나 `stderr` 은 모두 기본적으로 리다이렉트(redirect) 되지 않는 이상 unbuffered 스트림으로 설정된다.

만일 스트림을 line buffered 스트림으로 바꾸고 싶다면 `setvbuf` 함수를 사용하면 된다.

###  인자


`stream`

작업을 수행할 스트림의 `FILE` 객체를 가리키는 포인터

`buffer`

사용자가 직접 할당한 버퍼로, 최소 `BUFSIZ` 이상의 바이트를 가져야 한다. 이 `BUFSIZ` 는 매크로 상수로 `<stdio.h>` (C++ 이면 `<cstdio>`) 에 정의되어 있다. 또한 unbuffered 스트림으로 바꾸려면 `NULL` 포인터를 전달하면 된다.



###  리턴값




없음



###  예제


```cpp-formatted
/* myfile.txt 와 myfile2.txt 를 각각 쓰기 모드 와 덧붙이기(append) 모드로 열어서
 * buffer 을 버퍼로 사용한다. 이 때, pFIle1 의 경우 buffer 를 버퍼로 사용하지만
 * pFile2 는 버퍼를 사용하지 않는다. */
#include <stdio.h>
int main() {
  char buffer[BUFSIZ];
  FILE *pFile1, *pFile2;
  pFile1 = fopen("myfile.txt", "w");
  pFile2 = fopen("myfile2.txt", "a");
  setbuf(pFile1, buffer);
  fputs("This is sent to a buffered stream\n", pFile1);
  fflush(pFile1);
  setbuf(pFile2, NULL);
  fputs("This is sent to an unbuffered stream\n", pFile2);
  fclose(pFile1);
  fclose(pFile2);
  return 0;
}
```

파일에 쓰여진 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F137E581E4B7816E90A324C)


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F1705EC1E4B7816E90789F8)

일단 첫번째의 경우

```cpp-formatted
setbuf(pFile1, buffer);
fputs("This is sent to a buffered stream\n", pFile1);
fflush(pFile1);
```

`buffer` 을 `pFile1` 스트림의 버퍼로 사용하였다. 이 때, 데이터가 한 블록이 다 채워졌는지 아닌지 모르므로 마지막에 `fflush` 를 강제적으로 호출하여 파일에 써준다.

```cpp-formatted
setbuf(pFile2, NULL);
fputs("This is sent to an unbuffered stream\n", pFile2);
```

두번째의 경우 `pFile2` 는 버퍼를 사용하지 않는 `unbuffered` 스트림 이므로 버퍼를 강제적으로 비울 필요가 없다. (사실 비울 버퍼도 없다)왜냐하면 쓰기 작업을 하자 마자 바로 파일에 쓰여지기 때문이다.



###  연관된 함수


*  [fopen](http://itguru.tistory.com/58)  :  파일을 연다.
*  [fflush](http://itguru.tistory.com/57):  스트림을 비운다.
*  [setvbuf](http://itguru.tistory.com/62)  :  스트림 버퍼링 방식을 설정한다.