----------------
title : 씹어먹는 C 언어 - <15 - 4. 일로와봐, 문자열(string) - 도서 관리 프로젝트>
next_page : 55
--------------


이번 강좌에서는

* 도서 관리 프로그램을 만든다.



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F15077B1D4B6EE67712BF27)

안녕하세요 여러분. 지난번 강좌의 마지막 생각하기 문제를 기억하시나요? 일단 이 강의는 여러분이 그 문제에 대해 충분한 시간 노력해서 생각해 보았다는 것을 가정한 하에 진행하도록 하겠습니다.

지난번에 생각해보기 마지막 문제는 아래와 같았습니다.

```info
도서 관리 프로그램을 만들어봅시다. 프로그램에는 다음과 같은 기능들이 구현되어 있어야 합니다. (난이도 : 上)

* 책을 새로 추가하는 기능 (책의 총 개수는 100 권이라 하자. 이 때, 각 책의 정보는 제목, 저자의 이름, 출판사로 한다)

* 책의 제목을 검색하면 그 책의 정보가 나와야 한다.

* 위와 마찬가지로 저자, 출판사 검색 기능이 있어야 한다.

* 책을 빌리는 기능

* 책을 반납하는 기능


```

흠. 여러분은 위들 중 얼마나 해결 하셨나요? 저는 개인적으로 여러분이 위들 중에서 적어도`3 3`` 개 이상은 했으리라 믿고 싶습니다. 만일 그렇지 않다면 이 강의를 얼른 닫아서 다시 생각해보도록 하세요.



###  프로그램을 어떻게 만들 것인가?




사실 여러분이 이 문제를 해결했을 때 많은 어려움이 있었을 것이라 생각합니다. 왜냐하면 여러분은 아직까지 조그마한 작업들을 하는 프로그램만을 만들었지 이렇게 거대한(?) 프로그램은 만들어보지 않았기 때문이죠. 이렇게 거대한 프로그램을 만들 때면 이전의 작은 프로그램들을 만들때와는 달리 체계적으로 계획을 세우는 자세가 필요합니다.

이 때, 체계적으로 계획을 세우는 자세란 다음을 모두 생각해보는 것입니다.


1. 이 프로그램은 무슨 작업을 하는가?

1. 과연 이 작업이 꼭 필요한 것인가? (만일 그렇지 않다면 (1) 로 되돌아갑니다)



1. 어떠한 환경에서 프로그램이 작동되는가?



1. 무슨 언어로 개발할 것인가?


정도로 되겠습니다. 일단 1 번의 경우 프로그램을 계획하는 단계에서 가장 중요한 부분 중에 하나 입니다. 우리가 만들 프로그램의 경우 "도서 관리 프로그램" 입니다. 이 도서 관리 프로그램에는 정말 도서를 관리하는데 꼭 필요한 기능들 만이 들어가야 되겠지요. 예를 들면 제가 위해서 요구한 것들이지요. 만일 쓸데 없는 작업들을 많이 넣게 되면 프로그램 용량도 커질 뿐더러 개발하는데 드는 시간도 많이 들기 때문에 좋지 않습니다.

 2 번의 경우 1 번에서 내가 한 것들을 확인하는 단계입니다. 필요 없는 기능이나 꼭 필요하지 않거나, 아니면 이 프로그램의 목적과 부합하지 않는 작업들의 경우 다시 1 번으로 돌아가 생각해 보아야할 필요성이 있습니다. 우리가 만들어야 할 도서프로그램은 제가 요구한 조건 만을 만들어 주면 충분합니다.

`3` 번은 우리에게는 큰 문제가 아니지만 실제로 프로그램을 개발하게 되면 상당히 중요한 역할을 차지합니다. 우리가 만드는 프로그램은 `Windows` 에서 작동될 수 도 있고 `Linux` 나 `Machintosh` 에서 작동될 수 도 있습니다. 아니면 `TV` 나 냉장고 아니면 세탁기와 같은 가전 제품에서도 작동될 수 있고 요즘 가장 화제가 되는 `iPhone` 과 같은 스마트 폰에서 작동될 수 도 있습니다. 우리는 이러한 프로그램의 작동 환경에 맞추어 프로그램을 어떻게 만들어야 될지 고민해야 합니다. 예를 들어 은행의 `ATM` 에서 작동되는 프로그램은 보안이 최고로 우선이어야 겠죠. 비교적 속도가 느리더라도 말이죠. `iPhone` 과 같은 스마트 폰에서 작동하는 프로그램은 스마트폰의 사양이 보통 `PC` 보다 좋지 않으므로 프로그램을 가볍고 빠르게 만들어야 합니다. 우리가 만들 도서 관리 프로그램은 그냥 `Windows` 에서만 작동되도 충분합니다 3 번은 우리에게는 큰 문제가 아니지만 실제로 프로그램을 개발하게 되면 상당히 중요한 역할을 차지합니다. 우리가 만드는 프로그램은 `Windows` 에서 작동될 수 도 있고 `Linux` 나 `Machintosh` 에서 작동될 수 도 있습니다. 아니면 `TV` 나 냉장고 아니면 세탁기와 같은 가전 제품에서도 작동될 수 있고 요즘 가장 화제가 되는 `iPhone` 과 같은 스마트 폰에서 작동될 수 도 있습니다. 우리는 이러한 프로그램의 작동 환경에 맞추어 프로그램을 어떻게 만들어야 될지 고민해야 합니다. 예를 들어 은행의 `ATM` 에서 작동되는 프로그램은 보안이 최고로 우선이어야 겠죠. 비교적 속도가 느리더라도 말이죠. `iPhone` 과 같은 스마트 폰에서 작동하는 프로그램은 스마트폰의 사양이 보통 `PC` 보다 좋지 않으므로 프로그램을 가볍고 빠르게 만들어야 합니다. 우리가 만들 도서 관리 프로그램은 그냥 `Windows` 에서만 작동되도 충분합니다.

`4` 번은 프로그램을 어떠한 언어 (물론 우리의 경우 무조건 C 이지만...) 로 만들지 결정하는 단계입니다. 세상에서는 수 많은 언어들이 있는데 우리가 지금 배우는 C 말고도 (물론 C 가 가장 기본적이면서도 중요한 언어지요^^) 각각의 특성을 가지는 언어들이 많습니다. 우리는 이 때 마다 `1,2,3` 번을 충분히 고려하여 가장 효율적인 언어를 선택해서 프로그램을 만들어야 겠지요. 물론 우리가 만들 도서 프로그램은 C 언어로 만듭니다 4 번은 프로그램을 어떠한 언어 (물론 우리의 경우 무조건 C 이지만...) 로 만들지 결정하는 단계입니다. 세상에서는 수 많은 언어들이 있는데 우리가 지금 배우는 C 말고도 (물론 C 가 가장 기본적이면서도 중요한 언어지요^^) 각각의 특성을 가지는 언어들이 많습니다. 우리는 이 때 마다 `1,2,3` 번을 충분히 고려하여 가장 효율적인 언어를 선택해서 프로그램을 만들어야 겠지요. 물론 우리가 만들 도서 프로그램은 C 언어로 만듭니다.



###  프로그램의 기본 뼈대




자. 그럼 무슨 작업을 하는 프로그램을 만들지 정했으니 이제, 어떠한 방식으로 작동되는지 생각해보도록 합시다. 우리가 만들어야 할 프로그램은 단순히 C 언어 프로그래밍 실력을 키우기 위한 것이기 때문이 굳이 예쁘게 까지 만들 필요는 없을 것 같습니다. 따라서, 이 도서 관리 프로그램은 매우 단순하게, 첫 화면에서 메뉴를 입력 받고 입력 받은 작업을 수행 한 후 다시 메뉴로 돌아오는 것으로 하면 될 것 같습니다.

따라서 프로그램의 기본 뼈대는 아래 처럼 만들 수 있습니다. (물론 여러분이 하신 방법도 좋은 방법 일 것입니다. 제 방법은 단순히 참고로만 알아두세요)

```cpp
#include <stdio.h>
int main ()
{
    int user_choice; /* 유저가 선택한 메뉴*/

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
        }
        else if(user_choice == 2)
        {
            /* 책을 검색하는 함수 호출 */
        }
        else if(user_choice == 3)
        {
            /* 책을 빌리는 함수 호출 */
        }
        else if(user_choice == 4)
        {
            /* 책을 반납하는 함수 호출 */
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


성공적으로 컴파일 하면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1316E80E4B6D80F00CEDD6)

