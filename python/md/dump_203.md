----------------
title : 씹어먹는 C++ - <5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩>
cat_title: 5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩
next_page : 204
publish_date : 2013-08-29
tex_title : 잡다한 연산자들의 오버로딩
path : /C++
--------------

이번 강좌에서는

* 멤버 함수가 아닌 연산자 함수 오버로딩
* 입출력 연산자 오버로딩 (정확히 보면 `<<, >>` 연산자)
* 첨자 연산자 `[]` 오버로딩
* 타입 변환 연산자 오버로딩
* 증감 연산자 `++, --` 오버로딩

에 대해 다룹니다.



![](/img/ChewingCpplogo.png)



안녕하세요 여러분. 잘 지내셨나요? 올해 안으로 C++ 강좌를 끝내기 위한 노력의 일환으로 강좌를 열심히 업로드 하려고 노력중인 Psi 입니다. 그래도 강좌를 읽으시는 여러분들은 꼼꼼히 읽어보시고, 궁금하신 점들은 꼭 댓글로 남겨 주시거나 메일로 질문해 주시기 바랍니다 :)


지난 강좌에서, 마지막에 다음과 같은 문제점을 지적하였습니다.

```cpp-formatted
a = a + "-1.1 + i3.923";  // ①
```

는 잘 컴파일 되서 실행되지만

```cpp-formatted
a = "-1.1 + i3.923" + a;  // ②
```

는 컴파일 되지 않습니다. 왜냐하면, ① 의 경우 `a.operator+("i3.923");` 으로 변환될 수 있지만 ② 는 그렇지 못하기 때문이죠. 하지만, 원칙적으로  클래스를 사용하는 사용자의 입장에서① 이 된다면 당연히② 도 수행될 수 있어야 연산자 오버로딩을 하는 명분이 생깁니다. 다행 스럽게도, 사실 컴파일러는 이항 연산자 (피연산자를 두 개를 취하는 연산자 `-` 예를 들어서 `+, -, *, /, ->, =` 등이 이항 연산자 이다) 를 다음과 같은 두 개의 방식으로 해석합니다.


어떤 임의의 연산자 `@` 에 대해서, `a@b` 는\sidenote{C++ 에 @ 연산자는 없지만, 여기서 '임의의 연산자' 를 나타내기 위해 잠시 사용하겠습니다.}

```cpp-formatted
*a.operator@(b);
*operator@(a, b);
```

두 가지 방법으로 해석됩니다.\sidenote{참고로 이는 일부 연산자들에 대해서는 해당되지 않는데 대표적으로 [] 연산자 (첨자), -> 연산자 (멤버 접근), 대입 연산자 (=), () 함수 호출 연산자들의 경우 멤버 함수로만 존재할 수 있습니다. 즉, 따로 멤버 함수가 아닌 전역 함수로 뺄 수 없다는 의미 입니다. 따라서 이들 함수를 오버로딩 할 때 주의하시기 바랍니다.}

즉, 컴파일 시에 둘 중 하나의 가장 가까운 것을 택해서 처리됩니다. `a.operator@(b)` 에서의 `operator@` 는 `a` 의 클래스의 멤버 변수로써 사용되는 것이고, `operator@(a,b)` 에서의 `operator@` 는 그냥 일반적인 함수를 의미하게 됩니다. 따라서 이를 처리하기 위해 함수를 정의하여 봅시다.

```cpp-formatted
Complex operator+(const Complex& a, const Complex& b) {
  return a + b;
}
```

우리의 또 다른 `operator+` 는 두 개의 `const Complex&` 타입의 인자 `a,b` 를 받게 됩니다. 앞에서도 말했지만 컴파일러는 정확히 일치 하지 않는 경우, 가장 가까운 *가능한* 오버로딩 되는 함수를 찾게 되는데, 마침 우리에게는 `Complex(const char *)` 타입의 생성자가 있으므로,

```cpp-formatted
"-1.1 + i3.923" + a;
```

는

```cpp-formatted
operator+(Complex("-1.1 + i3.923"), a);
```

가 되어서 잘 실행되게 됩니다. 실제로 컴파일 해보면

