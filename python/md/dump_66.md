----------------
title : C 언어 레퍼런스 - sprintf 함수
cat_title :  sprintf
publish_date : 2010-02-22
--------------



```warning
아직 C 언어와 친숙하지 않다면, [씹어먹는 C 언어 강좌](http://itguru.tistory.com/notice/15)를 보는 것이 어떻까요?

```

#@ sprintf

```info-format
#include <stdio.h> // C++ 에서는 <cstdio>

int sprintf ( char * str, const char * format, ... );
```


`str` 에 데이터를 형식에 맞추어 쓴다.
`str` 가 가리키는 배열에 형식 문자열에 지정한 방식 대로 C 문자열을 쓴다. 쉽게 설명하자면, `printf` 에서 화면에 출력하는 대신에 화면에 출력할 문자열을 인자로 지정한 문자열에 쓴다는 것이다. 이 때, 인자로 지정한 배열의 크기는 배열에 쓰여질 문자열의 크기 보다 커야만 한다. 주의할 점은 `sprintf` 함수는 자동적으로 `str` 맨 마지막에 NULL  문자를 붙이기 때문에 항상 한 칸의 여유가 있어야 한다.



###  인자

`str`

C 문자열이 저장될 `char` 배열을 가리키는 포인 C 문자열이 저장될 `char` 배열을 가리키는 포인터

`format`

위 `str` 에 쓰여질 문자열을 포함하는 형식 문자열으로, 이는 형식 태그를 포함할 수 있다. 이 때, 형식 태그는 부수적 인자로 지정한 데이터와 치환되어 쓰여지게 된다. 이 때, 데이터가 치환되는 방식은 형식 태그에 의해 좌우된다. 따라서 부수적 인자의 개수는 적어도 형식 문자열에 사용된 형식 태그의 수 보다 많아야 한다.

형식 태그는 아래와 같이 생겼다.

```info
%[플래그(flag)][폭(width)][.정밀도][크기(length)]서식 문자(specifier)
```

#### 서식문자

이 때 서식 문자(specifier) 는 대응하는 인자를 어떠한 형태로 표현할지를 결정하는데에 가장 중요한 역할을 한다.

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
  int integer = 123;
  char character = 'c';
  char string[] = "hello, world";
  int* pointer = &integer;
  double pi = 3.141592;
  char buf[100];

  sprintf(buf, "integer : (decimal) %d (octal) %o \n", integer, integer);
  printf("%s \n", buf);

  sprintf(buf, "character : %c \n", character);
  printf("%s \n", buf);

  sprintf(buf, "string : %s \n", string);
  printf("%s \n", buf);

  sprintf(buf, "pointer addr : %p \n", pointer);
  printf("%s \n", buf);

  sprintf(buf, "floating point : %e // %f \n", pi, pi);
  printf("%s \n", buf);

  sprintf(buf, "percent symbol : %% \n");
  printf("%s \n", buf);

  return 0;
}
```

출력 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F112B51264B816E0D281CCD)

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
  char buffer[100];
  int i = 123;
  int j = -123;
  double f = 3.141592;

  sprintf(buffer, "폭 맞추기 \n");
  fputs(buffer, fp);
  sprintf(buffer, "i : %6d \n", i);
  fputs(buffer, fp);
  sprintf(buffer, "i : %7d \n", i);
  fputs(buffer, fp);
  sprintf(buffer, "i : %2d \n\n", i);
  fputs(buffer, fp);

  sprintf(buffer, "왼쪽 정렬 \n");
  fputs(buffer, fp);
  sprintf(buffer, "i : %5d끝 \n", i);
  fputs(buffer, fp);
  sprintf(buffer, "오른쪽 정렬 \n");
  fputs(buffer, fp);
  sprintf(buffer, "i : %-5d끝 \n\n", i);
  fputs(buffer, fp);

  sprintf(buffer, "# 문자의 사용 \n");
  fputs(buffer, fp);
  sprintf(buffer, "i : %#x \n", i);
  fputs(buffer, fp);
  sprintf(buffer, "i : %#X \n\n", i);
  fputs(buffer, fp);

  sprintf(buffer, "부호 붙이기 \n");
  fputs(buffer, fp);
  sprintf(buffer, "%+d, %+d \n", i, j);
  fputs(buffer, fp);
  return 0;
}
```

출력결과
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F207483284B816ECE83B42C)

파일에 쓰여진 모습
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F1979DC284B816ECEB91429)

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
  char buffer[100];

  sprintf(buffer, "f : %.3f \n", f);
  printf("buf: %s \n", buffer);
  sprintf(buffer, "i : %.10d \n", i);
  printf("buf : %s \n", buffer);

  return 0;
}
```

출력 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F1825CF264B816F33170FE3)

#### 부수적인 인자

형식 문자열에 따라 함수는 여러 인자들을 가지며, 각 인자는 형식 문자열의 각 형식 태그에 순차적으로 대응된다. 기본적으로 형식 문자열에 들어 있는 형식 태그의 수와 뒤따라 붙는 인자들의 수는 같아야 한다. (물론 `.*` 이나 `*` 과 같은 예외적인 상황은 제외한다)



###  sprintf 함수의 활용 : 수를 문자열로 바꾸기


`sprintf` 함수를 잘 이용하면 수를 손쉽게 문자열로 바꿀 수 있다. 바로 다음과 같이.

```cpp-formatted
#include <stdio.h>
int main() {
  int i;
  char str[100];

  scanf("%d", &i);
  sprintf(str, "%d", i);

  printf("str : %s \n", str);

  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F182E3B244B816FA01FF33B)

`i` 의 값을 `%d` 의 형태로 `str` 에 문자열로 넣었으니 `str` 에는 `i` 의 값이 문자열의 형태로 변환된다.
마찬가지 방법으로 `i` 의 값을 16 진수나 8 진수 형태로 (`%x, %o`) 넣을 수 도 있다.



###  리턴값


`str` 에 쓰기가 성공할 경우 쓰여진 총 문자의 개수가 반환된다. 이 때, 이 문자의 개수는 맨 마지막에 자동적으로 붙는 `NULL` 문자는 포함하지 않는다.
실패할 경우 음수가 리턴된다.



###  실행 예제


```cpp-formatted
/*

sprintf 함수 예제
이 예제는 http://www.cplusplus.com/reference/clibrary/cstdio/sprintf/
에서 가져왔습니다.

*/
#include <stdio.h>
int main() {
  char buffer[50];
  int n, a = 5, b = 3;
  n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
  printf("[%s] is a %d char long string\n", buffer, n);
  return 0;
}
```


실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1203AA0C4B8170D90DA277)




###  연관된 함수

*  [printf](http://itguru.tistory.com/35) :  표준 출력(stdout) 에 데이터를 형식에 맞추어 출력한다.
*  [sscanf](http://itguru.tistory.com/67) :  문자열에서 데이터를 형식에 맞추어 읽는다.