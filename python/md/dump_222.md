----------------
title : 씹어먹는 C++ - <9 - 4. 템플릿 메타 프로그래밍 2>
cat_title: 9 - 4. 템플릿 메타 프로그래밍 2
next_page : 223
publish_date : 2017-07-02
tex_title : 템플릿 메타프로그래밍 2 부
--------------

이번 강좌에서는

* 의존 타입 (dependent type)

* `Unit` 라이브러리 만들기

* `auto` 키워드


에 대해서 배웁니다.


![](/img/ChewingCpplogo.png)


안녕하세요 여러분! 지난 강좌에서 왜 `TMP` 를 활용하여 힘들게 힘들게 `Ratio` 클래스를 만들었는데, 아직 아마 이걸 왜 굳이 `TMP` 로 만들었는지는 설명하지 않았었습니다.


그에 앞서, 이번 강좌에서 왜 `Ratio` 클래스를 만들었는지 설명하기 전에 지난 강좌의 생각 해보기에 대해서 짚고 넘어가보자 합니다.



###  지난 강의 생각해보기 문제




지난번 생각해보기 문제는 아래와 같습니다.

TMP 를 사용해서 어떤 수가 소수인지 아닌지를 판별하는 프로그램을 만들어보세요. (난이도 : 상)

```cpp-formatted
int main()
{
  std::cout << std::boolalpha;
  std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl; // true
  std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl; // false
  std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl; // true
  std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl; // true
}
```

사실 처음에 딱 보았을 때 도대체 어떻게 `TMP` 로 구현할 것인지 감이 안잡혔을 것입니다. 하지만 만약에 소수 인지 아닌지 판별하라는 '함수' 를 작성하게 하였다면 잘 작성하였겠지요. 아마 여러분은 아래와 같은 코드를 쓰셨을 것입니다.

```cpp-formatted
bool is_prime(int N) {
  if (N == 2) return true;
  if (N == 3) return true;

  for (int i = 2; i <= N / 2; i++) {
    if (N % i == 0) return false;
  }

  return true;
}
```



왜 2 와 3 일 때 따로 처리하냐면 `N / 2` 까지 나누는 걸로 비교할 때 `2, 3` 일 경우 제대로 처리가 안되기 때문입니다. 이제 여러분이 해야할 일은 간단히 저 코드를 `TMP` 형식으로 옮기는 것입니다.

```cpp-formatted
template <>
struct is_prime<2> {
  static const bool result = true;
};

template <>
struct is_prime<3> {
  static const bool result = true;
};

template <int N>
struct is_prime {
  static const bool result = !check_div<N, 2>::result;
};

template <int N, int d>
struct check_div {
  static const bool result = (N % d == 0) || check_div<N, d + 1>::result;
};

template <int N>
struct check_div<N, N / 2> {
  static const bool result = (N % (N / 2) == 0);
};
```



무언가 잘 짜여진 코드 같습니다. 하지만 실제로 컴파일 해보면 다음과 같은 오류가 발생합니다.

```compiler-warning
check_div<N,N/>: non-type parameter of a partial specialization must be a simple identifier
```

바로

```cpp-formatted
template <int N>
struct check_div<N, N / 2> {
  static const bool result = (N % (N / 2) == 0);
};
```



이 부분에서 발생하는 문제 이지요. 위 오류가 발생한 문제는 템플릿 부분 특수화 시에 반드시 다른 연산자가 붙지 않고 단순한 식별자만 입력해주어야만 합니다. 따라서 C++ 컴파일러에 한계 상

```compiler-warning
struct check_div<N, N / 2>
```



와 같은 문법은 불가능 합니다. 그렇다면 이를 어떻게 해결할 수 있을까요? 생각을 잘 해보면, `N` 을 `int` 인자로 나타내는 대신에, 아예 `N` 을 나타내는 '타입' 으로 구현하면 어떨까요? 그렇다면 `N / 2` 역시, 직접 계산하는것이 아니라 `N / 2` 를 나타내는 타입으로 대체할 수 있고 따라서 템플릿 부분 특수화 문제를 해결할 수 있습니다.


따라서 아래와 같이 `int` 값을 표현하는 타입을 만들 수 있습니다.

```cpp-formatted
template <int N>
struct INT {
  static const int num = N;
};

template <typename a, typename b>
struct add {
  typedef INT<a::num + b::num> result;
};

template <typename a, typename b>
struct divide {
  typedef INT<a::num / b::num> result;
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;
```



