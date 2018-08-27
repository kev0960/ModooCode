----------------
title : C 언어 레퍼런스 - fgetpos 함수
--------------



```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?
```


fgetpos




```cpp
#include <stdio.h> // C++ 에서는 <cstdio>int fgetpos ( FILE * stream, fpos_t * position );
```


스트림의 위치 지정자(position indicator)가 가리키는 위치를 position 에 저장한다. 
따라서 인자로 전달되는 position 은 fpos_t 의 형을 가리키는 포인터 형태로 사용되어야 하며, 거의 대부분 fsetpos 의 인자로만 사용하게 된다. 
만일 파일 위치 지정자의 값을 정수형 데이터로 얻고 싶다면 ftell 함수를 호출하면 된다. 



###  인자




stream

스트림의 FILE 객체에 대한 포인터

position

fpos_t 객체를 가리키는 포인터 



###  리턴값




이 함수는 성공적으로 값을 구하였다면 0 을 리턴하고 그렇지 않을 경우 0 이 아닌 값을 리턴한다. 



###  실행 예제




```cpp
/* 이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fgetpos/에서 가져왔습니다.  */#include <stdio.h>int main (){    FILE * pFile;    int c;    int n;    fpos_t pos;    pFile = fopen ("myfile.txt","r");    if (pFile==NULL) perror ("Error opening file");    else    {        c = fgetc (pFile);        printf ("1st character is %c\n",c);        fgetpos (pFile,&pos);        for (n=0;n<3;n++)        {            fsetpos (pFile,&pos);            c = fgetc (pFile);            printf ("2nd character is %c\n",c);        }        fclose (pFile);    }    return 0;}
```


myfile.txt 파일의 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F156B741F4BCA43C84F2A48)
실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F156A741F4BCA43C8528424)


위 예제에서 일단 myfile.txt 에서 문자 하나를 입력받는다. 그 이후, pos 에 현재의 파일 위치 지정자의 위치를 저장한다. 문자 하나를 입력 받았으므로 파일 위치 지정자는 두 번째 문자 (b) 를 가리킬 것이다. 그 후, for 문에서 fsetpos 함수를 이용하여 파일 위치 지정자의 위치를 계속 pos 로 바꾼다. 즉, 문자를 입력 받더라도 파일 위치 지정자가 그 다음 문자를 가리키는 것이 아니라 fsetpos 함수에 의해 계속 두 번째 문자만 가리키게 되는 것이다. 따라서 c d 가 출력되지 않고 계속 b b 만 출력되게 된다. 



###  연관된 함수





* 

fsetpos
  :  스트림 위치 지정자를 설정한다.


* 

ftell
  :  스트림 위치 지정자의 현재 위치를 구한다.


* 

fseek
  :  스트림 위치 지정자의 위치를 변경한다.








공감sns신고
저작자표시

'C Reference > stdio.h (cstdio)' 카테고리의 다른 글C 언어 레퍼런스 - fsetpos 함수(0)
2010.04.24C 언어 레퍼런스 - fseek 함수(0)
2010.04.24C 언어 레퍼런스 - fgetpos 함수(0)
2010.04.18C 언어 레퍼런스 - fwrite 함수(1)
2010.04.11C 언어 레퍼런스 - fread 함수(2)
2010.03.21C 언어 레퍼런스 - sprintf 함수(3)
2010.02.22

