----------------
title : C 언어 레퍼런스 - clearerr 함수
cat_title :  clearerr
publish_date : 2010-02-05
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ clearerr

```info-format
#include <stdio.h> // C++ 에서는 <cstdio>

void clearerr ( FILE * stream );
```


오류 표시자를 초기화(clear) 한다.

스트림의 `EOF` 표시자와 오류 표시자를 모두 재설정(reset) 한다.

만일 스트림 함수가 오류 혹은 파일끝에 도달하였기 때문에 실패한다면, 이 두 개의 표시자들 중 하나가 설정된다. 이 표시자들은 `rewind, fseek, fsetpos` 함수 들 중 어느 하나가 호출 되기 전 까지 변경되지 않는다.



###  인자

`stream`

작업을 수행할 스트림의 `FILE` 객체를 가리키는 포인터

###  리턴값

없음

###  실행 예제

```cpp-formatted
/* 인위적으로 오류를 발생시킨 뒤 이 오류가 clearerr 에 의해 어떻게 처리되는지
살펴본다.

이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/clearerr/에서
가져왔습니다. */
#include <stdio.h>
int main() {
  FILE* pFile;
  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    fputc('x', pFile);
    if (ferror(pFile)) {
      printf("Error Writing to myfile.txt\n");
      clearerr(pFile);
    }
    fgetc(pFile);
    if (!ferror(pFile)) printf("No errors reading myfile.txt\n");
    fclose(pFile);
  }
  return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F143FEB114B6AED222A25EB)

이 예제에서 `myfile.txt` 를 읽기 전용 (r) 로 열었으나, `fputc` 함수를 이용해 이 파일에 쓰기를 시도하였기 때문에 오류가 발생하였다.

따라서 첫번째 `if` 문에서 *Error Writing to myfile.txt\n* 이 출력되었지만, `clearerr` 함수를 이용하여 오류 플래그를 비워버렸다. 따라서 아래 `if` 문에서 성공적으로 *No errors reading myfile.txt\n* 가 출력될 수 있었다.


###  참고 자료

*  [feof](http://itguru.tistory.com/51)   :  파일 끝 표시자(EOF) 를 검사한다.
*  [ferror](http://itguru.tistory.com/52):  오류 표시자를 검사한다.
* `rewind ` :  위치 표시자를 처음으로 되돌린다.