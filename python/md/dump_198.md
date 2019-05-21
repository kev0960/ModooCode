----------------
title : 씹어먹는 C++ - <4 - 5. 내가 만드는 String 클래스>
cat_title: 4 - 5. 내가 만드는 String 클래스
next_page : 253
publish_date : 2013-08-15
--------------

이번 강좌에서는

* 직접 만드는 문자열 클래스(MyString)

에 대해 다룹니다.


![](/img/ChewingCpplogo.png)

안녕하세요? 여러분. C++ 강좌도 벌써 10 번째 강좌입니다. 그 동안 잘 따라오고 있으셨나요? 이번 강좌는 그 동안 배운 내용을 종합해서 하나의 작은 프로젝트를 진행해보도록 할 것입니다. 이 강좌를 통해 여태까지 배운 C++ 클래스의 중요한 내용들을 복습하고 점검할 수 있는 기회가 되었으면 합니다.


이번 강좌에서는 문자열들을 효율적으로 관리하고 보관할 수 있는 문자열 클래스를 만들어보려고 합니다. 

이 강좌를 읽기에 앞서 여태까지 배운 내용들을 복습할 겸 직접 자신만의 문자열 클래스를 만들어보기 바랍니다. 그 문자열 클래스는 아래와 같은 내용들을 지원해야 합니다.

1. 문자(`char`) 로 부터의 문자열 생성, C 문자열 (`char *`) 로 부터의 생성
1. 문자열 길이를 구하는 함수
1. 문자열 뒤에 다른 문자열 붙이기
1. 문자열 내에 포함되어 있는 문자열 구하기
1. 문자열이 같은지 비교
1. 문자열 크기 비교 (사전 순)

만일 위 내용을 다 만드셨다면 아래 내용을 읽으셔도 되고, 그렇지 않다면, 다시 한 번 도전해보시기 바랍니다!

```lec-warning
참고로 C++ 표준에서는 문자열 클래스 (`string`) 을 지원하므로 여러분이 직접 문자열 클래스를 만들어서 사용할 일은 거의 없을 것이고, 그 성능 역시 C++ 에서 제공하는 문자열 클래스를 이용하는 것이 훨씬 빠를 것입니다.

하지만, 페이스북이나 구글 같은 큰 회사들에서는 C++ 에서 기본적으로 지원하는 표준 문자열 대신에 자체적으로 최적화 된 버전을 만들어서 사용하고 있기는 합니다.
```

###  문자열 클래스를 만들자


