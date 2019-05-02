----------------
title : 씹어먹는 C++ - <12 - 2. Move 문법 (move semantics) 과 완벽한 전달 (perfect forwarding)>
cat_title: 12 - 2. Move 문법 (move semantics) 과 완벽한 전달 (perfect forwarding)
next_page: 229
publish_date : 2018-03-27
--------------


이번 강좌에서는
* `move` 문법 (move semantics)

* 완벽한 전달 (perfect forwarding)

* 레퍼런스 겹침 (reference collapsing)


등에 대해 다룹니다.

![](/img/ChewingCpplogo.png)


안녕하세요 여러분! 지난번의 우측값 레퍼런스 강의는 어떠셨나요? 우측값 레퍼런스를 통해서, 기존에는 불가능하였던 우측값에 대한 복사가 아닌 이동의 구현이 가능하게 되었습니다.


하지만, 만약에 좌측값도 이동을 시키고 싶다면 어떨까요? 예를 들어서 아래와 같이 두 변수의 값을 바꾸는 `swap` 함수를 생각해보세요.

```cpp-formatted
template <typename T>
void my_swap(T &a, T &b) {
  T tmp(a);
  a = b;
  b = tmp;
}
```

위 `my_swap` 함수에서 `tmp` 라는 임시 객체를 생성한 뒤에, `b` 를 `a` 에 복사하고, `b` 에 `a` 를 복사하게 됩니다. 문제는 무려 복사를 쓸데없이 3 번이나 한다는 점입니다. 예를 들어서 `T` 가 `MyString` 인 경우를 생각해봅시다.

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
  MyString &operator=(const MyString &s);
  ~MyString();

  int length() const;

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
MyString &MyString::operator=(const MyString &s) {
  cout << "복사!" << endl;
  if (s.string_length > memory_capacity) {
    delete[] string_content;
    string_content = new char[s.string_length];
    memory_capacity = s.string_length;
  }
  string_length = s.string_length;
  for (int i = 0; i != string_length; i++) {
    string_content[i] = s.string_content[i];
  }

  return *this;
}
int MyString::length() const { return string_length; }
void MyString::println() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];

  cout << endl;
}
template <typename T>
void my_swap(T &a, T &b) {
  T tmp(a);
  a = b;
  b = tmp;
}

