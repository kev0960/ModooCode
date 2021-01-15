----------------
title : C++ 11 자주 질문되는 것들 모음 (C++ 11 FAQs - Bjarne Stroustup)
publish_date : 2013-10-02
path : /C++
--------------

```warning
오픈북 프로젝트는 인터넷 상의양질의 컴퓨터 문서를 번역하여 우리 말로 공급하는 프로젝트 입니다. 번역된 문서들은 인터넷 상으로어떠한 제한 조건 없이 배포되고 있으며, 다만 원 번역자의 허락 없는 무단 수정을 금합니다.

현재 까지 번역된 문서들의 리스트는 [여기에서 확인하시면 됩니다.](http://itguru.tistory.com/201)
```


```info
이 문서의 내용을 쉽게 이해 하려면일정 수준 이상의 C++ 지식이 필요로 합니다. 아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)를 보시는 것은 어때요?
```


이번에 번역된 문서는 C++ 언어의 창시자 이신 [Bjarne Stroustrup 씨의 개인 홈페이지](http://www.stroustrup.com/C++11FAQ.html)에 올라와 있는 `C++ 11 FAQ` 를 번역한 것입니다. C++ 11 은 출시된지 2년여가 흘렀음에도 불구하고 국내에 양질의 C++ 11 에 추가된 내용들을 다루는 문서가 별로 없습니다. 따라서 저는 `C++ 11 FAQ` 를 한국어로 번역해서 많은 분들이 C++ 11 의 새롭게 추가된 기능과 C++ 표준 위원회에서 하는 일에 대해 전반적으로 훑어보고 이해할 수 있도록 하고자 합니다. 특히 심도 있는 공부나, 각 기능에 관한 전문적인 기술 문서들을 찾으려는 분들은, 각 질문에 대한 답 밑에 있는 '참고자료' 를 이용하시면 쉽게 찾을 수 있습니다.이 문서에는 아래와 같은 질문들이 포함되어 있습니다.


아래는 먼저 위원회와 C++ 11 에 대해 전반적인 내용에 대한 질문들입니다. 아래 모든 질문들에 대한 답변은 첨부된 `pdf` 파일에서 확인할 수 있으며, 조만간 인터넷에서 쉽게 확인할 수 있도록 웹버전으로도 제작할 생각입니다. 오탈자 관련 문제는 kev0960@gmail.com 으로 보내주시면 감사하겠습니다.


###  질문 목록



* 당신은 C++ 11 에 대해 어떻게 생각하시나요?
* `C++ 0x` 가 공식적인 표준이 언제 될까요?
* 컴파일러가 C++ 11 를 언제 구현할까요?
* 새로운 표준 라이브러리를 언제 사용할 수 있을까요?
* C++ 11 에서 제공하는 새로운 언어 기능들은 무엇인가요? (아래 질문들 참조)
* C++ 11 에서 제고공하는 새로운 표준 라이브러리는 무엇인가요? (아래 질문들 참조)
* `C++ 0x` 가 목표했던 것은 무엇인가요?
*  위원회가 추구했던 디자인 목표는 무엇인가요?
* 위원회 보고서들을 어디서 찾을 수 있나요?
* C++ 11 에 대한 전문적이고 기술적인 문서들을 어디서 찾을 수 있나요?
* C++ 11 에 대해 어디서 읽을 수 있나요?
* C++ 11 에 대한 영상 자료들은 있나요?
* C++ 11 은 배우기 어렵나요?• 위원회를 어떻게 운영되나요?
* 누가 위원회에 있나요?• `C++1y` 가 있을 예정인가요?
* “concepts” 에는 무슨 일이 있었나요?
* 당신이 별로 마음에 들지 않는 기능들이 있나요?
    
개개의 언어 기능 자체에 대한 질문들은 아래와 같습니다. 이 역시 `pdf` 파일 내에서 확인할 수 있습니다.

* `__cplusplus`
* `alignments`
* `atomic` 연산들
* `auto` (초기화자(initializer) 로 부터 타입 유추)
* `C99` 기능들
* `enum` 클래스
* `[[carries dependency]]`
* 예외의 복사와 다시 던지기 (rethrow)
* 상수 표현식 (constexpr)
* `decltype`
* 디폴트 조정하기 : `default` 와 `delete`
* 대표 생성자(delegating constructor)
* 동시성(Concurrency) 를 이용한 동적 초기화와 파괴
* 예외의 전파
* 명시적(explicit) 타입 변환 연산자
* `extern` 템플릿
* `for` 문 (range-for 문 참조)
* 후위 리턴 타입 문법 (확장된 함수 선언 문법)
* 클래스 내부 멤버 초기화자• 상속된 생성자들
* 초기화 리스트(initializer list)
* 인라인 네임스페이스(inline namespace)
* 람다(lambda)
* 템플릿 인자로 사용되는 지역 클래스
* `long long integer` (최소 64비트)
* 메모리 모델• 이동 연산 (우측값 레퍼런스 참조)
* 줄어듬(narrowing)• `[[noreturn]]`
* 널 포인터 (nullptr)
* 오버라이드 컨트롤 : `override`
* 오버라이드 컨트롤 : `final`
* `PODs`
* `range-for` 문
* `raw string` 리터럴
* `<>`
* 우측값 참조
* `static assert`
* 템플릿 별명(alias)
* 템플릿 `typedef` (템플릿 별명 참조)
* `thread local`
* 유니코드 문자
* 단일화(uniform) 된 초기화 문법
* `union`
* 사용자 정의 리터럴
* 가변인자(variadic) 템플릿


아래는 라이브러리 측면에서 향상된 부분들에 관한 질문 입니다.


* 표준 알고리즘의 향상된 부분들
* `array`
* `async()`
* `atoming` 작업들
* `condition` 변수들
* 표준 컨테이너의 향상된 부분들
* `function` 과 `bind`
* `foward_list`
* `future` 와 `promise`
* 가비지 컬렛션 `ABI`
* hash tables (unordered map 참조)
* 메타 프로그래밍(meta programming)과 `type traits`
* 상호 배제(Mutual exclusion)
* 난수 생성
* `<regex>` (정규 표현식 라이브러리)
* 범위있는 할당자
* `shared_ptr`
* 스마트 포인터 (`shared_ptr, weak_ptr, unique_ptr`)
* 쓰레드(thread)
* `Time` 기능들
* `tuple`
* `unique_ptr`
* `unordered_map`
* `weak_ptr`


아래는 위 내용들에 대한 모든 대답을 담은 pdf 파일 입니다. 전체 페이지는 103쪽 입니다.

 [ cplusplus_faq.pdf](/attachment/cplusplus_faq.pdf)