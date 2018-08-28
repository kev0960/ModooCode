

이번 강좌에서는

* 구조체의 나머지 기능에 대한 이해

* 공용체(union) 에 대한 이해

* 열거형(enum) 에 대한 이해



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F133AE4114C14EBD2712D54)


  안녕하세요 여러분! 또 오래간만 입니다. (저 아직 죽지 않고 살아있어요) 구조체를 향한 강좌도 끝을 향해 달려가고 있습니다. 물론 이번 강좌에서는 구조체만을 다루는 것이 아니라 C 언어에서 사용 비중이 그렇게 크지는 않지만 어쨋든 알기는 알아야 하는 기능들에 대해서 배워볼 차례 입니다. 다시말해, 큰 산들은 다 넘었고 이제 우리 앞에는 조그마한 언덕만이 남아 있을 뿐이라는 것이죠 :)



###  구조체 안의 구조체




```cpp
/* 구조체 안의 구조체*/
#include <stdio.h>
struct employee
{
    int age;
    int salary;
};
struct company
{
    struct employee data;
    char name[10];
};
int main()
{
    struct company Kim;

    Kim.data.age = 31;
    Kim.data.salary = 3000000;

    printf("Kim's age : %d \n", Kim.data.age);
    printf("Kim's salary : %d$/year \n", Kim.data.salary);

    return 0;
}

```

성공적으로 컴파일 했다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1701851E4BCAB179451724)

먼저 `employee` 구조체를 살펴 봅시다.

```cpp
struct employee
{
    int age;
    int salary;
};
```

위 구조체에는 `int` 형의 `age` 와 `salary` 변수 두 개가 멤버로 되어 있습니다. 다음, `company` 구조체를 살펴보면

```cpp
struct company
{
    struct employee data;
    char name[10];
};

```

와 같이 또다른 구조체 변수를 멤버로 가짐을 볼 수 있습니다. 뭔가 이상하다는 느낌이 들 수 도 있는데, 사실 위와 같이 정의해도 되는 것은 당연한 일입니다. 왜냐하면 제가 이전에도 말했듯이 구조체는 '사용자가 정의한 또다른 형(type)' 이라고 보는 것이기 때문이죠. 구조체 역시 `int` 나 `char` 과 같은 하나의 형 입니다. 우리가 만든 형은 이름이 'struct employee' 라는 것이고, 그 중 `data` 라는 (구조체) 변수를 생성하였죠. 이는 `int a` 와 지극히 똑같은 작업 입니다.

```cpp
    struct company Kim;
```

위와 같이 `company` 구조체를 정의한 뒤, 'struct company' 형의 변수 `Kim` 을 정의하였습니다. 이제, `Kim` 의 멤버들에게 값을 대입해 보아야 겠죠.

```cpp
    Kim.data.age = 31;
```

일단 위 문장을 살펴 봅시다. '.' 연산자의 우선 순위는 왼쪽 부터 이므로 `Kim.data` 가 해석 된 후, (Kim.data).age 가 해석이 됩니다. 다시 말해 "Kim 의 `data` 멤버의 `age` 멤버" 로 생각 되는 것이지요. 따라서 위와 같이 "Kim 의 `data` 멤버의 `age` 멤버" 에 31 의 값을 넣었습니다. 마찬가지로 `salary` 에`30000` 을 넣었지요 30000 을 넣었지요.

따라서 위와 같이 출력이 됩니다.



###  구조체를 리턴하는 함수




구조체는 말그대로여러분이 창조하신 하나의 타입이기 때문에 `int , char` 등이 가능했던 모든 것들을 구조체는 그대로 할 수 있습니다. 역시 구조체 형을 리턴하는 함수도 가능하겠지요.

```cpp
/* 구조체를 리턴하는 함수 */
#include <stdio.h>
struct AA function(int j);
struct AA
{
    int i;
};

int main()
{
    struct AA a;

    a = function(10);
    printf("a.i : %d \n", a.i);

return 0;
}

struct AA function(int j)
{
    struct AA A;
    A.i = j;

    return A;
}
```


성공적으로 컴파일 했다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F202E540D4C14C54CAA7088)

