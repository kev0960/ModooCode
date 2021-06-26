----------------
title : 씹어먹는 C 언어 - <17. 변수의 생존 조건 및 데이터 세그먼트의 구조>
cat_title : 17. 변수의 생존 조건 및 데이터 세그먼트의 구조
next_page : 87
publish_date : 2010-06-19
chapter : 변수의 생존 조건과 데이터 세그먼트의 구조
path : /C
--------------

이번 강좌에서는

* 지역 변수(local variable), 전역 변수(global variable), 정적 변수(static variable) 에 대해 알아본다.

* 데이터 세그먼트의 구조에 대해 알아본다.

![씹어먹는 C 언어](/img/ChewingClogo.png)

안녕하세요 여러분. 드디어 17 번째 강좌 입니다. 총 20 에서 25 강 까지로 예상하고 있는데 이제 앞으로 얼마 남지 않았군요. 구조체까지 완전히 배웠으니 이제 여러분은 정말로 만들어 볼 것이 많을 것 같네요. 이번 강좌는 단순한 내용이므로 딱히 아주 길지는 않을 것 입니다. 아마도 여태까지 배운 개념들을 환기시키는 정도로 사용될 것 같네요.


### 변수의 접근 범위 

아래의 간단한 소스를 살펴 봅시다.

```cpp-formatted
#include <stdio.h>

void function() {
  int a = 2;
}

int main() {
  int a = 3;
  function();

  printf("a = %d \n", a);
}
```

컴파일 하였다면

```exec
a = 3 
```

와 같이 나옵니다. 

```cpp
void function() {
  int a = 2;
}
```

분명히 `function` 에서 `a` 에 2 를 대입했는데에도 `main` 함수에서는 이전의 `a` 의 값인 3 이 나왔습니다. 이런 결과가 나온 이유는 어떠한 함수 내에서 일반적으로 정의된 변수는 해당 함수 내에서만 접근할 수 있기 때문입니다. 

이렇게 해당 **지역** 에서만 접근할 수 있다고 해서 위와 같은 변수들을 지역 변수라고 합니다. 즉 `main` 함수 안의 `a` 와 `function` 안에 `a` 는 컴파일러가 보기에 다른 변수로 취급됩니다.

```cpp
#include <stdio.h>

int main() {
  int a = 3;
  {
    int a = 4;
    printf("a = %d \n", a);
  }

  printf("a = %d \n", a);
}
```

참고로 중괄호 `{}` 는 하나의 **지역** 으로 취급되는데, 해당 지역에서 정의된 변수는 바깥 지역에서 정의된 같은 이름의 변수를 가리게 됩니다. 예를 들어서 4 로 초기화된 `a` 는 바깥의 3 으로 초기화 된 `a` 를 완전히 가리게 됩니다.

따라서 안의 `printf` 에서는 4 가 출력되고, 바깥의 `printf` 에는 3 이 출력되겠지요. 위 두 `a` 는 아예 다른 변수로 취급됩니다. 또한 바깥 지역에서 안쪽 지역에 정의된 변수를 사용할 수 없습니다. 예를 들어서

```cpp
#include <stdio.h>

int main() {
  {
    int b = 4;
  }

  printf("b = %d \n", a);
}
```

컴파일 하였다면 

```compiler-warning
test2.c: In function ‘main’:
test2.c:8:23: error: ‘a’ undeclared (first use in this function)
   printf("b = %d \n", a);
                       ^
test2.c:8:23: note: each undeclared identifier is reported only once for each function it appears in
```

위와 같은 컴파일 오류가 발생합니다. 왜냐하면 `b` 는 `printf` 가 살고 있는 지역 보다 안쪽에서 정의된 녀석이므로 바깥에서 볼 수 없기 때문이지요!

###  전역 변수

그렇다면 어떠한 지역에도 속하지 않는 변수를 정의할 수 있을까요? 물론 가능합니다! 그냥 맨 바깥에 정의하면 됩니다.

```cpp-formatted
/* 전역 변수 */
#include <stdio.h>

int global = 0;

int function() {
  global++;
  return 0;
}
int main() {
  global = 10;
  function();
  printf("%d \n", global);
  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
11
```

어떠한 지역에도 속해있지 않은 변수를 **전역 변수(global variable)** 라 합니다. 전역 변수는 위의 지역 변수와는 달리 코드 어느 곳에서도 접근할 수 있습니다.

먼저 `main` 에서

```cpp-formatted
global = 10;
function();
```

