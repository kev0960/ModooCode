----------------
title : 씹어먹는 C 언어 - <20 - 1. 동동동 메모리 동적할당(Dynamic Memory Allocation)>
cat_title : 20 - 1. 동동동 메모리 동적할당(Dynamic Memory Allocation)
next_page : 100
--------------



이번 강좌에서는

* `malloc` 함수의 이해

* `1` 차원 배열 메모리 동적 할 1 차원 배열 메모리 동적 할당

* `2` 차원 배열 (정확히 말하면 우리가 아는 2 차원 배열과 틀리지만) 메모리 동적 할 2 차원 배열 (정확히 말하면 우리가 아는 2 차원 배열과 틀리지만) 메모리 동적 할당



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F165D28354C57BA87AF012C)

안녕하세요. 여러분. 정말 멀리 달려 온 것 같네요. 벌써 제 20 장을 지나가고 있습니다. 물론 강의 수로 따지면 더 많죠.

아마도 여러분은 프로그램을 만들면서 다음과 같은 문제에 봉착했던 적들이 많았었을 것입니다.


배열의 크기를 자유 자재로 다룰 수 있으면 얼마나 좋을까?

맞습니다. 우리가 배열을 정할 때 그 크기는 언제나 '컴파일 시간에 확정' 되어 있어야 합니다. 즉 컴파일러가 배열의 크기를 추측할 필요 없이 명확하게 나타나 있어야 된다는 것이지요. 하지만 이는 정말 고역스러운 일이 아닙니다. 예를 들어 우리가 컴퓨터로 부터 학생들의 수학 점수를 입력 받아 평균을 내는 프로그램을 만든다고 해봅시다. 각 학급 마다 학생들의 수가 모두 다르기 때문에 배열의 크기를 명확하게 정할 수 없게 됩니다. 따라서 보통 이 경우 배열을 '충분히 크게' 잡게 되는데 이렇게 된다면 메모리가 낭비되는 경우가 허다하게 발생합니다.

컴퓨터에서 '낭비' 란 곧 비효율적인 프로그램을 의미하는 것이지요. 이렇게 쓸데 없이 낭비되는 자원을 막기 위해 '학생 수' 를 입력 받고 그 학생 수 만큼 배열의 크기를 지정하면 얼마나 좋을까요. 하지만 놀랍게도 이렇게 할 수 있는 방법이 있습니다.

바로 '동적 메모리 할당' 이라는 방법 이지요. 이 것은 말그대로 '동적' 으로 메모리를 할당 합니다. 여기서 '동적' 이란 말은 딱 정해진 것이 아니라 가변적으로 변할 수 있다는 말이지요. 또한 메모리를 '할당' 한다는 이야기는 역시 우리가 배열을 정의하면 배열에 맞는 메모리의 특정한 공간이 배열을 나타내는 것 처럼 메모리의 특정한 부분을 사용할 수 있게 됩니다.참고적으로 아마 다 아시겠지만 할당되지 않는 메모리는 절대로 사용할 수 없습니다.

도대체 어떻게 그런 일이 가능할까요.

```cpp
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int SizeOfArray;
    int *arr;

    printf("만들고 싶은 배열의 원소의 수 : ");
    scanf("%d", &SizeOfArray);

    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    // int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성

    free(arr);

    return 0;

}
```


성공적으로 컴파일 했다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F1623460D4C578DE32320B7)

일단 위 예제를 통해서는 정말 우리가 원하는 크기의 배열이 생겼는지는 모르겠지만 일단 위 소스코드 부터 파헤쳐봅시다.

```cpp
    printf("만들고 싶은 배열의 원소의 수 : ");
    scanf("%d", &SizeOfArray);
```


먼저 우리는 위 과정을 통해서 우리가 원하고자 하는 `int` 배열의 원소의 개수를 입력 받았습니다. 그리고,

```cpp
    arr = (int *)malloc(sizeof(int) * SizeOfArray);
```