```cpp
#include <iostream>
#include <cstring>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex operator+(const Complex& c) const;
  Complex& operator+=(const Complex& c);

  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 :) 

  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex operator+(const Complex& a, const Complex& b) {
  return a.operator+(b);
}

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}

Complex& Complex::operator+=(const Complex& c) {
  (*this) = operator+(c);
  return *this;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  a.println();
}
```

성공적으로 컴파일 하였다면

```exec
( -1.1 , 3.923 ) 
```

와 같이 잘 실행됨을 알 수 있습니다. 그런데, 아마 `operator+` 를 유심히 살펴보신 분들은 조금 특이한 점을 발견하실 수 있을 것입니다.

```cpp-formatted
Complex operator+(const Complex& a, const Complex& b) {
  return a.operator+(b);
}
```

왜 굳이 귀찮게 a 의 operator+ 를 명시적으로 호출하였을 까요? 그냥 `a + b` 을 하면 되는 것 아닐까요? 한 번 아래와 같이 수정해서 컴파일을 해봅시다.

```cpp-formatted
Complex operator+(const Complex& a, const Complex& b) { return a + b; }
```

위 코드를 컴파일 시에 다음과 같은 경고 메세지를 볼 수 있을 것입니다.

```compiler-warning
test.cc: In function ‘Complex operator+(const Complex&, const Complex&)’:
test.cc:30:12: error: ambiguous overload for ‘operator+’ (operand types are ‘const Complex’ and ‘const Complex’)
   30 |   return a + b;
      |          ~ ^ ~
      |          |   |
      |          |   const Complex
      |          const Complex
test.cc:15:11: note: candidate: ‘Complex Complex::operator+(const Complex&) const’
   15 |   Complex operator+(const Complex& c) const;
      |           ^~~~~~~~
test.cc:29:9: note: candidate: ‘Complex operator+(const Complex&, const Complex&)’
   29 | Complex operator+(const Complex& a, const Complex& b) {
      |         ^~~~~~~~
```

즉, `a + b` 에서 컴파일러가 `a.operator+(b)` 을 호출해야 할지, 아니면 우리가 새로 정의한 `operator+(a,b)` 가 호출 할지 구별할 수 없다는 문제 입니다. 따라서 우리는 다음과 같이 강제로 멤버 함수 `operator+` 를 호출하도록 지정해야 합니다.

```cpp-formatted
Complex operator+(const Complex& a, const Complex& b) { return a.operator+(b); }
```

마찬가지 이유에서 `operator+=` 도 멤버 함수로 정의되어 있는 `operator+` 을 호출할 수 있도록 살짝 바꿔줘야 합니다.

```cpp
Complex& Complex::operator+=(const Complex& c) {
  (*this) = operator+(c);
  return *this;
}
```

따라서 위 처럼 멤버 함수인 `operator+` 를 강제로 호출하게 됩니다. 만일 이전 처럼 `(*this) + c` 를 하였다면, 앞서 보았던 동일한 컴파일러 오류 메세지를 보게 될 것입니다.

###  입출력 연산자 오버로딩 하기

아마도, 눈치를 채신 분들이 있겠지만 우리가

```cpp-formatted
std::cout << a;
```

라고 하는 것은 사실 `std::cout.operator<<(a)` 를 하는 것과 동일한 명령이었습니다. 즉, 어떤 `std::cout` 이라는 객체에 멤버 함수 `operator<<` 가 정의되어 있어서 `a` 를 호출하게 되는 것이지요. 그런데, `std::cout` 이 `int` 나 `double` 변수, 심지어 문자열 까지 자유 자재로 `operator<<` 하나로 출력할 수 있었던 이유는 그 많은 수의 `operator<<` 함수들이 오버로딩 되어 있다는 뜻입니다.


실제로 우리가 `include` 하던 `iostream` 의 헤더파일의 내용을 살펴보면 (실제로는 `ostream` 에 정의되어 있습니다. 다만 `iostream` 이 `ostream` 을 include 하고 있음) `ostream` 클래스에

```cpp-formatted
ostream& operator<<(bool val);
ostream& operator<<(short val);
ostream& operator<<(unsigned short val);
ostream& operator<<(int val);
ostream& operator<<(unsigned int val);
ostream& operator<<(long val);
ostream& operator<<(unsigned long val);
ostream& operator<<(float val);
ostream& operator<<(double val);
ostream& operator<<(long double val);
ostream& operator<<(void* val);
```

