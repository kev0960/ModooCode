----------------
title : 씹어먹는 C++ - <2 - 1. C++ 은 C 친구 - C 와 공통점>
cat_title: 2 - 1. C++ 은 C 친구 - C 와 공통점
next_page : 141
publish_date : 2011-05-15
--------------


이번 강좌에서는

* C++ 과 C 언어와의 동일한 문법 구조들에 대해 살펴본다 C++ 과 C 언어와의 동일한 문법 구조들에 대해 살펴본다.

* 예를 들어 `if - else, while, for, switch` 문 등이다.

* 변수 정의에 대해 알아본다.

![](/img/ChewingCpplogo.png)

안녕하세요 여러분~ Psi 입니다. 저의 C++ 세번째 강좌 이네요. 이번 강좌에는 여러분과 많이 친숙할 듯 한데요, 왜냐하면 C++ 이 C 언어의 여러가지 문법들을 어떻게 사용하는지 살펴볼 것입니다. 사실 C 언어에서 작성된 코드를 그대로 C++ 에 붙여 넣기 해도 큰 문제가 없다고 말해도 과언이 아닌 만큼 C++ 은 C 언어의 문법을 거의 완전하게 포함하고 있습니다 C++ 은 C 언어의 문법을 거의 완전하게 포함하고 있습니다.

```cpp-formatted
// 변수의 정의
#include <iostream>
using namespace std;

int main() {
  int i;
  char c;
  double d;
  float f;

  return 0;
}
```

일단 가장 기초적인 부분으로 변수를 정의하는 것 부터 봅시다. 사실 위 코드를 볼 때 의위 `#include` 와 `using ...` 만 빼면은 C 언어에서 작성한 코드라고 말해도 똑같이 생각할 것입니다. 변수를 정의하는 부분에서 만큼은 C 언어때와 달라진 것이 없습니다. 물론 변수 명 이름 작성 규칙도 바뀐 것이 없지요. 변수명도 C 언어 때와 마찬가지로 알파벳과 `_` 기호, 숫자들를 사용할 수 있고 그 외의 것들은 사용할 수 없습니다. (Visual C++ 2010 에서는 한글 변수명도 사용 가능하지만 바람직한 일이 절대로 아닙니다) 또한 변수 이름의 맨 앞부분에는 숫자가 오면 안되지요.

`Google` 의 C++ 변수 이름 짓기 가이드에 따르면 [여기](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml#General_Naming_Rules)에서 보실 수 있습니다. 다음과 같이 하기를 권장합니다.

먼저 변수의 이름은 변수의 이름만을 딱 보았을 때 무엇을 하는지 확실히 알 수 있어야 합니다.

```cpp-formatted
int number_of_people;  // OK
double interest_rate;  // OK
```

```warning
    int num_of_ppl; // BAD
    double intrst_rt; // BAD
```


맨 위의 두 변수 이름들은 딱 보았을 때 '아, 사람의 인원수이고 아래는 이자율 이구나' 라는 느낌이 확 들지만 아래의 두 변수 이름을 보았을 때에는 그러한 느낌을 받기 힘듭니다. 따라서 변수 이름이 조금 길더라도 확실히 이해할 수 있는 변수 이름을 짓는 것이 매우 중요합니다.

둘째로 변수 이름의 띄어쓰기에 관한 규칙인데, 보통 변수 이름을 지을 때

```cpp-formatted
int number_of_people;  // OK
int NumberOfPeople;    // Ok
```


위 처럼 두 가지 방법을 사용하는데 하나는 이름의 띄어쓰기 부분에 `_` 를 넣는 것이고 다른 하나는 띄어쓰기 부분에 대문자로 구분하는 것인데, 저의 경우 전자의 방법을 선호합니다. 물론 이는 사람 마다 개인차가 있겠지만, 가장 중요한 것은 소스 상에서 위 둘을 같이 사용하는 것을 막는 것인데, 예를 들어서

```warning
    int NumberOf_People; // BAD
```


는 전혀 권장할 것이 못됩니다. 저는 앞으로 제 소스에서 전자의 방법을 취할 것입니다 :)