기존 [C 언어에서는 문자열을 나타내기 위해 널 종료 문자열(Null-terstd::minating string)](http://itguru.tistory.com/29)이라는 개념을 도입해서 문자열 끝에 `NULL` 문자를 붙여 문자열을 나타내는 방식을 사용하였습니다.

하지만 C 언어 문자열을 사용하는데에는 번거로움이 많았는데, 예를 들어서 만들어진 문자열의 크기를 바꾼다던지, 문자열 뒤에 다른 문자열을 붙인다던지 등의 작업들은 상당히 프로그래머 입장에서는 귀찮을 수 밖에 없습니다. 이와 같은 작업들을 문자열 클래스를 따로 만들어서 클래스 차원에서 지원해주면 상당히 편할 텐데 말이지요. 그래서 우리는 직접 문자열 클래스를 만들고자 합니다.

사실 C++ 에서는 표준 라이브러리로 `string` 클래스를 지원하고 있습니다. (실제로 `<string>` 헤더파일을 `include` 하면 사용할 수 있습니다.)

```lec-warning
노파심에 이야기 하지만 C++ 에서는 정말 왠만하면 `char` 배열을 사용하는 것보다 `string` 을 사용해서 문자열을 다루는 것을 권정합니다. 뒤에 강좌에서 `string` 클래스를 어떻게 사용하는지 자세히 다룹니다.
```

하지만 이 막강한 `string` 클래스를 사용하기 이전에 우리는 직접 `MyString` 이라는 우리 만의 문자열 클래스를 만들고자 합니다.

일단 간단히 생각해서 우리가 만들 `MyString` 클래스에 멤버 변수로 무엇이 필요할지 생각해봅시다. 아마, 대표적으로 아래 두 개의 데이터들이 필요하다고 볼 수 있습니다.

1. 문자열 데이터가 저장된 공간을 가리키는 포인터
1. 문자열 데이터의 길이

왜 객체에 문자열 데이터를 직접 보관하는 것이 아니라, 그 저장된 공간을 가리키는 포인터를 보관하냐고 물을 수 있습니다. 이렇게 하는 이유는 나중에 문자열 데이터의 크기가 바뀔 때, 저장된 공간을 가리키는 방식으로 하면 그 메모리를 해제한 뒤에, 다시 할당할 수 있지만 직접 보관하면 그럴 수 없기 때문이죠.

또한, 문자열 데이터의 길이를 보관하는 이유는 문자열 길이를 사용할 일이 굉장히 많은데, 그 때 마다 계속 길이를 구하는 것은 상당히 불필요한 일이기 때문입니다. 따라서 길이를 한 번 구해놓고 길이가 바뀔 때 까지 변경하지 않는 방법이 유용할 것입니다. 그럼, 위 내용을 바탕으로 한번 `MyString` 을 구성해보도록 하겠습니다.

```cpp-formatted
class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
};
```


일단 위 두 정보는 `private` 으로 설정하였습니다. 왜냐하면 우리는 다른 프로그래머가 저의 `MyString` 을 이용하면서 위와 같은 중요한 정보들에 함부로 접근하기를 원치 않거든요.

프로그래머가 실수로 `string_length` 를 조작하는 명령을 썼다가 자칫 잘못하기라도 하면 어떻겠습니까. 그렇기에 우리는 다른 프로그래머가 저의 `MyString` 을 `string_length` 나 `string_content` 를 직접 만지작거리지 않고도 그들의 원하는 모든 작업들을 수행할 수 있도록 충분한 '함수' 들을 제공해야 할 것입니다.


그럼 생성자들은 어떨까요. 일단, 위에 제가 구현하고자 요구했던 내용들을 충족시키기 위해서는 아래와 같은 생성자들을 만들어야 합니다.

```cpp-formatted
// 문자 하나로 생성
MyString(char c);

// 문자열로 부터 생성
MyString(const char* str);

// 복사 생성자
MyString(const MyString& str);
```

위와 같은 생성자들을 만들기 전에, 어떠한 방식으로 문자열을 저장할 것인지에 대해 먼저 생각해보도록 합시다. 과연 그대로 `string_content` 에 C 형식의 문자열 (널 종료 문자열) 을 보관하는 것이 좋을까요, 아니면 필요없는 정보들을 빼고 (즉 맨 마지막의 널 문자) 실제 '문자' 만 해당하는 부분만을 넣을까요.

C 형식의 문자열을 그대로 보관한다면, 문자열의 끝 부분을 쉽게 체크할 수 있다는 장점이 있지만 이 문제는 우리가 `string_length` 라는 변수를 같이 도입함으로써 해결할 수 있게 되었습니다. 따라서, 저희 `MyString` 클래스에서는 실제 문자에만 해당하는 내용만을 `string_content` 에 보관하도록 하겠습니다.

```cpp-formatted
MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
  string_length = 1;
}
MyString::MyString(const char* str) {
  string_length = strlen(str);
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
```


위와 같이 3 개의 생성자들을 정의하였고, `string_content` 를 동적 할당으로 처리하였기 때문에 반드시 소멸자에서 이를 동적해제하는 것을 처리해줘야만 합니다. 

이것이 클래스의 큰 장점이라고도 볼 수 있는데, C 언어에서 구조체같은 것으로 문자열을 구현하였다면 이를 일일히 해제 하는 것도 처리해줘야 했었기 때문입니다. 말 그대로, 클래스를 사용하는 사람은 안에서 어떻게 돌아가는지 전혀 신경쓰지 않고도 사용할 수 있게 되는 것입니다.

그럼 이제 매우 쉽게 문자열의 길이를 구하는 함수를 만들 수 있게 되었습니다. 단순히 `string_length` 만 리턴해 주면 되는 것입니다. 참고로 내부 변수의 내용을 바꾸지 않는다면 꼭 상수 함수로 정의해주는 것이 좋습니다.

```lec-warning
내부 멤버 변수의 값을 바꾸지 않는다면 함수를 꼭 상수로 정의하세요.
```

`length` 함수 역시 `string_length` 의 값을 **읽기만 하므로** 처럼 상수 함수로 정의하였습니다.

```cpp-formatted
int MyString::length() const { return string_length; }
```


다만 이러한 방식으로 문자열의 길이를 구한다면, 문자열 조작시에 `string_length` 의 값을 올바른 값으로 설정해야만 합니다. 예를 들어서, 두 문자열을 서로 더해서 새로운 문자열을 만들 때 새로운 문자열의 `string_length` 는 두 문자열의 `string_length` 의 합이 되겠지요. 마찬가지로 부분 문자열을 추출하거나, 문자 하나를 지우는 등 모든 작업을 할 때 `string_length` 값을 정확하게 조정해야만 합니다.

```cpp-formatted
void MyString::print() {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}
```

그리고 마지막으로, 우리의 `MyString` 클래스의 내용을 보기 위해서, 문자열을 출력하는 함수 `print` 와 `println` 을 만들었습니다. (단지 마지막에 개행을 하느냐 안하느냐의 차이) 마찬가지로 `print` 와 `println` 모두 문자열을 읽기만 하므로 상수 함수로 만들었습니다.

그럼, 우리의 현재 임시로 만들어 놓은 `MyString` 클래스가 잘 작동하고 있는지 살펴보도록 합시다.

```cpp-formatted
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;

  void print() const;
  void println() const;
};

MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
}
MyString::MyString(const char* str) {
  string_length = strlen(str);
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}
MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

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
int main() {
  MyString str1("hello world!");
  MyString str2(str1);

  str1.println();
  str2.println();
}
```



성공적으로 컴파일 하였다면

```exec
hello world!
hello world!
```

와 같이 잘 실행됨을 알 수 있습니다.


###  assign 함수


`assign` 함수는 '지정하다' 라는 뜻을 가진 함수로, 우리가 흔히 생각하는 '=' 과 동일한 역할을 하게 됩니다. 예를 들어서 우리의 `MyString` 변수 `str` 에서

```cpp-formatted
str.assign("abc");
```



를 하게 된다면 `str` 에는 원래 있었던 문자열이 지워지고 `abc` 가 들어가게 되겠지요. 그렇다면 우리는 다음과 같은 두 개의 `assign` 함수를 준비할 수 있습니다.

```cpp-formatted
MyString& assign(const MyString& str);
MyString& assign(const char* str);
```

물론 이 `assign` 함수들의 구현 자체는 매우 간단하게 할 수 있습니다. 저의 경우 다음과 같이 구현하였습니다.

```cpp-formatted
MyString& MyString::assign(const MyString& str) {
  if (str.string_length > string_length) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > string_length) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
```


`string` 의 크기가 작으면 동적 할당을 수행하는데 큰 시간이 필요하지 않겠지만, 우리의 `MyString` 클래스는 어떤 크기의 문자열에 대해서도 좋은 성능을 보여주어야만 하기 때문에 위 처럼 인자로 입력받는 문자열의 크기가, 원래 문자열의 크기 보다 작다면 굳이 동적 할당을 할 필요가 없게 되죠.

따라서 그 경우에는 그냥 그대로 복사하게 됩니다. 하지만, 인자로 입력받는 문자열의 크기가 더 크다면, 현재까지는 이전에 동적으로 할당된 메모리 바로 뒤에 메모리를 추가하는 방법은 없으므로, 새로 동적할당을 해줘야만 합니다.


그런데 이렇나 방식으로 구현하는데에는 약간의 문제가 있습니다. 예를 들어 다음과 같은 상황을 생각해봅시다.

```cpp-formatted
MyString str1("very very very long string");
str1.assign("short string");
str1.assign("very long string");
```



맨 처음에 `str1` 에 아주 긴 문자열을 할당하였습니다. 예를 들어서 그 문자열의 길이가 1000 바이트 라고 생각해봅시다. (물론 위 소스에서는 겨우 몇 바이트 이겠지만 아무튼 아주 긴 문자열이라 생각합시다) 그런 다음에 `str1` 에 다시 짧은 문자열을 `assign` 하였다고 가정합니다.

우리의 `assign` 함수에 따르면 맨 처음에 *아주 긴 문자열* 의 길이가 *짧은 문자열* 보다 훨씬 작을 것이므로 `assign` 시에 특별히 동적 할당을 할 필요 없이 그냥 `string_length` 만을 줄인채 짧은 문자열로 덮어 씌우게 됩니다.


그런데 문제는 다시 `str1` 에 긴 문자열을 `assign` 시에 발생하게 됩니다 (이번의 긴 문자열은 이전의 *아주 긴 문자열* 보다는 약간 짧다고 생각합니다). 비록 `str1` 에 이미 1000 바이트에 달하는 공간이 할당되어 있는데도 불구하고 현재 짧은 문자열이 있기 때문에 새롭게 긴 문자열을 `assign` 시에 이미 1000 바이트가 할당되어 있다는 사실을 알 수 없게 됩니다.

따라서, `assign` 함수는 문자열에 짧은 문자열을 위한 작은 크기에 공간만이 할당되어 있다고 생각하여 메모리를 해제하고 다시 많은 양의 메모리를 할당하는 매우 비효율 적인 작업을 하게 됩니다. 이 과정을 그림으로 나타내면 아래와 같습니다.


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile7.uf.tistory.com%2Fimage%2F2328BB34520B972526BB09)



