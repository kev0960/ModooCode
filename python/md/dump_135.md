----------------
title : 씹어먹는 C++ 강좌 계획
next_page: 134
publish_date : 2011-03-06
chapter : C++ 을 시작하기에 앞서
--------------

![](/img/ChewingCpplogo.png)

안녕하세요 여러분~ 이제 C 언어에 이어서 C++ 강좌를 연재하게 된 이재범 입니다. 저의 C++ 강좌는 여러분이 C 언어를 충분히 이해하고 사용하고 있다는 것을 가정으로 진도를 나갈 것입니다.


물론 C 언어를 굳이 배우지 않은 상태에서 C++ 을 첫 언어로 배워도 상관 없습니다. C 언어와 C++ 은 아예 다른 언어기 때문에 **무엇을 먼저 배워야 하냐 라는 의미는 크게 중요하지 않습니다.** 하지만 C++ 이 C 의 기초적인 문법을 그대로 사용하고 있고, 제가 C 언어 강의를 먼저 완성하였기 때문에 독자 타겟을 **C 언어 문법을 어느 정도 아는 사람** 으로 잡았을 뿐입니다.

다시 말해 구질 구질하게 `for` 문 사용법, 포인터와 같은 것들은 C++ 강좌에서 다루지 않겠다는 의미 입니다.

간혹 C++ 이 C 언어 확장팩(?) 개념이라고 생각하시는 분들이 있는데 이건 역시 사실이 아닙니다. 물론 초기에는 C++ 이름이 *C with classes* 였을 정도로 그냥 C 언어에 몇 가지 정도를 더 얹은 정도였습니다. 하지만 이제는 C++ 과 C 언어가 *둘이 같은 언어야?* 라고 말할 수 있을 정도로 매우 달라졌습니다.

### 왜 C++ 을 배우냐

C++ 은 전세계에서 가장 사랑 받는 언어들 중 하나입니다. 그 사용 예시를 따지면 수 도 없이 많은데 몇 가지 꼽아보자면

* 많은 게임들과 게임 엔진들 (Unity, Unreal 등등)
* 대부분의 컴파일러 (gcc, clang 등)
* 동영상 및 오디오 처리
* 운영체제 (대표적으로 마이크로소프트의 윈도우즈가 C++ 로 쓰여져 있습니다)
* 상용 프로그램들 (예를 들어 포토샵)
* 크롬 브라우저
* 딥러닝 프레임워크 (Tensorflow, PyTorch 모두 파이썬은 인터페이스 일 뿐 내부적으론 모두 C++ 로 만들어져 있습니다.)
* 서버 프로그램 (구글의 검색 서버도 C++ 로 만들어져 있습니다.)
* 그 외 금융쪽이나 많은 연산이 필요한 경우들...

등등 수 도 없이 많습니다. 특히 위와 같이 프로그램의 성능이 중요한 부분에서 널리 쓰이고 있죠. 

다만 많은 사람들이 하나같이 손꼽아서 이야기하는 C++ 의 큰 단점이 있는데 바로 **쓰기 어렵다** 입니다. 맞습니다. 정말로 C++ 을 제대로 공부하지 않는다면 쏟아지는 수 많은 컴파일 오류들과 복잡한 템플릿 문법, 그리고 우측값 좌측값이니 하는 값 카테고리 등등, 덕분에 많은 좌절감을 느끼실 것입니다. 

하지만 제 생각으로는 이 문제들은 모두 **C++ 을 제대로 공부하지 않아서** 발생하는 문제라고 생각하고 굳이 언어를 배우지 않는 시점에서 너무 두려워 할 필요가 없음을 알려드리고 싶습니다. 특히 제 강좌를 통해서 C++ 이 **생각했던 것 보다는 괜찮다** 라는 것을 전해드리고 싶네요. 위 많은 프로그램들이 C++ 로 쓰여져 있는 것은 분명히 이유가 있을 테니까요!

### 강의 가이드라인

