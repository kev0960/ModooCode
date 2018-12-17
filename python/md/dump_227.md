----------------
title : 씹어먹는 C++ - <11 - 1. 우측값 레퍼런스와 이동 생성자>
cat_title: 11 - 1. 우측값 레퍼런스와 이동 생성자
next_page : 228
--------------

이번 강좌에서는
* 복사 생략 (Copy elision)

* 우측값 레퍼런스 (rvalue reference)

* 이동 생성자 (move constructor)

![](/img/ChewingCpplogo.png)


안녕하세요 여러분! 지난번 `STL` 강좌는 어떠셨나요? 이번 강좌에서는 C++ 11 에서 추가된 우측값 레퍼런스에 대해서 다루어보도록 하겠습니다. 처음에 보면 약간 생소할 수 있는데 천천히 읽어보시기 바랍니다.



###  복사 생략(Copy `Elision)`




아래 코드를 실행해보면 결과가 어떻게 나올까요?
```cpp-formatted
#include <iostream>

using namespace std;

class A {
  int data_;

 public:
  A(int data) : data_(data) { cout << "일반 생성자 호출!" << endl; }

  A(const A& a) : data_(a.data_) {
    data_ = a.data_;
    cout << "복사 생성자 호출!" << endl;
  }
};

int main() {
  A a(1);  // 일반 생성자 호출
  A b(a);  // 복사 생성자 호출

  // 그렇다면 이것은?
  A c(A(2));
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F9936A83359A3A1A72E5EDB)



와 같이 나옵니다.


뭔가 예상했던 것과 조금 다르지요?

```cpp-formatted
// 그렇다면 이것은?
A c(A(2));
```



이 부분에서 "일반 생성자 호출!" 한번 만 출력되었습니다. 아마 정석대로 였다면,

```cpp-formatted
A(2)
```



를 만들면서 "일반 생성자 호출!" 이 한 번 출력되어야 되고, 생성된 임시 객체로 `c` 가 복사 생성되면서 "복사 생성자 호출!" 이 될 것이기 때문이지요. 그런데 왜 "일반 생성자 호출!" 한 번 밖에 출력되지 않았을 까요? 복사 생성자가 왜 불리지 않았을까요?


사실 생각해보면 굳이 임시 객체를 한 번 만들고, 이를 복사 생성할 필요가 없습니다. 어차피 `A(2)` 로 똑같이 `c` 를 만들거면, 차라리 `c` 자체를 `A(2)` 로 만들어진 객체로 해버리는 것이랑 똑같기 때문이지요.



따라서 똑똑한 컴파일러는 복사 생성을 굳이 수행하지 않고, 만들어진 임시로 만들어진 `A(2)` 자체를 `c` 로 만들어버립니다. 이렇게, 컴파일러 자체에서 복사를 생략해 버리는 작업을 복사 생략(copy `elision)` 이라고 합니다.


컴파일러가 복사 생략을 하는 경우는 (함수의 인자가 아닌) 함수 내부에서 생성된 객체를 그래도 리턴할 때, 수행할 수 있습니다. 물론 C++ 표준을 읽어보면 반드시 복사 생략을 해라 라는 식이 아니라, '복사 생략을 할 수 도 있다' 라는 뜻으로 써 있습니다. 즉, 경우에 따라서는 복사 생략을 해도 되는 경우에, 복사 생략을 하지 않을 수도 있다는 뜻이지요.


이전에 만들어 놓았던 `MyString` 클래스를 다시 살펴보도록 해봅시다.

```cpp-formatted
#include <iostream>
using namespace std;

class MyString {
  char *string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;  // 현재 할당된 용량

 public:
  MyString();

  // 문자열로 부터 생성
  MyString(const char *str);

  // 복사 생성자
  MyString(const MyString &str);

  void reserve(int size);
  MyString operator+(const MyString &s);
  ~MyString();

  int length() const;

  void print();
  void println();
};

MyString::MyString() {
  cout << "생성자 호출 ! " << endl;
  string_length = 0;
  memory_capacity = 0;
  string_content = NULL;
}

MyString::MyString(const char *str) {
  cout << "생성자 호출 ! " << endl;
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
  cout << "복사 생성자 호출 ! " << endl;
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char *prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    if (prev_string_content != NULL) delete[] prev_string_content;
  }
}
MyString MyString::operator+(const MyString &s) {
  MyString str;
  str.reserve(string_length + s.string_length);
  for (int i = 0; i < string_length; i++)
    str.string_content[i] = string_content[i];
  for (int i = 0; i < s.string_length; i++)
    str.string_content[string_length + i] = s.string_content[i];
  str.string_length = string_length + s.string_length;
  return str;
}
int MyString::length() const { return string_length; }
void MyString::print() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];
}
void MyString::println() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];

  cout << endl;
}