아무튼 제 C++ 강좌를 보고 계실 여러분들의 실력은 이미 상당한 수준(아마도 C 언어 정도는 다룰 줄 아실 분들) 이실 테니 이러한 내용들도 중간에 짬짬히 이야기 하고 지나갈 것입니다 ㅎㅎ

이렇게 해서 변수의 정의는 C 나 C++ 이 차이가 없다는 것을 보실 수 있으셨을 것입니다. 마찬가지로 배열이나 포인터를 정의하는 방법도 C 나 C++ 이 동일합니다. 물론 포인터의 경우 C 에서 `*` 와 `&` 가 하였던 역할을 C++ 에서도 그대로 물려 받았습니다.

예를 들어 C 에서

```cpp-formatted
int arr[10];
int *parr = arr;

int i;
int *pi = &i;
```


  게 했던 것들을 C++ 에서는 어떻게 할까요? 답은 간단합니다. 똑같이

```cpp-formatted
int arr[10];
int *parr = arr;

int i;
int *pi = &i;
```


 쓰면 됩니다. 쉽지요? 어떠한 것들을 선언하는 방법은 정말로 C++ 이나 C 가 차이가 하나도 없음을 알 수 있습니다.

그렇다면 다른 문법 구조들은 어떻까요. 반복문(`for, while`)이라던지 조건문(`if, else, switch`) 이라던지.. 일단 `for` 부터 살펴보도록 합시다.

```cpp-formatted
// C++ 의 for 문
#include <iostream>
using namespace std;

int main() {
  int i;

  for (i = 0; i < 10; i++) {
    cout << i << endl;
  }
  return 0;
}
```


  성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile30.uf.tistory.com%2Fimage%2F1342C9454D857C7D29DDCF)

와우! 정말로 똑같습니다. C 언어 때와 `for` 문은 달라진 것이 없군요. 그렇다면 C++ 에서 `for` 문을 이용해 1 부터 10 까지 더하는 문장은 어떻게 만들까요.

```cpp-formatted
/* 1 부터 10 까지 합*/
#include <iostream>
using namespace std;

int main() {
  int i, sum = 0;

  for (i = 1; i <= 10; i++) {
    sum += i;
  }

  cout << "합은 : " << sum << endl;
  return 0;
}
```


  성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F1744AB3E4D8581790CB209)

역시 기존의 C 언어 때와 동일합니다.

사실 `for` 문은 C++ 에서도 그 문법이 바뀌지 않았습니다. 그냥 여러분이 기억하시는대로 사용하시면 됩니다. 한 가지 달라진 점이 있다면 변수의 선언이 반드시 최상단에 있어야 되는 것은 아닙니다. 기존의 C 에서는 변수를 정의할 때 언제나 소스 맨 위부분에 선언을 하였습니다. 예를 들어

```cpp-formatted
int i, sum = 0;

for (i = 1; i <= 10; i++) {
  sum += i;
}
```

와 같이 말이지요. 하지만 C++ 에서는 변수를 사용하기 직전 어느 위치에서 든지 변수를 선언할 수 있게 됩니다. 예를 들어서 다음과 같이 해도 상관이 없습니다.

```cpp-formatted
/* 변수는 변수 사용 직전에 선언해도 된다.*/
#include <iostream>
using namespace std;

int main() {
  int sum = 0;

  for (int i = 1; i <= 10; i++) {
    sum += i;
  }

  cout << "합은 : " << sum << endl;
  return 0;
}
```


성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F1744AB3E4D8581790CB209)

로 동일한 결과를 보입니다.
그렇다면 `while` 문은 어떨까요. 역시 동일합니다

```cpp-formatted
/* while 문 이용하기 */
#include <iostream>
using namespace std;

int main() {
  int i = 1, sum = 0;

  while (i <= 10) {
    sum += i;
    i++;
  }

  cout << "합은 : " << sum << endl;
  return 0;
}
```


성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F1744AB3E4D8581790CB209)

와 같이 우리가 기존에 알고 있었던 `while` 문과 동일한 결과를 나타냅니다.

C++ 에서 `if - else` 문 역시 C 와 동일한 문법 구조로 되어 있습니다. 아래의 예제를 볼까요 C++ 에서 `if - else` 문 역시 C 와 동일한 문법 구조로 되어 있습니다. 아래의 예제를 볼까요.

