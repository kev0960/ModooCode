----------------
title : C 언어 레퍼런스 - rewind 함수
cat_title :  rewind
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ rewind

```info
#include <stdio.h> // C++ 에서는 <cstdio>

void rewind ( FILE * stream );

```

스트림의 위치 지정자를 맨 처음으로 설정한다.
참고로 위 함수의 작업은

```cpp
fseek (stream, 0, SEEK_SET);
```

과 정확히 동일하다.단, [fseek](http://itguru.tistory.com/72)`` 함수와는 달리 `rewind` 함수는 오류 지정자를 초기화 한다.
따라서, 스트림이 읽기 및 쓰기 형식으로 열려있을 경우, `rewind` 함수를 호출함으로써 읽기에서 쓰기 모드로, 쓰기에서 읽기 모드로 변경할 수 있다.



###  인자




`stream`

스트림의 `FILE` 객체를 가리키는 포인터



###  리턴값




없음



###  실행 예제




```cpp


/*myfile.txt 에 A 부터 Z 까지 출력한 뒤, 다시 pFile 을 파일의 처음으로 옮긴 후 파일의 내용을 읽어들인다. 즉, buffer 에는 A 부터 Z 까지 들어가게 된다. 따라서 화면에는 ABCDEFGHIZKLMNOPQRSTUVWXYZ 가 출력된다.이 예제는http://www.cplusplus.com/reference/clibrary/cstdio/rewind/에서 가져왔습니다.*/#include <stdio.h>int main (){    int n;    FILE * pFile;    char buffer [27];    pFile = fopen ("myfile.txt","w+");    for ( n='A' ; n<='Z' ; n++)        fputc ( n, pFile);    rewind (pFile);    fread (buffer,1,26,pFile);    fclose (pFile);    buffer[26]='\0';    puts (buffer);    return 0;}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F2010CA164BD2B5D56CBB0B)

`myfile.txt` 의 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F1745BD164BD2B5D502B924)



###  연관된 함수

*  [fseek](http://itguru.tistory.com/72)`` :  스트림 위치 지정자를 설정한다.
*  [fsetpos](http://itguru.tistory.com/73)  :  스트림 위치 지정자를 설정한다.
*  [fflush](http://itguru.tistory.com/57)  :  스트림을 비운다.