따라서 이러한 비효율 적인 막기 위해서는 얼마나 많은 공간이 할당되어 있는지 알 수 있는 정보를 따로 보관하는 것이 좋을 것이라 생각됩니다. 이를 위해 `memory_capacity` 라는, 현재 할당된 메모리 공간의 크기를 나타내는 새로운 변수를 추가하였습니다.

```cpp-formatted
MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
```



이렇게 하게 된다면, 앞선 그림에서 나타나는 상황과 같은 문제를 방지할 수 있게 됩니다. 이렇게 `capacity` 를 도입함으로써 여러가지 새로운 함수들을 추가할 수 있게 되었습니다. 예를 들어서, 할당할 문자열의 크기를 미리 예약해 놓는 `reserve` 함수와 현재 문자열의 할당된 메모리 크기를 나타내는 `capacity` 함수를 만들 수 있습니다. 이들은 다음과 같습니다.

```cpp-formatted
int MyString::capacity() { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char *prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
```

참고로 `reserve` 함수의 경우, 만일 할당하려는 크기가 현재의 할당된 크기보다 작다면 굳이 할당할 필요가 없게 됩니다. 따라서 위와 같이 `size` 가 `memory_capacity` 보다 클 경우에만 할당하도록 처리하였습니다. 과연 잘 작동하는지 살펴볼까요.

