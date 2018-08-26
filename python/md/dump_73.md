

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


fsetpos
```info
#include <stdio.h> // C++ 에서는 <cstdio>

int fsetpos ( FILE * stream, const fpos_t * pos );
```


스트림의 파일 위치 지정자(position indicator)를 설정한다. 
스트림의 위치 지정자를 새로운 위치로 변경한다. 위 함수에서 인자로 전달되는 pos 는 fpos_t 객체를 가리키는 포인터로 반드시 이전의 fgetpos 함수의 호출을 통해 값을 가지고 있어야 한다.
파일 끝 지정자는 이 함수의 호출 뒤에 초기화 되며, 만일 이전에 ungetc 함수를 호출하였더라면 이 함수의 호출로 인한 모든 영향도 사라지게 된다. 
또한, 스트림의 읽기 및 쓰기 형식으로 열려있을 경우, 이 함수를 호출함을 통해서 읽기 - 쓰기 모드를 변경할 수 있다. (자세한 내용은 fopen 함수를 참조) 

###  인자
### 
stream

작업을 수행할 스트림의 FILE 객체를 가리키는 포인터 

position

fpos_t 객체를 가리키는 포인터로, 반드시 이전의 fgetpos 함수를 통해서 값을 지니고 있어야 한다. 

###  리턴값
### 
만일 성공적으로 수행하였다면 0 을 리턴한다. 그렇지 않다면 0 이 아닌 값을 리턴하고, 전역 변수인 errno 를 양수로 설정한다. 이 errno 에 설정된 값은 perror 함수를 통해서 무슨 오류인지 확인할 수 있다. 

###  실행 예제
### 
```cpp
/* 

먼저 position 에 myfile.txt 의 맨 처음 부분을 넣은 후 myfile.txt 에 "That is a sample" 을 쓴다. 그 다음에 fsetpos 함수를 호출함으로써 fputs 로 인해 변경되었던 위치 지정자가 다시 파일 맨 앞으로 옮겨진다. 그 후 "This" 를 다시 출력하면 결국 "This is a sample" 이 된다. 
이 예제는 
http://www.cplusplus.com/reference/clibrary/cstdio/fsetpos/
에서 가져왔습니다. 

*/
#include <stdio.h>
int main ()
{
    FILE * pFile;
    fpos_t position;

    pFile = fopen ("myfile.txt","w");
    fgetpos (pFile, &position);
    fputs ("That is a sample",pFile);
    fsetpos (pFile, &position);
    fputs ("This",pFile);
    fclose (pFile);
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F157059164BD2A5DB951099)

myfile.txt 의 모습

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F1701FE164BD2A5DB5B77A4)



###  연관된 함수
### * fgetpos  :  스트림의 현재 위치 지정자 값을 가져온다.fseek  :  스트림 위치 지정자를 다시 조정한다. rewind  :  스트림 위치 지정자를 맨 처음으로 되돌린다.

공감sns신고저작자표시'C Reference > stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - rewind 함수(4)
2010.04.24C 언어 레퍼런스 - ftell 함수(1)
2010.04.24C 언어 레퍼런스 - fsetpos 함수(0)
2010.04.24C 언어 레퍼런스 - fseek 함수(0)
2010.04.24C 언어 레퍼런스 - fgetpos 함수(0)
2010.04.18C 언어 레퍼런스 - fwrite 함수(1)
2010.04.11

