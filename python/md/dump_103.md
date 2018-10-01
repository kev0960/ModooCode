----------------
title : 씹어먹는 C 언어 - <22. C 언어의 잡다한 키워드들 (typedef, volatile, #pragma)>
cat_title : 22. C 언어의 잡다한 키워드들 (typedef, volatile, #pragma)
next_page : 117
--------------


이번 강좌에서는

* `typedef` 키워드에 대해 알아본다.

* `volatile` 키워드에 대해 알아본다.

* `#pragma` 에 대해 알고, 특히 `#pragma pack` 과 `#pragma once` 키워드에 대해 이해한다.

![씹어먹는 C 언어](/img/ChewingClogo.png)

안녕하세요 여러분. 저의 C 언어 강의도 이제 막바지에 다다랐습니다. 정말로 첫번째 강의부터 여기 까지 달려오셨다면 정말 대단하다고 말씀 드리고 싶네요. 마라톤에 비유하자면, `42.195km` 에서 한 `40km` 정도 까지 열심히 뛰어 왔다고 보시면 됩니다. 그럼, 나머지 `2.195km` 도 더 뛸 의향이 있겠죠?

```cpp
/* 루저 위너 판별*/
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

위 코드는 이전에 구조체 단원에서 만들었던 루저-위너 구별 프로그램 입니다. 그런데 위 코드에서 한 가지 귀찮은 점이 있습니다. 바로, 구조체를 사용할 때 마다 앞에 `struct` 키워드를 붙여야 한다는 점입니다. 이게 상당히 짜증나는 일인데, 간혹 `struct` 키워드를 붙이지 않는 날에는

```warning
error C2146: 구문 오류 : ')'이(가) 'human' 식별자 앞에 없습니다.
error C2061: 구문 오류 : 식별자 'human'
error C2059: 구문 오류 : ';'
error C2059: 구문 오류 : ')'
error C2449: 파일 범위에 '{'가 있습니다. 함수 헤더가 없는 것 같습니다.
error C2059: 구문 오류 : '}'
```


위와 같은 오류 테러를 맞보게 됩니다. (위 오류는 `int Print_Status(struct HUMAN human)` 대신에 `int Print_Status(HUMAN human)` 이라 썼을 때 나타나는 오류들 입니다) 상당히 짜증나는 일지요. 그렇다면 귀찮게 'struct HUMAN' 이라 길게 쓰는 대신에 짧에 쓰는 방법이 없을까요?

물론 있습니다.

```cpp
/* typedef 의 이용 */
#include <stdio.h>
struct HUMAN
{
    int age;
    int height;
    int weight;
    int gender;
};

typedef struct HUMAN Human;
int Print_Status(Human human);
int main()
{
    Human Adam = {31, 182, 75, 0};
    Human Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(Human human)
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

성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F157220264CF104BC288A84)

와 같이 나옵니다.

위 코드에서 가장 눈여겨 보아야 할 부분은

```cpp
typedef struct HUMAN Human;
```


입니다. 우리는 여기서 `typedef` 라는 키워드를 사용했는데 이 키워드는 다음과 같이 사용합니다

```info
typedef (이름을 새로 부여하고자 하는 타입) (새로 준 타입의 이름)
```


다시 말해 위에서 썼던 코드는 `struct HUMAN` 이라는 타입에 `Human` 이라는 다른 이름을 붙인 것이 됩니다. 즉, `struct HUMAN` 이라고 쓸 것을 `Human` 이라고 써도 된다는 것이지요. 물론 기존의 이름을 없애 버린 것이 아니기 때문에 `typedef` 를 사용한 이후에도 `struct HUMAN` 이라고 쓴 것은 유효 합니다.

즉 위와 같은 일을 하고 나면 다음과 같은 문장은 모두 동일해집니다.

```cpp
    struct HUMAN a;
    Human a;
```

상당히 편리해졌지요? 하지만 진정 `typedef` 를 이용하는 이유는 이렇게 형을 간단하게 쓴다는 이유 때만은 아닙니다. 아래의 예제를 보세요.

```cpp
/* 간단한 계산기 프로그램 */
#include <stdio.h>
int main()
{
    int input;
    int a,b;

    while(1)
    {
        printf("--- 계산기 --- \n");
        printf("1. 덧셈 \n");
        printf("2. 뺄셈 \n");
        printf("3. 종료 \n");

        scanf("%d", &input);

        if(input == 1)
        {
            printf("두 수 : ");
            scanf("%d%d", &a, &b);
            printf("%d 와 %d 의 합 : %d \n", a,b,a+b);
        }
        else if(input == 2)
        {
            printf("두 수 : ");
            scanf("%d%d", &a, &b);
            printf("%d 와 %d 의 차 : %d \n", a,b,a-b);
        }
        else
            break;
    }

    return 0;
}
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F2057E0564D0D58391AEC1F)

와 같이 계산기 프로그램이 잘 실행됩니다. 만일 이 프로그램을 실제 계산기에 사용한다고 합시다. 그런데, 우리가 이 프로그램을 사용할 계산기는 안타깝게도 `CPU` 에서 32 비트 정수의 연산을 할 수 없습니다. 오직 16 비트 이하만 연산할 수 있다고 합시다. 그렇다면 이 계산기에서 `int` 형을 사용하는 것은 불가능 하고 `short` 나 `char` 형의 변수들만 선언해야 겠죠.

그렇다면 이를 위해 소스 코드 전체의 모든 변수들을 `char` 이나 `short` 로 바꿔주어야 합니다. 그런데 만일 동일한 프로그램인데 다른 기종의 계산기 에서는 `int` 형이 사용 가능하다고 합시다. 그렇다면 이 코드를 다시 또 바꿔주어야 합니다. 아주 아주 귀찮은 일이 아닐 수 없죠. 이런 상황을 대비하여서 다음과 같이 코드를 바꿔봅시다.

```cpp
/* 향상된 소스 코드 */
#include <stdio.h>
typedef int CAL_TYPE;
int main()
{
    CAL_TYPE input;
    CAL_TYPE a,b;

    while(1)
    {
        printf("--- 계산기 --- \n");
        printf("1. 덧셈 \n");
        printf("2. 뺄셈 \n");
        printf("3. 종료 \n");

        scanf("%d", &input);

        if(input == 1)
        {
            printf("두 수 : ");
            scanf("%d%d", &a, &b);
            printf("%d 와 %d 의 합 : %d \n", a,b,a+b);
        }
        else if(input == 2)
        {
            printf("두 수 : ");
            scanf("%d%d", &a, &b);
            printf("%d 와 %d 의 차 : %d \n", a,b,a-b);
        }
        else
            break;
    }

    return 0;
}
```


이 역시 잘 실행됩니다. 다만 바뀐 것은 변수들의 타입을 `CAL_TYPE` 라고 했던 점이지요. 그리고 위에서 `typedef` 를 통해 `CAL_TYPE` 가 `int` 형과 같다고 정의하였습니다. 만일 이 소스 코드를 `short` 나 `char` 만 되는 계산기에 적용시킬려면 어떻게 해야 할까요? 기존에는 모든 변수의 타입을 전부다 수정해야 했지만 이제는 `typedef` 에서 `CAL_TYPE` 의 형을 `short` 나 `char` 로 간단히 바꿔버리면 되는 것입니다. 정말로 일이 쉬워졌습니다.



### 여러가지 `typedef` 들


```cpp
/* 여러가지 typedef 예제들 */


 #include <stdio.h>
 int add(int a, int b){
       return a+b;
   }
   typedef int CAL_TYPE;
   typedef int (*Padd)(int,int);
   typedef int Arrays[10];
   int main(){
         CAL_TYPE a = 10;
         Arrays arr = {1,2,3,4,5,6,7,8,9,0}; 
        Padd ptr = add;
         printf("a : %d \n", a);
         printf("arr[3] : %d \n", arr[3]);
         printf("add(3, 5) : %d \n", ptr(3,5));
         return 0;
     }
```


성공적으로 컴파일 하였다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F20513A4E4D0D5B96266941)


가장 먼저 소스 코드에서 아래 문장 부터 살펴봅시다.

```cpp
typedef int (*Padd)(int,int);
```


이전에 배웠던 함수 포인터가 잘 기억이 나시는지는 잘 모르겠지만 아무튼, 위 `typedef` 명령문은 복잡한 함수 포인터 명령을 `Padd` 라는 이름을 붙이는 것입니다. 즉, 다음 문장은 정확히 동일해집니다.

```cpp
int (*ptr)(int, int) = add;
Padd ptr = add;
```

참고로 간혹

```cpp
typedef int (*Padd)(int,int);
```

문장을 잘못 이해 하셔서, "우리가 앞에서 배운 바에 따르면 위 문장은 `int` 라는 형에 `(*Padd)(int, int)` 라는 또다른 이름을 붙이는 것이 아닌가?" 라고 물으실 수 있는데, 그건 아니고 `Padd` 라는 이름을 붙여주신다고 생각하시면 편합니다. 마찬가지로

```cpp
typedef int Arrays[10];
```


도 역시 '원소가 10 개인 `int` 형 배열을 선언해라' 문장을 `Arrays` 라고 하나의 이름으로 바꾼 것이라 보면 됩니다. 즉,

```cpp
int arr[10];
Arrays arr;
```

은 정확히 동일한 문장입니다.



### `volatile` 키워드





`volatile` 은 아주 아주 특수한 상황이 아니고서는 사용하지 않는 키워드 입니다. 사실 저도 그렇게 흔하게  사용하지 않고요. `volatile` 키워드를 사용하는 경우는 대부분 외부 하드웨어와 통신할 때 사용하게 됩니다. 이 말이 무슨 말이냐면, 아래 예제를 보시면 알게 될 것입니다.

만일 여러분이 특정한 외부 센서와 소통하는 프로그램을 만든다고 합시다. 이 센서는 RAM 의 특정 영역을 이용하는데, 만일 센서에 값이 감지되지 않으면 그 곳의 값이 0 이 되어 무언가가 감지되면 그 부분의 값을 1 로 한다고 합시다. 그렇다면 여러분은 십중팔구 아래와 같은 코드를 작성할 것입니다.

```cpp
#include <stdio.h>
typedef struct SENSOR
{
    /* 감지 안되면 0, 감지되면 1 이다.*/
    int sensor_flag;
    int data;
} SENSOR;

int main()
{
    SENSOR *sensor;
    /* 값이 감지되지 않는 동안 계속 무한 루프를 돈다*/
    while(!(sensor->sensor_flag))
    {
    }
    printf("Data : %d \n", sensor->data);
}
```

\sidenote{참고로 typedef 를 위와 같이 써줌으로써 typedef struct SENSOR SENSOR 한 효과를 낼 수 있습니다.} 위 코드는 가상의 코드 이므로 컴파일 해보지 않겠습니다만, 일단 여러분은 위 코드에서 별 이상을 느끼지는 못할 것입니다. 하지만 똑똑한 컴파일러는 ‘너무 과하게 똑똑해서’ 우리가 사용한 `while` 문을 최적화 해버립니다. 보통의 상황에서 `sensor->sensor_flag` 의 값이 바뀌는 경우는 없기 때문에 굳이 `while` 문을 매번 돌릴 때 마다 값을 비교할 필요가 없게 되는 것이지요. 그냥 컴파일러는 값을 딱 한 번만 읽고 0 이 아니라면 그냥 가고, 0 이라면 `while` 문을 무한히 돌리는 것으로 생각해버립니다. 결과적으로 위 코드를 컴파일러는 다음과 같은 코드로 바꿔버립니다.

```cpp

#include <stdio.h>
typedef struct SENSOR
{
    /* 감지 안되면 0, 감지되면 1 이다.*/
    int sensor_flag;
    int data;
}SENSOR;
int main()
{
    SENSOR *sensor;
    if(!(sensor->sensor_flag))
    {
        while(1)
        {
        }
    }
    printf("Data : %d \n", sensor->data);
}
```



이는 우리가 결코 원하던 결과가 아닙니다. 만일 센서에 값이 감지되었다고 해도 `while` 문을 절대로 탈출할 수 없게 되어 무한 루프에 빠지게 되는 것이지요. 우리는 컴파일러가 이런 최적화 작업을 수행하는 것을 원하지 않습니다. 이를 컴파일러에게 알려주기 위해서는 두 가지 방법이 있습니다.

첫번째로는 컴파일러의 최적화 옵션을 빼버리는 것입니다. `gcc` 에서는 단순히 최적화 옵션을 안주면 됩니다. `Visual Studio` 에서는 살짝 복잡한데, 프로젝트 속성의 **C/C++ –> 최적화** 에서 사용 안함을 선택하시면 됩니다. 그런데, 최적화를 하지 않기에는 너무나 그 손실이 큽니다. 최적화 옵션을 끄는 순간 다른 모든 코드들도 최적화를 하지 않겠다는 의미가 되거든요. 이를 위해 `volatile` 키워드가 생겨났습니다.

```cpp

#include <stdio.h>
typedef struct SENSOR
{
    /* 감지 안되면 0, 감지되면 1 이다.*/
    int sensor_flag;
    int data;
} SENSOR;

int main()
{
    volatile SENSOR *sensor;
    /* 값이 감지되지 않는 동안 계속 무한 루프를 돈다*/
    while(!(sensor->sensor_flag))
    {
    }
    printf("Data : %d \n", sensor->data);
}
```



이렇게 해준 순간 컴파일러는 `sensor` 에 대해 최적화를 수행하지 않게 됩니다. `volatile` 의 의미는 ‘변덕스러운’ 이라는 의미를 가지고 있는데, `sensor` 에 `volatile` 키워드를 붙여준 순간 `sensor->sensor_flag` 의 값이 ‘변덕스럽게 변할 수 있기 때문’ 에 이에 대한 최적화 작업들을 수행하지 말라 라는 의미가 됩니다. 따라서 컴파일러는 위 소스를 의미 그대로 컴파일 하게 되어 우리가 원하던 결과를 얻을 수 있게 됩니다.

### #pragma 키워드

`#pragma` 는 **컴파일러에게 말하는 전처리기 명령** 이라고 보시면 됩니다. 즉, `#include` 나 `#define` 처럼 전처리기에 의해 컴파일 이전에 처리되지만, 그 명령은 컴파일러에게 전달되기 때문이죠. 사실 `pragma` 는 C 언어의 기본 키워드라고 하기 보다는, 컴파일러에 종속적인 키워드라고 하는 것이 맞습니다. `pragma` 를 사용하는 문법은 컴파일러 마다 다르고 딱히 통일 된 것이 없기 때문입니다. 이 강좌에서는 `pragma` 를 사용하는 몇 가지 예제들을 보고 어떤 경우에 편리하게 `pragma` 를 사용할 수 있는지 살펴봅시다.

#### `#pragma pack`

```cpp
#include <stdio.h>
struct Weird
{
    char arr[2];
    int i;
};
int main()
{
    struct Weird a;
    printf("size of a : %d \n", sizeof(a));
    return 0;
}
```



성공적으로 컴파일 했다면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile25.uf.tistory.com%2Fimage%2F160848524D1491DA137DB7)

와 같이 나옵니다.


상당히 이상하지요. 분명히 `Weird` 구조체 내의 원소들의 총 바이트 수를 계산해보면 `arr` 은 `char` 형 변수 2 개로 2 바이트 이고, `i` 는 `int` 형 변수 1 개로 4 바이트 이므로 6 이 나와야 정상이지요. 그런데 도대체 왜 컴퓨터는 이를 8 로 출력했을까요?

왜냐하면 실제로 메모리 상에서 위 구조체의 크기를 8 바이트로 **컴파일러**가 지정하였기 때문입니다. 현재 우리가 사용하는 컴퓨터에서는 언제나 4 바이트 단위로 모든 것을 처리하는 것이 빠릅니다. 따라서 언제나 컴퓨터에서 데이터를 보관할 때 에는 4의 배수로 데이터를 보관하는 것이 처리시 용이하게 됩니다. 이렇게 데이터가 4 의 배수 경계에 놓인 것을 *더블 워드 경계에 놓여 있다* 라고 합니다.

이러한 이유 때문에 위 `Weird` 구조체 역시 4 의 배수를 맞추기 위해 크기를 8 바이트로 ‘필요없는 2 바이트를 추가하면서 까지’ 맞춘 것입니다. 이 문제가 중요하게 여겨지는 부분은 역시 하드웨어 간의 통신 때문에 그렇습니다. 

예를 들어서 `SCSI` 인터페이스는 `PC` 에서 하드 디스크와 같은 주변 기기에 연결하기 위한 통신 방식으로 `SCSI` 장치들에게 읽기 명령을 내리기 위해서는 6 바이트의 명령어를 전송하면 됩니다. 이 6 바이트의 명령어의 구조는 꽤 복잡해서 흔히 구조체로 많이 이용하는데, 만일 위와 같이 그냥 사용했다가는 구조체의 크기가 8 바이트로 설정되어서 무슨 문제가 생길 지 알 수 없습니다.

이렇게 컴파일러로 하여금 구조체를 더블 워드 경계에 놓지 말라고 하고 싶을 때 `pragma` 키워드를 이용하면 됩니다.

```cpp
#include <stdio.h>
/* 전처리기 명령에는 ; 를 붙이지 않는다! */
#pragma pack(1)
struct Weird
{
    char arr[2];
    int i;
};
int main()
{
    struct Weird a;
    printf("size of a : %d \n", sizeof(a));
    return 0;
}
```

성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile21.uf.tistory.com%2Fimage%2F180710424D14A4D401D28E)