```cpp-formatted
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);
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

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

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

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
int main() {
  MyString str1("very very very long string");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();
}
```

성공적으로 컴파일 하였다면

```exec
Capacity : 30
String length : 26
very very very long string
```

와 같이 잘 나옴을 알 수 있습니다.


마지막으로 추가할 함수는 임의의 위치의 문자를 리턴하는 함수로, 이전 C 언어에서 `[]` 로 구현되었던 것입니다. C 문자열의 경우 구조상 배열의 범위를 벗어나는 위치에 대한 문자를 요구하여도 이를 처리할 수 밖에 없었는데 (이는 결국 심각한 오류로 이루어졌죠) C++ 의 경우 특정 위치의 문자를 얻는 것을 함수로 만들어서 올바르지 않는 위치에 대한 문제를 처리할 수 잇게 되었습니다.

```cpp-formatted
char MyString::at(int i) const {
  if (i >= string_length || i < 0)
    return NULL;
  else
    return string_content[i];
}
```

위와 같이 `i` 가 허용되는 범위를 초과한다면 `NULL` 을 리턴하도록 하였습니다.

자 이것으로 해서, 우리가 직접 제작한 문자열 클래스 `MyString` 의 기본적인 함수들은 모두 제작하였다고 볼 수 있습니다.

```info
* 문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자
* 문자열의 길이를 리턴하는 함수(length)
* 문자열 대입 함수(assign)
* 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
* 특정 위치의 문자를 리턴하는 함수(at)

```


이제 `MyString` 을 사용하는 다른 프로그래머들은 이 최소한의 인터페이스를 이용해서, 여러가지 문자열에 관련한 모든 작업을 수행할 수 있게 됩니다. 하지만 실제로 여러분이 `MyString` 함수를 널리 편하게 사용하고 싶다면, 더 많은 기능을 제공할 수 있어야 하겠습니다.



###  문자열 삽입하기 (insert)


문자열 처리에서 가장 빈번하게 사용되는 작업으로, 문자열 중간에 다른 문자열을 삽입하는 작업을 들 수 있습니다. 사실 여태까지 만들언 놓은 함수들만을 가지고도 `insert` 작업을 쉽게 구현할 수 있겠지만, 빈번하게 사용되는 작업이다 보니까 미리 만들어 놓아서 인터페이스로 제공하는 것도 나쁘지 않을 것이라 생각됩니다.

```cpp-formatted
MyString& MyString::insert(int loc, const MyString& str);
MyString& MyString::insert(int loc, const char* str);
MyString& MyString::insert(int loc, char c);
```

일단 저의 경우 `insert` 작업이 워낙 다양한 용도로 빈번하게 사용되기 때문에 위와 같은 3 개의 `insert` 함수를 준비하였습니다. 참고로 `loc` 을 어떻게 생각할 지 미리 기준을 정해야 하는데, 일반적으로 `insert` 함수에서 입력 위치를 받는 경우, 그 입력 위치 '앞' 에 문자를 `insert` 하는 경우가 많습니다.

예를 들어서 `abc` 라는 문자열에 `insert(1, "d")` 를 하게 된다면, 1 의 위치에 있는 `b` 앞에 (참고로 모든 위치는 배열의 인덱스로 생각합니다. 즉 `a` 는 0 의 위치) `d` 가 삽입됩니다.


저는 맨 위의 `MyString` 을 인자로 받는 함수 하나만 제작할 것입니다. 왜냐하면 이 함수만 제대로 제작한다면 나머지 아래의 두 함수는