소스 코드에는 특별히 어려운 부분이 없으나 혹시 다음 문장이 무슨 뜻인지 모를 수 있을 것입니다.

```cpp
    while (1)
```

위 말은, 이전에도 이야기 했듯이 컴퓨터는 0 을 거짓, 0 이 아닌 값을 참 으로 판별한다고 말했습니다. 따라서 `while` 문의 조건이 1 이므로, 다시 말하면 `while` 문의 조건이 언제나 참이라는 것이지요. 따라서 이 `while` 문은 무한히 반복되게 됩니다. 우리가 `break` 를 하지 않을 경우 말이죠.

  위 소스 코드에서 중요한 점은 각 작업을 선택할 때 마다 이에 해당하는 '함수' 를 호출한다는 점입니다. 물론, 함수를 반드시 호출할 필요는 없습니다. 그냥 `if` 문 안에다가 위 작업을 처리하는 코드를 열심히 적어주면 되지요. 하지만 함수를 호출하게 되면 코드를 보기에 상당히 깔끔하며 이해도 잘됩니다.



### 이 프로그램에 필요한 변수는?
### 



 기본적으로 생각해 보아도 책의 제목, 출판사의 이름, 저자의 이름을 저장할 배열이 있어야 합니다. 또한 현재 이 책의 상태 (빌려갔는지, 안 빌려갔는지) 를 표시할 수 있는 배열도 필요합니다. 마지막으로 현재 책의 총 개수가 있어야지만 나중에 책을 새로 추가할 때 배열의 몇 번째 원소에 표시할 지 알 수 있습니다. 따라서 이들을 조합하면 다음과 같이 변수를 선언할 수 있습니다.