아무래도 이 강좌를 보러오시는 분들이 다 같은 출발 선상에 있는 것이 아닐 테니 어떤 강좌들을 먼저 보면 좋을지에 대해 아래와 같은 가이드라인을 제안해드립니다. 본인의 현재 상황에 맞게 적절한 강좌를 찾아 보세요.

* **나는 컴퓨터 프로그래밍을 한 번도 해본적이 없다** : 아무래도 이 강의는 적합하지 않은 것 같습니다. 일단 기본적으로 C 언의 문법을 알고 있다고 가정하고 시작하거든요. 만일 C 언어를 먼저 배우고 싶다면 [이 강의](/231) 을 먼저 보고 와주세요
* **얼마 전에 C 언어를 대충 공부했는데 C++ 을 배워보고 싶다** : 좋습니다! 처음부터 찬찬히 보시기를 바랍니다.
* **C++ 문법을 대충 아는데 좀 더 심도 있게 공부하고 싶다**: 이 분들도 환영입니다. 중간 중간 내용은 스킵해도 되고, 템플릿을 본격적으로 다루는 [9 - 1 강의](/219) 부터 보시면 좋을 것이라 생각합니다. 
* **프로그래밍 대회를 위해 C++ 자료 구조를 복습하고 싶다**: C++ 의 여러가지 자료구조들을(`vector`, `map`, `unordered_map` 등등) 빠르게 짚고 넘어가고 싶다면 [10 - 1](/223), [2](/224), [3](/225) 강의를 보시는 것을 추천합니다.
* **최근 나온 C++ 기능들에 대해 알아보고 싶다** : [9 - 2 강의](/290) 부터 거의 대부분 C++ 11 에 도입된 내용들 입니다. 만일 C++ 17 에 새로 추가된 내용들을 공부하고 싶다면 [17 - 4](/306), [5](/309) 를 보시면 됩니다.


### C++ 강의를 시작하기에 앞서

![caption=이 아저씨가 바로 C++ 의 아버지인 Bjarne Stroustrup 입니다](/img/cpp/cppfather.jpg)

C++ 은 역사가 매우 긴 언어 입니다. 1979년에 컴퓨터 과학자인 Bjarne Stroustrup 이 C 언어에 *클래스* 라는 개념을 적립한 *C with Classes* 라는 언어가 C++ 의 전신인데, 1982년에 해당 언어를 조금 발전 시켜서 **C++** 이라는 이름을 붙였습니다. 그리고 1998년에 C++ 의 첫 번째 표준이 공개되었는데 이를 **C++ 98** 이라고 부릅니다. 2003년에 표준안에 작은 몇 가지 개정이 있었지만 언어 자체는 크게 바뀌지 않았습니다. 씹어먹는 C++ 강좌 초반에 9 장 까지 내용들이 바로 이 시절에 추가된 개념들 입니다.

그 동안 언어가 정체 상태에 있다가 비로소 2011년이 되서야 흔히 말하는 **대격변 패치**를 받고 여러가지 새로운 개념들이 추가되었습니다. 이 버전의 C++ 을 **C++ 11** 이라고 하는데, 우리 강좌 9 장 부터 해당 내용들을 다루게 됩니다. 참고로 C++ 11 부터 **Modern C++** 이라고 부릅니다.\sidenote{재미있는 사실은 원래 이 개정안이 2010 년 안에 마무리 될 줄 알고 C++ 0x 라고 불리었습니다. 하지만 너무나 많은 변화가 필요하였기에 시간 내에 마무리 하지 못하고 C++ 11 이 되버렸습니다.}

그 후로 3 년 마다 C++ 언어의 새로운 표준안이 공개되고 또 컴파일러들에게 반영이 되고 있습니다. C++ 14 와 C++ 17 에서는 비교적 작은 변화만 있었는데, C++ 20 에서 또다른 대규모의 업그레이드를 받을 예정입니다.

