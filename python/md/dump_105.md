----------------
title : C 언어 레퍼런스 - strerror 함수
cat_title :  strerror
publish_date : 2010-12-12
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ strerror

```info-format
#include <string.h> // C++ 에서는 <cstring>

char * strerror ( int errnum );
```

오류 메세지 문자열을 가리키는 포인터를 얻어온다.
`errnum` 의 값을 통해 발생하였던 오류에 알맞은 오류 메세지를 가리키는 포인터를 리턴한다. 이 때 리턴되는 포인터는 [문자열 리터럴](http://itguru.tistory.com/33)을 가리키고 있기 때문에 그 내용이 바뀔 수 없다. 참고로 `strerror` 에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.



###  인자




`errnum`

오류 번호



###  리턴값




오류 번호에 해당하는 오류 문자열을 가리키는 포인터



###  놀라운 사실




이 함수는 C 표준 함수 중에서이름에 `r` 이 가장 많이 포함되어 있는 함수이다. 무려 `r` 이 4 개나 있다.




###  실행 예제


```cpp-formatted
/*

존재하지 않는 파일 unexist.ent 를 열라고 해 오류가 발생한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strerror/
에서 가져왔습니다.

 */
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE* pFile;
  pFile = fopen("unexist.ent", "r");
  if (pFile == NULL)
    printf("Error opening file unexist.ent: %s\n", strerror(errno));
  return 0;
}
```

실행 결과




![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F146390194D039BFE0DBDB8)



###  참고 자료

*  [perror](http://itguru.tistory.com/53):  오류 메세지를 출력한다.