먼저 `AA` 라는 구조체를 정의하였습니다. 편의상 멤버는 `int` i  로 하나만 가진다고 합시다.

```cpp
struct AA
{
    int i;
};
```


아래는 "struct AA" 형을 리턴하는 함수 `function` 입니다. 인자로는 `int j` 를 취합니다.

```cpp
struct AA function(int j)
{
    struct AA A;
    A.i = j;

    return A;
}
```

말그래도 `struct AA` 형을 리턴하기 때문에 리턴하는 것 역시 `struct AA` 형의 것이 되야 합니다. 위 함수는 인자로 받는 `j` 값으로 `A` 의 `i` 멤버를 `j` 의 값으로 초기화 한 후 이를 그대로 리턴합니다.

```cpp
    struct AA a;

    a = function(10);
```

우리는 `main` 함수에서 `struct AA` 타입의 구조체 변수 `a` 를 정의하였습니다. 그렇다면 `a =` function(10); 을 통해 `function(10)` 이 리턴한 구조체의 대입이 일어나게 됩니다.  `function(10)` 은 'i 멤버의 값이 10 인 구조체 변수' 를 리턴하므로 `a` 의 `i` 멤버 값은 10 이 됩니다.



###  구조체 변수의 정의 방법




우리는 여태까지 구조체 변수를 다음과 같이 정의하였습니다.

```info
struct Anomynous Var1, Var2; // "struct Anomynous" 형의 변수 Var1 , Var2 를 정의한다.
```

그런데 구조체 변수를 정의하는 방법 중 아래와 같이 색다른 방법을 소개해 드립니다.

```cpp
/*

구조체 변수를 정의하는 색다른 방법.
예제를 이렇게 길게 만든 이유는 소스를 읽으면서 구조체와 조금 더 친해지기 바래서 입니다.
소스를 찬찬히 분석해보세요 ^^

*/
 [#include <stdio.h>](https://t1.daumcdn.net/cfile/tistory/1422060F4C14D60306?tt_attachpath=/blog/329162/attach/cfile27.uf@1422060F4C14D60306D348.png)
char copy_str(char *dest, char *src);
int Print_Obj_Status (struct obj OBJ);
struct obj
{
    char name[20];
    int x,y;
} Ball;

int main()
{
    Ball.x = 3;
    Ball.y = 4;
    copy_str(Ball.name, "RED BALL");

    Print_Obj_Status(Ball);

    return 0;

}
int Print_Obj_Status (struct obj OBJ)
{
    printf("Location of %s \n", OBJ.name);
    printf("( %d , %d ) \n", OBJ.x, OBJ.y);

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


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F195FEB0C4C14C8D901E478)

```cpp
struct obj
{
    char name[20];
    int x,y;
} Ball;
```

저는 위와 같이 "sturct obj" 라는 구조체를 정의하였고 멤버는 위와 같습니다. 그런데, 맨 아래 `Ball` 은 무엇인가요? 이는 바로 그냥 `sturct obj` 형의 `Ball` 이란 구조체 변수를 정의하라는 뜻입니다. 사실 우리가 `main` 함수 내부에서

```cpp
struct obj Ball;
```

이라고 써왔든 것과 다를 바가 없습니다. 그냥, 위와 같이 구조체 변수를 정의하는 방법도 있다는 것을 알려 드린 것입니다.

나머지 부분은 여러분이 스스로 분석해 보시기 바랍니다.

```cpp
/* 멤버를 쉽게 초기화 하기*/
#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN
{
    int age;
    int height;
    int weight;
    int gender;
};