int main() {
  MyString str1("abc");
  MyString str2("def");
  cout << "Swap 전 -----" << endl;
  str1.println();
  str2.println();

  cout << "Swap 후 -----" << endl;
  my_swap(str1, str2);
  str1.println();
  str2.println();
}
```



성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F99115F3E5AB8FD86061B59)



와 같이 나옵니다.

```cpp-formatted
template <typename T>
void my_swap(T &a, T &b) {
  T tmp(a);
  a = b;
  b = tmp;
}
```



위 `my_swap` 함수를 살펴봅시다. 일단, 첫번째 줄에서, `a` 가 좌측값이기 때문에 `tmp` 의 복사 생성자가 호출됩니다. 따라서 1 차적으로 `a` 가 차지하는 공간 만큼 메모리 할당이 발생한 후 `a` 의 데이터가 복사됩니다.

```cpp-formatted
a = b;
```



두 번째로 `a =` b; 에서 2 차적으로 복사가 발생합니다. 그리고 마지막으로,

```cpp-formatted
b = tmp;
```



에서 또 한번 문자열 전체의 복사가 이루어지게 됩니다. 무려 `swap` 을 하기 위해 문자열 전체 복사를 3번이나 해야 합니다. 아래 그림처럼 말입니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F9960ED4D5AB96B7D09D8A7)

하지만 우리는 굳이 문자열 내용을 복사할 필요 없이 각 `MyString` 객체의 `string_content` 주소값만 서로 바꿔주면 되는 것을 알고 있습니다. (물론 `string_length` 와 `memory_capacity` 도 바꿔야겠지만, 이들은 단순히 4바이트 `int` 복사 이기 때문에 속도에 영향을 주지는 않습니다).

![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile27.uf.tistory.com%2Fimage%2F997263435AB96BB9085570)


하지만 위를 `my_swap` 에서 구현하기 위해서는 여러가지 문제가 있습니다. 일단 첫번째로 `my_swap` 함수는 `generic` 한 함수 입니다. 다시 말해,

```cpp-formatted
template <typename T>
void my_swap(T &a, T &b)
```



위 함수가 일반적인 타입 `T` 에 대해 작동해야 한다는 의미이지요. 하지만 위 `string_content` 의 경우 `MyString` 에만 존재하는 필드이기 때문에 일반적인 타입 `T` 에 대해서는 작동하지 않습니다. 물론 그렇다고 해서 불가능 한 것은 아닙니다. 아래 처럼 템플릿 특수화를 이용하면 되기 때문이죠.

```cpp-formatted
template <>
void my_swap(MyString &a, MyString &b) {
  // ...
}
```



문제는 `string_content` 가 `private` 이기 때문에, 이를 위해 `MyString` 내부에 `swap` 관련한 함수를 만들어야 된다는 것입니다. 사실 이렇게 된다면 굳이 `my_swap` 이라는 함수를 정의할 필요가 없게 됩니다.


위 문제를 원래의 `my_swap` 함수를 사용하면서 좀 더 깔끔하게 해결할 수 있는 방법은 없을까요?

```cpp-formatted
T tmp(a);
```



먼저 기존의 `my_swap` 함수를 다시 살펴봅시다. 우리는 위 문장이 복사 생성자 대신에, 이동 생성자가 되기를 원합니다. 왜냐하면 `tmp` 를 복사생성 할 필요 없이, 단순히 `a` 를 잠깐 옮겨놓기만 하면 되기 때문이지요. 하지만 문제는 `a` 가 좌측값이라는 점입니다 ('a' 라는 실체가 있으므로). 따라서 지금 이 상태로는 우리가 무얼 해도 이동 생성자는 오버로딩 되지 않습니다.


그렇다면, 좌측값이 우측값으로 취급될 수 있게 바꿔주는 함수 같은 것이 있을까요? 즉, 어떠한 좌측값이 이동 될 수 있도록 말이죠.



###  move 문법 (move semantics)




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
  MyString &operator=(const MyString &s);
  ~MyString();

  int length() const;

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
  str.string_length = 0;
  str.memory_capacity = 0;
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
void MyString::println() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];

  cout << endl;
}

int main() {
  MyString str1("abc");
  cout << "이동 전 -----" << endl;
  cout << "str1 : ";
  str1.println();

  cout << "이동 후 -----" << endl;
  MyString str2(move(str1));
  cout << "str1 : ";
  str1.println();
  cout << "str2 : ";
  str2.println();
}
```



성공적으로 컴파일 하였다면



![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F99BE55345AB99D231E151B)



와 같이 나옵니다.

```cpp-formatted
cout << "이동 후 -----" << endl;
MyString str2(move(str1));
```



부분을 살펴보도록 합시다. 놀랍게도 `str2` 의 복사 생성자가 아닌 이동 생성자가 호출되었습니다. C++ 11 에 새롭게 추가된 `move` 함수는 입력받은 좌측값을 이동 가능한 값으로 캐스팅 해줍니다.사실 `move` 함수가 수정하는 것은 아무 것도 없습니다. 다만 컴파일러가 `move` 함수가 리턴하는 값을 '이동 가능 하구나' 라고 생각하게 해주지요.

```cpp-formatted
cout << "str1 : ";
str1.println();
cout << "str2 : ";
str2.println();
```



그렇게 이동 된 후에 문자열들을 출력해보면 `str1` 에는 빈 문자열이, `str2` 에는 원래의 `str1` 의 문자열이 들어있음을 알 수 있습니다. 이 과정에서 문자열 전체 복사는 한 번도 발생하지 않고 단순히 `string_content` 의 값만 복사되었을 뿐입니다.


