

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


memmove
```info
#include <string.h> // C++ 에서는 <cstring>

void * memmove ( void * destination, const void * source, size_t num );
```


메모리 블록을 옮긴다.

source 가 가리키는 곳 부터 num 바이트 만큼을 destination 이 가리키는 곳으로 옮긴다. 이 때, 메모리 복사 수행시, 중간에 버퍼를 이용하게 되므로 destination 과 source 의 해당하는 범위가 겹쳐져도 문제는 없다. 
이 때, destination 와 source 가 가리키는 타입은 위 함수에서는 상관이 없다. 오직 단순하게 이진 데이터 만을 복사하는 것이기 때문이다. 또한 위 함수는 source 의 널 종료 문자를 확인하지 않는다. 언제나 정확히 num 바이트 만큼 복사를 수행한다.
오버플로우를 방지하기 위해 destination 와 source 가 가리키는 배열 모두 적어도 num 바이트 이상은 되어야 한다. 

###  인자
### 
destination

데이터가 복사될 곳을 가리키는 포인터로, 언제나 void* 형이다. 

source

복사할 데이터가 있는 위치를 가리키는 포인터로 언제나 void* 형이다. 

num

복사할 바이트 수 이다.

###  리턴값
### 
destination 이 리턴된다.

###  실행 예제
### 
```cpp
/* 

memmove can be very useful...... 에서, 문자열 시작 주소 부터 15 번째 부분 부터 11 바이트, 즉 "very useful" 을 문자열 시작 주소 부터 20 번째 부분, 즉 "use~" 부분에 복사해 넣는다. 다시말해, 위 문자열은 "memmove can be very very useful." 이 된다. 
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/memmove/
에서 가져왔습니다. 

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] = "memmove can be very useful......";
    memmove (str+20,str+15,11);
    puts (str);
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F19158D034BDD5D6A30A5D5)



###  연관된 함수
### 
* memcpy  :  메모리 블록을 복사한다. 
memchr  :  메모리 블록에 문자를 위치시킨다. 
memcmp  :  두 개의 메모리 블록을 비교한다. 
memset  :  메모리 블록을 채운다. strncpy  :  문자열에서 문자들을 복사한다.
공감sns신고저작자표시'C Reference > string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strcat 함수(0)
2010.05.21C 언어 레퍼런스 - strncpy 함수(5)
2010.05.09C 언어 레퍼런스 - strcpy 함수(8)
2010.05.02C 언어 레퍼런스 - memmove 함수(7)
2010.04.25C 언어 레퍼런스 - memcpy 함수(11)
2010.04.24C 언어 레퍼런스 - string.h (cstring) 헤더파일(2)
2010.04.24