두둥. 바로 이 녀석이 우리가 원하는 작업을 해주는 역할을 합니다. 이 함수의 이름은`malloc``` 이며`memory allocation``` 의 약자 입니다. 이 함수는 `<stdlib.h>` 에 정의되어 있기 때문에 #include `<stdlib.h>` 를 추가해주어야 합니다.이 함수는 인자로 전달된 크기의 바이트 수 만큼 메모리 공간을 만듭니다. 즉 메모리 공간을 할당하게 되는 것이지요. 우리가 원소의 개수가 `SizeOfArray` 인 `int` 형 배열을 만들기 위해서는 당연히 (int 의 크기) `* (SizeOfArray)` 가 되겠지요. 이 때, 우리는 `int` 의 크기가 4 바이트 란 것을 알고 있지만 사실 이 '4 바이트' 라는 것이 정확히 정해진 것이 아니기 때문에 (즉 다른 컴퓨터에서는 `int` 가 4 바이트가 아닐 수 있습니다) `sizeof` 키워드를 사용하게 됩니다. `sizeof` 는 이 타입의 크기를 정확하게 알려줍니다. 따라서 `sizeof(int) * SizeOfArray` 를 인자로 전달해 주면 됩니다.

이 함수가 리턴하는 것은 자신이 할당한 메모리의 시작 주소를 리턴하게 됩니다. 이 때, 리턴형이 (void *) 형이므로 우리는 이를 (int *) 형으로 형변환 하여 `arr` 에 넣어주기만 하면 됩니다. 이렇게 보니 마치 `malloc` 함수가 공원에서 돗자리를 까는 역할을 하는 것과 같네요. 사람이 바글바글한 공원에서 `malloc` 함수는 '원하는 크기의 돗자리' 를 깔아주고 이 돗자리로 사람들이 올 수 있도록 손을 흔들어주는 역할을 하는 것과 같습니다.

따라서 `arr` 에는 `malloc` 이 할당해준 메모리를 이용할 수 있게 됩니다. 즉, `arr[SizeOfArray]` 만큼을 사용할 수 있게 되죠.

```cpp
    free(arr);
```