자 이제 이 새로운 `move` 를 이용해서 위 `my_swap` 함수를 수정해보도록 합시다.

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
  MyString &operator=(const MyString &s);
  ~MyString();

  int length() const;

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
  str.string_length = 0;
  str.memory_capacity = 0;
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
MyString &MyString::operator=(const MyString &s) {
  cout << "복사!" << endl;
  if (s.string_length > memory_capacity) {
    delete[] string_content;
    string_content = new char[s.string_length];
    memory_capacity = s.string_length;
  }
  string_length = s.string_length;
  for (int i = 0; i != string_length; i++) {
    string_content[i] = s.string_content[i];
  }

  return *this;
}
int MyString::length() const { return string_length; }
void MyString::println() {
  for (int i = 0; i != string_length; i++) cout << string_content[i];

  cout << endl;
}

template <typename T>
void my_swap(T &a, T &b) {
  T tmp(move(a));
  a = move(b);
  b = move(tmp);
}
int main() {
  MyString str1("abc");
  MyString str2("def");
  cout << "Swap 전 -----" << endl;
  cout << "str1 : ";
  str1.println();
  cout << "str2 : ";
  str2.println();

  cout << "Swap 후 -----" << endl;
  my_swap(str1, str2);
  cout << "str1 : ";
  str1.println();
  cout << "str2 : ";
  str2.println();
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile4.uf.tistory.com%2Fimage%2F99BA0F435AB9A114146E55)



와 같이 나옵니다.


위에서 보시다시피 `swap` 은 잘 되었지만, 공교롭게도 두 번의 복사를 수행하였습니다.

```cpp-formatted
a = move(b);
b = move(tmp);
```



왜냐하면 바로 위 두 줄 때문이지요. 비록 `move` 를 시키고자 하였지만, 오버로딩 된 `operator=` 가 복사를 수행하였습니다. 그 이유는 현재 정의된 `operator=` 가

```cpp-formatted
MyString& MyString::operator=(const MyString& s)
```



꼴 이므로, `s` 를 그대로 복사하기 때문이지요. 따라서 우리는 우측값에만 특이적으로 오버로딩 되는 `operator=` 를 정의해줘야만 합니다. 아래와 같이 말이지요.

```cpp-formatted
MyString& MyString::operator=(MyString&& s) {
  cout << "이동!" << endl;
  string_content = s.string_content;
  memory_capacity = s.memory_capacity;
  string_length = s.string_length;

  s.string_content = nullptr;
  s.memory_capacity = 0;
  s.string_length = 0;
  return *this;
}
```



그리고 성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F99ABCE4F5AB9A225263122)



와 같이 제대로 이동을 시키고 있음을 알 수 있습니다.


새롭게 정의한 `operator=` 를 살펴보면 매우 간단합니다. 굳이 문자열 전체를 복사할 필요가 없이, 단순히 `string_content` 값만 복사해주면 되기 때문이지요. 물론 s 에 있던 문자열은 사라지게 됩니다. 하지만 상관 없습니다. 어차피 우측값 이니까요!




###  완벽한 전달
 (perfect forwarding)




`C++ 11` 에 우측값 레퍼런스가 도입되기 전 까지 해결할 수 없었던 문제가 있었습니다. 예를 들어서 아래와 같은 `wrapper` 함수를 생각해봅시다 C++ 11 에 우측값 레퍼런스가 도입되기 전 까지 해결할 수 없었던 문제가 있었습니다. 예를 들어서 아래와 같은 `wrapper` 함수를 생각해봅시다.
```cpp-formatted
template <typename T>
void wrapper(T u) {
  g(u);
}
```



이 함수는 인자로 받은 `u` 를 그대로 `g` 라는 함수에 인자로 '전달' 해줍니다. 물론 왜 저런 함수가 필요하나고 생각할 수 있습니다. 그냥 저런 `wrapper` 함수를 만들지 말고 그냥 `g(u)` 를 호출하면 되잖아요?


하지만 실제로 저러한 형태의 전달 방식이 사용되는 경우가 종종 있습니다. 예를 들어 `STL` 의 `vector` 에는 `emplace_back` 이라는 함수가 있습니다. 예를 들어서 클래스 `A` 를 원소로 가지는 벡터의 뒤에 원소를 추가하기 위해서는

```cpp-formatted
vec.push_back(A(1, 2, 3));
```



