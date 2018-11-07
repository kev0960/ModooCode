----------------
title : C++ 레퍼런스 - STL 컨테이너 - vector
cat_title :  vector
path : /C++ Reference/Containers/vector
--------------

```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference/](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ vector

**벡터(vector)** 는 헤더파일 `<vector>` 에 정의되어 있는 는 순차 컨테이너의 한 종류로, 각각의 원소들이 선형으로 배열되어 있다.

벡터 컨테이너는 동적 배열로 구현되는데, 보통의 배열 처럼 벡터 컨테이너들도 각각의 원소들이 메모리 상에서 연속적으로 존재하게 된다. 이 때문에 벡터 컨테이너의 원소를 참조할 때 반복자(iterator) 을 이용해서 순차적으로 참조할 수 있고, 처음 원소의 부터의 상대적인 거리를 이용하여 접근할 수 도 있다.

하지만, 보통의 배열과는 달리 벡터 컨테이너는 스스로 공간을 할당하고, 크기를 확장할 수 있고, 또 줄일 수 도 있다.

  벡터 컨테이너는 아래와 같은 장점을 가지고 있다.


*  각각의 원소를 원소의 인덱스(index) 값으로 바로 참조 가능하다 (상수 시간이 소요)

*  원소들을 임의의 순서로 접근할 수 있다. (선형 시간 소요)

*  벡터 끝에 새로운 원소를 추가하거나 제거하기 (상수 시간 소요 - constant amortized time \sidenote{동적 배열 끝에 새로운 원소를 추가하는 경우를 생각해보자. 만일 이미 공간 자체가 할당되어 있으면 새로운 원소를 추가하는 일은 O(1) 일 것이다. 하지만, 공간이 할당되어 있지 않다면, 보통 2 배의 공간으로 다시 할당하게 되는데 이 때 시간이 O(n) 정도 들어가게 된다. 따라서 전체 평균적으로 볼 때 O(1) 정도의 상수 시간이 걸린다고 볼 수 있고 이러한 형태의 소요 시간을 constant amortized time 이라고 부른다.})


벡터는 배열이 제공하는 거의 모든 기능을 다 가지고 있다. 게다가, 벡터 컨테이너의 크기는 쉽게 조정될 수 있기 때문에 매우 용이하다. 하지만 이러한 장점들 때문에 보통의 배열보다 더 많은 메모리 공간을 필요로 한다는 단점이 있다.

다른 표준 순차 컨테이너 ([deque](http://itguru.tistory.com/176), [list](http://itguru.tistory.com/177)) 와 비교해 볼 때, 벡터는 원소에 접근하는 시간이나, 컨테이너의 끝에 새로운 원소를 삽입/삭제 하는데 매우 효율적이다. 반면에 끝이 아닌 중간에 새로운 원소를 삽입하는 작업은 [deque](http://itguru.tistory.com/176)나 [list](http://itguru.tistory.com/177)에 비해 느리다.

벡터 컨테이너는 내부적으로 공간을 관리하기 위해 두 개의 변수를 사용한다. 하나는 `size` 로 `vector::size` 함수를 통해서 그 값을 얻을 수 있는데, 이는 현재 벡터에 보관되어 있는 원소의 개수를 의미한다. 다른 하나는 `capacity` 로 `vector::capacity` 함수를 통해서 그 값을 얻을 수 있는데, 이는 벡터에 할당된 공간의 크기를 의미한다.

따라서 당연하게도, `capacity` 의 크기는 항상 `size` 보다 크게 조정되며, 만일 원소를 추가해서 `size` 의 크기가 `capacity` 를 넘어가 버리면 벡터 내부적으로 추가적인 공간을 할당하게 된다. 이 때 추가적으로 할당되는 공간은 많은 경우 현재 벡터 `capacity` 만큼 할당되어서 (즉, 전체 할당 크기가 이전의 두 배가 됨) 메모리 할당을 빈번하게 하는 경우를 최대한 줄이고, 사용하는 메모리 양도 줄이도록 최적화되어 있다.

벡터의 `capacity` 를 확장하는 작업은 꽤 많은 시간을 필요로 하는 작업이기 때문에 (왜냐하면 일단 메모리를 새로 할당해야 하고, 벡터의 내용을 새로운 장소에 복사해야 하기 때문이다) 만일 최적화가 필요한 경우 사용자는 직접 `vector::reserve` 함수를 이용해서 `capacity` 를 미리 크게 할당해 놓을 수 있다.

C++ 표준 템플릿 라이브러리 (STL) 에서는 벡터를 다음과 같이 두 개의 템플릿 인자를 가지도록 구현하였다.

```cpp-formatted
template <class T, class Allocator = allocator<T> >
class vector;
```


  이 때 각각의 템플릿 인자는 다음을 의미한다.

* `T` : (보관하려는) 원소의 타입

* `Allocator` : 어떠한 방식으로 메모리를 할당할지에 관련한 할당자(allocator) 타입을 나타낸다. 기본값으로 `T` 의 할당자 클래스 템플릿을 사용하며, `Heap` 에 할당하게 된다. 많은 경우 인자를 생략한다.





###  벡터의 멤버 함수



*  [생성자](http://itguru.tistory.com/178): 벡터를 생성한다.

* 소멸자 : 벡터를 소멸한다.

* `operator=` : 벡터의 내용을 복사한다.




반복자 (Iterators)


* `begin` : 시작 부분 (벡터의 첫번째 원소) 을 가리키는 반복자를 리턴한다.



* `end` : 끝 부분 (벡터의 마지막 원소 바로 다음) 을 가리키는 반복자를 리턴한다.

* `rbegin` : 역순으로 첫번째 (즉, 벡터의 마지막 원소) 를 가리키는 반복자를 리턴한다.

* `rend` : 역순으로 끝 부분 (즉, 벡터의 첫번째 원소 바로 이전) 을 가리키는 반복자를 리턴한다.




할당 관련


* `size` : 벡터의 `size` 를 리턴한다 (현재 원소의 개수)

* `max_size` : 벡터 최대 크기를 리턴한다.

* `resize` : 벡터가 `size` 개의 원소를 포함하도록 변경한다.

* `capacity` : 벡터에 할당된 전체 크기를 리턴한다.

* `empty` : 벡터가 비었는지 체크한다.

* `reserve` : 벡터에 할당된 크기를 변경한다.




원소 접근 관련


* `operator[]` : 원소에 접근한다.

* `at` : 원소에 접근한다.

* `front` : 첫번째 원소에 접근한다.

* `back` : 마지막 원소에 접근한다.




수정자 (Modifier)


* `assign` : 벡터의 원소를 집어넣는다.

* `push_back`: 벡터 끝에 원소를 집어 넣는다.

* `pop_back` : 마지막 원소를 제거한다.

* `insert$vector` : 벡터 중간에 원소를 추가한다.

* `erase` : 원소를 제거한다.

* `swap` : 다른 벡터와 원소를 바꿔치기 한다.



* `clear` : 원소를 모두 제거한다.




할당자


* `get_allocator` : 할당자(allocator) 을 얻는다.





###  멤버 변수들





* `reference` : `Allocator::reference`


* `const_reference` :  `Allocator::const_reference`


* `iterator` :  임의 접근 반복자(random `access iterator)`



* `const_iterator` : 상수 임의 접근 반복자 (즉, 접근하는 원소의 내용을 수정 못함)



* `size_type` : 벡터 `size` 를 나타내는 타입 (많은 경우 `size_t` 와 타입이 같으며 부호없는 정수이다)



* `difference_type` : 벡터 내의 두 원소 사이의 거리를 나타내는 타입 (많은 경우 `ptfdiff_t` 와 타입이 같으며 부호있는 정수)





* `value_type` : 원소 타입 (T)

* `allocator_type` : 할당자

* `pointer` : 포인터 (`Allocator::pointer`)

* `const_pointer` : 상수 포인터 (`Allocator::const_pointer`)

* `reverse_iterator` :  역 반복자 (끝에서 부터 참조해나간다) `reverse_iterator<iterator>`

* `const_reverse_iterator` :  상수 역 반복자 (`reverse_iterator<const_iterator>`)


###  템플릿 특수화 (template specialization)

벡터 템플릿 클래스는 특별히 `bool` 타입에 대한 템플릿 특수화(specialization)를 가지고 있다.

`bool` 만 특별하게 특수화 시킨 이유는 메모리 공간을 최적화 하기 위해 `bool` 원소가 한 개의 비트만 사용하도록 설계하였기 때문이다. (C++ 에서 최소 자료형의 크기는 8 비트 이다 - 즉 실제 bool 객체는 8 비트를 차지한다. )

따라서 `bool` 원소의 레퍼런스는 `bool&` 가 아니라, 아래와 같이 `vector<bool>` 에 특별히 정의되어 있는 멤버 변수를 통해 `vector<bool>` 의 단일 비트에 대한 조작을 수행할 수 있게 된다.


```cpp-formatted
class vector<bool>::reference {
  friend class vector;
  reference();  // public 생성자가 아니다
 public:
  ~reference();
  operator bool() const;                     // bool 로 캐스팅 한다.
  reference& operator=(const bool x);        // bool 을 대입
  reference& operator=(const reference& x);  // 비트로 대입
  void flip();  // 비트값 반전 (0 -> 1, 1 -> 0)
}
```

이와 비슷한 컨테이너로 `bitset` 이 있다.