와 같이 나옵니다.

이번에는 6 으로 잘 나옵니다. 위 명령은 마이크로소프트 계열의 컴파일러들에만 유효한 문장인데, 구조체를 ‘1 바이트 단위로 정렬하라는 뜻’ 입니다. 즉, 구조체의 크기가 1 의 배수가 되게 하라는 것이지요. 1 외에도 2,4,8,16 등이 올 수 있습니다. 만일 기본값, 즉 더블 워드 경계로 정렬하기 위해서는 `#pragma pack(4)` 로 하시면 됩니다.

#### `#pragma once`

아까의 `Weird` 구조체 예제에서 `Werid` 부분만 다른 헤더파일로 빼놓아 봅시다. 이 헤더파일의 이름은 `werid.h` 입니다.

```cpp
/* weird.h */
struct Weird
{
    char arr[2];
    int i;
};
```

```cpp

/* test.c*/
#include <stdio.h>
#include "weird.h"
int main()
{
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
}
```



성공적으로 컴파일 했다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F186C4F424D14A4D42684F7)




와 같이 나옵니다.

상당히 단순한 예제이지요. `test.c` 에서 `weird.h` 를 포함했으므로 `weird.h` 의 내용이 `test.c` 로 그대로 복사된 셈입니다. (즉, #include “weird.h” 부분이 `weird.h` 의  내용으로 바뀌었다고 보셔도 무방합니다) 따라서 `struct Weird` 를 사용할 수 있게 되므로 위와 같은 결과가 발생합니다. 그런데 만일 실수로 `weird.h` 를 두 번 포함했다고 합시다. 그렇다면 어떻게 될까요?

```cpp

#include <stdio.h>
#include "weird.h"
#include "weird.h"
int main()
{
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
}
```



컴파일 하였다면

```warning
error C2011: 'Weird' : 'struct' 형식 재정의
 'Weird' 선언을 참조하십시오.
```


위와 같이 오류를 만나게 됩니다. 왜냐하면 각각 `#include "weird.h"` 부분이 `weird.h` 의 내용으로 바뀌어서 결과적으로는

```cpp

#include <stdio.h>
struct Weird
{
    char arr[2];
    int i;
};
struct Weird
{
    char arr[2];
    int i;
};

int main()
{
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
}
```



를 한 것과 마찬가지가 되어서 `struct Weird` 를 두 번 정의하였다고 오류가 나게 됩니다. 이를 막으려면 어떻게 해야 할까요?
일단 C 의 기본 전처리기 명령을 이용하여 하는 방법이 있습니다.

```cpp

/* 수정된 weird.h*/
#ifndef WEIRD_H
#define WEIRD_H
struct Weird
{
    char arr[2];
    int i;
};
#endif
```



```cpp

/* 이상한 test.c*/
#include <stdio.h>
#include "weird.h"
#include "weird.h"
int main()
{
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
}
```



성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F186C4F424D14A4D42684F7)




