----------------
title : C 언어 레퍼런스 - ferror 함수
cat_title :  ferror
publish_date : 2010-02-05
--------------

```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ ferror

```info-format
#include <stdio.h> // C++ 에서는 <cstdio>
int ferror ( FILE * stream );
```

오류 표시자를 검사한다.

인자에서 지정한 스트림의 오류 표시자가 설정 되어 있는지 확인하고, 설정 되어 있다면 0 이 아닌 값을 리턴한다.

보통 오류 표시자는 이전의 스트림 작업에서 오류가 발생했을 때 설정된다.

###  인자

`stream`

오류 표시자의 값을 확인할 스트림의 `FILE` 객체를 가리키는 포인터

###  리턴값

만일 스트림의 오류 표시자가 설정되어 있다면 0 이 아닌 값을 리턴한다.
그렇지 않을 경우 0 을 리턴한다.

###  실행 예제

```cpp-formatted
/*

읽기 전용으로 열은 파일에 fputc 를 이용해 강제적을 파일에 쓰기를 함으로써 오류를
발생시켜 ferror 함수에 의해 어떻게 처리되는지 살펴본다. 이 예제는
http://www.cplusplus.com/reference/clibrary/cstdio/ferror/ 에서 가져왔습니다.
*/
#include <stdio.h>
int main() {
  FILE* pFile;
  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");

  else {
    fputc('x', pFile);
    if (ferror(pFile)) printf("Error Writing to myfile.txt\n");
    fclose(pFile);
  }
  return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F12149C1E4B6EEBF2A949BD)



###  참고 자료

*  [feof](http://itguru.tistory.com/51)  :  파일 끝 표시자를 검사한다.
*  [clearerr](http://itguru.tistory.com/50):  오류 표시자들을 클리어(clear) 한다.
*  [perror](http://itguru.tistory.com/53)  :  오류 메세지를 표시한다.