참고로 C++ 은 이전 버전과 호환이 꽤나 괜찮은 언어 중에 하나 입니다. 따라서 새로운 버전이 나오더라도 기존의 코드를 거의 대부분의 경우 무리 없이 컴파일 할 수 있습니다. 쉽게 말해 C++ 11 컴파일러로 C++ 98 코드를 무리 없이 컴파일 할 수 있다는 의미 입니다.\sidenote{물론 이전 버전 호환성이 언어 차원에서 과격한 변화를 가져오기 힘들다는 문제도 있습니다. C++ 과 반대되는 예시가 Python 을 들 수 있는데 Python2 에서 Python3 으로 가면서 언어 간의 호환성을 버리는 대신에 많은 개선을 할 수 있었죠.}

### 강좌 수칙

제 강좌를 들으시면서 지켜야 할 수칙들은 다음과 같습니다.

1. 강좌는 적어도 한 번 꼭 정독해보기
1. 모르는 것은 꼭 답글 달기
1. 답글로 질문하기 꺼린 내용은 kev0960@gmail.com 으로 메일 보내기!
1. '생각 해보기' 에 적어도 30 분 이상은 투자하기
1. 이전 강좌를 완벽히 이해했다 싶지 않으면 다음 강좌로 넘어가지 말기

입니다. 위 수칙 중에서 무엇보다도 중요한 것은 바로 모르는 내용은 꼭 답글을 다는 것입니다 :) 
세상에서 어리석은 질문은 없습니다. 여러분들이 궁금하거나 이상한 내용, 마음에 와닿지 않는 내용들을 질문하지 않고 다음강좌로 넘어가는 한 여러분의 실력은 결코 향상될 수 없을 것입니다.

꼭 궁금한 것들은 댓글로 남겨주시고, 공개적으로 남기기 꺼리면 비밀글로 남기거나 정 그렇다면 제 메일로 보내주시면 감사하겠습니다. 그러면 제가 확인하는대로 최대한 빨리 답글로 보내드릴께요 ㅎ

```warning
[참고로 이 강좌는 Visual Studio 2017 커뮤니티 버전을 사용하고 있습니다. 여기를 클릭해서 사용법을 미리 숙지하는게 좋겠습니다.](http://itguru.tistory.com/220)
```

그렇다면 이제 강좌를 보러갈 시간이 되었네요~


### C++ 강좌 총 목록

```latex-only
앞의 차례를 참고하시기 바랍니다.
```

###@ [1 - 1. 자~ C++ 의 세계로](http://itguru.tistory.com/134)

```html-only
이번 강좌에는 `Visual Studio 2010` 을 설치하고 첫번째 C++ 프로그램을 만들어본다.
```

###@ [1 - 2. 첫 C++ 프로그램 분석하기](http://itguru.tistory.com/136)

```html-only
이번 강좌에서는 첫번째 C++ 에 관한 상세한 분석 및 `namespace` (이름 공간) 에 대해 알아본다
```

###@ [1 - 3. C++ 은 C 친구 - C 와 공통점](http://itguru.tistory.com/138)

```html-only
기초적인 변수의 정의, `if`, `else`, `switch`, `for`, `while`, 배열 등등
```

###@ [2. C++ 참조자(레퍼런스)의 도입](http://itguru.tistory.com/141)

```html-only
C++ 에 새로 도입된 개념인 참조자(레퍼런스) 에 대해 알아본다
```

###@ [3. C++ 의 세계로 오신 것을 환영합니다(new, delete)](http://itguru.tistory.com/169)

```html-only
`new`, `delete`, 그리고 왜 객체 지향 프로그래밍을 해야 하는가?
```

###@ [4 - 1. 이 세상은 객체로 이루어져 있다](http://itguru.tistory.com/172)

```html-only
객체 지향 프로그래밍은 무엇인가?, 객체와 클래스, 접근 제어자
```

###@ [4 - 2. 클래스의 세계로 오신 것을 환영합니다 (함수의 오버로딩, 생성자)](http://itguru.tistory.com/173)

