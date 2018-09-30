----------------
title : C 언어 레퍼런스 - putc 함수
cat_title :  putc
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ putc

```info


#include <stdio.h> // C++ 에서는 <cstdio>int putc ( int character, FILE * stream );
```


스트림에 문자를 쓴다.
스트림에 한 문자를 쓴 뒤 위치 표시자 (Position indicator) 를 한 칸 전진시킨다.
문자가 스트림에 어떤 부분에 쓰일지는 위치 표시자에 의해 정해진다.
`putc` 는 [fputc](http://itguru.tistory.com/39)와 동일하며 [fputc](http://itguru.tistory.com/39)와 마찬가지로 스트림을 인자로 받지만 `putc` 는 매크로의 형태로 구현되어 있기 때문에 인자를 전달할 때, 복잡한 식을 사용하지 않는 것이 좋다.
`putchar` 함수는 `putc` 와 비슷한 작업을 하지만 `stream` 인자를 받지 않고 무조건 `stdout` 에 쓴다.



###  putc




`character`

스트림에 쓰여질 문자. 이 때 `int` 로 형변환되어 전달된다.

`stream`

문자가 쓰여질 스트림의 `FILE` 객체를 가리키는 포인터



###  리턴값




만일 오류가 없다면 스트림에 쓰인 문자가 똑같이 반환된다.
오류가 발생한다면 `EOF` 가 리턴되고 오류 표시자가 설정된다.



###  예제




```cpp
/* stdout (표준 출력) 에 p 를 쓴다.*/
#include <stdio.h>
int main ()
{
    char ch = 'p';

    putc(ch, stdout);

    return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F1666211A4B6AB39234C27A)


```cpp
/*

alphabet.txt 에 (없다면 파일을 생성해서) A 부터 Z 까지 쓴다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/putc/
에서 가져왔습니다.

 */
#include <stdio.h>
int main ()
{
    FILE * pFile;
    char c;

    pFile=fopen("alphabet.txt","wt");
    for (c = 'A' ; c <= 'Z' ; c++) {
        putc (c , pFile);
    }
    fclose (pFile);
    return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F20227D1B4B6AB3446E7630)




###  연관된 함수





* putchar  :   표준 출력(stdout) 에 문자를 쓴다.



*  [fputc](http://itguru.tistory.com/39)  :  스트림에 문자를 쓴다.



*  [getc](http://itguru.tistory.com/41)   :  스트림에서 문자를 받는다.



*  [fwrite](http://itguru.tistory.com/69)  :  스트림에 데이터 블록을 쓴다.



*  [fprintf](http://itguru.tistory.com/64)  :  스트림에 형식에 맞춘 데이터를 쓴다.







