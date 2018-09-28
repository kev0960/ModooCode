----------------
title : 씹어먹는 C 언어 - <18 - 2. 파일 뽀개기 (# 친구들, 라이브러리)>
cat_title : 18 - 2. 파일 뽀개기 (# 친구들, 라이브러리)
next_page : 89
--------------


이번 강좌에서는

* #include, #define, #ifdef, #endif, #else 와 같은 전처리기 구문에 대한 이해

* 헤더파일에 대한 설명

* 라이브러리 (string.h) 사용하기





![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F193C5C364C4E87A113BEDF)

안녕하세요 여러분~ 잘 지내셨는지요. 그럼 군말 없이 바로 강의에 들어가겠습니다. 참고로 이게 32 번째 강의인데 이렇게 보니까 참 많이도 썻다고 생각되네요. 30 강 까지 모두 pdf 로 만들었는데 사진을 모두 빼고도 페이지가 380 페이지에 달하내요. 사진을 모두 넣게 되면 적어도 500 페이지 정도는 될 텐데 보기 조금 힘들 것 같네요. 제 블로그에 우수한 성적으로 (?) 방문해 주신 분들께 선물로 나눠드릴라 그랬는데 제본비만 만원이 넘을 것 같아서 그건 좀 힘들겠네요.



###  헤더 파일

여태까지 헤더 파일에는 오직 함수의 원형들 만을 넣었습니다. 하지만 헤더파일에는 함수의 원형 뿐만이 아니라 아래의 것들도 함께 주로 쓰는 경우가 대다수 입니다. (물론 헤더 파일에도 보통의 C 코드를 집어 넣을 수 있지만 권장하지는 않습니다.)



* 전역 변수


* 구조체, 공용체, 열거형




* 함수의 원형


* 일부 특정한 함수 (인라인 함수.. 나중에 설명함)


* 매크로 (나중에 설명함)




우리는 그 중에서도 위의 3 개 정도만 지금 사용해 보도록 하겠습니다. 다른 것들은 나중에 배워 가면서 익히도록 하죠.

이번에 만들어 볼 것은 `Human` 이라는 구조체 입니다. `Human` 구조체에서 가질 정보는, 사람의 이름, 나이, 성별 입니다. 또한, 이 구조체 변수에 대한 정보를 출력하는 함수와, 이 구조체를 설정하는 함수들이 필요합니다.

먼저, `Human` 구조체 부터 봅시다.

```cpp
/* human.h */
enum {MALE, FEMALE};

struct Human
{
    char name[20];
    int age;
    int gender;
};

struct Human Create_Human(char *name, int age, int gender);
int Print_Human(struct Human *human);

```

`human.h` 에는 위와 같은 것들이 포함되어 있습니다. 일단 열거형으로 남자와 여자에 대한 정수값들이 선언되어 있으며, `Human` 구조체, 그리고 한 `Human` 구조체 변수를 설정하는 `Create_Human` 함수와 한 `Human` 에 대한 정보를 출력하는 `Print_Human` 함수들이 설정되어 있습니다.

그럼 이 함수들에 대한 정보를 가지는 `human.c` 파일을 봅시다.

```cpp
/* human.c */
#include "human.h"
#include "str.h"
#include <stdio.h>

struct Human Create_Human(char *name, int age, int gender)
{
    struct Human human;

    human.age = age;
    human.gender = gender;
    copy_str(human.name, name);

    return human;
}
int Print_Human(struct Human *human)
{
    printf("Name : %s \n", human->name);
    printf("Age : %d \n", human->age);
    if(human->gender == MALE)
    {
        printf("Gender : Male \n");
    }
    else if(human->gender == FEMALE)
    {
        printf("Gender : Female \n");
    }

    return 0;
}
```


일단 `Human` 구조체를 사용하므로 이 구조체에 대한 설명이 들어있는 `human.h` 와, `printf` 를 위한 `stdio.h,` 그리고 `copy_str` 함수를 위한 `str.h` 헤더 파일들을 모두 `include` 해주어야 합니다. 이를 안할 시에 함수를 찾을 수 없다는 오류가 발생하게 됩니다.

`str.h` 는 단순히 `copy_str` 함수를 위한 것이므로 `str.h` 에는 다음과 같이 써있습니다.

```cpp
/* str.h */
char copy_str(char *dest, char *src);

```

또한

```cpp
/* str.c */
#include "str.h"

char copy_str(char *dest, char *src)
{
    while (*src)
    {
        *dest = *src;
        src ++;
        dest ++;
    }

    *dest = '\0';

    return 1;
}
```


와 같이 함수의 몸체가 나타나 있지요. 자, 그럼 `main` 함수가 위치한 `test.c` 를 봅시다.

```cpp
#include <stdio.h>
#include "human.h"
int main()
{
    struct Human Lee = Create_Human("Lee", 40, MALE);

    Print_Human(&Lee);

    return 0;
}
```


상당히 간단합니다. 이는 우리가 파일을 잘 나누었기 때문입니다. 좋은 프로그램일 수 록 `main` 함수에서 하는 일이 적어집니다.
성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F1845010D4C45CCA868064E)

위에서 소스를 설명하면서 다 말했기 때문에 굳이 설명할 부분은 없습니다만, 만일 위 소스에서 하나라도 이해가 되지 않는 부분이 있다면 반드시 이전 강의를 복습해주시기 바랍니다.

이제 파일을 분할하는 과정에 대해 배웠으니 파일을 분할하는 것을 습관을 들이시기 바랍니다. 처음에 함수를 배웠을 때 프로그래밍이 상당히 편해진 것 처럼 파일을 분할하게 되면 프로그래밍이 상당히 편해지는 것을 느끼실 수 있을 것입니다. 각 소스 파일에 정확히 무엇을 하는지 나타내주는 것이 중요합니다.



###  다른 사람이 만들어 놓은 것 쓰기


이번에는 파일을 분할하는 것 만큼이나 중요한 것에 대해 알아볼 시간 입니다. 바로 '다른 사람이 만들어 놓은 함수들' 을 사용하는 방법에 대해서 말이지요. 이렇게 다른 사람들이 만들어 놓은 것을 가리켜서 **라이브러리** 라고 합니다. 우리가 도서관에 가서 책을 고르듯이, C 프로그래밍에서 우리는 원하는 함수를 라이브러리에서 찾아 사용할 수 있습니다. 이는 정말로 편리한 일이지요. 시시 콜콜 하게 함수들을 귀찮게 만들 필요가 없다는 말입니다.

아래 예제는 기존에 우리가 `copy_str` 을 이용하여 `str1` 에 `str2` 를 복사하는 과정을 나타냈습니다.

```cpp
/* test.c */
#include <stdio.h>
#include "str.h"
int main()
{
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};

    copy_str(str1, str2);

    printf("str1 : %s \n", str1);

    return 0;
}
```


```cpp
/* str.h */
char copy_str(char *dest, char *src);
```


```cpp
/* str.c */
#include "str.h"
char copy_str(char *dest, char *src)
{
    while (*src)
    {
        *dest = *src;
        src ++;
        dest ++;
    }

    *dest = '\0';

    return 1;
}
```



성공적으로 컴파일 했다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F1770D4364C45CE608F659A)