```cpp
    int user_choice; /* 유저가 선택한 메뉴 */
    int num_total_book = 0; /* 현재 책의 수 */

    /* 각각 책, 저자, 출판사를 저장할 배열 생성. 책의 최대 개수는 100 권*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    /* 빌렸는지 상태를 표시 */
    int borrowed[100];
```


이 때 `book_name` 의 크기가 `[100][30]` 인 이유는 이전에도 말했듯이 이 도서프로그램에 들어갈 수 있는 책의 최대 개수는 100 권이고, 제목의 크기는 최대 30 자로 제한되기 때문이죠. 나머지 변수들도 마찬가지 입니다. 이 때 `borrowed` 배열의 경우 원소의 값이 1 이면 빌림, 0 이면 빌리지 않음 이라고 생각하시면 됩니다.

 이제 무슨 변수가 필요한지도 알았으니 먼저 1 번 작업, 즉 책을 새로 추가하는 함수를 만들어보도록 합시다. 이름은 `add_book` 이고 리턴형은 `int` 로 합시다.

```cpp
/* 책을 추가하는 함수*/
int add_book()
{
}
```


  일단 함수를 만들기 전에 인자로 무엇을 받아야 하는지 생각해봅시다. 책을 추가하려면 책의 이름, 출판사, 저자를 저장할 배열에 대한 포인터를 인자로 받아야 합니다. 그래야지만 이 배열에 새로운 책의 정보를 추가할 수 있지요. 또한 `borrowed` 배열도 인자로 받아서 기본 설정을 해주어야 합니다. 물론 `borrowed` 배열의 기본 값은 `0,` 즉 빌려가지 않음 이겠지요. 마지막으로 `num_total_book` 도 필요합니다. 왜냐하면 현재 책의 총 수를 알아야 배열의 몇번째 원소에 값을 집어 넣을 지 알게 되기 때문이죠.

