----------------
title : 씹어먹는 C 언어 - <16 - 2. 모아 모아 구조체(struct) - 구조체 인자로 가진 함수>
cat_title : 16 - 2. 모아 모아 구조체(struct) - 구조체 인자로 가진 함수
next_page : 71
--------------



이번 강좌에서는

* 구조체 포인터

* 구조체를 인자로 받기

* 구조체의 대입



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F147DD5274BC143036690CB)

  안녕하세요 여러분~ 드디어 구조체의 두번째 강의를 시작하게 되었습니다. 지금 강좌를 쓰다가 느낀 건데 제가 구조체를 배웠을 때 에는 정말로 재미있게 배웠던 것 같습니다. 일단 이전 강좌에서도 말했듯이 `->` 기호가 상당히 매력적으로 다가왔는데 그것 이외에도 "struct" 라는 단어를 정말 좋아했던 것 같네요. 여러분은 안그러시나요?






###  구조체 포인터 연습하기

일단, 이번 장의 진도를 나가기 위해선 구조체 포인터에 아주 능숙해 져야 하므로 지난번의 내용을 잠깐 복습하도록 하겠습니다.

```cpp
/* 포인터 갖고 놀기 */
#include <stdio.h>
struct TEST
{
    int c;
};
int main()
{
    struct TEST t;
    struct TEST *pt = &t;

    /* pt 가 가리키는 구조체 변수의 c 멤버의 값을 0 으로 한다*/
    (*pt).c = 0;

    printf("t.c : %d \n", t.c);

    /* pt 가 가리키는 구조체 변수의 c 멤버의 값을 1 으로 한다*/
    pt->c = 1;

    printf("t.c : %d \n", t.c);

    return 0;

}
```

성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F18181F034B7D593F6DD7A5)

만일 지난번의 강좌를 어렴풋이 나마 기억하고 있는 분들이라면 별로 어려운 내용은 아닐 듯 싶습니다.

```cpp
    struct TEST t;
    struct TEST *pt = &t;
```