예를 들어 `one` 타입은 1을, `two` 타입은 2 를 나타내게 됩니다. 그렇다면 이를 바탕으로 `TMP` 코드를 수정해보도록 하겠습니다.

```cpp-formatted
using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div {
  // result 중에서 한 개라도 true 면 전체가 true
  static const bool result =
    (N::num % d::num == 0) || check_div<N, add<d, one>::result>::result;
};

template <typename N>
struct is_prime {
  static const bool result = !check_div<N, two>::result;
};

template <>
struct is_prime<two> {
  static const bool result = true;
};

template <>
struct is_prime<three> {
  static const bool result = true;
};

template <typename N>
struct check_div<N, divide<N, two>::result> {
  static const bool result = (N::num % (N::num / 2) == 0);
};
```



그런데 컴파일 한다면 다음과 같은 오류를 보게 됩니다.


```compiler-warning
'check_div': 'divide<N,two>::result' is not a valid template type argument for parameter 'd'
```



왜 저런 오류가 발생하였을까요? 일단 오류가 발생하는 다음 두 부분의 코드를 살펴보겠습니다.

```cpp-formatted
(N::num % d::num == 0) || check_div<N, add<d, one>::result>::result;
```



와

```cpp-formatted
struct check_div<N, divide<N, two>::result> {
```



입니다. 먼저 컴파일러 입장에서 저 `::result` 를 어떻게 해석할지에 대해 생각해봅시다. 물론 우리는 `add<d, one>::result` 가 언제나 `INT<>` 타입 이라는 사실을 알고 있습니다. 왜냐하면 `typename` 인자로 들어오는 `N` 과 `d` 가 항상 `INT` 타입이기 때문에 저 `result` 를 항상 '타입'이네 라고 생각할 것입니다.


그런데, 컴파일러에 구조상 어떠한 식별자(변수 이름이든 함수 이름이든 코드 상의 이름들 `-` 위 코드의 경우 `add, check_div,, result, one` 등등 ...) 를 보았을 때 이 식별자가 '값' 인지 '타입' 인지 결정을 해야 합니다. 왜냐하면 예를들어서

```info-format
template <typename T>
int func() {
  T::t* p;
}

class A {
  const static int t;
};

class B {
  using t = int;
};
```



위와 같은 템플릿 함수에서 저 문장을 해석할 때 만약에 클래스 `A` 에 대해서, `func` 함수를 특수화 한다면, `t` 가 어떠한 `int` 값이 되어서

```info-format
T::t * p;
```



위 문장은 단순히 클래스 `A` 의 `t` 와 `p` 를 곱하는 식으로 해석이 됩니다.


반면에 `func` 함수가 클래스 `B` 에 대해서 특수화 된다면,

```info-format
T::t* p;
```



이 문장은 `int` 형 포인터 `p` 를 선언하는 꼴이 되겠지요. 따라서 컴파일러가 이 두 상황을 명확히 구분하기 위해 저 `T::t` 가 타입인지 아니면 값인지 명확하게 알려줘야만 합니다.


우리가 쓴 코드도 마찬가지로 컴파일러가 `result` 가 항상 '타입' 인지 아니면 '값' 인지 알 수 없습니다. 예컨대 만약에


```info-format
template <>
struct divide <int a, int b> {
  const static int result = a + b;
};
```



이런 템플릿이 정의가 되어있다면, 만약에 `N` 과 `two` 가 그냥 `int` 값이였다면 저 `result` 는 `static const int` 타입의 '값' 이 됩니다.이렇게 템플릿 인자에 따라서 어떠한 타입이 달라질 수 있는 것을 **의존 타입(dependent type)** 이라고 부릅니다. 위 경우 저 `result` 는 `N` 에 의존하기 때문에 의존 타입이 되겠지요.


따라서 컴파일러가 저 문장을 성공적으로 해석하기 위해서는 우리가 반드시 "야 저 `result` 는 무조건 타입이야" 라고 알려주어야만 합니다. 이를 위해서는 간단히 아래 코드 처럼

```cpp-formatted
struct check_div<N, typename divide<N, two>::result> {
```

`typename` 키워드를 붙여주면 됩니다.마찬가지로

```cpp-formatted
(N::num % d::num == 0) || check_div<N, add<d, one>::result>::result;
```



에서 `typename` 키워드를 붙인다면

```cpp-formatted
(N::num % d::num == 0) || check_div<N, typename add<d, one>::result>::result;
```



