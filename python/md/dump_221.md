 itguru Top itguru Top


이번 강좌에서는
* 타입이 아닌 템플릿 인자
* 템플릿 메타 프로그래밍의 시작
* using 키워드 사용





안녕하세요 여러분! 지난번 강좌에서 template 을 처음으로 소개하였는데 어떠하셨나요? 템플릿을 통해서 프로그래밍이 좀 더 편해진 것 같나요? 이렇게 템플릿을 통해서 타입이 마치 인자 인것 처럼 사용하는 것을 바로 일반화 프로그래밍 (generic programming) 혹은 그냥 제너릭 프로그래밍 이라고 부릅니다.


앞선 강좌에서는 템플릿 인자로 타입들만 전달하였지만, 실제로는 일반적인 값들도 인자로 전달할 수 있습니다. 아래의 예제를 살펴보겠습니다.

```cpp

/* 템플릿 인자로 값을 받기 */
#include <iostream>
using namespace std;


template <typename T, unsigned int N>
class Array
{
T data[N];


public:


// 배열을 받는 레퍼런스 arr
Array(T (&arr)[N]) {
for (int i = 0; i < N; i++) {
data[i] = arr[i];
}
}


T* get_array() {
return data;
}


unsigned int size() {
return N;
}


void print_all() {
for (int i = 0; i < N; i++) {
cout << data[i] << ", ";
}
cout << endl;
}
};


int main()
{
int arr[3] = { 1,2,3 };


// 배열 wrapper 클래스
Array<int, 3> arr_w (arr);


arr_w.print_all();
}


```



성공적으로 컴파일 하였다면





와 같이 나옵니다.

```cpp

template <typename T, int N>
```



템플릿 정의 부분을 살펴보면 바로 알겠지만, 템플릿 역시 마치 함수의 인자에 값을 받는 것 처럼 템플릿에도 값을 전달 할 수 있습니다. 다만 함수 처럼 임의의 객체를 인자로 받을 수 있는 것은 아니고, 위 처럼 정수 타입이나, 레퍼런스 혹은 포인터 만을 받을 수 있습니다. 그 이유는 잘 생각해보면 당연한데, 템플릿이 인스턴스화 되는 과정은 컴파일 시에 일어나는데, 만약에 객체를 직접 받는다면, 컴파일을 하기 전에 컴파일을 해야되는 모순적인 상황이 발생하게 되기 때문이지요.


아무튼, 템플릿 인자로는 단순한 정수타입이나, 레퍼런스, 포인터만 받을 수 있다고 생각하시면 됩니다.

```cpp

// 배열 wrapper 클래스
Array<int, 3> arr_w (arr);
```





위와 같이 템플릿 인스턴스화를 하게 되면, 템플릿에 T 자리에는 int 가, N 자리에는 3 이 들어가겠지요. 그렇다면 컴파일러는

```cpp

T data[N];
```

를
```cpp

int data[3];

으로 대체해서 코드를 생성하게 되고, 마찬가지로

```cpp

  // 배열을 받는 레퍼런스 arr
Array(T (&arr)[N]) {
for (int i = 0; i < N; i++) {
data[i] = arr[i];
}
}
```



생성자 역시

```cpp

  // 배열을 받는 레퍼런스 arr
Array(int (&arr)[3]) {
for (int i = 0; i < 3; i++) {
data[i] = arr[i];
}
}
```



로 아예 코드가 생성되어 실행됩니다. 참고로 이 처럼 배열을 감싸는 wrapper 클래스를 만들어서 마치 배열 처럼 사용한다면 (물론 그러기 위해서는 [] 연산자도 오버로드 해야겠죠?) 배열을 사용함으로써 발생하는 문제들을 많이 해결할 수 있게 됩니다. 예를 들어서, 일반 배열은 배열 범위가 넘어가도 알 수 없지만, 위 Array 클래스는 index 범위가 넘어가는 곳을 가리키면 뭔가 메세지를 띄우든 오류를 발생 시키든 해서 사용자에게 알려 줄 수 있습니다.


그런데, 과연 아래 두 개 클래스는 같은 클래스 일까요? 다른 클래스 일까요?

```cpp