```cpp-formatted
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}
```



와 같이 간단하게 처리할 수 있기 때문이지요. 따라서 우리가 제대로 만들어야 할 함수는 맨 위의 `MyString` 을 인자로 받는 함수 입니다.

```cpp-formatted
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.
    memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
```



제가 만든 `insert` 함수는, 이전의 `assign` 함수 처럼 새로 메모리를 할당해야 할 경우와, 굳이 할당할 필요가 없는 경우를 나누어서 처리하도록 하였습니다. 만일 원 문자열의 길이 `+` 새로 삽입되는 문자열의 길이가, 현재의 할당된 메모리의 크기 보다 크다면 반드시 메모리를 새로 할당해야 하겠지만, 작은 경우에는, 굳이 메모리를 해제하고 재할당하는데 시간을 낭비할 필요가 없게 됩니다.


메모리를 다시 할당해야 하는 경우, 일단 `string_content` 에 새로운 할당된 메모리 주소가 들어가므로, 이전의 메모리 주소를 보관하기 위해 `prev_string_content` 함수를 이용하였습니다. 따라서 이를 이용해서, `string_content` 에 삽입된 문자열을 손쉽게 집어 넣을 수 있었습니다.



반면에, 메모리를 다시 할당할 필요가 없는 경우 원래의 문자열 내용을 이용하며 삽입된 문자열을 `string_content` 에 넣어야 하므로 약간의 트릭을 이용하였습니다. 바로, 자리가 바뀌는 문자열들을 먼저 뒤로 밀어버리는 것입니다. 이미 메모리의 할당된 공간은 충분하기 때문에 뒤로 미는 것을 쉽게 수행할 수 있습니다.

```cpp-formatted
for (int i = string_length - 1; i >= loc; i--) {
  // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
  string_content[i + str.string_length] = string_content[i];
```



예를 들어서 앞서 `abc` 에서 `d` 를 삽입하는 예에서, 1 의 위치에 `d` 를 넣었으므로, 자리가 바뀌는 것들은 `bc` 가 됩니다. 따라서 먼저 `bc` 를 뒤로 밀어버린 다음, 생긴 공간에 `d` 를 집어 넣으면 되는 것입니다. 즉, 위 작업을 수행하면 `abc` 는 `abbc` 가 되고,

```cpp-formatted
// 그리고 insert 되는 문자 다시 집어넣기
for (int i = 0; i < str.string_length; i++)
  string_content[i + loc] = str.string_content[i];
```



를 수행하면, `insert` 되는 문자가 밀린 문자열 공간에 들어가면서 `abbc` 에서 `adbc` 가 됩니다. 실제로 실행해보면 아래와 같이 잘 작동함을 알 수 있습니다.

```cpp-formatted
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
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

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

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

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) {
    return *this;
  }

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.
    memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}
int main() {
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();
}
```

성공적으로 컴파일 하였다면

```exec
Capacity : 30
String length : 16
very long string
very <some string inserted between>long string
```

와 같이 잘 나옵니다.


훌륭한 `MyString` 클래스를 만들기 위해서, 한 가지 좀 더 생각해보아야 할 점들이 있습니다. 과연 `insert` 를 사용하는 경우는 보통 어떤 경우일까요? 많은 경우 `insert` 는 많은 문자열을 한 꺼번에 집어넣는 것이 아니라, 작은 크기의 문자열들을 자주 집어넣는 경우가 많습니다. 

즉, 큰 크기의 문자열을 한 번에 `insert` 하는 작업 보다는 작은 크기의 문자열들을 여러번 `insert` 하는 명령을 많이 수행한다는 뜻이지요. 그런데, 만일 이미 `capacity` 한계에 달한 문자열 클래스에 문자 a 를 계속 추가하는 명령을 생각해보도록 합시다.


```cpp-formatted
while (some_condition) {
  str.insert(some_location, 'a');
}
```



마치 위와 같은 명령 말이지요. 이미 `str` 가 `capacity` 한계에 도달했다고 가정했으므로, 매 `insert` 마다 메모리를 해제하고, 1 만큼 큰 메모리를 할당하는 작업을 반복하게 될 것입니다. 이는 `str` 의 크기가 크다면 엄청난 작업의 낭비가 아닐 수 없습니다.

즉, 짜잘하게 계속 `insert` 하는 명령에서 메모리 할당과 해제를 반복하지 않도록 하기 위해서라면, 통 크게 메모리를 미리 `reserve` 해놓는 것이 필요합니다. 물론, 무턱대고 미리 엄청난 크기의 메모리를 할당해 놓을 수 도 없는 일이지요. 만일 10 바이트 밖에 사용하지 않는데, 이와 같이 짜잘하게 `insert` 하는 문제를 피하기 위해 1000 바이트를 미리 할당해 놓는다면 소중한 자원의 낭비가 될 것입니다.