int main() {
  MyString str1("abc");
  MyString str2("def");
  cout << "-------------" << endl;
  MyString str3 = str1 + str2;
  str3.println();
}
```



성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F99E2F6505AB50C7A30ED98)



와 같이 나옵니다.

```cpp-formatted
MyString str3 = str1 + str2;
```



이 부분에서 두 개의 문자열을 더한 새로운 문자열로 `str3` 를 생성하고 있습니다.

```cpp-formatted
MyString MyString::operator+(const MyString &s) {
  MyString str;
  str.reserve(string_length + s.string_length);
  for (int i = 0; i < string_length; i++)
    str.string_content[i] = string_content[i];
  for (int i = 0; i < s.string_length; i++)
    str.string_content[string_length + i] = s.string_content[i];
  str.string_length = string_length + s.string_length;
  return str;
}
```



위 함수가 `str1 + str2` 를 실행 시에 호출되는데, 먼저 빈 `MyString` 객체인 `str` 을 생성합니다. (생성자 호출! 출력됨) 그 후에, `reserve` 함수를 이용해서 공간을 할당하고, `str1` 과 `str2` 를 더한 문자열을 복사하게 됩니다.


이렇게 리턴된 `str` 은 `str3` 을 생성하는데 전달되어서, `str3` 의 복사 생성자가 호출 됩니다.



하지만, 이미 예상했겠지만, 굳이 `str3` 의 복사 생성자를 또 호출할 필요가 없습니다. 왜냐하면, 어차피 똑같이 복사해서 생성할 것이면, 이미 생성된 `(str1 + str2)` 가 리턴한 객체를 `str3` 셈 치고 사용하면 되기 때문이지요. 이전의 예제에서는 컴파일러가 불필요한 복사 생성자 호출을 복사 생략을 통해 수행하지 않았지만, 이 예제의 경우, 컴파일러가 복사 생략 최적화를 수행하지 않았습니다.


위 과정을 그림으로 간단히 살펴보면 아래와 같습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F996BBA465AB638B019DAE7)



만약에 `str1` 과 `str2` 의 크기가 엄청 컸다면 어떨까요? 쓸데 없는 복사를 두 번 하는데 상당한 자원이 소모될 것입니다.


그렇다면 이러한 문제를 C++ 에서는 어떠한 방식으로 해결하고 있을까요?


###  좌측값 (lvalue) 와 우측값 (rvalue)

모든 C++ 표현식 (expression) 의 경우 두 가지 카테고리로 구분할 수 있습니다. 하나는 이 구문이 어떤 타입을 가지냐 이고, 다른 하나는 어떠한 종류의 '값' 을 가지냐 입니다. 값에 종류가 있어? 라고 생각 하실 수 있는데, 아래 예시를 살펴보도록 합시다.

```cpp-formatted
int a = 3;
```



위 표현식에서 먼저 'a' 를 살펴보도록 합시다. 우리는 `a` 가 메모리 상에서 존재하는 변수 임을 알고 있습니다. 즉 'a' 의 주소값을 `&` 연산자를 통해 알아 낼 수 있다는 것입니다. 우리는 보통 이렇게 주소값을 취할 수 있는 값을 **좌측값 (lvalue)** 라고 부릅니다. 그리고 좌측값은 어떠한 표현식의 왼쪽 오른쪽 모두에 올 수 있습니다 (왼쪽에만 와야 하는게 아닙니다).


반면에 오른쪽에 있는 '3' 을 살펴보도록 합시다. 우리가 '3' 의 주소값을 취할 수 있나요? 아닙니다. '3' 은 왼쪽의 'a' 와는 다르게, 위 표현식을 연산할 때만 잠깐 존재할 뿐 위 식이 연산되고 나면 사라지는 값입니다. 즉, '3' 은 실체가 없는 값입니다.

이렇게, 주소값을 취할 수 없는 값을 **우측값 (rvalue)** 라고 부릅니다. 이름에도 알 수 있듯이, 우측값은 식의 오른쪽에만 항상 와야 합니다. 좌측값이 식의 왼쪽 오른쪽 모두 올 수 있는반면, 우측값은 식의 오른쪽에만 존재해야 합니다.

```cpp-formatted
int a;         // a 는 좌측값
int& l_a = a;  // l_a 는 좌측값 레퍼런스

