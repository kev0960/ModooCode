----------------
title : C 언어 레퍼런스 - getc 함수
cat_title :  getc
publish_date : 2010-02-02
--------------


#@ getc



```info-format
#include <stdio.h> // C++ 의 경우 <cstdio>
int getc ( FILE * stream );
```

스트림에서 한 문자를 읽어온다.

문자를 읽어온 스트림의 내부 파일 위치 표시자가 현재 가리키는 문자를 리턴한다. 그리고 내부 파일 표시자는 그 다음 문자를 가리키게 된다.

`getc` 는 [fgetc](http://itguru.tistory.com/37)와 동일하며 역시 스트림을 인자로 취하고 있지만 매크로의 형태로 만들어져 있기 때문에 인자는 만일을 위해 식이 아닌 형태여야 한다.
`getchar` 함수는 `getc` 와 비슷하지만 스트림을 인자로 받지 않는다.



###  인자




`stream`

문자를 읽어올 스트림의 `FILE` 객체를 가리키는 포인터



###  리턴값




읽어들인 문자는 `int` 값으로 리턴된다.
만일 파일 끝에 도달하거나, 읽기 오류가 발생한다면 함수는 `EOF` 를 리턴하고 이에 대응하는 오류 혹은 `EOF` 표시자가 설정된다. 여러분은 [ferror](http://itguru.tistory.com/52)이나 [feof](http://itguru.tistory.com/51)함수를 통해 각각 어떤 오류가 발생했는지, 파일 끝에 도달하였는지 알 수 있다.



###  실행 예제


```cpp-formatted
/*

한 문자를 입력받은 후 이를 출력한다.

*/
#include <stdio.h>
int main() {
  int c;

  c = getc(stdin);

  printf("입력한 문자 : %c", c);

  return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F1703A41F4B6817C08DA705)



위와 같이 입력한 문자가 출력되었음을 볼 수 있다. `getc` 함수는 `scanf` 와는 달리 공백 문자도 입력 받을 수 있다.

```cpp-formatted
/*

myfile.txt 에 들어있는 $ 문자의 개수를 셉니다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/getc/
에서 가져왔습니다.

 */
#include <stdio.h>
int main() {
  FILE* pFile;
  int c;
  int n = 0;
  pFile = fopen("myfile.txt", "r");
  if (pFile == NULL)
    perror("Error opening file");
  else {
    do {
      c = getc(pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose(pFile);
    printf("File contains %d$.\n", n);
  }
  return 0;
}
```

현재 파일의 모습

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F127BE4224B68175B48FF15)

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F11249C204B68174A101E4C)




###  연관된 함수





*  [fgetc](http://itguru.tistory.com/37)  : 스트림에서 한 문자를 가져온다.



*  [fputc](http://itguru.tistory.com/39)  : 스트림에 한 문자를 쓴다.



*  [fread](http://itguru.tistory.com/68)  : 스트림에서 데이터 블록을 읽어온다.



*  [fwrite](http://itguru.tistory.com/69): 스트림에 데이터 블록을 쓴다.