그리고 마지막에`free``` 는 우리가 할당받은 다 쓰고 난 후에 메모리 영역을 다시 컴퓨터에게 돌려주는 역할을 합니다. 이를 '해제(free)' 한다 그러는데 이 `free` 를 제대로 하지 않게 된다면 어떤 오류가 발생할지 아무도 알 수 없습니다. 이렇게 `free` 를 제대로 하지 않아 발생되는 문제를 메모리 누출(memory `leak)` 이라고 합니다. 이는 마치 공원에 돗자리를 깔아놓고 그대로 놓고 집에 가는 것과 똑같은 일입니다. (이런 일이 반복된다면 나중에 다시 왔을 때 공원에는 돗자리를 놓을 수 있는 공간이 하나도 없겠죠?)



###  malloc 은 어디에 할당할까?




우리가 이전에 [17 강](http://itguru.tistory.com/83)에서 메모리 구조에 대해 배울 때 메모리에는 다음과 같은 구조들이 있다는 것을 배웠습니다.

[##_1C|cfile27.uf@157F371D4C5790E83D0A22.png|width="587"_##]
이 때 다른 부분은 모두 설명하였는데 오직 '힙(Heap)' 에 대해서만 언급을 안했다는 것을 기억 하실 것입니다. 자, 이제 드디어 힙의 정체를 알 수 있는 시간입니다. 스택 이나, 데이타 영역, `Read Only Data` 부분은 당연하게도 `malloc` 함수가 결코 건드릴 수 없는 부분 입니다. 이 부분의 크기는 반드시 컴파일 때에 `100%` 추호의 의심의 여지도 없이 정해져야 합니다.

하지만 힙의 경우 다릅니다. 메모리의 힙 부분은 사용자가 자유롭게 할당하거나 해제할 수 있습니다. 따라서 우리의 `malloc` 함수도 이 힙을 이용하는 것입니다. 우리가 만들어낸 `arr` 은 힙에 위치하고 있습니다. 힙은 할당과 해제가 자유로운 만큼 제대로 사용해야 합니다. 만일 힙에 할당은 하였는데 해제를 하지 않았다면 나중에 어떠한 문제가 발생할지 모릅니다. 다른 메모리 부분의 경우 컴퓨터가 알아서 처리하기 때문에 문제가 발생할 여지가 적지만 힙은 인간이 다루는 만큼 철저히 해야 합니다.


```cpp
/* 동적 할당의 활용 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int student; // 입력 받고자 하는 학생 수
    int i, input;
    int *score; // 학생 들의 수학점수 변수
    int sum = 0; // 총점

    printf("학생의 수는? : ");
    scanf("%d", &student);

    score = (int *)malloc(student*sizeof(int));

    for(i=0;i<student;i++)
    {
        printf("학생 %d 의 점수 : ", i);
        scanf("%d", &input);

        score[i] = input;
    }

    for(i=0;i<student;i++)
    {
        sum += score[i];
    }

    printf("전체 학생 평균 점수 : %d \n", sum/student);
    free(score);
    return 0;

}
```


성공적으로 컴파일 하였다면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F16365A014C57925EC450CA)

와 같이 나옵니다.

```cpp
    score = (int *)malloc(student*sizeof(int));
```


먼저 위 부분을 통해 원소의 개수가 `student` 인 `int` 형 배열을 생성하였죠. 따라서 우리는 `score` 을 `int score[student]` 로 한 것 마냥 사용할 수 있게 됩니다.

```cpp
    for(i=0;i<student;i++)
    {
        printf("학생 %d 의 점수 : ", i);
        scanf("%d", &input);

        score[i] = input;
    }

    for(i=0;i<student;i++)
    {
        sum += score[i];
    }
```


따라서 위와 같이 `score` 에 원소를 입력 받고 그 원소들을 모두 더해 평균을 구하게 됩니다. 어때요. 간단하지요.



###  2 차원 배열의 동적 할당


그렇다면 좀더 높은 난이도의 문제에 도전해봅시다. 2 차원 배열을 동적으로 할당할 수 있을까요? 물론 가능합니다. 여러분은 지금 머리속으로 마구 어떻게 할지 생각하고 있으실 텐데 의외로 간단합니다. 바로 포인터 배열을 이용하면 됩니다.

포인터 배열이라 함은 이전에도 이야기 했었지만 배열의 각 원소들이 모두 포인터 인 것이지요. 따라서, 각 원소들이 다른 일차원 배열들을 가리킬 수 있습니다. 따라서, 이 배열은 2  차원 배열이 되겠지요. 따라서 우리가 해야할 일은 먼저 포인터 배열을 동적으로 할당한 뒤에 다시 포인터 배열의 각각의 원소들이 가리키는 일차원 배열을 다시 동적으로 할당해 주면 됩니다.

그럼 이를 실행에 옮기도록 하겠습니다.

```cpp
/* 2 차원 배열의 동적 할당 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int x,y;
    int **arr; // 우리는 arr[x][y] 를 만들 것이다.


    printf("arr[x][y] 를 만들 것입니다.\n");
    scanf("%d %d", &x, &y);

    arr = (int **)malloc(sizeof(int *) * x);
    // int* 형의 원소를 x 개 가지는 1 차원 배열 생성

    for(i=0;i<x;i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * y);
    }

    printf("생성 완료! \n");

    for(i=0;i<x;i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;

}
```


성공적으로 컴파일 했다면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F1901341B4C5797E91E51F1)

흠. 일단 잘 생성은 된 것 같기는 한데, 한 번 차근 차근 소스를 따라가 봅시다.


```cpp
    int **arr; // 우리는 arr[x][y] 를 만들 것이다.
```


일단 `int **arr` 부터 봅시다. 만일 `int` array[3]; 이란 배열을 만들었다면 `array` 의 형은 무엇일까요. 네 맞습니다. `int *` 입니다. 그렇다면 `int *` arr[10]; 이란 배열을 만들었다면 `arr` 의 형은? 네. `int **arr` 이죠. 따라서 우리는 `int` **arr; 과 같이 선언하였습니다.

```cpp
    arr = (int **)malloc(sizeof(int *) * x);
```


따라서 위와 같이 `int *` 형 배열을 동적 할당 할 수 있었습니다. 위 과정을 거치게 되면 `arr` 은 다음과 같은 모습일 것입니다.

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F121B36104C57A23F6C4DB6)

자. 그럼 `arr` 배열의 각각의 원소들은 `int *` 형 이므로 다른 `int` 배열을 가리키기를 갈망하고 있을 것입니다. 우리는 그 욕구를 해소 시켜 주어야 겠죠. 따라서 각각의 원소들에 대해 원하는 메모리 공간을 짝지어 줍시다.

```cpp
    for(i=0;i<x;i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * y);
    }
```


각각의 원소들에 대해 메모리 공간을 할당하고 있습니다. `arr[i]` 는 `malloc` 이 정의한 또다른 공간을 가리키겠네요.

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F161D45184C57A55A450594)

