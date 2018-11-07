----------------
title : C 언어 레퍼런스 - memset 함수
cat_title :  memset
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ memset

```info
#include <string.h> // C++ 에서는 <cstring>

void * memset ( void * ptr, int value, size_t num );
```


메모리 블록을 채운다.
`ptr` 로 시작하는 메모리 주소 부터 `num` 개의 바이트를 `value` 값으로 채운다. 이 때, `value` 는 `unsigned char` 로 형변환 된다.



###  인자


`ptr`

값을 채울 메모리의 시작 주소

`value`

채울 값. 인자로는 `int` 로 전달되지만 함수 내부적으로는 `unsigned char` 로 형변환 되어서 사용된다.

`num`

`value` 로 채울 바이트 수



###  리턴값




`ptr` 이 리턴된다.



###  실행 예제


```cpp-formatted
/*

이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/memset/
에서 가져왔습니다.

*/
#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "almost every programmer should know memset!";
  memset(str, '-', 6);
  puts(str);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F19727B194CF1A1D02D9726)




###  연관된 함수





*  [memcpy](http://itguru.tistory.com/77)  :   메모리 블록을 복사한다.
*  [strncpy](http://itguru.tistory.com/80)  :  문자열의 일부분을 복사한다.
*  [memcmp](http://itguru.tistory.com/84):  두 개의 메모리 블록을 비교한다.