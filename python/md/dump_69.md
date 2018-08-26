

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


fwrite
```cpp
#include <stdio.h> // C++ 에서는 <cstdio>

size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
```


스트림에 데이터 블록을 쓴다. 
스트림에 count 개의 원소를 가지는 배열을 쓴다. 각각의 원소는 size 바이트이고, 그 배열은 ptr 이 가리키는 것이다. 
따라서, 전체 스트림에 써지는 바이트 수는 size * count 가 된다. 
전체 스트림에 써지는 바이트 수 만큼 위치 지정자가 증가하게 된다. 

###  인자
### 
ptr

스트림에 쓰여질 배열을 가리키는 포인터. 


size

그 배열의 각각의 원소의 크기

count

그 배열의 원소의 수 이다. 이 때, 각 원소의 크기는 size 바이트 이다. 

stream

내용을 쓸 스트림을 가리키는 FILE 포인터

###  리턴값
### 
스트림에 성공적으로 써진 전체 원소의 개수는 size_t 형으로 리턴된다. 이는 정수형이다. 만일, 쓰여진 바이트 수와 count 의 값이 다르다면 오류가 발생되게 된다. 

###  실행 예제
### 
```cpp
/*

myfile.bin 에 "xyz" 라는 문자열을 출력한다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fwrite/
에서 가져왔습니다.

 */

#include <stdio.h>
int main ()
{
    FILE * pFile;
    char buffer[] = { 'x' , 'y' , 'z' };
    pFile = fopen ( "myfile.bin" , "wb" );
    fwrite (buffer , 1 , sizeof(buffer) , pFile );
    fclose (pFile);
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F1602181D4BC9A451538037)


파일의 모습

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F15745F1D4BC9A452724628)



###  연관된 함수
### 
* fread  :  스트림에서 데이터 블록을 읽어온다. 
fprintf : 스트림에 형식에 맞추어 출력한다.putc  :  스트릠에 문자를 쓴다.fputc  : 스트림에 문자를 쓴다. 
공감sns신고저작자표시'C Reference > stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - fseek 함수(0)
2010.04.24C 언어 레퍼런스 - fgetpos 함수(0)
2010.04.18C 언어 레퍼런스 - fwrite 함수(1)
2010.04.11C 언어 레퍼런스 - fread 함수(2)
2010.03.21C 언어 레퍼런스 - sprintf 함수(3)
2010.02.22C 언어 레퍼런스 - fscanf 함수(2)
2010.02.22