int main()
{
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(struct HUMAN human)
{
    if(human.gender == 0)
    {
        printf("MALE \n");
    }
    else
    {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height, human.weight);

    if(human.gender == 0 && human.height >= 180)
    {
        printf("HE IS A WINNER!! \n");
    }
    else if(human.gender == 0 && human.height < 180)
    {
        printf("HE IS A LOSER!! \n");
    }

    printf("------------------------------------------- \n");

    return 0;

}
```

성공적으로 컴파일 했다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F1814FB0C4C14CB0DD0DE6E)

위 예제도 역시 구조체의 잡다한 기능 중 하나를 보여주고 있습니다. 바로 멤버를 초기화 하는 방식 인데요, 우리가 이전까지 멤버를 초기화 해온 방법 보다 더 쉽게 할 수 있습니다.

```cpp
struct HUMAN
{
    int age;
    int height;
    int weight;
    int gender;
};
```

`HUMAN` 구조체는 위와 같이 4 개의 `int` 형 멤버들을 가지고 있습니다.

```cpp
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};
```

그리고 `main` 내부에서 위와 같이 `Adam` 과 `Eve` 를 정의하였죠. 이 때, `= {}` 를 통해서 중괄호 내부의 정보들이 순차적으로 각 멤버에 대입되게 됩니다. 따라서 `Adam` 의 경우 `age` 에는 31 이, `height` 에는 182 가, `weight` 에는 `75, gender` 에는 0 이 들어가게 되죠.

이전 예제에서 배운 초기화 방식에서는 다음과 같이 해주면 됩니다.

```cpp
struct HUMAN
{
    int age;
    int height;
    int weight;
    int gender;
}Adam = {31, 182, 75, 0}, Eve = {27, 166, 48, 1};
```


어때요? 간단하지요. 그렇다면 이전 예제의

```info
struct obj
{
    char name[20];
    int x,y;
};

```

의 경우 어떻게 하면 될까요? 간단 합니다.

```cpp
struct obj
{
    char name[20];
    int x,y;
} Ball={"abc", 10, 2};
```

와 같이 하게 되면 `name` 에는 "abc" `, x` 에는 `10, y` 에는 2 가 들어가게 됩니다.

여기서 구조체에 관한 이야기는 끝이 납니다. 아. 정말로 길었던 구조체 강좌였습니다. 아마 3 번의 강좌를 걸쳐서 제가 구조체에 관한 모든 지식들을 전달한 것 같습니다.



###  공용체 (union)




사실 공용체(union)는 그다지 많이 사용하는 기능은 아닙니다만, 그래도 C 언어에서 제공하는 것들 중 하나 이니 간단하게 나마 집고 넘어가도록 합시다. 공용체는 구조체와는 달리 메모리를 ‘공유’ 합니다. 이게 도대체 무슨 말인가 하면 아래 그림을 참조해주세요.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F1210640D4C14DC693AF455)

위 그림을 보아도 알 수 있듯이 공용체의 각 멤버들의메모리 시작 주소는 모두 동일합니다. 따라서 우리는 위 그림의 `union A` 의 경우 `j` 의 값을 변경함으로 써 `i` 의 값을 변경할 수 있고 마찬가지로 `i` 의 값을 변경함으로써  `j` 의 값을 변경할 수 있게 됩니다. 과연 이 말이 진짜 인지 확인해 보도록 합시다.

```cpp

/* 공용체 */
#include <stdio.h>
union A
{
    int i;
    char j;
};
int main()
{
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j);
    return 0;
}
```




성공적으로 컴파일 했다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F1868AA0C4C14DC6A84F982)





 음. 과연 우리는 `a` 의 `j` 멤버 값을 전혀 설정해 주지 않았음에도 불구하고 `i` 에 `0x12345678` 을 대입하자 `j` 의 값이 78 로 잘 나왔습니다. 그런데 이상한 점이 듭니다. 왜 78 이 나왔을 까요? `0x12` 가 나와야 되는 것 아닌가요? 분명히 `i` 와 `j` 에 동일한 주소값에 위치해 있고 `i` 가 `0x12345678` 로 메모리 상에 있다면 `j` 는 처음 두 개인 `0x12` 가 되어야 되는 것 아닌가요? 물론, 여러분의 생각은 옳습니다. 하지만 컴퓨터에서는 수를 이렇게 보관하지 않습니다. 적어도 여러분의 컴퓨터에서는요.





###  빅 엔디안 (Big Endian), 리틀 엔디안 (Little Endian)


  컴퓨터에서 메모리에 수를 저장할 때, 우리가 생각하는 방법, 즉 낮은 주소값에 상위 비트를 적는 방식을 빅 엔디안 방식이라고 합니다. 그리고, 우리가 생각하는 방법의 정반대로 높은 주소값에 상위 비트를 적는 방식을 리틀 엔디안`` 이라고 합니다. 현재대부분은 `x86` 프로세서는 리틀 엔디안`` 방식을 사용하고 있고 일부 컴퓨터에서만 빅 엔디안 방식을 사용하고 있습니다. 먼저, 빅 엔디안 에서 수를 어떻게 저장하는지 보면
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F15149E0E4C14DC6A3AB3FF)


와 같이 상식적으로 수를 저장하게 됩니다. 하지만 이건 빅 엔디안 방식의 경우이고요, 우리가 대부분 사용하는 프로세서는 리틀 엔디안 방식이므로 리틀 엔디안 방식의 경우를 살펴 보게 되면
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile8.uf.tistory.com%2Fimage%2F122BC3054C14DC6B87546A)

와 같이 1 바이트 씩 역으로 보관함을 알 수 있다. 따라서 우리가 출력했던 `j` 값은 `0x78` 이 된다.만일 `j` 를 `short` 형을 지정했으면 어떨까? `0x7856` 이 나올까? `0x5678` 이 나올까?간단히 확인해보자
```cpp

