

```warning
아직 C 언어와 친숙하지 않다면, 씹어먹는 C 언어 강좌를 보는 것이 어떻까요?

```


atof


```info
#include <stdlib.h> // C++ 에서는 <cstdlib>

double atof ( const char * str );

```

문자열을 double 형 값으로 바꾼다.

C 형식 문자열의 내용을 double 형 수로 생각하여 그 값을 double 로 변환한다. 즉, 문자열 "3.145" 로 입력 받은 데이터를 실제 산술 연산에 사용하기 위해서 double 형인 3.145 로 변환함을 의미한다. 

이 함수는 입력 받은 문자열에서 최초로 공백 문자가 아닌 문자(non-whitespace) 까지 도달할 때 까지 그 앞의 모든 공백 문자를 지워버린다. 그리고, 최초의 비 공백문자로 부터 부동 소수점 수와 연관된 문자들(예를 들면 0 부터 9 까지 숫자들과, 소수점 (.), -, + 등등)을 최대한 많이 읽어들인후 그 데이터를 수치로 변환하다. 문자열의 나머지 부분들은 무시되고 이 함수에 전혀 영향을 주지 않는다.

atof 함수가 변환할 수 있는 올바른 형태의 수는 다음과 같다.
* 숫자 앞의 + 또는 - 기호0 부터 9 까지의 숫자들, 그리고 소수점지수로 부호 기호와 숫자들 뒤에 나타나야 하며 e 또는 E 가 사용될 수 있다. 
만일 맨 첫번재 비 공백문자로 올바른 부동 소수점 수를 구성할 수 없거나, 문자열 자체가 비어 있다면 어떠한 작업도 진행되지 않는다. 

※ 참고적으로 double 형 변수를 문자열 형태로 바꾸는 방법은 sprintf 함수를 참조하기를 바란다. 

###  인자
### 
str

C 형식 문자열로 부동 소수점 수를 문자열 형태로 포함하고 있어야 한다. 

###  리턴값
### 
성공적으로 수를 구했다면 double 형의 형태로 그 값이 리턴된다.

만일 올바른 값을 구할 수 없거나, 수의 값이 언더플로우(underflow - double 형 부동 소수점으로 표현할 수 있는 최소의 값보다도 값이 작은 경우) 일 경우 0.0 이 리턴된다.

만일 문자열의 수가 double 형에서 표현할 수 있는 최대의 범위 보다 클 경우 양 또는 음의 HUGE_VAL 이 리턴된다. 

###  실행 예제

```cpp
/* 

각도를 문자열로 입력 받아서 double 형 수치 값으로 변환한 뒤 이의 sine 값을 계산한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstdlib/atof/
에서 가져왔습니다.

 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    double n,m;
    double pi=3.1415926535;
    char szInput [256];
    printf ( "Enter degrees: " );
    gets ( szInput );
    n = atof ( szInput );
    m = sin (n*pi/180);
    printf ( "The sine of %f degrees is %f\n" , n, m );
    return 0;
}
```


실행 결과

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F113F11534D29C4192AA79E)


###  연관된 함수
### * strtod  :  문자열을 double 형 값으로 바꾼다.  
atoi  :  문자열을 int 형 값으로 바꾼다.atol  :  문자열을 long 형 값으로 바꾼다.
공감sns신고저작자표시'C Reference > stdlib.h (cstdlib)' 카테고리의 다른 글C 언어 레퍼런스 - srand 함수(0)
2011.05.05C 언어 레퍼런스 - rand 함수(2)
2011.05.05C 언어 레퍼런스 - atol 함수(4)
2011.01.27C 언어 레퍼런스 - atoi 함수(0)
2011.01.27C 언어 레퍼런스 - atof 함수(0)
2011.01.09C 언어 레퍼런스 - stdlib.h (cstlib)(1)
2011.01.05

