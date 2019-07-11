----------------
title : 씹어먹는 C 언어 - <21. 매크로 함수, 인라인 함수>
cat_title : 21. 매크로 함수, 인라인 함수
next_page : 103
publish_date : 2010-11-21
chapter : 매크로 함수, 인라인 함수
--------------

이번 강좌에서는

* 매크로 함수에 대해 배운다

* 인라인 함수에 대해 배운다.


![씹어먹는 C 언어](/img/ChewingClogo.png)


안녕하세요 여러분. 저의 36 번째 강좌가 시작되었습니다. 요즘에 뒤로 갈 수 록 강좌들의 댓글 수가 적어지는 것을 보아 처음에 큰마음 먹고 강좌 보기를 시작하였다가 시간적 여유의 한계나 온라인 상의 한계를 느끼고 포기하신 분들이 많은 것 같은데 과연 누가 여기 까지 성공적으로 달려왔는지 궁금하네요. 전체 강좌의 앞부분은 C 언어 자체를 아는데 주력하였다면 후반으로 갈 수록 C 언어 자체를 이해하기 보다는 C 언어와 친해지는 과정으로 진행이 되고 있습니다.

아무튼. 적어도 제 강좌만 다 이해한다면 C 의 기초 부분은 훌륭하게 다진 프로그래머로 만들어 줄 수 있으니 열심히 따라와주세요:)


###  매크로 함수


```cpp-formatted
/* 매크로 함수*/
#include <stdio.h>
#define square(x) x *x

int main(int argc, char **argv) {
  printf("square(3) : %d \n", square(3));

  return 0;
}
```


성공적으로 컴파일 하였다면

```exec
square(3) : 9 
```

와 같이 나옵니다.

매크로 함수를 정의하는 방법은 아래와 같습니다.

```info
#define 함수 이름(인자) 치환할 것
```


그렇다면

```cpp-formatted
#define square(x) x* x
```


위 문장의 의미는 `square` 라는 이름의 매크로 함수고 인자로 `x` 를 `x*x` 로 치환한다는 의미 입니다. `#define` 문은 앞서 배웠듯이 '어떠한 것을 다른 것으로 치환해주는 것' 이라고 배웠습니다. 여기서도 그 역할이 똑같습니다. `squre(x)` 부분을 `x*x` 로 치환해주게 되지요. 따라서

```cpp-formatted
printf("square(3) : %d \n", square(3));
```


위 문장은

```cpp-formatted
printf("square(3) : %d \n", 3 * 3);
```


과 정확히 동일하게 됩니다. 위와 같은 것을 '매크로 함수' 라 부르는 이유는 정말 하는 일이 함수와 비슷하기 때문입니다. 만일 우리가 `int squre(x)` 라는 함수를 만들어서 `x*x` 를 리턴하게 하였다면 말그대로 `3*3` 이 리턴될 것이지요. 하지만 이 매크로 함수와 진짜 함수는 엄연한 차이가 있습니다.

```cpp-formatted
printf("square(3) : %d \n", square(3));
```


우리가 컴파일러라고 생각하고 위 문장을 어떻게 해석할지 봅시다. 만일 `int squre(int x)` 라는 실제 함수가 있다면 '`square` 라는 함수를 호출해서 인자에 3 을 전달하고 9 를 리턴한다' 가 됩니다. 하지만 매크로 함수는 위 문장이 컴파일 되기 전에 전처리기에 의해 그냥

```cpp-formatted
printf("square(3) : %d \n", 3 * 3);
```


로 바뀌어 버립니다. 여기서 중요한 점은 '컴파일 되기 전에' 부분에 있지요. 다시 말해 컴퓨터는 함수를 호출하고 뭐시기 뭐시기 하는 부분 없이 그냥 `3*3` 을 계산해 버립니다. 이는 앞서 보았던 `#define` 문을 통한 치환과 동일합니다.

```cpp-formatted
/* 매크로 함수*/
#include <stdio.h>
#define square(x) x *x

int main(int argc, char **argv) {
  printf("square(3) : %d \n", square(3 + 1));

  return 0;
}
```


성공적으로 컴파일 하였다면

```exec
square(3) : 7 
```

흠. 조금 놀라운 결과가 나왔습니다.

분명히

```cpp-formatted
printf("square(3) : %d \n", square(3 + 1));
```