일단 위와 같이 잘 복사되었음을 알 수 있습니다. 하지만 이는 정말로 귀찮은 일이 아닐 수 없습니다. 문자열을 복사하는 과정은 정말로 많이 쓰이는 것입니다. 이렇게 문자열 복사가 필요할 때 마다 `copy_str` 함수를 만들어서 쓴다면 참으로 귀찮은 일이 아닐 수 없습니다. 하지만 정말 다행스럽게도, 사람들은 이 역할을 하는 함수를 '미리' 만들어 놓았습니다.

```cpp
/* 라이브러리의 사용 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};

    strcpy(str1, str2);

    printf("str1 : %s \n", str1);

    return 0;
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F1770D4364C45CE608F659A)

와 같이 위와 똑같이 나옵니다.

```cpp
#include <string.h>
```

위 명령은 "string.h" 파일에 있는 내용을 모두 가져다 붙인다 라는 의미를 가지고 있습니다. 그런데 이 `string.h` 파일에는 '문자열을 처리하는데 관련된 함수들의 원형' 모음이 있습니다. 따라서 우리는 이 파일을 `include` 시킴으로써 문자열을 처리하는 여러가지 편리한 함수들을 사용할 수 있게 됩니다. 우리가 `str.h` 를 `include` 해서 `copy_str` 을 사용할 수 있었던 것과 일맥 상통합니다. 우리는 여기서 'strcpy' 라는 함수를 사용했습니다.

```cpp
    strcpy(str1, str2);
