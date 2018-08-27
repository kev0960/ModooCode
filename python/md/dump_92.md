----------------
title : C 언어 레퍼런스 - memchr 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?
```


memchr




```info
#include <string.h> // C++ 에서는 <cstring>const void * memchr ( const void * ptr, int value, size_t num );      void * memchr (       void * ptr, int value, size_t num );
```


메모리 블록에서의 문자를 찾는다.
ptr 이 가리키는 메모리의 처음 num 바이트 중에서 처음으로 value 와 일치하는 값의 주소를 리턴한다.  

참고적으로 위에 나타난 두 함수의 원형은 C++ 에서 정의된 방식으로 경우에 따라 오버로딩 되어서 나타난다. C 에서는 함수 오버로딩이 없기 때문에 다음과 같이 하나의 원형만을 가진다. 

```info
void * memchr ( const void *, int, size_t );
```





###  인자


ptr

검색을 수행할 부분의 시작 주소이다. 

value

찾을 값으로, int 로 값이 전달되지만 함수 내부적으로는 한 바이트씩 비교하기 때문에 이 값은 unsigned char 로 변환되어 사용된다. 

num

검색을 시작한 부분 부터 검색을 수행할 만큼의 바이트 수 



###  리턴값




메모리 블록에서 value 와 일치하는 값이 있다면 그 곳의 주소를 리턴하고 값을 찾지 못한다면 NULL 을 리턴한다. 




###  실행 예제




```cpp
/* str 에서 처음으로 나타나는 'p' 의 위치를 찾는다. 이 예제는http://www.cplusplus.com/reference/clibrary/cstring/memchr/에서 가져왔습니다. */#include <stdio.h>#include <string.h>int main (){    char * pch;    char str[] = "Example string";    pch = (char*) memchr (str, 'p', strlen(str));    if (pch!=NULL)        printf ("'p' found at position %d.\n", pch-str+1);    else        printf ("'p' not found.\n");    return 0;}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F207EAB0F4C5588E0CAACE4)




###  연관된 함수





* 

memcmp
   :  두 메모리 블록을 비교한다.


* strchr
  :  문자열에서 특정한 문자를 검색하되 가장 먼저 나타나는 위치를 구한다.  

* strrchr
  :   
문자열에서 특정한 문자를 검색하되 가장 마지막에 나타나는 위치를 구한다.  







공감sns신고
저작자표시

'C Reference > string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strcspn 함수(4)
2010.08.02C 언어 레퍼런스 - strchr 함수(0)
2010.08.02C 언어 레퍼런스 - memchr 함수(0)
2010.08.01C 언어 레퍼런스 - strxfrm 함수(0)
2010.08.01C 언어 레퍼런스 - strncmp 함수(0)
2010.08.01C 언어 레퍼런스- strcoll 함수(0)
2010.07.10