```html-only
함수의 오버로딩(function overloading), 생성자(constructor), 디폴트 생성자(default constructor)
```

###@ [4 - 3. 스타크래프트를 만들자 ① (복사 생성자, 소멸자)](http://itguru.tistory.com/188)

```html-only
복사 생성자(copy constructor), 얕은 복사, 깊은 복사, 소멸자(destructor)
```

###@ [4 - 4. 스타크래프트를 만들자 ② (const, static)](http://itguru.tistory.com/197)

```html-only
생성자 초기화자 리스트(initializer list), `const`, `static` 멤버 변수, 레퍼런스를 리턴하는 함수, `this` 포인터, `const` 멤버함수
```

###@ [4 - 5. 내가 만드는 String 클래스](http://itguru.tistory.com/198)

```html-only
직접 `String` 클래스를 제작해서 여태까지 클래스에 대해 배웠던 내용을 복습하며 정리한다.
```

###@ [4 - 6. 클래스의 explicit 과 mutable 키워드](/253)

```html-only
클래스의 `explicit` 과 `mutable` 키워드에 대해 다룹니다.
```

###@ [5 - 1. 내가 만든 연산자 - 연산자 오버로딩](http://itguru.tistory.com/202)

```html-only
연산자 오버로딩의 기초적인 개념 정리와 함께, 산술, 비교, 대입 연산자의 오버로딩을 수행한다.
```

###@ [5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩](http://itguru.tistory.com/203)

```html-only
멤버함수가 아닌 표현의 연산자 오버로딩과 함께, 입출력 연산자, 첨자 연산자([]), 타입 변환 연산자, 증감 연산자(++, --)들의 오버로딩에 대해 알아본다.
```
 
###@ [5 - 3. 연산자 오버로딩 프로젝트 - N 차원 배열](http://itguru.tistory.com/204)

```html-only
C++ 스타일의 캐스팅, 디폴트 인자(default argument), 반복자(iterator), 그리고 N 차원 배열 제작에 대해 알아본다.
```

###@ [6 - 1. C++ 표준 문자열 & 부모의 것을 물려쓰자 - 상속](http://itguru.tistory.com/209)

```html-only
C++ 표준 문자열, 상속 (inheritance), `protected` 키워드에 대해 알아본다.
```

###@ [6 - 2. 가상(virtual) 함수와 다형성](http://itguru.tistory.com/210)

```html-only
*is-a* 와 *has-a* 관계. 오버라이딩, `virtual` 키워드, 가상(virtual) 함수, 다형성(polymorphism)
```

###@ [6 - 3. 가상함수와 상속에 관련한 잡다한 내용들](http://itguru.tistory.com/211)

```html-only
`virtual` 소멸자, 가상 함수 테이블, 다중 상속, 가상 상속
```

###@ [7 - 1. C++ 에서의 입출력 (istream, ostream)](http://itguru.tistory.com/213)

```html-only
C++ 입출력 라이브러리, `istream`, `ostream`, `streambuf` 에 대해 알아본다.
```

###@ [7 - 2. C++ 파일 입출력 (ifstream, ofstream, stringstream)](http://itguru.tistory.com/215)

```html-only
C++ 에서의 파일 입출력, `stringstream` 과 그 활용에 대해 알아본다 C++ 에서의 파일 입출력, `stringstream` 과 그 활용에 대해 알아본다.
```

###@ [8 - 1. Excel 만들기 프로젝트 1부](http://itguru.tistory.com/217)

```html-only
여태까지 배운 내용을 총 동원 하여 조그만 엑셀을 만드는 프로젝트이다.
```

###@ [8 - 2. Excel 만들기 프로젝트 2부](http://itguru.tistory.com/218)

```html-only
이전 강좌에서 이어서 엑셀 만들기를 진행한다. 중위 표기법과 후위 표기법에 대해 다룬다.
```