위 문장에서 우리의 의도는 `4*4` 를 계산하는 것이였을 것입니다. 그런데 16 이 아니라 전혀 엉뚱한 답인 7 이 나왔습니다. 도대체 왜 이런 일이 벌어진 것일까요? 제가 아까 한 말, 매크로 함수는 단순히 '싹 치환해 버리는 것이다' 라는 것을 상기 시켜 보세요. 전처리기에서 `square(3+1)` 이 어떻게 바뀔지 말이지요. 단순히 생각해보면

```cpp-formatted
printf("square(3) : %d \n", 3 + 1 * 3 + 1);
```


이 됩니다. 그런데 놀랍게도 맞습니다. 컴퓨터는 실제로 위 문장을 위와 같이 치환해버립니다. 따라서 결과적으로 7 이 출력된 것이지요. 이러한 문제를 해결하기 위해서는 어떻게 해야 할까요. 방법은 단순합니다.

```cpp-formatted
#define square(x) x* x
```


를

```cpp-formatted
#define square(x) (x) * (x)
```


로 바꾸어 주기만 하면 됩니다. 그렇게 된다면 `printf` 안에 있었던 문장은

```cpp-formatted
printf("square(3) : %d \n", (3 + 1) * (3 + 1));
```


가 되어 16 이 성공적으로 출력될 것입니다.

```cpp-formatted
/* 라디안에서 도로 바꾸기*/
#include <stdio.h>
#define RADTODEG(x) (x) * 57.295

int main(int argc, char **argv) {
  printf("5 rad 는 : %f 도", RADTODEG(5));

  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
5 rad 는 : 286.475000 도
```

아마 위 소스 코드의 내용 보다 라디안(radian) 이 무엇인지 모르는 분들이 더 많을 듯 한데, 그냥 말하자면 원주의 길이와 반지름의 길이의 비를 이용해 각도를 나타내는 단위로 자세한 내용은 생략하고 여기서는 단순히 `1 rad` 는 `57.295` 도 라는 것만 아시면 됩니다.

```cpp-formatted
#define RADTODEG(x) (x) * 57.295
```


위와 같이 라디안에서 각도로 변환하는 매크로 함수를 정의하였습니다. 그리고 `printf` 에서

```cpp-formatted
printf("5 rad 는 : %f 도", RADTODEG(5));
```


와 같이 매크로 함수를 이용하였을 때

```cpp-formatted
printf("5 rad 는 : %f 도", 5 * 57.295);
```


로 잘 바뀌어 값이 잘 출력되었습니다. 물론 `RADTODEG(1+4)` 를 하더라도 `(1+4) * 57.295` 로 잘 바뀌어 원하는 결과를 출력할 수 있게 되지요. 그렇다면 위와 같이 정의한 `RADTODEG` 는 문제가 없을까요?

한 5 초 만 생각해보세요. 위와 같이 완벽하게 잘 정의했다고 하더라도 문제는 있습니다. 바로 아래와 같은 문장이지요

```cpp-formatted
printf("5 rad 는 : %f 도", 1 / RADTODEG(5));
```


위 문장은 전처리기에 의해

```cpp-formatted
printf("5 rad 는 : %f 도", 1 / 5 * 57.295);
```


로 바뀝니다. 이는 우리가 원하는 결과인 `1 / (5 * 57.295)` 와 전혀 다른 것이지요. 이와 같은 문제를 막기 위해서 역시 전체 수식을 소괄호로 감싸 `#define RADTODEG(x) ((x) * 57.295)`와 같이 만들어야 합니다. 상당히 귀찮은 일이지요. 사소한 실수 하나로 꽤 큰 문제가 초래될 수 있으니까요.

```cpp-formatted
/* 변수의 이름 출력하기 */
#include <stdio.h>
#define PrintVariableName(var) printf(#var "\n");

int main(int argc, char **argv) {
  int a;

  PrintVariableName(a);

  return 0;
}
```


성공적으로 컴파일 하였다면

```exec
a
```

와 같이 잘 나옵니다.

```cpp-formatted
#define PrintVariableName(var) printf(#var "\n");
```


위 문장의 의미 부터 살펴봅시다. `#define` 과 같은 전처리기 문에서만 사용되는 것 중 `#` 이 있는데, 어떠한 인자 앞에 `#` 을 붙이게 되면 이 인자를 문자열로 바꾸어 버립니다. 따라서

```cpp-formatted
PrintVariableName(a);
```


은

```cpp-formatted
printf(
  "a"
  "\n");
```


으로 바뀌게 되지요. 이 때 C 언어에서 연속한 두 개의 문자열은 그냥 하나로 합쳐지므로 위 코드는 그냥

```cpp-formatted
printf("a\n");
```