int& r_b = 3;  // 3 은 우측값. 따라서 오류
```


여태까지 우리가 다루어왔던 레퍼런스는 '좌측값' 에만 레퍼런스를 가질 수 있습니다. 예를 들어서, `a` 의 경우 좌측값 이기 때문에, `a` 의 좌측값 레퍼런스인 `l_a` 를 만들 수 있습니다.


반면에 3 의 경우 우측값이기 때문에, 우측값의 레퍼런스인 `r_b` 를 만들 수 없습니다. 따라서 이 문장은 오류가 발생하게 됩니다.



이와 같이 `&` 하나를 이용해서 정의하는 레퍼런스를 **좌측값 레퍼런스 (lvalue reference)** 라고 부르고, 좌측값 레퍼런스 자체도 좌측값이 됩니다.


그럼 다른 예제를 살펴보도록 합시다.

```cpp-formatted
int& func1(int& a) { return a; }

int func2(int b) { return b; }

int main() {
  int a = 3;
  func1(a) = 4;
  cout << &func1(a) << endl;

  int b = 2;
  a = func2(b);               // 가능
  func2(b) = 5;               // 오류 1
  cout << &func2(b) << endl;  // 오류 2
}
```



컴파일 하였다면 위 오류 `1, 2,` 줄에서 각각 다음과 같은 오류를 볼 수 있습니다.

```warning

ErrorC2106'=': left operand must be l-value
ErrorC2102'&' requires l-value
```



일단 `func1` 의 경우 좌측값 레퍼런스를 리턴합니다. 앞서, 좌측값 레퍼런스의 경우 좌측값에 해당하기 때문에,

```cpp-formatted
func1(a) = 4;
```



의 경우 '`func(a)` 가 리턴하는 레퍼런스의 값을 4' 로 해라 라는 의미로, 실제로 변수 `a` 의 값이 바뀌게 됩니다. 또한, `func1(a)` 가 좌측값 레퍼런스를 리턴하므로, 그 리턴값의 주소값 역시 취할 수 있습니다.


하지만 `func2` 를 살펴볼까요? `func2` 의 경우, 레퍼런스가 아닌, 일반적인 `int` 값을 리턴하고 있습니다. 이 때 리턴되는 값은


```cpp-formatted
a = func2(b);
```



이 문장이 실행 될 때 잠깐 존재할 뿐 그 문장 실행이 끝나면 사라지게 됩니다. 즉, 실체가 없는 값이라는 뜻이지요. 따라서 `func2(b)` 는 우측값이 됩니다. 따라서 위와 같이 우측값이 실제 표현식의 오른쪽에 오는 경우는 가능하지만,

```cpp-formatted
func2(b) = 5;
```



위 문장 처럼 우측값이 왼쪽의 오는 경우는 가능하지 않습니다.

```cpp-formatted
cout << &func2(b) << endl;  // 오류 2
```



마찬가지로 우측값의 주소값을 취할 수 없기 때문에 위 문장은 허용되지 않습니다.


그렇다면 앞선 예제에서

```cpp-formatted
MyString str3 = str1 + str2;
```



를 다시 살펴보도록 합시다. 위 문장은

```cpp-formatted
MyString str3(str1.operator+(str2));
```



와 동일합니다. 그런데, `operator+` 의 정의를 살펴보면,

```cpp-formatted
MyString MyString::operator+(const MyString &s)
```



로 우측값을 리턴하고 있는데, 이 우측값이 어떻게 좌측값 레퍼런스를 인자로 받는,

```cpp-formatted
MyString(const MyString &str);
```



를 호출 시킬 수 있었을까요? 이는 `&` 가 좌측값 레퍼런스를 의미하지만, 예외적으로

```cpp-formatted
const T&
```



의 타입의 한해서만, 우측값도 레퍼런스로 받을 수 있습니다. 그 이유는 `const` 레퍼런스 이기 때문에 임시로 존재하는 객체의 값을 참조만 할 뿐 이를 변경할 수 없기 때문입니다.



###  그렇다면 이동은 어떻게?




그렇다면 앞서 `MyString` 에서 지적한 문제를 해결할 생성자의 경우 어떠한 방식으로 작동해야 할까요?

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F99DC5E435AB639BF0D7DD5)
위와 같이 간단합니다. `str3` 생성 시에 임시로 생성된 객체의 `string_content` 가리키는 문자열의 주소값을 `str3` 의 `string_content` 로 해주면 됩니다.

문제는 이렇게 하게 되면, 임시 객체가 소멸 시에 `string_content` 를 메모리에서 해제하게 되는데, 그렇게 되면 `str3` 가 가리키고 있던 문자열이 메모리에서 소멸되게 됩니다. 따라서 이를 방지 하기 위해서는, 임시 생성된 객체의 `string_content` 를 `NULL` 로 바꿔주고, 소멸자에서 `string_content` 가 `NULL` 이면 소멸하지 않도록 해주면 됩니다. 매우 간단하지요?

하지만, 이 방법은 기존의 복사 생성자에서 사용할 수 없습니다. 왜냐하면 우리는 인자를 `const MyString&` 으로 받았기 때문에, 인자의 값을 변경할 수 없게 되지요. 즉 임시 객체의 `string_content` 값을 수정할 수 없기에 문제가 됩니다.

이와 같은 문제가 발생한 이유는 `const MyString&` 이 좌측값과 우측값 모두 받을 수 있다는 점에서 비롯되었습니다. 그렇다면, 좌측값 말고 우측값만 특이적으로 받을 수 있는 방법은 없을까요? 바로 C++ 11 부터 제공하는 우측값 레퍼런스를 이용하면 됩니다. (참고로 C++ 11 가 기본으로 설정되어 있지 않는 컴파일러는 사용 불가능 합니다. 비주얼 스튜디오 2017 버전의 경우 자동으로 `on` 되어 있으니 걱정하실 필요 없습니다.)


###  우측값 레퍼런스




```cpp-formatted
#include <iostream>
using namespace std;

