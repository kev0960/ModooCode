----------------
title : C 언어 레퍼런스 - freopen 함수
cat_title :  freopen
publish_date : 2010-02-13
ref_title : freopen
path : /C Reference/stdio.h
--------------


#@ freopen

```cpp
#include <stdio.h> // C++ 에서는 <cstdio>

FILE * freopen ( const char * filename, const char * mode, FILE * stream );
```


스트림을 다른 파일이나 방식(mode)으로 다시 연다. (물론 둘 다 바꿔도 된다)

`freopen` 함수는 먼저 세번째 인자로 전달된 스트림에 해당하는 파일을 닫아버립니다(`close`). 그 후, 그 파일이 성공적으로 닫혔든 안닫혔든 간에, `freopen` 함수는 첫번째 인자로 전달된 파일 이름에 해당하는 파일을 두번째 인자로 전달된 방식(mode)에 맞게 엽니다.

이 함수는 특히 이미 정의된 스트림들, 예를 들면 표준 입력(stdin) 이나 표준 출력(stdout), 표준 오류(stderr) 와 같은 스트림들을 특정한 파일에 해당하는 스트림으로 변경할 수 있습니다.


###  인자

`filename`

열을 파일의 이름을 포함하는 C 문자열. 특히, `freopen` 함수가 실행되는 환경에 따라 파일에 경로에 대한 정보도 포함할 수 있다.

(예를 들어 `Windows` 의 경우 `filename` 에 "C:\\a.txt" 를 전달하면 C 드라이브에 `a.txt` 파일을 열 게 된다. 이 때, \ 를 두 개 붙인 이유는 C 언어에서 \ 하나는 **탈출 문자(escape character)** 로 사용되기 때문이다)

만일 인자가 널 포인터라면 `freopen` 함수는 세번째 인자로 전달된 스트림과 연관되어 있던 파일의 열기 방식 만을 두 번째 인자로 전달된 방법으로 변경한다. (Windows 에선 이것이 지원되지 않으므로 사용하지 않도록 한다.. msdn 참조)

`mode`

C 문자열로 파일 접근 방식에 대한 정보를 포함해야 한다. 이 모드는 다음이 될 수 있다 C 문자열로 파일 접근 방식에 대한 정보를 포함해야 한다. 이 모드는 다음이 될 수 있다.


|mode|설명|
|------|------|
|"r"|파일을 읽기 형식으로 연다. 이 때, 파일은 반드시 존재해야 한다.|
|"w"|파일을 쓰기 형식으로 연다. 만일 동일한 파일이 이미 존재하고 있다면 그 파일의 내용은 모두 지워진 후 새롭게 생긴 빈 파일로 간주하며, 파일이 존재하고 있지 않는다면 빈 파일을 새롭게 생성한다.|
|"a"|파일을 덧붙이기(append) 형식으로 연다. 쓰기 작업은 파일 끝에 데이타를 덧붙일 것이다. 만일 파일이 존재하지 않는다면 새로 생성된다.|
|"r+"|파일을 읽기 및 쓰기 형식으로 연다. 이 때, 파일은 반드시 존재해야 한다.|
|"w+"|파일을 읽기 및 쓰기 형식으로 연다. 만일 동일한 파일이 이미 존재하고 있다면 그 파일의 내용은 모두 지워진 후 새롭게 생긴 빈 파일로 간주하며, 파일이 존재하고 있지 않다면 빈 파일을 새로 생성하게 된다.|
|"a+"|파일을 읽기 및 덧붙이기(append) 형식으로 연다. 지정한 파일이 존재하지 않는다면 새롭게 생성된다. 모든 쓰기 작업은 파일의 맨 끝에서 진행되며 기존의 파일 내용들에 덮혀씌여지지 않는다. 여러분은 읽기 작업에서는 [fseek](http://itguru.tistory.com/72)이나 [rewind](http://itguru.tistory.com/75)함수 등을 이용하여 파일 위치 포인터를 원하는 대로 움직일 수 있지만, 쓰기 작업에서는 위치 포인터를 언제나 파일 맨 끝으로 이동 시킬 것이다.|


또한 뒤에 `b` 를 붙인다면 바이너리 형식으로 파일을 열게 된다. (아무것도 안붙이면 자동적으로 텍스트 파일 형식으로 열린다). 파일 열기 방식에 대한 자세한 정보는 [fopen](http://itguru.tistory.com/58)함수를 참조하면 된다.

`stream`

작업을 수행할 스트림의 `FILE` 객체에 대한 포인터



###  리턴값

만일 파일이 성공적으로 열렸다면 이 함수는 세번째 인자로 전달되었던 스트림 포인터를 리턴하게 된다.
그렇지 않을 겨우 널 포인터가 리턴된다.

###  실행 예제

```cpp-formatted
/*

a.txt 를 쓰기 형식으로 열어서 Hello, Psi 를 쓴 뒤, 다시 읽기 형식으로 열어서 그
내용을 읽어 출력한다.

*/
#include <stdio.h>
int main() {
  FILE *fp;
  char str[100];

  fp = fopen("C:\\a.txt", "w");
  fputs("Hello, Psi!!", fp);

  fp = freopen("C:\\a.txt", "r", fp);
  fgets(str, 99, fp);

  printf("%s", str);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F171C77104B76B24B4F80E7)


```cpp-formatted
/*

표준 출력(stdout) 을 myfile.txt 의 스트림으로 변경한다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/freopen/
에서 가져왔습니다.

 */
#include <stdio.h>
int main() {
  freopen("myfile.txt", "w", stdout);
  printf("This sentence is redirected to a file.");
  fclose(stdout);
  return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F13251E104B76B24CB820E6)

파일에 쓰여진 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F120B55104B76B24DB79354)





###  참고 자료

* [fopen](http://itguru.tistory.com/58)  :  파일을 연다
* [fclose](http://itguru.tistory.com/54):  파일을 닫는다.