Array<int, 5>
Array<int, 3>
```



간단히 아래 코드로 확인해 볼 수 있습니다.

```cpp

cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << endl;
```



참고로 typeid 를 사용하려면 <typeinfo> 헤더파일을 추가해주시면 됩니다. 그 결과는 당연하게도





와 같이 다르다고 나옵니다. 왜 다르냐면 당연히, 다른 템플릿 인자로 인스턴스화 되었기 때문이지요. 컴파일러는 Array<int, 5> 와 Array<int, 3> 를 위해 각기 다른 코드를 생성하며 다른 클래스의 객체들을 만들게 됩니다.


그렇다면 아래와 같이 정의된 Int 클래스를 생각해봅시다.

```cpp

template <int N>
struct Int {
static const int num = N;
};
```



이 클래스는 템플릿 인자로 int 값을 받습니다. 참고로, 왜 static const 에 값을 저장하냐면, 첫 번째로 C++ 클래스 멤버 중에서 클래스 자체에서 저런 식으로 초기화를 할 수 있는 멤버의 타입은 static const 밖에 없고, 두 번째로 static const 야 말로 '이 클래스는 이 것이다' 라는 의미를 가장 잘 나타내기 때문입니다. 왜냐하면 static 타입 멤버의 특성 상, 이 클래스가 생성한 객체들 사이에서 공유되는 값이기 때문에 '이 타입이면 이 값을 나타낸다'라고 볼 수 있습니다. 또한 const 이므로, 그 나타내는 값이 변하지 않게 됩니다.


따라서 아래 처럼 마치 객체를 생성하듯 타입들을 생성할 수 있습니다.

```cpp

typedef Int<1> one;
typedef Int<2> two;
```





그렇다면 저 one 타입과 two 타입은 1 과 2 의 값을 나타내는 타입이 됩니다. (one 과 two 는 객체가 아닙니다!)


그럼 이제 one 과 two 를 가지고 무엇을 할 수 있을까요? 재미있게도 마치 int 변수를 다루는 것 처럼 연산자를 만들 수 있습니다. 아래 예제를 살펴볼까요.

```cpp

#include <iostream>
#include <typeinfo>
using namespace std;


template <int N>
struct Int {
static const int num = N;
};


template <typename T, typename U>
struct add {
typedef Int <T::num + U::num> result;
};


int main()
{
typedef Int<1> one;
typedef Int<2> two;


typedef add<one, two>::result three;


cout << "Addtion result : " << three::num << endl;
}


```



성공적으로 컴파일 하였다면





와 같이 실제 계산 결과가 잘 나오게 됩니다.


덧셈을 수행하는 템플릿 클래스를 살펴봅시다.

```cpp

template <typename T, typename U>
struct add {
typedef Int<T::num + U::num> result;
};
```



위 add 클래스의 템플릿은 인자로 두 개의 타입을 받아서 그 타입의 num 멤버를 더해서 새로운 타입인 result 를 만들어 내게 됩니다.


```cpp

typedef add<one, two>::result three;
```

위 부분은 실제 덧셈을 수행하는 부분입니다. add 클래스를 함수라고 생각한다면 그 계산 결과를 내부 result 타입으로 반환한다고 보면 됩니다. 아무튼 one 과 two 를 더한 것을 나타내는 타입이 result 로 정의되고, 이를 three 라고 부르겠습니다.
실제로, 그 결과를 보면
```cpp
cout << "Addtion result : " << three::num << endl;
```

를 통해서 3 이 잘 출력됨을 알 수 있습니다.
한 가지 흥미로운 점은저 3 이라는 값이 프로그램이 실행되면서 계산되는 것이 아니라는 점입니다. 컴파일 시에, 컴파일러가 three::num 을 3 으로 치환 해버립니다.


실제로 마우스를 올려보면 저 값이 3 이란 사실을 알 수 있습니다.

다시 말해, 저 덧셈이 수행 되는 시기는 컴파일 타임이고, 런타임 시에는 단순히 그 결과를 보여주게 되는 것입니다.

 템플릿 메타 프로그래밍### (Template Meta Programming - TMP)


여태까지타입은 어떠한 객체에 무엇을 저장하느냐를 지정하는데 사용해 왔지, 타입 자체가 어떠한 값을 가지지는 않았습니다. 하지만, 바로 위 예제를 통해서 알 수 있듯이, 템플릿을 사용하면 객체를 생성하지 않더라도, 타입에 어떠한 '값' 을 부여할 수 있고, 또 그타입들을 가지고 '연산' 을 할 수 있다는 점 입니다. 또한 타입은 반드시 컴파일 타임에 확정되어야 하므로, 컴파일 타임에 모든 연산이 끝나게 됩니다.


이렇게 타입을 가지고컴파일 타임에 생성되는 '코드'로 프로그래밍을 하는 것을 메타 프로그래밍(meta programming) 이라고 합니다. C++ 의 경우 템플릿을 가지고 이러한 작업을 하기 때문에템플릿 메타 프로그래밍, 줄여서 TMP라고 부릅니다.

```cpp