따라서 'insert 작업에서의 잦은 할당/해제를 피하기 위해 미리 메모리를 할당해놓기' 와 '메모리를 할당해 놓되, 많은 자원을 낭비하지 않는다' 라는 두 조건을 모두 만족하는 방법이 있을까요? 물론 있습니다. 메모리를 미리 할당할 경우, 현재 메모리 크기의 두 배 정도를 할당해 놓는 다는 것입니다. 이를 코드로 표현하면 아래와 같습니다.


```cpp-formatted
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

  // 생략..
```



즉 새로 할당해야 할 메모리 크기(`string_length + str.string_length`) 가 현재의 `memory_capacity` 의 두 배 이하라면, 아예 `memory_capacity` 의 두 배에 달하는 크기를 할당해버리는 것입니다.

그리고 물론 `insert` 되는 문자열의 크기가 엄청 커서 `memory_capacity` 의 두 배를 뛰어 넘어버린다면 그냥 예약을 생각하지 않고 필요한 만큼 할당해버리면 됩니다. 이와 같은 방식으로 처리한다면, 빈번한 메모리의 할당/해제를 막을 수 있고 또 많은 메모리 공간을 낭비하지 않을수 있습니다.


참고로 이러한 방법은 C++ 에서 동적으로 할당되는 메모리를 처리하는데 매우 빈번하게 사용되는 기법중 하나입니다.


```cpp-formatted
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
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

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

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

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}
int main() {
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();
}
```

성공적으로 컴파일 하였다면

```exec
Capacity : 30
String length : 16
very long string
very <some string inserted between>long string
Capacity : 60
String length : 46
very <some string inserted between>long string
```


로 잘 수행됨을 알 수 있습니다.

###  erase 함수


앞서 `insert` 함수를 만들었으니, 이번에는 정 반대의 역할을 하는 `erase` 함수를 만들어보도록 합시다. `erase` 함수는 `insert` 함수보다 만들기 훨씬 쉬운데, 왜냐하면 기본적으로 데이터의 양이 줄어 드는 것이기 때문에 복잡하게 `capacity` 이런 것들을 생각할 필요가 없기 때문입니다.

```cpp-formatted
MyString& erase(int loc, int num);
```

`erase` 함수는 위와 같이 생겼고, `loc` 은 `insert` 와 동일하게 `loc` 의 해당하는 문자 앞 을 의미합니다. 그리고 `num` 은 지우는 문자의 수를 의미하죠. 예를 들어서 `abcd` 라는 문자열에서 `erase(1, 2);` 를 하게 된다면, 1 에 해당하는 문자 'b' 의 앞에서 부터 2 문자를 지우게 되어, `bc` 가 지워져서 `ad` 가 리턴됩니다.

```cpp-formatted
MyString& MyString::erase(int loc, int num) {
  // loc 의 앞 부터 시작해서 num 문자를 지운다.
  if (num < 0 || loc < 0 || loc > string_length) return *this;

  // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
  // 생각하면 됩니다.

  for (int i = loc + num; i < string_length; i++) {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}
```


위와 같이 간단히 처리할 수 있습니다. `string_length` 를 도입하여서 정말 편리한 점이 무엇이냐면, 어차피 `string_length` 뒤에 어떠한 정보가 오든지 간에 별로 신경을 안써도 된다는 점입니다. 위와 같이 앞으로 문자들을 끌고 오면서 뒤의 문자들을 초기화 하지 않았지만, `string_length` 값을 처리하였기 때문에 뒤의 문자들에 신경 쓰지 않아도 됩니다.


물론 실제로 컴파일 해보면


![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile6.uf.tistory.com%2Fimage%2F223EB14F520BCEBF0B22EC)



로 아주 잘 작동함을 알 수 있습니다.



###  find 함수


이제 `insert` 와 `erase` 이외에 매우 빈번하게 사용되는 또 다른 작업으로 `find` 함수가 있습니다. 사실 `insert, erase, find` 는 문자열 연산의 기초 중의 기초라고 불러도 과언이 아닐 만큼 필수적인 함수 입니다. 그렇기 때문에 `find` 함수 자체를 어떻게 구현하느냐에 따라 문자열 클래스의 전반적인 성능이 좌지우지 되는 경우도 있습니다.

왜냐하면 `insert` 와 `erase` 는 사실 연산 시간이 크게 오래 걸리지는 않지만 문자열의 크기가 매우 크다면 `find` 연산은 엄청나게 오래 걸릴 수 있게 될 수 있지요.

