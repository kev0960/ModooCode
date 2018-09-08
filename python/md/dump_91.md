----------------
title : C 언어 레퍼런스 - strxfrm 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strxfrm

```info
#include <string.h> // C++ 에서는 <cstring>

size_t strxfrm ( char * destination, const char * source, size_t num );
```


`locale` 을 사용해 문자열을 변환한다.
`source` 가 가리키는 C 형식 문자열을 현재 `locale` 에 따라 문자열을 변환한 후 변환한 문자열의 처음 `num` 개 문자를 `destination` 에 복사한다. 이 때,  변환된 문자열의 길이를 리턴하게 된다.  이 함수는 또한 문자열의 길이를 계산하는데 (NULL 은 세지지 않는다) 사용할 수 있는데, `destination` 에 `NULL` 포인터를 넣고, `num` 에 0 을 주면 된다.



###  인자




`destination`

변환된 문자열의 처음 `num` 개 문자가 보관될 곳의 주소값

`source`

변환될 C 형식의 문자열

`num`

`destination` 에 복사할 최대 문자의 수



###  리턴값




변환된 문자열의 길이로 `NULL` 은 세지 않는다.



###  실행 예제


```cpp
/*

strxfrm 을 이용하여 문자열의 길이를 구한다.

 */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[20] = "Hello, World";

    printf("문자열의 길이 : %d \n", strxfrm(NULL, str, 0));

    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F186A6F1C4C54E5888668F1)




###  연관된 함수

*  [strncpy](http://itguru.tistory.com/80)  :  문자열의 일부분을 복사한다.
*  [strncmp](http://itguru.tistory.com/90)  :  두 문자열의 일부분을 비교한다.
*  [strcoll](http://itguru.tistory.com/86)`` :  `locale` 을 사용하여 두 문자열을 비교한다.





