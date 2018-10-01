----------------
title : 씹어먹는 C++ 강좌 계획
--------------





![](http://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile23.uf.tistory.com%2Fimage%2F244D624E51A1FE1210DC30)



안녕하세요 여러분~ 이제 C 언어에 이어서 C++ 강좌를 연재하게 된 Psi 입니다. 저의 C++ 강좌는 여러분이 C 언어를 충분히 이해하고 사용하고 있다는 것을 가정으로 진도를 나갈 것입니다.


물론C 언어를 굳이 배우지 않아도 C++ 를 먼저 배워도 되고,  C 언어와 C++ 이 매우 다르기 때문에 '무엇을 먼저 배워야 하냐' 라는 의미는 크게 중요하지 않습니다. 하지만 C++ 이 C 의 기초적인 문법을 그대로 사용하고 있고, 제가 강좌를 C 언어를 먼저 완성하였기 때문에 독자 타겟 C 언어를 굳이 배우지 않아도 C++ 를 먼저 배워도 되고,  C 언어와 C++ 이 매우 다르기 때문에 '무엇을 먼저 배워야 하냐' 라는 의미는 크게 중요하지 않습니다. 하지만 C++ 이 C 의 기초적인 문법을 그대로 사용하고 있고, 제가 강좌를 C 언어를 먼저 완성하였기 때문에 독자 타겟을'C 언어 문법을 어느 정도 아는 사람' 으로 잡았을 뿐입니다.


다시 말해 구질 구질하게 기초적인 `for` 문 사용법, 포인터와 같은 것들은 C++ 강좌에서 다루지 않겠다는 의미 입니다.

간혹 C++ 이 C 언어 확장팩(?) 개념이라고 생각하시는 분들이 있는데 이건 역시 사실이 아닙니다. 물론 초기에는 C++ 이름이 `C with classes` 였을 정도로 그냥 C 언어에 몇 가지 정도를 더 얹은 정도였습니다. 하지만 이제는 C++ 과 C 언어가 '둘이 같은 언어야?' 라고 말할 수 있을 정도로 매우 달라졌습니다.



###  강좌 수칙


제 강좌를 들으시면서 지켜야 할 수칙들은 다음과 같습니다.

1. 강좌는 적어도 한 번 꼭 정독해보기
1. 모르는 것은 꼭 답글 달기
1. 답글로 질문하기 꺼린 내용은 kev0960@gmail.com 으로 메일 보내기!
1. '생각 해보기' 에 적어도 30 분 이상은 투자하기
1. 이전 강좌를 완벽히 이해했다 싶지 않으면 다음 강좌로 넘어가지 말기

입니다. 위 수칙 중에서 무엇보다도 중요한 것은 바로 모르는 내용은 꼭 답글을 다는 것입니다 :)
세상에서 어리석은 질문은 없습니다. 여러분들이 궁금하거나 이상한 내용, 마음에 와닿지 않는 내용들을 질문하지 않고 다음강좌로 넘어가는 한 여러분의 실력은 결코 향상될 수 없을 것입니다.
꼭 궁금한 것들은 댓글로 남겨주시고, 공개적으로 남기기 꺼리면 비밀글로 남기거나 정 그렇다면 `mail` 로 보내주시면 감사하겠습니다. 그러면 제가 확인하는대로 최대한 빨리 답글로 보내드릴께요 ㅎ

```warning
 [참고로 이 강좌는 Visual Studio 2017 커뮤니티 버전을 사용하고 있습니다. 여기를 클릭해서 사용법을 미리 숙지하는게 좋겠습니다.](http://itguru.tistory.com/220)
```


그렇다면 이제 강좌를 보러갈 시간이 되었네요~


###  C++ 강좌 총 목록

###@ [1 - 1. 자~ C++ 의 세계로](http://itguru.tistory.com/134)

이번 강좌에는 `Visual Studio 2010` 을 설치하고 첫번째 C++ 프로그램을 만들어본다.

###@ [1 - 2. 첫 C++ 프로그램 분석하기](http://itguru.tistory.com/136)

이번 강좌에서는 첫번째 C++ 에 관한 상세한 분석 및 `namespace` (이름 공간) 에 대해 알아본다

###@ [2 - 1. C++ 은 C 친구 - C 와 공통점](http://itguru.tistory.com/138)

기초적인 변수의 정의, `if, else, switch for, while,` 배열 등등

###@ [2 - 2. C++ 은 C 친구일까?](http://itguru.tistory.com/141)

함수의 정의, 레퍼런스 등등

###@ [3. C++ 의 세계로 오신 것을 환영합니다(new, delete)](http://itguru.tistory.com/169)

`new, delete,` 그리고 왜 객체 지향 프로그래밍을 해야 하는가?

###@ [4 - 1. 이 세상은 객체로 이루어져 있다](http://itguru.tistory.com/172)

객체 지향 프로그래밍은 무엇인가?, 객체와 클래스, 접근 제어자

###@  [4 - 2. 클래스의 세계로 오신 것을 환영합니다 (함수의 오버로딩, 생성자)](http://itguru.tistory.com/173)

