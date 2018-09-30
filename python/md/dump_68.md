----------------
title : C 언어 레퍼런스 - fread 함수
cat_title :  fread
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ fread



```cpp
#include <stdio.h> // C++ 에서는 <cstdio>

size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
```


스트림에서 데이터 블록을 읽어온다.
스트림에서 `count` 개의 원소를 가지는 배열을 읽어온다. 이 때, 각 원소의 크기는 `size` 바이트 이고 `ptr` 이 가리키는 배열에 넣게 된다. (이 때, `count` 와 `size` 와 `ptr` 은 모두 `fread` 의 각각의 인자들을 의미한다)
스트림의 위치 표시자는 읽어들인 바이트 수 만큼 증가하게 된다.
전체 읽어들인 바이트 수는 만일 성공적일 경우, (size * count) 가 된다.



###  인자




`ptr`

`size * count` 의 크기를 가지는 배열을 가리키는 포인터

`size`
읽어들일 원소의 크기로 단위는 바이트 이다. 예를 들어 `size` 가 4 이면 하나의 원소의 크기는 4 바이트 임을 일컫는다.

`count`
읽어들일 원소들의 개수로 각 원소의 크기는 `size` 바이트 이다.

`stream`
데이터를 입력받을 스트림의 `FILE` 객체를 가리키는 포인터



###  리턴값




만일 성공적으로 지정한 원소의 개수 만큼 읽어들였다면 읽어들인 원소의 개수가 `size_t` 형으로 리턴된다. 참고로 `size_t` 형은 정수 타입이다. 만일 읽어들인 개수가 `count` 인자에서 지정한 것과 다르거나, `End OF File` 에 도달하였다면 오류가 발생한다. 이 때, 여러분은 [ferror](http://itguru.tistory.com/52)함수나 [feof](http://itguru.tistory.com/51)함수를 이용하여 어떠한 오류인지를 파악할 수 있다.



###  실행 예제


```cpp
/*

myfile.bin 의 내용을 읽어 들여와 동적으로 할당한 buffer 에 저장한다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fread/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE * pFile;
    long lSize;
    char * buffer;
    size_t result;

    pFile = fopen ( "myfile.bin" , "rb" );
    if (pFile==NULL)
    {
        fputs ("File error",stderr);
        exit (1);
    }

    // 파일의 크기를 ISize 에 저장한다.
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);

    // 전체 파일의 내용을 받을 수 있을 정도의 크기로 메모리를 할당한다.
    buffer = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL)
    {
        fputs ("Memory error",stderr);
        exit (2);
    }

    // 그 파일의 내용을 버퍼에 저장한다.
    result = fread (buffer,1,lSize,pFile);
    if (result != lSize)
    {
        fputs ("Reading error",stderr);
        exit (3);
    }

    /* 이제 파일의 모든 내용은 버퍼에 들어가게 된다. */

    // 종료
    fclose (pFile);
    free (buffer);
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F154D38104BA61B89A274D0)

###  연관된 함수

* `fwrite` : 스트림에 데이터 블록을 쓴다.
*  [fgetc](http://itguru.tistory.com/37): 스트림에서 한 문자를 가져온다.
*  [fscanf](http://itguru.tistory.com/65): 스트림에서 형식에 맞추러 데이터를 읽어온다.