와 같이 엄청난 수의 `operator<<` 가 정의되어 있는 것을 알 수 있습니다. 이들 덕분에 우리가 편하게 인자의 타입에 관계없이 손쉽게 출력을 사용할 수 있게 되는 것이지요.

그렇다면 한 번 우리의 `Complex` 클래스에서 `ostream` 클래스의 연산자 `operator<<` 를 자유롭게 사용할 수 있으면 어떨까요. 예를 들어서

```cpp-formatted
Complex c;
std::cout << c;
```

를 하게 되면 마치

```cpp-formatted
Complex c;
c.println();
```

을 한 것과 같은 효과를 내도록 말이지요. 당연하게도, `ostream` 클래스에 `operator<<` 멤버 함수를 새롭게 추가하는 것은 불가능 합니다. 이를 위해서는 표준 헤더파일의 내용을 수정해야 하기 때문이죠. 

따라서, 우리는 `ostream` 클래스에 `Complex` 객체를 오버로딩하는 `operator<<` 연산자 함수를 추가할 수는 없습니다.

하지만 우리는 클래스의 연산자 함수를 추가하는 방법으로, 멤버 함수를 사용하는 것 말고도 한 가지 더 있다는 것을 알고 있지요. 바로 `ostream` 클래스 객체와 `Complex` 객체 두 개를 인자로 받는 전역 `operator<<` 함수를 정의하면 됩니다.

```cpp-formatted
std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}
```

참고로 `opreator<<` 에서 `ostream&` 타입을 리턴하는 이유는 다음과 같은 문장을 처리할 수 있기 위해서입니다.

```cpp-formatted
std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
```

하지만 위 `operator<<` 의 경우 한 가지 문제가 있는데 바로 이 `operator<<` 에서 `c.real` 과 `c.img` 에 접근할 수 없다는 점입니다. 왜냐하면 `real` 과 `img` 모두 `Complex` 클래스의 `private` 멤버 변수들이기 때문이죠.

따라서 이를 해결하기 위해 세 가지 방법을 고려할 수 있습니다.

1. 그냥 `real` 과 `img` 를 `public` 으로 바꾼다.
2. `Complex` 에 `print(std::ostream& os)` 와 같은 멤버 함수를 추가한 뒤, 이를 `operator<<` 에서 호출한다.
3. 위 `operator<<` 를 `friend` 로 지정한다.

흠 첫 번째 방법은 그닥 권장되지 않는 방법입니다. 구현 디테일은 최대한 숨기는 것이 좋습니다. 두 번째 방법은 나름 괜찮은 방법이기는 한데, 세 번째 방법은 어떨까요? `friend` 로 지정한다는 것이 무슨 말일까요?

### friend 키워드

`friend` 키워드는 클래스 내부에서 **다른 클래스나 함수들을 friend** 로 정의할 수 있는데, `friend` 로 정의된 클래스나 함수들은 원래 클래스의 private 로 정의된 변수나 함수들에 접근할 수 있습니다.

아래 간단한 예시를 살펴봅시다.

```cpp
class A {
 private:
  void private_func() {}
  int private_num;

  // B 는 A 의 친구!
  friend class B;

  // func 은 A 의 친구!
  friend void func();
};

class B {
 public:
  void b() {
    A a;

    // 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
    a.private_func();
    a.private_num = 2;
  }
};

void func() {
  A a;

  // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
  // 가능하다.
  a.private_func();
  a.private_num = 2;
}

int main() {}
```

그리고 컴파일도 잘 됨을 알 수 있습니다.

```cpp
  // B 는 A 의 친구!
  friend class B;

  // func 은 A 의 친구!
  friend void func();
```

위 처럼 클래스 `B` 와 `void` 함수 `func` 을 `A` 의 친구라고 선언하고 있습니다. 이렇게 친구라고 선언하게 되면, `B` 와 `func` 안에서는 `A` 의 모든 `private` 멤버 함수들과 멤버 변수들에 대한 접근 권한을 부여하게 됩니다. **정말 친한 친구 사이라 보면 됩니다.**

한 가지 재미있는 점은 이 친구 관계가 **짝사랑** 과 같다는 점입니다. 즉 위 경우 `B` 는 `A` 의 모든 `private` 들을 볼 수 있지만, `B` 안에서 `A` 를 `friend` 로 지정하지 않는 이상, `A` 는 `B` 의 `private` 개체들에 접근할 수 없습니다.