함수의 오버로딩(function overloading), 생성자(constructor), 디폴트 생성자(default `constructor)`

###@ [4 - 3. 스타크래프트를 만들자 ① (복사 생성자, 소멸자)](http://itguru.tistory.com/188)

복사 생성자(copy constructor), 얕은 복사, 깊은 복사, 소멸자(destructor)

###@ [4 - 4. 스타크래프트를 만들자 ② (const, static)](http://itguru.tistory.com/197)

생성자 초기화 리스트(initializer list), `const, static` 멤버 변수, 레퍼런스를 리턴하는 함수, `this` 포인터, `const` 멤버함수

###@ [4 - 5. 내가 만드는 String 클래스](http://itguru.tistory.com/198)

직접 `String` 클래스를 제작해서 여태까지 클래스에 대해 배웠던 내용을 복습하며 정리한다.

###@ [5 - 1. 내가 만든 연산자 - 연산자 오버로딩](http://itguru.tistory.com/202)

연산자 오버로딩의 기초적인 개념 정리와 함께, 산술, 비교, 대입 연산자의 오버로딩을 수행한다.

###@ [5 - 2. 입출력, 첨자, 타입변환, 증감 연산자 오버로딩](http://itguru.tistory.com/203)

멤버함수가 아닌 표현의 연산자 오버로딩과 함께, 입출력 연산자, 첨자 연산자([]), 타입 변환 연산자, 증감 연산자(++, --)들의 오버로딩에 대해 알아본다.
 
###@ [5 - 3. 연산자 오버로딩 프로젝트 - N 차원 배열](http://itguru.tistory.com/204)

C++ 스타일의 캐스팅, 디폴트 인자(default argument), 반복자(iterator), 그리고 `N` 차원 배열 제작에 대해 알아본다 C++ 스타일의 캐스팅, 디폴트 인자(default argument), 반복자(iterator), 그리고 `N` 차원 배열 제작에 대해 알아본다.

###@ [6 - 1. C++ 표준 문자열 & 부모의 것을 물려쓰자 - 상속](http://itguru.tistory.com/209)

C++ 표준 문자열, 상속 (inheritance), `protected` 키워드에 대해 알아본다.

###@ [6 - 2. 가상(virtual) 함수와 다형성](http://itguru.tistory.com/210)

*is-a* 와 *has-a* 관계. 오버라이딩, `virtual` 키워드, 가상(virtual) 함수, 다형성(polymorphism)

###@ [6 - 3. 가상함수와 상속에 관련한 잡다한 내용들](http://itguru.tistory.com/211)

`virtual` 소멸자, 가상 함수 테이블, 다중 상속, 가상 상속

###@ [7 - 1. C++ 에서의 입출력 (istream, ostream)](http://itguru.tistory.com/213)

C++ 입출력 라이브러리, `istream, ostream, streambuf` 에 대해 알아본다 C++ 입출력 라이브러리, `istream, ostream, streambuf` 에 대해 알아본다.

###@ [7 - 2. C++ 파일 입출력 (ifstream, ofstream, stringstream)](http://itguru.tistory.com/215)

C++ 에서의 파일 입출력, `stringstream` 과 그 활용에 대해 알아본다 C++ 에서의 파일 입출력, `stringstream` 과 그 활용에 대해 알아본다.

###@ [8 - 1. Excel 만들기 프로젝트 1부](http://itguru.tistory.com/217)

여태까지 배운 내용을 총 동원 하여 조그만 엑셀을 만드는 프로젝트이다.

###@ [8 - 2. Excel 만들기 프로젝트 2부](http://itguru.tistory.com/218)

이전 강좌에서 이어서 엑셀 만들기를 진행한다. 중위 표기법과 후위 표기법에 대해 다룬다.

###@ [9 - 1. 코드를 찍어내는 틀 - C++ 템플릿(Template)](http://itguru.tistory.com/219)

템플릿이란 무엇인가?, 함수 템플릿, 클래스 템플릿. 템플릿 인스턴스화, 템플릿 특수화. 함수 객체 (Functor)

###@  [ 9 - 2. 템플릿 메타 프로그래밍 (Template Meta Programming)](http://itguru.tistory.com/221)

타입이 아닌 인자를 받는 템플릿, 템플릿 메타 프로그래밍

###@ [9 - 3. 템플릿 메타 프로그래밍 2 (Template Meta Programming)](http://itguru.tistory.com/222)

`TMP` 마무리, 의존 타입(dependent type), `auto` 키워드

###@ [10 - 1. C++ 의 표준 템플릿 라이브러리 (STL) - 시퀀스 컨테이너](http://itguru.tistory.com/223)

시퀀스 컨테이너 (vector, list, deque) 와반복자(iterator)

###@ [10 - 2. C++ 의 표준 템플릿 라이브러리 (STL) - 연관 컨테이너](http://itguru.tistory.com/224)

`set, multiset, map, multimap, unordered_set, unordered_map` 등에 대해 배웁니다.

###@ [10 - 3. C++ STL - 알고리즘(algorithm)](http://itguru.tistory.com/225)

STL 알고리즘 라이브러리, 람다 함수, `sort, partial_sort, stable_sort, find, erase, erase_if, any_of, all_of`

###@ 10 - 4. STL 알고리즘들

###@ [11 - 1. 우측값 레퍼런스와 이동 생성자](http://itguru.tistory.com/227)

복사 생략 (copy elision), C++ 11 에 추가된 우측값 레퍼런스 (rvalue reference)와 이동 생성자 (move constructor)

###@ [11 - 2. Move 문법 (move semantics) 과 완벽한 전달 (perfect forwarding)](http://itguru.tistory.com/228)

move semantics, 완벽한 전달 (perfect forwarding), 레퍼런스 접힘 규칙 (reference collapsing rule)

###@ [12. C++ 에서의 예외 처리](/230)

`try .. catch` 와 `throw` 를 사용한 C++ 스타일의 예외 처리 방식에 대해 배운다.

###@ 13. 스마트 포인터 (`unique_ptr, shared_ptr, weak_ptr`)
