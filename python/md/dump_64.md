----------------
title : C 언어 레퍼런스 - fprintf 함수
cat_title :  fprintf
publish_date : 2010-02-19
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ fprintf

```info-format
#include <stdio.h> // C++ 에서는 <cstdio>

int fprintf ( FILE * stream, const char * format, ... );

```

데이터를 형식에 맞추어 스트림에 쓴다.

특정한 스트림에 일련의 데이터를 특정한 형식에 맞추어 쓰게 된다. 이 때, 그 형식은 형식 문자열에 지정되어 있으며, 출력할 데이터는 형식 문자열 다음에 오는 인자들에 써주면 된다.



###  인자




`stream`

작업을 수행할 스트림의 `FILE` 객체

`format`

C 문자열로 스트림에 써질 텍스트를 포함하고 있다 C 문자열로 스트림에 써질 텍스트를 포함하고 있다.

또한 이 문자열에는 형식 태그를 부수적으로 포함할 수 있는데 이는 각각의 형식 태그에 대응되는 인자의 데이터가 형식 태그가 지정하는대로 치환된다.

따라서, 이 문자열에 포함되어 있는 형식 태그의 수는 뒤에 부수적으로 오는 인자의 개수 보다 언제나 같거나 적어야 한다.

형식 태그는 다음과 같은 꼴로 써야 한다.

```info
%[플래그(flag)][폭(width)][.정밀도][크기(length)]서식 문자(specifier)
```

#### 서식문자

이 때, 형식 태그에서 가장 중요한 부분은 서식 문자로 이는 이 형식 태그에 대응되는 인자의 값이 어떠한 형태로 출력되는지를 조정해 준다.

|서식 문자|출력 형태|예시 |
|---------|---------|-----|
|`c`      | 문자    | `a` |
|`d` or `i` | 부호 있는 십진법으로 나타난 정수|`392`|
|`e`      | 지수 표기법(Scientific notation) 으로 출력하되, `e` 문자를 이용한다.| `3.9265e+2`|
|`E`      | 지수 표기법(Scientific notation) 으로 출력하되, `E` 문자를 이용한다.|`3.9265E+2`|
|`f`      | 십진법으로 나타낸 부동 소수점 수| `392.65` |
| `g`     | %e나 `%f` 보다 간략하게 출력 |`392.65`|
| `G`     | %E나 `%f` 보다 간략하게 출력| `392.65`|
|`o`      | 부호 있는 팔진수| `610`|
|`s`      | 문자열 | `sample`|
|`u`      | 부호없는 십진법으로 나타낸 정수|`7235`|
|`x`      | 부호없는 16 진법으로 나타낸 정수 (소문자 사용) |`7fa`|
|`X`      | 부호없는 16 진법으로 나타낸 정수 (대문자 사용) |`7FA`|
|`p`      | 포인터 주소 |B800:0000 |
|`n`      | 아무것도 출력하지 않는다. 그 대신, 인자로 부호 있는 `int` 형을 가리키는 포인터를 전달해야 되는데, 여기에 현재까지 쓰여진 문자 수가 저장된다.||
|`%`      |`%` 다음에 %를 또 붙이면 `stdout` 에 `%` 를 출력한다.||


위 서식 문자를 이용한 다양한 출력 형태는 아래와 같다.
```cpp-formatted
#include <stdio.h>
int main() {
  FILE* fp = fopen("output.txt", "w");
  int integer = 123;
  char character = 'c';
  char string[] = "hello, world";
  int* pointer = &integer;
  double pi = 3.141592;

  fprintf(fp, "integer : (decimal) %d (octal) %o \n", integer, integer);

  fprintf(fp, "character : %c \n", character);

  fprintf(fp, "string : %s \n", string);

  fprintf(fp, "pointer addr : %p \n", pointer);

  fprintf(fp, "floating point : %e // %f \n", pi, pi);

  fprintf(fp, "percent symbol : %% \n");

  return 0;
}
```


출력 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F2043C0134B7C11CA50B5DB)


파일의 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F12480A134B7C11CA40B3C2)

`output.txt` 에 우리가 형식 문자열에서 지정해준대로 잘 표시되었음을 알 수 있다. 또한, 콘솔에는 출력을 하지 않았으므로 콘솔에는 아무것도 표시되지 않았다.

#### 플래그

형식 태그에는 위 말고도 플래그, 폭, .정확도, 제한자(modifier), 부-서식문자(sub-specifiers) 에 관련한 정보들이 포함될 수 있다. 먼저 플래그를 살펴보면 플래그는 기본적으로 출력되는 형태에 대해 조금 더 자세하게 지정할 수 있게 해준다. 플래그는 아래와 같다.