이 되겠지요. 참고로 의존 '값' 의 경우 `typename` 을 안 붙여줘도 됩니다. 컴파일러는 어떤 식별자를 보았을 때 기본으로 '값' 이라고 생각합니다. 따라서 `check_div` 앞에 아무것도 안올 수 있는 것입니다 (`check_div` 의 `result` 는 `static const bool` 이기 때문에!)


따라서 이를 고치면 다음과 같습니다.

```cpp-formatted
template <typename N, typename d>
struct check_div {
  // result 중에서 한 개라도 true 면 전체가 true
  static const bool result = (N::num % d::num == 0) ||
                             check_div<N, typename add<d, one>::result>::result;
};

// 생략

template <typename N>
struct check_div<N, typename divide<N, two>::result> {
  static const bool result = (N::num % (N::num / 2) == 0);
};
```



마지막으로, 위 `is_prime` 을 사용하기 위해서는

```cpp-formatted
is_prime<INT<11>>::result
```



이런 식으로 사용해야 합니다. 하지만 생각해보기에서 요구한 것은 `is_prime<11>::result` 로 사용하는 것이기 때문에 이를 위해서 `is_prime` 을 다음과 같이 정의하고, 기존의 `is_prime` 을 `_is_prime` 으로 바꾸도록 하겠습니다.

```cpp-formatted
template <int N>
struct is_prime {
  static const bool result = _is_prime<INT<N>>::result;
};
```

그렇다면 전체 코드를 살펴보겠습니다.

```cpp-formatted
#include <iostream>

template <int N>
struct INT {
  static const int num = N;
};

template <typename a, typename b>
struct add {
  typedef INT<a::num + b::num> result;
};

template <typename a, typename b>
struct divide {
  typedef INT<a::num / b::num> result;
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div {
  // result 중에서 한 개라도 true 면 전체가 true
  static const bool result = (N::num % d::num == 0) ||
                             check_div<N, typename add<d, one>::result>::result;
};

template <typename N>
struct _is_prime {
  static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> {
  static const bool result = true;
};

template <>
struct _is_prime<three> {
  static const bool result = true;
};

template <typename N>
struct check_div<N, typename divide<N, two>::result> {
  static const bool result = (N::num % (N::num / 2) == 0);
};

template <int N>
struct is_prime {
  static const bool result = _is_prime<INT<N>>::result;
};

int main() {
  std::cout << std::boolalpha;
  std::cout << "Is 2 prime ? :: " << is_prime<2>::result << std::endl;
  std::cout << "Is 10 prime ? :: " << is_prime<10>::result << std::endl;
  std::cout << "Is 11 prime ? :: " << is_prime<11>::result << std::endl;
  std::cout << "Is 61 prime ? :: " << is_prime<61>::result << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
Is 2 prime ? :: true
Is 10 prime ? :: false
Is 11 prime ? :: true
Is 61 prime ? :: true
```

와 같이 제대로 판별함을 알 수 있습니다.


참고로 컴파일러에 따라서 재귀적으로 몇 번까지 사용 가능한지 깊이가 정해져있기 때문에, 꽤 큰 수를 넣는다면 컴파일 오류가 발생할 수 도 있습니다.



자, 그렇다면 본격적으로 이번 강의를 시작해보도록 하겠습니다. 지난 강좌에서 `Ratio` 클래스를 만들면서 왜 굳이 이것을 `TMP` 로 만들었을까, 그냥 일반적인 클래스로 만들었다면 훨씬 직관적이고 편하지 않나라고 많이 생각하셨을 것입니다. 바로 지금부터 `TMP` 의 진짜 파워에 대해서 알아보도록 하겠습니다.




###  단위(Unit) 라이브러리


C++ 코드를 작성하는 이유는 여러가지가 있겠지만, 그 중 하나로 바로 여러 수치 계산을 사용하는데에도 많이 사용합니다. 예를 들어서 인공위성의 궤도를 계산한다던지, 입자의 운동을 계산한다던지 말이지요. 이러한 물리적 수치 계산 시에 꼭 필요한 것이 바로 '단위' 입니다.

단위라 하면 쉽게 말해 킬로그램 (kg), 미터 (m), 초 (s) 등을 생각하시면 됩니다. 이러한 것들을 계산하는 프로그램들의 경우, `double` 이나 `float` 변수에 들어가는 값에는 '단위' 가 붙어서 들어가겠지요.