`global` 의 값을 10 으로 한 후 `function` 을 호출했습니다. `function` 에서는 `global` 의 값을 1 더하는데 따라서 다시 `main` 에서 `global` 의 값을 출력 했을 때 에는 11 이 됩니다.

지역 변수의 경우 함수가 종료 될 때 파괴 되었는데, 전역 변수의 경우 프로그램이 시작 할 때 만들어 졌다가 프로그램이 종료 될 때 파괴 됩니다. 전역 변수는 지역 변수와는 달리 메모리의 **데이터 영역(Data segment)**에 할당 됩니다.

한 가지 재미있는 것은 모든 전역 변수들은 정의 시 자동으로 0 으로 초기화 된다는 것입니다.

```cpp-formatted
/* 전역 변수의 초기화 ? */
#include <stdio.h>

int global;
int function() {
  global++;
  return 0;
}
int main() {
  function();
  printf("%d \n", global);
  return 0;
}
```

성공적으로 컴파일 했다면

```exec
1 
```

위와 같이 1 이 출력됨을 알 수 있습니다. 만일 `global` 이 지역 변수 같았더라면 일단 컴파일 시에 `global` 변수가 초기화 되지 않고 사용되었습니다 라는 경고를 냈을 것입니다. 하지만 컴파일러는 전역 변수는 따로 초기화를 하지 않는다면 디폴트로 0 으로 초기화 해버립니다.

따라서 위와 같이 1 이 출력되었죠.

```cpp-formatted
/* 함수 호출 횟수 세기*/
#include <stdio.h>

int how_many_called = 0;
int function() {
  how_many_called++;
  printf("called : %d \n", how_many_called);

  return 0;
}
int main() {
  function();
  function();
  function();
  function();
  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
called : 1 
called : 2 
called : 3 
called : 4 
```

위 프로그램에서는 `function` 이라는 변수가 몇 번 호출 되는지 알려줍니다. `how_many_called` 라는 변수는 `function` 함수를 몇 번 이나 호출했는데 카운트 해줍니다. 만일 `how_many_called` 를 `function` 함수의 지역 변수로 만들었다면 함수 종료 후 파괴 되므로 정보를 보관할 수 없겠지요.

```cpp-formatted
/* 전역 변수의 문제점 */
#include <stdio.h>

int how_many_called = 0;
int how_many_called2 = 0;
int function() {
  how_many_called++;
  printf("function called : %d \n", how_many_called);

  return 0;
}
int function2() {
  how_many_called2++;
  printf("function 2 called : %d \n", how_many_called2);

  return 0;
}
int main() {
  function();
  function2();
  function();
  function2();
  function2();
  function2();
  function();
  function();
  function2();
  return 0;
}
```


성공적으로 컴파일 하였다면

```exec
function called : 1 
function 2 called : 1 
function called : 2 
function 2 called : 2 
function 2 called : 3 
function 2 called : 4 
function called : 3 
function called : 4 
function 2 called : 5 
```

이번에는 또 다른 함수 `function2` 의 호출 회수도 세는 변수를 지정하였습니다. 전역 변수는 모든 함수에서 접근할 수 있기 때문에 이를 위해 다른 변수 `how_many_called2` 를 도입하게 되었습니다. 그렇다면 이렇게 10 개의 함수에 대해 각각 호출 회수를 세기 위해서는 아마도 10 개의 전역 변수가 필요하게 됩니다.

이는 심각한 문제가 아닐 수 있습니다. 전역 변수는 모든 함수에서 접근할 수 있기 때문에 전역 변수를 사용할 때에는 매우 주의를 기울여라 합니다. 심지어 위처럼 전역 변수를 수십개 선언 하다 보면 필연적으로 문제가 생기게 마련입니다.

```lec-warning
많은 수의 전역 변수를 선언하지 않는 것을 권장합니다.
```

### 변수의 생존 기간

앞서 변수가 어떤 범위에서 접근 가능한지 이야기 하였습니다. 그렇다면 이번에는 정의한 변수가 얼마나 살아 있는지 이야기할 차례 입니다.

**일반적으로 정의된 변수들은 자신이 정의된 지역을 빠져나갈 때 파괴 됩니다.** 이 말이 무슨 말이냐면, 자신이 정의된 위치를 포함하고 있는 `{}` 를 벗어날 때 해당 변수가 사라지게 된다는 뜻이지요.

예를 들어서 아래 코드를 살펴봅시다.

```cpp
#include <stdio.h>

int* function() {
  int a = 2;
  return &a;
}

int main() {
  int *pa = function();
  printf("%d \n", *pa);
}
```