```cpp-formatted
class A {
 private:
  int x;

  friend class B;
};

class B {
 private:
  int y;
};
```

쉽게 말해 위 경우 `B` 에는 `A` 가 `friend` 라고 지정하지 않았으므로, `A` 는 `B` 의 `private` 변수인 `int y` 에 접근할 수 없게 됩니다. 안타까운 관계이지요.

자 그러면 본론으로 돌아와서 `ostream& operator<<` 안에서 `c` 의 `real` 과 `img` 필드들에 접근하기 위해선 아래와 같이 `friend` 로 선언하면 됩니다.

```cpp-formatted
friend ostream& operator<<(ostream& os, const Complex& c);
```

위와 같이 `friend` 선언을 해주시면 됩니다. 비슷한 방법으로 `Complex` 객체 `c` 에 대해 `cin >> c;` 와 같은 작업을 할 수 있습니다. 다만, 이번에는 `cin` 은 `istream` 객체이고, `opreator>>` 를 오버로딩 해야 된다는 점이 다를 뿐이지요.

```cpp
#include <iostream>
#include <cstring>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex operator+(const Complex& c) const;
  Complex& operator+=(const Complex& c);

  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 :) 

  // 아래 함수는 Complex 의 멤버 함수를 정의한 것이 *아니다*
  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}

Complex operator+(const Complex& a, const Complex& b) {
  return a.operator+(b);
}

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}

Complex& Complex::operator+=(const Complex& c) {
  (*this) = operator+(c);
  return *this;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
a 의 값은 : ( -1.1 , 3.923 )  이다. 
```

와 같이 잘 실행됨을 알 수 있습니다.

```lec-warning
물론 무분별하게 `friend` 키워드를 남발하는 것은 썩 권장하지 않습니다. 왜냐하면 `friend` 키워드는 해당 함수나 클래스에게 자기 자신의 모든 `private` 멤버 함수와 변수들을 공개하기 때문이지요. 따라서 **구현 디테일은 최대한 숨기라** 는 원칙을 지키기가 힘들어집니다. 물론 절대 `friend` 를 쓰지 말라는 것은 아니고, 테스트 코드 작성과 같이 `friend` 를 유용하게 사용할 수 있는 경우가 종종 있습니다.
```

###  첨자 연산자 (operator[])


이번에는 배열에서 원소를 지정할 때 사용되는 첨자 연산자 `[]` 를 오버로딩 해보도록 합시다.\sidenote{참고로 왜 첨자 연산자라고 부르냐면, 배열의 원소를 지정할 때 [] 안에 넣는 수를 첨자(subscript) 라고 부르기 때문입니다} 우리가 전에 만들었던 `MyString` 클래스에서 개개의 문자에 접근하기 위해 `[]` 를 지원해주어야만 하는데요, `[]` 를 이용해서 `str[10]` 과 같이 10 번째 문자에 정확하게 접근할 수 있게 됩니다.

여기서 그렇다면 `MyString` 클래스의 `operator[]` 를 추가해보도록 합시다. `operator[]` 함수는 자명하게도 인자로 몇 번째 문자인지, `int` 형 변수를 인덱스로 받게 됩니다. 따라서 `operator[]` 는 다음과 같은 원형을 가집니다.

```cpp-formatted
char& operator[](const int index);
```

`index` 로 `[]` 안에 들어가는 값을 받게 됩니다. 그리고 `char&` 를 인자로 리턴하는 이유는

```cpp-formatted
str[10] = 'c';
```

와 같은 명령을 수행하기 때문에, 그 원소의 레퍼런스를 리턴하게 되는 것이지요. 실제로 `opreator[]` 의 구현은 아래와 같이 매우 단순합니다.

```cpp-formatted
char& MyString::operator[](const int index) { return string_content[index]; }
```

위와 같이 `index` 번째의 `string_content` 를 리턴해서, `operator[]` 를 사용하는 사용자가, 이의 레퍼런스를 가질 수 있게 되지요. 그렇다면, 전체 소스를 한 번 살펴보도록 합시다.