/* 컴파일 타임 팩토리얼 계산 */
#include <iostream>
using namespace std;


template <int N>
struct Factorial {
static const int result = N * Factorial<N - 1>::result;
};


template <>
struct Factorial<1> {
static const int result = 1;
};


int main()
{
cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << endl;
}


성공적으로 컴파일 하였다면



와 같이 잘 나옵니다.


팩토리얼(factorial) 은 단순히 1 부터  n 까지 곱한 것이라 생각하면 됩니다. 예를 들어 3 팩토리얼 (3! 이라 씁니다) 은 1 * 2 * 3 이라 생각하면 됩니다. 이 팩토리얼을 어떻게 하면 이전 예제와 같은 템플릿을 사용한 구조로 나타낼 수 있을까요? 사실 아래와 같이 매우 단순합니다.

```cpp

template <int N>
struct Factorial {
static const int result = N * Factorial<N - 1>::result;
};
```



만약에 저 Factorial 을 일반적인 함수로 구성하려고 했다면 아마 아래와 같은 재귀 함수 형태를 사용했겠지요.

```cpp

int factorial(int n) {
if (n == 1) return 1;


return n * factorial(n - 1);
}
```



따라서 우리는 위 처럼 재귀 함수 호출이 끝나게 하기 위해선, n 이 1 일 때 따로 처리를 해주어야 합니다. 템플릿 역시 마찬가지로 n = 1 일 때 따로 처리할 수 있는데 바로 아래 처럼 템플릿 특수화를 이용해주면 됩니다.

```cpp

template <>
struct Factorial<1> {
static const int result = 1;
};
```



컴파일러는 Factorial<1> 타입의 경우만 따로 result = 1 로 만들어주게 되어서 재귀적 구조가 끝날 수 있게 해줍니다.


위 예제에서 볼 수 있듯이, 저기서 실질적으로 값을 가지는 객체는 아무 것도 없습니다. 즉, '720' 이라는 값을 가지고 있는 변수는 메모리 상에서 없다는 뜻입니다 (물론 cout 에서 출력 할 때 빼고). 저 화면에 나타나는 720 이라는 값은, 단순히 컴파일러가 만들어낸 Factorial<6> 이라는 타입을 나타내고 있을 뿐입니다.


사실 여러분 한테 factorial 을 계산하라는 함수를 만들라고 이야기 했다면 십중팔구 그냥 단순히 for 문으로 구현을 하였을 것입니다. 하지만 안타깝게도 템플릿으로는 for 문을 쓸 수 없기 때문에 위와 같은 재귀적 구조를 사용하였습니다. 한 가지 다행인 소식은 for 문으로 구현할 수 있는 모든 코드는 똑같이 템플릿 메타 프로그래밍을 이용해서 구현할 수 있습니다.


더군다나 위에서 보셨듯이 if 문 역시 템플릿 메타 프로그래밍으로 구현할 수 있습니다. 위 팩토리얼 예제에서도 알 수 있듯이, if 문 부분은 템플릿 특수화로 처리 가능합니다.


 TMP 를 왜 쓰는가?