성공적으로 컴파일 후에 실행하였다면

```exec
[1]    30588 segmentation fault (core dumped)  ./test
```

위와 같이 오류가 발생하게 됩니다. 사실 컴파일 시에도 경고 메세지가 나오는데;

```compiler-warning
test.c: In function ‘function’:
test.c:5:10: warning: function returns address of local variable [-Wreturn-local-addr]
   return &a;
          ^~
```

위 처럼 함수가 지역 변수의 주소값을 리턴한다고 경고하고 있습니다.

그렇다면 위 코드가 왜 문제인지 살펴보겠습니다.

```cpp
int* function() {
  int a = 2;
  return &a;
}
```

일단 `a` 라는 변수는 **지역 변수** 입니다. 따라서 `a` 가 정의된 지역인 `function` 을 빠져나가면 `a` 는 소멸됩니다. 다시 말해 `a` 를 사용할 수 없다는 뜻입니다. 

하지만 아래 처럼 `a` 의 주소값을 리턴해서 `function` 외부에서 `a` 를 사용하려 그런다면 어떨까요?

```cpp
  int *pa = function();
  printf("%d \n", *pa);
```

이 경우 pa 는 이미 파괴된 변수를 가리키고 있기 때문에 문제가 됩니다. 따라서 위 코드는 프로그램 실행시에 오류를 발생하게 됩니다.

아마도 여러분은 이쯤 부터 **그럼, 지역을 빠져나가도 파괴되지 않는 변수는 없을까** 라는 생각을 하시겠죠? 물론 있습니다. 이를 **정적 변수 (static variable)** 이라 합니다.


###  정적 변수

```cpp
#include <stdio.h>

int* function() {
  static int a = 2;
  return &a;
}

int main() {
  int *pa = function();
  printf("%d \n", *pa);
}
```

성공적으로 컴파일 하였다면

```exec
2
```

와 같이 잘 나옵니다.

```cpp
  static int a = 2;
```

정적 변수를 선언하기 위해서는 그냥 위와 같이 일반적인 변수 선언 앞에 `static` 만 붙여주면 됩니다. 그리고 해당 변수는 자신이 선언된 범위를 벗어나더라도 **절대로** 파괴되지 않습니다.

```cpp
  int *pa = function();
```

따라서 `a` 가 정의된 지역 밖에서 접근하더라도 `a` 는 소멸되지 않았기 때문에 2 라는 값이 잘 출력되는 것입니다. 

그렇다면 한 가지 궁금한 점은 `function` 을 여러번 호출하면 `a` 가 여러번 2 로 초기화 되냐고 물을 수 있습니다. 하지만 `a` 는 딱 한 번만 초기화 됩니다. 다시 말해 `static int a = 2` 라는 문장은 **딱 한 번** 실행 되며, 더 놀라운 점은 `function` 을 실행하지 않더라도 `a` 라는 정적 변수는 이미 정의되어 있는 상태 입니다.

따라서 이와 같은 정적 변수를 사용하면 아래 처럼 해당 함수가 몇 번 호출되었는지도 쉽게 추적할 수 있습니다. 

```cpp-formatted
/* 정적 변수의 활용 */
#include <stdio.h>

int function() {
  static int how_many_called = 0;

  how_many_called++;
  printf("function called : %d \n", how_many_called);

  return 0;
}
int function2() {
  static int how_many_called = 0;

  how_many_called++;
  printf("function 2 called : %d \n", how_many_called);

  return 0;
}
int main() {
  function();
  function2();
  function();
  function2();
  function2();
  function2();
  function();
  function();
  function2();
  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
function called : 1 
function 2 called : 1 
function called : 2 
function 2 called : 2 
function 2 called : 3 
function 2 called : 4 
function called : 3 
function called : 4 
function 2 called : 5 
```

와 같이 동일하게 작동함을 알 수 있습니다. 

참고로 정적 변수의 경우 전역 변수 처럼 데이터 영역에 저장되고 프로그램이 종료될 때 파괴됩니다. 또한 전역 변수 처럼 정적 변수도 정의시 특별한 값을 지정해 주지 않는 한 0 으로 자동 초기화 됩니다.


###  데이터 세그먼트의 구조

```lec-warning
아래 내용은 일반적인 운영체제에서 실행 파일이 메모리에 로드될 때 상황을 가정한 그림 입니다. C 언어 자체적으로는 **스택** 이나 **힙** 영역을 따로 구분하지 않습니다. 하지만 대부분의 운영체제에서 프로그램을 실행한다면, 아래 그림 처럼 힙과 스택 영역을 구분해서 만들게됩니다.
```

