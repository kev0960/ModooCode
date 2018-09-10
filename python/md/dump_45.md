----------------
title : C 언어 레퍼런스 - gets 함수
cat_title :  gets
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ gets

```info
#include <stdio.h> // C++ 에서는 <cstdio>

char * gets ( char * str );
```


표준 입력(stdin) 에서 문자열을 가져온다.

표준 입력에서 문자들을 개행 문자 ('\n') 이나 파일 끝(EOF) 를 만나기 전 까지 가져와서 `str` 에 저장한다.
이 때, 개행 문자 ('\n') 은 문자열에 포함되지 않는다.
널 문자 ('\0') 는 문자열 맨 마지막에 자동적으로 추가된다.
참고로 `gets` 함수에서 주의할 점은, 이 함수는 인자가 `stdin` 인 [fgets](http://itguru.tistory.com/38)`` 함수와 다르다는 것이다. 일단 `gets` 는 개행 문자를 문자열에 포함시키지 않지만 [fgets](http://itguru.tistory.com/38)`` 함수는 개행 문자도 포함시킨다. 또한, `gets` 함수는 얼마나 많은 문자를 읽어들일 것인지에 대해 지정하지 않기 때문에 여러분은 `gets` 함수를 사용시 충분한 크기의 `str` 배열을 만들어서 버퍼 오버플로우를 방지해야 한다.



###  인자




`str`

`C` 형식의 문자열이 저장될 `char` 배열의 포인터 C 형식의 문자열이 저장될 `char` 배열의 포인터.



###  리턴값




성공적으로 읽어 들였다면 `str` 을 리턴한다.
만일 아무런 문자도 읽어들이지 못했는데 `EOF` 에 도달하였다면 `str` 의 내용은 하나도 바뀌지 않고 `NULL` 포인터를 리턴한다.
오류가 발생했다면 `NULL` 포인터가 리턴된다.
여러분은 [ferror](http://itguru.tistory.com/52)`` 이나 [feof](http://itguru.tistory.com/51)`` 함수를 이용해서 각각 어떤 오류가 발생했는지, `EOF` 에 도달하였는지 알 수 있다.




###  실행 예제




```cpp

/* 사용자로 부터 문자열을 입력받는다.  */#include <stdio.h>int main (){    char str[100];    printf("당신의 이름은 무엇인가요? ");    gets(str);    printf("만나서 반가워요 %s 님 \n", str);    return 0;}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F11671B284B698C0E2350EE)




###  연관된 함수





*  [fgets](http://itguru.tistory.com/38)  :  스트림에서 문자열을 읽어온다.

*  [getchar](http://itguru.tistory.com/44)  :  표준 입력(stdin)에서 문자를 읽어온다.

*  [scanf](http://itguru.tistory.com/36)  :  표준 입력에서 데이터를 형식에 맞추어 읽어온다.