|플래그    |설명|
|`-`      | 폭에 맞추어 왼쪽 정렬을 하여 출력한다. `-` 를 붙이지 않는다면 기본적으로 오른쪽 정렬이 되어 출력한다. (아래 폭 지정자 참조).|
|`+`      | 출력 결과값이 양수인 경우라도 `+` 기호를 앞에 붙여서 출력하도록 한다. (물론 음수면 자동적으로 `-` 가 붙는다). 기본적으로 지정하지 않았을 경우 음수에만 앞에 `-` 가 붙는다.|
|(공백)    | 앞에 부호가 붙지 않는다면 한 칸을 띄어서 출력한다. (다시말해 123 은 " 123" 으로 출력되고 -123 은 "-123" 으로 출력된다)|
| #       |`o, x, X` 서식 문자들과 사용되면 출력되는 값 앞에 각각 `0, 0x, 0X` 가 붙게 된다. (이 때 0 은 제외한다). `e, E, f` 서식 문자들과 사용되면 소수점 아래 수들이 없음에도 불구하고 강제적으로 소수점을 붙이도록 한다. 원래 소수점 아래 수들이 없다면 소수점을 붙이지 않는다. `g` 와 `G` 서식 문자들과 사용되면 `e` 와 `E` 일때와 동일한 작업을 하지만 소수들의 뒷부분에 붙는 0 들 (123.1200 등) 은 제거되지 않는다.|
|`0`      | 수들을 왼쪽으로 정렬하되 빈 칸을 삽입하는 대신에 0 을 삽입한다. (폭 지정자 참조)|

#### 폭

폭은 말그대로 출력되는 데이터의 폭을 지정해준다. 참고로 여기서의 폭(width)은 뒤에 나오는 길이(length) 와는 완전히 다른 개념이므로 유의 하시기 바란다.

|폭 | 설명 |
| (수) | 출력할 최소의 문자 개수. 만일 이 수 보다 출력할 수 보다 작다면 빈칸을 삽입하여 길이를 맞춘다. 대신에, 이 수 보다 출력할 수가 큰 수의 경우 잘려서 출력되지는 않는다.|
|`*`   |폭을 형식 문자열에 지정해서 받지 않지만, 그 대신에 형식 문자열 뒤에 오는 인자들에 넣어서 받는다. 이 때, 이는 정수 값이여야 하며 폭을 지정하는 변수 뒤에 출력할 데이터가 위치하면 된다.|

```cpp-formatted
/* 사용 예 */
#include <stdio.h>
int main() {
  FILE *fp = fopen("output.txt", "w");
  int i = 123;
  int j = -123;
  double f = 3.141592;

  fprintf(fp, "폭 맞추기 \n");
  fprintf(fp, "i : %6d \n", i);
  fprintf(fp, "i : %7d \n", i);
  fprintf(fp, "i : %2d \n\n", i);

  fprintf(fp, "왼쪽 정렬 \n");
  fprintf(fp, "i : %5d끝 \n", i);
  fprintf(fp, "오른쪽 정렬 \n");
  fprintf(fp, "i : %-5d끝 \n\n", i);

  fprintf(fp, "# 문자의 사용 \n");
  fprintf(fp, "i : %#x \n", i);
  fprintf(fp, "i : %#X \n\n", i);

  fprintf(fp, "부호 붙이기 \n");
  fprintf(fp, "%+d, %+d \n", i, j);
  return 0;
}
```

출력결과
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F2043C0134B7C11CA50B5DB)

파일에 출력된 모습
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F143AC8134B7C128D4E3B18)

이전의 예제와 같이 `output.txt` 에 우리가 지정한 방식대로 잘 출력되었음을 볼 수 있다.

#### 정밀도 

정밀도는 말그대로 수치 데이터를 출력할 때 어떠한 정밀도로 출력하는지 (즉, 몇 자리 까지 출력해야 되는지) 를 지정해준다. 참고적으로 정밀도를 나타낼 때, 앞에 꼭 마침표(.) 을 찍는 것을 잊지 말기 바란다. 마침표를 찍는 이유는 앞에 폭과 구분을 하기 위해서 이다.

|정밀도|설명|
|.숫자| 정수 지정자 (d,i,o,u,x,X) 의 경우 : 정밀도는 출력되야할 최소의 자리수를 일컫는다. 만일, 어떤 정수의 자리수가 정밀도 보다 작다면 앞에 0 이 붙어서 자리수를 맞추게 된다. 또한 자리수가 더 크다고 해서 정수를 잘라서 출력하지는 않는다. 만일 정밀도가 0 이라면, 소수점 뒤에 자리수를 출력하지 않는다. `e,E, F` 의 경우 : 여기서 정밀도는 소수점 이하 출력될 자리수를 의미한다. `g, G` 의 경우 : 출력될 유효 숫자의 수를 의미한다. `s` 의 경우 : 출력될 문자의 최대 개수를 의미한다. 원래는 널 문자를 만나기 전까지 모든 문자가 출력되었었다. `c` 의 경우 : 아무 효과 없다. 만일 정밀도가 지정되지 않는다면 기본값으로 1 이 된다. 또한, 마침표(.) 을 찍었는데 아무런 숫자를 적지 않았다면 기본적으로 0 이 적혔다고 생각한다.|
|`.*`|형식 문자열에서 정밀도를 나타내지는 않지만 뒤에 인자로 정밀도 값을 준다. 이 때 인자는 형식 태그가 적용되는 데이타 앞에 있어야 한다.|

