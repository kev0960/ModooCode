----------------
title : 씹어먹는 C 언어 - <18 - 1. 파일 뽀개기 (헤더파일과 #include) >
cat_title : 18 - 1. 파일 뽀개기 (헤더파일과 #include)
next_page : 88
--------------


이번 강좌에서는

* 모듈화 프로그래밍 (파일 나누기)

* #include 전처리기에 대한 이해


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F194C3F154C4076333A0245)

안녕하세요 여러분. 저도 강좌를 쓰는 것이 참으로 오래간만 입니다. 현재 저는 강좌를 모두 모두 모아 하나의 pdf 파일로 만드려고 노력중입니다. 이를 위해 `Latex` 를 사용하고 있는데 한국 `Latex` 커뮤니티 (KTUG) 분들께서 훌륭하게 만들어주신 `kotex` 덕분에 수월하게 파일 제작이 가능합니다. 아무튼 감사하다는 말씀을 드리며 강좌를 시작해 나가보도록 하겠습니다.

현재까지 여러분은 모든 소스 코드를 하나의 소스 파일에서 작성하였습니다. 사실 이는 큰 문제가 아니였습니다. 왜냐하면 우리가 여태 까지 만들었던 프로그램의 총 소스 길이는 그다지 길지 않았고 또 나 혼자 만들기 때문에 하나의 파일에 모조리 작성해도 상관이 없었습니다. 하지만 여러분이 프로그래머가 되어서 회사에서 프로그래밍을 한다면 소스의 길이도 수천~ 수만줄에 이르고, 여러 사람들이 만들기 때문에 파일을 여러개로 나누어야 할 필요성이 있습니다. 물론 파일을 나눌 때 에는 비슷한 작업을 하는 것 끼리 나누는 것이 좋겠죠.

```cpp
/* 평범한 문장 */
#include <stdio.h>
char compare(char *str1, char *str2);
int main()
{
    char str1[20];
    char str2[20];

    scanf("%s", str1);
    scanf("%s", str2);

    if(compare(str1, str2))
    {
        printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
    }
    else
    {
        printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
    }
     return 0;
}

char compare(char *str1, char *str2)
{
    while (*str1)
    {
        if(*str1 != *str2)
        {
            return 0;
        }

        str1++;
        str2++;
    }

    if(*str2 == '\0')
        return 1;

    return 0;
}
```


성공적으로 컴파일 하였다면



![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F130E31144C40527F9208AF)


와 같이 나옵니다.

만일 같은 두 문장을 사용하였다면 같다는 메세지가 뜨겠지요. 위 소스 코드는 아주아주 쉬운 내용으로 여태까지 내용을 잘 이수하였다면 잘 이해하실 수 있을 것입니다. 다만,

```cpp
    if(compare(str1, str2))
```


이 부분에서 살짝 갸우뚱 하시는 분들이 있으실 텐데 우리가 만든 `compare` 함수는 두 문자열이 같으면 `1,` 다르면 0 을 리턴합니다. 그런데 `if` 문의 경우 괄호 안의 값이 0 이면 '거짓' 으로, 0 이 아니면 '참' 으로 판단하기 때문에 (이는 이전 강좌에서 이야기 했던 바 입니다. 기억이 안나면 [http://itguru.tistory.com/10](http://itguru.tistory.com/10) 를 보세요) 우리가 원하는 결과를 얻을 수 있었던 것이지요.

그렇다면 이번에는 이 강좌의 주제에 맞게 파일을 분할해봅시다. `compare` 함수는 상당히 다른 일을 하고 있기 때문에 굳이 `main` 함수와 같은 파일에 둘 필요가 없습니다. 따라서 다른 파일에 만들어 보겠습니다.



###  파일 나누기

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F190193344C4053CBBD99BB)
먼저 위의 그림과 같이 오른쪽 파일 목록이 나와 있는 부분에서 '소스 파일' 폴더를 클릭한 후 마우스 오른쪽 클릭을 한 후, '새 항목' 을 위와 같이 누릅니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F172A08344C4053CC2CB431)

그러면 위와 같이 새 항목을 추가할 수 있는 화면이 뜨는데 우리는 'C++ 파일(.cpp)' 을 선택하고, 이름에 `str` 을 적습니다. `str` 을 적은 이유는 우리가 만든 `compare` 함수는 문자열을 처리하므로 이에 맞게 `str` 이라는 이름을 붙여 주었습니다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F160643374C40544BC789F8)
하지만 우리가 하려는 것이 C 언어 이지 C++ 이 아니므로 파일 이름을 `str.c` 로 변경해줍니다. 이는 파일을 클릭한 후 `F2` 를 누르면 파일이름을 변경할 수 있습니다. (또는 마우스 오른쪽 클릭 후 이름 바꾸기를 누른다)


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F112028344C4053CC733B8F)