와 동일하게 됩니다. 따라서 결과적으로 `a` 가 화면에 출력되는 것이지요. 여러분은 `#` 가 붙으면 단순히 '이 것을 문자열로 바꾼다' 라고 생각만 해주시면 됩니다.

```cpp-formatted
/* ## 의 사용 */
#include <stdio.h>
#define AddName(x, y) x##y

int main(int argc, char **argv) {
  int AddName(a, b);

  ab = 3;

  printf("%d \n", ab);

  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
3 
```

와 같이 나옵니다.

이번에는 `#` 의 친구 격인 `##` 에 대해 보도록 합시다. 한 가지 명심할 점은 `#` 나 `##` 모두 '전처리기 문' 에서만 사용할 수 있다는 것입니다. 즉 `#define` 에서만 사용할 수 있다는 정도로만 알아두세요. `##` 문은 아마 짐작했지만 입력된 것을 하나로 '합쳐주는' 역할을 합니다.

```cpp-formatted
#define AddName(x, y) x##y
```


위와 같이 `AddName` 에서는 `x##y` 는 `x` 에 있는 것과 `y` 에 있는 것을 하나로 합쳐줍니다. 따라서


```cpp-formatted
int AddName(a, b);
```


이 부분은 전처리기에 의해

```cpp-formatted
int ab;
```


로 정확히 치환됩니다. 따라서 컴파일러는 `ab` 라는 이름의 변수를 선언하게 되고 그 뒤로 쭉 가는 것이지요.

매크로함수가 위와 같이 여러 편리한 점들은 있지만 앞서 집고 나간 것 처럼 여러가지 어려운 문제점들도 많습니다. 위에서 처럼 괄호를 제대로 쓰지 않아 오류가 나는 경우가 많은데 이 경우 디버깅하기가 매우 까다롭기 때문에 오랜 시간을 잡아먹는 경우도 많습니다. 이러한 문제를 해결하기 위해 C 언어에서는 또다른 해결책을 제시하였는데요, 이는 바로 **인라인(inline)** 함수 입니다.


###  인라인 함수

```cpp-formatted
/* 인라인 함수 */

#include <stdio.h>
__inline int square(int a) { return a * a; }
int main(int argc, char **argv) {
  printf("%d", square(3));

  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
9
```

음. 일단 내용만을 보아서는 크게 어렵지 않습니다.

```cpp-formatted
__inline int square(int a) { return a * a; }
```



위 부분은 `__inline` 을 빼고 본다면 단순히 `square` 라는 함수를 만든데 지나지 않습니다. 또한 `printf` 에서도 역시 함수를 호출했던 것처럼 똑같은 방식으로

```cpp-formatted
printf("%d", square(3));
```


로 사용하고 있지요. 하지만 이는 함수와는 전혀 다른 행동을 합니다. 함수의 경우 호출을 하게 되면 프로그램의 흐름이 완전히 다른 곳으로 넘어가게 됩니다. 예를 들어서

```cpp-formatted
int cubic(int a) { return a * a * a; }
```
와 같은 세제곱을 하는 '평범한' 함수 하나를 만들고, `main` 함수에서

```cpp-formatted
int main(int argc, char **argv) {
  printf("%d", cubic(3));
  return 0;
}
```

와 같이 `cubic` 함수를 호출을 하게 된다면, `cubic (3)` 을 실행 시, 프로그램의 흐름이 `main` 함수를 벗어나 메모리 어딘가에 위치한 `cubic` 함수에 찾아가서 인자로 3 을 전달하고 27 을 리턴하는데, 그 리턴값을 가지고 다시 `main` 함수로 돌아오게 되는 것이지요. 이렇게 함수를 사용하게 되면 프로그램의 흐름이 기존의 함수 내부에서 벗어나 다른 함수에 들렸다가 오게 되는데 이러한 과정을 줄여서 '함수를 호출하는 과정' 이라고 말하게 됩니다.

이렇게 함수를 호출하게 된다면 단순히 `a` 를 세 번 곱하는 작업인데도 시간이 꽤 걸리게 되죠. 즉 `cubic` 함수처럼 단순한 작업만을 하는 함수의 경우에는 굳이 함수로 따로 만들 필요 없이 차라리 `main` 함수 내에서

```cpp-formatted
printf("%d", 3 * 3 * 3);
```



으로 하는 것이 훨씬 효율적일 것입니다.

이러한 생각을 살려 만든 것이 `inline` 함수 입니다. 위에서 `inline` 형식으로 만든 `square` 함수는 우리가 생각하는 함수가 전혀 아닙니다. 단순히 '함수 처럼 보이는 것' 일 뿐이지요. `inline` 함수를 사용하게 되면 마치 매크로 함수처럼