한 가지 재미있는 사실은어떠한 C++ 코드도 템플릿 메타 프로그래밍 코드로 변환할 수 있다는 점입니다 (물론 엄청나게 코드가 길어지겠지만요). 게다가 템플릿 메타 프로그래밍으로 작성된 코드는 모두 컴파일 타임에 모든 연산이 끝나기 때문에 프로그램 실행 속도를 향상 시킬 수 있다는 장점이 있습니다 (당연히도 컴파일 시간은 엄청 늘어나게 됩니다).


하지만 그렇다고 해서 템플릿 메타 프로그래밍으로 프로그램 전체를 구현하는 일은 없습니다. 일단 템플릿 메타 프로그래밍은 매우 복잡합니다. 물론 위 Factorial 예제는 꽤 간단하였지만 아래 좀 더 복잡한 예제를 다루면서 왜 템플릿 메타 프로그래밍이 힘든 것인지 이야기 하겠습니다. 그 뿐만이 아니라, 템플릿 메타 프로그래밍으로 작성된 코드는 버그를 찾는 것이 매우 힘듭니다. 일단 기본적으로 '컴파일' 타임에 연산하는 것이기 때문에 디버깅이 불가능 하고, C++ 컴파일러에 특성 상 템플릿 오류 시에 엄청난 길이의 오류를 내뿜게 됩니다.


따라서 TMP 를 이용하는 경우는 꽤나 제한적이지만, 많은 C++ 라이브러리들이 TMP 를 이용해서 구현되었고 (Boost 라이브러리), TMP 를 통해서 컴파일 타임에 여러 오류들을 잡아낼 수 도 있고 (Ex. 단위나 통화 일치 여부등등) 속도가 매우 중요한 프로그램의 경우 TMP 를 통해서 런타임 속도도 향상 시킬 수 있습니다.


아래에서 좀 더 복잡한 예제를 가지고 그렇다면 TMP 를 어떻게 사용할 지에 대해서 자세히 알아보도록 하겠습니다.


컴퓨터 상에서 두 수의 최대공약수를 구하기 위해선 보통 유클리드 호제법을 이용합니다. 이는 매우 간단한데, 이 알고리즘을 일반적인 함수로 나타내자면 아래와 같습니다.

```cpp

int gcd(int a, int b)
{
if (b == 0) {
return a;
}


return  gcd(b, a % b);
}
```



따라서 이를 그대로 TMP 로 바꿔보면 아래와 같습니다. (여러분도 직접 해보세요!)

```cpp

#include <iostream>
using namespace std;


template <int X, int Y>
struct GCD
{
static const int value = GCD<Y, X%Y>::value;
};


template <int X>
struct GCD<X, 0>
{
static const int value = X;
};


int main()
{
cout << "gcd (36, 24) :: " << GCD<36, 24>::value << endl;
}
```



성공적으로 컴파일 하였다면





와 같이 잘 계산됩니다.


이 최대 공약수 계산 클래스를 만든 이유는, 바로 Ratio 클래스를 만들기 위함입니다. Ratio 클래스는 유리수(p/q 꼴로 쓸 수 있는 수) 를 오차 없이 표현해 주는 클래스 입니다. 물론 TMP 를 사용하지 않고 간단하게 클래스를 사용해서도 만들 수 있습니다. 하지만 일단 연습 삼아서 한 번 TMP 를 사용해서 만들어 보겠습니다.

```cpp



template <int N, int D = 1>
struct Ratio
{
typedef Ratio<N, D> type;
static const int num = N;
static const int den = D;
};
```



먼저 Ratio 클래스는 위 처럼 정의할 수 있겠습니다. 위 처럼 분자와 분모를 템플릿 인자로 받고, 타입을 나타내게 됩니다. 참고로 편의상

```cpp

typedef Ratio<N, D> type;
```



typedef 로 '자기 자신을 가리키는 타입' 을 넣어 주었습니다. 이는 마치 클래스에서의 this 와 비슷한 역할입니다.


그렇다면 이 Ratio 로 덧셈을 수행하는 템플릿을 만들어보겠습니다. 상당히 직관적입니다.

```cpp

template <class R1, class R2>
struct _Ratio_add
{
typedef Ratio <R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};
```