와 같이 잘 실행됩니다. 일단 왜 오류가 나지 않는지 살펴 봅시다. 우리가 전처리기라고 한다면 맨 처음에 첫번째 `#include "weird.h"` 를 만났을 때 `WEIRD_H` 가 정의되어 있지 않으므로 #ifndef 가 참이 되어 아래 #define `WEIRD_H` 가 수행되어 `WEIRD_H` 라는 것이 정의됩니다. (값은 모르지만 아무튼, 이러한 이름이 정의되었다고 합시다) 또한 헤더파일의 내용도 `test.c` 로 그대로 복사되죠. 그 후에 실수로 `weird.h` 를 다시 한 번 `include` 하였을 때 에는 이미 `WEIRD_H` 가 정의되어 있는 상태이므로 `#ifndef WEIRD_H` 가 거짓이 되어 #endif 로 넘어가버려 `test.c` 에 그 내용이 복사가 안됩니다.

이렇게 하면 헤더파일의 내용이 중복으로 포함되는 것을 막을 수 있습니다. (이는 이미 수많은 헤더파일에서 사용되고 있는 방법입니다) 하지만 `#pragma` 를 이용하면 훨씬 단순하게 할 수 있는데,

```cpp

/* #pragma 의 위엄 – weird.h*/
#pragma once
struct Weird
{
    char arr[2];
    int i;
};
```