프로그램이 실행 될 때 프로그램은 RAM 에 적재 됩니다. 다시 말해 프로그램의 모든 내용이 RAM 위로 올라오게 된다는 것이지요. 여기서 '프로그램의 모든 내용' 이라 하면 프로그램의 코드와 프로그램의 데이터를 모두 의미 하는 것입니다. 이렇게 RAM 위로 올라오는 프로그램의 내용을 크게 나누어서 **코드 세그먼트(Code Segment)** 와 **데이터 세그먼트(Data Segment)** 로 분류할 수 있습니다.

우리가 중점 적으로 살펴볼 것은 데이터 세그먼트입니다. 일단 아래의 그림을 보면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F140309404D2EF2B93B6CF4)

위와 같이 메모리에 배치 되어 있는 것을 알 수 있습니다.

일단 가장 먼저 주목할 부분은 **읽기 전용(Read-Only) Data** 부분 입니다. 이전에 상수와 리터럴에 대해서 이야기 할 때 등장하였는데 이 부분에 저장되는 데이터들은 값이 절대로 변경될 수 없습니다. 다시 말해 궁극적으로 보호 받는 부분 이죠.

그 다음으로 그 위에 전역 변수와 정적 변수가 거처하는 데이터 영역이 있습니다. 그 위에 바로 **힙(Heap)** 이라는 영역이 있는데 이 부분에 대해서는 나중에 설명하도록 합시다. 힙 맨 위를 보면 **스택(Stack)** 이 있습니다. 스택은 지역 변수가 거처하는 곳입니다. 스택의 특징으로는 지역 변수가 늘어나면 크기가 아래로 증가하다가 지역변수가 파괴되면 다시 스택의 크기는 위로 줄어들게 됩니다. 즉, 스택이 늘어나는 방향은 메모리 주소가 낮아지는 방향(아래 방향) 이라 보시면 됩니다.

```cpp-formatted
/* 메모리의 배치 모습 */

#include <stdio.h>
int global = 3;
int main() {
  int i;
  char *str = "Hello, Baby";
  char arr[20] = "WHATTHEHECK";

  printf("global : %p \n", &global);
  printf("i : %p \n", &i);
  printf("str : %p \n", str);
  printf("arr : %p \n", arr);
}
```

성공적으로 컴파일 했다면


![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F181FA3194C1E30486DBF36)


각 변수들의 주소값을 살펴 보면서 과연 메모리에 정말로 그렇게 배치 되었는지 살펴 봅시다. 일단 저의 결과는 여러분의 컴퓨터의 결과와 당연히 차이가 나게 됩니다. 왜냐하면 프로그램 실행 시 그 프로그램이 RAM 어디에 위치하게 될 지는 아무도 모르기 때문이죠. 하지만 그 주소값들만 비교 해보도록 합시다.


가장 먼저 읽기 전용(Read Only) 데이터인 `str` 을 봅시다. `str` 에는 “Hello, Baby” 라는 리터럴의 주소값이 들어가 있습니다. 따라서, `str` 의 값을 출력했다면 Read Only 데이터의 위치를 대략 알 수 있겠지요. 여기서는 `0x1175a28` 로 나옵니다. 예상 대로 출력된 주소값들 중 가장 작게 나옵니다. 왜냐하면 `RO data` 는 데이터 세그먼트 맨 아래에 위치해 있기 때문이죠.



두 번째로 전역 변수인 `global` 의 주소값을 살펴보면 `str` 보다는 살짝 크지만 다른 것들 보다는 많이 작다는 것을 알 수 있습니다. 이는 `global` 이 전역 변수로 데이터 영역에 위치해 있기 때문이죠. 세 번째로 `i` 를 보자면 지역 변수 이기 때문에 `stack` 에 존재하고 있습니다. `stack` 의 경우 지역 변수를 추가할 수록 메모리 주소가 작아지는 방향으로 추가가 되므로 `i` 보다 나중에 추가 된 `arr` 의 주소값이 더 작습니다. 이들이 데이터 세그먼트에 배치된 모습을 그림으로 그려 본다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F114F551E4C1E3404A1F0AD)




와 같이 됨을 알 수 있습니다. 어때요? 간단 하지요?


### 생각해보기

#### 문제 1

스택에 대한 폭넓은 이해를 위해 아래 글을 보는 것을 추천합니다. (동적 할당 부분 전까지만)
 [여기](http://blog.naver.com/speciallive?Redirect=Log&logNo=98372211)

##@ chewing-c-end