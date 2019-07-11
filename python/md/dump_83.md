----------------
title : 씹어먹는 C 언어 - <17. 변수의 생존 조건 및 데이터 세그먼트의 구조>
cat_title : 17. 변수의 생존 조건 및 데이터 세그먼트의 구조
next_page : 87
publish_date : 2010-06-19
chapter : 변수의 생존 조건과 데이터 세그먼트의 구조
--------------

이번 강좌에서는

* 지역 변수(local variable), 전역 변수(global variable), 정적 변수(static variable) 에 대해 알아본다.

* 데이터 세그먼트의 구조에 대해 알아본다.

![씹어먹는 C 언어](/img/ChewingClogo.png)

안녕하세요 여러분.. 드디어 17 번째 강좌 입니다. 총 20 에서 25 강 까지로 예상하고 있는데 이제 앞으로 얼마 남지 않았군요. 구조체까지 완전히 배웠으니 이제 여러분은 정말로 만들어 볼 것이 많을 것 같네요. 이번 강좌는 단순한 내용이므로 딱히 아주 길지는 않을 것 입니다. 아마도 여태까지 배운 개념들을 환기시키는 정도로 사용될 것 같네요.


###  지역 변수


아래의 간단한 소스를 살펴 봅시다.

```cpp-formatted
/* 오류 */
#include <stdio.h>
int function() {
  int a = 3;
  return 0;
}
int main() {
  int a;
  function();
  printf("%d", a);

  return 0;
}
```

컴파일 하였다면

![""](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F1145B3014C1E1E1454D7DA)

와 같은 상콤한 오류를 만나게 됩니다.

이러한 오류는 왜 발생하였을 까요? 아마 제 강좌를 열심히 들었던 분들은 이미 다 알고 계시겠지만,,

그 이유는 바로 `function` 함수의 변수 `a` 와 `main` 함수의 변수 `a` 는 다르기 때문 입니다. 이렇게 각 함수의 내부에서 정의된 변수들을지역 변수 (local variable)이라고 하는데 이 변수들은 메모리 상의 '스택' 에 저장되어 있습니다. 이에 대한 설명은 나중에 하겠습니다. 아무튼 이러한 지역 변수들은 같은 함수 내에서 선언 된 것 끼리 말고는 서로에 접근할 수 없습니다. 물론 C 에서는 이를 해결하기 위해 포인터라는 훌륭한 것이 있지만 아무튼 다른 함수에 선언된 지역 변수 끼리는 서로의 값에 접근을 할 수 없습니다.

또한 이 지역 변수들은 자신이 속한 함수가 종료 될 때 (즉 `return` 을 수행할 때) 파괴 됩니다. 다시말해 메모리 상에서 사라지게 되는 것입니다. 따라서, `main` 함수에서 `function` 을 실행 했다면 처음에 메모리에 3 이란 값을 볼 수 있겠지만 `function` 이 종료된 직후 메모리 에서는 3 이 사라지게 됩니다. 즉 `function` 의 지역변수 `a` 가 사라지게 되는 것이죠.

마찬가지로 `main` 함수의 지역 변수 `a` 역시 `main` 함수가 종료하면 파괴 됩니다.

지역 변수를 쉽게 비유하자면 '하나의 국가(함수) 에 사는 국민(지역 변수)' 라고 생각하면 됩니다. 즉 같은 국가 내에서는 서로 같은 언어로 자유롭게 대화할 수 있지만 우리가 외국인만 만나면 한없이 작아지는 것 처럼 다른 국가 사람들과는 이야기 하기가 힘들다는 것과 비슷합니다.

참고로 배열은 지역 변수 일까요? 맞습니다. 배열은 '지역 변수의 모음' 이라면 보면 적당합니다. 아무튼 배열 역시 지역 변수고 스택에 저장됩니다.


###  전역 변수



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

이번에는 어느 함수에도 속하지 않는 변수가 등장하였습니다. 이와 같이 함수 '외부' 에 선언되어 있는 변수를 바로 **전역 변수(global variable)** 이라 합니다. 얘는 정말 이름대로 글로벌 한 녀석인데 아까 지역 변수가 자신이 정의되어 있는 함수 내부에서는 접근할 수 있었더라면 이 변수의 경우 모든 함수에서 접근할 수 있습니다. 마치 몇 개 국어를 자유롭게 구사하는 사람 처럼 말이죠.

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

