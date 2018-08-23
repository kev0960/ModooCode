 itguru Top itguru Top

이번 강좌에서는

* 구조체에 대한 소개
* 구조체 포인터 및 -> 라는 새로운 연산자 도입
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F2020AA124B780AA6B73A2B)

  안녕하세요 여러분. 잘 지내셨는지요? 제가 요즘에 강좌를 올리는 틈틈히C 레퍼런스를 정리하고 있습니다. 레퍼런스라 하면, 일종의 백과사전 같은 것으로 여러분들이 궁금한 함수들이 있다면 찾아볼 수 있게 해놓았습니다. 아직 일부 함수들 밖에 올리지는 못했지만 그래도 그 양이 꽤 되니 읽어 보시는 것이 좋을 듯 합니다. 특히, 화면에서 입력을 받는 함수는 아직 scanf 와 getchar 밖에 보지 못했지만 fgets, gets 등이 있고, 화면에 출력하는 함수는 fputs, puts, putchar 등등 매우 많습니다. 뿐만 아니라 우리가 scanf 함수나 printf 함수를 여태까지 써오면서 사용하지 못했던 기능이 수없이 많은데 이들 모두레퍼런스에 잘 정리되어 있으니 참조하시기 바랍니다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F111277144B780AC91786E6)

심즈 3, 출처 http://www.softsailor.com/wp-content/uploads/2009/05/sims-3.jpg
여러분은 지금 Sims 라는 게임을 만들고 있습니다. Sims 라는 게임은 워낙 유명하지만, 그래도 뭔지 설명 해보자면 사람을 육성(?) 하는 게임 입니다. 말그대로 '신' 이 되는 게임이죠. 자신의 사람들을 훌륭한 사람으로 키우는 것이 목표입니다. 아무튼, 만일 게임하는 유저가 사람을 한 명 추가했다고 합시다. 그렇다면 이를 어떻게 저장할까요?

여러분의 머리속에는 "음, 그럼 이전에 만들어놓은 문자열 배열의 i 번째 원소에 이름을 등록하고, int 형 배열의 i 번째 원소에 나이를 등록하고, 성격은 ... " 과 같이 생각할 것입니다. 맞아요. 이렇게 한 방법은 우리가 지난 강좌에서 도서 관리 프로그램을 만들 때 사용했던 방법이지요. i 번째 책에 대한 정보는 book_name[i - 1], auth_name[i - 1], publ_name[i - 1] , borrow[i - 1] (i 번째 이므로, 원소는 [i - 1] 이겠지요) 배열에 넣어서 보관하였습니다.

그런데 말이죠. 위 방법에는 살짝 문제점이 있었습니다. 책의 정보를 수정하기 위해서 함수에 인자로 전달할 때 상당히 불편하다는 사실입니다. 한 번 도서 관리 프로그램의 새로운 책을 추가하는 함수였던 add_book 함수의 원형을 가져와보았습니다.

```cpp
int add_book(char (*book_name)[30], char (*auth_name)[30], char (*publ_name)[30],
             int *borrowed, int *num_total_book);

```

헐. num_total_book 을 빼더라도 인자가 너무나 깁니다. 그래도 도서 관리 프로그램은 봐줄만 했죠. 하지만 우리가 만들게 될 Sims 는 다릅니다. 일단 사람 한 명에는 수없이 많은 정보가 있습니다. 예를 들어, 이름, 나이, 직업, 성격 (외향적, 내향적, 사교적, ... 들을 모두 수치화 시켜서 보관한다), 직업, 재산, 가족 관계 등등 수없이 많은 정보가 있습니다. 책과는 완전히 다르지요. 우리가 사람의 정보를 수정하기 위해 함수를 호출할 때 마다 이렇게 무지막지 하게 많은 정보들을 인자로 전달하려면 손가락이 빠질 뿐더러 눈도 매우 아프게 됩니다.

우리가 배열을 배웠기 전의 모습을 생각해봅시다. 배열을 배우기 전에, 예를 들어 10 명의 학생의 점수를 보관하기 위해 10 개의 변수를 선언해서 각각에 보관했어야 했습니다. 하지만, 배열을 배운 이후는 어떨까요? 10 개의 변수를 한꺼번에 배열로 처리하여 배열의 각각의 원소를 손쉽게 다루기 위해서였습니다. 즉 int arr[10]; 이라 한다면 int 형 변수 10 개를 쉽게 다룰 수 있는 것입니다. 뿐만 아니라 함수에 int 형 변수를 전달할 때, int 형 변수 10 개를 일일히 전달하려면

