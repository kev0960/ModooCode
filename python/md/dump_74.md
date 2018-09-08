----------------
title : C 언어 레퍼런스 - ftell 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ ftell

```info
#include <stdio.h> // C++ 에서는 <cstdio>

long int ftell ( FILE * stream );

```

스트림의 위치 지정자의 현재 위치를 구한다.
이진(binary) 스트림의 경우, 리턴된 값이 파일의 시작 부분에서 부터 현재 위치까지의 바이트 수를 말한다.
텍스트 스트림의 경우 위의 경우와는 조금 다르게,파일의 시작 부분으로 부터 현재 위치 까지의 바이트 수라고 단정짓기 힘들다.
(이진 스트림과 텍스트 스트림에 대해 자세히 알고 싶다면 [stdio.h](http://itguru.tistory.com/34)`` 를 참조) 하지만, 이 리턴된 값을 가지고 [fseek](http://itguru.tistory.com/72)`` 함수를 이용하면 현재의 위치로 파일 위치 포인터를 설정할 수 있다.



###  인자


`stream`

작업을 수행할 스트림의 `FILE` 객체를 가리키는 포인터



###  리턴값




성공적으로 수행하였다면 현재의 위치 포인터가 가진 값이 리턴된다.
만일 오류가 발생하였다면 `NULL` 이 리턴되고, 전역 변수 `errno` 의 값은 양수로 설정된다. [perror](http://itguru.tistory.com/53)함수를 통해 `errno` 의 값을 해석할 수 있다.



###  실행 예제




```cpp
/*

파일 전체의 크기를 읽어온다. pFile 을 파일 끝으로 선택한 뒤, ftell 함수를 통해서 파일 처음 부터 pFile 까지, 즉 파일 처음 부터 끝 까지의 바이트 수를 계산한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstdio/ftell/
에서 가져왔습니다.

 */
#include <stdio.h>
int main ()
{
    FILE * pFile;
    long size;

    pFile = fopen ("myfile.txt","rb");

    if (pFile==NULL)
        perror ("Error opening file");
    else
    {
        fseek (pFile, 0, SEEK_END);
        size=ftell (pFile);
        fclose (pFile);
        printf ("Size of myfile.txt: %ld bytes.\n",size);
    }
    return 0;
}
```


`myfile.txt` 의 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1858FF104BD2ACF234484A)

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F134E27104BD2ACF2879D3F)




###  연관된 함수

*  [fseek](http://itguru.tistory.com/72)  :  스트림 위치 지정자를 다시 조정한다.
*  [fgetpos](http://itguru.tistory.com/70)`` :  스트림의 위치 지정자의 현재 위치를 구한다.
*  [rewind](http://itguru.tistory.com/75)  :  스트림 위치 지정자를 맨 처음으로 설정한다.