###@ [9 - 1. 코드를 찍어내는 틀 - C++ 템플릿(Template)](http://itguru.tistory.com/219)

```html-only
템플릿이란 무엇인가?, 함수 템플릿, 클래스 템플릿. 템플릿 인스턴스화, 템플릿 특수화. 함수 객체 (Functor), 타입이 아닌 템플릿 인자, 디폴트 템플릿 인자
```

###@ [9 - 2. 가변 길이 템플릿 (Variadic template)](/290)

```html-only
가변 길이 템플릿, 템플릿 파라미터 팩(parameter pack), fold expression
```

###@ [9 - 3. 템플릿 메타 프로그래밍 (Template Meta Programming)](http://itguru.tistory.com/221)

```html-only
타입이 아닌 인자를 받는 템플릿, 템플릿 메타 프로그래밍
```

###@ [9 - 4. 템플릿 메타 프로그래밍 2 (Template Meta Programming)](http://itguru.tistory.com/222)

```html-only
TMP 마무리, 의존 타입(dependent type), `auto` 키워드
```

###@ [10 - 1. C++ 의 표준 템플릿 라이브러리 (STL) - 시퀀스 컨테이너](http://itguru.tistory.com/223)

```html-only
시퀀스 컨테이너 (`vector`, `list`, `deque`), 반복자(`iterator`), 범위 기반 `for` 문 (range based for)
```

###@ [10 - 2. C++ 의 표준 템플릿 라이브러리 (STL) - 연관 컨테이너](http://itguru.tistory.com/224)

```html-only
`set`, `multiset`, `map`, `multimap`, `unordered_set`, `unordered_map` 등에 대해 배웁니다.
```

###@ [10 - 3. C++ STL - 알고리즘(algorithm)](http://itguru.tistory.com/225)

```html-only
STL 알고리즘 라이브러리, 람다 함수, `sort`, `partial_sort`, `stable_sort`, `find`, `erase`, `erase_if`, `any_of`, `all_of`
```

###@ [10 - 4. C++ 문자열의 모든 것 (string 과 string_view)](/292)

```html-only
C++ 의 표준 문자열 라이브러리인 `basic_string` 과 여러가지 문자열 리터럴 정의 방식과 인코딩 방식, 그리고 `string_view` 의 사용법에 대해 다룬다.
```

###@ [11. C++ 에서의 예외 처리](/230)

```html-only
`try .. catch` 와 `throw` 를 사용한 C++ 스타일의 예외 처리 방식에 대해 배운다.
```

###@ [12 - 1. 우측값 레퍼런스와 이동 생성자](http://itguru.tistory.com/227)

```html-only
복사 생략 (copy elision), C++ 11 에 추가된 우측값 레퍼런스 (rvalue reference)와 이동 생성자 (move constructor)
```

###@ [12 - 2. Move 문법 (move semantics) 과 완벽한 전달 (perfect forwarding)](http://itguru.tistory.com/228)

```html-only
move semantics, 완벽한 전달 (perfect forwarding), 레퍼런스 접힘 규칙 (reference collapsing rule)
```

###@ [13 - 1. 객체의 유일한 소유권 (unique_ptr)](/229)

```html-only
C++ 에서의 RAII 패턴과 `unique_ptr` 의 사용법에 대해 배웁니다.
```

###@ [13 - 2. 자원을 공유할 때 - shared_ptr 와 weak_ptr](/252)

```html-only
`shared_ptr`, `weak_ptr` 의 사용법에 대해 배웁니다.
```

###@ [14. 함수를 객체로! (C++ std::function, std::mem_fn, std::bind)](/254)

```html-only
Callable 의 정의와 `std::function`, `std::mem_fn`, `std::bind` 들의 사용법을 배운다.
```

###@ [15 - 1. 동시에 실행을 시킨다고? - C++ 쓰레드(thread)](/269)

```html-only
프로세스와 쓰레드, 왜 멀티 쓰레드 프로그래밍을 하는가. C++ `thread` 의 시작
```