이를 종합하여 인자를 만들어보면

```cpp
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book)
{
}
```


참고로 팁으로 알려주는 사실은 위와 같이 인자를 쓰는 부분에 엔터를 쳐도 큰 문제는 없습니다. 왜냐하면 C 언어는 위 인자들이 같은 문장에 나열되어 있다고 생각하기 때문이죠. 인자가 길어져서 보기 흉할 때 자주 쓰는 방법 입니다. 자, 그럼 얼른 `add_book` 함수를 완성시켜봅시다. `add_book` 함수는 매우 간단합니다.

```cpp
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
```



저는 위와 같이 하였습니다.
이제 `add_book` 함수를 이용하기 위해 `main` 함수의 `if (user_choice == 1)` 부분에 `add_book` 함수를 호출하는 코드를 넣어 주시면 됩니다. 아래와 같이 말이지요.

```cpp
#include <stdio.h>
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
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
        }
        else if(user_choice == 3)
        {
            /* 책을 빌리는 함수 호출 */
        }
        else if(user_choice == 4)
        {
            /* 책을 반납하는 함수 호출 */
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
```


성공적으로 컴파일 했으면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F1574EC164B6D8E0092933E)

어때요. 프로그램이 아주 잘 작동하고 있는 것 같네요. `main` 함수의 `if` 문에서 주의해야 할 점은

```cpp
add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
```

과 같이 `&` 를 어디에 붙일지 매우 헷깔린다는 것입니다. 기본적으로 배열의 경우, 배열의 이름이 배열의 메모리 상의 시작 주소 이기 때문에 `&` 를 붙일 필요가 없습니다. (정확히 말하면 붙이면 안됩니다). 그러나 `num_total_book` 과 같은 `int` 형 변수의 경우 `int*` 포인터에 주소값을 전달하려면 `&` 를 이용하여 `num_total_book` 변수의 주소값을 전달 해주어야 합니다.

또 하나 주의해야 할 부분은 `add_book` 함수의 원형에서

```cpp
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
```


와 같이 해야 하는데 마지막의 세미 콜론을 빠뜨리게 되면

```warning
error C2085: 'main' : 정식 매개 변수 목록에 없습니다.
error C2143: 구문 오류 : ';'이(가) '{' 앞에 없습니다.
error C2082: 'num_total_book' 정식 매개 변수 재정의
error C2082: 'book_name' 정식 매개 변수 재정의
error C2082: 'auth_name' 정식 매개 변수 재정의
error C2082: 'publ_name' 정식 매개 변수 재정의
error C2082: 'borrowed' 정식 매개 변수 재정의
warning C4047: '함수' : 'int *'의 간접 참조 수준이 'int **'과(와) 다릅니다.
warning C4024: 'add_book' : 형식 및 실제 매개 변수 5의 형식이 서로 다릅니다.
error C2084: 'int add_book(char (*)[30],char (*)[30],char (*)[30],int *,int *)' 함수에 이미 본문이 있습니다.

```

와 같이 이해하기 힘든 오류의 향연을 맛보게 됩니다.



### 책 검색하기
### 



자. 이번에는 두 번째 작업, 책을 검색하는 작업을 수행하는 함수를 만들어보기로 합시다. 이 함수의 이름은 `serach_book` 이라고 합시다. 그렇다면 이 함수는 어떠한 인자를 취해야 될까요? 일단, 단순히 생각해 보아도 `book_name, auth_name, publ_name` 은 모두 취해야 될 것 같네요. 왜냐하면 우리가 검색을 수행 시, 책 제목에서, 지은이 이름에서, 출판사 이름에서 중 어느 하나를 선택해서 검색할 것이기 때문이죠. 또한 전체 책의 총 개수도 필요합니다. 검색할 때 불필요한 부분은 찾지 않게 하기 말이죠. 결과적으로 함수의 인자는 아래와 같으면 충분하다는 사실을 알 수 있습니다.

