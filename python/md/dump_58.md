 itguru Top itguru Top

```warning
아직 C 언어와 친숙하지 않다면,씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```

fopen
```info
#include <stdio.h> // C++ 에서는 <cstdio>FILE * fopen ( const char * filename, const char * mode );
```



파일을 연다

filename 인자에서 지정한 파일을 열고, 이에 해당하는 스트림의 FILE 객체를 가리키는 포인터를 반환한다. 이 때, 이 스트림에서 어떠한 입출력 작업이 가능한지는 mode 인자에 의해 결정된다.
fopen 함수는 동시에 최소 FOPEN_MAX 개의 파일들을 열 수 있게 보장하고 있으며 (이 이상 열 수도 있지만 성공적으로 열 수 있을지에 대해선 보장할 수 없다) 이 값은 실행 환경에 따라 다를 수 있다. 참고로 FOPEN_MAX 는 <stdio.h> (C++ 에서는 <cstdio> ) 에 정의되어 있는 매크로 상수 이다.

### 인자

filename

C 문자열로 열을 파일의 이름이다. 이 인자는 각 실행 환경에서 지정하는 파일 이름 형식을 따라야 하며, 만일 시스템에서 경로 설정이 지원된다면 경로도 포함할 수 있다.

mode

C 문자열로 파일 접근 모드를 설정한다. 이 모드는 다음이 될 수 있다.

"r"파일을 읽기 형식으로 연다. 이 때, 파일은 반드시 존재해야 한다.
"w"파일을 쓰기 형식으로 연다. 만일 동일한 파일이 이미 존재하고 있다면 그 파일의 내용은 모두 지워진 후 새롭게 생긴 빈 파일로 간주하며, 파일이 존재하고 있지 않는다면 빈 파일을 새롭게 생성한다.
"a"파일을 덧붙이기(append) 형식으로 연다. 쓰기 작업은 파일 끝에 데이타를 덧붙일 것이다. 만일 파일이 존재하지 않는다면 새로 생성된다.
"r+"파일을 읽기 및 쓰기 형식으로 연다. 이 때, 파일은 반드시 존재해야 한다.
"w+"파일을 읽기 및 쓰기 형식으로 연다. 만일 동일한 파일이 이미 존재하고 있다면 그 파일의 내용은 모두 지워진 후 새롭게 생긴 빈 파일로 간주하며, 파일이 존재하고 있지 않다면 빈 파일을 새로 생성하게 된다.
"a+"파일을 읽기 및 덧붙이기(append) 형식으로 연다. 지정한 파일이 존재하지 않는다면 새롭게 생성된다. 모든 쓰기 작업은 파일의 맨 끝에서 진행되며 기존의 파일 내용들에 덮혀씌여지지 않는다. 여러분은 읽기 작업에서는fseek 이나rewind 함수 등을 이용하여 파일 위치 포인터를 원하는 대로 움직일 수 있지만, 쓰기 작업에서는 위치 포인터를 언제나 파일 맨 끝으로 이동 시킬 것이다.

표에서 나온 바와 같이 mode 문자열 ("r", "w", "a", "r+", "w+", "a+")을 사용한다면 파일은 "텍스트(text) 파일" 형식으로 열리게 된다. (참고로, 이 파일이 텍스트 파일로 열린다는 사실을 굳이 명시해 주고 싶다면 끝에 "t" 를 붙이면 된다. 하지만 붙이나 안붙이나 효과는 똑같다)
만일 파일을 이진 형식으로 열고 싶다면 mode 문자열 뒤에 "b" 문자를 붙여주면 된다. 즉, "rb", "wb", "ab", "r+b", "w+b", "a+b"로 하면 된다. 이 때, + 기호는 맨 뒤로 보내도 된다. 다시 말해, "rb+", "wb+", "ab+" 는 각각 "r+b", "w+b", "a+b" 와 동일하다.
파일을 텍스트 파일 형식으로 열게 된다면, 프로그램이 실행되는 환경에 따라 일부 특수 문자들은 입출력 연산시 다른 방식으로 해석될 수 있다. (이 사실에 대해선 stdio.h 를 참조하여라) 하지만, 이진 형식으로 파일을 읽게 된다면 실행 환경에 상관 없이 언제나 동일하게 해석될 수 밖에 없다.
읽기/쓰기를 동시에 하는 모드 ("r+", "w+", "a+") 의 경우, 읽기 작업을 한 후, 쓰기 작업을 하거나, 쓰기 작업을 한 후 읽기작업을 하는 경우 중간에 반드시 스트림을 비우거나 (fflush), 위치가 조정 되어야 한다.

### 리턴값

만일 파일이 성공적으로 열렸다면 fopen 함수는 FILE 객체에 대한 포인터를 리턴할 것이다. 이 포인터는 나중에 스트림 관련 작업시에 스트림을 구분하기 위해 자주 사용된다. 그렇지 않을 경우 널 포인터가 리턴된다.
### 실행 예제

```cpp
/*

example.txt 파일을 생성한 뒤, 쓰기 형식으로 오픈하여 "안녕하세요 여러분 \n Psi 입니다 \n" 를 파일 내용에 집어 넣는다. 그리고, example.txt 를 덧붙이기 형식으로 오픈한 뒤 뒤에 "어 그래 안녕" 을 덧붙인다.

*/
#include <stdio.h>
int main()
{
    FILE *fp, *fp2;

    if((fp = fopen("example.txt", "w")) == NULL)
    {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    fputs("안녕하세요 여러분 \n Psi 입니다 \n", fp);

    if((fp2 = fopen("example.txt", "a")) == NULL)
    {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    fputs("어 그래 안녕?", fp2);
    return 0;
}
```


example.txt 에 쓰여진 모습

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F1345071D4B73C8EA199FA6)


### 연관된 함수


* fclose    :  파일을 닫는다.
* setbuf    :  스트림 버퍼를 설정한다.
* setvbuf  :  스트림 버퍼의 모드를 설정한다.
* tmpfile   :  임시 파일을 연다.

* tmpnam  : 임시 파일 이름을 생성한다.

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C Reference >stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - setbuf 함수(0)2010.02.16C 언어 레퍼런스 - freopen 함수(0)2010.02.13C 언어 레퍼런스 - fopen 함수(0)2010.02.11C 언어 레퍼런스 - fflush 함수(4)2010.02.10C 언어 레퍼런스 - fclose 함수(3)2010.02.08C 언어 레퍼런스 - perror 함수(0)2010.02.08