```


이 함수는 `copy_str` 과 사용법이 정확히 똑같습니다. 문자열을 복사하고자 하는 곳의 주소값을 첫번째 인자로, 복사가 되는 문자열의 주소값을 두번째 인자로 주면 됩니다.

이렇게 사람들이 미리 만든 함수들의 모임을 가리켜서 '라이브러리' 라고 합니다. 우리가 현재 사용한 라이브러리는 **문자열(string) 라이브러리** 입니다. 그렇다면 `stdio.h` 도 라이브러리 일까요? 맞습니다. 이는 **입출력 라이브러리** 로 입력과 출력에 관련된 함수들을 모아놓았습니다. 대표적으로 `prinf` 와 `scanf` 가 있지만 이전에 잠깐 소개했던 `getchar()` 함수나 `puts()` 등등 수 많은 함수가 여기에 정의되어 있습니다. 이 목록은 제 블로그 C 언어 레퍼런스를 참조하세요.

```cpp
/* strcmp 함수 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20] = {"hi"};
    char str2[20] = {"hello every1"};
    char str3[20] = {"hi"};

    if(!strcmp(str1, str2))
    {
        printf("%s and %s is equal \n", str1, str2);
    }
    else
    {
        printf("%s and %s is NOT equal \n", str1, str2);
    }

    if(!strcmp(str1, str3))
    {
        printf("%s and %s is equal \n", str1, str3);
    }
    else
    {
        printf("%s and %s is NOTequal \n", str1, str3);
    }

    return 0;
}
```


성공적으로 살펴 보았다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F152F3D264C45D10A38A0EF)



이번에 사용해본 함수는 `strcmp` 함수 입니다.

이 함수는 두 문자열을 비교해서 두 문자열이 같다면 0 을 다르면 0 이 아닌 값을 리턴하게 되어 있습니다.
이 함수의 사용법도 이전에 우리가 만들었던 `compare_str` 함수와 동일합니다. 첫 번째와 두 번째 인자에는 비교할 문자열들의 주소를 넣어주면 됩니다.

이렇게, 다른 라이브러리의 함수들을 사용하니 상당히 편리합니다. 이번에는 `string` 라이브러리 말고도 다른 여러가지 라이브러리들이 많은데 이 들에 대한 정보는 여러분이 직접 찾아보세요



###  # 친구들




여태까지 우리는 `#include` 라는 명령에 대해 알아보았습니다. 이렇게 # 이 들어간 명령들은 ‘전처리기 명령’ 이라고 하는데 전처리기의 의미는 컴파일 이전에 처리된다는 뜻 입니다. 즉, 컴파일이 되기 이전에 `#include` 라는 부분은 `#include` 에 해당하는 파일의 소스 코드로 정확히 바뀝니다.

이전 강좌에서 `stdio.h` 의 내용을 썼었을 때, `#include` 말고도 `#` 이 들어가 있는 엄청나게 많은 수의 명령들을 볼 수 있었습니다. 예를 들면 `#define, #ifdef` 등등 이죠. 이번에는 이러한 다양한 종류의 전처리기 명령들에 대해 알아보도록 합시다.

#### #define

```cpp
/* #define */
#include <stdio.h>
#define VAR 10
int main()
{
      char arr[VAR] = {"hi"};
    printf("%s\n", arr);
    return 0;}
```

성공적으로 컴파일 하였다면



![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1153F6234C4E846069CEC3)




여러분은 아마도 배열을 정의하는데 대괄호 안어에 수가 아닌 값이 들어왔는데도 컴파일이 어떻게 잘되고 실형 역시 잘되었는지 놀랐었을 수 도 있습니다. 배열을 정의할 때 대괄호 안에는 언제가 수가 와야 합니다. 심지어 상수 조차 올 수 없습니다. 하지만 위 경우 어떻게 된 것일까요?

`#define` 명령은 다음과 같이 사용합니다.

```info
#define 매크로이름 값
// 전처리기 문들은 끝에 ; 를 붙이지 않습니다!!
```



이는 소스 코드에서 ‘매크로이름’ 에 해당하는 부분을 ‘값’ 으로 대체하게 되는 것입니다. 물론, 전처리기 명령이기 때문에 컴파일 이전에 정확하게 대체됩니다. 따라서,

```cpp

#include <stdio.h>
#define VAR 10
int main()
{
    char arr[VAR] = {"hi"};
    printf("%s\n", arr);
    return 0;
}
```



라는 문장은

```cpp

#include <stdio.h>
int main()
{
    char arr[10] = {"hi"};
    printf("%s\n", arr);
    return 0;
}

```


과 완전히 똑같은 문장 입니다. 이 작업이 컴파일 이전에 처리되기 때문에 컴파일러 입장에서는 `arr[10]` 이라는 문장을 처리하는 것과 똑같으므로 오류 없이 정확하게 수행될 수 있다는 것이죠.