```cpp
int func(int a, int b, int c, .....(생략) ... )
```


와 같이 해야 합니다. 그런데 int 형 변수 10 개를 arr 을 이용하여 쉽게 전달할 수 있습니다. 아래와 같이요.

```cpp
int func(int *arr);
```

그렇다면 위 배열과 같은 논리가 여기에도 적용될 수 있지 않을까요? 원소의 크기가 제각각인 배열을 만드는 것입니다.한 사람에 대한 정보를 한 개의 배열에 저장하는 것입니다! 첫번째 원소는 int 로 나이를 보관하고, 두 번째 원소는 char [30] 으로 이름을 보관하는 것입니다. 정말 괜찮은 아이디어입니다. 하지만 C 언어에서는 배열의 원소의 타입은 모두 동일해야 합니다. 다시말해 동일한 배열에서 어떤 원소는 char 이고 어떤 원소는 int 일 수 없다는 것이죠. 다행스럽게도 C 언어에서는 배열로 해결하지 못하는 문제를구조체 를 이용하여 해결할 수 있었습니다.

```cpp
/* 구조체의 도입*/
#include <stdio.h>
struct Human
{
    int age; /* 나이 */
    int height; /* 키 */
    int weight; /* 몸무게 */
}; /* ; 붙이는 것 주의하세요 */
int main()
{
    struct Human Psi;

    Psi.age = 99;
    Psi.height = 185;
    Psi.weight = 80;

    printf("Psi 에 대한 정보 \n");
    printf("나이   : %d \n", Psi.age);
    printf("키     : %d \n", Psi.height);
    printf("몸무게 : %d \n", Psi.weight);
    return 0;
}
```


성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F117079184B703C597BB598)

아마 여러분은 위 소스 코드에서 여러가지 새로운 것들을 보실 수 있으셨을 겁니다. 아마 이 강좌가 끝날 즈음에는 위 사실들을 자유롭게 다룰 수 있게 되니 크게 걱정 안하셔도 됩니다. 일단 구조체를 정의한 부분 부터 살펴 봅시다. 직관적으로 아래의 부분과 같다는 사실을 알 수 있습니다.

```cpp
struct Human
{
    int age; /* 나이 */
    int height; /* 키 */
    int weight; /* 몸무게 */
}; /* ; 붙이는 것 주의하세요 */
```


  앞서 말했듯이 구조체는 "각 원소의 타입이 제각각인 배열" 이라고 말했습니다. 이 때문에 배열에서는 배열의 타입만으로 모든 원소의 타입을 알 수 있었지만 (예를 들어 int array[100] 이면 array 의 모든 원소의 타입은 int 형 이다) 구조체는 그렇지 않습니다. 따라서 구조체는 정의할 때 모든 원소의 타입을 명시해 주어야 합니다. 위와 같이 말이죠. 이 Human 이라는 이름의 구조체는 3 개의멤버를 가지고 있는데 (보통 구조체에서는 원소 보다는멤버(member) 라고 부르는 경우가 많습니다. 이 강좌에서도 멤버라 칭하겠습니다) 각각의 멤버는 int age, int height, int weight 로 3 개가 있습니다.

  구조체의 일반적인 정의는 아래와 같습니다.

```cpp
struct 구조체이름
{
    멤버들.. 예를 들면
    char str[10];
    int i;
}; /* 마지막에 꼭 ; 를 붙인다. */

```

다음은 main 함수내부를 살펴 볼 것입니다.

```cpp
    struct Human Psi;
```


위와 같이 Human 이라는 구조체의 구조체 변수 Psi 를 정의하였습니다. 여기서 놀라운 점은 "struct Human" 이라는 것이 우리가 마치 int 형 변수를 정의할 때 "int" 를 쓰는 것과 같이 사용되었다는 것입니다. 아무튼 이처럼 Psi 를 정의하고 나면,Psi 의 타입은 "struct Human", 즉 "Human 구조체"가 됩니다. "int a" 했을 때 a 의 타입이 int 인 것처럼 말이지요.

  그렇다면 배열에서 [] 를 이용해서 원소에 접근하듯이, 구조체에서도 멤버에 접근할 방법이 있어야 겠죠? C 언어에서는 . 을 이용하여 원소에 접근할 수 있습니다. 예를 들어서, Psi 의 height 멤버에 접근하려면 Psi.height 라고 하면 됩니다. 이는 마치 배열에서 arr[3] 과 같이 원소에 접근하는 것과 동일한 것입니다. 다만구조체는 . 을 이용하고, 멤버가 무엇인지 특별히 명시해주어야 하는 것만 빼고요.