이제, `test.c` (저의 기존 소스를 보관했던 파일 명 입니다. 여러분의 경우 다를 수 있습니다.) 에 쓰여 있던 기존의 `compare` 함수 소스를 잘라옵니다. 즉, `test.c` 에 있던 `compare` 함수 소스는 사라지고 `str.c` 에 `compare` 함수 소스를 넣는 것입니다.

위 작업이 끝나게 된다면 각 파일에는 다음과 같이 소스가 들어가 있을 것입니다.

```cpp
/*
test.c
여러분과 파일 이름은 다를 수 있습니다.
*/
#include <stdio.h>
char compare(char *str1, char *str2);
int main()
{
    char str1[20];
    char str2[20];

    scanf("%s", str1);
    scanf("%s", str2);

    if(compare(str1, str2))
    {
        printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
    }
    else
    {
        printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
    }
     return 0;
}
```


```cpp
/*
str.c
*/

char compare(char *str1, char *str2)
{
    while (*str1)
    {
        if(*str1 != *str2)
        {
            return 0;
        }

        str1++;
        str2++;
    }

    if(*str2 == '\0')
        return 1;

    return 0;
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F130E31144C40527F9208AF)

아까와 동일한 결과를 얻을 수 있었습니다.

일단 위 프로그램이 어떻게 작동하는지 살펴 봅시다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F13697A0E4C406E8688A9DF)


아마 예전에 배워서 까먹었을 가능성이 있는데 우리가 실행 파일을 만들기 위해서는 먼저 C 코드를 컴퓨터가 이해할 수 있는 언어로 바꿔주는 **컴파일(compile)** 이라는 과정이 진행됩니다. 이는 단일 소스 코드 전체를 어셈블리어 (기계어와 1 : 1 대응이 되어 있음) 로 변환해 줍니다 (이 때, 목적코드라 불리는 확장자가 `.o` 인 파일이 생성됩니다). 이 과정이 끝나게 되면 **링킹(linking)** 이라는 과정이 진행되는데 말그대로 각기 다른 파일에 위치한 소스 코드들을 한데 엮어서 하나의 실행 파일로 만들어지는 과정이라 생각하시면 됩니다.

링킹 과정에서 특정한 소스 파일에 있는 함수들이 어디어디에 있는지 찾는 과정을 거치게 되는데 예를 들어서 `test.c` 의 경우 `compare` 함수가 어디있는지 찾게 됩니다. (눈치가 빠른 독자라면 `printf` 함수 역시 찾아야 함을 알 수 있는데 이에 대한 설명은 나중에 하겠습니다)

우리의 예제의 경우 `compare` 함수는 `str.c` 에 있기 때문에 **링커**(링킹을 해주는 프로그램) 는 'test.c 에서 `compare` 함수를 호출하는 경우 `str.c` 에서 찾아라' 정도로 처리해 주게 됩니다. 덕분에 우리는 `test.c` 에서 `compare` 함수를 호출하더라도 `str.c` 의 `compare` 함수를 이용할 수 있게 되는 것이지요.

만일 `test.c` 에서

```cpp
char compare(char *str1, char *str2);
```


부분을 지워버리면 어떨까요? 이렇게 된다면 컴파일러는 'main 함수에서 `compare` 함수를 호출하였는데, 도대체 `compare` 함수는 어떻게 생긴 모양이야!' 가 되어 컴파일 시에 오류가 발생하게 됩니다. 물론 링커의 경우도 `compare` 함수의 정확한 모양이 무엇인지 알 수 없으므로 오류가 발생하게 되죠.

따라서 이렇게 언제나 함수의 선언을 명시해 주는 것은 매우 중요한 일입니다.

하지만 `compare` 라는 함수 말고도 `copy` 라는 함수가 `str.c` 에 추가되었습니다. 이 함수는 두 문자열을 복사해주는 역할을 합니다. `copy` 라는 함수를 `test.c` 에서 이용하기 위해선 역시 `copy` 함수의 원형을 써주어야 합니다. 이는 상당히 귀찮은 일이지요. 뿐만 아니라 다른 파일에서도 `compare` 함수와 `copy` 함수를 이용할 수 있는데 이 파일 역시 이 두 함수의 원형을 써주어야 합니다.

이렇게 귀찮은 작업을 막기 위해 C 에서는 아주 놀라운 해결책을 제시하였는데 바로 **헤더파일 (header file)** 을 이용하는 것입니다. 헤더파일은 다음과 같은 방법으로 만들 수 있습니다.



###  헤더 파일

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F160941104C4069157ABB63)
먼저 기존에 `str.c` 파일을 추가했을 때 했던 것 처럼 하되 이번에는 헤더파일 폴더에 파일을 추가해보도록 합시다.


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F206DC2104C4069211A9828)

헤더파일을 추가하는 것이므로 '헤더파일' 을 선택한 후, 이름에 `str` 을 적습니다.



![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F1367AB104C40696025CB87)

그리고 헤더파일에는 위와 같이 내용을 기록합니다. 그 후, 각 소스 코드를 다음과 같이 수정해줍니다.

```cpp
/* test.c */
#include <stdio.h>
#include "str.h"
int main()
{
    char str1[20];
    char str2[20];

    scanf("%s", str1);
    scanf("%s", str2);

    if(compare(str1, str2))
    {
        printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
    }
    else
    {
        printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
    }
     return 0;
}
```




```cpp
/* str.c */
#include "str.h"