#### 길이

길이는 출력하는 데이터의 정확한 크기를 지정하는데 사용된다. 예를 들어서 `%d` 서식문자의 경우 막연하게 '정수형 데이터를 십진법으로 출력한다' 였지만 길이를 지정해주면 어떻나 크기로 데이터를 출력해야되는지 (`int` 냐 `short` 냐 등등) 을 지정할 수 있다.

|길이|설명|
|`h`|인자를 `short int` 혹은 `unsigned short int` 로 생각한다. (오직 `i, d, o, u , x, X` 서식 문자에만 적용된다)|
|`l`|정수 서식 문자(i,d,o,u,x, `X)` 에 사용되었을 경우 인자를 `long int` 나 `unsigned long int` 로 생각하며 `c` 나 `s` 에 사용되었을 경우 `wide character` 나 `wide string` 으로 생각한다.|
|`L`|인자를 `long double` 로 생각한다. (오직 부동 소수점 서식 문자인 `e,E,f,g, G` 에만 적용된다)|

```cpp-formatted
/* 사용 예 */
#include <stdio.h>
int main() {
  double f = 3.141592;
  int i = 12345;

  fprintf(stdout, "f : %.3f \n", f);
  fprintf(stdout, "i : %.10d \n", i);

  return 0;
}
```

출력 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F135054234B5DB76133E080)

이번에는 파일 스트림에 출력하는 것이 아니라 표준 출력(stdout), 즉 콘솔 화면에 출력을 해 보았다. 역시 우리가 지정한 형식대로 잘 출력된다.

부수적인 인자

형식 문자열에 따라 함수는 여러 인자들을 가지며, 각 인자는 형식 문자열의 각 형식 태그에 순차적으로 대응된다. 기본적으로 형식 문자열에 들어 있는 형식 태그의 수와 뒤따라 붙는 인자들의 수는 같아야 한다. (물론 `.*` 이나 `*` 과 같은 예외적인 상황은 제외한다)



###  리턴값


출력 성공시, 화면에 출력된 총 문자의 개수를 반환한다.
실패했다면 음수가 반환된다.



###  실행 예제


```cpp-formatted
/*

사용자로 부터 이름을 입력받아 이를 깔끔하게 myfile.txt 에 기록한다.
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/fprintf/
에서 가져왔습니다.

 */
#include <stdio.h>
int main() {
  FILE* pFile;
  int n;
  char name[100];

  pFile = fopen("myfile.txt", "w");
  for (n = 0; n < 3; n++) {
    puts("please, enter a name: ");
    scanf("%s", name);
    fprintf(pFile, "Name %d [%-10.10s]\n", n, name);
  }
  fclose(pFile);

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F115248014B7D726B2BDC4A)

파일에 출력된 모습


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F18235C014B7D726B5F7BA8)

`fprintf` 에서 사용한 형식 문자열에 대해 설명을 하자면

```info
%-10.10s
```

먼저 봐야 할 것은 서식 문자인데, `s` 는 데이터를 문자열로 출력하라는 것이다. 맨 앞의 `-` 는 문자열을 "왼쪽 정렬" 해서 출력하라는 의미 이다. 그 뒤에 10 은 최소 10 개의 문자를 출력하라는 뜻으로 길이가 10 미만인 문자열은 공백으로 길이를 맞춘다. Psi 다음에 쭉 위치한 공백이 그것이다. 그리고 `.10` 은 최대 10 문자를 출력하라는 뜻으로 10 문자가 넘으면 잘리게 된다. 위에 `Genious Psi` 가 잘려서 `Genious Ps` 까지 출력된 것을 볼 수 있다.



###  참고 자료


*  [printf](http://itguru.tistory.com/35)  :  특정한 형식에 맞추어 데이터를 `stdout` 에 출력한다.

*  [fscanf](http://itguru.tistory.com/65)  :  특정한 형식에 맞추어 스트림에서 데이터를 읽어온다.

*  [fwrite](http://itguru.tistory.com/69)  :  스트림에 데이터 블록을 쓴다.

*  [fputs](http://itguru.tistory.com/40)  :  스트림에 문자열을 쓴다.