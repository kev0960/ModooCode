----------------
title : C 언어 레퍼런스 - perror 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`perror`



```info
#include <stdio.h> // C++ 에서는 <cstdio>

void perror ( const char * str );
```


오류 메세지를 출력한다.
전역 변수 `errno` 의 값을 해석하여 이에 해당하는 시스템 오류 메세지를 표준 오류 출력 스트림(standard `error output stream,``stderr``)`에 출력한다. 보통 `stderr` 은 화면이다. 또한 추가적으로 전달하고자 하는 사용자 정의 메세지를 `str` 인자에 담아 출력할 수 도 있다.
`errno` 는 정수형 변수로 이전의 라이브러리 함수에 의해 발생한 오류에 대한 정보를 가지고 있다. 이 때, `errno` 에 값에 따라 `perror` 함수에 의해 출력되는 시스템 오류 메세지는 플랫폼이나 컴파일러에 따라 달라질 수 있다.
만일 `str` 이 널 포인터가 아니라면 사용자 정의 메세지가 시스템 오류 메세지 이전에 출력된다. 이 때 두 개의 메세지는 ": " 로 구분된다. 그리고 `str` 이 널 포인터인지 아닌지에 상관 없이 맨 마지막에는 개행 문자('\n')가 출력된다.
`perror` 은 오류가 발생한 바로 다음에 호출되어야 한다. 그렇지 않을 경우 다른 함수들의 호출에 의해 출력 결과가 달라질 수 있다.



###  인자




`str`

`C` 형식 문자열로 시스템 오류 메세지 다음에 이어서 출력할 사용자 정의 메세지이다 C 형식 문자열로 시스템 오류 메세지 다음에 이어서 출력할 사용자 정의 메세지이다.
만일 널 포인터라면, 시스템 오류 메세지 다음에 어떠한 메세지도 출력되지 않는다.
관습적으로 프로그램의 이름이 인자로 주로 사용된다.



###  리턴값




없음



###  실행 예제


```cpp


/*존재하지 않는 파일(unexist.ent) 을 열어 오류를 발생시켜 perror 함수를 호출시킨다.이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/perror/에서 가져왔습니다.*/#include <stdio.h>int main (){    FILE * pFile;    pFile=fopen ("unexist.ent","rb");    if (pFile==NULL)        perror ("The following error occurred");    else        fclose (pFile);    return 0;}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F121F7E144B6EEFA0172711)




###  연관된 함수



*  [clearerr](http://itguru.tistory.com/50)  :  오류 표시자들을 초기화한다.

*  [ferror](http://itguru.tistory.com/52)  :  오류 표시자를 검사한다.






