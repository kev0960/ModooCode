 itguru Top itguru Top

```warning
이 레퍼런스의 모든 내용은http://www.cplusplus.com/reference/ 의 내용을 기초로 하여, Microsoft 의 MSDN 과 Bjarne Stroustrup 의 책 <<The C++ Programming Language>> 를 참고로 하여 만들어졌습니다. 이는 또한 저의 개인적인 C++ 능력 향상과 '저의 모토인 지식 전파'를 위해 모든 이들에게 공개하도록 하겠습니다.
```

```info
아직 C++ 에 친숙하지 않다면씹어먹는 C++ 강좌는 어때요?
```

deque

양쪽에서 끝나는 큐 (Double ended queue) 로 <deque> 에 정의되어 있다.

  흔히 줄여서 데크 ("deck") 로 발음된다. 보통의 스택(stack) 의 경우 최상단(top) 에서 삭제(pop) 과 삽입(push) 가 일어나고 반대쪽 (end) 에서는 아무것도 할 수 없다. 또한 큐(queue) 의 경우 한쪽에서는 삭제, 반대쪽에서는 삽입이 일어나지만, 삭제하는 쪽에서는 삽입을, 반대쪽에서는 삭제를 할 수 없다. 즉 스택의 경우 나중에 들어간 것이 먼저 나가는 LIFO (Last In First Out) 구조를, 큐의 경우 먼저 들어간 것이 먼저 나가는 FIFO (First In First Out) 구조를 취하가 된다. 데크의 경우 스택과 큐를 합친 것이라 볼 수 있으며, 즉, 양쪽 끝에서 삭제와 입력 모두 수행할 수 있게 된다.

  다른 순차 컨테이너 처럼 데크에서도 데이터는 선형으로 메모리 상에 위치하게 된다.데크는 라이브러리 마다 다른 방식으로 구현되겠지만, 어떤 경우라도 각각의 원소는 임의 접근 반복자를 통해 접근할 수 있고, 크기 할당 역시 자동으로 수행되게 된다.

  데크는 아래과 같은 장점이 있다.


* 개개의 원소들은 각자의 인덱스 값을 통해 접근할 수 있다.
* 원소를 어떠한 방향으로도 참조해 나갈 수 (iterate) 있다.
* 데크 끝과 시작 부분에 효율적으로 원소를 추가하거나 삭제할 수 있다.



  데크는 벡터(vector) 에서 제공하는 많은 기능을 제공해준다. 하지만, 데크의 경우벡터와는 다르게 양쪽 끝 모두에서 원소의 효율적인 추가와 삭제가 가능하다. 하지만,벡터와는 달리 데크는 모든 원소가 메모리 상에 연속적으로 존재한다고 보장할 수 없다. 즉, 포인터 연산을 통해서 데크의 원소들을 안전하게 접근할 수 없다는 의미이다.


벡터와 데크 모두 비슷한 인터페이스를 제공하고 있지만, 내부적으로는 다르게 처리된다.벡터의 경우 capacity 가 꽉 찼을 경우 새롭게 크게 한 덩어리의 메모리를 할당하게 되지만, 데크의 경우메모리 상에서 잘게 쪼개어서 보관하게 된다. 물론, 데크 객체 자체에서 메모리에 쪼개져서 보관되는 덩어리들의 위치를 기억하고, 각각의 원소에 대해 접근할 수 있는 인터페이스를 제공해준다. 따라서 데크는 내부적으로벡터의 비해 조금 더 복잡하게 구현되어 있지만 그 덕분에벡터와는 달리 메모리 공간을 효율적으로 사용할 수 있게 된다. 뿐만 아니라 엄청나게 큰 데이터의 경우, 데크는벡터와는 다르게 많은 양의 메모리 재할당을 하지 않기 때문에 좀더 빠르다고 볼 수 있다.

  처음과 끝 말고 중간에 원소의 삽입과 삭제를 빈번하게 사용한다면 데크 보다는리스트(list) 를 사용하는 것을 추천한다.

  C++ 표준 템플릿 라이브러리에서는 데크는 다음과 같은 두 개의 템플릿 인자를 받는다.

```cpp
template < class T, class Allocator = allocator<T> > class deque;
```