```cpp
    Psi.age = 99;
    Psi.height = 185;
    Psi.weight = 80;

```

따라서, 위 작업은 Psi 라는 구조체의 각 멤버에 값을 대입하는 것입니다. 이는 마치 배열에서 arr[1] = 99, arr[2] = 185 와 같이 하는 것과 동일합니다.

지금 구조체를 처음 배워서 살짝 이해가 안되는 것도 있고 무언가 혼동되는 것이 있을 것입니다. 그래도 구조체가 무엇인지는 감이 대충 오지 않나요? 이제, 다음 예제를 살펴 보아서 구조체가 뭔지 감을 확 잡아보도록 합시다.

```cpp
/* 구조체 예제 2 */
#include <stdio.h>
char copy_str(char *dest, char *src);
struct Books
{
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 빌려 졌나요? */
    int borrowed;
};
int main()
{
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K. Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;

    printf("책 이름 : %s \n", Harry_Potter.name);
    printf("저자 이름 : %s \n", Harry_Potter.auth);
    printf("출판사 이름 : %s \n", Harry_Potter.publ);


    return 0;
}
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

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F181952154B757D69B2D89C)

일단, 저는지지난 강좌에서 만들었던 copy_str 함수를 가져왔습니다. 이 함수는 문자열을 src 에서 dest 로 복사하는 함수이지요. 이렇게 이미 썼던 것을 활용하는 것은 상당히 시간도 절약되고 편리한 방법 중에 하나 입니다.

먼저, 구조체를 정의한 부분 부터 살펴 보도록 합시다.

```cpp
struct Books
{
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 빌려 졌나요? */
    int borrowed;
};
```


흥미로운 점은 이 Book 구조체가 우리가 이전에 만들었던 도서 관리 프로그램을 쏙 빼닮았다는 것이죠. 그 때 에는 각 책을 배열의 한 개의 원소로 표현했는데, 책 이름의 경우 name[100][30] 의 한 문자열 name[i] 으로, (여기서 i 는 임의의 수) , 빌려 졌는지에 대한 유무의 경우, borrowed[100] 의 한 원소 borrowed[i] 로 표현했었죠. 하지만 구조체를 이용하면 책의 각각의 정보를 따로 따로 배열에 정의할 필요가 없게 됩니다. main 함수를 살펴보면

```cpp
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K. Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;
```

먼저 우리는 Harry_Potter 라는 struct Books 의 구조체 변수를 만들었습니다. 자, 그럼 Harry_Potter 의 각 멤버에 값을 대입해야 겠죠? 먼저 책의 이름, 즉 Harry_Potter.name 에 "Harry Potter" 를, 마찬가지로 저자 이름과 출판사에도 모두 대입합니다. 마지막으로 빌렸는지 안빌렸는지에 대한 유무 확인을 위한 Harry_Potter.borrowed 에도 0 을 넣어주어야 합니다.

그런데 말이죠. borrowed 멤버의 값은 처음에 언제나 0 으로 설정되어있습니다. 그렇다면 굳이 매번 책을 새로 등록할 때 마다 borrowed = 0 을 해줄 필요 없이 구조체 자체 에서 바꿔버리면 안될까요?

한 번 구조체 정의 부분을

```cpp
struct Books
{
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 빌려 졌나요? */
    int borrowed = 0;
};
```


로 바꿔서 컴파일 해보세요. 과연..?
잘 되리라 기대했지만 아래와 같은 오류의 향연을 보실 수 있습니다.

```warning
error C2143: 구문 오류 : ';'이(가) '=' 앞에 없습니다.
error C2059: 구문 오류 : '='
error C2059: 구문 오류 : '}'
error C2079: 'Harry_Potter'은(는) 정의되지 않은 struct 'Books'을(를) 사용합니다.
error C2224: '.name' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
error C2198: 'copy_str' : 호출에 매개 변수가 너무 적습니다.
error C2224: '.auth' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
error C2198: 'copy_str' : 호출에 매개 변수가 너무 적습니다.
error C2224: '.publ' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
error C2198: 'copy_str' : 호출에 매개 변수가 너무 적습니다.
error C2224: '.borrowed' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
error C2224: '.name' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
error C2224: '.auth' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
error C2224: '.publ' 왼쪽에는 구조체/공용 구조체 형식이 있어야 합니다.
```

도대체 이게 뭔일인가요?

사실 위 처럼 나온 이유는 간단합니다. 구조체의 정의에서는 변수를 초기화 할 수 없기 때문입니다. 그냥, 받아 들여주세요. 구조체 정의 내부에서는 변수를 초기화 할 수 없다고 말이죠. 특히, 위와 같이 실수를 할 경우 찾기도 잘 어렵고 오류들도 엉뚱한 것들만 나오기 때문에 위와 같은 실수를 조심하는 것이 아주 중요합니다.


```cpp
/* 구조체 예제*/
#include <stdio.h>
struct Books
{
    /* 책 이름 */
    char name[30];
    /* 저자 이름 */
    char auth[30];
    /* 출판사 이름 */
    char publ[30];
    /* 빌려 졌나요? */
    int borrowed;
};
int main()
{
    struct Books book_list[3];
    int i;

    for(i=0;i<3;i++)
    {
        printf("책 %d 정보 입력 : ", i);
        scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
        book_list[i].borrowed = 0;
    }

    for(i=0;i<3;i++)
    {
        printf("------------------------------- \n");
        printf("책 %s 의 정보\n", book_list[i].name);
        printf("저자 : %s \n", book_list[i].auth);
        printf("출판사 : %s \n", book_list[i].publ);

        if(book_list[i].borrowed == 0)
        {
            printf("안 빌려짐\n");
        }
        else
        {
            printf("빌려짐 \n");
        }
    }
    return 0;
}
```


  성공적으로 컴파일 되었다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F1953ED1F4B77FE083B4039)

먼저 구조체의 정의에 대한 부분은 생략하고 바로 main 함수 부터 이야기 하겠습니다.

```cpp
    struct Books book_list[3];