char compare(char *str1, char *str2)
{
    while (*str1)
    {
        if(*str1 != *str2)
        {
            return 0;
        }

        str1++;
        str2++;
    }

    if(*str2 == '\0')
        return 1;

    return 0;
}


```



```cpp
/* str.h */
char compare(char *str1, char *str2);
```



  성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F15681B1C4C406A05628C04)

역시 위와 같이 잘 작동하고 있음을 알 수 있습니다.

먼저 `test.c` 부터 살펴봅시다.

```cpp
#include <stdio.h>
#include "str.h"

```

`#include` 와 같은 명령들은 **전처리기(Preprocessor)** 명령이라고 부르는데 이러한 명령들의 특징은 컴파일 이전에 실행된다는 점 입니다.이 명령은 우리가 지칭하는 파일의 내용을 정확히 `100%` 복사해서 붙여 넣는다는 점입니다. 따라서 `#include "str.h"` 라는 명령은 `str.h` 에 있었던 내용, 즉 `char compare(char *str1, char *str2);` 로 컴파일이 시작하기 전에 바뀌어 버립니다.

그렇다면 `#include <stdio.h>` 는 어떨까요? 이 역시 똑같습니다. `stdio.h` 에 써있는 내용들이 정확히 복사되어 컴파일 이전에 코드에 붙어버립니다. 그런데 한 가지 이상한 점은 `stdio.h` 는 `<>` 로 감쌌는데, `str.h` 는 왜 " " 로 감쌌을까요? 그 이유는 단순한데, `< >` 로 감싸는 헤더파일은 컴파일러에서 기본으로 지원하는 헤더파일의 경우이고 " " 로 감싸는 헤더파일은 사용자가 직접 제작한 헤더파일의 경우 입니다.