예를 들어서 핸드폰의 가속도 센서에서 부터 데이터를 받는 프로그램은 아마도 m/s^2 단위로 데이터를 받겠지요. 혹은 시계로 부터 데이터를 받는 프로그램은 `s` 단위로 데이터를 받을 것 입니다.

아무튼 이렇게 단위가 붙은 데이터를 처리할 때 중요한 점은 바로 데이터를 연산할 때 항상 단위를 확인해야 된다는 점입니다. 예를 들어서, 다음과 같은 코드가 있다고 생각해봅시다.

```cpp-formatted
float v1, v2;  // v1, v2 는 속도
std::cout << v1 + v2;
```

당연히 `v1` 과 `v2` 는 속도 값을 나타내므로 같은 단위이기 때문에 더할 수 있습니다. (여기서 더할 수 있다는 말은 물리적으로 더한 값이 말이 된다는 의미 입니다). 반면에;


```cpp-formatted
float v;        // 속도; m/s
float a;        // 가속도; m/s^2
std::cout << v + a;  // ???
```


만약에 `v` 가 속도를 나타내는 값이고, `a` 가 가속도를 나타내는 값이라면, `v + a` 는 불가능한 연산입니다. 만약에 프로그래머가 저러한 코드를 썻다면 분명히 실수일 것입니다. 물론 C++ 컴파일러 입장에서는 그냥 두 개의 `float` 변수를 더한 것이기 때문에 문제 없이 컴파일 됩니다. 하지만 프로그램을 돌리게 된다면 골치아픈 문제가 발생하겠지요.