```


일단 위 문장을 보았을 때 어떤 분들은 이해가 잘 되지만 어떤 분들은 이해가 안될 수 도 있을 것이니 다시 한 번 설명하겠습니다. 이전에도 말했듯이 int arr[3] 에서 int 가 하나의 타입이듯이, "struct Books" 가 하나의 타입으로 생각하면 됩니다. 그런데, int arr[3] 을 하면 arr 에 int 형 원소가 3 개 만들어지듯이, book_list 배열에는 struct Books 형의 변수가 3 개 만들어지는 것이지요.

```cpp
    for(i=0;i<3;i++)
    {
        printf("책 %d 정보 입력 : ", i);
        scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
        book_list[i].borrowed = 0;
    }
```


  이제, for 문을 살펴봅시다. scanf 함수로 book_list 의 i 원소의 name, auth, publ 멤버에 문자열을 입력받고 있는 모습을 볼 수 있습니다 또한 borrowed 의 값도 0 으로 초기화 해주고 있습니다.
```cpp
 for(i=0;i<3;i++)
    {
        printf("------------------------------- \n");
        printf("책 %s 의 정보\n", book_list[i].name);
        printf("저자 : %s \n", book_list[i].auth);
        printf("출판사 : %s \n", book_list[i].publ);

        if(book_list[i].borrowed == 0)
        {
            printf("안 빌려짐\n");
        }
        else
        {
            printf("빌려짐 \n");
        }
    }