따라서 `arr` 의 하나의 원소가 크기가 `y` 인 배열을 가리키고 있는데 `arr` 의 원소가 `x` 개 이므로 전체적으로 보았을 때 총 `x * y` 배열을 가지는 셈입니다. 하지만 이렇게 만들어진 배열은 정확히 말해 2 차원 배열이라 말하기는 힘듧니다. 왜냐하면 배열은 모름지기 메모리에 연속적으로 있어야 하기 때문이죠. 예를 들어 이전 강의의 사진을 잠깐 가져오면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F1108E70B4C57A770849D95)
와 같이 말이지요. 하지만 우리가 만든 배열은 `arr` 의 원소들이 가리키는 메모리 공간이 연달아 존재한다고 보장할 수 없습니다. 또한 한 가지 재미있는점은 우리가 만든 '2 차원 배열 처럼 생긴' 포인터 배열은 2 차원 배열과는 달리 함수의 인자로 손쉽게 넘길 수 있습니다. 예를 들면

```cpp
int array(int **array);
```

처럼 말이지요. array(arr); 을 하게 되면 우리가 만든 배열을 함수에 넘길 수 있게 됩니다. 이게 가능한 이유는 사실 우리가 만든 배열은 1 차원 배열들이지 2 차원 배열이 아니기 때문입니다. `arr` 은 단순히 `int *` 형 원소들을 가지는 1 차원 배열 이지요. 1 차원 배열을 함수의 인자로 넘겨줄 때 에는 크기를 써 주지 않아도 되지 않았습니까. 사실 `main` 함수의 인자로 전달되는 argv 역시 이와 같은 성격을 띕니다.

그렇다고 해서 2 차원 배열의 성질을 잃어버리는 것은 아닙니다. 이 배열도 2 차원 배열 처럼 `arr[3][4]` 과 같이 원소에 접근할 수 있습니다 (그렇기 때문에 우리가 만든 이 배열을 2 차원 배열이라 부르는 것입니다). 왜냐하면 `arr[3][4]` 는 `*(*(arr + 3)+4)` 로 해석되는데, `*(arr + 3)` 을 통해 `arr` 의 세번째 원소에 접근하게 되고 `*(arr + 3)` 은 자신이 가리키는 `int` 형 배열의 주소값읠 의미하므로 `+ 4` 를 하면 `int` 형 배열의 5 번째 원소에 접근하는 것과 같습니다.

아무튼 이와 같은 방법으로 2 차원 배열 (사실은 다르지만 이렇게 부르겠습니다) 를 생성하였습니다. 우리가 이 배열을 힙에 할당하였으면 사용이 끝났으면 역시 되돌려 주어야 하겠죠. 해제하는 순서는 할당하는 순서와 정 반대로 하면 됩니다. 즉, `arr[i]` 들이 가리키고 있던 `int` 배열들을 해제한 후, `arr` 을 해제하면 되겠지요. 만일 `arr` 을 먼저 해제하면 `arr[i]` 들이 메모리 상에서 사라지게 되므로 `arr[i]` 들이 가리키고 있던 `int` 배열들을 해제할 수 없게 되므로 오류가 나게 됩니다.

```cpp
/* 2 차원 배열 동적 할당의 활용 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i,j, input, sum = 0;
    int subject, students;
    int **arr;
    // 우리는 arr[subject][students] 배열을 만들 것이다.

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생의 수 : ");
    scanf("%d", &students);

    arr =(int **)malloc(sizeof(int *) * subject);

    for(i=0;i<subject;i++)
    {
        arr[i]=(int *)malloc(sizeof(int) * students);
    }

    for(i=0;i<subject;i++)
    {
        printf("과목 %d 점수 --------- \n", i);

        for(j=0;j<students;j++)
        {
            printf("학생 %d 점수 입력 : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    for(i=0;i<subject;i++)
    {
        sum = 0;
        for(j=0;j<students;j++)
        {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum/students);
    }

    for(i=0;i<subject;i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}
```


성공적으로 컴파일 하였다면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile3.uf.tistory.com%2Fimage%2F134E8C274C57AD69885E45)

와 같이 나옵니다. 대성공이군요 `~`

```cpp
    int **arr;
```


위 예제에서 우리는 과목별 학생의 점수를 보관하기 위해 이차원 배열을 사용하였습니다. 즉 `arr[subject][students]` 를 만든 것이지요. 이를 위해

```cpp
    arr =(int **)malloc(sizeof(int *) * subject);

    for(i=0;i<subject;i++)
    {
        arr[i]=(int *)malloc(sizeof(int) * students);
    }

```

를 통해 `arr[subject][students]` 를 만들 수 있었습니다. 따라서 이제 과목별 학생의 점수를

```cpp
    for(i=0;i<subject;i++)
    {
        printf("과목 %d 점수 --------- \n", i);

        for(j=0;j<students;j++)
        {
            printf("학생 %d 점수 입력 : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }
```