과 같이 객체를 생성한 뒤에 인자로 전달해줘야만 합니다. 하지만 이 과정에서 불필요한 이동 혹은 복사가 발생하게 됩니다. 그렇다면, 아예 벡터에 인자를 전달해준 다음, 벡터 내부에서 자체적으로 객체를 생성한 뒤에 벡터 뒤에 추가하면 어떨까요? 이를 가능하게 하는게 `emplace_back` 함수 입니다.

```cpp-formatted
vec.emplace_back(1, 2, 3);  // 위와 동일한 작업을 수행한다.
```



`emplace_back` 함수는 인자를 직접 전달받아서, 내부에서 `A` 의 생성자를 호출한 뒤에 이를 벡터 원소 뒤에 추가하게 되지요. 이 과정에서 불필요한 이동/복사 모두 발생하지 않습니다. 참고로 새로 생성한 객체를 벡터 뒤에 추가할 경우 위와 같이 `push_back` 을 이용하는 것 보다 `emplace_back` 을 이용하는 것이 권장되는 방식입니다.


그렇다면 문제는 `emplace_back` 함수가 받은 인자들을 `A` 의 생성자에 제대로 전달해야 합니다. 그렇지 않을 경우 사용자가 의도하지 않은 생성자가 호출될 수 있기 때문입니다. 그렇다면 위와 같은 `wrapper` 함수를 어떻게 하면 잘 정의할 수 있을까요?

```cpp-formatted
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void wrapper(T u) {
  g(u);
}

class A {};

void g(A& a) { cout << "좌측값 레퍼런스 호출" << endl; }
void g(const A& a) { cout << "좌측값 상수 레퍼런스 호출" << endl; }
void g(A&& a) { cout << "우측값 레퍼런스 호출" << endl; }

int main() {
  A a;
  const A ca;

  cout << "원본 --------" << endl;
  g(a);
  g(ca);
  g(A());

  cout << "Wrapper -----" << endl;
  wrapper(a);
  wrapper(ca);
  wrapper(A());
}
```



성공적으로 컴파일 하였다면
![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile2.uf.tistory.com%2Fimage%2F99ADBC435AB9C1621B4011)



와 같이 나옵니다.

```cpp-formatted
cout << "원본 --------" << endl;
g(a);
g(ca);
g(A());
```



먼저 위 경우 우리의 예상대로 좌측값 레퍼런스, 좌측값 상수 레퍼런스, 우측값 레퍼런스가 각각 호출되었습니다. 반면에 `wrapper` 함수를 거쳐갔을 경우, 공교롭게도 위 세 경우 모두 좌측값 레퍼런스를 받는 `g` 함수가 호출되었습니다.


이러한 일이 발생한 이유는 C++ 컴파일러가 템플릿 타입을 추론할 때,템플릿 인자 `T` 가 레퍼런스가 아닌 일반적인 타입이라면 `const` 를 무시하기 때문입니다. 다시 말해,

```cpp-formatted
template <typename T>
void wrapper(T u) {
  g(u);
}
```



에서 `T` 가 전부 다 `class A` 로 추론됩니다. 따라서 위 세 경우 전부 다 좌측값 레퍼런스를 호출하는 `g` 를 호출하였습니다.


```cpp-formatted
template <typename T>
void wrapper(T& u) {
  g(u);
}
```



그렇다면 위 경우는 어떨까요?

```compiler-warning
error: cannot bind non-const lvalue reference of type 'A&' to an rvalue of type 'A'
  wrapper(A());
          ^~~
```

위와 같은 컴파일 오류가


g(A());


에서 발생합니다. (참고로 이 오류는 `gcc` 와 `clang` 컴파일러에서 모두 발생하는데, 비주얼 스튜디오에서는 발생하지 않습니다. 하지만 원칙적으로 위와 같은 오류를 발생시켜야 하는 것이 맞습니다)


왜 위와 같은 오류가 발생하는지 생각해보자면 다음과 같습니다. 일단, `A()` 자체는 `const` 속성이 없으므로 템플릿 인자 추론에서 `T` 가 `class A` 로 추론됩니다. 하지만 `A&` 는 우측값의 레퍼런스가 될 수 없기 때문에 컴파일 오류가 발생하는 것입니다.