```cpp
int search_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30], int num_total_book)
```


참고로, 우리가 도서 관리 프로그램에서 만들 "검색" 기능은 우리가 알고 있는 검색 기능과는 살짝 다릅니다. 우리가 흔히 쓰는 검색 기능은 문자열이 비슷하거나 형태를 포함해도 검색 결과에 나타나지만 우리가 만들 검색 기능은 문자열이 완전히 같을 때 나타난다고 합시다. (나중에 업그레이드시 이 부분도 고려해서 하도록 합시다)

그렇다면 머리속에 번뜩이는 생각은 아마,

" [지난번 강좌](http://itguru.tistory.com/33)에서 만들었던 문자열 비교 함수를 이용하면 되겠네!"

그럼, 지난번 강좌에서 문자열 비교 함수 코드를 복사해오겠습니다.

```cpp
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

이렇게 미리 만들어놓은 소스 코드를 이용하는 것도 매우 중요한 기술중에 하나 입니다. 이미 만든 것을 또 만드느랴 시간을 굳이 낭비할 필요가 없게 되죠.

이번에는 `book_search` 함수에 어떠한 변수들이 필요할지 생각해봅시다. (굳이 지금 변수들이 뭐가 필요하나 생각을 안해도 됩니다. 저 역시 프로그래밍을 하다가 필요한 변수들이 있으면 그때 그때 추가하는 스타일 입니다. 여기서 집고 넘어가는 것은 기본적으로 무슨 변수들이 필요할 지 생각해 보는 것입니다)

 먼저, 사용자의 검색어를 받는 배열이 필요합니다. 따라서 나중에 이 검색어와 책 정보를 비교할 수 있겠지요. 또한 사용자가 어떠한 검색을 할지 (책 제목 검색, 지은이 검색, 출판사 검색) 선택을 할 때도 변수가 필요합니다. 마지막으로 첫번째 책 부터 `num_total_book` 번째 책 까지 책 정보를 비교하기 현재 몇 번째 책의 정보와 검색어를 비교하고 있는지에 대한 변수가 필요합니다.

그렇다면 아래와 같이 되겠군요.

```cpp
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30]; /* 사용자가 입력한 검색어 */
```


자 이제, 사용자로 부터 입력을 받아 봅시다.

```cpp
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

    return 0;
}
```


자. 그럼 사용자로 부터 검색어 까지 입력을 받았으니 검색어를 처리하는 일만 남았습니다. 사실 '검색' 이란 말이 거창해 보이지만 우리가 만들 도서 프로그램에서는 상당히 단순합니다. 단순히 `compare` 함수를 이용해서 책 제목 검색을 했다면, 각 책들의 제목과 `user_search` 와 비교하면 되는 것이지요. 이 아이디어를 바탕으로 만들면 다음과 같이 됩니다.

```cpp
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
```


어때요? 소스가 그다지 어렵지 않죠? 위 소스코드에 대한 해석은 여태까지 강좌를 정말 보았다고 한 사람이라면 이해할 수 있을 것입니다. 그럼, 다시 `main` 함수에 `search_book` 함수를 적용시켜 봅시다.

```cpp
#include <stdio.h>
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book);