```cpp-formatted
#include <iostream>
#include <cstring>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;  // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length();

  void print() const;
  void println() const;

  char& operator[](const int index);
};

MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}
MyString::MyString(const char* str) {
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() { return string_length; }
void MyString::print() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}
void MyString::println() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
  std::cout << std::endl;
}

char& MyString::operator[](const int index) { return string_content[index]; }

int main() {
  MyString str("abcdef");
  str[3] = 'c';

  str.println();
}
```

성공적으로 컴파일 하였다면

```exec
abccef
```

와 같이 제대로 `str[3]` 의 'd' 를 'c' 로 잘 바꾸었음을 알 수 있습니다.


이 정도만 하면 `MyString` 클래스는 거의 왠만한 문자열 클래스 뺨치게 완전한 모습을 갖추었다고 볼 수 있습니다. 문자열 삽입, 삭제, 대입 뿐만이 아니라 개개의 문자의 조작 까지 원활하게 수행할 수 있는 훌륭한 문자열 클래스라고 할 수 있지요.



###  int Wrapper 클래스 - 타입 변환 연산자

`Wrapper` 라는 것은 원래 우리가 흔히 음식을 포장할 때 '랩(wrap)으로 싼다' 라고 하는 것 처럼, '포장지' 라는 의미의 단어 입니다. 즉 `Wrapper` 클래스는 무언가를 포장하는 클래스라는 의미인데, C++ 에서 프로그래밍을 할 때 어떤 경우에 기본 자료형들을 객체로써 다루어야 할 때가 있습니다. 이럴 때, 기본 자료형들 (`int, float` 등등) 을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것을 `Wrapper` 클래스를 이용한다는 뜻 입니다.

즉, `int` 자료형을 감싸는 int Wrapper 클래스 `Int` 는 다음과 같이 구성할 수 있습니다.

```cpp-formatted
class Int
{
  int data;
  // some other data

 public:
  Int(int data) : data(data) {}
  Int(const Int& i) : data(i.data) {}
};
```

위 `Int` 클래스에 `int` 형 자료형을 보관하는 `data` 라는 변수를 정의해 놓았는데, 이렇게 한다면 `int` 형 데이터를 저장하는 객체로 `Int` 클래스를 사용할 수 있을 것입니다. 우리는 이 `Int` 객체가 `int` 의 `Wrapper` 클래스의 객체인 만큼, `int` 와 정확히 똑같이 작동하도록 만들고 싶습니다. 다시 말해서 다음과 같은 명령을 내려도 아무 하자 없이 잘 실행될 수 있도록 말이지요.

```cpp-formatted
Int x = 3;      // Wrapper 객체
int a = x + 4;  // 그냥 평범한 int 형 변수 a
```

이를 잘 수행하기 위해서라면, 여태까지 연산자 오버로딩을 열심히 배워오신 여러분 생각이라면


그렇다면 `int` 변수에 사용되는 모든 연산자 함수들을 만들어주면 되겠군!


이라고 생각이 들 것입니다. 물론, 이렇게 해도 잘 작동하는 `Wrapper` 클래스를 만들 수 있을 것입니다. 하지만, 그 수 많은 연산자들을 일일히 오버로딩을 하는 것은 정말로 고통스러운 일이 아닐 수 없습니다.

왜 이러한 일이 고통스러운 것이냐면, `Complex` 클래스를 만들 때만 해도, `Complex` 객체에서 + 나 - 연산자가 하는 일 자체가 `int` 변수 끼리 하는 일과 완전히 달랐기 때문에 반드시 `operator+` 나 `operator-` 등을 만들어주어야만 했을 것입니다. 하지만 이 `int Wrapper` 클래스 객체끼리 하는 일은 그냥 단순히 `int` 형 변수 끼리 하는 일과 정확히 똑같기 때문에 굳이 이미 제공하는 기능을 다시 만들어야 한다는 점이지요.


그렇다면, 그냥 이 `Wrapper` 클래스의 객체를 마치 '`int` 형 변수' 라고 컴파일러가 생각할 수 는 없는 것일까요. 물론 가능합니다. 왜냐하면 우리에게는 타입 변환 연산자가 있기 때문이지요. 만일 컴파일러가 이 클래스의 객체를 `int` 형 변수로 변환할 수 있다면, 비록 `operator+` 등을 정의하지 않더라도 컴파일러가 가장 이 객체를 `int` 형 변수로 변환 한 다음에 `+` 를 수행할 수 있기 때문입니다.