```


  입력을 다 받고 나면 for 문에서 book_list 의 각 원소의 멤버들을 출력해줍니다. 특히 borrowed 값이 0 이면 "안빌려짐", 0 이 아니면 "빌려짐" 이 출력되는데 위의 경우 0 으로 값을 설정해 놓고 값을 바꾸는 부분이 없으므로 언제나 안 빌려짐이 출력됩니다. 어때요? 간단하죠?

### 구조체 포인터

  으음... 위 파란색 제목만 보고도 눈살을 찌부리는 분들이 있을 지도 모릅니다. 한동안 포인터에게서 벗어난 줄 알았는데 또 등장하는거냐! 하지만 구조체 포인터, 말그대로 구조체를 가리키는 포인터 역시 잘만 이해하면 정말로 아무 것도 아닌 것이 됩니다. 오히려 나중엔 "내가 왜 여기서 겁먹었지?" 라는 생각이 들 정도로요.

```cpp
/* 구조체 포인터 */
#include <stdio.h>
struct test
{
    int a,b;
};
int main()
{
    struct test st;
    struct test *ptr;

    ptr = &st;

    (*ptr).a = 1;
    (*ptr).b = 2;

    printf("st 의 a 멤버 : %d \n", st.a);
    printf("st 의 b 멤버 : %d \n", st.b);

    return 0;
}
```


  성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F126D58234B7802D8028612)

먼저 구조체 포인터에 대해 이야기 하기 전에 확실히 짚고 넘어가야 할 것이 있습니다. 여태까지 누누히 이야기 하였지만 struct test 역시 하나의 형 (타입) 이라는 것입니다. 위의 예제들의 struct Human 이나 struct Book 역시 하나의 타입이였지요. 즉, 구조체는 한 개의 타입을 창조하는 것과 마찬가지라는 것입니다. 마치 int 나 char 처럼 말이지요. 그런데 이러한 타입들을 가리킬 때 우리가 포인터를 어떻게 사용했나요? 바로, int * 나 char * 로 사용했습니다. 구조체도 마찬가지 입니다.

```cpp
    struct test st;
    struct test *ptr;
```

위의 두 번째 문장과 같이 struct test *ptr, 즉 "struct test 형을 가리키는 포인터 ptr" 을 정의한 것이지요. 여기서 주의해야 할 점은 ptr 은 절대로 구조체가 아니라는 것입니다. ptr 역시 다른 모든 포인터 처럼 4 바이트의 공간을 차지(물론 컴퓨터 마다 다를 수 있지만 아마 여러분이 사용하는 컴퓨터는 십중 팔구일 것입니다) 하는 것입니다.

```cpp
    ptr = &st;
```

그리고 위와 같이 ptr 에 str 의 주소값을 집어 넣습니다. 그런데 눈치가 조금 빠르신 분들은 다음과 같이 질문할 수 있습니다.

"아까 구조체는 단순히 원소의 크기가 제각각인 배열이라면서요? 그러면 구조체도 배열처럼 변수의 이름이 그 주소값이 되어야 하는 것 아닌가요? 다시 말해 우리가 int arr[100]; 을 정의했다면 이를 가리키는 포인터를 정의할 때 int *ptr = arr 이라고 하지 int *ptr = &arr 이라 하지 않잖아요?"

상당히 좋은 질문 입니다. 하지만 조금 아래에 보면 구조체 변수의 이름은 역할이 살짝 다르다는 것을 알게 됩니다. 그냥 보통 변수 처럼, (그래서 구조체 변수라 부르지, 구조체 '배열' 이라고 부르지 않잖아요) & 를 붙여 구조체가 정의된 메모리의 주소값을 얻어온다고 생각해주세요.

이제 ptr 은 구조체 st 를 가리키는 포인터가 됩니다.

```cpp
    (*ptr).a = 1;
    (*ptr).b = 2;

```

그럼 ptr 이 가리키는 구조체의 멤버의 값을 변경하는 부분을 살펴 봅시다. 일단 여러분은 (*ptr) 이라는 부분이 st 라는 것과 동일하다는 사실을 알 수 있습니다. 왜냐하면 ptr 이 st 를 가리키고 있기 때문이죠. 따라서 (*ptr).a = 1 은 st.a = 1 과 완전히 100% 동일한 문장임을 알 수 있습니다. 그 아랫 줄도 마찬가지이죠. (*ptr).b = 2 도 st.b = 2 와 정확히 일치하는 문장입니다. 따라서 아래 printf 문에서 st.a 의 값은 1, st.b 의 값은 2 가 출력된 것입니다.

그런데 말이죠. 굳이 괄호를 쳐 주어야 하나요? 그냥 *ptr.a = 1 이라 하면 무엇이 문제이길래 그런 것인가요?

```info
    (*ptr).a = 1; 을
    *ptr.a = 1; 로 바꿔서 컴파일 해봅시다.
```

그렇다면 아래의 오류들을 만나실 수 있을 것입니다.

```warning
error C2231: '.a' : 왼쪽 피연산자가 'struct'을(를) 가리킵니다. '->'를 사용하십시오.
error C2100: 간접 참조가 잘못되었습니다.