그렇다면 아예 우측값을 레퍼런스로 받을 수 있도록 `const A&` 와 `A&` 따로 만들어주는 방법이 있습니다. 아래와 같이 말이지요.

```cpp-formatted
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void wrapper(T& u) {
  cout << "T& 로 추론됨" << endl;
  g(u);
}

template <typename T>
void wrapper(const T& u) {
  cout << "const T& 로 추론됨" << endl;
  g(u);
}

class A {};

void g(A& a) { cout << "좌측값 레퍼런스 호출" << endl; }
void g(const A& a) { cout << "좌측값 상수 레퍼런스 호출" << endl; }
void g(A&& a) { cout << "우측값 레퍼런스 호출" << endl; }

int main() {
  A a;
  const A ca;

  cout << "원본 --------" << endl;
  g(a);
  g(ca);
  g(A());

  cout << "Wrapper -----" << endl;
  wrapper(a);
  wrapper(ca);
  wrapper(A());
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F99DB5A3A5ABA0364292293)



와 같이 나옵니다.


일단 `a` 와 `ca` 의 경우 각각 `T&` 와 `const T&` 로 잘 추론되서 올바른 함수를 호출하고 있음을 알 수 있습니다. 반면에 `A()` 의 경우 `const T&` 로 추론되면서 `g(const T&)` 함수를 호출하게 됩니다. 물론 이는 예상했던 일입니다. 우리가 무엇을 해도 `wrapper` 안에 `u` 가 좌측값이라는 사실은 변하지 않고 이에 언제나 좌측값 레퍼런스를 받는 함수들이 오버로딩 되겠지요.



뿐만이 아니라 다음과 같은 문제가 있습니다. 예를 들어서 함수 `g` 가 인자를 한 개가 아니라 2 개를 받는다고 가정합니다. 그렇다면 우리는 다음과 같은 모든 조합의 템플릿 함수들을 정의해야합니다.

```cpp-formatted
template <typename T>
void wrapper(T& u, T& v) {
  g(u, v);
}
template <typename T>
void wrapper(const T& u, T& v) {
  g(u, v);
}

template <typename T>
void wrapper(T& u, const T& v) {
  g(u, v);
}
template <typename T>
void wrapper(const T& u, const T& v) {
  g(u, v);
}
```



매우 귀찮은 일입니다. 위와 같이 짜야하는 이유는 단순히 일반적인 레퍼런스가 우측값을 받을 수 없기 때문입니다. 그렇다고 해서 디폴트로 상수 레퍼런스만 받게 된다면, 상수가 아닌 레퍼런스도 상수 레퍼런스로 캐스팅되서 들어간다는 점이지요.


하지만 놀랍게도 C++ 11 에서는 이를 간단하게 해결할 수 있습니다.

```cpp-formatted
#include <iostream>
using namespace std;

template <typename T>
void wrapper(T&& u) {
  g(forward<T>(u));
}

class A {};

void g(A& a) { cout << "좌측값 레퍼런스 호출" << endl; }
void g(const A& a) { cout << "좌측값 상수 레퍼런스 호출" << endl; }
void g(A&& a) { cout << "우측값 레퍼런스 호출" << endl; }

int main() {
  A a;
  const A ca;

  cout << "원본 --------" << endl;
  g(a);
  g(ca);
  g(A());

  cout << "Wrapper -----" << endl;
  wrapper(a);
  wrapper(ca);
  wrapper(A());
}
```



성공적으로 컴파일 하였다면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile5.uf.tistory.com%2Fimage%2F99772B4C5ABA05F832FD06)



와 같이 잘 작동함을 알 수 있습니다.


```cpp-formatted
template <typename T>
void wrapper(T&& u) {
  g(forward<T>(u));
}
```



일단 우리의 `wrapper` 함수는 인자로 아예 `T&&` 를 받아버리고 있습니다. 아니 이렇게 된다면 도대체 좌측값은 어떻게 받겠다는 것일까요? 사실 C++ 11 에서 템플릿 인자들 간에 다음과 같은 레퍼런스 겹침 규칙 (reference collapsing rule) 을 정하였습니다.

```info-format
typedef int& T;
T& r1; // int& &; r1 은 int&
T&& r2; // int & &&;  r2 는 int&