두 분수의 더한 결과를 Ratio 에 분자 분모로 전달하면 알아서 기약분수로 만들어줍니다.

```cpp

typedef Ratio <R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
```



그 후에, 그 덧셈 결과를 type 로 나타내게 됩니다. 따라서 덧셈을 수행하기 위해서는

```cpp

typedef _Ratio_add<rat, rat2>::type result;
```

이런 식으로 사용하면 되겠지요. 하지만 한 발 더 나아가서, 귀찮게 ::type 를 치고 싶지 않다고 해 봅시다. 다시 말해 Ratio_add 를 하면 그 자체로 두 Ratio 가 더해진 타입이 되는 것이지요. 이는 아래와 같이 구현할 수 있습니다.
```cpp
template <class R1, class R2>struct Ratio_add : _Ratio_add<R1, R2>::type {};


바로 _Ratio_add<R1, R2>::type 를 상속 받는 Ratio_add 클래스를 만들어 버리는 것입니다! 상당히 재미있는 아이디어입니다. 따라서 Ratio_add 는 마치 Ratio 타입 처럼 사용할 수 있게 됩니다. 전체 코드를 살펴 보자면 아래와 같습니다.

```cpp

#include <iostream>
#include <typeinfo>
using namespace std;


template <int X, int Y>
struct GCD
{
static const int value = GCD<Y, X%Y>::value;
};


template <int X>
struct GCD<X, 0>
{
static const int value = X;
};


template <int N, int D = 1>
struct Ratio
{
typedef Ratio<N, D> type;
static const int num = N; // 분자
static const int den = D; // 분모
};
template <class R1, class R2>
struct _Ratio_add
{
typedef Ratio <R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};


template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};




int main()
{
typedef Ratio<2, 3> rat;
typedef Ratio<3, 2> rat2;
typedef Ratio_add<rat, rat2> rat3;

cout << rat3::num << " / " << rat3::den << endl;


return 0;
}
```



성공적으로 컴파일 하였다면








와 같이 잘 계산되서 나옵니다.


참고로 C++11 부터 typedef 대신에 좀 더 직관적인 using 이라는 키워드를 사용할 수 있습니다.

```cpp

  typedef Ratio_add<rat, rat2> rat3;
using rat3 = Ratio_add<rat, rat2>;
```



위 두 문장 모두 동일한 의미를 가집니다. 다만 using 을 사용하였을 경우 typedef 보다 좀 더 이해하기가 쉽습니다. 특히, 함수 포인터의 경우 만일 void 를 리턴하고 int, int 를 인자로 받는 함수의 포인터의 타입을 func 라고 정의하기 위해서는 typedef 로

```cpp

        typedef void (*func)(int, int);
```



위와 같이 사용해야 했지만 (놀랍게도 func 이 새로 정의된 타입 이름이 됩니다) using 키워드를 사용하면

```cpp

using func = void(*) (int, int);
```



아래와 같이 매우 직관적으로 나타낼 수 있습니다. 따라서 위의 코드를 수정하자면;

```cpp