문자열을 검색하는 알고리즘은 수 없이 많지만, 어떤 상황에 대해서도 좋은 성능을 발휘하는 알고리즘은 없습니다. (예를 들어 짧은 문자열 검색에 최적화 된 알고리즘과 긴 문자열 검색에 최적화 된 알고리즘들 같이 말입니다) 그렇기에 특별한 알고리즘을 사용하는 경우에는 그 클래스의 사용 목적이 명확해서 그 알고리즘이 좋은 성능을 발휘할 수 있는 경우에만 사용하는 것이 보통입니다. 따라서 우리의 `MyString` 의 경우, 가장 간단한 방법으로 `find` 알고리즘을 구현하기로 하였습니다.

```cpp-formatted
int find(int find_from, MyString& str) const;

int find(int find_from, const char* str) const;
int find(int find_from, char c) const;
```

일단 우리는 앞서 `insert` 함수를 구현한 방법처럼, 맨 위의 `MyString` 을 인자로 받는 `find` 만 제대로 구현한 후에, 아래 두 개의 `find` 는 맨 위의 함수를 이용해서 구현하는 방식으로 처리하였습니다.


참고로 `find` 함수는 `find_from` 에서 부터 시작해서 가장 첫 번째 `str` 의 위치를 리턴하게 됩니다. 그리고 `str` 이 문자열에 포함되어 있지 않다면, -1 을 리턴하게 되지요. 이러한 방법으로, 어떤 문자열 내에 있는 모든 `str` 들을 찾을 수 있는 `for` 문을 생각할 수 도 있을 것입니다.

```cpp-formatted
int MyString::find(int find_from, MyString& str) const {
  int i, j;
  if (str.string_length == 0) return -1;
  for (i = find_from; i < string_length - str.string_length; i++) {
    for (j = 0; j < str.string_length; j++) {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;  // 찾지 못했음
}
```



저의 경우 위와 같이 간단한 방법으로 `find` 함수를 구현하였습니다. `find_from` 부터  시작해서 `string_content` 와 `str` 가 완벽히 일치하는 부분이 생긴다면 그 위치를 리턴하고, 찾지 못할 경우 -1 을 리턴하도록 말이지요. 그럼 잘 작동하는지 살펴보도록 합시다.

```cpp-formatted
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);

  MyString& erase(int loc, int num);

  int find(int find_from, const MyString& str) const;
  int find(int find_from, const char* str) const;
  int find(int find_from, char c) const;
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

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

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

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
  // loc 의 앞 부터 시작해서 num 문자를 지운다.
  if (num < 0 || loc < 0 || loc > string_length) return *this;

  // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
  // 생각하면 됩니다.

  for (int i = loc + num; i < string_length; i++) {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}
int MyString::find(int find_from, const MyString& str) const {
  int i, j;
  if (str.string_length == 0) return -1;
  for (i = find_from; i < string_length - str.string_length; i++) {
    for (j = 0; j < str.string_length; j++) {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;  // 찾지 못했음
}
int MyString::find(int find_from, const char* str) const {
  MyString temp(str);
  return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
  MyString temp(c);
  return find(find_from, temp);
}
int main() {
  MyString str1("this is a very very long string");
  std::cout << "Location of first <very> in the string : " << str1.find(0, "very")
       << std::endl;
  std::cout << "Location of second <very> in the string : "
       << str1.find(str1.find(0, "very") + 1, "very") << std::endl;
}
```

성공적으로 컴파일 하였다면

```exec
Location of first <very> in the string : 10
Location of second <very> in the string : 15
```


와 같이 잘 처리되고 있음을 알 수 있습니다. 참고로 첫 번째 `str1.find(0, "very")` 에서는, 맨 처음 부터 시작해서 "very" 를 찾습니다. 그 결과 10 의 위치에 있음을 알 수 있었지요. 그 다음 "very" 를 찾기 위해 이전의 검색 한 위치 바로 다음 부터 시작하여 또 "very" 를 찾습니다. 그 결과 15 의 위치에 있는 "very" 를 찾을 수 있게 됩니다.


###  크기 비교 함수 `compare`


마지막으로 만들 함수는 문자열 간의 크기를 비교하는 `compare` 함수 입니다. 여기서 '크기' 를 비교한다는 의미는 사전식으로 배열해서 어떤 문자열이 더 뒤에 오는지 판단한다는 의미가 됩니다. 이 함수를 이용해서 문자열 전체를 정렬하는 함수라던지, 기존의 C 언어에서 `strcmp` 함수 등으로 지원하였던 것들을 그대로 사용할 수 있게 됩니다.