로 얻었습니다. `arr` 은 사실 2 차원 배열은 아니지만 2 차원 배열과 똑같이 행동하므로 `arr[i][j]` 와 같은 문장도 맞게 되지요. `arr[i][j]` 를 `i` 행 `j` 열에 위치한 값이라 생각해도 무방합니다.

```cpp
    for(i=0;i<subject;i++)
    {
        sum = 0;
        for(j=0;j<students;j++)
        {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum/students);
    }
```


이제 값을 모두 입력받았다면 각 과목별 평균을 내면 되는데 이는 간단히 위와 같은 `for` 문으로 해결할 수 있었습니다.

```cpp
    for(i=0;i<subject;i++)
    {
        free(arr[i]);
    }

    free(arr);

```

마지막으로 할당 받은 메모리의 사용이 끝났기 때문에 해제해야 하는데 이는 이전에 설명했던 예제와 동일하게 하면 됩니다.

```cpp
/* 할당한 (2 차원 배열 처럼 생긴) 배열 전달하기 */
#include <stdio.h>
#include <stdlib.h>

void get_average(int **arr, int numStudent, int numSubject);

int main(int argc, char **argv)
{
    int i,j, input, sum = 0;
    int subject, students;
    int **arr;
    // 우리는 arr[subject][students] 배열을 만들 것이다.

    printf("과목 수 : ");
    scanf("%d", &subject);

    printf("학생의 수 : ");
    scanf("%d", &students);

    arr =(int **)malloc(sizeof(int *) * subject);

    for(i=0;i<subject;i++)
    {
        arr[i]=(int *)malloc(sizeof(int) * students);
    }

    for(i=0;i<subject;i++)
    {
        printf("과목 %d 점수 --------- \n", i);

        for(j=0;j<students;j++)
        {
            printf("학생 %d 점수 입력 : ", j);
            scanf("%d", &input);

            arr[i][j] = input;
        }
    }

    get_average(arr, students, subject);

    for(i=0;i<subject;i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
void get_average(int **arr, int numStudent, int numSubject)
{
    int i,j, sum;

    for(i=0;i<numSubject;i++)
    {
        sum = 0;
        for(j=0;j<numStudent;j++)
        {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum/numStudent);
    }
}
```


성공적으로 컴파일 했다면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F20023A1D4C57B2DE9350C5)

와 같이 나옵니다. 다른 부분은 모두 똑같으므로 함수만 살펴봅시다.

```cpp
void get_average(int **arr, int numStudent, int numSubject)
```


일단 `void` 형이고 `int **arr` 와 `numStudent, numSubject` 를 인자로 받고 있습니다. 앞에서 설명 했지만 `arr` 은 2 차원 배열 처럼 행동함에도 불구하고 사실은 단순히 원소가 `int *` 형인 배열이기 때문에 (1 차원 배열의 경우 단순히 배열의 타입에 * 만 붙이면 된다는 사실은 다 알고계시죠?)  위와 같이 `int **arr` 로 기존의 2 차원 배열 처럼 열의 개수에 대한 정보가 없어도 됩니다. (2 차원 배열의 경우 int (*arr)[3]과 같이 열에 관한 정보가 있어야 함) 물론 함수 내부에서 총 학생의 명수와 총 과목의 개수를 알아야 하므로 위와 같이 `numStudent` 와 `numSubject` 를 넣어주었지만요.자. 그럼 동적 할당 까지 배웠군요. 이제 여러분은 C 언어의 대부분을 배웠다고 해도 무방합니다만, 아직 몇 가지 재미있는 것들이 남아있으니 다음 강좌가 나올 때 까지 생각해 볼 문제나 풀어보세요. ㅎ생각해보기`1)` 위 성적 프로그램을 개량하여 학생별 평균을 내어 학생의 등수를 출력하는 프로그램을 만들어보세요 (난이도 : 下)`2)` 동적으로 할당된 배열의 크기를 다시 바꾸는 프로그램을 만들어보세요.즉 `p` 가 이미 원소가 10 인 동적으로 할당된 배열을 가리키고 있었는데 예상치 못하게 원소 5 개를 더 추가하려면 어떻게 해야 할까요. (난이도 : 中)


```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C 언어 - <20. 동동동 메모리 동적할당(Dynamic Memory Allocation)>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요


 [다음 강좌 보러가기](http://itguru.tistory.com/notice/15)
```