위와 같이 1 이 출력됨을 알 수 있습니다. 만일 `global` 이 지역 변수 같았더라면 일단 컴파일 시에 `global` 변수가 초기화 되지 않고 사용되었습니다 라는 경고를 보았을 테고, 설사 실행했다고 해도 맨 위에서 보았던 상콤한 오류 창을 보았을 텐데요.

하지만 컴파일러는 전역 변수의 정의와 동시에 0 으로 초기화 해버립니다.

따라서 위와 같이 1 이 출력되었죠.

```cpp-formatted
/* 함수 호출 횟수 세기*/
#include <stdio.h>

int How_Many_Times_This_Function_Called = 0;
int function() {
  How_Many_Times_This_Function_Called++;
  printf("called : %d \n", How_Many_Times_This_Function_Called);

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

위 프로그램에서는 `function` 이라는 변수가 몇 번 호출 되는지 알려줍니다. `How_Many_Times_This_Function_Called` 라는 변수는 `function` 함수를 몇 번 이나 호출했는데 카운트 해줍니다. 만일 `How_Many_Times_This_Function_Called` 를 `function` 함수의 지역 변수로 만들었다면 함수 종료 후 파괴 되므로 정보를 보관할 수 없었겠죠.

```cpp-formatted
/* 전역 변수의 문제점 */
#include <stdio.h>