class MyString {
  char *string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

  int memory_capacity;  // 현재 할당된 용량

 public:
  MyString();

  // 문자열로 부터 생성
  MyString(const char *str);

  // 복사 생성자
  MyString(const MyString &str);

  // 이동 생성자
  MyString(MyString &&str);

  void reserve(int size);
  MyString operator+(const MyString &s);
  ~MyString();

  int length() const;

  void print();
  void println();
};

MyString::MyString() {
  cout << "생성자 호출 ! " << endl;
  string_length = 0;
  memory_capacity = 0;
  string_content = NULL;
}

MyString::MyString(const char *str) {
  cout << "생성자 호출 ! " << endl;
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString &str) {
  cout << "복사 생성자 호출 ! " << endl;
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::MyString(MyString &&str) {
  cout << "이동 생성자 호출 !" << endl;
  string_length = str.string_length;
  string_content = str.string_content;
  memory_capacity = str.memory_capacity;

  // 임시 객체 소멸 시에 메모리를 해제하지
  // 못하게 한다.
  str.string_content = nullptr;
}
MyString::~MyString() {
  if (string_content) delete[] string_content;
}
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char *prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    if (prev_string_content != NULL) delete[] prev_string_content;
  }
}
MyString MyString::operator+(const MyString &s) {
  MyString str;
  str.reserve(string_length + s.string_length);
  for (int i = 0; i < string_length; i++)
    str.string_content[i] = string_content[i];
  for (int i = 0; i < s.string_length; i++)
    str.string_content[string_length + i] = s.string_content[i];
  str.string_length = string_length + s.string_length;
  return str;
}
int MyString::length() const { return string_length; }
void MyString::print() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];
}
void MyString::println() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];

  cout << endl;
}