실제로, `NASA` 의 경우 [단위를 잘못 처리해서 1조원 짜리 화성 탐사선을 날려먹은 경우](http://www.cnn.com/TECH/space/9909/30/mars.metric.02/)가 있습니다. 이 경우 1조원 자리 버그 이겠네요.


여러분 이라면 이러한 실수를 어떻게 막을 것인가요? 일단 가장 먼저 드는 생각으로 단위 데이터를 일반적인 변수에 보관하지 말고 클래스를 만들어서 클래스 객체에서 보관하는 것입니다. 그리고 `operator+` 등으로 연산자들을 오버로딩 한 뒤에, 연산 시에 객체 끼리 단위를 체크해서 단위가 맞지 않으면 적절히 처리하면 됩니다.


물론 이 방법은 꽤나 괜찮아 보이지만 한 가지 문제가 있습니다. 만일 틀린 단위를 연산하는 코드가 *매우 드물게* 일어난다면 어떨까요? 즉 런타임에서 그 문제를 발견하지 못한 채 넘어갈 수 있다는 점입니다.


가장 이상적인 상황은 단위가 맞지 않는 연산을 수행하는 코드가 있다면 아예 컴파일 시에 오류를 발생시켜버리는 것입니다. 그렇다면 적어도 틀린 단위를 연산하는 일은 막을 수 있게 되고, 프로그램을 실행 시키면서 기다리는 수고를 줄일 수 있게 되지요.

이를 위해서 다음과 같은 클래스를 생각해봅시다.

```cpp-formatted
template <typename U, typename V, typename W>
struct Dim {
  using M = U;  // kg
  using L = V;  // m
  using T = W;  // s

  using type = Dim<M, L, T>;
};
```


이 `Dim` 이라는 클래스는 어떠한 데이터의 단위를 나타내기 위해서 사용됩니다. 어떠한 물리량의 단위를 나타내기 위해서는 무게(kg), 길이(m), 시간(s) 이 3 개로 나타낼 수 있습니다. (실제로는 8개가 필요하지만 단순화를 위해 3개만 사용하도록 하겠습니다).


예를 들어서 속도의 경우 *m/s* 이므로, 저 `Dim` 클래스로 표현하자면 `Dim<0, 1, -1>` 로 나타낼 수 있습니다. 왜냐하면 *m/s = kg^0 m^1 s^-1* 이기 때문이지요.


마찬가지로 힘의 경우 단위가 *kg m /s^2* 이므로 `Dim` 클래스로 표현하자면 `Dim<1, 1, -2>` 가 됩니다.


물론 저 `Dim` 의 경우 템플릿 인자로 타입을 받기 때문에 단순히 `Dim<0, 1, -1>` 이렇게 사용할 수 있는 것이 아닙니다. 대신에 앞서 만들었던`Ratio` 클래스를 이용해서 저 숫자들을 '타입' 으로 표현해주어야 합니다. 따라서, 실제로는

```cpp-formatted
Dim<1, 1, -2>
```

가 아니라

```cpp-formatted
Dim<Ratio<1, 1>, Ratio<1, 1>, Ratio<-2, 1>>
```

이런 식으로 정의를 해야겠지요. 그렇다면 `Dim` 끼리 더하고 빼는 템플릿 클래스도 아래와 같이 만들 수 있게 됩니다.

```cpp-formatted
template <typename U, typename V>
struct add_dim_ {
  typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
              typename Ratio_add<typename U::L, typename V::L>::type,
              typename Ratio_add<typename U::T, typename V::T>::type>
    type;
};

template <typename U, typename V>
struct subtract_dim_ {
  typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
              typename Ratio_subtract<typename U::L, typename V::L>::type,
              typename Ratio_subtract<typename U::T, typename V::T>::type>
    type;
};
```



왜 `typename` 이 저렇게도 많이 붙어있는지는 아마 잘 이해하실 거라 생각합니다. 왜냐하면 예를 들어 `M` 의 경우 `U` 에 의존한 타입이고, `type` 의 경우도 마찬가지로 `U` 와 `V` 에 의존하는 타입이기 때문이지요.


자 이제, 실제 데이터를 담는 클래스를 만들어보도록 하겠습니다.

```cpp-formatted
template <typename T, typename D>
struct quantity {
  T q;
  using dim_type = D;
};
```

일단 위 처럼 `q` 라는 멤버 변수에 데이터를 담고, (데이터의 타입은 `T` 가 되겠지요), `dim_type` 에 차원 정보를 담게 됩니다. 차원 정보는 데이터와는 다르게 'Dim 타입' 그 자체로 표현됩니다.


자 이제, 실제로 `quantity` 객체를 가지고 연산을 수행하기 위해서는 우리가 연산자들을 오버로드 해줘야만 합니다. 일단 간단히 `+` 와 `-` 연산자를 어떻게 오버로드 할 지 생각해봅시다. 앞서 말했듯이, 두 개의 데이터를 더하거나 빼기 위해서는 반드시 단위가 일치해야 합니다. 이 말은, `dim_type` 이 같은 타입이어야만 하다는 것이지요.

따라서 `operator+` 와 `operator-` 는 다음과 같이 간단히 정의할 수 있습니다.

```cpp-formatted
quantity operator+(quantity<T, D> quant) { return quantity<T, D>(q + quant.q); }
quantity operator-(quantity<T, D> quant) { return quantity<T, D>(q - quant.q); }
```



위 `operator+` 는 인자로 받는 `quantity` 의 데이터 타입과 `Dim` 타입이 일치해야지만 인스턴스화 됩니다. 만약에, 데이터 타입이나 `Dim` 타입이 일치하지 않았더라면 저 `operator+` 는 인스턴스화 될 수 없고 따라서 컴파일러는 저 `operator+` 를 찾을 수 없다는 오류를 발생시키게 됩니다!


그렇다면 실제로 테스트를 해볼까요.

```cpp
#include <iostream>

template <int X, int Y>
struct GCD {
  static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
  static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
 private:
  const static int _gcd = GCD<N, D>::value;

 public:
  typedef Ratio<N / _gcd, D / _gcd> type;
  static const int num = N / _gcd;
  static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
  using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
  using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
  using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
  using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim {
  using M = U;
  using L = V;
  using T = W;

  using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
  typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
              typename Ratio_add<typename U::L, typename V::L>::type,
              typename Ratio_add<typename U::T, typename V::T>::type>
    type;
};

template <typename U, typename V>
struct subtract_dim_ {
  typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
              typename Ratio_subtract<typename U::L, typename V::L>::type,
              typename Ratio_subtract<typename U::T, typename V::T>::type>
    type;
};

template <typename T, typename D>
struct quantity {
  T q;
  using dim_type = D;

  quantity operator+(quantity<T, D> quant) {
    return quantity<T, D>(q + quant.q);
  }

  quantity operator-(quantity<T, D> quant) {
    return quantity<T, D>(q - quant.q);
  }

  quantity(T q) : q(q) {}
};
int main() {
  using one = Ratio<1, 1>;
  using zero = Ratio<0, 1>;

  quantity<double, Dim<one, zero, zero>> kg(1);
  quantity<double, Dim<zero, one, zero>> meter(1);
  quantity<double, Dim<zero, zero, one>> second(1);

  // Good
  kg + kg;

  // Bad
  kg + meter;
}
```

컴파일 하였다면 다음과 같은 오류가 납니다.

```compiler-warning
no operator "+" matches these operands
binary '+': no operator found which takes a right-hand operand of type 'quantity<double,Dim<zero,one,zero>>' (or there is no acceptable conversion)
```

즉 위 `+` 에 해당하는 연산자 함수를 찾을 수 없다는 것이지요. 예상했던 대로,

```code-warning
// Bad
kg + meter;
```

위 부분에서 오류가 발생하는데, `kg` 와 `meter` 의 단위가 다르기 때문에 발생하게 됩니다. 반면에

```info-format
// Good
kg + kg;
```

는 잘 컴파일되지요.


그렇다면 이제 `*` 와 `/` 연산자만 만들어주면 되겠습니다. 하지만 `*` 와 `/` 의 경우 `+` 와 `-` 보다 좀 더 까다롭습니다. 왜냐하면 `*` 와 `/` 의 경우 굳이 `Dim` 이 일치하지 않아도 되거든요! 다만 이 연산을 수행하였을 때 새로운 차원의 데이터가 나올 뿐입니다.


예를 들어서 가속도를 나타내기 위해서는

```cpp-formatted
meter / (second * second)
```

이렇게 해주면 됩니다. 다만 새로운 차원의 데이터 (`Dim<zero, one, minus_two>`) 가 탄생할 뿐이지요. 따라서, `operator*` 와 `operator/` 의 경우 두 개의 다른 차원의 값을 받아도 처리할 수 있어야 합니다. 따라서 `opreator*` 와 `/` 를 정의해보자면 아래와 같습니다.

```cpp-formatted
template <typename D2>
quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
  return quantity<T, typename add_dim_<D, D2>::type>(q * quant.q);
}

template <typename D2>
quantity<T, typename subtract_dim_<D, D2>::type> operator/(
  quantity<T, D2> quant) {
  return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
}
```

새로 만들어지는 타입의 차원은 당연히도 `add_dim_<D, D2>::type` 이 되겠고 (`opreator*` 의 경우), 그 값은 그냥 실제 값을 곱해주면 됩니다. 이와 더불어서

```cpp-formatted
3 * kg
```

과 같은 곱도 처리해야 하기 때문에, 아래와 같은 함수들도 정의해줘야 합니다.

```cpp-formatted
quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }
quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }
```

이는 위 처럼 일반적인 차원이 없는 값 과의 곱도 지원해줍니다. 그렇다면 예를 들어서 아래와 같이 정의된 `F` 의 타입은 어떻게 될까요?


```cpp-formatted
// F 의 타입은?
F = kg * meter / (second * second);
```

일단 `F` 의 차원은 계산해보면 (1, 1, -2) 이렇게 나올 것 입니다. 따라서, `F` 의 `dim` 타입은 `<Ratio<1, 1>, Ratio<1, 1>, Ratio<-2, 1>>` 가 되겠지요. 다시 말해, `F` 를 다음과 같이 나타낼 수 있습니다.

```cpp
quantity<double, Dim<one, one, Ratio<-2, 1>>> F = kg * meter / (second * second);
```

그런데, 매번 변수를 정의할 때 마다 저렇게 길고 긴 타입을 써주는 것은 매우 귀찮은 일입니다. 저 `kg * meter / (second * second)` 를 계산해서 나오는 객체의 타입이 저렇게 된다는 사실은 저도 알고 컴파일러도 알고 있습니다. 컴파일러가 쉽게 알아낼 수 있는 타입을 굳이 우리가 써주어야 할까요? 똑똑한 컴파일러가 타입을 알아서 생각하도록 하면 안될까요?


물론 가능합니다.


###  타입을 알아서 추측해라! `- auto` 키워드


C++ 코드를 많이 짜면서 느꼈겠지만, 객체를 생성할 때, 많은 경우 굳이 타입을 쓰지 않아도 알아서 추측할 수 있는 경우들이 많이 있습니다.

예를 들어서,
```cpp-formatted
(??) a = 3;
```

와 같이 썼다면 저 (??) 는 아마 `int` 를 의도한 것이겠지요. 아니면

```cpp-formatted
some_class a;
(??) b = a;
```


의 경우 저 (??) 에는 아마 `some_class` 가 들어가겠지요? 즉 객체가 복사 생성 될 때, 그 복사 생성하는 대상의 타입을 확실히 알 수 있다면 굳이 그 객체의 타입을 명시하지 않아도 컴파일러가 알아낼 수 있습니다.


물론 때때로 컴파일러가 타입을 제대로 유추할 수 없는 경우도 있습니다. 예를 들어서, 우리의 위 예제 코드에서

```cpp-formatted
quantity<double, Dim<one, zero, zero>> kg(1);
```

의 경우 만약에 저 타입 부분을 가리고

```cpp-formatted
(??) kg(1);
```



와 같이 살펴본다면 어떨까요? 컴파일러에 입장에서는 단순히 생각해봤을 때 그냥 1 로 초기화 하는 변수 이므로 (??) 에는 `int` 가 들어가겠지요. 따라서 이 경우에는 우리가 원하는 타입으로 생성할 수 없습니다. 반면에,

```cpp-formatted
(??) F = kg * meter / (second * second);
```



`F` 의 경우 우리가 굳이 타입을 적지 않아도 컴파일러가 오른쪽의 연산을 통해서 `F` 의 타입을 정확하게 알아낼 수 있습니다.


이와 같이 컴파일러가 타입을 정확히 알아낼 수 있는 경우 굳이 그 길고 긴 타입을 적지 않고 간단히 `auto` 로 표현할 수 있습니다. 그리고 그 `auto` 에 해당하는 타입은 컴파일 시에 컴파일러에 의해 추론됩니다. 아래 간단한 예제를 살펴볼까요.

```cpp-formatted
#include <iostream>
#include <typeinfo>

int sum(int a, int b) { return a + b; }

class SomeClass {
  int data;

 public:
  SomeClass(int d) : data(d) {}
  SomeClass(const SomeClass& s) : data(s.data) {}
};

int main() {
  auto c = sum(1, 2);  // 함수 리턴 타입으로 부터 int 라고 추측 가능
  auto num = 1.0 + 2.0;  // double 로 추측 가능!

  SomeClass some(10);
  auto some2 = some;

  auto some3(10);  // SomeClass 객체를 만들까요?

  std::cout << "c 의 타입은? :: " << typeid(c).name() << std::endl;
  std::cout << "num 의 타입은? :: " << typeid(num).name() << std::endl;
  std::cout << "some2 의 타입은? :: " << typeid(some2).name() << std::endl;
  std::cout << "some3 의 타입은? :: " << typeid(some3).name() << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
c 의 타입은? :: i
num 의 타입은? :: d
some2 의 타입은? :: 9SomeClass
some3 의 타입은? :: i
```

와 같이 나옵니다.

```cpp-formatted
std::cout << "c 의 타입은? :: " << typeid(c).name() << std::endl;
std::cout << "num 의 타입은? :: " << typeid(num).name() << std::endl;
std::cout << "some2 의 타입은? :: " << typeid(some2).name() << std::endl;
```

일단 위 3줄은 우리의 예상대로 `auto` 키워드가 잘 타입을 추론해줍니다. `c` 의 경우 함수의 리턴 타입으로 부터 `int` 타입이라는 것을 알 수 있고, `num` 의 경우 `1.0 + 2.0` 의 결과가 `double` 이므로 `num` 역시 `double` 타입 변수로 초기화 됩니다. 마지막으로 `some2` 의 경우 `SomeClass` 타입인 `some` 으로 부터 복사 생성 되므로 `SomeClass` 타입이 되지요.


마지막으로 `some3` 를 살펴봅시다.

```cpp-formatted
auto some3(10);  // SomeClass 객체를 만들까요?
```

이전에 `some` 을 만들 때 `SomeClass some(10)` 으로 만들었기 때문에 저 `some3` 도 혹시 `SomeClass` 타입으로 추론하지 않을까 생각할 수 있습니다. 하지만 컴파일러는 최대한 단순하게 가능한 방법으로 추론하기 때문에 (실제로 `auto` 타입을 추론하는 방법은 템플릿에 들어갈 타입을 추론하는 것과 동일합니다), 그냥 `int` 변수로 만들어 버립니다.


하지만 아래의 `F` 의 경우 정확히 타입을 추론할 수 있기 때문에 그냥

```cpp-formatted
// F 의 타입은 굳이 알필요 없다!
auto F = kg * meter / (second * second);
```

위와 같이 `auto` 키워드를 이용하면 됩니다.


참고로 편의를 위해 `quantity` 를 `ostream` 으로 출력해주는 함수인
```cpp-formatted
template <typename T, typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q) {
  out << q.q << "kg^" << D::M::num / D::M::den << "m^" << D::L::num / D::L::den
      << "s^" << D::T::num / D::T::den;

  return out;
}
```

를 제작하였습니다. 따라서 전체 코드를 살펴보면 다음과 같습니다.

```cpp
#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD {
  static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
  static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
 private:
  const static int _gcd = GCD<N, D>::value;

 public:
  typedef Ratio<N / _gcd, D / _gcd> type;
  static const int num = N / _gcd;
  static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
  using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
  using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
  using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
  using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim {
  using M = U;
  using L = V;
  using T = W;

  using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
  typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
              typename Ratio_add<typename U::L, typename V::L>::type,
              typename Ratio_add<typename U::T, typename V::T>::type>
    type;
};

template <typename U, typename V>
struct subtract_dim_ {
  typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
              typename Ratio_subtract<typename U::L, typename V::L>::type,
              typename Ratio_subtract<typename U::T, typename V::T>::type>
    type;
};

template <typename T, typename D>
struct quantity {
  T q;
  using dim_type = D;

  quantity operator+(quantity<T, D> quant) {
    return quantity<T, D>(q + quant.q);
  }

  quantity operator-(quantity<T, D> quant) {
    return quantity<T, D>(q - quant.q);
  }

  template <typename D2>
  quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
    return quantity<T, typename add_dim_<D, D2>::type>(q * quant.q);
  }

  template <typename D2>
  quantity<T, typename subtract_dim_<D, D2>::type> operator/(
    quantity<T, D2> quant) {
    return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
  }

  // Scalar multiplication and division
  quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }

  quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }

  quantity(T q) : q(q) {}
};

template <typename T, typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q) {
  out << q.q << "kg^" << D::M::num / D::M::den << "m^" << D::L::num / D::L::den
      << "s^" << D::T::num / D::T::den;

  return out;
}

int main() {
  using one = Ratio<1, 1>;
  using zero = Ratio<0, 1>;

  quantity<double, Dim<one, zero, zero>> kg(2);
  quantity<double, Dim<zero, one, zero>> meter(3);
  quantity<double, Dim<zero, zero, one>> second(1);

  // F 의 타입은 굳이 알필요 없다!
  auto F = kg * meter / (second * second);
  std::cout << "2 kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는? " << F << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
2 kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는? 6kg^1m^1s^-2
```


와 같이 잘 나옵니다.


`auto` 키워드는 템플릿의 사용으로 복잡해진 타입 이름들을 간단하게 나타낼 수 있는 획기적인 방법입니다. 물론 짧은 이름의 타입일 경우 그냥 써주는 것이 좋지만 (왜냐면 그 코드를 읽는 사람에 입장에서 한눈에 타입을 알 수 있으면 좋기 때문에), 위 경우 처럼 복잡한 타입 이름의 경우, 그 타입을 쉽게 추측할 수 있다면 `auto` 키워드를 활용하는 것도 좋습니다.


이것으로 템플릿 메타프로그래밍에 대한 강좌를 마치도록 하겠습니다. 사실 실제 현업에서 템플릿 메타 프로그래밍을 활용하는 경우는 그다지 많지 않습니다. 왜냐하면 일단 `TMP` 의 특성상복잡하고, 머리를 매우 많이 써야되고, 무엇보다도 버그가 발생하였을 때 찾는 것이 매우 힘듧니다.


하지만 우리의 `Unit` 클래스 처럼 `TMP` 를 적절하게 활용하면 런타임에서 찾아야 하는 오류를 컴파일 타임에서 미리 다 잡아낼 수 도 있고, 런타임 시에 수행해야 하는 연산들도 일부 컴파일 타임으로 옮길 수 있습니다.


만약에 `TMP` 를 직접 작성할 일이 있다면 이미 `TMP` 를 그나마 편하게 수행하기 위해 만들어진 `boost::MPL` 라이브러리가 있습니다. 이 라이브러리를 활용하신다면 비교적 쉽게 `TMP` 코드를 짤 수 있을 것입니다!


다음 강좌에서는 C++ 의 또다른 막강한 무기인 표준 라이브러리 (STL) 에 대해 알아보도록 하겠습니다!



###  생각 해보기

#### 문제 1

컴파일러가 `auto` 키워드에 들어갈 타입을 추측하는 방법은 템플릿에서 들어갈 타입을 추측하는 방법과 같습니다. [여기를 클릭해서 읽어보세요!](http://en.cppreference.com/w/cpp/language/template_argument_deduction)

##@ chewing-cpp-end