```cpp

/* test.c*/
#include <stdio.h>
#include "weird.h"
#include "weird.h"
int main()
{
    struct Weird a;
    a.i = 3;
    printf("Weird 구조체의 a.i : %d \n", a.i);
    return 0;
}
```



성공적으로 컴파일 하였다면

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile10.uf.tistory.com%2Fimage%2F186C4F424D14A4D42684F7)




와 같이 잘 나옵니다. 이 명령은 컴파일러로 하여금 이 파일이 오직 딱 한 번만 `include` 될 수 있다는 것을 말해주는데, 이는 위에서 #ifndef 를 이용하여 복잡하게 하였던 작업들을 단순하게 한 문장으로 끝낼 수 있게 됩니다. 또한 `#pragma once` 의 장점으로 `#ifndef` 를 이용하는 것 보다 컴파일 시간을 절약할 수 있다는 점인데, `#ifndef` 를 이용하게 되면 `include` 하였을 때 전처리기가 직접 헤더파일을 열어 보아서 과연 `WEIRD_H` 가 정의되었나 정의되지 않았나 확인해 보아야 하는데, `pragma once` 를 이용하면 한 번 `include` 되었다면 헤더파일을 다시 열어보지도 않기 때문에 컴파일 시간이 절약되는 효과가 나게 됩니다.

