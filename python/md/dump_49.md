----------------
title : C 언어 레퍼런스 - ungetc 함수
cat_title :  ungetc
publish_date : 2010-02-04
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ ungetc

```info
#include <stdio.h> // C++ 에서는 <cstdio>

int ungetc ( int character, FILE * stream );
```


스트림에 문자를 다시 집어 넣는다(unget)

스트림에 마지막으로 문자가 읽어들여졌던 자리에 문자(`ungetc` 함수에 인자로 전달된 character)가 말그대로 들어가고, 파일 위치 표시자가 감소하여 이전 위치를 가리키게 한다. 따라서, 다음 읽기 작업에서는 방금 스트림에 집어 넣어졌던 문자가 읽히기 된다.

예를 들면

```cpp-formatted
FILE *fp = fopen("a.txt", "r");
char ch;
getc(fp);
getc(fp);
ungetc('a', fp);
ch = getc(fp);
```

을 한다면 `a.txt` 에 무엇이 들어 있던 간에 `ch` 에는 `a` 가 들어가게 된다. 왜냐하면 `ungetc` 를 실행하기 직전에 위치 표시자의 값은 2 였다.

그런데 `ungetc` 를 호출함으로써 위치 표시자의 값은 1 이 되고, 그 자리에 `a` 가 써지게 된다.

그 후 `getc` 함수를 호출하면 현재 파일 위치 표시자의 문자를 리턴하는데, 여기서 위치 표시자의 값은 1 이고 그 자리에 `a` 가 있으므로 결과적으로 `ch` 에는 `a` 가 들어간다. 물론, `a` 가 써진다는 말은파일에 실질적으로 `a` 가 기록되는 것이 아니라 버퍼에 써지는 것이다.

`unget` 함수를 여러번 호출하게 되면 나중 읽기작업에서 호출된 역순으로 출력된다.예를 들어

```cpp-formatted
ungetc('a', fp);
ungetc('b', fp);

ch = getc(fp);  // ch 에는 b 가 들어간다.
ch = getc(fp);  //  ch 에는 a 가 들어간다.
```

주의할 점은 `unget` 함수를 여러번 호출하여서 중간에 파일 위치 표시자의 값이 0 이 된다면 그 이후에 호출된 `unget` 함수들은 모두 무시된다. 예를 들어

```cpp-formatted
fp = fopen("test.txt", "r");
getc(fp);         // 이 함수 호출 이후 위치 표시자의 값은 1
ungetc('a', fp);  // 이 함수 호출 이후 값은 0
ungetc('b', fp);  // 따라서 버퍼에 b 가 들어갈 수 없다.

ch = getc(fp);  // ch 에는 a 가 들어간다.
printf("%c", ch);
ch = getc(fp);  //  ch 에는 test.txt 의 두 번째 문자가 들어간다.
```

만일 `EOF` 표시자가 설정된 상태에서 이 함수를 호출하면 `EOF` 표시자는 초기화(clear) 된다.

`fseek` 나 `fsetpos` 나 `rewind` 함수를 호출하면 이전에 `unget` 함수에 의해 들어갔었던 문자들이 모두 삭제된다.

만일 `unget` 함수의 `character` 인자로 전달된 값이 `EOF` 라면 입력 스트림에는 아무런 변화가 없게된다.

###  인자




`character`

스트림에 집어 넣을 문자. 이 때, 문자는 `int` 로 형변환 되어 전달된다.

`stream`

문자를 넣을 입력 스트림의 `FILE` 객체를 가리키는 포인터.



###  리턴값




성공적으로 문자가 들어간다면 들어갔던 문자가 리턴된다.
실패한다면 `EOF` 가 리턴되고 스트림에는 아무런 변화가 없게 된다.



###  실행 예제




```cpp-formatted
/*myfile.txt 로 부터 각 문장을 입력 받되  # 로 시작하는 문장은 @ 로 대체해서
 * 입력받는다.이 예제는
 * http://www.cplusplus.com/reference/clibrary/cstdio/ungetc/에서 가져왔습니다.
 */
#include <stdio.h>
int main() {
  FILE* pFile;
  int c;
  char buffer[256];
  pFile = fopen("myfile.txt", "rt");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    while (!feof(pFile)) {
      c = getc(pFile);
      if (c == '#')
        ungetc('@', pFile);
      else
        ungetc(c, pFile);
      fgets(buffer, 255, pFile);
      fputs(buffer, stdout);
    }
  }
  return 0;
}
```

`myfile.txt` 의 내용


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F2040C2284B6ACA04A4744E)

실행 화면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1205D2284B6ACA02032FD1)

위 프로그램 소스에 대해 간단히 설명을 하자면

```cpp-formatted
c = getc(pFile);
if (c == '#')
  ungetc('@', pFile);
else
  ungetc(c, pFile);
```

일단 `getc` 를 통해 `pFile` 에서 문장의 첫번째 문자를 읽어온다. (왜냐하면 밑의 `fgets` 를 통해 개행 문자가 있을 때 까지 읽어오기 때문에 `getc` 는 언제나 문장의 첫번째 문자를 읽어오게 된다) 이 때, 그 문자가 # 이라면 `ungetc('@', pFile)` 을 통해 버퍼에서 현재 '#' 가 들어 있는 위치에 @ 가 들어가게 된다. 따라서

```cpp-formatted
fgets(buffer, 255, pFile);
fputs(buffer, stdout);
```

를 하게 되면 `buffer` 에는 @ 부터 '\n' 이 나올 때 까지, 즉 한 문장의 끝까지 들어가게 된다.

이 때 주목할 점은 `myfile.txt` 의 내용은 전혀 바뀌지 않았다는 것이다. `ungetc` 함수는 단지 버퍼의 내용만을 조작하는 함수 이므로 `myfile.txt` 의 # 들은 결코 @ 로 바뀌지 않는다.



###  연관된 함수





*  [getc](http://itguru.tistory.com/41):  스트림에서 문자를 받는다.



*  [fgetc](http://itguru.tistory.com/37):  스트림에서 문자를 받는다.

*  [putc](http://itguru.tistory.com/46)  :  스트림에 문자를 쓴다.