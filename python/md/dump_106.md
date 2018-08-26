

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


strlen
```info
#include <string.h> // C++ 에서는 <cstring>

size_t strlen ( const char * str );
```


문자열의 길이를 구한다.
문자열의 길이는 리턴한다. C 문자열의 길이는 마지막 널 문자에 의해 결정된다. 따라서 strlen 은 문자열의 시작 부터, 널 문자 직전 까지의 문자의 개수를 센다. 

간혹 

```cpp
char mystr[100]="test string";
```


라 되어 있으면 strlen 이 100 을 리턴할 것 같지만 mystr 은 오직 11 개의 문자로만 선언되어 있으므로 11 이 리턴된다. 

###  인자### 

string

C 형식 문자열

###  리턴값### 

문자열의 길이. 참고로 size_t 형으로 선언 되어 있는데 대부분의 string.h 에서는 부호 없는 정수형으로 선언되어 있다. 

###  구현 예### 

```cpp
/* 

이 예제는
http://www.jbox.dk/sanos/source/lib/string.c.html
에서 가져왔습니다. 

*/
size_t strlen(const char *s)
{
  const char *eos = s;
  while (*eos++);
  return (int) (eos - s - 1);
}
```


###  실행 예제
### 
```cpp
/* 

문자열을 하나 입력 받아서 그 길이를 리턴한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strlen/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char szInput[256];
    printf ("Enter a sentence: ");
    gets (szInput);
    printf ("The sentence entered is %u characters long.\n",strlen(szInput));
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1772BF1F4D0420B837D97C)


###  연관된 함수
### * strcmp  :  두 개의 문자열을 비교한다.  
strchr  :  문자열에서 특정한 문자의 첫번째로 나타나는 위치를 찾는다.strrchr  :  문자열에서 특정한 문자의 마지막으로 나타나는 위치를 찾는다. 

공감sns신고저작자표시'C Reference > string.h (cstring)' 카테고리의 다른 글C 언어 레퍼런스 - strlen 함수(0)
2010.12.12C 언어 레퍼런스 - strerror 함수(0)
2010.12.12C 언어 레퍼런스 - memset 함수(5)
2010.11.28C 언어 레퍼런스 - strtok 함수(0)
2010.11.27C 언어 레퍼런스 - strstr 함수(3)
2010.11.27C 언어 레퍼런스 - strspn 함수(0)
2010.11.21

