 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

fputc
```info
#include <stdio.h> //C++ 의 경우 <cstdio>int fputc ( int character, FILE * stream );
```



스트림에 한 문자를 쓴다.스트림(stream) 에 한 문자를 쓰고 위치 표시자를 증가시킨다.
스트림에 써질 문자의 위치는 위치 표시자에 의해 지정되며, 한 문자를 쓴 후에 위치 표시자가 한 칸 증가된다.

인자

character

쓰여질 문자. 이 때, 문자는 int 로 형변환 되어서 전달된다.

stream

문자가 쓰여질 스트림의 FILE 객체를 가리키는 포인터.

리턴값

오류가 없다면 쓰여진 문자가 그대로 반환된다.
만일 오류가 발생하였다면 EOF 가 리턴되고, 오류 표시자가 설정된다. (ferror 참조)

실행 예제

```cpp
/* 표준출력(stdout) 에 문자열을 출력한다 */
#include <stdio.h>

int main ()
{
    char str[20]="hello every1";
    int i = 0;

    while (str[i])
    {
        fputc(str[i], stdout);
        i++;
    }

    return 0;
}
```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F1738630D4B61C80E01732A)

화면에 문자열 str 의 내용이 표시된다.

```cpp
/*
alphabet.txt 라는 파일을 (없으면) 생성하고 A 부터 Z 까지 쓴다.
참고로 이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fputc/
에서 가져왔습니다.
*/
#include <stdio.h>
int main ()
{
    FILE * pFile;
    char c;

    pFile = fopen ("alphabet.txt","w");
    if (pFile!=NULL)
    {
        for (c = 'A' ; c <= 'Z' ; c++)
        {
            fputc ( (int) c , pFile );
        }
        fclose (pFile);
    }
    return 0;
}

```

실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F1869230C4B61C795010616)

제목이 alphabet.txt 이고 내용이 A~Z 인 파일이 생성된다.

### 관련된 함수들


* putc : 스트림에 문자를 쓴다.
* fgetc : 스트림에서 문자를 가져온다.
* fwrite : 스트림에 데이터 블록을 쓴다.
* fopen : 파일을 연다.




공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - getc 함수(0)2010.02.02C 언어 레퍼런스 - fputs 함수(0)2010.02.02C 언어 레퍼런스 -  fputc 함수(0)2010.01.29C 언어 레퍼런스 - fgets 함수(1)2010.01.28C 언어 레퍼런스 - fgetc 함수(1)2010.01.28C 언어 레퍼런스 - stdio.h (cstdio) 헤더파일(6)2010.01.25