```

도대체 왜 발생한 것일까요?
이에 대해 답하기 전에 연산자 우선 순위 표를 먼저 살펴봅시다.

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F183F47204B7806317A2E79)

http://www.winapi.co.kr/ 에서 가져왔습니다.
가장 맨 위를 보면 . 이라고 되있는 것을 볼 수 있습니다... 찾았나요? 여기서 . 은 구조체의 멤버를 지칭할 때 사용하는 . 을 의미하는 것입니다. 즉 (*ptr).a 에서 사용된 . 을 말하지요. 그 바로 아래 행을 보면 *(포인터) 라고 써있는 것이 있습니다. 즉 (*ptr).a 에서의 * 를 말하는 것이지요. 여기서 주목해야 할 점은 . 이 * 보다 우선순위가 높다는 것입니다.

따라서, *ptr.a 를 사용하게 되면 ptr.a 를 먼저 실행한 후, 그 값에 * 를 한 것에 2 가 들어가게 됩니다. 즉 *ptr.a 는 *(ptr.a) 와 동일한 문장인 것이지요. 그런데 위에서도 말했지만 ptr 은 단순히 4 바이트 짜리(역시 여기서 태클을 걸지 말아주세요^^) 포인터에 불과합니다. ptr 은 절대로 구조체가 아니라는 것이지요. 그런데 구조체가 아닌 것의 있지도 않는 a 라는 멤버에 접근하라니 컴파일 시에 오류가 발생하는 것입니다.

결과적으로 구조체 포인터를 사용해서 멤버에 접근하려면 (*ptr).a 와 같이 언제나 괄호로 감싸 주어야 됩니다. 상당히 귀찮은 일이 아닐 수 없습니다. 하지만 똑똑한 C 프로그래머들은 이 문제를 해결하기 위해 다음과 같이 아름다운 기호를 등장시켰습니다.

```cpp
/* 구조체 포인터 */
#include <stdio.h>
struct test
{
    int a,b;
};
int main()
{
    struct test st;
    struct test *ptr;

    ptr = &st;

    ptr->a = 1;
    ptr->b = 2;

    printf("st 의 a 멤버 : %d \n", st.a);
    printf("st 의 b 멤버 : %d \n", st.b);

    return 0;
}

```

  성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F124CD7204B7808081A8128)

여기서 새로 등장한 기호는 제가 가장 좋아하는 기호입니다.

```cpp
    ptr->a = 1;
    ptr->b = 2;
```

위와 같이 (*ptr).a = 1 이라는 문장을 ptr->a = 1 로 간단히 표현할 수 있습니다. 아래 ptr->b = 2 역시 (*ptr).b = 2 와 정확히 일치하는 문장입니다. 단순히 사용자의 편의를 위해서 -> 라는 새로운 기호를 도입한 것 뿐이지요. (이 기호는 위의 우선 순위 표 맨 위에서도 볼 수 있습니다)


자, 그럼 오늘 강좌는 여기서 마치도록 하겠습니다. 사실 이번 강좌는 구조체에 대한 개략 적인 소개만을 전해드린 것이지, 구조체의 진짜 면모는 다음 시간 부터 시작됩니다. 구조체는 정말 잘 쓰면 보물 같은 존재이니 포인터와 더불이 C 언어의 양대 산맥을 이루는 기능이라 말할 수 있습니다. 그럼, 이만 계세요~

생각해보기

1. 구조체 안에 또다른 구조체 변수를 설정할 수 있을까요? (난이도 : 中)

2. 구조체를 인자로 가지는 함수를 생각해보세요. (난이도 : 中)

```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <16 - 1. 모아 모아 구조체(struct)>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요

다음 강좌 보러가기

```

공감1sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C' 카테고리의 다른 글씹어먹는 C 언어 - <16 - 3. 구조체와 친구들(공용체(union), 열거형(enum))>(20)2010.06.13씹어먹는 C 언어 - <16 - 2. 모아 모아 구조체(struct) - 구조체 인자로 가진 함수>(41)2010.04.11씹어먹는 C 언어 - <16 - 1. 모아 모아 구조체(struct)>(26)2010.02.14씹어먹는 C 언어 - <15 - 4. 일로와봐, 문자열(string) - 도서 관리 프로젝트>(31)2010.02.08씹어먹는 C 언어 - <15 - 3. 일로와봐, 문자열(string) - 문자열 지지고 볶기 & 리터럴>(120)2010.02.01씹어먹는 C 언어 - <15 - 2. 일로와봐, 문자열(string) - 버퍼에 관한 이해>(62)2010.01.25

