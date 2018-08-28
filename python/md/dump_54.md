


```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

`fclose`



```info
#include <stdio.h> // C++ 에서는 <cstdio>

int fclose ( FILE * stream );

```

파일을 닫는다.
인자로 지정한 스트림에 해당하는 파일을 닫는다.
이 때, 그 스트림의 모든 버퍼들은 비워(flush)진다. 아직 파일에 쓰이지 않고 남아있던 버퍼의 내용물은 모두 파일에 쓰이고, 아직 읽히지 않고 남아있떤 버퍼의 내용물은 모두 사라진다.
`fclose` 함수의 호출이 실패하더라도 인자로 전달된 스트림과 이에 해당하는 파일의 관계는 끊어지게 된다.



###  인자




`stream`

파일을 닫을 스트림의 `FILE` 객체를 가리키는 포인터.



###  리턴값




많일 스트림이 성공적으로 닫힌다면 0 이 리턴된다.
실패할 경우 `EOF` 가 리턴된다.



###  실행 예제




```cpp

/*myfile.txt 를 오픈하여 "fclose example" 을 쓴 후 파일을 닫는다.이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fclose/에서 가져왔습니다.*/#include <stdio.h>int main (){    FILE * pFile;    pFile = fopen ("myfile.txt","wt");    fprintf (pFile, "fclose example");    fclose (pFile);    return 0;}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F192A9D1F4B702E01249504)

파일에 쓰여진 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F127B681F4B702E017E42DF)





###  연관된 함수




* fopen  :  파일을 연다(open)

* fflush  :  스트림을 비운다(flush)