#include <stdio.h>
union A
{
    int i;
    short j;
};
int main()
{
    union A a;
    a.i = 0x12345678;
    printf("%x", a.j);
    return 0;
}
```




성공적으로 컴파일 했다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F1868700C4C14DC6B7EB212)




로 `0x5678` 이 나오게 된다.


이제 다시 머리가 혼란스러워 지기 시작했습니다. 메모리 상에 그대로 살펴 보게 되면 분명히 `j` 에 해당하는 부분은 `0x7856` 으로 출력되야 정상이지만 컴퓨터는 ‘지극히 정상적으로’ `0x5678` 을 출력하였습니다. 도대체 왜 그럴까. 그 이유는 간단합니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile24.uf.tistory.com%2Fimage%2F1522E70D4C14DC6C02944D)





이번에는 `j` 가 `short` 형 (2 바이트) 이므로 위와 같이 `j` 가 2 바이트를 차지하게 됩니다. 이 때 왜 `j` 의 값을 출력하면 `0x7856` 이 나오지 않고 `0x5678` 이 나올까? 이 문제에 대해 고민하고 있을 여러분을 위해 질문을 하나 던지겠습니다. `i` 의 값을 출력하면 얼마가 나올까요? 당연히 `0x12345678` 이 될것입니다. 왜냐하면 컴퓨터는 자신이 메모리에 수를 ‘리틀 엔디안 방식’ 을 저장하고 있다는 사실을 알고 있기 때문이죠. 따라서 이를 출력할 때에는 적절한 변환을 취해서 `0x12345678` 을 출력할 것입니다.


`j` 의 경우도 마찬가지 입니다. `j` 는 현재 ‘78 56’ 부분을 가리키고 있지만 컴퓨터는 `j` 가 리틀 엔디안 형식으로 이루어 졌다는 것을 알기 때문에 `j` 를 출력할 때에는 적절히 변환하여 `0x5678` 을 출력하게 될 것입니다.


어때요? 간단 하지요?


공용체에 관한 설명은 여기서 끝납니다. 아마도 공용체를 접할 가능성이 100 번 코딩 하다 보면 1 번 나올까 말까 한데 이를 자세히 짚고 넘어가는 것은 큰 의미가 없다고 생각합니다. 사실 공용체에 대해 배운 것 보다는 엔디안에 대해 배운 것이 훨씬 중요하기 때문에 혹여라도 엔디안에 대해 잊는 일은 없길 바랍니다.




###  열거형 (Enum)


열거형도 그닥 많이 쓰이는 것은 아니지만 사용 빈도로 볼 때 구조체 `>` 열거형 `>>` 공용체 라고 보시면 되겠습니다. 열거형을 알고 나면 상당히 편리한 일이 많기 때문에 잘 습득 하시기 바랍니다. (상당히 간단합니다)
프로그래밍을 하다 보면 각 데이터에 수를 대응 시키는 경우가 많습니다. 예를 들어 사람을 처리할 때, 남자에는 `0,` 여자에는 1 을 대응시켜서 처리하거나 색깔을 나타낼 때도 빨강에는 `0 ,` 흰색에는 1 등을 대응 시켜서 나타내게 됩니다. 이렇게 수를 대응 시켜서 처리할 때 에는 아래와 같이 헷깔리는 경우가 발생합니다.
```info
if (human.gender == 0) // 사람의 성별이 0 일 때
```

즉 남자에는 `0,` 여자에는 1 임을 확실하게 기억하고 있다면 상관이 없겠지만 기억하지 못하게 된다면 성에 대해 무엇을 대응 시켰는지 다시 찾아 보아야 된다는 번거로운 일이 발생합니다. 하지만 아래와 같이
```info
if(human.gender == MALE) // 사람의 성별이 남자 일 때
```

와 같이 한다면 확실히 알아 듣기 쉽겠지요. 하지만 문제는 이를 위해 `MALE` 이라는 상수를 설정해야 되고 이 때문에 메모리가 낭비되게 됩니다. 이는 프로그래머의 입장에서 난감한 일이 아닐 수 없지요.`C` 에서는 이를 열거형(Enum)을 도입해서 말끔하게 해결해줍니다 C 에서는 이를 열거형(Enum)을 도입해서 말끔하게 해결해줍니다.

```cpp