일단 "struct TEST" 형의 구조체 변수 `t` 와 "struct `TEST` 형을 가리키는 포인터" `pt` 를 선언하였습니다. 다시 강조하지만, 우리가 `int, char` 로 생각하는 것 처럼 'struct TEST' 도 우리가창조해 낸 하나의 타입이며, 이를 가리키는 포인터 역시 다른 모든 포인터와 마찬가지로 크기가 4 바이트 [[각주:](#footnote_60_1)`1 1`]``` 라는 것입니다. 즉 `pt` 는절대로 구조체가 아니며`, pt` 는 단순히 구조체 변수 `t` 가 저장되어 있는 메모리 공간의 주소값을 보관하고 있을 뿐입니다.

이 때, `pt` 는 `t` 의 주소값을 가지고 있으므로 `pt` 는 `t` 를 가리키게 됩니다.

```cpp
    (*pt).c = 0;

    printf("t.c : %d \n", t.c);
```


이제, `pt` 가 `t` 를 가리키고 있으므로 우리는 `pt` 를 가지고 `t` 의 값을 마음대로 조작할 수 있게 되었습니다.

이전에 `int *pi = &i` 를 한 후, `*pi` 를 쓰면 `i` 를 간접적으로 나타낼 수 있었듯이 `*pt` 를 이용하면 `pt` 가 가리키고 있는 `struct TEST` 형의 변수, 즉 `t` 를 나타낼 수 있게 됩니다. 따라서 `(*pt).c` 를 하면 `t` 의 멤버 `c` 를 의미하게 되죠. 이 때, `*pt` 를 괄호로 감싸주는 이유는 . 이 우선순위가 `*` 보다 높기 때문에 그냥 `*pt.c` 라고 쓰면 "pt 의 `c` 멤버가 가리키는 것" 을 의미하게 됩니다.

아무튼 `(*pt).c = 0;` 을 통해 우리는 `t` 의 `c` 멤버의 값을 성공적으로 바꿀 수 있었습니다.

하지만 `(*pt).c` 는 너무 쓰기 불편합니다. 항상 `*pt` 를 괄호로 닫아 주어야 하는데, 괄호는 `Shift` 를 누르고 키보드의 9 번과 0 번을 눌러야 하니 정말로 손가락도 아프로 불편할 따름이지요. 그래서 훌륭한 C 언어 제작자들은 새로운 편리한 연산자를 만들었습니다.

```cpp
    pt->c = 1;

    printf("t.c : %d \n", t.c);
```


바로 `->` 이죠. `->` 연산자의 의미는 "`pt` 가 가리키는 구조체 변수의 멤버" 를 의미합니다. 따라서 `pt->c` 는 "`pt` 가 가리키는 구조체 변수, 즉 `t` 의 멤버 `c`" 를 의미하게 됩니다. 따라서 `pt->c = 1;1 을 통해 우리는 `t` 의 멤버 `c` 의 값을 1 로 바꿀 수 있었습니다.

```cpp
/* 헷깔림 */
#include <stdio.h>
struct TEST
{
    int c;
    int *pointer;
};
int main()
{
    struct TEST t;
    struct TEST *pt = &t;
    int i = 0;

    /* t 의 멤버 pointer 는 i 를 가리키게 된다*/
    t.pointer = &i;

    /* t 의 멤버 pointer 가 가리키는 변수의 값을 3 으로 만든다*/
    *t.pointer = 3;

    printf("i : %d \n", i);

    /*

    -> 가 * 보다 우선순위가 높으므로 먼저 해석하게 된다.
    즉,
    (pt 가 가리키는 구조체 변수의 pointer 멤버) 가 가리키는 변수의 값을 4 로 바꾼다.
    라는 뜻이다/

    */
    *pt->pointer = 4;

    printf("i : %d \n", i);
    return 0;

}
```


성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F19492E144B7D5C5B2117C3)

아마 위 예제만 제대로 이해하신 다면 더이상 구조체 포인터 가지고 혼동하는 일은 없을 듯 합니다.
먼저, `TEST` 구조체의 멤버들 부터 살펴봅시다.

```cpp
struct TEST
{
    int c;
    int *pointer;
};
```


흠. 쟁쟁한 녀석이 나왔군요. 포인터가 있습니다. 하지만 괜찮습니다. 우리는 포인터를 잘 다루거든요.

```cpp
    struct TEST t;
    struct TEST *pt = &t;
    int i = 0;
```

마찬가지로 `pt` 는 `t` 를 가리키게 됩니다.

```cpp
    t.pointer = &i;
```


일단, 위 문장에서 `t` 의 `pointer` 라는 멤버에는 `i` 의 주소값이 들어갑니다. 따라서 `pointer` 는 `i` 를 가리키게 됩니다. 그렇다면 `pointer` 를 가지고 `i` 의 값을 바꾸며 놀 수 있겠죠? 바로 다음 문장을 봅시다.

```cpp
    *t.pointer = 3;
```

흠. 우선 순위를 고려하면 `.` 가 `*` 보다 높으므로 `t.pointer` 가 먼저 해석되고 그 다음에 `*(t.pointer)` 형태로 해석되게 됩니다. 따라서, `*t.pointer` 를 통해 구조체 `` 변수 `t` 의 `pointer` 멤버가 가리키는 변수를 지칭할 수 있게 됩니다.

```cpp
    *pt->pointer = 4;
```

`.` 과 마찬가지로 `->` 도 `*` 보다 우선순위가 높습니다. 즉, `*(pt->pointer)` 와 `*pt->pointer` 는 동일한 의미라는 것입니다. 아무튼, `pt->pointer` 를 통해 "pt 가 가리키는 구조체 변수의 `pointer` 멤버", 즉 `t.pointer` 을 의미할 수 `*(pt->pointer) = 4` 를 통해 `pointer` 가 가리키는 변수의 값을 4 로 바꿀 수 있게 됩니다 . 과 마찬가지로 `->` 도 `*` 보다 우선순위가 높습니다. 즉, `*(pt->pointer)` 와 `*pt->pointer` 는 동일한 의미라는 것입니다. 아무튼, `pt->pointer` 를 통해 "pt 가 가리키는 구조체 변수의 `pointer` 멤버", 즉 `t.pointer` 을 의미할 수 `*(pt->pointer) = 4` 를 통해 `pointer` 가 가리키는 변수의 값을 4 로 바꿀 수 있게 됩니다.

```cpp
/*

구조체 포인터 연습

 */
#include <stdio.h>
int add_one(int *a);
struct TEST
{
    int c;
};
int main()
{
    struct TEST t;
    struct TEST *pt = &t;

    /* pt 가 가리키는 구조체 변수의 c 멤버의 값을 0 으로 한다*/
    pt->c = 0;

    /*
    add_one 함수의 인자에 t 구조체 변수의 멤버 c 의 주소값을
    전달하고 있다.
    */
    add_one(&t.c);

    printf("t.c : %d \n", t.c);

    /*
    add_one 함수의 인자에 pt 가 가리키는 구조체 변수의 멤버 c
    의 주소값을 전달하고 있다.

    */
    add_one(&pt->c);

    printf("t.c : %d \n", t.c);

    return 0;

}
int add_one(int *a)
{
    *a += 1;
    return 0;
}

```

성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F146925104B7D5EF68E44B1)

이제, 마지막으로 구조체 포인터 연습을 해볼까 합니다.

```cpp
    struct TEST t;
    struct TEST *pt = &t;
```

이전과 마찬가지로 `pt` 는 `t` 를 가리키고 있습니다.

```cpp
    add_one(&t.c);
```


그리고 `add_one` 함수에 `t` 의 멤버 `c` 의 주소값을 전달하였습니다. 역시 `&` 보다 . 이 우선순위가 높으므로 위 식은 `&(t.c)` 와 동일합니다. 아무튼, `add_one` 함수에 의해 `c` 의 값이 1 증가 합니다.

```cpp
    add_one(&pt->c);
```

마찬가지로 `->` 가 `&` 보다 우선순위가 높습니다. 따라서, `pt` 가 가리키는 구조체의 멤버 `c` 의 값이 1 증가하게 됩니다.

이해가 잘 되시죠?



### 구조체의 대입



`` 구조체의 복사라 하면 무언가 거창할 것 같지만 사실은 상당히 단순한 내용입니다.

바로, 구조체도 보통의 변수들과 같이 `=` 를 사용할 수 있다는 것이지요. (= 가 대입 연산자 라는 사실은 기억하시죠??)
```cpp
#include <stdio.h>
struct TEST
{
    int i;
    char c;
};
int main()
{
    struct TEST st, st2;

    st.i = 1;
    st.c = 'c';

    st2 = st;

    printf("st2.i : %d \n", st2.i);
    printf("st2.c : %c \n", st2.c);

    return 0;
}
```


  성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F203B51194B815A09E19D54)

여러분은 아마도 위 소스 코드를 한눈에 이해하셨을 수 있을 것입니다.

```cpp
struct TEST
{
    int i;
    char c;
};

```

멤버가 `i` 와 `c` 인 `struct TEST` 를 정의하였고, 이 구조체의 변수인

```cpp
    struct TEST st, st2;
```


`st` 와 `st2` 를 정의하였습니다. 그리고 `st` 의 각 멤버에

```cpp
    st.i = 1;
    st.c = 'c';

```

를 넣였죠.

```cpp
    st2 = st;

```

그리고 우리는 위와 같이 `st` 를 `st2` 에 대입하였습니다. 우리가 변수 `i` 를 `j` 에 대입하면 `i` 의 값이 `j` 에 그대로 복사되듯이, `st2` 의 멤버 `i` 의 값은 `st` 의 멤버 `i` 의 값과 같아지고, `st2` 의 멤버 `c` 의 값은 `st` 의 멤버 `c` 의 값과 동일해졌습니다. 이는 상당히 합리적이고 대입 연산자의 역할을 잘 해내는 것 같네요.

```cpp
#include <stdio.h>
char copy_str(char *dest, char *src);
struct TEST
{
    int i;
    char str[20];
};
int main()
{
    struct TEST a,b;

    b.i = 3;
    copy_str(b.str, "hello, world");

    a = b;

    printf("a.str : %s \n", a.str);
    printf("a.i : %d \n", a.i);

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

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F1433CC154B83C9B880ADCB)


위 코드 역시 구조체의 대입이 무엇인지 잘 이해만 했다면 별 무리 없이 이해하실 수 있으리라 생각 합니다.

```cpp
struct TEST
{
    int i;
    char str[20];
};
```


위와 같이 `struct TEST` 를 정의하였습니다. 이번에는 `int i` 와 `char str[20]` 을 멤버로 가지고 있습니다.

```cpp
    struct TEST a,b;

    b.i = 3;
    copy_str(b.str, "hello, world");
```


이제 구조체를 정의한 뒤, 위와 같이 각각의 멤버를 초기화 합니다. `copy_str` 함수는 [15 - 3 강](http://itguru.tistory.com/33)에서 만들어본 함수죠?

```cpp
    a = b;
```


그리고 우리는 위와 같이 `b` 구조체를 `a` 구조체에 대입하였습니다. 따라서, `b` 구조체의 모든 멤버의 데이터가 `a` 구조체에 일대일로 대응이 되어 값이 복사됩니다. 즉, `i` 는 `i` 끼리, `str` 은 `str` 의 각 원소 끼리 쭈르륵 복사가 됩니다. 결과적으로 각각의 멤버의 값을 출력해 보면 동일하게 나옵니다.



### 구조체를 인자로 전달하기



```cpp

/*구조체를 인자로 전달하기 */#include <stdio.h>struct TEST{    int age;    int gender;
};
int set_human(struct TEST a, int age, int gender);int main(){    struct TEST human;    set_human(human, 10, 1);    printf("AGE : %d // Gender : %d ", human.age, human.gender);    return 0;}int set_human(struct TEST a, int age, int gender){    a.age = age;    a.gender = gender;    return 0;}
```


  성공적으로 컴파일 하였다면 다음과 같은 오류를 만날 수 있으셨을 것입니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F18631B174BAEA99F7C78E4)

허걱. 오래간만에 만나는 오류이군요. 오류의 내용을 보자 하니, `human` 이라는 구조체 변수가 값이 초기화되지 않은 채 사용되었다고 하네요. 일단 소스 부터 살펴보도록 합시다.


```cpp
struct TEST
{
    int age;
    int gender;
};
```


일단 우리는 위와 같이 `TEST` 구조체를 정의하였습니다. 그리고

```cpp
int set_human(struct TEST a, int age, int gender)
{
    a.age = age;
    a.gender = gender;

    return 0;
}

```

`set_human` 이라는 함수를 만들어서 `TEST` 구조체 변수들을 초기화 하도록 했습니다. 따라서,

```cpp
    set_human(human, 10, 1);
```

와 같이 한다면 `human` 의 `age` 와 `gender` 멤버들이 초기화 될 것 처럼보이지요`.` 하지만 그렇지 않습니다. 왜냐구요? 아마 여태까지 강좌를 잘 따라오셨더라면 한 번에 짐작하실 수 있으실 텐데 말이죠. 바로 제 . 하지만 그렇지 않습니다. 왜냐구요? 아마 여태까지 강좌를 잘 따라오셨더라면 한 번에 짐작하실 수 있으실 텐데 말이죠. 바로 제가 [13 - 2 강](http://itguru.tistory.com/27)에서 말한 규칙, "특정한 변수의 값을 다른 함수를 통해 바꾸려면 변수의 주소값을 전달해야 한다" 라는 룰을 지키지 않았기 때문입니다. 다시 말해 위 경우에서 `a.age =` age; 를 했을 때 `age` 의 값이 바뀌는 것은 실제 `main` 함수에서의 `human` 이 아니라 `set_human` 함수의 `a` 라는 `human` 과 별개의 구조체변수의 `age` 멤버의 값이 바뀌게 되는 것이지요.

따라서 실제 `human` 구조체변수의 멤버들은 전혀 초기화 되지 않은 채 출력이 실행되어 오류가 발생했습니다.

이를 해결하기 위해서는 역시 `human` 구조체 변수의 주소값을 인자로 받는 함수를 만들어야 할 것입니다.

```cpp
/* 인자로 제대로 전달하기 */
#include <stdio.h>
struct TEST{
    int age;
    int gender;
};
int set_human(struct TEST *a, int age, int gender);
int main()
{
    struct TEST human;

    set_human(&human, 10, 1);

    printf("AGE : %d // Gender : %d ", human.age, human.gender);
    return 0;
}
int set_human(struct TEST *a, int age, int gender)
{
    a->age = age;
    a->gender = gender;

    return 0;
}

```



성공적으로 컴파일 했다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F1848DC1B4BAEB19D56553A)

위와 같이 `human` 구조체 변수의 멤버의 값들이 제대로 변경되었음을 알 수 있습니다.


```cpp
int set_human(struct TEST *a, int age, int gender)
{
    a->age = age;
    a->gender = gender;

    return 0;
}

```

위 `set_human` 함수는 이전 예제에서의 `set_human` 함수와는 다르게 구조체의 포인터를 인자로 취하고 있습니다. 그렇기 때문에 `set_human` 함수를 호출할 때 에서도

```cpp
    set_human(&human, 10, 1);
```

위와 같이 `human` 의 주소값을 인자로 전달하고 있었죠. 따라서, `a` 는 `human` 을 가리키게 됩니다. (역시 주의할 점은 `a` 는 절대로 구조체 변수가 아니라는 것이죠. 단순히 `human` 구조체 변수가 메모리 상에 위치한 곳의 시작 지점의 주소값을 보관하고 있을 뿐입니다) 아무튼 위와 같이 전달한다면 이제 `a->` 를 통해 `a` 가 가리키고 있는 구조체 변수의 멤버, 즉 위의 경우에서는 `human` 의 멤버를 지칭할 수 있게 됩니다. 따라서 `a->age =` age; 를 하게 되면 `human` 의 `age` 멤버의 값이 바뀌게 되는 것입니다.

물론 주의할 점은 "a->age" 와 "age" 는 다르다는 것이죠. "a->age" 는 "human 구조체 변수의 `int` 형 멤버 age" 를 지칭하는 것이고, "age" 는 단순히 `set_human` 함수에서 인자로 받아들여진 `int` 형의 `age` 라는 변수를 가리키는 말입니다. 이 둘은 다른 것이고 실제로 컴퓨터 내부에서도 다르게 처리됩니다.

아무튼 위와 같이 제대로 값이 바뀌어서 출력됨을 알 수 있습니다.

```cpp
/* 살짝 업그레이드*/
#include <stdio.h>
struct TEST
{
    int age;
    int gender;
    char name[20];
};
int set_human(struct TEST *a, int age, int gender, char *name);
char copy_str(char *dest, char *src);

int main()
{
    struct TEST human;

    set_human(&human, 10, 1, "Lee");

    printf("AGE : %d // Gender : %d // Name : %s \n", human.age, human.gender, human.name);
    return 0;
}
int set_human(struct TEST *a, int age, int gender, char *name)
{
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);

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


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F125F3F264BAEB62683A187)

기본적으로 이전의 예제와는 동일하지만 멤버를 하나 더 추가했습니다.

```cpp
struct TEST
{
    int age;
    int gender;
    char name[20];
};
```


위와 같이 `name[20]` 이라는 멤버를 새로 추가해주었습니다.

```cpp
int set_human(struct TEST *a, int age, int gender, char *name);
```


그리고 `set_human` 함수에서 `name` 멤버 역시 같이 초기화해주기 위해 인자로 `char *` 형의 `name` 이라는 인자를 추가로 받게 됩니다.

```cpp
    set_human(&human, 10, 1, "Lee");
```

이제 `TEST` 구조체 변수인 `human` 을 초기화 하기 위해서 `set_human` 함수를 호출하였습니다.


```cpp
int set_human(struct TEST *a, int age, int gender, char *name)
{
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);

    return 0;
}
```



위 함수는 `a` 가 가리키는 구조체 변수의 각 멤버들을 초기화 하게 됩니다. 이 때, `main` 함수의 `human` 구초제 변수의 `name` 멤버를 초기화 하기 위해서는 `copy_str` 함수를 이용해야 합니다. 이를 위해서는 `name` 배열의 주소값과, 복사해 넣으려는 문자열의 주소값을 넣어야 하는데 `a->name` 을 통해 `human` 구조체 변수의 `name` 멤버의 주소값과, `name` (이는 두 번째 인자로 `a->name` 과 전혀 다른 것이다) 을 통해 복사해 넣으려는 문자열의 주소값을 `copy_str` 에 전달할 수 있게 됩니다. 아무튼, 위를 통해 성공적으로 `human` 의 각각의 멤버들을 초기화 할 수 있게 되었죠.
자, 그럼 이번 강좌는 여기서 마치도록 하겠습니다. 아무래도 이번 강좌를 통해 구조체에 대한 확실한 자신감이 생겼으면 하네요. 다음 강좌에서는 구조체에 대해서 조금 더 살펴보고 실습을 해보던지, 아니면 새로운 C 의 기능들에 대해 탐구해 보도록 하죠. (아마 여기까지 도달하신 여러분들은 C 의 모든 고비를 넘겼다고 하셔도 무방합니다. 이제 모든 것이 술술 풀리게 될 것입니다 `~ )`


생각해보기


`1.` (이전에 만든)도서 관리 프로그램을만들되,구조체를 이용해 봅시다. 또한 `register_book` 과 같은 함수를 이용하여 책을 등록해봅시다. (난이도 : 下)


`2. ` 큰 수를 다루는 구조체를 생각해봅시다. 그 구조체의 이름은 ` BigNum` 입니다. `BigNum` 구조체에는 다음과 같은 멤버들이 있을 수 있습니다.



```cpp
 struct BigNum
{
    int i_digit[100]; // 정수 부분
    int d_digit[100]; // 소수 부분
    int i_total_digit; // 전체 사용되고 있는 정수부분 자리수
    int d_total_digit; // 전체 사용되고 있는 소수부분 자리수
    char sign; // 부호, 0 이면 양수, 1 이면 음수. 0 은 양수로 간주한다.
};
```



(a) 이 때, `BigNum` 구조체의 변수들의 덧셈, 뺄셈을 수행하는 함수를 작성해보세요 (난이도 : 中上)
(b) `BigNum` 구조체 변수들의 곱셈을 수행하는 함수를 만들어보세요 (난이도 : 上)
(c) `BigNum` 구조체 변수들의 나눗셈을 수행하는 함수를 만들어보세요 (난이도 : 最上)
참고로 `BigNum` 구조체를 다룰 때 중요한 점은 수의 크기가 위 배열에 들어가지 않을 정도로 클 때를 적절히 처리해 주어야 한다는 점에 있습니다.



```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <16 - 2. 모아 모아 구조체(struct) - 구조체 인자로 가진 함수>>입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```




1. 역시, 여기에 태클은 금물입니다.
 [[본문으로]](#footnote_link_60_1)