```cpp-formatted
/* 행운의 숫자 맞추기*/
#include <iostream>
using namespace std;

int main() {
  int lucky_number = 3;
  cout << "내 비밀 수를 맞추어 보세요~" << endl;

  int user_input;  // 사용자 입력

  while (1) {
    cout << "입력 : ";
    cin >> user_input;
    if (lucky_number == user_input) {
      cout << "맞추셨습니다~~" << endl;
      break;
    } else {
      cout << "다시 생각해보세요~" << endl;
    }
  }
  return 0;
}
```

  성공적으로 컴파일 했다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F1636CA3F4DCD5438225045)

와 같이 역시 우리가 C 에서 생각했던 대로 동일하게 나옵니다. 위 코드에서 살펴볼 부분은 바로

```cpp-formatted
cout << "입력 : ";
cin >> user_input;
```

입니다. 일단 `cout` 은 앞에서 배웠지만 `<<` 를 이용하여 출력을 시키지요.  그리고, 이미 예상했다 싶이 `cin` 은 사용자로 부터 입력을 받아서 `>>` 를 통해 `user_input` 에 넣습니다. `scanf` 에서는 `&` 를 붙였는데 C++ 에서는 편리하게도 앞에 `&` 연산자를 붙일 필요가 없네요. 심지어, `scanf` 에서는 `int` 형태로 입력받을 지 아니면 `char` 인지에 따라서 `%d` 냐 `%c` 냐로 구분하였는데 여기서는 그냥 변수를 보고 `cin` 이 알아서 처리해 줍니다. 매우 편리하지요

아직까지 여러분은 `cin` 이 뭔지, `cout` 이 뭔지 이게 도대체 함수인건지 변수인건지 구조체 인건지, 기본의 쉬프트 연산자로 사용되었던 `<<` 나 `>>` 는 뭔지 도저히 감이 잡히지 않을 것입니다. 그래도 상관은 없습니다. 일단 사용하세요! 사용하시고 편리하게 될 쯤에는 제 강좌에서 뭔지 배우실 것입니다.


```cpp-formatted
if (lucky_number == user_input) {
  cout << "맞추셨습니다~~" << endl;
  break;
} else {
  cout << "다시 생각해보세요~" << endl;
}
```


C 에서와 마찬가지로 C++ 에서도 `if` 문은 동일하게 사용함을 알 수 있습니다. 그렇다면 `switch` 문은 어떨까요?

```cpp-formatted
// switch 문 이용하기
#include <iostream>

using namespace std;
int main() {
  int user_input;
  cout << "저의 정보를 표시해줍니다" << endl;
  cout << "1. 이름 " << endl;
  cout << "2. 나이 " << endl;
  cout << "3. 성별 " << endl;
  cin >> user_input;

  switch (user_input) {
    case 1:
      cout << "Psi ! " << endl;
      break;

    case 2:
      cout << "99 살" << endl;
      break;

    case 3:
      cout << "남자" << endl;
      break;

    default:
      cout << "궁금한게 없군요~" << endl;
      break;
  }
  return 0;
}
```


  성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F181E9D454DCF3D540FB6F4)


 으로 `switch` 문이 잘 작동하는 것을 보실 수 있습니다.

```cpp-formatted
switch (user_input) {
  case 1:
    cout << "Psi ! " << endl;
    break;

  case 2:
    cout << "99 살" << endl;
    break;

  case 3:
    cout << "남자" << endl;
    break;

  default:
    cout << "궁금한게 없군요~" << endl;
    break;
}
```


위를 보면 기존의 C 에서 사용하였던 `switch` 문과 다를 바 없다는 것을 아실 수 있습니다.그렇습니다. 늘 말해왔듯이 C와 C++ 은 기본적인 문법 구조(조건문; `if, else, switch`, 제어문; `for, whlie, break, continue` ...)는 똑같습니다.

자 그럼 이번 강좌에서는 이것으로 마치도록 하겠습니다:) C 에서 기본적으로 다뤘던 예제들을 C++ 로 바꿔 보는 것도 재밌는 작업 일 것 같습니다.

##@ chewing-cpp-end