char compare(char *str1, char *str2);

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
        }
        else if(user_choice == 4)
        {
            /* 책을 반납하는 함수 호출 */
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
```


성공적으로 컴파일 했다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F116BB2174B6DAB63173D26)

위와 같이 아주 잘 작동함을 알 수 있습니다.

아마도 위 도서 프로그램에서는 검색하기 기능이 가장 어려운 것 같네요. 나머지 기능들은 정말로 단순합니다. 3 번째 기능인 "책을 빌리기" 는 단순히 사용자가 빌리려는 책의 번호를 입력하면 `borrowed` 배열의 책 번호에 위치한 원소의 값을 0 에서 1 로 바꾸어주면 됩니다. 왜냐하면 `borrowed` 가 1 이면 빌려진 것, 0 이 면 안 빌려진 것 이기 때문이죠. 마찬가지로  책을 반납하는 기능도 만들 수 있습니다.



### `3,4` 번 기능
### 



먼저, 3 번 기능 부터 만들어봅시다. 함수 이름은 `borrow_book` 으로 합시다.

```cpp
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
```


사실 위 함수는 매우 매우 간단하므로 특별히 설명할 것은 없습니다. 다만 주의할 점은 책이 이미 대출되어 있는 경우에도 처리를 잘 해주어야 한다는 점입니다. 책이 대출되어 있을 경우 "이미 대출된 책입니다" 라는 메세지를 표시하고 대출을 시키면 안됩니다. 자, 그럼 이제 위 함수를 `main` 함수에 넣어 작동시켜 봅시다.

```cpp
#include <stdio.h>
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);
int search_book(char (*book_name)[30], char (*auth_name)[30],
                char (*publ_name)[30], int num_total_book);

char compare(char *str1, char *str2);
int borrow_book(int *borrowed);

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
```


성공적으로 컴파일 했다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F112C861D4B6EDBE9726CA1)

위와 같이 책이 잘 대출됨을 알 수 있습니다.

마찬가지 아이디어를 이용해서 책을 반납하는 함수를 만들어봅시다. 함수의 이름은 `return_book` 으로 합시다. 이 역시 `borrow_book` 과 하는 일이 거의 똑같으므로 설명을 생략하도록 하겠습니다.

```cpp
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


역시 간단하군요. `borrow_book` 함수의 거의 똑같습니다. 이제, 이 함수를 `main` 함수에 넣어 봅시다.

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


성공적으로 컴파일 했다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F1142561D4B6EDE859221FE)

위와 같이 아주 잘 작동됨을 알 수 있습니다.

아. 그럼 마침내 우리는 도서 관리 프로그램을 완성하였습니다!! 처음에 막연하게 도서 관리 프로그램을 만들라고 하니까 상당히 막연해 보였는데 하나 하나 조금씩 해보니 금새 만들게 되었습니다. 뿐만 아니라 함수를 이용해서 소스 코드의 가독성도 높여주었습니다. 뿐만 아니라 여러분이 도서 관리 프로그램을 만들면서 느끼게 될 점은 "주석의 유용함" 일 것입니다. 만일 우리가 주석 하나 없이 단순하게 프로그램을 만들었다면 나중에.. 한 1 달 뒤에 이 소스 코드를 다시 보게 된다면 "이 변수가 뭐지? 이 부분은 뭐하는 것이지?" 라는 생각이 들 것입니다. 저는 심지어 주석이 없이 프로그래밍 한 경우 어제 한 코드도 이해 못하는 경우가 있었습니다. 하지만 주석이 있다면 정말 아무리 오래 전에 만든 프로그램이여도 소스를 보면서 손쉽게 이해해 나갈 수 있습니다.

그럼 여기서 이번 강좌를 마치도록 하겠습니다.

생각해보기

`1.` 위 프로그램을 다 지우고 다시 만들어보자. 물론 소스가 정확히 일치하지 않아도 된다. 기능만 동일하면 된다. (난이도 : 下)

2. search_book 함수는 살짝 지저분한 편이다. 다른 함수를 제작하여 조금 간추릴 수 있겠는가? (난이도 : 中下)

`3. search_book` 함수를 조금 개량하여 빌려진 책은 검색결과 출력되지 않게 하거나, "대출됨" 이라는 문구가 출력되게 해보자. (난이도 : 下)

`4. search_book` 함수를 개량하여 특정한 검색어를 입력했을 때 그 검색어를 포함하는 문자열도 검색되게 해보자. (난이도 : 中)
예를 들어 책 제목이 "learnCfast", "learningC", "whatisC?" 일 때, learn 를 검색하면 "learnCfast" 와 "learningC" 가 나온다. 왜냐하면 이들은 모두 "learn 라는 문자열을 포함하고 있기 때문이다.

```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <15 - 4. 일로와봐, 문자열(string) - 도서 관리 프로젝트>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```