###@ [15 - 2. C++ 뮤텍스(mutex) 와 조건 변수(condition variable)](/270)

```html-only
경쟁 상태 (Race Condition), 뮤텍스 (mutex) 와 데드락 (deadlock), 생산자 - 소비자 패턴, `condition_variable` 에 대해 다룹니다.
```

###@ [15 - 3. C++ memory order 와 atomic 객체](/271)

```html-only
CPU 와 컴파일러에서의 명령어 재배치, `atomic`, `memory_order` 에 대해 다룹니다.
```

###@ [15 - 4. C++ future, promise, packaged_task, async](/284)

```html-only
비동기적 작업을 쉽게 할 수 있도록 도와주는 `future`, `promise`, `packaged_task`, `async` 들의 사용법에 대해 다룹니다.
```

###@ [15 - 5. C++ 쓰레드풀 (ThreadPool) 만들기](/285)

```html-only
여태 까지 배운 내용들을 활용해서 쓰레드풀(ThreadPool) 클래스를 만듧니다.
```

###@ 15 - 6. C++ 17 의 병렬 알고리즘 사용하기

###@ [16 - 1. C++ 유니폼 초기화(Uniform Initialization)](/286)

```html-only
C++ 11 에 도입된 유니폼 초기화(uniform initialization)와 초기화자 리스트 (`initializer_list`) 의 사용법에 대해 다룹니다.
```

###@ [16 - 2. constexpr 와 함께라면 컴파일 타임 상수는 문제없어](/293)

```html-only
`constexpr` 키워드를 이용해서 컴파일 타임 상수 생성을 알아본다. 
```

###@ [16 - 3. 타입을 알려주는 키워드 decltype 와 친구 std::declval](/294)

```html-only
C++ 11 에 추가된 `decltype` 와 C++ 의 값 카테고리 (\serif{lvalue, prvalue, xvalue, glvalue, rvalue}), `std::declval` 함수에 대해 다룬다.
```

###@ [17 - 1. type_traits 라이브러리, SFIANE, enable_if](/295) 

```html-only
`type_traits` 라이브러리의 여러가지 메타 함수들 (`enable_if` 와 `void_t`) 에 대해 살펴보면서 SFINAE 를 통해 원하는 타입만을 받는 함수들을 만들어본다.
```

###@ [17 - 2. 정규 표현식(<regex>) 라이브러리 소개](/303)

```html-only
C++ 11 에 추가된 정규 표현식 라이브러리 (`<regex>`) 의 사용법에 대해 다룬다. 
```

###@ [17 - 3. 난수 생성(<random>)과 시간 관련 라이브러리(<chrono>) 소개](/304)

```html-only
C++ 11 에 추가된 난수 생성 라이브러리 (`<random>`) 과 시간 관련 라이브러리 (`<chrono>`) 의 사용법을 알아봅니다.
```

###@ [17 - 4. C++ 17 - 파일시스템(<filesystem>) 라이브러리 소개](/306)

```html-only
C++ 17 에 추가된 파일 시스템 (`<filesystem>`) 라이브러리 사용법을 알아봅니다.
```

###@ [17 - 5. C++ 17 의 std::optional, variant, tuple 살펴보기](/309)

```html-only
C++ 11 에 추가된 `tuple` 과 C++ 17 에 추가된 `optional` 과 `variant` 의 사용법에 대해 알아봅니다.
```

###@ [18. 강의를 마치며](/310)

### 부록

이 부분 부터는 C++ 언어 자체와는 직접 관련은 없지만 실제로 C++ 을 프로그래밍 하기 위해서 필요한 지식들과 여러가지 유용한 도구들에 대해서 이야기 하고자 합니다

###@ [19 - 1. Make 사용 가이드 (Makefile 만들기)](/311)

```html-only
Makefile 의 문법에 대한 이해와 함께 만능 Makefile 을 만들어본다.
```