typedef int&& U
U& r3; // int && &; r3 는 int&
U&& r4; // int && &&; r4 는 int&&
```



즉 쉽게 생각하면 `&` 는 1 이고 `&&` 은 0 이라 둔 뒤에, `OR` 연산을 한다고 보면 됩니다. 그렇다면,

```cpp-formatted
wrapper(a);
wrapper(ca);
```



위 두 개의 호출의 경우 `T` 가 각각 `A&` 와 `const A&` 로 추론될 것이고,

```cpp-formatted
wrapper(A());
```



의 경우에는 `T` 가 단순히 `A&&` 로 추론되겠지요.


그런데 문제는 이제 직접 `g` 에 이 인자를 전달하는 방법입니다. 왜 그냥

```cpp-formatted
g(u)
```



로 하지 않았는지 생각해봅시다. 앞서도 말했듯이 여기서 `u` 는 좌측값 입니다. `u` 가 우측값 레퍼런스임에도 불구하고, const `int&` 를 오버로딩하는 `g` 가 호출되게 됩니다. 물론 우리는 좌측값을 어떻게 하면 우측값으로 캐스팅 시킬지 알고 있습니다. 바로 `move` 를 이용하는 것입니다.


하지만 위 경우 아무때나 `move` 를 하면 안됩니다. 인자로 받은 `u` 가 우측값 레퍼런스 일 때 에만 `move` 를 해줘야만 하는 것입니다. 만일 좌측값 레퍼런스일 때 `move` 를 해버린다면 좌측값에 오버로딩 되는 `g` 가 아닌 우측값에 오버로딩 되는 `g` 가 호출되겠지요.


```cpp-formatted
g(forward<T>(u));
```



이 문제를 해결해주는 것이 `forward` 함수 입니다. 이 함수는 `u` 가 우측값 레퍼런스 일 때 에만 마치 `move` 를 적용한 것 처럼 작동합니다. 실제로 `forward` 가 어떻게 생겼나면,


```cpp-formatted
template <class S>
S&& forward(typename remove_reference<S>::type& a) noexcept {
  return static_cast<S&&>(a);
}
```



와 같이 생겼는데, `S` 가 `A&` 라면 (참고로 `remove_reference` 는 타입의 레퍼런스를 지워주는 템플릿 메타 함수 입니다)



```cpp-formatted
A&&& forward(typename remove_reference<A&>::type& a) noexcept {
  return static_cast<A&&&>(a);
}
```



가 되어 레퍼런스 겹침 규칙에 따라



```cpp-formatted
A& forward(A& a) noexcept { return static_cast<A&>(a); }
```



가 되버리고, `S` 가 그냥 `A` 라면, (퀴즈! 여기서 왜 `forward` 의 인자가 `A&&` 가 아니라 A& 일까요?)



```cpp-formatted
A&& forward(A& a) noexcept { return static_cast<A&&>(a); }
```



가 되어 성공적으로 우측값으로 캐스팅해줍니다. 따라서 결과적으로 위 그림 처럼 원본과 `Wrapper` 을 사용했을 때 모두 호출되는 함수가 동일함을 알 수 있습니다. 성공적으로 인자를 전달한 것이지요!


자 그럼 이것으로 이번 강좌를 마치도록 하겠습니다. 다음 강좌에서는 여태까지 배운 내용을 바탕으로 스마트 포인터를 사용하는 방법에 대해서 다루어보도록 하겠습니다.





###  생각 해보기

#### 문제 1

실제로 `move` 와 `forward` 가 어떠한 방식으로 구현되어 있는지 궁금하신 분들은 [여기를 참고하시면 됩니다](https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-api-4.5/a00936_source.html) 한 번 코드를 보시고 왜 이런 방식으로 구현되어 있는지 생각해보세요. (난이도 : 중)

##@ chewing-cpp-end