/* 열거형의 도입 */
#include <stdio.h>
enum {RED, BLUE, WHITE, BLACK};
int main()
{
    int palette = RED;
    switch(palette)
    {
    case RED:
        printf("palette : RED \n");
        break;
    case BLUE:
        printf("palette : BLUE \n");
        break;

    case WHITE:        printf("palette : WHITE \n");        break;
    case BLACK:        printf("palette : BLACK \n");        break;    }}
```




성공적으로 컴파일 했다면


![](http://)



일단, 열거형을 정의한 부분 부터 살펴 봅시다.


```cpp
enum {RED, BLUE, WHITE, BLACK};
```




열거형을 나타내기 위해서는 `enum` 을 쓰고 중괄호 안에 각각에 대해 써주면 됩니다. 그렇다면 컴파일러는 열거형에 나타나 있는 각 원소에 0 부터 차례로 정수값을 매겨 주게 됩니다. 즉 `RED = 0, BLUE = 1, .. BLACK = 3` 와 같이 말이지요. 이제 우리는 이를 자유롭게 이용하면 됩니다.


예를 들어


```info
if(palette == 0) // 현재 파레트의 색이 빨강인지 확인한다.
```




로 했던 것을



```info
if(palette == RED) // 현재 파레트의 색이 빨강인지 확인한다.
```




로 하면 됩니다. 사실 위와 의미는 정확히 똑같지만 프로그래머가 읽을 때 에는 큰 차이가 있게 되죠. 위와 같이 한다고 해서 실질적으로 `RED` 라는 변수가 메모리에 정해지는 것은 아닙니다. 컴파일 시에 컴파일러는 `RED` 는 모두 0 로 바꾸고 `BLUE` 는 모두 1 로 바꾸는 등 변환 작업을 하게 됩니다.



```cpp

/* 열거형 팁 */
#include <stdio.h>
enum {RED = 3, BLUE, WHITE, BLACK};
int main()
{
    int palette = BLACK;
    printf("%d \n", palette);
}
```




성공적으로 컴파일 했다면


![](http://)



열거형에서 처음 수를 0 으로 시작하기 싫다면 어떨까요. 단순히 원하는 수로 해주면 됩니다. 예를 들어 위와 같이



```cpp
enum {RED = 3, BLUE, WHITE, BLACK};
```




으로 한다면 `RED = 3` 부터 해서 `BLUE = 4, WHITE = 5, BLACK = 6` 이 됩니다. 또한,


```cpp
enum {RED = 3, BLUE , WHITE = 3, BLACK}
```




으로 한다면 수를 지정한 부분 부터 다시 시작 되는 방식으로 `BLUE = 4, BLACK = 4` 가 됩니다.
참고로 열거형 에서는 언제나 ‘정수값’ 이여야만 합니다.



생각해볼 문제


`1)` 공용체는 도대체 어디에 써먹을 수 있을까요? 아래 글을 읽어보세요

http://www.go4expert.com/forums/showthread.php?t=15


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <16 - 3. 구조체와 친구들(공용체(union), 열거형(enum))>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```