여러분은 `stdio.h` 에 무엇이 써져 있는지 궁금하지 않으세요? 한 번 제가 그 내용을 올려드리겠습니다. 참고로 [여기](https://code.woboq.org/userspace/glibc/libio/stdio.h.html)에서 전체 코드를 보실 수 있습니다.

```cpp

#ifndef _STDIO_H
#define _STDIO_H        1
#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#include <bits/libc-header-start.h>
__BEGIN_DECLS
#define __need_size_t
#define __need_NULL
#include <stddef.h>
#define __need___va_list
#include <stdarg.h>
#include <bits/types.h>
#include <bits/types/__fpos_t.h>
#include <bits/types/__fpos64_t.h>
#include <bits/types/__FILE.h>
#include <bits/types/FILE.h>
#include <bits/types/struct_FILE.h>
#ifdef __USE_GNU
# include <bits/types/cookie_io_functions_t.h>
#endif
#if defined __USE_XOPEN || defined __USE_XOPEN2K8
# ifdef __GNUC__
#  ifndef _VA_LIST_DEFINED
typedef __gnuc_va_list va_list;
#   define _VA_LIST_DEFINED
#  endif
# else
#  include <stdarg.h>
# endif
#endif
#if defined __USE_UNIX98 || defined __USE_XOPEN2K
# ifndef __off_t_defined
# ifndef __USE_FILE_OFFSET64
typedef __off_t off_t;
# else
typedef __off64_t off_t;
# endif
# define __off_t_defined
# endif
# if defined __USE_LARGEFILE64 && !defined __off64_t_defined
typedef __off64_t off64_t;
# define __off64_t_defined
# endif
#endif
#ifdef __USE_XOPEN2K8
# ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
# endif
#endif
/* The type of the second argument to `fgetpos' and `fsetpos'.  */
#ifndef __USE_FILE_OFFSET64
typedef __fpos_t fpos_t;
#else
typedef __fpos64_t fpos_t;
#endif
#ifdef __USE_LARGEFILE64
typedef __fpos64_t fpos64_t;
#endif
/* The possibilities for the third argument to `setvbuf'.  */
#define _IOFBF 0                /* Fully buffered.  */
#define _IOLBF 1                /* Line buffered.  */
#define _IONBF 2                /* No buffering.  */
/* Default buffer size.  */
#define BUFSIZ 8192
/* The value returned by fgetc and similar functions to indicate the
   end of the file.  */
#define EOF (-1)
/* The possibilities for the third argument to `fseek'.
   These values should not be changed.  */
#define SEEK_SET        0        /* Seek from beginning of file.  */
#define SEEK_CUR        1        /* Seek from current position.  */
#define SEEK_END        2        /* Seek from end of file.  */
#ifdef __USE_GNU
# define SEEK_DATA        3        /* Seek to next data.  */
# define SEEK_HOLE        4        /* Seek to next hole.  */
#endif
#if defined __USE_MISC || defined __USE_XOPEN
/* Default path prefix for `tempnam' and `tmpnam'.  */
# define P_tmpdir        "/tmp"
#endif
/* Get the values:
   L_tmpnam        How long an array of chars must be to be passed to `tmpnam'.
   TMP_MAX        The minimum number of unique filenames generated by tmpnam
                (and tempnam when it uses tmpnam's name space),
                or tempnam (the two are separate).
   L_ctermid        How long an array to pass to `ctermid'.
   L_cuserid        How long an array to pass to `cuserid'.
   FOPEN_MAX        Minimum number of files that can be open at once.
   FILENAME_MAX        Maximum length of a filename.  */
#include <bits/stdio_lim.h>
/* Standard streams.  */
extern FILE *stdin;                /* Standard input stream.  */
extern FILE *stdout;                /* Standard output stream.  */
extern FILE *stderr;                /* Standard error output stream.  */
/* C89/C99 say they're macros.  Make them happy.  */
#define stdin stdin
#define stdout stdout
#define stderr stderr
/* ... 너무 길어서 생략 ... */
```


만일 헤더 파일이라는 것이 존재하지 않았더라면 우리는 `printf` 함수를 이용하기 위해서 위 모든 내용은 아니지만 적어도 `printf` 함수의 원형을 써주어야 하는데 이는

```cpp
_Check_return_opt_ _CRTIMP int __cdecl printf(_In_z_ _Printf_format_string_ const char * _Format, ...);
```


로 무지하게 복잡합니다. 아무튼, 이렇게 `printf, scanf` 함수와 같이 매 함수를 쓰기 위해서 위 모든 내용을 쓰는 것 대신에 헤더파일 `include` 하나로 간단하게 해결할 수 있습니다.

보통 헤더파일을 만들 때 에는 그 헤더파일에 있는 함수들이 정의되어 있는 소스 파일의 이름을 따서 짓는 것이 보통입니다. 위 경우 `str.h` 에 선언되어 있는 함수들이 모두 `str.c` 에 정의되어 있으므로 헤더파일의 이름을 `str.h` 로 하였습니다. 또한 한 가지 흥미로운 점은 `str.c` 에서도 `str.h` 를 `include` 하고 있다는 점입니다.

이는 다음과 같은 상황을 방지할 수 있습니다.

```info
/* something.c */
int A()
{
    B();
    return 0;
}
int B()
{
    return 1;
}
```


만일 `something.c` 라는 파일에 위와 같은 소스가 있다고 합시다. 이는 `100%` 오류가 발생됩니다. 왜냐하면 `A()` 함수에서 `B()` 를 호출할 때 `B` 가 무엇인지 뭔지 모르므로 오류가 발생하게 되는 것이지요. (이는 함수 단원에서 공부한 한 바 입니다) 다시 말해 `B()` 를 위에 선언 해주어야 합니다. 아래와 같이요.

```info
/* something.c */
int B();
int A()
{
    B();
    return 0;
}
int B()
{
    return 1;
}
```


하지만 헤더파일을 배웠으니 차라리 이렇게 할 바에는 아래와 같이 하는 것이 훨씬 낫을 것이라는 거죠.

```info
/* something.c */
#include "something.h"
int A()
{
    B();
    return 0;
}
int B()
{
    return 1;
}
```


```info
/* something.h*/

int A();
int B();
```


이와 같은 이유로 `str.c` 에서도 (이 경우 꼭 필요는 없었지만) `str.h` 를 `include` 해준 것입니다.

도서 관리 프로그램 리모델링

그렇다면 이번에는 여태까지 쌓은 지식을 바탕으로 이전에 만들었던 도서 관리 프로그램을 파일을 나누어서 깔끔하게 만들어봅시다.

아래는 기존의 소스 입니다.

```cpp
#include <stdio.h>
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book);

