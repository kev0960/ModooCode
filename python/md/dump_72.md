----------------
title : C 언어 레퍼런스 - fseek 함수
cat_title :  fseek
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ fseek

```info
#include <stdio.h> // C++ 에서는 <cstdio>

int fseek ( FILE * stream, long int offset, int origin );

```

스트림 위치 지정자 (position indicator) 의 위치를 조정한다.
`origin` 인자로 전달된 위치로 부터 `offset` 인자로 전달된 만큼 더한 위치로 위치 지정자를 설정한다.
이 함수를 호출한 이후에는 파일 끝 지정자 (End of File indicator) 가 초기화 되고, 이전에 만일 [ungetc](http://itguru.tistory.com/49)함수를 호출하였다면 이로 인한 효과는 모두 사라지게 된다.
한가지 명심해야 할 점은, 만일 텍스트 파일에 `fseek` 함수를 사용할 때, `offset` 값으로 0 이 아닌 값 혹은 `ftell` 함수에 의해 반환된 값을 사용할 때에는 일부 플랫폼에서는 약간 문제가 생겨서 예상치 못했던 위치에 위치 지정자가 설정되어 있는 경우가 있으니 주의해야 한다.
`fseek` 함수는 또한 스트림이 읽기 및 쓰기 형식으로 열려있을 때, 이 함수를 호출함을 통해 읽기 - 쓰기 모드를 전환할 수 있다. (자세한 내용은 [fopen](http://itguru.tistory.com/58)함수를 참조하기 바란다)



###  인자




`stream`

작업을 수행할 스트림의 `FILE` 객체를 가리키는 포인터

`offset`

`orgin` 으로 부터 얼마나 떨어진 곳에 설정할 지에 대한 값

`origin`

오프셋이 더해지는 위치로, `<stdio.h>` 에 정의된 다음과 같은 상수들을 이용한다.

`SEEK_SET`파일의 시작
`SEEK_CUR`현재 파일 포인터의 위치
`SEEK_END`파일의 끝




###  리턴값




만일 성공하였으면 0 을 리턴한다. 그렇지 않다면 0 이 아닌 값을 리턴한다.



###  실행 예제




```cpp
/*

example.txt 에 "This is an apple" 을 쓴 뒤에 다시 fseek 함수를 이용하여 n 부터 sam 으로 바꾼다. 즉, example.txt 에는 "This is an sample" 이 들어가게 된다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fseek/
에서 가져왔습니다.

 */
#include <stdio.h>

int main ()
{
    FILE * pFile;
    pFile = fopen ( "example.txt" , "w" );
    fputs ( "This is an apple." , pFile );
    fseek ( pFile , 9 , SEEK_SET );
    fputs ( " sam" , pFile );
    fclose ( pFile );
    return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1470C5114BD23C5D569FE8)

`myfile.txt` 에는


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F1470A1114BD23C5D437B49)





###  연관된 함수

*  [ftell](http://itguru.tistory.com/74)  :  스트림의 현재 위치를 구한다.
*  [fsetpos](http://itguru.tistory.com/73):  스트림의 위치 지정자를 설정한다.
*  [rewind](http://itguru.tistory.com/75)  :  스트림의 위치 지정자를 맨 처음으로 설정한다.