```cpp-formatted
int compare(const MyString& str) const;
```



일단 함수의 원형은 위와 같이 `*this` 와 `str` 을 비교하는 형태로 이루어집니다.

```cpp-formatted
int MyString::compare(const MyString& str) const {
  // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
  // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
  // 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.

  for (int i = 0; i < std::min(string_length, str.string_length); i++) {
    if (string_content[i] > str.string_content[i])
      return 1;

    else if (string_content[i] < str.string_content[i])
      return -1;
  }

  // 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
  // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

  if (string_length == str.string_length) return 0;

  // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
  else if (string_length > str.string_length)
    return 1;

  return -1;
}
```



참고로 말하면 `abc` 와 `abcd` 의 크기를 비교하면 `abc` 가 `abcd` 보다 사전식으로 더 앞에 오게 됩니다. 따라서 이에 대한 처리는 뒷부분에서 따로 하게 됩니다. 그리고 한 가지 더 말하자면 `std::min` 과 `std::max` 함수는 `iostream` 를 `include` 하면 사용할 수 있는 함수들 이므로, 굳이 귀찮게 만드실 필요는 없습니다.

```cpp-formatted
#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);

  MyString& erase(int loc, int num);

  int find(int find_from, const MyString& str) const;
  int find(int find_from, const char* str) const;
  int find(int find_from, char c) const;

  int compare(const MyString& str) const;
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

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

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

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) return *this;

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.

    if (memory_capacity * 2 > string_length + str.string_length)
      memory_capacity *= 2;
    else
      memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
  // loc 의 앞 부터 시작해서 num 문자를 지운다.
  if (num < 0 || loc < 0 || loc > string_length) return *this;

  // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
  // 생각하면 됩니다.

  for (int i = loc + num; i < string_length; i++) {
    string_content[i - num] = string_content[i];
  }

  string_length -= num;
  return *this;
}
int MyString::find(int find_from, const MyString& str) const {
  int i, j;
  if (str.string_length == 0) return -1;
  for (i = find_from; i < string_length - str.string_length; i++) {
    for (j = 0; j < str.string_length; j++) {
      if (string_content[i + j] != str.string_content[j]) break;
    }

    if (j == str.string_length) return i;
  }

  return -1;  // 찾지 못했음
}
int MyString::find(int find_from, const char* str) const {
  MyString temp(str);
  return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
  MyString temp(c);
  return find(find_from, temp);
}
int MyString::compare(const MyString& str) const {
  // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
  // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
  // 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.

  for (int i = 0; i < std::min(string_length, str.string_length); i++) {
    if (string_content[i] > str.string_content[i])
      return 1;

    else if (string_content[i] < str.string_content[i])
      return -1;
  }

  // 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
  // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

  if (string_length == str.string_length) return 0;

  // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
  else if (string_length > str.string_length)
    return 1;

  return -1;
}
int main() {
  MyString str1("abcdef");
  MyString str2("abcde");

  std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
}
```



성공적으로 컴파일 하였다면

```exec
str1 and str2 compare : 1
```


와 같이 잘 나옴을 알 수 있습니다.


이것으로, 여태까지 배운 C++ 에 대한 내용을 종합해서 훌륭한 `MyString` 클래스를 만들었다고 볼 수 있습니다. 우리의 `MyString` 클래스는 다음과 같은 인터페이스를 제공합니다.

* 문자 c 혹은 C 형식 문자열 str 에서 생성할 수 있는 생성자와 복사 생성자
* 문자열의 길이를 리턴하는 함수(length)
* 문자열 대입 함수(assign)
* 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
* 특정 위치의 문자를 리턴하는 함수(at)
* 특정 위치에 특정 문자열을 삽입하는 함수(insert)
* 특정 위치의 특정 개수의 문자를 지우는 함수(erase)
* 특정 위치를 시작으로 특정 문자열을 검색하는 함수(find)
* 두 문자열을 사전식 비교하는 함수(compare)


이 정도면 괜찮은 문자열 클래스라고 볼 수 있지 않나요 ㅎㅎ. 이번 강좌를 통해서 현재 까지 배운 C++ 클래스에 좀더 친숙해 질 수 있는 좋은 경험이 되었으면 합니다. 자, 그럼 이것으로 이번 강좌를 마치도록 하겠습니다.


###  생각해보기

#### 문제 1

여러가지 검색 알고리즘(KMP, Boyer - Moore) 들을 이용하는 `find` 함수를 만들어보세요. 어떤 알고리즘의 경우 미리 계산된 테이블이 필요할 텐데, 이러한 정보들 역시 `class` 변수로 처리하셔도 됩니다. (난이도 : 上)

##@ chewing-cpp-end