char compare(char *str1, char *str2);
int borrow_book(int *borrowed);
int return_book(int *borrowed);

int main ()
{
    int user_choice; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */

    /* 각각 책, 저자, 출판사를 저장할 배열 생성. 책의 최대 개수는 100 권*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    /* 빌렸는지 상태를 표시 */
    int borrowed[100];

    while (1)
    {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");

        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);

        if(user_choice == 1)
        {
            /* 책을 새로 추가하는 함수 호출 */
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        }
        else if(user_choice == 2)
        {
            /* 책을 검색하는 함수 호출 */
            search_book(book_name, auth_name, publ_name, num_total_book);
        }
        else if(user_choice == 3)
        {
            /* 책을 빌리는 함수 호출 */
            borrow_book(borrowed);
        }
        else if(user_choice == 4)
        {
            /* 책을 반납하는 함수 호출 */
            return_book(borrowed);
        }
        else if(user_choice == 5)
        {
            /* 프로그램을 종료한다. */
            break;
        }
    }


    return 0;
}
/* 책을 추가하는 함수*/
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book)
{
    printf("추가할 책의 제목 : ");
    scanf("%s", book_name[*num_total_book]);

    printf("추가할 책의 저자 : ");
    scanf("%s", auth_name[*num_total_book]);

    printf("추가할 책의 출판사 : ");
    scanf("%s", publ_name[*num_total_book]);

    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/
    printf("추가 완료! \n");
    (*num_total_book)++;

    return 0;
}
/* 책을 검색하는 함수 */
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book)
{
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30];

    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 지은이 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf("%d", &user_input);

    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);

    printf("검색 결과 \n");

    if(user_input == 1)
    {
        /*

        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을
        사용자가 입력한 검색어와 비교하고 있다.

        */
        for(i = 0;i < num_total_book; i++)
        {
            if(compare(book_name[i], user_search))
            {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",
                    i, book_name[i], auth_name[i], publ_name[i] );
            }
        }

    }
    else if(user_input == 2)
    {
        /*

        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을
        사용자가 입력한 검색어와 비교하고 있다.

        */
        for(i = 0;i < num_total_book; i++)
        {
            if(compare(auth_name[i], user_search))
            {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",
                    i, book_name[i], auth_name[i], publ_name[i] );
            }
        }

    }
    else if(user_input == 3)
    {
        /*

        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를
        사용자가 입력한 검색어와 비교하고 있다.

        */
        for(i = 0;i < num_total_book; i++)
        {
            if(compare(publ_name[i], user_search))
            {
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",
                    i, book_name[i], auth_name[i], publ_name[i] );
            }
        }
    }

    return 0;
}
char compare(char *str1, char *str2)
{
    while (*str1)
    {
        if(*str1 != *str2)
        {
            return 0;
        }

        str1++;
        str2++;
    }

    if(*str2 == '\0')
        return 1;

    return 0;
}
int borrow_book(int *borrowed)
{
    /* 사용자로 부터 책번호를 받을 변수*/
    int book_num;

    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &book_num);

    if(borrowed[book_num] == 1)
    {
        printf("이미 대출된 책입니다! \n");
    }
    else
    {
        printf("책이 성공적으로 대출되었습니다. \n");
        borrowed[book_num] = 1;
    }

    return 0;
}
int return_book(int *borrowed)
{
    /* 반납할 책의 번호 */
    int num_book;

    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &num_book);

    if(borrowed[num_book] == 0)
    {
        printf("이미 반납되어 있는 상태입니다\n");
    }
    else
    {
        borrowed[num_book] = 0;
        printf("성공적으로 반납되었습니다\n");
    }

    return 0;
}
```

파일들로 나누기 전에 가장 먼저 고려해야 할 사실은 바로 '어떠한 파일들로 나눌 것인가?’ 입니다. 파일을 나눌 때 가장 먼저 살펴보아야 할 점은 각 파일들을 특정한 역할을 가지도록 나누는 것인데 우리의 프로그램의 경우 다음과 같이 나누면 될 것 같습니다.`main` 함수를 가지는 `test.c ,` 도서 관리 함수들을 가지는 `book_function.c,` 그리고 문자열 관리 함수를 가지는 `str.c` 로 나누면 될 것 같습니다. 따라서 `book_function.h` 와 `str.h` 라는 헤더파일도 가지겠네요.
먼저 가장 단순한 `str.c` 부터 봅시다. `str.c` 에는 `compare` 함수가 들어가면 적당할 것 같습니다.

```cpp
/* str.c */
#include "str.h"
char compare(char *str1, char *str2)
{
    while (*str1)
    {
        if(*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    if(*str2 == '\0')
        return 1;
    return 0;
}
```

또한 `str.h` 에는 `compare` 함수의 원형이 선언되어 있죠.

```cpp

/* str.h */
char compare(char *str1, char *str2);
```



그럼 이제, 책들을 처리하는 함수들을 모아놓은 `book_function.c` 를 살펴봅시다. 단순하게 생각해보면 아래와 같이 하면 될 것 같습니다.

```cpp
#include "book_function.h"
/* 책을 추가하는 함수*/
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book)
{
    printf("추가할 책의 제목 : ");
    scanf("%s", book_name[*num_total_book]);
    printf("추가할 책의 저자 : ");
    scanf("%s", auth_name[*num_total_book]);

    printf("추가할 책의 출판사 : ");    scanf("%s", publ_name[*num_total_book]);
    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/
    printf("추가 완료! \n");    (*num_total_book)++;
    return 0;}/* 책을 검색하는 함수 */int search_book(char (*book_name)[30], char (*auth_name)[30],                char (*publ_name)[30], int num_total_book){
      int user_input; /* 사용자의 입력을 받는다. */
      int i;
      char user_search[30];
    printf("어느 것으로 검색 할 것인가요? \n");    printf("1. 책 제목 검색 \n");    printf("2. 지은이 검색 \n");    printf("3. 출판사 검색 \n");    scanf("%d", &user_input);
    printf("검색할 단어를 입력해주세요 : ");    scanf("%s", user_search);
    printf("검색 결과 \n");
    if(user_input == 1)    {
          /*
        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을        사용자가 입력한 검색어와 비교하고 있다.
        */        for(i = 0;i < num_total_book; i++)        {            if(compare(book_name[i], user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_name[i], auth_name[i], publ_name[i] );            }        }
    }    else if(user_input == 2)    { 
         /*
        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을        사용자가 입력한 검색어와 비교하고 있다.
        */
        for(i = 0;i < num_total_book; i++)        {            if(compare(auth_name[i], user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_name[i], auth_name[i], publ_name[i] );            }        }

    }    else if(user_input == 3)    {
          /*
        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를        사용자가 입력한 검색어와 비교하고 있다.
        */
        for(i = 0;i < num_total_book; i++)        {            if(compare(publ_name[i], user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_name[i], auth_name[i], publ_name[i] );            }        }    }
    return 0;}int borrow_book(int *borrowed){
      /* 사용자로 부터 책번호를 받을 변수*/
      int book_num;
    printf("빌릴 책의 번호를 말해주세요 \n");    printf("책 번호 : ");    scanf("%d", &book_num);
    if(borrowed[book_num] == 1)    {        printf("이미 대출된 책입니다! \n");    }    else    {        printf("책이 성공적으로 대출되었습니다. \n");        borrowed[book_num] = 1;    }
    return 0;}int return_book(int *borrowed){
      /* 반납할 책의 번호 */
      int num_book;
    printf("반납할 책의 번호를 써주세요 \n");    printf("책 번호 : ");    scanf("%d", &num_book);
    if(borrowed[num_book] == 0)    {        printf("이미 반납되어 있는 상태입니다\n");    }    else    {        borrowed[num_book] = 0;        printf("성공적으로 반납되었습니다\n");    }
    return 0;}
```



그런데 이렇게 하게 되면 `100%` 오류가 발생하게 됩니다. 왜냐하면 `add_book` 함수의 경우만 보아도 `printf` 함수와 `scanf` 함수를 사용하고 있기 때문이죠. 이 함수들을 사용하기 위해서는 `stdio.h` 를 꼭 `include` 해주어야 합니다. 뿐만 아니라 `search_book` 함수의 경우 `compare` 함수를 호출하고 있는데 이 때문에 역시 `str.h` 를 `include` 해주어야 합니다. 따라서 올바른 `book_function.c` 의 모습은 아래와 같이 되어야 합니다.

```cpp
/* book_function.c  */
#include <stdio.h>
#include "str.h"
#include "book_function.h"
/* 책을 추가하는 함수*/
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book)
{
    printf("추가할 책의 제목 : ");
    scanf("%s", book_name[*num_total_book]);

    printf("추가할 책의 저자 : ");    scanf("%s", auth_name[*num_total_book]);
    printf("추가할 책의 출판사 : ");    scanf("%s", publ_name[*num_total_book]);
    borrowed[*num_total_book] = 0; /* 빌려지지 않음*/
    printf("추가 완료! \n");    (*num_total_book)++;
    return 0;}/* 책을 검색하는 함수 */int search_book(char (*book_name)[30], char (*auth_name)[30],                char (*publ_name)[30], int num_total_book){    int user_input; /* 사용자의 입력을 받는다. */    int i;    char user_search[30];
    printf("어느 것으로 검색 할 것인가요? \n");    printf("1. 책 제목 검색 \n");    printf("2. 지은이 검색 \n");    printf("3. 출판사 검색 \n");    scanf("%d", &user_input);
    printf("검색할 단어를 입력해주세요 : ");    scanf("%s", user_search);
    printf("검색 결과 \n");
    if(user_input == 1)    {
          /*
        i 가 0 부터 num_total_book 까지 가면서 각각의 책 제목을        사용자가 입력한 검색어와 비교하고 있다.
        */
        for(i = 0;i < num_total_book; i++)        {            if(compare(book_name[i], user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_name[i], auth_name[i], publ_name[i] );            }        }
    }    else if(user_input == 2)    {
          /*
        i 가 0 부터 num_total_book 까지 가면서 각각의 지은이 이름을        사용자가 입력한 검색어와 비교하고 있다.
        */
        for(i = 0;i < num_total_book; i++)        {            if(compare(auth_name[i], user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_name[i], auth_name[i], publ_name[i] );            }        }
    }    else if(user_input == 3)    {
          /*
        i 가 0 부터 num_total_book 까지 가면서 각각의 출판사를        사용자가 입력한 검색어와 비교하고 있다.
        */
        for(i = 0;i < num_total_book; i++)        {            if(compare(publ_name[i], user_search))            {                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n",                    i, book_name[i], auth_name[i], publ_name[i] );            }        }    }
    return 0;}int borrow_book(int *borrowed){
      /* 사용자로 부터 책번호를 받을 변수*/
      int book_num;
    printf("빌릴 책의 번호를 말해주세요 \n");    printf("책 번호 : ");    scanf("%d", &book_num);
    if(borrowed[book_num] == 1)    {        printf("이미 대출된 책입니다! \n");    }    else    {        printf("책이 성공적으로 대출되었습니다. \n");        borrowed[book_num] = 1;    }
    return 0;}int return_book(int *borrowed){
      /* 반납할 책의 번호 */
      int num_book;
    printf("반납할 책의 번호를 써주세요 \n");    printf("책 번호 : ");    scanf("%d", &num_book);
    if(borrowed[num_book] == 0)    {        printf("이미 반납되어 있는 상태입니다\n");    }    else    {        borrowed[num_book] = 0;        printf("성공적으로 반납되었습니다\n");    }
    return 0;}
```



또한 당연하게도 `book_function.h` 의 모습은 아래와 같겠죠.

```cpp
/* book_function.h */
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book);
int borrow_book(int *borrowed);
int return_book(int *borrowed);
```



이제 마지막으로 `main` 함수가 있는 `test.c` 를 살펴볼 차례 입니다.

`main` 함수에서는 `printf` 와 `scanf` 등과, `book_function` 에 정의되어 있는 함수들을 사용하고 있고 `compare` 함수는 사용하지 않으므로 다음과 같이만 해주면 됩니다.

```cpp
/* test.c */
#include <stdio.h>
#include "book_function.h"
int main ()
{
    int user_choice; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */
    /* 각각 책, 저자, 출판사를 저장할 배열 생성. 책의 최대 개수는 100 권*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    /* 빌렸는지 상태를 표시 */
    int borrowed[100];
    while (1)
    {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);
        if(user_choice == 1)
        {
            /* 책을 새로 추가하는 함수 호출 */
            add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
        }
        else if(user_choice == 2)
        {
            /* 책을 검색하는 함수 호출 */
            search_book(book_name, auth_name, publ_name, num_total_book);
        }
        else if(user_choice == 3)
        {
            /* 책을 빌리는 함수 호출 */
            borrow_book(borrowed);
        }
        else if(user_choice == 4)
        {
            /* 책을 반납하는 함수 호출 */
            return_book(borrowed);
        }
        else if(user_choice == 5)
        {
            /* 프로그램을 종료한다. */
            break;
        }
    }
    return 0;
}
```



어때요? 꽤 간단하지요. 이 작업을 한 후 컴파일 후 실행하면 역시나 잘 작동됨을 알 수 있습니다. 이렇게 여러분은 파일을 나누는 방법에 대해서 알게 되었습니다. 이렇게 파일을 나누어서 처리하게 되면 상당히 체계적으로 프로그래밍을 할 수 있는데 이렇게 하는 프로그래밍을 모듈화 프로그래밍 (modular programming) 이라고 합니다. 즉 프로그램의 각 부분 부분을 나누어서 따로 처리 한다는 의미지요.

우리는 여태까지 헤더 파일에는 함수의 선언 밖에 쓰지 않았지만 사실 헤더파일에도 많은 것들이 올 수 있습니다. 이에 대해서는 다음 시간에 알아보도록 합시다.

### 생각해 볼 문제

#### 문제 1

위 도서 관리 프로그램을 구조체를 이용하여 만든 것이 있을 것입니다. ( [http://itguru.tistory.com/60](http://itguru.tistory.com/60) 생각해 볼 문제 참조) 이 역시 위와 같이 파일로 쪼개 보세요.




```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <18 - 1. 파일 뽀개기 (헤더파일과 #include) >>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```





