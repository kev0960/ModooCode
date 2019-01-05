----------------
title : C 언어 레퍼런스 - fgets 함수
cat_title :  fgets
publish_date : 2010-01-28
--------------

```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ fgets


```info
#include <stdio.h> // C++ 의 경우 <cstdio>
char * fgets ( char * str, int num, FILE * stream );
```

스트림(stream)에서 문자열을 받는다.

스트림에서 문자열을 받아서 `(num - 1)` 개의 문자를 입력 받을 때 까지나, 개행 문자나 파일 끝(End-of-File) 에 도달할 때 까지 입력 받아서 C 형식의 문자열로 저장한다. 개행 문자는 `fgets` 로 하여금 입력을 끝나게 하지만 이 문자 역시 `str` 에 저장한다. `NULL` 문자는 자동적으로 마지막으로 입력받은 문자 뒤에 붙는다.

참고적으로 `fgets` 함수는 [scanf](http://itguru.tistory.com/36)함수와는 달리 오직 개행 문자에 의해서만 입력이 끝나기 때문에 띄어쓰기가 있는 문자열도 입력 받을 수 있다. 반면에 `scanf` 함수의 경우 개행 문자 뿐만이 아니라 ' ' 와 '\t' 에 의해서도 입력이 끝나기 때문에 띄어쓰기가 있는 문자열은 입력 받을 수 없다.



###  인자


`str`

읽어들인 문자열을 저장할 `char` 배열을 가리키는 포인터.

`num`

마지막 `NULL` 문자를 포함하여, 읽어들일 최대 문자 수. 다시 말해 이 값이 10 이면 컴퓨터는 최대 9 문자를 입력 받는다.

`stream`

문자열을 읽어들일 스트림의 `FILE` 객체를 가리키는 포인터. 특히, 표준 입력(stdin) 에서 입력을 받으려면 여기에 `stdin` 을 써주면 된다. (예를 들어 `fgets (str, 100, stdin);` 과 같이)



###  리턴값




성공적으로 읽어들였다면 함수는 `str` 을 리턴한다.

만일 파일 끝에 도달하였는데 아무런 문자도 읽어들이지 않았다면 `str` 의 내용은 변하지 않고 그 대신 `null` 포인터가 리턴된다.

또한 오류가 발생해도 `null` 포인터가 리턴된다.

[ferror](http://itguru.tistory.com/52)함수나 [ feof](http://itguru.tistory.com/51)를 사용해서 각각 어떤 오류가 발생하였는지, 파일 끝에 도달하였는지 알 수 있다.



###  실행 예제


```cpp-formatted
/* 화면에서 문자열을 읽어들인다. */

#include <stdio.h>
#define MAX_STR_SIZE 100
int main() {
  char str_read[MAX_STR_SIZE];
  fgets(str_read, MAX_STR_SIZE, stdin);
  printf("읽어들인 문자열 : %s \n", str_read);
  return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F1349861C4B6069D5B11BBE)

이 때 유의해서 볼 점은 `str_read` 에 개행 문자도 입력 되어서 `printf` 문 출력결과에서 개행이 두 번 되었다는 점을 볼 수 있다.

```cpp-formatted
/*

myfile.txt 에서 읽어들인 문자열을 출력한다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fgets/
에서 가져왔습니다.

*/
#include <stdio.h>
int main() {
  FILE* pFile;
  char mystring[100];

  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    fgets(mystring, 100, pFile);
    puts(mystring);
    fclose(pFile);
  }
  return 0;
}
```

위 예제는 `myfile.txt` 의 첫 번째 문장을 입력 받되 최대 100 문자만 입력 받는다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F123F321D4B606A8F0198ED)



###  관련된 함수들





*  [fputs](http://itguru.tistory.com/40):   스트림에 문자열을 쓴다.

*  [fgetc](http://itguru.tistory.com/37):   스트림에서 문자 하나를 읽어온다.

*  [gets](http://itguru.tistory.com/45)  :  표준 입력(stdin) 에서 문자열을 읽어온다.