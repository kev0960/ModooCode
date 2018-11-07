----------------
title : C 언어 레퍼런스 - feof 함수
cat_title :  feof
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ feof

```info
#include <stdio.h> // C++ 에서는 <cstdio>

int feof ( FILE * stream );
```


파일 끝 표시자(End-of-File indicator)를 검사한다.

인자로 넘겨준 스트림의 파일 끝 표시자를 검사하여 설정(set) 되어 있다면 0 이 아닌 값을 리턴한다.
보통 표시자는 이전의 입출력 작업에 의해 스트림이 파일 끝에 도달하였을 때 설정된다.

[rewind](http://itguru.tistory.com/75)이나 [fseek](http://itguru.tistory.com/72), [fsetpos](http://itguru.tistory.com/73)함수들 중 어느 하나가 성공적으로 위치 표시자의 값을 바꾸기 전 까지, 모든 입출력 작업들은 오류를 리턴하게 된다.

###  인자

`stream`

작업을 수행할 스트림의 `FILE` 객체를 가리키는 포인터.

###  리턴값

인자로 전달된 스트림의 파일 끝 지시자가 설정되어 있다면 0 이 아닌 값을 리턴한다.
그렇지 않을 경우 0 이 리턴된다.

###  실행 예제


```cpp-formatted
/*

myfile.txt 의 총 바이트 수를 센다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/feof/
에서 가져왔습니다.

*/
#include <stdio.h>
int main() {
  FILE* pFile;
  long n = 0;
  pFile = fopen("myfile.txt", "rb");
  if (pFile == NULL)
    perror("Error opening file");

  else {
    while (!feof(pFile)) {
      fgetc(pFile);
      n++;
    }
    fclose(pFile);
    printf("Total number of bytes: %d\n", n - 1);
  }
  return 0;
}
```

`myfile.txt` 의 내용


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F145B2A1B4B6EEADA2826C0)

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F135DE91B4B6EEADA159C42)

만일 파일을 읽어들이다가 파일 끝에 도달하게 되면 `feof` 가 0 이 아닌 값을 리턴하게 되어 `while` 문을 빠져나가게 된다.



###  연관된 함수

* [clearerr](http://itguru.tistory.com/50):  오류 표시자들을 클리어한다.
* [ferror](http://itguru.tistory.com/52)  :  오류 표시자를 검사한다.