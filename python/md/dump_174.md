----------------
title : C++ 레퍼런스 - STL 컨테이너 (STL Container)
cat_title :  STL 컨테이너 (STL Container)
path : /C++ Reference/Containers
--------------



```info
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

### STL 컨테이너 (STL Container)


**컨테이너(Container)**는 말 그대로 다른 객체들 (원소) 을 보관하는 하나의 커다란 객체라고 볼 수 있다. 특히, STL 컨테이너는 클래스 템플릿(class template) 의 형태로 구현되어 있기 때문에 다양한 타입의 원소들을 보관할 수 있게 된다.

컨테이너는 자신이 보관하는 원소(element) 들의 저장 공간을 관리하며, 각각의 원소에 접근할 수 있도록 멤버 함수를 제공해준다. 컨테이서 상에서 원소에 접근하는 방법으로 크게 두 가지가 있는데, 하나는 직접 함수를 호출해서 접근하는 것이고, 다른 하나는 반복자(iterator) 을 이용해서 접근하는 것이다. 이에 관해서는 나중에 설명하도록 하겠다.

[시퀀스 컨테이너(vector, list, deque)에 대한 자세한 설명을 보려면 여기를 클릭](http://itguru.tistory.com/223)!


이처럼 컨테이너가 보관하는 원소의 타입에 크게 관계 없기 때문에 실제 프로그래밍에서 자주 사용되고 있다. 또한 표준 라이브러리에서는, 컨테이너를 여러가지 형태로 구현하여서 프로그래머들에게 각각의 상황에 적합한 컨테이너를 고를 수 있도록 제공하고 있는데, 예컨대 동적 배열(`vector`), 큐(`queue`), 스택(`stack`), 힙(`priority_queue`), 링크드 리스트 (`list`) 트리 (`set`), 연관 컨테이너 (`map`) 등등이 지원되고 있다.

[연관 컨테이너(set, map, multiset, multimap,](http://itguru.tistory.com/224)unordered_set, unordered_map) [에 대한 자세한 설명을 보려면 여기를 클릭](http://itguru.tistory.com/223)!


한 가지 유의할 사항은 스택(`stack`), 큐(`queue`), 우선순위 큐(`priority_queue`) 들로 이들은 컨테이너 어댑터(container adaptor) 이다. 이들은 다른 컨테이너 클래스들을 상속 받아서 다른 컨테이터 클래스의 객체에 특정한 인터페이스를 제공해준다. 

이를 통해 원래 컨테이너의 기능을 제한하고, 어댑터가 제공하는 인터페이스를 사용할 수 있게 된다. 예컨대 `stack` 이 [deque](http://itguru.tistory.com/176)  에 작용한다면, [deque](http://itguru.tistory.com/176)에 `stack` 이 제공하는 `top, pop, push` 등의 인터페이스를 사용할 수 있게 되는 것이다.



### 컨테이너 클래스 템플릿





순차 컨테이너 (Sequence Container)


*  [vector](http://itguru.tistory.com/175):  벡터 (Vector)


*  [deque](http://itguru.tistory.com/176):  데크 (double ended queue)


*  [list](http://itguru.tistory.com/177): 리스트 (List)


컨테이너 어댑터 (Container Adaptor)


* `stack` : `LIFO (Last in First out)` 스택


* `queue` : `FIFO (First in First out)` 큐


* `priority_queue` : 우선순위 큐 (Priority queue)




연관 컨테이너


* `set` : `Set`


* `multiset` : 여러 키를 가지는 `set`


* `map` : `Map`


* `multimap` : 여러 키를 가지는 `map`


* `bitset` :  `Bitset`