다만 앞에서도 말했듯이 `#pragma` 관련 키워드들이 컴파일러 종속적이여서 어떤 컴파일러에서는 `#pragma once` 가 지원이 되지 않을 수 도 있습니다. 따라서 무슨 컴파일러를 사용하는지 보고 `#pragma once` 를 지원한다면 되도록 이것을 사용하는 것이 도움이 됩니다.

실제로 아래 코드는 `stdio.h` 의 헤더파일을 열어본 것입니다.

```cpp

/***
*stdio.h - definitions/declarations for standard I/O routines
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file defines the structures, values, macros, and functions
*       used by the level 2 I/O ("standard I/O") routines.
*       [ANSI/System V]
*
*       [Public]
*
****/
#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_STDIO
#define _INC_STDIO

/* 내용 (생략) */

#endif  /* _INC_STDIO */
```



위 헤더파일에서 사용하는 컴파일러마다 어떠한 키워드를 사용할 수 있게 하였는지 알 수 있는데,
```cpp
#if     _MSC_VER > 1000
#pragma once
#endif
```



를 보면 `_MSC_VER` 이 1000 보다 크면 `#pragma once` 키워드를 사용하라고 되어있습니다. `_MSC_VER` 은 마이크로소프트 사의 전처리기에 의해 기본적으로 정의되어 있는 상수로 컴파일러의 버전을 나타내는데, `Visual C++` 의 경우 `_MSC_VER` 값이 1000 부터 시작 하여 현재 2008 버전은 1500 의 값을 가지고 있습니다. 즉, 현재 버전의 컴파일러의 경우 `_MSV_VER > 1000` 이 참이 되므로 `#pragma once` 키워드를 이용하게 됩니다. 구 버전의 컴파일러는 그 아래

```cpp

#ifndef _INC_STDIO
#define _INC_STDIO

…

#endif  /* _INC_STDIO */
```



과 같이 C 표준 방식의 형태를 사용하도록 되어 있는 것을 볼 수 있습니다.

자. 이제 C 언어의 가장 뒷부분인 `typedef, volatile, #pragma` 와 같은 키워들에 대해서도 모두 알아 보았습니다. 이제 더이상 강의할 내용들도 별로 없는 것 같아서 슬프네요 ㅠㅠ. 아무튼 제 강의를 읽는 모든 분들, 즐거운 성탄절을 보내시기 바랍니다 :)

### 생각해 볼 문제

#### 문제 1

MSDN 에 들어가서 `#pragma` 와 연관된 키워드들을 잘 살펴보시기 바랍니다.
 [http://msdn.microsoft.com/en-us/library/d9x1s805%28v=VS.71%29.aspx](http://msdn.microsoft.com/en-us/library/d9x1s805%28v=VS.71%29.aspx)



```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는 <<씹어먹는 C 언어 - <22. C 언어의 잡다한 키워드들 (typedef, volatile, #pragma)>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```





