----------------
title : C 언어 레퍼런스 - fflush 함수
cat_title :  fflush
publish_date : 2010-02-10
ref_title : fflush
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ fflush

```cpp
#include <stdio.h> // C++ 에서는 <cstdio>

int fflush ( FILE * stream );
```

스트림을 비운다(flush)

만일 함수의 인자로 전달된 스트림이 쓰기 가능하고, 마지막 입출력 작업이 출력 작업이였다면 출력 버퍼에 쓰이지 않고 남아 있던 데이터들은 모두 파일에 쓰이게 된다.

만일 함수의 인자로 전달된 스트림이 읽기 가능하고 마지막 입출력 작업이 입력 작업이였다면, 이 함수가 어떠한 작업을 할지에 대해선 라이브러리에 따라 다르다. 몇몇의 라이브러리에선 입력 버퍼를 비워버리지만(이 때 비운다는 것은 버퍼에 있는 데이터들을 모두 삭제한다는 뜻이다) 이는 표준으로 정해진 것이 아니다.

만일 인자가 널 포인터라면 모든 열린 스트림을 비운다.

이 함수 호출 이후에도 스트림은 열려 있는 상태로 남아있다.

만일 파일이 [fclose](http://itguru.tistory.com/54)를 호출 하건 프로그램이 종료되건 어떤 연유에서 든지 닫히게 된다면 (close), 이 파일에 해당하는 모든 버퍼들은 자동적으로 비워지게 된다.


###  인자

`stream`

작업을 수행할 buffered (스트림의 상태 중 하나로 fully buffered 와 line buffered 를 일컫는다. 자세한 내용은 [stdio.h](http://itguru.tistory.com/34)를 참조) 스트림의 파일 객체를 가리키는 포인터.

###  리턴값

`0` 이 리턴되면 성공적으로 작동되었음을 의미한다 0 이 리턴되면 성공적으로 작동되었음을 의미한다.
오류가 발생하면 `EOF` 가 리턴되고 오류 표시자가 설정된다 ( [feof](http://itguru.tistory.com/51)참조)

###  실행 예제


```cpp-formatted
/*
example.txt 파일을 "r+" 로 오픈하여 "test" 를 쓴 뒤 pFile 버퍼를 비우고 다시
파일로 부터 읽어온다.

이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fflush/에서
가져왔습니다.
*/
#include <stdio.h>
char mybuffer[80];
int main() {
  FILE* pFile;
  pFile = fopen("example.txt", "r+");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    fputs("test", pFile);
    fflush(pFile);
    fgets(mybuffer, 80, pFile);
    puts(mybuffer);
    fclose(pFile);
    return 0;
  }
}
```



실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F202412114B725620428B8C)

파일에 쓰여진 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1560F8134B725637318657)

위 소스 코드가 어떻게 작동하는지 잠깐 설명하자면, 파일을 "r+" 형식으로 오픈했다면 한 개의 스트림을 이용하여 파일 쓰기와 읽기를 동시에 수행할 수 있다.

다만, C 표준에 따르면 "r+" 형식으로 오픈한 파일에서 파일을 읽은 다음에 쓰기를 하려면 파일 위치 표시자 설정 함수 ([fseek](http://itguru.tistory.com/72), [fsetpos](http://itguru.tistory.com/73), [rewind](http://itguru.tistory.com/75)) 들을 호출하거나 `fflush` 함수를 호출해야 한다. 그렇지 않을 경우 오류가 발생하게 된다.

마찬가지로 파일을 쓴 다음에 읽기를 하려면 위와 동일한 작업을 해야 한다. 위 예제의 경우 마찬가지로 파일을 "r+" 형식으로 오픈하였는데, [fputs](http://itguru.tistory.com/40)로 "test" 를 쓴 후, 그 다음에 [fgets](http://itguru.tistory.com/38)로 파일에서 입력 받는다. 따라서 중간에 파일 위치 표시자 설정 함수를 호출하거나 `fflush` 함수를 호출해야 하는데 이 경우 `fflush` 함수를 호출하였다.

참고로, 왜 실행 화면에 `example.txt` 로 부터 입력받은 것이 아무것도 없냐면, 파일 위치 표시자가 파일에서 `test` 문자열 다음 위치를 가리키고 있기 때문이다. (참고적으로 개행 문자가 출력된 것처럼 보이는데 사실 [puts](http://itguru.tistory.com/48) 함수는 출력할 문자열 뒤에 자동으로 개행 문자를 붙여서 출력하기 때문에 실질적으로 출력된 것은 아무것도 없다)



###  참고 자료

*  [fclose](http://itguru.tistory.com/54)  :  파일을 닫는다.
*  [fopen](http://itguru.tistory.com/58)   : 파일을 연다.
*  [setbuf](http://itguru.tistory.com/61)  : 스트림 버퍼를 지정한다.
*  [setvbuf](http://itguru.tistory.com/62)  :  스트림 버퍼링 모드를 설정한다.