```cpp-formatted
int main(int argc, char **argv) {
  printf("%d", square(3));
  return 0;
}
```



위 코드가

```cpp-formatted
int main(int argc, char **argv) {
  printf("%d", 3 * 3);
  return 0;
}
```

과 정확히 동일해집니다. 한 가지 매크로 함수와 차이점이 있다면 매크로 함수와는 달리 인라인 함수는 전처리기가 무식하게 치환해 버리는 것이 아닙니다. 매크로 함수를 사용 했었을 때 에는 전처리기가 무식하게 치환해 버리는 바람에 연산자 우선 순위를 정확하게 고려해서 괄호도 적당히 묶어주고 해야겠지만 인라인 함수의 경우 똑똑한 컴파일러가 인라인 함수를 사용한 문장 내부에서 적절하게 '우리가 보통 함수를 사용하는 것처럼' 바꿔 줍니다.

다시 말해

```cpp-formatted
int main(int argc, char **argv) {
  printf("%d", square(3 + 1));
  return 0;
}
```

과 같은 문장은 우리가 보통 함수를 사용 하는 것처럼 처리가 되기 때문에 똑똑하게

```cpp-formatted
int main(int argc, char **argv) {
  printf("%d", (3 + 1) * (3 + 1));
  return 0;
}
```

이 됩니다.

```cpp-formatted
/* 다른 인라인 함수 예제*/
#include <stdio.h>
__inline int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main(int argc, char **argv) {
  printf("3 과 2 중 최대값은 : %d", max(3, 2));
  return 0;
}
```

성공적으로 컴파일 하였다면

```exec
3 과 2 중 최대값은 : 3
```

와 같이 나옵니다.

이번에도 역시 인라인 함수를 사용하였습니다. 컴파일러는 `max(3,2)` 라는 문장을 보고 `max` 함수 내부의 코드로 `max(3,2)` 를 대체할 수 있을 지 생각하게 됩니다.

만일 이를 `max` 함수를 호출하고 리턴 받는 형태 보다, 직접 작업하는 비용이 더 작다고 생각할 때 에는 이를 치환하게 됩니다. 하지만, 이 비용이 더 크다면 (코드 길이가 더 길어지겠지요?) `inline` 키워드를 무시하게 됩니다.

다행히도 이 `max` 함수의 경우 간단히 치환할 수 있는데 있는데 아마 컴파일러는 이 함수의 내용을

```cpp-formatted
int main(int argc, char **argv) {
  printf("%d 과 %d 중 최대값은 : %d \n", 3, 2, 3 > 2 ? 3 : 2);
  return 0;
}
```

위와 같은 문장으로 변환 시켜서 3 이 출력되게 할 것입니다. \sidenote{컴파일러가 컴파일을 수행할 때 실제로 저 코드로 바꿔서 컴파일 하지는 않습니다. 코드가 컴파일 된 결과가 위 코드가 컴파일 된 결과와 같다는 뜻입니다.}

여태까지 인라인 함수와 매크로 함수를 살펴 보았는데, 많은 사람들은 매크로 함수 보다는 인라인 함수를 사용하도록 권장하고 있습니다. 이 때문에 원래는 C 표준에 없던 인라인 함수가 `C99` 라는 새로운 C 표준에 포함된 것만 보아도 알 수 있습니다. 

인라인 함수는 매크로 함수와는 달리 **컴파일러**가 처리하기 때문에 훨씬 더 똑똑하게 동작하는데 일단, 매크로 함수와는 달리 인라인 함수는 인자들의 타입을 확인합니다.

또한 인라인 함수는 매크로와는 달리 단순 치환을 하는 것이 아니라 진짜 함수 처럼 동작하기 때문에 훨씬 구현하기 쉽고 편리합니다. 뿐만 아니라 디버깅 역시 인라인 함수가 편리하지요.

앞으로 여러분들은 단순한 작업들을 보기 편하게 함수로 처리하고 싶을 때 에는 인라인 함수들을 적극적으로 사용하였으면 합니다 :)


### 생각 해 보기

#### 문제 1

다음과 같은 인라인 함수를 하나의 문장으로 바꿀 수 있는지 생각해보세요.

```cpp-formatted
__inline int some_function(int a) {
  if (a == 0)
    return 1;
  else if (a == 1)
    return 3;
  else
    return a * 2;
}
```

##@ chewing-c-end