int How_Many_Times_This_Function_Called = 0;
int How_Many_Times_This_Function_Called2 = 0;
int function() {
  How_Many_Times_This_Function_Called++;
  printf("function called : %d \n", How_Many_Times_This_Function_Called);

  return 0;
}
int function2() {
  How_Many_Times_This_Function_Called2++;
  printf("function 2 called : %d \n", How_Many_Times_This_Function_Called2);

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

이번에는 또 다른 함수 `function2` 의 호출 회수도 세는 변수를 지정하였습니다. 전역 변수는 모든 함수에서 접근할 수 있기 때문에 이를 위해 다른 변수 `How_Many_Times_This_Function_Called2` 를 도입하게 되었습니다. 그렇다면 이렇게 10 개의 함수에 대해 각각 호출 회수를 세기 위해서는 아마도 10 개의 전역 변수가 필요하게 됩니다.

이는 심각한 문제가 아닐 수 있습니다. 전역 변수는 모든 함수에서 접근할 수 있기 때문에 전역 변수에 조금 이라도 문제가 생기면 전체 함수에 영향을 미치게 됩니다. 따라서 전역 변수는 매우 조심 스럽게 사용해야 하는데 이렇게 '위험한' 전역 변수를 수십개 선언 하다 보면 필연적으로 문제가 생기게 마련입니다.

```lec-warning
많은 수의 전역 변수를 선언하지 않는 것을 권장합니다.
```

아마도 여러분은 이쯤 부터 *그럼, 함수가 종료되어도 값이 변경되지 않는 지역변수 는 없을까?* 라는 생각을 하게 됩니다. 다행이도 있습니다. 물론 지역 변수는 아니지요. 이를 **정적 변수 (static variable)** 이라 합니다.



###  정적 변수


```cpp-formatted
/* 정적 변수의 활용 */
#include <stdio.h>

int function() {
  static int How_Many_Times_This_Function_Called = 0;

  How_Many_Times_This_Function_Called++;
  printf("function called : %d \n", How_Many_Times_This_Function_Called);

  return 0;
}
int function2() {
  static int How_Many_Times_This_Function_Called = 0;

  How_Many_Times_This_Function_Called++;
  printf("function 2 called : %d \n", How_Many_Times_This_Function_Called);

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

와 같이 동일하게 작동함을 알 수 있습니다. 정적 변수는 보통 아래와 같이 정의합니다.

```info
static (변수의 타입) (변수의 이름);
```

예를 들면

```cpp-formatted
static struct HUMAN adam;
static char c;
```

와 같이 말이죠.

```cpp-formatted
static int How_Many_Times_This_Function_Called = 0;
```

먼저 `function` 함수 부터 살펴 봅시다. 위와 같이 정적 변수 `How_Many_Times_This_Function_Called` 를 정의하였습니다. 이는 지역 변수와 하는 짓이 비슷해서 다른 어떠한 함수에서도 `How_Many_Times_This_Function_Called` 에 접근할 수 없습니다. 당연하게도 `function2` 에 정의된 `How_Many_Times_This_Function_Called` 와 이름은 같지만 메모리 상에 다른 곳에 존재하는 완전히 다른 것입니다.

정적 변수의 경우 함수가 처음 실행 될 때 정의 됩니다. 즉, 위 문장을 함수를 실행할 때 매번 적용되서 언제나 `How_Many_Times_This_Function_Called` 의 값이 0 이 되는 것이 아닙니다.

정적 변수의 특징은 앞에서도 말했듯이 함수가 종료 되어도 그 값을 계속 유지하고 있다는 점입니다. 따라서

```cpp-formatted
How_Many_Times_This_Function_Called++;
```

를 통해 함수의 호출 횟수를 셀 수 있습니다. 그렇다면 `main` 함수 에서 `How_Many_Times_This_Function_Called` 의 값을 볼 수 있는 방법이 있을까요? 답은 '없습니다' 입니다. 맨 위의 예제에서 지역 변수 `a` 값을 참조 할 수 없었던 것 처럼 `How_Many_Times_This_Function_Called` 는 '함수가 종료 될 때 파괴되지 않는다' 라는 점 빼고는 지역 변수와 하는 짓이 동일합니다.

다만 정적 변수의 경우 전역 변수 처럼 '데이터 영역' 에 저장되고 프로그램이 종료될 때 파괴됩니다. 또한 전역 변수 처럼 정적 변수도 정의시 특별한 값을 지정해 주지 않는 한 0 으로 자동 초기화 됩니다.



###  데이터 세그먼트의 구조

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


각 변수들의 주소값을 살펴 보면서 과연 메모리에 정말로 그렇게 배치 되었는지 살펴 봅시다. 일단 저의 결과는 여러분 컴퓨터의 결과와 당연히 차이가 나게 됩니다. 왜냐하면 프로그램 실행 시 그 프로그램이 RAM 어디에 위치하게 될 지는 아무도 모르기 때문이죠. 하지만 그 주소값들만 비교 해보도록 합시다.


가장 먼저 읽기 전용(Read Only) 데이터인 `str` 을 봅시다. `str` 에는 “Hello, Baby” 라는 리터럴의 주소값이 들어가 있습니다. 따라서, `str` 의 값을 출력했다면 Read Only 데이터의 위치를 대략 알 수 있겠지요. 여기서는 `0x1175a28` 로 나옵니다. 예상 대로 출력된 주소값들 중 가장 작게 나옵니다. 왜냐하면 `RO data` 는 데이터 세그먼트 맨 아래에 위치해 있기 때문이죠.



두 번째로 전역 변수인 `global` 의 주소값을 살펴보면 `str` 보다는 살짝 크지만 다른 것들 보다는 많이 작다는 것을 알 수 있습니다. 이는 `global` 이 전역 변수로 데이터 영역에 위치해 있기 때문이죠. 세 번째로 `i` 를 보자면 지역 변수 이기 때문에 `stack` 에 존재하고 있습니다. `stack` 의 경우 지역 변수를 추가할 수록 메모리 주소가 작아지는 방향으로 추가가 되므로 `i` 보다 나중에 추가 된 `arr` 의 주소값이 더 작습니다. 이들이 데이터 세그먼트에 배치된 모습을 그림으로 그려 본다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F114F551E4C1E3404A1F0AD)




와 같이 됨을 알 수 있습니다. 어때요? 간단 하지요?


### 생각해보기

#### 문제 1

스택에 대한 폭넓은 이해를 위해 아래 글을 보는 것을 추천합니다. (동적 할당 부분 전까지만)
 [여기](http://blog.naver.com/speciallive?Redirect=Log&logNo=98372211)

##@ chewing-c-end