----------------
title : C 언어 레퍼런스 - atoi 함수
path : /C Reference/stdlib.h
cat_title :  atoi
publish_date : 2011-01-27
--------------


#@ atoi

```info
#include <stdlib.h> // C++ 에서는 <cstdlib>

int atoi ( const char * str );
```


문자열을 정수로 변환한다.

C 형식 문자열을 정수로 변환하여 변환된 값을 리턴한다 C 형식 문자열을 정수로 변환하여 변환된 값을 리턴한다.

이 함수는 C 형식 문자열에서 비-공백 문자가 나오기 전 까지 최대한 많은 공백 문자(' ', '\t', \n') 들을 무시한다. 그 다음에 첫 번째 비-공백 문자부터 최대한 많은 숫자들을 수로 변환한다. 이 때, 숫자의 맨 앞부분에는 `+` 나 `-` 가 올 수 도 있다. 숫자들 다음에 나타나는 문자들은 모두 무시된다. 예를 들면

```cpp-formatted
"\n\n-123aaa"
```

이라는 문자열이 있다면 -123 으로 변환된다.
만일 문자열에서 첫 번째로 나타나는 비-공백 문자가 숫자 혹은 `+` 나 `-` 가 아니라면 어떠한 변환도 이루어 지지 않는다. 또한 문자열이 공백 문자로만 이루어져 있어도 변환이 이루어 지지 않는다. 예로

```cpp-formatted
"a123"
```

의 경우 123 이 있지만 첫번째 비-공백 문자가 `a` 이기 때문에 변환이 이루어지지 않는다. 변환이 이루어 지지 않는 경우 0 이 리턴된다. 참고로 `atoi` 함수를 잘 이용하면 `scanf` 로 정수를 입력받을 때 문자를 입력하면 오류가 발생하는 문제를 피할 수 있다. 예를 들면

```cpp-formatted
int i;
char input[10];

scanf("%s", input);
i = atoi(input);
```


와 같은 형태로 입력을 받으면 설사 문자를 입력 했다고 해도 오류가 나지 않고 정수를 입력하면 `atoi` 로 잘 변환된다.



###  인자




`str`

정수를 포함하고 있는 C 형식 문자열




###  리턴값




성공적으로 변환을 하였다면 `int` 값을 리턴한다.
만일 변환을 실패하였다면 0 이 리턴된다.

만일 변환을 하였지만 그 값이 표현 가능한 범위를 벗어난다면 `INT_MAX` 혹은 `INT_MIN` 이 리턴된다.



###  구현 예


```cpp-formatted
/*

아래 예제는
http://cboard.cprogramming.com/linux-programming/125356-complete-function-definition-i-e-atoi.html
에서 가져왔습니다.

*/
#include <ctype.h>  // C++ 에서는 <cctype>

int atoi(char s[]) {
  int i, n, sign;
  for (i = 0; isspace(s[i]); i++)
    ; /* skip white space */
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') /* skip sign */
    i++;
  for (n = 0; isdigit(s[i]); i++) n = 10 * n + (s[i] - '0');
  return sign * n;
}
```





###  실행 예제




```cpp-formatted
/*

수를 문자열로 입력받은 뒤 atoi 함수로 이를 정수로 변환한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstdlib/atoi/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  char szInput[256];
  printf("Enter a number: ");
  fgets(szInput, 256, stdin);
  i = atoi(szInput);
  printf("The value entered is %d. The double is %d.\n", i, i * 2);
  return 0;
}
```

실행 결과


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F196A4A444D40CB2D281113)





###  연관된 함수


* atol  :  문자열을 `long` 형 정수로 변환한다.
*  [atof](http://itguru.tistory.com/124)  :  문자열을 `double` 형으로 변환한다.
* strtol  :  문자열을 `long` 형 정수로 변환한다.