* T : (보관하려는) 원소의 타입
* Allocator : 어떠한 방식으로 메모리를 할당할지에 관련한 할당자(allocator) 타입을 나타낸다. 기본값으로 T 의 할당자 클래스 템플릿을 사용하며, Heap 에 할당하게 된다. 많은 경우 인자를 생략한다.



 멤버 함수



* 생성자 : 데크를 생성한다.
* 소멸자 : 데크를 소멸한다.
* operator= : 데크의 내용을 복사한다.

반복자


* begin : 시작 부분 (첫번째 원소) 을 가리키는 반복자를 리턴한다.

* end : 끝 부분 (마지막 원소 바로 다음) 을 가리키는 반복자를 리턴한다.
* rbegin : 역순으로 첫번째 (즉, 마지막 원소) 를 가리키는 반복자를 리턴한다.
* rend : 역순으로 끝 부분 (즉, 첫번째 원소 바로 이전) 을 가리키는 반복자를 리턴한다.


할당 관련 (벡터와는 다르게 capacity 와 reserve 가 없다! )


* size : 데크의 size 를 리턴한다 (현재 원소의 개수)
* max_size : 데크 최대 크기를 리턴한다.
* resize : 데크가 size 개의 원소를 포함하도록 변경한다.
* empty : 데크가 비었는지 체크한다.



임의 접근


* operator[] : 원소에 접근한다.
* at : 원소에 접근한다.
* front : 첫번째 원소에 접근한다.
* back : 마지막 원소에 접근한다.



수정자 (Modifier)


* assign : 데크에 원소를 집어넣는다.
* push_back : 데크 끝에 원소를 집어 넣는다.
* push_front : 데크 맨 앞에 원소를 집어 넣는다.

* pop_back : 마지막 원소를 제거한다.

* pop_front : 첫번째 원소를 제거한다.

* insert : 데크 중간에 원소를 추가한다.
* erase : 원소를 제거한다.
* swap : 다른 데크와 원소를 바꿔치기 한다.

* clear : 원소를 모두 제거한다.

할당자


* get_allocator : 할당자(allocator) 을 얻는다.


 멤버 변수들


* reference : Allocator::reference

* const_reference :  Allocator::const_reference

* iterator :  임의 접근 반복자(random access iterator)



* const_iterator : 상수 임의 접근 반복자 (즉, 접근하는 원소의 내용을 수정 못함)



* size_type : 데크 size 를 나타내는 타입 (많은 경우 size_t 와 타입이 같으며 부호없는 정수이다)



* difference_type : 데크 내의 두 원소 사이의 거리를 나타내는 타입 (많은 경우 ptfdiff_t 와 타입이 같으며 부호있는 정수)




* value_type : 원소 타입 (T)
* allocator_type : 할당자
* pointer : 포인터 (Allocator::pointer)
* const_pointer : 상수 포인터 (Allocator::const_pointer)
* reverse_iterator :  역 반복자 (끝에서 부터 참조해나간다) reverse_iterator<iterator>
* const_reverse_iterator :  상수 역 반복자 (reverse_iterator<const_iterator>)

공감sns신고저작자표시	<rdf:RDF xmlns="http://web.resource.org/cc/" xmlns:dc="http://purl.org/dc/elements/1.1/" xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">		<Work rdf:about="">			<license rdf:resource="http://creativecommons.org/licenses/by-fr/2.0/kr/" />		</Work>		<License rdf:about="http://creativecommons.org/licenses/by-fr/">			<permits rdf:resource="http://web.resource.org/cc/Reproduction"/>			<permits rdf:resource="http://web.resource.org/cc/Distribution"/>			<requires rdf:resource="http://web.resource.org/cc/Notice"/>			<requires rdf:resource="http://web.resource.org/cc/Attribution"/>			<permits rdf:resource="http://web.resource.org/cc/DerivativeWorks"/>		</License>	</rdf:RDF>'C++ Reference >STL Container' 카테고리의 다른 글C++ 레퍼런스 - STL 컨테이너 - vector::assign 함수(0)2012.03.25C++ 레퍼런스 - STL 컨테이너 - vector 생성자(0)2012.03.25C++ 레퍼런스 - STL 컨테이너 - list(0)2012.03.24C++ 레퍼런스 - STL 컨테이너 - deque(0)2012.03.24C++ 레퍼런스 - STL 컨테이너 - vector(0)2012.03.24C++ 레퍼런스 - STL 컨테이너 (STL Container)(2)2012.03.24