#### #ifdef, endif`

`ifdef` 와 `endif` 는 무언가 `if` 문과 관련이 있을 것 같습니다. `if` 문 처럼 특정한 조건에만 수행이 되겠지요.

```cpp

/* ifdef */
#include <stdio.h>#define A
int main(){
#ifdef A    printf("AAAA \n");#endif
#ifdef B    printf("BBBB \n");#endif
    return 0;}
```



성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F206F8D204C4E8453AB502D)



만일, #define 부분을 #define `A` 에서 #define `B` 로 바꿔보면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F1932ED234C4E846003ADD5)


와 같이 나옵니다.
상당히 재미있지요. 일단 `ifdef` 는 다음과 같은 형식으로 사용됩니다.

```info

#ifdef 매크로이름

// ‘매크로’ 가 정의되었다면 이 부분이 코드에 포함되고 그렇지 않다면 코드에 포함되지 않는다.
코드

#endif
```



언제나 `ifdef` 는 `endif` 와 짝을 지어서 사용하는데, `ifdef` 에서 지정한 매크로가 정의되어 있다면 `ifdef` 와 `endif` 속에 있는 코드가 포함되고 그렇지 않다면 코드에 포함되지 않는 것으로 간주 됩니다. `#define A` 를 통해 `A` 가 정의 되어 있다면

```cpp
#ifdef A
    printf("AAAA \n");
#endif
```


부분은 전처리기에 의해

```cpp
    printf("AAAA \n");
```



로 바뀌지만


```cpp
#ifdef B
    printf("BBBB \n");
#endif
```


부분은 소스에 포함되어 있지 않은 것으로 간주되어 컴파일러 입장에서는 마치 주석 처럼 무시됩니다.
만일 `#define A` 대신에 `#define B` 를 하게 된다면 반대의 상황이 연출되고, 둘 다 `define` 해주게 된다면 둘 다 코드에 포함이 되겠지요. 이와 같은 기능을 도대체 왜 만들었냐고도 물어볼 수 있는데 사실 이 ‘조건부 컴파일 (특정한 조건에 따라 컴파일 되는 부분이 다른 것)’ 은 상당히 유용하게 쓰일 수 있습니다.

예를 들어 계산기 프로그램을 만드는데, 계산기 모델 마다 조금씩 메모리와 CPU가 틀려서 어떤 계산기에는 `double` 을 사용할 수 있지만 어떤 모델에서는 `float` 밖에 사용할 수 없다고 합시다.

그렇다면 각각 이 계산기를 위해 다음과 같이 소스를 짜야 할 것입니다.

```cpp

/*
계산기 모델 1 을 위한 코드
calculator1.c
*/
float var1, var2;
// do something
```



```cpp

/*
계산기 모델 2 을 위한 코드
calculator2.c
*/
double var1, var2;
// do something
```



하지만 조건부 컴파일을 이용하면 이 두 개의 파일로 나누어서 해야 했던 작업을 다음과 같이 줄일 수 있습니다.

```cpp

#define CACULATOR_MODEL_1

#ifdef CALCULATOR_MODEL_1
float var1, var2;
#endif
#ifdef CALCULATOR_MODEL_2
double var1, var2;
#endif;
//do something
```



이 때, `define` 되는 것이 무엇이냐에 따라 간단히 무엇을 컴파일 할 것인지를 나타낼 수 있습니다.
사실 `ifdef` 와 `endif` 가 사용되는 경우는 이것보다 훨씬 많지만 일단 여기서 매듭 짓기로 하겠습니다.


위 조건부 컴파일에서 #else 라는 것도 사용할 수 있는데 이는 #ifdef 의 경우 이외의 나머지 것들을 처리하는 것입니다. 이 역시 #endif 로 항상 끝을 맺어주어야 합니다. 예를 들면 아래와 같지요.

```cpp

#ifdef CALC_1
// do something
#else
//do something ‘else’
#endif
```



또한 `#ifdef` 의 친구로 `#ifndef` 도 있는데 이는 ‘매크로가 정의되어 있지 않다면’ 참이 됩니다. `#ifdef` 의 정 반대이지요.
이 기능들에 대해서는 나중에 좀더 큰 프로젝트를 진행하면서 차근 차근 알아가보도록 합시다.

### 생각해보기

#### 문제 1

헤더 파일이 두 번 중복되서 `include` 되지 않기 위해서는 헤더파일에 어떠한 조건문을 넣으면 좋을 지 생각해보세요.



```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <18 - 2. 파일 뽀개기 (# 친구들, 라이브러리)>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```



