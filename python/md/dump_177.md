----------------
title : C++ 레퍼런스 - STL 컨테이너 - list
cat_title :  list
--------------



```warning
이 레퍼런스의 모든 내용은 [http://www.cplusplus.com/reference](http://www.cplusplus.com/reference/iostream/) 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 ' [저의 모토인 지식 전파](http://itguru.tistory.com/notice/107)'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면 [씹어먹는 C++ 강좌](http://itguru.tistory.com/135)는 어때요?
```

#@ `list`

  리스트(list) 는 헤더파일 `<list>` 에 정의된 순차 컨테이너의 한 종류로 원소들은 메모리 상에 선형으로 배열된다.

  리스트 컨테이너는 이중 연결 리스트 (doubly linked list) 로 구현된다. 이중 연결 리스트를 이용하면 메모리 상의 임의의 위치에 원소를 저장하더라도 참조할 수 있게 된다. 왜냐하면 어떤 원소의 위치는 이전 원소와 다음 원소의 링크를 통해 따라서 추적해나갈 수 있기 때문이다.

  덕분에 리스트는 아래와 같은 장점을 가진다.


*  컨테이너 임의의 위치에 원소의 삽입과 삭제가 가능하다 (상수 시간)

*  서로 다른 컨테이너 사이 나 컨테이너 내부에서 원소들 간의 이동이 매우 효율적이다. (상수 시간)

*  원소들을 앞에서 뒤로, 혹은 뒤에서 앞으로 참조해나갈 수 있다 (선형 시간)



  다른 표준 순차 컨테이너 ( [vector](http://itguru.tistory.com/175)`,` [deque](http://itguru.tistory.com/176)`)` 와 비교했을 때, 리스트는 원소의 삽입, 삭제, 그리고 컨테이너 내부에서의 원소들 간의 이동이 매우 효율적이다. 따라서 정렬 알고리즘 처럼 원소의 이동이 빈번하게 일어나는 곳에 적용하면 효율적이다. 특히 list::sort 함수와, 원소 이동 관련한 함수가 list::splice 가 기본적으로 제공되어서 편리하다.

  하지만 리스트의 가장 큰 문제점은 원소들을 인덱스로 직접 참조하는 것이 비효율적이라는 것이다. 예를 들어서 리스트의 6 번째 원소를 참조하기 위해서는 리스트의 시작 부분으로 부터 링크를 하나씩 돌면서 찾아 나가야 한다. 뿐만 아니라, 링크 되는 다른 원소의 주소값을 보관해야 하기 때문에 추가적인 메모리가 사용된다는 것인데, 보관하는 원소에 크기가 작을 수 록 배보다 배꼽이 더 커지는 현상이 발생하게 된다. (원소의 주소값은 4 바이트인데, 보관하는 것은 1 바이트 원소라면 전체 메모리 사용의 `80%` 가 단순히 다음 원소의 주소값을 보관하는데 낭비된다)

  다른 순차 컨테이너들 처럼 메모리 할당과 해제는 내부적으로 스스로 수행한다.

  리스트는 C++ 표준 템플릿 라이브러리에서 아래와 같이 구현된다.

```cpp
template < class T, class Allocator = allocator<T> > class list;
```


* `T` : (보관하려는) 원소의 타입

* `Allocator` : 어떠한 방식으로 메모리를 할당할지에 관련한 할당자(allocator) 타입을 나타낸다. 기본값으로 `T` 의 할당자 클래스 템플릿을 사용하며, `Heap` 에 할당하게 된다. 많은 경우 인자를 생략한다.








###  멤버 함수





* 생성자 : 리스트를 생성한다.

* 소멸자 : 리스트를 소멸한다.

* `operator=` : 리스트의 내용을 복사한다.


반복자

* `begin` : 시작 부분 (첫번째 원소) 을 가리키는 반복자를 리턴한다.



* `end` : 끝 부분 (마지막 원소 바로 다음) 을 가리키는 반복자를 리턴한다.

* `rbegin` : 역순으로 첫번째 (즉, 마지막 원소) 를 가리키는 반복자를 리턴한다.

* `rend` : 역순으로 끝 부분 (즉, 첫번째 원소 바로 이전) 을 가리키는 반복자를 리턴한다.



할당 관련` (` [벡터](http://itguru.tistory.com/175)와는 다르게 `capacity` 와 `reserve` 가 없다! `)`

* `size` : 리스트의 `size` 를 리턴한다 (현재 원소의 개수)

* `max_size` : 리스트 최대 크기를 리턴한다.

* `resize` : 리스트가 `size` 개의 원소를 포함하도록 변경한다.

* `empty` : 리스트가 비었는지 체크한다.





임의 접근

* `front` : 첫번째 원소에 접근한다.

* `back` : 마지막 원소에 접근한다.





수정자 (Modifier)

* `assign` :
리스트
에 원소를 집어넣는다.

* `push_back` :
리스트
`` 끝에 원소를 집어 넣는다.

* `push_front` :
리스트
맨 앞에 원소를 집어 넣는다.



* `pop_back` : 마지막 원소를 제거한다.



* `pop_front` : 첫번째 원소를 제거한다.



* `insert` :
리스트
`` 중간에 원소를 추가한다.

* `erase` : 원소를 제거한다.

* `swap` : 다른
리스트
와 원소를 바꿔치기 한다.



* `clear` : 원소를 모두 제거한다.


특별한 작업들 (Operations)


* `splice` : 리스트와 리스트 사이에서 원소를 이동한다.

* `remove` : 특정 값을 지닌 원소를 삭제한다.


* `remove_if` : 특정 조건을 만족시 원소를 삭제한다.

* `unique` : 중복된 값을 삭제한다.


* `merge` : 정렬된 리스트를 합친다.

* `sort` : 컨테이너의 원소를 정렬한다.

* `reverse` : 원소들의 순서를 거꾸로 뒤집는다.



할당자


* `get_allocator` : 할당자(allocator) 을 얻는다.



###  멤버 변수들





* `reference` : Allocator::reference


* `const_reference` :  Allocator::const_reference


* `iterator` :  임의 접근 반복자(random `access iterator)`



* `const_iterator` : 상수 임의 접근 반복자 (즉, 접근하는 원소의 내용을 수정 못함)



* `size_type` : 리스트 `size` 를 나타내는 타입 (많은 경우 `size_t` 와 타입이 같으며 부호없는 정수이다)



* `difference_type` :
리스트
내의 두 원소 사이의 거리를 나타내는 타입 (많은 경우 `ptfdiff_t` 와 타입이 같으며 부호있는 정수)





* `value_type` : 원소 타입 (T)

* `allocator_type` : 할당자

* `pointer` : 포인터 (Allocator::pointer)

* `const_pointer` : 상수 포인터 (Allocator::const_pointer)

* `reverse_iterator` :  역 반복자 (끝에서 부터 참조해나간다) `reverse_iterator<iterator>`

* `const_reverse_iterator` :  상수 역 반복자 (reverse_iterator<const_iterator>)