타입 변환 연산자는 다음과 같이 정의합니다.

```info
operator (변환 하고자 하는 타입) ()
```



예를 들어 우리의 `int Wrapper` 클래스의 경우 다음과 같은 타입 변환 연산자를 정의할 수 있지요.

```cpp-formatted
operator int()
```



한 가지 주의할 점은, 생성자 처럼 함수의 리턴 타입을 써주시면 안됩니다. 이는 C++ 에서 변환 연산자를 정의하기 위한 언어 상의 규칙이라고도 볼 수 있습니다. 그렇게 된다면, 우리의 `int` 변환 연산자는 다음과 같이 간단하게 구성할 수 있겠지요.

```cpp-formatted
operator int() { return data; }
```



그냥 단순히 `data` 를 리턴해주면 됩니다. 그렇게 된다면 우리의 `Wrapper` 클래스의 객체를 '읽는' 데에는 아무런 문제가 없게 됩니다. 왜냐하면 컴파일러 입장에서 적절한 변환 연산자로 `operator int` 를 찾아서 결국 `int` 로 변환해서 처리하기 때문이지요. 다만 문제는 '대입' 시에 발생하는데, 다행이도 디폴트 대입 연산자가 이 역시 알아서 잘 처리할 것이기 때문에 걱정 안하셔도 됩니다.

```cpp-formatted
#include <iostream>

class Int {
  int data;
  // some other data

 public:
  Int(int data) : data(data) {}
  Int(const Int& i) : data(i.data) {}

  operator int() { return data; }
};
int main() {
  Int x = 3;
  int a = x + 4;

  x = a * 2 + x + 4;
  std::cout << x << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
21
```


와 같이 `Int` 객체가 `int` 변수 처럼 정확히 동일하게 작동되고 있음을 알 수 있습니다.

###  전위/후위 증감 연산자


마지막으로 살펴볼 연산자로 우리가 흔히 `++, --` 로 사용하는 전위/후위 증감 연산자들 입니다. 아마, 이 연산자를 오버로딩 하기 전에 한 가지 궁금증이 드셨을 텐데요, 과연 C++ 컴파일러는 전위/후위 증감을 구분 해서 오버로딩 시켜주냐 입니다. 다시 말해;

```cpp-formatted
a++;
++a;
```

위 두 `++` 연산자들을 구분해서 오버로딩을 시켜주냐 이말이죠. 두 연산자 모두 `operator++` 이기 때문입니다. 

C++ 언어에서는 다음과 같은 재미있는 방법으로 구분합니다. 일단 C++ 언어에서는 다음과 같은 재미있는 방법으로 구분합니다. 일단;

```cpp-formatted
operator++();
operator--();
```

은 전위 증감 연산자 (`++x, --x`) 를 오버로딩 하게 됩니다. 그렇다면 후위 증감 연산자 (`x++, x--`) 는 어떨까요. 바로

```cpp-formatted
operator++(int x);
operator--(int x);
```

로 구현하게 됩니다. 물론 인자 `x` 는 아무런 의미가 없습니다. 단순히 컴파일러 상에서 전위와 후위를 구별하기 위해 `int` 인자를 넣어주는 것이지요.

실제로 `++` 을 구현하면서 인자로 들어가는 값을 사용하는 경우는 없습니다. 따라서 그냥 

```cpp-formatted
operator++(int);
operator--(int);
```

와 같이 해도 무방합니다.

한 가지 중요한 점은, 전위 증감 연산의 경우 **값이 바뀐 자기 자신** 을 리턴해야 하고, 후위 증감의 경우 **값이 바뀌기 이전의 객체** 를 리턴해야 된다는 점입니다.

왜냐하면 전위와 후위 연산자가 어떻게 다른지 생각해봤을 때

```cpp
int x = 1;
func(++x);
```

를 하게 되면 `func` 에는 2 가 인자로 전달되지만,

```cpp
int x = 1;
func(x++);
```

의 경우 `func` 에 1 이 인자로 전달되고, 나중에 `x++` 이 실행되어서 `x` 가 2 가 되기 때문이지요.

따라서 이를 감안한다면 아래와 같은 꼴이 됩니다.

```cpp
A& operator++() {
  // A ++ 을 수행한다.
  return *this;
}
```