int main() {
  MyString str1("abc");
  MyString str2("def");

  cout << "-------------" << endl;
  MyString str3 = str1 + str2;
  str3.println();
}
```



성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile9.uf.tistory.com%2Fimage%2F995166505AB63D112FF31F)



와 같이 나옵니다.


먼저 우측값 레퍼런스를 사용한 이동 생성자의 정의 부분 부터 살펴봅시다.

```cpp-formatted
MyString::MyString(MyString&& str) {
  cout << "이동 생성자 호출 !" << endl;
  string_length = str.string_length;
  string_content = str.string_content;
  memory_capacity = str.memory_capacity;

  // 임시 객체 소멸 시에 메모리를 해제하지
  // 못하게 한다.
  str.string_content = nullptr;
}
```



우측값의 레퍼런스를 정의하기 위해서는 좌측값과는 달리 `&` 를 두 개 사용해서 정의해야 합니다. 즉, 위 생성자의 경우 `MyString` 타입의 우측값을 인자로 받고 있습니다.


그렇다면 한 가지 퀴즈! 과연 `str` 자체는 우측값 일까요 좌측값 일까요? 당연히도 좌측값 입니다. 실체가 있기 때문이지요 (`str` 이라는 이름이 있잖아요). 다시 말해 `str` 은 타입이 '`MyString` 의 우측값 레퍼런스' 인 좌측값 이라 보면 됩니다. 따라서 표현식의 좌측에 올 수도 있습니다. (마지막 줄 처럼)

```cpp-formatted
string_content = str.string_content;
```



이제 위와 같이 우리가 바라던 대로 임시 객체의 `string_content` 가 가리키는 메모리를 새로 생성되는 객체의 메모리로 옮겨주기만 하면 됩니다. 기존의 복사 생성자의 경우 문자열 전체를 새로 복사해야 했지만, 이동 생성자의 경우 단순히 주소값 하나만 달랑 복사해주면 끝이기 때문에 매우 간단합니다.

```cpp-formatted
// 임시 객체 소멸 시에 메모리를 해제하지
// 못하게 한다.
str.string_content = nullptr;
```



한 가지 중요한 부분은 인자로 받은 임시 객체가 소멸되면서 자신이 가리키고 있던 문자열을 `delete` 하지 못하게 해야 합니다. 만약에 그 문자열을 지우게 된다면, 새롭게 생성된 문자열 `str3` 도 같은 메모리를 가리키고 있기 때문에 `str3` 의 문자열도 같이 사라지는 셈이 되기 때문입니다.


따라서 `str` 의 `string_content` 를 `nullptr` 로 바꿔줍니다. 참고로 `nullptr` 역시 C++ 11 에 새로 추가된 키워드로, 기존의 `NULL` 대체합니다. C 언어에서의 `NULL` 은 단순히 #define 으로 정의되어 있는 상수값 0 인데, 이 때문에 이 `NULL` 이 값 0 을 의미하는 것인지, 아니면 포인터 주소값 0 을 의미하는 것인지 구분할 수 가 없었습니다. 하지만 `nullptr` 로 '포인터 주소값 0' 을 정확히 명시해 준다면 미연에 발생할 실수를 줄여 줄 수 있게 됩니다.

```cpp-formatted
MyString::~MyString() {
  if (string_content) delete[] string_content;
}
```



그리고 물론 소멸자 역시 바꿔줘야만 합니다. `string_content` 가 `nullptr` 가 아닐 때 에만 `delete` 를 하도록 말이죠.


일반적으로 우측값 레퍼런스는 아래와 같은 방식으로 사용할 수 있습니다.

```cpp-formatted
int a;
int& l_a = a;
int& ll_a = 3;  // 불가능

int&& r_b = 3;
int&& rr_b = a;  // 불가능
```



일단 우측값 레퍼런스의 경우 반드시 우측값의 레퍼런스만 가능합니다. 따라서, `r_b` 의 경우 우측값 '3' 의 레퍼런스가 될 수 있겠지만, `rr_b` 의 경우 `a` 가 좌측값이기 때문에 컴파일 되지 않습니다.


우측값 레퍼런스의 재미있는 특징으로 레퍼런스 하는 임시 객체가 소멸되지 않도록 붙들고 있는다는 점입니다. 예를 들어서,

```cpp-formatted
MyString&& str3 = str1 + str2;
str3.println();
```



의 경우 `str3` 이 `str1 + str2` 에서 리턴되는 임시 객체의 레퍼런스가 되면서 그 임시 객체가 소멸되지 않도록 합니다. 실제로, 아래 `println` 함수에서 더해진 문자열이 잘 보여집니다.


자 이것으로 이번 강좌는 여기서 마치도록 하겠습니다. 다음 강좌에서는 C++ 11 에 우측값 레퍼런스와 함께 새로 추가된 `move` 에 대해 살펴보도록 하겠습니다.



###  생각 해보기

#### 문제 1

사실 C++ 에서 값의 종류로 좌측값 우측값 만이 있는게 아니라 조금 더 세부적으로 나눠어집니다. 이에 대해 자세히 알아보고 싶으신 분들은 [여기를 참조해주세요](https://medium.com/@barryrevzin/value-categories-in-c-17-f56ae54bccbe)(난이도 : 상)

##@ chewing-cpp-end