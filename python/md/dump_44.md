----------------
title : C 언어 레퍼런스 - getchar 함수
cat_title :  getchar
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ getchar


```info

#include <stdio.h> // C++ 의 경우 <cstdio>int getchar ( void );
```


`stdin` 에서 한 문자를 가져온다.

표준 입력에서 다음 문자를 리턴한다.
이는 인자가 `stdin` 인 `getc` 함수와 동일하다.



###  인자

없음

###  리턴값

읽어들인 문자를 `int` 값으로 리턴한다.

만일 파일 끝에 도달하거나, 읽기 오류가 발생한다면 함수는 `EOF` 를 리턴하고 이에 대응하는 오류혹은 `EOF` 표시자가 설정된다. 여러분은 [ferror](http://itguru.tistory.com/52)이나 [feof](http://itguru.tistory.com/51)함수를 통해 각각 어떤 오류가 발생했는지, 파일 끝에 도달하였는지 알 수 있다.



###  실행 예제




```cpp
/* 한 문자를 읽는다.*/
#include <stdio.h>
int main ()
{
    char ch = getchar();
    printf("문자 : %c \n", ch);

    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F1465C7154B685E0307EE2B)

`getchar` 함수는 아래와 같이 버퍼를 비우는데에도 종종 사용될 수 있다.

```cpp
/* 버퍼 비우기 */
#include <stdio.h>
int main ()
{
    int i;
    char c;

    scanf("%d", &i);
    getchar();
    scanf("%c", &c);

    printf("입력한 문자 : %c \n", c);
return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F190939164B685E7E02CEC7)

만일 위 프로그래램에서 `getchar()` 부분을 지워버린다면 `scanf` 는 문자 `c` 를 사용자로 부터 입력받지 않고 지나갈 것이다. 왜냐하면 이전에 호출한 `scanf` 에 의해 버퍼에 이미 `\n` 이 남아 있었기 때문이다. 

하지만 `getchar` 함수를 호출함으로 통해 버퍼에 남아 있던 `\n` 을 날려버릴 수 있었다. 자세한 내용을 알고 싶다면 [여기를 클릭하세요](http://itguru.tistory.com/32)

물론 `getchar` 함수를 호출하지 않고도 `scanf` 함수 만으로 문제를 해결할 수 있다. [자세한 내용은 여기를 클릭하세요](http://itguru.tistory.com/36)

```cpp
/*

타이프기 처럼 한 문장을 입력하면 아래 써진다.
. 이 입력되면 입력이 종료된다.
다음 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/getchar/
에서 가져왔습니다.

*/
#include <stdio.h>
int main ()
{
    char c;
    puts ("Enter text. Include a dot ('.') in a sentence to exit:");
    do {
        c=getchar();
        putchar (c);
    } while (c != '.');

    return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F173C481F4B685F6E015E38)





###  연관된 함수



*  [getc](http://itguru.tistory.com/41)  : 스트림에서 한 문자를 가져온다.

* `putchar ` : `stdout` 에 한 문자를 쓴다.

*  [scanf](http://itguru.tistory.com/36)  :  형식 문자열에 정의된 방법에 따라 데이터를 `stdin` 에서 읽는다.