전위 연산자는 간단히 `++` 에 해당하는 연산을 수행한 후에 자기 자신을 반환해야 합니다. 반면에 후위 연산자의 경우

```cpp
A operator++(int) {
  A temp(A);
  // A++ 을 수행한다.
  return temp;
}
```

`++` 을 하기 전에 객체를 반환해야 하므로, `temp` 객체를 만들어서 이전 상태를 기록한 후에, `++` 을 수행한 뒤에 `temp` 객체를 반환하게 됩니다.

따라서 **후위 증감 연산의 경우 추가적으로 복사 생성자를 호출하기 때문에 전위 증감 연산보다 더 느립**니다!

그렇다면 아래와 같이 예제를 살펴봅시다.

클래스 자체에는 별거 없지만 전위와 후위가 호출될 때를 구별하기 위해 메세지를 출력하도록 하였습니다.

```cpp-formatted
#include <iostream>


class Test {
  int x;

 public:
  Test(int x) : x(x) {}
  Test(const Test& t) : x(t.x) {}

  Test& operator++() {
    x++;
    std::cout << "전위 증감 연산자" << std::endl;
    return *this;
  }

  // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
  // 받지만 실제로는 아무것도 전달되지 않는다.
  Test operator++(int) {
    Test temp(*this);
    x++;
    std::cout << "후위 증감 연산자" << std::endl;
    return temp;
  }

  int get_x() const {
    return x;
  }
};

void func(const Test& t) {
  std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
  Test t(3);

  func(++t); // 4
  func(t++); // 4 가 출력됨
  std::cout << "x : " << t.get_x() << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
전위 증감 연산자
x : 4
후위 증감 연산자
x : 4
x : 5
```

와 같이 제대로 골라서 실행되고 있음을 알 수 있습니다.


###  정리


연산자 오버로딩에 대해 다루면서 몇 가지 중요한 포인트 들만 따로 정리해보자면;

* 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩 하는 것이 좋습니다. (예를 들어 `Complex` 의 `operator+(const Complex&, const Complex&) const` 와 같이 말입니다.)
* 두 개의 객체 사이의 이항 연산자 이지만 한 객체만 값이 바뀐다던지 등의 동등하지 않는 이항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다. (예를 들어서 `operator+=` 는 이항 연산자 이지만 `operator+=(const Complex&)` 가 낫다)
* 단항 연산자는 멤버 함수로 오버로딩 하는 것이 좋습니다 (예를 들어 `operator++` 의 경우 멤버 함수로 오버로딩 합니다)
* 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 합니다 (강좌 앞 부분 참고)
  

자, 이것으로 가장 많이 사용되는 연산자 함수들에 대해 알아보았습니다. 이제 슬슬 C++ 언어의 강력함이 느껴지시나요? 다음 강좌에서는 여태까지 배운 내용들을 총 망라하는 조그마한 프로젝트를 해볼려고 합니다. 그 프로젝트는 아래 '생각해보기'에 나와 있는데요, 다음 강좌를 보기 전 까지 아래 문제를 한 번 해결해 보시기 (해결은 못해도 최소한 노력은 하시기) 바랍니다.



###  생각해보기


#### 문제 1

`N` 차원 배열을 제공하는 클래스를 만들어보세요. 이는 여러분이 여태까지 배운 내용을 시험할 것입니다. 참고로, 원소에 접근하기 위해서는 `a[1][2][3]` 과 같은 방법으로 접근하겠지요. 다만 `N` 차원 배열이기 때문에 (N은 객체 생성시에 사용자가 입력합니다) 2 차원 배열은 `a[1][2], 3` 차원 배열은 `a[1][2][3]` 과 같은 방식으로 접근할 것입니다. (난이도 : 最上)

#### 문제 2

영어를 잘하시는 분들은 연산자 오버로딩에 관해 정리해 놓은 [다음 글](http://stackoverflow.com/questions/4421706/operator-overloading)을 읽어보시기를 추천합니다. 참고로 이 글에서 다루지만 본 강좌에서는 다루지 않는 일부 내용들은 아직 배운 내용이 아니라 생략한 것이므로 너무 걱정하지 마시고 복습하는 느낌으로 천천히 읽어보시면 좋습니다. (난이도 : 中)

##@ chewing-cpp-end