int main()
{
using rat = Ratio<2, 3>;
using rat2 = Ratio<3, 2>;


using rat3 = Ratio_add<rat, rat2>;
cout << rat3::num << " / " << rat3::den << endl;


return 0;
}
```

로 간단하고 좀 더 직관적으로 나타낼 수 있습니다. 다시 한 번 말하지만, 마치 Ratio 클래스의 객체를 생성한 것 같지만, 실제로 생성된 객체는 한 개도 없고, 단순히 타입들을 컴파일러가 만들어낸 것 뿐입니다.
마찬가지 방법으로 모든 사칙연산들을 구현하자면 아래와 같습니다.
```cpp
#include <iostream>using namespace std;
template <int X, int Y>struct GCD{static const int value = GCD<Y, X%Y>::value;};
template <int X>struct GCD<X, 0>{static const int value = X;};
template <int N, int D = 1>struct Ratio{private:const static int _gcd = GCD<N, D>::value;
public:typedef Ratio<N / _gcd, D / _gcd> type;static const int num = N / _gcd;static const int den = D / _gcd;};template <class R1, class R2>struct _Ratio_add{using type = Ratio <R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;};
template <class R1, class R2>struct Ratio_add : _Ratio_add<R1, R2>::type {};
template <class R1, class R2>struct _Ratio_subtract{using type = Ratio <R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;};
template <class R1, class R2>struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};
template <class R1, class R2>struct _Ratio_multiply{using type = Ratio <R1::num * R2::num , R1::den * R2::den>;};
template <class R1, class R2>struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};
template <class R1, class R2>struct _Ratio_divide{using type = Ratio < R1::num * R2::den, R1::den * R2::num>;};
template <class R1, class R2>struct Ratio_divide : _Ratio_divide<R1, R2>::type {};
int main(){using r1 = Ratio<2, 3>;using r2 = Ratio<3, 2>;
using r3 = Ratio_add<r1, r2>;cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << endl;
using r4 = Ratio_multiply<r1, r3>;cout << "13 / 6 * 2 /3 = " << r4::num << " / " << r4::den << endl;}
성공적으로 컴파일 하였다면





와 같이 나옵니다.


자 여기까지 따라 오셨다면 한 가지 궁금증이 들 것입니다.



"음 그래. Ratio 로 이용해서 재미있는 것을 할 수 있는거 같애. 컴파일 타임에 유리수 사칙 연산을 계산할 수 있다는 것도 좋아. 근데 도대체 저게 왜 필요하지?"


바로 다음 강좌에서 알아 보도록 하겠습니다!


 생각 해보기



1. N 번째 피보나치 수를 나타내는 TMP 를 만들어보세요. 참고로 피보나치 수는, N 번째 항이 N - 1 번째 항과 N - 2 번째 항의 합으로 정의되는 수 입니다. 참고로 1, 1, 2, 3, 5, ... 로 진행됩니다.(난이도 : 하)

```cpp

int main()
{
cout << "5 번째 피보나치 수 :: " << fib<5>::result << endl; // 5
}
```





2. TMP 를 사용해서 어떤 수가 소수인지 아닌지를 판별하는 프로그램을 만들어보세요. (난이도 : 상)참고로 이 문제는 다음 강좌에서 다룰 예정입니다!


```cpp

int main()
{
cout << boolalpha;
cout << "Is prime ? :: " << is_prime<2>::result << endl; // true
cout << "Is prime ? :: " << is_prime<10>::result << endl; // false
cout << "Is prime ? :: " << is_prime<11>::result << endl; // true
cout << "Is prime ? :: " << is_prime<61>::result << endl; // true
}
```





```warning
강좌를 보다가 조금이라도 궁금한 것이나 이상한 점이 있다면꼭 댓글을 남겨주시기 바랍니다. 그 외에도 강좌에 관련된 것이라면 어떠한 것도 질문해 주셔도 상관 없습니다. 생각해 볼 문제도 정 모르겠다면 댓글을 달아주세요.

현재 여러분이 보신 강좌는<<씹어먹는 C++ - <9 - 2. 템플릿 메타 프로그래밍 (Template Meta programming)>>> 입니다. 이번 강좌의모든 예제들의 코드를 보지 않고 짤 수준까지 강좌를 읽어 보시기 전까지 다음 강좌로 넘어가지 말아주세요

다음 강좌 보러가기

```


공감1sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++' 카테고리의 다른 글씹어먹는 C++ - <10 - 1. C++ STL - 벡터(vector), 리스트(list), 데크(deque)>(2)2017.07.04씹어먹는 C++ - <9 - 3. 템플릿 메타 프로그래밍 2>(8)2017.07.02씹어먹는 C++ - <9 - 2. 템플릿 메타 프로그래밍 (Template Meta programming)>(2)2017.06.26씹어먹는 C++ - <9 - 1. 코드를 찍어내는 틀 - C++ 템플릿(template)>(10)2017.04.07씹어먹는 C++ - <8 - 2. Excel 만들기 프로젝트 2부>(6)2016.07.19씹어먹는 C++ - <8 - 1. Excel 만들기 프로젝트 1부>(0)2016.07.18

