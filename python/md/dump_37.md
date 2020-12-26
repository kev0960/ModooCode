----------------
title : C 언어 레퍼런스 - fgetc 함수
cat_title :  fgetc
publish_date : 2010-01-28
ref_title : fgetc
path : /C Reference/stdio.h
--------------


```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ fgetc

```cpp
#include <stdio.h> // C++ 에서는 <cstdio>

int fgetc ( FILE * stream );
```



스트림(stream) 에서 문자 하나를 읽어온다

인자로 전달한 `stream` 의 파일 위치 지정자가 가리키는 문자를 리턴한다. 이 때 파일 위치 지정자는 그 다음 문자를 가리키게 된다. `fgetc` 와 `getc` 는 동일하지만 `getc` 의 경우 매크로의 형태로 만들어져 있기 때문에 인자가 만일을 위해 식이 아닌 형태여야 한다.



###  인자



스트림(stream)

`fgetc` 가 읽어들인 스트림의 `FILE` 객체에 대한 포인터



###  리턴값

읽어들인 문자는 `int` 값으로 리턴된다.

만일 파일의 끝(End-of-File) 에 도달하였거나, 읽는 도중 오류가 발생하였다면 `EOF` 를 리턴하고, 이에 대응하는 오류 표시자나 파일 끝 표시자가 설정된다.

[ferror](http://itguru.tistory.com/52)이나 `feof` 함수를 이용하여 각각 어떤 오류가 발생하였는지, 파일 끝에 도달하였는지 확인할 수 있다.



###  실행 예제




```cpp-formatted
/*

stdin 에서 문자를 입력받는다.

*/
#include <stdio.h>
int main() {
  int i = fgetc(stdin);

  printf("입력 값 : %c \n", i);
  return 0;
}
```

  실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F1521E9184B60618605A0D0)

또다른 예제

```cpp-formatted
/*

myfile.txt 에서의 $ 의 개수를 센다
참고로, http://www.cplusplus.com/reference/clibrary/cstdio/fgetc/
에서 가져온 예제입니다.

*/
#include <stdio.h>
int main() {
  FILE* pFile;
  int c;
  int n = 0;
  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    do {
      c = fgetc(pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose(pFile);
    printf("The file contains %d dollar sign characters ($).\n", n);
  }
  return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F155C96174B6060F23B9824)




###  관련된 함수들



*  [getc](http://itguru.tistory.com/41)   :  스트림에서 문자 한 개를 읽어온다.

*  [fputc](http://itguru.tistory.com/39)  :  스트림에 문자 한 개를 쓴다.

*  [fread](http://itguru.tistory.com/68)  :  스트림에서 데이타 한 블록을 읽어온다.

*  [fscanf](http://itguru.tistory.com/65)  : 스트림에서 형식화 된 데이터를 읽어온다.